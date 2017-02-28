/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1a8b+2155-0x22f4)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_spis_sf
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
#define zdf24515981              ((0x705+2776-0x11d7))
#define z533b11d03f               ssGetSFcnParam(S, (0x52+5454-0x15a0))
#define za9d8fb6bcf                 ssGetSFcnParam(S, (0xa04+636-0xc7f))
#define z86af52d74e                    ssGetSFcnParam(S, (0xc22+2370-0x1562))
#define z31fb671cb8                    ssGetSFcnParam(S, (0x339+8092-0x22d2))
#define zea4d7ef473                ssGetSFcnParam(S, (0x1216+2089-0x1a3b))
#define z702a26a5e9                    ssGetSFcnParam(S, (0x1156+4683-0x239c))
#define z2e6483d505              ((0xc07+147-0xc98))
#define z7e2eeaa57c          ((0x8b9+719-0xb88))
#define z6a0da049de         ((0xc88+5877-0x237c))
#define zc5ce4cb81a              ((0x10dc+3054-0x1cba))
#define z2b17e2ee3b              ((0x1386+364-0x14f2))
static char_T zea4cd01646[(0x12fc+2172-0x1a78)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xa75+3892-0x19a9));ssSetNumDiscStates(S,(0x44c+7474-0x217e));ssSetNumOutputPorts(S,(0x1031+5263-0x24c0));ssSetNumInputPorts(S,(0x1308+4182-0x235e));ssSetNumSampleTimes(S,(0x7ed+1636-0xe50));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x514+2363-0xe4f));ssSetNumNonsampledZCs(S,(0x19a2+2612-0x23d6));for(i=(0xbbf+2553-0x15b8);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x10b4+3763-0x1f67));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x183b+3377-0x256c),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xeb6+4115-0x1ec9),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint8_T z16ba527520[(0x688+6953-0x219d)];uint16_T z6f813cde47,za4a2434e08;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x1f8d+26-0x1fa7)];switch(z78caf1ba61){case(0x2489+59-0x2397):strcpy(z16ba527520,"\x49\x4f\x33\x30\x31");z6f813cde47=(0x1bbc+6106-0x1cc1);za4a2434e08=17232;break;case(0x1fc8+469-0x206f):strcpy(z16ba527520,"\x49\x4f\x33\x30\x32");z6f813cde47=(0x1876+896-0x521);za4a2434e08=17239;break;case(0x1e2+1292-0x5bf):strcpy(z16ba527520,"\x49\x4f\x33\x30\x33");z6f813cde47=5845;za4a2434e08=16979;break;case(0xc70+4776-0x1de8):strcpy(z16ba527520,"\x49\x4f\x33\x30\x34");z6f813cde47=(0x19d9+2857-0xe2d);za4a2434e08=(0x5f1+6756-0x1b51);break;case(0xc1c+4856-0x1ddd):strcpy(z16ba527520,"\x49\x4f\x33\x31\x31");z6f813cde47=(0x16dc+6128-0x17f7);za4a2434e08=21069;break;case(0x128c+4254-0x21f2):strcpy(z16ba527520,"\x49\x4f\x33\x31\x32");z6f813cde47=(0x23d8+207-0xdd2);za4a2434e08=16971;break;case(0xbf8+6795-0x254a):strcpy(z16ba527520,"\x49\x4f\x33\x31\x33");z6f813cde47=(0x1b74+7117-0x206c);za4a2434e08=17235;break;case(0x139b+2791-0x1d48):strcpy(z16ba527520,"\x49\x4f\x33\x31\x34");z6f813cde47=5845;za4a2434e08=8196;break;case(0x5f7+3567-0x12a5):strcpy(z16ba527520,"\x49\x4f\x33\x32\x31");z6f813cde47=(0x1b0f+3964-0x13b6);za4a2434e08=19520;break;}if((int_T)mxGetPr(z702a26a5e9)[(0x1cc5+1238-0x219b)]<(0x654+581-0x899)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x32d+6295-0x1bc3)){z366b2f03bf=(0x10d7+1032-0x14df);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x199f+1706-0x2049)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0xb90+4228-0x1c14)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xa18+6456-0x234f)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0xbf7+2895-0x1647))|((z366b2f03bf&(0xaa9+1489-0xf7b))<<(0xde5+4292-0x1ea1)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x9b1+5614-0x1f9d)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE       
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE   
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T i;volatile uint32_T*za42cf7dd4a;uint32_T z4e3026977c,z1209c02d78,zdc0d676974,zbea4a89f24,z9e58a4ec45;za42cf7dd4a=(void*)base;z1209c02d78=(uint32_T)za42cf7dd4a[10240];zdc0d676974=(uint32_T)za42cf7dd4a[10241];zbea4a89f24=(uint32_T)za42cf7dd4a[10248];z9e58a4ec45=(uint32_T)za42cf7dd4a[10242];for(i=(0x1c74+251-0x1d6f);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x29a+1169-0x72a);z1209c02d78|=((0x713+2378-0x105c)<<z4e3026977c);zdc0d676974|=(((uint32_T)mxGetPr(z86af52d74e)[i])<<z4e3026977c);zbea4a89f24|=(((uint32_T)mxGetPr(z31fb671cb8)[i])<<z4e3026977c);z9e58a4ec45|=(((uint32_T)mxGetPr(zea4d7ef473)[i])<<z4e3026977c);}za42cf7dd4a[10497]=zdc0d676974;
za42cf7dd4a[10498]=z9e58a4ec45;
za42cf7dd4a[10504]=zbea4a89f24;

za42cf7dd4a[10496]=z1209c02d78;
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

