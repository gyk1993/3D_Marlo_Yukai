#define 	S_FUNCTION_LEVEL 	2
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_zmi4104_position_s

#include 	<stddef.h>
#include 	<stdlib.h>

#include 	"simstruc.h" 


#ifdef 		MATLAB_MEX_FILE
#include 	"mex.h"
#endif

#ifndef         MATLAB_MEX_FILE
#include        <windows.h>

#include    "xpcimports.h"
#include    "sg_vme_zmi4104.h"

#endif

/* Input Arguments */

#define NUMBER_OF_ARGS          (6)
#define SLOT_ARG                ssGetSFcnParam(S,0)
#define SAMPLETIME_ARG          ssGetSFcnParam(S,1)
#define ZMI4104ID_ARG           ssGetSFcnParam(S,2)
#define AXIS_ARG                ssGetSFcnParam(S,3)
#define ACTVEL_ARG              ssGetSFcnParam(S,4)
#define ACTTIME_ARG             ssGetSFcnParam(S,5)

#define NO_I_WORKS              (1)
#define AXIS_ADDR_I_IND         (0)

#define NO_R_WORKS              (0)

#define NO_P_WORKS              (0)

char msg[256];
 
/* Initialize Sizes ******************************************************/
static void mdlInitializeSizes(SimStruct *S)
{
    char msg[256];
    int32_T i;
    
    uint8_T act_velocity = (uint8_T)mxGetPr(ACTVEL_ARG)[0];
    uint8_T act_time = (uint8_T)mxGetPr(ACTTIME_ARG)[0];
    
    uint8_T nPort = 0;

    ssSetNumSFcnParams(S, NUMBER_OF_ARGS);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S))
    {
        sprintf(msg,"Wrong number of input arguments passed.\n%d arguments are expected\n", NUMBER_OF_ARGS);
        ssSetErrorStatus(S,msg);
    }

    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);
    
    ssSetNumSampleTimes(S, 1);

    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);
    
    

    for( i = 0 ; i < NUMBER_OF_ARGS ; i++ )
    {
        ssSetSFcnParamTunable(S,i,0);  /* None of the parameters are tunable */
    }

    ssSetNumInputPorts(S, 0);
    
    ssSetNumOutputPorts(S, 1 + act_velocity + act_time); 
    
    nPort = 0;
    
    // Position
    ssSetOutputPortWidth(S, nPort, 1);
    ssSetOutputPortDataType(S, nPort, SS_DOUBLE);
    nPort++;

    if (act_velocity == 1)
    {         
        ssSetOutputPortWidth(S, nPort, 1);
        ssSetOutputPortDataType(S, nPort, SS_DOUBLE);
        nPort++;
    }
    if (act_time == 1)
    {    
        ssSetOutputPortWidth(S, nPort, 1);
        ssSetOutputPortDataType(S, nPort, SS_DOUBLE);
        nPort++;
    } 
      

    ssSetNumRWork(S, NO_R_WORKS);
    ssSetNumIWork(S, NO_I_WORKS);
    ssSetNumPWork(S, NO_P_WORKS);
    
    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
}

/* Initialize Sample Times ***********************************************/
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

