/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1b99+2331-0x24b2)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO104_DMA_do_s 






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
#define z694756a014 (0x1770+1346-0xbfd)
#define zea87e0ba83 36950
#define z29146a1837 (0x1328+200-0x33b)
#define zab7e64468b 12658
#define z173eaebd82 (0x3b7+5275-0x184e)
#define zf16899d845 (0xb79+6678-0x2587)
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
volatile uint32_T z0156d3cf53[(0x12c7+1825-0x19e4)];
}z020494c81d;
#define z28c5dfd366            (0x1124+2267-0x19ff) 
#define ze9906393f1         (0xc53+5915-0x236b) 
#define z34c5a897f9                (0x1884+294-0x19a6) 
#define z5dd45f00a5                (0x112d+2387-0x1a7a) 
#define z904e2847ca               (0x435+661-0x6c2) 
#define zf54309da44           (0x1fa+2421-0xb66) 
#define z8e173b4aa9            (0x62c+5040-0x19d2) 
#define z7459717d7c            (0x1a14+603-0x1c64) 
#define zaf09f9129e         (0xcb4+4334-0x1d96) 
#define zb7c295e611          (0x928+7646-0x26f9) 
#define z2177cc8d71 (0x2dc+3451-0x1049) 
#define zdc80a1dcc5       (0x687+4436-0x17cc) 
#define z2c46089855                (0x560+4458-0x16ba) 
#define z9c45b39fac        (0x887+1941-0x100a) 
#define zc0c6d7bce0     (0xf84+3984-0x1f01) 
#define z452e3417e1             (0x1df+2808-0xcc3) 
#define z1378a8e713           (0xfca+3571-0x1da8) 
#define zed9cb402fc     (0x912+6265-0x2175) 
#define z28d133f1e6      (0xb5b+4528-0x1cf4) 
#define za74c2ed17b  (0x1bef+2629-0x261c) 
#define zbf7ff181d5               (0x9e2+2016-0x11a9) 
#define z08b102ac19     (0x1c18+1561-0x2217) 
#define z7c2b0fb1d1     (0xfa8+4015-0x1f3c) 
#define zb0261a24c5                     (0x904+6750-0x2346) 
#define z8a1c8a1e84                (0x1276+4509-0x23f6) 
#define zb0499d9319   (0xce7+4826-0x1fa3) 
#define INITIALIZE                  (0x1bf9+2731-0x2685) 
#define z871ba5e63d            (0x1311+3927-0x2268) 
#define z059e80d468            (0x150+3330-0xe51)
#define zf3e0b2fa74            (0x106d+2926-0x1bd9)
#define zeeec8b2ebb            (0x284+14-0x28f)
#define z2de56a8878  (0x813+7335-0x24b6) 
#define za6afb27593       (0xa1+214-0x172) 
#define z90687dcb41           (0xaef+828-0xe25) 
#define z3d132243ee          (0x167b+2280-0x1f5c) 
#define z148fc42565              (0xaa8+3780-0x1964) 
#define zc707c018e2                 (0x3c4+8271-0x240a) 
#define z6b55dca319                  (0x1288+714-0x1548) 
#define zabe89d9b05         (0x5a+5249-0x14d0) 
#define zc738ebdc54             (0x254+5678-0x1876) 
#define z53f96f9a93         (0x5d2+3318-0x12bb) 
#define z2011ff577b              (0x5a7+7694-0x23a6) 
#define z48012f2ce7          (0x15c2+3591-0x23b9) 
#define z9fc17111c4              (0x95a+2277-0x122e) 
#define z8b72ab7941                 (0x161c+1539-0x1c0d) 
#define zc9661f8327         (0x77f+7709-0x2589) 
#define z5f5020ac0b           (0x6ea+6076-0x1e92) 
#define z200bf8f7d0                   (0x58a+195-0x64d) 
#define zc1a63d2a27               (0x1b+7879-0x1eda) 
#define zd4f65135a2                  (0x2d3+233-0x3ac) 
#define zffec758124              (0x165b+1472-0x1c03) 
#define z7c9bc122b1  (0x1a0+1265-0x691)
#define z7231b70c4f (0x126f+3241-0x1f17)

#define za40af8be03           16777215 
#define z86eea319be                          (0x173a+1037-0x1b2f) 

#define z95b35fa456     262143 
#define zaff3da4574           (0xb36+1868-0x126f) 

#define z79fb3e5887         (0x1537+4217-0x25b0) 
#define z3f59e11cd5                 (0xa49+4401-0x1b6a) 
#define z89772640d7           (0xccb+1117-0x1127) 
#define zd69c8154ae                   (0xa82+6582-0x2427) 
#define z880c27a5db             (0x2a7+4899-0x15c8) 
#define z93f0144cec                     (0x83d+7020-0x2397) 
#define z29a6f340ee  (0x12f0+2043-0x1ae8) 
#define z5cffa5ee7c          (0x1f54+680-0x21e9) 
#define z8507451090          (0xa8d+2838-0x159f) 
#define z8706fd3aec                  (0x1b67+1191-0x1ffa) 
#define z03a425d686        (0x467+1816-0xb7a) 
#define z9fc4ddc311                (0x8e4+87-0x926) 
#define zaf55e7c759                  (0xc65+1906-0x13d1) 
#define z4e7d98be49                          (0x654+4492-0x17ca) 
#define zf636f129e2                  (0x1189+538-0x139c) 
#define zc2b1ac4e1c                          (0x2dc+6586-0x1c7f) 
#define zc5e19bcda6          (0x15d8+3442-0x2342) 
#define z25f9cdfe54                  (0x12f1+181-0x138e) 
#define z77518fe65b           (0x43d+749-0x721) 
#define za02048e51d                   (0xf2+3605-0xeee) 
#define z4803b022e6            (0xa5+3593-0xea4) 
#define z94812845d3                     (0x8c6+7262-0x250a) 
#define zf1c6a6f07e  (0x1c13+577-0x1e49) 
#define z59d93d7b20           (0x2d7+4099-0x12bf) 
#define za97c522794    (0x513+1289-0xa10) 
#define zec1b6962c1             (0x1da7+335-0x1eda) 
#define zc18d6729c5           (0x764+6688-0x2177) 
#define zf9d5e888b0                    (0x1723+1935-0x1e95) 
#define z3be9d5f81a (0x1b71+2297-0x245c) 
#define z37a0881b22          (0x3c7+2550-0xd9f) 

#define z02eb2797c6    262143 
#define z5eff383092            (0x20ac+758-0x238f) 

#define z18826d8f2e                   (0x694+1682-0xd16) 
#define z21e78a36fd                    (0xbc7+4164-0x1bfa) 

#define zd77bd3455c                    (0x9f4+3284-0x16b8) 

#define z0205a40243 (0x3a7+5375-0x1892)          
#define z4950fe3cb1 (((0xb06+179-0xbb8)<<(0x54+5171-0x146f))-(0x1687+2493-0x2043)) 
#define z6e71fd742f (0x73a+6170-0x1f2c)          
#define zc19bacea26 (((0x62a+2844-0x1145)<<(0x8c+9834-0x26de))-(0x16f8+2350-0x2025)) 
#define zec8535e02c (0x10e2+2532-0x1936)         
#define z571e534c6e (((0x1836+809-0x1b5e)<<(0x64a+64-0x672))-(0x1742+4006-0x26e7)) 
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
#define z551c6433ad        (0xa57+6828-0x2503) 
#define z9ff50a1d47      (0x1ca+1055-0x5e7) 
#define z60fa808c68      (0x107f+1962-0x1823) 
#define za495e5447f  (0x43a+1277-0x930) 
#define ze284f6dda4   (0x383+1504-0x95b) 
#define zbd9cc3ea3e   (0xd00+1036-0x1103) 
#define z72a2273697     (0x1192+885-0x14fd) 
#define zb538b13023  (0x348+8394-0x2407) 
#define z082f6638ca     (0x1118+3095-0x1d23) 
#define ze57bee66e7  (0x201c+1633-0x2670) 
#define ze8cdd8692c      (0x17bc+3889-0x26df) 
#define z48a21f4939  (0x2313+911-0x2693) 
#define z6bd25a24d0  (0xd22+817-0x1043) 
#define z3471c69077      (0xdc4+5132-0x21bf) 
#define zf9faf82f5c  (0xc32+3961-0x1b99) 
#define zf04451bb1a (0xb97+4317-0x1c61) 
#define z6e73a222da   (0x117a+2630-0x1bac) 
#define z25384e33ac    (0x9e0+1812-0x10df) 

