/* Copyright 2006-2013 Speedgoat GmbH. */
#define         DEBUG                   (0x1b28+2010-0x2302)
#define         S_FUNCTION_LEVEL        (0x1b8+8207-0x21c5)
#undef          S_FUNCTION_NAME
#define         S_FUNCTION_NAME         sg_IO601_cread_s
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
#define         z694756a014                (0x1250+3176-0xe03)
#define         zea87e0ba83                36912
#define         z29146a1837             (0x1b6f+3986-0x1a4c)
#define         zab7e64468b             10615
#define         zdf24515981          ((0x1ac4+504-0x1cb7))
#define         zbcb3e4d083              ssGetSFcnParam(S,(0x87+4801-0x1348))
#define         zd75b5280cf               ssGetSFcnParam(S,(0x635+8347-0x26cf))
#define         z11e8538834              ssGetSFcnParam(S,(0x17ea+621-0x1a55))
#define         z3832b85a32           ssGetSFcnParam(S,(0x4c6+5884-0x1bbf))
#define         z702a26a5e9                ssGetSFcnParam(S,(0x176d+3289-0x2442))
#define         z2e6483d505              ((0xd56+2376-0x169c))
#define         z57e55a08c5        ((0x66b+3677-0x14c8))
#define         z84eb1db314        ((0x952+6077-0x210e))
#define         zc5ce4cb81a              ((0xb7c+5073-0x1f4d))
#define         z2b17e2ee3b              ((0x660+5866-0x1d4a))
#ifndef MATLAB_MEX_FILE
#ifndef  zb84e0c3c3b
#define  zb84e0c3c3b(zc1d61b7d63)  *( (uint8_T *) &zc1d61b7d63)
#endif
#ifndef  z15e663b423
#define  z15e663b423(zc1d61b7d63)  *(((uint8_T *) &zc1d61b7d63) + (0x7d1+1420-0xd5c))
#endif
#ifndef  zfca7eb6338
#define  zfca7eb6338(zc1d61b7d63)  *( (uint16_T *) &zc1d61b7d63)
#endif
#ifndef  z3607971cd6
#define  z3607971cd6(zc1d61b7d63)  *(((uint16_T *) &zc1d61b7d63) + (0xfd+5452-0x1648))
#endif
#ifndef z0056adfa94
#define z0056adfa94(zc1d61b7d63)       { uint8_T z7be9105675; z7be9105675 = z15e663b423(zc1d61b7d63); z15e663b423(zc1d61b7d63) = (uint8_T) zc1d61b7d63; zb84e0c3c3b(zc1d61b7d63) = z7be9105675; }
#endif
#ifndef z8444fc96d2
#define z8444fc96d2(zc1d61b7d63)       { uint16_T z7be9105675; z7be9105675 = z3607971cd6(zc1d61b7d63); z3607971cd6(zc1d61b7d63) = (uint16_T) zc1d61b7d63; zfca7eb6338(zc1d61b7d63) = z7be9105675; }
#endif
#endif
static char_T zea4cd01646[(0x11e0+3938-0x2042)];
#ifndef MATLAB_MEX_FILE
extern uint8_T z199556e987[];static uint32_T zaf39b56932(uint32_T id){z0056adfa94(z3607971cd6(id));z0056adfa94(zfca7eb6338(id));z8444fc96d2(id);id=id>>(0x1543+492-0x171a);return id;}static uint32_T zdc2355eb74(uint32_T id){z0056adfa94(z3607971cd6(id));z0056adfa94(zfca7eb6338(id));z8444fc96d2(id);id=id>>(0x125+8945-0x2413);return id;}static unsigned char zf6c13379ed(double value,int n){unsigned char*p;p=(unsigned char*)&value;return p[n];}
#endif
static void mdlInitializeSizes(SimStruct*S){int_T i;DECL_AND_INIT_DIMSINFO(iDimsInfo);int z58ec39b04d[(0x90c+7632-0x26da)];
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x63d+948-0x9f1));ssSetNumDiscStates(S,(0x348+7521-0x20a9));iDimsInfo.width=(0x37a+652-0x600)*((int_T)mxGetPr(zd75b5280cf)[(0xa10+6849-0x24d1)]+(int_T)mxGetPr(zd75b5280cf)[(0x61+6993-0x1bb1)]);iDimsInfo.numDims=(0x181a+2268-0x20f4);iDimsInfo.dims=z58ec39b04d;z58ec39b04d[(0x9d3+5385-0x1edc)]=(int_T)mxGetPr(zd75b5280cf)[(0xebd+5445-0x2402)]+(int_T)mxGetPr(zd75b5280cf)[(0x899+5182-0x1cd6)];z58ec39b04d[(0x7f9+3202-0x147a)]=(0xe87+4190-0x1edf);if((int_T)mxGetPr(z11e8538834)[(0x171a+573-0x1957)]){ssSetNumOutputPorts(S,(0x484+1550-0xa90));ssSetOutputPortWidth(S,(0xf42+3857-0x1e52),(0x144a+999-0x182f));}else{ssSetNumOutputPorts(S,(0x64f+4459-0x17b9));}if(!ssSetOutputPortDimensionInfo(S,(0x9db+5017-0x1d74),&iDimsInfo))return;ssSetNumInputPorts(S,(0x8e1+389-0xa66));ssSetNumSampleTimes(S,(0x8d0+241-0x9c0));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,(0xf49+552-0x1171));ssSetNumModes(S,(0x165d+497-0x184e));ssSetNumNonsampledZCs(S,(0xb25+6839-0x25dc));for(i=(0x8c0+1869-0x100d);i<zdf24515981;i++){ssSetSFcnParamNotTunable(S,i);}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x8c+5101-0x1479),mxGetPr(z3832b85a32)[(0x5df+7623-0x23a6)]);if(mxGetN((z3832b85a32))==(0xa20+6115-0x2202)){ssSetOffsetTime(S,(0x1fc5+1566-0x25e3),0.0);}else{ssSetOffsetTime(S,(0x695+4402-0x17c7),mxGetPr(z3832b85a32)[(0x605+2692-0x1088)]);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zef529fae4a,*zdfcb1da404;void*ze2370ae9b9,*zf2db5722bf;volatile uint32_T*z3e5b8e05d8;volatile uint8_T*z27fd94ac66;volatile uint32_T*z706da0e1e5;uint8_T zc369e1e9c6;zc369e1e9c6=(uint8_T)mxGetPr(zbcb3e4d083)[(0x830+5680-0x1e60)]-(0xb99+6853-0x265d);if((int_T)mxGetPr(z702a26a5e9)[(0xa61+1783-0x1158)]<(0x147d+3762-0x232f)){if(rl32eGetPCIInfoExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x30c+5322-0x17d5)){z366b2f03bf=(0xedb+1571-0x14fe);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x124+8582-0x22aa)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x1f4d+308-0x2081)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xa20+1223-0xee6)];}if(rl32eGetPCIInfoAtSlotExt((uint16_T)z694756a014,(uint16_T)zea87e0ba83,(uint16_T)z29146a1837,(uint16_T)zab7e64468b,(z441f9e6d1b&(0x8b2+5291-0x1c5e))|((z366b2f03bf&(0x123b+4528-0x22ec))<<(0x826+5181-0x1c5b)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",zf1b619edf2,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zef529fae4a=(void*)zeccbadd9b3.BaseAddress[(0x1070+2640-0x1ac0)];ze2370ae9b9=rl32eGetDevicePtr(zef529fae4a,(0xc3f+1226-0xfe1),RT_PG_USERREADWRITE);z3e5b8e05d8=(volatile uint32_T*)ze2370ae9b9;
zdfcb1da404=(void*)zeccbadd9b3.BaseAddress[(0xfb5+1349-0x14f8)];zf2db5722bf=rl32eGetDevicePtr(zdfcb1da404,16384,RT_PG_USERREADWRITE);z27fd94ac66=(volatile uint8_T*)zf2db5722bf;z706da0e1e5=(volatile uint32_T*)zf2db5722bf;
ssSetIWorkValue(S,z57e55a08c5,(uint32_T)z3e5b8e05d8);ssSetIWorkValue(S,z84eb1db314,(uint32_T)z27fd94ac66);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
int_T i,z26dbd73a5e,m,z812c65ff2f;real_T*y;uint8_T zc369e1e9c6=(uint8_T)mxGetPr(zbcb3e4d083)[(0xfec+4359-0x20f3)]-(0x1721+923-0x1abb);uint8_T message[(0xdb+1260-0x5b3)];uint32_T za6dad42b7e[(0xb38+3832-0x1a2b)];volatile uint32_T*z3e5b8e05d8;volatile uint32_T*z706da0e1e5;uint32_T z5d9c31c2b6=ssGetIWorkValue(S,z57e55a08c5);uint32_T z31a846515d=ssGetIWorkValue(S,z84eb1db314);z3e5b8e05d8=(void*)z5d9c31c2b6;z706da0e1e5=(void*)z31a846515d;y=(real_T*)ssGetOutputPortSignal(S,(0x190+5636-0x1794));m=ssGetOutputPortWidth(S,(0x189+216-0x261))/(0xf11+2365-0x1848);
z812c65ff2f=z199556e987[(0x199c+572-0x1bd6)+zc369e1e9c6*(0x9d6+1493-0xfa7)];for(i=(0x10b5+5457-0x2606);i<(int_T)mxGetPr(zd75b5280cf)[(0xea4+2150-0x170a)];i++){for(z26dbd73a5e=(0xc71+5650-0x2283);z26dbd73a5e<(0x1ff0+1662-0x2669);z26dbd73a5e++){za6dad42b7e[z26dbd73a5e]=z706da0e1e5[(0x13e6+673-0x147f)+z812c65ff2f*(0x61c+3020-0x11e3)+z26dbd73a5e];
}
memcpy(message,za6dad42b7e,(0x702+4468-0x1862));if(message[(0x198+6382-0x1a86)]){z706da0e1e5[(0x1d6a+389-0x1ce7)+z812c65ff2f*(0x1c5a+1817-0x236e)+(0xd91+2448-0x1721)]=za6dad42b7e[(0x12+4107-0x101d)]&4294967040;z812c65ff2f++;if(z812c65ff2f==(0x6cb+6366-0x1f77))z812c65ff2f=(0x17d5+1537-0x1dd6);y[i+m*(0x1eba+604-0x2116)]=1.0;if((message[(0x237+1252-0x714)]&(0x1ab+934-0x4d1))==(0x213d+167-0x21e4)){
y[i+m*(0x1274+4074-0x225d)]=(real_T)zaf39b56932(message[(0xc49+1510-0x1227)]|(message[(0x1e87+1079-0x22b5)]<<(0x624+5733-0x1c81)));y[i+m*(0x41f+8164-0x2401)]=1.0;
y[i+m*(0x195b+2864-0x2486)]=(real_T)*((real_T*)&message[(0x59f+1783-0xc8c)]);}else{y[i+m*(0x202a+314-0x2163)]=(real_T)zdc2355eb74(message[(0x141c+3452-0x2190)]|(message[(0xaf5+3244-0x1798)]<<(0xd+8498-0x2137))|(message[(0x1220+1921-0x1997)]<<(0x18dc+2506-0x2296))|(message[(0x2314+861-0x2666)]<<(0x7eb+3366-0x14f9)));y[i+m*(0x1e4f+1295-0x235c)]=9.0;
y[i+m*(0xab1+5193-0x1ef5)]=(real_T)*((real_T*)&message[(0x325+9138-0x26cb)]);}y[i+m*(0xdc9+345-0xf1f)]=message[(0x20aa+169-0x214c)]&(0x1bc0+1276-0x20ad);y[i+m*(0x26c+4483-0x13eb)]=(real_T)*((uint32_T*)&message[(0xaab+1816-0x11c1)]);}else{y[i+m*(0x1f2c+1727-0x25eb)]=0.0;y[i+m*(0xa64+3751-0x190a)]=-1.0;y[i+m*(0xeef+4853-0x21e2)]=0.0;y[i+m*(0x558+8546-0x26b7)]=0.0;y[i+m*(0xf1b+4982-0x228d)]=-1.0;y[i+m*(0x982+60-0x9b9)]=0.0;}}z199556e987[(0x21a3+669-0x243e)+zc369e1e9c6*(0xf6+8061-0x206f)]=z812c65ff2f;z812c65ff2f=z199556e987[(0x2a+4093-0x1024)+zc369e1e9c6*(0x1198+324-0x12d8)];
for(i=(int_T)mxGetPr(zd75b5280cf)[(0xd38+3593-0x1b41)];i<(int_T)mxGetPr(zd75b5280cf)[(0xe21+222-0xeff)]+(int_T)mxGetPr(zd75b5280cf)[(0x14e1+3178-0x214a)];i++){for(z26dbd73a5e=(0x10c9+588-0x1315);z26dbd73a5e<(0xb32+1434-0x10c7);z26dbd73a5e++){za6dad42b7e[z26dbd73a5e]=z706da0e1e5[(0x1721+3222-0x20b5)+z812c65ff2f*(0x9f2+7372-0x26b9)+z26dbd73a5e];
}
memcpy(message,za6dad42b7e,(0x1c7+8590-0x2341));



if(message[(0xdf0+4090-0x1dea)]){z706da0e1e5[(0xc0b+1700-0xfad)+z812c65ff2f*(0x12cd+3230-0x1f66)+(0x9fa+1725-0x10b7)]=za6dad42b7e[(0x8cc+2322-0x11de)]&4294967040;z812c65ff2f++;if(z812c65ff2f==(0xca9+6580-0x262b))z812c65ff2f=(0x2223+558-0x2451);y[i+m*(0x1a01+487-0x1be8)]=2.0;if((message[(0xd10+5769-0x2392)]&(0x19e5+771-0x1c68))==(0x10e3+3646-0x1f21)){
y[i+m*(0xd04+2726-0x17a9)]=(real_T)zaf39b56932(message[(0x6e0+6936-0x21f0)]|(message[(0x3c4+2945-0xf3c)]<<(0x116d+2330-0x1a7f)));y[i+m*(0x660+4250-0x16f8)]=1.0;
y[i+m*(0x18d2+1672-0x1f55)]=(real_T)*((real_T*)&message[(0x84d+3197-0x14c0)]);}else{y[i+m*(0x992+1435-0xf2c)]=(real_T)zdc2355eb74(message[(0x1a05+2267-0x22d8)]|(message[(0xaf7+3273-0x17b7)]<<(0x2d1+3482-0x1063))|(message[(0x17dc+1605-0x1e17)]<<(0x33f+7138-0x1f11))|(message[(0x1268+4193-0x22be)]<<(0x4ef+8476-0x25f3)));y[i+m*(0x764+3256-0x141a)]=9.0;
y[i+m*(0xcc4+5331-0x2192)]=(real_T)*((real_T*)&message[(0x368+7687-0x2163)]);}y[i+m*(0x941+284-0xa5a)]=message[(0x7d6+2529-0x11b0)]&(0x737+4819-0x19fb);y[i+m*(0x1205+2817-0x1d02)]=(real_T)*((uint32_T*)&message[(0x89c+968-0xc62)]);}else{y[i+m*(0xb14+1615-0x1163)]=0.0;y[i+m*(0x679+4643-0x189b)]=-1.0;y[i+m*(0x137f+3272-0x2045)]=0.0;y[i+m*(0xee7+2065-0x16f5)]=0.0;y[i+m*(0xfeb+5621-0x25dc)]=-1.0;y[i+m*(0x9a1+4634-0x1bb6)]=0.0;}}z199556e987[(0x7c1+5574-0x1d84)+zc369e1e9c6*(0x123f+3726-0x20c9)]=z812c65ff2f;if((int_T)mxGetPr(z11e8538834)[(0x112c+3482-0x1ec6)]){y=(real_T*)ssGetOutputPortSignal(S,(0x12b+3728-0xfba));if(!ssGetT(S)>0.0){y[(0xb31+2543-0x1520)]=0.0;y[(0x1249+4196-0x22ac)]=0.0;}else{y[(0x1404+667-0x169f)]=0.0;y[(0x17da+2162-0x204b)]=0.0;}}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef  MATLAB_MEX_FILE    
#include "simulink.c"      
#else
#include "cg_sfun.h"       
#endif

