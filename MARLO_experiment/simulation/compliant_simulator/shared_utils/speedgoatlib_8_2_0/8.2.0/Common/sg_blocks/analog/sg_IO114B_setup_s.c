/* Copyright 2006-2013 Speedgoat GmbH. */
#define         S_FUNCTION_LEVEL        (0x356+5242-0x17ce)
#undef          S_FUNCTION_NAME
#define         S_FUNCTION_NAME         sg_IO114B_setup_s
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
#define zdf24515981          ((0x10dd+803-0x13fe))
#define z8fd86139be               ssGetSFcnParam(S,(0x421+296-0x549))
#define z702a26a5e9                ssGetSFcnParam(S,(0x18d+8949-0x2481))
#define zc5ce4cb81a              ((0x2013+1426-0x25a5))
#define z2e6483d505              ((0x1976+858-0x1cd0))
#define z2b17e2ee3b              ((0xbcb+5842-0x229d))
static char_T zea4cd01646[(0xaf2+1441-0xf93)];
#define z694756a014        5194
#define zea87e0ba83        25352
#define z29146a1837     (0x1660+8214-0x222c)
#define zab7e64468b     25512
#define zf1b619edf2         "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x31\x34\x42"
static void mdlInitializeSizes(SimStruct*S){int i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x1d8f+316-0x1ecb));ssSetNumDiscStates(S,(0x236+567-0x46d));ssSetNumInputPorts(S,(0xb72+2765-0x163f));ssSetNumOutputPorts(S,(0x1c70+2262-0x2546));ssSetNumSampleTimes(S,(0xc30+3615-0x1a4e));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xd17+2044-0x1513));ssSetNumNonsampledZCs(S,(0xb50+2824-0x1658));for(i=(0xf4+2538-0xade);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x496+4506-0x1630));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x3ad+2609-0xdde),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1485+4147-0x24b8),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;volatile uint32_T ze8382fc3a1;int_T z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x443+1371-0x99e)];int_T z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x11a8+2981-0x1d4c)];
if(xpcGetPCIDeviceInfo((unsigned short)z694756a014,(unsigned short)zea87e0ba83,(unsigned short)z29146a1837,(unsigned short)zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}ze8382fc3a1=(uint32_T)zeccbadd9b3.BaseAddress[(0xce7+395-0xe71)];if(xpcIsModelInit()){

xpcOutpB(ze8382fc3a1+(0xa4d+5932-0x2129),(0x403+908-0x6fa));



switch((int)mxGetPr(z8fd86139be)[(0x102a+4640-0x224a)]){case(0xd15+635-0xf8f):
printf("\x25\x73\x20\x3a\x20\x30\x2e\x2e\x32\x30\x6d\x41" "\n",zf1b619edf2);xpcOutpB(ze8382fc3a1+(0x1711+2416-0x2030),(0x1de2+2034-0x25b0));break;case(0xa6f+569-0xca6):
printf("\x25\x73\x20\x3a\x20\x35\x2e\x2e\x32\x35\x6d\x41" "\n",zf1b619edf2);xpcOutpB(ze8382fc3a1+(0x419+8781-0x2615),(0x1590+1535-0x1b63));break;case(0x2c5+413-0x45f):
printf("\x25\x73\x20\x3a\x20\x34\x2e\x2e\x32\x30\x6d\x41" "\n",zf1b619edf2);xpcOutpB(ze8382fc3a1+(0x7cd+6613-0x2151),(0x18ec+2553-0x22b8));break;}xpcBusyWait(500e-6);}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
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

