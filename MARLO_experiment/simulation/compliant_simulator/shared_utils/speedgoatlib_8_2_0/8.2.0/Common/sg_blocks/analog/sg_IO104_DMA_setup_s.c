/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x724+4270-0x17d0)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO104_DMA_setup_s






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
#define z694756a014 4277
#define zea87e0ba83 36950
#define z29146a1837 (0x18d9+5130-0x1c2e)
#define zab7e64468b 12658
#define z173eaebd82 (0x5c6+7693-0x23cf)
#define zf16899d845 (0x2094+1367-0x25e3)
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
volatile uint32_T z0156d3cf53[(0x4f7+3399-0x123a)];
}z020494c81d;
#define z28c5dfd366            (0x7f6+4707-0x1a59) 
#define ze9906393f1         (0x5e5+749-0x8cf) 
#define z34c5a897f9                (0x7c0+1622-0xe12) 
#define z5dd45f00a5                (0x4b4+253-0x5ab) 
#define z904e2847ca               (0xeba+1535-0x14b1) 
#define zf54309da44           (0x553+535-0x761) 
#define z8e173b4aa9            (0xc87+3435-0x19e8) 
#define z7459717d7c            (0x1510+3737-0x239e) 
#define zaf09f9129e         (0x337+4170-0x1375) 
#define zb7c295e611          (0x672+189-0x722) 
#define z2177cc8d71 (0xb22+1102-0xf62) 
#define zdc80a1dcc5       (0x105+6398-0x19f4) 
#define z2c46089855                (0x11+6900-0x1af5) 
#define z9c45b39fac        (0x1003+5086-0x23cf) 
#define zc0c6d7bce0     (0x1cc2+1789-0x23ac) 
#define z452e3417e1             (0x9b8+4822-0x1c7a) 
#define z1378a8e713           (0x90f+6488-0x2252) 
#define zed9cb402fc     (0xd6+1762-0x7a2) 
#define z28d133f1e6      (0xd2c+4613-0x1f1a) 
#define za74c2ed17b  (0x54+6954-0x1b66) 
#define zbf7ff181d5               (0xb01+4022-0x1a9e) 
#define z08b102ac19     (0x744+5240-0x1ba2) 
#define z7c2b0fb1d1     (0x32a+4602-0x1509) 
#define zb0261a24c5                     (0x178+6993-0x1cad) 
#define z8a1c8a1e84                (0x4cf+3322-0x11ac) 
#define zb0499d9319   (0x7ad+3235-0x1432) 
#define INITIALIZE                  (0x655+2800-0x1126) 
#define z871ba5e63d            (0x48f+7863-0x2346) 
#define z059e80d468            (0x3df+858-0x738)
#define zf3e0b2fa74            (0x1d90+74-0x1dd8)
#define zeeec8b2ebb            (0x329+6034-0x1ab8)
#define z2de56a8878  (0x2f9+2201-0xb8e) 
#define za6afb27593       (0x1000+192-0x10bb) 
#define z90687dcb41           (0x15e9+812-0x190f) 
#define z3d132243ee          (0x91a+6134-0x2109) 
#define z148fc42565              (0xac9+2705-0x1552) 
#define zc707c018e2                 (0xc10+432-0xdb7) 
#define z6b55dca319                  (0x1483+3622-0x229f) 
#define zabe89d9b05         (0x85d+4534-0x1a08) 
#define zc738ebdc54             (0x1ca7+2261-0x2570) 
#define z53f96f9a93         (0x1931+2051-0x2127) 
#define z2011ff577b              (0x2327+157-0x23b5) 
#define z48012f2ce7          (0xf68+4238-0x1fe6) 
#define z9fc17111c4              (0x621+873-0x979) 
#define z8b72ab7941                 (0x80c+1683-0xe8d) 
#define zc9661f8327         (0xdc3+2194-0x1642) 
#define z5f5020ac0b           (0x887+4761-0x1b0c) 
#define z200bf8f7d0                   (0xf02+2008-0x16da) 
#define zc1a63d2a27               (0x12d1+1462-0x187f) 
#define zd4f65135a2                  (0x661+7616-0x2411) 
#define zffec758124              (0x54f+6609-0x1f08) 
#define z7c9bc122b1  (0x430+1670-0xab6)
#define z7231b70c4f (0x60c+8278-0x2661)

#define za40af8be03           16777215 
#define z86eea319be                          (0x832+3495-0x15c1) 

#define z95b35fa456     262143 
#define zaff3da4574           (0xef+6094-0x18aa) 

#define z79fb3e5887         (0xdd0+1156-0x1254) 
#define z3f59e11cd5                 (0x886+2122-0x10c0) 
#define z89772640d7           (0x1330+1063-0x1756) 
#define zd69c8154ae                   (0xdcd+430-0xf6a) 
#define z880c27a5db             (0x1be4+61-0x1c1f) 
#define z93f0144cec                     (0x1564+1221-0x1a17) 
#define z29a6f340ee  (0x2c6+5351-0x17aa) 
#define z5cffa5ee7c          (0x4e1+6441-0x1df7) 
#define z8507451090          (0x290+6089-0x1a55) 
#define z8706fd3aec                  (0x13fa+1374-0x1944) 
#define z03a425d686        (0x785+3507-0x1533) 
#define z9fc4ddc311                (0x1504+1217-0x19b0) 
#define zaf55e7c759                  (0x132+7669-0x1f21) 
#define z4e7d98be49                          (0xd63+5624-0x2345) 
#define zf636f129e2                  (0x3f6+8571-0x256a) 
#define zc2b1ac4e1c                          (0x1465+2908-0x1faa) 
#define zc5e19bcda6          (0x37b+4892-0x168f) 
#define z25f9cdfe54                  (0xcc7+708-0xf73) 
#define z77518fe65b           (0x2241+878-0x25a6) 
#define za02048e51d                   (0x11fa+2038-0x19d7) 
#define z4803b022e6            (0x324+7497-0x2063) 
#define z94812845d3                     (0xfb2+1968-0x1748) 
#define zf1c6a6f07e  (0x1c48+1954-0x23df) 
#define z59d93d7b20           (0x1566+1703-0x1bf2) 
#define za97c522794    (0x1205+732-0x14d5) 
#define zec1b6962c1             (0x14fa+1283-0x19e1) 
#define zc18d6729c5           (0x4bd+8645-0x2675) 
#define zf9d5e888b0                    (0x99b+425-0xb27) 
#define z3be9d5f81a (0x80b+2198-0x1093) 
#define z37a0881b22          (0x8f7+5613-0x1ec6) 

#define z02eb2797c6    262143 
#define z5eff383092            (0x6a6+3466-0x141d) 

#define z18826d8f2e                   (0x2188+311-0x22af) 
#define z21e78a36fd                    (0x444+4565-0x1608) 

#define zd77bd3455c                    (0xc8+4419-0x11fb) 

#define z0205a40243 (0xbad+3996-0x1b35)          
#define z4950fe3cb1 (((0x7c+3480-0xe13)<<(0x1039+1058-0x1443))-(0x9ad+6624-0x238c)) 
#define z6e71fd742f (0x2065+872-0x23a5)          
#define zc19bacea26 (((0x60f+8186-0x2608)<<(0x1606+2061-0x1dfb))-(0x111d+324-0x1260)) 
#define zec8535e02c (0x211+6399-0x1980)         
#define z571e534c6e (((0x1354+3745-0x21f4)<<(0x9af+139-0xa22))-(0xf34+856-0x128b)) 




#define z6a19b0a974  (0x1261+2663-0x1cc8) 
#define ze4fe6ff741    (0x433+8469-0x2547) 
#define z4b7fa6bd94  (0x4fa+397-0x685) 
#define z1c8d8a656e    (0x5e1+945-0x98f)
#define z863cf2e79f  (0x16c+3633-0xf99)
#define z585157ce83    (0x18b1+2230-0x2162)
#define z0425abeaaa  (0x2f9+4093-0x12f0)
#define z69f063aa4f    (0xc64+12-0xc69)
#define za0cdb8627b  (0xbb9+1773-0x129e)
#define z42cbd10951    (0x1ccd+1088-0x2104)
#define z161ba5aa2f  (0xbe7+1415-0x1164)
#define zdad84c05dd    (0x5a8+1820-0xcb9)
#define zc9307c4385  (0x10e7+2562-0x1add)
#define z5d0c0747fd    (0x1209+4681-0x2445)
#define zf77ec1a9b2  (0xdda+2582-0x17e2)
#define za5e69ea1f2    (0x3dd+5862-0x1ab4)
#define z2dde21a7c6   (0x194c+3053-0x2529)
#define z23b316812b     (0x738+4814-0x19f5)
#define zc13f0cf778   (0x5d8+6667-0x1fd1)
#define z7616b7bc1a     (0x36c+7172-0x1f5d)
#define z0a245d354d   (0x5d0+2037-0xdb1)
#define zd7d441f2b1     (0x16fc+1117-0x1b44)
#define zca7177aa5a   (0xa0c+4517-0x1b9b)
#define za70eb0e135     (0x22b+5326-0x16e2)
#define zba115cd4ff   (0x1480+908-0x17f4)
#define z3a299fd0b5     (0x3f3+6452-0x1d0e)
#define z5d88bf466a   (0xd1a+2203-0x159b)
#define za100b4e85d     (0x1a56+729-0x1d14)
#define ze1c1d5a078   (0x1934+708-0x1bdc)
#define z84a363204a     (0x361+5393-0x1855)
#define z4193c7acb1   (0xd2c+5418-0x2238)
#define z91cb754fe9     (0x3f0+4352-0x14d1)
#define z4e1515da7d  (0x863+5725-0x1ea0)
#define za44bbf15c6    (0x36d+5709-0x1999)
#define zfdc1df0966  (0x67f+7435-0x2368)
#define zd7ad9ed258    (0x659+8322-0x26b8)
#define ze44c956ee8  (0x746+4123-0x173d)
#define zd846424103    (0x1685+1748-0x1d34)
#define zf23efb5596  (0x172d+2278-0x1fed)
#define zd8d66ab183    (0x1298+3985-0x2202)
#define z131e158aa6  (0xd27+6345-0x25c8)
#define zdc5e25e6d6    (0x1e87+1576-0x2486)
#define z307ac8d8ea  (0x1642+4000-0x25b8)
#define ze8c468f0db    (0xf4f+4524-0x20d0)
#define za922018a59  (0x781+3634-0x1587)
#define z6f52486d16    (0x14c2+2306-0x1d97)
#define zc5991ec4fa  (0x14d8+3207-0x2131)
#define z84278f2a61    (0xdf3+2826-0x18ce)
#define z7fcb923f93  (0x150f+3053-0x20bc)
#define za2c38cc5e5    (0x43f+2512-0xdce)
#define z737d803dbc  (0x1a14+425-0x1b7b)
#define z511700c9db    (0x3d6+5375-0x1892)
#define z76413b157f  (0x13bf+3168-0x1fdb)
#define z764722168b    (0x42c+2011-0xbc2)
#define z7b62e7b2c6  (0xc17+4452-0x1d35)
#define z10fe31d0e4    (0x5d2+575-0x7ca)
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
#define z551c6433ad        (0x170c+3531-0x24d7) 
#define z9ff50a1d47      (0x74c+316-0x886) 
#define z60fa808c68      (0x1836+2414-0x219e) 
#define za495e5447f  (0x39a+4207-0x1402) 
#define ze284f6dda4   (0x22b+9385-0x26cc) 
#define zbd9cc3ea3e   (0x419+5512-0x1998) 
#define z72a2273697     (0x1678+1169-0x1aff) 
#define zb538b13023  (0x629+5615-0x1c0d) 
#define z082f6638ca     (0xbb5+2989-0x1756) 
#define ze57bee66e7  (0x16f6+2391-0x2040) 
#define ze8cdd8692c      (0x1252+4875-0x254f) 
#define z48a21f4939  (0xae8+1026-0xedb) 
#define z6bd25a24d0  (0x369+6718-0x1d97) 
#define z3471c69077      (0xf81+5757-0x25ed) 
#define zf9faf82f5c  (0x7b3+4762-0x1a3b) 
#define zf04451bb1a (0x12d6+2423-0x1c3a) 
#define z6e73a222da   (0x215c+1438-0x26e6) 
#define z25384e33ac    (0xa8d+7200-0x2698) 

#define z9b226a1cab     (0x1126+2212-0x19ca)
#define z583be2f5c1     (0xd3f+2235-0x15f9)
#define z2472b0b295   (0x10cf+2947-0x1c50)
#define zecc0da7a42      (0x671+4639-0x188d)

#define z08d0b4e518  (0x31c+822-0x652) 
#define z3e27e0685c  (0x874+6126-0x2061) 
#define zc7139e459d  (0x4e6+8213-0x24f9) 
#define zb7f318c2a8 (0x1419+2161-0x1c87) 
#define zb7eaca017a   (0x1a82+1008-0x1e6e) 
typedef volatile struct z4324a84488{volatile uint32_T zb76599274b;volatile uint32_T cntrl;}za6edc6d81a;
#define zfb2170cd8e (0x147b+4122-0x248e)
#define z445a635dd2      (0xf14+1150-0x138a) 
#define z3c87fa7ea1 (0x9d5+4318-0x1aa1) 
#define z82868178d9 (0x1411+2249-0x1cc5) 
#define zbbbb241a6c (0x15d7+255-0x16c0)


#define zd03e44657a  (0x823+4945-0x1b73)
#define z4ef2da205f (0x8b1+4748-0x1b3b)
#define z4292246d73 (0x1039+4796-0x22f4)
#define z1bf87cb58b (0xa0+2314-0x9a9)
#define TARGET (0x2ff+8246-0x2335)
#define z141532d9e2 (0xd33+5073-0x2103)
#define z1ca0467348 (0xf66+6014-0x26e3)





#define z702a26a5e9                ssGetSFcnParam(S, (0x1573+2828-0x207f)) 

#define zb8a0473698    ssGetSFcnParam(S, (0x11c2+3844-0x20c5)) 
#define z0cd5a88349         ssGetSFcnParam(S, (0x246+5324-0x1710)) 
#define zd6d6a44c19                 ssGetSFcnParam(S, (0x246+2062-0xa51)) 

#define zdbac35e6a8          ssGetSFcnParam(S, (0x90+2733-0xb39)) 
#define z4785157cf4            ssGetSFcnParam(S, (0x5d6+6300-0x1e6d)) 
#define z57621982a4            ssGetSFcnParam(S, (0x1cb+7881-0x208e)) 
#define z186580de21          ssGetSFcnParam(S, (0x200+646-0x47f)) 
#define z12e55ce479        ssGetSFcnParam(S, (0x1ecf+1051-0x22e2)) 
#define zb35adceb5a         ssGetSFcnParam(S, (0x12f5+629-0x1561)) 
#define z0b57e9675d      ssGetSFcnParam(S,(0x1412+3089-0x2019)) 
#define z522c647b2a        ssGetSFcnParam(S,(0xad7+4997-0x1e51)) 

#define za073552a39          ssGetSFcnParam(S,(0x666+2466-0xffc)) 
#define z15e14cdb28  ssGetSFcnParam(S,(0xa10+2911-0x1562)) 
#define z22e8a8c9a0          ssGetSFcnParam(S,(0x143b+3810-0x230f)) 
#define za6b3fb79a3             ssGetSFcnParam(S,(0x53f+7855-0x23df)) 
#define z061b63a1f4             ssGetSFcnParam(S,(0x250c+494-0x26ea)) 
#define zd48d355167        ssGetSFcnParam(S,(0x16a8+453-0x185c)) 
#define z99106e76be         ssGetSFcnParam(S,(0x2161+1458-0x2701)) 
#define zc6de92780d      ssGetSFcnParam(S,(0xc93+1101-0x10cd)) 
#define zfb30127239        ssGetSFcnParam(S,(0xa45+4336-0x1b21)) 

#define zac66f82ae1         ssGetSFcnParam(S,(0x1459+3677-0x22a1)) 
#define z17f5615ed3         ssGetSFcnParam(S,(0x10d4+68-0x1102)) 

#define z5bc3ce0d50           ssGetSFcnParam(S,(0x6c7+2531-0x1093)) 
#define z2d8f240c11           ssGetSFcnParam(S,(0x818+5740-0x1e6c)) 
#define z1f9bebb47b             ssGetSFcnParam(S,(0x1236+966-0x15e3)) 

