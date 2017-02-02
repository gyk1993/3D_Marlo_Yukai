/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xb98+4016-0x1b46)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO421_ref_s
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
#define zdf24515981              ((0xf0d+1763-0x15ec))
#define z86992bd6b1                 ssGetSFcnParam(S,(0x6b7+324-0x7fb))
#define zce920812fd                    ssGetSFcnParam(S,(0x2007+1044-0x241a))
#define z73855d5f1e                 ssGetSFcnParam(S,(0x1b76+2415-0x24e3))
#define z702a26a5e9                    ssGetSFcnParam(S,(0xc6d+5154-0x208c))
#define z2e6483d505              ((0x3e7+3575-0x11dc))
#define z7e2eeaa57c          ((0x13e0+4634-0x25fa))
#define z6a0da049de         ((0xab0+5703-0x20f6))
#define zc5ce4cb81a              ((0x307+3652-0x113b))
#define z2b17e2ee3b              ((0x1028+5777-0x26b9))
static char_T zea4cd01646[(0x1065+4185-0x1fbe)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x1961+240-0x1a51));ssSetNumDiscStates(S,(0x8e8+5867-0x1fd3));ssSetNumOutputPorts(S,(0x7ea+1161-0xc73));ssSetNumInputPorts(S,(0x73a+2783-0x1219));ssSetNumSampleTimes(S,(0x17e0+1864-0x1f27));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xe9d+3910-0x1de3));ssSetNumNonsampledZCs(S,(0x479+1543-0xa80));for(i=(0xc10+953-0xfc9);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x86+9109-0x241b));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x1e49+2225-0x26fa),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x443+8142-0x2411),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint16_T*za42cf7dd4a;uint32_T zd0072007fc;uint16_T z6f813cde47,za4a2434e08;real_T z4d7ed90f27,za2273a11ad;uint32_T zd4b3a173d5,z61ab524473;za4a2434e08=30354;z6f813cde47=5548;if((int_T)mxGetPr(z702a26a5e9)[(0x20b+5122-0x160d)]<(0x1929+2006-0x20ff)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x5b\x72\x65\x66\x5d\x20\x49\x4f\x34\x32\x32\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74");ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x2a3+4911-0x15d1)){z366b2f03bf=(0xbac+4058-0x1b86);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x502+4354-0x1604)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x156+3637-0xf8b)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x350+1980-0xb0b)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x39c+4120-0x12b5))|((z366b2f03bf&(0x1f11+2066-0x2624))<<(0x1b35+1870-0x227b)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x49\x4f\x34\x32\x31\x20\x52\x65\x66\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x5e2+1301-0xaf7)];Virtual=rl32eGetDevicePtr(z1cf2c50191,32768,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint16_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint_T)za42cf7dd4a);switch((uint32_T)mxGetPr(z86992bd6b1)[(0xd01+2372-0x1645)]){case(0x1a59+1684-0x20ec):zd0072007fc=(0x17aa+2688-0x222a);break;case(0x266+7453-0x1f81):zd0072007fc=(0x1016+6439-0x213d);break;case(0xbe6+6880-0x26c3):zd0072007fc=(0x1257+6865-0x1d28);break;}z4d7ed90f27=mxGetPr(zce920812fd)[(0x6f6+6721-0x2137)];z4d7ed90f27*=(0x1e6+6819-0x1c25);
zd4b3a173d5=(uint32_T)z4d7ed90f27;za42cf7dd4a[zd0072007fc/(0x6b5+94-0x711)+(0xec8+5091-0x20ab)/(0x195f+1539-0x1f60)]=(uint16_T)(zd4b3a173d5&65535);

za42cf7dd4a[zd0072007fc/(0x51f+2256-0xded)+(0x1143+259-0x1042)/(0x13ef+4160-0x242d)]=(uint16_T)((zd4b3a173d5>>(0x5c9+501-0x7ae))&65535);

za2273a11ad=mxGetPr(z73855d5f1e)[(0x1750+336-0x18a0)];za2273a11ad*=(0x1008+1517-0x1591);
z61ab524473=(uint32_T)za2273a11ad;za42cf7dd4a[zd0072007fc/(0x19a1+3350-0x26b5)+(0xadd+5665-0x1ef6)/(0x6f4+6679-0x2109)]=(uint16_T)(z61ab524473&65535);
za42cf7dd4a[zd0072007fc/(0x384+7404-0x206e)+(0x322+6860-0x1be2)/(0x19ca+1855-0x2107)]=(uint16_T)((z61ab524473>>(0x6fb+969-0xab4))&65535);
za42cf7dd4a[zd0072007fc/(0x15d1+3870-0x24ed)+(0x7b7+3519-0x13b6)/(0x334+6365-0x1c0f)]=(0xdd+6091-0x18a7);printf("\x4d\x6f\x64\x75\x6c\x65\x20\x57\x20\x64\x65\x73\x69\x67\x6e\x20\x76\x65\x72\x73\x69\x6f\x6e\x3a\x20\x30\x78\x25\x58" "\n",za42cf7dd4a[zd0072007fc/(0x997+3565-0x1782)+(0x237f+273-0x1d18)/(0xf57+2094-0x1783)]);printf("\x4d\x6f\x64\x75\x6c\x65\x20\x57\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x65\x64\x2e" "\n\n");
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE                 
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint16_T*za42cf7dd4a;uint16_T zd0072007fc;za42cf7dd4a=(uint16_T*)base;switch((uint32_T)mxGetPr(z86992bd6b1)[(0x18db+814-0x1c09)]){case(0x15b4+1780-0x1ca7):zd0072007fc=(0x627+6573-0x1fd4);break;case(0x1647+3387-0x2380):zd0072007fc=(0x2115+3266-0x25d7);break;case(0xc73+6163-0x2483):zd0072007fc=(0x208b+250-0x1185);break;}za42cf7dd4a[zd0072007fc/(0x16b+5987-0x18cc)+(0x78b+7438-0x22d9)/(0xf84+2331-0x189d)]=(0xfa1+5589-0x2576);
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