#define z08d0b4e518  (0x5c4+5983-0x1d23) 
#define z3e27e0685c  (0x67b+3902-0x15b8) 
#define zc7139e459d  (0x253+2458-0xbeb) 
#define zb7f318c2a8 (0x149a+208-0x1567) 
#define zb7eaca017a   (0xd9f+3097-0x19b4) 
typedef volatile struct z4324a84488{volatile uint32_T zb76599274b;volatile uint32_T cntrl;}za6edc6d81a;
#define zfb2170cd8e (0x65d+5002-0x19e0)
#define z445a635dd2      (0x1cc+5788-0x1860) 
#define z3c87fa7ea1 (0x42+5753-0x16a9) 
#define z82868178d9 (0x976+1018-0xd5b) 
#define zbbbb241a6c (0x442+5135-0x183b)


#define zd03e44657a  (0x3d2+6855-0x1e98)
#define z4ef2da205f (0xaa8+871-0xe0d)
#define z4292246d73 (0x12bd+4245-0x2351)
#define z1bf87cb58b (0xd8c+4654-0x1fb9)
#define TARGET (0x16d1+1294-0x1bdf)
#define z141532d9e2 (0x69b+1740-0xd66)
#define z1ca0467348 (0x964+673-0xc04)




#define z96b1a4487e          ssGetSFcnParam(S,(0x1c80+2450-0x2612))
#define z702a26a5e9                ssGetSFcnParam(S,(0x17c3+1986-0x1f84))
#define z3832b85a32           ssGetSFcnParam(S,(0xed8+321-0x1017))
#define z1038324b81       ssGetSFcnParam(S,(0x1252+2317-0x1b5c))
#define z724139b233            ssGetSFcnParam(S,(0x135d+859-0x16b4))
#define zdf24515981                          ((0x19a5+742-0x1c86))
#define z3f9365e858        ((0x19cd+1398-0x1f43))
#define z2e6483d505              ((0x452+4162-0x1493))
#define zc5ce4cb81a              ((0xf86+3462-0x1d0c))
#define zc4ce4213f7               ((0x304+793-0x61d))
#define zc1cfebef6f             ((0x5a5+5402-0x1abe))
#define z2b17e2ee3b              ((0x2e2+5748-0x1954))
static char_T zea4cd01646[(0x66b+4112-0x157b)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e\x20\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x459+5866-0x1b43));ssSetNumDiscStates(S,(0x1423+1432-0x19bb));ssSetNumOutputPorts(S,(0x1465+3662-0x22b3));ssSetNumInputPorts(S,(uint16_T)mxGetN(z96b1a4487e));for(i=(0x6f4+6032-0x1e84);i<(uint16_T)mxGetN(z96b1a4487e);i++){ssSetInputPortWidth(S,i,(0x458+2836-0xf6b));ssSetInputPortDirectFeedThrough(S,i,(0x1112+2678-0x1b87));ssSetInputPortRequiredContiguous(S,i,(0x1352+5028-0x26f5));}ssSetNumSampleTimes(S,(0xf24+1400-0x149b));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x924+2500-0x12e8));ssSetNumNonsampledZCs(S,(0x8f+8627-0x2242));for(i=(0x23d0+598-0x2626);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xfa9+4620-0x21b5));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x1417+243-0x150a)]==-1.0){ssSetSampleTime(S,(0x91c+5311-0x1ddb),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x2e3+6199-0x1b1a),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xc63+5993-0x23cc),mxGetPr(z3832b85a32)[(0x120d+3673-0x2066)]);ssSetOffsetTime(S,(0xb5b+5154-0x1f7d),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;z83d93efdde*z612247fc60;z020494c81d*z183fd27444;uint32_T z366b2f03bf,z441f9e6d1b,zf91d71c6d9;if(mxGetN(z702a26a5e9)==(0x149+2611-0xb7b)){z366b2f03bf=(0xb94+5011-0x1f27);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xf4b+3160-0x1ba3)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x4aa+476-0x686)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x1911+1456-0x1ec0)];}

if(xpcGetPCIDeviceInfo(z694756a014,zea87e0ba83,z29146a1837,zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}
zeccbadd9b3.VirtAddress[(0x644+1104-0xa94)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x1bf3+550-0x1e19)],(0x115d+2025-0x946),XPC_RT_PG_USERREADWRITE);zeccbadd9b3.VirtAddress[(0x652+5919-0x1d6f)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x209+677-0x4ac)],(0x1284+8911-0x2553),XPC_RT_PG_USERREADWRITE);
z183fd27444=(z020494c81d*)(zeccbadd9b3.VirtAddress[(0x33a+1036-0x744)]);
z612247fc60=(z83d93efdde*)(zeccbadd9b3.VirtAddress[(0xb7f+1055-0xf9e)]+(0x178+3039-0xcd7));
ssSetPWorkValue(S,zc4ce4213f7,(void*)z612247fc60);ssSetPWorkValue(S,zc1cfebef6f,(void*)z183fd27444);zf91d71c6d9=(uint32_T)mxGetN(z96b1a4487e);ssSetIWorkValue(S,z3f9365e858,zf91d71c6d9);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
z020494c81d*z183fd27444=ssGetPWorkValue(S,zc1cfebef6f);uint32_T zf91d71c6d9,z718c4c15f4,bit,z9f2f6f91bc,ze1dce08a7a,i;real_T const*z2a6249eb7a;bool z93fe8f9934;zf91d71c6d9=ssGetIWorkValue(S,z3f9365e858);z93fe8f9934=((zf91d71c6d9>(0xe83+437-0x1030))||(mxGetPr(z96b1a4487e)[(0x717+2816-0x1217)]>(0x196+4992-0x150f)))?(0xacd+998-0xeb2):(0xdb+506-0x2d5);z718c4c15f4=z183fd27444->z53343b042a;
for(i=(0x5c3+301-0x6f0);i<zf91d71c6d9;i++){z9f2f6f91bc=(uint32_T)mxGetPr(z96b1a4487e)[i]-(0x327+7111-0x1eed);ze1dce08a7a=i+((z93fe8f9934)?(0x59a+3673-0x13f3):(0xd21+2791-0x1800));z2a6249eb7a=ssGetInputPortRealSignal(S,ze1dce08a7a);bit=((0xd44+2581-0x1758)<<(z9f2f6f91bc+((z9f2f6f91bc>(0x1ad+6188-0x19d2))?(zd4f65135a2-(0x10c8+192-0x1180)):(0x1cb+1613-0x818))));if(*z2a6249eb7a){z718c4c15f4|=bit;
}else{z718c4c15f4&=~bit;
}}z183fd27444->z53343b042a=z718c4c15f4;
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
z020494c81d*z183fd27444=ssGetPWorkValue(S,zc1cfebef6f);uint32_T zf91d71c6d9=ssGetIWorkValue(S,z3f9365e858);uint32_T z718c4c15f4,bit,z9f2f6f91bc,i;
#ifdef zb482f925e2
printf("\x44\x4f\x2e\x6d\x64\x6c\x54\x65\x72\x6d\x69\x6e\x61\x74\x65\x20\x28\x25\x73\x69\x6e\x69\x74\x29" "\n",(xpceIsModelInit())?"":"\x6e\x6f\x6e\x2d");
#endif

z718c4c15f4=z183fd27444->z53343b042a;
for(i=(0x483+4782-0x1731);i<zf91d71c6d9;i++){if(xpceIsModelInit()||(int)mxGetPr(z724139b233)[i]){z9f2f6f91bc=(uint32_T)mxGetPr(z96b1a4487e)[i]-(0x80c+1341-0xd48);bit=((0x8b9+3216-0x1548)<<(z9f2f6f91bc+((z9f2f6f91bc>(0xbef+5098-0x1fd2))?(zd4f65135a2-(0xe49+1578-0x146b)):(0xfad+3146-0x1bf7))));if(mxGetPr(z1038324b81)[i]){z718c4c15f4|=bit;
}else{z718c4c15f4&=~bit;
}}}
z183fd27444->z53343b042a=z718c4c15f4;
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

