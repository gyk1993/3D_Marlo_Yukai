/* Curtiss Wright Controls embedded Computing */
/* SCRAMNet GT write function */

#define         S_FUNCTION_LEVEL        2
#undef          S_FUNCTION_NAME
#define         S_FUNCTION_NAME         cwcec_scgt_write

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
#define NUMBER_OF_ARGS        (4)
#define OFFSET_ARG            ssGetSFcnParam(S, 0)
#define NWORDS_ARG            ssGetSFcnParam(S, 1)
#define SAMPLETIME_ARG        ssGetSFcnParam(S, 2)
#define SLOT_ARG              ssGetSFcnParam(S, 3)

#define NO_I_WORKS            (1)
#define NO_R_WORKS            (0)
#define NO_P_WORKS            (0)

#define VENDOR_ID             (0x1387)
#define DEVICE_ID             (0x5310)
#define DEVICE_NAME           "SCRAMNet GT"

static char_T msg[256];

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

   ssSetNumInputPorts(S, 1);
   ssSetInputPortWidth(S, 0, (int_T)mxGetPr(NWORDS_ARG)[0]);
   ssSetInputPortDataType(S, 0, SS_UINT32);
   ssSetInputPortDirectFeedThrough(S, 0, 1);
   ssSetInputPortRequiredContiguous(S, 0, 1);

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

   /* Show Device Information */
   //rl32eShowPCIInfo(pciInfo);

   /* Map GT CSRs */
   PhysicalAddr = (void *)pciInfo.BaseAddress[0];
   VirtualAddr  = rl32eGetDevicePtr(PhysicalAddr, 0x100, RT_PG_USERREADWRITE);
   ioAddress32  = (void *)PhysicalAddr;

   /* Figure out the memory size */
   switch (ioAddress32[0] & 0x00000003)
   {
      case 0:
         memSize = 0x08000000;
         break;
      case 1:
         memSize = 0x10000000;
         break;
      case 2:
         memSize = 0x20000000;
         break;
      default:
         memSize = 0x08000000;
         break;
   }

   PhysicalAddr = (void *)pciInfo.BaseAddress[2];
   VirtualAddr  = rl32eGetDevicePtr(PhysicalAddr, memSize, RT_PG_USERREADWRITE);
   ioAddress32  = (void *)PhysicalAddr;

   ssSetIWorkValue(S, 0, (uint_T)ioAddress32);
#endif
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
#ifndef MATLAB_MEX_FILE
   uint32_T i;
   uint32_T *u = (uint32_T *)ssGetInputPortSignal(S, 0);
   uint32_T nwords = (uint32_T)mxGetPr(NWORDS_ARG)[0];
   uint32_T offset = (uint32_T)mxGetPr(OFFSET_ARG)[0];
   volatile unsigned long *ioAddress32 =
       (volatile unsigned long *)ssGetIWorkValue(S, 0);

   for (i = 0; i < nwords; i++)
   {
      ioAddress32[(offset / 4) + i] = u[i];
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
