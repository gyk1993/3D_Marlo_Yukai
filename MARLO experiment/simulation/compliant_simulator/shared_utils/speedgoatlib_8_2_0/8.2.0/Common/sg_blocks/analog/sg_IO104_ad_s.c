/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1b73+752-0x1e61)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO104_ad_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x30\x34"
#define z694756a014 (0x1d63+2310-0x15b4)
#define zea87e0ba83 36950
#define z29146a1837 (0x184d+1540-0xd9c)
#define zab7e64468b 12658
#define zdf24515981          ((0x1009+4000-0x1fa3))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0xd4f+1055-0x116e))
#define z9cd34e3860                ssGetSFcnParam(S,(0x1d25+651-0x1faf))
#define z8e65f77d17              ssGetSFcnParam(S,(0x116a+5324-0x2634))
#define z0520ad4962              ssGetSFcnParam(S,(0x925+5195-0x1d6d))
#define z3832b85a32           ssGetSFcnParam(S,(0x1713+821-0x1a44))
#define z702a26a5e9                ssGetSFcnParam(S,(0x89c+3383-0x15ce))
#define z2e6483d505              ((0x10b0+2241-0x196f))
#define z6a0da049de         ((0xbbc+1824-0x12dc))
#define zc2f3e0cbc0        ((0x1fa9+442-0x2162))
#define zc5ce4cb81a              ((0x11a+6599-0x1ad1))
#define z8caad2a8e6              ((0x18a4+3034-0x247e))
#define z5bfe7a2613            ((0x6d8+2935-0x1247))
#define z2b17e2ee3b              ((0xe28+4808-0x20f0))
static char_T zea4cd01646[(0x607+4526-0x16b5)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xbd3+969-0xf9c));ssSetNumDiscStates(S,(0xccf+537-0xee8));ssSetNumInputPorts(S,(0x1a6a+418-0x1c0c));ssSetNumOutputPorts(S,(uint16_T)mxGetN(za9d8fb6bcf));for(i=(0xb2+4717-0x131f);i<(uint16_T)mxGetN(za9d8fb6bcf);i++){ssSetOutputPortWidth(S,i,(0x1980+707-0x1c42));}ssSetNumSampleTimes(S,(0x947+6095-0x2115));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xa25+4182-0x1a7b));ssSetNumNonsampledZCs(S,(0xa8c+2769-0x155d));for(i=(0xad5+4647-0x1cfc);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x82+8491-0x21ad));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0xe39+237-0xf26)]==-1.0){ssSetSampleTime(S,(0x4c8+7690-0x22d2),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x258a+344-0x26e2),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x7b8+4916-0x1aec),mxGetPr(z3832b85a32)[(0xc00+2772-0x16d4)]);ssSetOffsetTime(S,(0x155a+838-0x18a0),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T range,out;uint16_T z4e3026977c;uint32_T zf91d71c6d9=(uint32_T)mxGetN(za9d8fb6bcf);if((int_T)mxGetPr(z702a26a5e9)[(0x2e8+7707-0x2103)]<(0x1074+2544-0x1a64)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x1458+4717-0x26c4)){z366b2f03bf=(0xf1a+1746-0x15ec);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xe39+619-0x10a4)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x1b07+419-0x1caa)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x30+7516-0x1d8b)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x2e3+2631-0xc2b))|((z366b2f03bf&(0x990+424-0xa39))<<(0x914+1100-0xd58)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x161d+1590-0x1c51)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x1d43+777-0x1fcc),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,zc2f3e0cbc0,(uint32_T)zf91d71c6d9);for(i=(0x7a+3102-0xc98);i<zf91d71c6d9;i++){z4e3026977c=(uint16_T)mxGetPr(za9d8fb6bcf)[i];if(z4e3026977c==(0xdb+5601-0x16bb)||z4e3026977c==(0x717+1809-0xe26)||z4e3026977c==(0x1f7+1208-0x6aa)||z4e3026977c==(0x542+30-0x55a)){range=(uint16_T)mxGetPr(z8e65f77d17)[(0xd28+6092-0x24f4)];}else{range=(uint16_T)mxGetPr(z0520ad4962)[(0xb04+2041-0x12fd)];}switch(range){case(0xa13+3307-0x16fd):ssSetRWorkValue(S,z8caad2a8e6+i,3276.8);ssSetRWorkValue(S,z5bfe7a2613+i,10.0);break;case(0x1c01+2530-0x25e1):ssSetRWorkValue(S,z8caad2a8e6+i,6553.6);ssSetRWorkValue(S,z5bfe7a2613+i,5.0);break;case(0x7cd+7642-0x25a4):ssSetRWorkValue(S,z8caad2a8e6+i,13107.2);ssSetRWorkValue(S,z5bfe7a2613+i,2.5);break;}}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T zf91d71c6d9=ssGetIWorkValue(S,zc2f3e0cbc0);volatile uint32_T*za42cf7dd4a;uint16_T z0add1d1c25;real_T*y,z0754dd67cc,offset;uint32_T i;uint32_T count;za42cf7dd4a=(void*)base;za42cf7dd4a[(0xf1f+213-0xff4)]=za42cf7dd4a[(0x1942+3471-0x26d1)]|(0xf2a+3772-0x1ce6);while((za42cf7dd4a[(0x1db9+401-0x1f4a)]&(0x10d0+4525-0x217d)));for(i=(0x16b5+2732-0x2161);i<zf91d71c6d9;i++){
z0add1d1c25=(uint16_T)mxGetPr(z9cd34e3860)[i];y=ssGetOutputPortSignal(S,z0add1d1c25-(0x143b+3464-0x21c2));count=za42cf7dd4a[(0xc66+6456-0x2598)]&65535;z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6+z0add1d1c25-(0x5b4+8494-0x26e1));offset=ssGetRWorkValue(S,z5bfe7a2613+z0add1d1c25-(0x75f+5955-0x1ea1));y[(0x1a37+354-0x1b99)]=(real_T)count/z0754dd67cc-offset;}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

