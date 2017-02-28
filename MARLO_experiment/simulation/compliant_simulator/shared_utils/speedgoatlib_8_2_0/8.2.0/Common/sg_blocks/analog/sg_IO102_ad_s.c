/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1b6b+2160-0x23d9)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO102_ad_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x30\x32"
#define z694756a014 (0x122b+1956-0x91a)
#define zea87e0ba83 36992
#define z29146a1837 4277
#define zab7e64468b 9218
#define zdf24515981          ((0x31f+8701-0x2516))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0x17f+1358-0x6cd))
#define z8fd86139be               ssGetSFcnParam(S,(0x220+191-0x2de))
#define z3832b85a32           ssGetSFcnParam(S,(0xe52+930-0x11f2))
#define z702a26a5e9                ssGetSFcnParam(S,(0x3f9+3314-0x10e8))
#define z05e67510ff        ssGetSFcnParam(S,(0x5e5+1516-0xbcd))
#define z0d9acd09bb         ssGetSFcnParam(S,(0x6c4+3719-0x1546))
#define z2e6483d505              ((0x126b+2117-0x1aae))
#define z6a0da049de         ((0xa15+5460-0x1f69))
#define zc2f3e0cbc0        ((0x5b9+1493-0xb8d))
#define zc5ce4cb81a              ((0x541+3349-0x1254))
#define z8caad2a8e6              ((0x1813+3150-0x2461))
#define z5bfe7a2613            ((0x912+2428-0x128d))
#define z2b17e2ee3b              ((0x15c+2065-0x96d))
static char_T zea4cd01646[(0x1616+1602-0x1b58)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x3cc+8467-0x24df));ssSetNumDiscStates(S,(0x3da+1971-0xb8d));ssSetNumInputPorts(S,(0x1ecb+1961-0x2674));ssSetNumOutputPorts(S,(uint16_T)mxGetN(za9d8fb6bcf));for(i=(0x544+803-0x867);i<(uint16_T)mxGetN(za9d8fb6bcf);i++){ssSetOutputPortWidth(S,i,(0x1190+4834-0x2471));}ssSetNumSampleTimes(S,(0x85a+5366-0x1d4f));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xd+4723-0x1280));ssSetNumNonsampledZCs(S,(0x8c5+2279-0x11ac));for(i=(0xe40+2634-0x188a);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xcff+1530-0x12f9));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x1701+3073-0x2302)]==-1.0){ssSetSampleTime(S,(0x1bc4+846-0x1f12),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x97f+1928-0x1107),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x1322+3403-0x206d),mxGetPr(z3832b85a32)[(0x7d1+6528-0x2151)]);ssSetOffsetTime(S,(0x1194+403-0x1327),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T range,out;uint32_T zf91d71c6d9=(uint32_T)mxGetN(za9d8fb6bcf);if((int_T)mxGetPr(z702a26a5e9)[(0x12a2+1375-0x1801)]<(0x933+4698-0x1b8d)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x1016+862-0x1373)){z366b2f03bf=(0xc6f+2834-0x1781);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x15e4+394-0x176e)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x11a6+4508-0x2342)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xd4c+3197-0x19c8)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0xc69+3603-0x197d))|((z366b2f03bf&(0x929+6956-0x2356))<<(0xf56+3075-0x1b51)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0xebb+1184-0x1359)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x604+2689-0x1045),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,zc2f3e0cbc0,(uint32_T)zf91d71c6d9);switch((uint16_T)mxGetPr(z8fd86139be)[(0x42f+7769-0x2288)]){case(0x3d4+6172-0x1bef):ssSetRWorkValue(S,z8caad2a8e6,3276.8);ssSetRWorkValue(S,z5bfe7a2613,10.0);range=(0x1bdf+2097-0x240e);break;case(0x16d4+2705-0x2163):ssSetRWorkValue(S,z8caad2a8e6,6553.6);ssSetRWorkValue(S,z5bfe7a2613,5.0);range=(0xfe8+3711-0x1e66);break;case(0x1c17+1019-0x200f):ssSetRWorkValue(S,z8caad2a8e6,13107.2);ssSetRWorkValue(S,z5bfe7a2613,2.5);range=(0x20cf+1472-0x268f);break;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T zf91d71c6d9=ssGetIWorkValue(S,zc2f3e0cbc0);real_T z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6);real_T offset=ssGetRWorkValue(S,z5bfe7a2613);volatile uint32_T*za42cf7dd4a;real_T*y;uint32_T i;uint32_T count;za42cf7dd4a=(void*)base;za42cf7dd4a[(0x78f+2251-0x105a)]=za42cf7dd4a[(0x2d2+461-0x49f)]|(0x15b3+4104-0x15bb);
for(i=(0x565+2111-0xda4);i<zf91d71c6d9;i++){y=ssGetOutputPortSignal(S,i);while(!(za42cf7dd4a[(0xe1b+5285-0x22bd)]&65536));count=za42cf7dd4a[(0x814+7698-0x2624)]&65535;if(mxGetPr(z05e67510ff)[(0x8a+7292-0x1d06)]==(0x9a4+3920-0x18f4)){y[(0x6f+2723-0xb12)]=(real_T)count/z0754dd67cc-offset;}else
{if(mxGetPr(z0d9acd09bb)[(0x353+6102-0x1b29)]==(0x1790+1928-0x1f16))
{if(i<(0x1fa+38-0x210))y[(0x1138+1402-0x16b2)]=(real_T)count/z0754dd67cc-offset;else y[(0xd69+2732-0x1815)]=((real_T)count/z0754dd67cc-offset)*(0xb59+4803-0x1e16);}else
{if(i<(0x701+2094-0xf27))y[(0x1d55+1657-0x23ce)]=(real_T)count/z0754dd67cc-offset;else y[(0x2b9+3968-0x1239)]=((real_T)count/z0754dd67cc-offset)*(0x6d6+1191-0xb77);}}}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

