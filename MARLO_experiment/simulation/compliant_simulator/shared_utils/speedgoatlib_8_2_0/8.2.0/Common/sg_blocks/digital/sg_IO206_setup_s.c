/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1523+537-0x173a)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO206_setup_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x32\x30\x36"
#define z694756a014 (0x1cda+209-0x913)
#define zea87e0ba83 (0x1db1+1682-0x21eb)
#define zdf24515981          ((0x759+1740-0xe23))
#define z702a26a5e9                ssGetSFcnParam(S,(0x1779+3265-0x243a))
#define z1120e7330e            ssGetSFcnParam(S,(0x1706+1816-0x1e1d))
#define z2e6483d505              ((0x146b+4268-0x2515))
#define z6a0da049de         ((0x1cd+5924-0x18f1))
#define zc2f3e0cbc0        ((0x79c+3602-0x15ad))
#define zc5ce4cb81a              ((0xd22+4661-0x1f55))
#define z8caad2a8e6              ((0xf8b+2315-0x1896))
#define z5bfe7a2613            ((0x99f+3991-0x1935))
#define z2b17e2ee3b              ((0x14cd+3774-0x238b))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0xc17+78-0xb65)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x17ef+142-0x187d));ssSetNumDiscStates(S,(0x14cc+4441-0x2625));ssSetNumInputPorts(S,(0x1714+1444-0x1cb8));ssSetNumOutputPorts(S,(0xdad+4886-0x20c3));ssSetNumSampleTimes(S,(0x1129+3022-0x1cf6));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x494+7452-0x21b0));ssSetNumNonsampledZCs(S,(0x82d+1388-0xd99));for(i=(0x855+5124-0x1c59);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x4fc+1635-0xb5f));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x9a1+2251-0x126c),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x20f+4310-0x12e5),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zef529fae4a;void*ze2370ae9b9;volatile uint32_T*z3e5b8e05d8;void*zdfcb1da404;void*zf2db5722bf;volatile uint32_T*z27fd94ac66;uint_T i;uint32_T out;if((int_T)mxGetPr(z702a26a5e9)[(0x419+2633-0xe62)]<(0x1268+2565-0x1c6d)){
if(rl32eGetPCIInfo((uint16_T)z694756a014,(uint16_T)zea87e0ba83,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{int_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xa59+1972-0x120c)){z366b2f03bf=(0x60b+8070-0x2591);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x370+1967-0xb1f)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x4a9+7262-0x2107)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x8f+6021-0x1813)];}
if(rl32eGetPCIInfoAtSlot((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(z441f9e6d1b&(0x6a6+3258-0x1261))|((z366b2f03bf&(0x150b+510-0x160a))<<(0x199f+1533-0x1f94)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zef529fae4a=(void*)zeccbadd9b3.BaseAddress[(0x3c9+3085-0xfd6)];ze2370ae9b9=rl32eGetDevicePtr(zef529fae4a,(0x856+2273-0x10b7),RT_PG_USERREADWRITE);z3e5b8e05d8=(volatile uint32_T*)ze2370ae9b9;zdfcb1da404=(void*)zeccbadd9b3.BaseAddress[(0x33a+8-0x340)];zf2db5722bf=rl32eGetDevicePtr(zdfcb1da404,(0x10e1+3371-0x1dec),RT_PG_USERREADWRITE);z27fd94ac66=(volatile uint32_T*)zf2db5722bf;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)z27fd94ac66);

z3e5b8e05d8[(0x13bd+4862-0x26b1)]=z3e5b8e05d8[(0x149c+3321-0x218b)]&4278190079;
if(mxGetPr(z1120e7330e)[(0x831+1237-0xd06)]<0.0){z27fd94ac66[(0x777+2197-0x100b)]=(0x14b1+2501-0x1e76);}else{z27fd94ac66[(0xb2+3619-0xed4)]=(0x16cc+2366-0x2006);z27fd94ac66[(0x1aa2+109-0x1b09)]=(uint32_T)mxGetPr(z1120e7330e)[(0xd27+3427-0x1a8a)];}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T i;volatile uint32_T*z27fd94ac66;uint32_T out;z27fd94ac66=(void*)base;
#endif    
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

