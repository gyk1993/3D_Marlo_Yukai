/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x6cb+7810-0x254b)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_qadcread_sf
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
#define zdf24515981              ((0x2f+6428-0x1946))
#define z702a26a5e9                    ssGetSFcnParam(S,(0xcb5+2732-0x1761))
#define z3832b85a32               ssGetSFcnParam(S,(0x2191+516-0x2394))
#define za9d8fb6bcf                 ssGetSFcnParam(S,(0x62c+1025-0xa2b))
#define z533b11d03f               ssGetSFcnParam(S,(0x5b0+5522-0x1b3f))
#define z11e8538834                  ssGetSFcnParam(S,(0xd12+1975-0x14c5))
#define z2e6483d505              ((0x5f8+3870-0x1514))
#define z7e2eeaa57c          ((0x11f0+107-0x125b))
#define z6a0da049de         ((0x1748+2484-0x20fb))
#define zc5ce4cb81a              ((0x1050+2439-0x19c7))
#define z2b17e2ee3b              ((0x2026+134-0x20ac))
static char_T zea4cd01646[(0x9d8+2228-0x118c)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x219+5164-0x1645));ssSetNumDiscStates(S,(0x369+5802-0x1a13));switch((int)mxGetPr(z11e8538834)[(0x173+5438-0x16b1)]){case(0x1523+1995-0x1ced):ssSetNumOutputPorts(S,(0x618+6813-0x20b4));break;case(0xea7+4143-0x1ed4):ssSetNumOutputPorts(S,(0x1d81+1456-0x232f));ssSetOutputPortDataType(S,(0x15a5+440-0x175c),SS_BOOLEAN);ssSetOutputPortWidth(S,(0x280+5501-0x17fc),mxGetN(za9d8fb6bcf));break;case(0xf74+364-0x10dd):ssSetNumOutputPorts(S,(0x250+5972-0x19a2));ssSetOutputPortDataType(S,(0x22bc+931-0x265e),SS_BOOLEAN);ssSetOutputPortWidth(S,(0xde4+2113-0x1624),mxGetN(za9d8fb6bcf));break;case(0x8e8+3461-0x1669):ssSetNumOutputPorts(S,(0x3f1+8503-0x2525));ssSetOutputPortDataType(S,(0x2b2+2142-0xb0f),SS_BOOLEAN);ssSetOutputPortWidth(S,(0x1a38+793-0x1d50),mxGetN(za9d8fb6bcf));ssSetOutputPortDataType(S,(0xacb+1511-0x10b0),SS_BOOLEAN);ssSetOutputPortWidth(S,(0x85c+185-0x913),mxGetN(za9d8fb6bcf));break;}ssSetOutputPortDataType(S,(0x289+6026-0x1a13),SS_INT32);ssSetOutputPortWidth(S,(0x518+2204-0xdb4),mxGetN(za9d8fb6bcf));ssSetNumInputPorts(S,(0xa6f+6316-0x231b));ssSetNumSampleTimes(S,(0x20c+9215-0x260a));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1c3a+403-0x1dcd));ssSetNumNonsampledZCs(S,(0xaf7+3767-0x19ae));for(i=(0x1eb4+1028-0x22b8);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1b61+1177-0x1ffa));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x1d9+9116-0x2575)]==-1.0){ssSetSampleTime(S,(0x9e9+5882-0x20e3),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x117b+262-0x1281),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x8a7+230-0x98d),mxGetPr(z3832b85a32)[(0x19a4+1060-0x1dc8)]);ssSetOffsetTime(S,(0x1539+1724-0x1bf5),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z7be9105675,z4e3026977c;real_T scale;uint8_T z16ba527520[(0x17f6+2427-0x215d)];uint16_T z6f813cde47,za4a2434e08;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x15e8+1158-0x1a6e)];switch(z78caf1ba61){case(0x336+3612-0x1025):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");z6f813cde47=(0x1bea+2700-0xfa1);za4a2434e08=17232;break;case(0xc26+3072-0x16f8):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");z6f813cde47=5845;za4a2434e08=17239;break;case(0x1708+2284-0x1ec5):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");z6f813cde47=(0x25dd+749-0x11f5);za4a2434e08=16979;break;case(0x164+8314-0x20ae):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");z6f813cde47=(0x18b5+7873-0x20a1);za4a2434e08=(0x1583+2469-0x1a24);break;case(0x217+97-0x141):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");z6f813cde47=(0x1ff1+5893-0x2021);za4a2434e08=21069;break;case(0xec9+3966-0x1d0f):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");z6f813cde47=5845;za4a2434e08=16971;break;case(0x751+6306-0x1eba):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");z6f813cde47=(0x20f7+2492-0x13de);za4a2434e08=17235;break;case(0x1b3a+763-0x1cfb):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");z6f813cde47=(0x1f5d+6782-0x2306);za4a2434e08=8196;break;case(0xa2f+2877-0x142b):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");z6f813cde47=5845;za4a2434e08=19520;break;}
if((int_T)mxGetPr(z702a26a5e9)[(0x23f+7775-0x209e)]<(0x1bd6+704-0x1e96)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xce0+6237-0x253c)){z366b2f03bf=(0x4ed+8221-0x250a);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x640+6874-0x211a)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x45f+3304-0x1147)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1cdb+1516-0x22c6)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x1938+1141-0x1cae))|((z366b2f03bf&(0x9bc+2767-0x138c))<<(0x1177+2786-0x1c51)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x33a+937-0x6e1)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;uint32_T*za4749e65b3;boolean_T*zf85a1f44ea;uint32_T i,ze938c3d87d,z6ed25a6cde,z4e3026977c;za42cf7dd4a=(void*)base;za4749e65b3=(int32_T*)ssGetOutputPortSignal(S,(0x1e65+1869-0x25b2));if((uint32_T)mxGetPr(z11e8538834)[(0xbb8+2296-0x14b0)]==(0x175+8361-0x221c)||(uint32_T)mxGetPr(z11e8538834)[(0x120c+1216-0x16cc)]==(0x709+6959-0x2234)){ze938c3d87d=(uint32_T)za42cf7dd4a[9889];}if((uint32_T)mxGetPr(z11e8538834)[(0x1f0c+1918-0x268a)]==(0x31+1477-0x5f3)||(uint32_T)mxGetPr(z11e8538834)[(0x1352+3458-0x20d4)]==(0xfe6+1312-0x1502)){z6ed25a6cde=(uint32_T)za42cf7dd4a[9888];}for(i=(0x1abd+859-0x1e18);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x136+6987-0x1c80);
za4749e65b3[i]=(int32_T)za42cf7dd4a[9824+z4e3026977c];
switch((uint32_T)mxGetPr(z11e8538834)[(0x3ec+1582-0xa1a)]){case(0x157d+1010-0x196d):zf85a1f44ea=(boolean_T*)ssGetOutputPortSignal(S,(0x412+8284-0x246d));zf85a1f44ea[i]=(boolean_T)((ze938c3d87d>>z4e3026977c)&(0x8b+1651-0x6fd));break;case(0x1027+2176-0x18a4):zf85a1f44ea=(boolean_T*)ssGetOutputPortSignal(S,(0x7c7+128-0x846));zf85a1f44ea[i]=(boolean_T)((z6ed25a6cde>>z4e3026977c)&(0x191+895-0x50f));break;case(0x162c+480-0x1808):zf85a1f44ea=(boolean_T*)ssGetOutputPortSignal(S,(0x16fa+2764-0x21c5));zf85a1f44ea[i]=(boolean_T)((ze938c3d87d>>z4e3026977c)&(0x5a6+4032-0x1565));zf85a1f44ea=(boolean_T*)ssGetOutputPortSignal(S,(0x650+6655-0x204d));zf85a1f44ea[i]=(boolean_T)((z6ed25a6cde>>z4e3026977c)&(0x463+4881-0x1773));break;}}
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

