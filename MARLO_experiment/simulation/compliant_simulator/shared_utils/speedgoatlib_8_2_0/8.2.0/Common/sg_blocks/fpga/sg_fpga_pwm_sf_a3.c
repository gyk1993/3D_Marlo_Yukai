/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x4c8+934-0x86c)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_pwm_sf_a3
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
#define zdf24515981        ((0x1175+3578-0x1f60))
#define z533b11d03f         ssGetSFcnParam(S, (0xba4+991-0xf83)) 
#define za9d8fb6bcf           ssGetSFcnParam(S, (0x76d+4586-0x1956)) 
#define z01bb085356         ssGetSFcnParam(S, (0x2d+3455-0xdaa))
#define zc74c85e681           ssGetSFcnParam(S, (0x3ea+5816-0x1a9f))
#define z311fbc5bad           ssGetSFcnParam(S, (0x1f49+767-0x2244))
#define za04af20061           ssGetSFcnParam(S, (0x5ab+5607-0x1b8d))
#define za9b36fc92d            ssGetSFcnParam(S, (0xd12+5059-0x20cf))
#define zfde61350f8     ssGetSFcnParam(S, (0x1e45+395-0x1fc9))
#define zeac6896859        ssGetSFcnParam(S, (0x1a72+1558-0x2080))
#define z2dceaadc0f         ssGetSFcnParam(S, (0xb51+3536-0x1918))
#define z4eb7791e75     ssGetSFcnParam(S, (0x1bc9+1716-0x2273))
#define z502d9ed0cf             ssGetSFcnParam(S, (0x89a+2448-0x121f))
#define z1918c3f4db             ssGetSFcnParam(S, (0x6c7+6297-0x1f54))
#define z3832b85a32         ssGetSFcnParam(S, (0x13db+4165-0x2413))
#define z702a26a5e9              ssGetSFcnParam(S, (0x10ec+2054-0x18e4))
#define z2e6483d505              ((0xa52+2864-0x1581))
#define zc5ce4cb81a              ((0x1567+3184-0x21d7))
#define z2b17e2ee3b              ((0x28b+7730-0x20bd))
#define z6a0da049de         ((0x8ab+4654-0x1ad9))
#define zcf76109ce0              (98304)
static char_T zea4cd01646[(0x9b8+4634-0x1ad2)];typedef struct{uint32_T z4da0d16710;uint32_T z2f1801d2e2;uint32_T z8db8bb5a06;uint32_T zee8378496a;uint32_T z37cfa98aaf;uint32_T ze7198b4532;uint32_T zba6c56af50;uint32_T zf30711d604[(0x6e7+3882-0x15f1)];uint32_T z6756646a81[(0x141+6556-0x1abd)];uint32_T z9ca0045836[(0x1430+1549-0x1a1d)];uint32_T z8e8b32e98e[(0x584+4967-0x18cb)];uint32_T z886a62b902[(0x1c1+9458-0x2693)];uint32_T protection[(0x4a7+8466-0x2599)];uint32_T z7211d763fb[(0xadc+1031-0xec3)];uint32_T z64b63d5c98[(0x146a+1087-0x1889)];uint32_T z3144e9a755[(0x989+4012-0x1915)];}z8dc61d99bb;static void mdlInitializeSizes(SimStruct*S){uint32_T i,zbc7ebd0e53,width;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x29b+9208-0x2693));ssSetNumDiscStates(S,(0x38b+6025-0x1b14));width=(uint32_T)mxGetN(za9d8fb6bcf);zbc7ebd0e53=(0x2589+194-0x264b);if((uint32_T)mxGetPr(z01bb085356)[(0x30d+5998-0x1a7b)]==(0x1817+2162-0x2088)){zbc7ebd0e53=(0x239+7877-0x20fc);}else{zbc7ebd0e53=(0x53+4871-0x1356);}ssSetNumInputPorts(S,zbc7ebd0e53);
for(i=(0xa1b+698-0xcd5);i<zbc7ebd0e53;i++){ssSetInputPortWidth(S,i,width);ssSetInputPortDirectFeedThrough(S,i,(0x30+8768-0x226f));ssSetInputPortRequiredContiguous(S,i,(0x1227+2195-0x1ab9));}ssSetNumOutputPorts(S,(0x122f+1224-0x16f7));ssSetNumSampleTimes(S,(0x1b64+2598-0x2589));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x66b+2757-0x1130));ssSetNumNonsampledZCs(S,(0x1dd7+2043-0x25d2));for(i=(0xf6a+762-0x1264);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x11c3+3199-0x1e42));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x114d+1302-0x1663)]==-1.0){ssSetSampleTime(S,(0xddb+2014-0x15b9),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x298+597-0x4ed),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x5f8+5633-0x1bf9),mxGetPr(z3832b85a32)[(0x8a5+5688-0x1edd)]);ssSetOffsetTime(S,(0x20f1+525-0x22fe),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i,z4e3026977c,z4da0d16710,z8db8bb5a06,zee8378496a,z37cfa98aaf;volatile z8dc61d99bb*z9e95a8730f;uint8_T z16ba527520[(0x122c+225-0x12f9)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x1eca+320-0x200a)];z6f813cde47=z05b56d9d51=5845;switch(z78caf1ba61){case(0x5bb+3327-0x116f):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;break;default:sprintf(zea4cd01646,"\x62\x6f\x61\x72\x64\x20\x74\x79\x70\x65\x20\x69\x6e\x63\x6f\x72\x72\x65\x63\x74\x2e");ssSetErrorStatus(S,zea4cd01646);return;}if(mxGetN(z702a26a5e9)==(0x8f+7627-0x1e59)){z366b2f03bf=(0x2b6+6375-0x1b9d);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x1d9+1511-0x7c0)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0xfb0+2384-0x1900)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x4c9+4473-0x1641)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0xc2+9157-0x2485)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x840+7690-0x2648)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x22d+7752-0x2073)]);z9e95a8730f=(z8dc61d99bb*)(zeccbadd9b3.VirtAddress[(0x10fb+5222-0x255f)]+zcf76109ce0);if(!xpceIsModelInit()){z4da0d16710=z9e95a8730f->z4da0d16710;z8db8bb5a06=z9e95a8730f->z8db8bb5a06;zee8378496a=z9e95a8730f->zee8378496a;z37cfa98aaf=z9e95a8730f->z37cfa98aaf;for(i=(0x1463+119-0x14da);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x75f+3782-0x1624);
z9e95a8730f->zf30711d604[z4e3026977c]=(uint32_T)mxGetPr(za9b36fc92d)[i];z9e95a8730f->z3144e9a755[z4e3026977c]=(uint32_T)mxGetPr(zfde61350f8)[i];z9e95a8730f->protection[z4e3026977c]=(uint32_T)mxGetPr(zeac6896859)[i]-(0x12fd+3930-0x2256);z9e95a8730f->z7211d763fb[z4e3026977c]=(uint32_T)mxGetPr(z2dceaadc0f)[i]-(0x386+40-0x3ad);z9e95a8730f->z64b63d5c98[z4e3026977c]=(uint32_T)mxGetPr(z4eb7791e75)[i]-(0x10f7+3866-0x2010);if((uint32_T)mxGetPr(zc74c85e681)[i]==(0x1edc+75-0x1f25)){z8db8bb5a06|=((0x15eb+3628-0x2416)<<z4e3026977c);}else{z8db8bb5a06&=~((0xa8+1706-0x751)<<z4e3026977c);}if((uint32_T)mxGetPr(z311fbc5bad)[i]==(0x20c0+1005-0x24ab)){zee8378496a|=((0x8da+7277-0x2546)<<z4e3026977c);}else{zee8378496a&=~((0x7bf+6590-0x217c)<<z4e3026977c);}if((uint32_T)mxGetPr(za04af20061)[i]==(0x254+1891-0x9b5)){z37cfa98aaf|=((0x7c5+4992-0x1b44)<<z4e3026977c);}else{z37cfa98aaf&=~((0x229+289-0x349)<<z4e3026977c);}
z4da0d16710|=((0x1aad+2071-0x22c3)<<z4e3026977c);}z9e95a8730f->z8db8bb5a06=z8db8bb5a06;z9e95a8730f->zee8378496a=zee8378496a;z9e95a8730f->z37cfa98aaf=z37cfa98aaf;z9e95a8730f->z2f1801d2e2=z4da0d16710;z9e95a8730f->z2f1801d2e2=(0x4ff+4498-0x1691);z9e95a8730f->z4da0d16710=z4da0d16710;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base,i,z4e3026977c;volatile z8dc61d99bb*z9e95a8730f;uint32_T z6756646a81,z9ca0045836,z8e8b32e98e,z886a62b902,z2f1801d2e2,zf30711d604;real_T*z611581ab5c,*zf9036781e1,*z8f4e633df2,*z02d773b6fc;base=ssGetIWorkValue(S,z6a0da049de);z9e95a8730f=(z8dc61d99bb*)(base+zcf76109ce0);z2f1801d2e2=(0x3f3+4148-0x1427);for(i=(0x1f+1040-0x42f);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x681+3505-0x1431);if((uint32_T)mxGetPr(z01bb085356)[(0x1fc3+1348-0x2507)]==(0x9ab+6413-0x22b7)){z611581ab5c=(real_T*)ssGetInputPortSignal(S,(0x250+586-0x49a));zf9036781e1=(real_T*)ssGetInputPortSignal(S,(0x2333+53-0x2367));z6756646a81=(uint32_T)z611581ab5c[i];z8e8b32e98e=(uint32_T)zf9036781e1[i];zf30711d604=(uint32_T)mxGetPr(za9b36fc92d)[i];if(z6756646a81<=(0x3b7+1158-0x83d)){z9ca0045836=zf30711d604;}else if(z6756646a81>=zf30711d604){z9ca0045836=(0x378+1828-0xa9c);}else if(z6756646a81==zf30711d604/(0x1750+993-0x1b2f)){z9ca0045836=zf30711d604/(0x6a1+3556-0x1483);}else{z9ca0045836=zf30711d604-z6756646a81;}if(z8e8b32e98e<=(0x1f4b+294-0x2071)){z886a62b902=zf30711d604;}else if(z8e8b32e98e>=zf30711d604){z886a62b902=(0x899+3932-0x17f5);}else if(z8e8b32e98e==zf30711d604/(0xc5d+145-0xcec)){z886a62b902=zf30711d604/(0x5fd+4214-0x1671);}else{z886a62b902=zf30711d604-z8e8b32e98e;}}else{z611581ab5c=(real_T*)ssGetInputPortSignal(S,(0xe53+4978-0x21c5));zf9036781e1=(real_T*)ssGetInputPortSignal(S,(0x1430+3826-0x2321));z8f4e633df2=(real_T*)ssGetInputPortSignal(S,(0xd8f+910-0x111b));z02d773b6fc=(real_T*)ssGetInputPortSignal(S,(0xabd+4286-0x1b78));z6756646a81=(uint32_T)z611581ab5c[i];z9ca0045836=(uint32_T)zf9036781e1[i];z8e8b32e98e=(uint32_T)z8f4e633df2[i];z886a62b902=(uint32_T)z02d773b6fc[i];}z9e95a8730f->z6756646a81[z4e3026977c]=z6756646a81;z9e95a8730f->z9ca0045836[z4e3026977c]=z9ca0045836;z9e95a8730f->z8e8b32e98e[z4e3026977c]=z8e8b32e98e;z9e95a8730f->z886a62b902[z4e3026977c]=z886a62b902;z2f1801d2e2|=((0x7f+2670-0xaec)<<z4e3026977c);}z9e95a8730f->z2f1801d2e2=z2f1801d2e2;z9e95a8730f->z2f1801d2e2=(0xed+6686-0x1b0b);
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE    
uint32_T ze7198b4532,zba6c56af50;uint32_T base,i,z4e3026977c;volatile z8dc61d99bb*z9e95a8730f;
ze7198b4532=z9e95a8730f->ze7198b4532;zba6c56af50=z9e95a8730f->zba6c56af50;base=ssGetIWorkValue(S,z6a0da049de);z9e95a8730f=(z8dc61d99bb*)(base+zcf76109ce0);for(i=(0xec5+2529-0x18a6);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x942+4640-0x1b61);if((uint32_T)mxGetPr(z502d9ed0cf)[i]==(0xff+2168-0x976)){ze7198b4532&=~((0x143+2478-0xaf0)<<z4e3026977c);}else{ze7198b4532|=((0x29d+2999-0xe53)<<z4e3026977c);}if((uint32_T)mxGetPr(z1918c3f4db)[i]==(0x924+7527-0x268a)){zba6c56af50&=~((0x666+1336-0xb9d)<<z4e3026977c);}else{zba6c56af50|=((0x605+8082-0x2596)<<z4e3026977c);}}z9e95a8730f->ze7198b4532=ze7198b4532;z9e95a8730f->zba6c56af50=zba6c56af50;z9e95a8730f->z4da0d16710=(0x227+1044-0x63b);
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif
