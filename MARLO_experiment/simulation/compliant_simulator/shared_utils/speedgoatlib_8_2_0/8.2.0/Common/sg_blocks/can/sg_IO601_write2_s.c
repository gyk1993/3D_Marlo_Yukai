/* Copyright 2006-2013 Speedgoat GmbH. */
#define         DEBUG                  (0x1557+2354-0x1e89)
#define         S_FUNCTION_LEVEL       (0xd41+454-0xf05)
#undef          S_FUNCTION_NAME
#define         S_FUNCTION_NAME        sg_IO601_write2_s
#include        <stddef.h>
#include        <stdlib.h>
#include        "simstruc.h"
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x36\x30\x31"
#define z694756a014 (0x2165+4830-0x238e)
#define zea87e0ba83 36912
#define z29146a1837 (0x231c+478-0x1445)
#define zab7e64468b 10615
#define         z01f8dc1780            536870911
#define         za207ed9b4c            (0x137c+4645-0x1da2)
#define         zdf24515981         ((0x227+3262-0xedd))
#define         zbcb3e4d083             ssGetSFcnParam(S,(0x1069+3530-0x1e33))
#define         z11e8538834             ssGetSFcnParam(S,(0x460+1064-0x887))
#define         zfdec0918ff   ssGetSFcnParam(S,(0xc1+1897-0x828))
#define         za86ac132cf              ssGetSFcnParam(S,(0xed9+3442-0x1c48))
#define         z1de802f68c             ssGetSFcnParam(S,(0x9f+3704-0xf13))
#define         z9cd34e3860               ssGetSFcnParam(S,(0xb45+3974-0x1ac6))
#define         z3832b85a32          ssGetSFcnParam(S,(0xadc+2377-0x141f))
#define         z702a26a5e9               ssGetSFcnParam(S,(0x21a1+328-0x22e2))
#define z2e6483d505              ((0x144+6345-0x1a0b))
#define z57e55a08c5        ((0x4df+5753-0x1b58))
#define z84eb1db314        ((0x39d+6781-0x1e19))
#define zc5ce4cb81a              ((0x1ee9+812-0x2215))
#define z2b17e2ee3b              ((0x326+5631-0x1925))
#ifndef  zb84e0c3c3b
#define  zb84e0c3c3b(zc1d61b7d63)  *( (uint8_T *) &zc1d61b7d63)
#endif
#ifndef  z15e663b423
#define  z15e663b423(zc1d61b7d63)  *(((uint8_T *) &zc1d61b7d63) + (0xa5d+856-0xdb4))
#endif
#ifndef  zfca7eb6338
#define  zfca7eb6338(zc1d61b7d63)  *( (uint16_T *) &zc1d61b7d63)
#endif
#ifndef  z3607971cd6
#define  z3607971cd6(zc1d61b7d63)  *(((uint16_T *) &zc1d61b7d63) + (0x3ca+6935-0x1ee0))
#endif
#ifndef z0056adfa94
#define z0056adfa94(zc1d61b7d63)       { uint8_T z7be9105675; z7be9105675 = z15e663b423(zc1d61b7d63); z15e663b423(zc1d61b7d63) = (uint8_T) zc1d61b7d63; zb84e0c3c3b(zc1d61b7d63) = z7be9105675; }
#endif
#ifndef z8444fc96d2
#define z8444fc96d2(zc1d61b7d63)       { uint16_T z7be9105675; z7be9105675 = z3607971cd6(zc1d61b7d63); z3607971cd6(zc1d61b7d63) = (uint16_T) zc1d61b7d63; zfca7eb6338(zc1d61b7d63) = z7be9105675; }
#endif
static char_T zea4cd01646[(0x173+5799-0x171a)];










