/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xb48+4626-0x1d58)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO401_setup_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x34\x30\x31"
#define z694756a014 (0x186a+7389-0x20af)
#define zea87e0ba83 (0x101+8246-0x20c2)
#define zdf24515981          ((0xee3+5533-0x246e))
#define z2881f1949c               ssGetSFcnParam(S,(0xc8d+1580-0x12b9))
#define z702a26a5e9                ssGetSFcnParam(S,(0x287+5322-0x1750))
#define za42e288061                ssGetSFcnParam(S,(0x945+5650-0x1f55))
#define z659ae1646b          ssGetSFcnParam(S,(0x15da+1441-0x1b78))
#define ze9153280f8            ssGetSFcnParam(S,(0x84f+5875-0x1f3e))
#define zabba59fab9           ssGetSFcnParam(S,(0x333+2946-0xeb0))
#define z2b4281b393               ssGetSFcnParam(S,(0x563+6745-0x1fb6))
#define zd92d0f9975             ssGetSFcnParam(S,(0x1b01+2512-0x24ca))
#define z91e3a5ec2f             ssGetSFcnParam(S,(0x9ab+6945-0x24c4))
#define z5ba474b8b4            ssGetSFcnParam(S,(0x8c+5885-0x1780))
#define za532a604a6                ssGetSFcnParam(S,(0x469+7028-0x1fd3))
#define zc94290e6d7             ssGetSFcnParam(S,(0xacd+1136-0xf32))
#define z9ec704f025            ssGetSFcnParam(S,(0xb4+2987-0xc53))
#define zfc3bd23d10           ssGetSFcnParam(S,(0x491+741-0x769))
#define z0678e4e8a5           ssGetSFcnParam(S,(0x110b+2449-0x1a8e))
#define z344539cf87       ssGetSFcnParam(S,(0x161c+3388-0x2349))
#define z1ac6f595c9      ssGetSFcnParam(S,(0x330+3610-0x113a))
#define z686b33c197        ssGetSFcnParam(S,(0x100f+5148-0x241a))
#define z2e6483d505              ((0x293+6808-0x1d29))
#define z6a0da049de         ((0x113b+503-0x1332))
#define zc2f3e0cbc0        ((0x2f5+2067-0xb07))
#define zc5ce4cb81a              ((0x32a+3230-0xfc6))
#define z8caad2a8e6              ((0x1115+3345-0x1e26))
#define z5bfe7a2613            ((0x10dd+2034-0x18ce))
#define z2b17e2ee3b              ((0x679+2598-0x109f))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0x1ad9+2149-0x223e)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x278+6239-0x1ad7));ssSetNumDiscStates(S,(0x1ca3+2043-0x249e));ssSetNumInputPorts(S,(0x33c+4292-0x1400));ssSetNumOutputPorts(S,(0x1042+5744-0x26b2));ssSetNumSampleTimes(S,(0x19c5+2456-0x235c));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x168+1313-0x689));ssSetNumNonsampledZCs(S,(0x14c1+1102-0x190f));for(i=(0x621+621-0x88e);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xd3+6038-0x1869));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0xfe1+5872-0x26d1),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x923+6471-0x226a),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zef529fae4a;void*ze2370ae9b9;volatile uint32_T*z3e5b8e05d8;void*zdfcb1da404;void*zf2db5722bf;volatile uint32_T*z27fd94ac66;uint_T i;uint32_T z4e3026977c,global;real_T z19c4ca5f82,start;if((int_T)mxGetPr(z702a26a5e9)[(0xe3+515-0x2e6)]<(0xbb6+1810-0x12c8)){
if(rl32eGetPCIInfo((uint16_T)z694756a014,(uint16_T)zea87e0ba83,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{int_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xa26+1206-0xedb)){z366b2f03bf=(0x16dc+1593-0x1d15);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x33b+634-0x5b5)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x497+8267-0x24e2)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x1f21+1588-0x2554)];}
if(rl32eGetPCIInfoAtSlot((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(z441f9e6d1b&(0x131+4247-0x10c9))|((z366b2f03bf&(0x140d+1784-0x1a06))<<(0x148d+3813-0x236a)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zef529fae4a=(void*)zeccbadd9b3.BaseAddress[(0x12e8+4765-0x2585)];ze2370ae9b9=rl32eGetDevicePtr(zef529fae4a,(0xdba+2019-0x139d),RT_PG_USERREADWRITE);z3e5b8e05d8=(volatile uint32_T*)ze2370ae9b9;zdfcb1da404=(void*)zeccbadd9b3.BaseAddress[(0x6b0+4206-0x171c)];zf2db5722bf=rl32eGetDevicePtr(zdfcb1da404,(0x354+7340-0x1f00),RT_PG_USERREADWRITE);z27fd94ac66=(volatile uint32_T*)zf2db5722bf;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)z27fd94ac66);

z3e5b8e05d8[(0xdf8+1931-0x1579)]=z3e5b8e05d8[(0x464+2095-0xc89)]&4278190079;
for(i=(0x14b8+2027-0x1ca3);i<(0x3b6+7358-0x206e);i++){z4e3026977c=(0x12b7+361-0x1420);
z4e3026977c|=(((uint32_T)mxGetPr(z686b33c197)[i])-(0x745+6519-0x20bc))<<(0x1764+1553-0x1d75);z4e3026977c|=(((uint32_T)mxGetPr(z1ac6f595c9)[i])-(0x1bdb+1353-0x2123))<<(0x1d3+1747-0x8a0);z4e3026977c|=(((uint32_T)mxGetPr(z344539cf87)[i])-(0x609+426-0x7b2))<<(0xf41+4056-0x1f14);z4e3026977c|=(((uint32_T)mxGetPr(z0678e4e8a5)[i])-(0x8b8+610-0xb19))<<(0x51f+7929-0x2414);z4e3026977c|=(((uint32_T)mxGetPr(zfc3bd23d10)[i])-(0x10d1+237-0x11bd))<<(0x2d9+5767-0x1959);z4e3026977c|=(((uint32_T)mxGetPr(z9ec704f025)[i])-(0x1683+2843-0x219e))<<(0x1bf5+2050-0x23ef);z4e3026977c|=(((uint32_T)mxGetPr(zc94290e6d7)[i])-(0x11e2+742-0x14c7))<<(0x11e5+3897-0x2110);

if((uint32_T)mxGetPr(za42e288061)[i]==(0x2321+684-0x25cc)){
z4e3026977c|=((((uint32_T)mxGetPr(z659ae1646b)[i])-(0x857+3883-0x1781))|(0x1feb+1800-0x26ee))<<(0xab5+1086-0xee3);}z4e3026977c|=(((uint32_T)mxGetPr(zabba59fab9)[i])-(0x21b+4007-0x11c1))<<(0x9b7+6022-0x212a);z4e3026977c|=(((uint32_T)mxGetPr(zd92d0f9975)[i])-(0xebb+1593-0x14f3))<<(0x136b+1841-0x1a87);z4e3026977c|=(((uint32_T)mxGetPr(z2b4281b393)[i])-(0xe18+2760-0x18df))<<(0x779+3304-0x144a);z4e3026977c|=(((uint32_T)mxGetPr(ze9153280f8)[i])-(0x826+6200-0x205d))<<(0xc54+6293-0x24cf);z4e3026977c|=(((uint32_T)mxGetPr(ze9153280f8)[i])-(0x9d5+1537-0xfd5))<<(0xd61+2954-0x18d0);z4e3026977c|=(((uint32_T)mxGetPr(ze9153280f8)[i])-(0xb68+5489-0x20d8))<<(0x185+8203-0x2174);z27fd94ac66[(0x2113+253-0x2210)+i*(0x15+1524-0x603)]=z4e3026977c;
}
global=(0x8a0+435-0xa53);for(i=(0x525+3805-0x1402);i<(0x693+7328-0x232d);i++){if((uint32_T)mxGetPr(za42e288061)[i]==(0x12b0+3519-0x206e)){
global|=(0x5c1+1102-0xa0d)<<(i*(0x446+7831-0x22db));
}else{global|=(0xd60+3275-0x1a2a)<<(i*(0x43b+8207-0x2448));
}}
for(i=(0x628+2200-0xec0);i<(uint32_T)mxGetN(z2881f1949c);i++){z4e3026977c=(uint32_T)mxGetPr(z2881f1949c)[i]-(0x1c2b+1328-0x215a);global|=(0x1d99+1883-0x24f3)<<((0x2260+118-0x22c4)+z4e3026977c);}z27fd94ac66[(0x19b+753-0x464)]=global;

for(i=(0x1bea+1790-0x22e8);i<(0x1c9c+523-0x1ea1);i++){z27fd94ac66[(0x720+417-0x8be)+i*(0x420+873-0x783)]=(uint32_T)mxGetPr(z91e3a5ec2f)[i];}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T i;volatile uint32_T*z27fd94ac66;z27fd94ac66=(void*)base;for(i=(0x47c+6194-0x1cae);i<(0x3a6+6604-0x1d6c);i++){if(xpceIsModelInit()&&(int)mxGetPr(z5ba474b8b4)[i]){z27fd94ac66[(0xaab+249-0xb9f)+i*(0xbcf+3830-0x1abf)]=(0x1514+852-0x1866);}if((int)mxGetPr(za532a604a6)[i]){z27fd94ac66[(0x368+4964-0x16c7)+i*(0x579+3126-0x11a9)]=(0xf92+3152-0x1be0);}}
#endif    
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

