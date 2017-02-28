#ifndef __SG_VME_ZMI4104_C__
#define __SG_VME_ZMI4104_C__

#include <math.h>
#include "sg_vme_zmi4104.h"
//#define SG_DEBUG

volatile uint8_T zmiRead8(ZMI4104TYPE* ptBaseReg, uint16_T offset)
{
    volatile uint8_T* ptTempReg = (volatile uint8_T*)ptBaseReg;
    
    return ptTempReg[offset];
}

volatile uint16_T zmiRead16(ZMI4104TYPE* ptBaseReg, uint16_T offset)
{
    volatile uint16_T* ptTempReg = (volatile uint16_T*)ptBaseReg;
    
    return (ptTempReg[offset/2]);
}

volatile uint32_T zmiRead32(ZMI4104TYPE* ptBaseReg, uint16_T offset)
{
    volatile uint32_T* ptTempReg = (volatile uint32_T*)ptBaseReg;
    
	uint32_T v = ptTempReg[offset/4];
	
    return (v << 16) | (v >> 16);
}

void zmiWrite8(ZMI4104TYPE* ptBaseReg, uint16_T offset, uint8_T data)
{
    volatile uint8_T* ptTempReg = (volatile uint8_T*)ptBaseReg;
    
    ptTempReg[offset] = data;
}

void zmiWrite16(ZMI4104TYPE* ptBaseReg, uint16_T offset, uint16_T data)
{
    volatile uint16_T* ptTempReg = (volatile uint16_T*)ptBaseReg;
    ptTempReg[offset/2] = data;
}

void zmiWrite32(ZMI4104TYPE* ptBaseReg, uint16_T offset, uint32_T data)
{
    volatile uint32_T* ptTempReg = (volatile uint32_T*)ptBaseReg;
	
    ptTempReg[offset/4] = (data << 16) | (data >> 16);
}

/**************************************************************************
 * Function: VmeBusInit
 * arg 1, SimStruct *S : Simulink structure
 * arg 2, BAR1TYPE *nodeio_bar: pointer to the Command and Status Register
 *                              BAR
 * return: 0 if success, 1 if error
 * Description: Initialize Vme Bus through Bus Adapter card
 * 
 * Modifications 
 * +-------------+----------------------------------------------+--------+
 * | Date        | Comments                                     | Author |
 * +-------------+----------------------------------------------+--------+
 * | 18-Oct-2012 | First version                                | DK     |
 * +-------------+----------------------------------------------+--------+
 *
 *************************************************************************/

int VmeBusInit(SimStruct *S, BAR1TYPE * nodeio_bar, char msg[])
{
    volatile uint8_T tempByte = 0x00;
    
    if ((nodeio_bar[VME_NODE_LOCAL_STATUS] & 0x01) == 0)   // Read Local Status register bit 0
    {
        tempByte = 0x00; // clear

        tempByte = nodeio_bar[VME_NODE_REMOTE_STATUS_REG]; // Read Remote Status register

        tempByte = 0x00; // clear

        nodeio_bar[VME_NODE_LOCAL_COMMAND] |= 0x80;        // Set bit 7 of Local Command register

        nodeio_bar[VME_NODE_REMOTE_COMMAND_REG_1] &= ~0x80;   // Reset VME bus
        xpcBusyWait(1);
        
        #ifdef SG_DEBUG
        printf("Remote Status Register = 0x%x \n", nodeio_bar[VME_NODE_REMOTE_STATUS_REG]);
        #endif
                
        tempByte = nodeio_bar[VME_NODE_LOCAL_STATUS];      // Read Local Status register

        tempByte = nodeio_bar[VME_NODE_LOCAL_STATUS];      // Read Local Status register

        return VmeBusStatus(S, nodeio_bar);
    }
    else
    {
//         sprintf(msg,"%s: initializazion failed\n", DEVNAME);
//         ssSetErrorStatus(S,msg);
        return 1;
    }   
}

/**************************************************************************
 * Function: VmeBusStatus
 * arg 1, SimStruct *S: Simulink Structure
 * arg 2, BAR1TYPE * nodeio_bar: pointer to the CSR
 * arg 3, char msg[]: return error message
 * return: 0 if success, or error code
 * Description: Check the connection with the VME bus.
 * 
 * Modifications 
 * +-------------+----------------------------------------------+--------+
 * | Date        | Comments                                     | Author |
 * +-------------+----------------------------------------------+--------+
 * | 19-Oct-2012 | First version                                | DK     |
 * +-------------+----------------------------------------------+--------+
 * | 10-Dec-2012 | Error messages removed                       | DK     |
 * +-------------+----------------------------------------------+--------+
 *
 *************************************************************************/

uint8_T VmeBusStatus (SimStruct *S, BAR1TYPE * nodeio_bar)
{
    volatile uint8_T tempByte = 0x00;
    
    tempByte = nodeio_bar[VME_NODE_LOCAL_STATUS];      // Read Local Status register
    
    if ((tempByte & 0x80) == 0x80)
    {
        // Fiber optic interface error

        return 1;
    }
    else if ((tempByte & 0x40) == 0x40)
    {
        // Remote bus error

        return 2;
    }
    else if ((tempByte & 0x04) == 0x04)
    {
        // Interface timeout

        return 3;
    }
    else if ((tempByte & 0x01) == 0x01)
    {
        // Remote bus power off or cable not connected

        return 4;
    }
    return 0;
}

/**************************************************************************
 * Function: VmeBusInit
 * arg 1, int_T id: id of the card to map (1 or 2)
 * arg 2, uint32_T *mappingreg_bar: pointer to Mapping Register BAR
 * arg 3, int_T addr_sw1: Code of SW1
 * arg 4, int_T addr_sw2: Code of SW2
 * return: 0 if success
 * Description: Mapping of the ZMI card(s) on the Bus Adapter. After the
 *              call of this functions, the Remote windows registers are
 *              mapped with the ZMI card(s) registers.
 * 
 * Modifications 
 * +-------------+----------------------------------------------+--------+
 * | Date        | Comments                                     | Author |
 * +-------------+----------------------------------------------+--------+
 * | 18-Oct-2012 | First version                                | DK     |
 * +-------------+----------------------------------------------+--------+
 *
 *************************************************************************/

int VmeZmiMapping(int_T id, volatile uint32_T *mappingreg_bar, int_T addr_sw1, int_T addr_sw2)
{
    uint8_T i;
    uint32_T lword;
    printf("Zygo ZMI4104C Card %i mapping\n", id);
    
    for (i = 0; i < 4; i++)     // for each axis
    {
        #ifdef SG_DEBUG
        printf("Zygo ZMI4104C Card %i, mapping axis %i\n",id, i+1);
        #endif
                
        lword = 0x00000000;

        lword |= (0x00004 << 12);       //A31-A12
        lword |= (addr_sw1 << 20);      // A20-A23
        lword |= (addr_sw2 << 16);      // A16-A19
        lword |= i << 12;               // Axis #
        lword |= (0x3D << 6);           // Address Modifier
        lword |= (0x2 << 4);            // Function code
        lword |= (0x0 << 1);            // Data swapping
        
        if (id == 1)
        {
            mappingreg_bar[i] = lword;
            
            #ifdef SG_DEBUG
            printf("Mapping register 0x%x = 0x%08x \n", i, mappingreg_bar[i]);
            #endif
        }
        else if (id == 2)
        {
            mappingreg_bar[i+4] = lword;
            
            #ifdef SG_DEBUG
            printf("Mapping register 0x%x = 0x%08x \n", i+4, mappingreg_bar[i+4]);
            #endif
        }
    }

    xpcBusyWait(3); // Wait configuration (don't delete this delay!)
    
    return 0;
}

/* Axis init *************************************************************/
int VmeZmiAxisInit(ZMI4104TYPE* ptZmiRegs, int axis)
{
    volatile uint16_T tempData16;
    
    zmiWrite32(ptZmiRegs, ZMI_VME_ERROR_CLEAR0, 0xFFFFFFFF);
    
    zmiWrite16(ptZmiRegs, ZMI_VME_COMMAND_REGISTER, 0x3F);
    
    tempData16 = zmiRead16(ptZmiRegs, ZMI_VME_CONTROL_REGISTER_2);
    
    tempData16 &= 0xFF1F;
    tempData16 |= ZMI4000_VME_BIT_WINDOW << 5;
    tempData16 |= 0x0200;
    tempData16 &= 0xE7FF;
    tempData16 |= (1 << 4);
    
    zmiWrite16(ptZmiRegs, ZMI_VME_CONTROL_REGISTER_2, tempData16);
    
    if (axis == 1)
    {
        zmiWrite16(ptZmiRegs, ZMI_VME_SCLK_COMMAND_REGISTER, 0x1);
    }
    
    if (axis % 2)   // Axis 1 or 3
    {
        zmiWrite16(ptZmiRegs, ZMI_VME_CONTROL_REGISTER_16, 0x0023);
        zmiWrite16(ptZmiRegs, ZMI_VME_CONTROL_REGISTER_17, 0x0C00);
    }
}

int VmeZmiAxisInit_intTriggerModeForceExtSample(ZMI4104TYPE* ptZmiRegs, int axis)
{
    volatile uint16_T Data = 0x0000;
   
    // uninstall Interrupt handle here ...
    
    zmiWrite16(ptZmiRegs, ZMI_VME_CONTROL_REGISTER_0, 0);
	
	zmiWrite16(ptZmiRegs, ZMI_VME_CONTROL_REGISTER_1, 0);

	zmiWrite16(ptZmiRegs, ZMI_VME_CONTROL_REGISTER_2, 0);
	
	zmiWrite16(ptZmiRegs, ZMI_VME_CONTROL_REGISTER_3, 0);
	
	zmiWrite16(ptZmiRegs, ZMI_VME_CONTROL_REGISTER_4, 0);
	
	zmiWrite16(ptZmiRegs, ZMI_VME_CONTROL_REGISTER_5, 0);
	
    if (axis % 2)   // Axis 1 or 3
    {
        zmiWrite16(ptZmiRegs, ZMI_VME_CONTROL_REGISTER_15, 0);
        zmiWrite16(ptZmiRegs, ZMI_VME_CONTROL_REGISTER_16, 0);
        zmiWrite16(ptZmiRegs, ZMI_VME_CONTROL_REGISTER_17, 0);
        
        zmiWrite16(ptZmiRegs, ZMI_VME_DIAG_TEMP_MONITOR_CONTROL_REG, 0x2A0D);
	}
    
    if (axis == 1)
    {
        zmiWrite16(ptZmiRegs, ZMI_VME_CE_CONTROL_REGISTER, 0x0000);
    }
    
    if (axis == 3)
    {
        zmiWrite16(ptZmiRegs, ZMI_VME_CE_CONTROL_REGISTER, 0x0003);
    }

	zmiWrite16(ptZmiRegs, ZMI_VME_EEPROM_CONTROL_REGISTER, 0x0000);

	zmiWrite16(ptZmiRegs, ZMI_VME_USER_VELOCITY_REGISTER, 0xFFFF);

    
    // Init internal trigger mode *****************************************
    
	zmiWrite32(ptZmiRegs, ZMI_VME_ERROR_CLEAR0, 0xFFFFFFFF);
		
	/*FA Reset axis, position quick, time, position, P2 errors VME errors*/
	/*FA setzen ueber Command Register*/
	zmiWrite16(ptZmiRegs, ZMI_VME_COMMAND_REGISTER, 0x003F);
		
	/*FA VME Bit Window werden in Position Register geshiftet */
	Data = zmiRead16(ptZmiRegs, ZMI_VME_CONTROL_REGISTER_2);

	Data &= 0xFF1F;	//VME Bit Window loeschen
	Data |= ZMI4000_VME_BIT_WINDOW << 5;	//VME Bit Window setzen
	Data |= 0x200;		//Aux Reg. Enable (fuer CEC Zugriff) setzen
	Data &= 0xE7FF;	//SCLK VME Sample In und VME enable 32bit overflow loeschen
	Data |= 1<< 4; //DACx16 Bit setzen um analoge SSI-Ausgabe zu verst�rken (Interferometerjustage) ~OtS 18.08.2010
	
    zmiWrite16(ptZmiRegs, ZMI_VME_CONTROL_REGISTER_2, Data);
	
	if (axis % 2) // Axis 1 and 3
	{	
		/*FA USERLED und SCLK devide by 2 einstellen ueber Controlregister 16*/
		zmiWrite16(ptZmiRegs, ZMI_VME_CONTROL_REGISTER_16, 0x0023);
	
		/*FA P2 SCLK1 Timer einstellen ueber Controlregister 17*/
		zmiWrite16(ptZmiRegs, ZMI_VME_CONTROL_REGISTER_17, 0x0C00);
    }
    
    zmiWrite16(ptZmiRegs, ZMI_VME_SCLK_COMMAND_REGISTER, 0x1);  // Force External Sample
    
    if (axis == 3)
    {
        zmiWrite16(ptZmiRegs, ZMI_VME_SAMPLE_TIMER_REGISTER, 0x1387);
	
        /*FA SCLK1 output enable ueber Controlregister 17 setzen*/
        zmiWrite16(ptZmiRegs,ZMI_VME_CONTROL_REGISTER_17, 0x200);

        /*FA USERLED und "SCLK devide by 2", SCLK0 enablen mit Output*/
        /*FA einstellen ueber Controlregister 16*/
        zmiWrite16(ptZmiRegs,ZMI_VME_CONTROL_REGISTER_16, 0x0E23);        
    }
    
    #ifdef SG_DEBUG
    printf("Axis %i, init ok\n");
    #endif
    
    return 0;
}


/**************************************************************************
 * Function: VmeZmiReadPosition
 * arg 1, ZMI4104TYPE *ptZmiRegs1: Pointer to the axis register
 * arg 2, uint32_T *ptOutPort_Pos: Sim out port for Position
 * return: 0 if success
 * Description: Read the Position from the VME Position MSB/LSB regs
 * 
 * Modifications 
 * +-------------+----------------------------------------------+--------+
 * | Date        | Comments                                     | Author |
 * +-------------+----------------------------------------------+--------+
 * | 23-Oct-2012 | First version                                | DK     |
 * +-------------+----------------------------------------------+--------+
 *
 *************************************************************************/
int VmeZmiReadPosition(ZMI4104TYPE *ptZmiRegs, real_T *ptOutPort_Pos)
{           
	volatile uint32_T lsb = 0x00000000;
	volatile uint16_T ext = 0x0000;

	ext = zmiRead16(ptZmiRegs, ZMI_VME_POSITION_EXT);
	#ifdef SG_DEBUG
	printf("VmeZmiReadPosition: before zmiRead32\n");
	#endif
	lsb = zmiRead32(ptZmiRegs, ZMI_VME_POSITION_LSB);
	#ifdef SG_DEBUG
	printf("VmeZmiReadPosition: after zmiRead32\n");
	#endif

	#ifdef SG_DEBUG
	printf("ext = 0x%04x, msb+lsb = 0x%08x\n", ext, lsb);
	#endif

	ptOutPort_Pos[0] = GetRealValue(ext, lsb);

	return 0;
 }
    
void VmeZmiReadPositionComponents(ZMI4104TYPE *ptZmiRegs, uint32_T *lsb, uint16_T *ext)
{
	*ext = zmiRead16(ptZmiRegs, ZMI_VME_POSITION_EXT);
	*lsb = zmiRead32(ptZmiRegs, ZMI_VME_POSITION_LSB);
}
	
/**************************************************************************
 * Function: VmeZmiReadSamplePosition
 * arg 1, ZMI4104TYPE *ptZmiRegs1: Pointer to the axis register
 * arg 2, uint32_T *ptOutPort_SamPos: Sim out port for Sample Position
 * return: 0 if success
 * Description: Read the Sample Position from the VME Sample Position 
 *              MSB/LSB regs
 * 
 * Modifications 
 * +-------------+----------------------------------------------+--------+
 * | Date        | Comments                                     | Author |
 * +-------------+----------------------------------------------+--------+
 * | 23-Oct-2012 | First version                                | DK     |
 * +-------------+----------------------------------------------+--------+
 *
 *************************************************************************/
int VmeZmiReadSamplePosition(ZMI4104TYPE *ptZmiRegs, real_T *ptOutPort_SamPos)
{  
	volatile uint32_T lsb = 0x00000000;
	volatile uint16_T ext = 0x0000;

	ext = zmiRead16(ptZmiRegs, ZMI_VME_SAMPLE_POSITION_EXT);
	#ifdef SG_DEBUG
	printf("VmeZmiReadSamplePosition: before zmiRead32\n");
	#endif
	lsb = zmiRead32(ptZmiRegs, ZMI_VME_SAMPLE_POSITION_LSB);
	#ifdef SG_DEBUG
	printf("VmeZmiReadSamplePosition: after zmiRead32\n");
	#endif

	#ifdef SG_DEBUG
	printf("ext = 0x%04x, msb+lsb = 0x%08x\n", ext, lsb);
	#endif

	ptOutPort_SamPos[0] = GetRealValue(ext, lsb);

	return 0;
}
    
/**************************************************************************
 * Function: VmeZmiReadVelocity
 * arg 1, ZMI4104TYPE *ptZmiRegs1: Pointer to the axis register
 * arg 2, uint32_T *ptOutPort_Vel: Sim out port for Velocity
 * return: 0 if success
 * Description: Read the Sample Position from the VME Velocity MSB/LSB regs
 * 
 * Modifications 
 * +-------------+----------------------------------------------+--------+
 * | Date        | Comments                                     | Author |
 * +-------------+----------------------------------------------+--------+
 * | 23-Oct-2012 | First version                                | DK     |
 * +-------------+----------------------------------------------+--------+
 *
 *************************************************************************/
int VmeZmiReadVelocity(ZMI4104TYPE *ptZmiRegs, real_T *ptOutPort_Vel)
{
    uint32_T lsb;
    
	#ifdef SG_DEBUG
	printf("VmeZmiReadVelocity: before zmiRead32\n");
	#endif
    lsb = zmiRead32(ptZmiRegs, ZMI_VME_VELOCITY_LSB);
	#ifdef SG_DEBUG
	printf("VmeZmiReadVelocity: after zmiRead32\n");
	#endif
    lsb = (lsb << 16) | (lsb >> 16);
    ptOutPort_Vel[0] = lsb;
    
    return 0;
}

/**************************************************************************
 * Function: VmeZmiReadTime
 * arg 1, ZMI4104TYPE *ptZmiRegs1: Pointer to the axis register
 * arg 2, uint32_T *ptOutPort_Time: Sim out port for Time
 * return: 0 if success
 * Description: Read the Sample Position from the VME Velocity MSB/LSB regs
 * 
 * Modifications 
 * +-------------+----------------------------------------------+--------+
 * | Date        | Comments                                     | Author |
 * +-------------+----------------------------------------------+--------+
 * | 23-Oct-2012 | First version                                | DK     |
 * +-------------+----------------------------------------------+--------+
 *
 *************************************************************************/
int VmeZmiReadTime(ZMI4104TYPE *ptZmiRegs, real_T *ptOutPort_Time)
{
    uint32_T lsb;
    
	#ifdef SG_DEBUG
	printf("VmeZmiReadTime: before zmiRead32\n");
	#endif
    lsb = zmiRead32(ptZmiRegs, ZMI_VME_TIME_LSB);
	#ifdef SG_DEBUG
	printf("VmeZmiReadTime: after zmiRead32\n");
	#endif
    lsb = (lsb << 16) | (lsb >> 16);    
    ptOutPort_Time[0] = (real_T)lsb * 25e-9;

    return 0;
}
    
/**************************************************************************
 * Function: VmeZmiSetFilter
 * arg 1, ZMI4104TYPE *ptZmiRegs: Pointer to the axis register
 * arg 2, int8_T kp_id: kp index 0..7
 * arg 3, int8_T kv_id: kv index 0..7 
 * return: 0 if success
 * Description: Set the value of Kp and Kv for digital filtering, for the
 *				provided axis
 * 
 * Modifications 
 * +-------------+----------------------------------------------+--------+
 * | Date        | Comments                                     | Author |
 * +-------------+----------------------------------------------+--------+
 * | 28-Nov-2012 | First version                                | DK     |
 * +-------------+----------------------------------------------+--------+
 *
 *************************************************************************/
int VmeZmiSetFilter(ZMI4104TYPE *ptZmiRegs, int8_T kp_id, int8_T kv_id)
{
	uint16_T temp = 0x0000;

	temp |= kv_id;
	temp |= (kp_id << 4);

	zmiWrite16(ptZmiRegs, ZMI_VME_CONTROL_REGISTER_1, temp);

	return 0;
}

/**************************************************************************
 * Function: VmeZmiEepromRead
 * arg 1, ZMI4104TYPE *ptZmiRegs: Pointer to the axis register
 * arg 2, uint8_T offset: offset address of the EEPROM
 * return: value contained on the register
 * Description: Read the value of an EEPROM address
 * 
 * Modifications 
 * +-------------+----------------------------------------------+--------+
 * | Date        | Comments                                     | Author |
 * +-------------+----------------------------------------------+--------+
 * | 28-Nov-2012 | First version                                | DK     |
 * +-------------+----------------------------------------------+--------+
 *
 *************************************************************************/
int VmeZmiEepromRead(ZMI4104TYPE *ptZmiRegs, uint8_T offset)
{
    uint16_T temp = 0x0000;

    if ((zmiRead16(ptZmiRegs, ZMI_VME_TEST_STATUS1) & 0x0800) == 0x0800)  // Check if Error = 1
    {
        volatile uint16_T data = zmiRead16(ptZmiRegs, ZMI_VME_TEST_COMMAND1);

        data |= 0x0004;
        zmiWrite16(ptZmiRegs, ZMI_VME_TEST_COMMAND1, data);
    }

    while((zmiRead16(ptZmiRegs,ZMI_VME_TEST_STATUS1) & 0x0200)==0x0200);   // Wait EEPROM busy

    temp |= (0x2 << 12);    // Read
    temp |= offset;         // address 0..1024

    zmiWrite16(ptZmiRegs,ZMI_VME_EEPROM_CONTROL_REGISTER, temp);

    while((zmiRead16(ptZmiRegs,ZMI_VME_TEST_STATUS1) & 0x0200)==0x0200);   // Wait EEPROM busy

    return zmiRead16(ptZmiRegs,ZMI_VME_EEPROM_READ);
}

/**************************************************************************
 * Function: VmeZmiWaitingAxis
 * arg 1, SimStruct *S: Simulink Structure
 * arg 2, ZMI4104TYPE *ptZmiRegs: Pointer to the axis register
 * arg 3, uint8_T ax_n: axis number
 * arg 4, char msg[]: Message for error
 * return: 0 for success or error code
 * Description: Wait that the axis is ready
 * 
 * Modifications 
 * +-------------+----------------------------------------------+--------+
 * | Date        | Comments                                     | Author |
 * +-------------+----------------------------------------------+--------+
 * | 29-Nov-2012 | First version                                | DK     |
 * +-------------+----------------------------------------------+--------+
 *
 *************************************************************************/
int VmeZmiWaitingAxis(SimStruct *S, ZMI4104TYPE *ptZmiRegs, uint8_T ax_n,  char msg[])
{
    uint8_T timeout = 0;
    printf("Waiting Axis %i ", ax_n);

    while((zmiRead16(ptZmiRegs, ZMI_VME_STATUS_REGISTER0) & 0x0002) != 0x0002) // wait 
    {
        timeout++;
        xpcBusyWait(1);
        printf(".");
        if (timeout == 5)   // Timeout 5 seconds
        {
            printf("\n");
            sprintf(msg,"%s: Timeout, axis %i", DEVNAME, ax_n);
            ssSetErrorStatus(S,msg);
            return 1;
        }
    }
    printf("\nAxis %i ready\n", ax_n);
    return 0;
}

/**************************************************************************
 * Function: VmeZmiReset
 * arg 1, ZMI4104TYPE *ptZmiRegs: Pointer to the axis register
 * return: 0 for success or error code
 * Description: Wait that the axis is ready
 * 
 * Modifications 
 * +-------------+----------------------------------------------+--------+
 * | Date        | Comments                                     | Author |
 * +-------------+----------------------------------------------+--------+
 * | 29-Nov-2012 | First version                                | DK     |
 * +-------------+----------------------------------------------+--------+
 *
 *************************************************************************/
int VmeZmiReset(ZMI4104TYPE *ptZmiRegs)
{
    ptZmiRegs[ZMI_VME_STATUS_REGISTER0] |= 0x0020;
    
    return 0;
}

/**************************************************************************
 * Function: GetRealValue
 * arg 1, uint32_T ext: Value of the Ext register
 * arg 2, uint32_T msb: Value of the MSB+LSB registers
 * return: double (real_T) value
 * Description: Wait that the axis is ready
 * 
 * Modifications 
 * +-------------+----------------------------------------------+--------+
 * | Date        | Comments                                     | Author |
 * +-------------+----------------------------------------------+--------+
 * | 10-Dec-2012 | First version                                | Unknow |
 * +-------------+----------------------------------------------+--------+
 * | 13-Feb-2013 | Byte swap removed                            | DK     |
 * +-------------+----------------------------------------------+--------+
 *
 *************************************************************************/
real_T GetRealValue(uint32_T ext, uint32_T msb)
{
	double result = 0;
	/*
	 double: bit  63     sign
	         bits 52-62  exponent
			 bits 0-51   fraction

			 v = (-1)^sign * 2^(exponent - 1023) x 1.fraction
	*/

	int exponent = 1023 + 52;
	uint32_T fraction_high = ext & 0xFF;
	uint32_T fraction_low = (msb << 16) | (msb >> 16);

	bool isNegative = ext & 0x10;

	if (isNegative)
	{
		fraction_high = ~fraction_high;
		fraction_low ^= 0xFFFFFFFF;

		if (fraction_low == 0xFFFFFFF)
		{
			fraction_low = 0;
			fraction_high++;
		}
		else
		{
			fraction_low++;
		}
	}

	fraction_high &= 0xFF;	

	if (!fraction_high && !fraction_low)
	{
		return 0.0;
	}

	while(!(fraction_high & (1 << 20)))
	{
		fraction_high <<= 1;
		fraction_high |= (fraction_low >> 31);
		fraction_low <<= 1;
		exponent--;
	}
	
	fraction_high &= (1 << 20) - 1;

	((uint32_T*)&result)[0] = fraction_low;
	((uint32_T*)&result)[1] = fraction_high | (exponent << 20);
	
	/* sign */
	if (isNegative)
		((uint32_T*)&result)[1] |= 0x80000000;

	return result;
}

int VmeZmiReadCyclicErrorCNReal(ZMI4104TYPE *ptZmiRegs, real_T *ptValue)
{
	uint32_T aCE_CN = 0;
	uint32_T aExponent, aSign, aMantissa;
	real_T result;
	#ifdef SG_DEBUG
	printf("VmeZmiReadCyclicErrorCNReal: before zmiRead32\n");
	#endif
	aCE_CN = zmiRead32(ptZmiRegs, ZMI_VME_CE_CN_CALCULATED);
	#ifdef SG_DEBUG
	printf("VmeZmiReadCyclicErrorCNReal: after zmiRead32\n");
	#endif
    aCE_CN = (aCE_CN << 16) | (aCE_CN >> 16);
	aExponent = (aCE_CN & VMICFLOAT_EXP_MASK) >> VMICFLOAT_EXP_SHIFT;
	aSign     = (aCE_CN & VMICFLOAT_RSIGN_MASK) >> VMICFLOAT_RSIGN_SHIFT;
	aMantissa = (aCE_CN & VMICFLOAT_RMANT_MASK) >> VMICFLOAT_RMANT_SHIFT;
	result = (real_T)(aMantissa) * pow(2.0, (real_T)((signed int)aExponent - VMICFLOAT_EXP_BIAS - VMICFLOAT_MANT_BITS));
	if (aSign)
	{
		result = -result;
	}

	*ptValue = result;
	
	return 0;
}

