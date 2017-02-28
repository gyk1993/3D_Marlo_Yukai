/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xedc+5203-0x232d)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO110_setup_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x31\x30"
#define z694756a014 (0x1ae3+1029-0xa50)
#define zea87e0ba83 (0x18e0+2226-0x1f69)
#define z29146a1837 (0x23ec+3283-0x1c27)
#define zab7e64468b (0x3ea+2455-0xd77)
#define zdf24515981          ((0x1061+1229-0x1528))
#define z702a26a5e9                ssGetSFcnParam(S,(0xc00+2919-0x1767))
#define z1f7e7173d9          ssGetSFcnParam(S,(0x12c3+23-0x12d9))
#define z84dd9a9a5c            ssGetSFcnParam(S,(0xa74+6252-0x22de))
#define z4d2d92ea80         ssGetSFcnParam(S,(0x18f5+2900-0x2446))
#define z9c3881c2c2           ssGetSFcnParam(S,(0x6bf+2554-0x10b5))
#define zc6f930323f            ssGetSFcnParam(S,(0x200+5877-0x18f0))
#define z2e6483d505              ((0x588+3724-0x13b0))
#define z71d06eae75        ((0x1255+4414-0x2393))
#define ze575982d5f        ((0x336+2769-0xe06))
#define z9c9edc1d33        ((0x1ca4+555-0x1ecd))
#define zc5ce4cb81a              ((0x883+953-0xbfc))
#define z2b17e2ee3b              ((0xbc+123-0x137))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0x1203+658-0x1395)];static uint16_T z0363d30aab(uint16_T x){if(x%(0x13bf+3275-0x2088)==(0x111b+3084-0x1d27))return x+(0x176f+3198-0x23ec);else return x-(0x1379+2849-0x1e99);}static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x11cb+1289-0x16d4));ssSetNumDiscStates(S,(0x344+3794-0x1216));ssSetNumInputPorts(S,(0x8ca+3650-0x170c));ssSetNumOutputPorts(S,(0xa22+774-0xd28));ssSetNumSampleTimes(S,(0xb74+2668-0x15df));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1c98+1046-0x20ae));ssSetNumNonsampledZCs(S,(0x1153+563-0x1386));for(i=(0x1545+3803-0x2420);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x12bc+3136-0x1efc));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x363+592-0x5b3),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x782+947-0xb35),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zef529fae4a;void*ze2370ae9b9;volatile uint32_T*z3e5b8e05d8;void*zdfcb1da404,*z4b22edbbef,*z3a3f02d297;void*zf2db5722bf,*z25b7c8cb15,*z347e24803c;volatile uint32_T*z27fd94ac66;volatile uint16_T*z7638e8fb2b;volatile int16_T*z730e4b2b7b;uint_T i,z812c65ff2f;uint32_T out;if((int_T)mxGetPr(z702a26a5e9)[(0x34c+5149-0x1769)]<(0xeb6+681-0x115f)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x607+2861-0x1133)){z366b2f03bf=(0x13eb+1431-0x1982);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x113+9577-0x267c)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x548+1774-0xc36)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xf5b+2723-0x19fd)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x1645+2727-0x1fed))|((z366b2f03bf&(0x1886+1663-0x1e06))<<(0xc47+2381-0x158c)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zef529fae4a=(void*)zeccbadd9b3.BaseAddress[(0x16b3+2362-0x1fed)];ze2370ae9b9=rl32eGetDevicePtr(zef529fae4a,(0x340+2172-0x9bc),RT_PG_USERREADWRITE);z3e5b8e05d8=(volatile uint32_T*)ze2370ae9b9;zdfcb1da404=(void*)zeccbadd9b3.BaseAddress[(0x1bd5+2866-0x2705)];zf2db5722bf=rl32eGetDevicePtr(zdfcb1da404,(0x1881+3813-0x2566),RT_PG_USERREADWRITE);z27fd94ac66=(volatile uint32_T*)zf2db5722bf;z4b22edbbef=(void*)zeccbadd9b3.BaseAddress[(0x219+8169-0x21ff)];z25b7c8cb15=rl32eGetDevicePtr(z4b22edbbef,(0x1c2a+2450-0x257c),RT_PG_USERREADWRITE);z7638e8fb2b=(volatile uint16_T*)z25b7c8cb15;z3a3f02d297=(void*)zeccbadd9b3.BaseAddress[(0x6b+9852-0x26e3)];z347e24803c=rl32eGetDevicePtr(z3a3f02d297,(0xe30+5287-0x1ed7),RT_PG_USERREADWRITE);z730e4b2b7b=(volatile int16_T*)z347e24803c;


ssSetIWorkValue(S,z71d06eae75,(uint32_T)z27fd94ac66);ssSetIWorkValue(S,ze575982d5f,(uint32_T)z7638e8fb2b);ssSetIWorkValue(S,z9c9edc1d33,(uint32_T)z730e4b2b7b);if(xpceIsModelInit()){
z3e5b8e05d8[(0x177+7299-0x1df0)]=z3e5b8e05d8[(0x11c1+787-0x14ca)]&4278190079;z3e5b8e05d8[(0x231+3664-0x1076)]=z3e5b8e05d8[(0x32+3943-0xf8e)]&4278190079;z3e5b8e05d8[(0x16c5+1404-0x1c35)]=z3e5b8e05d8[(0x1eb+2900-0xd33)]&4278190079;}for(i=(0xb4f+4497-0x1ce0);i<(0x1d7+6755-0x1c1a);i++){switch((uint16_T)mxGetPr(zc6f930323f)[i]){case(0x9c+5302-0x1552):ssSetRWorkValue(S,i,13107.2);break;case(0xacc+3721-0x1954):ssSetRWorkValue(S,i,6553.6);break;case(0x12b1+2827-0x1dba):ssSetRWorkValue(S,i,6068.148);break;case(0x1108+4747-0x2390):ssSetRWorkValue(S,i,6553.6);break;case(0x1481+304-0x15ad):ssSetRWorkValue(S,i,3276.8);break;case(0x17b5+2314-0x20ba):ssSetRWorkValue(S,i,3034.074);break;}}
for(i=(0xd03+2186-0x158d);i<(0x14a6+1487-0x1a55);i++){uint16_T range;range=(uint16_T)mxGetPr(zc6f930323f)[i];ssSetIWorkValue(S,(0x30+5406-0x1544)+i,z730e4b2b7b[z0363d30aab((0x1e3a+910-0x2188)*range+i)]);ssSetIWorkValue(S,(0x17c3+3218-0x244b)+i+(0x38+3094-0xc2e),z730e4b2b7b[z0363d30aab(((0xab6+1334-0xfac)*range)+(0x928+6576-0x22b8)+i)]);}if(xpceIsModelInit()){
z3e5b8e05d8[(0x419+7793-0x2280)]=z3e5b8e05d8[(0x1c4c+452-0x1e06)]&4278190079;z3e5b8e05d8[(0xbc8+5087-0x1f9c)]=z3e5b8e05d8[(0x698+6567-0x2034)]&4278190079;z3e5b8e05d8[(0x6da+7357-0x238b)]=z3e5b8e05d8[(0x1b52+390-0x1ccc)]&4278190079;
for(i=(0x1457+4211-0x24ca);i<(0x1477+2857-0x1f98);i++){
z27fd94ac66[(0x1fe1+1768-0x26c1)+i]=(0x1c4f+2435-0x25d2);}
for(i=(0x28f+6588-0x1c4b);i<(0x10e9+717-0x13ae);i++){z812c65ff2f=(0x919+2993-0x14ca);while(z27fd94ac66[(0x19f1+301-0x1afb)]&((0x11c1+2630-0x1c06)<<(i*(0x1045+4911-0x2370))))z812c65ff2f++;
z27fd94ac66[(0xd9+3452-0xe55)+i]=(uint32_T)mxGetPr(z9c3881c2c2)[i];}



}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T z31a846515d=ssGetIWorkValue(S,z71d06eae75);uint32_T z8ace1f9f47=ssGetIWorkValue(S,ze575982d5f);uint16_T i,z4e3026977c;volatile uint32_T*z27fd94ac66;volatile int16_T*z7638e8fb2b;real_T out;z27fd94ac66=(void*)z31a846515d;z7638e8fb2b=(void*)z8ace1f9f47;for(i=(0x501+2800-0xff1);i<mxGetN(z1f7e7173d9);i++){if(xpceIsModelInit()||(int)mxGetPr(z84dd9a9a5c)[i]){z4e3026977c=(uint16_T)mxGetPr(z1f7e7173d9)[i]-(0xe69+3478-0x1bfe);out=mxGetPr(z4d2d92ea80)[i]*ssGetRWorkValue(S,z4e3026977c);
out=out*(1.0-(real_T)ssGetIWorkValue(S,(0x1a21+3081-0x2620)+z4e3026977c)/131072.0)-(real_T)ssGetIWorkValue(S,(0xbf+7240-0x1cfd)+z4e3026977c+(0xabd+516-0xca1))/4.0;




z7638e8fb2b[z0363d30aab(z4e3026977c)]=(int16_T)out;}}
#endif    
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

