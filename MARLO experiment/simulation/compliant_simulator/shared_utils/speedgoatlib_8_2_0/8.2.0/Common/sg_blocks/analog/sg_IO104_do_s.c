/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xec4+89-0xf1b)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO104_do_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x30\x34"
#define z694756a014 (0x16e5+1742-0xcfe)
#define zea87e0ba83 36950
#define z29146a1837 (0x1dc4+5566-0x22cd)
#define zab7e64468b 12658
#define zdf24515981          ((0xde0+1299-0x12f0))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0x139a+1053-0x17b7))
#define z3832b85a32           ssGetSFcnParam(S,(0x4b6+720-0x785))
#define z702a26a5e9                ssGetSFcnParam(S,(0x1838+1455-0x1de5))
#define z2e6483d505              ((0x1050+2210-0x18f0))
#define z7e2eeaa57c          ((0x1808+1355-0x1d53))
#define z6a0da049de         ((0x1ae8+251-0x1be2))
#define zc5ce4cb81a              ((0x24+8886-0x22da))
#define z2b17e2ee3b              ((0x1619+3276-0x22e5))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0x1422+4999-0x26a9)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x2164+332-0x22b0));ssSetNumDiscStates(S,(0x5bc+2519-0xf93));ssSetNumOutputPorts(S,(0x4f2+8007-0x2439));ssSetNumInputPorts(S,(int)mxGetN(za9d8fb6bcf));for(i=(0x979+97-0x9da);i<(int)mxGetN(za9d8fb6bcf);i++){ssSetInputPortWidth(S,i,(0x20db+261-0x21df));ssSetInputPortDirectFeedThrough(S,i,(0x23c3+578-0x2604));ssSetInputPortRequiredContiguous(S,i,(0xe43+1481-0x140b));}ssSetNumSampleTimes(S,(0x3fa+669-0x696));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x6e5+7307-0x2370));ssSetNumNonsampledZCs(S,(0x94a+5726-0x1fa8));for(i=(0x1431+2578-0x1e43);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x808+958-0xbc6));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x1856+304-0x1986)]==-1.0){ssSetSampleTime(S,(0x326+3914-0x1270),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x700+816-0xa30),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x13e5+4246-0x247b),mxGetPr(z3832b85a32)[(0x11a0+3126-0x1dd6)]);ssSetOffsetTime(S,(0x12f1+1390-0x185f),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;uint16_T zf91d71c6d9=(int)mxGetN(za9d8fb6bcf);real_T z19c4ca5f82,start;uint32_T range;if((int_T)mxGetPr(z702a26a5e9)[(0x728+7804-0x25a4)]<(0x1e79+263-0x1f80)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x102+6992-0x1c51)){z366b2f03bf=(0xbcb+5081-0x1fa4);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xa35+176-0xae5)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0xd38+2027-0x1523)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x16ca+2152-0x1f31)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x996+2825-0x13a0))|((z366b2f03bf&(0xba5+5639-0x20ad))<<(0xc28+5267-0x20b3)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x119+2812-0xc13)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x21f+3293-0xe7c),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,z7e2eeaa57c,zf91d71c6d9);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;int_T z0c3eef007f;int_T i;uint_T output,z718c4c15f4,z4e3026977c;real_T*zc7fdaf6331;za42cf7dd4a=(void*)base;z718c4c15f4=(0x193+2579-0xba6);for(i=(0x1e2+4305-0x12b3);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uchar_T)mxGetPr(za9d8fb6bcf)[i]-(0x19a3+67-0x19e5);zc7fdaf6331=(real_T*)ssGetInputPortRealSignal(S,i);if(zc7fdaf6331[(0xa9+6673-0x1aba)]>=THRESHOLD){z718c4c15f4|=(0x1df5+1956-0x2598)<<z4e3026977c;}}za42cf7dd4a[(0x1272+3821-0x215e)]=16777216|(z718c4c15f4<<(0x882+2834-0x1384));
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

