/* Abstract: Hook functions for IO511 board
 *
 * Copyright 1996-2010: Speedgoat
 */


#ifndef __XPCIO511INTAHOOKS_C__
#define __XPCIO511INTAHOOKS_C__

#include <conio.h>
#include <windows.h>
#include "xpctarget.h"
#include "util_xpcimport.h" 

struct plxInt  // at addr[2]+0x68
{
    volatile uint32_T INTCSR;  // 0x68
};


int __cdecl xpcIO511intaprehook(xpcPCIDevice *pci);
void __cdecl xpcIO511intastart(xpcPCIDevice *pci);
void __cdecl xpcIO511intastop(xpcPCIDevice *pci);

int __cdecl xpcIO511intaprehook(xpcPCIDevice *pci)
{
    volatile uint32_T *ioaddress;
    uint32_T tmp;
    struct plxInt *plx;

    ioaddress = (volatile uint32_T *)pci->VirtAddress[2];
    plx = (struct plxInt *)(pci->VirtAddress[0] + 0x68);
   
    // Is the IO511 asserting the interrupt line? 
    if (plx->INTCSR & 0x8000){

        // interrupts will be clear inside the model.
		//printf("int\n");
		return XPC_RUN_ISR;
    }
    else{
       return XPC_DROP_ISR; //not our interrupt
    }
}


void __cdecl xpcIO511intastart(xpcPCIDevice *pci){

    volatile uint32_T *ioaddressFPGA, *ioaddressPLX;
    uint32_T tmp;
    struct plxInt *plx;  

		if (!xpceIsModelInit())
		{		
			pci->VirtAddress[0] = (unsigned long)xpcReserveMemoryRegion((void *)pci->BaseAddress[0], 4096, XPC_RT_PG_USERREADWRITE );
			pci->VirtAddress[2] = (unsigned long)xpcReserveMemoryRegion((void *)pci->BaseAddress[2], 4096, XPC_RT_PG_USERREADWRITE );

			//printf("Interrupt initialization.\n");
			
			// interrupt activation on PLX side    
			/* 1. Local interrupt activation [LINTi],  set the bits 11 and 8 to activate local interrupt source*/
			plx = (struct plxInt *)(pci->VirtAddress[0] + 0x68);
			tmp = plx->INTCSR;   
			plx->INTCSR = tmp | 0x900;
			//printf("Interrupt at PLX level enabled (0x%08X).\n", plx->INTCSR);
		}
    return;
  
}

void __cdecl xpcIO511intastop(xpcPCIDevice *pci)
{
   
    //volatile uint32_T *ioaddressFPGA;
    uint32_T tmp;
    struct plxInt *plx;  
    
		if (!xpceIsModelInit())
		{ 
			// Disable interrupts from the board.
			plx = (struct plxInt *)(pci->VirtAddress[0] + 0x68);
			tmp = plx->INTCSR;
			plx->INTCSR = tmp & (~0x900);
		}
    return;
}

#endif /* __XPCIO511INTAHOOKS_C__  */
