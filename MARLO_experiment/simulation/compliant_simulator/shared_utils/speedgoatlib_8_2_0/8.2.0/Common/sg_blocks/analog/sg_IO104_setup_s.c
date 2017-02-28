/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x22+2844-0xb3c)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO104_setup_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x30\x34"
#define z694756a014 4277
#define zea87e0ba83 36950
#define z29146a1837 (0x19dd+5905-0x2039)
#define zab7e64468b 12658
#define zdf24515981          ((0xb2f+3453-0x189d))
#define zd6d6a44c19                 ssGetSFcnParam(S,(0x18bc+286-0x19da))
#define z1c6ce8e1bc           ssGetSFcnParam(S,(0x851+2011-0x102b))
#define z702a26a5e9                ssGetSFcnParam(S,(0x8db+1072-0xd09))
#define z2afc595703           ssGetSFcnParam(S,(0x1389+1706-0x1a30))
#define z4785157cf4            ssGetSFcnParam(S,(0x9f5+1507-0xfd4))
#define z57621982a4            ssGetSFcnParam(S,(0x6bf+7604-0x246e))
#define z186580de21          ssGetSFcnParam(S,(0x617+6568-0x1fb9))
#define z79b944ae89           ssGetSFcnParam(S,(0xb45+2959-0x16cd))
#define z061b63a1f4             ssGetSFcnParam(S,(0x1605+148-0x1691))
#define za6b3fb79a3             ssGetSFcnParam(S,(0x76b+1784-0xe5a))
#define z5317f28eb6           ssGetSFcnParam(S,(0x13eb+4645-0x2606))
#define zb18e38a301           ssGetSFcnParam(S,(0x201b+70-0x2056))
#define z5bc3ce0d50           ssGetSFcnParam(S,(0xc4f+6396-0x253f))
#define z1f9bebb47b             ssGetSFcnParam(S,(0x1674+3357-0x2384))
#define z2d8f240c11           ssGetSFcnParam(S,(0xee2+4639-0x20f3))
#define z2e6483d505              ((0xfb5+2477-0x1960))
#define z6a0da049de         ((0x113+2920-0xc7b))
#define zc2f3e0cbc0        ((0xee1+1169-0x1371))
#define zc5ce4cb81a              ((0xb57+6733-0x25a2))
#define z8caad2a8e6              ((0x1e9f+674-0x2141))
#define z5bfe7a2613            ((0x1378+2397-0x1cd4))
#define z2b17e2ee3b              ((0x865+7636-0x2639))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0x148d+2294-0x1c83)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x63a+4782-0x18e8));ssSetNumDiscStates(S,(0x953+3894-0x1889));ssSetNumInputPorts(S,(0x12c9+814-0x15f7));ssSetNumOutputPorts(S,(0x79+7784-0x1ee1));ssSetNumSampleTimes(S,(0x62d+449-0x7ed));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x55f+2420-0xed3));ssSetNumNonsampledZCs(S,(0x208b+36-0x20af));for(i=(0x230+6473-0x1b79);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x3ba+6457-0x1cf3));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x5fb+6225-0x1e4c),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x23c3+645-0x2648),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T z5d37e44dda,zb4b263f92d,zeedc7fe20f,z8b9d33e44f,out,z4e3026977c,zf11c0432d9;uint32_T zf91d71c6d9=(uint32_T)mxGetN(z2afc595703);if((int_T)mxGetPr(z702a26a5e9)[(0xc01+44-0xc2d)]<(0x5e7+698-0x8a1)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xf90+294-0x10b5)){z366b2f03bf=(0x1b2c+350-0x1c8a);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1923+390-0x1aa9)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x2116+199-0x21dd)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xbff+4384-0x1d1e)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x10bd+942-0x136c))|((z366b2f03bf&(0x12b9+4527-0x2369))<<(0x15d+4693-0x13aa)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x106+3911-0x104b)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0xf35+5651-0x24c8),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,zc2f3e0cbc0,(uint32_T)zf91d71c6d9);if(xpceIsModelInit()&&((int)mxGetPr(zd6d6a44c19)[(0x11a3+1860-0x18e7)]==(0x111f+5061-0x24e3))){za42cf7dd4a[(0x9c4+4656-0x1bf4)]=268435456;start=rl32eGetTicksDouble();printf("\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x73\x74\x61\x72\x74\x65\x64\x2e\x2e" "\n",zf1b619edf2);while((za42cf7dd4a[(0x7a3+2267-0x107e)]&268435456)==268435456){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*7.0){
sprintf(zea4cd01646,"\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x74\x69\x6d\x65\x64\x20\x6f\x75\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}if((za42cf7dd4a[(0x14f9+2182-0x1d7f)]&536870912)==536870912)
printf("\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x73\x75\x63\x63\x65\x65\x64\x65\x64\x2e" "\n",zf1b619edf2);else{sprintf(zea4cd01646,"\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x66\x61\x69\x6c\x65\x64",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}switch((uint16_T)mxGetPr(z4785157cf4)[(0xb45+41-0xb6e)]){case(0xe1+315-0x21b):z5d37e44dda=(0x57b+3148-0x11c5);break;case(0x26a+7349-0x1f1d):z5d37e44dda=(0x15f9+3889-0x2529);break;case(0xeea+6050-0x2689):z5d37e44dda=(0x10b5+792-0x13cd);break;}switch((uint16_T)mxGetPr(z57621982a4)[(0x1d7+5883-0x18d2)]){case(0x490+6995-0x1fe2):zb4b263f92d=(0x581+6986-0x20c9);break;case(0x798+2102-0xfcc):zb4b263f92d=(0x122c+4811-0x24f6);break;case(0x7c0+1630-0xe1b):zb4b263f92d=(0xc76+67-0xcb9);break;}switch((uint16_T)mxGetPr(z061b63a1f4)[(0x1e37+1278-0x2335)]){case(0x1b5d+656-0x1dec):ssSetRWorkValue(S,z8caad2a8e6,3276.8);ssSetRWorkValue(S,z5bfe7a2613,10.0);zeedc7fe20f=(0x400+6768-0x1e6e);break;case(0xd40+1109-0x1193):ssSetRWorkValue(S,z8caad2a8e6,6553.6);ssSetRWorkValue(S,z5bfe7a2613,5.0);zeedc7fe20f=(0x15d2+4082-0x25c3);break;case(0xcba+5393-0x21c8):ssSetRWorkValue(S,z8caad2a8e6,13107.2);ssSetRWorkValue(S,z5bfe7a2613,2.5);zeedc7fe20f=(0x1003+543-0x1222);break;}if((uint16_T)mxGetPr(z186580de21)[(0x1a0+2514-0xb72)]==(0x2419+210-0x24ea)){z8b9d33e44f=(0x10c9+5315-0x258c);}else{z8b9d33e44f=(0xf8+4907-0x1422);}if((uint16_T)mxGetPr(z1c6ce8e1bc)[(0x14d9+3756-0x2385)]==(0xb23+4817-0x1df3)){zf11c0432d9=(0x37d+5559-0x1933);}else{zf11c0432d9=(0x1953+2203-0x21ee);}
za42cf7dd4a[(0x3cc+3640-0x1204)]=33558528|(zf11c0432d9<<(0x985+4463-0x1adc))|(zeedc7fe20f<<(0x170f+3261-0x23bc))|(zb4b263f92d<<(0x3e5+7051-0x1f6a))|(z5d37e44dda<<(0x6ff+1170-0xb8d))|z8b9d33e44f;

out=(0x5f7+4398-0x1725);for(i=(0xdc5+4096-0x1dc5);i<zf91d71c6d9;i++){z4e3026977c=(uint32_T)mxGetPr(z2afc595703)[i]-(0x53d+6509-0x1ea9);out|=(0x1753+2791-0x2239)<<((0x5c1+687-0x858)+z4e3026977c);}za42cf7dd4a[(0x207+7893-0x20d3)]=out;
za42cf7dd4a[(0xc7d+5591-0x2254)]=za42cf7dd4a[(0x18cb+1760-0x1fab)]|8192;start=rl32eGetTicksDouble();while(za42cf7dd4a[(0x1067+5529-0x2600)]&8192){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*1.0){
sprintf(zea4cd01646,"\x20\x20\x25\x73\x20\x66\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x63\x6c\x65\x61\x72\x20\x61\x6e\x61\x6c\x6f\x67\x20\x69\x6e\x70\x75\x74\x20\x46\x49\x46\x4f",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}za42cf7dd4a[(0x1451+2726-0x1eec)]=(0x594+2753-0x1055);za42cf7dd4a[(0x1537+3019-0x2101)]=16777216;
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T zf91d71c6d9=mxGetN(z79b944ae89);real_T z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6);real_T offset=ssGetRWorkValue(S,z5bfe7a2613);uint16_T i;volatile uint32_T*za42cf7dd4a;int32_T out;uint16_T z4e3026977c;uint32_T z718c4c15f4;za42cf7dd4a=(void*)base;for(i=(0x142f+239-0x151e);i<zf91d71c6d9;i++){if(xpceIsModelInit()||(int)mxGetPr(za6b3fb79a3)[i]){z4e3026977c=(uint16_T)mxGetPr(z79b944ae89)[i]-(0x99f+2851-0x14c1);out=(int32_T)(((real_T)mxGetPr(z5317f28eb6)[i]+offset)*z0754dd67cc);
if(out>65535)out=65535;if(out<(0x203c+1362-0x258e))out=(0xe72+3549-0x1c4f);za42cf7dd4a[(0x981+6016-0x20ff)+z4e3026977c]=out;}}za42cf7dd4a[(0x106+1844-0x83a)]=za42cf7dd4a[(0x282+2588-0xc9e)]|1048576;
z718c4c15f4=(0x1607+1637-0x1c6c);for(i=(0x13e5+367-0x1554);i<(uint16_T)mxGetPr(z5bc3ce0d50)[i];i++){if(xpceIsModelInit()||(int)mxGetPr(z1f9bebb47b)[i]){z4e3026977c=(uint32_T)mxGetPr(z5bc3ce0d50)[i]-(0xf89+4249-0x2021);out=(real_T)mxGetPr(z2d8f240c11)[i];if(out>=THRESHOLD){z718c4c15f4|=(0x249+1962-0x9f2)<<z4e3026977c;}}}za42cf7dd4a[(0x19d2+2361-0x230a)]=(z718c4c15f4<<(0xbcf+2220-0x146b));
#endif    
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

