/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xea6+766-0x11a2)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_cap_sf
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
#define zdf24515981              ((0x5b0+6056-0x1d51))
#define z533b11d03f               ssGetSFcnParam(S,(0x258+20-0x26c))
#define za9d8fb6bcf                 ssGetSFcnParam(S,(0x65d+6524-0x1fd8))
#define z2cbaca9fde                   ssGetSFcnParam(S,(0x7bc+4092-0x17b6))
#define za532a604a6                    ssGetSFcnParam(S,(0x3ad+1242-0x884))
#define za9b36fc92d                  ssGetSFcnParam(S,(0xff5+2942-0x1b6f))
#define z3832b85a32               ssGetSFcnParam(S,(0x2b7+1217-0x773))
#define z702a26a5e9                    ssGetSFcnParam(S,(0x12a+7211-0x1d4f))
#define z2e6483d505              ((0x562+4854-0x1856))
#define z7e2eeaa57c          ((0xa46+1807-0x1155))
#define z6a0da049de         ((0x913+3905-0x1853))
#define zc5ce4cb81a              ((0xc7b+5303-0x2122))
#define z2b17e2ee3b              ((0x10f2+2766-0x1bc0))
static char_T zea4cd01646[(0xbf0+1013-0xee5)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x1714+315-0x184f));ssSetNumDiscStates(S,(0x12c+4153-0x1165));ssSetNumOutputPorts(S,(0x776+57-0x7ae));ssSetOutputPortDataType(S,(0x7b5+2622-0x11f3),SS_UINT32);ssSetOutputPortWidth(S,(0x111c+5201-0x256d),mxGetN(za9d8fb6bcf));ssSetNumInputPorts(S,(0x615+5404-0x1b31));ssSetNumSampleTimes(S,(0x1fd0+1833-0x26f8));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x90b+5546-0x1eb5));ssSetNumNonsampledZCs(S,(0x133c+4880-0x264c));for(i=(0x666+3890-0x1598);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x145+5689-0x177e));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x5cf+6879-0x20ae)]==-1.0){ssSetSampleTime(S,(0x130b+3125-0x1f40),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1f4f+1125-0x23b4),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xb65+5060-0x1f29),mxGetPr(z3832b85a32)[(0x1305+5098-0x26ef)]);ssSetOffsetTime(S,(0xfc+2758-0xbc2),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z7be9105675,z4e3026977c;real_T scale;uint8_T z16ba527520[(0x128+7120-0x1ce4)];uint16_T z6f813cde47,za4a2434e08;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x5e2+638-0x860)];switch(z78caf1ba61){case(0x848+1220-0xbdf):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");z6f813cde47=5845;za4a2434e08=17232;break;case(0x13ca+3233-0x1f3d):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");z6f813cde47=(0x1cb6+8309-0x2656);za4a2434e08=17239;break;case(0x56b+484-0x620):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");z6f813cde47=5845;za4a2434e08=16979;break;case(0xed1+2125-0x15ee):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");z6f813cde47=5845;za4a2434e08=(0x132b+217-0xf00);break;case(0x1cfa+2817-0x26c4):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");z6f813cde47=5845;za4a2434e08=21069;break;case(0x553+866-0x77d):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");z6f813cde47=5845;za4a2434e08=16971;break;case(0x217c+460-0x220f):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");z6f813cde47=5845;za4a2434e08=17235;break;case(0x3e7+2960-0xe3d):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");z6f813cde47=5845;za4a2434e08=(0x206a+8417-0x2147);break;case(0xa8f+1355-0xe99):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");z6f813cde47=5845;za4a2434e08=19520;break;}if((int_T)mxGetPr(z702a26a5e9)[(0x1b8+3289-0xe91)]<(0xe15+2149-0x167a)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xcca+2520-0x16a1)){z366b2f03bf=(0x13ed+2150-0x1c53);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x9ef+1001-0xdd8)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x18a6+2276-0x218a)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1826+2233-0x20de)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x9b9+6836-0x236e))|((z366b2f03bf&(0x3e1+5325-0x17af))<<(0x4d4+6891-0x1fb7)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x1388+3954-0x22f8)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T i;volatile uint32_T*za42cf7dd4a;uint32_T*z8184bef3ae;uint32_T z4e3026977c;za42cf7dd4a=(void*)base;
z8184bef3ae=(uint32_T*)ssGetOutputPortSignal(S,(0xf8a+3618-0x1dac));for(i=(0x18da+1809-0x1feb);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x9da+327-0xb20);z8184bef3ae[i]=(uint32_T)za42cf7dd4a[9472+z4e3026977c];}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T i;volatile uint32_T*za42cf7dd4a;uint16_T z4e3026977c;uint32_T z7be9105675;za42cf7dd4a=(void*)base;
z7be9105675=za42cf7dd4a[9536];for(i=(0x16ac+220-0x1788);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xec1+2312-0x17c8);if((uint32_T)mxGetPr(z2cbaca9fde)[i]>0.5){z7be9105675|=((0x21f2+1273-0x26ea)<<z4e3026977c);}else{z7be9105675&=~((0xce8+4587-0x1ed2)<<z4e3026977c);}}za42cf7dd4a[9536]=z7be9105675;

z7be9105675=za42cf7dd4a[9537];for(i=(0x1925+651-0x1bb0);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xa45+6463-0x2383);if((uint32_T)mxGetPr(za532a604a6)[i]>0.5){z7be9105675|=((0x111c+1968-0x18cb)<<z4e3026977c);}else{z7be9105675&=~((0x1a0b+1660-0x2086)<<z4e3026977c);}}za42cf7dd4a[9537]=z7be9105675;

for(i=(0x1a12+697-0x1ccb);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xa10+2952-0x1597);za42cf7dd4a[9504+z4e3026977c]=(uint32_T)mxGetPr(za9b36fc92d)[i];}
za42cf7dd4a[9538]=4294967295;
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

