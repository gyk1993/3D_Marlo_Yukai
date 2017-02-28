#ifndef __XPCIO331INTAHOOKS_C__
#define __XPCIO331INTAHOOKS_C__

#include <conio.h>
#include <windows.h>
#include "xpctarget.h"
#include "util_xpcimport.h" 

#define INTABASE                (0x24000)

struct pciBridge
{
    uint32_T intcsr;
    uint32_T dma;
    uint32_T globalInterruptEnable;
};

struct INTA
{
    uint32_T parameter;
    uint32_T clear;
    uint32_T event;
};

int __cdecl xpcIO331intaprehook(xpcPCIDevice *pci);
void __cdecl xpcIO331intastart(xpcPCIDevice *pci);
void __cdecl xpcIO331intastop(xpcPCIDevice *pci);

int __cdecl xpcIO331intaprehook(xpcPCIDevice *pci)
{
    volatile struct pciBridge *ptr; 
    volatile struct INTA *inta; 
    ptr = (struct pciBridge *)(pci->VirtAddress[0]);
    inta = (struct pciBridge *)(pci->VirtAddress[2] + INTABASE);
   
    // does the FPGA asserts the interrupt?
    if (ptr->intcsr & 0x8)
    {    
        inta->clear = 0x1;
        inta->clear = 0x0;
        return XPC_RUN_ISR;
    }
    else
    {
        return XPC_DROP_ISR; //not our interrupt
    }
}

void __cdecl xpcIO331intastart(xpcPCIDevice *pci)
{
    volatile struct pciBridge *ptr;  

	if (!xpceIsModelInit())
	{
		pci->VirtAddress[0] = (unsigned long)xpcReserveMemoryRegion((void *)pci->BaseAddress[0], 4096, XPC_RT_PG_USERREADWRITE );
        pci->VirtAddress[2] = (unsigned long)xpcReserveMemoryRegion((void *)pci->BaseAddress[2], 2097152, XPC_RT_PG_USERREADWRITE );
		// interrupt activation on PCI bridge side   
		ptr = (struct pciBridge *)(pci->VirtAddress[0]);
        ptr->intcsr |= (0x1 << 18);
		ptr->globalInterruptEnable = 0x80000000;
	}
  return;
}

void __cdecl xpcIO331intastop(xpcPCIDevice *pci)
{
    volatile struct pciBridge *ptr;  
		
	if (!xpceIsModelInit())
    {    
        // Disable interrupts from the board.
		ptr = (struct pciBridge *)(pci->VirtAddress[0]);  
        ptr->intcsr &= ~(0x1 << 18);
		ptr->globalInterruptEnable = 0x0;
	}
    return;
}
#endif
