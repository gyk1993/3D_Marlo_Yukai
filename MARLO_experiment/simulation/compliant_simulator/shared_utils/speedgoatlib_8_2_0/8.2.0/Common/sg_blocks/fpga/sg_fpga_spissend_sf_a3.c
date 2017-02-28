/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x7ec+6965-0x231f)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_spissend_sf_a3
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
#define zdf24515981              ((0x1298+880-0x1603))
#define z533b11d03f               ssGetSFcnParam(S, (0x1de1+656-0x2071))
#define za9d8fb6bcf                 ssGetSFcnParam(S, (0x1026+2313-0x192e))
#define z3d4ad966bd                   ssGetSFcnParam(S, (0x97+5814-0x174b))
#define z3832b85a32               ssGetSFcnParam(S, (0x21dd+1249-0x26bb))
#define z702a26a5e9                    ssGetSFcnParam(S, (0xe6f+4309-0x1f40))
#define z2e6483d505              ((0x8c+8433-0x217b))
#define z7e2eeaa57c          ((0x11c7+4697-0x2420))
#define z6a0da049de         ((0xdec+4720-0x205b))
#define zc5ce4cb81a              ((0x10dd+74-0x1117))
#define z2b17e2ee3b              ((0x2245+944-0x25f5))
#define zcbf95547ad								212992
static char_T zea4cd01646[(0x1d65+23-0x1c7c)];typedef struct{volatile uint32_T z4da0d16710;volatile uint32_T z13e3aff50f;volatile uint32_T MSBFirst;volatile uint32_T z79c39f7a01;volatile uint32_T z21ab44ce3e;volatile uint32_T z05095ec8c5;volatile uint32_T z633e4d0b43[(0xb95+273-0xc96)];volatile uint32_T z1907ddba6c[(0xc04+5732-0x2258)];volatile uint32_T z17cbe2a22e[(0xe7+8974-0x23e5)];volatile uint32_T z45128425fd[(0x205+4011-0x11a0)];}ze823aa19b7;static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x15bc+2439-0x1f43));ssSetNumDiscStates(S,(0x1b35+2997-0x26ea));ssSetNumOutputPorts(S,(0x5ff+4503-0x1796));ssSetNumInputPorts(S,mxGetN(za9d8fb6bcf));for(i=(0x54f+1653-0xbc4);i<mxGetN(za9d8fb6bcf);i++){ssSetInputPortWidth(S,i,(uint32_T)mxGetPr(z3d4ad966bd)[(0xb92+5329-0x2063)]+(0x1a07+2471-0x23ad));ssSetInputPortDirectFeedThrough(S,i,(0x7c1+6589-0x217d));ssSetInputPortRequiredContiguous(S,i,(0x24d+2002-0xa1e));}ssSetNumSampleTimes(S,(0x6a2+5575-0x1c68));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xd05+3048-0x18ed));ssSetNumNonsampledZCs(S,(0x87b+7661-0x2668));for(i=(0xcc5+5129-0x20ce);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x12e8+2167-0x1b5f));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x350+6064-0x1b00)]==-1.0){ssSetSampleTime(S,(0xba2+3632-0x19d2),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1419+2583-0x1e30),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x3d5+5548-0x1981),mxGetPr(z3832b85a32)[(0xf81+53-0xfb6)]);ssSetOffsetTime(S,(0x492+6163-0x1ca5),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint8_T z16ba527520[(0x8c5+1091-0xcf4)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61;int32_T z366b2f03bf,z441f9e6d1b;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x155b+962-0x191d)];z6f813cde47=z05b56d9d51=(0x1b61+4456-0x15f4);switch(z78caf1ba61){case(0x1c0a+1243-0x1fa4):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;case(0x17d4+3775-0x2548):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;break;}if(mxGetN(z702a26a5e9)==(0x111+5580-0x16dc)){z366b2f03bf=(0x7a9+7976-0x26d1);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x1e13+521-0x201c)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x1e84+552-0x20ac)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x420+2844-0xf3b)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x8b1+6942-0x23cd)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0xbcf+3915-0x1b18)],zeccbadd9b3.Length[(0x31+5959-0x1776)],XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0xed4+1574-0x14f8)]);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE     
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint32_T z26dbd73a5e,i,width,count;real_T*in;uint32_T z4e3026977c;volatile ze823aa19b7*z380706df00;width=(uint32_T)mxGetPr(z3d4ad966bd)[(0xb43+3717-0x19c8)]+(0x10c+4225-0x118c);z380706df00=(ze823aa19b7*)(base+zcbf95547ad);for(i=(0x82a+3530-0x15f4);i<mxGetN(za9d8fb6bcf);i++)
{z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1f9d+1538-0x259e);in=(real_T*)ssGetInputPortSignal(S,z4e3026977c);count=(uint32_T)in[(0xd19+903-0x10a0)];for(z26dbd73a5e=(0x1928+1911-0x209f);z26dbd73a5e<count;z26dbd73a5e++)
{
z380706df00->z633e4d0b43[z4e3026977c]=(uint32_T)in[z26dbd73a5e+(0x1fea+1317-0x250e)];
z380706df00->z17cbe2a22e[z4e3026977c]=z26dbd73a5e;
z380706df00->z21ab44ce3e=((0x1114+2492-0x1acf)<<z4e3026977c);z380706df00->z21ab44ce3e=(0x61a+6000-0x1d8a);}}
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

