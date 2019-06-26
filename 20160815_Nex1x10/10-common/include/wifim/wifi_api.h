#ifndef _WIFI_API_H
#define _WIFI_API_H

#ifdef __cplusplus
extern "C" {
#endif
#include <time.h>
#include <arpa/inet.h>
#define WIFIM_PROTO_TYPE_IPV4 AF_INET      /*ipv4*/
#define WIFIM_PROTO_TYPE_IPV6 AF_INET6     /*ipv6*/
#define WIFIM_PROTO_TYPE_ALL (AF_INET6+1) /* ipv4+ipv6 */

/* IPv6地址类型 */
typedef enum{
    WIFIM_SCOPE_TYPE_DEF = 0, /* 默认使用WIFIM_SCOPE_TYPE_GLOBAL类型 */
    WIFIM_SCOPE_TYPE_HOST,
    WIFIM_SCOPE_TYPE_LINK, /* LINK地址, 此类型地址不可修改 */
    WIFIM_SCOPE_TYPE_SITE,
    WIFIM_SCOPE_TYPE_GLOBAL,
}EWifimScopeType;
typedef struct tagWifimAddr
{
    unsigned int wSinFamily;  /* WIFIM_PROTO_TYPE_IPV4 or WIFIM_PROTO_TYPE_IPV6 */
    union{
        struct in_addr tV4Addr;
        struct in6_addr tV6Addr;
    };
}TWifimAddr;

typedef struct{
    EWifimScopeType eScopeType; /* 默认值0为SCOPE_GLOBAL */
    TWifimAddr tIpAddr;         /* 网络字节序 */
    unsigned int dwPrefix;                /* 主机字节序 */
}TWifimIfaceIp;

typedef enum{
    WIFIM_INET_IPV4 = 0,
    WIFIM_INET_IPV6,
    WIFIM_INET_ALL,
}EWifimInetType;

typedef struct in6_addr TWiFimInaddrV6;
typedef struct in_addr TWiFimInaddrV4;

/* Wifi Mode */
#define WIFIM_MODE_STA     0
#define WIFIM_MODE_AP      1
#define WIFIM_MODE_SWITCH  2
#define WIFIM_MODE_MONITOR 3

#define WIFIM_CLEAN_CONFIG_FILE        0    /* clean all the wifi config file */
#define WIFIM_NOT_CLEAN_CONFIG_FILE    1    /* not clean all the config file */


/* Len define */
#define WIFIM_IFNAME_LEN        8
#define WIFIM_PINCODE_LEN       9
#define WIFIM_MAX_PATH_LEN      512
#define WIFIM_BSSID_LEN         18    /* The len of SSID's MAC */
#define WIFIM_IP_LEN        16    /*The len of ip*/
#define WIFIM_IPV6_LEN      64    /*The len of ipv6*/
#define WIFIM_STA_NAME_LEN  20    /*The sta name len*/
#define WIFIM_SSID_MAXLEN       32    /* The MAX len of SSID */
#define WIFIM_PASSWD_LEN        64    /* The MAX len of Password */
#define WIFIM_MAX_DNS_SERVER    16    /* The MAX number of DNS */

/* The Struct To Notice User Dhcp-assigned IP Configuration */
typedef struct WifiMIPAddrMsg{
    char         achIFName[WIFIM_IFNAME_LEN];
    /* IP config mode :DHCP/STATIC */
    int          nIPMode;
    /* get or lose ip address, Network Byte Order */
    unsigned int dwIpAddrs;
    /* get or lose ip netmask, Network Byte Order */
    unsigned int dwMask;
    /* get or lose default gateway, Network Byte Order */
    unsigned int dwGateWay;
    int          nDnsMode;
    /* the max number of DNS Server can be 64 */
    unsigned int dwDnsNum;
    /* get or lose DNS Server address,Network Byte Order */
    unsigned int dwDnsServer[WIFIM_MAX_DNS_SERVER];
    EWifimScopeType scope;/*ip address type*/
    unsigned int       dwIPModeV6;
    unsigned int       dwDnsModeV6;
    TWiFimInaddrV6     tIpAddrsv6;
    TWiFimInaddrV6     tGateWayv6;
    unsigned int  dwPrefixv6;
    unsigned int dwDnsNumv6;
    TWiFimInaddrV6     tDnsServerv6[WIFIM_MAX_DNS_SERVER];
}TWifiMIPAddrMsg;

typedef struct WifiMStationInfo{
    char  achBssid[WIFIM_BSSID_LEN];
}TWifiMStaInfo;

typedef struct WifiMAPInfo{
    char  achBssid[WIFIM_BSSID_LEN];
    char  achSsid[WIFIM_SSID_MAXLEN+1];
    short nFrequency;
}TWifiMAPInfo;

/*
 * Signal levels as used by notification icon
 * Level 4  -55 <= CurSignal
 * Level 3  -66 <= CurSignal < -55
 * Level 2  -77 <= CurSignal < -67
 * Level 1  -88 <= CurSignal < -78
 * Level 0         CurSignal < -88
 */

typedef struct WifiMLinkQuality{
    int CurSignal;
    int CurLinkSpeed;
}TWifiMLinkQuality;

typedef struct{
    int nMsgTypy;
    union{
        TWifiMIPAddrMsg tIPAddr;              /* WIFIM_MSG_CONNECTED CBMSG */
        TWifiMStaInfo   tStaInfo;             /* only AP used */
        TWifiMAPInfo    tAPInfo;              /* WIFIM_MSG_LINK_QUALITY CBMSG */
        TWifiMLinkQuality   tLinkQuality;     /* WIFIM_MSG_CONNECTING CBMSG */
        char       achPinCode[WIFIM_PINCODE_LEN]; /* wps dynamic pin code */
        void       *pMsg;
    }UMsg;
}TWifiMNotify;

/* Dhcp Server Config Msg */
typedef struct{
    unsigned int IsAssignDns;  /* 0: using default dns; 1: use assigned DNS */
    unsigned int dwDnsIp;      /* DNS's IP address , Network Byte Order */
    char         *pchDnsName;  /* DNS's name */
}TWifiMDhcpSerVDnsInfo;

/* Dhcp Server Ethernet Configuration Structure */
typedef struct{
    /* Network Byte Order : SubNetMask */
    unsigned int dwSubNetMask;
    /* Network Byte Order:	assign start address */
    unsigned int dwIpPoolStart;
    /* Network Byte Order : assign end address */
    unsigned int dwIpPoolEnd;
    /* Network Byte Order : default gateway or route address */
    unsigned int dwRoutes;
    /* Network Byte Order: dhcp server's IP address */
    unsigned int dwEthIp;
}TWifiMDhcpSerVEthInfo;

/* Dhcp Configuration Structure */
typedef struct{
    char *pchIfName;
    TWifiMDhcpSerVEthInfo tDhcpServerEthInfo;
    TWifiMDhcpSerVDnsInfo tDhcpServerDnsInfo;
}TWifiMDhcpSerVConfInfo;

typedef struct{
    /* Network Byte Order : dwPrefixV6 */
    unsigned int dwPrefixV6;
    unsigned int dwScope;
    /*for example :fec0:db8:0:1::/64,relation to dwIpPoolStartV6&dwIpPoolEndV6*/
    char achSubnet[128];
    /* Network Byte Order:  assign start address V6 */
    TWiFimInaddrV6       dwIpPoolStartV6;
    /* Network Byte Order : assign end address V6*/
    TWiFimInaddrV6       dwIpPoolEndV6;
    /* Network Byte Order : default gateway or route address V6*/
    TWiFimInaddrV6       dwRoutesV6;
    /* Network Byte Order: dhcp server's IP address V6*/
    TWiFimInaddrV6       dwEthIpV6;
}TWifiMDhcpSerVEthInfoV6;
typedef struct{
    unsigned int IsAssignDns;  /* 0: using default dns; 1: use assigned DNS */
    TWiFimInaddrV6 dwDnsIpV6;      /* DNS's IP address , Network Byte Order */
    char *pchDnsName;  /* DNS's name */
}TWifiMDhcpSerVDnsInfoV6;

typedef struct{
    char *pchIfName;
    TWifiMDhcpSerVEthInfoV6 tDhcpServerEthInfoV6;
    TWifiMDhcpSerVDnsInfoV6 tDhcpServerDnsInfoV6;
}TWifiMDhcpSerVConfInfoV6;
typedef int(*WifiMSTANotifyCallBack)(TWifiMNotify *ptWifiMNotify);
typedef int(*WifiMAPNotifyCallBack)(TWifiMNotify *ptWifiMAPNotify);

typedef  struct WifiMStaRegisterInfo{
    char *pchIfName;
    WifiMSTANotifyCallBack WifiMSTANotifyCB;
} TWifiMStaRegInfo;

typedef  struct WifiMAPRegisterInfo{
    char *pchIfName;
    WifiMAPNotifyCallBack  WifiAPNotifyCB ;
}TWifiMAPRegInfo;

typedef  struct WifiMRegisterInfo{
    int nIndex;
    int nWifiMode;
    char *pchDrvPath;
    /* default null, or such as /lib/modules/3.4.35/extra/8188eu.ko */
    TWifiMStaRegInfo *ptStaRegInfo;
    TWifiMAPRegInfo *ptAPRegInfo;
}TWifiMRegInfo;

/* API Return Value */
#define  WIFIM_OK                 (int)0
#define  WIFIM_ERR_PARAM          (int)1    /* parameter error */
#define  WIFIM_ERR_CREATESOCK     (int)2    /* create socket failed */
#define  WIFIM_ERR_SCAN           (int)3    /* scan failed */
#define  WIFIM_ERR_SCANRESULTS    (int)4    /* get scan result failed */
#define  WIFIM_ERR_ADDNETWORK     (int)5    /* add a network failed */
#define  WIFIM_ERR_SETNETWORK     (int)6    /* set a network failed */
#define  WIFIM_ERR_ENABLENETWORK  (int)7    /* enable a network failed */
#define  WIFIM_ERR_DISABLENETWORK (int)8    /* disable a network failed */
#define  WIFIM_ERR_REMOVENETWORK  (int)9    /* remove a network failed */
#define  WIFIM_ERR_DISCONNECT     (int)10   /* disconnect a network failed */
#define  WIFIM_ERR_WPSPIN         (int)11   /* WPS_PIN method failed */
#define  WIFIM_ERR_WPSPBC         (int)12   /* WPS_PBC method failed */
#define  WIFIM_ERR_WPSCANCEL      (int)13   /* WPS_CANCEL failed */
#define  WIFIM_ERR_STATUS         (int)14   /* get status failed */
#define  WIFIM_ERR_SIGNAL_POLL    (int)15   /* signal poll failed */
#define  WIFIM_ERR_LOADDRIVER     (int)16   /* load driver faile */
#define  WIFIM_ERR_UNINITIAL      (int)17   /* did not initialed */
#define  WIFIM_ERR_SYSERR         (int)18   /* system call error */
#define  WIFIM_ERR_FILE           (int)19   /* access file error */
#define  WIFIM_ERROR_DHCPD_IPV4   (int)20
#define  WIFIM_ERROR_DHCPD_IPV6   (int)21
#define  WIFIM_ERROR_DHCPD_ALL    (int)22
#define  WIFIM_ERROR              (int)100



/* Msg Type */
#define  WIFIM_MSG_BASE             (int)1000
/* connecting to a AP */
#define  WIFIM_MSG_CONNECTING       (int)(WIFIM_MSG_BASE+1)
/* connect to a AP & assign a IP address */
#define  WIFIM_MSG_CONNECTED        (int)(WIFIM_MSG_BASE+2)
/* connect to ap failed */
#define  WIFIM_MSG_CONNECTED_FAILED (int)(WIFIM_MSG_BASE+3)
/* DHCP failed*/
#define  WIFIM_MSG_DHCP_FAILED      (int)(WIFIM_MSG_BASE+4)
/* DHCP failed*/
#define  WIFIM_MSG_DHCP_RENEW       (int)(WIFIM_MSG_BASE+5)
/* disconnect to a AP */
#define  WIFIM_MSG_DISCONNECTED     (int)(WIFIM_MSG_BASE+6)
/* lose connect to wpa_s server */
#define  WIFIM_MSG_WPAS_DISCONN     (int)(WIFIM_MSG_BASE+7)
/* authorize failed */
#define  WIFIM_MSG_AUTH_FAILURE     (int)(WIFIM_MSG_BASE+8)
/* password error */
#define  WIFIM_MSG_PWD_ERROR        (int)(WIFIM_MSG_BASE+9)
/* rejected associating by AP */
#define  WIFIM_MSG_AP_REJECT        (int)(WIFIM_MSG_BASE+10)
/* connect to a AP & assign a IP address */
#define  WIFIM_MSG_CONNECTED_IPV6        (int)(WIFIM_MSG_BASE+11)
/* connect to ap failed */
#define  WIFIM_MSG_CONNECTED_FAILED_IPV6 (int)(WIFIM_MSG_BASE+12)
/* DHCP failed*/
#define  WIFIM_MSG_DHCP_FAILED_IPV6      (int)(WIFIM_MSG_BASE+13)
/* DHCP failed*/
#define  WIFIM_MSG_DHCP_RENEW_IPV6       (int)(WIFIM_MSG_BASE+14)
/* DHCP failed*/
#define  WIFIM_MSG_DHCP_IPV6_START_FAIL   (int)(WIFIM_MSG_BASE+15)
/* DHCP failed*/
#define  WIFIM_MSG_DHCP_IPV4_START_FAIL   (int)(WIFIM_MSG_BASE+16)
/* connect to a AP & assign a IP address */
#define  WIFIM_MSG_CONNECTED_INVALID   (int)(WIFIM_MSG_BASE+100)




/* wps msg type */
#define  WIFIM_MSG_WPS_SUCCESS      (int)(WIFIM_MSG_BASE+20) /* WPS succeed */
#define  WIFIM_MSG_WPS_FAILED       (int)(WIFIM_MSG_BASE+21) /* WPS failed */
#define  WIFIM_MSG_WPS_TIMEOUT      (int)(WIFIM_MSG_BASE+22) /* WPS overtime */
#define  WIFIM_MSG_WPS_PINCODE      (int)(WIFIM_MSG_BASE+23) /* WPS failed */

/* AP Callback Msg Type */
/* increase a connected station to ap */
#define  WIFIM_MSG_AP_INC_STA       (int)(WIFIM_MSG_BASE+30)
/* a station disconnected from ap */
#define  WIFIM_MSG_AP_DEC_STA       (int)(WIFIM_MSG_BASE+31)
/* Link Quality of wifi */
#define  WIFIM_MSG_LINK_QUALITY     (int)(WIFIM_MSG_BASE+40)

/* Resolv.conf Keywords */
/* define DNS server 's IP address */
#define  WIFIM_DNS_KEYWORD_NAMSERV    (const char*)"nameserver"
/* define local domain */
#define  WIFIM_DNS_KEYWORD_DOMAIN     (const char*)"domain"

/* Wps Method */
#define  WIFIM_WPS_PIN_METHOD   0
#define  WIFIM_WPS_PBC_METHOD   1 /* default, pbc method */

/* Priority Command */
#define  WIFIM_PRIO_LOWEST   0
#define  WIFIM_PRIO_HIGEST   1
#define  WIFIM_PRIO_UP       2
#define  WIFIM_PRIO_DOWN     3

/* Wep */
#define  WIFIM_NUM_WEP_KEYS     4
#define  WIFIM_WEP_KEY_LEN 16

enum EWifiMStates {
    WIFIM_STATE_DISCONNECTED,
    WIFIM_STATE_INTERFACE_DISABLED,
    WIFIM_STATE_INACTIVE,
    WIFIM_STATE_SCANNING,
    WIFIM_STATE_AUTHENTICATING,
    WIFIM_STATE_ASSOCIATING,
    WIFIM_STATE_ASSOCIATED,
    WIFIM_STATE_4WAY_HANDSHAKE,
    WIFIM_STATE_GROUP_HANDSHAKE,
    WIFIM_STATE_COMPLETED,
    WIFIM_STATE_AP_REJECT,
    WIFIM_STATE_PWD_ERROR
};

/* Ecryption Method */
enum EWifiMMode{
    WIFIM_EM_NONE = 1,
    WIFIM_EM_WEP = 2,
    WIFIM_EM_WPA = 4,
    WIFIM_EM_WPA2 = 8
};

typedef struct WifiMSBSSIDItem{
        struct WifiMSBSSIDItem *next;
        char   abyBSSIDMac[WIFIM_BSSID_LEN];   /* AP 's MAC address */
        char   abySSID[WIFIM_SSID_MAXLEN + 1]; /* AP 's ssid */
        int    nEncryptMode;
        int    nSignal;
        void   *Reserve[0];
}TWifiMSBSSIDItem;

/* Network type */
typedef enum WifiMSNetType {
        NT_INFRA = 0,
        NT_IBSS = 1,
        NT_AP = 2,
        NT_P2P_GO = 3,
        NT_P2P_GROUP_FORMATION = 4,
}EWifiMSNetType;

#ifndef BIT
#define BIT(x) (1U << (x))
#endif

/* nKeyMgmt */
#define WIFIM_ENC_NONE BIT(0)
#define WIFIM_ENC_WEP  BIT(1)
#define WIFIM_ENC_WPA  BIT(2)
#define WIFIM_ENC_WPA2 BIT(3)

/* wifi stat connecte state */
#define WIFIM_STA_CONNECTED      1
#define WIFIM_STA_DISCONNECTED   2

typedef struct WifiMStatus{
    int nId;    /* current network ID*/
    int nPriority;    /* current network priority*/
    char pdwSsid[WIFIM_SSID_MAXLEN+1];    /* current ap's ssid*/
    char achBssid[WIFIM_BSSID_LEN];    /* current ap's Bssid */
    char achPsk[WIFIM_PASSWD_LEN];    /* current ap's Password */
    char achPassPhrase[WIFIM_PASSWD_LEN];    /* current ap's PassPhrase */
    int nPairwiseCipher;    /* current ap's PairwiseCipher*/
    int nGroupCipher;    /* current ap's GroupCipher */
    int nKeyMgmt;    /* KeyMgmt type */
    unsigned char achWepKey[WIFIM_NUM_WEP_KEYS][WIFIM_WEP_KEY_LEN];/* WEP Key*/
    enum WifiMSNetType eWifiMode;    /* wifi networking mode */
    enum EWifiMStates eWpaState;    /* wifi state */
    char  achP2pDevAddr[WIFIM_BSSID_LEN];    /* p2p device 's MAC address */
    char achOwnAddr[WIFIM_BSSID_LEN];    /* local MAC address */
    int nFrequency;    /* frequncy*/
    int nSignalLevel;    /* signal_level */
    int nDisabled;    /* 0 is enabled,1 is disabled */
    int bIsPosJoinSsid;    /* Is positive to join a ap,1 is Postive, 0 is not */
    int nLinkSpeed;    /* wifi link speed */
    int nConnectState;    /* WIFIM_STA_CONNECTED or WIFIM_STA_DISCONNECTED */
}TWifiMStatus;

#define WIFIM_IP_MODE_STATIC 1
#define WIFIM_IP_MODE_DYNMIC 2

#define WIFIM_DNS_MODE_STATIC 1
#define WIFIM_DNS_MODE_DYNMIC 2

typedef struct WifiMStaConfigParam{
    char  *pchSSID;
    char           *pchBSSID;
    char           *pchAPPassWd;   /*WEP method means wepKeys[0]*/
    enum EWifiMMode *eEMode;   /*If assigned a value ,means join a hidden ssid*/
    int            nIPMode;
    TWifiMIPAddrMsg *ptStaticParam; /* default Dynamic */
    unsigned int       dwIPModeV6;
    EWifimInetType     eInetType; //0--ipv4  1--ipv6 2--all
}TWifiMStaConfigParam;

/* NETWOKR PARAMETER READ FROM CONF FILE */
typedef struct WifiMConfigBss{
    struct WifiMConfigBss *next;
    char   *pchSSID;
    char   *pchAPPassWd;
    char   *pchBSSID;
    enum EWifiMMode  *eEMode;
    /*the bigger number, the higher priority */
    int   nPriority;
    int   nSignal;
    int   nIPMode;
    unsigned int   dwIPAddress;
    unsigned int   dwNetMask;
    unsigned int   dwGateway;
    int nDnsMode;
    unsigned int   dwDNSAddress[WIFIM_MAX_DNS_SERVER];
    int nDNSNum;
    EWifimInetType     eInetType; //0--ipv4  1--ipv6 2--all
    EWifimScopeType scope;   /*ip address type*/
    unsigned int         dwIPModeV6;
    unsigned int         dwDnsModeV6;
    unsigned int  dwPrefixv6;
    unsigned int  dwDnsNumv6;
    TWiFimInaddrV6     tIpAddrsv6;
    TWiFimInaddrV6     tGateWayv6;
    TWiFimInaddrV6     tDNSAddressv6[WIFIM_MAX_DNS_SERVER];
}TWifiMConfigBss;


typedef struct WifiMStaWpsConfigParam{
    int     nWPSMethod;
    char    *pchPin;
    int     nIPMode;
    TWifiMIPAddrMsg *ptStaticParam;  /* default Dynamic */
}TWifiMStaWpsConfigParam;

/* authentication type */
typedef enum WifiMAuth{
    OPEN=0,
    SHARED,
    WPAPSK,
    WPA2PSK,
    WPA2PSKMIXED,
}EWifiMAPAuth;

/* encryption type */
typedef enum WifiMEncr{
    NONE=0,
    WEP,
    TKIP,
    CCMP,
    TKIPCCMP,
}EWifiMAPEncr;

/*Ieee80211  type*/
typedef enum WifiMIeee80211{
    IEEENONE=0,
    IEEE80211d,
    IEEE80211h,
    IEEE80211n,
    IEEE80211ac,
    IEEE80211w,
}EWifiMIeee80211;

/* ap config parameters */
typedef struct WifiMAPConfigParam{
    char      *pchSsid;
    char      *pchKeyword;
    EWifiMAPAuth       emAuth;
    EWifiMAPEncr       emEncr;
    EWifiMIeee80211    emIeee80211;
    int                nChannel;
    int                nAPStaBLFilterEnable;
    int                nAPStaWLFilterEnable;
    int                nApMaxInactivity;  /*default: 300 (i.e., 5 minutes)*/
    int                nBroadcastSsid;/*default 0,should not hide ssid*/
    TWifiMDhcpSerVConfInfo* ptDhcpServerConfInfo;
    EWifimInetType     eInetType; //0--ipv4  1--ipv6 2--all
    TWifiMDhcpSerVConfInfoV6 * ptDhcpServerConfInfoV6;
}TWifiMAPConfigParam;

typedef struct WifiMStationMsg {
    struct WifiMStationMsg *ptNext;
    char achBssid[WIFIM_BSSID_LEN];
    char achIp[WIFIM_IP_LEN];
    char achStaName[WIFIM_STA_NAME_LEN];
    EWifimInetType eInetType;
    char achIpv6[WIFIM_IPV6_LEN];
}TWifiMStationMsg;

typedef struct WifiMFilterList{
    struct WifiMFilterList *next;
    char achBssid[WIFIM_BSSID_LEN];
}TWifiMFilterList;

enum EWifiMIPAddrType{
    WIFIM_ADDR_TYPE_NONE=0,
    WIFIM_ADDR_TYPE_SRC,
    WIFIM_ADDR_TYPE_DST,
};

enum EWifiMProto{
    WIFIM_PROTO_NONE=0,
    WIFIM_PROTO_UDP,
    WIFIM_PROTO_TCP,
};

typedef struct WifiMOutRule{
    enum EWifiMIPAddrType emType;
    enum EWifiMProto enProto;
    TWiFimInaddrV6 tIPAddress;
    unsigned int dwIPAddress;
    unsigned int dwIPNetmask;
    short int nPort;  /* default:-1 */
    char achReserve[2];
}TWifiMOutRule;

/************************************************************************
 * Name:  WifiMInit
 *
 * Function:
 *      Wifi initial funcion
 * Description:
 *      register interface, init global param, and load driver
 * Parameters:
 *      @Param nNum                [IN]the number of ethernet card
 *      @Param ptWifiRegInfo       [IN]the wifi register infomation
 * Returns:
 *      @return SUCCEED : WIFI_OK
 *      @return FAILED  : specifically defined in error type
 ***********************************************************************/

int WifiMInit(int nNum, TWifiMRegInfo* ptWifiMRegInfo);

/***********************************************************************
 * Name:  WifiMDestroy
 *
 * Function:
 *      kill wpa_supplicant/hostapd,stop some interaction clean
 *          the configre file
 *
 * Description:
 *
 * Parameters:
 *      @Param void     [IN]nCleConf(WIFIM_CLEAN_CONFIG:
 *                                                      clean all config file;
 *                                   WIFIM_NOT_CLEAN_CONFIG:
 *                                                      not clean config file)
 * Returns:
 *      @return SUCCEED : WIFI_OK
 *      @return FAILED  : specifically defined in error type
 ***********************************************************************/
int WifiMDestroy(int nCleConf);

/***********************************************************************
 * Name:  WifiMStart
 *
 * Function:
 *      Wifi initial funcion
 * Description:
 *
 * Parameters:
 *      @Param pchIfName        [IN]The name of wireless physical chip
 *      @Param nWifiMode        [IN]The mode that you want to start with
 *
 * Returns:
 *      @return SUCCEED : WIFI_OK
 *      @return FAILED  : specifically defined in error type
 ***********************************************************************/
int WifiMStart(char *pchIfName, int nWifiMode);

/***********************************************************************
 * Name:  WifiMStop
 *
 * Function:
 *      kill wpa_supplicant/hostapd,stop some interaction
 * Description:
 *
 * Parameters:
 *      @Param pchIfName          [IN] the name of phyical chip
 * Returns:
 *      @return SUCCEED : WIFI_OK
 *      @return FAILED  : specifically defined in error type
 ***********************************************************************/
int WifiMStop(char *pchIfName);

/***********************************************************************
 * Name:  WifiSTAScanBss
 *
 * Function:
 *      Wifi ScanBss funcion
 * Description:
 *
 * Parameters:
 *      @Param pchIfName       [IN]Ethernet Interface
 *      @Param pplist          [OUT]Pointer to scanned bss infomation
 *                                  list head pointer
 * Returns:
 *      @return SUCCEED : WIFI_OK
 *      @return FAILED  : specifically defined in error type
 ***********************************************************************/
int WifiMSTAScanBss(char* pchIfName, TWifiMSBSSIDItem** ppList);

/***********************************************************************
 * Name:  WifiMFreeBss
 *
 * Function:
 *      Wifi Free bss list funcion
 * Description:
 *
 * Parameters:
 *      @Param pchIfName       [IN]ethernet interface
 *      @Param plist           [IN]pointer to scanned bss infomation
 *                                 list head
 * Returns:
 *      @return SUCCEED : WIFI_OK
 *      @return FAILED  : specifically defined in error type
 ***********************************************************************/
int WifiMFreeBss(char* pchIfName, TWifiMSBSSIDItem* ptList);

/***********************************************************************
 * Name:  WifiMSTAGetStatus
 *
 * Function:
 *      Wifi WifiSTAGetStatus funcion
 * Description:
 *
 * Parameters:
 *      @Param pchIfName       [IN]Interface name
 *      @Param ptWifiStatus    [OUT]point to wifi status list
 * Returns:
 *      @return SUCCEED : WIFI_OK
 *      @return FAILED  : specifically defined in error type
 ***********************************************************************/
int WifiMSTAGetStatus(char* pchIfName, TWifiMStatus* ptWifiStatus);

/***********************************************************************
 * Name:  WifiMSTAJoin
 *
 * Function:
 *      to join a new Network
 * Description:
 *
 * Parameters:
 *      @Param pchIfName       [IN]Interface name
 *      @Param ptConfigParam   [IN]configuration join parameters
 * Returns:
 *      @return SUCCEED : WIFI_OK
 *      @return FAILED  : specifically defined in error type
 ***********************************************************************/
int WifiMSTAJoin(char* pchIfName, TWifiMStaConfigParam* ptConfigParam);

/***********************************************************************
 * Name:  WifiMSTAUpdateNet
 *
 * Function:
 *      Update a Network 's configuration
 * Description:
 *      just reconfigure but not deal with this configuration right now
 * Parameters:
 *      @Param pchIfName       [IN]Interface name
 *      @Param ptConfigParam   [IN]configuration join parameters
 * Returns:
 *      @return SUCCEED : WIFI_OK
 *      @return FAILED  : specifically defined in error type
 ***********************************************************************/
 int WifiMSTAUpdateNet(char* pchIfName,
                               TWifiMStaConfigParam* ptConfigParam);

 /***********************************************************************
 * Name:  WifiMSTAGetConfigNet
 *
 * Function:
 *      get saved configuration network
 * Description:
 *      Get saved network configurations
 * Parameters:
 *      @Param pchIfName       [IN]Interface name
 * Returns:
 *      @return SUCCEED : List head pointer
 *      @return FAILED  : NULL
 ***********************************************************************/
struct WifiMConfigBss* WifiMSTAGetConfigNet(char* pchIfName);

/***********************************************************************
 * Name:  WifiMSTAFreeConfigNet
 *
 * Function:
 *      Wifi saved network list funcion
 * Description:
 *
 * Parameters:
 *      @Param ptConfigList       [IN]list of saved network configurations
 * Returns:
 *      @return SUCCEED : WIFI_OK
 *      @return FAILED  : specifically defined in error type
 ***********************************************************************/
int WifiMSTAFreeConfigNet(struct WifiMConfigBss* ptConfigList);

/***********************************************************************
 * Name:  WifiSTAForgetNetwork
 *
 * Function:
 *      Wifi forget network funcion
 * Description:
 *      Remove a NetWork from config file
 *      and disconnect with a AP right now.
 * Parameters:
 *      @Param pchIfName       [IN]Interface name
 *      @Param pchSsid         [IN]AP's Name
 * Returns:
 *      @return SUCCEED : WIFI_OK
 *      @return FAILED  : specifically defined in error type
 ***********************************************************************/
int WifiMSTAForgetNet(char* pchIfName, char* pchSsid);

/***********************************************************************
 * Name:  WifiMSTAForgetAllNet
 *
 * Function:
 *      Wifi forget all network funcion
 * Description:
 *     Remove all NetWork from config file
 *      and disconnect with  AP right now.
 * Parameters:
 *      @Param pchIfName       [IN]Interface name
 * Returns:
 *      @return WIFI_OK
 *      @return WIFIM_ERROR
 ***********************************************************************/
int WifiMSTAForgetAllNet(char *pchIfName);

/***********************************************************************
 * Name:  WifiMSTAReassocAP
 * Function:
 *      Wifi reassociate funcion
 * Description:
 *      Reassociate AP.
 * Parameters:
 *      @Param pchIfName       [IN]Interface name
 * Returns:
 *      @return WIFI_OK
 *      @return WIFIM_ERROR
 ***********************************************************************/
int WifiMSTAReassocAP(char *pchIfName);

/***********************************************************************
 * Name:  WifiMSTAWPSRequest
 *
 * Function:
 *      Request WPS method to join a network
 * Description:
 *      this function is called to use WPS method to join a network.it
 *      must be needed to choose from two wps method pbc/pin.If you
 *      choose wps_pin method but don't know what pin code is,you may
 *      not write it and it will callback a random pin code.
 * Parameters:
 *      @Param pchIfName          [IN]Interface name
 *      @Param ptWpsConfigParam   [IN]wps config parameter
 * Returns:
 *      @return SUCCEED : WIFI_OK
 *      @return FAILED  : specifically defined in error type
 ***********************************************************************/
int WifiMSTAWPSRequest(char* pchIfName,
                               TWifiMStaWpsConfigParam* ptWpsConfigParam);

/***********************************************************************
 * Name:  WifiMSTAWPSStop
 *
 * Function:
 *      stop WPS connecting
 * Description:
 *
 * Parameters:
 *      @Param pchIfName          [IN]Interface name
 * Returns:
 *      @return SUCCEED : WIFI_OK
 *      @return FAILED  : specifically defined in error type
 ***********************************************************************/
int WifiMSTAWPSStop(char* pchIfName);

#define WIFIM_NONE_PORT -1
#define WIFIM_NAT_SET    0
#define WIFIM_NAT_UNSET  1

/***********************************************************************
 * Name:  WifiMManageNAT
 *
 * Function:
 *      ADD/DEL NAT rule
 * Description:
 *
 * Parameters:
 *      @Param pchOutIfName       [IN]output Interface name
 *      @Param nCmd               [IN]ADD/DEL NAT rule
 *      @Param ptOutRule          [IN]pointer to TWifiMOutRule structure
 * Returns:
 *      @return SUCCEED : WIFI_OK
 *      @return FAILED  : specifically defined in error type
 ***********************************************************************/
int WifiMManageNAT(char* pchOutIfName, int nCmd,
                          TWifiMOutRule* ptOutRule);

/***********************************************************************
 * Name:  WifiSTAConfigSsidPriority
 *
 * Function:
 *      Set specific SSID 's Priority to highest /lowest
 * Description:
 *
 * Parameters:
 *      @Param pchIfName       [IN]Interface name
 *      @Param pchSsid         [IN]ssid
 *      @Param nCmd            [IN]highest/lowest
 * Returns:
 *      @return SUCCEED : WIFI_OK
 *      @return FAILED  : specifically defined in error type
 ***********************************************************************/
int WifiMSTAConfigSsidPriority(char *pchIfName, char* pchSsid,
                                           int nCmd);

/* List Type */
#define  WIFIM_BLACK_LIST_DISABLE  0
#define  WIFIM_BLACK_LIST_ENABLE   1

#define  WIFIM_WHITE_LIST_DISABLE  0
#define  WIFIM_WHITE_LIST_ENABLE   1

#define  WIFIM_BLACK_LIST  0
#define  WIFIM_WHITE_LIST  1
/* Cmd Type */
#define  WIFIM_LIST_CMD_ADD   0
#define  WIFIM_LIST_CMD_DEL   1


/***********************************************************************
 * Name:  WifiMAPConfiguration
 *
 * Function:
 *      reconfigure a AP function
 * Description:
 *
 * Parameters:
 *      @Param pchIfName       [IN]Interface name
 *      @Param tTConfigParam   [IN]configuration parameters
 *                             (the lenth of pchSsid should be less than 33,
 *                              if the channel number(0-13) is 0,
 *                                 the channel model is automatic
 *                              if EWifiMAPAuth is OPEN, EWifiMAPEncr is NONE,
 *                                 the pchKeyword should be NULL
 *                              if EWifiMAPAuth is SHARED,  EWifiMAPEncr is WEP,
 *                                 the lenth of pchKeyword should be 10 or 26
 *                              if EWifiMAPAuth is WPAPSK/WPAPSK2,  EWifiMAPEncr
 *                                 is TKIP/CCMP, the lenth of pchKeyword
 *                                 should between 8 and 63)
 * Returns:
 *      @return SUCCEED : WIFI_OK
 *      @return FAILED  : specifically defined in error type
 ***********************************************************************/
int WifiMAPConfiguration(char* pchIfName,
                                  TWifiMAPConfigParam* ptTConfigParam);

/***********************************************************************
 * Name:  WifiMAPWPSStart
 *
 * Function:
 *      start wps function ,send broadcast to associate with a station
 *      supported WPS function.
 * Description:
 *
 * Parameters:
 *      @Param pchIfName       [IN]Interface name
 *      @Param nWpaMethod      [IN]-WPS_PIN_METHOD 0
 *                                 -WPS_PBC_METHOD 1
 *      @Param pchPin          [IN]set pin code
 * Returns:
 *      @return 0 : WIFI_OK
 *      @return specifically defined in error type
 ***********************************************************************/
int WifiMAPWPSStart(char* pchIfName, int nWpsMethod, char* pchPin);

/***********************************************************************
 * Name:  WifiMAPWPSAck
 *
 * Function:
 *      WPS Connect function
 * Description:
 *      allow to connect to a station
 * Parameters:
 *      @Param pchIfName       [IN]Interface name
 * Returns:
 *      @return SUCCEED : WIFI_OK
 *      @return FAILED  : specifically defined in error type
 ***********************************************************************/
int WifiMAPWPSAck(char* pchIfName);

/***********************************************************************
 * Name:  WifiMAPWPSNack
 *
 * Function:
 *      WPS reject to connect function
 * Description:
 *      reject to connect to a station
 * Parameters:
 *      @Param pchIfName       [IN]Interface name
 * Returns:
 *      @return SUCCEED : WIFI_OK
 *      @return FAILED  : specifically defined in error type
 ***********************************************************************/
int WifiMAPWPSNack(char* pchIfName);

/***********************************************************************
 * Name:  WifiMAPGetStaList
 *
 * Function:
 *      get connected station list to user
 * Description:
 *
 * Parameters:
 *      @Param pchIfName       [IN]Interface name
 *      @Param pptMsg
 *      @return FAILED  : specifically defined in error type
 ***********************************************************************/
int WifiMAPGetStaList(char* pchIfName, TWifiMStationMsg** pptMsg);

/***********************************************************************
 * Name:  WifiMAPFreeStaList
 *
 * Function:
 *      FREE STATION LIST
 * Description:
 *
 * Parameters:
 *      @Param pchIfName       [IN]Interface name
 *      @Param ptMsg           [IN]point to station list head
 * Returns:
 *      @return SUCCEED : WIFI_OK
 *      @return FAILED  : specifically defined in error type
 ***********************************************************************/
int WifiMAPFreeStaList(char* pchIfName, TWifiMStationMsg** ptMsg);

/***********************************************************************
 * Name:  WifiMAPRemoveSta
 *
 * Function:
 *      ap remove a connected station
 * Description:
 *
 * Parameters:
 *      @Param pchIfName       [IN]Interface name
 *      @Param pchBssid        [IN]station 's bssid
 * Returns:
 *      @return SUCCEED : WIFI_OK
 *      @return FAILED  : specifically defined in error type
 ***********************************************************************/
int WifiMAPRemoveSta(char* pchIfName, char* pchBssid);

/***********************************************************************
 * Name:  WifiMAPStaFilterManage
 *
 * Function:
 *      to add/del station to blacklist/whitelist
 * Description:
 *
 * Parameters:
 *      @Param pchIfName       [IN]Interface name
 *      @Param pchBssid        [IN]station 's bssid
 *      @Param nListType       [IN]blacklist/whitelist
 *      @Param nCmd            [IN]add/del
 * Returns:
 *      @return SUCCEED : WIFI_OK
 *      @return FAILED  : specifically defined in error type
 ***********************************************************************/
int WifiMAPStaFilterManage(char* pchIfName, char* pchBssid,
                                     int nListType, int nCmd);

/***********************************************************************
 * Name:  WifiAPGetFilterList
 *
 * Function:
 *      get white/black filter list
 * Description:
 *      this function is called to get current filter list
 * Parameters:
 *      @Param pchIfName       [IN]Interface name
 *      @Param nListType       [IN]blacklist/whitelist
 * Returns:
 *      @return SUCCEED : filterlist head  pointer
 *      @return FAILED  : NULL
 ***********************************************************************/
TWifiMFilterList* WifiMAPGetFilterList(char *pchIfName, int nListType);

/***********************************************************************
 * Name:  WifiMAPFreeFilterList
 *
 * Function:
 *      free white/black filter list
 * Description:
 *      this function is called to free current filter list
 * Parameters:
 *      @Param pchIfName       [IN]Interface name
 *      @Param nListType       [IN]blacklist/whitelist
 * Returns:
 *      @return SUCCEED : WIFI_OK
 *      @return FAILED  : specifically defined in error type
 ***********************************************************************/
int WifiMAPFreeFilterList(char* pchIfName, int nListType);

/***********************************************************************
 * Name:  WifiMQueryVersion
 *
 * Function:
 *      provide interface to upper to acquire OS version
 * Description:
 *      provide interface to upper to acquire OS version
 * Parameters:
 *      @Param pchVer         [IN]pointer to acquired OS version string
 *      @Param dwBufLen       [IN]len of OS version string
 * Returns:
 *      @return SUCCEED : WIFI_OK
 *      @return FAILED  : specifically defined in error type
 ***********************************************************************/
int WifiMQueryVersion(char* pchVer, unsigned int dwBufLen);

/***********************************************************************
 * Name: WifiMDebug
 *
 * Function:
 *      provide a print switch
 * Description:
 *      provide a print switch
 * Parameters:
 *      @Param n0n         [IN]1 -->open
 *                             0 -->close
 * Returns:
 *      @return WIFIM_OK
 ***********************************************************************/
int WifiMDebug(int nSwitch);

/***********************************************************************
 * Name:  WifiMSetMode
 *
 * Function:
 *      Wifi set mode
 * Description:
 *
 * Parameters:
 *      @Param pchIfName        [IN]The name of wireless physical chip
 *      @Param nWifiMode        [IN]The mode that you want to set, 0-managed,
 *                                  1--master,3--monitor
 *
 * Returns:
 *      @return SUCCEED : WIFI_OK
 *      @return FAILED  : specifically defined in error type
 ***********************************************************************/
int WifiMSetMode(char *pchIfName, int nWifiMode);

#define WIFIM_MODUL_ALL     0x00000000  /* Everything supported */
#define WIFIM_MODUL_FH      0x00000001  /* Frequency Hopping */
#define WIFIM_MODUL_DS      0x00000002  /* Original Direct Sequence */
#define WIFIM_MODUL_CCK     0x00000004  /* 802.11b : 5.5 + 11 Mb/s */
#define WIFIM_MODUL_PBCC    0x00000008  /* TI : 5.5 + 11 + 22 Mb/s */
#define WIFIM_MODUL_OFDM_A  0x00000010  /* 802.11a : 54 Mb/s */
#define WIFIM_MODUL_OFDM_G  0x00000020  /* 802.11g : 54 Mb/s */
#define WIFIM_MODUL_TURBO   0x00000040  /* ATH : bonding, 108 Mb/s */

/* Bit field values for enc_capa in struct tagWifiMCapability */
#define WIFIM_ENC_CAPA_WPA              0x00000001
#define WIFIM_ENC_CAPA_WPA2             0x00000002
#define WIFIM_ENC_CAPA_CIPHER_TKIP      0x00000004
#define WIFIM_ENC_CAPA_CIPHER_CCMP      0x00000008
#define WIFIM_ENC_CAPA_4WAY_HANDSHAKE   0x00000010

#define WIFIM_MAX_FREQUENCIES    32


/* modul_capa */
#define WIFIM_MODUL_11B     (WIFIM_MODUL_DS | WIFIM_MODUL_CCK)
#define WIFIM_MODUL_11A     (WIFIM_MODUL_OFDM_A)
#define WIFIM_MODUL_11AB    (WIFIM_MODUL_11B | WIFIM_MODUL_11A)
#define WIFIM_MODUL_11G     (WIFIM_MODUL_11B | WIFIM_MODUL_OFDM_G)
#define WIFIM_MODUL_11AG    (WIFIM_MODUL_11G | WIFIM_MODUL_11A)

typedef struct WifiMPhyCapability{
    /* Frequency */
    unsigned short  dwChannelsNum;   /* Number of channels [0; num - 1] */
    int             anChannelFreq[WIFIM_MAX_FREQUENCIES];  /* list */
    /* enc capability */
    unsigned int dwEncCapa; /* WIFIM_ENC_CAPA* bit field defined in wireless.h*/
    /* Modul capability */
    int             nModulCapa; /* WIFIM_MODUL_* bit field */
    int             nBand;

}TWifiMPhyCapability;

/***********************************************************************
 * Name:  WifiMGetPhyChipCapa
 *
 * Function:
 *      Get infomaition of physical chip's cabability
 * Description:
 *      Get infomaition of physical chip's cabability
 * Parameters:
 *      @Param pchIfName         [IN]Interface name
 *      @Param ptPhyChipCapa     [OUT]point to wifi physical chip
 *                                    infomation struct
 * Returns:
 *      @return WIFI_OK
 *      @return WIFIM_ERROR
 ***********************************************************************/
int WifiMGetPhyChipCapa(char* pchIfName,
                                 TWifiMPhyCapability* ptPhyChipCapa);

#define WIFIM_DEVICE_STA   1
#define WIFIM_DEVICE_AP    2
#define WIFIM_MAC_LEN      19     /* the length of mac */
#define WIFIM_COLLECT_MAC  1      /* collect mac info */
#define WIFIM_MAX_TIMEVAL  300    /* the max timeval */
#define WIFIM_MIN_TIMEVAL  10     /* the min timeval */
#define WIFIM_SSID_LEN      32     /* the length of mac */

typedef struct WifiMColNotify {
    char achFile[WIFIM_MAX_PATH_LEN];
} TWifiMColNotify;

typedef int(*WifiMColNotifyCallBack)
             (TWifiMColNotify *ptWifiColNotify);

typedef struct WifiMColRegInfo{
    char *pchIfName;
    /* the directory path of callback file, default null, or such as /tmp/ */
    char *pchFilePath;
    /* the ccuracy time of mac record */
    int nTimeAccur;
    /* the time interval of pull mac collect file, 10s < nFileTimeInter < 600s*/
    int nFileTimeInter;
    /* the max num of mac collect file, default 0 */
    int nFileMaxNum;
    /* the max size of mac collect file,  default 0 */
    int nFileMaxSize;
    WifiMColNotifyCallBack WifiMColNotifyCB;
} TWifiMColRegInfo;

/***********************************************************************
 * Name:  WifiMStartCollect
 *
 * Function:
 *      Start collect mac information
 * Description:
 *      Start collect mac information
 * Parameters:
 *      @Param pchIfName             [IN]Interface name
 *      @Param ptWifimColRegInfo     [IN]Collect mac register information
 * Returns:
 *      @return WIFI_OK
 *      @return WIFIM_ERROR
 ***********************************************************************/
int WifiMStartCollect(TWifiMColRegInfo *ptWifimColRegInfo);

/***********************************************************************
 * Name:  WifiMStopCollect
 *
 * Function:
 *      Stop collect mac information
 * Description:
 *      Stop collect mac information
 * Parameters:
 *      @Param pchIfName         [IN]Interface name
 * Returns:
 *      @return WIFI_OK
 *      @return WIFIM_ERROR
 ***********************************************************************/
int WifiMStopCollect(char *pchIfName);

/***********************************************************************
 * Name:  WifiMColRmFile
 *
 * Function:
 *      remove collect mac file
 * Description:
 *      remove collect mac file
 * Parameters:
 *      @Param pchFilePath         [IN]the path of collect mac file
 * Returns:
 *      @return WIFI_OK
 *      @return WIFIM_ERROR
 ***********************************************************************/
int WifiMColRmFile(char *pchFilePath);

/***********************************************************************
 * Name:  WifiMClearFakeMac
 *
 * Function:
 *      config how to ideal fake mac
 * Description:
 *      config how to ideal fake mac
 * Parameters:
 *      @Param nEnable         [IN]enable or disable clear fake mac
 * Returns:
 *      @return WIFI_OK
 *      @return WIFIM_ERROR
 ***********************************************************************/
int WifiMClearFakeMac(int nEnable);

/***********************************************************************
 * Name:  WifiMCollectApInfo
 *
 * Function:
 *      config whether to collect ap info or not
 * Description:
 *      config whether to collect ap info or not
 * Parameters:
 *      @Param nEnable         [IN]enable or disable collect ap info
 * Returns:
 *      @return WIFI_OK
 *      @return WIFIM_ERROR
 ***********************************************************************/
int WifiMCollectApInfo(int nEnable);

#define WIFIM_MANUFACT_LEN     64

typedef struct WifiMProbeInfo{
    int nDevType;   /* the device type , WIFIM_DEVICE_STA/WIFIM_DEVICE_AP*/
    char achMac[WIFIM_MAC_LEN];   /* the device mac */
    time_t tTime;   /* time of first collect the device */
    int nSignalLevel;                        /* signal_level */
    int nChannel;                            /* Channel */
    char achManufact[WIFIM_MANUFACT_LEN];    /* manufacturer */
    char achSsid[WIFIM_SSID_LEN];
    /*0-"none", 1-"wep", 2-"wpa-psk-tkip", 3-"wpa-psk-ccmp",
     *4-"wpa-psk-tkip/ccmp", 5-"wpa2-psk-tkip",
     *6-"wpa2-psk-ccmp", 7-"wpa2-psk-tkip/ccmp", 8-"wpa/wpa2-psk-tkip",
     *9-"wpa/wpa2-psk-ccmp", 10-"wpa/wpa2-psk-tkip/ccmp"
     */
    int nAuthencry;
} TWifiMProbeInfo;

/***********************************************************************
 * Name:  WifiMParseColInfo
 *
 * Function:
 *      parse collect mac info
 * Description:
 *      parse collect mac info
 * Parameters:
 *      @Param pchbuffer      [IN]pchbuffer
 *      @Param ptProbeInfo    [IN]the point of mac info
 * Returns:
 *      @return WIFI_OK
 *      @return WIFIM_ERROR
 ***********************************************************************/
int WifiMParseColInfo(char *pchBuffer, TWifiMProbeInfo* ptProbeInfo);

#ifdef __cplusplus
}
#endif
#endif
