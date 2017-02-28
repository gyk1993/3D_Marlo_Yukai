/* File Pilpxi.h */
/* Public header for PIL PXI Driver */
/* (c) Pickering Interfaces Ltd. 2012 */
/* D.C.H  14/02/12 */


#ifdef _CVI_
typedef char CHAR;
#include <cvidef.h>
#endif


#ifndef __PILPXI_H__
#define __PILPXI_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Function return error code definitions */
enum
{
	NO_ERR					= 0,	/* OK */
	ER_NO_CARD				= 1,	/* No Pickering card has the specified number */
	ER_NO_INFO				= 2,	/* Cannot obtain information for specified card */
	ER_CARD_DISABLED		= 3,	/* Specified card is disabled */
	ER_BAD_SUB				= 4,	/* Sub-unit value out-of-range for target card */
	ER_BAD_BIT				= 5,	/* Bit-number out-of-range for target sub-unit */
	ER_NO_CAL_DATA			= 6,	/* Target sub-unit has no calibration data to read/write */
	ER_BAD_ARRAY			= 7,	/* SafeArray type, shape or size is incorrect */
	ER_MUX_ILLEGAL			= 8,	/* Non-zero write data value is illegal for MUX sub-unit */
	ER_EXCESS_CLOSURE		= 9,	/* Execution would cause closure limit to be exceeded */
	ER_ILLEGAL_MASK			= 10,	/* One or more of the specified channels cannot be masked */
	ER_OUTPUT_MASKED		= 11,	/* Cannot activate an output that is masked */
	ER_BAD_LOCATION			= 12,	/* Cannot open a Pickering card at the specified location */
	ER_READ_FAIL			= 13,	/* Failed read from hardware */
	ER_WRITE_FAIL			= 14,	/* Failed write to hardware */
	ER_DRIVER_OP			= 15,	/* Hardware driver failure */
	ER_DRIVER_VERSION		= 16,	/* Incompatible hardware driver version */
	ER_SUB_TYPE				= 17,	/* Function call incompatible with sub-unit type or capabilities */
	ER_BAD_ROW				= 18,	/* Matrix row value out-of-range */
	ER_BAD_COLUMN			= 19,	/* Matrix column value out-of-range */
	ER_BAD_ATTEN			= 20,	/* Attenuation value out-of-range */
	ER_BAD_VOLTAGE			= 21,	/* Voltage value out-of-range */
	ER_BAD_CAL_INDEX		= 22,	/* Calibration index value out-of-range */
	ER_BAD_SEGMENT			= 23,	/* Segment number out of range */
	ER_BAD_FUNC_CODE		= 24,	/* Function code value out of range */
	ER_BAD_SUBSWITCH		= 25,	/* Subswitch value out of range */
	ER_BAD_ACTION			= 26,	/* Action code out of range */
	ER_STATE_CORRUPT		= 27,	/* Cannot execute due to corrupt sub-unit state */
	ER_BAD_ATTR_CODE		= 28,	/* Unrecognised attribute code */
	ER_EEPROM_WRITE_TMO		= 29,	/* Timeout writing to EEPROM */
	ER_ILLEGAL_OP			= 30,	/* Operation is illegal in the sub-unit's current state */
	ER_BAD_POT				= 31,	/* Unrecognised pot number requested */
	ER_MATRIXR_ILLEGAL		= 32,	/* Invalid write pattern for MATRIXR sub-unit */
	ER_MISSING_CHANNEL		= 33,	/* Attempted operation on non-existent channel */
	ER_CARD_INACCESSIBLE	= 34,	/* Card cannot be accessed (failed/removed/unpowered) */
	ER_BAD_FP_FORMAT		= 35,	/* Unsupported internal floating-point format (internal error) */
	ER_UNCALIBRATED			= 36,	/* Sub-unit is not calibrated */
	ER_BAD_RESISTANCE		= 37,	/* Unobtainable resistance value */
	ER_BAD_STORE			= 38,	/* Invalid calibration store number */
	ER_BAD_MODE				= 39,	/* Invalid mode value */
	ER_SETTINGS_CONFLICT	= 40,	/* Conflicting device settings */
	ER_CARD_TYPE			= 41,	/* Function call incompatible with card type or capabilities */
	ER_BAD_POLE				= 42,	/* Switch pole value out of range */
	ER_MISSING_CAPABILITY	= 43,	/* Attempted to activate a non-existent capability */
	ER_MISSING_HARDWARE		= 44,	/* Action requires hardware that is not present */
	ER_HARDWARE_FAULT		= 45,	/* Faulty hardware */
	ER_EXECUTION_FAIL		= 46,	/* Failed to execute (e.g. blocked by a hardware condition) */
	ER_BAD_CURRENT			= 47,	/* Current value out of range */
	ER_BAD_RANGE			= 48,	/* Invalid range value */
	ER_ATTR_UNSUPPORTED		= 49,	/* Attribute not supported */
	ER_BAD_REGISTER			= 50,	/* Register number out of range */
	ER_MATRIXP_ILLEGAL		= 51,	/* Invalid channel closure or write pattern for MATRIXP sub-unit */
	ER_BUFFER_UNDERSIZE		= 52	/* Data buffer too small */
};

/* Card status bits for PIL_Status() and PIL_SubStatus() results */
enum
{
	STAT_NO_CARD			= 0x80000000UL,	/* No card with specified number */
	STAT_WRONG_DRIVER		= 0x40000000UL,	/* Card requires later driver version */
	STAT_EEPROM_ERR			= 0x20000000UL,	/* Error interpreting card EEPROM data */
	STAT_DISABLED			= 0x10000000UL,	/* Card is disabled */
	STAT_NO_SUB				= 0x08000000UL,	/* Card has no sub-unit with specified number */
	STAT_BUSY				= 0x04000000UL,	/* Busy (card or sub-unit) */
	STAT_HW_FAULT			= 0x02000000UL,	/* Hardware fault (eg. defective serial loop) */
	STAT_PARITY_ERROR		= 0x01000000UL,	/* 9050 Parity Error */
	STAT_PSU_INHIBITED		= 0x00800000UL,	/* PSU sub-unit - supply is disabled (by software) */
	STAT_PSU_SHUTDOWN		= 0x00400000UL,	/* PSU sub-unit - supply is shutdown (due to overload) */
	STAT_PSU_CURRENT_LIMIT	= 0x00200000UL,	/* PSU sub-unit - supply is operating in current-limited mode */
	STAT_CORRUPTED			= 0x00100000UL,	/* Sub-unit logical state is corrupted */
	STAT_CARD_INACCESSIBLE	= 0x00080000UL,	/* Card cannot be accessed (failed/removed/unpowered) */
	STAT_UNCALIBRATED		= 0x00040000UL,	/* Calibration data is faulty (card or sub-unit) */
	STAT_CALIBRATION_DUE	= 0x00020000UL,	/* Calibration is due (card or sub-unit) */
	STAT_BIRST_ENABLED		= 0x00010000UL,	/* BIRST is active (card or sub-unit) */
	STAT_OK					= 0x00000000UL
};

/* Driver operating mode control bits for PIL_SetMode() */
enum
{
	MODE_DEFAULT		= 0x00000000UL,	/* Default, no special modes set */
	MODE_NO_WAIT		= 0x00000001UL,	/* Function calls exclude output settling delay */
	MODE_UNLIMITED		= 0x00000002UL,	/* Disable maximium closure limits */
	MODE_REOPEN			= 0x00000004UL,	/* Allow re-open without clearing cards */
	MODE_IGNORE_TEST	= 0x00000008UL	/* Enable card operation even if selftest fails */
};

/* OUTPUT sub-unit type specifier codes (as returned by PIL_SubInfo())*/
enum
{
    TYPE_SW		= 1,	/* Uncommitted switches */
    TYPE_MUX	= 2,	/* Relay multiplexer (single-channel only) */
    TYPE_MUXM	= 3,	/* Relay multiplexer (multi-channel capable) */
    TYPE_MAT	= 4,	/* Standard matrix */
    TYPE_MATR	= 5,	/* RF matrix */
    TYPE_DIG	= 6,	/* Digital outputs */
	TYPE_RES	= 7,	/* Programmable Resistor */
	TYPE_ATTEN	= 8,	/* Programmable Attenuator */
	TYPE_PSUDC	= 9,	/* Power supply - DC */
	TYPE_BATT	= 10,	/* Battery simulator */
	TYPE_VSOURCE	= 11,	/* Programmable voltage source */
    TYPE_MATP	= 12	/* Matrix with restricted operating modes */
};

/* Note: there is only a single type of INPUT sub-unit; PIL_SubInfo() always
 * returns type code 1 for INPUT sub-units.
 */

/* Maximum lengths of string results */
enum
{
	MAX_DIAG_LENGTH		= 1024,	/* PIL_Diagnostic() */
	MAX_ID_STR			= 52,	/* PIL_CardId() */
	MAX_SUB_TYPE_STR	= 80,	/* PIL_SubType() */
	MAX_PSU_TYPE_STR	= 80,	/* PIL_PsuType() */
	MAX_ATTEN_TYPE_STR	= 80,	/* PIL_AttenType() */
	MAX_ERR_STR			= 256	/* PIL_ErrorMessage() */
};

/* =============================================================================
 * Function:	get Pickering card identification string
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				Str     = pointer to character string to receive result
 * Returns:		0 = success; non-zero = error code
 * The result string contains <type code>,<serial number>,<revision number>.
 */
DWORD _stdcall PIL_CardId(DWORD CardNum, CHAR *Str);

/* =============================================================================
 * Function:	get Pickering card location information
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				Bus     = pointer to DWORD to receive Bus result value
 *				Slot    = pointer to DWORD to receive Slot result value
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_CardLoc(DWORD CardNum, DWORD *Bus, DWORD *Slot);

/* =============================================================================
 * Function:	obtain count of card operations
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				Count   = pointer to variable to receive the result
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_CardOpsCount(DWORD CardNum, DWORD *Count);

/* =============================================================================
 * Function:	clear all output sub-units of all open Pickering cards
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_ClearAll(void);

/* =============================================================================
 * Function:	clear all output sub-units on a card
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_ClearCard(DWORD CardNum);

/* =============================================================================
 * Function:	clear the switch mask for an output sub-unit
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to write (unity-based)
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_ClearMask(DWORD CardNum, DWORD OutSub);

/* =============================================================================
 * Function:	clear all outputs of a sub-unit
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to access (unity-based)
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_ClearSub(DWORD CardNum, DWORD OutSub);

/* =============================================================================
 * Function:	Close all open Pickering cards
 */
void _stdcall PIL_CloseCards(void);

/* =============================================================================
 * Function:	close a card, specified by Pickering card reference
 * Argument:	CardNum = Pickering card reference of target (unity-based)
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_CloseSpecifiedCard(DWORD CardNum);

/* =============================================================================
 * Function:	get a sub-unit's closure limit
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to access (unity-based)
 *				Limit   = pointer to DWORD variable to accept result
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_ClosureLimit(DWORD CardNum, DWORD OutSub, DWORD *Limit);

/* =============================================================================
 * Function:	get diagnostic information
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				Str     = pointer to character string to receive result
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_Diagnostic(DWORD CardNum, CHAR *Str);

/* =============================================================================
 * Function:	get Pickering card input and output sub-unit counts
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				InSubs  = pointer to variable to receive input sub-unit count
 *				OutSubs = pointer to variable to receive output sub-unit count
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_EnumerateSubs(DWORD CardNum, DWORD *InSubs, DWORD *OutSubs);

/* =============================================================================
 * Function:	get a string description of an error code
 * Arguments:	ErrorCode = the error code to be described
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_ErrorMessage(DWORD ErrorCode, CHAR *Str);

/* =============================================================================
 * Function:	set or clear a single mask bit
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to access (unity-based)
 *				BitNum  = output bit number (unity-based)
 *				Action  = TRUE (for MASKED) or FALSE (for UNMASKED)
 * Returns: 0 = success; non-zero = error code
 */
DWORD _stdcall PIL_MaskBit(DWORD CardNum, DWORD OutSub, DWORD BitNum, BOOL Action);

/* =============================================================================
 * Function:	set or clear a matrix crosspoint's mask
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to access (unity-based)
 *				Row     = crosspoint row (Y) location (unity-based)
 *				Column  = crosspoint column (X) location (unity-based)
 *				Action  = TRUE (for MASKED) or FALSE (for UNMASKED)
 * Returns: 0 = success; non-zero = error code
 */
DWORD _stdcall PIL_MaskCrosspoint(DWORD CardNum, DWORD OutSub, DWORD Row, DWORD Column, BOOL Action);

/* =============================================================================
 * Function:	operate a single output bit
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to access (unity-based)
 *				BitNum  = output bit number (unity-based)
 *				Action  = TRUE (for ON) or FALSE (for OFF)
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_OpBit(DWORD CardNum, DWORD OutSub, DWORD BitNum, BOOL Action);

/* =============================================================================
 * Function:	set the state of a matrix crosspoint
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to view (unity-based)
 *				Row     = crosspoint row (Y) location (unity-based)
 *				Column  = crosspoint column (X) location (unity-based)
 *				Action  = TRUE (for ON) or FALSE (for OFF)
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_OpCrosspoint(DWORD CardNum, DWORD OutSub, DWORD Row, DWORD Column, BOOL Action);

/* =============================================================================
 * Function:	Locate and open all installed Pickering cards.	
 * Returns:		the number of Pickering cards located and opened.
 */
DWORD _stdcall PIL_OpenCards(void);

/* =============================================================================
 * Function:	open a card, specified by logical bus and slot location
 * Arguments:	Bus = logical bus location of card to open
 *				Slot = logical slot location of card to open
 *				CardNum = pointer to variable to receive the Pickering card
 *							reference of target (unity-based)
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_OpenSpecifiedCard(DWORD Bus, DWORD Slot, DWORD *CardNum);

/* =============================================================================
 * Function:	read the state of an individual input
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				InSub   = sub-unit of target to read (unity-based)
 *				BitNum  = input bit number (unity-based)
 *				State   = pointer to BOOL variable to accept result
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_ReadBit(DWORD CardNum, DWORD InSub, DWORD BitNum, BOOL *State);

/* =====================================================================
 * Function:	read a calibration value from EEPROM
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to access (unity-based)
 *				Idx     = calibration value index number (unity-based)
 *				Data =  pointer to variable to receive result
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_ReadCal(DWORD CardNum, DWORD OutSub, DWORD Idx, DWORD *Data);

/* =============================================================================
 * Function:	read data from input sub-unit
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				InSub   = sub-unit of target to read (unity-based)
 *				Data    = pointer to DWORD array to accept result
 * Returns:		0 = success; non-zero = error code
 * The data array must be dimensioned to hold the number of bits representing
 * the specified sub-unit. The result occupies the appropriate number of least
 * significant bits in the data array.
 */
DWORD _stdcall PIL_ReadSub(DWORD CardNum, DWORD InSub, DWORD *Data);

/* =============================================================================
 * Function:	set driver operating mode
 * Argument:	ModeFlags = bit flags controlling driver options
 * Returns:		previous operating mode flags
 */
DWORD _stdcall PIL_SetMode(DWORD ModeFlags);

/* =============================================================================
 * Function:	get a sub-unit's settling time in microseconds
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to access (unity-based)
 *				Time   = pointer to DWORD variable to accept result
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_SettleTime(DWORD CardNum, DWORD OutSub, DWORD *Time);

/* =============================================================================
 * Function:	get status information for a Pickering card
 * Argument:	CardNum = Pickering card reference of target (unity-based)
 * Returns:		bit-flags indicating the status of the specified card
 */
DWORD _stdcall PIL_Status(DWORD CardNum);

/* =============================================================================
 * Function:	get Pickering card sub-unit information (numeric format)
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				SubNum  = sub-unit of target to access (unity-based)
 *				Out     = TRUE for output sub-unit, FALSE for input sub-unit
 *				TypeNum = pointer to variable to receive type code result
 *				Rows    = pointer to variable to receive row dimension result
 *				Cols    = pointer to variable to receive column dimension result
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_SubInfo(DWORD CardNum, DWORD SubNum, BOOL Out, DWORD *TypeNum, DWORD *Rows, DWORD *Cols);

/* =============================================================================
 * Function:	get status information for a sub-unit of a Pickering card
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				SubNum  = sub-unit of target to access (unity-based)
 * Returns:		bit-flags indicating the status of the specified sub-unit
 */
DWORD _stdcall PIL_SubStatus(DWORD CardNum, DWORD SubNum);

/* =============================================================================
 * Function:	get Pickering card sub-unit information (in string format)
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				SubNum  = sub-unit of target to access (unity-based)
 *				Out     = TRUE for output sub-unit, FALSE for input sub-unit
 *				Str     = pointer to character string to receive result
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_SubType(DWORD CardNum, DWORD SubNum, BOOL Out, CHAR *Str);

/* =============================================================================
 * Function:	get PIL driver version
 * Returns:		version number of PIL software driver, for example
 *				return value = 100 indicates version 1.00
 */
DWORD _stdcall PIL_Version(void);

/* =============================================================================
 * Function:	get the state of an individual output bit
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to view (unity-based)
 *				BitNum  = output bit number (unity-based)
 *				State   = pointer to BOOL variable to accept result
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_ViewBit(DWORD CardNum, DWORD OutSub, DWORD BitNum, BOOL *State);

/* =============================================================================
 * Function:	get the state of a matrix crosspoint
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to view (unity-based)
 *				Row     = crosspoint row (Y) location (unity-based)
 *				Column  = crosspoint column (X) location (unity-based)
 *				State   = pointer to BOOL variable to accept result
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_ViewCrosspoint(DWORD CardNum, DWORD OutSub, DWORD Row, DWORD Column, BOOL *State);

/* =============================================================================
 * Function:	get the switch mask of an output sub-unit
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to view (unity-based)
 *				Data    = pointer to DWORD array to accept result
 * Returns:		0 = success; non-zero = error code
 * The data array must be dimensioned to hold the number of bits representing
 * the specified sub-unit. The result occupies the appropriate number of least
 * significant bits in the data array.
 */
DWORD _stdcall PIL_ViewMask(DWORD CardNum, DWORD OutSub, DWORD *Data);

/* =============================================================================
 * Function:	get the state of an individual switch mask bit
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to view (unity-based)
 *				BitNum  = output bit number (unity-based)
 *				State   = pointer to BOOL variable to accept result
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_ViewMaskBit(DWORD CardNum, DWORD OutSub, DWORD BitNum, BOOL *State);

/* =============================================================================
 * Function:	get the state of a matrix crosspoint's mask
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to view (unity-based)
 *				Row     = crosspoint row (Y) location (unity-based)
 *				Column  = crosspoint column (X) location (unity-based)
 *				State   = pointer to BOOL variable to accept result
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_ViewMaskCrosspoint(DWORD CardNum, DWORD OutSub, DWORD Row, DWORD Column, BOOL *State);

/* =============================================================================
 * Function:	get the state of an output sub-unit
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to view (unity-based)
 *				Data    = pointer to DWORD array to accept result
 * Returns:		0 = success; non-zero = error code
 * The data array must be dimensioned to hold the number of bits representing
 * the specified sub-unit. The result occupies the appropriate number of least
 * significant bits in the data array.
 */
