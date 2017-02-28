/**************************************************************************
 * File: sg_IO75X_setup_s.c
 * Description: cifX generic configuration, using configuration files
 * 
 * Modifications 
 * +-------------+----------------------------------------------+--------+
 * | Date        | Comments                                     | Author |
 * +-------------+----------------------------------------------+--------+
 * | 05-Jul-2013 | First version                                | DK     |
 * +-------------+----------------------------------------------+--------+
 * PLEASE DO NOT MODIFY THIS FILE!
 *************************************************************************/

#define 	S_FUNCTION_LEVEL 	2
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO756_setup_s

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
#define NUMBER_OF_ARGS      (21)
#define ID_ARG              ssGetSFcnParam(S,0)
#define SLOT_ARG            ssGetSFcnParam(S,1)
#define SAMPLETIME_ARG      ssGetSFcnParam(S,2)
#define DRIVE_ARG           ssGetSFcnParam(S,3)
#define MODE_ARG            ssGetSFcnParam(S,4)

#define CONFIGMODE_ARG      ssGetSFcnParam(S,5)

#define INPUT_ARG           ssGetSFcnParam(S,6)
#define OUTPUT_ARG          ssGetSFcnParam(S,7)
#define DHCP_ARG            ssGetSFcnParam(S,8)
#define BOOTP_ARG           ssGetSFcnParam(S,9)
#define IPADDR_EN_ARG       ssGetSFcnParam(S,10)
#define IPADDRESS_ARG       ssGetSFcnParam(S,11)
#define NETMASK_ARG         ssGetSFcnParam(S,12)
#define GATEWAY_ARG         ssGetSFcnParam(S,13)
#define WATCHDOG_ARG        ssGetSFcnParam(S,14)
#define VENDORID_ARG        ssGetSFcnParam(S,15)
#define PRODUCTTYPE_ARG     ssGetSFcnParam(S,16)
#define PRODUCTCODE_ARG     ssGetSFcnParam(S,17)
#define MAJORREV_ARG        ssGetSFcnParam(S,18)
#define MINORREV_ARG        ssGetSFcnParam(S,19)
#define DEVICENAME_ARG      ssGetSFcnParam(S,20)

/* Work vectors **********************************************************/

#define NO_R_WORKS          (0)
#define NO_I_WORKS          (1)

#define BAR0_I_IND          (0)

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
    int cardId = (int)mxGetPr(ID_ARG)[0];

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

    ssSetIWorkValue(S, BAR0_I_IND, (int)ptBar0);
    /* Toolkit initialization ********************************************/
    if(xpceIsModelInit() == 1)
    {      
        char drive[10];
        int mode = (int)mxGetPr(MODE_ARG)[0]-1; // 0: polling mode , 1: interrupt mode
        
        int config_mode = (int)mxGetPr(CONFIGMODE_ARG)[0];

        IO75XDATA cardData;	
        
        mxGetString(DRIVE_ARG, drive, sizeof(drive));
        
        printf("EtherNet/IP Adapter\n");
        
        strcpy(cardData.driveletter, drive);
        strcpy(cardData.firmware, FIRMWARE_EIS);    // EtherNet/IP Adapter (Slave)
        
        cardData.mode = mode;  // polling mode / interrupt (not supported yet)
        
        if (config_mode == 1)
        {
            cardData.init_mode = SG_CONFIGFILES2;       // 2x Configuration files required
        }
        else
        {          
            IO756DATA eisData;
            
            cardData.init_mode = SG_WARMSTART;
            
            eisData.inputLen = (uint32_T)mxGetPr(INPUT_ARG)[0];
            eisData.outputLen = (uint32_T)mxGetPr(OUTPUT_ARG)[0];
            eisData.dhcp_en = (int)mxGetPr(DHCP_ARG)[0];
            eisData.bootp_en = (int)mxGetPr(BOOTP_ARG)[0];
            eisData.ipaddr_en = (int)mxGetPr(IPADDR_EN_ARG)[0];
            eisData.ipaddress = (uint32_T)mxGetPr(IPADDRESS_ARG)[0];
            eisData.netmask = (uint32_T)mxGetPr(NETMASK_ARG)[0];
            eisData.gateway = (uint32_T)mxGetPr(GATEWAY_ARG)[0];
            eisData.watchdog = (uint32_T)mxGetPr(WATCHDOG_ARG)[0];
            eisData.vendorid = (uint32_T)mxGetPr(VENDORID_ARG)[0];
            eisData.producttype = (uint32_T)mxGetPr(PRODUCTTYPE_ARG)[0];
            eisData.productcode = (uint32_T)mxGetPr(PRODUCTCODE_ARG)[0];
            eisData.majorrev = (uint32_T)mxGetPr(MAJORREV_ARG)[0];
            eisData.minorrev = (uint32_T)mxGetPr(MINORREV_ARG)[0];
   
            mxGetString(DEVICENAME_ARG, eisData.devicename, mxGetN(DEVICENAME_ARG)+1);
            
            sg_cifx_eis_data(cardId, SG_DATA_WRITE, &eisData);
        }

        printf("Speedgoat %s\n", cardData.firmware);

        sg_cifx_config_data(cardId, SG_DATA_WRITE, &cardData);
        lRet = sg_cifx_init (cardId, thisDevice, cardData, 10);
    }
    else
    {
        sg_cifx_startComm(cardId);
    }
    
#endif
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
#ifndef MATLAB_MEX_FILE
    int cardId = (int)mxGetPr(ID_ARG)[0];

uint32_T* ptBar0 = (uint32_T*) ssGetIWorkValue(S, BAR0_I_IND);

    volatile uint16_T* ch0_handshake = (uint16_T*)(ptBar0 + 0x0200);

    volatile uint16_T usNetxFlags = ch0_handshake[0x0008]; //netx comm flags

   
    if ((int)mxGetPr(ID_ARG)[0] == 1)
        sg_cifx_cyclictimer(cardId);
    
    else
        sg_cifx_DSR_handler(cardId);
 

#endif
}

static void mdlTerminate(SimStruct *S)
{   
#ifndef MATLAB_MEX_FILE
    if(xpceIsModelInit() == 0)  // stop communication when the application ends
    {  
        int cardId = (int)mxGetPr(ID_ARG)[0];

        sg_cifx_stopComm(cardId);
    }
#endif
}

#ifdef MATLAB_MEX_FILE  /* Is this file being compiled as a MEX-file? */
#include "simulink.c"   /* Mex glue */
#else
#include "cg_sfun.h"    /* Code generation glue */
#endif


