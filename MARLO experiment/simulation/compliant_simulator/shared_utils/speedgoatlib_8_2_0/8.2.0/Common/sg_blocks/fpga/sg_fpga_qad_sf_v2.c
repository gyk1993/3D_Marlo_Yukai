/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x743+5178-0x1b7b)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_qad_sf_v2
#include 	<stddef.h>
#include 	<stdlib.h>
#include 	"simstruc.h" 
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
#define zdf24515981          ((0x1bab+790-0x1eb7))
#define z702a26a5e9                ssGetSFcnParam(S,(0xd00+3482-0x1a9a))
#define zcb009ec8df                ssGetSFcnParam(S,(0x4a7+6922-0x1fb0))
#define z3832b85a32           ssGetSFcnParam(S,(0xd06+3453-0x1a81))
#define z6a07768ac8      ssGetSFcnParam(S,(0x1a1a+3109-0x263c))
#define z3b23451ce3    ssGetSFcnParam(S,(0x14d2+25-0x14e7))
#define z985e5b754b    ssGetSFcnParam(S,(0x271+3459-0xfef))
#define ze7b042c9dd  ssGetSFcnParam(S,(0x13b5+694-0x1665))
#define z1120e7330e            ssGetSFcnParam(S,(0x2db+4428-0x1420))
#define zcdfafad9ca            ssGetSFcnParam(S,(0x9e0+4090-0x19d2))
#define z533b11d03f           ssGetSFcnParam(S,(0x16e7+2857-0x2207))
#define z2e6483d505              ((0xb04+5166-0x1f30))
#define z7e2eeaa57c          ((0x13d5+1724-0x1a91))
#define z6a0da049de         ((0x1d73+1855-0x24b1))
#define zc5ce4cb81a              ((0x2ec+7049-0x1e65))
#define z2b17e2ee3b              ((0xa34+1946-0x11ce))
static char_T zea4cd01646[(0x757+8118-0x260d)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x1629+2709-0x20be));ssSetNumDiscStates(S,(0x9f6+2936-0x156e));ssSetNumOutputPorts(S,(0x5f1+5739-0x1c5c));ssSetNumInputPorts(S,(0x14b2+3099-0x20cb));


ssSetInputPortDataType(S,(0xa0a+2550-0x1400),SS_UINT8);ssSetInputPortWidth(S,(0x58+4380-0x1174),(uint32_T)mxGetN(zcb009ec8df));ssSetInputPortDataType(S,(0xcb7+2393-0x160f),SS_INT32);ssSetInputPortWidth(S,(0x254+1296-0x763),(uint32_T)mxGetN(zcb009ec8df));ssSetInputPortDirectFeedThrough(S,(0xfd4+308-0x1108),(0x1a54+1491-0x2026));ssSetInputPortRequiredContiguous(S,(0x6ac+1514-0xc96),(0x18e8+1104-0x1d37));ssSetInputPortDirectFeedThrough(S,(0x1c87+95-0x1ce5),(0x402+4535-0x15b8));ssSetInputPortRequiredContiguous(S,(0x847+4330-0x1930),(0x831+5688-0x1e68));ssSetNumSampleTimes(S,(0x239d+2-0x239e));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x11ba+217-0x1293));ssSetNumNonsampledZCs(S,(0x596+2737-0x1047));for(i=(0x32c+7632-0x20fc);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x820+3025-0x13f1));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0xe55+806-0x117b)]==-1.0){ssSetSampleTime(S,(0x6da+1166-0xb68),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x2184+660-0x2418),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x1b25+1921-0x22a6),mxGetPr(z3832b85a32)[(0x1e96+1388-0x2402)]);ssSetOffsetTime(S,(0x10b0+1653-0x1725),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z7be9105675,z4e3026977c;uint8_T z16ba527520[(0xc02+2051-0x13f1)];uint16_T z6f813cde47,za4a2434e08;uint32_T zd4796eea24;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x1341+4263-0x23e8)];switch(z78caf1ba61){case(0xb1b+1227-0xeb9):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");z6f813cde47=(0x1dea+5492-0x1c89);za4a2434e08=17232;break;case(0x2251+1363-0x2676):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");z6f813cde47=(0x1e1a+3824-0x1635);za4a2434e08=17239;break;case(0x32f+1728-0x8c0):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");z6f813cde47=(0x2425+2171-0x15cb);za4a2434e08=16979;break;case(0x15a3+481-0x1654):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");z6f813cde47=5845;za4a2434e08=(0xd68+2191-0x10f3);break;case(0xbd8+5590-0x2077):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");z6f813cde47=5845;za4a2434e08=21069;break;case(0x17ac+2624-0x20b4):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");z6f813cde47=(0x193d+1166-0x6f6);za4a2434e08=16971;break;case(0x5e2+4378-0x15c3):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");z6f813cde47=(0x21bf+3041-0x16cb);za4a2434e08=17235;break;case(0xfd3+19-0xeac):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");z6f813cde47=(0x2226+6639-0x2540);za4a2434e08=(0x20ef+7767-0x1f42);break;case(0x157+7256-0x1c6e):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");z6f813cde47=(0x1de9+8079-0x26a3);za4a2434e08=19520;break;}
if((int_T)mxGetPr(z702a26a5e9)[(0x107+7688-0x1f0f)]<(0x2129+1260-0x2615)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x49\x6e\x63\x72\x45\x6e\x63\x6f\x64\x65\x72\x20\x53\x65\x74\x75\x70\x20\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x50a+2605-0xf36)){z366b2f03bf=(0x23dd+687-0x268c);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1453+3505-0x2204)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0xbfd+1632-0x125d)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xa68+4611-0x1c6a)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x16e4+3556-0x23c9))|((z366b2f03bf&(0x10e8+3168-0x1c49))<<(0x72d+1571-0xd48)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x1195+196-0x1257)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);