#define zb18e38a301           ssGetSFcnParam(S,(0xdf0+3445-0x1b4b)) 
#define zdf24515981                          ((0xe66+2450-0x17dd))
#define z2e6483d505              ((0x1138+5095-0x251f))
#define zbd291336e9           ((0x11ef+1422-0x177d))
#define z3b859f7689         ((0xcc1+3967-0x1c3f))
#define zc5ce4cb81a              ((0x942+5889-0x2041))
#define zc4ce4213f7               ((0x115a+1639-0x17c1))
#define zc1cfebef6f             ((0x148+5549-0x16f4))
#define z2b17e2ee3b              ((0x7f8+5071-0x1bc5))
#define zcb8375ba3e 0.1
#define zeb7fa7b5c6     (0x10c+3336-0xe0d)
static char_T zea4cd01646[(0x1aa5+3136-0x25e5)];static uint32_T z15cce05e60(real_T x);static void ze5344c3613(SimStruct*S,z020494c81d*z183fd27444);static void z288de859c0(z020494c81d*z183fd27444,uint32_T bit,uint32_T value);static void z288de859c0(z020494c81d*z183fd27444,uint32_T bit,uint32_T value){
#ifdef z3bfc590c91
#ifndef MATLAB_MEX_FILE
uint32_T z5450d078d5;if(!z183fd27444){printf("\x73\x65\x74\x44\x4f\x3a\x20\x70\x49\x4f\x31\x30\x34\x20\x69\x73\x20\x4e\x55\x4c\x4c" "\n");return;}if((bit>(0x186f+1238-0x1d3e))||(value>(0xba0+6926-0x26ad))){printf("\x73\x65\x74\x44\x4f\x3a\x20\x62\x61\x64\x20\x70\x61\x72\x61\x6d" "\n");return;}z5450d078d5=z183fd27444->z53343b042a;if(value)z5450d078d5|=((0xdb7+632-0x102e)<<bit);else z5450d078d5&=~((0x1801+543-0x1a1f)<<bit);z5450d078d5|=(z7231b70c4f<<zc1a63d2a27);z183fd27444->z53343b042a=z5450d078d5;
#endif
#endif
}static void z190ad20cb8(z020494c81d*z183fd27444,uint32_T bit);static void z190ad20cb8(z020494c81d*z183fd27444,uint32_T bit){
#ifdef z3bfc590c91
#ifndef MATLAB_MEX_FILE
uint32_T z5450d078d5;if(!z183fd27444){printf("\x74\x67\x6c\x44\x4f\x3a\x20\x70\x49\x4f\x31\x30\x34\x20\x69\x73\x20\x4e\x55\x4c\x4c" "\n");return;}if((bit>(0xe6+4244-0x1173))){printf("\x74\x67\x6c\x44\x4f\x3a\x20\x62\x61\x64\x20\x70\x61\x72\x61\x6d" "\n");return;}z5450d078d5=z183fd27444->z53343b042a;if(z5450d078d5&((0xf0f+1977-0x16c7)<<bit))z5450d078d5&=~((0x8b9+6951-0x23df)<<bit);else z5450d078d5|=((0x7b6+4993-0x1b36)<<bit);z5450d078d5|=(z7231b70c4f<<zc1a63d2a27);z183fd27444->z53343b042a=z5450d078d5;
#endif
#endif
}static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c" 
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xfb5+1363-0x1508));ssSetNumDiscStates(S,(0xb10+693-0xdc5));ssSetNumOutputPorts(S,(0x756+2501-0x111b));ssSetNumInputPorts(S,(0x1560+2142-0x1dbe));ssSetNumSampleTimes(S,(0x96c+5493-0x1ee0));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0xf72+4880-0x2282));ssSetNumNonsampledZCs(S,(0xd88+4776-0x2030));for(i=(0x1502+347-0x165d);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x160+1070-0x58e));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x49b+3253-0x1150),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x452+5596-0x1a2e),FIXED_IN_MINOR_STEP_OFFSET);}static uint16_T z0abf3f31e3(int z366b2f03bf,int z441f9e6d1b);static void zc2f11ccb7a(real_T t);
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;uint32_T z366b2f03bf,z441f9e6d1b;z83d93efdde*z612247fc60;z020494c81d*z183fd27444;uint32_T*z920d002f57;uint32_T*zbf7f59fabb;uint32_T zcc7e8410a6=TARGET,z2b74be5904=z7c9bc122b1,z7503f59baa=z7c9bc122b1,size,z9f2f6f91bc;uint32_T z826c5bb813=(0x1718+1445-0x1cbd),zd8a0291585=(0x184b+2453-0x21e0),z477fe62ff4=(0x920+7501-0x266d),z3f409ba692=(0x886+2435-0x1209),z60e81f22f0=(0x740+820-0xa74),zf19a26010b=TARGET,z756a2380a7;uint32_T zc2889b1256=(0x21df+432-0x238d),z572e2feb72=(0x787+3882-0x16af),z68c505c5e0=(0x1d12+2196-0x25a6),z74b7b2fba8=(0xf55+2508-0x1921),z44e7366341=z141532d9e2,z3ffaae14b1=(0xc37+1982-0x13f5),zbf352f9f56=(0xee4+2434-0x1866),z6689d96757=TARGET,zbe86ff2fa9;uint32_T zaf49fd5709=(0x7a3+6195-0x1fd6),z963c71b80b=(0x1b5a+68-0x1b9e);real_T offset,z0754dd67cc,z17eef240dd;uint32_T z615725805d,i,b,c,z14bc320aa4,zf66194a2f2,z53343b042a,z0302abc276,z2f01869a88,za0112e85fa,z26dbd73a5e;
#ifdef zb482f925e2
printf("\x53\x65\x74\x75\x70\x2e\x6d\x64\x6c\x53\x74\x61\x72\x74\x20\x28\x25\x73\x69\x6e\x69\x74\x29" "\n",(xpceIsModelInit())?"":"\x6e\x6f\x6e\x2d");
#endif
if(mxGetN(z702a26a5e9)==(0x143b+1199-0x18e9)){z366b2f03bf=(0xa08+7248-0x2658);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x11b+7304-0x1da3)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x4bb+8333-0x2548)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x182f+3536-0x25fe)];}

