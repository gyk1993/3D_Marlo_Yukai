/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x45f+2447-0xdec)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO103_ad_s
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
#define z694756a014 (0x1896+1412-0xd65)
#define zea87e0ba83 36992
#define z29146a1837 (0x1479+1517-0x9b1)
#define zab7e64468b 10361
#define zdf24515981          ((0x114a+1977-0x18ff))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0x141a+479-0x15f9))
#define z8fd86139be               ssGetSFcnParam(S,(0x7b5+7395-0x2497))
#define z3832b85a32           ssGetSFcnParam(S,(0xea7+2697-0x192e))
#define z702a26a5e9                ssGetSFcnParam(S,(0x89c+655-0xb28))
#define z2e6483d505              ((0x7af+4642-0x19cf))
#define z6a0da049de         ((0x21d2+1100-0x261e))
#define zc2f3e0cbc0        ((0x1141+4058-0x211a))
#define zc5ce4cb81a              ((0x267+3775-0x1124))
#define z8caad2a8e6              ((0xefc+3838-0x1dfa))
#define z5bfe7a2613            ((0xa9a+13-0xaa6))
#define z2b17e2ee3b              ((0x62c+5286-0x1ad2))
static char_T zea4cd01646[(0x140d+1132-0x1779)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x708+6021-0x1e8d));ssSetNumDiscStates(S,(0x6b7+989-0xa94));ssSetNumInputPorts(S,(0x3dc+8536-0x2534));ssSetNumOutputPorts(S,(uint16_T)mxGetN(za9d8fb6bcf));for(i=(0x1cc9+44-0x1cf5);i<(uint16_T)mxGetN(za9d8fb6bcf);i++){ssSetOutputPortWidth(S,i,(0x147a+4042-0x2443));}ssSetNumSampleTimes(S,(0x23c+5562-0x17f5));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x2a9+118-0x31f));ssSetNumNonsampledZCs(S,(0x1ca+1490-0x79c));for(i=(0x3a7+3737-0x1240);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x981+3581-0x177e));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0xd6c+5522-0x22fe)]==-1.0){ssSetSampleTime(S,(0xf16+4679-0x215d),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xeb3+6157-0x26c0),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x251+2542-0xc3f),mxGetPr(z3832b85a32)[(0xcc8+3840-0x1bc8)]);ssSetOffsetTime(S,(0x18db+433-0x1a8c),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T range,out;uint32_T zf91d71c6d9=(uint32_T)mxGetN(za9d8fb6bcf);if((int_T)mxGetPr(z702a26a5e9)[(0xedf+4564-0x20b3)]<(0x80c+946-0xbbe)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x18f7+806-0x1c1c)){z366b2f03bf=(0x634+3913-0x157d);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1da9+603-0x2004)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0xcb+1065-0x4f4)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x15d1+2387-0x1f23)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x1447+2561-0x1d49))|((z366b2f03bf&(0x1c20+2774-0x25f7))<<(0x1582+2994-0x212c)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x15f9+3952-0x2567)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x163a+1308-0x1b16),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,zc2f3e0cbc0,(uint32_T)zf91d71c6d9);switch((uint16_T)mxGetPr(z8fd86139be)[(0x5c+7889-0x1f2d)]){case(0x579+5960-0x1cc0):ssSetRWorkValue(S,z8caad2a8e6,3276.8);ssSetRWorkValue(S,z5bfe7a2613,10.0);range=(0x314+2617-0xd4b);break;case(0x148d+2239-0x1d4a):ssSetRWorkValue(S,z8caad2a8e6,6553.6);ssSetRWorkValue(S,z5bfe7a2613,5.0);range=(0x8c2+1093-0xd06);break;case(0x1d8b+2424-0x2700):ssSetRWorkValue(S,z8caad2a8e6,13107.2);ssSetRWorkValue(S,z5bfe7a2613,2.5);range=(0x14ab+1310-0x19c9);break;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T zf91d71c6d9=ssGetIWorkValue(S,zc2f3e0cbc0);real_T z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6);real_T offset=ssGetRWorkValue(S,z5bfe7a2613);volatile uint32_T*za42cf7dd4a;real_T*y;uint32_T i;uint32_T count;za42cf7dd4a=(void*)base;za42cf7dd4a[(0x198a+1453-0x1f37)]=za42cf7dd4a[(0x1862+3210-0x24ec)]|(0x18c2+1307-0xddd);





for(i=(0x6bc+4338-0x17ae);i<zf91d71c6d9;i++){y=ssGetOutputPortSignal(S,i);while(!(za42cf7dd4a[(0x508+4830-0x17e3)]&65536));count=za42cf7dd4a[(0x85c+5109-0x1c4f)]&65535;y[(0x829+5066-0x1bf3)]=(real_T)count/z0754dd67cc-offset;}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

