/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1c5+8534-0x2319)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_qae_sf_a1
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
#define z3d31aba69b
#define zdf24515981        ((0x879+1601-0xeae))
#define z533b11d03f         ssGetSFcnParam(S,(0xdef+4732-0x206b)) 
#define za9d8fb6bcf           ssGetSFcnParam(S,(0x14b4+4558-0x2681)) 
#define z503e6ced0f    ssGetSFcnParam(S,(0x12ed+281-0x1404)) 
#define zf0a85064b6     ssGetSFcnParam(S,(0x2656+76-0x269f)) 
#define ze4d3b8eb95        ssGetSFcnParam(S,(0x8e3+7039-0x245e)) 
#define zb59583bf39         ssGetSFcnParam(S,(0x775+7433-0x2479)) 
#define zc8bbaa6115             ssGetSFcnParam(S,(0x93c+6760-0x239e)) 
#define z290889a43b      ssGetSFcnParam(S,(0x401+3100-0x1016)) 
#define z13bb501290         ssGetSFcnParam(S,(0x22cf+27-0x22e2)) 
#define z19087bd486        ssGetSFcnParam(S,(0x1079+4327-0x2157))
#define z3832b85a32         ssGetSFcnParam(S,(0x837+2924-0x1399))
#define z702a26a5e9              ssGetSFcnParam(S,(0x32f+7922-0x2216))
#define z2e6483d505              ((0x1594+1710-0x1c41))
#define zc5ce4cb81a              ((0x902+455-0xac8))
#define z2b17e2ee3b              ((0x28c+6072-0x1a44))
#define z6a0da049de         ((0x3d3+8996-0x26f7))
#define z5ae2c8ee5e         ((0x23b1+790-0x26c7))    
#define z5228c492cb                 (196608)
static char_T zea4cd01646[(0xabd+393-0xb46)];struct z89df2198fb{uint32_T z3fd72505ec;uint32_T z4da0d16710;uint32_T z2f1801d2e2;int32_T z8ccca10206[(0x1467+1199-0x18f6)];int32_T z141ebdb094[(0x1903+1541-0x1ee8)];uint32_T z090cd67c73[(0x188b+3307-0x2556)];uint32_T z6695674542[(0x1374+1582-0x1982)];uint32_T z1b3a4657a7[(0x708+328-0x830)];uint32_T z32b35fb51b[(0x35+3421-0xd72)];uint32_T zcb34517c3c[(0x415+3813-0x12da)];uint32_T z1c9de180ec[(0x25a+4570-0x1414)];};static void mdlInitializeSizes(SimStruct*S){uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xf58+4476-0x20d4));ssSetNumDiscStates(S,(0x992+451-0xb55));if(mxGetPr(zf0a85064b6)[(0xea1+6003-0x2614)]){if(mxGetPr(ze4d3b8eb95)[(0x7b2+3766-0x1668)]){ssSetNumInputPorts(S,(0x168c+1354-0x1bd4));ssSetInputPortWidth(S,(0x25f+4855-0x1556),mxGetN(za9d8fb6bcf));ssSetInputPortDirectFeedThrough(S,(0x105a+2200-0x18f2),(0x179f+2022-0x1f84));ssSetInputPortRequiredContiguous(S,(0x122c+323-0x136f),(0x126d+848-0x15bc));ssSetInputPortWidth(S,(0x4b5+8346-0x254e),mxGetN(za9d8fb6bcf));ssSetInputPortDirectFeedThrough(S,(0x10a1+5017-0x2439),(0x182+9089-0x2502));ssSetInputPortRequiredContiguous(S,(0xbc5+1625-0x121d),(0xfe0+780-0x12eb));}else{ssSetNumInputPorts(S,(0x114c+3193-0x1dc4));ssSetInputPortWidth(S,(0xfeb+1920-0x176b),mxGetN(za9d8fb6bcf));ssSetInputPortDirectFeedThrough(S,(0xc8d+3917-0x1bda),(0x98+7181-0x1ca4));ssSetInputPortRequiredContiguous(S,(0x174+2174-0x9f2),(0x4dd+746-0x7c6));}}else{if(mxGetPr(ze4d3b8eb95)[(0x1c04+2099-0x2437)]){ssSetNumInputPorts(S,(0xe9a+731-0x1174));ssSetInputPortWidth(S,(0x10f7+1216-0x15b7),mxGetN(za9d8fb6bcf));ssSetInputPortDirectFeedThrough(S,(0x150b+1856-0x1c4b),(0x1ebb+916-0x224e));ssSetInputPortRequiredContiguous(S,(0x945+7188-0x2559),(0xac0+7196-0x26db));}else{ssSetNumInputPorts(S,(0xd7f+526-0xf8d));}}if(mxGetPr(z503e6ced0f)[(0x4d+5155-0x1470)]){ssSetNumOutputPorts(S,(0xc44+358-0xda9));ssSetOutputPortWidth(S,(0x1321+3311-0x2010),mxGetN(za9d8fb6bcf));}else{ssSetNumOutputPorts(S,(0x68c+813-0x9b9));}ssSetNumSampleTimes(S,(0x20e3+1290-0x25ec));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x5dc+1500-0xbb8));ssSetNumNonsampledZCs(S,(0x7dc+2803-0x12cf));for(i=(0x85d+245-0x952);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x56b+3536-0x133b));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0xa2+9549-0x25ef)]==-1.0){ssSetSampleTime(S,(0x726+3067-0x1321),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x182+4716-0x13ee),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x1103+5135-0x2512),mxGetPr(z3832b85a32)[(0x129+6796-0x1bb5)]);ssSetOffsetTime(S,(0x4a4+6535-0x1e2b),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i,z26dbd73a5e;int64_T delta;uint64_T position;real_T z32b35fb51b;uint8_T z16ba527520[(0xbb4+5692-0x21dc)];real_T z5ec2b7da0a=(0x14b2+557-0x16df);uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61,z4e3026977c,z4da0d16710,z2f1801d2e2;volatile struct z89df2198fb*z57bf1945ef;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x147d+1592-0x1ab5)];z6f813cde47=z05b56d9d51=(0x22a6+1453-0x117e);switch(z78caf1ba61){case(0x1ffd+928-0x2252):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;z5ec2b7da0a=75000000.0;break;default:sprintf(zea4cd01646,"\x62\x6f\x61\x72\x64\x20\x74\x79\x70\x65\x20\x69\x6e\x63\x6f\x72\x72\x65\x63\x74\x2e");ssSetErrorStatus(S,zea4cd01646);return;}ssSetRWorkValue(S,z5ae2c8ee5e,z5ec2b7da0a);if(mxGetN(z702a26a5e9)==(0x9fc+3293-0x16d8)){z366b2f03bf=(0xa82+4157-0x1abf);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xc0b+6622-0x25e9)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x2049+4-0x204d)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x83a+440-0x9f1)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0xc4d+6769-0x26bc)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x73b+6300-0x1fd5)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x218d+1216-0x264b)]);z57bf1945ef=(struct z89df2198fb*)(zeccbadd9b3.VirtAddress[(0x1009+361-0x1170)]+z5228c492cb);if(!xpceIsModelInit()){if((uint32_T)mxGetPr(zc8bbaa6115)[(0xe10+5241-0x2289)]){z2f1801d2e2=(0x42f+7329-0x20d0);for(i=(0x798+3640-0x15d0);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xbaf+2754-0x1670);z2f1801d2e2|=((0x170b+2572-0x2116)<<z4e3026977c);delta=(int64_T)(18446744073709551616.0/60.0*((real_T)mxGetPr(z13bb501290)[z4e3026977c]/z5ec2b7da0a));
z57bf1945ef->z8ccca10206[z4e3026977c]=(int32_T)((delta>>(0x1d6+5618-0x17a8))&4294967295);z57bf1945ef->z141ebdb094[z4e3026977c]=(int32_T)((delta)&4294967295);z57bf1945ef->z2f1801d2e2=((0xae4+638-0xd61)<<z4e3026977c);z57bf1945ef->z2f1801d2e2=(0xbab+341-0xd00);z32b35fb51b=1.0;for(z26dbd73a5e=(0xdfd+3515-0x1bb8);z26dbd73a5e<(uint32_T)(mxGetPr(z19087bd486)[z4e3026977c]);z26dbd73a5e++){z32b35fb51b*=2.0;}position=(uint64_T)((18446744073709551616.0/z32b35fb51b)*(real_T)mxGetPr(z290889a43b)[z4e3026977c]);z57bf1945ef->z090cd67c73[z4e3026977c]=(uint32_T)((position>>(0x1890+3010-0x2432))&4294967295);z57bf1945ef->z6695674542[z4e3026977c]=(uint32_T)((position)&4294967295);z57bf1945ef->z2f1801d2e2=((0xa45+4704-0x1ca4)<<z4e3026977c);z57bf1945ef->z2f1801d2e2=(0x1650+1900-0x1dbc);z57bf1945ef->z1b3a4657a7[z4e3026977c]=(0x12a8+4494-0x2435);z57bf1945ef->z1b3a4657a7[z4e3026977c]=(0x4f7+2891-0x1042);
position+=(uint64_T)(18446744073709551616.0/z32b35fb51b/2.0);
z57bf1945ef->z090cd67c73[z4e3026977c]=(uint32_T)((position>>(0xd9+9388-0x2565))&4294967295);;z57bf1945ef->z6695674542[z4e3026977c]=(uint32_T)((position)&4294967295);z57bf1945ef->z2f1801d2e2=((0xd6f+4086-0x1d64)<<z4e3026977c);z57bf1945ef->z2f1801d2e2=(0x7ac+2315-0x10b7);z57bf1945ef->z1b3a4657a7[z4e3026977c]=(0x8a8+6359-0x217d);z57bf1945ef->z1b3a4657a7[z4e3026977c]=(0xb30+3115-0x175b);}}z4da0d16710=(0x1611+299-0x173c);for(i=(0x1048+3114-0x1c72);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x90a+5633-0x1f0a);z4da0d16710|=((0x19e9+3156-0x263c)<<z4e3026977c);}z57bf1945ef->z4da0d16710=z4da0d16710;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint32_T i,z4e3026977c;int64_T delta;real_T*y1,*y2;real_T*out;real_T z5ec2b7da0a=ssGetRWorkValue(S,z5ae2c8ee5e);volatile struct z89df2198fb*z57bf1945ef=(struct z89df2198fb*)(base+z5228c492cb);if(mxGetPr(z503e6ced0f)[(0x2cf+7395-0x1fb2)]){out=(real_T*)ssGetOutputPortSignal(S,(0xd89+2754-0x184b));for(i=(0xedc+937-0x1285);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xb2a+4294-0x1bef);out[i]=(real_T)z57bf1945ef->z1c9de180ec[z4e3026977c];}}if(mxGetPr(zf0a85064b6)[(0x595+3443-0x1308)]){if(mxGetPr(ze4d3b8eb95)[(0xd38+3965-0x1cb5)]){for(i=(0xe95+6137-0x268e);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x6c6+3307-0x13b0);y1=(real_T*)ssGetInputPortSignal(S,(0x1422+4835-0x2705));y2=(real_T*)ssGetInputPortSignal(S,(0x2eb+1592-0x922));z57bf1945ef->zcb34517c3c[z4e3026977c]=(uint32_T)y1[i];delta=(int64_T)(18446744073709551616.0/60.0*((real_T)y2[z4e3026977c]/z5ec2b7da0a));
z57bf1945ef->z8ccca10206[z4e3026977c]=(int32_T)((delta>>(0x4bc+1432-0xa34))&4294967295);z57bf1945ef->z141ebdb094[z4e3026977c]=(int32_T)((delta)&4294967295);z57bf1945ef->z2f1801d2e2=((0x359+6611-0x1d2b)<<z4e3026977c);z57bf1945ef->z2f1801d2e2=(0xc1d+2466-0x15bf);}}else{y1=(real_T*)ssGetInputPortSignal(S,(0xc0c+3054-0x17fa));for(i=(0x2bb+1956-0xa5f);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1157+3004-0x1d12);z57bf1945ef->zcb34517c3c[z4e3026977c]=(uint32_T)y1[i];}}}else{if(mxGetPr(ze4d3b8eb95)[(0x116b+2592-0x1b8b)]){y1=(real_T*)ssGetInputPortSignal(S,(0xf09+4296-0x1fd1));for(i=(0x8e1+5706-0x1f2b);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xbe1+80-0xc30);delta=(int64_T)(18446744073709551616.0/60.0*((real_T)y1[z4e3026977c]/z5ec2b7da0a));
z57bf1945ef->z8ccca10206[z4e3026977c]=(int32_T)((delta>>(0x7e7+7968-0x26e7))&4294967295);z57bf1945ef->z141ebdb094[z4e3026977c]=(int32_T)((delta)&4294967295);z57bf1945ef->z2f1801d2e2=((0xacf+5818-0x2188)<<z4e3026977c);z57bf1945ef->z2f1801d2e2=(0x512+2055-0xd19);}}}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint32_T i,z26dbd73a5e;uint32_T z4e3026977c;int64_T delta;uint64_T position;real_T z32b35fb51b;real_T z5ec2b7da0a=ssGetRWorkValue(S,z5ae2c8ee5e);volatile struct z89df2198fb*z57bf1945ef=(struct z89df2198fb*)(base+z5228c492cb);if(xpceIsModelInit())
{z57bf1945ef->z3fd72505ec=((uint32_T)mxGetPr(zb59583bf39)[(0x718+7134-0x22f6)]);for(i=(0x204a+1620-0x269e);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xa10+2069-0x1224);
z57bf1945ef->z32b35fb51b[z4e3026977c]=(uint32_T)mxGetPr(z19087bd486)[i]-(0xdef+2738-0x18a0);}for(i=(0x418+944-0x7c8);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1b2+1537-0x7b2);delta=(int64_T)(18446744073709551616.0/60.0*((real_T)mxGetPr(z13bb501290)[z4e3026977c]/z5ec2b7da0a));
z57bf1945ef->z8ccca10206[z4e3026977c]=(int32_T)((delta>>(0x152f+4349-0x260c))&4294967295);z57bf1945ef->z141ebdb094[z4e3026977c]=(int32_T)((delta)&4294967295);z57bf1945ef->z2f1801d2e2=((0x11a6+2181-0x1a2a)<<z4e3026977c);z57bf1945ef->z2f1801d2e2=(0xdf9+3259-0x1ab4);z32b35fb51b=1.0;for(z26dbd73a5e=(0x14a5+3905-0x23e6);z26dbd73a5e<(uint32_T)(mxGetPr(z19087bd486)[z4e3026977c]);z26dbd73a5e++){z32b35fb51b*=2.0;}position=(uint64_T)((18446744073709551616.0/z32b35fb51b)*(real_T)mxGetPr(z290889a43b)[z4e3026977c]);z57bf1945ef->z090cd67c73[z4e3026977c]=(uint32_T)((position>>(0x3c0+7805-0x221d))&4294967295);z57bf1945ef->z6695674542[z4e3026977c]=(uint32_T)((position)&4294967295);z57bf1945ef->z2f1801d2e2=((0x122+2158-0x98f)<<z4e3026977c);z57bf1945ef->z2f1801d2e2=(0x1626+820-0x195a);z57bf1945ef->z1b3a4657a7[z4e3026977c]=(0x22ab+861-0x2607);z57bf1945ef->z1b3a4657a7[z4e3026977c]=(0x813+531-0xa26);
position+=(uint64_T)(18446744073709551616.0/z32b35fb51b/2.0);
z57bf1945ef->z090cd67c73[z4e3026977c]=(uint32_T)((position>>(0x6f+1243-0x52a))&4294967295);;z57bf1945ef->z6695674542[z4e3026977c]=(uint32_T)((position)&4294967295);z57bf1945ef->z2f1801d2e2=((0xc8f+6509-0x25fb)<<z4e3026977c);z57bf1945ef->z2f1801d2e2=(0x3a2+7704-0x21ba);z57bf1945ef->z1b3a4657a7[z4e3026977c]=(0x22cc+639-0x2549);z57bf1945ef->z1b3a4657a7[z4e3026977c]=(0x1047+1942-0x17dd);}}z57bf1945ef->z4da0d16710=(0x3b4+994-0x796);
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

