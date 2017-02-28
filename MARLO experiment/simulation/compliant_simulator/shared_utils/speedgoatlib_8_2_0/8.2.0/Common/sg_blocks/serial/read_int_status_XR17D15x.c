/* $Revision$ $Date$ */
/* iqueryfcc422335.c - xPC Target, non-inlined S-function driver for digital
 * input section for the Fastcomm 422/2-PCI-335 board */
/* Copyright 1996-2006 The MathWorks, Inc.
*/

#define         S_FUNCTION_LEVEL        2
#undef          S_FUNCTION_NAME
#define         S_FUNCTION_NAME         read_int_status_XR17D15x

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
#define NUMBER_OF_ARGS          (2)
#define SLOT_ARG                ssGetSFcnParam(S,0)
#define TYPE_ARG                ssGetSFcnParam(S,1)

#define SAMP_TIME_IND           (0)
#define BASE_ADDR_IND           (0)

#define NO_I_WORKS              (1)
#define REG_I_IND               (0)

#define NO_R_WORKS              (0)

static char_T msg[256];

static void mdlInitializeSizes(SimStruct *S)
{
    int32_T i;
    int32_T boardtype;

    ssSetNumSFcnParams(S, NUMBER_OF_ARGS);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S))
    {
        sprintf(msg,"Wrong number of input arguments passed.\n%d arguments are expected\n",NUMBER_OF_ARGS);
        ssSetErrorStatus(S,msg);
        return;
    }

    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);

    ssSetNumOutputPorts(S, 1);
    boardtype = (int32_T)mxGetPr(TYPE_ARG)[0];
    switch( boardtype )
    {
      case 100:  // Acromag PMC520, 8 serial ports
        ssSetOutputPortWidth(S, 0, 8);
        break;
      case 101:  // Acromag PMC521, 8 serial ports
        ssSetOutputPortWidth(S, 0, 8);
        break;
      case 102:  // TEWS TPMC466, 4 serial ports
        ssSetOutputPortWidth(S, 0, 4);
        break;
      case 103:  // TEWS TPMC465, 8 serial ports
        ssSetOutputPortWidth(S, 0, 8);
        break;
      default:
        sprintf(msg, "Unknown board type: %d\n", boardtype );
        ssSetErrorStatus(S,msg);
        return;
    }
    ssSetOutputPortDataType( S, 0, SS_UINT32 );

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

//     ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE | SS_OPTION_PLACE_ASAP);
    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
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

    xpcPCIDevice pDev;
    int32_T   vendorId, deviceId;
    int8_T    *devName;
    int32_T   pciSlot;
    int32_T   pciBus;
    int32_T boardtype = (int)mxGetPr(TYPE_ARG)[0];

    switch( boardtype )
    {
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
      case 102:
        vendorId = 0x1498;
        deviceId = 0x01D2;
        devName = "TEWS TPMC466";
        break;
      case 103:
        vendorId = 0x1498;
        deviceId = 0x01D1;
        devName = "TEWS TPMC465";
        break;
      default:
        sprintf( msg, "read_int_status_XR17D15x driver: Unknown board type, %d", boardtype );
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

    ssSetIWorkValue(S, REG_I_IND, (int32_T)pDev.VirtAddress[0] );
#endif

}

static int intcount = 0;

static void mdlOutputs(SimStruct *S, int32_T tid)
{

#ifndef MATLAB_MEX_FILE

    struct uartregs *regs;
    int8_T *base = (int8_T *)ssGetIWorkValue(S, REG_I_IND );
    struct uartconfig *config = (struct uartconfig *)((int32_T)base + UARTCONFIGOFFSET );
    int32_T ports = 0;
    int32_T *OPtr = ssGetOutputPortSignal(S,0);
    int32_T i;
    int32_T gint;  // global interrupt register
    int32_T lint;  // local interrupt register, per uart

//printf("ISR entry:  ");
    switch( (int)(mxGetPr(TYPE_ARG)[0]) )
    {
      case 100:
        ports = 8;
        break;
      case 101:
        ports = 8;
        break;
      case 102:
        ports = 4;
        break;
      case 103:
        ports = 8;
        break;
    }

    gint = config->intstat;
//printf("   gint = 0x%x\n", gint );
    for( i = 0 ; i < ports ; i++ )
    {
        if( gint & (1 << i) )  // Check bits in the low order byte
        {
            int32_T reason;

            regs = (struct uartregs *)(base + UARTCHANOFFSET * i);
            lint = regs->isr;
            //printf("       isr %d, = 0x%x, ier = 0x%x\n", i, lint, regs->ier );
            reason = 0;

            switch( lint & IIRREASON )
            {
              case 1:  // No interrupt on this port
                reason = 0;
                break;
              case 4:   // received data available
              case 6:   // receiver line status, overrun etc.
              case 0xc: // character timeout
                reason = 1;  // All three are receive interrupts
                break;
              case 2:
                reason = 2;  // Transmitter holding register empty
//printf("       fifo(%x) = %d, lsr %x\n", 
//       (((int)regs)>>8)&0xff, 
//       regs->txfifolevel, regs->lsr );
                break;
              case 0:
                reason = 3;  // Modem status change
                break;
            }
            OPtr[i] = reason | lint << 8;
        }
        else
            OPtr[i] = 0;   // No interrupt pending on port i.
    }
#endif

}

static void mdlTerminate(SimStruct *S)
{
}

#ifdef MATLAB_MEX_FILE  /* Is this file being compiled as a MEX-file? */
#include "simulink.c"   /* Mex glue */
#else
#include "cg_sfun.h"    /* Code generation glue */
#endif
