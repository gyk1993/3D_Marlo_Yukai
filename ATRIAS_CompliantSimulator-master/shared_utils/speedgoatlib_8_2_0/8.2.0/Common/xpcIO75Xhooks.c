#ifndef __XPCIO75XHOOKS_C__
#define __XPCIO75XHOOKS_C__

#include <conio.h>
#include <windows.h>
#include "xpctarget.h"
#include "util_xpcimport.h" 
#include <stdio.h>

#include "sg_cifx_ext.h"


int  __cdecl xpcIO75Xprehook(xpcPCIDevice *pci);
void __cdecl xpcIO75Xstart(xpcPCIDevice *pci);
void __cdecl xpcIO75Xstop(xpcPCIDevice *pci);

int __cdecl xpcIO75Xprehook(xpcPCIDevice *pci)
{
    return sg_cifx_interrupt_handler(2);
}

void __cdecl xpcIO75Xstart(xpcPCIDevice *pci)
{
    //volatile uint32_T *ptr;  
   // printf("ERROR: Interrupt not yet supported!\n");
    
	if (!xpceIsModelInit())
	{
        uint8_T data[5760];
        
        printf("Init interrupt\n");
		pci->VirtAddress[0] = (unsigned long)xpcReserveMemoryRegion((void *)pci->BaseAddress[0], 0x10000, XPC_RT_PG_USERREADWRITE );
        
        sg_cifx_interrupt_init(2, 1);
       
	}
     
}

void __cdecl xpcIO75Xstop(xpcPCIDevice *pci)
{
    //volatile struct pciBridge *ptr;  
		
	if (!xpceIsModelInit())
    {    
        // Disable interrupts from the board.
        sg_cifx_interrupt_init(2, 0);
	}
}
#endif
