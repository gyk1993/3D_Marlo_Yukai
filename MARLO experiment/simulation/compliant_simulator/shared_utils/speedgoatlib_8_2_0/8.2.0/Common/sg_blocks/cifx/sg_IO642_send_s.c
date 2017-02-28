/**************************************************************************
 * File: sg_IO642_send_s.c
 * Description: Simple cyclic data output block
 * 
 * Modifications 
 * +-------------+----------------------------------------------+--------+
 * | Date        | Comments                                     | Author |
 * +-------------+----------------------------------------------+--------+
 * | 04-Jun-2014 | First version (based on IO750)               | PR     |
 * +-------------+----------------------------------------------+--------+
 * PLEASE DO NOT MODIFY THIS FILE!
 *************************************************************************/

#define 	S_FUNCTION_LEVEL 	2
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO642_send_s

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
#include    "sg_cifx_ext.h"

#endif


/* S-Function input arguments ********************************************/

#define NUMBER_OF_ARGS      (4)
#define ID_ARG              ssGetSFcnParam(S,0)
#define SAMPLETIME_ARG      ssGetSFcnParam(S,1)
#define OUTPUTBYTES_ARG     ssGetSFcnParam(S,2)
#define PORTTYPE_ARG        ssGetSFcnParam(S,3)

/* Work vectors **********************************************************/
#define NO_I_WORKS          (0)
#define NO_R_WORKS          (0)
#define NO_P_WORKS          (0)

/* Global variables ******************************************************/
static char_T msg[256];

static void mdlInitializeSizes(SimStruct *S)
{
    int i;
    int out_length; 
    int port_type;

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
    
    out_length = (int)mxGetPr(OUTPUTBYTES_ARG)[0];
    port_type = (int)mxGetPr(PORTTYPE_ARG)[0];

    if (port_type == 1)
    {
        ssSetNumInputPorts(S, out_length);   // Input ports

        for (i = 0 ; i < out_length; i++)
        {
            ssSetInputPortWidth(S, i, 1);
            ssSetInputPortDirectFeedThrough(S, i, 1);
            ssSetInputPortRequiredContiguous( S, i, 1 );
            ssSetInputPortDataType(S, i, SS_UINT8);
        }
    }
    else if (port_type == 2)
    {
        ssSetNumInputPorts(S, 1);   // Input ports

        ssSetInputPortWidth(S, 0, out_length);
        ssSetInputPortDirectFeedThrough(S, 0, 1);
        ssSetInputPortRequiredContiguous( S, 0, 1 );
        ssSetInputPortDataType(S, 0, SS_UINT8);
    }
    
    ssSetNumOutputPorts(S, 0); // No output ports         
        
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

#endif
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
#ifndef MATLAB_MEX_FILE
    volatile uint8_T* ptInPort; // Input port
    int cardId = (int)mxGetPr(ID_ARG)[0];
    int out_bytes = (int)mxGetPr(OUTPUTBYTES_ARG)[0];
    int port_type = (int)mxGetPr(PORTTYPE_ARG)[0];
    uint8_T data[5760];        
    int i;
    
    if (port_type == 1)
    {         
        for (i = 0 ; i < out_bytes ; i++)
        {
            ptInPort = (uint8_T*) ssGetInputPortSignal(S, i);           // Get port pointer

            data[i] = ptInPort[0];
        }
    }
    else if (port_type == 2)
    {
        ptInPort = (uint8_T*) ssGetInputPortSignal(S, 0);           // Get port pointer
        
        for (i = 0 ; i < out_bytes ; i++)
        {
            data[i] = ptInPort[i];
        }
    }
    // send data
    sg_cifx_write(cardId, 0, out_bytes, data);
    

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


