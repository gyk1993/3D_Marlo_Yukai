/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x67f+6983-0x21c4)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_biss_sf_a1
#include 	<stddef.h>
#include 	<stdlib.h>
#include  <math.h>
#include 	"simstruc.h" 
#ifdef 		MATLAB_MEX_FILE
#include 	"mex.h"
#endif
#ifndef  MATLAB_MEX_FILE
#include <windows.h>
#include "io_xpcimport.h"
#include "pci_xpcimport.h"
#include "time_xpcimport.h"
#include "ioext_xpcimport.h"
#include "util_xpcimport.h"
#endif
#define zdf24515981        ((0x1f86+456-0x2142)) 
#define z533b11d03f         ssGetSFcnParam(S,  (0x2b0+8593-0x2441))  
#define za9d8fb6bcf           ssGetSFcnParam(S,  (0x203d+1243-0x2517))  
#define z3832b85a32         ssGetSFcnParam(S,  (0x8e4+6778-0x235c))  
#define z702a26a5e9              ssGetSFcnParam(S,  (0x1a16+375-0x1b8a))  
#define z81beea20ac  ssGetSFcnParam(S,  (0xb2c+3779-0x19eb))  
#define ze77ebac966          ssGetSFcnParam(S,  (0x2f4+9172-0x26c3))  
#define z49f490d257            ssGetSFcnParam(S,  (0x7db+7186-0x23e7))  
#define z7cb79de14c        ssGetSFcnParam(S,  (0xedc+2670-0x1943))  
#define z4f84032443         ssGetSFcnParam(S,  (0xc12+4984-0x1f82))  
#define zea12d54e0e          ssGetSFcnParam(S,  (0x202b+329-0x216b))  
#define z6a3166e6cf       ssGetSFcnParam(S, (0x4af+7947-0x23b0))  
#define z791eb959fb    ssGetSFcnParam(S, (0x2ad+1934-0xa30))  
#define z2e6483d505            ((0x5b0+3309-0x129b))
#define zc5ce4cb81a            ((0xaa9+5308-0x1f65))
#define z2b17e2ee3b            ((0x1bc1+1199-0x2070))
#define z6a0da049de       ((0x1dfa+130-0x1e7c))
#define z00701a6abb       ((0x1880+2317-0x218c))
#define z9280404cec             278528
static char_T zea4cd01646[(0xd76+5106-0x2068)];static const real_T z5cfed3e8b9=4294967296;typedef struct{uint32_T z8a88ac521c[(0x1516+274-0x1608)];uint32_T z101e4cd9e6[(0x17aa+613-0x19ef)];uint32_T zd64461ce28[(0x5b8+741-0x87d)];uint32_T za4a88f4979[(0x951+1345-0xe72)];uint32_T zd59329a8b7[(0x13c9+3250-0x205b)];uint32_T error;uint32_T zea9d5c3d22;uint32_T z88f10f6163;uint32_T z0013d14a70;uint32_T z5b776a868c;uint32_T z19690b6adb;uint32_T z73b6066883;}zd0656dfddb;static void mdlInitializeSizes(SimStruct*S){uint32_T i,zbc7ebd0e53,zde2210a484;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x1053+1287-0x155a));ssSetNumDiscStates(S,(0x4a4+5625-0x1a9d));
ssSetNumInputPorts(S,(0x1d1+2268-0xaad));
zbc7ebd0e53=(0x1368+1193-0x1810);
if((uint32_T)mxGetPr(zea12d54e0e)[(0x62+1518-0x650)]){zbc7ebd0e53+=(0x1a02+104-0x1a69);}if((uint32_T)mxGetPr(z4f84032443)[(0xe7c+3552-0x1c5c)]){zbc7ebd0e53+=(0x1d35+2447-0x26c3);}if((uint32_T)mxGetPr(z7cb79de14c)[(0xbbb+3679-0x1a1a)]){zbc7ebd0e53+=(0xe50+4977-0x21c0);}if((uint32_T)mxGetPr(z791eb959fb)[(0x243+4941-0x1590)]){zbc7ebd0e53+=(0xe8c+1029-0x1290);}

