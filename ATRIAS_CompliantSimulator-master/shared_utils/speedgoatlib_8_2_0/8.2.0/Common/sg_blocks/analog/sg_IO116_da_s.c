/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xc4b+1086-0x1087)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO116_da_s
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
#define z694756a014        		(0x1257+2179-0xa25)
#define zea87e0ba83        		36950
#define z29146a1837     		4277
#define zab7e64468b     		13648 
#define zdf24515981			((0x18b+4214-0x11fb))
#define za9d8fb6bcf				ssGetSFcnParam(S,(0x14ea+4625-0x26fb))
#define z39cbd24432			ssGetSFcnParam(S,(0x1590+3745-0x2430))
#define z702a26a5e9					ssGetSFcnParam(S,(0x16b9+2846-0x21d5))
#define zda964b0978					ssGetSFcnParam(S,(0xaa1+4897-0x1dbf))
#define z8e2c007185		ssGetSFcnParam(S,(0x9b3+822-0xce5))
#define z323aba6146	ssGetSFcnParam(S,(0x1ab0+2066-0x22bd))
#define z2e6483d505              ((0xdcf+5903-0x24dd))
#define z6a0da049de         ((0x1d+6933-0x1b32))     
#define zc5ce4cb81a              ((0x50+1399-0x5c5))
#define zbf20f918a7      ((0x1b63+838-0x1ea9))
#define z61107aaf54      ((0x1faa+645-0x222e))
#define z2b17e2ee3b              ((0x849+6292-0x20dd))
#define z9ffbe855ce			((0x152a+4310-0x25ff)<<(0x9da+4332-0x1ab3))
#define ze101baf43a				~((0x1af9+1305-0x2011)<<(0x170f+666-0x1997))
char zea4cd01646[(0x786+455-0x84d)];
struct zb54cad244e{uint32_T z14bc320aa4;uint32_T z90bb3dec2c;uint32_T z690d720321;uint32_T z8727c368fa;uint32_T z46c3b1e2b8;uint32_T z93f444544d;uint32_T z1c94a69882;uint32_T z720c2d0954;uint32_T z1163d7bf1e;uint32_T zfb3b6a8e3f;uint32_T z3ec1de51f5;uint32_T z7adaa60756;uint32_T zb86e6c0151;uint32_T zc6056578ff;uint32_T z57d8eb858f;uint32_T z9603048a8e;};
static void mdlInitializeSizes(SimStruct*S){char zea4cd01646[(0x13cb+2366-0x1c09)];uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x11ac+1557-0x17c1));ssSetNumDiscStates(S,(0xd1a+5893-0x241f));ssSetNumSampleTimes(S,(0x1715+3615-0x2533));ssSetNumModes(S,(0x872+4671-0x1ab1));ssSetNumNonsampledZCs(S,(0x3a8+721-0x679));for(i=(0xccc+195-0xd8f);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xdc3+5542-0x2369));}ssSetNumInputPorts(S,(int)mxGetN(za9d8fb6bcf));for(i=(0x408+1435-0x9a3);i<(int)mxGetN(za9d8fb6bcf);i++){ssSetInputPortWidth(S,i,(0x1283+4565-0x2457));ssSetInputPortDirectFeedThrough(S,i,(0x1903+1087-0x1d41));ssSetInputPortRequiredContiguous(S,i,(0xac+6152-0x18b3));}if((uint32_T)mxGetPr(z323aba6146)[(0xde6+2031-0x15d5)]==(0x34d+7534-0x20ba)&&(uint32_T)mxGetPr(z8e2c007185)[(0x1050+4689-0x22a1)]==(0x12a9+3054-0x1e96))
{
ssSetNumOutputPorts(S,(0x2dc+5032-0x1680));for(i=(0x115d+3302-0x1e43);i<(0x1a59+1816-0x216d);i++){ssSetOutputPortWidth(S,i,(0x5e7+5819-0x1ca1));}}else
{ssSetNumOutputPorts(S,(0x476+2861-0xfa3));}ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if((uint32_T)mxGetPr(z39cbd24432)[(0x141+826-0x47b)]==-1.0){ssSetSampleTime(S,(0x361+4644-0x1585),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xfbd+557-0x11ea),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x1107+667-0x13a2),mxGetPr(z39cbd24432)[(0x19eb+3200-0x266b)]);ssSetOffsetTime(S,(0xa17+2398-0x1375),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;
volatile struct zb54cad244e*zb54cad244e;
if((int_T)mxGetPr(z702a26a5e9)[(0x1e76+728-0x214e)]<(0x329+6678-0x1d3f)){if(xpcGetPCIDeviceInfo(z694756a014,zea87e0ba83,z29146a1837,zab7e64468b,XPC_NO_BUS_SLOT,XPC_NO_BUS_SLOT,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x1a96+893-0x1e12)){z366b2f03bf=(0xabf+3829-0x19b4);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x6e5+4814-0x19b3)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x1a49+338-0x1b9b)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1379+584-0x15c0)];}if(xpcGetPCIDeviceInfo(z694756a014,zea87e0ba83,z29146a1837,zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}
zeccbadd9b3.VirtAddress[(0x7e7+4517-0x198a)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x61c+5134-0x1a28)],zeccbadd9b3.Length[(0xd1a+5163-0x2143)],XPC_RT_PG_USERREADWRITE);zb54cad244e=(struct zb54cad244e*)(zeccbadd9b3.VirtAddress[(0x480+4560-0x164e)]);
ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x585+1511-0xb6a)]);
#ifdef z95773b8cb8
xpcShowPCIDeviceInfo(&zeccbadd9b3);
#endif
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
volatile struct zb54cad244e*zb54cad244e=(struct zb54cad244e*)ssGetIWorkValue(S,z6a0da049de);uint32_T i,z6ebde3830d=(0x14a4+3091-0x20b7),zcb322daed6,zf91d71c6d9=(uint32_T)mxGetN(za9d8fb6bcf),alarm;real_T z0754dd67cc=(0x6f6+6308-0x1f9a);real_T*z6811465ec0,*zc7fc760ccc;int32_T z2ee0b44103=(0x375+7540-0x20e9);z0754dd67cc=(real_T)mxGetPr(zda964b0978)[(0xe38+6129-0x2629)];for(i=(0xf4d+1707-0x15f8);i<zf91d71c6d9;i++){zcb322daed6=(uint16_T)mxGetPr(za9d8fb6bcf)[i]-(0xcdb+2421-0x164f);z6811465ec0=(real_T*)ssGetInputPortRealSignal(S,i);z2ee0b44103=(int32_T)((z6811465ec0[(0x16d0+1495-0x1ca7)])*z0754dd67cc);if(z2ee0b44103>65535){z2ee0b44103=65535;}if(z2ee0b44103<(0xf20+4181-0x1f75)){z2ee0b44103=(0x14d9+4173-0x2526);}if(i>=(zf91d71c6d9-(0x13bb+3504-0x216a)))
{zb54cad244e->z1c94a69882=z2ee0b44103|(zcb322daed6<<(0x1d03+1506-0x22d5))|((0x430+150-0x4c5)<<(0x11ed+5339-0x26b6))|((0x1156+1949-0x18f2)<<(0x1f45+852-0x2286));zb54cad244e->z14bc320aa4=zb54cad244e->z14bc320aa4|((0x7c8+971-0xb92)<<(0x575+5340-0x1a46));}else
{zb54cad244e->z1c94a69882=z2ee0b44103|(zcb322daed6<<(0xcdf+4642-0x1ef1));}}if((uint32_T)mxGetPr(z323aba6146)[(0x11fb+4501-0x2390)]==(0xe5d+5586-0x242e)&&(uint32_T)mxGetPr(z8e2c007185)[(0x143b+1804-0x1b47)]==(0x210+5475-0x1772))
{
alarm=zb54cad244e->z720c2d0954;for(i=(0xa12+871-0xd79);i<(0xa65+404-0xbf5);i++){zc7fc760ccc=ssGetOutputPortSignal(S,i);zc7fc760ccc[(0x112b+3843-0x202e)]=(real_T)((alarm&((0x1013+76-0x105e)<<((0x19ef+2500-0x23a2)+i)))>>((0x3bb+8437-0x249f)+i));}}
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

