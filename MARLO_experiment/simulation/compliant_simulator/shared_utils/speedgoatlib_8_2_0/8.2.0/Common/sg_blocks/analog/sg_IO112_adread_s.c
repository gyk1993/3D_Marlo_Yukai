/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1aa0+773-0x1da3)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO112_adread_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x31\x32"
#define z694756a014 (0x120a+695-0x40c)
#define zea87e0ba83 36950
#define z29146a1837 (0x14af+3461-0x117f)
#define zab7e64468b 13361
#define zdf24515981          ((0x1785+1880-0x1ed6))
#define za8bff65d14              ssGetSFcnParam(S,(0x1584+2333-0x1ea1))
#define z04bce731b0             ssGetSFcnParam(S,(0x1802+116-0x1875))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0x4f3+588-0x73d))
#define z8fd86139be               ssGetSFcnParam(S,(0x252+2852-0xd73))
#define z19087bd486          ssGetSFcnParam(S,(0xa85+6656-0x2481))
#define z3832b85a32           ssGetSFcnParam(S,(0x295+1445-0x835))
#define z702a26a5e9                ssGetSFcnParam(S,(0x2226+1157-0x26a5))
#define z2e6483d505              ((0xcf2+2978-0x1892))
#define z6a0da049de         ((0x4f+8303-0x20be))
#define zc2f3e0cbc0        ((0x135d+4922-0x2696))
#define zc5ce4cb81a              ((0xc1a+1427-0x11ab))
#define z8caad2a8e6              ((0xe34+2831-0x1943))
#define z5bfe7a2613            ((0x830+2133-0x1084))
#define z2b17e2ee3b              ((0x128+9250-0x254a))
static char_T zea4cd01646[(0x1e35+2430-0x26b3)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x5c8+7636-0x239c));ssSetNumDiscStates(S,(0x3bd+7257-0x2016));if(!(boolean_T)mxGetPr(z04bce731b0)[(0x52b+6899-0x201e)]){ssSetNumOutputPorts(S,(0x8b9+2885-0x13fd));

ssSetOutputPortWidth(S,(0x5d9+4392-0x1701),(uint32_T)mxGetPr(za9d8fb6bcf)[(0x1c79+634-0x1ef3)]);







}else{ssSetNumOutputPorts(S,(0x1cfb+2003-0x24cc));ssSetOutputPortDataType(S,(0x90a+573-0xb47),SS_BOOLEAN);ssSetOutputPortWidth(S,(0x9ed+6343-0x22b4),(0xd4+2480-0xa83));

ssSetOutputPortWidth(S,(0x656+3154-0x12a7),(uint32_T)mxGetPr(za9d8fb6bcf)[(0x665+7095-0x221c)]);







}if(!(boolean_T)mxGetPr(za8bff65d14)[(0xb+3651-0xe4e)]){ssSetNumInputPorts(S,(0x38b+3856-0x129b));}else{ssSetNumInputPorts(S,(0x380+909-0x70c));ssSetInputPortDirectFeedThrough(S,(0x97f+641-0xc00),(0x521+5162-0x194a));ssSetInputPortWidth(S,(0xfb0+4727-0x2227),(0xa2+759-0x398));ssSetInputPortDataType(S,(0xc95+1552-0x12a5),SS_BOOLEAN);ssSetInputPortRequiredContiguous(S,(0xe57+375-0xfce),(0xb17+688-0xdc6));}ssSetNumSampleTimes(S,(0x1f0c+1625-0x2564));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x23b+4184-0x1293));ssSetNumNonsampledZCs(S,(0x4f8+6440-0x1e20));for(i=(0x16bc+2165-0x1f31);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x2a3+3438-0x1011));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x1bbd+2638-0x260b)]==-1.0){ssSetSampleTime(S,(0x429+6394-0x1d23),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xf76+3197-0x1bf3),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x635+6329-0x1eee),mxGetPr(z3832b85a32)[(0x19dd+9-0x19e6)]);ssSetOffsetTime(S,(0x175b+593-0x19ac),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T range,out;uint16_T z4e3026977c;uint32_T zf91d71c6d9=(uint32_T)mxGetPr(za9d8fb6bcf)[(0x140f+2524-0x1deb)];if((int_T)mxGetPr(z702a26a5e9)[(0xda0+2594-0x17c2)]<(0x168+949-0x51d)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x8cc+5407-0x1dea)){z366b2f03bf=(0xb63+6232-0x23bb);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x81+5985-0x17e2)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x840+363-0x9ab)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1725+1093-0x1b69)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x2c4+7665-0x1fb6))|((z366b2f03bf&(0x136b+4345-0x2365))<<(0x1aaa+2747-0x255d)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0xabd+345-0xc14)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x62c+754-0x89e),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,zc2f3e0cbc0,(uint32_T)zf91d71c6d9);
if((uint32_T)mxGetPr(z19087bd486)[(0x71a+2889-0x1263)]==(0x931+2582-0x1346)){
switch((uint32_T)mxGetPr(z8fd86139be)[(0x116f+1583-0x179e)]){case(0xde0+5963-0x252a):
ssSetRWorkValue(S,z8caad2a8e6,13107.15);ssSetRWorkValue(S,z5bfe7a2613,10.0);break;case(0x16c6+1880-0x1e1c):
ssSetRWorkValue(S,z8caad2a8e6,26214.3);ssSetRWorkValue(S,z5bfe7a2613,5.0);break;}}else{
switch((uint32_T)mxGetPr(z8fd86139be)[(0x14cb+4218-0x2545)]){case(0xd1+9513-0x25f9):
ssSetRWorkValue(S,z8caad2a8e6,3276.8);ssSetRWorkValue(S,z5bfe7a2613,10.0);break;case(0x1c2a+2771-0x26fb):
ssSetRWorkValue(S,z8caad2a8e6,6553.6);ssSetRWorkValue(S,z5bfe7a2613,5.0);break;}}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T zf91d71c6d9=ssGetIWorkValue(S,zc2f3e0cbc0);volatile uint32_T*za42cf7dd4a;uint32_T z32b35fb51b=(uint32_T)mxGetPr(z19087bd486)[(0x400+8631-0x25b7)];real_T*y,z0754dd67cc,offset;uint32_T i;uint32_T count;uint32_T z4314ccb6ec=(0xf6b+5121-0x236c);boolean_T*z0daf90e5e1;boolean_T enabled=true;
if((int)mxGetPr(za8bff65d14)[(0x2367+880-0x26d7)]){z0daf90e5e1=(boolean_T*)ssGetInputPortSignal(S,(0x22a5+1055-0x26c4));enabled=z0daf90e5e1[(0x28f+8934-0x2575)];}if((int)mxGetPr(z04bce731b0)[(0x99a+3529-0x1763)]){z0daf90e5e1=(boolean_T*)ssGetOutputPortSignal(S,(0x147f+2448-0x1e0f));z0daf90e5e1[(0xf61+179-0x1014)]=enabled;z4314ccb6ec=(0x16a8+3056-0x2297);}za42cf7dd4a=(void*)base;y=ssGetOutputPortSignal(S,z4314ccb6ec);z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6);offset=ssGetRWorkValue(S,z5bfe7a2613);if(enabled){i=(0x1595+2033-0x1d86);
while(!(za42cf7dd4a[(0x896+1970-0x1045)]&524288))i++;
if(z32b35fb51b==(0x192d+532-0x1b40)){
for(i=(0xac4+4778-0x1d6e);i<zf91d71c6d9;i++){
count=za42cf7dd4a[(0x53f+1692-0xbd9)];
y[i]=(real_T)(count&262143)/z0754dd67cc-offset;}}else{

count=za42cf7dd4a[(0x1228+4497-0x23b7)];if(count!=65537){printf("\x73\x6f\x6d\x65\x74\x68\x69\x6e\x67\x20\x73\x74\x72\x61\x6e\x67\x65" "\n");}for(i=(0x24b+778-0x555);i<zf91d71c6d9/(0x14f9+733-0x17d4);i++){
count=za42cf7dd4a[(0x1c5+7647-0x1fa2)];
y[(0x143+8888-0x23fb)+i*(0x103c+3973-0x1fbf)]=(real_T)(count&65535)/z0754dd67cc-offset;y[(0x16+8180-0x2009)+i*(0xb92+150-0xc26)]=(real_T)((count&4294901760)>>(0xd5+2252-0x991))/z0754dd67cc-offset;}}}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

