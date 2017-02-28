/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1d1d+628-0x1f8f)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_qad_sf
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
#define zdf24515981          ((0x1c2c+1285-0x2128))
#define z702a26a5e9                ssGetSFcnParam(S,(0xa93+2174-0x1311))
#define z75204e189b             ssGetSFcnParam(S,(0xf4+6183-0x191a))
#define z3832b85a32           ssGetSFcnParam(S,(0x1e2+8084-0x2174))
#define z6a07768ac8      ssGetSFcnParam(S,(0x53a+5375-0x1a36))
#define z3b23451ce3    ssGetSFcnParam(S,(0xf6+3279-0xdc1))
#define z985e5b754b    ssGetSFcnParam(S,(0x1213+3900-0x214a))
#define ze7b042c9dd  ssGetSFcnParam(S,(0x48b+6479-0x1dd4))
#define z1120e7330e            ssGetSFcnParam(S,(0xc8a+3510-0x1a39))
#define z533b11d03f           ssGetSFcnParam(S,(0x5b1+3412-0x12fd))
#define z2e6483d505              ((0x3ff+1373-0x95a))
#define z7e2eeaa57c          ((0x137a+866-0x16dc))
#define z6a0da049de         ((0xa5c+423-0xc02))
#define zc5ce4cb81a              ((0x20b+2591-0xc1a))
#define z2b17e2ee3b              ((0x321+4329-0x140a))
static char_T zea4cd01646[(0x155+6885-0x1b3a)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x1803+1219-0x1cc6));ssSetNumDiscStates(S,(0x58c+3869-0x14a9));ssSetNumOutputPorts(S,(0x1797+1410-0x1d19));ssSetNumInputPorts(S,(0xda5+1538-0x13a5));


ssSetInputPortDataType(S,(0x1986+3060-0x257a),SS_UINT8);ssSetInputPortWidth(S,(0x147b+557-0x16a8),(uint32_T)mxGetPr(z75204e189b)[(0x14fc+2339-0x1e1f)]);ssSetInputPortDataType(S,(0x511+8522-0x265a),SS_INT32);ssSetInputPortWidth(S,(0x17d9+1792-0x1ed8),(uint32_T)mxGetPr(z75204e189b)[(0x5b8+5586-0x1b8a)]);ssSetInputPortDirectFeedThrough(S,(0x4b3+1023-0x8b2),(0x1718+1255-0x1bfe));ssSetInputPortRequiredContiguous(S,(0xea4+2374-0x17ea),(0xbad+5173-0x1fe1));ssSetInputPortDirectFeedThrough(S,(0xd92+1908-0x1505),(0x2c0+6844-0x1d7b));ssSetInputPortRequiredContiguous(S,(0x16c2+3169-0x2322),(0x134b+3426-0x20ac));ssSetNumSampleTimes(S,(0x154f+1027-0x1951));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1f5c+388-0x20e0));ssSetNumNonsampledZCs(S,(0x1657+2413-0x1fc4));for(i=(0x871+7480-0x25a9);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1ff+3240-0xea7));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0xe7c+793-0x1195)]==-1.0){ssSetSampleTime(S,(0x1207+233-0x12f0),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1473+565-0x16a8),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x20f8+1177-0x2591),mxGetPr(z3832b85a32)[(0x3b9+5831-0x1a80)]);ssSetOffsetTime(S,(0xcbc+1430-0x1252),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z7be9105675,z4e3026977c;real_T scale;uint8_T z16ba527520[(0x11bd+3060-0x1d9d)];uint16_T z6f813cde47,za4a2434e08;uint32_T out;uint32_T zd4796eea24;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x3e3+6224-0x1c33)];switch(z78caf1ba61){case(0x737+6385-0x1efb):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");z6f813cde47=5845;za4a2434e08=17232;break;case(0x308+3217-0xe6b):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");z6f813cde47=(0x1db0+4773-0x1980);za4a2434e08=17239;break;case(0x103f+1356-0x145c):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");z6f813cde47=(0x206a+3563-0x1780);za4a2434e08=16979;break;case(0x1860+3832-0x2628):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");z6f813cde47=5845;za4a2434e08=(0x1a25+3947-0x248c);break;case(0xbe9+766-0xdb0):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");z6f813cde47=5845;za4a2434e08=21069;break;case(0x18ff+205-0x1894):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");z6f813cde47=(0x211b+2386-0x1398);za4a2434e08=16971;break;case(0xe58+2229-0x15d4):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");z6f813cde47=5845;za4a2434e08=17235;break;case(0x20a1+5-0x1f6c):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");z6f813cde47=(0x1fe9+5424-0x1e44);za4a2434e08=8196;break;case(0xa59+2915-0x147b):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");z6f813cde47=(0x1f06+5284-0x1cd5);za4a2434e08=19520;break;}
if((int_T)mxGetPr(z702a26a5e9)[(0x48d+3794-0x135f)]<(0x1416+684-0x16c2)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x49\x6e\x63\x72\x45\x6e\x63\x6f\x64\x65\x72\x20\x53\x65\x74\x75\x70\x20\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x1c2+2318-0xacf)){z366b2f03bf=(0x821+5279-0x1cc0);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x310+184-0x3c8)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x61d+7779-0x2480)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1544+3963-0x24be)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x10d7+1431-0x156f))|((z366b2f03bf&(0x14c9+4609-0x25cb))<<(0x5ca+4465-0x1733)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0xc0c+1974-0x13c0)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
for(i=(0x365+154-0x3ff);i<(uint32_T)mxGetPr(z75204e189b)[(0xed4+3899-0x1e0f)];i++){z7be9105675=(0xab1+5313-0x1f72);if(mxGetPr(z6a07768ac8)[i]==(0xeeb+3501-0x1c97)){z7be9105675=(0x647+6158-0x1e55);}else if(mxGetPr(z6a07768ac8)[i]==(0x193f+587-0x1b88)){z7be9105675=(0x2656+49-0x2686);}else{z7be9105675=(0xee5+5953-0x2624);}
if(mxGetPr(z3b23451ce3)[i]==(0xbb4+718-0xe81)){
z7be9105675=z7be9105675|((0x4ac+6653-0x1ea9)<<(0x1127+4819-0x23f8));}else if(mxGetPr(z3b23451ce3)[i]==(0x338+6622-0x1d14)){
z7be9105675=z7be9105675|((0x9ff+7132-0x25da)<<(0x446+1305-0x95d));}else{
z7be9105675=z7be9105675|((0x1e89+584-0x20cf)<<(0x15fb+988-0x19d5));}
if(mxGetPr(z985e5b754b)[i]==(0x7b6+2753-0x1276)){
z7be9105675=z7be9105675|((0xec+9698-0x26ce)<<(0x11cd+2811-0x1cc4));}else if(mxGetPr(z985e5b754b)[i]==(0x1fb+6121-0x19e2)){
z7be9105675=z7be9105675|((0x16c4+2113-0x1f04)<<(0x318+2949-0xe99));}else if(mxGetPr(z985e5b754b)[i]==(0x1ae2+1981-0x229c)){
z7be9105675=z7be9105675|((0x4a4+6106-0x1c7c)<<(0x433+3343-0x113e));}else if(mxGetPr(z985e5b754b)[i]==(0x980+567-0xbb3)){
z7be9105675=z7be9105675|((0x19a+5827-0x185a)<<(0x107+9247-0x2522));}else if(mxGetPr(z985e5b754b)[i]==(0x10df+5122-0x24dc)){
z7be9105675=z7be9105675|((0x16eb+1447-0x1c8e)<<(0x1320+319-0x145b));}za42cf7dd4a[9728+i]=z7be9105675;}for(i=(0xf09+2227-0x17bc);i<(uint32_T)mxGetPr(z75204e189b)[(0x428+4319-0x1507)];i++){zd4796eea24=(uint32_T)mxGetPr(ze7b042c9dd)[i];za42cf7dd4a[9760+i]=zd4796eea24-(0x12cd+3539-0x209f);

}za42cf7dd4a[9893]=(uint32_T)mxGetPr(z1120e7330e)[(0x12bb+410-0x1455)];za42cf7dd4a[9891]=4294967295;
za42cf7dd4a[9892]=4294967295;za42cf7dd4a[9892]=(0xf9d+5561-0x2556);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;uint32_T*za4749e65b3;uint8_T*z0729343411;uint32_T i;za42cf7dd4a=(void*)base;
za4749e65b3=(int32_T*)ssGetInputPortSignal(S,(0x15d4+1074-0x1a05));for(i=(0x2df+8317-0x235c);i<(uint32_T)mxGetPr(z75204e189b)[(0x1520+1621-0x1b75)];i++){za42cf7dd4a[9792+i]=za4749e65b3[i];}
z0729343411=(uint8_T*)ssGetInputPortSignal(S,(0x1f03+1772-0x25ef));for(i=(0x1173+1687-0x180a);i<(uint32_T)mxGetPr(z75204e189b)[(0x21a9+1108-0x25fd)];i++){za42cf7dd4a[9856+i]=z0729343411[i];}
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

