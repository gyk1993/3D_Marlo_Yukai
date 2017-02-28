/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x197+3574-0xf8b)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_spim_sf_a1
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
#include        "xpcPCFunctions.h"
#include        "time_xpcimport.h"
#include        "ioext_xpcimport.h"
#include        "util_xpcimport.h"
#endif
#define zdf24515981              ((0x72d+4597-0x1912))
#define z533b11d03f               ssGetSFcnParam(S,  (0x92a+2024-0x1112))
#define za9d8fb6bcf                 ssGetSFcnParam(S,  (0x441+5709-0x1a8d))
#define zf6f668e67a         ssGetSFcnParam(S,  (0x1122+1198-0x15ce))
#define zbb0d1897b2     ssGetSFcnParam(S,  (0x32c+762-0x623))
#define z8f7a5b7479           ssGetSFcnParam(S,  (0x1863+1279-0x1d5e))
#define zdc5f8981b7              ssGetSFcnParam(S,  (0x1127+2613-0x1b57))
#define zc09b06e5fc             ssGetSFcnParam(S,  (0xeac+4783-0x2155))
#define z7039def18e              ssGetSFcnParam(S,  (0x1f6b+1766-0x264a))
#define z86af52d74e                    ssGetSFcnParam(S,  (0x10c3+382-0x1239))
#define z31fb671cb8                    ssGetSFcnParam(S,  (0x5ad+1893-0xd09))
#define zea4d7ef473                ssGetSFcnParam(S, (0x114f+3849-0x204e))
#define z3d4ad966bd                   ssGetSFcnParam(S, (0x1d6a+2230-0x2615))
#define z62fc1d1d8e              ssGetSFcnParam(S, (0xa72+5049-0x1e1f))
#define z08a9674173        ssGetSFcnParam(S, (0xc6+8445-0x21b6))
#define z3832b85a32               ssGetSFcnParam(S, (0x3a+9493-0x2541))
#define z702a26a5e9                    ssGetSFcnParam(S, (0xb6f+420-0xd04))
#define z2e6483d505              ((0xbe8+5336-0x20be))
#define z7e2eeaa57c          ((0x229a+87-0x22f1))
#define z6a0da049de         ((0x8ca+7191-0x24e0))
#define zc5ce4cb81a              ((0x135f+3653-0x2194))
#define z2b17e2ee3b              ((0x6b6+3910-0x15fc))
#define z992cb6e285             163840
static char_T zea4cd01646[(0x5f8+520-0x700)];typedef struct{volatile uint32_T z4da0d16710;volatile uint32_T z13e3aff50f;volatile uint32_T MSBFirst;volatile uint32_T z79c39f7a01;volatile uint32_T z03312e422a;volatile uint32_T z21ab44ce3e;volatile uint32_T z05095ec8c5;volatile uint32_T status;volatile uint32_T z633e4d0b43[(0xd2c+1823-0x142b)];volatile uint32_T z1907ddba6c[(0x1c52+685-0x1edf)];volatile uint32_T z185b3cf79e[(0xc15+2116-0x1439)];volatile uint32_T z17cbe2a22e[(0x2f3+8283-0x232e)];volatile uint32_T z45128425fd[(0x1e80+1944-0x25f8)];volatile uint32_T zef72e5f2d0[(0x1cd3+2076-0x24cf)];volatile uint32_T z8a775a0c78[(0x1b21+2887-0x2648)];volatile uint32_T zfac62c691a[(0x69f+38-0x6a5)];volatile uint32_T zd5c4841bfc[(0x9f1+3554-0x17b3)];volatile uint32_T zac3cfff3eb[(0x268+415-0x3e7)];}ze52d134951;static void mdlInitializeSizes(SimStruct*S){uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x142+1983-0x901));ssSetNumDiscStates(S,(0x1983+1690-0x201d));if(mxGetPr(z62fc1d1d8e)[(0xc8a+244-0xd7e)]){ssSetNumOutputPorts(S,mxGetN(za9d8fb6bcf));for(i=(0x19ac+2275-0x228f);i<mxGetN(za9d8fb6bcf);i++){ssSetOutputPortWidth(S,i,(uint32_T)mxGetPr(z3d4ad966bd)[(0x22c4+289-0x23e5)]+(0x16c8+1190-0x1b6d));}}else{ssSetNumOutputPorts(S,(0x7c7+1010-0xbb9));}if(mxGetPr(z08a9674173)[(0xfb6+4724-0x222a)]){ssSetNumInputPorts(S,mxGetN(za9d8fb6bcf)+(0xbb1+3269-0x1875));}else{ssSetNumInputPorts(S,mxGetN(za9d8fb6bcf));}for(i=(0x51c+8334-0x25aa);i<mxGetN(za9d8fb6bcf);i++){ssSetInputPortWidth(S,i,(uint32_T)mxGetPr(z3d4ad966bd)[(0x508+107-0x573)]+(0x18bc+1356-0x1e07));ssSetInputPortDirectFeedThrough(S,i,(0x2f6+1879-0xa4c));ssSetInputPortRequiredContiguous(S,i,(0x1628+2180-0x1eab));}if(mxGetPr(z08a9674173)[(0x10c9+4428-0x2215)]){ssSetInputPortWidth(S,mxGetN(za9d8fb6bcf),mxGetN(za9d8fb6bcf));ssSetInputPortDirectFeedThrough(S,mxGetN(za9d8fb6bcf),(0x12b+5577-0x16f3));ssSetInputPortRequiredContiguous(S,mxGetN(za9d8fb6bcf),(0xb54+2282-0x143d));}ssSetNumSampleTimes(S,(0x1435+4226-0x24b6));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xaa8+7251-0x26fb));ssSetNumNonsampledZCs(S,(0x18e2+3460-0x2666));for(i=(0x2da+3207-0xf61);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x16ab+3896-0x25e3));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0xa58+2889-0x15a1)]==-1.0){ssSetSampleTime(S,(0x241c+501-0x2611),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x4dd+5863-0x1bc4),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xd9+246-0x1cf),mxGetPr(z3832b85a32)[(0x1610+3681-0x2471)]);ssSetOffsetTime(S,(0xf7f+3763-0x1e32),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;uint8_T z16ba527520[(0x178d+2023-0x1f60)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61,z4da0d16710,i,z4e3026977c;int32_T z366b2f03bf,z441f9e6d1b;volatile ze52d134951*z7b342dc82d;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x511+5849-0x1bea)];z6f813cde47=z05b56d9d51=5845;switch(z78caf1ba61){case(0x1f0+3328-0xdaf):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;case(0x1c66+1042-0x1f2d):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;break;}if(mxGetN(z702a26a5e9)==(0x1287+5044-0x263a)){z366b2f03bf=(0x1cfd+2384-0x264d);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x98a+933-0xd2f)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x16b2+3640-0x24ea)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x66+9430-0x253b)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x1e08+111-0x1e75)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x20c+4664-0x1442)],zeccbadd9b3.Length[(0x7d4+2646-0x1228)],XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0xee5+5587-0x24b6)]);if(!xpceIsModelInit()){z7b342dc82d=(ze52d134951*)(zeccbadd9b3.VirtAddress[(0x343+2943-0xec0)]+z992cb6e285);z4da0d16710=(0x4e7+2331-0xe02);for(i=(0x523+1564-0xb3f);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x24a7+98-0x2508);z4da0d16710|=((0x155f+1546-0x1b68)<<z4e3026977c);}z7b342dc82d->z4da0d16710=z4da0d16710;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE     
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint32_T z26dbd73a5e,i,width,count,z03312e422a;real_T*in,*out,*z46c2b7bc26;uint32_T z4e3026977c,status;volatile ze52d134951*z7b342dc82d;z7b342dc82d=(ze52d134951*)(base+z992cb6e285);width=(uint32_T)mxGetPr(z3d4ad966bd)[(0x396+1600-0x9d6)]+(0x139f+2772-0x1e72);z03312e422a=(0x2096+939-0x2441);for(i=(0x673+5572-0x1c37);i<mxGetN(za9d8fb6bcf);i++)
{z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x14f7+2740-0x1faa);in=(real_T*)ssGetInputPortSignal(S,z4e3026977c);count=z7b342dc82d->z45128425fd[z4e3026977c];if(count>(0x2da+6870-0x1db0)){sprintf(zea4cd01646,"\x54\x72\x69\x65\x64\x20\x74\x6f\x20\x77\x72\x69\x74\x65\x20\x69\x6e\x20\x61\x20\x6e\x6f\x6e\x2d\x65\x6d\x70\x74\x79\x20\x62\x75\x66\x66\x65\x72");ssSetErrorStatus(S,zea4cd01646);return;}
if(mxGetPr(z08a9674173)[(0xde5+6385-0x26d6)]){z46c2b7bc26=(real_T*)ssGetInputPortSignal(S,mxGetN(za9d8fb6bcf));z7b342dc82d->zef72e5f2d0[z4e3026977c]=(uint32_T)z46c2b7bc26[i];}count=(uint32_T)in[(0x1c63+770-0x1f65)];for(z26dbd73a5e=(0x2092+1321-0x25bb);z26dbd73a5e<count;z26dbd73a5e++)
{
z7b342dc82d->z633e4d0b43[z4e3026977c]=(uint32_T)in[z26dbd73a5e+(0xf16+3376-0x1c45)];
z7b342dc82d->z17cbe2a22e[z4e3026977c]=z26dbd73a5e;
z7b342dc82d->z21ab44ce3e=((0xa9f+1085-0xedb)<<z4e3026977c);z7b342dc82d->z21ab44ce3e=(0xa29+7319-0x26c0);}
z7b342dc82d->z45128425fd[z4e3026977c]=count;
z7b342dc82d->z03312e422a=((0x22da+71-0x2320)<<z4e3026977c);z7b342dc82d->z03312e422a=(0x1da9+2037-0x259e);}
if(mxGetPr(z62fc1d1d8e)[(0xe75+5884-0x2571)]){for(i=(0x6f6+2715-0x1191);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x325+5596-0x1900);out=ssGetOutputPortSignal(S,z4e3026977c);in=(real_T*)ssGetInputPortSignal(S,z4e3026977c);if(in[(0xd4+4591-0x12c3)]>(0x1643+3949-0x25b0)){do{status=z7b342dc82d->status;}while((status&((0x1245+753-0x1535)<<z4e3026977c))==(0x174+1368-0x6cc));}for(z26dbd73a5e=(0x3d5+1125-0x83a);z26dbd73a5e<(uint8_T)mxGetPr(z3d4ad966bd)[(0xf18+1927-0x169f)];z26dbd73a5e++){out[z26dbd73a5e]=(0xe79+4682-0x20c3);
}for(z26dbd73a5e=(0x986+7081-0x252f);z26dbd73a5e<in[(0x109f+4896-0x23bf)];z26dbd73a5e++){
z7b342dc82d->z17cbe2a22e[z4e3026977c]=z26dbd73a5e;
out[z26dbd73a5e+(0x2ba+8985-0x25d2)]=(real_T)z7b342dc82d->z1907ddba6c[z4e3026977c];
}out[(0x826+6834-0x22d8)]=in[(0x132d+1675-0x19b8)];

z7b342dc82d->z05095ec8c5=((0x11a+4795-0x13d4)<<z4e3026977c);z7b342dc82d->z05095ec8c5=(0x76d+4299-0x1838);}}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE   
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T i;uint32_T z4e3026977c,z1209c02d78,zdc0d676974,zbea4a89f24,z9e58a4ec45;volatile ze52d134951*z7b342dc82d=(ze52d134951*)(base+z992cb6e285);z1209c02d78=(uint32_T)z7b342dc82d->z4da0d16710;zdc0d676974=(uint32_T)z7b342dc82d->z13e3aff50f;zbea4a89f24=(uint32_T)z7b342dc82d->z79c39f7a01;z9e58a4ec45=(uint32_T)z7b342dc82d->MSBFirst;for(i=(0x206+8223-0x2225);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1124+451-0x12e6);z7b342dc82d->z185b3cf79e[z4e3026977c]=(uint32_T)mxGetPr(z7039def18e)[i];z7b342dc82d->zef72e5f2d0[z4e3026977c]=(uint32_T)mxGetPr(zf6f668e67a)[i];z7b342dc82d->z8a775a0c78[z4e3026977c]=(uint32_T)mxGetPr(zbb0d1897b2)[i];z7b342dc82d->zfac62c691a[z4e3026977c]=(uint32_T)mxGetPr(z8f7a5b7479)[i];z7b342dc82d->zd5c4841bfc[z4e3026977c]=(uint32_T)mxGetPr(zdc5f8981b7)[i];z7b342dc82d->zac3cfff3eb[z4e3026977c]=(uint32_T)mxGetPr(zc09b06e5fc)[i];z1209c02d78|=((0x106d+1310-0x158a)<<z4e3026977c);zdc0d676974|=(((uint32_T)mxGetPr(z86af52d74e)[i])<<z4e3026977c);zbea4a89f24|=(((uint32_T)mxGetPr(z31fb671cb8)[i])<<z4e3026977c);z9e58a4ec45|=(((uint32_T)mxGetPr(zea4d7ef473)[i])<<z4e3026977c);}z7b342dc82d->z13e3aff50f=zdc0d676974;z7b342dc82d->MSBFirst=z9e58a4ec45;z7b342dc82d->z79c39f7a01=zbea4a89f24;
z7b342dc82d->z4da0d16710=(0x550+1938-0xce2);
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