typedef struct{uint8_T z1fde0a5efd;uint8_T Length;uint8_T ze0cf853226;uint8_T Error;uint32_T ID;double Timestamp;uint8_T Data[(0xecd+2350-0x17f3)];}z80857f1537;
#ifndef MATLAB_MEX_FILE
extern uint8_T z199556e987[];static uint32_T zb2ab7dbb1a(uint32_T value){value=value<<(0x1334+1900-0x1a8b);z0056adfa94(z3607971cd6(value));z0056adfa94(zfca7eb6338(value));z8444fc96d2(value);return(value);}static uint32_T zdd53c2bd21(uint32_T value){value=value<<(0x1db4+142-0x1e3f);z0056adfa94(z3607971cd6(value));z0056adfa94(zfca7eb6338(value));z8444fc96d2(value);return(value);}static unsigned char zf6c13379ed(double value,int n){unsigned char*p;p=(unsigned char*)&value;return p[n];}
#endif
static void mdlInitializeSizes(SimStruct*S){int_T i;int_T z9dc9623fa2,status;DTypeId id;z80857f1537 z52754d10b7;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x16ff+1085-0x1b3c));ssSetNumDiscStates(S,(0x5bf+1028-0x9c3));
#ifdef MATLAB_MEX_FILE
if((int_T)mxGetPr(za86ac132cf)[(0x11fc+2192-0x1a8c)]){ssSetNumInputPorts(S,(0x1492+278-0x15a6));ssSetInputPortWidth(S,(0x609+5081-0x19e1),(0xbdd+2013-0x13b9));ssSetInputPortDirectFeedThrough(S,(0x1380+3859-0x2292),(0x1e39+1851-0x2573));ssSetInputPortRequiredContiguous(S,(0xc2b+4894-0x1f48),(0x12bb+4670-0x24f8));}else{ssSetNumInputPorts(S,(0x1312+4350-0x240f));}
if((int_T)mxGetPr(zfdec0918ff)[(0x22b2+341-0x2407)]==(0x1c06+2343-0x252c)){if(!ssSetInputPortMatrixDimensions(S,(0xcbc+5523-0x224f),DYNAMICALLY_SIZED,DYNAMICALLY_SIZED))return;}else{


id=ssRegisterDataType(S,"\x43\x41\x4e\x5f\x4d\x45\x53\x53\x41\x47\x45");if(id==INVALID_DTYPE_ID)return;status=ssSetDataTypeSize(S,id,sizeof(z52754d10b7));z9dc9623fa2=ssGetDataTypeId(S,"\x43\x41\x4e\x5f\x4d\x45\x53\x53\x41\x47\x45");ssSetInputPortDataType(S,(0x118f+2808-0x1c87),z9dc9623fa2);ssSetInputPortWidth(S,(0xb0a+6115-0x22ed),mxGetPr(z1de802f68c)[(0xf79+5583-0x2548)]);}ssSetInputPortDirectFeedThrough(S,(0xe49+1707-0x14f4),(0x1f6+2708-0xc89));ssSetInputPortRequiredContiguous(S,(0x1874+2842-0x238e),(0x485+1842-0xbb6));if((int_T)mxGetPr(z11e8538834)[(0x343+2442-0xccd)]&&(int_T)mxGetPr(zfdec0918ff)[(0x1251+5014-0x25e7)]==(0x1241+846-0x158e)){ssSetNumOutputPorts(S,(0xead+1138-0x131e));ssSetOutputPortWidth(S,(0x16eb+736-0x19cb),DYNAMICALLY_SIZED);}else if((int_T)mxGetPr(z11e8538834)[(0x1ee1+798-0x21ff)]&&(int_T)mxGetPr(zfdec0918ff)[(0xbe6+447-0xda5)]==(0x61c+1195-0xac5)){ssSetNumOutputPorts(S,(0x5b9+5743-0x1c27));ssSetOutputPortWidth(S,(0x1b25+1036-0x1f31),mxGetPr(z1de802f68c)[(0x10b+7036-0x1c87)]);}else{ssSetNumOutputPorts(S,(0x7fc+5346-0x1cde));}
#endif
ssSetNumSampleTimes(S,(0xaf5+157-0xb91));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,(0x186+3384-0xebe));ssSetNumModes(S,(0xda9+5536-0x2349));ssSetNumNonsampledZCs(S,(0x13c+1461-0x6f1));for(i=(0x29b+8864-0x253b);i<zdf24515981;i++){ssSetSFcnParamNotTunable(S,i);}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}
#define z66116822c9
static void mdlSetInputPortDimensionInfo(SimStruct*S,int zb9276e93a2,const DimsInfo_T*zde3f224951){if((int_T)mxGetPr(zfdec0918ff)[(0x19d8+1423-0x1f67)]==(0x1aa0+2118-0x22e5)){if(zde3f224951->dims[(0xaad+5602-0x208e)]!=(0x10e9+899-0x1467)&&zde3f224951->dims[(0x195+1137-0x605)]!=(0x3b4+1225-0x877)){sprintf(zea4cd01646,"\x49\x6e\x70\x75\x74\x20\x6d\x75\x73\x74\x20\x62\x65\x20\x61\x20\x6d\x2a\x35\x20\x6f\x72\x20\x61\x20\x6d\x2a\x36\x20\x20\x6d\x61\x74\x72\x69\x78");ssSetErrorStatus(S,zea4cd01646);return;}if(!ssSetInputPortDimensionInfo(S,zb9276e93a2,zde3f224951))return;if((int_T)mxGetPr(z11e8538834)[(0x12d3+4535-0x248a)]){if(!ssSetOutputPortVectorDimension(S,(0x4aa+5365-0x199f),zde3f224951->dims[(0xf1f+6099-0x26f2)]))return;}}}
#define z12b5c990f1
static void mdlSetOutputPortDimensionInfo(SimStruct*S,int zb9276e93a2,const DimsInfo_T*zde3f224951){if(!ssSetOutputPortDimensionInfo(S,zb9276e93a2,zde3f224951))return;}
#define z4fd520fcfe
static void mdlSetDefaultPortDimensionInfo(SimStruct*S){if((int_T)mxGetPr(zfdec0918ff)[(0x66b+2755-0x112e)]==(0x1240+4790-0x24f5)){if(!ssSetInputPortMatrixDimensions(S,(0x699+4478-0x1817),(0x2d2+3617-0x10f2),(0x2b1+548-0x4d0)))return;if((int_T)mxGetPr(z11e8538834)[(0x17db+16-0x17eb)]){if(!ssSetOutputPortVectorDimension(S,(0x1044+148-0x10d8),(0xcf0+997-0x10d4)))return;}}}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0xd26+3586-0x1b28),mxGetPr(z3832b85a32)[(0x2c6+7471-0x1ff5)]);if(mxGetN((z3832b85a32))==(0xb76+3553-0x1956)){ssSetOffsetTime(S,(0x4cc+6356-0x1da0),0.0);}else{ssSetOffsetTime(S,(0x56f+1081-0x9a8),mxGetPr(z3832b85a32)[(0xd13+5173-0x2147)]);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zef529fae4a,*zdfcb1da404;void*ze2370ae9b9,*zf2db5722bf;volatile uint32_T*z3e5b8e05d8;volatile uint8_T*z27fd94ac66;volatile uint32_T*z706da0e1e5;uint8_T zc369e1e9c6;zc369e1e9c6=(uint8_T)mxGetPr(zbcb3e4d083)[(0x1b1a+2532-0x24fe)]-(0x502+7083-0x20ac);if((int_T)mxGetPr(z702a26a5e9)[(0x2e4+5117-0x16e1)]<(0x55+9330-0x24c7)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xc8c+1591-0x12c2)){z366b2f03bf=(0xa31+4499-0x1bc4);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x16cb+2219-0x1f76)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x3e1+6440-0x1d09)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x341+7124-0x1f14)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x914+4997-0x1b9a))|((z366b2f03bf&(0xc4d+817-0xe7f))<<(0x7f3+3814-0x16d1)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zef529fae4a=(void*)zeccbadd9b3.BaseAddress[(0xefd+2137-0x1756)];ze2370ae9b9=rl32eGetDevicePtr(zef529fae4a,(0x1605+514-0x16df),RT_PG_USERREADWRITE);z3e5b8e05d8=(volatile uint32_T*)ze2370ae9b9;
zdfcb1da404=(void*)zeccbadd9b3.BaseAddress[(0x1e9+5781-0x187c)];zf2db5722bf=rl32eGetDevicePtr(zdfcb1da404,16384,RT_PG_USERREADWRITE);z27fd94ac66=(volatile uint8_T*)zf2db5722bf;z706da0e1e5=(volatile uint32_T*)zf2db5722bf;
ssSetIWorkValue(S,z57e55a08c5,(uint32_T)z3e5b8e05d8);ssSetIWorkValue(S,z84eb1db314,(uint32_T)z27fd94ac66);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
int_T z563e4da9f6,i,m,z26dbd73a5e,z97d855d69f,z2b9653a7df;uint8_T*z42362badca;real_T*u,*y,*in,z266f92ba7c;z80857f1537*zcc6fcdb7f7;int_T z9e4a2d1ebd;int_T z7b5c8c9301;int_T*dims;int_T zc430a259a4,za1bbbf817a,ze7b7ebebbf;uint32_T zc1ac25c1d6,z7be9105675;uint8_T zc369e1e9c6=(uint8_T)mxGetPr(zbcb3e4d083)[(0x1006+5731-0x2669)]-(0x744+6452-0x2077);uint8_T message[(0x1012+1931-0x1789)];uint32_T za6dad42b7e[(0x170d+2305-0x2009)];volatile uint32_T*z3e5b8e05d8;volatile uint32_T*z706da0e1e5;uint32_T z5d9c31c2b6=ssGetIWorkValue(S,z57e55a08c5);uint32_T z31a846515d=ssGetIWorkValue(S,z84eb1db314);z3e5b8e05d8=(volatile uint32_T*)z5d9c31c2b6;z706da0e1e5=(volatile uint32_T*)z31a846515d;if((int_T)mxGetPr(zfdec0918ff)[(0x10c6+2951-0x1c4d)]==(0x1e3+7397-0x1ec6)){
zcc6fcdb7f7=(z80857f1537*)ssGetInputPortSignal(S,(0x149c+4475-0x2617));if((int_T)mxGetPr(z11e8538834)[(0x126c+2-0x126e)]){y=(real_T*)ssGetOutputPortSignal(S,(0x12cd+96-0x132d));}dims=ssGetInputPortDimensions(S,(0x85c+4336-0x194c));if((int_T)mxGetPr(za86ac132cf)[(0x4ea+7712-0x230a)]){

in=(real_T*)ssGetInputPortSignal(S,(0x1551+2208-0x1df0));z7b5c8c9301=(int_T)in[(0xf40+5513-0x24c9)];
if(z7b5c8c9301>dims[(0x62c+7471-0x235b)]){z7b5c8c9301=dims[(0xb+8421-0x20f0)];}}else{z7b5c8c9301=dims[(0xba6+2795-0x1691)];}for(z9e4a2d1ebd=(0x561+8592-0x26f1);z9e4a2d1ebd<z7b5c8c9301;z9e4a2d1ebd++){
int32_T ident=zcc6fcdb7f7[z9e4a2d1ebd].ID;uint8_T type=zcc6fcdb7f7[z9e4a2d1ebd].z1fde0a5efd;uint8_T z38357fbbbb=zcc6fcdb7f7[z9e4a2d1ebd].Length;uint8_T z22f55d8c9c=zcc6fcdb7f7[z9e4a2d1ebd].ze0cf853226;int_T za1bbbf817a=(0xd8b+1326-0x12b8);




if(ident<(0xbb+8091-0x2056)){
za1bbbf817a=(0x47f+3651-0x12c2);}if(type!=(0x9ef+2000-0x11bf)&&type!=(0x644+5583-0x1c12)){za1bbbf817a=(0x51a+2570-0xf24);z563e4da9f6=-(0xeca+5280-0x235f);
}switch(type){case(0x76b+5273-0x1c04):if(ident>(0x20b6+529-0x1ac8)){za1bbbf817a=(0x1212+743-0x14f9);z563e4da9f6=-(0xf3c+4184-0x1f88);
}break;case(0x7a8+3381-0x14dc):if(ident>536870911){za1bbbf817a=(0xebf+2817-0x19c0);z563e4da9f6=-(0x13ab+2772-0x1e72);}break;}if(z38357fbbbb>(0x1056+5125-0x2453)){za1bbbf817a=(0x42c+8455-0x2533);z563e4da9f6=-(0x909+3958-0x1871);}if(za1bbbf817a){if(z22f55d8c9c){sprintf(zea4cd01646,"\x52\x65\x6d\x6f\x74\x65\x20\x66\x72\x61\x6d\x65\x20\x61\x72\x65\x20\x6e\x6f\x74\x20\x73\x75\x70\x70\x6f\x72\x74\x65\x64\x20\x79\x65\x74\x2e");ssSetErrorStatus(S,zea4cd01646);return;}else{}z97d855d69f=z199556e987[(0x182+2006-0x958)+zc369e1e9c6*(0x3a9+8596-0x2539)];z2b9653a7df=z199556e987[(0x599+5124-0x199c)+zc369e1e9c6*(0x2d2+93-0x32b)];ze7b7ebebbf=(0xa46+5390-0x1f53);message[(0xb43+6595-0x2506)]=(0x12e9+3420-0x2044);message[(0x11c+5156-0x153f)]=(0x1db9+283-0x1ec2);message[(0x3d3+8398-0x249f)]=(0x408+3107-0x102b);message[(0xb87+2088-0x13ac)]=(0x388+4258-0x142a);message[(0x349+788-0x659)]=(0x18a0+3424-0x2600);message[(0xd25+2938-0x189a)]=(0x1365+2508-0x1d31);message[(0x100c+1788-0x1702)]=(0xe1+914-0x473);if(type==(0x36b+7378-0x203d)){
message[(0xad8+6531-0x2454)]=z38357fbbbb;z7be9105675=zb2ab7dbb1a(ident);message[(0x166d+3301-0x234a)]=z7be9105675&(0x1625+2229-0x1ddb);message[(0x56a+5768-0x1be9)]=(z7be9105675>>(0x12f9+4348-0x23ed))&(0x60b+761-0x805);for(z26dbd73a5e=(0x185f+27-0x187a);z26dbd73a5e<z38357fbbbb;z26dbd73a5e++){message[(0x312+6393-0x1c01)+z26dbd73a5e]=zcc6fcdb7f7[z9e4a2d1ebd].Data[z26dbd73a5e];}}else{
message[(0x1f0d+1001-0x22ef)]=(0x2e2+3436-0xfce)|z38357fbbbb;z7be9105675=zdd53c2bd21(ident);message[(0x2075+470-0x2243)]=z7be9105675&(0xaaa+7468-0x26d7);message[(0x158+2698-0xbd9)]=(z7be9105675>>(0x1810+55-0x183f))&(0x1743+249-0x173d);message[(0x249c+529-0x26a3)]=(z7be9105675>>(0xa86+6273-0x22f7))&(0x9dd+6245-0x2143);message[(0x1a4d+1611-0x208d)]=(z7be9105675>>(0xe1b+3589-0x1c08))&(0x10d+3404-0xd5a);for(z26dbd73a5e=(0x110a+4073-0x20f3);z26dbd73a5e<z38357fbbbb;z26dbd73a5e++){message[(0x15f+3395-0xe96)+z26dbd73a5e]=zcc6fcdb7f7[z9e4a2d1ebd].Data[z26dbd73a5e];
}
}memcpy(za6dad42b7e,message,(0x4c7+3464-0x123b));if((int_T)mxGetPr(z9cd34e3860)[(0x1488+2433-0x1e09)]==(0x22a+7882-0x20f3)){
for(z26dbd73a5e=(0xeb2+1403-0x142d);z26dbd73a5e<(0x95+6718-0x1ace);z26dbd73a5e++){z706da0e1e5[(0x161d+4152-0x2641)+z97d855d69f*(0x18c1+2542-0x22aa)+z26dbd73a5e]=za6dad42b7e[z26dbd73a5e];}z97d855d69f++;if(z97d855d69f==(0x4b1+7871-0x233e))z97d855d69f=(0x482+1859-0xbc5);}else{for(z26dbd73a5e=(0x10af+856-0x1407);z26dbd73a5e<(0x26c3+22-0x26d4);z26dbd73a5e++){z706da0e1e5[(0x1006+4487-0x207f)+z2b9653a7df*(0x406+8289-0x2462)+z26dbd73a5e]=za6dad42b7e[z26dbd73a5e];}z2b9653a7df++;if(z2b9653a7df==(0xeef+6043-0x2658))z2b9653a7df=(0x32+5532-0x15ce);}}if((int_T)mxGetPr(z11e8538834)[(0x52a+7675-0x2325)]){y[z9e4a2d1ebd]=(real_T)z563e4da9f6;}if(ze7b7ebebbf){
zc1ac25c1d6=z3e5b8e05d8[(0x38d+5263-0x1807)];z3e5b8e05d8[(0x846+1910-0xfa7)]=zc1ac25c1d6&~((0x506+5269-0x199a)<<(0x17a6+743-0x1a8b));z3e5b8e05d8[(0x1918+2026-0x20ed)]=zc1ac25c1d6|((0x3fd+4696-0x1654)<<(0x1ab0+2752-0x256e));}z199556e987[(0x887+7549-0x2604)+zc369e1e9c6*(0x127+6477-0x1a70)]=z97d855d69f;z199556e987[(0xe40+5886-0x253d)+zc369e1e9c6*(0x125a+1125-0x16bb)]=z2b9653a7df;}}else{
dims=ssGetInputPortDimensions(S,(0x494+7344-0x2144));if(dims[(0xb47+2487-0x14fd)]==(0x6c3+2694-0x1144)){zc430a259a4=(0x1954+2152-0x21bc);m=dims[(0x9da+3274-0x16a4)];}else{zc430a259a4=(0x15b2+2801-0x20a2);m=(0x1268+346-0x13bc);}
u=(real_T*)ssGetInputPortSignal(S,(0x472+8675-0x2655));if((int_T)mxGetPr(z11e8538834)[(0x120+6041-0x18b9)]){y=(real_T*)ssGetOutputPortSignal(S,(0x29d+3065-0xe96));}z97d855d69f=z199556e987[(0xd02+757-0xff7)+zc369e1e9c6*(0xc74+832-0xfb0)];z2b9653a7df=z199556e987[(0x1e30+1086-0x226d)+zc369e1e9c6*(0x9d2+137-0xa57)];ze7b7ebebbf=(0x147b+1281-0x197c);for(i=(0x1769+3923-0x26bc);i<m;i++){
int_T z0add1d1c25=(int_T)u[i+m*(0x6c+2294-0x962)];uint32_T ident=(uint32_T)u[i+m*(0x39a+663-0x630)];int_T type=(int_T)u[i+m*(0x7fa+4916-0x1b2c)];int_T z38357fbbbb=(int_T)u[i+m*(0x575+4011-0x151d)];z563e4da9f6=(0x657+3123-0x128a);za1bbbf817a=(0xeb8+3307-0x1ba2);if(zc430a259a4){if(u[i+m*(0x1f6+3916-0x113d)]<0.5){za1bbbf817a=(0x22a+2760-0xcf2);}}if(z0add1d1c25!=(0x2578+79-0x25c6)&&z0add1d1c25!=(0xcfd+3294-0x19d9)){za1bbbf817a=(0x4f+8196-0x2053);z563e4da9f6=-(0x2bd+3385-0xfec);}if(type!=(0x20c4+1152-0x2544)&&type!=(0xb8c+3256-0x1843)){za1bbbf817a=(0x495+5968-0x1be5);z563e4da9f6=-(0x12bf+570-0x14ee);}switch(type){case(0xb7+8574-0x2235):if(ident<(0x12fb+330-0x1445)||ident>za207ed9b4c){za1bbbf817a=(0x2358+128-0x23d8);z563e4da9f6=-(0xbe4+4504-0x1d70);}break;case(0x719+1050-0xb32):if(ident<(0x938+2939-0x14b3)||ident>z01f8dc1780){za1bbbf817a=(0x1d51+1087-0x2190);z563e4da9f6=-(0x10fc+550-0x1315);}break;}if(z38357fbbbb<(0x1b5+6548-0x1b49)||z38357fbbbb>(0x715+4474-0x1887)){za1bbbf817a=(0x377+5795-0x1a1a);z563e4da9f6=-(0x10ed+5373-0x25dc);}if((int_T)mxGetPr(z11e8538834)[(0x695+1975-0xe4c)]){if(z0add1d1c25==(0x19bc+1172-0x1e4f)){if(z706da0e1e5[(0x145c+3676-0x22a4)+z97d855d69f*(0x1c90+1136-0x20fb)+(0x1270+436-0x1424)]&(0x157d+1535-0x1a7d)){za1bbbf817a=(0xa12+5823-0x20d1);z563e4da9f6=-(0x112+5973-0x1866);}}else{if(z706da0e1e5[(0x8bb+5252-0x1c31)+z2b9653a7df*(0xaf3+5227-0x1f59)+(0xbd0+450-0xd92)]&(0xa2f+7106-0x24f2)){za1bbbf817a=(0x1660+1864-0x1da8);z563e4da9f6=-(0x1fb+9282-0x263c);}}}if(za1bbbf817a){ze7b7ebebbf=(0x117c+3360-0x1e9b);z266f92ba7c=u[i+m*(0x9ab+5852-0x2083)];z42362badca=(uint8_T*)&z266f92ba7c;message[(0x88b+3290-0x1565)]=(0x1455+441-0x160d);message[(0xd02+6300-0x259d)]=(0x1750+1507-0x1d21);message[(0x9b8+674-0xc58)]=(0x1084+5356-0x2570);message[(0xf8a+234-0x1071)]=(0x12b9+3782-0x217f);message[(0x1568+4135-0x258b)]=(0x1fd0+1569-0x25f1);message[(0x83+4390-0x11a4)]=(0xb7c+2025-0x1365);message[(0xc0a+972-0xfd0)]=(0x620+4906-0x194a);if(type==(0x10c7+2852-0x1beb)){
message[(0xb13+5712-0x215c)]=z38357fbbbb;z7be9105675=zb2ab7dbb1a(ident);message[(0x124+1461-0x6d1)]=z7be9105675&(0x1f07+1289-0x2311);message[(0x764+4126-0x1779)]=(z7be9105675>>(0x279+3600-0x1081))&(0x412+4121-0x132c);for(z26dbd73a5e=(0xc7a+5246-0x20f8);z26dbd73a5e<z38357fbbbb;z26dbd73a5e++){message[(0x2241+1203-0x26ea)+z26dbd73a5e]=z42362badca[z26dbd73a5e];}}else{
message[(0x1594+2248-0x1e55)]=(0xd5+3459-0xdd8)|z38357fbbbb;z7be9105675=zdd53c2bd21(ident);message[(0xffa+4150-0x2028)]=z7be9105675&(0x200f+924-0x22ac);message[(0x431+7928-0x2320)]=(z7be9105675>>(0xedb+4831-0x21b2))&(0x13c8+3275-0x1f94);message[(0xf52+5674-0x2572)]=(z7be9105675>>(0xb9b+3212-0x1817))&(0xbc3+3231-0x1763);message[(0x60d+167-0x6a9)]=(z7be9105675>>(0x9dd+1152-0xe45))&(0x1594+4069-0x247a);for(z26dbd73a5e=(0x6c8+2351-0xff7);z26dbd73a5e<z38357fbbbb;z26dbd73a5e++){message[(0x1d35+2339-0x264c)+z26dbd73a5e]=z42362badca[z26dbd73a5e];}}memcpy(za6dad42b7e,message,(0x1176+4679-0x23a9));if(z0add1d1c25==(0x1fc2+1663-0x2640)){for(z26dbd73a5e=(0xc8+7037-0x1c45);z26dbd73a5e<(0x36a+7051-0x1ef0);z26dbd73a5e++){z706da0e1e5[(0x37d+6914-0x1e6b)+z97d855d69f*(0x350+681-0x5f4)+z26dbd73a5e]=za6dad42b7e[z26dbd73a5e];}z97d855d69f++;if(z97d855d69f==(0x4ea+6968-0x1ff0))z97d855d69f=(0x248+3698-0x10ba);}else{for(z26dbd73a5e=(0xb37+2870-0x166d);z26dbd73a5e<(0x835+1050-0xc4a);z26dbd73a5e++){z706da0e1e5[(0x24a9+255-0x249a)+z2b9653a7df*(0x380+4906-0x16a5)+z26dbd73a5e]=za6dad42b7e[z26dbd73a5e];}z2b9653a7df++;if(z2b9653a7df==(0xfe4+4685-0x21ff))z2b9653a7df=(0xfa+6963-0x1c2d);}}if((int_T)mxGetPr(z11e8538834)[(0x4e4+6547-0x1e77)]){y[(0x52f+5270-0x19c5)]=(real_T)z563e4da9f6;}}if(ze7b7ebebbf){
zc1ac25c1d6=z3e5b8e05d8[(0x21df+275-0x22dd)];

}z199556e987[(0x3c7+8728-0x25df)+zc369e1e9c6*(0x403+4832-0x16df)]=z97d855d69f;z199556e987[(0x128b+1085-0x16c7)+zc369e1e9c6*(0x6c+9591-0x25df)]=z2b9653a7df;}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef  MATLAB_MEX_FILE    
#include "simulink.c"      
#else
#include "cg_sfun.h"       
#endif

