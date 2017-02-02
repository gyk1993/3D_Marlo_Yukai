/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xed7+5806-0x2583)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO113_do_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x31\x33"
#define z694756a014 (0x1cf7+4414-0x1d80)
#define zea87e0ba83 36950
#define z29146a1837 (0x13df+4014-0x12d8)
#define zab7e64468b 13143
#define zdf24515981          ((0x5e7+679-0x88b))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0x1984+1384-0x1eec))
#define z3832b85a32           ssGetSFcnParam(S,(0x284+8487-0x23aa))
#define z702a26a5e9                ssGetSFcnParam(S,(0x16a5+3454-0x2421))
#define z2e6483d505              ((0x2163+142-0x21f0))
#define z6a0da049de         ((0x1ead+2117-0x26f2))
#define zc5ce4cb81a              ((0x17eb+1160-0x1c73))
#define z2b17e2ee3b              ((0xec7+349-0x1024))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0x18fc+869-0x1b61)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif

ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x504+5078-0x18da));ssSetNumDiscStates(S,(0xef+4114-0x1101));ssSetNumOutputPorts(S,(0x218+3608-0x1030));ssSetNumInputPorts(S,(int)mxGetN(za9d8fb6bcf));for(i=(0x21d1+4-0x21d5);i<(int)mxGetN(za9d8fb6bcf);i++){ssSetInputPortWidth(S,i,(0x10e3+2092-0x190e));ssSetInputPortDirectFeedThrough(S,i,(0x182c+3465-0x25b4));ssSetInputPortRequiredContiguous(S,i,(0x20f5+892-0x2470));}ssSetNumSampleTimes(S,(0x426+8072-0x23ad));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x2175+1337-0x26ae));ssSetNumNonsampledZCs(S,(0x2f5+4081-0x12e6));for(i=(0x2251+445-0x240e);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xeba+5420-0x23e6));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);
}static void mdlInitializeSampleTimes(SimStruct*S){
if(mxGetPr(z3832b85a32)[(0x168d+675-0x1930)]==-1.0){ssSetSampleTime(S,(0xaf0+4951-0x1e47),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x711+6662-0x2117),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xa2a+1040-0xe3a),mxGetPr(z3832b85a32)[(0x1cbf+768-0x1fbf)]);ssSetOffsetTime(S,(0x8f2+3543-0x16c9),0.0);}
}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;uint16_T zf91d71c6d9=(int)mxGetN(za9d8fb6bcf);real_T z19c4ca5f82,start;uint32_T range;
if((int_T)mxGetPr(z702a26a5e9)[(0x88+252-0x184)]<(0x115f+4364-0x226b)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x26b+4311-0x1341)){z366b2f03bf=(0x242+822-0x578);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x147d+3010-0x203f)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x8b7+6112-0x2097)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x3eb+7425-0x20eb)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x2c1+9315-0x2625))|((z366b2f03bf&(0xb75+349-0xbd3))<<(0xa96+3542-0x1864)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x1d4+2716-0xc6e)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0xd2+2682-0xb2c),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);int_T i;volatile uint32_T*za42cf7dd4a;real_T*zc7fdaf6331;
uint_T output,z718c4c15f4,z4e3026977c;int_T z0c3eef007f;za42cf7dd4a=(void*)base;

z0c3eef007f=mxGetN(za9d8fb6bcf);z718c4c15f4=(0x5e9+5807-0x1c98)|(za42cf7dd4a[(0xf92+4576-0x2171)]&32896);for(i=(0xc05+4890-0x1f1f);i<z0c3eef007f;i++){z4e3026977c=(uint16_T)mxGetPr(za9d8fb6bcf)[i]-(0x127c+3047-0x1e62);zc7fdaf6331=(real_T*)ssGetInputPortRealSignal(S,i);if(zc7fdaf6331[(0xca+3158-0xd20)]>=THRESHOLD){if((z4e3026977c<=(0x11b4+1505-0x1792))&&(za42cf7dd4a[(0x27c+1385-0x7e4)]&(0x1006+5722-0x25e0))){z718c4c15f4|=(0x6da+4172-0x16a6);
z718c4c15f4|=((0x1d68+1912-0x24df)<<z4e3026977c);
}else if(za42cf7dd4a[(0x595+556-0x7c0)]&32768){z718c4c15f4|=32768;
z718c4c15f4|=(0xa6f+3284-0x1742)<<(z4e3026977c+(0x1b4b+241-0x1c38));
}}}za42cf7dd4a[(0xe13+3304-0x1afa)]=z718c4c15f4;
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

