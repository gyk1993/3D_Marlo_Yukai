/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x10fa+4072-0x20e0)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO101_da_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x30\x31"
#define z694756a014 5845
#define zea87e0ba83 17495
#define zdf24515981          ((0x1df9+337-0x1f45))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0x278+8416-0x2358))
#define zc8bbaa6115               ssGetSFcnParam(S,(0x725+6478-0x2072))
#define zae7f89439f                ssGetSFcnParam(S,(0x3a4+1381-0x907))
#define z3832b85a32           ssGetSFcnParam(S,(0x963+7380-0x2634))
#define z702a26a5e9                ssGetSFcnParam(S,(0x864+7626-0x262a))
#define z2e6483d505              ((0x914+3022-0x14e0))
#define z7e2eeaa57c          ((0x16c2+2522-0x209c))
#define z6a0da049de         ((0x318+7302-0x1f9d))
#define zc5ce4cb81a              ((0x5a3+3787-0x145e))
#define z2b17e2ee3b              ((0x1ee0+1066-0x230a))
static char_T zea4cd01646[(0x1254+4101-0x2159)];
#ifndef MATLAB_MEX_FILE
static void z14abefc6ac(volatile uint32_T*za42cf7dd4a,SimStruct*S){real_T start,z19c4ca5f82;
start=rl32eGetTicksDouble();
while((za42cf7dd4a[(0x12aa+151-0x1327)]&(0x10+7123-0x1be2))==(0x5e4+4413-0x1721)){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*0.1){

sprintf(zea4cd01646,"\x25\x73\x20\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x64\x61\x74\x61\x20\x72\x65\x74\x72\x69\x65\x76\x61\x6c\x20\x74\x69\x6d\x65\x64\x20\x6f\x75\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}
}
}static void ze60f8e9903(uint32_T z4e3026977c,real_T*zd3add15c40,real_T*zbd0243c03e,volatile uint32_T*za42cf7dd4a,SimStruct*S){uint32_T z7be9105675,z548bd6fb7c;int16_T offset,z0754dd67cc;z548bd6fb7c=z4e3026977c*(0x19d4+139-0x1a5b)+(0x22f+1753-0x907);za42cf7dd4a[(0x9f3+6141-0x21d7)]=((0x183+3566-0xf70)<<(0x125b+3977-0x21d5))|(z548bd6fb7c<<(0x1271+3386-0x1fa3));
z14abefc6ac(za42cf7dd4a,S);z7be9105675=(za42cf7dd4a[(0xff+7745-0x1f26)]>>(0x61f+6763-0x2082))&(0x2067+747-0x2253);
rl32eWaitDouble(0.001);z548bd6fb7c=z4e3026977c*(0x5e5+3170-0x1243)+(0x1708+2121-0x1f51);za42cf7dd4a[(0x3d2+2727-0xe60)]=((0x10e3+3291-0x1dbd)<<(0xeca+5331-0x238e))|(z548bd6fb7c<<(0x55c+5190-0x199a));
z14abefc6ac(za42cf7dd4a,S);z7be9105675=(za42cf7dd4a[(0x763+5484-0x1cb5)]&65280)|z7be9105675;
offset=(int16_T)z7be9105675;rl32eWaitDouble(0.001);z548bd6fb7c=z4e3026977c*(0x5a9+3664-0x13f5)+(0x34b+6952-0x1e70);za42cf7dd4a[(0x62a+5481-0x1b7a)]=((0x18cc+2614-0x2301)<<(0xe80+5293-0x231e))|(z548bd6fb7c<<(0x2f8+4205-0x135d));
z14abefc6ac(za42cf7dd4a,S);z7be9105675=(za42cf7dd4a[(0x56f+1127-0x9bc)]>>(0xc19+2934-0x1787))&(0x16ed+2860-0x211a);
rl32eWaitDouble(0.001);z548bd6fb7c=z4e3026977c*(0x3b5+8072-0x2339)+(0x1243+2214-0x1ae7);za42cf7dd4a[(0x525+2878-0x104a)]=((0x11d2+4851-0x24c4)<<(0x9c1+5823-0x2071))|(z548bd6fb7c<<(0xd84+3572-0x1b70));
z14abefc6ac(za42cf7dd4a,S);z7be9105675=(za42cf7dd4a[(0xd11+4655-0x1f26)]&65280)|z7be9105675;
z0754dd67cc=(int16_T)z7be9105675;rl32eWaitDouble(0.001);
*zd3add15c40=((z0754dd67cc/1.0e6)+(0xa71+5739-0x20db))*3276.75;*zbd0243c03e=offset/100.0;}
#endif
static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xb21+208-0xbf1));ssSetNumDiscStates(S,(0x570+4538-0x172a));ssSetNumOutputPorts(S,(0x150d+4039-0x24d4));ssSetNumInputPorts(S,(int)mxGetN(za9d8fb6bcf));for(i=(0x2630+119-0x26a7);i<(int)mxGetN(za9d8fb6bcf);i++){ssSetInputPortWidth(S,i,(0x4ec+1693-0xb88));ssSetInputPortDirectFeedThrough(S,i,(0x3ba+4709-0x161e));ssSetInputPortRequiredContiguous(S,i,(0x8d8+6700-0x2303));}ssSetNumSampleTimes(S,(0xaf+8121-0x2067));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x365+4507-0x1500));ssSetNumNonsampledZCs(S,(0x76a+3373-0x1497));for(i=(0x56+3513-0xe0f);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x15ad+1439-0x1b4c));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x1509+1728-0x1bc9)]==-1.0){ssSetSampleTime(S,(0x3b5+1281-0x8b6),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x539+5413-0x1a5e),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x9cc+499-0xbbf),mxGetPr(z3832b85a32)[(0x4f0+1823-0xc0f)]);ssSetOffsetTime(S,(0x1f5+5451-0x1740),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;real_T scale;uint16_T zf91d71c6d9=(int)mxGetN(za9d8fb6bcf);if((int_T)mxGetPr(z702a26a5e9)[(0x6ac+6614-0x2082)]<(0x4b6+5057-0x1877)){if(rl32eGetPCIInfo((uint16_T)z694756a014,(uint16_T)zea87e0ba83,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xa13+6721-0x2453)){z366b2f03bf=(0x4ca+8333-0x2557);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x106d+4679-0x22b4)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x18bc+1182-0x1d5a)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1010+327-0x1156)];}if(rl32eGetPCIInfoAtSlot((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(z441f9e6d1b&(0xd8d+4982-0x2004))|((z366b2f03bf&(0x680+5782-0x1c17))<<(0x1663+3168-0x22bb)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x1c1b+1381-0x2180)];Virtual=rl32eGetDevicePtr(z1cf2c50191,4096,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,z7e2eeaa57c,zf91d71c6d9);

{uint32_T i;real_T zd3add15c40,zbd0243c03e;for(i=(0x283+7512-0x1fdb);i<(0x3b2+1012-0x79e);i++){ze60f8e9903(i,&zd3add15c40,&zbd0243c03e,za42cf7dd4a,S);ssSetRWorkValue(S,i*(0xa92+2909-0x15ed),zd3add15c40);ssSetRWorkValue(S,i*(0x9e3+4233-0x1a6a)+(0xa0a+3488-0x17a9),zbd0243c03e);}}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T zf91d71c6d9=ssGetIWorkValue(S,z7e2eeaa57c);uint16_T i;volatile uint32_T*za42cf7dd4a;real_T*zc7fdaf6331;int32_T out;uint16_T z4e3026977c;real_T zd3add15c40,zbd0243c03e;uint16_T first;za42cf7dd4a=(void*)base;first=(0xc30+4870-0x1f35);for(i=(0x68+9662-0x2626);i<zf91d71c6d9;i++){if(first){first=(0x100b+382-0x1189);}else{za42cf7dd4a[(0x182b+2674-0x2291)]=(uint32_T)out;}z4e3026977c=(uint16_T)mxGetPr(za9d8fb6bcf)[i]-(0x1c19+327-0x1d5f);zd3add15c40=ssGetRWorkValue(S,z4e3026977c*(0x6d4+2584-0x10ea));zbd0243c03e=ssGetRWorkValue(S,z4e3026977c*(0x1c72+1077-0x20a5)+(0xf9f+5737-0x2607));zc7fdaf6331=(real_T*)ssGetInputPortRealSignal(S,i);out=(int32_T)(((zc7fdaf6331[(0x623+160-0x6c3)]+10.0)*zd3add15c40)-zbd0243c03e);
if(out>65535){out=65535;}if(out<(0x5db+6324-0x1e8f)){out=(0x4f+5458-0x15a1);}
out=out|(z4e3026977c<<(0x216f+1209-0x2618));}

out=out|((0xc86+1874-0x13d7)<<(0x19+4215-0x107d));za42cf7dd4a[(0x12c6+2875-0x1df5)]=(uint32_T)out;
za42cf7dd4a[(0xaca+5989-0x2224)]=(0xab4+278-0xbc9);
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T zf91d71c6d9=ssGetIWorkValue(S,z7e2eeaa57c);uint16_T i;volatile uint32_T*za42cf7dd4a;int32_T out;uint16_T z4e3026977c;real_T zd3add15c40,zbd0243c03e;uint16_T first;za42cf7dd4a=(void*)base;
if(xpceIsModelInit()){za42cf7dd4a[(0x1207+2939-0x1d7a)]=(0xd11+2964-0x1885);first=(0x161b+3601-0x242b);for(z4e3026977c=(0x933+177-0x9e4);z4e3026977c<(0x1e8+134-0x266);z4e3026977c++){if(first){first=(0x880+6293-0x2115);}else{za42cf7dd4a[(0x6af+3508-0x1457)]=(uint32_T)out;}zd3add15c40=ssGetRWorkValue(S,z4e3026977c*(0x5af+6941-0x20ca));zbd0243c03e=ssGetRWorkValue(S,z4e3026977c*(0xfaa+3552-0x1d88)+(0x3b9+5119-0x17b7));out=(int32_T)((10.0*zd3add15c40)-zbd0243c03e);
if(out>65535){out=65535;}if(out<(0x205+1761-0x8e6)){out=(0x1783+1366-0x1cd9);}
out=out|(z4e3026977c<<(0x14d7+2536-0x1eaf));}

out=out|((0x1c0+7742-0x1ffd)<<(0x98+540-0x2a1));za42cf7dd4a[(0x1b55+705-0x1e0a)]=(uint32_T)out;za42cf7dd4a[(0x7fb+6813-0x2290)]=(0x13c+6770-0x1bad);
za42cf7dd4a[(0xcb9+633-0xf27)]=(0x1fa+513-0x3fa);}
rl32eWaitDouble(0.0001);first=(0x9bc+1914-0x1135);for(i=(0x1256+3866-0x2170);i<zf91d71c6d9;i++){if(xpceIsModelInit()||(int)mxGetPr(zc8bbaa6115)[i]){if(first){first=(0x261+3975-0x11e8);}else{za42cf7dd4a[(0x470+7389-0x2141)]=(uint32_T)out;}z4e3026977c=(uint16_T)mxGetPr(za9d8fb6bcf)[i]-(0x1396+4176-0x23e5);zd3add15c40=ssGetRWorkValue(S,z4e3026977c*(0x137+9040-0x2485));zbd0243c03e=ssGetRWorkValue(S,z4e3026977c*(0x935+3602-0x1745)+(0x1aa1+597-0x1cf5));
out=(int32_T)((((real_T)mxGetPr(zae7f89439f)[i]+10.0)*zd3add15c40)-zbd0243c03e);
if(out>65535){out=65535;}if(out<(0x18c0+636-0x1b3c)){out=(0xa70+1868-0x11bc);}
out=out|(z4e3026977c<<(0xe04+5278-0x2292));}}

out=out|((0x2423+2-0x2424)<<(0xd64+4266-0x1dfb));za42cf7dd4a[(0x48+2009-0x815)]=(uint32_T)out;
za42cf7dd4a[(0x19b3+2755-0x246b)]=(0x1f2+3890-0x1123);
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

