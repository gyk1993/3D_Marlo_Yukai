/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x2339+624-0x25a7)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO106_ad_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x30\x36"
#define z694756a014 (0x2670+3629-0x23e8)
#define zea87e0ba83 36950
#define z29146a1837 (0x1836+2650-0x11db)
#define zab7e64468b 12545
#define zdf24515981          ((0xbd7+3873-0x1af3))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0x5a5+513-0x7a6))
#define z8fd86139be               ssGetSFcnParam(S,(0x11f0+5017-0x2588))
#define z8e37b80355            ssGetSFcnParam(S,(0x24d+3742-0x10e9))
#define z3832b85a32           ssGetSFcnParam(S,(0x71b+2045-0xf15))
#define z702a26a5e9                ssGetSFcnParam(S,(0x12eb+3472-0x2077))
#define z2e6483d505              ((0x1655+715-0x191e))
#define z6a0da049de         ((0x13ea+4052-0x23be))
#define zc2f3e0cbc0        ((0x10f2+4865-0x23f2))
#define zc5ce4cb81a              ((0x3c7+7735-0x21fc))
#define z8caad2a8e6              ((0x13f6+860-0x1752))
#define z5bfe7a2613            ((0x519+724-0x7ec))
#define z2b17e2ee3b              ((0xcd9+95-0xd38))
static char_T zea4cd01646[(0x1063+3386-0x1c9d)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xad6+4972-0x1e42));ssSetNumDiscStates(S,(0x1c84+1764-0x2368));ssSetNumInputPorts(S,(0x178a+2313-0x2093));ssSetNumOutputPorts(S,(0x598+773-0x89c));switch((uint32_T)mxGetPr(z8e37b80355)[(0xe8f+3060-0x1a83)]){case(0x65d+2753-0x111d):
ssSetOutputPortWidth(S,(0xf4d+1518-0x153b),(uint32_T)mxGetPr(za9d8fb6bcf)[(0x136c+715-0x1637)]);break;case(0xc80+2573-0x168b):
ssSetOutputPortWidth(S,(0xb02+6953-0x262b),(uint32_T)mxGetPr(za9d8fb6bcf)[(0x607+843-0x952)]-(0xde0+1356-0x132b));break;case(0x1867+2114-0x20a6):
ssSetOutputPortWidth(S,(0x65a+2415-0xfc9),(uint32_T)mxGetPr(za9d8fb6bcf)[(0x7c1+10-0x7cb)]);break;}ssSetNumSampleTimes(S,(0x5cb+5629-0x1bc7));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x2336+777-0x263f));ssSetNumNonsampledZCs(S,(0x190f+1029-0x1d14));for(i=(0xd14+5235-0x2187);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1c22+2084-0x2446));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x270+1506-0x852)]==-1.0){ssSetSampleTime(S,(0x557+6101-0x1d2c),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x17f9+336-0x1949),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x1753+71-0x179a),mxGetPr(z3832b85a32)[(0x138+6161-0x1949)]);ssSetOffsetTime(S,(0x1d1f+1689-0x23b8),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T range,out;uint16_T z4e3026977c;uint32_T zf91d71c6d9=(uint32_T)mxGetPr(za9d8fb6bcf)[(0x1362+570-0x159c)];if((int_T)mxGetPr(z702a26a5e9)[(0xa38+3420-0x1794)]<(0x20ed+556-0x2319)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x122d+1799-0x1933)){z366b2f03bf=(0x10b9+327-0x1200);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x148b+333-0x15d8)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x4a7+8050-0x2419)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x655+5065-0x1a1d)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x12a4+3548-0x1f81))|((z366b2f03bf&(0xc53+4207-0x1bc3))<<(0x659+6287-0x1ee0)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0xc45+4942-0x1f91)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x1f16+1679-0x2525),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,zc2f3e0cbc0,(uint32_T)zf91d71c6d9);switch((uint32_T)mxGetPr(z8fd86139be)[(0x1822+2992-0x23d2)]){case(0x72c+164-0x7cf):
ssSetRWorkValue(S,z8caad2a8e6,3276.8);ssSetRWorkValue(S,z5bfe7a2613,10.0);break;case(0xaed+1479-0x10b2):
ssSetRWorkValue(S,z8caad2a8e6,6553.6);ssSetRWorkValue(S,z5bfe7a2613,5.0);break;case(0x35+1595-0x66d):
ssSetRWorkValue(S,z8caad2a8e6,13107.2);ssSetRWorkValue(S,z5bfe7a2613,2.5);break;case(0x18fa+3265-0x25b7):
ssSetRWorkValue(S,z8caad2a8e6,6553.6);ssSetRWorkValue(S,z5bfe7a2613,0.0);break;case(0xb47+1210-0xffc):
ssSetRWorkValue(S,z8caad2a8e6,13107.2);ssSetRWorkValue(S,z5bfe7a2613,0.0);break;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T zf91d71c6d9=ssGetIWorkValue(S,zc2f3e0cbc0);volatile uint32_T*za42cf7dd4a;uint32_T z8b9d33e44f=(uint32_T)mxGetPr(z8e37b80355)[(0x32f+6488-0x1c87)];real_T*y,z0754dd67cc,offset;uint32_T i;uint32_T count;za42cf7dd4a=(void*)base;za42cf7dd4a[(0x909+66-0x94b)]=za42cf7dd4a[(0x140c+548-0x1630)]|4096;y=ssGetOutputPortSignal(S,(0x45c+7828-0x22f0));z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6);offset=ssGetRWorkValue(S,z5bfe7a2613);i=(0x1983+1960-0x212b);
while(!(za42cf7dd4a[(0x3e6+819-0x716)]&524288))i++;

