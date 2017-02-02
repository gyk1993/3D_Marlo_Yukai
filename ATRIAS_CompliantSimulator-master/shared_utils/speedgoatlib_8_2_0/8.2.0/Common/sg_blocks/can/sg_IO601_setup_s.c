/* Copyright 2006-2013 Speedgoat GmbH. */
#define DEBUG (0x138+6870-0x1c0e)
#define         S_FUNCTION_LEVEL        (0x18ec+1831-0x2011)
#undef          S_FUNCTION_NAME
#define         S_FUNCTION_NAME         sg_IO601_setup_s
#include        <stddef.h>
#include        <stdlib.h>
#ifndef         MATLAB_MEX_FILE
#endif
#include        "tmwtypes.h"
#include        "simstruc.h"
#ifdef          MATLAB_MEX_FILE
#include        "mex.h"
#endif
#ifndef         MATLAB_MEX_FILE
#include        <windows.h>
#include        "io_xpcimport.h"
#include        "pci_xpcimport.h"
#include        "time_xpcimport.h"
#include        "ioext_xpcimport.h"
#include        "util_xpcimport.h"
#endif
#define         zdf24515981              ((0xb81+4782-0x1e1f))
#define         zbcb3e4d083                  ssGetSFcnParam(S,(0xae1+2783-0x15c0))
#define         z58c4256b9b             ssGetSFcnParam(S,(0x1de2+1769-0x24ca))
#define         za457bf2dc4                ssGetSFcnParam(S,(0x789+7538-0x24f9))
#define         z13d4592f13      ssGetSFcnParam(S,(0xdad+5353-0x2293))
#define         z193682178f                    ssGetSFcnParam(S,(0xca6+3576-0x1a9a))
#define         zd82eddfd5f              ssGetSFcnParam(S,(0x1822+1834-0x1f47))
#define         z0b1c7e6895              ssGetSFcnParam(S,(0x9e7+5530-0x1f7b))
#define         z69ea1c654a             ssGetSFcnParam(S,(0x1723+2902-0x2272))
#define         zdd4ab756a7                ssGetSFcnParam(S,(0x37+5515-0x15ba))
#define         zc91b5ad104      ssGetSFcnParam(S,(0x109a+4095-0x2090))
#define         z887063f6e9                    ssGetSFcnParam(S,(0x866+6940-0x2378))
#define         z101093622d              ssGetSFcnParam(S,(0x20ac+1442-0x2643))
#define         z8439a88983              ssGetSFcnParam(S,(0x5b3+2604-0xfd3))
#define         zd39abcef8f                ssGetSFcnParam(S,(0x1439+871-0x1793))
#define         zdfab922aba                ssGetSFcnParam(S,(0x116c+1107-0x15b1))
#define         z702a26a5e9                    ssGetSFcnParam(S,(0xdb3+3039-0x1983))
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x36\x30\x31"
#define z694756a014 4277
#define zea87e0ba83 36912
#define z29146a1837 (0x22dc+2567-0x1c2e)
#define zab7e64468b 10615
#define         z2e6483d505                  ((0x1e25+831-0x2162))
#define         z57e55a08c5            ((0x96f+4713-0x1bd8))
#define         z84eb1db314            ((0xb02+2097-0x1332))
#define         zc5ce4cb81a                  ((0x9c0+5240-0x1e38))

#define         z5730f2fda1               (0x89b+4405-0x19d0)
#define         z530aa6a16c               (0x16b5+1912-0x1e2d)
#define         z5762d73f37           0x00000000L
#define         z1f5a5fd00d           0x00000000L
#define         z8c1240ba23               (0x1b54+2448-0x24e4)
#define         z158bc3bca3               (0x1c4+9514-0x26ee)
#define         z5770d0d131           0x00000000L
#define         za83b97f58a           0x00000000L
#ifndef  zb84e0c3c3b
#define  zb84e0c3c3b(zc1d61b7d63)  *( (uint8_T *) &zc1d61b7d63)
#endif
#ifndef  z15e663b423
#define  z15e663b423(zc1d61b7d63)  *(((uint8_T *) &zc1d61b7d63) + (0x932+3676-0x178d))
#endif
#ifndef  zfca7eb6338
#define  zfca7eb6338(zc1d61b7d63)  *( (uint16_T *) &zc1d61b7d63)
#endif
#ifndef  z3607971cd6
#define  z3607971cd6(zc1d61b7d63)  *(((uint16_T *) &zc1d61b7d63) + (0xbbc+6841-0x2674))
#endif
#ifndef z0056adfa94
#define z0056adfa94(zc1d61b7d63)       { uint8_T z7be9105675; z7be9105675 = z15e663b423(zc1d61b7d63); z15e663b423(zc1d61b7d63) = (uint8_T) zc1d61b7d63; zb84e0c3c3b(zc1d61b7d63) = z7be9105675; }
#endif
#ifndef z8444fc96d2
#define z8444fc96d2(zc1d61b7d63)       { uint16_T z7be9105675; z7be9105675 = z3607971cd6(zc1d61b7d63); z3607971cd6(zc1d61b7d63) = (uint16_T) zc1d61b7d63; zfca7eb6338(zc1d61b7d63) = z7be9105675; }
#endif
static char_T zea4cd01646[(0x805+4788-0x19b9)];
#ifndef MATLAB_MEX_FILE
uint8_T z199556e987[(0x279+7301-0x1ed6)];static uint32_T zb2ab7dbb1a(uint32_T value){value=value<<(0x142a+820-0x1749);z0056adfa94(z3607971cd6(value));z0056adfa94(zfca7eb6338(value));z8444fc96d2(value);return(value);}static uint32_T zdd53c2bd21(uint32_T value){value=value<<(0x300+8948-0x25f1);z0056adfa94(z3607971cd6(value));z0056adfa94(zfca7eb6338(value));z8444fc96d2(value);return(value);}static void z4c4950f631(uint8_T*dest,volatile uint8_T*z0f2d183aba,uint32_T n){uint32_T i=(0xc3+4786-0x1375);while(i++<n){*dest++=*z0f2d183aba++;}}static uint8_T zf344ecfecb(volatile uint32_T*z3e5b8e05d8,volatile uint8_T*z27fd94ac66,uint8_T zec3c5099c1,uint8_T z5e97dc60db,uint8_T z9b0743fe91,uint8_T mode){uint32_T zc1ac25c1d6,i;z27fd94ac66[(0x140+9155-0x2503)]=(0xc46+3559-0x1a2d);z27fd94ac66[(0xcdb+5229-0x2147)]=(0x2678+72-0x26bb);z27fd94ac66[(0x1363+1647-0x19d0)]=(0xfe7+4830-0x22c5);z27fd94ac66[(0x1bfd+1786-0x22f4)]=(0xfa2+2548-0x1996);z27fd94ac66[(0xbc0+3663-0x1a0b)]=(0x18c6+1493-0x1e97);z27fd94ac66[(0xd03+2076-0x151a)]=zec3c5099c1;z27fd94ac66[(0x78f+1442-0xd2b)]=z5e97dc60db;z27fd94ac66[(0x1977+2191-0x21ff)]=z9b0743fe91;z27fd94ac66[(0x7ba+5266-0x1c44)]=mode;
z27fd94ac66[(0x5bb+4546-0x177d)]=(0x11c0+4420-0x2303);
zc1ac25c1d6=z3e5b8e05d8[(0x1f30+402-0x20ad)];z3e5b8e05d8[(0x407+730-0x6cc)]=zc1ac25c1d6&~((0x166+8904-0x242d)<<(0x966+4201-0x19cd));z3e5b8e05d8[(0x1082+4735-0x22ec)]=zc1ac25c1d6|((0x1303+483-0x14e5)<<(0x494+409-0x62b));i=(0x7d4+3741-0x1671);while(z27fd94ac66[(0x1140+2726-0x1be6)]==(0x1861+3450-0x25da)){i++;}

return(0x16ba+2181-0x1f3f);}static uint8_T z36e52286a2(volatile uint32_T*z3e5b8e05d8,volatile uint8_T*z27fd94ac66,uint8_T zec3c5099c1){

uint32_T zc1ac25c1d6,i;z27fd94ac66[(0xb81+5398-0x2097)]=(0x4c7+913-0x858);z27fd94ac66[(0x1536+2974-0x20d3)]=(0xbf2+3890-0x1b22);z27fd94ac66[(0x404+7632-0x21d2)]=(0x2132+1276-0x262e);z27fd94ac66[(0x1639+3080-0x223e)]=(0x15f2+1545-0x1bfb);z27fd94ac66[(0xcc5+200-0xd89)]=(0xc8+4283-0x117d);z27fd94ac66[(0xf09+3390-0x1c42)]=zec3c5099c1;
z27fd94ac66[(0x143+2842-0xc5d)]=(0x286+8591-0x2414);
zc1ac25c1d6=z3e5b8e05d8[(0x2361+786-0x265e)];z3e5b8e05d8[(0x126+2891-0xc5c)]=zc1ac25c1d6&~((0x1964+3352-0x267b)<<(0xcc2+5349-0x21a5));z3e5b8e05d8[(0xdf3+1752-0x14b6)]=zc1ac25c1d6|((0x4d4+6575-0x1e82)<<(0x17f9+2373-0x213c));i=(0x715+7307-0x23a0);while(z27fd94ac66[(0x1483+234-0x156d)]==(0x15a0+2687-0x201e)){i++;}

return(0x558+2778-0x1032);}static uint8_T z2cb48b8ffe(volatile uint32_T*z3e5b8e05d8,volatile uint8_T*z27fd94ac66,uint8_T zec3c5099c1,uint8_T mode){uint32_T zc1ac25c1d6,i;z27fd94ac66[(0x1a08+2403-0x236b)]=(0x1ffb+1256-0x24e3);z27fd94ac66[(0x1ae3+2564-0x24e6)]=(0xc6f+1695-0x130b);z27fd94ac66[(0x1ae1+1665-0x2160)]=(0xa4b+4091-0x1a46);z27fd94ac66[(0xeb5+1952-0x1652)]=(0xe4c+5498-0x23c6);z27fd94ac66[(0x7f+605-0x2d8)]=(0xafa+2998-0x16a5);z27fd94ac66[(0x622+189-0x6da)]=zec3c5099c1;z27fd94ac66[(0x10d2+5036-0x2478)]=mode;
z27fd94ac66[(0x12b2+1885-0x1a0f)]=(0x165+7226-0x1d9e);
zc1ac25c1d6=z3e5b8e05d8[(0x132b+4748-0x25a2)];z3e5b8e05d8[(0xe29+1092-0x1258)]=zc1ac25c1d6&~((0x637+1995-0xe01)<<(0x11c1+2789-0x1ca4));z3e5b8e05d8[(0x560+3748-0x13ef)]=zc1ac25c1d6|((0x5ac+1006-0x999)<<(0x26f+5137-0x167e));i=(0x50f+1418-0xa99);while(z27fd94ac66[(0x500+6926-0x200e)]==(0x16c5+3724-0x2550)){i++;}

return(0x3d3+2865-0xf04);}static uint8_T z3d252d79db(volatile uint32_T*z3e5b8e05d8,volatile uint8_T*z27fd94ac66,uint8_T zec3c5099c1){uint32_T zc1ac25c1d6,i;z27fd94ac66[(0x11c1+2249-0x1a8a)]=(0x10f6+929-0x1497);z27fd94ac66[(0x1516+2713-0x1fae)]=(0x1fd4+1770-0x26bc);z27fd94ac66[(0x1f55+37-0x1f78)]=(0x1807+2366-0x2145);z27fd94ac66[(0xa76+5138-0x1e85)]=(0x1a7+528-0x3b7);z27fd94ac66[(0x7ca+946-0xb78)]=(0x365+6257-0x1bcf);z27fd94ac66[(0xe68+5617-0x2454)]=zec3c5099c1;
z27fd94ac66[(0x197c+2127-0x21cb)]=(0x1e6b+318-0x1fa8);
zc1ac25c1d6=z3e5b8e05d8[(0xd46+2790-0x1817)];z3e5b8e05d8[(0x1570+1729-0x1c1c)]=zc1ac25c1d6&~((0x6a4+6558-0x2041)<<(0x157d+1569-0x1b9c));z3e5b8e05d8[(0x1a6b+1208-0x1f0e)]=zc1ac25c1d6|((0x36a+2505-0xd32)<<(0x10da+65-0x1119));i=(0x11+5907-0x1724);while(z27fd94ac66[(0x1232+954-0x15ec)]==(0x130a+1321-0x1832)){i++;}

return(0x128+6165-0x193d);}static uint8_T ze4f231f5de(volatile uint32_T*z3e5b8e05d8,volatile uint8_T*z27fd94ac66){uint16_T status;uint32_T i;
for(i=(0x1468+3237-0x210d);i<(0x4f8+5775-0x1b81);i++){status=z27fd94ac66[(0x1465+5804-0x1b21)+i*(0x1100+678-0x13a4)];status|=z27fd94ac66[4080+i*(0xb2f+1462-0x10e3)+(0xf62+4601-0x215a)]<<(0xc0a+370-0xd74);
}
return(0x1891+2118-0x20d7);}
#endif
static void mdlInitializeSizes(SimStruct*S){int_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xf78+2392-0x18d0));ssSetNumDiscStates(S,(0x1619+327-0x1760));ssSetNumInputPorts(S,(0x6f8+1754-0xdd2));ssSetNumOutputPorts(S,(0x467+47-0x496));ssSetNumSampleTimes(S,(0x672+5483-0x1bdc));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,(0x1344+168-0x13ec));ssSetNumModes(S,(0xbd+6130-0x18af));ssSetNumNonsampledZCs(S,(0x143a+2270-0x1d18));for(i=(0x89+5655-0x16a0);i<zdf24515981;i++){ssSetSFcnParamNotTunable(S,i);}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x836+5204-0x1c8a),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x169+312-0x2a1),0.0);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zef529fae4a,*zdfcb1da404;void*ze2370ae9b9,*zf2db5722bf;volatile uint32_T*z3e5b8e05d8;volatile uint8_T*z27fd94ac66;volatile uint32_T*z706da0e1e5;uint_T i,z97d855d69f,z2b9653a7df,m;int_T z26dbd73a5e;uint8_T name[(0x215+6004-0x1909)];uint8_T version[(0x1837+2131-0x207a)];uint32_T zc1ac25c1d6,z7be9105675;char z09e5c25c98[(0xddd+4561-0x1faa)];uint8_T zb825bf1c08;uint8_T message[(0x1115+3314-0x1df3)];uint32_T za6dad42b7e[(0x412+3025-0xfde)];uint8_T z5e97dc60db,z9b0743fe91;int_T z0add1d1c25;uint32_T ident;int_T type;int_T z38357fbbbb;uint8_T zc369e1e9c6,zddcad00412,ze7f7c7c9a3,ze3ffc04544,z4ed2387f30;zc369e1e9c6=(uint8_T)mxGetPr(zbcb3e4d083)[(0x365+1594-0x99f)]-(0x1ddd+1536-0x23dc);zddcad00412=(uint8_T)mxGetPr(z58c4256b9b)[(0x1ab8+584-0x1d00)];ze7f7c7c9a3=(uint8_T)mxGetPr(z69ea1c654a)[(0xbcf+2556-0x15cb)];ze3ffc04544=(uint8_T)mxGetPr(za457bf2dc4)[(0x191d+1393-0x1e8e)]-(0x2068+187-0x2122);z4ed2387f30=(uint8_T)mxGetPr(zdd4ab756a7)[(0x583+802-0x8a5)]-(0x16fd+1236-0x1bd0);if((int_T)mxGetPr(z702a26a5e9)[(0xd5+4674-0x1317)]<(0x3c0+648-0x648)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x25a+2612-0xc8d)){z366b2f03bf=(0x1136+906-0x14c0);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x373+8523-0x24be)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x6f3+5816-0x1dab)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xa83+5324-0x1f4e)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x203+4034-0x10c6))|((z366b2f03bf&(0x10a+8912-0x22db))<<(0x18a2+1525-0x1e8f)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zef529fae4a=(void*)zeccbadd9b3.BaseAddress[(0xfff+5708-0x264b)];ze2370ae9b9=rl32eGetDevicePtr(zef529fae4a,(0x1120+1797-0x16fd),RT_PG_USERREADWRITE);z3e5b8e05d8=(volatile uint32_T*)ze2370ae9b9;
zdfcb1da404=(void*)zeccbadd9b3.BaseAddress[(0x11c6+356-0x1328)];zf2db5722bf=rl32eGetDevicePtr(zdfcb1da404,16384,RT_PG_USERREADWRITE);z27fd94ac66=(volatile uint8_T*)zf2db5722bf;z706da0e1e5=(volatile uint32_T*)zf2db5722bf;


zc1ac25c1d6=z3e5b8e05d8[(0xd2f+1675-0x13a5)];
zc1ac25c1d6&=~((0xb39+319-0xc77)<<(0x142a+2727-0x1ec6));z3e5b8e05d8[(0x1533+2061-0x1d2b)]=zc1ac25c1d6;
rl32eWaitDouble(0.050);zc1ac25c1d6=z3e5b8e05d8[(0x1b81+16-0x1b7c)];
zc1ac25c1d6|=((0x1416+2999-0x1fcc)<<(0xcb1+4106-0x1cb0));z3e5b8e05d8[(0x857+4564-0x1a16)]=zc1ac25c1d6;zc1ac25c1d6=z3e5b8e05d8[(0x131c+1315-0x182a)];
rl32eWaitDouble(0.050);
memcpy(name,(void*)(z27fd94ac66+(0x15df+3097-0x21e8)),(0x2434+87-0x244b));name[(0x132a+103-0x1351)]='\0';

memcpy(version,(void*)(z27fd94ac66+(0x4a7+8028-0x23d3)),(0x5f0+4364-0x16f3));version[(0xa2a+5842-0x20f3)]='\0';
z27fd94ac66[(0x561+1823-0xc80)]=(0x1039+2851-0x1b5c);z27fd94ac66[(0x25f+635-0x4d9)]=(0x1b75+804-0x1e99);z27fd94ac66[(0xaf4+3179-0x175d)]=(0x126f+3604-0x2083);z27fd94ac66[(0x4e6+3698-0x1355)]=(0x211+2810-0xd09);z27fd94ac66[(0x1101+143-0x118c)]=(0x369+566-0x598);z27fd94ac66[(0x1512+1998-0x1cdb)]=(0x8e7+181-0x99c);z27fd94ac66[(0x6b1+8095-0x2650)]=(0x20d+5737-0x1875);rl32eWaitDouble(0.050);z27fd94ac66[(0xb89+5246-0x2006)]=(0x1c49+115-0x1cbc);rl32eWaitDouble(0.050);z4c4950f631(z09e5c25c98,z27fd94ac66+(0x1cbd+2278-0x2589),(0x1113+5310-0x25ce));if(strncmp(z09e5c25c98,"\x42\x43\x49",(0x15d6+2802-0x20c5))){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x46\x4c\x41\x53\x48\x20\x63\x6f\x6e\x74\x61\x69\x6e\x73\x20\x77\x72\x6f\x6e\x67\x20\x66\x69\x72\x6d\x77\x61\x72\x65\x20\x76\x65\x72\x73\x69\x6f\x6e",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}
z27fd94ac66[(0xabf+5896-0x21c7)]=(0x1989+1644-0x1ff5);z27fd94ac66[(0xa7+8764-0x22e2)]=(0xef0+4096-0x1ef0);z27fd94ac66[(0xf5b+1544-0x1561)]=(0x1e9+3244-0xe95);z27fd94ac66[(0x101b+5860-0x26fc)]=(0xc78+5336-0x214d);z27fd94ac66[(0x74b+7002-0x22a1)]=(0x19e7+1974-0x219b);z27fd94ac66[(0x351+5355-0x1837)]=(0x161d+1149-0x1a9a);z27fd94ac66[(0x1784+1084-0x1bba)]=(0xae4+6011-0x225e);z27fd94ac66[(0xddc+3295-0x1abb)]=(0x21e9+558-0x2416);rl32eWaitDouble(0.050);z27fd94ac66[(0x1d7d+2072-0x2594)]=(0x8b0+3568-0x16a0);rl32eWaitDouble(0.050);

z5e97dc60db=(((uint8_T)mxGetPr(z13d4592f13)[(0x17f4+3067-0x23ee)]-(0x1135+4-0x1138))<<(0x174f+46-0x1777))|((uint8_T)mxGetPr(z13d4592f13)[(0x7d6+6081-0x1f97)]-(0x14cc+242-0x15bd));z9b0743fe91=(((uint8_T)mxGetPr(z13d4592f13)[(0x257+7982-0x2182)]-(0x1db+8376-0x2292))<<(0x42a+619-0x691))|((uint8_T)mxGetPr(z13d4592f13)[(0x1472+1573-0x1a95)]-(0x6cc+5516-0x1c57));
if(zddcad00412){printf("\x20\x20\x20\x20\x20\x20\x20\x20\x69\x6e\x69\x74\x69\x61\x6c\x69\x7a\x65\x20\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x36\x30\x31\x20\x6d\x6f\x64\x75\x6c\x65\x20\x25\x64\x20\x43\x41\x4e\x20\x31" "\n",zc369e1e9c6+(0xa37+4329-0x1b1f));zb825bf1c08=zf344ecfecb(z3e5b8e05d8,z27fd94ac66,(0x157b+544-0x179b),z5e97dc60db,z9b0743fe91,ze3ffc04544);

}z199556e987[(0x2360+636-0x25dc)+zc369e1e9c6*(0x17b+885-0x4ec)]=(0xbff+2356-0x1533);z199556e987[(0x1f14+1117-0x236f)+zc369e1e9c6*(0xce9+5212-0x2141)]=(0x8cd+6408-0x21d5);z5e97dc60db=(((uint8_T)mxGetPr(zc91b5ad104)[(0x10bf+381-0x123b)]-(0x52f+2923-0x1099))<<(0x61d+1313-0xb38))|((uint8_T)mxGetPr(zc91b5ad104)[(0x19e6+1990-0x21ac)]-(0x1090+3788-0x1f5b));z9b0743fe91=(((uint8_T)mxGetPr(zc91b5ad104)[(0xdb9+1653-0x142b)]-(0x1362+4154-0x239b))<<(0x89+7390-0x1d63))|((uint8_T)mxGetPr(zc91b5ad104)[(0x9af+6450-0x22df)]-(0x363+1261-0x84f));
if(ze7f7c7c9a3){printf("\x20\x20\x20\x20\x20\x20\x20\x20\x69\x6e\x69\x74\x69\x61\x6c\x69\x7a\x65\x20\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x36\x30\x31\x20\x6d\x6f\x64\x75\x6c\x65\x20\x25\x64\x20\x43\x41\x4e\x20\x32" "\n",zc369e1e9c6+(0x1a11+428-0x1bbc));zb825bf1c08=zf344ecfecb(z3e5b8e05d8,z27fd94ac66,(0x1581+1016-0x1978),z5e97dc60db,z9b0743fe91,z4ed2387f30);

}z199556e987[(0xf56+4023-0x1f0c)+zc369e1e9c6*(0xb56+6486-0x24a8)]=(0x1dcc+280-0x1ee4);z199556e987[(0x10f1+5103-0x24dd)+zc369e1e9c6*(0x1d06+1815-0x2419)]=(0x1142+3719-0x1fc9);if(zddcad00412){zb825bf1c08=z2cb48b8ffe(z3e5b8e05d8,z27fd94ac66,(0x325+100-0x389),(0x622+6081-0x1de3));

}if(ze7f7c7c9a3){zb825bf1c08=z2cb48b8ffe(z3e5b8e05d8,z27fd94ac66,(0x2523+433-0x26d3),(0x396+1526-0x98c));

}
if(zddcad00412){zb825bf1c08=z36e52286a2(z3e5b8e05d8,z27fd94ac66,(0x7ed+6883-0x22d0));

}if(ze7f7c7c9a3){zb825bf1c08=z36e52286a2(z3e5b8e05d8,z27fd94ac66,(0xc52+975-0x1020));

}ssSetIWorkValue(S,z57e55a08c5,(uint32_T)z3e5b8e05d8);ssSetIWorkValue(S,z84eb1db314,(uint32_T)z27fd94ac66);
{int_T start;uint8_T data[(0x56f+8612-0x270b)];if((int_T)mxGetPr(zd39abcef8f)[(0x209c+804-0x23c0)]){z97d855d69f=z199556e987[(0xd1d+1848-0x1455)+zc369e1e9c6*(0x34+6279-0x18b7)];z2b9653a7df=z199556e987[(0x1045+4167-0x208b)+zc369e1e9c6*(0x123f+3870-0x2159)];start=(0x140c+113-0x147c);

m=(uint_T)mxGetPr(zd39abcef8f)[(0x1a2b+812-0x1d57)];
for(i=(0xb28+5677-0x2155);i<m;i++){
for(z26dbd73a5e=(0x11cc+1650-0x183e);z26dbd73a5e<(int_T)mxGetPr(zd39abcef8f)[start+(0x6da+2206-0xf75)];z26dbd73a5e++){data[z26dbd73a5e]=(uint8_T)mxGetPr(zd39abcef8f)[start+(0x1ca4+547-0x1ec3)+z26dbd73a5e];
}

z0add1d1c25=(int_T)mxGetPr(zd39abcef8f)[start];ident=(uint32_T)mxGetPr(zd39abcef8f)[start+(0x13dc+1846-0x1b10)];type=(int_T)mxGetPr(zd39abcef8f)[start+(0x1835+1301-0x1d49)];z38357fbbbb=(int_T)mxGetPr(zd39abcef8f)[start+(0x1b19+1528-0x210e)];
message[(0x216+6893-0x1d03)]=(0xba3+1465-0x115b);message[(0x15ef+1408-0x1b6e)]=(0x1c00+581-0x1e33);message[(0xe6+3849-0xfed)]=(0x1b7b+1370-0x20d5);message[(0x161f+1604-0x1c60)]=(0x2276+81-0x22c7);message[(0x13b+6223-0x1986)]=(0x1564+2039-0x1d5b);message[(0x10d8+4095-0x20d2)]=(0xc66+3040-0x1846);message[(0x115d+61-0x1194)]=(0xd70+1353-0x12b9);if(type==(0x427+5009-0x17b8)){
message[(0x1350+1770-0x1a33)]=z38357fbbbb;z7be9105675=zb2ab7dbb1a(ident);message[(0x911+1158-0xd8f)]=z7be9105675&(0x14f2+699-0x16ae);message[(0x14d+3-0x147)]=(z7be9105675>>(0x252+3835-0x1145))&(0x1af7+2920-0x2560);for(z26dbd73a5e=(0x22ed+658-0x257f);z26dbd73a5e<z38357fbbbb;z26dbd73a5e++){message[(0x15e4+1369-0x1b33)+z26dbd73a5e]=data[z26dbd73a5e];}}else{
message[(0x26+8587-0x21aa)]=(0x15d5+1091-0x1998)|z38357fbbbb;z7be9105675=zdd53c2bd21(ident);message[(0x1065+1681-0x16ee)]=z7be9105675&(0x306+9015-0x253e);message[(0x927+3157-0x1573)]=(z7be9105675>>(0x196b+1684-0x1ff7))&(0x6aa+4113-0x15bc);message[(0x47+8660-0x2211)]=(z7be9105675>>(0x420+6713-0x1e49))&(0xb24+4568-0x1bfd);message[(0x116+1696-0x7ab)]=(z7be9105675>>(0x1216+1667-0x1881))&(0x941+7008-0x23a2);for(z26dbd73a5e=(0x179+7867-0x2034);z26dbd73a5e<z38357fbbbb;z26dbd73a5e++){message[(0x17cb+3821-0x26ac)+z26dbd73a5e]=data[z26dbd73a5e];}}memcpy(za6dad42b7e,message,(0x2ec+6728-0x1d20));if(z0add1d1c25==(0x963+2945-0x14e3)){for(z26dbd73a5e=(0x401+7606-0x21b7);z26dbd73a5e<(0x2a4+5612-0x188b);z26dbd73a5e++){z706da0e1e5[(0xf17+5751-0x257a)+z97d855d69f*(0x4b1+3170-0x110e)+z26dbd73a5e]=za6dad42b7e[z26dbd73a5e];
}z97d855d69f++;if(z97d855d69f==(0x1de6+1736-0x247c))z97d855d69f=(0x1620+3753-0x24c9);}else{for(z26dbd73a5e=(0xbd5+428-0xd81);z26dbd73a5e<(0x1216+4222-0x228f);z26dbd73a5e++){z706da0e1e5[(0xa73+122-0x9df)+z2b9653a7df*(0x18eb+1026-0x1ce8)+z26dbd73a5e]=za6dad42b7e[z26dbd73a5e];
}z2b9653a7df++;if(z2b9653a7df==(0x872+3876-0x1764))z2b9653a7df=(0x96b+5099-0x1d56);}

zc1ac25c1d6=z3e5b8e05d8[(0x4cf+1994-0xc84)];z3e5b8e05d8[(0xacf+1290-0xfc4)]=zc1ac25c1d6&~((0x198a+3272-0x2651)<<(0x104+3983-0x1091));z3e5b8e05d8[(0x530+3413-0x1270)]=zc1ac25c1d6|((0x2a9+8415-0x2387)<<(0x149c+1264-0x198a));

rl32eWaitDouble(mxGetPr(zd39abcef8f)[start+(0xf96+2136-0x17e2)]);start+=(0x15a2+192-0x1655);}
z199556e987[(0x14c+4565-0x1321)+zc369e1e9c6*(0xd39+2959-0x18c4)]=z97d855d69f;z199556e987[(0x12e6+785-0x15f6)+zc369e1e9c6*(0x1903+1534-0x1efd)]=z2b9653a7df;}}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE      
uint32_T z5d9c31c2b6=ssGetIWorkValue(S,z57e55a08c5);uint32_T z31a846515d=ssGetIWorkValue(S,z84eb1db314);volatile uint32_T*z3e5b8e05d8;volatile uint8_T*z27fd94ac66;volatile uint32_T*z706da0e1e5;uint8_T zb825bf1c08;uint8_T zddcad00412,ze7f7c7c9a3;uint_T i,z97d855d69f,z2b9653a7df,m;int_T z26dbd73a5e;uint8_T zc369e1e9c6;uint8_T message[(0x1e0f+465-0x1fcc)];uint32_T za6dad42b7e[(0x8f0+7561-0x2674)];uint32_T zc1ac25c1d6,z7be9105675;int_T z0add1d1c25;uint32_T ident;int_T type;int_T z38357fbbbb;zc369e1e9c6=(uint8_T)mxGetPr(zbcb3e4d083)[(0x191b+2914-0x247d)]-(0x427+172-0x4d2);zddcad00412=(uint8_T)mxGetPr(z58c4256b9b)[(0x1983+653-0x1c10)];ze7f7c7c9a3=(uint8_T)mxGetPr(z69ea1c654a)[(0xcb6+5064-0x207e)];z3e5b8e05d8=(void*)z5d9c31c2b6;z27fd94ac66=(void*)z31a846515d;z706da0e1e5=(void*)z31a846515d;
{int_T start;uint8_T data[(0x185b+3198-0x24d1)];if((int_T)mxGetPr(zdfab922aba)[(0x1506+1503-0x1ae5)]){z97d855d69f=z199556e987[(0x48d+5067-0x1858)+zc369e1e9c6*(0xae0+6712-0x2514)];z2b9653a7df=z199556e987[(0xd1b+3037-0x18f7)+zc369e1e9c6*(0x1a08+3134-0x2642)];start=(0x174f+3993-0x26e7);m=(uint_T)mxGetPr(zdfab922aba)[(0x95c+3987-0x18ef)];
for(i=(0x768+1948-0xf04);i<m;i++){for(z26dbd73a5e=(0x12c0+4950-0x2616);z26dbd73a5e<(int_T)mxGetPr(zdfab922aba)[start+(0x700+7178-0x2307)];z26dbd73a5e++){data[z26dbd73a5e]=(uint8_T)mxGetPr(zdfab922aba)[start+(0x2a3+814-0x5cd)+z26dbd73a5e];}
z0add1d1c25=(int_T)mxGetPr(zdfab922aba)[start];ident=(uint32_T)mxGetPr(zdfab922aba)[start+(0x15cb+3775-0x2488)];type=(int_T)mxGetPr(zdfab922aba)[start+(0x95+3361-0xdb5)];z38357fbbbb=(int_T)mxGetPr(zdfab922aba)[start+(0x1a74+1492-0x2045)];
message[(0x421+1535-0xa20)]=(0x1c41+789-0x1f55);message[(0x512+3115-0x113c)]=(0xb81+4521-0x1d18);message[(0x1e40+377-0x1fb7)]=(0x847+7610-0x2601);message[(0x1ba+1515-0x7a2)]=(0x885+6834-0x2337);message[(0xd48+4629-0x1f59)]=(0x1a99+1473-0x205a);message[(0xb35+1845-0x1265)]=(0x1ac6+2770-0x2598);message[(0x108c+696-0x133e)]=(0x1aaa+2494-0x2468);if(type==(0x169+6485-0x1abe)){
message[(0x21c+8015-0x2164)]=z38357fbbbb;z7be9105675=zb2ab7dbb1a(ident);message[(0x758+4020-0x1704)]=z7be9105675&(0x6cb+7049-0x2155);message[(0x62+6599-0x1a20)]=(z7be9105675>>(0x139+1923-0x8b4))&(0xc65+1151-0xfe5);for(z26dbd73a5e=(0x19fa+2784-0x24da);z26dbd73a5e<z38357fbbbb;z26dbd73a5e++){message[(0x1981+3161-0x25d0)+z26dbd73a5e]=data[z26dbd73a5e];}}else{
message[(0x1c16+967-0x1fd6)]=(0xb61+594-0xd33)|z38357fbbbb;z7be9105675=zdd53c2bd21(ident);message[(0x12fd+2555-0x1cf0)]=z7be9105675&(0x1376+3292-0x1f53);message[(0xb2c+5275-0x1fbe)]=(z7be9105675>>(0x12ff+331-0x1442))&(0x2322+1047-0x263a);message[(0x1bef+1814-0x22fb)]=(z7be9105675>>(0x3a6+4151-0x13cd))&(0x236a+908-0x25f7);message[(0x110f+4057-0x20dd)]=(z7be9105675>>(0x6bb+6171-0x1ebe))&(0x1fac+1227-0x2378);for(z26dbd73a5e=(0x11eb+4837-0x24d0);z26dbd73a5e<z38357fbbbb;z26dbd73a5e++){message[(0x8b4+7462-0x25ce)+z26dbd73a5e]=data[z26dbd73a5e];}}memcpy(za6dad42b7e,message,(0x615+1430-0xb97));if(z0add1d1c25==(0x51f+5863-0x1c05)){for(z26dbd73a5e=(0x1a9f+722-0x1d71);z26dbd73a5e<(0xed3+3613-0x1ceb);z26dbd73a5e++){z706da0e1e5[(0x1541+1498-0x1b07)+z97d855d69f*(0x7a5+5204-0x1bf4)+z26dbd73a5e]=za6dad42b7e[z26dbd73a5e];}z97d855d69f++;if(z97d855d69f==(0x467+7915-0x2320))z97d855d69f=(0x3b1+6291-0x1c44);}else{for(z26dbd73a5e=(0x1c71+2692-0x26f5);z26dbd73a5e<(0xa2a+6064-0x21d5);z26dbd73a5e++){z706da0e1e5[(0x2155+1336-0x257f)+z2b9653a7df*(0x250f+90-0x2564)+z26dbd73a5e]=za6dad42b7e[z26dbd73a5e];}z2b9653a7df++;if(z2b9653a7df==(0xf7d+6032-0x26db))z2b9653a7df=(0xc02+2914-0x1764);}
zc1ac25c1d6=z3e5b8e05d8[(0x1c+356-0x16b)];z3e5b8e05d8[(0x590+3942-0x14e1)]=zc1ac25c1d6&~((0x1286+2037-0x1a7a)<<(0x209+2416-0xb77));z3e5b8e05d8[(0x41a+4402-0x1537)]=zc1ac25c1d6|((0x8e2+786-0xbf3)<<(0x1ce3+56-0x1d19));
rl32eWaitDouble(mxGetPr(zdfab922aba)[start+(0xe6f+352-0xfc3)]);start+=(0x140f+924-0x179e);}z199556e987[(0x121b+44-0x1247)+zc369e1e9c6*(0x9+7377-0x1cd6)]=z97d855d69f;z199556e987[(0xcdd+3954-0x1c4e)+zc369e1e9c6*(0x15c8+1962-0x1d6e)]=z2b9653a7df;}}if(zddcad00412){zb825bf1c08=z3d252d79db(z3e5b8e05d8,z27fd94ac66,(0x1c3+9538-0x2705));

}if(zddcad00412){zb825bf1c08=z3d252d79db(z3e5b8e05d8,z27fd94ac66,(0x195+1999-0x963));

}
#endif 
}
#ifdef  MATLAB_MEX_FILE    
#include "simulink.c"      
#else
#include "cg_sfun.h"       
#endif

