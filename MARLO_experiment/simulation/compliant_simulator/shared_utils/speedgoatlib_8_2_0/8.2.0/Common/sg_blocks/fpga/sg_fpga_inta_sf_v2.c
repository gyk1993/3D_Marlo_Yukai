/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x4b1+4573-0x168c)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_inta_sf_v2
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
#define zdf24515981              ((0x24d9+463-0x26a1))
#define z533b11d03f               ssGetSFcnParam(S,(0x80a+828-0xb46))
#define z1120e7330e                ssGetSFcnParam(S,(0x1330+4484-0x24b3))
#define z644559a0a7                   ssGetSFcnParam(S,(0x866+5177-0x1c9d))
#define ze9153280f8                ssGetSFcnParam(S,(0x589+3007-0x1145))
#define z9b8d67d0a4          ssGetSFcnParam(S,(0x888+3602-0x1696))
#define z702a26a5e9                    ssGetSFcnParam(S,(0x11c6+12-0x11cd))
#define z3832b85a32               ssGetSFcnParam(S,(0xb95+845-0xedc))
#define z2e6483d505              ((0x16ff+1486-0x1ccb))
#define z7e2eeaa57c          ((0xae8+7068-0x2684))
#define z6a0da049de         ((0x12a9+3567-0x2097))
#define zc5ce4cb81a              ((0x1df9+1983-0x25b8))
#define z2b17e2ee3b              ((0x1f02+624-0x2172))
#define z2084644852               (458752)
struct za22997a26d{uint32_T zab46142f2e;uint32_T clear;uint32_T copy;uint32_T event;};static char_T zea4cd01646[(0x18f+2879-0xbce)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x9f3+2029-0x11e0));ssSetNumDiscStates(S,(0xd51+724-0x1025));if((uint32_T)mxGetPr(z9b8d67d0a4)[(0x153+1768-0x83b)]){ssSetNumOutputPorts(S,(0xccb+2683-0x1745));ssSetOutputPortWidth(S,(0x1d2c+999-0x2113),(0xe6b+5761-0x24eb));}else{ssSetNumOutputPorts(S,(0x63c+2148-0xea0));}ssSetNumInputPorts(S,(0x1457+743-0x173e));ssSetNumSampleTimes(S,(0x1e8d+1497-0x2465));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x728+3544-0x1500));ssSetNumNonsampledZCs(S,(0x7c5+3159-0x141c));for(i=(0x62b+4446-0x1789);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x473+6249-0x1cdc));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0xc4d+6243-0x24b0)]==-1.0){ssSetSampleTime(S,(0x5d5+7708-0x23f1),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x3ff+3957-0x1374),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xf94+1222-0x145a),mxGetPr(z3832b85a32)[(0x90f+4599-0x1b06)]);ssSetOffsetTime(S,(0x12c+2280-0xa14),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint8_T z16ba527520[(0xbb4+5432-0x20d8)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61;uint32_T val,z7be9105675;volatile struct za22997a26d*zc4ac91c294;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x12d1+2103-0x1b08)];z05b56d9d51=z6f813cde47=(0x1c2d+3595-0x1363);switch(z78caf1ba61){case(0x747+6384-0x1f0a):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");z182d03571c=za4a2434e08=17232;break;case(0x4e0+1956-0xb56):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");z182d03571c=za4a2434e08=17239;break;case(0x9af+1674-0xf0a):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");z182d03571c=za4a2434e08=16979;break;case(0x1821+3879-0x2618):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");z182d03571c=za4a2434e08=(0xaa7+1847-0xcda);break;case(0xc36+7013-0x2664):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");z182d03571c=za4a2434e08=21069;break;case(0xa64+2662-0x1392):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");z182d03571c=za4a2434e08=16971;break;case(0xbca+4441-0x1bea):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");z182d03571c=za4a2434e08=17235;break;case(0xf55+3827-0x1d0e):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");z182d03571c=za4a2434e08=(0x241a+4141-0x1443);break;case(0x9cd+2788-0x1370):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");z182d03571c=za4a2434e08=19520;break;}if(mxGetN(z702a26a5e9)==(0xc72+3035-0x184c)){z366b2f03bf=(0x1a42+1788-0x213e);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xf0b+3145-0x1b54)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x4ba+7969-0x23db)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xeb5+4784-0x2164)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x5f4+5270-0x1a88)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x1097+669-0x1332)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x3c1+8916-0x2693)]);zc4ac91c294=(struct za22997a26d*)(zeccbadd9b3.VirtAddress[(0x1a01+1541-0x2004)]+z2084644852);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x956+4646-0x1b7a)]);if(!xpceIsModelInit()){val=(0x9b2+3718-0x1837);z7be9105675=mxGetPr(ze9153280f8)[(0x2ab+1741-0x978)];val=val|(z7be9105675<<(0x13b+5929-0x1863));z7be9105675=mxGetPr(z1120e7330e)[(0x1516+2434-0x1e98)];val=val|(z7be9105675<<(0x761+7429-0x2464));z7be9105675=mxGetPr(z644559a0a7)[(0xe56+3743-0x1cf5)];val=val|(z7be9105675<<(0x4ac+1849-0xbd9));
zc4ac91c294->clear=(0x92d+6179-0x214f);zc4ac91c294->clear=(0x1248+2516-0x1c1c);zc4ac91c294->zab46142f2e=val;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE 
uint32_T base=ssGetIWorkValue(S,z6a0da049de);real_T*out;volatile struct za22997a26d*zc4ac91c294=(struct za22997a26d*)(base+z2084644852);if(zc4ac91c294->event){zc4ac91c294->clear=(0x1f64+549-0x2188);zc4ac91c294->clear=(0xfd8+3633-0x1e09);if((uint32_T)mxGetPr(z9b8d67d0a4)[(0x1d11+1398-0x2287)]){out=(real_T*)ssGetOutputPortSignal(S,(0x1291+5089-0x2672));out[(0x2dc+1526-0x8d2)]=(0x1a1b+2818-0x251c);}}else{if((uint32_T)mxGetPr(z9b8d67d0a4)[(0x12c+2989-0xcd9)]){out=(real_T*)ssGetOutputPortSignal(S,(0x1e6b+2017-0x264c));out[(0x10d8+4822-0x23ae)]=(0x216d+480-0x234d);}}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile struct za22997a26d*zc4ac91c294=(struct za22997a26d*)(base+z2084644852);if(!xpceIsModelInit()){
zc4ac91c294->clear=(0x125+4964-0x1488);zc4ac91c294->clear=(0x6b1+6027-0x1e3c);zc4ac91c294->zab46142f2e=(0x7b+6488-0x19d3);}
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

