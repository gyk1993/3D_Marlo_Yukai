/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x8a5+2041-0x109c)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO422_lvdt_write_s
#include 	<stddef.h>
#include 	<stdlib.h>
#include 	"simstruc.h" 
#ifdef 		MATLAB_MEX_FILE
#include 	"mex.h"
#endif
#ifndef         MATLAB_MEX_FILE
#include        <windows.h>
#include        "io_xpcimport.h"
#include        "pci_xpcimport.h"
#include        "time_xpcimport.h"
#include        "ioext_xpcimport.h"
#include        "util_xpcimport.h"
#endif
#define zdf24515981              ((0x8ba+5135-0x1cbd))
#define za9d8fb6bcf                 ssGetSFcnParam(S, (0xf9a+483-0x117d))
#define z86992bd6b1                 ssGetSFcnParam(S, (0x458+3129-0x1090)) 
#define za80bdf5015            ssGetSFcnParam(S, (0x2dd+1240-0x7b3))
#define z1e1f908411           ssGetSFcnParam(S, (0xe48+3466-0x1bcf))
#define z8d12cdfdee          ssGetSFcnParam(S, (0xa13+2924-0x157b))
#define z8f32a49296              ssGetSFcnParam(S, (0xfdb+4394-0x2100))
#define zb377f6022b              ssGetSFcnParam(S, (0xb74+6120-0x2356))
#define zf8013dab26              ssGetSFcnParam(S, (0x14b1+3672-0x2302))
#define za7e979a45c              ssGetSFcnParam(S, (0x9c2+3203-0x163d))
#define z7763d247aa            ssGetSFcnParam(S, (0x1253+2797-0x1d37))
#define z3832b85a32               ssGetSFcnParam(S, (0x8f+3247-0xd34))
#define z702a26a5e9                    ssGetSFcnParam(S, (0x71b+7625-0x24d9))  
#define z2e6483d505              ((0xda1+4531-0x1f52))
#define z7e2eeaa57c          ((0xaf6+4236-0x1b82))
#define z6a0da049de         ((0x900+4012-0x18ab))
#define zc5ce4cb81a              ((0x500+7510-0x2246))
#define z2b17e2ee3b              ((0x23af+551-0x25d6))
#define z7b38f83bd1          (0.0000000004656612873077390)
static char_T zea4cd01646[(0x433+990-0x711)];static void mdlInitializeSizes(SimStruct*S){uint32_T i,z094c0030e8;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x12e6+3621-0x210b));ssSetNumDiscStates(S,(0x87b+6909-0x2378));ssSetNumInputPorts(S,mxGetN(za9d8fb6bcf));for(i=(0xc8f+2046-0x148d);i<mxGetN(za9d8fb6bcf);i++){ssSetInputPortWidth(S,i,(0x722+5830-0x1de7));ssSetInputPortDataType(S,i,SS_DOUBLE);ssSetInputPortDirectFeedThrough(S,i,(0x1d4d+220-0x1e28));ssSetInputPortRequiredContiguous(S,i,(0x1165+827-0x149f));}z094c0030e8=(0xb09+1967-0x12b8);if((uint32_T)mxGetPr(za80bdf5015)[(0x855+6218-0x209f)]){z094c0030e8++;}if((uint32_T)mxGetPr(z1e1f908411)[(0x5bc+7770-0x2416)]){z094c0030e8++;}if((uint32_T)mxGetPr(z8d12cdfdee)[(0x7db+3739-0x1676)]){z094c0030e8++;}if((uint32_T)mxGetPr(z8f32a49296)[(0x8bb+1032-0xcc3)]){z094c0030e8++;}ssSetNumOutputPorts(S,z094c0030e8);for(i=(0xb81+4939-0x1ecc);i<z094c0030e8;i++){if((uint32_T)mxGetPr(z8f32a49296)[(0x1c7c+1958-0x2422)]&&i==z094c0030e8-(0x24c6+237-0x25b2)){ssSetOutputPortWidth(S,i,(0x1683+613-0x18e4));ssSetOutputPortDataType(S,i,SS_DOUBLE);}else{ssSetOutputPortWidth(S,i,(uint32_T)mxGetN(za9d8fb6bcf));ssSetOutputPortDataType(S,i,SS_DOUBLE);}}ssSetNumSampleTimes(S,(0x393+6256-0x1c02));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1125+2308-0x1a29));ssSetNumNonsampledZCs(S,(0xf9b+3644-0x1dd7));for(i=(0xafd+688-0xdad);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1083+190-0x1141));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0xed4+5730-0x2536)]==-1.0){ssSetSampleTime(S,(0x1c75+367-0x1de4),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x2c5+9170-0x2697),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0xcbc+4937-0x2005),mxGetPr(z3832b85a32)[(0x1f5+7619-0x1fb8)]);ssSetOffsetTime(S,(0x1286+1414-0x180c),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint16_T*za42cf7dd4a;uint16_T z6f813cde47,za4a2434e08;uint32_T i,z4e3026977c,z4da0d16710,val;uint16_T zd0072007fc;real_T z19c4ca5f82,start;za4a2434e08=30099;z6f813cde47=5548;if((int_T)mxGetPr(z702a26a5e9)[(0xf18+3908-0x1e5c)]<(0x1575+3828-0x2469)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x49\x4f\x34\x32\x32\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74\x2e");ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x1a1+975-0x56f)){z366b2f03bf=(0x1362+4542-0x2520);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1c27+279-0x1d3e)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x812+7282-0x2484)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x621+3230-0x12be)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x1223+4131-0x2147))|((z366b2f03bf&(0x18c1+3613-0x25df))<<(0x1423+2828-0x1f27)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x49\x4f\x34\x32\x32\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74\x2e",z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0xf0b+1720-0x15c3)];Virtual=rl32eGetDevicePtr(z1cf2c50191,32768,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint16_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);if(xpceIsModelInit()){switch((uint32_T)mxGetPr(z86992bd6b1)[(0xa3b+3965-0x19b8)]){case(0x80b+77-0x857):zd0072007fc=(0x768+777-0xa71);break;case(0xfc2+1031-0x13c7):zd0072007fc=(0x113a+415-0xad9);break;case(0xb1f+5753-0x2195):zd0072007fc=(0x2012+5874-0x2704);break;}
z4da0d16710=(0x1bc+8634-0x2376);for(i=(0x637+2109-0xe74);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x16d9+1599-0x1d17);z4da0d16710|=((0xc27+2875-0x1761)<<z4e3026977c);}
za42cf7dd4a[zd0072007fc/(0x17d4+2930-0x2344)+(0x16e3+2221-0x1df8)/(0x1400+1936-0x1b8e)]=(0x109b+1971-0x1839);
za42cf7dd4a[zd0072007fc/(0xeb7+5960-0x25fd)+(0xaf3+1624-0xfbf)/(0x1699+1269-0x1b8c)]=(0xd02+3094-0x1918);
za42cf7dd4a[zd0072007fc/(0x510+8514-0x2650)+(0x19ec+2321-0x2135)/(0x61f+882-0x98f)]=z4da0d16710;
for(i=(0x1025+3305-0x1d0e);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1ac+2916-0xd0f);
val=(uint32_T)(mxGetPr(zb377f6022b)[i]*(0xc1d+1148-0x1035));za42cf7dd4a[zd0072007fc/(0x1d05+623-0x1f72)+(0x7e0+8078-0x262e)/(0x1dd+3165-0xe38)+z4e3026977c*(0x5d5+6970-0x210b)]=val&65535;
za42cf7dd4a[zd0072007fc/(0xc6d+2967-0x1802)+(0x15f+6764-0x1a87)/(0x8e9+6229-0x213c)+z4e3026977c*(0x1b38+2017-0x2315)]=(val>>(0x11dd+2982-0x1d73))&65535;}
for(i=(0x1346+756-0x163a);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1058+4264-0x20ff);
val=(uint32_T)(mxGetPr(zf8013dab26)[i]*(0xf4f+1525-0x14e0));za42cf7dd4a[zd0072007fc/(0x4a9+3632-0x12d7)+(0x1d26+2161-0x2437)/(0x451+1602-0xa91)+z4e3026977c*(0x9ef+6081-0x21ac)]=val&65535;
za42cf7dd4a[zd0072007fc/(0xa51+4172-0x1a9b)+(0x265+1690-0x79b)/(0x408+8128-0x23c6)+z4e3026977c*(0x1171+3230-0x1e0b)]=(val>>(0x1d4+296-0x2ec))&65535;}
for(i=(0xc13+1659-0x128e);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x2cd+4067-0x12af);val=(uint32_T)(mxGetPr(zb377f6022b)[i]*(0x8ad+3262-0x1507)*0.9);za42cf7dd4a[zd0072007fc/(0xa95+363-0xbfe)+(0x157d+3347-0x2204)/(0x6ab+5994-0x1e13)+z4e3026977c*(0x6cb+5738-0x1d33)]=val;}
for(i=(0x400+1551-0xa0f);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x8f9+2808-0x13f0);val=(uint32_T)(mxGetPr(zf8013dab26)[i]*(0x779+558-0x943)*0.9);za42cf7dd4a[zd0072007fc/(0x690+8133-0x2653)+(0x821+7020-0x230d)/(0xad1+251-0xbca)+z4e3026977c*(0xd0d+3351-0x1a22)]=val;}
val=(uint32_T)(mxGetPr(z7763d247aa)[i]*(0x1b32+1913-0x2247));
za42cf7dd4a[zd0072007fc/(0x1659+3535-0x2426)+(0x1d96+1630-0x20bc)/(0x251+8722-0x2461)]=val&65535;
za42cf7dd4a[zd0072007fc/(0x548+1305-0xa5f)+(0x19f9+733-0x199a)/(0x85d+7401-0x2544)]=(val>>(0xc87+3966-0x1bf5))&65535;val=(uint32_T)(mxGetPr(za7e979a45c)[i]*(0x91f+4202-0x1925));
za42cf7dd4a[zd0072007fc/(0x10c0+5102-0x24ac)+(0x3cb+6584-0x1a53)/(0x38b+3084-0xf95)]=val&65535;
za42cf7dd4a[zd0072007fc/(0xa75+112-0xae3)+(0x185a+2371-0x1e69)/(0xa36+1161-0xebd)]=(val>>(0xbdb+3374-0x18f9))&65535;printf("\x57\x61\x69\x74\x20\x32\x20\x73\x65\x63\x6f\x6e\x64\x73\x20\x74\x6f\x20\x70\x68\x61\x73\x65\x20\x6c\x6f\x63\x6b\x20\x77\x69\x74\x68\x20\x74\x68\x65\x20\x72\x65\x66\x65\x72\x65\x6e\x63\x65\x2e" "\n");xpcBusyWait((0x1d84+2237-0x263f));for(i=(0xb7c+1689-0x1215);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x9ed+3177-0x1655);
za42cf7dd4a[zd0072007fc/(0xd3b+5125-0x213e)+(0xa96+1370-0xcf0)/(0x1151+5197-0x259c)+z4e3026977c*(0x925+3328-0x1621)]=(0x1470+4132-0x2494);
za42cf7dd4a[zd0072007fc/(0xc8+1873-0x817)+(0x16b0+2368-0x1cec)/(0x421+6274-0x1ca1)+z4e3026977c*(0x11db+904-0x155f)]=(0x1b0c+2665-0x2575);}val=za42cf7dd4a[zd0072007fc/(0x10d+8658-0x22dd)+(0x187f+3775-0x268e)/(0x1478+2444-0x1e02)];xpcBusyWait(0.05);if(val){printf("\x53\x69\x67\x6e\x61\x6c\x20\x6c\x6f\x73\x73\x20\x73\x74\x61\x74\x75\x73\x3a\x20\x30\x78\x25\x58" "\n",val);}val=za42cf7dd4a[zd0072007fc/(0xefc+639-0x1179)+(0x79a+3756-0x147a)/(0x15bf+3958-0x2533)];xpcBusyWait(0.05);if(val){printf("\x52\x65\x66\x65\x72\x65\x6e\x63\x65\x20\x6c\x6f\x73\x73\x20\x73\x74\x61\x74\x75\x73\x3a\x20\x30\x78\x25\x58" "\n",val);}val=za42cf7dd4a[zd0072007fc/(0xfb+339-0x24c)+(0x17e7+5231-0x2556)/(0x9c+4056-0x1072)];xpcBusyWait(0.05);if(val){printf("\x42\x49\x54\x20\x6c\x6f\x73\x73\x20\x73\x74\x61\x74\x75\x73\x3a\x20\x30\x78\x25\x58" "\n",val);}val=za42cf7dd4a[zd0072007fc/(0x14d6+2005-0x1ca9)+(0xd79+1222-0x106f)/(0x117c+4888-0x2492)];xpcBusyWait(0.05);if(val){printf("\x50\x68\x61\x73\x65\x20\x6c\x6f\x73\x73\x20\x73\x74\x61\x74\x75\x73\x3a\x20\x30\x78\x25\x58" "\n",za42cf7dd4a[zd0072007fc/(0x36a+3402-0x10b2)+(0x1100+5130-0x233a)/(0xd1+8041-0x2038)]);}printf("\x42\x75\x69\x6c\x74\x2d\x69\x6e\x20\x74\x65\x73\x74\x73\x20\x61\x72\x65\x20\x69\x6e\x69\x74\x69\x61\x74\x65\x64" "\n");if(za42cf7dd4a[zd0072007fc/(0x1722+3939-0x2683)+(0x504+1989-0xb49)/(0x7d4+623-0xa41)]!=(0x1099+1730-0x1757)){za42cf7dd4a[zd0072007fc/(0x1d71+1642-0x23d9)+(0x1a23+956-0x1c5f)/(0x4cd+6028-0x1c57)]=(0x2cd+6790-0x1d4f);za42cf7dd4a[zd0072007fc/(0x1f66+721-0x2235)+(0xff4+5842-0x253e)/(0x33f+7530-0x20a7)]=(0x285+8425-0x236e);start=rl32eGetTicksDouble();while(za42cf7dd4a[zd0072007fc/(0x733+1359-0xc80)+(0x1cf+6134-0x183d)/(0x1f7+8500-0x2329)]!=(0xe08+2369-0x16f4)){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*1.0)
{sprintf(zea4cd01646,"\x49\x4f\x34\x32\x32\x3a\x20\x54\x65\x73\x74\x20\x44\x32\x20\x66\x61\x69\x6c\x65\x64");ssSetErrorStatus(S,zea4cd01646);return;}}
}za42cf7dd4a[zd0072007fc/(0x1254+2692-0x1cd6)+(0x26a+5286-0x1550)/(0x1334+1883-0x1a8d)]=(0x1705+867-0x1a67);printf("\x44\x4c\x56\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x65\x64\x20\x28\x73\x6c\x6f\x74\x3a\x20\x25\x64\x29\x2e" "\n",(uint32_T)mxGetPr(z86992bd6b1)[(0x5b7+7414-0x22ad)]);}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE   
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint16_T*za42cf7dd4a;uint16_T zd0072007fc;int32_T z63603eed4c;uint32_T z095c8f6c33;uint32_T i,z4e3026977c,z094c0030e8;real_T*in,*out;real_T position;za42cf7dd4a=(void*)base;switch((uint32_T)mxGetPr(z86992bd6b1)[(0x1777+3678-0x25d5)]){case(0x1d73+1540-0x2376):zd0072007fc=(0xc1f+360-0xd87);break;case(0xba1+5914-0x22b9):zd0072007fc=(0x16f0+4347-0x1feb);break;case(0x556+5426-0x1a85):zd0072007fc=(0x1418+1372-0x974);break;}for(i=(0x76d+4476-0x18e9);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x156+6009-0x18ce);in=(real_T*)ssGetInputPortSignal(S,i);position=in[(0x18+227-0xfb)];if(position>=1.0){position=1.0-z7b38f83bd1;}if(position<-1.0){position=-1.0;}z095c8f6c33=(int32_T)(position/z7b38f83bd1);za42cf7dd4a[zd0072007fc/(0x6+9501-0x2521)+(0x4df+157-0x27c)/(0x158d+855-0x18e2)+z4e3026977c*(0x64d+1772-0xd35)]=(uint16_T)(z095c8f6c33&65535);za42cf7dd4a[zd0072007fc/(0x14af+1429-0x1a42)+(0x508+9264-0x2634)/(0x18ad+1784-0x1fa3)+z4e3026977c*(0x25c+7726-0x2086)]=(uint16_T)((z095c8f6c33>>(0xee0+4972-0x223c))&65535);}z094c0030e8=(0x21e2+964-0x25a6);if((uint32_T)mxGetPr(za80bdf5015)[(0x342+2236-0xbfe)]){out=(real_T*)ssGetOutputPortSignal(S,z094c0030e8);for(i=(0x789+5359-0x1c78);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x508+1223-0x9ce);z63603eed4c=(uint16_T)za42cf7dd4a[zd0072007fc/(0xe08+4946-0x2158)+(0x1cc4+1867-0x240f)+z4e3026977c*(0xc57+5921-0x2374)+(0x145a+583-0x169f)];
z63603eed4c=z63603eed4c<<(0x14+5916-0x1720);z63603eed4c|=(uint16_T)za42cf7dd4a[zd0072007fc/(0x2000+1094-0x2444)+(0x227+2846-0xd45)+z4e3026977c*(0x255+439-0x408)];out[i]=(real_T)z63603eed4c*z7b38f83bd1;}z094c0030e8++;}if((uint32_T)mxGetPr(z1e1f908411)[(0x1e76+1107-0x22c9)]){out=(real_T*)ssGetOutputPortSignal(S,z094c0030e8);for(i=(0x1d54+1870-0x24a2);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1a14+227-0x1af6);out[i]=za42cf7dd4a[zd0072007fc/(0x254+2270-0xb30)+(0x237a+286-0x2400)/(0x989+5398-0x1e9d)+z4e3026977c*(0x15a1+124-0x161b)];}z094c0030e8++;}if((uint32_T)mxGetPr(z8d12cdfdee)[(0x6b1+3574-0x14a7)]){out=(real_T*)ssGetOutputPortSignal(S,z094c0030e8);for(i=(0x52f+686-0x7dd);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x4e1+293-0x605);out[i]=za42cf7dd4a[zd0072007fc/(0xc58+2897-0x17a7)+(0x1195+19-0x1144)/(0x516+2419-0xe87)+z4e3026977c*(0x111b+2629-0x1b5e)];}z094c0030e8++;}if((uint32_T)mxGetPr(z8f32a49296)[(0x10b4+2822-0x1bba)]){out=(real_T*)ssGetOutputPortSignal(S,z094c0030e8);out[(0x1ab+1572-0x7cf)]=za42cf7dd4a[zd0072007fc/(0x1982+242-0x1a72)+(0x894+407-0x97b)/(0x4f8+6686-0x1f14)];out[(0x1bf1+2299-0x24eb)]=za42cf7dd4a[zd0072007fc/(0x1549+17-0x1558)+(0xc67+3464-0x1823)/(0x1983+3056-0x2571)];out[(0x108d+2831-0x1b9a)]=za42cf7dd4a[zd0072007fc/(0xaaf+469-0xc82)+(0xadc+2808-0xed4)/(0x27f+7388-0x1f59)];out[(0x1361+1052-0x177a)]=za42cf7dd4a[zd0072007fc/(0x10fa+3345-0x1e09)+(0x1f69+2274-0x267b)/(0x1ba7+1601-0x21e6)];z094c0030e8++;}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE    
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint16_T*za42cf7dd4a;za42cf7dd4a=(void*)base;
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

