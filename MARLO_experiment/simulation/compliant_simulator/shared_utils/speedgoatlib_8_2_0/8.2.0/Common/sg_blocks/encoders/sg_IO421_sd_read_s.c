/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x18b+4969-0x14f2)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO421_sd_read_s
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
#define zdf24515981              ((0x1869+199-0x1921))
#define za9d8fb6bcf                 ssGetSFcnParam(S,(0x3f5+5086-0x17d3))
#define z86992bd6b1                 ssGetSFcnParam(S,(0x153c+1561-0x1b54))
#define zab611d784e               ssGetSFcnParam(S,(0x16ef+3583-0x24ec))
#define zc6dd00a534         ssGetSFcnParam(S,(0x1df+9477-0x26e1))
#define z840ee59d27          ssGetSFcnParam(S,(0x14a4+3538-0x2272))
#define z6407e5c238                 ssGetSFcnParam(S,(0x8d7+4683-0x1b1d))
#define zd3c37ec5dd                 ssGetSFcnParam(S,(0x57b+5586-0x1b47))
#define z942f0304b7         ssGetSFcnParam(S,(0x1367+2071-0x1b77))
#define zb3e8c30072         ssGetSFcnParam(S,(0x1c19+2319-0x2520))
#define zd4b2dcc28a           ssGetSFcnParam(S,(0xddb+1937-0x1563))
#define z3350ecfebd         ssGetSFcnParam(S,(0x34f+691-0x5f8))
#define z329c06005c                  ssGetSFcnParam(S,(0x18c1+831-0x1bf5))
#define zc2f544da3c                   ssGetSFcnParam(S,(0x13ff+2811-0x1eee))
#define z3832b85a32               ssGetSFcnParam(S,(0x231+769-0x525))
#define z702a26a5e9                    ssGetSFcnParam(S,(0x9ca+2682-0x1436))
#define z2e6483d505              ((0xdd5+5567-0x2392))
#define z7e2eeaa57c          ((0x21a+6989-0x1d67))
#define z6a0da049de         ((0xb21+6858-0x25ea))
#define zc5ce4cb81a              ((0x2ed+1657-0x956))
#define z2b17e2ee3b              ((0x32d+3944-0x1295))
#define z293caa0fc3               (11.9209)
#define zc095f236bc               (190.7348)
#define z3c26710301                       (3.14159265358979)
#define zf582ac547e(x, zbcef5ca055)          (x < zbcef5ca055 ? zbcef5ca055 : x)
#define zddff81264d(x, z1a670ae0bc)          (x > z1a670ae0bc ? z1a670ae0bc : x)
#define zf2378c6436(x, zbcef5ca055, z1a670ae0bc)         (zf582ac547e(zddff81264d(x, z1a670ae0bc), zbcef5ca055))
#define z2a9dd6156b(x)         (zf2378c6436(x, z293caa0fc3, zc095f236bc))
static char_T zea4cd01646[(0xb60+979-0xe33)];static void mdlInitializeSizes(SimStruct*S){uint32_T i,zbc7ebd0e53;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x19a1+2476-0x234d));ssSetNumDiscStates(S,(0x18ab+3631-0x26da));zbc7ebd0e53=(0x222a+156-0x22c6);if((uint32_T)mxGetPr(z942f0304b7)[(0xf0c+1432-0x14a4)]){zbc7ebd0e53++;}if((uint32_T)mxGetPr(zb3e8c30072)[(0x17f2+3331-0x24f5)]){zbc7ebd0e53++;}if((uint32_T)mxGetPr(zd4b2dcc28a)[(0x82b+6228-0x207f)]){zbc7ebd0e53++;}ssSetNumOutputPorts(S,zbc7ebd0e53);for(i=(0x43a+2894-0xf88);i<zbc7ebd0e53;i++){ssSetOutputPortWidth(S,i,(uint32_T)mxGetN(za9d8fb6bcf));ssSetOutputPortDataType(S,i,SS_DOUBLE);}if((uint32_T)mxGetPr(z3350ecfebd)[(0x1a5a+2657-0x24bb)]){ssSetNumInputPorts(S,(0x239b+740-0x267e));ssSetInputPortWidth(S,(0x6a9+4301-0x1776),(uint32_T)mxGetN(za9d8fb6bcf));ssSetInputPortDataType(S,(0x1658+3614-0x2476),SS_DOUBLE);ssSetInputPortDirectFeedThrough(S,(0x3f5+2368-0xd35),(0x1a08+1407-0x1f86));ssSetInputPortRequiredContiguous(S,(0x2b0+7026-0x1e22),(0x1069+4342-0x215e));}else{ssSetNumInputPorts(S,(0x229+5375-0x1728));}ssSetNumSampleTimes(S,(0x1363+2685-0x1ddf));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x3b2+5336-0x188a));ssSetNumNonsampledZCs(S,(0x1e6f+541-0x208c));for(i=(0x7d8+277-0x8ed);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xaf0+4047-0x1abf));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x5f0+2267-0xecb)]==-1.0){ssSetSampleTime(S,(0xb75+5322-0x203f),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x3f4+6192-0x1c24),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x190a+1992-0x20d2),mxGetPr(z3832b85a32)[(0x164b+1213-0x1b08)]);ssSetOffsetTime(S,(0x18f0+1460-0x1ea4),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint16_T*za42cf7dd4a;uint16_T z6f813cde47,za4a2434e08;uint16_T z4e3026977c,value;uint16_T zd0072007fc;uint32_T i;real_T z7208ec02cc;za4a2434e08=30354;z6f813cde47=(0x2525+5762-0x25fb);if((int_T)mxGetPr(z702a26a5e9)[(0x119d+3348-0x1eb1)]<(0xa30+5329-0x1f01)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x5b\x53\x2f\x44\x5d\x20\x49\x4f\x34\x32\x31\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74");ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0xbba+3196-0x1835)){z366b2f03bf=(0x164b+2506-0x2015);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xee3+3775-0x1da2)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x680+398-0x80e)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xadb+6617-0x24b3)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x1558+4130-0x247b))|((z366b2f03bf&(0x14cd+3823-0x22bd))<<(0x87d+4362-0x197f)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x5b\x53\x2f\x44\x5d\x20\x49\x4f\x34\x32\x32\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x12d+230-0x213)];Virtual=rl32eGetDevicePtr(z1cf2c50191,32768,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint16_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);switch((uint32_T)mxGetPr(z86992bd6b1)[(0x13a1+2805-0x1e96)]){case(0x12da+2601-0x1d02):zd0072007fc=(0x1137+3076-0x1d3b);break;case(0x88c+3892-0x17be):zd0072007fc=(0xbd3+6114-0x1bb5);break;case(0xe1a+3923-0x1d6a):zd0072007fc=(0x1548+3726-0x13d6);break;}value=(0x1cfc+114-0x1d6e);for(i=(0x14f1+2281-0x1dda);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint16_T)mxGetPr(za9d8fb6bcf)[i]-(0xa59+2264-0x1330);if((uint16_T)mxGetPr(zab611d784e)[z4e3026977c]==(0x6d9+6308-0x1f7d)){value|=(0x628+7195-0x2242)<<z4e3026977c;}else{za42cf7dd4a[zd0072007fc/(0xee7+468-0x10b9)+(0x1264+2964-0x1db8)/(0xdaf+2112-0x15ed)+(0x98f+7401-0x2676)*z4e3026977c]=(uint16_T)mxGetPr(zab611d784e)[z4e3026977c];
}}za42cf7dd4a[zd0072007fc/(0x1493+1490-0x1a63)+(0xee3+567-0x10ca)/(0x127d+3842-0x217d)]=value;
if(mxGetN(za9d8fb6bcf)>(0xbfd+4225-0x1c7d)){za42cf7dd4a[zd0072007fc/(0x16e3+1066-0x1b0b)+(0x210+8419-0x229f)/(0xbdc+6281-0x2463)]=(uint16_T)mxGetPr(zc6dd00a534)[(0xf58+3912-0x1ea0)];
}if(mxGetN(za9d8fb6bcf)>(0x2e3+3648-0x1120)){za42cf7dd4a[zd0072007fc/(0x759+915-0xaea)+(0x1b72+265-0x1c23)/(0x232+518-0x436)]=(uint16_T)mxGetPr(zc6dd00a534)[(0x320+5733-0x1984)];
}value=(0xd8f+5297-0x2240);for(i=(0x7d0+1940-0xf64);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint16_T)mxGetPr(za9d8fb6bcf)[i]-(0x5df+281-0x6f7);value|=(0xe60+3606-0x1c75)<<z4e3026977c;}za42cf7dd4a[zd0072007fc/(0x9fd+6330-0x22b5)+(0x1286+2550-0x1c20)/(0xa71+1271-0xf66)]=value;
value=(0x3aa+3-0x3ad);for(i=(0xaa2+0-0xaa2);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint16_T)mxGetPr(za9d8fb6bcf)[i]-(0x13d1+4470-0x2546);if((uint16_T)mxGetPr(z840ee59d27)[z4e3026977c]){value|=(0x17f5+2028-0x1fde)<<((0x1b86+1689-0x221d)*z4e3026977c);}}za42cf7dd4a[zd0072007fc/(0xf13+3364-0x1c35)+(0x1b8b+1054-0x1f31)/(0xe6f+3881-0x1d96)]=value;
for(i=(0x1e90+609-0x20f1);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint16_T)mxGetPr(za9d8fb6bcf)[i]-(0xbfc+2034-0x13ed);value=(0x155+5999-0x18c4);switch((uint16_T)mxGetPr(z6407e5c238)[z4e3026977c]){case(0x1198+1396-0x1708):value=32768;break;
case(0x1065+435-0x1212):value=32769;break;
case(0x1e57+1188-0x22f3):value=32770;break;
case(0x1031+3870-0x1f43):value=(0x1b65+19-0x1b74);break;
case(0x8e0+6260-0x2147):value=(0xd0b+3567-0x1af7);break;
case(0xed2+5962-0x260e):value=(0x1dd9+1823-0x24f6);break;
case(0x19e3+51-0x1a07):value=(0x171d+2260-0x1ff0);break;
case(0x1899+2735-0x2338):value=(0xc96+2673-0x1707);break;
}za42cf7dd4a[zd0072007fc/(0x8a6+1071-0xcd3)+(0xbfa+2347-0x1445)/(0xd9f+4027-0x1d58)+(0x7e1+859-0xb3a)*z4e3026977c]=value;
}for(i=(0x2175+286-0x2293);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint16_T)mxGetPr(za9d8fb6bcf)[i]-(0x1146+3472-0x1ed5);z7208ec02cc=z2a9dd6156b(mxGetPr(zd3c37ec5dd)[z4e3026977c]);value=(uint16_T)((0x1dd0+102-0xe36)*zc095f236bc/z7208ec02cc);za42cf7dd4a[zd0072007fc/(0x64b+8141-0x2616)+(0xefc+6241-0x260d)/(0xa99+4813-0x1d64)+(0x14d+2031-0x93a)*z4e3026977c]=value;
}za42cf7dd4a[zd0072007fc/(0xbb2+5295-0x205f)+(0x1721+2793-0x21aa)/(0x5d8+2557-0xfd3)]=(0xa84+144-0xb14);printf("\x4d\x6f\x64\x75\x6c\x65\x20\x53\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x65\x64\x2e" "\n\n");
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE   
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint16_T*za42cf7dd4a;uint16_T zd0072007fc,z8592e64c0f,z2eb14e2e61,z5e8d348fd9,status;uint16_T z29d9b4ecb8,zd6533f4fca,z775fb9a2c6;uint16_T z0261aeb023,z4f866f9d7c;uint32_T i,z4e3026977c,z0add1d1c25;int32_T zd6d1a8bb26;real_T*out,*in,position,z86240707c5,z7208ec02cc;za42cf7dd4a=(void*)base;switch((uint32_T)mxGetPr(z86992bd6b1)[(0x6fb+806-0xa21)]){case(0x675+7017-0x21dd):zd0072007fc=(0xd3b+600-0xf93);break;case(0xe4+6606-0x1ab0):zd0072007fc=(0x1050+1788-0xf4c);break;case(0x990+1145-0xe06):zd0072007fc=4096;break;}if((uint32_T)mxGetPr(zc2f544da3c)[(0x14ca+3221-0x215f)]){za42cf7dd4a[zd0072007fc/(0x97a+3313-0x1669)+(0x39c+4366-0x144a)/(0x1c4a+2549-0x263d)]=(0x446+7197-0x2061);}
if((uint32_T)mxGetPr(zd4b2dcc28a)[(0xd22+1013-0x1117)]){z8592e64c0f=za42cf7dd4a[zd0072007fc/(0x2082+648-0x2308)+(0xb86+6616-0x1e5e)/(0x1435+2784-0x1f13)];z2eb14e2e61=za42cf7dd4a[zd0072007fc/(0x154+130-0x1d4)+(0x1a85+3662-0x2703)/(0xea4+49-0xed3)];z5e8d348fd9=za42cf7dd4a[zd0072007fc/(0xa02+4303-0x1acf)+(0xa2a+2195-0x10e9)/(0x1c54+939-0x1ffd)];}for(i=(0x64d+4993-0x19ce);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint16_T)mxGetPr(za9d8fb6bcf)[i]-(0x15aa+3396-0x22ed);z0add1d1c25=(0x110b+3684-0x1f6f);
if((uint32_T)mxGetPr(z942f0304b7)[(0xabf+3928-0x1a17)]){if(z4e3026977c==(0x26+2938-0xba0)||z4e3026977c==(0x358+8014-0x22a5)){zd6533f4fca=(uint16_T)mxGetPr(z329c06005c)[(0x2080+1352-0x25c8)];}else{zd6533f4fca=(uint16_T)mxGetPr(z329c06005c)[(0x155f+1935-0x1ced)];}if(zd6533f4fca){if(z4e3026977c==(0x209f+755-0x2392)||z4e3026977c==(0x1073+4472-0x21ea)){if((uint16_T)mxGetPr(zc6dd00a534)[(0x1602+3486-0x23a0)]>(0x32c+3496-0x10d3)){
z775fb9a2c6=za42cf7dd4a[zd0072007fc/(0x6d8+1364-0xc2a)+(0x4d2+4317-0x15ab)*z4e3026977c];z775fb9a2c6=(z775fb9a2c6>>(0x785+642-0x9ff))&16777215;
position=za42cf7dd4a[zd0072007fc/(0xd65+1269-0x1258)+(0x1a07+2042-0x21fd)/(0x905+117-0x978)+(0xf2a+1412-0x14aa)*z4e3026977c];
position=256.0*position+z775fb9a2c6;position*=(0xeef+1356-0x1439)*z3c26710301/16777216;
}else{
position=(0x1543+1040-0x1953);}}else{if((uint16_T)mxGetPr(zc6dd00a534)[(0x1517+1931-0x1ca1)]>(0x181c+2586-0x2235)){
z775fb9a2c6=za42cf7dd4a[zd0072007fc/(0x212c+1106-0x257c)+(0x379+83-0x3c8)*z4e3026977c];z775fb9a2c6>>=(0x524+8315-0x2597);
position=za42cf7dd4a[zd0072007fc/(0xae2+1169-0xf71)+(0x8f6+3147-0x153d)/(0x1842+802-0x1b62)+(0x3c5+1414-0x947)*z4e3026977c];
position=256.0*position+z775fb9a2c6;position*=(0x1743+2039-0x1f38)*z3c26710301/16777216;
}else{
position=(0xf8+318-0x236);}}}else{
position=za42cf7dd4a[zd0072007fc/(0x542+2526-0xf1e)+(0x199a+1669-0x201b)/(0x1f3+7132-0x1dcd)+(0x227+3052-0xe0f)*z4e3026977c];position*=(0x944+2303-0x1241)*z3c26710301/65536;}out=ssGetOutputPortSignal(S,z0add1d1c25);out[i]=position;z0add1d1c25++;}
if((uint32_T)mxGetPr(zb3e8c30072)[(0x711+39-0x738)]){
if((uint32_T)mxGetPr(z3350ecfebd)[(0xb3+7416-0x1dab)]){in=(real_T*)ssGetInputPortSignal(S,(0x23ed+674-0x268f));z7208ec02cc=z2a9dd6156b(in[i]);z29d9b4ecb8=(uint16_T)(4096*zc095f236bc/z7208ec02cc);za42cf7dd4a[zd0072007fc/(0x1e86+117-0x1ef9)+(0x640+279-0x607)/(0x343+3828-0x1235)+(0x1aaf+1304-0x1fc5)*z4e3026977c]=z29d9b4ecb8;}else{z7208ec02cc=z2a9dd6156b(mxGetPr(zd3c37ec5dd)[z4e3026977c]);}z0261aeb023=(uint16_T)za42cf7dd4a[zd0072007fc/(0x2103+1049-0x251a)+(0x351+5199-0x177c)/(0x13a6+3707-0x221f)+(0x3e9+8483-0x2508)*z4e3026977c];z4f866f9d7c=(uint16_T)za42cf7dd4a[zd0072007fc/(0x8cc+2556-0x12c6)+(0x7ff+7275-0x244a)/(0x142f+1044-0x1841)+(0xf+6748-0x1a67)*z4e3026977c];zd6d1a8bb26=(z0261aeb023<<(0x39c+1785-0xa85))+z4f866f9d7c;z86240707c5=zd6d1a8bb26*z7208ec02cc/2147483648;out=ssGetOutputPortSignal(S,z0add1d1c25);out[i]=z86240707c5;z0add1d1c25++;}
if((uint32_T)mxGetPr(zd4b2dcc28a)[(0x9c9+5152-0x1de9)]){status=((z8592e64c0f&((0x13a0+3309-0x208c)<<z4e3026977c))?(0x1245+569-0x147d):(0x1197+5044-0x254b))|((z2eb14e2e61&((0xee0+495-0x10ce)<<z4e3026977c))?(0xe28+2764-0x18f2):(0x5da+2713-0x1073))|((z5e8d348fd9&((0x943+5697-0x1f83)<<z4e3026977c))?(0x1125+2284-0x1a0d):(0x20f+4202-0x1279));out=ssGetOutputPortSignal(S,z0add1d1c25);out[z4e3026977c]=status;}}
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

