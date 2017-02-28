#define 	S_FUNCTION_LEVEL 	2
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IOPIL_resistor_s

#include 	<stddef.h>
#include 	<stdlib.h>
#include    <math.h>

#include 	"simstruc.h" 

#ifdef 		MATLAB_MEX_FILE
#include 	"mex.h"
#endif

#ifndef     MATLAB_MEX_FILE
#include    <windows.h>
#include    <string.h>
 
#include    "pilpxi.h"

#include    "xpcimports.h"

#define     HUGE_VAL_XPC    100e6       //HUGE_VAL (open circuit)

#endif

/* Uncomment if debug session */
//#define     SG_DEBUG

/* Input Arguments *******************************************************/
#define NUMBER_OF_ARGS          (8)
#define ID_ARG                  ssGetSFcnParam(S,0)
#define CARDTYPE_ARG            ssGetSFcnParam(S,1)
#define CHANNEL_ARG             ssGetSFcnParam(S,2)
#define INIT_ARG                ssGetSFcnParam(S,3)
#define RESET_ARG               ssGetSFcnParam(S,4)
#define SHOW_OUTPUTPORT_ARG     ssGetSFcnParam(S,5)
#define SLOT_ARG                ssGetSFcnParam(S,6)
#define SAMPLETIME_ARG          ssGetSFcnParam(S,7)


/* Works vectors *********************************************************/
#define NO_I_WORKS              (3)
#define PIL_ID_I_IND            (0)
#define PIL_CARD_TYPE_I_IND     (1)
#define TOTAL_BIN_VALS_I        (2) // total binary values: for 12-bit resolution this is 2^12 = 4096

#define NO_R_WORKS              (0)
#define NO_P_WORKS              (0)


/* Global variables ******************************************************/
char msg[256];                  // String, used for error messages

 
/* Initialize Sizes ******************************************************/
static void mdlInitializeSizes(SimStruct *S)
{
    char msg[256];
    int32_T i;

    ssSetNumSFcnParams(S, NUMBER_OF_ARGS);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S))
    {
        sprintf(msg,
                "Wrong number of input arguments passed.\n%d arguments are expected\n", 
                NUMBER_OF_ARGS);
        
        ssSetErrorStatus(S,msg);
    }

    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);
    
    ssSetNumSampleTimes(S, 1);

    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    for( i = 0 ; i < NUMBER_OF_ARGS ; i++ )
    {
        /* None of the parameters are tunable */
        ssSetSFcnParamTunable(S,i,0);  
    }
  
    
    ssSetNumInputPorts(S, (int)mxGetN(CHANNEL_ARG));
   
    for ( i = 0 ; i < (int)mxGetN(CHANNEL_ARG) ; i++ )
    {
		ssSetInputPortWidth(S, i, 1);
		ssSetInputPortDirectFeedThrough(S, i, 1);
		ssSetInputPortRequiredContiguous(S, i, 1);
	}
   
    if (mxGetPr(SHOW_OUTPUTPORT_ARG)[0])
    {
        ssSetNumOutputPorts(S, (int)mxGetN(CHANNEL_ARG));
       
        for ( i = 0 ; i < (int)mxGetN(CHANNEL_ARG) ; i++ ) 
        {
            ssSetOutputPortWidth(S, i, 1);
        }
    }
    else
        ssSetNumOutputPorts(S, 0);
    
        
    ssSetNumRWork(S, NO_R_WORKS);
    ssSetNumIWork(S, NO_I_WORKS);
    ssSetNumPWork(S, NO_P_WORKS);
    
    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
}

/* Initialize Sample Times ***********************************************/
static void mdlInitializeSampleTimes(SimStruct *S)
{
    if (mxGetPr(SAMPLETIME_ARG)[0]==-1.0)
    {
        ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
        ssSetOffsetTime(S, 0, FIXED_IN_MINOR_STEP_OFFSET);
    }
    else
    {
        ssSetSampleTime(S, 0, mxGetPr(SAMPLETIME_ARG)[0]);
        ssSetOffsetTime(S, 0, 0.0);
    }
}


static void wait_s(real_T t)
{
#ifndef MATLAB_MEX_FILE
    xpcTime t_start, t_now, t_elapsed;
    xpcGetElapsedTime(&t_start);

    do
    {
        xpcGetElapsedTime(&t_now);
        xpcSubtractTime(&t_elapsed, &t_now, &t_start);
    }while( (((real_T)t_elapsed.U64.NanoSecondsLo * 1e-9) + ((real_T)t_elapsed.U64.NanoSecondsHi * 4.294967296)) < t );
#endif
}

/* mdlStart **************************************************************/
#define MDL_START
static void mdlStart(SimStruct *S)
{
#ifndef MATLAB_MEX_FILE

    xpcPCIDevice PciInfo; 
    
    uint32_T VendorID = 0x00;
    uint32_T DeviceID = 0x00;
    uint32_T SubVendorID = 0x00;
    uint32_T SubDeviceID = 0x00;
    char DevName[256];
    
    int Simulink_CardID = (int_T)mxGetPr(ID_ARG)[0];    // Card ID in Simulink
    static int PIL_CardID[100];                              // Card ID for Pickering driver
    
    real_T init_value = 0.0;    // temp variable for initial value(s)
    real_T resistance = 0.0;    // temp variable for resistance
    real_T *ptOutPort;          // variable for output port(s)
    
    int index;
    int channel;

    char card_type[256] ; 
    static int card_type_num = 0;
    
    uint32_T Data = 0;
    uint32_T TotBinVals = 0;
    
    int nChAvailable = 0; // number of channels available on the card, channels used (mxGetN(CHANNEL_ARG)) might be less!
    
    mxGetString(CARDTYPE_ARG, card_type, mxGetN(CARDTYPE_ARG));
    
    strcpy(DevName, "Speedgoat ");
    strcat(DevName, card_type);

    // The comments for mapping Speedgoat IO names to Pickering numbers are 
    // copied from J:\Pricing\IOModules_ItemIDs.docx
    // Only the cards that were already tested sold get the if-block here.
    // SubDeviceID is the same when the first three numbers are the same.
    
    // High density resistor simulation
    //----------------------------------------------------------------------------------------------
    // IO921-8/10    10 x 08-bit, 0 to  255Ω, configurable in steps of 1Ω.    PCI 50-295-021-10/8
    // IO921-8/18    18 x 08-bit, 0 to  255Ω, configurable in steps of 1Ω.    PCI 50-295-121-18/8
    // IO921-12/05   05 x 12-bit, 0 to 4000Ω, configurable in steps of 1Ω.    PCI 50-295-021-5/12
    // IO921-12/10   10 x 12-bit, 0 to 4000Ω, configurable in steps of 1Ω.    PCI 50-295-121-10/12
    if (strcmp(card_type, "IO921-12/10") == 0)                                    
    {                                                                             
        VendorID    = 0x10B5;                                                     
        DeviceID    = 0x9050;                                                     
        SubVendorID = 0x1761;                                                     
        SubDeviceID = 0x101A;                                                     
                                                                                  
        card_type_num = 921;                                                      
        TotBinVals    = 1<<12; // 12-bit resolution card                          
    }                                                                             
    // IO921-16/05   05 x 16-bit, 0 to  65kΩ, configurable in steps of 1Ω.    PCI 50-295-021-5/16
    // IO921-16/10   10 x 16-bit, 0 to  65kΩ, configurable in steps of 1Ω.    PCI 50-295-121-10/16
    else if (strcmp(card_type, "IO921-16/10") == 0)                               
    {                                                                             
        VendorID    = 0x10B5;                                                     
        DeviceID    = 0x9050;                                                     
        SubVendorID = 0x1761;                                                     
        SubDeviceID = 0x101A;                                                     
                                                                                  
        card_type_num = 921;                                                      
        TotBinVals    = 1<<16; // 16-bit resolution card                          
    }                                                                             
    // IO921-24/03   03 x 24-bit, 0 to  16MΩ, configurable in steps of 1Ω.    PCI 50-295-121-3/24
    
    // Potentiometer
    //----------------------------------------------------------------------------------------------
    // IO923-8/5    5 x  8-bit, 0 to  255Ω, configurable in steps of 1Ω.      PCI 50-296-021-5/8
    // IO923-8/9    9 x  8-bit, 0 to  255Ω, configurable in steps of 1Ω.      PCI 50-296-121-9/8
    // IO923-12/2   2 x 12-bit, 0 to 4000Ω, configurable in steps of 1Ω.      PCI 50-296-021-2/12
    // IO923-12/4   4 x 12-bit, 0 to 4000Ω, configurable in steps of 1Ω.      PCI 50-296-121-4/12
    // IO923-16/2   2 x 16-bit, 0 to  65kΩ, configurable in steps of 1Ω.      PCI 50-296-021-2/16
    // IO923-16/4   4 x 16-bit, 0 to  65kΩ, configurable in steps of 1Ω.      PCI 50-296-121-4/16
    // IO923-24/1   1 x 24-bit, 0 to  16MΩ, configurable in steps of 1Ω.      PCI 50-296-021-1/24
    // IO923-24/3   3 x 24-bit, 0 to  16MΩ, configurable in steps of 1Ω.      PCI 50-296-121-3/24
    //     
    
    // High precision resistor simulation
    //----------------------------------------------------------------------------------------------
    // IO925-3-1 3 channels, 3Ω to 1.5MΩ,  configurable in steps of 0.125Ω.   PCI 50-297-103 (should use 50-297-150 in the future)
    // IO925-4-1 4 channels, 2Ω to 13.5kΩ, configurable in steps of 0.25Ω.    PCI 50-297-102 (should use 50-297-131 in the future)
    // IO925-6   6 channels, 3Ω to 1.5MΩ,  configurable in steps of 0.125Ω.   PCI 50-297-003 (should use 50-297-050 in the future)
	else if (strcmp(card_type, "IO925-6") == 0)
    {
        VendorID    = 0x10B5;
        DeviceID    = 0x9030;
        SubVendorID = 0x1761;
        SubDeviceID = 0x1102;
        
        card_type_num = 925;
    }
    // IO925-9   9 channels, 2Ω to 13.5kΩ,   configurable in steps of 1Ω.       PCI 50-297-002 (should use 50-297-031 in the future)
	else if (strcmp(card_type, "IO925-9") == 0)
    {
        VendorID    = 0x10B5;
        DeviceID    = 0x9030;
        SubVendorID = 0x1761;
        SubDeviceID = 0x1101;
        
        card_type_num = 925;
    }
    // IO925-9-1  9 channels, 1Ω to 230Ω,   configurable in steps of 1Ω.       PCI 50-297-101 (should use 50-297-113 in the future)
    // IO925-18  18 channels, 1Ω to 230Ω,   configurable in steps of 1Ω.       PCI 50-297-001 (should use 50-297-013 in the future)
    
    // IO926-6    6 channels, 3Ω to 1.5MΩ,  configurable in steps of 0.125Ω.  cPCI 40-297-003
    // IO926-9    9 channels, 2Ω to 13.5kΩ, configurable in steps of 0.25Ω.   cPCI 40-297-002
    else if (strcmp(card_type, "IO926-9") == 0)
    {
        VendorID    = 0x10B5;
        DeviceID    = 0x9050;
        SubVendorID = 0x1761;
        SubDeviceID = 0x014A;
        
        card_type_num = 926;
    }
    // IO926-18 18 channels, 1Ω to 230Ω,   configurable in steps of 1Ω.      cPCI 40-297-001
    else if (strcmp(card_type, "IO926-18") == 0)
    {
        VendorID    = 0x10B5;
        DeviceID    = 0x9050;
        SubVendorID = 0x1761;
        SubDeviceID = 0x0149;
        
        card_type_num = 926;
    }
    
    // Reed Relays
    //----------------------------------------------------------------------------------------------
    // IO941-SPDT-32     32 x SPDT, Ruthenium Reed Relays                     PCI 50-110-021
    // IO941-SPDT-64     64 x SPDT, Ruthenium Reed Relays                     PCI 50-110-121
    // IO941-SPST-32     32 x SPST, Ruthenium Reed Relays                     PCI 50-115-021
    // IO941-SPST-64     64 x SPST, Ruthenium Reed Relays                     PCI 50-115-121
    // IO941-DPST-25     25 x DPST, Ruthenium Reed Relays                     PCI 50-115-022
    // IO941-DPST-50     50 x DPST, Ruthenium Reed Relays                     PCI 50-115-122
    // IO941-SPDT-S-32   32 x Shielded SPDT Reed Relays                       PCI 50-120-021
    // IO941-SPST-S-32   32 x Shielded SPST Reed Relays                       PCI 50-125-021
    // IO941-SPST-S-50   50 x Shielded SPST Reed Relays                       PCI 50-121-121
    //     
    
    // RTD simulation (resistance temperature detectors)
    //----------------------------------------------------------------------------------------------
    // IO970-PT100-6    PT100  RTD simulation,  6 channels,  90Ω to  250Ω     PCI 50-262-101
        else if (strcmp(card_type, "IO970-PT100-6") == 0)
    {
        VendorID    = 0x10B5;
        DeviceID    = 0x9030;
        SubVendorID = 0x1761;
        SubDeviceID = 0x114C;
        
        card_type_num = 970;
    }

    // IO970-PT100-18   PT100  RTD simulation, 18 channels,  90Ω to  250Ω     PCI 50-262-001
    // IO970-PT1000-6   PT1000 RTD simulation,  6 channels, 900Ω to 2500Ω     PCI 50-262-102
    // IO970-PT1000-18  PT1000 RTD simulation, 18 channels, 900Ω to 2500Ω     PCI 50-262-002
    // IO971-PT100-6    PT100  RTD simulation,  6 channels,  90Ω to  250Ω    cPCI 40-262-101
    else if (strcmp(card_type, "IO971-PT100-6") == 0)
    {
        VendorID    = 0x10B5;
        DeviceID    = 0x9050;
        SubVendorID = 0x1761;
        SubDeviceID = 0x0140;
        
        card_type_num = 971;
    }
    // IO971-PT100-18   PT100  RTD simulation, 18 channels,  90Ω to  250Ω    cPCI 40-262-001
    // IO971-PT1000-6   PT1000 RTD simulation,  6 channels, 900Ω to 2500Ω    cPCI 40-262-102
    // IO971-PT1000-18  PT1000 RTD simulation, 18 channels, 900Ω to 2500Ω    cPCI 40-262-002
    
    // Strain Gauge Simulation
    //----------------------------------------------------------------------------------------------
    // IO972-6-350  6 ch, 350Ω bridge, adjustable Resistor: +/-2%            cPCI 40-265-016
    // IO972-6-2000 6 ch,  2kΩ bridge, adjustable Resistor: +/-5.3%          cPCI 40-265-306
    // IO972-6-3000 6 ch,  3kΩ bridge, adjustable Resistor: +/-5.3%          cPCI 40-265-106
    // IO973-6-350  6 ch, 350Ω bridge, adjustable Resistor: +/-2%             PCI 50-265-016
    // IO973-6-2000 6 ch,  2kΩ bridge, adjustable Resistor: +/-5.3%           PCI 50-265-306
    // IO973-6-3000 6 ch,  3kΩ bridge, adjustable Resistor: +/-5.3%           PCI 50-265-106
    else if (strcmp(card_type, "IO973-6-2000") == 0)
    {
        VendorID    = 0x10B5;
        DeviceID    = 0x9030;
        SubVendorID = 0x1761;
        SubDeviceID = 0x114B;
        nChAvailable = 6;
        card_type_num = 973;
    }
    
    // Check PCI slot
   if ((int_T)mxGetPr(SLOT_ARG)[0]<0) 
   {
       if (xpcGetPCIDeviceInfo(VendorID, 
                               DeviceID, 
                               SubVendorID, 
                               SubDeviceID, 
                               XPC_NO_BUS_SLOT, 
                               XPC_NO_BUS_SLOT, 
                               &PciInfo)) 
       {
           sprintf(msg,"%s: board not present", DevName);
           ssSetErrorStatus(S,msg);
           return;
       }
   } 
   else 
   {
      uint16_T bus, slot;

      if (mxGetN(SLOT_ARG) == 1) 
      {
          bus = 0;
          slot = (uint16_T)mxGetPr(SLOT_ARG)[0];
      } 
      else 
      {
          bus = (uint16_T)mxGetPr(SLOT_ARG)[0];
          slot = (uint16_T)mxGetPr(SLOT_ARG)[1];
      }
      
      if (xpcGetPCIDeviceInfo(VendorID, 
                              DeviceID, 
                              SubVendorID, 
                              SubDeviceID, 
                              bus, 
                              slot, 
                              &PciInfo)) 
      {
          sprintf(msg,"%s (bus %d, slot %d): board not present",DevName, bus, slot );
          ssSetErrorStatus(S,msg);
          return;
      }
    }
    
	PciInfo.VirtAddress[2] = (uint32_T) xpcReserveMemoryRegion((void*)PciInfo.BaseAddress[2],PciInfo.Length[2], XPC_RT_PG_USERREADWRITE);

    // Model initialization
    if (xpcIsModelInit())
    {
        int err;

        err = PIL_OpenSpecifiedCard(PciInfo.bus, PciInfo.slot, &PIL_CardID[Simulink_CardID]);  // cards are address by their bus/device location

        if (err)
        {
            sprintf(msg,"%s : error 0x%x",DevName, err );
            ssSetErrorStatus(S,msg);
            return;
        }
        // printf("**************************************************\n");
        // printf("* %s \n", DevName); 
        // printf("* at bus %i, slot %i \n", PciInfo.bus, PciInfo.slot );
        // printf("* Pickering card opened: OK \n");
        
        printf("%s (bus %i, slot %i) Card Status: ", DevName, PciInfo.bus, PciInfo.slot ); 
        
        err = PIL_Status(PIL_CardID[Simulink_CardID]);
        // printf("* Card Status: 0x%x \n", err);
        
		if(err == STAT_OK)                  {printf("OK \n");}
        else
        {
            if(err & STAT_NO_CARD)          {printf("\nNo card with specified number\n");}
            if(err & STAT_WRONG_DRIVER)     {printf("\nCard requires later driver version\n");}
            if(err & STAT_EEPROM_ERR)       {printf("\nError interpreting card EEPROM data\n");}
            if(err & STAT_DISABLED)         {printf("\nCard is disabled\n");}
            if(err & STAT_NO_SUB)           {printf("\nCard has no sub-unit with specified number\n");}
            if(err & STAT_BUSY)             {printf("\nBusy (card or sub-unit)\n");}
            if(err & STAT_HW_FAULT)         {printf("\nHardware fault (eg. defective serial loop)\n");}
            if(err & STAT_PARITY_ERROR)     {printf("\n9050 Parity Error\n");}
            if(err & STAT_PSU_INHIBITED)    {printf("\nPSU sub-unit - supply is disabled (by software)\n");}
            if(err & STAT_PSU_SHUTDOWN)     {printf("\nPSU sub-unit - supply is shutdown (due to overload)\n");}
            if(err & STAT_PSU_CURRENT_LIMIT){printf("\nPSU sub-unit - supply is operating in current-limited mode\n");}
            if(err & STAT_CORRUPTED)        {printf("\nSub-unit logical state is corrupted\n");}
            if(err & STAT_CARD_INACCESSIBLE){printf("\nCard cannot be accessed (failed/removed/unpowered)\n");}
            if(err & STAT_UNCALIBRATED)     {printf("\nCalibration data is faulty (card or sub-unit)\n");}
            if(err & STAT_CALIBRATION_DUE)  {printf("\nCalibration is due (card or sub-unit)\n");}
            if(err & STAT_BIRST_ENABLED)    {printf("\nBIRST is active (card or sub-unit)\n");}
        }		
        //Channels info
        for ( index = 0 ; index < (int)mxGetN(CHANNEL_ARG) ; index++ )
        {
            double MinRes, MaxRes, RefRes, PrecPC, PrecDelta, Int1, IntDelta;
            uint32_T Capabilities;
            
            channel = (int)mxGetPr(CHANNEL_ARG)[index];
            
            err = PIL_ResInfo(PIL_CardID[Simulink_CardID], channel, &MinRes, &MaxRes, &RefRes, &PrecPC, &PrecDelta, &Int1, &IntDelta, &Capabilities);
            if(err)
			{
				sprintf(msg,"%s : error 0x%x",DevName, err );
				ssSetErrorStatus(S,msg);
				return;
			}
			// if(MaxRes) // from non-precision boards such as IO921 we get all zero values. so we better not printf that.
			// {
				// printf("* Channel %2i - Rmin = %.3f  (ohm)\n", channel, MinRes);
				// printf("*              Rmax = %.3f (ohm) \n", MaxRes);
				// printf("*              Precision: +/- %.3f%% \n", PrecPC);
				// printf("*                         +/- %.3f ohm \n*\n", PrecDelta);
			// }
		}
        
        // printf("* Starting initialization \n");
        
        for ( index = 0 ; index < (int)mxGetN(CHANNEL_ARG) ; index++ )
        {     
            channel = (int)mxGetPr(CHANNEL_ARG)[index];

            init_value = (real_T)mxGetPr(INIT_ARG)[index];
            
            #ifdef SG_DEBUG 
            printf("* Channel %i init_value = %.3f ohm\n", channel, init_value);
            printf("* PIL card = %i \n", PIL_CardID[Simulink_CardID]);
            #endif 
            
            if (init_value >= HUGE_VAL_XPC)    //Open circuit
                init_value = HUGE_VAL;  
            
            switch (card_type_num)
            {
                // 50-295 cards (high density) ['50' == PCI]
                case 921:
                    Data = (int32_T)init_value;//let it just round down
                    if(Data > TotBinVals)
                        Data = TotBinVals; 
                    if(Data == 0)
                        Data = 1; // minimum is 1, not zero

                    if (mxGetPr(SHOW_OUTPUTPORT_ARG)[0])
                    {
                        ptOutPort = ssGetOutputPortSignal(S, index);
                        ptOutPort[index] = (real_T)(Data);
                    }

                    // printf("* Ch %2i: R = %4i Ohm ",channel, Data);
                    
                    
                    /* data needs to be "reversed" because a '1'@p means: "remove resistor 
                    at position 'p' (resistance = 2^p) from the resistor chain 
                    (total resistance = 2^BitResolution = TotBinVals) by closing the 
                    bridge relay." So for the IO921 with 12-bit resolution 0x0110 means 
                    R = 2^12 - 2^4 - 2^8 = 3824 Ohm */
                    Data = TotBinVals - Data; 
                    // printf("(0x%04x)\n", Data);
                    
                    // according to Noman from Pickering we must use PIL_WriteSub for that kind of card (non-precision)
                    err = PIL_WriteSub(PIL_CardID[Simulink_CardID], channel, &Data); 
                    if (err)
                    {
                        sprintf(msg,"%s : error %i (ch. %i)",DevName, err, channel );
                        ssSetErrorStatus(S,msg);
                        return;
                    }
                    break;
                
                // precision cards
                case 925:   
				case 926:   
                case 970:   
                case 971:   
                
                    #if 0
                    // find maximum. result for IO925-9 (50-297-002) is 13500
                    if(index==0)
                    {
                        real_T v = 13.59e3;
                        err=0;
                        while(err==0)
                        {
                            err = PIL_ResSetResistance(PIL_CardID[Simulink_CardID], channel, 0, v);
                            if(err)
                                printf("max is %f (err = %i)\n",v-1,err);
                            else
                            printf(".");
                            v=v+1;
                            wait_s(0.01);
                        }
                    }
                    #endif
                    
                    err = PIL_ResSetResistance(PIL_CardID[Simulink_CardID], channel, 0, init_value);
                    
                    if (err)
                    {
                        sprintf(msg,"%s : error %i (ch. %i)",DevName, err, channel );
                        ssSetErrorStatus(S,msg);
                        return;
                    }

                    // if (init_value >= HUGE_VAL_XPC)    //Open circuit
                        // printf("* Channel %i - Open circuit \n", channel);
                    // else
                        // printf("* Channel %i - Resistance %f \n", channel, init_value);

                    if (mxGetPr(SHOW_OUTPUTPORT_ARG)[0])
                    {
                        ptOutPort = ssGetOutputPortSignal(S, index);
                        PIL_ResGetResistance(PIL_CardID[Simulink_CardID], channel, &resistance);
                        ptOutPort[index] = (real_T)resistance;
                    }
                    
                    break;
                    
                case 972:   
                case 973:   
                
                    // Set the switches: 
                    
                    #if 1 // 1: normal operation, 0: resistance check
                    Data = 14;//0b00001110;
                    err = PIL_WriteSub(PIL_CardID[Simulink_CardID], channel + nChAvailable, &Data); 
                    if (err)
                    {
                        sprintf(msg,"%s : error %i (ch. %i)",DevName, err, channel );
                        ssSetErrorStatus(S,msg);
                        return;
                    }

                    #else
                    printf("Resistance check: ch%i = %f\n",channel,init_value);
                    
                    /* ch  sub-unit  Excite1   Out2
                    ----------------------------------------------------------------------
                        1      7      pin  9  pin  6
                        2      8      pin 18  pin 15
                        3      9      pin 26  pin 23
                        4     10      pin  5  pin  2
                        5     11      pin 14  pin 11
                        6     12      pin 22  pin 20
                    */
                    
                    // For instace on Ch1 we need to operate Bit 2 and Bit 3 on Sub-unit 7 to see the resistance across the programmable resistor between Excite1 (pin 9) and Out2 (pin 6).
                    Data = 6;//0b00000110;
                    err = PIL_WriteSub(PIL_CardID[Simulink_CardID], channel + nChAvailable, &Data); 
                    if (err)
                    {
                        sprintf(msg,"%s : error %i (ch. %i)",DevName, err, channel );
                        ssSetErrorStatus(S,msg);
                        return;
                    }
                    
                    
                        #if 0
                        // find maximum. result for IO925-9 (50-297-002) is 13500
                        if(index==0)
                        {
                            real_T v = 13.59e3;
                            err=0;
                            while(err==0)
                            {
                                err = PIL_ResSetResistance(PIL_CardID[Simulink_CardID], channel, 0, v);
                                if(err)
                                    printf("max is %f (err = %i)\n",v-1,err);
                                else
                                printf(".");
                                v=v+1;
                                wait_s(0.01);
                            }
                        }
                        #endif
                    
                    #endif
                    
                    err = PIL_ResSetResistance(PIL_CardID[Simulink_CardID], channel, 0, init_value);
                    
                    if (err)
                    {
                        sprintf(msg,"%s : error %i (ch. %i)",DevName, err, channel );
                        ssSetErrorStatus(S,msg);
                        return;
                    }

                    // if (init_value >= HUGE_VAL_XPC)    //Open circuit
                        // printf("* Channel %i - Open circuit \n", channel);
                    // else
                        // printf("* Channel %i - Resistance %f \n", channel, init_value);

                    if (mxGetPr(SHOW_OUTPUTPORT_ARG)[0])
                    {
                        ptOutPort = ssGetOutputPortSignal(S, index);
                        PIL_ResGetResistance(PIL_CardID[Simulink_CardID], channel, &resistance);
                        ptOutPort[index] = (real_T)resistance;
                    }
                    
                    break;

                    
            }

        }
        // printf("**************************************************\n\n");
    }

    ssSetIWorkValue(S, PIL_ID_I_IND, PIL_CardID[Simulink_CardID]); 
    ssSetIWorkValue(S, PIL_CARD_TYPE_I_IND, card_type_num);
    ssSetIWorkValue(S, TOTAL_BIN_VALS_I, TotBinVals);

#endif
}




/* mdlOutput *************************************************************/
static void mdlOutputs(SimStruct *S, int_T tid)
{
#ifndef MATLAB_MEX_FILE  
    
    
    real_T resistance = 0.0;   // temp variable for resistance
    real_T *ptOutPort;          // variable for output port(s)
    real_T *ptInPort;
    
    int index;
    int channel;
    int err;
    
    uint32_T Data = 0;

    int Simulink_CardID = 0;
    uint32_T TotBinVals = 0;
    int card_type_num = 0;
    int PIL_CardID[100]; 
    
    Simulink_CardID = (int_T)mxGetPr(ID_ARG)[0];        // Card ID in Simulink
    
    PIL_CardID[Simulink_CardID] = (int)ssGetIWorkValue(S, PIL_ID_I_IND); // Card ID for Pickering driver
    card_type_num  = (int)ssGetIWorkValue(S, PIL_CARD_TYPE_I_IND);
    TotBinVals     = ssGetIWorkValue(S, TOTAL_BIN_VALS_I);

    for ( index = 0 ; index < (int)mxGetN(CHANNEL_ARG) ; index++ )
    {     
        channel = (int)mxGetPr(CHANNEL_ARG)[index];

        ptInPort = (real_T *)ssGetInputPortRealSignal(S,index);
        
        //printf("OUT ch %2i:  ptInPort = 0x%08x\n", channel, ptInPort);
        
        if (!ptInPort)
        {
            sprintf(msg," ptInPort is pNULL (ch %i)", channel);
            ssSetErrorStatus(S,msg);
            return;
        }
        
        if (ptInPort[0] >= HUGE_VAL_XPC)    //Open circuit
                ptInPort[0] = HUGE_VAL;
        
        switch (card_type_num)
        {
			case 921:
                    
                    Data = (int32_T)ptInPort[0]; //let it just round down
                    if(Data > TotBinVals)
                        Data = TotBinVals;
                    if(Data == 0)
                        Data = 1; // minimum is 1, not zero

                    if (mxGetPr(SHOW_OUTPUTPORT_ARG)[0])
                    {
                        ptOutPort = ssGetOutputPortSignal(S, index);
                        ptOutPort[0] = (real_T)(Data);
                    }

                    Data = TotBinVals - Data; // data needs to be "reversed" as it seems
                    
                    err = PIL_WriteSub(PIL_CardID[Simulink_CardID], channel, &Data); 
                    #ifdef SG_DEBUG 
                    if (err) { printf("err = %i \n", err); }
                    #endif 

                    break;

			case 925:
            case 926:
            case 970:
            case 971:
            case 972:
            case 973:
        
                #ifdef SG_DEBUG 
                printf("PIL card = %i \n", PIL_CardID[Simulink_CardID]);
                printf("channel %i ptInPort[0] = %f \n", channel, ptInPort[0]);
                #endif

                err = PIL_ResSetResistance(PIL_CardID[Simulink_CardID], channel, 0, ptInPort[0]); 

                #ifdef SG_DEBUG 
                printf("err = %i \n", err);
                #endif

                if (mxGetPr(SHOW_OUTPUTPORT_ARG)[0])
                {
                    ptOutPort = ssGetOutputPortSignal(S, index);

                    PIL_ResGetResistance(PIL_CardID[Simulink_CardID], channel, &resistance);

                    #ifdef SG_DEBUG 
                    printf("channel %i resistance = %f \n", channel, resistance);
                    #endif

                    ptOutPort[0] = resistance;
                }
                break;
                
        }
    }

#endif
}

/* mdlTerminate **********************************************************/
static void mdlTerminate(SimStruct *S)
{   
#ifndef MATLAB_MEX_FILE

    int reset = 0;   // temp variable for initial value(s)
    real_T reset_value = 0.0;
    real_T resistance = 0.0;   // temp variable for resistance
    real_T *ptOutPort;          // variable for output port(s)
    real_T *ptInPort;
    
    int index;
    int channel;
    uint32_T Data = 0;

    int Simulink_CardID = 0;
    uint32_T TotBinVals = 0;
    int card_type_num = 0;
    int PIL_CardID[100] ; // Card ID for Pickering driver
    
    Simulink_CardID = (int_T)mxGetPr(ID_ARG)[0];        // Card ID in Simulink
    
    PIL_CardID[Simulink_CardID] = (int)ssGetIWorkValue(S, PIL_ID_I_IND); // Card ID for Pickering driver
    card_type_num  = (int)ssGetIWorkValue(S, PIL_CARD_TYPE_I_IND);
    TotBinVals     = ssGetIWorkValue(S, TOTAL_BIN_VALS_I);
    
    if(!xpcIsModelInit())
    {
        for ( index = 0 ; index < (int)mxGetN(CHANNEL_ARG) ; index++ )
        {     
            channel = (int)mxGetPr(CHANNEL_ARG)[index];

            reset = (int)mxGetPr(RESET_ARG)[index];
            
            switch (card_type_num)
            {
				case 921:
                    if (reset == 1)
                    {
                        reset_value = (real_T)mxGetPr(INIT_ARG)[index];
                        
                        Data = (int32_T)reset_value; //let it just round down
                        if(Data > TotBinVals)
                            Data = TotBinVals;
                        if(Data == 0)
                            Data = 1; // minimum is 1, not zero

                        if (mxGetPr(SHOW_OUTPUTPORT_ARG)[0])
                        {
                            ptOutPort = ssGetOutputPortSignal(S, index);
                            ptOutPort[index] = (real_T)(Data);
                        }
                        printf("Channel %2i: R = %4i Ohm\n",channel, Data);
                        Data = TotBinVals - Data; // data needs to be "reversed"
                        PIL_WriteSub(PIL_CardID[Simulink_CardID], channel, &Data); 
                    }
                    break;  
                
				case 925:
                case 926:
                case 970:
                case 971:
                case 972:
                case 973:
            
                    if (reset == 1)
                    {
                        reset_value = (real_T)mxGetPr(INIT_ARG)[index];
                        PIL_ResSetResistance(PIL_CardID[Simulink_CardID], channel, 0, reset_value); 
                    }

                    if (mxGetPr(SHOW_OUTPUTPORT_ARG)[0])
                    {
                        ptOutPort = ssGetOutputPortSignal(S, index);
                        PIL_ResGetResistance(PIL_CardID[Simulink_CardID], channel, &resistance);
                        ptOutPort[0] = (real_T)resistance;
                    }
                    break;  
            }
        }

    }
#endif    
}

#ifdef MATLAB_MEX_FILE  /* Is this file being compiled as a MEX-file? */
#include "simulink.c"   /* Mex glue */
#else
#include "cg_sfun.h"    /* Code generation glue */
#endif


