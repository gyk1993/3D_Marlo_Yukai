/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xfe3+3300-0x1cc5)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO104_adstart_s
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
#define z694756a014 4277
#define zea87e0ba83 36950
#define z29146a1837 (0x13b6+4445-0x145e)
#define zab7e64468b 12658
#define zdf24515981          ((0x53b+5777-0x1bc8))
#define za8bff65d14              ssGetSFcnParam(S,(0xa1f+3971-0x19a2))
#define z04bce731b0             ssGetSFcnParam(S,(0x1489+575-0x16c7))
#define z3832b85a32           ssGetSFcnParam(S,(0x1359+2117-0x1b9c))
#define z702a26a5e9                ssGetSFcnParam(S,(0x46+2717-0xae0))
#define z2e6483d505              ((0x95d+7034-0x24d5))
#define z6a0da049de         ((0x1125+3865-0x203e))
#define zc2f3e0cbc0        ((0xb44+3081-0x174c))
#define zc5ce4cb81a              ((0x783+5555-0x1d26))
#define z8caad2a8e6              ((0x192b+528-0x1b3b))
#define z5bfe7a2613            ((0xc6a+1559-0x1279))
#define z2b17e2ee3b              ((0x2059+207-0x2128))
static char_T zea4cd01646[(0xa4c+1262-0xe3a)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x2348+557-0x2575));ssSetNumDiscStates(S,(0x210a+540-0x2326));if(!(boolean_T)mxGetPr(z04bce731b0)[(0x253d+139-0x25c8)]){ssSetNumOutputPorts(S,(0x8dd+744-0xbc5));}else{ssSetNumOutputPorts(S,(0x58b+2348-0xeb6));ssSetOutputPortWidth(S,(0xb88+4271-0x1c37),(0xbe9+2721-0x1689));ssSetOutputPortDataType(S,(0x227f+172-0x232b),SS_BOOLEAN);}if(!(boolean_T)mxGetPr(za8bff65d14)[(0x11e6+567-0x141d)]){ssSetNumInputPorts(S,(0x1134+1146-0x15ae));}else{ssSetNumInputPorts(S,(0xe29+1438-0x13c6));ssSetInputPortDirectFeedThrough(S,(0xec9+5551-0x2478),(0xf06+5021-0x22a2));ssSetInputPortWidth(S,(0xc81+3634-0x1ab3),(0x1475+509-0x1671));ssSetInputPortDataType(S,(0x937+6091-0x2102),SS_BOOLEAN);ssSetInputPortRequiredContiguous(S,(0x170d+3007-0x22cc),(0x15f3+1897-0x1d5b));}ssSetNumSampleTimes(S,(0x10a5+715-0x136f));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xd7+6441-0x1a00));ssSetNumNonsampledZCs(S,(0xb66+3258-0x1820));for(i=(0xa54+6219-0x229f);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xbff+6512-0x256f));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x941+2582-0x1357)]==-1.0){ssSetSampleTime(S,(0x1624+3608-0x243c),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x71+7360-0x1d31),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x58+6913-0x1b59),mxGetPr(z3832b85a32)[(0x52c+3301-0x1211)]);ssSetOffsetTime(S,(0xc95+5130-0x209f),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T range,out;uint16_T z4e3026977c;if((int_T)mxGetPr(z702a26a5e9)[(0x7e9+3914-0x1733)]<(0xc64+5687-0x229b)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x6cd+5224-0x1b34)){z366b2f03bf=(0x1e76+1660-0x24f2);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x189+8064-0x2109)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0xd21+6059-0x24cc)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x6d+1306-0x586)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0xce1+6431-0x2501))|((z366b2f03bf&(0xb4a+3668-0x189f))<<(0xc4b+6134-0x2439)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x100b+1736-0x16d1)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x1328+1638-0x190e),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;boolean_T*z0daf90e5e1;boolean_T enabled=true;if((int)mxGetPr(za8bff65d14)[(0x2161+333-0x22ae)]){z0daf90e5e1=(boolean_T*)ssGetInputPortSignal(S,(0x15c1+3532-0x238d));enabled=z0daf90e5e1[(0x1599+1838-0x1cc7)];}if((int)mxGetPr(z04bce731b0)[(0xf2c+882-0x129e)]){z0daf90e5e1=(boolean_T*)ssGetOutputPortSignal(S,(0x5bb+4413-0x16f8));z0daf90e5e1[(0x8ef+6687-0x230e)]=enabled;}za42cf7dd4a=(void*)base;if(enabled){za42cf7dd4a[(0x320+5868-0x1a0c)]=za42cf7dd4a[(0x1448+3819-0x2333)]|(0xc1a+6028-0x22a6);}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

