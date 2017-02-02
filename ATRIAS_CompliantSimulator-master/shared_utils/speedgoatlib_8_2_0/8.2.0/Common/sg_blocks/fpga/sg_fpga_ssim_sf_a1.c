/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x9d1+2614-0x1405)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_ssim_sf_a1
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
#define zdf24515981        ((0x1301+2024-0x1adf))
#define z533b11d03f         ssGetSFcnParam(S,  (0x2c1+9055-0x2620)) 
#define za9d8fb6bcf           ssGetSFcnParam(S,  (0x21f+9440-0x26fe)) 
#define zf5ee62a4ad      ssGetSFcnParam(S,  (0x6+8738-0x2226))
#define z3a4907dee5          ssGetSFcnParam(S,  (0x11b1+1525-0x17a3))
#define z3832b85a32         ssGetSFcnParam(S, (0x18f+4822-0x1461))
#define z702a26a5e9              ssGetSFcnParam(S, (0x85+122-0xfa))
#define z3e94973266              ssGetSFcnParam(S, (0x638+6892-0x211e))
#define z2624d402ab              ssGetSFcnParam(S, (0x81c+519-0xa1c))
#define z0422d86ad2					ssGetSFcnParam(S, (0x20d6+1467-0x2689))
#define z596b77cbe5					ssGetSFcnParam(S, (0x1376+1118-0x17cb))
#define z2e6483d505            ((0x7a6+4636-0x19c1))
#define zc5ce4cb81a            ((0x5c9+7263-0x2228))
#define z2b17e2ee3b            ((0x4cc+4567-0x16a3))
#define z6a0da049de       ((0x11cf+1972-0x1983))
#define z9b67aa523f              (245760)
static char_T zea4cd01646[(0x162a+2577-0x1f3b)];typedef struct{uint32_T z15923ef3d9[(0x11e0+5321-0x2689)];uint32_T z28e9d9261f[(0x25f+8121-0x21f8)];uint32_T z42ad4eacaf[(0xa59+5159-0x1e60)];uint32_T zfe18d134a8[(0x1705+3745-0x2586)];uint32_T z86bb419998[(0x35c+7062-0x1ed2)];uint32_T z08fefe38a9[(0x196a+2818-0x244c)];uint32_T zb15396a870[(0x1965+2542-0x2333)];uint32_T zdd951fbe16[(0x500+2452-0xe74)];uint32_T z64fc736a62[(0x2d0+6942-0x1dce)];uint32_T zaf2186d9ec[(0x1670+138-0x16da)];uint32_T z8c1a8bbff3[(0x32+600-0x26a)];uint32_T zdc1eed0ad0[(0x19bb+1137-0x1e0c)];uint32_T start;uint32_T z19690b6adb;uint32_T z73b6066883;}z69e58993ac;void z1339a94323(uint32_T*z407efd0741,uint32_T*zbcc3fe600b,uint32_T z15923ef3d9,uint32_T za746b13f73){uint32_T mask;uint32_T offset;uint32_T i;uint32_T zb534899b45,count;
mask=(0x11d6+2591-0x1bf5);offset=(0xca8+4010-0x1c52);count=(0x7a0+21-0x7b5);
for(i=(0x544+3502-0x12f2);i<z15923ef3d9;i++){mask|=((0x1467+3390-0x21a4)<<i);}
for(i=(0xbb9+5489-0x212a);i<za746b13f73;i++){zb534899b45=z407efd0741[count];
if(offset+z15923ef3d9<(0x86f+5324-0x1d1b)){zbcc3fe600b[i]=(zb534899b45>>offset)&mask;offset+=z15923ef3d9;}
else if(offset+z15923ef3d9==(0x4c7+2399-0xe06)){zbcc3fe600b[i]=(zb534899b45>>offset)&mask;offset=(0x178d+3532-0x2559);count++;}else
{
zbcc3fe600b[i]=(zb534899b45>>offset)&mask;count++;zb534899b45=z407efd0741[count];zbcc3fe600b[i]|=(zb534899b45<<((0x877+621-0xac4)-offset));zbcc3fe600b[i]&=mask;

offset=z15923ef3d9-((0x135d+2403-0x1ca0)-offset);}}}static void mdlInitializeSizes(SimStruct*S){uint32_T i,zbc7ebd0e53;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x4f+1257-0x538));ssSetNumDiscStates(S,(0x436+7109-0x1ffb));zbc7ebd0e53=(uint32_T)mxGetN(za9d8fb6bcf);ssSetNumOutputPorts(S,zbc7ebd0e53);for(i=(0x13c9+2130-0x1c1b);i<zbc7ebd0e53;i++){ssSetOutputPortDataType(S,i,SS_UINT32);ssSetOutputPortWidth(S,i,(0x1737+1387-0x1ca1));}ssSetNumSampleTimes(S,(0x8f4+1697-0xf94));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1596+4238-0x2624));ssSetNumNonsampledZCs(S,(0x1ad4+1380-0x2038));for(i=(0xd76+5590-0x234c);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xe2+3659-0xf2d));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0xf10+3404-0x1c5c)]==-1.0){ssSetSampleTime(S,(0x1d8+3120-0xe08),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x2bc+6243-0x1b1f),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x7ab+1885-0xf08),mxGetPr(z3832b85a32)[(0x16a0+3125-0x22d5)]);ssSetOffsetTime(S,(0x7fd+5333-0x1cd2),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i,z4e3026977c;volatile z69e58993ac*zb9f7147b6c;uint8_T z16ba527520[(0x2396+844-0x26ce)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61,test=(0x4f8+7393-0x21d9),z19690b6adb=(0x346+6249-0x1baf),x=(0x124b+2116-0x1a8f);z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0xf13+3812-0x1df7)];z6f813cde47=z05b56d9d51=(0x208f+6704-0x23ea);switch(z78caf1ba61){case(0xaf7+3265-0x166d):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;break;default:sprintf(zea4cd01646,"\x62\x6f\x61\x72\x64\x20\x74\x79\x70\x65\x20\x69\x6e\x63\x6f\x72\x72\x65\x63\x74\x2e");ssSetErrorStatus(S,zea4cd01646);return;}if(mxGetN(z702a26a5e9)==(0x898+4973-0x1c04)){z366b2f03bf=(0x10e3+4075-0x20ce);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x77d+6698-0x21a7)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x543+5105-0x1934)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x6cd+4941-0x1a19)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x17a6+562-0x19d6)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x1f4+3996-0x118e)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x56f+71-0x5b4)]);zb9f7147b6c=(z69e58993ac*)(zeccbadd9b3.VirtAddress[(0xd9b+1221-0x125e)]+z9b67aa523f);

if(!xpceIsModelInit()){



for(i=(0x717+429-0x8c4);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xfe0+2710-0x1a75);zb9f7147b6c->z15923ef3d9[z4e3026977c]=(uint32_T)mxGetPr(z3a4907dee5)[i];zb9f7147b6c->z28e9d9261f[z4e3026977c]=(uint32_T)mxGetPr(zf5ee62a4ad)[i];zb9f7147b6c->zdc1eed0ad0[z4e3026977c]=(uint32_T)mxGetPr(z3e94973266)[i];zb9f7147b6c->z8c1a8bbff3[z4e3026977c]=(uint32_T)mxGetPr(z2624d402ab)[i];}

zb9f7147b6c->start=(uint32_T)4294967295;
}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base,i,z26dbd73a5e=(0x14d2+2775-0x1fa9),z4e3026977c,binary,zf67c59be22;volatile z69e58993ac*zb9f7147b6c;uint32_T*out,z69a8079db8,za892a705b5=(0x10bb+5259-0x2546),x;
uint32_T z407efd0741[(0x1e98+1392-0x2400)],*zbcc3fe600b;base=ssGetIWorkValue(S,z6a0da049de);zb9f7147b6c=(z69e58993ac*)(base+z9b67aa523f);
for(i=(0xc6+7870-0x1f84);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x124a+4771-0x24ec);z69a8079db8=(uint32_T)mxGetPr(z3a4907dee5)[i]/(0xfb6+1268-0x148a);if(((uint32_T)mxGetPr(z3a4907dee5)[i]%(0x1b5+3241-0xe3e))!=(0x1e3+7637-0x1fb8)){z69a8079db8=z69a8079db8+(0xd52+6565-0x26f6);}
z407efd0741[(0xc0f+710-0xed5)]=(0x452+6000-0x1bc2);z407efd0741[(0x637+5302-0x1aec)]=(0x455+2833-0xf66);z407efd0741[(0x1920+2261-0x21f3)]=(0x1e24+1943-0x25bb);z407efd0741[(0x17eb+2380-0x2134)]=(0x11b5+2852-0x1cd9);z407efd0741[(0xefb+2839-0x1a0e)]=(0x183+6781-0x1c00);z407efd0741[(0xb0+9691-0x2686)]=(0x13f6+4547-0x25b9);z407efd0741[(0x1434+1391-0x199d)]=(0x1905+2346-0x222f);z407efd0741[(0xbd4+3722-0x1a57)]=(0x956+5408-0x1e76);
if(z69a8079db8>=(0x67f+1224-0xb46)){
if((uint32_T)mxGetPr(z0422d86ad2)[(0x571+5134-0x197f)]==(0x4d9+6697-0x1f01)){
z407efd0741[(0x1537+847-0x1886)]=zb9f7147b6c->z42ad4eacaf[z4e3026977c];za892a705b5=z407efd0741[(0x1e2+1960-0x98a)];z407efd0741[(0xb85+502-0xd7b)]=(0x8f0+7268-0x2554);
for(x=(0x21a+7754-0x2064);x<(uint32_T)mxGetPr(z3a4907dee5)[i];x++){if(x!=(0x2fd+6888-0x1de5)){za892a705b5=za892a705b5>>(0x119c+549-0x13c0);z407efd0741[(0xff0+3920-0x1f40)]=z407efd0741[(0xd73+5816-0x242b)]<<(0x3a3+665-0x63b);}z407efd0741[(0x1414+376-0x158c)]=z407efd0741[(0x1f27+1718-0x25dd)]|(za892a705b5&(0x13f8+529-0x1608));}
}else if((uint32_T)mxGetPr(z596b77cbe5)[(0xeea+495-0x10d9)]==(0x5ac+7654-0x2390))
{binary=(0xa0+8455-0x21a7);z407efd0741[(0xefb+851-0x124e)]=zb9f7147b6c->z42ad4eacaf[z4e3026977c];zf67c59be22=z407efd0741[(0x10b7+74-0x1101)];z407efd0741[(0xa4d+7057-0x25de)]=(0x1341+698-0x15fb);binary=binary|(zf67c59be22&2147483648);for(x=(0xf1d+3374-0x1c4a);x<(0x132b+4207-0x237a);x++){binary=binary|((((zf67c59be22<<x)^(binary<<(x-(0x8c+4700-0x12e7))))&16777216)>>x);}z407efd0741[(0xd84+9-0xd8d)]=binary;}else{z407efd0741[(0x5ca+1049-0x9e3)]=zb9f7147b6c->z42ad4eacaf[z4e3026977c];}}if(z69a8079db8>=(0x6d6+7123-0x22a7)){z407efd0741[(0xa05+564-0xc38)]=zb9f7147b6c->zfe18d134a8[z4e3026977c];}if(z69a8079db8>=(0x1ba+7005-0x1d14)){z407efd0741[(0x103+9724-0x26fd)]=zb9f7147b6c->z86bb419998[z4e3026977c];}if(z69a8079db8>=(0x1b5+4684-0x13fd)){z407efd0741[(0x9e1+6426-0x22f8)]=zb9f7147b6c->z08fefe38a9[z4e3026977c];}if(z69a8079db8>=(0x711+4980-0x1a80)){z407efd0741[(0xded+400-0xf79)]=zb9f7147b6c->zb15396a870[z4e3026977c];}if(z69a8079db8>=(0x11b5+4556-0x237b)){z407efd0741[(0x14b5+2498-0x1e72)]=zb9f7147b6c->zdd951fbe16[z4e3026977c];}if(z69a8079db8>=(0x11d8+3881-0x20fa)){z407efd0741[(0x16b2+3786-0x2576)]=zb9f7147b6c->z64fc736a62[z4e3026977c];}if(z69a8079db8>=(0x1213+2343-0x1b32)){z407efd0741[(0x1563+3948-0x24c8)]=zb9f7147b6c->zaf2186d9ec[z4e3026977c];}
zbcc3fe600b=malloc(z69a8079db8*sizeof(uint32_T));z69a8079db8=(uint32_T)mxGetPr(z3a4907dee5)[i]/(0xd16+6428-0x2612);if(((uint32_T)mxGetPr(z3a4907dee5)[i]%(0x12d4+2478-0x1c62))!=(0x172f+3122-0x2361)){z69a8079db8=z69a8079db8+(0x2a5+1369-0x7fd);}z1339a94323(z407efd0741,zbcc3fe600b,(0x102+803-0x405),z69a8079db8);
out=(uint32_T*)ssGetOutputPortSignal(S,i);for(z26dbd73a5e=(0xb23+61-0xb60);z26dbd73a5e<z69a8079db8;z26dbd73a5e++){out[z26dbd73a5e]=zbcc3fe600b[z26dbd73a5e];}
free(zbcc3fe600b);}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE     
uint32_T base;volatile z69e58993ac*zb9f7147b6c;base=ssGetIWorkValue(S,z6a0da049de);zb9f7147b6c=(z69e58993ac*)(base+z9b67aa523f);
zb9f7147b6c->start=(uint32_T)(0x1d96+1613-0x23e3);
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif
