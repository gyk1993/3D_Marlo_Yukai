/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x13e2+2048-0x1be0)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_i2cmwrite_sf
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
#define zdf24515981        ((0x19a1+2298-0x2296))
#define z533b11d03f         ssGetSFcnParam(S, (0x8d9+6578-0x228b)) 
#define za9d8fb6bcf           ssGetSFcnParam(S, (0x2ec+3679-0x114a)) 
#define zf5ee62a4ad      ssGetSFcnParam(S, (0x1a4a+983-0x1e1f))
#define z3832b85a32         ssGetSFcnParam(S, (0x69a+1183-0xb36))
#define z702a26a5e9              ssGetSFcnParam(S, (0xd17+1430-0x12a9))
#define z2e6483d505              ((0x414+8636-0x25cf))
#define zc5ce4cb81a              ((0x1f6d+888-0x22e5))
#define z2b17e2ee3b              ((0x498+7740-0x22d4))
#define z6a0da049de         ((0x7f2+1680-0xe82))
#define zb4530cf885                (589824)
static char_T zea4cd01646[(0x1eaf+977-0x2180)];struct z71f90c95f9{uint32_T start;uint32_T clear;uint32_T zeb5b1d96b9;uint32_T z21ab44ce3e;uint32_T count[(0x117a+2972-0x1cf6)];uint32_T z28e9d9261f[(0x1db2+2099-0x25c5)];uint32_T z1fe5bfccaf[(0x642+6749-0x207f)];uint32_T z627a05d850[(0x1207+5087-0x25c6)];uint32_T z94328689b6[(0x14dd+2220-0x1d69)];uint32_T z039626e71b[(0x30a+3822-0x11d8)];uint32_T z5e4e5bef4b;};static void mdlInitializeSizes(SimStruct*S){uint32_T i,za0df33019b;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x2087+1190-0x252d));ssSetNumDiscStates(S,(0xfd1+5070-0x239f));ssSetNumOutputPorts(S,(0xb14+446-0xcd2));ssSetNumInputPorts(S,(0x1cfc+2066-0x250b));
ssSetInputPortWidth(S,(0xdf6+5886-0x24f4),(0x406+5718-0x1a5b));ssSetInputPortDirectFeedThrough(S,(0x1ab4+2180-0x2338),(0x1696+2102-0x1ecb));ssSetInputPortRequiredContiguous(S,(0x52c+5765-0x1bb1),(0x22b+5266-0x16bc));ssSetInputPortWidth(S,(0x106c+3803-0x1f46),(0xfa+5804-0x17a5));ssSetInputPortDirectFeedThrough(S,(0x15c5+2063-0x1dd3),(0x141+8115-0x20f3));ssSetInputPortRequiredContiguous(S,(0x614+666-0x8ad),(0x4b8+3923-0x140a));ssSetInputPortWidth(S,(0x827+3320-0x151d),(0x66+5339-0x1501));ssSetInputPortDirectFeedThrough(S,(0x1a07+569-0x1c3e),(0xa0f+7121-0x25df));ssSetInputPortRequiredContiguous(S,(0x18b7+3405-0x2602),(0xae6+6529-0x2466));ssSetNumSampleTimes(S,(0x416+581-0x65a));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x212f+875-0x249a));ssSetNumNonsampledZCs(S,(0x14d9+2197-0x1d6e));for(i=(0x1f59+151-0x1ff0);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1c3a+311-0x1d71));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x55+4276-0x1109)]==-1.0){ssSetSampleTime(S,(0x2370+412-0x250c),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1a1b+49-0x1a4c),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xd46+3526-0x1b0c),mxGetPr(z3832b85a32)[(0xe38+2837-0x194d)]);ssSetOffsetTime(S,(0xcac+1371-0x1207),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i;uint8_T z16ba527520[(0x10c8+2997-0x1c69)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61,z4e3026977c;volatile struct z71f90c95f9*zca56c6316b;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x1165+1595-0x17a0)];z6f813cde47=z05b56d9d51=(0x1e37+5496-0x1cda);switch(z78caf1ba61){case(0x986+6105-0x2032):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");za4a2434e08=z182d03571c=17232;break;case(0x73f+7257-0x226a):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");za4a2434e08=z182d03571c=17239;break;case(0x200f+1944-0x2678):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");za4a2434e08=z182d03571c=16979;break;case(0x568+926-0x7d6):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");za4a2434e08=z182d03571c=(0x102c+6230-0x237e);break;case(0x1761+2085-0x1e4f):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");za4a2434e08=z182d03571c=21069;break;case(0xcc6+3655-0x19d5):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");za4a2434e08=z182d03571c=16971;break;case(0x1b0+6138-0x1871):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");za4a2434e08=z182d03571c=17235;break;case(0x19e2+3239-0x254f):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");za4a2434e08=z182d03571c=(0x23b8+3348-0x10c8);break;case(0x349+1158-0x68e):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;}if(mxGetN(z702a26a5e9)==(0xf40+270-0x104d)){z366b2f03bf=(0x25a+3856-0x116a);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x2a5+505-0x49e)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x11d0+2160-0x1a40)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x431+2664-0xe98)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x1e3d+1193-0x22e4)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x4e0+5335-0x19b5)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x8d8+2543-0x12c5)]);zca56c6316b=(volatile struct z71f90c95f9*)(zeccbadd9b3.VirtAddress[(0x2154+1316-0x2676)]+zb4530cf885);if(!xpceIsModelInit()){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[(0x213d+740-0x2421)]-(0x779+4369-0x1889);zca56c6316b->z28e9d9261f[z4e3026977c]=(uint32_T)mxGetPr(zf5ee62a4ad)[(0x18e9+2938-0x2463)];}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint32_T i,z4e3026977c,z039626e71b,count;real_T*y;real_T z9ab632cec0,zab642cf9f7;volatile struct z71f90c95f9*zca56c6316b=(struct z71f90c95f9*)(base+zb4530cf885);z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[(0x14a4+1389-0x1a11)]-(0x1b48+1693-0x21e4);
z9ab632cec0=rl32eGetTicksDouble();while(!((zca56c6316b->z5e4e5bef4b>>z4e3026977c)&(0x1140+1218-0x1601))==(0x9f0+1195-0xe9a)){zab642cf9f7=rl32eGetTicksDouble();if(zab642cf9f7-z9ab632cec0>1193000.0*5.0){sprintf(zea4cd01646,"\x49\x32\x43\x4d\x20\x77\x72\x69\x74\x65\x3a\x20\x54\x69\x6d\x65\x6f\x75\x74\x20\x65\x72\x72\x6f\x72");ssSetErrorStatus(S,zea4cd01646);return;}};y=(real_T*)ssGetInputPortSignal(S,(0xe26+3321-0x1b1f));z039626e71b=(uint32_T)y[(0xa58+6169-0x2271)];zca56c6316b->z039626e71b[z4e3026977c]=z039626e71b;y=(real_T*)ssGetInputPortSignal(S,(0x11f3+2411-0x1b5d));count=(uint32_T)y[(0x12c4+2967-0x1e5b)];zca56c6316b->count[z4e3026977c]=count;y=(real_T*)ssGetInputPortSignal(S,(0x2c7+1293-0x7d2));for(i=(0xd1+5851-0x17ac);i<count;i++){
zca56c6316b->z1fe5bfccaf[z4e3026977c]=(uint32_T)i;
zca56c6316b->z627a05d850[z4e3026977c]=(uint32_T)y[i];zca56c6316b->z21ab44ce3e=((0xd46+4721-0x1fb6)<<z4e3026977c);zca56c6316b->z21ab44ce3e=(0x9e4+1705-0x108d);}zca56c6316b->zeb5b1d96b9=((0x1c4f+2703-0x26de)<<z4e3026977c);
if(count>(0xced+494-0xedb)){zca56c6316b->start=((0x2af+9041-0x25ff)<<z4e3026977c);zca56c6316b->start=(0x1061+4856-0x2359);}

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
