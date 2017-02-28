/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xd7f+3960-0x1cf5)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO205_setup_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x32\x30\x35"
#define z694756a014 (0x14a4+8268-0x2058)
#define zea87e0ba83 (0x766+6714-0x1ee4)
#define zdf24515981          ((0xabf+4685-0x1d09))
#define z702a26a5e9                ssGetSFcnParam(S,(0x206c+24-0x2084))
#define zc8bbaa6115               ssGetSFcnParam(S,(0x179+2811-0xc73))
#define zd1b4794672               ssGetSFcnParam(S,(0xbb2+5759-0x222f))
#define z2e6483d505              ((0x1215+4954-0x256d))
#define z6a0da049de         ((0x706+6308-0x1faa))
#define zc2f3e0cbc0        ((0x807+4441-0x195f))
#define zc5ce4cb81a              ((0xc2+5185-0x1501))
#define z8caad2a8e6              ((0x974+1484-0xf40))
#define z5bfe7a2613            ((0x231+1601-0x871))
#define z2b17e2ee3b              ((0xbe5+4046-0x1bb3))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0x1d42+1321-0x216b)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xdcb+1809-0x14dc));ssSetNumDiscStates(S,(0x657+2165-0xecc));ssSetNumInputPorts(S,(0x1234+5027-0x25d7));ssSetNumOutputPorts(S,(0x181b+981-0x1bf0));ssSetNumSampleTimes(S,(0x864+6301-0x2100));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x7c2+6890-0x22ac));ssSetNumNonsampledZCs(S,(0x1d11+238-0x1dff));for(i=(0x17ab+3229-0x2448);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xfa+1050-0x514));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x393+6974-0x1ed1),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x340+1323-0x86b),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zef529fae4a;void*ze2370ae9b9;volatile uint32_T*z3e5b8e05d8;void*zdfcb1da404;void*zf2db5722bf;volatile uint32_T*z27fd94ac66;uint_T i;uint32_T out;if((int_T)mxGetPr(z702a26a5e9)[(0x1094+4854-0x238a)]<(0x5e3+2515-0xfb6)){
if(rl32eGetPCIInfo((uint16_T)z694756a014,(uint16_T)zea87e0ba83,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{int_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x9a8+2662-0x140d)){z366b2f03bf=(0x58f+8388-0x2653);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x23b6+353-0x2517)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x289+8690-0x247b)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x156c+2603-0x1f96)];}
if(rl32eGetPCIInfoAtSlot((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(z441f9e6d1b&(0x833+5900-0x1e40))|((z366b2f03bf&(0x1979+2933-0x23ef))<<(0x13f6+3258-0x20a8)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zef529fae4a=(void*)zeccbadd9b3.BaseAddress[(0x828+3565-0x1615)];ze2370ae9b9=rl32eGetDevicePtr(zef529fae4a,(0x1d86+514-0x1f08),RT_PG_USERREADWRITE);z3e5b8e05d8=(volatile uint32_T*)ze2370ae9b9;zdfcb1da404=(void*)zeccbadd9b3.BaseAddress[(0xa1d+6326-0x22d1)];zf2db5722bf=rl32eGetDevicePtr(zdfcb1da404,(0x863+5925-0x1f78),RT_PG_USERREADWRITE);z27fd94ac66=(volatile uint32_T*)zf2db5722bf;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)z27fd94ac66);

z3e5b8e05d8[(0xd31+5467-0x2282)]=z3e5b8e05d8[(0x19b6+2762-0x2476)]&4278190079;
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T i;volatile uint32_T*z27fd94ac66;uint32_T out;z27fd94ac66=(void*)base;out=z27fd94ac66[(0x1214+2552-0x1c0c)];for(i=(0x1b54+2129-0x23a5);i<(0x1453+4548-0x25f7);i++){if(xpceIsModelInit()||(uint32_T)mxGetPr(zc8bbaa6115)[i]){if(mxGetPr(zd1b4794672)[i]>=THRESHOLD){out|=(0x16c+4694-0x13c1)<<i;}else{out&=~((0x83+3366-0xda8)<<i);}}}z27fd94ac66[(0x6b5+5875-0x1da8)]=out;
#endif    
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

