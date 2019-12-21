/*****************************************************************************
   模块名      : DataSwitch
   文件名      : dataswitch.h
   相关文件    :
   文件实现功能: DataSwitch模块接口函数定义
-----------------------------------------------------------------------------
   修改记录:
   日  期      版本        修改人      修改内容
   2005/03/18  4.0         靳志业        创建
   2005/08/10  4.0         靳志业        实现3.6中新增的功能
   2014/06/20  5.0         曾昭鸣        实现rtpswitch功能
   2014/10/09  5.1         曾昭鸣        合并所有kdv和movision的dataswitch
******************************************************************************/

#ifndef DATASWITCH_H
#define DATASWITCH_H

#define DSVERSION       "DataSwitch.TS.5.1.20141009"

#include "osp.h"
#include "rtp_endpoint_id.h"     //rtp标识的定义和接口

/* DataSwitch 句柄 */
#define DSID    u32

#define DSID_LEN          16
#define DSID_MASK         0xffff0000
#define RTPID_MASK        0x0000ffff

#define DS_GET_DSID(rtpId) \
    ((((rtpId) & DSID_MASK) >> DSID_LEN) + 1)

#define DS_GET_DSRTPID(rtpId) \
    ((rtpId) & RTPID_MASK)

/*DataSwitch 返回值*/
#define DSOK    1
#define DSERROR 0

#define INVALID_DSID  0xffffffff   /*无效的句柄值*/

#if (defined _MSC_VER)
#include <Winsock2.h>
#include <ws2tcpip.h>
//TODO: inet_pton的工作移到OSP中完成
#ifndef inet_pton
#define inet_pton
#endif
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#endif

typedef struct tagDsGlobalParam
{
	tagDsGlobalParam()
	{
		m_dwRecvBuff = 2 * 1024 * 1024 ;
		m_dwSendBuff = 2 * 1024 * 1024 ;
	}

	u32	m_dwRecvBuff;
	u32	m_dwSendBuff;
} TDsGlobalparam;

API void dsSetGlobalParam(TDsGlobalparam tParam );

/*----------- 开始定义udpswitch ----------------------*/

/**
 * @func FilterFunc
 * @brief 接收过滤函数
 *
 * 每个接收结点有一个过滤函数，当此结点接收到UDP数据包时执行此函数。
 * 并根据函数的返回值，来动态地决定是否对此数据包转发。
 *
 * @param dwRecvIP        - 接收IP
 * @param wRecvPort      - 接收Port
 * @param dwSrcIP         - 源IP
 * @param SrcPort       - 源Port
 * @param pData          - [in, out]数据包；可以修改；
 * @param uLen           - [in, out]数据包长度；修改后的长度不可超过最大值
 * @return 0, 该数据包有效； 其他值，该数据包无效；
 */
typedef u32 (*FilterFunc)(u32 dwRecvIP, u16 wRecvPort,
                          u32 dwSrcIP, u16 wSrcPort,
                          u8* pData, u32 uLen);

#define SENDMEM_MAX_MODLEN        (u8)32        // 发送时允许的最大修改长度

/**
 * 数据包转发目标：指明具体的IP, port对
 * DS所控制的多个IP，对于数据包的转发应该不产生影响。也就是说，如果
 * 有两个IP都可以将一个数据包正确的地转发出去，则使用哪一个IP是没有
 * 关系的。所以，转发输出接口IP是不需要的。
 */
typedef struct tagNetSndMember
{
    u32     dwIP;       /* 转发目的IP地址   */
    u16     wPort;      /* 转发目的端口号   */
    s32     lIdx;       /* 接口索引 */
    u32     errNum;     /* 出错次数*/
    s32     errNo;      /* 错误号 */
    void    *lpuser;    /* user info */
    /* 为实现发送时修改数据而增加的部分 */
    u16     wOffset;    /* 修改部分的起始位置; 目前未使用 */
    u16     wLen;       /* 修改部分的长度，必须为4的倍数；为零表示不修改 */
    char    pNewData[SENDMEM_MAX_MODLEN];
    /* 要修改的数据 */
    void    *pAppData;  /* 用户自定义的回调函数的参数 */
} TNetSndMember;

typedef void (*SendCallback)(u32 dwRecvIP, u16 wRecvPort,
                             u32 dwSrcIP,  u16 wSrcPort,
                             TNetSndMember *ptSends,            // 转发目标列表
                             u16* pwSendNum,                    // 转发目标个数
                             u8* pUdpData, u32* dwUdpLen);

/**********************************************************
 * 函数: DsRemoveRtpExtension                             *
 * 功能: 去除rtp包中的扩展信息，以兼容外厂商设备          *
 * 输出: 无                                               *
 * 返回: N/A                                              *
 **********************************************************/
API void DsRemoveRtpExtension(u32 dwRecvIP, u16 wRecvPort,
                             u32 dwSrcIP,  u16 wSrcPort,
                             TNetSndMember *ptSends,            // 转发目标列表
                             u16* pwSendNum,                    // 转发目标个数
                             u8* RtpPkt, u32* dwRtpLen);

API void dsSetApiTimeOut(s32 timeout);
/**********************************************************
 * 函数: dsSetCapacity                                    *
 * 功能: 容量设置(只能在创建交换模块之前调用)             *
 * 输入: dwMaxRcvGrp        - 最大接收组数                *
 *       dwMaxSndMmbPerRcvGrp  - 每一接收组最大发送目标数   *
 * 输出: 无                                               *
 * 返回: 成功返回DSOK 否则DSERROR                         *
 **********************************************************/
API u32 dsSetCapacity( u32 dwMaxRcvGrp, u32 dwMaxSndMmbPerRcvGrp );

/************************************************************
 * 函数名：dsCreate
 *
 * 功能：  运行DataSwitch模块
 *
 * 实现说明：
 * Dataswitch支持“多用户”；每次调用dsCreate就会返回一个
 * 用户标识。添加、删除时均要匹配用户标志，转发时则不考虑。
 *
 * 返回值：
 * @return INVALID_DSID: 表示失败 ; 否则成功
 ************************************************************/
API DSID dsCreate( u32, u32 * );

/************************************************************
 * 函数名：dsDestroy
 *
 * 功能： 终止DataSwitch的运行
 *
 * 实现说明：
 * 一次删除一个用户，直到所有用户都删除，所有资源才全释放。
 *
 * 参数说明：
 * @param dsId  - 用户标识
 *
 * 返回值：
 ************************************************************/
API void dsDestroy( DSID dsId );

/************************************************************
 * 函数名： dsAdd
 *
 * 功能： 增加转发目标唯一的转发规则
 *
 * 实现说明：
 * “目前唯一”的含义是：如果已经存在的交换规则中转发目标
 * 与当前规则的相同，则先删除这些规则。
 *
 * 参数说明：
 * @param dsId          - 用户标识
 * @param dwRecvIP      - 接收IP，即接收数据包的目的IP
 * @param wRecvPort     - 接收Port，即接收数据包的目的Port
 * @param dwInLocalIP   - 接收数据包的网络接口
 * @param dwSendtoIP    - 转发目的IP
 * @param wSendtoPort   - 转发目的Port
 * @param dwOutLocalIP  - 转发数据包所用本地IP
 *
 * 返回值：
 * @return DSOK: 表示成功 ; DSERROR: 表示失败 ;
 ************************************************************/
API u32 dsAdd(DSID dsId,
              u32  dwRecvIP ,
              u16  wRecvPort,
              u32  dwInLocalIP,
              u32  dwSendtoIP,
              u16  wSendtoPort,
              u32  dwOutLocalIP = 0);

/************************************************************
 * 函数名：dsRemove
 *
 * 功能： 删除转发目标为指定地址的转发规则
 *
 * 实现说明：
 *
 * 参数说明：
 * @param dsId          - 用户标识
 * @param dwSendtoIP    - 转发目的IP
 * @param wSendtoPort   - 转发目的Port
 *
 * 返回值：
 * @return DSOK: 表示成功 ; DSERROR: 表示失败 ;
 ************************************************************/
API u32 dsRemove(DSID dsId,
                 u32  dwSendtoIP,
                 u16  wSendtoPort);

/************************************************************
 * 函数名：dsAddDump
 *
 * 功能： 增加Dump规则
 * DUMP规则：从指定地址接收的数据包不被转发。
 * 如果一个接收地址只有DUMP规则，则接收的数据包不被转发；
 * 如果还有其他转发规则，则按照其他规则转发。
 *
 * 实现说明：
 * DUMP规则允许被创建多次，因为它与其他规则是可以并存的，
 * 包括它自身；
 *
 * 参数说明：
 * @param dsId          - 用户标识
 * @param dwRecvIP      - 接收IP，即接收数据包的目的IP
 * @param wRecvPort     - 接收Port，即接收数据包的目的Port
 * @param dwInLocalIP   - 接收数据包的网络接口
 *
 * 返回值：
 * @return DSOK: 表示成功 ; DSERROR: 表示失败 ;
 ************************************************************/
API u32 dsAddDump(DSID dsId, u32 dwRecvIP, u16 wRecvPort, u32 dwInLocalIP);

/************************************************************
 * 函数名：dsRemoveDump
 *
 * 功能： 删除Dump规则
 *
 * 实现说明：
 *
 * 参数说明：
 * @param dsId          - 用户标识
 * @param dwRecvIP      - 接收IP，即接收数据包的目的IP
 * @param wRecvPort     - 接收Port，即接收数据包的目的Port
 *
 * 返回值：
 * @return DSOK: 表示成功 ; DSERROR: 表示失败 ;
 ************************************************************/
API u32 dsRemoveDump(DSID dsId, u32 dwRecvIP, u16 wRecvPort);

/************************************************************
 * 函数名：dsAddManyToOne
 *
 * 功能： 增加多对一的转发规则
 * 注意，它与dsAdd的语义正好相反，两者混合使用时要小心。
 *
 * 实现说明：
 *
 * 参数说明：
 * @param dsId          - 用户标识
 * @param dwRecvIP      - 接收IP，即接收数据包的目的IP
 * @param wRecvPort     - 接收Port，即接收数据包的目的Port
 * @param dwInLocalIP   - 接收数据包的网络接口
 * @param dwSendtoIP    - 转发目的IP
 * @param wSendtoPort   - 转发目的Port
 * @param dwOutLocalIP  - 转发数据包所用本地IP
 *
 * 返回值：
 * @return DSOK: 表示成功 ; DSERROR: 表示失败 ;
 ************************************************************/
API u32 dsAddManyToOne(DSID dsId ,
                       u32  dwRecvIP,
                       u16  wRecvPort,
                       u32  dwInLocalIP,
                       u32  dwSendtoIP,
                       u16  wSendtoPort,
                       u32  dwOutLocalIP = 0);

/************************************************************
 * 函数名：dsRemoveAllManyToOne
 *
 * 功能： 删除所有转发目标为指定地址的多对一规则
 *
 * 注意：它的语义与dsRemove完全相同（可以从接口参数上证明）
 * 提供这个接口是为了不让两类不同语义的接口混合使用。一个
 * 程序中，应当始终使用某一类接口。
 *
 * 实现说明：
 *
 * 参数说明：
 * @param dsId          - 用户标识
 * @param dwSendtoIP    - 转发目的IP
 * @param wSendtoPort   - 转发目的Port
 *
 * 返回值：
 * @return DSOK: 表示成功 ; DSERROR: 表示失败 ;
 ************************************************************/
