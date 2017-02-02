/* $Revision$ $Date$ */
/* setupfc422335.c - xPC Target, non-inlined S-function driver for digital
 * input section for the Fastcomm 422/2-PCI-335 board  */
/* Copyright 1996-2006 The MathWorks, Inc.
*/

#define         S_FUNCTION_LEVEL        2
#undef          S_FUNCTION_NAME
#define         S_FUNCTION_NAME         setup_PMC521_XR17D15x

#include        <stddef.h>
#include        <stdlib.h>

#include        "simstruc.h"

#ifdef          MATLAB_MEX_FILE
#include        "mex.h"
#endif

#ifndef         MATLAB_MEX_FILE
#include        <windows.h>
#include        "xpctarget.h"
#include        "sg_serialdefines.h"
#endif

/* Input Arguments */
#define NUMBER_OF_ARGS          (20)
#define SLOT_ARG                ssGetSFcnParam(S,0)
#define TYPE_ARG                ssGetSFcnParam(S,1)
#define PORT_ARG                ssGetSFcnParam(S,2)
#define STANDARD_ARG            ssGetSFcnParam(S,3)
#define STANDARDRATE_ARG        ssGetSFcnParam(S,4)
#define CUSTOMDIVISOR_ARG       ssGetSFcnParam(S,5)
#define MODE8X_ARG              ssGetSFcnParam(S,6)
#define PRESCALE_ARG            ssGetSFcnParam(S,7)
#define WIDTH_ARG               ssGetSFcnParam(S,8)
#define NSTOP_ARG               ssGetSFcnParam(S,9)
#define PARITY_ARG              ssGetSFcnParam(S,10)
#define RLEVEL_ARG              ssGetSFcnParam(S,11)
#define CTSMODE_ARG             ssGetSFcnParam(S,12)
#define XONOFF_ARG              ssGetSFcnParam(S,13)
#define XONCHAR_ARG             ssGetSFcnParam(S,14)
#define XOFFCHAR_ARG            ssGetSFcnParam(S,15)
#define RS485_ARG               ssGetSFcnParam(S,16)
#define RS485DLY_ARG            ssGetSFcnParam(S,17)
#define RECINT_ARG              ssGetSFcnParam(S,18)
#define MCRRTS_ARG              ssGetSFcnParam(S,19)

#define SAMP_TIME_IND           (0)
#define BASE_ADDR_IND           (0)

#define NO_I_WORKS              (2)
#define PORTBASE_I_IND          (0)
#define CONFIG_I_IND            (1)

#define NO_R_WORKS              (0)

static char_T msg[256];

#define FCRT_EN_FIFOTRG     0x30  // Enable receive fifo depth
#define FCRT_EN_SELRT       0x80
#define EFR_AUTO_CTS        0x80
#define EFR_AUTO_RTS        0x40

static void mdlInitializeSizes(SimStruct *S)
{
    int32_T i;

    ssSetNumSFcnParams(S, NUMBER_OF_ARGS);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        sprintf(msg,"Wrong number of input arguments passed.\n%d arguments are expected\n",NUMBER_OF_ARGS);
        ssSetErrorStatus(S,msg);
        return;
    }

    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);

    ssSetNumOutputPorts(S, 0);

    ssSetNumInputPorts(S, 0);

    ssSetNumSampleTimes(S, 1);

    ssSetNumRWork(S, NO_R_WORKS);
    ssSetNumIWork(S, NO_I_WORKS);
    ssSetNumPWork(S, 0);

    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    for( i = 0 ; i < NUMBER_OF_ARGS ; i++ )
    {
        ssSetSFcnParamTunable(S,i,0);  /* None of the parameters are tunable */
    }

    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE | SS_OPTION_PLACE_ASAP);
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
    	ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    	ssSetOffsetTime(S, 0, FIXED_IN_MINOR_STEP_OFFSET);
}

