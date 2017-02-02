/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1a3c+2965-0x25cf)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO401_multi_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x34\x30\x31"
#define z694756a014 (0x263c+5148-0x25c0)
#define zea87e0ba83 (0x417+6751-0x1e01)
#define zdf24515981          ((0x4c4+8265-0x2509))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0x7f8+2635-0x1243))
#define z8a52ac7545            ssGetSFcnParam(S,(0x15d4+1751-0x1caa))
#define z3832b85a32           ssGetSFcnParam(S,(0xfbd+407-0x1152))
#define z702a26a5e9                ssGetSFcnParam(S,(0x467+3264-0x1124))
#define z2e6483d505              ((0x24a8+298-0x25d0))
#define z6a0da049de         ((0x1bd5+1888-0x2335))
#define zc2f3e0cbc0        ((0x1550+3627-0x237a))
#define zc5ce4cb81a              ((0x4c4+8216-0x24dc))
#define z2b17e2ee3b              ((0x1a+2775-0xaf1))
static char_T zea4cd01646[(0x45a+6448-0x1c8a)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;uint32_T z4e3026977c,z3125d30160;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x8c3+76-0x90f));ssSetNumDiscStates(S,(0xd1a+6228-0x256e));ssSetNumOutputPorts(S,(uint16_T)mxGetN(za9d8fb6bcf));for(i=(0x1aa7+1715-0x215a);i<(uint16_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[(0xae0+4479-0x1c5f)]-(0x9d6+6488-0x232d);z3125d30160=(uint32_T)mxGetPr(z8a52ac7545)[(0xec5+4035-0x1e88)+z4e3026977c*(0x934+6271-0x21af)];if(z3125d30160==(0x1205+1164-0x1690)){ssSetOutputPortWidth(S,i,(0xec7+3847-0x1dcd));}else{ssSetOutputPortWidth(S,i,(0xd22+1216-0x11e0));}}ssSetNumSampleTimes(S,(0xdb0+403-0xf42));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x189d+1100-0x1ce9));ssSetNumNonsampledZCs(S,(0x676+5158-0x1a9c));for(i=(0xd52+5582-0x2320);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x29+9738-0x2633));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x59d+3406-0x12eb)]==-1.0){ssSetSampleTime(S,(0xd85+972-0x1151),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xb4d+3430-0x18b3),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x11c7+3175-0x1e2e),mxGetPr(z3832b85a32)[(0xed+9073-0x245e)]);ssSetOffsetTime(S,(0xe63+1106-0x12b5),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zdfcb1da404;void*zf2db5722bf;volatile uint32_T*z27fd94ac66;uint_T i;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T range,out;uint32_T zf91d71c6d9=(uint32_T)mxGetN(za9d8fb6bcf);if((int_T)mxGetPr(z702a26a5e9)[(0x885+2370-0x11c7)]<(0x85b+6642-0x224d)){
if(rl32eGetPCIInfo((uint16_T)z694756a014,(uint16_T)zea87e0ba83,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{int_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x21fc+1079-0x2632)){z366b2f03bf=(0x1c75+1181-0x2112);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x3f6+7480-0x212e)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x157f+1166-0x1a0d)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x11d4+5404-0x26ef)];}
if(rl32eGetPCIInfoAtSlot((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(z441f9e6d1b&(0x718+6110-0x1df7))|((z366b2f03bf&(0x7cf+1802-0xdda))<<(0x3b0+3415-0x10ff)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zdfcb1da404=(void*)zeccbadd9b3.BaseAddress[(0x1347+853-0x169a)];zf2db5722bf=rl32eGetDevicePtr(zdfcb1da404,(0x1bea+514-0x1cec),RT_PG_USERREADWRITE);z27fd94ac66=(volatile uint32_T*)zf2db5722bf;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)z27fd94ac66);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;uint32_T z4e3026977c,z7be9105675,i;real_T*y;uint32_T z3125d30160,z59da8ef72c,zbb1608bd48,z095557afa2;za42cf7dd4a=(void*)base;for(i=(0x2260+999-0x2647);i<(uint16_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[(0x1e19+408-0x1fb1)]-(0x76a+6842-0x2223);z3125d30160=(uint32_T)mxGetPr(z8a52ac7545)[(0xf+5602-0x15f1)+z4e3026977c*(0x3f7+766-0x6f1)];z59da8ef72c=(uint32_T)mxGetPr(z8a52ac7545)[(0x301+2221-0xbad)+z4e3026977c*(0x1a3+1929-0x928)];zbb1608bd48=(uint32_T)mxGetPr(z8a52ac7545)[(0xc8+6469-0x1a0b)+z4e3026977c*(0x56d+3742-0x1407)];z095557afa2=(uint32_T)mxGetPr(z8a52ac7545)[(0x1138+3066-0x1d2f)+z4e3026977c*(0x931+978-0xcff)];}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

