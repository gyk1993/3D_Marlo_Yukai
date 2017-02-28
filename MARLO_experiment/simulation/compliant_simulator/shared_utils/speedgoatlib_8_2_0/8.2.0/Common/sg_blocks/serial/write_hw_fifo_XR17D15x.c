/* $Revision$ $Date$ */
/* serwritefc422335.c - xPC Target, non-inlined S-function driver for serial
 * output direction for the Fastcomm 422/2-PCI board  */
/* Copyright 1996-2006 The MathWorks, Inc.
*/

#define         S_FUNCTION_LEVEL        2
#undef          S_FUNCTION_NAME
#define         S_FUNCTION_NAME         write_hw_fifo_XR17D15x

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
#define REG_I_IND               (0)

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

    ssSetNumInputPorts(S, 2);

    ssSetInputPortRequiredContiguous( S, 0, 1 ); 
    ssSetInputPortWidth(S, 0, DYNAMICALLY_SIZED);
    ssSetInputPortDataType( S, 0, SS_UINT32 );
    ssSetInputPortDirectFeedThrough(S, 0, 1);

    ssSetInputPortRequiredContiguous( S, 1, 1 ); 
    ssSetInputPortWidth(S, 1, 1 );
    ssSetInputPortDataType( S, 1, SS_UINT32 );
    ssSetInputPortDirectFeedThrough(S, 1, 1);

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

#define MDL_SET_INPUT_PORT_WIDTH
static void mdlSetInputPortWidth( SimStruct *S, int_T port, int_T width )
{
    if( width > 65 )  // Need to check the fifo mode that the board is set to!
    {
        sprintf( msg, "Input vector width must be less than the hardware fifo size" );
        ssSetErrorStatus(S,msg);
        return;
    }
    ssSetInputPortWidth( S, port, width );
}

#define MDL_SET_OUTPUT_PORT_WIDTH
static void mdlSetOutputPortWidth( SimStruct *S, int_T port, int_T width )
{
//    ssSetInputPortWidth( S, port, width );
}

#define MDL_START
static void mdlStart(SimStruct *S)
{

#ifndef MATLAB_MEX_FILE

    struct uartregs *reg;
    xpcPCIDevice pDev;
    int32_T  vendorId, deviceId;
    int32_T  pciBus, pciSlot;
    char_T   *devName;
    int32_T  boardtype = (int32_T)mxGetPr(TYPE_ARG)[0];
    int32_T  port = (int32_T)mxGetPr(PORT_ARG)[0];

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
        sprintf( msg, "write_hw_fifo_XR17D15x driver: Unknown board type, %d", boardtype );
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

    // Save the base address for mdlterminate
    reg = (struct uartregs *)((int32_T)pDev.VirtAddress[0] + UARTCHANOFFSET * (port - 1));
    ssSetIWorkValue(S, REG_I_IND, (int32_T)reg );

#endif

}

static void mdlOutputs(SimStruct *S, int_T tid)
{
#ifndef MATLAB_MEX_FILE
    struct uartregs *reg = (struct uartregs *)ssGetIWorkValue(S, REG_I_IND);
    int32_T *IPtr = (int_T *)ssGetInputPortSignal(S,0);
    int32_T volatile status = 0;
    uint8_T ier, isr;
    int32_T port = (int32_T)mxGetPr(PORT_ARG)[0];
    int32_T enable = *(int32_T *)ssGetInputPortSignal(S,1);

    if( enable <= 0 )
        return;  // This isn't our interrupt.

    // On entry, verify that the transmitter holding register is empty
    // so we can stuff all that came from the software fifo into the
    // hardware fifo.  Assume that the software fifo has a max read
    // parameter that fits with the hardware fifo mode setting.

    status = reg->lsr & 0xff;
    if( IPtr[0] == 0 )
    {
//printf("THRE off\n");
        // No data, turn off the transmitter empty interrupt and leave
        reg->ier = reg->ier & ~IERXMT;
    }
    else if( status & LSRTHRE )
    {
        int32_T i;
        int32_T *fifo = (int32_T *)((int)reg + TXFIFOOFFSET);
        int32_T d4cnt = IPtr[0] >> 2;
        int32_T d4rem = IPtr[0] & 0x3;
        uint8_T buf[64];  // max size of the fifo

        // Copy all the data from the input vector to the HW fifo.
        // The fifo read block MUST have the correct max read value
        // for the fifo mode.

//printf("copy %d bytes\n", IPtr[0] );

        // Use the 4 byte wide area at base+N*0x200+0x100 for the
        // first part of the data that is in whole 4 byte chunks.
        // Then finish it off with 1-3 single byte writes.
        // To minimize the time until the first byte can be sent after
        // this loop, we write the fifo after every 4 bytes are packed.

        // Future optimization:  bring the fifo read into this routine
        // so that we don't have to read all 60 bytes from the fifo before
        // writing the first one to the hardware.  This version can have
        // a 10 microsecond gap in RS485 mode between the last character
        // before the next one is written to the hardware.  This is a side
        // effect of auto RS485 turnaround using 'shift register empty'
        // instead of 'holding register empty' for the interrupt.

        for( i = 0 ; i < IPtr[0] ; i++ )
        {
            buf[i] = IPtr[i+1] & 0xff;  // copy to contiguous buffer
            if( d4cnt > 0 && (i & 3) == 3 )
            {
                *(fifo+(i>>2)) = *(int32_T *)(buf + i-3);
            }
        }
        if( d4rem > 0 )
        {
            for( i = 4*d4cnt ; i < IPtr[0] ; i++ )
                reg->data = buf[i];
        }
    }
    else
    {
        //printf("ne: LSR(%x) = 0x%x, lth = %d, fifo = %d\n", 
        //       (((int)reg)>>8)&0xff, 
        //       status, IPtr[0], reg->txfifolevel );

        sprintf(msg, "Attempted write to hardware fifo that isn't empty" );
        ssSetErrorStatus( S, msg );
        return;
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
