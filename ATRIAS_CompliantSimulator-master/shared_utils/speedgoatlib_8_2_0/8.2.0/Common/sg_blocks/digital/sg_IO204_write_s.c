/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xe2b+669-0x10c6)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO204_write_s
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
#define z694756a014 (0x18af+3738-0x12b1)
#define zea87e0ba83 (0xccc+3823-0x191c)
#define zdf24515981          ((0x141a+2511-0x1de6))
#define z2cc9a52544            ssGetSFcnParam(S,(0x15d7+4055-0x25ae))
#define z3832b85a32           ssGetSFcnParam(S,(0xce2+3562-0x1acb))
#define z702a26a5e9                ssGetSFcnParam(S,(0x52f+2604-0xf59))
#define z2e6483d505              ((0xcf6+2947-0x1877))
#define z6a0da049de         ((0x27c+326-0x3c2))
#define zc2f3e0cbc0        ((0x859+3436-0x15c4))
#define zc5ce4cb81a              ((0x1efc+476-0x20d8))
#define z2b17e2ee3b              ((0xa44+453-0xc09))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0x1d39+1544-0x2241)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x10db+1436-0x1677));ssSetNumDiscStates(S,(0x801+5674-0x1e2b));ssSetNumOutputPorts(S,(0x644+8039-0x25ab));switch((uint8_T)mxGetPr(z2cc9a52544)[(0x10c4+1330-0x15f6)]){case(0x15e0+473-0x17b8):ssSetNumInputPorts(S,(0x640+5219-0x1a93));for(i=(0xee4+3349-0x1bf9);i<(0xaf8+3740-0x1984);i++){ssSetInputPortWidth(S,i,(0x151b+2156-0x1d86));ssSetInputPortRequiredContiguous(S,i,(0xa77+1221-0xf3b));}break;case(0x634+6361-0x1f0b):ssSetNumInputPorts(S,(0x9fd+5119-0x1dec));for(i=(0x316+4576-0x14f6);i<(0xe03+2888-0x193b);i++){ssSetInputPortWidth(S,i,(0x5d1+2224-0xe80));ssSetInputPortDataType(S,i,SS_BOOLEAN);ssSetInputPortRequiredContiguous(S,i,(0x438+1862-0xb7d));}break;case(0xe10+3426-0x1b6f):ssSetNumInputPorts(S,(0xd9c+6354-0x266d));ssSetInputPortWidth(S,(0x2cf+1088-0x70f),(0x67b+3317-0x1360));ssSetInputPortRequiredContiguous(S,(0xc91+1943-0x1428),(0x2d8+4478-0x1455));break;case(0x4fa+8342-0x258c):ssSetNumInputPorts(S,(0x542+71-0x588));ssSetInputPortWidth(S,(0x2073+322-0x21b5),(0x123b+4117-0x2240));ssSetInputPortDataType(S,(0x154d+1088-0x198d),SS_BOOLEAN);ssSetInputPortRequiredContiguous(S,(0x1da+3299-0xebd),(0x1322+478-0x14ff));break;case(0x3bb+1080-0x7ee):ssSetNumInputPorts(S,(0x1956+291-0x1a78));ssSetInputPortWidth(S,(0x1384+1093-0x17c9),(0x1f05+1024-0x2304));ssSetInputPortDataType(S,(0x2a2+3863-0x11b9),SS_UINT16);ssSetInputPortRequiredContiguous(S,(0x1cd7+2600-0x26ff),(0x1fc+8216-0x2213));break;}ssSetNumSampleTimes(S,(0xda1+3849-0x1ca9));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1097+4797-0x2354));ssSetNumNonsampledZCs(S,(0x959+5143-0x1d70));for(i=(0x1176+2397-0x1ad3);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xe67+4955-0x21c2));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x3a6+3966-0x1324)]==-1.0){ssSetSampleTime(S,(0x217+8339-0x22aa),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xcd1+1059-0x10f4),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x34a+3739-0x11e5),mxGetPr(z3832b85a32)[(0x705+3575-0x14fc)]);ssSetOffsetTime(S,(0x968+302-0xa96),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zef529fae4a;void*ze2370ae9b9;volatile uint32_T*z3e5b8e05d8;void*zdfcb1da404;void*zf2db5722bf;volatile uint16_T*z27fd94ac66;uint_T i;uint16_T out;if((int_T)mxGetPr(z702a26a5e9)[(0xdc3+4945-0x2114)]<(0x24c6+26-0x24e0)){
if(rl32eGetPCIInfo((uint16_T)z694756a014,(uint16_T)zea87e0ba83,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{int_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x44c+7536-0x21bb)){z366b2f03bf=(0x17b+4589-0x1368);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x8bd+3464-0x1645)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x170a+2735-0x21b9)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x18c7+2167-0x213d)];}
if(rl32eGetPCIInfoAtSlot((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(z441f9e6d1b&(0x10d4+1824-0x16f5))|((z366b2f03bf&(0x1ef1+349-0x1f4f))<<(0x712+6278-0x1f90)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zef529fae4a=(void*)zeccbadd9b3.BaseAddress[(0x615+5534-0x1bb3)];ze2370ae9b9=rl32eGetDevicePtr(zef529fae4a,(0x216b+153-0x2184),RT_PG_USERREADWRITE);z3e5b8e05d8=(volatile uint32_T*)ze2370ae9b9;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)zeccbadd9b3.BaseAddress[(0x1a20+1840-0x214e)]);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint16_T base=(uint16_T)ssGetIWorkValue(S,z6a0da049de);volatile uint16_T*z27fd94ac66;uint16_T i,output;real_T*y1;boolean_T*y2;uint16_T*z671e76e748;
switch((uint8_T)mxGetPr(z2cc9a52544)[(0x523+2672-0xf93)]){case(0xcab+2381-0x15f7):output=(0x132b+4389-0x2450);for(i=(0x37c+5058-0x173e);i<(0x6f8+5521-0x1c79);i++){y1=(real_T*)ssGetInputPortSignal(S,i);if(y1[(0xe1d+1920-0x159d)]>=THRESHOLD){output|=(0xc06+1134-0x1073)<<i;}}break;case(0xf98+1269-0x148b):output=(0x12cd+91-0x1328);for(i=(0xfa2+2836-0x1ab6);i<(0x1972+3362-0x2684);i++){y2=(boolean_T*)ssGetInputPortSignal(S,i);if(y2[(0x99+4717-0x1306)]){output|=(0x1995+2981-0x2539)<<i;}}break;case(0x1449+1913-0x1bbf):output=(0x80f+5384-0x1d17);y1=(real_T*)ssGetInputPortSignal(S,(0x14a4+3148-0x20f0));for(i=(0x19e1+1324-0x1f0d);i<(0x16b8+4049-0x2679);i++){if(y1[i]>=THRESHOLD){output|=(0xb0+3649-0xef0)<<i;}}break;case(0x1450+1999-0x1c1b):output=(0x15b6+3089-0x21c7);y2=(boolean_T*)ssGetInputPortSignal(S,(0x7c6+7165-0x23c3));for(i=(0x1420+3352-0x2138);i<(0xed2+1407-0x1441);i++){if(y2[i]){output|=(0x10ba+345-0x1212)<<i;}}break;case(0x772+7603-0x2520):z671e76e748=(uint16_T*)ssGetInputPortSignal(S,(0xe08+4046-0x1dd6));output=z671e76e748[(0x757+3990-0x16ed)];break;}

rl32eOutpW(base+(0x51f+5627-0x1b1a),output);
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

