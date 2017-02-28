#define 	S_FUNCTION_LEVEL 	2
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_IO511_setup_s

#include 	<stddef.h>
#include 	<stdlib.h>

#include 	"simstruc.h" 

#ifdef 		MATLAB_MEX_FILE
#include 	"mex.h"
#endif

#ifndef         MATLAB_MEX_FILE
#include        <windows.h>
#include        "io_xpcimport.h"
//#include        "io511Adr.h"
#include        "pci_xpcimport.h"
#include        "time_xpcimport.h"
#include        "ioext_xpcimport.h"
#include        "util_xpcimport.h"
#endif

/* io511Adr */
#define BOARD_CONTROL_REG (0x0004/4)

/* USC */
#define CCAR_Hi 0x01
#define CCAR_Lo 0x00
#define CMR_Hi 0x03
#define CMR_Lo 0x02
#define CCSR_Hi 0x05
#define CCSR_Lo 0x04
#define CCR_Hi 0x07
#define CCR_Lo 0x06
#define CMCR_Hi 0x11
#define CMCR_Lo 0x10
#define IVR_Hi 0x15
#define IVR_Lo 0x14
#define HCR_Hi 0x13
#define HCR_Lo 0x12
#define IOCR_Hi 0x17
#define IOCR_Lo 0x16
#define ICR_Hi 0x19
#define ICR_Lo 0x18
#define DCCR_Hi 0x1B
#define DCCR_Lo 0x1A
#define MISR_Hi 0x1D
#define MISR_Lo 0x1C
#define SICR_Hi 0x1F
#define SICR_Lo 0x1E
#define RDR 0x20
#define RMR_Hi 0x23
#define RMR_Lo 0x22
#define RCSR_Hi 0x25
#define RCSR_Lo 0x24
#define RICR_Hi 0x27
#define RICR_Lo 0x26
#define RSR_Hi 0x29
#define RSR_Lo 0x28
#define RCLR_Hi 0x2B
#define RCLR_Lo 0x2A
#define RCCR_Hi 0x2D
#define RCCR_Lo 0x2C
#define TC0R_Hi 0x2F
#define TC0R_Lo 0x2E
#define TDR 0x30
#define TMR_Hi 0x33
#define TMR_Lo 0x32
#define TCSR_Hi 0x35
#define TCSR_Lo 0x34
#define TICR_Hi 0x37
#define TICR_Lo 0x36
#define TSR_Hi 0x39
#define TSR_Lo 0x38
#define TCLR_Hi 0x3B
#define TCLR_Lo 0x3A
#define TCCR_Hi 0x3D
#define TCCR_Lo 0x3C
#define TC1R_Hi 0x3F
#define TC1R_Lo 0x3E

/* Input Arguments */
#define NUMBER_OF_ARGS              (5)
#define SLOT_ARG                    ssGetSFcnParam(S,0)
#define CHANNEL_ARG                 ssGetSFcnParam(S,1)
#define MODE_ARG                    ssGetSFcnParam(S,2)
#define FREQ_ARG                    ssGetSFcnParam(S,3)
#define RXALMOST_ARG                ssGetSFcnParam(S,4)
//#define INTIO_ARG                   ssGetSFcnParam(S,5)
    
#define NO_I_WORKS              (2)
#define CHANNELS_I_IND          (0)
#define BASE_ADDR_I_IND         (1)

#define NO_R_WORKS              (16)
#define NO_P_WORKS              (0)

#define POST_DIVIDER_BITS 11 // Number of bits in the post divider
unsigned char	block_1[20];			// Bytes to be written to 08->1B
unsigned char	block_2[24];			// Bytes to be written to 40->57
unsigned char	second_block_1[20];		// Bytes to be written to 08->1B (2nd chip)
unsigned char	second_block_2[24];		// Bytes to be written to 40->57 (2nd chip)
enum {SRC_REF=0, SRC_PLL1, SRC_PLL2, SRC_PLL3, SRC_PLL4, SRC_UNKNOWN};

typedef struct {
  int	Div, P, Q, PO;
  int	Error, Freq, PLL;
  int	PostDivider;
  float pError;
} PLL_PARAMS;

//
// Structure that holds the current usage information for each PLL
//
typedef struct { 
  int		Freq;
  int		Q;
  int		P;
  int		PO;
} PLL_USAGE;

int PD;
// This array hold the current Frequency for the 4 clocks
PLL_PARAMS params[4];

// This array hold the current Frequency for the REF and up to 4 PLLs
PLL_USAGE pllUsage[5];

static char_T msg[256];
void ChannelSetClock(SimStruct *S);
void ProgOscFromFreq(void);

static void mdlInitializeSizes(SimStruct *S)
{
    uint32_T i;

#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif

    ssSetNumSFcnParams(S, NUMBER_OF_ARGS);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S))
    {
        sprintf(msg,"Wrong number of input arguments passed.\n%d arguments are expected\n",NUMBER_OF_ARGS);
        ssSetErrorStatus(S,msg);
        return;
    }

    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);

    ssSetNumOutputPorts(S, 0);
    ssSetNumInputPorts(S, 0);    
   

   
    ssSetNumSampleTimes(S, 1);

    ssSetNumRWork(S, NO_R_WORKS);
    ssSetNumIWork(S, NO_I_WORKS);
    ssSetNumPWork(S, NO_P_WORKS);

    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    for(i = 0 ; i < NUMBER_OF_ARGS ; i++)
    {
        ssSetSFcnParamTunable(S,i,0);  /* None of the parameters are tunable */
    }

    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE | SS_OPTION_PLACE_ASAP);
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, FIXED_IN_MINOR_STEP_OFFSET);
}

#define MDL_START
static void mdlStart(SimStruct *S)
{
#ifndef MATLAB_MEX_FILE
    PCIDeviceInfo pciinfo;
    void *Physical;
    void *Virtual;
    volatile uint32_T *ioaddress32;
    volatile uint8_T *ioaddress8;
    uint32_T chan, nChannels, tmp, tmp2, count;
    uint32_T i, txDataSize, rxDataSize;
    uint8_T LSB, MSB;
    uint32_T value;
    uint16_T vendorid, deviceid, subvendorid, subdeviceid;
    
    vendorid= 0x10B5;
    deviceid= 0x9080;
    subvendorid= 0x10B5;
    subdeviceid= 0x2401;    

    if ((int_T)mxGetPr(SLOT_ARG)[0]<0) {
        if (rl32eGetPCIInfoExt(vendorid, deviceid, subvendorid, subdeviceid, &pciinfo)) {
            sprintf(msg,"[Setup]IO511 board not present");
            ssSetErrorStatus(S,msg);
            return;
        }
    } else {
        uint16_T bus, slot;
        if (mxGetN(SLOT_ARG) == 1) {
            bus = 0;
            slot = (uint16_T)mxGetPr(SLOT_ARG)[0];
        } else {
            bus = (uint16_T)mxGetPr(SLOT_ARG)[0];
            slot = (uint16_T)mxGetPr(SLOT_ARG)[1];
        }
        if (rl32eGetPCIInfoAtSlotExt(vendorid, deviceid, subvendorid, subdeviceid, (slot & 0xff) | ((bus & 0xff)<< 8), &pciinfo)) {
            sprintf(msg,"[Setup]: IO511 board (at bus %d, slot %d) not present", bus, slot );
            ssSetErrorStatus(S,msg);
            return;
        }
    }
    
    Physical = (void *)pciinfo.BaseAddress[2]; 
    Virtual = rl32eGetDevicePtr(Physical, 2097152, RT_PG_USERREADWRITE);
    ioaddress32 =(volatile uint32_T *)Virtual;
    ioaddress8 =(volatile uint8_T *)Virtual;
    ssSetIWorkValue(S, BASE_ADDR_I_IND, (uint32_T)ioaddress32);    
    
    nChannels = (uint32_T)mxGetN(CHANNEL_ARG);
    
    /* Board Reset operation */
    ioaddress32[BOARD_CONTROL_REG] = 0x80000000;
    xpcBusyWait(0.001);
    
    /* Configuration of BCR*/
    ioaddress8[0x100] = 0x00;
    ioaddress8[0x300] = 0x00;  

    /* Clear FIFO and FIFO's set Threshold values*/
    for (i = 0; i < nChannels; i++){
        chan= (uint32_T)mxGetPr(CHANNEL_ARG)[i] - 1; 
        
        /* Clear operations */
        ioaddress32[(0x001C + 0x10*chan)/4] = 0x3;
        xpcBusyWait(0.001);
        //printf("Status: 0x%X\n", ioaddress32[(0x001C + 0x10 * chan) / 4]);
        //printf("TX almost: 0x%X\n", ioaddress32[(0x0010 + 0x10 * chan) / 4]);
        //printf("RX almost: 0x%X\n", ioaddress32[(0x0014 + 0x10 * chan) / 4]);
        /* TX Almost Full-Emtpy */
        ioaddress32[(0x0010 + chan * 0x10) / 4] = 0x0000FFFD;
        
        /* RX Almost Full-Emtpy */
        ioaddress32[(0x0014 + chan * 0x10) / 4] = 0xFFFF0000 - ((uint32_T)mxGetPr(RXALMOST_ARG)[chan] << 16);
        //printf("RX almost Full value: 0x%X\n",  ioaddress32[(0x0014 + chan * 0x10) / 4]);
    }
    
    /* Channel Pin Source */
    for (i = 0; i < nChannels; i++){
        chan= (uint32_T)mxGetPr(CHANNEL_ARG)[i] - 1;  // {1, 2, 3, 4}
        
        
        if ((uint32_T)mxGetPr(MODE_ARG)[chan]){
            if ((int32_T)mxGetPr(FREQ_ARG)[0] == -1){
                ioaddress32[0x0080 / 4 + chan] = 0x90000024;
            }
            else{
                ioaddress32[0x0080 / 4 + chan] = 0x90000020;
            }
        }
        else{
            if ((int32_T)mxGetPr(FREQ_ARG)[0] == -1){
                ioaddress32[0x0080 / 4 + chan] = 0x80000024;
            }
            else{
                ioaddress32[0x0080 / 4 + chan] = 0x80000020;
            }
        }
        //printf("Channel %d Pin Source configured (0x%X)\n", chan + 1, ioaddress32[0x0080 / 4 + chan]);
    }
    
    /* USC configuration.
       USC registers are 16 bits, but can only be accessed through a byte.
       For this reason we use two addresses, the even and the odd.
       Even address can access the Lower byte of the register and odd address
       can access the upper byte of the register.*/    

    /* USC channels are reseted to a default value.*/
    for (i = 0; i < nChannels; i++){
        chan= (uint32_T)mxGetPr(CHANNEL_ARG)[i];  
        ioaddress8[CCAR_Hi + chan * 0x100] = 0x04;
        
        ioaddress8[CCAR_Lo + chan * 0x100] = 0x00;
        ioaddress8[CCAR_Hi + chan * 0x100] = 0x00;
    }
    
    /*
     *
     *
     */
    for (i = 0; i < nChannels; i++){
        chan= (uint32_T)mxGetPr(CHANNEL_ARG)[i];
        
        /* Mode configuration */
        ioaddress8[CMR_Hi + chan * 0x100] = 0x06;
        ioaddress8[CMR_Lo + chan * 0x100] = 0x06; 
        
        /* Clock configuration */ 
        ioaddress8[CMCR_Hi + chan * 0x100] = 0x00;
        ioaddress8[CMCR_Lo + chan * 0x100] = 0x11; 
        
        /* Hardware control register */
        ioaddress8[HCR_Hi + chan * 0x100] = 0x00;
        ioaddress8[HCR_Lo + chan * 0x100] = 0x44;
        
        /* I/O Control register */
        ioaddress8[IOCR_Hi + chan * 0x100] = 0x05;
        ioaddress8[IOCR_Lo + chan * 0x100] = 0x00;

        /* Transfers are disabled, they will be enabled once the FIFO has been
           written. */
        
        /* Receive mode register */
        ioaddress8[RMR_Hi + chan * 0x100] = 0x00; 
        ioaddress8[RMR_Lo + chan * 0x100] = 0x00;   
        
        /* Transmit mode register */
        ioaddress8[TMR_Hi + chan * 0x100] = 0x00; 
        ioaddress8[TMR_Lo + chan * 0x100] = 0x00; 
    }    
    
    
    /* DMA threshold between Internal and External TX FIFO are configured.
       If 31 characters are empty in the internal TX FIFO, it will request
       data from the External TX FIFO. */
    for (i = 0; i < nChannels; i++){
       chan= (uint32_T)mxGetPr(CHANNEL_ARG)[i];  
       ioaddress8[TCSR_Hi + chan * 0x100] = 0x70;
       ioaddress8[TICR_Hi + chan * 0x100] = 0x1F;
    } 
    
    /* DMA threshold between Internal and External RX FIFO are configured.
       If more than 16 characters are present in the internal RX FIFO, the
       data will be written to the External TX FIFO.      
       In the release version this value will be set to zero. */
    for (i = 0; i < nChannels; i++){
       chan= (uint32_T)mxGetPr(CHANNEL_ARG)[i];  
       ioaddress8[RCSR_Hi + chan * 0x100] = 0x70;
       ioaddress8[RICR_Hi + chan * 0x100] = 0x00;
    }      
    
    /* TX and RX are enabled. */
    for (i = 0; i < nChannels; i++){
        chan= (uint32_T)mxGetPr(CHANNEL_ARG)[i]; 
        
        ioaddress8[RMR_Hi + chan * 0x100] = 0x00; 
        ioaddress8[RMR_Lo + chan * 0x100] = 0x02;   
        
        ioaddress8[TMR_Hi + chan * 0x100] = 0x00; 
        ioaddress8[TMR_Lo + chan * 0x100] = 0x02; 
    }    
    
    
    tmp = 0x00004444; // RX Fifo full interrupts are always enabled.
    
    /* USC interrupts are enabled if required. */
//     for (i = 0; i < nChannels; i++){
//         chan= (uint32_T)mxGetPr(CHANNEL_ARG)[i] - 1; 
//         
//         if ((uint32_T)mxGetPr(INTIO_ARG)[chan]){
//             MSB = ioaddress8[ICR_Hi + (chan + 1)*0x100];
//             LSB = ioaddress8[ICR_Lo + (chan + 1)*0x100];
//             ioaddress8[ICR_Hi + (chan + 1)*0x100] = (MSB | 0x80);
//             ioaddress8[ICR_Lo + (chan + 1)*0x100] = (LSB | 0x02);
//             
//             
//             LSB = ioaddress8[SICR_Lo + (chan + 1)*0x100];
//             ioaddress8[SICR_Lo + (chan + 1)*0x100] = (LSB | 0x10);
//             
//             ioaddress32[0x90 / 4 + chan] = 0x4;
//         }
//         tmp |= (((uint32_T)mxGetPr(INTIO_ARG)[chan] * 0x8) << (0x4 * chan));
//     }
    
    
    if ((int32_T)mxGetPr(FREQ_ARG)[0] >= 0){
        ChannelSetClock(S);
        /* Oscillator configuration.*/
        ioaddress32[0x00A8 / 4] = PD;
        xpcBusyWait(0.001);
        for (i = 0; i < 18; i++){
            
            /* address */
            ioaddress32[0x00A0 / 4] = i + 8;
            
            /* First data block */
            ioaddress32[0x00A4 / 4] = block_1[i];
            //printf("Block_1[%d] : %d //", i, block_1[i]);
            
            /* Second data block */
            ioaddress32[0x00AC / 4] = second_block_1[i];
            //printf("Second_block_1[%d] : %d\n", i, second_block_1[i]);

        }
        
        for (i = 0; i < 24; i++){
            /* address */
            ioaddress32[0x00A0 / 4] = i + 0x40;

            /* First data block */
            ioaddress32[0x00A4 / 4] = block_2[i];

            /* Second data block */
            ioaddress32[0x00AC / 4] = second_block_2[i];

            
        }
        do{
            xpcBusyWait(0.001);
            value = ioaddress32[0x00A8 / 4];
        }
        while ((value & 0x1) == 0);
        ioaddress32[0x00A8 / 4] = 0x0001;

        
    }
    
    ioaddress32[0x0060 / 4] = tmp;
    //printf("Interrupt configured: 0x%X\n", ioaddress32[0x0060 / 4]);
    printf("IO511 Configured.\n");
#endif
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
#ifndef MATLAB_MEX_FILE            
#endif
}

static void mdlTerminate(SimStruct *S)
{   
#ifndef MATLAB_MEX_FILE  
#endif
}


/* This routine is used to calculate the compensation
   value for a given set of P and PO values. */  
unsigned char getLfValue(int P, int PO){
#ifndef MATLAB_MEX_FILE  
    int pt = 2*P+6+PO;
    
    if (pt < 232) return 0x00;
    if (pt < 627) return 0x08;
    if (pt < 835) return 0x10;
    if (pt <1044) return 0x18;
    return 0x20;
#endif
}

void FillInPLL1(PLL_PARAMS info){
#ifndef MATLAB_MEX_FILE      
    int i;

    // Fill in first block
    block_2[0] = info.Q;
    block_2[1] = info.P & 0x00ff;
    block_2[2] = 0x40 | (info.PO<<2) | (info.P>>8) | getLfValue(info.P, info.PO);

    // Copy first block to other 7
    for (i = 1; i < 8; i++){
        block_2[3*i] = block_2[0];
        block_2[3*i+1] = block_2[1];
        block_2[3*i+2] = block_2[2];
    }
    //printf("Test FillInPLL1\n");
#endif
}

void FillInPLL2(PLL_PARAMS info){
#ifndef MATLAB_MEX_FILE  
    // Fill in block   
    block_1[9] = info.Q;
    block_1[10] = info.P & 0x00ff;
    block_1[11] = 0x40 | (info.PO<<2) | (info.P>>8) | getLfValue(info.P, info.PO);
    //printf("Test FillInPLL2\n");
#endif
}

void FillInPLL3(PLL_PARAMS info){
#ifndef MATLAB_MEX_FILE  
    // Fill in block
    block_1[12] = info.Q;
    block_1[13] = info.P & 0x00ff;
    block_1[14] = 0x40 | (info.PO<<2) | (info.P>>8) | getLfValue(info.P, info.PO);
    //printf("Test FillInPLL3\n");
#endif
}

void FillInPLL4(PLL_PARAMS info){
#ifndef MATLAB_MEX_FILE    
     // Fill in block
    second_block_1[12] = info.Q;
    second_block_1[13] = info.P & 0x00ff;
    second_block_1[14] = 0x40 | (info.PO<<2) | (info.P>>8) | getLfValue(info.P, info.PO);
    //printf("Test FillInPLL4\n");
#endif
}

/*  This routine determines the optimum values for the PLL
 paramters given the desired frequency.*/
void DetermineParameters(int iChan){
#ifndef MATLAB_MEX_FILE   
    int Div;
    int Q, PO;
    float volatile firstStep, secondStep, pFloat, pError;
    int desiredFreq = params[iChan].Freq;
    int diff;
    int minDiv,maxDiv;
    int minTotalDiv,maxTotalDiv;
    int refDiv;
    int postDiv;
    int i;
    int loopDone = 0x00;
    int currentPostDivider, currentPD;

    // Initialize results, assume reference driver
    params[iChan].Div = 0;
    params[iChan].Q = 0;
    params[iChan].P = 0;
    params[iChan].PO = 0;
    params[iChan].Error = 100;
    params[iChan].PLL = SRC_REF;
    params[iChan].PostDivider = 0;
    params[iChan].pError = 1;

    // Do nothing for 0 freq.
    if (desiredFreq == 0) return;

    // Check to see if a previous PLL setting can be used
    for (i=0;i<5;i++){
        if (desiredFreq <= pllUsage[i].Freq){
            // Get a possible divider
            refDiv = pllUsage[i].Freq / desiredFreq;
            diff = abs((refDiv * desiredFreq) - pllUsage[i].Freq);
            if (diff <= (pllUsage[i].Freq/10000)) {
                // See if we need a post divider
                postDiv = 0;	
                while (refDiv > 127){
                    if ((refDiv % 2) != 0) break;
                    refDiv /=2;
                    postDiv++;
                }

                if ((refDiv < 128) && (postDiv <= POST_DIVIDER_BITS)){
                    params[iChan].Error = diff;
                    params[iChan].pError = 0;
                    params[iChan].Div = refDiv;
                    params[iChan].Q = pllUsage[i].Q;
                    params[iChan].P = pllUsage[i].P;
                    params[iChan].PO = pllUsage[i].PO;
                    params[iChan].PLL = i;
                    params[iChan].PostDivider = postDiv;
                    return;
                }
            }
        }
    }

    // Since we are not using the reference, change to unknown
    params[iChan].PLL = SRC_UNKNOWN;

    // The maximum and minimum PLL frequencies are 400MHz and 100MHz, so the range of
    // dividers can be determined.
    maxTotalDiv = (400000000 / desiredFreq) + 1;
    minTotalDiv = maxTotalDiv/4;

    // Calculate the first step of the equation
    firstStep = (float)desiredFreq/(float)(2*20000000);

    // Loop through all of the possible dividers
    currentPostDivider = 0;
    do{
        currentPD = (int)pow(2,currentPostDivider);
        minDiv = minTotalDiv/currentPD;
        if (minDiv>127) 
            currentPostDivider++;
        if (currentPostDivider >= POST_DIVIDER_BITS)
            break;
    } while (minDiv > 127);

    while (loopDone == 0x00){
        currentPD = (int)pow(2,currentPostDivider);
        minDiv = minTotalDiv/currentPD;
        if ((minDiv * currentPD * desiredFreq) < 100000000) 
            minDiv++;
        if (minDiv < 1) 
            minDiv = 1;
        maxDiv = maxTotalDiv/currentPD;
        if ((maxDiv * currentPD * desiredFreq) > 400000000)
            maxDiv--;
        if (maxDiv > 127)
            maxDiv = 127;
 
        // Loop through all of the divisors
        for (Div=minDiv;Div<=maxDiv;Div++){
            secondStep = firstStep * (float)(Div * currentPD);
      
            for (Q=0;Q<256;Q++){
                for (PO=0;PO<2;PO++){
                    // Calculate the P value and its error
                    pFloat = secondStep * (float)(Q+2) - (float)(PO/2) - (float)3.0;
                    pError = pFloat - (int)pFloat;

                    // If this is a new minimum error, save the info
                    if (pError < params[iChan].pError){
                        params[iChan].PostDivider = currentPostDivider;
                        params[iChan].Div = Div;
                        params[iChan].Q = Q;
                        params[iChan].P = (int)pFloat;
                        params[iChan].PO = PO;
                        params[iChan].pError = pError;

                        // If the error is 0, we are done
                        if (pError <= 0.0001) 
                            return;
                    }
                }
            }
        }
        if (minDiv == maxDiv) 
            loopDone = 0xff;
        else 
            currentPostDivider++; 
        if (currentPostDivider > POST_DIVIDER_BITS) 
            loopDone = 0xff;
    }
#endif
}


//-------------------------------------------------- ProgramOscillatorFromFreq
void ProgOscFromFreq()
{
#ifndef MATLAB_MEX_FILE   

    int iChan,pll=SRC_PLL1;
    int postDivider;

    // Initialize the PLL frequency array
    pllUsage[0].Freq = 20000000;	// Reference
    pllUsage[1].Freq = 0;				// PLL 1
    pllUsage[2].Freq = 0;				// PLL 2
    pllUsage[3].Freq = 0;				// PLL 3
    pllUsage[4].Freq = 0;				// PLL 4

    // Get the parameters and determine the PLL arangement
    for (iChan = 0;iChan < 4; iChan++){
        // Get the PLL setup for this channel
        DetermineParameters(iChan);

        // If a previous PLL was not used
        if (params[iChan].PLL == SRC_UNKNOWN){
            if (pll < 5){
                pllUsage[pll].Freq = params[iChan].Div*params[iChan].Freq*(int)pow(2,params[iChan].PostDivider);
                pllUsage[pll].Q = params[iChan].Q;
                pllUsage[pll].P = params[iChan].P;
                pllUsage[pll].PO = params[iChan].PO;
                params[iChan].PLL = pll++;
                //printf("PLL: %d\n", params[iChan].PLL);
            }
            else{
                
                params[iChan].Div = 1;
                params[iChan].PLL = 0;
            }
        }
    }
			
    // Fill the block arrays
    memset(block_1, 0, sizeof(block_1));
    memset(block_2, 0, sizeof(block_2));

    block_1[0] = params[0].Div;		// 8
    block_1[1] = block_1[0];		// 9
    block_1[2] = params[1].Div;		// a
    block_1[3] = block_1[2];		// b
    block_1[4] = params[2].Div;		// c
    block_1[5] = params[3].Div;		// d
    block_1[7] = 0x50;              // f
    block_1[8] = 0x55;              // 10
    //	block_1[18] = 0xea;				// 1a
    //	block_1[19] = 0x08;				// 1b

    // Fill in the proper PLL info for each clockout 
    for (iChan = 0; iChan < 4; iChan++){
        // Make room for next bits
        block_1[6] >>= 2;

        switch (params[iChan].PLL){
            case SRC_PLL1: FillInPLL1(params[iChan]); block_1[6] |= 0x40; break;
            case SRC_PLL2: FillInPLL2(params[iChan]); block_1[6] |= 0x80; break;
            case SRC_PLL3: FillInPLL3(params[iChan]); block_1[6] |= 0xc0; break;
        }
    }

    // Copy the first chip data into the second
    memcpy(second_block_1, block_1, sizeof(block_1));
    memcpy(second_block_2, block_2, sizeof(block_2));

    // See if PLL 4 was used for channel 4
    if (params[3].PLL == SRC_PLL4){
        FillInPLL4(params[3]);
        second_block_1[6] |= 0xc0;
    }

    // Generate the post Divider info
    postDivider = ((params[3].PostDivider & 0x0f) << 20) + ((params[2].PostDivider & 0x0f) << 16) + ((params[1].PostDivider & 0x0f) << 12) + ((params[0].PostDivider & 0x0f) <<  8) + 0x80;

    PD = postDivider;
    //xpcBusyWait(0.001);
//     for (iChan = 0; iChan < 4; iChan++){
//         printf("Ch %d: Freq = %d, PLL = %d, PLLFreq = %d, P = %d, Q = %d, PO = %d, Div = %d, PostDiv = %d, Error = %6.4f\n",
//                 iChan+1,
//                 params[iChan].Freq,
//                 params[iChan].PLL,
//                 params[iChan].P,
//                 params[iChan].Q,
//                 params[iChan].PO,
//                 params[iChan].Div,
//                 params[iChan].PostDivider,
//                 params[iChan].pError);
//     }
#endif
}

void ChannelSetClock(SimStruct *S){
#ifndef MATLAB_MEX_FILE  
    int i;
    //int freq[4] = {8000000, 8000000, 8000000, 8000000};       

    for (i = 0; i < 4; i++){        
        params[i].Freq = (int32_T)mxGetPr(FREQ_ARG)[i];        
        printf("Channel %d: %d[Hz]\n", i + 1, params[i].Freq);
    }
    
	ProgOscFromFreq();
#endif
}

#ifdef MATLAB_MEX_FILE  /* Is this file being compiled as a MEX-file? */
#include "simulink.c"   /* Mex glue */
#else
#include "cg_sfun.h"    /* Code generation glue */
#endif


