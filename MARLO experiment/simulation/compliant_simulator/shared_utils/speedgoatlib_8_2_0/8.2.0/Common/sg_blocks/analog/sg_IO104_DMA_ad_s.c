/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x154c+1016-0x1942)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO104_DMA_ad_s






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
#define z694756a014 (0x13e9+3013-0xef9)
#define zea87e0ba83 36950
#define z29146a1837 (0x1d97+1290-0x11ec)
#define zab7e64468b 12658
#define z173eaebd82 (0x1678+2428-0x1ff0)
#define zf16899d845 (0x81a+6321-0x20c3)
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
volatile uint32_T z0156d3cf53[(0xea4+798-0x11be)];
}z020494c81d;
#define z28c5dfd366            (0x212+3914-0x115c) 
#define ze9906393f1         (0x3e2+8729-0x25f8) 
#define z34c5a897f9                (0x146+3391-0xe81) 
#define z5dd45f00a5                (0x921+691-0xbce) 
#define z904e2847ca               (0x1872+2880-0x23aa) 
#define zf54309da44           (0xdfc+1955-0x1596) 
#define z8e173b4aa9            (0xbeb+6920-0x26e9) 
#define z7459717d7c            (0x1b56+1996-0x2317) 
#define zaf09f9129e         (0x1a02+2804-0x24ea) 
#define zb7c295e611          (0x184+4548-0x133b) 
#define z2177cc8d71 (0xd41+680-0xfdb) 
#define zdc80a1dcc5       (0x13a7+1955-0x1b3b) 
#define z2c46089855                (0x1089+2439-0x1a00) 
#define z9c45b39fac        (0x20f4+85-0x2137) 
#define zc0c6d7bce0     (0x1503+3604-0x2304) 
#define z452e3417e1             (0x184+2504-0xb38) 
#define z1378a8e713           (0x1d24+1068-0x213b) 
#define zed9cb402fc     (0xba2+2796-0x1678) 
#define z28d133f1e6      (0x1a12+1306-0x1f15) 
#define za74c2ed17b  (0x5a0+4324-0x166c) 
#define zbf7ff181d5               (0x465+2081-0xc6d) 
#define z08b102ac19     (0xad2+4436-0x1c0c) 
#define z7c2b0fb1d1     (0x1e87+1900-0x25d8) 
#define zb0261a24c5                     (0x61d+632-0x879) 
#define z8a1c8a1e84                (0x14aa+295-0x15b4) 
#define zb0499d9319   (0x473+3312-0x1145) 
#define INITIALIZE                  (0x18c9+2276-0x218e) 
#define z871ba5e63d            (0x228+4338-0x131a) 
#define z059e80d468            (0xd23+1375-0x1281)
#define zf3e0b2fa74            (0x1243+3058-0x1e33)
#define zeeec8b2ebb            (0x2c1+5667-0x18e1)
#define z2de56a8878  (0x2d1+2761-0xd96) 
#define za6afb27593       (0x77f+6727-0x21c1) 
#define z90687dcb41           (0x15da+2450-0x1f66) 
#define z3d132243ee          (0x1207+4326-0x22e6) 
#define z148fc42565              (0x10f4+3955-0x205f) 
#define zc707c018e2                 (0x7c3+2450-0x114c) 
#define z6b55dca319                  (0x3b4+600-0x602) 
#define zabe89d9b05         (0xc9f+5986-0x23f6) 
#define zc738ebdc54             (0x1e72+1066-0x2290) 
#define z53f96f9a93         (0x815+3362-0x152a) 
#define z2011ff577b              (0xdf0+5612-0x23cd) 
#define z48012f2ce7          (0x1e5+2761-0xc9e) 
#define z9fc17111c4              (0x74a+7172-0x233d) 
#define z8b72ab7941                 (0x1018+933-0x13ab) 
#define zc9661f8327         (0x142a+4801-0x26d8) 
#define z5f5020ac0b           (0x1887+2552-0x226b) 
#define z200bf8f7d0                   (0x143b+4212-0x24af) 
#define zc1a63d2a27               (0x11d5+3944-0x2135) 
#define zd4f65135a2                  (0x12d6+2287-0x1bb5) 
#define zffec758124              (0x12bd+3922-0x21f7) 
#define z7c9bc122b1  (0x15e9+3689-0x2452)
#define z7231b70c4f (0x65c+4170-0x16a5)

#define za40af8be03           16777215 
#define z86eea319be                          (0x5cd+1094-0x9fb) 

#define z95b35fa456     262143 
#define zaff3da4574           (0x1685+3178-0x22dc) 

#define z79fb3e5887         (0x1c9f+1507-0x2282) 
#define z3f59e11cd5                 (0x9d9+1517-0xfb6) 
#define z89772640d7           (0x142+5944-0x1879) 
#define zd69c8154ae                   (0x1c94+2131-0x24d6) 
#define z880c27a5db             (0x14b4+2028-0x1c9e) 
#define z93f0144cec                     (0x68c+6166-0x1e90) 
#define z29a6f340ee  (0x215f+169-0x2205) 
#define z5cffa5ee7c          (0x4b1+5391-0x19ad) 
#define z8507451090          (0x1891+700-0x1b49) 
#define z8706fd3aec                  (0xe40+4259-0x1ecf) 
#define z03a425d686        (0xe78+5012-0x2207) 
#define z9fc4ddc311                (0x6aa+988-0xa71) 
#define zaf55e7c759                  (0xc62+3627-0x1a87) 
#define z4e7d98be49                          (0x4b6+8033-0x2401) 
#define zf636f129e2                  (0x13a9+1819-0x1abd) 
#define zc2b1ac4e1c                          (0x1282+3914-0x21b5) 
#define zc5e19bcda6          (0xe13+4075-0x1df6) 
#define z25f9cdfe54                  (0x498+7231-0x20bf) 
#define z77518fe65b           (0x10da+2427-0x1a4c) 
#define za02048e51d                   (0x8b2+2545-0x128a) 
#define z4803b022e6            (0x596+6798-0x201a) 
#define z94812845d3                     (0xf24+4219-0x1f85) 
#define zf1c6a6f07e  (0xbef+686-0xe92) 
#define z59d93d7b20           (0x4fa+3063-0x10d6) 
#define za97c522794    (0x18d3+3272-0x258f) 
#define zec1b6962c1             (0x12e1+1158-0x174b) 
#define zc18d6729c5           (0xbdf+1916-0x134e) 
#define zf9d5e888b0                    (0x7fd+7651-0x25c3) 
#define z3be9d5f81a (0xc10+6739-0x2655) 
#define z37a0881b22          (0x12f3+750-0x15c3) 

#define z02eb2797c6    262143 
#define z5eff383092            (0x468+6219-0x1ca0) 

#define z18826d8f2e                   (0xae6+824-0xe0e) 
#define z21e78a36fd                    (0x1f3c+1096-0x2373) 

#define zd77bd3455c                    (0x15c6+4011-0x2561) 

#define z0205a40243 (0x1678+1909-0x1dd9)          
#define z4950fe3cb1 (((0x82f+7878-0x26f4)<<(0x6c2+3342-0x13b8))-(0xaf7+6944-0x2616)) 
#define z6e71fd742f (0xd33+517-0xf10)          
#define zc19bacea26 (((0xa67+4672-0x1ca6)<<(0x741+4718-0x1997))-(0x1dd0+264-0x1ed7)) 
#define zec8535e02c (0x10f6+4268-0x2012)         
#define z571e534c6e (((0x113c+710-0x1401)<<(0x455+4735-0x16bc))-(0x11e6+898-0x1567)) 
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
#define z551c6433ad        (0x1348+1967-0x1af7) 
#define z9ff50a1d47      (0x707+2811-0x1200) 
#define z60fa808c68      (0x3b5+581-0x5f4) 
#define za495e5447f  (0x112+3679-0xf6a) 
#define ze284f6dda4   (0x91c+1775-0x1003) 
#define zbd9cc3ea3e   (0x4b4+8619-0x2656) 
#define z72a2273697     (0x248+8883-0x24f1) 
#define zb538b13023  (0x142b+566-0x1656) 
#define z082f6638ca     (0x757+748-0xa37) 
#define ze57bee66e7  (0x1593+4091-0x2581) 
#define ze8cdd8692c      (0x212f+86-0x2177) 
#define z48a21f4939  (0xbf4+2160-0x1455) 
#define z6bd25a24d0  (0x8bd+5331-0x1d80) 
#define z3471c69077      (0xdb7+4127-0x1dc5) 
#define zf9faf82f5c  (0x13c4+2387-0x1d05) 
#define zf04451bb1a (0xf16+5309-0x23c0) 
#define z6e73a222da   (0x548+4304-0x1604) 
#define z25384e33ac    (0x27+4624-0x1222) 

#define z08d0b4e518  (0x25da+23-0x25f1) 
#define z3e27e0685c  (0x430+2033-0xc20) 
#define zc7139e459d  (0xb16+1841-0x1245) 
#define zb7f318c2a8 (0x156+6681-0x1b6c) 
#define zb7eaca017a   (0x19f+8903-0x2462) 
typedef volatile struct z4324a84488{volatile uint32_T zb76599274b;volatile uint32_T cntrl;}za6edc6d81a;
#define zfb2170cd8e (0x621+1636-0xc7e)
#define z445a635dd2      (0x1924+134-0x19a2) 
#define z3c87fa7ea1 (0xc59+750-0xf35) 
#define z82868178d9 (0x364+4492-0x14db) 
#define zbbbb241a6c (0x792+6776-0x21f4)


#define zd03e44657a  (0x86f+1659-0xee9)
#define z4ef2da205f (0x304+3918-0x1250)
#define z4292246d73 (0x14d0+1367-0x1a26)
#define z1bf87cb58b (0xa76+1598-0x10b3)
#define TARGET (0xd1a+1684-0x13ae)
#define z141532d9e2 (0x19c5+375-0x1b3b)
#define z1ca0467348 (0x430+5924-0x1b53)





#define z702a26a5e9                ssGetSFcnParam(S, (0x11b5+3313-0x1ea6)) 
#define z38de3397f8    ssGetSFcnParam(S, (0x3cf+5437-0x190b)) 
#define zeda2a9d389   ssGetSFcnParam(S, (0x22a+3114-0xe52)) 
#define z0f4f8c2101        ssGetSFcnParam(S, (0x1e23+1933-0x25ad)) 
#define z25204c5561         ssGetSFcnParam(S, (0x91a+5669-0x1f3b)) 
#define z8b5cd85f12  ssGetSFcnParam(S, (0x2c1+7263-0x1f1b)) 
#define z05c57013c0           ssGetSFcnParam(S, (0x11e7+3257-0x1e9a)) 
#define z7a95c6e40a           ssGetSFcnParam(S, (0x20f1+394-0x2274)) 
#define z0d9acd09bb         ssGetSFcnParam(S, (0x9ed+2305-0x12e6)) 
#define z28f37fc626      ssGetSFcnParam(S, (0x1ac+2193-0xa34)) 
#define za785236a26       ssGetSFcnParam(S,(0xeab+1518-0x148f)) 
#define z91f11b48c2    ssGetSFcnParam(S,(0x349+1417-0x8c7)) 
#define zc7d0304ae1       ssGetSFcnParam(S,(0x8e5+1912-0x1051)) 
#define zdf24515981                          ((0x7ab+2170-0x1018))
#define z8caad2a8e6              ((0x1b17+1079-0x1f4e))           
#define z5bfe7a2613            (z8caad2a8e6 + zf16899d845)   
#define zc5ce4cb81a              (z5bfe7a2613 + zf16899d845)
#define zc2f3e0cbc0        ((0x333+5679-0x1962))
#define zba952b5889      ((0x11f2+3271-0x1eb8)) 
#define z2e6483d505              (zba952b5889 + zf16899d845)
#define zc4ce4213f7               ((0x867+5071-0x1c36))
#define zc1cfebef6f             ((0x358+1311-0x876))
#define z7a0bc5653f        ((0x17b+7636-0x1f4d))
#define z2b17e2ee3b              ((0x744+5333-0x1c05))
static char_T zea4cd01646[(0x63b+6193-0x1d6c)];static void zc2f11ccb7a(real_T t);static void zc2f11ccb7a(real_T t){
#ifndef MATLAB_MEX_FILE
xpcTime z9764181524,zce60958e79,zde9131ca7b;xpcGetElapsedTime(&z9764181524);do{xpcGetElapsedTime(&zce60958e79);xpcSubtractTime(&zde9131ca7b,&zce60958e79,&z9764181524);}while((((real_T)zde9131ca7b.U64.NanoSecondsLo*1e-9)+((real_T)zde9131ca7b.U64.NanoSecondsHi*4.294967296))<t);
#endif
}
#ifdef z3bfc590c91
static void z288de859c0(z020494c81d*z183fd27444,uint32_T bit,uint32_T value);static void z288de859c0(z020494c81d*z183fd27444,uint32_T bit,uint32_T value){
#ifndef MATLAB_MEX_FILE
uint32_T z5450d078d5;if(!z183fd27444){printf("\x73\x65\x74\x44\x4f\x3a\x20\x70\x49\x4f\x31\x30\x34\x20\x69\x73\x20\x4e\x55\x4c\x4c" "\n");return;}if((bit>(0x7f0+4649-0x1a12))||(value>(0x9cd+2553-0x13c5))){printf("\x73\x65\x74\x44\x4f\x3a\x20\x62\x61\x64\x20\x70\x61\x72\x61\x6d" "\n");return;}z5450d078d5=z183fd27444->z53343b042a;if(value)z5450d078d5|=((0x8e6+1755-0xfc0)<<bit);else z5450d078d5&=~((0x35b+3997-0x12f7)<<bit);z5450d078d5|=(z7231b70c4f<<zc1a63d2a27);z183fd27444->z53343b042a=z5450d078d5;
#endif
}static void z190ad20cb8(z020494c81d*z183fd27444,uint32_T bit);static void z190ad20cb8(z020494c81d*z183fd27444,uint32_T bit){
#ifndef MATLAB_MEX_FILE
uint32_T z5450d078d5;if(!z183fd27444){printf("\x74\x67\x6c\x44\x4f\x3a\x20\x70\x49\x4f\x31\x30\x34\x20\x69\x73\x20\x4e\x55\x4c\x4c" "\n");return;}if((bit>(0x8fb+7308-0x2580))){printf("\x74\x67\x6c\x44\x4f\x3a\x20\x62\x61\x64\x20\x70\x61\x72\x61\x6d" "\n");return;}z5450d078d5=z183fd27444->z53343b042a;if(z5450d078d5&((0x1b5b+1810-0x226c)<<bit))z5450d078d5&=~((0x1a97+874-0x1e00)<<bit);else z5450d078d5|=((0x562+4099-0x1564)<<bit);z5450d078d5|=(z7231b70c4f<<zc1a63d2a27);z183fd27444->z53343b042a=z5450d078d5;
#endif
}
#else
#define z190ad20cb8(z183fd27444, bit) {}
#define z288de859c0(z183fd27444, bit, value) {}
#endif
#ifndef MATLAB_MEX_FILE
static void z9e1980f3c2(xpcTime*z8b485c4ba6);static void z9e1980f3c2(xpcTime*z8b485c4ba6){xpcGetElapsedTime(z8b485c4ba6);}static void zb0e134f6ca(xpcTime*z8b485c4ba6);static void zb0e134f6ca(xpcTime*z8b485c4ba6){xpcTime zce60958e79,zde9131ca7b;xpcGetElapsedTime(&zce60958e79);xpcSubtractTime(&zde9131ca7b,&zce60958e79,z8b485c4ba6);printf("\x64\x74\x5f\x69\x6e\x20\x3d\x20\x25\x65" "\n",(((real_T)zde9131ca7b.U64.NanoSecondsLo*1e-9)+((real_T)zde9131ca7b.U64.NanoSecondsHi*4.294967296)));}static int z2c9c2fb1a8(SimStruct*S,z020494c81d*z183fd27444);static int z2c9c2fb1a8(SimStruct*S,z020494c81d*z183fd27444){uint32_T b,c;if(!z183fd27444){printf("\x63\x6c\x65\x61\x72\x5f\x69\x6e\x70\x75\x74\x5f\x62\x75\x66\x66\x65\x72\x28\x29\x3a\x20\x70\x49\x4f\x31\x30\x34\x20\x69\x73\x20\x4e\x55\x4c\x4c" "\n");return-(0x1e1+2568-0xbe8);}
#ifdef z1919c093bf
printf("\x49\x4f\x31\x30\x34\x3a\x20\x43\x6c\x65\x61\x72\x69\x6e\x67\x20\x69\x6e\x70\x75\x74\x20\x62\x75\x66\x66\x65\x72" "\n");
#endif

z183fd27444->z14bc320aa4|=((0xd88+3063-0x197e)<<zb7c295e611);b=z183fd27444->z14bc320aa4;c=(0xac5+5665-0x20e6);while(b&((0x5d0+6202-0x1e09)<<zb7c295e611)){zc2f11ccb7a(0.1);
c++;b=z183fd27444->z14bc320aa4;if(c>=(0x496+3623-0x12a9))
{sprintf(zea4cd01646,"\x25\x73\x20\x54\x69\x6d\x65\x6f\x75\x74\x20\x77\x61\x69\x74\x69\x6e\x67\x20\x66\x6f\x72\x20\x63\x6c\x65\x61\x72\x69\x6e\x67\x20\x69\x6e\x70\x75\x74\x20\x62\x75\x66\x66\x65\x72\x2e" "\n",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return-(0x181f+1073-0x1c4f);}}

return(0x1b7c+194-0x1c3e);}
#endif
static void mdlInitializeSizes(SimStruct*S){uint32_T i,z6aa707ac85,z68c505c5e0;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xb9a+4224-0x1c1a));ssSetNumDiscStates(S,(0x6d2+1062-0xaf8));ssSetNumInputPorts(S,(0x579+5988-0x1cdd));z68c505c5e0=(uint32_T)mxGetN(z25204c5561);if(z68c505c5e0==(0x14ab+2716-0x1f46)&&(uint32_T)mxGetPr(z25204c5561)[(0x801+1494-0xdd7)]==(0xb12+4846-0x1e00))
z68c505c5e0=(0x5f9+8195-0x25fc);ssSetNumOutputPorts(S,z68c505c5e0);z6aa707ac85=(uint32_T)mxGetPr(za785236a26)[(0xc2f+1991-0x13f6)];for(i=(0x272+4514-0x1414);i<z68c505c5e0;i++){ssSetOutputPortWidth(S,i,z6aa707ac85);}ssSetNumSampleTimes(S,(0x248+1437-0x7e4));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1481+183-0x1538));ssSetNumNonsampledZCs(S,(0xae0+6697-0x2509));for(i=(0x2f8+4160-0x1338);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x14b5+1841-0x1be6));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){real_T Ts=mxGetPr(z38de3397f8)[(0x11b2+1665-0x1833)];if(Ts==-1.0){ssSetSampleTime(S,(0xa2b+4148-0x1a5f),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1361+760-0x1659),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x8ac+2325-0x11c1),Ts);ssSetOffsetTime(S,(0xa43+4015-0x19f2),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;z83d93efdde*z612247fc60;z020494c81d*z183fd27444;uint32_T z366b2f03bf,z441f9e6d1b,i,range,z9f2f6f91bc,z68c505c5e0,ze1dce08a7a,z3ffaae14b1,z74b7b2fba8,zbe86ff2fa9;
#ifdef zb482f925e2
printf("\x41\x44\x2e\x6d\x64\x6c\x53\x74\x61\x72\x74\x20\x28\x25\x73\x69\x6e\x69\x74\x29" "\n",(xpceIsModelInit())?"":"\x6e\x6f\x6e\x2d");
#endif
if(mxGetN(z702a26a5e9)==(0x802+2463-0x11a0)){z366b2f03bf=(0x386+7419-0x2081);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x1509+4450-0x266b)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x1768+3562-0x2552)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x282+6778-0x1cfb)];}

if(xpcGetPCIDeviceInfo(z694756a014,zea87e0ba83,z29146a1837,zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}
zeccbadd9b3.VirtAddress[(0x81b+4568-0x19f3)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x52c+480-0x70c)],4096,XPC_RT_PG_USERREADWRITE);zeccbadd9b3.VirtAddress[(0x246+5458-0x1796)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x7bf+4939-0x1b08)],(0x1fef+3536-0x1dbf),XPC_RT_PG_USERREADWRITE);
z183fd27444=(z020494c81d*)(zeccbadd9b3.VirtAddress[(0x859+5834-0x1f21)]);
z612247fc60=(z83d93efdde*)(zeccbadd9b3.VirtAddress[(0x1023+4312-0x20fb)]+(0x1469+2494-0x1da7));
ssSetPWorkValue(S,zc4ce4213f7,(void*)z612247fc60);ssSetPWorkValue(S,zc1cfebef6f,(void*)z183fd27444);z68c505c5e0=(uint32_T)mxGetN(z25204c5561);if(z68c505c5e0==(0xc2+5381-0x15c6)&&(uint32_T)mxGetPr(z25204c5561)[(0x1179+3611-0x1f94)]==(0x1061+1947-0x17fc))
z68c505c5e0=(0x16e6+2812-0x21e2);ssSetIWorkValue(S,zc2f3e0cbc0,z68c505c5e0);z3ffaae14b1=(z68c505c5e0&&((uint32_T)*mxGetPr(z28f37fc626)==z1ca0467348))?(0xf27+1294-0x1434):(0xa97+2386-0x13e9);z74b7b2fba8=(uint32_T)*mxGetPr(za785236a26);zbe86ff2fa9=(z3ffaae14b1||(z74b7b2fba8>(0x45d+107-0x4c7)))?(0x696+2935-0x120c):(0x2db+5388-0x17e7);
for(i=(0xd03+3904-0x1c43);i<z68c505c5e0;i++){z9f2f6f91bc=(uint32_T)mxGetPr(z25204c5561)[i];switch(z9f2f6f91bc){case(0xd34+3849-0x1c3c):case(0x20+6247-0x1885):case(0xbc4+2577-0x15d0):case(0x1639+4137-0x265c):range=(uint32_T)*mxGetPr(z05c57013c0);break;case(0x14d7+1016-0x18cc):case(0x695+767-0x990):case(0x23b2+171-0x2456):case(0x431+507-0x624):range=(uint32_T)*mxGetPr(z7a95c6e40a);break;default:sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x42\x61\x64\x20\x41\x44\x20\x63\x68\x61\x6e\x6e\x65\x6c\x73\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x3a\x20\x25\x69" "\n",zf1b619edf2,z366b2f03bf,z441f9e6d1b,z9f2f6f91bc);ssSetErrorStatus(S,zea4cd01646);return;}z9f2f6f91bc--;
switch(range){case(0x1291+4230-0x2316):ssSetRWorkValue(S,z8caad2a8e6+z9f2f6f91bc,3276.8);ssSetRWorkValue(S,z5bfe7a2613+z9f2f6f91bc,10.0);break;case(0x23+1756-0x6fd):ssSetRWorkValue(S,z8caad2a8e6+z9f2f6f91bc,6553.6);ssSetRWorkValue(S,z5bfe7a2613+z9f2f6f91bc,5.0);break;case(0x1ab+5583-0x1777):ssSetRWorkValue(S,z8caad2a8e6+z9f2f6f91bc,13107.2);ssSetRWorkValue(S,z5bfe7a2613+z9f2f6f91bc,2.5);break;default:sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x42\x61\x64\x20\x72\x61\x6e\x67\x65\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x20\x25\x69\x20\x66\x6f\x72\x20\x63\x68\x61\x6e\x6e\x65\x6c\x20" "\n",zf1b619edf2,z366b2f03bf,z441f9e6d1b,range,z9f2f6f91bc);ssSetErrorStatus(S,zea4cd01646);return;}}
for(i=(0x10a+6292-0x199e);i<z68c505c5e0;i++){z9f2f6f91bc=(uint32_T)mxGetPr(z8b5cd85f12)[i];
for(ze1dce08a7a=(0x868+4132-0x188c);ze1dce08a7a<zf16899d845;ze1dce08a7a++){if(mxGetPr(z25204c5561)[ze1dce08a7a]==z9f2f6f91bc){ssSetIWorkValue(S,zba952b5889+z9f2f6f91bc-(0x6c8+7812-0x254b),ze1dce08a7a);
break;}}}
if(!xpceIsModelInit()){if(zbe86ff2fa9){
ssSetPWorkValue(S,z7a0bc5653f,(void*)z612247fc60->ze467ac829e);z2c9c2fb1a8(S,z183fd27444);}else{ssSetPWorkValue(S,z7a0bc5653f,(void*)(0x129d+2293-0x1b92));
}z288de859c0(z183fd27444,(0xdad+3191-0x1a23),(0xe4f+3461-0x1bd4));}else{z288de859c0(z183fd27444,(0x1fb6+514-0x21b7),(0x3ed+1187-0x88f));}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
z83d93efdde*z7897fc6582=ssGetPWorkValue(S,zc4ce4213f7);z020494c81d*z183fd27444=ssGetPWorkValue(S,zc1cfebef6f);uint32_T*z77cb1c2f42;real_T*zc0efaa16c3;real_T offset,z0754dd67cc;uint32_T z68c505c5e0,ze1dce08a7a,i,z6aa707ac85,z2f01869a88,z0302abc276,z9f2f6f91bc;uint16_T zec7e626afe;z288de859c0(z183fd27444,(0x1934+240-0x1a23),(0x843+6970-0x237c));
#ifdef z65139427e8
printf("\x41\x44\x2e\x6d\x64\x6c\x4f\x75\x74\x70\x75\x74\x73\x20\x62\x65\x67\x69\x6e" "\n");
#endif
z68c505c5e0=ssGetIWorkValue(S,zc2f3e0cbc0);z77cb1c2f42=ssGetPWorkValue(S,z7a0bc5653f);z6aa707ac85=(uint32_T)*mxGetPr(za785236a26);if(z77cb1c2f42)
{for(i=(0x1067+2469-0x1a0c);i<z68c505c5e0;i++){z9f2f6f91bc=(uint32_T)mxGetPr(z8b5cd85f12)[i]-(0xf28+5636-0x252b);
ze1dce08a7a=ssGetIWorkValue(S,zba952b5889+z9f2f6f91bc);
z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6+z9f2f6f91bc);offset=ssGetRWorkValue(S,z5bfe7a2613+z9f2f6f91bc);zc0efaa16c3=ssGetOutputPortSignal(S,ze1dce08a7a);
for(z2f01869a88=(0x17b4+594-0x1a06),z0302abc276=z9f2f6f91bc;z2f01869a88<z6aa707ac85;z2f01869a88++,z0302abc276+=z68c505c5e0){zec7e626afe=z77cb1c2f42[z0302abc276];
zc0efaa16c3[z2f01869a88]=(real_T)zec7e626afe/z0754dd67cc-offset;}}z7897fc6582->z1def6086f7=((0x1270+4668-0x24ab)<<z08d0b4e518);z7897fc6582->z1def6086f7=((0x84c+832-0xb8b)<<z08d0b4e518)|((0x18bf+275-0x19d1)<<z3e27e0685c);}else{
z183fd27444->z14bc320aa4=z183fd27444->z14bc320aa4|((0xa87+6533-0x240b)<<z904e2847ca);while((z183fd27444->z14bc320aa4&((0x3bd+165-0x461)<<z904e2847ca)));for(i=(0x1d79+2381-0x26c6);i<z68c505c5e0;i++){z9f2f6f91bc=(uint32_T)mxGetPr(z8b5cd85f12)[i]-(0x1448+1032-0x184f);
ze1dce08a7a=ssGetIWorkValue(S,zba952b5889+z9f2f6f91bc);
z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6+z9f2f6f91bc);offset=ssGetRWorkValue(S,z5bfe7a2613+z9f2f6f91bc);zc0efaa16c3=ssGetOutputPortSignal(S,ze1dce08a7a);zec7e626afe=z183fd27444->z16f820f545;*zc0efaa16c3=(real_T)zec7e626afe/z0754dd67cc-offset;
#ifdef z1919c093bf
printf("\x41\x44\x25\x69\x3a\x25\x30\x2e\x33\x66" "\n",z9f2f6f91bc,*zc0efaa16c3);
#endif
}}
#ifdef z65139427e8
printf("\x41\x44\x2e\x6d\x64\x6c\x4f\x75\x74\x70\x75\x74\x73\x20\x65\x6e\x64" "\n");
#endif
z288de859c0(z183fd27444,(0x24fa+86-0x254f),(0xcc2+2980-0x1866));
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
z020494c81d*z183fd27444=ssGetPWorkValue(S,zc1cfebef6f);
#ifdef zb482f925e2
printf("\x41\x44\x2e\x6d\x64\x6c\x54\x65\x72\x6d\x69\x6e\x61\x74\x65\x20\x28\x25\x73\x69\x6e\x69\x74\x29" "\n",(xpceIsModelInit())?"":"\x6e\x6f\x6e\x2d");
#endif
z288de859c0(z183fd27444,(0x7d5+6069-0x1f89),(0xbaf+951-0xf65));
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

