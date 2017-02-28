/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x15cc+1557-0x1bdf)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_cap_sf_a2
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
#define zdf24515981        ((0x61c+4113-0x1625))
#define z533b11d03f         ssGetSFcnParam(S, (0x8df+5157-0x1d04)) 
#define za9d8fb6bcf           ssGetSFcnParam(S, (0x32f+5880-0x1a26)) 
#define z65adacaed7  ssGetSFcnParam(S, (0x18e4+2947-0x2465))
#define zcd0368f327   ssGetSFcnParam(S, (0x16b4+1251-0x1b94))
#define zbeff7d4e04        ssGetSFcnParam(S, (0xbcc+5282-0x206a))
#define za42e288061              ssGetSFcnParam(S, (0xae3+2180-0x1362))
#define z3832b85a32         ssGetSFcnParam(S, (0xc4+4660-0x12f2))
#define z702a26a5e9              ssGetSFcnParam(S, (0xb8+5100-0x149d))
#define z2e6483d505              ((0x228+185-0x2e0))
#define zc5ce4cb81a              ((0x97c+1548-0xf88))
#define z2b17e2ee3b              ((0x127+8564-0x229b))
#define z6a0da049de         ((0x20f+493-0x3fc))
#define z0029de9784          (114688)
static char_T zea4cd01646[(0x135f+3589-0x2064)];struct zccf45b4cac{uint32_T z4da0d16710[(0x56b+8197-0x256e)];uint32_T zc78a7188e6[(0x18d+2868-0xcbf)];uint32_T mode[(0x610+7699-0x23e3)];uint32_T zf277fad9fc[(0x20ed+1039-0x24bc)];uint32_T ze1c0f7736d[(0x1c99+556-0x1e85)];uint32_T z26f345a067[(0x1996+1239-0x1e2d)];};static void mdlInitializeSizes(SimStruct*S){uint32_T i,za0df33019b;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x6+9169-0x23d7));ssSetNumDiscStates(S,(0x4b+4302-0x1119));za0df33019b=(0xdc4+5277-0x2261);if(mxGetPr(z65adacaed7)[(0x186+6259-0x19f9)]){za0df33019b++;}if(mxGetPr(zcd0368f327)[(0x3ed+1427-0x980)]){za0df33019b++;}if(mxGetPr(zbeff7d4e04)[(0xe7f+3050-0x1a69)]){za0df33019b++;}ssSetNumOutputPorts(S,za0df33019b);for(i=(0x88c+7589-0x2631);i<za0df33019b;i++){ssSetOutputPortWidth(S,i,mxGetN(za9d8fb6bcf));}ssSetNumInputPorts(S,(0x699+2980-0x123d));
ssSetNumSampleTimes(S,(0x4e6+8743-0x270c));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x19f6+1414-0x1f7c));ssSetNumNonsampledZCs(S,(0x244+55-0x27b));for(i=(0x1804+964-0x1bc8);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xd7f+375-0xef6));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x1061+4322-0x2143)]==-1.0){ssSetSampleTime(S,(0x1245+3034-0x1e1f),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x929+5001-0x1cb2),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x124+8331-0x21af),mxGetPr(z3832b85a32)[(0x1006+1238-0x14dc)]);ssSetOffsetTime(S,(0x4ac+5117-0x18a9),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i;uint8_T z16ba527520[(0x9f6+4884-0x1cf6)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61,z4e3026977c,z4da0d16710,z46d3e78680;volatile struct zccf45b4cac*z565c99c453;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x241+8361-0x22ea)];z6f813cde47=z05b56d9d51=(0x1a99+8485-0x24e9);z6f813cde47=z05b56d9d51=(0x21a6+4094-0x1acf);switch(z78caf1ba61){case(0x11f5+1124-0x1518):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;case(0x2063+438-0x20ce):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;break;}if(mxGetN(z702a26a5e9)==(0x4ac+2463-0xe4a)){z366b2f03bf=(0xee2+2645-0x1937);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x80c+5017-0x1ba5)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x1531+1953-0x1cd2)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x9dd+6886-0x24c2)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x17cc+3504-0x257a)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x4f+9853-0x26ca)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x67d+2849-0x119c)]);z565c99c453=(struct zccf45b4cac*)(zeccbadd9b3.VirtAddress[(0x8ec+3619-0x170d)]+z0029de9784);if(!xpceIsModelInit()){z4da0d16710=z46d3e78680=(0x17e8+2308-0x20ec);for(i=(0x1744+577-0x1985);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xc04+4967-0x1f6a);if(z4e3026977c<(0x1818+1409-0x1d79)){z4da0d16710|=((0x1c1f+1539-0x2221)<<z4e3026977c);}else{z46d3e78680|=((0x4ad+691-0x75f)<<(z4e3026977c-(0xad7+2276-0x139b)));}z565c99c453->mode[z4e3026977c]=(uint32_T)mxGetPr(za42e288061)[i]-(0xd60+4349-0x1e5c);}z565c99c453->z4da0d16710[(0x6f7+2848-0x1217)]=z4da0d16710;z565c99c453->z4da0d16710[(0x1657+2602-0x2080)]=z46d3e78680;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint32_T i,z4e3026977c,zc78a7188e6,z944b9e6027,z0add1d1c25;uint32_T zde7140fd0d;real_T*y;volatile struct zccf45b4cac*z565c99c453=(struct zccf45b4cac*)(base+z0029de9784);z0add1d1c25=(0x484+2483-0xe37);zc78a7188e6=z944b9e6027=(0x689+2973-0x1226);zde7140fd0d=(0x1837+36-0x185b);for(i=(0x21a1+1095-0x25e8);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x2f1+927-0x68f);if((uint32_T)mxGetPr(za42e288061)[z4e3026977c]==(0x1f3+2349-0xb1c)){zde7140fd0d=(0x16+3619-0xe38);if(z4e3026977c<(0xa98+7315-0x270b)){zc78a7188e6|=(0x159b+3778-0x245c)<<z4e3026977c;}else{z944b9e6027|=(0x626+6285-0x1eb2)<<(z4e3026977c-(0x139+5489-0x168a));}}}if(zde7140fd0d){z565c99c453->zc78a7188e6[(0x172c+26-0x1746)]=zc78a7188e6;z565c99c453->zc78a7188e6[(0x39b+6963-0x1ecd)]=z944b9e6027;z565c99c453->zc78a7188e6[(0x1846+331-0x1991)]=(0x179+4642-0x139b);z565c99c453->zc78a7188e6[(0xfdd+739-0x12bf)]=(0x18a7+633-0x1b20);}if(mxGetPr(z65adacaed7)[(0x151b+1007-0x190a)]){y=(real_T*)ssGetOutputPortSignal(S,z0add1d1c25);z0add1d1c25++;for(i=(0x889+4678-0x1acf);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x2661+42-0x268a);y[i]=(real_T)z565c99c453->zf277fad9fc[z4e3026977c];}}if(mxGetPr(zcd0368f327)[(0x1017+77-0x1064)]){y=(real_T*)ssGetOutputPortSignal(S,z0add1d1c25);z0add1d1c25++;for(i=(0xe6a+1516-0x1456);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1fcf+1307-0x24e9);y[i]=(real_T)z565c99c453->ze1c0f7736d[z4e3026977c];}}if(mxGetPr(zbeff7d4e04)[(0x9a4+3289-0x167d)]){y=(real_T*)ssGetOutputPortSignal(S,z0add1d1c25);z0add1d1c25++;for(i=(0x5ca+2895-0x1119);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x3d2+4981-0x1746);y[i]=(real_T)z565c99c453->z26f345a067[z4e3026977c];}}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile struct zccf45b4cac*z565c99c453=(struct zccf45b4cac*)(base+z0029de9784);if(!xpceIsModelInit())
{z565c99c453->z4da0d16710[(0x10b2+3662-0x1f00)]=(0x10dc+89-0x1135);z565c99c453->z4da0d16710[(0xf6+6111-0x18d4)]=(0x1425+3148-0x2071);}
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif
