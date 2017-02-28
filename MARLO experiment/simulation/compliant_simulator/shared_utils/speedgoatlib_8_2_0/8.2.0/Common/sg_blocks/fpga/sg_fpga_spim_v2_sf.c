/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xaa7+3023-0x1674)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_spim_v2_sf
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
#include        "xpcPCFunctions.h"
#include        "time_xpcimport.h"
#include        "ioext_xpcimport.h"
#include        "util_xpcimport.h"
#endif
#define zdf24515981              ((0xafd+5689-0x2126))
#define z533b11d03f               ssGetSFcnParam(S,  (0x8b0+1228-0xd7c))
#define za9d8fb6bcf                 ssGetSFcnParam(S,  (0x1069+2685-0x1ae5))
#define zf6f668e67a         ssGetSFcnParam(S,  (0x3f5+6500-0x1d57))
#define zbb0d1897b2     ssGetSFcnParam(S,  (0x6eb+3350-0x13fe))
#define z8f7a5b7479           ssGetSFcnParam(S,  (0x60d+6581-0x1fbe))
#define zdc5f8981b7              ssGetSFcnParam(S,  (0x6e5+4524-0x188c))
#define zc09b06e5fc             ssGetSFcnParam(S,  (0xae9+2892-0x162f))
#define z7039def18e              ssGetSFcnParam(S,  (0x1b00+300-0x1c25))
#define z86af52d74e                    ssGetSFcnParam(S,  (0x86c+6164-0x2078))
#define z31fb671cb8                    ssGetSFcnParam(S,  (0xeda+843-0x121c))
#define zea4d7ef473                ssGetSFcnParam(S, (0x160b+4018-0x25b3))
#define z3d4ad966bd                   ssGetSFcnParam(S, (0x4dd+324-0x616))
#define z62fc1d1d8e              ssGetSFcnParam(S, (0x23e8+760-0x26d4))
#define z08a9674173        ssGetSFcnParam(S, (0x445+1206-0x8ee))
#define z3832b85a32               ssGetSFcnParam(S, (0xc30+6019-0x23a5))
#define z702a26a5e9                    ssGetSFcnParam(S, (0x1cf2+414-0x1e81))
#define z2e6483d505              ((0x1535+3681-0x2394))
#define z7e2eeaa57c          ((0x2131+507-0x232c))
#define z6a0da049de         ((0x795+3998-0x1732))
#define zc5ce4cb81a              ((0x803+4884-0x1b07))
#define z2b17e2ee3b              ((0xd1a+2639-0x1769))
static char_T zea4cd01646[(0x4f1+608-0x651)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x66b+6734-0x20b9));ssSetNumDiscStates(S,(0x126a+248-0x1362));if(mxGetPr(z62fc1d1d8e)[(0x19f4+228-0x1ad8)]){ssSetNumOutputPorts(S,mxGetN(za9d8fb6bcf));for(i=(0xe26+4086-0x1e1c);i<mxGetN(za9d8fb6bcf);i++){ssSetOutputPortWidth(S,i,(uint32_T)mxGetPr(z3d4ad966bd)[(0x815+4589-0x1a02)]+(0x6cd+4987-0x1a47));}}else{ssSetNumOutputPorts(S,(0x533+8447-0x2632));}if(mxGetPr(z08a9674173)[(0x2019+1757-0x26f6)]){ssSetNumInputPorts(S,(mxGetN(za9d8fb6bcf)*(0xc59+572-0xe93))+(0x761+3021-0x132d));}else{ssSetNumInputPorts(S,mxGetN(za9d8fb6bcf)*(0x84c+355-0x9ad));}
for(i=(0xfb6+393-0x113f);i<mxGetN(za9d8fb6bcf);i++){ssSetInputPortWidth(S,i,(uint32_T)mxGetPr(z3d4ad966bd)[(0xec+7791-0x1f5b)]+(0xc86+2531-0x1668));ssSetInputPortDirectFeedThrough(S,i,(0x9b5+1694-0x1052));ssSetInputPortRequiredContiguous(S,i,(0x6cf+629-0x943));}
for(i=(0x503+451-0x6c6);i<mxGetN(za9d8fb6bcf);i++){ssSetInputPortWidth(S,i+(uint32_T)mxGetN(za9d8fb6bcf),(0x240+744-0x527));ssSetInputPortDirectFeedThrough(S,i+(uint32_T)mxGetN(za9d8fb6bcf),(0x398+7636-0x216b));ssSetInputPortRequiredContiguous(S,i+(uint32_T)mxGetN(za9d8fb6bcf),(0x8ad+3327-0x15ab));}
if(mxGetPr(z08a9674173)[(0x883+6422-0x2199)]){ssSetInputPortWidth(S,(((uint32_T)mxGetN(za9d8fb6bcf))*(0x1793+727-0x1a68)),mxGetN(za9d8fb6bcf));ssSetInputPortDirectFeedThrough(S,(((uint32_T)mxGetN(za9d8fb6bcf))*(0xf27+3750-0x1dcb)),(0x1a39+189-0x1af5));ssSetInputPortRequiredContiguous(S,(((uint32_T)mxGetN(za9d8fb6bcf))*(0xe40+3899-0x1d79)),(0xf1+3366-0xe16));}ssSetNumSampleTimes(S,(0x853+1944-0xfea));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x907+7320-0x259f));ssSetNumNonsampledZCs(S,(0x18c8+2056-0x20d0));for(i=(0x16f8+115-0x176b);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x53a+3926-0x1490));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x29f+2984-0xe47)]==-1.0){ssSetSampleTime(S,(0xad2+7051-0x265d),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x29c+3477-0x1031),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xf5+5564-0x16b1),mxGetPr(z3832b85a32)[(0x101+5766-0x1787)]);ssSetOffsetTime(S,(0x46c+7056-0x1ffc),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint8_T z16ba527520[(0x20c+1249-0x6d9)];uint16_T z6f813cde47,za4a2434e08;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x1c0d+2800-0x26fd)];switch(z78caf1ba61){case(0x157b+2547-0x1e41):strcpy(z16ba527520,"\x49\x4f\x33\x30\x31");z6f813cde47=5845;za4a2434e08=17232;break;case(0x16c2+3643-0x23cf):strcpy(z16ba527520,"\x49\x4f\x33\x30\x32");z6f813cde47=5845;za4a2434e08=17239;break;case(0x1450+1270-0x1817):strcpy(z16ba527520,"\x49\x4f\x33\x30\x33");z6f813cde47=(0x1948+1437-0x810);za4a2434e08=16979;break;case(0xe74+1094-0x118a):strcpy(z16ba527520,"\x49\x4f\x33\x30\x34");z6f813cde47=(0x189c+472-0x39f);za4a2434e08=(0x85b+232-0x43f);break;case(0x4a7+6714-0x1daa):strcpy(z16ba527520,"\x49\x4f\x33\x31\x31");z6f813cde47=5845;za4a2434e08=21069;break;case(0x92a+7760-0x2642):strcpy(z16ba527520,"\x49\x4f\x33\x31\x32");z6f813cde47=5845;za4a2434e08=16971;break;case(0xbaa+779-0xd7c):strcpy(z16ba527520,"\x49\x4f\x33\x31\x33");z6f813cde47=(0x1e1b+439-0x8fd);za4a2434e08=17235;break;case(0x2625+509-0x26e8):strcpy(z16ba527520,"\x49\x4f\x33\x31\x34");z6f813cde47=5845;za4a2434e08=8196;break;case(0xef4+4117-0x1dc8):strcpy(z16ba527520,"\x49\x4f\x33\x32\x31");z6f813cde47=5845;za4a2434e08=19520;break;}if((int_T)mxGetPr(z702a26a5e9)[(0x1b76+2293-0x246b)]<(0x219d+343-0x22f4)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xfc+1495-0x6d2)){z366b2f03bf=(0x10cb+4560-0x229b);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x5d9+6409-0x1ee2)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x1316+5020-0x26b2)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x42f+7828-0x22c2)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x268+1687-0x800))|((z366b2f03bf&(0x62b+8655-0x26fb))<<(0x183f+734-0x1b15)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x1a77+624-0x1ce5)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE     
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;uint32_T z26dbd73a5e,i,width,count,z03312e422a,z4da3ce354d;real_T*in,*out,*z46c2b7bc26,*zfbec81ea2e;uint32_T z4e3026977c,status;uint32_T z830dd005b1=(uint32_T)mxGetN(za9d8fb6bcf);width=(uint32_T)mxGetPr(z3d4ad966bd)[(0x92d+2313-0x1236)]+(0x5b2+7119-0x2180);za42cf7dd4a=(void*)base;
z03312e422a=(0xd79+1396-0x12ed);for(i=(0x6d8+6476-0x2024);i<mxGetN(za9d8fb6bcf);i++)
{
z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x8d8+6206-0x2115);in=(real_T*)ssGetInputPortSignal(S,z4e3026977c);
z4da3ce354d=i+z830dd005b1;zfbec81ea2e=(real_T*)ssGetInputPortSignal(S,z4da3ce354d);za42cf7dd4a[10416+z4e3026977c]=zfbec81ea2e[(0x8c6+556-0xaf2)]-(0x22+9035-0x236c);count=za42cf7dd4a[10320+z4e3026977c];if(count>(0x427+6611-0x1dfa)){sprintf(zea4cd01646,"\x54\x72\x69\x65\x64\x20\x74\x6f\x20\x77\x72\x69\x74\x65\x20\x69\x6e\x20\x61\x20\x6e\x6f\x6e\x2d\x65\x6d\x70\x74\x79\x20\x62\x75\x66\x66\x65\x72");ssSetErrorStatus(S,zea4cd01646);return;}
if(mxGetPr(z08a9674173)[(0x1792+1719-0x1e49)]){z46c2b7bc26=(real_T*)ssGetInputPortSignal(S,mxGetN(za9d8fb6bcf)*(0x613+144-0x6a1));za42cf7dd4a[10336+z4e3026977c]=(uint32_T)z46c2b7bc26[i];}count=(uint32_T)in[(0x3a4+5680-0x19d4)];for(z26dbd73a5e=(0x3e3+7143-0x1fca);z26dbd73a5e<count;z26dbd73a5e++)
{
za42cf7dd4a[10256+z4e3026977c]=(uint32_T)in[z26dbd73a5e+(0x801+3350-0x1516)];
za42cf7dd4a[10304+z4e3026977c]=z26dbd73a5e;
za42cf7dd4a[10250]=((0x1a34+1745-0x2104)<<z4e3026977c);za42cf7dd4a[10250]=(0x1856+1490-0x1e28);}
za42cf7dd4a[10320+z4e3026977c]=count;za42cf7dd4a[10249]=((0x173b+3603-0x254d)<<z4e3026977c);za42cf7dd4a[10249]=(0xd1b+834-0x105d);
}



if(mxGetPr(z62fc1d1d8e)[(0x662+7926-0x2558)]){for(i=(0xaec+3114-0x1716);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xb74+2781-0x1650);out=ssGetOutputPortSignal(S,z4e3026977c);in=(real_T*)ssGetInputPortSignal(S,z4e3026977c);if(in[(0x10c4+1666-0x1746)]>(0x2081+886-0x23f7)){do{status=za42cf7dd4a[10252];}while((status&((0x719+7165-0x2315)<<z4e3026977c))==(0x15cb+621-0x1838));}for(z26dbd73a5e=(0xf90+6-0xf96);z26dbd73a5e<(uint8_T)mxGetPr(z3d4ad966bd)[(0x7a1+3112-0x13c9)];z26dbd73a5e++){out[z26dbd73a5e]=(0x137b+2064-0x1b8b);
}for(z26dbd73a5e=(0x37f+3926-0x12d5);z26dbd73a5e<in[(0x2c7+6492-0x1c23)];z26dbd73a5e++){
za42cf7dd4a[10304+z4e3026977c]=z26dbd73a5e;
out[z26dbd73a5e+(0xa53+6573-0x23ff)]=(real_T)za42cf7dd4a[10272+z4e3026977c];}out[(0x3d9+5737-0x1a42)]=in[(0x680+355-0x7e3)];

za42cf7dd4a[10251]=((0x32+6442-0x195b)<<z4e3026977c);za42cf7dd4a[10251]=(0xeca+2175-0x1749);}}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE   
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T i;volatile uint32_T*za42cf7dd4a;uint32_T z4e3026977c,z1209c02d78,zdc0d676974,zbea4a89f24,z9e58a4ec45;za42cf7dd4a=(void*)base;z1209c02d78=(uint32_T)za42cf7dd4a[10240];zdc0d676974=(uint32_T)za42cf7dd4a[10241];zbea4a89f24=(uint32_T)za42cf7dd4a[10248];z9e58a4ec45=(uint32_T)za42cf7dd4a[10242];for(i=(0x11f3+2842-0x1d0d);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x2b5+4013-0x1261);za42cf7dd4a[10288+z4e3026977c]=(uint32_T)mxGetPr(z7039def18e)[i];za42cf7dd4a[10336+z4e3026977c]=(uint32_T)mxGetPr(zf6f668e67a)[i];za42cf7dd4a[10352+z4e3026977c]=(uint32_T)mxGetPr(zbb0d1897b2)[i];za42cf7dd4a[10368+z4e3026977c]=(uint32_T)mxGetPr(z8f7a5b7479)[i];za42cf7dd4a[10384+z4e3026977c]=(uint32_T)mxGetPr(zdc5f8981b7)[i];za42cf7dd4a[10400+z4e3026977c]=(uint32_T)mxGetPr(zc09b06e5fc)[i];z1209c02d78|=((0xd2f+6125-0x251b)<<z4e3026977c);zdc0d676974|=(((uint32_T)mxGetPr(z86af52d74e)[i])<<z4e3026977c);zbea4a89f24|=(((uint32_T)mxGetPr(z31fb671cb8)[i])<<z4e3026977c);z9e58a4ec45|=(((uint32_T)mxGetPr(zea4d7ef473)[i])<<z4e3026977c);}za42cf7dd4a[10241]=zdc0d676974;
za42cf7dd4a[10242]=z9e58a4ec45;
za42cf7dd4a[10248]=zbea4a89f24;

za42cf7dd4a[10240]=z1209c02d78;
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

