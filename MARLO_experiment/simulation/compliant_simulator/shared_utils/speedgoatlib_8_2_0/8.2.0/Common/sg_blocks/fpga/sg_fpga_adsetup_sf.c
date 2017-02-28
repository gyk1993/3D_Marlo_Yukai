/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1050+1754-0x1728)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_adsetup_sf
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
#define zdf24515981              ((0x4e6+2647-0xf3a))
#define z702a26a5e9                    ssGetSFcnParam(S,(0xae0+1232-0xfb0))
#define z8c2942e11d                  ssGetSFcnParam(S,(0x1083+2094-0x18b0))
#define zda964b0978					ssGetSFcnParam(S,(0x83c+4681-0x1a83))
#define z2e6483d505              ((0x59+6952-0x1b7f))
#define z7e2eeaa57c          ((0x16f+1855-0x8ae))
#define z6a0da049de         ((0x4df+1732-0xba2))
#define zc5ce4cb81a              ((0x535+723-0x7f8))
#define z2b17e2ee3b              ((0x1505+3499-0x22b0))
static char_T zea4cd01646[(0xb5f+6345-0x2328)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x1f6+8227-0x2219));ssSetNumDiscStates(S,(0x1e7a+662-0x2110));ssSetNumOutputPorts(S,(0x175+4990-0x14f3));ssSetNumInputPorts(S,(0x17a6+2521-0x217f));ssSetNumSampleTimes(S,(0x154a+2051-0x1d4c));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x25d3+161-0x2674));ssSetNumNonsampledZCs(S,(0xb22+2193-0x13b3));for(i=(0x94b+6782-0x23c9);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x111f+3612-0x1f3b));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0xc7f+192-0xd3f),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x6f1+2470-0x1097),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z7be9105675,z4e3026977c;real_T scale;uint8_T z16ba527520[(0x834+3835-0x171b)];uint16_T z6f813cde47,za4a2434e08;strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");z6f813cde47=(0x230d+3422-0x1996);za4a2434e08=19520;if((int_T)mxGetPr(z702a26a5e9)[(0x1388+3670-0x21de)]<(0xea7+1340-0x13e3)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x6d5+1725-0xd91)){z366b2f03bf=(0xe64+3348-0x1b78);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xccb+2872-0x1803)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x8ab+3699-0x171e)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x743+5517-0x1ccf)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x10c0+3145-0x1c0a))|((z366b2f03bf&(0x5b6+1463-0xa6e))<<(0x463+2130-0xcad)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x2f2+300-0x41c)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T i,z812c65ff2f;volatile uint32_T*za42cf7dd4a;int32_T out;uint16_T z4e3026977c;uint16_T first;uint32_T z52754d10b7;real_T start,z19c4ca5f82;

uint32_T zefc6de980b[]={131840,131841,197379,197380,8519691,43581533,138410510,140814095};
za42cf7dd4a=(void*)base;

z52754d10b7=za42cf7dd4a[8256];za42cf7dd4a[8256]=z52754d10b7&(~(0x1ec6+1280-0x23ae));
#ifdef DEBUG
printf("\x50\x4d\x43\x2d\x4c\x58\x34\x30\x2d\x41\x58\x4d\x2d\x41\x33\x30\x3a\x20\x43\x6c\x6f\x63\x6b\x20\x73\x6f\x75\x72\x63\x65\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x65\x64\x2e" "\n");
#endif

z52754d10b7=za42cf7dd4a[(0x2256+3962-0x118c)];za42cf7dd4a[8260]=z52754d10b7&(~(0xc8a+3379-0x19ad));
#ifdef DEBUG
printf("\x50\x4d\x43\x2d\x4c\x58\x34\x30\x2d\x41\x58\x4d\x2d\x41\x33\x30\x3a\x20\x43\x6c\x6f\x63\x6b\x20\x67\x65\x6e\x65\x72\x61\x74\x6f\x72\x20\x6f\x75\x74\x70\x75\x74\x73\x20\x64\x69\x73\x61\x62\x6c\x65\x64\x2e" "\n");
#endif

z52754d10b7=za42cf7dd4a[(0x2541+1469-0xab9)];za42cf7dd4a[8261]=z52754d10b7|2147483648;

xpcBusyWait(0.001);
#ifdef DEBUG    
printf("\x50\x4d\x43\x2d\x4c\x58\x34\x30\x2d\x41\x58\x4d\x2d\x41\x33\x30\x3a\x20\x43\x6f\x6e\x66\x69\x67\x75\x72\x61\x74\x69\x6f\x6e\x20\x52\x30\x20\x74\x6f\x20\x52\x31\x35\x2e" "\n");
#endif

for(i=(0x1d4+7023-0x1d43);i<(0x1fe3+1490-0x25ad);i++){
za42cf7dd4a[8261+i]=zefc6de980b[i];
z812c65ff2f=(0x14f+4321-0x1230);while((za42cf7dd4a[8260]&(0xb35+4753-0x1dc5))==(0x10b+5783-0x17a1)){z812c65ff2f++;}
#ifdef DEBUG    
printf("\x50\x4d\x43\x2d\x4c\x58\x34\x30\x2d\x41\x58\x4d\x2d\x41\x33\x30\x3a\x20\x63\x6c\x6f\x63\x6b\x20\x72\x65\x67\x69\x73\x74\x65\x72\x3a\x20\x25\x78" "\n",za42cf7dd4a[8261+i]);printf("\x50\x4d\x43\x2d\x4c\x58\x34\x30\x2d\x41\x58\x4d\x2d\x41\x33\x30\x3a\x20\x6b\x3a\x20\x25\x64" "\n",z812c65ff2f);
#endif
}
#ifdef DEBUG
printf("\x50\x4d\x43\x2d\x4c\x58\x34\x30\x2d\x41\x58\x4d\x2d\x41\x33\x30\x3a\x20\x52\x30\x20\x74\x6f\x20\x52\x31\x35\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x65\x64\x2e" "\n");
#endif


#ifdef DEBUG   
printf("\x50\x4d\x43\x2d\x4c\x58\x34\x30\x2d\x41\x58\x4d\x2d\x41\x33\x30\x3a\x20\x50\x4c\x4c\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x65\x64\x2e\x2e\x2e" "\n");
#endif

z52754d10b7=za42cf7dd4a[8260];za42cf7dd4a[8260]=z52754d10b7|(0xcd7+4605-0x1eb4);
xpcBusyWait(0.002);
z52754d10b7=za42cf7dd4a[8260];za42cf7dd4a[8260]=z52754d10b7|(0x1541+4424-0x2679);
#ifdef DEBUG    
printf("\x50\x4d\x43\x2d\x4c\x58\x34\x30\x2d\x41\x58\x4d\x2d\x41\x33\x30\x3a\x20\x43\x6c\x6f\x63\x6b\x20\x67\x65\x6e\x65\x72\x61\x74\x6f\x72\x20\x72\x65\x2d\x61\x63\x74\x69\x76\x61\x74\x65\x64\x2e" "\n");
#endif


za42cf7dd4a[9588]=(uint32_T)mxGetPr(z8c2942e11d)[(0x17f2+2890-0x233c)];za42cf7dd4a[9589]=(uint32_T)mxGetPr(z8c2942e11d)[(0xbf9+354-0xd5a)];
za42cf7dd4a[9586]=(uint32_T)mxGetPr(zda964b0978)[(0x1b46+2274-0x2428)];za42cf7dd4a[9587]=(uint32_T)mxGetPr(zda964b0978)[(0x152a+3208-0x21b1)];
z52754d10b7=za42cf7dd4a[8257];za42cf7dd4a[(0x22c4+2602-0xcad)]=z52754d10b7|((0xa37+6877-0x250e)|((0xd41+6386-0x262d)<<(0x3c8+1453-0x965)));
z52754d10b7=za42cf7dd4a[8256];za42cf7dd4a[8256]=z52754d10b7|(0xda8+1484-0x1014);
#ifdef DEBUG	
printf("\x50\x4d\x43\x2d\x4c\x58\x34\x30\x2d\x41\x58\x4d\x2d\x41\x33\x30\x3a\x20\x43\x6c\x6f\x63\x6b\x20\x43\x6f\x6e\x64\x69\x74\x69\x6f\x6e\x6e\x65\x72\x20\x72\x65\x67\x69\x73\x74\x65\x72\x3a\x20\x25\x78" "\n",za42cf7dd4a[8260]);printf("\x50\x4d\x43\x2d\x4c\x58\x34\x30\x2d\x41\x58\x4d\x2d\x41\x33\x30\x3a\x20\x53\x61\x6d\x70\x6c\x65\x20\x65\x6e\x67\x69\x6e\x65\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x61\x74\x69\x6f\x6e\x20\x63\x6f\x6d\x70\x6c\x65\x74\x65\x64\x2e" "\n");
#endif   
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif
