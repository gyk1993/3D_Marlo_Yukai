/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0xb0d+1656-0x1183)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO104_DMA_da_s






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
#define z694756a014 (0x2008+5702-0x2599)
#define zea87e0ba83 36950
#define z29146a1837 (0x1714+7852-0x250b)
#define zab7e64468b 12658
#define z173eaebd82 (0x1562+4047-0x252d)
#define zf16899d845 (0xae3+2831-0x15ea)
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
volatile uint32_T z0156d3cf53[(0x9d3+6256-0x223f)];
}z020494c81d;
#define z28c5dfd366            (0x1868+2326-0x217e) 
#define ze9906393f1         (0x4db+6146-0x1cda) 
#define z34c5a897f9                (0x889+1468-0xe41) 
#define z5dd45f00a5                (0x516+7563-0x229b) 
#define z904e2847ca               (0x2479+453-0x2636) 
#define zf54309da44           (0xee7+3864-0x1df6) 
#define z8e173b4aa9            (0x1350+2081-0x1b67) 
#define z7459717d7c            (0x7f3+5077-0x1bbd) 
#define zaf09f9129e         (0x3bb+237-0x49c) 
#define zb7c295e611          (0x364+2090-0xb81) 
#define z2177cc8d71 (0x1047+3759-0x1ee8) 
#define zdc80a1dcc5       (0x173+2068-0x978) 
#define z2c46089855                (0x8a1+1516-0xe7d) 
#define z9c45b39fac        (0x1f26+1003-0x22ff) 
#define zc0c6d7bce0     (0xec+9031-0x2420) 
#define z452e3417e1             (0x505+7748-0x2335) 
#define z1378a8e713           (0xf73+4567-0x2135) 
#define zed9cb402fc     (0xf27+3612-0x1d2d) 
#define z28d133f1e6      (0xfac+1357-0x14e2) 
#define za74c2ed17b  (0x401+5865-0x1ad2) 
#define zbf7ff181d5               (0x192b+1354-0x1e5c) 
#define z08b102ac19     (0x10e7+1782-0x17c3) 
#define z7c2b0fb1d1     (0x8b9+5483-0x1e09) 
#define zb0261a24c5                     (0x5f0+8427-0x26bf) 
#define z8a1c8a1e84                (0xd2b+711-0xfd5) 
#define zb0499d9319   (0xc66+6822-0x26ee) 
#define INITIALIZE                  (0x3c3+7180-0x1fb0) 
#define z871ba5e63d            (0x17c9+317-0x1906) 
#define z059e80d468            (0x8+498-0x1f9)
#define zf3e0b2fa74            (0xee5+6007-0x265a)
#define zeeec8b2ebb            (0x1daa+447-0x1f66)
#define z2de56a8878  (0x9a8+1268-0xe98) 
#define za6afb27593       (0xf2c+2085-0x174c) 
#define z90687dcb41           (0x777+3679-0x15d0) 
#define z3d132243ee          (0x119+3000-0xcca) 
#define z148fc42565              (0x70+4570-0x1242) 
#define zc707c018e2                 (0x893+5231-0x1cf9) 
#define z6b55dca319                  (0xd9+6586-0x1a89) 
#define zabe89d9b05         (0x1068+3006-0x1c1b) 
#define zc738ebdc54             (0xa64+4896-0x1d78) 
#define z53f96f9a93         (0x831+213-0x8f9) 
#define z2011ff577b              (0x2c4+2737-0xd66) 
#define z48012f2ce7          (0xacc+4348-0x1bb8) 
#define z9fc17111c4              (0xfb1+2141-0x17fd) 
#define z8b72ab7941                 (0x1385+480-0x1553) 
#define zc9661f8327         (0x822+2828-0x131b) 
#define z5f5020ac0b           (0x1dc+7799-0x203f) 
#define z200bf8f7d0                   (0xc53+1197-0x1100) 
#define zc1a63d2a27               (0xffa+1602-0x1634) 
#define zd4f65135a2                  (0x1471+2080-0x1c81) 
#define zffec758124              (0x10ea+1886-0x1830) 
#define z7c9bc122b1  (0x1393+4927-0x26d2)
#define z7231b70c4f (0xc92+2125-0x14de)

#define za40af8be03           16777215 
#define z86eea319be                          (0xe9a+2490-0x183c) 

#define z95b35fa456     262143 
#define zaff3da4574           (0x2f1+2637-0xd2b) 

#define z79fb3e5887         (0x113d+3663-0x1f8c) 
#define z3f59e11cd5                 (0xa69+2691-0x14dc) 
#define z89772640d7           (0x16d+5400-0x1684) 
#define zd69c8154ae                   (0x11+2497-0x9c1) 
#define z880c27a5db             (0x1647+3516-0x2401) 
#define z93f0144cec                     (0x870+3037-0x143b) 
#define z29a6f340ee  (0x12cd+3572-0x20be) 
#define z5cffa5ee7c          (0xa03+2919-0x1557) 
#define z8507451090          (0xa65+5176-0x1e99) 
#define z8706fd3aec                  (0x7eb+4633-0x19f0) 
#define z03a425d686        (0x1bac+409-0x1d40) 
#define z9fc4ddc311                (0x12f2+2923-0x1e48) 
#define zaf55e7c759                  (0x1c08+1838-0x2330) 
#define z4e7d98be49                          (0x12d4+3132-0x1efa) 
#define zf636f129e2                  (0x20e5+124-0x215a) 
#define zc2b1ac4e1c                          (0x12b0+2585-0x1cb2) 
#define zc5e19bcda6          (0x574+6350-0x1e3a) 
#define z25f9cdfe54                  (0xc62+66-0xc8c) 
#define z77518fe65b           (0x619+86-0x666) 
#define za02048e51d                   (0x1f70+1572-0x257b) 
#define z4803b022e6            (0x1f78+1758-0x264c) 
#define z94812845d3                     (0x34b+7530-0x209b) 
#define zf1c6a6f07e  (0x4b5+4285-0x1567) 
#define z59d93d7b20           (0x8b7+5728-0x1efc) 
#define za97c522794    (0x174c+3858-0x2652) 
#define zec1b6962c1             (0x20ab+226-0x2171) 
#define zc18d6729c5           (0x1421+312-0x154c) 
#define zf9d5e888b0                    (0xf7f+2576-0x1972) 
#define z3be9d5f81a (0x14f6+1803-0x1bf3) 
#define z37a0881b22          (0xc50+1002-0x101c) 

#define z02eb2797c6    262143 
#define z5eff383092            (0x445+1511-0xa19) 

#define z18826d8f2e                   (0x882+7517-0x25cf) 
#define z21e78a36fd                    (0x886+6285-0x2102) 

#define zd77bd3455c                    (0xf77+1887-0x16c6) 

#define z0205a40243 (0x10b2+1279-0x159d)          
#define z4950fe3cb1 (((0xc49+4692-0x1e9c)<<(0x1e24+506-0x2006))-(0x6cc+5721-0x1d24)) 
#define z6e71fd742f (0x1866+1941-0x1fd3)          
#define zc19bacea26 (((0x8b+9016-0x23c2)<<(0xe19+5690-0x243b))-(0xbcc+58-0xc05)) 
#define zec8535e02c (0x276+5673-0x170f)         
#define z571e534c6e (((0x9c2+7486-0x26ff)<<(0x1277+3924-0x21b3))-(0x718+3814-0x15fd)) 
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
#define z551c6433ad        (0x870+1732-0xf34) 
#define z9ff50a1d47      (0x14f0+978-0x18c0) 
#define z60fa808c68      (0x1822+476-0x19f8) 
#define za495e5447f  (0xd45+1986-0x1500) 
#define ze284f6dda4   (0x560+6395-0x1e53) 
#define zbd9cc3ea3e   (0x17d0+3390-0x2505) 
#define z72a2273697     (0x14c9+4558-0x268d) 
#define zb538b13023  (0x41a+5293-0x18bc) 
#define z082f6638ca     (0xf15+2269-0x17e6) 
#define ze57bee66e7  (0xcd9+1783-0x13c3) 
#define ze8cdd8692c      (0xb77+3662-0x19b7) 
#define z48a21f4939  (0x1018+2252-0x18d5) 
#define z6bd25a24d0  (0x701+7588-0x2495) 
#define z3471c69077      (0x193+3224-0xe1a) 
#define zf9faf82f5c  (0x636+481-0x805) 
#define zf04451bb1a (0x1717+1160-0x1b8c) 
#define z6e73a222da   (0x1aba+1135-0x1f15) 
#define z25384e33ac    (0x9db+3762-0x1878) 

