/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1140+2609-0x1b6f)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_qae_sf
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
#define zdf24515981        ((0x10f9+1199-0x159c))
#define z533b11d03f         ssGetSFcnParam(S,(0x181+2721-0xc22)) 
#define za9d8fb6bcf           ssGetSFcnParam(S,(0xa33+2616-0x146a)) 
#define z503e6ced0f    ssGetSFcnParam(S,(0x851+4454-0x19b5)) 
#define zf0a85064b6     ssGetSFcnParam(S,(0x1ee3+2085-0x2705)) 
#define ze4d3b8eb95        ssGetSFcnParam(S,(0xb21+6815-0x25bc)) 
#define zb59583bf39         ssGetSFcnParam(S,(0xa8c+5370-0x1f81)) 
#define zc8bbaa6115             ssGetSFcnParam(S,(0x161+8772-0x239f)) 
#define z290889a43b      ssGetSFcnParam(S,(0x12c9+1037-0x16cf)) 
#define z13bb501290         ssGetSFcnParam(S,(0x189c+1413-0x1e19)) 
#define z19087bd486        ssGetSFcnParam(S,(0x1383+3161-0x1fd3))
#define z3832b85a32         ssGetSFcnParam(S,(0x1097+1774-0x177b))
#define z702a26a5e9              ssGetSFcnParam(S,(0x1f9+2365-0xb2b))
#define z2e6483d505              ((0x770+3377-0x14a0))
#define zc5ce4cb81a              ((0x1650+1883-0x1dab))
#define z2b17e2ee3b              ((0xad0+5921-0x21f1))
#define z6a0da049de         ((0x1138+5500-0x26b4))
#define z43241952e9                 (196608)
static char_T zea4cd01646[(0x50a+8436-0x24fe)];struct z89df2198fb{uint32_T z3fd72505ec;uint32_T z4da0d16710;uint32_T z2f1801d2e2;int32_T z8ccca10206[(0x356+4567-0x150d)];int32_T z141ebdb094[(0x487+8221-0x2484)];uint32_T z090cd67c73[(0x48d+2087-0xc94)];uint32_T z6695674542[(0x19c+1617-0x7cd)];uint32_T z1b3a4657a7[(0x1a0f+2486-0x23a5)];uint32_T z32b35fb51b[(0x18f7+1521-0x1ec8)];uint32_T zcb34517c3c[(0x1d2+8237-0x21df)];uint32_T z1c9de180ec[(0xcdb+4945-0x200c)];};static void mdlInitializeSizes(SimStruct*S){uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x1330+479-0x150f));ssSetNumDiscStates(S,(0xb4+2972-0xc50));if(mxGetPr(zf0a85064b6)[(0x839+1950-0xfd7)]){if(mxGetPr(ze4d3b8eb95)[(0x379+8638-0x2537)]){ssSetNumInputPorts(S,(0xb10+377-0xc87));ssSetInputPortWidth(S,(0x76a+971-0xb35),mxGetN(za9d8fb6bcf));ssSetInputPortDirectFeedThrough(S,(0xfc7+425-0x1170),(0x48d+2410-0xdf6));ssSetInputPortRequiredContiguous(S,(0x76c+6022-0x1ef2),(0x974+1505-0xf54));ssSetInputPortWidth(S,(0x12d5+1499-0x18af),mxGetN(za9d8fb6bcf));ssSetInputPortDirectFeedThrough(S,(0x110d+4283-0x21c7),(0x13b6+1177-0x184e));ssSetInputPortRequiredContiguous(S,(0x1e30+161-0x1ed0),(0x119b+2919-0x1d01));}else{ssSetNumInputPorts(S,(0x18e4+1898-0x204d));ssSetInputPortWidth(S,(0x161f+1013-0x1a14),mxGetN(za9d8fb6bcf));ssSetInputPortDirectFeedThrough(S,(0xb6a+547-0xd8d),(0x97a+5127-0x1d80));ssSetInputPortRequiredContiguous(S,(0x1978+2039-0x216f),(0x718+848-0xa67));}}else{if(mxGetPr(ze4d3b8eb95)[(0xe54+5371-0x234f)]){ssSetNumInputPorts(S,(0xb60+5637-0x2164));ssSetInputPortWidth(S,(0x6a5+5169-0x1ad6),mxGetN(za9d8fb6bcf));ssSetInputPortDirectFeedThrough(S,(0x1233+3879-0x215a),(0x312+8748-0x253d));ssSetInputPortRequiredContiguous(S,(0x14dc+2327-0x1df3),(0x686+5039-0x1a34));}else{ssSetNumInputPorts(S,(0x763+6426-0x207d));}}if(mxGetPr(z503e6ced0f)[(0x1dd+4725-0x1452)]){ssSetNumOutputPorts(S,(0x1ad+1704-0x854));ssSetOutputPortWidth(S,(0x350+2819-0xe53),mxGetN(za9d8fb6bcf));}else{ssSetNumOutputPorts(S,(0xcc0+6486-0x2616));}ssSetNumSampleTimes(S,(0x2a+2347-0x954));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xac5+2199-0x135c));ssSetNumNonsampledZCs(S,(0x310+7426-0x2012));for(i=(0x1298+2509-0x1c65);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x9e1+319-0xb20));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x7e4+7558-0x256a)]==-1.0){ssSetSampleTime(S,(0x22c8+735-0x25a7),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x856+912-0xbe6),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xa4a+6718-0x2488),mxGetPr(z3832b85a32)[(0x180+5457-0x16d1)]);ssSetOffsetTime(S,(0x932+149-0x9c7),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i,z26dbd73a5e;int64_T delta;uint64_T position;real_T z32b35fb51b;uint8_T z16ba527520[(0x5d7+7076-0x2167)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61,z4e3026977c,z4da0d16710,z2f1801d2e2;volatile struct z89df2198fb*z57bf1945ef;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0xea7+3857-0x1db8)];z6f813cde47=z05b56d9d51=5845;switch(z78caf1ba61){case(0x14d8+2243-0x1c6e):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");za4a2434e08=z182d03571c=17232;break;case(0x102f+5138-0x2313):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");za4a2434e08=z182d03571c=17239;break;case(0x4d8+6441-0x1cd2):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");za4a2434e08=z182d03571c=16979;break;case(0x67a+5759-0x1bc9):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");za4a2434e08=z182d03571c=(0x109d+4629-0x1dae);break;case(0x7b3+5667-0x1c9f):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");za4a2434e08=z182d03571c=21069;break;case(0x2c5+635-0x408):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");za4a2434e08=z182d03571c=16971;break;case(0x1435+2811-0x1df7):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");za4a2434e08=z182d03571c=17235;break;case(0xafc+6030-0x2150):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");za4a2434e08=z182d03571c=(0x213d+8010-0x2083);break;case(0x7b1+6610-0x2042):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;}if(mxGetN(z702a26a5e9)==(0x2ab+6860-0x1d76)){z366b2f03bf=(0x1bd+6445-0x1aea);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x146f+287-0x158e)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x91+5697-0x16d2)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x8d6+5409-0x1df6)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x1609+932-0x19ab)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x1336+3786-0x21fe)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x1909+741-0x1bec)]);z57bf1945ef=(struct z89df2198fb*)(zeccbadd9b3.VirtAddress[(0x19e9+648-0x1c6f)]+z43241952e9);if(!xpceIsModelInit()){if((uint32_T)mxGetPr(zc8bbaa6115)[(0x192+3357-0xeaf)]){z2f1801d2e2=(0x1a51+3234-0x26f3);for(i=(0x12b8+3872-0x21d8);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x528+6410-0x1e31);z2f1801d2e2|=((0x227c+361-0x23e4)<<z4e3026977c);delta=(int64_T)(18446744073709551616.0/60.0*((real_T)mxGetPr(z13bb501290)[z4e3026977c]/33000000.0));z57bf1945ef->z8ccca10206[z4e3026977c]=(int32_T)((delta>>(0xa5b+5592-0x2013))&4294967295);z57bf1945ef->z141ebdb094[z4e3026977c]=(int32_T)((delta)&4294967295);z57bf1945ef->z2f1801d2e2=((0x16c6+3148-0x2311)<<z4e3026977c);z57bf1945ef->z2f1801d2e2=(0x1304+2716-0x1da0);z32b35fb51b=1.0;for(z26dbd73a5e=(0x1113+2556-0x1b0f);z26dbd73a5e<(uint32_T)(mxGetPr(z19087bd486)[z4e3026977c]);z26dbd73a5e++){z32b35fb51b*=2.0;}position=(uint64_T)((18446744073709551616.0/z32b35fb51b)*(real_T)mxGetPr(z290889a43b)[z4e3026977c]);z57bf1945ef->z090cd67c73[z4e3026977c]=(uint32_T)((position>>(0xa5+6553-0x1a1e))&4294967295);z57bf1945ef->z6695674542[z4e3026977c]=(uint32_T)((position)&4294967295);z57bf1945ef->z2f1801d2e2=((0x86f+1097-0xcb7)<<z4e3026977c);z57bf1945ef->z2f1801d2e2=(0x7b0+788-0xac4);z57bf1945ef->z1b3a4657a7[z4e3026977c]=(0xffc+3831-0x1ef2);z57bf1945ef->z1b3a4657a7[z4e3026977c]=(0x6fd+2298-0xff7);
position+=(uint64_T)(18446744073709551616.0/z32b35fb51b/2.0);
z57bf1945ef->z090cd67c73[z4e3026977c]=(uint32_T)((position>>(0x41b+4090-0x13f5))&4294967295);;z57bf1945ef->z6695674542[z4e3026977c]=(uint32_T)((position)&4294967295);z57bf1945ef->z2f1801d2e2=((0x1649+1102-0x1a96)<<z4e3026977c);z57bf1945ef->z2f1801d2e2=(0x874+4833-0x1b55);z57bf1945ef->z1b3a4657a7[z4e3026977c]=(0x1c1c+1924-0x239e);z57bf1945ef->z1b3a4657a7[z4e3026977c]=(0x5da+7540-0x234e);}}z4da0d16710=(0x221f+1235-0x26f2);for(i=(0xbf9+3025-0x17ca);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x29+5338-0x1502);z4da0d16710|=((0x149d+433-0x164d)<<z4e3026977c);}z57bf1945ef->z4da0d16710=z4da0d16710;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint32_T i,z4e3026977c;int64_T delta;real_T*y1,*y2;real_T*out;volatile struct z89df2198fb*z57bf1945ef=(struct z89df2198fb*)(base+z43241952e9);if(mxGetPr(z503e6ced0f)[(0x43c+5494-0x19b2)]){out=(real_T*)ssGetOutputPortSignal(S,(0xb4c+4126-0x1b6a));for(i=(0x861+2658-0x12c3);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x367+6647-0x1d5d);out[i]=(real_T)z57bf1945ef->z1c9de180ec[z4e3026977c];}}if(mxGetPr(zf0a85064b6)[(0x1956+2403-0x22b9)]){if(mxGetPr(ze4d3b8eb95)[(0x19b5+1987-0x2178)]){for(i=(0x7b4+6018-0x1f36);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xc21+2914-0x1782);y1=(real_T*)ssGetInputPortSignal(S,(0x1e59+873-0x21c2));y2=(real_T*)ssGetInputPortSignal(S,(0x240+8227-0x2262));z57bf1945ef->zcb34517c3c[z4e3026977c]=(uint32_T)y1[i];delta=(int64_T)(18446744073709551616.0/60.0*((real_T)y2[z4e3026977c]/33000000.0));z57bf1945ef->z8ccca10206[z4e3026977c]=(int32_T)((delta>>(0x7d7+3332-0x14bb))&4294967295);z57bf1945ef->z141ebdb094[z4e3026977c]=(int32_T)((delta)&4294967295);z57bf1945ef->z2f1801d2e2=((0x20cd+658-0x235e)<<z4e3026977c);z57bf1945ef->z2f1801d2e2=(0x1d0+7107-0x1d93);}}else{y1=(real_T*)ssGetInputPortSignal(S,(0x2f2+2051-0xaf5));for(i=(0x3f2+6759-0x1e59);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x189+1985-0x949);z57bf1945ef->zcb34517c3c[z4e3026977c]=(uint32_T)y1[i];}}}else{if(mxGetPr(ze4d3b8eb95)[(0x8d2+3959-0x1849)]){y1=(real_T*)ssGetInputPortSignal(S,(0xe6f+1908-0x15e3));for(i=(0x981+7549-0x26fe);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xa41+1472-0x1000);delta=(int64_T)(18446744073709551616.0/60.0*((real_T)y1[z4e3026977c]/33000000.0));z57bf1945ef->z8ccca10206[z4e3026977c]=(int32_T)((delta>>(0x2d1+4611-0x14b4))&4294967295);z57bf1945ef->z141ebdb094[z4e3026977c]=(int32_T)((delta)&4294967295);z57bf1945ef->z2f1801d2e2=((0xa2+7174-0x1ca7)<<z4e3026977c);z57bf1945ef->z2f1801d2e2=(0x11d0+4993-0x2551);}}}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint32_T i,z26dbd73a5e;uint32_T z4e3026977c;int64_T delta;uint64_T position;real_T z32b35fb51b;volatile struct z89df2198fb*z57bf1945ef=(struct z89df2198fb*)(base+z43241952e9);if(xpceIsModelInit())
{z57bf1945ef->z3fd72505ec=((uint32_T)mxGetPr(zb59583bf39)[(0x385+2869-0xeba)]);for(i=(0x19aa+1116-0x1e06);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x7da+7544-0x2551);z57bf1945ef->z32b35fb51b[z4e3026977c]=(uint32_T)mxGetPr(z19087bd486)[i]-(0x606+2813-0x1102);}for(i=(0x8cf+1223-0xd96);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x370+3260-0x102b);delta=(int64_T)(18446744073709551616.0/60.0*((real_T)mxGetPr(z13bb501290)[z4e3026977c]/33000000.0));z57bf1945ef->z8ccca10206[z4e3026977c]=(int32_T)((delta>>(0x111c+3955-0x206f))&4294967295);z57bf1945ef->z141ebdb094[z4e3026977c]=(int32_T)((delta)&4294967295);z57bf1945ef->z2f1801d2e2=((0x51b+4794-0x17d4)<<z4e3026977c);z57bf1945ef->z2f1801d2e2=(0x730+4558-0x18fe);z32b35fb51b=1.0;for(z26dbd73a5e=(0x1748+893-0x1ac5);z26dbd73a5e<(uint32_T)(mxGetPr(z19087bd486)[z4e3026977c]);z26dbd73a5e++){z32b35fb51b*=2.0;}position=(uint64_T)((18446744073709551616.0/z32b35fb51b)*(real_T)mxGetPr(z290889a43b)[z4e3026977c]);z57bf1945ef->z090cd67c73[z4e3026977c]=(uint32_T)((position>>(0xa21+1345-0xf42))&4294967295);z57bf1945ef->z6695674542[z4e3026977c]=(uint32_T)((position)&4294967295);z57bf1945ef->z2f1801d2e2=((0x1da5+1648-0x2414)<<z4e3026977c);z57bf1945ef->z2f1801d2e2=(0xee5+554-0x110f);z57bf1945ef->z1b3a4657a7[z4e3026977c]=(0x1497+1042-0x18a8);z57bf1945ef->z1b3a4657a7[z4e3026977c]=(0x329+1346-0x86b);
position+=(uint64_T)(18446744073709551616.0/z32b35fb51b/2.0);
z57bf1945ef->z090cd67c73[z4e3026977c]=(uint32_T)((position>>(0xda+1084-0x4f6))&4294967295);;z57bf1945ef->z6695674542[z4e3026977c]=(uint32_T)((position)&4294967295);z57bf1945ef->z2f1801d2e2=((0x9cc+4139-0x19f6)<<z4e3026977c);z57bf1945ef->z2f1801d2e2=(0xc82+3785-0x1b4b);z57bf1945ef->z1b3a4657a7[z4e3026977c]=(0x39d+8605-0x2538);z57bf1945ef->z1b3a4657a7[z4e3026977c]=(0xc52+5470-0x21b0);}}z57bf1945ef->z4da0d16710=(0x24df+536-0x26f7);
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif
