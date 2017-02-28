/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x121b+2393-0x1b72)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO102_setup_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x30\x32"
#define z694756a014 (0x1b59+1765-0x1189)
#define zea87e0ba83 36992
#define z29146a1837 4277
#define zab7e64468b 9218
#define zdf24515981          ((0x294+8289-0x22e9))
#define z8fd86139be               ssGetSFcnParam(S,(0xc11+4248-0x1ca9))
#define zd6d6a44c19                 ssGetSFcnParam(S,(0x13a1+688-0x1650))
#define z702a26a5e9                ssGetSFcnParam(S,(0x1fa+8400-0x22c8))
#define z2afc595703           ssGetSFcnParam(S,(0x11e4+1137-0x1652))
#define z186580de21          ssGetSFcnParam(S,(0x952+6233-0x21a7))
#define z79b944ae89           ssGetSFcnParam(S,(0xe04+3908-0x1d43))
#define za6b3fb79a3             ssGetSFcnParam(S,(0x16bd+776-0x19bf))
#define z5317f28eb6           ssGetSFcnParam(S,(0x10e3+5531-0x2677))
#define zb18e38a301           ssGetSFcnParam(S,(0xe9+3254-0xd97))
#define z5bc3ce0d50           ssGetSFcnParam(S,(0x1aa2+2203-0x2334))
#define z1f9bebb47b             ssGetSFcnParam(S,(0x5bf+2903-0x110c))
#define z2d8f240c11           ssGetSFcnParam(S,(0x1df7+453-0x1fb1))
#define z2e6483d505              ((0xa13+2919-0x1578))
#define z6a0da049de         ((0x11ac+4721-0x241d))
#define zc2f3e0cbc0        ((0x104a+3830-0x1f3f))
#define zc5ce4cb81a              ((0x479+8661-0x264c))
#define z8caad2a8e6              ((0x104b+1180-0x14e7))
#define z5bfe7a2613            ((0x3d+266-0x146))
#define z2b17e2ee3b              ((0x14da+461-0x16a7))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0x792+7822-0x2520)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x99c+4588-0x1b88));ssSetNumDiscStates(S,(0x13df+348-0x153b));ssSetNumInputPorts(S,(0xf6+1379-0x659));ssSetNumOutputPorts(S,(0xbcc+1916-0x1348));ssSetNumSampleTimes(S,(0x15da+3020-0x21a5));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1f27+511-0x2126));ssSetNumNonsampledZCs(S,(0x3f4+3344-0x1104));for(i=(0x429+2359-0xd60);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1339+835-0x167c));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x304+1918-0xa82),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x138f+4402-0x24c1),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T range,z8b9d33e44f,out;uint32_T zf91d71c6d9=(uint32_T)mxGetN(z2afc595703);if((int_T)mxGetPr(z702a26a5e9)[(0x1c4+4176-0x1214)]<(0x13a6+478-0x1584)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xe4+2348-0xa0f)){z366b2f03bf=(0xa63+5690-0x209d);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x7ef+7819-0x267a)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0xcb2+4636-0x1ece)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xb9b+6393-0x2493)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x2cc+346-0x327))|((z366b2f03bf&(0xcf8+3073-0x17fa))<<(0x436+2084-0xc52)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x834+326-0x978)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x1ff0+1637-0x2615),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,zc2f3e0cbc0,(uint32_T)zf91d71c6d9);
if(xpceIsModelInit()&&((int)mxGetPr(zd6d6a44c19)[(0x14c6+1484-0x1a92)]==(0x171b+170-0x17c4))){za42cf7dd4a[(0x6db+6426-0x1ff5)]=8192;start=rl32eGetTicksDouble();printf("\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x73\x74\x61\x72\x74\x65\x64\x2e\x2e" "\n",zf1b619edf2);while((za42cf7dd4a[(0x13d5+1244-0x18b1)]&(0x24ac+8212-0x24c0))==(0x266c+7240-0x22b4)){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*7.0){
sprintf(zea4cd01646,"\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x74\x69\x6d\x65\x64\x20\x6f\x75\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}if((za42cf7dd4a[(0x1076+1520-0x1666)]&16384)==16384)
printf("\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x73\x75\x63\x63\x65\x65\x64\x65\x64\x2e" "\n",zf1b619edf2);else{sprintf(zea4cd01646,"\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x66\x61\x69\x6c\x65\x64",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}switch((uint16_T)mxGetPr(z8fd86139be)[(0x8d7+6966-0x240d)]){case(0x5b8+3021-0x1184):ssSetRWorkValue(S,z8caad2a8e6,3276.8);ssSetRWorkValue(S,z5bfe7a2613,10.0);range=(0x8b3+1682-0xf43);break;case(0x13a7+1344-0x18e5):ssSetRWorkValue(S,z8caad2a8e6,6553.6);ssSetRWorkValue(S,z5bfe7a2613,5.0);range=(0x191+5119-0x158f);break;case(0x11c9+2636-0x1c12):ssSetRWorkValue(S,z8caad2a8e6,13107.2);ssSetRWorkValue(S,z5bfe7a2613,2.5);range=(0x1219+4733-0x2496);break;}if((uint16_T)mxGetPr(z186580de21)[(0x1080+5302-0x2536)]==(0xc9f+1599-0x12dd)){z8b9d33e44f=(0x14e7+4093-0x24e4);}else{z8b9d33e44f=(0xa08+2784-0x14e7);}za42cf7dd4a[(0x3ec+4125-0x1409)]=(0x1791+342-0x15a7)|(range<<(0x1588+2245-0x1e49))|z8b9d33e44f;
out=(0x1082+1659-0x1421);switch(zf91d71c6d9){case(0xbcd+4273-0x1c7d):out|=(0xd8d+5261-0x1a1a)|(((uint32_T)mxGetPr(z2afc595703)[(0x699+5806-0x1d47)]-(0x1356+482-0x1537))<<(0x1071+632-0x12dd));break;case(0x407+7106-0x1fc7):out|=131072;break;case(0x166d+3486-0x2407):out|=(0x948+238-0xa36);break;case(0x17f+9464-0x266f):out|=(0xe57+5445-0x239b);break;case(0x180c+1318-0x1d22):out|=(0xf3b+1789-0x1636);break;case(0xab2+2459-0x142d):out|=(0x13f7+484-0x15d8);break;}za42cf7dd4a[(0xaa7+202-0xb69)]=out;
za42cf7dd4a[(0x2d0+942-0x67b)]=32768;start=rl32eGetTicksDouble();while(za42cf7dd4a[(0x966+4702-0x1bc1)]&32768){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*1.0){
sprintf(zea4cd01646,"\x20\x20\x25\x73\x20\x66\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x63\x6c\x65\x61\x72\x20\x61\x6e\x61\x6c\x6f\x67\x20\x69\x6e\x70\x75\x74\x20\x46\x49\x46\x4f",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}za42cf7dd4a[(0x1676+2051-0x1e76)]=(0xa7b+4458-0x1be5);za42cf7dd4a[(0x571+984-0x940)]=524288;
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T zf91d71c6d9=mxGetN(z79b944ae89);real_T z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6);real_T offset=ssGetRWorkValue(S,z5bfe7a2613);uint16_T i;volatile uint32_T*za42cf7dd4a;int32_T out;uint16_T z4e3026977c;real_T zd3add15c40,zbd0243c03e;uint16_T first=(0x1cfd+847-0x204b);real_T scale=3276.8;uint32_T z718c4c15f4;size_t z410dae3cab;bool zd31d76284c;za42cf7dd4a=(void*)base;

if(xpceIsModelInit()){for(i=(0x17d4+3368-0x24fc);i<(0x2445+531-0x2654);i++){if(first){first=(0xbcf+5796-0x2273);}else{za42cf7dd4a[(0x148d+1735-0x1b4e)]=out|(z4e3026977c<<(0x14a6+4605-0x2693));
}z4e3026977c=i;out=(int32_T)((0.0+offset)*z0754dd67cc);if(out>65535)out=65535;if(out<(0x5db+4703-0x183a))out=(0x9b7+5135-0x1dc6);}za42cf7dd4a[(0x1cd5+2360-0x2607)]=out|(z4e3026977c<<(0x12da+3094-0x1ee0))|786432;
za42cf7dd4a[(0xfd2+3238-0x1c78)]=za42cf7dd4a[(0x132a+305-0x145b)]|(0xd07+1904-0xc77);
}
first=(0xed0+3238-0x1b75);z410dae3cab=mxGetNumberOfElements(za6b3fb79a3);

for(i=(0xb45+6935-0x265c);i<zf91d71c6d9;i++){zd31d76284c=(z410dae3cab>(0x10c0+2006-0x1895))?(int)mxGetPr(za6b3fb79a3)[i]:(int)mxGetPr(za6b3fb79a3)[(0xee7+1569-0x1508)];
if(xpceIsModelInit()||zd31d76284c){if(first){first=(0xcf1+6410-0x25fb);}else{za42cf7dd4a[(0xb97+6332-0x244d)]=out|(z4e3026977c<<(0x16a1+1034-0x1a9b));}z4e3026977c=(uint16_T)mxGetPr(z79b944ae89)[i]-(0xbf4+3048-0x17db);out=(int32_T)(((real_T)mxGetPr(z5317f28eb6)[i]+offset)*z0754dd67cc);if(out>65535)out=65535;if(out<(0x135+173-0x1e2))out=(0x9bf+1656-0x1037);}}if(first==(0x253f+349-0x269c)){za42cf7dd4a[(0x11f+7862-0x1fcf)]=out|(z4e3026977c<<(0xb3b+210-0xbfd))|786432;za42cf7dd4a[(0x1cd5+2329-0x25ee)]=za42cf7dd4a[(0xe23+276-0xf37)]|(0xb80+6104-0x1b58);}z718c4c15f4=za42cf7dd4a[(0x23f+9071-0x25a5)]&65280;
z410dae3cab=mxGetNumberOfElements(z1f9bebb47b);

for(i=(0x391+2735-0xe40);i<(uint16_T)mxGetPr(z5bc3ce0d50)[i];i++){zd31d76284c=(z410dae3cab>(0xaa3+841-0xdeb))?(int)mxGetPr(z1f9bebb47b)[i]:(int)mxGetPr(z1f9bebb47b)[(0x1da2+2385-0x26f3)];
if(xpceIsModelInit()||zd31d76284c){z4e3026977c=(uint32_T)mxGetPr(z5bc3ce0d50)[i]-(0x1312+5070-0x26df);out=(real_T)mxGetPr(z2d8f240c11)[i];if(out>=THRESHOLD){z718c4c15f4|=(0x940+3789-0x180c)<<(z4e3026977c+(0xdb1+1428-0x133d));}else{z718c4c15f4&=~((0x34+2225-0x8e4)<<(z4e3026977c+(0x15d9+1030-0x19d7)));}}}
za42cf7dd4a[(0xa87+1683-0x1111)]=524288|z718c4c15f4;
#endif    
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

