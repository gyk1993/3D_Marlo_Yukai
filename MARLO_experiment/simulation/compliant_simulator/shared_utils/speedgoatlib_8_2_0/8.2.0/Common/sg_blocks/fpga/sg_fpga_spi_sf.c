/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x17c+6700-0x1ba6)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_spi_sf
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
#define zdf24515981        ((0x3e5+6806-0x1e6c))
#define z533b11d03f         ssGetSFcnParam(S,  (0x17bc+40-0x17e4)) 
#define za9d8fb6bcf           ssGetSFcnParam(S,  (0x3ec+1018-0x7e5)) 
#define z31fb671cb8              ssGetSFcnParam(S,  (0x1985+966-0x1d49))
#define z86af52d74e              ssGetSFcnParam(S,  (0x3e3+1025-0x7e1))
#define z1ca1c73d42      ssGetSFcnParam(S,  (0x9f4+4586-0x1bda))
#define zf5ee62a4ad      ssGetSFcnParam(S,  (0x7+746-0x2ec))
#define z3a4907dee5          ssGetSFcnParam(S,  (0x539+2711-0xfca))
#define zb0ce0940e9         ssGetSFcnParam(S,  (0x6f8+5105-0x1ae2))
#define zb00b469153        ssGetSFcnParam(S,  (0xac+6944-0x1bc4))
#define zd259a80613    ssGetSFcnParam(S,  (0xe82+4550-0x203f))
#define zbdd1493fee         ssGetSFcnParam(S, (0x1067+3110-0x1c83))
#define z5afbf66955      ssGetSFcnParam(S, (0x4e7+5315-0x199f))
#define z9bc0bec087     ssGetSFcnParam(S, (0xcc9+4658-0x1eef))
#define z3832b85a32         ssGetSFcnParam(S, (0x198a+824-0x1cb5))
#define z702a26a5e9              ssGetSFcnParam(S, (0x8dd+4530-0x1a81))
#define z2e6483d505            ((0x3e6+3887-0x1314))
#define zc5ce4cb81a            ((0x4a9+7214-0x20d7))
#define z2b17e2ee3b            ((0x53+3099-0xc6e))
#define z6a0da049de       ((0x1939+2799-0x2428))
#define z9b67aa523f              851968 
static char_T zea4cd01646[(0x1608+2823-0x200f)];typedef struct{uint32_T z15923ef3d9[(0x8d0+3190-0x1526)];uint32_T za746b13f73[(0x57a+8027-0x24b5)];uint32_T z02bb7b1721[(0x552+3908-0x1476)];uint32_T z1ad71181ab[(0x1480+938-0x180a)];uint32_T z2681ed6ece[(0x15ad+2862-0x20bb)];uint32_T z28e9d9261f[(0x185f+659-0x1ad2)];uint32_T z42ad4eacaf[(0xe92+884-0x11e6)];uint32_T zfe18d134a8[(0x234+9039-0x2563)];uint32_T z86bb419998[(0x7b8+634-0xa12)];uint32_T z08fefe38a9[(0x1d03+1878-0x2439)];uint32_T zb15396a870[(0x8a9+5113-0x1c82)];uint32_T zdd951fbe16[(0x16ed+3534-0x249b)];uint32_T z64fc736a62[(0x7fa+7220-0x240e)];uint32_T zaf2186d9ec[(0x4e5+1359-0xa14)];uint32_T z2ae1a9d412[(0xc0f+4757-0x1e84)];uint32_T z07f373fbd4[(0x1c23+2806-0x26f9)];uint32_T zac3cadef55[(0x1dd2+989-0x218f)];uint32_T za3910307c9[(0x930+833-0xc51)];uint32_T zd176e82c10[(0x692+3645-0x14af)];uint32_T z4ae288e0c9[(0x1dfc+443-0x1f97)];uint32_T z12402c138a[(0xb25+4972-0x1e71)];uint32_T z8575031947[(0x107+9034-0x2431)];uint32_T zf64b65d5a7;uint32_T z2f1801d2e2;uint32_T zbea4a89f24;uint32_T zdc0d676974;uint32_T z556bd4727a;uint32_T z19690b6adb;uint32_T z73b6066883;}z69e58993ac;void z1bceafb7d6(uint32_T*zb9e8f50428,uint32_T*z5b2574d0cd,uint32_T z15923ef3d9,uint32_T za746b13f73){int32_T i,z26dbd73a5e,z5f52b5adb3;uint8_T z718c4c15f4[(0xc44+2694-0x15ca)]={(0x1256+2517-0x1c2b)};
for(i=(0x134+381-0x2b1);i<(0x1ae4+2275-0x23bf);i++){zb9e8f50428[i]=(0x165a+882-0x19cc);}


z5f52b5adb3=(0x515+4960-0x1776);for(i=za746b13f73-(0x1720+926-0x1abd);i>=(0xfcf+2534-0x19b5);i--){for(z26dbd73a5e=z15923ef3d9-(0x25+8956-0x2320);z26dbd73a5e>=(0x223+8697-0x241c);z26dbd73a5e--){if((z5b2574d0cd[i]&((0xfaf+3424-0x1d0e)<<z26dbd73a5e))>(0x1a99+1180-0x1f35)){z718c4c15f4[z5f52b5adb3]=(0x998+2649-0x13f0);}z5f52b5adb3--;}}

z5f52b5adb3=(0x433+8122-0x23ed);for(i=(0xa9b+5937-0x21cc);i<(0x16f7+2289-0x1fe0);i++){for(z26dbd73a5e=(0xb4+7474-0x1de6);z26dbd73a5e<(0x10f0+3362-0x1df2);z26dbd73a5e++){if(z718c4c15f4[z5f52b5adb3]){zb9e8f50428[i]|=((0xb39+6023-0x22bf)<<z26dbd73a5e);}z5f52b5adb3++;}}}
void z1339a94323(uint32_T*zbcc3fe600b,uint32_T*z96295371e9,int32_T z15923ef3d9,int32_T za746b13f73){uint8_T z718c4c15f4[(0x148f+3349-0x20a4)]={(0x810+6494-0x216e)};int32_T i,z26dbd73a5e,z5f52b5adb3;

for(i=(0xa23+5339-0x1efe);i<za746b13f73;i++){zbcc3fe600b[i]=(0x6+399-0x195);}


z5f52b5adb3=(0x1c2d+526-0x1e3b);for(i=(0xf53+4998-0x22d9);i<(0x7c1+1370-0xd13);i++){for(z26dbd73a5e=(0x954+1148-0xdd0);z26dbd73a5e<(0x1614+1813-0x1d09);z26dbd73a5e++){if((z96295371e9[i]&((0x1b20+2897-0x2670)<<z26dbd73a5e))>(0xfdd+4162-0x201f)){z718c4c15f4[z5f52b5adb3]=(0x7bf+3596-0x15ca);}z5f52b5adb3++;}}
z5f52b5adb3=(0x1180+3223-0x1e17);for(i=(0xad0+1257-0xfb9);i<za746b13f73;i++){for(z26dbd73a5e=(0x20bf+678-0x2365);z26dbd73a5e<z15923ef3d9;z26dbd73a5e++){if(z718c4c15f4[z5f52b5adb3]){zbcc3fe600b[i]|=((0x10f+4202-0x1178)<<z26dbd73a5e);}z5f52b5adb3++;}}}
static void mdlInitializeSizes(SimStruct*S){uint32_T i,zbc7ebd0e53;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x2d5+2648-0xd2d));ssSetNumDiscStates(S,(0x8cf+4725-0x1b44));if((uint32_T)mxGetPr(z5afbf66955)[(0x14b0+2847-0x1fcf)]){zbc7ebd0e53=(uint32_T)mxGetN(za9d8fb6bcf);}else{zbc7ebd0e53=(0x1c55+2083-0x2478);}ssSetNumInputPorts(S,zbc7ebd0e53);for(i=(0x571+5121-0x1972);i<zbc7ebd0e53;i++){ssSetInputPortDataType(S,i,SS_UINT32);ssSetInputPortWidth(S,i,(uint32_T)mxGetPr(zb0ce0940e9)[i]);ssSetInputPortDirectFeedThrough(S,i,(0x1873+2430-0x21f0));ssSetInputPortRequiredContiguous(S,i,(0x1150+71-0x1196));}if((uint32_T)mxGetPr(z9bc0bec087)[(0xa0c+1223-0xed3)]){zbc7ebd0e53=(uint32_T)mxGetN(za9d8fb6bcf);}else{zbc7ebd0e53=(0x103f+1605-0x1684);}ssSetNumOutputPorts(S,zbc7ebd0e53);for(i=(0x1b9+5593-0x1792);i<zbc7ebd0e53;i++){ssSetOutputPortDataType(S,i,SS_UINT32);ssSetOutputPortWidth(S,i,(uint32_T)mxGetPr(zb0ce0940e9)[i]);}ssSetNumSampleTimes(S,(0xd4a+1009-0x113a));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x142+3821-0x102f));ssSetNumNonsampledZCs(S,(0x49b+3955-0x140e));for(i=(0x397+919-0x72e);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xc7f+1524-0x1273));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x288+8617-0x2431)]==-1.0){ssSetSampleTime(S,(0x1623+3733-0x24b8),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x26a+4926-0x15a8),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x5e6+1829-0xd0b),mxGetPr(z3832b85a32)[(0x574+8118-0x252a)]);ssSetOffsetTime(S,(0xa95+6264-0x230d),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i,z4e3026977c,zbea4a89f24,zdc0d676974,zf64b65d5a7;volatile z69e58993ac*zb9f7147b6c;uint8_T z16ba527520[(0x123+1091-0x552)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x10e8+4837-0x23cd)];z6f813cde47=z05b56d9d51=(0x2134+1897-0x11c8);switch(z78caf1ba61){case(0x6a5+933-0x91d):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");za4a2434e08=z182d03571c=17232;break;case(0x831+205-0x7d0):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");za4a2434e08=z182d03571c=17239;break;case(0xbb0+6628-0x2465):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");za4a2434e08=z182d03571c=16979;break;case(0x211c+1402-0x2566):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");za4a2434e08=z182d03571c=(0x16b9+2606-0x1be3);break;case(0x49d+4081-0x1357):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");za4a2434e08=z182d03571c=21069;break;case(0xd4b+3873-0x1b34):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");za4a2434e08=z182d03571c=16971;break;case(0x42b+2683-0xd6d):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");za4a2434e08=z182d03571c=17235;break;case(0x2e7+3601-0xfbe):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");za4a2434e08=z182d03571c=(0x2554+4882-0x1862);break;case(0xa36+3302-0x15db):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;case(0xd33+6940-0x2704):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;break;default:sprintf(zea4cd01646,"\x62\x6f\x61\x72\x64\x20\x74\x79\x70\x65\x20\x69\x6e\x63\x6f\x72\x72\x65\x63\x74\x2e");ssSetErrorStatus(S,zea4cd01646);return;}if(mxGetN(z702a26a5e9)==(0xf7b+1061-0x139f)){z366b2f03bf=(0x4dc+2907-0x1037);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x1303+1512-0x18eb)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x38d+3911-0x12d4)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xc79+1327-0x11a7)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x612+4227-0x1693)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x1b57+13-0x1b62)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x145c+3911-0x23a1)]);zb9f7147b6c=(z69e58993ac*)(zeccbadd9b3.VirtAddress[(0x284+4580-0x1466)]+z9b67aa523f);
if(!xpceIsModelInit()){
zbea4a89f24=zb9f7147b6c->zbea4a89f24;zdc0d676974=zb9f7147b6c->zdc0d676974;zf64b65d5a7=zb9f7147b6c->zf64b65d5a7;for(i=(0x1f0f+105-0x1f78);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xc2a+1621-0x127e);if((uint32_T)mxGetPr(z31fb671cb8)[i]){zbea4a89f24|=((0x2564+352-0x26c3)<<z4e3026977c);}else{zbea4a89f24&=~((0xd99+1221-0x125d)<<z4e3026977c);}if((uint32_T)mxGetPr(z86af52d74e)[i]){zdc0d676974|=((0x8e6+3807-0x17c4)<<z4e3026977c);}else{zdc0d676974&=~((0x47b+81-0x4cb)<<z4e3026977c);}if((uint32_T)mxGetPr(z1ca1c73d42)[i]==(0x301+287-0x41f)){zf64b65d5a7|=((0x911+7280-0x2580)<<z4e3026977c);}else{zf64b65d5a7&=~((0x1109+2485-0x1abd)<<z4e3026977c);}zb9f7147b6c->z15923ef3d9[z4e3026977c]=(uint32_T)mxGetPr(z3a4907dee5)[i];zb9f7147b6c->za746b13f73[z4e3026977c]=(uint32_T)mxGetPr(zb0ce0940e9)[i];zb9f7147b6c->z02bb7b1721[z4e3026977c]=(uint32_T)mxGetPr(zb00b469153)[i];zb9f7147b6c->z1ad71181ab[z4e3026977c]=(uint32_T)mxGetPr(zd259a80613)[i];zb9f7147b6c->z2681ed6ece[z4e3026977c]=(uint32_T)mxGetPr(zbdd1493fee)[i];zb9f7147b6c->z28e9d9261f[z4e3026977c]=(uint32_T)mxGetPr(zf5ee62a4ad)[i];}zb9f7147b6c->zbea4a89f24=zbea4a89f24;zb9f7147b6c->zdc0d676974=zdc0d676974;zb9f7147b6c->zf64b65d5a7=zf64b65d5a7;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
int32_T base,i,z26dbd73a5e,z4e3026977c,zcd308d01c9;volatile z69e58993ac*zb9f7147b6c;uint32_T*in,*out;
uint32_T z4840e5f93b[(0x3e4+5531-0x1977)],*z9f72036884;
uint32_T z96295371e9[(0x5b+2715-0xaee)],*zbcc3fe600b;base=ssGetIWorkValue(S,z6a0da049de);zb9f7147b6c=(z69e58993ac*)(base+z9b67aa523f);if((uint32_T)mxGetPr(z5afbf66955)[(0x281+3759-0x1130)])
{zcd308d01c9=(0xee5+3723-0x1d70);
for(i=(0x4e7+2105-0xd20);i<(int32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(int32_T)mxGetPr(za9d8fb6bcf)[i]-(0x18a4+1143-0x1d1a);z9f72036884=malloc((int32_T)mxGetPr(zb0ce0940e9)[i]*sizeof(uint32_T));in=(uint32_T*)ssGetInputPortSignal(S,i);for(z26dbd73a5e=(0x47a+5017-0x1813);z26dbd73a5e<(int32_T)mxGetPr(zb0ce0940e9)[i];z26dbd73a5e++){z9f72036884[z26dbd73a5e]=in[z26dbd73a5e];}z1bceafb7d6(z4840e5f93b,z9f72036884,(int32_T)mxGetPr(z3a4907dee5)[i],(int32_T)mxGetPr(zb0ce0940e9)[i]);

zb9f7147b6c->z2ae1a9d412[z4e3026977c]=z4840e5f93b[(0x1201+1611-0x184c)];zb9f7147b6c->z07f373fbd4[z4e3026977c]=z4840e5f93b[(0x5d4+5628-0x1bcf)];zb9f7147b6c->zac3cadef55[z4e3026977c]=z4840e5f93b[(0xb2b+6892-0x2615)];zb9f7147b6c->za3910307c9[z4e3026977c]=z4840e5f93b[(0x1c54+565-0x1e86)];zb9f7147b6c->zd176e82c10[z4e3026977c]=z4840e5f93b[(0xd9f+6405-0x26a0)];zb9f7147b6c->z4ae288e0c9[z4e3026977c]=z4840e5f93b[(0x104b+5216-0x24a6)];zb9f7147b6c->z12402c138a[z4e3026977c]=z4840e5f93b[(0x46a+7875-0x2327)];zb9f7147b6c->z8575031947[z4e3026977c]=z4840e5f93b[(0x17a5+460-0x196a)];free(z9f72036884);
zcd308d01c9|=((0x9c9+3962-0x1942)<<z4e3026977c);}
zb9f7147b6c->z2f1801d2e2=zcd308d01c9;zb9f7147b6c->z2f1801d2e2=(0x3a4+2934-0xf1a);}if((uint32_T)mxGetPr(z9bc0bec087)[(0xb64+4789-0x1e19)]){
if((uint32_T)mxGetPr(z1ca1c73d42)[(0x2f9+394-0x483)]==(0x1212+2216-0x1ab9)){while((zb9f7147b6c->z556bd4727a&zcd308d01c9)!=zcd308d01c9);}
for(i=(0xf55+2122-0x179f);i<(int32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(int32_T)mxGetPr(za9d8fb6bcf)[i]-(0xd41+6086-0x2506);
z96295371e9[(0x1fd+5335-0x16d4)]=zb9f7147b6c->z42ad4eacaf[z4e3026977c];
z96295371e9[(0x51f+3699-0x1391)]=zb9f7147b6c->zfe18d134a8[z4e3026977c];
z96295371e9[(0x11a3+3576-0x1f99)]=zb9f7147b6c->z86bb419998[z4e3026977c];
z96295371e9[(0x320+7743-0x215c)]=zb9f7147b6c->z08fefe38a9[z4e3026977c];
z96295371e9[(0xcf5+2698-0x177b)]=zb9f7147b6c->zb15396a870[z4e3026977c];
z96295371e9[(0x14da+2539-0x1ec0)]=zb9f7147b6c->zdd951fbe16[z4e3026977c];
z96295371e9[(0x6b+396-0x1f1)]=zb9f7147b6c->z64fc736a62[z4e3026977c];
z96295371e9[(0x6f1+4122-0x1704)]=zb9f7147b6c->zaf2186d9ec[z4e3026977c];

zbcc3fe600b=malloc((int32_T)mxGetPr(zb0ce0940e9)[i]*sizeof(uint32_T));z1339a94323(zbcc3fe600b,z96295371e9,(int32_T)mxGetPr(z3a4907dee5)[i],(int32_T)mxGetPr(zb0ce0940e9)[i]);
out=(uint32_T*)ssGetOutputPortSignal(S,i);for(z26dbd73a5e=(0xa24+6124-0x2210);z26dbd73a5e<(int32_T)mxGetPr(zb0ce0940e9)[i];z26dbd73a5e++){out[z26dbd73a5e]=zbcc3fe600b[z26dbd73a5e];}
free(zbcc3fe600b);}}
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
