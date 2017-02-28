/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1b8b+1148-0x2005)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_spim_sf
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
#define zdf24515981              ((0x51f+8332-0x259b))
#define z533b11d03f               ssGetSFcnParam(S,  (0xf88+2032-0x1778))
#define za9d8fb6bcf                 ssGetSFcnParam(S,  (0x4+3334-0xd09))
#define zf6f668e67a         ssGetSFcnParam(S,  (0x1df+8012-0x2129))
#define zbb0d1897b2     ssGetSFcnParam(S,  (0xdf7+5015-0x218b))
#define z8f7a5b7479           ssGetSFcnParam(S,  (0x8aa+2500-0x126a))
#define zdc5f8981b7              ssGetSFcnParam(S,  (0x10c6+2979-0x1c64))
#define zc09b06e5fc             ssGetSFcnParam(S,  (0x1b25+1460-0x20d3))
#define z7039def18e              ssGetSFcnParam(S,  (0x4a2+7422-0x2199))
#define z86af52d74e                    ssGetSFcnParam(S,  (0x13c7+3146-0x2009))
#define z31fb671cb8                    ssGetSFcnParam(S,  (0x979+6759-0x23d7))
#define zea4d7ef473                ssGetSFcnParam(S, (0x1eba+910-0x223e))
#define z3d4ad966bd                   ssGetSFcnParam(S, (0x1c00+2538-0x25df))
#define z62fc1d1d8e              ssGetSFcnParam(S, (0xc8+5113-0x14b5))
#define z08a9674173        ssGetSFcnParam(S, (0x53f+1430-0xac8))
#define z3832b85a32               ssGetSFcnParam(S, (0x854+1326-0xd74))
#define z702a26a5e9                    ssGetSFcnParam(S, (0x147c+472-0x1645))
#define z2e6483d505              ((0x98f+3371-0x16b8))
#define z7e2eeaa57c          ((0x1617+3347-0x232a))
#define z6a0da049de         ((0xa04+4616-0x1c0b))
#define zc5ce4cb81a              ((0x1f30+203-0x1feb))
#define z2b17e2ee3b              ((0x22+6800-0x1ab2))
static char_T zea4cd01646[(0xf38+1232-0x1308)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x4c0+7883-0x238b));ssSetNumDiscStates(S,(0xbd7+4122-0x1bf1));if(mxGetPr(z62fc1d1d8e)[(0x1e7c+1102-0x22ca)]){ssSetNumOutputPorts(S,mxGetN(za9d8fb6bcf));for(i=(0xff4+906-0x137e);i<mxGetN(za9d8fb6bcf);i++){ssSetOutputPortWidth(S,i,(uint32_T)mxGetPr(z3d4ad966bd)[(0x7ef+7608-0x25a7)]+(0x650+1690-0xce9));}}else{ssSetNumOutputPorts(S,(0x50b+3022-0x10d9));}if(mxGetPr(z08a9674173)[(0x27c+5271-0x1713)]){ssSetNumInputPorts(S,mxGetN(za9d8fb6bcf)+(0x584+1351-0xaca));}else{ssSetNumInputPorts(S,mxGetN(za9d8fb6bcf));}for(i=(0x48a+8646-0x2650);i<mxGetN(za9d8fb6bcf);i++){ssSetInputPortWidth(S,i,(uint32_T)mxGetPr(z3d4ad966bd)[(0xb4+4909-0x13e1)]+(0x97c+6394-0x2275));ssSetInputPortDirectFeedThrough(S,i,(0x15e7+3184-0x2256));ssSetInputPortRequiredContiguous(S,i,(0x1204+1093-0x1648));}if(mxGetPr(z08a9674173)[(0x1b72+461-0x1d3f)]){ssSetInputPortWidth(S,mxGetN(za9d8fb6bcf),mxGetN(za9d8fb6bcf));ssSetInputPortDirectFeedThrough(S,mxGetN(za9d8fb6bcf),(0x10ea+4197-0x214e));ssSetInputPortRequiredContiguous(S,mxGetN(za9d8fb6bcf),(0x19fd+1420-0x1f88));}ssSetNumSampleTimes(S,(0x8b2+2568-0x12b9));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x20d+8194-0x220f));ssSetNumNonsampledZCs(S,(0x1464+1143-0x18db));for(i=(0x606+2751-0x10c5);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x18c6+1967-0x2075));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x10f+4625-0x1320)]==-1.0){ssSetSampleTime(S,(0x897+1427-0xe2a),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x830+1634-0xe92),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x1d6+937-0x57f),mxGetPr(z3832b85a32)[(0x1764+2400-0x20c4)]);ssSetOffsetTime(S,(0xaf5+6733-0x2542),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint8_T z16ba527520[(0x356+9035-0x268d)];uint16_T z6f813cde47,za4a2434e08;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x1814+256-0x1914)];switch(z78caf1ba61){case(0x107c+2662-0x19b5):strcpy(z16ba527520,"\x49\x4f\x33\x30\x31");z6f813cde47=(0x211f+5896-0x2152);za4a2434e08=17232;break;case(0x1d7+8122-0x2063):strcpy(z16ba527520,"\x49\x4f\x33\x30\x32");z6f813cde47=(0x2691+4232-0x2044);za4a2434e08=17239;break;case(0x1d7b+185-0x1d05):strcpy(z16ba527520,"\x49\x4f\x33\x30\x33");z6f813cde47=(0x1ca7+1857-0xd13);za4a2434e08=16979;break;case(0x541+3502-0x11bf):strcpy(z16ba527520,"\x49\x4f\x33\x30\x34");z6f813cde47=(0x262b+2913-0x1ab7);za4a2434e08=(0xbf7+499-0x8e6);break;case(0x74a+4204-0x167f):strcpy(z16ba527520,"\x49\x4f\x33\x31\x31");z6f813cde47=(0x1859+1557-0x799);za4a2434e08=21069;break;case(0x1e52+828-0x2056):strcpy(z16ba527520,"\x49\x4f\x33\x31\x32");z6f813cde47=(0x1d1d+2187-0xed3);za4a2434e08=16971;break;case(0x2459+118-0x2396):strcpy(z16ba527520,"\x49\x4f\x33\x31\x33");z6f813cde47=5845;za4a2434e08=17235;break;case(0x12d0+982-0x156c):strcpy(z16ba527520,"\x49\x4f\x33\x31\x34");z6f813cde47=(0x1e5f+4035-0x174d);za4a2434e08=(0x2270+3595-0x1077);break;case(0x9e3+296-0x9ca):strcpy(z16ba527520,"\x49\x4f\x33\x32\x31");z6f813cde47=(0x1e4f+6469-0x20bf);za4a2434e08=19520;break;}if((int_T)mxGetPr(z702a26a5e9)[(0x9f7+5116-0x1df3)]<(0x565+1626-0xbbf)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xf02+6059-0x26ac)){z366b2f03bf=(0xf64+2508-0x1930);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1834+497-0x1a25)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x18a0+1884-0x1ffc)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x6a0+1634-0xd01)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x7ac+25-0x6c6))|((z366b2f03bf&(0x123+9958-0x270a))<<(0x672+5729-0x1ccb)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0xa6f+3656-0x18b5)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE     
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;uint32_T z26dbd73a5e,i,width,count,z03312e422a;real_T*in,*out,*z46c2b7bc26;uint32_T z4e3026977c,status;width=(uint32_T)mxGetPr(z3d4ad966bd)[(0x13ab+1993-0x1b74)]+(0x12f8+4295-0x23be);za42cf7dd4a=(void*)base;
z03312e422a=(0x4c5+2569-0xece);for(i=(0x25e3+72-0x262b);i<mxGetN(za9d8fb6bcf);i++)
{z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1180+2435-0x1b02);in=(real_T*)ssGetInputPortSignal(S,i);count=za42cf7dd4a[10320+z4e3026977c];if(count>(0x1d59+2143-0x25b8)){sprintf(zea4cd01646,"\x54\x72\x69\x65\x64\x20\x74\x6f\x20\x77\x72\x69\x74\x65\x20\x69\x6e\x20\x61\x20\x6e\x6f\x6e\x2d\x65\x6d\x70\x74\x79\x20\x62\x75\x66\x66\x65\x72");ssSetErrorStatus(S,zea4cd01646);return;}
if(mxGetPr(z08a9674173)[(0x1964+2705-0x23f5)]){z46c2b7bc26=(real_T*)ssGetInputPortSignal(S,mxGetN(za9d8fb6bcf));za42cf7dd4a[10336+z4e3026977c]=(uint32_T)z46c2b7bc26[i];}count=(uint32_T)in[(0xcf5+2680-0x176d)];for(z26dbd73a5e=(0x14cd+2023-0x1cb4);z26dbd73a5e<count;z26dbd73a5e++)
{
za42cf7dd4a[10256+z4e3026977c]=(uint32_T)in[z26dbd73a5e+(0x5e0+6819-0x2082)];
za42cf7dd4a[10304+z4e3026977c]=z26dbd73a5e;
za42cf7dd4a[10250]=((0xe18+2155-0x1682)<<z4e3026977c);za42cf7dd4a[10250]=(0xd76+3960-0x1cee);}
za42cf7dd4a[10320+z4e3026977c]=count;
za42cf7dd4a[10249]=((0xf18+1986-0x16d9)<<z4e3026977c);za42cf7dd4a[10249]=(0x1931+453-0x1af6);}
if(mxGetPr(z62fc1d1d8e)[(0x293+4783-0x1542)]){for(i=(0x51b+3905-0x145c);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x179+8129-0x2139);out=ssGetOutputPortSignal(S,i);in=(real_T*)ssGetInputPortSignal(S,i);if(in[(0x19a6+3055-0x2595)]>(0x15a2+3388-0x22de)){do{status=za42cf7dd4a[10252];
}while((status&((0x87f+3536-0x164e)<<z4e3026977c))==(0x1cfa+1766-0x23e0));}for(z26dbd73a5e=(0x103b+344-0x1193);z26dbd73a5e<(uint8_T)mxGetPr(z3d4ad966bd)[(0x197+8357-0x223c)];z26dbd73a5e++){out[z26dbd73a5e]=(0x1547+832-0x1887);
}for(z26dbd73a5e=(0xd24+2690-0x17a6);z26dbd73a5e<in[(0x3aa+2140-0xc06)];z26dbd73a5e++){
za42cf7dd4a[10304+z4e3026977c]=z26dbd73a5e;
out[z26dbd73a5e+(0xd97+6436-0x26ba)]=(real_T)za42cf7dd4a[10272+z4e3026977c];}out[(0x625+3866-0x153f)]=in[(0x4a3+1756-0xb7f)];

za42cf7dd4a[10251]=((0x306+7330-0x1fa7)<<z4e3026977c);za42cf7dd4a[10251]=(0xb00+5787-0x219b);}}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE   
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T i;volatile uint32_T*za42cf7dd4a;uint32_T z4e3026977c,z1209c02d78,zdc0d676974,zbea4a89f24,z9e58a4ec45;za42cf7dd4a=(void*)base;z1209c02d78=(uint32_T)za42cf7dd4a[10240];zdc0d676974=(uint32_T)za42cf7dd4a[10241];zbea4a89f24=(uint32_T)za42cf7dd4a[10248];z9e58a4ec45=(uint32_T)za42cf7dd4a[10242];for(i=(0x772+3703-0x15e9);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x8ac+5314-0x1d6d);za42cf7dd4a[10288+z4e3026977c]=(uint32_T)mxGetPr(z7039def18e)[i];za42cf7dd4a[10336+z4e3026977c]=(uint32_T)mxGetPr(zf6f668e67a)[i];za42cf7dd4a[10352+z4e3026977c]=(uint32_T)mxGetPr(zbb0d1897b2)[i];za42cf7dd4a[10368+z4e3026977c]=(uint32_T)mxGetPr(z8f7a5b7479)[i];za42cf7dd4a[10384+z4e3026977c]=(uint32_T)mxGetPr(zdc5f8981b7)[i];za42cf7dd4a[10400+z4e3026977c]=(uint32_T)mxGetPr(zc09b06e5fc)[i];z1209c02d78|=((0x119f+1129-0x1607)<<z4e3026977c);zdc0d676974|=(((uint32_T)mxGetPr(z86af52d74e)[i])<<z4e3026977c);zbea4a89f24|=(((uint32_T)mxGetPr(z31fb671cb8)[i])<<z4e3026977c);z9e58a4ec45|=(((uint32_T)mxGetPr(zea4d7ef473)[i])<<z4e3026977c);}za42cf7dd4a[10241]=zdc0d676974;
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

