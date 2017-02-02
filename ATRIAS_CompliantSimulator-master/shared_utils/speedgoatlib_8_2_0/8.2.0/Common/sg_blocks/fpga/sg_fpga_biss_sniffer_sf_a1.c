/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xcb2+2567-0x16b7)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_biss_sniffer_sf_a1
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
#define zdf24515981        ((0x68a+1547-0xc8e))
#define z533b11d03f         ssGetSFcnParam(S,  (0x1b4b+1288-0x2053)) 
#define za9d8fb6bcf           ssGetSFcnParam(S,  (0x1f6d+414-0x210a)) 
#define z3a4907dee5          ssGetSFcnParam(S,  (0x4ad+5437-0x19e8))
#define z3832b85a32         ssGetSFcnParam(S, (0xb62+4723-0x1dd2))
#define z702a26a5e9              ssGetSFcnParam(S, (0x1996+2766-0x2460))
#define z2641f02224      ssGetSFcnParam(S, (0x15d0+3218-0x225d))
#define z62e2a03dc6        ssGetSFcnParam(S, (0x1746+2805-0x2235))
#define z2e6483d505            ((0x114+7001-0x1c6c))
#define zc5ce4cb81a            ((0x11d9+3707-0x2054))
#define z2b17e2ee3b            ((0xa49+3308-0x1735))
#define z6a0da049de       ((0x1d2+6797-0x1c5f))
#define zbe5ecb87ad     (262144)
static char_T zea4cd01646[(0x15d6+1938-0x1c68)];typedef struct{uint32_T z15923ef3d9[(0x397+4294-0x143d)];uint32_T z42ad4eacaf[(0xed2+1497-0x148b)];uint32_T zfe18d134a8[(0x1be4+2031-0x23b3)];uint32_T z86bb419998[(0x1475+2192-0x1ce5)];uint32_T z08fefe38a9[(0xa95+6209-0x22b6)];uint32_T zb15396a870[(0xca3+967-0x104a)];uint32_T zdd951fbe16[(0x10c0+1322-0x15ca)];uint32_T z64fc736a62[(0x16c+6008-0x18c4)];uint32_T zaf2186d9ec[(0xc62+1417-0x11cb)];uint32_T z9773a1ff40[(0xce7+2516-0x169b)];uint32_T za9ab52ab4b[(0x11d0+3069-0x1dad)];uint32_T start;uint32_T z19690b6adb;uint32_T z73b6066883;}z7a6eea8a71;static void mdlInitializeSizes(SimStruct*S){uint32_T i,zbc7ebd0e53;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x40c+5183-0x184b));ssSetNumDiscStates(S,(0x1c0b+1696-0x22ab));zbc7ebd0e53=(uint32_T)mxGetN(za9d8fb6bcf);ssSetNumOutputPorts(S,zbc7ebd0e53);for(i=(0x1687+1778-0x1d79);i<zbc7ebd0e53;i++){ssSetOutputPortDataType(S,i,SS_UINT32);ssSetOutputPortWidth(S,i,(0x1d1+8883-0x2480));}ssSetNumSampleTimes(S,(0x1df0+1536-0x23ef));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x115f+1460-0x1713));ssSetNumNonsampledZCs(S,(0x3+3324-0xcff));for(i=(0x941+5484-0x1ead);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x107d+524-0x1289));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x14+7850-0x1ebe)]==-1.0){ssSetSampleTime(S,(0x504+7056-0x2094),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xf61+3744-0x1e01),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xc8+9692-0x26a4),mxGetPr(z3832b85a32)[(0xab3+3056-0x16a3)]);ssSetOffsetTime(S,(0x115b+2011-0x1936),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i,z4e3026977c,z4878a1852b;volatile z7a6eea8a71*z372c4452d9;uint8_T z16ba527520[(0xe48+3595-0x1c3f)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61,test=(0xa+9427-0x24dd),z19690b6adb=(0x11e4+2057-0x19ed),x=(0xa71+7037-0x25ee);z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x9b2+3743-0x1851)];z6f813cde47=z05b56d9d51=(0x1c1d+5215-0x19a7);switch(z78caf1ba61){case(0x94b+7628-0x25cc):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;break;default:sprintf(zea4cd01646,"\x62\x6f\x61\x72\x64\x20\x74\x79\x70\x65\x20\x69\x6e\x63\x6f\x72\x72\x65\x63\x74\x2e");ssSetErrorStatus(S,zea4cd01646);return;}if(mxGetN(z702a26a5e9)==(0xfe3+5051-0x239d)){z366b2f03bf=(0x146f+4681-0x26b8);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x11f5+3121-0x1e26)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x1fb+5327-0x16ca)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xc8d+4400-0x1dbc)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x1756+966-0x1b1a)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x19ff+867-0x1d60)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x164f+3512-0x2405)]);z372c4452d9=(z7a6eea8a71*)(zeccbadd9b3.VirtAddress[(0x1710+489-0x18f7)]+zbe5ecb87ad);if(!xpceIsModelInit()){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[(0xab0+3656-0x18f8)]-(0x2ed+3221-0xf81);switch((uint32_T)mxGetPr(z3a4907dee5)[(0x597+1262-0xa85)]){case(0x1319+2729-0x1dc1):z4878a1852b=(0xbab+1743-0x1261);
break;case(0xa71+5689-0x20a8):z4878a1852b=(0x13c8+4775-0x264e);
break;case(0x6c3+5053-0x1a7d):z4878a1852b=(0xfa0+1506-0x155b);
break;case(0x61d+2757-0x10de):z4878a1852b=(0x1156+5584-0x26fb);
break;}z372c4452d9->z15923ef3d9[z4e3026977c]=z4878a1852b;z372c4452d9->z9773a1ff40[z4e3026977c]=(uint32_T)mxGetPr(z2641f02224)[(0x930+1307-0xe4b)];z372c4452d9->za9ab52ab4b[z4e3026977c]=(uint32_T)mxGetPr(z62e2a03dc6)[(0x18e5+768-0x1be5)];
}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base,i,z26dbd73a5e=(0x954+5488-0x1ec4),z4e3026977c,binary,zf67c59be22;volatile z7a6eea8a71*z372c4452d9;uint32_T*out,z69a8079db8,za892a705b5=(0x1874+3191-0x24eb),x;
uint32_T z763a561972,error,zd5e842b8a2,z9b3fdb4ada,z583865a754,z85c31dfec3,z557c37979b,z8e7fa426ca,data1,z407efd0741[(0x10f5+5045-0x24a2)],zc5ac1d6073[(0x4dd+4954-0x182f)],*zbcc3fe600b;base=ssGetIWorkValue(S,z6a0da049de);z372c4452d9=(z7a6eea8a71*)(base+zbe5ecb87ad);z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[(0x1368+2704-0x1df8)]-(0xd26+4221-0x1da2);z407efd0741[(0x1617+696-0x18cf)]=z372c4452d9->z42ad4eacaf[z4e3026977c];z407efd0741[(0xe13+3638-0x1c48)]=z372c4452d9->zfe18d134a8[z4e3026977c];out=(uint32_T*)ssGetOutputPortSignal(S,(0xcfd+5215-0x215c));if((uint32_T)mxGetPr(z3a4907dee5)[(0x98+1052-0x4b4)]==(0xca2+4028-0x1c5b))
{z763a561972=((z407efd0741[(0xb33+1038-0xf40)]&(0x16f6+4060-0x25d3))<<(0x348+9053-0x268d))|((z407efd0741[(0x8f1+1546-0xefb)]&4294967040)>>(0x765+2505-0x1126));error=(z407efd0741[(0x8b+2123-0x8d6)]&(0x69b+1390-0xb89))>>(0xc08+284-0xd1d);zd5e842b8a2=(z407efd0741[(0xa07+3665-0x1858)]&(0x7b4+6271-0x1ff3))>>(0x11b2+5328-0x267c);z9b3fdb4ada=(z407efd0741[(0x1873+2156-0x20df)]&(0x8c4+4989-0x1c02));out[(0xc1a+4387-0x1d3d)]=z763a561972;out[(0x156a+3598-0x2377)]=error;out[(0x5d6+8318-0x2652)]=zd5e842b8a2;out[(0x666+1421-0xbf0)]=z9b3fdb4ada;}
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
