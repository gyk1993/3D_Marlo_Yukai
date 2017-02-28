/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xa4d+1624-0x10a3)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO112_setup_s
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
#define zf1b619edf2 "\x50\x4d\x43\x2d\x31\x38\x41\x49\x33\x32\x53\x53\x43"
#define z694756a014 (0x136d+6648-0x1cb0)
#define zea87e0ba83 36950
#define z29146a1837 (0x173f+5819-0x1d45)
#define zab7e64468b 13361
#define zdf24515981          ((0x1977+2319-0x227e))
#define zd6d6a44c19                 ssGetSFcnParam(S,(0x54a+5170-0x197c))
#define z1c6ce8e1bc           ssGetSFcnParam(S,(0x1ac6+1684-0x2159))
#define z702a26a5e9                ssGetSFcnParam(S,(0x2071+1593-0x26a8))
#define z2afc595703           ssGetSFcnParam(S,(0x853+3363-0x1573))
#define zea2279958e             ssGetSFcnParam(S,(0x9f+6186-0x18c5))
#define z186580de21          ssGetSFcnParam(S,(0x19c2+1296-0x1ecd))
#define z8305e81beb            ssGetSFcnParam(S,(0x1437+917-0x17c6))
#define z2f0cae928e        ssGetSFcnParam(S,(0x2c2+4672-0x14fb))
#define z2e6483d505              ((0x8f8+6113-0x20d7))
#define z6a0da049de         ((0x293+824-0x5cb))
#define zc2f3e0cbc0        ((0x191+4567-0x1367))
#define zc5ce4cb81a              ((0xb3a+3896-0x1a70))
#define z8caad2a8e6              ((0x182a+799-0x1b49))
#define z5bfe7a2613            ((0x1f9+2278-0xade))
#define z2b17e2ee3b              ((0x2c4+7164-0x1ec0))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0xc2c+2662-0x1592)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x1a7+8043-0x2112));ssSetNumDiscStates(S,(0x1401+1301-0x1916));ssSetNumInputPorts(S,(0x1b7c+917-0x1f11));ssSetNumOutputPorts(S,(0x1423+2963-0x1fb6));ssSetNumSampleTimes(S,(0x180b+1446-0x1db0));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1fd5+60-0x2011));ssSetNumNonsampledZCs(S,(0x2a5+7164-0x1ea1));for(i=(0x1a13+1798-0x2119);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x30f+6067-0x1ac2));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x736+4305-0x1807),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xca+1667-0x74d),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T z2c1768fde6,z8b9d33e44f,z0a7ca59f77,z605608625c,z80a2b1bccf,out,z4e3026977c,zf11c0432d9,z6acd4b4bf9,z37a693f042,zae7c2b43fb;uint32_T zf91d71c6d9=(uint32_T)mxGetPr(z2afc595703)[(0x11e6+1244-0x16c2)];if((int_T)mxGetPr(z702a26a5e9)[(0xf68+2478-0x1916)]<(0xe81+6211-0x26c4)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xc48+3270-0x190d)){z366b2f03bf=(0x13f1+3878-0x2317);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x17d1+1585-0x1e02)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x65a+4650-0x1884)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xa3+7992-0x1fda)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x3ed+920-0x686))|((z366b2f03bf&(0xabd+2670-0x142c))<<(0x12cf+4231-0x234e)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x4b5+7081-0x205c)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x4c8+5800-0x1af0),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,zc2f3e0cbc0,(uint32_T)zf91d71c6d9);switch((uint16_T)mxGetPr(zea2279958e)[(0xa20+1231-0xeef)]){case(0xe43+3693-0x1caf):z0a7ca59f77=(0xe07+192-0xec7);z2c1768fde6=(0x20b6+107-0x211f);break;case(0xd62+3698-0x1bd2):z0a7ca59f77=(0x984+3820-0x1870);z2c1768fde6=(0xdf8+2520-0x17cf);break;}switch((uint16_T)mxGetPr(z186580de21)[(0xb88+4703-0x1de7)]){case(0x74+5401-0x158c):z8b9d33e44f=(0x5bf+4022-0x1575);break;case(0x1d29+275-0x1e3a):z8b9d33e44f=(0x1b91+1928-0x2318);break;case(0x498+6457-0x1dce):z8b9d33e44f=(0x17c1+2719-0x225e);break;}if((uint16_T)mxGetPr(z1c6ce8e1bc)[(0xfa9+1142-0x141f)]==(0xbe6+6127-0x23d4)){z605608625c=(0xafa+779-0xe05);z80a2b1bccf=(0x1e78+242-0x1f67);}else{z605608625c=(0x525+2461-0xec2);z80a2b1bccf=(0xdc6+108-0xe32);}if(((uint16_T)mxGetPr(z8305e81beb)[(0x1182+4789-0x2437)]==(0xdbd+1824-0x14dc))){z37a693f042=(0x6f0+6083-0x1eb2);}else{z37a693f042=(0xd3f+995-0x1122);}if((uint16_T)mxGetPr(z2f0cae928e)[(0x5ac+5382-0x1ab2)]==(0x79+8667-0x2253)){z6acd4b4bf9=(0x17c+8640-0x233b);zae7c2b43fb=(0xce0+6221-0x252d);}else{z6acd4b4bf9=(0x2357+723-0x262a);zae7c2b43fb=(0xcb7+2479-0x1665);}za42cf7dd4a[(0x100b+5469-0x2568)]=(0x9a6+2158-0x11d4)|(z2c1768fde6<<(0x86d+3203-0x14ec))|(zae7c2b43fb<<(0x1fd+6142-0x19e9));
za42cf7dd4a[(0x900+7514-0x2652)]=(0xec5+5369-0x23b7)|(z80a2b1bccf<<(0x1403+2975-0x1f9f))|(z37a693f042<<(0x6a0+3251-0x1348));





