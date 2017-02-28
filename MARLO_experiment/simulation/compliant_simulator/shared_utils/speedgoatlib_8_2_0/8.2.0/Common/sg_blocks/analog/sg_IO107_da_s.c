/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x243+3909-0x1186)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO107_da_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x30\x37"
#define z694756a014 4277
#define zea87e0ba83 36950
#define z29146a1837 (0x16c0+2047-0xe0a)
#define zab7e64468b 12576
#define zdf24515981          ((0x772+5145-0x1b86))
#define z2b4281b393               ssGetSFcnParam(S,(0x12d8+3678-0x2136))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0x304+3937-0x1264))
#define z8fd86139be               ssGetSFcnParam(S,(0xd36+5858-0x2416))
#define z3832b85a32           ssGetSFcnParam(S,(0x122+9364-0x25b3))
#define z702a26a5e9                ssGetSFcnParam(S,(0x80f+4002-0x17ad))
#define z2e6483d505              ((0x1c1c+1751-0x22f1))
#define z7e2eeaa57c          ((0x4fc+8268-0x2548))
#define z6a0da049de         ((0x1675+1477-0x1c39))
#define zc5ce4cb81a              ((0xa64+4006-0x1a08))
#define z8caad2a8e6              ((0x5c3+7388-0x229f))
#define z5bfe7a2613            ((0x57f+2193-0xe0f))
#define z2b17e2ee3b              ((0xce5+4977-0x2056))
static char_T zea4cd01646[(0x1b62+2747-0x251d)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x3aa+4655-0x15d9));ssSetNumDiscStates(S,(0x13bc+674-0x165e));ssSetNumOutputPorts(S,(0x1f3+6324-0x1aa7));ssSetNumInputPorts(S,(int)mxGetN(za9d8fb6bcf));for(i=(0x49+2723-0xaec);i<(int)mxGetN(za9d8fb6bcf);i++){ssSetInputPortWidth(S,i,(0x1f5+7832-0x208c));ssSetInputPortDirectFeedThrough(S,i,(0x178a+467-0x195c));ssSetInputPortRequiredContiguous(S,i,(0x2fd+4146-0x132e));}ssSetNumSampleTimes(S,(0x16b8+1610-0x1d01));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xd9c+597-0xff1));ssSetNumNonsampledZCs(S,(0x19fa+2173-0x2277));for(i=(0x184f+2545-0x2240);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1568+1487-0x1b37));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x9b2+2031-0x11a1)]==-1.0){ssSetSampleTime(S,(0x921+711-0xbe8),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x15bf+1872-0x1d0f),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x19a3+1790-0x20a1),mxGetPr(z3832b85a32)[(0x994+5661-0x1fb1)]);ssSetOffsetTime(S,(0x5e8+2558-0xfe6),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;uint16_T zf91d71c6d9=(int)mxGetN(za9d8fb6bcf);real_T z19c4ca5f82,start;uint32_T range;if((int_T)mxGetPr(z702a26a5e9)[(0x591+7960-0x24a9)]<(0x13e8+96-0x1448)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xbf+3251-0xd71)){z366b2f03bf=(0x67f+8279-0x26d6);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x293+3012-0xe57)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x1fb6+537-0x21cf)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x674+391-0x7fa)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x12d1+4179-0x2225))|((z366b2f03bf&(0x367+786-0x57a))<<(0xc1a+1952-0x13b2)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x1bb0+279-0x1cc5)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x765+4131-0x1768),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,z7e2eeaa57c,zf91d71c6d9);switch((uint16_T)mxGetPr(z8fd86139be)[(0x981+6585-0x233a)]){case(0x8d4+5340-0x1daf):ssSetRWorkValue(S,z8caad2a8e6,3276.8);ssSetRWorkValue(S,z5bfe7a2613,10.0);range=(0x10d9+3660-0x1f22);break;case(0x122c+4859-0x2525):ssSetRWorkValue(S,z8caad2a8e6,6553.6);ssSetRWorkValue(S,z5bfe7a2613,5.0);range=(0x3ba+8068-0x233c);break;case(0x20b2+10-0x20b9):ssSetRWorkValue(S,z8caad2a8e6,13107.2);ssSetRWorkValue(S,z5bfe7a2613,2.5);range=(0xc03+88-0xc5a);break;case(0x133+1548-0x73b):ssSetRWorkValue(S,z8caad2a8e6,26214.4);ssSetRWorkValue(S,z5bfe7a2613,1.25);range=(0x1497+2452-0x1e2b);break;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T zf91d71c6d9=ssGetIWorkValue(S,z7e2eeaa57c);real_T z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6);real_T offset=ssGetRWorkValue(S,z5bfe7a2613);uint16_T i;volatile uint32_T*za42cf7dd4a;real_T*zc7fdaf6331;int32_T out;uint16_T z4e3026977c,index;real_T zd3add15c40,zbd0243c03e;uint16_T first=(0x7ca+2162-0x103b);real_T scale=3276.8;za42cf7dd4a=(void*)base;for(i=(0x113d+2813-0x1c3a);i<zf91d71c6d9;i++){index=(uint16_T)mxGetPr(z2b4281b393)[i]-(0x614+3116-0x123f);z4e3026977c=(uint16_T)mxGetPr(za9d8fb6bcf)[i]-(0x163c+3103-0x225a);zc7fdaf6331=(real_T*)ssGetInputPortRealSignal(S,index);out=(int32_T)((zc7fdaf6331[(0xc4a+347-0xda5)]+offset)*z0754dd67cc);if(out>65535)out=65535;if(out<(0x1644+3080-0x224c))out=(0x70c+5992-0x1e74);za42cf7dd4a[(0x1c93+660-0x1f21)]=out;}
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

