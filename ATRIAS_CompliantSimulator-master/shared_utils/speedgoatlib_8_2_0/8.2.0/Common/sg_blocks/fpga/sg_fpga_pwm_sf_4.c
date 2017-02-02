/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1af0+3099-0x2709)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_pwm_sf_4
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
#define zdf24515981        ((0x7c9+807-0xad9))
#define z533b11d03f         ssGetSFcnParam(S,  (0xbf6+6016-0x2376)) 
#define za9d8fb6bcf           ssGetSFcnParam(S,  (0x81a+4420-0x195d)) 
#define z01bb085356         ssGetSFcnParam(S,  (0x36f+2889-0xeb6))
#define z8e1815e073             ssGetSFcnParam(S,  (0x8a6+2829-0x13b0))
#define zbfd84bbef9             ssGetSFcnParam(S,  (0x119+4401-0x1246))
#define z8944e1fed9             ssGetSFcnParam(S,  (0x4c0+7449-0x21d4))
#define zc74c85e681           ssGetSFcnParam(S,  (0x1058+2737-0x1b03))
#define z311fbc5bad           ssGetSFcnParam(S,  (0x39c+4237-0x1422))
#define za04af20061           ssGetSFcnParam(S,  (0xc86+781-0xf8b))
#define za9b36fc92d            ssGetSFcnParam(S,  (0x9f5+3749-0x1891))
#define z2d3e9570ac           ssGetSFcnParam(S, (0x1912+458-0x1ad2))
#define z1240a5c516          ssGetSFcnParam(S, (0xcf0+1517-0x12d2))
#define z718df4ebba           ssGetSFcnParam(S, (0x3c+3246-0xcde))
#define zf303968f76          ssGetSFcnParam(S, (0x1af+6504-0x1b0a))
#define z6c8b14d68e           ssGetSFcnParam(S, (0x2096+1464-0x2640))
#define zc36a3da4ad          ssGetSFcnParam(S, (0x2f6+2917-0xe4c))
#define zeac6896859        ssGetSFcnParam(S, (0x74c+6169-0x1f55))
#define z2dceaadc0f         ssGetSFcnParam(S, (0x1226+74-0x125f))
#define z502d9ed0cf             ssGetSFcnParam(S, (0x297+4536-0x143d))
#define z1918c3f4db             ssGetSFcnParam(S, (0xd24+3576-0x1b09))
#define zc6c46560aa             ssGetSFcnParam(S, (0x440+5064-0x17f4))
#define z3832b85a32         ssGetSFcnParam(S, (0xe24+2546-0x1801))
#define z702a26a5e9              ssGetSFcnParam(S, (0x340+9083-0x26a5))
#define z2e6483d505              ((0x494+7018-0x1ffd))
#define zc5ce4cb81a              ((0xe41+3718-0x1cc7))
#define z2b17e2ee3b              ((0x7cc+5553-0x1d7d))
#define z6a0da049de         ((0x1e2+6709-0x1c17))
#define z0f9ded0223              (655360)
static char_T zea4cd01646[(0xd50+1176-0x10e8)];typedef struct{uint32_T z4da0d16710;uint32_T z2f1801d2e2;uint32_T z8db8bb5a06;uint32_T zee8378496a;uint32_T z37cfa98aaf;uint32_T ze7198b4532;uint32_T zba6c56af50;uint32_T z727d169ad5;uint32_T zf30711d604[(0xb06+3099-0x1701)];uint32_T z6756646a81[(0x11b8+3536-0x1f68)];uint32_T z9ca0045836[(0x1360+4931-0x2683)];uint32_T z8e8b32e98e[(0x90f+6756-0x2353)];uint32_T z886a62b902[(0x5d+1064-0x465)];uint32_T z56a6f5a2f5[(0xdc3+6029-0x2530)];uint32_T z26ba860554[(0xb34+4807-0x1ddb)];uint32_T protection[(0x2338+165-0x23bd)];uint32_T z7211d763fb[(0x1437+1321-0x1940)];}z8dc61d99bb;static void mdlInitializeSizes(SimStruct*S){uint32_T i,zbc7ebd0e53,width;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x41+8882-0x22f3));ssSetNumDiscStates(S,(0x1a8c+1630-0x20ea));width=(uint32_T)mxGetN(za9d8fb6bcf);zbc7ebd0e53=(0x1b5c+1864-0x22a4);if((uint32_T)mxGetPr(z01bb085356)[(0x42c+411-0x5c7)]==(0xdbf+5446-0x2304)){if((uint32_T)mxGetPr(z8e1815e073)[(0x151f+1820-0x1c3b)]){zbc7ebd0e53+=(0x76b+2819-0x126d);}if((uint32_T)mxGetPr(zbfd84bbef9)[(0x95a+6711-0x2391)]){zbc7ebd0e53+=(0xc6b+663-0xf01);}}else{if((uint32_T)mxGetPr(z8e1815e073)[(0xb7c+4039-0x1b43)]){zbc7ebd0e53+=(0x7f8+4731-0x1a71);}if((uint32_T)mxGetPr(zbfd84bbef9)[(0xced+229-0xdd2)]){zbc7ebd0e53+=(0x2411+639-0x268e);}}if((uint32_T)mxGetPr(z8944e1fed9)[(0x1894+2693-0x2319)]){zbc7ebd0e53+=(0x150f+4063-0x24ec);}ssSetNumInputPorts(S,zbc7ebd0e53);
for(i=(0xc1f+1243-0x10fa);i<zbc7ebd0e53;i++){ssSetInputPortWidth(S,i,width);ssSetInputPortDirectFeedThrough(S,i,(0x1bf1+288-0x1d10));ssSetInputPortRequiredContiguous(S,i,(0x881+1908-0xff4));}ssSetNumOutputPorts(S,(0x1c24+1877-0x2379));ssSetNumSampleTimes(S,(0xb75+3900-0x1ab0));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x273+1449-0x81c));ssSetNumNonsampledZCs(S,(0x702+2045-0xeff));for(i=(0x1f5a+568-0x2192);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xda+2019-0x8bd));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x1da3+2310-0x26a9)]==-1.0){ssSetSampleTime(S,(0x7df+705-0xaa0),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x106b+3064-0x1c63),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xb58+2689-0x15d9),mxGetPr(z3832b85a32)[(0x8ba+2354-0x11ec)]);ssSetOffsetTime(S,(0x15b0+3227-0x224b),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i,z4e3026977c,z4da0d16710;volatile z8dc61d99bb*z9e95a8730f;uint8_T z16ba527520[(0x1de9+1068-0x2201)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x1bc9+564-0x1dfd)];z6f813cde47=z05b56d9d51=(0x1921+7728-0x207c);switch(z78caf1ba61){case(0xd0c+6904-0x26d7):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");za4a2434e08=z182d03571c=17232;break;case(0xcaa+3386-0x18b6):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");za4a2434e08=z182d03571c=17239;break;case(0x1a0f+159-0x197f):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");za4a2434e08=z182d03571c=16979;break;case(0x6e5+2581-0xfca):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");za4a2434e08=z182d03571c=(0x951+4819-0x1720);break;case(0x12e9+4229-0x2237):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");za4a2434e08=z182d03571c=21069;break;case(0x1b58+1445-0x1fc5):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");za4a2434e08=z182d03571c=16971;break;case(0x837+7671-0x24f5):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");za4a2434e08=z182d03571c=17235;break;case(0x547+3838-0x130b):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");za4a2434e08=z182d03571c=8196;break;case(0xe0d+3541-0x1aa1):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;case(0xa58+7294-0x258b):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;break;default:sprintf(zea4cd01646,"\x62\x6f\x61\x72\x64\x20\x74\x79\x70\x65\x20\x69\x6e\x63\x6f\x72\x72\x65\x63\x74\x2e");ssSetErrorStatus(S,zea4cd01646);return;}if(mxGetN(z702a26a5e9)==(0x1554+4300-0x261f)){z366b2f03bf=(0x17c2+1208-0x1c7a);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x203+4081-0x11f4)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x957+1056-0xd77)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x2122+512-0x2321)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x1339+1904-0x1aa7)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x36f+7127-0x1f44)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x135f+4105-0x2366)]);z9e95a8730f=(z8dc61d99bb*)(zeccbadd9b3.VirtAddress[(0xfec+4853-0x22df)]+z0f9ded0223);if(!xpceIsModelInit()){z4da0d16710=z9e95a8730f->z4da0d16710;for(i=(0x77a+3639-0x15b1);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x301+3647-0x113f);z4da0d16710|=((0x36f+4913-0x169f)<<z4e3026977c);}z9e95a8730f->z4da0d16710=z4da0d16710;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base,i,z4e3026977c,z6756646a81,z9ca0045836,z8e8b32e98e,z886a62b902,z56a6f5a2f5,z26ba860554,z2f1801d2e2,z397487b191;uint32_T z1c41364797;volatile z8dc61d99bb*z9e95a8730f;real_T*in;base=ssGetIWorkValue(S,z6a0da049de);z9e95a8730f=(z8dc61d99bb*)(base+z0f9ded0223);z2f1801d2e2=(0xa65+1806-0x1173);z397487b191=(0xcef+6375-0x25d6);
for(i=(0x1293+4457-0x23fc);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z1c41364797=(0x206+6736-0x1c56);z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1429+3500-0x21d4);z2f1801d2e2|=((0xe7d+2706-0x190e)<<z4e3026977c);if((uint32_T)mxGetPr(z01bb085356)[(0x2ff+1986-0xac1)]==(0x10a3+5039-0x2451)){
if((uint32_T)mxGetPr(z8e1815e073)[(0x10b3+4189-0x2110)]){in=(real_T*)ssGetInputPortSignal(S,z1c41364797);z6756646a81=(uint32_T)in[i];z9e95a8730f->z6756646a81[z4e3026977c]=z6756646a81;z9e95a8730f->z9ca0045836[z4e3026977c]=(uint32_T)mxGetPr(za9b36fc92d)[z4e3026977c]-z6756646a81;z1c41364797++;z397487b191=(0x789+4549-0x194d);}if((uint32_T)mxGetPr(zbfd84bbef9)[(0x1404+4745-0x268d)]){in=(real_T*)ssGetInputPortSignal(S,z1c41364797);z8e8b32e98e=(uint32_T)in[i];z9e95a8730f->z8e8b32e98e[z4e3026977c]=z6756646a81;z9e95a8730f->z886a62b902[z4e3026977c]=(uint32_T)mxGetPr(za9b36fc92d)[z4e3026977c]-z8e8b32e98e;z1c41364797++;z397487b191=(0x1503+480-0x16e2);}}else{
if((uint32_T)mxGetPr(z8e1815e073)[(0x1314+720-0x15e4)]){in=(real_T*)ssGetInputPortSignal(S,z1c41364797);z6756646a81=(uint32_T)in[i];z9e95a8730f->z6756646a81[z4e3026977c]=z6756646a81;z1c41364797++;in=(real_T*)ssGetInputPortSignal(S,z1c41364797);z9ca0045836=(uint32_T)in[i];z9e95a8730f->z9ca0045836[z4e3026977c]=z9ca0045836;z1c41364797++;z397487b191=(0x7e0+2133-0x1034);}if((uint32_T)mxGetPr(zbfd84bbef9)[(0x9a8+4646-0x1bce)]){in=(real_T*)ssGetInputPortSignal(S,z1c41364797);z8e8b32e98e=(uint32_T)in[i];z9e95a8730f->z8e8b32e98e[z4e3026977c]=z8e8b32e98e;z1c41364797++;in=(real_T*)ssGetInputPortSignal(S,z1c41364797);z886a62b902=(uint32_T)in[i];z9e95a8730f->z886a62b902[z4e3026977c]=z886a62b902;z1c41364797++;z397487b191=(0x263+879-0x5d1);}}
if((uint32_T)mxGetPr(z8944e1fed9)[(0x1598+1007-0x1987)]){in=(real_T*)ssGetInputPortSignal(S,z1c41364797);z56a6f5a2f5=(uint32_T)in[i];z9e95a8730f->z56a6f5a2f5[z4e3026977c]=z56a6f5a2f5;z1c41364797++;in=(real_T*)ssGetInputPortSignal(S,z1c41364797);z26ba860554=(uint32_T)in[i];z9e95a8730f->z26ba860554[z4e3026977c]=z26ba860554;z1c41364797++;z397487b191=(0xd3f+3321-0x1a37);}}
if(z397487b191){z9e95a8730f->z2f1801d2e2=z2f1801d2e2;z9e95a8730f->z2f1801d2e2=(0x1059+5372-0x2555);}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE   
uint32_T base,i,z4e3026977c;uint32_T z2f1801d2e2,z8db8bb5a06,zee8378496a,z37cfa98aaf,ze7198b4532,zba6c56af50,z727d169ad5;volatile z8dc61d99bb*z9e95a8730f;base=ssGetIWorkValue(S,z6a0da049de);z9e95a8730f=(z8dc61d99bb*)(base+z0f9ded0223);if(xpceIsModelInit()){
z8db8bb5a06=z9e95a8730f->z8db8bb5a06;zee8378496a=z9e95a8730f->zee8378496a;z37cfa98aaf=z9e95a8730f->z37cfa98aaf;ze7198b4532=z9e95a8730f->ze7198b4532;zba6c56af50=z9e95a8730f->zba6c56af50;z727d169ad5=z9e95a8730f->z727d169ad5;z2f1801d2e2=(0x3fb+1717-0xab0);for(i=(0xb02+3389-0x183f);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x22+2104-0x859);if((uint32_T)mxGetPr(zc74c85e681)[i]==(0x934+820-0xc66)){z8db8bb5a06|=((0x1337+4496-0x24c6)<<z4e3026977c);}else{z8db8bb5a06&=~((0xd7a+1274-0x1273)<<z4e3026977c);}if((uint32_T)mxGetPr(z311fbc5bad)[i]==(0x1439+558-0x1665)){zee8378496a|=((0xdab+3420-0x1b06)<<z4e3026977c);}else{zee8378496a&=~((0xf80+2447-0x190e)<<z4e3026977c);}if((uint32_T)mxGetPr(za04af20061)[i]==(0x8d9+3-0x8da)){z37cfa98aaf|=((0x1bd1+2160-0x2440)<<z4e3026977c);}else{z37cfa98aaf&=~((0x238+1604-0x87b)<<z4e3026977c);}if((uint32_T)mxGetPr(z502d9ed0cf)[i]==(0x4ec+714-0x7b4)){ze7198b4532|=((0xc1a+4975-0x1f88)<<z4e3026977c);}else{ze7198b4532&=~((0x1f26+182-0x1fdb)<<z4e3026977c);}if((uint32_T)mxGetPr(z1918c3f4db)[i]==(0xf91+5635-0x2592)){zba6c56af50|=((0x42+562-0x273)<<z4e3026977c);}else{zba6c56af50&=~((0x2e8+6846-0x1da5)<<z4e3026977c);}if((uint32_T)mxGetPr(zc6c46560aa)[i]==(0x1cea+440-0x1ea0)){z727d169ad5|=((0x126c+4291-0x232e)<<z4e3026977c);}else{z727d169ad5&=~((0x114a+5357-0x2636)<<z4e3026977c);}z9e95a8730f->zf30711d604[z4e3026977c]=(uint32_T)mxGetPr(za9b36fc92d)[i];z9e95a8730f->z6756646a81[z4e3026977c]=(uint32_T)mxGetPr(z2d3e9570ac)[i];z9e95a8730f->z9ca0045836[z4e3026977c]=(uint32_T)mxGetPr(z1240a5c516)[i];z9e95a8730f->z8e8b32e98e[z4e3026977c]=(uint32_T)mxGetPr(z718df4ebba)[i];z9e95a8730f->z886a62b902[z4e3026977c]=(uint32_T)mxGetPr(zf303968f76)[i];z9e95a8730f->z56a6f5a2f5[z4e3026977c]=(uint32_T)mxGetPr(z6c8b14d68e)[i];z9e95a8730f->z26ba860554[z4e3026977c]=(uint32_T)mxGetPr(zc36a3da4ad)[i];z9e95a8730f->protection[z4e3026977c]=(uint32_T)mxGetPr(zeac6896859)[i]-(0x326+1262-0x813);z9e95a8730f->z7211d763fb[z4e3026977c]=(uint32_T)mxGetPr(z2dceaadc0f)[i]-(0x96a+5700-0x1fad);z2f1801d2e2|=((0x5e1+3916-0x152c)<<z4e3026977c);}z9e95a8730f->ze7198b4532=ze7198b4532;z9e95a8730f->zba6c56af50=zba6c56af50;z9e95a8730f->z727d169ad5=z727d169ad5;z9e95a8730f->z8db8bb5a06=z8db8bb5a06;z9e95a8730f->zee8378496a=zee8378496a;z9e95a8730f->z37cfa98aaf=z37cfa98aaf;z9e95a8730f->z2f1801d2e2=z2f1801d2e2;z9e95a8730f->z2f1801d2e2=(0xdc1+789-0x10d6);z9e95a8730f->z4da0d16710=(0x736+5894-0x1e3c);}else{z9e95a8730f->z4da0d16710=(0x1aa+5539-0x174d);}
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif
