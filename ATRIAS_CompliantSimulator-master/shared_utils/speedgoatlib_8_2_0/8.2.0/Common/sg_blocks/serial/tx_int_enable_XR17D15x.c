/* $Revision$ $Date$ */
/* sertxenablefc422335.c - xPC Target, non-inlined S-function driver for serial
 * output direction for  the Fastcomm 422/2-PCI-335 board */
/* Copyright 1996-2006 The MathWorks, Inc.
*/

#define         S_FUNCTION_LEVEL        2
#undef          S_FUNCTION_NAME
#define         S_FUNCTION_NAME         tx_int_enable_XR17D15x

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
#define NUMBER_OF_ARGS          (3)
#define SLOT_ARG                ssGetSFcnParam(S,0)
#define PORT_ARG                ssGetSFcnParam(S,1)
#define TYPE_ARG                ssGetSFcnParam(S,2)

#define NO_I_WORKS              (1)
#define BASE_I_IND              (0)

#define NO_R_WORKS              (0)

static char_T msg[256];

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

    ssSetNumInputPorts(S, 1);

    ssSetInputPortRequiredContiguous( S, 0, 1 ); 
    ssSetInputPortWidth(S, 0, 1 );
    ssSetInputPortDataType( S, 0, SS_BOOLEAN );
    ssSetInputPortDirectFeedThrough(S, 0, 1);

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
    struct uartregs   *regs;
    int32_T    vendorId, deviceId;
    int32_T    pciBus, pciSlot;
    int8_T     *devName;
    int32_T    boardtype = (int32_T)mxGetPr(TYPE_ARG)[0];
    int32_T    port = (int32_T)mxGetPr(PORT_ARG)[0] - 1;

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
        sprintf( msg, "tx_int_enable_XR17F15x driver: Unknown board type, %d", boardtype );
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

    // Save the base address for mdlOutputs
    regs = (struct uartregs *)((int32_T)pDev.VirtAddress[0] + port * UARTCHANOFFSET);
    ssSetIWorkValue(S, BASE_I_IND, (int32_T)regs );

#endif

}

static void mdlOutputs(SimStruct *S, int_T tid)
{
#ifndef MATLAB_MEX_FILE
    struct uartregs *regs = (struct uartregs *)ssGetIWorkValue(S, BASE_I_IND);
    int32_T *IPtr = (int32_T *)ssGetInputPortSignal(S,0);
    int32_T enable;
    uint8_T reg;

    enable = (IPtr[0]) & 0xff;

    if( enable )
    {
        reg = regs->ier;
        regs->ier = reg & ~IERXMT;
        reg |= IERXMT;
        regs->ier = reg;
        //printf("IER: 0x%x\n", regs->ier);
    }
#endif

}

static void mdlTerminate(SimStruct *S)
{
#ifndef MATLAB_MEX_FILE

#endif
}

#ifdef MATLAB_MEX_FILE  /* Is this file being compiled as a MEX-file? */
#include "simulink.c"   /* Mex glue */
#else
#include "cg_sfun.h"    /* Code generation glue */
#endif
