/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xa48+4878-0x1d54)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO113_setup_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x31\x33"
#define z694756a014 (0x1124+342-0x1c5)
#define zea87e0ba83 36950
#define z29146a1837 (0x1b76+6123-0x22ac)
#define zab7e64468b 13143
#define zdf24515981          ((0x739+3394-0x146d))
#define z702a26a5e9                ssGetSFcnParam(S,(0x24af+366-0x261d))
#define z1e0b67709d       ssGetSFcnParam(S,(0x7cf+3439-0x153d))
#define zd6d6a44c19                 ssGetSFcnParam(S,(0x11e8+1364-0x173a))
#define z79b944ae89           ssGetSFcnParam(S,(0x6e7+6035-0x1e77))
#define z8fd86139be               ssGetSFcnParam(S,(0x11e2+3990-0x2174))
#define zab5e3ff87e          ssGetSFcnParam(S,(0x6f0+5487-0x1c5a))
#define za6b3fb79a3             ssGetSFcnParam(S,(0x1bf9+1398-0x2169))
#define z5317f28eb6           ssGetSFcnParam(S,(0x654+7652-0x2431))
#define zcaea56018f             ssGetSFcnParam(S,(0xaf9+6216-0x2339))
#define z5bc3ce0d50           ssGetSFcnParam(S,(0x137b+1004-0x175e))
#define z1f9bebb47b             ssGetSFcnParam(S,(0xc41+745-0xf20))
#define z2d8f240c11           ssGetSFcnParam(S,(0x1610+3621-0x242a))
#define zcd0c7b4197            ssGetSFcnParam(S,(0x1a53+940-0x1df3))
#define zf1ce6579c8            ssGetSFcnParam(S,(0x379+2280-0xc54))
#define z04dd55c185         ( (0x141a+3068-0x2016) / (0x4a3+5393-0x19b0)) 
#define z676b87833d         ( (0x9a1+428-0xb49) / (0x147b+1099-0x18c2)) 
#define zb2d3195db0         ((0xdd0+4466-0x1f2e) / (0x122f+978-0x15fd)) 
#define zc85deb5f55         ((0x6fd+2717-0x1182) / (0xa72+286-0xb8c)) 
#define z4e55f0dcd8         ((0xd1c+4751-0x1f8f) / (0xacb+2357-0x13fc)) 
#define z729363651e         ((0x9e9+45-0x9e6) / (0xf84+2643-0x19d3)) 
#define z97f175fc3f         ((0x167+8801-0x2394) / (0x8d8+3456-0x1654)) 
#define z8950d414f2         ((0xb32+7165-0x26f7) / (0x1bb5+203-0x1c7c)) 
#define zf63f399f4e        ((0x983+3986-0x18d9) / (0x19ab+1819-0x20c2)) 
#define z9e21286eba        ((0xcf9+1598-0x12f7) / (0xc9f+736-0xf7b)) 
#define zd8d94f0c39        ((0x701+4060-0x1699) / (0xff2+4391-0x2115)) 
#define za01cd60f50        ((0x71+8763-0x2264) / (0xe18+343-0xf6b)) 
#define z2e5810a8c5        ((0x1894+1920-0x1fc8) / (0x11e9+4612-0x23e9)) 
#define zd9b8eebc9b        ((0x121d+2273-0x1aae) / (0x1a6a+2546-0x2458)) 
#define ze330088749        ((0xe32+4304-0x1eae) / (0x775+4553-0x193a)) 
#define z2e6483d505              ((0x784+3654-0x15c9))
#define z6a0da049de         ((0xb87+659-0xe1a))
#define zc5ce4cb81a              ((0x1b4f+895-0x1ecc))
#define z8caad2a8e6              ((0xdff+505-0xff8))
#define z5bfe7a2613            ((0x81b+4455-0x1981))
#define z2b17e2ee3b              ((0x1c02+438-0x1db8))
#define THRESHOLD               (0.5)
#define z7935114df5          (262143) 
static char_T zea4cd01646[(0x596+4752-0x1726)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xeb+7098-0x1ca5));ssSetNumDiscStates(S,(0x155c+1103-0x19ab));ssSetNumInputPorts(S,(0x595+3173-0x11fa));ssSetNumOutputPorts(S,(0x20c1+1243-0x259c));ssSetNumSampleTimes(S,(0x4f+1195-0x4f9));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x221+7336-0x1ec9));ssSetNumNonsampledZCs(S,(0x826+1063-0xc4d));for(i=(0x1153+2240-0x1a13);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1a7b+170-0x1b25));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0xc01+4059-0x1bdc),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x13d1+1653-0x1a46),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;real_T z19c4ca5f82,start;uint32_T range,out,z880d37ab6f,ze77fa94a00,zcd308d01c9;uint16_T z4e3026977c;uint16_T zb5ae6e3431,z9330649150;if((int_T)mxGetPr(z702a26a5e9)[(0x982+4996-0x1d06)]<(0xba8+5751-0x221f)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x13a7+4579-0x2589)){z366b2f03bf=(0xf48+3727-0x1dd7);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x14a9+349-0x1606)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x162c+1792-0x1d2c)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x192a+959-0x1ce8)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x870+5166-0x1b9f))|((z366b2f03bf&(0x1079+5963-0x26c5))<<(0x60f+4172-0x1653)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x15fd+3384-0x2333)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x261+6911-0x1d40),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);switch((uint16_T)mxGetPr(z8fd86139be)[(0x868+734-0xb46)]){case(0xaa7+4660-0x1cda):ssSetRWorkValue(S,z8caad2a8e6,13107.2);
ssSetRWorkValue(S,z5bfe7a2613,10.0);range=(0x804+2713-0x129b);break;case(0x16a8+669-0x1943):ssSetRWorkValue(S,z8caad2a8e6,26214.4);
ssSetRWorkValue(S,z5bfe7a2613,5.0);range=(0x319+8851-0x25ab);break;case(0x878+6059-0x2020):ssSetRWorkValue(S,z8caad2a8e6,52428.8);
ssSetRWorkValue(S,z5bfe7a2613,2.5);range=(0x3f5+7283-0x2068);break;}
if(xpceIsModelInit()){



z880d37ab6f=(uint16_T)mxGetPr(z1e0b67709d)[(0x9a1+1952-0x1141)]-(0xa51+5720-0x20a8);za42cf7dd4a[z04dd55c185]=((0x1a17+459-0x1be1)<<(0x1132+1095-0x1565))|((0x13ab+1406-0x1928)<<(0x4a6+6475-0x1dd8))|((0x29b+8169-0x2283)<<(0x83b+510-0xa27))|(z880d37ab6f<<(0x1310+291-0x142e));







zcd308d01c9=(0x861+7263-0x24c0);for(i=(0x10bb+3683-0x1f1e);i<(uint32_T)mxGetN(z79b944ae89);i++){z4e3026977c=(uint16_T)mxGetPr(z79b944ae89)[i]-(0x55b+3500-0x1306);zcd308d01c9|=(0x41f+5437-0x195b)<<z4e3026977c;}ze77fa94a00=(uint16_T)mxGetPr(zab5e3ff87e)[(0xf59+2770-0x1a2b)]-(0x1a47+1523-0x2039);

za42cf7dd4a[ze330088749]=((0x576+2179-0xdf8)<<(0x8a3+1685-0xf2d))|zcd308d01c9|(range<<(0x375+4884-0x1681))|(ze77fa94a00<<(0x1030+402-0x11b2));

za42cf7dd4a[zf63f399f4e]|=((0x171+7831-0x2007)<<(0x1644+1075-0x1a72));start=rl32eGetTicksDouble();za42cf7dd4a[zf63f399f4e]|=((0x28d+8317-0x2309)<<(0x46f+6929-0x1f75));while((za42cf7dd4a[zf63f399f4e]>>(0x9f4+4805-0x1cae))&(0x39c+1966-0xb49)){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*1.0){
sprintf(zea4cd01646,"\x25\x73\x20\x66\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x63\x6c\x65\x61\x72\x20\x61\x6e\x61\x6c\x6f\x67\x20\x6f\x75\x74\x70\x75\x74\x20\x46\x49\x46\x4f",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}
if((int)mxGetPr(zd6d6a44c19)[(0x3b1+2843-0xecc)]==(0xa53+1529-0x104b)){za42cf7dd4a[z04dd55c185]|=((0x421+3449-0x1199)<<(0xa25+2107-0x1244));
start=rl32eGetTicksDouble();printf("\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x73\x74\x61\x72\x74\x65\x64\x2e\x2e" "\n",zf1b619edf2);while((za42cf7dd4a[z04dd55c185]>>(0xe92+6144-0x2676))&(0x11c1+2965-0x1d55))
{z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*9.9){
sprintf(zea4cd01646,"\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x66\x61\x69\x6c\x65\x64\x2e",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}printf("\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x73\x75\x63\x63\x65\x65\x64\x65\x64\x2e" "\n",zf1b619edf2);}


zb5ae6e3431=(uint16_T)mxGetPr(zcd0c7b4197)[(0x21d5+650-0x245f)]-(0x361+4021-0x1315);z9330649150=(uint16_T)mxGetPr(zf1ce6579c8)[(0x701+4792-0x19b9)]-(0x602+1817-0xd1a);za42cf7dd4a[z676b87833d]=(0x2e4+8495-0x2413)|(zb5ae6e3431<<(0xd5a+4942-0x20a1))|(z9330649150<<(0x1109+2981-0x1c9f));printf("\x25\x73\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x61\x74\x69\x6f\x6e\x20\x73\x75\x63\x63\x65\x65\x64\x65\x64\x2e" "\n",zf1b619edf2);}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T z879ede9171=mxGetN(z79b944ae89);real_T z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6);real_T offset=ssGetRWorkValue(S,z5bfe7a2613);uint16_T i;volatile uint32_T*za42cf7dd4a;uint32_T z7711a772ed,out;uint16_T z4e3026977c,index;uint16_T z344fcf0ef3=mxGetN(z5bc3ce0d50);uint32_T z718c4c15f4;za42cf7dd4a=(void*)base;za42cf7dd4a[z04dd55c185]|=((0xf36+3818-0x1e1f)<<(0x43f+3961-0x13a3));

for(i=(0x2c6+6322-0x1b78);i<z879ede9171;i++){if(xpceIsModelInit()||(int)mxGetPr(za6b3fb79a3)[i]){index=(uint16_T)mxGetPr(zcaea56018f)[i]-(0x1286+1469-0x1842);z4e3026977c=(uint16_T)mxGetPr(z79b944ae89)[i]-(0x23ba+782-0x26c7);z7711a772ed=(uint32_T)(((real_T)mxGetPr(z5317f28eb6)[index]+offset)*z0754dd67cc);
if(z7711a772ed>z7935114df5){z7711a772ed=z7935114df5;}else if(z7711a772ed<(0x8ad+6749-0x230a)){z7711a772ed=(0x5d0+1212-0xa8c);}

za42cf7dd4a[za01cd60f50]=z7711a772ed;}}
z718c4c15f4=(0x424+4446-0x1582);for(i=(0xbbb+639-0xe3a);i<z344fcf0ef3;i++){if(xpceIsModelInit()||(int)mxGetPr(z1f9bebb47b)[i]){z4e3026977c=(uint16_T)mxGetPr(z5bc3ce0d50)[i]-(0x19f+4374-0x12b4);out=(real_T)mxGetPr(z2d8f240c11)[i];if(out>=THRESHOLD){if((z4e3026977c<=(0x145+4245-0x11d7))&&(za42cf7dd4a[(0x493+2695-0xf19)]&(0x130c+4519-0x2433))){z718c4c15f4|=(0x785+7949-0x2612);
z718c4c15f4|=(0xd38+2442-0x16c1)<<z4e3026977c;}else if(za42cf7dd4a[(0x2a4+2570-0xcad)]&32768){z718c4c15f4|=32768;
z718c4c15f4|=(0x108b+2709-0x1b1f)<<(z4e3026977c+(0x18c7+2769-0x2390));}}}}za42cf7dd4a[z676b87833d]=z718c4c15f4;za42cf7dd4a[z04dd55c185]&=4292870143;
#endif    
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

