#ifndef _WIFI_NETLINK_H
#define _WIFI_NETLINK_H

#ifdef __cplusplus
extern "C" {
#endif


#include <sys/types.h>
#include <sys/socket.h>
#include <asm/types.h>
#include <linux/socket.h>
#include <linux/netlink.h>
#include <pthread.h>
#include <time.h>
#include "common/defs.h"

#include "wifi_api.h"

#define WIFIM_COL_DIR     "/tmp/"

#define WIFIM_START_NETLINK        "Start NetLink"
#define WIFIM_STOP_NETLINK         "Stop NetLink"
#define WIFIM_CLEAR_FAKEMAC        "Enable ClearFakeMac"
#define WIFIM_SAVE_FAKEMAC         "Disable ClearFakeMac"
#define WIFIM_COLLECT_APINFO       "Enable CollectApInfo"
#define WIFIM_DISABLE_COLLECT_APINFO       "Disable CollectApInfo"

#define WIFIM_USER_NETLINK     25
#define WIFIM_MAX_MSGLEN       1024
#define WIFIM_MAX_RECORD       15
#define WIFIM_COL_MTIMEACC     10
#define WIFIM_COL_ATIMEINT     600
#define WIFIM_COL_ITIMEINT     10
#define WIFIM_COL_SIZE         5*1024*1024
#define WIFIM_COL_MSIZE        100*1024*1024
#define WIFIM_COL_NUM          10
#define WIFIM_COL_MNUM         50
#define WIFIM_COL_BUF          128

typedef enum mNetLinkErr {
	NET_ERROR,
	NET_OK,
	NET_MEM,
	NET_SOCK,
} MNetLinkErr;

typedef struct tNetLinkSock {
	int sock;
	struct sockaddr_nl dest;
	struct sockaddr_nl src;
} TNetLinkSock;

typedef struct tIEEEInfo {
	unsigned char nIfType;
	unsigned char chIEEEType;
	unsigned char chIEEESType;
	unsigned char achSmac[WIFIM_MAC_LEN];
	unsigned char achDmac[WIFIM_MAC_LEN];
	unsigned char achBssid[WIFIM_MAC_LEN];
	signed char nChannel;
	signed char nRssi;
	time_t tFirTime;
	unsigned char nAuth;//dev_type is ap,should set ap auth
	unsigned char achSsid[WIFIM_SSID_LEN];//dev_type is ap, should set ap ssid
} TIEEEInfo;

typedef struct tMacData {
	unsigned char chIfType;
	unsigned char chIEEEType;
	unsigned char chIEEESType;
	unsigned char achSmac[WIFIM_MAC_LEN];
	unsigned char achDmac[WIFIM_MAC_LEN];
	unsigned char achBssid[WIFIM_MAC_LEN];
	unsigned char nChannel;
	signed char nRssi;
	time_t tFirTime;
	unsigned char nAuth;//dev_type is ap,should set ap auth
	unsigned char achSsid[WIFIM_SSID_LEN];//dev_type is ap, should set ap ssid
	struct tMacData *next;
} TMacData;

typedef struct WifiCollectInfo{
	char *ctrl_ifname;
	char achFilePath[WIFIM_MAX_PATH_LEN];
	int nProtocol;
	int nNlPid;
	int nTimeAccur;
	int nFileTimeInter;
	int nFileMaxNum;
	int nFileMaxSize;
	pthread_t netlink_thread;
	pthread_mutex_t netlink_mutex;
	TMacData *ptMacInfo;
	Boolean bNetlinkStart;
	WifiMColNotifyCallBack ptColCallbackMsg;
}TWifiCollectInfo;

typedef struct WifiMColMacInfo {
	int nDevType;                 /* the device type , ap or station*/
	char achMac[WIFIM_MAC_LEN];   /* the device mac */
	time_t FirTime;               /* time of first collect the device */
	time_t LastTime;              /* time of last collect the device*/
	int nTimes;                   /* the times of device be collected*/
	struct WifiMColMacInfo *next;
} TWifiMColMacInfo;


int InitColInfo(TWifiCollectInfo *ptWifiColInfo, TWifiMColRegInfo *ptWifimColRegInfo);
int WifiGetColInfo(TWifiCollectInfo *ptWifiColInfo, TWifiMColMacInfo **ptColMacInfo);
int DeInitColInfo(TWifiCollectInfo *ptWifiColInfo);
int WifiStartCollect(char *pchIfName, TWifiCollectInfo *ptWifiColInfo);
int WifiStopCollect(TWifiCollectInfo *ptWifiColInfo);
int WifiNetlinkSendMsg(char *pchMsg);
int CheckColParam(TWifiMColRegInfo *ptWifimColRegInfo);

#ifdef __cplusplus
}
#endif

#endif
