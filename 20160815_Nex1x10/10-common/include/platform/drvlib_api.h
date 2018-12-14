/*
 * Kedacom Hardware Abstract Level
 *
 * drvlib_api.h
 *
 * Copyright (C) 2015, Kedacom, Inc.
 *
 * History:
 *   2015/02/06 - Create
 *
 */

#ifndef __DRVLIB_API_H
#define __DRVLIB_API_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <errno.h>


#include <drvlib_def.h>

#include <hardware/brd_btn.h>
#include <hardware/brd_eth.h>
#include <hardware/brd_hwmon.h>
#include <hardware/brd_info.h>
#include <hardware/brd_led.h>
#include <hardware/brd_misc.h>
#include <hardware/brd_rtc.h>
#include <hardware/brd_serial.h>
#include <hardware/brd_oled.h>
#include <hardware/brd_usb.h>
#include <hardware/brd_touch.h>

#include <dspcci/dspcci_api_host.h>
#include <dspcci/dspcci_common.h>

#include <system/sys_control.h>
#include <system/sys_upgrade.h>
#include <system/sys_wdt.h>
#include <system/sys_firmware.h>
#include <video/vid_intf.h>
#include <video/vid_sensor.h>
#include <video/vid_lens.h>
#include <video/vid_ptz.h>

#include <audio/aud_intf.h>
#include <audio/aud_msnd.h>

__BEGIN_DECLS

/*
 * Module Versions
 */
typedef struct
{
	u32 dwModVersion;
	u32 dwModSubvers;
	char *pchAndroidVer;
	char *pchKernelVer;
	char *pchBootVer;
} TDrvVersions;

/*
 * DrvLib log level defines
 */
#define DRV_CON_LOG_LVL_NONE     0x00
#define DRV_CON_LOG_LVL_ERR      0x01
#define DRV_CON_LOG_LVL_WARNING  0x02
#define DRV_CON_LOG_LVL_INFO     0x03
#define DRV_CON_LOG_LVL_DEBUG    0x04

int DrvModuleInit(void);
int DrvModuleExit(void);

int DrvVersionGet(TDrvVersions *ptVers);

void DrvLogSetConsoleLevel(int nLevel);

__END_DECLS

#endif
