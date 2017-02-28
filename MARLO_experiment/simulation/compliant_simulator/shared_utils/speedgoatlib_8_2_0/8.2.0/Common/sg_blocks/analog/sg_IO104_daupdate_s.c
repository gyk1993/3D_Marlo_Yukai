/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x2d5+6741-0x1d28)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO104_daupdate_s
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
#define z29146a1837 (0x1cdb+6111-0x2405)
#define zab7e64468b 12658
#define zdf24515981          ((0xefb+3877-0x1e1c))
#define za8bff65d14              ssGetSFcnParam(S,(0xe07+609-0x1068))
#define z04bce731b0             ssGetSFcnParam(S,(0x100b+1522-0x15fc))
#define z3832b85a32           ssGetSFcnParam(S,(0x13b6+4406-0x24ea))
#define z702a26a5e9                ssGetSFcnParam(S,(0xaff+2608-0x152c))
#define z2e6483d505              ((0x5c+9767-0x2681))
#define z6a0da049de         ((0x7+4943-0x1356))
#define zc2f3e0cbc0        ((0x128+7215-0x1d56))
#define zc5ce4cb81a              ((0x78+1158-0x4ee))
#define z8caad2a8e6              ((0xea5+2062-0x16b3))
#define z5bfe7a2613            ((0xc8c+2766-0x1752))
#define z2b17e2ee3b              ((0x1951+429-0x1afe))
static char_T zea4cd01646[(0x160d+4162-0x254f)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x12dd+139-0x1368));ssSetNumDiscStates(S,(0x12d7+190-0x1395));if(!(boolean_T)mxGetPr(z04bce731b0)[(0x186f+1356-0x1dbb)]){ssSetNumOutputPorts(S,(0x5da+3571-0x13cd));}else{ssSetNumOutputPorts(S,(0x18e1+1933-0x206d));ssSetOutputPortWidth(S,(0x1132+2833-0x1c43),(0xbc+9653-0x2670));ssSetOutputPortDataType(S,(0x144a+31-0x1469),SS_BOOLEAN);}if(!(boolean_T)mxGetPr(za8bff65d14)[(0x13db+783-0x16ea)]){ssSetNumInputPorts(S,(0x1de8+761-0x20e1));}else{ssSetNumInputPorts(S,(0x141b+1944-0x1bb2));ssSetInputPortDirectFeedThrough(S,(0xb5c+3465-0x18e5),(0xc32+1126-0x1097));ssSetInputPortWidth(S,(0xd0a+589-0xf57),(0x1ab1+937-0x1e59));ssSetInputPortDataType(S,(0x26f+2451-0xc02),SS_BOOLEAN);ssSetInputPortRequiredContiguous(S,(0x871+6838-0x2327),(0x9e4+6309-0x2288));}ssSetNumSampleTimes(S,(0x2b0+1005-0x69c));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x86f+5236-0x1ce3));ssSetNumNonsampledZCs(S,(0x11c+2125-0x969));for(i=(0x12d+7223-0x1d64);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1b80+1249-0x2061));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x58+8158-0x2036)]==-1.0){ssSetSampleTime(S,(0x30+7494-0x1d76),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x4b9+5909-0x1bce),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x21c9+1290-0x26d3),mxGetPr(z3832b85a32)[(0x14b6+4221-0x2533)]);ssSetOffsetTime(S,(0x17b3+1188-0x1c57),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T range,out;uint16_T z4e3026977c;if((int_T)mxGetPr(z702a26a5e9)[(0x149d+465-0x166e)]<(0x1192+3381-0x1ec7)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x6b2+7958-0x25c7)){z366b2f03bf=(0x179c+3901-0x26d9);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x8fc+6468-0x2240)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x1c8f+996-0x2073)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xe63+4404-0x1f96)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x699+857-0x8f3))|((z366b2f03bf&(0x21a+9564-0x2677))<<(0x36a+8973-0x266f)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x19e3+1960-0x2189)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0xcc6+836-0xf8a),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;boolean_T*z0daf90e5e1;boolean_T enabled=true;if((int)mxGetPr(za8bff65d14)[(0x1386+3412-0x20da)]){z0daf90e5e1=(boolean_T*)ssGetInputPortSignal(S,(0x11d1+3922-0x2123));enabled=z0daf90e5e1[(0xb3b+1980-0x12f7)];}if((int)mxGetPr(z04bce731b0)[(0xbaf+477-0xd8c)]){z0daf90e5e1=(boolean_T*)ssGetOutputPortSignal(S,(0x7c1+4299-0x188c));z0daf90e5e1[(0xb4d+6748-0x25a9)]=enabled;}za42cf7dd4a=(void*)base;if(enabled){za42cf7dd4a[(0xae8+5175-0x1f1f)]=za42cf7dd4a[(0x17cf+3499-0x257a)]|1048576;}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

