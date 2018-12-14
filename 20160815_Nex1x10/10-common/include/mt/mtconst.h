#ifndef _MTCONST_H_
#define _MTCONST_H_

#include "kdvtype.h"
#include "kdvdef.h"

//app id 定义
//划分给产品模块使用的范围
#define AID_PRODUCT_BGN     (u32)50
#define AID_PRODUCT_END     (u32)100

//组件模块app id定义
#define AID_MTSYSCTRL		(u32)(AID_MT_BGN + 1)     //系统控制
#define AID_DATACONFCLIENT  (u32)(AID_MT_BGN + 2)     //数据会议客户端
#define AID_FTPDOWNLOAD     (u32)(AID_MT_BGN + 3)     //数据会议文件下载
#define AID_MTMP            (u32)(AID_MT_BGN + 4)     //mtmp模块

//////dispatch 和access 调整是为了兼容 access重构
#define AID_MTDISPATCH2     (u32)(AID_MT_BGN + 6)     //消息调度模块
#define AID_MTDISPATCH      AID_MTDISPATCH2
#define AID_MTACCESS        (u32)(AID_MT_BGN + 5)     //终端客户端接入模块

#define AID_AGENT           (u32)(AID_MT_BGN + 7)     //网管agent
#define AID_GUARD           (u32)(AID_MT_BGN + 8)     //网管guard
#define AID_MTAPI           (u32)(AID_MT_BGN + 9)     //MTAPI
#define AID_MTPA            (u32)(AID_MT_BGN + 10)    //mtpa模块
#define AID_SIPMODULE       (u32)(AID_MT_BGN + 11)    //协议层sipmoule,终端指定
#define AID_SIPSTACKIN      (u32)(AID_MT_BGN + 12)    //协议层sipstackout， 终端指定
#define AID_SIPSTACKOUT     (u32)(AID_MT_BGN + 13)    //协议层sipstackin, 终端指定
#define AID_MTMC            (u32)(AID_MT_BGN + 14)    //内置mc模块
#define AID_MISC            (u32)(AID_MT_BGN + 15)    //小业务模块
#define AID_MTH323SERVICE   (u32)(AID_MT_BGN + 16)    //mth323Service
#define AID_MTH323STACKOUT  (u32)(AID_MT_BGN + 17)    //mth323stakcout
#define AID_MTH323STACKIN   (u32)(AID_MT_BGN + 18)    //mth323stackin
#define AID_MTVOD           (u32)(AID_MT_BGN + 19)    //点播模块
#define AID_REST			(u32)(AID_MT_BGN + 20)    //rest模块
#define DONT_USE_ME 		122                       //不要使用122，她已经被OSP库内部使用了
#define AID_IM				(u32)(AID_MT_BGN + 22)    //rest模块
#define AID_AGENTADP        (u32)(AID_MT_BGN + 23)    //网管适配库
#define AID_UPGRADE         (u32)(AID_MT_BGN + 24)    //升级子系统
#define AID_CFGSRV	        (u32)(AID_MT_BGN + 25)    //配置服务
#define AID_MTMCSERVICE	    (u32)(AID_MT_BGN + 26)    //内置mc模块
#define AID_MTRECORD	    (u32)(AID_MT_BGN + 27)    //本地地址簿&呼叫记录
#define AID_SATSERVICE	    (u32)(AID_MT_BGN + 28)    //sat service app
#define AID_SATSTACK	    (u32)(AID_MT_BGN + 29)    //sat stack app
#define AID_MTSERVICE		(u32)(AID_MT_BGN + 30)	  //mtservice模块
#define AID_MTNETMANAGER    (u32)(AID_MT_BGN + 31)    //网络管理
#define AID_XMPP_JINGLE     (u32)(AID_MT_BGN + 32)    //libjingle 业务APP

