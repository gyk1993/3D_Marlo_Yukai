/* Copyright 2006-2013 Speedgoat GmbH. */
#define         DEBUG                   (0x1874+309-0x19a9)
#define         S_FUNCTION_LEVEL        (0x106a+3282-0x1d3a)
#undef          S_FUNCTION_NAME
#define         S_FUNCTION_NAME         sg_IO601_read_s
#include        <stddef.h>
#include        <stdlib.h>
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
#define         zf1b619edf2                 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x36\x30\x31"
#define         z694756a014                (0x13b8+4979-0x1676)
#define         zea87e0ba83                36912
#define         z29146a1837             (0x1a27+1871-0x10c1)
#define         zab7e64468b             10615
#define         zdf24515981          ((0x873+5609-0x1e56))
#define         zbcb3e4d083              ssGetSFcnParam(S,(0xdcc+520-0xfd4))
#define         z9cd34e3860                ssGetSFcnParam(S,(0x6ab+1787-0xda5))
#define         zd75b5280cf               ssGetSFcnParam(S,(0x1980+1365-0x1ed3))
#define         z11e8538834              ssGetSFcnParam(S,(0xc35+1937-0x13c3))
#define         z3832b85a32           ssGetSFcnParam(S,(0x1587+3726-0x2411))
#define         z702a26a5e9                ssGetSFcnParam(S,(0x1623+1479-0x1be5))
#define         z2e6483d505              ((0xe19+6240-0x2677))
#define         z57e55a08c5        ((0x6a2+7678-0x24a0))
#define         z84eb1db314        ((0x3e8+4327-0x14ce))
#define         zc5ce4cb81a              ((0x1ec2+1363-0x2415))
#define         z2b17e2ee3b              ((0x1da1+38-0x1dc7))
#ifndef MATLAB_MEX_FILE
#ifndef  zb84e0c3c3b
#define  zb84e0c3c3b(zc1d61b7d63)  *( (uint8_T *) &zc1d61b7d63)
#endif
#ifndef  z15e663b423
#define  z15e663b423(zc1d61b7d63)  *(((uint8_T *) &zc1d61b7d63) + (0x1621+1107-0x1a73))
#endif
#ifndef  zfca7eb6338
#define  zfca7eb6338(zc1d61b7d63)  *( (uint16_T *) &zc1d61b7d63)
#endif
#ifndef  z3607971cd6
#define  z3607971cd6(zc1d61b7d63)  *(((uint16_T *) &zc1d61b7d63) + (0x3af+2767-0xe7d))
#endif
#ifndef z0056adfa94
#define z0056adfa94(zc1d61b7d63)       { uint8_T z7be9105675; z7be9105675 = z15e663b423(zc1d61b7d63); z15e663b423(zc1d61b7d63) = (uint8_T) zc1d61b7d63; zb84e0c3c3b(zc1d61b7d63) = z7be9105675; }
#endif
#ifndef z8444fc96d2
#define z8444fc96d2(zc1d61b7d63)       { uint16_T z7be9105675; z7be9105675 = z3607971cd6(zc1d61b7d63); z3607971cd6(zc1d61b7d63) = (uint16_T) zc1d61b7d63; zfca7eb6338(zc1d61b7d63) = z7be9105675; }
#endif
#endif
static char_T zea4cd01646[(0x2db+848-0x52b)];
#ifndef MATLAB_MEX_FILE
extern uint8_T z199556e987[];static uint32_T zaf39b56932(uint32_T id){z0056adfa94(z3607971cd6(id));z0056adfa94(zfca7eb6338(id));z8444fc96d2(id);id=id>>(0xb0f+1292-0x1006);return id;}static uint32_T zdc2355eb74(uint32_T id){z0056adfa94(z3607971cd6(id));z0056adfa94(zfca7eb6338(id));z8444fc96d2(id);id=id>>(0x1539+1888-0x1c96);return id;}static unsigned char zf6c13379ed(double value,int n){unsigned char*p;p=(unsigned char*)&value;return p[n];}
#endif
static void mdlInitializeSizes(SimStruct*S){int_T i;DECL_AND_INIT_DIMSINFO(iDimsInfo);int z58ec39b04d[(0x2a3+2131-0xaf4)];
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x10e4+92-0x1140));ssSetNumDiscStates(S,(0x4d2+3664-0x1322));iDimsInfo.width=(0x11fc+3247-0x1ea5)*(int_T)mxGetPr(zd75b5280cf)[(0xc47+4503-0x1dde)];iDimsInfo.numDims=(0x18df+2965-0x2472);iDimsInfo.dims=z58ec39b04d;z58ec39b04d[(0x8af+1908-0x1023)]=(int_T)mxGetPr(zd75b5280cf)[(0x8af+1569-0xed0)];z58ec39b04d[(0x1231+4329-0x2319)]=(0xfd9+4342-0x20c9);if((int_T)mxGetPr(z11e8538834)[(0x1019+713-0x12e2)]){ssSetNumOutputPorts(S,(0x1b89+1743-0x2256));ssSetOutputPortWidth(S,(0x67c+3729-0x150c),(0xd6f+5920-0x248d));}else{ssSetNumOutputPorts(S,(0xf14+3894-0x1e49));}if(!ssSetOutputPortDimensionInfo(S,(0x181b+2698-0x22a5),&iDimsInfo))return;ssSetNumInputPorts(S,(0x1bf1+325-0x1d36));ssSetNumSampleTimes(S,(0x1383+3983-0x2311));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,(0x6ab+3735-0x1542));ssSetNumModes(S,(0xafb+2979-0x169e));ssSetNumNonsampledZCs(S,(0x1465+3500-0x2211));for(i=(0xc7b+4396-0x1da7);i<zdf24515981;i++){ssSetSFcnParamNotTunable(S,i);}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0xb3a+887-0xeb1),mxGetPr(z3832b85a32)[(0x151b+3862-0x2431)]);if(mxGetN((z3832b85a32))==(0xb47+3670-0x199c)){ssSetOffsetTime(S,(0xfd0+2483-0x1983),0.0);}else{ssSetOffsetTime(S,(0x2d+6872-0x1b05),mxGetPr(z3832b85a32)[(0x13a9+4404-0x24dc)]);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zef529fae4a,*zdfcb1da404;void*ze2370ae9b9,*zf2db5722bf;volatile uint32_T*z3e5b8e05d8;volatile uint8_T*z27fd94ac66;volatile uint32_T*z706da0e1e5;uint_T i,z812c65ff2f,z26dbd73a5e;uint32_T z8ebd19230b;real_T z19c4ca5f82,start;uint32_T range,out;uint8_T name[(0x6f7+739-0x95a)];uint8_T version[(0x362+129-0x3d3)],z47f664c6f4[(0x199d+3024-0x2569)];uint32_T zc1ac25c1d6,z7be9105675;char z09e5c25c98[(0x84f+1240-0xd23)];uint8_T zb825bf1c08,zc369e1e9c6;uint8_T message[(0x1169+5452-0x26a1)];uint32_T za6dad42b7e[(0x1aa0+3008-0x265b)];zc369e1e9c6=(uint8_T)mxGetPr(zbcb3e4d083)[(0xf27+714-0x11f1)]-(0x5fa+8210-0x260b);if((int_T)mxGetPr(z702a26a5e9)[(0x190+1075-0x5c3)]<(0xcb0+4982-0x2026)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x2c5+955-0x67f)){z366b2f03bf=(0x856+3645-0x1693);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x14ff+522-0x1709)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x1bbf+2532-0x25a3)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1441+4130-0x2462)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x1788+3197-0x2306))|((z366b2f03bf&(0xdfd+4088-0x1cf6))<<(0x121f+2405-0x1b7c)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zef529fae4a=(void*)zeccbadd9b3.BaseAddress[(0x5cc+8079-0x255b)];ze2370ae9b9=rl32eGetDevicePtr(zef529fae4a,(0x800+2138-0xf32),RT_PG_USERREADWRITE);z3e5b8e05d8=(volatile uint32_T*)ze2370ae9b9;
zdfcb1da404=(void*)zeccbadd9b3.BaseAddress[(0x973+1443-0xf14)];zf2db5722bf=rl32eGetDevicePtr(zdfcb1da404,16384,RT_PG_USERREADWRITE);z27fd94ac66=(volatile uint8_T*)zf2db5722bf;z706da0e1e5=(volatile uint32_T*)zf2db5722bf;
ssSetIWorkValue(S,z57e55a08c5,(uint32_T)z3e5b8e05d8);ssSetIWorkValue(S,z84eb1db314,(uint32_T)z27fd94ac66);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
int_T index,z563e4da9f6,i,z26dbd73a5e,m,z812c65ff2f;unsigned char z42362badca[(0xa79+3061-0x1666)];real_T*y;unsigned long time;real_T*value;real_T z141dbfe199;real_T z05696d02cb;uint32_T zc1ac25c1d6,z7be9105675;uint8_T zc369e1e9c6=(uint8_T)mxGetPr(zbcb3e4d083)[(0x2a9+8239-0x22d8)]-(0x667+8260-0x26aa);uint8_T z0add1d1c25=(uint8_T)mxGetPr(z9cd34e3860)[(0x1322+4163-0x2365)]-(0x1af6+1994-0x22bf);uint8_T message[(0xb0a+1485-0x10c3)];uint32_T za6dad42b7e[(0x660+28-0x677)];volatile uint32_T*z3e5b8e05d8;volatile uint32_T*z706da0e1e5;uint32_T z5d9c31c2b6=ssGetIWorkValue(S,z57e55a08c5);uint32_T z31a846515d=ssGetIWorkValue(S,z84eb1db314);z3e5b8e05d8=(void*)z5d9c31c2b6;z706da0e1e5=(void*)z31a846515d;y=(real_T*)ssGetOutputPortSignal(S,(0x1072+4137-0x209b));m=ssGetOutputPortWidth(S,(0xf10+1148-0x138c))/(0x277+7115-0x1e3c);
z812c65ff2f=z199556e987[(0x26a+6213-0x1aad)+z0add1d1c25+zc369e1e9c6*(0x2df+3291-0xfb6)];for(i=(0x477+8180-0x246b);i<(int_T)mxGetPr(zd75b5280cf)[(0x20f5+962-0x24b7)];i++){if(z0add1d1c25==(0x1c54+1535-0x2253)){for(z26dbd73a5e=(0x14ca+1293-0x19d7);z26dbd73a5e<(0x9c+458-0x261);z26dbd73a5e++){za6dad42b7e[z26dbd73a5e]=z706da0e1e5[(0x7b2+2940-0x1126)+z812c65ff2f*(0xd5+8183-0x20c7)+z26dbd73a5e];
}
}else{for(z26dbd73a5e=(0xcdd+2848-0x17fd);z26dbd73a5e<(0x897+1267-0xd85);z26dbd73a5e++){za6dad42b7e[z26dbd73a5e]=z706da0e1e5[(0x1548+2051-0x1a49)+z812c65ff2f*(0x1643+2998-0x21f4)+z26dbd73a5e];
}
}memcpy(message,za6dad42b7e,(0x1234+3084-0x1e2c));if(message[(0xcd9+134-0xd5f)]){if(z0add1d1c25==(0x942+3019-0x150d)){z706da0e1e5[(0x86c+2084-0xe88)+z812c65ff2f*(0x145a+4586-0x263f)+(0x4fd+262-0x603)]=za6dad42b7e[(0x1008+891-0x1383)]&4294967040;}else{z706da0e1e5[(0x388+1027-0x489)+z812c65ff2f*(0x178+4364-0x127f)+(0x829+4402-0x195b)]=za6dad42b7e[(0x1526+2134-0x1d7c)]&4294967040;}z812c65ff2f++;if(z812c65ff2f==(0x15a+1170-0x5ba))z812c65ff2f=(0x787+2344-0x10af);if(z0add1d1c25==(0x2bb+3598-0x10c9)){y[i+m*(0xab8+624-0xd28)]=1.0;}else{y[i+m*(0x50b+2-0x50d)]=2.0;}if((message[(0x7f+8482-0x219a)]&(0x3bb+6018-0x1abd))==(0x13d0+3342-0x20de)){
y[i+m*(0xf0c+3921-0x1e5c)]=(real_T)zaf39b56932(message[(0x381+578-0x5bb)]|(message[(0x55c+728-0x82b)]<<(0xd09+1388-0x126d)));y[i+m*(0xd40+753-0x102f)]=1.0;
y[i+m*(0xc79+2657-0x16d5)]=(real_T)*((real_T*)&message[(0xab5+6731-0x24f6)]);}else{y[i+m*(0xb5c+3292-0x1837)]=(real_T)zdc2355eb74(message[(0xf49+3027-0x1b14)]|(message[(0x1684+864-0x19db)]<<(0x147f+1435-0x1a12))|(message[(0x803+3987-0x178c)]<<(0x663+3900-0x158f))|(message[(0x1178+597-0x13c2)]<<(0x1f24+1440-0x24ac)));y[i+m*(0x114f+2838-0x1c63)]=9.0;
y[i+m*(0x77b+1448-0xd1e)]=(real_T)*((real_T*)&message[(0x158a+671-0x181d)]);}y[i+m*(0x1c44+356-0x1da5)]=message[(0xa71+1077-0xe9f)]&(0x950+1224-0xe09);y[i+m*(0x15e5+969-0x19aa)]=(real_T)*((uint32_T*)&message[(0x15c0+3642-0x23f8)]);}else{y[i+m*(0x941+5337-0x1e1a)]=0.0;y[i+m*(0x3da+6056-0x1b81)]=-1.0;y[i+m*(0x132b+2186-0x1bb3)]=0.0;y[i+m*(0x1398+1545-0x199e)]=0.0;y[i+m*(0x801+7228-0x2439)]=-1.0;y[i+m*(0xc9c+5569-0x2258)]=0.0;}}z199556e987[(0x538+182-0x5ec)+z0add1d1c25+zc369e1e9c6*(0x1283+1515-0x186a)]=z812c65ff2f;if((int_T)mxGetPr(z11e8538834)[(0x274+5047-0x162b)]){y=(real_T*)ssGetOutputPortSignal(S,(0x1105+2688-0x1b84));if(!ssGetT(S)>0.0){y[(0x130+7082-0x1cda)]=0.0;y[(0x289+3808-0x1168)]=0.0;}else{y[(0x16fd+1270-0x1bf3)]=0.0;y[(0x2c0+7373-0x1f8c)]=0.0;}}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef  MATLAB_MEX_FILE    
#include "simulink.c"      
#else
#include "cg_sfun.h"       
#endif

