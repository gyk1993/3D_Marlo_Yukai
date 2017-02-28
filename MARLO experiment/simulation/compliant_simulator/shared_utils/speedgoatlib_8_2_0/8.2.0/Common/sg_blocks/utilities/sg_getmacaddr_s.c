
#define S_FUNCTION_LEVEL   2
#undef  S_FUNCTION_NAME
#define S_FUNCTION_NAME    sg_getmacaddr_s

#include <stddef.h>
#include <stdlib.h>
#include "simstruc.h"

#ifndef MATLAB_MEX_FILE
#include <windows.h>
#include "xpctarget.h"
#include "xpcimports.h"
#endif



#ifdef MATLAB_MEX_FILE
#include "mex.h"
#endif


static void mdlInitializeSizes(SimStruct *S)
{
    ssSetNumSFcnParams(S, 0);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; /* Parameter mismatch will be reported by Simulink */
    }

    if (!ssSetNumInputPorts(S, 0)) return;

    if (!ssSetNumOutputPorts(S,1)) return;
    ssSetOutputPortWidth(S, 0, 6);
    ssSetOutputPortDataType(S, 0, SS_UINT8);

    ssSetNumSampleTimes(S, 1);

    ssSetOptions(S, SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME | SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE);

}

static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
    ssSetModelReferenceSampleTimeDefaultInheritance(S); 
}

#ifndef MATLAB_MEX_FILE
int (XPCCALLCONV *xpceGetMACAddress)(unsigned char *addr);
#endif

#define MDL_START
static void mdlStart(SimStruct *S) {
#ifndef MATLAB_MEX_FILE
    uint8_T *y;
    if ((xpceGetMACAddress = (void *)GetProcAddress(GetModuleHandle(NULL),
                                            "xpceGetMACAddress")) == NULL) {
        ssSetErrorStatus(S, "Could not find xpceGetMACAddress");
        return;
    }
    y = ssGetOutputPortSignal(S, 0);
    xpceGetMACAddress(y);
#endif
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
}

static void mdlTerminate(SimStruct *S)
{
}



#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif
