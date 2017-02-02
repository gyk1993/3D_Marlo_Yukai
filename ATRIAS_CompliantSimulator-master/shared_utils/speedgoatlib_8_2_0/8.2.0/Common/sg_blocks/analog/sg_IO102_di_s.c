/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x217+4839-0x14fc)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO102_di_s
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
#define z694756a014 (0x1418+7760-0x21b3)
#define zea87e0ba83 36992
#define z29146a1837 (0x1648+5673-0x1bbc)
#define zab7e64468b 9218
#define zdf24515981          ((0xa4c+5305-0x1f02))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0xfcc+2071-0x17e3))
#define z3832b85a32           ssGetSFcnParam(S,(0x1398+2610-0x1dc9))
#define z702a26a5e9                ssGetSFcnParam(S,(0x1507+1426-0x1a97))
#define z2e6483d505              ((0x480+4148-0x14b2))
#define z6a0da049de         ((0x1099+1373-0x15f6))
#define zc2f3e0cbc0        ((0x839+4487-0x19bf))
#define zc5ce4cb81a              ((0x1095+722-0x1367))
#define z2b17e2ee3b              ((0x1aa9+958-0x1e67))
static char_T zea4cd01646[(0xd31+1366-0x1187)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x213+3023-0xde2));ssSetNumDiscStates(S,(0x1872+1673-0x1efb));ssSetNumInputPorts(S,(0x6b4+6403-0x1fb7));ssSetNumOutputPorts(S,(uint16_T)mxGetN(za9d8fb6bcf));for(i=(0x2274+465-0x2445);i<(uint16_T)mxGetN(za9d8fb6bcf);i++){ssSetOutputPortWidth(S,i,(0x175+6150-0x197a));}ssSetNumSampleTimes(S,(0xeb3+1576-0x14da));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1339+3028-0x1f0d));ssSetNumNonsampledZCs(S,(0x1b2d+865-0x1e8e));for(i=(0x4a+8171-0x2035);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xd33+2172-0x15af));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x1d+6537-0x19a6)]==-1.0){ssSetSampleTime(S,(0x721+1617-0xd72),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1510+1806-0x1c1e),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xca4+3225-0x193d),mxGetPr(z3832b85a32)[(0x6f5+922-0xa8f)]);ssSetOffsetTime(S,(0x19a0+1277-0x1e9d),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T range,out;uint32_T zf91d71c6d9=(uint32_T)mxGetN(za9d8fb6bcf);if((int_T)mxGetPr(z702a26a5e9)[(0x1181+2708-0x1c15)]<(0x3cc+5901-0x1ad9)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x1d77+77-0x1dc3)){z366b2f03bf=(0x2c8+2384-0xc18);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x5ef+7771-0x244a)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0xc46+6075-0x2401)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x456+3683-0x12b8)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x2324+1203-0x26d8))|((z366b2f03bf&(0x181b+1585-0x1d4d))<<(0x1e32+938-0x21d4)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x1ac7+3008-0x2685)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x19a6+1617-0x1fb7),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,zc2f3e0cbc0,(uint32_T)zf91d71c6d9);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;int_T z0c3eef007f;uint32_T i,input,z4e3026977c;real_T*y;za42cf7dd4a=(void*)base;z0c3eef007f=mxGetN(za9d8fb6bcf);input=za42cf7dd4a[(0x243d+478-0x2612)]&(0xbf8+2937-0x1672);for(i=(0xa9f+6639-0x248e);i<z0c3eef007f;i++){z4e3026977c=(int_T)mxGetPr(za9d8fb6bcf)[i]-(0x96a+7529-0x26d2);y=ssGetOutputPortSignal(S,i);y[(0x22c3+619-0x252e)]=(input>>z4e3026977c)&(0x32a+2567-0xd30);}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

