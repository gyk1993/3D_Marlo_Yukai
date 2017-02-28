/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1331+787-0x1642)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO107_setup_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x30\x37"
#define z694756a014 (0x1764+2155-0xf1a)
#define zea87e0ba83 36950
#define z29146a1837 (0x168f+1637-0xc3f)
#define zab7e64468b 12576
#define zdf24515981          ((0xb31+6480-0x2478))
#define z8fd86139be               ssGetSFcnParam(S,(0x62d+5327-0x1afc))
#define z23de257f05         ssGetSFcnParam(S,(0x13ed+2723-0x1e8f))
#define z1e0b67709d       ssGetSFcnParam(S,(0x1bdf+2671-0x264c))
#define zd6d6a44c19                 ssGetSFcnParam(S,(0xb4c+2967-0x16e0))
#define z702a26a5e9                ssGetSFcnParam(S,(0x1353+4156-0x238b))
#define zcaea56018f             ssGetSFcnParam(S,(0x16a3+3986-0x2630))
#define z79b944ae89           ssGetSFcnParam(S,(0x1c6c+1102-0x20b4))
#define za6b3fb79a3             ssGetSFcnParam(S,(0x78+9465-0x256a))
#define z5317f28eb6           ssGetSFcnParam(S,(0x971+7190-0x257f))
#define z2e6483d505              ((0x1eaa+24-0x1ec0))
#define z6a0da049de         ((0x15aa+3007-0x2169))
#define zc2f3e0cbc0        ((0x218d+707-0x244f))
#define zc5ce4cb81a              ((0x6a1+7012-0x2203))
#define z8caad2a8e6              ((0x3a9+4743-0x1630))
#define z5bfe7a2613            ((0x17c+484-0x35f))
#define z2b17e2ee3b              ((0x121d+3031-0x1df4))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0x297+6600-0x1b5f)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x4b8+5631-0x1ab7));ssSetNumDiscStates(S,(0xc82+3638-0x1ab8));ssSetNumInputPorts(S,(0x1769+1318-0x1c8f));ssSetNumOutputPorts(S,(0x76a+4717-0x19d7));ssSetNumSampleTimes(S,(0x16+3331-0xd18));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x814+1192-0xcbc));ssSetNumNonsampledZCs(S,(0x8cd+6557-0x226a));for(i=(0x17cd+3698-0x263f);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x343+5696-0x1983));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x841+2927-0x13b0),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1c5d+1908-0x23d1),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T range,z8b9d33e44f,out,count,z23c49555fe,z880d37ab6f;uint16_T z4e3026977c;uint32_T zf91d71c6d9=(uint32_T)mxGetN(z79b944ae89);if((int_T)mxGetPr(z702a26a5e9)[(0x22cc+220-0x23a8)]<(0xbf6+6148-0x23fa)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x1122+861-0x147e)){z366b2f03bf=(0x1044+1263-0x1533);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x2060+1101-0x24ad)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0xc1c+4618-0x1e26)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x4d9+8430-0x25c6)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x1d37+1790-0x2336))|((z366b2f03bf&(0x21dd+341-0x2233))<<(0x1b08+249-0x1bf9)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x1db+8231-0x2200)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0xdaa+470-0xf60),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,zc2f3e0cbc0,(uint32_T)zf91d71c6d9);switch((uint16_T)mxGetPr(z8fd86139be)[(0xf44+4017-0x1ef5)]){case(0x12e0+5134-0x26ed):ssSetRWorkValue(S,z8caad2a8e6,3276.8);ssSetRWorkValue(S,z5bfe7a2613,10.0);range=(0xeea+5262-0x2375);break;case(0x1044+3219-0x1cd5):ssSetRWorkValue(S,z8caad2a8e6,6553.6);ssSetRWorkValue(S,z5bfe7a2613,5.0);range=(0xfcc+860-0x1326);break;case(0xb6a+2472-0x150f):ssSetRWorkValue(S,z8caad2a8e6,13107.2);ssSetRWorkValue(S,z5bfe7a2613,2.5);range=(0xead+1005-0x1299);break;case(0x12f7+4473-0x246c):ssSetRWorkValue(S,z8caad2a8e6,26214.4);ssSetRWorkValue(S,z5bfe7a2613,1.25);range=(0x1192+5218-0x25f4);break;}z23c49555fe=(uint16_T)mxGetPr(z23de257f05)[(0xde5+3731-0x1c78)];z880d37ab6f=(uint16_T)mxGetPr(z1e0b67709d)[(0x1a89+2167-0x2300)]-(0x1be8+684-0x1e93);za42cf7dd4a[(0x172+5031-0x1519)]=(0x19cd+2491-0x22f8)|(range<<(0xca5+3838-0x1b93))|(z880d37ab6f<<(0x1672+884-0x19e1))|(z23c49555fe<<(0x2f5+3651-0x1135));
out=(0x4bb+1562-0xad5);for(i=(0x164d+4256-0x26ed);i<zf91d71c6d9;i++){z4e3026977c=(uint16_T)mxGetPr(z79b944ae89)[i]-(0xa3b+3534-0x1808);out|=(0x194b+1267-0x1e3d)<<z4e3026977c;}za42cf7dd4a[(0x11cb+3580-0x1fc6)]=out;

za42cf7dd4a[(0x1b2d+789-0x1e3f)]=za42cf7dd4a[(0x343+7763-0x2193)]|(0x1b9a+2007-0x2351);za42cf7dd4a[(0xb9c+5467-0x20f4)]=za42cf7dd4a[(0xcf0+213-0xdc2)]|(0x1141+534-0xb57);start=rl32eGetTicksDouble();while(za42cf7dd4a[(0x225+8350-0x22c0)]&2048){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*1.0){
sprintf(zea4cd01646,"\x20\x20\x25\x73\x20\x66\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x63\x6c\x65\x61\x72\x20\x61\x6e\x61\x6c\x6f\x67\x20\x6f\x75\x74\x70\x75\x74\x20\x46\x49\x46\x4f",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}
if(xpceIsModelInit()&&((int)mxGetPr(zd6d6a44c19)[(0x7a+1430-0x610)]==(0x933+6880-0x2412))){za42cf7dd4a[(0x8d4+4160-0x1914)]=za42cf7dd4a[(0x2a5+1786-0x99f)]|8192;
start=rl32eGetTicksDouble();printf("\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x73\x74\x61\x72\x74\x65\x64\x2e\x2e" "\n",zf1b619edf2);while((za42cf7dd4a[(0x1cac+567-0x1ee3)]&8192)==(0x25da+1468-0xb96)){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*9.9){
sprintf(zea4cd01646,"\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x66\x61\x69\x6c\x65\x64\x2e",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}
printf("\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x73\x75\x63\x63\x65\x65\x64\x65\x64\x2e" "\n",zf1b619edf2);}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T zf91d71c6d9=mxGetN(z79b944ae89);real_T z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6);real_T offset=ssGetRWorkValue(S,z5bfe7a2613);uint16_T i;volatile uint32_T*za42cf7dd4a;int32_T out;uint16_T z4e3026977c,index;real_T zd3add15c40,zbd0243c03e;uint16_T first=(0x956+2057-0x115e);real_T scale=3276.8;uint32_T z718c4c15f4;za42cf7dd4a=(void*)base;
if(xpceIsModelInit()){

}
first=(0x238c+121-0x2404);
for(i=(0x17ff+1873-0x1f50);i<zf91d71c6d9;i++){if(xpceIsModelInit()||(int)mxGetPr(za6b3fb79a3)[i]){index=(uint16_T)mxGetPr(zcaea56018f)[i]-(0x14cb+1933-0x1c57);z4e3026977c=(uint16_T)mxGetPr(z79b944ae89)[i]-(0x2044+749-0x2330);
out=(int32_T)(((real_T)mxGetPr(z5317f28eb6)[index]+offset)*z0754dd67cc);if(out>65535)out=65535;if(out<(0x715+7976-0x263d))out=(0x1ae0+858-0x1e3a);
za42cf7dd4a[(0x114b+3779-0x2008)]=out;}}
#endif    
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

