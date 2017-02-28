/**************************************************************************
 * File: sg_IO75X_netstate_s.c
 * Description: Network status
 * 
 * Modifications 
 * +-------------+----------------------------------------------+--------+
 * | Date        | Comments                                     | Author |
 * +-------------+----------------------------------------------+--------+
 * | 10-Oct-2012 | First version                                | DK     |
 * +-------------+----------------------------------------------+--------+
 * | 07-Apr-2013 | Integration in speedgoatlib                  | DK     |
 * +-------------+----------------------------------------------+--------+
 * | 06-Aug-2013 | Adapted for new version                      | DK     |
 * +-------------+----------------------------------------------+--------+
 * PLEASE DO NOT MODIFY THIS FILE!
 *************************************************************************/
#define 	S_FUNCTION_LEVEL 	2
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO75X_netstate_s

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
#define NUMBER_OF_ARGS      (5)
#define ID_ARG              ssGetSFcnParam(S,0)
#define SAMPLETIME_ARG      ssGetSFcnParam(S,1)
#define GETSTATUS_ARG       ssGetSFcnParam(S,2)
#define SETSTATUS_ARG       ssGetSFcnParam(S,3)
#define TIMEOUT_ARG         ssGetSFcnParam(S,4)

/* Work vectors **********************************************************/
#define NO_I_WORKS          (0) 
//#define BASE_ADDR_I_IND     (0)

#define NO_R_WORKS          (0)
#define NO_P_WORKS          (0)

/* Global variables ******************************************************/
static char_T msg[256];

static void mdlInitializeSizes(SimStruct *S)
{
    uint16_T i;

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
    
    // Input ports
    if(mxGetPr(SETSTATUS_ARG)[0] == 1)
    {
        ssSetNumInputPorts(S, 1);
        ssSetInputPortWidth(S, 0, 1);
        ssSetInputPortDirectFeedThrough(S, 0, 1);
        ssSetInputPortRequiredContiguous( S, 0, 1 );
        ssSetInputPortDataType(S, 0, SS_UINT32);
    }
    else
        ssSetNumInputPorts(S, 0);
    
    // Outport ports
    if(mxGetPr(GETSTATUS_ARG)[0] == 1)
    {
    
        ssSetNumOutputPorts(S, 1);
        ssSetOutputPortWidth(S, 0, 1);
        ssSetOutputPortDataType(S, 0, SS_UINT32);
    }
    else
       ssSetNumOutputPorts(S, 0); 
    
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
    int cardId = (int)mxGetPr(ID_ARG)[0];
    
    if(mxGetPr(GETSTATUS_ARG)[0] == 1)
    {
        uint32_T *ptOutPort = ssGetOutputPortSignal(S, 0);  

         ptOutPort[0] = sg_cifx_getstate(cardId);

    }
    
    if(mxGetPr(SETSTATUS_ARG)[0] == 1)
    {
        volatile uint32_T* ptInPort = (uint32_T*) ssGetInputPortSignal(S,0);  
        uint32_T timeout = (uint32_T)mxGetPr(TIMEOUT_ARG)[0];

        sg_cifx_setstate (cardId, ptInPort[0], timeout);
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


