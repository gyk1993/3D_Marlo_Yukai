/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x13c7+1301-0x18da)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO203_write_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x32\x30\x33"
#define z694756a014 5272
#define zea87e0ba83 (0xeed+1890-0x13a6)
#define zdf24515981          ((0xfdd+2418-0x194b))
#define z2cc9a52544            ssGetSFcnParam(S,(0x7ea+6846-0x22a8))
#define ze072c43310               ssGetSFcnParam(S,(0x1e92+411-0x202c))
#define z3832b85a32           ssGetSFcnParam(S,(0x1e80+1180-0x231a))
#define z702a26a5e9                ssGetSFcnParam(S,(0xf2a+727-0x11fe))
#define z2e6483d505              ((0x6ec+7350-0x23a0))
#define z6a0da049de         ((0x570+4980-0x18e4))
#define zc2f3e0cbc0        ((0x1e91+2037-0x2685))
#define zc5ce4cb81a              ((0x4d4+4784-0x1784))
#define z2b17e2ee3b              ((0x1377+3021-0x1f44))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0x203d+1895-0x26a4)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x124a+4786-0x24fc));ssSetNumDiscStates(S,(0xbec+352-0xd4c));ssSetNumOutputPorts(S,(0x91b+6145-0x211c));switch((uint8_T)mxGetPr(z2cc9a52544)[(0x155d+717-0x182a)]){case(0x2234+674-0x24d5):ssSetNumInputPorts(S,(0x42d+7951-0x231c));for(i=(0x14b+994-0x52d);i<(0x4bd+6421-0x1db2);i++){ssSetInputPortWidth(S,i,(0x1d28+1239-0x21fe));ssSetInputPortDirectFeedThrough(S,i,(0x20b+1240-0x6e2));ssSetInputPortRequiredContiguous(S,i,(0xb03+3678-0x1960));}break;case(0x13dc+4512-0x257a):ssSetNumInputPorts(S,(0xcf3+3758-0x1b81));for(i=(0x428+3536-0x11f8);i<(0x1df3+1515-0x23be);i++){ssSetInputPortWidth(S,i,(0x1f03+328-0x204a));ssSetInputPortDataType(S,i,SS_BOOLEAN);ssSetInputPortDirectFeedThrough(S,i,(0xbe7+4962-0x1f48));ssSetInputPortRequiredContiguous(S,i,(0x1ab+207-0x279));}break;case(0xe3b+884-0x11ac):ssSetNumInputPorts(S,(0x172c+3190-0x23a1));ssSetInputPortWidth(S,(0x1cfc+2305-0x25fd),(0x211b+731-0x23d6));ssSetInputPortDirectFeedThrough(S,(0x43a+6429-0x1d57),(0x6da+362-0x843));ssSetInputPortRequiredContiguous(S,(0x1a8f+2279-0x2376),(0xe97+765-0x1193));break;case(0x1c19+2082-0x2437):ssSetNumInputPorts(S,(0x824+7651-0x2606));ssSetInputPortWidth(S,(0x10a8+5689-0x26e1),(0x1cb1+659-0x1f24));ssSetInputPortDataType(S,(0x6c6+2886-0x120c),SS_BOOLEAN);ssSetInputPortDirectFeedThrough(S,(0x838+362-0x9a2),(0x6cc+2462-0x1069));ssSetInputPortRequiredContiguous(S,(0x7f5+245-0x8ea),(0x41d+5810-0x1ace));break;case(0xaed+1342-0x1026):ssSetNumInputPorts(S,(0x4b+5212-0x14a6));ssSetInputPortWidth(S,(0x1a77+470-0x1c4d),(0x369+6185-0x1b91));ssSetInputPortDataType(S,(0xd19+592-0xf69),SS_UINT32);ssSetInputPortDirectFeedThrough(S,(0x19c1+1106-0x1e13),(0xbc+5183-0x14fa));ssSetInputPortRequiredContiguous(S,(0x271+3572-0x1065),(0x1bb3+1851-0x22ed));break;default:ssSetNumInputPorts(S,(0xa90+3023-0x165f));break;}ssSetNumSampleTimes(S,(0x79d+5813-0x1e51));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x356+2251-0xc21));ssSetNumNonsampledZCs(S,(0x1ce9+2039-0x24e0));for(i=(0x11c5+4746-0x244f);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x47a+7702-0x2290));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x804+2508-0x11d0)]==-1.0){ssSetSampleTime(S,(0x1d0d+59-0x1d48),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x13d5+3588-0x21d9),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xebb+4188-0x1f17),mxGetPr(z3832b85a32)[(0x1cef+2140-0x254b)]);ssSetOffsetTime(S,(0x453+6010-0x1bcd),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zef529fae4a;void*ze2370ae9b9;volatile uint32_T*z3e5b8e05d8;void*zdfcb1da404;void*zf2db5722bf;volatile uint32_T*z27fd94ac66;uint_T i;uint32_T out;if((int_T)mxGetPr(z702a26a5e9)[(0x1f64+520-0x216c)]<(0xfe0+4296-0x20a8)){
if(rl32eGetPCIInfo((uint16_T)z694756a014,(uint16_T)zea87e0ba83,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{int_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x22+1907-0x794)){z366b2f03bf=(0xeb4+5782-0x254a);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x1282+684-0x152e)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0xcf2+3939-0x1c55)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x10ef+4289-0x21af)];}
if(rl32eGetPCIInfoAtSlot((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(z441f9e6d1b&(0xffc+4717-0x216a))|((z366b2f03bf&(0x129d+3249-0x1e4f))<<(0xdf9+1773-0x14de)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zef529fae4a=(void*)zeccbadd9b3.BaseAddress[(0x817+1627-0xe72)];ze2370ae9b9=rl32eGetDevicePtr(zef529fae4a,(0xb59+3256-0x1611),RT_PG_USERREADWRITE);z3e5b8e05d8=(volatile uint32_T*)ze2370ae9b9;zdfcb1da404=(void*)zeccbadd9b3.BaseAddress[(0x7ff+596-0xa51)];zf2db5722bf=rl32eGetDevicePtr(zdfcb1da404,(0x1472+739-0x1655),RT_PG_USERREADWRITE);z27fd94ac66=(volatile uint32_T*)zf2db5722bf;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)z27fd94ac66);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*z27fd94ac66;uint32_T i,output;real_T*y1;boolean_T*y2;uint32_T*z671e76e748;z27fd94ac66=(void*)base;switch((uint8_T)mxGetPr(z2cc9a52544)[(0x815+1499-0xdf0)]){case(0xe27+4943-0x2175):output=(0xa3+8024-0x1ffb);for(i=(0x1da4+1572-0x23c8);i<(0x137f+1235-0x1832);i++){y1=(real_T*)ssGetInputPortSignal(S,i);if(y1[(0xcac+5483-0x2217)]>=THRESHOLD){output|=(0x1b0c+2275-0x23ee)<<i;}}break;case(0x1a5+9274-0x25dd):output=(0xe4+5290-0x158e);for(i=(0x15d5+1925-0x1d5a);i<(0xce5+6459-0x2600);i++){y2=(boolean_T*)ssGetInputPortSignal(S,i);if(y2[(0x22c6+332-0x2412)]){output|=(0x350+4975-0x16be)<<i;}}break;case(0xad5+5187-0x1f15):output=(0x143a+3503-0x21e9);y1=(real_T*)ssGetInputPortSignal(S,(0x12+2060-0x81e));for(i=(0x743+7771-0x259e);i<(0x28b+6538-0x1bf5);i++){if(y1[i]>=THRESHOLD){output|=(0x780+4867-0x1a82)<<i;}}break;case(0x65+4103-0x1068):output=(0xd1+1649-0x742);y2=(boolean_T*)ssGetInputPortSignal(S,(0xcd7+4259-0x1d7a));for(i=(0x1601+4112-0x2611);i<(0x113b+3931-0x2076);i++){if(y2[i]){output|=(0x6fb+2469-0x109f)<<i;}}break;case(0x1936+594-0x1b83):z671e76e748=(uint32_T*)ssGetInputPortSignal(S,(0x12f7+98-0x1359));output=z671e76e748[(0x12df+3312-0x1fcf)];break;}if(((uint8_T)mxGetPr(ze072c43310)[(0x354+4109-0x1361)])==(0x1cc7+2482-0x2678)){z27fd94ac66[(0x70a+137-0x793)]=output;}else{z27fd94ac66[(0xb97+2282-0x1480)]=output;}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

