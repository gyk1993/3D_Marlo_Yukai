/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x508+4216-0x157e)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_spisreceive_sf
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
#include        "xpcPCFunctions.h"
#include        "time_xpcimport.h"
#include        "ioext_xpcimport.h"
#include        "util_xpcimport.h"
#endif
#define zdf24515981              ((0x619+1012-0xa08))
#define z533b11d03f               ssGetSFcnParam(S, (0x96d+2498-0x132f))
#define za9d8fb6bcf                 ssGetSFcnParam(S, (0x2b3+5919-0x19d1))
#define z3d4ad966bd                   ssGetSFcnParam(S, (0xac0+374-0xc34))
#define z3832b85a32               ssGetSFcnParam(S, (0x8f2+2943-0x146e))
#define z702a26a5e9                    ssGetSFcnParam(S, (0xac5+4162-0x1b03))
#define z2e6483d505              ((0x2599+71-0x25de))
#define z7e2eeaa57c          ((0xe8+4033-0x10a9))
#define z6a0da049de         ((0x15bf+2056-0x1dc6))
#define zc5ce4cb81a              ((0x806+1465-0xdaf))
#define z2b17e2ee3b              ((0x250+2421-0xbc5))
static char_T zea4cd01646[(0xdaa+2019-0x148d)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x168+4774-0x140e));ssSetNumDiscStates(S,(0x105c+5302-0x2512));ssSetNumOutputPorts(S,mxGetN(za9d8fb6bcf));for(i=(0x17a+4823-0x1451);i<mxGetN(za9d8fb6bcf);i++){ssSetOutputPortWidth(S,i,(uint32_T)mxGetPr(z3d4ad966bd)[(0x64c+1245-0xb29)]+(0x36d+8524-0x24b8));}ssSetNumSampleTimes(S,(0x13+1145-0x48b));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1da0+232-0x1e88));ssSetNumNonsampledZCs(S,(0x1790+1312-0x1cb0));for(i=(0xb62+6403-0x2465);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x8df+4978-0x1c51));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x666+6056-0x1e0e)]==-1.0){ssSetSampleTime(S,(0xe08+1115-0x1263),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xb5+9118-0x2453),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xac6+488-0xcae),mxGetPr(z3832b85a32)[(0x1576+98-0x15d8)]);ssSetOffsetTime(S,(0x18a8+1721-0x1f61),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint8_T z16ba527520[(0x13ec+2900-0x1f2c)];uint16_T z6f813cde47,za4a2434e08;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x6e7+1957-0xe8c)];switch(z78caf1ba61){case(0x3fd+275-0x3e3):strcpy(z16ba527520,"\x49\x4f\x33\x30\x31");z6f813cde47=(0x1e3c+2709-0x11fc);za4a2434e08=17232;break;case(0xd7f+3365-0x1976):strcpy(z16ba527520,"\x49\x4f\x33\x30\x32");z6f813cde47=5845;za4a2434e08=17239;break;case(0x10b0+4575-0x2160):strcpy(z16ba527520,"\x49\x4f\x33\x30\x33");z6f813cde47=(0x1975+371-0x413);za4a2434e08=16979;break;case(0x6ff+1089-0xa10):strcpy(z16ba527520,"\x49\x4f\x33\x30\x34");z6f813cde47=(0x223d+1004-0xf54);za4a2434e08=(0x97f+1686-0xb11);break;case(0x28d+4900-0x147a):strcpy(z16ba527520,"\x49\x4f\x33\x31\x31");z6f813cde47=5845;za4a2434e08=21069;break;case(0x6f9+2845-0x10de):strcpy(z16ba527520,"\x49\x4f\x33\x31\x32");z6f813cde47=5845;za4a2434e08=16971;break;case(0x143+124-0x86):strcpy(z16ba527520,"\x49\x4f\x33\x31\x33");z6f813cde47=(0x194b+7529-0x1fdf);za4a2434e08=17235;break;case(0xb16+4596-0x1bd0):strcpy(z16ba527520,"\x49\x4f\x33\x31\x34");z6f813cde47=(0x2520+940-0x11f7);za4a2434e08=(0x21e9+14-0x1f3);break;case(0x4ef+1969-0xb5f):strcpy(z16ba527520,"\x49\x4f\x33\x32\x31");z6f813cde47=5845;za4a2434e08=19520;break;}if((int_T)mxGetPr(z702a26a5e9)[(0xd39+1034-0x1143)]<(0x1b10+1995-0x22db)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x15b5+2709-0x2049)){z366b2f03bf=(0x1b1+2270-0xa8f);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x17aa+2711-0x2241)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x2193+182-0x2249)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x709+858-0xa62)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0xba5+5588-0x207a))|((z366b2f03bf&(0x328+1592-0x861))<<(0x1943+501-0x1b30)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x3b9+6100-0x1b8b)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE     
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*za42cf7dd4a;uint32_T z26dbd73a5e,i,width,count;real_T*out;uint32_T z4e3026977c;width=(uint32_T)mxGetPr(z3d4ad966bd)[(0x5f7+8329-0x2680)]+(0x4e1+6456-0x1e18);za42cf7dd4a=(void*)base;
for(i=(0x9a5+1537-0xfa6);i<mxGetN(za9d8fb6bcf);i++)
{z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1120+2142-0x197d);count=za42cf7dd4a[10560+z4e3026977c];out=ssGetOutputPortSignal(S,z4e3026977c);if(count>(0x1331+2168-0x1ba9)){

for(z26dbd73a5e=(0xf2+4629-0x1307);z26dbd73a5e<(uint8_T)mxGetPr(z3d4ad966bd)[(0x23a+6019-0x19bd)];z26dbd73a5e++){out[z26dbd73a5e]=(0xd11+1174-0x11a7);}for(z26dbd73a5e=(0x1998+63-0x19d7);z26dbd73a5e<count;z26dbd73a5e++){
za42cf7dd4a[10544+z4e3026977c]=z26dbd73a5e;
out[z26dbd73a5e+(0xd91+1481-0x1359)]=(real_T)za42cf7dd4a[10528+z4e3026977c];}
za42cf7dd4a[10506]=((0x11c6+3544-0x1f9d)<<z4e3026977c);za42cf7dd4a[10506]=(0x21a+3466-0xfa4);}out[(0x14f9+4213-0x256e)]=(real_T)count;
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

