/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1514+2959-0x20a1)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO110_da_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x31\x30"
#define z694756a014 (0x15fa+2023-0x949)
#define zea87e0ba83 (0x14d7+155-0x1349)
#define z29146a1837 (0x1c94+9-0x805)
#define zab7e64468b (0x138a+2391-0x1cd7)
#define zdf24515981          ((0x5ef+3643-0x1426))
#define z702a26a5e9                ssGetSFcnParam(S,(0x4e4+257-0x5e5))
#define z1f7e7173d9          ssGetSFcnParam(S,(0x877+6850-0x2338))
#define zc6f930323f            ssGetSFcnParam(S,(0x1f5a+1195-0x2403))
#define z3832b85a32           ssGetSFcnParam(S,(0xd15+3898-0x1c4c))
#define z2e6483d505              ((0x153a+406-0x166c))
#define z71d06eae75        ((0x2473+603-0x26ce))
#define ze575982d5f        ((0x9ef+7325-0x268b))
#define z9c9edc1d33        ((0xb81+38-0xba5))
#define zc5ce4cb81a              ((0x745+7224-0x233d))
#define z2b17e2ee3b              ((0x8d5+6470-0x221b))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0xe06+2811-0x1801)];static uint16_T z0363d30aab(uint16_T x){if(x%(0x633+1159-0xab8)==(0x11bd+652-0x1449))return x+(0x118d+5172-0x25c0);else return x-(0x161b+3792-0x24ea);}static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x38a+5962-0x1ad4));ssSetNumDiscStates(S,(0xafd+6101-0x22d2));ssSetNumOutputPorts(S,(0x1957+1418-0x1ee1));ssSetNumInputPorts(S,(int)mxGetN(z1f7e7173d9));for(i=(0xc84+2478-0x1632);i<(int)mxGetN(z1f7e7173d9);i++){ssSetInputPortWidth(S,i,(0x8bb+657-0xb4b));ssSetInputPortDirectFeedThrough(S,i,(0x13d7+3774-0x2294));ssSetInputPortRequiredContiguous(S,i,(0xc20+5793-0x22c0));}ssSetNumSampleTimes(S,(0xcd4+1791-0x13d2));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x49a+5508-0x1a1e));ssSetNumNonsampledZCs(S,(0x124a+2645-0x1c9f));for(i=(0x654+5832-0x1d1c);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x165a+769-0x195b));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x2fa+3249-0xfab)]==-1.0){ssSetSampleTime(S,(0x663+7714-0x2485),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x11d7+4522-0x2381),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xd63+5547-0x230e),mxGetPr(z3832b85a32)[(0x5c8+3323-0x12c3)]);ssSetOffsetTime(S,(0x8c0+890-0xc3a),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zef529fae4a;void*ze2370ae9b9;volatile uint32_T*z3e5b8e05d8;void*zdfcb1da404,*z4b22edbbef,*z3a3f02d297;void*zf2db5722bf,*z25b7c8cb15,*z347e24803c;volatile uint32_T*z27fd94ac66;volatile uint16_T*z7638e8fb2b;volatile int16_T*z730e4b2b7b;uint_T i,z812c65ff2f;uint32_T out;if((int_T)mxGetPr(z702a26a5e9)[(0x68a+7910-0x2570)]<(0xad0+6807-0x2567)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x1829+3091-0x243b)){z366b2f03bf=(0x5df+5610-0x1bc9);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x799+3427-0x14fc)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x84d+2680-0x12c5)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x19b7+30-0x19d4)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0xe1c+3123-0x1950))|((z366b2f03bf&(0x2c4+2813-0xcc2))<<(0x182+971-0x545)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zef529fae4a=(void*)zeccbadd9b3.BaseAddress[(0x1b80+2877-0x26bd)];ze2370ae9b9=rl32eGetDevicePtr(zef529fae4a,(0x1890+812-0x19bc),RT_PG_USERREADWRITE);z3e5b8e05d8=(volatile uint32_T*)ze2370ae9b9;zdfcb1da404=(void*)zeccbadd9b3.BaseAddress[(0x1c9c+652-0x1f26)];zf2db5722bf=rl32eGetDevicePtr(zdfcb1da404,(0x4f9+2307-0xbfc),RT_PG_USERREADWRITE);z27fd94ac66=(volatile uint32_T*)zf2db5722bf;z4b22edbbef=(void*)zeccbadd9b3.BaseAddress[(0x341+1251-0x821)];z25b7c8cb15=rl32eGetDevicePtr(z4b22edbbef,(0x540+173-0x5ad),RT_PG_USERREADWRITE);z7638e8fb2b=(volatile uint16_T*)z25b7c8cb15;z3a3f02d297=(void*)zeccbadd9b3.BaseAddress[(0x253+8398-0x231d)];z347e24803c=rl32eGetDevicePtr(z3a3f02d297,(0xd2c+815-0xc5b),RT_PG_USERREADWRITE);z730e4b2b7b=(volatile int16_T*)z347e24803c;


