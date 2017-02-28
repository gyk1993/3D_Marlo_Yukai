#ifndef __XPCIO104DMAHOOKS_C__
#define __XPCIO104DMAHOOKS_C__

#include <conio.h>
#include <windows.h>
#include "xpctarget.h"

/* General Standards 16AISS8AO4 */
////////////////////////////////////////////////////////////////////////////////////
//#include "sg_IO104_DMA.h"  START OF INCLUDE FILE
////////////////////////////////////////////////////////////////////////////////////
// Because of the obfuscation we need to really include the include file....

//#ifndef SG_IO104_DMA_H
//#define SG_IO104_DMA_H

#include <stddef.h>
#include <stdlib.h>
         
#include "simstruc.h" 
         
#ifdef 	 MATLAB_MEX_FILE
#include "mex.h"
#endif   

#ifndef  MATLAB_MEX_FILE
#include <windows.h>
#include "io_xpcimport.h"
#include "pci_xpcimport.h"
#include "time_xpcimport.h"
#include "ioext_xpcimport.h"
#include "util_xpcimport.h"
#endif

/* Debug Settings */
//#define USE_DIGITAL_OUTPUTS_FOR_DEBUGGING
//#define DEBUG_PRINTF
//#define DEBUG_PRINT_FUNCTION_CALLS

/* Board constants */
#define DEVNAME "Speedgoat IO104"
#define VENDORID 0x10b5
#define DEVICEID 0x9056
#define SUBVENDORID 0x10b5
#define SUBDEVICEID 0x3172

#define NUM_DA_CH 4
#define NUM_AD_CH 8

#define INTERNAL_CLOCK 40.32e6

/* IO104 register access structure */
typedef volatile struct IO104_tag {
    volatile uint32_T bcr;                      // (00) Board Control Register (BCR). 
    volatile uint32_T dio;                      // (04) 16-Bit Digital I/O port data (00XX 00XXh)
    volatile uint32_T analogOutCh[NUM_DA_CH];   // (08) Output Channel X data.
    volatile uint32_T analogInBuf;              // (18) Analog input buffer data. (00XX XXXXh)
    volatile uint32_T inputClkDiv;              // (1c) Rate-A generator divider; 24 bits.
    volatile uint32_T burstClkDiv;              // (20) Rate-B generator divider; 24 bits.
    volatile uint32_T inputConfig;              // (24) Analog inputs channel-mask and burst-size.
    volatile uint32_T inputBufSize;             // (28) Number of data values in the input buffer.
    volatile uint32_T inputBufThreshold;        // (2c) Input buffer status flag threshold
    volatile uint32_T primaryStatus;            // (30) Principal status-flag register
    volatile uint32_T assemblyConfig;           // (34) Options and firmware revision
    volatile uint32_T autoCalValues;            // (38) Autocal value readback
    volatile uint32_T bor;                      // (3c) Buffered Analog Outputs Control (BOR)
    volatile uint32_T outputBufThreshold;       // (40) Output buffer status flag threshold
    volatile uint32_T outputBufSize;            // (44) Number of data values in the output buffer.
    volatile uint32_T analogOutBuf;             // (48) Analog Output Data Buffer
    volatile uint32_T outputClkDiv;             // (4c) Rate-C generator divider; 24 bits.
    volatile uint32_T auxUser[4];               // (50) Four auxiliary 32-Bit user registers
} IO104_T;


/* IO104->bcr BCR bit positions */
#define ANALOG_INPUT_MODE            0 /* RW  Analog input mode: 0 => Differential system inputs, 1 => Single-ended system inputs, 2 => Zero selftest, 3 => VREF selftest, 4 => Output Channel 00, 5 => Output Channel 01, 6 => Output Channel 02, 7 => Output Channel 03 */
#define ANALOG_INPUT_AUTOCAL         3 /* RW  Initiates an analog-inputs autocalibration operation. */
#define INPUT_RANGE_A                4 /* RW  Analog input Range-A; Channels 00, 01, 04, 05: 0 => ±2.5V, 1 => ±5V, 2 => ±10V (default)  3 => (Reserved) */
#define INPUT_RANGE_B                6 /* RW  Analog input Range-B; Channels 02, 03, 06, 07: 0 => ±2.5V, 1 => ±5V, 2 => ±10V (default)  3 => (Reserved) */
#define INPUT_SW_CLOCK               8 /* RW  Initiates a single sample of active input channels. Overrides existing input clocking source. */
#define ENABLE_INPUT_BURST           9 /* RW  Enables triggered burst input acquisition. */
#define INPUT_BURST_BUSY            10 /* RO  HIGH when a triggered input burst is in progress. */
#define INPUT_SW_TRIGGER            11 /* RW  Initiates a single input data burst. Overrides existing burst triggering source. */
#define ENABLE_INPUT_BUFFER         12 /* RW  Enables the analog input buffer for accepting data. */
#define CLEAR_INPUT_BUFFER          13 /* RW  Clears (empties) the analog input data buffer. Clears automatically. */
#define INPUT_BUFFER_THRESHOLD_FLAG 14 /* RO  HIGH when the number of values in the input buffer exceeds the selected buffer threshold. */
#define INPUT_BUFFER_OVERFLOW       15 /* RW  Set HIGH if the input buffer overflows. Stays HIGH until cleared from the bus or by a board reset. */
#define OUTPUT_RANGE                16 /* RW  Analog Output Voltage Range: 0 => ±2.5V, 2 => ±10V, 1 => ±5V 3 => (Reserved) */
#define SIMULTANEOUS_OUTPUTS        18 /* RW  When HIGH, all outputs update simultaneously in response to an output clock. When LOW, each output is updated immediately when new data is received. */
#define ENABLE_BUFFERED_OUTPUTS     19 /* RW  When HIGH, enables the analog output FIFO buffer, and disables the analog output registers ANALOG OUTPUT CHAN xx. */
#define OUTPUT_SW_CLOCK             20 /* RW  Produces a single analog output clock. Overrides existing output clocking source. */
#define TRIGGER_INITIATOR           21 /* RW  Configures the shared analog input/output hardware trigger pin as an output if HIGH, or as an input if LOW. */
#define ENABLE_RATE_C_GENERATOR     22 /* RW  Enables the Rate-C generator for analog outputs. */
#define INPUT_BUFFER_UNDERFLOW      23 /* RW  Set HIGH if the input buffer underflows. Stays HIGH until cleared from the bus or by a board reset. */
#define ANALOG_INPUT_CLK_INITIATOR  24 /* RW  Configures the analog input I/O clock as an output if HIGH, or as an input if LOW. */
#define OFFSET_BINARY               25 /* RW  Selects offset-binary analog I/O data format when HIGH, or two's complement when LOW. */
#define ENABLE_RATE_A_GENERATOR     26 /* RW  Enables the Rate-A generator for analog inputs. */
#define ENABLE_RATE_B_GENERATOR     27 /* RW  Enables the Rate-B generator for triggered bursts. */
#define AUTOCAL                     28 /* RW  Initiates an autocalibration operation when asserted. Clears automatically upon completion, */
#define AUTOCAL_PASS                29 /* RO  Set HIGH at reset or autocal initialization. A HIGH state after autocal confirms a successful calibration. */
#define SWAP_DEMAND_MODE_CHANNELS   30 /* RW  Reverses the default demand-mode DMA channels for analog inputs and outputs */
#define INITIALIZE                  31 /* RW  Initializes the board. Sets all register defaults. */

/* IO104->bor Buffered Output Operations Register BOR */
#define AO_CHAN_00_ACTIVE            0 /* Active-channel mask for analog output channels. HIGH => Active; LOW => Inactive.*/
#define AO_CHAN_01_ACTIVE            1
#define AO_CHAN_02_ACTIVE            2
#define AO_CHAN_03_ACTIVE            3
#define ANALOG_OUTPUT_CLK_INITIATOR  4 /* Selects the internal Rate-C generator for output clocking if HIGH, or the Output Clock I/O hardware input if LOW. */
#define ENABLE_OUTPUT_CLOCKING       5 /* Enables output clocking when HIGH. Disables clocking when LOW. Default is LOW (clocking disabled). */
#define OUTPUT_CLOCK_READY           6 /* Indicates when HIGH that an output clock will be accepted. If LOW, indicates that the output will not respond to a clock. */
#define OUTPUT_SW_CLOCK_BOR          7 /* Produces a single output clock event when asserted. Independent of clocking mode. Duplicated in the BCR.*/ 
#define CIRCULAR_BUFFER              8 /* Selects circular buffer configuration if HIGH, or open self-flushing buffer configuration if LOW. Access for loading new data into the circular buffer must be requested by asserting LOAD REQUEST. Default is LOW; i.e. open buffer. */
#define LOAD_REQUEST                 9 /* When set HIGH, requests loading access to the circular buffer. Initializes LOW. */
#define LOAD_READY                  10 /* Set HIGH when the frame index passes through zero, if both CIRCULAR BUFFER and LOAD REQUEST are HIGH. When HIGH, indicates that the circular buffer is ready to accept new data. Available also in the PSR. Defaults HIGH. */
#define CLEAR_OUTPUT_BUFFER         11 /* Resets the output buffer to empty. */
#define AO_BUFFER_EMPTY             12 /* Indicates the analog output buffer is empty. */
#define AO_BUFFER_THRESHOLD         13 /* Analog output buffer threshold flag. Duplicated in the AO Buffer Threshold register. */
                                       /* D14 (Reserved) Inactive; Returns zero. */
#define AO_BUFFER_FULL              15 /* Indicates the output buffer is full. */
#define AO_BUFFER_OVERFLOW          16 /* Set HIGH when data is written to a full buffer. */
#define FRAME_OVERFLOW              17 /* Set HIGH when data is written to a closed buffer. */
#define BURST_READY                 18 /* If HIGH, indicates that a burst trigger will be accepted. If LOW, indicates that the output will not respond to a trigger. */
#define ENABLE_OUTPUT_BURST         19 /* Enables analog output burst operation. */
#define OUTPUT_SW_TRIGGER           20 /* Produces a single output trigger event when asserted. Clears LOW automatically when the clock event is completed. Independent of triggering mode. */
                                       /* D21-D31 (Reserved) Inactive. Returns all-zero. */
/* IO104->dio Digital I/O Port bit positions */
#define DIO_BYTE_0                   0 /* System connector pins DIO 00 through DIO 07. */
#define DIO_BYTE_0_DIR               8 /* Direction control for DIO BYTE 00. When LOW, DIO BYTE 00 is an input field. When HIGH, DIO BYTE 00 is an output field. */
                                       /* D09-D15 (Reserved) Read back as all-zero. */
#define DIO_BYTE_1                  16 /* System connector pins DIO 08 through DIO 15. */
#define DIO_BYTE_1_DIR              24 /* Direction control for DIO BYTE 01. When LOW, DIO BYTE 01 is an input field. When HIGH, DIO BYTE 01 is an output field. */
                                       /* D25-D31 (Reserved) Read back as all-zero. */
#define DIO_INPUT  0
#define DIO_OUTPUT 1
                                       
                                       
// IO104->inputConfig
#define BURST_BLOCK_SIZE_MASK           0x00ffffff /* Number of active channel sets acquired during a triggered burst. */
#define ENABLE_INPUT_0                          24 /* Bit position for Analog input channel 0 selection */

// IO104->inputBufThreshold
#define INPUT_BUFFER_THRESHOLD_MASK     0x0003ffff /* Specifies the number of values in the input buffer, above which the threshold flag is asserted HIGH. */
#define INPUT_BUFFER_THRESHOLD_FLAG_2           19 /* HIGH when the number of values in the input buffer exceeds the specified buffer threshold. */

// IO104->primaryStatus
#define AUTOCAL_COMPLETED_EVENT_SELECTOR         0 /* Enable Autocal completed event*/
#define AUTOCAL_COMPLETED_EVENT                 16 /* Autocal completed event*/
#define AD_BUF_THR_DOWN_EVENT_SELECTOR           1 /* Enable Input Buffer threshold flag HIGH-to-LOW transition event*/
#define AD_BUF_THR_DOWN_EVENT                   17 /* Input Buffer threshold flag HIGH-to-LOW transition */
#define AD_BUF_THR_UP_EVENT_SELECTOR             2 /* Enable Input Buffer threshold flag LOW-to-HIGH transition event */
#define AD_BUF_THR_UP_EVENT                     18 /* Input Buffer threshold flag LOW-to-HIGH transition event */
#define AD_BUF_OVER_OR_UNDERFLOW_EVENT_SELECTOR  3 /* Enable Input Buffer Overflow or Underflow event */
#define AD_BUF_OVER_OR_UNDERFLOW_EVENT          19 /* Input Buffer Overflow or Underflow event */
#define AD_BURST_STARTED_EVENT_SELECTOR          4 /* Enable Analog Input Burst initiated (BURST BUSY LO-HI) event */
#define AD_BURST_STARTED_EVENT                  20 /* Analog Input Burst initiated (BURST BUSY LO-HI) event */
#define AD_BURST_COMPLETED_EVENT_SELECTOR        5 /* Enable Analog Input Burst Completed (BURST BUSY HI-LO) event */
#define AD_BURST_COMPLETED_EVENT                21 /* Analog Input Burst Completed (BURST BUSY HI-LO) event */
#define AD_CLOCK_EVENT_SELECTOR                  6 /* Enable Analog Input Clock event */
#define AD_CLOCK_EVENT                          22 /* Analog Input Clock event */
#define DA_CLOCK_EVENT_SELECTOR                  7 /* Enable Analog Output Clock event */
#define DA_CLOCK_EVENT                          23 /* Analog Output Clock event */
#define DI_BYTE_0_RISING_EVENT_SELECTOR          8 /* Enable Digital I/O Port DIO 00 LOW-to-HIGH transition event */
#define DI_BYTE_0_RISING_EVENT                  24 /* Digital I/O Port DIO 00 LOW-to-HIGH transition event */
#define DA_BUF_THR_DOWN_EVENT_SELECTOR           9 /* Enable Output Buffer threshold flag HIGH-to-LOW transition event*/
#define DA_BUF_THR_DOWN_EVENT                   25 /* Output Buffer threshold flag HIGH-to-LOW transition */
#define DA_BUF_THR_UP_EVENT_SELECTOR            10 /* Enable Output Buffer threshold flag LOW-to-HIGH transition event */
#define DA_BUF_THR_UP_EVENT                     26 /* Output Buffer threshold flag LOW-to-HIGH transition event */
#define DA_LOAD_READY_FLAG_DOWN_EVENT_SELECTOR  11 /* Enable Output Load-Ready Flag HIGH-to-LOW transition event */
#define DA_LOAD_READY_FLAG_DOWN_EVENT           27 /* Output Load-Ready Flag HIGH-to-LOW transition event */
#define DA_LOAD_READY_FLAG_UP_EVENT_SELECTOR    12 /* Enable Output Load-Ready Flag LOW-to-HIGH transition event */
#define DA_LOAD_READY_FLAG_UP_EVENT             28 /* Output Load-Ready Flag LOW-to-HIGH transition event */
#define DA_BURST_READY_EVENT_SELECTOR           13 /* Enable Analog Output Burst Ready event */
#define DA_BURST_READY_EVENT                    29 /* Analog Output Burst Ready event */
#define DA_BUF_OR_FRAME_OVERFLOW_EVENT_SELECTOR 14 /* Enable Output Buffer Overflow or Frame Overflow event */
#define DA_BUF_OR_FRAME_OVERFLOW_EVENT          30 /* Output Buffer Overflow or Frame Overflow event */

// IO104->outputBufThreshold
#define OUTPUT_BUFFER_THRESHOLD_MASK    0x0003ffff /* Specifies the number of values in the output buffer, above which the threshold flag is asserted HIGH. */
#define OUTPUT_BUFFER_THRESHOLD_FLAG            19 /* HIGH when the number of values in the output buffer exceeds the specified buffer threshold. */

// input buffer flags
#define AD_FIRST_CHANNEL_FLAG                   16 /* Tag assigned to first (lowest-numbered) active channel. */
#define AD_END_OF_BURST_FLAG                    17 /* Identifies the last input value in a burst. */

// output buffer flags
#define DA_END_OF_FRAME_FLAG                    16 /* HIGH to indicate the last value in a data frame */

// divider limits
#define AD_MIN_CLK_DIV 20          // minimum clock divider value for analog inputs
#define AD_MAX_CLK_DIV ((1<<24)-1) // maximum clock divider value for analog inputs
#define DA_MIN_CLK_DIV 40          // minimum clock divider value for analog outputs
#define DA_MAX_CLK_DIV ((1<<24)-1) // maximum clock divider value for analog outputs
#define BT_MIN_CLK_DIV 400         // minimum clock divider value for the burst trigger (this value is artificial. smaller values are not realistic on current xpc target machines)
#define BT_MAX_CLK_DIV ((1<<24)-1) // maximum clock divider value for the burst trigger 

