/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1ab7+2317-0x23c2)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_spiwrite_sf_2
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
#include "util_xpcimport.c"
#endif
#define zdf24515981              ((0x13cb+532-0x15d9))
#define z533b11d03f               ssGetSFcnParam(S, (0x18b9+1967-0x2068))
#define za9d8fb6bcf                 ssGetSFcnParam(S, (0x8df+3228-0x157a))
#define z3d4ad966bd                   ssGetSFcnParam(S, (0x1357+3715-0x21d8))
#define zef034c4c5a             ssGetSFcnParam(S, (0x13b6+4926-0x26f1))
#define z3832b85a32               ssGetSFcnParam(S, (0x1272+3378-0x1fa0))
#define z702a26a5e9                    ssGetSFcnParam(S, (0x1e07+116-0x1e76))
#define z2e6483d505              ((0xb80+5544-0x2126))
#define z7e2eeaa57c          ((0x147+1234-0x619))
#define z6a0da049de         ((0xea5+4516-0x2048))
#define zc5ce4cb81a              ((0xddd+3104-0x19fd))
#define z2b17e2ee3b              ((0x1680+3319-0x2377))
static char_T zea4cd01646[(0x2c7+857-0x520)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xb61+6122-0x234b));ssSetNumDiscStates(S,(0x1644+3340-0x2350));ssSetNumOutputPorts(S,(0x1962+2216-0x220a));if(mxGetPr(zef034c4c5a)[(0x34+1671-0x6bb)])ssSetNumInputPorts(S,(0x1280+855-0x15d4));else ssSetNumInputPorts(S,(0xaff+5123-0x1f00));ssSetInputPortDataType(S,(0x20a+7474-0x1f3c),SS_DOUBLE);ssSetInputPortMatrixDimensions(S,(0x1729+3637-0x255e),(uint32_T)mxGetPr(z3d4ad966bd)[(0x885+3635-0x16b8)]+(0x17a+2583-0xb90),mxGetN(za9d8fb6bcf));ssSetInputPortDirectFeedThrough(S,(0x42a+4688-0x167a),(0xaf9+724-0xdcc));ssSetInputPortRequiredContiguous(S,(0x61d+6102-0x1df3),(0x521+549-0x745));ssSetInputPortRequiredContiguous(S,(0x2135+253-0x2231),(0xde9+1274-0x12e2));ssSetInputPortDataType(S,(0xde4+2306-0x16e5),SS_BOOLEAN);ssSetInputPortWidth(S,(0x627+2955-0x11b1),mxGetN(za9d8fb6bcf));ssSetInputPortDirectFeedThrough(S,(0x2203+1108-0x2656),(0x8d5+266-0x9de));if(mxGetPr(zef034c4c5a)[(0x466+8051-0x23d9)]){ssSetInputPortDataType(S,(0x716+6631-0x20fb),SS_DOUBLE);ssSetInputPortDirectFeedThrough(S,(0x8a7+437-0xa5a),(0x13aa+3479-0x2140));ssSetInputPortRequiredContiguous(S,(0xbf6+6625-0x25d5),(0x1e89+1918-0x2606));ssSetInputPortWidth(S,(0x990+6067-0x2141),mxGetN(za9d8fb6bcf));}ssSetNumSampleTimes(S,(0x780+3093-0x1394));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x7c7+7323-0x2462));ssSetNumNonsampledZCs(S,(0x1a47+415-0x1be6));for(i=(0x1058+4068-0x203c);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1215+853-0x156a));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x27c+3586-0x107e)]==-1.0){ssSetSampleTime(S,(0x12a5+4055-0x227c),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x148a+344-0x15e2),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x35f+119-0x3d6),mxGetPr(z3832b85a32)[(0x695+6286-0x1f23)]);ssSetOffsetTime(S,(0x15ec+1788-0x1ce8),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint8_T z16ba527520[(0x51+2332-0x959)];uint16_T z6f813cde47,za4a2434e08;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x4dd+4234-0x1567)];switch(z78caf1ba61){case(0x1ac6+3224-0x2631):strcpy(z16ba527520,"\x49\x4f\x33\x30\x31");z6f813cde47=(0x2037+5330-0x1e34);za4a2434e08=17232;break;case(0x532+8107-0x23af):strcpy(z16ba527520,"\x49\x4f\x33\x30\x32");z6f813cde47=5845;za4a2434e08=17239;break;case(0xe09+1802-0x13e4):strcpy(z16ba527520,"\x49\x4f\x33\x30\x33");z6f813cde47=5845;za4a2434e08=16979;break;case(0x16d3+498-0x1795):strcpy(z16ba527520,"\x49\x4f\x33\x30\x34");z6f813cde47=(0x2668+1165-0x1420);za4a2434e08=(0x1f77+3161-0x26cc);break;case(0x5b8+404-0x615):strcpy(z16ba527520,"\x49\x4f\x33\x31\x31");z6f813cde47=5845;za4a2434e08=21069;break;case(0x87c+2168-0xfbc):strcpy(z16ba527520,"\x49\x4f\x33\x31\x32");z6f813cde47=(0x1b19+3063-0x103b);za4a2434e08=16971;break;case(0x198+974-0x42d):strcpy(z16ba527520,"\x49\x4f\x33\x31\x33");z6f813cde47=(0x1e73+5782-0x1e34);za4a2434e08=17235;break;case(0x790+5835-0x1d21):strcpy(z16ba527520,"\x49\x4f\x33\x31\x34");z6f813cde47=(0x1ba5+5491-0x1a43);za4a2434e08=8196;break;case(0xa98+3265-0x1618):strcpy(z16ba527520,"\x49\x4f\x33\x32\x31");z6f813cde47=(0x1830+2193-0x9ec);za4a2434e08=19520;break;}if((int_T)mxGetPr(z702a26a5e9)[(0x1a57+35-0x1a7a)]<(0x257+1871-0x9a6)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x571+5128-0x1978)){z366b2f03bf=(0xa76+2539-0x1461);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x457+8652-0x2623)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x19a0+2635-0x23eb)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x11f1+2401-0x1b51)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x394+3514-0x104f))|((z366b2f03bf&(0x1711+2872-0x214a))<<(0x830+2155-0x1093)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x7ed+1716-0xe9f)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint32_T i,z26dbd73a5e,width,z2f1801d2e2;volatile uint32_T*za42cf7dd4a;real_T*data;
real_T*z46c2b7bc26;uint32_T z4e3026977c,zc7af584786;boolean_T*z4da0d16710;za42cf7dd4a=(void*)base;width=(uint8_T)mxGetPr(z3d4ad966bd)[(0xab0+3436-0x181c)]+(0x5e8+7309-0x2274);data=(real_T*)ssGetInputPortSignal(S,(0x456+2897-0xfa7));z4da0d16710=(boolean_T*)ssGetInputPortSignal(S,(0x36d+2893-0xeb9));z2f1801d2e2=(0x74+6375-0x195b);if(mxGetPr(zef034c4c5a)[(0xab8+7095-0x266f)]){z46c2b7bc26=(real_T*)ssGetInputPortSignal(S,(0x24+2860-0xb4e));for(i=(0x14cd+640-0x174d);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x2244+1152-0x26c3);za42cf7dd4a[10464+z4e3026977c]=(uint32_T)z46c2b7bc26[i];}}for(z26dbd73a5e=(0x126f+3827-0x2162);z26dbd73a5e<mxGetN(za9d8fb6bcf);z26dbd73a5e++)
{if(z4da0d16710[z26dbd73a5e]>(0x133+1710-0x7e1))
{z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[z26dbd73a5e]-(0x307+2489-0xcbf);for(i=(0xca4+1588-0x12d8);i<(uint32_T)data[z26dbd73a5e*width];i++)
{
za42cf7dd4a[10256+z4e3026977c]=(uint32_T)data[z26dbd73a5e*width+i+(0xc44+6260-0x24b7)];
za42cf7dd4a[10384+z4e3026977c]=(0x4da+487-0x6c0);za42cf7dd4a[10384+z4e3026977c]=(0x3cc+4893-0x16e9);}


za42cf7dd4a[10400+z4e3026977c]=(0x562+2982-0x1108);z2f1801d2e2|=((0x1e21+892-0x219c)<<z4e3026977c);}}
za42cf7dd4a[10528+z4e3026977c]=(uint32_T)data[z26dbd73a5e*width];za42cf7dd4a[10560]=z2f1801d2e2;za42cf7dd4a[10560]=(0xf+3427-0xd72);
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

