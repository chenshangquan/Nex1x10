/*
 * Kedacom Hardware Abstract Level
 *
 * brd_info.h
 *
 * Copyright (C) 2015, Kedacom, Inc.
 *
 * History:
 *   2015/02/06 - Create
 *
 */

#ifndef _BRD_INFO_H
#define _BRD_INFO_H

__BEGIN_DECLS
#include <drvlib_def.h>

#ifndef USE_KLSP_DEFINES
/*
 * Product firmware infomation definition
 */
#define PINFO_USERDATA_LEN      64
#define PINFO_ISPDATA_LEN       4096

/* Flag0 defines */
#define PINFO_FLAG0_TEST        0x00000001 /* Test flag */
#define PINFO_FLAG0_TESTIP      0x00000002 /* Test IP address exist flag */
/* Flag1 defines */
#define PINFO_FLAG1_CMODE       0x00000001 /* 0-PAL, 1-NTSC */
#define PINFO_FLAG1_VOUT        0x00000006
#define PINFO_FLAG1_VOUT_PAL    0x00000002 /* Output PAL */
#define PINFO_FLAG1_VOUT_NTSC   0x00000004 /* Output NTSC */
#define PINFO_FLAG1_VOUT_VGA    0x00000006 /* Output VGA */

#else
/* refer to kernel/driver/klsp */
#include <base/product_info.h>
#endif /* USE_KLSP_DEFINES */

/* flag operation code */
#define FL0_TST_QUERY        0x01
#define FL0_TST_SET          0x02
#define FL0_TST_CLEAR        0x03
#define FL1_OMODE_GET        0x01
#define FL1_OMODE_SET        0x02
#define FL1_VMODE_GET        0X03
#define FL1_VMODE_SET        0X04

/* product info
 * NOTE : Don`t change the struct element order. TLV format no care it, 
 *        however, ARRAY format care it.
 */
typedef struct
{
	u32 dwProtect;           /* user defined write protect flag */
	u32 dwHwId;              /* product hardware ID */
	u32 dwPid;               /* product ID */
	u32 dwHwVer;             /* product hardware version */
	u32 dwHwSubVer;          /* product hardware sub version */
	u32 dwMdate;             /* product manufacture date, such as 20150210 */
	u32 dwFlag0;             /* see also PINFO_FLAG0_TEST */
	u32 dwFlag1;             /* see also PINFO_FLAG1_CMODE */
	u32 dwTestIp;            /* Test IP address */
	u8 abyFlowid[32];        /* product pipeline coding */
	u8 abyDevsq[32];         /* device serial number */
	u8 aabyEthMacAddr[4][6]; /* Eth MAC Address */
	u8 aabyWlanMacAddr[6];   /* WLAN MAC Address */
	u8 aabyBtMacAddr[6];     /* Bluetooth MAC Address */
	u8 abyUserData[PINFO_USERDATA_LEN + 1]; /* User defined data */
	u8 byEthMacNum;             /* Eth MAC number */
} TPrdInfo;

int BrdPinfoQuery(TPrdInfo *ptInfo);
int BrdPinfoClean(void);
int BrdIspdataClean(void);
int BrdPinfoUpdate(const TPrdInfo *ptInfo);
int BrdPinfoSetHwver(u32 dwHwver);
int BrdPinfoSetHwSubver(u32 dwSubVer);
int BrdPinfoSetHWID(u32 dwHwid);
int BrdPinfoSetPID(u32 dwPid);
int BrdPinfoFlag0Ops(int nOps, u32 dwArg);
int BrdPinfoFlag1Ops(int nOps, u32 dwArg);
int BrdPinfoSetUserdata(u8 *byData, int nLength);
int BrdPinfoSetIspdata(u8 *byData, int nOffset, int nCount);
int BrdPinfoGetIspdata(u8 *byData, int nOffset, int nCount);
int BrdPinfoGetHwSubver(u32 *byData);
int BrdPinfoGetAccId(u32 *byData);
int BrdPinfoSetAccId(u32 dwAccid);
int BrdPinfoGetHsver(u32 *byData);
int BrdPinfoSetHsver(u32 dwHsver);
int BrdPinfoGetCPU(u32 *byData);
int BrdPinfoSetCPU(u32 dwCpu);
int BrdPinfoGetSID(u32 *byData);
int BrdPinfoSetSID(u32 dwSid);
int BrdPinfoGetHver(u32 *byData);
int BrdPinfoSetHver(u32 dwHver);

/* board info: globle <struct brd_info board_cfg;> */
typedef struct
{
	char  achName[DRVLIB_NAME_MAX_LEN];   /* board name */

	u32   dwBrdId;     /* board id, may be = hwid of product info */
	u32   dwBrdVer;    /* board version, may be = hwver of product info */
	u32   dwPldVer;    /* EPLD/CPLD ver:D[31:24]= pld3 ... D[7:0]=pld3 */
	u32   dwFpgaVer;   /* FPGA version: D[31:24]=fpga3 ... D[7:0]=fpga0 */
	s32    nLayer;     /* < 0: no support; 0 - Max: layer ID stackable */
	s32    nSlot;      /* < 0: no support; 0 - Max: slot  ID inserted */

	u32   dwCpuNum;    /* total cpu number on board, include MCU */
	u32   dwCpuSelfNo; /* index for self-cpu: host-cpu must be 0 */

	u32   dwPldNum;    /* EPLD/CPLD number */
	u32   dwFpgaNum;   /* FPGA number */
	u16   wRtcNum;    /* Rtc number */
	u16   wEthNum;    /* Ethernet number */
	u16   wWlanNum;   /* WLAN number */
	u16   wBtNum;     /* Bluetooth number */
	u16   wE1Num;     /* E1 net Interface number */
	u16   wV35Num;    /* V35 net Interface number */
	u16   wSerialNum; /* serial number */
	u16   wFanNum;    /* Fan number */
	u16   wLedNum;    /* led number */
	u16   wButtonNum; /* button number */
	u16   wHwmonNum;  /* hardware monitor obj number, such as temperature voltage */
	u16   wOledNum;   /* oled screen number */
} TBrdInfo;


/* cpu info: globle <struct cpu_info board_cpus[CFG_CPU_NUM];> */
typedef struct
{
	u32   dwNo;         /* Input: 0 ~ cpu_num-1 */
	u32   dwId;         /* see also: CPU_ID_AMBA_A5S */
	u32   dwCpuFreq;    /* in MHz */
	u32   dwCab;        /* see also: CPU_CAB_HOST_LOAD_FW */
	u32   dwHostIntf;   /* see also: CPU_HOST_INTF_LBUS */

	u32   dwMemSize;    /* such as DDR3 size, in KB */
	u32   dwMemFreq;    /* such as DDR3 freq, in MHz */

	u32   dwNandSize;   /* nand flash size, in KB; 0 = no nand */
	u32   dwNandWidth;  /* nand flash width: 8 16 32 */

	u32   dwNorSize;    /* nor flash size, in KB; 0 = no nor */
	u32   dwNorWidth;   /* nor flash width: 8 16 32 */

	u32   dwMmcSize;    /* eMMC size, in KB; 0 = no eMMC */

	char  achName[DRVLIB_NAME_MAX_LEN];
} TCpuInfo;

int BrdInfoQuery(TBrdInfo *ptInfo);
int BrdCpuInfoQuery(TCpuInfo *ptInfo);

__END_DECLS

#endif
