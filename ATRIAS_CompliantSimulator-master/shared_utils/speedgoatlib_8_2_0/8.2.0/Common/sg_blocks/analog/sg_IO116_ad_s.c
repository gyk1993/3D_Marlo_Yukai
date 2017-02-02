/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xa23+2127-0x1270)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO116_ad_s
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
#define z694756a014        		(0x178c+3108-0x12fb)
#define zea87e0ba83        		36950
#define z29146a1837     		(0x16a0+1340-0xb27)
#define zab7e64468b     		13648 
#define zdf24515981        ((0x1a00+844-0x1d47))
#define za9d8fb6bcf           ssGetSFcnParam(S,(0x3aa+2528-0xd8a))
#define z39cbd24432       ssGetSFcnParam(S,(0x30b+6249-0x1b73))
#define z702a26a5e9              ssGetSFcnParam(S,(0xcb1+5547-0x225a))
#define zda964b0978					ssGetSFcnParam(S,(0x15dc+207-0x16a8))
#define ze342ab7eba			ssGetSFcnParam(S,(0xdd0+8-0xdd4))
#define z2e6483d505              ((0x11e9+5129-0x25f1))
#define z6a0da049de         ((0x1cd0+1459-0x2283))     
#define zc5ce4cb81a              ((0x8fc+6915-0x23fd))
#define zbf20f918a7      ((0x1f7d+1281-0x247e))
#define z61107aaf54      ((0x456+1947-0xbf0))
#define z2b17e2ee3b              ((0x57f+3978-0x1509))
#define z9ffbe855ce			((0x294+2981-0xe38)<<(0x7f5+6723-0x2225))
#define ze101baf43a				~((0xe88+2805-0x197c)<<(0x8f6+3588-0x16e8))
#define zf95e657598						((0xccc+389-0xe50)<<(0x6fc+6423-0x2007))
#define z452dd4baee				((0x65c+7337-0x2304)<<(0x1520+3042-0x20f2))
#define z595545062b				(65535/(0x106+7104-0x1cc1))
char zea4cd01646[(0x2495+684-0x2641)];
struct zb54cad244e{uint32_T z14bc320aa4;uint32_T z90bb3dec2c;uint32_T z690d720321;uint32_T z8727c368fa;uint32_T z46c3b1e2b8;uint32_T z93f444544d;uint32_T z1c94a69882;uint32_T z720c2d0954;uint32_T z1163d7bf1e;uint32_T zfb3b6a8e3f;uint32_T z3ec1de51f5;uint32_T z7adaa60756;uint32_T zb86e6c0151;uint32_T zc6056578ff;uint32_T z57d8eb858f;uint32_T z9603048a8e;};
static void mdlInitializeSizes(SimStruct*S){char zea4cd01646[(0xbdd+4742-0x1d63)];uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x897+6968-0x23cf));ssSetNumDiscStates(S,(0x1d30+1310-0x224e));ssSetNumSampleTimes(S,(0x100c+3664-0x1e5b));ssSetNumModes(S,(0xf9f+2221-0x184c));ssSetNumNonsampledZCs(S,(0xc1a+6040-0x23b2));for(i=(0x1004+1559-0x161b);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xd59+6140-0x2555));}ssSetNumOutputPorts(S,(uint16_T)mxGetN(za9d8fb6bcf));for(i=(0x1635+643-0x18b8);i<(uint16_T)mxGetN(za9d8fb6bcf);i++){ssSetOutputPortWidth(S,i,(0xe54+1917-0x15d0));}ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if((uint32_T)mxGetPr(z39cbd24432)[(0x1443+1296-0x1953)]==-1.0){ssSetSampleTime(S,(0x2247+83-0x229a),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x32d+5410-0x184f),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x8c4+1169-0xd55),mxGetPr(z39cbd24432)[(0xe3b+3766-0x1cf1)]);ssSetOffsetTime(S,(0x90a+1400-0xe82),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;
volatile struct zb54cad244e*zb54cad244e;
if((int_T)mxGetPr(z702a26a5e9)[(0x7d5+147-0x868)]<(0xc71+986-0x104b)){if(xpcGetPCIDeviceInfo(z694756a014,zea87e0ba83,z29146a1837,zab7e64468b,XPC_NO_BUS_SLOT,XPC_NO_BUS_SLOT,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x1c7d+1268-0x2170)){z366b2f03bf=(0x1455+2872-0x1f8d);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xfdf+3740-0x1e7b)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0xa16+6721-0x2457)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x12b1+4195-0x2313)];}if(xpcGetPCIDeviceInfo(z694756a014,zea87e0ba83,z29146a1837,zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}
zeccbadd9b3.VirtAddress[(0x1cc+6305-0x1a6b)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x2238+380-0x23b2)],zeccbadd9b3.Length[(0x1ac3+1208-0x1f79)],XPC_RT_PG_USERREADWRITE);zb54cad244e=(struct zb54cad244e*)(zeccbadd9b3.VirtAddress[(0xe97+3113-0x1abe)]);
ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x1d28+1399-0x229d)]);
#ifdef z95773b8cb8
xpcShowPCIDeviceInfo(&zeccbadd9b3);
#endif
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
volatile struct zb54cad244e*zb54cad244e=(struct zb54cad244e*)ssGetIWorkValue(S,z6a0da049de);uint32_T i=(0x24d+4881-0x155e),z31f3f2b868=(0x44+8661-0x2219),zf91d71c6d9=(uint32_T)mxGetN(za9d8fb6bcf),z46c3f9a479=(0x20a+1132-0x676),z64002f2ffb=(0xb49+5313-0x200a);real_T z0754dd67cc=(real_T)mxGetPr(zda964b0978)[(0x7e8+3233-0x1489)],*y;zb54cad244e->z14bc320aa4=zb54cad244e->z14bc320aa4|zf95e657598;for(i=(0x17d+2783-0xc5c);i<zf91d71c6d9;i++)
{y=ssGetOutputPortSignal(S,i);while(!(zb54cad244e->z8727c368fa&z452dd4baee));
z31f3f2b868=zb54cad244e->z690d720321&65535;
if((uint32_T)mxGetPr(ze342ab7eba)[i]==(0x7a2+5598-0x1d7f))
{z64002f2ffb=z0754dd67cc;
}else{z64002f2ffb=65535/20e-3;
}y[(0xc0d+5030-0x1fb3)]=(real_T)z31f3f2b868/z64002f2ffb;}
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

