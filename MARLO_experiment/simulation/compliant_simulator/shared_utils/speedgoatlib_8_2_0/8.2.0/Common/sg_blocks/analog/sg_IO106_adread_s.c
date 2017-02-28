/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xd40+2869-0x1873)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO106_adread_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x30\x36"
#define z694756a014 (0x11c1+4728-0x1384)
#define zea87e0ba83 36950
#define z29146a1837 (0x1798+1504-0xcc3)
#define zab7e64468b 12545
#define zdf24515981          ((0x9ec+610-0xc47))
#define za8bff65d14              ssGetSFcnParam(S,(0x1c79+202-0x1d43))
#define z04bce731b0             ssGetSFcnParam(S,(0xdd+6674-0x1aee))
#define za9d8fb6bcf             ssGetSFcnParam(S,(0x967+5758-0x1fe3))
#define z8fd86139be               ssGetSFcnParam(S,(0x1290+5117-0x268a))
#define z8e37b80355            ssGetSFcnParam(S,(0x3dc+3467-0x1163))
#define z3832b85a32           ssGetSFcnParam(S,(0x781+8006-0x26c2))
#define z702a26a5e9                ssGetSFcnParam(S,(0x1e7b+236-0x1f61))
#define z2e6483d505              ((0xf25+1733-0x15e8))
#define z6a0da049de         ((0x17f2+1178-0x1c8c))
#define zc2f3e0cbc0        ((0xf10+5173-0x2344))
#define zc5ce4cb81a              ((0x22ff+490-0x24e7))
#define z8caad2a8e6              ((0x79c+1503-0xd7b))
#define z5bfe7a2613            ((0x105f+259-0x1161))
#define z2b17e2ee3b              ((0x1509+1204-0x19bd))
static char_T zea4cd01646[(0x13cc+632-0x1544)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x1c67+2032-0x2457));ssSetNumDiscStates(S,(0x1a41+2579-0x2454));if(!(boolean_T)mxGetPr(z04bce731b0)[(0xab+4850-0x139d)]){ssSetNumOutputPorts(S,(0x1118+4028-0x20d3));switch((uint32_T)mxGetPr(z8e37b80355)[(0x654+2970-0x11ee)]){case(0x957+5152-0x1d76):
ssSetOutputPortWidth(S,(0xcba+797-0xfd7),(uint32_T)mxGetPr(za9d8fb6bcf)[(0x10d3+5265-0x2564)]);break;case(0xdc4+4220-0x1e3e):
ssSetOutputPortWidth(S,(0x1d5+5458-0x1727),(uint32_T)mxGetPr(za9d8fb6bcf)[(0x1cb1+28-0x1ccd)]-(0x3dd+655-0x66b));break;case(0x968+2866-0x1497):
ssSetOutputPortWidth(S,(0x12ac+1432-0x1844),(uint32_T)mxGetPr(za9d8fb6bcf)[(0x94b+7485-0x2688)]);break;}}else{ssSetNumOutputPorts(S,(0x87b+3963-0x17f4));ssSetOutputPortDataType(S,(0x517+2308-0xe1b),SS_BOOLEAN);ssSetOutputPortWidth(S,(0x1415+3852-0x2321),(0x1085+3780-0x1f48));switch((uint32_T)mxGetPr(z8e37b80355)[(0x134c+906-0x16d6)]){case(0x194a+1974-0x20ff):
ssSetOutputPortWidth(S,(0x1916+2319-0x2224),(uint32_T)mxGetPr(za9d8fb6bcf)[(0x441+7683-0x2244)]);break;case(0x343+372-0x4b5):
ssSetOutputPortWidth(S,(0x17ab+2359-0x20e1),(uint32_T)mxGetPr(za9d8fb6bcf)[(0x469+5801-0x1b12)]-(0x187+5087-0x1565));break;case(0x993+7228-0x25cc):
ssSetOutputPortWidth(S,(0x218f+518-0x2394),(uint32_T)mxGetPr(za9d8fb6bcf)[(0xe04+4185-0x1e5d)]);break;}}if(!(boolean_T)mxGetPr(za8bff65d14)[(0xe7f+453-0x1044)]){ssSetNumInputPorts(S,(0xf4+6986-0x1c3e));}else{ssSetNumInputPorts(S,(0x14d1+2855-0x1ff7));ssSetInputPortDirectFeedThrough(S,(0xde8+5278-0x2286),(0x50a+288-0x629));ssSetInputPortWidth(S,(0xaa+7649-0x1e8b),(0xb94+4732-0x1e0f));ssSetInputPortDataType(S,(0xf37+1198-0x13e5),SS_BOOLEAN);ssSetInputPortRequiredContiguous(S,(0x791+5901-0x1e9e),(0x2c0+1887-0xa1e));}ssSetNumSampleTimes(S,(0xe4b+1385-0x13b3));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1315+4138-0x233f));ssSetNumNonsampledZCs(S,(0x410+2005-0xbe5));for(i=(0xc30+717-0xefd);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x221f+305-0x2350));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x1018+1864-0x1760)]==-1.0){ssSetSampleTime(S,(0x20e5+908-0x2471),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x164+5095-0x154b),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x939+7542-0x26af),mxGetPr(z3832b85a32)[(0x34c+2040-0xb44)]);ssSetOffsetTime(S,(0x53+6459-0x198e),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T range,out;uint16_T z4e3026977c;uint32_T zf91d71c6d9=(uint32_T)mxGetPr(za9d8fb6bcf)[(0x1df4+1375-0x2353)];if((int_T)mxGetPr(z702a26a5e9)[(0xc14+5780-0x22a8)]<(0x877+357-0x9dc)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x166d+3891-0x259f)){z366b2f03bf=(0x14f2+42-0x151c);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x160a+3422-0x2368)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0xa3c+4657-0x1c6d)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x517+3079-0x111d)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x19d6+101-0x193c))|((z366b2f03bf&(0x18e6+604-0x1a43))<<(0x6f5+3715-0x1570)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x19f5+605-0x1c50)];Virtual=rl32eGetDevicePtr(z1cf2c50191,(0x1a60+2957-0x256d),RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);ssSetIWorkValue(S,zc2f3e0cbc0,(uint32_T)zf91d71c6d9);
switch((uint32_T)mxGetPr(z8fd86139be)[(0xd0a+1887-0x1469)]){case(0xa3+2789-0xb87):
ssSetRWorkValue(S,z8caad2a8e6,3276.8);ssSetRWorkValue(S,z5bfe7a2613,10.0);break;case(0x689+7195-0x22a2):
ssSetRWorkValue(S,z8caad2a8e6,6553.6);ssSetRWorkValue(S,z5bfe7a2613,5.0);break;case(0x1c6+3212-0xe4f):
ssSetRWorkValue(S,z8caad2a8e6,13107.2);ssSetRWorkValue(S,z5bfe7a2613,2.5);break;case(0x240+1133-0x6a9):
ssSetRWorkValue(S,z8caad2a8e6,6553.6);ssSetRWorkValue(S,z5bfe7a2613,0.0);break;case(0x19db+3368-0x26fe):
ssSetRWorkValue(S,z8caad2a8e6,13107.2);ssSetRWorkValue(S,z5bfe7a2613,0.0);break;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T zf91d71c6d9=ssGetIWorkValue(S,zc2f3e0cbc0);volatile uint32_T*za42cf7dd4a;uint32_T z8b9d33e44f=(uint32_T)mxGetPr(z8e37b80355)[(0x1e96+1515-0x2481)];real_T*y,z0754dd67cc,offset;uint32_T i;uint32_T count;uint32_T z4314ccb6ec=(0x1240+4164-0x2284);boolean_T*z0daf90e5e1;boolean_T enabled=true;
if((int)mxGetPr(za8bff65d14)[(0xd4d+6573-0x26fa)]){z0daf90e5e1=(boolean_T*)ssGetInputPortSignal(S,(0x17b2+657-0x1a43));enabled=z0daf90e5e1[(0x1301+3958-0x2277)];}if((int)mxGetPr(z04bce731b0)[(0xb68+5461-0x20bd)]){z0daf90e5e1=(boolean_T*)ssGetOutputPortSignal(S,(0x849+1581-0xe76));z0daf90e5e1[(0xdb9+5585-0x238a)]=enabled;z4314ccb6ec=(0x54b+4875-0x1855);}za42cf7dd4a=(void*)base;y=ssGetOutputPortSignal(S,z4314ccb6ec);z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6);offset=ssGetRWorkValue(S,z5bfe7a2613);if(enabled){i=(0x46d+5762-0x1aef);
while(!(za42cf7dd4a[(0x8+1110-0x45b)]&524288))i++;

count=za42cf7dd4a[(0x50d+8206-0x2519)];if(count!=65537){printf("\x73\x6f\x6d\x65\x74\x68\x69\x6e\x67\x20\x73\x74\x72\x61\x6e\x67\x65" "\n");}for(i=(0x2ba+7533-0x2027);i<zf91d71c6d9/(0xe0a+909-0x1195);i++){
count=za42cf7dd4a[(0x302+2416-0xc70)];if(z8b9d33e44f==(0x11b3+3995-0x214c)){if(i==(0x515+2489-0xece)){y[(0x58d+6287-0x1e1b)+i*(0xb5f+2416-0x14cd)-(0xbd+8193-0x20bd)]=2.0*((real_T)((count&4294901760)>>(0x8ac+2475-0x1247))/z0754dd67cc-offset);}else{y[(0x133d+4760-0x25d5)+i*(0x304+5757-0x197f)-(0x4c4+408-0x65b)]=2.0*((real_T)(count&65535)/z0754dd67cc-offset);y[(0x1cd6+691-0x1f88)+i*(0x1211+4460-0x237b)-(0x10e2+2736-0x1b91)]=2.0*((real_T)((count&4294901760)>>(0x1089+3970-0x1ffb))/z0754dd67cc-offset);}}else{if(z8b9d33e44f==(0x441+4683-0x1689)){y[(0x16ad+535-0x18c4)+i*(0xc5+8066-0x2045)]=2.0*((real_T)(count&65535)/z0754dd67cc-offset);y[(0x1c97+2224-0x2546)+i*(0xb13+4365-0x1c1e)]=2.0*((real_T)((count&4294901760)>>(0x109a+1983-0x1849))/z0754dd67cc-offset);}else{y[(0x1ac8+1909-0x223d)+i*(0x16f0+827-0x1a29)]=(real_T)(count&65535)/z0754dd67cc-offset;y[(0xc3d+1277-0x1139)+i*(0x970+20-0x982)]=(real_T)((count&4294901760)>>(0x8c2+6988-0x23fe))/z0754dd67cc-offset;}}}za42cf7dd4a[(0x95d+2788-0x143e)]=za42cf7dd4a[(0xa7a+6598-0x243d)]|262144;}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

