/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xca2+6667-0x26ab)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO401_ssi_s
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
#define z694756a014 (0x16f8+7322-0x1efa)
#define zea87e0ba83 (0x1984+1476-0x1ed3)
#define zdf24515981          ((0x1f6b+1284-0x246b))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0x174+8379-0x222f))
#define z8a52ac7545            ssGetSFcnParam(S,(0x626+5886-0x1d23))
#define z3832b85a32           ssGetSFcnParam(S,(0xcf8+907-0x1081))
#define z702a26a5e9                ssGetSFcnParam(S,(0xf67+4887-0x227b))
#define z2e6483d505              ((0xbe5+2801-0x16d4))
#define z6a0da049de         ((0x24bf+435-0x2672))
#define zc2f3e0cbc0        ((0x1286+795-0x15a0))
#define zc5ce4cb81a              ((0x1a0+700-0x45c))
#define z2b17e2ee3b              ((0x11c+9303-0x2573))
static char_T zea4cd01646[(0x215+8643-0x22d8)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;uint32_T z4e3026977c,z3125d30160;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x6d2+5795-0x1d75));ssSetNumDiscStates(S,(0x948+381-0xac5));ssSetNumInputPorts(S,(0x257f+373-0x26f4));z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[(0x47c+2003-0xc4f)]-(0x1a6c+1581-0x2098);z3125d30160=(uint32_T)mxGetPr(z8a52ac7545)[(0x1688+2324-0x1f9c)+z4e3026977c*(0x6c9+6359-0x1f9c)];ssSetNumOutputPorts(S,(0x12d8+4421-0x241c));if(z3125d30160==(0x3eb+8077-0x2377)){ssSetOutputPortWidth(S,(0x11d1+123-0x124c),(0x9a0+3686-0x1805));}else{ssSetOutputPortWidth(S,(0xe35+1006-0x1223),(0x13e1+3723-0x226a));}ssSetNumSampleTimes(S,(0x446+1789-0xb42));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xa1+9023-0x23e0));ssSetNumNonsampledZCs(S,(0x9d9+5600-0x1fb9));for(i=(0xbb4+652-0xe40);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x480+7013-0x1fe5));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x1ea1+1994-0x266b)]==-1.0){ssSetSampleTime(S,(0xe2c+2710-0x18c2),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x781+5515-0x1d0c),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xc49+3759-0x1af8),mxGetPr(z3832b85a32)[(0x18d0+3080-0x24d8)]);ssSetOffsetTime(S,(0x64d+5617-0x1c3e),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zdfcb1da404;void*zf2db5722bf;volatile uint32_T*z27fd94ac66;uint_T i;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T range,out;uint32_T zf91d71c6d9=(uint32_T)mxGetN(za9d8fb6bcf);if((int_T)mxGetPr(z702a26a5e9)[(0x977+7215-0x25a6)]<(0x4a8+4484-0x162c)){
if(rl32eGetPCIInfo((uint16_T)z694756a014,(uint16_T)zea87e0ba83,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{int_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x27f+2903-0xdd5)){z366b2f03bf=(0x18c+9018-0x24c6);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x54d+6607-0x1f1c)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x52d+3669-0x1382)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x5a8+8094-0x2545)];}
if(rl32eGetPCIInfoAtSlot((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(z441f9e6d1b&(0xac4+4026-0x197f))|((z366b2f03bf&(0x14f4+3067-0x1ff0))<<(0x171+8048-0x20d9)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zdfcb1da404=(void*)zeccbadd9b3.BaseAddress[(0x7c3+3478-0x1557)];zf2db5722bf=rl32eGetDevicePtr(zdfcb1da404,(0x1a0a+1415-0x1e91),RT_PG_USERREADWRITE);z27fd94ac66=(volatile uint32_T*)zf2db5722bf;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)z27fd94ac66);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;uint32_T z4e3026977c,z7be9105675;real_T*y;uint32_T z3125d30160,z59da8ef72c,zbb1608bd48,z095557afa2;za42cf7dd4a=(void*)base;z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[(0xc4+179-0x177)]-(0x1105+772-0x1408);z3125d30160=(uint32_T)mxGetPr(z8a52ac7545)[(0xb57+2828-0x1663)+z4e3026977c*(0x14eb+1294-0x19f5)];z59da8ef72c=(uint32_T)mxGetPr(z8a52ac7545)[(0xf3b+5051-0x22f5)+z4e3026977c*(0x5b5+6276-0x1e35)];zbb1608bd48=(uint32_T)mxGetPr(z8a52ac7545)[(0x149d+4117-0x24b0)+z4e3026977c*(0x9e8+6583-0x239b)];z095557afa2=(uint32_T)mxGetPr(z8a52ac7545)[(0x77+2299-0x96f)+z4e3026977c*(0x1bb0+1128-0x2014)];y=ssGetOutputPortSignal(S,(0x738+2938-0x12b2));za42cf7dd4a[(0x2c1+4641-0x14e1)+z4e3026977c*(0x957+759-0xc48)]=(0x4d1+6336-0x1d90);while((za42cf7dd4a[(0x114+6398-0x1a10)+z4e3026977c*(0x1769+544-0x1983)]&(0xf27+1238-0x13fc))==(0xcdf+238-0xdcc));z7be9105675=za42cf7dd4a[(0xc95+1428-0x1228)+z4e3026977c*(0x1466+3323-0x215b)];if(z3125d30160==(0x22c4+839-0x260a)){y[(0x249+8763-0x2484)]=(real_T)(z7be9105675&zbb1608bd48);}else{y[(0x134b+37-0x1370)]=(real_T)(z7be9105675&zbb1608bd48);y[(0x147d+3086-0x208a)]=(real_T)((z7be9105675>>z59da8ef72c)&z095557afa2);}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

