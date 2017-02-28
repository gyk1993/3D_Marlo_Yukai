/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x189f+1194-0x1d47)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO116_do_s
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
#define z694756a014        		(0x17e2+2055-0xf34)
#define zea87e0ba83        		36950
#define z29146a1837     		4277
#define zab7e64468b     		13648 
#define zdf24515981         ((0xf32+4009-0x1ed8))
#define za9d8fb6bcf            ssGetSFcnParam(S,(0x2503+13-0x2510))
#define z39cbd24432        ssGetSFcnParam(S,(0x6d8+3410-0x1429))
#define z702a26a5e9               ssGetSFcnParam(S,(0xfe7+3959-0x1f5c))

#define z2e6483d505              ((0x144a+4354-0x254b))
#define z6a0da049de         ((0x77a+5789-0x1e17))     
#define zc5ce4cb81a              ((0x3af+8208-0x23bd))
#define zbf20f918a7      ((0x183+4072-0x116b))
#define z61107aaf54      ((0xfd2+4622-0x21df))
#define z2b17e2ee3b              ((0x1b0f+223-0x1bee))
#define z9ffbe855ce			((0x1c40+545-0x1e60)<<(0x389+8763-0x25b1))
#define ze101baf43a				~((0xc8c+6264-0x2503)<<(0x1acf+2437-0x2442))
char zea4cd01646[(0x5d3+370-0x645)];
struct zb54cad244e{uint32_T z14bc320aa4;uint32_T z90bb3dec2c;uint32_T z690d720321;uint32_T z8727c368fa;uint32_T z46c3b1e2b8;uint32_T z93f444544d;uint32_T z1c94a69882;uint32_T z720c2d0954;uint32_T z1163d7bf1e;uint32_T zfb3b6a8e3f;uint32_T z3ec1de51f5;uint32_T z7adaa60756;uint32_T zb86e6c0151;uint32_T zc6056578ff;uint32_T z57d8eb858f;uint32_T z9603048a8e;};
static void mdlInitializeSizes(SimStruct*S){char zea4cd01646[(0xa6a+242-0xa5c)];uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x532+2986-0x10dc));ssSetNumDiscStates(S,(0x1cb4+781-0x1fc1));ssSetNumSampleTimes(S,(0xbef+2723-0x1691));ssSetNumModes(S,(0x17c4+3658-0x260e));ssSetNumNonsampledZCs(S,(0xdad+577-0xfee));for(i=(0xe3b+1863-0x1582);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1a9c+3085-0x26a9));}ssSetNumInputPorts(S,(int)mxGetN(za9d8fb6bcf));for(i=(0x2bd+4741-0x1542);i<(int)mxGetN(za9d8fb6bcf);i++){ssSetInputPortWidth(S,i,(0x93d+3713-0x17bd));ssSetInputPortDirectFeedThrough(S,i,(0x112d+1229-0x15f9));ssSetInputPortRequiredContiguous(S,i,(0xa67+5720-0x20be));}ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if((uint32_T)mxGetPr(z39cbd24432)[(0x775+5630-0x1d73)]==-1.0){ssSetSampleTime(S,(0x890+5902-0x1f9e),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x92c+1740-0xff8),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x1891+2920-0x23f9),mxGetPr(z39cbd24432)[(0x8f9+1482-0xec3)]);ssSetOffsetTime(S,(0x70+1974-0x826),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;
volatile struct zb54cad244e*zb54cad244e;
if((int_T)mxGetPr(z702a26a5e9)[(0x190f+2160-0x217f)]<(0x1607+1794-0x1d09)){if(xpcGetPCIDeviceInfo(z694756a014,zea87e0ba83,z29146a1837,zab7e64468b,XPC_NO_BUS_SLOT,XPC_NO_BUS_SLOT,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x15c9+4206-0x2636)){z366b2f03bf=(0x28c+7970-0x21ae);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1416+1123-0x1879)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x1413+3553-0x21f4)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x6f4+1684-0xd87)];}if(xpcGetPCIDeviceInfo(z694756a014,zea87e0ba83,z29146a1837,zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}
zeccbadd9b3.VirtAddress[(0xfc9+1031-0x13ce)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x23a0+644-0x2622)],zeccbadd9b3.Length[(0x12a7+600-0x14fd)],XPC_RT_PG_USERREADWRITE);zb54cad244e=(struct zb54cad244e*)(zeccbadd9b3.VirtAddress[(0xe77+1986-0x1637)]);
ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x1e91+134-0x1f15)]);
#ifdef z95773b8cb8
xpcShowPCIDeviceInfo(&zeccbadd9b3);
#endif
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
volatile struct zb54cad244e*zb54cad244e=(struct zb54cad244e*)ssGetIWorkValue(S,z6a0da049de);uint32_T i,z6ebde3830d=(0x12e3+4278-0x2399),z4e3026977c;real_T*z8b5ae3b99c;z6ebde3830d=(0x905+4802-0x1bc7);for(i=(0x11f8+2595-0x1c1b);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uchar_T)mxGetPr(za9d8fb6bcf)[i]-(0x1253+1950-0x19f0);z8b5ae3b99c=(real_T*)ssGetInputPortRealSignal(S,i);if(z8b5ae3b99c[(0x861+5551-0x1e10)]==(0xdc+3893-0x1010)){z6ebde3830d=z6ebde3830d|((0x6df+5379-0x1be1)<<z4e3026977c);}}zb54cad244e->zfb3b6a8e3f=(z9ffbe855ce|(z6ebde3830d<<(0x4ec+2250-0xdae)));
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

