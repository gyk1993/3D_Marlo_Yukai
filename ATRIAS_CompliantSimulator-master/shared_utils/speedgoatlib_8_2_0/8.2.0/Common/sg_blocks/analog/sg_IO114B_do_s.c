/* Copyright 2006-2013 Speedgoat GmbH. */
#define         S_FUNCTION_LEVEL        (0x1dd9+21-0x1dec)
#undef          S_FUNCTION_NAME
#define         S_FUNCTION_NAME         sg_IO114B_do_s
#include        <stddef.h>
#include        <stdlib.h>
#include        "simstruc.h"
#ifdef          MATLAB_MEX_FILE
#include        "mex.h"
#endif
#ifndef         MATLAB_MEX_FILE
#include        <windows.h>
#include        "xpctarget.h"
#endif
#define zdf24515981          ((0x188c+3560-0x266f))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0xf53+3503-0x1d02))
#define zabe1e0cd2c          ssGetSFcnParam(S,(0x566+2712-0xffd))
#define z702a26a5e9                ssGetSFcnParam(S,(0x1eea+1022-0x22e6))
#define zc8bbaa6115               ssGetSFcnParam(S,(0x734+7738-0x256b))
#define zf80b27df71                ssGetSFcnParam(S,(0x1cd6+1754-0x23ac))
#define zc5ce4cb81a              ((0x1bd+855-0x514))
#define z2b17e2ee3b              ((0x1203+4709-0x2468))
#define z2e6483d505              ((0x9f5+6304-0x2294))
#define z6a0da049de         ((0xaed+2150-0x1353))
static char_T zea4cd01646[(0x102a+20-0xf3e)];
#define z694756a014 (0x1fe1+6455-0x24ce)
#define zea87e0ba83 25352
#define z29146a1837 (0x18f8+222-0x58c)
#define zab7e64468b 25512
#define zf1b619edf2     "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x31\x34\x42"
static void mdlInitializeSizes(SimStruct*S){int i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x20bb+945-0x246c));ssSetNumDiscStates(S,(0xdd+7706-0x1ef7));ssSetNumInputPorts(S,(int_T)mxGetN(za9d8fb6bcf));for(i=(0xe19+5758-0x2497);i<(int)mxGetN(za9d8fb6bcf);i++){ssSetInputPortWidth(S,i,(0xd98+2774-0x186d));ssSetInputPortDirectFeedThrough(S,i,(0x1498+2465-0x1e38));}ssSetNumOutputPorts(S,(0x875+5083-0x1c50));ssSetNumSampleTimes(S,(0x16d+147-0x1ff));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xb11+6001-0x2282));ssSetNumNonsampledZCs(S,(0x1cf6+2028-0x24e2));for(i=(0x269+6625-0x1c4a);i<zdf24515981;i++){ssSetSFcnParamNotTunable(S,i);}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(zabe1e0cd2c)[(0x1f8+5632-0x17f8)]==-1.0){ssSetSampleTime(S,(0xfc5+3143-0x1c0c),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xb2a+6278-0x23b0),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xf2+1296-0x602),mxGetPr(zabe1e0cd2c)[(0x484+926-0x822)]);ssSetOffsetTime(S,(0x926+7455-0x2645),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;volatile uint32_T z5fcf9921e0;int_T z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x14c1+780-0x17cd)];int_T z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xe82+3648-0x1cc1)];
if(xpcGetPCIDeviceInfo((unsigned short)z694756a014,(unsigned short)zea87e0ba83,(unsigned short)z29146a1837,(unsigned short)zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}z5fcf9921e0=(uint32_T)zeccbadd9b3.BaseAddress[(0xbff+4249-0x1c96)];
ssSetIWorkValue(S,z6a0da049de,(uint32_T)z5fcf9921e0);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
volatile uint32_T z5fcf9921e0=(uint32_T)ssGetIWorkValue(S,z6a0da049de);int_T zf91d71c6d9=mxGetN(za9d8fb6bcf);int_T i;real_T output;int_T z4e3026977c;InputRealPtrsType z142f9c10a3;uint16_T zcb341ffb0e=(0xaad+3693-0x191a);for(i=(0x1c94+1940-0x2428);i<zf91d71c6d9;i++){z4e3026977c=(int_T)mxGetPr(za9d8fb6bcf)[i]-(0xa3+3205-0xd27);z142f9c10a3=ssGetInputPortRealSignalPtrs(S,i);output=*z142f9c10a3[(0xbcb+2467-0x156e)];if(output>0.5)zcb341ffb0e|=(0x1e12+1338-0x234b)<<(z4e3026977c+(0x1406+548-0x1626));}
xpcOutpW(z5fcf9921e0+(0x2178+1275-0x2633),zcb341ffb0e);
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
volatile uint32_T z5fcf9921e0=(uint32_T)ssGetIWorkValue(S,z6a0da049de);int_T zf91d71c6d9=mxGetN(za9d8fb6bcf);int_T i;real_T output;int_T z4e3026977c;uint16_T zcb341ffb0e;zcb341ffb0e=xpcInpW(z5fcf9921e0+(0x100c+3841-0x1ecd));for(i=(0xc6a+4078-0x1c58);i<zf91d71c6d9;i++){z4e3026977c=(int_T)mxGetPr(za9d8fb6bcf)[i]-(0x16a9+3135-0x22e7);if(xpcIsModelInit()||(mxGetPr(zc8bbaa6115)[i]==(0xde4+4518-0x1f89))){output=mxGetPr(zf80b27df71)[i];if(output>0.5)zcb341ffb0e|=(0x12a8+2913-0x1e08)<<(z4e3026977c+(0x798+2447-0x1123));else zcb341ffb0e&=~((0xfe2+4052-0x1fb5)<<(z4e3026977c+(0x12c9+957-0x1682)));}
}xpcOutpW(z5fcf9921e0+(0x67d+6666-0x2047),zcb341ffb0e);
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

