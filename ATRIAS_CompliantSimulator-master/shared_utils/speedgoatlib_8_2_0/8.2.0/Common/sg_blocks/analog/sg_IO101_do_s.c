/* Copyright 2006-2013 Speedgoat GmbH. */
#define         S_FUNCTION_LEVEL        (0x11e5+934-0x1589)
#undef          S_FUNCTION_NAME
#define         S_FUNCTION_NAME         sg_IO101_do_s
#include        <stddef.h>
#include        <stdlib.h>
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
#define zdf24515981          ((0x4f7+7836-0x238a))
#define z942d41a49c        ssGetSFcnParam(S,(0xc33+1961-0x13dc)) 
#define z0cf2e207bc        ssGetSFcnParam(S,(0x648+586-0x891))
#define z7bf3bce264        ssGetSFcnParam(S,(0x1b4b+497-0x1d3a))
#define z871352ca17          ssGetSFcnParam(S,(0x12f7+3754-0x219e))
#define zb34d68df21          ssGetSFcnParam(S,(0x228+9342-0x26a2))
#define z4464f2b915           ssGetSFcnParam(S,(0x1358+1630-0x19b1))
#define zfd0a35e5cb           ssGetSFcnParam(S,(0x181+7991-0x20b2))
#define z3832b85a32           ssGetSFcnParam(S,(0xd4d+1416-0x12ce))
#define z702a26a5e9                ssGetSFcnParam(S,(0x567+7461-0x2284))
#define z2e6483d505              ((0x4ec+8294-0x2551))
#define z6a0da049de         ((0x5b+91-0xb6))
#define zc5ce4cb81a              ((0x1b06+2931-0x2679))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0xdcf+6087-0x2496)];static void mdlInitializeSizes(SimStruct*S){int i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x41+96-0xa1));ssSetNumDiscStates(S,(0x1190+1886-0x18ee));if((uint32_T)mxGetPr(z942d41a49c)[(0xc2f+4223-0x1cae)]==(0x1adf+2410-0x2448)){ssSetNumInputPorts(S,mxGetN(z0cf2e207bc));for(i=(0xebc+5844-0x2590);i<mxGetN(z0cf2e207bc);i++){ssSetInputPortWidth(S,i,(0x1e09+1618-0x245a));ssSetInputPortDirectFeedThrough(S,i,(0xcc9+2374-0x160e));ssSetInputPortDataType(S,i,SS_DOUBLE);ssSetInputPortRequiredContiguous(S,i,(0x17c4+2368-0x2103));}}else{ssSetNumInputPorts(S,mxGetN(z7bf3bce264));for(i=(0x22b+6107-0x1a06);i<mxGetN(z7bf3bce264);i++){ssSetInputPortWidth(S,i,(0x2172+275-0x2284));ssSetInputPortDirectFeedThrough(S,i,(0x1c49+87-0x1c9f));ssSetInputPortDataType(S,i,SS_DOUBLE);ssSetInputPortRequiredContiguous(S,i,(0xeb7+1938-0x1648));}}ssSetNumOutputPorts(S,(0x96f+7011-0x24d2));ssSetNumSampleTimes(S,(0x1043+3508-0x1df6));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,(0x1fe2+1827-0x2705));ssSetNumModes(S,(0x1490+181-0x1545));ssSetNumNonsampledZCs(S,(0xe6+6830-0x1b94));for(i=(0x85b+6080-0x201b);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x22d+7691-0x2038));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x1c7c+1027-0x207f)]==-1.0){ssSetSampleTime(S,(0x762+2515-0x1135),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x176+9245-0x2593),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x7a8+392-0x930),mxGetPr(z3832b85a32)[(0xae8+4291-0x1bab)]);ssSetOffsetTime(S,(0x20e8+230-0x21ce),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;int_T base;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;int_T z049b04bd7f,z3b7a4946fb;char_T zda7b5a7e16[(0xc1b+1115-0x1058)];int_T z0add1d1c25;int_T z2b835486be;uint32_T zfff46c32bd;z049b04bd7f=5845;z3b7a4946fb=17495;strcpy(zda7b5a7e16,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x30\x31");if((int_T)mxGetPr(z702a26a5e9)[(0x1294+3115-0x1ebf)]<(0x42f+1281-0x930)){
if(rl32eGetPCIInfo((unsigned short)z049b04bd7f,(unsigned short)z3b7a4946fb,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zda7b5a7e16);ssSetErrorStatus(S,zea4cd01646);return;}}else{int_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x155b+3986-0x24ec)){z366b2f03bf=(0x14+9919-0x26d3);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x164+483-0x347)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x96f+6545-0x2300)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x292+8805-0x24f6)];}
if(rl32eGetPCIInfoAtSlot((unsigned short)z049b04bd7f,(unsigned short)z3b7a4946fb,(z441f9e6d1b&(0x1300+3620-0x2025))|((z366b2f03bf&(0x506+668-0x6a3))<<(0x27a+3004-0xe2e)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zda7b5a7e16,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x224+2545-0xc15)];Virtual=rl32eGetDevicePtr(z1cf2c50191,4096,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;int_T i;uint_T z718c4c15f4,z4e3026977c;uint32_T data;real_T*zc7fdaf6331;za42cf7dd4a=(void*)base;data=za42cf7dd4a[(0xb62+3937-0x1ab5)];if((uint32_T)mxGetPr(z942d41a49c)[(0x16db+1515-0x1cc6)]==(0x14f1+2461-0x1e8d)){data&=4294967040;
z718c4c15f4=(0x16f7+3883-0x2622);for(i=(0x151d+1839-0x1c4c);i<mxGetN(z0cf2e207bc);i++){z4e3026977c=(uchar_T)mxGetPr(z0cf2e207bc)[i]-(0x67+400-0x1f6);zc7fdaf6331=(real_T*)ssGetInputPortRealSignal(S,i);if(zc7fdaf6331[(0xf22+880-0x1292)]>=THRESHOLD){z718c4c15f4|=(0x48f+8307-0x2501)<<z4e3026977c;}}

za42cf7dd4a[(0x18bf+273-0x19c2)]=data|z718c4c15f4;}else{data&=4294902015;z718c4c15f4=(0x210b+233-0x21f4);for(i=(0xc8c+4165-0x1cd1);i<mxGetN(z7bf3bce264);i++){z4e3026977c=(uchar_T)mxGetPr(z7bf3bce264)[i]-(0xc43+6182-0x2468);zc7fdaf6331=(real_T*)ssGetInputPortRealSignal(S,i);if(zc7fdaf6331[(0x1aec+1959-0x2293)]>=THRESHOLD){z718c4c15f4|=(0x89f+5819-0x1f59)<<z4e3026977c;}}za42cf7dd4a[(0x1163+1509-0x173a)]=data|(z718c4c15f4<<(0x239c+167-0x243b));}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T i;volatile uint32_T*za42cf7dd4a;real_T out;uint32_T z4e3026977c;uint32_T z718c4c15f4,data;za42cf7dd4a=(void*)base;z718c4c15f4=(0x745+3106-0x1367);data=za42cf7dd4a[(0x48b+7104-0x203d)];if((uint32_T)mxGetPr(z942d41a49c)[(0x95f+5086-0x1d3d)]==(0x8c+1563-0x6a6)){data&=4294967040;for(i=(0x441+7834-0x22db);i<mxGetN(z0cf2e207bc);i++){if(xpceIsModelInit()||(int)mxGetPr(z871352ca17)[i]){z4e3026977c=(uint32_T)mxGetPr(z0cf2e207bc)[i]-(0xc5a+110-0xcc7);out=(real_T)mxGetPr(z4464f2b915)[i];if(out>=THRESHOLD){z718c4c15f4|=(0x100+6740-0x1b53)<<z4e3026977c;}}}za42cf7dd4a[(0x916+454-0xace)]=data|z718c4c15f4;}else{data&=4294902015;for(i=(0x578+4994-0x18fa);i<mxGetN(z7bf3bce264);i++){if(xpceIsModelInit()||(int)mxGetPr(zb34d68df21)[i]){z4e3026977c=(uint32_T)mxGetPr(z7bf3bce264)[i]-(0xf14+1545-0x151c);out=(real_T)mxGetPr(zfd0a35e5cb)[i];if(out>=THRESHOLD){z718c4c15f4|=(0x1ced+2088-0x2514)<<z4e3026977c;}}}za42cf7dd4a[(0x338+8626-0x24dc)]=data|(z718c4c15f4<<(0xa0a+1503-0xfe1));}
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

