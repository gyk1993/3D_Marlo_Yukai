/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xe4c+1056-0x126a)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_spirdint_sf
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
#define zdf24515981              ((0x9eb+2595-0x140b))
#define z533b11d03f               ssGetSFcnParam(S,(0x506+3043-0x10e9))
#define za9d8fb6bcf                 ssGetSFcnParam(S,(0x1692+3563-0x247c))
#define z702a26a5e9                    ssGetSFcnParam(S,(0x3e6+4787-0x1697))
#define z2e6483d505              ((0x1a87+2008-0x225d))
#define z7e2eeaa57c          ((0x2094+965-0x2459))
#define z6a0da049de         ((0x1009+5467-0x2563))
#define zc5ce4cb81a              ((0x5ba+4356-0x16ae))
#define z2b17e2ee3b              ((0x25da+108-0x2646))
static char_T zea4cd01646[(0x192b+2763-0x22f6)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x1794+3858-0x26a6));ssSetNumDiscStates(S,(0xc01+5786-0x229b));ssSetNumOutputPorts(S,(0xf53+1551-0x1560));ssSetOutputPortWidth(S,(0x1d8d+592-0x1fdd),mxGetN(za9d8fb6bcf));ssSetOutputPortDataType(S,(0x178f+3125-0x23c4),SS_BOOLEAN);ssSetOutputPortWidth(S,(0x1831+943-0x1bdf),mxGetN(za9d8fb6bcf));ssSetOutputPortDataType(S,(0xe60+6304-0x26ff),SS_BOOLEAN);ssSetNumInputPorts(S,(0x17ca+3141-0x240f));ssSetNumSampleTimes(S,(0x363+589-0x5af));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x153+1879-0x8aa));ssSetNumNonsampledZCs(S,(0x8d7+3478-0x166d));for(i=(0xd61+2572-0x176d);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x188+4617-0x1391));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x15f+3616-0xf7f),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1d66+1090-0x21a8),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint8_T z16ba527520[(0x4d+6505-0x19a2)];uint16_T z6f813cde47,za4a2434e08;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x791+2762-0x125b)];switch(z78caf1ba61){case(0x170a+868-0x1941):strcpy(z16ba527520,"\x49\x4f\x33\x30\x31");z6f813cde47=(0x19ab+5-0x2db);za4a2434e08=17232;break;case(0x49d+7466-0x2099):strcpy(z16ba527520,"\x49\x4f\x33\x30\x32");z6f813cde47=(0x172d+3004-0xc14);za4a2434e08=17239;break;case(0x467+3961-0x12b1):strcpy(z16ba527520,"\x49\x4f\x33\x30\x33");z6f813cde47=5845;za4a2434e08=16979;break;case(0x6fa+3684-0x142e):strcpy(z16ba527520,"\x49\x4f\x33\x30\x34");z6f813cde47=5845;za4a2434e08=(0x14c6+5819-0x267d);break;case(0x82d+154-0x790):strcpy(z16ba527520,"\x49\x4f\x33\x31\x31");z6f813cde47=5845;za4a2434e08=21069;break;case(0x38d+8869-0x24fa):strcpy(z16ba527520,"\x49\x4f\x33\x31\x32");z6f813cde47=(0x201b+7496-0x268e);za4a2434e08=16971;break;case(0x17ff+3536-0x2496):strcpy(z16ba527520,"\x49\x4f\x33\x31\x33");z6f813cde47=(0x1cfd+6864-0x20f8);za4a2434e08=17235;break;case(0x1954+3606-0x2630):strcpy(z16ba527520,"\x49\x4f\x33\x31\x34");z6f813cde47=(0x1c95+4183-0x1617);za4a2434e08=8196;break;case(0x15cf+3054-0x207c):strcpy(z16ba527520,"\x49\x4f\x33\x32\x31");z6f813cde47=(0x18fb+8977-0x2537);za4a2434e08=19520;break;}if((int_T)mxGetPr(z702a26a5e9)[(0x2494+409-0x262d)]<(0x18c4+2797-0x23b1)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x57+1576-0x67e)){z366b2f03bf=(0x1543+149-0x15d8);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xfed+1579-0x1618)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x625+4428-0x1771)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x574+4492-0x16ff)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x1584+3796-0x2359))|((z366b2f03bf&(0x1667+215-0x163f))<<(0x1f9+6246-0x1a57)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x1183+1407-0x1700)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;boolean_T*z078e2d77f8;boolean_T*z43f49ea85e;uint8_T z4e3026977c,i;uint32_T z1f3e87fcfc;za42cf7dd4a=(void*)base;z078e2d77f8=(boolean_T*)ssGetOutputPortSignal(S,(0x13ba+1679-0x1a49));z43f49ea85e=(boolean_T*)ssGetOutputPortSignal(S,(0x141f+2597-0x1e43));
z1f3e87fcfc=(uint32_T)za42cf7dd4a[9987];
for(i=(0xf77+5907-0x268a);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=mxGetPr(za9d8fb6bcf)[i]-(0xd86+5026-0x2127);if(z1f3e87fcfc&((0x69f+3372-0x13ca)<<((0xd8c+3974-0x1d10)*z4e3026977c)))z078e2d77f8[i]=(0x1a45+2360-0x237c);else z078e2d77f8[i]=(0x217a+390-0x2300);if(z1f3e87fcfc&((0x2e4+3578-0x10dd)<<((0x4c3+1584-0xaf1)*z4e3026977c+(0x577+476-0x752))))z43f49ea85e[i]=(0xbd+306-0x1ee);else z43f49ea85e[i]=(0x92a+1082-0xd64);}
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

