/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xce4+33-0xd03)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO203_setup_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x32\x30\x33"
#define z694756a014 (0x235d+2907-0x1a20)
#define zea87e0ba83 (0xff4+6238-0x25a9)
#define zdf24515981          ((0x1796+1156-0x1c13))
#define z702a26a5e9                ssGetSFcnParam(S,(0xab3+6515-0x2426))
#define zf768aabc64     ssGetSFcnParam(S,(0xb26+1914-0x129f))
#define z048dc3d76c         ssGetSFcnParam(S,(0x3c0+7622-0x2184))
#define z2e390019d2         ssGetSFcnParam(S,(0x181a+3757-0x26c4))
#define z61407191e1     ssGetSFcnParam(S,(0x1ba+4078-0x11a4))
#define z229876d7a9         ssGetSFcnParam(S,(0x623+5948-0x1d5a))
#define zda06aecc0b         ssGetSFcnParam(S,(0x945+1221-0xe04))
#define z2e6483d505              ((0xc43+2312-0x1549))
#define z6a0da049de         ((0xb35+5825-0x21f6))
#define zc2f3e0cbc0        ((0xa68+4096-0x1a67))
#define zc5ce4cb81a              ((0x1e4f+964-0x2211))
#define z8caad2a8e6              ((0x277+6855-0x1d3e))
#define z5bfe7a2613            ((0x780+2731-0x122a))
#define z2b17e2ee3b              ((0xb13+5245-0x1f90))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0x2252+223-0x2231)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xbe4+3980-0x1b70));ssSetNumDiscStates(S,(0xfa+4289-0x11bb));ssSetNumInputPorts(S,(0x3ab+4233-0x1434));ssSetNumOutputPorts(S,(0x2161+16-0x2171));ssSetNumSampleTimes(S,(0xde6+5466-0x233f));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1d96+1945-0x252f));ssSetNumNonsampledZCs(S,(0x2387+446-0x2545));for(i=(0x79f+25-0x7b8);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x834+7325-0x24d1));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x759+2947-0x12dc),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1b68+1633-0x21c9),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zef529fae4a;void*ze2370ae9b9;volatile uint32_T*z3e5b8e05d8;void*zdfcb1da404;void*zf2db5722bf;volatile uint32_T*z27fd94ac66;uint_T i;uint32_T out;if((int_T)mxGetPr(z702a26a5e9)[(0x12b+6962-0x1c5d)]<(0x49+897-0x3ca)){
if(rl32eGetPCIInfo((uint16_T)z694756a014,(uint16_T)zea87e0ba83,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{int_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x13a0+4542-0x255d)){z366b2f03bf=(0x2d9+3527-0x10a0);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x87b+2384-0x11cb)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x11e8+1723-0x18a3)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x1e66+1045-0x227a)];}
if(rl32eGetPCIInfoAtSlot((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(z441f9e6d1b&(0xc84+1671-0x120c))|((z366b2f03bf&(0xe90+4870-0x2097))<<(0x6fc+6099-0x1ec7)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zef529fae4a=(void*)zeccbadd9b3.BaseAddress[(0x1454+96-0x14b4)];ze2370ae9b9=rl32eGetDevicePtr(zef529fae4a,(0x1b74+460-0x1b40),RT_PG_USERREADWRITE);z3e5b8e05d8=(volatile uint32_T*)ze2370ae9b9;zdfcb1da404=(void*)zeccbadd9b3.BaseAddress[(0xf64+1801-0x166b)];zf2db5722bf=rl32eGetDevicePtr(zdfcb1da404,(0x493+2512-0xd63),RT_PG_USERREADWRITE);z27fd94ac66=(volatile uint32_T*)zf2db5722bf;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)z27fd94ac66);

z3e5b8e05d8[(0x19f+2066-0x9a7)]=z3e5b8e05d8[(0x506+282-0x616)]&4278190079;
out=(0xab1+430-0xc5f);for(i=(0xf6a+4068-0x1f4e);i<(0xec7+2479-0x1856);i++){if(mxGetPr(zf768aabc64)[i]>=THRESHOLD){out|=(0x1069+1460-0x161c)<<i;}}z27fd94ac66[(0x1506+2927-0x2071)]=out;
out=(0x142d+1828-0x1b51);for(i=(0x513+1693-0xbb0);i<(0xb10+4345-0x1be9);i++){if(mxGetPr(z61407191e1)[i]>=THRESHOLD){out|=(0xbda+6009-0x2352)<<i;}}z27fd94ac66[(0x386+7950-0x228f)]=out;
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T i;volatile uint32_T*z27fd94ac66;uint32_T out;z27fd94ac66=(void*)base;out=z27fd94ac66[(0x8a7+7686-0x26ad)];for(i=(0x83+4481-0x1204);i<(0x1334+669-0x15b1);i++){if(xpceIsModelInit()||(uint32_T)mxGetPr(z048dc3d76c)[i]){if(mxGetPr(z2e390019d2)[i]>=THRESHOLD){out|=(0x15b1+3956-0x2524)<<i;}else{out&=~((0x7c1+7386-0x249a)<<i);}}}z27fd94ac66[(0x6b3+5469-0x1c10)]=out;out=z27fd94ac66[(0x1369+2979-0x1f0b)];for(i=(0x209+5446-0x174f);i<(0x1da6+2181-0x260b);i++){if(xpceIsModelInit()||(uint32_T)mxGetPr(z229876d7a9)[i]){if(mxGetPr(zda06aecc0b)[i]>=THRESHOLD){out|=(0x86c+4346-0x1965)<<i;}else{out&=~((0x12a3+3503-0x2051)<<i);}}}z27fd94ac66[(0x71b+2365-0x1057)]=out;
#endif    
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

