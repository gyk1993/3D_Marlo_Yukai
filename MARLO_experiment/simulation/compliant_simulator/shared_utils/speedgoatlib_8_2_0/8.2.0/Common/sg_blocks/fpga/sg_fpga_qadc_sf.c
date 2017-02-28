/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x768+1750-0xe3c)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_qadc_sf
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
#define zdf24515981          ((0x6ea+2313-0xfe9))
#define z75204e189b             ssGetSFcnParam(S,(0x1759+651-0x19e4))
#define z702a26a5e9                ssGetSFcnParam(S,(0x1118+3845-0x201c))
#define z19087bd486          ssGetSFcnParam(S,(0x422+811-0x74b))
#define z3b23451ce3    ssGetSFcnParam(S,(0x434+8309-0x24a6))
#define z985e5b754b    ssGetSFcnParam(S,(0x418+5219-0x1877))
#define z10dce3de38               ssGetSFcnParam(S,(0x13bb+22-0x13cc))
#define z6729b77e5a        ssGetSFcnParam(S,(0x22f+1035-0x634))
#define z1120e7330e            ssGetSFcnParam(S,(0x2d8+8102-0x2277))
#define z86e9a7b867         ssGetSFcnParam(S,(0x269+2683-0xcdc))
#define z533b11d03f           ssGetSFcnParam(S,(0x281+8477-0x2395))
#define z2e6483d505              ((0x464+3745-0x1303))
#define z7e2eeaa57c          ((0x1119+2475-0x1ac4))
#define z6a0da049de         ((0xafd+6622-0x24da))
#define zc5ce4cb81a              ((0xe27+3466-0x1ba1))
#define z2b17e2ee3b              ((0x1293+2015-0x1a72))
static char_T zea4cd01646[(0x429+5404-0x1845)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xa29+2479-0x13d8));ssSetNumDiscStates(S,(0x204+5390-0x1712));ssSetNumOutputPorts(S,(0xe8f+1922-0x1611));ssSetNumInputPorts(S,(0x1cf4+671-0x1f93));ssSetNumSampleTimes(S,(0x1212+4811-0x24dc));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xf39+4366-0x2047));ssSetNumNonsampledZCs(S,(0x276+9258-0x26a0));for(i=(0x13c4+3329-0x20c5);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1fa+3306-0xee4));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x2fc+8191-0x22fb),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x266+9364-0x26fa),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint8_T z16ba527520[(0x1732+2749-0x21db)];uint16_T z6f813cde47,za4a2434e08;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0xae6+2913-0x1647)];switch(z78caf1ba61){case(0x467+36-0x35e):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");z6f813cde47=5845;za4a2434e08=17232;break;case(0x51f+759-0x6e8):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");z6f813cde47=(0x2178+6194-0x22d5);za4a2434e08=17239;break;case(0x1765+3776-0x24f6):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");z6f813cde47=(0x190f+3220-0xece);za4a2434e08=16979;break;case(0x1285+890-0x14cf):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");z6f813cde47=(0x17ea+171-0x1c0);za4a2434e08=(0x16a3+3262-0x1e5d);break;case(0xc21+926-0xe88):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");z6f813cde47=5845;za4a2434e08=21069;break;case(0x16ff+3380-0x22fb):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");z6f813cde47=(0x16e0+8389-0x20d0);za4a2434e08=16971;break;case(0x9e2+1558-0xebf):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");z6f813cde47=(0x243f+1829-0x148f);za4a2434e08=17235;break;case(0xfb1+500-0x106b):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");z6f813cde47=(0x17ab+2337-0x9f7);za4a2434e08=(0x22d1+6118-0x1ab3);break;case(0xdb4+2149-0x14d8):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");z6f813cde47=5845;za4a2434e08=19520;break;}
if((int_T)mxGetPr(z702a26a5e9)[(0xba0+2716-0x163c)]<(0xc75+1997-0x1442)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x49\x6e\x63\x72\x45\x6e\x63\x6f\x64\x65\x72\x20\x53\x65\x74\x75\x70\x20\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xe09+2876-0x1944)){z366b2f03bf=(0xb0b+3114-0x1735);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x60+252-0x15c)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x391+6853-0x1e56)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x9bd+6519-0x2333)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x1e54+2254-0x2623))|((z366b2f03bf&(0x149a+1360-0x18eb))<<(0xaaf+3656-0x18ef)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0xed9+3949-0x1e44)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T i;volatile uint32_T*z2afed1cdc6;uint32_T z52754d10b7,z65fe40fb3c,z4da0d16710;z2afed1cdc6=(void*)base;z65fe40fb3c=(0x656+3736-0x14ee);z52754d10b7=(0x9e3+1575-0x100a);z4da0d16710=(0x158b+3585-0x238c);for(i=(0x4d6+1374-0xa34);i<(uint32_T)mxGetPr(z75204e189b)[(0x1cd+3266-0xe8f)];i++){z52754d10b7=mxGetPr(z19087bd486)[i];
z52754d10b7|=((uint32_T)(mxGetPr(z3b23451ce3)[i])<<(0x1827+1448-0x1dcd));
z52754d10b7|=((uint32_T)(mxGetPr(z985e5b754b)[i])<<(0x1481+3622-0x22a3));z2afed1cdc6[9728+i]=z52754d10b7;if((uint32_T)mxGetPr(z3b23451ce3)[i]==(0x1b2a+2927-0x2698)){
z2afed1cdc6[9760+i]=(0x12f8+4991-0x2677);}else{z2afed1cdc6[9760+i]=(uint32_T)mxGetPr(z10dce3de38)[i];}
z65fe40fb3c|=((uint32_T)mxGetPr(z86e9a7b867)[i])<<(0x2c6+4033-0x1285)*i;
z4da0d16710|=(0x1cb+6246-0x1a30)<<i;
z2afed1cdc6[9792+i]=(uint32_T)mxGetPr(z6729b77e5a)[i];}z2afed1cdc6[9904]=z65fe40fb3c;
z2afed1cdc6[9906]=z4da0d16710;z2afed1cdc6[9906]=(0x76d+3748-0x1611);
z2afed1cdc6[9892]=z4da0d16710;
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

