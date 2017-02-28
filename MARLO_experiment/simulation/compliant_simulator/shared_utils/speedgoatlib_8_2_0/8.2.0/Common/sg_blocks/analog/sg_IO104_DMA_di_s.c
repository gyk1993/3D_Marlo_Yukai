/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x16e5+3400-0x242b) 
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO104_DMA_di_s






#include <stddef.h>
#include <stdlib.h>
#include "simstruc.h" 
#ifdef 	 MATLAB_MEX_FILE
#include "mex.h"
#endif   
#ifndef  MATLAB_MEX_FILE
#include <windows.h>
#include "io_xpcimport.h"
#include "pci_xpcimport.h"
#include "time_xpcimport.h"
#include "ioext_xpcimport.h"
#include "util_xpcimport.h"
#endif



#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x30\x34"
#define z694756a014 (0x163f+5545-0x1b33)
#define zea87e0ba83 36950
#define z29146a1837 (0x1bc4+1188-0xfb3)
#define zab7e64468b 12658
#define z173eaebd82 (0x7e5+6525-0x215e)
#define zf16899d845 (0x5b7+8296-0x2617)
#define zb16b309883 40.32e6
typedef volatile struct z6db44e084a{volatile uint32_T z14bc320aa4;
volatile uint32_T z53343b042a;
volatile uint32_T zed3e896995[z173eaebd82];
volatile uint32_T z16f820f545;
volatile uint32_T z3378080323;
volatile uint32_T zb6903ad9ad;
volatile uint32_T z99fc22bc3e;
volatile uint32_T z6f57237277;
volatile uint32_T z3b57a6b8bc;
volatile uint32_T z97bbca0da7;
volatile uint32_T zd5b1eea47e;
volatile uint32_T z6c201be134;
volatile uint32_T zf66194a2f2;
volatile uint32_T z697ef1fddc;
volatile uint32_T z42024f906b;
volatile uint32_T z18c5808540;
volatile uint32_T z0e5f6239d4;
volatile uint32_T z0156d3cf53[(0x147b+2965-0x200c)];
}z020494c81d;
#define z28c5dfd366            (0x10f8+1526-0x16ee) 
#define ze9906393f1         (0x1df+822-0x512) 
#define z34c5a897f9                (0xfb7+1097-0x13fc) 
#define z5dd45f00a5                (0x16a2+3408-0x23ec) 
#define z904e2847ca               (0x13f2+263-0x14f1) 
#define zf54309da44           (0x642+7156-0x222d) 
#define z8e173b4aa9            (0x1179+4060-0x214b) 
#define z7459717d7c            (0x770+7596-0x2511) 
#define zaf09f9129e         (0x120f+4946-0x2555) 
#define zb7c295e611          (0x900+2480-0x12a3) 
#define z2177cc8d71 (0xe58+695-0x1101) 
#define zdc80a1dcc5       (0x17d7+84-0x181c) 
#define z2c46089855                (0x4eb+2718-0xf79) 
#define z9c45b39fac        (0x1a6+3381-0xec9) 
#define zc0c6d7bce0     (0x114a+778-0x1441) 
#define z452e3417e1             (0xbe0+2083-0x13ef) 
#define z1378a8e713           (0x1adc+1119-0x1f26) 
#define zed9cb402fc     (0x1146+3529-0x1ef9) 
#define z28d133f1e6      (0x177a+1684-0x1df7) 
#define za74c2ed17b  (0x1eab+885-0x2208) 
#define zbf7ff181d5               (0x60b+6128-0x1de2) 
#define z08b102ac19     (0x27b+7132-0x1e3d) 
#define z7c2b0fb1d1     (0x772+3696-0x15c7) 
#define zb0261a24c5                     (0x15f6+742-0x18c0) 
#define z8a1c8a1e84                (0x1124+2231-0x19be) 
#define zb0499d9319   (0x131d+3690-0x2169) 
#define INITIALIZE                  (0x149b+1472-0x1a3c) 
#define z871ba5e63d            (0xd80+437-0xf35) 
#define z059e80d468            (0xd49+1748-0x141c)
#define zf3e0b2fa74            (0xc5c+5495-0x21d1)
#define zeeec8b2ebb            (0x275+2539-0xc5d)
#define z2de56a8878  (0x542+2463-0xedd) 
#define za6afb27593       (0xa6d+2336-0x1388) 
#define z90687dcb41           (0xba4+6807-0x2635) 
#define z3d132243ee          (0x1ba3+2845-0x26b9) 
#define z148fc42565              (0xa01+3889-0x192a) 
#define zc707c018e2                 (0x20b8+1389-0x261c) 
#define z6b55dca319                  (0x4db+4028-0x148d) 
#define zabe89d9b05         (0x14d0+1048-0x18dd) 
#define zc738ebdc54             (0xbe3+6913-0x26d8) 
#define z53f96f9a93         (0xe21+1575-0x143b) 
#define z2011ff577b              (0x1771+1214-0x1c20) 
#define z48012f2ce7          (0x12d2+3870-0x21e0) 
#define z9fc17111c4              (0x6d3+1867-0xe0d) 
#define z8b72ab7941                 (0x17c9+3390-0x24f5) 
#define zc9661f8327         (0x1068+2971-0x1bf0) 
#define z5f5020ac0b           (0x550+5393-0x1a4d) 
#define z200bf8f7d0                   (0x107d+1972-0x1831) 
#define zc1a63d2a27               (0x617+1250-0xaf1) 
#define zd4f65135a2                  (0x783+1387-0xcde) 
#define zffec758124              (0x7a6+4240-0x181e) 
#define z7c9bc122b1  (0x26a5+103-0x270c)
#define z7231b70c4f (0xe2f+4587-0x2019)

#define za40af8be03           16777215 
#define z86eea319be                          (0xaec+1884-0x1230) 

#define z95b35fa456     262143 
#define zaff3da4574           (0xe3d+6060-0x25d6) 

#define z79fb3e5887         (0x2a8+1692-0x944) 
#define z3f59e11cd5                 (0x14e1+2241-0x1d92) 
#define z89772640d7           (0x1ae0+865-0x1e40) 
#define zd69c8154ae                   (0xc33+2048-0x1422) 
#define z880c27a5db             (0xa45+959-0xe02) 
#define z93f0144cec                     (0x196+2924-0xcf0) 
#define z29a6f340ee  (0x6b7+48-0x6e4) 
#define z5cffa5ee7c          (0x1529+0-0x1516) 
#define z8507451090          (0x8f9+3528-0x16bd) 
#define z8706fd3aec                  (0xac9+160-0xb55) 
#define z03a425d686        (0x341+1923-0xabf) 
#define z9fc4ddc311                (0x19a6+651-0x1c1c) 
#define zaf55e7c759                  (0x1ca+6931-0x1cd7) 
#define z4e7d98be49                          (0x574+1405-0xadb) 
#define zf636f129e2                  (0xd1c+2334-0x1633) 
#define zc2b1ac4e1c                          (0x10d5+1222-0x1584) 
#define zc5e19bcda6          (0x1083+1319-0x15a2) 
#define z25f9cdfe54                  (0xda5+4789-0x2042) 
#define z77518fe65b           (0xbd+1056-0x4d4) 
#define za02048e51d                   (0x3df+3342-0x10d4) 
#define z4803b022e6            (0xc0d+4787-0x1eb6) 
#define z94812845d3                     (0xc1c+1866-0x134c) 
#define zf1c6a6f07e  (0xbf1+121-0xc5f) 
#define z59d93d7b20           (0x1d0+6202-0x19ef) 
#define za97c522794    (0x1d55+1916-0x24c5) 
#define zec1b6962c1             (0xfc9+1222-0x1473) 
#define zc18d6729c5           (0xceb+5274-0x2178) 
#define zf9d5e888b0                    (0x15b4+2392-0x1eef) 
#define z3be9d5f81a (0x44d+4011-0x13ea) 
#define z37a0881b22          (0xf50+2062-0x1740) 

#define z02eb2797c6    262143 
#define z5eff383092            (0x127f+627-0x14df) 

#define z18826d8f2e                   (0x2186+660-0x240a) 
#define z21e78a36fd                    (0x1107+4119-0x210d) 

#define zd77bd3455c                    (0x1c3+7900-0x208f) 

#define z0205a40243 (0x61b+6191-0x1e36)          
#define z4950fe3cb1 (((0x2f9+4431-0x1447)<<(0x10ef+4171-0x2122))-(0x14c3+4374-0x25d8)) 
#define z6e71fd742f (0x9bb+2039-0x118a)          
#define zc19bacea26 (((0x13ca+1098-0x1813)<<(0x788+2859-0x129b))-(0x9f8+1577-0x1020)) 
#define zec8535e02c (0xa8b+4626-0x1b0d)         
#define z571e534c6e (((0x739+7822-0x25c6)<<(0xbe0+5197-0x2015))-(0x1022+3434-0x1d8b)) 
typedef volatile struct z199830d680{
volatile uint32_T z592e200bad;
volatile uint32_T*ze467ac829e;
volatile uint32_T zad0f44b32f;
volatile uint32_T z0d3df49bb1;
volatile uint32_T z37045d746d;
volatile uint32_T z8179a91d7b;
volatile uint32_T*z0aa1aefd2d;
volatile uint32_T zbdff1f0f0c;
volatile uint32_T zcf249b6ea3;
volatile uint32_T zec1a4ba4e1;
volatile uint8_T z1def6086f7;
volatile uint8_T z851354b1dc;
volatile uint16_T zc75aeee1f2;
volatile uint32_T zfec283e685;
volatile uint32_T z9f6de8f7ae;
volatile uint32_T zda904ce628;
volatile uint32_T zca048d0cc2;
}z83d93efdde;
#define z551c6433ad        (0x791+2860-0x12bd) 
#define z9ff50a1d47      (0xca6+3761-0x1b55) 
#define z60fa808c68      (0xc10+821-0xf3f) 
#define za495e5447f  (0x1624+2739-0x20d0) 
#define ze284f6dda4   (0x18b4+2792-0x2394) 
#define zbd9cc3ea3e   (0x495+2203-0xd27) 
#define z72a2273697     (0x3f3+5589-0x19be) 
#define zb538b13023  (0x1449+1168-0x18ce) 
#define z082f6638ca     (0x13cf+2886-0x1f09) 
#define ze57bee66e7  (0x58f+2695-0x1009) 
#define ze8cdd8692c      (0x53d+5782-0x1bc5) 
#define z48a21f4939  (0x901+7243-0x253d) 
#define z6bd25a24d0  (0xd27+5197-0x2164) 
#define z3471c69077      (0xe1f+4518-0x1fb4) 
#define zf9faf82f5c  (0x276+5551-0x1813) 
#define zf04451bb1a (0x262+3235-0xef2) 
#define z6e73a222da   (0x1d69+398-0x1ee3) 
#define z25384e33ac    (0x170b+2881-0x2237) 

#define z08d0b4e518  (0xa4b+6369-0x232c) 
#define z3e27e0685c  (0x1082+1407-0x1600) 
#define zc7139e459d  (0x13b7+1337-0x18ee) 
#define zb7f318c2a8 (0x120c+2581-0x1c1e) 
#define zb7eaca017a   (0x1264+1868-0x19ac) 
typedef volatile struct z4324a84488{volatile uint32_T zb76599274b;volatile uint32_T cntrl;}za6edc6d81a;
#define zfb2170cd8e (0x84c+2314-0x114f)
#define z445a635dd2      (0x13da+3378-0x2104) 
#define z3c87fa7ea1 (0x1f07+1498-0x24cf) 
#define z82868178d9 (0xcc+7688-0x1ebf) 
#define zbbbb241a6c (0x762+1312-0xc6c)


#define zd03e44657a  (0x7b5+5770-0x1e3e)
#define z4ef2da205f (0x1093+1472-0x1651)
#define z4292246d73 (0xe1a+3676-0x1c75)
#define z1bf87cb58b (0x276+8610-0x2417)
#define TARGET (0x170+7829-0x2005)
#define z141532d9e2 (0x8e1+3967-0x185f)
#define z1ca0467348 (0x434+3042-0x1015)




#define z102e21cf98          ssGetSFcnParam(S,(0xe27+1524-0x141b))
#define z3832b85a32           ssGetSFcnParam(S,(0x721+1465-0xcd9))
#define z702a26a5e9                ssGetSFcnParam(S,(0x114+9685-0x26e7))
#define zdf24515981                          ((0xac9+4046-0x1a94))
#define z3f9365e858        ((0x448+8756-0x267c))
#define z2e6483d505              ((0x8db+1073-0xd0b))
#define zc5ce4cb81a              ((0x51f+1502-0xafd))
#define zc4ce4213f7               ((0x170+3658-0xfba))
#define zc1cfebef6f             ((0x159f+3977-0x2527))
#define z2b17e2ee3b              ((0x1f4c+1619-0x259d))
static char_T zea4cd01646[(0x79c+8172-0x2688)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x1f44+1763-0x2627));ssSetNumDiscStates(S,(0x5ca+3260-0x1286));ssSetNumInputPorts(S,(0xb2b+1254-0x1011));ssSetNumOutputPorts(S,(uint16_T)mxGetN(z102e21cf98));for(i=(0x1a07+1452-0x1fb3);i<(uint16_T)mxGetN(z102e21cf98);i++){ssSetOutputPortWidth(S,i,(0x1a03+2335-0x2321));}ssSetNumSampleTimes(S,(0x913+2114-0x1154));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1d46+524-0x1f52));ssSetNumNonsampledZCs(S,(0x56f+7240-0x21b7));for(i=(0x371+8546-0x24d3);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1a5f+2084-0x2283));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x19b8+1246-0x1e96)]==-1.0){ssSetSampleTime(S,(0xe49+2464-0x17e9),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xd14+449-0xed5),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x20ed+1191-0x2594),mxGetPr(z3832b85a32)[(0x12c2+2581-0x1cd7)]);ssSetOffsetTime(S,(0x15ea+3647-0x2429),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;z83d93efdde*z612247fc60;z020494c81d*z183fd27444;uint32_T z366b2f03bf,z441f9e6d1b,zf91d71c6d9;if(mxGetN(z702a26a5e9)==(0xc34+5266-0x20c5)){z366b2f03bf=(0x665+749-0x952);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x300+1649-0x971)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x178a+1685-0x1e1f)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x15cf+1216-0x1a8e)];}

if(xpcGetPCIDeviceInfo(z694756a014,zea87e0ba83,z29146a1837,zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}
zeccbadd9b3.VirtAddress[(0xb15+5293-0x1fc2)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x1545+4150-0x257b)],(0x1f56+1398-0x14cc),XPC_RT_PG_USERREADWRITE);zeccbadd9b3.VirtAddress[(0x1a1c+150-0x1ab0)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x872+160-0x910)],(0x11aa+2719-0xc49),XPC_RT_PG_USERREADWRITE);
z183fd27444=(z020494c81d*)(zeccbadd9b3.VirtAddress[(0x12d4+3357-0x1fef)]);
z612247fc60=(z83d93efdde*)(zeccbadd9b3.VirtAddress[(0x1114+3398-0x1e5a)]+(0x8c3+2103-0x107a));
ssSetPWorkValue(S,zc4ce4213f7,(void*)z612247fc60);ssSetPWorkValue(S,zc1cfebef6f,(void*)z183fd27444);zf91d71c6d9=(uint32_T)mxGetN(z102e21cf98);ssSetIWorkValue(S,z3f9365e858,zf91d71c6d9);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
z020494c81d*z183fd27444=ssGetPWorkValue(S,zc1cfebef6f);uint32_T zf91d71c6d9,z718c4c15f4,z9f2f6f91bc,ze1dce08a7a,i,z8a7e6753de;real_T*zc0efaa16c3;bool z93fe8f9934;zf91d71c6d9=ssGetIWorkValue(S,z3f9365e858);z93fe8f9934=(zf91d71c6d9<(0xe4+4767-0x137b))&&((mxGetPr(z102e21cf98)[(0x7e9+3014-0x13af)]>(0x468+2888-0xfa9))?(0x66+9823-0x26c4):(0xc30+673-0xed1));z718c4c15f4=z183fd27444->z53343b042a;
for(i=(0xe35+6101-0x260a);i<zf91d71c6d9;i++){z9f2f6f91bc=(uchar_T)mxGetPr(z102e21cf98)[i]-(0xbcc+6610-0x259d);ze1dce08a7a=i+(z93fe8f9934?(0x19b7+680-0x1c57):(0x71+3389-0xdae));zc0efaa16c3=ssGetOutputPortSignal(S,ze1dce08a7a);z8a7e6753de=(0x9ba+5469-0x1f16)<<(z9f2f6f91bc+((z9f2f6f91bc>(0x2562+223-0x263a))?zd4f65135a2-(0x12e3+3455-0x205a):(0x1fec+1361-0x253d)));*zc0efaa16c3=(z718c4c15f4&z8a7e6753de)?(0x1250+3667-0x20a2):(0x11ba+439-0x1371);
}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

