#ifndef __XPCIO106DMAHOOKS_C__
#define __XPCIO106DMAHOOKS_C__

#include <conio.h>
#include <windows.h>
#include "xpctarget.h"

#include "io_xpcimport.h"
#include "pci_xpcimport.h"
#include "time_xpcimport.h"
#include "ioext_xpcimport.h"
#include "util_xpcimport.h"

/* IO106, addressing map */
struct IO106 {
    volatile uint32_T bcr;
    volatile uint32_T icr;
    volatile uint32_T inputDataBuffer;
    volatile uint32_T inputBufferControl;
    volatile uint32_T rateAGenerator;
    volatile uint32_T rateBGenerator;
    volatile uint32_T bufferSize;
    volatile uint32_T burstSize;
    volatile uint32_T scanAndSyncControl;
    volatile uint32_T activeChannelAssignment;
    volatile uint32_T boardConfiguration;
    volatile uint32_T autoCalValues;
    volatile uint32_T auxRWRegisters;
    volatile uint32_T auxSyncIOControl;
    volatile uint32_T scanMarkerUpperWord;
    volatile uint32_T scanMarkerLowerWord;   
};

struct plxint { //at addr[0]+0x68
    volatile uint32_T intcsr;
};    

struct plxdma  // at addr[0]+0x80
{
    volatile uint32_T dma0mode;  // 0x80
    volatile uint32_T dma0addr;  // 0x84, target memory buffer address
    volatile uint32_T dma0local; // 0x88, set to 0x48, analog input buffer
    volatile uint32_T dma0bcnt;  // 0x8c, byte count for transfer
    volatile uint32_T dma0descr; // 0x90, DMA descriptor == 0xA
    volatile uint32_T dma1mode;  // 0x94 
    volatile uint32_T dma1addr;  // 0x98, target memory buffer address
    volatile uint32_T dma1local; // 0x9c, set to 0x48, analog input buffer
    volatile uint32_T dma1bcnt;  // 0xA0 , byte count for transfer
    volatile uint32_T dma1descr; // 0xA4 , DMA descriptor == 0xA
    volatile uint8_T  dma0csr;   // 0xA8, DMA0 command and status reg
    volatile uint8_T  dma1csr;   // 0xA9, DMA1 command and status reg
    volatile uint16_T d1;        // 0xAA filler
    volatile uint32_T dmaarb;    // 0xAC, mode/arbitration control
    volatile uint32_T dmathresh; // 0xB0, dma threshold register
};

/* PLX PCI bridge DMA register access structure */
typedef volatile struct plxdma_tag { // at BAR[0] + 0x80
    volatile uint32_T  dma0mode;  // 0x80 DMAMODE0 DMA channel 0 Mode
    volatile uint32_T* dma0addr;  // 0x84 DMAPADR0 DMA channel 0 PCI Address
    volatile uint32_T  dma0local; // 0x88 DMALADR0 DMA channel 0 Local Address
    volatile uint32_T  dma0bcnt;  // 0x8C DMASIZ0  DMA channel 0 Transfer Size (Bytes)
    volatile uint32_T  dma0descr; // 0x90 DMADPR0  DMA channel 0 Descriptor Pointer
    volatile uint32_T  dma1mode;  // 0x94 DMAMODE1 DMA channel 1 Mode
    volatile uint32_T* dma1addr;  // 0x98 DMAPADR1 DMA channel 1 PCI Address 
    volatile uint32_T  dma1local; // 0x9C DMALADR1 DMA channel 1 Local Address 
    volatile uint32_T  dma1bcnt;  // 0xA0 DMASIZ1  DMA channel 1 Transfer Size (Bytes) 
    volatile uint32_T  dma1descr; // 0xA4 DMADPR1  DMA channel 1 Descriptor Pointer 
    volatile uint8_T   dma0csr;   // 0xA8 DMACSR0
    volatile uint8_T   dma1csr;   // 0xA9 DMACSR1
    volatile uint16_T  d1;        // 0xAA
    volatile uint32_T  dmaarb;    // 0xAC
    volatile uint32_T  dmathresh; // 0xB0
    volatile uint32_T  dma0dac;   // 0xB4 DMADAC0  DMA channel 0 PCI dual address cycles upper address
    volatile uint32_T  dma1dac;   // 0xB8 DMADAC1  DMA channel 1 PCI dual address cycles upper address
}PlxDma_T;

// dma0csr, dma1csr
#define DMA_CSR_ENABLE_CHANNEL  0 // RW 1: enable channel to transfer data, 0: disable transfer and suspend if already running
#define DMA_CSR_START_TRANSFER  1 // So
#define DMA_CSR_ABORT_TRANSFER  2 // So
#define DMA_CSR_CLEAR_INTERRUPT 3 // Co Writing '1' clears channel interrupt
#define DMA_CSR_TRANSFER_DONE   4 // Ro Either all data transferred or xfer abort

typedef volatile struct PlxInt_tag 
{ 
    volatile uint32_T intcsr;
    volatile uint32_T cntrl;
} PlxInt_T;    

#define INTCSR_LOCAL_DATA_PARITY_CHECK_ERROR 7
#define INTCSR_PCI_INT_ENABLE      8 // INTA#
#define INTCSR_DMA_CH0_INT_ENABLE 18 // enable the channel 0 interrupt, cleared by DMA_CSR_CLEAR_INTERRUPT
#define INTCSR_DMA_CH0_INT_ACTIVE 21 // PCI_9056BA p325
#define INTCSR_DMA_CH1_INT_ACTIVE 22