/* mdlStart **************************************************************/
#define MDL_START
static void mdlStart(SimStruct *S)
{
#ifndef MATLAB_MEX_FILE
    xpcPCIDevice pciinfo;

    volatile uint32_T *remotemem_bar;
    ZMI4104TYPE *ptAxis1, *ptAxis2, *ptAxis3, *ptAxis4;

    // Check PCI slot
    if ((int_T)mxGetPr(SLOT_ARG)[0]<0) 
    {
        xpcGetPCIDeviceInfo(VENDORID, DEVICEID, SUBVENDORID, SUBDEVICEID, XPC_NO_BUS_SLOT, XPC_NO_BUS_SLOT, &pciinfo);
    } 
    else 
    {
        uint16_T bus, slot;

        if (mxGetN(SLOT_ARG) == 1) 
        {
            bus = 0;
            slot = (uint16_T)mxGetPr(SLOT_ARG)[0];
        } 
        else 
        {
            bus = (uint16_T)mxGetPr(SLOT_ARG)[0];
            slot = (uint16_T)mxGetPr(SLOT_ARG)[1];
        }
        
        xpcGetPCIDeviceInfo(VENDORID, DEVICEID, SUBVENDORID, SUBDEVICEID, bus, slot, &pciinfo);
    }
    
    // Physical / Virtual BAR addresses assignment     
    pciinfo.VirtAddress[3] = (uint32_T*)xpcReserveMemoryRegion((uint32_T*)pciinfo.BaseAddress[3],
                                                                pciinfo.Length[1], 
                                                                XPC_RT_PG_USERREADWRITE);
    
    remotemem_bar = (volatile uint32_T*) (pciinfo.VirtAddress[3] & 0xFFFFFFF0);     // BAR3 (Remote Memory Window)

    if ((uint_T)mxGetPr(ZMI4104ID_ARG)[0] == 1)
    {
        ptAxis1 = &remotemem_bar[VME_REMOTE_ZMI_BOARD1_AXIS1];
        ptAxis2 = &remotemem_bar[VME_REMOTE_ZMI_BOARD1_AXIS2];
        ptAxis3 = &remotemem_bar[VME_REMOTE_ZMI_BOARD1_AXIS3];
        ptAxis4 = &remotemem_bar[VME_REMOTE_ZMI_BOARD1_AXIS4];
    }
    else if ((uint_T)mxGetPr(ZMI4104ID_ARG)[0] == 2)
    {
        ptAxis1 = &remotemem_bar[VME_REMOTE_ZMI_BOARD2_AXIS1];
        ptAxis2 = &remotemem_bar[VME_REMOTE_ZMI_BOARD2_AXIS2];
        ptAxis3 = &remotemem_bar[VME_REMOTE_ZMI_BOARD2_AXIS3];
        ptAxis4 = &remotemem_bar[VME_REMOTE_ZMI_BOARD2_AXIS4];
    }
    
    switch  ( (uint_T)mxGetPr(AXIS_ARG)[0] )
    {
        case 1: ssSetIWorkValue(S, AXIS_ADDR_I_IND, (int_T)ptAxis1);
                printf("Position Axis 1: Active\n");
                break;
                
        case 2: ssSetIWorkValue(S, AXIS_ADDR_I_IND, (int_T)ptAxis2);
                printf("Position Axis 2: Active\n");
                break;
                
        case 3: ssSetIWorkValue(S, AXIS_ADDR_I_IND, (int_T)ptAxis3);
                printf("Position Axis 3: Active\n");
                break;
                
        case 4: ssSetIWorkValue(S, AXIS_ADDR_I_IND, (int_T)ptAxis4);
                printf("Position Axis 4: Active\n");
                break;
    }
        
#endif
}

/* mdlOutput *************************************************************/
static void mdlOutputs(SimStruct *S, int_T tid)
{
#ifndef MATLAB_MEX_FILE
       
    real_T *ptOutPort_Pos; 
    real_T *ptOutPort_Vel; 
    real_T *ptOutPort_Time; 
    
    ZMI4104TYPE *ptZmiRegs;

    uint8_T act_velocity = (uint8_T)mxGetPr(ACTVEL_ARG)[0];
    uint8_T act_time = (uint8_T)mxGetPr(ACTTIME_ARG)[0];
    
    uint8_T nPort;
    
    uint16_T Data = 0x0000;
    
    
            
    ptZmiRegs = (ZMI4104TYPE *) ssGetIWorkValue(S, AXIS_ADDR_I_IND);
    
    //Data = zmiRead16(ptZmiRegs, ZMI_VME_COMMAND_REGISTER);
    Data = 0x0200;
    zmiWrite16(ptZmiRegs, ZMI_VME_COMMAND_REGISTER, Data);    

    ptOutPort_Pos = ssGetOutputPortSignal(S, 0);
    nPort = 1;
    
    if (act_velocity == 1)
    {
        ptOutPort_Vel = ssGetOutputPortSignal(S, nPort); 
        VmeZmiReadVelocity(ptZmiRegs, ptOutPort_Vel);
        nPort++;
    }
    
    if (act_time == 1)
    { 
        ptOutPort_Time = ssGetOutputPortSignal(S, nPort); 
        VmeZmiReadTime(ptZmiRegs, ptOutPort_Time); 
    }

    VmeZmiReadPosition(ptZmiRegs, ptOutPort_Pos);  
    
#endif
}

/* mdlTerminate **********************************************************/
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