#define z9b226a1cab     (0x1baf+384-0x1d2f)
#define z583be2f5c1     (0xee8+2966-0x1a7d)
#define z2472b0b295   (0xed4+3905-0x1e13)
#define zecc0da7a42      (0xed5+4409-0x200b)

#define z08d0b4e518  (0x23f6+218-0x24d0) 
#define z3e27e0685c  (0xc78+2988-0x1823) 
#define zc7139e459d  (0x6a1+888-0xa17) 
#define zb7f318c2a8 (0x451+1414-0x9d4) 
#define zb7eaca017a   (0x5c7+1464-0xb7b) 
typedef volatile struct z4324a84488{volatile uint32_T zb76599274b;volatile uint32_T cntrl;}za6edc6d81a;
#define zfb2170cd8e (0x112a+4901-0x2448)
#define z445a635dd2      (0x5fd+3424-0x1355) 
#define z3c87fa7ea1 (0x14da+1105-0x1919) 
#define z82868178d9 (0x1f23+1287-0x2415) 
#define zbbbb241a6c (0x271+868-0x5bf)


#define zd03e44657a  (0x19e9+1736-0x20b0)
#define z4ef2da205f (0xa89+2507-0x1452)
#define z4292246d73 (0x964+689-0xc14)
#define z1bf87cb58b (0x658+8150-0x262d)
#define TARGET (0x3d1+488-0x5b9)
#define z141532d9e2 (0x1ef+1915-0x969)
#define z1ca0467348 (0xbba+3285-0x188e)





