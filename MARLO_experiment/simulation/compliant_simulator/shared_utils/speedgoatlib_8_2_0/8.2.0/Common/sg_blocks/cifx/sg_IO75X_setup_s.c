/**************************************************************************
 * File: sg_IO75X_setup_s.c
 * Description: cifX configuration, protocol initialization
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
#define 	S_FUNCTION_NAME 	sg_IO75X_setup_s

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

// General
#define NUMBER_OF_ARGS      (7)
#define ID_ARG              ssGetSFcnParam(S,0)
#define SLOT_ARG            ssGetSFcnParam(S,1)
#define FIRMWARE_ARG        ssGetSFcnParam(S,2)
#define SAMPLETIME_ARG      ssGetSFcnParam(S,3)

// EtherCAT Slave
#define ECS_CONFIGFILE_ARG	ssGetSFcnParam(S,4)
#define ECS_INPUT_ARG       ssGetSFcnParam(S,5)
#define ECS_OUTPUT_ARG      ssGetSFcnParam(S,6)

/* Work vectors **********************************************************/
#define NO_I_WORKS          (1)
#define BASE_ADDR_I_IND     (0)

#define NO_R_WORKS          (0)
#define NO_P_WORKS          (0)

/* Global variables ******************************************************/
static char_T msg[256];         // General message

static void mdlInitializeSizes(SimStruct *S)
{
    uint16_T i;
    
    ssSetNumSFcnParams(S, NUMBER_OF_ARGS);  // Number of S-Fcn parameters
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S))
    {
        sprintf(msg,
                "Wrong number of input arguments passed.\n%d arguments are expected\n",
                NUMBER_OF_ARGS);
        
        ssSetErrorStatus(S,msg);
        return;
    }

    ssSetNumContStates(S, 0);       // No continuos states
    ssSetNumDiscStates(S, 0);       // No discrete States

    ssSetNumInputPorts(S, 0);       // No input ports
    ssSetNumOutputPorts(S, 0);      // No output ports
  
    ssSetNumSampleTimes(S, 1);      // Number of sample times

    ssSetNumRWork(S, NO_R_WORKS);   // Number of floating-point work vectors  
    ssSetNumIWork(S, NO_I_WORKS);   // Number of integer work vectors
    ssSetNumPWork(S, NO_P_WORKS);   // Numbero of pointer work vectors

    ssSetNumModes(S, 0);            // Size of mode vector
    ssSetNumNonsampledZCs(S, 0);    // Number of states Zero-Crossing detection

    for( i = 0 ; i < NUMBER_OF_ARGS ; i++ )
    {
        ssSetSFcnParamTunable(S,i,0);  // None of the parameters are tunable
    }

    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE | SS_OPTION_PLACE_ASAP);
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
    int32_T lRet = 0;  
    int16_T pcislot[2];

    volatile uint32_T *ptBAR0;
    
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
    
    /* Toolkit initialization ********************************************/
    if(xpceIsModelInit())
    {
        uint8_T firmwareCode;
        uint8_T cardId;
        
        lRet = sg_cifx_init();
        
        if (lRet != 0x00)
        {
            sprintf(msg,"%s: initialization error", DEVNAME);
            ssSetErrorStatus(S,msg);
            return;
        }
            
        firmwareCode = (uint8_T)mxGetPr(FIRMWARE_ARG)[0];
        cardId = (uint8_T)mxGetPr(ID_ARG)[0];
 
        if (firmwareCode == 1)                                  // EtherCAT Slave
        {
            char ecsConfigName[256];
            uint16_T ecsInput, ecsOutput;
            
            // Get parameters
            mxGetString(ECS_CONFIGFILE_ARG, 
                        ecsConfigName, 
                        sizeof(ecsConfigName));                 // ESI filename

            ecsInput = (uint8_T)mxGetPr(ECS_INPUT_ARG)[0];      // Number of Inputs
            ecsOutput = (uint8_T)mxGetPr(ECS_OUTPUT_ARG)[0];    // Number of Outputs

            // Save parameters
            sg_cifx_ecs_data(cardId, SG_DATA_WRITE, ecsConfigName, &ecsInput, &ecsOutput);
            
            // EtherCAT Slave init
            printf("%s: EtherCAT Slave (IO750, id %i)\n", DEVNAME, cardId);
            lRet = sg_cifx_ecs_init(cardId, pciinfo, "IO750");  
            
            if (lRet != 0x00)
            {
                sprintf(msg,"%s: ECS initialization error", DEVNAME);
                ssSetErrorStatus(S,msg);
                return;
            }
         }
        
        else
        {
            sprintf(msg,"%s: invalid firmware", DEVNAME);
            ssSetErrorStatus(S,msg);
            return;
        }
    }

#endif
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
#ifndef MATLAB_MEX_FILE
    
    sg_cifx_cyclictimer();

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


