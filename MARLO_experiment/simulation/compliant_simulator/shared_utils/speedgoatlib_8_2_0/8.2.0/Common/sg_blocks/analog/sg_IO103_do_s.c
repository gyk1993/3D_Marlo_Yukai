/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x3bc+5151-0x17d9)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO103_do_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x30\x33"
#define z694756a014 (0x2556+3836-0x239d)
#define zea87e0ba83 36992
#define z29146a1837 (0x22d9+1123-0x1687)
#define zab7e64468b 10361
#define zdf24515981          ((0x6a7+419-0x847))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0x1563+84-0x15b7))
#define z3832b85a32           ssGetSFcnParam(S,(0x1eac+1488-0x247b))
#define z702a26a5e9                ssGetSFcnParam(S,(0x9d2+4297-0x1a99))
#define z2e6483d505              ((0x10cf+3233-0x1d6e))
#define z7e2eeaa57c          ((0x48f+6699-0x1eba))
#define z6a0da049de         ((0x1c22+2033-0x2412))
#define zc5ce4cb81a              ((0xbc5+4044-0x1b91))
#define z2b17e2ee3b              ((0x63+2204-0x8ff))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0x457+4531-0x150a)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x19fb+2546-0x23ed));ssSetNumDiscStates(S,(0x189c+3001-0x2455));ssSetNumOutputPorts(S,(0x1598+1425-0x1b29));ssSetNumInputPorts(S,(int)mxGetN(za9d8fb6bcf));for(i=(0x3f4+847-0x743);i<(int)mxGetN(za9d8fb6bcf);i++){ssSetInputPortWidth(S,i,(0x49d+8649-0x2665));ssSetInputPortDirectFeedThrough(S,i,(0x986+6328-0x223d));ssSetInputPortRequiredContiguous(S,i,(0xb32+6817-0x25d2));}ssSetNumSampleTimes(S,(0x6e3+1532-0xcde));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xb09+1464-0x10c1));ssSetNumNonsampledZCs(S,(0x3a5+1838-0xad3));for(i=(0xd89+3315-0x1a7c);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xa30+581-0xc75));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x120+8538-0x227a)]==-1.0){ssSetSampleTime(S,(0xfe0+1246-0x14be),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xb14+1829-0x1239),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x6b8+8213-0x26cd),mxGetPr(z3832b85a32)[(0x218+7946-0x2122)]);ssSetOffsetTime(S,(0xf58+5158-0x237e),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;uint16_T zf91d71c6d9=(int)mxGetN(za9d8fb6bcf);real_T z19c4ca5f82,start;uint32_T range;if((int_T)mxGetPr(z702a26a5e9)[(0x751+4201-0x17ba)]<(0xb00+3911-0x1a47)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x680+3739-0x151a)){z366b2f03bf=(0x964+3680-0x17c4);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x842+7618-0x2604)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0xd35+4279-0x1dec)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1d3+9464-0x26ca)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0xc98+840-0xee1))|((z366b2f03bf&(0x420+6907-0x1e1c))<<(0x6dd+677-0x97a)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0xd93+2278-0x1677)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x2a1+314-0x39b),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,z7e2eeaa57c,zf91d71c6d9);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;int_T z0c3eef007f;int_T i;uint_T output,z718c4c15f4,z4e3026977c;real_T*zc7fdaf6331;za42cf7dd4a=(void*)base;z718c4c15f4=(0x1d02+1370-0x225c);for(i=(0x23b+1579-0x866);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uchar_T)mxGetPr(za9d8fb6bcf)[i]-(0x15d4+928-0x1973);zc7fdaf6331=(real_T*)ssGetInputPortRealSignal(S,i);if(zc7fdaf6331[(0xa7f+4289-0x1b40)]>=THRESHOLD){z718c4c15f4|=(0x1868+508-0x1a63)<<z4e3026977c;}}za42cf7dd4a[(0xc5f+2810-0x1750)]=z718c4c15f4;
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

