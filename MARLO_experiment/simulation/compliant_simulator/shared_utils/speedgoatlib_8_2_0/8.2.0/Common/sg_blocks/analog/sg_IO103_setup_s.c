/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xafd+4258-0x1b9d)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO103_setup_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x30\x33"
#define z694756a014 (0x25ac+2478-0x1ea5)
#define zea87e0ba83 36992
#define z29146a1837 (0x1808+2983-0x12fa)
#define zab7e64468b 10361
#define zdf24515981          ((0xce1+3297-0x19b6))
#define z8fd86139be               ssGetSFcnParam(S,(0x142+3308-0xe2e))
#define zd6d6a44c19                 ssGetSFcnParam(S,(0x1490+2623-0x1ece))
#define z702a26a5e9                ssGetSFcnParam(S,(0x502+8345-0x2599))
#define z2afc595703           ssGetSFcnParam(S,(0x1165+4014-0x2110))
#define z186580de21          ssGetSFcnParam(S,(0x278+6442-0x1b9e))
#define z79b944ae89           ssGetSFcnParam(S,(0xb30+6503-0x2492))
#define za6b3fb79a3             ssGetSFcnParam(S,(0x1c06+2363-0x253b))
#define z5317f28eb6           ssGetSFcnParam(S,(0x9e8+750-0xccf))
#define zb18e38a301           ssGetSFcnParam(S,(0xc2a+5077-0x1ff7))
#define z5bc3ce0d50           ssGetSFcnParam(S,(0x870+6626-0x2249))
#define z1f9bebb47b             ssGetSFcnParam(S,(0x2172+1372-0x26c4))
#define z2d8f240c11           ssGetSFcnParam(S,(0x1785+3963-0x26f5))
#define z2e6483d505              ((0x137b+1523-0x196c))
#define z6a0da049de         ((0xcec+2169-0x1565))
#define zc2f3e0cbc0        ((0x11d9+76-0x1224))
#define zc5ce4cb81a              ((0xb33+615-0xd98))
#define z8caad2a8e6              ((0xae9+3693-0x1956))
#define z5bfe7a2613            ((0x505+5507-0x1a87))
#define z2b17e2ee3b              ((0xf68+3939-0x1ecb))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0x1437+4406-0x246d)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x1264+1249-0x1745));ssSetNumDiscStates(S,(0x152f+747-0x181a));ssSetNumInputPorts(S,(0xe3c+1497-0x1415));ssSetNumOutputPorts(S,(0x2039+1472-0x25f9));ssSetNumSampleTimes(S,(0x8d7+567-0xb0d));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x2103+966-0x24c9));ssSetNumNonsampledZCs(S,(0xf43+1396-0x14b7));for(i=(0x123+150-0x1b9);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xf1+787-0x404));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x10fd+5209-0x2556),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1a55+11-0x1a60),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T range,z8b9d33e44f,out,count;uint32_T zf91d71c6d9=(uint32_T)mxGetN(z2afc595703);if((int_T)mxGetPr(z702a26a5e9)[(0x13d7+1979-0x1b92)]<(0x4b8+8127-0x2477)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x1d91+287-0x1eaf)){z366b2f03bf=(0x10a+4872-0x1412);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x9b3+2222-0x1261)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x56b+4983-0x18e2)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x17e3+2343-0x2109)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x1374+2241-0x1b36))|((z366b2f03bf&(0xe71+5873-0x2463))<<(0x8c9+5121-0x1cc2)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x17ac+3072-0x23aa)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x6ea+5793-0x1d4b),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,zc2f3e0cbc0,(uint32_T)zf91d71c6d9);switch((uint16_T)mxGetPr(z8fd86139be)[(0xe8a+4127-0x1ea9)]){case(0x3+483-0x1e5):ssSetRWorkValue(S,z8caad2a8e6,3276.8);ssSetRWorkValue(S,z5bfe7a2613,10.0);range=(0x9b4+553-0xbdb);break;case(0x233+8380-0x22ed):ssSetRWorkValue(S,z8caad2a8e6,6553.6);ssSetRWorkValue(S,z5bfe7a2613,5.0);range=(0x14da+3029-0x20ae);break;case(0x1bdf+1621-0x2231):ssSetRWorkValue(S,z8caad2a8e6,13107.2);ssSetRWorkValue(S,z5bfe7a2613,2.5);range=(0x2bb+7051-0x1e46);break;}if((uint16_T)mxGetPr(z186580de21)[(0xba6+4979-0x1f19)]==(0x1959+2571-0x2363)){z8b9d33e44f=(0x1860+727-0x1b37);}else{z8b9d33e44f=(0x857+4990-0x1bd4);}za42cf7dd4a[(0xf3+7837-0x1f90)]=(0x773+4162-0x1475)|(range<<(0x12a+9565-0x2683))|z8b9d33e44f;
out=(0xba3+6335-0x2186);switch(zf91d71c6d9){case(0xeef+2319-0x17fd):out|=(0x1ac9+953-0x1682)|(((uint32_T)mxGetPr(z2afc595703)[(0x570+3615-0x138f)]-(0xa28+7130-0x2601))<<(0xf2+6419-0x19f9));break;case(0x670+4527-0x181d):out|=131072;break;case(0x33b+490-0x521):out|=(0x1712+691-0x19c5);break;case(0x4c6+3196-0x113a):out|=(0x176b+1139-0x1bdd);break;case(0xb11+328-0xc49):out|=(0x3d3+2207-0xc70);break;case(0x1f74+401-0x20e5):out|=(0x9ca+7106-0x2589);break;}za42cf7dd4a[(0x217f+220-0x2253)]=out;
za42cf7dd4a[(0x134b+4998-0x26ce)]=32768;start=rl32eGetTicksDouble();while(za42cf7dd4a[(0x1026+455-0x11ea)]&32768){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*1.0){
sprintf(zea4cd01646,"\x20\x20\x25\x73\x20\x66\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x63\x6c\x65\x61\x72\x20\x61\x6e\x61\x6c\x6f\x67\x20\x69\x6e\x70\x75\x74\x20\x46\x49\x46\x4f",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}za42cf7dd4a[(0x1c44+2407-0x25a8)]=(0xf81+5295-0x2430);
if(xpceIsModelInit()&&((int)mxGetPr(zd6d6a44c19)[(0x1239+2109-0x1a76)]==(0x48a+4718-0x16f7))){za42cf7dd4a[(0x42b+5857-0x1b0c)]=8192;start=rl32eGetTicksDouble();printf("\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x73\x74\x61\x72\x74\x65\x64\x2e\x2e" "\n",zf1b619edf2);while((za42cf7dd4a[(0x770+2454-0x1106)]&8192)==8192){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*7.0){
sprintf(zea4cd01646,"\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x74\x69\x6d\x65\x64\x20\x6f\x75\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}if((za42cf7dd4a[(0x815+7493-0x255a)]&16384)==16384)
printf("\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x73\x75\x63\x63\x65\x65\x64\x65\x64\x2e" "\n",zf1b619edf2);else{sprintf(zea4cd01646,"\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x66\x61\x69\x6c\x65\x64",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T zf91d71c6d9=mxGetN(z79b944ae89);real_T z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6);real_T offset=ssGetRWorkValue(S,z5bfe7a2613);uint16_T i;volatile uint32_T*za42cf7dd4a;int32_T out;uint16_T z4e3026977c;real_T zd3add15c40,zbd0243c03e;uint16_T first=(0x390+2189-0xc1c);real_T scale=3276.8;uint32_T z718c4c15f4;za42cf7dd4a=(void*)base;
if(xpceIsModelInit()){for(i=(0xa83+5304-0x1f3b);i<(0xccb+1738-0x138d);i++){if(first){first=(0x55b+653-0x7e8);}else{za42cf7dd4a[(0x16b9+3168-0x2313)]=out|(z4e3026977c<<(0xc80+1726-0x132e));}z4e3026977c=i;out=(int32_T)((0.0+offset)*z0754dd67cc);if(out>65535)out=65535;if(out<(0x542+2500-0xf06))out=(0x1732+3378-0x2464);}za42cf7dd4a[(0x10ba+3146-0x1cfe)]=out|(z4e3026977c<<(0x1d72+1880-0x24ba))|1572864;za42cf7dd4a[(0x2046+890-0x23c0)]=za42cf7dd4a[(0x804+2207-0x10a3)]|(0x23af+1674-0x2239);}
first=(0x1d2+2262-0xaa7);for(i=(0xde9+1156-0x126d);i<zf91d71c6d9;i++){if(xpceIsModelInit()||(int)mxGetPr(za6b3fb79a3)[i]){if(first){first=(0x1a8f+1436-0x202b);}else{za42cf7dd4a[(0x42a+1821-0xb41)]=out|(z4e3026977c<<(0x947+5881-0x2030));}z4e3026977c=(uint16_T)mxGetPr(z79b944ae89)[i]-(0x15cd+947-0x197f);out=(int32_T)(((real_T)mxGetPr(z5317f28eb6)[i]+offset)*z0754dd67cc);if(out>65535)out=65535;if(out<(0x169d+3635-0x24d0))out=(0x1284+3863-0x219b);}}if(first==(0x180c+84-0x1860)){za42cf7dd4a[(0x10ed+4976-0x2457)]=out|(z4e3026977c<<(0x12d6+4094-0x22c4))|1572864;za42cf7dd4a[(0xe8b+3657-0x1cd4)]=za42cf7dd4a[(0x7b7+2598-0x11dd)]|(0x24f8+1977-0x24b1);}z718c4c15f4=(0x2a5+9142-0x265b);for(i=(0x711+1270-0xc07);i<(uint16_T)mxGetPr(z5bc3ce0d50)[i];i++){if(xpceIsModelInit()||(int)mxGetPr(z1f9bebb47b)[i]){z4e3026977c=(uint32_T)mxGetPr(z5bc3ce0d50)[i]-(0xf6+8505-0x222e);out=(real_T)mxGetPr(z2d8f240c11)[i];if(out>=THRESHOLD){z718c4c15f4|=(0x8a3+3557-0x1687)<<z4e3026977c;}}}za42cf7dd4a[(0x252+9079-0x25c0)]=z718c4c15f4;
#endif    
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

