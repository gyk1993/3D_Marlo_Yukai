/* Copyright 2006-2013 Speedgoat GmbH. */

#define S_FUNCTION_LEVEL (0x4a1+1521-0xa90)
#undef S_FUNCTION_NAME
#define S_FUNCTION_NAME sg_IO601_setuplin_s
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
#define zdf24515981         ((0xa29+2036-0x1219))
#define zbcb3e4d083             ssGetSFcnParam(S, (0x105f+5806-0x270d))
#define zc9f8f200a4           ssGetSFcnParam(S, (0x9ef+7158-0x25e4))
#define z8536354e66               ssGetSFcnParam(S, (0xc95+204-0xd5f))  
#define z702a26a5e9               ssGetSFcnParam(S, (0x637+7720-0x245c))
#define zf1b619edf2                "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x36\x30\x31"
#define z694756a014               (4277)
#define zea87e0ba83               (36912)
#define z29146a1837            ((0x1e83+4673-0x200f))
#define zab7e64468b            (10615)
#define z2e6483d505             ((0xfaa+2129-0x17f9))
#define z4fc736908d       ((0x47b+7534-0x21e9))
#define z6a0da049de        ((0xc41+6235-0x249b))
#define zc5ce4cb81a             ((0x1143+117-0x11b8))
#define z296045870f                    ((0xa70+4425-0x1bb8))
#define zdfcd8b2600               ((0xa41+2988-0x15eb))
#define z63e0d8bf20                  ((0x13a6+350-0x1501))
#define z10dc9d01f3              ((0x537+967-0x8fa))
#define z2536dfa17d             ((0x1901+2335-0x221a))
#define z9ae489463a              ((0x16f8+2867-0x2224))
#define zd11f22184c             ((0x2f5+5652-0x1901))
#define z72ded8c82d       ((0x792+7845-0x262c))
#define z6930c89bc3        ((0x197d+1922-0x20f3))
#define z978445fac6           ((0x7ac+2203-0x103a))
#define z9fbf0f9979            ((0x1e8+3374-0xf08))
#define zd87bbfc3eb          ((0x15f7+2242-0x1eaa))

#define z45900d86e0          ((0x672+3472-0x13d9))
#define z352a70ac71             ((0x17b7+1337-0x1cc6))
#define z6a4a666983              ((0xae7+1432-0x1054))
#define z5cecf4d088             ((0xba5+6517-0x24ee))
#define z0c9cc09a35              ((0x1031+5262-0x2492))
#define z4ecb930c5b ((0xae5+224-0xb97))
#define z05ed543282          ((0x97c+4490-0x1b06))
#define z00aab4ba34       ((0x1758+94-0x17b5))
#define z55873e7fb7    ((0xda5+2820-0x18a7))
static char_T zea4cd01646[(0xbe0+584-0xd28)];uint8_T ptrWritePointer[(0x19fd+1157-0x1e78)];uint8_T ptrReadPointer[(0xdfb+3029-0x19c6)];
#ifndef MATLAB_MEX_FILE
typedef struct{uint8_T zc35c0f42b9;uint8_T za6e45e4916;uint8_T z0375dad321;uint8_T zf42e3db443;uint8_T z263746de21;uint8_T ze51815850a;uint8_T z75ca12472b[(0xec1+4524-0x2065)];}z71e526926d;typedef struct{uint8_T zc4ac91c294;uint8_T count;uint16_T z3bcf72e3b0;uint8_T command;uint8_T data[(0xed4+27-0xea4)];}zd40b3e4dfd;static void zc0d11e95a0(volatile uint32_T*z3e5b8e05d8){uint32_T zc1ac25c1d6;zc1ac25c1d6=z3e5b8e05d8[(0x7c3+1617-0xdff)];z3e5b8e05d8[(0x199+1024-0x584)]=zc1ac25c1d6&~((0x2032+1324-0x255d)<<(0x1974+1319-0x1e99));z3e5b8e05d8[(0xc1+3823-0xf9b)]=zc1ac25c1d6|((0x16dc+1943-0x1e72)<<(0x799+5081-0x1b70));}
#define z770f0bf117 0.050

