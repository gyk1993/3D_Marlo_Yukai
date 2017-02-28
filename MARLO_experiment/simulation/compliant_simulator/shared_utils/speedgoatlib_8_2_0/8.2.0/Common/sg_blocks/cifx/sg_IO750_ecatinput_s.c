/**************************************************************************
 * File: sg_IO750_ecatinput_s.c
 * Description: EtherCAT Slave simple input block
 * 
 * Modifications 
 * +-------------+----------------------------------------------+--------+
 * | Date        | Comments                                     | Author |
 * +-------------+----------------------------------------------+--------+
 * | 10-Oct-2012 | First version                                | DK     |
 * +-------------+----------------------------------------------+--------+
 * | 07-Apr-2013 | Integration in speedgoatlib                  | DK     |
 * +-------------+----------------------------------------------+--------+
 * PLEASE DO NOT MODIFY THIS FILE!
 *************************************************************************/

#define 	S_FUNCTION_LEVEL 	2
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO750_ecatinput_s

/* Includes **************************************************************/
#include 	<stddef.h>
#include 	<stdlib.h>

#include 	"simstruc.h" 

// Only for MEX:
#ifdef 		MATLAB_MEX_FILE
#include 	"mex.h"
#endif

// Only for Code generation:
#ifndef     MATLAB_MEX_FILE
#include    <windows.h>

#include    "xpctarget.h"
#include    "xpcimports.h"
   
#include    "sg_cifx.h"
#include    "speedgoat.h"

#endif


/* S-Function input arguments ********************************************/
#define NUMBER_OF_ARGS      (3)
#define SLOT_ARG            ssGetSFcnParam(S,0)
#define SAMPLETIME_ARG      ssGetSFcnParam(S,1)
#define CHANNELS_ARG        ssGetSFcnParam(S,2)

/* Work vectors **********************************************************/
#define NO_I_WORKS          (1)
#define BASE_ADDR_I_IND     (0)

#define NO_R_WORKS          (0)
#define NO_P_WORKS          (0)

/* Global variables ******************************************************/
static char_T msg[256];

/**************************************************************************
 * Function: mdlInitializeSizes
 * Parameters: SimStruct *S
 * Return: -
 * Description: defines Simulink block sizes
 * 
 * Modifications 
 * +-------------+----------------------------------------------+--------+
 * | Date        | Comments                                     | Author |
 * +-------------+----------------------------------------------+--------+
 * | 10-Oct-2012 | First version                                | DK     |
 * +-------------+----------------------------------------------+--------+
 * 
 *************************************************************************/
static void mdlInitializeSizes(SimStruct *S)
{
    uint32_T i;

    ssSetNumSFcnParams(S, NUMBER_OF_ARGS);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S))
    {
        sprintf(msg,
                "Wrong number of input arguments passed.\n%d arguments are expected\n",
                NUMBER_OF_ARGS);
        
        ssSetErrorStatus(S,msg);
        return;
    }

    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);

    
    ssSetNumInputPorts(S, 0);                           // No input ports 
    ssSetNumOutputPorts(S, (int)mxGetN(CHANNELS_ARG));  // Number of outputs ports
    
    for (i = 0 ; i < (int)mxGetN(CHANNELS_ARG) ; i++)
    {         
        ssSetOutputPortWidth(S, i, 1);
        ssSetOutputPortDataType(S, i, SS_UINT8);

    }
    
    ssSetNumSampleTimes(S, 1);

    ssSetNumRWork(S, NO_R_WORKS);
    ssSetNumIWork(S, NO_I_WORKS);
    ssSetNumPWork(S, NO_P_WORKS);

    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    for( i = 0 ; i < NUMBER_OF_ARGS ; i++ )
    {
        ssSetSFcnParamTunable(S,i,0);  // None of the parameters are tunable
    }

    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
    if (mxGetPr(SAMPLETIME_ARG)[0]==-1.0)
    {
        ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
        ssSetOffsetTime(S, 0, FIXED_IN_MINOR_STEP_OFFSET);
    }
    else
    {
        ssSetSampleTime(S, 0, mxGetPr(SAMPLETIME_ARG)[0]);
        ssSetOffsetTime(S, 0, 0.0);
    }
}

#define MDL_START
static void mdlStart(SimStruct *S)
{
#ifndef MATLAB_MEX_FILE
    xpcPCIDevice pciinfo;
    volatile uint32_T *ptBAR0;
    int16_T pcislot[2];

    /* Memory mapping ****************************************************/
    pcislot[0] = (int16_T)mxGetPr(SLOT_ARG)[0];
    pcislot[1] = (int16_T)mxGetPr(SLOT_ARG)[1];
    
    if (sg_find_device(DEVNAME, (uint16_T)VENDORID,
                                (uint16_T)DEVICEID,
                                (uint16_T)SUBVENDORID,
                                (uint16_T)SUBDEVICEID,
                                pcislot, &pciinfo, msg)) 
    {
        ssSetErrorStatus(S,msg);
        return;
    }

    sg_map_BAR(&pciinfo,1,0,0,0,0,0);   // map BAR0 only

    ptBAR0 = (volatile uint32_T*)pciinfo.VirtAddress[0];
    ssSetIWorkValue(S, BASE_ADDR_I_IND, ptBAR0); 
#endif
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
#ifndef MATLAB_MEX_FILE
    int32_T i;
    uint16_T nChannel;
    volatile uint32_T baseAddress = ssGetIWorkValue(S, BASE_ADDR_I_IND);

    volatile uint8_T* ptOutPort;     // Output port

    /* Receive data ******************************************************/
    // Check if the protocol stack is successfully opened (flag = 1) 
    // and communication status is "OPERATE"
    if (sg_cifx_StackOpen_StatusOperate(baseAddress))
    {    
        for (i = 0 ; i < (int)mxGetN(CHANNELS_ARG) ; i++)
        {
            ptOutPort = (uint8_T*)ssGetOutputPortSignal(S, i);          // Get port pointer
            nChannel = (uint16_T)mxGetPr(CHANNELS_ARG)[i] - 1;          // Channel number

            ptOutPort[0] = sg_cifx_ecs_input_readByte(baseAddress, nChannel); 

        }
        
        sg_cifx_PD0_in_ack(baseAddress);            
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


