/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x3a+3532-0xe04)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_spitxint_sf
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
#define zdf24515981              ((0x26c+8157-0x2245))
#define z533b11d03f               ssGetSFcnParam(S,(0xc91+5807-0x2340))
#define za9d8fb6bcf                 ssGetSFcnParam(S,(0xe7a+365-0xfe6))
#define z3832b85a32               ssGetSFcnParam(S,(0xd63+5972-0x24b5))
#define z702a26a5e9                    ssGetSFcnParam(S,(0x14bb+3186-0x212a))
#define z2e6483d505              ((0xd98+701-0x1053))
#define z7e2eeaa57c          ((0x1cd6+819-0x2009))
#define z6a0da049de         ((0x8aa+4981-0x1c1e))
#define zc5ce4cb81a              ((0xc5d+5802-0x22f7))
#define z2b17e2ee3b              ((0x10a5+4291-0x2168))
static char_T zea4cd01646[(0x117a+4420-0x21be)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}
#ifdef MATLAB_MEX_FILE
#endif
ssSetNumContStates(S,(0x261+6080-0x1a21));ssSetNumDiscStates(S,(0xb93+1240-0x106b));ssSetNumOutputPorts(S,(0x1973+2145-0x21d4));ssSetNumInputPorts(S,(0x1480+1745-0x1b50));ssSetInputPortDataType(S,(0x77d+5701-0x1dc2),SS_BOOLEAN);ssSetInputPortWidth(S,(0x1bb4+2172-0x2430),mxGetN(za9d8fb6bcf));ssSetInputPortDirectFeedThrough(S,(0x6d3+1680-0xd63),(0xe7a+1198-0x1327));ssSetInputPortRequiredContiguous(S,(0x421+549-0x646),(0x1aaf+860-0x1e0a));ssSetNumSampleTimes(S,(0x560+8559-0x26ce));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xe5f+5784-0x24f7));ssSetNumNonsampledZCs(S,(0xbd+1184-0x55d));for(i=(0x17bf+3887-0x26ee);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x805+4157-0x1842));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x1d24+215-0x1dfb)]==-1.0){ssSetSampleTime(S,(0x1285+1864-0x19cd),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1c22+1063-0x2049),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x35c+5745-0x19cd),mxGetPr(z3832b85a32)[(0x94f+2547-0x1342)]);ssSetOffsetTime(S,(0x3f2+382-0x570),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint8_T z16ba527520[(0x41+2669-0xa9a)];uint16_T z6f813cde47,za4a2434e08;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x1644+4051-0x2617)];switch(z78caf1ba61){case(0x14f4+104-0x142f):strcpy(z16ba527520,"\x49\x4f\x33\x30\x31");z6f813cde47=5845;za4a2434e08=17232;break;case(0x408+4516-0x147e):strcpy(z16ba527520,"\x49\x4f\x33\x30\x32");z6f813cde47=5845;za4a2434e08=17239;break;case(0x917+4844-0x1ad4):strcpy(z16ba527520,"\x49\x4f\x33\x30\x33");z6f813cde47=(0x17a5+5758-0x174e);za4a2434e08=16979;break;case(0xd18+3492-0x198c):strcpy(z16ba527520,"\x49\x4f\x33\x30\x34");z6f813cde47=5845;za4a2434e08=(0x1280+3339-0x1a87);break;case(0xc4b+3028-0x16e8):strcpy(z16ba527520,"\x49\x4f\x33\x31\x31");z6f813cde47=(0x17c4+651-0x37a);za4a2434e08=21069;break;case(0x4a0+8864-0x2608):strcpy(z16ba527520,"\x49\x4f\x33\x31\x32");z6f813cde47=(0x1737+6724-0x1aa6);za4a2434e08=16971;break;case(0x467+2344-0xc56):strcpy(z16ba527520,"\x49\x4f\x33\x31\x33");z6f813cde47=5845;za4a2434e08=17235;break;case(0xc72+6815-0x25d7):strcpy(z16ba527520,"\x49\x4f\x33\x31\x34");z6f813cde47=5845;za4a2434e08=8196;break;case(0x1295+5550-0x2702):strcpy(z16ba527520,"\x49\x4f\x33\x32\x31");z6f813cde47=(0x1ae1+8173-0x23f9);za4a2434e08=19520;break;}if((int_T)mxGetPr(z702a26a5e9)[(0x731+2299-0x102c)]<(0x60c+977-0x9dd)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x2205+881-0x2575)){z366b2f03bf=(0xd03+576-0xf43);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x8c6+6670-0x22d4)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x1954+1724-0x2010)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x478+2200-0xd0f)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x410+8991-0x2630))|((z366b2f03bf&(0xc5b+3704-0x19d4))<<(0x3ca+1279-0x8c1)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x1b75+1245-0x2050)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;uint32_T z55b9e90d74,i;boolean_T*z4da0d16710;za42cf7dd4a=(void*)base;
z4da0d16710=(boolean_T*)ssGetInputPortSignal(S,(0x11b2+1452-0x175e));for(i=(0xbad+4201-0x1c16);i<mxGetN(za9d8fb6bcf);i++){z55b9e90d74=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1767+3194-0x23e0);

if(z4da0d16710[i])za42cf7dd4a[10400+z55b9e90d74]=(0x1dc2+1259-0x22ac);else za42cf7dd4a[10400+z55b9e90d74]=(0x1289+3784-0x2151);}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE   
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint32_T z55b9e90d74,i;volatile uint32_T*za42cf7dd4a;za42cf7dd4a=(void*)base;for(i=(0x1a6f+1841-0x21a0);i<mxGetN(za9d8fb6bcf);i++){z55b9e90d74=(uint32_T)mxGetPr(za9d8fb6bcf)[(0x337+1618-0x989)]-(0x1375+2223-0x1c23);za42cf7dd4a[10400+z55b9e90d74]=(0xc63+5770-0x22ed);}
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

