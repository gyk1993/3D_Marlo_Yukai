/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1658+3302-0x233c)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO104_dawrite_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x30\x34"
#define z694756a014 (0x1b9a+2116-0x1329)
#define zea87e0ba83 36950
#define z29146a1837 (0x13f1+2949-0xec1)
#define zab7e64468b 12658
#define zdf24515981          ((0x1613+729-0x18e6))
#define za8bff65d14              ssGetSFcnParam(S,(0x3f+2769-0xb10))
#define z04bce731b0             ssGetSFcnParam(S,(0xd01+6491-0x265b))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0x2032+556-0x225c))
#define z8fd86139be               ssGetSFcnParam(S,(0xa0c+3583-0x1808))
#define z3832b85a32           ssGetSFcnParam(S,(0x182b+621-0x1a94))
#define z702a26a5e9                ssGetSFcnParam(S,(0x1517+3354-0x222c))
#define z2e6483d505              ((0x931+2509-0x12fc))
#define z7e2eeaa57c          ((0x1001+252-0x10fd))
#define z6a0da049de         ((0xd6b+1728-0x142a))
#define zc5ce4cb81a              ((0x7ec+5583-0x1db9))
#define z8caad2a8e6              ((0x110f+2679-0x1b86))
#define z5bfe7a2613            ((0x1ef3+531-0x2105))
#define z2b17e2ee3b              ((0x23c+4451-0x139f))
static char_T zea4cd01646[(0x6e3+2424-0xf5b)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x366+6935-0x1e7d));ssSetNumDiscStates(S,(0x234+3119-0xe63));if(!(boolean_T)mxGetPr(z04bce731b0)[(0x1346+3938-0x22a8)]){ssSetNumOutputPorts(S,(0xcd3+1371-0x122e));}else{ssSetNumOutputPorts(S,(0x5+8179-0x1ff7));ssSetOutputPortDataType(S,(0xcff+3608-0x1b17),SS_BOOLEAN);ssSetOutputPortWidth(S,(0x236+5173-0x166b),(0x2227+278-0x233c));}if(!(boolean_T)mxGetPr(za8bff65d14)[(0x2ed+856-0x645)]){ssSetNumInputPorts(S,(int)mxGetN(za9d8fb6bcf));for(i=(0x703+2936-0x127b);i<(int)mxGetN(za9d8fb6bcf);i++){ssSetInputPortWidth(S,i,(0x209+5170-0x163a));ssSetInputPortDirectFeedThrough(S,i,(0x12c6+1355-0x1810));ssSetInputPortRequiredContiguous(S,i,(0x1f55+1295-0x2463));}}else{ssSetNumInputPorts(S,(int)mxGetN(za9d8fb6bcf)+(0x1170+5025-0x2510));ssSetInputPortDirectFeedThrough(S,(0x22+919-0x3b9),(0xb89+1780-0x127c));ssSetInputPortWidth(S,(0x1339+1256-0x1821),(0x1a29+1300-0x1f3c));ssSetInputPortDataType(S,(0x35d+2515-0xd30),SS_BOOLEAN);ssSetInputPortRequiredContiguous(S,(0xa2+7993-0x1fdb),(0x38b+7146-0x1f74));for(i=(0xbb8+6063-0x2367);i<(int)mxGetN(za9d8fb6bcf);i++){ssSetInputPortWidth(S,i+(0x1710+3194-0x2389),(0xe8+6736-0x1b37));ssSetInputPortDirectFeedThrough(S,i+(0x1bd1+2387-0x2523),(0x22ad+206-0x237a));ssSetInputPortRequiredContiguous(S,i+(0x12cb+4932-0x260e),(0xc79+4384-0x1d98));}}ssSetNumSampleTimes(S,(0x49c+5420-0x19c7));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xdda+3606-0x1bf0));ssSetNumNonsampledZCs(S,(0x5dc+8230-0x2602));for(i=(0x3c0+5107-0x17b3);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x39c+997-0x781));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x272+8319-0x22f1)]==-1.0){ssSetSampleTime(S,(0x1756+3646-0x2594),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xcf5+3695-0x1b64),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x205+3893-0x113a),mxGetPr(z3832b85a32)[(0x142f+4804-0x26f3)]);ssSetOffsetTime(S,(0x17f1+1989-0x1fb6),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;uint16_T zf91d71c6d9=(int)mxGetN(za9d8fb6bcf);real_T z19c4ca5f82,start;uint32_T range;if((int_T)mxGetPr(z702a26a5e9)[(0x1ab3+1274-0x1fad)]<(0x276+8680-0x245e)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x536+6224-0x1d85)){z366b2f03bf=(0x242+1347-0x785);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x6c5+3057-0x12b6)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x1291+2700-0x1d1d)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x7e1+7578-0x257a)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x1e00+215-0x1dd8))|((z366b2f03bf&(0x1f7f+1453-0x242d))<<(0x141+5988-0x189d)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x1ba8+2062-0x23b4)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x1013+166-0x1039),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,z7e2eeaa57c,zf91d71c6d9);switch((uint16_T)mxGetPr(z8fd86139be)[(0x1a88+230-0x1b6e)]){case(0x1082+2700-0x1b0d):ssSetRWorkValue(S,z8caad2a8e6,3276.8);ssSetRWorkValue(S,z5bfe7a2613,10.0);range=(0x1102+2596-0x1b24);break;case(0x126+8877-0x23d1):ssSetRWorkValue(S,z8caad2a8e6,6553.6);ssSetRWorkValue(S,z5bfe7a2613,5.0);range=(0x1478+108-0x14e3);break;case(0xaf2+2679-0x1566):ssSetRWorkValue(S,z8caad2a8e6,13107.2);ssSetRWorkValue(S,z5bfe7a2613,2.5);range=(0x14b5+160-0x1555);break;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T zf91d71c6d9=ssGetIWorkValue(S,z7e2eeaa57c);real_T z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6);real_T offset=ssGetRWorkValue(S,z5bfe7a2613);uint16_T i;volatile uint32_T*za42cf7dd4a;real_T*zc7fdaf6331;int32_T out;uint16_T z4e3026977c;uint32_T z4314ccb6ec=(0x8a6+5212-0x1d02);boolean_T*z0daf90e5e1;boolean_T enabled=true;if((int)mxGetPr(za8bff65d14)[(0xc77+5743-0x22e6)]){z0daf90e5e1=(boolean_T*)ssGetInputPortSignal(S,(0x16ec+1877-0x1e41));enabled=z0daf90e5e1[(0xdea+4751-0x2079)];z4314ccb6ec=(0x6d8+1091-0xb1a);}if((int)mxGetPr(z04bce731b0)[(0x1778+3855-0x2687)]){z0daf90e5e1=(boolean_T*)ssGetOutputPortSignal(S,(0x1236+2775-0x1d0d));z0daf90e5e1[(0xeda+3218-0x1b6c)]=enabled;}za42cf7dd4a=(void*)base;if(enabled){for(i=(0x188c+2885-0x23d1);i<zf91d71c6d9;i++){z4e3026977c=(uint16_T)mxGetPr(za9d8fb6bcf)[i]-(0x5b+1088-0x49a);zc7fdaf6331=(real_T*)ssGetInputPortRealSignal(S,i+z4314ccb6ec);out=(int32_T)((zc7fdaf6331[(0xac3+6162-0x22d5)]+offset)*z0754dd67cc);if(out>65535)out=65535;if(out<(0x19ec+3277-0x26b9))out=(0x1baa+270-0x1cb8);za42cf7dd4a[(0x3bf+5403-0x18d8)+z4e3026977c]=out;}}
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