#define z702a26a5e9                ssGetSFcnParam(S,  (0x51b+1567-0xb3a)) 
#define z38de3397f8    ssGetSFcnParam(S,  (0x823+472-0x9fa)) 
#define zeda2a9d389   ssGetSFcnParam(S,  (0xbcd+6954-0x26f5)) 
#define z0f4f8c2101        ssGetSFcnParam(S,  (0x11b+4352-0x1218)) 
#define z143c69c545         ssGetSFcnParam(S,  (0x892+3426-0x15f0)) 
#define z15e14cdb28  ssGetSFcnParam(S,  (0xd1d+4849-0x2009)) 
#define zc122b0a510         ssGetSFcnParam(S,  (0x2268+887-0x25d9)) 
#define z84dd9a9a5c            ssGetSFcnParam(S,  (0x651+2559-0x1049)) 
#define zc6f930323f            ssGetSFcnParam(S,  (0xd27+924-0x10bb)) 
#define zf4aff54a03      ssGetSFcnParam(S,  (0x3fc+3500-0x119f)) 
#define z8c935c4ad2       ssGetSFcnParam(S, (0x55d+5230-0x19c1)) 
#define z1fb64fe2c5      ssGetSFcnParam(S, (0x1c9c+2223-0x2540)) 
#define z4242341ac8    ssGetSFcnParam(S, (0xd12+2591-0x1725)) 
#define zdf24515981                        (   (0x14fc+4344-0x25e7)) 
#define zc2f3e0cbc0        ((0x371+2444-0xcfd))
#define zba952b5889      ((0x1c49+1989-0x240d)) 
#define z2e6483d505              (zba952b5889 + z173eaebd82)
#define z8caad2a8e6              ((0x65d+2996-0x1211))
#define z5bfe7a2613            ((0x4b3+3009-0x1073))
#define zc5ce4cb81a              ((0x6f0+2671-0x115d))
#define zc4ce4213f7               ((0x1199+4977-0x250a))
#define zc1cfebef6f             ((0x1db8+465-0x1f88))
#define z7a0bc5653f        ((0x169+109-0x1d4))
#define z2b17e2ee3b              ((0x22d+1121-0x68b))
static char_T zea4cd01646[(0x233+2746-0xbed)];static void zc2f11ccb7a(real_T t);static void zc2f11ccb7a(real_T t){
#ifndef MATLAB_MEX_FILE
xpcTime z9764181524,zce60958e79,zde9131ca7b;xpcGetElapsedTime(&z9764181524);do{xpcGetElapsedTime(&zce60958e79);xpcSubtractTime(&zde9131ca7b,&zce60958e79,&z9764181524);}while((((real_T)zde9131ca7b.U64.NanoSecondsLo*1e-9)+((real_T)zde9131ca7b.U64.NanoSecondsHi*4.294967296))<t);
#endif
}static uint32_T z30183ef48c(void);static uint32_T z30183ef48c(void){
#ifndef MATLAB_MEX_FILE
xpcTime t;xpcGetElapsedTime(&t);return(uint32_T)t.U64.NanoSecondsLo/(0xbd9+766-0xaef);
#endif
}static int z8407d5ceb3(SimStruct*S,z020494c81d*z183fd27444);static int z8407d5ceb3(SimStruct*S,z020494c81d*z183fd27444){
#ifndef MATLAB_MEX_FILE
uint32_T b,c;
z183fd27444->zf66194a2f2|=((0x15a+447-0x318)<<zabe89d9b05);b=z183fd27444->zf66194a2f2;c=(0xdf1+1568-0x1411);while(b&((0x40f+2494-0xdcc)<<zabe89d9b05)){zc2f11ccb7a(0.1);
c++;b=z183fd27444->zf66194a2f2;if(c>=(0x18c2+851-0x1c01))
{sprintf(zea4cd01646,"\x25\x73\x20\x54\x69\x6d\x65\x6f\x75\x74\x20\x77\x61\x69\x74\x69\x6e\x67\x20\x66\x6f\x72\x20\x63\x6c\x65\x61\x72\x69\x6e\x67\x20\x6f\x75\x74\x70\x75\x74\x20\x62\x75\x66\x66\x65\x72\x2e" "\n",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return-(0xf0d+5232-0x237c);
}}return(0xfc5+991-0x13a4);
#endif
}
#ifdef z3bfc590c91
static void z288de859c0(z020494c81d*z183fd27444,uint32_T bit,uint32_T value);static void z288de859c0(z020494c81d*z183fd27444,uint32_T bit,uint32_T value){
#ifndef MATLAB_MEX_FILE
uint32_T z5450d078d5;if(!z183fd27444){printf("\x73\x65\x74\x44\x4f\x3a\x20\x70\x49\x4f\x31\x30\x34\x20\x69\x73\x20\x4e\x55\x4c\x4c" "\n");return;}if((bit>(0x242b+632-0x269c))||(value>(0x16a8+2581-0x20bc))){printf("\x73\x65\x74\x44\x4f\x3a\x20\x62\x61\x64\x20\x70\x61\x72\x61\x6d" "\n");return;}z5450d078d5=z183fd27444->z53343b042a;if(value)z5450d078d5|=((0x1a65+836-0x1da8)<<bit);else z5450d078d5&=~((0x22c+4980-0x159f)<<bit);z5450d078d5|=(z7231b70c4f<<zc1a63d2a27);z183fd27444->z53343b042a=z5450d078d5;
#endif
}static void z190ad20cb8(z020494c81d*z183fd27444,uint32_T bit);static void z190ad20cb8(z020494c81d*z183fd27444,uint32_T bit){
#ifndef MATLAB_MEX_FILE
uint32_T z5450d078d5;if(!z183fd27444){printf("\x74\x67\x6c\x44\x4f\x3a\x20\x70\x49\x4f\x31\x30\x34\x20\x69\x73\x20\x4e\x55\x4c\x4c" "\n");return;}if((bit>(0x7ef+3697-0x1659))){printf("\x74\x67\x6c\x44\x4f\x3a\x20\x62\x61\x64\x20\x70\x61\x72\x61\x6d" "\n");return;}z5450d078d5=z183fd27444->z53343b042a;if(z5450d078d5&((0x32b+731-0x605)<<bit))z5450d078d5&=~((0x1119+5313-0x25d9)<<bit);else z5450d078d5|=((0x10cc+575-0x130a)<<bit);z5450d078d5|=(z7231b70c4f<<zc1a63d2a27);z183fd27444->z53343b042a=z5450d078d5;
#endif
}
#else
#define z190ad20cb8(z183fd27444, bit) {}
#define z288de859c0(z183fd27444, bit, value) {}
#endif
static void mdlInitializeSizes(SimStruct*S){uint32_T i,z6aa707ac85,zd8a0291585;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c" 
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x119f+5164-0x25cb));ssSetNumDiscStates(S,(0xbc6+4973-0x1f33));ssSetNumOutputPorts(S,(0x306+8128-0x22c6));ssSetNumInputPorts(S,(int)mxGetN(z143c69c545));z6aa707ac85=(uint32_T)*mxGetPr(z8c935c4ad2);zd8a0291585=(uint32_T)mxGetN(z143c69c545);if(zd8a0291585==(0x108d+4312-0x2164)&&(uint32_T)mxGetPr(z143c69c545)[(0x2da+5461-0x182f)]==(0x414+7660-0x2200))
zd8a0291585=(0x51f+1617-0xb70);for(i=(0xbbc+3445-0x1931);i<zd8a0291585;i++){ssSetInputPortWidth(S,i,z6aa707ac85);ssSetInputPortDirectFeedThrough(S,i,(0x57+4649-0x127f));ssSetInputPortRequiredContiguous(S,i,(0xcb+5771-0x1755));}ssSetNumSampleTimes(S,(0x597+6928-0x20a6));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xc7d+4630-0x1e93));ssSetNumNonsampledZCs(S,(0x22ad+580-0x24f1));for(i=(0x73c+4371-0x184f);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x61b+4261-0x16c0));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){real_T Ts=mxGetPr(z38de3397f8)[(0x11d+5646-0x172b)];if(Ts==-1.0){ssSetSampleTime(S,(0x121f+3741-0x20bc),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x849+5188-0x1c8d),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x364+2738-0xe16),Ts);ssSetOffsetTime(S,(0x1aa+2900-0xcfe),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;z83d93efdde*z612247fc60;z020494c81d*z183fd27444;uint32_T z366b2f03bf,z441f9e6d1b,range;uint32_T zd8a0291585;uint32_T i,z9f2f6f91bc,ze1dce08a7a;int z3f409ba692;
#ifdef zb482f925e2
printf("\x44\x41\x2e\x6d\x64\x6c\x53\x74\x61\x72\x74\x20\x28\x25\x73\x69\x6e\x69\x74\x29" "\n",(xpceIsModelInit())?"":"\x6e\x6f\x6e\x2d");
#endif
#ifdef z1919c093bf


#endif
if(mxGetN(z702a26a5e9)==(0xea6+4352-0x1fa5)){z366b2f03bf=(0x296+1341-0x7d3);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xebd+2027-0x16a8)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x1344+3347-0x2057)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xc05+52-0xc38)];}

