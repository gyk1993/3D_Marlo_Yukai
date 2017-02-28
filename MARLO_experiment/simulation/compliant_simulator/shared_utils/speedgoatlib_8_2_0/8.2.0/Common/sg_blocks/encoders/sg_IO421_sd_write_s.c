/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x1e22+1793-0x2521)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO421_sd_write_s
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
#define zdf24515981              ((0x44b+94-0x49c))
#define za9d8fb6bcf                 ssGetSFcnParam(S,  (0x15c+7585-0x1efd))
#define z86992bd6b1                 ssGetSFcnParam(S,  (0x305+7956-0x2218)) 
#define zb377f6022b              ssGetSFcnParam(S,  (0xc83+2712-0x1719))
#define zf8013dab26              ssGetSFcnParam(S,  (0x21c7+410-0x235e))
#define zd1642a12cf                   ssGetSFcnParam(S,  (0x15ef+994-0x19cd))
#define zf4fcbe5b7a              ssGetSFcnParam(S,  (0x641+3013-0x1201))
#define zc5ef14af8b            ssGetSFcnParam(S,  (0x1add+741-0x1dbc))
#define z47eb233d6d            ssGetSFcnParam(S,  (0x1292+2711-0x1d22))
#define zdde7341751     ssGetSFcnParam(S,  (0x208a+166-0x2128))
#define z30665ac3eb      ssGetSFcnParam(S,  (0x4a7+7468-0x21ca))
#define z04abba38a8             ssGetSFcnParam(S, (0x11cd+1980-0x197f))
#define z3832b85a32               ssGetSFcnParam(S, (0xdb8+989-0x118a))
#define z702a26a5e9                    ssGetSFcnParam(S, (0x19a5+2405-0x22fe))  
#define z2e6483d505              ((0x4c2+1327-0x9ef))
#define z7e2eeaa57c          ((0x569+7600-0x2319))
#define z6a0da049de         ((0x591+5407-0x1aaf))
#define zc5ce4cb81a              ((0x1df7+369-0x1f68))
#define z2b17e2ee3b              ((0xd1f+5128-0x2127))
#define z41461d72db                (  (0xe95+5763-0x2518) / (0x17f5+1715-0x1ea6))    
#define z5cef2be5f7               (  (0x15b6+4444-0x270e) / (0x1801+1576-0x1e27))    
#define zf8ea1b5074             ( (0xaa4+2397-0x139d) / (0xd8b+1859-0x14cc))    
#define zb739c3a233          ( (0x3e5+6771-0x1de8) / (0x561+8576-0x26df))    
#define z3ee92efa11            ( (0x1233+1810-0x18c5) / (0x3b7+8876-0x2661))    
#define z8bd1607860        	   ( (0xbe8+2971-0x16f7) / (0x384+6705-0x1db3))    
#define z0776aaf5ff       ( (0x11f9+2103-0x1998) / (0x1293+929-0x1632))    
#define z8e70620702                     ( (0x708+4943-0x19a7) / (0x788+4724-0x19fa))    
#define zad6a77448e                  ( (0x129c+4252-0x2278) / (0xa87+4299-0x1b50))    
#define z78f921705c                 ( (0x1098+933-0x1379) / (0x1319+76-0x1363))    
#define ze55d123c04                      ( (0x19dd+341-0x1a4e) / (0x11e8+2678-0x1c5c))    
#define zc7bb7885c5                ((0x196f+638-0x1aed) / (0x3e4+8006-0x2328))    
#define z127ba20791               ((0x1098+3204-0x1c18) / (0x9cf+5972-0x2121))    
#define zad28482c68            ((0x257f+377-0x25b8) / (0x1259+4722-0x24c9))    
#define zd67a06ced0           ((0x1832+3187-0x2361) / (0xe33+3550-0x1c0f))    
#define zf4383b38ab               ((0x17ef+1243-0x1b6a) / (0xdb3+2465-0x1752))    
#define z330941fece              ((0xfab+562-0x1079) / (0x64+9417-0x252b))    
#define z42fe744553                     ((0x625+4609-0x16a6) / (0x1c0+3313-0xeaf))    
#define za2dd4548ab                          ((0x2d1+6083-0x1910) / (0x1f82+1118-0x23de))    
#define z3b74416723                   ((0x11e9+5354-0x254b) / (0x42a+1303-0x93f))    
#define z0b2e734a37                     ((0x215+8957-0x2386) / (0x1b91+1461-0x2144))    
#define z721ac69294                   ((0x9cd+6822-0x22e3) / (0x1c8f+1757-0x236a))    
#define z31b9c5d818                   ((0x996+333-0x94b) / (0x132a+1603-0x196b))    
#define zd08093bdbf            ((0x10c1+6116-0x2705) / (0x426+8052-0x2398))    
#define ze1ebb6d76d             ((0x1c7+7555-0x1d9e) / (0x1443+1737-0x1b0a))    
#define z10f4d4776a              ((0xe84+372-0xe38) / (0xf7+3980-0x1081))    
#define zc1dfad6ec0                 ((0x1592+1584-0x19fa) / (0x690+5536-0x1c2e))    
#define zfae0b3ba46                ((0x1a8b+2165-0x2134) / (0x17da+1334-0x1d0e))    
#define z4ae738a948                ((0x679+3929-0x1402) / (0x1f9a+1561-0x25b1))    
#define z2318caedff                    ((0x3dd+8995-0x2518) / (0x1d5a+876-0x20c4))    
#define z0020200104                 ((0x1bf7+779-0x1d0e) / (0xd49+923-0x10e2))    
#define zf5f82e67c2                  ((0x6f3+5971-0x1aa6) / (0x707+7808-0x2585))    
#define z1901723e57                   ((0x1b6d+2686-0x2247) / (0x2c+6795-0x1ab5))    
#define za991ebbbaf                        ((0x7fc+8298-0x2166) / (0x884+1501-0xe5f))    
#define zb4741c5d85                 ((0x1019+2557-0x12ae) / (0x1786+3532-0x2550))    
#define z76b2e8cf70                 ((0x885+9660-0x26d5) / (0xa6+2812-0xba0))    
#define z66ef01412c                    ((0x258f+1068-0x224b) / (0x41d+5242-0x1895))    
#define zb44a118adc                   ((0xadb+659-0x5fa) / (0x1a3+3964-0x111d))    
#define zee468a647c                     ((0x1627+5823-0x256e) / (0x78c+3415-0x14e1))    
#define zdcbd1b7a19                           (3.1415926535897932384626433832795)
static char_T zea4cd01646[(0x1739+3290-0x2313)];static void mdlInitializeSizes(SimStruct*S){uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x1c1c+2769-0x26ed));ssSetNumDiscStates(S,(0x1ea+4651-0x1415));if((uint32_T)mxGetPr(zc5ef14af8b)[(0xe84+415-0x1023)]==(0xf35+3176-0x1b9b))
{ssSetNumInputPorts(S,(0xb92+6384-0x247f));ssSetInputPortWidth(S,(0x1a9d+1405-0x201a),(uint32_T)mxGetN(za9d8fb6bcf));ssSetInputPortDataType(S,(0xdf5+1260-0x12e1),SS_DOUBLE);ssSetInputPortDirectFeedThrough(S,(0x525+2804-0x1019),(0x1a11+2155-0x227b));ssSetInputPortRequiredContiguous(S,(0x2057+1665-0x26d8),(0x1293+3336-0x1f9a));ssSetInputPortWidth(S,(0xaed+6684-0x2508),(uint32_T)mxGetN(za9d8fb6bcf));ssSetInputPortDataType(S,(0x46+4531-0x11f8),SS_DOUBLE);ssSetInputPortDirectFeedThrough(S,(0x1894+2690-0x2315),(0x1714+1494-0x1ce9));ssSetInputPortRequiredContiguous(S,(0x2467+401-0x25f7),(0x1e26+1304-0x233d));ssSetInputPortWidth(S,(0x99f+6358-0x2273),(uint32_T)mxGetN(za9d8fb6bcf));ssSetInputPortDataType(S,(0xe9c+994-0x127c),SS_DOUBLE);ssSetInputPortDirectFeedThrough(S,(0x18a8+1152-0x1d26),(0xa58+4611-0x1c5a));ssSetInputPortRequiredContiguous(S,(0x2168+1109-0x25bb),(0xda0+712-0x1067));}else
{ssSetNumInputPorts(S,(0x916+2171-0x1190));ssSetInputPortWidth(S,(0x23d+3051-0xe28),(uint32_T)mxGetN(za9d8fb6bcf));ssSetInputPortDataType(S,(0xde4+4893-0x2101),SS_DOUBLE);ssSetInputPortDirectFeedThrough(S,(0x2495+570-0x26cf),(0x1d51+1861-0x2495));ssSetInputPortRequiredContiguous(S,(0x1238+817-0x1569),(0x3d+8412-0x2118));}ssSetNumOutputPorts(S,(0x821+1774-0xf0f));ssSetNumSampleTimes(S,(0x1e4d+568-0x2084));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x1497+4004-0x243b));ssSetNumNonsampledZCs(S,(0x282+3773-0x113f));for(i=(0x217c+696-0x2434);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0xf19+2595-0x193c));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0x144f+2176-0x1ccf)]==-1.0){ssSetSampleTime(S,(0x99b+4317-0x1a78),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x22+3696-0xe92),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x229+5808-0x18d9),mxGetPr(z3832b85a32)[(0x9e1+2330-0x12fb)]);ssSetOffsetTime(S,(0x8bc+1124-0xd20),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint16_T*za42cf7dd4a;uint16_T z6f813cde47,za4a2434e08;uint32_T i,z4e3026977c,z4da0d16710,val;uint16_T zd0072007fc;real_T z19c4ca5f82,start;za4a2434e08=30354;z6f813cde47=(0x169d+9357-0x257e);if((int_T)mxGetPr(z702a26a5e9)[(0x2124+272-0x2234)]<(0xdd2+2448-0x1762)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x49\x4f\x34\x32\x31\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74\x2e");ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x1501+2019-0x1ce3)){z366b2f03bf=(0x2bc+1101-0x709);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xc60+3760-0x1b10)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x5ac+5843-0x1c7f)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x9e1+3498-0x178a)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0xa89+3062-0x1580))|((z366b2f03bf&(0x15b6+1711-0x1b66))<<(0x617+4861-0x190c)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x49\x4f\x34\x32\x32\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74\x2e",z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x5a3+3720-0x142b)];Virtual=rl32eGetDevicePtr(z1cf2c50191,32768,RT_PG_USERREADWRITE);za42cf7dd4a=(volatile uint16_T*)Virtual;ssSetIWorkValue(S,z6a0da049de,(uint32_T)za42cf7dd4a);if(!xpceIsModelInit()){switch((uint32_T)mxGetPr(z86992bd6b1)[(0x1e62+1539-0x2465)]){case(0x7e3+7484-0x251e):zd0072007fc=(0xc86+2203-0x1521);break;case(0xc5f+5411-0x2180):zd0072007fc=(0xd38+2568-0xf40);break;case(0x516+8484-0x2637):zd0072007fc=4096;break;}



for(i=(0x2021+1737-0x26ea);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x445+941-0x7f1);
val=(uint32_T)(mxGetPr(zb377f6022b)[i]*(0x4ef+6943-0x1faa));za42cf7dd4a[zd0072007fc/(0x13ad+565-0x15e0)+zad28482c68+z4e3026977c*(0x10c2+325-0x1203)]=val&65535;

za42cf7dd4a[zd0072007fc/(0x16c9+3609-0x24e0)+zd67a06ced0+z4e3026977c*(0xdf5+4892-0x210d)]=(val>>(0x220+2861-0xd3d))&65535;
}