if(xpcGetPCIDeviceInfo(z694756a014,zea87e0ba83,z29146a1837,zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}

zeccbadd9b3.VirtAddress[(0x10db+2224-0x198b)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x50c+4107-0x1517)],(0x1fca+1865-0x1713),XPC_RT_PG_USERREADWRITE);zeccbadd9b3.VirtAddress[(0x2f8+6719-0x1d35)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x2a0+3881-0x11c7)],4096,XPC_RT_PG_USERREADWRITE);
z183fd27444=(z020494c81d*)(zeccbadd9b3.VirtAddress[(0xce5+2164-0x1557)]);
z612247fc60=(z83d93efdde*)(zeccbadd9b3.VirtAddress[(0x58a+8018-0x24dc)]+(0x596+6850-0x1fd8));
ssSetPWorkValue(S,zc4ce4213f7,(void*)z612247fc60);ssSetPWorkValue(S,zc1cfebef6f,(void*)z183fd27444);z68c505c5e0=(uint32_T)mxGetN(zdbac35e6a8);if(z68c505c5e0==(0x47f+6175-0x1c9d)&&(uint32_T)mxGetPr(zdbac35e6a8)[(0x354+5593-0x192d)]==(0xe98+5393-0x23a9))
z68c505c5e0=(0x595+2365-0xed2);zd8a0291585=(uint32_T)mxGetN(za073552a39);if(zd8a0291585==(0x6dc+4368-0x17eb)&&(uint32_T)mxGetPr(za073552a39)[(0x1adb+1478-0x20a1)]==(0x701+3833-0x15fa))
zd8a0291585=(0x945+987-0xd20);z963c71b80b=(uint32_T)*mxGetPr(zb18e38a301);if(z963c71b80b==(0xa6c+1275-0xf66)&&(uint32_T)mxGetPr(zb18e38a301)[(0xd6b+141-0xdf8)]==(0x3e0+3730-0x1272))
z963c71b80b=(0x85a+7316-0x24ee);zaf49fd5709=(uint32_T)*mxGetPr(z5bc3ce0d50);if(zaf49fd5709==(0x85+6228-0x18d8)&&(uint32_T)mxGetPr(z5bc3ce0d50)[(0x914+3822-0x1802)]==(0x19ff+854-0x1d55))
zaf49fd5709=(0x9f4+5017-0x1d8d);
if(z68c505c5e0){z44e7366341=((uint32_T)*mxGetPr(z186580de21)==z141532d9e2)?(0x54c+6310-0x1df2):(0x1ae1+1170-0x1f72);z6689d96757=((uint32_T)*mxGetPr(z0b57e9675d)==z1bf87cb58b)?(0x68b+3089-0x129b):(0x849+1992-0x1011);z3ffaae14b1=(z68c505c5e0&&((uint32_T)*mxGetPr(z12e55ce479)==z1ca0467348))?(0x74b+7329-0x23eb):(0xe7c+1911-0x15f3);z74b7b2fba8=(uint32_T)*mxGetPr(zb35adceb5a);zbf352f9f56=(0x9a5+6435-0x22c7);zbe86ff2fa9=(z3ffaae14b1||(z74b7b2fba8>(0x42f+5205-0x1883)))?(0x878+2955-0x1402):(0x3cd+2933-0xf42);
switch((uint16_T)mxGetPr(z4785157cf4)[(0x922+3093-0x1537)]){case(0xf9a+3258-0x1c52):zc2889b1256=(0x6ec+1675-0xd76);break;
case(0x77f+1436-0xd18):zc2889b1256=(0x195d+638-0x1bdb);break;
case(0x144b+3107-0x206d):default:zc2889b1256=(0x131+3026-0xd01);break;
}
switch((uint16_T)mxGetPr(z57621982a4)[(0x1c5c+2475-0x2607)]){case(0x14c2+4549-0x2685):z572e2feb72=(0xa72+5167-0x1ea0);break;
case(0x11c+8475-0x2234):z572e2feb72=(0x1aa7+700-0x1d63);break;
case(0x20f5+1219-0x25b7):default:z572e2feb72=(0x74+3306-0xd5c);break;
}}if(zd8a0291585){zf19a26010b=((uint8_T)*mxGetPr(zc6de92780d)==z1bf87cb58b)?(0xd36+3712-0x1bb5):(0x1d1+5493-0x1746);z3f409ba692=(zd8a0291585&&((uint32_T)*mxGetPr(zd48d355167)==z1ca0467348))?(0xf9+7040-0x1c78):(0x12a4+1734-0x196a);z477fe62ff4=(uint32_T)*mxGetPr(z99106e76be);z756a2380a7=(z3f409ba692||(z477fe62ff4>(0xeb4+809-0x11dc)))?(0x811+7473-0x2541):(0x1008+4292-0x20cc);z60e81f22f0=z756a2380a7;
switch((uint16_T)mxGetPr(z061b63a1f4)[(0x2131+48-0x2161)]){case(0xd97+6445-0x26c2):z826c5bb813=(0x1d23+1840-0x2452);z0754dd67cc=6553.6;offset=5.0;break;
case(0x1701+1652-0x1d72):z826c5bb813=(0x898+1210-0xd52);z0754dd67cc=13107.2;offset=2.5;break;
case(0xbc0+1408-0x113f):default:z826c5bb813=(0x1364+2944-0x1ee2);z0754dd67cc=3276.8;offset=10.0;break;
}ssSetRWorkValue(S,zbd291336e9,z0754dd67cc);ssSetRWorkValue(S,z3b859f7689,offset);}zcc7e8410a6=((uint32_T)*mxGetPr(zb8a0473698)==z1bf87cb58b)?(0xbc0+601-0xe18):(0x121a+5331-0x26ed);z14bc320aa4=(z44e7366341<<z28c5dfd366)|(zc2889b1256<<z34c5a897f9)|(z572e2feb72<<z5dd45f00a5)|(z3ffaae14b1<<zf54309da44)|(zbf352f9f56<<zaf09f9129e)|(z826c5bb813<<z2c46089855)|((0x13bc+916-0x174f)<<z9c45b39fac)|(z60e81f22f0<<zc0c6d7bce0)|(zcc7e8410a6<<z1378a8e713)|(z6689d96757<<za74c2ed17b)|((0x1870+2883-0x23b2)<<zbf7ff181d5)
;
if(zd8a0291585){zf66194a2f2=(0x1afb+2419-0x246e);if(zd8a0291585>z173eaebd82){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x54\x6f\x6f\x20\x6d\x61\x6e\x79\x20\x6f\x75\x74\x70\x75\x74\x20\x63\x68\x61\x6e\x6e\x65\x6c\x73\x20\x64\x65\x66\x69\x6e\x65\x64\x2e" "\n",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}for(i=(0xe1a+3168-0x1a7a),z615725805d=(0x25f+6372-0x1b43);i<zd8a0291585;i++){z9f2f6f91bc=(uint32_T)mxGetPr(za073552a39)[i]-(0x4ec+5519-0x1a7a);if(z9f2f6f91bc>=z173eaebd82){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x49\x6c\x6c\x65\x67\x61\x6c\x20\x61\x6e\x61\x6c\x6f\x67\x20\x6f\x75\x74\x70\x75\x74\x20\x63\x68\x61\x6e\x6e\x65\x6c\x20\x69\x6e\x64\x65\x78\x3a\x20\x25\x69" "\n",zf1b619edf2,z9f2f6f91bc);ssSetErrorStatus(S,zea4cd01646);return;}z615725805d|=((0x1192+960-0x1551)<<(z9f2f6f91bc+z871ba5e63d));}
#ifdef z1919c093bf
printf("\x25\x69\x20\x41\x63\x74\x69\x76\x65\x20\x4f\x75\x74\x70\x75\x74\x20\x43\x68\x61\x6e\x6e\x65\x6c\x73\x3a\x20\x25\x73\x25\x73\x25\x73\x25\x73" "\n",zd8a0291585,(z615725805d&(0x1124+311-0x125a))?"\x30\x20":"",(z615725805d&(0x22cf+949-0x2682))?"\x31\x20":"",(z615725805d&(0xe12+1136-0x127e))?"\x32\x20":"",(z615725805d&(0xcf0+3881-0x1c11))?"\x33\x20":"");
#endif
zf66194a2f2=z615725805d|(zf19a26010b<<z2de56a8878)|((0x184a+841-0x1b92)<<zabe89d9b05)|(z3f409ba692<<zc9661f8327)|((0x8a6+2367-0x11e4)<<za6afb27593);}
if(xpceIsModelInit()){
#ifdef z1919c093bf
printf("\x49\x4e\x49\x54\x49\x41\x4c\x49\x5a\x45" "\n");
#endif
z183fd27444->z14bc320aa4=((0x1e16+1391-0x2384)<<INITIALIZE);while(z183fd27444->z14bc320aa4&((0x1097+5227-0x2501)<<INITIALIZE));i=z183fd27444->zd5b1eea47e&4095;
#ifdef z1919c093bf
printf("\x70\x49\x4f\x31\x30\x34\x20\x46\x69\x72\x6d\x77\x61\x72\x65\x20\x52\x65\x76\x69\x73\x69\x6f\x6e\x3a\x20\x30\x78\x25\x30\x33\x78\x20\x28\x25\x69\x29" "\n",i,i);
#endif

if(((uint32_T)mxGetPr(zd6d6a44c19)[(0x133d+2807-0x1e34)]==z1ca0467348)){
z183fd27444->z14bc320aa4=z14bc320aa4;
#if (0x767+4694-0x19bc)
z183fd27444->z14bc320aa4=((0x108a+1570-0x16ab)<<zb0261a24c5);
#ifdef z1919c093bf
printf("\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x73\x74\x61\x72\x74\x65\x64\x2e\x2e" "\n",zf1b619edf2);
#endif
#else
z183fd27444->z14bc320aa4=z14bc320aa4|((0x112+9244-0x252d)<<ze9906393f1);
#ifdef z1919c093bf
printf("\x20\x20\x25\x73\x20\x69\x6e\x70\x75\x74\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x73\x74\x61\x72\x74\x65\x64\x2e\x2e" "\n",zf1b619edf2);
#endif
#endif
b=z183fd27444->z14bc320aa4;c=(0x1107+3891-0x203a);while((b&((0x6da+7217-0x230a)<<zb0261a24c5))&&((c*zcb8375ba3e)<zeb7fa7b5c6)){c++;zc2f11ccb7a(zcb8375ba3e);b=z183fd27444->z14bc320aa4;}if((c*zcb8375ba3e)>=zeb7fa7b5c6)
{sprintf(zea4cd01646,"\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x74\x69\x6d\x65\x64\x20\x6f\x75\x74\x20\x28\x37\x73\x29",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}if(b&((0x8e6+642-0xb67)<<z8a1c8a1e84))
{
#ifdef z1919c093bf
printf("\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x73\x75\x63\x63\x65\x65\x64\x65\x64\x2e\x20" "\n",zf1b619edf2);
#endif
}else{sprintf(zea4cd01646,"\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x20\x66\x61\x69\x6c\x65\x64\x20\x28\x30\x78\x25\x30\x38\x78\x29",zf1b619edf2,z183fd27444->z6c201be134);ssSetErrorStatus(S,zea4cd01646);return;}
#ifdef z1919c093bf
printf("\x54\x69\x6d\x65\x20\x75\x73\x65\x64\x20\x66\x6f\x72\x20\x61\x75\x74\x6f\x63\x61\x6c\x3a\x20\x25\x66\x73" "\n",c*zcb8375ba3e);
#endif
}z183fd27444->z14bc320aa4=z14bc320aa4;
z183fd27444->zf66194a2f2=zf66194a2f2;
}else
{z183fd27444->z14bc320aa4=z14bc320aa4;

z183fd27444->z3378080323=(zbe86ff2fa9)?z15cce05e60(*mxGetPr(z522c647b2a)*zb16b309883):z0205a40243;z183fd27444->zb6903ad9ad=z15cce05e60(*mxGetPr(z0cd5a88349)*zb16b309883);z183fd27444->z0e5f6239d4=(z3f409ba692)?z15cce05e60(*mxGetPr(zfb30127239)*zb16b309883):z6e71fd742f;if(zd8a0291585){
z183fd27444->zf66194a2f2=zf66194a2f2;if(z756a2380a7){size=zd8a0291585*z477fe62ff4*(0xb41+3878-0x1a63);
#ifdef z1919c093bf
printf("\x20\x20\x25\x73\x3a\x20\x41\x6c\x6c\x6f\x63\x20\x44\x41\x20\x44\x4d\x41\x20\x70\x6f\x6f\x6c\x20\x28\x25\x69\x20\x62\x79\x74\x65\x73\x29" "\n",zf1b619edf2,size);
#endif
zbf7f59fabb=xpcAllocPhysicalMemory(size+(0x127f+6479-0x1bce));
if(!zbf7f59fabb){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x46\x61\x69\x6c\x65\x64\x20\x61\x6c\x6c\x6f\x63\x61\x74\x69\x6e\x67\x20\x44\x41\x20\x44\x4d\x41\x20\x70\x6f\x6f\x6c\x21" "\n",zf1b619edf2,z9f2f6f91bc);ssSetErrorStatus(S,zea4cd01646);return;}
memset(zbf7f59fabb,(0x108f+1109-0x14e4),size);for(i=(0xc69+2331-0x1584);i<zd8a0291585;i++){z9f2f6f91bc=(uint32_T)mxGetPr(z15e14cdb28)[i]-(0x12bb+3386-0x1ff4);for(z26dbd73a5e=(0x143b+821-0x1770);z26dbd73a5e<zd8a0291585;z26dbd73a5e++)
{if((uint32_T)mxGetPr(za073552a39)[z26dbd73a5e]-(0x122b+4575-0x2409)==z9f2f6f91bc)break;}z17eef240dd=(mxGetN(z22e8a8c9a0)==(0x8c1+5099-0x1cab))?mxGetPr(z22e8a8c9a0)[(0x210+9019-0x254b)]:mxGetPr(z22e8a8c9a0)[z26dbd73a5e];
for(z2f01869a88=(0x1477+2058-0x1c81),z0302abc276=z9f2f6f91bc;z2f01869a88<z477fe62ff4;z2f01869a88++,z0302abc276+=zd8a0291585){za0112e85fa=(int32_T)((z17eef240dd+offset)*z0754dd67cc);if(za0112e85fa>65535)za0112e85fa=65535;else if(za0112e85fa<(0x101d+4460-0x2189))za0112e85fa=(0xe71+2779-0x194c);zbf7f59fabb[z0302abc276]=za0112e85fa;}}

z612247fc60->z0aa1aefd2d=zbf7f59fabb;
z612247fc60->zbdff1f0f0c=(0x17a3+2053-0x1f60);
z612247fc60->zcf249b6ea3=size;
z612247fc60->zec1a4ba4e1=(0x95c+674-0xbfe);
z612247fc60->z851354b1dc=(0x1055+3555-0x1e37);
z612247fc60->z8179a91d7b=((0xa01+5617-0x1ff0)<<z551c6433ad)
|((0x15df+785-0x18f0)<<z9ff50a1d47)
|((0x1125+5501-0x26a1)<<z60fa808c68)
|((0xf5f+5343-0x243e)<<za495e5447f)
|((0x50d+3695-0x137b)<<ze284f6dda4)
|((0x1252+721-0x1523)<<zbd9cc3ea3e)

|((0x127a+2891-0x1dc4)<<zb538b13023)
|((0x10ed+687-0x139b)<<z082f6638ca)
|((0x496+6525-0x1e13)<<ze57bee66e7)
|((0x232+1972-0x9e6)<<ze8cdd8692c)
|((0xae2+1511-0x10c9)<<z48a21f4939)
|((0x666+7258-0x22c0)<<z6bd25a24d0)

|((0x166a+1238-0x1b40)<<zf9faf82f5c)
|((0xe90+2373-0x17d5)<<zf04451bb1a)
|((0x2b9+6728-0x1d01)<<z6e73a222da)
|((0x1660+705-0x1921)<<z25384e33ac)
;z612247fc60->z851354b1dc=(0x1ea1+34-0x1ec3);z612247fc60->z851354b1dc=((0x5d7+7072-0x2176)<<z08d0b4e518);z612247fc60->z851354b1dc=((0x240+5566-0x17fd)<<z08d0b4e518)|((0x111+6545-0x1aa1)<<z3e27e0685c);
#ifdef z1919c093bf
printf("\x70\x50\x4c\x58\x2d\x3e\x64\x6d\x61\x31\x6d\x6f\x64\x65\x20\x28\x30\x78\x30\x30\x30\x32\x31\x44\x34\x32\x29\x3a\x20\x30\x78\x25\x30\x38\x78\x20\x25\x73" "\n",z612247fc60->z8179a91d7b,(z612247fc60->z8179a91d7b==138562)?"\x6f\x6b":"\x6f\x6f\x70\x73");
#endif
if(!z68c505c5e0){z74b7b2fba8=(0x112+2673-0xb81);
z68c505c5e0=(0x64d+6661-0x2051);
z615725805d=((0x205+866-0x566)<<z86eea319be);
z183fd27444->z99fc22bc3e=(z74b7b2fba8&za40af8be03)+z615725805d;z183fd27444->z3b57a6b8bc=((z74b7b2fba8*z68c505c5e0)-(0x1f7d+1111-0x23d3))&z95b35fa456;z183fd27444->z3378080323=z0205a40243;
z14bc320aa4=z14bc320aa4|((0x1cb+3101-0xde7)<<z28c5dfd366)
|((0x459+4822-0x172d)<<z34c5a897f9)
|((0x67c+6167-0x1e91)<<z5dd45f00a5)
|((0x867+599-0xabd)<<zf54309da44)
|((0xb44+205-0xc10)<<zaf09f9129e)
|((0x23d+6017-0x19bd)<<za74c2ed17b)
|((0x518+4065-0x14f8)<<zbf7ff181d5)
;z183fd27444->z14bc320aa4=z14bc320aa4;
size=z68c505c5e0*z74b7b2fba8*(0x99d+916-0xd2d);
#ifdef z1919c093bf
printf("\x20\x20\x25\x73\x3a\x20\x41\x6c\x6c\x6f\x63\x20\x41\x44\x20\x44\x4d\x41\x20\x70\x6f\x6f\x6c\x20\x28\x25\x69\x20\x62\x79\x74\x65\x73\x29" "\n",zf1b619edf2,size);
#endif
z920d002f57=xpcAllocPhysicalMemory(size+4096);
if(!z920d002f57){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x46\x61\x69\x6c\x65\x64\x20\x61\x6c\x6c\x6f\x63\x61\x74\x69\x6e\x67\x20\x41\x44\x20\x44\x4d\x41\x20\x70\x6f\x6f\x6c\x21" "\n",zf1b619edf2,z9f2f6f91bc);ssSetErrorStatus(S,zea4cd01646);return;}memset(z920d002f57,(0xaeb+5895-0x21f2),size);
z612247fc60->ze467ac829e=z920d002f57;
z612247fc60->zad0f44b32f=(0x4cd+3418-0x120f);
z612247fc60->z0d3df49bb1=size;
z612247fc60->z37045d746d=((0x111c+2419-0x1a8f)<<z9b226a1cab)|((0x959+7178-0x2562)<<z583be2f5c1)
|((0x733+2667-0x119d)<<z2472b0b295)
|((0x56c+7585-0x230c)<<zecc0da7a42);
z612247fc60->z592e200bad=((0xce3+6694-0x2707)<<z551c6433ad)
|((0x1850+1900-0x1fbc)<<z9ff50a1d47)
|((0x171f+1813-0x1e33)<<z60fa808c68)
|((0xb58+2510-0x1526)<<za495e5447f)
|((0x19ab+2649-0x2403)<<ze284f6dda4)
|((0x55b+2889-0x10a4)<<zbd9cc3ea3e)
|((0xe32+4553-0x1ffa)<<z72a2273697)
|((0x470+2463-0xe0e)<<zb538b13023)
|((0x44+3833-0xf3c)<<z082f6638ca)
|((0x6ff+3104-0x131f)<<ze57bee66e7)
|((0x630+6287-0x1ebf)<<ze8cdd8692c)
|((0x994+346-0xaee)<<z48a21f4939)
|((0xc30+4444-0x1d8c)<<z6bd25a24d0)
|((0x24c2+348-0x261d)<<z3471c69077)
|((0x71d+7214-0x234b)<<zf9faf82f5c)
|((0xf16+135-0xf9d)<<zf04451bb1a)
|((0x528+7551-0x22a7)<<z6e73a222da)
|((0x1074+3959-0x1feb)<<z25384e33ac)
;
#ifdef z1919c093bf
printf("\x70\x50\x4c\x58\x2d\x3e\x64\x6d\x61\x30\x6d\x6f\x64\x65\x20\x28\x30\x78\x30\x30\x30\x32\x31\x44\x34\x32\x29\x3a\x20\x30\x78\x25\x30\x38\x78\x20\x25\x73" "\n",z612247fc60->z592e200bad,(z612247fc60->z592e200bad==138562)?"\x6f\x6b":"\x6f\x6f\x70\x73");
#endif
z612247fc60->z1def6086f7=((0xdc5+1733-0x1489)<<zb7f318c2a8);z612247fc60->z1def6086f7=(0x2d9+7616-0x2099);z612247fc60->z1def6086f7=((0x1043+3246-0x1cf0)<<z08d0b4e518);z612247fc60->z1def6086f7=((0xd01+5249-0x2181)<<z08d0b4e518)|((0xfad+1378-0x150e)<<z3e27e0685c);z68c505c5e0=(0x4e3+6575-0x1e92);
}}}
if(z68c505c5e0){for(i=(0xf38+4324-0x201c),z615725805d=(0x23c3+471-0x259a);i<z68c505c5e0;i++){z9f2f6f91bc=(uint32_T)mxGetPr(zdbac35e6a8)[i]-(0x1a9+1583-0x7d7);if(z9f2f6f91bc>=zf16899d845){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x49\x6c\x6c\x65\x67\x61\x6c\x20\x69\x6e\x70\x75\x74\x20\x63\x68\x61\x6e\x6e\x65\x6c\x20\x69\x6e\x64\x65\x78\x3a\x20\x25\x69" "\n",zf1b619edf2,z9f2f6f91bc);ssSetErrorStatus(S,zea4cd01646);return;}z615725805d|=((0x918+1954-0x10b9)<<(z9f2f6f91bc+z86eea319be));}z183fd27444->z99fc22bc3e=(z74b7b2fba8&za40af8be03)+z615725805d;if(z74b7b2fba8*z68c505c5e0>z95b35fa456){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x46\x72\x61\x6d\x65\x20\x73\x69\x7a\x65\x20\x70\x72\x6f\x62\x6c\x65\x6d" "\n",zf1b619edf2,z9f2f6f91bc);ssSetErrorStatus(S,zea4cd01646);return;}z183fd27444->z3b57a6b8bc=z95b35fa456&((z74b7b2fba8*z68c505c5e0)-(0x7d7+496-0x9c6));
if(zbe86ff2fa9){
size=z68c505c5e0*z74b7b2fba8*(0x15e2+3916-0x252a);
#ifdef z1919c093bf
printf("\x20\x20\x25\x73\x3a\x20\x41\x6c\x6c\x6f\x63\x20\x41\x44\x20\x44\x4d\x41\x20\x70\x6f\x6f\x6c\x20\x28\x25\x69\x20\x62\x79\x74\x65\x73\x29" "\n",zf1b619edf2,size);
#endif
z920d002f57=xpcAllocPhysicalMemory(size+4096);if(!z920d002f57){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x46\x61\x69\x6c\x65\x64\x20\x61\x6c\x6c\x6f\x63\x61\x74\x69\x6e\x67\x20\x41\x44\x20\x44\x4d\x41\x20\x70\x6f\x6f\x6c\x21" "\n",zf1b619edf2,z9f2f6f91bc);ssSetErrorStatus(S,zea4cd01646);return;}memset(z920d002f57,(0x6eb+1863-0xe32),size+(0x1394+7831-0x222b));
z612247fc60->ze467ac829e=z920d002f57;
z612247fc60->zad0f44b32f=(0x85d+4538-0x19ff);
z612247fc60->z0d3df49bb1=size;
z612247fc60->z37045d746d=((0xbb3+6122-0x239d)<<z9b226a1cab)|((0x1444+2671-0x1eb2)<<z583be2f5c1)
|((0xb60+1604-0x11a3)<<z2472b0b295)
|((0x114c+4240-0x21db)<<zecc0da7a42);
z612247fc60->z592e200bad=((0x875+7760-0x26c3)<<z551c6433ad)
|((0x112+429-0x2bf)<<z9ff50a1d47)
|((0x2166+1077-0x259a)<<z60fa808c68)
|((0xc01+1455-0x11b0)<<za495e5447f)
|((0x10c5+4801-0x2385)<<ze284f6dda4)
|((0xaba+6116-0x229e)<<zbd9cc3ea3e)
|((0x7f2+6574-0x219f)<<z72a2273697)
|((0xc0a+4833-0x1eea)<<zb538b13023)
|((0x2090+300-0x21bb)<<z082f6638ca)
|((0x12a+5747-0x179d)<<ze57bee66e7)
|((0x1b41+1919-0x22c0)<<ze8cdd8692c)
|((0x4d5+220-0x5b1)<<z48a21f4939)
|((0x12e5+2426-0x1c5f)<<z6bd25a24d0)
|((0x851+2773-0x1325)<<z3471c69077)
|((0x185+5475-0x16e8)<<zf9faf82f5c)
|((0x1874+2387-0x21c7)<<zf04451bb1a)
|((0x7e1+5584-0x1db1)<<z6e73a222da)
|((0xd5f+2114-0x15a1)<<z25384e33ac)
;
#ifdef z1919c093bf
printf("\x70\x50\x4c\x58\x2d\x3e\x64\x6d\x61\x30\x6d\x6f\x64\x65\x20\x28\x30\x78\x30\x30\x30\x32\x31\x44\x34\x32\x29\x3a\x20\x30\x78\x25\x30\x38\x78\x20\x25\x73" "\n",z612247fc60->z592e200bad,(z612247fc60->z592e200bad==138562)?"\x6f\x6b":"\x6f\x6f\x70\x73");
#endif





{z612247fc60->z1def6086f7=((0x1d94+931-0x2136)<<zb7f318c2a8);z612247fc60->z1def6086f7=(0x618+5927-0x1d3f);z612247fc60->z1def6086f7=((0xb39+4437-0x1c8d)<<z08d0b4e518);z612247fc60->z1def6086f7=((0xa35+1923-0x11b7)<<z08d0b4e518)|((0x20f7+620-0x2362)<<z3e27e0685c);}}}}
if(zaf49fd5709||z963c71b80b){z2b74be5904=((uint32_T)*mxGetPr(zac66f82ae1)==z4ef2da205f)?z7231b70c4f:z7c9bc122b1;z7503f59baa=((uint32_T)*mxGetPr(z17f5615ed3)==z4ef2da205f)?z7231b70c4f:z7c9bc122b1;z53343b042a=z183fd27444->z53343b042a;
if(z2b74be5904)z53343b042a|=(z2b74be5904<<zc1a63d2a27);if(z7503f59baa)z53343b042a|=(z7503f59baa<<zffec758124);z183fd27444->z53343b042a=z53343b042a;printf("\x53\x65\x74\x74\x69\x6e\x67\x20\x44\x69\x67\x69\x74\x61\x6c\x49\x4f\x20\x42\x79\x74\x65\x30\x20\x74\x6f\x20\x25\x73\x20\x61\x6e\x64\x20\x42\x79\x74\x65\x31\x20\x74\x6f\x20\x25\x73\x20" "\n",(z2b74be5904==z7231b70c4f)?"\x4f\x55\x54\x50\x55\x54":"\x49\x4e\x50\x55\x54",(z7503f59baa==z7231b70c4f)?"\x4f\x55\x54\x50\x55\x54":"\x49\x4e\x50\x55\x54");}ze5344c3613(S,z183fd27444);zc2f11ccb7a(0.1);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE






#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T i,z9f2f6f91bc,z14bc320aa4;int32_T za0112e85fa;real_T z17eef240dd;uint32_T zd8a0291585;real_T z0754dd67cc=ssGetRWorkValue(S,zbd291336e9);real_T offset=ssGetRWorkValue(S,z3b859f7689);z83d93efdde*z612247fc60=ssGetPWorkValue(S,zc4ce4213f7);z020494c81d*z183fd27444=ssGetPWorkValue(S,zc1cfebef6f);
#ifdef zb482f925e2
printf("\x53\x65\x74\x75\x70\x2e\x54\x65\x72\x6d\x69\x6e\x61\x74\x65\x20\x28\x25\x73\x69\x6e\x69\x74\x29" "\n",(xpceIsModelInit())?"":"\x6e\x6f\x6e\x2d");
#endif
ze5344c3613(S,z183fd27444);zd8a0291585=(uint32_T)mxGetN(za073552a39);if(zd8a0291585==(0xfb5+3057-0x1ba5)&&(uint32_T)mxGetPr(za073552a39)[(0x12b+302-0x259)]==(0xd27+4976-0x2097))
zd8a0291585=(0x14df+369-0x1650);z14bc320aa4=z183fd27444->z14bc320aa4;z14bc320aa4&=~(((0x16a+865-0x4ca)<<z7c2b0fb1d1)|((0xb6a+904-0xef1)<<z08b102ac19)|((0x617+5219-0x1a79)<<zed9cb402fc));
#ifdef z1919c093bf
printf("\x49\x4e\x49\x54\x49\x41\x4c\x49\x5a\x45" "\n");
#endif
z183fd27444->z14bc320aa4=((0x632+2034-0xe23)<<INITIALIZE);while(z183fd27444->z14bc320aa4&((0x176c+3610-0x2585)<<INITIALIZE));z183fd27444->z14bc320aa4=z14bc320aa4;z14bc320aa4&=~(((0x1b06+2543-0x24f4)<<zc0c6d7bce0)|((0xcca+892-0x1045)<<z9c45b39fac));z183fd27444->z14bc320aa4=z14bc320aa4;z183fd27444->zf66194a2f2=z183fd27444->zf66194a2f2&~((0x24f+6196-0x1a82)<<zc9661f8327);for(i=(0x2d4+1839-0xa03);i<zd8a0291585;i++){boolean_T zd31d76284c=(boolean_T)((mxGetN(za6b3fb79a3)==(0xc70+5818-0x2329))?mxGetPr(za6b3fb79a3)[(0xe75+2992-0x1a25)]:mxGetPr(za6b3fb79a3)[i]);
if(xpceIsModelInit()||zd31d76284c){z9f2f6f91bc=(uint32_T)mxGetPr(za073552a39)[i]-(0x22c+7417-0x1f24);z17eef240dd=(mxGetN(z22e8a8c9a0)==(0xb06+4943-0x1e54))?mxGetPr(z22e8a8c9a0)[(0x16c2+2096-0x1ef2)]:mxGetPr(z22e8a8c9a0)[i];
za0112e85fa=(uint32_T)((z17eef240dd+offset)*z0754dd67cc);
#ifdef z1919c093bf
printf("\x53\x65\x74\x74\x69\x6e\x67\x20\x44\x41\x20\x63\x68\x20\x25\x69\x20\x74\x6f\x20\x25\x66\x20\x28\x25\x69\x29" "\n",z9f2f6f91bc,z17eef240dd,za0112e85fa);
#endif
if((za0112e85fa>65535)||(za0112e85fa<(0xbb3+5612-0x219f))){sprintf(zea4cd01646,"\x25\x73\x20\x44\x41\x20\x69\x6e\x69\x74\x20\x76\x61\x6c\x20\x25\x69\x20\x28\x63\x68\x20\x25\x69\x29\x20\x6f\x75\x74\x20\x6f\x66\x20\x72\x61\x6e\x67\x65\x3a\x20\x25\x66\x56\x20\x28\x25\x69\x29" "\n",zf1b619edf2,i,z9f2f6f91bc,z17eef240dd,za0112e85fa);ssSetErrorStatus(S,zea4cd01646);return;}z183fd27444->zed3e896995[z9f2f6f91bc]=za0112e85fa;}}
#endif    
}static void zc2f11ccb7a(real_T t){
#ifndef MATLAB_MEX_FILE
xpcTime z9764181524,zce60958e79,zde9131ca7b;xpcGetElapsedTime(&z9764181524);do{xpcGetElapsedTime(&zce60958e79);xpcSubtractTime(&zde9131ca7b,&zce60958e79,&z9764181524);}while((((real_T)zde9131ca7b.U64.NanoSecondsLo*1e-9)+((real_T)zde9131ca7b.U64.NanoSecondsHi*4.294967296))<t);
#endif
}static uint32_T z15cce05e60(real_T x){double d=(double)((uint32_T)x);
return(uint32_T)((x-d<(d+(0xb64+519-0xd6a))-x)?d:(d+(0x10fc+3117-0x1d28)));}static void ze5344c3613(SimStruct*S,z020494c81d*z183fd27444){
#ifndef MATLAB_MEX_FILE
#ifdef z1919c093bf
uint32_T z14bc320aa4=z183fd27444->z14bc320aa4;uint32_T zf66194a2f2=z183fd27444->zf66194a2f2;z83d93efdde*z612247fc60=ssGetPWorkValue(S,zc4ce4213f7);uint32_T div,z5450d078d5,i,n;div=z183fd27444->zb6903ad9ad&16777215;printf("\x54\x72\x67\x20\x43\x6c\x6b\x3a\x20\x25\x30\x2e\x33\x45\x20\x64\x69\x76\x3a\x20\x25\x69\x2c\x20\x25\x73" "\n",div/zb16b309883,div,(z14bc320aa4&((0x27a+3005-0xe36)<<z1378a8e713))?"\x49\x6e\x69\x74\x69\x61\x74\x6f\x72":"\x54\x61\x72\x67\x65\x74");div=z183fd27444->z3378080323&16777215;printf("\x41\x44\x20\x43\x6c\x6b\x3a\x20\x20\x25\x30\x2e\x33\x45\x20\x64\x69\x76\x3a\x20\x25\x69\x2c\x20\x25\x73" "\n",div/zb16b309883,div,(z14bc320aa4&((0x2cb+8349-0x2367)<<za74c2ed17b))?"\x49\x6e\x69\x74\x69\x61\x74\x6f\x72":"\x54\x61\x72\x67\x65\x74");div=z183fd27444->z0e5f6239d4&16777215;printf("\x44\x41\x20\x43\x6c\x6b\x3a\x20\x20\x25\x30\x2e\x33\x45\x20\x64\x69\x76\x3a\x20\x25\x69\x2c\x20\x25\x73" "\n",div/zb16b309883,div,(zf66194a2f2&((0x4b9+5945-0x1bf1)<<z2de56a8878))?"\x49\x6e\x69\x74\x69\x61\x74\x6f\x72":"\x54\x61\x72\x67\x65\x74");z5450d078d5=z183fd27444->z99fc22bc3e;printf("\x41\x44\x20\x46\x72\x61\x6d\x65\x3a\x20\x25\x69\x2c\x20\x42\x75\x72\x73\x74\x3a\x20\x25\x73\x2c\x20\x42\x75\x66\x3a\x20\x25\x73\x20\x43\x68\x3a\x20",z5450d078d5&za40af8be03,(z14bc320aa4&((0x15ba+1561-0x1bd2)<<zf54309da44))?"\x6f\x6e\x20":"\x6f\x66\x66",(z14bc320aa4&((0x3e0+63-0x41e)<<zaf09f9129e))?"\x65\x6e\x20":"\x64\x69\x73");for(i=(0xcfb+4946-0x204d);i<zf16899d845;i++){if(z5450d078d5&((0x1e90+189-0x1f4c)<<(z86eea319be+i)))printf("\x25\x69",i+(0x5b6+770-0x8b7));
else printf("\x2d");}printf("\n");z5450d078d5=z612247fc60->zcf249b6ea3;
n=(zf66194a2f2&((0x1c18+1350-0x215d)<<z871ba5e63d))?(0x1a0a+1483-0x1fd4):(0xfa2+2934-0x1b18)+(zf66194a2f2&((0x277+6809-0x1d0f)<<z059e80d468))?(0x101f+3817-0x1f07):(0x1256+3346-0x1f68)+(zf66194a2f2&((0x82a+2024-0x1011)<<zf3e0b2fa74))?(0x548+1974-0xcfd):(0x1f4+4633-0x140d)+(zf66194a2f2&((0x13d0+17-0x13e0)<<zeeec8b2ebb))?(0x593+4366-0x16a0):(0x185+4168-0x11cd);printf("\x44\x41\x20\x46\x72\x61\x6d\x65\x3a\x20\x25\x69\x2c\x20\x42\x75\x72\x73\x74\x3a\x20\x25\x73\x2c\x20\x42\x75\x66\x3a\x20\x25\x73\x20\x43\x68\x3a\x20\x25\x73\x25\x73\x25\x73\x25\x73" "\n",n?z5450d078d5/(n*(0x1d+9132-0x23c5)):(0x716+6897-0x2207),(zf66194a2f2&((0xcf0+5630-0x22ed)<<zc9661f8327))?"\x6f\x6e\x20":"\x6f\x66\x66",(z14bc320aa4&((0xb1b+3694-0x1988)<<zc0c6d7bce0))?"\x65\x6e\x20":"\x64\x69\x73",(zf66194a2f2&((0x3c7+86-0x41c)<<z871ba5e63d))?"\x31":"\x2d",(zf66194a2f2&((0x1463+696-0x171a)<<z059e80d468))?"\x32":"\x2d",(zf66194a2f2&((0xb3b+3609-0x1953)<<zf3e0b2fa74))?"\x33":"\x2d",(zf66194a2f2&((0x19b+688-0x44a)<<zeeec8b2ebb))?"\x34":"\x2d");printf("\x46\x59\x49\x3a\x20\x42\x43\x52\x3d\x25\x30\x38\x78\x20\x42\x4f\x52\x3d\x25\x30\x38\x78" "\n",z14bc320aa4,zf66194a2f2);
#endif
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif
#if (0x1895+3255-0x254c)

static void z273a153073(SimStruct*S,z020494c81d*z183fd27444){int(0x66f+7680-0x246e);
for(i=(0xda8+2414-0x1716);i<zf16899d845;i++){uint32_T zc05aed7b41,z1a9972b388,zd06c92a743,z7201c7f896,zed677d5e41,zb65061fa06;z183fd27444->z6c201be134=z6a19b0a974+(0xbbf+2105-0x13f6)*i;
zc05aed7b41=z183fd27444->z6c201be134;
z183fd27444->z6c201be134=z2dde21a7c6+(0x1b35+1577-0x215c)*i;z1a9972b388=z183fd27444->z6c201be134;z183fd27444->z6c201be134=z4e1515da7d+(0x9cb+1031-0xdd0)*i;zd06c92a743=z183fd27444->z6c201be134;z183fd27444->z6c201be134=ze4fe6ff741+(0x76a+860-0xac4)*i;
z7201c7f896=z183fd27444->z6c201be134;
z183fd27444->z6c201be134=z23b316812b+(0x10cf+4312-0x21a5)*i;zed677d5e41=z183fd27444->z6c201be134;z183fd27444->z6c201be134=za44bbf15c6+(0x153b+4435-0x268c)*i;zb65061fa06=z183fd27444->z6c201be134;printf("\x41\x44\x20\x63\x68\x25\x69\x3a\x20\x25\x35\x69\x20\x25\x35\x69\x20\x25\x35\x69",i,zc05aed7b41,z1a9972b388,zd06c92a743);printf("\x20\x25\x35\x69\x20\x25\x35\x69\x20\x25\x35\x69" "\n",z7201c7f896,zed677d5e41,zb65061fa06);}for(i=(0x15+9576-0x257d);i<z173eaebd82;i++){uint32_T zbf8cb6cfdb,g;z183fd27444->z6c201be134=z7fcb923f93+(0x10d0+224-0x11ae)*i;
zbf8cb6cfdb=z183fd27444->z6c201be134;
z183fd27444->z6c201be134=za2c38cc5e5+(0x778+5476-0x1cda)*i;
g=z183fd27444->z6c201be134;
printf("\x44\x41\x20\x63\x68\x25\x69\x3a\x20\x6f\x3d\x25\x35\x69\x20\x67\x3d\x25\x35\x69" "\n",i,zbf8cb6cfdb,g);}
z183fd27444->z14bc320aa4=((0xd3b+3205-0x19bf)<<INITIALIZE);while(z183fd27444->z14bc320aa4&((0x1e7+6522-0x1b60)<<INITIALIZE));
for(i=(0xb73+1294-0x1081);i<zf16899d845;i++){uint32_T zc05aed7b41,z1a9972b388,zd06c92a743,z7201c7f896,zed677d5e41,zb65061fa06;z183fd27444->z6c201be134=z6a19b0a974+(0x2c4+6962-0x1df4)*i;
zc05aed7b41=z183fd27444->z6c201be134;
z183fd27444->z6c201be134=z2dde21a7c6+(0x1c5+2320-0xad3)*i;z1a9972b388=z183fd27444->z6c201be134;z183fd27444->z6c201be134=z4e1515da7d+(0x6fc+8104-0x26a2)*i;zd06c92a743=z183fd27444->z6c201be134;z183fd27444->z6c201be134=ze4fe6ff741+(0x125c+1187-0x16fd)*i;
z7201c7f896=z183fd27444->z6c201be134;
z183fd27444->z6c201be134=z23b316812b+(0x11+9670-0x25d5)*i;zed677d5e41=z183fd27444->z6c201be134;z183fd27444->z6c201be134=za44bbf15c6+(0x1735+3515-0x24ee)*i;zb65061fa06=z183fd27444->z6c201be134;printf("\x41\x44\x20\x63\x68\x25\x69\x3a\x20\x25\x35\x69\x20\x25\x35\x69\x20\x25\x35\x69",i,zc05aed7b41,z1a9972b388,zd06c92a743);printf("\x20\x25\x35\x69\x20\x25\x35\x69\x20\x25\x35\x69" "\n",z7201c7f896,zed677d5e41,zb65061fa06);}for(i=(0x1f72+754-0x2264);i<z173eaebd82;i++){uint32_T zbf8cb6cfdb,g;z183fd27444->z6c201be134=z7fcb923f93+(0x539+6056-0x1cdf)*i;
zbf8cb6cfdb=z183fd27444->z6c201be134;
z183fd27444->z6c201be134=za2c38cc5e5+(0x187a+2744-0x2330)*i;
g=z183fd27444->z6c201be134;
printf("\x44\x41\x20\x63\x68\x25\x69\x3a\x20\x6f\x3d\x25\x35\x69\x20\x67\x3d\x25\x35\x69" "\n",i,zbf8cb6cfdb,g);}}
#endif

