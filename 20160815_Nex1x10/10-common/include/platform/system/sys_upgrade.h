/*
 * Kedacom Hardware Abstract Level
 *
 * sys_upgrade.h
 *
 * Copyright (C) 2015, Kedacom, Inc.
 *
 * History:
 *   2015/02/09 - Create
 *
 */

#ifndef _SYS_UPGRADE_H
#define _SYS_UPGRADE_H

__BEGIN_DECLS
#include <drvlib_def.h>

#define UGR_CHECK_ONLY      (1<<0) /* do package validity check only */
#define UGR_REBOOT_AUTO     (1<<1) /* auto reboot after upgrade */
#define UGR_WIPE_USER_DATA  (1<<2) /* wipe user data partition, for Android */
#define UGR_WIPE_CACHE      (1<<3) /* wipe cache data partition, for Android */

/*
 * Master system upgrade calls
 */
int SysUpgradeDoUgAll(const char *filename, u32 flag);
int SysUpgradeDoUgboot(const char *filename, u32 flag);
int SysUpgradeDoUgDtb(const char *filename, u32 flag);
int SysUpgradeDoUgFpga(const char *filename, u32 flag);
int SysUpgradeDoUgPic(const char *filename, u32 flag);
int SysUpgradeDoUgIos(const char *filename, u32 flag);
int SysUpgradeDoUgRecovery(const char *filename, u32 flag);
int SysUpgradeDoUgPqparam(const char *filename, u32 flag);
int SysUpgradeDoUgBaseparam(const char *filename, u32 flag);
int SysUpgradeDoUgVcmt(const char *filename, u32 flag);
int SysUpgradeDoUgApp(const char *filename, u32 flag);
int SysMntAppBak(void);
int SysMntVcmtBak(void);
int SysUpgradeDev(const char *szFileName, u32 nFlags);
int SysUpgradeCleanEnv(void);
int SysUpgradeReport(u32 *pdwReport);
int SysUpgradeGetVerbose(const char *szFileName, u8 *pchVerbose);
//int SysSwitchSystem(int nSysId);
int SysSwitchSystem(void);
int SysRunSuccess(void);
int SysSetRoll(u32 flag);
int SysGetRoll(u32* flag);
int SysUpgradeScm(u32 dwDevId, const char *szFileName);
#define SYS_RUN_NOR    0
#define SYS_RUN_FAIL   1
#define SYS_RUN_SUC    2

/*
 * FPAG Defines
 */
#define FPGA_PROGRAM_PROGRESS   0
#define FPGA_PROGRAM_START      1
#define FPGA_PROGRAM_END        2

/*
 * FPGAs calls
 */
int SysLoadFpga(int nForce, const char *szFilenName);
int SysProgramFpga(const char *byData, int nLength, int nInProgress);

/*
 * For backup system
 */

/*
 * backup part.
 */
#define BACKUP_IOS	0x1	/* update.linux or zImage+ramdisk */
#define BACKUP_APP	0x2	/* app.img */
#define BACKUP_ALL	0x3	/* IOS+APP */

//int SysBackUp(u32 part);
int SysBackUp(void);

#define NORMAL		(0)
#define ABNORMAL	(-1)

/*
*Get the pair partition stat
*Return Vaule:
*     NORMAL(0) the pair partition's version is ok,it can run.
*     ABNORMAL(-1) the pair parition's version is fail,it can't run.
*
*/
int SysGetPPStat(void);

/*
*Disable the Backup capability.

*the system will not backup if the system can't run
*Return Value:
	0:	Succ
	-1:	Fail
*/

int SysDisableBackUp(void);

/*
 * Enable the recover capability.
 * 	the system will not recover if the system can't run when disable.
 * 	Default is enable in system.
 *
 * @param:
 * 	0 : disable
 * 	1 : enable
 *
 * @Return Value:
 *	0:	Succ
 *	-1:	Fail
 */

int SysEnableRecover(int enable);

__END_DECLS

#endif
