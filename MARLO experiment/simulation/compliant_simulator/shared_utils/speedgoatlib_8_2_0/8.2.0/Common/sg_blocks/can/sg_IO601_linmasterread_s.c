/* Copyright 2006-2013 Speedgoat GmbH. */

#define S_FUNCTION_LEVEL (0x4dc+4527-0x1689)
#undef S_FUNCTION_NAME
#define S_FUNCTION_NAME sg_IO601_linmasterread_s
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
#define z694756a014               (4277)
#define zea87e0ba83               (36912)
#define z29146a1837            ((0x1b33+2895-0x15cd))
#define zab7e64468b            (10615)
#define zdf24515981         ((0x1140+469-0x1311))
#define zbcb3e4d083             ssGetSFcnParam(S, (0x14f0+3428-0x2254))
#define z8be821e1c6         ssGetSFcnParam(S, (0x72a+7553-0x24aa))
#define z3832b85a32          ssGetSFcnParam(S, (0x15a1+1074-0x19d1))
#define z702a26a5e9               ssGetSFcnParam(S, (0x4d1+7745-0x230f))
#define z2e6483d505             ((0x1a21+2836-0x2533))
#define z6a0da049de        ((0x382+2360-0xcba))
#define z4fc736908d       ((0x18a4+2630-0x22e9))
#define zc5ce4cb81a             ((0x12c7+3139-0x1f0a))
#define z2b17e2ee3b             ((0xedf+5518-0x246d))
extern uint8_T ptrWritePointer[];extern uint8_T ptrReadPointer[];static char_T zea4cd01646[(0x16c0+852-0x1914)];
#ifndef MATLAB_MEX_FILE
typedef struct z5d859c8e2d{uint8_T status;uint8_T count;uint8_T timeStamp[(0x13e9+2591-0x1e04)];uint8_T type;uint8_T z636e2cf3e0;uint8_T zf528bd284e;uint8_T z6fca5ff095;uint8_T checkSum;uint8_T z11f2a08c09;uint8_T length;uint8_T zdcc6ef6f12;uint8_T data[(0x244f+82-0x2499)];}z5d859c8e2d;typedef struct{uint8_T z787fcfe334:(0x150+830-0x48d),zdc0b977329:(0x818+6934-0x232d),zaae2cd1378:(0x2271+78-0x22be),zf2008ed5e1:(0x831+5419-0x1d5b),za978b3e9be:(0x18a+2723-0xc2c),z7159ca38e3:(0x13da+3600-0x21e9),z11a8412f0c:(0x8b7+4048-0x1886),zcf452bf3c7:(0x1bb8+1915-0x2332);}z149e1b8f6c;typedef union{uint8_T b;z149e1b8f6c u;}z6f5aefeff2;static uint8_T z746f98b245(uint8_T id){z6f5aefeff2 z526d1e6e88;z526d1e6e88.b=id;z526d1e6e88.u.z11a8412f0c=z526d1e6e88.u.z787fcfe334^z526d1e6e88.u.zdc0b977329^z526d1e6e88.u.zaae2cd1378^z526d1e6e88.u.za978b3e9be;z526d1e6e88.u.zcf452bf3c7=~(z526d1e6e88.u.zdc0b977329^z526d1e6e88.u.zf2008ed5e1^z526d1e6e88.u.za978b3e9be^z526d1e6e88.u.z7159ca38e3);return(uint8_T)z526d1e6e88.b;}static int8_T z963e43522f(SimStruct*S,uint32_T z31a846515d,uint8_T zc369e1e9c6,uint8_T id,uint8_T length,uint8_T*data){int32_T z563e4da9f6,position;volatile z5d859c8e2d*z256cbcfc8b;z563e4da9f6=(0x1876+458-0x1a3f);if(id<(0x40a+791-0x721)||id>(0xbc9+1236-0x105e)){z563e4da9f6=-(0x1b11+642-0x1d91);
}if(length>(0x7b4+2265-0x1085)){z563e4da9f6=-(0x156+6373-0x1a38);}if(z563e4da9f6>(0x1df+8054-0x2155)){if(!ptrWritePointer){sprintf(zea4cd01646,"\x4c\x4d\x52\x20\x53\x65\x6e\x64\x4c\x49\x4e\x4d\x65\x73\x73\x61\x67\x65\x3a\x20\x70\x74\x72\x57\x72\x69\x74\x65\x50\x6f\x69\x6e\x74\x65\x72\x20\x69\x73\x20\x4e\x55\x4c\x4c" "\n");ssSetErrorStatus(S,zea4cd01646);return-(0x23c+8941-0x2526);}position=ptrWritePointer[zc369e1e9c6];
z256cbcfc8b=(z5d859c8e2d*)(z31a846515d+(0x158b+179-0x63e)+position*sizeof(z5d859c8e2d));if(z256cbcfc8b->status==(0xe1+4222-0x115f)){z256cbcfc8b->status=(0x13af+3489-0x214f);z256cbcfc8b->count=(0x18e2+896-0x1c56)+length;z256cbcfc8b->type=(0xee9+2227-0x179c);z256cbcfc8b->z636e2cf3e0=(0xed0+3760-0x1d80);z256cbcfc8b->zf528bd284e=z746f98b245(id);z256cbcfc8b->z6fca5ff095=(0x1bb8+2297-0x24b1);z256cbcfc8b->checkSum=(0x5fc+7400-0x22e4);z256cbcfc8b->z11f2a08c09=(0x2324+604-0x2580);z256cbcfc8b->length=length;
z256cbcfc8b->zdcc6ef6f12=(0x542+5488-0x1ab2);z256cbcfc8b->data[(0xd28+3374-0x1a56)]=data[(0xc7+4773-0x136c)];z256cbcfc8b->data[(0x1261+142-0x12ee)]=data[(0x252+3794-0x1123)];z256cbcfc8b->data[(0x862+2041-0x1059)]=data[(0x55c+3345-0x126b)];z256cbcfc8b->data[(0x420+1942-0xbb3)]=data[(0xa76+3546-0x184d)];z256cbcfc8b->data[(0x20+7467-0x1d47)]=data[(0x843+412-0x9db)];z256cbcfc8b->data[(0x1104+259-0x1202)]=data[(0x809+1717-0xeb9)];z256cbcfc8b->data[(0x19d9+1630-0x2031)]=data[(0x1596+1705-0x1c39)];z256cbcfc8b->data[(0x172+174-0x219)]=data[(0x47c+6649-0x1e6e)];position=(position==(0x1b08+1470-0x2095))?(0xbaf+5251-0x2032):++position;ptrWritePointer[zc369e1e9c6]=position;}else{z563e4da9f6=-(0xc69+4765-0x1f05);}}return z563e4da9f6;}static uint8_T z3c68e3f61b(SimStruct*S,uint32_T z31a846515d,uint8_T zc369e1e9c6,uint8_T*timestamp,uint8_T*data,uint8_T*id,uint8_T*length,uint8_T*checksum,uint8_T*type,uint8_T*zbcd06d4a67){uint8_T position;volatile z5d859c8e2d*z256cbcfc8b;if(!ptrReadPointer){sprintf(zea4cd01646,"\x4c\x4d\x52\x20\x52\x65\x61\x64\x4c\x49\x4e\x42\x75\x66\x66\x65\x72\x3a\x20\x70\x74\x72\x52\x65\x61\x64\x50\x6f\x69\x6e\x74\x65\x72\x20\x69\x73\x20\x4e\x55\x4c\x4c" "\n");ssSetErrorStatus(S,zea4cd01646);return;}position=ptrReadPointer[zc369e1e9c6];
z256cbcfc8b=(z5d859c8e2d*)(z31a846515d+5196+position*sizeof(z5d859c8e2d));
if(z256cbcfc8b->status){z256cbcfc8b->status=(0x469+6844-0x1f25);timestamp[(0x33f+431-0x4ee)]=z256cbcfc8b->timeStamp[(0x3a0+2178-0xc22)];
timestamp[(0x56f+6126-0x1d5c)]=z256cbcfc8b->timeStamp[(0xe40+1019-0x123a)];timestamp[(0x1355+4001-0x22f4)]=z256cbcfc8b->timeStamp[(0xb16+4390-0x1c3a)];timestamp[(0x223f+957-0x25f9)]=z256cbcfc8b->timeStamp[(0x2b1+5772-0x193a)];id[(0xc99+2534-0x167f)]=z256cbcfc8b->zf528bd284e;
data[(0xae4+6139-0x22df)]=z256cbcfc8b->data[(0x41d+1107-0x870)];
data[(0xfc6+827-0x1300)]=z256cbcfc8b->data[(0x32f+1054-0x74c)];data[(0x31a+3067-0xf13)]=z256cbcfc8b->data[(0x160f+3989-0x25a2)];data[(0x26c+9217-0x266a)]=z256cbcfc8b->data[(0x14f2+2148-0x1d53)];data[(0x1127+740-0x1407)]=z256cbcfc8b->data[(0xea+2082-0x908)];data[(0x24ac+609-0x2708)]=z256cbcfc8b->data[(0x9ad+53-0x9dd)];data[(0x7b+1874-0x7c7)]=z256cbcfc8b->data[(0xe7a+4028-0x1e30)];data[(0x704+7941-0x2602)]=z256cbcfc8b->data[(0x1548+2502-0x1f07)];length[(0x1fc+5718-0x1852)]=z256cbcfc8b->length;
checksum[(0x14f8+765-0x17f5)]=z256cbcfc8b->checkSum;type[(0x1dd3+1069-0x2200)]=z256cbcfc8b->type;zbcd06d4a67[(0xdbd+1590-0x13f3)]=z256cbcfc8b->z636e2cf3e0;
position=(position==(0x913+4704-0x1b42))?(0xab1+3416-0x1809):++position;ptrReadPointer[zc369e1e9c6]=position;return(0x308+158-0x3a5);}else{return(0x1008+5646-0x2616);}}
#endif
static void mdlInitializeSizes(SimStruct*S){int_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x16ca+1723-0x1d85));ssSetNumDiscStates(S,(0x15b8+758-0x18ae));
ssSetNumInputPorts(S,(0x5e1+6910-0x20dd));for(i=(0x690+3413-0x13e5);i<(0x49a+3302-0x117e);i++){ssSetInputPortDirectFeedThrough(S,i,(0xd18+1745-0x13e8));ssSetInputPortRequiredContiguous(S,i,(0x1622+3200-0x22a1));ssSetInputPortDataType(S,i,SS_UINT8);ssSetInputPortWidth(S,i,(uint32_T)mxGetPr(z8be821e1c6)[(0x919+258-0xa1b)]);}ssSetNumOutputPorts(S,(0x157+2437-0xace));ssSetOutputPortDataType(S,(0x96f+215-0xa46),SS_UINT8);ssSetOutputPortWidth(S,(0x13fc+62-0x143a),(uint32_T)mxGetPr(z8be821e1c6)[(0x14ef+713-0x17b8)]);ssSetOutputPortDataType(S,(0xa42+3031-0x1618),SS_UINT8);ssSetOutputPortWidth(S,(0x18a3+142-0x1930),(uint32_T)mxGetPr(z8be821e1c6)[(0x17cf+2816-0x22cf)]);ssSetOutputPortDataType(S,(0x722+4945-0x1a71),SS_UINT8);ssSetOutputPortWidth(S,(0xc31+4728-0x1ea7),(uint32_T)mxGetPr(z8be821e1c6)[(0x7fc+6822-0x22a2)]);ssSetOutputPortDataType(S,(0xcbf+762-0xfb6),SS_UINT8);ssSetOutputPortWidth(S,(0xdd5+5944-0x250a),(uint32_T)mxGetPr(z8be821e1c6)[(0xd97+1594-0x13d1)]);ssSetOutputPortDataType(S,(0x4f2+6043-0x1c89),SS_UINT8);ssSetOutputPortWidth(S,(0x1a6+6940-0x1cbe),(uint32_T)mxGetPr(z8be821e1c6)[(0x13+6419-0x1926)]);ssSetOutputPortDataType(S,(0x132f+2725-0x1dcf),SS_UINT8);ssSetOutputPortWidth(S,(0xa0+6001-0x180c),(uint32_T)mxGetPr(z8be821e1c6)[(0xcb7+4991-0x2036)]);ssSetOutputPortDataType(S,(0x19f5+986-0x1dc9),SS_UINT8);ssSetOutputPortWidth(S,(0x570+989-0x947),(uint32_T)mxGetPr(z8be821e1c6)[(0x1b1+2061-0x9be)]);ssSetOutputPortDataType(S,(0x57c+4957-0x18d2),SS_UINT8);ssSetOutputPortWidth(S,(0x2c0+1688-0x951),(uint32_T)mxGetPr(z8be821e1c6)[(0x44c+3744-0x12ec)]);ssSetOutputPortDataType(S,(0x2f+5231-0x1496),SS_UINT8);ssSetOutputPortWidth(S,(0x2394+397-0x2519),(uint32_T)mxGetPr(z8be821e1c6)[(0xdcf+424-0xf77)]);ssSetOutputPortDataType(S,(0x121+5865-0x1801),SS_UINT8);ssSetOutputPortWidth(S,(0x17ed+1479-0x1dab),(uint32_T)mxGetPr(z8be821e1c6)[(0x102+5015-0x1499)]);ssSetOutputPortDataType(S,(0x303+2333-0xc16),SS_UINT32);ssSetOutputPortWidth(S,(0xd96+2133-0x15e1),(uint32_T)mxGetPr(z8be821e1c6)[(0xd54+6550-0x26ea)]);ssSetOutputPortDataType(S,(0x141+9304-0x258e),SS_UINT8);ssSetOutputPortWidth(S,(0x1006+4339-0x20ee),(uint32_T)mxGetPr(z8be821e1c6)[(0x81+8583-0x2208)]);ssSetOutputPortDataType(S,(0x262+3249-0xf07),SS_UINT8);ssSetOutputPortWidth(S,(0x1520+1553-0x1b25),(uint32_T)mxGetPr(z8be821e1c6)[(0xb46+5766-0x21cc)]);ssSetOutputPortDataType(S,(0x5af+1969-0xd53),SS_UINT8);ssSetOutputPortWidth(S,(0x25e3+32-0x25f6),(uint32_T)mxGetPr(z8be821e1c6)[(0x729+5671-0x1d50)]);ssSetNumSampleTimes(S,(0xf2a+3150-0x1b77));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,(0x779+4164-0x17bd));ssSetNumModes(S,(0x713+4111-0x1722));ssSetNumNonsampledZCs(S,(0x1a13+2399-0x2372));for(i=(0x477+1283-0x97a);i<zdf24515981;i++){ssSetSFcnParamNotTunable(S,i);}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x1109+886-0x147f),mxGetPr(z3832b85a32)[(0x54+3324-0xd50)]);if(mxGetN((z3832b85a32))==(0x7d2+3657-0x161a)){ssSetOffsetTime(S,(0x1763+1293-0x1c70),0.0);}else{ssSetOffsetTime(S,(0xaaa+268-0xbb6),mxGetPr(z3832b85a32)[(0x34d+4841-0x1635)]);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;
#ifdef zb482f925e2
printf("\x4d\x52\x73\x74\x61\x72\x74\x20\x62\x65\x67\x69\x6e" "\n");
#endif
if(mxGetN(z702a26a5e9)==(0xfe3+1222-0x14a8)){z366b2f03bf=(0x1a18+701-0x1cd5);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xb19+1032-0xf21)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x1ea+1774-0x8d8)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xa60+7044-0x25e3)];}if(xpcGetPCIDeviceInfo((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x4c\x4d\x52\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}rl32eWaitDouble(0.05);
zeccbadd9b3.VirtAddress[(0xafd+6228-0x234f)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0xec8+155-0xf61)],zeccbadd9b3.Length[(0x534+6216-0x1d7a)],XPC_RT_PG_USERREADWRITE);zeccbadd9b3.VirtAddress[(0xafb+175-0xbaa)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x191d+2973-0x24ba)],zeccbadd9b3.Length[(0x970+5144-0x1d88)],XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x1739+1150-0x1bb5)]);ssSetIWorkValue(S,z4fc736908d,zeccbadd9b3.VirtAddress[(0x5a7+1481-0xb70)]);
#ifdef zb482f925e2
printf("\x4d\x52\x73\x74\x61\x72\x74\x20\x65\x6e\x64" "\n");
#endif
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
volatile uint8_T*out;volatile uint8_T*u;uint32_T*z126ed5de63;uint32_T i,z26dbd73a5e,count,z0ba1e0e76e,zae20974d90;uint8_T id;uint8_T length;uint8_T data[(0x1920+619-0x1b83)];uint8_T timestamp[(0x47c+4765-0x1715)];uint8_T checksum;uint8_T type;uint8_T zbcd06d4a67;volatile uint32_T*z3e5b8e05d8;uint32_T zc1ac25c1d6;uint8_T zc369e1e9c6;int8_T z563e4da9f6;uint32_T z5d9c31c2b6=ssGetIWorkValue(S,z4fc736908d);uint32_T z31a846515d=ssGetIWorkValue(S,z6a0da049de);
#ifdef zb482f925e2
printf("\x4d\x52\x20\x62\x65\x67\x69\x6e");
#endif
z3e5b8e05d8=(void*)z5d9c31c2b6;zc369e1e9c6=(uint32_T)mxGetPr(zbcb3e4d083)[(0x2e8+8896-0x25a8)]-(0x7a5+3109-0x13c9);z0ba1e0e76e=(0x82b+6383-0x211a);
for(i=(0x9f+2343-0x9c6);i<(uint32_T)mxGetPr(z8be821e1c6)[(0x1d52+1035-0x215d)];i++){
u=(uint8_T*)ssGetInputPortSignal(S,(0xb07+6268-0x2383));id=(uint8_T)u[i];u=(uint8_T*)ssGetInputPortSignal(S,(0x5ab+1742-0xc78));length=(uint8_T)u[i];for(z26dbd73a5e=(0xbb2+5854-0x2290);z26dbd73a5e<(0x39f+9020-0x26d3);z26dbd73a5e++){data[z26dbd73a5e]=(0x105b+3653-0x1ea0);}if(length==(0x1449+1272-0x1941)&&id==(0x5d1+8265-0x261a)){z0ba1e0e76e++;}else{z563e4da9f6=z963e43522f(S,z31a846515d,zc369e1e9c6,id,length,data);switch(z563e4da9f6){case(0x178+613-0x3dc):
zc1ac25c1d6=z3e5b8e05d8[(0x240+5614-0x1819)];z3e5b8e05d8[(0x1110+1435-0x1696)]=zc1ac25c1d6&~((0x46b+3171-0x10cd)<<(0xf99+2377-0x18e0));z3e5b8e05d8[(0x1e54+1201-0x22f0)]=zc1ac25c1d6|((0x582+2587-0xf9c)<<(0x8cd+1056-0xceb));z0ba1e0e76e++;
break;case-(0x14f6+4224-0x2575):printf("\x25\x73\x20\x4c\x49\x4e\x20\x4d\x52\x20\x71\x75\x65\x75\x65\x20\x6f\x76\x65\x72\x6c\x6f\x61\x64\x65\x64\x2e" "\n",zf1b619edf2);
zc1ac25c1d6=z3e5b8e05d8[(0x3e5+4385-0x14f1)];z3e5b8e05d8[(0x822+7359-0x24cc)]=zc1ac25c1d6&~((0xf0+5061-0x14b4)<<(0x4c+1960-0x7f2));z3e5b8e05d8[(0x3a4+1930-0xb19)]=zc1ac25c1d6|((0x1919+2875-0x2453)<<(0xf76+3758-0x1e22));


break;case-(0x9c4+3095-0x15d9):sprintf(zea4cd01646,"\x25\x73\x20\x49\x6e\x63\x6f\x72\x72\x65\x63\x74\x20\x4c\x49\x4e\x20\x69\x64\x2e",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;case-(0xa43+3246-0x16ee):sprintf(zea4cd01646,"\x25\x73\x20\x49\x6e\x63\x6f\x72\x72\x65\x63\x74\x20\x6d\x65\x73\x73\x61\x67\x65\x20\x6c\x65\x6e\x67\x74\x68\x2e",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;default:sprintf(zea4cd01646,"\x25\x73\x20\x55\x6e\x6b\x6e\x6f\x77\x6e\x20\x65\x72\x72\x6f\x72\x20\x69\x6e\x20\x53\x65\x6e\x64\x4c\x49\x4e\x4d\x65\x73\x73\x61\x67\x65\x28\x29\x2e",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}}
for(i=(0x719+432-0x8c9);i<(uint32_T)mxGetPr(z8be821e1c6)[(0x700+3360-0x1420)];i++){out=(uint8_T*)ssGetOutputPortSignal(S,(0x1b50+536-0x1d68));out[i]=(0xec2+4234-0x1f4c);out=(uint8_T*)ssGetOutputPortSignal(S,(0x1546+3904-0x2485));out[i]=(0xcaf+6223-0x24fe);out=(uint8_T*)ssGetOutputPortSignal(S,(0x3e0+4649-0x1607));out[i]=(0x1e64+1141-0x22d9);out=(uint8_T*)ssGetOutputPortSignal(S,(0x12c+3995-0x10c4));out[i]=(0x1519+22-0x152f);out=(uint8_T*)ssGetOutputPortSignal(S,(0x976+1518-0xf60));out[i]=(0xfe1+1748-0x16b5);out=(uint8_T*)ssGetOutputPortSignal(S,(0xc37+6-0xc38));out[i]=(0x2f2+1668-0x976);out=(uint8_T*)ssGetOutputPortSignal(S,(0x13c0+1299-0x18cd));out[i]=(0x292+3571-0x1085);out=(uint8_T*)ssGetOutputPortSignal(S,(0x306+8333-0x238c));out[i]=(0x1806+21-0x181b);out=(uint8_T*)ssGetOutputPortSignal(S,(0x11b6+1111-0x1605));out[i]=(0xc43+238-0xd31);out=(uint8_T*)ssGetOutputPortSignal(S,(0xbf+1135-0x525));out[i]=(0x3e5+7494-0x212b);z126ed5de63=(uint32_T*)ssGetOutputPortSignal(S,(0x1267+4751-0x24ec));z126ed5de63[i]=(0x394+735-0x673);out=(uint8_T*)ssGetOutputPortSignal(S,(0x1152+491-0x1332));out[i]=(0x1141+1293-0x164e);out=(uint8_T*)ssGetOutputPortSignal(S,(0x20a4+1228-0x2564));out[i]=(0x82+2895-0xbd1);out=(uint8_T*)ssGetOutputPortSignal(S,(0x1db+6460-0x1b0a));out[i]=(0xc8+6567-0x1a6f);}zae20974d90=(0x8e4+1898-0x104e);count=(0x1d7+6562-0x1b79);while((count!=z0ba1e0e76e)
&&(zae20974d90<(0x1cad+1944-0x2441)*z0ba1e0e76e))
{
if(z3c68e3f61b(S,z31a846515d,zc369e1e9c6,timestamp,data,&id,&length,&checksum,&type,&zbcd06d4a67)){
out=(uint8_T*)ssGetOutputPortSignal(S,(0xb35+4396-0x1c61));out[count]=id&(0x516+5766-0x1b5d);
out=(uint8_T*)ssGetOutputPortSignal(S,(0x193b+758-0x1c30));out[count]=length;out=(uint8_T*)ssGetOutputPortSignal(S,(0xb6+6931-0x1bc7));out[count]=data[(0x1ee2+1336-0x241a)];out=(uint8_T*)ssGetOutputPortSignal(S,(0xd7+2784-0xbb4));out[count]=data[(0xd8+6578-0x1a89)];out=(uint8_T*)ssGetOutputPortSignal(S,(0x1a3f+1583-0x206a));out[count]=data[(0x47c+1104-0x8ca)];out=(uint8_T*)ssGetOutputPortSignal(S,(0x1b7c+661-0x1e0c));out[count]=data[(0x4d2+8107-0x247a)];out=(uint8_T*)ssGetOutputPortSignal(S,(0xc2+5631-0x16bb));out[count]=data[(0x7c1+5956-0x1f01)];out=(uint8_T*)ssGetOutputPortSignal(S,(0xb9d+489-0xd7f));out[count]=data[(0x1d1d+83-0x1d6b)];out=(uint8_T*)ssGetOutputPortSignal(S,(0x2eb+6084-0x1aa7));out[count]=data[(0x2038+1344-0x2572)];out=(uint8_T*)ssGetOutputPortSignal(S,(0x1de3+2236-0x2696));out[count]=data[(0x1dc7+965-0x2185)];z126ed5de63=(uint32_T*)ssGetOutputPortSignal(S,(0xe87+2609-0x18ae));z126ed5de63[count]=timestamp[(0xcec+4111-0x1cfb)]|(timestamp[(0x1a35+1220-0x1ef8)]<<(0x8d+1428-0x619))|(timestamp[(0x465+107-0x4ce)]<<(0x1bfd+323-0x1d30))|(timestamp[(0x11c9+1959-0x196f)]<<(0x3ed+2158-0xc43));out=(uint8_T*)ssGetOutputPortSignal(S,(0x1936+2248-0x21f3));out[count]=checksum;out=(uint8_T*)ssGetOutputPortSignal(S,(0x462+3133-0x1093));out[count]=type;out=(uint8_T*)ssGetOutputPortSignal(S,(0xe0d+5317-0x22c5));out[count]=zbcd06d4a67;count++;}else{
#ifdef zec3e4ced3e
printf("\x2e");
#endif
zae20974d90++;}}
#ifdef zb482f925e2
printf("\x4d\x52\x20\x65\x6e\x64");
#endif
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