if(xpcGetPCIDeviceInfo(z694756a014,zea87e0ba83,z29146a1837,zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}
zeccbadd9b3.VirtAddress[(0x6cd+5893-0x1dd2)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x76f+6198-0x1fa5)],(0x1053+6996-0x1ba7),XPC_RT_PG_USERREADWRITE);zeccbadd9b3.VirtAddress[(0xfab+1609-0x15f2)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x6a2+2339-0xfc3)],(0x11ea+8300-0x2256),XPC_RT_PG_USERREADWRITE);
z183fd27444=(z020494c81d*)(zeccbadd9b3.VirtAddress[(0x1038+654-0x12c4)]);
z612247fc60=(z83d93efdde*)(zeccbadd9b3.VirtAddress[(0x2165+670-0x2403)]+(0x12fd+2314-0x1b87));
ssSetPWorkValue(S,zc4ce4213f7,(void*)z612247fc60);ssSetPWorkValue(S,zc1cfebef6f,(void*)z183fd27444);
zd8a0291585=(uint32_T)mxGetN(z143c69c545);if(zd8a0291585==(0x471+8513-0x25b1)&&(uint32_T)mxGetPr(z143c69c545)[(0x1dc1+543-0x1fe0)]==(0x9e5+732-0xcc1))
zd8a0291585=(0x66c+4952-0x19c4);ssSetIWorkValue(S,zc2f3e0cbc0,zd8a0291585);z3f409ba692=((uint32_T)*mxGetPr(zf4aff54a03)==z1ca0467348)?(0x330+7321-0x1fc8):(0x2562+63-0x25a1);switch((uint16_T)mxGetPr(zc6f930323f)[(0x18a3+705-0x1b64)]){case(0x935+6083-0x20f7):ssSetRWorkValue(S,z8caad2a8e6,3276.8);ssSetRWorkValue(S,z5bfe7a2613,10.0);range=(0xdf1+782-0x10fd);break;case(0xf21+5490-0x2491):ssSetRWorkValue(S,z8caad2a8e6,6553.6);ssSetRWorkValue(S,z5bfe7a2613,5.0);range=(0x4b+6656-0x1a4a);break;case(0x100f+3682-0x1e6e):ssSetRWorkValue(S,z8caad2a8e6,13107.2);ssSetRWorkValue(S,z5bfe7a2613,2.5);range=(0xe22+475-0xffd);break;}

