/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1b04+2696-0x258a)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_pwm_sf_v2
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
#define zdf24515981         ((0x20a6+942-0x2436))
#define z533b11d03f          ssGetSFcnParam(S, (0x3f2+2671-0xe61)) 
#define za9d8fb6bcf            ssGetSFcnParam(S, (0x932+5304-0x1de9)) 
#define zcd9b105fb7         ssGetSFcnParam(S, (0x15f1+1506-0x1bd1))
#define z51d41da523         ssGetSFcnParam(S, (0x262+3109-0xe84))
#define z6b9d58d592         ssGetSFcnParam(S, (0x130b+2525-0x1ce4))
#define z5b4c17d1ad      ssGetSFcnParam(S, (0x1e4+7993-0x2118))
#define z5a3ce9fe21     ssGetSFcnParam(S, (0xc8+4328-0x11aa))
#define z094db898c2      ssGetSFcnParam(S, (0xf1a+226-0xff5))
#define z9daff973a2     ssGetSFcnParam(S, (0x433+4752-0x16bb))
#define zc2aa337210      ssGetSFcnParam(S, (0x7ea+1848-0xf19))
#define z9e8abd8bf9       ssGetSFcnParam(S, (0x131c+289-0x1433))
#define z5337a6c14d       ssGetSFcnParam(S, (0xe3+4337-0x11c9))
#define z6dc9b50112       ssGetSFcnParam(S, (0x1e0+6057-0x197d))
#define z8c7c0fb62d       ssGetSFcnParam(S, (0xa89+6919-0x2583))
#define zd334f58c8b         ssGetSFcnParam(S, (0x1175+2403-0x1aca))
#define z19a7c92df0    ssGetSFcnParam(S, (0x1469+390-0x15e0))
#define z8108d5c236  ssGetSFcnParam(S, (0x635+320-0x765))
#define z35f3aaa676      ssGetSFcnParam(S, (0x8ca+2045-0x10b6)) 
#define z3f4d317b75       ssGetSFcnParam(S, (0xbf1+1740-0x12ab))
#define zf90722b648         ssGetSFcnParam(S, (0x949+3260-0x15f2))
#define z626dc936fa    ssGetSFcnParam(S, (0x1575+4206-0x25cf))
#define z8eefe04ef3  ssGetSFcnParam(S, (0x298+2398-0xbe1))
#define z3692ea3514      ssGetSFcnParam(S, (0x2076+1148-0x24dc))
#define z4eb7791e75      ssGetSFcnParam(S, (0x899+7572-0x2616))
#define z17ebfe798d ssGetSFcnParam(S, (0x628+38-0x636))
#define z7630eb4bf5    ssGetSFcnParam(S, (0xae8+5447-0x2016))
#define zeac6896859         ssGetSFcnParam(S, (0x977+7457-0x267e))
#define z2dceaadc0f          ssGetSFcnParam(S, (0x1d65+242-0x1e3c))
#define z3832b85a32          ssGetSFcnParam(S, (0x1a5+2564-0xb8d))
#define z702a26a5e9               ssGetSFcnParam(S, (0xceb+4733-0x1f4b))
#define z2e6483d505              ((0x28a+1849-0x9c2))
#define zc5ce4cb81a              ((0xae2+571-0xd1d))
#define z2b17e2ee3b              ((0x11fc+5114-0x25f6))
#define z6a0da049de         ((0xf24+2485-0x18d9))
#define z8e27f5c413       (720896)
static char_T zea4cd01646[(0x717+7747-0x245a)];struct z20b28b4e70{uint32_T z14406e7ff2[(0xb8a+1703-0x1211)];uint32_T z1c3ac5a807[(0x1f2+9497-0x26eb)];uint32_T zbb8903d755[(0xc0+1640-0x708)];uint32_T z35b44eb482[(0xf5c+6042-0x26d6)];uint32_T z79857c3368[(0xf28+5710-0x2556)];uint32_T z56f65088e3[(0x11e9+411-0x1364)];uint32_T z60de63c603[(0x1722+1340-0x1c3e)];uint32_T z64b63d5c98[(0x2c5+6910-0x1da3)];uint32_T protection[(0x1ccb+1419-0x2236)];uint32_T zd2088daf5f[(0x46c+2297-0xd45)];uint32_T z4da0d16710;uint32_T z99cc8c9a38;uint32_T z05cc1af873;uint32_T z2f1801d2e2;uint32_T z8a80701de3;uint32_T z7211d763fb;};static void mdlInitializeSizes(SimStruct*S){uint32_T i,za0df33019b;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x316+5402-0x1830));ssSetNumDiscStates(S,(0x1b00+302-0x1c2e));za0df33019b=(0x39+5941-0x176e);if((uint32_T)mxGetPr(zcd9b105fb7)[(0x374+1735-0xa3b)]){za0df33019b++;}if((uint32_T)mxGetPr(z6dc9b50112)[(0x91d+58-0x957)]){za0df33019b++;}if((uint32_T)mxGetPr(z9e8abd8bf9)[(0x11e0+4626-0x23f2)]){za0df33019b+=(0x7d6+5865-0x1ebd);}if((uint32_T)mxGetPr(z5337a6c14d)[(0x15c4+3959-0x253b)]){za0df33019b+=(0xb91+543-0xdae);}if((uint32_T)mxGetPr(z35f3aaa676)[(0x42a+2833-0xf3b)]){za0df33019b+=(0xc8f+1307-0x11a6);}if((uint32_T)mxGetPr(z3692ea3514)[(0x1a6f+1574-0x2095)]){za0df33019b+=(0xf5f+3513-0x1d14);}ssSetNumInputPorts(S,za0df33019b);for(i=(0xafb+2681-0x1574);i<za0df33019b;i++){ssSetInputPortWidth(S,i,(uint32_T)mxGetN(za9d8fb6bcf));ssSetInputPortDirectFeedThrough(S,i,(0xe47+4264-0x1eee));ssSetInputPortRequiredContiguous(S,i,(0x73b+6992-0x228a));}ssSetNumOutputPorts(S,(0x1293+1688-0x192b));
ssSetNumSampleTimes(S,(0x1437+2651-0x1e91));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x46d+5621-0x1a62));ssSetNumNonsampledZCs(S,(0x742+6420-0x2056));for(i=(0x3c0+2918-0xf26);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1a11+575-0x1c50));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0xb04+3872-0x1a24)]==-1.0){ssSetSampleTime(S,(0x377+2259-0xc4a),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x2379+915-0x270c),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x1634+664-0x18cc),mxGetPr(z3832b85a32)[(0x142a+1434-0x19c4)]);ssSetOffsetTime(S,(0x2df+3136-0xf1f),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i;uint8_T z16ba527520[(0xc7+1791-0x7b2)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61,z4e3026977c,z4da0d16710,z2f1801d2e2,z7211d763fb;volatile struct z20b28b4e70*zfd8911cf5a;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x16e6+1320-0x1c0e)];z6f813cde47=z05b56d9d51=(0x2707+2699-0x1abd);switch(z78caf1ba61){case(0x970+1761-0xf24):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");za4a2434e08=z182d03571c=17232;break;case(0x987+3088-0x1469):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");za4a2434e08=z182d03571c=17239;break;case(0x196b+1161-0x1cc5):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");za4a2434e08=z182d03571c=16979;break;case(0x1794+3160-0x22bc):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");za4a2434e08=z182d03571c=(0x10aa+4804-0x1e6a);break;case(0x579+6286-0x1cd0):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");za4a2434e08=z182d03571c=21069;break;case(0x180d+360-0x183d):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");za4a2434e08=z182d03571c=16971;break;case(0xaa9+7218-0x25a2):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");za4a2434e08=z182d03571c=17235;break;case(0x9b5+7269-0x24e0):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");za4a2434e08=z182d03571c=(0x2508+7954-0x2416);break;case(0x337+6533-0x1b7b):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;case(0x12e8+3260-0x1e59):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=22273;break;}if(mxGetN(z702a26a5e9)==(0x7b6+1159-0xc3c)){z366b2f03bf=(0x3cf+6708-0x1e03);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x879+2484-0x122d)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x1827+1911-0x1f9e)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x1349+2564-0x1d4c)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x1386+2468-0x1d28)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0xb71+249-0xc68)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x167b+1264-0x1b69)]);zfd8911cf5a=(volatile struct z20b28b4e70*)(zeccbadd9b3.VirtAddress[(0x627+1935-0xdb4)]+z8e27f5c413);if(!xpceIsModelInit()){z4da0d16710=zfd8911cf5a->z4da0d16710;z2f1801d2e2=(0x858+6600-0x2220);z7211d763fb=zfd8911cf5a->z7211d763fb;for(i=(0x150a+543-0x1729);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xf6d+2551-0x1963);z4da0d16710|=(0x73f+7335-0x23e5)<<z4e3026977c;zfd8911cf5a->zbb8903d755[z4e3026977c]=(uint32_T)mxGetPr(z5b4c17d1ad)[i];zfd8911cf5a->z35b44eb482[z4e3026977c]=(uint32_T)mxGetPr(z5a3ce9fe21)[i];zfd8911cf5a->z79857c3368[z4e3026977c]=(uint32_T)mxGetPr(z094db898c2)[i];zfd8911cf5a->z56f65088e3[z4e3026977c]=(uint32_T)mxGetPr(z9daff973a2)[i];zfd8911cf5a->z60de63c603[z4e3026977c]=(uint32_T)mxGetPr(zc2aa337210)[i];zfd8911cf5a->z14406e7ff2[z4e3026977c]=((uint32_T)mxGetPr(zd334f58c8b)[i])|(((uint32_T)mxGetPr(z8c7c0fb62d)[i])<<(0xe05+3894-0x1d39))|(((uint32_T)mxGetPr(z8108d5c236)[i])<<(0x274+2834-0xd82))|(((uint32_T)mxGetPr(z19a7c92df0)[i])<<(0x3dc+1989-0xb9b));zfd8911cf5a->z1c3ac5a807[z4e3026977c]=((uint32_T)mxGetPr(zf90722b648)[i])|(((uint32_T)mxGetPr(z3f4d317b75)[i])<<(0x1f5+6206-0x1a31))|(((uint32_T)mxGetPr(z8eefe04ef3)[i])<<(0x15+2584-0xa29))|(((uint32_T)mxGetPr(z626dc936fa)[i])<<(0x5f8+2051-0xdf5));zfd8911cf5a->z64b63d5c98[z4e3026977c]=(uint32_T)mxGetPr(z4eb7791e75)[i];zfd8911cf5a->protection[
z4e3026977c]=(uint32_T)mxGetPr(zeac6896859)[i];z7211d763fb|=((uint32_T)mxGetPr(z2dceaadc0f)[i])<<z4e3026977c;zfd8911cf5a->zd2088daf5f[z4e3026977c]=(uint32_T)mxGetPr(z17ebfe798d)[i];z2f1801d2e2|=(0x1c43+2003-0x2415)<<z4e3026977c;}zfd8911cf5a->z7211d763fb=z7211d763fb;zfd8911cf5a->z2f1801d2e2=z2f1801d2e2;zfd8911cf5a->z2f1801d2e2=(0x793+3795-0x1666);zfd8911cf5a->z4da0d16710=z4da0d16710;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint32_T i,z4e3026977c,z0add1d1c25,z4da0d16710,mask,doUpdate,z2f1801d2e2,ze10307c65c,zd54f8d8068;real_T zbb8903d755,z79857c3368,z60de63c603;real_T*y1,*y2,*z671e76e748,*z86101c2849;volatile struct z20b28b4e70*zfd8911cf5a=(struct z20b28b4e70*)(base+z8e27f5c413);doUpdate=(0xe2f+4458-0x1f99);for(i=(0x16e5+1432-0x1c7d);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z0add1d1c25=(0x12f7+4217-0x2370);z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x7a8+2317-0x10b4);zd54f8d8068=(0x28+6580-0x19db)<<z4e3026977c;if((uint32_T)mxGetPr(zcd9b105fb7)[(0x91d+6094-0x20eb)]){y1=(real_T*)ssGetInputPortSignal(S,z0add1d1c25);ze10307c65c|=(uint32_T)y1[i]<<z4e3026977c;z0add1d1c25+=(0xd23+3807-0x1c01);}if((uint32_T)mxGetPr(z6dc9b50112)[(0x644+3062-0x123a)]){y1=(real_T*)ssGetInputPortSignal(S,z0add1d1c25);z60de63c603=y1[i];if(z60de63c603<1.0){z60de63c603=1.0;}zfd8911cf5a->z60de63c603[z4e3026977c]=(uint32_T)z60de63c603;z0add1d1c25+=(0x1fcf+802-0x22f0);doUpdate=(0xb73+1921-0x12f3);}else{z60de63c603=(uint32_T)mxGetPr(zc2aa337210)[i];}if((uint32_T)mxGetPr(z9e8abd8bf9)[(0x167a+323-0x17bd)]){y1=(real_T*)ssGetInputPortSignal(S,z0add1d1c25);zbb8903d755=y1[i];if(zbb8903d755<1.0){zbb8903d755=1.0;}else{if(zbb8903d755>z60de63c603-1.0){zbb8903d755=z60de63c603-1.0;}}zfd8911cf5a->zbb8903d755[z4e3026977c]=(uint32_T)zbb8903d755;y1=(real_T*)ssGetInputPortSignal(S,z0add1d1c25+(0xecd+604-0x1128));zbb8903d755=y1[i];if(zbb8903d755<1.0){zbb8903d755=1.0;}else{if(zbb8903d755>z60de63c603-1.0){zbb8903d755=z60de63c603-1.0;}}zfd8911cf5a->z35b44eb482[z4e3026977c]=(uint32_T)zbb8903d755;z0add1d1c25+=(0xee2+3218-0x1b72);doUpdate=(0x15d+1934-0x8ea);
}if((uint32_T)mxGetPr(z5337a6c14d)[(0xd3+4837-0x13b8)]){y1=(real_T*)ssGetInputPortSignal(S,z0add1d1c25);z79857c3368=y1[i];if(z79857c3368<1.0){z79857c3368=1.0;}else{if(z79857c3368>z60de63c603-1.0){z79857c3368=z60de63c603-1.0;}}zfd8911cf5a->z79857c3368[z4e3026977c]=(uint32_T)z79857c3368;y1=(real_T*)ssGetInputPortSignal(S,z0add1d1c25+(0xfb6+153-0x104e));z79857c3368=y1[i];if(z79857c3368<1.0){z79857c3368=1.0;}else{if(z79857c3368>z60de63c603-1.0){z79857c3368=z60de63c603-1.0;}}zfd8911cf5a->z56f65088e3[z4e3026977c]=(uint32_T)z79857c3368;z0add1d1c25+=(0xc92+4500-0x1e24);doUpdate=(0x67+7970-0x1f88);}if((uint32_T)mxGetPr(z35f3aaa676)[(0x15f5+116-0x1669)]){y1=(real_T*)ssGetInputPortSignal(S,z0add1d1c25);
y2=(real_T*)ssGetInputPortSignal(S,z0add1d1c25+(0x1251+4353-0x2351));
z671e76e748=(real_T*)ssGetInputPortSignal(S,z0add1d1c25+(0xc77+5326-0x2143));
z86101c2849=(real_T*)ssGetInputPortSignal(S,z0add1d1c25+(0x17b3+1282-0x1cb2));
zfd8911cf5a->z14406e7ff2[z4e3026977c]=(uint32_T)y1[i]|
((uint32_T)y2[i]<<(0xc7c+3932-0x1bd6))|
((uint32_T)z671e76e748[i]<<(0x546+2870-0x1078))|
((uint32_T)z671e76e748[i]<<(0x11f8+1826-0x1914));
z0add1d1c25+=(0x12ad+2773-0x1d7e);doUpdate=(0x4d5+1417-0xa5d);}if((uint32_T)mxGetPr(z3692ea3514)[(0x16bf+525-0x18cc)]){y1=(real_T*)ssGetInputPortSignal(S,z0add1d1c25);
y2=(real_T*)ssGetInputPortSignal(S,z0add1d1c25+(0x1689+1628-0x1ce4));
z671e76e748=(real_T*)ssGetInputPortSignal(S,z0add1d1c25+(0x7ac+1430-0xd40));
z86101c2849=(real_T*)ssGetInputPortSignal(S,z0add1d1c25+(0xfa4+3385-0x1cda));
zfd8911cf5a->z1c3ac5a807[z4e3026977c]=(uint32_T)y1[i]|
((uint32_T)y2[i]<<(0x4c9+4249-0x1560))|
((uint32_T)z671e76e748[i]<<(0x121d+91-0x1274))|
((uint32_T)z671e76e748[i]<<(0x295+8724-0x24a3));
z0add1d1c25+=(0x155d+262-0x165f);doUpdate=(0xb21+3029-0x16f5);}}if((uint32_T)mxGetPr(zcd9b105fb7)[(0x426+1747-0xaf9)]){z4da0d16710=zfd8911cf5a->z4da0d16710;z4da0d16710&=~zd54f8d8068;z4da0d16710|=ze10307c65c;zfd8911cf5a->z4da0d16710=z4da0d16710;}if(doUpdate){z2f1801d2e2=(0x83b+2364-0x1177);for(i=(0x2b2+9269-0x26e7);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1964+600-0x1bbb);z2f1801d2e2|=(0xe0a+539-0x1024)<<z4e3026977c;}zfd8911cf5a->z2f1801d2e2=z2f1801d2e2;zfd8911cf5a->z2f1801d2e2=(0xde6+3788-0x1cb2);}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile struct z20b28b4e70*zfd8911cf5a=(struct z20b28b4e70*)(base+z8e27f5c413);uint32_T i,z4e3026977c,z99cc8c9a38,z05cc1af873,z8a80701de3;if(xpceIsModelInit())
{z99cc8c9a38=zfd8911cf5a->z99cc8c9a38;z05cc1af873=zfd8911cf5a->z05cc1af873;z8a80701de3=zfd8911cf5a->z8a80701de3;for(i=(0xea9+5993-0x2612);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xe5b+1854-0x1598);z8a80701de3|=((uint32_T)mxGetPr(z7630eb4bf5)[i])<<z4e3026977c;z99cc8c9a38|=((uint32_T)mxGetPr(z51d41da523)[i])<<z4e3026977c;z05cc1af873|=((uint32_T)mxGetPr(z6b9d58d592)[i])<<z4e3026977c;}zfd8911cf5a->z99cc8c9a38=z99cc8c9a38;zfd8911cf5a->z05cc1af873=z05cc1af873;zfd8911cf5a->z8a80701de3=z8a80701de3;}else
{zfd8911cf5a->z4da0d16710=(0x966+5048-0x1d1e);}
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif
