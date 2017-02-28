/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x240+6624-0x1c1e)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_pwmcapture_sf
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
#define zdf24515981        ((0xcaf+702-0xf65))
#define z533b11d03f         ssGetSFcnParam(S, (0xc75+6355-0x2548)) 
#define za9d8fb6bcf           ssGetSFcnParam(S, (0x1877+91-0x18d1)) 
#define z65adacaed7  ssGetSFcnParam(S, (0x143b+4504-0x25d1))
#define zcd0368f327   ssGetSFcnParam(S, (0x1818+2234-0x20cf))
#define zbeff7d4e04        ssGetSFcnParam(S, (0x170b+742-0x19ed))
#define za42e288061              ssGetSFcnParam(S, (0x5e1+1062-0xa02))
#define z3832b85a32         ssGetSFcnParam(S, (0x17a8+2763-0x226d))
#define z702a26a5e9              ssGetSFcnParam(S, (0x12a3+3956-0x2210))
#define z2e6483d505              ((0xb26+333-0xc72))
#define zc5ce4cb81a              ((0x203a+944-0x23ea))
#define z2b17e2ee3b              ((0x998+4152-0x19d0))
#define z6a0da049de         ((0x1238+1576-0x1860))
#define z0029de9784          (131072)
static char_T zea4cd01646[(0xa8f+5411-0x1eb2)];struct zccf45b4cac{uint32_T z4da0d16710[(0x5b8+76-0x602)];uint32_T zc78a7188e6[(0x134f+3614-0x216b)];uint32_T mode[(0x55+924-0x3b1)];uint32_T zf277fad9fc[(0x1da9+1286-0x226f)];uint32_T ze1c0f7736d[(0x68d+5499-0x1bc8)];uint32_T z26f345a067[(0xed9+3329-0x1b9a)];};static void mdlInitializeSizes(SimStruct*S){uint32_T i,za0df33019b;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x5aa+6731-0x1ff5));ssSetNumDiscStates(S,(0x1099+391-0x1220));za0df33019b=(0x227+7417-0x1f20);if(mxGetPr(z65adacaed7)[(0x17ad+2300-0x20a9)]){za0df33019b++;}if(mxGetPr(zcd0368f327)[(0xf30+4645-0x2155)]){za0df33019b++;}if(mxGetPr(zbeff7d4e04)[(0x186+3647-0xfc5)]){za0df33019b++;}ssSetNumOutputPorts(S,za0df33019b);for(i=(0x298+6785-0x1d19);i<za0df33019b;i++){ssSetOutputPortWidth(S,i,mxGetN(za9d8fb6bcf));}ssSetNumInputPorts(S,(0xf8b+4082-0x1f7d));
ssSetNumSampleTimes(S,(0x19a1+248-0x1a98));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1547+1945-0x1ce0));ssSetNumNonsampledZCs(S,(0x886+4440-0x19de));for(i=(0x92d+1723-0xfe8);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1fca+908-0x2356));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x1da+4196-0x123e)]==-1.0){ssSetSampleTime(S,(0x10f7+3202-0x1d79),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x824+3458-0x15a6),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x8f3+4135-0x191a),mxGetPr(z3832b85a32)[(0x7c9+7654-0x25af)]);ssSetOffsetTime(S,(0xed1+722-0x11a3),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i;uint8_T z16ba527520[(0x114d+4525-0x22e6)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61,z4e3026977c,z4da0d16710,z46d3e78680;volatile struct zccf45b4cac*z565c99c453;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0xd84+3117-0x19b1)];z6f813cde47=z05b56d9d51=(0x17a9+7758-0x1f22);switch(z78caf1ba61){case(0x154a+2281-0x1d06):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");za4a2434e08=z182d03571c=17232;break;case(0x890+1136-0xbd2):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");za4a2434e08=z182d03571c=17239;break;case(0xa9b+2786-0x144e):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");za4a2434e08=z182d03571c=16979;break;case(0xc2c+608-0xd5c):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");za4a2434e08=z182d03571c=(0x1fa1+728-0x1d75);break;case(0x802+5329-0x1b9c):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");za4a2434e08=z182d03571c=21069;break;case(0x1d0+8862-0x2336):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");za4a2434e08=z182d03571c=16971;break;case(0xfd7+4204-0x1f0a):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");za4a2434e08=z182d03571c=17235;break;case(0x19cf+3651-0x26d8):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");za4a2434e08=z182d03571c=8196;break;case(0x10a3+2378-0x18ac):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;}if(mxGetN(z702a26a5e9)==(0x1d7+5212-0x1632)){z366b2f03bf=(0x864+2818-0x1366);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x6c0+502-0x8b6)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0xf81+1820-0x169d)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x1639+2582-0x204e)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x530+1419-0xab9)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x16e4+2716-0x217e)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x1780+1397-0x1cf3)]);z565c99c453=(struct zccf45b4cac*)(zeccbadd9b3.VirtAddress[(0x1b06+1295-0x2013)]+z0029de9784);if(!xpceIsModelInit()){z4da0d16710=z565c99c453->z4da0d16710[(0x100+4659-0x1333)];z46d3e78680=z565c99c453->z4da0d16710[(0x4bc+1199-0x96a)];for(i=(0x1540+1196-0x19ec);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1145+298-0x126e);if(z4e3026977c<(0x4d3+2685-0xf30)){z4da0d16710|=((0x195+2384-0xae4)<<z4e3026977c);}else{z46d3e78680|=((0x1995+1268-0x1e88)<<(z4e3026977c-(0x181b+3744-0x269b)));}z565c99c453->mode[z4e3026977c]=(uint32_T)mxGetPr(za42e288061)[i]-(0x12b2+2479-0x1c60);}z565c99c453->z4da0d16710[(0x1db0+1601-0x23f1)]=z4da0d16710;z565c99c453->z4da0d16710[(0xeba+1579-0x14e4)]=z46d3e78680;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint32_T i,z4e3026977c,zc78a7188e6,z944b9e6027,z0add1d1c25;uint32_T zde7140fd0d;real_T*y;volatile struct zccf45b4cac*z565c99c453=(struct zccf45b4cac*)(base+z0029de9784);z0add1d1c25=(0x1cb+9132-0x2577);zc78a7188e6=z944b9e6027=(0x1b5+7212-0x1de1);zde7140fd0d=(0xbf+4747-0x134a);for(i=(0x18e0+778-0x1bea);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1991+2617-0x23c9);if((uint32_T)mxGetPr(za42e288061)[z4e3026977c]==(0x16d4+467-0x18a3)){zde7140fd0d=(0x17e4+3822-0x26d1);if(z4e3026977c<(0x5d6+1656-0xc2e)){zc78a7188e6|=(0x8e7+6489-0x223f)<<z4e3026977c;}else{z944b9e6027|=(0x8eb+5764-0x1f6e)<<(z4e3026977c-(0xd3c+56-0xd54));}}}if(zde7140fd0d){z565c99c453->zc78a7188e6[(0xfa6+153-0x103f)]=zc78a7188e6;z565c99c453->zc78a7188e6[(0x6cf+5071-0x1a9d)]=z944b9e6027;z565c99c453->zc78a7188e6[(0x18aa+977-0x1c7b)]=(0x112+2846-0xc30);z565c99c453->zc78a7188e6[(0x7c3+1455-0xd71)]=(0x1130+4713-0x2399);}if(mxGetPr(z65adacaed7)[(0xe6b+5685-0x24a0)]){y=(real_T*)ssGetOutputPortSignal(S,z0add1d1c25);z0add1d1c25++;for(i=(0xac1+2574-0x14cf);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x33d+5163-0x1767);y[i]=(real_T)z565c99c453->zf277fad9fc[z4e3026977c];}}if(mxGetPr(zcd0368f327)[(0x1306+105-0x136f)]){y=(real_T*)ssGetOutputPortSignal(S,z0add1d1c25);z0add1d1c25++;for(i=(0xd13+5959-0x245a);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x587+795-0x8a1);y[i]=(real_T)z565c99c453->ze1c0f7736d[z4e3026977c];}}if(mxGetPr(zbeff7d4e04)[(0x1448+3192-0x20c0)]){y=(real_T*)ssGetOutputPortSignal(S,z0add1d1c25);z0add1d1c25++;for(i=(0x100f+5267-0x24a2);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xc94+2947-0x1816);y[i]=(real_T)z565c99c453->z26f345a067[z4e3026977c];}}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile struct zccf45b4cac*z565c99c453=(struct zccf45b4cac*)(base+z0029de9784);if(!xpceIsModelInit())
{z565c99c453->z4da0d16710[(0x891+2307-0x1194)]=(0x17eb+1003-0x1bd6);z565c99c453->z4da0d16710[(0x735+7415-0x242b)]=(0xb4d+6024-0x22d5);}
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif
