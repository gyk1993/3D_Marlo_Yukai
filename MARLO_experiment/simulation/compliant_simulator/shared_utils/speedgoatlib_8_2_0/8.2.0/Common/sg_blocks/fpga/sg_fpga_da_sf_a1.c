/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x17b3+1760-0x1e91)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_da_sf_a1
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
#define zdf24515981        ((0x892+1222-0xd53))
#define z533b11d03f         ssGetSFcnParam(S, (0xf8+7141-0x1cdd)) 
#define za9d8fb6bcf           ssGetSFcnParam(S, (0x839+696-0xaf0)) 
#define z4eb7791e75     ssGetSFcnParam(S, (0x10a4+2968-0x1c3a)) 
#define z3832b85a32         ssGetSFcnParam(S, (0x718+5524-0x1ca9))
#define z702a26a5e9              ssGetSFcnParam(S, (0xc7+3216-0xd53))
#define z2e6483d505              ((0x8f+9163-0x2459))
#define zc5ce4cb81a              ((0x6d+1781-0x762))
#define z2b17e2ee3b              ((0x6d1+6533-0x2056))
#define z6a0da049de         ((0x129+4339-0x121c))
#define zf7dba45c7b                  (65536)
static char_T zea4cd01646[(0x20c6+873-0x232f)];struct z6e54179dbd{uint32_T zcbaef9b07f;uint32_T command;int32_T data[(0x8c7+5857-0x1fa0)];uint32_T zaf91a33927;uint32_T zc78a7188e6;};static void mdlInitializeSizes(SimStruct*S){uint32_T i,za0df33019b;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xc59+1771-0x1344));ssSetNumDiscStates(S,(0x1705+1163-0x1b90));za0df33019b=(uint32_T)mxGetN(za9d8fb6bcf);ssSetNumInputPorts(S,za0df33019b);
for(i=(0x15af+810-0x18d9);i<za0df33019b;i++){ssSetInputPortWidth(S,i,(0xfed+614-0x1252));ssSetInputPortDirectFeedThrough(S,i,(0xe93+5992-0x25fa));ssSetInputPortRequiredContiguous(S,i,(0xde5+3241-0x1a8d));}ssSetNumOutputPorts(S,(0x1a3c+1237-0x1f11));ssSetNumSampleTimes(S,(0xfa4+1842-0x16d5));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x10e3+3200-0x1d63));ssSetNumNonsampledZCs(S,(0x1df+2587-0xbfa));for(i=(0xdd+8891-0x2398);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x7c6+6033-0x1f57));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x41d+7064-0x1fb5)]==-1.0){ssSetSampleTime(S,(0x12d8+2092-0x1b04),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x4f0+8305-0x2561),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x752+4076-0x173e),mxGetPr(z3832b85a32)[(0xd76+3579-0x1b71)]);ssSetOffsetTime(S,(0x1c6+1186-0x668),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i;uint8_T z16ba527520[(0x624+5902-0x1d1e)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61,z4e3026977c,z4da0d16710;volatile struct z6e54179dbd*zf1756dff08;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x6b6+7599-0x2465)];z6f813cde47=z05b56d9d51=(0x1c75+5601-0x1b81);switch(z78caf1ba61){case(0x1b9f+2362-0x23ac):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");za4a2434e08=z182d03571c=17232;break;case(0x22d+2870-0xc35):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");za4a2434e08=z182d03571c=17239;break;case(0xfa2+1766-0x1559):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");za4a2434e08=z182d03571c=16979;break;case(0x32f+7852-0x20ab):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");za4a2434e08=z182d03571c=1284;break;case(0xedb+3630-0x1bd2):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");za4a2434e08=z182d03571c=21069;break;case(0x151b+3429-0x2148):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");za4a2434e08=z182d03571c=16971;break;case(0x79c+4006-0x1609):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");za4a2434e08=z182d03571c=17235;break;case(0xa3a+454-0xac6):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");za4a2434e08=z182d03571c=(0x2238+5632-0x1834);break;case(0x1fa0+1962-0x2609):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;case(0xd84+2605-0x1666):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;break;}if(mxGetN(z702a26a5e9)==(0xfad+3541-0x1d81)){z366b2f03bf=(0x14da+2286-0x1dc8);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x4f6+584-0x73e)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0xc44+2466-0x15e6)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x24a+8437-0x233e)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x1389+4284-0x2443)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x5e9+7194-0x2201)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0xb06+1645-0x1171)]);zf1756dff08=(struct z6e54179dbd*)(zeccbadd9b3.VirtAddress[(0xe19+6129-0x2608)]+zf7dba45c7b);if(!xpceIsModelInit()){z4da0d16710=(0x5a6+3184-0x1216);for(i=(0x220+4269-0x12cd);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xbfb+2639-0x1649);z4da0d16710|=((0xfc4+85-0x1018)<<z4e3026977c);}zf1756dff08->zaf91a33927=(uint32_T)mxGetPr(z4eb7791e75)[(0x540+4310-0x1616)]-(0x1aa3+802-0x1dc4);
zf1756dff08->zcbaef9b07f=z4da0d16710;
}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint32_T i,z4e3026977c;real_T*y;volatile struct z6e54179dbd*zf1756dff08=(struct z6e54179dbd*)(base+zf7dba45c7b);if((uint32_T)mxGetPr(z4eb7791e75)[(0x123a+4020-0x21ee)]==(0x1a20+556-0x1c4b)){zf1756dff08->zc78a7188e6=(0xa74+5074-0x1e45);zf1756dff08->zc78a7188e6=(0x151c+2438-0x1ea2);}for(i=(0x1528+1790-0x1c26);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1914+1436-0x1eaf);y=(real_T*)ssGetInputPortSignal(S,i);zf1756dff08->data[z4e3026977c]=(int32_T)(y[(0x436+5747-0x1aa9)]*32768.0/10.0);}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile struct z6e54179dbd*zf1756dff08=(struct z6e54179dbd*)(base+zf7dba45c7b);if(!xpceIsModelInit()){zf1756dff08->zcbaef9b07f=(0xf9f+1616-0x15ef);}
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif
