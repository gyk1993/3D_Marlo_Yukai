/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x12e9+954-0x16a1)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO111_setup_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x31\x31"
#define z694756a014 (0x259f+4698-0x2361)
#define zea87e0ba83 (0xfd9+5646-0x23be)
#define z29146a1837 (0x1c21+1329-0xcba)
#define zab7e64468b (0xa48+5944-0x2175)
#define zdf24515981          ((0x2069+887-0x23da))
#define z702a26a5e9                ssGetSFcnParam(S,(0x1279+3966-0x21f7))
#define z1f7e7173d9          ssGetSFcnParam(S,(0x1c18+953-0x1fd0))
#define z84dd9a9a5c            ssGetSFcnParam(S,(0x7bb+6566-0x215f))
#define z4d2d92ea80         ssGetSFcnParam(S,(0x424+4258-0x14c3))
#define z9c3881c2c2           ssGetSFcnParam(S,(0x609+5494-0x1b7b))
#define zc6f930323f            ssGetSFcnParam(S,(0x3d0+3519-0x118a))
#define z2e6483d505              ((0xd83+4656-0x1f4f))
#define z71d06eae75        ((0x13ea+4864-0x26ea))
#define ze575982d5f        ((0x1ac5+3085-0x26d1))
#define z9c9edc1d33        ((0x2301+6-0x2305))
#define zc5ce4cb81a              ((0x18f+5628-0x174b))
#define z2b17e2ee3b              ((0xc58+1274-0x1152))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0x792+1062-0xab8)];static uint16_T z0363d30aab(uint16_T x){if(x%(0x1b9+7673-0x1fb0)==(0x36f+3293-0x104c))return x+(0xbdc+1802-0x12e5);else return x-(0xfc8+3334-0x1ccd);}static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x232+9184-0x2612));ssSetNumDiscStates(S,(0x2c8+5277-0x1765));ssSetNumInputPorts(S,(0x795+4734-0x1a13));ssSetNumOutputPorts(S,(0x3ff+67-0x442));ssSetNumSampleTimes(S,(0xb7f+5164-0x1faa));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xc67+2891-0x17b2));ssSetNumNonsampledZCs(S,(0x2002+1473-0x25c3));for(i=(0x16ef+1935-0x1e7e);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x270+7486-0x1fae));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x9f7+1597-0x1034),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x131a+3159-0x1f71),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zef529fae4a;void*ze2370ae9b9;volatile uint32_T*z3e5b8e05d8;void*zdfcb1da404,*z4b22edbbef,*z3a3f02d297;void*zf2db5722bf,*z25b7c8cb15,*z347e24803c;volatile uint32_T*z27fd94ac66;volatile uint16_T*z7638e8fb2b;volatile int16_T*z730e4b2b7b;uint_T i,z812c65ff2f;uint32_T out;if((int_T)mxGetPr(z702a26a5e9)[(0x1c5+1006-0x5b3)]<(0x1b80+101-0x1be5)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x79b+733-0xa77)){z366b2f03bf=(0x1540+405-0x16d5);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x2262+185-0x231b)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x12b+2180-0x9af)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1635+1130-0x1a9e)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x14e1+4583-0x25c9))|((z366b2f03bf&(0x24c8+300-0x24f5))<<(0x2c9+8117-0x2276)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zef529fae4a=(void*)zeccbadd9b3.BaseAddress[(0x57c+4631-0x1793)];ze2370ae9b9=rl32eGetDevicePtr(zef529fae4a,(0x9fc+1294-0xd0a),RT_PG_USERREADWRITE);z3e5b8e05d8=(volatile uint32_T*)ze2370ae9b9;zdfcb1da404=(void*)zeccbadd9b3.BaseAddress[(0x5f0+2458-0xf88)];zf2db5722bf=rl32eGetDevicePtr(zdfcb1da404,(0x420+5465-0x1779),RT_PG_USERREADWRITE);z27fd94ac66=(volatile uint32_T*)zf2db5722bf;z4b22edbbef=(void*)zeccbadd9b3.BaseAddress[(0xd76+1557-0x1388)];z25b7c8cb15=rl32eGetDevicePtr(z4b22edbbef,(0x14e5+2123-0x1cf0),RT_PG_USERREADWRITE);z7638e8fb2b=(volatile uint16_T*)z25b7c8cb15;z3a3f02d297=(void*)zeccbadd9b3.BaseAddress[(0xdea+4612-0x1fea)];z347e24803c=rl32eGetDevicePtr(z3a3f02d297,(0xa60+6660-0x2064),RT_PG_USERREADWRITE);z730e4b2b7b=(volatile int16_T*)z347e24803c;


