/* Curtiss Wright Controls embedded Computing */
/* SCRAMNet GT Send Interrupt function */

#define         S_FUNCTION_LEVEL        2
#undef          S_FUNCTION_NAME
#define         S_FUNCTION_NAME         cwcec_scgt_send_interrupt

#include        <stddef.h>
#include        <stdlib.h>

#include        "simstruc.h"

#ifdef          MATLAB_MEX_FILE
#include        "mex.h"
#endif

#ifndef         MATLAB_MEX_FILE
#include        <windows.h>
#include        "io_xpcimport.h"
#include        "pci_xpcimport.h"
#endif

/* Input Arguments */
#define NUMBER_OF_ARGS        (2)
#define SAMPLETIME_ARG        ssGetSFcnParam(S, 0)
#define SLOT_ARG              ssGetSFcnParam(S, 1)

#define NO_I_WORKS            (1)
#define NO_R_WORKS            (0)
#define NO_P_WORKS            (0)

#define VENDOR_ID             (0x1387)
#define DEVICE_ID             (0x5310)
#define DEVICE_NAME           "SCRAMNet GT"

static char_T msg[256];

#include "cwcec_scgtdata.h"
  
static void mdlInitializeSizes(SimStruct *S)
{
#ifndef MATLAB_MEX_FILE
   #include "io_xpcimport.c"
   #include "pci_xpcimport.c"
#endif

   ssSetNumSFcnParams(S, NUMBER_OF_ARGS);
   if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S))
   {
      sprintf(msg, "Wrong number of input arguments passed.\n"
                   "%d arguments are expected\n", NUMBER_OF_ARGS);
      ssSetErrorStatus(S,msg);
      return;
   }

   ssSetNumContStates(S, 0);
   ssSetNumDiscStates(S, 0);

   ssSetNumOutputPorts(S, 0);

   if(ssSetNumInputPorts(S, 3) == 0)
   {
      sprintf(msg, "ssSetNumInputPorts returned 0, indicating a problem creating input ports.\n");
      ssSetErrorStatus(S,msg);
//      return;
   }
   
   ssSetInputPortWidth(S, 0, 1);
   ssSetInputPortDataType(S, 0, SS_UINT8);
   ssSetInputPortDirectFeedThrough(S, 0, 1);
   ssSetInputPortRequiredContiguous(S, 0, 1);
   
   ssSetInputPortWidth(S, 1, 1);
   ssSetInputPortDataType(S, 1, SS_UINT8);
   ssSetInputPortDirectFeedThrough(S, 1, 1);
   ssSetInputPortRequiredContiguous(S, 1, 1);
   
   ssSetInputPortWidth(S, 2, 1);
   ssSetInputPortDataType(S, 2, SS_UINT32);
   ssSetInputPortDirectFeedThrough(S, 2, 1);
   ssSetInputPortRequiredContiguous(S, 2, 1);

   ssSetNumSampleTimes(S, 1);

   ssSetNumRWork(S, NO_R_WORKS);
   ssSetNumIWork(S, NO_I_WORKS);
   ssSetNumPWork(S, NO_P_WORKS);

   ssSetNumModes(S, 0);
   ssSetNumNonsampledZCs(S, 0);

   ssSetOptions(S, SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE);
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
   uint32_T memSize;
        PCIDeviceInfo pciInfo;
   void *VirtualAddr, *PhysicalAddr;
   volatile unsigned long *ioAddress32;

   if ((int_T)mxGetPr(SLOT_ARG)[0] < 0)
   {
      /* Look for the SCRAMNet GT Device */
      if (rl32eGetPCIInfo((unsigned short)VENDOR_ID, (unsigned short)DEVICE_ID, &pciInfo))
      {
         sprintf(msg, "%s: Board Not Present!", DEVICE_NAME);
         ssSetErrorStatus(S,msg);
         return;
      }
   }
   else
   {
      int_T bus, slot;
      if (mxGetN(SLOT_ARG) == 1)
      {
         bus  = 0;
         slot = (int_T)mxGetPr(SLOT_ARG)[0];
      }
      else
      {
         bus  = (int_T)mxGetPr(SLOT_ARG)[0];
         slot = (int_T)mxGetPr(SLOT_ARG)[1];
      }
      /* Look for the SCRAMNet GT Device */
      if (rl32eGetPCIInfoAtSlot((unsigned short)VENDOR_ID, (unsigned short)DEVICE_ID, (slot & 0xff) | ((bus & 0xff) << 8), &pciInfo))
      {
         sprintf(msg,"%s (bus %d, slot %d): Board Not Present!", DEVICE_NAME, bus, slot );
         ssSetErrorStatus(S,msg);
         return;
      }
   }
   
   /* Map GT Network management registers */
   PhysicalAddr = (void *)pciInfo.BaseAddress[1];
   VirtualAddr  = rl32eGetDevicePtr(PhysicalAddr, 0x2000, RT_PG_USERREADWRITE);
   ioAddress32  = (void *)PhysicalAddr;

   /* store pointer to Network Management register mapped at BAR 1 address*/
   ssSetIWorkValue(S, 0, (uint_T)ioAddress32);
#endif
}



static void mdlOutputs(SimStruct *S, int_T tid)
{
#ifndef MATLAB_MEX_FILE
	/* get input paramater values */
   uint8_T  *interruptType =  (uint8_T *)ssGetInputPortSignal(S, 0);
   uint8_T  *input2        =  (uint8_T *)ssGetInputPortSignal(S, 1);
   uint32_T *input3        = (uint32_T *)ssGetInputPortSignal(S, 2);
   uint32_T value;
   uint8_T  id;
   /* Get pointer to Network Management registers */
   volatile unsigned long *ioAddress32 =
       (volatile unsigned long *)ssGetIWorkValue(S, 0);
   scgtDevice gtDev;
   scgtDevice *dev;
   dev = &gtDev;   
   /* update network management registers pointer in scrDevice structure before
      calling scgtWriteNMreg fucntion which uses this pointer */
   dev->nmRegPtr = ioAddress32;
   
   id    = *input2;
   value = *input3;
   

   if(*interruptType == SCGT_BROADCAST_INTR)
   {
	   if(id >31)
	   { 
		   sprintf(msg,"Send Interrupt error:Broadcast ID value %d outsize valid rang 0-31",id);
           ssSetErrorStatus(S,msg);
		   return;
	   }
	   scgtWriteNMReg(dev, GTCORE_NM_TX_HBI + (id * 4), value);
   }
   else  if(*interruptType == SCGT_UNICAST_INTR)
   {
	   scgtWriteNMReg(dev, GTCORE_NM_TX_HUI + (id * 4), value);       

   }
   else
   {
	   sprintf(msg,"Send Interrupt error: Unknown Interrupt type %d ",*interruptType);
       ssSetErrorStatus(S,msg);	
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
