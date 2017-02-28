/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xe05+706-0x10c5)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_setupfdio_sf
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
#define zdf24515981          ((0x77a+3460-0x14f5))
#define z533b11d03f           ssGetSFcnParam(S, (0x1bbc+840-0x1f04))
#define z439f9503b2      ssGetSFcnParam(S, (0x3a6+7492-0x20e9))
#define zbd40e273de      ssGetSFcnParam(S, (0xd5b+1788-0x1455))
#define zbcb3e4d083              ssGetSFcnParam(S, (0x1e18+1459-0x23c8))
#define z871352ca17          ssGetSFcnParam(S, (0x18c1+2704-0x234d))
#define zb34d68df21          ssGetSFcnParam(S, (0x3a7+1014-0x798))
#define z6d22837c30          ssGetSFcnParam(S, (0x1534+1136-0x199e))
#define z1fb57f3c8f          ssGetSFcnParam(S, (0x3a+8969-0x233c))
#define z702a26a5e9                ssGetSFcnParam(S, (0xc64+5154-0x207e))
#define z2e6483d505              ((0x3fb+307-0x52c))
#define z7e2eeaa57c          ((0x3fc+6618-0x1dd6))
#define z6a0da049de         ((0xcfb+1774-0x13e8))
#define zc5ce4cb81a              ((0xb76+6472-0x24ae))
#define z2b17e2ee3b              ((0x1352+1142-0x17c8))
#define THRESHOLD               0.5
#define z912da550ff                 (0x227+5502-0x17a4)
#define zfdfce9fcd3                 (0x338+3881-0x125f)
#define z4e6712de2b                 (0x3e6+1536-0x9e3)
static char_T zea4cd01646[(0x6d0+6984-0x2118)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xe5c+5250-0x22de));ssSetNumDiscStates(S,(0xe57+5954-0x2599));ssSetNumOutputPorts(S,(0xb81+4493-0x1d0e));ssSetNumInputPorts(S,(0x63a+6649-0x2033));ssSetNumSampleTimes(S,(0x2164+1314-0x2685));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x870+4288-0x1930));ssSetNumNonsampledZCs(S,(0x324+2493-0xce1));for(i=(0x9a8+7505-0x26f9);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x950+2964-0x14e4));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x1798+3772-0x2654),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x859+3540-0x162d),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*z2afed1cdc6;volatile uint8_T*z3283caa368;uint_T i;uint8_T z16ba527520[(0x1051+44-0x1069)];uint16_T z6f813cde47,za4a2434e08;uint32_T z5a0a17ae45,z62db3a631c;uint32_T zd7dc6a39d3,z582cdb4021;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0xb6d+892-0xee9)];switch(z78caf1ba61){case(0x114f+2199-0x18a5):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");z6f813cde47=(0x1d30+5347-0x1b3e);za4a2434e08=19520;break;default:sprintf(zea4cd01646,"\x62\x6f\x61\x72\x64\x20\x74\x79\x70\x65\x20\x69\x6e\x63\x6f\x72\x72\x65\x63\x74\x2e");ssSetErrorStatus(S,zea4cd01646);return;}if((int_T)mxGetPr(z702a26a5e9)[(0xde6+3868-0x1d02)]<(0x1bdc+2781-0x26b9)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xaa4+7272-0x270b)){z366b2f03bf=(0x386+57-0x3bf);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1a3+8521-0x22ec)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x71b+2050-0xf1d)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xa48+3072-0x1647)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x562+6704-0x1e93))|((z366b2f03bf&(0x1a89+1790-0x2088))<<(0x1895+3188-0x2501)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x1cd1+2551-0x26c6)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);z2afed1cdc6=(volatile uint32_T*)Virtual;z3283caa368=(volatile uint8_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)z2afed1cdc6);zd7dc6a39d3=(0x1805+2890-0x234f);z582cdb4021=(0x9e6+4166-0x1a2c);z5a0a17ae45=(0xa4+1988-0x868);z62db3a631c=(0x1671+2961-0x2202);if((uint32_T)mxGetPr(zbcb3e4d083)[(0x15cb+773-0x18d0)]==z912da550ff){for(i=(0x1ec+652-0x478);i<(0x35a+1167-0x7cb);i++){if(mxGetPr(z6d22837c30)[i]>=THRESHOLD){zd7dc6a39d3|=(0xd0d+3320-0x1a04)<<i;}if(mxGetPr(z439f9503b2)[i]>=THRESHOLD){z5a0a17ae45|=((0xe56+1807-0x1564)<<i);}}z2afed1cdc6[(0x22f9+6492-0x1c54)]=zd7dc6a39d3;z2afed1cdc6[(0x2222+5687-0x1857)]=z5a0a17ae45;}else if((uint32_T)mxGetPr(zbcb3e4d083)[(0x506+3017-0x10cf)]==zfdfce9fcd3){for(i=(0xa0c+2925-0x1579);i<(0xfa+1421-0x671);i++){if(mxGetPr(z1fb57f3c8f)[i]>=THRESHOLD){z582cdb4021|=(0x785+3038-0x1362)<<i;}if(mxGetPr(zbd40e273de)[i]>=THRESHOLD){z62db3a631c|=((0x131+4885-0x1445)<<i);}}
z2afed1cdc6[(0x2457+3545-0x122f)]=z582cdb4021<<(0x1843+1696-0x1edb);z2afed1cdc6[8194]=z62db3a631c<<(0x49+84-0x95);for(i=(0xca4+3869-0x1bc1);i<(0xba2+4114-0x1ba4);i++){if(mxGetPr(z6d22837c30)[i]>=THRESHOLD){zd7dc6a39d3|=(0x1afb+2854-0x2620)<<i;}if(mxGetPr(z439f9503b2)[i]>=THRESHOLD){z5a0a17ae45|=((0xa10+7190-0x2625)<<i);}}z2afed1cdc6[8195]=zd7dc6a39d3;z2afed1cdc6[8196]=z5a0a17ae45;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE 
uint32_T z78caf1ba61;uint32_T reset,input,z52754d10b7,i;uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*z2afed1cdc6;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x281+8628-0x2435)];z2afed1cdc6=(void*)base;if((uint32_T)mxGetPr(zbcb3e4d083)[(0xb8a+5843-0x225d)]==z912da550ff){input=z2afed1cdc6[(0x20c4+1523-0x6b6)];reset=(0x300+1514-0x8ea);for(i=(0xc18+1071-0x1047);i<(0x1500+1485-0x1aaf);i++){if(mxGetPr(z871352ca17)[i]>THRESHOLD){if(mxGetPr(z6d22837c30)[i]>THRESHOLD){z52754d10b7=(0x6f7+6312-0x1f9e);}else{z52754d10b7=(0xa3d+50-0xa6f);}reset|=z52754d10b7<<i;}else{reset|=input&((0x11e7+4244-0x227a)<<i);}}z2afed1cdc6[8193]=reset;}else if((uint32_T)mxGetPr(zbcb3e4d083)[(0x13af+2238-0x1c6d)]==zfdfce9fcd3){input=z2afed1cdc6[(0x2160+7434-0x1e67)];reset=(0x1ffc+1503-0x25db);for(i=(0xcd+8118-0x2083);i<(0x101+5585-0x16c2);i++){if(mxGetPr(z871352ca17)[i]>THRESHOLD){if(mxGetPr(z6d22837c30)[i]>THRESHOLD){z52754d10b7=(0xea2+1699-0x1544);}else{z52754d10b7=(0x541+1404-0xabd);}reset|=z52754d10b7<<i;}else{reset|=input&((0xcd4+6620-0x26af)<<i);}}z2afed1cdc6[8195]=reset;input=z2afed1cdc6[8193];reset=(0x60c+7113-0x21d5);for(i=(0x1a2d+2252-0x22f9);i<(0xdc5+579-0xff2);i++){if(mxGetPr(zb34d68df21)[i]>THRESHOLD){if(mxGetPr(z1fb57f3c8f)[i]>THRESHOLD){z52754d10b7=(0x354+4404-0x1487);}else{z52754d10b7=(0xe54+156-0xef0);}reset|=z52754d10b7<<i;}else{reset|=input&((0x885+6541-0x2211)<<i);}}z2afed1cdc6[8193]=reset;}
#endif    
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