DWORD _stdcall PIL_ViewSub(DWORD CardNum, DWORD OutSub, DWORD *Data);

/* =====================================================================
 * Function:	write a calibration value to EEPROM
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to access (unity-based)
 *				Idx     = calibration value index number (unity-based)
 *				Data =  calibration value to write
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_WriteCal(DWORD CardNum, DWORD OutSub, DWORD Idx, DWORD Data);

/* =============================================================================
 * Function:	set the switch mask for an output sub-unit
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to write (unity-based)
 *				Data    = pointer to array of DWORD values to be used as the mask
 * Returns:		0 = success; non-zero = error code
 * The data array must be dimensioned to hold the number of bits representing
 * the specified sub-unit. The appropriate number of least significant bits in
 * the data array are written into the mask. Writing a '1' bit into the mask
 * disables the corresponding switch for PIL_OpBit(), PIL_OpCrosspoint(),
 * PIL_WriteSub(), PIL_WriteSub_s() and PIL_WriteSubArray() operations.
 */
DWORD _stdcall PIL_WriteMask(DWORD CardNum, DWORD OutSub, DWORD *Data);

/* =============================================================================
 * Function:	write data to an output sub-unit
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to write (unity-based)
 *				Data    = pointer to array of DWORD values to be written
 * Returns:		0 = success; non-zero = error code
 * The data array must be dimensioned to hold the number of bits representing
 * the specified sub-unit. The appropriate number of least significant bits in
 * the data array are written.
 */
DWORD _stdcall PIL_WriteSub(DWORD CardNum, DWORD OutSub, DWORD *Data);



/* =============================================================================
 * Functions:	New scanlist functionality
 */

DWORD _stdcall ScanListSizeSet( int card, int sub, int size);
DWORD _stdcall ScanListRecord( int card, int sub, int slot);

DWORD _stdcall ScanListClear( int card, int sub, int slot);
DWORD _stdcall ScanListReset( int card, int sub);
DWORD _stdcall ScanListDestroy( int card, int sub);

DWORD _stdcall ScanListTrigger( int card, int sub, int slot);



/* ********************************************************************************
 * The following functions are SAFEARRAY-based equivalents for PIL_ViewMask(),
 * PIL_ViewSub(), PIL_WriteMask() and PIL_WriteSub(). Although present mainly to
 * provide secure array handling in Visual Basic, they are also usable in Visual C++.
 * They are not supported in environments other than WIN32 or in LabWindows/CVI.
 * ********************************************************************************
 */


#ifdef WIN32
#ifndef _CVI_

/* =============================================================================
 * Function:	get the switch mask of an output sub-unit (in a SAFEARRAY)
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to view (unity-based)
 *				Data    = Pointer to Pointer to SafeArray (of longwords) to accept result
 * Returns:		0 = success; non-zero = error code
 * The linear data array (vector) must be of sufficient size to hold the number
 * of bits representing the specified sub-unit. The result occupies the appropriate
 * number of least significant bits in the array.
 */
DWORD _stdcall PIL_ViewMaskArray(DWORD CardNum, DWORD OutSub, LPSAFEARRAY FAR* Data);

/* =============================================================================
 * Function:	get the state of an output sub-unit (in a SAFEARRAY)
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to view (unity-based)
 *				Data    = Pointer to Pointer to SAFEARRAY (of longwords) to
 *							accept result
 * Returns:		0 = success; non-zero = error code
 * The linear data array (vector) must be of sufficient size to hold the number
 * of bits representing the specified sub-unit. The result occupies the appropriate
 * number of least significant bits in the array.
 */
DWORD _stdcall PIL_ViewSubArray(DWORD CardNum, DWORD OutSub, LPSAFEARRAY FAR* Data);

/* =============================================================================
 * Function:	set the switch mask for an output sub-unit (using a SAFEARRAY)
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target (unity-based)
 *				Data    = Pointer to Pointer to SAFEARRAY (of longwords) containing mask data
 * Returns:		0 = success; non-zero = error code
 * The linear data array (vector) must be of sufficient size to hold the number
 * of bits representing the specified sub-unit. The appropriate number of least
 * significant bits in the array are written to the mask.
 */
DWORD _stdcall PIL_WriteMaskArray(DWORD CardNum, DWORD OutSub, LPSAFEARRAY FAR* Data);

/* =============================================================================
 * Function:	write data to an output sub-unit (using a SAFEARRAY)
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to write (unity-based)
 *				Data    = Pointer to Pointer to SAFEARRAY (of longwords) containing 
 *							data to be written
 * Returns:		0 = success; non-zero = error code
 * The linear data array (vector) must be of sufficient size to hold the number
 * of bits representing the specified sub-unit. The appropriate number of least
 * significant bits in the array are written.
 */
DWORD _stdcall PIL_WriteSubArray(DWORD CardNum, DWORD OutSub, LPSAFEARRAY FAR* Data);

#endif
#endif

/* ********************************************************************************
 * Attenuator specific functions.
 * ********************************************************************************
 */

/* =============================================================================
 * Function:	get attenuator sub-unit information (in string format)
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				SubNum  = sub-unit of target to access (unity-based)
 *				Str     = pointer to character string to receive result
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_AttenType(DWORD CardNum, DWORD SubNum, char *Str);

/* =============================================================================
 * Function:	get attenuator sub-unit information (numeric format)
 * Arguments:	CardNum  = Pickering card reference of target (unity-based)
 *				SubNum   = sub-unit of target to access (unity-based)
 *				TypeNum  = pointer to variable to receive type code result
 *				NumSteps = pointer to variable to receive step count result
 *				StepSize = pointer to variable to receive step size result
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_AttenInfo(DWORD CardNum, DWORD SubNum, DWORD *TypeNum, DWORD *NumSteps, float *StepSize);

/* =============================================================================
 * Function:	set attenuation value
 * Arguments:	CardNum  = Pickering card reference of target (unity-based)
 *				SubNum   = sub-unit of target to access (unity-based)
 *				Atten    = the attenuation value to set
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_AttenSetAttenuation(DWORD CardNum, DWORD SubNum, float Atten);

/* =============================================================================
 * Function:	get attenuation value
 * Arguments:	CardNum  = Pickering card reference of target (unity-based)
 *				SubNum   = sub-unit of target to access (unity-based)
 *				Atten    = pointer to variable to receive the attenuation value
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_AttenGetAttenuation(DWORD CardNum, DWORD SubNum, float *Atten);

/* =============================================================================
 * Function:	get the attenuation value associated with a numbered pad
 * Arguments:	CardNum  = Pickering card reference of target (unity-based)
 *				SubNum   = sub-unit of target to access (unity-based)
 *				PadNum   = the pad number (unity-based)
 *				Atten    = pointer to variable to receive the attenuation value
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_AttenPadValue(DWORD CardNum, DWORD SubNum, DWORD PadNum, float *Atten);

/* ********************************************************************************
 * Power supply specific functions.
 * ********************************************************************************
 */

/* PSU capability flag bits for PIL_PsuInfo() */
enum
{
	PSU_CAP_OUTPUT_CONTROL		= 0x00000001,	/* Has output on/off control */
	PSU_CAP_OUTPUT_SENSE		= 0x00000002,	/* Has logic-level sensing of output active state */
	PSU_CAP_PROG_VOLTAGE		= 0x00000004,	/* Output voltage is programmable */
	PSU_CAP_PROG_CURRENT		= 0x00000008,	/* Output current is programmable */
	PSU_CAP_CURRENT_MODE_SENSE	= 0x00000010	/* Can sense if operating in current-limited mode */
};

/* =============================================================================
 * Function:	get power supply sub-unit information (in string format)
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				SubNum  = sub-unit of target to access (unity-based)
 *				Str     = pointer to character string to receive result
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_PsuType(DWORD CardNum, DWORD SubNum, CHAR *Str);

/* =============================================================================
 * Function:	get power supply sub-unit information (numeric format)
 * Arguments:	CardNum  = Pickering card reference of target (unity-based)
 *				SubNum   = sub-unit of target to access (unity-based)
 *				TypeNum  = pointer to variable to receive the type code
 *				Voltage  = pointer to variable to receive rated output voltage
 *				Current  = pointer to variable to receive rated output current
 *				Precis   = pointer to variable to receive converter precision (for programmable models - bits)
 *				Capabilities = pointer to variable to receive capability flags
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_PsuInfo(DWORD CardNum, DWORD SubNum, DWORD *TypeNum, double *Voltage, double *Current, DWORD *Precis, DWORD *Capabilities);

/* =============================================================================
 * Function:	set power supply output voltage
 * Arguments:	CardNum  = Pickering card reference of target (unity-based)
 *				SubNum   = sub-unit of target to access (unity-based)
 *				Voltage  = the voltage to set
 * Returns:		0 = success; non-zero = error code
 * Note:		The output voltage will be set to the nearest available DAC
 *				step value.
 */
DWORD _stdcall PIL_PsuSetVoltage(DWORD CardNum, DWORD SubNum, double Voltage);

/* =============================================================================
 * Function:	get power supply output voltage
 * Arguments:	CardNum  = Pickering card reference of target (unity-based)
 *				SubNum   = sub-unit of target to access (unity-based)
 *				Voltage  = pointer to variable to receive the voltage value
 * Returns:		0 = success; non-zero = error code
 * Note:		Obtains the nominal voltage to which the output voltage has
 *				been set by PIL_PsuSetVoltage().
 */
DWORD _stdcall PIL_PsuGetVoltage(DWORD CardNum, DWORD SubNum, double *Voltage);

/* =============================================================================
 * Function:	enable/disable the output of a power supply
 * Arguments:	CardNum  = Pickering card reference of target (unity-based)
 *				SubNum   = sub-unit of target to access (unity-based)
 *				State    = 1 to enable, 0 to disable output
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_PsuEnable(DWORD CardNum, DWORD SubNum, BOOL State);

/* =============================================================================
 * NOTE: PSU status information can be obtained using the general-purpose
 * function PIL_SubStatus
 */

/* ********************************************************************************
 * Functions supporting arbitrary switch access in sub-units with auto-isolation
 * and/or auto-loopthru
 * ********************************************************************************
 */

/* AttrCode values for PIL_SubAttribute() */
enum
{
	SUB_ATTR_CHANNEL_SUBSWITCHES	= 1,		/* Gets number of subswitches per logical channel */
	SUB_ATTR_X_ISO_SUBSWITCHES		= 2,		/* Gets number of subswitches per logical X-isolator */
	SUB_ATTR_Y_ISO_SUBSWITCHES		= 3,		/* Gets number of subswitches per logical Y-isolator */
	SUB_ATTR_X_LOOPTHRU_SUBSWITCHES	= 4,		/* Gets number of subswitches per logical X-loopthru */
	SUB_ATTR_Y_LOOPTHRU_SUBSWITCHES	= 5,		/* Gets number of subswitches per logical Y-loopthru */
	SUB_ATTR_MATRIXP_TOPOLOGY		= 6,		/* Gets a code representing MATRIXP topology */

	SUB_ATTR_NUM_X_SEGMENTS			= 0x100,	/* Gets number of X-axis segments */
	SUB_ATTR_X_SEGMENT01_SIZE		= 0x101,	/* Gets size of X-axis segment 1 */
	SUB_ATTR_X_SEGMENT02_SIZE		= 0x102,	/* Gets size of X-axis segment 2 */
	SUB_ATTR_X_SEGMENT03_SIZE		= 0x103,	/* Gets size of X-axis segment 3 */
	SUB_ATTR_X_SEGMENT04_SIZE		= 0x104,	/* Gets size of X-axis segment 4 */
	SUB_ATTR_X_SEGMENT05_SIZE		= 0x105,	/* Gets size of X-axis segment 5 */
	SUB_ATTR_X_SEGMENT06_SIZE		= 0x106,	/* Gets size of X-axis segment 6 */
	SUB_ATTR_X_SEGMENT07_SIZE		= 0x107,	/* Gets size of X-axis segment 7 */
	SUB_ATTR_X_SEGMENT08_SIZE		= 0x108,	/* Gets size of X-axis segment 8 */
	SUB_ATTR_X_SEGMENT09_SIZE		= 0x109,	/* Gets size of X-axis segment 9 */
	SUB_ATTR_X_SEGMENT10_SIZE		= 0x10A,	/* Gets size of X-axis segment 10 */
	SUB_ATTR_X_SEGMENT11_SIZE		= 0x10B,	/* Gets size of X-axis segment 11 */
	SUB_ATTR_X_SEGMENT12_SIZE		= 0x10C,	/* Gets size of X-axis segment 12 */

	SUB_ATTR_NUM_Y_SEGMENTS			= 0x200,	/* Gets number of Y-axis segments */
	SUB_ATTR_Y_SEGMENT01_SIZE		= 0x201,	/* Gets size of Y-axis segment 1 */
	SUB_ATTR_Y_SEGMENT02_SIZE		= 0x202		/* Gets size of Y-axis segment 2 */
};

/* SwitchFunc codes for PIL_OpSwitch() */
enum
{
	SW_FUNC_CHANNEL			= 0,	/* A channel (crosspoint) switch */
	SW_FUNC_X_ISO			= 1,	/* An X-isolation switch */
	SW_FUNC_Y_ISO			= 2,	/* A Y-isolation switch */
	SW_FUNC_X_LOOPTHRU		= 3,	/* An X-loopthru switch */
	SW_FUNC_Y_LOOPTHRU		= 4,	/* A Y-loopthru switch */
	SW_FUNC_X_BIFURCATION	= 5,	/* An X-bifurcation switch */
	SW_FUNC_Y_BIFURCATION	= 6		/* A Y-bifurcation switch */
};

/* SwitchAction codes for PIL_OpSwitch() */
enum
{
	SW_ACT_NONE		= 0,	/* No switch change - just set State result */
	SW_ACT_OPEN		= 1,	/* Open switch */
	SW_ACT_CLOSE	= 2		/* Close switch */
};

/* Codes returned for SUB_ATTR_MATRIXP_TOPOLOGY attribute */
enum
{
	MATRIXP_NOT_APPLICABLE	= 0,	/* Sub-unit is not MATRIXP type */
	MATRIXP_RESTRICTIVE_X	= 1,	/* MATRIXP allowing only one column (X) connection on any row (Y) */
	MATRIXP_RESTRICTIVE_Y	= 2		/* MATRIXP allowing only one row (Y) connection on any column (X) */
};

/* =============================================================================
 * Function:	obtain the value of a sub-unit attribute
 * Arguments:	CardNum       = Pickering card reference of target (unity-based)
 *				SubNum        = sub-unit of target to access (unity-based)
 *				Out           = TRUE for output sub-unit, FALSE for input sub-unit
 *				AttrCode      = code indicating the attribute to be obtained
 *				AttrValue     = pointer to variable to receive the value of the attribute
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_SubAttribute(DWORD CardNum, DWORD SubNum, BOOL Out, DWORD AttrCode, DWORD *AttrValue);

/* =============================================================================
 * Function:	operate a specific switch, and/or discover its state
 * Arguments:	CardNum       = Pickering card reference of target (unity-based)
 *				OutSub        = sub-unit of target to access (unity-based)
 *				SwitchFunc    = code indicating the functional group of the switch
 *              SegNum        = the segment location of the switch (unity-based)
 *				SwitchNum     = the number of the switch in its functional group (unity-based)
 *              SubSwitch     = the number of the subswitch to operate (unity-based)
 *				SwitchAction  = code indicating the action to be performed
 *				State         = pointer to variable to receive the state of the switch
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_OpSwitch(DWORD CardNum,
							DWORD OutSub,
							DWORD SwitchFunc,
							DWORD SegNum,
							DWORD SwitchNum,
							DWORD SubSwitch,
							DWORD SwitchAction,
							BOOL *State);

/* =============================================================================
 * Function:	obtain a count of unopened Pickering cards (without opening them)
 * Arguments:   NumCards = pointer to variable to receive the number of cards found
 * Returns:		0 = success; non-zero = error code */
DWORD _stdcall PIL_CountFreeCards(DWORD *NumCards);

/* =============================================================================
 * Function:	find the locations of unopened Pickering cards (without opening them)
 * Arguments:   NumCards = the number of cards (maximum) for which information is to be obtained
 *              BusList = pointer to array to receive cards' bus locations
 *              SlotList = pointer to array to receive cards' slot locations
 * Returns:		0 = success; non-zero = error code */
DWORD _stdcall PIL_FindFreeCards(DWORD NumCards, DWORD *BusList, DWORD *SlotList);


/* ********************************************************************************
 * Floating-point calibration data functions.
 * ********************************************************************************
 */

/* Values for selecting User or Factory calibration stores */
#define CAL_STORE_USER		0
#define CAL_STORE_FACTORY	1

/* =============================================================================
 * Function:	store floating-point calibration value(s) in EEPROM
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to access (unity-based)
 *				Store  = value indicating which store to access (user = 0, factory = 1)
 *				Offset  = offset in the sub-unit's calibration table at which to start (zero-based)
 *				NumValues  = the number of calibration values to write
 *				Data   = pointer to array of calibration values
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_WriteCalFP(DWORD CardNum, DWORD OutSub, DWORD Store, DWORD Offset, DWORD NumValues, double *Data);

/* =============================================================================
 * Function:	read floating-point calibration value(s) from EEPROM
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to access (unity-based)
 *				Store  = value indicating which store to access (user = 0, factory = 1)
 *				Offset  = offset in the sub-unit's calibration table at which to start (zero-based)
 *				NumValues  = the number of calibration values to read
 *				Data   = pointer to array to receive calibration values
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_ReadCalFP(DWORD CardNum, DWORD OutSub, DWORD Store, DWORD Offset, DWORD NumValues, double *Data);

/* =============================================================================
 * Function:	write calibration date information to EEPROM
 *              Date information is obtained from the current system date.
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to access (unity-based)
 *				Store  = value indicating which store to access (user = 0, factory = 1)
 *				Interval   = the desired calibration interval (in days)
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_WriteCalDate(DWORD CardNum, DWORD OutSub, DWORD Store, DWORD Interval);

/* =============================================================================
 * Function:	read calibration date information from EEPROM
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to access (unity-based)
 *				Store  = value indicating which store to access (user = 0, factory = 1)
 *				Year  = pointer to variable to receive year of calibration
 *				Day   = pointer to variable to receive day in year of calibration
 *				Interval   = pointer to variable to receive calibration interval (in days)
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_ReadCalDate(DWORD CardNum, DWORD OutSub, DWORD Store, DWORD *Year, DWORD *Day, DWORD *Interval);

/* =============================================================================
 * Function:	set a calibration point
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to access (unity-based)
 *				Idx  = index number of calibration point
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_SetCalPoint(DWORD CardNum, DWORD OutSub, DWORD Idx);

/* ********************************************************************************
 * Programmable resistor specific functions.
 * ********************************************************************************
 */

/* Mode codes for PIL_ResSetResistance() */
enum
{
	RES_MODE_SET		= 0	/* Set the specified value */
};

/* =============================================================================
 * Function:	set resistance as close as possible to the given value
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to access (unity-based)
 *				Mode  = a value indicating how the given resistance value is to be applied
 *				Resistance   = the resistance value
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_ResSetResistance(DWORD CardNum, DWORD OutSub, DWORD Mode, double Resistance);

/* =============================================================================
 * Function:	obtain the set resistance value
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to access (unity-based)
 *				Resistance   = pointer to variable to receive the resistance value
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_ResGetResistance(DWORD CardNum, DWORD OutSub, double *Resistance);

/* Capabilites flag bits for PIL_ResInfo */
enum
{
	RES_CAP_NONE	= 0x00000000UL,	/* No special capabilities */
	RES_CAP_PREC	= 0x00000001UL,	/* Supports precision setting (40-260 etc.) */
	RES_CAP_ZERO	= 0x00000002UL,	/* Supports "zero ohms" setting */
	RES_CAP_INF		= 0x00000004UL,	/* Supports infinity setting */
	RES_CAP_REF		= 0x00000008UL	/* Supports reference calibration value (e.g. 40-265) */
};

/* =============================================================================
 * Function:	obtain resistor characteristics
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to access (unity-based)
 *				MinRes  = pointer to variable to receive the minimum resistance setting
 *				MaxRes  = pointer to variable to receive the maximum resistance setting
 *				RefRes  = pointer to variable to receive the reference resistance value
 *				PrecPC  = pointer to variable to receive percentage precision (+/- percent)
 *				PrecDelta   = pointer to variable to receive delta precision (+/- ohms)
 *				Int1 = pointer to variable to receive (currently unused) value
 *				IntDelta = pointer to variable to receive internal precision (+/- ohms)
 *				Capabilities   = pointer to variable to receive capabilities flags
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_ResInfo(DWORD CardNum, DWORD OutSub, double *MinRes, double *MaxRes, double *RefRes, double *PrecPC, double *PrecDelta, double *Int1, double *IntDelta, DWORD *Capabilities);

/* ********************************************************************************
 * Battery Simulator (BATT type) specific functions.
 * ********************************************************************************
 */

enum
{
	BATT_ALL_BATT_SUB_UNITS	= 0UL		/* Sub-unit number to make operation affect all BATT sub-units */
};

/* =============================================================================
 * Function:	set Battery Simulator (BATT type) channel output voltage
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				SubNum  = sub-unit of target to access (unity-based)
 *				Voltage = the voltage to set (in Volts)
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_BattSetVoltage(DWORD CardNum, DWORD SubNum, double Voltage);

/* =============================================================================
 * Function:	get Battery Simulator (BATT type) channel output voltage
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				SubNum  = sub-unit of target to access (unity-based)
 *				Voltage = pointer to variable to receive the voltage currently set (in Volts)
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_BattGetVoltage(DWORD CardNum, DWORD SubNum, double *Voltage);

/* =============================================================================
 * Function:	set Battery Simulator (BATT type) channel sink current
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				SubNum  = sub-unit of target to access (unity-based)
 *				Current = the current to set (in Amps)
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_BattSetCurrent(DWORD CardNum, DWORD SubNum, double Current);

/* =============================================================================
 * Function:	get Battery Simulator (BATT type) channel sink current
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				SubNum  = sub-unit of target to access (unity-based)
 *				Current = pointer to variable to receive the current currently set (in Amps)
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_BattGetCurrent(DWORD CardNum, DWORD SubNum, double *Current);

/* =============================================================================
 * Function:	set Battery Simulator (BATT type) channel output enable states
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				SubNum  = sub-unit of target to access (unity-based, or BATT_ALL_BATT_SUB_UNITS)
 *				Pattern = the enable state to set for a given channel; or a pattern of
 *				channel outputs to enable ('1' bits enable corresponding channel)
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_BattSetEnable(DWORD CardNum, DWORD SubNum, DWORD Pattern);

/* =============================================================================
 * Function:	get Battery Simulator (BATT type) channel output enable states
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				SubNum  = sub-unit of target to access (unity-based, or BATT_ALL_BATT_SUB_UNITS)
 *				Pattern = pointer to variable to receive a given channel's enable state;
 *				or a pattern of channel outputs currently enabled ('1' bits indicate
 *				the corresponding channel is enabled)
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_BattGetEnable(DWORD CardNum, DWORD SubNum, DWORD *Pattern);

/* =============================================================================
 * Function:	get Battery Simulator (BATT type) interlock state
 * Arguments:	CardNum   = Pickering card reference of target (unity-based)
 *				SubNum    = sub-unit of target to access (unity-based)
 *				Interlock = pointer to variable to receive the interlock state ('1' = interlock intact)
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_BattReadInterlockState(DWORD CardNum, DWORD SubNum, BOOL *Interlock);


/* ********************************************************************************
 * Voltage Source (VSOURCE type) specific functions.
 * ********************************************************************************
 */

enum
{
	VSOURCE_ALL_VSOURCE_SUB_UNITS	= 0UL		/* Sub-unit number to make operation affect all VSOURCE sub-units */
};

/* =============================================================================
 * Function:	set Voltage Source (VSOURCE type) range
 * Arguments:	CardNum   = Pickering card reference of target (unity-based)
 *				SubNum    = sub-unit of target to access (unity-based)
 *				Range     = the range to set
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_VsourceSetRange(DWORD CardNum, DWORD SubNum, double Range);

/* =============================================================================
 * Function:	get Voltage Source (VSOURCE type) range
 * Arguments:	CardNum   = Pickering card reference of target (unity-based)
 *				SubNum    = sub-unit of target to access (unity-based)
 *				Range     = pointer to variable to receive the present range setting
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_VsourceGetRange(DWORD CardNum, DWORD SubNum, double *Range);

/* =============================================================================
 * Function:	set Voltage Source (VSOURCE type) output voltage
 * Arguments:	CardNum   = Pickering card reference of target (unity-based)
 *				SubNum    = sub-unit of target to access (unity-based)
 *				Voltage   = the voltage to set
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_VsourceSetVoltage(DWORD CardNum, DWORD SubNum, double Voltage);

/* =============================================================================
 * Function:	get Voltage Source (VSOURCE type) output voltage
 * Arguments:	CardNum   = Pickering card reference of target (unity-based)
 *				SubNum    = sub-unit of target to access (unity-based)
 *				Voltage   = pointer to variable to receive the present voltage setting
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_VsourceGetVoltage(DWORD CardNum, DWORD SubNum, double *Voltage);

/* =============================================================================
 * Function:	set Voltage Source (VSOURCE type) channel output enable states
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				SubNum  = sub-unit of target to access (unity-based, or VSOURCE_ALL_VSOURCE_SUB_UNITS)
 *				Pattern = the enable state to set for a given channel; or a pattern of
 *				channel outputs to enable ('1' bits enable corresponding channel)
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_VsourceSetEnable(DWORD CardNum, DWORD SubNum, DWORD Pattern);

/* =============================================================================
 * Function:	get Voltage Source (VSOURCE type) channel output enable states
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				SubNum  = sub-unit of target to access (unity-based, or VSOURCE_ALL_VSOURCE_SUB_UNITS)
 *				Pattern = pointer to variable to receive a given channel's enable state;
 *				or a pattern of channel outputs currently enabled ('1' bits indicate
 *				the corresponding channel is enabled)
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_VsourceGetEnable(DWORD CardNum, DWORD SubNum, DWORD *Pattern);


/* ********************************************************************************
 * Secure versions of functions accessing character strings or DWORD arrays.
 * ********************************************************************************
 */

