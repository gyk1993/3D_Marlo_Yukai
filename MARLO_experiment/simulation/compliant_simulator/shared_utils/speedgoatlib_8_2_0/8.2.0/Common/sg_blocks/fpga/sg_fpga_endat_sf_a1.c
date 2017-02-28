/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x855+2059-0x105e)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_endat_sf_a1
#include 	<stddef.h>
#include 	<stdlib.h>
#include  <math.h>
#include 	"simstruc.h" 
#ifdef 		MATLAB_MEX_FILE
#include 	"mex.h"
#endif
#ifndef  MATLAB_MEX_FILE
#include <windows.h>
#include "io_xpcimport.h"
#include "pci_xpcimport.h"
#include "time_xpcimport.h"
#include "ioext_xpcimport.h"
#include "util_xpcimport.h"
#endif
#define zdf24515981        ((0x8b6+1675-0xf36)) 
#define z533b11d03f         ssGetSFcnParam(S,  (0xb2+123-0x12d))  
#define za9d8fb6bcf           ssGetSFcnParam(S,  (0xce0+2069-0x14f4))  
#define z3832b85a32         ssGetSFcnParam(S,  (0x38b+5099-0x1774))  
#define z702a26a5e9              ssGetSFcnParam(S,  (0xb7c+5941-0x22ae))  
#define zdb6deb4abb       ssGetSFcnParam(S,  (0xb1+1913-0x826))  
#define zaafb76cff8   ssGetSFcnParam(S,  (0x1318+903-0x169a))  
#define z17ee1edf87   ssGetSFcnParam(S,  (0x1b3d+1134-0x1fa5))  
#define z92028f5179         ssGetSFcnParam(S,  (0x10c4+5357-0x25aa))  
#define z5291370c09     ssGetSFcnParam(S,  (0x1712+2891-0x2255))  
#define z837907708e   ssGetSFcnParam(S,  (0x5e8+7370-0x22a9))  
#define z1272ff95a8    ssGetSFcnParam(S,  (0x9d6+2700-0x1458)) 
#define zc3abbe7eb0 (0x1e88+1911-0x25cf)
#define z2e6483d505            ((0xeb9+400-0x1047))
#define zc5ce4cb81a            ((0x289+7246-0x1ed7))
#define z2b17e2ee3b            ((0x22a+1300-0x73e))
#define z6a0da049de       ((0x1ca+4262-0x1270))
#define z23d7148f08         ((0x17b+6037-0x190f)) 
#define za0a0c1033d             393216

