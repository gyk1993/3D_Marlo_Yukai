/* Copyright 2006-2013 Speedgoat GmbH. */
#define S_FUNCTION_LEVEL (0x17ea+734-0x1ac6)
#undef S_FUNCTION_NAME
#define S_FUNCTION_NAME sg_IO601_setup_s_3
#include <stddef.h>
#include <stdlib.h>
#include "simstruc.h"
#ifdef MATLAB_MEX_FILE
#include "mex.h"
#endif
#ifndef MATLAB_MEX_FILE
#include <windows.h>
#include "io_xpcimport.h"
#include "pci_xpcimport.h"
#include "time_xpcimport.h"
#include "ioext_xpcimport.h"
#include "util_xpcimport.h"
#endif
#define zdf24515981         ((0x10c+5048-0x14b9))
#define z58c4256b9b        ssGetSFcnParam(S,(0x270+2392-0xbc8))
#define za457bf2dc4           ssGetSFcnParam(S,(0xa5b+3175-0x16c1))  
#define z13d4592f13 ssGetSFcnParam(S,(0x851+7846-0x26f5))
#define za50a344e1b            ssGetSFcnParam(S,(0x1338+3563-0x2120))
#define z39195436c1            ssGetSFcnParam(S,(0x1b6+1874-0x904))
#define z69ea1c654a        ssGetSFcnParam(S,(0x123c+3030-0x1e0d))
#define zdd4ab756a7           ssGetSFcnParam(S,(0x3ab+4981-0x171a))
#define zc91b5ad104 ssGetSFcnParam(S,(0x1596+3096-0x21a7))
#define z9e605dec30            ssGetSFcnParam(S,(0x3c2+6758-0x1e20))
#define z8de06d052a            ssGetSFcnParam(S,(0x763+3465-0x14e3))
#define z702a26a5e9               ssGetSFcnParam(S,(0x12ac+5057-0x2663))
#define zf1b619edf2                "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x36\x30\x31"
#define z694756a014               ((0x15d8+652-0x7af))
#define zea87e0ba83               (36912)
#define z29146a1837            ((0x1c59+4744-0x1e2c))
#define zab7e64468b            (10615)
#define z2e6483d505             ((0x1268+2387-0x1bb9))
#define z57e55a08c5       ((0xe88+1955-0x162b))
#define z84eb1db314       ((0x17a6+3748-0x2649))
#define zc5ce4cb81a             ((0x241+4074-0x122b))
#define z296045870f                 ((0x818+6087-0x1fde))
#define zdfcd8b2600            ((0x1f56+1559-0x256b))
#define z63e0d8bf20               ((0xe4c+6241-0x26aa))
#define z10dc9d01f3           ((0x1025+662-0x12b7))
#define z2536dfa17d          ((0x11c3+4050-0x218f))
#define z9ae489463a           ((0x888+1287-0xd88))
#define zd11f22184c          ((0x30f+6432-0x1c27))
#define z72ded8c82d    ((0xa39+6374-0x2314))
#define z6930c89bc3     ((0x35d+6630-0x1d37))
#define z978445fac6        ((0x108+586-0x345))
#define z9fbf0f9979         ((0x1a47+1470-0x1ff7))
#define zd87bbfc3eb       ((0x1558+1239-0x1a20))
#define z05ed543282          ((0x1243+3480-0x1fdb))
#define z00aab4ba34       ((0xaaa+4216-0x1b21))
#define z55873e7fb7    ((0x198c+1345-0x1ecb))
static char_T zea4cd01646[(0x1d44+687-0x1ef3)];
#ifndef MATLAB_MEX_FILE
uint8_T ptrWritePointer1[(0x40c+8344-0x249a)];uint8_T ptrWritePointer2[(0x73f+444-0x8f1)];typedef struct{uint8_T zc4ac91c294;uint8_T count;uint16_T z3bcf72e3b0;uint8_T command;uint8_T data[(0x19f0+1185-0x1e46)];}zd40b3e4dfd;static void zc0d11e95a0(volatile uint32_T*z3e5b8e05d8){uint32_T zc1ac25c1d6;zc1ac25c1d6=z3e5b8e05d8[(0x12bf+3629-0x20d7)];z3e5b8e05d8[(0x3f6+1990-0xba7)]=zc1ac25c1d6&~((0xd8+2048-0x8d7)<<(0x1a23+2685-0x249e));z3e5b8e05d8[(0xf0d+5897-0x2601)]=zc1ac25c1d6|((0x27+1266-0x518)<<(0x1245+4957-0x25a0));}static void z2521217c2d(volatile uint32_T*z3e5b8e05d8,volatile uint8_T*z27fd94ac66){uint32_T zc1ac25c1d6;
zc1ac25c1d6=z3e5b8e05d8[(0x25b+8423-0x232d)];zc1ac25c1d6&=~((0x116f+4462-0x22dc)<<(0x1930+2121-0x216e));z3e5b8e05d8[(0x486+1670-0xaf7)]=zc1ac25c1d6;rl32eWaitDouble(0.050);zc1ac25c1d6|=((0x1713+2400-0x2072)<<(0xb76+4974-0x1ed9));z3e5b8e05d8[(0x1dff+1023-0x21e9)]=zc1ac25c1d6;rl32eWaitDouble(0.050);z27fd94ac66[(0x18ec+2949-0x2471)]=(0x1131+5529-0x26ca);z27fd94ac66[(0x529+1974-0xcde)]=(0xcd0+554-0xefa);z27fd94ac66[(0x108d+3514-0x1e45)]=(0x14c3+1197-0x1970);z27fd94ac66[(0x636+2738-0x10e5)]=(0xe4+5119-0x14e0);z27fd94ac66[(0x22c0+964-0x2680)]=(0x2cc+4559-0x1499);z27fd94ac66[(0x5af+4642-0x17cc)]=(0xbcc+4097-0x1bcd);z27fd94ac66[(0x1b6+7767-0x2007)]=(0x1541+53-0x1575);z27fd94ac66[(0xf93+2844-0x1aaf)]=(0xe7d+3194-0x1af6);rl32eWaitDouble(0.050);z27fd94ac66[(0xa93+6041-0x222b)]=(0x8db+6009-0x2054);rl32eWaitDouble(0.050);zc0d11e95a0(z3e5b8e05d8);}static void z256e1590a0(volatile uint32_T*z3e5b8e05d8,volatile zd40b3e4dfd*zd042227c40){zd042227c40->zc4ac91c294=(0x1056+1472-0x1616);zd042227c40->count=(0x456+4588-0x1641);zd042227c40->command=zdfcd8b2600;zd042227c40->zc4ac91c294=(0x16a3+693-0x1957);zc0d11e95a0(z3e5b8e05d8);while(zd042227c40->zc4ac91c294!=(0x1916+424-0x1abc));return;}static uint8_T zf344ecfecb(volatile uint32_T*z3e5b8e05d8,volatile zd40b3e4dfd*zd042227c40,uint8_T z0add1d1c25,uint8_T z5e97dc60db,uint8_T z9b0743fe91,uint8_T mode){zd042227c40->zc4ac91c294=(0x19cb+1529-0x1fc4);zd042227c40->count=(0x1e9b+1306-0x23b0);zd042227c40->command=z10dc9d01f3;zd042227c40->data[(0xa0c+4899-0x1d2f)]=z0add1d1c25;zd042227c40->data[(0x19ef+375-0x1b65)]=z5e97dc60db;zd042227c40->data[(0x270+3956-0x11e2)]=z9b0743fe91;zd042227c40->data[(0x161c+2901-0x216e)]=mode;zd042227c40->zc4ac91c294=(0x107a+1954-0x181b);zc0d11e95a0(z3e5b8e05d8);while(zd042227c40->zc4ac91c294!=(0xfc+551-0x321));return zd042227c40->data[(0x983+5220-0x1de7)];
}static uint8_T z36e52286a2(volatile uint32_T*z3e5b8e05d8,volatile zd40b3e4dfd*zd042227c40,uint8_T z0add1d1c25){zd042227c40->zc4ac91c294=(0x608+53-0x63d);zd042227c40->count=(0xb7+1319-0x5dc);zd042227c40->command=z2536dfa17d;zd042227c40->data[(0x5a3+8132-0x2567)]=z0add1d1c25;zd042227c40->zc4ac91c294=(0x1281+2563-0x1c83);zc0d11e95a0(z3e5b8e05d8);
while(zd042227c40->zc4ac91c294!=(0x2a7+4026-0x125f));return zd042227c40->data[(0x466+7329-0x2107)];
}static uint8_T z2cb48b8ffe(volatile uint32_T*z3e5b8e05d8,volatile zd40b3e4dfd*zd042227c40,uint8_T z0add1d1c25,uint8_T mode){zd042227c40->zc4ac91c294=(0x1e38+1864-0x2580);zd042227c40->count=(0x1269+2524-0x1c42);zd042227c40->command=z72ded8c82d;zd042227c40->data[(0x5f5+4463-0x1764)]=z0add1d1c25;zd042227c40->data[(0x167+1522-0x758)]=mode;zd042227c40->zc4ac91c294=(0x2ff+4429-0x144b);zc0d11e95a0(z3e5b8e05d8);while(zd042227c40->zc4ac91c294!=(0x68b+3363-0x13ac));return zd042227c40->data[(0x4cf+4493-0x165c)];
}static uint8_T z3d252d79db(volatile uint32_T*z3e5b8e05d8,volatile zd40b3e4dfd*zd042227c40,uint8_T z0add1d1c25){zd042227c40->zc4ac91c294=(0xbc3+35-0xbe6);zd042227c40->count=(0x1c96+2361-0x25cd);zd042227c40->command=z9ae489463a;zd042227c40->data[(0xddd+3600-0x1bed)]=z0add1d1c25;zd042227c40->zc4ac91c294=(0x7db+3220-0x146e);zc0d11e95a0(z3e5b8e05d8);while(zd042227c40->zc4ac91c294!=(0x250+6543-0x1bdd));return zd042227c40->data[(0x9e8+6006-0x215e)];
}static uint8_T z49452fc13f(volatile uint32_T*z3e5b8e05d8,volatile zd40b3e4dfd*zd042227c40,uint8_T z0add1d1c25,uint8_T z949a944c9a,uint8_T mode,uint32_T z4b4cfe7c62,uint32_T z9bd3a054dd){zd042227c40->zc4ac91c294=(0x1ad2+162-0x1b74);zd042227c40->count=(0x156+5497-0x16c5);zd042227c40->command=zd87bbfc3eb;zd042227c40->data[(0xaff+3457-0x1880)]=z0add1d1c25;zd042227c40->data[(0x5a8+1633-0xc08)]=z949a944c9a;zd042227c40->data[(0x568+7988-0x249a)]=mode;zd042227c40->data[(0x6f9+6644-0x20ea)]=(uint8_T)(z4b4cfe7c62&(0x916+1598-0xe55));zd042227c40->data[(0x16ff+4105-0x2704)]=(uint8_T)((z4b4cfe7c62>>(0xd24+1760-0x13fc))&(0x13bd+2552-0x1cb6));zd042227c40->data[(0x97d+5700-0x1fbc)]=(uint8_T)((z4b4cfe7c62>>(0x1722+4051-0x26e5))&(0x127a+4844-0x2467));zd042227c40->data[(0x4e7+8108-0x248d)]=(uint8_T)((z4b4cfe7c62>>(0x1349+2491-0x1cec))&(0x14d4+4581-0x25ba));zd042227c40->data[(0xdfd+2706-0x1888)]=(uint8_T)(z9bd3a054dd&(0x2ba+7450-0x1ed5));zd042227c40->data[(0x79f+1490-0xd69)]=(uint8_T)((z9bd3a054dd>>(0x1842+3418-0x2594))&(0x142b+1634-0x198e));zd042227c40->data[(0x817+2016-0xfee)]=(uint8_T)((z9bd3a054dd>>(0xdd6+4101-0x1dcb))&(0x26f+9237-0x2585));zd042227c40->data[(0xab+2998-0xc57)]=(uint8_T)((z9bd3a054dd>>(0x1186+3686-0x1fd4))&(0xc9b+860-0xef8));zd042227c40->zc4ac91c294=(0xa9a+7085-0x2646);
zc0d11e95a0(z3e5b8e05d8);while(zd042227c40->zc4ac91c294!=(0x4e6+7603-0x2297));return zd042227c40->data[(0x489+3715-0x130c)];
}
#endif
static void mdlInitializeSizes(SimStruct*S){int_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x6dc+7376-0x23ac));ssSetNumDiscStates(S,(0x7ba+4171-0x1805));ssSetNumInputPorts(S,(0x1dbf+2349-0x26ec));ssSetNumOutputPorts(S,(0x653+7109-0x2218));ssSetNumSampleTimes(S,(0x66d+2126-0xeba));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,(0x4d2+7711-0x22f1));ssSetNumModes(S,(0x19b4+1921-0x2135));ssSetNumNonsampledZCs(S,(0x357+2165-0xbcc));for(i=(0x1382+3377-0x20b3);i<zdf24515981;i++){ssSetSFcnParamNotTunable(S,i);}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x4cd+4772-0x1771),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x1553+4235-0x25de),0.0);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint8_T version[(0x16+8641-0x21d1)];uint8_T ze7686fdd83;uint8_T z5e97dc60db,z9b0743fe91;uint8_T z0add1d1c25,mode,z949a944c9a;int8_T status;uint32_T z4b4cfe7c62,z9bd3a054dd,i;volatile zd40b3e4dfd*zd042227c40;volatile uint32_T*z3e5b8e05d8;volatile uint8_T*z27fd94ac66;if(mxGetN(z702a26a5e9)==(0x1c1b+1800-0x2322)){z366b2f03bf=(0xf89+1070-0x13b7);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x1c7d+1355-0x21c8)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x115b+1081-0x1594)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x834+7829-0x26c8)];}if(xpcGetPCIDeviceInfo(z694756a014,zea87e0ba83,z29146a1837,zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0xd2f+4383-0x1e4e)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x865+2872-0x139d)],zeccbadd9b3.Length[(0x88a+4721-0x1afb)],XPC_RT_PG_USERREADWRITE);zeccbadd9b3.VirtAddress[(0xe9c+5006-0x2228)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0xc69+1018-0x1061)],zeccbadd9b3.Length[(0xdd+6798-0x1b69)],XPC_RT_PG_USERREADWRITE);
zd042227c40=(volatile zd40b3e4dfd*)(zeccbadd9b3.VirtAddress[(0x1fcd+1157-0x2450)]);z3e5b8e05d8=(volatile uint32_T*)(zeccbadd9b3.VirtAddress[(0x1c+6894-0x1b0a)]);z27fd94ac66=(volatile uint8_T*)(zeccbadd9b3.VirtAddress[(0x117+8612-0x22b9)]);
for(i=(0xdaf+5400-0x22c7);i<(0x2ef+5538-0x1887);i++){ptrWritePointer1[i]=(0x1103+1648-0x1773);ptrWritePointer2[i]=(0x842+7120-0x2412);}z2521217c2d(z3e5b8e05d8,z27fd94ac66);z256e1590a0(z3e5b8e05d8,zd042227c40);version[(0x1402+34-0x1424)]=zd042227c40->data[(0x171d+2361-0x2055)];version[(0xe47+4241-0x1ed7)]=zd042227c40->data[(0x715+5333-0x1be8)];version[(0x16c+4725-0x13df)]=zd042227c40->data[(0xd73+6417-0x2681)];version[(0x628+3178-0x128f)]=zd042227c40->data[(0x622+1542-0xc24)];version[(0x75c+2551-0x114f)]=zd042227c40->data[(0x9a4+2917-0x1504)];version[(0x2d2+6558-0x1c6b)]='\0';
if(strncmp(version,"\x34\x2e\x32\x37",(0x12c5+4154-0x22fa))&&strncmp(version,"\x34\x2e\x31\x38",(0xd4f+2548-0x173e))){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x77\x72\x6f\x6e\x67\x20\x66\x69\x72\x6d\x77\x61\x72\x65\x20\x28\x25\x73\x29",zf1b619edf2,version);ssSetErrorStatus(S,zea4cd01646);return;}if((uint8_T)mxGetPr(z58c4256b9b)[(0xd42+2389-0x1697)]){z0add1d1c25=(0x15d7+4234-0x2661);printf("\x69\x6e\x69\x74\x69\x61\x6c\x69\x7a\x65\x20\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x36\x30\x31\x20\x43\x41\x4e\x20\x31" "\n");z5e97dc60db=(((uint8_T)mxGetPr(z13d4592f13)[(0x773+2627-0x11b5)]-(0x1511+163-0x15b3))<<(0x1366+2743-0x1e17))|((uint8_T)mxGetPr(z13d4592f13)[(0x22b0+801-0x25d1)]-(0xe19+659-0x10ab));z9b0743fe91=(((uint8_T)mxGetPr(z13d4592f13)[(0x1ca3+2006-0x2476)]-(0x1586+326-0x16cb))<<(0xeb6+4019-0x1e65))|((uint8_T)mxGetPr(z13d4592f13)[(0xa23+361-0xb8a)]-(0x6f3+4490-0x187c));ze7686fdd83=(uint8_T)mxGetPr(za457bf2dc4)[(0x1f0a+1226-0x23d4)]-(0x14e0+2477-0x1e8c);status=zf344ecfecb(z3e5b8e05d8,zd042227c40,z0add1d1c25,z5e97dc60db,z9b0743fe91,ze7686fdd83);if(!status){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x46\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x69\x6e\x69\x74\x20\x43\x41\x4e\x20\x31",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}z4b4cfe7c62=(uint32_T)mxGetPr(za50a344e1b)[(0x179a+2100-0x1fce)];z9bd3a054dd=(uint32_T)mxGetPr(za50a344e1b)[(0x8cf+2417-0x123f)];mode=(0xc3+9022-0x2401);z949a944c9a=(0x18e3+2232-0x219b);status=z49452fc13f(z3e5b8e05d8,zd042227c40,z0add1d1c25,z949a944c9a,mode,z4b4cfe7c62,z9bd3a054dd);if(!status){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x46\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x73\x65\x74\x20\x53\x54\x44\x20\x61\x63\x63\x65\x70\x74\x61\x6e\x63\x65\x20\x6d\x61\x73\x6b\x20\x31\x20\x28\x43\x41\x4e\x20\x31\x29",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}z4b4cfe7c62=(uint32_T)mxGetPr(za50a344e1b)[(0xebf+654-0x114b)];z9bd3a054dd=(uint32_T)mxGetPr(za50a344e1b)[(0x1cf9+2376-0x263e)];mode=(0xac4+5836-0x2190);z949a944c9a=(0x1ab6+3139-0x26f8);status=z49452fc13f(z3e5b8e05d8,zd042227c40,z0add1d1c25,z949a944c9a,mode,z4b4cfe7c62,z9bd3a054dd);if(!status){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x46\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x73\x65\x74\x20\x53\x54\x44\x20\x61\x63\x63\x65\x70\x74\x61\x6e\x63\x65\x20\x6d\x61\x73\x6b\x20\x32\x20\x28\x43\x41\x4e\x20\x31\x29",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}z4b4cfe7c62=(uint32_T)mxGetPr(z39195436c1)[(0x525+1534-0xb23)];z9bd3a054dd=(uint32_T)mxGetPr(z39195436c1)[(0x1480+2930-0x1ff1)];mode=(0x2c1+8445-0x23bd);z949a944c9a=(0x32d+3787-0x11f8);status=z49452fc13f(z3e5b8e05d8,zd042227c40,z0add1d1c25,z949a944c9a,mode,z4b4cfe7c62,z9bd3a054dd);if(!status){sprintf(zea4cd01646,"\x46\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x73\x65\x74\x20\x45\x58\x54\x20\x61\x63\x63\x65\x70\x74\x61\x6e\x63\x65\x20\x6d\x61\x73\x6b\x20\x31\x20\x28\x43\x41\x4e\x20\x31\x29");
ssSetErrorStatus(S,zea4cd01646);return;}z4b4cfe7c62=(uint32_T)mxGetPr(z39195436c1)[(0xa0a+6129-0x21f9)];z9bd3a054dd=(uint32_T)mxGetPr(z39195436c1)[(0x473+2403-0xdd3)];mode=(0x62b+3992-0x15c2);z949a944c9a=(0xae9+7016-0x2650);status=z49452fc13f(z3e5b8e05d8,zd042227c40,z0add1d1c25,z949a944c9a,mode,z4b4cfe7c62,z9bd3a054dd);if(!status){sprintf(zea4cd01646,"\x46\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x73\x65\x74\x20\x45\x58\x54\x20\x61\x63\x63\x65\x70\x74\x61\x6e\x63\x65\x20\x6d\x61\x73\x6b\x20\x32\x20\x28\x43\x41\x4e\x20\x31\x29");
ssSetErrorStatus(S,zea4cd01646);return;}mode=z05ed543282;status=z2cb48b8ffe(z3e5b8e05d8,zd042227c40,z0add1d1c25,mode);if(!status){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x46\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x65\x20\x52\x58\x20\x71\x75\x65\x75\x65\x20\x28\x43\x41\x4e\x20\x31\x29",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}status=z36e52286a2(z3e5b8e05d8,zd042227c40,z0add1d1c25);if(!status){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x46\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x73\x74\x61\x72\x74\x20\x43\x41\x4e\x20\x6f\x6e\x20\x70\x6f\x72\x74\x20\x31",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}if((uint8_T)mxGetPr(z69ea1c654a)[(0x1a07+1092-0x1e4b)]){z0add1d1c25=(0xb7f+5469-0x20db);printf("\x69\x6e\x69\x74\x69\x61\x6c\x69\x7a\x65\x20\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x36\x30\x31\x20\x43\x41\x4e\x20\x32" "\n");z5e97dc60db=(((uint8_T)mxGetPr(zc91b5ad104)[(0x6ba+8242-0x26eb)]-(0x5dd+7496-0x2324))<<(0x63+3626-0xe87))|((uint8_T)mxGetPr(zc91b5ad104)[(0x195b+114-0x19cd)]-(0x101b+3677-0x1e77));z9b0743fe91=(((uint8_T)mxGetPr(zc91b5ad104)[(0xed4+3126-0x1b07)]-(0x2b2+1815-0x9c8))<<(0x1c2d+2183-0x24b0))|((uint8_T)mxGetPr(zc91b5ad104)[(0x1ac8+1135-0x1f35)]-(0x52f+3919-0x147d));ze7686fdd83=(uint8_T)mxGetPr(zdd4ab756a7)[(0x984+1796-0x1088)]-(0x679+3484-0x1414);status=zf344ecfecb(z3e5b8e05d8,zd042227c40,z0add1d1c25,z5e97dc60db,z9b0743fe91,ze7686fdd83);if(!status){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x46\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x69\x6e\x69\x74\x20\x43\x41\x4e\x20\x32",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}z4b4cfe7c62=(uint32_T)mxGetPr(z9e605dec30)[(0xbbf+489-0xda8)];z9bd3a054dd=(uint32_T)mxGetPr(z9e605dec30)[(0x1648+1593-0x1c80)];mode=(0x598+2640-0xfe8);z949a944c9a=(0xe4b+2753-0x190c);status=z49452fc13f(z3e5b8e05d8,zd042227c40,z0add1d1c25,z949a944c9a,mode,z4b4cfe7c62,z9bd3a054dd);if(!status){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x46\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x73\x65\x74\x20\x53\x54\x44\x20\x61\x63\x63\x65\x70\x74\x61\x6e\x63\x65\x20\x6d\x61\x73\x6b\x20\x31\x20\x28\x43\x41\x4e\x20\x32\x29",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}z4b4cfe7c62=(uint32_T)mxGetPr(z9e605dec30)[(0x1960+1073-0x1d8f)];z9bd3a054dd=(uint32_T)mxGetPr(z9e605dec30)[(0x418+5313-0x18d6)];mode=(0x49+7483-0x1d84);z949a944c9a=(0x49+1237-0x51d);status=z49452fc13f(z3e5b8e05d8,zd042227c40,z0add1d1c25,z949a944c9a,mode,z4b4cfe7c62,z9bd3a054dd);if(!status){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x46\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x73\x65\x74\x20\x53\x54\x44\x20\x61\x63\x63\x65\x70\x74\x61\x6e\x63\x65\x20\x6d\x61\x73\x6b\x20\x32\x20\x28\x43\x41\x4e\x20\x32\x29",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}z4b4cfe7c62=(uint32_T)mxGetPr(z8de06d052a)[(0x152a+1829-0x1c4f)];z9bd3a054dd=(uint32_T)mxGetPr(z8de06d052a)[(0xc46+4558-0x1e13)];mode=(0x8db+287-0x9f9);z949a944c9a=(0x1663+515-0x1866);status=z49452fc13f(z3e5b8e05d8,zd042227c40,z0add1d1c25,z949a944c9a,mode,z4b4cfe7c62,z9bd3a054dd);if(!status){sprintf(zea4cd01646,"\x46\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x73\x65\x74\x20\x45\x58\x54\x20\x61\x63\x63\x65\x70\x74\x61\x6e\x63\x65\x20\x6d\x61\x73\x6b\x20\x31\x20\x28\x43\x41\x4e\x20\x32\x29");
ssSetErrorStatus(S,zea4cd01646);return;}z4b4cfe7c62=(uint32_T)mxGetPr(z8de06d052a)[(0x31d+6607-0x1cea)];z9bd3a054dd=(uint32_T)mxGetPr(z8de06d052a)[(0x1b65+2617-0x259b)];mode=(0xe31+2397-0x178d);z949a944c9a=(0x542+3649-0x1382);status=z49452fc13f(z3e5b8e05d8,zd042227c40,z0add1d1c25,z949a944c9a,mode,z4b4cfe7c62,z9bd3a054dd);if(!status){sprintf(zea4cd01646,"\x46\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x73\x65\x74\x20\x45\x58\x54\x20\x61\x63\x63\x65\x70\x74\x61\x6e\x63\x65\x20\x6d\x61\x73\x6b\x20\x32\x20\x28\x43\x41\x4e\x20\x32\x29");
ssSetErrorStatus(S,zea4cd01646);return;}mode=z05ed543282;status=z2cb48b8ffe(z3e5b8e05d8,zd042227c40,z0add1d1c25,mode);if(!status){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x46\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x65\x20\x52\x58\x20\x71\x75\x65\x75\x65\x20\x28\x43\x41\x4e\x20\x32\x29",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}status=z36e52286a2(z3e5b8e05d8,zd042227c40,z0add1d1c25);if(!status){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x46\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x73\x74\x61\x72\x74\x20\x43\x41\x4e\x20\x6f\x6e\x20\x70\x6f\x72\x74\x20\x32",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE  
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE      
#endif 
}
#ifdef  MATLAB_MEX_FILE    
#include "simulink.c"      
#else
#include "cg_sfun.h"       
#endif