ssSetIWorkValue(S,z71d06eae75,(uint32_T)z27fd94ac66);ssSetIWorkValue(S,ze575982d5f,(uint32_T)z7638e8fb2b);ssSetIWorkValue(S,z9c9edc1d33,(uint32_T)z730e4b2b7b);if(xpceIsModelInit()){
z3e5b8e05d8[(0x1841+2554-0x2231)]=z3e5b8e05d8[(0x6d8+1792-0xdce)]&4278190079;z3e5b8e05d8[(0xd1+6011-0x1841)]=z3e5b8e05d8[(0x1e71+2152-0x26ce)]&4278190079;z3e5b8e05d8[(0x18f4+3422-0x2646)]=z3e5b8e05d8[(0x690+6614-0x205a)]&4278190079;}for(i=(0x2c+9472-0x252c);i<(0x36d+6207-0x1b9c);i++){switch((uint16_T)mxGetPr(zc6f930323f)[i]){case(0x5fc+2617-0x1035):ssSetRWorkValue(S,i,13107.2);break;case(0x514+6591-0x1ed2):ssSetRWorkValue(S,i,6553.6);break;case(0x67+426-0x20f):ssSetRWorkValue(S,i,6068.148);break;case(0x1f95+1688-0x262a):ssSetRWorkValue(S,i,6553.6);break;case(0xa79+6015-0x21f4):ssSetRWorkValue(S,i,3276.8);break;case(0x395+6835-0x1e43):ssSetRWorkValue(S,i,3034.074);break;}}
for(i=(0x51f+6039-0x1cb6);i<(0x1dd1+1199-0x2270);i++){uint16_T range;range=(uint16_T)mxGetPr(zc6f930323f)[i];ssSetIWorkValue(S,(0x1694+1816-0x1da2)+i,z730e4b2b7b[z0363d30aab((0x1379+3084-0x1f45)*range+i)]);ssSetIWorkValue(S,(0xe4+7972-0x1ffe)+i+(0x1d8f+1158-0x2205),z730e4b2b7b[z0363d30aab(((0xd84+5547-0x22ef)*range)+(0x65c+406-0x7e2)+i)]);}if(xpceIsModelInit()){
z3e5b8e05d8[(0x1c5b+2436-0x25d5)]=z3e5b8e05d8[(0x5e7+693-0x892)]&4278190079;z3e5b8e05d8[(0x9e1+296-0xafe)]=z3e5b8e05d8[(0x1db+4322-0x12b2)]&4278190079;z3e5b8e05d8[(0xb77+1350-0x10b1)]=z3e5b8e05d8[(0x1656+1591-0x1c81)]&4278190079;
for(i=(0x1cd9+1689-0x2372);i<(0x394+2467-0xd2f);i++){
z27fd94ac66[(0xc11+6439-0x2530)+i]=(0x17b0+2035-0x1fa3);}
for(i=(0x935+1882-0x108f);i<(0x9f7+799-0xd0e);i++){z812c65ff2f=(0x312+6207-0x1b51);while(z27fd94ac66[(0x143b+1473-0x19d9)]&((0x2b1+8523-0x23fb)<<(i*(0x14d1+2491-0x1e88))))z812c65ff2f++;
z27fd94ac66[(0x107+5488-0x1677)+i]=(uint32_T)mxGetPr(z9c3881c2c2)[i];}



}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T z31a846515d=ssGetIWorkValue(S,z71d06eae75);uint32_T z8ace1f9f47=ssGetIWorkValue(S,ze575982d5f);uint16_T i,z4e3026977c;volatile uint32_T*z27fd94ac66;volatile int16_T*z7638e8fb2b;real_T out;z27fd94ac66=(void*)z31a846515d;z7638e8fb2b=(void*)z8ace1f9f47;for(i=(0xae2+2522-0x14bc);i<mxGetN(z1f7e7173d9);i++){if(xpceIsModelInit()||(int)mxGetPr(z84dd9a9a5c)[i]){z4e3026977c=(uint16_T)mxGetPr(z1f7e7173d9)[i]-(0x10ac+1738-0x1775);out=mxGetPr(z4d2d92ea80)[i]*ssGetRWorkValue(S,z4e3026977c);
out=out*(1.0-(real_T)ssGetIWorkValue(S,(0xd98+888-0x1106)+z4e3026977c)/131072.0)-(real_T)ssGetIWorkValue(S,(0xb4b+2784-0x1621)+z4e3026977c+(0x602+6980-0x2136))/4.0;




z7638e8fb2b[z0363d30aab(z4e3026977c)]=(int16_T)out;}}
#endif    
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