zde2210a484=(uint32_T)mxGetN(za9d8fb6bcf);ssSetNumOutputPorts(S,zbc7ebd0e53);
ssSetOutputPortDataType(S,(0xecc+1802-0x15d6),SS_DOUBLE);ssSetOutputPortWidth(S,(0x11e2+3942-0x2148),zde2210a484);
for(i=(0x329+4579-0x150b);i<zbc7ebd0e53;i++){ssSetOutputPortDataType(S,i,SS_UINT8);ssSetOutputPortWidth(S,i,zde2210a484);}ssSetNumSampleTimes(S,(0x1432+3987-0x23c4));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1671+4192-0x26d1));ssSetNumNonsampledZCs(S,(0x980+5176-0x1db8));for(i=(0xf7a+4690-0x21cc);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xc9a+61-0xcd7));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x109c+4559-0x226b)]==-1.0){ssSetSampleTime(S,(0x1157+648-0x13df),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x4ba+1516-0xaa6),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xe06+767-0x1105),mxGetPr(z3832b85a32)[(0x1852+2899-0x23a5)]);ssSetOffsetTime(S,(0x1dd3+230-0x1eb9),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i,z4e3026977c;volatile zd0656dfddb*zdb53d4d276;real_T z9ab632cec0,zab642cf9f7;uint8_T z16ba527520[(0x16c1+2930-0x221f)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61;uint32_T zcd308d01c9=(0xe6c+3421-0x1bc9);z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0xeaf+3733-0x1d44)];z6f813cde47=z05b56d9d51=(0x1c42+8360-0x2615);switch(z78caf1ba61){case(0x40b+5171-0x16f3):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;break;default:sprintf(zea4cd01646,"\x62\x6f\x61\x72\x64\x20\x74\x79\x70\x65\x20\x69\x6e\x63\x6f\x72\x72\x65\x63\x74\x2e");ssSetErrorStatus(S,zea4cd01646);return;}if(mxGetN(z702a26a5e9)==(0xb68+1204-0x101b)){z366b2f03bf=(0xfc9+4711-0x2230);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x27+5137-0x1438)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x162d+1705-0x1cd6)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x269+7127-0x1e3f)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x29+6860-0x1af3)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x83c+6059-0x1fe5)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x5ef+97-0x64e)]);zdb53d4d276=(zd0656dfddb*)(zeccbadd9b3.VirtAddress[(0x363+4418-0x14a3)]+z9280404cec);if(!xpceIsModelInit()){
printf("\x46\x50\x47\x41\x20\x42\x69\x53\x53\x20\x63\x6f\x64\x65\x6d\x6f\x64\x75\x6c\x65\x20\x76\x65\x72\x73\x69\x6f\x6e\x20\x25\x6c\x75\x2e\x25\x6c\x75\x2e\x25\x6c\x75" "\n",zdb53d4d276->z5b776a868c,zdb53d4d276->z0013d14a70,zdb53d4d276->z88f10f6163);





for(i=(0x60b+2384-0xf5b);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){
z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x10e3+203-0x11ad);zcd308d01c9|=((0x13f9+2937-0x1f71)<<z4e3026977c);
zdb53d4d276->z8a88ac521c[z4e3026977c]=(uint32_T)mxGetPr(z49f490d257)[i];
zdb53d4d276->z101e4cd9e6[z4e3026977c]=(uint32_T)mxGetPr(ze77ebac966)[i];
zdb53d4d276->zd64461ce28[z4e3026977c]=(uint32_T)mxGetPr(z81beea20ac)[i];}




ssSetIWorkValue(S,z00701a6abb,zcd308d01c9);}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base,i,z4e3026977c,z743e9390e5;uint32_T zcd308d01c9;real_T z9ab632cec0,zab642cf9f7;volatile zd0656dfddb*zdb53d4d276;real_T*z8717f00384;uint8_T*z1312a42048;uint8_T*z5ca35d42e2;uint8_T*zd7de0e0641;uint8_T*zc041f59d18;uint32_T zdd4a9e3efd,z6e0a3d60d4;
uint32_T z4f3067de90,zdac094b04b,z31ac91f556,z430748c38c;uint32_T z6aa82bf962;base=ssGetIWorkValue(S,z6a0da049de);zdb53d4d276=(zd0656dfddb*)(base+z9280404cec);
zcd308d01c9=ssGetIWorkValue(S,z00701a6abb);
zdb53d4d276->zea9d5c3d22=zcd308d01c9;

z9ab632cec0=rl32eGetTicksDouble();while((zdb53d4d276->zea9d5c3d22&zcd308d01c9)>(0x2f3+27-0x30e)){zab642cf9f7=rl32eGetTicksDouble();
if(rl32eETimeDouble(zab642cf9f7,z9ab632cec0)>3.0)
{sprintf(zea4cd01646,"\x42\x69\x53\x53\x20\x72\x65\x61\x64\x3a\x20\x54\x69\x6d\x65\x2d\x6f\x75\x74\x20\x65\x72\x72\x6f\x72");ssSetErrorStatus(S,zea4cd01646);return;}}
z8717f00384=(real_T*)ssGetOutputPortSignal(S,(0xa71+525-0xc7e));
z743e9390e5=(0x1922+86-0x1977);z4f3067de90=(0xab3+646-0xd39);if((uint32_T)mxGetPr(zea12d54e0e)[(0x768+3808-0x1648)]){zd7de0e0641=(uint8_T*)ssGetOutputPortSignal(S,z743e9390e5++);z4f3067de90+=(uint32_T)mxGetPr(z6a3166e6cf)[(0xcda+4851-0x1fcd)];}if((uint32_T)mxGetPr(z4f84032443)[(0x723+6015-0x1ea2)]){z5ca35d42e2=(uint8_T*)ssGetOutputPortSignal(S,z743e9390e5++);z430748c38c=z4f3067de90++;}if((uint32_T)mxGetPr(z7cb79de14c)[(0x1f58+179-0x200b)]){z1312a42048=(uint8_T*)ssGetOutputPortSignal(S,z743e9390e5++);z31ac91f556=z4f3067de90++;}if((uint32_T)mxGetPr(z791eb959fb)[(0x9a5+93-0xa02)]){zc041f59d18=(uint8_T*)ssGetOutputPortSignal(S,z743e9390e5++);z6aa82bf962=zdb53d4d276->error;}
for(i=(0x610+1584-0xc40);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x21bb+16-0x21ca);
zdd4a9e3efd=zdb53d4d276->za4a88f4979[z4e3026977c];z6e0a3d60d4=zdb53d4d276->zd59329a8b7[z4e3026977c];


z8717f00384[i]=floor((((real_T)z6e0a3d60d4*z5cfed3e8b9)+(real_T)zdd4a9e3efd)/pow((0x8ef+3392-0x162d),z4f3067de90));
if((uint32_T)mxGetPr(zea12d54e0e)[(0x625+2216-0xecd)]){zdac094b04b=(uint32_T)mxGetPr(z6a3166e6cf)[(0x1594+2545-0x1f85)];zd7de0e0641[i]=(zdd4a9e3efd&((uint32_T)(pow((0xe29+4409-0x1f60),zdac094b04b)-(0x1123+4933-0x2467))));}
if((uint32_T)mxGetPr(z4f84032443)[(0x6b0+7306-0x233a)]){z5ca35d42e2[i]=(zdd4a9e3efd>>z430748c38c)&(0x250+7287-0x1ec6);}
if((uint32_T)mxGetPr(z7cb79de14c)[(0x2a7+4162-0x12e9)]){z1312a42048[i]=(zdd4a9e3efd>>z31ac91f556)&(0x207f+81-0x20cf);}if((uint32_T)mxGetPr(z791eb959fb)[(0x1f1f+1886-0x267d)]){zc041f59d18[i]=(z6aa82bf962&((0x17a3+3473-0x2533)<<z4e3026977c))>>z4e3026977c;}}
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
