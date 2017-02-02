#ifndef __SPEEDGOAT_H__
#define __SPEEDGOAT_H__

#include <stdio.h>
#include <xpctarget.h>

int sg_find_device (char DevName[256], uint16_T VendorId, uint16_T DeviceId, uint16_T SubVendorId, uint16_T SubDeviceId, int16_T SlotArg[2], xpcPCIDevice* ptPciInfo, char msg[256]);
int sg_map_BAR(xpcPCIDevice *ptPciDevice, int BAR_0, int BAR_1, int BAR_2, int BAR_3, int BAR_4, int BAR_5);

#endif