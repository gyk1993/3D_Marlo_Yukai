


#define         S_FUNCTION_LEVEL        2
#undef          S_FUNCTION_NAME
#define         S_FUNCTION_NAME         setup_tews_XR17D15x

#include        <stddef.h>
#include        <stdlib.h>

#include        "simstruc.h"

#ifdef          MATLAB_MEX_FILE
#include        "mex.h"
#endif

#ifndef         MATLAB_MEX_FILE
#include        <windows.h>
#include        "xpctarget.h"
#include        "sg_serialdefines.h"
#endif

/* Input Arguments */
#define NUMBER_OF_ARGS          (19)
#define SLOT_ARG                ssGetSFcnParam(S,0)
#define TYPE_ARG                ssGetSFcnParam(S,1)
#define PORT_ARG                ssGetSFcnParam(S,2)
#define STANDARD_ARG            ssGetSFcnParam(S,3)
#define STANDARDRATE_ARG        ssGetSFcnParam(S,4)
#define CUSTOMDIVISOR_ARG       ssGetSFcnParam(S,5)
#define MODE8X_ARG              ssGetSFcnParam(S,6)
#define PRESCALE_ARG            ssGetSFcnParam(S,7)
#define WIDTH_ARG               ssGetSFcnParam(S,8)
#define NSTOP_ARG               ssGetSFcnParam(S,9)
#define PARITY_ARG              ssGetSFcnParam(S,10)
#define RLEVEL_ARG              ssGetSFcnParam(S,11)
#define CTSMODE_ARG             ssGetSFcnParam(S,12)
#define XONOFF_ARG              ssGetSFcnParam(S,13)
#define XONCHAR_ARG             ssGetSFcnParam(S,14)
#define XOFFCHAR_ARG            ssGetSFcnParam(S,15)
#define RS485_ARG               ssGetSFcnParam(S,16)
#define RS485DLY_ARG            ssGetSFcnParam(S,17)
#define TRANSCEIVER_ARG         ssGetSFcnParam(S,18)

#define SAMP_TIME_IND           (0)
#define BASE_ADDR_IND           (0)

#define NO_I_WORKS              (3)
#define PORTBASE_I_IND          (0)
#define CONFIG_I_IND            (1)
#define FIRST_I_IND             (2)

#define NO_R_WORKS              (0)

static char_T msg[256];

#define FCRT_EN_FIFOTRG     0x30  // Enable receive fifo depth
#define FCRT_EN_SELRT       0x80
#define EFR_AUTO_CTS        0x80
#define EFR_AUTO_RTS        0x40

#ifndef         MATLAB_MEX_FILE

static uint16_T tews_divisors[] =
{
        0x0001,   // 2764800    1
        0x0002,   // 1382400    2
        0x0003,   // 921600     3
        0x0006,   // 460800     4
        0x000c,   // 230400     5
        0x0018,   // 115200     6
        0x0030,   // 57600      7
        0x0048,   // 38400      8
        0x0090,   // 19200      9
        0x0120,   // 9600       10
        0x0240,   // 4800       11
        0x0480,   // 2400       12
        0x0900,   // 1200       13
        0x1200,   // 600        14
        0x1b00,   // 400        15        
};

static uint8_T read_CPLD_TEWS(struct uartconfig *config, uint8_T address)
{             
    uint8_T value, i;
    
    value=0;
    
    
    config->mpiosel= 0x80;
    
    config->mpiolvl= 0x03 | (address << 3);
    config->mpiolvl= 0x07 | (address << 3);
    config->mpiolvl= 0x03;
    value|= ((config->mpiolvl >> 7) & 0x01) << 6;
    
    for (i=0; i<6; i++) {
        config->mpiolvl= 0x07;
        config->mpiolvl= 0x03;
        value|= ((config->mpiolvl >> 7) & 0x01) << (5-i);
    }
    
    config->mpiolvl= 0x00;

    return value;
    
}

