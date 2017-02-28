/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x4a5+2309-0xda8)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_adreadfpga_sf
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
#define zdf24515981              ((0x1c03+1090-0x2043))
#define z3832b85a32               ssGetSFcnParam(S,(0x417+2320-0xd27))
#define z702a26a5e9                    ssGetSFcnParam(S,(0x1d3f+1545-0x2347))
#define z2e6483d505              ((0x3d4+2463-0xd71))
#define z7e2eeaa57c          ((0x19e6+2481-0x2397))
#define z6a0da049de         ((0x357+4387-0x1479))
#define zc5ce4cb81a              ((0xe90+6265-0x26f9))
#define z2b17e2ee3b              ((0x589+4171-0x15d4))
static char_T zea4cd01646[(0xf29+1397-0x139e)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xf0d+5943-0x2644));ssSetNumDiscStates(S,(0xb2a+818-0xe5c));ssSetNumOutputPorts(S,(0x1e29+482-0x2009));for(i=(0xac9+435-0xc7c);i<(0x4a3+5236-0x1915);i++){ssSetOutputPortDataType(S,i,SS_INT16);ssSetOutputPortWidth(S,i,(0x394+5935-0x1ac2));}ssSetNumInputPorts(S,(0x3b5+5419-0x18e0));ssSetNumSampleTimes(S,(0x2d1+7017-0x1e39));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x77d+407-0x914));ssSetNumNonsampledZCs(S,(0x339+5196-0x1785));for(i=(0x14a8+2749-0x1f65);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x818+7006-0x2376));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0xc87+4813-0x1f54)]==-1.0){ssSetSampleTime(S,(0x348+7376-0x2018),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x2c9+6254-0x1b37),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x1674+2778-0x214e),mxGetPr(z3832b85a32)[(0x247+6715-0x1c82)]);ssSetOffsetTime(S,(0x18c2+1781-0x1fb7),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z7be9105675,z4e3026977c;real_T scale;uint8_T z16ba527520[(0x6af+680-0x943)];uint16_T z6f813cde47,za4a2434e08;strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");z6f813cde47=5845;za4a2434e08=19520;if((int_T)mxGetPr(z702a26a5e9)[(0x505+2383-0xe54)]<(0x12f3+2856-0x1e1b)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x1c3+6042-0x195c)){z366b2f03bf=(0xa47+4197-0x1aac);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1ea4+454-0x206a)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0xf38+3108-0x1b5c)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xb62+4517-0x1d06)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x1008+4465-0x207a))|((z366b2f03bf&(0x454+2332-0xc71))<<(0x316+4567-0x14e5)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x18a5+2148-0x2107)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T z52754d10b7;uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;uint16_T*y;za42cf7dd4a=(void*)base;y=ssGetOutputPortSignal(S,(0x5c9+2509-0xf96));z52754d10b7=(uint32_T)(za42cf7dd4a[9584]);
y[(0xc3+6953-0x1bec)]=(uint16_T)z52754d10b7;y=ssGetOutputPortSignal(S,(0xf4d+502-0x1142));z52754d10b7=(uint32_T)(za42cf7dd4a[9585]);y[(0x10a5+2824-0x1bad)]=(uint16_T)z52754d10b7;
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

