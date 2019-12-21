/*
 * Kedacom Hardware Abstract Level
 *
 * sys_wdt.h
 *
 * Copyright (C) 2015, Kedacom, Inc.
 *
 * History:
 *   2015/02/06 - Create
 *
 */

#ifndef _SYS_WDT_H
#define _SYS_WDT_H

__BEGIN_DECLS
#include <drvlib_def.h>
/*
 * Watch Dog Timer
 */
typedef struct
{
	int nTimeout;          /* in second */
} TWdParams;

typedef struct
{
	u8  byOpened;          /* 1 = opened */
	int nTimeout;          /* in second */
} TWdStatus;


#define RESET_MODE_HW         0x0 /* hardware reboot */
#define RESET_MODE_NORMAL     0x1 /* normal reboot */
#define RESET_MODE_POWEROFF   0x2 /* poweroff */
#define RESET_MODE_FASTBOOT   0x3 /* reboot to fastboot mode */
#define RESET_MODE_RECOVERY   0x4 /* reboot to recovery mode */


int SysOpenWdGuard(TWdParams *ptParams);
int SysCloseWdGuard(void);
int SysNoticeWdGuard(void);
int SysWdGuardStatusGet(TWdStatus *ptStatus);
int SysHwReset(int nNormalReboot);
int SysReset(int nRebootMode);


__END_DECLS

#endif