int VmeZmiReadCyclicErrorCNImaginary(ZMI4104TYPE *ptZmiRegs, real_T *ptValue)
{
	uint32_T aCE_CN = 0;
	uint32_T aExponent, aSign, aMantissa;
	real_T result;
	#ifdef SG_DEBUG
	printf("VmeZmiReadCyclicErrorCNImaginary: before zmiRead32\n");
	#endif
	aCE_CN = zmiRead32(ptZmiRegs, ZMI_VME_CE_CN_CALCULATED);
	#ifdef SG_DEBUG
	printf("VmeZmiReadCyclicErrorCNImaginary: after zmiRead32\n");
	#endif
    aCE_CN = (aCE_CN << 16) | (aCE_CN >> 16);

	aExponent = (aCE_CN & VMICFLOAT_EXP_MASK) >> VMICFLOAT_EXP_SHIFT;
	aSign 	  = (aCE_CN & VMICFLOAT_ISIGN_MASK) >> VMICFLOAT_ISIGN_SHIFT;
	aMantissa = (aCE_CN & VMICFLOAT_IMANT_MASK) >> VMICFLOAT_IMANT_SHIFT;
	result = (real_T)(aMantissa) * pow(2.0, (real_T)((signed int)aExponent - VMICFLOAT_EXP_BIAS - VMICFLOAT_MANT_BITS));
	if (aSign)
	{
		result = -result;
	}

	*ptValue = result;
	
	return 0;
}

int VmeZmiReadCyclicErrorC1Real(ZMI4104TYPE *ptZmiRegs, real_T *ptValue)
{
	uint32_T aCE_C1 = 0;
	uint32_T aExponent, aSign, aMantissa;
	real_T result;
	#ifdef SG_DEBUG
	printf("VmeZmiReadCyclicErrorC1Real: before zmiRead32\n");
	#endif
	aCE_C1 = zmiRead32(ptZmiRegs, ZMI_VME_CE_C1_CALCULATED);
	#ifdef SG_DEBUG
	printf("VmeZmiReadCyclicErrorC1Real: after zmiRead32\n");
	#endif
    aCE_C1 = (aCE_C1 << 16) | (aCE_C1 >> 16);

	aSign = (aCE_C1 & VMIFLOAT_SIGN_MASK) >> VMIFLOAT_SIGN_SHIFT;
	aExponent = (aCE_C1 & VMIFLOAT_EXP_MASK) >> VMIFLOAT_EXP_SHIFT;
	aMantissa = (aCE_C1 & VMIFLOAT_MANT_MASK) >> VMIFLOAT_MANT_SHIFT;
	result = (real_T)(aMantissa | VMIFLOAT_MANT_MSB) * pow(2.0, (real_T)((signed)aExponent - VMIFLOAT_EXP_BIAS - VMIFLOAT_MANT_BITS));
	if (aSign)
	{
		result = -result;
	}

	*ptValue = result;
	
	return 0;
}

int VmeZmiReadCyclicErrorC0Real(ZMI4104TYPE *ptZmiRegs, real_T *ptValue)
{
	uint32_T aCE_C0 = 0;
	signed short aShortCE_C0_real;
	real_T result;
	#ifdef SG_DEBUG
	printf("VmeZmiReadCyclicErrorC0Real: before zmiRead32\n");
	#endif
	aCE_C0 = zmiRead32(ptZmiRegs, ZMI_VME_CE_C0_CALCULATED);
	#ifdef SG_DEBUG
	printf("VmeZmiReadCyclicErrorC0Real: after zmiRead32\n");
	#endif
    aCE_C0 = (aCE_C0 << 16) | (aCE_C0 >> 16);

	aShortCE_C0_real = (signed short)( (aCE_C0 >> 16) & 0xFFFF );

	*ptValue = 1.0 * aShortCE_C0_real;

	return 0;
}

int VmeZmiReadCyclicErrorC0Imaginary(ZMI4104TYPE *ptZmiRegs, real_T *ptValue)
{
	uint32_T aCE_C0 = 0;
	signed short aShortCE_C0_im;
	real_T result;
	#ifdef SG_DEBUG
	printf("VmeZmiReadCyclicErrorC0Imaginary: before zmiRead32\n");
	#endif
	aCE_C0 = zmiRead32(ptZmiRegs, ZMI_VME_CE_C0_CALCULATED);
	#ifdef SG_DEBUG
	printf("VmeZmiReadCyclicErrorC0Imaginary: after zmiRead32\n");
	#endif
    aCE_C0 = (aCE_C0 << 16) | (aCE_C0 >> 16);

	aShortCE_C0_im = (signed short)( aCE_C0 & 0xFFFF );

	*ptValue = 1.0 * aShortCE_C0_im;

	return 0;
}

#endif