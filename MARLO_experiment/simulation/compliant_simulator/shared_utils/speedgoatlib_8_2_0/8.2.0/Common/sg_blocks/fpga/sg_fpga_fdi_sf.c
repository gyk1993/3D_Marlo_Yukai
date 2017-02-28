/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x827+890-0xb9f)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_fdi_sf
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
#define zdf24515981          ((0xbf4+5790-0x228c))
#define z533b11d03f           ssGetSFcnParam(S, (0x1456+4401-0x2587))
#define z2cc9a52544            ssGetSFcnParam(S, (0xb22+4456-0x1c89))
#define zbcb3e4d083              ssGetSFcnParam(S, (0x1250+1894-0x19b4))
#define ze072c43310               ssGetSFcnParam(S, (0x10bd+659-0x134d)) 
#define z3832b85a32           ssGetSFcnParam(S, (0x207c+770-0x237a))
#define z702a26a5e9                ssGetSFcnParam(S, (0x17fa+1929-0x1f7e))
#define z2e6483d505              ((0x11b9+4302-0x2285))
#define z6a0da049de         ((0xb0+8267-0x20fb))
#define zc2f3e0cbc0        ((0x11b7+4893-0x24d3))
#define zc5ce4cb81a              ((0xa09+3366-0x172f))
#define z2b17e2ee3b              ((0x1d+3034-0xbf7))
#define THRESHOLD               0.5
#define z912da550ff                 (0xeb+7120-0x1cba)
#define zfdfce9fcd3                 (0xaac+768-0xdaa)
#define z4e6712de2b                 (0x1064+2854-0x1b87)
static char_T zea4cd01646[(0x1bc3+949-0x1e78)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;uint16_T z5c3a9b25b9;uint32_T z78caf1ba61;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x9aa+2597-0x13cf));ssSetNumDiscStates(S,(0x1325+214-0x13fb));ssSetNumInputPorts(S,(0xa54+6065-0x2205));
if((int_T)mxGetPr(zbcb3e4d083)[(0x4c+5643-0x1657)]==z912da550ff){
z5c3a9b25b9=(0x15d0+3839-0x24b1);
switch((uint8_T)mxGetPr(z2cc9a52544)[(0x24+8974-0x2332)]){case(0x995+5582-0x1f62):ssSetNumOutputPorts(S,z5c3a9b25b9);for(i=(0x633+3936-0x1593);i<z5c3a9b25b9;i++){ssSetOutputPortWidth(S,i,(0x214b+636-0x23c6));}break;case(0x811+2769-0x12e0):ssSetNumOutputPorts(S,z5c3a9b25b9);for(i=(0x1e29+1061-0x224e);i<z5c3a9b25b9;i++){ssSetOutputPortWidth(S,i,(0x1a4c+553-0x1c74));ssSetOutputPortDataType(S,i,SS_BOOLEAN);}break;case(0x11ff+840-0x1544):ssSetNumOutputPorts(S,(0x212+6377-0x1afa));ssSetOutputPortWidth(S,(0x580+3125-0x11b5),z5c3a9b25b9);break;case(0x12d4+1597-0x190d):ssSetNumOutputPorts(S,(0xd68+5449-0x22b0));ssSetOutputPortWidth(S,(0x6f8+4141-0x1725),z5c3a9b25b9);ssSetOutputPortDataType(S,(0x2231+806-0x2557),SS_BOOLEAN);break;case(0x425+7931-0x231b):ssSetNumOutputPorts(S,(0x748+349-0x8a4));ssSetOutputPortWidth(S,(0xf36+4885-0x224b),(0x35f+4681-0x15a7));ssSetOutputPortDataType(S,(0x664+3739-0x14ff),SS_UINT32);break;}}else if((int_T)mxGetPr(zbcb3e4d083)[(0xb3+4650-0x12dd)]==zfdfce9fcd3){if((uint32_T)mxGetPr(ze072c43310)[(0x6d2+29-0x6ef)]==(0x9f0+6938-0x2509)){z5c3a9b25b9=(0x454+816-0x774);}else{z5c3a9b25b9=(0x267+7333-0x1ef6);}switch((uint8_T)mxGetPr(z2cc9a52544)[(0x379+8226-0x239b)]){case(0x9bd+5321-0x1e85):ssSetNumOutputPorts(S,z5c3a9b25b9);for(i=(0x225+9195-0x2610);i<z5c3a9b25b9;i++){ssSetOutputPortWidth(S,i,(0x74b+6260-0x1fbe));}break;case(0x15ba+3061-0x21ad):ssSetNumOutputPorts(S,z5c3a9b25b9);for(i=(0x1285+2617-0x1cbe);i<z5c3a9b25b9;i++){ssSetOutputPortWidth(S,i,(0xdf8+506-0xff1));ssSetOutputPortDataType(S,i,SS_BOOLEAN);}break;case(0x85f+3870-0x177a):ssSetNumOutputPorts(S,(0x184a+711-0x1b10));ssSetOutputPortWidth(S,(0x21d4+1266-0x26c6),z5c3a9b25b9);break;case(0x2315+457-0x24da):ssSetNumOutputPorts(S,(0xd71+2380-0x16bc));ssSetOutputPortWidth(S,(0x1740+1488-0x1d10),z5c3a9b25b9);ssSetOutputPortDataType(S,(0x264+5234-0x16d6),SS_BOOLEAN);break;case(0x1616+2454-0x1fa7):ssSetNumOutputPorts(S,(0x1d5+6959-0x1d03));ssSetOutputPortWidth(S,(0xe5b+5712-0x24ab),(0xad+9438-0x258a));ssSetOutputPortDataType(S,(0x447+876-0x7b3),SS_UINT32);break;}}else{sprintf(zea4cd01646,"\x25\x49\x6e\x76\x61\x6c\x69\x64\x20\x63\x68\x6f\x69\x63\x65");ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumSampleTimes(S,(0x64c+3784-0x1513));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x200b+1728-0x26cb));ssSetNumNonsampledZCs(S,(0x4ca+2336-0xdea));for(i=(0x1aa+2156-0xa16);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x5b+1204-0x50f));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x2a5+8763-0x24e0)]==-1.0){ssSetSampleTime(S,(0x8d9+7140-0x24bd),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xa28+4648-0x1c50),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xc2a+1765-0x130f),mxGetPr(z3832b85a32)[(0x14f3+2611-0x1f26)]);ssSetOffsetTime(S,(0x4f+228-0x133),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zef529fae4a;void*ze2370ae9b9;volatile uint32_T*z3e5b8e05d8;void*zdfcb1da404;void*zf2db5722bf;volatile uint32_T*z27fd94ac66;uint_T i;uint32_T out;uint8_T z16ba527520[(0x1050+978-0x140e)];uint16_T z6f813cde47,za4a2434e08;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x1c34+2268-0x2510)];switch(z78caf1ba61){case(0x18d8+1405-0x1d14):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");z6f813cde47=(0x206a+483-0xb78);za4a2434e08=19520;break;}if((int_T)mxGetPr(z702a26a5e9)[(0x1a7d+2492-0x2439)]<(0x374+8955-0x266f)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xf54+4195-0x1fb6)){z366b2f03bf=(0x7ba+3113-0x13e3);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x372+2583-0xd89)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0xbeb+5069-0x1fb8)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xced+5359-0x21db)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x1418+696-0x15d1))|((z366b2f03bf&(0xd17+3240-0x18c0))<<(0x122b+3537-0x1ff4)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zef529fae4a=(void*)zeccbadd9b3.BaseAddress[(0x605+147-0x696)];ze2370ae9b9=rl32eGetDevicePtr(zef529fae4a,2097152,RT_PG_USERREADWRITE);z3e5b8e05d8=(volatile uint32_T*)ze2370ae9b9;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)z3e5b8e05d8);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*z3e5b8e05d8;uint32_T i,input;real_T*y1;boolean_T*y2;uint32_T*z671e76e748;uint16_T z5c3a9b25b9;z3e5b8e05d8=(void*)base;if((uint8_T)mxGetPr(zbcb3e4d083)[(0x5eb+6246-0x1e51)]==z912da550ff){z5c3a9b25b9=(0x177+9015-0x2490);input=z3e5b8e05d8[8193];switch((uint8_T)mxGetPr(z2cc9a52544)[(0x122b+2320-0x1b3b)]){case(0x150d+3918-0x245a):for(i=(0x1979+3441-0x26ea);i<z5c3a9b25b9;i++){y1=(real_T*)ssGetOutputPortSignal(S,i);y1[(0x129b+230-0x1381)]=(real_T)((input>>i)&(0x1236+3656-0x207d));}break;case(0xb95+3656-0x19db):for(i=(0xf24+2828-0x1a30);i<z5c3a9b25b9;i++){y2=(boolean_T*)ssGetOutputPortSignal(S,i);y2[(0x7ed+6960-0x231d)]=(boolean_T)((input>>i)&(0x1c3d+349-0x1d99));}break;case(0xc15+2476-0x15be):y1=(real_T*)ssGetOutputPortSignal(S,(0x124b+2410-0x1bb5));for(i=(0x1097+2527-0x1a76);i<z5c3a9b25b9;i++){y1[i]=(real_T)((input>>i)&(0x31c+7424-0x201b));}break;case(0xc04+6537-0x2589):y2=(boolean_T*)ssGetOutputPortSignal(S,(0x1a2+8483-0x22c5));for(i=(0x386+2309-0xc8b);i<z5c3a9b25b9;i++){y2[i]=(boolean_T)((input>>i)&(0x4a3+2227-0xd55));}break;case(0xad5+5678-0x20fe):z671e76e748=(uint32_T*)ssGetOutputPortSignal(S,(0xb85+643-0xe08));z671e76e748[(0x4df+3867-0x13fa)]=(uint32_T)input;break;}}else if((uint8_T)mxGetPr(zbcb3e4d083)[(0x4fd+8447-0x25fc)]==zfdfce9fcd3){if((uint32_T)mxGetPr(ze072c43310)[(0x134f+2944-0x1ecf)]==(0x139a+2929-0x1f09)){input=z3e5b8e05d8[8193];

input=(input>>(0xebf+1436-0x1453));z5c3a9b25b9=(0x3f2+882-0x74e);}else{input=z3e5b8e05d8[8195];z5c3a9b25b9=(0x856+4683-0x1a91);}switch((uint8_T)mxGetPr(z2cc9a52544)[(0x1b5+7744-0x1ff5)]){case(0x8c2+3093-0x14d6):for(i=(0xad4+78-0xb22);i<z5c3a9b25b9;i++){y1=(real_T*)ssGetOutputPortSignal(S,i);y1[(0x4dc+4301-0x15a9)]=(real_T)((input>>i)&(0x889+7787-0x26f3));}break;case(0x1010+1515-0x15f9):for(i=(0x649+8220-0x2665);i<z5c3a9b25b9;i++){y2=(boolean_T*)ssGetOutputPortSignal(S,i);y2[(0x13b+6772-0x1baf)]=(boolean_T)((input>>i)&(0x93+181-0x147));}break;case(0x192f+2860-0x2458):y1=(real_T*)ssGetOutputPortSignal(S,(0x1230+129-0x12b1));for(i=(0x9b8+348-0xb14);i<z5c3a9b25b9;i++){y1[i]=(real_T)((input>>i)&(0x1b+3213-0xca7));}break;case(0xc04+4075-0x1beb):y2=(boolean_T*)ssGetOutputPortSignal(S,(0x1c11+2796-0x26fd));for(i=(0x306+1679-0x995);i<z5c3a9b25b9;i++){y2[i]=(boolean_T)((input>>i)&(0x43a+1935-0xbc8));}break;case(0x1b5d+259-0x1c5b):z671e76e748=(uint32_T*)ssGetOutputPortSignal(S,(0xd8+7309-0x1d65));z671e76e748[(0xee4+5804-0x2590)]=(uint32_T)input;break;}}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

