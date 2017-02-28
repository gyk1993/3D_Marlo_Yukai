/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1c61+1591-0x2296)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_ssis_sf
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
#define zdf24515981        ((0x17e4+1738-0x1e9f))
#define z533b11d03f         ssGetSFcnParam(S,  (0x601+6171-0x1e1c)) 
#define za9d8fb6bcf           ssGetSFcnParam(S,  (0x197+4256-0x1236)) 
#define z31fb671cb8              ssGetSFcnParam(S,  (0x756+2332-0x1070))
#define z86af52d74e              ssGetSFcnParam(S,  (0x1af5+1632-0x2152))
#define zf5ee62a4ad      ssGetSFcnParam(S,  (0x1b0f+2131-0x235e))
#define z3a4907dee5          ssGetSFcnParam(S,  (0x871+6109-0x2049))
#define zb0ce0940e9         ssGetSFcnParam(S,  (0xd42+2521-0x1715))
#define zb00b469153        ssGetSFcnParam(S,  (0x1251+12-0x1256))
#define zd259a80613    ssGetSFcnParam(S,  (0x56a+1223-0xa29))
#define zbdd1493fee         ssGetSFcnParam(S, (0xf36+1650-0x159f))
#define z3832b85a32         ssGetSFcnParam(S, (0x418+3238-0x10b4))
#define z702a26a5e9              ssGetSFcnParam(S, (0x600+5468-0x1b51))
#define z596b77cbe5            ssGetSFcnParam(S, (0xd46+1566-0x1358))
#define z6ee4a37819            	  ssGetSFcnParam(S, (0x1195+3101-0x1da5))
#define z6699565c9c        ssGetSFcnParam(S, (0x179f+168-0x1839))
#define z2e6483d505            ((0x10+7442-0x1d21))
#define zc5ce4cb81a            ((0x9d0+1061-0xdf5))
#define z2b17e2ee3b            ((0x63b+7688-0x2443))
#define z6a0da049de       ((0x158f+4336-0x267f))

#define za0acc6f3f8              (720896)
static char_T zea4cd01646[(0x2392+910-0x2620)];typedef struct{uint32_T z15923ef3d9[(0x102d+4352-0x210d)];uint32_T za746b13f73[(0x19b1+342-0x1ae7)];uint32_T z02bb7b1721[(0x22da+703-0x2579)];uint32_T z1ad71181ab[(0x1170+2728-0x1bf8)];uint32_T z2681ed6ece[(0x1e83+1904-0x25d3)];uint32_T z28e9d9261f[(0x1a3+1396-0x6f7)];uint32_T z2ae1a9d412[(0x521+6548-0x1e95)];uint32_T z07f373fbd4[(0x1389+2475-0x1d14)];uint32_T zac3cadef55[(0x1b9+5408-0x16b9)];uint32_T za3910307c9[(0x1d92+496-0x1f62)];uint32_T zd176e82c10[(0xc59+4022-0x1bef)];uint32_T z4ae288e0c9[(0x16cc+2574-0x20ba)];uint32_T z12402c138a[(0x2f1+3089-0xee2)];uint32_T z8575031947[(0x1cdf+2010-0x2499)];uint32_T za98b68092e[(0x1e1+1773-0x8ae)];uint32_T z75afeb530f[(0x14ba+2563-0x1e9d)];uint32_T zbea4a89f24;uint32_T zdc0d676974;uint32_T z19690b6adb;uint32_T z73b6066883;}z6b3137e20b;void z8f08a20b06(uint32_T*zb9e8f50428,uint32_T*z68d7c00737,uint32_T z15923ef3d9,uint32_T za746b13f73){uint32_T zb534899b45,mask,z7be9105675,z04f44c4a64,z4fb4bb4280;int32_T z2894423462,offset,i,z26dbd73a5e;zb534899b45=(0xf22+5276-0x23b7);z2894423462=(0x7f0+1850-0xf0a);offset=(0xc23+990-0x1001);for(i=za746b13f73-(0xb2+184-0x169);i>=(0xfa8+3704-0x1e20);i--){if(z2894423462>(0xf02+3068-0x1afe))
{offset=z2894423462-z15923ef3d9;zb9e8f50428[zb534899b45]|=(z68d7c00737[i]<<offset);z2894423462-=z15923ef3d9;}else{

mask=(0x2069+518-0x226f);z04f44c4a64=z2894423462;for(z26dbd73a5e=(0xb32+803-0xe55);z26dbd73a5e<z04f44c4a64;z26dbd73a5e++){mask|=((0xfb8+1242-0x1491)<<z26dbd73a5e);}z7be9105675=(z68d7c00737[i]>>(z15923ef3d9-z04f44c4a64))&mask;zb9e8f50428[zb534899b45]|=z7be9105675;
z4fb4bb4280=z15923ef3d9-z04f44c4a64;zb534899b45--;mask=(0x4e5+8291-0x2548);for(z26dbd73a5e=(0x168+1422-0x6f6);z26dbd73a5e<z4fb4bb4280;z26dbd73a5e++){mask|=((0x104+7504-0x1e53)<<z26dbd73a5e);}z7be9105675=z68d7c00737[i]&mask;offset=(0x536+8326-0x259c)-z4fb4bb4280;zb9e8f50428[zb534899b45]|=(z7be9105675<<offset);
z2894423462=(0x1052+1364-0x1586)-z4fb4bb4280;}}}





































































