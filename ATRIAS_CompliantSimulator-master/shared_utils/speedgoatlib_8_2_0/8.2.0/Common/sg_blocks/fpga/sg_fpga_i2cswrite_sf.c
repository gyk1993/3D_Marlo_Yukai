/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1410+1739-0x1ad9)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_i2cswrite_sf
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
#define zdf24515981        ((0x4d5+6442-0x1dfa))
#define z533b11d03f         ssGetSFcnParam(S, (0x1b5a+2450-0x24ec)) 
#define za9d8fb6bcf           ssGetSFcnParam(S, (0x19c6+2691-0x2448)) 
#define zd7a15617ca         ssGetSFcnParam(S, (0x3e6+4043-0x13af))
#define z3832b85a32         ssGetSFcnParam(S, (0x1318+1133-0x1782))
#define z702a26a5e9              ssGetSFcnParam(S, (0x16c0+356-0x1820))
#define z2e6483d505              ((0xa97+1929-0x121f))
#define zc5ce4cb81a              ((0x1877+1870-0x1fc5))
#define z2b17e2ee3b              ((0x163+657-0x3f4))
#define z6a0da049de         ((0x2465+318-0x25a3))
#define zceae5ef027                (524288)
static char_T zea4cd01646[(0x7d1+7847-0x2578)];struct z4ffeb08593{uint32_T z4da0d16710;uint32_T clear;uint32_T z553991aa78;uint32_T z039626e71b[(0x86f+2839-0x1366)];uint32_T z7515281f6c[(0x9d+5575-0x1644)];uint32_T zd6e550175f[(0x1592+756-0x1866)];uint32_T z2678040317[(0x92+4913-0x13a3)];};static void mdlInitializeSizes(SimStruct*S){uint32_T i,za0df33019b;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x3dc+4266-0x1486));ssSetNumDiscStates(S,(0x91+8107-0x203c));ssSetNumOutputPorts(S,(0x7b9+6460-0x20f5));ssSetNumInputPorts(S,(0x126f+4555-0x2439));ssSetInputPortWidth(S,(0x713+7450-0x242d),mxGetN(zd7a15617ca));ssSetInputPortDirectFeedThrough(S,(0x4b7+1930-0xc41),(0x570+6861-0x203c));ssSetInputPortRequiredContiguous(S,(0x597+6473-0x1ee0),(0xff8+2-0xff9));ssSetNumSampleTimes(S,(0x839+1136-0xca8));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x65f+2351-0xf8e));ssSetNumNonsampledZCs(S,(0x244+5573-0x1809));for(i=(0x1ac4+2511-0x2493);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1c87+2078-0x24a5));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x2c6+594-0x518)]==-1.0){ssSetSampleTime(S,(0x4a3+1856-0xbe3),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1452+748-0x173e),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x1739+2485-0x20ee),mxGetPr(z3832b85a32)[(0x18ca+1321-0x1df3)]);ssSetOffsetTime(S,(0x483+5888-0x1b83),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i;uint8_T z16ba527520[(0x157+8340-0x21d7)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x46+9615-0x25d5)];z6f813cde47=z05b56d9d51=5845;switch(z78caf1ba61){case(0x1ee3+1506-0x2398):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");za4a2434e08=z182d03571c=17232;break;case(0xc76+5823-0x2207):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");za4a2434e08=z182d03571c=17239;break;case(0x1533+171-0x14af):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");za4a2434e08=z182d03571c=16979;break;case(0xc13+160-0xb83):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");za4a2434e08=z182d03571c=(0x19f8+498-0x16e6);break;case(0xb38+2711-0x1498):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");za4a2434e08=z182d03571c=21069;break;case(0x575+4256-0x14dd):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");za4a2434e08=z182d03571c=16971;break;case(0x1066+5913-0x2646):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");za4a2434e08=z182d03571c=17235;break;case(0xd47+3592-0x1a15):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");za4a2434e08=z182d03571c=8196;break;case(0x1690+2769-0x2020):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;}if(mxGetN(z702a26a5e9)==(0x232+7845-0x20d6)){z366b2f03bf=(0xbf0+1142-0x1066);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x7a0+7559-0x2527)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x1bcb+2271-0x24aa)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x11b3+2087-0x19d9)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0xa44+5701-0x2087)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0xd5d+3015-0x1922)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x1c6+9521-0x26f5)]);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint32_T i,z4e3026977c;real_T*y;volatile struct z4ffeb08593*z77b62f8983=(struct z4ffeb08593*)(base+zceae5ef027);y=(real_T*)ssGetInputPortSignal(S,(0x127d+4110-0x228b));for(i=(0x48a+7193-0x20a3);i<mxGetN(zd7a15617ca);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[(0xc1f+4925-0x1f5c)]-(0x205+7226-0x1e3e);
z77b62f8983->z7515281f6c[z4e3026977c]=(uint32_T)mxGetPr(zd7a15617ca)[i]-(0x7a6+5598-0x1d83);
z77b62f8983->zd6e550175f[z4e3026977c]=(uint32_T)y[i];
z77b62f8983->z553991aa78=((0x21f+6743-0x1c75)<<z4e3026977c);z77b62f8983->z553991aa78=(0xdcb+6308-0x266f);}
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