API u32 dsRemoveAllManyToOne(DSID dsId ,
                             u32  dwSendtoIP,
                             u16  wSendtoPort);

/************************************************************
 * 函数名：dsRemoveManyToOne
 *
 * 功能： 删除指定的多对一规则
 *
 * 实现说明：
 *
 * 参数说明：
 * @param dsId          - 用户标识
 * @param dwRecvIP      - 接收IP，即接收数据包的目的IP
 * @param wRecvPort     - 接收Port，即接收数据包的目的Port
 * @param dwInLocalIP   - 接收数据包的网络接口
 * @param dwSendtoIP    - 转发目的IP
 * @param wSendtoPort   - 转发目的Port
 *
 * 返回值：
 * @return DSOK: 表示成功 ; DSERROR: 表示失败 ;
 ************************************************************/
API u32 dsRemoveManyToOne(DSID dsId ,
                          u32  dwRecvIP,
                          u16  wRecvPort,
                          u32  dwSendtoIP,
                          u16  wSendtoPort );

/************************************************************
 * 函数名：dsAddSrcSwitch
 *
 * 功能： 增加按源转发的规则
 *
 * 按源转发：使用此规则时，接收数据包的源地址必须与规则中的源
 * 地址相等。每次转发时，都要先根据数据包中的源地址查找转发规
 * 则，如果找不到，则使用默认源地址（即0@0）的转发规则。
 * 注意：该接口支持多点到一点。如果dwSrcIP和wSrcPort都为零，
 * 它就完全等同于dsAddManyToOne。
 *
 * 实现说明：
 *
 * 参数说明：
 * @param dsId          - 用户标识
 * @param dwRecvIP      - 接收IP，即接收数据包的目的IP
 * @param wRecvPort     - 接收Port，即接收数据包的目的Port
 * @param dwInLocalIP   - 接收数据包的网络接口
 * @param dwSrcIP       - 接收数据包的源IP
 * @param wSrcPort      - 接收数据包的源Port
 * @param dwSendtoIP    - 转发目的IP
 * @param wSendtoPort   - 转发目的Port
 * @param dwOutLocalIP  - 转发数据包所用本地IP
 *
 * 返回值：
 * @return DSOK: 表示成功 ; DSERROR: 表示失败 ;
 ************************************************************/
API u32 dsAddSrcSwitch(DSID dsId ,
                       u32  dwRecvIP,
                       u16  wRecvPort,
                       u32  dwInLocalIP,
                       u32  dwSrcIP ,
                       u16  wSrcPort,
                       u32  dwSendtoIP,
                       u16  wSendtoPort,
                       u32  dwOutLocalIP = 0);

/************************************************************
 * 函数名：dsRemoveAllSrcSwitch
 *
 * 功能： 删除所有指定的按源转发规则
 *
 * 实现说明：
 *
 * 参数说明：
 * @param dsId          - 用户标识
 * @param dwRecvIP      - 接收IP，即接收数据包的目的IP
 * @param wRecvPort     - 接收Port，即接收数据包的目的Port
 * @param dwSrcIP       - 接收数据包的源IP
 * @param wSrcPort      - 接收数据包的源Port
 *
 * 返回值：
 * @return DSOK: 表示成功 ; DSERROR: 表示失败 ;
 ************************************************************/
API u32 dsRemoveAllSrcSwitch(DSID dsId,
                             u32  dwRecvIP,
                             u16  wRecvPort,
                             u32  dwSrcIP,
                             u16  wSrcPort);

/************************************************************
 * 函数名：dsRemoveSrcSwitch
 *
 * 功能： 删除指定的按源转发的规则
 *
 * 实现说明：
 *
 * 参数说明：
 * @param dsId          - 用户标识
 * @param dwRecvIP      - 接收IP，即接收数据包的目的IP
 * @param wRecvPort     - 接收Port，即接收数据包的目的Port
 * @param dwSrcIP       - 接收数据包的源IP
 * @param wSrcPort      - 接收数据包的源Port
 * @param dwSendtoIP    - 转发目的IP
 *
 * 返回值：
 * @return DSOK: 表示成功 ; DSERROR: 表示失败 ;
 ************************************************************/
API u32 dsRemoveSrcSwitch(DSID dsId,
                          u32  dwRecvIP,
                          u16  wRecvPort,
                          u32  dwSrcIP,
                          u16  wSrcPort,
                          u32  dwSendtoIP,
                          u16  wSendtoPort);

API u32 dsSetUserData(DSID dsId,
                      u32  dwLocalIP,
                      u16  wLocalPort,
                      u32  dwLoalIfIP,
                      u32  dwSrcIP ,
                      u16  wSrcPort,
                      u32  dwDstIP,
                      u16  wDstPort,
                      u32  dwDstOutIfIP,
                      BOOL32 bSend,
                      u8* pbyUserData,
                      s32 nUserLen);

/************************************************************
 * 函数名：dsSetFilterFunc
 *
 * 功能： 设置过滤函数
 *
 * 注意：函数指针可以为空，表示清除原有的设置；另外，由于
 * DataSwitch是在另外的线程中调用此函数的，要设置的函数必
 * 须是全局函数；设置的参数，也必须是全局有效的。
 *
 * 实现说明：
 *
 * 参数说明：
 * @param dsId          - 用户标识
 * @param dwRecvIP      - 接收IP，即接收数据包的目的IP
 * @param wRecvPort     - 接收Port，即接收数据包的目的Port
 * @param ptFunc        - 过滤函数指针
 * @param FuncParam     - 为过滤函数传递的参数
 *
 * 返回值：
 * @return DSOK: 表示成功 ; DSERROR: 表示失败 ;
 ************************************************************/
API u32 dsSetFilterFunc(DSID dsId,
                        u32 dwRecvIP,
                        u16 wRecvPort,
                        FilterFunc ptFunc);

/************************************************************
 * 函数名：dsRemoveAll
 *
 * 功能： 删除所有的转发规则
 *
 * 实现说明：
 *
 * 参数说明：
 * @param dsId          - 用户标识
 * @param bKeepDump     - 是否保留所有的dump规则，默认不保留（VX版本暂未实现）
 * 返回值：
 * @return DSOK: 表示成功 ; DSERROR: 表示失败 ;
 ************************************************************/
API u32 dsRemoveAll( DSID dsId, BOOL32 bKeepDump = FALSE );

enum {
    DS_SKIP_POLICY_ROUTING = 0x1 << 0,  //防止被内核策略路由丢弃
};

 /**********************************************************
 * 函数: dsSetSpecifyFwdSrc                                *
 * 功能: 为指定目的地址设置转发数据包所填充的源地址        *
 * 输入:
 * @param dsId          - DSID
 * @param dwLocalIP     - 本地IP
 * @param wLocalPort    - 本地Port
 * @param dwDstIP		- 目的IP
 * @param wDstPort		- 目的端口
 * @param dwMappedIP    - 映射IP
 * @param wMappedPort   - 映射Port
 * @param dwSrcIP		- 源IP
 * @param wSrcPort		- 源端口
 * @dwflags: 伪装规则的flags， 可用于绕过策略路由等
 * 输出: 无                                               *
 * 返回: 成功返回DSOK 否则DSERROR                         *
 * 说明: 如果需要取消源地址设置，将dwMappedIp和wMappedPort*
 *       设置为0                                          *
 **********************************************************/
API u32	dsSetSpecifyFwdSrc(DSID dsId,
                           u32 dwLocalIP, u16 wLocalPort,
						   u32 dwDstIP, u16 wDstPort ,
						   u32 dwMappedIP, u16 wMappedPort,
						   u32 dwSrcIP = 0, u16 wSrcPort = 0,
						   u32 dwflags = 0);

 /**********************************************************
 * 函数: dsSetSendCallback                                *
 * 功能: 设置发送回调函数                                 *
 *       取消时，设置函数指针为NULL即可
 * 输入: dsID           - 创建交换模块时的句柄            *
 *       dwLocalIp      - 本地接收IP                      *
 *       wLocalPort     - 本地接收端口号                  *
 *       dwSrcIP        - 转发目的IP地址                  *
 *       wSrcPort       - 转发目的端口号                  *
 *       pfCallback     - 回调函数
 * 输出: 无                                               *
 * 返回: 无                                               *
 **********************************************************/
API u32 dsSetSendCallback(DSID dsId,
                          u32 dwRecvIP,
                          u16 wRecvPort,
                          u32 dwSrcIP,
                          u16 wSrcPort,
                          SendCallback pfCallback);

 /*********************************************************
 * 函数: dsSetAppDataForSend                              *
 * 功能: 为发送目标设置一个自定义的指针                   *
 *       取消时，设置函数指针为NULL即可                   *
 * 输入: dsID           - 创建交换模块时的句柄            *
 *       dwLocalIp      - 本地接收IP                      *
 *       wLocalPort     - 本地接收端口号                  *
 *       dwSrcIP        - 源IP地址                        *
 *       wSrcPort       - 源端口号                        *
 *       dwDstIP        - 转发目的IP地址                  *
 *       wDstPort       - 转发目的端口号                  *
 *       pAppData       - 自定义指针                      *
 * 输出: 无                                               *
 * 返回:
 *     DSOK:成功 DSERROR:失败                             *
 **********************************************************/
API u32 dsSetAppDataForSend(DSID dsId,
                u32 dwRecvIP,
                u16 wRecvPort,
                u32 dwSrcIP,
                u16 wSrcPort,
                u32 dwDstIP,
                u16 wDstPort,
                void *pAppData);

/*----------- 结束定义udpswitch ----------------------*/

/* 网络地址定义，应该放到osp.h中，暂时放在这里 */
typedef union {
    struct sockaddr_in		v4addr;     //ipv4地址
    struct sockaddr_in6		v6addr;     //ipv6地址
    struct sockaddr_storage staddr;     //socket表示的地址
    //socket无法表示的私有地址类型
    u8  raw_addr[sizeof(struct sockaddr_storage)];
} dsNetAddr;

#define DS_IS_VALID_ADDR(netaddr)   \
    ((netaddr) &&   \
    (((netaddr)->v4addr.sin_family == AF_INET && (netaddr)->v4addr.sin_port) || \
    ((netaddr)->v6addr.sin6_family == AF_INET6 && (netaddr)->v6addr.sin6_port)))

#define DS_IS_VALID_LOCAL_ADDR(netaddr)   \
    ((netaddr) &&   \
    (((netaddr)->v4addr.sin_family == AF_INET && (netaddr)->v4addr.sin_port) || \
    ((netaddr)->v6addr.sin6_family == AF_INET6 && (netaddr)->v6addr.sin6_port)))

#define DS_IS_VALID_REMOTE_ADDR(netaddr)    \
    ((netaddr) &&   \
    (((netaddr)->v4addr.sin_family == AF_INET &&    \
        (netaddr)->v4addr.sin_addr.s_addr && (netaddr)->v4addr.sin_port) || \
    ((netaddr)->v6addr.sin6_family == AF_INET6 &&   \
        (netaddr)->v6addr.sin6_port)))

/* 提供网络字节序地址设置到dsNetAddr结构中 */
#define DS_SET_NETADDR_ADDR(netaddr, type, address)    \
    do {    \
        switch(type) {    \
        case AF_INET:   \
            (netaddr)->v4addr.sin_family = (type);      \
            (netaddr)->v4addr.sin_addr.s_addr = (address);   \
            break;      \
        case AF_INET6:  \
            (netaddr)->v6addr.sin6_family = (type);     \
            break;  \
        default:    \
            break;  \
        }   \
    } while(0)

/* 提供网络地址字符串设置到dsNetAddr结构中 */
#define DS_SET_NETADDR_ADDR_STR(netaddr, type, address)    \
    do {    \
        switch(type) {      \
        case AF_INET:       \
            (netaddr)->v4addr.sin_family = (type);      \
            if (address)    \
                OspPton(type, address, &((netaddr)->v4addr.sin_addr.s_addr));\
            else        \
                (netaddr)->v4addr.sin_addr.s_addr = INADDR_ANY;    \
            break;      \
        case AF_INET6:  \
            (netaddr)->v6addr.sin6_family = (type);     \
            if (address)    \
                OspPton(type, address, &((netaddr)->v6addr.sin6_addr.s6_addr));  \
            else    \
                memcpy(&(netaddr)->v6addr.sin6_addr, &in6addr_any, sizeof(in6addr_any));  \
            break;  \
        default:    \
            break;  \
        }   \
    } while(0)

/* 提供主机序端口号设置到dsNetAddr 中 */
#define DS_SET_NETADDR_PORT(netaddr, type, port)    \
    do {    \
        switch(type) {    \
        case AF_INET:   \
            (netaddr)->v4addr.sin_family = (type);      \
            (netaddr)->v4addr.sin_port = htons(port);   \
            break;      \
        case AF_INET6:  \
            (netaddr)->v6addr.sin6_family = (type);     \
            (netaddr)->v6addr.sin6_port = htons(port);  \
            break;  \
        default:    \
            break;  \
        }   \
    } while(0)

/* -------------------- 开始定义rtpswitch -------------------*/
#define INVALID_RTPSWITCHID ((u32)-1)

//为了多实例将 DSRTPSID定义改为 
/*
 *  31---------------------15-----------------------0
 *  |    DSID               | RTPID                 |
 *  -------------------------------------------------
 */
typedef u32		DSRTPSID;

#define DS_MAX_SECKEY_LEN (512)

//密钥长度
#define DS_SECKEY_LEN_AES_256_GCM (44)
#define DS_SECKEY_LEN_AES_128_GCM (28)
#define DS_SECKEY_LEN_AES_256_ICM (46)
#define DS_SECKEY_LEN_AES_128_ICM (30)
#define DS_SECKEY_LEN_SM4_128_CM  (30)

#define DS_SECKEY_LEN_AES_256_H235 (32)
#define DS_SECKEY_LEN_AES_192_H235 (28)
#define DS_SECKEY_LEN_AES_128_H235 (24)

typedef enum {
	DS_SECKEY_TYPE_UNDEFINED	= 0,
    DS_SECKEY_TYPE_STATIC		= 1, 
	DS_SECKEY_TYPE_QUANTUM		= 2, 
	DS_SECKEY_TYPE_DTLS			= 3,	
} dsSecKeyTypes;

typedef struct {
  u8        keytype;  
  u16		keylen;
  u8		key[DS_MAX_SECKEY_LEN];  
} dsSecKey; 

#define DS_CIPHER_ENABLE      ((u8)1)
#define DS_CIPHER_DISABLE     ((u8)0)

#define DS_CIPHERPOLICY_NONE  ((u8)0)
#define DS_CIPHERPOLICY_H235  ((u8)1)
#define DS_CIPHERPOLICY_SRTP  ((u8)2)

//算法类型
typedef enum {
	DS_SEC_ALG_NONE		= 0,
	DS_SEC_ALG_AES_128	= 1,
	DS_SEC_ALG_AES_192	= 2,
	DS_SEC_ALG_AES_256	= 3,
	DS_SEC_ALG_SM_4     = 4,
}ds_Cipher_Alg_Id;

typedef enum {
	DS_AUTH_ALG_NONE		= 0,
	DS_AUTH_ALG_SHA1		= 1,	
}ds_Auth_Alg_Id;


//模式
typedef enum {
    SRTP_AES_ICM	= 1, 
	SRTP_AES_GCM	= 2,
	
	H235_AES_CBC	= 3,
	H235_AES_ECB	= 4,
	H235_AES_CFB1	= 5,

	SRTP_SM4_CM     = 6,

	SRTP_UNDEFINED  = 0,
} dsSrtpCryptoTypes;


typedef struct {
  u8        enable;//是否启用加解密 1：启用 0：不启用
  u8		policy;//模式 0: none 1：H235 2: srtp 
  u8		isCipher;//是否加解密 1: 加解密 0: 不加解密  
  u32		cipher_alg_id;//算法id   
  u8        cipher_mod;//加密工作模式 
  //u8        ext_cipher;//是否加密扩展头
  dsSecKey  seckey;//密钥
  u8		isAuth;//是否认证
  u32		auth_alg_id;//算法id
  u8        auth_tag_len;//auth tag 长度
  dsSecKey  authKey;//认证密钥 
} dsCipher;

typedef enum {
    DS_RTP_FLAG_SSRC_FIXED = 0x00000001, //固定SSRC
	DS_RTP_FLAG_DUMP_RULE  = 0x00000002, //dump规则
	DS_RTP_FLAG_DISABLE_FEC = 0x00000004, //禁止FEC转发,只对目的设置
	DS_RTP_FLAG_UNDEFINED  = 0x00000000, 
} dsRtpModFlag;

