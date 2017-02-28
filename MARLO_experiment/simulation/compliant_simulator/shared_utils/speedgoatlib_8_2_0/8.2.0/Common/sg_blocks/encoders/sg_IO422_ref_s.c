/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xc69+569-0xea0)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO422_ref_s
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
#define zdf24515981              ((0x108d+2086-0x18af))
#define z86992bd6b1                 ssGetSFcnParam(S,(0x19e0+1865-0x2129))
#define zce920812fd                    ssGetSFcnParam(S,(0x5f3+8295-0x2659))
#define z73855d5f1e                 ssGetSFcnParam(S,(0xf25+1447-0x14ca))
#define z702a26a5e9                    ssGetSFcnParam(S,(0x92+3132-0xccb))
#define z2e6483d505              ((0x2086+269-0x2191))
#define z7e2eeaa57c          ((0x6dc+400-0x86c))
#define z6a0da049de         ((0x1045+693-0x12f9))
#define zc5ce4cb81a              ((0x1a0+7706-0x1faa))
#define z2b17e2ee3b              ((0x16f9+1051-0x1b14))
static char_T zea4cd01646[(0x1074+2399-0x18d3)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xa59+505-0xc52));ssSetNumDiscStates(S,(0x360+2616-0xd98));ssSetNumOutputPorts(S,(0x1a78+2894-0x25c6));ssSetNumInputPorts(S,(0xc7d+5764-0x2301));ssSetNumSampleTimes(S,(0x436+8877-0x26e2));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1f11+555-0x213c));ssSetNumNonsampledZCs(S,(0xb0c+5162-0x1f36));for(i=(0x579+3539-0x134c);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x4c2+4569-0x169b));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0xa7+7140-0x1c8b),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1907+2048-0x2107),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint16_T*za42cf7dd4a;uint32_T zd0072007fc;uint16_T z6f813cde47,za4a2434e08;real_T z4d7ed90f27,za2273a11ad;uint32_T zd4b3a173d5,z61ab524473;za4a2434e08=30099;z6f813cde47=(0x1b09+6183-0x1d84);if((int_T)mxGetPr(z702a26a5e9)[(0x10ed+3526-0x1eb3)]<(0x1570+2650-0x1fca)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x5b\x72\x65\x66\x5d\x20\x49\x4f\x34\x32\x32\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74");ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x649+3947-0x15b3)){z366b2f03bf=(0x54a+988-0x926);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x127+5023-0x14c6)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0xd76+1906-0x14e8)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xead+2829-0x19b9)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x1f48+1173-0x22de))|((z366b2f03bf&(0x1639+3220-0x21ce))<<(0x7c6+5299-0x1c71)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x5b\x72\x65\x66\x5d\x20\x37\x36\x43\x32\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x11cd+249-0x12c6)];Virtual=rl32eGetDevicePtr(z1cf2c50191,32768,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint16_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint_T)za42cf7dd4a);switch((uint32_T)mxGetPr(z86992bd6b1)[(0x6a+3787-0xf35)]){case(0xfd2+1052-0x13ed):zd0072007fc=(0x6b1+1084-0xaed);break;case(0x1fcd+1641-0x2634):zd0072007fc=(0x85c+3190-0xcd2);break;case(0x495+5146-0x18ac):zd0072007fc=(0x1af8+3082-0x1702);break;}z4d7ed90f27=mxGetPr(zce920812fd)[(0xc8+7899-0x1fa3)];z4d7ed90f27*=(0x102b+2607-0x19f6);
zd4b3a173d5=(uint32_T)z4d7ed90f27;za42cf7dd4a[zd0072007fc/(0x6cd+2047-0xeca)+(0xd2a+168-0xbd2)/(0x916+3981-0x18a1)]=(uint16_T)(zd4b3a173d5&65535);

za42cf7dd4a[zd0072007fc/(0x22c+8522-0x2374)+(0xf2b+1583-0x1356)/(0xf46+4296-0x200c)]=(uint16_T)((zd4b3a173d5>>(0xa7f+4192-0x1acf))&65535);

za2273a11ad=mxGetPr(z73855d5f1e)[(0x168a+3470-0x2418)];za2273a11ad*=(0x925+3360-0x15e1);
z61ab524473=(uint32_T)za2273a11ad;za42cf7dd4a[zd0072007fc/(0x1145+1336-0x167b)+(0xe4d+4758-0x1edb)/(0x2d+4380-0x1147)]=(uint16_T)(z61ab524473&65535);
za42cf7dd4a[zd0072007fc/(0x1589+3987-0x251a)+(0x14c4+4756-0x254c)/(0xc2+981-0x495)]=(uint16_T)((z61ab524473>>(0x6d6+3769-0x157f))&65535);
za42cf7dd4a[zd0072007fc/(0x68b+6655-0x2088)+(0x209+7172-0x1c4d)/(0x19bf+2425-0x2336)]=(0x23c+925-0x5d8);printf("\x4d\x6f\x64\x75\x6c\x65\x20\x57\x20\x64\x65\x73\x69\x67\x6e\x20\x76\x65\x72\x73\x69\x6f\x6e\x3a\x20\x30\x78\x25\x58" "\n",za42cf7dd4a[zd0072007fc/(0x85+6259-0x18f6)+(0xf6d+7943-0x26fc)/(0xfa+2332-0xa14)]);printf("\x4d\x6f\x64\x75\x6c\x65\x20\x57\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x65\x64\x2e" "\n\n");
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE                 
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint16_T*za42cf7dd4a;uint16_T zd0072007fc;za42cf7dd4a=(uint16_T*)base;switch((uint32_T)mxGetPr(z86992bd6b1)[(0x17b5+915-0x1b48)]){case(0x2534+252-0x262f):zd0072007fc=(0xe96+5501-0x2413);break;case(0xe18+2411-0x1781):zd0072007fc=(0x14af+3961-0x1c28);break;case(0x16+1718-0x6c9):zd0072007fc=4096;break;}za42cf7dd4a[zd0072007fc/(0x3ea+7136-0x1fc8)+(0x100c+4671-0x208b)/(0x23a7+322-0x24e7)]=(0x309+8712-0x2511);
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

