/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1636+757-0x1929)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO105_setup_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x30\x35"
#define z694756a014 (0x186b+825-0xaef)
#define zea87e0ba83 36992
#define z29146a1837 (0x1f70+1500-0x1497)
#define zab7e64468b 9223
#define zdf24515981          ((0x75c+1256-0xc3f))
#define z8fd86139be               ssGetSFcnParam(S,(0x640+6583-0x1ff7))
#define zd6d6a44c19                 ssGetSFcnParam(S,(0x14fa+113-0x156a))
#define z702a26a5e9                ssGetSFcnParam(S,(0x160b+2061-0x1e16))
#define z2afc595703           ssGetSFcnParam(S,(0x7cb+4193-0x1829))
#define z186580de21          ssGetSFcnParam(S,(0x163a+279-0x174d))
#define z2e6483d505              ((0x793+3975-0x1718))
#define z6a0da049de         ((0x18d9+2400-0x2239))
#define zc2f3e0cbc0        ((0xa8c+2641-0x14dc))
#define zc5ce4cb81a              ((0x6dc+3707-0x1555))
#define z8caad2a8e6              ((0xd9c+2030-0x158a))
#define z5bfe7a2613            ((0x14d8+1632-0x1b37))
#define z2b17e2ee3b              ((0x840+4657-0x1a71))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0x18fa+751-0x1ae9)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x17c3+2819-0x22c6));ssSetNumDiscStates(S,(0x834+2337-0x1155));ssSetNumInputPorts(S,(0x823+641-0xaa4));ssSetNumOutputPorts(S,(0x962+4142-0x1990));ssSetNumSampleTimes(S,(0x15ff+10-0x1608));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xcc9+887-0x1040));ssSetNumNonsampledZCs(S,(0x599+3656-0x13e1));for(i=(0x13f+6845-0x1bfc);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x502+3076-0x1106));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x1f8+611-0x45b),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x65b+7969-0x257c),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T range,z8b9d33e44f,out;uint32_T zf91d71c6d9=(uint32_T)mxGetN(z2afc595703);if((int_T)mxGetPr(z702a26a5e9)[(0x77f+635-0x9fa)]<(0x1da0+1310-0x22be)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x1894+97-0x18f4)){z366b2f03bf=(0x153b+1226-0x1a05);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xe9a+3939-0x1dfd)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x903+740-0xbe7)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x973+1440-0xf12)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x815+336-0x866))|((z366b2f03bf&(0x2ba+6489-0x1b14))<<(0x225+3400-0xf65)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x15d1+123-0x164a)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x1061+2492-0x19dd),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,zc2f3e0cbc0,(uint32_T)zf91d71c6d9);
if(xpceIsModelInit()&&((int)mxGetPr(zd6d6a44c19)[(0x1e19+607-0x2078)]==(0x4ff+2663-0xf65))){za42cf7dd4a[(0xd8+8318-0x2156)]=8192;start=rl32eGetTicksDouble();printf("\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x73\x74\x61\x72\x74\x65\x64\x2e\x2e" "\n",zf1b619edf2);while((za42cf7dd4a[(0x1550+1836-0x1c7c)]&(0x20b9+1878-0x80f))==8192){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*7.0){
sprintf(zea4cd01646,"\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x74\x69\x6d\x65\x64\x20\x6f\x75\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}if((za42cf7dd4a[(0x63b+4942-0x1989)]&16384)==16384)
printf("\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x73\x75\x63\x63\x65\x65\x64\x65\x64\x2e" "\n",zf1b619edf2);else{sprintf(zea4cd01646,"\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x66\x61\x69\x6c\x65\x64",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}switch((uint16_T)mxGetPr(z8fd86139be)[(0x12b+887-0x4a2)]){case(0x19+7639-0x1def):ssSetRWorkValue(S,z8caad2a8e6,3276.8);ssSetRWorkValue(S,z5bfe7a2613,10.0);range=(0x53d+7014-0x20a1);break;case(0xf51+783-0x125e):ssSetRWorkValue(S,z8caad2a8e6,6553.6);ssSetRWorkValue(S,z5bfe7a2613,5.0);range=(0x141f+3659-0x2269);break;case(0x7d9+6774-0x224c):ssSetRWorkValue(S,z8caad2a8e6,13107.2);ssSetRWorkValue(S,z5bfe7a2613,2.5);range=(0x1c3b+2714-0x26d5);break;}if((uint16_T)mxGetPr(z186580de21)[(0x14d1+1103-0x1920)]==(0x1792+54-0x17c7)){z8b9d33e44f=(0x62c+4897-0x194d);}else{z8b9d33e44f=(0x615+6092-0x1de0);}za42cf7dd4a[(0x674+5877-0x1d69)]=(0xb0b+2416-0x143b)|(range<<(0x1bda+2245-0x249b))|z8b9d33e44f;out=za42cf7dd4a[(0x1537+918-0x18c5)];out=out&(0x1555+8479-0x2694);out=out|(0x1c79+888-0x1fd9);switch(zf91d71c6d9){case(0x264+5057-0x1624):out=out|(((uint32_T)mxGetPr(z2afc595703)[(0x63+4157-0x10a0)]-(0x277+4053-0x124b))<<(0x471+3237-0x110a));break;case(0x1abb+1357-0x2006):out|=(0x804+4594-0x19f5);break;case(0xe7d+6091-0x2644):out|=(0x2376+292-0x2498);break;case(0xeca+2129-0x1713):out|=(0x89c+493-0xa86);break;case(0x39c+6703-0x1dbb):out|=(0x1fd+2867-0xd2c);break;case(0x8d6+1220-0xd7a):out|=(0x1926+2249-0x21ea);break;case(0x1d7+5755-0x1812):out|=(0xb04+2440-0x1486);break;}za42cf7dd4a[(0x245+2705-0xcce)]=out;
za42cf7dd4a[(0x1cba+51-0x1cea)]=65536;start=rl32eGetTicksDouble();while(za42cf7dd4a[(0x808+4836-0x1ae9)]&65536){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*1.0){
sprintf(zea4cd01646,"\x20\x20\x25\x73\x20\x66\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x63\x6c\x65\x61\x72\x20\x61\x6e\x61\x6c\x6f\x67\x20\x69\x6e\x70\x75\x74\x20\x46\x49\x46\x4f",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}za42cf7dd4a[(0xeed+3469-0x1c77)]=(0x1510+4182-0x2566);
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

