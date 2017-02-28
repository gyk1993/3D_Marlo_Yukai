#ifndef __SG_CIFX_EXT_H__
#define __SG_CIFX_EXT_H__

#include <stdio.h>
#include <stdlib.h>

#include    "xpctarget.h"
#include    "xpcimports.h"

#define DEVNAME					"Speedgoat IO75x"
#define VENDORID				0x15cf
#define DEVICEID				XPC_NO_VEND_DEV
#define SUBVENDORID				XPC_NO_VEND_DEV
#define SUBDEVICEID				XPC_NO_VEND_DEV


#define     FIRMWARE_PBM		"IO641"
#define     FIRMWARE_PBS		"IO642"
#define     FIRMWARE_ECS		"IO750"
#define     FIRMWARE_EIM		"IO755"
#define     FIRMWARE_EIS		"IO756"
#define		FIRMWARE_ECM		"IO759"

#define		SG_DATA_READ		(1)
#define		SG_DATA_WRITE		(2)

#define		SG_WARMSTART		(1)
#define		SG_CONFIGFILES1		(2)
#define		SG_CONFIGFILES2		(3)

#define		MAX_CARD_NUMBER		10
#define		FSTR_LEN			16		//MAX STRING CHARACTER FOR A FILENAME (INCLUDIGN EXTENSION AND STRING END

typedef struct IO75XDATAtag 
{
	char firmware[256];	// Firmware name
	int init_mode;		// Initialization mode
	int mode;			// 0: polling mode, 1: interrupt mode
	char driveletter[10];
} IO75XDATA, *PIO75XDATA; //todo: rename cifxData or similar

// Generic (sg_cifx_ext_fcn.c)
void sg_cifx_config_data(int cardId, int access, PIO75XDATA ptCardData);
int32_T sg_cifx_init (int cardId, xpcPCIDevice pciinfo, IO75XDATA cardData, int timeout);
void sg_cifx_deinit (int cardId);
void sg_cifx_cyclictimer(int cardId);

int sg_cifx_getstate (int cardId);
void sg_cifx_setstate (int cardId, uint32_T commState, uint32_T ulTimeout);

int sg_cifx_read(int cardId, int address_start, int length, uint8_T data[5760]);
void sg_cifx_write(int cardId, int address_start, int length, uint8_T data[5760]);

void sg_cifx_startComm(int cardId);
void sg_cifx_stopComm(int cardId);

void sg_cifx_interrupt_init(int cardId, int enable);
int sg_cifx_interrupt_handler(int cardId);
void sg_cifx_DSR_handler(int cardId);

int sg_cifx_getint(int cardId);

//Profibus Slave specific (sg_cifx_pbs.c)
typedef struct IO642DATAtag 
{
	int input; // I/O offset: 0x1000  length: 244 R/W
	int output;// I/O offset: 0x2680  length: 244  R

} IO642DATA, *PIO642DATA; 

void sg_cifx_pbs_data(int cardId, int access, PIO642DATA ptCardData);

//EtherCAT Slave specific (sg_cifx_ecs.c)
typedef struct IO750DATAtag 
{
	int input;
	int output;

} IO750DATA, *PIO750DATA;

void sg_cifx_ecs_data(int cardId, int access, PIO750DATA ptCardData);

//Ethernet/IP Slave specifix (sg_cifx_eis.c)
typedef struct IO756DATAtag 
{
	uint32_T inputLen;
	uint32_T outputLen;
	int dhcp_en;
	int bootp_en;
	int ipaddr_en;
	uint32_T ipaddress;
	uint32_T netmask;
	uint32_T gateway;
	uint32_T watchdog;
	uint32_T vendorid;
	uint32_T producttype;
	uint32_T productcode;
	uint32_T majorrev;
	uint32_T minorrev;
	char devicename[31];

} IO756DATA, *PIO756DATA;

void sg_cifx_eis_data(int cardId, int access, PIO756DATA ptCardData);

void sg_cifx_eis_assembly (int cardId, uint32_T ulInstance, uint32_T ulDPMOffset, uint32_T ulSize);
void EIS_RegisterOutputAssembly( int cardId );
void EIS_RegisterInputAssembly( int cardId );
#endif