/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x671+3996-0x160b)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO103_da_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x30\x33"
#define z694756a014 (0x1c8f+781-0xee7)
#define zea87e0ba83 36992
#define z29146a1837 (0x2253+2917-0x1d03)
#define zab7e64468b 10361
#define zdf24515981          ((0x1791+2933-0x2302))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0x7b1+3472-0x1541))
#define z8fd86139be               ssGetSFcnParam(S,(0x20d0+429-0x227c))
#define z3832b85a32           ssGetSFcnParam(S,(0x800+2310-0x1104))
#define z702a26a5e9                ssGetSFcnParam(S,(0x6a4+8107-0x264c))
#define z2e6483d505              ((0x4f1+4784-0x179f))
#define z7e2eeaa57c          ((0xc37+6590-0x25f5))
#define z6a0da049de         ((0x21eb+480-0x23ca))
#define zc5ce4cb81a              ((0xba3+6343-0x2468))
#define z8caad2a8e6              ((0x108f+3488-0x1e2f))
#define z5bfe7a2613            ((0x1c56+2284-0x2541))
#define z2b17e2ee3b              ((0x4b5+1391-0xa24))
static char_T zea4cd01646[(0x1283+482-0x1365)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x2f1+3924-0x1245));ssSetNumDiscStates(S,(0x16c4+3046-0x22aa));ssSetNumOutputPorts(S,(0x9f6+2829-0x1503));ssSetNumInputPorts(S,(int)mxGetN(za9d8fb6bcf));for(i=(0x1427+2281-0x1d10);i<(int)mxGetN(za9d8fb6bcf);i++){ssSetInputPortWidth(S,i,(0x1c00+677-0x1ea4));ssSetInputPortDirectFeedThrough(S,i,(0x376+4862-0x1673));ssSetInputPortRequiredContiguous(S,i,(0x966+3869-0x1882));}ssSetNumSampleTimes(S,(0x5f6+6483-0x1f48));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1f67+141-0x1ff4));ssSetNumNonsampledZCs(S,(0x1b5+7095-0x1d6c));for(i=(0x17b7+2070-0x1fcd);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x949+418-0xaeb));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0xeb8+610-0x111a)]==-1.0){ssSetSampleTime(S,(0x3fc+5309-0x18b9),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1227+3030-0x1dfd),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x341+6856-0x1e09),mxGetPr(z3832b85a32)[(0x868+1814-0xf7e)]);ssSetOffsetTime(S,(0xaec+6089-0x22b5),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;uint16_T zf91d71c6d9=(int)mxGetN(za9d8fb6bcf);real_T z19c4ca5f82,start;uint32_T range;if((int_T)mxGetPr(z702a26a5e9)[(0x11c7+5225-0x2630)]<(0x9df+5825-0x20a0)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x10e0+2334-0x19fd)){z366b2f03bf=(0x566+7541-0x22db);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xb93+77-0xbe0)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x5ba+6800-0x204a)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1180+366-0x12ed)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x1bf5+1906-0x2268))|((z366b2f03bf&(0x969+2189-0x10f7))<<(0x2161+795-0x2474)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0xe28+3246-0x1ad4)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x1156+969-0x14df),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,z7e2eeaa57c,zf91d71c6d9);switch((uint16_T)mxGetPr(z8fd86139be)[(0x132a+4057-0x2303)]){case(0x310+1738-0x9d9):ssSetRWorkValue(S,z8caad2a8e6,3276.8);ssSetRWorkValue(S,z5bfe7a2613,10.0);range=(0x1a2+4953-0x14f9);break;case(0xc06+981-0xfd9):ssSetRWorkValue(S,z8caad2a8e6,6553.6);ssSetRWorkValue(S,z5bfe7a2613,5.0);range=(0x867+3842-0x1768);break;case(0x598+3829-0x148a):ssSetRWorkValue(S,z8caad2a8e6,13107.2);ssSetRWorkValue(S,z5bfe7a2613,2.5);range=(0x3f+5196-0x148b);break;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T zf91d71c6d9=ssGetIWorkValue(S,z7e2eeaa57c);real_T z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6);real_T offset=ssGetRWorkValue(S,z5bfe7a2613);uint16_T i;volatile uint32_T*za42cf7dd4a;real_T*zc7fdaf6331;int32_T out;uint16_T z4e3026977c;real_T zd3add15c40,zbd0243c03e;uint16_T first=(0x1192+2847-0x1cb0);real_T scale=3276.8;za42cf7dd4a=(void*)base;for(i=(0x8c3+1755-0xf9e);i<zf91d71c6d9;i++){if(first){first=(0xd3f+5524-0x22d3);}else{za42cf7dd4a[(0xbd8+1999-0x13a1)]=out|(z4e3026977c<<(0xf33+2424-0x189b));}z4e3026977c=(uint16_T)mxGetPr(za9d8fb6bcf)[i]-(0x8fc+235-0x9e6);zc7fdaf6331=(real_T*)ssGetInputPortRealSignal(S,i);out=(int32_T)((zc7fdaf6331[(0xd68+3136-0x19a8)]+offset)*z0754dd67cc);if(out>65535)out=65535;if(out<(0x226+4086-0x121c))out=(0x39+7486-0x1d77);}za42cf7dd4a[(0x114+3340-0xe1a)]=out|(z4e3026977c<<(0x605+7934-0x24f3))|1572864;za42cf7dd4a[(0x56a+8342-0x2600)]=za42cf7dd4a[(0x3e7+7859-0x229a)]|(0x1075+6684-0x2291);
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

