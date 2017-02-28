/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1c75+2392-0x25cb)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO104_di_s
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
#define z694756a014 4277
#define zea87e0ba83 36950
#define z29146a1837 (0x19f0+2672-0x13ab)
#define zab7e64468b 12658
#define zdf24515981          ((0x73a+4799-0x19f6))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0x1828+1813-0x1f3d))
#define z3832b85a32           ssGetSFcnParam(S,(0x1e2c+1423-0x23ba))
#define z702a26a5e9                ssGetSFcnParam(S,(0x707+1691-0xda0))
#define z2e6483d505              ((0x11c7+4774-0x246b))
#define z6a0da049de         ((0x13b9+1987-0x1b7c))
#define zc2f3e0cbc0        ((0x30c+8853-0x25a0))
#define zc5ce4cb81a              ((0xf3b+2838-0x1a51))
#define z2b17e2ee3b              ((0x7a1+6239-0x2000))
static char_T zea4cd01646[(0xc3f+6690-0x2561)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x989+2407-0x12f0));ssSetNumDiscStates(S,(0xf9+405-0x28e));ssSetNumInputPorts(S,(0x1022+3030-0x1bf8));ssSetNumOutputPorts(S,(uint16_T)mxGetN(za9d8fb6bcf));for(i=(0x2c4+1004-0x6b0);i<(uint16_T)mxGetN(za9d8fb6bcf);i++){ssSetOutputPortWidth(S,i,(0x22a+1341-0x766));}ssSetNumSampleTimes(S,(0x989+1654-0xffe));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xd02+3213-0x198f));ssSetNumNonsampledZCs(S,(0xcb0+3855-0x1bbf));for(i=(0x1aaa+2799-0x2599);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x12ea+337-0x143b));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x1619+646-0x189f)]==-1.0){ssSetSampleTime(S,(0x1b1b+68-0x1b5f),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xdca+1063-0x11f1),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xf49+4472-0x20c1),mxGetPr(z3832b85a32)[(0xaf1+2861-0x161e)]);ssSetOffsetTime(S,(0x134f+4998-0x26d5),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T range,out;uint32_T zf91d71c6d9=(uint32_T)mxGetN(za9d8fb6bcf);if((int_T)mxGetPr(z702a26a5e9)[(0x837+2-0x839)]<(0xea7+1805-0x15b4)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xae2+7090-0x2693)){z366b2f03bf=(0x13a4+1203-0x1857);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1607+3618-0x2429)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x5cd+5883-0x1cc8)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x196+8873-0x243e)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x13df+3175-0x1f47))|((z366b2f03bf&(0x1278+1527-0x1770))<<(0x1b25+722-0x1def)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0xb1f+6684-0x2539)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x16b3+2445-0x1fc0),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,zc2f3e0cbc0,(uint32_T)zf91d71c6d9);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;int_T z0c3eef007f;uint32_T i,input,z4e3026977c;real_T*y;za42cf7dd4a=(void*)base;z0c3eef007f=mxGetN(za9d8fb6bcf);input=za42cf7dd4a[(0x201+4907-0x152b)]&(0x86d+3766-0x1624);for(i=(0x1523+3826-0x2415);i<z0c3eef007f;i++){z4e3026977c=(int_T)mxGetPr(za9d8fb6bcf)[i]-(0x1838+604-0x1a93);y=ssGetOutputPortSignal(S,i);y[(0x2d4+1626-0x92e)]=(input>>z4e3026977c)&(0x264+3860-0x1177);}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

