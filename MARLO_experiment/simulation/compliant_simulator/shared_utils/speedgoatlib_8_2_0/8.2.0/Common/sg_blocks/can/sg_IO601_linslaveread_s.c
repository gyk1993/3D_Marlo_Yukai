/* Copyright 2006-2013 Speedgoat GmbH. */
#define S_FUNCTION_LEVEL (0x1001+1106-0x1451)
#undef S_FUNCTION_NAME
#define S_FUNCTION_NAME sg_IO601_linslaveread_s
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
#define z694756a014               ((0x19ec+7038-0x24b5))
#define zea87e0ba83               (36912)
#define z29146a1837            ((0x13d6+120-0x399))
#define zab7e64468b            (10615)
#define zdf24515981         ((0x5c0+6939-0x20d7))
#define zbcb3e4d083             ssGetSFcnParam(S, (0x1f11+1768-0x25f9))
#define z8be821e1c6         ssGetSFcnParam(S, (0xe79+3680-0x1cd8))
#define z3832b85a32          ssGetSFcnParam(S, (0xa64+1331-0xf95))
#define z702a26a5e9               ssGetSFcnParam(S, (0x3f8+927-0x794))
#define z2e6483d505             ((0x481+8521-0x25c8))
#define z6a0da049de        ((0xfe4+5032-0x238c))
#define z4fc736908d       ((0x8b+997-0x46f))
#define zc5ce4cb81a             ((0xccf+793-0xfe8))
#define z2b17e2ee3b             ((0x14f9+1752-0x1bd1))
static char_T zea4cd01646[(0xa4d+6881-0x242e)];extern uint8_T ptrWritePointer[];extern uint8_T ptrReadPointer[];
#ifndef MATLAB_MEX_FILE
typedef struct z5d859c8e2d{uint8_T status;uint8_T count;uint8_T timeStamp[(0x1766+2543-0x2151)];uint8_T type;uint8_T z636e2cf3e0;uint8_T zf528bd284e;uint8_T z6fca5ff095;uint8_T checkSum;uint8_T z11f2a08c09;uint8_T length;uint8_T zdcc6ef6f12;uint8_T data[(0x9ba+1200-0xe62)];}z5d859c8e2d;static uint8_T z3c68e3f61b(SimStruct*S,uint32_T z31a846515d,uint8_T zc369e1e9c6,uint8_T*timestamp,uint8_T*data,uint8_T*id,uint8_T*length,uint8_T*checksum,uint8_T*type){uint8_T position;volatile z5d859c8e2d*z256cbcfc8b;if(!ptrReadPointer){sprintf(zea4cd01646,"\x4c\x53\x52\x20\x52\x65\x61\x64\x4c\x49\x4e\x42\x75\x66\x66\x65\x72\x3a\x20\x70\x74\x72\x52\x65\x61\x64\x50\x6f\x69\x6e\x74\x65\x72\x20\x69\x73\x20\x4e\x55\x4c\x4c" "\n");ssSetErrorStatus(S,zea4cd01646);return;}position=ptrReadPointer[zc369e1e9c6];
z256cbcfc8b=(z5d859c8e2d*)(z31a846515d+(0x17f4+239-0x497)+position*sizeof(z5d859c8e2d));if(z256cbcfc8b->status){
z256cbcfc8b->status=(0x27a+2733-0xd27);timestamp[(0x1dd+572-0x419)]=z256cbcfc8b->timeStamp[(0xc8f+4591-0x1e7e)];
timestamp[(0xbb6+397-0xd42)]=z256cbcfc8b->timeStamp[(0x2b7+8426-0x23a0)];timestamp[(0x16dd+2649-0x2134)]=z256cbcfc8b->timeStamp[(0x11a3+5292-0x264d)];timestamp[(0x604+1774-0xcef)]=z256cbcfc8b->timeStamp[(0x94c+2587-0x1364)];id[(0x154d+577-0x178e)]=z256cbcfc8b->zf528bd284e;
data[(0x1825+675-0x1ac8)]=z256cbcfc8b->data[(0x5a1+3500-0x134d)];
data[(0x12b2+3625-0x20da)]=z256cbcfc8b->data[(0x626+659-0x8b8)];data[(0x5a5+795-0x8be)]=z256cbcfc8b->data[(0x57c+4551-0x1741)];data[(0x443+8473-0x2559)]=z256cbcfc8b->data[(0x1a71+2745-0x2527)];data[(0xbf+6282-0x1945)]=z256cbcfc8b->data[(0x1b5+9321-0x261a)];data[(0x2cf+8896-0x258a)]=z256cbcfc8b->data[(0xd46+5260-0x21cd)];data[(0x105a+882-0x13c6)]=z256cbcfc8b->data[(0x1d7+416-0x371)];data[(0x1b6c+1276-0x2061)]=z256cbcfc8b->data[(0xd8b+166-0xe2a)];length[(0x1d71+1262-0x225f)]=z256cbcfc8b->length;
checksum[(0x927+3411-0x167a)]=z256cbcfc8b->checkSum;type[(0x132+6262-0x19a8)]=z256cbcfc8b->type;
position=(position==(0x100+259-0x1d2))?(0x16b1+1677-0x1d3e):++position;ptrReadPointer[zc369e1e9c6]=position;return(0xef5+2296-0x17ec);}else{
return(0x12d+690-0x3df);}}
#endif
static void mdlInitializeSizes(SimStruct*S){int_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x81+1792-0x781));ssSetNumDiscStates(S,(0xfec+1846-0x1722));
ssSetNumInputPorts(S,(0x1e1f+870-0x2185));ssSetNumOutputPorts(S,(0x1dc1+1986-0x2576));ssSetOutputPortDataType(S,(0x1cd3+2206-0x2571),SS_UINT8);ssSetOutputPortWidth(S,(0x49f+7558-0x2225),(uint32_T)mxGetPr(z8be821e1c6)[(0x1af3+109-0x1b60)]);ssSetOutputPortDataType(S,(0x146c+4463-0x25da),SS_UINT8);ssSetOutputPortWidth(S,(0xd35+4596-0x1f28),(uint32_T)mxGetPr(z8be821e1c6)[(0x177c+1179-0x1c17)]);ssSetOutputPortDataType(S,(0x1218+5157-0x263b),SS_UINT8);ssSetOutputPortWidth(S,(0x162a+1925-0x1dad),(uint32_T)mxGetPr(z8be821e1c6)[(0x14f8+1776-0x1be8)]);ssSetOutputPortDataType(S,(0x21c+6082-0x19db),SS_UINT8);ssSetOutputPortWidth(S,(0x115c+317-0x1296),(uint32_T)mxGetPr(z8be821e1c6)[(0x164f+2424-0x1fc7)]);ssSetOutputPortDataType(S,(0x2c5+6337-0x1b82),SS_UINT8);ssSetOutputPortWidth(S,(0x1a96+744-0x1d7a),(uint32_T)mxGetPr(z8be821e1c6)[(0x926+7119-0x24f5)]);ssSetOutputPortDataType(S,(0x328+1214-0x7e1),SS_UINT8);ssSetOutputPortWidth(S,(0xb71+4729-0x1de5),(uint32_T)mxGetPr(z8be821e1c6)[(0x51d+5258-0x19a7)]);ssSetOutputPortDataType(S,(0x83f+6026-0x1fc3),SS_UINT8);ssSetOutputPortWidth(S,(0x1bf1+93-0x1c48),(uint32_T)mxGetPr(z8be821e1c6)[(0x1e31+241-0x1f22)]);ssSetOutputPortDataType(S,(0xa84+7213-0x26aa),SS_UINT8);ssSetOutputPortWidth(S,(0xa75+1473-0x102f),(uint32_T)mxGetPr(z8be821e1c6)[(0x189a+1011-0x1c8d)]);ssSetOutputPortDataType(S,(0xd39+1863-0x1478),SS_UINT8);ssSetOutputPortWidth(S,(0x722+1899-0xe85),(uint32_T)mxGetPr(z8be821e1c6)[(0xc84+1828-0x13a8)]);ssSetOutputPortDataType(S,(0xca6+5919-0x23bc),SS_UINT8);ssSetOutputPortWidth(S,(0x54a+509-0x73e),(uint32_T)mxGetPr(z8be821e1c6)[(0x566+4193-0x15c7)]);ssSetOutputPortDataType(S,(0x330+9116-0x26c2),SS_UINT32);ssSetOutputPortWidth(S,(0x1e6+3536-0xfac),(uint32_T)mxGetPr(z8be821e1c6)[(0x8c4+4344-0x19bc)]);ssSetOutputPortDataType(S,(0x1297+1992-0x1a54),SS_UINT8);ssSetOutputPortWidth(S,(0x812+4133-0x182c),(uint32_T)mxGetPr(z8be821e1c6)[(0x14f7+1680-0x1b87)]);ssSetOutputPortDataType(S,(0x31f+8319-0x2392),SS_UINT8);ssSetOutputPortWidth(S,(0xdbb+6195-0x25e2),(uint32_T)mxGetPr(z8be821e1c6)[(0x1b34+1314-0x2056)]);ssSetNumSampleTimes(S,(0x85f+4954-0x1bb8));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,(0xc77+6593-0x2638));ssSetNumModes(S,(0xdb3+3612-0x1bcf));ssSetNumNonsampledZCs(S,(0x1351+1553-0x1962));for(i=(0xb67+3307-0x1852);i<zdf24515981;i++){ssSetSFcnParamNotTunable(S,i);}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x930+6538-0x22ba),mxGetPr(z3832b85a32)[(0x14a1+1576-0x1ac9)]);if(mxGetN((z3832b85a32))==(0x24b7+435-0x2669)){ssSetOffsetTime(S,(0x1283+1301-0x1798),0.0);}else{ssSetOffsetTime(S,(0x1378+1897-0x1ae1),mxGetPr(z3832b85a32)[(0x11ef+4632-0x2406)]);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x9a2+5593-0x1f7a)){z366b2f03bf=(0x315+8434-0x2407);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xff+5068-0x14cb)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x15d7+1268-0x1acb)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xe54+5082-0x222d)];}if(xpcGetPCIDeviceInfo((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x4c\x53\x52\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}rl32eWaitDouble(0.05);
zeccbadd9b3.VirtAddress[(0x106d+656-0x12fb)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x1e98+1663-0x2515)],zeccbadd9b3.Length[(0x1363+597-0x15b6)],XPC_RT_PG_USERREADWRITE);zeccbadd9b3.VirtAddress[(0x171b+1640-0x1d83)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0xde6+2072-0x15fe)],zeccbadd9b3.Length[(0x1c38+1958-0x23de)],XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0xf61+5620-0x2553)]);ssSetIWorkValue(S,z4fc736908d,zeccbadd9b3.VirtAddress[(0xab7+2919-0x161e)]);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint8_T*out;uint32_T*z126ed5de63;uint32_T i;uint8_T id;uint8_T length;uint8_T data[(0x127c+2639-0x1cc3)];uint8_T timestamp[(0xdb0+4066-0x1d8e)];uint8_T checksum;uint8_T type;uint8_T status;volatile uint32_T*z3e5b8e05d8;uint32_T zc1ac25c1d6;uint8_T zc369e1e9c6;uint32_T z5d9c31c2b6=ssGetIWorkValue(S,z4fc736908d);uint32_T z31a846515d=ssGetIWorkValue(S,z6a0da049de);z3e5b8e05d8=(void*)z5d9c31c2b6;zc369e1e9c6=(uint8_T)mxGetPr(zbcb3e4d083)[(0xa3a+6996-0x258e)]-(0x102+5008-0x1491);
for(i=(0x1e58+1152-0x22d8);i<(uint32_T)mxGetPr(z8be821e1c6)[(0xe67+2272-0x1747)];i++){out=(uint8_T*)ssGetOutputPortSignal(S,(0x15c7+2413-0x1f34));out[i]=(0x1012+3397-0x1d57);out=(uint8_T*)ssGetOutputPortSignal(S,(0x375+1690-0xa0e));out[i]=(0x1140+437-0x12f5);out=(uint8_T*)ssGetOutputPortSignal(S,(0x847+4055-0x181c));out[i]=(0x1844+2022-0x202a);out=(uint8_T*)ssGetOutputPortSignal(S,(0x8a8+1752-0xf7d));out[i]=(0xe38+4723-0x20ab);out=(uint8_T*)ssGetOutputPortSignal(S,(0x1bd0+2521-0x25a5));out[i]=(0xb3f+6802-0x25d1);out=(uint8_T*)ssGetOutputPortSignal(S,(0x14d0+620-0x1737));out[i]=(0xc4d+2241-0x150e);out=(uint8_T*)ssGetOutputPortSignal(S,(0x12c6+3214-0x1f4e));out[i]=(0x1724+2710-0x21ba);out=(uint8_T*)ssGetOutputPortSignal(S,(0xe5c+2020-0x1639));out[i]=(0xc74+3382-0x19aa);out=(uint8_T*)ssGetOutputPortSignal(S,(0x19ca+2057-0x21cb));out[i]=(0xa1a+433-0xbcb);out=(uint8_T*)ssGetOutputPortSignal(S,(0x215f+535-0x236d));out[i]=(0x85d+1223-0xd24);z126ed5de63=(uint32_T*)ssGetOutputPortSignal(S,(0x2523+480-0x26f9));z126ed5de63[i]=(0x1b85+185-0x1c3e);out=(uint8_T*)ssGetOutputPortSignal(S,(0x5ed+6382-0x1ed0));out[i]=(0x182f+2394-0x2189);out=(uint8_T*)ssGetOutputPortSignal(S,(0x1ec6+316-0x1ff6));out[i]=(0x13e8+3655-0x222f);}for(i=(0xc96+2426-0x1610);i<(uint32_T)mxGetPr(z8be821e1c6)[(0x7fc+3112-0x1424)];i++){
status=z3c68e3f61b(S,z31a846515d,zc369e1e9c6,timestamp,data,&id,&length,&checksum,&type);if(status==(0x2094+138-0x211d)){out=(uint8_T*)ssGetOutputPortSignal(S,(0x189c+896-0x1c1c));out[i]=id&(0x3d2+8263-0x23da);
out=(uint8_T*)ssGetOutputPortSignal(S,(0x8ac+360-0xa13));out[i]=length;out=(uint8_T*)ssGetOutputPortSignal(S,(0x206+8139-0x21cf));out[i]=data[(0x1256+3358-0x1f74)];out=(uint8_T*)ssGetOutputPortSignal(S,(0x26bb+61-0x26f5));out[i]=data[(0x15f+7513-0x1eb7)];out=(uint8_T*)ssGetOutputPortSignal(S,(0x164+4741-0x13e5));out[i]=data[(0x5bd+8472-0x26d3)];out=(uint8_T*)ssGetOutputPortSignal(S,(0x754+1268-0xc43));out[i]=data[(0x5b6+3119-0x11e2)];out=(uint8_T*)ssGetOutputPortSignal(S,(0x5a5+556-0x7cb));out[i]=data[(0x111c+2387-0x1a6b)];out=(uint8_T*)ssGetOutputPortSignal(S,(0xcba+3852-0x1bbf));out[i]=data[(0xe95+1081-0x12c9)];out=(uint8_T*)ssGetOutputPortSignal(S,(0x4c7+5292-0x196b));out[i]=data[(0x6d6+2012-0xeac)];out=(uint8_T*)ssGetOutputPortSignal(S,(0x91f+4020-0x18ca));out[i]=data[(0x1bd+8824-0x242e)];z126ed5de63=(uint32_T*)ssGetOutputPortSignal(S,(0x425+5058-0x17dd));z126ed5de63[i]=timestamp[(0x1023+2590-0x1a41)]|(timestamp[(0x707+4106-0x1710)]<<(0x16c8+1754-0x1d9a))|(timestamp[(0x1631+3250-0x22e1)]<<(0x17ea+2447-0x2169))|(timestamp[(0x924+5414-0x1e49)]<<(0x479+469-0x636));out=(uint8_T*)ssGetOutputPortSignal(S,(0xc70+2189-0x14f2));out[i]=checksum;out=(uint8_T*)ssGetOutputPortSignal(S,(0x1390+835-0x16c7));out[i]=type;}else{
break;}}
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