void zf4047a8710(SimStruct*S,enum z27dce6945f mode,uint8_T z4966782f31,uint16_T z7e1088d4a8,uint8_T z133ffa41db);void z9d385537bd(SimStruct*S,enum z27dce6945f mode,uint8_T z4966782f31,uint16_T z7e1088d4a8);static char_T zea4cd01646[(0x17c9+2741-0x217e)];typedef struct{uint32_T z027568aa65[(0x1016+4228-0x207a)];uint32_T z0fe2089aaf[(0xbd+1566-0x6bb)];uint32_T zbcf8ec971a[(0x529+1588-0xb3d)];uint32_T z01bba996c7[(0x4a5+5988-0x1be9)];uint32_T zcba7ccbc32[(0x254+4237-0x12c1)];uint32_T z41e6678e62[(0x24+7005-0x1b61)];uint32_T z3884ceefa0[(0xa7c+5786-0x20f6)];uint32_T zfbc40eefb9[(0x49a+7065-0x2013)];uint32_T z5451129c82;uint32_T z97287efa46;uint32_T zeeeba54a90;uint32_T zea70196bc2;uint32_T z19690b6adb;uint32_T z73b6066883;}z12533270f3;enum z27dce6945f{z017eafc8e7=(0x1975+182-0x1a24),z1bdb5475e3=(0x121c+582-0x1454),za0025817ff=(0xa2+1283-0x589),z44434285f4=(0xc6+1605-0x6e8),zf8b38fdc22=(0x15a1+857-0x18d0),za870d43c64=(0x4d1+1770-0xba6),zf5f9a4b551=(0x3c+4600-0x1203),z1209f5d6ff=(0x1c58+1240-0x20f8),z1cf42ca33f=(0xefb+1932-0x167e),zf022f0025c=(0x60b+7107-0x21b3),z2d518d8bbe=(0xbf0+3770-0x1a86),z47e41ac44f=(0x2450+535-0x263a),z0c91ffb2ea=(0x6f4+6642-0x20b0),za515f21bce=(0x101+3384-0xe27)};static void mdlInitializeSizes(SimStruct*S){uint32_T i,zbc7ebd0e53,zde2210a484;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x169+59-0x1a4));ssSetNumDiscStates(S,(0x1c+2953-0xba5));
ssSetNumInputPorts(S,(0x365+8031-0x22c4));
zbc7ebd0e53=(0x1909+2232-0x21c0);if((uint32_T)mxGetPr(z1272ff95a8)[(0x682+4970-0x19ec)]){zbc7ebd0e53+=(0x1472+1479-0x1a37);}if((uint32_T)mxGetPr(z837907708e)[(0x840+4374-0x1956)]){zbc7ebd0e53+=(0x18d2+2266-0x21ab);}zde2210a484=(uint32_T)mxGetN(za9d8fb6bcf);ssSetNumOutputPorts(S,zbc7ebd0e53);for(i=(0x1496+3442-0x2208);i<zbc7ebd0e53;i++){ssSetOutputPortDataType(S,i,SS_UINT32);
ssSetOutputPortWidth(S,i,zde2210a484);}ssSetNumSampleTimes(S,(0x9d1+5032-0x1d78));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x10f8+2988-0x1ca4));ssSetNumNonsampledZCs(S,(0x360+7098-0x1f1a));for(i=(0x16b8+1459-0x1c6b);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1523+339-0x1676));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x21cd+50-0x21ff)]==-1.0){ssSetSampleTime(S,(0x164d+2209-0x1eee),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x9ca+4915-0x1cfd),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x1251+3026-0x1e23),mxGetPr(z3832b85a32)[(0x10d3+2216-0x197b)]);ssSetOffsetTime(S,(0x1eea+1819-0x2605),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i,z4e3026977c;volatile z12533270f3*z8c651b2813;real_T z9ab632cec0,zab642cf9f7;uint8_T z16ba527520[(0xa3f+5408-0x1f4b)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61;uint32_T ze120d93882,ze6fc8c4625,z772ac2e27d=(0x1ad9+2620-0x2515);real_T z46ecb9e916;uint8_T zfb0d8e35a1;uint32_T*z78e4183e4d;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x15b2+53-0x15e7)];z6f813cde47=z05b56d9d51=5845;switch(z78caf1ba61){case(0x1832+210-0x17b9):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;break;default:sprintf(zea4cd01646,"\x62\x6f\x61\x72\x64\x20\x74\x79\x70\x65\x20\x69\x6e\x63\x6f\x72\x72\x65\x63\x74\x2e");ssSetErrorStatus(S,zea4cd01646);return;}if(mxGetN(z702a26a5e9)==(0x1a6d+2512-0x243c)){z366b2f03bf=(0xd7a+332-0xec6);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x142f+111-0x149e)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x717+7768-0x256f)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x19c4+1581-0x1ff0)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0xa4c+1416-0xfd2)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x4bc+596-0x70e)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x110f+3833-0x2006)]);z8c651b2813=(z12533270f3*)(zeccbadd9b3.VirtAddress[(0x2d4+1530-0x8cc)]+za0a0c1033d);if(!xpceIsModelInit()){
printf("\x46\x50\x47\x41\x20\x45\x6e\x44\x61\x74\x20\x63\x6f\x64\x65\x6d\x6f\x64\x75\x6c\x65\x20\x76\x65\x72\x73\x69\x6f\x6e\x20\x25\x6c\x75\x2e\x25\x6c\x75\x2e\x25\x6c\x75" "\n",z8c651b2813->z97287efa46,z8c651b2813->zeeeba54a90,z8c651b2813->zea70196bc2);





for(i=(0x14e2+4196-0x2546);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){
z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x76b+6944-0x228a);
z8c651b2813->z0fe2089aaf[z4e3026977c]=(uint32_T)mxGetPr(z92028f5179)[i];
z8c651b2813->zbcf8ec971a[z4e3026977c]=(uint32_T)mxGetPr(z5291370c09)[i];}


z9d385537bd(S,zf8b38fdc22,(0x1166+3413-0x1ebb),(0xc33+4012-0x1bdf));


