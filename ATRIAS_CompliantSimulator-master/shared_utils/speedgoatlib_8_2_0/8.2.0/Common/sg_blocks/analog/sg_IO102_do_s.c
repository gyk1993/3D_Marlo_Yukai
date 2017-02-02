/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xc46+3312-0x1934)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO102_do_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x30\x32"
#define z694756a014 (0x142c+8895-0x2636)
#define zea87e0ba83 36992
#define z29146a1837 4277
#define zab7e64468b (0x256a+2903-0xcbf)
#define zdf24515981          ((0x6d1+298-0x7f8))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0xfe3+5152-0x2403))
#define z3832b85a32           ssGetSFcnParam(S,(0x4a3+1924-0xc26))
#define z702a26a5e9                ssGetSFcnParam(S,(0x1e48+1604-0x248a))
#define z2e6483d505              ((0x2185+299-0x22ae))
#define z7e2eeaa57c          ((0x849+5371-0x1d44))
#define z6a0da049de         ((0x609+6995-0x215b))
#define zc5ce4cb81a              ((0x1836+3718-0x26bc))
#define z2b17e2ee3b              ((0x3c0+3691-0x122b))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0x4c7+6790-0x1e4d)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x465+1150-0x8e3));ssSetNumDiscStates(S,(0x934+288-0xa54));ssSetNumOutputPorts(S,(0xa60+6263-0x22d7));ssSetNumInputPorts(S,(int)mxGetN(za9d8fb6bcf));for(i=(0xfa2+599-0x11f9);i<(int)mxGetN(za9d8fb6bcf);i++){ssSetInputPortWidth(S,i,(0x3d4+5851-0x1aae));ssSetInputPortDirectFeedThrough(S,i,(0x10e4+2651-0x1b3e));ssSetInputPortRequiredContiguous(S,i,(0x442+226-0x523));}ssSetNumSampleTimes(S,(0x395+3867-0x12af));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x900+3446-0x1676));ssSetNumNonsampledZCs(S,(0x16f+7421-0x1e6c));for(i=(0xdcb+3604-0x1bdf);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x9b8+6118-0x219e));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0xac2+96-0xb22)]==-1.0){ssSetSampleTime(S,(0xd5+3834-0xfcf),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x18c7+1055-0x1ce6),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x155+3498-0xeff),mxGetPr(z3832b85a32)[(0xebd+4152-0x1ef5)]);ssSetOffsetTime(S,(0x54a+8543-0x26a9),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;uint16_T zf91d71c6d9=(int)mxGetN(za9d8fb6bcf);real_T z19c4ca5f82,start;uint32_T range;if((int_T)mxGetPr(z702a26a5e9)[(0x143b+262-0x1541)]<(0x678+515-0x87b)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x2075+1283-0x2577)){z366b2f03bf=(0x1037+348-0x1193);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1917+3349-0x262c)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x1eb3+1339-0x23ee)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x195+3327-0xe93)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x118+6226-0x186b))|((z366b2f03bf&(0xd67+6714-0x26a2))<<(0x1d49+243-0x1e34)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0xa4+3924-0xff6)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x737+605-0x954),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,z7e2eeaa57c,zf91d71c6d9);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;int_T z0c3eef007f;int_T i;uint_T output,z718c4c15f4,z4e3026977c;real_T*zc7fdaf6331;za42cf7dd4a=(void*)base;z718c4c15f4=(0xad1+5292-0x1f7d);for(i=(0x8bb+3191-0x1532);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uchar_T)mxGetPr(za9d8fb6bcf)[i]-(0x20+8974-0x232d);zc7fdaf6331=(real_T*)ssGetInputPortRealSignal(S,i);if(zc7fdaf6331[(0xbb1+4035-0x1b74)]>=THRESHOLD){z718c4c15f4|=(0x12d2+3244-0x1f7d)<<z4e3026977c;}}za42cf7dd4a[(0x2d6+1451-0x878)]=524288|(z718c4c15f4<<(0x1000+5902-0x2706));
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

