/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1984+1244-0x1e5e)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO206_read_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x32\x30\x36"
#define z694756a014 (0x2043+6316-0x2457)
#define zea87e0ba83 (0x84c+8428-0x26e0)
#define zdf24515981          ((0x12f5+4563-0x24c5))
#define z2cc9a52544            ssGetSFcnParam(S,(0x449+6834-0x1efb))
#define z3832b85a32           ssGetSFcnParam(S,(0xad2+1491-0x10a4))
#define z702a26a5e9                ssGetSFcnParam(S,(0x2bc+6187-0x1ae5))
#define z2e6483d505              ((0x83b+7132-0x2415))
#define z6a0da049de         ((0x80d+6084-0x1fd1))
#define zc2f3e0cbc0        ((0x50a+8273-0x255a))
#define zc5ce4cb81a              ((0x1829+2009-0x2002))
#define z2b17e2ee3b              ((0x128c+2885-0x1dd1))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0xbfd+6316-0x23a9)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x15f6+4265-0x269f));ssSetNumDiscStates(S,(0x281+7756-0x20cd));ssSetNumInputPorts(S,(0x178a+2069-0x1f9f));switch((uint8_T)mxGetPr(z2cc9a52544)[(0x18d6+2005-0x20ab)]){case(0x880+3690-0x16e9):ssSetNumOutputPorts(S,(0xc2d+1669-0x1292));for(i=(0x73+3348-0xd87);i<(0x87+5320-0x152f);i++){ssSetOutputPortWidth(S,i,(0xcc2+1077-0x10f6));}break;case(0x10b3+4809-0x237a):ssSetNumOutputPorts(S,(0x146+3264-0xde6));for(i=(0xbc4+980-0xf98);i<(0x141f+2655-0x1e5e);i++){ssSetOutputPortWidth(S,i,(0x20f6+435-0x22a8));ssSetOutputPortDataType(S,i,SS_BOOLEAN);}break;case(0x161+2067-0x971):ssSetNumOutputPorts(S,(0xd61+3779-0x1c23));ssSetOutputPortWidth(S,(0x1ccd+2264-0x25a5),(0x1a07+3038-0x25c5));break;case(0x63+6873-0x1b38):ssSetNumOutputPorts(S,(0xce8+6576-0x2697));ssSetOutputPortWidth(S,(0x1b38+1923-0x22bb),(0x45c+4874-0x1746));ssSetOutputPortDataType(S,(0x16a+8795-0x23c5),SS_BOOLEAN);break;case(0xa32+5538-0x1fcf):ssSetNumOutputPorts(S,(0x12ea+4312-0x23c1));ssSetOutputPortWidth(S,(0x1190+108-0x11fc),(0x15da+2368-0x1f19));ssSetOutputPortDataType(S,(0x728+6517-0x209d),SS_UINT32);break;}ssSetNumSampleTimes(S,(0xb9b+2037-0x138f));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x199c+2007-0x2173));ssSetNumNonsampledZCs(S,(0xa26+2907-0x1581));for(i=(0xd25+506-0xf1f);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xe2c+1310-0x134a));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x408+1330-0x93a)]==-1.0){ssSetSampleTime(S,(0x763+3599-0x1572),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xdc7+5374-0x22c5),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x103d+645-0x12c2),mxGetPr(z3832b85a32)[(0x41+5601-0x1622)]);ssSetOffsetTime(S,(0x859+6842-0x2313),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zef529fae4a;void*ze2370ae9b9;volatile uint32_T*z3e5b8e05d8;void*zdfcb1da404;void*zf2db5722bf;volatile uint32_T*z27fd94ac66;uint_T i;uint32_T out;if((int_T)mxGetPr(z702a26a5e9)[(0xe1f+4072-0x1e07)]<(0x1515+3805-0x23f2)){
if(rl32eGetPCIInfo((uint16_T)z694756a014,(uint16_T)zea87e0ba83,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{int_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x6ff+847-0xa4d)){z366b2f03bf=(0x1a37+702-0x1cf5);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x16e2+333-0x182f)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x47b+5456-0x19cb)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x154c+1021-0x1948)];}
if(rl32eGetPCIInfoAtSlot((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(z441f9e6d1b&(0x17df+2455-0x2077))|((z366b2f03bf&(0x1fa0+2002-0x2673))<<(0xc8f+3354-0x19a1)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zef529fae4a=(void*)zeccbadd9b3.BaseAddress[(0x1ee2+1009-0x22d3)];ze2370ae9b9=rl32eGetDevicePtr(zef529fae4a,(0x1a9d+1910-0x2193),RT_PG_USERREADWRITE);z3e5b8e05d8=(volatile uint32_T*)ze2370ae9b9;zdfcb1da404=(void*)zeccbadd9b3.BaseAddress[(0x350+5767-0x19d5)];zf2db5722bf=rl32eGetDevicePtr(zdfcb1da404,(0x105f+5552-0x25ef),RT_PG_USERREADWRITE);z27fd94ac66=(volatile uint32_T*)zf2db5722bf;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)z27fd94ac66);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*z27fd94ac66;uint32_T i,input;real_T*y1;boolean_T*y2;uint32_T*z671e76e748;z27fd94ac66=(void*)base;input=z27fd94ac66[(0x155a+3766-0x2410)];switch((uint8_T)mxGetPr(z2cc9a52544)[(0x74f+1569-0xd70)]){case(0x30a+6862-0x1dd7):for(i=(0x949+2026-0x1133);i<(0x881+3156-0x14b5);i++){y1=(real_T*)ssGetOutputPortSignal(S,i);y1[(0x967+4202-0x19d1)]=(real_T)((input>>i)&(0xfa+9668-0x26bd));}break;case(0x794+1009-0xb83):for(i=(0xbac+1242-0x1086);i<(0x11c0+2931-0x1d13);i++){y2=(boolean_T*)ssGetOutputPortSignal(S,i);y2[(0xfc2+4422-0x2108)]=(boolean_T)((input>>i)&(0x917+2427-0x1291));}break;case(0x37d+2547-0xd6d):y1=(real_T*)ssGetOutputPortSignal(S,(0x1aa0+1995-0x226b));for(i=(0x1230+4419-0x2373);i<(0xf78+2541-0x1945);i++){y1[i]=(real_T)((input>>i)&(0xb20+3732-0x19b3));}break;case(0x16ac+418-0x184a):y2=(boolean_T*)ssGetOutputPortSignal(S,(0x1e34+1130-0x229e));for(i=(0x4ed+251-0x5e8);i<(0x1971+3273-0x261a);i++){y2[i]=(boolean_T)((input>>i)&(0x456+3468-0x11e1));}break;case(0x1322+977-0x16ee):z671e76e748=(uint32_T*)ssGetOutputPortSignal(S,(0xa58+5851-0x2133));z671e76e748[(0x5b6+7327-0x2255)]=(uint32_T)input;break;}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