for(i=(0xa57+2755-0x151a);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x339+7485-0x2075);
val=(uint32_T)(mxGetPr(zf8013dab26)[i]*(0x188+3409-0xe75));za42cf7dd4a[zd0072007fc/(0x1190+178-0x1240)+zf4383b38ab+z4e3026977c*(0xf92+625-0x11ff)]=val&65535;

za42cf7dd4a[zd0072007fc/(0xd7+5873-0x17c6)+z330941fece+z4e3026977c*(0x1892+9-0x1897)]=(val>>(0x3b4+4879-0x16b3))&65535;}
for(i=(0xd19+2198-0x15af);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1ae8+1519-0x20d6);val=(uint32_T)(mxGetPr(zb377f6022b)[i]*(0xf6a+4617-0x210f)*0.9);za42cf7dd4a[zd0072007fc/(0x1201+2846-0x1d1d)+z8bd1607860+z4e3026977c*(0xd00+4037-0x1cc3)]=val;}
for(i=(0x1bfa+301-0x1d27);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xc58+6450-0x2589);val=(uint32_T)(mxGetPr(zf8013dab26)[i]*(0xb3a+451-0xc99)*0.9);za42cf7dd4a[zd0072007fc/(0x11cc+5425-0x26fb)+z3ee92efa11+z4e3026977c*(0x1e00+416-0x1f9e)]=val;}


za42cf7dd4a[zd0072007fc/(0x344+8750-0x2570)+za2dd4548ab]=(uint16_T)(mxGetPr(zd1642a12cf)[(0x741+3076-0x1345)]);




val=za42cf7dd4a[zd0072007fc/(0x1217+3311-0x1f04)+z0b2e734a37];for(i=(0x205f+693-0x2314);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1724+3053-0x2310);if((uint32_T)mxGetPr(zf4fcbe5b7a)[i]){val|=((0x98a+7359-0x2648)<<z4e3026977c);}else{val&=~((0x57f+8348-0x261a)<<z4e3026977c);}}za42cf7dd4a[zd0072007fc/(0x134c+1359-0x1899)+z0b2e734a37]=val;


val=za42cf7dd4a[zd0072007fc/(0x54+8749-0x227f)+z721ac69294];for(i=(0x1465+835-0x17a8);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xad7+714-0xda0);if((uint32_T)mxGetPr(zc5ef14af8b)[i]){val|=((0x2b6+6935-0x1dcc)<<z4e3026977c);}else{val&=~((0x922+5310-0x1ddf)<<z4e3026977c);}}za42cf7dd4a[zd0072007fc/(0xff0+2597-0x1a13)+z721ac69294]=val;



val=za42cf7dd4a[zd0072007fc/(0x455+171-0x4fe)+z31b9c5d818];for(i=(0x91b+4755-0x1bae);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1acc+80-0x1b1b);if((uint32_T)mxGetPr(z47eb233d6d)[i]){val|=((0x1020+3239-0x1cc4)<<(0x42a+3566-0x1216)*z4e3026977c);
}else{val&=~((0x508+707-0x7c8)<<(0xf1d+5790-0x25b9)*z4e3026977c);
}}za42cf7dd4a[zd0072007fc/(0x1d6+1455-0x783)+z31b9c5d818]=val;



for(i=(0x41c+7873-0x22dd);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1075+2380-0x19c0);za42cf7dd4a[zd0072007fc/(0x408+903-0x78d)+zd08093bdbf+z4e3026977c*(0x797+7059-0x2328)]=(0x75+5195-0x1497);}
for(i=(0x9e9+3199-0x1668);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x168b+1859-0x1dcd);za42cf7dd4a[zd0072007fc/(0xe90+4875-0x2199)+z2318caedff+z4e3026977c*(0x123c+1491-0x180d)]=(int16_T)(mxGetPr(z04abba38a8)[i]*10.0);}z4da0d16710=(0x22a8+221-0x2385);for(i=(0x19af+2092-0x21db);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xb06+3162-0x175f);z4da0d16710|=((0x8f+3755-0xf39)<<z4e3026977c);}za42cf7dd4a[zd0072007fc/(0x129b+5144-0x26b1)+zc1dfad6ec0]=z4da0d16710;xpcBusyWait(0.5);za42cf7dd4a[zd0072007fc/(0x9ff+1264-0xeed)+z10f4d4776a]=(z4da0d16710<<(0x6a7+1530-0xc9d));printf("\x57\x61\x69\x74\x20\x32\x20\x73\x65\x63\x6f\x6e\x64\x73\x20\x74\x6f\x20\x70\x68\x61\x73\x65\x20\x6c\x6f\x63\x6b\x20\x77\x69\x74\x68\x20\x74\x68\x65\x20\x72\x65\x66\x65\x72\x65\x6e\x63\x65\x2e" "\n");xpcBusyWait((0x76f+4542-0x192b));for(i=(0x3ea+7634-0x21bc);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x72c+4354-0x182d);
za42cf7dd4a[zd0072007fc/(0x318+8710-0x251c)+zad6a77448e+z4e3026977c*(0xdb+6993-0x1c28)]=(0x33+2010-0x80d);
za42cf7dd4a[zd0072007fc/(0x8b4+3650-0x16f4)+z78f921705c+z4e3026977c*(0x1cb+8847-0x2456)]=(0xd37+629-0xfac);}
for(i=(0x574+5478-0x1ada);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xe3a+4805-0x20fe);za42cf7dd4a[zd0072007fc/(0x6f1+7646-0x24cd)+zc7bb7885c5+z4e3026977c*(0x1bf9+2116-0x2439)]=(0x9e2+2666-0x144c);za42cf7dd4a[zd0072007fc/(0x656+8130-0x2616)+z127ba20791+z4e3026977c*(0xa0c+5583-0x1fd7)]=(0x741+3805-0x161e);}


if(za42cf7dd4a[zd0072007fc/(0x5ec+6088-0x1db2)+z42fe744553]!=(0x1958+2439-0x22db)){
xpcBusyWait((0x1b53+779-0x1e5c));za42cf7dd4a[zd0072007fc/(0x58+3414-0xdac)+z42fe744553]=(0x14c4+3001-0x2079);za42cf7dd4a[zd0072007fc/(0x1446+3176-0x20ac)+z3b74416723]=(0xfb3+4090-0x1fad);start=rl32eGetTicksDouble();while(za42cf7dd4a[zd0072007fc/(0xaeb+4170-0x1b33)+z3b74416723]!=(0xba6+3396-0x1895)){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*1.0)
{sprintf(zea4cd01646,"\x49\x4f\x34\x32\x31\x3a\x20\x54\x65\x73\x74\x20\x44\x32\x20\x66\x61\x69\x6c\x65\x64");ssSetErrorStatus(S,zea4cd01646);return;}}
}printf("\x44\x2f\x53\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x65\x64\x20\x28\x73\x6c\x6f\x74\x3a\x20\x25\x64\x29\x2e" "\n",(uint32_T)mxGetPr(z86992bd6b1)[(0xf7+5909-0x180c)]);






}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE   
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint16_T*za42cf7dd4a;uint16_T zd0072007fc;int32_T z6fafebb892,zdfe762b8d2;uint32_T i,z4e3026977c,zcd308d01c9;real_T*in;za42cf7dd4a=(void*)base;
switch((uint32_T)mxGetPr(z86992bd6b1)[(0x176f+2230-0x2025)]){case(0x15a3+3381-0x22d7):zd0072007fc=(0x180d+1020-0x1c09);break;case(0x1890+66-0x18d0):zd0072007fc=(0x2097+971-0x1c62);break;case(0xdeb+1167-0x1277):zd0072007fc=(0x2510+3920-0x2460);break;}zcd308d01c9=(0x162+2385-0xab3);for(i=(0x1769+2167-0x1fe0);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xd48+6309-0x25ec);zcd308d01c9|=((0xd37+5208-0x218e)<<z4e3026977c);}if((uint32_T)mxGetPr(zc5ef14af8b)[(0x700+5751-0x1d77)]==(0x1a5c+2290-0x234c))
{
in=(real_T*)ssGetInputPortSignal(S,(0x19af+2339-0x22d1));for(i=(0x1010+3634-0x1e42);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x160a+4038-0x25cf);z6fafebb892=(uint32_T)(in[i]/0.00000008381903171539306640625*180.0/zdcbd1b7a19);

za42cf7dd4a[zd0072007fc/(0x1a08+2640-0x2456)+zad6a77448e+z4e3026977c*(0x7eb+1671-0xe6e)]=z6fafebb892&65535;za42cf7dd4a[zd0072007fc/(0xb06+620-0xd70)+z78f921705c+z4e3026977c*(0x1074+3538-0x1e42)]=(z6fafebb892>>(0x1f1a+77-0x1f57))&65535;
}
in=(real_T*)ssGetInputPortSignal(S,(0x6d+4434-0x11bf));for(i=(0x483+1755-0xb5e);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x2121+739-0x2403);zdfe762b8d2=(uint32_T)(in[i]*24000.0);za42cf7dd4a[zd0072007fc/(0x6ef+7322-0x2387)+zc7bb7885c5+z4e3026977c*(0x1851+3033-0x2426)]=zdfe762b8d2&65535;za42cf7dd4a[zd0072007fc/(0x21b+452-0x3dd)+z127ba20791+z4e3026977c*(0x6ab+7188-0x22bb)]=(zdfe762b8d2>>(0x110b+1491-0x16ce)&65535);

}
in=(real_T*)ssGetInputPortSignal(S,(0xf02+5797-0x25a5));for(i=(0x3f7+8887-0x26ae);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0xcb4+945-0x1064);z6fafebb892=(uint32_T)(in[i]/0.0054931640625*180.0/zdcbd1b7a19);za42cf7dd4a[zd0072007fc/(0x81d+1138-0xc8d)+ze55d123c04+z4e3026977c*(0xc61+2053-0x1464)]=z6fafebb892&65535;}
za42cf7dd4a[zd0072007fc/(0x469+3971-0x13ea)+zf5f82e67c2]=zcd308d01c9;
}else if((uint32_T)mxGetPr(zc5ef14af8b)[(0xb1+5897-0x17ba)]==(0x7bf+2708-0x1250))
{
in=(real_T*)ssGetInputPortSignal(S,(0xf68+4829-0x2245));for(i=(0x280+1462-0x836);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x2128+449-0x22e8);z6fafebb892=(uint32_T)(in[i]/0.00000008381903171539306640625*180.0/zdcbd1b7a19);

za42cf7dd4a[zd0072007fc/(0xbc2+2420-0x1534)+zad6a77448e+z4e3026977c*(0x1a6a+1952-0x2206)]=z6fafebb892&65535;za42cf7dd4a[zd0072007fc/(0xcf6+3713-0x1b75)+z78f921705c+z4e3026977c*(0x1797+365-0x1900)]=(z6fafebb892>>(0x525+4181-0x156a))&65535;
}}else
{
in=(real_T*)ssGetInputPortSignal(S,(0xa14+7176-0x261c));for(i=(0xa96+2746-0x1550);i<(uint32_T)mxGetN(za9d8fb6bcf);i++){z4e3026977c=(uint32_T)mxGetPr(za9d8fb6bcf)[i]-(0x1766+2549-0x215a);zdfe762b8d2=(uint32_T)(in[i]*360.0/0.015);za42cf7dd4a[zd0072007fc/(0x80c+116-0x87e)+zc7bb7885c5+z4e3026977c*(0x8e9+5913-0x1ffe)]=zdfe762b8d2&65535;za42cf7dd4a[zd0072007fc/(0xa16+647-0xc9b)+z127ba20791+z4e3026977c*(0x8cf+3738-0x1765)]=(zdfe762b8d2>>(0xe0f+2738-0x18b1)&65535);

}
za42cf7dd4a[zd0072007fc/(0x398+2236-0xc52)+zf5f82e67c2]=zcd308d01c9;
}



#endif
}static void mdlTerminate(SimStruct*S){
#ifndef MATLAB_MEX_FILE    
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint16_T*za42cf7dd4a;uint16_T zd0072007fc;za42cf7dd4a=(void*)base;
switch((uint32_T)mxGetPr(z86992bd6b1)[(0x77d+5981-0x1eda)]){case(0x8db+5250-0x1d5c):zd0072007fc=(0xaba+4593-0x1cab);break;case(0x89f+286-0x9bb):zd0072007fc=(0x1192+1656-0x100a);break;case(0x1d81+48-0x1dae):zd0072007fc=(0x1f77+4320-0x2057);break;}za42cf7dd4a[zd0072007fc/(0xa69+5863-0x214e)+zf5f82e67c2]=(0x1672+3365-0x2397);za42cf7dd4a[zd0072007fc/(0x253+5854-0x192f)+z10f4d4776a]=(0x748+6023-0x1ecf);
#endif
}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