/* =============================================================================
 * Function:	get Pickering card identification string (secure version)
 * Arguments:	CardNum   = Pickering card reference of target (unity-based)
 *				Str       = pointer to character string to receive result
 *				StrLen    = length of the string buffer
 * Returns:		0 = success; non-zero = error code
 * The result string contains <type code>,<serial number>,<revision number>.
 */
DWORD _stdcall PIL_CardId_s(DWORD CardNum, CHAR *Str, DWORD StrLen);

/* =============================================================================
 * Function:	get diagnostic information (secure version)
 * Arguments:	CardNum   = Pickering card reference of target (unity-based)
 *				Str       = pointer to character string to receive result
 *				StrLen    = length of the string buffer
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_Diagnostic_s(DWORD CardNum, CHAR *Str, DWORD StrLen);

/* =============================================================================
 * Function:	get a string description of an error code (secure version)
 * Arguments:	ErrorCode = the error code to be described
 *				Str       = pointer to character string to receive result
 *				StrLen    = length of the string buffer
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_ErrorMessage_s(DWORD ErrorCode, CHAR *Str, DWORD StrLen);

/* =============================================================================
 * Function:	get Pickering card sub-unit information, in string format (secure version)
 * Arguments:	CardNum   = Pickering card reference of target (unity-based)
 *				SubNum    = sub-unit of target to access (unity-based)
 *				Out       = TRUE for output sub-unit, FALSE for input sub-unit
 *				Str       = pointer to character string to receive result
 *				StrLen    = length of the string buffer
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_SubType_s(DWORD CardNum, DWORD SubNum, BOOL Out, CHAR *Str, DWORD StrLen);

/* =============================================================================
 * Function:	get attenuator sub-unit information, in string format (secure version)
 * Arguments:	CardNum   = Pickering card reference of target (unity-based)
 *				SubNum    = sub-unit of target to access (unity-based)
 *				Str       = pointer to character string to receive result
 *				StrLen    = length of the string buffer
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_AttenType_s(DWORD CardNum, DWORD SubNum, CHAR *Str, DWORD StrLen);

/* =============================================================================
 * Function:	get power supply sub-unit information, in string format (secure version)
 * Arguments:	CardNum   = Pickering card reference of target (unity-based)
 *				SubNum    = sub-unit of target to access (unity-based)
 *				Str       = pointer to character string to receive result
 *				StrLen    = length of the string buffer
 * Returns:		0 = success; non-zero = error code
 */
DWORD _stdcall PIL_PsuType_s(DWORD CardNum, DWORD SubNum, CHAR *Str, DWORD StrLen);

/* =============================================================================
 * Function:	read data from input sub-unit (secure version)
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				InSub   = sub-unit of target to read (unity-based)
 *				Data    = pointer to DWORD array to accept result
 *				DataLen = number of DWORD elements in the Data array
 * Returns:		0 = success; non-zero = error code
 * The data array must be dimensioned to hold the number of bits representing
 * the specified sub-unit. The result occupies the appropriate number of least
 * significant bits in the data array.
 */
DWORD _stdcall PIL_ReadSub_s(DWORD CardNum, DWORD InSub, DWORD *Data, DWORD DataLen);

/* =============================================================================
 * Function:	get the switch mask of an output sub-unit (secure version)
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to view (unity-based)
 *				Data    = pointer to DWORD array to accept result
 *				DataLen = number of DWORD elements in the Data array
 * Returns:		0 = success; non-zero = error code
 * The data array must be dimensioned to hold the number of bits representing
 * the specified sub-unit. The result occupies the appropriate number of least
 * significant bits in the data array.
 */
DWORD _stdcall PIL_ViewMask_s(DWORD CardNum, DWORD OutSub, DWORD *Data, DWORD DataLen);

/* =============================================================================
 * Function:	get the state of an output sub-unit (secure version)
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to view (unity-based)
 *				Data    = pointer to DWORD array to accept result
 *				DataLen = number of DWORD elements in the Data array
 * Returns:		0 = success; non-zero = error code
 * The data array must be dimensioned to hold the number of bits representing
 * the specified sub-unit. The result occupies the appropriate number of least
 * significant bits in the data array.
 */
DWORD _stdcall PIL_ViewSub_s(DWORD CardNum, DWORD OutSub, DWORD *Data, DWORD DataLen);

/* =============================================================================
 * Function:	set the switch mask for an output sub-unit (secure version)
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to write (unity-based)
 *				Data    = pointer to array of DWORD values to be used as the mask
 *				DataLen = number of DWORD elements in the Data array
 * Returns:		0 = success; non-zero = error code
 * The data array must be dimensioned to hold the number of bits representing
 * the specified sub-unit. The appropriate number of least significant bits in
 * the data array are written into the mask. Writing a '1' bit into the mask
 * disables the corresponding switch for PIL_OpBit(), PIL_OpCrosspoint(),
 * PIL_WriteSub(), PIL_WriteSub_s() and PIL_WriteSubArray() operations.
 */
DWORD _stdcall PIL_WriteMask_s(DWORD CardNum, DWORD OutSub, DWORD *Data, DWORD DataLen);

/* =============================================================================
 * Function:	write data to an output sub-unit (secure version)
 * Arguments:	CardNum = Pickering card reference of target (unity-based)
 *				OutSub  = sub-unit of target to write (unity-based)
 *				Data    = pointer to array of DWORD values to be written
 *				DataLen = number of DWORD elements in the Data array
 * Returns:		0 = success; non-zero = error code
 * The data array must be dimensioned to hold the number of bits representing
 * the specified sub-unit. The appropriate number of least significant bits in
 * the data array are written.
 */
DWORD _stdcall PIL_WriteSub_s(DWORD CardNum, DWORD OutSub, DWORD *Data, DWORD DataLen);

#ifdef __cplusplus
}
#endif

#endif // __PILPXI_H__
