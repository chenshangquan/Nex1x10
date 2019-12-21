/*
 * Kedacom Hardware Abstract Level
 *
 * brd_hwmon.h
 *
 * Copyright (C) 2015, Kedacom, Inc.
 *
 * History:
 *   2015/02/06 - Create
 *
 */

#ifndef _BRD_HWMON_H
#define _BRD_HWMON_H

__BEGIN_DECLS
#include <drvlib_def.h>

#ifndef USE_KLSP_DEFINES

/*
 * Hardware monitor definition
 * use u32 type variable
 *   D[31:16]: hwmon type
 *   D[ 7: 0]: index for each hwmon type
 */
#define HWMON_NO_SHIFT          0
#define HWMON_NO_MASK           0xff
#define HWMON_NO(v)             (((v) >> HWMON_NO_SHIFT) & HWMON_NO_MASK)

#define HWMON_TYPE_SHIFT        16
#define HWMON_TYPE_MASK         0xffff
#define HWMON_TYPE(v)           (((v) >> HWMON_TYPE_SHIFT) & HWMON_TYPE_MASK)

#define HWMON_ID(type, no) \
        (((type) << HWMON_TYPE_SHIFT) | \
         ((no)   << HWMON_NO_SHIFT))

#define HWMON_TYPE_LINE_IN      0 /* line input  on/off */
#define HWMON_TYPE_LINE_OUT     1 /* line output on/off */
#define HWMON_TYPE_FAN_SPEED    2 /* fan speed */
#define HWMON_TYPE_TEMP         3 /* temperature */
#define HWMON_TYPE_VOLT         4 /* voltage */
#define HWMON_TYPE_BRIGHT       5 /* brightness */
#define HWMON_TYPE_HEATER       6 /* heater */
#define HWMON_TYPE_MAGNETIC     7 /* 3-axis digital magnetometer */
#define HWMON_TYPE_ACCELE       8 /* 3-axis digital accelerometer */
#define HWMON_TYPE_PRESSURE     9 /* pressure */
#define HWMON_TYPE_HUMIDITY     10 /* humidity */

#define HWMON_ID_FAN_SPEED(n)   HWMON_ID(HWMON_TYPE_FAN_SPEED, n)
#define HWMON_ID_TEMP(n)        HWMON_ID(HWMON_TYPE_TEMP, n)
#define HWMON_ID_VOLT(n)        HWMON_ID(HWMON_TYPE_VOLT, n)
#define HWMON_ID_MAGNETIC(n)    HWMON_ID(HWMON_TYPE_MAGNETIC,  n)
#define HWMON_ID_ACCELE(n)      HWMON_ID(HWMON_TYPE_ACCELE,  n)
#define HWMON_ID_PRESSURE(n)    HWMON_ID(HWMON_TYPE_PRESSURE,  n)
#define HWMON_ID_HUMIDITY(n)    HWMON_ID(HWMON_TYPE_HUMIDITY,  n)

#endif /* USE_KLSP_DEFINES */

/* fan info: globle <struct fan_info board_fans[CFG_FAN_NUM];> */
typedef struct
{
	u32   dwCab;        /* see also: FAN_CAB_SPEED_SET */
	u32   dwSpeedMax;  /*  rotate speed, in RPM or 0-100(%) */
	u32   dwSpeedCur;  /* cuttent rotate speed, in RPM or 0-100(%) */
	u32   dwSpeedAlarm;/* if (speed_cur < speed_alarm) report alarm */
} TFanInfo;

/* temperature info */
typedef struct
{
	s32   dwCur;        /* cuttent temperature, in 0.001 degree C */
	s32   dwAlarmMin;  /* if (cur < alarm_min) report alarm */
	s32   dwAlarmMax;  /* if (cur > alarm_max) report alarm */
} TTempInfo;

/* pressure info */
typedef struct
{
	s32   dwCur;        /* cuttent pressure, in hPa */
	s32   dwAlarmMin;  /* if (cur < alarm_min) report alarm */
	s32   dwAlarmMax;  /* if (cur > alarm_max) report alarm */
} TPreInfo;

/* humidity info */
typedef struct
{
	s32   dwCur;        /* cuttent humidity, in % */
	s32   dwAlarmMin;  /* if (cur < alarm_min) report alarm */
	s32   dwAlarmMax;  /* if (cur > alarm_max) report alarm */
} THumidityInfo;

/* voltage info */
typedef struct
{
	s32   dwCur;        /* cuttent voltage, in mVolt */
	s32   dwAlarmMin;  /* if (cur < alarm_min) report alarm */
	s32   dwAlarmMax;  /* if (cur > alarm_max) report alarm */
} TVoltInfo;

/* brightness info */
typedef struct {
        u32   dwCur;        /* cuttent brightness, in LM */
        u32   dwAlarmMin;  /* if (cur < alarm_min) report alarm */
        u32   dwAlarmMax;  /* if (cur > alarm_max) report alarm */
}TBrightInfo;

/* magnetometer info */
typedef struct {
	s32   x; /* X-axis 16-bit output sample data of the magnetic field
	            strength expressed as signed 2's complement numbers */
	s32   y; /* Y-axis 16-bit output sample data of the magnetic field
	            strength expressed as signed 2's complement numbers */
	s32   z; /* Z-axis 16-bit output sample data of the magnetic field
	            strength expressed as signed 2's complement numbers */
}TMagneticInfo;

/* accelerometer info */
typedef struct {
	s32   x; /* X-axis measured acceleration data */
	s32   y; /* Y-axis measured acceleration data */
	s32   z; /* Z-axis measured acceleration data */
}TAcceleInfo;

/* heater info */
typedef struct {
	u32   id;         /* device id */
	u32   on_off;     /* switch for heater 1:on 0:off */
	u32   temper;     /* heater temperature, in 0.001 degree C */
}THeatInfo;

typedef struct
{
	u32   dwNo;    /* Input: 0 ~ hwmon_num-1 */

	u32   dwId;    /* see also: HWMON_ID_TEMP */
	char  achName[DRVLIB_NAME_MAX_LEN]; /* hwmon obj name */
} THwmonInfo;

typedef struct
{
	u32   dwId;    /* see also: HWMON_ID_TEMP */
	int   nAlarm;  /* hwmon state: 0 = normal; 1 = alarm on */

	union
	{
		u8 abyParam[256];
		TFanInfo    tFan;
		TTempInfo   tTemp;
		TPreInfo    tPressure;
		THumidityInfo tHumidity;
		TVoltInfo   tVolt;
		TBrightInfo tBright;
		TMagneticInfo tMagnetic;
		TAcceleInfo tAccele;
		THeatInfo tHeater;
	} tEntry;           /* append param for each HWMON_TYPE(id) */
} THwmonStat;

int BrdHwmonQueryInfo(THwmonInfo *ptInfo);
int BrdHwmonGetStatus(THwmonStat *ptStatus);
int BrdHwmonSetStatus(THwmonStat *ptStatus);

__END_DECLS

#endif