#define AID_MT_AUTOTEST     (u32)(AID_MT_BGN + 33)    //终端硬件自动化测试应用ID
#define AID_MT_AUTOTESTCLIENT (u32)(AID_MT_BGN + 34)  //终端硬件自动化终端应用ID 
#define AID_MT_PINGTEST (u32)(AID_MT_BGN + 35)		  //ping测试网络
#define AID_MTSEC           (u32)(AID_MT_BGN + 36)    //mtsec模块
#define AID_MTDCS           (u32)(AID_MT_BGN + 37)    //mtdcs模块
#define AID_MTKEYDRIVER     (u32)(AID_MT_BGN + 38)    //mtkeydriver模块
#define AID_MTKEYDRIVER_OSD (u32)(AID_MT_BGN + 39)    //OSD的keydriver应用ID 
#define AID_MTAI            (u32)(AID_MT_BGN + 40)    //mtai 
#define AID_AICAMERA        (u32)(AID_MT_BGN + 41)    //mtaicamera app Id

// 子系统最大数量
#define MT_SYS_NUM_MAX		(u32)40

// 字符串长度
#define MT_STR_LEN_4		(u32)4
#define MT_STR_LEN_8		(u32)8
#define MT_STR_LEN_16		(u32)16
#define MT_STR_LEN_32		(u32)32
#define MT_STR_LEN_64		(u32)64
#define MT_STR_LEN_128		(u32)128
#define MT_STR_LEN_256		(u32)256
#define MT_STR_LEN_512		(u32)512
#define MT_STR_LEN_1024		(u32)1024
#define MT_STR_LEN_2048		(u32)2048
#define MT_STR_LEN_4096		(u32)4096
#define MT_STR_LEN_8192		(u32)8192
#define MT_STR_LEN_URI		    (u32)(128*1024)

#define MT_SIP_LEN_XML      (u32)10240
#define MT_MAX_SIP_UNCOMPRESS_XMLLEN (u32)(1024*100)

#define MT_MAX_NUM_5		(u32)5
#define MT_MAX_NUM_10		(u32)10
#define MT_MAX_NUM_15		(u32)15
#define MT_MAX_NUM_16		(u32)16
#define MT_MAX_NUM_20		(u32)20
#define MT_MAX_NUM_25		(u32)25
#define MT_MAX_NUM_30		(u32)30
#define MT_MAX_NUM_32       (u32)32
#define MT_MAX_NUM_40		(u32)40
#define MT_MAX_NUM_50		(u32)50
#define MT_MAX_NUM_100		(u32)100

#define MT_E164_LEN			(u32)13

#define MT_LEN_4K          (u32)(1 << 12)
#define MT_LEN_8K          (u32)(1 << 13)
#define MT_LEN_16K          (u32)(1 << 14)
#define MT_LEN_24K          (u32)(24 * 1024)
#define MT_LEN_32K          (u32)(1 << 15)

#ifndef MT_MAX_PATH
#define MT_MAX_PATH			(u16)256  /* 定义最大路径长度 */
#endif

#define MT_DCS_POINT_MAX		5000
#define MT_DCS_CONF_USER_MAX	192
#define MT_DCS_WB_MAX			64

//无效值定义
#define INVALID_U8   (u8)(~0)
#define INVALID_U16  (u16)(~0)
#define INVALID_U32  (u32)(~0)
#define INVALID_S8   (s8)(~0)
#define INVALID_S16  (s16)(~0)
#define INVALID_S32  (s32)(~0)

//表示u32数字转换字符串最多占十个字节
#define MT_U32_MAX_LEN 10

//终端核心进程监听端口
#define MT_KERNEL_LISTEN_PORT (u16)60001

//终端内部RPC服务器监听端口
#define RPC_SERVER_PORT       (u16)8000

//<数据共享服务器监听端口
#define DSS_PORT              (u16)12581 

//================厂商定义============
const u32 VENDOR_MICROSOFT_NETMEETING = 1;
const u32 VENDOR_KEDA = 2;
const u32 VENDOR_HUAWEI = 3;
const u32 VENDOR_POLYCOM = 4;
const u32 VENDOR_POLYCOM_MCU = 5;
const u32 VENDOR_TANDBERG = 6;
const u32 VENDOR_RADVISION = 7;
const u32 VENDOR_VCON = 8;
const u32 VENDOR_SONY = 9;
const u32 VENDOR_VTEL = 10;
const u32 VENDOR_ZTE = 11;
const u32 VENDOR_ZTE_MCU = 12;
const u32 VENDOR_CODIAN = 13;
const u32 VENDOR_AETHRA = 14;
const u32 VENDOR_CHAORAN = 15; //超然
const u32 VENDOR_AVCON  = 16; //华平
const u32 VENDOR_DONJIN = 17; //东进GW
const u32 VENDOR_CISCO = 18;
const u32 VENDOR_SMARTPHONE = 19;

const u32 VENDOR_UNKNOWN = 50;


//////conf模块定义的常量
#define MTCONF_MAX_BANDWIDTH        (u32)(8192)      ///最大带宽8M
#define MTCONF_MAX_BANDWIDTH_SKY100 (u32)(4096)      ///最大带宽4M
#define AUTO_ASSBANDWIDTH_RATE      (u32)30          ///auto的双流带宽比  /100 

#define MTCONF_RRQ_TIMETOLIVE       (u32)(20)          //轻量级注册时间为60秒,5s用于测试, 这里设置到协议栈单位为s，非ms

#define MTCONF_UIAPPLYCHIEME_TIMEOUT  (u32)(30*1000)       // 申请插话定时器：30秒
#define MTCONF_UIAPPLYSPEAK_TIMEOUT   (u32)(30*1000)       // 申请发言定时器：30秒
#define MTCONF_UIAPPLYCHAIR_TIMEOUT   (u32)(30*1000)       // 申请主席定时器：30秒
#define MTCONF_GetAllTerminal_TIMEOUT (u32)(10*1000)       // 获取与会终端列表信息定时器：10秒
#define MTCONF_CONFLIST_TIMEOUT       (u32)(4*1000)        //获取会议列表没有收到结束标志，认为超时
#define MTCONF_CREATECONF_TIMEOUT     (u32)(20*1000)        //创建会议超时20s， 等收到平台setup为止
#define MTCONF_JOINCONF_TIMEOUT       (u32)(20*1000)        //参加会议超时20s， 等收到平台setup为止
#define GETBWE_STATUS_TIMEOUT         (u32)(5*1000)         //动态带宽检测，每隔5s,检测一次
#define PRI_VIDEO_OFF_TIMEOUT         (u32)(2*1000)         //呼叫建立后，超时检测视频通道收发，都没开，告诉上层

#define MTCONF_SECSTRONGATH_TIMEOUT   (u32)(2*60*1000)       //强认证超时时间
#define MTCONF_SECWAITCALL_TIMEOUT    (u32)(5*60*1000)       //等待强认证会议呼叫

//#define GKNONSTAND_PORT             (u32)1759        //GK非标侦听端口
#define GKLISTENING_PORT              (u32)1719        //GK标准 侦听端口
#define STAND_H323CALLING_PORT        (u32)1720        //h323标准侦听端口
#define NONSTAND_H323CALLING_PORT     (u32)1760        //h323非标侦听端口
#define NONSTAND_H323CALLING_PORT_END (u32)1780        //在非标端口在[1760,1780]端口中找空闲的端口
#define SIPSTANDLISTENING_PORT        (u32)5060        //sip标准侦听端口
#define SIPTLSLISTENING_PORT          (u32)5061        //sipTLS侦听端口

#define MTCONF_NAME                  "mtconf"      //填在mtmsg的userdata字段， 表示这个消息由mtconf模块处理,具体格式为mtconf*handle(0*0)
#define MTMC_NAME                    "mtmc"        //填在mtmsg的userdata字段， 表示这个消息由mtmc模块处理,具体格式为mtmc*handle(mchandle*otherhandle)
#define MTPA_NAME                    "mtpa"        //填在mtmsg的userdata字段， 表示这个消息由mtma模块处理,具体格式为mtpa*hande(pahandle*otherhandle)
#define MTH323_NAME                  "mth323"      
#define MTMCC_NAME                   "mtmcc"       //填在mtmsg的userdata字段， 表示这个消息由mtconf模块处理,具体格式为mtmcc*handle(0*0)
#define MTVERSION50                  "MT-50"       //5.0终端的version定为"MT-50"
#define MTH323PROXYPORTSIZE          (u32)40       //代理内部需要预留40个端口


#define MTPA_CONFESTABLISH_TIMEOUT   (u32)(32*1000)       //秒
#define MTPA_DISCONNECT_TIMEOUT      (u32)(20*1000)       //秒
#define MTPA_TLSRENEGOTIATE_TIMEOUT  (u32)(3600*1000)      //秒

