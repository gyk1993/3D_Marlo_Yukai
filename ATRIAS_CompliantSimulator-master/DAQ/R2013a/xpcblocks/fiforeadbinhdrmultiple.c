/* $Revision: 1.1.8.11 $ $Date: 2010/02/17 18:57:25 $ */
/* fiforeadbinhdrmultiple.c - xPC Target, non-inlined S-function to perform 
 * the read side of a fifo read/write pair given several binary headers and
 * message lengths */
/* Copyright 1996-2009 The MathWorks, Inc.
 *
 * Modified:
 *   2014-07-26 BGB
 *      Created FIFOREADBINHDRMULTIPLE from FIFOBINREADHDR. This new block
 *      differs from the original in that it returns the FIRST valid packet
 *      found, instead of discarding all all but the last.
*/

#define         S_FUNCTION_LEVEL        2
#undef          S_FUNCTION_NAME
#define         S_FUNCTION_NAME         fiforeadbinhdrmultiple

#include        <stddef.h>
#include        <stdlib.h>

#include        "simstruc.h"

#ifdef          MATLAB_MEX_FILE
#include        "mex.h"
#endif

#ifndef         MATLAB_MEX_FILE
#include        <windows.h>
#endif

#include        "xpcdatatypes.h"

//#define DEBUG

/* Input Arguments */
#define NUMBER_OF_ARGS          (8)
#define MAX_WIDTH_ARG           ssGetSFcnParam(S,0)
#define TYPE_ARG                ssGetSFcnParam(S,1)
#define SAMP_TIME_ARG           ssGetSFcnParam(S,2)
#define HEADER_ARG              ssGetSFcnParam(S,3)
#define HLTHS_ARG               ssGetSFcnParam(S,4)
#define LENGTHS_ARG             ssGetSFcnParam(S,5)
#define HOLD_ARG                ssGetSFcnParam(S,6)
#define ENABLE_ARG              ssGetSFcnParam(S,7)

#define NO_I_WORKS              (0)
#define NO_R_WORKS              (0)
#define NO_P_WORKS              (2)

#define HEADERS_P_IND           (0)
#define FIFO_P_IND              (1)

static char_T msg[256];

static void mdlInitializeSizes(SimStruct *S)
{

    int i;
    int maxwidth;
    int outdatatype;
    int type;
    DTypeId id = SS_UINT32;
    int_T nout;
    // enable == 0 if no enable port, 1 to have the enable port
    //    int enable;

    ssSetNumSFcnParams(S, NUMBER_OF_ARGS);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        sprintf(msg,"Wrong number of input arguments passed.\n%d arguments are expected\n",NUMBER_OF_ARGS);
        ssSetErrorStatus(S,msg);
        return;
    }
    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);


    // port 0 is the fifo data
#ifdef          MATLAB_MEX_FILE
    // First create the custom data type for a fifo pointer
    // The Register call defines the signal as a unique type for Simulink
    id = ssRegisterDataType( S, "serialfifoptr" );
    if(id == INVALID_DTYPE_ID)
        return;
    ssSetDataTypeSize(S, id, 12 );
    if( ssGetDataTypeZero( S, id ) == NULL )
    {
        serialfifoptr fifozero;
        
        fifozero.ptrlow = 0;
        fifozero.ptrhigh = 0;
        fifozero.token = 0;
        ssSetDataTypeZero( S, id, &fifozero );
    }
    // Neither of these functions can be called from the target side.
#endif

    if( (int)mxGetPr( ENABLE_ARG )[0] == 1 )
    {
        if( !ssSetNumInputPorts(S, 2) ) return;   // add the enable port
        // Set second port attributes
        ssSetInputPortWidth(S, 1, 1 );
        ssSetInputPortRequiredContiguous( S, 1, 1 ); 
        ssSetInputPortDirectFeedThrough( S, 1, 1 );
    }
    else
    {
        if( !ssSetNumInputPorts(S, 1) ) return;
    }

    ssSetInputPortWidth(S, 0, 1 );
    ssSetInputPortDataType( S, 0, id );
    ssSetInputPortRequiredContiguous( S, 0, 1 ); 
    ssSetInputPortDirectFeedThrough( S, 0, 1 );

    nout = (int_T)mxGetM(ssGetSFcnParam(S,3));
    // Each header string generates an output stream.
    if( !ssSetNumOutputPorts(S, nout) ) return;
    if( mxGetPr( MAX_WIDTH_ARG ) == NULL )
        return;  // undefined variable
    maxwidth = (int)mxGetPr( MAX_WIDTH_ARG )[0];

    // This switch has to agree with the popup list in the mask editor
    // for the output vector type.
    outdatatype = (int)mxGetPr( TYPE_ARG )[0];
    switch( outdatatype )
    {
      case 1:
        type = SS_INT32;
        break;
      case 2:
        type = SS_UINT32;
        break;
      case 3:
        type = SS_INT16;
        break;
      case 4:
        type = SS_UINT16;
        break;
      case 5:
        type = SS_INT8;
        break;
      case 6:
        type = SS_UINT8;
        break;
    }

    for( i = 0 ; i < nout ; i++ )
    {
        ssSetOutputPortWidth(S, i, maxwidth + 1 );
        ssSetOutputPortDataType( S, i, type );
    }

    ssSetNumSampleTimes(S, 1);

    ssSetNumRWork(S, NO_R_WORKS);
    ssSetNumIWork(S, NO_I_WORKS);
    ssSetNumPWork(S, NO_P_WORKS);

    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    ssSetSimStateCompliance( S, DISALLOW_SIM_STATE );
     
    for( i = 0 ; i < NUMBER_OF_ARGS ; i++ )
    {
        ssSetSFcnParamTunable(S,i,0);  /* None of the parameters are tunable */
    }

    ssSetOptions(S, SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME | SS_OPTION_EXCEPTION_FREE_CODE |
                    SS_OPTION_NONSTANDARD_PORT_WIDTHS );
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
    if (mxGetPr(SAMP_TIME_ARG)[0]==-1.0)
    {
        ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
        ssSetOffsetTime(S, 0, FIXED_IN_MINOR_STEP_OFFSET);
    }
    else
    {
        ssSetSampleTime(S, 0, mxGetPr(SAMP_TIME_ARG)[0]);
        ssSetOffsetTime(S, 0, 0.0);
    }
}

#define MDL_START
static void mdlStart(SimStruct *S)
{
    int i, j;
    unsigned char **strings;
    int_T M, N;
    //unsigned char *tempstr;
    int fifosize;
    serialfifoptr *IPtr = (serialfifoptr *)ssGetInputPortSignal(S,0);
#ifdef _WIN64
    int_T *Fifo = (int_T *)( (uint64_T)IPtr->ptrlow | ((uint64_T)IPtr->ptrhigh << 32));
#else
    int_T *Fifo = (int_T *)IPtr->ptrlow;
#endif
    unsigned char *fstr;

    M = (int_T)mxGetM(HEADER_ARG);  // number of header strings
    N = (int_T)mxGetN(HEADER_ARG);  // length of longest string
#ifdef DEBUG
    printf("header M = %d, N = %d\n", M, N );
#endif
    if( (int_T)mxGetN(HLTHS_ARG) != M )
    {
        sprintf( msg, "Number of header lengths is not the same as the number of headers: %d, %d\n", mxGetN(HLTHS_ARG), M );
        ssSetErrorStatus( S, msg );
    }

    strings = (unsigned char **)malloc( M * sizeof(char *) );
    for( i = 0 ; i < M ; i++ )
        strings[i] = (unsigned char *)malloc( N + 1 );

    for( i = 0 ; i < M ; i++ )
    {
        for( j = 0 ; j < N ; j++ )
        {
            strings[i][j] = (unsigned char)mxGetPr( HEADER_ARG )[i + j*M];
#ifdef DEBUG
            printf("%x ", strings[i][j] & 0xff);
#endif
        }
        strings[i][j] = 0;
#ifdef DEBUG
        printf("\n" );
#endif
    }

    ssSetPWorkValue(S, HEADERS_P_IND, strings );

    if( IPtr->token != 'FiFo' )
    {
        ssSetPWorkValue(S, FIFO_P_IND, (void *)0 );
        return;  // Don't allocate fifo copy buffer if not connected
    }

    fifosize = Fifo[0];
    fstr = malloc( fifosize+1 );
    if( fstr == 0 )
    {
        printf("Malloc error: fstr = 0x%x\n", fstr );
        return;
    }
    ssSetPWorkValue(S, FIFO_P_IND, fstr );
}
#undef DEBUG

static void mdlOutputs(SimStruct *S, int_T tid)
{
    // This block uses the output arrays as persistent storage between
    // calls.

    serialfifoptr *IPtr = (serialfifoptr *)ssGetInputPortSignal(S,0);
#ifdef _WIN64
    int_T *Fifo = (int_T *)( (uint64_T)IPtr->ptrlow | ((uint64_T)IPtr->ptrhigh << 32));
#else
    int_T *Fifo = (int_T *)IPtr->ptrlow;
#endif
    int fifosize;
    int_T *rptr = &Fifo[1];
    int_T *wptr = &Fifo[2];
    int_T *data = &Fifo[3];
    int fifocount;
    // enable == 0 if no enable port, 1 to have the enable port
    int enable = (int)mxGetPr( ENABLE_ARG )[0];
    double enabled;
    // hold = 1 to hold previous output, 2 to zero all outputs first
    int hold = (int)mxGetPr( HOLD_ARG )[0];
    unsigned char **strings = ssGetPWorkValue( S, HEADERS_P_IND );
    int hdrnum;
    int hdrmaxlth = 0;
    int_T M = (int_T)mxGetM(HEADER_ARG);    // number of header strings
    unsigned char *fstr = ssGetPWorkValue( S, FIFO_P_IND );

    void  *DPtr;
    int   *intPtr;    // types 1 and 2
    short *shortPtr;  // types 3 and 4
    char  *charPtr;   // types 5 and 6

    //int maxenabled;
    //int maxread = (int)mxGetPr( MAX_WIDTH_ARG )[0];
    int type = (int)mxGetPr( TYPE_ARG )[0];
    int i, j, k;

#ifdef DEBUG
printf("mdlOut start fifo read\n");
#endif

    if( IPtr->token != 'FiFo' )
        return;  // Do nothing, unless there really is a fifowrite connected

    if( fstr == NULL )  // Allocate the copy buffer the first time.
    {
        // In simulation, the 'FiFo' token doesn't make it through the
        // rate transition at mdlStart time.  It does get through in
        // target code though.  This catches the simulation delay.
        fifosize = Fifo[0];
        fstr = malloc( fifosize+1 );
        if( fstr == 0 )
        {
            printf("Malloc error: fstr = 0x%x\n", fstr );
            return;
        }
        ssSetPWorkValue(S, FIFO_P_IND, fstr );
    }

    if( enable == 1 )  // check the enable input
    {
        enabled = *(double *)ssGetInputPortSignal(S,1);
#ifdef DEBUG
printf("enabled = %f\n", enabled );
#endif
        if( enabled < 0.5 )
            return;
    }
#ifdef DEBUG
printf("start: rptr = %d, wptr = %d\n", *rptr, *wptr );
#endif
    fifosize = Fifo[0];
    fifocount = *wptr - *rptr;
    if( fifocount < 0 )
        fifocount += fifosize;

    for( i = 0 ; i < fifocount ; i++ )
    {
        j = (*rptr + i) % fifosize;
        fstr[i] = data[(*rptr + i) % fifosize];
    }
    fstr[fifocount] = 0;  // null terminate the whole string

    for( hdrnum = 0 ; hdrnum < M ; hdrnum++ )
    {
        int lth;
        lth = (int)mxGetPr(HLTHS_ARG)[hdrnum];
        hdrmaxlth = (lth > hdrmaxlth)?lth:hdrmaxlth;
        // Stopping if there are fewer characters left than the longest
        // header might be a bug if there is one header that is much
        // shorter than the others.  Detecting the short header would
        // be delayed until more characters are available.

        if( hold == 2 ) // Zero out the output vector if no new data
        {
            DPtr     =  (void *)ssGetOutputPortSignal( S, hdrnum );
            intPtr   =   (int *)DPtr;   // types 1 and 2
            shortPtr = (short *)DPtr;   // types 3 and 4
            charPtr  =  (char *)DPtr;   // types 5 and 6
            switch( type )
            {
              case 1:  // int32
              case 2:  // uint32
                intPtr[0] = 0;  // clear the count
                break;
              case 3:  // int16
              case 4:  // uint16
                shortPtr[0] = 0;  // clear count
                break;
              case 5:  // int8
              case 6:  // uint8
                charPtr[0] = 0;  // first character is the null terminator
                break;
            }
        }
    }

    // Search for the header, then check to see if there are enough
    // characters to satisfy the requested message length.

    {
        int state = 1;  // Search for header state
        //int port;
        int hdrfound = 0;
#ifdef DEBUG
        printf("start: rptr = %d, wptr = %d\n", *rptr, *wptr );
#endif
        for( i = 0 ; i < fifocount ; i++ )
        {
            // state 1
            // search for header or end of string
            // if header found, then
            //   remember where the header starts
            //   increment i to jump over the whole header
            //   switch to state 2
            // else if header not found, then increment *rptr to discard
            //   the lead character in the fifo.
            // else if too few chars for the longest header, leave.

            // state 2
            // Check for enough characters to satisfy the specified length.
            // If there are enough, copy header+chars to output.
            // If not enough, leave.

            hdrfound = 0;
            for( hdrnum = 0 ; hdrnum < M ; hdrnum++ )
            {
                int hdrlen = (int)mxGetPr(HLTHS_ARG)[hdrnum];

                // strncmp won't work if the header has a NULL in it!
                if( strncmp( strings[hdrnum], &(fstr[i]), hdrlen ) == 0 )
                {
                    int copyend = i + (int)mxGetPr(LENGTHS_ARG)[hdrnum];

#ifdef DEBUG
                    printf("hdrnum %d, i %d, end %d\n", hdrnum, i, copyend );
#endif
                    if( copyend > fifocount ) // if not enough characters
                    {
                        hdrfound = -1;  // found, but not enough chars
                        break;
                    }

                    hdrfound = 1;

                    DPtr     =  (void *)ssGetOutputPortSignal( S, hdrnum );
                    intPtr   =   (int *)DPtr;   // types 1 and 2
                    shortPtr = (short *)DPtr;   // types 3 and 4
                    charPtr  =  (char *)DPtr;   // types 5 and 6

                    // Only clear the correct number of bytes for this
                    // output data type, just in case the output vector
                    // is very short!
                    switch( type )
                    {
                      case 1:  // int32
                      case 2:  // uint32
                        intPtr[0] = 0;  // clear the count
                        break;
                      case 3:  // int16
                      case 4:  // uint16
                        shortPtr[0] = 0;  // clear count
                        break;
                      case 5:  // int8
                      case 6:  // uint8
                        charPtr[0] = 0;  // first character is the null terminator
                        break;
                    }

                    for( j = i ; j < copyend ; j++ )
                    {
                        int value = data[ *rptr ];
                        k = j - i;
                        //data[*rptr] = 0;  // clear the stale data
                        switch( type )
                        {
                          case 1:  // int32
                          case 2:  // uint32
                            intPtr[k+1] = value;
                            intPtr[0]++;
                            break;
                          case 3:  // int16
                          case 4:  // uint16
                            shortPtr[k+1] = value & 0xffff;
                            shortPtr[0]++;
                            break;
                          case 5:  // int8
                          case 6:  // uint8
                            charPtr[k] = value & 0xff;
                            break;
                        }
                        *rptr = (*rptr + 1)%fifosize;
#ifdef DEBUG
                        printf("copy: rptr = %d, wptr = %d\n", *rptr, *wptr );
#endif
                    }
                    if( type == 5 || type == 6 )
                        charPtr[j-i] = 0;  // Null terminator for strings
                    state = 1;
                    i = copyend - 1;  // position of LAST char copied.
                }
            }
            // BGB
            // Break if we already found a valid packet so that we do not
            // overwrite it if another valid packet exists.
            if( hdrfound == 1)
                break;
            // END BGB
            // If the longest header won't fit, don't discard any more
            // if we're still looking for a header.  Pick it up next
            // time.
            if( (fifocount - i) <= hdrmaxlth )
            {
                break;
            }
            if( hdrfound == -1 )
                break;
            if( hdrfound == 0 )
            {   // Drop the character from the fifo.
                *rptr = (*rptr + 1)%fifosize;
#ifdef DEBUG
                printf("loop: rptr = %d, wptr = %d\n", *rptr, *wptr );
#endif
            } 
       } // end on for each character in the fifo
    } // end block of code
}

static void mdlTerminate(SimStruct *S)
{
    int_T M = (int_T)mxGetM(ssGetSFcnParam(S,3));  // number of header strings
    char **strings = ssGetPWorkValue( S, HEADERS_P_IND );
    int i;
    unsigned char *fstr = ssGetPWorkValue( S, FIFO_P_IND );

    for( i = 0 ; i < M ; i++ )
        free( strings[i] );

    free( strings );

    if( fstr != NULL )
        free( fstr );
}

#ifdef MATLAB_MEX_FILE  /* Is this file being compiled as a MEX-file? */
#include "simulink.c"   /* Mex glue */
#else
#include "cg_sfun.h"    /* Code generation glue */
#endif
