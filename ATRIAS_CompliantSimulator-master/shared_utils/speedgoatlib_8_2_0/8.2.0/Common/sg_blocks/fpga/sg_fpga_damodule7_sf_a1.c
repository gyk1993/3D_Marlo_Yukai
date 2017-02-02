/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1831+2518-0x2205)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_damodule7_sf_a1
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
#define zdf24515981        ((0x143b+2658-0x1e95))
#define z533b11d03f         ssGetSFcnParam(S, (0x1877+1586-0x1ea9)) 
#define za9d8fb6bcf           ssGetSFcnParam(S, (0x78f+3062-0x1384)) 
#define z9ad049935d        ssGetSFcnParam(S, (0x1a89+1821-0x21a4))
#define z59bb2f4bac        ssGetSFcnParam(S, (0x4c8+4424-0x160d))
#define z962f28f429        ssGetSFcnParam(S, (0x1b60+2511-0x252b))
#define zad03d924d8              ssGetSFcnParam(S, (0x13ab+178-0x1458)) 
#define z3832b85a32         ssGetSFcnParam(S, (0x84+224-0x15e))
#define z702a26a5e9              ssGetSFcnParam(S, (0x20+537-0x232))
#define z2e6483d505              ((0x1b6+5121-0x15b6))
#define zc5ce4cb81a              ((0x4a5+4165-0x14ea))
#define z2b17e2ee3b              ((0x1715+473-0x18ee))
#define z6a0da049de         ((0x7af+5661-0x1dcc))
#define zf7dba45c7b                  (655360)
#define zd055b77bdc                         ((0x352+3267-0x1014))
#define z59a7b09cad                       ((0x5bd+3399-0x1302))
#define z893a26ca15                ((0x102b+621-0x1295))
#define zaa2f1194f3                    ((0x1df0+1216-0x22ac))
#define zde225cb98f    ((0x207+4036-0x11c6))
#define zd784dd3efd  ((0x7bd+923-0xb52))
static char_T zea4cd01646[(0xddf+3427-0x1a42)];struct z6e54179dbd{uint32_T zd7f607991c[(0x175+4879-0x1474)];uint32_T z64c973e715[(0x141c+1735-0x1ad3)];uint32_T z3a9c5f054e[(0x6bd+6870-0x2183)];uint32_T z4da0d16710;uint32_T z6a621e2ebc;uint32_T zfc0eea4f31;uint32_T za87b7c2ad3;uint32_T version;uint32_T revision;};static void mdlInitializeSizes(SimStruct*S){uint32_T i,za0df33019b;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x3f4+34-0x416));ssSetNumDiscStates(S,(0x4d0+3343-0x11df));za0df33019b=(0x6c+87-0xc3);
for(i=(0x1201+408-0x1399);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){if((uint32_T)mxGetPr(z9ad049935d)[i]==(0x2d2+800-0x5f2)){za0df33019b++;}}ssSetNumInputPorts(S,za0df33019b);for(i=(0x14b5+4356-0x25b9);i<za0df33019b;i++){ssSetInputPortWidth(S,i,(0x70b+6031-0x1e99));ssSetInputPortDirectFeedThrough(S,i,(0x19d+2630-0xbe2));ssSetInputPortRequiredContiguous(S,i,(0x10cc+1299-0x15de));}ssSetNumOutputPorts(S,(0x7b7+959-0xb76));ssSetNumSampleTimes(S,(0x539+5780-0x1bcc));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xed0+5756-0x254c));ssSetNumNonsampledZCs(S,(0xd7a+1471-0x1339));for(i=(0x86b+4485-0x19f0);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x25d+491-0x448));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x11d7+5148-0x25f3)]==-1.0){ssSetSampleTime(S,(0x2e7+5715-0x193a),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1da+5420-0x1706),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x1434+4278-0x24ea),mxGetPr(z3832b85a32)[(0x1056+1256-0x153e)]);ssSetOffsetTime(S,(0xcdd+5246-0x215b),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i;uint32_T z6a621e2ebc;uint8_T z16ba527520[(0x14bb+2897-0x1ff8)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61,z4e3026977c,z4da0d16710;volatile struct z6e54179dbd*zf1756dff08;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0xfb3+4888-0x22cb)];z6f813cde47=z05b56d9d51=(0x1c55+3872-0x14a0);switch(z78caf1ba61){case(0x137d+4497-0x23e1):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");za4a2434e08=z182d03571c=17232;break;case(0x467+7554-0x20bb):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");za4a2434e08=z182d03571c=17239;break;case(0x162+5698-0x1675):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");za4a2434e08=z182d03571c=16979;break;case(0xb1f+3828-0x18e3):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");za4a2434e08=z182d03571c=(0xb76+760-0x96a);break;case(0x137c+1557-0x185a):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");za4a2434e08=z182d03571c=21069;break;case 312:strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");za4a2434e08=z182d03571c=16971;break;case(0x119d+3699-0x1ed7):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");za4a2434e08=z182d03571c=17235;break;case(0x112d+5655-0x260a):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");za4a2434e08=z182d03571c=8196;break;case(0x19a7+2545-0x2257):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;case(0xcb5+5339-0x2045):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;break;}if(mxGetN(z702a26a5e9)==(0x1cbd+1610-0x2306)){z366b2f03bf=(0x625+4608-0x1825);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xcc9+5855-0x23a8)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0xe57+6262-0x26cd)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xe87+1493-0x145b)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x25c8+156-0x2662)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x18c8+2961-0x2457)],(void*)zeccbadd9b3.Length[(0x1d67+245-0x1e5a)],XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x1ca8+1288-0x21ae)]);zf1756dff08=(volatile struct z6e54179dbd*)(zeccbadd9b3.VirtAddress[(0x10d3+4045-0x209e)]+zf7dba45c7b);if(!xpceIsModelInit()){z6a621e2ebc=zf1756dff08->z6a621e2ebc;z4da0d16710=zf1756dff08->z4da0d16710;for(i=(0xdc4+1004-0x11b0);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x533+1989-0xcf7);z4da0d16710|=((0x1c1b+462-0x1de8)<<z4e3026977c);if((uint32_T)mxGetPr(z9ad049935d)[i]==(0xa0+5371-0x159a)){z6a621e2ebc|=((0x862+2882-0x13a3)<<z4e3026977c);}else{z6a621e2ebc&=~((0x74+350-0x1d1)<<z4e3026977c);}zf1756dff08->z3a9c5f054e[z4e3026977c]=(uint32_T)mxGetPr(z59bb2f4bac)[i]-(0xe25+6079-0x25e3);zf1756dff08->z64c973e715[z4e3026977c]=(uint32_T)mxGetPr(z962f28f429)[i]-(0xbe4+78-0xc31);}zf1756dff08->zfc0eea4f31=(uint32_T)mxGetPr(zad03d924d8)[(0x4b4+6608-0x1e84)]-(0xcf8+5703-0x233e);zf1756dff08->z6a621e2ebc=z6a621e2ebc;zf1756dff08->z4da0d16710=z4da0d16710;
}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T i,z4e3026977c,z2f1801d2e2,z0add1d1c25;volatile struct z6e54179dbd*zf1756dff08;real_T*in;uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T count;real_T z7de4111e09;zf1756dff08=(volatile struct z6e54179dbd*)(base+zf7dba45c7b);z2f1801d2e2=(0x7e0+4949-0x1b35);z0add1d1c25=(0x60c+5552-0x1bbc);for(i=(0xb43+5610-0x212d);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){if((uint32_T)mxGetPr(z9ad049935d)[i]==(0x1ad2+2099-0x2305)){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xa64+4877-0x1d70);z2f1801d2e2|=((0x62b+1876-0xd7e)<<z4e3026977c);in=(real_T*)ssGetInputPortSignal(S,z0add1d1c25);z7de4111e09=in[(0xe61+5261-0x22ee)];

if((uint32_T)mxGetPr(zad03d924d8)[(0x1d7+2401-0xb38)]==zaa2f1194f3){z7de4111e09+=10.0;count=(uint16_T)((z7de4111e09/20.0)*65535.0);}else if((uint32_T)mxGetPr(zad03d924d8)[(0x498+1770-0xb82)]==z59a7b09cad){z7de4111e09+=0.0;count=(uint16_T)((z7de4111e09/10.0)*65535.0);}else if((uint32_T)mxGetPr(zad03d924d8)[(0x1497+3949-0x2404)]==zde225cb98f){z7de4111e09+=2.5;count=(uint16_T)((z7de4111e09/5.0)*65535.0);}else if((uint32_T)mxGetPr(zad03d924d8)[(0x7d4+8-0x7dc)]==zd055b77bdc){z7de4111e09+=0.0;count=(uint16_T)((z7de4111e09/5.0)*65535.0);}else if((uint32_T)mxGetPr(zad03d924d8)[(0x739+1041-0xb4a)]==z893a26ca15){z7de4111e09+=5.0;count=(uint16_T)((z7de4111e09/10.0)*65535.0);}else if((uint32_T)mxGetPr(zad03d924d8)[(0xa9a+2871-0x15d1)]==zd784dd3efd){z7de4111e09+=2.5;count=(uint16_T)((z7de4111e09/10.0)*65535.0);}zf1756dff08->zd7f607991c[z4e3026977c]=count;z0add1d1c25++;}
if(z2f1801d2e2>(0x563+75-0x5ae)){zf1756dff08->za87b7c2ad3=z2f1801d2e2;zf1756dff08->za87b7c2ad3=(0x721+3210-0x13ab);}}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile struct z6e54179dbd*zf1756dff08=(struct z6e54179dbd*)(base+zf7dba45c7b);if(!xpceIsModelInit()){zf1756dff08->z4da0d16710=(0x2ef+8356-0x2393);

}
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif
