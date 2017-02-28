/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xf4c+2944-0x1aca)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_spiwrite_sf
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
#define zdf24515981              ((0x7ab+5833-0x1e6f))
#define z533b11d03f               ssGetSFcnParam(S,(0x528+2945-0x10a9))
#define za9d8fb6bcf                 ssGetSFcnParam(S,(0x1f71+1677-0x25fd))
#define z3d4ad966bd                   ssGetSFcnParam(S,(0x1693+1695-0x1d30))
#define z3832b85a32               ssGetSFcnParam(S,(0x362+729-0x638))
#define z702a26a5e9                    ssGetSFcnParam(S,(0x4b5+4647-0x16d8))
#define z2e6483d505              ((0x18dc+3221-0x256f))
#define z7e2eeaa57c          ((0xfc7+2024-0x17af))
#define z6a0da049de         ((0x9e4+4845-0x1cd0))
#define zc5ce4cb81a              ((0x48+9428-0x250c))
#define z2b17e2ee3b              ((0x874+3693-0x16e1))
static char_T zea4cd01646[(0x15a8+3490-0x224a)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}
#ifdef MATLAB_MEX_FILE
#endif
ssSetNumContStates(S,(0x427+6944-0x1f47));ssSetNumDiscStates(S,(0x66b+3513-0x1424));ssSetNumOutputPorts(S,(0x8e1+2958-0x146f));ssSetNumInputPorts(S,(0xbb1+2340-0x14d4));ssSetInputPortDataType(S,(0x183c+778-0x1b46),SS_DOUBLE);ssSetInputPortMatrixDimensions(S,(0x1daa+1217-0x226b),(uint32_T)mxGetPr(z3d4ad966bd)[(0x584+1764-0xc68)]+(0x1150+4748-0x23db),mxGetN(za9d8fb6bcf));ssSetInputPortDirectFeedThrough(S,(0x1d22+96-0x1d82),(0xe49+608-0x10a8));ssSetInputPortRequiredContiguous(S,(0x46f+862-0x7cd),(0x90a+2808-0x1401));ssSetNumSampleTimes(S,(0x201a+37-0x203e));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x10d6+5009-0x2467));ssSetNumNonsampledZCs(S,(0xc70+1454-0x121e));for(i=(0xa1a+5099-0x1e05);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x4ad+3641-0x12e6));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x8d6+7366-0x259c)]==-1.0){ssSetSampleTime(S,(0x1e6d+1494-0x2443),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x31a+8223-0x2339),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x19f7+1546-0x2001),mxGetPr(z3832b85a32)[(0xa8b+583-0xcd2)]);ssSetOffsetTime(S,(0xedf+3362-0x1c01),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint8_T z16ba527520[(0x1af0+868-0x1e40)];uint16_T z6f813cde47,za4a2434e08;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0xd2b+4461-0x1e98)];switch(z78caf1ba61){case(0x422+2886-0xe3b):strcpy(z16ba527520,"\x49\x4f\x33\x30\x31");z6f813cde47=(0x2393+1540-0x12c2);za4a2434e08=17232;break;case(0x237b+825-0x2586):strcpy(z16ba527520,"\x49\x4f\x33\x30\x32");z6f813cde47=(0x1ff6+3678-0x177f);za4a2434e08=17239;break;case(0xa51+5280-0x1dc2):strcpy(z16ba527520,"\x49\x4f\x33\x30\x33");z6f813cde47=(0x22f0+5904-0x232b);za4a2434e08=16979;break;case(0x1a90+518-0x1b66):strcpy(z16ba527520,"\x49\x4f\x33\x30\x34");z6f813cde47=(0x1ab9+8171-0x23cf);za4a2434e08=(0x1047+638-0xdc1);break;case(0xcdf+2769-0x1679):strcpy(z16ba527520,"\x49\x4f\x33\x31\x31");z6f813cde47=5845;za4a2434e08=21069;break;case(0x10ba+3232-0x1c22):strcpy(z16ba527520,"\x49\x4f\x33\x31\x32");z6f813cde47=5845;za4a2434e08=16971;break;case(0x1318+1169-0x1670):strcpy(z16ba527520,"\x49\x4f\x33\x31\x33");z6f813cde47=(0x264a+5331-0x2448);za4a2434e08=17235;break;case(0x1b49+1278-0x1f0d):strcpy(z16ba527520,"\x49\x4f\x33\x31\x34");z6f813cde47=(0x1705+857-0x389);za4a2434e08=(0x2624+1940-0xdb4);break;case(0x1fc9+859-0x21e3):strcpy(z16ba527520,"\x49\x4f\x33\x32\x31");z6f813cde47=(0x16ef+8597-0x21af);za4a2434e08=19520;break;}if((int_T)mxGetPr(z702a26a5e9)[(0x1191+4336-0x2281)]<(0xc5d+1356-0x11a9)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x178+1653-0x7ec)){z366b2f03bf=(0x293+6831-0x1d42);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x13b0+2534-0x1d96)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x171a+3199-0x2399)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x6b2+63-0x6f0)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x838+7805-0x25b6))|((z366b2f03bf&(0xb70+5613-0x205e))<<(0x4fa+4370-0x1604)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0xb73+6366-0x244f)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint32_T i,z26dbd73a5e,width,z4e3026977c,count,z03312e422a;volatile uint32_T*za42cf7dd4a;real_T*data;
za42cf7dd4a=(void*)base;width=(uint8_T)mxGetPr(z3d4ad966bd)[(0x2200+1272-0x26f8)]+(0x33a+5590-0x190f);data=(real_T*)ssGetInputPortSignal(S,(0x1c1b+856-0x1f73));z03312e422a=(0x1645+1583-0x1c74);for(z26dbd73a5e=(0x536+4332-0x1622);z26dbd73a5e<mxGetN(za9d8fb6bcf);z26dbd73a5e++)
{z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[z26dbd73a5e]-(0xabb+6274-0x233c);count=za42cf7dd4a[10320+z4e3026977c];if(count>(0xe68+2706-0x18fa)){sprintf(zea4cd01646,"\x54\x72\x69\x65\x64\x20\x74\x6f\x20\x77\x72\x69\x74\x65\x20\x69\x6e\x20\x61\x20\x6e\x6f\x6e\x2d\x65\x6d\x70\x74\x79\x20\x62\x75\x66\x66\x65\x72");ssSetErrorStatus(S,zea4cd01646);return;}count=(uint32_T)data[z26dbd73a5e*width];for(i=(0x1739+1265-0x1c2a);i<count;i++)
{
za42cf7dd4a[10256+z4e3026977c]=(uint32_T)data[z26dbd73a5e*width+i+(0x8b3+5254-0x1d38)];
za42cf7dd4a[10304+z4e3026977c]=i;
za42cf7dd4a[10250]=((0x12e4+4858-0x25dd)<<z4e3026977c);za42cf7dd4a[10250]=(0x2161+560-0x2391);}
za42cf7dd4a[10320+z4e3026977c]=count;za42cf7dd4a[10249]=((0x1e30+2138-0x2689)<<z4e3026977c);za42cf7dd4a[10249]=(0x849+4340-0x193d);
}


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

