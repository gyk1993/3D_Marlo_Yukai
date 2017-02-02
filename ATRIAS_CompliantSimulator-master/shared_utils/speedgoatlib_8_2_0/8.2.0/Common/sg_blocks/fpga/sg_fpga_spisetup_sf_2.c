/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x50+6644-0x1a42)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_spisetup_sf_2
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
#define zdf24515981              ((0x23a4+360-0x24fd))
#define z533b11d03f               ssGetSFcnParam(S, (0xc6b+4510-0x1e09))
#define za9d8fb6bcf                 ssGetSFcnParam(S, (0x7ab+4871-0x1ab1))
#define zd030c7afd0             ssGetSFcnParam(S, (0x342+2144-0xba0))
#define za07102a5be             ssGetSFcnParam(S, (0x92c+6853-0x23ee))
#define z7039def18e              ssGetSFcnParam(S, (0xc39+5027-0x1fd8))
#define z86af52d74e                    ssGetSFcnParam(S, (0x76b+4500-0x18fa))
#define z31fb671cb8                    ssGetSFcnParam(S, (0x101b+2984-0x1bbd))
#define zf6f668e67a         ssGetSFcnParam(S, (0x1472+2757-0x1f30))
#define z986ad4e96d            ssGetSFcnParam(S, (0x1d4c+701-0x2001))
#define z8f7a5b7479           ssGetSFcnParam(S, (0x1773+2719-0x2209))
#define zdc5f8981b7              ssGetSFcnParam(S, (0x5a4+6493-0x1ef7))
#define zc09b06e5fc             ssGetSFcnParam(S, (0x408+4966-0x1763))
#define zea4d7ef473                ssGetSFcnParam(S, (0x693+5781-0x1d1c))
#define z6dbb1ea7a9             ssGetSFcnParam(S, (0x13bd+1204-0x1864))
#define z702a26a5e9                    ssGetSFcnParam(S, (0xdca+2009-0x1595))
#define z2e6483d505              ((0x845+1410-0xdc5))
#define z7e2eeaa57c          ((0x558+2445-0xee5))
#define z6a0da049de         ((0x255+2119-0xa9b))
#define zc5ce4cb81a              ((0x1577+3592-0x237f))
#define z2b17e2ee3b              ((0x2367+394-0x24f1))
static char_T zea4cd01646[(0x377+1545-0x880)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x646+6091-0x1e11));ssSetNumDiscStates(S,(0x607+1301-0xb1c));ssSetNumOutputPorts(S,(0x1eaa+996-0x228e));ssSetNumInputPorts(S,(0x11d2+1485-0x179f));ssSetNumSampleTimes(S,(0xc8d+3263-0x194b));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xbdc+2892-0x1728));ssSetNumNonsampledZCs(S,(0x191d+2402-0x227f));for(i=(0xf94+670-0x1232);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x148f+2429-0x1e0c));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0xd0+6077-0x188d),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x11ff+4060-0x21db),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;uint8_T z16ba527520[(0x17+7719-0x1e2a)];uint16_T z6f813cde47,za4a2434e08;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x1+9346-0x2483)];z6f813cde47=5845;switch(z78caf1ba61){case(0x1bf+911-0x421):strcpy(z16ba527520,"\x49\x4f\x33\x30\x31");za4a2434e08=17232;break;case(0x13f8+2406-0x1c30):strcpy(z16ba527520,"\x49\x4f\x33\x30\x32");za4a2434e08=17239;break;case(0x5b4+3503-0x1234):strcpy(z16ba527520,"\x49\x4f\x33\x30\x33");za4a2434e08=16979;break;case(0x48b+4019-0x130e):strcpy(z16ba527520,"\x49\x4f\x33\x30\x34");za4a2434e08=(0x1522+1752-0x16f6);break;case(0x179c+1164-0x1af1):strcpy(z16ba527520,"\x49\x4f\x33\x31\x31");za4a2434e08=21069;break;case(0x5a4+726-0x742):strcpy(z16ba527520,"\x49\x4f\x33\x31\x32");za4a2434e08=16971;break;case(0x864+2149-0xf90):strcpy(z16ba527520,"\x49\x4f\x33\x31\x33");za4a2434e08=17235;break;case(0x7e3+4315-0x1784):strcpy(z16ba527520,"\x49\x4f\x33\x31\x34");za4a2434e08=8196;break;case(0x1d72+1199-0x20e0):strcpy(z16ba527520,"\x49\x4f\x33\x32\x31");za4a2434e08=19520;break;}if((int_T)mxGetPr(z702a26a5e9)[(0xab3+1013-0xea8)]<(0x14b+9354-0x25d5)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x1591+2295-0x1e87)){z366b2f03bf=(0x7f3+7519-0x2552);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xc46+4476-0x1dc2)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x1082+5153-0x24a3)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x887+6527-0x2205)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x1409+5113-0x2703))|((z366b2f03bf&(0xae8+1315-0xf0c))<<(0x81+4234-0x1103)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x194b+2362-0x2283)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);
za42cf7dd4a=(volatile uint32_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);
#endif
}
static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE 
#endif
}
static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE   
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint16_T i;volatile uint32_T*za42cf7dd4a;uint32_T z4e3026977c,z1209c02d78,zdc0d676974,zbea4a89f24,z9e58a4ec45;za42cf7dd4a=(void*)base;
z1209c02d78=(uint32_T)za42cf7dd4a[10240];zdc0d676974=(uint32_T)za42cf7dd4a[10241];zbea4a89f24=(uint32_T)za42cf7dd4a[10248];z9e58a4ec45=(uint32_T)za42cf7dd4a[10242];for(i=(0x7e5+927-0xb84);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x746+5178-0x1b7f);
za42cf7dd4a[10304+z4e3026977c]=(uint32_T)mxGetPr(zd030c7afd0)[i];
za42cf7dd4a[10320+z4e3026977c]=(uint32_T)mxGetPr(za07102a5be)[i];
za42cf7dd4a[10288+z4e3026977c]=(uint32_T)mxGetPr(z7039def18e)[i];z1209c02d78|=((0x56b+6776-0x1fe2)<<z4e3026977c);zdc0d676974|=(((uint32_T)mxGetPr(z86af52d74e)[i])<<z4e3026977c);zbea4a89f24|=(((uint32_T)mxGetPr(z31fb671cb8)[i])<<z4e3026977c);z9e58a4ec45|=(((uint32_T)mxGetPr(zea4d7ef473)[i])<<z4e3026977c);za42cf7dd4a[10464+z4e3026977c]=(uint32_T)mxGetPr(zf6f668e67a)[i];za42cf7dd4a[10480+z4e3026977c]=(uint32_T)mxGetPr(z986ad4e96d)[i];za42cf7dd4a[10496+z4e3026977c]=(uint32_T)mxGetPr(z8f7a5b7479)[i];za42cf7dd4a[10512+z4e3026977c]=(uint32_T)mxGetPr(zdc5f8981b7)[i];za42cf7dd4a[10544+z4e3026977c]=(uint32_T)mxGetPr(zc09b06e5fc)[i];}za42cf7dd4a[10241]=zdc0d676974;za42cf7dd4a[10248]=zbea4a89f24;za42cf7dd4a[10242]=z9e58a4ec45;
za42cf7dd4a[10243]=4294967295;za42cf7dd4a[10243]=(0x934+4315-0x1a0f);
za42cf7dd4a[10240]=z1209c02d78;
if(mxGetPr(z6dbb1ea7a9)[(0x1e73+1631-0x24d2)]){for(i=(0x1973+865-0x1cd4);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1fd+7680-0x1ffc);za42cf7dd4a[10416+z4e3026977c]=(0x1027+4107-0x2031);}}else{for(i=(0x1373+3988-0x2307);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xfea+1182-0x1487);za42cf7dd4a[10416+z4e3026977c]=(0x26f+6918-0x1d75);}}
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

