/* Copyright 2006-2013 Speedgoat GmbH. */
#define S_FUNCTION_LEVEL (0xda0+3319-0x1a95)
#undef S_FUNCTION_NAME
#define S_FUNCTION_NAME sg_IO601_status_s_3
#include <stddef.h>
#include <stdlib.h>
#include "simstruc.h"
#ifdef MATLAB_MEX_FILE
#include "mex.h"
#endif
#ifndef MATLAB_MEX_FILE
#include <windows.h>
#include "io_xpcimport.h"
#include "pci_xpcimport.h"
#include "time_xpcimport.h"
#include "ioext_xpcimport.h"
#include "util_xpcimport.h"
#endif
#define zdf24515981         ((0xa4b+3757-0x18f6))
#define z3832b85a32          ssGetSFcnParam(S,(0xe6+2024-0x8ce))
#define z702a26a5e9               ssGetSFcnParam(S,(0xf41+1822-0x165e))
#define zf1b619edf2                "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x36\x30\x31"
#define z694756a014               ((0x1763+3425-0x140f))
#define zea87e0ba83               (36912)
#define z29146a1837            ((0x1265+6218-0x19fa))
#define zab7e64468b            (10615)
#define z2e6483d505             ((0x299+2190-0xb26))
#define z99799387bd        ((0xbb8+329-0xd01))
#define zc5ce4cb81a             ((0x1748+1588-0x1d7c))
static char_T zea4cd01646[(0x4f6+3086-0x1004)];typedef struct{uint16_T z2f2c9bdf0c;uint16_T z48732c8016;uint16_T z01ed36fba7;uint16_T z14a34f26e8;uint16_T za8729768cd;uint16_T z3d18fd88af;}z09285759dc;static void mdlInitializeSizes(SimStruct*S){int_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x71+7637-0x1e46));ssSetNumDiscStates(S,(0x799+6162-0x1fab));ssSetNumInputPorts(S,(0x1135+2471-0x1adc));ssSetNumOutputPorts(S,(0xc9d+1134-0x1105));ssSetOutputPortWidth(S,(0x416+2799-0xf05),(0x985+1522-0xf76));ssSetOutputPortWidth(S,(0x1644+2033-0x1e34),(0x51b+4691-0x176d));ssSetOutputPortWidth(S,(0x9aa+2893-0x14f5),(0x255+394-0x3de));ssSetOutputPortWidth(S,(0x4bf+3027-0x108f),(0x9ec+2821-0x14f0));ssSetOutputPortWidth(S,(0x3a5+5374-0x189f),(0xa08+6992-0x2557));ssSetOutputPortWidth(S,(0xf5f+3468-0x1ce6),(0x12da+4867-0x25dc));ssSetNumSampleTimes(S,(0x2b2+1009-0x6a2));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,(0x26f+7268-0x1ed3));ssSetNumModes(S,(0x196d+2966-0x2503));ssSetNumNonsampledZCs(S,(0x1a8b+2044-0x2287));for(i=(0x113+7006-0x1c71);i<zdf24515981;i++){ssSetSFcnParamNotTunable(S,i);}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x186+1-0x187),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x5b7+2257-0xe88),0.0);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;volatile z09285759dc*status;if(mxGetN(z702a26a5e9)==(0xb4f+6562-0x24f0)){z366b2f03bf=(0x450+3412-0x11a4);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x10eb+2880-0x1c2b)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0xecd+5377-0x23ce)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x19d9+1958-0x217e)];}if(xpcGetPCIDeviceInfo(z694756a014,zea87e0ba83,z29146a1837,zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x114c+391-0x12d3)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x5b7+3626-0x13e1)],zeccbadd9b3.Length[(0x1f7d+408-0x2115)],XPC_RT_PG_USERREADWRITE);zeccbadd9b3.VirtAddress[(0x678+5085-0x1a53)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x25b+8370-0x230b)],zeccbadd9b3.Length[(0xd10+6056-0x24b6)],XPC_RT_PG_USERREADWRITE);
status=(volatile z09285759dc*)(zeccbadd9b3.VirtAddress[(0x770+4938-0x1ab8)]);ssSetIWorkValue(S,z99799387bd,zeccbadd9b3.VirtAddress[(0x1541+834-0x1881)]);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE  
uint32_T base;volatile z09285759dc*status;real_T*out;volatile uint8_T*z27fd94ac66;z27fd94ac66=(void*)ssGetIWorkValue(S,z99799387bd);z27fd94ac66[8192]=(0x188b+1194-0x1d35);if(z27fd94ac66[8192]!=(0xb53+3922-0x1aa5)){z27fd94ac66[8192]=(0xc81+6643-0x2673);
return;}base=ssGetIWorkValue(S,z99799387bd);status=(z09285759dc*)(base+(0x19d2+465-0xbb3));out=(real_T*)ssGetOutputPortSignal(S,(0x4f9+6043-0x1c94));out[(0x741+7444-0x2455)]=status->z2f2c9bdf0c;out=(real_T*)ssGetOutputPortSignal(S,(0x606+1255-0xaec));out[(0x13a2+579-0x15e5)]=status->z48732c8016;out=(real_T*)ssGetOutputPortSignal(S,(0x523+7779-0x2384));out[(0x10e1+3782-0x1fa7)]=status->z01ed36fba7;out=(real_T*)ssGetOutputPortSignal(S,(0x781+5921-0x1e9f));out[(0x89f+538-0xab9)]=status->z14a34f26e8;out=(real_T*)ssGetOutputPortSignal(S,(0xffc+3367-0x1d1f));out[(0x558+2596-0xf7c)]=status->za8729768cd;out=(real_T*)ssGetOutputPortSignal(S,(0xa93+6328-0x2346));out[(0x4db+6527-0x1e5a)]=status->z3d18fd88af;z27fd94ac66[8192]=(0x1132+5249-0x25b2);
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE      
#endif 
}
#ifdef  MATLAB_MEX_FILE    
#include "simulink.c"      
#else
#include "cg_sfun.h"       
#endif
