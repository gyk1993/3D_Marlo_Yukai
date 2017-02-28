/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x7f9+6056-0x1f9f)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO204_read_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x32\x30\x34"
#define z694756a014 (0x1b3b+2344-0xfcb)
#define zea87e0ba83 (0x113b+3392-0x1bdc)
#define zdf24515981          ((0x9ff+3850-0x1905))
#define ze072c43310               ssGetSFcnParam(S,(0x15d+7538-0x1ecf))
#define z2cc9a52544            ssGetSFcnParam(S,(0x11f8+4572-0x23d3))
#define z3832b85a32           ssGetSFcnParam(S,(0x1a7c+1484-0x2046))
#define z702a26a5e9                ssGetSFcnParam(S,(0x32a+5421-0x1854))
#define z2e6483d505              ((0x1cfc+2089-0x2523))
#define z6a0da049de         ((0x740+817-0xa71))
#define zc2f3e0cbc0        ((0x7a4+6789-0x2228))
#define zc5ce4cb81a              ((0x1033+2596-0x1a57))
#define z2b17e2ee3b              ((0x9cb+3841-0x18cc))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0x516+3372-0x1142)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x214c+168-0x21f4));ssSetNumDiscStates(S,(0x10c+5392-0x161c));ssSetNumInputPorts(S,(0x13b4+2422-0x1d2a));switch((uint8_T)mxGetPr(z2cc9a52544)[(0x6a2+8162-0x2684)]){case(0x8ad+1129-0xd15):ssSetNumOutputPorts(S,(0x338+4945-0x1679));for(i=(0x1527+1663-0x1ba6);i<(0x1862+3341-0x255f);i++){ssSetOutputPortWidth(S,i,(0xa21+569-0xc59));}break;case(0x498+5858-0x1b78):ssSetNumOutputPorts(S,(0xbca+4595-0x1dad));for(i=(0xd3d+2541-0x172a);i<(0x12f6+1436-0x1882);i++){ssSetOutputPortWidth(S,i,(0x63b+1884-0xd96));ssSetOutputPortDataType(S,i,SS_BOOLEAN);}break;case(0x116a+4604-0x2363):ssSetNumOutputPorts(S,(0xb7+6220-0x1902));ssSetOutputPortWidth(S,(0x140c+3856-0x231c),(0x493+4458-0x15ed));break;case(0x211+2772-0xce1):ssSetNumOutputPorts(S,(0xa4f+376-0xbc6));ssSetOutputPortWidth(S,(0x8f1+6382-0x21df),(0x1493+3984-0x2413));ssSetOutputPortDataType(S,(0xcad+6593-0x266e),SS_BOOLEAN);break;case(0x51c+6650-0x1f11):ssSetNumOutputPorts(S,(0x403+2529-0xde3));ssSetOutputPortWidth(S,(0x1cc3+626-0x1f35),(0xfb9+4242-0x204a));ssSetOutputPortDataType(S,(0xe05+6132-0x25f9),SS_UINT16);break;}ssSetNumSampleTimes(S,(0xcbf+1212-0x117a));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x366+5376-0x1866));ssSetNumNonsampledZCs(S,(0xb1+9044-0x2405));for(i=(0x609+3750-0x14af);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x785+7667-0x2578));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x104d+4470-0x21c3)]==-1.0){ssSetSampleTime(S,(0x61c+3473-0x13ad),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1444+2825-0x1f4d),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xda8+1520-0x1398),mxGetPr(z3832b85a32)[(0x7f5+2745-0x12ae)]);ssSetOffsetTime(S,(0x117c+4076-0x2168),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zef529fae4a;void*ze2370ae9b9;volatile uint32_T*z3e5b8e05d8;void*zdfcb1da404;void*zf2db5722bf;volatile uint16_T*z27fd94ac66;uint_T i;uint32_T out;if((int_T)mxGetPr(z702a26a5e9)[(0x2ac+1361-0x7fd)]<(0xdaa+4301-0x1e77)){
if(rl32eGetPCIInfo((uint16_T)z694756a014,(uint16_T)zea87e0ba83,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{int_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x1385+3104-0x1fa4)){z366b2f03bf=(0xe53+2670-0x18c1);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x1b66+2679-0x25dd)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x15+182-0xcb)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x23a+1237-0x70e)];}
if(rl32eGetPCIInfoAtSlot((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(z441f9e6d1b&(0xae2+5780-0x2077))|((z366b2f03bf&(0x507+8874-0x26b2))<<(0x835+741-0xb12)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zef529fae4a=(void*)zeccbadd9b3.BaseAddress[(0x128d+2444-0x1c19)];ze2370ae9b9=rl32eGetDevicePtr(zef529fae4a,(0x10dc+4291-0x211f),RT_PG_USERREADWRITE);z3e5b8e05d8=(volatile uint32_T*)ze2370ae9b9;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)zeccbadd9b3.BaseAddress[(0x1baf+65-0x1bee)]);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint16_T base=(uint16_T)ssGetIWorkValue(S,z6a0da049de);volatile uint16_T*z27fd94ac66;uint16_T i,input;real_T*y1;boolean_T*y2;uint16_T*z671e76e748;
if((uint8_T)mxGetPr(ze072c43310)[(0x1296+412-0x1432)]){input=rl32eInpW(base+(0x542+1267-0xa34));}else{input=rl32eInpW(base+(0xafd+2885-0x1642));}input=((input&(0xe7a+959-0x113a))<<(0x75b+1953-0xef4))|((input&65280)>>(0x147c+2804-0x1f68));switch((uint8_T)mxGetPr(z2cc9a52544)[(0x224+8987-0x253f)]){case(0x173c+1215-0x1bfa):for(i=(0x506+5567-0x1ac5);i<(0x6a7+6257-0x1f08);i++){y1=(real_T*)ssGetOutputPortSignal(S,i);y1[(0x41a+2488-0xdd2)]=(real_T)((input>>i)&(0x8da+5160-0x1d01));}break;case(0xa0b+6180-0x222d):for(i=(0x190+7038-0x1d0e);i<(0xab0+5954-0x21e2);i++){y2=(boolean_T*)ssGetOutputPortSignal(S,i);y2[(0x1a95+1915-0x2210)]=(boolean_T)((input>>i)&(0xe4b+4129-0x1e6b));}break;case(0x3fa+3764-0x12ab):y1=(real_T*)ssGetOutputPortSignal(S,(0x1db7+1158-0x223d));for(i=(0xebd+3150-0x1b0b);i<(0x20bf+475-0x228a);i++){y1[i]=(real_T)((input>>i)&(0x1585+3185-0x21f5));}break;case(0x8b1+7271-0x2514):y2=(boolean_T*)ssGetOutputPortSignal(S,(0x1910+1390-0x1e7e));for(i=(0x387+2211-0xc2a);i<(0x7ea+487-0x9c1);i++){y2[i]=(boolean_T)((input>>i)&(0x1f82+618-0x21eb));}break;case(0x3b2+6810-0x1e47):z671e76e748=(uint16_T*)ssGetOutputPortSignal(S,(0x1659+1044-0x1a6d));z671e76e748[(0x4b7+5969-0x1c08)]=(uint16_T)input;break;}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

