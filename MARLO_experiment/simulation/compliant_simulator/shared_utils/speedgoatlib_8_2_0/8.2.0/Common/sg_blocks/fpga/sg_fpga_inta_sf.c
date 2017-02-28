/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xb7b+2887-0x16c0)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_inta_sf
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
#include        "xpcPCFunctions.h"
#endif
#define zdf24515981              ((0x1248+4639-0x2461))
#define z533b11d03f               ssGetSFcnParam(S,(0x1614+3744-0x24b4))
#define z1120e7330e                ssGetSFcnParam(S,(0xba7+1312-0x10c6))
#define z644559a0a7                   ssGetSFcnParam(S,(0xd45+3057-0x1934))
#define ze9153280f8                ssGetSFcnParam(S,(0xc89+4443-0x1de1))
#define z702a26a5e9                    ssGetSFcnParam(S,(0x7e4+3852-0x16ec))
#define z3832b85a32               ssGetSFcnParam(S,(0x1ae4+2921-0x2648))
#define z2e6483d505              ((0x7c8+7670-0x25bc))
#define z7e2eeaa57c          ((0x12d3+1685-0x1968))
#define z6a0da049de         ((0xc1b+1213-0x10d7))
#define zc5ce4cb81a              ((0x184+4180-0x11c8))
#define z2b17e2ee3b              ((0x1403+419-0x15a6))
static char_T zea4cd01646[(0x5e1+3054-0x10cf)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x13a0+3343-0x20af));ssSetNumDiscStates(S,(0x230+1197-0x6dd));ssSetNumOutputPorts(S,(0x11b7+26-0x11d1));ssSetNumInputPorts(S,(0xd59+907-0x10e4));ssSetNumSampleTimes(S,(0x8e8+6142-0x20e5));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xd1f+5419-0x224a));ssSetNumNonsampledZCs(S,(0x16d5+1771-0x1dc0));for(i=(0x2118+1084-0x2554);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xbcc+961-0xf8d));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x1a96+823-0x1dcd)]==-1.0){ssSetSampleTime(S,(0x470+1869-0xbbd),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x15e3+106-0x164d),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x1822+3413-0x2577),mxGetPr(z3832b85a32)[(0x1071+50-0x10a3)]);ssSetOffsetTime(S,(0x7e9+2117-0x102e),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z7be9105675,z4e3026977c,val;real_T scale;uint8_T z16ba527520[(0x491+809-0x7a6)];uint16_T z6f813cde47,za4a2434e08;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x958+3413-0x16ad)];switch(z78caf1ba61){case(0x15bd+4007-0x2437):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");z6f813cde47=(0x17bf+2572-0xaf6);za4a2434e08=17232;break;case(0x261+2441-0xabc):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");z6f813cde47=(0x2497+2250-0x168c);za4a2434e08=17239;break;case(0x2d9+9370-0x2644):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");z6f813cde47=(0x2308+4523-0x1dde);za4a2434e08=16979;break;case(0x2b6+5134-0x1594):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");z6f813cde47=5845;za4a2434e08=(0x199f+4162-0x24dd);break;case(0xeea+5629-0x23b0):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");z6f813cde47=(0x24ea+503-0x100c);za4a2434e08=21069;break;case(0xa16+6673-0x22ef):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");z6f813cde47=(0x26c3+3821-0x1edb);za4a2434e08=16971;break;case(0x57a+955-0x7fc):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");z6f813cde47=(0x1a3b+2739-0xe19);za4a2434e08=17235;break;case(0xf35+6338-0x26bd):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");z6f813cde47=(0x1e90+2637-0x1208);za4a2434e08=8196;break;case(0x11e2+4659-0x22d4):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");z6f813cde47=(0x192d+4028-0x1214);za4a2434e08=19520;break;}if((int_T)mxGetPr(z702a26a5e9)[(0x594+6698-0x1fbe)]<(0xdd9+4515-0x1f7c)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x17f3+3298-0x24d4)){z366b2f03bf=(0xd77+1485-0x1344);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1039+162-0x10db)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x22c3+302-0x23f1)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xcf2+6063-0x24a0)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x382+8903-0x254a))|((z366b2f03bf&(0x1151+2339-0x1975))<<(0x649+3136-0x1281)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x10b2+4110-0x20be)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);if(!xpceIsModelInit()){val=(0x1b3+5298-0x1664);z7be9105675=mxGetPr(ze9153280f8)[(0xd64+3020-0x1930)];val=val|(z7be9105675<<(0x8eb+939-0xc95));z7be9105675=mxGetPr(z1120e7330e)[(0xb30+715-0xdfb)];val=val|(z7be9105675<<(0x6fa+6146-0x1efa));z7be9105675=mxGetPr(z644559a0a7)[(0x125a+2075-0x1a75)];val=val|(z7be9105675<<(0xe56+1651-0x14bd));
za42cf7dd4a[9984]=val;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE    
volatile uint32_T*za42cf7dd4a;uint32_T base=ssGetIWorkValue(S,z6a0da049de);za42cf7dd4a=(void*)base;
za42cf7dd4a[9985]=(0x411+7775-0x226f);za42cf7dd4a[9985]=(0xe02+4672-0x2042);
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
volatile uint32_T*za42cf7dd4a;uint32_T base=ssGetIWorkValue(S,z6a0da049de);za42cf7dd4a=(void*)base;
za42cf7dd4a[9985]=(0x1642+2651-0x209c);za42cf7dd4a[9985]=(0xc14+1508-0x11f8);za42cf7dd4a[9984]=(0x357+3426-0x10b9);
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

