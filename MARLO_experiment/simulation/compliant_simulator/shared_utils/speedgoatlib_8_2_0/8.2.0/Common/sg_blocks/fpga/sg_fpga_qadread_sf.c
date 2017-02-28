/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x15c+9079-0x24d1)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_qadread_sf
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
#define zdf24515981              ((0x35c+5541-0x18fd))
#define z702a26a5e9                    ssGetSFcnParam(S,(0x871+5611-0x1e5c))
#define z3832b85a32               ssGetSFcnParam(S,(0x397+591-0x5e5))
#define za9d8fb6bcf                 ssGetSFcnParam(S,(0x1820+75-0x1869))
#define z533b11d03f               ssGetSFcnParam(S,(0x216+2539-0xbfe))
#define z2e6483d505              ((0x3a4+3492-0x1146))
#define z7e2eeaa57c          ((0x8f4+537-0xb0d))
#define z6a0da049de         ((0x1f9+4637-0x1415))
#define zc5ce4cb81a              ((0x1523+1288-0x1a1b))
#define z2b17e2ee3b              ((0x1411+459-0x15dc))
static char_T zea4cd01646[(0x11d8+3889-0x2009)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x62b+4277-0x16e0));ssSetNumDiscStates(S,(0x4a6+5290-0x1950));ssSetNumOutputPorts(S,(0x6ab+2641-0x10fa));ssSetOutputPortDataType(S,(0x149c+1808-0x1bac),SS_INT32);ssSetOutputPortWidth(S,(0x2b1+7309-0x1f3e),mxGetN(za9d8fb6bcf));ssSetOutputPortDataType(S,(0x10f5+4324-0x21d8),SS_BOOLEAN);ssSetOutputPortWidth(S,(0x1913+2618-0x234c),mxGetN(za9d8fb6bcf));ssSetNumInputPorts(S,(0x146a+3330-0x216c));ssSetNumSampleTimes(S,(0xe58+3231-0x1af6));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x26c+1809-0x97d));ssSetNumNonsampledZCs(S,(0x5b3+1229-0xa80));for(i=(0x20f+730-0x4e9);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1d60+508-0x1f5c));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x11bf+2681-0x1c38)]==-1.0){ssSetSampleTime(S,(0x205+1671-0x88c),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1036+3406-0x1d84),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x69a+7216-0x22ca),mxGetPr(z3832b85a32)[(0xb05+402-0xc97)]);ssSetOffsetTime(S,(0x26f+4279-0x1326),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z7be9105675,z4e3026977c;real_T scale;uint8_T z16ba527520[(0x2281+631-0x24e4)];uint16_T z6f813cde47,za4a2434e08;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0xc49+3500-0x19f5)];switch(z78caf1ba61){case(0xda7+1640-0x12e2):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");z6f813cde47=(0x2578+3693-0x1d10);za4a2434e08=17232;break;case(0x222+1181-0x591):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");z6f813cde47=(0x17f0+4451-0x127e);za4a2434e08=17239;break;case(0xf59+1472-0x13ea):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");z6f813cde47=5845;za4a2434e08=16979;break;case(0x7f0+2690-0x1142):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");z6f813cde47=(0x1887+848-0x502);za4a2434e08=(0x18fc+477-0x15d5);break;case(0xc78+173-0xbee):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");z6f813cde47=5845;za4a2434e08=21069;break;case(0x1cc+9358-0x2522):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");z6f813cde47=5845;za4a2434e08=16971;break;case(0x3f7+4086-0x12b4):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");z6f813cde47=(0x179d+3078-0xcce);za4a2434e08=17235;break;case(0x178+3745-0xedf):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");z6f813cde47=(0x2217+4670-0x1d80);za4a2434e08=8196;break;case(0x62d+8065-0x246d):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");z6f813cde47=5845;za4a2434e08=19520;break;}
if((int_T)mxGetPr(z702a26a5e9)[(0x334+504-0x52c)]<(0x119a+5009-0x252b)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xdb2+4315-0x1e8c)){z366b2f03bf=(0x3f9+1996-0xbc5);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1014+3108-0x1c38)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x1985+2932-0x24f9)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1d01+1725-0x23bd)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0xf9c+3038-0x1a7b))|((z366b2f03bf&(0x1038+4919-0x2270))<<(0x14c9+1527-0x1ab8)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x3e5+8870-0x2689)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;uint32_T*za4749e65b3;boolean_T*zf85a1f44ea;uint32_T i,ze938c3d87d,z4e3026977c;za42cf7dd4a=(void*)base;za4749e65b3=(int32_T*)ssGetOutputPortSignal(S,(0x637+6369-0x1f18));zf85a1f44ea=(boolean_T*)ssGetOutputPortSignal(S,(0x61b+4438-0x1770));ze938c3d87d=(uint32_T)za42cf7dd4a[9889];for(i=(0x17e4+1310-0x1d02);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1366+2641-0x1db6);za4749e65b3[i]=(int32_T)za42cf7dd4a[9824+z4e3026977c];zf85a1f44ea[i]=(boolean_T)((ze938c3d87d>>z4e3026977c)&(0x554+5208-0x19ab));}
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

