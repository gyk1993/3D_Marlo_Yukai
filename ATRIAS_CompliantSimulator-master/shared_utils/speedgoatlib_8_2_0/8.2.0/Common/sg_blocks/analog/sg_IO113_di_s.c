/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1178+2210-0x1a18)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO113_di_s
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
#define z694756a014 (0x1a34+2572-0x138b)
#define zea87e0ba83 36950
#define z29146a1837 4277
#define zab7e64468b 13143
#define zdf24515981          ((0x7d6+3335-0x14da))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0x118b+535-0x13a2))
#define z3832b85a32           ssGetSFcnParam(S,(0x5e3+8174-0x25d0))
#define z702a26a5e9                ssGetSFcnParam(S,(0x7f8+5514-0x1d80))
#define z2e6483d505              ((0x154f+3828-0x2442))
#define z6a0da049de         ((0x1901+2891-0x244c))
#define zc5ce4cb81a              ((0x1bff+2528-0x25df))
#define z2b17e2ee3b              ((0x229b+448-0x245b))
static char_T zea4cd01646[(0x173+6280-0x18fb)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif

ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xc02+1424-0x1192));ssSetNumDiscStates(S,(0x9b6+4292-0x1a7a));ssSetNumInputPorts(S,(0xb10+3275-0x17db));ssSetNumOutputPorts(S,(int)mxGetN(za9d8fb6bcf));for(i=(0x1539+2249-0x1e02);i<(int)mxGetN(za9d8fb6bcf);i++){ssSetOutputPortWidth(S,i,(0x28f+7293-0x1f0b));ssSetOutputPortDataType(S,(0x18c9+2264-0x21a1),SS_DOUBLE);}ssSetNumSampleTimes(S,(0x1fd2+1413-0x2556));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1fa7+988-0x2383));ssSetNumNonsampledZCs(S,(0x876+2446-0x1204));for(i=(0x82+3624-0xeaa);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1c01+1395-0x2174));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);
}static void mdlInitializeSampleTimes(SimStruct*S){
if(mxGetPr(z3832b85a32)[(0x3a2+3817-0x128b)]==-1.0){ssSetSampleTime(S,(0xf26+5908-0x263a),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x42d+923-0x7c8),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x14bf+2204-0x1d5b),mxGetPr(z3832b85a32)[(0x144+531-0x357)]);ssSetOffsetTime(S,(0xb6b+1877-0x12c0),0.0);}
}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint16_T zf91d71c6d9=(int)mxGetN(za9d8fb6bcf);
if((int_T)mxGetPr(z702a26a5e9)[(0xf3d+44-0xf69)]<(0x952+2231-0x1209)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x653+2658-0x10b4)){z366b2f03bf=(0xf4b+2183-0x17d2);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1daf+1577-0x23d8)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x24e5+533-0x26fa)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x14c+178-0x1fd)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x110+5111-0x1408))|((z366b2f03bf&(0xb23+3070-0x1622))<<(0xd47+956-0x10fb)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x158a+3766-0x243e)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x155f+4198-0x25a5),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;uint32_T z0c3eef007f;uint32_T i,input,z4e3026977c;real_T*y;
za42cf7dd4a=(void*)base;z0c3eef007f=mxGetN(za9d8fb6bcf);input=za42cf7dd4a[(0x20f+5609-0x17f7)];
for(i=(0xcec+5005-0x2079);i<z0c3eef007f;i++){z4e3026977c=(uint16_T)mxGetPr(za9d8fb6bcf)[i]-(0xc3f+2803-0x1731);y=ssGetOutputPortSignal(S,i);switch(z4e3026977c){case(0x1a0+8855-0x2437):y[(0x1203+3365-0x1f28)]=(input&(0x1679+567-0x18af));break;case(0x15cb+692-0x187e):y[(0xa38+209-0xb09)]=(input&(0x9cf+5940-0x2101))>>(0x14a7+3245-0x2153);break;case(0xbf8+3803-0x1ad1):y[(0x10b3+3018-0x1c7d)]=(input&(0x682+3220-0x1312))>>(0x2f3+3748-0x1195);break;case(0x320+6457-0x1c56):y[(0x1500+2976-0x20a0)]=(input&(0x1d74+1945-0x2505))>>(0x1a5f+2354-0x238e);break;case(0x219+4634-0x142f):y[(0x14d3+4525-0x2680)]=(input&(0x114b+5127-0x2452))>>(0x194+295-0x2b3);break;case(0x28f+4190-0x12e8):y[(0x851+4269-0x18fe)]=(input&(0x365+4150-0x119b))>>(0x14a3+3878-0x23c0);break;case(0x307+7891-0x21d4):y[(0x2a2+2955-0xe2d)]=(input&(0x23c7+435-0x217a))>>(0x1403+2860-0x1f25);break;case(0xe8+2354-0xa13):y[(0x6f4+3826-0x15e6)]=(input&(0x1c60+704-0x1720))>>(0x120a+3462-0x1f85);break;}}
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

