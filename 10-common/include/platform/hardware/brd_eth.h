/*
 * Kedacom Hardware Abstract Level
 *
 * brd_eth.h
 *
 * Copyright (C) 2015, Kedacom, Inc.
 *
 * History:
 *   2015/02/09 - Create
 *
 */

#ifndef _BRD_ETH_H
#define _BRD_ETH_H

__BEGIN_DECLS
#include <drvlib_def.h>
/*
 * Infomation & Peripherals definition
 */
#ifndef USE_KLSP_DEFINES
/*  eth type */
#define ETH_10M_HALF                    0
#define ETH_10M_FULL                    1
#define ETH_100M_HALF                   2
#define ETH_100M_FULL                   3
#define ETH_1000M_FULL                  4
#endif

/* The forced speed, 10Mb, 100Mb, gigabit, 2.5Gb, 10GbE. */
#define ETH_SPEED_AUTO       0
#define ETH_SPEED_10         10
#define ETH_SPEED_100        100
#define ETH_SPEED_1000       1000
#define ETH_SPEED_2500       2500
#define ETH_SPEED_10000      10000

/* Duplex, half or full. */
#define ETH_DUPLEX_HALF      0x00
#define ETH_DUPLEX_FULL      0x01
#define ETH_DUPLEX_AUTO      0x02

/* Enable or disable autonegotiation. */
#define ETH_AUTONEG_DISABLE  0x00
#define ETH_AUTONEG_ENABLE   0x01

typedef struct
{
	u32   dwNo;        /* Input: 0 ~ eth_num-1 */
	u32   dwType;      /* see also: ETH_10M_HALF */
	u8    abyMac[6];   /* MAC Address */
	char  achName[DRVLIB_NAME_MAX_LEN]; /* name */
} TEthInfo;


int BrdEthQueryInfo(TEthInfo *ptInfo);
int BrdEthGetLinkStat(u32 dwNo, int *pnLink);
int BrdEthGetNegStat(u32 dwNo, int *pnAutoNego, int *pnDuplex, int *pnSpeed);
int BrdEthSetNego(u32 dwNo, int nDuplex, int nSpeed);

__END_DECLS

#endif
