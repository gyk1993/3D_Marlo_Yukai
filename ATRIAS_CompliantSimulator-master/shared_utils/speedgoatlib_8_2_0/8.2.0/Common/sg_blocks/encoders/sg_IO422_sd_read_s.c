/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x193c+3238-0x25e0)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO422_sd_read_s
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
#define zdf24515981              ((0x87+5570-0x163a))
#define za9d8fb6bcf                 ssGetSFcnParam(S,(0xf1c+5267-0x23af))
#define z86992bd6b1                 ssGetSFcnParam(S,(0xb17+3463-0x189d))
#define zab611d784e               ssGetSFcnParam(S,(0x9f+4602-0x1297))
#define zc6dd00a534         ssGetSFcnParam(S,(0x2e9+2794-0xdd0))
#define z840ee59d27          ssGetSFcnParam(S,(0x1dad+1516-0x2395))
#define z6407e5c238                 ssGetSFcnParam(S,(0xae7+2678-0x1558))
#define zd3c37ec5dd                 ssGetSFcnParam(S,(0x16b4+3570-0x24a0))
#define z942f0304b7         ssGetSFcnParam(S,(0x1c82+9-0x1c84))
#define zb3e8c30072         ssGetSFcnParam(S,(0xcdc+5121-0x20d5))
#define zd4b2dcc28a           ssGetSFcnParam(S,(0x1466+1319-0x1984))
#define z3350ecfebd         ssGetSFcnParam(S,(0x1516+1940-0x1ca0))
#define z329c06005c                  ssGetSFcnParam(S,(0x92+8235-0x20b2))
#define zc2f544da3c                   ssGetSFcnParam(S,(0x45a+2297-0xd47))
#define z3832b85a32               ssGetSFcnParam(S,(0x65a+5308-0x1b09))
#define z702a26a5e9                    ssGetSFcnParam(S,(0xbd1+5328-0x2093))
#define z2e6483d505              ((0x4a9+7172-0x20ab))
#define z7e2eeaa57c          ((0x1f06+1143-0x237d))
#define z6a0da049de         ((0x18ab+51-0x18dd))
#define zc5ce4cb81a              ((0x131c+1824-0x1a2c))
#define z2b17e2ee3b              ((0xd9f+610-0x1001))
#define z293caa0fc3               (11.9209)
#define zc095f236bc               (190.7348)
#define z3c26710301                       (3.14159265358979)
#define zf582ac547e(x, zbcef5ca055)          (x < zbcef5ca055 ? zbcef5ca055 : x)
#define zddff81264d(x, z1a670ae0bc)          (x > z1a670ae0bc ? z1a670ae0bc : x)
#define zf2378c6436(x, zbcef5ca055, z1a670ae0bc)         (zf582ac547e(zddff81264d(x, z1a670ae0bc), zbcef5ca055))
#define z2a9dd6156b(x)         (zf2378c6436(x, z293caa0fc3, zc095f236bc))
static char_T zea4cd01646[(0xd09+1928-0x1391)];static void mdlInitializeSizes(SimStruct*S){uint32_T i,zbc7ebd0e53;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x326+6434-0x1c48));ssSetNumDiscStates(S,(0x141d+2691-0x1ea0));zbc7ebd0e53=(0x962+2022-0x1148);if((uint32_T)mxGetPr(z942f0304b7)[(0x1e99+294-0x1fbf)]){zbc7ebd0e53++;}if((uint32_T)mxGetPr(zb3e8c30072)[(0x17d8+2327-0x20ef)]){zbc7ebd0e53++;}if((uint32_T)mxGetPr(zd4b2dcc28a)[(0x170f+1444-0x1cb3)]){zbc7ebd0e53++;}ssSetNumOutputPorts(S,zbc7ebd0e53);for(i=(0x10fc+5334-0x25d2);i<zbc7ebd0e53;i++){ssSetOutputPortWidth(S,i,(uint32_T)mxGetN(za9d8fb6bcf));ssSetOutputPortDataType(S,i,SS_DOUBLE);}if((uint32_T)mxGetPr(z3350ecfebd)[(0x13b4+3678-0x2212)]){ssSetNumInputPorts(S,(0x715+3120-0x1344));ssSetInputPortWidth(S,(0x221a+394-0x23a4),(uint32_T)mxGetN(za9d8fb6bcf));ssSetInputPortDataType(S,(0x991+7371-0x265c),SS_DOUBLE);ssSetInputPortDirectFeedThrough(S,(0x1395+1544-0x199d),(0xd0a+4130-0x1d2b));ssSetInputPortRequiredContiguous(S,(0x1f80+1174-0x2416),(0xdd1+2265-0x16a9));}else{ssSetNumInputPorts(S,(0x6c4+3516-0x1480));}ssSetNumSampleTimes(S,(0x1f91+410-0x212a));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x10a6+2892-0x1bf2));ssSetNumNonsampledZCs(S,(0x13b+1564-0x757));for(i=(0x2477+40-0x249f);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x30+7253-0x1c85));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x122f+4218-0x22a9)]==-1.0){ssSetSampleTime(S,(0xf39+5409-0x245a),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xcaa+2670-0x1718),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x22a+3359-0xf49),mxGetPr(z3832b85a32)[(0x1152+5334-0x2628)]);ssSetOffsetTime(S,(0x1523+3927-0x247a),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint16_T*za42cf7dd4a;uint16_T z6f813cde47,za4a2434e08;uint16_T z4e3026977c,value;uint16_T zd0072007fc;uint32_T i;real_T z7208ec02cc;za4a2434e08=30099;z6f813cde47=(0x24ad+2955-0x1a8c);if((int_T)mxGetPr(z702a26a5e9)[(0x215+390-0x39b)]<(0x601+8269-0x264e)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x5b\x53\x2f\x44\x5d\x20\x49\x4f\x34\x32\x32\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74");ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x2cc+7069-0x1e68)){z366b2f03bf=(0x98f+4333-0x1a7c);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x6ef+1784-0xde7)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x30f+9010-0x2641)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1a5+8131-0x2167)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x63c+813-0x86a))|((z366b2f03bf&(0x49c+5484-0x1909))<<(0x305+8142-0x22cb)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x5b\x53\x2f\x44\x5d\x20\x49\x4f\x34\x32\x32\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0xfd1+4589-0x21be)];Virtual=rl32eGetDevicePtr(z1cf2c50191,32768,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint16_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);switch((uint32_T)mxGetPr(z86992bd6b1)[(0x1a6+5872-0x1896)]){case(0xf0b+3097-0x1b23):zd0072007fc=(0x3b+801-0x35c);break;case(0x412+7757-0x225d):zd0072007fc=(0x253d+2501-0x2702);break;case(0x1476+3206-0x20f9):zd0072007fc=(0x1ccc+915-0x105f);break;}value=(0x199+7232-0x1dd9);for(i=(0x30c+4199-0x1373);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint16_T)mxGetPr(za9d8fb6bcf)[i]-(0xb6+5635-0x16b8);if((uint16_T)mxGetPr(zab611d784e)[z4e3026977c]==(0x10a5+5378-0x25a7)){value|=(0x8f4+4715-0x1b5e)<<z4e3026977c;}else{za42cf7dd4a[zd0072007fc/(0x3f+7922-0x1f2f)+(0x7b0+744-0xa58)/(0x3ed+6669-0x1df8)+(0x16f+5058-0x152f)*z4e3026977c]=(uint16_T)mxGetPr(zab611d784e)[z4e3026977c];
}}za42cf7dd4a[zd0072007fc/(0x17b+4709-0x13de)+(0x902+4798-0x1b70)/(0x3a5+3881-0x12cc)]=value;
if(mxGetN(za9d8fb6bcf)>(0xc99+6183-0x24bf)){za42cf7dd4a[zd0072007fc/(0x1385+1933-0x1b10)+(0xea5+4364-0x1f5d)/(0x73b+6401-0x203a)]=(uint16_T)mxGetPr(zc6dd00a534)[(0xa2b+4220-0x1aa7)];
}if(mxGetN(za9d8fb6bcf)>(0x5c2+4856-0x18b7)){za42cf7dd4a[zd0072007fc/(0x169d+3835-0x2596)+(0x1921+3426-0x262b)/(0x96b+3686-0x17cf)]=(uint16_T)mxGetPr(zc6dd00a534)[(0x1070+1266-0x1561)];
}value=(0x1fd+6473-0x1b46);for(i=(0xdfb+4883-0x210e);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint16_T)mxGetPr(za9d8fb6bcf)[i]-(0x19d0+1741-0x209c);value|=(0x1710+94-0x176d)<<z4e3026977c;}za42cf7dd4a[zd0072007fc/(0x2373+99-0x23d4)+(0x64c+4550-0x17b6)/(0x5aa+8168-0x2590)]=value;
value=(0x68+4967-0x13cf);for(i=(0xd9c+6486-0x26f2);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint16_T)mxGetPr(za9d8fb6bcf)[i]-(0x11f2+3749-0x2096);if((uint16_T)mxGetPr(z840ee59d27)[z4e3026977c]){value|=(0x278+4155-0x12b0)<<((0x1738+1930-0x1ec0)*z4e3026977c);}}za42cf7dd4a[zd0072007fc/(0x133a+727-0x160f)+(0xd11+597-0xeee)/(0xcb5+172-0xd5f)]=value;
for(i=(0x86b+133-0x8f0);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint16_T)mxGetPr(za9d8fb6bcf)[i]-(0xee0+545-0x1100);value=(0x33c+7149-0x1f29);switch((uint16_T)mxGetPr(z6407e5c238)[z4e3026977c]){case(0x902+2173-0x117b):value=32768;break;
case(0x1b5d+405-0x1cec):value=32769;break;
case(0xf7f+1944-0x170f):value=32770;break;
case(0x6e0+8152-0x26ac):value=(0x1214+2188-0x1a9c);break;
case(0xf80+513-0x1174):value=(0x1512+2402-0x1e71);break;
case(0x8c0+4703-0x1b11):value=(0x19b9+3323-0x26b2);break;
case(0x2b9+3430-0x1010):value=(0xbc5+3374-0x18f2);break;
case(0x2ed+1865-0xa26):value=(0x790+405-0x925);break;
}za42cf7dd4a[zd0072007fc/(0xb9f+4193-0x1bfe)+(0x2b2+4946-0x1524)/(0x1cb4+770-0x1fb4)+(0xf7d+5799-0x2622)*z4e3026977c]=value;
}for(i=(0xf59+3071-0x1b58);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint16_T)mxGetPr(za9d8fb6bcf)[i]-(0x1c0+4819-0x1492);z7208ec02cc=z2a9dd6156b(mxGetPr(zd3c37ec5dd)[z4e3026977c]);value=(uint16_T)((0x1a9a+1526-0x1090)*zc095f236bc/z7208ec02cc);za42cf7dd4a[zd0072007fc/(0x1147+957-0x1502)+(0x1182+2353-0x1963)/(0x177+1310-0x693)+(0xe54+773-0x1157)*z4e3026977c]=value;
}za42cf7dd4a[zd0072007fc/(0xeb5+5161-0x22dc)+(0x4fb+2063-0xcaa)/(0x1ff8+1737-0x26bf)]=(0x44d+4798-0x170b);printf("\x4d\x6f\x64\x75\x6c\x65\x20\x53\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x65\x64\x2e" "\n\n");
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE   
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint16_T*za42cf7dd4a;uint16_T zd0072007fc,z8592e64c0f,z2eb14e2e61,z5e8d348fd9,status;uint16_T z29d9b4ecb8,zd6533f4fca,z775fb9a2c6;uint16_T z0261aeb023,z4f866f9d7c;uint32_T i,z4e3026977c,z0add1d1c25;int32_T zd6d1a8bb26;real_T*out,*in,position,z86240707c5,z7208ec02cc;za42cf7dd4a=(void*)base;switch((uint32_T)mxGetPr(z86992bd6b1)[(0x39f+4656-0x15cf)]){case(0x2d3+2216-0xb7a):zd0072007fc=(0x550+526-0x75e);break;case(0x988+2327-0x129d):zd0072007fc=(0xa01+5927-0x1928);break;case(0xa17+1046-0xe2a):zd0072007fc=(0x1b8f+5773-0x221c);break;}if((uint32_T)mxGetPr(zc2f544da3c)[(0x430+4659-0x1663)]){za42cf7dd4a[zd0072007fc/(0x1e69+1427-0x23fa)+(0x239+5485-0x1746)/(0x8c5+1874-0x1015)]=(0xefc+2897-0x1a4b);}
if((uint32_T)mxGetPr(zd4b2dcc28a)[(0xcd4+4834-0x1fb6)]){z8592e64c0f=za42cf7dd4a[zd0072007fc/(0x1162+582-0x13a6)+(0x142d+3292-0x1a09)/(0x422+1333-0x955)];z2eb14e2e61=za42cf7dd4a[zd0072007fc/(0x1f2c+162-0x1fcc)+(0x1470+64-0x12e0)/(0xfb+5695-0x1738)];z5e8d348fd9=za42cf7dd4a[zd0072007fc/(0xc17+1643-0x1280)+(0x997+3519-0x1582)/(0x1ecf+1782-0x25c3)];}for(i=(0x1119+5230-0x2587);i<mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint16_T)mxGetPr(za9d8fb6bcf)[i]-(0x8d2+2766-0x139f);z0add1d1c25=(0x942+2662-0x13a8);
if((uint32_T)mxGetPr(z942f0304b7)[(0xbda+2753-0x169b)]){if(z4e3026977c==(0x7d9+6076-0x1f95)||z4e3026977c==(0xa9b+2583-0x14b1)){zd6533f4fca=(uint16_T)mxGetPr(z329c06005c)[(0x4e6+1335-0xa1d)];}else{zd6533f4fca=(uint16_T)mxGetPr(z329c06005c)[(0x9e4+2808-0x14db)];}if(zd6533f4fca){if(z4e3026977c==(0x7+5598-0x15e5)||z4e3026977c==(0x1d78+665-0x2010)){if((uint16_T)mxGetPr(zc6dd00a534)[(0xda2+4747-0x202d)]>(0x1b2+1967-0x960)){
z775fb9a2c6=za42cf7dd4a[zd0072007fc/(0x1af+2167-0xa24)+(0x1cec+809-0x2011)*z4e3026977c];z775fb9a2c6=(z775fb9a2c6>>(0x13e0+4519-0x257f))&16777215;
position=za42cf7dd4a[zd0072007fc/(0x1121+2648-0x1b77)+(0xdb+2100-0x90b)/(0x55+3817-0xf3c)+(0xa1c+5504-0x1f98)*z4e3026977c];
position=256.0*position+z775fb9a2c6;position*=(0x3d3+4998-0x1757)*z3c26710301/16777216;
}else{
position=(0x754+2340-0x1078);}}else{if((uint16_T)mxGetPr(zc6dd00a534)[(0xe76+1471-0x1434)]>(0x1241+2959-0x1dcf)){
z775fb9a2c6=za42cf7dd4a[zd0072007fc/(0xc1+8828-0x233b)+(0x1426+301-0x154f)*z4e3026977c];z775fb9a2c6>>=(0x2e3+9166-0x26a9);
position=za42cf7dd4a[zd0072007fc/(0x18cd+3609-0x26e4)+(0x111+4447-0x126c)/(0x1a99+278-0x1bad)+(0xc2b+6729-0x2670)*z4e3026977c];
position=256.0*position+z775fb9a2c6;position*=(0xfe8+2527-0x19c5)*z3c26710301/16777216;
}else{
position=(0x608+3732-0x149c);}}}else{
position=za42cf7dd4a[zd0072007fc/(0x447+6430-0x1d63)+(0x287+2653-0xce0)/(0xe1f+54-0xe53)+(0x126b+4363-0x2372)*z4e3026977c];position*=(0xb95+1086-0xfd1)*z3c26710301/65536;}out=ssGetOutputPortSignal(S,z0add1d1c25);out[i]=position;z0add1d1c25++;}
if((uint32_T)mxGetPr(zb3e8c30072)[(0x102+7906-0x1fe4)]){
if((uint32_T)mxGetPr(z3350ecfebd)[(0x7fb+5097-0x1be4)]){in=(real_T*)ssGetInputPortSignal(S,(0x3b3+615-0x61a));z7208ec02cc=z2a9dd6156b(in[i]);z29d9b4ecb8=(uint16_T)((0x2176+518-0x137c)*zc095f236bc/z7208ec02cc);za42cf7dd4a[zd0072007fc/(0x1956+303-0x1a83)+(0x7c5+8078-0x2603)/(0x294+8996-0x25b6)+(0x681+4916-0x19b3)*z4e3026977c]=z29d9b4ecb8;}else{z7208ec02cc=z2a9dd6156b(mxGetPr(zd3c37ec5dd)[z4e3026977c]);}z0261aeb023=(uint16_T)za42cf7dd4a[zd0072007fc/(0x1748+2312-0x204e)+(0xea2+2405-0x17e3)/(0x300+7775-0x215d)+(0xf8+9202-0x24e6)*z4e3026977c];z4f866f9d7c=(uint16_T)za42cf7dd4a[zd0072007fc/(0x15f+5312-0x161d)+(0x1b11+1715-0x21a4)/(0x449+3690-0x12b1)+(0x18bf+857-0x1c14)*z4e3026977c];zd6d1a8bb26=(z0261aeb023<<(0xaca+458-0xc84))+z4f866f9d7c;z86240707c5=zd6d1a8bb26*z7208ec02cc/2147483648;out=ssGetOutputPortSignal(S,z0add1d1c25);out[i]=z86240707c5;z0add1d1c25++;}
if((uint32_T)mxGetPr(zd4b2dcc28a)[(0x16e6+2539-0x20d1)]){status=((z8592e64c0f&((0x2b3+910-0x640)<<z4e3026977c))?(0x630+5030-0x19d5):(0x790+2292-0x1084))|((z2eb14e2e61&((0x9d0+2379-0x131a)<<z4e3026977c))?(0x2a1+8489-0x23c8):(0x197b+250-0x1a75))|((z5e8d348fd9&((0x202a+1600-0x2669)<<z4e3026977c))?(0x404+4894-0x171e):(0x5f0+309-0x725));out=ssGetOutputPortSignal(S,z0add1d1c25);out[z4e3026977c]=status;}}
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

