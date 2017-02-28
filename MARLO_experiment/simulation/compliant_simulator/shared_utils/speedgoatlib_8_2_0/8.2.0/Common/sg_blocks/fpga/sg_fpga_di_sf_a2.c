/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x17ed+1256-0x1cd3)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_di_sf_a2
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
#define zdf24515981        ((0x23b8+773-0x26b8))
#define z533b11d03f         ssGetSFcnParam(S, (0xa8b+1532-0x1087)) 
#define za9d8fb6bcf           ssGetSFcnParam(S, (0xd1+3746-0xf72)) 
#define zeb9408a20d        ssGetSFcnParam(S, (0x9cc+5512-0x1f52))
#define z3832b85a32         ssGetSFcnParam(S, (0x54c+5257-0x19d2))
#define z702a26a5e9              ssGetSFcnParam(S, (0x1531+3722-0x23b7))
#define z2e6483d505              ((0x320+1679-0x9ae))
#define zc5ce4cb81a              ((0x1c05+2732-0x26b1))
#define z2b17e2ee3b              ((0x1e90+398-0x201e))
#define z6a0da049de         ((0x1b8f+1014-0x1f85))
#define z6ca7c70544                 (81920)
static char_T zea4cd01646[(0xf26+2570-0x1830)];typedef struct{uint32_T dir[(0xb1f+1056-0xf3b)];uint32_T z53343b042a[(0x7e9+7855-0x2694)];}z53343b042a;static void mdlInitializeSizes(SimStruct*S){uint32_T i,za0df33019b;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x1262+1628-0x18be));ssSetNumDiscStates(S,(0x6+4804-0x12ca));za0df33019b=(uint32_T)mxGetN(za9d8fb6bcf);if((uint32_T)mxGetPr(zeb9408a20d)[(0x1721+1525-0x1d16)]){ssSetNumOutputPorts(S,(0x754+7634-0x2525));ssSetOutputPortWidth(S,(0x183a+3544-0x2612),za0df33019b);}else{ssSetNumOutputPorts(S,za0df33019b);for(i=(0x176a+2367-0x20a9);i<za0df33019b;i++){ssSetOutputPortWidth(S,i,(0x1894+1379-0x1df6));}}ssSetNumInputPorts(S,(0x2105+1428-0x2699));ssSetNumSampleTimes(S,(0x380+8948-0x2673));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1dbf+760-0x20b7));ssSetNumNonsampledZCs(S,(0xf48+3562-0x1d32));for(i=(0x14c5+2335-0x1de4);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xef5+6054-0x269b));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x5+2629-0xa4a)]==-1.0){ssSetSampleTime(S,(0x2c8+4582-0x14ae),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x491+8786-0x26e3),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x64c+4049-0x161d),mxGetPr(z3832b85a32)[(0x760+3044-0x1344)]);ssSetOffsetTime(S,(0x715+6417-0x2026),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i,z4e3026977c;uint32_T z3c94dc2444,zbf16694233,z95284da6db,zbd36544ae7;volatile z53343b042a*z84bcaa13e8;uint8_T z16ba527520[(0x20e5+495-0x22c0)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x15a0+513-0x17a1)];z6f813cde47=z05b56d9d51=5845;switch(z78caf1ba61){case(0x474+871-0x690):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;break;default:sprintf(zea4cd01646,"\x62\x6f\x61\x72\x64\x20\x74\x79\x70\x65\x20\x69\x6e\x63\x6f\x72\x72\x65\x63\x74\x2e");ssSetErrorStatus(S,zea4cd01646);return;}if(mxGetN(z702a26a5e9)==(0x157b+4247-0x2611)){z366b2f03bf=(0x1375+1561-0x198e);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x17f9+445-0x19b6)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x8e0+4089-0x18d9)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x1d91+464-0x1f60)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x648+5648-0x1c56)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x1346+4382-0x2462)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x12f+1283-0x630)]);if(!xpceIsModelInit()){z84bcaa13e8=(z53343b042a*)(zeccbadd9b3.VirtAddress[(0xd8+4435-0x1229)]+z6ca7c70544);

z3c94dc2444=z84bcaa13e8->dir[(0x832+5628-0x1e2e)];zbf16694233=z84bcaa13e8->dir[(0x1247+913-0x15d7)];z95284da6db=z84bcaa13e8->dir[(0xdfa+1101-0x1245)];zbd36544ae7=z84bcaa13e8->dir[(0xdfb+4926-0x2136)];
for(i=(0x95+9479-0x259c);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x41+8285-0x209d);if(z4e3026977c<(0x9cd+4554-0x1b77)){z3c94dc2444&=~((0x165+2655-0xbc3)<<z4e3026977c);}else if(z4e3026977c<(0xb6a+1497-0x1103)){z4e3026977c-=(0xd36+4697-0x1f6f);zbf16694233&=~((0xfba+3885-0x1ee6)<<z4e3026977c);}else if(z4e3026977c<(0x3b0+2194-0xbe2)){z4e3026977c-=(0x1b6b+2040-0x2323);z95284da6db&=~((0x1b1b+1047-0x1f31)<<z4e3026977c);}else if(z4e3026977c<(0x132d+2179-0x1b30)){z4e3026977c-=(0x296+31-0x255);zbd36544ae7&=~((0x888+6636-0x2273)<<z4e3026977c);}}
z84bcaa13e8->dir[(0x799+2934-0x130f)]=z3c94dc2444;z84bcaa13e8->dir[(0x39b+8828-0x2616)]=zbf16694233;z84bcaa13e8->dir[(0x7a+3729-0xf09)]=z95284da6db;z84bcaa13e8->dir[(0xd4a+4643-0x1f6a)]=zbd36544ae7;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base;uint32_T z846c604456,z1955d85f1a,zc816afd9e0,zb390043d6c,data,z4e3026977c,i;uint32_T reg1,reg2,zdd04f3ebee,zb4174f765c;real_T*out;volatile z53343b042a*z84bcaa13e8;base=ssGetIWorkValue(S,z6a0da049de);z84bcaa13e8=(z53343b042a*)(base+z6ca7c70544);
z846c604456=(0x541+5619-0x1b34);z1955d85f1a=(0x10d0+1728-0x1790);zc816afd9e0=(0x27+3481-0xdc0);zb390043d6c=(0x16b3+3194-0x232d);for(i=(0x168f+1683-0x1d22);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x18a0+1402-0x1e19);if(z4e3026977c<(0x1c67+2313-0x2550)){z846c604456=(0xa54+3681-0x18b4);}else if(z4e3026977c<(0x627+3967-0x1566)){z1955d85f1a=(0x13b9+3739-0x2253);}else if(z4e3026977c<(0x521+7343-0x2170)){zc816afd9e0=(0x131+1767-0x817);}else if(z4e3026977c<(0x1599+2758-0x1fdf)){zb390043d6c=(0x340+8492-0x246b);}else{sprintf(zea4cd01646,"\x45\x72\x72\x6f\x72\x3a\x20\x75\x6e\x73\x75\x70\x70\x6f\x72\x74\x65\x64\x20\x63\x68\x61\x6e\x6e\x65\x6c\x2e");ssSetErrorStatus(S,zea4cd01646);return;}}if(z846c604456){reg1=z84bcaa13e8->z53343b042a[(0x1683+1133-0x1af0)];}if(z1955d85f1a){reg2=z84bcaa13e8->z53343b042a[(0x1141+4108-0x214c)];}if(zc816afd9e0){zdd04f3ebee=z84bcaa13e8->z53343b042a[(0x73c+5060-0x1afe)];}if(zb390043d6c){zb4174f765c=z84bcaa13e8->z53343b042a[(0x19ab+719-0x1c77)];}
for(i=(0xc38+5282-0x20da);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1738+1972-0x1eeb);if(z4e3026977c<(0x709+1042-0xafb)){data=(reg1>>z4e3026977c)&(0x480+7762-0x22d1);}else if(z4e3026977c<(0x31c+3872-0x11fc)){z4e3026977c-=(0x1094+1859-0x17b7);data=(reg2>>z4e3026977c)&(0x700+7384-0x23d7);}else if(z4e3026977c<(0xd2a+4100-0x1cce)){z4e3026977c-=(0x157c+1088-0x197c);data=(zdd04f3ebee>>z4e3026977c)&(0xd1a+6492-0x2675);}else if(z4e3026977c<(0xad7+110-0xac5)){z4e3026977c-=(0x109d+1464-0x15f5);data=(zb4174f765c>>z4e3026977c)&(0xeaa+1161-0x1332);}if((uint32_T)mxGetPr(zeb9408a20d)[(0x530+3960-0x14a8)]){out=(real_T*)ssGetOutputPortSignal(S,(0x755+5545-0x1cfe));out[i]=data;}else{out=(real_T*)ssGetOutputPortSignal(S,i);out[(0x157+4269-0x1204)]=data;}}
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
