
/* Abstract: Hook functions for Scramnet GT boards */


#ifndef __XPCSCRAMNETGTHOOKS_C__
#define __XPCSCRAMNETGTHOOKS_C__

#ifdef _MSC_VER                         /* Visual C/C++ */
#define OUTPD _outpd
#define INPD  _inpd
#elif defined(__WATCOMC__)              /* WATCOM C/C++ */
#define OUTPD outpd
#define INPD  inpd
#else                                   /* error out */
#define OUTPD
#define INPD
#endif

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <xpctarget.h>

typedef unsigned short uint16_T;
int __cdecl xpcscgtprehook(xpcPCIDevice *pci);
void __cdecl xpcscgtstart(xpcPCIDevice *pci);
void __cdecl xpcscgtstop(xpcPCIDevice *pci);


/**********************************************************************/
int __cdecl xpcscgtprehook(xpcPCIDevice *pci) 
{
    volatile unsigned long * cRegPtr;
    unsigned long intCSR;  
	int rval = XPC_DROP_ISR;
	    
    cRegPtr  = (volatile unsigned long *)pci->VirtAddress[0];
    
    // Read interrupt control status register 
    intCSR = cRegPtr[3];  /* read register at byte offset 0xc*/
        
    while (intCSR & 0xFF)
    {   
		rval = XPC_RUN_ISR;
        // clear interrupt 
        cRegPtr[3] = intCSR;
		// get next 
		intCSR = cRegPtr[3];
    } 	
	return rval;
}

void __cdecl xpcscgtstart(xpcPCIDevice * pci) 
{	    
    void * Physical0;
    volatile unsigned long * cRegPtr;
       
    // Get pointer to Control status register space 
    Physical0=(void *)pci->BaseAddress[0];
	pci->VirtAddress[0] = 
		(unsigned long) xpcReserveMemoryRegion(Physical0,
		                                       0x100,
										       XPC_RT_PG_USERREADWRITE);
    
    cRegPtr=(volatile unsigned long *)pci->VirtAddress[0];

    /* Arm interrupts */
    cRegPtr[3] = 0x80000; /* 0x80000=Enable receive network interrupts */
    return;
	
}
void __cdecl xpcscgtstop(xpcPCIDevice *pci) 
{	    
  	volatile unsigned long * cRegPtr;

    cRegPtr = (volatile unsigned long*)pci->VirtAddress[0];    

    // make sure interrupts are disabled 
    cRegPtr[3] = 0;	
    
    return;	
}

#endif /* __XPCSCRAMNETGTHOOKS_C__ */