static void z2521217c2d(volatile uint32_T*z3e5b8e05d8,volatile uint8_T*z27fd94ac66){uint32_T zc1ac25c1d6;
zc1ac25c1d6=z3e5b8e05d8[(0x738+2556-0x111f)];zc1ac25c1d6&=~((0x2527+168-0x25ce)<<(0xde4+2151-0x1640));z3e5b8e05d8[(0x39f+4369-0x149b)]=zc1ac25c1d6;rl32eWaitDouble(z770f0bf117);zc1ac25c1d6|=((0x121+3172-0xd84)<<(0x966+4200-0x19c3));z3e5b8e05d8[(0x133c+1191-0x17ce)]=zc1ac25c1d6;rl32eWaitDouble(z770f0bf117);z27fd94ac66[(0x558+4705-0x17b9)]=(0x1bc1+968-0x1f89);z27fd94ac66[(0x1203+1889-0x1963)]=(0xba1+3204-0x1825);z27fd94ac66[(0x1d1b+1164-0x21a5)]=(0x336+785-0x647);z27fd94ac66[(0x75+6224-0x18c2)]=(0x1153+4395-0x227b);z27fd94ac66[(0x16e8+1812-0x1df8)]=(0x186+9296-0x25d4);z27fd94ac66[(0x1286+3617-0x20a2)]=(0xec+4122-0x1106);z27fd94ac66[(0xa28+2984-0x15ca)]=(0xb5+1168-0x544);z27fd94ac66[(0x1e09+1645-0x2476)]=(0x748+4678-0x198d);rl32eWaitDouble(z770f0bf117);z27fd94ac66[(0x485+4457-0x15ed)]=(0xf5f+5646-0x256d);rl32eWaitDouble(z770f0bf117);zc0d11e95a0(z3e5b8e05d8);}static void z256e1590a0(volatile uint32_T*z3e5b8e05d8,volatile zd40b3e4dfd*zd042227c40){
#ifdef zec3e4ced3e
printf("\x4c\x49\x4e\x20\x63\x6f\x6e\x74\x72\x6f\x6c\x6c\x65\x72\x20\x66\x69\x72\x6d\x77\x61\x72\x65\x2e\x2e\x2e");
#endif
zd042227c40->zc4ac91c294=(0x918+4160-0x1958);zd042227c40->count=(0x9b5+56-0x9ec);zd042227c40->command=zdfcd8b2600;zd042227c40->zc4ac91c294=(0x197c+2090-0x21a5);zc0d11e95a0(z3e5b8e05d8);
#ifdef zec3e4ced3e
while(zd042227c40->zc4ac91c294!=(0x140a+2954-0x1f92))printf("\x2e");printf("\x76\x25\x63\x25\x63\x25\x63\x25\x63" "\n",zd042227c40->data[(0x1040+4645-0x2264)],zd042227c40->data[(0x1fec+1209-0x24a3)],zd042227c40->data[(0x948+2817-0x1446)],zd042227c40->data[(0xc8a+6676-0x269a)]);
#else
while(zd042227c40->zc4ac91c294!=(0x79d+4542-0x1959));
#endif
return;}static uint8_T z0661e37cc5(volatile uint32_T*z3e5b8e05d8,volatile zd40b3e4dfd*zd042227c40){
#ifdef zec3e4ced3e
printf("\x4c\x49\x4e\x20\x63\x6f\x6e\x74\x72\x6f\x6c\x6c\x65\x72\x20\x73\x74\x61\x72\x74\x2e\x2e\x2e");
#endif
zd042227c40->zc4ac91c294=(0x3e4+7245-0x2031);zd042227c40->count=(0xf31+4654-0x215d);zd042227c40->command=z352a70ac71;zd042227c40->zc4ac91c294=(0x1119+4846-0x2406);zc0d11e95a0(z3e5b8e05d8);
#ifdef zec3e4ced3e
while(zd042227c40->zc4ac91c294!=(0x14c3+3629-0x22ee))printf("\x2e");if(zd042227c40->data[(0x216+2700-0xca2)])printf("\x20\x6f\x6b" "\n");else printf("\x20\x66\x61\x69\x6c\x65\x64" "\n");
#else
while(zd042227c40->zc4ac91c294!=(0x5ea+2105-0xe21));
#endif
return zd042227c40->data[(0xa4d+2010-0x1227)];
}static uint8_T z88bdd21b2f(volatile uint32_T*z3e5b8e05d8,volatile zd40b3e4dfd*zd042227c40){
#ifdef zec3e4ced3e
printf("\x4c\x49\x4e\x20\x63\x6f\x6e\x74\x72\x6f\x6c\x6c\x65\x72\x20\x73\x74\x6f\x70\x2e\x2e\x2e");
#endif
zd042227c40->zc4ac91c294=(0x42b+5597-0x1a08);zd042227c40->count=(0x9b3+5490-0x1f23);zd042227c40->command=z6a4a666983;zd042227c40->zc4ac91c294=(0x1d5+6052-0x1978);zc0d11e95a0(z3e5b8e05d8);
#ifdef zec3e4ced3e
while(zd042227c40->zc4ac91c294!=(0xd9f+2677-0x1812))printf("\x2e");if(zd042227c40->data[(0xb19+4036-0x1add)])printf("\x20\x6f\x6b" "\n");else printf("\x20\x66\x61\x69\x6c\x65\x64" "\n");
#else
while(zd042227c40->zc4ac91c294!=(0xb8f+977-0xf5e));
#endif
return zd042227c40->data[(0xf27+3119-0x1b56)];
}static uint8_T zf22ca6f603(volatile uint32_T*z3e5b8e05d8,volatile zd40b3e4dfd*zd042227c40){
#ifdef zec3e4ced3e
printf("\x4c\x49\x4e\x20\x63\x6f\x6e\x74\x72\x6f\x6c\x6c\x65\x72\x20\x72\x65\x73\x65\x74\x2e\x2e\x2e");
#endif
zd042227c40->zc4ac91c294=(0x1ea6+788-0x21ba);zd042227c40->count=(0xe39+1549-0x1444);zd042227c40->command=z5cecf4d088;zd042227c40->zc4ac91c294=(0x1734+3911-0x267a);zc0d11e95a0(z3e5b8e05d8);
#ifdef zec3e4ced3e
while(zd042227c40->zc4ac91c294!=(0x2b3+7746-0x20f3))printf("\x2e");if(zd042227c40->data[(0xe25+369-0xf96)])printf("\x20\x6f\x6b" "\n");else printf("\x20\x66\x61\x69\x6c\x65\x64" "\n");
#else
while(zd042227c40->zc4ac91c294!=(0x1630+683-0x18d9));
#endif
return zd042227c40->data[(0x3b9+8704-0x25b9)];
}static uint8_T z91e6acbe24(volatile uint32_T*z3e5b8e05d8,volatile zd40b3e4dfd*zd042227c40,uint8_T z2480c04862,uint16_T baudrate){
#ifdef zec3e4ced3e
printf("\x4c\x49\x4e\x20\x63\x6f\x6e\x74\x72\x6f\x6c\x6c\x65\x72\x20\x69\x6e\x69\x74\x2e\x2e\x2e");
#endif
zd042227c40->zc4ac91c294=(0x12d4+2027-0x1abf);zd042227c40->count=(0x945+1583-0xf6e);zd042227c40->command=z0c9cc09a35;zd042227c40->data[(0xf51+5905-0x2662)]=(0x43b+2325-0xd50);
zd042227c40->data[(0x14b+8410-0x2224)]=z2480c04862;

zd042227c40->data[(0x48b+6453-0x1dbe)]=(0x824+5171-0x1c57);
zd042227c40->data[(0x314+2937-0xe8a)]=baudrate&(0x149b+2341-0x1cc1);
zd042227c40->data[(0x1d57+1900-0x24bf)]=(baudrate>>(0xcb9+3750-0x1b57))&(0xd94+4032-0x1c55);
zd042227c40->zc4ac91c294=(0x1a44+2898-0x2595);zc0d11e95a0(z3e5b8e05d8);
#ifdef zec3e4ced3e
while(zd042227c40->zc4ac91c294!=(0xf7f+1952-0x171d))printf("\x2e");if(zd042227c40->data[(0x1641+2125-0x1e8e)])printf("\x20\x6f\x6b" "\n");else printf("\x20\x66\x61\x69\x6c\x65\x64" "\n");
#else
while(zd042227c40->zc4ac91c294!=(0x1641+968-0x1a07));
#endif
return zd042227c40->data[(0x179+5483-0x16e4)];
}static uint8_T z2cb48b8ffe(volatile uint32_T*z3e5b8e05d8,volatile zd40b3e4dfd*zd042227c40,uint8_T z0add1d1c25,uint8_T mode){
#ifdef zec3e4ced3e
printf("\x4c\x49\x4e\x20\x63\x6f\x6e\x74\x72\x6f\x6c\x6c\x65\x72\x20\x63\x6f\x6e\x66\x69\x67\x20\x72\x78\x20\x71\x75\x65\x75\x65\x2e\x2e\x2e");
#endif
zd042227c40->zc4ac91c294=(0x13ec+3524-0x21b0);zd042227c40->count=(0xba9+1395-0x1119);zd042227c40->command=z72ded8c82d;zd042227c40->data[(0x3f+3623-0xe66)]=z0add1d1c25;zd042227c40->data[(0xa08+6051-0x21aa)]=mode;zd042227c40->zc4ac91c294=(0x602+5559-0x1bb8);zc0d11e95a0(z3e5b8e05d8);
#ifdef zec3e4ced3e
while(zd042227c40->zc4ac91c294!=(0x3d6+8894-0x2692))printf("\x2e");if(zd042227c40->data[(0x398+683-0x643)])printf("\x20\x6f\x6b" "\n");else printf("\x20\x66\x61\x69\x6c\x65\x64" "\n");
#else
while(zd042227c40->zc4ac91c294!=(0x8bf+2461-0x125a));
#endif
return zd042227c40->data[(0x7b2+5977-0x1f0b)];
}
#endif
static void mdlInitializeSizes(SimStruct*S){int_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x18ef+1358-0x1e3d));ssSetNumDiscStates(S,(0x53c+8171-0x2527));ssSetNumInputPorts(S,(0x1679+1378-0x1bdb));ssSetNumOutputPorts(S,(0xf66+2849-0x1a87));ssSetNumSampleTimes(S,(0xec1+5380-0x23c4));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,(0x1bdd+2422-0x2553));ssSetNumModes(S,(0x842+1209-0xcfb));ssSetNumNonsampledZCs(S,(0xba3+6365-0x2480));for(i=(0xe5c+3439-0x1bcb);i<zdf24515981;i++){ssSetSFcnParamNotTunable(S,i);}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x18b+1958-0x931),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x81+8607-0x2220),0.0);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;uint8_T version[(0xea+1292-0x5f0)];uint16_T baudrate;uint8_T z2480c04862;int8_T status;volatile zd40b3e4dfd*zd042227c40;volatile uint32_T*z3e5b8e05d8;volatile uint8_T*z27fd94ac66;if(mxGetN(z702a26a5e9)==(0xf58+721-0x1228)){z366b2f03bf=(0x17a4+885-0x1b19);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x17b4+1538-0x1db6)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x2087+460-0x2253)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0xba3+5672-0x21ca)];}if(xpcGetPCIDeviceInfo(z694756a014,zea87e0ba83,z29146a1837,zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x53\x45\x54\x55\x50\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}
#ifdef zb482f925e2
else printf("\x53\x45\x54\x55\x50\x20\x6f\x6b" "\n");
#endif  
zeccbadd9b3.VirtAddress[(0x127+6020-0x18ab)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0xac2+6943-0x25e1)],zeccbadd9b3.Length[(0x11aa+1280-0x16aa)],XPC_RT_PG_USERREADWRITE);zeccbadd9b3.VirtAddress[(0x1614+3075-0x2215)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x158+2550-0xb4c)],zeccbadd9b3.Length[(0x1d51+2288-0x263f)],XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x1187+3458-0x1f07)]);ssSetIWorkValue(S,z4fc736908d,zeccbadd9b3.VirtAddress[(0x1f8+2317-0xb05)]);zd042227c40=(volatile zd40b3e4dfd*)(zeccbadd9b3.VirtAddress[(0x9d1+5340-0x1eab)]);z3e5b8e05d8=(volatile uint32_T*)(zeccbadd9b3.VirtAddress[(0x1c0c+1339-0x2147)]);z27fd94ac66=(volatile uint8_T*)(zeccbadd9b3.VirtAddress[(0xa26+7008-0x2584)]);ptrWritePointer[(uint8_T)mxGetPr(zbcb3e4d083)[(0x145c+1401-0x19d5)]-(0x1482+2349-0x1dae)]=(0xc94+3763-0x1b47);ptrReadPointer[(uint8_T)mxGetPr(zbcb3e4d083)[(0x21e5+654-0x2473)]-(0x8e4+439-0xa9a)]=(0x8cf+5708-0x1f1b);
{z2521217c2d(z3e5b8e05d8,z27fd94ac66);z256e1590a0(z3e5b8e05d8,zd042227c40);version[(0x891+2305-0x1192)]=zd042227c40->data[(0xf90+2464-0x192f)];version[(0xa9d+463-0xc6b)]=zd042227c40->data[(0x591+2173-0xe0c)];version[(0x126c+280-0x1382)]=zd042227c40->data[(0x13f6+2194-0x1c85)];version[(0x1f77+1930-0x26fe)]=zd042227c40->data[(0xe68+4348-0x1f60)];version[(0x1e3+1802-0x8e9)]=zd042227c40->data[(0xcdf+1725-0x1397)];version[(0x54c+5203-0x199a)]='\0';if(strncmp(version,"\x34\x2e\x32\x37",(0xe4c+2943-0x19c6))&&strncmp(version,"\x34\x2e\x31\x38",(0xb5b+7085-0x2703))){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x77\x72\x6f\x6e\x67\x20\x66\x69\x72\x6d\x77\x61\x72\x65\x20\x28\x25\x73\x29",zf1b619edf2,version);ssSetErrorStatus(S,zea4cd01646);return;}
status=zf22ca6f603(z3e5b8e05d8,zd042227c40);if(!status){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x46\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x72\x65\x73\x65\x74\x20\x4c\x49\x4e\x20\x63\x6f\x6e\x74\x72\x6f\x6c\x6c\x65\x72",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}
baudrate=(uint16_T)mxGetPr(zc9f8f200a4)[(0x429+475-0x604)];z2480c04862=(uint8_T)mxGetPr(z8536354e66)[(0x1bc7+1508-0x21ab)]-(0x667+7982-0x2594);status=z91e6acbe24(z3e5b8e05d8,zd042227c40,z2480c04862,baudrate);if(!status){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x46\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x69\x6e\x69\x74\x20\x4c\x49\x4e\x20\x63\x6f\x6e\x74\x72\x6f\x6c\x6c\x65\x72",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}
status=z2cb48b8ffe(z3e5b8e05d8,zd042227c40,(0x2e0+1624-0x938),z05ed543282);if(!status){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x46\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x65\x20\x52\x58\x20\x71\x75\x65\x75\x65\x20\x28\x4c\x49\x4e\x29",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}
{
status=z0661e37cc5(z3e5b8e05d8,zd042227c40);if(!status){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x46\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x73\x74\x61\x72\x74\x20\x4c\x49\x4e\x20\x63\x6f\x6e\x74\x72\x6f\x6c\x6c\x65\x72",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE  
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE    
int8_T status;volatile uint32_T*z3e5b8e05d8;volatile zd40b3e4dfd*zd042227c40;uint32_T z5d9c31c2b6;uint32_T z31a846515d;
{z5d9c31c2b6=ssGetIWorkValue(S,z4fc736908d);z31a846515d=ssGetIWorkValue(S,z6a0da049de);z3e5b8e05d8=(void*)z5d9c31c2b6;zd042227c40=(volatile zd40b3e4dfd*)(z31a846515d);status=z88bdd21b2f(z3e5b8e05d8,zd042227c40);if(!status){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x46\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x73\x74\x6f\x70\x20\x4c\x49\x4e\x20\x63\x6f\x6e\x74\x72\x6f\x6c\x6c\x65\x72",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}
#endif 
}
#ifdef  MATLAB_MEX_FILE    
#include "simulink.c"      
#else
#include "cg_sfun.h"       
#endif

