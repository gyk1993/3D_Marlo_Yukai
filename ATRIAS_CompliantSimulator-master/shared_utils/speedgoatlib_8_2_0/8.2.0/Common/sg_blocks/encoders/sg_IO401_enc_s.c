/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xaf3+4253-0x1b8e)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO401_enc_s
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
#define z694756a014 (0x2201+3059-0x195c)
#define zea87e0ba83 (0xd83+2947-0x1891)
#define zdf24515981          ((0x164+4360-0x1269))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0x2ff+3509-0x10b4))
#define z3832b85a32           ssGetSFcnParam(S,(0xcaf+3257-0x1967))
#define z702a26a5e9                ssGetSFcnParam(S,(0x2cf+1949-0xa6a))
#define z2e6483d505              ((0x1247+2204-0x1ae1))
#define z6a0da049de         ((0x11e7+1114-0x1641))
#define zc2f3e0cbc0        ((0x622+4652-0x184d))
#define zc5ce4cb81a              ((0xbf+631-0x336))
#define z2b17e2ee3b              ((0x417+124-0x493))
static char_T zea4cd01646[(0x1d98+1651-0x230b)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xc99+5817-0x2352));ssSetNumDiscStates(S,(0x13e2+1758-0x1ac0));ssSetNumInputPorts(S,(0xb80+5126-0x1f86));ssSetNumOutputPorts(S,(0x2bc+394-0x445));ssSetOutputPortWidth(S,(0x2bf+6949-0x1de4),(0x478+937-0x820));ssSetNumSampleTimes(S,(0x529+3080-0x1130));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x17da+2453-0x216f));ssSetNumNonsampledZCs(S,(0xd06+2070-0x151c));for(i=(0x1735+2609-0x2166);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x15b8+1071-0x19e7));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x8d9+6109-0x20b6)]==-1.0){ssSetSampleTime(S,(0x10b4+3103-0x1cd3),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x4df+7864-0x2397),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x103+5666-0x1725),mxGetPr(z3832b85a32)[(0x1061+1963-0x180c)]);ssSetOffsetTime(S,(0x2dd+1171-0x770),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zdfcb1da404;void*zf2db5722bf;volatile uint32_T*z27fd94ac66;uint_T i;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T range,out;uint32_T zf91d71c6d9=(uint32_T)mxGetN(za9d8fb6bcf);if((int_T)mxGetPr(z702a26a5e9)[(0x2219+1048-0x2631)]<(0x1ddc+1309-0x22f9)){
if(rl32eGetPCIInfo((uint16_T)z694756a014,(uint16_T)zea87e0ba83,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{int_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x1a1c+2953-0x25a4)){z366b2f03bf=(0x7a6+181-0x85b);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xd35+3531-0x1b00)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x322+5776-0x19b2)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x5c4+3942-0x1529)];}
if(rl32eGetPCIInfoAtSlot((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(z441f9e6d1b&(0xbab+4548-0x1c70))|((z366b2f03bf&(0x525+6332-0x1ce2))<<(0x1428+2009-0x1bf9)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zdfcb1da404=(void*)zeccbadd9b3.BaseAddress[(0x11bc+102-0x1220)];zf2db5722bf=rl32eGetDevicePtr(zdfcb1da404,(0x1170+5338-0x254a),RT_PG_USERREADWRITE);z27fd94ac66=(volatile uint32_T*)zf2db5722bf;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)z27fd94ac66);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;uint32_T z4e3026977c;real_T*y;za42cf7dd4a=(void*)base;y=ssGetOutputPortSignal(S,(0x7f0+6235-0x204b));z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[(0x2b+9416-0x24f3)]-(0x234+2861-0xd60);y[(0xc+172-0xb8)]=(real_T)za42cf7dd4a[(0x247+5207-0x169d)+z4e3026977c*(0x1935+1453-0x1edc)];
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

