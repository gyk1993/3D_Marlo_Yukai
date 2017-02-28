/* Copyright 2006-2013 Speedgoat GmbH. */
#define         S_FUNCTION_LEVEL        (0x9e4+4636-0x1bfe)
#undef          S_FUNCTION_NAME
#define         S_FUNCTION_NAME         sg_disable_smi_s
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
#include        "time_xpcimport.h"
#include        "ioext_xpcimport.h"
#include        "util_xpcimport.h"
#endif
#define zdf24515981    ((0xdf1+3939-0x1d54))
#define zc5ce4cb81a        ((0x1ce0+2213-0x2585))
#define z2e6483d505        ((0x1923+3379-0x2651))
#define z2b17e2ee3b        ((0x29b+7801-0x2114))
#define  z8f49cf4196      ((0x213f+1389-0x26ac))
#define  zf95459c125      ((0x15a3+423-0x1749))
#define zf24010f582      ((0x15f0+1810-0x1d00))
#define z0f0ee58ec5      ((0x175d+1094-0x1ba0))
#define z35b267a35d        ((0x4fd+7837-0x2396))
#define z412d1ea254            ((0x271+6380-0x1b58))
#define z267a3712d4          ((0x8b9+4958-0x1c11))
static char zea4cd01646[(0x682+2746-0x103c)];static void z94d4b24eec(short zc430a259a4,short zebca149147);static void mdlInitializeSizes(SimStruct*S){int z26dbd73a5e;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n""\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x543+7688-0x234b));ssSetNumDiscStates(S,(0xeca+4749-0x2157));ssSetNumInputPorts(S,(0x9d3+5096-0x1dbb));ssSetNumOutputPorts(S,(0x434+8764-0x2670));ssSetNumSampleTimes(S,(0x12bf+194-0x1380));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1e3d+1170-0x22cf));ssSetNumNonsampledZCs(S,(0xf56+4063-0x1f35));for(z26dbd73a5e=(0x18e6+3052-0x24d2);z26dbd73a5e<zdf24515981;z26dbd73a5e++)ssSetSFcnParamNotTunable(S,z26dbd73a5e);ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);return;}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x143+3075-0xd46),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xe58+2861-0x1985),FIXED_IN_MINOR_STEP_OFFSET);}
#ifndef MATLAB_MEX_FILE
static const struct ze2ec40958f{uint16_T id;const char*zd7653867c6;}zca0e1c304e[]={{9232,"\x38\x32\x38\x30\x31\x41\x41\x5f\x30"},{9248,"\x38\x32\x38\x30\x31\x41\x42\x5f\x30"},{9280,"\x38\x32\x38\x30\x31\x42\x41\x5f\x30"},{9292,"\x38\x32\x38\x30\x31\x42\x41\x5f\x31\x30"},{9296,"\x38\x32\x38\x30\x31\x45\x5f\x30"},{9344,"\x38\x32\x38\x30\x31\x43\x41\x5f\x30"},{9356,"\x38\x32\x38\x30\x31\x43\x41\x5f\x31\x32"},{9408,"\x38\x32\x38\x30\x31\x44\x42\x5f\x30"},{9420,"\x38\x32\x38\x30\x31\x44\x42\x5f\x31\x32"},{9424,"\x38\x32\x38\x30\x31\x45\x42\x5f\x30"},{9633,"\x36\x33\x30\x30\x45\x53\x42\x20\x4c\x49\x42"},{9792,"\x49\x43\x48\x36\x5f\x30"},{9793,"\x49\x43\x48\x36\x5f\x31"},{9794,"\x49\x43\x48\x36\x5f\x32"},{10168,"\x49\x43\x48\x37"},{10512,"\x49\x43\x48\x39"},{10520,"\x49\x43\x48\x39"},{(0xe72+4554-0x203c),NULL}};
#endif
#define BIT(n) ((0x1074+909-0x1400) << (n))
#define z3014320d12 BIT((0x7a4+1437-0xd41))
#define zb478812b1b BIT((0x1bb+457-0x381))
#define zde6207d0a1 BIT((0xd4a+4779-0x1fe4))
#define zc85d2e55e9  BIT((0x1218+549-0x142b))
#define zf759b7c5fe (z3014320d12 | zb478812b1b | zde6207d0a1 | zc85d2e55e9)

void z4df50f1dda(void){
#ifndef MATLAB_MEX_FILE
uint32_T z9e92215ca6;xpcOutpDW((0x22cf+3021-0x21a4),2147483648|((0xdd2+5163-0x21de)<<(0xfb2+4083-0x1f9a)));z9e92215ca6=xpcInpDW((0xff7+2075-0xb16));
#endif
}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
int32_T*i=ssGetIWork(S),z812c65ff2f;xpcPCIDevice zeccbadd9b3;struct ze2ec40958f*zb996cda81b;uint32_T z663e47f260;
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
if(!xpceIsModelInit()){return;}z4df50f1dda();for(zb996cda81b=zca0e1c304e;zb996cda81b->id>(0x67b+4347-0x1776);zb996cda81b++){if(xpcGetPCIDeviceInfo(32902,zb996cda81b->id,XPC_NO_SUB,XPC_NO_SUB,(0xbd7+6100-0x23ab),(0x10fd+1355-0x1629),&zeccbadd9b3)==(0xe94+5856-0x2574)){break;}}i[z35b267a35d]=zb996cda81b->id;printf("\x20\x20\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x72\x65\x61\x6c\x2d\x74\x69\x6d\x65\x20\x74\x61\x72\x67\x65\x74\x20\x6d\x61\x63\x68\x69\x6e\x65\x3a" "\n");if(zb996cda81b->id==(0xf16+3851-0x1e21)){printf("\x20\x20\x20\x20\x55\x6e\x73\x75\x70\x70\x6f\x72\x74\x65\x64\x20\x63\x68\x69\x70\x73\x65\x74\x20\x66\x6f\x75\x6e\x64\x21" "\n");printf("\x20\x20\x20\x20\x50\x6f\x74\x65\x6e\x74\x69\x61\x6c\x6c\x79\x20\x6e\x6f\x74\x20\x61\x6c\x6c\x20\x53\x4d\x49\x73\x20\x64\x69\x73\x61\x62\x6c\x65\x64" "\n");return;}else{printf("\x20\x20\x20\x20\x41\x6c\x6c\x20\x53\x4d\x49\x73\x20\x66\x6f\x72\x20\x25\x73\x20\x63\x68\x69\x70\x73\x65\x74\x20\x64\x69\x73\x61\x62\x6c\x65\x64" "\n",zb996cda81b->zd7653867c6);printf("\x20\x20\x20\x20\x52\x65\x61\x6c\x2d\x74\x69\x6d\x65\x20\x62\x65\x68\x61\x76\x69\x6f\x72\x20\x67\x75\x61\x72\x61\x6e\x74\x65\x65\x64" "\n");}
xpcOutpDW((0x2471+291-0x189c),2147483648|((0x135b+1448-0x18e4)<<(0x1e57+369-0x1fbd))|(0x91a+164-0x97e));z663e47f260=xpcInpDW((0x1707+456-0xbd3))&(uint32_T)((0x25f+823-0x397)<<(0x65+1970-0x810));





i[z8f49cf4196]=z663e47f260+(0x1a5+1218-0x637);i[zf24010f582]=z663e47f260+(0x1f43+1149-0x2394);i[z412d1ea254]=z663e47f260;i[zf95459c125]=(uint32_T)xpcInpDW((uint16_T)i[z8f49cf4196]);
i[z0f0ee58ec5]=(uint32_T)xpcInpDW((uint16_T)i[zf24010f582]);xpcOutpDW((uint16_T)i[z8f49cf4196],(uint32_T)i[zf95459c125]&~zf759b7c5fe);

xpcOutpDW(((uint16_T)(z663e47f260+(0x169+9013-0x246a))),65535);

#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE



#endif 
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T*i=(uint32_T*)ssGetIWork(S);if(i[z35b267a35d]==(0xb24+6881-0x2605))return;xpcOutpDW((uint16_T)i[z8f49cf4196],i[zf95459c125]);xpcOutpDW((uint16_T)i[zf24010f582],i[z0f0ee58ec5]);
#endif
}
#ifndef MATLAB_MEX_FILE
static void z94d4b24eec(short zc430a259a4,short zebca149147){unsigned long zdcdadfc170;unsigned long z794bbc97f5,z2a39f7dd4f;xpcOutpDW(3320,(2147483648|(0x216d+15-0x215d)<<(0xa61+7295-0x26d5)|(0x1417+2270-0x1cb5)));zdcdadfc170=xpcInpDW((0x198c+5221-0x20f5));zdcdadfc170&=65408;
z794bbc97f5=xpcInpDW((uint16_T)(zdcdadfc170+(0x233a+654-0x2598)));z2a39f7dd4f=xpcInpDW((uint16_T)(zdcdadfc170+(0x9b2+6648-0x2376)));
if(zebca149147==(0xa8f+5021-0x1e2b))xpcOutpDW((uint16_T)(zdcdadfc170+(0x18ba+3183-0x24f5)),4294967295);z2a39f7dd4f=xpcInpDW((uint16_T)(zdcdadfc170+(0x1c44+1558-0x2226)));
if(zc430a259a4==(0x48b+1290-0x994))xpcOutpDW((uint16_T)(zdcdadfc170+(0x244+60-0x250)),(0x80a+2022-0xff0));z794bbc97f5=xpcInpDW((uint16_T)(zdcdadfc170+(0x109+9448-0x25c1)));
}
#endif
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

