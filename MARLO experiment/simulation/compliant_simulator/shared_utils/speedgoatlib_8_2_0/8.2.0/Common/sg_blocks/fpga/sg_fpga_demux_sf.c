/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x109f+5007-0x242c)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_demux_sf
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
#define zdf24515981        ((0x312+7805-0x2189))
#define z533b11d03f         ssGetSFcnParam(S, (0x6aa+2555-0x10a5)) 
#define za9d8fb6bcf           ssGetSFcnParam(S, (0xe2f+2837-0x1943)) 
#define z3a4907dee5          ssGetSFcnParam(S, (0x1200+4244-0x2292))
#define zb0ce0940e9         ssGetSFcnParam(S, (0x1715+555-0x193d))
#define z3832b85a32         ssGetSFcnParam(S, (0x554+5417-0x1a79))
#define z702a26a5e9              ssGetSFcnParam(S, (0x48b+4630-0x169c))
#define z2e6483d505            ((0x490+7080-0x2037))
#define zc5ce4cb81a            ((0xda3+3837-0x1ca0))
#define z2b17e2ee3b            ((0x1305+1348-0x1849))
#define z6a0da049de       ((0x1f51+381-0x20ce))
#define zf55b7c20c2            (983040)
#define z9b67aa523f              (851968)
static char_T zea4cd01646[(0x1bc+3351-0xdd3)];typedef struct{uint32_T sel[(0x746+4889-0x1a3f)];uint32_T z19690b6adb;}z797f7486dd;typedef struct{uint32_T z15923ef3d9[(0x1393+2332-0x1c8f)];uint32_T za746b13f73[(0x18e3+1967-0x2072)];uint32_T z02bb7b1721[(0x125d+4535-0x23f4)];uint32_T z1ad71181ab[(0x911+3940-0x1855)];uint32_T z2681ed6ece[(0xc25+2180-0x1489)];uint32_T z28e9d9261f[(0x16a2+311-0x17b9)];uint32_T z42ad4eacaf[(0x5d1+4314-0x168b)];uint32_T zfe18d134a8[(0x9b9+2580-0x13ad)];uint32_T z86bb419998[(0x216+5608-0x17de)];uint32_T z08fefe38a9[(0xc22+3674-0x1a5c)];uint32_T zb15396a870[(0x1235+4607-0x2414)];uint32_T zdd951fbe16[(0x1278+1603-0x189b)];uint32_T z64fc736a62[(0x3db+8502-0x24f1)];uint32_T zaf2186d9ec[(0xf63+2718-0x19e1)];uint32_T z2ae1a9d412[(0x1457+1869-0x1b84)];uint32_T z07f373fbd4[(0x90a+193-0x9ab)];uint32_T zac3cadef55[(0x10ff+1296-0x15ef)];uint32_T za3910307c9[(0xcb2+4126-0x1cb0)];uint32_T zd176e82c10[(0xe9d+668-0x1119)];uint32_T z4ae288e0c9[(0x414+499-0x5e7)];uint32_T z12402c138a[(0x17f6+3757-0x2683)];uint32_T z8575031947[(0x1982+2997-0x2517)];uint32_T zf64b65d5a7;uint32_T z2f1801d2e2;uint32_T zbea4a89f24;uint32_T zdc0d676974;uint32_T z556bd4727a;uint32_T z19690b6adb;uint32_T z73b6066883;}z69e58993ac;
static void mdlInitializeSizes(SimStruct*S){uint32_T i,zbc7ebd0e53;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x1913+1880-0x206b));ssSetNumDiscStates(S,(0x283+9114-0x261d));zbc7ebd0e53=(0x1b81+2414-0x24ee);ssSetNumInputPorts(S,zbc7ebd0e53);for(i=(0x13e5+736-0x16c5);i<zbc7ebd0e53;i++){ssSetInputPortDataType(S,i,SS_UINT32);ssSetInputPortWidth(S,i,(0x1aed+2124-0x2338));ssSetInputPortDirectFeedThrough(S,i,(0x960+2255-0x122e));ssSetInputPortRequiredContiguous(S,i,(0x1433+2311-0x1d39));}ssSetNumSampleTimes(S,(0x121f+4958-0x257c));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1a41+1371-0x1f9c));ssSetNumNonsampledZCs(S,(0x933+2158-0x11a1));for(i=(0x520+1030-0x926);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x13f2+3223-0x2089));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0xb66+6776-0x25de)]==-1.0){ssSetSampleTime(S,(0x11dc+4109-0x21e9),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1500+2369-0x1e41),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x16a2+1191-0x1b49),mxGetPr(z3832b85a32)[(0x7ea+7625-0x25b3)]);ssSetOffsetTime(S,(0x2035+1687-0x26cc),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;volatile z797f7486dd*z0caa4df534;uint8_T z16ba527520[(0x136f+2585-0x1d74)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x96a+1275-0xe65)];z6f813cde47=z05b56d9d51=(0x2335+6692-0x2684);switch(z78caf1ba61){case(0x173b+2990-0x21b2):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");za4a2434e08=z182d03571c=21069;break;default:sprintf(zea4cd01646,"\x62\x6f\x61\x72\x64\x20\x74\x79\x70\x65\x20\x69\x6e\x63\x6f\x72\x72\x65\x63\x74\x2e");ssSetErrorStatus(S,zea4cd01646);return;}if(mxGetN(z702a26a5e9)==(0x1f1+4107-0x11fb)){z366b2f03bf=(0xcf6+2099-0x1529);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x449+5124-0x184d)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x226+6913-0x1d27)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x1ba8+2865-0x26d8)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x365+4620-0x156f)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0xfa8+1322-0x14d0)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0xf92+949-0x1345)]);z0caa4df534=(z797f7486dd*)(zeccbadd9b3.VirtAddress[(0xb59+3165-0x17b4)]+zf55b7c20c2);



if(!xpceIsModelInit()){}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
volatile z797f7486dd*z0caa4df534;volatile z69e58993ac*zedf7516ada;uint32_T*in;uint32_T base,i,z4e3026977c,za746b13f73,z15923ef3d9;base=ssGetIWorkValue(S,z6a0da049de);z0caa4df534=(z797f7486dd*)(base+zf55b7c20c2);zedf7516ada=(z69e58993ac*)(base+z9b67aa523f);z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[(0x6e7+3052-0x12d3)]-(0xbbf+5044-0x1f72);
in=(uint32_T*)ssGetInputPortSignal(S,(0x1066+2435-0x19e9));
z0caa4df534->sel[z4e3026977c]=in[(0xacb+4760-0x1d63)];

zedf7516ada->za746b13f73[z4e3026977c]=(uint32_T)mxGetPr(zb0ce0940e9)[(0x341+6879-0x1e20)];zedf7516ada->z15923ef3d9[z4e3026977c]=(uint32_T)mxGetPr(z3a4907dee5)[(0x5a1+7814-0x2427)];
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
