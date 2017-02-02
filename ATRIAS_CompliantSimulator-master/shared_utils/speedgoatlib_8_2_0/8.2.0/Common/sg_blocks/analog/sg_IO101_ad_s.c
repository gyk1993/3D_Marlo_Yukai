/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x16fd+1557-0x1d10)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO101_ad_s
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
#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x30\x31"
#define z694756a014 (0x1864+4226-0x1211)
#define zea87e0ba83 17495
#define zb700a21e90 (0x2473+415-0x2512)
#define z405bc1a59d
#define zdf24515981          ((0x877+566-0xaa4))
#define z7abddc8aad       ssGetSFcnParam(S,(0x696+3252-0x134a))
#define z37c3cb7f0a         ssGetSFcnParam(S,(0xdca+2644-0x181d))
#define z8e37b80355            ssGetSFcnParam(S,(0x14aa+3675-0x2303))
#define z8fd86139be               ssGetSFcnParam(S,(0x16ef+373-0x1861))
#define z6e0dbe056e            ssGetSFcnParam(S,(0xba4+3468-0x192c))
#define z440bc5d441           ssGetSFcnParam(S,(0x374+2754-0xe31)) 
#define z3832b85a32           ssGetSFcnParam(S,(0x19a9+462-0x1b71))
#define z702a26a5e9                ssGetSFcnParam(S,(0x8ed+6470-0x222c))
#define z6b1a64c92c             ssGetSFcnParam(S,(0x5ad+5087-0x1984))
#define z2e6483d505              ((0x81c+1858-0xf58))
#define z6a0da049de         ((0x6b8+979-0xa8b))
#define zc65b792f40     ((0x743+6670-0x2150))
#define z5301267c3b      ((0x7b0+7536-0x251e))
#define z68983ebba8          ((0x6f9+6719-0x2135))
#define zbe66eb8546         ((0x6c3+2556-0x10bb))
#define z43cf08dd43             ((0xb0a+830-0xe43))
#define zc5ce4cb81a              ((0x7e8+331-0x931))
#define z8caad2a8e6              ((0x111a+670-0x13b8))
#define z5bfe7a2613            ((0xa4d+7046-0x25d2))
#define z2b17e2ee3b              ((0x1902+1317-0x1e27))
static char_T zea4cd01646[(0x10dc+5116-0x23d8)];
#ifndef MATLAB_MEX_FILE
static void z14abefc6ac(volatile uint32_T*za42cf7dd4a,SimStruct*S){real_T start,z19c4ca5f82;
start=rl32eGetTicksDouble();
while((za42cf7dd4a[(0xd8+8624-0x226e)]&(0x1427+3694-0x2294))==(0xfb7+5491-0x252a)){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*0.1){

sprintf(zea4cd01646,"\x25\x73\x20\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x64\x61\x74\x61\x20\x72\x65\x74\x72\x69\x65\x76\x61\x6c\x20\x74\x69\x6d\x65\x64\x20\x6f\x75\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}
}
}
#endif
static void mdlInitializeSizes(SimStruct*S){uint32_T i;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x242+6670-0x1c50));ssSetNumDiscStates(S,(0xda9+1668-0x142d));ssSetNumInputPorts(S,(0x18c0+707-0x1b83));switch((int32_T)mxGetPr(z440bc5d441)[(0x15b5+3458-0x2337)]-(0x1e0+8853-0x2474)){case(0xde5+3050-0x19cf):ssSetNumOutputPorts(S,(int32_T)mxGetPr(z37c3cb7f0a)[(0x1c08+2415-0x2577)]);for(i=(0xd07+1868-0x1453);i<(uint32_T)mxGetPr(z37c3cb7f0a)[(0x903+4326-0x19e9)];i++){ssSetOutputPortWidth(S,i,(0x1c5+2036-0x9b8));}break;case(0x21ca+193-0x228a):ssSetNumOutputPorts(S,(int32_T)mxGetPr(z37c3cb7f0a)[(0x1f93+536-0x21ab)]+(0x20ca+337-0x221a));for(i=(0xd59+1425-0x12ea);i<(uint32_T)mxGetPr(z37c3cb7f0a)[(0x1ea+58-0x224)]+(0xd7f+598-0xfd4);i++){ssSetOutputPortWidth(S,i,(0x1949+1169-0x1dd9));}break;}ssSetNumSampleTimes(S,(0x3ea+4095-0x13e8));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x635+7444-0x2349));ssSetNumNonsampledZCs(S,(0x6ba+3907-0x15fd));for(i=(0x17cd+2581-0x21e2);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x14e7+633-0x1760));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x3f2+7976-0x231a)]==-1.0){ssSetSampleTime(S,(0x1a51+683-0x1cfc),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xa8a+4299-0x1b55),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x726+7540-0x249a),mxGetPr(z3832b85a32)[(0x13+594-0x265)]);ssSetOffsetTime(S,(0x1ab4+2538-0x249e),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint32_T*za42cf7dd4a;volatile uint8_T*z3283caa368;uint32_T i;uint8_T z34c68d4df7,z979d8f17a3;uint8_T zd254bf6903,z2a78d7bb7c,first;real_T zd7ed04e88c,z1d52f1a257;real_T za8a33144e7[(0xd9f+5419-0x22c5)];uint32_T z32f0d7e7fd,z77a6329c73;uint32_T zd5317f54d8,zcadf9c54a7,z9fc7e38097;real_T z0754dd67cc;if((int_T)mxGetPr(z702a26a5e9)[(0x8e3+3426-0x1645)]<(0x258+1461-0x80d)){if(rl32eGetPCIInfo((uint16_T)z694756a014,(uint16_T)zea87e0ba83,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x1960+2349-0x228c)){z366b2f03bf=(0x27+3376-0xd57);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x9f2+3249-0x16a3)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x21a+817-0x54b)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x6a9+1090-0xaea)];}if(rl32eGetPCIInfoAtSlot((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(z441f9e6d1b&(0x1ea7+63-0x1de7))|((z366b2f03bf&(0x871+7201-0x2393))<<(0x11bd+5262-0x2643)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0xa58+3843-0x195b)];Virtual=rl32eGetDevicePtr(z1cf2c50191,4096,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint32_T*)Virtual;z3283caa368=(volatile uint8_T*)Virtual;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);z34c68d4df7=(uint8_T)mxGetPr(z7abddc8aad)[(0x141f+2411-0x1d8a)]-(0x480+3177-0x10e8);ssSetIWorkValue(S,zc65b792f40,z34c68d4df7);z979d8f17a3=(uint8_T)mxGetPr(z37c3cb7f0a)[(0xefc+1638-0x1562)];ssSetIWorkValue(S,z5301267c3b,z979d8f17a3);z2a78d7bb7c=(uint8_T)mxGetPr(z6e0dbe056e)[(0xca5+4202-0x1d0f)]-(0x313+1807-0xa21);ssSetIWorkValue(S,z68983ebba8,z2a78d7bb7c);zd254bf6903=(uint8_T)mxGetPr(z440bc5d441)[(0x1d6b+1422-0x22f9)]-(0x6cf+7268-0x2332);ssSetIWorkValue(S,zbe66eb8546,zd254bf6903);first=(0x8ad+5416-0x1dd4);ssSetIWorkValue(S,z43cf08dd43,first);switch((int32_T)mxGetPr(z8fd86139be)[(0x1a0c+570-0x1c46)]-(0x374+401-0x504)){case(0x108+6793-0x1b91):
z32f0d7e7fd=(0xfe5+4401-0x2114);
z77a6329c73=(0x1450+1945-0x1be5);
zcadf9c54a7=(0xbe6+489-0xdca);z9fc7e38097=(0x3bc+9002-0x26df);break;case(0x53a+2250-0xe03):
z32f0d7e7fd=(0x20f4+643-0x2376);
z77a6329c73=(0x1cd7+1259-0x21be);
zcadf9c54a7=(0x341+7179-0x1f48);z9fc7e38097=(0x830+3159-0x1480);break;case(0xfe2+2132-0x1834):
z32f0d7e7fd=(0xa60+4332-0x1b4c);
z77a6329c73=(0x112+8314-0x2188);
zcadf9c54a7=(0x34+8402-0x2103);z9fc7e38097=(0xeb1+4545-0x206b);break;case(0x248+6297-0x1ade):
z32f0d7e7fd=(0x27a+207-0x348);
z77a6329c73=(0xa31+2124-0x127a);
zcadf9c54a7=(0xf18+3473-0x1ca5);z9fc7e38097=(0x9b5+923-0xd4a);break;case(0x484+7634-0x2252):
z32f0d7e7fd=(0x394+442-0x54e);
z77a6329c73=(0x1e24+1049-0x223a);
zcadf9c54a7=(0x125+211-0x1f5);z9fc7e38097=(0x94b+2895-0x1494);break;}switch((int32_T)mxGetPr(z8e37b80355)[(0x53+7865-0x1f0c)]-(0xbcc+2325-0x14e0)){case(0x226d+445-0x242a):
zd5317f54d8=(0x395+1203-0x848);break;case(0x1a6+9082-0x251f):
zd5317f54d8=(0x1e6f+2078-0x268c);break;}
{char_T current;char_T str[(0x995+6796-0x2411)];uint16_T index;uint32_T z548bd6fb7c;for(i=(0x1176+3125-0x1dab);i<(0x1cb7+964-0x2077);i++){index=(0x692+8311-0x2709);current=(0x23ed+735-0x26cb);z548bd6fb7c=(0xa82+2767-0x1531)+i*(0x105+4138-0x111f);while(current){za42cf7dd4a[(0x294+6642-0x1c6d)]=((0x39c+2789-0xe80)<<(0x53f+6615-0x1f07))|(z548bd6fb7c<<(0x654+1481-0xc15));
z14abefc6ac(za42cf7dd4a,S);current=(za42cf7dd4a[(0x1668+3797-0x2523)]>>(0x25dc+205-0x26a1))&(0x1762+2107-0x1e9e);
str[index]=current;index++;z548bd6fb7c++;rl32eWaitDouble(0.001);}za8a33144e7[i]=atof(str);
}za8a33144e7[(0x278+5293-0x1721)]=0.0;}
z3283caa368[(0x443+308-0x56f)]=(0x52a+7933-0x2427);z3283caa368[(0x1251+1728-0x1908)]=(0x1d49+396-0x1ed5);
za42cf7dd4a[(0x1744+2851-0x2263)]=zb700a21e90-(0x230+3939-0x1192);

za42cf7dd4a[(0x1113+5299-0x25c5)]=8960|(z9fc7e38097<<(0xa96+1599-0x10d2));
za42cf7dd4a[(0x221+3185-0xe8d)]=(0x15c7+3003-0x2181);
while(!(za42cf7dd4a[(0x245+25-0x25d)]&32768));
za42cf7dd4a[(0x14e0+3149-0x212c)]=(0x21f2+6600-0x1bba)|(z9fc7e38097<<(0x1416+2384-0x1d63));
zd7ed04e88c=0.0;for(i=zb700a21e90/(0x75+4898-0x1395);i<zb700a21e90;i++){zd7ed04e88c+=(real_T)(int16_T)(za42cf7dd4a[(0x18f1+84-0x1745)+i]&65535);}zd7ed04e88c=zd7ed04e88c/(real_T)zb700a21e90*2.0;


za42cf7dd4a[(0x1e2a+850-0x217b)]=8960|(zcadf9c54a7<<(0x6fa+723-0x9ca));;
za42cf7dd4a[(0x41c+1298-0x929)]=(0x82d+5464-0x1d84);
while(!(za42cf7dd4a[(0xc7+5449-0x160f)]&32768));
za42cf7dd4a[(0xa95+4168-0x1adc)]=8192|(zcadf9c54a7<<(0xb20+4009-0x1ac6));
z1d52f1a257=0.0;for(i=zb700a21e90/(0x164c+999-0x1a31);i<zb700a21e90;i++){z1d52f1a257+=(real_T)(int16_T)(za42cf7dd4a[(0x105a+1787-0x1555)+i]&65535);}z1d52f1a257=z1d52f1a257/(real_T)zb700a21e90*2.0;
z0754dd67cc=(z1d52f1a257-zd7ed04e88c)/(za8a33144e7[z32f0d7e7fd]-za8a33144e7[z77a6329c73]);ssSetRWorkValue(S,z8caad2a8e6,z0754dd67cc);ssSetRWorkValue(S,z5bfe7a2613,zd7ed04e88c-z0754dd67cc*za8a33144e7[z77a6329c73]);
z3283caa368[(0xd40+4355-0x1e3b)]=z34c68d4df7;z3283caa368[(0x1bdf+703-0x1e95)]=z34c68d4df7+z979d8f17a3-(0x2085+97-0x20e5);
za42cf7dd4a[(0x6f0+6453-0x2021)]=z979d8f17a3-(0x80+6720-0x1abf);
za42cf7dd4a[(0x38+9235-0x243c)]=(0xd91+1649-0x1400);switch(z2a78d7bb7c){case(0x7bf+682-0xa69):
za42cf7dd4a[(0x1317+3577-0x210f)]=(0x912+4522-0x16bc)|(zd5317f54d8<<(0xab6+4263-0x1b5a));break;case(0x829+4048-0x17f8):
za42cf7dd4a[(0x1ce0+1987-0x24a2)]=(0x10eb+2126-0x1537)|(zd5317f54d8<<(0x65a+5834-0x1d21));
za42cf7dd4a[(0x11d7+813-0x14f0)]=(0x1b46+937-0x1ae8);




za42cf7dd4a[(0xf32+3621-0x1d41)]=(uint32_T)mxGetPr(z6b1a64c92c)[(0x6f7+8163-0x26da)];
za42cf7dd4a[(0xf56+2213-0x17e4)]=(uint32_T)mxGetPr(z6b1a64c92c)[(0x1115+3685-0x1f79)];za42cf7dd4a[(0x1104+296-0x121a)]=(0x7fc+5234-0x1c6e);
break;}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);uint8_T z34c68d4df7=ssGetIWorkValue(S,zc65b792f40);uint8_T z979d8f17a3=ssGetIWorkValue(S,z5301267c3b);uint8_T z2a78d7bb7c=ssGetIWorkValue(S,z68983ebba8);uint8_T zd254bf6903=ssGetIWorkValue(S,zbe66eb8546);uint8_T first=ssGetIWorkValue(S,z43cf08dd43);uint8_T z8ceacacbdb;uint16_T i;uint32_T z812c65ff2f;volatile uint32_T*za42cf7dd4a;real_T*y;int16_T count;uint8_T z4e3026977c;uint32_T z7be9105675;real_T z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6);real_T offset=ssGetRWorkValue(S,z5bfe7a2613);za42cf7dd4a=(void*)base;z8ceacacbdb=(0xe4+4887-0x13fa);switch(z2a78d7bb7c){case(0x18b6+490-0x1aa0):
za42cf7dd4a[(0x3e7+3685-0x1247)]=(0x88c+1432-0xe23);break;case(0xacf+5947-0x2209):
za42cf7dd4a[(0xeb1+642-0x111b)]=(0x1c53+699-0x1f0d);if(first){ssSetIWorkValue(S,z43cf08dd43,(0x57+9353-0x24e0));
z8ceacacbdb=(0x11c3+5213-0x2620);}break;}z812c65ff2f=(0x74d+8103-0x26f4);if(z8ceacacbdb){
while(!(za42cf7dd4a[(0x170d+1319-0x1c33)]&32768))z812c65ff2f++;
}
for(i=(0x6e0+7221-0x2315);i<z979d8f17a3;i++){y=ssGetOutputPortSignal(S,i);if(z8ceacacbdb){z7be9105675=za42cf7dd4a[(0xfdf+2421-0x1754)+i];count=(int16_T)(z7be9105675&65535);z4e3026977c=(uint8_T)((z7be9105675>>(0xe21+3356-0x1b2d))&(0x1c3b+913-0x1fad));if((i+z34c68d4df7)!=z4e3026977c){printf("\x41\x44\x43\x20\x6d\x65\x6d\x6f\x72\x79\x20\x6f\x72\x64\x65\x72\x20\x70\x72\x6f\x62\x6c\x65\x6d" "\n");}y[(0x1bc2+1525-0x21b7)]=((real_T)count-offset)/z0754dd67cc;}else{y[(0x81a+3587-0x161d)]=0.0;}
}if(zd254bf6903==(0xeb9+4600-0x20b0)){y=ssGetOutputPortSignal(S,i);y[(0x18fd+699-0x1bb8)]=(real_T)z812c65ff2f;}
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

