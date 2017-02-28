/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1165+4208-0x21d3)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_qae_sf_2
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
#define zdf24515981        ((0x772+3889-0x1697))
#define z533b11d03f         ssGetSFcnParam(S,(0x11e4+4983-0x255b)) 
#define za9d8fb6bcf           ssGetSFcnParam(S,(0x93b+2433-0x12bb)) 
#define z503e6ced0f    ssGetSFcnParam(S,(0x92a+1263-0xe17)) 
#define zf0a85064b6     ssGetSFcnParam(S,(0x1df5+69-0x1e37)) 
#define ze4d3b8eb95        ssGetSFcnParam(S,(0xa76+5039-0x1e21)) 
#define zb59583bf39         ssGetSFcnParam(S,(0xe21+1346-0x135e)) 
#define z56f7a09453     ssGetSFcnParam(S,(0x2199+598-0x23e9)) 
#define za690f302a2     ssGetSFcnParam(S,(0x108f+5303-0x253f)) 
#define z13bb501290         ssGetSFcnParam(S,(0x11e9+48-0x1211)) 
#define z19087bd486        ssGetSFcnParam(S,(0x12f1+4563-0x24bb))
#define z3832b85a32         ssGetSFcnParam(S,(0x77b+4319-0x1850))
#define z702a26a5e9              ssGetSFcnParam(S,(0x12cf+398-0x1452))
#define z2e6483d505              ((0xaef+5531-0x2089))
#define zc5ce4cb81a              ((0x965+3448-0x16dd))
#define z2b17e2ee3b              ((0x1ad0+2926-0x263e))
#define z6a0da049de         ((0x224d+432-0x23fd))
#define z3c26710301                      (3.14159265358979323846)
#define z43241952e9                 (196608)
static char_T zea4cd01646[(0x1146+4843-0x2331)];typedef struct{uint32_T volatile z3fd72505ec;uint32_T volatile z4da0d16710;uint32_T volatile z1bf388aa66;
uint32_T volatile z98cba76ae0;int32_T volatile z8ccca10206[(0x8a7+39-0x8ae)];int32_T volatile z141ebdb094[(0x37+8761-0x2250)];uint32_T volatile z090cd67c73[(0x4e9+3099-0x10e4)];uint32_T volatile z6695674542[(0x1901+1603-0x1f24)];uint32_T volatile z1b3a4657a7[(0x144f+2113-0x1c70)];uint32_T volatile z32b35fb51b[(0x385+7019-0x1ed0)];uint32_T volatile zcb34517c3c[(0xa64+5214-0x1ea2)];uint32_T volatile z1c9de180ec[(0xeb5+4212-0x1f09)];}z89df2198fb;static void mdlInitializeSizes(SimStruct*S){uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x1db+3998-0x1179));ssSetNumDiscStates(S,(0x844+1464-0xdfc));if(mxGetPr(zf0a85064b6)[(0x1129+195-0x11ec)]){if(mxGetPr(ze4d3b8eb95)[(0xf3+7833-0x1f8c)]){ssSetNumInputPorts(S,(0xdaa+3153-0x19f9));ssSetInputPortWidth(S,(0x14b8+110-0x1526),mxGetN(za9d8fb6bcf));ssSetInputPortDirectFeedThrough(S,(0x1217+2229-0x1acc),(0x4eb+1674-0xb74));ssSetInputPortRequiredContiguous(S,(0x1c25+2761-0x26ee),(0x62b+3169-0x128b));ssSetInputPortWidth(S,(0x1407+59-0x1441),mxGetN(za9d8fb6bcf));ssSetInputPortDirectFeedThrough(S,(0x13d+6366-0x1a1a),(0x16f3+254-0x17f0));ssSetInputPortRequiredContiguous(S,(0x1405+3625-0x222d),(0x30a+5074-0x16db));}else{ssSetNumInputPorts(S,(0x943+5274-0x1ddc));ssSetInputPortWidth(S,(0x878+5876-0x1f6c),mxGetN(za9d8fb6bcf));ssSetInputPortDirectFeedThrough(S,(0x1eb7+1547-0x24c2),(0x3d1+3530-0x119a));ssSetInputPortRequiredContiguous(S,(0xb3+8136-0x207b),(0x181b+766-0x1b18));}}else{if(mxGetPr(ze4d3b8eb95)[(0x835+6481-0x2186)]){ssSetNumInputPorts(S,(0x9e1+7132-0x25bc));ssSetInputPortWidth(S,(0x15c+7262-0x1dba),mxGetN(za9d8fb6bcf));ssSetInputPortDirectFeedThrough(S,(0x17b4+2386-0x2106),(0x9cc+5324-0x1e97));ssSetInputPortRequiredContiguous(S,(0x6cc+1410-0xc4e),(0x1926+3504-0x26d5));}else{ssSetNumInputPorts(S,(0x5fd+394-0x787));}}if(mxGetPr(z503e6ced0f)[(0x19b+408-0x333)]){ssSetNumOutputPorts(S,(0x988+334-0xad5));ssSetOutputPortWidth(S,(0x10+7066-0x1baa),mxGetN(za9d8fb6bcf));}else{ssSetNumOutputPorts(S,(0x46f+2771-0xf42));}ssSetNumSampleTimes(S,(0x1793+1502-0x1d70));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x621+5853-0x1cfe));ssSetNumNonsampledZCs(S,(0x131+2145-0x992));for(i=(0x8d7+935-0xc7e);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1b04+1320-0x202c));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x1651+1671-0x1cd8)]==-1.0){ssSetSampleTime(S,(0x16c3+4003-0x2666),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xfd3+1629-0x1630),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xcc2+2503-0x1689),mxGetPr(z3832b85a32)[(0x209d+56-0x20d5)]);ssSetOffsetTime(S,(0x654+1038-0xa62),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i;uint8_T z16ba527520[(0x48a+1015-0x86d)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61,z4e3026977c,z4da0d16710;z89df2198fb*z57bf1945ef;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x2034+715-0x22ff)];z6f813cde47=z05b56d9d51=5845;switch(z78caf1ba61){case(0x1189+2290-0x194e):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");za4a2434e08=z182d03571c=17232;break;case(0x7ea+3700-0x1530):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");za4a2434e08=z182d03571c=17239;break;case(0x724+7524-0x2359):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");za4a2434e08=z182d03571c=16979;break;case(0x24c0+797-0x26ad):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");za4a2434e08=z182d03571c=(0x1129+3671-0x1a7c);break;case(0x399+4813-0x152f):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");za4a2434e08=z182d03571c=21069;break;case(0x18b3+2230-0x2031):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");za4a2434e08=z182d03571c=16971;break;case(0x499+3656-0x11a8):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");za4a2434e08=z182d03571c=17235;break;case(0xdfb+3037-0x189e):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");za4a2434e08=z182d03571c=8196;break;case(0x1014+619-0x113e):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;}if(mxGetN(z702a26a5e9)==(0x1814+2438-0x2199)){z366b2f03bf=(0x830+7592-0x25d8);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xf1+7333-0x1d96)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x68c+182-0x742)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x111a+2082-0x193b)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x1203+4363-0x230c)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x407+959-0x7c4)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x811+1375-0xd6e)]);z57bf1945ef=(z89df2198fb*)(zeccbadd9b3.VirtAddress[(0xb54+429-0xcff)]+z43241952e9);if(!xpceIsModelInit()){z4da0d16710=(0x20c9+659-0x235c);for(i=(0xc53+5345-0x2134);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x65b+2998-0x1210);z4da0d16710|=((0x1aa3+2705-0x2533)<<z4e3026977c);}z57bf1945ef->z4da0d16710=z4da0d16710;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint32_T i,z4e3026977c,z1bf388aa66;int64_T delta;real_T*y1,*y2;real_T*out;z89df2198fb*z57bf1945ef=(z89df2198fb*)(base+z43241952e9);if(mxGetPr(z503e6ced0f)[(0x15d9+777-0x18e2)]){out=(real_T*)ssGetOutputPortSignal(S,(0x185+117-0x1fa));for(i=(0xec8+5930-0x25f2);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xb0c+5195-0x1f56);out[i]=(real_T)z57bf1945ef->z1c9de180ec[z4e3026977c];}}if(mxGetPr(zf0a85064b6)[(0x843+3852-0x174f)]){if(mxGetPr(ze4d3b8eb95)[(0x63+5415-0x158a)]){z1bf388aa66=(0x804+5865-0x1eed);for(i=(0xe24+2576-0x1834);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x79d+3713-0x161d);y1=(real_T*)ssGetInputPortSignal(S,(0x1480+0-0x1480));y2=(real_T*)ssGetInputPortSignal(S,(0x57c+503-0x772));z57bf1945ef->zcb34517c3c[z4e3026977c]=(uint32_T)y1[i];delta=(int64_T)(18446744073709551616.0/60.0*((real_T)y2[i]/33000000.0));z57bf1945ef->z8ccca10206[z4e3026977c]=(int32_T)((delta>>(0xb76+3285-0x182b))&4294967295);z57bf1945ef->z141ebdb094[z4e3026977c]=(int32_T)((delta)&4294967295);z1bf388aa66|=((0x21d4+137-0x225c)<<z4e3026977c);}z57bf1945ef->z1bf388aa66=z1bf388aa66;z57bf1945ef->z1bf388aa66=(0x8e2+3764-0x1796);}else{y1=(real_T*)ssGetInputPortSignal(S,(0xae8+2844-0x1604));for(i=(0x8bd+1999-0x108c);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xbd9+2847-0x16f7);z57bf1945ef->zcb34517c3c[z4e3026977c]=(uint32_T)y1[i];}}}else{if(mxGetPr(ze4d3b8eb95)[(0x1d22+303-0x1e51)]){y1=(real_T*)ssGetInputPortSignal(S,(0xbfd+6100-0x23d1));z1bf388aa66=(0x271+7915-0x215c);for(i=(0x207c+810-0x23a6);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xf4f+865-0x12af);delta=(int64_T)(18446744073709551616.0/60.0*((real_T)y1[i]/33000000.0));z57bf1945ef->z8ccca10206[z4e3026977c]=(int32_T)((delta>>(0xfb1+3138-0x1bd3))&4294967295);z57bf1945ef->z141ebdb094[z4e3026977c]=(int32_T)((delta)&4294967295);z1bf388aa66|=((0xab7+2104-0x12ee)<<z4e3026977c);}z57bf1945ef->z1bf388aa66=z1bf388aa66;z57bf1945ef->z1bf388aa66=(0xb38+2702-0x15c6);}}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint32_T i,z26dbd73a5e;uint32_T z4e3026977c,z1bf388aa66;int64_T delta;uint64_T position;real_T z32b35fb51b;uint32_T z7be9105675;z89df2198fb*z57bf1945ef=(z89df2198fb*)(base+z43241952e9);z1bf388aa66=(0x166b+2519-0x2042);for(i=(0x1359+1162-0x17e3);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x117+6334-0x19d4);z57bf1945ef->z3fd72505ec=((uint32_T)mxGetPr(zb59583bf39)[(0x83a+95-0x899)]);z57bf1945ef->z32b35fb51b[z4e3026977c]=(uint32_T)mxGetPr(z19087bd486)[i]-(0x17a1+1195-0x1c4b);delta=(int64_T)(18446744073709551616.0/60.0*((real_T)mxGetPr(z13bb501290)[z4e3026977c]/33000000.0));z57bf1945ef->z8ccca10206[z4e3026977c]=(int32_T)((delta>>(0x316+6830-0x1da4))&4294967295);z57bf1945ef->z141ebdb094[z4e3026977c]=(int32_T)((delta)&4294967295);z1bf388aa66|=((0x7ac+4233-0x1834)<<z4e3026977c);z32b35fb51b=1.0;for(z26dbd73a5e=(0x936+4068-0x191a);z26dbd73a5e<(uint32_T)(mxGetPr(z19087bd486)[z4e3026977c]);z26dbd73a5e++){z32b35fb51b*=2.0;}position=(uint64_T)((18446744073709551616.0*(real_T)mxGetPr(z56f7a09453)[z4e3026977c])/(2.0*z3c26710301));
z57bf1945ef->z090cd67c73[z4e3026977c]=(uint32_T)((position>>(0x1267+3776-0x2107))&4294967295);
z57bf1945ef->z6695674542[z4e3026977c]=(uint32_T)((position)&4294967295);
z57bf1945ef->z98cba76ae0=((0x1dd8+918-0x216d)<<z4e3026977c);z57bf1945ef->z98cba76ae0=(0x1ae8+1733-0x21ad);z57bf1945ef->z1b3a4657a7[z4e3026977c]=(0x10fa+3967-0x2078);z57bf1945ef->z1b3a4657a7[z4e3026977c]=(0x19c0+249-0x1ab9);position=(uint64_T)((18446744073709551616.0*(real_T)mxGetPr(za690f302a2)[z4e3026977c])/(2.0*z3c26710301));
z57bf1945ef->z090cd67c73[z4e3026977c]=(uint32_T)((position>>(0x2d5+5369-0x17ae))&4294967295);;z57bf1945ef->z6695674542[z4e3026977c]=(uint32_T)((position)&4294967295);z57bf1945ef->z98cba76ae0=((0x260+8302-0x22cd)<<z4e3026977c);z57bf1945ef->z98cba76ae0=(0x182a+3643-0x2665);z57bf1945ef->z1b3a4657a7[z4e3026977c]=(0x10f3+2136-0x1949);z57bf1945ef->z1b3a4657a7[z4e3026977c]=(0x886+4234-0x1910);}z57bf1945ef->z1bf388aa66=z1bf388aa66;z57bf1945ef->z1bf388aa66=(0x5e1+744-0x8c9);z57bf1945ef->z4da0d16710=(0x1c37+1593-0x2270);
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

