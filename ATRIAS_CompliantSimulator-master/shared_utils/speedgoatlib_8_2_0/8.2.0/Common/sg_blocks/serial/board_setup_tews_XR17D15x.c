/* $Revision$ $Date$ */
/* intcheckfc422335.c - xPC Target, non-inlined S-function driver for serial
 * output direction for the  Fastcomm 422/2-PCI board */
/* Copyright 1996-2006 The MathWorks, Inc.
*/

#define         S_FUNCTION_LEVEL        2
#undef          S_FUNCTION_NAME
#define         S_FUNCTION_NAME         board_setup_tews_XR17D15x

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

//#define DEBUG

/* Input Arguments */
#define NUMBER_OF_ARGS          (3)
#define SLOT_ARG                ssGetSFcnParam(S,0)
#define IRQ_ARG                 ssGetSFcnParam(S,1)
#define TYPE_ARG                ssGetSFcnParam(S,2)

#define NO_I_WORKS              (1)
#define CONFIG_I_IND            (0)

#define NO_R_WORKS              (0)

static unsigned long set_clock( struct uartconfig *reg, unsigned long rate);

static char_T msg[256];

static void mdlInitializeSizes(SimStruct *S)
{

    int i;

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

    struct uartconfig *config;
    xpcPCIDevice pDev;
    int_T  vendorId, deviceId;
    int_T  pciBus, pciSlot;
    int_T  bdregs;
    char_T *devName;
    int_T  boardtype = (int_T)mxGetPr(TYPE_ARG)[0];
    int_T  intnum    = (int_T)mxGetPr(IRQ_ARG)[0];

    switch( boardtype )
    {
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
        sprintf( msg, "board_setup_XR17D15x driver: Unknown board type, %d", boardtype );
        ssSetErrorStatus( S, msg );
        return;
    }

    if( mxGetN(SLOT_ARG) == 1 )
    {
        pciBus = 0;
        pciSlot = (int_T) mxGetPr(SLOT_ARG)[0];
    } else
    {
        pciBus = (int_T) mxGetPr(SLOT_ARG)[0];
        pciSlot = (int_T) mxGetPr(SLOT_ARG)[1];
    }

    if( xpcGetPCIDeviceInfo( vendorId, deviceId, -1, -1, pciBus, pciSlot, &pDev ) )
    {
        sprintf(msg, "No %s at bus %d slot %d", devName, pciBus, pciSlot);
        ssSetErrorStatus(S, msg);
        return;
    }

    pDev.VirtAddress[0]
        = (long)xpcReserveMemoryRegion( (void *)(pDev.BaseAddress[0]),
                                        pDev.Length[0],
                                        XPC_RT_PG_USERREADWRITE);

    // show Device Information
    // xpcShowPCIDeviceInfo( &pDev );
    //printf("base addr = 0x%x\n", pDev.VirtAddress[0]);

    ssSetIWorkValue(S, CONFIG_I_IND, (int32_T)pDev.VirtAddress[0] );
    config = (struct uartconfig *)((int)pDev.VirtAddress[0] + UARTCONFIGOFFSET);
    

    //set_clock( config, reffreq );
 
    if( intnum != pDev.InterruptLine )
    {
        // Can't print a two line error message with ssSetErrorStatus
        // and calling it twice only yields the second message.  This error
        // needs just a bit more room than 1 line, hence the printf.
        printf( "TEWS TPMC/PMC521:\n");
        sprintf( msg, " Expected IRQ %d, found IRQ %d.", intnum, pDev.InterruptLine );
        ssSetErrorStatus( S, msg );
        return;
    }
    
    // enable global interrupts
    
    config->mpiosel=0xfe;
    config->mpiolvl=0x01;
    
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
    int8_T *base = (int8_T *)ssGetIWorkValue(S, CONFIG_I_IND );
    struct uartconfig *config = (struct uartconfig *)((int32_T)base + UARTCONFIGOFFSET );

    // Disable global interrupts.
    config->mpiolvl = 0x00;

#endif
}

#ifndef MATLAB_MEX_FILE
static unsigned long set_clock( struct uartconfig *reg, unsigned long rate)
{
    unsigned long bestVDW = 1;  //Best calculated VCO Divider Word
    unsigned long bestRDW = 1;  //Best calculated Reference Divider Word
    unsigned long bestOD = 1;   //Best calculated Output Divider
    unsigned long result = 0;
    unsigned long i = 0;
    unsigned long tempValue = 0;
    unsigned long vdw = 1;      //VCO Divider Word
    unsigned long rdw = 1;      //Reference Divider Word
    unsigned long od = 1;       //Output Divider
    unsigned long lVDW = 1;     //Lowest vdw
    unsigned long lRDW = 1;     //Lowest rdw
    unsigned long lOD = 1;      //Lowest OD
    unsigned long hVDW = 1;     //Highest vdw
    unsigned long hRDW = 1;     //Highest rdw
    unsigned long hOD = 1;      //Highest OD
    unsigned long desired = 0;  //Desired clock 1 output
    unsigned long hi;           //initial range freq Max
    unsigned long low;          //initial freq range Min
    unsigned long check;        //Calculated clock
    unsigned long clk1;         //Actual clock 1 output
    unsigned long inFreq = 18432000;  //Input clock frequency
    unsigned long range1=0;     //Desired frequency range limit per ics307 mfg spec.
    unsigned long range2=0;     //Desired frequency range limit per ics307 mfg spec.
    unsigned data = 0;
    unsigned origmpio = 0;
    int odskip = 0;

#ifdef DEBUG
    printf("SerialSetClock Executing %ld Hz\n",rate);
#endif //DEBUG

    desired = rate;

    // Initialize the mpio to:
    reg->mpioint = 0;    // no interrupts
    reg->mpio3t = 0;     // not tristate
    reg->mpioinv = 0;    // not inverted
    reg->mpiosel = 0;    // all output
    reg->mpiolvl = 0x78; // Not 485 mode

    origmpio = reg->mpiolvl;   //Save MPIO pin state
#ifdef DEBUG
    printf("orig mpiolvl = 0x%2.2x\n", origmpio );
#endif //DEBUG
    data = origmpio;

    // Check reference frequency range in the mask.

    hi=(desired+(desired/10));
    low=(desired-(desired/10));
	
#ifdef DEBUG
    printf("Hi = %d  Low = %d \n",hi, low);
#endif //DEBUG

    od = 2;
    while (od <= 10)
    {
        switch(od)  //check maximum frequency with given OD for industrial temp chips
        {
          case 2:
            if(desired > 180000000)
                odskip = 1;
            break;
          case 3:
            if(desired > 120000000)
                odskip = 1;
            break;
          case 4:
            if(desired > 90000000)
                odskip = 1;
            break;
          case 5:
            if(desired > 72000000)
                odskip = 1;
            break;
          case 6:
            if(desired > 60000000)
                odskip = 1;
            break;
          case 7:
            if(desired > 50000000)
                odskip = 1;
            break;
          case 8:
            if(desired > 45000000)
                odskip = 1;
            break;
          case 9:	// OD = 9 not allowed
            odskip=1;
          case 10:
            if(desired > 36000000)
                odskip = 1;
            break;
          default:
            printf("Case 1 Invalid OD = %ld.\n",od);
            return -1;
        }
        rdw = 1;
        while ( (rdw <= 127) && (odskip==0) )
        {
            vdw = 4;
            while (vdw <= 511)
            {
                check = (((inFreq * 2) / ((rdw + 2)*od)) * (vdw + 8) );	//calculate a check frequency
                range1 = ((inFreq * 2 * (vdw + 8)) / (rdw + 2));
                range2 = (inFreq / (rdw + 2));
                //Calculate operating ranges
                if ( ((range1) > 60000000) && ((range1) < 360000000) && ((range2) > 200000) )	//check operating ranges
                {
                    if (check == low)	//If this combination of variables == the current lowest set
                    {
                        if (lRDW > rdw)	//If this combination has a lower rdw
                        {
                            lVDW=vdw;
                            lRDW=rdw;
                            lOD=od;
                            low=check;
                        }
                        else if ((lRDW == rdw) && (lVDW < vdw))	//If this combo has the same rdw then take the higher vdw
                        {
                            lVDW=vdw;
                            lRDW=rdw;
                            lOD=od;
                            low=check;
                        }
                    }
                    else if (check == hi)	//If this combination of variables == the current lowest set
                    {
                        if (hRDW > rdw)	//If this combination has a lower rdw
                        {
                            hVDW=vdw;
                            hRDW=rdw;
                            hOD=od;
                            hi=check;
                        }
                        else if ((hRDW == rdw) && (hVDW < vdw))	//If this combo has the same rdw then take the higher vdw	
                        {
                            hVDW=vdw;
                            hRDW=rdw;
                            hOD=od;
                            hi=check;
                        }
                    }
                    if ((check > low) && (check < hi))		//if difference is less than previous difference
                    {
                        if (check > desired)	//if the new combo is larger than the desired, new hi combination
                        {
                            hi=check;
                            hVDW=vdw;
                            hRDW=rdw;
                            hOD=od;
                        }
                        else	//if the new combo is less than the desired, new low combination
                        {
                            low=check;
                            lVDW = vdw;
                            lRDW = rdw;
                            lOD = od;
                        }
                    }
                }
                vdw++;
            }
            
            rdw++;
        }
        odskip=0;
        od++;
    }
    
    if ((hi - desired) < (desired - low))
    {
        bestVDW=hVDW;
        bestRDW=hRDW;
        bestOD=hOD;
        clk1=hi;
    }
    else
    {
        bestVDW=lVDW;
        bestRDW=lRDW;
        bestOD=lOD;
        clk1=low;
    }
    switch(bestOD)
    {
      case 2:
        result=0x11;
        break;
      case 3:
        result=0x16;
        break;
      case 4:
        result=0x13;
        break;
      case 5:
        result=0x14;
        break;
      case 6:
        result=0x17;
        break;
      case 7:
        result=0x15;
        break;
      case 8:
        result=0x12;
        break;
      case 10:
        result=0x10;
        break;
      default:
        printf("Case 2 Invalid OD=%ld.\n",od);
        return -1;	
    }
    range1 = (inFreq * 2 * ((bestVDW + 8)/(bestRDW + 2)));
    range2 = (inFreq/(bestRDW + 2));
    clk1 = (((inFreq * 2) / ((bestRDW + 2)*bestOD)) * (bestVDW + 8) );
//    printf(" 55 MHz < %d MHz < 400 MHz\n", range1);
//    printf(" 200 kHz < %d kHz \n", range2*1000);
    result <<= 9;
    result |= bestVDW;
    result <<= 7;
    result |= bestRDW;
//    result |= 0x200000;  //1 = set levels to TTL, 0 = CMOS
//    printf("Clock bytes = %X\n",result);
#ifdef DEBUG
    printf("The desired clock control bytes are: 0x%lx\n",result);
    printf("The desired frequency is: %dHz\n", desired);
    printf("The base clock is: %dHz\n", inFreq);
    printf("High: %d    ",hi);
    printf("Low: %d.\n",low);
    printf("The best calculated clock is: %ldHz\n", clk1);
    printf("The best VDW = %d  RDW = %d  OD = %d.\n", bestVDW, bestRDW, bestOD);
    //printf("CH_ID = %d \n", extension->chid);
#endif // DEBUG
	
	
    /*********************** Begin clock set *************************/

#ifdef DEBUG
    printf("addr reg = 0x%x, reg->mpiolvl = 0x%x\n", reg, &(reg->mpiolvl) );
#endif // DEBUG

    tempValue = (result & 0x00ffffff);
    tempValue |= 0x00180000;  // [F1,F0] == 11
	
    for( i = 0 ; i < 24 ; i++ )
    {
        //data bit set
        if ((tempValue & 0x800000)!=0) 
        {
            data = 0x01;
        }
        else 
        {
            data = 0;
        }
#ifdef DEBUG
            printf("%x ", data);
#endif // DEBUG
        reg->mpiolvl = data;
        rl32eWaitDouble( 40e-6 );

        //clock high, data still there
        data |= 0x02;
        reg->mpiolvl = data;
        rl32eWaitDouble( 40e-6 );

        //clock low, data still there
        data &= 0x01;
        reg->mpiolvl = data;
        rl32eWaitDouble( 40e-6 );

        tempValue = tempValue << 1;
    }
#ifdef DEBUG
    printf("\n");
#endif // DEBUG
	
    data = 0x04;		//strobe on
#ifdef DEBUG
            printf("strobe: %x ", data);
#endif // DEBUG
    reg->mpiolvl = data;
    rl32eWaitDouble( 40e-6 );

    data = 0;		//all off
#ifdef DEBUG
            printf("strobe off: %x ", data);
#endif // DEBUG
    reg->mpiolvl = data;
    rl32eWaitDouble( 40e-6 );

    reg->mpiolvl = 0; //origmpio;
    rl32eWaitDouble( 40e-6 );
    return clk1;
}
#endif

#ifdef MATLAB_MEX_FILE  /* Is this file being compiled as a MEX-file? */
#include "simulink.c"   /* Mex glue */
#else
#include "cg_sfun.h"    /* Code generation glue */
#endif
