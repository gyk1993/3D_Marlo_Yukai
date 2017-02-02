/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x196+9410-0x2656)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO421_lvdt_write_s
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
#define zdf24515981              ((0xf81+2496-0x1937))
#define za9d8fb6bcf                 ssGetSFcnParam(S, (0x117d+3553-0x1f5e))
#define z86992bd6b1                 ssGetSFcnParam(S, (0x22d5+1061-0x26f9)) 
#define za80bdf5015            ssGetSFcnParam(S, (0x5e0+2763-0x10a9))
#define z1e1f908411           ssGetSFcnParam(S, (0x385+3695-0x11f1))
#define z8d12cdfdee          ssGetSFcnParam(S, (0x1648+2701-0x20d1))
#define z8f32a49296              ssGetSFcnParam(S, (0x1156+4761-0x23ea))
#define zb377f6022b              ssGetSFcnParam(S, (0x65d+5001-0x19e0))
#define zf8013dab26              ssGetSFcnParam(S, (0xde8+3303-0x1ac8))
#define z3832b85a32               ssGetSFcnParam(S, (0x3fb+1179-0x88e))
#define z702a26a5e9                    ssGetSFcnParam(S, (0x17f8+245-0x18e4))  
#define z2e6483d505              ((0x7a5+6896-0x2293))
#define z7e2eeaa57c          ((0x1875+393-0x19fe))
#define z6a0da049de         ((0x1ee8+11-0x1ef2))
#define zc5ce4cb81a              ((0x602+7245-0x223f))
#define z2b17e2ee3b              ((0x22df+869-0x2644))
#define z7b38f83bd1          (0.0000000004656612873077390)
static char_T zea4cd01646[(0xb59+5898-0x2163)];static void mdlInitializeSizes(SimStruct*S){uint32_T i,z094c0030e8;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x16b3+4168-0x26fb));ssSetNumDiscStates(S,(0x188+7667-0x1f7b));ssSetNumInputPorts(S,mxGetN(za9d8fb6bcf));for(i=(0xb73+443-0xd2e);i<mxGetN(za9d8fb6bcf);i++){ssSetInputPortWidth(S,i,(0x14f2+454-0x16b7));ssSetInputPortDataType(S,i,SS_DOUBLE);ssSetInputPortDirectFeedThrough(S,i,(0x19b7+365-0x1b23));ssSetInputPortRequiredContiguous(S,i,(0x486+6786-0x1f07));}z094c0030e8=(0x1e5+7396-0x1ec9);if((uint32_T)mxGetPr(za80bdf5015)[(0xa8c+5007-0x1e1b)]){z094c0030e8++;}if((uint32_T)mxGetPr(z1e1f908411)[(0x1c5a+484-0x1e3e)]){z094c0030e8++;}if((uint32_T)mxGetPr(z8d12cdfdee)[(0x730+3837-0x162d)]){z094c0030e8++;}if((uint32_T)mxGetPr(z8f32a49296)[(0x308+6359-0x1bdf)]){z094c0030e8++;}ssSetNumOutputPorts(S,z094c0030e8);for(i=(0x5eb+2133-0xe40);i<z094c0030e8;i++){if((uint32_T)mxGetPr(z8f32a49296)[(0x2619+112-0x2689)]&&i==z094c0030e8-(0x1c72+600-0x1ec9)){ssSetOutputPortWidth(S,i,(0x4e6+6060-0x1c8e));ssSetOutputPortDataType(S,i,SS_DOUBLE);}else{ssSetOutputPortWidth(S,i,(uint32_T)mxGetN(za9d8fb6bcf));ssSetOutputPortDataType(S,i,SS_DOUBLE);}}ssSetNumSampleTimes(S,(0xa69+1111-0xebf));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x453+3010-0x1015));ssSetNumNonsampledZCs(S,(0x21c4+917-0x2559));for(i=(0x911+3178-0x157b);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xa54+375-0xbcb));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x721+4089-0x171a)]==-1.0){ssSetSampleTime(S,(0x3c4+4372-0x14d8),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x388+8792-0x25e0),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x119f+735-0x147e),mxGetPr(z3832b85a32)[(0x117c+4414-0x22ba)]);ssSetOffsetTime(S,(0x321+9024-0x2661),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint16_T*za42cf7dd4a;uint16_T z6f813cde47,za4a2434e08;uint32_T i,z4e3026977c,z4da0d16710,val;uint16_T zd0072007fc;real_T z19c4ca5f82,start;za4a2434e08=30354;z6f813cde47=5548;if((int_T)mxGetPr(z702a26a5e9)[(0x158a+610-0x17ec)]<(0x8f2+3420-0x164e)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x49\x4f\x34\x32\x31\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74\x2e");ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xae1+4089-0x1ad9)){z366b2f03bf=(0x13c+3784-0x1004);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xef7+404-0x108b)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0xb31+1508-0x1115)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x74d+3822-0x163a)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0xd98+1610-0x12e3))|((z366b2f03bf&(0x941+6573-0x21ef))<<(0x1c01+1630-0x2257)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x49\x4f\x34\x32\x32\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74\x2e",z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x39f+3106-0xfc1)];Virtual=rl32eGetDevicePtr(z1cf2c50191,32768,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint16_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);if(xpceIsModelInit()){switch((uint32_T)mxGetPr(z86992bd6b1)[(0x1895+2982-0x243b)]){case(0x639+1664-0xcb8):zd0072007fc=(0x1bc+289-0x2dd);break;case(0x4e6+3664-0x1334):zd0072007fc=(0x1364+2242-0x1426);break;case(0x1178+583-0x13bc):zd0072007fc=4096;break;}
z4da0d16710=(0xc8b+1474-0x124d);for(i=(0x13ed+3734-0x2283);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x2ff+8221-0x231b);z4da0d16710|=((0x4df+3570-0x12d0)<<z4e3026977c);}
za42cf7dd4a[zd0072007fc/(0x3fd+4095-0x13fa)+(0x2dd+5455-0x1694)/(0x1d4+5381-0x16d7)]=(0x854+6387-0x2132);
za42cf7dd4a[zd0072007fc/(0x1ae6+2635-0x252f)+(0x8fd+5974-0x1ec7)/(0x694+1881-0xdeb)]=(0x1a50+2105-0x2289);
za42cf7dd4a[zd0072007fc/(0xee2+4361-0x1fe9)+(0x1a0a+2431-0x21c1)/(0x1233+363-0x139c)]=z4da0d16710;
for(i=(0x20a6+343-0x21fd);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x87d+5066-0x1c46);
val=(uint32_T)(mxGetPr(zb377f6022b)[i]*(0x938+1264-0xdc4));za42cf7dd4a[zd0072007fc/(0x632+5937-0x1d61)+(0x1977+1121-0x1c98)/(0x143b+1239-0x1910)+z4e3026977c*(0xd13+2388-0x1663)]=val&65535;
za42cf7dd4a[zd0072007fc/(0x118+6405-0x1a1b)+(0x393+7118-0x1e1d)/(0x7a8+4242-0x1838)+z4e3026977c*(0xaec+5526-0x207e)]=(val>>(0x16b3+17-0x16b4))&65535;}
for(i=(0x17e7+3597-0x25f4);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x12e4+3558-0x20c9);
val=(uint32_T)(mxGetPr(zf8013dab26)[i]*(0xa0f+5114-0x1da5));za42cf7dd4a[zd0072007fc/(0x1454+4174-0x24a0)+(0x652+1656-0xb6a)/(0x4d5+8054-0x2449)+z4e3026977c*(0x836+2801-0x1323)]=val&65535;
za42cf7dd4a[zd0072007fc/(0xd2b+5269-0x21be)+(0x9e6+1968-0x1032)/(0x1159+1421-0x16e4)+z4e3026977c*(0xb01+1739-0x11c8)]=(val>>(0xddf+2639-0x181e))&65535;}
for(i=(0x881+5414-0x1da7);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x82c+3287-0x1502);val=(uint32_T)(mxGetPr(zb377f6022b)[i]*(0x9f2+6869-0x2463)*0.9);za42cf7dd4a[zd0072007fc/(0xa3b+1577-0x1062)+(0xec+3083-0xc6b)/(0x438+8740-0x265a)+z4e3026977c*(0x1b36+2679-0x25ab)]=val;}
for(i=(0x12c2+1509-0x18a7);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x7d8+6420-0x20eb);val=(uint32_T)(mxGetPr(zf8013dab26)[i]*(0x1001+2914-0x1aff)*0.9);za42cf7dd4a[zd0072007fc/(0x1817+1749-0x1eea)+(0x80a+5387-0x1c95)/(0x10d7+5163-0x2500)+z4e3026977c*(0xaf3+6425-0x240a)]=val;}za42cf7dd4a[zd0072007fc/(0xb2c+4613-0x1d2f)+(0xcfb+34-0xb5d)/(0x288+6145-0x1a87)]=(0x79c+4183-0x17f2);
printf("\x57\x61\x69\x74\x20\x32\x20\x73\x65\x63\x6f\x6e\x64\x73\x20\x74\x6f\x20\x70\x68\x61\x73\x65\x20\x6c\x6f\x63\x6b\x20\x77\x69\x74\x68\x20\x74\x68\x65\x20\x72\x65\x66\x65\x72\x65\x6e\x63\x65\x2e" "\n");xpcBusyWait((0x996+5339-0x1e6f));for(i=(0xfd5+829-0x1312);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1015+5055-0x23d3);
za42cf7dd4a[zd0072007fc/(0x519+5126-0x191d)+(0x681+5577-0x194a)/(0x1314+90-0x136c)+z4e3026977c*(0x1faf+1352-0x24f3)]=(0x601+8267-0x264c);
za42cf7dd4a[zd0072007fc/(0x665+6151-0x1e6a)+(0xfc5+913-0x1052)/(0xbea+6502-0x254e)+z4e3026977c*(0x396+960-0x752)]=(0x1879+22-0x188f);}val=za42cf7dd4a[zd0072007fc/(0x9d9+3831-0x18ce)+(0x1960+1697-0x1f51)/(0x1dd6+495-0x1fc3)];xpcBusyWait(0.05);if(val){printf("\x53\x69\x67\x6e\x61\x6c\x20\x6c\x6f\x73\x73\x20\x73\x74\x61\x74\x75\x73\x3a\x20\x30\x78\x25\x58" "\n",val);}val=za42cf7dd4a[zd0072007fc/(0xfbf+1931-0x1748)+(0x12b7+4913-0x241c)/(0x760+2561-0x115f)];xpcBusyWait(0.05);if(val){printf("\x52\x65\x66\x65\x72\x65\x6e\x63\x65\x20\x6c\x6f\x73\x73\x20\x73\x74\x61\x74\x75\x73\x3a\x20\x30\x78\x25\x58" "\n",val);}val=za42cf7dd4a[zd0072007fc/(0x969+2871-0x149e)+(0x861+6893-0x1c4e)/(0x674+4029-0x162f)];xpcBusyWait(0.05);if(val){printf("\x42\x49\x54\x20\x6c\x6f\x73\x73\x20\x73\x74\x61\x74\x75\x73\x3a\x20\x30\x78\x25\x58" "\n",val);}val=za42cf7dd4a[zd0072007fc/(0x1fb3+991-0x2390)+(0x1dd8+2365-0x2545)/(0x5da+178-0x68a)];xpcBusyWait(0.05);if(val){printf("\x50\x68\x61\x73\x65\x20\x6c\x6f\x73\x73\x20\x73\x74\x61\x74\x75\x73\x3a\x20\x30\x78\x25\x58" "\n",za42cf7dd4a[zd0072007fc/(0x20c+7148-0x1df6)+(0x8ef+7613-0x24dc)/(0x820+2573-0x122b)]);}printf("\x42\x75\x69\x6c\x74\x2d\x69\x6e\x20\x74\x65\x73\x74\x73\x20\x61\x72\x65\x20\x69\x6e\x69\x74\x69\x61\x74\x65\x64" "\n");if(za42cf7dd4a[zd0072007fc/(0x4ef+8184-0x24e5)+(0x34c+4270-0x127a)/(0x9ad+1452-0xf57)]!=(0xad9+4149-0x1b0a)){za42cf7dd4a[zd0072007fc/(0x1093+3749-0x1f36)+(0x7f2+1182-0xb10)/(0xa7d+4453-0x1be0)]=(0x1761+3670-0x25b3);za42cf7dd4a[zd0072007fc/(0x3d6+5118-0x17d2)+(0x1555+2903-0x1f24)/(0x14e0+268-0x15ea)]=(0xd98+3047-0x197f);start=rl32eGetTicksDouble();while(za42cf7dd4a[zd0072007fc/(0x46c+6429-0x1d87)+(0x33f+8936-0x249f)/(0xa36+6843-0x24ef)]!=(0x10a8+311-0x118a)){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*1.0)
{sprintf(zea4cd01646,"\x49\x4f\x34\x32\x32\x3a\x20\x54\x65\x73\x74\x20\x44\x32\x20\x66\x61\x69\x6c\x65\x64");ssSetErrorStatus(S,zea4cd01646);return;}}printf("\x42\x75\x69\x6c\x64\x20\x69\x6e\x20\x74\x65\x73\x74\x20\x72\x65\x73\x75\x6c\x74\x73\x3a\x20\x30\x78\x25\x58\x2e" "\n",za42cf7dd4a[zd0072007fc/(0x1112+176-0x11c0)+(0xd05+1321-0xb2e)/(0x1c23+1894-0x2387)]);}printf("\x44\x4c\x56\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x65\x64\x20\x28\x73\x6c\x6f\x74\x3a\x20\x25\x64\x29\x2e" "\n",(uint32_T)mxGetPr(z86992bd6b1)[(0x3a0+7941-0x22a5)]);}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE   
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint16_T*za42cf7dd4a;uint16_T zd0072007fc;int32_T z63603eed4c;uint32_T z095c8f6c33;uint32_T i,z4e3026977c,z094c0030e8;real_T*in,*out;real_T position;za42cf7dd4a=(void*)base;switch((uint32_T)mxGetPr(z86992bd6b1)[(0xeb9+5694-0x24f7)]){case(0x3a6+1318-0x8cb):zd0072007fc=(0x7ba+2211-0x105d);break;case(0x11d4+4100-0x21d6):zd0072007fc=(0x1157+6950-0x247d);break;case(0x19d+7066-0x1d34):zd0072007fc=(0x1941+1318-0xe67);break;}for(i=(0xf5f+5096-0x2347);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x13eb+760-0x16e2);in=(real_T*)ssGetInputPortSignal(S,i);position=in[(0x1395+1979-0x1b50)];if(position>=1.0){position=1.0-z7b38f83bd1;}if(position<-1.0){position=-1.0;}z095c8f6c33=(int32_T)(position/z7b38f83bd1);za42cf7dd4a[zd0072007fc/(0x2c0+6309-0x1b63)+(0xe21+5688-0x2159)/(0x67+7720-0x1e8d)+z4e3026977c*(0xfc5+5856-0x26a1)]=(uint16_T)(z095c8f6c33&65535);za42cf7dd4a[zd0072007fc/(0x1274+1676-0x18fe)+(0xfc4+5005-0x204d)/(0x1d77+1114-0x21cf)+z4e3026977c*(0x464+2158-0xcce)]=(uint16_T)((z095c8f6c33>>(0x2a6+2580-0xcaa))&65535);}z094c0030e8=(0x1a23+1803-0x212e);if((uint32_T)mxGetPr(za80bdf5015)[(0x5f3+2688-0x1073)]){out=(real_T*)ssGetOutputPortSignal(S,z094c0030e8);for(i=(0xcc3+469-0xe98);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xb2d+2174-0x13aa);z63603eed4c=(uint16_T)za42cf7dd4a[zd0072007fc/(0x44a+6464-0x1d88)+(0x20cf+23-0x20e6)+z4e3026977c*(0x6d9+4026-0x168f)+(0x1145+69-0x1188)];
z63603eed4c=z63603eed4c<<(0x1152+363-0x12ad);z63603eed4c|=(uint16_T)za42cf7dd4a[zd0072007fc/(0x12ab+1789-0x19a6)+(0x62d+3984-0x15bd)+z4e3026977c*(0x491+3333-0x1192)];out[i]=(real_T)z63603eed4c*z7b38f83bd1;}z094c0030e8++;}if((uint32_T)mxGetPr(z1e1f908411)[(0xa3+8158-0x2081)]){out=(real_T*)ssGetOutputPortSignal(S,z094c0030e8);for(i=(0x279+4725-0x14ee);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x3f6+4054-0x13cb);out[i]=za42cf7dd4a[zd0072007fc/(0x22fb+733-0x25d6)+(0x134c+2977-0x1e55)/(0xb4c+5568-0x210a)+z4e3026977c*(0x1f76+1222-0x243a)];}z094c0030e8++;}if((uint32_T)mxGetPr(z8d12cdfdee)[(0x770+120-0x7e8)]){out=(real_T*)ssGetOutputPortSignal(S,z094c0030e8);for(i=(0xea8+4377-0x1fc1);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xdf0+3497-0x1b98);out[i]=za42cf7dd4a[zd0072007fc/(0x268+4756-0x14fa)+(0x3a1+898-0x6bf)/(0xf0d+438-0x10c1)+z4e3026977c*(0x17df+1897-0x1f46)];}z094c0030e8++;}if((uint32_T)mxGetPr(z8f32a49296)[(0xb7b+3050-0x1765)]){out=(real_T*)ssGetOutputPortSignal(S,z094c0030e8);out[(0x2029+1616-0x2679)]=za42cf7dd4a[zd0072007fc/(0xddd+4238-0x1e69)+(0x1370+3955-0x2233)/(0xc36+1188-0x10d8)];out[(0x7c6+7246-0x2413)]=za42cf7dd4a[zd0072007fc/(0x6d9+7363-0x239a)+(0x1284+1767-0x179f)/(0x1ac0+645-0x1d43)];out[(0x10a0+3141-0x1ce3)]=za42cf7dd4a[zd0072007fc/(0xa98+6297-0x232f)+(0x15ed+3323-0x1be8)/(0x69b+553-0x8c2)];out[(0xb91+1358-0x10dc)]=za42cf7dd4a[zd0072007fc/(0xf66+237-0x1051)+(0x14a4+578-0x1516)/(0x631+6243-0x1e92)];z094c0030e8++;}
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

