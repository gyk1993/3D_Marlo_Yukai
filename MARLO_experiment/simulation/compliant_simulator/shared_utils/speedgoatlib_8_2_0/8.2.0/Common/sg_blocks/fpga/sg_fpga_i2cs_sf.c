/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x727+4953-0x1a7e)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_i2cs_sf
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
#define zdf24515981        ((0x193+1465-0x747))
#define z533b11d03f         ssGetSFcnParam(S, (0x934+3704-0x17ac)) 
#define za9d8fb6bcf           ssGetSFcnParam(S, (0x154+7480-0x1e8b)) 
#define z4bd6be73a3           ssGetSFcnParam(S, (0x550+3785-0x1417))
#define z3832b85a32         ssGetSFcnParam(S, (0xa92+5382-0x1f95))
#define z702a26a5e9              ssGetSFcnParam(S, (0x207+1494-0x7d9))
#define z2e6483d505              ((0xa67+3198-0x16e4))
#define zc5ce4cb81a              ((0x387+3203-0x100a))
#define z2b17e2ee3b              ((0x3ea+4743-0x1671))
#define z6a0da049de         ((0x114d+1478-0x1713))
#define zceae5ef027                (524288)
static char_T zea4cd01646[(0xe6a+3403-0x1ab5)];struct z4ffeb08593{uint32_T z4da0d16710;uint32_T clear;uint32_T z553991aa78;uint32_T z039626e71b[(0xd6f+6528-0x26cf)];uint32_T z7515281f6c[(0x1791+2454-0x2107)];uint32_T zd6e550175f[(0x4c5+5706-0x1aef)];uint32_T z2678040317[(0x1a7d+2188-0x22e9)];};static void mdlInitializeSizes(SimStruct*S){uint32_T i,za0df33019b;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x100d+3314-0x1cff));ssSetNumDiscStates(S,(0x67f+2216-0xf27));ssSetNumOutputPorts(S,(0xb0c+35-0xb2f));ssSetNumInputPorts(S,(0x412+4875-0x171d));ssSetNumSampleTimes(S,(0x5c5+5030-0x196a));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xec5+4529-0x2076));ssSetNumNonsampledZCs(S,(0x218+1792-0x918));for(i=(0x798+1242-0xc72);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1303+83-0x1356));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0xbb2+2938-0x172c)]==-1.0){ssSetSampleTime(S,(0x4b8+6093-0x1c85),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1287+759-0x157e),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xac7+3746-0x1969),mxGetPr(z3832b85a32)[(0x554+4174-0x15a2)]);ssSetOffsetTime(S,(0x275+5298-0x1727),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i;uint8_T z16ba527520[(0xc1f+94-0xc69)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61,z4e3026977c,z4da0d16710;volatile struct z4ffeb08593*z77b62f8983;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x420+8341-0x24b5)];z6f813cde47=z05b56d9d51=(0x26b0+5095-0x23c2);switch(z78caf1ba61){case(0x19b7+927-0x1c29):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");za4a2434e08=z182d03571c=17232;break;case(0xa68+1768-0x1022):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");za4a2434e08=z182d03571c=17239;break;case(0x1760+1158-0x1ab7):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");za4a2434e08=z182d03571c=16979;break;case(0x724+4922-0x192e):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");za4a2434e08=z182d03571c=(0x1749+664-0x14dd);break;case(0x1697+2707-0x1ff3):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");za4a2434e08=z182d03571c=21069;break;case(0xe5d+3430-0x1a8b):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");za4a2434e08=z182d03571c=16971;break;case(0x2a4+4078-0x1159):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");za4a2434e08=z182d03571c=17235;break;case(0x1a24+267-0x19f5):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");za4a2434e08=z182d03571c=8196;break;case(0x1185+5364-0x2538):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;}if(mxGetN(z702a26a5e9)==(0x7f0+3578-0x15e9)){z366b2f03bf=(0x992+7166-0x2590);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xd3c+2030-0x152a)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x61d+4947-0x1970)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x618+4265-0x16c0)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0xb9a+3214-0x1826)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x81a+178-0x8ca)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x1fd9+287-0x20f6)]);z77b62f8983=(struct z4ffeb08593*)(zeccbadd9b3.VirtAddress[(0x2d0+5870-0x19bc)]+zceae5ef027);if(!xpceIsModelInit()){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[(0xfac+4507-0x2147)]-(0x1b4a+2765-0x2616);z77b62f8983->z039626e71b[z4e3026977c]=(uint32_T)mxGetPr(z4bd6be73a3)[(0x10e1+2876-0x1c1d)];
z4da0d16710=z77b62f8983->z4da0d16710;z4da0d16710|=((0x35c+2041-0xb54)<<z4e3026977c);z77b62f8983->z4da0d16710=z4da0d16710;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile struct z4ffeb08593*z77b62f8983=(struct z4ffeb08593*)(base+zceae5ef027);if(!xpceIsModelInit())
{z77b62f8983->z4da0d16710=(0xa20+524-0xc2c);}
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif
