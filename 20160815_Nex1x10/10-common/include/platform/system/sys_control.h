/*
 * Kedacom Hardware Abstract Level
 *
 * sys_control.h
 *
 * Copyright (C) 2015, Kedacom, Inc.
 *
 * History:
 *   2015/05/05 - Create
 *
 */

#ifndef _SYS_CONTROL_H
#define _SYS_CONTROL_H

__BEGIN_DECLS
#include <drvlib_def.h>

#define PWR_UP_INIT 0x1 /* bootloader status */
#define PWR_UP_IOS  0x2 /* kernel status */
#define PWR_UP_SUC  0x0 /* app status */

int SysSetBootStatus(u32 dwStatus);

__END_DECLS

#endif

