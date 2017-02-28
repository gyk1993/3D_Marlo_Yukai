/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x39+6596-0x19fb)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_i2cmread_sf_a1
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
#define zdf24515981        ((0x79f+5824-0x1e59))
#define z533b11d03f         ssGetSFcnParam(S, (0x1eef+1274-0x23e9)) 
#define za9d8fb6bcf           ssGetSFcnParam(S, (0x1725+1641-0x1d8d)) 
#define zf5ee62a4ad      ssGetSFcnParam(S, (0xf90+2102-0x17c4))
#define zdcecd118d0     ssGetSFcnParam(S, (0xdf4+5456-0x2341))
#define z3832b85a32         ssGetSFcnParam(S, (0xb12+4581-0x1cf3))
#define z702a26a5e9              ssGetSFcnParam(S, (0x472+5106-0x185f))
#define z2e6483d505              ((0x455+2833-0xf65))
#define zc5ce4cb81a              ((0x100f+5503-0x258e))
#define z2b17e2ee3b              ((0xf93+2473-0x193c))
#define z6a0da049de         ((0x9fd+5291-0x1ea8))
#define zb4530cf885                180224
static char_T zea4cd01646[(0xe81+1193-0x122a)];typedef struct{volatile uint32_T start;volatile uint32_T clear;volatile uint32_T zeb5b1d96b9;volatile uint32_T z21ab44ce3e;volatile uint32_T count[(0x7a6+4975-0x1af5)];volatile uint32_T z28e9d9261f[(0x3af+5475-0x18f2)];volatile uint32_T z1fe5bfccaf[(0x4c6+2668-0xf12)];volatile uint32_T z627a05d850[(0x292+364-0x3de)];volatile uint32_T z94328689b6[(0x24bd+619-0x2708)];volatile uint32_T z039626e71b[(0x1a56+326-0x1b7c)];volatile uint32_T z5e4e5bef4b;}z71f90c95f9;static void mdlInitializeSizes(SimStruct*S){uint32_T i,za0df33019b;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x58a+3069-0x1187));ssSetNumDiscStates(S,(0xa3a+185-0xaf3));ssSetNumOutputPorts(S,(0x824+639-0xaa2));ssSetOutputPortWidth(S,(0x18+2983-0xbbf),(0xfe7+1045-0x13bc));if((uint32_T)mxGetPr(zdcecd118d0)[(0x271+2454-0xc07)]){ssSetNumInputPorts(S,(0xadc+5184-0x1f19));
ssSetInputPortWidth(S,(0xb8b+1495-0x1162),(0x185c+644-0x1adf));ssSetInputPortDirectFeedThrough(S,(0x1ecc+0-0x1ecc),(0x7f3+6315-0x209d));ssSetInputPortRequiredContiguous(S,(0x355+449-0x516),(0xbb+2884-0xbfe));ssSetInputPortWidth(S,(0x8cf+2490-0x1288),(0x201+986-0x5da));ssSetInputPortDirectFeedThrough(S,(0x12c0+688-0x156f),(0x142d+3554-0x220e));ssSetInputPortRequiredContiguous(S,(0x4b5+674-0x756),(0x29a+344-0x3f1));ssSetInputPortWidth(S,(0x8b7+5462-0x1e0b),(0x248+9261-0x2674));ssSetInputPortDirectFeedThrough(S,(0x1725+2157-0x1f90),(0x24fd+148-0x2590));ssSetInputPortRequiredContiguous(S,(0x1d9b+1871-0x24e8),(0x14bc+3350-0x21d1));}else{ssSetNumInputPorts(S,(0x511+2940-0x108b));
ssSetInputPortWidth(S,(0x631+7790-0x249f),(0x1912+2824-0x2419));ssSetInputPortDirectFeedThrough(S,(0x1365+3390-0x20a3),(0x31+8089-0x1fc9));ssSetInputPortRequiredContiguous(S,(0xeac+4375-0x1fc3),(0x7f3+1619-0xe45));ssSetInputPortWidth(S,(0x24c+3507-0xffe),(0x19c8+546-0x1be9));ssSetInputPortDirectFeedThrough(S,(0xaff+2409-0x1467),(0xfd5+599-0x122b));ssSetInputPortRequiredContiguous(S,(0x111a+461-0x12e6),(0x1e4f+725-0x2123));}ssSetNumSampleTimes(S,(0x36d+5668-0x1990));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x172f+3255-0x23e6));ssSetNumNonsampledZCs(S,(0x2b+8234-0x2055));for(i=(0x1385+924-0x1721);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x267+1335-0x79e));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x11+4838-0x12f7)]==-1.0){ssSetSampleTime(S,(0x74+251-0x16f),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x128+774-0x42e),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x1973+927-0x1d12),mxGetPr(z3832b85a32)[(0xa35+4438-0x1b8b)]);ssSetOffsetTime(S,(0xc0c+1142-0x1082),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i;uint8_T z16ba527520[(0x347+5266-0x17c5)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61,z4e3026977c;
volatile z71f90c95f9*zca56c6316b;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x887+4711-0x1aee)];z6f813cde47=z05b56d9d51=5845;switch(z78caf1ba61){case(0xad6+1675-0x1020):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;case(0x1de8+473-0x1e76):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;break;}if(mxGetN(z702a26a5e9)==(0x125+3143-0xd6b)){z366b2f03bf=(0x1b83+2432-0x2503);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xce0+2662-0x1746)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x1c2f+914-0x1fc1)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x3d1+8866-0x2672)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0xdb5+5784-0x244b)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x98c+1439-0xf29)],zeccbadd9b3.Length[(0x128+9276-0x2562)],XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x13f1+2841-0x1f08)]);zca56c6316b=(z71f90c95f9*)(zeccbadd9b3.VirtAddress[(0x17a5+2006-0x1f79)]+zb4530cf885);if(!xpceIsModelInit()){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[(0xebb+3811-0x1d9e)]-(0x3ef+702-0x6ac);zca56c6316b->z28e9d9261f[z4e3026977c]=(uint32_T)mxGetPr(zf5ee62a4ad)[(0x3bb+132-0x43f)];}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint32_T i,z4e3026977c,z812c65ff2f;real_T*z039626e71b,*count,*za2cbad8e67,*ze769fc7d2c;
volatile z71f90c95f9*zca56c6316b;zca56c6316b=(z71f90c95f9*)(base+zb4530cf885);z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[(0x33f+4388-0x1463)]-(0xb6+7763-0x1f08);z039626e71b=(real_T*)ssGetInputPortSignal(S,(0x642+7503-0x2391));zca56c6316b->z039626e71b[z4e3026977c]=(uint32_T)z039626e71b[(0xc6b+2046-0x1469)];if(mxGetPr(zdcecd118d0)[(0x718+7854-0x25c6)]){while(!((zca56c6316b->z5e4e5bef4b>>z4e3026977c)&(0x30d+4992-0x168c))==(0x692+2134-0xee7));za2cbad8e67=(real_T*)ssGetInputPortSignal(S,(0xf73+5016-0x2309));zca56c6316b->zeb5b1d96b9=((0x13d8+3223-0x206f)<<z4e3026977c);
zca56c6316b->z1fe5bfccaf[z4e3026977c]=(0xf14+2964-0x1aa8);zca56c6316b->z627a05d850[z4e3026977c]=(uint32_T)za2cbad8e67[(0x5da+6609-0x1fab)];zca56c6316b->z21ab44ce3e=(0x518+573-0x754);zca56c6316b->z21ab44ce3e=(0x1544+2686-0x1fc2);zca56c6316b->count[z4e3026977c]=(0x8aa+4916-0x1bdd);zca56c6316b->start=((0x16e3+1889-0x1e43)<<z4e3026977c);zca56c6316b->start=(0xb2+3797-0xf87);}while(!((zca56c6316b->z5e4e5bef4b>>z4e3026977c)&(0x1095+2287-0x1983))==(0x31d+6006-0x1a92));zca56c6316b->zeb5b1d96b9=((0x308+40-0x32f)<<z4e3026977c);count=(real_T*)ssGetInputPortSignal(S,(0x182b+2020-0x200e));zca56c6316b->count[z4e3026977c]=(uint32_T)count[(0x1756+2733-0x2203)];zca56c6316b->start=((0x7fd+6107-0x1fd7)<<z4e3026977c);zca56c6316b->start=(0x1285+3363-0x1fa8);while(!((zca56c6316b->z5e4e5bef4b>>z4e3026977c)&(0x18e9+2364-0x2224))==(0xaec+6315-0x2396));
ze769fc7d2c=(real_T*)ssGetOutputPortSignal(S,(0x32c+3382-0x1062));for(i=(0x250+6112-0x1a30);i<count[(0x15b2+393-0x173b)];i++){zca56c6316b->z1fe5bfccaf[z4e3026977c]=(uint32_T)i;ze769fc7d2c[i]=zca56c6316b->z94328689b6[z4e3026977c];}
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