#define DS_EP_ATTR_MAX_SIZE (2048)

//终端属性
typedef union {
	u8 attr_data[DS_EP_ATTR_MAX_SIZE];
	void* align;
}dsEpAttr_t;

/* rtp终端的信息 */
typedef struct {
    dsRtpEndpointId id;     //rtp 终端id
    dsNetAddr addr;         //rtp 终端的网络地址
    s32 ifindex;            //rtp 终端的上线网口

	dsEpAttr_t attr;        //终端属性,可以多个
} dsRtpEndpoint;

#define DS_INIT_RTP_ENDPOINT(endpoint)  \
    do {    \
        (endpoint)->id = DS_RTP_ANY_ID; \
        (endpoint)->ifindex = -1;   \
        memset(&(endpoint)->addr, 0, sizeof((endpoint)->addr));  \
		memset(&(endpoint)->attr, 0, sizeof((endpoint)->attr));  \
    } while(0)

//设置终端回调标识
API u32 dsAddEpAttr_ModFlag( dsRtpEndpoint * ep, dsRtpModFlag modflag );

//设置终端加密属性
API u32 dsAddEpAttr_Cipher( dsRtpEndpoint * ep, const dsCipher * const cipher );


/****************************************************************
 * 函数: dsCreateRtpRtcpSwitch()
 * 功能: 在某个ip地址和端口创建rtpswitch
 * 参数:
 *   dsid: dataswitch 实例id
 *   addr: 要创建rtpswitch的地址和端口信息
 * 输出:
 *   返回值dsrtpswitch id，出错返回INVALID_RTPSWITCHID
 ****************************************************************/
API DSRTPSID dsCreateRtpRtcpSwitch(DSID dsid, dsNetAddr *addr);

/****************************************************************
 * 函数: dsAddRtpSwitchRule() / dsAddRtcpSwitchRule()
 * 功能: 在某个rtpswitch中添加rtp交换规则
 * 参数:
 *   id: rtpswitch的id，标识码流接收的ip地址和端口
 *   src: 码流的源信息，包括原ip地址和端口，原endpoint id信息等
 *        如果不包括ip地址和端口，则不尝试匹配地址和端口
 *        如果不包括endpoint id信息，则不匹配endpoint id信息
 *        如果src == NULL, 收到的所有包都匹配这个规则.
 *   modifier: 码流经过转发后修改的源信息, 如果 == NULL, 不修改
 *   dst: 码流转发到的目的信息，包括目的ip和端口，目的endpoint等
 *   priority: 规则的优先级(1~100), 越大优先级越高。
 * 输出:
 *   返回值DSOK和DSERROR.
 ****************************************************************/
API u32 dsAddRtpSwitchRule(
    DSRTPSID id,
    dsRtpEndpoint *src,
    dsRtpEndpoint *modifier,
    dsRtpEndpoint *dst,
    u32 priority);

API u32 dsAddRtcpSwitchRule(
    DSRTPSID id,
    dsRtpEndpoint *src,
    dsRtpEndpoint *modifier,
    dsRtpEndpoint *dst,
    u32 priority);
/****************************************************************
 * 函数: dsRemoveRtpSwitchRule() / dsRemoveRtcpSwitchRule()
 * 功能: 在某个rtpswitch中删除rtp交换规则
 * 参数:
 *   id: 规则所在的rtpswitch的id.
 *   src: 码流的源信息，包括原ip地址和端口，原endpoint id信息等
 *        如果src == NULL, 匹配所有源
 *   modifier: 码流经过转发后修改的源信息, 如果 == NULL, 不修改
 *   dst: 码流转发到的目的信息，包括目的ip和端口，目的endpoint等
 * 输出:
 *   返回值DSOK和DSERROR.
 ****************************************************************/
API u32 dsRemoveRtpSwitchRule(
    DSRTPSID id,
    dsRtpEndpoint *src,
    dsRtpEndpoint *modifier,
    dsRtpEndpoint *dst);

API u32 dsRemoveRtcpSwitchRule(
    DSRTPSID id,
    dsRtpEndpoint *src,
    dsRtpEndpoint *modifier,
    dsRtpEndpoint *dst);
/****************************************************************
 * 函数: dsDestroyRtpSwitch()
 * 功能: 清除一个rtpswitch
 * 参数:
 *   dsid: dataswitch 实例id
 *   id:   rtp switch id
 * 输出:
 *   返回值DSOK和DSERROR.
 ****************************************************************/
 API u32 dsDestroyRtpSwitch(DSID dsid, DSRTPSID id);

/*---------------- 定义rtpswitch 结束 -------------------------*/

/*---------------- 定义sipswitch 开始 -------------------------*/
#define INVALID_SIPSWITCHID ((u32)-1)

 //为了多实例将 DSSIPSID定义改为 
/*
 *  31---------------------15-----------------------0
 *  |    DSID               | SIPID                 |
 *  -------------------------------------------------
 */
 typedef u32		DSSIPSID;

#define DS_SIP_INVALID_ID   ((u8*)0x0)

enum
{
    /* for src match */
    DS_SRC_SIP_ANY_ID = 0x0,    //转发时源不匹配任何信息
    DS_SRC_SIP_MATCH_ID = 0x1,  //转发时源必须匹配e164和callid

    /* for modifier action */
    DS_MOD_SIP_UNTOUCH_ID = 0x0, //转发时不修改包中的e164和callid信息
    DS_MOD_SIP_CHANGE_ID = 0x1,  //转发时修改包中的e164和callid信息
    DS_MOD_SIP_REMOVE_ID = 0x2,  //转发时去除包中的e164和callid信息