/* PLX PCI bridge DMA register access structure */
typedef volatile struct plxdma_tag { // at BAR[0] + 0x80
    volatile uint32_T  dma0mode;  // 0x80 DMAMODE0 DMA channel 0 Mode
    volatile uint32_T* dma0addr;  // 0x84 DMAPADR0 DMA channel 0 PCI Address
    volatile uint32_T  dma0local; // 0x88 DMALADR0 DMA channel 0 Local Address
    volatile uint32_T  dma0bcnt;  // 0x8C DMASIZ0  DMA channel 0 Transfer Size (Bytes)
    volatile uint32_T  dma0descr; // 0x90 DMADPR0  DMA channel 0 Descriptor Pointer
    volatile uint32_T  dma1mode;  // 0x94 DMAMODE1 DMA channel 1 Mode
    volatile uint32_T* dma1addr;  // 0x98 DMAPADR1 DMA channel 1 PCI Address 
    volatile uint32_T  dma1local; // 0x9C DMALADR1 DMA channel 1 Local Address 
    volatile uint32_T  dma1bcnt;  // 0xA0 DMASIZ1  DMA channel 1 Transfer Size (Bytes) 
    volatile uint32_T  dma1descr; // 0xA4 DMADPR1  DMA channel 1 Descriptor Pointer 
    volatile uint8_T   dma0csr;   // 0xA8 DMACSR0
    volatile uint8_T   dma1csr;   // 0xA9 DMACSR1
    volatile uint16_T  d1;        // 0xAA
    volatile uint32_T  dmaarb;    // 0xAC
    volatile uint32_T  dmathresh; // 0xB0
    volatile uint32_T  dma0dac;   // 0xB4 DMADAC0  DMA channel 0 PCI dual address cycles upper address
    volatile uint32_T  dma1dac;   // 0xB8 DMADAC1  DMA channel 1 PCI dual address cycles upper address
}PlxDma_T;

// dma0mode, dma1mode
#define DMA_MODE_BUS_WIDTH        0 // RW 2 bit: set 2 or 3 for 32-bit bus
#define DMA_MODE_WAIT_STATES      2 // RW 4 bit: Internal wait state counter
#define DMA_MODE_TA_READY_EN      6 // RW DMA channel enable TA/READY input pin
#define DMA_MODE_CONTIN_BURST_EN  7 // RW DMA channel continuous burst enable
#define DMA_MODE_LOCAL_BURST_EN   8 // RW DMA channel local burst enable
#define DMA_MODE_SCATTER_GATHER   9 // RW DMA channel scatter/gather mode
#define DMA_MODE_DONE_INT_EN     10 // RW DMA channel DONE interrupt enable
#define DMA_MODE_LOC_ADDR_CONST  11 // RW DMA channel local addressing mode
#define DMA_MODE_DEMAND_MODE     12 // RW DMA channel demand mode
#define DMA_MODE_MEM_INVALIDATE  13 // RW DMA channel memory write and invalidate mode
#define DMA_MODE_EOT_PIN_EN      14 // RW DMA channel enable EOT# input pin
#define DMA_MODE_FAST_TERMINATE  15 // RW DMA channel set fast terminate mode
#define DMA_MODE_SG_CLEAR_COUNT  16 // RW DMA channel clear byte count in scatter/gather descriptor
#define DMA_MODE_INT_TO_PCI      17 // RW DMA channel interrupt is routed to PCI INTA#
#define DMA_MODE_DAC_CHAIN_LOAD  18 // RW DMA channel descriptor loads 1: PCI dual cycle addr, 0: DMADACx
#define DMA_MODE_SG_EOT_END_LINK 19 // RW DMA channel scatter/gather stuff
#define DMA_MODE_RING_VALID_EN   20 // RW DMA channel use ring management valid bit DMASIZx[31]
#define DMA_MODE_RING_STOP_EN    21 // RW DMA channel scatter/gather ring management stop stuff

// dma0descr, dma1descr (DMADPRx)
#define DMA_DESC_LOCATION_PCI     0
#define DMA_DESC_END_OF_CHAIN     1
#define DMA_DESC_INT_AFTER_TERM   2
#define DMA_DESC_DIR_LOC2PCI      3

// dma0csr, dma1csr
#define DMA_CSR_ENABLE_CHANNEL  0 // RW 1: enable channel to transfer data, 0: disable transfer and suspend if already running
#define DMA_CSR_START_TRANSFER  1 // So
#define DMA_CSR_ABORT_TRANSFER  2 // So
#define DMA_CSR_CLEAR_INTERRUPT 3 // Co Writing '1' clears channel interrupt
#define DMA_CSR_TRANSFER_DONE   4 // Ro Either all data transferred or xfer abort


typedef volatile struct PlxInt_tag 
{ 
    volatile uint32_T intcsr;
    volatile uint32_T cntrl;
} PlxInt_T;    

#define INTCSR_LOCAL_DATA_PARITY_CHECK_ERROR 7
#define INTCSR_PCI_INT_ENABLE      8 // INTA#
#define INTCSR_DMA_CH0_INT_ENABLE 18 // enable the channel 0 interrupt, cleared by DMA_CSR_CLEAR_INTERRUPT
#define INTCSR_DMA_CH0_INT_ACTIVE 21 // PCI_9056BA p325
#define INTCSR_DMA_CH1_INT_ACTIVE 22

//--------------------------------------------------------------------------------------------

// some definitions for mask-argument interpretation
#define DIGITAL_INPUT  1
#define DIGITAL_OUTPUT 2
#define DIGITAL_DIR_INPUTS 1
#define INITIATOR 1
#define TARGET 0
#define DIFFERENTIAL 1
#define CHECKBOX_ON 1

//#endif 

////////////////////////////////////////////////////////////////////////////////////
//#include "sg_IO104_DMA.h"   END OF INCLUDE FILE
////////////////////////////////////////////////////////////////////////////////////



int  __cdecl xpcio104dmaprehook(xpcPCIDevice *pPciDev);
void __cdecl xpcio104dmaposthook(xpcPCIDevice *pPciDev); // currently disabled in xpcIO104_dma_int.m
void __cdecl xpcio104dmastart(xpcPCIDevice *pPciDev);
void __cdecl xpcio104dmastop(xpcPCIDevice *pPciDev);

/** just for debugging. sets d-byte 0 as output, bit: 0..7 */
#ifdef USE_DIGITAL_OUTPUTS_FOR_DEBUGGING
static void set_digital_output(IO104_T* pIO104, uint32_T bit, uint32_T value);
static void set_digital_output(IO104_T* pIO104, uint32_T bit, uint32_T value)  
{
#ifndef MATLAB_MEX_FILE
    uint32_T reg;

    if(!pIO104)
    {
        printf("setDO: pIO104 is NULL\n");
        return;
    }
    if((bit > 7) || (value > 1))
    {
        printf("setDO: bad param\n");
        return;
    }
    reg = pIO104->dio;
    
    if(value)
        reg |= (1 << bit);
    else
        reg &= ~(1 << bit);
    
    reg |= (DIO_OUTPUT << DIO_BYTE_0_DIR);
    pIO104->dio = reg;
#endif
}

/** just for debugging. toggles a bit: 0..7 */
static void toggle_digital_output(IO104_T* pIO104, uint32_T bit);
static void toggle_digital_output(IO104_T* pIO104, uint32_T bit)
{
#ifndef MATLAB_MEX_FILE
    uint32_T reg;
    
    if(!pIO104)
    {
        printf("tglDO: pIO104 is NULL\n");
        return;
    }
    if((bit > 7))
    {
        printf("tglDO: bad param\n");
        return;
    }
    reg = pIO104->dio;
    
    if( reg &   (1 << bit))
        reg &= ~(1 << bit);
    else
        reg |=  (1 << bit);
    
    reg |= (DIO_OUTPUT << DIO_BYTE_0_DIR);
    pIO104->dio = reg;
#endif
}

#else
#define toggle_digital_output(pIO104, bit) {}
#define set_digital_output(pIO104, bit, value) {}
#endif

static void dump_card_registers(IO104_T* pIO104);
static void dump_card_registers(IO104_T* pIO104)
{
    printf("bcr                0x%08x\n", pIO104->bcr                );
    printf("dio                0x%08x\n", pIO104->dio                );
    printf("analogOutCh[0]     0x%08x\n", pIO104->analogOutCh[0]     );
    printf("analogOutCh[1]     0x%08x\n", pIO104->analogOutCh[1]     );
    printf("analogOutCh[2]     0x%08x\n", pIO104->analogOutCh[2]     );
    printf("analogOutCh[3]     0x%08x\n", pIO104->analogOutCh[3]     );
    printf("analogInBuf        0x%08x\n", pIO104->analogInBuf        );
    printf("inputClkDiv        0x%08x\n", pIO104->inputClkDiv        );
    printf("burstClkDiv        0x%08x\n", pIO104->burstClkDiv        );
    printf("inputConfig        0x%08x\n", pIO104->inputConfig        );
    printf("inputBufSize       0x%08x\n", pIO104->inputBufSize       );
    printf("inputBufThreshold  0x%08x\n", pIO104->inputBufThreshold  );
    printf("primaryStatus      0x%08x\n", pIO104->primaryStatus      );
    printf("assemblyConfig     0x%08x\n", pIO104->assemblyConfig     );
    printf("autoCalValues      0x%08x\n", pIO104->autoCalValues      );
    printf("bor                0x%08x\n", pIO104->bor                );
    printf("outputBufThreshold 0x%08x\n", pIO104->outputBufThreshold );
    printf("outputBufSize      0x%08x\n", pIO104->outputBufSize      );
    printf("analogOutBuf       0x%08x\n", pIO104->analogOutBuf       );
    printf("outputClkDiv       0x%08x\n", pIO104->outputClkDiv       );
    printf("auxUser[0]         0x%08x\n", pIO104->auxUser[0]         );
    printf("auxUser[1]         0x%08x\n", pIO104->auxUser[1]         );
    printf("auxUser[2]         0x%08x\n", pIO104->auxUser[2]         );
    printf("auxUser[3]         0x%08x\n", pIO104->auxUser[3]         );

}

static void dump_dma_registers(xpcPCIDevice *pPciDev);
static void dump_dma_registers(xpcPCIDevice *pPciDev)
{
    PlxDma_T* pPlxDma = (PlxDma_T*)(pPciDev->VirtAddress[0] + 0x80);
    PlxInt_T* pPlxInt = (PlxInt_T*)(pPciDev->VirtAddress[0] + 0x68); 
    
    printf("0x%08x 0x%08x 0x%02x\n", pPlxInt->intcsr, pPlxDma->dma0mode, pPlxDma->dma0csr);
}

/** Runs as the last item when starting a model, just before the model runs. 
    It is typically used to turn on interrupt generation. Program this function 
    to enable interrupts on the board and start any action. */
void __cdecl xpcio104dmastart(xpcPCIDevice *pPciDev)
{
    PlxDma_T* pPlxDma;
    PlxInt_T* pPlxInt;
    IO104_T* pIO104;
    uint32_T intcsr, dma0descr, bcr;
    
    pPciDev->VirtAddress[0] = (unsigned long)xpcReserveMemoryRegion( (void *)pPciDev->BaseAddress[0], 4096, XPC_RT_PG_USERREADWRITE );
    pPciDev->VirtAddress[2] = (unsigned long)xpcReserveMemoryRegion( (void *)pPciDev->BaseAddress[2], 4096, XPC_RT_PG_USERREADWRITE );
    
    pPlxDma = (PlxDma_T*)(pPciDev->VirtAddress[0] + 0x80);
    pPlxInt = (PlxInt_T*)(pPciDev->VirtAddress[0] + 0x68); 
    pIO104 = (IO104_T*) (pPciDev->VirtAddress[2]);
    
    #ifdef DEBUG_PRINT_FUNCTION_CALLS
    printf("INT.Start (%sinit)\n",(xpceIsModelInit())?"":"non-");
    #endif
    
    //dump_card_registers(pIO104);
   
    set_digital_output(pIO104, 4, 0); // if USE_DIGITAL_OUTPUTS_FOR_DEBUGGING is defined
    
    if (!xpceIsModelInit()) 
    {
        intcsr = pPlxInt->intcsr & 0xffffff00; // Channnel 1 is configured in the same register, so be careful
        
        dma0descr = pPlxDma->dma0descr;
        bcr = pIO104->bcr;
        
        #ifdef DEBUG_PRINTF
        printf("DMA Start: Interrupts enabled (0x%08X)\n", pPlxInt->intcsr);
        #endif

        // Section moved to setup block for Target-mode support (not sure if this produces problems in other use cases)
        /*
        pPlxDma->dma0csr  = (1 << DMA_CSR_CLEAR_INTERRUPT);
        pPlxDma->dma0csr  = 0;
        pPlxDma->dma0csr  = (1 << DMA_CSR_ENABLE_CHANNEL);
        pPlxDma->dma0csr  = (1 << DMA_CSR_ENABLE_CHANNEL) | (1 << DMA_CSR_START_TRANSFER);
        */
        
        //rl32eWaitDouble(0.1);
        pPlxInt->intcsr   = intcsr | ((1 << INTCSR_DMA_CH0_INT_ENABLE) | ( 1 << INTCSR_PCI_INT_ENABLE));
        pIO104->bcr = bcr | (1<< ENABLE_RATE_C_GENERATOR) | (1<< ENABLE_RATE_B_GENERATOR) | (1<< ENABLE_RATE_A_GENERATOR); 
        
    }
    return;
}


/** Runs just before either a function-call subsystem or entire model is called. 
    Program this function to acknowledge the interrupt and cause the board to 
    stop issuing the interrupt signal. Interrupts are disabled here. */
int __cdecl xpcio104dmaprehook(xpcPCIDevice *pPciDev)
{
    PlxDma_T* pPlxDma;
    PlxInt_T* pPlxInt;
    uint32_T  intcsr;
//    uint32_T dma0mode;
    uint32_T dma0csr;
    
    #ifdef USE_DIGITAL_OUTPUTS_FOR_DEBUGGING
    IO104_T*  pIO104  = (IO104_T*) (pPciDev->VirtAddress[2]);
    //set_digital_output(pIO104, 4, 1);
    #endif

    pPlxDma = (PlxDma_T*)(pPciDev->VirtAddress[0] + 0x80);
    pPlxInt = (PlxInt_T*)(pPciDev->VirtAddress[0] + 0x68); 
    
    intcsr  = pPlxInt->intcsr;
//    dma0mode = pPlxDma->dma0mode;
    dma0csr  = pPlxDma->dma0csr;

    if( 1 // no need to check all this, but it works
//    && (intcsr   & (1 << INTCSR_PCI_INT_ENABLE))     // are PCI interrupts enabled?
//    && (intcsr   & (1 << INTCSR_DMA_CH0_INT_ENABLE)) // is the channel 0 interrupt enabled?
    && (intcsr   & (1 << INTCSR_DMA_CH0_INT_ACTIVE)) // is the channel 0 interrupt active? 
//    && (dma0csr  & (1 << DMA_CSR_ENABLE_CHANNEL))    // is DMA channel 0 enabled?
//    && (dma0mode & (1 << DMA_MODE_DONE_INT_EN  ))    // is the DMA DONE interrupt enabled?
    && (dma0csr  & (1 << DMA_CSR_TRANSFER_DONE ))    // is the DMA DONE interrupt active?
      )
    {
        set_digital_output(pIO104, 4, 1);
        pPlxDma->dma0csr = (1 << DMA_CSR_CLEAR_INTERRUPT);
        pPlxDma->dma0csr =  0;
        // IMPORTANT: enable and start DMA only AFTER reading.
        // optionally ping-pong-buffers could be used.
        
        #ifdef DEBUG_PRINTF
        printf("i\n");
        #endif
        set_digital_output(pIO104, 4, 0);
        return XPC_RUN_ISR;
    }
    set_digital_output(pIO104, 4, 0);
    return XPC_DROP_ISR;
}

/** Runs after return from function call on interrupt, and BEFORE model execution. 
    It is typically not used. */
void __cdecl xpcio104dmaposthook(xpcPCIDevice *pPciDev)
{
}

/** Runs at the beginning of a stop request, before any mdlTerminate entries 
    for any block in the model runs. It is typically used to turn off interrupt 
    generation. Program this function to disable interrupts from the board and 
    stop any action. This is the first action called, when a target application 
    stops executing. */
void __cdecl xpcio104dmastop(xpcPCIDevice *pPciDev)
{
    PlxDma_T* pPlxDma = (PlxDma_T*)(pPciDev->VirtAddress[0] + 0x80);
    PlxInt_T* pPlxInt = (PlxInt_T*)(pPciDev->VirtAddress[0] + 0x68);
    IO104_T*  pIO104  = (IO104_T*) (pPciDev->VirtAddress[2]);
    uint32_T bcr;
    
    #ifdef DEBUG_PRINT_FUNCTION_CALLS
    printf("INT.Stop (%sinit)\n",(xpceIsModelInit())?"":"non-");
    #endif
    
    toggle_digital_output(pIO104, 4);
    
    /* Stop all rate generators */
    if (!xpceIsModelInit()) 
    {
        bcr = pIO104->bcr;    
        bcr &= ~(
                 (1 << ENABLE_RATE_B_GENERATOR)
               | (1 << ENABLE_RATE_A_GENERATOR)
               | (1 << ENABLE_RATE_C_GENERATOR));
        pIO104->bcr = bcr;
        pPlxDma->dma0csr  = (1 << DMA_CSR_ABORT_TRANSFER);
        pPlxDma->dma1csr  = (1 << DMA_CSR_ABORT_TRANSFER);
        pPlxDma->dma0csr  = 0;
        pPlxDma->dma1csr  = 0;
        pPlxDma->dma0mode = 0;
        pPlxInt->intcsr   = 0;

        #ifdef DEBUG_PRINTF
        printf("DMA Stop: Interrupts disabled (0x%08X)\n", pPlxInt->intcsr);
        #endif
    }        
    return;
}

#endif
