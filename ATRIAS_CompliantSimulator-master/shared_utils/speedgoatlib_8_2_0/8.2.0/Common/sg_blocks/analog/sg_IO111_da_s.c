/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x67a+8105-0x2621)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO111_da_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x31\x31"
#define z694756a014 (0x15b5+1798-0x823)
#define zea87e0ba83 (0x1fdc+333-0x1f00)
#define z29146a1837 (0x16f7+7799-0x20d6)
#define zab7e64468b (0x743+1107-0xb8b)
#define zdf24515981          ((0x13d7+2500-0x1d97))
#define z702a26a5e9                ssGetSFcnParam(S,(0x1868+2834-0x237a))
#define z1f7e7173d9          ssGetSFcnParam(S,(0x225+3529-0xfed))
#define zc6f930323f            ssGetSFcnParam(S,(0x1e38+704-0x20f6))
#define z3832b85a32           ssGetSFcnParam(S,(0xc01+5561-0x21b7))
#define z2e6483d505              ((0x519+8329-0x253e))
#define z71d06eae75        ((0xd28+3256-0x19e0))
#define ze575982d5f        ((0x6eb+4538-0x18a4))
#define z9c9edc1d33        ((0x17ed+3592-0x25f3))
#define zc5ce4cb81a              ((0x1d21+1362-0x2233))
#define z2b17e2ee3b              ((0x1fab+459-0x2176))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0x146f+2996-0x1f23)];static uint16_T z0363d30aab(uint16_T x){if(x%(0x242+7635-0x2013)==(0xcc1+3026-0x1893))return x+(0x5b5+337-0x705);else return x-(0x9bd+95-0xa1b);}static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x179b+2821-0x22a0));ssSetNumDiscStates(S,(0x428+3311-0x1117));ssSetNumOutputPorts(S,(0x904+4778-0x1bae));ssSetNumInputPorts(S,(int)mxGetN(z1f7e7173d9));for(i=(0x14d2+1777-0x1bc3);i<(int)mxGetN(z1f7e7173d9);i++){ssSetInputPortWidth(S,i,(0x1535+316-0x1670));ssSetInputPortDirectFeedThrough(S,i,(0x60+342-0x1b5));ssSetInputPortRequiredContiguous(S,i,(0x124d+194-0x130e));}ssSetNumSampleTimes(S,(0x8fa+1802-0x1003));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xa00+4650-0x1c2a));ssSetNumNonsampledZCs(S,(0xcb3+6625-0x2694));for(i=(0x19c0+2567-0x23c7);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x93+685-0x340));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x1344+1911-0x1abb)]==-1.0){ssSetSampleTime(S,(0x683+3146-0x12cd),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x2638+14-0x2646),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x123+1267-0x616),mxGetPr(z3832b85a32)[(0x755+4252-0x17f1)]);ssSetOffsetTime(S,(0x20+6470-0x1966),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zef529fae4a;void*ze2370ae9b9;volatile uint32_T*z3e5b8e05d8;void*zdfcb1da404,*z4b22edbbef,*z3a3f02d297;void*zf2db5722bf,*z25b7c8cb15,*z347e24803c;volatile uint32_T*z27fd94ac66;volatile uint16_T*z7638e8fb2b;volatile int16_T*z730e4b2b7b;uint_T i,z812c65ff2f;uint32_T out;if((int_T)mxGetPr(z702a26a5e9)[(0xc03+5762-0x2285)]<(0xba3+6835-0x2656)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x1d5d+2346-0x2686)){z366b2f03bf=(0x541+4473-0x16ba);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x991+5038-0x1d3f)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x633+6532-0x1fb7)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x205+1747-0x8d7)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0xec3+5853-0x24a1))|((z366b2f03bf&(0xb9a+6381-0x2388))<<(0xac3+6576-0x246b)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zef529fae4a=(void*)zeccbadd9b3.BaseAddress[(0x19b4+1248-0x1e94)];ze2370ae9b9=rl32eGetDevicePtr(zef529fae4a,(0x640+7004-0x1f9c),RT_PG_USERREADWRITE);z3e5b8e05d8=(volatile uint32_T*)ze2370ae9b9;zdfcb1da404=(void*)zeccbadd9b3.BaseAddress[(0x1d4+7822-0x2060)];zf2db5722bf=rl32eGetDevicePtr(zdfcb1da404,(0x440+795-0x55b),RT_PG_USERREADWRITE);z27fd94ac66=(volatile uint32_T*)zf2db5722bf;z4b22edbbef=(void*)zeccbadd9b3.BaseAddress[(0xc75+4281-0x1d2b)];z25b7c8cb15=rl32eGetDevicePtr(z4b22edbbef,(0x2d0+8748-0x24bc),RT_PG_USERREADWRITE);z7638e8fb2b=(volatile uint16_T*)z25b7c8cb15;z3a3f02d297=(void*)zeccbadd9b3.BaseAddress[(0x13d9+4506-0x256f)];z347e24803c=rl32eGetDevicePtr(z3a3f02d297,(0x768+8711-0x256f),RT_PG_USERREADWRITE);z730e4b2b7b=(volatile int16_T*)z347e24803c;


ssSetIWorkValue(S,z71d06eae75,(uint32_T)z27fd94ac66);ssSetIWorkValue(S,ze575982d5f,(uint32_T)z7638e8fb2b);ssSetIWorkValue(S,z9c9edc1d33,(uint32_T)z730e4b2b7b);for(i=(0x872+2116-0x10b6);i<(0xfbf+5435-0x24ea);i++){switch((uint16_T)mxGetPr(zc6f930323f)[i]){case(0x1341+3342-0x204f):ssSetRWorkValue(S,i,13107.2);break;case(0x737+8068-0x26ba):ssSetRWorkValue(S,i,6553.6);break;case(0xce9+2487-0x169e):ssSetRWorkValue(S,i,6068.148);break;case(0x105f+5545-0x2605):ssSetRWorkValue(S,i,6553.6);break;case(0x1115+3705-0x1f8a):ssSetRWorkValue(S,i,3276.8);break;case(0x1a67+1048-0x1e7a):ssSetRWorkValue(S,i,3034.074);break;}}
for(i=(0xc62+5358-0x2150);i<(0x1781+786-0x1a83);i++){uint16_T range;range=(uint16_T)mxGetPr(zc6f930323f)[i];ssSetIWorkValue(S,(0x758+3216-0x13de)+i,z730e4b2b7b[z0363d30aab((0x720+7529-0x2449)*range+i)]);ssSetIWorkValue(S,(0x18c6+1294-0x1dca)+i+(0x1d63+976-0x2123),z730e4b2b7b[z0363d30aab(((0xbdb+1476-0x115f)*range)+(0x12c9+3857-0x21ca)+i)]);}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T z31a846515d=ssGetIWorkValue(S,z71d06eae75);uint32_T z8ace1f9f47=ssGetIWorkValue(S,ze575982d5f);uint16_T i,z4e3026977c;volatile uint32_T*z27fd94ac66;volatile int16_T*z7638e8fb2b;real_T out;real_T*zc7fdaf6331;z27fd94ac66=(void*)z31a846515d;z7638e8fb2b=(void*)z8ace1f9f47;for(i=(0x499+8202-0x24a3);i<mxGetN(z1f7e7173d9);i++){zc7fdaf6331=(real_T*)ssGetInputPortRealSignal(S,i);z4e3026977c=(uint16_T)mxGetPr(z1f7e7173d9)[i]-(0x91d+4592-0x1b0c);out=zc7fdaf6331[(0x207f+1090-0x24c1)]*ssGetRWorkValue(S,z4e3026977c);
out=out*(1.0-(real_T)ssGetIWorkValue(S,(0x804+3840-0x16fa)+z4e3026977c)/131072.0)-(real_T)ssGetIWorkValue(S,(0x6ef+3480-0x147d)+z4e3026977c+(0x652+7648-0x2422))/4.0;
switch((uint16_T)mxGetPr(zc6f930323f)[i]){case(0xecf+2034-0x16c1):case(0xac2+641-0xd42):case(0x1096+4547-0x2257):if(out>65535){out=65535;}if(out<(0x670+916-0xa04)){out=(0x591+556-0x7bd);}break;case(0x1975+649-0x1bfb):case(0x1b17+480-0x1cf3):case(0x2564+21-0x2574):if(out>32767){out=32767;}if(out<-32768){out=-32768;}break;}z7638e8fb2b[z0363d30aab(z4e3026977c)]=(int16_T)out;}
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

