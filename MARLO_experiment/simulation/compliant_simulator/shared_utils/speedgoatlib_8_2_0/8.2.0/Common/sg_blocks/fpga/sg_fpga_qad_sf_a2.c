/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x915+7001-0x246c)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_qad_sf_a2
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
#define zdf24515981 ((0x687+770-0x976)) 
#define z533b11d03f                 ssGetSFcnParam(S,  (0x20c0+1568-0x26e0))
#define z3832b85a32                 ssGetSFcnParam(S,  (0x1052+1089-0x1492))
#define z702a26a5e9                      ssGetSFcnParam(S,  (0x1522+989-0x18fd))
#define za9d8fb6bcf                   ssGetSFcnParam(S,  (0x135a+4409-0x2490))
#define ze60f29c132             ssGetSFcnParam(S,  (0x1341+4697-0x2596))
#define zcc5c4ecc21                  ssGetSFcnParam(S,  (0x1a7+2080-0x9c2))
#define z985e5b754b          ssGetSFcnParam(S,  (0x14e2+645-0x1761))
#define zfcfa40e23c               ssGetSFcnParam(S,  (0x16ca+3872-0x25e3))
#define z10dce3de38                     ssGetSFcnParam(S,  (0x6a2+2426-0x1014))
#define z2dceaadc0f                 ssGetSFcnParam(S,  (0x1287+3857-0x218f))
#define z6729b77e5a              ssGetSFcnParam(S, (0x88f+6335-0x2144))      

#define ze22a17d3a2        ssGetSFcnParam(S, (0x13c+5117-0x152e))
#define z91b94c7a5f ssGetSFcnParam(S, (0xf17+4794-0x21c5))
#define z064c4a8f6b           ssGetSFcnParam(S, (0xb77+1325-0x1097))

#define za80bdf5015              ssGetSFcnParam(S, (0x978+286-0xa88))
#define z3906fc3439       ssGetSFcnParam(S, (0x2305+576-0x2536))
#define z176946a612         ssGetSFcnParam(S, (0xac4+1645-0x1121))
#define z279284fd47        ssGetSFcnParam(S, (0x8ec+2881-0x141c))
#define z68ceca1398           ssGetSFcnParam(S, (0x12a0+2248-0x1b56))
#define z2e6483d505              ((0x215+1715-0x8c6))
#define z7e2eeaa57c          ((0x244b+69-0x2490))
#define z6a0da049de         ((0xb72+559-0xda0))
#define zc5ce4cb81a              ((0x1da1+2092-0x25cd))
#define z2b17e2ee3b              ((0xadf+5185-0x1f20))
#define z4a0e34dbb9                 (131072)
static char_T zea4cd01646[(0x65d+7406-0x224b)];struct z3d3d501873{uint32_T z4da0d16710;uint32_T z677c7f0c4f;uint32_T z1b3a4657a7;
uint32_T zb27c544ed7;uint32_T z6ed25a6cde;uint32_T ze938c3d87d;uint32_T z74b57607ca;uint32_T zcd9696cb37[(0x516+1112-0x94e)];uint32_T z5573a0e7cf[(0xcb+7639-0x1e82)];uint32_T z024a711a96[(0xe9a+5376-0x237a)];uint32_T z7211d763fb[(0x113+218-0x1cd)];uint32_T zb0bab4db6b[(0x1683+1292-0x1b6f)];
uint32_T zb22461074b[(0xe8+9060-0x242c)];
uint32_T z0ba1e0e76e[(0x1503+1003-0x18ce)];int32_T ze49603104c[(0x1db+7521-0x1f1c)];int32_T position[(0x13ad+4543-0x254c)];};static void mdlInitializeSizes(SimStruct*S){uint32_T i,za0df33019b;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x781+6195-0x1fb4));ssSetNumDiscStates(S,(0x553+3305-0x123c));
za0df33019b=(0x8e8+2325-0x11fd);if((uint32_T)mxGetPr(ze22a17d3a2)[(0xf39+3063-0x1b30)]){za0df33019b++;}if((uint32_T)mxGetPr(z064c4a8f6b)[(0x2d7+7507-0x202a)]){za0df33019b++;}if((uint32_T)mxGetPr(z91b94c7a5f)[(0x4ff+3197-0x117c)]){za0df33019b++;}ssSetNumInputPorts(S,za0df33019b);


for(i=(0x212+5249-0x1693);i<za0df33019b;i++){ssSetInputPortDataType(S,i,SS_DOUBLE);ssSetInputPortWidth(S,i,(uint32_T)mxGetN(za9d8fb6bcf));ssSetInputPortDirectFeedThrough(S,i,(0x4f7+4887-0x180d));ssSetInputPortRequiredContiguous(S,i,(0x1be3+1779-0x22d5));}
za0df33019b=(0x690+7643-0x246b);if((uint32_T)mxGetPr(za80bdf5015)[(0x3ad+1441-0x94e)]){za0df33019b++;}if((uint32_T)mxGetPr(z3906fc3439)[(0x1111+4536-0x22c9)]){za0df33019b++;}if((uint32_T)mxGetPr(z176946a612)[(0x206+4353-0x1307)]){za0df33019b++;}if((uint32_T)mxGetPr(z279284fd47)[(0x1c3+4213-0x1238)]){za0df33019b++;}if((uint32_T)mxGetPr(z68ceca1398)[(0x210b+537-0x2324)]){za0df33019b++;}ssSetNumOutputPorts(S,za0df33019b);for(i=(0xa75+1096-0xebd);i<za0df33019b;i++){ssSetOutputPortWidth(S,i,mxGetN(za9d8fb6bcf));}ssSetNumSampleTimes(S,(0x19d5+1963-0x217f));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x5d1+8106-0x257b));ssSetNumNonsampledZCs(S,(0x5b8+446-0x776));for(i=(0x12c5+3202-0x1f47);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xf90+2158-0x17fe));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x158+1091-0x59b)]==-1.0){ssSetSampleTime(S,(0x1338+726-0x160e),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x113+5632-0x1713),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x442+115-0x4b5),mxGetPr(z3832b85a32)[(0x369+8980-0x267d)]);ssSetOffsetTime(S,(0x8f1+5430-0x1e27),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint8_T z16ba527520[(0x131c+3222-0x1f9e)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61;uint32_T z4da0d16710,i,z4e3026977c;volatile struct z3d3d501873*z77f31777e8;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x841+6702-0x226f)];z6f813cde47=z05b56d9d51=5845;z6f813cde47=z05b56d9d51=(0x18b1+8248-0x2214);switch(z78caf1ba61){case(0x2301+350-0x231e):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;case(0x281+939-0x4e1):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;break;}if(mxGetN(z702a26a5e9)==(0x625+2903-0x117b)){z366b2f03bf=(0xa76+3098-0x1690);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x495+885-0x80a)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x37+4462-0x11a5)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xb24+5127-0x1f2a)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x3e0+6183-0x1c05)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0xd2a+3854-0x1c36)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x712+2680-0x1188)]);z77f31777e8=(volatile struct z3d3d501873*)(zeccbadd9b3.VirtAddress[(0x10c8+2781-0x1ba3)]+z4a0e34dbb9);if(!xpceIsModelInit()){z4da0d16710=(0x30c+3686-0x1172);for(i=(0x6ef+7616-0x24af);i<mxGetN(za9d8fb6bcf);i++){
z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x92a+2995-0x14dc);
z77f31777e8->z5573a0e7cf[z4e3026977c]=(uint32_T)mxGetPr(ze60f29c132)[i]-(0xe37+4050-0x1e08);
z77f31777e8->zcd9696cb37[z4e3026977c]=(uint32_T)mxGetPr(zcc5c4ecc21)[i]-(0xf4+1077-0x528);
z77f31777e8->z024a711a96[z4e3026977c]=(uint32_T)mxGetPr(z985e5b754b)[i]-(0x5b2+5435-0x1aec);
z77f31777e8->zb22461074b[z4e3026977c]=(uint32_T)mxGetPr(zfcfa40e23c)[i];
z77f31777e8->z0ba1e0e76e[z4e3026977c]=(uint32_T)mxGetPr(z10dce3de38)[i];
z77f31777e8->z7211d763fb[z4e3026977c]=(uint32_T)mxGetPr(z2dceaadc0f)[i]-(0x1b84+2064-0x2393);
z77f31777e8->z677c7f0c4f=((0x125a+4895-0x2578)<<z4e3026977c);z77f31777e8->z677c7f0c4f=(0xf32+3215-0x1bc1);
z77f31777e8->zb0bab4db6b[z4e3026977c]=(uint32_T)mxGetPr(z6729b77e5a)[i];z77f31777e8->z1b3a4657a7=((0x1357+1549-0x1963)<<z4e3026977c);z77f31777e8->z1b3a4657a7=(0x2080+623-0x22ef);
z77f31777e8->zb22461074b[z4e3026977c]=(uint32_T)mxGetPr(zfcfa40e23c)[i];z4da0d16710|=((0x454+736-0x733)<<z4e3026977c);}
z77f31777e8->z4da0d16710=z77f31777e8->z4da0d16710|z4da0d16710;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE   
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile struct z3d3d501873*z77f31777e8=(volatile struct z3d3d501873*)(base+z4a0e34dbb9);uint32_T z4e3026977c,i,zb871a780a7,z677c7f0c4f,z1b3a4657a7,z34a675f13b,z41711266a5;real_T*out,*in;
z41711266a5=(0x709+288-0x829);if((uint32_T)mxGetPr(ze22a17d3a2)[(0x3d8+4787-0x168b)]){for(i=(0x752+6820-0x21f6);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x12ff+2661-0x1d63);in=(real_T*)ssGetInputPortSignal(S,z41711266a5);z77f31777e8->zb0bab4db6b[z4e3026977c]=(uint32_T)in[i];}z41711266a5++;}if((uint32_T)mxGetPr(z064c4a8f6b)[(0x50b+629-0x780)]){for(i=(0x151b+4135-0x2542);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xc7+4724-0x133a);in=(real_T*)ssGetInputPortSignal(S,z41711266a5);z1b3a4657a7|=((uint32_T)in[i])<<z4e3026977c;}z77f31777e8->z1b3a4657a7=z1b3a4657a7;z77f31777e8->z1b3a4657a7=(0x938+6085-0x20fd);z41711266a5++;}if((uint32_T)mxGetPr(z91b94c7a5f)[(0x154a+2410-0x1eb4)]){for(i=(0xe4b+1978-0x1605);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xa49+70-0xa8e);in=(real_T*)ssGetInputPortSignal(S,z41711266a5);z77f31777e8->zb22461074b[z4e3026977c]=(uint32_T)in[i];}}
if(mxGetPr(z2dceaadc0f)[(0x185f+1284-0x1d63)]==(0xa36+258-0xb34)){zb871a780a7=(0x1883+1919-0x2002);for(i=(0x1c6c+498-0x1e5e);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1fa2+589-0x21ee);zb871a780a7|=((0x1e18+1973-0x25cc)<<z4e3026977c);}z77f31777e8->zb27c544ed7=zb871a780a7;z77f31777e8->zb27c544ed7=(0x1e84+559-0x20b3);}
z34a675f13b=(0xb38+5806-0x21e6);if((uint32_T)mxGetPr(za80bdf5015)[(0x1528+1324-0x1a54)]){out=(real_T*)ssGetOutputPortSignal(S,z34a675f13b);for(i=(0x123c+3027-0x1e0f);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x57d+10-0x586);out[i]=(real_T)z77f31777e8->position[z4e3026977c];}z34a675f13b++;}if((uint32_T)mxGetPr(z3906fc3439)[(0xa35+1749-0x110a)]){out=(real_T*)ssGetOutputPortSignal(S,z34a675f13b);for(i=(0xea1+2164-0x1715);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1195+3587-0x1f97);out[i]=(real_T)z77f31777e8->ze49603104c[z4e3026977c];}z34a675f13b++;}if((uint32_T)mxGetPr(z176946a612)[(0x11bc+2683-0x1c37)]){out=(real_T*)ssGetOutputPortSignal(S,z34a675f13b);for(i=(0xf05+1881-0x165e);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xa0a+3817-0x18f2);out[i]=((z77f31777e8->z6ed25a6cde)>>z4e3026977c)&(0x11a7+4059-0x2181);}z34a675f13b++;}if((uint32_T)mxGetPr(z279284fd47)[(0x7f1+2667-0x125c)]){out=(real_T*)ssGetOutputPortSignal(S,z34a675f13b);for(i=(0x3ab+5195-0x17f6);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x474+2841-0xf8c);out[i]=((z77f31777e8->ze938c3d87d)>>z4e3026977c)&(0x36c+8996-0x268f);}z34a675f13b++;}if((uint32_T)mxGetPr(z68ceca1398)[(0x1e59+10-0x1e63)]){out=(real_T*)ssGetOutputPortSignal(S,z34a675f13b);for(i=(0xf4c+5441-0x248d);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x82d+3182-0x149a);out[i]=((z77f31777e8->z74b57607ca)>>z4e3026977c)&(0x1443+798-0x1760);}z34a675f13b++;}
z677c7f0c4f=(0xa67+5522-0x1ff9);for(i=(0xde0+4392-0x1f08);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x11ed+1649-0x185d);z677c7f0c4f|=((0x9cc+4510-0x1b69)<<z4e3026977c);}z77f31777e8->z677c7f0c4f=z677c7f0c4f;z77f31777e8->z677c7f0c4f=(0x9c8+5741-0x2035);
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile struct z3d3d501873*z77f31777e8=(volatile struct z3d3d501873*)(base+z4a0e34dbb9);
z77f31777e8->z4da0d16710=(0xd62+3429-0x1ac7);
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

