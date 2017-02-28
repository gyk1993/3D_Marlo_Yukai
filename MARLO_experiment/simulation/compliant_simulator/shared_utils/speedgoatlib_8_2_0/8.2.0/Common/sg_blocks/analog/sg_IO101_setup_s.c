/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1948+246-0x1a3c)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO101_setup_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x30\x31"
#define z694756a014 (0x1e83+2241-0x106f)
#define zea87e0ba83 17495
#define zdf24515981          ((0xdab+1071-0x11d7))
#define z702a26a5e9                ssGetSFcnParam(S,(0xd6+3120-0xd06))
#define z726c6b0744        ssGetSFcnParam(S,(0xb97+4722-0x1e08))
#define zf59d07c647        ssGetSFcnParam(S,(0xb53+1328-0x1081))
#define z2e6483d505              ((0x1727+711-0x19ed))
#define z6a0da049de         ((0x708+4524-0x18b4))
#define zc5ce4cb81a              ((0x128a+1236-0x175e))
#define z2b17e2ee3b              ((0x65+7258-0x1cbf))
static char_T zea4cd01646[(0x103d+1946-0x16d7)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x4e7+2198-0xd7d));ssSetNumDiscStates(S,(0xa6f+4139-0x1a9a));ssSetNumInputPorts(S,(0x1430+1140-0x18a4));ssSetNumOutputPorts(S,(0x8b4+5806-0x1f62));ssSetNumSampleTimes(S,(0x3b1+1433-0x949));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x173f+3196-0x23bb));ssSetNumNonsampledZCs(S,(0x18e1+1840-0x2011));for(i=(0xcb8+1741-0x1385);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x991+5622-0x1f87));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x5e0+6539-0x1f6b),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x13b4+1081-0x17ed),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;int_T base;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;int_T z049b04bd7f,z3b7a4946fb;char_T zda7b5a7e16[(0x642+654-0x8b2)];int_T z0add1d1c25;int_T z2b835486be;uint32_T z9d16154d3f,z88b41962cc;z049b04bd7f=5845;z3b7a4946fb=17495;strcpy(zda7b5a7e16,"\x41\x63\x72\x6f\x6d\x61\x67\x20\x50\x4d\x43\x37\x33\x30");if((int_T)mxGetPr(z702a26a5e9)[(0x4cd+7728-0x22fd)]<(0x909+3206-0x158f)){
if(rl32eGetPCIInfo((unsigned short)z049b04bd7f,(unsigned short)z3b7a4946fb,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zda7b5a7e16);ssSetErrorStatus(S,zea4cd01646);return;}}else{int_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x2344+98-0x23a5)){z366b2f03bf=(0x62a+1336-0xb62);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xe4b+61-0xe88)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x1854+1821-0x1f71)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x282+8446-0x237f)];}
if(rl32eGetPCIInfoAtSlot((unsigned short)z049b04bd7f,(unsigned short)z3b7a4946fb,(z441f9e6d1b&(0xb15+1051-0xe31))|((z366b2f03bf&(0x579+3188-0x10ee))<<(0x1719+934-0x1ab7)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zda7b5a7e16,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x3f4+3723-0x127f)];Virtual=rl32eGetDevicePtr(z1cf2c50191,4096,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);z9d16154d3f=(uint32_T)mxGetPr(z726c6b0744)[(0x414+6205-0x1c51)]-(0x580+2219-0xe2a);z88b41962cc=(uint32_T)mxGetPr(zf59d07c647)[(0x17d1+105-0x183a)]-(0x1585+776-0x188c);za42cf7dd4a[(0x1d59+1143-0x21c1)]=z9d16154d3f+(z88b41962cc<<(0x13c9+1547-0x19d3));
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

