/* Copyright 2006-2013 Speedgoat GmbH. */
#define S_FUNCTION_LEVEL (0x1c0+6706-0x1bf0)
#undef S_FUNCTION_NAME
#define S_FUNCTION_NAME sg_IO601_statuslin_s
#include <stddef.h>
#include <stdlib.h>
#include "simstruc.h"
#ifdef MATLAB_MEX_FILE
#include "mex.h"
#endif
#ifndef MATLAB_MEX_FILE
#include <windows.h>
#include "io_xpcimport.h"
#include "pci_xpcimport.h"
#include "time_xpcimport.h"
#include "ioext_xpcimport.h"
#include "util_xpcimport.h"
#endif
#define zf1b619edf2                "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x36\x30\x31"
#define z694756a014               ((0x2272+2485-0x1b72))
#define zea87e0ba83               (36912)
#define z29146a1837            ((0x16d1+5570-0x1bde))
#define zab7e64468b            (10615)
#define zdf24515981         ((0xbec+4655-0x1e19))
#define z3832b85a32          ssGetSFcnParam(S, (0x1540+3127-0x2177))
#define z702a26a5e9               ssGetSFcnParam(S, (0x1fc2+1494-0x2597))
#define z2e6483d505             ((0x477+6911-0x1f74))
#define z6a0da049de        ((0x30a+6955-0x1e35))
#define z4fc736908d       ((0x1077+2335-0x1995))
#define zc5ce4cb81a             ((0xa8f+1702-0x1135))
#define z2b17e2ee3b             ((0x37f+2064-0xb8f))
#define z45900d86e0       ((0x591+2782-0x1046))
static char_T zea4cd01646[(0xd14+2169-0x148d)];typedef struct{uint8_T zc4ac91c294;uint8_T count;uint16_T z3bcf72e3b0;uint8_T command;uint8_T data[(0x2651+42-0x2630)];}zd40b3e4dfd;
#ifndef MATLAB_MEX_FILE
static void zc0d11e95a0(volatile uint32_T*z3e5b8e05d8){uint32_T zc1ac25c1d6;zc1ac25c1d6=z3e5b8e05d8[(0x25a+4481-0x13c6)];z3e5b8e05d8[(0x7d5+84-0x814)]=zc1ac25c1d6&~((0x1915+2147-0x2177)<<(0x385+4365-0x1490));z3e5b8e05d8[(0x1137+2692-0x1ba6)]=zc1ac25c1d6|((0x1d48+2275-0x262a)<<(0x3e0+6848-0x1e9e));}static uint8_T z06678de23e(volatile uint32_T*z3e5b8e05d8,volatile zd40b3e4dfd*zd042227c40){zd042227c40->zc4ac91c294=(0x10+8269-0x205d);zd042227c40->count=(0x424+5806-0x1ad0);zd042227c40->command=z45900d86e0;zd042227c40->zc4ac91c294=(0x7d0+5448-0x1d17);zc0d11e95a0(z3e5b8e05d8);while(zd042227c40->zc4ac91c294!=(0xdc7+2645-0x181a));return zd042227c40->data[(0x743+1395-0xcb6)];}
#endif
static void mdlInitializeSizes(SimStruct*S){int_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x10e6+2402-0x1a48));ssSetNumDiscStates(S,(0x54+7070-0x1bf2));ssSetNumInputPorts(S,(0x9d1+4708-0x1c35));ssSetNumOutputPorts(S,(0x1d66+542-0x1f80));for(i=(0xca+4454-0x1230);i<(0x453+2327-0xd66);i++){ssSetOutputPortDataType(S,i,SS_UINT32);ssSetOutputPortWidth(S,i,(0x1397+404-0x152a));}ssSetNumSampleTimes(S,(0x2b2+486-0x497));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,(0xe91+5341-0x236e));ssSetNumModes(S,(0x106d+2809-0x1b66));ssSetNumNonsampledZCs(S,(0x16a3+2062-0x1eb1));for(i=(0x1c26+2256-0x24f6);i<zdf24515981;i++){ssSetSFcnParamNotTunable(S,i);}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x17ac+2290-0x209e),mxGetPr(z3832b85a32)[(0x2e7+2935-0xe5e)]);if(mxGetN((z3832b85a32))==(0x1479+1244-0x1954)){ssSetOffsetTime(S,(0x1595+124-0x1611),0.0);}else{ssSetOffsetTime(S,(0xd3f+815-0x106e),mxGetPr(z3832b85a32)[(0x125d+842-0x15a6)]);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x2591+232-0x2678)){z366b2f03bf=(0x8+7301-0x1c8d);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x44b+4933-0x1790)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x1e94+2104-0x26cc)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x16ff+1613-0x1d4b)];}if(xpcGetPCIDeviceInfo((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0xbd7+1246-0x10b3)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x18a9+2608-0x22d7)],zeccbadd9b3.Length[(0x1687+1027-0x1a88)],XPC_RT_PG_USERREADWRITE);zeccbadd9b3.VirtAddress[(0xfe4+3213-0x1c71)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x1093+2673-0x1b04)],zeccbadd9b3.Length[(0xfb4+2383-0x1903)],XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0xa56+1674-0x10de)]);ssSetIWorkValue(S,z4fc736908d,zeccbadd9b3.VirtAddress[(0xf3c+5107-0x232f)]);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE       

