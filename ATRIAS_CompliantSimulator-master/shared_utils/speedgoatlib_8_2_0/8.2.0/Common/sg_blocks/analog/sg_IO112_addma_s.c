/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x3e7+561-0x616)
#undef 	S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO112_addma_s
#include 	<stddef.h>
#include 	<stdlib.h>
#include 	"simstruc.h" 
#ifdef 		MATLAB_MEX_FILE
#include 	"mex.h"
#endif
#ifndef     MATLAB_MEX_FILE
#include    <windows.h>
#include    "io_xpcimport.h"
#include    "pci_xpcimport.h"
#include    "time_xpcimport.h"
#include    "ioext_xpcimport.h"
#include    "util_xpcimport.h"
#endif

#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x31\x32"
#define z694756a014 (0x1d7a+4029-0x1c82)
#define zea87e0ba83 36950
#define z29146a1837 4277
#define zab7e64468b 13361


#define zdf24515981          ((0x1168+2632-0x1ba5))
#define zd6d6a44c19                 ssGetSFcnParam(S,(0xcff+1505-0x12e0))
#define z1c6ce8e1bc           ssGetSFcnParam(S,(0x9c9+2605-0x13f5))
#define z2afc595703           ssGetSFcnParam(S,(0x19b5+2955-0x253e))
#define zea2279958e             ssGetSFcnParam(S,(0x1e5f+570-0x2096))
#define z186580de21          ssGetSFcnParam(S,(0x59+1978-0x80f))
#define zb0ce0940e9           ssGetSFcnParam(S,(0x8bb+7658-0x26a0))
#define zf5ee62a4ad        ssGetSFcnParam(S,(0x1f7a+223-0x2053))
#define z3832b85a32           ssGetSFcnParam(S,(0x2c0+3344-0xfc9))
#define z702a26a5e9                ssGetSFcnParam(S,(0xc04+1036-0x1008))
#define z8305e81beb            ssGetSFcnParam(S,(0xc32+2572-0x1635))
#define z2f0cae928e        ssGetSFcnParam(S,(0xc5d+5426-0x2185))
#define z2e6483d505              ((0x765+6907-0x225b))
#define z473a4893ab               ((0x41+3203-0xcc4))
#define zad3f2cd753             ((0xc51+6451-0x2583))
#define zc2f3e0cbc0        ((0x19a7+3098-0x25bf))
#define z0c20a7744a                ((0xe34+3423-0x1b90))
#define z98a09abdad                 ((0xa61+1422-0xfeb))
#define zc5ce4cb81a              ((0x2149+1084-0x2583))
#define z8caad2a8e6              ((0x12dd+316-0x1419))
#define z5bfe7a2613            ((0x178a+932-0x1b2d))
#define z2b17e2ee3b              ((0x792+8011-0x26dd))

#define z28263ff405	 (0x5c0+6918-0x20c6)
#define z20bb162559	 (0x439+3427-0x119b)
#define z9846641709	 (0x1559+757-0x184c)
#define z207720f2de	 (0x1600+1800-0x1d05)
#define z3fcb56e548 (0x1063+3420-0x1dbd)
#define zad35b24765  (0x18fb+2802-0x23ec)

static char_T zea4cd01646[(0x6f7+1706-0xca1)];
struct zc227e3590e{
volatile uint32_T z592e200bad;volatile uint32_T ze467ac829e;volatile uint32_T zad0f44b32f;volatile uint32_T z0d3df49bb1;volatile uint32_T z37045d746d;volatile uint32_T z8179a91d7b;volatile uint32_T z0aa1aefd2d;volatile uint32_T zbdff1f0f0c;volatile uint32_T zcf249b6ea3;volatile uint32_T zec1a4ba4e1;volatile uint8_T z1def6086f7;volatile uint8_T z851354b1dc;volatile uint16_T zc75aeee1f2;volatile uint32_T zfec283e685;volatile uint32_T z9f6de8f7ae;};
struct zd6245b59f0{volatile uint32_T z14bc320aa4;volatile uint32_T zf7498a4592;volatile uint32_T z690d720321;volatile uint32_T z8727c368fa;volatile uint32_T z75f62ff613;volatile uint32_T zf4facab16c;volatile uint32_T z8cf87547ee;volatile uint32_T za1e3642b47;volatile uint32_T z9d4ac60381;volatile uint32_T ze4934072a9;volatile uint32_T z7a72a2666b;volatile uint32_T z6c201be134;volatile uint32_T z609e04d491;volatile uint32_T zfaeb77d74c;volatile uint32_T zad01750135;volatile uint32_T z68f2b9a029;volatile uint32_T zdacce4ef23;volatile uint32_T zb86e6c0151;volatile uint32_T zc6056578ff;volatile uint32_T z57d8eb858f;volatile uint32_T z9603048a8e;volatile uint32_T z14a90d520e;volatile uint32_T zcc04223910;volatile uint32_T ze09a57e39d;volatile uint32_T zf584caf1ea;volatile uint32_T zb0bd214c99;volatile uint32_T zf444bf523b;volatile uint32_T zda341247ea;volatile uint32_T z5d1c4607af;volatile uint32_T za5d1d275bb;volatile uint32_T z59ae0df3b5;volatile uint32_T z914c1e3365;};static void mdlInitializeSizes(SimStruct*S){uint16_T i;uint32_T zf91d71c6d9;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x261a+208-0x26ea));ssSetNumDiscStates(S,(0x16a8+3060-0x229c));ssSetNumInputPorts(S,(0x1faa+1030-0x23b0));
zf91d71c6d9=(uint32_T)mxGetPr(z2afc595703)[(0x1459+33-0x147a)];
ssSetNumOutputPorts(S,zf91d71c6d9);
for(i=(0x146c+2609-0x1e9d);i<zf91d71c6d9;i++){ssSetOutputPortWidth(S,i,(uint32_T)mxGetPr(zb0ce0940e9)[(0x9d7+1107-0xe2a)]);}ssSetNumSampleTimes(S,(0x526+8569-0x269e));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x11a2+314-0x12dc));ssSetNumNonsampledZCs(S,(0x296+9064-0x25fe));
for(i=(0x138+1874-0x88a);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x68c+3748-0x1530));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x93a+2606-0x1368)]==-1.0){ssSetSampleTime(S,(0x1c02+2037-0x23f7),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x11da+4860-0x24d6),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x2f5+2374-0xc3b),mxGetPr(z3832b85a32)[(0x1592+4195-0x25f5)]);ssSetOffsetTime(S,(0x18b5+3196-0x2531),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;uint_T i,size;real_T z19c4ca5f82,start;uint32_T z366b2f03bf,z441f9e6d1b;uint32_T zf91d71c6d9,z8d0508b30e;int z154c53ff1b;int z406dced9ea;volatile struct zc227e3590e*zeb24a60218;volatile struct zd6245b59f0*zd6245b59f0;uint32_T z2c1768fde6,z80a2b1bccf;int za746b13f73;if(mxGetN(z702a26a5e9)==(0xe98+3638-0x1ccd)){z366b2f03bf=(0xc66+6283-0x24f1);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x510+3956-0x1484)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0xba4+2373-0x14e9)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x1331+4870-0x2636)];}

if(xpcGetPCIDeviceInfo(z694756a014,zea87e0ba83,z29146a1837,zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}
zeccbadd9b3.VirtAddress[(0xed8+354-0x103a)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0xf70+3658-0x1dba)],(void*)zeccbadd9b3.Length[(0x141d+4273-0x24ce)],XPC_RT_PG_USERREADWRITE);zeccbadd9b3.VirtAddress[(0x776+1712-0xe24)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0xe23+2513-0x17f2)],(void*)zeccbadd9b3.Length[(0x1cf6+1182-0x2192)],XPC_RT_PG_USERREADWRITE);
zd6245b59f0=(struct zd6245b59f0*)(zeccbadd9b3.VirtAddress[(0x1edc+750-0x21c8)]);
zeb24a60218=(struct zc227e3590e*)(zeccbadd9b3.VirtAddress[(0x1d40+697-0x1ff9)]+(0x578+2023-0xcdf));

if((uint32_T)mxGetPr(z2f0cae928e)[(0xf16+2891-0x1a61)]==(0x1add+2554-0x24d6))
{switch((uint16_T)mxGetPr(zea2279958e)[(0x124d+3420-0x1fa9)]){case(0x1b72+258-0x1c73):
ssSetRWorkValue(S,z8caad2a8e6,13107.2);ssSetRWorkValue(S,z5bfe7a2613,10.0);z2c1768fde6=z3fcb56e548;break;case(0xa3b+3937-0x199a):
ssSetRWorkValue(S,z8caad2a8e6,26214.4);ssSetRWorkValue(S,z5bfe7a2613,5.0);z2c1768fde6=zad35b24765;break;}}else
{switch((uint32_T)mxGetPr(zea2279958e)[(0xab5+2906-0x160f)]){case(0x118a+2950-0x1d0f):
ssSetRWorkValue(S,z8caad2a8e6,3276.8);ssSetRWorkValue(S,z5bfe7a2613,10.0);z2c1768fde6=z3fcb56e548;break;case(0xc7c+5992-0x23e2):
ssSetRWorkValue(S,z8caad2a8e6,6553.6);ssSetRWorkValue(S,z5bfe7a2613,5.0);z2c1768fde6=zad35b24765;break;}}




zd6245b59f0->z14bc320aa4=((0x1356+4162-0x2397)<<(0x43d+7598-0x21dc));zd6245b59f0->z14bc320aa4=zd6245b59f0->z14bc320aa4&~((0x4a+4769-0x12bb));
start=rl32eGetTicksDouble();while((zd6245b59f0->z14bc320aa4&((0x915+2726-0x13ba)<<(0xc48+3061-0x182e)))==((0x8bb+2664-0x1322)<<(0x26b+5481-0x17c5))){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*1.0){
sprintf(zea4cd01646,"\x20\x20\x25\x73\x3a\x20\x74\x69\x6d\x65\x6f\x75\x74\x20\x64\x75\x72\x69\x6e\x67\x20\x69\x6e\x69\x74\x20\x6f\x70\x65\x72\x61\x74\x69\x6f\x6e",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}printf("\x20\x20\x25\x73\x3a\x20\x42\x6f\x61\x72\x64\x20\x72\x65\x73\x65\x74\x65\x64\x20\x74\x6f\x20\x61\x20\x6b\x6e\x6f\x77\x6e\x20\x73\x74\x61\x74\x65\x2e" "\n",zf1b619edf2);
zf91d71c6d9=(uint32_T)mxGetPr(z2afc595703)[(0x541+1543-0xb48)];z8d0508b30e=zf91d71c6d9-(0x120b+1938-0x199c);zd6245b59f0->ze4934072a9=(z8d0508b30e<<(0x1002+3923-0x1f4d));
if((uint16_T)mxGetPr(z1c6ce8e1bc)[(0x13d5+378-0x154f)]==(0x18ba+274-0x19cb)){printf("\x20\x20\x25\x73\x3a\x20\x42\x6f\x61\x72\x64\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x65\x64\x20\x61\x73\x20\x61\x6e\x20\x48\x57\x20\x63\x6c\x6f\x63\x6b\x20\x2f\x20\x69\x6e\x69\x74\x69\x61\x74\x6f\x72" "\n",zf1b619edf2);z80a2b1bccf=z20bb162559;
zd6245b59f0->z75f62ff613=((0x2ff+4568-0x14d6)<<(0xea9+5884-0x2595))|(uint16_T)mxGetPr(zf5ee62a4ad)[(0x1029+655-0x12b8)];zd6245b59f0->z9d4ac60381=((0x1983+1592-0x1fb4)|(z80a2b1bccf<<(0x7f8+2278-0x10db)));printf("\x20\x20\x25\x73\x3a\x20\x53\x61\x6d\x70\x6c\x65\x20\x72\x61\x74\x65\x3a\x20\x25\x34\x2e\x35\x66\x5b\x4b\x48\x7a\x5d" "\n",zf1b619edf2,36000000.0/(double)mxGetPr(zf5ee62a4ad)[(0x1a4c+3235-0x26ef)]/(0x1dc4+93-0x1a39));}else{printf("\x20\x20\x25\x73\x3a\x20\x42\x6f\x61\x72\x64\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x65\x64\x20\x61\x73\x20\x61\x20\x74\x61\x72\x67\x65\x74" "\n",zf1b619edf2);z80a2b1bccf=z28263ff405;zd6245b59f0->z9d4ac60381=((0x144+4767-0x13dc)|(z80a2b1bccf<<(0xc48+6744-0x269d)));}


zd6245b59f0->z14bc320aa4=zd6245b59f0->z14bc320aa4|((0x1d7+1512-0x7be)<<(0xcc0+4351-0x1db9))|(z2c1768fde6<<(0xa59+2007-0x122c));if(((uint16_T)mxGetPr(z8305e81beb)[(0x428+4474-0x15a2)]==(0x4d3+6156-0x1cde)))
{zd6245b59f0->z9d4ac60381=zd6245b59f0->z9d4ac60381|((0x13c5+4863-0x26c3)<<(0xaa+1785-0x798));}else{
}if((uint16_T)mxGetPr(z2f0cae928e)[(0x8c9+962-0xc8b)]==(0xda5+5595-0x237f)){
zd6245b59f0->z8727c368fa=zd6245b59f0->z8727c368fa|((0xb55+3254-0x180a)<<(0x14cb+434-0x1669));
zd6245b59f0->z14bc320aa4=zd6245b59f0->z14bc320aa4&(~((0x5c5+8342-0x265a)<<(0x1885+3374-0x25a1)));}else{
zd6245b59f0->z8727c368fa=zd6245b59f0->z8727c368fa&(~((0x19ef+2443-0x2379)<<(0xba7+3880-0x1abb)));
zd6245b59f0->z14bc320aa4=zd6245b59f0->z14bc320aa4|((0x180d+1595-0x1e47)<<(0x23e2+117-0x2445));
zd6245b59f0->z14bc320aa4=zd6245b59f0->z14bc320aa4|((0x342+3482-0x10db)<<(0x13a6+3194-0x2015));


}
if(xpceIsModelInit()&&((int)mxGetPr(zd6d6a44c19)[(0xdcd+5335-0x22a4)]==(0x8ac+913-0xc3c))){

zd6245b59f0->z14bc320aa4|=((0x136d+417-0x150d)<<(0x13af+3102-0x1fc0));start=rl32eGetTicksDouble();printf("\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x73\x74\x61\x72\x74\x65\x64\x2e\x2e" "\n",zf1b619edf2);while((zd6245b59f0->z14bc320aa4&((0xf8d+2959-0x1b1b)<<(0x1c96+53-0x1cbe)))==((0x834+1017-0xc2c)<<(0x504+8269-0x2544))){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*5.0){
sprintf(zea4cd01646,"\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x74\x69\x6d\x65\x64\x20\x6f\x75\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}
if((zd6245b59f0->z14bc320aa4&((0x1f4b+1770-0x2634)<<(0x9b0+2929-0x1513)))==((0x606+290-0x727)<<(0x106f+4998-0x23e7))){printf("\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x73\x75\x63\x63\x65\x65\x64\x65\x64\x2e" "\n",zf1b619edf2);}else{sprintf(zea4cd01646,"\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x66\x61\x69\x6c\x65\x64",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}
za746b13f73=(int)mxGetPr(zb0ce0940e9)[(0x1dc0+394-0x1f4a)];printf("\x20\x20\x25\x73\x3a\x20\x46\x72\x61\x6d\x65\x20\x73\x69\x7a\x65\x20\x73\x65\x74\x20\x74\x6f\x20\x25\x64" "\n",zf1b619edf2,za746b13f73);
if((uint32_T)mxGetPr(z2f0cae928e)[(0x1e67+1742-0x2535)]==(0x12a7+2852-0x1dca))
{zd6245b59f0->z8727c368fa=zd6245b59f0->z8727c368fa|zf91d71c6d9*za746b13f73-(0x1484+626-0x16f5);
printf("\x20\x20\x25\x73\x3a\x20\x50\x72\x65\x70\x61\x72\x69\x6e\x67\x20\x74\x68\x65\x20\x44\x4d\x41\x20\x70\x6f\x6f\x6c" "\n",zf1b619edf2);size=zf91d71c6d9*za746b13f73*(0x93b+3882-0x1861);}else
{zd6245b59f0->z8727c368fa=zd6245b59f0->z8727c368fa|((zf91d71c6d9*za746b13f73)/(0x1115+2003-0x18e6))-(0x1957+2551-0x234d);
printf("\x20\x20\x25\x73\x3a\x20\x50\x72\x65\x70\x61\x72\x69\x6e\x67\x20\x74\x68\x65\x20\x44\x4d\x41\x20\x70\x6f\x6f\x6c" "\n",zf1b619edf2);size=(zf91d71c6d9*za746b13f73*(0xb05+5623-0x20f8))/(0xbb6+1558-0x11ca);}z154c53ff1b=(int)xpcAllocPhysicalMemory(size+(0x164f+5324-0x1b1b));for(i=(0x8b+5583-0x165a);i<size/(0xafd+1292-0x1005);i++){*((int*)z154c53ff1b+i)=(0x990+6893-0x247d);}z406dced9ea=z154c53ff1b;
zeb24a60218->ze467ac829e=z406dced9ea;zeb24a60218->zad0f44b32f=(0x1b18+339-0x1c63);zeb24a60218->z0d3df49bb1=size;zeb24a60218->z37045d746d=(0x203+7734-0x202f);zeb24a60218->z592e200bad=138563;
ssSetIWorkValue(S,z98a09abdad,z154c53ff1b);ssSetIWorkValue(S,z0c20a7744a,z406dced9ea);ssSetIWorkValue(S,z473a4893ab,zeccbadd9b3.VirtAddress[(0x1d95+1892-0x24f9)]);ssSetIWorkValue(S,zad3f2cd753,zeccbadd9b3.VirtAddress[(0x1522+3812-0x2404)]);ssSetIWorkValue(S,zc2f3e0cbc0,(uint32_T)zf91d71c6d9);

printf("\x20\x20\x25\x73\x3a\x20\x44\x4d\x41\x20\x63\x6f\x72\x72\x65\x63\x74\x6c\x79\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x65\x64" "\n",zf1b619edf2);zd6245b59f0->z8727c368fa|=((0x1e00+685-0x20ac)<<(0xde4+5485-0x233f));start=rl32eGetTicksDouble();while((zd6245b59f0->z8727c368fa&((0x5f+7823-0x1eed)<<(0xe2d+5519-0x23aa)))==((0x210b+1038-0x2518)<<(0xf40+4292-0x1ff2))){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*1.0){
sprintf(zea4cd01646,"\x20\x20\x25\x73\x3a\x20\x74\x69\x6d\x65\x6f\x75\x74\x20\x64\x75\x72\x69\x6e\x67\x20\x63\x6c\x65\x61\x72\x20\x62\x75\x66\x66\x65\x72\x20\x6f\x70\x65\x72\x61\x74\x69\x6f\x6e",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}if((zd6245b59f0->z8727c368fa&((0x178d+1903-0x1efb)<<(0x1f36+1323-0x244e)))==((0x93b+7572-0x26ce)<<(0x9d5+944-0xd72))){sprintf(zea4cd01646,"\x20\x20\x25\x73\x3a\x20\x63\x6c\x65\x61\x72\x20\x62\x75\x66\x66\x65\x72\x20\x6f\x70\x65\x72\x61\x74\x69\x6f\x6e\x20\x66\x61\x69\x6c\x65\x64",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}else{printf("\x20\x20\x25\x73\x3a\x20\x42\x75\x66\x66\x65\x72\x20\x63\x6c\x65\x61\x72\x65\x64" "\n",zf1b619edf2);}
printf("\x20\x20\x25\x73\x3a\x20\x52\x61\x74\x65\x20\x41\x20\x47\x65\x6e\x65\x72\x61\x74\x6f\x72\x20\x65\x6e\x61\x62\x6c\x65\x64" "\n",zf1b619edf2);zd6245b59f0->z75f62ff613&=~((0x2d9+264-0x3e0)<<(0x595+7378-0x2257));
printf("\x20\x20\x25\x73\x3a\x20\x44\x4d\x41\x20\x65\x6e\x61\x62\x6c\x65\x64\x20\x61\x6e\x64\x20\x73\x74\x61\x72\x74\x65\x64" "\n",zf1b619edf2);zeb24a60218->z1def6086f7|=((0x977+6467-0x22b9)<<(0xec2+4772-0x2166));zeb24a60218->z1def6086f7|=((0x1dec+943-0x219a)<<(0x35d+31-0x37b));
zd6245b59f0->z9d4ac60381=zd6245b59f0->z9d4ac60381|((0x653+2719-0x10f1)<<(0x238d+541-0x25a5));
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T zf91d71c6d9=ssGetIWorkValue(S,zc2f3e0cbc0);volatile struct zd6245b59f0*zd6245b59f0=(struct zd6245b59f0*)ssGetIWorkValue(S,zad3f2cd753);volatile struct zc227e3590e*zeb24a60218=(struct zc227e3590e*)ssGetIWorkValue(S,z473a4893ab);uint32_T*databuf=(uint32_T*)ssGetIWorkValue(S,z0c20a7744a);uint32_T z8b9d33e44f=(uint32_T)mxGetPr(z186580de21)[(0x49a+357-0x5ff)];uint32_T za746b13f73=(int_T)mxGetPr(zb0ce0940e9)[(0x246+6543-0x1bd5)];real_T z0754dd67cc,offset;real_T*y;uint32_T i,z26dbd73a5e;uint32_T count,z8a7e6753de;z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6);offset=ssGetRWorkValue(S,z5bfe7a2613);z8a7e6753de=(0xf37+898-0x12b9);if((uint32_T)mxGetPr(z2f0cae928e)[(0xc15+5824-0x22d5)]==(0x1328+4621-0x2534))
{for(i=(0x523+5221-0x1988);i<za746b13f73;i++){for(z26dbd73a5e=(0x5a0+1568-0xbc0);z26dbd73a5e<zf91d71c6d9;z26dbd73a5e++){y=ssGetOutputPortSignal(S,z26dbd73a5e);count=databuf[z8a7e6753de];
y[i]=(real_T)(count&262143)/z0754dd67cc-offset;z8a7e6753de++;}}}else
{for(i=(0x1cb8+1493-0x228d);i<za746b13f73;i++){for(z26dbd73a5e=(0x318+2699-0xda3);z26dbd73a5e<zf91d71c6d9/(0x672+5843-0x1d43);z26dbd73a5e++){count=databuf[z8a7e6753de];y=ssGetOutputPortSignal(S,z26dbd73a5e*(0x66+6689-0x1a85));y[i]=(real_T)(count&65535)/z0754dd67cc-offset;y=ssGetOutputPortSignal(S,(0x840+1580-0xe6b)+z26dbd73a5e*(0x7fa+857-0xb51));y[i]=(real_T)((count&4294901760)>>(0x1a3f+489-0x1c18))/z0754dd67cc-offset;z8a7e6753de++;}}}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
volatile struct zd6245b59f0*zd6245b59f0=(struct zd6245b59f0*)ssGetIWorkValue(S,zad3f2cd753);volatile struct zc227e3590e*zc227e3590e=(struct zc227e3590e*)(ssGetIWorkValue(S,z473a4893ab)+(0x1b8+3293-0xe15));
zd6245b59f0->z9d4ac60381=zd6245b59f0->z9d4ac60381&(~((0x12a8+3861-0x219d)));zc227e3590e->z592e200bad=(0x8b3+7250-0x2502);zd6245b59f0->z8727c368fa=zd6245b59f0->z8727c368fa|262144;
zd6245b59f0->z75f62ff613=zd6245b59f0->z75f62ff613|65536;
#endif        
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

