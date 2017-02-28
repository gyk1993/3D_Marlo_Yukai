/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x2ed+3999-0x128a)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_ssim_sf
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
#define zdf24515981        ((0x1ca+2130-0xa12))
#define z533b11d03f         ssGetSFcnParam(S,  (0x1edc+250-0x1fd6)) 
#define za9d8fb6bcf           ssGetSFcnParam(S,  (0x125b+2585-0x1c73)) 
#define zf5ee62a4ad      ssGetSFcnParam(S,  (0x8a5+7319-0x253a))
#define z3a4907dee5          ssGetSFcnParam(S,  (0xe1f+2200-0x16b4))
#define z3832b85a32         ssGetSFcnParam(S, (0x4a9+6598-0x1e6b))
#define z702a26a5e9              ssGetSFcnParam(S, (0x19b1+1649-0x201d))
#define z3e94973266              ssGetSFcnParam(S, (0x12b5+1740-0x197b))
#define z2624d402ab              ssGetSFcnParam(S, (0x524+4589-0x170a))
#define z0422d86ad2					ssGetSFcnParam(S, (0x18a+4499-0x1315))
#define z596b77cbe5					ssGetSFcnParam(S, (0xc83+5234-0x20ec))
#define z2e6483d505            ((0x3a6+5533-0x1942))
#define zc5ce4cb81a            ((0x19cc+794-0x1ce6))
#define z2b17e2ee3b            ((0xa59+932-0xdfd))
#define z6a0da049de       ((0xb2a+6238-0x2388))
#define z9b67aa523f              (786432)
static char_T zea4cd01646[(0x551+2945-0xfd2)];typedef struct{uint32_T z15923ef3d9[(0x17d9+3575-0x25b0)];uint32_T z28e9d9261f[(0x17e6+3316-0x24ba)];uint32_T z42ad4eacaf[(0x1246+3142-0x1e6c)];uint32_T zfe18d134a8[(0x607+2091-0xe12)];uint32_T z86bb419998[(0x54b+7962-0x2445)];uint32_T z08fefe38a9[(0xf0c+4256-0x1f8c)];uint32_T zb15396a870[(0xf26+5918-0x2624)];uint32_T zdd951fbe16[(0x19a2+131-0x1a05)];uint32_T z64fc736a62[(0x18d5+1502-0x1e93)];uint32_T zaf2186d9ec[(0x9af+7372-0x265b)];uint32_T z8c1a8bbff3[(0x31+1595-0x64c)];uint32_T zdc1eed0ad0[(0x19cc+363-0x1b17)];uint32_T start;uint32_T z19690b6adb;uint32_T z73b6066883;}z69e58993ac;void z4726fd7cf7(uint32_T*z407efd0741,uint32_T*zbcc3fe600b,uint32_T z15923ef3d9,uint32_T za746b13f73){uint32_T mask;uint32_T offset;uint32_T i;uint32_T zb534899b45,count;
mask=(0x1713+2129-0x1f64);offset=(0x147+3183-0xdb6);count=(0x1c3b+785-0x1f4c);
for(i=(0x6f6+3643-0x1531);i<z15923ef3d9;i++){mask|=((0x1589+359-0x16ef)<<i);}
for(i=(0xcf3+2433-0x1674);i<za746b13f73;i++){zb534899b45=z407efd0741[count];
if(offset+z15923ef3d9<(0x1c56+670-0x1ed4)){zbcc3fe600b[i]=(zb534899b45>>offset)&mask;offset+=z15923ef3d9;}
else if(offset+z15923ef3d9==(0xbcd+1660-0x1229)){zbcc3fe600b[i]=(zb534899b45>>offset)&mask;offset=(0x1f2+1718-0x8a8);count++;}else
{
zbcc3fe600b[i]=(zb534899b45>>offset)&mask;count++;zb534899b45=z407efd0741[count];zbcc3fe600b[i]|=(zb534899b45<<((0xf1d+1293-0x140a)-offset));zbcc3fe600b[i]&=mask;

offset=z15923ef3d9-((0x1677+2628-0x209b)-offset);}}}static void mdlInitializeSizes(SimStruct*S){uint32_T i,zbc7ebd0e53;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xa19+7296-0x2699));ssSetNumDiscStates(S,(0xc8c+1579-0x12b7));zbc7ebd0e53=(uint32_T)mxGetN(za9d8fb6bcf);ssSetNumOutputPorts(S,zbc7ebd0e53);for(i=(0x47d+1708-0xb29);i<zbc7ebd0e53;i++){ssSetOutputPortDataType(S,i,SS_UINT32);ssSetOutputPortWidth(S,i,(0x40c+2717-0xea8));}ssSetNumSampleTimes(S,(0x189b+682-0x1b44));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x214+6565-0x1bb9));ssSetNumNonsampledZCs(S,(0xbfc+6287-0x248b));for(i=(0x1997+1984-0x2157);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x43d+525-0x64a));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x7e8+2216-0x1090)]==-1.0){ssSetSampleTime(S,(0x9b+5808-0x174b),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x379+8845-0x2606),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x85d+4693-0x1ab2),mxGetPr(z3832b85a32)[(0x1693+2800-0x2183)]);ssSetOffsetTime(S,(0x1d43+154-0x1ddd),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint32_T i,z4e3026977c;volatile z69e58993ac*zb9f7147b6c;uint8_T z16ba527520[(0xcd5+1606-0x1307)];uint16_T z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c;uint32_T z78caf1ba61,test=(0x1dba+1907-0x252d),z19690b6adb=(0x3bc+916-0x750),x=(0x20c0+1417-0x2649),binary=(0x186b+1047-0x1c82),zf67c59be22=(0xad8+5483-0x2043);uint32_T zcd308d01c9=(0x493+3275-0x115e),zc3f3fb8321=(0x552+7657-0x233b);z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0xc29+6833-0x26da)];z6f813cde47=z05b56d9d51=5845;switch(z78caf1ba61){case(0xdcd+1050-0x109c):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");za4a2434e08=z182d03571c=22273;break;case(0x1702+2414-0x1f43):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");za4a2434e08=z182d03571c=17232;break;case(0xa58+4181-0x197f):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");za4a2434e08=z182d03571c=17239;break;case(0x1498+3321-0x2062):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");za4a2434e08=z182d03571c=16979;break;case(0x1570+3303-0x2127):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");za4a2434e08=z182d03571c=(0x1132+4737-0x1eaf);break;case(0x1993+1589-0x1e91):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");za4a2434e08=z182d03571c=21069;break;case(0xc56+7124-0x26f2):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");za4a2434e08=z182d03571c=16971;break;case(0x1086+5319-0x2414):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");za4a2434e08=z182d03571c=17235;break;case(0x744+5060-0x19ce):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");za4a2434e08=z182d03571c=8196;break;case(0xd21+399-0xd6f):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");za4a2434e08=z182d03571c=19520;break;default:sprintf(zea4cd01646,"\x62\x6f\x61\x72\x64\x20\x74\x79\x70\x65\x20\x69\x6e\x63\x6f\x72\x72\x65\x63\x74\x2e");ssSetErrorStatus(S,zea4cd01646);return;}if(mxGetN(z702a26a5e9)==(0xaca+1001-0xeb2)){z366b2f03bf=(0x53+5109-0x1448);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x9a1+5864-0x2089)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0xf09+335-0x1058)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x1549+1574-0x1b6e)];}if(xpcGetPCIDeviceInfo(z6f813cde47,za4a2434e08,z05b56d9d51,z182d03571c,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0x96a+1163-0xdf3)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0xc36+261-0xd39)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x116f+4870-0x2473)]);zb9f7147b6c=(z69e58993ac*)(zeccbadd9b3.VirtAddress[(0x59f+6148-0x1da1)]+z9b67aa523f);

if(!xpceIsModelInit()){

zb9f7147b6c->z73b6066883=2863311530;
for(i=(0x1e1+1661-0x85e);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1936+2592-0x2355);zcd308d01c9|=((0x1f42+1604-0x2585)<<z4e3026977c);zb9f7147b6c->z15923ef3d9[z4e3026977c]=(uint32_T)mxGetPr(z3a4907dee5)[i];zb9f7147b6c->z28e9d9261f[z4e3026977c]=(uint32_T)mxGetPr(zf5ee62a4ad)[i];zb9f7147b6c->zdc1eed0ad0[z4e3026977c]=(uint32_T)mxGetPr(z3e94973266)[i];zb9f7147b6c->z8c1a8bbff3[z4e3026977c]=(uint32_T)mxGetPr(z2624d402ab)[i];}

zc3f3fb8321=zb9f7147b6c->start;zb9f7147b6c->start=zc3f3fb8321|zcd308d01c9;
}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base,i,z26dbd73a5e=(0x911+4337-0x1a02),z4e3026977c;volatile z69e58993ac*zb9f7147b6c;uint32_T*out,z69a8079db8,za892a705b5=(0x1a17+2635-0x2462),x,zf67c59be22=(0x4d8+1027-0x8db),binary=(0x662+1917-0xddf);
uint32_T z407efd0741[(0x1cdf+1012-0x20cb)],*zbcc3fe600b;base=ssGetIWorkValue(S,z6a0da049de);zb9f7147b6c=(z69e58993ac*)(base+z9b67aa523f);
for(i=(0x1966+2432-0x22e6);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x19fd+2181-0x2281);z69a8079db8=(uint32_T)mxGetPr(z3a4907dee5)[i]/(0xfc8+4744-0x2230);if(((uint32_T)mxGetPr(z3a4907dee5)[i]%(0x54f+5130-0x1939))!=(0xe70+3976-0x1df8)){z69a8079db8=z69a8079db8+(0xc59+4393-0x1d81);}
z407efd0741[(0x12f9+5109-0x26ee)]=(0xc57+1103-0x10a6);z407efd0741[(0x1439+797-0x1755)]=(0x1e58+1581-0x2485);z407efd0741[(0x7eb+2277-0x10ce)]=(0xee6+3973-0x1e6b);z407efd0741[(0xcf+7671-0x1ec3)]=(0x529+1607-0xb70);z407efd0741[(0xcd9+1776-0x13c5)]=(0x1222+1171-0x16b5);z407efd0741[(0xe2f+4376-0x1f42)]=(0x420+8422-0x2506);z407efd0741[(0x16c2+2258-0x1f8e)]=(0x5e8+2536-0xfd0);z407efd0741[(0x44f+2430-0xdc6)]=(0xe0a+2231-0x16c1);
if(z69a8079db8>=(0x20e5+492-0x22d0)){
if((uint32_T)mxGetPr(z0422d86ad2)[(0x1081+2687-0x1b00)]==(0xd99+827-0x10d3)){
z407efd0741[(0xe77+5667-0x249a)]=zb9f7147b6c->z42ad4eacaf[z4e3026977c];za892a705b5=z407efd0741[(0xbb7+6661-0x25bc)];z407efd0741[(0x1bb4+200-0x1c7c)]=(0x1700+3964-0x267c);
for(x=(0x7f7+7555-0x257a);x<(uint32_T)mxGetPr(z3a4907dee5)[i];x++){if(x!=(0x37b+6656-0x1d7b)){za892a705b5=za892a705b5>>(0x548+5732-0x1bab);z407efd0741[(0x1d0+586-0x41a)]=z407efd0741[(0x128+4295-0x11ef)]<<(0x1ab2+2670-0x251f);}z407efd0741[(0x9b4+7444-0x26c8)]=z407efd0741[(0x399+8603-0x2534)]|(za892a705b5&(0x132+7878-0x1ff7));}
}else if((uint32_T)mxGetPr(z596b77cbe5)[(0xe41+5250-0x22c3)]==(0xf05+5690-0x253d))
{binary=(0xcc5+6563-0x2668);z407efd0741[(0x1604+2833-0x2115)]=zb9f7147b6c->z42ad4eacaf[z4e3026977c];zf67c59be22=z407efd0741[(0x283+627-0x4f6)];z407efd0741[(0x21d2+525-0x23df)]=(0x1271+4003-0x2214);binary=binary|(zf67c59be22&2147483648);for(x=(0x7e7+2100-0x101a);x<(0x53d+5036-0x18c9);x++){binary=binary|((((zf67c59be22<<x)^(binary<<(x-(0x2169+765-0x2465))))&16777216)>>x);}z407efd0741[(0x13e7+941-0x1794)]=binary;}else{z407efd0741[(0x1346+1448-0x18ee)]=zb9f7147b6c->z42ad4eacaf[z4e3026977c];}}if(z69a8079db8>=(0xd35+4846-0x2021)){z407efd0741[(0x8ad+7403-0x2597)]=zb9f7147b6c->zfe18d134a8[z4e3026977c];}if(z69a8079db8>=(0x90+1747-0x760)){z407efd0741[(0x935+4957-0x1c90)]=zb9f7147b6c->z86bb419998[z4e3026977c];}if(z69a8079db8>=(0x1b09+1417-0x208e)){z407efd0741[(0x1bb0+296-0x1cd5)]=zb9f7147b6c->z08fefe38a9[z4e3026977c];}if(z69a8079db8>=(0x541+2106-0xd76)){z407efd0741[(0x6f0+1779-0xddf)]=zb9f7147b6c->zb15396a870[z4e3026977c];}if(z69a8079db8>=(0x261f+186-0x26d3)){z407efd0741[(0xf62+1866-0x16a7)]=zb9f7147b6c->zdd951fbe16[z4e3026977c];}if(z69a8079db8>=(0x11a9+1667-0x1825)){z407efd0741[(0xefd+5852-0x25d3)]=zb9f7147b6c->z64fc736a62[z4e3026977c];}if(z69a8079db8>=(0x155f+3422-0x22b5)){z407efd0741[(0x118c+4518-0x232b)]=zb9f7147b6c->zaf2186d9ec[z4e3026977c];}
zbcc3fe600b=malloc(z69a8079db8*sizeof(uint32_T));z69a8079db8=(uint32_T)mxGetPr(z3a4907dee5)[i]/(0x11f6+3070-0x1dd4);if(((uint32_T)mxGetPr(z3a4907dee5)[i]%(0x1302+5151-0x2701))!=(0x18c+984-0x564)){z69a8079db8=z69a8079db8+(0x1caa+182-0x1d5f);}z4726fd7cf7(z407efd0741,zbcc3fe600b,(0x1fa1+125-0x1ffe),z69a8079db8);
out=(uint32_T*)ssGetOutputPortSignal(S,i);for(z26dbd73a5e=(0x17bc+3249-0x246d);z26dbd73a5e<z69a8079db8;z26dbd73a5e++){out[z26dbd73a5e]=zbcc3fe600b[z26dbd73a5e];}
free(zbcc3fe600b);}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE     
uint32_T base;volatile z69e58993ac*zb9f7147b6c;uint32_T zcd308d01c9=(0x872+5459-0x1dc5),zc3f3fb8321=(0x178a+3171-0x23ed),i=(0x15d9+3993-0x2572),z4e3026977c=(0x179a+2659-0x21fd);base=ssGetIWorkValue(S,z6a0da049de);zb9f7147b6c=(z69e58993ac*)(base+z9b67aa523f);for(i=(0x1566+86-0x15bc);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1390+4709-0x25f4);zcd308d01c9|=((0x13b7+4929-0x26f7)<<z4e3026977c);}


zc3f3fb8321=zb9f7147b6c->start;zb9f7147b6c->start=zc3f3fb8321&~zcd308d01c9;
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif
