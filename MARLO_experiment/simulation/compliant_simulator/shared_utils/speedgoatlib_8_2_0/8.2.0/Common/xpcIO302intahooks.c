#ifndef __XPCIO302INTAHOOKS_C__
#define __XPCIO302INTAHOOKS_C__

#include <conio.h>
#include <windows.h>
#include "xpctarget.h"
#include "util_xpcimport.h" 

#define SYNCHBASE               (0x9C00)

struct SYNCH
{
  uint32_T parameter;
  uint32_T clear;
  uint32_T copy; 
  uint32_T event;
};
struct plxInt
{
  volatile uint32_T INTCSR;  // 0x68
};

int __cdecl xpcIO302intaprehook(xpcPCIDevice *pci);
void __cdecl xpcIO302intastart(xpcPCIDevice *pci);
void __cdecl xpcIO302intastop(xpcPCIDevice *pci);

int __cdecl xpcIO302intaprehook(xpcPCIDevice *pci)
{
  volatile struct plxInt *plx;
  volatile struct SYNCH *synch;
  
  synch = (struct SYNCH *)(pci->VirtAddress[2] + SYNCHBASE); 
  plx = (struct plxInt *)(pci->VirtAddress[0] + 0x68);
   
  // does the FPGA asserts the interrupt?
  if (plx->INTCSR & 0x8000)
  {
    synch->clear = 0x1;
    synch->clear = 0x0;
    return XPC_RUN_ISR;
  }
  else
  {
    return XPC_DROP_ISR; //not our interrupt
  }
}

void __cdecl xpcIO302intastart(xpcPCIDevice *pci)
{
  volatile struct plxInt *plx;  
  volatile struct SYNCH *synch;

  if (!xpceIsModelInit())
  {
		pci->VirtAddress[0] = (unsigned long)xpcReserveMemoryRegion((void *)pci->BaseAddress[0], 4096, XPC_RT_PG_USERREADWRITE );
		pci->VirtAddress[2] = (unsigned long)xpcReserveMemoryRegion((void *)pci->BaseAddress[2], 2097152, XPC_RT_PG_USERREADWRITE );	
		// interrupt activation on PLX side    
    /* 1. Local interrupt activation [LINTi],  set the bits 11 and 8 to activate local interrupt source*/
		plx = (struct plxInt *)(pci->VirtAddress[0] + 0x68);
    synch = (struct SYNCH *)(pci->VirtAddress[2] + SYNCHBASE); 
    synch->clear = 0x1;
    synch->clear = 0x0;
		plx->INTCSR |= 0x900;
	}
  return;
}

void __cdecl xpcIO302intastop(xpcPCIDevice *pci)
{
  volatile struct plxInt *plx;  
  volatile struct SYNCH *synch;

	if (!xpceIsModelInit())
	{    
	  // Disable interrupts from the board.
		plx = (struct plxInt *)(pci->VirtAddress[0] + 0x68);
    synch = (struct SYNCH *)(pci->VirtAddress[2] + SYNCHBASE); 
    synch->clear = 0x1;
    synch->clear = 0x0;
    
		plx->INTCSR &= (~0x900);
	}
  return;
}
#endif 