#define MDL_START
static void mdlStart(SimStruct *S)
{

#ifndef MATLAB_MEX_FILE

    struct uartregs   *regs;
    struct uartconfig *config;
    xpcPCIDevice   pDev;
    int32_T     vendorId, deviceId;
    char_T      *devName;
    int32_T     boardtype = (int)mxGetPr(TYPE_ARG)[0];
    int32_T     pciSlot;
    int32_T     pciBus;
    int32_T     port;
    int32_T     standard = (int)mxGetPr(STANDARD_ARG)[0];
    int32_T     bauddiv;
    int32_T     paritytemp;
    int32_T     lcrtemp;
    int32_T     fctrtemp;
    int32_T     rs485mode = (int)mxGetPr(RS485_ARG)[0];
    int32_T     rs485delay = (int)mxGetPr(RS485DLY_ARG)[0];
    int32_T     mode8x = (int)mxGetPr(MODE8X_ARG)[0];
    int32_T     rlevtemp;
    int32_T     efrtemp;
    int32_T     ctsmode = (int)mxGetPr(CTSMODE_ARG)[0];
    int32_T     xonoff = (int)mxGetPr(XONOFF_ARG)[0];
    int32_T     mcrtemp;

    switch( boardtype )
    {
        // board types 1-8 are used by Quatech, Diamond, etc.
        // Don't reuse types for different serial boards to ease confusion.
      case 100:
        vendorId = 0x16d5;
        deviceId = 0x0520;
        devName = "Acromag PMC520";
        break;
      case 101:
        vendorId = 0x16d5;
        deviceId = 0x0521;
        devName = "Acromag PMC521";
        break;
      default:
        sprintf( msg, "setupp_XR17D15x driver: Unknown board type, %d", boardtype );
        ssSetErrorStatus( S, msg );
        return;
    }

    if( mxGetN(SLOT_ARG) == 1 )
    {
        pciBus = 0;
        pciSlot = (int32_T) mxGetPr(SLOT_ARG)[0];
    } else
    {
        pciBus = (int32_T) mxGetPr(SLOT_ARG)[0];
        pciSlot = (int32_T) mxGetPr(SLOT_ARG)[1];
    }

    if( xpcGetPCIDeviceInfo( vendorId,
                             deviceId,
                             -1,
                             -1,
                             pciBus,
                             pciSlot,
                             &pDev ) )
    {
        sprintf(msg, "No %s at bus %d slot %d", devName, pciBus, pciSlot);
        ssSetErrorStatus(S, msg);
        return;
    }

    
    pDev.VirtAddress[0]
        = (int32_T)xpcReserveMemoryRegion( (void *)(pDev.BaseAddress[0]),
                                           pDev.Length[0],
                                           XPC_RT_PG_USERREADWRITE);

    // show Device Information
    // xpcShowPCIDeviceInfo( &pDev );

    port = (int32_T)mxGetPr(PORT_ARG)[0] - 1;
    regs = (struct uartregs *)((int32_T)pDev.VirtAddress[0] + port * UARTCHANOFFSET);
    config = (struct uartconfig *)((int32_T)pDev.VirtAddress[0] + UARTCONFIGOFFSET);

    // Save the UART address for mdlterminate
    ssSetIWorkValue(S, PORTBASE_I_IND, (int32_T)regs );
    ssSetIWorkValue(S, CONFIG_I_IND, (int32_T)config );

    if( standard == 1)
        bauddiv = divisors[ (int32_T)(mxGetPr(STANDARDRATE_ARG)[0] - 1) ];
    else
        bauddiv = (int32_T)(mxGetPr(CUSTOMDIVISOR_ARG)[0]);

    // Set the DLAB bit so we can get to the baud rate divisor
    // and the options register
    lcrtemp = regs->lcr;
    regs->lcr = lcrtemp | LCRDLAB;

    regs->dll = bauddiv & 0xff;
    regs->dlm = (bauddiv >> 8) & 0xff;

    // Clear the DLAB bit
    regs->lcr = lcrtemp;

    if( standard == 0 && mode8x == 1 )
    {
        config->mode8x = config->mode8x | (1 << port);
    }
    else
    {
        config->mode8x = config->mode8x & ~(1 << port);
    }

    // Enable the enhanced functions in the EFR register
    efrtemp = EFRENABLE;
    if( ctsmode == 1 )
        efrtemp |= EFRHWFLOW;
    if( xonoff == 1 )
        efrtemp |= EFRRXFLOW | EFRTXFLOW;
    regs->efr = efrtemp;    

    // Construct the contents of the LCR register.
    lcrtemp = 0;

    switch( (int32_T)(mxGetPr(WIDTH_ARG)[0]) )
    {
      case 1:
        lcrtemp = LCR5BIT;
        break;
      case 2:
        lcrtemp = LCR6BIT;
        break;
      case 3:
        lcrtemp = LCR7BIT;
        break;
      case 4:
        lcrtemp = LCR8BIT;
        break;
    }

    if( (int32_T)(mxGetPr(NSTOP_ARG)[0]) == 2 )  // If 2 stop bits are chosen,
        lcrtemp |= LCRSTOP;

    // Parity selection involves 3 bits in the LCR
    paritytemp = 0;
    switch( (int32_T)(mxGetPr(PARITY_ARG)[0] ) )
    {
      case 1:   // no parity
        paritytemp = 0;
        break;
      case 2:   // even parity
        paritytemp = LCRPARITY | LCREVEN;
        break;
      case 3:   // odd parity
        paritytemp = LCRPARITY;
        break;
      case 4:   // mark parity
        paritytemp = LCRPARITY | LCRSTICK;
        break;
      case 5:   // space parity
        paritytemp = LCRPARITY | LCREVEN | LCRSTICK;
        break;
    }
    lcrtemp |= paritytemp;

    regs->lcr = lcrtemp;
    //printf("final lcr = 0x%x\n", regs->lcr );

    // Set up FCTR, 485 Hysterisis, 485 auto mode, trigger table
    fctrtemp = FCTRTRIG;  // Programmed levels, RX and TX, FCR bits ignored
    if( rs485mode == 1 )
    {
        fctrtemp |= FCTRAUTO485;  // Enable auto turnaround signaling
        regs->msr = (rs485delay & 0xf) << 4;  // turn around delay
    }

    // Still need to consider the hysterisis value
    regs->fctr = fctrtemp;

    // Set up the FIFO trigger levels.
    // Let the transmitter trigger be 'empty'.
    // The receiver trigger is given by RLEVEL_ARG

    // Set the FCR with fifo properties
    rlevtemp = 1;
    switch( (int32_T)(mxGetPr(RLEVEL_ARG)[0] ) )
    {
      case 1:  // interrupt at 1 byte
        rlevtemp = 1;
        break;
      case 2:  // interrupt at quarter full (16)
        rlevtemp = 16;
        break;
      case 3:  // interrupt at half full   (32)
        rlevtemp = 32;
        break;
      case 4:  // interrupt at almost full (56)
        rlevtemp = 56;
        break;
    }
    regs->txfifolevel = 1;
    regs->rxfifolevel = rlevtemp;
 
    regs->fcr = FCREBL  | FCRRCLR | FCRTCLR;

    mcrtemp = 0;
    // The following disabled since the wiring doesn't bring out
    // the DTR or DSR lines even though they can be used in the UART.
    //if( ctsmode == 2 )
    //{
    //    mcrtemp |= MCRDTRFLOW;  // Use DTR/DSR instead of CTS/RTS
    //}
    //if (port<5) {
    //mcrtemp|= MCRDTR; // receiver enabled
    //mcrtemp|= MCRRTS; // transmitter enabled
    //}
    
    mcrtemp|= MCRDTR;
    
    if ((int32_T)(mxGetPr(MCRRTS_ARG)[0])) {
        mcrtemp|= MCRRTS; // transmitter enabled
    }
            
    if( standard == 0 && mxGetPr( PRESCALE_ARG )[0] == 1 )
    {
        mcrtemp |= MCRPRE;      // Divide reference by 4
    }
    // Defaults to DTR, RTS, OUT1, OUT2 all high, bits = 1 sets outputs high

// TEST
    //mcrtemp |= 0x10;  // loopback mode
    //printf("mcr = 0x%x\n", mcrtemp );
// TEST

    regs->mcr = mcrtemp;
        
    // Enable receive interrupts.
    
    if ((int32_T)(mxGetPr(RECINT_ARG)[0])) {
        regs->ier = IERRCV;
    }

    // Transmit interrupt isn't enabled yet, but is delayed until there
    // are characters available to be sent.
#endif

}

static void mdlOutputs(SimStruct *S, int_T tid)
{

#ifndef MATLAB_MEX_FILE

// No body, this block does nothing at run time.

#endif

}

static void mdlTerminate(SimStruct *S)
{
#ifndef MATLAB_MEX_FILE
    struct uartregs *regs = (struct uartregs *)ssGetIWorkValue(S, PORTBASE_I_IND);

    // Disable interrupts.
    regs->ier = 0;
    
    // Disable receiver
    // Disable transmitter
    regs->mcr= 0;

    // Flush the transmit and receive fifos so the next start will be clean
    regs->fcr = FCREBL | FCRRCLR | FCRTCLR;
#endif
}



#ifdef MATLAB_MEX_FILE  /* Is this file being compiled as a MEX-file? */
#include "simulink.c"   /* Mex glue */
#else
#include "cg_sfun.h"    /* Code generation glue */
#endif
