/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xbb3+522-0xdbb)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_pulse_sf
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
#define z3d31aba69b
#define zdf24515981        ((0x2ba+303-0x3e3))
#define z533b11d03f         ssGetSFcnParam(S,(0x71c+7689-0x2525)) 
#define za9d8fb6bcf           ssGetSFcnParam(S,(0x15cf+2357-0x1f03)) 
#define z589eb0a0ef          ssGetSFcnParam(S,(0x82+4061-0x105d))
#define zd9d3d536a6      ssGetSFcnParam(S,(0xb8c+6863-0x2658))
#define z3832b85a32         ssGetSFcnParam(S,(0x165+6070-0x1917))
#define z702a26a5e9              ssGetSFcnParam(S,(0xda4+2790-0x1885))
#define z2e6483d505              ((0x54d+6195-0x1d7f))
#define zc5ce4cb81a              ((0xc18+4610-0x1e1a))
#define z2b17e2ee3b              ((0xa13+2831-0x1522))
#define z6a0da049de         ((0x719+3228-0x13b5))
#define zce5d5c40c6                 (655360)
static char_T zea4cd01646[(0x374+8519-0x23bb)];struct PULSE{uint32_T zf30711d604[(0x2564+397-0x26d1)];uint32_T z340a1c4167[(0x1772+811-0x1a7d)];uint32_T za406535818[(0xdc9+3662-0x1bf7)];uint32_T z9a43414ac6[(0x108d+3686-0x1ed3)];uint32_T za457d4e38c[(0xaed+965-0xe92)];uint32_T z21d16af3cc[(0x202f+611-0x2272)];uint32_T zb5d7fbbc83[(0x53d+130-0x59f)];uint32_T zf5bfc5a316[(0x1926+1632-0x1f66)];uint32_T zf74f411162[(0xd45+1031-0x112c)];uint32_T zf6d96dda8f[(0x177c+3584-0x255c)];uint32_T z671eb3391e[(0x1d20+2108-0x253c)];uint32_T z441e1f60d4[(0x1598+144-0x1608)];uint32_T z324e7594cd[(0x1cff+927-0x207e)];uint32_T z4da0d16710;uint32_T z2f1801d2e2;uint32_T z6050462268;};static void mdlInitializeSizes(SimStruct*S){uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x11b0+3488-0x1f50));ssSetNumDiscStates(S,(0xf80+4565-0x2155));ssSetNumInputPorts(S,(0x1d06+124-0x1d80)*((uint32_T)mxGetPr(z589eb0a0ef)[(0x1a7d+654-0x1d0b)])+(0xa32+259-0xb32));for(i=(0x79b+1745-0xe6c);i<(0x1e1+2878-0xd1d)*mxGetPr(z589eb0a0ef)[(0x1ac+5108-0x15a0)]+(0xe35+5550-0x23e0);i++){ssSetInputPortWidth(S,i,(uint32_T)mxGetN(za9d8fb6bcf));ssSetInputPortDirectFeedThrough(S,i,(0x1df6+148-0x1e89));ssSetInputPortRequiredContiguous(S,i,(0x7ca+542-0x9e7));}ssSetNumOutputPorts(S,(0x1ef+5736-0x1857));ssSetNumSampleTimes(S,(0x1253+4447-0x23b1));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x33c+1314-0x85e));ssSetNumNonsampledZCs(S,(0x189a+3310-0x2588));for(i=(0xd32+2359-0x1669);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1a0d+125-0x1a8a));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x70c+1352-0xc54)]==-1.0){ssSetSampleTime(S,(0xad7+4586-0x1cc1),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1f95+936-0x233d),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x3c3+5715-0x1a16),mxGetPr(z3832b85a32)[(0x273+41-0x29c)]);ssSetOffsetTime(S,(0xdf0+4700-0x204c),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i;uint8_T z16ba527520[(0x943+3318-0x1625)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61,z4e3026977c,z4da0d16710,z2f1801d2e2;volatile struct PULSE*pulse;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x1cd9+2545-0x26ca)];z6f813cde47=z05b56d9d51=5845;switch(z78caf1ba61){case(0x2277+1352-0x2692):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");za4a2434e08=z182d03571c=17232;break;case(0x1a9+8570-0x21f5):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");za4a2434e08=z182d03571c=17239;break;case(0x2016+1182-0x2385):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");za4a2434e08=z182d03571c=16979;break;case(0x2b7+3056-0xd77):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");za4a2434e08=z182d03571c=(0xedb+4144-0x1a07);break;case(0x25a+9122-0x24c5):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");za4a2434e08=z182d03571c=21069;break;case(0x2171+1305-0x2552):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");za4a2434e08=z182d03571c=16971;break;case(0x1437+790-0x1614):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");za4a2434e08=z182d03571c=17235;break;case(0x1f8+5347-0x15a1):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");za4a2434e08=z182d03571c=8196;break;case(0xeb7+3135-0x19b5):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;}if(mxGetN(z702a26a5e9)==(0x1af3+1769-0x21db)){z366b2f03bf=(0x4dd+1136-0x94d);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x20f5+656-0x2385)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x1234+3003-0x1def)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x5a2+6200-0x1dd9)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x6d8+236-0x7c2)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0xf61+2737-0x1a10)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0xa3c+4970-0x1da4)]);pulse=(struct PULSE*)(zeccbadd9b3.VirtAddress[(0x4b9+2811-0xfb2)]+zce5d5c40c6);if(!xpceIsModelInit()){z2f1801d2e2=(0xe79+4837-0x215e);z4da0d16710=(0xcdc+4310-0x1db2);for(i=(0x4bc+1854-0xbfa);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1015+4359-0x211b);z2f1801d2e2|=((0x17ad+2362-0x20e6)<<z4e3026977c);z4da0d16710|=((0x1306+4800-0x25c5)<<z4e3026977c);pulse->z340a1c4167[z4e3026977c]=(0x15fa+4125-0x2617);pulse->za406535818[z4e3026977c]=(0x19d1+181-0x1a86);pulse->z9a43414ac6[z4e3026977c]=(0x720+2908-0x127c);pulse->za457d4e38c[z4e3026977c]=(0x1c2a+424-0x1dd2);pulse->z21d16af3cc[z4e3026977c]=(0x23c6+557-0x25f3);pulse->zb5d7fbbc83[z4e3026977c]=(0x1941+2076-0x215d);pulse->zf5bfc5a316[z4e3026977c]=(0x195d+313-0x1a96);pulse->zf74f411162[z4e3026977c]=(0x497+2108-0xcd3);pulse->zf6d96dda8f[z4e3026977c]=(0x129+1069-0x556);pulse->z671eb3391e[z4e3026977c]=(0xb6+9583-0x2625);pulse->zf30711d604[z4e3026977c]=(0xab0+1888-0x1210);}pulse->z2f1801d2e2=z2f1801d2e2;pulse->z2f1801d2e2=(0x8cd+1298-0xddf);pulse->z4da0d16710=z4da0d16710;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint32_T i,z26dbd73a5e,z4e3026977c,zf30711d604,on,off,z2f1801d2e2;real_T*y1,*y2;volatile struct PULSE*pulse=(struct PULSE*)(base+zce5d5c40c6);z2f1801d2e2=(0x1384+2919-0x1eeb);for(i=(0x20dc+21-0x20f1);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x63f+8011-0x2589);
y1=(real_T*)ssGetInputPortSignal(S,(0x1b27+801-0x1e48));zf30711d604=(uint32_T)y1[i];pulse->zf30711d604[z4e3026977c]=zf30711d604;
y1=(real_T*)ssGetInputPortSignal(S,(0x27+7283-0x1c99));y2=(real_T*)ssGetInputPortSignal(S,(0x260+8191-0x225d));on=(uint32_T)y1[i];off=(uint32_T)y2[i];pulse->z441e1f60d4[z4e3026977c]=on;pulse->z324e7594cd[z4e3026977c]=off;
z2f1801d2e2|=((0x564+5236-0x19d7)<<z4e3026977c);for(z26dbd73a5e=(0xe26+866-0x1188);z26dbd73a5e<(uint32_T)mxGetPr(z589eb0a0ef)[(0x46d+2644-0xec1)];z26dbd73a5e++){y1=(real_T*)ssGetInputPortSignal(S,(0x2b9+1492-0x88b)*z26dbd73a5e+(0x28f+8606-0x242a));y2=(real_T*)ssGetInputPortSignal(S,(0x440+7166-0x203c)*z26dbd73a5e+(0x944+3012-0x1507)+(0x792+4215-0x1806));on=(uint32_T)y1[i];off=(uint32_T)y2[i];switch(z26dbd73a5e){case(0x18b5+1397-0x1e2a):
pulse->z340a1c4167[z4e3026977c]=on;pulse->zb5d7fbbc83[z4e3026977c]=off;break;case(0x648+7588-0x23eb):
pulse->za406535818[z4e3026977c]=on;pulse->zf5bfc5a316[z4e3026977c]=off;break;case(0x69c+1596-0xcd6):
pulse->z9a43414ac6[z4e3026977c]=on;pulse->zf74f411162[z4e3026977c]=off;break;case(0x1657+1414-0x1bda):
pulse->za457d4e38c[z4e3026977c]=on;pulse->zf6d96dda8f[z4e3026977c]=off;break;case(0x7b3+1822-0xecd):
pulse->z21d16af3cc[z4e3026977c]=on;pulse->z671eb3391e[z4e3026977c]=off;break;}}}pulse->z2f1801d2e2=z2f1801d2e2;
pulse->z2f1801d2e2=(0x1522+3433-0x228b);
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile struct PULSE*pulse=(struct PULSE*)(base+zce5d5c40c6);uint32_T i,z4e3026977c,zd54f8d8068,ze10307c65c,z6050462268;zd54f8d8068=(0x1567+3699-0x23da);ze10307c65c=(0x7e4+6976-0x2324);for(i=(0x1195+503-0x138c);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x22+8442-0x211b);zd54f8d8068|=((0xe86+6060-0x2631)<<z4e3026977c);if((uint32_T)mxGetPr(zd9d3d536a6)[i]){ze10307c65c|=((0xe7+8476-0x2202)<<z4e3026977c);}}z6050462268=pulse->z6050462268;z6050462268&=~(zd54f8d8068);z6050462268|=ze10307c65c;pulse->z6050462268|=z6050462268;pulse->z4da0d16710=(0x1b6+6365-0x1a93);if(xpceIsModelInit()){printf("\x50\x75\x6c\x73\x65\x20\x70\x61\x74\x74\x65\x72\x6e\x20\x73\x75\x63\x63\x65\x73\x66\x75\x6c\x6c\x79\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x65\x64\x2e" "\n");}
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

