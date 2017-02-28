/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x9a8+2975-0x1545)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO106_setup_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x30\x36"
#define z694756a014 (0x26e9+2409-0x1f9d)
#define zea87e0ba83 36950
#define z29146a1837 (0x16c7+6896-0x2102)
#define zab7e64468b 12545
#define zdf24515981          ((0x1e9b+1489-0x2466))
#define zd6d6a44c19                 ssGetSFcnParam(S,(0x2210+306-0x2342))
#define z1c6ce8e1bc           ssGetSFcnParam(S,(0x110f+124-0x118a))
#define z702a26a5e9                ssGetSFcnParam(S,(0x1067+1853-0x17a2))
#define z2afc595703           ssGetSFcnParam(S,(0x1667+3216-0x22f4))
#define zea2279958e             ssGetSFcnParam(S,(0x56b+2730-0x1011))
#define z186580de21          ssGetSFcnParam(S,(0x14b9+3503-0x2263))
#define z2e6483d505              ((0x134a+3161-0x1fa1))
#define z6a0da049de         ((0x3e3+1073-0x814))
#define zc2f3e0cbc0        ((0xef2+1979-0x16ac))
#define zc5ce4cb81a              ((0xee8+2754-0x19a8))
#define z8caad2a8e6              ((0x1a9a+2721-0x253b))
#define z5bfe7a2613            ((0x1353+1360-0x18a2))
#define z2b17e2ee3b              ((0x1690+3483-0x242b))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0xa63+2948-0x14e7)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xc42+5801-0x22eb));ssSetNumDiscStates(S,(0x7f8+1829-0xf1d));ssSetNumInputPorts(S,(0x189+9467-0x2684));ssSetNumOutputPorts(S,(0xdbb+948-0x116f));ssSetNumSampleTimes(S,(0x19f2+1125-0x1e56));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x201f+1698-0x26c1));ssSetNumNonsampledZCs(S,(0x19c7+288-0x1ae7));for(i=(0x1bb4+875-0x1f1f);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xbd8+6017-0x2359));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0xc40+5384-0x2148),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x8d2+5631-0x1ed1),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T z2c1768fde6,z8b9d33e44f,z0a7ca59f77,z605608625c,z80a2b1bccf,out,z4e3026977c,zf11c0432d9;uint32_T zf91d71c6d9=(uint32_T)mxGetPr(z2afc595703)[(0x1680+152-0x1718)];if((int_T)mxGetPr(z702a26a5e9)[(0xd87+3150-0x19d5)]<(0x193a+2921-0x24a3)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xca5+4772-0x1f48)){z366b2f03bf=(0x154c+2758-0x2012);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1609+4181-0x265e)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0xaf9+1925-0x127e)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1616+4273-0x26c6)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x25c+2089-0x986))|((z366b2f03bf&(0x4c6+8056-0x233f))<<(0x4d3+942-0x879)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x1e3d+48-0x1e6b)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0xbbc+3226-0x17d6),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,zc2f3e0cbc0,(uint32_T)zf91d71c6d9);switch((uint16_T)mxGetPr(zea2279958e)[(0x1552+432-0x1702)]){case(0x15a0+3464-0x2327):z0a7ca59f77=(0x30a+6967-0x1e41);z2c1768fde6=(0x63b+766-0x937);break;case(0x1708+3036-0x22e2):z0a7ca59f77=(0x30b+4882-0x161d);z2c1768fde6=(0x1a8c+1087-0x1eca);break;case(0x29a+11-0x2a2):z0a7ca59f77=(0x47b+5382-0x1981);z2c1768fde6=(0x24+5351-0x150b);break;case(0x89b+4519-0x1a3e):z0a7ca59f77=(0xa59+5694-0x2096);z2c1768fde6=(0x198b+3422-0x26e8);break;case(0xd01+1579-0x1327):z0a7ca59f77=(0x885+4455-0x19eb);z2c1768fde6=(0x20ac+1284-0x25b0);break;}switch((uint16_T)mxGetPr(z186580de21)[(0x5e2+4614-0x17e8)]){case(0x21aa+846-0x24f7):z8b9d33e44f=(0x24cf+515-0x26d2);break;case(0xca2+5315-0x2163):z8b9d33e44f=(0x1c8c+2426-0x2605);break;case(0x841+1722-0xef8):z8b9d33e44f=(0x20+9134-0x23cc);break;}if((uint16_T)mxGetPr(z1c6ce8e1bc)[(0xe4d+3122-0x1a7f)]==(0x40d+569-0x645)){z605608625c=(0x611+5123-0x1a14);z80a2b1bccf=(0x17d+6982-0x1cc0);}else{z605608625c=(0x1ee8+1651-0x255b);z80a2b1bccf=(0xc77+6577-0x2626);}za42cf7dd4a[(0x77d+3975-0x1704)]=262208|(z0a7ca59f77<<(0x3d4+436-0x585))|(z2c1768fde6<<(0x1f0b+1898-0x2671))|(z605608625c<<(0x109+178-0x1b4))|(z8b9d33e44f<<(0x547+804-0x863));
za42cf7dd4a[(0x26d+2587-0xc80)]=(0x5bd+8115-0x2569)|(z80a2b1bccf<<(0x3f0+6092-0x1bb9));


if(z8b9d33e44f==(0x1784+2667-0x21ed)){
za42cf7dd4a[(0x85d+4620-0x1a60)]=(((uint8_T)(zf91d71c6d9*(0x1bc6+1978-0x237e)))-(0x783+6462-0x20c0))<<(0x1483+2242-0x1d3d);}else{
za42cf7dd4a[(0xa4f+2968-0x15de)]=((uint8_T)zf91d71c6d9-(0x37f+3536-0x114e))<<(0x1b8a+2087-0x23a9);}
za42cf7dd4a[(0x3b5+2992-0xf57)]=(0x5f6+1825-0xd16);za42cf7dd4a[(0x11fb+3937-0x214d)]=(0x4b0+4098-0x14b1);za42cf7dd4a[(0xf8+5106-0x14e7)]=za42cf7dd4a[(0x332+3719-0x11b6)]|262144;start=rl32eGetTicksDouble();while(za42cf7dd4a[(0x75f+3260-0x1418)]&262144){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*1.0){
sprintf(zea4cd01646,"\x20\x20\x25\x73\x20\x66\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x63\x6c\x65\x61\x72\x20\x61\x6e\x61\x6c\x6f\x67\x20\x69\x6e\x70\x75\x74\x20\x46\x49\x46\x4f",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}za42cf7dd4a[(0x5b9+4889-0x18cf)]=(0x329+7098-0x1ee3);
if(xpceIsModelInit()&&((int)mxGetPr(zd6d6a44c19)[(0x1df7+873-0x2160)]==(0x814+4442-0x196d))){za42cf7dd4a[(0xb24+2851-0x1647)]=8192|za42cf7dd4a[(0xdd4+3351-0x1aeb)];start=rl32eGetTicksDouble();printf("\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x73\x74\x61\x72\x74\x65\x64\x2e\x2e" "\n",zf1b619edf2);while((za42cf7dd4a[(0x106a+5474-0x25cc)]&8192)==(0x22c0+4762-0x155a)){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*5.0){
sprintf(zea4cd01646,"\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x74\x69\x6d\x65\x64\x20\x6f\x75\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}

printf("\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x73\x75\x63\x63\x65\x65\x64\x65\x64\x2e" "\n",zf1b619edf2);}
if(!xpceIsModelInit()){za42cf7dd4a[(0xbbd+700-0xe79)]=(0x9a2+934-0xcc8)|za42cf7dd4a[(0x11fc+2827-0x1d07)];}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;za42cf7dd4a=(void*)base;
if(!xpceIsModelInit()){za42cf7dd4a[(0xaaa+673-0xd4b)]=~((0xee3+5615-0x2452))&za42cf7dd4a[(0x750+3743-0x15ef)];}
#endif    
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

