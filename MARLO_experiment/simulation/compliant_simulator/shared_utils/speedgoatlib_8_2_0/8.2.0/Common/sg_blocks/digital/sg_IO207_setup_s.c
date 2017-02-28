/* Copyright 2006-2013 Speedgoat GmbH. */
#define		S_FUNCTION_LEVEL 	(0x350+4288-0x140e)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO207_setup_s
#include 	<stddef.h>
#include 	<stdlib.h>
#include 	"simstruc.h" 
#ifdef 		MATLAB_MEX_FILE
#include 	"mex.h"
#endif
#ifndef     MATLAB_MEX_FILE
#include    <windows.h>
#include    "xpcimports.h"
#endif
#define zf1b619edf2         		"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x32\x30\x37"
#define z694756a014        		5272
#define zea87e0ba83        		(0x1ddb+833-0x1e6f)
#define z29146a1837     		(0x1688+6636-0x1bdc)
#define zab7e64468b     		(0xbd7+6762-0x2637)
#define OUTPUT					(0xb18+2090-0x1341)
#define z07036f94e4				(0x1412+1811-0x1b25)
#define za7e5ff770f				(0x11+6424-0x1928)
#define zbd2af17e64				(0x58b+495-0x778)
#define zd721bc1f7d 				(0x1707+3793-0x25d5)
#define	z82ac25ee68				(0x1422+832-0x1761)
#define	zde7deffb36			(0x16e4+3617-0x2503)
#define zb8557d490d			(0xb3b+172-0xbe6)
#define z595f23365a			(0x1b9d+2407-0x2502)
#define zd5722e7b54			(0x2582+309-0x26b5)
#define z25297a45fe			(0xa18+1148-0xe93)
#define z2eb3db743c		(0x138f+1378-0x18ef)
#define zbd6eb35fcd			(0x324+7427-0x2025)
#define	THRESHOLD				0.5
#define z39451a5d37			(0x14ac+1815-0x1bb2)
#define zb0da4813e4		(0x1acf+794-0x1dc7)
#define z1491003f50	4294967278
#define z0a23ad657d	4294967261
#define FRONT					(0x75b+7017-0x22c3)
#define z722b515dc6					(0x12f5+3344-0x2003)
#define z5778f7a1a3			(0x959+6753-0x23b9)
#define z97d9bed5dc			(0xd78+6329-0x262f)
#define z509f1627a2		(0x623+4475-0x179b)
#define z9e732d4c07	(0x1dd7+1097-0x221c)
#define	za1420c1894		(0x370+2264-0xc43)
#define z3face4cfa2			(0xcb0+4346-0x1daa)
#define ze217394ff0		(0x28+9816-0x267f)
#define ON						(0x205+646-0x48a)
#define zcea0f9f05e			(0x234+6891-0x1d1e)	
#define z8d22d585f0			(0x100+3948-0x106a)
#define zec1d5a1fbb	(0x1f8b+1903-0x26f7)
#define zae532289bf 			(0x94b+6600-0x2212)
#define z1c66b39fc2 			(0x1fc1+1555-0x23d2)	
#define zc10c270d6d 	(0xf4c+3140-0x188d)
#define ze123281f9a 			(0x11e5+5084-0x24c1)
#define zf43a53c2c7 			(0x829+6344-0x1ef1)	
#define z68703d0a39 		(0xf54+3238-0x18fa)
#define z2499c861b0 			(0x13ab+4742-0x2630)
#define zc6ba819607 			(0xead+5055-0x226a)	
#define z05b05630ae 		(0x8f5+773-0xbf7)
typedef struct{volatile uint32_T z3bcf72e3b0:(0xf46+3270-0x1c00);volatile uint32_T zb2a1b81008:(0x11b7+2091-0x19e0);volatile uint32_T zc6056578ff:(0xbdb+1399-0x114c);volatile uint32_T za148ba1d39:(0x15bb+393-0x1742);}za9f694187f;typedef struct{volatile uint32_T z0bae92f8a6:(0xbc3+1937-0x1352);volatile uint32_T z2a4cb99921:(0x57f+4086-0x1573);volatile uint32_T z100a609d7e:(0xd42+3647-0x1b7f);volatile uint32_T z9dca0734d7:(0x2388+360-0x24ee);volatile uint32_T z7d0883b67c:(0x2c6+5003-0x164f);volatile uint32_T z766e168658:(0x329+1284-0x82b);volatile uint32_T z762be8382c:(0x13f2+3655-0x2237);volatile uint32_T z342301bac4:(0xc6d+6311-0x2512);volatile uint32_T z81e1191be9:(0x73a+4707-0x199b);volatile uint32_T zeeddbb94ee:(0x211c+1308-0x2636);volatile uint32_T z84dfa454a4:(0x1d84+2353-0x26b3);volatile uint32_T z37e531ad7c:(0x653+5281-0x1af2);volatile uint32_T za5956b286a:(0x350+3841-0x124f);volatile uint32_T z74a9b7298d:(0x1f57+1286-0x245b);volatile uint32_T zaee2a47eda:(0x1912+891-0x1c8b);volatile uint32_T z6f08faa826:(0x494+1190-0x938);}zef9692d1a5;typedef struct{volatile uint32_T z55adf78020:(0x17+6387-0x1902);volatile uint32_T zc9a82d16d2:(0xd32+5984-0x248a);volatile uint32_T z9e3604e32f:(0x944+5737-0x1fa5);volatile uint32_T z9e21f050a7:(0xa63+5984-0x21bb);volatile uint32_T z663361b3bd:(0x880+6527-0x21f7);volatile uint32_T ze5d8238fab:(0xce9+6296-0x2579);volatile uint32_T z491c7c851b:(0x116d+353-0x12c6);volatile uint32_T ze1cd30fe8c:(0x102f+1287-0x152e);volatile uint32_T z2206cd8626:(0xec6+796-0x11da);volatile uint32_T z11040e475d:(0x1bf1+1800-0x22f1);volatile uint32_T z9f23d60043:(0xdc+6388-0x19c8);volatile uint32_T z92dd099fcc:(0xd0d+5130-0x210f);volatile uint32_T z939de45019:(0xa97+1934-0x121d);volatile uint32_T z4305f9e43e:(0x1674+4148-0x26a0);volatile uint32_T z8ace4324e2:(0x1109+1936-0x1891);volatile uint32_T z15af32740e:(0xf8c+5876-0x2678);}z2a7ed9a195;typedef struct{volatile uint32_T z7f3e6de1c9;volatile uint32_T zc8d0c471e2;volatile uint32_T zf555a21781;volatile uint32_T ze863a41864;}z9accb57e12;typedef struct{volatile uint32_T ze6cf942569:(0x11b3+4619-0x23ae);volatile uint32_T z914c1e3365:(0xc94+4694-0x1ee4);volatile uint32_T z298035cbd7:(0xbfa+5775-0x2288);volatile uint32_T zfaaa787fe9:(0x1304+2811-0x1dfe);volatile uint32_T zd861c6f162:(0x814+2618-0x124c);volatile uint32_T z52a2e4e7b4:(0x299+4894-0x15b6);volatile uint32_T z1da935e695:(0x17e0+3827-0x26d2);volatile uint32_T z62c8722f81:(0x15ca+3826-0x24ba);volatile uint32_T zd431ee18af:(0x112f+4534-0x22e4);volatile uint32_T z7f9684ee9c:(0x134d+3604-0x2160);}z108ddbe7d2;struct z9352458a7e{union{volatile uint32_T zfcf290ae65;volatile z108ddbe7d2 z01ba27ea37;};volatile uint32_T z64e108ce79;volatile uint32_T zf634560d60;union{volatile uint32_T z38a734997e;volatile zef9692d1a5 z216e3dc0de;};union{volatile za9f694187f zb98b74f68b;volatile uint32_T z96d6777a46;};volatile uint32_T z5f4c500110;volatile uint32_T zb86e6c0151;volatile uint32_T zc6056578ff;volatile uint32_T z9ff13675ef;volatile uint32_T zb78d740ca9;volatile uint32_T z4aa54572fc;volatile uint32_T z1532f6e73a;volatile uint32_T zff6f8fc586;volatile uint32_T z1df15c3b5e;volatile uint32_T z0662e5575f:(0x2d6+5740-0x193a);volatile uint32_T z780e85314f:(0x5bd+4955-0x1910);volatile uint32_T z59905efb53:(0x255+1598-0x88b);volatile uint32_T zdc33f21b80:(0x226+3620-0x1042);volatile uint32_T z15492eeb4c:(0xa94+2105-0x12c5);volatile uint32_T zc9d0b3b99e:(0xcb4+5906-0x23be);volatile uint32_T zfc7f93f71d:(0xecf+448-0x1087);volatile uint32_T zd6720d2f44:(0x291+75-0x2d4);volatile uint32_T z3cdf8b00c2:(0x2250+903-0x25cf);volatile uint32_T z7579350ac8:(0x841+5950-0x1f77);volatile uint32_T zc91fd77f5d:(0x11a7+3487-0x1f3e);volatile uint32_T z35eb95d59f:(0x1c96+2075-0x24a9);volatile uint32_T zfbff660395:(0x8b+839-0x3ca);volatile uint32_T zd5ccdbf767:(0x8f5+371-0xa60);volatile uint32_T zbbfa7b0423:(0x106d+1951-0x1804);volatile uint32_T z2545fcbc59:(0x5f9+934-0x997);volatile uint32_T z57d8eb858f;volatile uint32_T z9603048a8e;volatile uint32_T z0013128818;volatile uint32_T z68748109eb;volatile uint32_T zae708dd178;volatile uint32_T 
zb0e6a24bc3;volatile uint32_T z4c047787ad;volatile uint32_T z58ccb35699;volatile uint32_T z2f3876fe26;volatile uint32_T z5e904ffaa5;volatile uint32_T za366274f8f;volatile uint32_T z7c50babe62;volatile uint32_T z78fccf0e8d;volatile uint32_T ze46d00d923;volatile uint32_T zfba812aa16;volatile uint32_T z7f7afd1a1c;volatile uint32_T z169cfd63df;volatile uint32_T z882b0826c4;volatile uint32_T z2fb8f1fdc4:(0xe76+962-0x1230);volatile uint32_T z30e60dbf98:(0x18bf+1579-0x1ee2);volatile uint32_T za03e2ba16c:(0x1e6f+785-0x2178);volatile uint32_T zb2acb4f445:(0xb7d+6902-0x266b);volatile uint32_T z1dba40c51d:(0x1229+1786-0x191b);volatile uint32_T z43f0a2167b:(0xef2+1767-0x15d1);volatile uint32_T z1f1c08cd8f:(0x1715+3336-0x2415);volatile uint32_T z0adb806f48:(0x910+1052-0xd24);volatile uint32_T z84d39b5d8e:(0x1710+727-0x19df);volatile uint32_T z02df292647:(0x6a+8215-0x2079);volatile uint32_T z2652474609:(0x7a4+1817-0xeb5);volatile uint32_T z8e692a6b27:(0xe95+2380-0x17d9);volatile uint32_T z07ae154fbf:(0x1295+2226-0x1b3f);volatile uint32_T zfd67937e0b:(0x189b+3470-0x2621);volatile uint32_T zc78c7b8fe3:(0x63c+403-0x7c7);volatile uint32_T zd8826e0840:(0x18a6+3270-0x2564);volatile uint32_T z6a7dbf75c1:(0x15d0+3173-0x222d);volatile uint32_T z4dcdeedd50:(0xbfa+5576-0x21ba);volatile uint32_T z8b5abd3294:(0xcb2+3869-0x1bc7);volatile uint32_T zd98c1dfb5e:(0x34b+2782-0xe21);volatile uint32_T zf54440c8a0:(0x1471+490-0x1653);volatile uint32_T z8ffc26ccf2:(0x658+1263-0xb3f);volatile uint32_T z5feefa368c:(0x541+8199-0x2540);volatile uint32_T z88acbfebd9:(0x967+5386-0x1e69);volatile uint32_T z7a025c5c2a:(0x15f9+1793-0x1cf2);volatile uint32_T zee184693df:(0x1a8b+2589-0x24a0);volatile uint32_T z01f92a32cf:(0xe0b+629-0x1078);volatile uint32_T z76ee226df3:(0xcd2+6613-0x269f);volatile uint32_T z97355c15cf:(0x1df8+911-0x217f);volatile uint32_T z0432a6af66:(0x152b+351-0x1682);volatile uint32_T z4094c589e9:(0x14c6+3129-0x20f7);volatile uint32_T zab9fe591c9:(0x4bc+5519-0x1a43);volatile uint32_T z6aa177be7b:(0x8a3+6879-0x237a);volatile uint32_T z9e10ed6bfc:(0x125+3931-0x1078);volatile uint32_T z3903d4280e:(0x11c9+1775-0x18b0);volatile uint32_T z8db4a9e05f:(0x4eb+7451-0x21fe);volatile uint32_T z97ab50d0e1:(0xcef+5684-0x231b);volatile uint32_T z5d49883aa8:(0x6fb+3307-0x13de);volatile uint32_T zd36617e34a:(0xbc9+1945-0x135a);volatile uint32_T z3d37bae027:(0x2644+60-0x2678);volatile uint32_T z9f12d8370d:(0xeb7+5136-0x22bf);volatile uint32_T z179b96afc4:(0x1e5+6505-0x1b46);volatile uint32_T z33c69d11f4:(0x18e7+1043-0x1cf2);volatile uint32_T z0aebdd2d4b:(0x73d+4722-0x19a7);volatile uint32_T z1f6c2867f8:(0xec+3728-0xf74);volatile uint32_T z9b6bc36219:(0x197d+2755-0x2438);volatile uint32_T zef6c2af81d:(0x717+947-0xac2);volatile uint32_T z5c14e4f0e2:(0x543+6411-0x1e46);volatile uint32_T z396015f081:(0xccc+4848-0x1fb4);volatile uint32_T z990126d5df:(0x1ce9+1629-0x233e);volatile uint32_T z1fafcfa21a:(0x1f1b+136-0x1f9b);volatile uint32_T z42bfdff275:(0x1a34+2668-0x2498);volatile uint32_T zb52305122c:(0x348+3417-0x1099);volatile uint32_T ze0f3853bee:(0x2fc+2022-0xada);volatile uint32_T z9d4379329f:(0xe61+806-0x117f);volatile uint32_T zc6a9a1ddc2:(0x195+7649-0x1f6e);volatile uint32_T z2624bf3001:(0x1813+3396-0x254f);volatile uint32_T z7a6bf95fda:(0xd03+1735-0x13c2);volatile uint32_T z08890b7527:(0xdf3+1010-0x11dd);volatile uint32_T z885fc6be12:(0x366+4655-0x158d);volatile uint32_T z944ffcdec8:(0x612+5249-0x1a8b);volatile uint32_T z675f2841b8:(0xb78+3159-0x17c7);volatile uint32_T zafc0f594ec:(0xea7+2093-0x16cc);volatile uint32_T zd903979df6:(0x14b1+1391-0x1a18);union{volatile z2a7ed9a195 z328e52c35d;volatile z9accb57e12 z84bb67aac4;};volatile uint32_T zcc04223910;volatile uint32_T ze09a57e39d;volatile uint32_T zf584caf1ea;volatile uint32_T zb0bd214c99;volatile uint32_T zf444bf523b;volatile uint32_T zda341247ea;volatile uint32_T z5d1c4607af;volatile uint32_T za5d1d275bb;};char zea4cd01646[(0xcd7+4382-0x1cf5)];
#define zdf24515981			((0x91+9652-0x2636))
#define z58f464b4bb					ssGetSFcnParam(S,(0x10e6+226-0x11c8))
#define z702a26a5e9                ssGetSFcnParam(S,(0x7a1+3700-0x1614))
#define z0254f95f00     ssGetSFcnParam(S,(0x1d91+1953-0x2530))
#define z44d8a68c1a         ssGetSFcnParam(S,(0xec1+1535-0x14bd))
#define z0e6f76218d         ssGetSFcnParam(S,(0xde9+2106-0x161f))
#define zb9dba6d10d		ssGetSFcnParam(S,(0xaf1+6225-0x233d))
#define zfc25efb894			ssGetSFcnParam(S,(0x1884+1157-0x1d03))
#define z0f3b626370			ssGetSFcnParam(S,(0x18a6+75-0x18ea))
#define z6a4eaeb2e3			ssGetSFcnParam(S,(0x8e0+7543-0x264f))
#define z6e5257a7ba			ssGetSFcnParam(S,(0x229+1570-0x842))
#define zfe38cda72c				ssGetSFcnParam(S,(0xc36+47-0xc5b))
#define za1d8e89e0e				ssGetSFcnParam(S,(0x206c+531-0x2274))
#define z233ae8e23f				ssGetSFcnParam(S,(0x1aa8+2538-0x2486))
#define z6c3b90de1b					ssGetSFcnParam(S,(0x9f4+3465-0x1770))
#define zd1cdc9602c		ssGetSFcnParam(S,(0x23da+827-0x2707))
#define z2e6483d505              ((0x85b+4358-0x1960))
#define z6a0da049de         ((0x7bd+9-0x7c6))     
#define zc5ce4cb81a              ((0x474+4318-0x1552))
#define z2b17e2ee3b              ((0x10e5+1556-0x16f9))
#define z53e64be319                ((0x35d+8766-0x259b))
#define zdf898925a0               ((0x1933+2804-0x2427))
static void mdlInitializeSizes(SimStruct*S){char zea4cd01646[(0x123+8501-0x2158)];int32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;
}ssSetNumContStates(S,(0x1765+1614-0x1db3));ssSetNumDiscStates(S,(0xb7+7122-0x1c89));ssSetNumSampleTimes(S,(0xea3+3303-0x1b89));ssSetNumModes(S,(0x1657+2696-0x20df));ssSetNumNonsampledZCs(S,(0x441+7822-0x22cf));for(i=(0xc19+1942-0x13af);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1c92+2234-0x254c));}ssSetNumInputPorts(S,z53e64be319);for(i=(0xdd3+4692-0x2027);i<z53e64be319;i++){ssSetInputPortDirectFeedThrough(S,i,(0x18cb+1677-0x1f57));ssSetInputPortRequiredContiguous(S,i,(0x1514+3445-0x2288));ssSetInputPortWidth(S,i,(0x884+1865-0xfcc));ssSetInputPortDataType(S,i,SS_DOUBLE);}ssSetNumOutputPorts(S,zdf898925a0);for(i=(0xd93+176-0xe43);i<zdf898925a0;i++){ssSetOutputPortWidth(S,i,(0x979+6280-0x2200));ssSetOutputPortDataType(S,i,SS_DOUBLE);}ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x985+3122-0x15b7),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x385+8052-0x22f9),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;

volatile struct z9352458a7e*z9352458a7e;uint32_T za7955ec6a8,zff5052694c,zff7c8b7bc1,z98c80f24a4,z3f5031a403,zf6535a176c,i,ze21a704653,zf2baf4f000;
if((int_T)mxGetPr(z702a26a5e9)[(0x65a+5624-0x1c52)]<(0x473+4653-0x16a0)){if(xpcGetPCIDeviceInfo(z694756a014,zea87e0ba83,z29146a1837,zab7e64468b,XPC_NO_BUS_SLOT,XPC_NO_BUS_SLOT,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x1ce1+1858-0x2422)){z366b2f03bf=(0x10f0+220-0x11cc);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x61+1885-0x7be)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x118d+1905-0x18fe)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x15a9+3442-0x231a)];}if(xpcGetPCIDeviceInfo(z694756a014,zea87e0ba83,z29146a1837,zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}
zeccbadd9b3.VirtAddress[(0x1211+4360-0x2319)]=(uint32_T*)xpcReserveMemoryRegion((uint32_T*)zeccbadd9b3.BaseAddress[(0x2507+73-0x2550)],zeccbadd9b3.Length[(0xd9+1878-0x82f)],XPC_RT_PG_USERREADWRITE);z9352458a7e=(struct z9352458a7e*)(zeccbadd9b3.VirtAddress[(0xd91+5802-0x243b)]);
ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x12f6+197-0x13bb)]);
#ifdef z95773b8cb8
xpcShowPCIDeviceInfo(&zeccbadd9b3);
#endif

za7955ec6a8=(0x3d8+5676-0x1a04);zff5052694c=(0x34d+4235-0x13d8);for(i=(0xb4a+450-0xd0c);i<(0x1101+4587-0x22e4);i++){if((uint32_T)mxGetPr(z0254f95f00)[i]==OUTPUT){za7955ec6a8=za7955ec6a8|((0x1dd0+2015-0x25ae)<<i);}if((uint32_T)mxGetPr(zb9dba6d10d)[i]==OUTPUT){zff5052694c=zff5052694c|((0x5c4+1677-0xc50)<<(i+(0xe82+952-0x1232)));}}z9352458a7e->zf634560d60=zff5052694c|za7955ec6a8;
z3f5031a403=(0x350+8625-0x2501);zf6535a176c=(0xfb0+4093-0x1fad);zff7c8b7bc1=(0x2dc+8242-0x230e);z98c80f24a4=(0x1217+3841-0x2118);for(i=(0x9e4+2644-0x1438);i<(0x163+1361-0x6ac);i++){z3f5031a403=(uint32_T)mxGetPr(z6e5257a7ba)[i];zf6535a176c=(uint32_T)mxGetPr(z6a4eaeb2e3)[i];zff7c8b7bc1=zff7c8b7bc1|(z3f5031a403<<(i*(0xe8a+1142-0x12fe)));z98c80f24a4=z98c80f24a4|(zf6535a176c<<((i*(0x1bab+414-0x1d47))+(0x2295+990-0x2663)));}z9352458a7e->z38a734997e=z98c80f24a4|zff7c8b7bc1;
if((uint32_T)mxGetPr(z233ae8e23f)[(0x9ab+6024-0x2133)]==zd5722e7b54){ze21a704653=(uint32_T)mxGetPr(zfe38cda72c)[(0x336+8397-0x2403)];switch(ze21a704653){case z82ac25ee68:z9352458a7e->zfcf290ae65=z9352458a7e->zfcf290ae65|z39451a5d37;break;case zde7deffb36:z9352458a7e->zfcf290ae65=z9352458a7e->zfcf290ae65&z1491003f50;break;default:
break;}}else{z9352458a7e->zfcf290ae65=z9352458a7e->zfcf290ae65&z1491003f50;}if((uint32_T)mxGetPr(z6c3b90de1b)[(0x1744+2277-0x2029)]==zbd6eb35fcd){zf2baf4f000=(uint32_T)mxGetPr(za1d8e89e0e)[(0xe65+5327-0x2334)];switch(zf2baf4f000){case z82ac25ee68:z9352458a7e->zfcf290ae65=z9352458a7e->zfcf290ae65|zb0da4813e4;break;case zde7deffb36:z9352458a7e->zfcf290ae65=z9352458a7e->zfcf290ae65&z0a23ad657d;break;default:
break;}}else{z9352458a7e->zfcf290ae65=z9352458a7e->zfcf290ae65&z0a23ad657d;}if(xpcIsModelInit()==(0xb0a+1317-0x102e))
{}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){volatile struct z9352458a7e*z9352458a7e=(struct z9352458a7e*)ssGetIWorkValue(S,z6a0da049de);
#ifndef MATLAB_MEX_FILE
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
uint32_T zcf073e63e1,z8bbfae7122;uint16_T z0772b57a3b;volatile struct z9352458a7e*z9352458a7e=(struct z9352458a7e*)ssGetIWorkValue(S,z6a0da049de);

zcf073e63e1=z9352458a7e->z84bb67aac4.z7f3e6de1c9;z8bbfae7122=z9352458a7e->z84bb67aac4.zc8d0c471e2;for(z0772b57a3b=(0x4b0+2845-0xfcd);z0772b57a3b<(0xb70+2691-0x15b3);z0772b57a3b++){if(z0772b57a3b<(0x5a9+1458-0xb3b)){if(xpceIsModelInit()||(uint32_T)mxGetPr(z44d8a68c1a)[z0772b57a3b]){if((uint32_T)mxGetPr(z0e6f76218d)[z0772b57a3b]>=THRESHOLD){zcf073e63e1=zcf073e63e1|((0xacf+1044-0xee2)<<z0772b57a3b);}else{zcf073e63e1=zcf073e63e1&(~((0x9c8+38-0x9ed)<<z0772b57a3b));}}}else{if(xpceIsModelInit()||(uint32_T)mxGetPr(z44d8a68c1a)[z0772b57a3b]){if((uint32_T)mxGetPr(z0e6f76218d)[z0772b57a3b]>=THRESHOLD){z8bbfae7122=z8bbfae7122|((0x843+5606-0x1e28)<<(z0772b57a3b-(0xc5f+675-0xee2)));}else{z8bbfae7122=z8bbfae7122&(~((0x20d8+1341-0x2614)<<(z0772b57a3b-(0x1776+2552-0x214e))));}}}}z9352458a7e->z84bb67aac4.z7f3e6de1c9=zcf073e63e1;z9352458a7e->z84bb67aac4.zc8d0c471e2=z8bbfae7122;
zcf073e63e1=z9352458a7e->z84bb67aac4.zf555a21781;z8bbfae7122=z9352458a7e->z84bb67aac4.ze863a41864;for(z0772b57a3b=(0x28a+3024-0xe5a);z0772b57a3b<(0xde0+1318-0x12c6);z0772b57a3b++){if(z0772b57a3b<(0x909+688-0xb99)){if(xpceIsModelInit()||(uint32_T)mxGetPr(zfc25efb894)[z0772b57a3b]){if((uint32_T)mxGetPr(z0f3b626370)[z0772b57a3b]>=THRESHOLD){zcf073e63e1=zcf073e63e1|((0x2121+1470-0x26de)<<z0772b57a3b);}else{zcf073e63e1=zcf073e63e1&(~((0xd5+3190-0xd4a)<<z0772b57a3b));}}}else{if(xpceIsModelInit()||(uint32_T)mxGetPr(zfc25efb894)[z0772b57a3b]){if((uint32_T)mxGetPr(z0f3b626370)[z0772b57a3b]>=THRESHOLD){z8bbfae7122=z8bbfae7122|((0x64d+1028-0xa50)<<(z0772b57a3b-(0x136+5337-0x15ef)));}else{z8bbfae7122=z8bbfae7122&(~((0x18d3+258-0x19d4)<<(z0772b57a3b-(0x148b+556-0x1697))));}}}}z9352458a7e->z84bb67aac4.zf555a21781=zcf073e63e1;z9352458a7e->z84bb67aac4.ze863a41864=z8bbfae7122;z9352458a7e->z96d6777a46=z68703d0a39;
#endif 
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

