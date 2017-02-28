/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xaff+1614-0x114b)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO204_setup_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x32\x30\x34"
#define z694756a014 (0x1caf+4084-0x180b)
#define zea87e0ba83 (0x109d+5032-0x21a6)
#define zdf24515981          ((0xd7a+4352-0x1e76))
#define z702a26a5e9                ssGetSFcnParam(S,(0xead+1753-0x1586))
#define z1120e7330e            ssGetSFcnParam(S,(0xf07+4242-0x1f98))
#define zc8bbaa6115               ssGetSFcnParam(S,(0x9d4+5572-0x1f96))
#define zd1b4794672               ssGetSFcnParam(S,(0x19da+2288-0x22c7))
#define z2e6483d505              ((0x1a8b+2888-0x25d1))
#define z6a0da049de         ((0x1a78+352-0x1bd8))
#define zc2f3e0cbc0        ((0x1ec6+1359-0x2414))
#define zc5ce4cb81a              ((0x1b1c+2387-0x246d))
#define z8caad2a8e6              ((0x10d2+752-0x13c2))
#define z5bfe7a2613            ((0x2da+8090-0x2273))
#define z2b17e2ee3b              ((0x1383+1685-0x1a18))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0x65f+1549-0xb6c)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x463+629-0x6d8));ssSetNumDiscStates(S,(0xd67+1023-0x1166));ssSetNumInputPorts(S,(0x131f+1075-0x1752));ssSetNumOutputPorts(S,(0x6f1+1806-0xdff));ssSetNumSampleTimes(S,(0x1979+3023-0x2547));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x178b+3215-0x241a));ssSetNumNonsampledZCs(S,(0x93b+4113-0x194c));for(i=(0xa4d+6433-0x236e);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1577+1874-0x1cc9));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x7e3+5391-0x1cf2),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1e55+707-0x2118),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zef529fae4a;void*ze2370ae9b9;volatile uint32_T*z3e5b8e05d8;uint_T i;uint32_T out;uint16_T base;


if((int_T)mxGetPr(z702a26a5e9)[(0x79c+5043-0x1b4f)]<(0xe51+4916-0x2185)){
if(rl32eGetPCIInfo((uint16_T)z694756a014,(uint16_T)zea87e0ba83,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{int_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xbaa+2449-0x153a)){z366b2f03bf=(0x1338+1824-0x1a58);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x11a8+309-0x12dd)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0xfa6+433-0x1157)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x1365+2808-0x1e5c)];}
if(rl32eGetPCIInfoAtSlot((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(z441f9e6d1b&(0xed9+3586-0x1bdc))|((z366b2f03bf&(0x108c+4826-0x2267))<<(0x60+8532-0x21ac)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zef529fae4a=(void*)zeccbadd9b3.BaseAddress[(0x19d5+1699-0x2078)];ze2370ae9b9=rl32eGetDevicePtr(zef529fae4a,(0xbc+2148-0x8a0),RT_PG_USERREADWRITE);z3e5b8e05d8=(volatile uint32_T*)ze2370ae9b9;base=zeccbadd9b3.BaseAddress[(0x696+1651-0xd07)];ssSetIWorkValue(S,z6a0da049de,base);

z3e5b8e05d8[(0x463+6291-0x1cec)]=z3e5b8e05d8[(0x392+4881-0x1699)]&4278190079;
if(mxGetPr(z1120e7330e)[(0x61d+455-0x7e4)]<0.0){rl32eOutpW(base+(0xe6+3877-0x1009),(0x134+2878-0xc72));
}else{rl32eOutpW(base+(0x71+7504-0x1dbf),(0x192+364-0x2fa));rl32eOutpW(base+(0x1ed5+913-0x225f),(uint16_T)mxGetPr(z1120e7330e)[(0x11f+9537-0x2660)]);

}

z3e5b8e05d8[(0x8f8+1971-0x105f)/(0xfdf+5472-0x253b)]&=~(0x559+5348-0x193e);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint16_T base=(uint16_T)ssGetIWorkValue(S,z6a0da049de);uint16_T i;volatile uint16_T*z27fd94ac66;uint32_T out;z27fd94ac66=(void*)base;
rl32eOutpW(base+(0x2ef+859-0x64a),(0x539+1757-0xc16));for(i=(0xcbd+5634-0x22bf);i<(0xd5a+5440-0x228a);i++){if(xpceIsModelInit()||(uint32_T)mxGetPr(zc8bbaa6115)[i]){if(mxGetPr(zd1b4794672)[i]>=THRESHOLD){out|=(0x1796+1963-0x1f40)<<i;}else{out&=~((0x1054+2132-0x18a7)<<i);}}}rl32eOutpW(base+(0x8fa+6723-0x233d),out);
#endif    
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

