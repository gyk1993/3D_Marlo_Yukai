/* Copyright 2006-2013 Speedgoat GmbH. */
#define         S_FUNCTION_LEVEL        (0x591+3486-0x132d)
#undef          S_FUNCTION_NAME
#define         S_FUNCTION_NAME         sg_IO114B_di_s
#include        <stddef.h>
#include        <stdlib.h>
#include        "simstruc.h"
#ifdef          MATLAB_MEX_FILE
#include        "mex.h"
#endif
#ifndef         MATLAB_MEX_FILE
#include        <windows.h>
#include        "xpctarget.h"
#endif
#define zdf24515981          ((0xd1d+1492-0x12ee))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0x921+7017-0x248a))
#define zabe1e0cd2c          ssGetSFcnParam(S,(0xd86+5294-0x2233))
#define z702a26a5e9                ssGetSFcnParam(S,(0x8fc+5114-0x1cf4))
#define zc5ce4cb81a              ((0x2e7+8333-0x2374))
#define z2b17e2ee3b              ((0x418+2328-0xd30))
#define z2e6483d505              ((0x1641+3503-0x23ef))
#define z6a0da049de         ((0x842+4608-0x1a42))
static char_T zea4cd01646[(0xabd+1626-0x1017)];
#define z694756a014        (0x1585+9585-0x26ac)
#define zea87e0ba83        25352
#define z29146a1837     (0x15ba+7188-0x1d84)
#define zab7e64468b     25512
#define zf1b619edf2         "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x31\x34\x42"
static void mdlInitializeSizes(SimStruct*S){int i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x1a+7945-0x1f23));ssSetNumDiscStates(S,(0xf4f+314-0x1089));ssSetNumInputPorts(S,(0x1183+3665-0x1fd4));ssSetNumOutputPorts(S,(int_T)mxGetN(za9d8fb6bcf));for(i=(0x1770+764-0x1a6c);i<(int)mxGetN(za9d8fb6bcf);i++){ssSetOutputPortWidth(S,i,(0x1481+820-0x17b4));}ssSetNumSampleTimes(S,(0x2dc+3900-0x1217));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1678+1739-0x1d43));ssSetNumNonsampledZCs(S,(0xf72+5383-0x2479));for(i=(0xaac+1733-0x1171);i<zdf24515981;i++){ssSetSFcnParamNotTunable(S,i);}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(zabe1e0cd2c)[(0x8a3+1500-0xe7f)]==-1.0){ssSetSampleTime(S,(0x114a+4866-0x244c),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x7e5+7346-0x2497),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x11e6+4634-0x2400),mxGetPr(zabe1e0cd2c)[(0xd10+1942-0x14a6)]);ssSetOffsetTime(S,(0x1866+2474-0x2210),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;volatile uint32_T z5fcf9921e0;int_T z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0xc05+3054-0x17f3)];int_T z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x18ca+2874-0x2403)];
if(xpcGetPCIDeviceInfo((unsigned short)z694756a014,(unsigned short)zea87e0ba83,(unsigned short)z29146a1837,(unsigned short)zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}z5fcf9921e0=(uint32_T)zeccbadd9b3.BaseAddress[(0x563+3930-0x14bb)];
ssSetIWorkValue(S,z6a0da049de,(uint32_T)z5fcf9921e0);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
volatile uint32_T z5fcf9921e0=(uint32_T)ssGetIWorkValue(S,z6a0da049de);int_T zf91d71c6d9=mxGetN(za9d8fb6bcf);int_T i;int_T z4e3026977c;real_T*y;uint16_T zf67144ac88;zf67144ac88=xpcInpW(z5fcf9921e0+(0x1a4f+754-0x1d01));
for(i=(0xa86+404-0xc1a);i<zf91d71c6d9;i++){y=ssGetOutputPortSignal(S,i);z4e3026977c=(int_T)mxGetPr(za9d8fb6bcf)[i]-(0x731+3149-0x137d);if(zf67144ac88&((0x436+3645-0x1272)<<z4e3026977c))y[(0x415+910-0x7a3)]=(0x10fd+3718-0x1f82);else y[(0xc8d+601-0xee6)]=(0x35b+5358-0x1849);}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

