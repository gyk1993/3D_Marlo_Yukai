#ifndef __XPCIO112DMAHOOKS_C__
#define __XPCIO112DMAHOOKS_C__

#include <conio.h>
#include <windows.h>
#include "xpctarget.h"

#include "io_xpcimport.h"
#include "pci_xpcimport.h"
#include "time_xpcimport.h"
#include "ioext_xpcimport.h"
#include "util_xpcimport.h"

/* IO112, addressing map */
struct IO112 {
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
	 volatile uint32_T tur;
 
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

int  __cdecl xpcio112dmaprehook(xpcPCIDevice *pci);
void __cdecl xpcio112dmastart(xpcPCIDevice *pci);
void __cdecl xpcio112dmastop(xpcPCIDevice *pci);

int __cdecl xpcio112dmaprehook(xpcPCIDevice *pci)
{
    volatile struct plxdma *plxdma;
    volatile struct plxint *plxint;
    int csr;

    plxdma = (struct plxdma *)(pci->VirtAddress[0] + 0x80);
    plxint = (struct plxint *)(pci->VirtAddress[0] + 0x68); 
	


	
    csr = plxint->intcsr;
       
    if ( (csr & (1 << 21)) == (1 << 21) ){  // is DMA complete?    
        plxdma->dma0csr = 0xB; // clear int, enable and start 
			  
        return XPC_RUN_ISR;
    }
    return XPC_DROP_ISR;
}

void __cdecl xpcio112dmastart(xpcPCIDevice *pci)
{
    
    volatile struct plxdma *plxdma;
    volatile struct plxint *plxint;
    

    pci->VirtAddress[0] = (unsigned long)xpcReserveMemoryRegion( (void *)pci->BaseAddress[0], pci->Length[0], XPC_RT_PG_USERREADWRITE );
    pci->VirtAddress[2] = (unsigned long)xpcReserveMemoryRegion( (void *)pci->BaseAddress[2], pci->Length[2], XPC_RT_PG_USERREADWRITE );
    
    plxdma = (struct plxdma *)(pci->VirtAddress[0] + 0x80);
    plxint = (struct plxint *)(pci->VirtAddress[0] + 0x68);
    
	 
    // the init operation are done inside of the mdlStart of ad_generalstandards_16ai64ss_dma.c
    // here we just enabled the interrupt source.
    
	 
	 
    if (~xpceIsModelInit()) {
		//printf("Interrupt support enabled (0x%X)\n", plxint->intcsr);    
		plxint->intcsr |= ( 1 << 18) | ( 1 << 8);
		//printf("Interrupt support enabled (0x%X)\n", plxint->intcsr);
	 }
    
    
    return;
}

void __cdecl xpcio112dmastop(xpcPCIDevice *pci)
{
    volatile struct plxdma *plxdma;
    volatile struct plxint *plxint;
    volatile struct IO112 *IO112;
    real_T ticks, start;
    
    plxdma = (volatile struct plxdma *)(pci->VirtAddress[0] + 0x80);
    plxint = (struct plxint *)(pci->VirtAddress[0] + 0x68);
    IO112 = (struct IO112 *)(pci->VirtAddress[2]);
    

	 
    plxdma->dma0csr = 0x0C;    // clear int, abort, disable and stop
    plxint->intcsr = 0;
    
    IO112->inputBufferControl |= (1 << 18);
    
    start = rl32eGetTicksDouble();
    
    while ( (IO112->inputBufferControl & (1 << 18)) == (1 << 18) ) {
        ticks = rl32eGetTicksDouble();
        if( ticks - start > 1193000.0 * 1.0 ) {   // 1 second timeout
            printf("timeout during clear buffer operation\n");
            return;
        }
    }
    
    if ( (IO112->inputBufferControl & (1 << 19) ) == (1 << 19) ){
        printf("Clear buffer operation failed\n");
        return;
    }

    return;
}

#endif
