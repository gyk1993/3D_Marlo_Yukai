/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xb97+4117-0x1baa)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_ad_sf_a1
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
#define zdf24515981        ((0xcb0+4242-0x1d3c))
#define z533b11d03f         ssGetSFcnParam(S, (0x187a+1742-0x1f48)) 
#define za9d8fb6bcf           ssGetSFcnParam(S, (0x2036+63-0x2074)) 
#define z4eb7791e75     ssGetSFcnParam(S, (0xfc7+2289-0x18b6)) 
#define z8fd86139be             ssGetSFcnParam(S, (0x5bb+3474-0x134a))
#define z3832b85a32         ssGetSFcnParam(S, (0x15c3+4377-0x26d8))
#define z702a26a5e9              ssGetSFcnParam(S, (0xd3+785-0x3df))
#define z2e6483d505              ((0xfbc+5365-0x24b0))
#define z6a0da049de         ((0x1020+4332-0x210c))
#define zc5ce4cb81a              ((0x46b+8859-0x2704))
#define z8caad2a8e6              ((0x131d+2092-0x1b49))
#define z5bfe7a2613            ((0x261+1157-0x6e5))
#define z2b17e2ee3b              ((0x1b83+1492-0x2157))
#define zdeac5a1dc4                  (49152)
static char_T zea4cd01646[(0xc77+986-0xf51)];struct zfe084664e7{uint32_T z0754dd67cc;uint32_T zc78a7188e6;uint32_T zaf91a33927;uint32_T done;int32_T data[(0x220c+648-0x2484)];};static void mdlInitializeSizes(SimStruct*S){uint32_T i,za0df33019b;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xbac+742-0xe92));ssSetNumDiscStates(S,(0xa27+1173-0xebc));za0df33019b=(uint32_T)mxGetN(za9d8fb6bcf);ssSetNumOutputPorts(S,za0df33019b);
for(i=(0xbd3+3961-0x1b4c);i<za0df33019b;i++){ssSetOutputPortWidth(S,i,(0x16d9+1006-0x1ac6));}ssSetNumInputPorts(S,(0xcb3+274-0xdc5));ssSetNumSampleTimes(S,(0x255+8998-0x257a));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x10f1+301-0x121e));ssSetNumNonsampledZCs(S,(0x1e36+2030-0x2624));for(i=(0x88c+399-0xa1b);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x11dc+3285-0x1eb1));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x13e7+4599-0x25de)]==-1.0){ssSetSampleTime(S,(0xc70+6784-0x26f0),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x15c6+4119-0x25dd),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x76b+6718-0x21a9),mxGetPr(z3832b85a32)[(0x602+2069-0xe17)]);ssSetOffsetTime(S,(0x1df3+1371-0x234e),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint8_T z16ba527520[(0x6ef+6589-0x2098)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61;volatile struct zfe084664e7*z8a0c00cf66;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x7c0+2823-0x12c7)];z6f813cde47=z05b56d9d51=(0x2498+4371-0x1ed6);switch(z78caf1ba61){case(0x12eb+4455-0x2311):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;case(0x16ed+3547-0x237d):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;break;}switch((uint32_T)mxGetPr(z8fd86139be)[(0xc96+2286-0x1584)]){case(0x1765+2349-0x2091):
ssSetRWorkValue(S,z8caad2a8e6,3276.8);ssSetRWorkValue(S,z5bfe7a2613,10.24);break;case(0x1fcc+1083-0x2405):
ssSetRWorkValue(S,z8caad2a8e6,6553.6);ssSetRWorkValue(S,z5bfe7a2613,5.12);break;case(0x15d2+3374-0x22fd):
ssSetRWorkValue(S,z8caad2a8e6,13107.2);ssSetRWorkValue(S,z5bfe7a2613,2.56);break;case(0x721+7113-0x22e6):
ssSetRWorkValue(S,z8caad2a8e6,26214.4);ssSetRWorkValue(S,z5bfe7a2613,1.28);break;}if(mxGetN(z702a26a5e9)==(0x5d8+2579-0xfea)){z366b2f03bf=(0xc47+3081-0x1850);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xd9a+205-0xe67)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x371+5551-0x1920)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x6a5+3486-0x1442)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x6c6+4966-0x1a2a)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x9b4+257-0xab3)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x572+3716-0x13f4)]);z8a0c00cf66=(struct zfe084664e7*)(zeccbadd9b3.VirtAddress[(0x68f+6185-0x1eb6)]+zdeac5a1dc4);if(!xpceIsModelInit()){z8a0c00cf66->z0754dd67cc=(uint32_T)mxGetPr(z8fd86139be)[(0x1f26+638-0x21a4)]-(0x12f8+1543-0x18fe);
z8a0c00cf66->zaf91a33927=(uint32_T)mxGetPr(z4eb7791e75)[(0x6c4+6784-0x2144)]-(0x74+6676-0x1a87);
}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint32_T i,z4e3026977c,done;real_T*y;real_T z0754dd67cc,offset;volatile struct zfe084664e7*z8a0c00cf66=(struct zfe084664e7*)(base+zdeac5a1dc4);z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6);offset=ssGetRWorkValue(S,z5bfe7a2613);if((uint32_T)mxGetPr(z4eb7791e75)[(0x1043+4427-0x218e)]==(0x1a7+9379-0x2649))
{z8a0c00cf66->zc78a7188e6=(0x3a7+2553-0xd9f);z8a0c00cf66->zc78a7188e6=(0x698+1701-0xd3d);}
done=(0xaab+3574-0x18a1);for(i=(0x3c9+4276-0x147d);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1820+3158-0x2475);done|=((0xeaa+1681-0x153a)<<z4e3026977c);}
while((z8a0c00cf66->done&done)!=done);

for(i=(0x174d+214-0x1823);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xd7+2492-0xa92);y=(real_T*)ssGetOutputPortSignal(S,i);y[(0x1a1d+2265-0x22f6)]=(z8a0c00cf66->data[z4e3026977c]-32768)/z0754dd67cc;
}
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
