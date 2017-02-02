/* Copyright 2006-2013 Speedgoat GmbH. */
#define S_FUNCTION_LEVEL (0x2006+1479-0x25cb)
#undef S_FUNCTION_NAME
#define S_FUNCTION_NAME sg_IO601_linslavewrite_s
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
#define z29146a1837            ((0x11fc+9391-0x25f6))
#define zab7e64468b            (10615)
#define zdf24515981         ((0x7fb+3920-0x1747))
#define zbcb3e4d083             ssGetSFcnParam(S, (0x60c+1496-0xbe4))
#define z8be821e1c6         ssGetSFcnParam(S, (0x1ea8+481-0x2088))
#define z3832b85a32          ssGetSFcnParam(S, (0x1782+2892-0x22cc))
#define z702a26a5e9               ssGetSFcnParam(S, (0x1146+3973-0x20c8))
#define z2e6483d505             ((0xa96+5089-0x1e75))
#define z6a0da049de        ((0x18dd+2848-0x23fd))
#define z4fc736908d       ((0xde4+5194-0x222d))
#define zc5ce4cb81a             ((0x4f+7769-0x1ea8))
#define z2b17e2ee3b             ((0x1375+4343-0x246c))
static char_T zea4cd01646[(0xfe0+5397-0x23f5)];
#ifndef MATLAB_MEX_FILE
typedef struct{uint8_T zc35c0f42b9;uint8_T za6e45e4916;uint8_T z0375dad321;uint8_T zf42e3db443;uint8_T z263746de21;uint8_T ze51815850a;uint8_T z75ca12472b[(0x26d+5438-0x17a3)];}z71e526926d;typedef struct{uint8_T z787fcfe334:(0x1008+1960-0x17af),zdc0b977329:(0x1622+3534-0x23ef),zaae2cd1378:(0x1309+2891-0x1e53),zf2008ed5e1:(0xdfd+5985-0x255d),za978b3e9be:(0x15c3+2284-0x1eae),z7159ca38e3:(0xd45+5167-0x2173),z11a8412f0c:(0xcab+845-0xff7),zcf452bf3c7:(0x11eb+2133-0x1a3f);}z149e1b8f6c;typedef union{uint8_T b;z149e1b8f6c u;}z6f5aefeff2;static uint8_T z746f98b245(uint8_T id){z6f5aefeff2 z526d1e6e88;z526d1e6e88.b=id;z526d1e6e88.u.z11a8412f0c=z526d1e6e88.u.z787fcfe334^z526d1e6e88.u.zdc0b977329^z526d1e6e88.u.zaae2cd1378^z526d1e6e88.u.za978b3e9be;z526d1e6e88.u.zcf452bf3c7=~(z526d1e6e88.u.zdc0b977329^z526d1e6e88.u.zf2008ed5e1^z526d1e6e88.u.za978b3e9be^z526d1e6e88.u.z7159ca38e3);return(uint8_T)z526d1e6e88.b;}static uint8_T CheckSum(uint8_T length,uint8_T*data){uint8_T i;uint16_T zd3c791df3e=(0x1e18+647-0x209f);for(i=(0x390+34-0x3b2);i<length;i++){zd3c791df3e=zd3c791df3e+data[i];
if(zd3c791df3e>(0x131a+4045-0x21e8)){zd3c791df3e-=(0x1d27+1319-0x214f);
}}
return(uint8_T)(~zd3c791df3e);
}static int8_T zadd973cac1(uint32_T base,uint8_T id,uint8_T length,uint8_T*data){
int32_T z563e4da9f6;uint8_T z3b4e8c7655,z24104a0f6d;volatile z71e526926d*message;volatile uint8_T*za42cf7dd4a;
z563e4da9f6=(0x589+3907-0x14cc);z3b4e8c7655=(0x5ed+5756-0x1c69);z24104a0f6d=(0x167c+2004-0x1e50);za42cf7dd4a=(uint8_T*)(base);if(id<(0xd3+5880-0x17cb)||id>(0x82a+2548-0x11df)){z563e4da9f6=-(0x18c8+1253-0x1dab);
}if(length>(0x8f0+3845-0x17ed)){z563e4da9f6=-(0x12+5841-0x16e0);}

if(z563e4da9f6==(0x2488+101-0x24ed)){while(!z3b4e8c7655||!z24104a0f6d){if(!z3b4e8c7655){
za42cf7dd4a[(0x2198+1099-0x5e3)+(0x35f+2652-0xdb9)]=(0x1782+3644-0x25be);if(za42cf7dd4a[8192+(0xaa6+4136-0x1acc)]==(0x2093+755-0x2386)){
message=(z71e526926d*)(base+6312+id*sizeof(z71e526926d));message->zc35c0f42b9=z746f98b245(id);
message->za6e45e4916=(0xd66+6548-0x26fa);message->z0375dad321=CheckSum(length,data);message->zf42e3db443=(0x285+6052-0x1a28);message->z263746de21=length;
message->ze51815850a=(0x17ad+2682-0x2227);message->z75ca12472b[(0xeac+6186-0x26d6)]=data[(0x801+2594-0x1223)];
message->z75ca12472b[(0x1d61+1892-0x24c4)]=data[(0x2db+8437-0x23cf)];message->z75ca12472b[(0x632+1098-0xa7a)]=data[(0xea1+325-0xfe4)];message->z75ca12472b[(0x105c+755-0x134c)]=data[(0x1443+4709-0x26a5)];message->z75ca12472b[(0x94f+3563-0x1736)]=data[(0xec+9157-0x24ad)];message->z75ca12472b[(0x2ba+6237-0x1b12)]=data[(0xd0a+3764-0x1bb9)];message->z75ca12472b[(0x1b26+1879-0x2277)]=data[(0x9e3+6885-0x24c2)];message->z75ca12472b[(0xb5f+1644-0x11c4)]=data[(0x1b0+7476-0x1edd)];z3b4e8c7655=(0x9fb+2602-0x1424);
za42cf7dd4a[(0x2610+7694-0x241e)+(0x13f0+364-0x155a)]=(0x1700+3190-0x2375);}}if(!z24104a0f6d){
za42cf7dd4a[8192+(0x5d0+8068-0x2551)]=(0xc07+4116-0x1c1b);if(za42cf7dd4a[8192+(0x1e4f+1517-0x2439)]==(0x9c+7951-0x1fab)){message=(z71e526926d*)(base+7208+id*sizeof(z71e526926d));message->zc35c0f42b9=z746f98b245(id);
message->za6e45e4916=(0x615+8381-0x26d2);message->z0375dad321=CheckSum(length,data);message->zf42e3db443=(0x3ed+5835-0x1ab7);message->z263746de21=length;
message->ze51815850a=(0x55c+827-0x897);message->z75ca12472b[(0x11a9+4591-0x2398)]=data[(0x1052+3062-0x1c48)];message->z75ca12472b[(0xda5+4414-0x1ee2)]=data[(0x1c1a+363-0x1d84)];message->z75ca12472b[(0x1a49+94-0x1aa5)]=data[(0x7fd+6689-0x221c)];message->z75ca12472b[(0xc+1895-0x770)]=data[(0x12a4+3602-0x20b3)];message->z75ca12472b[(0x97f+3863-0x1892)]=data[(0x261b+41-0x2640)];message->z75ca12472b[(0x14ec+1302-0x19fd)]=data[(0x166a+1490-0x1c37)];message->z75ca12472b[(0x131+3346-0xe3d)]=data[(0xa8+1647-0x711)];message->z75ca12472b[(0xe8b+5839-0x2553)]=data[(0x84c+3435-0x15b0)];z24104a0f6d=(0x401+7459-0x2123);
za42cf7dd4a[(0x2628+478-0x806)+(0x1096+3613-0x1eb0)]=(0x147f+4283-0x2539);}}}}return z563e4da9f6;}
#endif
static void mdlInitializeSizes(SimStruct*S){int_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xc09+354-0xd6b));ssSetNumDiscStates(S,(0x98+5486-0x1606));
ssSetNumInputPorts(S,(0x1cdd+2534-0x26b9));for(i=(0x595+193-0x656);i<(0x801+177-0x8a8);i++){ssSetInputPortDirectFeedThrough(S,i,(0x10ff+4544-0x22be));ssSetInputPortRequiredContiguous(S,i,(0x254+9359-0x26e2));ssSetInputPortDataType(S,i,SS_UINT8);ssSetInputPortWidth(S,i,(uint32_T)mxGetPr(z8be821e1c6)[(0x839+7036-0x23b5)]);}ssSetNumSampleTimes(S,(0x2f+8822-0x22a4));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,(0x4d+1507-0x630));ssSetNumModes(S,(0x88a+6251-0x20f5));ssSetNumNonsampledZCs(S,(0xd6+3972-0x105a));for(i=(0xf88+2709-0x1a1d);i<zdf24515981;i++){ssSetSFcnParamNotTunable(S,i);}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x1d75+1075-0x21a8),mxGetPr(z3832b85a32)[(0x5a+5784-0x16f2)]);if(mxGetN((z3832b85a32))==(0x26c+8415-0x234a)){ssSetOffsetTime(S,(0xed4+6038-0x266a),0.0);}else{ssSetOffsetTime(S,(0x3cd+577-0x60e),mxGetPr(z3832b85a32)[(0x45f+3738-0x12f8)]);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x1e8+6766-0x1c55)){z366b2f03bf=(0x2473+611-0x26d6);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x27c+6163-0x1a8f)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x16c2+322-0x1804)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x611+4126-0x162e)];}if(xpcGetPCIDeviceInfo((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x4c\x53\x57\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}rl32eWaitDouble(0.05);
zeccbadd9b3.VirtAddress[(0x1c64+1673-0x22eb)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x1262+3147-0x1eab)],zeccbadd9b3.Length[(0x1c9b+79-0x1ce8)],XPC_RT_PG_USERREADWRITE);zeccbadd9b3.VirtAddress[(0x1466+3228-0x2102)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0xc96+1567-0x12b5)],zeccbadd9b3.Length[(0x252a+165-0x25cf)],XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x683+8069-0x2606)]);ssSetIWorkValue(S,z4fc736908d,zeccbadd9b3.VirtAddress[(0x2130+183-0x21e7)]);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint8_T*u;uint8_T id,length;uint8_T data[(0x429+6512-0x1d91)];uint32_T i;volatile uint32_T*z3e5b8e05d8;uint32_T zc1ac25c1d6;uint32_T z5d9c31c2b6=ssGetIWorkValue(S,z4fc736908d);uint32_T z31a846515d=ssGetIWorkValue(S,z6a0da049de);z3e5b8e05d8=(void*)z5d9c31c2b6;
for(i=(0xa53+7067-0x25ee);i<(uint8_T)mxGetPr(z8be821e1c6)[(0xd67+5088-0x2147)];i++){
u=(uint8_T*)ssGetInputPortSignal(S,(0x12c3+2471-0x1c6a));id=(uint8_T)u[i];u=(uint8_T*)ssGetInputPortSignal(S,(0x952+5888-0x2051));length=(uint8_T)u[i];u=(uint8_T*)ssGetInputPortSignal(S,(0xd5a+1022-0x1156));data[(0x566+7067-0x2101)]=(uint8_T)u[i];u=(uint8_T*)ssGetInputPortSignal(S,(0x11d3+210-0x12a2));data[(0x523+8655-0x26f1)]=(uint8_T)u[i];u=(uint8_T*)ssGetInputPortSignal(S,(0xed0+47-0xefb));data[(0xe5a+1153-0x12d9)]=(uint8_T)u[i];u=(uint8_T*)ssGetInputPortSignal(S,(0x923+196-0x9e2));data[(0xbcb+1448-0x1170)]=(uint8_T)u[i];u=(uint8_T*)ssGetInputPortSignal(S,(0x1f5c+768-0x2256));data[(0x6ab+1976-0xe5f)]=(uint8_T)u[i];u=(uint8_T*)ssGetInputPortSignal(S,(0x5fa+2404-0xf57));data[(0x855+4507-0x19eb)]=(uint8_T)u[i];u=(uint8_T*)ssGetInputPortSignal(S,(0xe51+1084-0x1285));data[(0x15ab+2307-0x1ea8)]=(uint8_T)u[i];u=(uint8_T*)ssGetInputPortSignal(S,(0x1221+2789-0x1cfd));data[(0x48f+5100-0x1874)]=(uint8_T)u[i];
if(zadd973cac1(z31a846515d,id,length,data)==(0x760+1526-0xd55)){zc1ac25c1d6=z3e5b8e05d8[(0xc9d+4279-0x1d3f)];z3e5b8e05d8[(0x1979+3239-0x260b)]=zc1ac25c1d6&~((0x10d5+1366-0x162a)<<(0x13af+3047-0x1f94));z3e5b8e05d8[(0x12f5+1150-0x175e)]=zc1ac25c1d6|((0x122a+4458-0x2393)<<(0x62a+8417-0x2709));}}
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

