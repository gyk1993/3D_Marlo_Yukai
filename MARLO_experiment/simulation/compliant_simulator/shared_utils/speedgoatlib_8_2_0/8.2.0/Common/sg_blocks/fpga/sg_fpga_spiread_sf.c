/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x81f+5473-0x1d7e)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_spiread_sf
#include 	<stddef.h>
#include 	<stdlib.h>
#include 	"simstruc.h" 
#ifdef 		MATLAB_MEX_FILE
#include 	"mex.h"
#endif
#ifndef         MATLAB_MEX_FILE
#include        <windows.h>
#include        "io_xpcimport.h"
#include        "xpcPCFunctions.h"
#include        "pci_xpcimport.h"
#include        "time_xpcimport.h"
#include        "ioext_xpcimport.h"
#include        "util_xpcimport.h"
#endif
#define zdf24515981              ((0x90f+6095-0x20d8))
#define z533b11d03f               ssGetSFcnParam(S,(0x1cd9+1622-0x232f))
#define za9d8fb6bcf                 ssGetSFcnParam(S,(0x13d1+4281-0x2489))
#define z3d4ad966bd                   ssGetSFcnParam(S,(0x1924+1567-0x1f41))
#define zb0ce0940e9               ssGetSFcnParam(S,(0x7fd+7743-0x2639))
#define z3832b85a32               ssGetSFcnParam(S,(0x1168+1566-0x1782))
#define z702a26a5e9                    ssGetSFcnParam(S,(0x1830+3386-0x2565))
#define z2e6483d505              ((0x11b1+2911-0x1d0e))
#define z7e2eeaa57c          ((0x870+3277-0x153d))
#define z6a0da049de         ((0x5f5+1955-0xd97))
#define zc5ce4cb81a              ((0x194b+2029-0x2128))
#define z2b17e2ee3b              ((0x1047+296-0x116f))
static char_T zea4cd01646[(0x244+188-0x200)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x795+1775-0xe84));ssSetNumDiscStates(S,(0x18f9+1264-0x1de9));ssSetNumInputPorts(S,(0x1e08+1300-0x231c));ssSetNumOutputPorts(S,(0x1d09+2171-0x2583));ssSetOutputPortMatrixDimensions(S,(0x665+8145-0x2636),(uint32_T)mxGetPr(z3d4ad966bd)[(0x435+4314-0x150f)]+(0x79f+1534-0xd9c),mxGetN(za9d8fb6bcf));ssSetNumSampleTimes(S,(0x3a2+1326-0x8cf));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x41c+1446-0x9c2));ssSetNumNonsampledZCs(S,(0x1b39+2400-0x2499));for(i=(0xbb7+6797-0x2644);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x343+4129-0x1364));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x14d+893-0x4ca)]==-1.0){ssSetSampleTime(S,(0x231+2251-0xafc),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xbb9+6886-0x269f),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x1e7f+1877-0x25d4),mxGetPr(z3832b85a32)[(0x4ea+2463-0xe89)]);ssSetOffsetTime(S,(0x5bd+5425-0x1aee),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint8_T z16ba527520[(0x15f0+4018-0x258e)];uint16_T z6f813cde47,za4a2434e08;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0xce9+4185-0x1d42)];switch(z78caf1ba61){case(0x156b+4633-0x2657):strcpy(z16ba527520,"\x49\x4f\x33\x30\x31");z6f813cde47=(0x1b0f+1354-0x984);za4a2434e08=17232;break;case(0x996+5356-0x1d54):strcpy(z16ba527520,"\x49\x4f\x33\x30\x32");z6f813cde47=5845;za4a2434e08=17239;break;case(0x133c+1608-0x1855):strcpy(z16ba527520,"\x49\x4f\x33\x30\x33");z6f813cde47=(0x1d75+5336-0x1b78);za4a2434e08=16979;break;case(0xac5+3013-0x155a):strcpy(z16ba527520,"\x49\x4f\x33\x30\x34");z6f813cde47=5845;za4a2434e08=(0x749+2949-0xdca);break;case(0x1f91+1027-0x225d):strcpy(z16ba527520,"\x49\x4f\x33\x31\x31");z6f813cde47=(0x19b8+5273-0x177c);za4a2434e08=21069;break;case(0xfeb+4460-0x201f):strcpy(z16ba527520,"\x49\x4f\x33\x31\x32");z6f813cde47=5845;za4a2434e08=16971;break;case(0x5c2+7655-0x2270):strcpy(z16ba527520,"\x49\x4f\x33\x31\x33");z6f813cde47=(0x20e9+5861-0x20f9);za4a2434e08=17235;break;case(0x31b+3828-0x10d5):strcpy(z16ba527520,"\x49\x4f\x33\x31\x34");z6f813cde47=5845;za4a2434e08=(0x24e3+1581-0xb0c);break;case(0x108b+2087-0x1771):strcpy(z16ba527520,"\x49\x4f\x33\x32\x31");z6f813cde47=5845;za4a2434e08=19520;break;}if((int_T)mxGetPr(z702a26a5e9)[(0x16ad+1033-0x1ab6)]<(0x5aa+3562-0x1394)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x105f+5728-0x26be)){z366b2f03bf=(0x9e9+5735-0x2050);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xe16+21-0xe2b)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0xb26+1565-0x1143)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x631+8414-0x270e)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x1a2+1511-0x68a))|((z366b2f03bf&(0xec8+3068-0x19c5))<<(0xf41+5555-0x24ec)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x11b0+2266-0x1a88)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;uint8_T z26dbd73a5e,i,width;real_T*data;uint32_T z4e3026977c,status;za42cf7dd4a=(void*)base;data=ssGetOutputPortSignal(S,(0x1eb+5597-0x17c8));width=(uint8_T)mxGetPr(z3d4ad966bd)[(0x161+6770-0x1bd3)]+(0x610+4509-0x17ac);for(z26dbd73a5e=(0xbc5+2298-0x14bf);z26dbd73a5e<mxGetN(za9d8fb6bcf);z26dbd73a5e++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[z26dbd73a5e]-(0x77c+4043-0x1746);do{status=za42cf7dd4a[10252];}while((status&((0x4ec+99-0x54e)<<z4e3026977c))==(0x1504+1096-0x194c));for(i=(0x5+1973-0x7ba);i<(uint8_T)mxGetPr(z3d4ad966bd)[(0x107d+2199-0x1914)];i++){data[z26dbd73a5e*width+i]=(0x422+49-0x453);
}for(i=(0x424+8878-0x26d2);i<(uint8_T)mxGetPr(zb0ce0940e9)[z4e3026977c];i++){
za42cf7dd4a[10304+z4e3026977c]=i;

data[z26dbd73a5e*width+i+(0x11f9+747-0x14e3)]=(real_T)za42cf7dd4a[10272+z4e3026977c];}data[z26dbd73a5e*width]=mxGetPr(zb0ce0940e9)[z4e3026977c];

za42cf7dd4a[10251]=((0xf19+580-0x115c)<<z4e3026977c);za42cf7dd4a[10251]=(0x1021+230-0x1107);}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

