/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xe5+7647-0x1ec2)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO112_ad_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x31\x32"
#define z694756a014 (0x16a9+4884-0x1908)
#define zea87e0ba83 36950
#define z29146a1837 (0x17f0+3514-0x14f5)
#define zab7e64468b 13361
#define zdf24515981          ((0x1fe2+946-0x238f))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0xbc1+2423-0x1538))
#define z8fd86139be               ssGetSFcnParam(S,(0x22f1+583-0x2537))
#define z19087bd486          ssGetSFcnParam(S,(0x115d+4763-0x23f6))
#define z3832b85a32           ssGetSFcnParam(S,(0xb37+720-0xe04))
#define z702a26a5e9                ssGetSFcnParam(S,(0x7c1+2644-0x1211))
#define z2e6483d505              ((0xd1d+6037-0x24b0))
#define z6a0da049de         ((0x10fc+275-0x120f))
#define zc2f3e0cbc0        ((0x142+2497-0xb02))
#define zc5ce4cb81a              ((0x1001+2264-0x18d7))
#define z8caad2a8e6              ((0xf5b+5152-0x237b))
#define z5bfe7a2613            ((0x256+576-0x495))
#define z2b17e2ee3b              ((0x8a+8774-0x22d0))
static char_T zea4cd01646[(0x1da2+259-0x1da5)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x24f+5466-0x17a9));ssSetNumDiscStates(S,(0x1756+3187-0x23c9));ssSetNumInputPorts(S,(0x16d7+797-0x19f4));ssSetNumOutputPorts(S,(0xf85+946-0x1336));

ssSetOutputPortWidth(S,(0x7f8+7517-0x2555),(uint32_T)mxGetPr(za9d8fb6bcf)[(0xcc1+5795-0x2364)]);







ssSetNumSampleTimes(S,(0x363+6497-0x1cc3));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1425+4185-0x247e));ssSetNumNonsampledZCs(S,(0x31d+8461-0x242a));for(i=(0xf86+1856-0x16c6);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1412+4649-0x263b));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x1407+3679-0x2266)]==-1.0){ssSetSampleTime(S,(0xc33+3388-0x196f),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x4e4+5292-0x1990),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x1028+1788-0x1724),mxGetPr(z3832b85a32)[(0x121f+4437-0x2374)]);ssSetOffsetTime(S,(0x2323+336-0x2473),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T range,out;uint16_T z4e3026977c;uint32_T zf91d71c6d9=(uint32_T)mxGetPr(za9d8fb6bcf)[(0x13e5+2162-0x1c57)];if((int_T)mxGetPr(z702a26a5e9)[(0x1c56+2005-0x242b)]<(0x553+6494-0x1eb1)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x8cd+6274-0x214e)){z366b2f03bf=(0x1619+352-0x1779);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x13f9+202-0x14c3)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x48a+4760-0x1722)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xd9+4492-0x1264)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x77a+3154-0x12cd))|((z366b2f03bf&(0x49b+3950-0x130a))<<(0x1c79+2066-0x2483)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0xd6d+4617-0x1f74)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x4ed+6461-0x1daa),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,zc2f3e0cbc0,(uint32_T)zf91d71c6d9);if((uint32_T)mxGetPr(z19087bd486)[(0xb46+3716-0x19ca)]==(0xe38+5351-0x231e)){
switch((uint32_T)mxGetPr(z8fd86139be)[(0xb9a+377-0xd13)]){case(0x1eb6+975-0x2284):
ssSetRWorkValue(S,z8caad2a8e6,13107.15);ssSetRWorkValue(S,z5bfe7a2613,10.0);break;case(0xd55+2991-0x1902):
ssSetRWorkValue(S,z8caad2a8e6,26214.3);ssSetRWorkValue(S,z5bfe7a2613,5.0);break;}}else{
switch((uint32_T)mxGetPr(z8fd86139be)[(0x3c8+3318-0x10be)]){case(0x150f+2194-0x1da0):
ssSetRWorkValue(S,z8caad2a8e6,3276.8);ssSetRWorkValue(S,z5bfe7a2613,10.0);break;case(0xd60+3399-0x1aa5):
ssSetRWorkValue(S,z8caad2a8e6,6553.6);ssSetRWorkValue(S,z5bfe7a2613,5.0);break;}}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T zf91d71c6d9=ssGetIWorkValue(S,zc2f3e0cbc0);volatile uint32_T*za42cf7dd4a;uint32_T z32b35fb51b=(uint32_T)mxGetPr(z19087bd486)[(0x87c+2182-0x1102)];real_T*y,z0754dd67cc,offset;uint32_T i;uint32_T count;za42cf7dd4a=(void*)base;za42cf7dd4a[(0x673+5244-0x1aef)]=za42cf7dd4a[(0x1e06+330-0x1f50)]|(0x1129+6774-0x1b9f);y=ssGetOutputPortSignal(S,(0xb47+132-0xbcb));z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6);offset=ssGetRWorkValue(S,z5bfe7a2613);i=(0xdd+9584-0x264d);
while(!(za42cf7dd4a[(0x1257+313-0x138d)]&524288))i++;
if(z32b35fb51b==(0x1aa7+914-0x1e38)){
for(i=(0x949+1088-0xd89);i<zf91d71c6d9;i++){
count=za42cf7dd4a[(0x826+6593-0x21e5)];
y[i]=(real_T)(count&262143)/z0754dd67cc-offset;}}else{

count=za42cf7dd4a[(0x8e7+4167-0x192c)];if(count!=65537){printf("\x73\x6f\x6d\x65\x74\x68\x69\x6e\x67\x20\x73\x74\x72\x61\x6e\x67\x65" "\n");}for(i=(0x1556+4311-0x262d);i<zf91d71c6d9/(0x749+7950-0x2655);i++){
count=za42cf7dd4a[(0x451+5738-0x1ab9)];
y[(0xd0b+80-0xd5b)+i*(0x8d4+2904-0x142a)]=(real_T)(count&65535)/z0754dd67cc-offset;y[(0x1c5f+1727-0x231d)+i*(0x184+1699-0x825)]=(real_T)((count&4294901760)>>(0x1187+2063-0x1986))/z0754dd67cc-offset;}}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