#define MAX_MAINAUDIO_NUM            (u32)3    ///主流最大音频发送接收通道数
#define MAX_MAINVIDEO_NUM            (u32)3    ///主流最大视频发送接收通道数

#define MAX_MAINVIDEO_EMBED_FPS       (u32)60   ///硬终端主流最大帧率，只针对264,265
#define MAX_PCASSVIDEO_EMBED_FPS      (u32)5   ///硬终端pc辅流最大帧率，只针对264,265
#define MAX_VIDEOASSVIDEO_EMBED_FPS   (u32)60   ///硬终端video辅流， 最大帧率，只针对264,265
#define MAX_MAINVIDEO_TL_FPS          (u32)30   ///致邻主流最大帧率，只针对264,265
#define MAX_PCASSVIDEO_TL_FPS         (u32)15   ///致邻pc辅流最大帧率，只针对264,265

////////内置mc宏定义
#define MTMC_MAX_MTNUM              (u32)8                   //内置mc最多接终端数（包括mc终端本身）
#define MTMC_MAX_MIXER_NUM          (u32)8                   //mc混音器数量
#define MTMC_MAX_VMP_NUM            (u32)8                   //画面合成支持的最大数量
#define MTMC_MAX_STREAM_NUM         (u16)1                   //多流支持的最大数量
#define MTMC_MCC_HANDLE             (u16)0                   //mcc作为终端的句柄标识、
#define MTMC_LOCALMT_HANDLE         (u16)1                   //本地终端的句柄标识
#define MTMC_MCUID                  (u16)192                   //mcu的标识符

const u32    MT_MAX_H323ALIAS_LEN       =   32;              // 终端别名最大长度
const u32    MT_MAXLEN_SMSTEXT          =   1024*2;          //短消息内容最大长度

#define AUDIO_BITRATE_DEFAULT        64           // 音频码率默认值, 如果上层设置的码率小于等于此值，认为是音频呼叫,单位为kbps
#define AUDIO_BITRATE_128            128          //(384,768] 范围给音频的码率
#define AUDIO_BITRATE_192            192          //(768,2048] 和 （2048, 8M]范围给音频的码率        


//g7221码率定义
#define   MT_G7221_RATE_24           (u8)0x01
#define   MT_G7221_RATE_32           (u8)0x02
#define   MT_G7221_RATE_48           (u8)0x04
#define   MT_G7221_RATE_NONE         (u8)0x00

#define   MT_AAC_RATE                96      //lc/ld码率


/*********************************************************/
/*         Opus格式音频的码率定义(Kbps)                    */
/**********************************************************/
#define OPUS_MIN_BITRATE         (u16)8      //最低码率
#define OPUS_MAX_BITRATE_HD      (u16)56     //高清终端最高码率
#define OPUS_MAX_BITRATE_TL      (u16)32     //TL最高码率
#define OPUS_MAX_BITRATE_MOBILE  (u16)16     //移动终端最高码率



//编解码器最大数量
#define MAX_VENC_NUM  (u8)8
#define MAX_VDEC_NUM  (u8)8
#define MAX_AENC_NUM  (u8)8
#define MAX_ADEC_NUM  (u8)8


//im相关
#define  IM_MAX_ID_LEN                      64
#define  IM_MAX_ADDRESS_LEN                 32
#define  IM_MAX_PATH_LEN                    256
#define  IM_MAX_HEAD_PORTRAIT_LEN           4096        
#define  IM_MAX_SEND_PIC_COUNT              3    // 每次最多只能发送3张截图
#define  IM_MAX_CHAT_ROOMNAME_LEN           32
#define  IM_ENTERPRISE_NAME_LEN             32
#define  IM_MAX_MT_TYPE                     8
#define  IM_MAX_CHATROOM_ID_LEN             128
#define  IM_MAX_ROSTER_ITEMS_PER_BATCH      20        
#define  IM_MAX_SID_LEN                     32
#define  IM_MAX_FILE_NAME_LEN               256
#define  IM_MAX_ROSTER_ITEMS_PER_BATCH      20        
#define  IM_MAX_SID_LEN                     32
#define  IM_MAX_FILE_NAME_LEN               256
#define  IM_MAX_FONT_FACE_LEN               32
#define  IM_MAX_CHATROOM_MEMBER_CACHE_ARRAY_SIZE  40
#define  IM_MAX_PERSISTENT_CHATROOM_ARRAY_SIZE    40
#define  IM_MAX_MEMBER_STATUS_CACHE_ARRAY_SIZE  10
#define  IM_MAX_RESOURCE_LEN                8
#define  IM_MAX_CHATROOM_SCREEN_CNT         16
#define  IM_MAX_CONTEXT_LEN                 36
#define  IM_MAX_BATCH_USERS_COUNT           64

#define  IM_SOCK5_ADDR_NAME_LEN             32
#define  IM_SOCK5_USERNAME_LEN              32
#define  IM_SOCK5_PASSWORD_LEN              32

#define  IM_CUSTOM_TYPE_SPLASH              1
#define  IM_MAX_CONFIG_KEY_LEN              32
#define  IM_MAX_CONFIG_VALUE_LEN            2048
#define  IM_MAX_CONFIG_ITEMS_PER_BATCH      4
#define  IM_MAX_SCREENED_CHATROOM_COUNT     32
#define  IM_MAX_MOID_LEN                    64

#define  WEIBO_MAX_UID_LEN                  64
#define  WEIBO_MAX_NAME_LEN                 64
#define  WEIBO_MAX_EMAIL_LEN                64
#define  WEIBO_MAX_MUGSHOT_LEN              64
#define  WEIBO_MAX_GROUP_NAME_LEN           64

#define  REST_COMMON_BUF_SIZE               64

#define  REST_ACCOUNT_INFO_BIT_INDEX_MOBILE   0x01
#define  REST_ACCOUNT_INFO_BIT_INDEX_EXT      0x02
#define  REST_ACCOUNT_INFO_BIT_INDEX_SEAT     0x04
#define  REST_ACCOUNT_INFO_BIT_INDEX_POSITION 0x08
#define  REST_ACCOUNT_INFO_BIT_INDEX_BRIEF    0x10
#define  REST_ACCOUNT_INFO_BIT_INDEX_SEX      0x20
#define  REST_ACCOUNT_INFO_BIT_INDEX_NAME     0x40

#define MT_MAX_MONITOR_GROUP_COUNT	20		//监控设备组最大传20个
#define MT_MAX_MONITOR_DEVICE_COUNT 10		//设备信息最大传10个

#define MAX_PERSONAL_TEMPLATE_LIST_NUM 4		// 获取个人模板列表，每包最大个数
#define MAX_PUBLIC_TEMPLATE_LIST_NUM       10		// 获取公共模板列表，每包最大个数
#define MAX_RECORD_MEMBER_NUM          8    //录像列表成员最大数量
#define MAX_CONF_TERMINAL_NUM          8    //会议终端列表最大成员数

#define  MAX_PROXY_ADDR_LEN           64
#define  MAX_PROXY_USER_LEN           64
#define  MAX_PROXY_PWD_LEN            64

#define  REST_MAX_DATETIME_LEN            32
#define  MAX_XMPP_HANDLE_COUNT			1
#define  MAX_DELAY_CHAT_ROOM_INFO_COUNT 128

#define  MT_MAX_CALLRECORD_NUM	 300  // 呼叫记录最大条数
#define  MT_MAX_LOCALROSTER_NUM  1000  // 本地地址簿最大条数

#define MAX_PROXYSERVER_NAME_LEN  255         //代理防火墙域名的最大长度

#define		MAXLEN_GROUPINFO_LIST			(u32)20         //用户组信息列表最大长度
#define		MAX_QUERY_USERONLINE_NUM            5      // 一次最多查询的员工在线状态数，统一成五个，10个已经发不上来了 20130104  by zhouyanhua

//2. 数据的压缩编码类型
#define		DMS_DATA_COMPRESS_TYPE_UNDO		(u16)0			//没有压缩
#define		DMS_DATA_COMPRESS_TYPE_ZLIB		(u16)1			//Zlib压缩

