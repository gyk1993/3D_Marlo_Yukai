/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xd51+5281-0x21f0)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_i2cmwrite_sf_a1
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
#define zdf24515981        ((0x36b+2519-0xd3d))
#define z533b11d03f         ssGetSFcnParam(S, (0xb0+5559-0x1667)) 
#define za9d8fb6bcf           ssGetSFcnParam(S, (0x92d+7208-0x2554)) 
#define zf5ee62a4ad      ssGetSFcnParam(S, (0x17df+2824-0x22e5))
#define z3832b85a32         ssGetSFcnParam(S, (0x65a+1729-0xd18))
#define z702a26a5e9              ssGetSFcnParam(S, (0xb5b+4611-0x1d5a))
#define z2e6483d505              ((0xc33+5450-0x217c))
#define zc5ce4cb81a              ((0x12a9+3823-0x2198))
#define z2b17e2ee3b              ((0x1d1+5786-0x186b))
#define z6a0da049de         ((0x3cd+6859-0x1e98))
#define zb4530cf885                (180224)
static char_T zea4cd01646[(0x15eb+1727-0x1baa)];struct z71f90c95f9{uint32_T start;uint32_T clear;uint32_T zeb5b1d96b9;uint32_T z21ab44ce3e;uint32_T count[(0xf99+5835-0x2644)];uint32_T z28e9d9261f[(0x640+800-0x940)];uint32_T z1fe5bfccaf[(0x274+1744-0x924)];uint32_T z627a05d850[(0x1e2+4168-0x120a)];uint32_T z94328689b6[(0xb0a+353-0xc4b)];uint32_T z039626e71b[(0x10a4+3917-0x1fd1)];uint32_T z5e4e5bef4b;};static void mdlInitializeSizes(SimStruct*S){uint32_T i,za0df33019b;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x1fba+1404-0x2536));ssSetNumDiscStates(S,(0x1483+3210-0x210d));ssSetNumOutputPorts(S,(0x19b8+1315-0x1edb));ssSetNumInputPorts(S,(0x219c+844-0x24e5));
ssSetInputPortWidth(S,(0x1eda+1662-0x2558),(0x218b+664-0x2422));ssSetInputPortDirectFeedThrough(S,(0x237c+609-0x25dd),(0xea4+5941-0x25d8));ssSetInputPortRequiredContiguous(S,(0x931+1653-0xfa6),(0x87d+4500-0x1a10));ssSetInputPortWidth(S,(0x1211+1431-0x17a7),(0x229+7121-0x1df9));ssSetInputPortDirectFeedThrough(S,(0x914+3627-0x173e),(0x1769+519-0x196f));ssSetInputPortRequiredContiguous(S,(0x1fb+5299-0x16ad),(0xeb+5024-0x148a));ssSetInputPortWidth(S,(0x1d0+1671-0x855),(0xfd2+892-0x130e));ssSetInputPortDirectFeedThrough(S,(0x993+460-0xb5d),(0x279+4106-0x1282));ssSetInputPortRequiredContiguous(S,(0xb05+4045-0x1ad0),(0x6fd+4288-0x17bc));ssSetNumSampleTimes(S,(0x1cfd+1382-0x2262));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1029+950-0x13df));ssSetNumNonsampledZCs(S,(0x2b4+1967-0xa63));for(i=(0x21a7+1300-0x26bb);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1137+3815-0x201e));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x996+2395-0x12f1)]==-1.0){ssSetSampleTime(S,(0x826+816-0xb56),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x130d+4481-0x248e),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x2bf+6543-0x1c4e),mxGetPr(z3832b85a32)[(0x17bd+2544-0x21ad)]);ssSetOffsetTime(S,(0x2dd+4858-0x15d7),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i;uint8_T z16ba527520[(0xa29+1363-0xf68)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61,z4e3026977c;volatile struct z71f90c95f9*zca56c6316b;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x84+7827-0x1f17)];z6f813cde47=z05b56d9d51=(0x1843+5819-0x1829);switch(z78caf1ba61){case(0x1041+2647-0x1957):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;case(0x11c5+3413-0x1dcf):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;break;}if(mxGetN(z702a26a5e9)==(0xa3f+1344-0xf7e)){z366b2f03bf=(0xcb+2005-0x8a0);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x2d4+5632-0x18d4)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x14b+384-0x2cb)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x20ed+602-0x2346)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x10e7+3293-0x1dc2)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x17+5260-0x14a1)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x7d6+7718-0x25fa)]);zca56c6316b=(volatile struct z71f90c95f9*)(zeccbadd9b3.VirtAddress[(0xfcc+4543-0x2189)]+zb4530cf885);if(!xpceIsModelInit()){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[(0x8ba+4641-0x1adb)]-(0x633+6113-0x1e13);zca56c6316b->z28e9d9261f[z4e3026977c]=(uint32_T)mxGetPr(zf5ee62a4ad)[(0x25b+4577-0x143c)];

}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint32_T i,z4e3026977c,z039626e71b,count;real_T*y;volatile struct z71f90c95f9*zca56c6316b=(struct z71f90c95f9*)(base+zb4530cf885);
z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[(0xf60+5828-0x2624)]-(0x1dc0+1877-0x2514);
while(((zca56c6316b->z5e4e5bef4b>>z4e3026977c)&(0x154d+168-0x15f4))==(0x16cd+618-0x1937));y=(real_T*)ssGetInputPortSignal(S,(0x11+5855-0x16f0));z039626e71b=(uint32_T)y[(0x3e4+4330-0x14ce)];zca56c6316b->z039626e71b[z4e3026977c]=z039626e71b;y=(real_T*)ssGetInputPortSignal(S,(0x653+1073-0xa83));count=(uint32_T)y[(0x1fdb+64-0x201b)];zca56c6316b->count[z4e3026977c]=count;y=(real_T*)ssGetInputPortSignal(S,(0x35d+5244-0x17d7));for(i=(0xe3f+4832-0x211f);i<count;i++){
zca56c6316b->z1fe5bfccaf[z4e3026977c]=(uint32_T)i;
zca56c6316b->z627a05d850[z4e3026977c]=(uint32_T)y[i];zca56c6316b->z21ab44ce3e=((0x1f3a+592-0x2189)<<z4e3026977c);zca56c6316b->z21ab44ce3e=(0x565+6505-0x1ece);}zca56c6316b->zeb5b1d96b9=((0x76f+965-0xb34)<<z4e3026977c);
if(count>(0xea+5196-0x1536)){zca56c6316b->start=((0xb0b+6739-0x255d)<<z4e3026977c);zca56c6316b->start=(0x108c+1026-0x148e);}
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
