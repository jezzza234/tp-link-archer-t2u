/*
 ***************************************************************************
 * Ralink Tech Inc.
 * 4F, No. 2 Technology 5th Rd.
 * Science-based Industrial Park
 * Hsin-chu, Taiwan, R.O.C.
 *
 * (c) Copyright 2002-2004, Ralink Technology, Inc.
 *
 * All rights reserved. Ralink's source code is an unpublished work and the
 * use of a copyright notice does not imply otherwise. This source code
 * contains confidential trade secret material of Ralink Tech. Any attemp
 * or participation in deciphering, decoding, reverse engineering or in any
 * way altering the source code is stricitly prohibited, unless the prior
 * written consent of Ralink Technology, Inc. is obtained.
 ***************************************************************************

	Module Name:
	rtmp_mcu.c

	Abstract:

	Revision History:
	Who         When          What
	--------    ----------    ----------------------------------------------
*/


#include	"rt_config.h"

INT MCUBurstWrite(PRTMP_ADAPTER pAd, UINT32 Offset, UINT32 *Data, UINT32 Cnt)
{
#ifdef RTMP_USB_SUPPORT
	RTUSBMultiWrite_nBytes(pAd, Offset, (PUCHAR) Data, Cnt * 4, 64); 
#endif /* RTMP_USB_SUPPORT */
}

INT MCURandomWrite(PRTMP_ADAPTER pAd, RTMP_REG_PAIR *RegPair, UINT32 Num)
{
	UINT32 Index;
	
	for (Index = 0; Index < Num; Index++)
		RTMP_IO_WRITE32(pAd, RegPair->Register, RegPair->Value);
}

VOID ChipOpsMCUHook(PRTMP_ADAPTER pAd, enum MCU_TYPE MCUType)
{

	RTMP_CHIP_OP *pChipOps = &pAd->chipOps;



#ifdef CONFIG_ANDES_SUPPORT
	if (MCUType == ANDES) 
	{

#ifdef RTMP_USB_SUPPORT
		pChipOps->loadFirmware = andes_usb_loadfw;
#endif
		//pChipOps->sendCommandToMcu = andes_send_cmd_msg;
		pChipOps->MCUCtrlInit = andes_ctrl_init;
		pChipOps->MCUCtrlExit = andes_ctrl_exit;
		pChipOps->Calibration = (VOID*) andes_calibration;
		pChipOps->BurstWrite =  andes_burst_write;
		pChipOps->BurstRead = andes_burst_read;
		pChipOps->RandomRead = andes_random_read;
		pChipOps->RFRandomRead = andes_rf_random_read;
		pChipOps->ReadModifyWrite = andes_read_modify_write;
		pChipOps->RFReadModifyWrite = andes_rf_read_modify_write;
		pChipOps->RandomWrite = andes_random_write;
		pChipOps->RFRandomWrite = andes_rf_random_write;
		pChipOps->PwrSavingOP = andes_pwr_saving;
	}
#endif
}