count=za42cf7dd4a[(0x11e7+5044-0x2599)];if(count!=65537){printf("\x73\x6f\x6d\x65\x74\x68\x69\x6e\x67\x20\x73\x74\x72\x61\x6e\x67\x65" "\n");}for(i=(0xded+3692-0x1c59);i<zf91d71c6d9/(0x575+6309-0x1e18);i++){
count=za42cf7dd4a[(0x588+3114-0x11b0)];if(z8b9d33e44f==(0x174+977-0x543)){if(i==(0xae7+3188-0x175b)){y[(0x581+2068-0xd94)+i*(0x59b+1860-0xcdd)-(0x8d9+2691-0x135b)]=2.0*((real_T)((count&4294901760)>>(0xa42+2932-0x15a6))/z0754dd67cc-offset);}else{y[(0x651+7407-0x2340)+i*(0x59+4752-0x12e7)-(0x1148+3967-0x20c6)]=2.0*((real_T)(count&65535)/z0754dd67cc-offset);y[(0x92f+3483-0x16c9)+i*(0x181b+301-0x1946)-(0x11af+5157-0x25d3)]=2.0*((real_T)((count&4294901760)>>(0x1c60+1996-0x241c))/z0754dd67cc-offset);}}else{if(z8b9d33e44f==(0x170a+3185-0x2378)){y[(0xa34+1384-0xf9c)+i*(0x1cc4+907-0x204d)]=2.0*((real_T)(count&65535)/z0754dd67cc-offset);y[(0x12c7+3365-0x1feb)+i*(0x1be2+1191-0x2087)]=2.0*((real_T)((count&4294901760)>>(0x636+5971-0x1d79))/z0754dd67cc-offset);}else{y[(0xbd4+5158-0x1ffa)+i*(0x1704+1248-0x1be2)]=(real_T)(count&65535)/z0754dd67cc-offset;y[(0x269+827-0x5a3)+i*(0x15f5+1166-0x1a81)]=(real_T)((count&4294901760)>>(0x7aa+891-0xb15))/z0754dd67cc-offset;}}}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