int  __cdecl xpcio106dmaprehook(xpcPCIDevice *pPciDev);
void __cdecl xpcio106dmastart  (xpcPCIDevice *pPciDev);
void __cdecl xpcio106dmastop   (xpcPCIDevice *pPciDev);

int __cdecl xpcio106dmaprehook(xpcPCIDevice *pPciDev)
{
    PlxDma_T* pPlxDma = (PlxDma_T*)(pPciDev->VirtAddress[0] + 0x80);
    PlxInt_T* pPlxInt = (PlxInt_T*)(pPciDev->VirtAddress[0] + 0x68); 
    
    uint32_T  intcsr  = pPlxInt->intcsr;
//    uint32_T dma0mode = pPlxDma->dma0mode;
    uint32_T dma0csr  = pPlxDma->dma0csr;
    

    #ifdef DEBUG_PRINTF
    //printf("INT\n", pPlxInt->intcsr);
    #endif

    if( 1 // no need to check all this, but it works
//    && (intcsr   & (1 << INTCSR_PCI_INT_ENABLE))     // are PCI interrupts enabled?
//    && (intcsr   & (1 << INTCSR_DMA_CH0_INT_ENABLE)) // is the channel 0 interrupt enabled?
    && (intcsr   & (1 << INTCSR_DMA_CH0_INT_ACTIVE)) // is the channel 0 interrupt active? 
//    && (dma0csr  & (1 << DMA_CSR_ENABLE_CHANNEL))    // is DMA channel 0 enabled?
//    && (dma0mode & (1 << DMA_MODE_DONE_INT_EN  ))    // is the DMA DONE interrupt enabled?
    && (dma0csr  & (1 << DMA_CSR_TRANSFER_DONE ))    // is the DMA DONE interrupt active?
      )
    {  
        pPlxDma->dma0csr = (1 << DMA_CSR_CLEAR_INTERRUPT);
        pPlxDma->dma0csr =  0;
        // IMPORTANT: enable and start DMA only after reading the data in mdlOutputs().
        // optionally ping-pong-buffers could be used.
        return XPC_RUN_ISR;
    }
    return XPC_DROP_ISR;
}

void __cdecl xpcio106dmastart(xpcPCIDevice *pPciDev)
{
    
    PlxDma_T* pPlxDma;
    PlxInt_T* pPlxInt;
    uint32_T intcsr;
    volatile struct IO106 *IO106;
    
    pPciDev->VirtAddress[0] = (unsigned long)xpcReserveMemoryRegion( (void *)pPciDev->BaseAddress[0], 4096, XPC_RT_PG_USERREADWRITE );
    pPciDev->VirtAddress[2] = (unsigned long)xpcReserveMemoryRegion( (void *)pPciDev->BaseAddress[2], 4096, XPC_RT_PG_USERREADWRITE );
    
    pPlxDma = (PlxDma_T*)(pPciDev->VirtAddress[0] + 0x80);
    pPlxInt = (PlxInt_T*)(pPciDev->VirtAddress[0] + 0x68); 
    IO106 = (struct IO106 *)(pPciDev->VirtAddress[2]);
    
    // the init operation are done inside of the mdlStart of ad_generalstandards_16ai64ss_dma.c
    // here we just enabled the interrupt source.
    
    if (!xpceIsModelInit()) 
    {
        intcsr = pPlxInt->intcsr & 0xffffff00; // Channnel 1 is configured in the same register, so be careful
        pPlxInt->intcsr   = intcsr | ((1 << INTCSR_DMA_CH0_INT_ENABLE) | ( 1 << INTCSR_PCI_INT_ENABLE));
        
        pPlxDma->dma0csr  = (1 << DMA_CSR_CLEAR_INTERRUPT);
        pPlxDma->dma0csr  = 0;
        pPlxDma->dma0csr  = (1 << DMA_CSR_ENABLE_CHANNEL);
        pPlxDma->dma0csr  = (1 << DMA_CSR_ENABLE_CHANNEL) | (1 << DMA_CSR_START_TRANSFER);
        
        IO106->rateAGenerator &= ~(1 << 16); // enable rate generator
    }
    
    return;
}

void __cdecl xpcio106dmastop(xpcPCIDevice *pPciDev)
{
    PlxDma_T* pPlxDma = (PlxDma_T*)(pPciDev->VirtAddress[0] + 0x80);
    PlxInt_T* pPlxInt = (PlxInt_T*)(pPciDev->VirtAddress[0] + 0x68);
    volatile struct IO106 *IO106;
    real_T ticks, start;
    
    IO106 = (struct IO106 *)(pPciDev->VirtAddress[2]);
    
    /* Stop all rate generators */
    if (!xpceIsModelInit()) 
    {
        pPlxDma->dma0csr  = (1 << DMA_CSR_ABORT_TRANSFER);
        pPlxDma->dma0csr  = 0;
        pPlxDma->dma0mode = 0;
        pPlxInt->intcsr   = 0;

        #ifdef DEBUG_PRINTF
        printf("DMA Stop: Interrupts disabled (0x%08X)\n", pPlxInt->intcsr);
        #endif
    }        

    IO106->inputBufferControl |= (1 << 18);
    
    start = rl32eGetTicksDouble();
    
    while ( (IO106->inputBufferControl & (1 << 18)) == (1 << 18) ) {
        ticks = rl32eGetTicksDouble();
        if( ticks - start > 1193000.0 * 1.0 ) {   // 1 second timeout
            printf("timeout during clear buffer operation\n");
            return;
        }
    }
    
    if ( (IO106->inputBufferControl & (1 << 19) ) == (1 << 19) ){
        printf("Clear buffer operation failed\n");
        return;
    }

    return;
}

#endif
