/* Copyright 2006-2013 Speedgoat GmbH. */
#define         S_FUNCTION_LEVEL        (0x300+754-0x5f0)
#undef          S_FUNCTION_NAME
#define         S_FUNCTION_NAME         sg_IO101_di_s
#include        <stddef.h>
#include        <stdlib.h>
#include        "simstruc.h"
#ifdef          MATLAB_MEX_FILE
#include        "mex.h"
#endif
#ifndef         MATLAB_MEX_FILE
#include        <windows.h>
#include        "io_xpcimport.h"
#include        "pci_xpcimport.h"
#endif
#define zdf24515981          ((0x1dac+1702-0x244b))
#define z942d41a49c        ssGetSFcnParam(S,(0x1e21+6-0x1e27))
#define z0cf2e207bc        ssGetSFcnParam(S,(0x14ad+3333-0x21b1))
#define z7bf3bce264        ssGetSFcnParam(S,(0x1823+2819-0x2324))
#define z6fccdc8f6e       ssGetSFcnParam(S,(0x11c3+43-0x11eb))
#define z12acd7bee3       ssGetSFcnParam(S,(0x93f+2762-0x1405))
#define z3832b85a32           ssGetSFcnParam(S,(0xbbf+2302-0x14b8))
#define z702a26a5e9                ssGetSFcnParam(S,(0x12a4+4557-0x246b))
#define z824efc2f8d           ((0x894+61-0x8d1))
#define zf552029f69           ((0x1622+2896-0x2172))
#define z2e6483d505              ((0x281+5815-0x1937))
#define z6a0da049de         ((0x1322+2408-0x1c8a))
#define zc5ce4cb81a              ((0xa6d+6732-0x24b9))
static char_T zea4cd01646[(0x532+2920-0xf9a)];static void mdlInitializeSizes(SimStruct*S){int i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x19b3+316-0x1aef));ssSetNumDiscStates(S,(0x16d5+3409-0x2426));if((uint32_T)mxGetPr(z942d41a49c)[(0x621+7727-0x2450)]==(0x1293+227-0x1375)){ssSetNumOutputPorts(S,mxGetN(z0cf2e207bc));for(i=(0x14d2+2974-0x2070);i<mxGetN(z0cf2e207bc);i++){ssSetOutputPortWidth(S,i,(0x1cca+1090-0x210b));ssSetOutputPortDataType(S,(0x1477+4653-0x26a4),SS_DOUBLE);}}else{ssSetNumOutputPorts(S,mxGetN(z7bf3bce264));for(i=(0x1413+2978-0x1fb5);i<mxGetN(z7bf3bce264);i++){ssSetOutputPortWidth(S,i,(0xc89+1436-0x1224));ssSetOutputPortDataType(S,(0x185+4115-0x1198),SS_DOUBLE);}}ssSetNumInputPorts(S,(0x13f0+34-0x1412));ssSetNumSampleTimes(S,(0x36+9539-0x2578));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,(0x139d+4700-0x25f9));ssSetNumModes(S,(0x14e7+3485-0x2284));ssSetNumNonsampledZCs(S,(0x15ef+3724-0x247b));for(i=(0x1e70+1227-0x233b);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x4fa+2920-0x1062));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x1f47+1691-0x25e2)]==-1.0){ssSetSampleTime(S,(0x208b+1286-0x2591),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1205+2464-0x1ba5),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x181+3445-0xef6),mxGetPr(z3832b85a32)[(0x935+6173-0x2152)]);ssSetOffsetTime(S,(0xf92+2494-0x1950),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;int_T base;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;int_T z049b04bd7f,z3b7a4946fb;char_T zda7b5a7e16[(0x646+4583-0x180f)];uint32_T zaa88aaf485,i,z0c3eef007f,z4e3026977c;uint8_T zf841bb2451;z049b04bd7f=5845;z3b7a4946fb=17495;strcpy(zda7b5a7e16,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x30\x31");if((int_T)mxGetPr(z702a26a5e9)[(0x5ab+4876-0x18b7)]<(0x46d+1607-0xab4)){
if(rl32eGetPCIInfo((unsigned short)z049b04bd7f,(unsigned short)z3b7a4946fb,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zda7b5a7e16);ssSetErrorStatus(S,zea4cd01646);return;}}else{int_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x693+173-0x73f)){z366b2f03bf=(0x2223+6-0x2229);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x436+6672-0x1e46)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0xbbd+4537-0x1d76)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x2607+91-0x2661)];}
if(rl32eGetPCIInfoAtSlot((unsigned short)z049b04bd7f,(unsigned short)z3b7a4946fb,(z441f9e6d1b&(0x669+945-0x91b))|((z366b2f03bf&(0x9f4+4406-0x1a2b))<<(0xda7+5264-0x222f)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zda7b5a7e16,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0xc2b+1354-0x1175)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x18e8+5041-0x1c99),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);if((uint32_T)mxGetPr(z942d41a49c)[(0x729+7265-0x238a)]==(0x1085+5514-0x260e)){z0c3eef007f=mxGetN(z0cf2e207bc);
zaa88aaf485=(0x1790+603-0x19eb);for(i=(0x5b0+6359-0x1e87);i<z0c3eef007f;i++){z4e3026977c=(int_T)mxGetPr(z0cf2e207bc)[i]-(0xeb9+1658-0x1532);zf841bb2451=(uint8_T)mxGetPr(z6fccdc8f6e)[z4e3026977c];zaa88aaf485|=(zf841bb2451<<(0x18a9+177-0x1956)*i);}za42cf7dd4a[(0x10d7+4544-0x2285)]=zaa88aaf485;}else{z0c3eef007f=mxGetN(z7bf3bce264);
zaa88aaf485=(0x86a+6888-0x2352);for(i=(0x9f7+7233-0x2638);i<z0c3eef007f;i++){z4e3026977c=(int_T)mxGetPr(z7bf3bce264)[i]-(0xb23+5709-0x216f);zf841bb2451=(uint8_T)mxGetPr(z12acd7bee3)[z4e3026977c];zaa88aaf485|=(zf841bb2451<<(0x1ccf+1170-0x215d)*i);}za42cf7dd4a[(0x13fb+2324-0x1cfc)]=zaa88aaf485;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;int_T z0c3eef007f;uint32_T i,input,z4e3026977c;real_T*y;za42cf7dd4a=(void*)base;input=za42cf7dd4a[(0xb89+5609-0x2164)]&65535;if((uint32_T)mxGetPr(z942d41a49c)[(0x7f4+7185-0x2405)]==(0xc03+6473-0x254b)){z0c3eef007f=mxGetN(z0cf2e207bc);for(i=(0x1b7+3086-0xdc5);i<z0c3eef007f;i++){z4e3026977c=(int_T)mxGetPr(z0cf2e207bc)[i]-(0xe19+2205-0x16b5);y=ssGetOutputPortSignal(S,i);y[(0x1a1b+1737-0x20e4)]=(input>>z4e3026977c)&(0x10bf+2291-0x19b1);}}else{z0c3eef007f=mxGetN(z7bf3bce264);for(i=(0x162b+2869-0x2160);i<z0c3eef007f;i++){z4e3026977c=(int_T)mxGetPr(z7bf3bce264)[i]-(0x1cab+921-0x2043);y=ssGetOutputPortSignal(S,i);y[(0x212+1835-0x93d)]=(input>>(z4e3026977c+(0x18b7+1581-0x1edc)))&(0x724+82-0x775);}}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

