/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xf71+5745-0x25e0)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO106_adstart_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x30\x36"
#define z694756a014 (0x16d9+970-0x9ee)
#define zea87e0ba83 36950
#define z29146a1837 (0x1148+6918-0x1b99)
#define zab7e64468b 12545
#define zdf24515981          ((0xf28+4993-0x22a5))
#define za8bff65d14              ssGetSFcnParam(S,(0x86b+7254-0x24c1))
#define z04bce731b0             ssGetSFcnParam(S,(0x198+6614-0x1b6d))
#define z3832b85a32           ssGetSFcnParam(S,(0x13ba+4655-0x25e7))
#define z702a26a5e9                ssGetSFcnParam(S,(0x3a1+5375-0x189d))
#define z2e6483d505              ((0x2167+1367-0x26bc))
#define z6a0da049de         ((0xc1a+3364-0x193e))
#define zc2f3e0cbc0        ((0x14a2+2000-0x1c71))
#define zc5ce4cb81a              ((0x14e4+408-0x166c))
#define z8caad2a8e6              ((0xa91+2992-0x1641))
#define z5bfe7a2613            ((0xc2a+1670-0x12a8))
#define z2b17e2ee3b              ((0x1f47+5-0x1f4c))
static char_T zea4cd01646[(0x1717+3844-0x251b)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x6f6+1770-0xde0));ssSetNumDiscStates(S,(0xd3f+6113-0x2520));if(!(boolean_T)mxGetPr(z04bce731b0)[(0x220+2146-0xa82)]){ssSetNumOutputPorts(S,(0x1750+2884-0x2294));}else{ssSetNumOutputPorts(S,(0x221+7368-0x1ee8));ssSetOutputPortWidth(S,(0x3a3+5329-0x1874),(0xb15+429-0xcc1));ssSetOutputPortDataType(S,(0x5f6+1439-0xb95),SS_BOOLEAN);}if(!(boolean_T)mxGetPr(za8bff65d14)[(0x1772+1674-0x1dfc)]){ssSetNumInputPorts(S,(0xc7f+2404-0x15e3));}else{ssSetNumInputPorts(S,(0x24f+9362-0x26e0));ssSetInputPortDirectFeedThrough(S,(0xe83+2350-0x17b1),(0x245+1452-0x7f0));ssSetInputPortWidth(S,(0x11b4+3011-0x1d77),(0x18fb+1442-0x1e9c));ssSetInputPortDataType(S,(0x289+5802-0x1933),SS_BOOLEAN);ssSetInputPortRequiredContiguous(S,(0xec6+1489-0x1497),(0x7a1+2110-0xfde));}ssSetNumSampleTimes(S,(0xca7+5354-0x2190));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xbff+6825-0x26a8));ssSetNumNonsampledZCs(S,(0xb12+4484-0x1c96));for(i=(0xa4c+2458-0x13e6);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xcff+971-0x10ca));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x5a+1793-0x75b)]==-1.0){ssSetSampleTime(S,(0xdb+7471-0x1e0a),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x187+5493-0x16fc),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x91a+4469-0x1a8f),mxGetPr(z3832b85a32)[(0x11a2+1301-0x16b7)]);ssSetOffsetTime(S,(0x33a+5790-0x19d8),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T range,out;uint16_T z4e3026977c;if((int_T)mxGetPr(z702a26a5e9)[(0x1bd+8615-0x2364)]<(0x13b+351-0x29a)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x11c+4849-0x140c)){z366b2f03bf=(0x68c+6665-0x2095);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xa+2368-0x94a)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x409+8155-0x23e4)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xc55+5404-0x2170)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x1ea8+673-0x204a))|((z366b2f03bf&(0x1de2+759-0x1fda))<<(0x67f+6541-0x2004)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0xba8+6348-0x2472)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x1f41+1771-0x25ac),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;boolean_T*z0daf90e5e1;boolean_T enabled=true;
if((int)mxGetPr(za8bff65d14)[(0x1d25+594-0x1f77)]){z0daf90e5e1=(boolean_T*)ssGetInputPortSignal(S,(0xb40+5171-0x1f73));enabled=z0daf90e5e1[(0x652+4621-0x185f)];}if((int)mxGetPr(z04bce731b0)[(0xc8b+4297-0x1d54)]){z0daf90e5e1=(boolean_T*)ssGetOutputPortSignal(S,(0xa4a+7175-0x2651));z0daf90e5e1[(0x163+1490-0x735)]=enabled;}za42cf7dd4a=(void*)base;if(enabled){za42cf7dd4a[(0x1cd4+588-0x1f20)]=za42cf7dd4a[(0xcb5+666-0xf4f)]|(0x1df8+3541-0x1bcd);}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

