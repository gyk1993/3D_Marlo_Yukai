/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x50d+330-0x655)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO113_da_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x31\x33"
#define z694756a014 (0x1d3d+4137-0x1cb1)
#define zea87e0ba83 36950
#define z29146a1837 4277
#define zab7e64468b 13143
#define zdf24515981          ((0x6cd+2917-0x122d))
#define z2b4281b393               ssGetSFcnParam(S,(0x4fc+1984-0xcbc))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0x214d+237-0x2239))
#define z8fd86139be               ssGetSFcnParam(S,(0x171d+3562-0x2505))
#define z3832b85a32           ssGetSFcnParam(S,(0x1be8+101-0x1c4a))
#define z702a26a5e9                ssGetSFcnParam(S,(0xd5c+5421-0x2285))
#define z2e6483d505              ((0x7a9+6389-0x209c))
#define z7e2eeaa57c          ((0x512+6678-0x1f28))
#define z6a0da049de         ((0xc98+5306-0x2151))
#define zc5ce4cb81a              ((0xed9+2629-0x191c))
#define z8caad2a8e6              ((0x78b+276-0x89f))
#define z5bfe7a2613            ((0x95a+2267-0x1234))
#define z2b17e2ee3b              ((0x1092+5088-0x2472))
#define z7935114df5          (262143) 
static char_T zea4cd01646[(0xb8c+1039-0xe9b)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xb0d+6200-0x2345));ssSetNumDiscStates(S,(0xaa0+540-0xcbc));ssSetNumOutputPorts(S,(0x9d3+1260-0xebf));ssSetNumInputPorts(S,(int)mxGetN(za9d8fb6bcf));for(i=(0x167+4524-0x1313);i<(int)mxGetN(za9d8fb6bcf);i++){ssSetInputPortWidth(S,i,(0x577+2433-0xef7));ssSetInputPortDirectFeedThrough(S,i,(0x1aea+1984-0x22a9));ssSetInputPortRequiredContiguous(S,i,(0x4e6+6643-0x1ed8));}ssSetNumSampleTimes(S,(0x98b+6499-0x22ed));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xa96+3480-0x182e));ssSetNumNonsampledZCs(S,(0xa4d+1263-0xf3c));for(i=(0x1704+3613-0x2521);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1c2+7522-0x1f24));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x11cb+5000-0x2553)]==-1.0){ssSetSampleTime(S,(0x24d+1230-0x71b),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x40b+7988-0x233f),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x2130+1401-0x26a9),mxGetPr(z3832b85a32)[(0xa48+3887-0x1977)]);ssSetOffsetTime(S,(0x1771+840-0x1ab9),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;uint16_T zf91d71c6d9=(int)mxGetN(za9d8fb6bcf);real_T z19c4ca5f82,start;uint32_T range;if((int_T)mxGetPr(z702a26a5e9)[(0x1a8d+1466-0x2047)]<(0xf59+2020-0x173d)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xc12+6705-0x2642)){z366b2f03bf=(0x4c+9342-0x24ca);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xab3+4205-0x1b20)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x87f+4729-0x1af8)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x16bf+2392-0x2016)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0xf58+247-0xf50))|((z366b2f03bf&(0x654+5475-0x1ab8))<<(0x1456+1603-0x1a91)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0xae6+2898-0x1636)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0xd06+681-0xf8f),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,z7e2eeaa57c,zf91d71c6d9);switch((uint16_T)mxGetPr(z8fd86139be)[(0x19c+7116-0x1d68)]){case(0x1323+4560-0x24f2):ssSetRWorkValue(S,z8caad2a8e6,13107.2);
ssSetRWorkValue(S,z5bfe7a2613,10.0);range=(0x8f1+7430-0x25f5);break;case(0x20a3+303-0x21d0):ssSetRWorkValue(S,z8caad2a8e6,26214.4);
ssSetRWorkValue(S,z5bfe7a2613,5.0);range=(0x1225+2468-0x1bc8);break;case(0x849+3259-0x1501):ssSetRWorkValue(S,z8caad2a8e6,52428.8);
ssSetRWorkValue(S,z5bfe7a2613,2.5);range=(0xcf3+2436-0x1677);break;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T zf91d71c6d9=ssGetIWorkValue(S,z7e2eeaa57c);real_T z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6);real_T offset=ssGetRWorkValue(S,z5bfe7a2613);uint16_T i;volatile uint32_T*za42cf7dd4a;real_T*zc7fdaf6331;int32_T out;uint16_T z4e3026977c,index;real_T zd3add15c40,zbd0243c03e;uint16_T first=(0xa8b+1798-0x1190);za42cf7dd4a=(void*)base;
for(i=(0x7d1+3698-0x1643);i<zf91d71c6d9;i++){index=(uint16_T)mxGetPr(z2b4281b393)[i]-(0x1a93+1284-0x1f96);z4e3026977c=(uint16_T)mxGetPr(za9d8fb6bcf)[i]-(0xd53+3538-0x1b24);zc7fdaf6331=(real_T*)ssGetInputPortRealSignal(S,index);out=(int32_T)((zc7fdaf6331[(0x558+4955-0x18b3)]+offset)*z0754dd67cc);if(out>z7935114df5){out=z7935114df5;}else if(out<(0x1ea3+1851-0x25de)){out=(0x21a8+1312-0x26c8);}za42cf7dd4a[(0x146a+3906-0x239a)]=out;
}
za42cf7dd4a[(0x7a9+2205-0x100a)/(0xfca+5376-0x24c6)]=(((0x2076+1617-0x26c6)<<(0x70+4948-0x13bd))|((0x29+5436-0x1564)<<(0x11b7+3716-0x2036)));
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

