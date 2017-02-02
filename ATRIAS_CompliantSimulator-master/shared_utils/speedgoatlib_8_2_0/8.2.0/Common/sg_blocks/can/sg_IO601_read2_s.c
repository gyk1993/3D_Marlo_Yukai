/* Copyright 2006-2013 Speedgoat GmbH. */
#define         DEBUG                   (0x9f+1612-0x6eb)
#define         S_FUNCTION_LEVEL        (0xd1c+2477-0x16c7)
#undef          S_FUNCTION_NAME
#define         S_FUNCTION_NAME         sg_IO601_read2_s
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
#define         z694756a014                (0x1370+328-0x403)
#define         zea87e0ba83                36912
#define         z29146a1837             (0x1dab+802-0x1018)
#define         zab7e64468b             10615
#define         zdf24515981          ((0x107a+3202-0x1cf5))
#define         zbcb3e4d083              ssGetSFcnParam(S,(0x8e3+1320-0xe0b))
#define         z9cd34e3860                ssGetSFcnParam(S,(0x216c+433-0x231c))
#define         zd75b5280cf               ssGetSFcnParam(S,(0x1838+2269-0x2113))
#define         z8ce43c1a22             ssGetSFcnParam(S,(0x19ff+1714-0x20ae))
#define         z11e8538834              ssGetSFcnParam(S,(0x1598+3020-0x2160))
#define         z3832b85a32           ssGetSFcnParam(S,(0x79b+964-0xb5a))
#define         z702a26a5e9                ssGetSFcnParam(S,(0x192d+1404-0x1ea3))
#define         z2e6483d505              ((0x302+4609-0x1501))
#define         z57e55a08c5        ((0xa38+7317-0x26cd))
#define         z84eb1db314        ((0x136b+1045-0x177f))
#define         zc5ce4cb81a              ((0x12a8+397-0x1435))
#define         z2b17e2ee3b              ((0x1233+1413-0x17b8))
#ifndef MATLAB_MEX_FILE
#ifndef  zb84e0c3c3b
#define  zb84e0c3c3b(zc1d61b7d63)  *( (uint8_T *) &zc1d61b7d63)
#endif
#ifndef  z15e663b423
#define  z15e663b423(zc1d61b7d63)  *(((uint8_T *) &zc1d61b7d63) + (0x1474+2870-0x1fa9))
#endif
#ifndef  zfca7eb6338
#define  zfca7eb6338(zc1d61b7d63)  *( (uint16_T *) &zc1d61b7d63)
#endif
#ifndef  z3607971cd6
#define  z3607971cd6(zc1d61b7d63)  *(((uint16_T *) &zc1d61b7d63) + (0x1304+2046-0x1b01))
#endif
#ifndef z0056adfa94
#define z0056adfa94(zc1d61b7d63)       { uint8_T z7be9105675; z7be9105675 = z15e663b423(zc1d61b7d63); z15e663b423(zc1d61b7d63) = (uint8_T) zc1d61b7d63; zb84e0c3c3b(zc1d61b7d63) = z7be9105675; }
#endif
#ifndef z8444fc96d2
#define z8444fc96d2(zc1d61b7d63)       { uint16_T z7be9105675; z7be9105675 = z3607971cd6(zc1d61b7d63); z3607971cd6(zc1d61b7d63) = (uint16_T) zc1d61b7d63; zfca7eb6338(zc1d61b7d63) = z7be9105675; }
#endif
#endif
static char_T zea4cd01646[(0xed2+4469-0x1f47)];typedef struct{uint8_T z1fde0a5efd;uint8_T Length;uint8_T ze0cf853226;uint8_T Error;uint32_T ID;double Timestamp;uint8_T Data[(0x1fd6+531-0x21e1)];}z80857f1537;










#ifndef MATLAB_MEX_FILE
extern uint8_T z199556e987[];static uint32_T zaf39b56932(uint32_T id){z0056adfa94(z3607971cd6(id));z0056adfa94(zfca7eb6338(id));z8444fc96d2(id);id=id>>(0x1da+8818-0x2437);return id;}static uint32_T zdc2355eb74(uint32_T id){z0056adfa94(z3607971cd6(id));z0056adfa94(zfca7eb6338(id));z8444fc96d2(id);id=id>>(0x1cb3+1327-0x21df);return id;}static unsigned char zf6c13379ed(double value,int n){unsigned char*p;p=(unsigned char*)&value;return p[n];}
#endif
static void mdlInitializeSizes(SimStruct*S){int_T i;DECL_AND_INIT_DIMSINFO(iDimsInfo);int z58ec39b04d[(0x201+419-0x3a2)];int_T z9dc9623fa2,status;DTypeId id;int_T z635304c58c=(int_T)mxGetPr(z8ce43c1a22)[(0x9bd+4133-0x19e2)];int_T depth=(int_T)mxGetPr(zd75b5280cf)[(0x392+2591-0xdb1)];z80857f1537 z52754d10b7;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x1e7f+567-0x20b6));ssSetNumDiscStates(S,(0x6df+382-0x85d));
#ifdef MATLAB_MEX_FILE
switch(z635304c58c){case(0xc7d+691-0xf2f):if((int_T)mxGetPr(z11e8538834)[(0x1059+4852-0x234d)]){if(!ssSetNumOutputPorts(S,(0xe3d+4488-0x1fc3)))return;ssSetOutputPortWidth(S,(0xe8c+3643-0x1cc6),(0x3db+8684-0x25c5));
}else{if(!ssSetNumOutputPorts(S,(0x43a+7716-0x225d)))return;}iDimsInfo.width=(0x476+7125-0x2045)*depth;iDimsInfo.numDims=(0x93+2527-0xa70);iDimsInfo.dims=z58ec39b04d;z58ec39b04d[(0xfa3+2429-0x1920)]=depth;z58ec39b04d[(0x8c4+7081-0x246c)]=(0xb4f+6712-0x2581);if(!ssSetOutputPortDimensionInfo(S,(0x1f19+1082-0x2353),&iDimsInfo))return;break;case(0x5fc+4564-0x17ce):

id=ssRegisterDataType(S,"\x43\x41\x4e\x5f\x4d\x45\x53\x53\x41\x47\x45");if(id==INVALID_DTYPE_ID)return;status=ssSetDataTypeSize(S,id,sizeof(z52754d10b7));z9dc9623fa2=ssGetDataTypeId(S,"\x43\x41\x4e\x5f\x4d\x45\x53\x53\x41\x47\x45");if((int_T)mxGetPr(z11e8538834)[(0x23c+705-0x4fd)]){if(!ssSetNumOutputPorts(S,(0x2c+1957-0x7ce)))return;
ssSetOutputPortDataType(S,(0x1050+4312-0x2128),z9dc9623fa2);
ssSetOutputPortWidth(S,(0x141a+4531-0x25cd),depth);ssSetOutputPortWidth(S,(0x182+3763-0x1034),(0x1838+3563-0x2622));ssSetOutputPortWidth(S,(0x506+6013-0x1c81),(0x2f8+8661-0x24cb));
}else{if(!ssSetNumOutputPorts(S,(0xbe4+2742-0x1698)))return;
ssSetOutputPortDataType(S,(0x1142+5447-0x2689),z9dc9623fa2);
ssSetOutputPortWidth(S,(0xfea+4615-0x21f1),depth);ssSetOutputPortWidth(S,(0x1496+595-0x16e8),(0x198a+1328-0x1eb9));}break;case(0x288+7981-0x21b2):

id=ssRegisterDataType(S,"\x43\x41\x4e\x5f\x4d\x45\x53\x53\x41\x47\x45");if(id==INVALID_DTYPE_ID)return;status=ssSetDataTypeSize(S,id,sizeof(z52754d10b7));z9dc9623fa2=ssGetDataTypeId(S,"\x43\x41\x4e\x5f\x4d\x45\x53\x53\x41\x47\x45");if((int_T)mxGetPr(z11e8538834)[(0x193d+3002-0x24f7)]){if(!ssSetNumOutputPorts(S,(0x1337+979-0x1707)))return;
ssSetOutputPortDataType(S,(0xfc2+5721-0x261a),z9dc9623fa2);
ssSetOutputPortWidth(S,(0xdc1+455-0xf88),(0x1bd6+1585-0x2206));ssSetOutputPortWidth(S,(0xed9+2486-0x188e),(0x17b0+552-0x19d7));ssSetOutputPortWidth(S,(0x4a9+5968-0x1bf7),(0x1462+319-0x159f));
}else{if(!ssSetNumOutputPorts(S,(0x79+6439-0x199e)))return;
ssSetOutputPortDataType(S,(0x4d8+5269-0x196c),z9dc9623fa2);
ssSetOutputPortWidth(S,(0xf13+203-0xfde),(0x165f+757-0x1953));ssSetOutputPortWidth(S,(0x1a18+1502-0x1ff5),(0x1118+2961-0x1ca8));}break;}
#endif
ssSetNumInputPorts(S,(0x303+7113-0x1ecc));ssSetNumSampleTimes(S,(0x13b1+3855-0x22bf));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,(0x1771+1665-0x1df2));ssSetNumModes(S,(0x6c4+1610-0xd0e));ssSetNumNonsampledZCs(S,(0xd9a+2939-0x1915));for(i=(0x230+6792-0x1cb8);i<zdf24515981;i++){ssSetSFcnParamNotTunable(S,i);}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x1356+4800-0x2616),mxGetPr(z3832b85a32)[(0xd96+2913-0x18f7)]);if(mxGetN((z3832b85a32))==(0x16a8+3476-0x243b)){ssSetOffsetTime(S,(0xd5+8753-0x2306),0.0);}else{ssSetOffsetTime(S,(0xe9d+4744-0x2125),mxGetPr(z3832b85a32)[(0x1147+3586-0x1f48)]);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zef529fae4a,*zdfcb1da404;void*ze2370ae9b9,*zf2db5722bf;volatile uint32_T*z3e5b8e05d8;volatile uint8_T*z27fd94ac66;volatile uint32_T*z706da0e1e5;uint8_T zc369e1e9c6;zc369e1e9c6=(uint8_T)mxGetPr(zbcb3e4d083)[(0x1b7+7925-0x20ac)]-(0xf40+5691-0x257a);if((int_T)mxGetPr(z702a26a5e9)[(0xb63+4355-0x1c66)]<(0x85f+1278-0xd5d)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xac5+2239-0x1383)){z366b2f03bf=(0x3f+5335-0x1516);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x2a0+1532-0x89c)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x1646+3270-0x230c)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x53+884-0x3c6)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x76c+8134-0x2633))|((z366b2f03bf&(0x1e3b+513-0x1f3d))<<(0xb77+2294-0x1465)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zef529fae4a=(void*)zeccbadd9b3.BaseAddress[(0xdd7+2515-0x17aa)];ze2370ae9b9=rl32eGetDevicePtr(zef529fae4a,(0xfc1+1336-0x13d1),RT_PG_USERREADWRITE);z3e5b8e05d8=(volatile uint32_T*)ze2370ae9b9;
zdfcb1da404=(void*)zeccbadd9b3.BaseAddress[(0xae6+2173-0x1361)];zf2db5722bf=rl32eGetDevicePtr(zdfcb1da404,16384,RT_PG_USERREADWRITE);z27fd94ac66=(volatile uint8_T*)zf2db5722bf;z706da0e1e5=(volatile uint32_T*)zf2db5722bf;
ssSetIWorkValue(S,z57e55a08c5,(uint32_T)z3e5b8e05d8);ssSetIWorkValue(S,z84eb1db314,(uint32_T)z27fd94ac66);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
int_T i,z26dbd73a5e,m,z812c65ff2f,z73ad54f05e;z80857f1537*y1;real_T*y,*y2;uint8_T zc369e1e9c6=(uint8_T)mxGetPr(zbcb3e4d083)[(0x1a59+40-0x1a81)]-(0x1b2+2031-0x9a0);uint8_T z0add1d1c25=(uint8_T)mxGetPr(z9cd34e3860)[(0x16bc+3506-0x246e)]-(0x14ac+1784-0x1ba3);uint8_T message[(0x1be2+2846-0x26ec)];uint32_T za6dad42b7e[(0xb68+5283-0x2006)];
volatile uint32_T*z3e5b8e05d8;volatile uint32_T*z706da0e1e5;uint32_T z5d9c31c2b6=ssGetIWorkValue(S,z57e55a08c5);uint32_T z31a846515d=ssGetIWorkValue(S,z84eb1db314);z3e5b8e05d8=(volatile uint32_T*)z5d9c31c2b6;z706da0e1e5=(volatile uint32_T*)z31a846515d;m=ssGetOutputPortWidth(S,(0x4f0+5025-0x1891))/(0xbe8+3597-0x19ef);
z812c65ff2f=z199556e987[(0x1016+2821-0x1b19)+z0add1d1c25+zc369e1e9c6*(0x1595+3809-0x2472)];if((int_T)mxGetPr(z8ce43c1a22)[(0xbf+5033-0x1468)]==(0x6af+4666-0x18e7)){
y1=(z80857f1537*)ssGetOutputPortSignal(S,(0x10f4+4030-0x20b2));y2=(double*)ssGetOutputPortSignal(S,(0xbb6+2752-0x1675));z73ad54f05e=(0xdda+6333-0x2697);for(i=(0x1cc3+1815-0x23da);i<(int_T)mxGetPr(zd75b5280cf)[(0x129a+3694-0x2108)];i++){
if(z0add1d1c25==(0x1bd+6589-0x1b7a)){for(z26dbd73a5e=(0x96a+6877-0x2447);z26dbd73a5e<(0x21f+6702-0x1c48);z26dbd73a5e++){za6dad42b7e[z26dbd73a5e]=z706da0e1e5[(0x1326+3790-0x1fec)+z812c65ff2f*(0xaa0+4646-0x1cc1)+z26dbd73a5e];
}
}else{for(z26dbd73a5e=(0x596+1574-0xbbc);z26dbd73a5e<(0x921+1656-0xf94);z26dbd73a5e++){za6dad42b7e[z26dbd73a5e]=z706da0e1e5[(0xf64+5594-0x223c)+z812c65ff2f*(0x1580+706-0x183d)+z26dbd73a5e];
}
}memcpy(message,za6dad42b7e,(0x7cf+2136-0x1013));if(message[(0x1338+4206-0x23a6)]){if(z0add1d1c25==(0x1ad4+0-0x1ad4)){z706da0e1e5[(0x107f+5558-0x242d)+z812c65ff2f*(0x3d2+3128-0x1005)+(0xd88+6306-0x262a)]=za6dad42b7e[(0xe77+1510-0x145d)]&4294967040;}else{z706da0e1e5[(0x8ff+1808-0xd0d)+z812c65ff2f*(0x1cf1+2295-0x25e3)+(0x1594+886-0x190a)]=za6dad42b7e[(0x1053+3907-0x1f96)]&4294967040;}z812c65ff2f++;if(z812c65ff2f==(0xc83+1563-0x126c))z812c65ff2f=(0x14a6+2606-0x1ed4);if((message[(0x739+3683-0x1595)]&(0x1fc+5234-0x15ee))==(0xba5+6319-0x2454)){
y1[i].ID=(uint32_T)((real_T)zaf39b56932(message[(0x6ad+5480-0x1c0d)]|(message[(0xa2f+2126-0x1274)]<<(0x40a+3333-0x1107))));y1[i].z1fde0a5efd=(uint8_T)0.0;
y1[i].Data[(0x182f+2296-0x2127)]=message[(0x18c+7775-0x1fe1)];y1[i].Data[(0x777+8049-0x26e7)]=message[(0x558+3869-0x146a)];y1[i].Data[(0x6e7+6337-0x1fa6)]=message[(0xfb1+1461-0x155a)];y1[i].Data[(0x2f9+7179-0x1f01)]=message[(0x1080+1057-0x1494)];y1[i].Data[(0xc37+2855-0x175a)]=message[(0x5e1+7475-0x2306)];y1[i].Data[(0xc0f+4744-0x1e92)]=message[(0x8b1+6811-0x233d)];y1[i].Data[(0x581+6740-0x1fcf)]=message[(0x322+2349-0xc3f)];y1[i].Data[(0x532+4316-0x1607)]=message[(0xaef+1349-0x1023)];}else{y1[i].ID=(uint32_T)((real_T)zdc2355eb74(message[(0x282+4931-0x15bd)]|(message[(0x274+4373-0x1380)]<<(0x41d+6017-0x1b96))|(message[(0x5cd+4922-0x18fd)]<<(0x1880+2851-0x2393))|(message[(0x8c9+730-0xb98)]<<(0x406+7068-0x1f8a))));y1[i].z1fde0a5efd=(uint8_T)1.0;
y1[i].Data[(0x1933+3140-0x2577)]=message[(0xf02+4051-0x1ec9)];y1[i].Data[(0x5c5+6971-0x20ff)]=message[(0xe58+3420-0x1ba7)];y1[i].Data[(0x92b+4551-0x1af0)]=message[(0x2d7+5699-0x190c)];y1[i].Data[(0x361+6326-0x1c14)]=message[(0x755+1965-0xef3)];y1[i].Data[(0x1358+4860-0x2650)]=message[(0x1e48+2140-0x2694)];y1[i].Data[(0x149+9126-0x24ea)]=message[(0x767+583-0x99d)];y1[i].Data[(0x435+3341-0x113c)]=message[(0xd9a+5254-0x220e)];y1[i].Data[(0x358+1168-0x7e1)]=message[(0x687+3782-0x153a)];}y1[i].Length=message[(0x310+7649-0x20ea)]&(0xeff+1201-0x13a1);y1[i].Timestamp=(real_T)*((uint32_T*)&message[(0xd97+4241-0x1e26)]);z73ad54f05e++;}else{y1[i].ID=(uint32_T)-1.0;y1[i].Error=(uint8_T)0.0;y1[i].Length=(uint8_T)0.0;y1[i].Timestamp=-1.0;y1[i].Data[(0x132+3623-0xf59)]=(0x340+6649-0x1d39);y1[i].Data[(0xcf6+1147-0x1170)]=(0x229+2317-0xb36);y1[i].Data[(0x747+769-0xa46)]=(0x1d09+262-0x1e0f);y1[i].Data[(0x1c9c+695-0x1f50)]=(0x1216+5280-0x26b6);y1[i].Data[(0x4d6+4778-0x177c)]=(0x762+2599-0x1189);y1[i].Data[(0x596+1469-0xb4e)]=(0x1296+2638-0x1ce4);y1[i].Data[(0x8f7+6888-0x23d9)]=(0x3d+7722-0x1e67);y1[i].Data[(0xd8f+1542-0x138e)]=(0x4af+3029-0x1084);}
}y2[(0xb07+3195-0x1782)]=z73ad54f05e;}else{
y=(real_T*)ssGetOutputPortSignal(S,(0xc5+7279-0x1d34));for(i=(0x9+7851-0x1eb4);i<(int_T)mxGetPr(zd75b5280cf)[(0x1a8f+1941-0x2224)];i++){if(z0add1d1c25==(0x158c+3192-0x2204)){for(z26dbd73a5e=(0x7f8+3484-0x1594);z26dbd73a5e<(0xbdc+3416-0x192f);z26dbd73a5e++){za6dad42b7e[z26dbd73a5e]=z706da0e1e5[(0x115c+2770-0x1a26)+z812c65ff2f*(0xa6c+4619-0x1c72)+z26dbd73a5e];
}
}else{for(z26dbd73a5e=(0x128c+1924-0x1a10);z26dbd73a5e<(0x1be9+908-0x1f70);z26dbd73a5e++){za6dad42b7e[z26dbd73a5e]=z706da0e1e5[(0x7bc+5725-0x1b17)+z812c65ff2f*(0x9f7+2504-0x13ba)+z26dbd73a5e];
}
}memcpy(message,za6dad42b7e,(0x1419+1290-0x190f));if(message[(0x9bd+2382-0x130b)]){if(z0add1d1c25==(0x204+3863-0x111b)){z706da0e1e5[(0xb0a+2716-0x139e)+z812c65ff2f*(0x13bc+2178-0x1c39)+(0x13cd+1764-0x1ab1)]=za6dad42b7e[(0x141b+4361-0x2524)]&4294967040;}else{z706da0e1e5[(0x460+892-0x4da)+z812c65ff2f*(0x23+4688-0x126e)+(0xf2+7328-0x1d92)]=za6dad42b7e[(0x36b+8252-0x23a7)]&4294967040;}z812c65ff2f++;if(z812c65ff2f==(0x1252+4944-0x2570))z812c65ff2f=(0x17f+8894-0x243d);if(z0add1d1c25==(0xd6+4955-0x1431)){y[i+m*(0x13a+9467-0x2635)]=1.0;}else{y[i+m*(0xe09+3269-0x1ace)]=2.0;}if((message[(0x4b5+3655-0x12f5)]&(0x15c6+4453-0x26ab))==(0xd64+2144-0x15c4)){
y[i+m*(0xb40+3447-0x18b6)]=(real_T)zaf39b56932(message[(0x1603+348-0x1757)]|(message[(0xb0+3019-0xc72)]<<(0xdd1+5873-0x24ba)));y[i+m*(0x1c2a+744-0x1f10)]=1.0;
y[i+m*(0xcb0+6240-0x250b)]=(real_T)*((real_T*)&message[(0xbf9+3753-0x1a98)]);}else{y[i+m*(0x643+5600-0x1c22)]=(real_T)zdc2355eb74(message[(0x352+203-0x415)]|(message[(0xa66+54-0xa93)]<<(0xcbc+698-0xf6e))|(message[(0x757+6087-0x1f14)]<<(0x392+3743-0x1221))|(message[(0x194a+2641-0x2390)]<<(0x1290+326-0x13be)));y[i+m*(0x149f+1051-0x18b8)]=9.0;
y[i+m*(0x50f+5743-0x1b79)]=(real_T)*((real_T*)&message[(0x242+7540-0x1faa)]);
}y[i+m*(0x12d3+5072-0x26a0)]=message[(0x9fa+3846-0x18f9)]&(0x199+2629-0xbcf);y[i+m*(0x18d3+2197-0x2164)]=(real_T)*((uint32_T*)&message[(0xb55+6640-0x2543)]);}else{y[i+m*(0x7f+7868-0x1f3b)]=0.0;y[i+m*(0xde0+4791-0x2096)]=-1.0;y[i+m*(0x8fb+3828-0x17ed)]=0.0;y[i+m*(0x565+8527-0x26b1)]=0.0;y[i+m*(0xf9d+3707-0x1e14)]=-1.0;y[i+m*(0x77a+3150-0x13c3)]=0.0;}}}z199556e987[(0x1c0c+890-0x1f84)+z0add1d1c25+zc369e1e9c6*(0x5a8+2424-0xf1c)]=z812c65ff2f;if((int_T)mxGetPr(z11e8538834)[(0x68a+7756-0x24d6)]){y=(real_T*)ssGetOutputPortSignal(S,(0xcff+539-0xf19));if(!ssGetT(S)>0.0){y[(0xfbb+3514-0x1d75)]=0.0;y[(0x1991+151-0x1a27)]=0.0;}else{y[(0x943+6748-0x239f)]=0.0;y[(0xc65+2883-0x17a7)]=0.0;}}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef  MATLAB_MEX_FILE    
#include "simulink.c"      
#else
#include "cg_sfun.h"       
#endif