static void write_CPLD_TEWS(struct uartconfig *config, uint8_T address, uint8_T data )
{             
    uint8_T value, i;
    
    value=0;
   
    config->mpiosel= 0x80;
       
    config->mpiolvl= 0x01 | (address << 3) | (((data >> 6) & 0x01) << 6);
    config->mpiolvl= 0x05 | (address << 3) | (((data >> 6) & 0x01) << 6);
    
    for (i=0; i<6; i++) {
        config->mpiolvl= 0x01 | (((data >> (5-i)) & 0x01) << 6);
        config->mpiolvl= 0x05 | (((data >> (5-i)) & 0x01) << 6);
    }
    
    config->mpiolvl= 0x00;
    
}

#endif

static void mdlInitializeSizes(SimStruct *S)
{
    int32_T i;

    ssSetNumSFcnParams(S, NUMBER_OF_ARGS);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
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
    ssSetNumPWork(S, 0);

    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    for( i = 0 ; i < NUMBER_OF_ARGS ; i++ )
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

    struct uartregs   *regs;
    struct uartconfig *config;
    xpcPCIDevice   pDev;
    int32_T     vendorId, deviceId;
    char_T      *devName;
    int32_T     boardtype = (int)mxGetPr(TYPE_ARG)[0];
    int32_T     pciSlot;
    int32_T     pciBus;
    int32_T     port;
    int32_T     standard = (int)mxGetPr(STANDARD_ARG)[0];
    int32_T     bauddiv;
    int32_T     paritytemp;
    int32_T     lcrtemp;
    int32_T     fctrtemp;
    int32_T     rs485mode = (int)mxGetPr(RS485_ARG)[0];
    int32_T     rs485delay = (int)mxGetPr(RS485DLY_ARG)[0];
    int32_T     mode8x = (int)mxGetPr(MODE8X_ARG)[0];
    int32_T     rlevtemp;
    int32_T     efrtemp;
    int32_T     ctsmode = (int)mxGetPr(CTSMODE_ARG)[0];
    int32_T     xonoff = (int)mxGetPr(XONOFF_ARG)[0];
    int32_T     mcrtemp;
    uint8_T     transceiver, transceiverarg;
    
    //printf("mdlStart for port %d\n", port);

    switch( boardtype )
    {
        // board types 1-8 are used by Quatech, Diamond, etc.
        // Don't reuse types for different serial boards to ease confusion.
      case 102:
        vendorId = 0x1498;
        deviceId = 0x01D2;
        devName = "TEWS TPMC466";
        break;
      case 103:
        vendorId = 0x1498;
        deviceId = 0x01D1;
        devName = "TEWS TPMC465";
        break;
      default:
        sprintf( msg, "setup_tews_XR17D15x driver: Unknown board type, %d", boardtype );
        ssSetErrorStatus( S, msg );
        return;
    }

    if( mxGetN(SLOT_ARG) == 1 )
    {
        pciBus = 0;
        pciSlot = (int32_T) mxGetPr(SLOT_ARG)[0];
    } else
    {
        pciBus = (int32_T) mxGetPr(SLOT_ARG)[0];
        pciSlot = (int32_T) mxGetPr(SLOT_ARG)[1];
    }

    if( xpcGetPCIDeviceInfo( vendorId,
                             deviceId,
                             -1,
                             -1,
                             pciBus,
                             pciSlot,
                             &pDev ) )
    {
        sprintf(msg, "No %s at bus %d slot %d", devName, pciBus, pciSlot);
        ssSetErrorStatus(S, msg);
        return;
    }

    
    pDev.VirtAddress[0]
        = (int32_T)xpcReserveMemoryRegion( (void *)(pDev.BaseAddress[0]),
                                           pDev.Length[0],
                                           XPC_RT_PG_USERREADWRITE);

    // show Device Information
    // xpcShowPCIDeviceInfo( &pDev );

    port = (int32_T)mxGetPr(PORT_ARG)[0] - 1;
    regs = (struct uartregs *)((int32_T)pDev.VirtAddress[0] + port * UARTCHANOFFSET);
    config = (struct uartconfig *)((int32_T)pDev.VirtAddress[0] + UARTCONFIGOFFSET);

    // Save the UART address for mdlterminate
    ssSetIWorkValue(S, PORTBASE_I_IND, (int32_T)regs );
    ssSetIWorkValue(S, CONFIG_I_IND, (int32_T)config );
    
    transceiverarg= (int32_T)(mxGetPr(TRANSCEIVER_ARG)[0]);

    if( standard == 1)
        bauddiv = (int32_T)tews_divisors[ (int32_T)(mxGetPr(STANDARDRATE_ARG)[0] - 1) ];
    else
        bauddiv = (int32_T)(mxGetPr(CUSTOMDIVISOR_ARG)[0]);

    // Set the DLAB bit so we can get to the baud rate divisor
    // and the options register
    lcrtemp = regs->lcr;
    regs->lcr = lcrtemp | LCRDLAB;

    regs->dll = bauddiv & 0xff;
    regs->dlm = (bauddiv >> 8) & 0xff;

    // Clear the DLAB bit
    regs->lcr = lcrtemp;

    if( standard == 0 && mode8x == 1 )
    {
        config->mode8x = config->mode8x | (1 << port);
    }
    else
    {
        config->mode8x = config->mode8x & ~(1 << port);
    }

    // Enable the enhanced functions in the EFR register
    efrtemp = EFRENABLE;
    if( ctsmode == 1 )
        efrtemp |= EFRHWFLOW;
    if( xonoff == 1 )
        efrtemp |= EFRRXFLOW | EFRTXFLOW;
    regs->efr = efrtemp;    

    // Construct the contents of the LCR register.
    lcrtemp = 0;

    switch( (int32_T)(mxGetPr(WIDTH_ARG)[0]) )
    {
      case 1:
        lcrtemp = LCR5BIT;
        break;
      case 2:
        lcrtemp = LCR6BIT;
        break;
      case 3:
        lcrtemp = LCR7BIT;
        break;
      case 4:
        lcrtemp = LCR8BIT;
        break;
    }

    if( (int32_T)(mxGetPr(NSTOP_ARG)[0]) == 2 )  // If 2 stop bits are chosen,
        lcrtemp |= LCRSTOP;

    // Parity selection involves 3 bits in the LCR
    paritytemp = 0;
    switch( (int32_T)(mxGetPr(PARITY_ARG)[0] ) )
    {
      case 1:   // no parity
        paritytemp = 0;
        break;
      case 2:   // even parity
        paritytemp = LCRPARITY | LCREVEN;
        break;
      case 3:   // odd parity
        paritytemp = LCRPARITY;
        break;
      case 4:   // mark parity
        paritytemp = LCRPARITY | LCRSTICK;
        break;
      case 5:   // space parity
        paritytemp = LCRPARITY | LCREVEN | LCRSTICK;
        break;
    }
    lcrtemp |= paritytemp;

    regs->lcr = lcrtemp;
    //printf("final lcr = 0x%x\n", regs->lcr );

    // Set up FCTR, 485 Hysterisis, 485 auto mode, trigger table
    fctrtemp = FCTRTRIG;  // Programmed levels, RX and TX, FCR bits ignored
    if( rs485mode == 1 )
    {
        fctrtemp |= FCTRAUTO485;  // Enable auto turnaround signaling
        regs->msr = (rs485delay & 0xf) << 4;  // turn around delay
    }

    // Still need to consider the hysterisis value
    regs->fctr = fctrtemp;

    // Set up the FIFO trigger levels.
    // Let the transmitter trigger be 'empty'.
    // The receiver trigger is given by RLEVEL_ARG

    // Set the FCR with fifo properties
    rlevtemp = 1;
    switch( (int32_T)(mxGetPr(RLEVEL_ARG)[0] ) )
    {
      case 1:  // interrupt at 1 byte
        rlevtemp = 1;
        break;
      case 2:  // interrupt at quarter full (16)
        rlevtemp = 16;
        break;
      case 3:  // interrupt at half full   (32)
        rlevtemp = 32;
        break;
      case 4:  // interrupt at almost full (56)
        rlevtemp = 56;
        break;
    }
    regs->txfifolevel = 1;
    regs->rxfifolevel = rlevtemp;
 
    regs->fcr = FCREBL  | FCRRCLR | FCRTCLR;

    mcrtemp = 0;
    // The following disabled since the wiring doesn't bring out
    // the DTR or DSR lines even though they can be used in the UART.
    //if( ctsmode == 2 )
    //{
    //    mcrtemp |= MCRDTRFLOW;  // Use DTR/DSR instead of CTS/RTS
    //}
    //if (port<5) {
    //printf("%d\n", transceiverarg);
    if (transceiverarg==1 || transceiverarg==4 || transceiverarg==5 ) {
      mcrtemp|= MCRRTS;
    }
    mcrtemp|= MCRDTR;
    //}
    if( standard == 0 && mxGetPr( PRESCALE_ARG )[0] == 1 )
    {
        mcrtemp |= MCRPRE;      // Divide reference by 4
    }
    // Defaults to DTR, RTS, OUT1, OUT2 all high, bits = 1 sets outputs high

// TEST
    //mcrtemp |= 0x10;  // loopback mode
    //printf("mcr = 0x%x\n", mcrtemp );
// TEST

    regs->mcr = mcrtemp;
    

// TEWS specific channel setup
    
    //printf("CPLD setup for port %d\n", port);
    
    switch( transceiverarg )
    {
      case 1:  // RS232
        transceiver = 0x00;
        break;
      case 2:  // RS422 
        transceiver = 0x09;
        break;
      case 3:  // RS422 multidrop
        transceiver = 0x01;
        break;
      case 4:  // RS485 full duplex
        transceiver = 0x19;
        break;
      case 5:  // RS485 half duplex
        transceiver = 0x7;
        break;
    }
    
    write_CPLD_TEWS(config, port, transceiver);
    
    //printf("Port: %d, Transceiver: 0x%x\n", port, transceiver);
    
    // Enable receive interrupts.
    //regs->ier = IERRCV;

    // Transmit interrupt isn't enabled yet, but is delayed until there
    // are characters available to be sent.
    
    //printf("mdlStart for port %d finished\n", port);
    
    
    // clear power modes,
    // but wait for mdlOutputs to Enable receive interrupts  
    regs->ier = 0;
    ssSetIWorkValue( S, FIRST_I_IND, 1 );

    // Transmit interrupt isn't enabled yet, but is delayed until there
    // are characters available to be sent.

#endif

}

static void mdlOutputs(SimStruct *S, int_T tid)
{

#ifndef MATLAB_MEX_FILE
    struct uartregs *regs = (struct uartregs *)ssGetIWorkValue(S, PORTBASE_I_IND);
    int first = ssGetIWorkValue( S, FIRST_I_IND );
    int i = 0;

    if( first == 1 )
    {
        // Flush the hardware fifo on startup.
        while( i++ < 65 && (regs->lsr & LSRDR) )
        {
            // Read and discard the data.
            regs->data;
        }

        // Now enable the interrupt.
        // Since TX enable block may have executed first, read ier and modify.
        regs->ier = regs->ier | IERRCV;

        ssSetIWorkValue( S, FIRST_I_IND, 0 );
    }
#endif

}

static void mdlTerminate(SimStruct *S)
{
#ifndef MATLAB_MEX_FILE
    struct uartregs *regs = (struct uartregs *)ssGetIWorkValue(S, PORTBASE_I_IND);

    // Disable interrupts.
    regs->ier = 0;

    // Flush the transmit and receive fifos so the next start will be clean
    regs->fcr = FCREBL | FCRRCLR | FCRTCLR;
#endif
}



#ifdef MATLAB_MEX_FILE  /* Is this file being compiled as a MEX-file? */
#include "simulink.c"   /* Mex glue */
#else
#include "cg_sfun.h"    /* Code generation glue */
#endif
