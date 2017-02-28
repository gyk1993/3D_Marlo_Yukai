/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x18fd+2356-0x222f)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO203_read_s
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
#define z694756a014 (0x19b2+920-0x8b2)
#define zea87e0ba83 (0x1936+3063-0x2284)
#define zdf24515981          ((0xd19+6109-0x24f2))
#define z2cc9a52544            ssGetSFcnParam(S,(0x198b+1736-0x2053))
#define ze072c43310               ssGetSFcnParam(S,(0x128f+1713-0x193f))
#define z3832b85a32           ssGetSFcnParam(S,(0x1461+2002-0x1c31))
#define z702a26a5e9                ssGetSFcnParam(S,(0x188f+1601-0x1ecd))
#define z2e6483d505              ((0x5b8+6191-0x1de5))
#define z6a0da049de         ((0x2ea+7706-0x2104))
#define zc2f3e0cbc0        ((0xab7+797-0xdd3))
#define zc5ce4cb81a              ((0x13a6+2562-0x1da8))
#define z2b17e2ee3b              ((0xe35+5751-0x24ac))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0x1a04+3024-0x24d4)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x8cd+2937-0x1446));ssSetNumDiscStates(S,(0x121d+2844-0x1d39));ssSetNumInputPorts(S,(0xfe0+5086-0x23be));switch((uint8_T)mxGetPr(z2cc9a52544)[(0x154+306-0x286)]){case(0x176+2595-0xb98):ssSetNumOutputPorts(S,(0x7e9+2798-0x12b7));for(i=(0x357+1202-0x809);i<(0x660+5368-0x1b38);i++){ssSetOutputPortWidth(S,i,(0xb5b+6947-0x267d));}break;case(0x9fa+2924-0x1564):ssSetNumOutputPorts(S,(0x524+3324-0x1200));for(i=(0xf5c+4527-0x210b);i<(0x4e9+6131-0x1cbc);i++){ssSetOutputPortWidth(S,i,(0x108+8626-0x22b9));ssSetOutputPortDataType(S,i,SS_BOOLEAN);}break;case(0x8bd+3490-0x165c):ssSetNumOutputPorts(S,(0xd80+2612-0x17b3));ssSetOutputPortWidth(S,(0x211c+1072-0x254c),(0x1dd6+2244-0x267a));break;case(0xdf+5489-0x164c):ssSetNumOutputPorts(S,(0x1246+1795-0x1948));ssSetOutputPortWidth(S,(0x1444+0-0x1444),(0x1320+4129-0x2321));ssSetOutputPortDataType(S,(0x15cf+2942-0x214d),SS_BOOLEAN);break;case(0xcf3+4321-0x1dcf):ssSetNumOutputPorts(S,(0x136+1605-0x77a));ssSetOutputPortWidth(S,(0x1014+1755-0x16ef),(0xa79+2943-0x15f7));ssSetOutputPortDataType(S,(0xd9b+3932-0x1cf7),SS_UINT32);break;}ssSetNumSampleTimes(S,(0x12cf+561-0x14ff));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xd66+5948-0x24a2));ssSetNumNonsampledZCs(S,(0x215a+193-0x221b));for(i=(0x7ba+765-0xab7);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x15a2+94-0x1600));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x95b+1933-0x10e8)]==-1.0){ssSetSampleTime(S,(0x10a3+3202-0x1d25),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xd94+1714-0x1446),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x937+5348-0x1e1b),mxGetPr(z3832b85a32)[(0x1289+3692-0x20f5)]);ssSetOffsetTime(S,(0x13a5+746-0x168f),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zef529fae4a;void*ze2370ae9b9;volatile uint32_T*z3e5b8e05d8;void*zdfcb1da404;void*zf2db5722bf;volatile uint32_T*z27fd94ac66;uint_T i;uint32_T out;if((int_T)mxGetPr(z702a26a5e9)[(0x3e3+7917-0x22d0)]<(0x9a2+87-0x9f9)){
if(rl32eGetPCIInfo((uint16_T)z694756a014,(uint16_T)zea87e0ba83,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{int_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x1ea2+2111-0x26e0)){z366b2f03bf=(0x802+1989-0xfc7);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x11a8+3349-0x1ebd)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x100a+1930-0x1794)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x1590+3896-0x24c7)];}
if(rl32eGetPCIInfoAtSlot((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(z441f9e6d1b&(0xe05+6374-0x25ec))|((z366b2f03bf&(0x101c+2454-0x18b3))<<(0xa6a+4537-0x1c1b)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zef529fae4a=(void*)zeccbadd9b3.BaseAddress[(0x35c+8306-0x23ce)];ze2370ae9b9=rl32eGetDevicePtr(zef529fae4a,(0x3df+7436-0x1eeb),RT_PG_USERREADWRITE);z3e5b8e05d8=(volatile uint32_T*)ze2370ae9b9;zdfcb1da404=(void*)zeccbadd9b3.BaseAddress[(0x1880+3596-0x268a)];zf2db5722bf=rl32eGetDevicePtr(zdfcb1da404,(0x97b+3948-0x17e7),RT_PG_USERREADWRITE);z27fd94ac66=(volatile uint32_T*)zf2db5722bf;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)z27fd94ac66);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*z27fd94ac66;uint32_T i,input;real_T*y1;boolean_T*y2;uint32_T*z671e76e748;z27fd94ac66=(void*)base;if(((uint8_T)mxGetPr(ze072c43310)[(0x1a8a+1182-0x1f28)])==(0xff8+3246-0x1ca5)){input=z27fd94ac66[(0x185d+2246-0x2121)];}else{input=z27fd94ac66[(0x1485+3074-0x2084)];}switch((uint8_T)mxGetPr(z2cc9a52544)[(0x8d0+3853-0x17dd)]){case(0x66a+5629-0x1c66):for(i=(0x791+2981-0x1336);i<(0x106c+2903-0x1ba3);i++){y1=(real_T*)ssGetOutputPortSignal(S,i);y1[(0xaf+6389-0x19a4)]=(real_T)((input>>i)&(0xa1f+3898-0x1958));}break;case(0x1274+607-0x14d1):for(i=(0x9f4+6062-0x21a2);i<(0x789+5853-0x1e46);i++){y2=(boolean_T*)ssGetOutputPortSignal(S,i);y2[(0x1c6+8657-0x2397)]=(boolean_T)((input>>i)&(0x13ca+1558-0x19df));}break;case(0x507+4514-0x16a6):y1=(real_T*)ssGetOutputPortSignal(S,(0xb16+1480-0x10de));for(i=(0x19a6+2674-0x2418);i<(0x612+1217-0xab3);i++){y1[i]=(real_T)((input>>i)&(0x334+2190-0xbc1));}break;case(0x1506+2869-0x2037):y2=(boolean_T*)ssGetOutputPortSignal(S,(0x83f+2662-0x12a5));for(i=(0xcab+1628-0x1307);i<(0x11c+1338-0x636);i++){y2[i]=(boolean_T)((input>>i)&(0x2425+687-0x26d3));}break;case(0x14a1+1125-0x1901):z671e76e748=(uint32_T*)ssGetOutputPortSignal(S,(0x8f3+4744-0x1b7b));z671e76e748[(0x127+8171-0x2112)]=(uint32_T)input;break;}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

