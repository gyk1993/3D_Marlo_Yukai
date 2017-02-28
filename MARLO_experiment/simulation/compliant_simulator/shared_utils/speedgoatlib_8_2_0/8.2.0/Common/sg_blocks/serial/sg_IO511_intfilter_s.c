#define 	S_FUNCTION_LEVEL 	2
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO511_intfilter_s

#include 	<stddef.h>
#include 	<stdlib.h>

#include 	"simstruc.h" 

#ifdef 		MATLAB_MEX_FILE
#include 	"mex.h"
#endif

#ifndef         MATLAB_MEX_FILE
#include        <windows.h>
#include        "io_xpcimport.h"
#include        "pci_xpcimport.h"
#include        "time_xpcimport.h"
#include        "ioext_xpcimport.h"
#include        "util_xpcimport.h"
#endif

/* Input Arguments */
#define NUMBER_OF_ARGS              (5)
#define SLOT_ARG                    ssGetSFcnParam(S,0)
#define SAMP_TIME_ARG               ssGetSFcnParam(S,1)
#define DIRECTION_ARG               ssGetSFcnParam(S,2)
#define CHAN_ARG                    ssGetSFcnParam(S,3)
#define WIDTH_ARG                   ssGetSFcnParam(S,4)


#define NO_I_WORKS              (2)
#define CHANNELS_I_IND          (0)
#define BASE_ADDR_I_IND         (1)

#define NO_R_WORKS              (16)

#define NO_P_WORKS              (0)

static char_T msg[256];


static void mdlInitializeSizes(SimStruct *S)
{
    uint32_T i;

#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif

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
    ssSetOutputPortDataType(S, 0, SS_UINT32); 
    ssSetOutputPortWidth(S, 0, 1);

    ssSetNumInputPorts(S, 1);
    ssSetInputPortDataType(S, 0, SS_UINT32); 
    ssSetInputPortWidth(S, 0, 1);
    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortRequiredContiguous( S, 0, 1 );
    
    
    ssSetNumSampleTimes(S, 1);

    ssSetNumRWork(S, NO_R_WORKS);
    ssSetNumIWork(S, NO_I_WORKS);
    ssSetNumPWork(S, NO_P_WORKS);

    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    for( i = 0 ; i < NUMBER_OF_ARGS ; i++ )
    {
        ssSetSFcnParamTunable(S,i,0);  /* None of the parameters are tunable */
    }

    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE | SS_OPTION_PLACE_ASAP);
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
    if (mxGetPr(SAMP_TIME_ARG)[0]==-1.0)
    {
        ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
        ssSetOffsetTime(S, 0, FIXED_IN_MINOR_STEP_OFFSET);
    }
    else
    {
        ssSetSampleTime(S, 0, mxGetPr(SAMP_TIME_ARG)[0]);
        ssSetOffsetTime(S, 0, 0.0);
    }
}

#define MDL_START 
static void mdlStart(SimStruct *S)
{
#ifndef MATLAB_MEX_FILE
    PCIDeviceInfo pciinfo;
    void *Physical;
    void *Virtual;
    volatile uint32_T *ioaddress;
    uint16_T vendorid, deviceid, subvendorid, subdeviceid;

    
    vendorid= 0x10B5;
    deviceid= 0x9080;
    subvendorid= 0x10B5;
    subdeviceid= 0x2401;
    

    if ((int_T)mxGetPr(SLOT_ARG)[0]<0) {
        if (rl32eGetPCIInfoExt(vendorid, deviceid, subvendorid, subdeviceid, &pciinfo)) {
            sprintf(msg,"[Int filter]IO511 board not present");
            ssSetErrorStatus(S,msg);
            return;
        }
    } else {
        uint16_T bus, slot;
        if (mxGetN(SLOT_ARG) == 1) {
            bus = 0;
            slot = (uint16_T)mxGetPr(SLOT_ARG)[0];
        } else {
            bus = (uint16_T)mxGetPr(SLOT_ARG)[0];
            slot = (uint16_T)mxGetPr(SLOT_ARG)[1];
        }
        if (rl32eGetPCIInfoAtSlotExt(vendorid, deviceid, subvendorid, subdeviceid, (slot & 0xff) | ((bus & 0xff)<< 8), &pciinfo)) {
            sprintf(msg,"[Int filter]: IO511 board (at bus %d, slot %d) not present", bus, slot );
            ssSetErrorStatus(S,msg);
            return;
        }
    }

    Physical = (void *)pciinfo.BaseAddress[2]; 
    Virtual = rl32eGetDevicePtr(Physical, 2097152, RT_PG_USERREADWRITE);
    ioaddress=(volatile uint32_T *)Virtual;
    ssSetIWorkValue(S, BASE_ADDR_I_IND, (uint32_T)ioaddress);   

   
#endif
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
#ifndef MATLAB_MEX_FILE

    uint32_T *ePtrUInt32;
    uint32_T *ivr;
    uint32_T dir;   
    uint32_T chan;

    dir= (uint32_T)mxGetPr(DIRECTION_ARG)[0]; // 0 is TX, 1 is RX, 2 is USC
    chan= (uint32_T)mxGetPr(CHAN_ARG)[0] - 1;
    ePtrUInt32= (uint32_T *)ssGetOutputPortSignal(S,0);
    ivr = (uint32_T *)ssGetInputPortSignal(S,0);
       
    //printf("ivr: 0x%X\n", ivr[0]);
   
    switch (dir){
        case 0: 
            if ( (ivr[0] & (0x2 << 0x4*chan)) == (0x2 << 0x4*chan) ){
                ePtrUInt32[0] = (uint32_T)mxGetPr(WIDTH_ARG)[0];
            }
            else{
                ePtrUInt32[0] = 0;
            }    
            break;
            
        case 1:
            if ( (ivr[0] & (0x4 << 0x4*chan)) == (0x4 << 0x4*chan) ){
                ePtrUInt32[0] = (uint32_T)mxGetPr(WIDTH_ARG)[0];
            }
            else{
                ePtrUInt32[0] = 0;
            }  
            break;
            
        case 2:
            if ( (ivr[0] & (0x8 << 0x4*chan)) == (0x8 << 0x4*chan) ){
                printf("INT!\n");
                ePtrUInt32[0] = 1;
            }
            else{
                ePtrUInt32[0] = 0;
            }  
            break;
            
        default:
            sprintf(msg,"Invalid parameter for interrupt source, correct value is 0, 1 or 2.");
            ssSetErrorStatus(S,msg);
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


