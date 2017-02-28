/* Copyright 2006-2013 Speedgoat GmbH. */
#define         DEBUG                  (0x11d0+3295-0x1eaf)
#define         S_FUNCTION_LEVEL       (0x35c+3869-0x1277)
#undef          S_FUNCTION_NAME
#define         S_FUNCTION_NAME        sg_IO601_write_s
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
#define z694756a014 4277
#define zea87e0ba83 36912
#define z29146a1837 (0x1219+8339-0x21f7)
#define zab7e64468b 10615
#define         z01f8dc1780            536870911
#define         za207ed9b4c            (0x8fa+9417-0x25c4)
#define         zdf24515981         ((0x4f8+7425-0x21f5))
#define         zbcb3e4d083             ssGetSFcnParam(S,(0xe71+2029-0x165e))
#define         z11e8538834             ssGetSFcnParam(S,(0x68d+5194-0x1ad6))
#define         z3832b85a32          ssGetSFcnParam(S,(0x1d6c+211-0x1e3d))
#define         z702a26a5e9               ssGetSFcnParam(S,(0x395+6453-0x1cc7))
#define z2e6483d505              ((0x1a4b+1894-0x21af))
#define z57e55a08c5        ((0x26a+7245-0x1eb7))
#define z84eb1db314        ((0xed9+944-0x1288))
#define zc5ce4cb81a              ((0x14d4+3929-0x242d))
#define z2b17e2ee3b              ((0x17c7+1450-0x1d71))
#ifndef  zb84e0c3c3b
#define  zb84e0c3c3b(zc1d61b7d63)  *( (uint8_T *) &zc1d61b7d63)
#endif
#ifndef  z15e663b423
#define  z15e663b423(zc1d61b7d63)  *(((uint8_T *) &zc1d61b7d63) + (0x11ef+4153-0x2227))
#endif
#ifndef  zfca7eb6338
#define  zfca7eb6338(zc1d61b7d63)  *( (uint16_T *) &zc1d61b7d63)
#endif
#ifndef  z3607971cd6
#define  z3607971cd6(zc1d61b7d63)  *(((uint16_T *) &zc1d61b7d63) + (0x11c7+1380-0x172a))
#endif
#ifndef z0056adfa94
#define z0056adfa94(zc1d61b7d63)       { uint8_T z7be9105675; z7be9105675 = z15e663b423(zc1d61b7d63); z15e663b423(zc1d61b7d63) = (uint8_T) zc1d61b7d63; zb84e0c3c3b(zc1d61b7d63) = z7be9105675; }
#endif
#ifndef z8444fc96d2
#define z8444fc96d2(zc1d61b7d63)       { uint16_T z7be9105675; z7be9105675 = z3607971cd6(zc1d61b7d63); z3607971cd6(zc1d61b7d63) = (uint16_T) zc1d61b7d63; zfca7eb6338(zc1d61b7d63) = z7be9105675; }
#endif
static char_T zea4cd01646[(0xbcd+3036-0x16a9)];
#ifndef MATLAB_MEX_FILE
extern uint8_T z199556e987[];static uint32_T zb2ab7dbb1a(uint32_T value){value=value<<(0x219d+818-0x24ba);z0056adfa94(z3607971cd6(value));z0056adfa94(zfca7eb6338(value));z8444fc96d2(value);return(value);}static uint32_T zdd53c2bd21(uint32_T value){value=value<<(0x753+3545-0x1529);z0056adfa94(z3607971cd6(value));z0056adfa94(zfca7eb6338(value));z8444fc96d2(value);return(value);}static unsigned char zf6c13379ed(double value,int n){unsigned char*p;p=(unsigned char*)&value;return p[n];}
#endif
static void mdlInitializeSizes(SimStruct*S){int_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xc7a+6577-0x262b));ssSetNumDiscStates(S,(0x40c+3057-0xffd));ssSetNumInputPorts(S,(0x1acf+813-0x1dfb));if(!ssSetInputPortMatrixDimensions(S,(0x66+487-0x24d),DYNAMICALLY_SIZED,DYNAMICALLY_SIZED))return;ssSetInputPortDirectFeedThrough(S,(0x22a5+581-0x24ea),(0x759+1012-0xb4c));ssSetInputPortRequiredContiguous(S,(0xcf+7053-0x1c5c),(0x501+3543-0x12d7));if((int_T)mxGetPr(z11e8538834)[(0xa58+6297-0x22f1)]){ssSetNumOutputPorts(S,(0x1cb3+1433-0x224b));ssSetOutputPortWidth(S,(0xfdb+1927-0x1762),DYNAMICALLY_SIZED);}else{ssSetNumOutputPorts(S,(0x96f+2567-0x1376));}ssSetNumSampleTimes(S,(0x4e3+5709-0x1b2f));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,(0x7f0+5973-0x1f45));ssSetNumModes(S,(0xe36+4506-0x1fd0));ssSetNumNonsampledZCs(S,(0x9a4+1682-0x1036));for(i=(0x1bc+4801-0x147d);i<zdf24515981;i++){ssSetSFcnParamNotTunable(S,i);}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}
#define z66116822c9
static void mdlSetInputPortDimensionInfo(SimStruct*S,int zb9276e93a2,const DimsInfo_T*zde3f224951){if(zde3f224951->dims[(0x171+6737-0x1bc1)]!=(0x2d1+5447-0x1813)&&zde3f224951->dims[(0xb0+456-0x277)]!=(0xca8+3883-0x1bcd)){sprintf(zea4cd01646,"\x49\x6e\x70\x75\x74\x20\x6d\x75\x73\x74\x20\x62\x65\x20\x61\x20\x6d\x2a\x35\x20\x6f\x72\x20\x61\x20\x6d\x2a\x36\x20\x20\x6d\x61\x74\x72\x69\x78");ssSetErrorStatus(S,zea4cd01646);return;}if(!ssSetInputPortDimensionInfo(S,zb9276e93a2,zde3f224951))return;if((int_T)mxGetPr(z11e8538834)[(0x11d0+2868-0x1d04)]){if(!ssSetOutputPortVectorDimension(S,(0x326+6196-0x1b5a),zde3f224951->dims[(0x1da4+1239-0x227b)]))return;}}
#define z12b5c990f1
static void mdlSetOutputPortDimensionInfo(SimStruct*S,int zb9276e93a2,const DimsInfo_T*zde3f224951){if(!ssSetOutputPortDimensionInfo(S,zb9276e93a2,zde3f224951))return;}
#define z4fd520fcfe
static void mdlSetDefaultPortDimensionInfo(SimStruct*S){if(!ssSetInputPortMatrixDimensions(S,(0x222b+805-0x2550),(0x919+5617-0x1f09),(0x510+7648-0x22eb)))return;if((int_T)mxGetPr(z11e8538834)[(0x1298+4109-0x22a5)]){if(!ssSetOutputPortVectorDimension(S,(0x371+2348-0xc9d),(0x738+6500-0x209b)))return;}}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x1bf6+1105-0x2047),mxGetPr(z3832b85a32)[(0xa9a+2711-0x1531)]);if(mxGetN((z3832b85a32))==(0x1f9c+805-0x22c0)){ssSetOffsetTime(S,(0x19d6+3116-0x2602),0.0);}else{ssSetOffsetTime(S,(0x762+6412-0x206e),mxGetPr(z3832b85a32)[(0x586+7625-0x234e)]);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zef529fae4a,*zdfcb1da404;void*ze2370ae9b9,*zf2db5722bf;volatile uint32_T*z3e5b8e05d8;volatile uint8_T*z27fd94ac66;volatile uint32_T*z706da0e1e5;uint8_T zc369e1e9c6;zc369e1e9c6=(uint8_T)mxGetPr(zbcb3e4d083)[(0x1428+4130-0x244a)]-(0x4ed+573-0x729);if((int_T)mxGetPr(z702a26a5e9)[(0x4f3+1772-0xbdf)]<(0x14b8+2071-0x1ccf)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xfac+5473-0x250c)){z366b2f03bf=(0x17a5+3015-0x236c);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x6f4+1850-0xe2e)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x1556+1919-0x1cd5)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xae1+3702-0x1956)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x1d8+5053-0x1496))|((z366b2f03bf&(0xed7+4358-0x1ede))<<(0x11f6+2065-0x19ff)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zef529fae4a=(void*)zeccbadd9b3.BaseAddress[(0x1aff+3045-0x26e4)];ze2370ae9b9=rl32eGetDevicePtr(zef529fae4a,(0x1e38+2010-0x24ea),RT_PG_USERREADWRITE);z3e5b8e05d8=(volatile uint32_T*)ze2370ae9b9;
zdfcb1da404=(void*)zeccbadd9b3.BaseAddress[(0x7d4+4630-0x19e8)];zf2db5722bf=rl32eGetDevicePtr(zdfcb1da404,16384,RT_PG_USERREADWRITE);z27fd94ac66=(volatile uint8_T*)zf2db5722bf;z706da0e1e5=(volatile uint32_T*)zf2db5722bf;
ssSetIWorkValue(S,z57e55a08c5,(uint32_T)z3e5b8e05d8);ssSetIWorkValue(S,z84eb1db314,(uint32_T)z27fd94ac66);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
int_T z563e4da9f6,i,m,z26dbd73a5e,z97d855d69f,z2b9653a7df;uint8_T*z42362badca;real_T*u,*y,z266f92ba7c;int_T*dims;int_T zc430a259a4,za1bbbf817a,ze7b7ebebbf;uint32_T zc1ac25c1d6,z7be9105675;uint8_T zc369e1e9c6=(uint8_T)mxGetPr(zbcb3e4d083)[(0x166c+1360-0x1bbc)]-(0x1036+3307-0x1d20);uint8_T message[(0x589+1180-0xa11)];uint32_T za6dad42b7e[(0x724+6935-0x2236)];volatile uint32_T*z3e5b8e05d8;volatile uint32_T*z706da0e1e5;uint32_T z5d9c31c2b6=ssGetIWorkValue(S,z57e55a08c5);uint32_T z31a846515d=ssGetIWorkValue(S,z84eb1db314);z3e5b8e05d8=(void*)z5d9c31c2b6;z706da0e1e5=(void*)z31a846515d;dims=ssGetInputPortDimensions(S,(0x4d3+1098-0x91d));if(dims[(0x1461+4382-0x257e)]==(0xead+5701-0x24ed)){zc430a259a4=(0x1872+1248-0x1d52);m=dims[(0x174a+2963-0x22dd)];}else{zc430a259a4=(0x8b6+7074-0x2457);m=(0x126+410-0x2ba);}m=dims[(0x532+8032-0x2492)];u=(real_T*)ssGetInputPortSignal(S,(0x1106+628-0x137a));if((int_T)mxGetPr(z11e8538834)[(0x189f+2626-0x22e1)]){y=(real_T*)ssGetOutputPortSignal(S,(0x1030+579-0x1273));}z97d855d69f=z199556e987[(0x159d+1465-0x1b56)+zc369e1e9c6*(0x59d+1395-0xb0c)];z2b9653a7df=z199556e987[(0x13fb+3528-0x21c2)+zc369e1e9c6*(0x6e5+5433-0x1c1a)];ze7b7ebebbf=(0xc7f+1573-0x12a4);for(i=(0xb49+4869-0x1e4e);i<m;i++){
int_T z0add1d1c25=(int_T)u[i+m*(0x342+235-0x42d)];uint32_T ident=(uint32_T)u[i+m*(0x2185+765-0x2481)];int_T type=(int_T)u[i+m*(0x87a+2473-0x1221)];int_T z38357fbbbb=(int_T)u[i+m*(0x7e0+3773-0x169a)];z563e4da9f6=(0x37+6815-0x1ad6);za1bbbf817a=(0xd89+1813-0x149d);if(zc430a259a4){if(u[i+m*(0xeb1+4346-0x1fa6)]<0.5){za1bbbf817a=(0x8bb+2822-0x13c1);}}if(z0add1d1c25!=(0xd99+4026-0x1d52)&&z0add1d1c25!=(0xf9b+4596-0x218d)){za1bbbf817a=(0x463+6965-0x1f98);z563e4da9f6=-(0x497+843-0x7d8);}if(type!=(0xe1c+6239-0x267b)&&type!=(0xba7+4595-0x1d99)){za1bbbf817a=(0xa4a+4054-0x1a20);z563e4da9f6=-(0xfea+5624-0x25d7);}switch(type){case(0x87f+2769-0x1350):if(ident<(0x3b7+7355-0x2072)||ident>za207ed9b4c){za1bbbf817a=(0x569+4159-0x15a8);z563e4da9f6=-(0x393+9092-0x270b);}break;case(0x1478+1297-0x1988):if(ident<(0x1582+2771-0x2055)||ident>z01f8dc1780){za1bbbf817a=(0xd56+1651-0x13c9);z563e4da9f6=-(0x155+6192-0x1978);}break;}if(z38357fbbbb<(0x1c1d+1087-0x205c)||z38357fbbbb>(0xc35+2084-0x1451)){za1bbbf817a=(0x317+5465-0x1870);z563e4da9f6=-(0x48d+6183-0x1ca6);}if((int_T)mxGetPr(z11e8538834)[(0x185b+722-0x1b2d)]){if(z0add1d1c25==(0x3b6+2257-0xc86)){if(z706da0e1e5[(0x94+4500-0x1214)+z97d855d69f*(0x518+6552-0x1eab)+(0x2b3+1552-0x8c3)]&(0x52a+3119-0x105a)){za1bbbf817a=(0x402+651-0x68d);z563e4da9f6=-(0x2071+1324-0x259c);}}else{if(z706da0e1e5[(0x322+8413-0x22f1)+z2b9653a7df*(0xf0d+3585-0x1d09)+(0x26d+7137-0x1e4e)]&(0x430+4836-0x1615)){za1bbbf817a=(0x22a1+436-0x2455);z563e4da9f6=-(0xe07+6058-0x25b0);}}}if(za1bbbf817a){ze7b7ebebbf=(0xaf0+4722-0x1d61);z266f92ba7c=u[i+m*(0x7d1+2146-0x102f)];z42362badca=(uint8_T*)&z266f92ba7c;message[(0x10ff+3182-0x1d6d)]=(0x395+4108-0x13a0);message[(0x9c3+287-0xae1)]=(0x22ab+747-0x2584);message[(0x5a1+5008-0x192f)]=(0xfe7+2702-0x1a75);message[(0xfa8+565-0x11da)]=(0xe12+406-0xfa8);message[(0x5cf+7642-0x23a5)]=(0x9f3+6019-0x2176);message[(0x1446+2246-0x1d07)]=(0x108a+3883-0x1fb5);message[(0x7b+4561-0x1246)]=(0x8ed+627-0xb60);if(type==(0x25f+1546-0x869)){
message[(0x367+8865-0x2601)]=z38357fbbbb;z7be9105675=zb2ab7dbb1a(ident);message[(0x335+3787-0x11f8)]=z7be9105675&(0x15d6+937-0x1880);message[(0x564+828-0x897)]=(z7be9105675>>(0x86a+4803-0x1b25))&(0x1cb9+1391-0x2129);for(z26dbd73a5e=(0x7a8+5272-0x1c40);z26dbd73a5e<z38357fbbbb;z26dbd73a5e++){message[(0x164d+1366-0x1b99)+z26dbd73a5e]=z42362badca[z26dbd73a5e];}}else{
message[(0x13ab+2559-0x1da3)]=(0x8a3+6495-0x2182)|z38357fbbbb;z7be9105675=zdd53c2bd21(ident);message[(0xe97+2814-0x198d)]=z7be9105675&(0x828+2389-0x107e);message[(0x12a2+4094-0x2297)]=(z7be9105675>>(0x1b62+290-0x1c7c))&(0x12f0+5118-0x25ef);message[(0x9da+6612-0x23a4)]=(z7be9105675>>(0xb27+6151-0x231e))&(0x1055+4364-0x2062);message[(0x105b+2925-0x1bbd)]=(z7be9105675>>(0x13c1+2568-0x1db1))&(0x26b1+304-0x26e2);for(z26dbd73a5e=(0x19fb+231-0x1ae2);z26dbd73a5e<z38357fbbbb;z26dbd73a5e++){message[(0x190f+2053-0x2108)+z26dbd73a5e]=z42362badca[z26dbd73a5e];}}memcpy(za6dad42b7e,message,(0xaf+7242-0x1ce5));if(z0add1d1c25==(0xec7+5133-0x22d3)){for(z26dbd73a5e=(0x5f6+1534-0xbf4);z26dbd73a5e<(0x4fa+157-0x592);z26dbd73a5e++){z706da0e1e5[(0x199+1285-0x68a)+z97d855d69f*(0xc41+946-0xfee)+z26dbd73a5e]=za6dad42b7e[z26dbd73a5e];}z97d855d69f++;if(z97d855d69f==(0x1372+1553-0x1951))z97d855d69f=(0xd92+5140-0x21a6);}else{for(z26dbd73a5e=(0x1200+3940-0x2164);z26dbd73a5e<(0xab+7895-0x1f7d);z26dbd73a5e++){z706da0e1e5[(0x659+8029-0x24a8)+z2b9653a7df*(0x7eb+860-0xb42)+z26dbd73a5e]=za6dad42b7e[z26dbd73a5e];}z2b9653a7df++;if(z2b9653a7df==(0x192+2030-0x94e))z2b9653a7df=(0x1cd5+36-0x1cf9);}}if((int_T)mxGetPr(z11e8538834)[(0x433+848-0x783)]){y[i]=(real_T)z563e4da9f6;}}if(ze7b7ebebbf){
zc1ac25c1d6=z3e5b8e05d8[(0x836+6213-0x2066)];z3e5b8e05d8[(0x4f+3023-0xc09)]=zc1ac25c1d6&~((0x149a+464-0x1669)<<(0x10b6+3100-0x1cd0));z3e5b8e05d8[(0x198+9456-0x2673)]=zc1ac25c1d6|((0x161b+2793-0x2103)<<(0x1126+3679-0x1f83));}z199556e987[(0xb27+3070-0x1725)+zc369e1e9c6*(0xfc5+535-0x11d8)]=z97d855d69f;z199556e987[(0x85c+5637-0x1e60)+zc369e1e9c6*(0x155+7429-0x1e56)]=z2b9653a7df;
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef  MATLAB_MEX_FILE    
#include "simulink.c"      
#else
#include "cg_sfun.h"       
#endif

