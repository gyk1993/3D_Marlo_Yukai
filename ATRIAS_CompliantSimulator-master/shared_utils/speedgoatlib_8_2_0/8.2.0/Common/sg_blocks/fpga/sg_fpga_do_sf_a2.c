/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x11f8+943-0x15a5)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_do_sf_a2
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
#define zdf24515981        ((0x38+3701-0xea6))
#define z533b11d03f         ssGetSFcnParam(S, (0x39f+7344-0x204f)) 
#define za9d8fb6bcf           ssGetSFcnParam(S, (0x1+9573-0x2565)) 
#define zeb9408a20d        ssGetSFcnParam(S, (0x6e6+1833-0xe0d))
#define zc8bbaa6115             ssGetSFcnParam(S, (0xc80+1247-0x115c))
#define zf80b27df71              ssGetSFcnParam(S, (0x1ba1+933-0x1f42))
#define z3832b85a32         ssGetSFcnParam(S, (0xe8a+3813-0x1d6a))
#define z702a26a5e9              ssGetSFcnParam(S, (0x1670+2984-0x2212))
#define z2e6483d505              ((0x98a+3068-0x1585))
#define zc5ce4cb81a              ((0x288+1868-0x9d4))
#define z2b17e2ee3b              ((0x1b3+8179-0x21a6))
#define z6a0da049de         ((0x1821+1844-0x1f55))
#define z6ca7c70544                 (81920)
static char_T zea4cd01646[(0x1257+5407-0x2676)];typedef struct{uint32_T dir[(0x184d+3338-0x2553)];uint32_T z53343b042a[(0x23ba+670-0x2654)];}z53343b042a;static void mdlInitializeSizes(SimStruct*S){uint32_T i,za0df33019b;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x7b3+3540-0x1587));ssSetNumDiscStates(S,(0x2164+436-0x2318));if((uint32_T)mxGetPr(zeb9408a20d)[(0x944+92-0x9a0)]){ssSetNumInputPorts(S,(0x9ca+2348-0x12f5));ssSetInputPortWidth(S,(0x33d+6776-0x1db5),(uint32_T)mxGetN(za9d8fb6bcf));ssSetInputPortDirectFeedThrough(S,(0x20aa+731-0x2385),(0x21f0+1084-0x262b));ssSetInputPortRequiredContiguous(S,(0xd62+1697-0x1403),(0x10cc+4900-0x23ef));}else{za0df33019b=(uint32_T)mxGetN(za9d8fb6bcf);ssSetNumInputPorts(S,za0df33019b);for(i=(0xd0a+83-0xd5d);i<za0df33019b;i++){ssSetInputPortWidth(S,i,(0x7bc+3959-0x1732));ssSetInputPortDirectFeedThrough(S,i,(0x971+21-0x985));ssSetInputPortRequiredContiguous(S,i,(0x933+3370-0x165c));}}ssSetNumOutputPorts(S,(0x4cb+840-0x813));ssSetNumSampleTimes(S,(0x5f3+3774-0x14b0));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x417+3384-0x114f));ssSetNumNonsampledZCs(S,(0x714+1908-0xe88));for(i=(0x27a+249-0x373);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x712+1335-0xc49));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0xfa7+4084-0x1f9b)]==-1.0){ssSetSampleTime(S,(0xbf4+671-0xe93),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xc8+8063-0x2047),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xf39+3386-0x1c73),mxGetPr(z3832b85a32)[(0xd90+2373-0x16d5)]);ssSetOffsetTime(S,(0x2158+112-0x21c8),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;uint32_T i;int32_T z366b2f03bf,z441f9e6d1b;volatile z53343b042a*z84bcaa13e8;uint8_T z16ba527520[(0x1046+4722-0x22a4)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61,z4e3026977c;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x1490+435-0x1643)];z6f813cde47=z05b56d9d51=5845;switch(z78caf1ba61){case(0xcc8+6879-0x265c):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;break;default:sprintf(zea4cd01646,"\x62\x6f\x61\x72\x64\x20\x74\x79\x70\x65\x20\x69\x6e\x63\x6f\x72\x72\x65\x63\x74\x2e");ssSetErrorStatus(S,zea4cd01646);return;}if(mxGetN(z702a26a5e9)==(0x14b3+2480-0x1e62)){z366b2f03bf=(0x9af+7426-0x26b1);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x1053+195-0x1116)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x233d+754-0x262f)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x1370+683-0x161a)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0xf45+196-0x1007)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0xe1d+617-0x1084)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x61f+3487-0x13bc)]);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base;uint8_T z056c1df3ff,z6a384f9db4,z8a340138bc,zeeb5dd30fb;uint32_T z8f9317294c,z2e9721fc5a,zbba2e8a63c,z4f6f17a170;uint32_T i,z4e3026977c;real_T data;real_T*in;volatile z53343b042a*z84bcaa13e8;z056c1df3ff=(0x1eaa+782-0x21b8);z6a384f9db4=(0x404+5846-0x1ada);z8a340138bc=(0x1394+4463-0x2503);zeeb5dd30fb=(0x11d9+1076-0x160d);base=ssGetIWorkValue(S,z6a0da049de);z84bcaa13e8=(z53343b042a*)(base+z6ca7c70544);
for(i=(0xb61+3010-0x1723);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x9a0+6081-0x2160);if(z4e3026977c<(0xbf+9156-0x2463)){z056c1df3ff=(0x1c91+1002-0x207a);}else if(z4e3026977c<(0x49b+4856-0x1753)){z6a384f9db4=(0x644+66-0x685);}else if(z4e3026977c<(0x920+7209-0x24e9)){z8a340138bc=(0x101f+1055-0x143d);}else if(z4e3026977c<(0x29a+2263-0xaf1)){zeeb5dd30fb=(0x1976+2618-0x23af);}else{sprintf(zea4cd01646,"\x45\x72\x72\x6f\x72\x3a\x20\x75\x6e\x73\x75\x70\x70\x6f\x72\x74\x65\x64\x20\x63\x68\x61\x6e\x6e\x65\x6c\x2e");ssSetErrorStatus(S,zea4cd01646);return;}}
if(z056c1df3ff){z8f9317294c=z84bcaa13e8->z53343b042a[(0xcc6+5844-0x239a)];}if(z6a384f9db4){z2e9721fc5a=z84bcaa13e8->z53343b042a[(0x2f3+6035-0x1a85)];}if(z8a340138bc){zbba2e8a63c=z84bcaa13e8->z53343b042a[(0xc94+2116-0x14d6)];}if(zeeb5dd30fb){z4f6f17a170=z84bcaa13e8->z53343b042a[(0x115a+292-0x127b)];}
for(i=(0x4c2+8146-0x2494);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x22cd+809-0x25f5);if((uint32_T)mxGetPr(zeb9408a20d)[(0x1e7a+779-0x2185)]){in=(real_T*)ssGetInputPortSignal(S,(0x1ea+668-0x486));data=in[i];}else{in=(real_T*)ssGetInputPortSignal(S,i);data=in[(0x16b8+2811-0x21b3)];}if(z4e3026977c<(0x1c5+5974-0x18fb)){if(data>0.5){z8f9317294c|=((0x22a5+581-0x24e9)<<z4e3026977c);}else{z8f9317294c&=~((0xe2c+3010-0x19ed)<<z4e3026977c);}}else if(z4e3026977c<(0x6ad+4351-0x176c)){z4e3026977c-=(0x7cb+4666-0x19e5);if(data>0.5){z2e9721fc5a|=((0x111b+2167-0x1991)<<z4e3026977c);}else{z2e9721fc5a&=~((0x4cb+2670-0xf38)<<z4e3026977c);}}else if(z4e3026977c<(0xb3+7646-0x1e31)){z4e3026977c-=(0x95f+5963-0x206a);if(data>0.5){zbba2e8a63c|=((0x1614+4330-0x26fd)<<z4e3026977c);}else{zbba2e8a63c&=~((0x1d2d+1164-0x21b8)<<z4e3026977c);}}else if(z4e3026977c<(0x1086+2186-0x1890)){z4e3026977c-=(0xa26+2393-0x131f);if(data>0.5){z4f6f17a170|=((0x617+2641-0x1067)<<z4e3026977c);}else{z4f6f17a170&=~((0x396+3320-0x108d)<<z4e3026977c);}}
}
if(z056c1df3ff){z84bcaa13e8->z53343b042a[(0x1a06+2146-0x2268)]=z8f9317294c;}if(z6a384f9db4){z84bcaa13e8->z53343b042a[(0x16e9+3509-0x249d)]=z2e9721fc5a;}if(z8a340138bc){z84bcaa13e8->z53343b042a[(0xccb+5976-0x2421)]=zbba2e8a63c;}if(zeeb5dd30fb){z84bcaa13e8->z53343b042a[(0x44d+4316-0x1526)]=z4f6f17a170;}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base;uint32_T z8f9317294c,z2e9721fc5a,zbba2e8a63c,z4f6f17a170;uint32_T z3c94dc2444,zbf16694233,z95284da6db,zbd36544ae7;uint32_T i,z4e3026977c;volatile z53343b042a*z84bcaa13e8;base=ssGetIWorkValue(S,z6a0da049de);z84bcaa13e8=(z53343b042a*)(base+z6ca7c70544);z8f9317294c=z84bcaa13e8->z53343b042a[(0x15e0+2901-0x2135)];z2e9721fc5a=z84bcaa13e8->z53343b042a[(0xd24+3568-0x1b13)];zbba2e8a63c=z84bcaa13e8->z53343b042a[(0xc23+5437-0x215e)];z4f6f17a170=z84bcaa13e8->z53343b042a[(0x1c22+1459-0x21d2)];if(xpceIsModelInit()){
z3c94dc2444=z84bcaa13e8->dir[(0x1a8b+1811-0x219e)];zbf16694233=z84bcaa13e8->dir[(0x1fdc+58-0x2015)];z95284da6db=z84bcaa13e8->dir[(0x1513+2036-0x1d05)];zbd36544ae7=z84bcaa13e8->dir[(0x10b+9097-0x2491)];
for(i=(0x3d1+8285-0x242e);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1b8+7097-0x1d70);if(z4e3026977c<(0xc90+763-0xf6b)){z3c94dc2444|=((0xf05+4104-0x1f0c)<<z4e3026977c);}else if(z4e3026977c<(0x14c7+1885-0x1be4)){z4e3026977c-=(0x74c+7210-0x2356);zbf16694233|=((0x10c+1443-0x6ae)<<z4e3026977c);}else if(z4e3026977c<(0x381+6582-0x1cd7)){z4e3026977c-=(0x2192+184-0x220a);z95284da6db|=((0x5f3+7121-0x21c3)<<z4e3026977c);}else if(z4e3026977c<(0xf23+5999-0x2612)){z4e3026977c-=(0x2ff+6920-0x1da7);zbd36544ae7|=((0xd2a+1182-0x11c7)<<z4e3026977c);}}
z84bcaa13e8->dir[(0x179c+3661-0x25e9)]=z3c94dc2444;z84bcaa13e8->dir[(0x1b2b+2572-0x2536)]=zbf16694233;z84bcaa13e8->dir[(0x42a+2297-0xd21)]=z95284da6db;z84bcaa13e8->dir[(0xaf8+3379-0x1828)]=zbd36544ae7;}for(i=(0xc9c+5364-0x2190);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xea5+1312-0x13c4);if((uint32_T)mxGetPr(zc8bbaa6115)[i]){if(z4e3026977c<(0x2191+501-0x2366)){if((uint32_T)mxGetPr(zf80b27df71)[i]){z8f9317294c|=((0x3e4+3570-0x11d5)<<z4e3026977c);}else{z8f9317294c&=~((0x730+7714-0x2551)<<z4e3026977c);}}else if(z4e3026977c<(0x67c+4383-0x175b)){z4e3026977c-=(0x1719+511-0x18f8);if((uint32_T)mxGetPr(zf80b27df71)[i]){z2e9721fc5a|=((0xb22+3116-0x174d)<<z4e3026977c);}else{z2e9721fc5a&=~((0xc04+4356-0x1d07)<<z4e3026977c);}}else if(z4e3026977c<(0x1400+2670-0x1e0e)){z4e3026977c-=(0x792+5089-0x1b33);if((uint32_T)mxGetPr(zf80b27df71)[i]){zbba2e8a63c|=((0x971+5187-0x1db3)<<z4e3026977c);}else{zbba2e8a63c&=~((0x21fc+418-0x239d)<<z4e3026977c);}}else if(z4e3026977c<(0x317+29-0x2b4)){z4e3026977c-=(0x8b2+71-0x899);if((uint32_T)mxGetPr(zf80b27df71)[i]){z4f6f17a170|=((0x525+6428-0x1e40)<<z4e3026977c);}else{z4f6f17a170&=~((0xb3+2393-0xa0b)<<z4e3026977c);}}}}z84bcaa13e8->z53343b042a[(0x17e7+283-0x1902)]=z8f9317294c;z84bcaa13e8->z53343b042a[(0xe1+7618-0x1ea2)]=z2e9721fc5a;z84bcaa13e8->z53343b042a[(0x757+6662-0x215b)]=zbba2e8a63c;z84bcaa13e8->z53343b042a[(0x1618+170-0x16bf)]=z4f6f17a170;
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif
