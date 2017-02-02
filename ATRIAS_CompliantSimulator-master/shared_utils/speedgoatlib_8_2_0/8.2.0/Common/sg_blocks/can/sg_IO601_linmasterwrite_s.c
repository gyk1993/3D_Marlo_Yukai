/* Copyright 2006-2013 Speedgoat GmbH. */
#define S_FUNCTION_LEVEL (0x1009+5106-0x23f9)
#undef S_FUNCTION_NAME
#define S_FUNCTION_NAME sg_IO601_linmasterwrite_s
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
#define z694756a014               ((0x10dd+6455-0x195f))
#define zea87e0ba83               (36912)
#define z29146a1837            ((0x10bc+3825-0xef8))
#define zab7e64468b            (10615)
#define zdf24515981         ((0x1ec+5776-0x1878))
#define zbcb3e4d083             ssGetSFcnParam(S, (0x3a6+6293-0x1c3b))
#define z8be821e1c6         ssGetSFcnParam(S, (0xdcc+2267-0x16a6))
#define z3832b85a32          ssGetSFcnParam(S, (0x10b+3395-0xe4c))
#define z702a26a5e9               ssGetSFcnParam(S, (0x17c6+2692-0x2247))
#define z2e6483d505             ((0x270+4503-0x1405))
#define z6a0da049de        ((0x7e1+2611-0x1214))
#define z4fc736908d       ((0x48+7837-0x1ee4))
#define zc5ce4cb81a             ((0x1321+3520-0x20e1))
#define z2b17e2ee3b             ((0x591+4197-0x15f6))
extern uint8_T ptrWritePointer[];static char_T zea4cd01646[(0x1acb+1625-0x2024)];
#ifndef MATLAB_MEX_FILE
typedef struct z5d859c8e2d{uint8_T status;uint8_T count;uint8_T timeStamp[(0xb27+5014-0x1eb9)];uint8_T type;uint8_T z636e2cf3e0;uint8_T zf528bd284e;uint8_T z6fca5ff095;uint8_T checkSum;uint8_T z11f2a08c09;uint8_T length;uint8_T zdcc6ef6f12;uint8_T data[(0x1ea8+206-0x1f6e)];}z5d859c8e2d;typedef struct{uint8_T z787fcfe334:(0x746+385-0x8c6),zdc0b977329:(0x77+5098-0x1460),zaae2cd1378:(0xd7+198-0x19c),zf2008ed5e1:(0x23c+6149-0x1a40),za978b3e9be:(0x247+5259-0x16d1),z7159ca38e3:(0x4a7+8069-0x242b),z11a8412f0c:(0x1198+769-0x1498),zcf452bf3c7:(0x6ec+6287-0x1f7a);}z149e1b8f6c;typedef union{uint8_T b;z149e1b8f6c u;}z6f5aefeff2;static uint8_T z746f98b245(uint8_T id){z6f5aefeff2 z526d1e6e88;z526d1e6e88.b=id;z526d1e6e88.u.z11a8412f0c=z526d1e6e88.u.z787fcfe334^z526d1e6e88.u.zdc0b977329^z526d1e6e88.u.zaae2cd1378^z526d1e6e88.u.za978b3e9be;z526d1e6e88.u.zcf452bf3c7=~(z526d1e6e88.u.zdc0b977329^z526d1e6e88.u.zf2008ed5e1^z526d1e6e88.u.za978b3e9be^z526d1e6e88.u.z7159ca38e3);return(uint8_T)z526d1e6e88.b;}static uint8_T CheckSum(uint8_T length,uint8_T*data){uint8_T i;uint16_T zd3c791df3e=(0xf1+136-0x179);for(i=(0x81a+3393-0x155b);i<length;i++){zd3c791df3e=zd3c791df3e+data[i];
if(zd3c791df3e>(0x17f0+622-0x195f)){zd3c791df3e-=(0x16c3+3140-0x2208);
}}
return(uint8_T)(~zd3c791df3e);
}static int8_T z963e43522f(SimStruct*S,uint32_T z31a846515d,uint8_T zc369e1e9c6,uint8_T id,uint8_T type,uint8_T length,uint8_T*data){int32_T z563e4da9f6,position;z5d859c8e2d*z256cbcfc8b;z563e4da9f6=(0x5c9+7495-0x230f);if((id<(0x1027+2699-0x1ab2)||id>(0x2ba+602-0x4d5))&&type==(0x897+5427-0x1dca)){z563e4da9f6=-(0x944+5439-0x1e81);
}if(length>(0x12f0+4699-0x2543)){z563e4da9f6=-(0x978+5469-0x1ed2);}if(z563e4da9f6>(0x21fb+281-0x2314)){if(!ptrWritePointer){sprintf(zea4cd01646,"\x4c\x4d\x57\x20\x53\x65\x6e\x64\x4c\x49\x4e\x4d\x65\x73\x73\x61\x67\x65\x3a\x20\x70\x74\x72\x57\x72\x69\x74\x65\x50\x6f\x69\x6e\x74\x65\x72\x20\x69\x73\x20\x4e\x55\x4c\x4c" "\n");ssSetErrorStatus(S,zea4cd01646);return-(0x20ea+707-0x23aa);}position=ptrWritePointer[zc369e1e9c6];
z256cbcfc8b=(z5d859c8e2d*)(z31a846515d+(0x1958+3341-0x1665)+position*sizeof(z5d859c8e2d));if(z256cbcfc8b->status==(0x1704+3293-0x23e1)){z256cbcfc8b->count=(0x1388+2327-0x1c93)+length;
z256cbcfc8b->type=type;
z256cbcfc8b->z636e2cf3e0=(0x586+1585-0xbb7);z256cbcfc8b->zf528bd284e=z746f98b245(id);z256cbcfc8b->z6fca5ff095=(0x457+1963-0xc02);z256cbcfc8b->checkSum=CheckSum(length,data);z256cbcfc8b->z11f2a08c09=(0x1099+4717-0x2305);z256cbcfc8b->length=length;z256cbcfc8b->zdcc6ef6f12=(0xa4f+4780-0x1cfb);z256cbcfc8b->data[(0x814+4456-0x197c)]=data[(0x19c3+23-0x19da)];
z256cbcfc8b->data[(0x1710+3569-0x2500)]=data[(0x126c+627-0x14de)];z256cbcfc8b->data[(0x1173+2416-0x1ae1)]=data[(0x123c+4993-0x25bb)];z256cbcfc8b->data[(0x12ef+4745-0x2575)]=data[(0x1150+3923-0x20a0)];z256cbcfc8b->data[(0x194d+900-0x1ccd)]=data[(0x61+3153-0xcae)];z256cbcfc8b->data[(0x1924+3467-0x26aa)]=data[(0xa11+1322-0xf36)];z256cbcfc8b->data[(0x4b1+1416-0xa33)]=data[(0x7fb+4817-0x1ac6)];z256cbcfc8b->data[(0x161b+2692-0x2098)]=data[(0x951+2918-0x14b0)];z256cbcfc8b->status=(0x172f+1387-0x1c99);
position=(position==(0xa66+3909-0x197a))?(0x1787+1064-0x1baf):++position;ptrWritePointer[zc369e1e9c6]=position;}else{z563e4da9f6=-(0x8d+283-0x1a7);}}return z563e4da9f6;}
#endif
static void mdlInitializeSizes(SimStruct*S){int_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xac7+6127-0x22b6));ssSetNumDiscStates(S,(0xf8c+411-0x1127));ssSetNumInputPorts(S,(0xfe6+1327-0x150a));for(i=(0x1872+1147-0x1ced);i<(0x4f0+6501-0x1e4a);i++){ssSetInputPortDirectFeedThrough(S,i,(0x15f+1241-0x637));ssSetInputPortRequiredContiguous(S,i,(0x1c6a+2534-0x264f));ssSetInputPortDataType(S,i,SS_UINT8);ssSetInputPortWidth(S,i,(uint32_T)mxGetPr(z8be821e1c6)[(0x2503+220-0x25df)]);}ssSetNumOutputPorts(S,(0x12d1+4684-0x251d));ssSetNumSampleTimes(S,(0x18f3+832-0x1c32));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,(0x1f6+5587-0x17c9));ssSetNumModes(S,(0x223+1612-0x86f));ssSetNumNonsampledZCs(S,(0x14bf+1759-0x1b9e));for(i=(0x46d+2309-0xd72);i<zdf24515981;i++){ssSetSFcnParamNotTunable(S,i);}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x69+375-0x1e0),mxGetPr(z3832b85a32)[(0x17e1+1010-0x1bd3)]);if(mxGetN((z3832b85a32))==(0x3a0+1274-0x899)){ssSetOffsetTime(S,(0x56f+4399-0x169e),0.0);}else{ssSetOffsetTime(S,(0x830+2568-0x1238),mxGetPr(z3832b85a32)[(0x26a+9267-0x269c)]);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;
#ifdef zb482f925e2
printf("\x4d\x57\x73\x74\x61\x72\x74\x20\x62\x65\x67\x69\x6e" "\n");
#endif
if(mxGetN(z702a26a5e9)==(0x2f1+6901-0x1de5)){z366b2f03bf=(0x1ad2+2313-0x23db);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xa1+8121-0x205a)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x4+9916-0x26c0)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x1ba3+2138-0x23fc)];}if(xpcGetPCIDeviceInfo((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x4c\x4d\x57\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}rl32eWaitDouble(0.05);
zeccbadd9b3.VirtAddress[(0xa7b+1396-0xfed)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0xb28+6938-0x2640)],zeccbadd9b3.Length[(0x1cca+313-0x1e01)],XPC_RT_PG_USERREADWRITE);zeccbadd9b3.VirtAddress[(0x3a3+180-0x457)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x1c1c+1207-0x20d3)],zeccbadd9b3.Length[(0x508+4874-0x1812)],XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x299+174-0x345)]);ssSetIWorkValue(S,z4fc736908d,zeccbadd9b3.VirtAddress[(0xa73+78-0xac1)]);
#ifdef zb482f925e2
printf("\x4d\x57\x73\x74\x61\x72\x74\x20\x65\x6e\x64" "\n");
#endif
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE       

uint8_T data[(0x7a3+1918-0xf19)];uint8_T id;uint8_T length;uint8_T i,z26dbd73a5e;uint8_T*u;int8_T z563e4da9f6;uint8_T type;
volatile uint32_T*z3e5b8e05d8;uint32_T z5d9c31c2b6,z31a846515d;
uint32_T zc1ac25c1d6;uint8_T zc369e1e9c6;
#ifdef zb482f925e2
printf("\x4d\x57\x20\x62\x65\x67\x69\x6e");
#endif
z5d9c31c2b6=ssGetIWorkValue(S,z4fc736908d);z3e5b8e05d8=(void*)z5d9c31c2b6;z31a846515d=ssGetIWorkValue(S,z6a0da049de);zc369e1e9c6=(uint32_T)mxGetPr(zbcb3e4d083)[(0x322+2555-0xd1d)]-(0x2e8+8247-0x231e);for(i=(0x154+1750-0x82a);i<(uint32_T)mxGetPr(z8be821e1c6)[(0x8a9+176-0x959)];i++){
u=(uint8_T*)ssGetInputPortSignal(S,(0x13f6+2364-0x1d32));type=(uint8_T)u[i];u=(uint8_T*)ssGetInputPortSignal(S,(0x17a+2709-0xc0e));id=(uint8_T)u[i];u=(uint8_T*)ssGetInputPortSignal(S,(0x1134+406-0x12c8));length=(uint8_T)u[i];for(z26dbd73a5e=(0x27c+2915-0xddf);z26dbd73a5e<(0xfa1+4953-0x22f2);z26dbd73a5e++){u=(uint8_T*)ssGetInputPortSignal(S,(0x57+8636-0x2210)+z26dbd73a5e);data[z26dbd73a5e]=(uint8_T)u[i];}z563e4da9f6=z963e43522f(S,z31a846515d,zc369e1e9c6,id,type,length,data);switch(z563e4da9f6){case(0xdf5+1613-0x1441):
zc1ac25c1d6=z3e5b8e05d8[(0x1213+3938-0x2160)];z3e5b8e05d8[(0xefd+524-0x10f4)]=zc1ac25c1d6&~((0x10e3+2722-0x1b84)<<(0x32c+2934-0xea0));z3e5b8e05d8[(0x2bb+8211-0x22b9)]=zc1ac25c1d6|((0xdd4+4232-0x1e5b)<<(0x15fb+1812-0x1d0d));break;case-(0x3f+1628-0x69a):printf("\x25\x73\x20\x4c\x49\x4e\x20\x4d\x57\x20\x71\x75\x65\x75\x65\x20\x6f\x76\x65\x72\x6c\x6f\x61\x64\x65\x64\x2e" "\n",zf1b619edf2);
zc1ac25c1d6=z3e5b8e05d8[(0x1333+1724-0x19da)];z3e5b8e05d8[(0x3e6+8591-0x2560)]=zc1ac25c1d6&~((0x1bc0+2185-0x2448)<<(0x4ab+3453-0x1226));z3e5b8e05d8[(0x1b4c+1181-0x1fd4)]=zc1ac25c1d6|((0x12b6+1912-0x1a2d)<<(0x9ff+3704-0x1875));


break;case-(0x4b7+4778-0x175f):sprintf(zea4cd01646,"\x25\x73\x20\x49\x6e\x63\x6f\x72\x72\x65\x63\x74\x20\x4c\x49\x4e\x20\x69\x64\x2e",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;case-(0xc0c+3046-0x17ef):sprintf(zea4cd01646,"\x25\x73\x20\x49\x6e\x63\x6f\x72\x72\x65\x63\x74\x20\x6d\x65\x73\x73\x61\x67\x65\x20\x6c\x65\x6e\x67\x74\x68\x2e",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;default:sprintf(zea4cd01646,"\x25\x73\x20\x55\x6e\x6b\x6e\x6f\x77\x6e\x20\x65\x72\x72\x6f\x72\x20\x69\x6e\x20\x53\x65\x6e\x64\x4c\x49\x4e\x4d\x65\x73\x73\x61\x67\x65\x28\x29\x2e",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}
#ifdef zb482f925e2
printf("\x4d\x57\x20\x65\x6e\x64");
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