for(i=(0x931+5133-0x1d3e);i<zd8a0291585;i++){z9f2f6f91bc=(uint32_T)mxGetPr(z15e14cdb28)[i];

for(ze1dce08a7a=(0x94+9767-0x26bb);ze1dce08a7a<z173eaebd82;ze1dce08a7a++){if(mxGetPr(z143c69c545)[ze1dce08a7a]==z9f2f6f91bc){ssSetIWorkValue(S,zba952b5889+z9f2f6f91bc-(0x2159+849-0x24a9),ze1dce08a7a);
break;}}}
if(z612247fc60->z37045d746d&((0xfb+1525-0x6ef)<<zecc0da7a42))
{ssSetPWorkValue(S,z7a0bc5653f,(void*)z612247fc60->z0aa1aefd2d);}else{ssSetPWorkValue(S,z7a0bc5653f,(void*)z612247fc60->ze467ac829e);}if(!xpceIsModelInit()){if(z8407d5ceb3(S,z183fd27444))return;

{


}z288de859c0(z183fd27444,(0x82d+4703-0x1a8c),(0xa61+1346-0xfa3));}else{z288de859c0(z183fd27444,(0xd6+8439-0x21cd),(0x13df+4184-0x2436));}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
z83d93efdde*z612247fc60=ssGetPWorkValue(S,zc4ce4213f7);z020494c81d*z183fd27444=ssGetPWorkValue(S,zc1cfebef6f);uint32_T*z77cb1c2f42;real_T*z2a6249eb7a;real_T z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6);real_T offset=ssGetRWorkValue(S,z5bfe7a2613);uint32_T zf91d71c6d9=ssGetIWorkValue(S,zc2f3e0cbc0);uint32_T z6aa707ac85=(uint32_T)*mxGetPr(z8c935c4ad2);uint32_T i,z9f2f6f91bc,z2f01869a88,z0302abc276,ze1dce08a7a,z14bc320aa4,zf66194a2f2,z756a2380a7;int32_T out;
#ifdef z65139427e8
printf("\x44\x41\x2e\x6d\x64\x6c\x4f\x75\x74\x70\x75\x74\x73\x20\x62\x65\x67\x69\x6e" "\n");
#endif
if(!z183fd27444){printf("\x44\x41\x20\x6d\x64\x6c\x4f\x75\x74\x70\x75\x74\x73\x28\x29\x3a\x20\x70\x49\x4f\x31\x30\x34\x20\x69\x73\x20\x4e\x55\x4c\x4c" "\n");return;}z288de859c0(z183fd27444,(0x7dc+6194-0x200e),(0xaa4+4817-0x1d74));z14bc320aa4=z183fd27444->z14bc320aa4;z756a2380a7=(z14bc320aa4&((0x417+8929-0x26f7)<<zc0c6d7bce0))?(0x255+4411-0x138f):(0xde1+1111-0x1238);if(z756a2380a7)
{if(!(z14bc320aa4&((0x1d8f+2270-0x266c)<<zed9cb402fc)))
{zf66194a2f2=z183fd27444->zf66194a2f2;if(zf66194a2f2&((0xd08+4696-0x1f5f)<<zc9661f8327))
{z14bc320aa4|=((0x112c+1898-0x1895)<<zed9cb402fc);
if((z14bc320aa4&((0x19e0+3139-0x2622)<<z1378a8e713))
&&!(z14bc320aa4&((0x1c45+352-0x1da4)<<z7c2b0fb1d1)))
{z14bc320aa4|=((0xe21+5722-0x247a)<<z7c2b0fb1d1);}}if((0x98b+416-0xb2a)
&&(z14bc320aa4&((0x1817+3169-0x2477)<<za74c2ed17b))
&&!(z14bc320aa4&((0x3e4+5494-0x1959)<<z08b102ac19)))
{z14bc320aa4|=((0x1503+1344-0x1a42)<<z08b102ac19);
}z183fd27444->z14bc320aa4=z14bc320aa4;}
z77cb1c2f42=ssGetPWorkValue(S,z7a0bc5653f);if(!z77cb1c2f42){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x44\x41\x20\x70\x44\x6d\x61\x42\x75\x66\x20\x69\x73\x20\x4e\x55\x4c\x4c\x20" "\n",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}for(i=(0x244+4525-0x13f1);i<zf91d71c6d9;i++){z9f2f6f91bc=(uint16_T)mxGetPr(z15e14cdb28)[i]-(0x278+8162-0x2259);ze1dce08a7a=ssGetIWorkValue(S,zba952b5889+z9f2f6f91bc);
z2a6249eb7a=(real_T*)ssGetInputPortRealSignal(S,ze1dce08a7a);if(!z2a6249eb7a){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x44\x41\x20\x70\x55\x20\x28\x63\x68\x20\x25\x69\x29\x20\x69\x73\x20\x4e\x55\x4c\x4c\x20" "\n",zf1b619edf2,z9f2f6f91bc);ssSetErrorStatus(S,zea4cd01646);return;}
for(z2f01869a88=(0xba6+5962-0x22f0),z0302abc276=z9f2f6f91bc;z2f01869a88<z6aa707ac85;z2f01869a88++,z0302abc276+=zf91d71c6d9){out=(int32_T)((z2a6249eb7a[z2f01869a88]+offset)*z0754dd67cc);if(out>65535)out=65535;else if(out<(0x11f5+758-0x14eb))out=(0x5d3+4923-0x190e);z77cb1c2f42[z0302abc276]=out;}}z612247fc60->z851354b1dc=((0x6c5+7179-0x22cf)<<z08d0b4e518)|((0x1664+3262-0x2321)<<z3e27e0685c);if(*mxGetPr(z4242341ac8)==(0x2a3+5957-0x19e8)){z612247fc60->z1def6086f7=((0x1366+975-0x1734)<<z08d0b4e518);z612247fc60->z1def6086f7=((0x1c06+1732-0x22c9)<<z08d0b4e518)|((0x158b+3182-0x21f8)<<z3e27e0685c);}}else
{for(i=(0x6f4+6273-0x1f75);i<zf91d71c6d9;i++){z9f2f6f91bc=(uint16_T)mxGetPr(z15e14cdb28)[i]-(0x24b+6573-0x1bf7);ze1dce08a7a=ssGetIWorkValue(S,zba952b5889+z9f2f6f91bc);
z2a6249eb7a=(real_T*)ssGetInputPortRealSignal(S,ze1dce08a7a);out=(int32_T)((*z2a6249eb7a+offset)*z0754dd67cc);if(out>65535)out=65535;else if(out<(0x166a+3174-0x22d0))out=(0x187+8446-0x2285);z183fd27444->zed3e896995[z9f2f6f91bc]=out;
}z183fd27444->z14bc320aa4=z14bc320aa4=z14bc320aa4|((0xc40+945-0xff0)<<z452e3417e1);
}
#ifdef z65139427e8
printf("\x44\x41\x2e\x6d\x64\x6c\x4f\x75\x74\x70\x75\x74\x73\x20\x65\x6e\x64" "\n");
#endif
z288de859c0(z183fd27444,(0xf4d+5996-0x26b9),(0x16d8+4003-0x267b));
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
z020494c81d*z183fd27444=ssGetPWorkValue(S,zc1cfebef6f);
#ifdef zb482f925e2
printf("\x44\x41\x2e\x6d\x64\x6c\x54\x65\x72\x6d\x69\x6e\x61\x74\x65\x20\x28\x25\x73\x69\x6e\x69\x74\x29" "\n",(xpceIsModelInit())?"":"\x6e\x6f\x6e\x2d");
#endif
z288de859c0(z183fd27444,(0x8c+657-0x31d),(0x240+6911-0x1d3e));if(!xpceIsModelInit()){z8407d5ceb3(S,z183fd27444);}
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

