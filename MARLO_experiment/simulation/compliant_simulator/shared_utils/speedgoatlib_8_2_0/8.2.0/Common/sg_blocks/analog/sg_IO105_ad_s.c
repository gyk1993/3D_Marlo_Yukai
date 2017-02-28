/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x2bc+6613-0x1c8f)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO105_ad_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x30\x35"
#define z694756a014 (0x1439+7522-0x20e6)
#define zea87e0ba83 36992
#define z29146a1837 (0x2170+3808-0x1f9b)
#define zab7e64468b 9223
#define zdf24515981          ((0x15d+2474-0xb02))
#define z2cc9a52544            ssGetSFcnParam(S,(0x59b+3253-0x1250))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0x3b4+8159-0x2392))
#define z8fd86139be               ssGetSFcnParam(S,(0xeff+3131-0x1b38))
#define z3832b85a32           ssGetSFcnParam(S,(0x1673+3768-0x2528))
#define z702a26a5e9                ssGetSFcnParam(S,(0x2373+33-0x2390))
#define z2e6483d505              ((0xe27+5969-0x2576))
#define z6a0da049de         ((0x16bd+3112-0x22e5))
#define zc2f3e0cbc0        ((0x150c+690-0x17bd))
#define zc5ce4cb81a              ((0xfe6+2732-0x1a90))
#define z8caad2a8e6              ((0x1a76+1750-0x214c))
#define z5bfe7a2613            ((0xdb7+4975-0x2125))
#define z2b17e2ee3b              ((0x149c+1812-0x1bb0))
static char_T zea4cd01646[(0x24a+3978-0x10d4)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x738+4360-0x1840));ssSetNumDiscStates(S,(0x9c3+2270-0x12a1));ssSetNumInputPorts(S,(0x15c0+1223-0x1a87));switch((uint8_T)mxGetPr(z2cc9a52544)[(0x18cf+635-0x1b4a)]){case(0x701+4905-0x1a29):ssSetNumOutputPorts(S,(uint16_T)mxGetN(za9d8fb6bcf));for(i=(0xb4a+2169-0x13c3);i<(uint16_T)mxGetN(za9d8fb6bcf);i++){ssSetOutputPortWidth(S,i,(0x673+1802-0xd7c));}break;case(0x10c4+2302-0x19c0):ssSetNumOutputPorts(S,(0xb33+6716-0x256e));ssSetOutputPortWidth(S,(0x1521+2728-0x1fc9),(uint16_T)mxGetN(za9d8fb6bcf));break;}ssSetNumSampleTimes(S,(0x4fb+4437-0x164f));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x95a+47-0x989));ssSetNumNonsampledZCs(S,(0x6d9+173-0x786));for(i=(0x1601+809-0x192a);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xccf+2678-0x1745));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x10d5+1162-0x155f)]==-1.0){ssSetSampleTime(S,(0xb0d+63-0xb4c),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x17ad+1983-0x1f6c),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xd80+769-0x1081),mxGetPr(z3832b85a32)[(0x116a+1218-0x162c)]);ssSetOffsetTime(S,(0x4c3+7119-0x2092),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T range,out;uint32_T zf91d71c6d9=(uint32_T)mxGetN(za9d8fb6bcf);if((int_T)mxGetPr(z702a26a5e9)[(0x2004+1439-0x25a3)]<(0x617+7320-0x22af)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xb31+2469-0x14d5)){z366b2f03bf=(0x222+6179-0x1a45);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x2106+231-0x21ed)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x1688+2487-0x203f)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1db2+2033-0x25a2)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x1a62+2564-0x2367))|((z366b2f03bf&(0x89d+3693-0x160b))<<(0xc49+551-0xe68)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0xb1b+1140-0xf8d)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x463+4237-0x14b0),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,zc2f3e0cbc0,(uint32_T)zf91d71c6d9);switch((uint16_T)mxGetPr(z8fd86139be)[(0xbda+5669-0x21ff)]){case(0xa21+4453-0x1b85):ssSetRWorkValue(S,z8caad2a8e6,3276.8);ssSetRWorkValue(S,z5bfe7a2613,10.0);range=(0x2cb+1731-0x98c);break;case(0x15a1+2346-0x1ec9):ssSetRWorkValue(S,z8caad2a8e6,6553.6);ssSetRWorkValue(S,z5bfe7a2613,5.0);range=(0x1725+2382-0x2072);break;case(0x34f+6696-0x1d74):ssSetRWorkValue(S,z8caad2a8e6,13107.2);ssSetRWorkValue(S,z5bfe7a2613,2.5);range=(0x14b5+1508-0x1a99);break;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T zf91d71c6d9=ssGetIWorkValue(S,zc2f3e0cbc0);real_T z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6);real_T offset=ssGetRWorkValue(S,z5bfe7a2613);volatile uint32_T*za42cf7dd4a;real_T*y;uint32_T i;uint32_T count;za42cf7dd4a=(void*)base;za42cf7dd4a[(0xde7+39-0xe0e)]=za42cf7dd4a[(0x15f3+3492-0x2397)]|(0x18c4+5860-0x1fa8);
switch((uint8_T)mxGetPr(z2cc9a52544)[(0xb50+4577-0x1d31)]){case(0x787+3726-0x1614):for(i=(0xcf0+5222-0x2156);i<zf91d71c6d9;i++){y=ssGetOutputPortSignal(S,i);while(!(za42cf7dd4a[(0x4e1+7845-0x2383)]&131072));count=za42cf7dd4a[(0x102f+5280-0x24cd)]&65535;y[(0x460+544-0x680)]=(real_T)count/z0754dd67cc-offset;}break;case(0x1f7+2784-0xcd5):y=ssGetOutputPortSignal(S,(0x120d+4501-0x23a2));for(i=(0x1f5+1875-0x948);i<zf91d71c6d9;i++){while(!(za42cf7dd4a[(0xbb2+5369-0x20a8)]&131072));count=za42cf7dd4a[(0x15a0+3781-0x2463)]&65535;y[i]=(real_T)count/z0754dd67cc-offset;}break;}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

