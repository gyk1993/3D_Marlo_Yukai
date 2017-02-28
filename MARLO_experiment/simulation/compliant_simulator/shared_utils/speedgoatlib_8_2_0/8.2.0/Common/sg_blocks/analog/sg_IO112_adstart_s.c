/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x11dc+4233-0x2263)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO112_adstart_s
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
#define z694756a014 (0x2544+4230-0x2515)
#define zea87e0ba83 36950
#define z29146a1837 (0x1197+9125-0x2487)
#define zab7e64468b 13361
#define zdf24515981          ((0x601+5102-0x19eb))
#define za8bff65d14              ssGetSFcnParam(S,(0x1494+4703-0x26f3))
#define z04bce731b0             ssGetSFcnParam(S,(0x12c+9276-0x2567))
#define z3832b85a32           ssGetSFcnParam(S,(0x9b6+6489-0x230d))
#define z702a26a5e9                ssGetSFcnParam(S,(0x143a+1871-0x1b86))
#define z2e6483d505              ((0xdf7+247-0xeec))
#define z6a0da049de         ((0x1bc1+810-0x1eeb))
#define zc2f3e0cbc0        ((0xbeb+5764-0x226e))
#define zc5ce4cb81a              ((0x1622+1093-0x1a57))
#define z8caad2a8e6              ((0x1c9f+33-0x1cc0))
#define z5bfe7a2613            ((0x14f+6454-0x1a7d))
#define z2b17e2ee3b              ((0x9cc+5659-0x1fe7))
static char_T zea4cd01646[(0x341+438-0x3f7)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x44b+1555-0xa5e));ssSetNumDiscStates(S,(0x1047+1660-0x16c3));if(!(boolean_T)mxGetPr(z04bce731b0)[(0x857+6305-0x20f8)]){ssSetNumOutputPorts(S,(0x932+988-0xd0e));}else{ssSetNumOutputPorts(S,(0xf38+5207-0x238e));ssSetOutputPortWidth(S,(0x8fd+3996-0x1899),(0x1b1+7940-0x20b4));ssSetOutputPortDataType(S,(0xb85+715-0xe50),SS_BOOLEAN);}if(!(boolean_T)mxGetPr(za8bff65d14)[(0x1ddc+410-0x1f76)]){ssSetNumInputPorts(S,(0x55b+5597-0x1b38));}else{ssSetNumInputPorts(S,(0x1383+2832-0x1e92));ssSetInputPortDirectFeedThrough(S,(0x287+5333-0x175c),(0x15d+5532-0x16f8));ssSetInputPortWidth(S,(0x1ce9+1750-0x23bf),(0x1c2+6509-0x1b2e));ssSetInputPortDataType(S,(0xa83+5671-0x20aa),SS_BOOLEAN);ssSetInputPortRequiredContiguous(S,(0xfb9+1026-0x13bb),(0xe7c+3981-0x1e08));}ssSetNumSampleTimes(S,(0x12c+3032-0xd03));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xe8+7626-0x1eb2));ssSetNumNonsampledZCs(S,(0x1ed3+593-0x2124));for(i=(0x53f+2373-0xe84);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xec1+400-0x1051));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x226+5298-0x16d8)]==-1.0){ssSetSampleTime(S,(0x899+5909-0x1fae),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x16e0+3442-0x2452),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x343+8934-0x2629),mxGetPr(z3832b85a32)[(0xdc2+6411-0x26cd)]);ssSetOffsetTime(S,(0x5e1+4398-0x170f),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T range,out;uint16_T z4e3026977c;if((int_T)mxGetPr(z702a26a5e9)[(0x621+249-0x71a)]<(0x118c+4622-0x239a)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xf44+166-0xfe9)){z366b2f03bf=(0xee7+2701-0x1974);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x11cb+2602-0x1bf5)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x2a1+4994-0x1623)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x360+8121-0x2318)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x35f+5970-0x19b2))|((z366b2f03bf&(0x611+3436-0x127e))<<(0xadd+3036-0x16b1)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x594+4663-0x17c9)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x3c9+6626-0x1d2b),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;boolean_T*z0daf90e5e1;boolean_T enabled=true;
if((int)mxGetPr(za8bff65d14)[(0xaf8+1728-0x11b8)]){z0daf90e5e1=(boolean_T*)ssGetInputPortSignal(S,(0xdf6+3905-0x1d37));enabled=z0daf90e5e1[(0xcf9+6301-0x2596)];}if((int)mxGetPr(z04bce731b0)[(0x1281+1089-0x16c2)]){z0daf90e5e1=(boolean_T*)ssGetOutputPortSignal(S,(0xae4+4849-0x1dd5));z0daf90e5e1[(0x659+217-0x732)]=enabled;}za42cf7dd4a=(void*)base;if(enabled){za42cf7dd4a[(0x1894+1435-0x1e2f)]=za42cf7dd4a[(0xec6+1585-0x14f7)]|(0x1f18+2273-0x17f9);}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

