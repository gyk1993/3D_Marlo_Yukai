/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x10a4+888-0x141a)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_ldo_sf
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
#define zdf24515981          ((0x1272+1856-0x19ab))
#define z533b11d03f           ssGetSFcnParam(S,(0x9e0+2902-0x1536))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0xd2d+4349-0x1e29))
#define z644559a0a7               ssGetSFcnParam(S,(0x316+5537-0x18b5))
#define z5fcbfd2762      ssGetSFcnParam(S,(0x4ea+8316-0x2563))    
#define zeac6896859          ssGetSFcnParam(S,(0x1994+575-0x1bcf))
#define z3832b85a32           ssGetSFcnParam(S,(0x20b3+336-0x21fe))
#define z702a26a5e9                ssGetSFcnParam(S,(0x1b77+1835-0x229c))
#define z2e6483d505              ((0x870+1380-0xdd2))
#define z7e2eeaa57c          ((0xea5+1656-0x151d))
#define z6a0da049de         ((0x1db0+2198-0x2645))
#define zc5ce4cb81a              ((0x5e5+7588-0x2379))
#define z2b17e2ee3b              ((0x109+3866-0x1023))
static char_T zea4cd01646[(0x424+2913-0xe85)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x810+1138-0xc82));ssSetNumDiscStates(S,(0x635+1523-0xc28));ssSetNumOutputPorts(S,(0xe23+1093-0x1268));ssSetNumInputPorts(S,(0xab+2838-0xbbf)*mxGetPr(za9d8fb6bcf)[(0x2037+524-0x2243)]);for(i=(0x879+3526-0x163f);i<mxGetPr(za9d8fb6bcf)[(0x7b7+861-0xb14)]*(0x213+7768-0x2069);i++){ssSetInputPortDataType(S,i,SS_BOOLEAN);ssSetInputPortWidth(S,i,(0x976+413-0xb12));ssSetInputPortDirectFeedThrough(S,i,(0xbd4+782-0xee1));ssSetInputPortRequiredContiguous(S,i,(0x151d+4325-0x2601));}ssSetNumSampleTimes(S,(0x65c+8079-0x25ea));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x4a6+2784-0xf86));ssSetNumNonsampledZCs(S,(0xae2+5072-0x1eb2));for(i=(0x20f7+127-0x2176);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x119d+967-0x1564));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x668+6934-0x217e)]==-1.0){ssSetSampleTime(S,(0x10f3+419-0x1296),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1bdd+1775-0x22cc),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x14fa+677-0x179f),mxGetPr(z3832b85a32)[(0x4d0+2481-0xe81)]);ssSetOffsetTime(S,(0x63d+3454-0x13bb),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint8_T z16ba527520[(0x17e3+2483-0x2182)];uint16_T z6f813cde47,za4a2434e08;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x2272+952-0x262a)];switch(z78caf1ba61){case(0xba4+471-0xc4e):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");z6f813cde47=(0x197d+8772-0x24ec);za4a2434e08=17232;break;case(0xe69+2852-0x185f):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");z6f813cde47=(0x1b3f+1738-0xb34);za4a2434e08=17239;break;case(0xee7+2991-0x1967):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");z6f813cde47=(0x25d6+1567-0x1520);za4a2434e08=16979;break;case(0x6fb+5967-0x1d1a):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");z6f813cde47=(0x1a6d+5836-0x1a64);za4a2434e08=(0x91c+5023-0x17b7);break;case(0xc81+6869-0x261f):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");z6f813cde47=(0x175b+76-0xd2);za4a2434e08=21069;break;case(0x1f2f+682-0x20a1):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");z6f813cde47=5845;za4a2434e08=16971;break;case(0x1219+5260-0x256c):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");z6f813cde47=5845;za4a2434e08=17235;break;case(0x1006+1536-0x14cc):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");z6f813cde47=(0x26f5+5646-0x262e);za4a2434e08=(0x2550+4891-0x1867);break;case(0xda1+5993-0x23c9):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");z6f813cde47=(0x23e6+6578-0x26c3);za4a2434e08=19520;break;}if((int_T)mxGetPr(z702a26a5e9)[(0x6f3+6872-0x21cb)]<(0x51f+7261-0x217c)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x114c+1819-0x1866)){z366b2f03bf=(0x2e7+7340-0x1f93);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x18e3+99-0x1946)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x1d49+138-0x1dd3)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x8e8+1572-0xf0b)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0xea0+5837-0x246e))|((z366b2f03bf&(0x231+429-0x2df))<<(0x48c+3289-0x115d)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x1522+3070-0x211e)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T i;volatile uint32_T*za42cf7dd4a;boolean_T*za430cff744;uint32_T z4e3026977c;uint32_T z7be9105675;za42cf7dd4a=(void*)base;z7be9105675=(0x524+5866-0x1c0e);for(i=(0xef0+5241-0x2369);i<(0x1af1+662-0x1d85)*mxGetPr(za9d8fb6bcf)[(0x1ba0+2000-0x2370)];i++){za430cff744=(boolean_T*)ssGetInputPortSignal(S,i);if(za430cff744[(0x11b7+4631-0x23ce)]>(0x42f+3586-0x1231)){z7be9105675|=((0x65+7276-0x1cd0)<<i);}}za42cf7dd4a[10068]=z7be9105675;if(mxGetPr(z5fcbfd2762)[(0x15c2+4191-0x2621)]==(0x1232+270-0x133d)){za42cf7dd4a[10071]=(0x1b47+108-0x1bb2);za42cf7dd4a[10071]=(0x11fa+4549-0x23bf);}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T i;volatile uint32_T*za42cf7dd4a;uint32_T protection;za42cf7dd4a=(void*)base;protection=(0x633+8411-0x270e);for(i=(0x2cc+5887-0x19cb);i<mxGetPr(za9d8fb6bcf)[(0x164+1749-0x839)];i++){
protection|=((uint32_T)mxGetPr(zeac6896859)[i])<<((0x40+5891-0x1741)*i);}
za42cf7dd4a[10065]=protection;
za42cf7dd4a[10067]=(uint32_T)mxGetPr(z644559a0a7)[(0xfd4+2789-0x1ab9)];
if(mxGetPr(z5fcbfd2762)[(0x68a+1343-0xbc9)]==(0x1aa+5209-0x1602)){
za42cf7dd4a[10070]=(0x2d4+6835-0x1d86);}if(mxGetPr(z5fcbfd2762)[(0x1638+2464-0x1fd8)]==(0x1aef+294-0x1c13)){
za42cf7dd4a[10070]=(0x1426+2258-0x1cf6);}if(mxGetPr(z5fcbfd2762)[(0x2163+893-0x24e0)]==(0x1491+1626-0x1ae8)){
za42cf7dd4a[10070]=(0x1b64+1218-0x2023);}
za42cf7dd4a[10064]=(0xea5+4217-0x1f1d);
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

