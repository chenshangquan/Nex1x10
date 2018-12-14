/*
 * Kedacom Hardware Abstract Level
 *
 * brd_clock.h
 *
 * Copyright (C) 2015, Kedacom, Inc.
 *
 * History:
 *   2015/02/09 - Create
 *
 */

#ifndef _BRD_RTC_H
#define _BRD_RTC_H

__BEGIN_DECLS
#include <drvlib_def.h>

int BrdTimeGet(struct tm *tTime);
int BrdTimeSet(const struct tm *tTime);
int BrdSetRtcToSysClock(void);
int BrdSetSysToRtcClock(void);

__END_DECLS

#endif

