/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xeac+4516-0x204e)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_spis_sf_a3
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
#include        "xpcPCFunctions.h"
#include        "time_xpcimport.h"
#include        "ioext_xpcimport.h"
#include        "util_xpcimport.h"
#endif
#define zdf24515981              ((0x2ec+3982-0x1274))
#define z533b11d03f               ssGetSFcnParam(S, (0x1952+689-0x1c03))
#define za9d8fb6bcf                 ssGetSFcnParam(S, (0x133d+4451-0x249f))
#define z86af52d74e                    ssGetSFcnParam(S, (0x74d+3186-0x13bd))
#define z31fb671cb8                    ssGetSFcnParam(S, (0x100d+30-0x1028))
#define zea4d7ef473                ssGetSFcnParam(S, (0x20e2+1261-0x25cb))
#define z702a26a5e9                    ssGetSFcnParam(S, (0x19a9+427-0x1b4f))
#define z2e6483d505              ((0xef5+3641-0x1d2c))
#define z7e2eeaa57c          ((0x1411+1584-0x1a41))
#define z6a0da049de         ((0x833+6779-0x22ad))
#define zc5ce4cb81a              ((0x1348+2394-0x1c92))
#define z2b17e2ee3b              ((0x11e1+1846-0x1917))
#define zcbf95547ad								212992
static char_T zea4cd01646[(0x608+698-0x7c2)];typedef struct{volatile uint32_T z4da0d16710;volatile uint32_T z13e3aff50f;volatile uint32_T MSBFirst;volatile uint32_T z79c39f7a01;volatile uint32_T z21ab44ce3e;volatile uint32_T z05095ec8c5;volatile uint32_T z633e4d0b43[(0x1238+1450-0x17d2)];volatile uint32_T z1907ddba6c[(0x975+415-0xb04)];volatile uint32_T z17cbe2a22e[(0x25d3+211-0x2696)];volatile uint32_T z45128425fd[(0x1d11+660-0x1f95)];}ze823aa19b7;static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x436+8374-0x24ec));ssSetNumDiscStates(S,(0x205a+804-0x237e));ssSetNumOutputPorts(S,(0x915+5727-0x1f74));ssSetNumInputPorts(S,(0x92f+4237-0x19bc));ssSetNumSampleTimes(S,(0x733+907-0xabd));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x109c+1457-0x164d));ssSetNumNonsampledZCs(S,(0x166d+1286-0x1b73));for(i=(0x1abd+525-0x1cca);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1c99+910-0x2027));}
ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x2c9+5652-0x18dd),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x95f+2840-0x1477),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;uint8_T z16ba527520[(0x6fc+4034-0x16aa)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61;int32_T z366b2f03bf,z441f9e6d1b;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x609+8113-0x25ba)];z6f813cde47=z05b56d9d51=5845;switch(z78caf1ba61){case(0x18ef+2028-0x1f9a):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;case(0x196a+3630-0x264d):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;break;}if(mxGetN(z702a26a5e9)==(0x13f8+608-0x1657)){z366b2f03bf=(0xdd0+2239-0x168f);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x2f5+8956-0x25f1)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x21fb+917-0x2590)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xaa4+6166-0x22b9)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0xdd9+997-0x11bc)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0xee0+4623-0x20ed)],zeccbadd9b3.Length[(0x152f+3377-0x225e)],XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x993+2168-0x1209)]);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE       
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE   
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T i;uint32_T z4e3026977c,z1209c02d78,zdc0d676974,zbea4a89f24,z9e58a4ec45;volatile ze823aa19b7*z380706df00;z380706df00=(ze823aa19b7*)(base+zcbf95547ad);z1209c02d78=z380706df00->z4da0d16710;zdc0d676974=z380706df00->z13e3aff50f;zbea4a89f24=z380706df00->z79c39f7a01;z9e58a4ec45=z380706df00->MSBFirst;for(i=(0x21e2+415-0x2381);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x31d+343-0x473);z1209c02d78|=((0xdfa+2217-0x16a2)<<z4e3026977c);zdc0d676974|=(((uint32_T)mxGetPr(z86af52d74e)[i])<<z4e3026977c);zbea4a89f24|=(((uint32_T)mxGetPr(z31fb671cb8)[i])<<z4e3026977c);z9e58a4ec45|=(((uint32_T)mxGetPr(zea4d7ef473)[i])<<z4e3026977c);}z380706df00->z13e3aff50f=zdc0d676974;z380706df00->MSBFirst=z9e58a4ec45;z380706df00->z79c39f7a01=zbea4a89f24;
z380706df00->z4da0d16710=z1209c02d78;
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

