/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x130c+3120-0x1f3a)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_spisreceive_sf_a3
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
#define zdf24515981              ((0x2d+5095-0x140f))
#define z533b11d03f               ssGetSFcnParam(S, (0x6a0+7360-0x2360))
#define za9d8fb6bcf                 ssGetSFcnParam(S, (0x1c12+2309-0x2516))
#define z3d4ad966bd                   ssGetSFcnParam(S, (0x474+1205-0x927))
#define z3832b85a32               ssGetSFcnParam(S, (0x855+7655-0x2639))
#define z702a26a5e9                    ssGetSFcnParam(S, (0x2397+158-0x2431))
#define z2e6483d505              ((0x1150+2549-0x1b43))
#define z7e2eeaa57c          ((0x14d6+1536-0x1ad6))
#define z6a0da049de         ((0x252+3055-0xe40))
#define zc5ce4cb81a              ((0x3ff+7595-0x219a))
#define z2b17e2ee3b              ((0x258+7484-0x1f94))
#define zcbf95547ad								212992
static char_T zea4cd01646[(0x66d+2235-0xe28)];typedef struct{volatile uint32_T z4da0d16710;volatile uint32_T z13e3aff50f;volatile uint32_T MSBFirst;volatile uint32_T z79c39f7a01;volatile uint32_T z21ab44ce3e;volatile uint32_T z05095ec8c5;volatile uint32_T z633e4d0b43[(0x15+7531-0x1d70)];volatile uint32_T z1907ddba6c[(0xdb+1922-0x84d)];volatile uint32_T z17cbe2a22e[(0xacb+2514-0x148d)];volatile uint32_T z45128425fd[(0x15e4+92-0x1630)];}ze823aa19b7;static void mdlInitializeSizes(SimStruct*S){uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x68+7637-0x1e3d));ssSetNumDiscStates(S,(0x11df+5372-0x26db));ssSetNumOutputPorts(S,mxGetN(za9d8fb6bcf));for(i=(0x16f1+2098-0x1f23);i<mxGetN(za9d8fb6bcf);i++){ssSetOutputPortWidth(S,i,(uint32_T)mxGetPr(z3d4ad966bd)[(0x1eff+1086-0x233d)]+(0x163a+2024-0x1e21));}ssSetNumSampleTimes(S,(0xbff+1153-0x107f));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x729+856-0xa81));ssSetNumNonsampledZCs(S,(0x1749+1248-0x1c29));for(i=(0xa37+1177-0xed0);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xb74+5623-0x216b));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x1fdc+1211-0x2497)]==-1.0){ssSetSampleTime(S,(0x671+2588-0x108d),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x8b2+3528-0x167a),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x1477+2788-0x1f5b),mxGetPr(z3832b85a32)[(0xf71+5225-0x23da)]);ssSetOffsetTime(S,(0xfcb+3107-0x1bee),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint8_T z16ba527520[(0x2bf+3904-0x11eb)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61;int32_T z366b2f03bf,z441f9e6d1b;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x2332+61-0x236f)];z6f813cde47=z05b56d9d51=(0x1f7a+5844-0x1f79);switch(z78caf1ba61){case(0x47b+6378-0x1c24):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;case(0x102d+4547-0x20a5):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;break;}if(mxGetN(z702a26a5e9)==(0x3db+6447-0x1d09)){z366b2f03bf=(0x153+250-0x24d);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xc96+5075-0x2069)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x168a+4214-0x2700)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x14b2+4606-0x26af)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x1852+296-0x1978)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0xedf+770-0x11df)],zeccbadd9b3.Length[(0x136d+2996-0x1f1f)],XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0xaa9+1812-0x11bb)]);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE     
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint32_T z26dbd73a5e,i,width,count;real_T*out;uint32_T z4e3026977c;volatile ze823aa19b7*z380706df00;z380706df00=(ze823aa19b7*)(base+zcbf95547ad);width=(uint32_T)mxGetPr(z3d4ad966bd)[(0x12f+4619-0x133a)]+(0x1393+3530-0x215c);
for(i=(0xb86+6396-0x2482);i<mxGetN(za9d8fb6bcf);i++)
{z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xeb1+3326-0x1bae);count=z380706df00->z45128425fd[z4e3026977c];out=ssGetOutputPortSignal(S,z4e3026977c);if(count>(0xba3+287-0xcc2)){
for(z26dbd73a5e=(0xd39+3386-0x1a73);z26dbd73a5e<(uint8_T)mxGetPr(z3d4ad966bd)[(0x1c4b+1743-0x231a)];z26dbd73a5e++){out[z26dbd73a5e]=(0x1c83+1734-0x2349);}for(z26dbd73a5e=(0x1b02+2800-0x25f2);z26dbd73a5e<count;z26dbd73a5e++){
z380706df00->z17cbe2a22e[z4e3026977c]=z26dbd73a5e;
out[z26dbd73a5e+(0x1332+4978-0x26a3)]=(real_T)z380706df00->z1907ddba6c[z4e3026977c];}
z380706df00->z05095ec8c5=((0x103b+184-0x10f2)<<z4e3026977c);z380706df00->z05095ec8c5=(0x2f8+6047-0x1a97);}out[(0x9bc+1525-0xfb1)]=(real_T)count;
}
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

