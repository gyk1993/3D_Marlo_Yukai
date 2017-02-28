/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1b2+4643-0x13d3)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_inta_sf_a1
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
#include        "xpcPCFunctions.h"
#endif
#define zdf24515981              ((0x31a+6371-0x1bf7))
#define z533b11d03f               ssGetSFcnParam(S,(0x248+2533-0xc2d))
#define z1120e7330e                ssGetSFcnParam(S,(0x33c+4763-0x15d6))
#define z644559a0a7                   ssGetSFcnParam(S,(0x47f+8185-0x2476))
#define ze9153280f8                ssGetSFcnParam(S,(0x7b3+208-0x880))
#define z702a26a5e9                    ssGetSFcnParam(S,(0x972+768-0xc6e))
#define z3832b85a32               ssGetSFcnParam(S,(0x605+6476-0x1f4c))
#define z2e6483d505              ((0x9d3+6666-0x23db))
#define z7e2eeaa57c          ((0x46c+5939-0x1b9f))
#define z6a0da049de         ((0x1714+2391-0x206a))
#define zc5ce4cb81a              ((0xb2a+980-0xeee))
#define z2b17e2ee3b              ((0xad2+5334-0x1fa8))
#define za80b4365ac                (147456)
static char_T zea4cd01646[(0x123f+3950-0x20ad)];struct z02171375f2{uint32_T zab46142f2e;uint32_T clear;uint32_T event;};static void mdlInitializeSizes(SimStruct*S){uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xe3d+4600-0x2035));ssSetNumDiscStates(S,(0x86c+4480-0x19ec));ssSetNumOutputPorts(S,(0x399+6326-0x1c4f));ssSetNumInputPorts(S,(0x1605+4003-0x25a8));ssSetNumSampleTimes(S,(0x4c7+8224-0x24e6));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1467+2520-0x1e3f));ssSetNumNonsampledZCs(S,(0x5b8+5358-0x1aa6));for(i=(0xcd8+6259-0x254b);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x40b+6026-0x1b95));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x1462+2464-0x1e02)]==-1.0){ssSetSampleTime(S,(0xb56+5604-0x213a),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x85f+3478-0x15f5),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x137b+4826-0x2655),mxGetPr(z3832b85a32)[(0x18a8+204-0x1974)]);ssSetOffsetTime(S,(0x1066+4569-0x223f),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;volatile struct z02171375f2*z79f5963ede;uint8_T z16ba527520[(0x14c5+4431-0x2600)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61;uint32_T z7be9105675,val;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x365+8555-0x24d0)];z6f813cde47=z05b56d9d51=5845;switch(z78caf1ba61){case(0x6ed+5110-0x19a2):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;case(0x1706+2701-0x2048):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;break;}if(mxGetN(z702a26a5e9)==(0x73d+7142-0x2322)){z366b2f03bf=(0x130b+1326-0x1839);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x1403+2516-0x1dd7)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x13a9+3112-0x1fd1)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x111a+3345-0x1e2a)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x1105+2709-0x1b98)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x92+8129-0x2051)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x12a3+3826-0x2193)]);z79f5963ede=(struct z02171375f2*)(zeccbadd9b3.VirtAddress[(0xabc+7181-0x26c7)]+za80b4365ac);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0xbcd+3395-0x190e)]);if(!xpceIsModelInit()){val=(0xd75+3822-0x1c62);z7be9105675=(uint32_T)mxGetPr(ze9153280f8)[(0x4d9+6817-0x1f7a)];val=val|(z7be9105675<<(0xbbd+1828-0x12e0));z7be9105675=(uint32_T)mxGetPr(z1120e7330e)[(0xae8+7047-0x266f)];val=val|(z7be9105675<<(0x75f+4781-0x1a0a));z7be9105675=(uint32_T)mxGetPr(z644559a0a7)[(0x65b+3978-0x15e5)];val=val|(z7be9105675<<(0x450+6781-0x1ec1));
z79f5963ede->zab46142f2e=val;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE    
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile struct z02171375f2*z79f5963ede=(struct z02171375f2*)(base+za80b4365ac);z79f5963ede->zab46142f2e=(0xe66+4006-0x1e0c);
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

