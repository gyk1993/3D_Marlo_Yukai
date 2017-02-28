/**************************************************************************
 * File: sg_IO642_setup_s.c
 * Description: cifX setup for Profibus DP slave
 * 
 * Modifications 
 * +-------------+----------------------------------------------+--------+
 * | Date        | Comments                                     | Author |
 * +-------------+----------------------------------------------+--------+
 * | 04-Jun-2014 | First version (derived from sg_IO750_setup_s)| PR     |
 * +-------------+----------------------------------------------+--------+
 * PLEASE DO NOT MODIFY THIS FILE!
 *************************************************************************/

#define 	S_FUNCTION_LEVEL 	2
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO642_setup_s

/* Includes **************************************************************/
#include 	<stddef.h>
#include 	<stdlib.h>
#include    <string.h>
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

// General
#define NUMBER_OF_ARGS      (8)
#define ID_ARG              ssGetSFcnParam(S,0)
#define SLOT_ARG            ssGetSFcnParam(S,1)
#define SAMPLETIME_ARG      ssGetSFcnParam(S,2)
#define DRIVE_ARG           ssGetSFcnParam(S,3)
#define MODE_ARG            ssGetSFcnParam(S,4)
#define CONFIGMODE_ARG      ssGetSFcnParam(S,5)

#define INPUT_ARG           ssGetSFcnParam(S,6)
#define OUTPUT_ARG          ssGetSFcnParam(S,7)

/* Work vectors **********************************************************/

#define NO_R_WORKS          (0)
#define NO_I_WORKS          (0)
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
    xpcPCIDevice thisDevice;
    int32_T lRet = 0;  
    int16_T bus, slot;
    uint32_T* ptBar0;

    /* Memory mapping ****************************************************/
    bus = (int16_T)mxGetPr(SLOT_ARG)[0];
    slot = (int16_T)mxGetPr(SLOT_ARG)[1];
       
    if (xpcGetPCIDeviceInfo(VENDORID, DEVICEID, SUBVENDORID, SUBDEVICEID, bus, slot, &thisDevice))
    {
        sprintf(msg,"%s: board not present", DEVNAME);
        ssSetErrorStatus(S,msg);
    }


	ptBar0 = (uint32_T*) xpcReserveMemoryRegion((void*) thisDevice.BaseAddress[0], 
												    (uint32_T) thisDevice.Length[0], 
												    (uint32_T) XPC_RT_PG_USERREADWRITE);
    
    thisDevice.VirtAddress[0] = (uint32_T) ptBar0;

    /* Toolkit initialization ********************************************/
    if(xpceIsModelInit() == 1)
    {  
        int cardId = (int)mxGetPr(ID_ARG)[0];
        char drive[10];
        int mode = (int)mxGetPr(MODE_ARG)[0]-1;             // 0: polling mode , 1: interrupt mode
        int config_mode = (int)mxGetPr(CONFIGMODE_ARG)[0];
        
        int input = (int)mxGetPr(INPUT_ARG)[0];
        int output = (int)mxGetPr(OUTPUT_ARG)[0];
        
        IO75XDATA cardData;	
        
        mxGetString(DRIVE_ARG, drive, sizeof(drive));
        
        printf("Profibus Slave\n");
        
        strcpy(cardData.driveletter, drive);
        strcpy(cardData.firmware, FIRMWARE_PBS);    // EtherCAT Slave
        
        if (config_mode == 1)
            cardData.init_mode = SG_CONFIGFILES1;       // 1x Configuration files required
        else
        {
            IO642DATA pbsData;
            
            cardData.init_mode = SG_WARMSTART;
            
            pbsData.input = input;
            pbsData.output = output;
            
            sg_cifx_pbs_data(cardId, SG_DATA_WRITE, &pbsData);
//            sg_cifx_ecs_data(cardId, SG_DATA_WRITE, &pbsData);
        }
        
        cardData.mode = mode;                       

        printf("Speedgoat %s\n", cardData.firmware);

        sg_cifx_config_data(cardId, SG_DATA_WRITE, &cardData);
        lRet = sg_cifx_init (cardId, thisDevice, cardData, 10);
        if(lRet)
        {
            sprintf(msg,"%s: Please load config files first.", DEVNAME);
            ssSetErrorStatus(S,msg);
        }
    }
#endif
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
#ifndef MATLAB_MEX_FILE
    // int cardId = (int)mxGetPr(ID_ARG)[0];
    
    // if (cardId == 1)
        // sg_cifx_cyclictimer(cardId);
    // else
        // sg_cifx_DSR_handler(cardId);

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


