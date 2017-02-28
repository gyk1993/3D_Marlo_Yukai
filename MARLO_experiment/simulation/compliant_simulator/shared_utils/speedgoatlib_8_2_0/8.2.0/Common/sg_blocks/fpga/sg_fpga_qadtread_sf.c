/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x761+2988-0x130b)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_qadtread_sf
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
#define zdf24515981              ((0x9d9+206-0xaa2))
#define z702a26a5e9                    ssGetSFcnParam(S,(0x1980+2361-0x22b9))
#define z3832b85a32               ssGetSFcnParam(S,(0x2b0+4788-0x1563))
#define za9d8fb6bcf                 ssGetSFcnParam(S,(0x78f+6915-0x2290))
#define z533b11d03f               ssGetSFcnParam(S,(0x1db5+1202-0x2264))
#define z4eb7791e75           ssGetSFcnParam(S,(0xdbf+1088-0x11fb))
#define z2e6483d505              ((0x6e1+1161-0xb68))
#define z7e2eeaa57c          ((0xcdd+964-0x10a1))
#define z6a0da049de         ((0x2174+938-0x251d))
#define zc5ce4cb81a              ((0x1b1+6011-0x191c))
#define z2b17e2ee3b              ((0xae5+1870-0x1233))
static char_T zea4cd01646[(0x8dd+6303-0x207c)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x1189+4153-0x21c2));ssSetNumDiscStates(S,(0x1b68+2580-0x257c));ssSetNumOutputPorts(S,(0xce5+4046-0x1cb0));
ssSetOutputPortDataType(S,(0x3a4+4586-0x158e),SS_INT32);ssSetOutputPortWidth(S,(0x144a+1315-0x196d),mxGetN(za9d8fb6bcf));
ssSetOutputPortDataType(S,(0x11ac+746-0x1495),SS_BOOLEAN);ssSetOutputPortWidth(S,(0x17a2+3671-0x25f8),mxGetN(za9d8fb6bcf));
ssSetOutputPortDataType(S,(0xf4a+3034-0x1b22),SS_BOOLEAN);ssSetOutputPortWidth(S,(0x587+72-0x5cd),(0xa25+3758-0x18d2));ssSetNumInputPorts(S,(0x1d61+1058-0x2183));ssSetNumSampleTimes(S,(0x429+2580-0xe3c));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xaf7+6971-0x2632));ssSetNumNonsampledZCs(S,(0x38b+4340-0x147f));for(i=(0x1706+1425-0x1c97);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x47f+6628-0x1e63));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0xd4c+2788-0x1830)]==-1.0){ssSetSampleTime(S,(0xfea+20-0xffe),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x798+884-0xb0c),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x821+6476-0x216d),mxGetPr(z3832b85a32)[(0x2a4+3960-0x121c)]);ssSetOffsetTime(S,(0xd35+3412-0x1a89),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint_T i;uint32_T z7be9105675,z4e3026977c;real_T scale;uint8_T z16ba527520[(0xf66+4005-0x1ef7)];uint16_T z6f813cde47,za4a2434e08;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x113b+3894-0x2071)];switch(z78caf1ba61){case(0x14ef+4017-0x2373):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");z6f813cde47=(0x1895+1871-0x90f);za4a2434e08=17232;break;case(0xaab+970-0xd47):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");z6f813cde47=(0x23e1+796-0x1028);za4a2434e08=17239;break;case(0x24b+5981-0x1879):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");z6f813cde47=(0x26c6+317-0x112e);za4a2434e08=16979;break;case(0x214+679-0x38b):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");z6f813cde47=(0x1efb+6443-0x2151);za4a2434e08=(0x1040+2509-0x1509);break;case(0x699+1118-0x9c0):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");z6f813cde47=(0x212d+2987-0x1603);za4a2434e08=21069;break;case(0x67b+8542-0x26a1):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");z6f813cde47=(0x1e48+2832-0x1283);za4a2434e08=16971;break;case(0x807+1623-0xd25):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");z6f813cde47=(0x227a+6694-0x25cb);za4a2434e08=17235;break;case(0x14f1+2443-0x1d42):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");z6f813cde47=(0x1ddd+159-0x7a7);za4a2434e08=(0x2642+474-0x818);break;case(0xb46+3216-0x1695):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");z6f813cde47=(0x1e67+2182-0x1018);za4a2434e08=19520;break;}
if((int_T)mxGetPr(z702a26a5e9)[(0x1330+1111-0x1787)]<(0x43+4667-0x127e)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x4e2+649-0x76a)){z366b2f03bf=(0x13bb+3607-0x21d2);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1f83+1901-0x26f0)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x12d3+2786-0x1db5)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xd6b+3126-0x19a0)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x912+7490-0x2555))|((z366b2f03bf&(0x88c+1640-0xdf5))<<(0xcdf+6413-0x25e4)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x1254+360-0x13ba)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;uint32_T*za4749e65b3;boolean_T*zf85a1f44ea;uint32_T i,z4e3026977c,ze938c3d87d;za42cf7dd4a=(void*)base;if(mxGetPr(z4eb7791e75)[(0xea4+3593-0x1cad)]==(0x7f5+7573-0x2589)){za42cf7dd4a[9894]=(0x471+768-0x770);za42cf7dd4a[9894]=(0x2205+496-0x23f5);}zf85a1f44ea=(boolean_T*)ssGetOutputPortSignal(S,(0x1242+5278-0x26df));za4749e65b3=(int32_T*)ssGetOutputPortSignal(S,(0x1b79+2737-0x262a));ze938c3d87d=(uint32_T)za42cf7dd4a[9889];for(i=(0x84b+1351-0xd92);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x18d0+368-0x1a3f);za4749e65b3[i]=(int32_T)za42cf7dd4a[9824+z4e3026977c];zf85a1f44ea[i]=(boolean_T)((ze938c3d87d>>z4e3026977c)&(0x1013+1972-0x17c6));}zf85a1f44ea=(boolean_T*)ssGetOutputPortSignal(S,(0xc6a+772-0xf6c));zf85a1f44ea[(0x1d5+101-0x23a)]=(uint32_T)za42cf7dd4a[9897]&(0x1595+2813-0x2091);
za42cf7dd4a[9896]=(0x99a+2464-0x1339);za42cf7dd4a[9896]=(0x14c9+1663-0x1b48);
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;uint32_T*z8184bef3ae;za42cf7dd4a=(void*)base;if(mxGetPr(z4eb7791e75)[(0x4e5+3145-0x112e)]==(0xa94+3144-0x16db)){
za42cf7dd4a[9895]=(0x474+6708-0x1ea8);}if(mxGetPr(z4eb7791e75)[(0x1116+166-0x11bc)]==(0xc4+5306-0x157c)){
za42cf7dd4a[9895]=(0x94d+3722-0x17d6);}if(mxGetPr(z4eb7791e75)[(0xb91+3259-0x184c)]==(0xe11+4079-0x1dfd)){
za42cf7dd4a[9895]=(0x716+7200-0x2334);}
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

