/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xd77+4725-0x1fea)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_spissend_sf
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
#define zdf24515981              ((0x1d54+1032-0x2157))
#define z533b11d03f               ssGetSFcnParam(S, (0x1103+1356-0x164f))
#define za9d8fb6bcf                 ssGetSFcnParam(S, (0x55c+2446-0xee9))
#define z3d4ad966bd                   ssGetSFcnParam(S, (0x5ac+5931-0x1cd5))
#define z3832b85a32               ssGetSFcnParam(S, (0x6ad+5824-0x1d6a))
#define z702a26a5e9                    ssGetSFcnParam(S, (0xab3+2355-0x13e2))
#define z2e6483d505              ((0xc10+1758-0x12ec))
#define z7e2eeaa57c          ((0x222+8380-0x22de))
#define z6a0da049de         ((0x509+3256-0x11c0))
#define zc5ce4cb81a              ((0x685+5996-0x1de1))
#define z2b17e2ee3b              ((0x16b0+966-0x1a76))
static char_T zea4cd01646[(0x14c+3050-0xc36)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x403+1215-0x8c2));ssSetNumDiscStates(S,(0xab9+250-0xbb3));ssSetNumOutputPorts(S,(0x5a2+5392-0x1ab2));ssSetNumInputPorts(S,mxGetN(za9d8fb6bcf));for(i=(0x529+1269-0xa1e);i<mxGetN(za9d8fb6bcf);i++){ssSetInputPortWidth(S,i,(uint32_T)mxGetPr(z3d4ad966bd)[(0xfdb+2571-0x19e6)]+(0x1339+109-0x13a5));ssSetInputPortDirectFeedThrough(S,i,(0x16bc+1124-0x1b1f));ssSetInputPortRequiredContiguous(S,i,(0x158b+2022-0x1d70));}ssSetNumSampleTimes(S,(0x928+2127-0x1176));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x8a9+4306-0x197b));ssSetNumNonsampledZCs(S,(0x1332+2824-0x1e3a));for(i=(0x301+8638-0x24bf);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x175a+2599-0x2181));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0xc5c+364-0xdc8)]==-1.0){ssSetSampleTime(S,(0x1bf9+626-0x1e6b),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xae1+6478-0x242f),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x3fd+2414-0xd6b),mxGetPr(z3832b85a32)[(0x10f9+4192-0x2159)]);ssSetOffsetTime(S,(0x166c+298-0x1796),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint8_T z16ba527520[(0x1fa+7228-0x1e22)];uint16_T z6f813cde47,za4a2434e08;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x14b9+3494-0x225f)];switch(z78caf1ba61){case(0x3ba+6731-0x1cd8):strcpy(z16ba527520,"\x49\x4f\x33\x30\x31");z6f813cde47=(0x2008+985-0xd0c);za4a2434e08=17232;break;case(0x7b8+4537-0x1843):strcpy(z16ba527520,"\x49\x4f\x33\x30\x32");z6f813cde47=5845;za4a2434e08=17239;break;case(0x16c8+3164-0x21f5):strcpy(z16ba527520,"\x49\x4f\x33\x30\x33");z6f813cde47=(0x21ec+5532-0x20b3);za4a2434e08=16979;break;case(0x10ea+4687-0x2209):strcpy(z16ba527520,"\x49\x4f\x33\x30\x34");z6f813cde47=(0x18c6+9001-0x251a);za4a2434e08=(0x549+5264-0x14d5);break;case(0x885+3380-0x1482):strcpy(z16ba527520,"\x49\x4f\x33\x31\x31");z6f813cde47=(0x23d5+2418-0x1672);za4a2434e08=21069;break;case(0x4c4+7677-0x2189):strcpy(z16ba527520,"\x49\x4f\x33\x31\x32");z6f813cde47=5845;za4a2434e08=16971;break;case(0x33d+1060-0x628):strcpy(z16ba527520,"\x49\x4f\x33\x31\x33");z6f813cde47=(0x1c30+1971-0xd0e);za4a2434e08=17235;break;case(0x182c+1016-0x1aea):strcpy(z16ba527520,"\x49\x4f\x33\x31\x34");z6f813cde47=5845;za4a2434e08=8196;break;case(0xc77+835-0xe79):strcpy(z16ba527520,"\x49\x4f\x33\x32\x31");z6f813cde47=5845;za4a2434e08=19520;break;}if((int_T)mxGetPr(z702a26a5e9)[(0xfd4+2109-0x1811)]<(0x918+2102-0x114e)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xba0+5719-0x21f6)){z366b2f03bf=(0x5ed+7701-0x2402);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x10b9+5283-0x255c)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x944+388-0xac8)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x19d3+1798-0x20d8)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x4ca+6968-0x1f03))|((z366b2f03bf&(0x652+3735-0x13ea))<<(0x786+6683-0x2199)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x2bf+6910-0x1dbb)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE     
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;uint32_T z26dbd73a5e,i,width,count;real_T*in;uint32_T z4e3026977c;width=(uint32_T)mxGetPr(z3d4ad966bd)[(0x8e7+6128-0x20d7)]+(0x134c+42-0x1375);za42cf7dd4a=(void*)base;for(i=(0xa6+7603-0x1e59);i<mxGetN(za9d8fb6bcf);i++)
{z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1c0b+1917-0x2387);in=(real_T*)ssGetInputPortSignal(S,z4e3026977c);count=(uint32_T)in[(0xae6+633-0xd5f)];for(z26dbd73a5e=(0x4bf+8035-0x2422);z26dbd73a5e<count;z26dbd73a5e++)
{
za42cf7dd4a[10512+z4e3026977c]=(uint32_T)in[z26dbd73a5e+(0x13d2+642-0x1653)];
za42cf7dd4a[10544+z4e3026977c]=z26dbd73a5e;
za42cf7dd4a[10505]=((0x3a8+162-0x449)<<z4e3026977c);za42cf7dd4a[10505]=(0xd75+1739-0x1440);}}
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