    /* for forward to destination */
    DS_DST_SIP_TO_IP = 0x0,     //转发到指定的ip地址和端口
    DS_DST_SIP_TO_ID = 0x1,     //转发到指定的e164号和callid终端
};

#define DS_MAX_E164_LEN     64
#define DS_MAX_CALLID_LEN   64

/* sip终端的信息 */
typedef struct {
    u8 e164[DS_MAX_E164_LEN];
    u8 callId[DS_MAX_CALLID_LEN];
    u16 action;     //标识e164和callid中的信息如何使用
    s16 ifindex;            //sip 终端的上线网口
    dsNetAddr addr;         //sip 终端的网络地址
} dsSipEndpoint;

#define DS_INIT_SIP_ENDPOINT(endpoint)  \
    do {    \
        (endpoint)->action = 0x0; \
        (endpoint)->ifindex = -1;   \
        memset(&((endpoint)->e164[0]), 0, sizeof((endpoint)->e164)); \
        memset(&((endpoint)->callId[0]), 0, sizeof((endpoint)->callId)); \
        memset(&(endpoint)->addr, 0, sizeof((endpoint)->addr));  \
    } while(0)

/****************************************************************
 * 函数: dsCreateSipSwitch()
 * 功能: 在某个ip地址和端口创建sipswitch
 * 参数:
 *   dsid: dataswitch 实例id
 *   addr: 要创建sipswitch的地址和端口信息
 * 输出:
 *   返回值dssipswitch id，出错返回INVALID_SIPSWITCHID
 ****************************************************************/
API DSSIPSID dsCreateSipSwitch(DSID dsid, dsNetAddr *addr);

/****************************************************************
 * 函数: dsAddSipSwitchRule()
 * 功能: 在某个sipswitch中添加sip交换规则
 * 参数:
 *   id: sipswitch的id，标识码流接收的ip地址和端口
 *   src: 码流的源信息，包括原ip地址和端口，原endpoint id信息等
 *        如果想根据源ip地址和端口转发，
 *          设置addr信息，且action为DS_SRC_SIP_ANY_ID
 *        如果想根据e164和callid信息转发，
 *          设置e164和callid，且action为DS_SRC_SIP_MATCH_ID
 *        如果src == NULL, 收到的所有包都匹配这个规则.
 *
 *   modifier: 码流经过转发后修改的源信息, 如果 == NULL, 不修改
 *         如果想修改该数据包的源ip和端口，设置addr信息
 *         如果想修改该数据包的e164和callid信息，设置e164和callid，且
 *          action设置为DS_MOD_SIP_CHANGE_ID或者DS_MOD_SIP_REMOVE_ID
 *
 *   dst: 码流转发到的目的信息，包括目的ip和端口，目的endpoint等
 *         如果目标设备的公网ip不可知，想通过nat穿越包获取，addr不填，
 *         填对应的e164和callid，后续收到nat穿越包会自动更新这个交换的地址。
 *
 *   priority: 规则的优先级(1~100), 越大优先级越高。
 * 输出:
 *   返回值DSOK和DSERROR.
 ****************************************************************/
API u32 dsAddSipSwitchRule(
    DSSIPSID id,
    dsSipEndpoint *src,
    dsSipEndpoint *modifier,
    dsSipEndpoint *dst,
    u32 priority);

/****************************************************************
 * 函数: dsRemoveSipSwitchRule()
 * 功能: 在某个sipswitch中删除sip交换规则
 * 参数:
 *   id: 规则所在的sipswitch的id.
 *   src: 码流的源信息，包括原ip地址和端口，原endpoint id信息等
 *        如果src == NULL, 匹配所有源
 *   modifier: 码流经过转发后修改的源信息, 如果 == NULL, 不修改
 *   dst: 码流转发到的目的信息，包括目的ip和端口，目的endpoint等
 * 输出:
 *   返回值DSOK和DSERROR.
 ****************************************************************/
API u32 dsRemoveSipSwitchRule(
    DSSIPSID id,
    dsSipEndpoint *src,
    dsSipEndpoint *modifier,
    dsSipEndpoint *dst);

/****************************************************************
 * 函数: dsDestroySipSwitch()
 * 功能: 清除一个sipswitch
 * 参数:
 *   dsid: dataswitch 实例id
 *   id:   sip switch id
 * 输出:
 *   返回值DSOK和DSERROR.
 ****************************************************************/
 API u32 dsDestroySipSwitch(DSID dsid, DSSIPSID id);

/*---------------- 定义sipswitch 结束 -------------------------*/

/**********************************************************
 * 函数: dsGetRecvPktCount                                *
 * 功能: 查询接收总包数                                   *
 * 输入: dsID        - 创建交换模块时的句柄               *
 *       dwRecvIP   - 本地接收IP                          *
 *       wRecvPort  - 本地接收端口号                      *
 *       dwSrcIP     - 源IP                               *
 *       wSrcPort    - 源端口号                           *
 *       dwRecvPktCount  - 接收总包数                     *
 * 输出: 无                                               *
 * 返回: 成功返回DSOK 否则DSERROR                         *
 **********************************************************/
API u32 dsGetRecvPktCount( DSID dsId, u32 dwRecvIP, u16 wRecvPort ,
						  u32 dwSrcIP, u16 wSrcPort, u32& dwRecvPktCount);

/**********************************************************
 * 函数: dsGetSendPktCount                                *
 * 功能: 查询发送总包数                                   *
 * 输入: dsID        - 创建交换模块时的句柄               *
 *       dwRecvIP   - 本地接收IP                         *
 *       wRecvPort  - 本地接收端口号                     *
 *       dwSrcIP     - 源IP                               *
 *       wSrcPort    - 源端口号                           *
 *       dwSendtoIP     - 转发目的IP地址                     *
 *       wSendtoPort    - 转发目的端口号                     *
 *       dwSendPktCount  - 发送总包数                     *
 * 输出: 无                                               *
 * 返回: 成功返回DSOK 否则DSERROR                         *
 **********************************************************/
API u32 dsGetSendPktCount( DSID dsId, u32 dwRecvIP, u16 wRecvPort ,
						  u32 dwSrcIP, u16 wSrcPort,
						  u32 dwSendtoIP, u16 wSendtoPort, u32& dwSendPktCount);

/**********************************************************
 * 函数: dsGetRecvBytesCount	                          *
 * 功能: 查询接收总字节数                                 *
 * 输入:												  *
 * 输出: 无                                               *
 * 返回: 返回即时接收字节数								  *
 **********************************************************/
API s64 dsGetRecvBytesCount( );

/**********************************************************
 * 函数: dsGetSendBytesCount	                          *
 * 功能: 查询发送总字节数                                 *
 * 输入:												  *
 * 输出: 无                                               *
 * 返回: 返回即时字节数									  *
 **********************************************************/
API s64 dsGetSendBytesCount( );

/************************************************************
 * 函数： dsinfo
 * 功能： 显示所有的转发规则，及所有正在监听的端口
 * 输入：
 * 输出：
 * 返回：
 ************************************************************/
API void dsinfo();

/************************************************************
 * 函数： dsver
 * 功能： 显示Dataswitch的版本信息
 * 输入：
 * 输出：
 * 返回：
 ************************************************************/
API void dsver();

/************************************************************
 * 函数： dshelp
 * 功能： 显示Dataswitch所提供的命令的帮助信息
 * 输入：
 * 输出：
 * 返回：
 ************************************************************/
API void dshelp();

/*显示定时器*/
API void dsshowrtcptimer();

/************************************************************
 * 函数： dedebug
 * 功能： 打开/关闭调试信息
 *
 * 输入：
 * @param op            - 指明是设置还是清除：set, clear
 *                        (仅在WIN32有效)
 * 输出：
 * 返回：
 ************************************************************/
API void dsdebug(const char* op = NULL);

/************************************************************
 * 函数： dedebug
 * 功能： 打开/关闭更高一级调试信息
 * 单独设置此函数是因为调试信息会影响整体性能
 *
 * 输入：
 * @param op            - 指明是设置还是清除：set, clear
 *                        (仅在WIN32有效)
 * 输出：
 * 返回：
 ************************************************************/
API void dsdebug2();

 API void dstrace(DSID dsId, s8* pszLocalIP, u16 wLocalPort, u32 dwTraceNum);

 /**********************************************************
 * 函数: dsStartRtcpRR                               *
 * 功能: 设置发送RR报告包,必须存在本地节点,且未设置过发送RR包  *
 * 输入:
 * @param dsId          - DSID
 * @param dwLocalIP     - 本地IP
 * @param wLocalPort    - 本地Port
 * @param dwDstIP		- 目的IP
 * @param wDstPort		- 目的端口
 * @param dwInterval	- 间隔时间(单位:秒)
 * @param dwRtcpIP		- 接受rtcp的IP(默认则RR包信息将没有LSR DLSR信息)
 * @param wRtcpPort		- 接受rtcp的Port
 * 输出: 无                                               *
 * 返回: 成功返回DSOK 否则DSERROR                         *
 **********************************************************/
API u32 dsStartRtcpRR(DSID dsId,
                      u32 dwLocalIP, u16 wLocalPort,
                      u32 dwDstIP, u16 wDstPort,
                      u32 dwInterval,
                      u32 dwRtcpIP = 0, u16 wRtcpPort = 0);

 /**********************************************************
 * 函数: dsStartRtcpRR                               *
 * 功能: 取消设置发送RR报告包，必须存在本地节点,且设置过发送RR包  *
 * 输入:
 * @param dsId          - DSID
 * @param dwLocalIP     - 本地IP
 * @param wLocalPort    - 本地Port
 * @param dwRtcpIP		- 接受rtcp的IP(默认则RR包信息将没有LSR DLSR信息)
 * @param wRtcpPort		- 接受rtcp的Port
 * 输出: 无                                               *
 * 返回: 成功返回DSOK 否则DSERROR                         *
 **********************************************************/
API u32 dsStopRtcpRR(DSID dsId,
                     u32 dwLocalIP, u16 wLocalPort,
                     u32 dwRtcpIP = 0, u16 wRtcpPort = 0);

 /**********************************************************
 * 函数: DsGetUdpSocket                               *
 * 功能: 获取一个dataswitch的端口去发送数据, 提供给proxy   *
 *       client使用以解决无法使用raw socket的问题。        *
 * 输入:
 * @param dsId          - DSID
 * @param dwLocalIP     - 本地IP
 * @param wLocalPort    - 本地Port
 * 输出: 无                                               *
 * 返回: 成功返回socket 否则invalid_socket                *
 **********************************************************/
API SOCKHANDLE DsGetUdpSocket(DSID dsId, u32 dwLocalIP, u16 wLocalPort);

 /**********************************************************
 * 函数: DsReleaseUdpSocket                                *
 * 功能: 释放获取到的dataswitch socket。 提供给proxy       *
 *       client使用以解决无法使用raw socket的问题。        *
 * 输入:
 * @param SOCKHANDLE          - socket
 * 输出: 无                                               *
 * 返回: 成功返回DSOK 否则DSERROR                         *
 **********************************************************/
API u32 DsReleaseUdpSocket(DSID dsId, SOCKHANDLE socket);
#endif
