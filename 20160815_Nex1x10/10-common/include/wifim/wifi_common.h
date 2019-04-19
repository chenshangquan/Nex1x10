#ifndef _WIFI_COMMON_H
#define _WIFI_COMMON_H

#ifdef __cplusplus
extern "C" {
#endif

#include <syslog.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "wifi_station.h"
#include "utils/common.h"
#include "common/defs.h"

extern int nWifiLogSwitch;

#define WIFI_ERR(fmt, args...) \
				do{ \
					if (nWifiLogSwitch) \
					{ \
						printf("[WIFIM_ERR]:%s(%d): ", __func__, __LINE__); printf(fmt, ## args); \
						syslog(LOG_ERR, "[WIFIM_ERR]:%s(%d): ", __func__, __LINE__); syslog(LOG_ERR, fmt, ## args);\
					} \
				}while(0)

#define WIFI_PRT(fmt, args...) \
				do{ \
					if (nWifiLogSwitch) \
					{ \
						printf("[WIFIM_PRT]:%s(%d): ", __func__, __LINE__);printf(fmt, ## args); \
						syslog(LOG_NOTICE,"[WIFIM_PRT]: ");syslog(LOG_NOTICE,fmt, ## args);\
					} \
				}while(0)

#define WIFI_PERROR(buf) \
				do{ \
					if (nWifiLogSwitch) \
					{ \
						printf("[WIFI_PERROR]:%s(%d): %s{errno(%d):%s}\n", __func__, __LINE__, buf, errno, strerror(errno));\
						syslog(LOG_ERR, "[WIFI_PERROR]:%s(%d): %s{errno(%d):%s}\n", __func__, __LINE__, buf, errno, strerror(errno));\
					} \
				}while(0)

#ifdef WIFIM_DEBUG
#define WIFI_DBG(fmt, args...) \
				do{ \
					if (nWifiLogSwitch) \
					{ \
						printf("[WIFI_DBG]:%s(%d): ", __func__, __LINE__);printf(fmt, ## args); \
					} \
				}while(0)
#else
#define WIFI_DBG(fmt, args...) do { } while (0)
#endif

#define IEEE8021X_EAPOL    1
#define MAX_RECV_BUF_LEN   4096
#define MAX_CMD_LENGTH     1000
#define MAX_CMD_PRM        64
#define MAX_FILE_LENGTH    128
#define FILETYPE_ISDIRTORY 4
#define MAX_READ_BUF_LEN   512
#define MAX_WPS_CMD_LEN    256

#define WIFIM_SYSCMD_BUFF_SIZE	1024
/*needn't response*/
#define WIFIM_SYSCMD_REQ_0		0	/*不用返回状态与结果的请求*/
/*need exec status to response*/
#define WIFIM_SYSCMD_REQ_1		1	/*要返回执行状态的请求*/
/*need exec status&result to response*/
#define WIFIM_SYSCMD_REQ_2		2	/*要返回执行状态与执行结果的请求*/
/* exec sucess*/
#define WIFIM_SYSCMD_REPLY_SUCESS	0	/*执行成功*/
/*exec fail*/
#define WIFIM_SYSCMD_REPLY_FAILED	1	/*执行失败*/


/* All events coming from the supplicant start with this prefix */
#define   EVENT_PREFIX_STR  "CTRL-EVENT-"
#define   PASSWORD_MAY_BE_INCORRECT_STR "pre-shared key may be incorrect"
#define   WPA_EVENT_PREFIX_STR  "WPA:"

/* WPS events */
#define WPS_SUCCESS_STR "WPS-SUCCESS"
/* Format: WPS-FAIL msg=%d [config_error=%d] [reason=%d (%s)] */
#define WPS_FAIL_STR    "WPS-FAIL"
#define WPS_OVERLAP_STR "WPS-OVERLAP-DETECTED"
#define WPS_TIMEOUT_STR "WPS-TIMEOUT"
#define ASSOCIATED_STR "Associated with"

#define  WIFI_MAX_VERSION_LEN   (int)256

struct wifim_syscmd {
	/*请求类型或者返回状态*/
	unsigned int code;
	/*请求指令或者指令输出*/
	char data[WIFIM_SYSCMD_BUFF_SIZE];
};

struct wifim_msgbuf{
	/*内核线程号*/
	long mtype;

	/*传送信息体*/
	struct wifim_syscmd cmd;
};

typedef void (*sighandler_t)(int);/*from 3.13.0-24 define  __sighandler_t, so define this for previous version*/
int StrToData(char *pchBuf, char *pchOutput);
int ExecShellProcess(const char *pchFile, char *argv[], int *pnChildPid);
void IllStrtoStr(char *pchStr, const unsigned char *pchData, int nLen);
int BufToArgv(char *pchCmd, char *argv[], int nMaxParam, int nMaxLength, char chSepchar);
int StrStarts(const char *pchSrc, const char *pchMatch);
int WifimGetServicePid(char* pchPath, char* pchService);
TWifiConfigParam* WifiGetWpaConfig(char *pchIfName);
void WifiFreeWpaConfig(TWifiConfigParam* ptWpaConfig);
int WifiConfigWrite(char *pchIfName, TWifiConfigParam *ptConfig);
int StartProcess(char *pchCmd);
TWifiMNodeInfo* FindNodeFromGlobalInfo(char *pchIfName);
int RandNumber(int nMax, int nMin);
//if method is WIFIM_SYSCMD_REQ_2, should free *retbuf
int WifimSysExecCmd(char *cmd, char **retbuf, int method);
int CheckProcIsRun(char *process);
int WifiSetMode(char *ifname, char *mode);
#ifdef __cplusplus
}
#endif

#endif
