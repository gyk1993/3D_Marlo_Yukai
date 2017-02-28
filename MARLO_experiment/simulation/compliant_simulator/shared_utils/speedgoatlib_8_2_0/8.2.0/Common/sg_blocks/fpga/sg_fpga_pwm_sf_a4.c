/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xd33+5819-0x23ec)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_pwm_sf_a4
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
#define zdf24515981        ((0x10bc+4537-0x225e))
#define z533b11d03f         ssGetSFcnParam(S,  (0x33f+2000-0xb0f)) 
#define za9d8fb6bcf           ssGetSFcnParam(S,  (0x1362+4446-0x24bf)) 
#define z01bb085356         ssGetSFcnParam(S,  (0xb3b+6258-0x23ab))
#define z8e1815e073             ssGetSFcnParam(S,  (0x454+3084-0x105d))
#define zbfd84bbef9             ssGetSFcnParam(S,  (0x13ba+3281-0x2087))
#define z8944e1fed9             ssGetSFcnParam(S,  (0x53d+6498-0x1e9a))
#define zc74c85e681           ssGetSFcnParam(S,  (0x844+6026-0x1fc8))
#define z311fbc5bad           ssGetSFcnParam(S,  (0x1daa+20-0x1db7))
#define za04af20061           ssGetSFcnParam(S,  (0xf79+3152-0x1bc1))
#define za9b36fc92d            ssGetSFcnParam(S,  (0x969+366-0xace))
#define z2d3e9570ac           ssGetSFcnParam(S, (0x16ab+614-0x1907))
#define z1240a5c516          ssGetSFcnParam(S, (0x1b2+7697-0x1fb8))
#define z718df4ebba           ssGetSFcnParam(S, (0x183a+2262-0x2104))
#define zf303968f76          ssGetSFcnParam(S, (0xa2d+1669-0x10a5))
#define z6c8b14d68e           ssGetSFcnParam(S, (0x1310+3260-0x1fbe))
#define zc36a3da4ad          ssGetSFcnParam(S, (0x7f1+6883-0x22c5))
#define zeac6896859        ssGetSFcnParam(S, (0x33+7790-0x1e91))
#define z2dceaadc0f         ssGetSFcnParam(S, (0x6f4+344-0x83b))
#define z502d9ed0cf             ssGetSFcnParam(S, (0xd2b+547-0xf3c))
#define z1918c3f4db             ssGetSFcnParam(S, (0xcc9+1617-0x1307))
#define zc6c46560aa             ssGetSFcnParam(S, (0x1110+2231-0x19b3))
#define z3832b85a32         ssGetSFcnParam(S, (0xd17+4619-0x1f0d))
#define z702a26a5e9              ssGetSFcnParam(S, (0x557+7414-0x2237))
#define z2e6483d505              ((0x7c5+248-0x8bc))
#define zc5ce4cb81a              ((0x1e91+638-0x210f))
#define z2b17e2ee3b              ((0x10d2+3547-0x1ead))
#define z6a0da049de         ((0x5eb+1054-0xa09))
#define z0f9ded0223              (98304)
static char_T zea4cd01646[(0x7f1+8196-0x26f5)];typedef struct{uint32_T z4da0d16710;uint32_T z2f1801d2e2;uint32_T z8db8bb5a06;uint32_T zee8378496a;uint32_T z37cfa98aaf;uint32_T ze7198b4532;uint32_T zba6c56af50;uint32_T zf30711d604[(0x1a87+898-0x1de9)];uint32_T z6756646a81[(0x440+3120-0x1050)];uint32_T z9ca0045836[(0x1df0+1704-0x2478)];uint32_T z8e8b32e98e[(0x1150+776-0x1438)];uint32_T z886a62b902[(0x1870+235-0x193b)];uint32_T protection[(0x333+6955-0x1e3e)];uint32_T z7211d763fb[(0xecf+5077-0x2284)];uint32_T z64b63d5c98[(0x65b+4103-0x1642)];uint32_T z3144e9a755[(0x4a0+4504-0x1618)];}z8dc61d99bb;static void mdlInitializeSizes(SimStruct*S){uint32_T i,zbc7ebd0e53,width;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xb31+465-0xd02));ssSetNumDiscStates(S,(0x11bd+3363-0x1ee0));width=(uint32_T)mxGetN(za9d8fb6bcf);zbc7ebd0e53=(0xd3a+338-0xe8c);if((uint32_T)mxGetPr(z01bb085356)[(0x8bb+2067-0x10ce)]==(0xeb+4084-0x10de)){if((uint32_T)mxGetPr(z8e1815e073)[(0x96a+5939-0x209d)]){zbc7ebd0e53+=(0x479+981-0x84d);}if((uint32_T)mxGetPr(zbfd84bbef9)[(0x964+70-0x9aa)]){zbc7ebd0e53+=(0x84b+12-0x856);}}else{if((uint32_T)mxGetPr(z8e1815e073)[(0x1984+2712-0x241c)]){zbc7ebd0e53+=(0x11d+457-0x2e4);}if((uint32_T)mxGetPr(zbfd84bbef9)[(0xc59+2634-0x16a3)]){zbc7ebd0e53+=(0xa53+2747-0x150c);}}if((uint32_T)mxGetPr(z8944e1fed9)[(0xd18+2646-0x176e)]){zbc7ebd0e53+=(0x3b9+1222-0x87d);}ssSetNumInputPorts(S,zbc7ebd0e53);
for(i=(0x224c+813-0x2579);i<zbc7ebd0e53;i++){ssSetInputPortWidth(S,i,width);ssSetInputPortDirectFeedThrough(S,i,(0x1b75+1840-0x22a4));ssSetInputPortRequiredContiguous(S,i,(0x1843+1626-0x1e9c));}ssSetNumOutputPorts(S,(0xee9+6168-0x2701));ssSetNumSampleTimes(S,(0x962+6270-0x21df));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x7d5+3911-0x171c));ssSetNumNonsampledZCs(S,(0xb2f+4533-0x1ce4));for(i=(0x1cec+1882-0x2446);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1278+4979-0x25eb));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x876+1526-0xe6c)]==-1.0){ssSetSampleTime(S,(0x2159+348-0x22b5),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1441+3406-0x218f),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x7bd+1583-0xdec),mxGetPr(z3832b85a32)[(0x83a+2165-0x10af)]);ssSetOffsetTime(S,(0x20b2+784-0x23c2),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i,z4e3026977c,z4da0d16710,z8db8bb5a06,zee8378496a,z37cfa98aaf;volatile z8dc61d99bb*z9e95a8730f;uint8_T z16ba527520[(0x88+8607-0x2213)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x120+1387-0x68b)];z6f813cde47=z05b56d9d51=(0x25f6+5691-0x255c);switch(z78caf1ba61){case(0xf6c+5995-0x258c):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;break;default:sprintf(zea4cd01646,"\x62\x6f\x61\x72\x64\x20\x74\x79\x70\x65\x20\x69\x6e\x63\x6f\x72\x72\x65\x63\x74\x2e");ssSetErrorStatus(S,zea4cd01646);return;}if(mxGetN(z702a26a5e9)==(0x1be7+522-0x1df0)){z366b2f03bf=(0x2458+14-0x2466);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x1634+3285-0x2309)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x9d5+2112-0x1215)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x127c+1410-0x17fd)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x11cb+3839-0x20c8)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x11b8+1107-0x1609)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x942+2034-0x1132)]);z9e95a8730f=(z8dc61d99bb*)(zeccbadd9b3.VirtAddress[(0x193f+1725-0x1ffa)]+z0f9ded0223);if(!xpceIsModelInit()){}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
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
