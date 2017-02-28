/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x115b+4559-0x2328)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_qadcwrite_sf
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
#define zdf24515981              ((0x1e86+1909-0x25f7))
#define z702a26a5e9                    ssGetSFcnParam(S,(0x9fd+7118-0x25cb))
#define z3832b85a32               ssGetSFcnParam(S,(0x4f5+0-0x4f4))
#define za9d8fb6bcf                 ssGetSFcnParam(S,(0xccc+1743-0x1399))
#define z533b11d03f               ssGetSFcnParam(S,(0x99+7578-0x1e30))
#define z2e6483d505              ((0xf1+8649-0x22b8))
#define z7e2eeaa57c          ((0x8c5+4896-0x1be5))
#define z6a0da049de         ((0xbe9+5449-0x2131))
#define zc5ce4cb81a              ((0xae0+6924-0x25dc))
#define z2b17e2ee3b              ((0x35b+7913-0x2244))
static char_T zea4cd01646[(0x52f+2209-0xcd0)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x595+1244-0xa71));ssSetNumDiscStates(S,(0xb30+1507-0x1113));ssSetNumOutputPorts(S,(0x15b4+2020-0x1d98));ssSetNumInputPorts(S,(0x970+4234-0x19f7));ssSetInputPortWidth(S,(0xad4+5621-0x20c9),mxGetN(za9d8fb6bcf));ssSetInputPortDataType(S,(0x1aea+2561-0x24eb),SS_INT32);ssSetInputPortRequiredContiguous(S,(0x7cc+1755-0xea7),(0x752+3226-0x13eb));ssSetInputPortWidth(S,(0x84a+3487-0x15e8),mxGetN(za9d8fb6bcf));ssSetInputPortDataType(S,(0x2065+1099-0x24af),SS_BOOLEAN);ssSetInputPortRequiredContiguous(S,(0xf2+3080-0xcf9),(0x1dfb+55-0x1e31));ssSetInputPortWidth(S,(0x5e7+1938-0xd77),mxGetN(za9d8fb6bcf));ssSetInputPortDataType(S,(0x765+5581-0x1d30),SS_BOOLEAN);ssSetInputPortRequiredContiguous(S,(0x13eb+1018-0x17e3),(0x170d+1210-0x1bc6));ssSetNumSampleTimes(S,(0x1b67+1516-0x2152));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x136b+4837-0x2650));ssSetNumNonsampledZCs(S,(0x57c+6650-0x1f76));for(i=(0xe1a+1460-0x13ce);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1810+774-0x1b16));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0xf88+4403-0x20bb)]==-1.0){ssSetSampleTime(S,(0xc3f+6441-0x2568),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xec5+1908-0x1639),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x7+7189-0x1c1c),mxGetPr(z3832b85a32)[(0xf4a+5480-0x24b2)]);ssSetOffsetTime(S,(0x2e0+4029-0x129d),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint8_T z16ba527520[(0x5d3+5525-0x1b54)];uint16_T z6f813cde47,za4a2434e08;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x330+5129-0x1739)];switch(z78caf1ba61){case(0x297+6776-0x1be2):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");z6f813cde47=(0x1e44+1393-0xce0);za4a2434e08=17232;break;case(0x7f8+7963-0x25e5):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");z6f813cde47=5845;za4a2434e08=17239;break;case(0xfa5+3265-0x1b37):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");z6f813cde47=5845;za4a2434e08=16979;break;case(0x221+4900-0x1415):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");z6f813cde47=(0x1a80+8255-0x23ea);za4a2434e08=(0x91d+8863-0x26b8);break;case(0x9a9+5358-0x1d60):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");z6f813cde47=(0x23df+903-0x1091);za4a2434e08=21069;break;case(0x2b4+4078-0x116a):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");z6f813cde47=(0x1b25+1266-0x942);za4a2434e08=16971;break;case(0x7c0+7763-0x24da):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");z6f813cde47=(0x1b08+2348-0xd5f);za4a2434e08=17235;break;case(0x9a6+2307-0x116f):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");z6f813cde47=5845;za4a2434e08=8196;break;case(0x1287+3274-0x1e10):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");z6f813cde47=(0x1e90+1772-0xea7);za4a2434e08=19520;break;}
if((int_T)mxGetPr(z702a26a5e9)[(0x1e99+2135-0x26f0)]<(0xbda+1922-0x135c)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x8d4+4625-0x1ae4)){z366b2f03bf=(0x4a7+4165-0x14ec);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x36c+823-0x6a3)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x1c95+2250-0x255f)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x69+5991-0x17cf)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x5d3+1467-0xa8f))|((z366b2f03bf&(0xdc3+5990-0x242a))<<(0x144a+2864-0x1f72)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x29c+6541-0x1c27)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;uint32_T*za4749e65b3;boolean_T*zf85a1f44ea;uint32_T i,z52754d10b7,z4e3026977c;za42cf7dd4a=(void*)base;
za4749e65b3=(int32_T*)ssGetInputPortSignal(S,(0x15e6+2704-0x2076));for(i=(0xe43+3410-0x1b95);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x3a+3151-0xc88);za42cf7dd4a[9792+z4e3026977c]=za4749e65b3[i];}
zf85a1f44ea=(boolean_T*)ssGetInputPortSignal(S,(0x9c2+5935-0x20f0));z52754d10b7=za42cf7dd4a[9906];for(i=(0xf1f+5835-0x25ea);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xb57+6369-0x2437);if(zf85a1f44ea[i])z52754d10b7|=(0x59b+5546-0x1b44)<<z4e3026977c;else z52754d10b7&=~((0x71f+6392-0x2016)<<z4e3026977c);}za42cf7dd4a[9906]=z52754d10b7;
zf85a1f44ea=(boolean_T*)ssGetInputPortSignal(S,(0x1d11+1069-0x213c));z52754d10b7=za42cf7dd4a[9907];for(i=(0x2f3+5372-0x17ef);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xce3+4139-0x1d0d);if(zf85a1f44ea[i])z52754d10b7|=(0x61f+7424-0x231e)<<z4e3026977c;else z52754d10b7&=~((0x99c+1480-0xf63)<<z4e3026977c);}za42cf7dd4a[9907]=z52754d10b7;
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

