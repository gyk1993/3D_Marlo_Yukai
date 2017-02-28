/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xf00+990-0x12dc)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO421_lvdt_read_s
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
#define zdf24515981              ((0x896+780-0xb9d))
#define za9d8fb6bcf                 ssGetSFcnParam(S, (0x10e1+258-0x11e3))
#define z86992bd6b1                 ssGetSFcnParam(S, (0x351+4164-0x1394)) 
#define z7f058311fd                ssGetSFcnParam(S, (0x18ac+1577-0x1ed3))
#define z3832b85a32               ssGetSFcnParam(S, (0x232d+774-0x2630))
#define z702a26a5e9                    ssGetSFcnParam(S, (0x309+1785-0x9fe))  
#define z2e6483d505              ((0x29+2602-0xa51))
#define z7e2eeaa57c          ((0xfda+24-0xff2))
#define z6a0da049de         ((0x7c+215-0x152))
#define zc5ce4cb81a              ((0xb85+4576-0x1d55))
#define z2b17e2ee3b              ((0x667+3843-0x156a))
#define z4b51daeed4                    (  (0x173f+1136-0x1baf) / (0x1f38+1222-0x23fc))    
#define zb7ccc77f59                   (  (0x13b0+899-0x172f) / (0x19c8+707-0x1c89))    
#define zddce4fa7c0                      ( (0x1454+2903-0x1f6b) / (0x680+5594-0x1c58))   
#define ze85902dd95                ( (0x1e7d+543-0x204c) / (0x124+8208-0x2132))  
#define zc1dfad6ec0                 ( (0x158+4791-0x13b3) / (0x2c+9576-0x2592))  
#define z07c501f938                      ( (0x3bc+2614-0xd92) / (0x15e3+1102-0x1a2f))  
#define z3b74416723                   ( (0x2c5+2739-0xd14) / (0x358+7590-0x20fc))    
#define z42fe744553                     ( (0xa07+7252-0x25f3) / (0xf0+5747-0x1761))
#define z5f316ba4e9                   ( (0x7bb+6249-0x1fb4) / (0x2a9+7400-0x1f8f))
#define z4d370276eb                   ( (0x122f+1115-0x1612) / (0x4ed+5035-0x1896))
#define zc002c9c712                   ( (0x92c+1902-0xffa) / (0xbc9+2062-0x13d5))   
#define zea119e762d                  ( (0xc92+3909-0x1b33) / (0x584+8368-0x2632))   
#define zb068200dd2                            ( (0xfcf+2293-0x1804) / (0x910+2187-0x1199))   
#define z3ee92efa11            ((0xef7+5887-0x24f6) / (0x691+6012-0x1e0b))   
#define z8bd1607860        	   ((0xa66+6226-0x21a8) / (0x210d+1181-0x25a8))   
#define z04eaa2c08a                      ((0x217a+1723-0x26f5) / (0x13bf+37-0x13e2))
#define z6fc8330302                      ((0x1831+1776-0x1d51) / (0x902+6950-0x2426))
#define z55def7b1d4                      ((0x1426+3975-0x21d9) / (0x467+1103-0x8b4))
#define za991ebbbaf                        ((0x844+3242-0xdee) / (0x309+7794-0x2179))    
#define zb4741c5d85                 ((0xab9+2163-0xbc4) / (0x1665+1265-0x1b54))    
#define z76b2e8cf70                 ((0x16fd+2160-0x1801) / (0x576+5441-0x1ab5))    
#define z66ef01412c                    ((0xa34+396-0x450) / (0x1bfa+2420-0x256c))    
#define zb44a118adc                   ((0x24ed+1718-0x242f) / (0x4d3+6771-0x1f44))    
#define zee468a647c                     ((0x152b+5385-0x22bc) / (0x94+6679-0x1aa9))    
static char_T zea4cd01646[(0xff1+4053-0x1ec6)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x1981+1652-0x1ff5));ssSetNumDiscStates(S,(0xc7f+1527-0x1276));ssSetNumInputPorts(S,(0x270+2706-0xd02));ssSetNumOutputPorts(S,mxGetN(za9d8fb6bcf));for(i=(0xdb9+1229-0x1286);i<mxGetN(za9d8fb6bcf);i++){ssSetOutputPortWidth(S,i,(0x11e6+3804-0x20c1));ssSetOutputPortDataType(S,i,SS_UINT16);}ssSetNumSampleTimes(S,(0xefc+1609-0x1544));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xaab+5088-0x1e8b));ssSetNumNonsampledZCs(S,(0x11d+5231-0x158c));for(i=(0x376+8606-0x2514);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xcb+4521-0x1274));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0xdec+180-0xea0)]==-1.0){ssSetSampleTime(S,(0x10ea+2334-0x1a08),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x9ff+2278-0x12e5),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xf52+448-0x1112),mxGetPr(z3832b85a32)[(0x15b1+3501-0x235e)]);ssSetOffsetTime(S,(0x264+2422-0xbda),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint16_T*za42cf7dd4a;uint16_T zcd308d01c9,z8fa65436c2;uint16_T z6f813cde47,za4a2434e08;uint32_T i,z4e3026977c;uint16_T zd0072007fc;real_T z19c4ca5f82,start;za4a2434e08=30354;z6f813cde47=5548;if((int_T)mxGetPr(z702a26a5e9)[(0xa3+806-0x3c9)]<(0x7bc+2594-0x11de)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x49\x4f\x34\x32\x31\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74\x2e");ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x1636+3237-0x22da)){z366b2f03bf=(0x936+4956-0x1c92);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x135b+2233-0x1c14)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x79f+5542-0x1d45)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xe97+595-0x10e9)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0xc1a+2977-0x16bc))|((z366b2f03bf&(0x113c+4163-0x2080))<<(0xfd1+5070-0x2397)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x49\x4f\x34\x32\x31\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74\x2e",z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0xcfb+4588-0x1ee7)];Virtual=rl32eGetDevicePtr(z1cf2c50191,32768,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint16_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);if(xpceIsModelInit()){switch((uint32_T)mxGetPr(z86992bd6b1)[(0x13e7+1577-0x1a10)]){case(0xc63+393-0xdeb):zd0072007fc=(0xbec+608-0xe4c);break;case(0x1b4f+1815-0x2264):zd0072007fc=(0xc8c+4854-0x1782);break;case(0x120c+2838-0x1d1f):zd0072007fc=(0x1e5f+198-0xf25);break;}
zcd308d01c9=(0x97f+4620-0x1b8b);for(i=(0x103c+5355-0x2527);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x186d+3488-0x260c);zcd308d01c9|=((0x743+2559-0x1141)<<z4e3026977c);}za42cf7dd4a[zd0072007fc/(0x251+8623-0x23fe)+zc1dfad6ec0]=zcd308d01c9;
for(i=(0x11d8+2533-0x1bbd);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){za42cf7dd4a[zd0072007fc/(0x1290+367-0x13fd)+z04eaa2c08a+z4e3026977c*(0x76f+7511-0x24c4)]=65535;}
z8fa65436c2=za42cf7dd4a[zd0072007fc/(0x107d+3936-0x1fdb)+z4d370276eb];for(i=(0x5b9+3796-0x148d);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x8c9+6540-0x2254);
z8fa65436c2&=~((0x36a+6255-0x1bd8)<<((0x379+8672-0x2557)*z4e3026977c));z8fa65436c2&=~((0x1958+2890-0x24a1)<<((0x977+368-0xae5)*z4e3026977c+(0x594+892-0x90f)));if((uint32_T)mxGetPr(z7f058311fd)[i]==(0x1b94+135-0x1c1a)){z8fa65436c2|=((0x66d+1674-0xcf5)<<(0x35f+2268-0xc39)*z4e3026977c);
}else{z8fa65436c2|=((0x17ff+3802-0x26d8)<<(0x108d+5138-0x249d)*z4e3026977c);
}}za42cf7dd4a[zd0072007fc/(0x5a1+6791-0x2026)+z4d370276eb]=z8fa65436c2;
za42cf7dd4a[zd0072007fc/(0x1753+2467-0x20f4)+ze85902dd95]=(0x159a+2093-0x1db8);
printf("\x42\x75\x69\x6c\x74\x2d\x69\x6e\x20\x74\x65\x73\x74\x73\x20\x61\x72\x65\x20\x69\x6e\x69\x74\x69\x61\x74\x65\x64" "\n");za42cf7dd4a[zd0072007fc/(0x6a8+1599-0xce5)+z42fe744553]=(0xd43+3963-0x1cba);za42cf7dd4a[zd0072007fc/(0x424+2226-0xcd4)+z3b74416723]=(0x4e5+3160-0x113d);start=rl32eGetTicksDouble();while(za42cf7dd4a[zd0072007fc/(0x1645+2937-0x21bc)+z3b74416723]!=(0x631+5651-0x1bef)){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*2.0)
{sprintf(zea4cd01646,"\x49\x4f\x34\x32\x31\x3a\x20\x54\x65\x73\x74\x20\x44\x32\x20\x66\x61\x69\x6c\x65\x64");ssSetErrorStatus(S,zea4cd01646);return;}}printf("\x4c\x2f\x44\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x65\x64\x20\x28\x73\x6c\x6f\x74\x3a\x20\x25\x64\x29\x2e" "\n",(uint32_T)mxGetPr(z86992bd6b1)[(0x16e4+2307-0x1fe7)]);}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE       
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint16_T*za42cf7dd4a;uint16_T zd0072007fc;uint32_T i,z4e3026977c;uint16_T*out;za42cf7dd4a=(void*)base;switch((uint32_T)mxGetPr(z86992bd6b1)[(0x1069+2199-0x1900)]){case(0x2113+225-0x21f3):zd0072007fc=(0x57d+2847-0x109c);break;case(0x76c+1216-0xc2a):zd0072007fc=(0xae0+271-0x3ef);break;case(0x5b7+3476-0x1348):zd0072007fc=(0x1459+3236-0x10fd);break;}for(i=(0x450+4450-0x15b2);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x4a+8049-0x1fba);out=(uint16_T*)ssGetOutputPortSignal(S,i);out[(0x1f4a+1572-0x256e)]=(uint16_T)za42cf7dd4a[zd0072007fc/(0xd82+3379-0x1ab3)+zb7ccc77f59+z4e3026977c*(0x1112+1392-0x167e)];
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