//3. 长度的相关定义
#define		MAXLEN_USER_SIGNATURE			(u16)512        //用户个性签名最大长度
#define		MAXLEN_GROUPNAME				(u16)64         //用户组的最大长度
#define		MAXLEN_MULTI_CHAT_NAME			(u16)64         //多人聊天的会话名称的最大长度
#define		MAXLEN_U64STRING				(u16)20         //用户组的最大长度
#define		MAXLEN_DEPARTMENT_NAME			(u16)64         //部门名称的最大长度

#define		MAXLEN_SELFDEF_LIST				(u32)1          //用户自定义信息列表最大长度
#define		MAXLEN_GROUPINFO_LIST			(u32)20         //用户组信息列表最大长度
#define		MAXLEN_ONLINESTATE_LIST			(u32)20         //用户状态信息列表最大长度
#define		MAXLEN_USER_LIST				(u32)20         //用户列表最大长度
#define		MAXLEN_MEMBER_INFO_LIST			(u32)10         //好友列表最大长度
#define		MAXLEN_DEVICEINFO_LIST			(u32)20         //用户设备信息列表最大长度
#define		MAXLEN_DEPARTMENTINFO_LIST		(u32)20         //部门信息列表最大长度
#define		MAXLEN_EMPLOYEE_INFO_LIST		(u32)20         //员工列表最大长度


#define		MAXLEN_SENDMESSAGE_BUF			(u32)(1600*2)   //发送消息给用户的列表最大长度
#define		INVALID_MULTICHAT_ID			(u32)0          //无效的多人聊天ID

//4.特殊用户组的序列号
#define		GROUPSN_INVALID                 (u64)0			//无效的组序列号
#define		GROUPSN_TOPLEVEL_PARENT         (u64)0			//顶级组的父组序列号
#define		GROUPSN_UNGROUPING              (u64)1			//未分组 组序列号
#define		GROUPSN_BLACKLIST               (u64)2			//黑名单 组序列号

#define		GEOUPSN_NORMAL_BENGIN           (u64)1001		//正常分组的起始序号(前面的序号预留给特殊的分组)
#define		MEMBERSN_NORMAL_BENGIN          (u64)10001		//正常成员的起始序号(前面的序号预留给特殊的成员)
#define		DEPARTMENTSN_NORMAL_BENGIN      (u64)10001		//正常部门的起始序号(前面的序号预留给特殊的部门)
#define		EMPLOYEE_NORMAL_BENGIN			(u64)10001		//正常部门的起始序号(前面的序号预留给特殊的员工)

//5.特殊部门的序列号
#define		DEPARTMENTSN_TOPLEVEL_PARENT     (u64)0			//顶级部门的父部门序列号
#define     MAX_CHAT_MSG_LEN            1600    // 每条短消息限制长度为1600个字节
#define		MAX_CHAT_BYTE_LEN			4
#define     MT_MAX_TUI_DOMAINNAME_LEN	32
#define		MAX_DEVICE_STRLEN			32   // rest中设备类型字符串最大长度
#define		HTTP_PROTOCOL               "http"
#define		HTTPS_PROTOCOL              "https"
#define     MT_MAXLEN_TELEPHONE         32            // 联系电话的最大长度
#define		MAX_SAVE_PORTRAIT_PATH      256     // 保存图像的路径
#define		MAX_QUARY_USER			    5           // 一次最多查询的用户详细信息个数
#define		MAX_SAVE_PORTRAIT_FILENAME  64      // 保存图像的文件名
#define		MAX_DEPARTMENT_COUNT		200      // 一次分包200个部门信息给上层
#define		MAX_EMPLOYEE_COUNT		    100      // 一次分包100个员工信息给上层
#define		MAX_USER_DETAIL_INFO		6      // 每次最多POST给界面的详细信息个数
#define		MT_MAX_COUNT				20
#define		MT_MAX_PARTICIPANT_NUM		10			//会议参与人
#define		MAX_ADDRESS_NUM				20
#define     MAX_PATH                    260    //铃声路径长度

//6、tls相关 新添加
#define     TLS_CRYPTOKEY_LEN    46       
#define     SIP_CALLID_LEN       37       
#define     SIP_CALLID_STR       17       

#define		MT_DCS_MATRIXVALUE		9


const u32 MAX_PORT_VALUE = 65536;  //由65535改为 65536 ，因为端口使用范围为1 - 65535，一旦65535端口被占，程序崩溃

#endif