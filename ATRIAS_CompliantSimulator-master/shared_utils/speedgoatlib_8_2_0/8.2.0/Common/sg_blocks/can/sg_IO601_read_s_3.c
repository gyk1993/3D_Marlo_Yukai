/* Copyright 2006-2013 Speedgoat GmbH. */
#define S_FUNCTION_LEVEL (0x742+5180-0x1b7c)
#undef S_FUNCTION_NAME
#define S_FUNCTION_NAME sg_IO601_read_s_3
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
#define zf1b619edf2                "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x36\x30\x31"
#define z694756a014               ((0x16a0+8078-0x2579))
#define zea87e0ba83               (36912)
#define z29146a1837            ((0x2701+1541-0x1c51))
#define zab7e64468b            (10615)
#define zdf24515981          ((0x4b3+7055-0x203b))
#define z78148dc72a          ssGetSFcnParam(S,(0xa6+448-0x266))
#define z832d756852          ssGetSFcnParam(S,(0x1176+1356-0x16c1))
#define z8ce43c1a22             ssGetSFcnParam(S,(0x3ca+334-0x516))
#define z90e5a68e4d           ssGetSFcnParam(S,(0x1153+2329-0x1a69))
#define z14f05c70c1           ssGetSFcnParam(S,(0x137+6961-0x1c64))
#define z3832b85a32           ssGetSFcnParam(S,(0x202a+625-0x2296))
#define z702a26a5e9                ssGetSFcnParam(S,(0xc6f+4898-0x1f8b))
#define z2e6483d505              ((0x151c+103-0x1580))
#define z84eb1db314        ((0x1de9+1881-0x2542))
#define z23d4f5073f              ((0xb24+5015-0x1eba))
#define z7a85c5de9b              ((0x1522+2720-0x1fc0))
#define zc5ce4cb81a              ((0x7fd+5778-0x1e8f))
#define z2b17e2ee3b              ((0x175d+1299-0x1c70))
static char_T zea4cd01646[(0xf94+3617-0x1cb5)];typedef struct{uint8_T z1fde0a5efd;uint8_T Length;uint8_T ze0cf853226;uint8_T Error;int32_T ID;double Timestamp;uint8_T Data[(0xfd9+5360-0x24c1)];}z80857f1537;typedef struct z5d859c8e2d{uint32_T z9b71add2e2[(0x690+7817-0x2514)];}z5d859c8e2d;
#ifndef MATLAB_MEX_FILE
static uint32_T za85eba763d(uint32_T id,uint32_T z81f62ac42b){uint32_T z72a53e0b28;z72a53e0b28=id;
z72a53e0b28=(uint32_T)(((z72a53e0b28&(0xc99+6714-0x25d4))<<(0xb1a+6453-0x2437))+((z72a53e0b28&65280)<<(0xe84+368-0xfec))+((z72a53e0b28&16711680)>>(0x94+5802-0x1736))+((z72a53e0b28&4278190080)>>(0x45d+2959-0xfd4)));z72a53e0b28=z72a53e0b28>>((0x33f+1029-0x724)-z81f62ac42b);return z72a53e0b28;}static uint8_T z825df60379(SimStruct*S,int32_T z0add1d1c25,z80857f1537*message){uint8_T status,position;z5d859c8e2d*z256cbcfc8b;uint32_T z9b71add2e2[(0x1529+2921-0x208d)];uint8_T z71f4cd9753[(0x9c8+1981-0x1171)];uint16_T z0aed4f7bfc;uint32_T z30a684c1d7;uint32_T base;base=ssGetIWorkValue(S,z84eb1db314);if(z0add1d1c25==(0x2b4+3420-0x100f)){position=ssGetIWorkValue(S,z23d4f5073f);z256cbcfc8b=(z5d859c8e2d*)(base+(0x2268+993-0x1e29)+position*sizeof(z5d859c8e2d));}else{position=ssGetIWorkValue(S,z7a85c5de9b);z256cbcfc8b=(z5d859c8e2d*)(base+(0xef6+35-0x311)+position*sizeof(z5d859c8e2d));}z9b71add2e2[(0x1993+1048-0x1dab)]=z256cbcfc8b->z9b71add2e2[(0x1d88+476-0x1f64)];status=z9b71add2e2[(0x571+2898-0x10c3)]&(0x1bca+2876-0x2607);if(status){z256cbcfc8b->z9b71add2e2[(0x9b9+4971-0x1d24)]=(0xd2a+5594-0x2304);z9b71add2e2[(0x1953+3341-0x265f)]=z256cbcfc8b->z9b71add2e2[(0x756+5434-0x1c8f)];z9b71add2e2[(0xe21+3691-0x1c8a)]=z256cbcfc8b->z9b71add2e2[(0xc02+5815-0x22b7)];z9b71add2e2[(0x99a+5609-0x1f80)]=z256cbcfc8b->z9b71add2e2[(0xa9+2276-0x98a)];z9b71add2e2[(0xcd+5521-0x165a)]=z256cbcfc8b->z9b71add2e2[(0x68+7022-0x1bd2)];memcpy(z71f4cd9753,z9b71add2e2,(0x681+6507-0x1fd8));if(z71f4cd9753[(0xb29+4903-0x1e49)]&(0x1849+749-0x1ab6)){message->z1fde0a5efd=(0xdf+7407-0x1dcd);message->Length=z71f4cd9753[(0x141+2810-0xc34)]&(0x16d+1605-0x7a3);message->ze0cf853226=(z71f4cd9753[(0x616+214-0x6e5)]&(0x9a0+4432-0x1ab0))>>(0x1db0+1414-0x2330);message->Error=(0x1ada+891-0x1e55);z30a684c1d7=z71f4cd9753[(0x515+1081-0x946)]|(z71f4cd9753[(0x409+6521-0x1d79)]<<(0x317+4304-0x13df))|(z71f4cd9753[(0x390+458-0x550)]<<(0x147a+4612-0x266e))|(z71f4cd9753[(0x7cf+4590-0x19b2)]<<(0x1f0+1327-0x707));message->ID=za85eba763d(z30a684c1d7,(0x1958+2046-0x2139));message->Timestamp=z71f4cd9753[(0x317+7012-0x1e79)]|(z71f4cd9753[(0x29d+1279-0x799)]<<(0x891+1733-0xf4e))|(z71f4cd9753[(0x1374+3400-0x20b8)]<<(0x1085+5284-0x2519))|(z71f4cd9753[(0xc40+2814-0x1739)]<<(0x109c+616-0x12ec));message->Data[(0x362+3816-0x124a)]=z71f4cd9753[(0x19c3+1370-0x1f11)];message->Data[(0x14a3+289-0x15c3)]=z71f4cd9753[(0x1c40+2712-0x26cb)];message->Data[(0x2b2+5331-0x1783)]=z71f4cd9753[(0x82f+4006-0x17c7)];message->Data[(0x51d+4355-0x161d)]=z71f4cd9753[(0x240+4227-0x12b4)];message->Data[(0x73d+5033-0x1ae2)]=z71f4cd9753[(0x71a+4179-0x175d)];message->Data[(0x121f+1462-0x17d0)]=z71f4cd9753[(0x5d1+3506-0x1372)];message->Data[(0xedd+5806-0x2585)]=z71f4cd9753[(0x196+9126-0x252a)];message->Data[(0x737+1353-0xc79)]=z71f4cd9753[(0x1296+4959-0x25e2)];}else{message->z1fde0a5efd=(0x2216+844-0x2562);message->Length=z71f4cd9753[(0xc99+1705-0x133b)]&(0xcfb+5025-0x208d);message->ze0cf853226=(z71f4cd9753[(0x9c0+3190-0x162f)]&(0x8d8+5419-0x1dc3))>>(0xb38+4905-0x1e5b);message->Error=(0x639+4806-0x18ff);z0aed4f7bfc=z71f4cd9753[(0x135f+2632-0x1d9f)]|(z71f4cd9753[(0x15af+2675-0x2019)]<<(0x192b+2094-0x2151));message->ID=za85eba763d(z0aed4f7bfc,(0xafc+5886-0x21ef));message->Timestamp=(real_T)(z71f4cd9753[(0x208a+495-0x2277)]+(z71f4cd9753[(0x1448+2956-0x1fd1)]<<(0x1243+1229-0x1708))+(z71f4cd9753[(0xf5f+3439-0x1cca)]<<(0x19c4+1582-0x1fe2))+(z71f4cd9753[(0xa1+8343-0x2133)]<<(0xc29+1484-0x11dd)));message->Data[(0x5e4+665-0x87d)]=z71f4cd9753[(0xb60+4394-0x1c80)];message->Data[(0x233+8549-0x2397)]=z71f4cd9753[(0xdc5+1633-0x141b)];message->Data[(0x12f6+1729-0x19b5)]=z71f4cd9753[(0x2272+561-0x2497)];message->Data[(0x636+1372-0xb8f)]=z71f4cd9753[(0x1bc+99-0x212)];message->Data[(0x130b+3286-0x1fdd)]=z71f4cd9753[(0x18e7+2544-0x22c9)];message->Data[(0x30d+7962-0x2222)]=z71f4cd9753[(0xb4c+2270-0x141b)];message->Data[(0xbb3+1396-0x1121)]=z71f4cd9753[(0xedb+960-0x128b)];message->Data[(0x5b5+8108-0x255a)]=z71f4cd9753[(0xdab+5666-0x23bc)];}position=(position==(0x406+6346-0x1c9f))?(0xb3+9091-0x2436):++position;if(z0add1d1c25==(0x7e1+2515-0x11b3)){
ssSetIWorkValue(S,z23d4f5073f,position);}else{ssSetIWorkValue(S,z7a85c5de9b,position);}return(0xa16+5040-0x1dc5);}else{return(0x1ac5+2659-0x2528);}}
#endif
static void mdlInitializeSizes(SimStruct*S){int_T i;uint32_T zbc7ebd0e53;DECL_AND_INIT_DIMSINFO(iDimsInfo);int z58ec39b04d[(0xe04+1133-0x126f)];int_T z635304c58c=(int_T)mxGetPr(z8ce43c1a22)[(0x201c+1502-0x25fa)];int_T depth;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0xe13+3048-0x19fb));ssSetNumDiscStates(S,(0x1575+2902-0x20cb));zbc7ebd0e53=(0xc97+6738-0x26e9);if((uint32_T)mxGetPr(z90e5a68e4d)[(0x133c+2714-0x1dd6)]){zbc7ebd0e53+=(0x8e3+6018-0x2063);}if((uint32_T)mxGetPr(z14f05c70c1)[(0x2b9+5715-0x190c)]){zbc7ebd0e53+=(0x9eb+612-0xc4d);}if(!ssSetNumOutputPorts(S,zbc7ebd0e53))return;zbc7ebd0e53=(0xb84+4936-0x1ecc);if((uint32_T)mxGetPr(z90e5a68e4d)[(0x1ccc+1742-0x239a)]){depth=(int_T)mxGetPr(z78148dc72a)[(0x7fb+6931-0x230e)];switch(z635304c58c){case(0x1a95+269-0x1ba1):iDimsInfo.width=(0x7a+2454-0xa0a)*depth;iDimsInfo.numDims=(0x604+50-0x634);iDimsInfo.dims=z58ec39b04d;z58ec39b04d[(0xf99+3612-0x1db5)]=depth;z58ec39b04d[(0x1dd+3337-0xee5)]=(0x17a+8444-0x2270);if(!ssSetOutputPortDimensionInfo(S,zbc7ebd0e53,&iDimsInfo))return;break;case(0x2cd+2704-0xd5b):
#ifdef MATLAB_MEX_FILE
{int_T z9dc9623fa2,status;DTypeId id;z80857f1537 z52754d10b7;id=ssRegisterDataType(S,"\x43\x41\x4e\x5f\x4d\x45\x53\x53\x41\x47\x45");if(id==INVALID_DTYPE_ID)return;status=ssSetDataTypeSize(S,id,sizeof(z52754d10b7));z9dc9623fa2=ssGetDataTypeId(S,"\x43\x41\x4e\x5f\x4d\x45\x53\x53\x41\x47\x45");ssSetOutputPortDataType(S,zbc7ebd0e53,z9dc9623fa2);ssSetOutputPortWidth(S,zbc7ebd0e53,depth);}
#endif
break;}
ssSetOutputPortWidth(S,zbc7ebd0e53+(0xb35+1960-0x12dc),(0xa1+4281-0x1159));zbc7ebd0e53=(0x1030+2274-0x1910);}if((uint32_T)mxGetPr(z14f05c70c1)[(0x613+7477-0x2348)]){depth=(int_T)mxGetPr(z832d756852)[(0x71c+3884-0x1648)];switch(z635304c58c){case(0x1dd+27-0x1f7):iDimsInfo.width=(0x62d+5797-0x1ccc)*depth;iDimsInfo.numDims=(0x1ff+1283-0x700);iDimsInfo.dims=z58ec39b04d;z58ec39b04d[(0xfb7+5589-0x258c)]=depth;z58ec39b04d[(0xd4+4212-0x1147)]=(0x2006+896-0x2380);if(!ssSetOutputPortDimensionInfo(S,zbc7ebd0e53,&iDimsInfo))return;break;case(0xbe7+1212-0x10a1):
#ifdef MATLAB_MEX_FILE
{int_T z9dc9623fa2,status;DTypeId id;z80857f1537 z52754d10b7;id=ssRegisterDataType(S,"\x43\x41\x4e\x5f\x4d\x45\x53\x53\x41\x47\x45");if(id==INVALID_DTYPE_ID)return;status=ssSetDataTypeSize(S,id,sizeof(z52754d10b7));z9dc9623fa2=ssGetDataTypeId(S,"\x43\x41\x4e\x5f\x4d\x45\x53\x53\x41\x47\x45");ssSetOutputPortDataType(S,zbc7ebd0e53,z9dc9623fa2);
ssSetOutputPortWidth(S,zbc7ebd0e53,depth);}
#endif
break;}
ssSetOutputPortWidth(S,zbc7ebd0e53+(0xf95+1211-0x144f),(0x117d+5128-0x2584));}ssSetNumInputPorts(S,(0x1834+1753-0x1f0d));ssSetNumSampleTimes(S,(0x1182+525-0x138e));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,(0x169a+3904-0x25da));ssSetNumModes(S,(0xdd9+4958-0x2137));ssSetNumNonsampledZCs(S,(0x1170+5332-0x2644));for(i=(0x64+2432-0x9e4);i<zdf24515981;i++){ssSetSFcnParamNotTunable(S,i);}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0xc44+5498-0x21be),mxGetPr(z3832b85a32)[(0x176+7351-0x1e2d)]);if(mxGetN(z3832b85a32)==(0x1e39+1888-0x2598)){ssSetOffsetTime(S,(0xc29+4230-0x1caf),0.0);}else{ssSetOffsetTime(S,(0x117a+2320-0x1a8a),mxGetPr(z3832b85a32)[(0x1436+1941-0x1bca)]);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;int32_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x124+8141-0x20f0)){z366b2f03bf=(0x22f+6837-0x1ce4);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x865+1296-0xd75)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x36c+8148-0x2340)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x3c+47-0x6a)];}if(xpcGetPCIDeviceInfo((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}zeccbadd9b3.VirtAddress[(0xa80+4071-0x1a65)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x742+1600-0xd80)],zeccbadd9b3.Length[(0x180+686-0x42c)],XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z84eb1db314,zeccbadd9b3.VirtAddress[(0xa1d+327-0xb62)]);ssSetIWorkValue(S,z23d4f5073f,(0x56+2061-0x863));ssSetIWorkValue(S,z7a85c5de9b,(0x10f1+4272-0x21a1));
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint8_T zc8f3dea123,offset;uint32_T z0add1d1c25,m,i,size;real_T*count,*z74abdb05a4;z80857f1537*out,message;real_T data;uint8_T*zb425515a78;z0add1d1c25=(0xfd4+1984-0x1794);if((uint32_T)mxGetPr(z90e5a68e4d)[(0x401+5295-0x18b0)]){if((uint32_T)mxGetPr(z8ce43c1a22)[(0x2278+153-0x2311)]==(0x1d6+2588-0xbf0)){size=(uint32_T)mxGetPr(z78148dc72a)[(0x7d8+2524-0x11b4)];out=(z80857f1537*)ssGetOutputPortSignal(S,z0add1d1c25);for(i=(0x57f+8588-0x270b);i<size;i++){out[i].z1fde0a5efd=(0x10ab+1935-0x183a);out[i].Length=(0xddd+5528-0x2375);out[i].ze0cf853226=(0x2b2+132-0x336);out[i].Error=(0x455+6048-0x1bf5);out[i].ID=(0x18fc+773-0x1c01);out[i].Timestamp=0.0;out[i].Data[(0x9a5+6999-0x24fc)]=(0x1d4d+618-0x1fb7);out[i].Data[(0x412+642-0x693)]=(0x1059+4728-0x22d1);out[i].Data[(0x16a3+702-0x195f)]=(0x971+1984-0x1131);out[i].Data[(0x684+7207-0x22a8)]=(0x245f+318-0x259d);out[i].Data[(0x14ad+3627-0x22d4)]=(0x152c+4466-0x269e);out[i].Data[(0x1881+219-0x1957)]=(0x138d+3474-0x211f);out[i].Data[(0x8c2+1484-0xe88)]=(0x93+5672-0x16bb);out[i].Data[(0x53b+4840-0x181c)]=(0x768+5304-0x1c20);}}else{
z74abdb05a4=(real_T*)ssGetOutputPortSignal(S,z0add1d1c25);size=(0xfaf+250-0x10a3)*(uint32_T)mxGetPr(z78148dc72a)[(0x2a4+7930-0x219e)];for(i=(0x1921+2553-0x231a);i<size;i++){z74abdb05a4[i]=0.0;}}z0add1d1c25++;}if((uint32_T)mxGetPr(z14f05c70c1)[(0x9+1501-0x5e6)]){if((uint32_T)mxGetPr(z8ce43c1a22)[(0x151c+2904-0x2074)]==(0x5d8+2773-0x10ab)){size=(uint32_T)mxGetPr(z832d756852)[(0xd3f+6499-0x26a2)];out=(z80857f1537*)ssGetOutputPortSignal(S,z0add1d1c25);for(i=(0xa7+7662-0x1e95);i<size;i++){out[i].z1fde0a5efd=(0xa03+6951-0x252a);out[i].Length=(0x1082+2176-0x1902);out[i].ze0cf853226=(0xb1b+2547-0x150e);out[i].Error=(0xde8+4-0xdec);out[i].ID=(0xdc0+5597-0x239d);out[i].Timestamp=0.0;out[i].Data[(0x444+225-0x525)]=(0xd1f+3256-0x19d7);out[i].Data[(0x75a+6646-0x214f)]=(0x49b+3903-0x13da);out[i].Data[(0x13ec+2874-0x1f24)]=(0x190d+886-0x1c83);out[i].Data[(0x205f+538-0x2276)]=(0xc00+5310-0x20be);out[i].Data[(0x35b+123-0x3d2)]=(0x1285+1051-0x16a0);out[i].Data[(0x177f+381-0x18f7)]=(0x1003+5787-0x269e);out[i].Data[(0x1aaf+2075-0x22c4)]=(0x979+5452-0x1ec5);out[i].Data[(0x1b11+1170-0x1f9c)]=(0xaa6+3919-0x19f5);}}else{
z74abdb05a4=(real_T*)ssGetOutputPortSignal(S,z0add1d1c25);size=(0x832+4009-0x17d5)*(uint32_T)mxGetPr(z832d756852)[(0x1494+2668-0x1f00)];for(i=(0xc0a+3399-0x1951);i<size;i++){z74abdb05a4[i]=0.0;}}}zc8f3dea123=(0x1ed0+96-0x1f30);offset=(0x38b+2256-0xc5b);if((uint32_T)mxGetPr(z90e5a68e4d)[(0x245+5805-0x18f2)]){z0add1d1c25=(0x30b+2023-0xaf1);zc8f3dea123=(0x40f+934-0x7b5);while(z825df60379(S,z0add1d1c25,&message)){if((uint32_T)mxGetPr(z8ce43c1a22)[(0x5e9+1478-0xbaf)]==(0x76c+7369-0x2433)){out=(z80857f1537*)ssGetOutputPortSignal(S,(0x1d6f+1114-0x21c9));out[zc8f3dea123]=message;}else{m=ssGetOutputPortWidth(S,(0x589+6779-0x2004))/(0x7e0+5363-0x1ccd);z74abdb05a4=(real_T*)ssGetOutputPortSignal(S,(0x1a3d+832-0x1d7d));z74abdb05a4[zc8f3dea123+m*(0xf57+1497-0x1530)]=(real_T)z0add1d1c25;z74abdb05a4[zc8f3dea123+m*(0x3dd+4675-0x161f)]=(real_T)message.ID;z74abdb05a4[zc8f3dea123+m*(0x1bcd+1909-0x2340)]=(real_T)message.z1fde0a5efd;z74abdb05a4[zc8f3dea123+m*(0x148a+3289-0x2160)]=(real_T)message.Length;z74abdb05a4[zc8f3dea123+m*(0xb09+7114-0x26cf)]=(real_T)message.Timestamp;zb425515a78=(uint8_T*)&data;zb425515a78[(0x11b6+906-0x1540)]=message.Data[(0x166a+1251-0x1b4d)];zb425515a78[(0xa5+2650-0xafe)]=message.Data[(0xcbc+4994-0x203d)];zb425515a78[(0x1016+659-0x12a7)]=message.Data[(0x1c6b+1683-0x22fc)];zb425515a78[(0x11c3+4305-0x2291)]=message.Data[(0x107a+4152-0x20af)];zb425515a78[(0x10ad+616-0x1311)]=message.Data[(0x1abb+2613-0x24ec)];zb425515a78[(0x15a7+2520-0x1f7a)]=message.Data[(0x137+7762-0x1f84)];zb425515a78[(0x9e8+6543-0x2371)]=message.Data[(0x1405+3445-0x2174)];zb425515a78[(0xa69+1906-0x11d4)]=message.Data[(0xc83+5666-0x229e)];z74abdb05a4[zc8f3dea123+m*(0x682+5731-0x1ce0)]=data;}zc8f3dea123++;if(zc8f3dea123==(uint8_T)mxGetPr(z78148dc72a)[(0x1484+961-0x1845)])break;}count=(real_T*)ssGetOutputPortSignal(S,(0x15e5+2325-0x1ef9));count[(0x0+2505-0x9c9)]=zc8f3dea123;offset=(0x18c6+983-0x1c9b);}if((uint32_T)mxGetPr(z14f05c70c1)[(0x22+5410-0x1544)]){z0add1d1c25=(0x1ef1+849-0x2240);zc8f3dea123=(0xe54+5633-0x2455);while(z825df60379(S,z0add1d1c25,&message)){if((uint32_T)mxGetPr(z8ce43c1a22)[(0x7f8+7357-0x24b5)]==(0x3e1+3245-0x108c)){out=(z80857f1537*)ssGetOutputPortSignal(S,offset);out[zc8f3dea123]=message;}else{m=ssGetOutputPortWidth(S,(0xe8a+2177-0x170b))/(0xd64+3946-0x1cc8);z74abdb05a4=(real_T*)ssGetOutputPortSignal(S,offset);z74abdb05a4[zc8f3dea123+m*(0xbd4+702-0xe92)]=(real_T)z0add1d1c25;z74abdb05a4[zc8f3dea123+m*(0x102b+3498-0x1dd4)]=(real_T)message.ID;z74abdb05a4[zc8f3dea123+m*(0x1457+1996-0x1c21)]=(real_T)message.z1fde0a5efd;z74abdb05a4[zc8f3dea123+m*(0xe46+6273-0x26c4)]=(real_T)message.Length;z74abdb05a4[zc8f3dea123+m*(0x633+5570-0x1bf1)]=(real_T)message.Timestamp;zb425515a78=(uint8_T*)&data;zb425515a78[(0x1a52+520-0x1c5a)]=message.Data[(0x5d6+1677-0xc63)];zb425515a78[(0x791+2618-0x11ca)]=message.Data[(0x215c+813-0x2488)];zb425515a78[(0x26a+8701-0x2465)]=message.Data[(0x764+839-0xaa9)];zb425515a78[(0x474+4653-0x169e)]=message.Data[(0xa9a+3814-0x197d)];zb425515a78[(0x14a+5305-0x15ff)]=message.Data[(0x5fc+5759-0x1c77)];zb425515a78[(0x18a+6028-0x1911)]=message.Data[(0xd1b+74-0xd60)];zb425515a78[(0x5fa+5531-0x1b8f)]=message.Data[(0x72c+6443-0x2051)];zb425515a78[(0x78f+5861-0x1e6d)]=message.Data[(0x56d+1756-0xc42)];z74abdb05a4[zc8f3dea123+m*(0x911+4750-0x1b9a)]=data;}zc8f3dea123++;if(zc8f3dea123==(uint8_T)mxGetPr(z832d756852)[(0x14d8+1249-0x19b9)])break;}count=(real_T*)ssGetOutputPortSignal(S,offset+(0x11cc+477-0x13a8));count[(0x23a+3398-0xf80)]=zc8f3dea123;}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef  MATLAB_MEX_FILE    
#include "simulink.c"      
#else
#include "cg_sfun.h"       
#endif
