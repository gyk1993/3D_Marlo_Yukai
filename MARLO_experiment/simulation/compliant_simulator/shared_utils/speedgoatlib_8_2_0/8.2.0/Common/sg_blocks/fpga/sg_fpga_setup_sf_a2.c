/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x51c+6417-0x1e2b)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_setup_sf_a2
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

#define zd4c1aa112f             (0x8a1+7450-0x25bb)

#define za7281dd535   (0x7bd+2677-0x1232) 
#define zc2643045c9   (0xb4c+4779-0x1df7) 

#define ze3709fd80f				(0.0001)
#define ze986289b1a				(0.1)
#define z533b11d03f           ssGetSFcnParam(S,(0x894+2864-0x13c4))
#define zf81a32dab8           ssGetSFcnParam(S,(0x1147+2810-0x1c40))
#define z702a26a5e9                ssGetSFcnParam(S,(0x2cb+3459-0x104c))
#define z031790c9fa         ssGetSFcnParam(S,(0xe14+5047-0x21c8))
#define z68a97c472d					ssGetSFcnParam(S,(0xe34+5878-0x2526))
#define z7ac839cabf						ssGetSFcnParam(S,(0x30a+372-0x479))
#define DIR						ssGetSFcnParam(S,(0x503+8710-0x2703))
#define zdf24515981          				((0x16d5+48-0x16fe))
#define z6a0da049de         ((0x7d2+6375-0x20b9))
#define z2e6483d505              ((0x36a+3975-0x12f0))
#define zc5ce4cb81a              ((0x11e9+2799-0x1cc8))
#define z2b17e2ee3b              ((0x1141+2939-0x1cbc))
#define z4945c9b364           (671744)
static char_T zea4cd01646[(0xa22+3927-0x1879)];typedef struct{volatile uint32_T z4da0d16710;
volatile uint32_T z2f1801d2e2;
volatile uint32_T dir;
volatile uint32_T z4e420fa837;
volatile uint32_T z6b987bd4a6;
volatile uint32_T zadb9543f03;
volatile uint32_T z3c73e876c3;
volatile uint32_T z7945165dd1;
volatile uint32_T zb51ea233d0;
volatile uint32_T z8a8a7f82dc;
volatile uint32_T z19690b6adb;
volatile uint32_T z73b6066883;
}z3688ef9cb5;static void mdlInitializeSizes(SimStruct*S){uint32_T i;ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x22+300-0x14e));ssSetNumDiscStates(S,(0x377+4133-0x139c));ssSetNumOutputPorts(S,(0x14ec+4430-0x263a));ssSetNumInputPorts(S,(0x118b+5464-0x26e3));ssSetNumSampleTimes(S,(0x100a+1844-0x173d));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x28b+1662-0x909));ssSetNumNonsampledZCs(S,(0x7c0+7008-0x2320));for(i=(0x12a5+5220-0x2709);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x249d+472-0x2675));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){ssSetSampleTime(S,(0x1cb1+553-0x1eda),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0xa7f+4491-0x1c0a),FIXED_IN_MINOR_STEP_OFFSET);}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
xpcPCIDevice zeccbadd9b3;void*z1cf2c50191;void*Virtual;volatile uint8_T*z3283caa368;volatile uint32_T*z2afed1cdc6;volatile z3688ef9cb5*za63558babd;uint_T i;uint8_T z16ba527520[(0x1d84+1210-0x222a)];uint16_T z6f813cde47,za4a2434e08;uint32_T z78caf1ba61,za4eb27db8c;
z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x777+4178-0x17c9)];switch(z78caf1ba61){case(0x1645+3227-0x2195):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x33\x31");z6f813cde47=(0x1b50+4326-0x1561);za4a2434e08=22273;break;default:sprintf(zea4cd01646,"\x62\x6f\x61\x72\x64\x20\x74\x79\x70\x65\x20\x69\x6e\x63\x6f\x72\x72\x65\x63\x74\x2e");ssSetErrorStatus(S,zea4cd01646);return;}if((int_T)mxGetPr(z702a26a5e9)[(0xcf0+165-0xd95)]<(0x1da1+421-0x1f46)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x149f+4353-0x259f)){z366b2f03bf=(0xb4+5398-0x15ca);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0xc86+5423-0x21b5)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0xe0b+5270-0x22a1)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x14e7+1203-0x1999)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x67f+7451-0x229b))|((z366b2f03bf&(0x10e2+1673-0x166c))<<(0xeb1+3402-0x1bf3)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}z1cf2c50191=(void*)zeccbadd9b3.BaseAddress[(0x482+6893-0x1f6d)];Virtual=rl32eGetDevicePtr(z1cf2c50191,2097152,RT_PG_USERREADWRITE);z3283caa368=(volatile uint8_T*)Virtual;z2afed1cdc6=(volatile uint32_T*)Virtual;zeccbadd9b3.VirtAddress[(0x10c8+3283-0x1d99)]=(unsigned long)xpcReserveMemoryRegion((void*)zeccbadd9b3.BaseAddress[(0xbf5+1837-0x1320)],2097152,XPC_RT_PG_USERREADWRITE);ssSetIWorkValue(S,z6a0da049de,zeccbadd9b3.VirtAddress[(0x586+4895-0x18a3)]);za63558babd=(z3688ef9cb5*)(zeccbadd9b3.VirtAddress[(0x588+2263-0xe5d)]+z4945c9b364);if(xpceIsModelInit()){real_T start,z19c4ca5f82;uint32_T z812c65ff2f;printf("\x25\x73\x3a\x20\x70\x72\x65\x70\x61\x72\x65\x20\x46\x50\x47\x41\x20\x66\x6f\x72\x20\x70\x72\x6f\x67\x72\x61\x6d\x6d\x69\x6e\x67" "\n",z16ba527520);z3283caa368[(0x12a8+863-0x1603)]=(0x1240+5239-0x26b6);z3283caa368[(0xebf+1512-0x14a3)]=(0x3d7+8699-0x25cd);start=rl32eGetTicksDouble();while((z3283caa368[(0x6fc+7353-0x23b5)]&(0xc19+2987-0x17c2))==(0xeff+5194-0x2349)){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*3.0){printf("\x25\x73\x3a\x20\x45\x52\x52\x4f\x52\x20\x70\x72\x65\x70\x61\x72\x69\x6e\x67\x20\x46\x50\x47\x41\x20\x66\x61\x69\x6c\x65\x64" "\n",z16ba527520);return;}}printf("\x25\x73\x3a\x20\x73\x74\x61\x72\x74\x20\x70\x72\x6f\x67\x72\x61\x6d\x6d\x69\x6e\x67\x20\x46\x50\x47\x41" "\n",z16ba527520);printf("\x25\x73\x3a\x20\x25\x64\x20\x62\x79\x74\x65\x73\x20\x74\x6f\x20\x64\x6f\x77\x6e\x6c\x6f\x61\x64" "\n",z16ba527520,(uint32_T)((zf81a32dab8)[(0x87b+3741-0x1718)]));for(z812c65ff2f=(0x13fc+3551-0x21d9);z812c65ff2f<(uint32_T)((zf81a32dab8)[(0x5dc+1767-0xcc3)])+(0x8dc+1584-0xf0a);z812c65ff2f++){z3283caa368[(0x673+1396-0xbdf)]=(uint8_T)((zf81a32dab8)[z812c65ff2f]);}start=rl32eGetTicksDouble();while((z3283caa368[(0x8e2+3778-0x17a4)]&(0xf+8004-0x1f52))==(0x7d9+6000-0x1f49)){z19c4ca5f82=rl32eGetTicksDouble();if(z19c4ca5f82-start>1193000.0*3.0)
{printf("\x25\x73\x3a\x20\x45\x52\x52\x4f\x52\x20\x70\x72\x6f\x67\x72\x61\x6d\x6d\x69\x6e\x67\x20\x46\x50\x47\x41\x20\x66\x61\x69\x6c\x65\x64" "\n",z16ba527520);return;}}



z2afed1cdc6[32768/(0x142c+1471-0x19e7)]=2863311530;if(z2afed1cdc6[32768/(0xc3f+3214-0x18c9)]!=~2863311530){sprintf(zea4cd01646,"\x25\x73\x20\x3a\x20\x42\x75\x69\x6c\x74\x2d\x69\x6e\x20\x74\x65\x73\x74\x73\x20\x66\x61\x69\x6c\x65\x64",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}
# if zd4c1aa112f
printf("\x25\x73\x3a\x20\x70\x72\x6f\x67\x72\x61\x6d\x6d\x69\x6e\x67\x20\x46\x50\x47\x41\x20\x63\x6f\x6d\x70\x6c\x65\x74\x65\x64" "\n",z16ba527520);printf("\x30\x78\x25\x58" "\n",z2afed1cdc6[32768/(0x63f+1808-0xd4b)]);printf("\x30\x78\x25\x58" "\n",z2afed1cdc6[32772/(0x9b1+539-0xbc8)]);printf("\x30\x78\x25\x58" "\n",z2afed1cdc6[32776/(0x8c7+5270-0x1d59)]);printf("\x30\x78\x25\x58" "\n",z2afed1cdc6[32780/(0x1df3+440-0x1fa7)]);
# endif        
}else if(!xpceIsModelInit()){

za4eb27db8c=(uint32_T)mxGetPr(z031790c9fa)[(0x841+6126-0x202f)];if(za4eb27db8c==(0x12d5+5027-0x2676)){
# if zd4c1aa112f

printf("\x74\x65\x73\x74\x31\x3a\x20\x30\x78\x25\x58" "\n",za63558babd->z19690b6adb);printf("\x74\x65\x73\x74\x32\x3a\x20\x30\x78\x25\x58" "\n",za63558babd->z73b6066883);za63558babd->z73b6066883=2863311530;printf("\x74\x65\x73\x74\x32\x3a\x20\x30\x78\x25\x58" "\n",za63558babd->z73b6066883);
# endif			
za63558babd->z2f1801d2e2=(0x799+2557-0x1196);za63558babd->z4da0d16710=za7281dd535;za63558babd->zadb9543f03=zc2643045c9;printf("\x43\x6f\x6e\x64\x69\x74\x69\x6f\x6e\x69\x6e\x67\x20\x6d\x6f\x64\x75\x6c\x65\x3a\x20\x49\x4f\x33\x33\x31\x5f\x32\x31" "\n");
za63558babd->z6b987bd4a6=(uint32_T)mxGetPr(z68a97c472d)[(0x913+5640-0x1f1b)];za63558babd->dir=(uint32_T)mxGetPr(DIR)[(0x7bd+5362-0x1caf)];za63558babd->z4e420fa837=(uint32_T)mxGetPr(z7ac839cabf)[(0x4c6+2107-0xd01)];
# if zd4c1aa112f

printf("\x70\x75\x6c\x6c\x3a\x20\x25\x64" "\n",za63558babd->z6b987bd4a6);printf("\x64\x69\x72\x3a\x20\x25\x64" "\n",za63558babd->dir);printf("\x76\x69\x6f\x3a\x20\x25\x64" "\n",za63558babd->z4e420fa837);
# endif

rl32eWaitDouble(ze3709fd80f);za63558babd->z2f1801d2e2=(0x395+7877-0x2259);
# if zd4c1aa112f    
printf("\x75\x70\x64\x61\x74\x65\x3a\x20\x25\x64" "\n",za63558babd->z2f1801d2e2);
# endif    
rl32eWaitDouble(ze3709fd80f);za63558babd->z2f1801d2e2=(0x1c9f+1946-0x2439);
# if zd4c1aa112f    
printf("\x75\x70\x64\x61\x74\x65\x3a\x20\x25\x64" "\n",za63558babd->z2f1801d2e2);
rl32eWaitDouble(ze986289b1a);printf("\x72\x78\x44\x61\x74\x61\x20\x6f\x66\x20\x45\x78\x70\x61\x6e\x64\x65\x72\x31\x3a\x20\x30\x78\x25\x58" "\n",za63558babd->z3c73e876c3);printf("\x72\x78\x44\x61\x74\x61\x20\x6f\x66\x20\x45\x78\x70\x61\x6e\x64\x65\x72\x32\x3a\x20\x30\x78\x25\x58" "\n",za63558babd->z7945165dd1);printf("\x72\x78\x44\x61\x74\x61\x20\x6f\x66\x20\x45\x78\x70\x61\x6e\x64\x65\x72\x33\x3a\x20\x30\x78\x25\x58" "\n",za63558babd->zb51ea233d0);printf("\x72\x78\x44\x61\x74\x61\x20\x6f\x66\x20\x45\x78\x70\x61\x6e\x64\x65\x72\x34\x3a\x20\x30\x78\x25\x58" "\n",za63558babd->z8a8a7f82dc);
# endif      
}}
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

