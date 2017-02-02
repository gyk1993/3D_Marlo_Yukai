/* Copyright 2006-2013 Speedgoat GmbH. */
#define   S_FUNCTION_LEVEL  (0x55d+7687-0x2362)
#undef    S_FUNCTION_NAME
#define   S_FUNCTION_NAME   sg_fpga_zoh_sf
#include  <stddef.h>
#include  <stdlib.h>
#include  "simstruc.h" 
#ifdef    MATLAB_MEX_FILE
#include  "mex.h"
#endif
#ifndef         MATLAB_MEX_FILE
#include        <windows.h>
#include        "io_xpcimport.h"
#include        "pci_xpcimport.h"
#include        "time_xpcimport.h"
#include        "ioext_xpcimport.h"
#include        "util_xpcimport.h"
#endif
#define zdf24515981        ((0x97d+4680-0x1bc0))
#define z533b11d03f         ssGetSFcnParam(S, (0x1276+3402-0x1fc0)) 
#define z8ba1fe7533         ssGetSFcnParam(S, (0x192+6316-0x1a3d))
#define zeea69c2a77          ssGetSFcnParam(S, (0x2131+798-0x244d))
#define z3832b85a32         ssGetSFcnParam(S, (0x163a+3417-0x2390))
#define z702a26a5e9              ssGetSFcnParam(S, (0xde6+1448-0x138a))
#define z2e6483d505            ((0x92c+3452-0x16a7))
#define zc5ce4cb81a            ((0x584+3864-0x149c))
#define z2b17e2ee3b            ((0x25f+143-0x2ee))
#define z6a0da049de       ((0x12ad+3518-0x206b))
#define z893ab0b362              (917504)
static char_T zea4cd01646[(0x1497+1094-0x17dd)];typedef struct{uint32_T z4da0d16710;uint32_T z9341690719;uint32_T ze52a206df7;uint32_T zb22eccca44;uint32_T version;uint32_T revision;}z73fe6fa671;static void mdlInitializeSizes(SimStruct*S){uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x52+6763-0x1abd));ssSetNumDiscStates(S,(0xe80+3804-0x1d5c));ssSetNumInputPorts(S,(0x107+2146-0x969));ssSetNumOutputPorts(S,(0x4c3+3622-0x12e9));ssSetNumSampleTimes(S,(0x597+26-0x5b0));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x201+4891-0x151c));ssSetNumNonsampledZCs(S,(0x470+6798-0x1efe));for(i=(0x1341+3734-0x21d7);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x8a1+5425-0x1dd2));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0xbc3+2076-0x13df)]==-1.0){ssSetSampleTime(S,(0xcbb+2966-0x1851),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1fd7+330-0x2121),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x86d+6365-0x214a),mxGetPr(z3832b85a32)[(0x114b+5322-0x2615)]);ssSetOffsetTime(S,(0x1cff+947-0x20b2),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;volatile z73fe6fa671*z6df8338ca7;uint8_T z16ba527520[(0xf6d+2206-0x17f7)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x1553+179-0x1606)];z6f813cde47=z05b56d9d51=5845;switch(z78caf1ba61){case(0xd50+3213-0x18b0):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");za4a2434e08=z182d03571c=17232;break;case(0xb51+2776-0x14fb):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");za4a2434e08=z182d03571c=17239;break;case(0x47a+5398-0x1861):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");za4a2434e08=z182d03571c=16979;break;case(0xaaf+2710-0x1415):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");za4a2434e08=z182d03571c=(0x1d8c+695-0x1b3f);break;case(0x81d+2361-0x101f):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");za4a2434e08=z182d03571c=21069;break;case(0xaa1+7386-0x2643):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");za4a2434e08=z182d03571c=16971;break;case(0x2d1+9563-0x26f3):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");za4a2434e08=z182d03571c=17235;break;case(0x432+7863-0x21af):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");za4a2434e08=z182d03571c=(0x2058+416-0x1f4);break;case(0x1817+3716-0x255a):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;case(0x5a9+1877-0xbb3):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;break;default:sprintf(zea4cd01646,"\x62\x6f\x61\x72\x64\x20\x74\x79\x70\x65\x20\x69\x6e\x63\x6f\x72\x72\x65\x63\x74\x2e");ssSetErrorStatus(S,zea4cd01646);return;}if(mxGetN(z702a26a5e9)==(0x2d7+906-0x660)){z366b2f03bf=(0x102+1721-0x7bb);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xd5+8382-0x2193)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x1a2+5104-0x1592)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x10fd+4088-0x20f4)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x1e48+585-0x208f)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x163+11-0x16c)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0xbd5+3550-0x19b1)]);z6df8338ca7=(z73fe6fa671*)(zeccbadd9b3.VirtAddress[(0x355+5569-0x1914)]+z893ab0b362);if(!xpceIsModelInit()){z6df8338ca7->ze52a206df7=(uint32_T)(mxGetPr(zeea69c2a77)[(0x9b8+1861-0x10fd)]*33000000.0);printf("\x64\x65\x6c\x61\x79\x4d\x69\x6e\x3a\x20\x25\x64" "\n",(uint32_T)(mxGetPr(zeea69c2a77)[(0xab+1648-0x71b)]*33000000.0));printf("\x64\x65\x6c\x61\x79\x4d\x69\x6e\x3a\x20\x25\x64" "\n",z6df8338ca7->ze52a206df7);z6df8338ca7->zb22eccca44=(uint32_T)(mxGetPr(z3832b85a32)[(0x3b4+3862-0x12ca)]*33000000.0);printf("\x73\x61\x6d\x70\x6c\x65\x54\x69\x6d\x65\x3a\x20\x25\x64" "\n",z6df8338ca7->zb22eccca44);z6df8338ca7->z9341690719=(uint32_T)(mxGetPr(z8ba1fe7533)[(0xdd6+1896-0x153e)]);z6df8338ca7->z4da0d16710=(0x1e19+936-0x21c0);printf("\x65\x6e\x61\x62\x6c\x65\x3a\x20\x25\x64" "\n",z6df8338ca7->z4da0d16710);printf("\x76\x65\x72\x73\x69\x6f\x6e\x3a\x20\x25\x64" "\n",z6df8338ca7->version);printf("\x72\x65\x76\x69\x73\x69\x6f\x6e\x3a\x20\x25\x64" "\n",z6df8338ca7->revision);}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE                       
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE     
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile z73fe6fa671*z6df8338ca7=(z73fe6fa671*)(base+z893ab0b362);z6df8338ca7->z4da0d16710=(0x1232+40-0x125a);
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif
