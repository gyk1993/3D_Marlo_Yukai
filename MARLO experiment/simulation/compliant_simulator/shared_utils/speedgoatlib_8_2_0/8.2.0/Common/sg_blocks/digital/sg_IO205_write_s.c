/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x18f5+3237-0x2598)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO205_write_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x32\x30\x35"
#define z694756a014 (0x1734+439-0x453)
#define zea87e0ba83 (0x24ca+871-0x2575)
#define zdf24515981          ((0x9e8+3307-0x16d0))
#define z2cc9a52544            ssGetSFcnParam(S,(0x12ba+4891-0x25d5))
#define z3832b85a32           ssGetSFcnParam(S,(0xa77+1689-0x110f))
#define z702a26a5e9                ssGetSFcnParam(S,(0xc08+1325-0x1133))
#define z2e6483d505              ((0x234b+607-0x25a8))
#define z6a0da049de         ((0x4b5+2966-0x104b))
#define zc2f3e0cbc0        ((0xc0+3984-0x104f))
#define zc5ce4cb81a              ((0x3a6+5695-0x19e5))
#define z2b17e2ee3b              ((0x1df7+223-0x1ed6))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0x8b6+4768-0x1a56)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x3e7+7623-0x21ae));ssSetNumDiscStates(S,(0x44+2480-0x9f4));ssSetNumOutputPorts(S,(0x179+8556-0x22e5));switch((uint8_T)mxGetPr(z2cc9a52544)[(0x1088+4362-0x2192)]){case(0x19bf+695-0x1c75):ssSetNumInputPorts(S,(0xb7+6777-0x1b10));for(i=(0x12b5+3899-0x21f0);i<(0xd35+5532-0x22b1);i++){ssSetInputPortWidth(S,i,(0xba0+2948-0x1723));ssSetInputPortRequiredContiguous(S,i,(0x89d+2295-0x1193));}break;case(0x6b2+4979-0x1a23):ssSetNumInputPorts(S,(0x1094+5214-0x24d2));for(i=(0x1c38+2454-0x25ce);i<(0x516+3865-0x140f);i++){ssSetInputPortWidth(S,i,(0x1373+1136-0x17e2));ssSetInputPortDataType(S,i,SS_BOOLEAN);ssSetInputPortRequiredContiguous(S,i,(0x2273+583-0x24b9));}break;case(0x12b+8023-0x207f):ssSetNumInputPorts(S,(0x1b40+577-0x1d80));ssSetInputPortWidth(S,(0x1b6f+471-0x1d46),(0x1b3d+1536-0x211d));ssSetInputPortRequiredContiguous(S,(0x193+3967-0x1112),(0xcca+1344-0x1209));break;case(0x26+9580-0x258e):ssSetNumInputPorts(S,(0x16df+3909-0x2623));ssSetInputPortWidth(S,(0x97d+6979-0x24c0),(0x1000+2684-0x1a5c));ssSetInputPortDataType(S,(0xd76+6551-0x270d),SS_BOOLEAN);ssSetInputPortRequiredContiguous(S,(0xaaa+2684-0x1526),(0xac4+2834-0x15d5));break;case(0xc76+2865-0x17a2):ssSetNumInputPorts(S,(0x657+7631-0x2425));ssSetInputPortWidth(S,(0xa9a+2150-0x1300),(0x40c+7994-0x2345));ssSetInputPortDataType(S,(0x1183+2930-0x1cf5),SS_UINT32);ssSetInputPortRequiredContiguous(S,(0xe25+5526-0x23bb),(0x1a9b+98-0x1afc));break;}ssSetNumSampleTimes(S,(0x132f+3447-0x20a5));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x7a6+1684-0xe3a));ssSetNumNonsampledZCs(S,(0x894+5185-0x1cd5));for(i=(0xe29+4235-0x1eb4);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xeda+4823-0x21b1));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x246f+459-0x263a)]==-1.0){ssSetSampleTime(S,(0x1355+1931-0x1ae0),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x15dc+4101-0x25e1),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xd08+6646-0x26fe),mxGetPr(z3832b85a32)[(0x1837+1351-0x1d7e)]);ssSetOffsetTime(S,(0xc09+897-0xf8a),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zef529fae4a;void*ze2370ae9b9;volatile uint32_T*z3e5b8e05d8;void*zdfcb1da404;void*zf2db5722bf;volatile uint32_T*z27fd94ac66;uint_T i;uint32_T out;if((int_T)mxGetPr(z702a26a5e9)[(0x13e0+1466-0x199a)]<(0x4eb+2887-0x1032)){
if(rl32eGetPCIInfo((uint16_T)z694756a014,(uint16_T)zea87e0ba83,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{int_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x1e10+56-0x1e47)){z366b2f03bf=(0x1910+1716-0x1fc4);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x1a1a+462-0x1be8)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x10f7+2910-0x1c55)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x64+8845-0x22f0)];}
if(rl32eGetPCIInfoAtSlot((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(z441f9e6d1b&(0x545+6425-0x1d5f))|((z366b2f03bf&(0xed7+4926-0x2116))<<(0xcb+6288-0x1953)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zef529fae4a=(void*)zeccbadd9b3.BaseAddress[(0x2f8+1671-0x97f)];ze2370ae9b9=rl32eGetDevicePtr(zef529fae4a,(0x151+4707-0x1334),RT_PG_USERREADWRITE);z3e5b8e05d8=(volatile uint32_T*)ze2370ae9b9;zdfcb1da404=(void*)zeccbadd9b3.BaseAddress[(0x547+5008-0x18d5)];zf2db5722bf=rl32eGetDevicePtr(zdfcb1da404,(0xd75+612-0xfc9),RT_PG_USERREADWRITE);z27fd94ac66=(volatile uint32_T*)zf2db5722bf;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)z27fd94ac66);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*z27fd94ac66;uint32_T i,output;real_T*y1;boolean_T*y2;uint32_T*z671e76e748;z27fd94ac66=(void*)base;switch((uint8_T)mxGetPr(z2cc9a52544)[(0x138f+2355-0x1cc2)]){case(0xf7d+1037-0x1389):output=(0x806+357-0x96b);for(i=(0xeb2+4774-0x2158);i<(0x300+3726-0x116e);i++){y1=(real_T*)ssGetInputPortSignal(S,i);if(y1[(0x168+8993-0x2489)]>=THRESHOLD){output|=(0xbff+1108-0x1052)<<i;}}break;case(0xa85+2260-0x1357):output=(0x8ca+4901-0x1bef);for(i=(0x5b5+502-0x7ab);i<(0x42b+16-0x41b);i++){y2=(boolean_T*)ssGetInputPortSignal(S,i);if(y2[(0x32d+8499-0x2460)]){output|=(0x5ab+2784-0x108a)<<i;}}break;case(0x1bfc+1985-0x23ba):output=(0x17c9+1304-0x1ce1);y1=(real_T*)ssGetInputPortSignal(S,(0x795+7276-0x2401));for(i=(0x229+6105-0x1a02);i<(0x1ea+3738-0x1064);i++){if(y1[i]>=THRESHOLD){output|=(0x2d3+6-0x2d8)<<i;}}break;case(0x22c2+538-0x24d8):output=(0xe78+1068-0x12a4);y2=(boolean_T*)ssGetInputPortSignal(S,(0x191+4454-0x12f7));for(i=(0x581+2994-0x1133);i<(0x15d6+442-0x1770);i++){if(y2[i]){output|=(0x16bb+2657-0x211b)<<i;}}break;case(0x9fa+1524-0xfe9):z671e76e748=(uint32_T*)ssGetInputPortSignal(S,(0x59c+2201-0xe35));output=z671e76e748[(0x107d+2642-0x1acf)];break;}z27fd94ac66[(0x15f2+3259-0x22ad)]=output;
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