rl32eWaitDouble((0x7af+1286-0xcb4));

if(mxGetPr(zdb6deb4abb)[(0x16ab+2111-0x1eea)]){
zfb0d8e35a1=(0x1299+4437-0x23ee);

for(i=(0x13b1+613-0x1616);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){
z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xab5+4638-0x1cd2);



zf4047a8710(S,z1bdb5475e3,(0x1992+918-0x1c85),(0x111+636-0x38d),z4e3026977c);
zf4047a8710(S,z44434285f4,(0x1a96+1997-0x2262),(0x198f+123-0x1a0a),z4e3026977c);
ze6fc8c4625=z8c651b2813->zcba7ccbc32[z4e3026977c];printf("\x45\x6e\x63\x6f\x64\x65\x72\x20\x44\x69\x73\x74\x69\x6e\x67\x75\x69\x73\x68\x61\x62\x6c\x65\x20\x72\x65\x76\x6f\x6c\x75\x74\x69\x6f\x6e\x73\x20\x63\x68\x61\x6e\x5b\x25\x64\x5d\x3a\x20\x30\x78\x25\x30\x38\x58\x20\x28\x25\x64\x29" "\n",z4e3026977c,ze6fc8c4625,ze6fc8c4625);if(ze6fc8c4625>(0x142+8060-0x20be)){if(ze6fc8c4625==65535){sprintf(zea4cd01646,"\x54\x68\x69\x73\x20\x45\x6e\x44\x61\x74\x20\x45\x6e\x63\x6f\x64\x65\x72\x20\x69\x73\x20\x63\x75\x72\x72\x65\x6e\x74\x6c\x79\x20\x6e\x6f\x74\x20\x73\x75\x70\x70\x6f\x72\x74\x65\x64" "\n");ssSetErrorStatus(S,zea4cd01646);}z46ecb9e916=log10(ze6fc8c4625)-floor(log10(ze6fc8c4625)/log10(2.0))*log10(2.0);if(z46ecb9e916==0.0){ze6fc8c4625=(uint32_T)floor(log10(ze6fc8c4625)/log10(2.0));}else{sprintf(zea4cd01646,"\x45\x6e\x44\x61\x74\x20\x64\x69\x73\x74\x69\x6e\x2e\x20\x72\x65\x76\x6f\x6c\x75\x74\x69\x6f\x6e\x73\x3a\x20\x69\x6e\x63\x6f\x72\x72\x65\x63\x74\x20\x72\x65\x61\x64\x6f\x75\x74\x21" "\n");ssSetErrorStatus(S,zea4cd01646);}zfb0d8e35a1=(0x1734+2277-0x2018);
}printf("\x44\x69\x73\x74\x69\x6e\x67\x75\x69\x73\x68\x61\x62\x6c\x65\x20\x72\x65\x76\x6f\x6c\x75\x74\x69\x6f\x6e\x73\x20\x77\x69\x64\x74\x68\x20\x63\x68\x61\x6e\x5b\x25\x64\x5d\x3a\x20\x25\x64" "\n",z4e3026977c,ze6fc8c4625);z8c651b2813->z41e6678e62[z4e3026977c]=ze6fc8c4625;



zf4047a8710(S,z1bdb5475e3,(0x1a7+3146-0xd50),(0xd33+5069-0x2100),z4e3026977c);
zf4047a8710(S,z44434285f4,(0xe45+2187-0x16c3),(0x1006+1307-0x1521),z4e3026977c);
ze120d93882=z8c651b2813->zcba7ccbc32[z4e3026977c];
if((ze120d93882&32768)==(0x477+8733-0x2694)){sprintf(zea4cd01646,"\x45\x6e\x44\x61\x74\x20\x70\x61\x72\x61\x6d\x65\x74\x65\x72\x20\x72\x65\x61\x64\x6f\x75\x74\x3a\x20\x63\x6f\x72\x72\x75\x70\x74\x65\x64\x20\x72\x65\x61\x64\x6f\x75\x74" "\n");ssSetErrorStatus(S,zea4cd01646);}else{ze120d93882&=32767;
}if(ze120d93882>ze6fc8c4625){z772ac2e27d=ze120d93882-ze6fc8c4625;}else{sprintf(zea4cd01646,"\x45\x6e\x44\x61\x74\x20\x61\x75\x74\x6f\x6d\x61\x74\x69\x63\x20\x72\x65\x61\x64\x6f\x75\x74\x3a\x20\x63\x6f\x72\x72\x75\x70\x74\x65\x64\x20\x72\x65\x61\x64\x6f\x75\x74" "\n");ssSetErrorStatus(S,zea4cd01646);}
z8c651b2813->z027568aa65[z4e3026977c]=ze120d93882;
printf("\x74\x6f\x74\x42\x69\x74\x57\x69\x64\x74\x68\x3d\x25\x64\x2c\x20\x72\x65\x76\x57\x69\x64\x74\x68\x3d\x25\x64\x2c\x20\x73\x69\x6e\x67\x57\x69\x64\x74\x68\x3d\x25\x64" "\n",ze120d93882,ze6fc8c4625,z772ac2e27d);if((uint32_T)mxGetPr(z1272ff95a8)[(0xe5+2076-0x901)]){z78e4183e4d=(uint32_T*)ssGetOutputPortSignal(S,(0x445+4387-0x1567));
z78e4183e4d[z4e3026977c]=z772ac2e27d;}}}else{
zfb0d8e35a1=(0xf44+5717-0x2599);for(i=(0xba7+6966-0x26dd);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){
z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x568+549-0x78c);
z772ac2e27d=(uint32_T)mxGetPr(zaafb76cff8)[i];ze6fc8c4625=(uint32_T)mxGetPr(z17ee1edf87)[i];if(ze6fc8c4625>(0x1e7a+425-0x2023)){zfb0d8e35a1=(0x388+6117-0x1b6c);
}z8c651b2813->z41e6678e62[z4e3026977c]=ze6fc8c4625;ze120d93882=z772ac2e27d+ze6fc8c4625;z8c651b2813->z027568aa65[z4e3026977c]=ze120d93882;
printf("\x74\x6f\x74\x42\x69\x74\x57\x69\x64\x74\x68\x3d\x25\x64\x2c\x20\x72\x65\x76\x57\x69\x64\x74\x68\x3d\x25\x64\x2c\x20\x73\x69\x6e\x67\x57\x69\x64\x74\x68\x3d\x25\x64" "\n",ze120d93882,ze6fc8c4625,z772ac2e27d);if((uint32_T)mxGetPr(z1272ff95a8)[(0xcbc+1426-0x124e)]){z78e4183e4d=(uint32_T*)ssGetOutputPortSignal(S,(0xc8a+1312-0x11a9));
z78e4183e4d[z4e3026977c]=z772ac2e27d;}}}
ssSetIWorkValue(S,z23d7148f08,zfb0d8e35a1);}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base,i,z4e3026977c;uint8_T zfb0d8e35a1;volatile z12533270f3*z8c651b2813;uint32_T*z6eb2d4d8b7;uint32_T*z78e4183e4d;uint32_T*z0e0892c1c0;uint32_T*z1312a42048;
uint32_T z407efd0741;uint32_T z4334ea8c38=(0x1d78+1529-0x2371);uint32_T z9f43637a3a;base=ssGetIWorkValue(S,z6a0da049de);z8c651b2813=(z12533270f3*)(base+za0a0c1033d);
zfb0d8e35a1=ssGetIWorkValue(S,z23d7148f08);
z9d385537bd(S,z017eafc8e7,(0x1d55+462-0x1f23),(0x822+4347-0x191d));
z6eb2d4d8b7=(uint32_T*)ssGetOutputPortSignal(S,(0x1d4a+352-0x1eaa));
if((uint32_T)mxGetPr(z1272ff95a8)[(0x1c80+563-0x1eb3)]){z78e4183e4d=(uint32_T*)ssGetOutputPortSignal(S,(0xab7+1319-0xfdd));
z0e0892c1c0=(uint32_T*)ssGetOutputPortSignal(S,(0xa9+2601-0xad0));
if((uint32_T)mxGetPr(z837907708e)[(0xebd+108-0xf29)]){z1312a42048=(uint32_T*)ssGetOutputPortSignal(S,(0x1776+3473-0x2504));
}}else{if((uint32_T)mxGetPr(z837907708e)[(0x48c+8322-0x250e)]){z1312a42048=(uint32_T*)ssGetOutputPortSignal(S,(0xfbf+7-0xfc5));
}}
for(i=(0x5e8+4989-0x1965);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x12aa+3818-0x2193);
z407efd0741=z8c651b2813->zcba7ccbc32[z4e3026977c];
z6eb2d4d8b7[i]=z407efd0741;

if(zfb0d8e35a1==(0x437+6103-0x1c0d)){
z4334ea8c38=z8c651b2813->z3884ceefa0[z4e3026977c];}
if((uint32_T)mxGetPr(z1272ff95a8)[(0x356+6266-0x1bd0)]){z0e0892c1c0[i]=z4334ea8c38;}
if((uint32_T)mxGetPr(z837907708e)[(0x262+8504-0x239a)]){z9f43637a3a=z8c651b2813->zfbc40eefb9[z4e3026977c];z1312a42048[i]=z9f43637a3a;}}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE     
#endif
}
#ifndef MATLAB_MEX_FILE
void zf4047a8710(SimStruct*S,enum z27dce6945f mode,uint8_T z4966782f31,uint16_T z7e1088d4a8,uint8_T z133ffa41db){uint32_T z01bba996c7=(0x2a1+7627-0x206c);real_T z9ab632cec0,zab642cf9f7;uint32_T base;uint32_T z071fd3e93a=(0x18ad+2491-0x2268);volatile z12533270f3*z8c651b2813;
base=ssGetIWorkValue(S,z6a0da049de);z8c651b2813=(z12533270f3*)(base+za0a0c1033d);
z01bba996c7|=(mode<<(0x1359+245-0x1436));z01bba996c7|=(z4966782f31<<(0x1558+665-0x17e1));z01bba996c7|=z7e1088d4a8;z8c651b2813->z01bba996c7[z133ffa41db]=z01bba996c7;z071fd3e93a=((0x470+4439-0x15c6)<<z133ffa41db);

z8c651b2813->z5451129c82=z071fd3e93a;
z9ab632cec0=rl32eGetTicksDouble();
while((z8c651b2813->z5451129c82&z071fd3e93a)!=(0xcb3+3808-0x1b93)){zab642cf9f7=rl32eGetTicksDouble();
if(rl32eETimeDouble(zab642cf9f7,z9ab632cec0)>3.0)
{sprintf(zea4cd01646,"\x45\x6e\x44\x61\x74\x20\x72\x65\x61\x64\x3a\x20\x54\x69\x6d\x65\x2d\x6f\x75\x74\x20\x65\x72\x72\x6f\x72");ssSetErrorStatus(S,zea4cd01646);return;}}}
#endif
#ifndef MATLAB_MEX_FILE
void z9d385537bd(SimStruct*S,enum z27dce6945f mode,uint8_T z4966782f31,uint16_T z7e1088d4a8){uint32_T z01bba996c7=(0xa7f+5444-0x1fc3);real_T z9ab632cec0,zab642cf9f7;uint32_T base;uint8_T z133ffa41db,i;uint32_T zcd308d01c9=(0x17ba+566-0x19f0);volatile z12533270f3*z8c651b2813;
base=ssGetIWorkValue(S,z6a0da049de);z8c651b2813=(z12533270f3*)(base+za0a0c1033d);
z01bba996c7|=(mode<<(0x1931+381-0x1a96));z01bba996c7|=(z4966782f31<<(0xc45+1048-0x104d));z01bba996c7|=z7e1088d4a8;for(i=(0x156d+2892-0x20b9);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z133ffa41db=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xbaa+3780-0x1a6d);
zcd308d01c9|=((0xd0a+1291-0x1214)<<z133ffa41db);z8c651b2813->z01bba996c7[z133ffa41db]=z01bba996c7;}

z8c651b2813->z5451129c82=zcd308d01c9;
z9ab632cec0=rl32eGetTicksDouble();
while((z8c651b2813->z5451129c82&zcd308d01c9)!=(0x184f+2295-0x2146)){zab642cf9f7=rl32eGetTicksDouble();
if(rl32eETimeDouble(zab642cf9f7,z9ab632cec0)>3.0)
{sprintf(zea4cd01646,"\x45\x6e\x44\x61\x74\x20\x72\x65\x61\x64\x3a\x20\x54\x69\x6d\x65\x2d\x6f\x75\x74\x20\x65\x72\x72\x6f\x72");ssSetErrorStatus(S,zea4cd01646);return;}}}
#endif    
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif
