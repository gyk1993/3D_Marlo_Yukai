/* Copyright 2006-2013 Speedgoat GmbH. */
#define S_FUNCTION_LEVEL (0xa35+3347-0x1746)
#undef S_FUNCTION_NAME
#define S_FUNCTION_NAME sg_IO601_write_s_3
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
#define z694756a014               ((0x1564+4573-0x168c))
#define zea87e0ba83               (36912)
#define z29146a1837            ((0x1947+4764-0x1b2e))
#define zab7e64468b            (10615)
#define zdf24515981         ((0x20f+7387-0x1ee1))
#define zbcb3e4d083             ssGetSFcnParam(S,(0x11bc+5122-0x25be))
#define z11e8538834             ssGetSFcnParam(S,(0x1313+5073-0x26e3))
#define zfdec0918ff   ssGetSFcnParam(S,(0xd71+5882-0x2469))
#define z1de802f68c             ssGetSFcnParam(S,(0x1b18+1563-0x2130))
#define z9cd34e3860               ssGetSFcnParam(S,(0x1a67+1530-0x205d))
#define zd39abcef8f           ssGetSFcnParam(S,(0x327+424-0x4ca))
#define zdfab922aba           ssGetSFcnParam(S,(0xe2+998-0x4c2))
#define z3832b85a32          ssGetSFcnParam(S,(0x1141+5040-0x24ea))
#define z702a26a5e9               ssGetSFcnParam(S,(0xf4+5706-0x1736))
#define z2e6483d505             ((0x102c+1086-0x1466))
#define z6a0da049de        ((0x80+8221-0x209d))
#define z4fc736908d       ((0x1258+2110-0x1a95))
#define z23d4f5073f             ((0x5bf+2736-0x106d))
#define z7a85c5de9b             ((0x6ad+7682-0x24ac))
#define zc5ce4cb81a             ((0x227d+86-0x22d3))
#define z2b17e2ee3b             ((0x328+743-0x60f))
static char_T zea4cd01646[(0x18c9+376-0x1941)];extern uint8_T ptrWritePointer1[];extern uint8_T ptrWritePointer2[];typedef struct{uint8_T z1fde0a5efd;uint8_T Length;uint8_T ze0cf853226;uint8_T Error;int32_T ID;double Timestamp;uint8_T Data[(0x6c4+1734-0xd82)];}z80857f1537;typedef struct z5d859c8e2d{uint32_T z9b71add2e2[(0x17a+475-0x350)];}z5d859c8e2d;
#ifndef MATLAB_MEX_FILE
static uint32_T za85eba763d(uint32_T id,uint32_T z81f62ac42b){uint32_T ze52982b20e;ze52982b20e=(id<<((0xd15+1819-0x1410)-z81f62ac42b));ze52982b20e=(uint32_T)(((ze52982b20e&(0x1802+1198-0x1bb1))<<(0x2316+877-0x266b))+((ze52982b20e&65280)<<(0x8e1+4591-0x1ac8))+((ze52982b20e&16711680)>>(0xa23+6199-0x2252))+((ze52982b20e&4278190080)>>(0xec9+280-0xfc9)));return ze52982b20e;}static uint8_T zffbcd1020c(z80857f1537 message,z5d859c8e2d*z256cbcfc8b){uint8_T status,nBytes,z636e2cf3e0;uint16_T z0aed4f7bfc;uint32_T z30a684c1d7;status=z256cbcfc8b->z9b71add2e2[(0x1939+1412-0x1ebd)]&(0x896+1298-0xca9);if(status==(0xe09+2032-0x15f9))
{if(message.z1fde0a5efd){status=(0xb18+667-0xdb2);nBytes=(0x3bd+1905-0xb24)+message.Length;z636e2cf3e0=message.Length|(message.ze0cf853226<<(0x265+2145-0xac0))|(message.z1fde0a5efd<<(0x1dc8+1087-0x2200));z30a684c1d7=za85eba763d(message.ID,(0xa19+1689-0x1095));z256cbcfc8b->z9b71add2e2[(0x2b6+7376-0x1f85)]=(z636e2cf3e0<<(0x1b67+1457-0x2100));z256cbcfc8b->z9b71add2e2[(0x105+8462-0x2211)]=(z30a684c1d7);z256cbcfc8b->z9b71add2e2[(0x565+7964-0x247e)]=(message.Data[(0xaed+548-0xd0e)]<<(0xe8+20-0xe4))|(message.Data[(0xfb8+664-0x124e)]<<(0x54c+3269-0x1201))|(message.Data[(0x1a05+1190-0x1eaa)]<<(0x9d3+2340-0x12ef))|message.Data[(0x978+7236-0x25bc)];z256cbcfc8b->z9b71add2e2[(0xa23+5744-0x208f)]=(message.Data[(0x135+2210-0x9d0)]<<(0x1740+1409-0x1ca9))|(message.Data[(0xd02+6529-0x267d)]<<(0x7fb+2430-0x1169))|(message.Data[(0x203+7816-0x2086)]<<(0xec+3009-0xca5))|message.Data[(0x1958+2170-0x21ce)];z256cbcfc8b->z9b71add2e2[(0x1296+1623-0x18ed)]=(nBytes<<(0xa79+3911-0x19b8))|(status);}else{status=(0x178+7140-0x1d5b);nBytes=(0x130b+4027-0x22be)+message.Length;z636e2cf3e0=(message.Length)|(message.ze0cf853226<<(0x1993+2329-0x22a6))|(message.z1fde0a5efd<<(0xc55+314-0xd88));z0aed4f7bfc=za85eba763d(message.ID,(0x75+8308-0x20de));z256cbcfc8b->z9b71add2e2[(0x217+285-0x333)]=(z636e2cf3e0<<(0x745+7006-0x228b));z256cbcfc8b->z9b71add2e2[(0x229+2673-0xc98)]=(message.Data[(0x531+2733-0xfdd)]<<(0x5c0+4219-0x1623))|(message.Data[(0x1cd+6805-0x1c62)]<<(0xdda+4015-0x1d79))|z0aed4f7bfc;z256cbcfc8b->z9b71add2e2[(0xd84+3815-0x1c68)]=(message.Data[(0x6eb+589-0x933)]<<(0xe8+512-0x2d0))|(message.Data[(0x132+7764-0x1f82)]<<(0x286+6187-0x1aa1))|(message.Data[(0x5a3+3607-0x13b7)]<<(0x918+4400-0x1a40))|message.Data[(0x6cb+6475-0x2014)];z256cbcfc8b->z9b71add2e2[(0xf5f+5554-0x250d)]=(message.Data[(0x2095+1373-0x25eb)]<<(0xdf1+6132-0x25dd))|message.Data[(0xb1d+1298-0x1029)];z256cbcfc8b->z9b71add2e2[(0xe99+5800-0x2541)]=(nBytes<<(0xd37+1753-0x1408))|(status);}return(0xc82+6329-0x253a);}else{return(0x1e72+1803-0x257d);}}static int8_T z50a448c4af(SimStruct*S,int32_T z0add1d1c25,z80857f1537 message){int32_T z563e4da9f6,position;z5d859c8e2d*z256cbcfc8b;uint32_T base;base=ssGetIWorkValue(S,z6a0da049de);z563e4da9f6=(0x570+4939-0x18bb);if(z0add1d1c25!=(0x20e5+820-0x2418)&&z0add1d1c25!=(0xd8f+6405-0x2692)){z563e4da9f6=-(0x3a0+8484-0x24ba);}switch(message.z1fde0a5efd){case(0x1b03+140-0x1b8f):if(message.ID>(0xba1+7937-0x22a3)){z563e4da9f6=-(0x5b3+3216-0x1237);
}break;case(0xb46+6012-0x22c1):if(message.ID>536870911){z563e4da9f6=-(0x56b+7765-0x23b3);
}break;default:z563e4da9f6=-(0xff6+369-0x115c);
break;}if(message.Length>(0x8db+7259-0x252e)){z563e4da9f6=-(0x15d1+4229-0x2648);}if(z563e4da9f6==(0xbd6+288-0xcf6)&&message.ID>=(0x5b4+1950-0xd52)){if(z0add1d1c25==(0x406+6164-0x1c19)){position=ptrWritePointer1[(uint32_T)mxGetPr(zbcb3e4d083)[(0x327+7539-0x209a)]-(0x1741+142-0x17ce)];
z256cbcfc8b=(z5d859c8e2d*)(base+(0xc31+2274-0x14c3)+position*sizeof(z5d859c8e2d));}else{position=ptrWritePointer2[(uint32_T)mxGetPr(zbcb3e4d083)[(0x70b+476-0x8e7)]-(0x687+1032-0xa8e)];
z256cbcfc8b=(z5d859c8e2d*)(base+(0x1725+1424-0x187d)+position*sizeof(z5d859c8e2d));}if(zffbcd1020c(message,z256cbcfc8b)){position=(position==(0x26d+518-0x442))?(0x136d+4816-0x263d):++position;if(z0add1d1c25==(0x1155+4988-0x24d0)){ptrWritePointer1[(uint32_T)mxGetPr(zbcb3e4d083)[(0xff8+2838-0x1b0e)]-(0x1687+2877-0x21c3)]=position;}else{ptrWritePointer2[(uint32_T)mxGetPr(zbcb3e4d083)[(0x98f+4423-0x1ad6)]-(0x4f0+418-0x691)]=position;}}else{z563e4da9f6=-(0x2c0+1436-0x85b);}}return z563e4da9f6;}
#endif
static void mdlInitializeSizes(SimStruct*S){int_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x273+4955-0x15ce));ssSetNumDiscStates(S,(0x1ef0+120-0x1f68));
if((int_T)mxGetPr(zfdec0918ff)[(0xa29+1220-0xeed)]==(0x79d+561-0x9cd)){ssSetNumInputPorts(S,(0x2f3+6672-0x1d02));ssSetInputPortDirectFeedThrough(S,(0xbe5+6637-0x25d2),(0xcb3+1800-0x13ba));ssSetInputPortRequiredContiguous(S,(0x2077+732-0x2353),(0x320+1372-0x87b));if(!ssSetInputPortMatrixDimensions(S,(0x1df3+1089-0x2234),DYNAMICALLY_SIZED,DYNAMICALLY_SIZED))return;}else{
ssSetNumInputPorts(S,(0x1f91+410-0x2129));ssSetInputPortWidth(S,(0x11e0+4798-0x249e),(uint32_T)mxGetPr(z1de802f68c)[(0x1ab4+2882-0x25f6)]);ssSetInputPortDirectFeedThrough(S,(0x410+6729-0x1e59),(0x58b+5928-0x1cb2));ssSetInputPortRequiredContiguous(S,(0x1da+6565-0x1b7f),(0x20ff+644-0x2382));ssSetInputPortWidth(S,(0xbd0+4211-0x1c42),(0x2ea+3513-0x10a2));ssSetInputPortDirectFeedThrough(S,(0x19c+8749-0x23c8),(0x1b26+39-0x1b4c));ssSetInputPortRequiredContiguous(S,(0x538+8274-0x2589),(0x14cf+4198-0x2534));
#ifdef MATLAB_MEX_FILE   
{int_T z9dc9623fa2,status;DTypeId id;z80857f1537 z52754d10b7;id=ssRegisterDataType(S,"\x43\x41\x4e\x5f\x4d\x45\x53\x53\x41\x47\x45");if(id==INVALID_DTYPE_ID)return;status=ssSetDataTypeSize(S,id,sizeof(z52754d10b7));ssSetInputPortDataType(S,(0x2+9495-0x2519),id);}
#endif 		
}if((int_T)mxGetPr(z11e8538834)[(0x630+626-0x8a2)]&&(int_T)mxGetPr(zfdec0918ff)[(0x1269+4264-0x2311)]==(0x7f+5223-0x14e5)){ssSetNumOutputPorts(S,(0x74+8964-0x2377));ssSetOutputPortWidth(S,(0x1568+1003-0x1953),DYNAMICALLY_SIZED);}else if((int_T)mxGetPr(z11e8538834)[(0x751+6188-0x1f7d)]&&(int_T)mxGetPr(zfdec0918ff)[(0x129a+2086-0x1ac0)]==(0x13d1+3735-0x2266)){ssSetNumOutputPorts(S,(0x736+4806-0x19fb));ssSetOutputPortWidth(S,(0x157a+3558-0x2360),(uint32_T)mxGetPr(z1de802f68c)[(0xd45+1012-0x1139)]);}else{ssSetNumOutputPorts(S,(0xf02+3196-0x1b7e));}ssSetNumSampleTimes(S,(0x2d9+8540-0x2434));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,(0x956+4136-0x197e));ssSetNumModes(S,(0x1b+6935-0x1b32));ssSetNumNonsampledZCs(S,(0xd05+5892-0x2409));for(i=(0x60c+376-0x784);i<zdf24515981;i++){ssSetSFcnParamNotTunable(S,i);}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}
#define z66116822c9
static void mdlSetInputPortDimensionInfo(SimStruct*S,int zb9276e93a2,const DimsInfo_T*zde3f224951){if((int_T)mxGetPr(zfdec0918ff)[(0x90f+5668-0x1f33)]==(0x1211+3449-0x1f89)){if(zde3f224951->dims[(0xb13+6769-0x2583)]!=(0x7d1+2159-0x103b)&&zde3f224951->dims[(0x28d+1704-0x934)]!=(0x50c+3887-0x1435)){sprintf(zea4cd01646,"\x49\x6e\x70\x75\x74\x20\x6d\x75\x73\x74\x20\x62\x65\x20\x61\x20\x6d\x2a\x35\x20\x6f\x72\x20\x61\x20\x6d\x2a\x36\x20\x20\x6d\x61\x74\x72\x69\x78");ssSetErrorStatus(S,zea4cd01646);return;}if(!ssSetInputPortDimensionInfo(S,zb9276e93a2,zde3f224951))return;if((int_T)mxGetPr(z11e8538834)[(0xfe3+2874-0x1b1d)]){if(!ssSetOutputPortVectorDimension(S,(0x3cf+959-0x78e),zde3f224951->dims[(0x6fa+1530-0xcf4)]))return;}}else{if(!ssSetInputPortDimensionInfo(S,zb9276e93a2,zde3f224951))return;if((int_T)mxGetPr(z11e8538834)[(0xa5c+3668-0x18b0)]){if(!ssSetOutputPortVectorDimension(S,(0x53c+3587-0x133f),zde3f224951->dims[(0xf99+3198-0x1c17)]))return;}}}
#define z12b5c990f1
static void mdlSetOutputPortDimensionInfo(SimStruct*S,int zb9276e93a2,const DimsInfo_T*zde3f224951){if(!ssSetOutputPortDimensionInfo(S,zb9276e93a2,zde3f224951))return;}
#define z4fd520fcfe
static void mdlSetDefaultPortDimensionInfo(SimStruct*S){if((int_T)mxGetPr(zfdec0918ff)[(0x17e2+535-0x19f9)]==(0x239+7638-0x200e)){if(!ssSetInputPortMatrixDimensions(S,(0xc22+5553-0x21d3),(0xed6+5810-0x2587),(0x157b+1069-0x19a3)))return;if((int_T)mxGetPr(z11e8538834)[(0xbb5+2418-0x1527)]){if(!ssSetOutputPortVectorDimension(S,(0x17b9+9-0x17c2),(0x1eb0+1196-0x235b)))return;}}}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0xb0f+2572-0x151b),mxGetPr(z3832b85a32)[(0x3a3+6256-0x1c13)]);if(mxGetN((z3832b85a32))==(0x87d+1892-0xfe0)){ssSetOffsetTime(S,(0xb11+5693-0x214e),0.0);}else{ssSetOffsetTime(S,(0xf64+4649-0x218d),mxGetPr(z3832b85a32)[(0x1ed7+1189-0x237b)]);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;z80857f1537 message;int32_T z563e4da9f6;int32_T i,z26dbd73a5e,m;int_T z0add1d1c25,start;uint8_T data[(0x105+6996-0x1c51)];uint8_T length;volatile uint32_T*z3e5b8e05d8;uint32_T zc1ac25c1d6;if(mxGetN(z702a26a5e9)==(0x1755+1739-0x1e1f)){z366b2f03bf=(0x4b6+4047-0x1485);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xa34+6381-0x2321)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0xfd2+4091-0x1fcd)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x2b5+9093-0x2639)];}if(xpcGetPCIDeviceInfo((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x3ac+1740-0xa76)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0xdad+5313-0x226c)],zeccbadd9b3.Length[(0x3e1+2847-0xefe)],XPC_RT_PG_USERREADWRITE);zeccbadd9b3.VirtAddress[(0x996+3027-0x1569)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x24d+7792-0x20bd)],zeccbadd9b3.Length[(0xc56+463-0xe25)],XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x1c9+364-0x333)]);ssSetIWorkValue(S,z4fc736908d,zeccbadd9b3.VirtAddress[(0x4d3+6801-0x1f64)]);ssSetIWorkValue(S,z23d4f5073f,(0xaba+167-0xb61));ssSetIWorkValue(S,z7a85c5de9b,(0x7cc+7240-0x2414));z3e5b8e05d8=(void*)(zeccbadd9b3.VirtAddress[(0x929+4579-0x1b0c)]);if(!xpceIsModelInit()){start=(0x1189+316-0x12c4);
if((uint32_T)mxGetN(zd39abcef8f)){m=(uint_T)mxGetPr(zd39abcef8f)[(0x249b+368-0x260b)];for(i=(0x80a+2372-0x114e);i<m;i++){z0add1d1c25=(int_T)mxGetPr(zd39abcef8f)[start];length=(int_T)mxGetPr(zd39abcef8f)[start+(0x6f4+4999-0x1a78)];for(z26dbd73a5e=(0x537+7073-0x20d8);z26dbd73a5e<length;z26dbd73a5e++){data[z26dbd73a5e]=(uint8_T)mxGetPr(zd39abcef8f)[start+(0x3c0+5330-0x188e)+z26dbd73a5e];}message.Data[(0x600+3006-0x11be)]=data[(0xbfa+3687-0x1a61)];message.Data[(0x60d+7348-0x22c0)]=data[(0x4b3+7102-0x2070)];message.Data[(0x7e1+5679-0x1e0e)]=data[(0x10f5+266-0x11fd)];message.Data[(0x25+5124-0x1426)]=data[(0x70b+4419-0x184b)];message.Data[(0xd9+7699-0x1ee8)]=data[(0x2271+437-0x2422)];message.Data[(0x1757+492-0x193e)]=data[(0xee3+4183-0x1f35)];message.Data[(0xecf+1610-0x1513)]=data[(0x777+4558-0x193f)];message.Data[(0x5b7+4161-0x15f1)]=data[(0x181f+588-0x1a64)];message.Length=length;message.z1fde0a5efd=(int_T)mxGetPr(zd39abcef8f)[start+(0x1642+2003-0x1e14)];message.ID=(uint32_T)mxGetPr(zd39abcef8f)[start+(0xccc+3465-0x1a53)];message.ze0cf853226=(0xec7+2195-0x175a);z563e4da9f6=z50a448c4af(S,z0add1d1c25,message);if(z563e4da9f6==(0x1273+795-0x158e)){zc1ac25c1d6=z3e5b8e05d8[(0x1e2f+1596-0x2456)];z3e5b8e05d8[(0x1248+235-0x131e)]=zc1ac25c1d6&~((0x314+2123-0xb5e)<<(0x1484+2001-0x1c53));z3e5b8e05d8[(0x1b6+4025-0x115a)]=zc1ac25c1d6|((0xd99+1961-0x1541)<<(0x205d+468-0x222f));}
rl32eWaitDouble(mxGetPr(zd39abcef8f)[start+(0x4eb+5041-0x1890)]);start+=(0x520+1519-0xb02);}}}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
int32_T z563e4da9f6,z0add1d1c25,zc430a259a4,ID;real_T*u,*y;real_T data;uint8_T*zb425515a78;uint8_T ze7b7ebebbf;z80857f1537*zcc6fcdb7f7;z80857f1537 message;int_T*dims;uint32_T i,m,zd1c43753cf,count;volatile uint32_T*z3e5b8e05d8;uint32_T zc1ac25c1d6;uint8_T z4f29281a8f,length;uint32_T z5d9c31c2b6=ssGetIWorkValue(S,z4fc736908d);z3e5b8e05d8=(void*)z5d9c31c2b6;if((int_T)mxGetPr(zfdec0918ff)[(0x1bbf+1750-0x2295)]==(0x8f5+1577-0xf1c))
{zcc6fcdb7f7=(z80857f1537*)ssGetInputPortSignal(S,(0x17d4+648-0x1a5c));u=(real_T*)ssGetInputPortSignal(S,(0x106+5379-0x1608));count=(uint32_T)u[(0xe70+2407-0x17d7)];zd1c43753cf=(uint32_T)mxGetPr(z1de802f68c)[(0xa5b+5206-0x1eb1)];if(count<zd1c43753cf){zd1c43753cf=count;}}else{dims=ssGetInputPortDimensions(S,(0x13+7111-0x1bda));m=dims[(0x1b36+1695-0x21d4)];zd1c43753cf=dims[(0xae0+3133-0x171d)];u=(real_T*)ssGetInputPortSignal(S,(0x24+2637-0xa71));}ze7b7ebebbf=(0x22+2720-0xac2);for(i=(0x17ec+1426-0x1d7e);i<zd1c43753cf;i++){if((int_T)mxGetPr(zfdec0918ff)[(0x2aa+5871-0x1999)]==(0x148b+26-0x14a3)){message=zcc6fcdb7f7[i];z0add1d1c25=(int32_T)mxGetPr(z9cd34e3860)[(0x6e1+6288-0x1f71)];zc430a259a4=(0x39d+3758-0x124a);}else{ID=(int32_T)u[i+zd1c43753cf*(0x370+7772-0x21cc)];z0add1d1c25=(int32_T)u[i+zd1c43753cf*(0xd22+2995-0x18d4)];z4f29281a8f=(uint8_T)u[i+zd1c43753cf*(0x1d2a+940-0x20d4)];length=(uint8_T)u[i+zd1c43753cf*(0x1147+584-0x138c)];data=u[i+zd1c43753cf*(0x451+2454-0xde3)];zb425515a78=(uint8_T*)&data;message.Data[(0x749+3570-0x153b)]=zb425515a78[(0x758+5781-0x1ded)];message.Data[(0x97b+6074-0x2134)]=zb425515a78[(0xb4+1139-0x526)];message.Data[(0x1a4a+30-0x1a66)]=zb425515a78[(0x10f8+384-0x1276)];message.Data[(0x5e9+8004-0x252a)]=zb425515a78[(0x22ef+867-0x264f)];message.Data[(0x199f+1720-0x2053)]=zb425515a78[(0x7f3+798-0xb0d)];message.Data[(0xd00+1499-0x12d6)]=zb425515a78[(0x172d+2083-0x1f4b)];message.Data[(0xdf8+5878-0x24e8)]=zb425515a78[(0xe8d+4435-0x1fda)];message.Data[(0x1d88+1812-0x2495)]=zb425515a78[(0x9d3+1783-0x10c3)];message.Length=length;message.z1fde0a5efd=z4f29281a8f;message.ID=ID;message.ze0cf853226=(0x66c+7926-0x2562);if(m==(0xaf1+1911-0x1262)){zc430a259a4=(int32_T)u[i+zd1c43753cf*(0x8ff+2426-0x1274)];}else{zc430a259a4=(0x819+849-0xb69);}}if(zc430a259a4){z563e4da9f6=z50a448c4af(S,z0add1d1c25,message);if(z563e4da9f6==(0x885+5704-0x1ecd)){zc1ac25c1d6=z3e5b8e05d8[(0x118a+1457-0x1726)];z3e5b8e05d8[(0x56+6636-0x1a2d)]=zc1ac25c1d6&~((0x36d+6490-0x1cc6)<<(0x810+4790-0x1ac4));z3e5b8e05d8[(0x1a3f+245-0x1b1f)]=zc1ac25c1d6|((0x11ca+4065-0x21aa)<<(0x1357+2788-0x1e39));}if((int_T)mxGetPr(z11e8538834)[(0xada+4178-0x1b2c)]){y=(real_T*)ssGetOutputPortSignal(S,(0x4b6+3066-0x10b0));y[i]=(real_T)z563e4da9f6;}}}if(ze7b7ebebbf){
zc1ac25c1d6=z3e5b8e05d8[(0x1b2f+679-0x1dc1)];z3e5b8e05d8[(0x6d4+7681-0x24c0)]=zc1ac25c1d6&~((0xdcf+2437-0x1753)<<(0x1704+2417-0x2073));z3e5b8e05d8[(0x463+2619-0xe89)]=zc1ac25c1d6|((0x2395+44-0x23c0)<<(0x3b+479-0x218));}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef  MATLAB_MEX_FILE 
z80857f1537 message;int32_T z563e4da9f6;int32_T i,z26dbd73a5e,m;int_T z0add1d1c25,start;uint8_T data[(0x34b+3605-0x1158)];uint8_T length;volatile uint32_T*z3e5b8e05d8;uint32_T zc1ac25c1d6;uint32_T z5d9c31c2b6=ssGetIWorkValue(S,z4fc736908d);z3e5b8e05d8=(void*)z5d9c31c2b6;if(!xpceIsModelInit()){
if((uint32_T)mxGetN(zdfab922aba)){m=(uint32_T)mxGetPr(zdfab922aba)[(0x144c+4250-0x24e6)];start=(0x3f4+5833-0x1abc);for(i=(0xf9a+5908-0x26ae);i<m;i++){z0add1d1c25=(int_T)mxGetPr(zdfab922aba)[start];length=(int_T)mxGetPr(zdfab922aba)[start+(0x1192+4199-0x21f6)];for(z26dbd73a5e=(0x168+8210-0x217a);z26dbd73a5e<length;z26dbd73a5e++){data[z26dbd73a5e]=(uint8_T)mxGetPr(zdfab922aba)[start+(0x10c4+440-0x1278)+z26dbd73a5e];}message.Data[(0x14af+1566-0x1acd)]=data[(0x995+5179-0x1dd0)];message.Data[(0x353+1905-0xac3)]=data[(0x12f0+2160-0x1b5f)];message.Data[(0xca7+2833-0x17b6)]=data[(0x15c+354-0x2bc)];message.Data[(0xdd7+4305-0x1ea5)]=data[(0xf5d+3468-0x1ce6)];message.Data[(0x1768+2199-0x1ffb)]=data[(0x5bb+566-0x7ed)];message.Data[(0x1010+2571-0x1a16)]=data[(0x923+4822-0x1bf4)];message.Data[(0x17b2+2343-0x20d3)]=data[(0x4ef+7203-0x210c)];message.Data[(0x2555+44-0x257a)]=data[(0x129f+3394-0x1fda)];message.Length=length;message.z1fde0a5efd=(int_T)mxGetPr(zdfab922aba)[start+(0x632+377-0x7aa)];message.ID=(uint32_T)mxGetPr(zdfab922aba)[start+(0x9f1+2970-0x1589)];message.ze0cf853226=(0x12b8+3611-0x20d3);z563e4da9f6=z50a448c4af(S,z0add1d1c25,message);if(z563e4da9f6==(0xd20+894-0x109e)){zc1ac25c1d6=z3e5b8e05d8[(0x18c2+2133-0x2102)];z3e5b8e05d8[(0x110f+2863-0x1c29)]=zc1ac25c1d6&~((0x2126+120-0x219d)<<(0x11f0+2284-0x1ada));z3e5b8e05d8[(0x18d4+560-0x1aef)]=zc1ac25c1d6|((0x2026+1507-0x2608)<<(0x447+1943-0xbdc));}
rl32eWaitDouble(mxGetPr(zdfab922aba)[start+(0x4b0+2731-0xf4f)]);start+=(0x5dc+5998-0x1d3d);}}}
#endif
}
#ifdef  MATLAB_MEX_FILE    
#include "simulink.c"      
#else
#include "cg_sfun.h"       
#endif
