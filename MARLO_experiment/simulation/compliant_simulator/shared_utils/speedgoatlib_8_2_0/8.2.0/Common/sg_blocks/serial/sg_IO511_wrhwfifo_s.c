#define 	S_FUNCTION_LEVEL 	2
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO511_wrhwfifo_s

#include 	<stddef.h>
#include 	<stdlib.h>

#include 	"simstruc.h" 

#ifdef 		MATLAB_MEX_FILE
#include 	"mex.h"
#endif

#ifndef         MATLAB_MEX_FILE
#include        <windows.h>
#include        "xpcPCFunctions.h"
#include        "io_xpcimport.h"
//#include        "io511Adr.h"
#include        "pci_xpcimport.h"
#include        "time_xpcimport.h"
#include        "ioext_xpcimport.h"
#include        "util_xpcimport.h"
#endif

/* io511Adr */
#define BOARD_CONTROL_REG (0x0004/4)

/* USC */
#define CCAR_Hi 0x01
#define CCAR_Lo 0x00
#define CMR_Hi 0x03
#define CMR_Lo 0x02
#define CCSR_Hi 0x05
#define CCSR_Lo 0x04
#define CCR_Hi 0x07
#define CCR_Lo 0x06
#define CMCR_Hi 0x11
#define CMCR_Lo 0x10
#define IVR_Hi 0x15
#define IVR_Lo 0x14
#define HCR_Hi 0x13
#define HCR_Lo 0x12
#define IOCR_Hi 0x17
#define IOCR_Lo 0x16
#define ICR_Hi 0x19
#define ICR_Lo 0x18
#define DCCR_Hi 0x1B
#define DCCR_Lo 0x1A
#define MISR_Hi 0x1D
#define MISR_Lo 0x1C
#define SICR_Hi 0x1F
#define SICR_Lo 0x1E
#define RDR 0x20
#define RMR_Hi 0x23
#define RMR_Lo 0x22
#define RCSR_Hi 0x25
#define RCSR_Lo 0x24
#define RICR_Hi 0x27
#define RICR_Lo 0x26
#define RSR_Hi 0x29
#define RSR_Lo 0x28
#define RCLR_Hi 0x2B
#define RCLR_Lo 0x2A
#define RCCR_Hi 0x2D
#define RCCR_Lo 0x2C
#define TC0R_Hi 0x2F
#define TC0R_Lo 0x2E
#define TDR 0x30
#define TMR_Hi 0x33
#define TMR_Lo 0x32
#define TCSR_Hi 0x35
#define TCSR_Lo 0x34
#define TICR_Hi 0x37
#define TICR_Lo 0x36
#define TSR_Hi 0x39
#define TSR_Lo 0x38
#define TCLR_Hi 0x3B
#define TCLR_Lo 0x3A
#define TCCR_Hi 0x3D
#define TCCR_Lo 0x3C
#define TC1R_Hi 0x3F
#define TC1R_Lo 0x3E


/* Input Arguments */
#define NUMBER_OF_ARGS              (4)
#define SLOT_ARG                    ssGetSFcnParam(S,0)
#define SAMP_TIME_ARG               ssGetSFcnParam(S,1)
#define CHANNEL_ARG                 ssGetSFcnParam(S,2)
#define MAX_ARG                     ssGetSFcnParam(S,3)
    
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

    ssSetNumOutputPorts(S, 0);
    
    ssSetNumInputPorts(S, 2);
    ssSetInputPortDataType(S, 0, SS_UINT16); 
    ssSetInputPortWidth(S, 0, mxGetPr(MAX_ARG)[0] + 1);
    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortRequiredContiguous( S, 0, 1 );
    
    ssSetInputPortRequiredContiguous( S, 1, 1 ); 
    ssSetInputPortWidth(S, 1, 1 );
    ssSetInputPortDataType( S, 1, SS_UINT32 );
    ssSetInputPortDirectFeedThrough(S, 1, 1);

   
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
            sprintf(msg,"[Write HW Fifo]IO511 board not present");
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
            sprintf(msg,"[Write HW Fifo]: IO511 board (at bus %d, slot %d) not present", bus, slot );
            ssSetErrorStatus(S,msg);
            return;
        }
    }

    // Show device information
    //rl32eShowPCIInfo(pciinfo);

    Physical = (void *)pciinfo.BaseAddress[2]; 
    Virtual = rl32eGetDevicePtr(Physical, 2097152, RT_PG_USERREADWRITE);
    ioaddress=(volatile uint32_T *)Virtual;
    ssSetIWorkValue(S, BASE_ADDR_I_IND, (uint32_T)ioaddress);    

    
#endif
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
#ifndef MATLAB_MEX_FILE    
    uint32_T base = ssGetIWorkValue(S, BASE_ADDR_I_IND);
    volatile uint32_T *ioaddress32;
    uint32_T i;
    uint16_T  *ePtrUInt16;
    int32_T enable = *(int32_T *)ssGetInputPortSignal(S,1);
    uint32_T chan;

    EFLAGS_T flags;
    
    ioaddress32=(volatile uint32_T *) base;          
    
    if( enable > 0 ){
        
        /* Begining of critical section */
        flags = saveAndDisableInterrupts();
      
        ePtrUInt16= (uint16_T *)ssGetInputPortSignal(S, 0);
        chan = (uint32_T)mxGetPr(CHANNEL_ARG)[0] - 1;     
        
        /* TX FIFO (chan 1) is written - Access is performed via PIO. */
        for (i = 0; i < ePtrUInt16[0]; i++) {    
            ioaddress32[(0x18 + chan * 0x10)/4] = (uint8_T)(0xFF & ePtrUInt16[i + 1]);
        }   
        
        /* End of critical section */
        restoreInterrupts(flags);
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


