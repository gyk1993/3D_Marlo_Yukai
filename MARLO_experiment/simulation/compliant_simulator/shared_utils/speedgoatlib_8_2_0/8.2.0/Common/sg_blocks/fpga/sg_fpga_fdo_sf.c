/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x3ea+5191-0x182f)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_fdo_sf
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
#define zdf24515981          ((0x890+5768-0x1f12))
#define z533b11d03f           ssGetSFcnParam(S,(0x263+893-0x5e0))
#define ze072c43310               ssGetSFcnParam(S,(0x237+7242-0x1e80))
#define z2cc9a52544            ssGetSFcnParam(S,(0x217+6529-0x1b96))
#define zbcb3e4d083              ssGetSFcnParam(S,(0x148b+4479-0x2607))
#define z3832b85a32           ssGetSFcnParam(S,(0x82d+2269-0x1106))
#define z702a26a5e9                ssGetSFcnParam(S,(0x140b+293-0x152b))
#define z2e6483d505              ((0xb15+4869-0x1e18))
#define z6a0da049de         ((0x4a6+1141-0x91b))
#define zc2f3e0cbc0        ((0x824+2054-0x1029))
#define zc5ce4cb81a              ((0x487+5379-0x198a))
#define z2b17e2ee3b              ((0x660+2642-0x10b2))
#define THRESHOLD               0.5
#define z912da550ff                 (0x615+2921-0x117d)
#define zfdfce9fcd3                 (0x16fc+691-0x19ad)
#define z4e6712de2b                 (0x65c+5374-0x1b57)
static char_T zea4cd01646[(0x1d4d+2632-0x2695)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;uint16_T z5c3a9b25b9;uint32_T z78caf1ba61;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x284+8797-0x24e1));ssSetNumDiscStates(S,(0x943+446-0xb01));ssSetNumOutputPorts(S,(0x10e8+4590-0x22d6));if((int_T)mxGetPr(zbcb3e4d083)[(0x708+2270-0xfe6)]==z912da550ff){z5c3a9b25b9=(0x1b0c+490-0x1cd8);switch((uint8_T)mxGetPr(z2cc9a52544)[(0x1aa+8139-0x2175)]){case(0x1cb+4511-0x1369):ssSetNumInputPorts(S,z5c3a9b25b9);for(i=(0x316+2615-0xd4d);i<z5c3a9b25b9;i++){ssSetInputPortWidth(S,i,(0x2f2+795-0x60c));ssSetInputPortRequiredContiguous(S,i,(0xc00+5132-0x200b));}break;case(0x297+5213-0x16f2):ssSetNumInputPorts(S,z5c3a9b25b9);for(i=(0x1ae6+2626-0x2528);i<z5c3a9b25b9;i++){ssSetInputPortWidth(S,i,(0xce3+242-0xdd4));ssSetInputPortDataType(S,i,SS_BOOLEAN);ssSetInputPortRequiredContiguous(S,i,(0x34a+4903-0x1670));}break;case(0x127f+4757-0x2511):ssSetNumInputPorts(S,(0xac9+6261-0x233d));ssSetInputPortWidth(S,(0x1a64+2276-0x2348),z5c3a9b25b9);ssSetInputPortRequiredContiguous(S,(0x1266+4531-0x2419),(0xaa8+5999-0x2216));break;case(0xccd+5970-0x241b):ssSetNumInputPorts(S,(0xc9+7554-0x1e4a));ssSetInputPortWidth(S,(0x89a+1147-0xd15),z5c3a9b25b9);ssSetInputPortDataType(S,(0x19e2+1311-0x1f01),SS_BOOLEAN);ssSetInputPortRequiredContiguous(S,(0x12ff+5111-0x26f6),(0xe01+5720-0x2458));break;case(0x93+8517-0x21d3):ssSetNumInputPorts(S,(0x311+3606-0x1126));ssSetInputPortWidth(S,(0xdd2+2866-0x1904),(0x72a+6797-0x21b6));ssSetInputPortDataType(S,(0x1fb+361-0x364),SS_UINT32);ssSetInputPortRequiredContiguous(S,(0x7aa+1212-0xc66),(0x1db7+354-0x1f18));break;}}else if((int_T)mxGetPr(zbcb3e4d083)[(0xc22+729-0xefb)]==zfdfce9fcd3){if((uint32_T)mxGetPr(ze072c43310)[(0x172a+137-0x17b3)]==(0x764+5095-0x1b4a)){z5c3a9b25b9=(0x2025+679-0x22bc);}else{z5c3a9b25b9=(0x12d+3269-0xddc);}switch((uint8_T)mxGetPr(z2cc9a52544)[(0x56c+6517-0x1ee1)]){case(0x1b9d+706-0x1e5e):ssSetNumInputPorts(S,z5c3a9b25b9);for(i=(0x796+7753-0x25df);i<z5c3a9b25b9;i++){ssSetInputPortWidth(S,i,(0x888+209-0x958));ssSetInputPortRequiredContiguous(S,i,(0x8f0+4614-0x1af5));}break;case(0x181b+908-0x1ba5):ssSetNumInputPorts(S,z5c3a9b25b9);for(i=(0x11eb+4400-0x231b);i<z5c3a9b25b9;i++){ssSetInputPortWidth(S,i,(0x65b+5168-0x1a8a));ssSetInputPortDataType(S,i,SS_BOOLEAN);ssSetInputPortRequiredContiguous(S,i,(0xd88+1775-0x1476));}break;case(0x365+6040-0x1afa):ssSetNumInputPorts(S,(0x5ed+3659-0x1437));ssSetInputPortWidth(S,(0x5d3+4706-0x1835),z5c3a9b25b9);ssSetInputPortRequiredContiguous(S,(0x4f6+7681-0x22f7),(0x516+6551-0x1eac));break;case(0xbe6+4487-0x1d69):ssSetNumInputPorts(S,(0x1bed+1037-0x1ff9));ssSetInputPortWidth(S,(0x102b+2537-0x1a14),z5c3a9b25b9);ssSetInputPortDataType(S,(0x5a+5023-0x13f9),SS_BOOLEAN);ssSetInputPortRequiredContiguous(S,(0x1097+4999-0x241e),(0x259+6402-0x1b5a));break;case(0xd08+5485-0x2270):ssSetNumInputPorts(S,(0x561+7356-0x221c));ssSetInputPortWidth(S,(0x4dc+3621-0x1301),(0xca9+592-0xef8));ssSetInputPortDataType(S,(0x200+6874-0x1cda),SS_UINT32);ssSetInputPortRequiredContiguous(S,(0x1539+360-0x16a1),(0x116+2059-0x920));break;}}ssSetNumSampleTimes(S,(0x143f+2841-0x1f57));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x839+4481-0x19ba));ssSetNumNonsampledZCs(S,(0x185c+913-0x1bed));for(i=(0x1051+2039-0x1848);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x641+1311-0xb60));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x1387+678-0x162d)]==-1.0){ssSetSampleTime(S,(0x1487+791-0x179e),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x17c8+1325-0x1cf5),
FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x17cf+2442-0x2159),mxGetPr(z3832b85a32)[(0x1be0+1480-0x21a8)]);ssSetOffsetTime(S,(0x887+767-0xb86),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zef529fae4a;void*ze2370ae9b9;volatile uint32_T*z3e5b8e05d8;void*zdfcb1da404;void*zf2db5722bf;volatile uint32_T*z27fd94ac66;uint_T i;uint32_T out;uint8_T z16ba527520[(0x12d9+1310-0x17e3)];uint16_T z6f813cde47,za4a2434e08;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x197a+1984-0x213a)];switch(z78caf1ba61){case(0x1d55+2251-0x24df):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");z6f813cde47=(0x2573+3504-0x1c4e);za4a2434e08=19520;break;}if((int_T)mxGetPr(z702a26a5e9)[(0x11e6+4142-0x2214)]<(0x4ed+8449-0x25ee)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xf13+3136-0x1b52)){z366b2f03bf=(0x6f8+7078-0x229e);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1356+1221-0x181b)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x9a6+2961-0x1537)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x421+2672-0xe90)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0xf3a+2483-0x17ee))|((z366b2f03bf&(0x1973+1581-0x1ea1))<<(0x905+2688-0x137d)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zef529fae4a=(void*)zeccbadd9b3.BaseAddress[(0x16bc+2948-0x223e)];ze2370ae9b9=rl32eGetDevicePtr(zef529fae4a,2097152,RT_PG_USERREADWRITE);z3e5b8e05d8=(volatile uint32_T*)ze2370ae9b9;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)z3e5b8e05d8);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*z3e5b8e05d8;uint32_T i,output;real_T*y1;boolean_T*y2;uint32_T*z671e76e748;uint16_T z5c3a9b25b9;z3e5b8e05d8=(void*)base;if((uint8_T)mxGetPr(zbcb3e4d083)[(0x107+8742-0x232d)]==z912da550ff){z5c3a9b25b9=(0x1e0a+1231-0x22bb);switch((uint8_T)mxGetPr(z2cc9a52544)[(0x2f3+3467-0x107e)]){case(0x1016+3598-0x1e23):output=(0xdea+2837-0x18ff);for(i=(0x1b22+1059-0x1f45);i<z5c3a9b25b9;i++){y1=(real_T*)ssGetInputPortSignal(S,i);if(y1[(0x307+722-0x5d9)]>=THRESHOLD){output|=(0xb90+2335-0x14ae)<<i;}}break;case(0x9a0+463-0xb6d):output=(0xf6+46-0x124);for(i=(0x42c+3638-0x1262);i<z5c3a9b25b9;i++){y2=(boolean_T*)ssGetInputPortSignal(S,i);if(y2[(0x1958+1906-0x20ca)]){output|=(0x1226+4404-0x2359)<<i;}}break;case(0x652+2053-0xe54):output=(0x39c+6087-0x1b63);y1=(real_T*)ssGetInputPortSignal(S,(0x313+5092-0x16f7));for(i=(0x1dd0+181-0x1e85);i<z5c3a9b25b9;i++){if(y1[i]>=THRESHOLD){output|=(0x7f4+544-0xa13)<<i;}}break;case(0x136f+3739-0x2206):output=(0xd3d+4644-0x1f61);y2=(boolean_T*)ssGetInputPortSignal(S,(0x1330+420-0x14d4));for(i=(0x9bc+2935-0x1533);i<z5c3a9b25b9;i++){if(y2[i]){output|=(0x1082+5762-0x2703)<<i;}}break;case(0x97a+5555-0x1f28):z671e76e748=(uint32_T*)ssGetInputPortSignal(S,(0x6af+97-0x710));output=z671e76e748[(0x13f9+1808-0x1b09)];break;}z3e5b8e05d8[8193]=output;}else if((uint8_T)mxGetPr(zbcb3e4d083)[(0xc4b+1891-0x13ae)]==zfdfce9fcd3){if((uint32_T)mxGetPr(ze072c43310)[(0x8c+5542-0x1632)]==(0x7ba+960-0xb79)){z5c3a9b25b9=(0x1f21+1746-0x25e3);}else{z5c3a9b25b9=(0x19+141-0x90);}switch((uint8_T)mxGetPr(z2cc9a52544)[(0x10c6+1044-0x14da)]){case(0x1ef5+958-0x22b2):output=(0x1439+2485-0x1dee);for(i=(0x732+3650-0x1574);i<z5c3a9b25b9;i++){y1=(real_T*)ssGetInputPortSignal(S,i);if(y1[(0x14ed+2926-0x205b)]>=THRESHOLD){output|=(0x53b+6250-0x1da4)<<i;}}break;case(0x824+1789-0xf1f):output=(0x1020+658-0x12b2);for(i=(0x150+3886-0x107e);i<z5c3a9b25b9;i++){y2=(boolean_T*)ssGetInputPortSignal(S,i);if(y2[(0x1136+809-0x145f)]){output|=(0xaa6+6637-0x2492)<<i;}}break;case(0x882+3697-0x16f0):output=(0x1adb+1923-0x225e);y1=(real_T*)ssGetInputPortSignal(S,(0x67+9303-0x24be));for(i=(0x1e5+6339-0x1aa8);i<z5c3a9b25b9;i++){if(y1[i]>=THRESHOLD){output|=(0x1618+4031-0x25d6)<<i;}}break;case(0x11df+4221-0x2258):output=(0x548+1512-0xb30);y2=(boolean_T*)ssGetInputPortSignal(S,(0x26+3733-0xebb));for(i=(0x5c4+344-0x71c);i<z5c3a9b25b9;i++){if(y2[i]){output|=(0x12e8+65-0x1328)<<i;}}break;case(0x1060+3668-0x1eaf):z671e76e748=(uint32_T*)ssGetInputPortSignal(S,(0x7a+2397-0x9d7));output=z671e76e748[(0x2fc+8990-0x261a)];break;}if((uint32_T)mxGetPr(ze072c43310)[(0x4d5+1569-0xaf6)]==(0x286+257-0x386)){z3e5b8e05d8[8195]=output;}else{
z3e5b8e05d8[8193]=(output<<(0x1c38+526-0x1e3e));}}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

