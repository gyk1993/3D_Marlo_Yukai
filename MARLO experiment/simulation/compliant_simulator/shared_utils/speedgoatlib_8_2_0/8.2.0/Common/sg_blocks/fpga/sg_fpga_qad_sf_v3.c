/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x19bc+648-0x1c42)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_qad_sf_v3
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
#define zdf24515981 ((0x2ac+3115-0xec4)) 
#define z533b11d03f                 ssGetSFcnParam(S,  (0x1fbf+1651-0x2632))
#define z3832b85a32                 ssGetSFcnParam(S,  (0xe86+4699-0x20e0))
#define z702a26a5e9                      ssGetSFcnParam(S,  (0xbed+2312-0x14f3))
#define za9d8fb6bcf                   ssGetSFcnParam(S,  (0x22c+3358-0xf47))
#define ze60f29c132             ssGetSFcnParam(S,  (0xdf+8242-0x210d))
#define zcc5c4ecc21                  ssGetSFcnParam(S,  (0xd30+6093-0x24f8))
#define z985e5b754b          ssGetSFcnParam(S,  (0x403+5130-0x1807))
#define zfcfa40e23c               ssGetSFcnParam(S,  (0x66d+2898-0x11b8))
#define z10dce3de38                     ssGetSFcnParam(S,  (0x14d0+3033-0x20a1))
#define z2dceaadc0f                 ssGetSFcnParam(S,  (0xff3+2556-0x19e6))
#define z6729b77e5a              ssGetSFcnParam(S, (0xe49+3049-0x1a28))      

#define ze22a17d3a2        ssGetSFcnParam(S, (0x10d7+671-0x136b))
#define z91b94c7a5f ssGetSFcnParam(S, (0x1344+3711-0x21b7))
#define z064c4a8f6b           ssGetSFcnParam(S, (0x18f0+3328-0x25e3))

#define za80bdf5015              ssGetSFcnParam(S, (0x16a6+1189-0x1b3d))
#define z3906fc3439       ssGetSFcnParam(S, (0x113d+2722-0x1bd0))
#define z176946a612         ssGetSFcnParam(S, (0x5fb+6311-0x1e92))
#define z279284fd47        ssGetSFcnParam(S, (0x9ef+1717-0x1093))
#define z68ceca1398           ssGetSFcnParam(S, (0x9ff+7196-0x2609))
#define z2e6483d505              ((0xf79+1843-0x16aa))
#define z7e2eeaa57c          ((0xea+7050-0x1c74))
#define z6a0da049de         ((0x147a+4173-0x24c6))
#define zc5ce4cb81a              ((0x1f6c+1865-0x26b5))
#define z2b17e2ee3b              ((0x62+6354-0x1934))
#define z4a0e34dbb9                 (327680)
static char_T zea4cd01646[(0x17aa+1737-0x1d73)];struct z3d3d501873{uint32_T z4da0d16710;uint32_T z677c7f0c4f;uint32_T z1b3a4657a7;
uint32_T zb27c544ed7;uint32_T z6ed25a6cde;uint32_T ze938c3d87d;uint32_T z74b57607ca;uint32_T zcd9696cb37[(0xb62+3872-0x1a62)];uint32_T z5573a0e7cf[(0x371+4919-0x1688)];uint32_T z024a711a96[(0x8a6+2447-0x1215)];uint32_T z7211d763fb[(0x1187+4521-0x2310)];uint32_T zb0bab4db6b[(0x78f+1273-0xc68)];
uint32_T zb22461074b[(0x14a2+366-0x15f0)];
uint32_T z0ba1e0e76e[(0x66+3203-0xcc9)];int32_T ze49603104c[(0x1c2c+886-0x1f82)];int32_T position[(0x1387+4623-0x2576)];};static void mdlInitializeSizes(SimStruct*S){uint32_T i,za0df33019b;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x548+5151-0x1967));ssSetNumDiscStates(S,(0x17b3+176-0x1863));
za0df33019b=(0x59b+6203-0x1dd6);if((uint32_T)mxGetPr(ze22a17d3a2)[(0x44a+776-0x752)]){za0df33019b++;}if((uint32_T)mxGetPr(z064c4a8f6b)[(0x4d9+295-0x600)]){za0df33019b++;}if((uint32_T)mxGetPr(z91b94c7a5f)[(0x3bd+8398-0x248b)]){za0df33019b++;}ssSetNumInputPorts(S,za0df33019b);


for(i=(0x1922+19-0x1935);i<za0df33019b;i++){ssSetInputPortDataType(S,i,SS_DOUBLE);ssSetInputPortWidth(S,i,(uint32_T)mxGetN(za9d8fb6bcf));ssSetInputPortDirectFeedThrough(S,i,(0xc75+3081-0x187d));ssSetInputPortRequiredContiguous(S,i,(0x6ac+536-0x8c3));}
za0df33019b=(0x967+2234-0x1221);if((uint32_T)mxGetPr(za80bdf5015)[(0x277+6333-0x1b34)]){za0df33019b++;}if((uint32_T)mxGetPr(z3906fc3439)[(0x625+1349-0xb6a)]){za0df33019b++;}if((uint32_T)mxGetPr(z176946a612)[(0x1ac0+3101-0x26dd)]){za0df33019b++;}if((uint32_T)mxGetPr(z279284fd47)[(0x9b+873-0x404)]){za0df33019b++;}if((uint32_T)mxGetPr(z68ceca1398)[(0x9d+9446-0x2583)]){za0df33019b++;}ssSetNumOutputPorts(S,za0df33019b);for(i=(0x582+1701-0xc27);i<za0df33019b;i++){ssSetOutputPortWidth(S,i,mxGetN(za9d8fb6bcf));}ssSetNumSampleTimes(S,(0x797+1453-0xd43));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1a96+87-0x1aed));ssSetNumNonsampledZCs(S,(0xb83+5950-0x22c1));for(i=(0x19f9+736-0x1cd9);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x807+7048-0x238f));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x100f+546-0x1231)]==-1.0){ssSetSampleTime(S,(0x19b+9120-0x253b),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x48a+2887-0xfd1),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x369+8168-0x2351),mxGetPr(z3832b85a32)[(0x1548+1197-0x19f5)]);ssSetOffsetTime(S,(0xc09+2845-0x1726),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint8_T z16ba527520[(0x78c+1180-0xc14)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61;uint32_T z4da0d16710,i,z4e3026977c;volatile struct z3d3d501873*z77f31777e8;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x4d0+2837-0xfe5)];z6f813cde47=z05b56d9d51=5845;switch(z78caf1ba61){case(0x904+5747-0x1e4a):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");za4a2434e08=z182d03571c=17232;break;case(0x224+6209-0x1937):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");za4a2434e08=z182d03571c=17239;break;case(0x1f5f+1875-0x2583):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");za4a2434e08=z182d03571c=16979;break;case(0x45f+5706-0x1979):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");za4a2434e08=z182d03571c=(0xa17+1881-0xc6c);break;case(0x211b+349-0x2141):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");za4a2434e08=z182d03571c=21069;break;case(0x14ec+4059-0x238f):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");za4a2434e08=z182d03571c=16971;break;case(0x332+3970-0x117b):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");za4a2434e08=z182d03571c=17235;break;case(0xea6+1566-0x138a):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");za4a2434e08=z182d03571c=(0x25ba+4499-0x1749);break;case(0xec6+5322-0x224f):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;}if(mxGetN(z702a26a5e9)==(0x51d+8087-0x24b3)){z366b2f03bf=(0xc7+1956-0x86b);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xf58+5568-0x2518)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x1f41+473-0x211a)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x785+7649-0x2565)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x9da+812-0xd04)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0xd29+1280-0x1227)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x239+8655-0x2406)]);z77f31777e8=(volatile struct z3d3d501873*)(zeccbadd9b3.VirtAddress[(0x11ca+3125-0x1dfd)]+z4a0e34dbb9);if(!xpceIsModelInit()){z4da0d16710=(0xe0+6723-0x1b23);for(i=(0x422+8746-0x264c);i<mxGetN(za9d8fb6bcf);i++){
z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xe84+1390-0x13f1);
z77f31777e8->z5573a0e7cf[z4e3026977c]=(uint32_T)mxGetPr(ze60f29c132)[i]-(0x794+5395-0x1ca6);
z77f31777e8->zcd9696cb37[z4e3026977c]=(uint32_T)mxGetPr(zcc5c4ecc21)[i]-(0x234c+245-0x2440);
z77f31777e8->z024a711a96[z4e3026977c]=(uint32_T)mxGetPr(z985e5b754b)[i]-(0x18b0+1691-0x1f4a);
z77f31777e8->zb22461074b[z4e3026977c]=(uint32_T)mxGetPr(zfcfa40e23c)[i];
z77f31777e8->z0ba1e0e76e[z4e3026977c]=(uint32_T)mxGetPr(z10dce3de38)[i];
z77f31777e8->z7211d763fb[z4e3026977c]=(uint32_T)mxGetPr(z2dceaadc0f)[i]-(0x334+7834-0x21cd);
z77f31777e8->z677c7f0c4f=((0x472+6204-0x1cad)<<z4e3026977c);z77f31777e8->z677c7f0c4f=(0x57a+4443-0x16d5);
z77f31777e8->zb0bab4db6b[z4e3026977c]=(uint32_T)mxGetPr(z6729b77e5a)[i];z77f31777e8->z1b3a4657a7=((0x17d2+700-0x1a8d)<<z4e3026977c);z77f31777e8->z1b3a4657a7=(0x10c+2248-0x9d4);
z77f31777e8->zb22461074b[z4e3026977c]=(uint32_T)mxGetPr(zfcfa40e23c)[i];z4da0d16710|=((0xeac+240-0xf9b)<<z4e3026977c);}
z77f31777e8->z4da0d16710=z77f31777e8->z4da0d16710|z4da0d16710;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE   
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile struct z3d3d501873*z77f31777e8=(volatile struct z3d3d501873*)(base+z4a0e34dbb9);uint32_T z4e3026977c,i,zb871a780a7,z677c7f0c4f,z1b3a4657a7,z34a675f13b,z41711266a5;real_T*out,*in;
z41711266a5=(0xd05+41-0xd2e);if((uint32_T)mxGetPr(ze22a17d3a2)[(0x3d7+8002-0x2319)]){for(i=(0x14b6+1197-0x1963);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1fb+7691-0x2005);in=(real_T*)ssGetInputPortSignal(S,z41711266a5);z77f31777e8->zb0bab4db6b[z4e3026977c]=(uint32_T)in[i];}z41711266a5++;}if((uint32_T)mxGetPr(z064c4a8f6b)[(0x1ec9+1016-0x22c1)]){for(i=(0x743+1258-0xc2d);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x136+3945-0x109e);in=(real_T*)ssGetInputPortSignal(S,z41711266a5);z1b3a4657a7|=((uint32_T)in[i])<<z4e3026977c;}z77f31777e8->z1b3a4657a7=z1b3a4657a7;z77f31777e8->z1b3a4657a7=(0x86+8423-0x216d);z41711266a5++;}if((uint32_T)mxGetPr(z91b94c7a5f)[(0x1d3c+1492-0x2310)]){for(i=(0xf89+3190-0x1bff);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xb34+2379-0x147e);in=(real_T*)ssGetInputPortSignal(S,z41711266a5);z77f31777e8->zb22461074b[z4e3026977c]=(uint32_T)in[i];}}
if(mxGetPr(z2dceaadc0f)[(0x1056+2067-0x1869)]==(0x551+7699-0x2360)){zb871a780a7=(0x41b+1274-0x915);for(i=(0x101d+539-0x1238);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x710+7564-0x249b);zb871a780a7|=((0x466+7762-0x22b7)<<z4e3026977c);}z77f31777e8->zb27c544ed7=zb871a780a7;z77f31777e8->zb27c544ed7=(0x12c4+4542-0x2482);}
z34a675f13b=(0xe8c+3625-0x1cb5);if((uint32_T)mxGetPr(za80bdf5015)[(0x1011+4756-0x22a5)]){out=(real_T*)ssGetOutputPortSignal(S,z34a675f13b);for(i=(0xbc3+2303-0x14c2);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1e53+552-0x207a);out[i]=(real_T)z77f31777e8->position[z4e3026977c];}z34a675f13b++;}if((uint32_T)mxGetPr(z3906fc3439)[(0x31+8366-0x20df)]){out=(real_T*)ssGetOutputPortSignal(S,z34a675f13b);for(i=(0x18e5+657-0x1b76);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xb4b+2457-0x14e3);out[i]=(real_T)z77f31777e8->ze49603104c[z4e3026977c];}z34a675f13b++;}if((uint32_T)mxGetPr(z176946a612)[(0x409+6689-0x1e2a)]){out=(real_T*)ssGetOutputPortSignal(S,z34a675f13b);for(i=(0x838+5500-0x1db4);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x12d4+2630-0x1d19);out[i]=((z77f31777e8->z6ed25a6cde)>>z4e3026977c)&(0x9f6+2911-0x1554);}z34a675f13b++;}if((uint32_T)mxGetPr(z279284fd47)[(0x1931+2205-0x21ce)]){out=(real_T*)ssGetOutputPortSignal(S,z34a675f13b);for(i=(0x52d+5763-0x1bb0);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x3bc+6236-0x1c17);out[i]=((z77f31777e8->ze938c3d87d)>>z4e3026977c)&(0x689+6282-0x1f12);}z34a675f13b++;}if((uint32_T)mxGetPr(z68ceca1398)[(0x1b8f+2483-0x2542)]){out=(real_T*)ssGetOutputPortSignal(S,z34a675f13b);for(i=(0xcf4+3526-0x1aba);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x5f6+1613-0xc42);out[i]=((z77f31777e8->z74b57607ca)>>z4e3026977c)&(0xa4a+716-0xd15);}z34a675f13b++;}
z677c7f0c4f=(0x61a+3979-0x15a5);for(i=(0xf08+2674-0x197a);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xc5d+1312-0x117c);z677c7f0c4f|=((0x5b1+7182-0x21be)<<z4e3026977c);}z77f31777e8->z677c7f0c4f=z677c7f0c4f;z77f31777e8->z677c7f0c4f=(0xe60+3596-0x1c6c);
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile struct z3d3d501873*z77f31777e8=(volatile struct z3d3d501873*)(base+z4a0e34dbb9);
z77f31777e8->z4da0d16710=(0xc21+673-0xec2);
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