za42cf7dd4a[(0x3ad+4862-0x16a2)]=((uint8_T)zf91d71c6d9-(0x163f+963-0x1a01))<<(0x15cf+2633-0x2010);

za42cf7dd4a[(0x964+6868-0x242a)]=(0x9f3+6995-0x2545);za42cf7dd4a[(0x1d07+2410-0x2662)]=(0x210+2107-0xa4a);za42cf7dd4a[(0x511+6251-0x1d79)]=za42cf7dd4a[(0x1072+3580-0x1e6b)]|262144;start=rl32eGetTicksDouble();while(za42cf7dd4a[(0x803+5132-0x1c0c)]&262144){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*1.0){
sprintf(zea4cd01646,"\x20\x20\x25\x73\x20\x66\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x63\x6c\x65\x61\x72\x20\x61\x6e\x61\x6c\x6f\x67\x20\x69\x6e\x70\x75\x74\x20\x46\x49\x46\x4f",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}za42cf7dd4a[(0x184c+3407-0x2598)]=(0x104a+3506-0x1dfc)|(z6acd4b4bf9<<(0x153b+994-0x1909));
if(xpceIsModelInit()&&((int)mxGetPr(zd6d6a44c19)[(0xe43+5241-0x22bc)]==(0x1473+3549-0x224f))){za42cf7dd4a[(0x13f9+3330-0x20fb)]=8192|za42cf7dd4a[(0x682+5067-0x1a4d)];start=rl32eGetTicksDouble();printf("\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x73\x74\x61\x72\x74\x65\x64\x2e\x2e" "\n",zf1b619edf2);while((za42cf7dd4a[(0xa+6085-0x17cf)]&8192)==8192){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*5.0){
sprintf(zea4cd01646,"\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x74\x69\x6d\x65\x64\x20\x6f\x75\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}

printf("\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x73\x75\x63\x63\x65\x65\x64\x65\x64\x2e" "\n",zf1b619edf2);}
if(!xpceIsModelInit()){za42cf7dd4a[(0x2a6+6124-0x1a8a)]=(0x136b+2022-0x1b31)|za42cf7dd4a[(0x1459+3291-0x212c)];}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;za42cf7dd4a=(void*)base;
if(!xpceIsModelInit()){za42cf7dd4a[(0xf30+4418-0x206a)]=~((0x602+6563-0x1f85))&za42cf7dd4a[(0x916+136-0x996)];}
#endif    
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

