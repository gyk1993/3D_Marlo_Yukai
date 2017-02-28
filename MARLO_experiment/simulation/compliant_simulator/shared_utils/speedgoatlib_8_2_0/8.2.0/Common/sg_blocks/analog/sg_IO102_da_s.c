/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x7e7+835-0xb28)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO102_da_s
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
#define z694756a014 (0x1a6a+6427-0x22d0)
#define zea87e0ba83 36992
#define z29146a1837 (0x16ed+1107-0xa8b)
#define zab7e64468b 9218
#define zdf24515981          ((0x8c4+115-0x933))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0x224b+1083-0x2686))
#define z8fd86139be               ssGetSFcnParam(S,(0x660+3273-0x1328))
#define z3832b85a32           ssGetSFcnParam(S,(0xd93+1778-0x1483))
#define z702a26a5e9                ssGetSFcnParam(S,(0x119d+2331-0x1ab5))
#define z2e6483d505              ((0xb9c+6978-0x26dc))
#define z7e2eeaa57c          ((0x6b8+1882-0xe12))
#define z6a0da049de         ((0x1070+4861-0x236c))
#define zc5ce4cb81a              ((0xa31+2048-0x122f))
#define z8caad2a8e6              ((0x5f2+2402-0xf54))
#define z5bfe7a2613            ((0x1335+2969-0x1ecd))
#define z2b17e2ee3b              ((0x29+9654-0x25df))
static char_T zea4cd01646[(0xb0f+477-0xbec)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x4d9+8583-0x2660));ssSetNumDiscStates(S,(0x16e8+614-0x194e));ssSetNumOutputPorts(S,(0x129d+227-0x1380));ssSetNumInputPorts(S,(int)mxGetN(za9d8fb6bcf));for(i=(0xcb4+4323-0x1d97);i<(int)mxGetN(za9d8fb6bcf);i++){ssSetInputPortWidth(S,i,(0x392+3494-0x1137));ssSetInputPortDirectFeedThrough(S,i,(0xb5c+225-0xc3c));ssSetInputPortRequiredContiguous(S,i,(0x122+6334-0x19df));}ssSetNumSampleTimes(S,(0xa2a+6728-0x2471));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x9a7+4558-0x1b75));ssSetNumNonsampledZCs(S,(0x14dc+3051-0x20c7));for(i=(0x1790+2431-0x210f);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x10ff+4228-0x2183));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x10ab+1129-0x1514)]==-1.0){ssSetSampleTime(S,(0x810+4598-0x1a06),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xcda+492-0xec6),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x1df+7190-0x1df5),mxGetPr(z3832b85a32)[(0x1be6+1491-0x21b9)]);ssSetOffsetTime(S,(0x131+3933-0x108e),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;uint16_T zf91d71c6d9=(int)mxGetN(za9d8fb6bcf);real_T z19c4ca5f82,start;uint32_T range;if((int_T)mxGetPr(z702a26a5e9)[(0x1004+4365-0x2111)]<(0x4ec+6787-0x1f6f)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xfd6+4567-0x21ac)){z366b2f03bf=(0x124a+3929-0x21a3);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xab9+1841-0x11ea)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0xaf7+4105-0x1b00)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x794+1135-0xc02)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x95a+6209-0x209c))|((z366b2f03bf&(0x5cb+835-0x80f))<<(0x7c7+3807-0x169e)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x50+2606-0xa7c)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x222f+165-0x2294),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,z7e2eeaa57c,zf91d71c6d9);switch((uint16_T)mxGetPr(z8fd86139be)[(0x1436+3067-0x2031)]){case(0x849+2170-0x10c2):ssSetRWorkValue(S,z8caad2a8e6,3276.8);ssSetRWorkValue(S,z5bfe7a2613,10.0);range=(0xd13+6433-0x2632);break;case(0x1632+780-0x193c):ssSetRWorkValue(S,z8caad2a8e6,6553.6);ssSetRWorkValue(S,z5bfe7a2613,5.0);range=(0xd2f+2377-0x1677);break;case(0x16b6+2049-0x1eb4):ssSetRWorkValue(S,z8caad2a8e6,13107.2);ssSetRWorkValue(S,z5bfe7a2613,2.5);range=(0x907+690-0xbb9);break;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T zf91d71c6d9=ssGetIWorkValue(S,z7e2eeaa57c);real_T z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6);real_T offset=ssGetRWorkValue(S,z5bfe7a2613);uint16_T i;volatile uint32_T*za42cf7dd4a;real_T*zc7fdaf6331;int32_T out;uint16_T z4e3026977c;real_T zd3add15c40,zbd0243c03e;uint16_T first=(0x661+3206-0x12e6);real_T scale=3276.8;za42cf7dd4a=(void*)base;for(i=(0x11a2+4788-0x2456);i<zf91d71c6d9;i++){if(first){first=(0x155+5164-0x1581);}else{za42cf7dd4a[(0x10fa+1693-0x1791)]=out|(z4e3026977c<<(0x1c56+463-0x1e15));}z4e3026977c=(uint16_T)mxGetPr(za9d8fb6bcf)[i]-(0x132+6531-0x1ab4);zc7fdaf6331=(real_T*)ssGetInputPortRealSignal(S,i);out=(int32_T)((zc7fdaf6331[(0xf9+7651-0x1edc)]+offset)*z0754dd67cc);if(out>65535)out=65535;if(out<(0x1778+1215-0x1c37))out=(0x15a0+315-0x16db);}za42cf7dd4a[(0x301+7846-0x21a1)]=out|(z4e3026977c<<(0x762+1157-0xbd7))|786432;za42cf7dd4a[(0xb66+5568-0x2126)]=za42cf7dd4a[(0x10f+2300-0xa0b)]|(0xc15+7307-0x20a0);
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

