/*
 * Kedacom Hardware Abstract Level
 *
 * brd_serial.h
 *
 * Copyright (C) 2015, Kedacom, Inc.
 *
 * History:
 *   2015/02/10 - Create
 *
 */

#ifndef _BRD_SERIAL_H
#define _BRD_SERIAL_H

__BEGIN_DECLS
#include <drvlib_def.h>


#ifndef USE_KLSP_DEFINES

#define SERIAL_RS232       0
#define SERIAL_RS422       1
#define SERIAL_RS485       2

/* serial usage */
#define SERIAL_CONSOLE     0
#define SERIAL_INFRARED    1
#define SERIAL_VISCA       2
#define SERIAL_COMMU       3

#endif /* USE_KLSP_DEFINES */


typedef struct
{
	u32   dwNo;       /* Input: 0 ~ serial_num-1 */
	u32   dwType;     /* see also: SERIAL_RS232 */
	u32   dwUsage;    /* see also: SERIAL_CONSOLE */
	u32   dwFixBaudrate; /* 0 = no limit; else fixed, such as 115200 */

	char  achName[DRVLIB_TTY_NAME_MAX_LEN]; /* name */
} TSerialInfo;

/*
 * Serial Defines
 */
#define SIO_SET_BAUDRATE     0x2000
#define SIO_GET_BAUDRATE     0x2001
#define SIO_SET_STOPBIT      0x2002
#define SIO_GET_STOPBIT      0x2003
#define SIO_SET_DATABIT      0x2004
#define SIO_GET_DATABIT      0x2005
#define SIO_SET_PARITY       0x2006
#define SIO_GET_PARITY       0x2007

#define SIO_PARITY_NONE      0
#define SIO_PARITY_ODD       1
#define SIO_PARITY_EVEN      2
#define SIO_PARITY_MARK      3
#define SIO_PARITY_SPACE     4

#define SIO_STOPBIT_1        0
#define SIO_STOPBIT_2        1

int BrdSerialQueryInfo(TSerialInfo *ptInfo);
int BrdSerialOpen(TSerialInfo *ptInfo);
int BrdSerialClose(int nFd);
int BrdSerialIoctl(int nFd, int nFunc, void *pArgs);
int BrdSerialRead(int nFd, u8 *pbyBuff, int nLength);
int BrdSerialWrite(int nFd, const u8 *pbyBuff, int nLength);
int BrdSerialSetMode(int nMode);
int BrdSerialSelConsole(int nCpuId);
/*====================================================================
 *  name       : BrdSerialCheckConsole
 *  function   : check tty on/off
 *  paramter   : none
 *  return   
 *       0: serial off
 *       1: serial on
 * ----------------------------------------------------------------------
 *<modify log>
 * time       : 3/20 2017
 * version    : 1.0
 * author     : quxuetong
 * details    : create
 *====================================================================*/
int BrdSerialCheckConsole(void);

__END_DECLS

#endif
