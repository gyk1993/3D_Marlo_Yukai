/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x4db+4830-0x17b7)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO104_da_s
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
#define z694756a014 (0x1629+173-0x621)
#define zea87e0ba83 36950
#define z29146a1837 (0x26fa+3789-0x2512)
#define zab7e64468b 12658
#define zdf24515981          ((0x13ff+418-0x159d))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0x1209+26-0x1223))
#define z8fd86139be               ssGetSFcnParam(S,(0x1bad+2070-0x23c2))
#define z3832b85a32           ssGetSFcnParam(S,(0x1eec+1706-0x2594))
#define z702a26a5e9                ssGetSFcnParam(S,(0x57b+8387-0x263b))
#define z2e6483d505              ((0x1131+2990-0x1cdd))
#define z7e2eeaa57c          ((0x427+4032-0x13e7))
#define z6a0da049de         ((0x1205+548-0x1428))
#define zc5ce4cb81a              ((0x1180+4924-0x24ba))
#define z8caad2a8e6              ((0xec2+5521-0x2453))
#define z5bfe7a2613            ((0xa54+3406-0x17a1))
#define z2b17e2ee3b              ((0x40f+7840-0x22af))
static char_T zea4cd01646[(0x162f+1213-0x19ec)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xcd+5273-0x1566));ssSetNumDiscStates(S,(0x1a18+2701-0x24a5));ssSetNumOutputPorts(S,(0x8f8+2921-0x1461));ssSetNumInputPorts(S,(int)mxGetN(za9d8fb6bcf));for(i=(0x871+942-0xc1f);i<(int)mxGetN(za9d8fb6bcf);i++){ssSetInputPortWidth(S,i,(0xa96+3703-0x190c));ssSetInputPortDirectFeedThrough(S,i,(0x1f89+661-0x221d));ssSetInputPortRequiredContiguous(S,i,(0x7bd+4376-0x18d4));}ssSetNumSampleTimes(S,(0x23b+2179-0xabd));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xf95+384-0x1115));ssSetNumNonsampledZCs(S,(0x251f+237-0x260c));for(i=(0x6b5+6186-0x1edf);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xf04+4733-0x2181));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0xdeb+1931-0x1576)]==-1.0){ssSetSampleTime(S,(0x2b9+1434-0x853),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x642+572-0x87e),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xac2+4827-0x1d9d),mxGetPr(z3832b85a32)[(0x1804+3600-0x2614)]);ssSetOffsetTime(S,(0x13b2+3289-0x208b),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;uint16_T zf91d71c6d9=(int)mxGetN(za9d8fb6bcf);real_T z19c4ca5f82,start;uint32_T range;if((int_T)mxGetPr(z702a26a5e9)[(0x319+3905-0x125a)]<(0x432+8216-0x244a)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x242+7320-0x1ed9)){z366b2f03bf=(0x8f5+1213-0xdb2);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x4e5+3841-0x13e6)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0xe05+5666-0x2427)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xbd+4262-0x1162)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x695+1491-0xb69))|((z366b2f03bf&(0x45c+5208-0x17b5))<<(0x1910+1304-0x1e20)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0xa0b+6220-0x2255)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x120a+1364-0x16de),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,z7e2eeaa57c,zf91d71c6d9);switch((uint16_T)mxGetPr(z8fd86139be)[(0x6f8+2866-0x122a)]){case(0x129d+3511-0x2053):ssSetRWorkValue(S,z8caad2a8e6,3276.8);ssSetRWorkValue(S,z5bfe7a2613,10.0);range=(0xd93+6135-0x2588);break;case(0x20ab+679-0x2350):ssSetRWorkValue(S,z8caad2a8e6,6553.6);ssSetRWorkValue(S,z5bfe7a2613,5.0);range=(0x261+8556-0x23cc);break;case(0x1619+3618-0x2438):ssSetRWorkValue(S,z8caad2a8e6,13107.2);ssSetRWorkValue(S,z5bfe7a2613,2.5);range=(0x122+7014-0x1c88);break;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T zf91d71c6d9=ssGetIWorkValue(S,z7e2eeaa57c);real_T z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6);real_T offset=ssGetRWorkValue(S,z5bfe7a2613);uint16_T i;volatile uint32_T*za42cf7dd4a;real_T*zc7fdaf6331;int32_T out;uint16_T z4e3026977c;volatile uint32_T z7be9105675;za42cf7dd4a=(void*)base;for(i=(0x6b3+747-0x99e);i<zf91d71c6d9;i++){z4e3026977c=(uint16_T)mxGetPr(za9d8fb6bcf)[i]-(0x8c6+7699-0x26d8);zc7fdaf6331=(real_T*)ssGetInputPortRealSignal(S,i);out=(int32_T)((zc7fdaf6331[(0x540+388-0x6c4)]+offset)*z0754dd67cc);if(out>65535)out=65535;if(out<(0x1541+488-0x1729))out=(0x8e5+3177-0x154e);za42cf7dd4a[(0x1d5+9530-0x270d)+z4e3026977c]=out;}





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