uint32_T*out;uint8_T zfd0461066d;volatile zd40b3e4dfd*zd042227c40;
volatile uint32_T*z3e5b8e05d8;uint32_T z5d9c31c2b6,z31a846515d;
uint32_T zc1ac25c1d6;z5d9c31c2b6=ssGetIWorkValue(S,z4fc736908d);z3e5b8e05d8=(void*)z5d9c31c2b6;z31a846515d=ssGetIWorkValue(S,z6a0da049de);zd042227c40=(volatile zd40b3e4dfd*)(z31a846515d);zfd0461066d=z06678de23e(z3e5b8e05d8,zd042227c40);if(zfd0461066d==(0x47+8193-0x2048)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x53\x74\x72\x6f\x6e\x67\x20\x65\x72\x72\x6f\x72\x20\x64\x65\x74\x65\x63\x74\x65\x64\x2c\x20\x70\x6c\x65\x61\x73\x65\x20\x63\x6f\x6e\x74\x61\x63\x74\x20\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x2e",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}else if(zfd0461066d==(0x1f61+843-0x22aa)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x46\x69\x72\x6d\x77\x61\x72\x65\x20\x64\x6f\x65\x73\x20\x6e\x6f\x74\x20\x73\x75\x70\x70\x6f\x72\x74\x20\x4c\x49\x4e\x2e",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}out=(uint32_T*)ssGetOutputPortSignal(S,(0x102b+5081-0x2404));out[(0x13ba+1302-0x18d0)]=zd042227c40->data[(0x7e2+4913-0x1b12)];
out=(uint32_T*)ssGetOutputPortSignal(S,(0x12a3+3693-0x210f));out[(0xad3+3103-0x16f2)]=zd042227c40->data[(0x16fc+707-0x19bd)];
out=(uint32_T*)ssGetOutputPortSignal(S,(0x411+3980-0x139b));out[(0xb62+2248-0x142a)]=zd042227c40->data[(0x10b3+2159-0x191f)]|(zd042227c40->data[(0x1792+3632-0x25be)]<<(0x119c+4219-0x220f));
out=(uint32_T*)ssGetOutputPortSignal(S,(0x971+4651-0x1b99));out[(0x1d+6718-0x1a5b)]=zd042227c40->data[(0x4f9+7286-0x216a)]|(zd042227c40->data[(0x11ac+2540-0x1b92)]<<(0x5a7+5964-0x1ceb))|(zd042227c40->data[(0x74b+5597-0x1d21)]<<(0x2ed+4062-0x12bb))|(zd042227c40->data[(0x345+2822-0xe43)]<<(0x9a7+7514-0x26e9));
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef  MATLAB_MEX_FILE    
#endif
}
#ifdef  MATLAB_MEX_FILE    
#include "simulink.c"      
#else
#include "cg_sfun.h"       
#endif

