/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1f76+1562-0x258e)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO116_di_s
#include 	<stddef.h>
#include 	<stdlib.h>
#include 	"simstruc.h" 
#ifdef 		MATLAB_MEX_FILE
#include 	"mex.h"
#endif
#ifndef     MATLAB_MEX_FILE
#include    <windows.h>
#include    "xpcimports.h"
#endif
#define zf1b619edf2         		"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x31\x36"
#define z694756a014        		(0x1b82+5918-0x21eb)
#define zea87e0ba83        		36950
#define z29146a1837     		(0x1558+3415-0x11fa)
#define zab7e64468b     		13648 
#define zdf24515981			((0x442+3774-0x12fd))
#define za9d8fb6bcf           ssGetSFcnParam(S,(0xa27+1260-0xf13))
#define z39cbd24432       ssGetSFcnParam(S,(0x1003+2600-0x1a2a))
#define z702a26a5e9              ssGetSFcnParam(S,(0x740+7898-0x2618))
#define z2e6483d505              ((0x1091+2161-0x1901))
#define z6a0da049de         ((0xb1f+4682-0x1d69))     
#define zc5ce4cb81a              ((0x13f7+4610-0x25f7))
#define zbf20f918a7      ((0x412+7160-0x200a))
#define z61107aaf54      ((0x395+2132-0xbe8))
#define z2b17e2ee3b              ((0x3b8+1403-0x933))
#define z9ffbe855ce			((0x51b+5600-0x1afa)<<(0x7ba+6634-0x2191))
#define ze101baf43a				~((0x1864+614-0x1ac9)<<(0x297+7776-0x20e5))
char zea4cd01646[(0x868+2687-0x11e7)];
struct zb54cad244e{uint32_T z14bc320aa4;uint32_T z90bb3dec2c;uint32_T z690d720321;uint32_T z8727c368fa;uint32_T z46c3b1e2b8;uint32_T z93f444544d;uint32_T z1c94a69882;uint32_T z720c2d0954;uint32_T z1163d7bf1e;uint32_T zfb3b6a8e3f;uint32_T z3ec1de51f5;uint32_T z7adaa60756;uint32_T zb86e6c0151;uint32_T zc6056578ff;uint32_T z57d8eb858f;uint32_T z9603048a8e;};
static void mdlInitializeSizes(SimStruct*S){char zea4cd01646[(0x219+4465-0x128a)];uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x42c+1539-0xa2f));ssSetNumDiscStates(S,(0x3e7+2083-0xc0a));ssSetNumSampleTimes(S,(0x162+4240-0x11f1));ssSetNumModes(S,(0x13fd+3238-0x20a3));ssSetNumNonsampledZCs(S,(0xfda+1510-0x15c0));for(i=(0x1d3+3358-0xef1);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x136c+1371-0x18c7));}ssSetNumOutputPorts(S,(uint16_T)mxGetN(za9d8fb6bcf));for(i=(0xe45+5897-0x254e);i<(uint16_T)mxGetN(za9d8fb6bcf);i++){ssSetOutputPortWidth(S,i,(0x1019+259-0x111b));}ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if((uint32_T)mxGetPr(z39cbd24432)[(0x1149+4202-0x21b3)]==-1.0){ssSetSampleTime(S,(0x1cf6+152-0x1d8e),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xabb+6220-0x2307),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x1708+2692-0x218c),mxGetPr(z39cbd24432)[(0x8f2+3968-0x1872)]);ssSetOffsetTime(S,(0x387+2012-0xb63),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;
volatile struct zb54cad244e*zb54cad244e;
if((int_T)mxGetPr(z702a26a5e9)[(0x2df+6389-0x1bd4)]<(0x2497+231-0x257e)){if(xpcGetPCIDeviceInfo(z694756a014,zea87e0ba83,z29146a1837,zab7e64468b,XPC_NO_BUS_SLOT,XPC_NO_BUS_SLOT,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x2370+571-0x25aa)){z366b2f03bf=(0x1d0+7555-0x1f53);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xc92+4078-0x1c80)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x102a+296-0x1152)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x11d3+4541-0x238f)];}if(xpcGetPCIDeviceInfo(z694756a014,zea87e0ba83,z29146a1837,zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}
zeccbadd9b3.VirtAddress[(0x10f9+5524-0x268b)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x435+2610-0xe65)],zeccbadd9b3.Length[(0xd36+3957-0x1ca9)],XPC_RT_PG_USERREADWRITE);zb54cad244e=(struct zb54cad244e*)(zeccbadd9b3.VirtAddress[(0xf5+5126-0x14f9)]);
ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x11bd+1032-0x15c3)]);
#ifdef z95773b8cb8
xpcShowPCIDeviceInfo(&zeccbadd9b3);
#endif
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
volatile struct zb54cad244e*zb54cad244e=(struct zb54cad244e*)ssGetIWorkValue(S,z6a0da049de);uint32_T i,z979d8f17a3=(0x749+1812-0xe5d),z577e20787b=(0xc8+6255-0x1937),zb0004dfabf;real_T*y;z979d8f17a3=mxGetN(za9d8fb6bcf);zb0004dfabf=zb54cad244e->zfb3b6a8e3f&(0x1a61+3284-0x2636);for(i=(0x777+2139-0xfd2);i<z979d8f17a3;i++){z577e20787b=(int_T)mxGetPr(za9d8fb6bcf)[i]-(0x8dc+4318-0x19b9);y=ssGetOutputPortSignal(S,i);y[(0x35f+290-0x481)]=(zb0004dfabf>>z577e20787b)&(0x181+1075-0x5b3);}
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

