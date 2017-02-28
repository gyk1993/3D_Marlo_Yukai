/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x9bf+6545-0x234e)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO106_addma_s
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

#define zf1b619edf2 "\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x31\x30\x36"
#define z694756a014 (0x196d+4276-0x196c)
#define zea87e0ba83 36950
#define z29146a1837 (0x24aa+1215-0x18b4)
#define zab7e64468b 12545


#define zdf24515981          ((0x2d7+6644-0x1cc2))
#define zd6d6a44c19                 ssGetSFcnParam(S,(0x9d5+4598-0x1bcb))
#define z1c6ce8e1bc           ssGetSFcnParam(S,(0x86d+6313-0x2115))
#define z2afc595703           ssGetSFcnParam(S,(0xdb4+2891-0x18fd))
#define zea2279958e             ssGetSFcnParam(S,(0x6+530-0x215))
#define z186580de21          ssGetSFcnParam(S,(0xb0a+583-0xd4d))
#define zb0ce0940e9           ssGetSFcnParam(S,(0x4bd+7719-0x22df))
#define zf5ee62a4ad        ssGetSFcnParam(S,(0x133+3475-0xec0))
#define z3832b85a32           ssGetSFcnParam(S,(0xab8+4498-0x1c43))
#define z702a26a5e9                ssGetSFcnParam(S,(0x12d2+564-0x14fe))
#define zad3f2cd753             ((0x316+5061-0x16db))
#define zc2f3e0cbc0        ((0xf0d+131-0xf8f))
#define z0c20a7744a                ((0x102+4871-0x1407))
#define z98a09abdad                 ((0x2f0+3899-0x1228))
#define z2e6483d505              ((0xed3+4316-0x1fab))
#define z8caad2a8e6              ((0x4b+7325-0x1ce8))
#define z5bfe7a2613            ((0xde3+572-0x101e))
#define zc5ce4cb81a              ((0x131d+3519-0x20da))
#define zc4ce4213f7               ((0x1565+4034-0x2527))
#define z2b17e2ee3b              ((0x1ac0+1600-0x20ff))

#define z85a830b620                ((0x1026+3653-0x1e6a));
#define z8db90b478f                 ((0xc86+4066-0x1c68));
#define z566222c41e                  ((0x2b5+8087-0x224c));
#define z33c2d6ace6                 ((0xa10+6267-0x228a));
#define zf851d7576b                 ((0xf74+140-0xffe));
#define za6262af0c5            ((0x8d7+7556-0x265b));
#define z88b54fb810     ((0x1aed+2789-0x25d1));
#define z141532d9e2            ((0xb53+5717-0x21a6));
static char_T zea4cd01646[(0x678+1458-0xb2a)];typedef volatile struct z199830d680{
volatile uint32_T z592e200bad;
volatile uint32_T*ze467ac829e;
volatile uint32_T zad0f44b32f;
volatile uint32_T z0d3df49bb1;
volatile uint32_T z37045d746d;
volatile uint32_T z8179a91d7b;
volatile uint32_T*z0aa1aefd2d;
volatile uint32_T zbdff1f0f0c;
volatile uint32_T zcf249b6ea3;
volatile uint32_T zec1a4ba4e1;
volatile uint8_T z1def6086f7;
volatile uint8_T z851354b1dc;
volatile uint16_T zc75aeee1f2;
volatile uint32_T zfec283e685;
volatile uint32_T z9f6de8f7ae;
volatile uint32_T zda904ce628;
volatile uint32_T zca048d0cc2;
}z83d93efdde;
#define z551c6433ad        (0x1353+3500-0x20ff) 
#define z9ff50a1d47      (0x15b3+759-0x18a8) 
#define z60fa808c68      (0x11bf+3578-0x1fb3) 
#define za495e5447f  (0x9fa+845-0xd40) 
#define ze284f6dda4   (0x488+6084-0x1c44) 
#define zbd9cc3ea3e   (0x1422+29-0x1436) 
#define z72a2273697     (0x1e2+1624-0x830) 
#define zb538b13023  (0x975+4525-0x1b17) 
#define z082f6638ca     (0x464+1611-0xaa3) 
#define ze57bee66e7  (0x87f+2787-0x1355) 
#define ze8cdd8692c      (0x20+5769-0x169b) 
#define z48a21f4939  (0x195+6368-0x1a66) 
#define z6bd25a24d0  (0x2db+7800-0x2143) 
#define z3471c69077      (0x1cc+6031-0x194a) 
#define zf9faf82f5c  (0xc87+1033-0x107e) 
#define zf04451bb1a (0xc80+5114-0x2067) 
#define z6e73a222da   (0x109c+5750-0x26fe) 
#define z25384e33ac    (0xb85+4851-0x1e63) 

#define z08d0b4e518  (0x10f5+5417-0x261e) 
#define z3e27e0685c  (0x19dd+1228-0x1ea8) 
#define zc7139e459d  (0x1590+2457-0x1f27) 
#define zb7f318c2a8 (0x357+8345-0x23ed) 
#define zb7eaca017a   (0x1366+2998-0x1f18) 
struct zbea7874206{volatile uint32_T z14bc320aa4;volatile uint32_T zf7498a4592;volatile uint32_T z690d720321;volatile uint32_T z8727c368fa;volatile uint32_T z75f62ff613;volatile uint32_T zf4facab16c;volatile uint32_T z8cf87547ee;volatile uint32_T za1e3642b47;volatile uint32_T z9d4ac60381;volatile uint32_T ze4934072a9;volatile uint32_T z7a72a2666b;volatile uint32_T z6c201be134;volatile uint32_T z609e04d491;volatile uint32_T zfaeb77d74c;volatile uint32_T zad01750135;volatile uint32_T z68f2b9a029;};static void mdlInitializeSizes(SimStruct*S){uint16_T i;uint32_T zf91d71c6d9;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x153+5637-0x1758));ssSetNumDiscStates(S,(0xca4+2785-0x1785));ssSetNumInputPorts(S,(0x2330+878-0x269e));switch((uint32_T)mxGetPr(z186580de21)[(0x1d72+2367-0x26b1)]){case(0xed1+3225-0x1b69):
zf91d71c6d9=(uint32_T)mxGetPr(z2afc595703)[(0x74f+7368-0x2417)];break;case(0x1778+877-0x1ae3):
zf91d71c6d9=(uint32_T)mxGetPr(z2afc595703)[(0xdeb+4285-0x1ea8)]-(0xf5d+528-0x116c);break;case(0x127f+4022-0x2232):
zf91d71c6d9=(uint32_T)mxGetPr(z2afc595703)[(0xca+5752-0x1742)];break;}
ssSetNumOutputPorts(S,zf91d71c6d9);
for(i=(0xf84+1980-0x1740);i<zf91d71c6d9;i++){ssSetOutputPortWidth(S,i,(uint32_T)mxGetPr(zb0ce0940e9)[(0x27+6621-0x1a04)]);}ssSetNumSampleTimes(S,(0x810+6447-0x213e));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x206a+1517-0x2657));ssSetNumNonsampledZCs(S,(0x502+6041-0x1c9b));
for(i=(0x17a+7979-0x20a5);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x181f+364-0x198b));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x8c+7027-0x1bff)]==-1.0){ssSetSampleTime(S,(0x64a+4559-0x1819),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xb9+6057-0x1862),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x1448+2464-0x1de8),mxGetPr(z3832b85a32)[(0xd51+1882-0x14ab)]);ssSetOffsetTime(S,(0xa67+6394-0x2361),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;uint_T i,size;real_T z19c4ca5f82,start;uint32_T z366b2f03bf,z441f9e6d1b;uint32_T zf91d71c6d9,z8d0508b30e;int z154c53ff1b;int z406dced9ea;z83d93efdde*z612247fc60;volatile struct zbea7874206*zbea7874206;uint32_T zd33c3be778,z2c1768fde6,z8b9d33e44f,z80a2b1bccf;int za746b13f73;if(mxGetN(z702a26a5e9)==(0x1038+3332-0x1d3b)){z366b2f03bf=(0xbf7+5908-0x230b);z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x420+2425-0xd99)];}else{z366b2f03bf=(int_T)mxGetPr(z702a26a5e9)[(0x189+1526-0x77f)];z441f9e6d1b=(int_T)mxGetPr(z702a26a5e9)[(0x447+4585-0x162f)];}

if(xpcGetPCIDeviceInfo(z694756a014,zea87e0ba83,z29146a1837,zab7e64468b,z366b2f03bf,z441f9e6d1b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}
zeccbadd9b3.VirtAddress[(0x1da+327-0x321)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x1c04+2424-0x257c)],4096,XPC_RT_PG_USERREADWRITE);zeccbadd9b3.VirtAddress[(0x11e4+1971-0x1995)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0x3a5+6465-0x1ce4)],(0x14d0+775-0x7d7),XPC_RT_PG_USERREADWRITE);
zbea7874206=(struct zbea7874206*)(zeccbadd9b3.VirtAddress[(0x89b+4273-0x194a)]);
z612247fc60=(z83d93efdde*)(zeccbadd9b3.VirtAddress[(0x1015+2530-0x19f7)]+(0xa68+1950-0x1186));

switch((uint16_T)mxGetPr(zea2279958e)[(0x1211+2096-0x1a41)]){case(0xe18+2834-0x1929):
ssSetRWorkValue(S,z8caad2a8e6,3276.8);ssSetRWorkValue(S,z5bfe7a2613,10.0);zd33c3be778=z8db90b478f;z2c1768fde6=zf851d7576b;break;case(0x369+4215-0x13de):
ssSetRWorkValue(S,z8caad2a8e6,6553.6);ssSetRWorkValue(S,z5bfe7a2613,5.0);zd33c3be778=z8db90b478f;z2c1768fde6=z33c2d6ace6;break;case(0x180+3280-0xe4d):
ssSetRWorkValue(S,z8caad2a8e6,13107.2);ssSetRWorkValue(S,z5bfe7a2613,2.5);zd33c3be778=z8db90b478f;z2c1768fde6=z566222c41e;break;case(0xbd1+3178-0x1837):
ssSetRWorkValue(S,z8caad2a8e6,6553.6);ssSetRWorkValue(S,z5bfe7a2613,0.0);zd33c3be778=z85a830b620;z2c1768fde6=z33c2d6ace6;break;case(0xd1b+6165-0x252b):
ssSetRWorkValue(S,z8caad2a8e6,13107.2);ssSetRWorkValue(S,z5bfe7a2613,0.0);zd33c3be778=z85a830b620;z2c1768fde6=z566222c41e;break;}



zbea7874206->z14bc320aa4=((0x70c+2504-0x10d3)<<(0xcca+6708-0x26ef));start=rl32eGetTicksDouble();while((zbea7874206->z14bc320aa4&((0x16ac+2785-0x218c)<<(0x2a2+310-0x3c9)))==((0xc7d+5782-0x2312)<<(0xd4a+596-0xf8f))){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*1.0){
sprintf(zea4cd01646,"\x20\x20\x25\x73\x3a\x20\x74\x69\x6d\x65\x6f\x75\x74\x20\x64\x75\x72\x69\x6e\x67\x20\x69\x6e\x69\x74\x20\x6f\x70\x65\x72\x61\x74\x69\x6f\x6e",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}
#ifdef zec3e4ced3e
printf("\x20\x20\x25\x73\x3a\x20\x42\x6f\x61\x72\x64\x20\x72\x65\x73\x65\x74\x65\x64\x20\x74\x6f\x20\x61\x20\x6b\x6e\x6f\x77\x6e\x20\x73\x74\x61\x74\x65\x2e" "\n",zf1b619edf2);
#endif


zf91d71c6d9=(uint32_T)mxGetPr(z2afc595703)[(0x19d6+2765-0x24a3)];switch((uint16_T)mxGetPr(z186580de21)[(0xb46+802-0xe68)]){case(0xd4b+711-0x1011):z8b9d33e44f=za6262af0c5;z8d0508b30e=zf91d71c6d9-(0xd11+1601-0x1351);break;case(0x1890+1267-0x1d81):z8b9d33e44f=z88b54fb810;z8d0508b30e=zf91d71c6d9-(0x6a9+7223-0x22df);break;case(0xa57+4461-0x1bc1):z8b9d33e44f=z141532d9e2;z8d0508b30e=(0x15bb+1012-0x19ad)*zf91d71c6d9-(0xdec+4666-0x2025);break;}zbea7874206->ze4934072a9=(z8d0508b30e<<(0x9d3+4463-0x1b3a));
if((uint16_T)mxGetPr(z1c6ce8e1bc)[(0x13d+8870-0x23e3)]==(0xda8+6367-0x2686)){
#ifdef zec3e4ced3e
printf("\x20\x20\x25\x73\x3a\x20\x42\x6f\x61\x72\x64\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x65\x64\x20\x61\x73\x20\x61\x6e\x20\x48\x57\x20\x63\x6c\x6f\x63\x6b\x20\x2f\x20\x69\x6e\x69\x74\x69\x61\x74\x6f\x72\x2e" "\n",zf1b619edf2);
#endif
z80a2b1bccf=(0x602+211-0x6d5);
zbea7874206->z75f62ff613=((0x15d6+3308-0x22c1)<<(0x10d1+499-0x12b4))|(uint16_T)mxGetPr(zf5ee62a4ad)[(0x1e4+2224-0xa94)];zbea7874206->z9d4ac60381=(0x23aa+59-0x23de);
#ifdef zec3e4ced3e
printf("\x20\x20\x25\x73\x3a\x20\x53\x61\x6d\x70\x6c\x65\x20\x72\x61\x74\x65\x3a\x20\x25\x34\x2e\x35\x66\x5b\x4b\x48\x7a\x5d" "\n",zf1b619edf2,50000000.0/(double)mxGetPr(zf5ee62a4ad)[(0x15b1+4236-0x263d)]/(0xccf+878-0xc55));
#endif
}else{
#ifdef zec3e4ced3e
printf("\x20\x20\x25\x73\x3a\x20\x42\x6f\x61\x72\x64\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x65\x64\x20\x61\x73\x20\x61\x20\x74\x61\x72\x67\x65\x74" "\n",zf1b619edf2);
#endif
z80a2b1bccf=(0xbf6+585-0xe3d);zbea7874206->z9d4ac60381=((0x8f6+4031-0x18ae)|(z80a2b1bccf<<(0x966+3507-0x1716)));}



zbea7874206->z14bc320aa4=((0x19ba+1475-0x1f7c)<<(0x8a9+5602-0x1e85))|(zd33c3be778<<(0x10cc+4328-0x21b1))|(z2c1768fde6<<(0x9cf+7107-0x258e))|(z8b9d33e44f<<(0x1ed8+1776-0x25c0))|(0x152c+1079-0x18e3);
if(xpceIsModelInit()&&((int)mxGetPr(zd6d6a44c19)[(0x6d1+5559-0x1c88)]==(0x4bf+6828-0x1f6a))){

zbea7874206->z14bc320aa4|=((0x1de3+1519-0x23d1)<<(0x439+3115-0x1057));start=rl32eGetTicksDouble();
#ifdef zec3e4ced3e
printf("\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x73\x74\x61\x72\x74\x65\x64\x2e\x2e" "\n",zf1b619edf2);
#endif
while((zbea7874206->z14bc320aa4&((0x18bc+2537-0x22a4)<<(0xdf7+1924-0x156e)))==((0x161d+783-0x192b)<<(0x800+7864-0x26ab))){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*5.0){
sprintf(zea4cd01646,"\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x74\x69\x6d\x65\x64\x20\x6f\x75\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}
if((zbea7874206->z14bc320aa4&((0x119b+655-0x1429)<<(0x1f45+1889-0x2698)))==((0x553+3531-0x131d)<<(0xb08+957-0xeb7))){
#ifdef zec3e4ced3e
printf("\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x73\x75\x63\x63\x65\x65\x64\x65\x64\x2e" "\n",zf1b619edf2);
#endif
}else{sprintf(zea4cd01646,"\x20\x20\x25\x73\x20\x61\x75\x74\x6f\x63\x61\x6c\x69\x62\x72\x61\x74\x69\x6f\x6e\x20\x66\x61\x69\x6c\x65\x64",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}
za746b13f73=(int)mxGetPr(zb0ce0940e9)[(0xb03+3574-0x18f9)];
#ifdef zec3e4ced3e
printf("\x20\x20\x25\x73\x3a\x20\x46\x72\x61\x6d\x65\x20\x73\x69\x7a\x65\x20\x73\x65\x74\x20\x74\x6f\x20\x25\x64" "\n",zf1b619edf2,za746b13f73);
#endif
zbea7874206->z8727c368fa=zf91d71c6d9*za746b13f73-(0x2c+3198-0xca9);
#ifdef zec3e4ced3e 
printf("\x20\x20\x25\x73\x3a\x20\x50\x72\x65\x70\x61\x72\x69\x6e\x67\x20\x74\x68\x65\x20\x44\x4d\x41\x20\x70\x6f\x6f\x6c" "\n",zf1b619edf2);
#endif
size=zf91d71c6d9*za746b13f73*(0x225b+152-0x22ef);z154c53ff1b=(int)xpcAllocPhysicalMemory(size+(0x14a8+7177-0x20b1));for(i=(0x1bf8+909-0x1f85);i<size/(0x122b+270-0x1335);i++){*((int*)z154c53ff1b+i)=(0x284+9253-0x26a9);}z406dced9ea=z154c53ff1b;
z612247fc60->ze467ac829e=(uint32_T*)z406dced9ea;z612247fc60->zad0f44b32f=(0x1bfb+1769-0x22dc);z612247fc60->z0d3df49bb1=size;z612247fc60->z37045d746d=(0x808+3332-0x1502);z612247fc60->z592e200bad=138563;
ssSetIWorkValue(S,z98a09abdad,z154c53ff1b);ssSetIWorkValue(S,z0c20a7744a,z406dced9ea);ssSetPWorkValue(S,zc4ce4213f7,(void*)z612247fc60);ssSetIWorkValue(S,zad3f2cd753,zeccbadd9b3.VirtAddress[(0x2c2+220-0x39c)]);ssSetIWorkValue(S,zc2f3e0cbc0,(uint32_T)zf91d71c6d9);

#ifdef zec3e4ced3e
printf("\x20\x20\x25\x73\x3a\x20\x44\x4d\x41\x20\x63\x6f\x72\x72\x65\x63\x74\x6c\x79\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x65\x64" "\n",zf1b619edf2);
#endif
zbea7874206->z8727c368fa|=((0x85+2670-0xaf2)<<(0x1692+3458-0x2402));start=rl32eGetTicksDouble();while((zbea7874206->z8727c368fa&((0x127f+1796-0x1982)<<(0x1cb3+1168-0x2131)))==((0xc24+6617-0x25fc)<<(0x2cb+3837-0x11b6))){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*1.0){
sprintf(zea4cd01646,"\x20\x20\x25\x73\x3a\x20\x74\x69\x6d\x65\x6f\x75\x74\x20\x64\x75\x72\x69\x6e\x67\x20\x63\x6c\x65\x61\x72\x20\x62\x75\x66\x66\x65\x72\x20\x6f\x70\x65\x72\x61\x74\x69\x6f\x6e",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}if((zbea7874206->z8727c368fa&((0xd3c+1495-0x1312)<<(0x56f+3438-0x12ca)))==((0x3ab+7962-0x22c4)<<(0x1c0c+701-0x1eb6))){sprintf(zea4cd01646,"\x20\x20\x25\x73\x3a\x20\x63\x6c\x65\x61\x72\x20\x62\x75\x66\x66\x65\x72\x20\x6f\x70\x65\x72\x61\x74\x69\x6f\x6e\x20\x66\x61\x69\x6c\x65\x64",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}else{
#ifdef zec3e4ced3e
printf("\x20\x20\x25\x73\x3a\x20\x42\x75\x66\x66\x65\x72\x20\x63\x6c\x65\x61\x72\x65\x64" "\n",zf1b619edf2);
#endif
}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint16_T zf91d71c6d9=ssGetIWorkValue(S,zc2f3e0cbc0);volatile struct zbea7874206*zbea7874206=(struct zbea7874206*)ssGetIWorkValue(S,zad3f2cd753);uint32_T*databuf=(uint32_T*)ssGetIWorkValue(S,z0c20a7744a);uint32_T z8b9d33e44f=(uint32_T)mxGetPr(z186580de21)[(0x32f+2682-0xda9)];uint32_T za746b13f73=(int_T)mxGetPr(zb0ce0940e9)[(0x5e0+7387-0x22bb)];z83d93efdde*z7897fc6582=ssGetPWorkValue(S,zc4ce4213f7);real_T z0754dd67cc,offset;real_T*y;uint32_T i,z26dbd73a5e;uint32_T count,z8a7e6753de;z0754dd67cc=ssGetRWorkValue(S,z8caad2a8e6);offset=ssGetRWorkValue(S,z5bfe7a2613);
z8a7e6753de=(0x450+6248-0x1cb8);
for(i=(0xf2b+788-0x123f);i<za746b13f73;i++){for(z26dbd73a5e=(0x2ba+5555-0x186d);z26dbd73a5e<zf91d71c6d9;z26dbd73a5e++){count=databuf[z8a7e6753de];if(z8b9d33e44f==(0x6a2+3283-0x1374))
{y=ssGetOutputPortSignal(S,z26dbd73a5e);y[i]=(real_T)(count&65535)/z0754dd67cc-offset;}else if(z8b9d33e44f==(0x1ad2+1783-0x21c6))
{y=ssGetOutputPortSignal(S,z26dbd73a5e);y[i]=2.0*((real_T)(count&65535)/z0754dd67cc-offset);}else
{if(z26dbd73a5e>(0x1b7a+259-0x1c7d)){y=ssGetOutputPortSignal(S,z26dbd73a5e-(0x1f+796-0x33a));y[i]=2.0*((real_T)(count&65535)/z0754dd67cc-offset);}}z8a7e6753de++;}}z7897fc6582->z1def6086f7=((0x742+5555-0x1cf4)<<z08d0b4e518);z7897fc6582->z1def6086f7=((0x160d+1247-0x1aeb)<<z08d0b4e518)|((0x1734+93-0x1790)<<z3e27e0685c);
#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE
volatile struct zbea7874206*zbea7874206=(struct zbea7874206*)ssGetIWorkValue(S,zad3f2cd753);zbea7874206->z8727c368fa=zbea7874206->z8727c368fa|262144;
zbea7874206->z75f62ff613=zbea7874206->z75f62ff613|65536;
#endif        
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