if(mxGetPr(z6a07768ac8)[(0x603+2011-0xdde)]==(0x1214+3807-0x20f2)){z7be9105675=(0x7dc+5168-0x1c0c);}else if(mxGetPr(z6a07768ac8)[(0x535+1458-0xae7)]==(0xbca+717-0xe95)){z7be9105675=(0x227b+829-0x25b7);}else{z7be9105675=(0x563+5140-0x1975);}
if(mxGetPr(z3b23451ce3)[(0x16ac+2973-0x2249)]==(0x19e4+1473-0x1fa4)){
z7be9105675=z7be9105675|((0xd8+8130-0x209a)<<(0xcd9+3871-0x1bf6));}else if(mxGetPr(z3b23451ce3)[(0x1121+2049-0x1922)]==(0xd1a+2290-0x160a)){
z7be9105675=z7be9105675|((0xee2+4111-0x1ef0)<<(0x99b+6652-0x2395));}else{
z7be9105675=z7be9105675|((0x6d6+8139-0x269f)<<(0x30a+5999-0x1a77));}
if(mxGetPr(z985e5b754b)[(0xfc1+3723-0x1e4c)]==(0x515+6608-0x1ee4)){
z7be9105675=z7be9105675|((0x10c7+2928-0x1c37)<<(0x154a+276-0x165a));}else if(mxGetPr(z985e5b754b)[(0xd8f+1689-0x1428)]==(0xd2c+2353-0x165b)){
z7be9105675=z7be9105675|((0xe79+5040-0x2228)<<(0x9bd+6931-0x24cc));}else if(mxGetPr(z985e5b754b)[(0x3b2+6921-0x1ebb)]==(0x8d3+7441-0x25e1)){
z7be9105675=z7be9105675|((0x925+1798-0x1029)<<(0x2c6+6023-0x1a49));}else if(mxGetPr(z985e5b754b)[(0x654+988-0xa30)]==(0xfbd+3524-0x1d7d)){
z7be9105675=z7be9105675|((0x8b3+3689-0x1719)<<(0xd28+6064-0x24d4));}else if(mxGetPr(z985e5b754b)[(0x101+7773-0x1f5e)]==(0xbaa+4378-0x1cbf)){
z7be9105675=z7be9105675|((0x13e0+4211-0x244f)<<(0x8b1+5277-0x1d4a));}
for(i=(0xcac+3090-0x18be);i<(uint32_T)mxGetN(zcb009ec8df);i++){z4e3026977c=(uint32_T)mxGetPr(zcb009ec8df)[i]-(0xf48+4466-0x20b9);za42cf7dd4a[9728+z4e3026977c]=z7be9105675;}for(i=(0x88+3161-0xce1);i<(uint32_T)mxGetN(zcb009ec8df);i++){z4e3026977c=(uint32_T)mxGetPr(zcb009ec8df)[i]-(0x116+2496-0xad5);zd4796eea24=(uint32_T)mxGetPr(ze7b042c9dd)[i];za42cf7dd4a[9760+z4e3026977c]=zd4796eea24-(0xffa+4289-0x20ba);}za42cf7dd4a[9893]=(0x395+6838-0x1e4b);
za42cf7dd4a[9891]=4294967295;
za42cf7dd4a[9892]=4294967295;za42cf7dd4a[9892]=(0x736+345-0x88f);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;uint32_T*za4749e65b3,z4e3026977c;uint8_T*z0729343411;uint32_T i;za42cf7dd4a=(void*)base;
za4749e65b3=(int32_T*)ssGetInputPortSignal(S,(0x1539+1625-0x1b91));for(i=(0x628+2775-0x10ff);i<(uint32_T)mxGetN(zcb009ec8df);i++){z4e3026977c=(uint32_T)mxGetPr(zcb009ec8df)[i]-(0x1219+1615-0x1867);za42cf7dd4a[9792+z4e3026977c]=za4749e65b3[i];}
z0729343411=(uint8_T*)ssGetInputPortSignal(S,(0x1076+4691-0x22c9));for(i=(0x1c58+1171-0x20eb);i<(uint32_T)mxGetN(zcb009ec8df);i++){z4e3026977c=(uint32_T)mxGetPr(zcb009ec8df)[i]-(0x1cf1+389-0x1e75);za42cf7dd4a[9856+z4e3026977c]=z0729343411[i];}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T z4e3026977c,i;uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;za42cf7dd4a=(void*)base;
za42cf7dd4a[9891]=(0x1ab+2835-0xcbe);
if((uint32_T)mxGetPr(zcdfafad9ca)[(0x1ddf+1857-0x2520)]){for(i=(0x165+9028-0x24a9);i<(uint32_T)mxGetN(zcb009ec8df);i++){z4e3026977c=(uint32_T)mxGetPr(zcb009ec8df)[i]-(0x1ddf+2047-0x25dd);za42cf7dd4a[9856+z4e3026977c]=(0x1f77+1491-0x2549);za42cf7dd4a[9856+z4e3026977c]=(0x217+8639-0x23d6);}}
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

