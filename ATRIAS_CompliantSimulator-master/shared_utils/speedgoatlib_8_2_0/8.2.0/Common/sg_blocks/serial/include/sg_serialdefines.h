
/* $Revision: 1.1.6.3 $ $Date: 2006/11/15 15:12:40 $ */
/* quatechdefines.h - xPC Target, board specific defines used by
 *                    multiple blocks for the Quatech boards
 */
/* Copyright 1996-2006 The MathWorks, Inc.
*/


// First, with DLAB bit in LCR set to 0
// These are all offsets in IO space from the base address of
// the chosen UART.
#define DATA      0  // receive buffer on read, tx on write
#define IER       1  // Interrupt enable (read/write)
#define IIR       2  // Interrupt Ident (read only)
#define FCR       2  // FIFO control register (write only)
#define LCR       3  // Line control register (read/write)
#define MCR       4  // Moden control register (read/write)
#define LSR       5  // Line status register (read/write)
#define MSR       6  // Modem status register (read/write)
#define GISTAT    7  // Global interrupt status, all UARTS (read only)(Quatech)

// Now, with DLAB bit in LCR set to 1
#define DLSB      0  // LSB of baud rate divisor (read/write)
#define DMSB      1  // MSB of the board rate divisor (read/write)
#define OPTIONS   7  // Options register (Quatech)

// Bit definitions for the registers
// IER register
#define IERRCV     0x01  // Receive data available interrupt
#define IERXMT     0x02  // Transmitter holding register empty
#define IERLS      0x04  // Receiver line status interrupt
#define IERMS      0x08  // Modem status interrupt
#define IERSLEEP   0x10  // Sleep mode enable
#define IERPOWER   0x20  // Low power mode enable
// IER in XR17D152 and 154 (Commtech 422/(2,4)-335)
#define IERXOFF    0x20  // 1 to enable auto XON/XOFF
#define IERHWFLOW  0xC0  // Both 1 to enable auto RTS/CTS or DSR/DTR

// IIR register
#define IIRREASON  0x0f  // Mask for the 4 reason bits
#define IIR64      0x20  // Is the board in 64 byte FIFO mode?
#define IIRFEBL    0xc0  // FIFO mode enabled
// IIR in XR17D152 IIR == ISR
#define IIRXOFF    0x10  // XOFF has been received
#define IIRHWFLOW  0x20  // delta HW flow control

// FCR register
#define FCREBL     0x01  // Enable the FIFOs
#define FCRRCLR    0x02  // Clear the receive FIFO
#define FCRTCLR    0x04  // Clear the transmit FIFO
#define FCRDMA     0x08  // Enable DMA mode if FCREBL is set
#define FCR64      0x20  // Set for 64 byte FIFO, clear for 16 byte FIFO
#define FCRONE     0x00  // Interrupt with one byte in FIFO
#define FCRQUARTER 0x40  // Interrupt when quarter full
#define FCRHALF    0x80  // interrupt when the FIFO is half full
#define FCRFULL    0xc0  // Interrupt when almost full FIFO
// FCR in XR17D152
#define FCRTX      0x30  // Transmit fifo interrupt level

// LCR register
#define LCR5BIT    0x00  // 5 bit chars
#define LCR6BIT    0x01
#define LCR7BIT    0x02
#define LCR8BIT    0x03  // 8 bit chars
#define LCRSTOP    0x04  // Set for long (doubled) stop bit
#define LCRPARITY  0x08  // Set to enable parity checking
#define LCREVEN    0x10  // Set for even parity, clear for odd if STICK is clear
#define LCRSTICK   0x20  // with STICK set, if LCREVEN is set -> space parity
                         //                             clear -> mark parity
#define LCRBREAK   0x40  // Set to send break
#define LCRDLAB    0x80  // Divisor Latch Access Bit, DLAB

// MCR register
#define MCRDTR     0x01  // Set to force DTR HIGH
#define MCRRTS     0x02  // Set to force RTS HIGH
#define MCROUT1    0x04  // Set to force OUT1 HIGH (not wired)
#define MCROUT2    0x08  // Set to force OUT2 HIGH (not wired)
#define MCRLOOP    0x10  // Loopback (diagnostic) mode
#define MCRAFE     0x20  // Automatic RTS/CTS
// MCR in XR17D152
#define MCRDTRFLOW 0x04  // Set to choose DTR/DSR, clear for RTS/CTS flow ctrl
#define MCRXONANY  0x20  // Set for any character serves as XON
#define MCRIR      0x40  // Set for the IR decoder, we don't use this
#define MCRPRE     0x80  // Set for 1/4 prescale of master frequency

// LSR register
#define LSRDR      0x01  // Data ready
#define LSROE      0x02  // Overrun error
#define LSRPE      0x04  // Parity error
#define LSRFE      0x08  // Framing error
#define LSRBI      0x10  // Break indicator
#define LSRTHRE    0x20  // Transmitter Holding Register empty
#define LSRTEMT    0x40  // Transmitter empty
#define LSRERR     0x80  // a byte with an error is in the fifo

// MSR register
#define MSRDCTS    0x01  // CTS changed since last read
#define MSRDDSR    0x02  // DSR changed since last read
#define MSRTERI    0x04  // Trailing edge Ring Indicator
#define MSRDDCD    0x08  // DCD changed since last read
#define MSRCTS     0x10  // set when external CTS is low
#define MSRDSR     0x20  // set when external DSR is low
#define MSRRI      0x40  // set when external RI is low
#define MSRDCD     0x80  // set when external DCD is low

// GISTAT register
// port1 pending = 0x01, port2 = 0x02, etc.

// OPTIONS register, Quatech boards only
#define OPTX8      0x03  // Use x8 clock multiplier
#define OPTX4      0x02
#define OPTX2      0x01
#define OPTX1      0x00

// DLSB and DMSB registers get the divisor

// Divisors with the 8x clock source
// Use as is for the 750 UART, but divide by 4 and use OPTX2 for the 550.
// These are also the standard dividers for the Commtech 422/(2,4)-335 boards.
static divisors[14] =
{
        1,   // 921600
        2,   // 460800
        4,   // 230400
        8,   // 115200
       16,   // 57600
       24,   // 38400
       48,   // 19200
       96,   // 9600
      192,   // 4800
      384,   // 2400
      768,   // 1200
     1536,   // 600
     3072,   // 300
     8378,   // 110
};

// Baseboard UART drivers have 115200 max baud rate
static basedivisors[14] =
{
        1,   // 115200
        2,   // 57600
        3,   // 38400
        6,   // 19200
       12,   // 9600
       24,   // 4800
       48,   // 2400
       96,   // 1200
      192,   // 600
      384,   // 300
     1047,   // 110
};

// The Emerald MM comes with two different possible crystals.  The low
// speed crystal is 16*115200 = 1.8432 Mhz while the high speed (HS)
// board has a 7.3728 Mhz crystal.  To get all the standard baud rates,
// several 'extra' rates are inserted on each side.
static emeraldmmdivisors[] =
{
    1,      // 115200  (HS 460800)
    2,      // 57600   (HS 230400)
    3,      // 38400   (HS 153600)
    4,      // 28800   (HS 115200)
    6,      // 19200   (HS 76800)
    8,      // 14400   (HS 57600)
    12,     // 9600    (HS 38400)
    24,     // 4800    (HS 19200)
    48,     // 2400    (HS 9600)
    96,     // 1200    (HS 4800)
    192,    // 600     (HS 2400)
    384,    // 300     (HS 1200)
    768,    // 150     (HS 600)
    1047,   // 110     (HS 440)
    1536,   // 75      (HS 300)
    4188    // 27.5    (HS 110)
};


#define UART750        3
#define UART550        2
#define UART450        1

// The Commtech 422/2-PCI-335 uses the XR17D152 and the 422/4-PCI-335
// uses the XR17D154.  Both use memory mapped access to the UART.  This
// structure can be used to access the registers for each UART.

struct uartregs {
    volatile unsigned char data;
    volatile unsigned char ier;
    volatile unsigned char isr;
    volatile unsigned char lcr;
    volatile unsigned char mcr;
    volatile unsigned char lsr;
    volatile unsigned char msr;
    volatile unsigned char spr;
    volatile unsigned char fctr;
    volatile unsigned char efr;
    volatile unsigned char txfifolevel;
    volatile unsigned char rxfifolevel;
    volatile unsigned char xoff1;
    volatile unsigned char xoff2;
    volatile unsigned char xon1;
    volatile unsigned char xon2;
};

// The TX wide fifo port is at offset 0x100 from the channel base
#define TXFIFOOFFSET  0x100

// MSR upper 4 bits are the RS485 turnaround delay, write only
#define MSRDLY  0xf0;

// FCTR  Feature control register
#define FCTRHYST      0x0f
#define FCTRIRINVERT  0x10
#define FCTRAUTO485   0x20
#define FCTRTRIG      0xc0

// EFR Enhanced Function register
#define EFRRXFLOW     0x02  // compare with XON1, XOFF1
#define EFRTXFLOW     0x08  // transmit XON1, XOFF1
#define EFRENABLE     0x10
#define EFRCHAR       0x20
#define EFRHWFLOW     0xc0

// three registers fall on top of others, multiple uses
#define dll data
#define dlm ier
#define fcr isr

struct uartconfig {
    volatile unsigned int   intstat;

    volatile unsigned char  timerctl;
    volatile unsigned char  timer;
    volatile unsigned char  timerlsb;
    volatile unsigned char  timermsb;

    volatile unsigned char  mode8x;
    volatile unsigned char  rega;
    volatile unsigned char  reset;
    volatile unsigned char  sleep;

    volatile unsigned char  revision;
    volatile unsigned char  ident;
    volatile unsigned char  regb;
    volatile unsigned char  mpioint;

    volatile unsigned char  mpiolvl;
    volatile unsigned char  mpio3t;
    volatile unsigned char  mpioinv;
    volatile unsigned char  mpiosel;
};

// uartconfig is at base + 0x80
#define UARTCONFIGOFFSET  0x80

// uart channel N is at base + N*0x200, N = [0,3]
#define UARTCHANOFFSET    0x200
