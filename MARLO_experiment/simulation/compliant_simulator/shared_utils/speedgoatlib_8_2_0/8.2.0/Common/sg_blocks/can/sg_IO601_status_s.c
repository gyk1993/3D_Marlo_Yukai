/* Copyright 2006-2013 Speedgoat GmbH. */
#define         DEBUG                   (0x419+4771-0x16bc)
#define         S_FUNCTION_LEVEL        (0x1658+278-0x176c)
#undef          S_FUNCTION_NAME
#define         S_FUNCTION_NAME         sg_IO601_status_s
#include        <stddef.h>
#include        <stdlib.h>
#include        "tmwtypes.h"
#include        "simstruc.h" 
#ifdef          MATLAB_MEX_FILE
#include        "mex.h"
#endif
#ifndef         MATLAB_MEX_FILE
#include        <windows.h>
#include        "io_xpcimport.h"
#include        "pci_xpcimport.h"
#include        "time_xpcimport.h"
#include        "ioext_xpcimport.h"
#include        "util_xpcimport.h"
#endif
#define         zf1b619edf2                 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x36\x30\x31"
#define         z694756a014                (0x15a4+4016-0x149f)
#define         zea87e0ba83                36912
#define         z29146a1837             (0x1259+7107-0x1d67)
#define         zab7e64468b             10615
#define         zdf24515981          ((0x934+7494-0x2677))
#define         zbcb3e4d083              ssGetSFcnParam(S,(0x10af+802-0x13d1))
#define         z3832b85a32           ssGetSFcnParam(S,(0x852+2024-0x1039))
#define         z702a26a5e9                ssGetSFcnParam(S,(0x765+4407-0x189a))
#define         z2e6483d505              ((0x1f6c+1390-0x24d8))
#define         z57e55a08c5        ((0x1b64+1556-0x2178))
#define         z84eb1db314        ((0x679+634-0x8f2))
#define         zc5ce4cb81a              ((0x75f+7555-0x24e2))
#define         z2b17e2ee3b              ((0x4d7+6071-0x1c8e))
#ifndef MATLAB_MEX_FILE
#ifndef  zb84e0c3c3b
#define  zb84e0c3c3b(zc1d61b7d63)  *( (uint8_T *) &zc1d61b7d63)
#endif
#ifndef  z15e663b423
#define  z15e663b423(zc1d61b7d63)  *(((uint8_T *) &zc1d61b7d63) + (0x7f4+2418-0x1165))
#endif
#ifndef  zfca7eb6338
#define  zfca7eb6338(zc1d61b7d63)  *( (uint16_T *) &zc1d61b7d63)
#endif
#ifndef  z3607971cd6
#define  z3607971cd6(zc1d61b7d63)  *(((uint16_T *) &zc1d61b7d63) + (0x107d+1730-0x173e))
#endif
#ifndef z0056adfa94
#define z0056adfa94(zc1d61b7d63)       { uint8_T z7be9105675; z7be9105675 = z15e663b423(zc1d61b7d63); z15e663b423(zc1d61b7d63) = (uint8_T) zc1d61b7d63; zb84e0c3c3b(zc1d61b7d63) = z7be9105675; }
#endif
#ifndef z8444fc96d2
#define z8444fc96d2(zc1d61b7d63)       { uint16_T z7be9105675; z7be9105675 = z3607971cd6(zc1d61b7d63); z3607971cd6(zc1d61b7d63) = (uint16_T) zc1d61b7d63; zfca7eb6338(zc1d61b7d63) = z7be9105675; }
#endif
#endif
static char_T zea4cd01646[(0x121a+4575-0x22f9)];
#ifndef MATLAB_MEX_FILE
extern uint8_T z199556e987[];static uint32_T zaf39b56932(uint32_T id){z0056adfa94(z3607971cd6(id));z0056adfa94(zfca7eb6338(id));z8444fc96d2(id);id=id>>(0x146d+897-0x17d9);return id;}static uint32_T zdc2355eb74(uint32_T id){z0056adfa94(z3607971cd6(id));z0056adfa94(zfca7eb6338(id));z8444fc96d2(id);id=id>>(0x26d+1294-0x778);return id;}static unsigned char zf6c13379ed(double value,int n){unsigned char*p;p=(unsigned char*)&value;return p[n];}
#endif
static void mdlInitializeSizes(SimStruct*S){int_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x6c5+7477-0x23fa));ssSetNumDiscStates(S,(0x7e4+7253-0x2439));ssSetNumOutputPorts(S,(0xc4b+6553-0x25e3));ssSetOutputPortWidth(S,(0x14b4+3075-0x20b7),(0x16a3+1754-0x1d77));ssSetOutputPortDataType(S,(0x1775+2889-0x22be),SS_UINT16);ssSetNumInputPorts(S,(0x1654+3722-0x24de));ssSetNumSampleTimes(S,(0x31+1478-0x5f6));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,(0xe0+9243-0x24fb));ssSetNumModes(S,(0x2254+377-0x23cd));ssSetNumNonsampledZCs(S,(0x1668+805-0x198d));for(i=(0x1aec+2520-0x24c4);i<zdf24515981;i++){ssSetSFcnParamNotTunable(S,i);}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x206+7515-0x1f61),mxGetPr(z3832b85a32)[(0x11b8+2964-0x1d4c)]);if(mxGetN((z3832b85a32))==(0x1e00+1136-0x226f)){ssSetOffsetTime(S,(0x21d8+104-0x2240),0.0);}else{ssSetOffsetTime(S,(0x144b+300-0x1577),mxGetPr(z3832b85a32)[(0x10b3+1576-0x16da)]);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zef529fae4a,*zdfcb1da404;void*ze2370ae9b9,*zf2db5722bf;volatile uint32_T*z3e5b8e05d8;volatile uint8_T*z27fd94ac66;volatile uint32_T*z706da0e1e5;uint8_T zc369e1e9c6;zc369e1e9c6=(uint8_T)mxGetPr(zbcb3e4d083)[(0x5ff+4239-0x168e)]-(0x1907+171-0x19b1);if((int_T)mxGetPr(z702a26a5e9)[(0x540+5436-0x1a7c)]<(0x1537+4364-0x2643)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x1bcf+1181-0x206b)){z366b2f03bf=(0xc3b+5332-0x210f);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1220+387-0x13a3)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x786+2654-0x11e4)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x991+6976-0x24d0)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x9c6+5547-0x1e72))|((z366b2f03bf&(0x597+61-0x4d5))<<(0x1136+3838-0x202c)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zef529fae4a=(void*)zeccbadd9b3.BaseAddress[(0x699+4923-0x19d4)];ze2370ae9b9=rl32eGetDevicePtr(zef529fae4a,(0x2d8+4490-0x133a),RT_PG_USERREADWRITE);z3e5b8e05d8=(volatile uint32_T*)ze2370ae9b9;
zdfcb1da404=(void*)zeccbadd9b3.BaseAddress[(0xd83+3798-0x1c57)];zf2db5722bf=rl32eGetDevicePtr(zdfcb1da404,16384,RT_PG_USERREADWRITE);z27fd94ac66=(volatile uint8_T*)zf2db5722bf;z706da0e1e5=(volatile uint32_T*)zf2db5722bf;
ssSetIWorkValue(S,z57e55a08c5,(uint32_T)z3e5b8e05d8);ssSetIWorkValue(S,z84eb1db314,(uint32_T)z27fd94ac66);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
int_T i;uint16_T*y;uint16_T status[(0x527+2030-0xd0f)];uint32_T z44497d504e[(0x19cd+1218-0x1e8c)];uint8_T zc369e1e9c6=(uint8_T)mxGetPr(zbcb3e4d083)[(0xf11+4958-0x226f)]-(0x3f5+2296-0xcec);volatile uint32_T*z3e5b8e05d8;volatile uint32_T*z706da0e1e5;volatile uint8_T*z27fd94ac66;uint32_T z5d9c31c2b6=ssGetIWorkValue(S,z57e55a08c5);uint32_T z31a846515d=ssGetIWorkValue(S,z84eb1db314);z3e5b8e05d8=(void*)z5d9c31c2b6;z706da0e1e5=(void*)z31a846515d;z27fd94ac66=(void*)z31a846515d;z27fd94ac66[(0x25ca+1473-0xb8b)]=(0xfa4+3098-0x1bbe);if(z27fd94ac66[8192]!=(0x421+7887-0x22f0)){z27fd94ac66[(0x22ad+6064-0x1a5d)]=(0xad+503-0x2a3);
return;}for(i=(0x1384+131-0x1407);i<(0x50d+7413-0x21ff);i++){z44497d504e[i]=z706da0e1e5[(0xf4a+4167-0x1b95)+i];}z27fd94ac66[(0x2546+71-0x58d)]=(0x1a7d+356-0x1be0);memcpy(status,z44497d504e,(0x108d+4955-0x23dc));y=(uint16_T*)ssGetOutputPortSignal(S,(0xfb1+4533-0x2166));for(i=(0xbe0+3224-0x1878);i<(0x411+1372-0x967);i++){
y[i]=status[i];}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef  MATLAB_MEX_FILE    
#include "simulink.c"      
#else
#include "cg_sfun.h"       
#endif

