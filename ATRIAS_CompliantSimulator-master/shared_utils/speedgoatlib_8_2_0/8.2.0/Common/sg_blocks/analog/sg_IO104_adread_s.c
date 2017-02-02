/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x95d+2182-0x11e1)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO104_adread_s
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
#define z694756a014 (0x159f+7105-0x20ab)
#define zea87e0ba83 36950
#define z29146a1837 (0x192f+26-0x894)
#define zab7e64468b 12658
#define zdf24515981          ((0x20f1+663-0x2380))
#define za8bff65d14              ssGetSFcnParam(S,(0x893+4789-0x1b48))
#define z04bce731b0             ssGetSFcnParam(S,(0x180d+948-0x1bc0))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0x765+4554-0x192d))
#define z9cd34e3860                ssGetSFcnParam(S,(0xa11+714-0xcd8))
#define z8e65f77d17              ssGetSFcnParam(S,(0x15d6+3787-0x249d))
#define z0520ad4962              ssGetSFcnParam(S,(0xcda+5687-0x230c))
#define z3832b85a32           ssGetSFcnParam(S,(0x11fa+3447-0x1f6b))
#define z702a26a5e9                ssGetSFcnParam(S,(0x154c+245-0x163a))
#define z2e6483d505              ((0x585+4800-0x1843))
#define z6a0da049de         ((0x90c+3221-0x15a1))
#define zc2f3e0cbc0        ((0x1190+932-0x1533))
#define zc5ce4cb81a              ((0xc5+8220-0x20d1))
#define z8caad2a8e6              ((0xc1f+2799-0x170e))
#define z5bfe7a2613            ((0x14d3+3510-0x2281))
#define z2b17e2ee3b              ((0x310+1986-0xad2))
static char_T zea4cd01646[(0x178d+1583-0x1cbc)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x4ac+1492-0xa80));ssSetNumDiscStates(S,(0x743+2604-0x116f));if(!(boolean_T)mxGetPr(z04bce731b0)[(0x164b+166-0x16f1)]){ssSetNumOutputPorts(S,(uint16_T)mxGetN(za9d8fb6bcf));for(i=(0xc76+2596-0x169a);i<(uint16_T)mxGetN(za9d8fb6bcf);i++){ssSetOutputPortWidth(S,i,(0x2d9+8700-0x24d4));}}else{ssSetNumOutputPorts(S,(uint16_T)mxGetN(za9d8fb6bcf)+(0x9ef+3144-0x1636));ssSetOutputPortDataType(S,(0xec8+3102-0x1ae6),SS_BOOLEAN);ssSetOutputPortWidth(S,(0x41d+3255-0x10d4),(0x1367+3527-0x212d));for(i=(0xf91+4691-0x21e4);i<(uint16_T)mxGetN(za9d8fb6bcf);i++){ssSetOutputPortWidth(S,i+(0x1247+3255-0x1efd),(0x94d+3643-0x1787));}}if(!(boolean_T)mxGetPr(za8bff65d14)[(0x1dbf+543-0x1fde)]){ssSetNumInputPorts(S,(0x5db+7069-0x2178));}else{ssSetNumInputPorts(S,(0x20c1+1365-0x2615));ssSetInputPortDirectFeedThrough(S,(0x8e9+612-0xb4d),(0x1b86+864-0x1ee5));ssSetInputPortWidth(S,(0x1119+366-0x1287),(0x726+3385-0x145e));ssSetInputPortDataType(S,(0x338+7724-0x2164),SS_BOOLEAN);ssSetInputPortRequiredContiguous(S,(0xf52+5673-0x257b),(0x1b2c+1490-0x20fd));}ssSetNumSampleTimes(S,(0xbd6+202-0xc9f));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x287+2453-0xc1c));ssSetNumNonsampledZCs(S,(0x1215+1165-0x16a2));for(i=(0x45c+5327-0x192b);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x15b7+4248-0x264f));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x101f+1765-0x1704)]==-1.0){ssSetSampleTime(S,(0x7dd+6363-0x20b8),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x5a0+8113-0x2551),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x7b8+5706-0x1e02),mxGetPr(z3832b85a32)[(0x1d18+1410-0x229a)]);ssSetOffsetTime(S,(0xd2a+3934-0x1c88),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T range,out;uint16_T z4e3026977c;uint32_T zf91d71c6d9=(uint32_T)mxGetN(za9d8fb6bcf);if((int_T)mxGetPr(z702a26a5e9)[(0xf59+1159-0x13e0)]<(0xb9d+4738-0x1e1f)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x1302+2311-0x1c08)){z366b2f03bf=(0x1c0c+1022-0x200a);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xf2a+3771-0x1de5)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x1983+1241-0x1e5c)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xaa1+4950-0x1df6)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x9c1+2776-0x139a))|((z366b2f03bf&(0xfff+3533-0x1ccd))<<(0x94a+1480-0xf0a)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0xb8f+2270-0x146b)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x560+4488-0x1668),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,zc2f3e0cbc0,(uint32_T)zf91d71c6d9);for(i=(0x1e61+1594-0x249b);i<zf91d71c6d9;i++){z4e3026977c=(uint16_T)mxGetPr(za9d8fb6bcf)[i];if(z4e3026977c==(0x51a+2430-0xe97)||z4e3026977c==(0x1781+1302-0x1c95)||z4e3026977c==(0xf8d+2020-0x176c)||z4e3026977c==(0xb13+388-0xc91)){range=(uint16_T)mxGetPr(z8e65f77d17)[(0xec+2340-0xa10)];}else{range=(uint16_T)mxGetPr(z0520ad4962)[(0xc91+3317-0x1986)];}switch(range){case(0xa73+5322-0x1f3c):ssSetRWorkValue(S,z8caad2a8e6+i,3276.8);ssSetRWorkValue(S,z5bfe7a2613+i,10.0);break;case(0x12a0+1353-0x17e7):ssSetRWorkValue(S,z8caad2a8e6+i,6553.6);ssSetRWorkValue(S,z5bfe7a2613+i,5.0);break;case(0x1ca+2167-0xa3e):ssSetRWorkValue(S,z8caad2a8e6+i,13107.2);ssSetRWorkValue(S,z5bfe7a2613+i,2.5);break;}}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T zf91d71c6d9=ssGetIWorkValue(S,zc2f3e0cbc0);volatile uint32_T*za42cf7dd4a;uint16_T z0add1d1c25;real_T*y,z0754dd67cc,offset;uint32_T i;uint32_T count;uint32_T z4314ccb6ec=(0x18a+8991-0x24a9);boolean_T*z0daf90e5e1;boolean_T enabled=true;if((int)mxGetPr(za8bff65d14)[(0x292+3035-0xe6d)]){z0daf90e5e1=(boolean_T*)ssGetInputPortSignal(S,(0x1a7+6248-0x1a0f));enabled=z0daf90e5e1[(0x4e0+3920-0x1430)];}if((int)mxGetPr(z04bce731b0)[(0x52f+1448-0xad7)]){z0daf90e5e1=(boolean_T*)ssGetOutputPortSignal(S,(0xa24+1220-0xee8));z0daf90e5e1[(0xa5a+924-0xdf6)]=enabled;z4314ccb6ec=(0xf68+5607-0x254e);}za42cf7dd4a=(void*)base;if(enabled){while((za42cf7dd4a[(0x460+6937-0x1f79)]&(0x229+8578-0x22ab)));for(i=(0x18b+6326-0x1a41);i<zf91d71c6d9;i++){
z0add1d1c25=(uint16_T)mxGetPr(z9cd34e3860)[i];y=ssGetOutputPortSignal(S,z0add1d1c25-(0x728+1944-0xebf)+z4314ccb6ec);count=za42cf7dd4a[(0xbf3+6041-0x2386)]&65535;z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6+z0add1d1c25-(0x16d4+2890-0x221d));offset=ssGetRWorkValue(S,z5bfe7a2613+z0add1d1c25-(0xec3+5176-0x22fa));y[(0x552+553-0x77b)]=(real_T)count/z0754dd67cc-offset;}za42cf7dd4a[(0x1b1c+79-0x1b6b)]=za42cf7dd4a[(0x46a+6813-0x1f07)]|8192;}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