ssSetIWorkValue(S,z71d06eae75,(uint32_T)z27fd94ac66);ssSetIWorkValue(S,ze575982d5f,(uint32_T)z7638e8fb2b);ssSetIWorkValue(S,z9c9edc1d33,(uint32_T)z730e4b2b7b);for(i=(0xd2f+407-0xec6);i<(0xd22+4044-0x1cce);i++){switch((uint16_T)mxGetPr(zc6f930323f)[i]){case(0xbe9+3717-0x1a6e):ssSetRWorkValue(S,i,13107.2);break;case(0x1a37+1202-0x1ee8):ssSetRWorkValue(S,i,6553.6);break;case(0x627+2381-0xf72):ssSetRWorkValue(S,i,6068.148);break;case(0x1565+3217-0x21f3):ssSetRWorkValue(S,i,6553.6);break;case(0x14f8+1867-0x1c3f):ssSetRWorkValue(S,i,3276.8);break;case(0xddc+3046-0x19bd):ssSetRWorkValue(S,i,3034.074);break;}}
for(i=(0xcef+6261-0x2564);i<(0x11f9+2154-0x1a43);i++){uint16_T range;range=(uint16_T)mxGetPr(zc6f930323f)[i];ssSetIWorkValue(S,(0x19e0+211-0x1aa9)+i,z730e4b2b7b[z0363d30aab((0x32f+2545-0xce0)*range+i)]);ssSetIWorkValue(S,(0x26b+3322-0xf5b)+i+(0xd76+6230-0x25ac),z730e4b2b7b[z0363d30aab(((0xa21+5054-0x1d9f)*range)+(0x39d+109-0x3ea)+i)]);}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T z31a846515d=ssGetIWorkValue(S,z71d06eae75);uint32_T z8ace1f9f47=ssGetIWorkValue(S,ze575982d5f);uint16_T i,z4e3026977c;volatile uint32_T*z27fd94ac66;volatile int16_T*z7638e8fb2b;real_T out;real_T*zc7fdaf6331;z27fd94ac66=(void*)z31a846515d;z7638e8fb2b=(void*)z8ace1f9f47;for(i=(0x1fa5+764-0x22a1);i<mxGetN(z1f7e7173d9);i++){zc7fdaf6331=(real_T*)ssGetInputPortRealSignal(S,i);z4e3026977c=(uint16_T)mxGetPr(z1f7e7173d9)[i]-(0x149d+2038-0x1c92);out=zc7fdaf6331[(0x101+406-0x297)]*ssGetRWorkValue(S,z4e3026977c);
out=out*(1.0-(real_T)ssGetIWorkValue(S,(0xe2+7328-0x1d78)+z4e3026977c)/131072.0)-(real_T)ssGetIWorkValue(S,(0xe70+729-0x113f)+z4e3026977c+(0x19e9+3133-0x2606))/4.0;
switch((uint16_T)mxGetPr(zc6f930323f)[i]){case(0x1816+181-0x18cb):case(0x2146+247-0x223c):case(0xbe1+5913-0x22f8):if(out>65535){out=65535;}if(out<(0x8a2+120-0x91a)){out=(0x5da+5386-0x1ae4);}break;case(0xee0+2061-0x16ea):case(0x1b95+2361-0x24ca):case(0xf1d+2973-0x1ab5):if(out>32767){out=32767;}if(out<-32768){out=-32768;}break;}z7638e8fb2b[z0363d30aab(z4e3026977c)]=(int16_T)out;}
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

