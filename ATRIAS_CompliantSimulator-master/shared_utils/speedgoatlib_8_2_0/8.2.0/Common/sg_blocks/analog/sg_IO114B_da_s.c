/* Copyright 2006-2013 Speedgoat GmbH. */
#define         S_FUNCTION_LEVEL        (0x17a5+2217-0x204c)
#undef          S_FUNCTION_NAME
#define         S_FUNCTION_NAME         sg_IO114B_da_s
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
#define zdf24515981          ((0x1bc6+253-0x1cbd))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0x680+838-0x9c6))
#define z8fd86139be               ssGetSFcnParam(S,(0xf5c+2905-0x1ab4))
#define zabe1e0cd2c          ssGetSFcnParam(S,(0x153a+2896-0x2088))
#define z702a26a5e9                ssGetSFcnParam(S,(0x1430+4724-0x26a1))
#define zc8bbaa6115               ssGetSFcnParam(S,(0x145a+4377-0x256f))
#define zf80b27df71                ssGetSFcnParam(S,(0x13c+5502-0x16b5))
#define z2e6483d505              ((0x8a5+4067-0x1883))
#define z6a0da049de         ((0x2b8+9103-0x2647))
#define zb901964b43            ((0x284+2015-0xa62))
#define zdb781881ab         ((0x19c2+2885-0x2505))
#define z8185fbe314           ((0x8f5+1151-0xd71))
#define z6faec2ef7b           ((0x1089+902-0x140b))
#define zc5ce4cb81a              ((0x207f+1335-0x25b6))
#define z2b17e2ee3b              ((0xb79+5919-0x2298))
static char_T zea4cd01646[(0xbc6+1943-0x125d)];
#define z694756a014        (0x2682+2213-0x1add)
#define zea87e0ba83        25352
#define z29146a1837     (0x1866+480-0x5fc)
#define zab7e64468b     25512
#define zf1b619edf2         "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x31\x34\x42"
uint16_T z3568804f6b(int z4e3026977c);static void mdlInitializeSizes(SimStruct*S){int i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x23e1+198-0x24a7));ssSetNumDiscStates(S,(0x1475+4199-0x24dc));ssSetNumInputPorts(S,(int_T)mxGetN(za9d8fb6bcf));for(i=(0xa44+607-0xca3);i<(int)mxGetN(za9d8fb6bcf);i++){ssSetInputPortWidth(S,i,(0x147c+1911-0x1bf2));ssSetInputPortDirectFeedThrough(S,i,(0x663+6877-0x213f));}ssSetNumOutputPorts(S,(0x294+7413-0x1f89));ssSetNumSampleTimes(S,(0xa5b+5638-0x2060));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xcd8+5525-0x226d));ssSetNumNonsampledZCs(S,(0x63b+5250-0x1abd));for(i=(0x126d+4762-0x2507);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1cb2+2350-0x25e0));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(zabe1e0cd2c)[(0x999+4976-0x1d09)]==-1.0){ssSetSampleTime(S,(0x1f37+969-0x2300),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xa6+8555-0x2211),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x1691+2245-0x1f56),mxGetPr(zabe1e0cd2c)[(0x1603+3222-0x2299)]);ssSetOffsetTime(S,(0xb2d+4225-0x1bae),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;volatile uint32_T z5fcf9921e0;int offset=(0xe7d+2287-0x176c);int z429712b6a9=(0x62d+67-0x670);int za39423f5a5=(0xdc0+5563-0x237b);int z1bf711cd48=(0x67f+1028-0xa83);int_T z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0xc9f+5339-0x217a)];int_T z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x530+8446-0x262d)];
if(xpcGetPCIDeviceInfo((unsigned short)z694756a014,(unsigned short)zea87e0ba83,(unsigned short)z29146a1837,(unsigned short)zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}z5fcf9921e0=(uint32_T)zeccbadd9b3.BaseAddress[(0x2493+511-0x2690)];switch((int)mxGetPr(z8fd86139be)[(0x7a6+4338-0x1898)]){case(0x7f4+525-0xa00):
offset=(0x1879+3319-0x2570);z429712b6a9=(0x1624+1501-0x1bed);za39423f5a5=(0x12a+9612-0x26a2);z1bf711cd48=(0xf41+4334-0x202f);break;case(0xd2a+2929-0x1899):
offset=(0x19cb+3121-0x25f7);z429712b6a9=(0x87b+5851-0x1f42);za39423f5a5=(0x14f2+2648-0x1f31);z1bf711cd48=(0x2c5+5686-0x18f6);break;case(0x98+8325-0x211a):
offset=(0x3e3+2799-0xece);z429712b6a9=(0x1e01+2193-0x2682);za39423f5a5=(0x179+137-0x1ee);z1bf711cd48=(0x173+7196-0x1d8b);break;}ssSetIWorkValue(S,z6a0da049de,z5fcf9921e0);ssSetIWorkValue(S,zb901964b43,offset);ssSetIWorkValue(S,zdb781881ab,z429712b6a9);ssSetIWorkValue(S,z8185fbe314,za39423f5a5);ssSetIWorkValue(S,z6faec2ef7b,z1bf711cd48);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
volatile uint32_T z5fcf9921e0=(uint32_T)ssGetIWorkValue(S,z6a0da049de);real_T offset=(real_T)ssGetIWorkValue(S,zb901964b43);real_T z429712b6a9=(real_T)ssGetIWorkValue(S,zdb781881ab);real_T za39423f5a5=(real_T)ssGetIWorkValue(S,z8185fbe314);real_T z1bf711cd48=(real_T)ssGetIWorkValue(S,z6faec2ef7b);int_T zf91d71c6d9=(int_T)mxGetN(za9d8fb6bcf);int_T i;int_T z4e3026977c;real_T output;uint16_T zcb341ffb0e;InputRealPtrsType z142f9c10a3;for(i=(0xebf+6099-0x2692);i<zf91d71c6d9;i++){z4e3026977c=(int_T)mxGetPr(za9d8fb6bcf)[i]-(0x1ea5+108-0x1f10);z142f9c10a3=ssGetInputPortRealSignalPtrs(S,i);output=*z142f9c10a3[(0x3f8+1256-0x8e0)];if(output<z1bf711cd48)output=z1bf711cd48;else if(output>za39423f5a5)output=za39423f5a5;zcb341ffb0e=(uint16_T)(((output-offset)/z429712b6a9)*4095.0);while((xpcInpW(z5fcf9921e0)&(0xcc2+6536-0x2649))==(0x146f+2838-0x1f84));
xpcOutpW(z5fcf9921e0+z3568804f6b(z4e3026977c),zcb341ffb0e);}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
volatile uint32_T z5fcf9921e0=(uint32_T)ssGetIWorkValue(S,z6a0da049de);real_T offset=(real_T)ssGetIWorkValue(S,zb901964b43);real_T z429712b6a9=(real_T)ssGetIWorkValue(S,zdb781881ab);real_T za39423f5a5=(real_T)ssGetIWorkValue(S,z8185fbe314);real_T z1bf711cd48=(real_T)ssGetIWorkValue(S,z6faec2ef7b);int_T zf91d71c6d9=(int_T)mxGetN(za9d8fb6bcf);int_T i;int_T z4e3026977c;real_T output;uint16_T zcb341ffb0e;for(i=(0x1182+4073-0x216b);i<zf91d71c6d9;i++){z4e3026977c=(int_T)mxGetPr(za9d8fb6bcf)[i]-(0x854+4958-0x1bb1);if(xpcIsModelInit()||(mxGetPr(zc8bbaa6115)[i]==(0x553+5384-0x1a5a))){output=mxGetPr(zf80b27df71)[i];if(output<z1bf711cd48)output=z1bf711cd48;else if(output>za39423f5a5)output=za39423f5a5;zcb341ffb0e=(uint16_T)(((output-offset)/z429712b6a9)*4095.0);while((xpcInpW(z5fcf9921e0)&(0x1e4d+161-0x1eed))==(0x1c23+2715-0x26bd));
xpcOutpW(z5fcf9921e0+z3568804f6b(z4e3026977c),zcb341ffb0e);
while((xpcInpW(z5fcf9921e0)&(0x1de9+2125-0x2635))==(0x85d+5720-0x1eb4));
while((xpcInpW(z5fcf9921e0)&(0x1e1f+837-0x2163))==(0x15ed+2862-0x211a));
while((xpcInpW(z5fcf9921e0)&(0x10ff+4080-0x20ee))==(0x31c+4925-0x1658));
while((xpcInpW(z5fcf9921e0)&(0x254+1787-0x94e))==(0x200a+616-0x2271));
while((xpcInpW(z5fcf9921e0)&(0xd6a+1568-0x1389))==(0x15d2+4381-0x26ee));
}}
#endif
}uint16_T z3568804f6b(int z4e3026977c){uint16_T offset;switch(z4e3026977c){case(0x6f+9660-0x262b):offset=(0x51+8928-0x232b);break;case(0x1828+988-0x1c03):offset=(0x9c4+6936-0x24d8);break;case(0x897+3922-0x17e7):offset=(0x491+1732-0xb53);break;case(0xf46+3868-0x1e5f):offset=(0x1bcc+1351-0x2113);break;case(0x14fb+3721-0x2380):offset=(0x278+1457-0x81b);break;case(0x4b3+1472-0xa6e):offset=(0xfdc+3032-0x1ba8);break;case(0x1d90+1827-0x24ad):offset=(0xa2c+477-0xbff);break;case(0xc4b+3568-0x1a34):offset=(0x9b0+5258-0x1e32);}return offset;}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

