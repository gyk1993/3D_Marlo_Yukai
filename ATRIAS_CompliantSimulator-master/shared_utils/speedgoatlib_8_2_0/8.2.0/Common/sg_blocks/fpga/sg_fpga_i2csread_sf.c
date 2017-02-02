/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xb11+1427-0x10a2)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_i2csread_sf
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
#define zdf24515981        ((0x585+4717-0x17ed))
#define z533b11d03f         ssGetSFcnParam(S, (0x2103+13-0x2110)) 
#define za9d8fb6bcf           ssGetSFcnParam(S, (0x219+5831-0x18df)) 
#define zd7a15617ca         ssGetSFcnParam(S, (0xa3c+5384-0x1f42))
#define z3832b85a32         ssGetSFcnParam(S, (0x1809+2189-0x2093))
#define z702a26a5e9              ssGetSFcnParam(S, (0x18dc+3109-0x24fd))
#define z2e6483d505              ((0x46f+8799-0x26cd))
#define zc5ce4cb81a              ((0x2293+608-0x24f3))
#define z2b17e2ee3b              ((0x201b+1351-0x2562))
#define z6a0da049de         ((0x9c8+6949-0x24ed))
#define zceae5ef027                (524288)
static char_T zea4cd01646[(0xe78+1701-0x141d)];struct z4ffeb08593{uint32_T z4da0d16710;uint32_T clear;uint32_T z553991aa78;uint32_T z039626e71b[(0xa6a+1053-0xe67)];uint32_T z7515281f6c[(0x2ba+640-0x51a)];uint32_T zd6e550175f[(0x86a+3494-0x15f0)];uint32_T z2678040317[(0x1cd+9414-0x2673)];};static void mdlInitializeSizes(SimStruct*S){uint32_T i,za0df33019b;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x689+3846-0x158f));ssSetNumDiscStates(S,(0x13e4+1428-0x1978));ssSetNumOutputPorts(S,(0x813+3756-0x16be));ssSetOutputPortWidth(S,(0x1c66+2247-0x252d),mxGetN(zd7a15617ca));ssSetNumInputPorts(S,(0x15fd+2479-0x1fac));
ssSetNumSampleTimes(S,(0x680+4490-0x1809));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1ff8+1674-0x2682));ssSetNumNonsampledZCs(S,(0x1ae4+1326-0x2012));for(i=(0x15b1+2760-0x2079);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x4a+2531-0xa2d));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x7c6+5711-0x1e15)]==-1.0){ssSetSampleTime(S,(0x141d+2753-0x1ede),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x14aa+2654-0x1f08),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x116d+5108-0x2561),mxGetPr(z3832b85a32)[(0x23+9861-0x26a8)]);ssSetOffsetTime(S,(0x1369+102-0x13cf),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i;uint8_T z16ba527520[(0x8a1+4951-0x1be4)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x81d+588-0xa69)];z6f813cde47=z05b56d9d51=5845;switch(z78caf1ba61){case(0x679+1694-0xbea):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");za4a2434e08=z182d03571c=17232;break;case(0xb8d+6106-0x2239):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");za4a2434e08=z182d03571c=17239;break;case(0x70c+4246-0x1673):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");za4a2434e08=z182d03571c=16979;break;case(0x18bb+2269-0x2068):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");za4a2434e08=z182d03571c=(0x2068+1083-0x1f9f);break;case(0x1b8a+2626-0x2495):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");za4a2434e08=z182d03571c=21069;break;case(0xeac+3624-0x1b9c):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");za4a2434e08=z182d03571c=16971;break;case(0x1026+2732-0x1999):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");za4a2434e08=z182d03571c=17235;break;case(0x210d+290-0x20f5):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");za4a2434e08=z182d03571c=8196;break;case(0x825+2828-0x11f0):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;}if(mxGetN(z702a26a5e9)==(0x94c+2965-0x14e0)){z366b2f03bf=(0x511+5162-0x193b);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xa5c+2011-0x1237)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x552+2978-0x10f4)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x15c2+2033-0x1db2)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x30c+4525-0x14b7)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0xf04+5316-0x23c6)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x1784+289-0x18a3)]);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint32_T i,z4e3026977c;real_T*y;volatile struct z4ffeb08593*z77b62f8983=(struct z4ffeb08593*)(base+zceae5ef027);y=(real_T*)ssGetOutputPortSignal(S,(0x1bf7+2615-0x262e));for(i=(0x76f+190-0x82d);i<mxGetN(zd7a15617ca);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[(0x1712+111-0x1781)]-(0x9b2+3469-0x173e);
z77b62f8983->z7515281f6c[z4e3026977c]=(uint32_T)mxGetPr(zd7a15617ca)[i]-(0x200+5204-0x1653);
y[i]=(real_T)z77b62f8983->z2678040317[z4e3026977c];}
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
