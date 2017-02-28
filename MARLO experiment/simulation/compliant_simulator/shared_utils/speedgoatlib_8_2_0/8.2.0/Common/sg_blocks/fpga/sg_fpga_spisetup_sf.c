/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x52f+2049-0xd2e)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_spisetup_sf
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
#define zdf24515981              ((0x845+4968-0x1ba7))
#define z533b11d03f               ssGetSFcnParam(S, (0x5b5+204-0x681))
#define za9d8fb6bcf                 ssGetSFcnParam(S, (0x958+4656-0x1b87))
#define z7039def18e              ssGetSFcnParam(S, (0xbcd+1991-0x1392))
#define z86af52d74e                    ssGetSFcnParam(S, (0x146d+3896-0x23a2))
#define zea4d7ef473                ssGetSFcnParam(S, (0xca9+3167-0x1904))
#define z702a26a5e9                    ssGetSFcnParam(S, (0xce6+3292-0x19bd))
#define z2e6483d505              ((0xd2d+2217-0x15d4))
#define z7e2eeaa57c          ((0x310+7023-0x1e7f))
#define z6a0da049de         ((0x236a+318-0x24a7))
#define zc5ce4cb81a              ((0x1a66+822-0x1d8c))
#define z2b17e2ee3b              ((0x25c1+12-0x25cd))
static char_T zea4cd01646[(0x174+7724-0x1ea0)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xb55+1014-0xf4b));ssSetNumDiscStates(S,(0x729+1175-0xbc0));ssSetNumOutputPorts(S,(0x75f+3378-0x1491));ssSetNumInputPorts(S,(0x91+8394-0x215b));ssSetNumSampleTimes(S,(0xd27+1644-0x1392));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x205+1292-0x711));ssSetNumNonsampledZCs(S,(0xe02+4302-0x1ed0));for(i=(0x1826+1312-0x1d46);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x23c+7928-0x2134));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0xe3c+1560-0x1454),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1c2+3371-0xeed),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint8_T z16ba527520[(0x8aa+5342-0x1d74)];uint16_T z6f813cde47,za4a2434e08;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x29a+7038-0x1e18)];switch(z78caf1ba61){case(0x283+3533-0xf23):strcpy(z16ba527520,"\x49\x4f\x33\x30\x31");z6f813cde47=5845;za4a2434e08=17232;break;case(0x149c+354-0x14d0):strcpy(z16ba527520,"\x49\x4f\x33\x30\x32");z6f813cde47=5845;za4a2434e08=17239;break;case(0x1d94+1496-0x223d):strcpy(z16ba527520,"\x49\x4f\x33\x30\x33");z6f813cde47=5845;za4a2434e08=16979;break;case(0x13b8+198-0x134e):strcpy(z16ba527520,"\x49\x4f\x33\x30\x34");z6f813cde47=(0x1752+156-0x119);za4a2434e08=(0x146b+2552-0x195f);break;case(0xa0d+3165-0x1533):strcpy(z16ba527520,"\x49\x4f\x33\x31\x31");z6f813cde47=5845;za4a2434e08=21069;break;case(0x1f77+1602-0x2481):strcpy(z16ba527520,"\x49\x4f\x33\x31\x32");z6f813cde47=(0x2606+2660-0x1995);za4a2434e08=16971;break;case(0x1f92+1942-0x25ef):strcpy(z16ba527520,"\x49\x4f\x33\x31\x33");z6f813cde47=(0x1a0f+2707-0xdcd);za4a2434e08=17235;break;case(0x1213+4241-0x216a):strcpy(z16ba527520,"\x49\x4f\x33\x31\x34");z6f813cde47=(0x248f+388-0xf3e);za4a2434e08=8196;break;case(0x1756+3186-0x2287):strcpy(z16ba527520,"\x49\x4f\x33\x32\x31");z6f813cde47=(0x1c0c+8294-0x259d);za4a2434e08=19520;break;}if((int_T)mxGetPr(z702a26a5e9)[(0x78+2595-0xa9b)]<(0x69c+6610-0x206e)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x20e5+1316-0x2608)){z366b2f03bf=(0x113a+3178-0x1da4);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1e6+4138-0x1210)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x1033+3498-0x1ddd)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x8f8+1590-0xf2d)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x12e6+247-0x12de))|((z366b2f03bf&(0x17c0+517-0x18c6))<<(0xc6a+2735-0x1711)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x17ec+1853-0x1f27)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE            
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE   
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T i;volatile uint32_T*za42cf7dd4a;uint32_T z4e3026977c,z1209c02d78,zdc0d676974,z9e58a4ec45;za42cf7dd4a=(void*)base;z1209c02d78=(uint32_T)za42cf7dd4a[10240];zdc0d676974=(uint32_T)za42cf7dd4a[10241];z9e58a4ec45=(uint32_T)za42cf7dd4a[10242];for(i=(0xcc9+5162-0x20f3);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x19cc+776-0x1cd3);za42cf7dd4a[10288+z4e3026977c]=(uint32_T)mxGetPr(z7039def18e)[i];z1209c02d78|=((0x2d8+2519-0xcae)<<z4e3026977c);zdc0d676974|=(((uint32_T)mxGetPr(z86af52d74e)[i])<<z4e3026977c);z9e58a4ec45|=(((uint32_T)mxGetPr(zea4d7ef473)[i])<<z4e3026977c);}za42cf7dd4a[10241]=zdc0d676974;za42cf7dd4a[10242]=z9e58a4ec45;
za42cf7dd4a[10240]=z1209c02d78;
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

