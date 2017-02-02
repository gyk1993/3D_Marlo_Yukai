/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x7b3+7553-0x2532)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_i2cmread_sf
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
#define zdf24515981        ((0x1019+1530-0x160d))
#define z533b11d03f         ssGetSFcnParam(S, (0x22e2+103-0x2349)) 
#define za9d8fb6bcf           ssGetSFcnParam(S, (0xa1+2923-0xc0b)) 
#define zf5ee62a4ad      ssGetSFcnParam(S, (0x4ac+8160-0x248a))
#define zdcecd118d0     ssGetSFcnParam(S, (0x132+5077-0x1504))
#define z3832b85a32         ssGetSFcnParam(S, (0x1e2c+1364-0x237c))
#define z702a26a5e9              ssGetSFcnParam(S, (0x1ee0+223-0x1fba))
#define z2e6483d505              ((0x90f+798-0xc2c))
#define zc5ce4cb81a              ((0xcd6+375-0xe4d))
#define z2b17e2ee3b              ((0xb5b+4035-0x1b1e))
#define z6a0da049de         ((0x1602+691-0x18b5))
#define zb4530cf885                (589824)
static char_T zea4cd01646[(0x1f01+1715-0x24b4)];struct z71f90c95f9{uint32_T start;uint32_T clear;uint32_T zeb5b1d96b9;uint32_T z21ab44ce3e;uint32_T count[(0x20c+5214-0x164a)];uint32_T z28e9d9261f[(0x833+4932-0x1b57)];uint32_T z1fe5bfccaf[(0x1533+468-0x16e7)];uint32_T z627a05d850[(0x862+7835-0x26dd)];uint32_T z94328689b6[(0x1629+798-0x1927)];uint32_T z039626e71b[(0x156f+3579-0x234a)];uint32_T z5e4e5bef4b;};static void mdlInitializeSizes(SimStruct*S){uint32_T i,za0df33019b;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x41d+1201-0x8ce));ssSetNumDiscStates(S,(0x79b+4192-0x17fb));ssSetNumOutputPorts(S,(0x4a9+8077-0x2435));ssSetOutputPortWidth(S,(0x4a3+8626-0x2655),(0x1567+1787-0x1c22));if((uint32_T)mxGetPr(zdcecd118d0)[(0x792+2874-0x12cc)]){ssSetNumInputPorts(S,(0x150+7482-0x1e87));
ssSetInputPortWidth(S,(0xf9a+2988-0x1b46),(0x875+6105-0x204d));ssSetInputPortDirectFeedThrough(S,(0x47f+5525-0x1a14),(0x5e3+7394-0x22c4));ssSetInputPortRequiredContiguous(S,(0xbc1+1868-0x130d),(0x29a+1487-0x868));ssSetInputPortWidth(S,(0x882+5125-0x1c86),(0x1573+2083-0x1d95));ssSetInputPortDirectFeedThrough(S,(0x38c+3460-0x110f),(0x1024+3249-0x1cd4));ssSetInputPortRequiredContiguous(S,(0x1b67+1975-0x231d),(0x1792+54-0x17c7));ssSetInputPortWidth(S,(0x199b+138-0x1a23),(0x114a+3454-0x1ec7));ssSetInputPortDirectFeedThrough(S,(0x1265+3646-0x20a1),(0x124b+1497-0x1823));ssSetInputPortRequiredContiguous(S,(0xd4c+5643-0x2355),(0xa4a+5614-0x2037));}else{ssSetNumInputPorts(S,(0xbf7+4286-0x1cb3));
ssSetInputPortWidth(S,(0x3a4+2599-0xdcb),(0x1c21+1160-0x20a8));ssSetInputPortDirectFeedThrough(S,(0x81f+2024-0x1007),(0x1e8+1165-0x674));ssSetInputPortRequiredContiguous(S,(0xb96+6169-0x23af),(0x188b+3709-0x2707));ssSetInputPortWidth(S,(0x141b+4122-0x2434),(0x1fe7+232-0x20ce));ssSetInputPortDirectFeedThrough(S,(0x1b7f+1700-0x2222),(0xdd4+4618-0x1fdd));ssSetInputPortRequiredContiguous(S,(0x131a+918-0x16af),(0x719+3109-0x133d));}ssSetNumSampleTimes(S,(0x1359+1423-0x18e7));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1a01+1170-0x1e93));ssSetNumNonsampledZCs(S,(0x300+3798-0x11d6));for(i=(0x1a7f+1234-0x1f51);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x179d+3652-0x25e1));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x3f1+7531-0x215c)]==-1.0){ssSetSampleTime(S,(0x13b4+4664-0x25ec),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x19d+6719-0x1bdc),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xde3+5964-0x252f),mxGetPr(z3832b85a32)[(0x1e66+2101-0x269b)]);ssSetOffsetTime(S,(0x49+2802-0xb3b),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i;uint8_T z16ba527520[(0x113c+5067-0x24f3)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61,z4e3026977c;volatile struct z71f90c95f9*zca56c6316b;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x5a4+4512-0x1744)];z6f813cde47=z05b56d9d51=(0x251b+6287-0x26d5);switch(z78caf1ba61){case(0xf6c+2153-0x16a8):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");za4a2434e08=z182d03571c=17232;break;case(0x2ab+3599-0xf8c):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");za4a2434e08=z182d03571c=17239;break;case(0x885+6509-0x20c3):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");za4a2434e08=z182d03571c=16979;break;case(0x6e1+8043-0x251c):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");za4a2434e08=z182d03571c=(0x9aa+6133-0x1c9b);break;case(0x1d8+1453-0x64e):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");za4a2434e08=z182d03571c=21069;break;case(0x457+3202-0xfa1):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");za4a2434e08=z182d03571c=16971;break;case(0xec0+3349-0x1a9c):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");za4a2434e08=z182d03571c=17235;break;case(0x1f9+717-0x38c):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");za4a2434e08=z182d03571c=(0x2095+1841-0x7c2);break;case(0x53b+5249-0x187b):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;}if(mxGetN(z702a26a5e9)==(0x1f2+6270-0x1a6f)){z366b2f03bf=(0x11ed+3710-0x206b);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x191c+667-0x1bb7)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x19c5+1829-0x20ea)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x96f+3157-0x15c3)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x1937+68-0x1979)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0xfed+1877-0x1740)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x4ab+3357-0x11c6)]);zca56c6316b=(volatile struct z71f90c95f9*)(zeccbadd9b3.VirtAddress[(0xc73+4003-0x1c14)]+zb4530cf885);if(!xpceIsModelInit()){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[(0xbad+2978-0x174f)]-(0xce2+4241-0x1d72);zca56c6316b->z28e9d9261f[z4e3026977c]=(uint32_T)mxGetPr(zf5ee62a4ad)[(0xe3c+3973-0x1dc1)];}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint32_T i,z4e3026977c,z812c65ff2f;real_T*z039626e71b,*count,*za2cbad8e67,*ze769fc7d2c;real_T z9ab632cec0,zab642cf9f7;volatile struct z71f90c95f9*zca56c6316b=(volatile struct z71f90c95f9*)(base+zb4530cf885);z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[(0x3b1+1049-0x7ca)]-(0x106d+5726-0x26ca);if(mxGetPr(zdcecd118d0)[(0xc6b+3279-0x193a)]){z9ab632cec0=rl32eGetTicksDouble();while(!((zca56c6316b->z5e4e5bef4b>>z4e3026977c)&(0x5af+8219-0x25c9))==(0x9f+5660-0x16ba)){zab642cf9f7=rl32eGetTicksDouble();if(zab642cf9f7-z9ab632cec0>1193000.0*5.0){sprintf(zea4cd01646,"\x49\x32\x43\x4d\x20\x72\x65\x61\x64\x3a\x20\x54\x69\x6d\x65\x6f\x75\x74\x20\x65\x72\x72\x6f\x72");ssSetErrorStatus(S,zea4cd01646);return;}};z039626e71b=(real_T*)ssGetInputPortSignal(S,(0x1ce7+842-0x2031));zca56c6316b->z039626e71b[z4e3026977c]=(uint32_T)z039626e71b[(0x11d4+5010-0x2566)];za2cbad8e67=(real_T*)ssGetInputPortSignal(S,(0x97b+6326-0x222f));zca56c6316b->zeb5b1d96b9=((0x52b+7961-0x2444)<<z4e3026977c);
zca56c6316b->z1fe5bfccaf[z4e3026977c]=(0xc86+4496-0x1e16);zca56c6316b->z627a05d850[z4e3026977c]=(uint32_T)za2cbad8e67[(0x565+4604-0x1761)];zca56c6316b->z21ab44ce3e=((0x122d+4170-0x2276)<<z4e3026977c);zca56c6316b->z21ab44ce3e=(0xab0+3531-0x187b);zca56c6316b->count[z4e3026977c]=(0xd13+5154-0x2134);zca56c6316b->start=((0xc41+1302-0x1156)<<z4e3026977c);zca56c6316b->start=(0xa51+6890-0x253b);}z9ab632cec0=rl32eGetTicksDouble();while(!((zca56c6316b->z5e4e5bef4b>>z4e3026977c)&(0x862+2836-0x1375))==(0x4b2+7335-0x2158))
{zab642cf9f7=rl32eGetTicksDouble();if(zab642cf9f7-z9ab632cec0>1193000.0*5.0){sprintf(zea4cd01646,"\x49\x32\x43\x4d\x20\x72\x65\x61\x64\x3a\x20\x54\x69\x6d\x65\x6f\x75\x74\x20\x65\x72\x72\x6f\x72");ssSetErrorStatus(S,zea4cd01646);return;}};zca56c6316b->zeb5b1d96b9=((0xe1+6422-0x19f6)<<z4e3026977c);count=(real_T*)ssGetInputPortSignal(S,(0x37f+3169-0xfdf));zca56c6316b->count[z4e3026977c]=(uint32_T)count[(0x6b4+2436-0x1038)];z039626e71b=(real_T*)ssGetInputPortSignal(S,(0x1868+2031-0x2057));zca56c6316b->z039626e71b[z4e3026977c]=(uint32_T)z039626e71b[(0x13c9+3340-0x20d5)];zca56c6316b->start=((0x755+482-0x936)<<z4e3026977c);zca56c6316b->start=(0x12af+4533-0x2464);z9ab632cec0=rl32eGetTicksDouble();while(!((zca56c6316b->z5e4e5bef4b>>z4e3026977c)&(0x1404+4555-0x25ce))==(0x4b6+135-0x53c)){zab642cf9f7=rl32eGetTicksDouble();if(zab642cf9f7-z9ab632cec0>1193000.0*5.0){sprintf(zea4cd01646,"\x49\x32\x43\x4d\x20\x72\x65\x61\x64\x3a\x20\x54\x69\x6d\x65\x6f\x75\x74\x20\x65\x72\x72\x6f\x72");ssSetErrorStatus(S,zea4cd01646);return;}}
ze769fc7d2c=(real_T*)ssGetOutputPortSignal(S,(0x459+1454-0xa07));for(i=(0x17b4+2883-0x22f7);i<count[(0xd94+2640-0x17e4)];i++){zca56c6316b->z1fe5bfccaf[z4e3026977c]=(uint32_T)i;ze769fc7d2c[i]=zca56c6316b->z94328689b6[z4e3026977c];}
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