static void mdlInitializeSizes(SimStruct*S){uint32_T i,zbc7ebd0e53;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x598+2907-0x10f3));ssSetNumDiscStates(S,(0x100c+2336-0x192c));zbc7ebd0e53=(uint32_T)mxGetN(za9d8fb6bcf);ssSetNumInputPorts(S,zbc7ebd0e53);for(i=(0x1d48+153-0x1de1);i<zbc7ebd0e53;i++){ssSetInputPortDataType(S,i,SS_UINT32);ssSetInputPortWidth(S,i,(uint32_T)mxGetPr(zb0ce0940e9)[i]);ssSetInputPortDirectFeedThrough(S,i,(0x1dfc+2271-0x26da));ssSetInputPortRequiredContiguous(S,i,(0x13f7+4560-0x25c6));}ssSetNumSampleTimes(S,(0xdc8+3729-0x1c58));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xac+7112-0x1c74));ssSetNumNonsampledZCs(S,(0x191+2616-0xbc9));for(i=(0x411+7250-0x2063);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x6ef+6469-0x2034));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x41b+5212-0x1877)]==-1.0){ssSetSampleTime(S,(0x945+4080-0x1935),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x22a5+106-0x230f),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x1632+1034-0x1a3c),mxGetPr(z3832b85a32)[(0x3dd+3305-0x10c6)]);ssSetOffsetTime(S,(0x1064+3354-0x1d7e),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i,z4e3026977c,zbea4a89f24,zdc0d676974;volatile z6b3137e20b*z1b230a715b;uint8_T z16ba527520[(0x1692+3198-0x22fc)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0xbbd+612-0xe21)];z6f813cde47=z05b56d9d51=(0x2662+1081-0x13c6);switch(z78caf1ba61){case(0xdac+2079-0x1480):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;break;case(0x1458+5055-0x26ea):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");za4a2434e08=z182d03571c=17232;break;case(0x10bf+411-0x1123):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");za4a2434e08=z182d03571c=21069;break;case(0x25ea+556-0x26de):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");za4a2434e08=z182d03571c=16971;break;default:sprintf(zea4cd01646,"\x62\x6f\x61\x72\x64\x20\x74\x79\x70\x65\x20\x69\x6e\x63\x6f\x72\x72\x65\x63\x74\x2e");ssSetErrorStatus(S,zea4cd01646);return;}if(mxGetN(z702a26a5e9)==(0x750+172-0x7fb)){z366b2f03bf=(0xb9b+3617-0x19bc);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x633+1550-0xc41)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x75a+5949-0x1e97)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x2547+27-0x2561)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x4c3+6636-0x1ead)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x8ef+174-0x99b)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0xac3+2789-0x15a6)]);z1b230a715b=(z6b3137e20b*)(zeccbadd9b3.VirtAddress[(0x815+3294-0x14f1)]+za0acc6f3f8);if(!xpceIsModelInit()){
zbea4a89f24=z1b230a715b->zbea4a89f24;zdc0d676974=z1b230a715b->zdc0d676974;for(i=(0x11bc+1976-0x1974);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1a47+241-0x1b37);if((uint32_T)mxGetPr(z31fb671cb8)[i]){zbea4a89f24|=((0xb77+5432-0x20ae)<<z4e3026977c);}else{zbea4a89f24&=~((0x5a9+7594-0x2352)<<z4e3026977c);}if((uint32_T)mxGetPr(z86af52d74e)[i]){zdc0d676974|=((0x174d+559-0x197b)<<z4e3026977c);}else{zdc0d676974&=~((0xfbb+504-0x11b2)<<z4e3026977c);}z1b230a715b->z15923ef3d9[z4e3026977c]=(uint32_T)mxGetPr(z3a4907dee5)[i];z1b230a715b->za746b13f73[z4e3026977c]=(uint32_T)mxGetPr(zb0ce0940e9)[i];z1b230a715b->z02bb7b1721[z4e3026977c]=(uint32_T)mxGetPr(zb00b469153)[i];z1b230a715b->z1ad71181ab[z4e3026977c]=(uint32_T)mxGetPr(zd259a80613)[i];z1b230a715b->z2681ed6ece[z4e3026977c]=(uint32_T)mxGetPr(zbdd1493fee)[i];z1b230a715b->z28e9d9261f[z4e3026977c]=(uint32_T)mxGetPr(zf5ee62a4ad)[i];z1b230a715b->za98b68092e[z4e3026977c]=(uint32_T)mxGetPr(z6ee4a37819)[i];z1b230a715b->z75afeb530f[z4e3026977c]=(uint32_T)mxGetPr(z6699565c9c)[i];}z1b230a715b->zbea4a89f24=zbea4a89f24;z1b230a715b->zdc0d676974=zdc0d676974;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base,i,z26dbd73a5e,z4e3026977c;volatile z6b3137e20b*z1b230a715b;uint32_T*in;
uint32_T z463aec3630,zb9e8f50428[(0x983+2668-0x13e7)],*z68d7c00737;base=ssGetIWorkValue(S,z6a0da049de);z1b230a715b=(z6b3137e20b*)(base+za0acc6f3f8);
for(i=(0x5ef+7741-0x242c);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){zb9e8f50428[(0x695+58-0x6cf)]=(0xb35+5114-0x1f2f);zb9e8f50428[(0x1e33+845-0x217f)]=(0x1113+3983-0x20a2);zb9e8f50428[(0x3f4+4249-0x148b)]=(0xad7+936-0xe7f);zb9e8f50428[(0xa4d+6484-0x239e)]=(0x1251+4858-0x254b);zb9e8f50428[(0xa4a+4140-0x1a72)]=(0x14da+4525-0x2687);zb9e8f50428[(0x1d7a+2060-0x2581)]=(0x17cc+2685-0x2249);zb9e8f50428[(0x75a+7683-0x2557)]=(0x6d4+1682-0xd66);zb9e8f50428[(0x1a76+472-0x1c47)]=(0x994+5235-0x1e07);z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x23b+132-0x2be);z68d7c00737=malloc((uint32_T)mxGetPr(zb0ce0940e9)[i]*sizeof(uint32_T));in=(uint32_T*)ssGetInputPortSignal(S,i);for(z26dbd73a5e=(0x10df+424-0x1287);z26dbd73a5e<(uint32_T)mxGetPr(zb0ce0940e9)[i];z26dbd73a5e++){if((uint32_T)mxGetPr(z596b77cbe5)[(0x2043+683-0x22ee)]==(0x150a+1058-0x192b))
{z68d7c00737[z26dbd73a5e]=in[z26dbd73a5e];
}else
{z463aec3630=in[z26dbd73a5e]^(in[z26dbd73a5e]>>(0x4cf+2917-0x1033));z68d7c00737[z26dbd73a5e]=z463aec3630;}}
z8f08a20b06(zb9e8f50428,z68d7c00737,(uint32_T)mxGetPr(z3a4907dee5)[i],(uint32_T)mxGetPr(zb0ce0940e9)[i]);z1b230a715b->z2ae1a9d412[z4e3026977c]=zb9e8f50428[(0x171d+3579-0x2518)]<<(0x4e7+3248-0x1196);z1b230a715b->z07f373fbd4[z4e3026977c]=zb9e8f50428[(0xe6f+5586-0x2440)]<<(0x1471+587-0x16bb);z1b230a715b->zac3cadef55[z4e3026977c]=zb9e8f50428[(0x184f+1926-0x1fd3)]<<(0x162f+3186-0x22a0);z1b230a715b->za3910307c9[z4e3026977c]=zb9e8f50428[(0x745+6697-0x216b)]<<(0x1918+2534-0x22fd);z1b230a715b->zd176e82c10[z4e3026977c]=zb9e8f50428[(0x613+6351-0x1ede)]<<(0xeaf+5107-0x22a1);z1b230a715b->z4ae288e0c9[z4e3026977c]=zb9e8f50428[(0x22e3+869-0x2643)]<<(0xed0+4948-0x2223);z1b230a715b->z12402c138a[z4e3026977c]=zb9e8f50428[(0x738+1203-0xbe5)]<<(0xd75+1560-0x138c);z1b230a715b->z8575031947[z4e3026977c]=zb9e8f50428[(0xaa0+2722-0x153b)]<<(0x1614+1408-0x1b93);

free(z68d7c00737);}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE     
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif
