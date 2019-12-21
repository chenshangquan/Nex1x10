/*******************************************************************************//**
*@file          mtapi_def.h
*@brief         提供mtapi所有的常量定义
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_DEF_H_
#define _MTAPI_DEF_H_
/**@addtogroup common 公用
*@{
*/

/**@addtogroup other 其他
*@{
*/

#include "kdvtype.h"

#ifndef CONST
#  define CONST const
#endif

#ifndef IN
#  define IN
#endif

#ifndef OUT
#  define OUT
#endif

#ifndef INOUT
#  define INOUT
#endif

#ifndef OPTIONAL
#  define OPTIONAL
#endif
 
/** app id 定义 */
/** 划分给产品模块使用的范围 */
#define AID_PRODUCT_BGN     (u32)50
#define AID_PRODUCT_END     (u32)100

/** 组件模块app id定义 */
#define KMTAPI_AID_MTSYSCTRL	   (u32)102
#define KMTAPI_AID_MTMP            (u32)105    ///<mtmp模块
#define KMTAPI_AID_MTDISPATCH      (u32)106    ///<消息调度模块
#define KMTAPI_AID_MTACCESS        (u32)107    ///<终端客户端接入模块
#define KMTAPI_AID_AGENT           (u32)108    ///<网管agent
#define KMTAPI_AID_GUARD           (u32)109    ///<网管guard
#define KMTAPI_AID_MTAPI           (u32)110    ///<MTAPI
#define KMTAPI_AID_MTPA            (u32)111    ///<mtpa模块
#define KMTAPI_AID_SIPMODULE       (u32)112    ///<协议层sipmoule,终端指定
#define KMTAPI_AID_SIPSTACKIN      (u32)113    ///<协议层sipstackout， 终端指定
#define KMTAPI_AID_SIPSTACKOUT     (u32)114    ///<协议层sipstackin, 终端指定
#define KMTAPI_AID_MTMC            (u32)115    ///<内置mc模块
#define KMTAPI_AID_MISC            (u32)116    ///<小业务模块
#define KMTAPI_AID_MTH323SERVICE   (u32)117    ///<mth323Service
#define KMTAPI_AID_MTH323STACKOUT  (u32)118    ///<mth323stakcout
#define KMTAPI_AID_MTH323STACKIN   (u32)119    ///<mth323stackin
#define KMTAPI_AID_MTVOD           (u32)120    ///<点播模块
#define KMTAPI_AID_REST			   (u32)121    ///<rest模块
#define KMTAPI_DONT_USE_ME 		   (u32)122    ///<不要使用122，她已经被OSP库内部使用了
#define KMTAPI_AID_IM			   (u32)123    ///<IM模块
#define KMTAPI_AID_AGENTADP        (u32)124    ///<网管适配库
#define KMTAPI_AID_UPGRADE         (u32)125    ///<升级子系统
#define KMTAPI_AID_CFGSRV	       (u32)126    ///<配置服务
#define KMTAPI_AID_MTMCSERVICE	   (u32)127    ///<内置mc模块
#define KMTAPI_AID_MTRECORD	       (u32)128    ///<本地地址簿&呼叫记录
#define KMTAPI_AID_SATSERVICE	   (u32)129    ///<sat service app
#define KMTAPI_AID_SATSTACK	       (u32)130    ///<sat stack app
#define KMTAPI_AID_MTSECURE	       (u32)137    ///<secure模块
#define KMTAPI_AID_MTDCS           (u32)138    ///<mtdcs模块


//////////////////////////////////////////////////////////////////////////
/** BUF长度定义 */     
//////////////////////////////////////////////////////////////////////////
#define    KMTAPI_BUF_16_LEN					  (u16)16
#define    KMTAPI_BUF_32_LEN					  (u16)32
#define    KMTAPI_BUF_64_LEN					  (u16)64
#define    KMTAPI_BUF_128_LEN				      (u16)128
#define    KMTAPI_BUF_256_LEN				      (u16)256
#define    KMTAPI_BUF_512_LEN					  (u16)512
#define    KMTAPI_BUF_1024_LEN				      (u16)1024
#define    KMTAPI_SSID_MAX_LEN					  (u16)96

//////////////////////////////////////////////////////////////////////////
/** 常用个数定义 */
//////////////////////////////////////////////////////////////////////////
#define    KMTAPI_COUNT_4					  (u16)4
#define    KMTAPI_COUNT_8					  (u16)8
#define    KMTAPI_COUNT_16					  (u16)16
#define    KMTAPI_COUNT_32					  (u16)32
#define    KMTAPI_COUNT_64					  (u16)64
#define    KMTAPI_COUNT_128				      (u16)128
#define    KMTAPI_COUNT_192				      (u16)192
#define    KMTAPI_COUNT_256				      (u16)256
#define    KMTAPI_COUNT_512					  (u16)512
#define    KMTAPI_COUNT_1024				  (u16)1024

#define    KMTAPI_COUNT_100				      (u16)100
#define    KMTAPI_KEEP_CALLING_NUM			  (u16)2 
#define    KMTAPI_MAX_NUM_5                     (u16)5
//////////////////////////////////////////////////////////////////////////

/** 不可用的SESSIONID */
#define  KMTAPI_INVALID_SESSIONID                (SessionID)0


/** mtapi最多终端控制实例数量 */
#define  KMTAPI_MAX_INS_CNT                      (u16)128   

/** mtapi最多控制MT 的session数量 */
#define  KMTAPI_MAX_SESSION_CNT                  (KMTAPI_MAX_INS_CNT)


/** mtapi发给dispatch额消息最大长度3  */ 
#define  KMTAPI_MAX_MSGBUF_LEN                   ((32*1024))  //Byte

/** 终端MTDispatch监听端口 */
#define  KMTAPI_MT_LISTEN_PORT                    (u16)60001

/** 默认的会议呼叫码率 */
#define  KMTAPI_DEF_CONF_CALLRATE                 (u16)512


/** 最大的端对申请数 */
#define  KMTAPI_MAX_APPLY_PORT_NUM                 (u16)10

/** 终端登录用户名称长度 */
#define  KMTAPI_MAX_USERNAME_LEN                   (u16)48

/** 终端登录用户密码长度 */
#define  KMTAPI_MAX_USERPWD_LEN                    (u16)64

/** 终端登录用户名全名称长度 */
#define  KMTAPI_MAX_FULL_USERNAME_LEN              (u16)64

/** 终端登录用户描述信息长度 */
#define  KMTAPI_MAX_USER_DESCRIPTION_LEN           (u16)64

/** 最多用户列表信息 */
#define  KMTAPI_MAX_MUTLIUSERINFO_NUM              (u16)32  

/** 定义用户身份 */
#define KMTAPI_UM_ADMIN		                       (u16)0x01
#define KMTAPI_UM_OPERATOR		                   (u16)0x02


/** 设备名称长度 */
#define  KMTAPI_MAX_MT_ALIAS_LEN                   (u16)128

/** 设备E164长度 */
#define  KMTAPI_MAX_MT_E164_LEN                    (u16)32

/** 设备字符串IP长度 */
#define  KMTAPI_MAX_MT_IP_LEN                      (u16)32

/** 设备GUID长度 */
#define  KMTAPI_MAX_DEVICE_GUID_LEN                (u16)256

/** 设备密码长度 */
#define  KMTAPI_MAX_MT_PWD_LEN                     (u16)64

/** 最多设备列表个数 */
#define  KMTAPI_MAX_DEVICE_LIST_NUM                (u16)64

/** 最多快照列表个数 */
#define  KMTAPI_MAX_SNAPSHOT_LIST_NUM                (u16)128

/** 终端的ProductID长度 */
#define  KMTAPI_MAX_PRODUCT_ID_LEN                 (u16)64

/** 终端的Version ID长度 */
#define  KMTAPI_MAX_VERSION_ID_LEN                 (u16)64

/** 终端别名最大个数 */
#define  KMTAPI_MAX_MT_ALIAS_NUM                   (u16)10

/** 最大会议列表数量 */
#define  KMTAPI_MAX_CONFLIST_NUM                   (u16)500

/** 最大会议终端成员数量 */
#define  KMTAPI_MAX_CONF_MT_MEMBER_NUM             (u16)256

/** 最大会议Vip列表数量 */
#define  KMTAPI_MAX_CONF_MT_VIPLIST_NUM            (u16)30

/** 最大会议辅流路数 */
#define  KMTAPI_MAX_CONF_ASSVID_CHANNEL_NUM        (u16)3

/** 最大会议主流视频路数 */
#define  KMTAPI_MAX_CONF_VID_CHANNEL_NUM           (u16)3

/** 最大会议辅音频路数 */
#define  KMTAPI_MAX_CONF_ASSAUD_CHANNEL_NUM        (u16)3

/** 最大会议主音频路数 */
#define  KMTAPI_MAX_CONF_AUD_CHANNEL_NUM           (u16)3


/** 视频输入接口 */
#define  KMTAPI_MAX_VIDEO_PORT					   (u16)20

/** 最大视频接口能力列表 */
#define  KMTAPI_MAX_VIDEO_CAP_LIST		           (u16)5
/** 最大通道数 */
#define  KMTAPI_MAX_MULTI_CHANNEL_NUM              (u16)20

/** 最大域名长度 */
#define  KMTAPI_MAX_DOMAIN_NAME_LEN                (u16)128

/** 最大MOID长度 */
#define  KMTAPI_MAX_DOMAIN_MOID_LEN                (u16)64

/** 会议ID长度  */
#define  KMTAPI_MAX_CONF_ID_LEN 			       (u16)32   

/** 会议名称长度 */
#define  KMTAPI_MAX_CONF_NAME_LEN                  (u16)128

/** 会议E164长度 */
#define  KMTAPI_MAX_CONF_E164_LEN                  (u16)32                     
 
/** 会议Email长度 */
#define  KMTAPI_MAX_EMAIL_LEN					   (u16)50

/** 密码最大长度 */
#define  KMTAPI_MAXLEN_PASSWORD                    (u16)32		  

/** 最大轮询终端数*/
#define  KMTAPI_MAX_POLL_NUM		               (u16)192    		

/* 主席最多轮询方案数*/
#define  KMTAPI_MAX_POLL_SCHEME                    (u16)5

/** 画面合成成员数量 */
#define  KMTAPI_MAX_VMP_MEMBER_NUM                 (u16)25

/** 最大混音成员数量 */
#define  KMTAPI_MAX_MIX_MEMBER_NUM                 (u16)192


/** 最大摄像头数量 */
#define  KMTAPI_MAX_CAMERA_NUM                     (u16)10

/** 短消息发送目的成员最大值 */
#define  KMTAPI_MAX_SMSDST_NUM                     (u16)256

/** 短消息内容最大长度*/
#define  KMTAPI_MAX_SMSTEXT_LEN                    (u16)4096       

/** 最大加密密码内容长度 */
#define  KMTAPI_MAX_ENCRYPTKEY_LEN                 (u16)64 

/** 直播列表最大数 */
#define  KMTAPI_MAX_DIRECTBROADCAST_CNT            (u16)50 

/** vrs服务器文件夹最大数 */
#define  KMTAPI_MAX_VODFILE_CNT                    (u16)50 

/** vrs服务器节目最大数 */
#define  KMTAPI_MAX_VODPRG_CNT                     (u16)10 

/** vrs服务器某一节目中详细信息最大数 */
#define  KMTAPI_MAX_VODDETAIL_CNT				   (u16)20

/** 单VOD最多码流通道  */
#define  KMTAPI_MAX_VOD_STREAM_CHANNEL_NUM         (u16)5 

/** VOD最多数码流路数  */
#define  KMTAPI_MAX_VOD_STREAM_NUM                 (u16)10 


/** 代理防火墙域名的最大长度 */
#define  KMTAPI_MAX_PROXYSERVER_NAME_LEN           (u16)255

/** 带路径的文件名长度 */
#define  KMTAPI_MAX_PATH_FILE_NAME_LEN             (u16)256
 
/** 默认的SessionID */
#define  KMTAPI_DEF_SSID                          (u16)1     
 
/** 设备类型名称长度 */
#define  KMTAPI_MAX_DEV_TYPE_NAME_LEN              (u16)64

#define KMTAPI_MAXLEN_SUS_E164LIST             (u32)(16*30)

#define KMTAPI_MAXLEN_SUS_MOIDLIST             (u32)(40*30)

/** 设备OEM标识长度 */
#define  KMTAPI_MAX_DEV_OEM_MARK_LEN               (u16)64

/** 设备软件版本长度 */
#define  KMTAPI_MAX_DEV_SOFT_VER_LEN               (u16)64

/** 设备软件版本发布说明长度 */
#define  KMTAPI_MAX_VER_RELEASE_NOTES_LEN       (u16)(1024*2)

/**电话号码长度*/
#define  KMTAPI_MAX_TELE_INFO_LEN               (u16)(32)

/** 设备备注信息长度 */
#define  KMTAPI_MAX_DEV_DESC_LEN                   (u16)128

/** 设备备注名长度 */
#define  KMTAPI_MAX_DEV_MEMO_LEN                   (u16)128

/** 设备备注信息长度 */
#define  KMTAPI_MAX_UPGRATE_VER_LIST_NUM           (u16)10

/** XAP服务器列表个数 */
#define  KMTAPI_MAX_XAP_LIST_NUM                   (u16)10

/** Eth DNS最多个数 */
#define  KMTAPI_MAX_ETH_DNSLIST_NUM                (u16)2

/** StreamPlayer Channel 名称长度 */
#define  KMTAPI_MAX_CHANNEL_NAME_LEN               (u16)32

/** StreamPlayer Channel 密码长度 */
#define  KMTAPI_MAX_CHANNEL_PWD_LEN                (u16)32

/** SvrStateList最多服务器状态个数*/
#define  KMTAPI_MAX_SVRSTATE_LIST_NUM              (u16)20

/** 终端型号 */
#define  KMTAPI_MAX_MT_TYPE_NAME_LEN               (u16)32

/** 硬件版本 */
#define  KMTAPI_MAX_MT_HARDWARE_VER_LEN            (u16)32

/** 软件版本 */
#define  KMTAPI_MAX_MT_SOFTWARE_VER_LEN            (u16)32

/** 厂商信息 */
#define  KMTAPI_MAX_MT_OEM_NAME_LEN                (u16)64


/** 最多路由条目数量（硬终端） */
#define  KMTAPI_MAX_ROUTEITEM_CNT                  (u16)64
 
#define KMTAPI_FAST_CALL_LIST_CNT (u16)4

/** ftp/telnet最多限定10个ip网段（硬终端） */
#define  KMTAPI_MAX_FTPTELNET_LIMIT_IPITEM_CNT     (u16)10

///<added by ydwu 2014.06.17 begin
///<im相关
#define  KMTAPI_IM_MAX_ID_LEN                      (u16)64
#define  KMTAPI_IM_MAX_ADDRESS_LEN                 (u16)32
#define  KMTAPI_IM_MAX_PATH_LEN                    (u16)1024
#define  KMTAPI_IM_SENDER_PATH_LEN				   (u16)1024
#define  KMTAPI_IM_RECV_PATH_LEN				   (u16)1024
#define  KMTAPI_IM_MAX_HEAD_PORTRAIT_LEN           (u16)4096        
#define  KMTAPI_IM_ENTERPRISE_NAME_LEN             (u16)32
#define  KMTAPI_IM_MAX_MT_TYPE                     (u16)7
#define  KMTAPI_IM_MAX_CHATROOM_ID_LEN             (u16)128
#define  KMTAPI_IM_MAX_ROSTER_ITEMS_PER_BATCH      (u16)20        
#define  KMTAPI_IM_MAX_SID_LEN                     (u16)32
#define  KMTAPI_IM_MAX_PERSISTENT_CHATROOM_NUM     (u16)40
#define  KMTAPI_IM_MAX_MEMBER_STATUS_CACHE_NUM     (u16)20
#define  KMTAPI_IM_MAX_RESOURCE_LEN                (u16)8
#define  KMTAPI_IM_MAX_CHATROOM_SCREEN_NUM         (u16)16
#define  KMTAPI_IM_MAX_BATCH_USERS_NUM             (u16)64

#define  KMTAPI_IM_SOCK5_ADDR_NAME_LEN             (u16)32
#define  KMTAPI_IM_SOCK5_USERNAME_LEN              (u16)32
#define  KMTAPI_IM_SOCK5_PASSWORD_LEN              (u16)32

#define  KMTAPI_IM_MAX_CONFIG_KEY_LEN              (u16)32
#define  KMTAPI_IM_MAX_CONFIG_VALUE_LEN            (u16)2048
#define  KMTAPI_IM_MAX_CONFIG_ITEMS_PER_BATCH      (u16)4

#define  KMTAPI_IM_REST_COMMON_BUF_LEN             (u16)64
#define	 KMTAPI_IM_MAX_GROUPINFO_LIST_LEN	       (u16)20            ///< 用户组信息列表最大长度
#define	 KMTAPI_IM_MAX_QUERY_USERONLINE_NUM        (u16)5             ///< 一次最多查询的员工在线状态数，统一成五个，10个已经发不上来了 20130104  by zhouyanhua
#define	 KMTAPI_IM_MAX_GROUPNAME_LEN			   (u16)64            ///< 用户组的最大长度
#define  KMTAPI_IM_MAX_MULTI_CHAT_NAME_LEN	       (u16)64            ///< 多人聊天的会话名称的最大长度
#define	 KMTAPI_IM_MAX_U64STRING_LEN			   (u16)20            ///< 用户组的最大长度
#define	 KMTAPI_IM_MAX_ONLINESTATE_LIST_NUM   	   (u16)20            ///< 用户状态信息列表最大长度
#define	 KMTAPI_IM_MAX_USER_LIST_NUM			   (u16)20            ///< 用户列表最大长度
#define	 KMTAPI_IM_MAX_SENDMESSAGE_BUF_LEN	       (u32)(1600*2 + 4)  ///< 发送消息给用户的列表最大长度

 
#define	 KMTAPI_MT_MAX_TELEPHONE_LEN               (u16)32            ///< 联系电话的最大长度
#define	 KMTAPI_IM_MAX_WBPARSEKEDADEPT_NUM         (u16)5             ///< 最大部门数
#define	 KMTAPI_IM_MAX_BRIEF_LEN                   (u16)220           ///<  一句话介绍最大长度   
#define	 KMTAPI_IM_MAX_CHATROOM_MEMBER_CACHE_ARRAY_SIZE (u16)40
///<added by ydwu 2014.06.17 end



//by-qwchan-part-mtmeetingctrl begin(注释后面一起添加)
/** MG: MeetingManager 会议日程管理 */
#define KMTAPI_MG_MAX_MEETING_NAME_LEN			  (u16)64

#define	KMTAPI_MG_MAX_REGIONNAME_LEN			  (u16)50

#define KMTAPI_MG_MAX_SHORTROOMS_NUM 			  (u16)50

#define KMTAPI_MG_MAX_BRIEF						  (u16)1000

#define KMTAPI_MG_MAX_SHORTMEETINGS_NUM 		  (u16)50

#define KMTAPI_MG_MAX_ROOMS_NUM 		          (u16)50

#define KMTAPI_MG_MAX_ROOM_NAME_LEN  	          (u16)64

#define KMTAPI_MG_MAX_TEMPLATES_NUM 		      (u16)50
#define KMTAPI_MG_MAX_TEMPLATE_LIST_NUM 		      (u16)4
#define KMTAPI_MG_MAX_MEETING_PERSON_NUM 		  (u16)50

#define KMTAPI_MG_MAX_MEETING_REGION_NUM 		  (u16)50

#define KMTAPI_MG_MAX_ROOMS_LOCK_RESULT_NUM  	  (u16)50

#define KMTAPI_MG_MAX_MEETING_BRIEF_LEN			  (u16)1500

#define KMTAPI_MG_MAX_MEETING_ROOM_NUM		  (u16)1000

#define KMTAPI_MG_MAX_MEETING_SUBJECT_LEN		  (u16)100

#define KMTAPI_MG_MAX_MEETING_DATETIME_LEN		  (u16)32
 
#define KMTAPI_MG_MAX_PARTICIPANTNO_LEN			  (u16)20

#define KMTAPI_MG_MAX_MEETING_REGION_NAME_LEN	  (u16)64

#define KMTAPI_MG_MAX_MEETING_COMPANY_NAME_LEN	  (u16)64
 
/** 会议参与人 */
#define KMTAPI_MG_MAX_PARTICIPANT_NUM			  (u16)500

#define KMTAPI_MG_MAX_MODIFY_PARTICIPANT_NUM			  (u16)500
 
#define KMTAPI_MG_MAX_COMMON_BUF_LEN			  (u16)64

/** 例会包含的最大会议数20个 */
#define KMTAPI_MG_MAX_REGULAR_NUM				  (u16)20

#define KMTAPI_MG_MAX_ORGANIZER_LEN				  (u16)30

#define KMTAPI_MG_ORGANIZERMAIL_LEN				  (u16)50

#define KMTAPI_MG_MAX_TEMPLATE_ID_LEN			  (u16)20

#define KMTAPI_MG_MAX_REGIONS_NUM				  (u16)20

#define KMTAPI_MG_MAX_MT_NAME					  (u16)60
#define	KMTAPI_MG_MAX_MT_PHONE					  (u16)30
#define KMTAPI_MG_MAX_MT_REMARK					  (u16)100


#define KMTAPI_GM_NOTIFY_SIZE                     (u16)64 
#define KMTAPI_GM_MAX_SUBJECT			          (u16)100
#define KMTAPI_GM_MAX_DATETIME	                  (u16)20
#define KMTAPI_GM_MAX_MOID				          (u16)64
#define KMTAPI_GM_MAX_ORGANIZER		              (u16)30
#define KMTAPI_GM_MAX_ORGANIZERMAIL	              (u16)50
#define	KMTAPI_GM_MAX_PHONE			              (u16)30
#define KMTAPI_GM_MAX_MOBILE		              (u16)20
#define KMTAPI_GM_MAX_REGULAR_MEETING_COUNT (u16)5000

#define KMTAPI_GM_MAX_ROOM_NUM		              (u16)10		
#define KMTAPI_GM_MAX_E164				          (u16)16
#define KMTAPI_GM_MAX_TEMPLATEID		          (u16)20
#define KMTAPI_GM_MAX_TEMPLATENAME		          (u16)64
#define KMTAPI_GM_MAX_COMMON			          (u16)40


/**CM: ContactManager   联系人管理 */
#define KMTAPI_CM_MAX_RECORD_NUM				  (u16)32

#define KMTAPI_CM_MAX_ROSTER_NUM				  (u16)32

#define KMTAPI_CM_MAX_GROUP_NUM					  (u16)32

#define KMTAPI_CM_MAX_TEMPLATE_ID_LEN             (u16)32

#define KMTAPI_CM_MAX_TEMPLATE_NAME_LEN           (u16)64

/** 地址薄组名称长度 */
#define KMTAPI_CM_MAX_GROUP_NAME_LEN              (u16)64

//by-lw-part-mtsysctrl begin
#define KMTAPI_SYS_MAX_VER_LEN                    (u16)64
#define KMTAPI_SYS_MAX_SYSNAME_LEN                (u16)64
#define KMTAPI_SYS_MAX_STARTFUN_NAME_LEN          (u16)64
#define KMTAPI_SYS_MAX_STOPFUN_NAME_LEN           (u16)64
#define KMTAPI_SYS_MAX_MTSERVICE_NUM              (u16)64
//by-lw-part-mtsysctrl end

#define KMTAPI_MAX_PORT_NUM                        (u16)30   
#define KMTAPI_MAX_SERVER_NUM                      (u16)20 ///<终端注册服务器最大的数量
#define KMTAPI_MAX_CHAN_NUM                        (u16)10
#define KMTAPI_MAX_PRE_SERVER_NUM                  (u16)3  ///<登录策略最大前置服务器数量
#define KMTAPI_MAX_ENCODE_NUM                      (u16)5  ///<最大编码器个数
#define KMTAPI_MAX_DECODE_NUM                      (u16)5  ///<最大解码器数量
#define KMTAPI_MAX_APP_NUM                         (u16)45 ///<启动的最多子系统个数
#define KMTAPI_MAX_CODEC_NUM                       (u16)5  ///<编解码器最大个数

#define KMTAPI_MAX_USER_NUM                        (u16)5  ///<最大用户数量
#define KMTAPI_MAX_ADDRESS_NUM                     (u16)20 ///<每次上传最大地址簿个数

#define	KMTAPI_MAX_DEPARTMENT_COUNT		           (u16)200 ///< 一次分包200个部门信息给上层
#define	KMTAPI_MAX_USER_DETAIL_INFO		           (u16)6  ///< 每次最多POST给界面的详细信息个数
#define KMTAPI_MAX_EMPLOYEE_COUNT		           (u16)100 ///< 一次分包100个员工信息给上层

#define KMTAPI_MAX_MONITOR_GROUP_COUNT	           (u16)20 ///<监控设备组最大传20个
#define KMTAPI_MAX_MONITOR_DEVICE_COUNT            (u16)10 ///<设备信息最大传10个
#define KMTAPI_MAX_COMMON                          (u16)40 
#define KMTAPI_MAX_REMARK                          (u16)100 

#define KMTAPI_MAX_CAMERA_PRESET_NUM			   (u16)128 ///<摄像头最多预置位个数

#define KMTAPI_MAX_CAMERA_TYPE_NUM                  (u16)64  ///< 最大支持的摄像头类型个数

#define KMTAPI_MAX_AUDIO_IN_NUM                     (u16)16 ///<最大音频输入接口数
#define KMTAPI_MAX_AUDIO_OUT_NUM                    (u16)8  ///<最大音频输出接口数
#define KMTAPI_MAX_VIDSRC_NUM                       (u16)3  ///<最大视频源个数

#define KMTAPI_MAX_NET_DEST_NUM                     (u8)5   ///<最多远端网络地址
 
#define KMTAPI_MAX_VIDEO_SRC_NUM                    (u8)16  ///<最大的视频源标签个数
#define KMTAPI_MAX_VIDEO_OUT_NUM                    (u8)16  ///<最大的视频输出标签个数
#define KMTAPI_MAX_SERIAL_NUM                       (u8)16  ///<最大串口数目
#define KMTAPI_MAX_FPGA_NUM                         (u8)16  ///<最大FPGA个数

#define  KMTAPI_REST_ACCOUNT_INFO_BIT_INDEX_MOBILE   0x01
#define  KMTAPI_REST_ACCOUNT_INFO_BIT_INDEX_EXT      0x02
#define  KMTAPI_REST_ACCOUNT_INFO_BIT_INDEX_SEAT     0x04
#define  KMTAPI_REST_ACCOUNT_INFO_BIT_INDEX_POSITION 0x08
#define  KMTAPI_REST_ACCOUNT_INFO_BIT_INDEX_BRIEF    0x10
#define  KMTAPI_REST_ACCOUNT_INFO_BIT_INDEX_SEX      0x20
#define  KMTAPI_REST_ACCOUNT_INFO_BIT_INDEX_NAME     0x40

#define KMTAPI_E1_USRNAME_LEN         20    ///<E1用户名称的最大长度
#define KMTAPI_E1_USRPSW_LEN            6   ///<E1用户密码的最大长度
#define KMTAPI_E1_MAX_UNIT_NUM       4      ///<E1分组内最大的单元个数
#define KMTAPI_E1_MAX_GROUP_NUM   4         ///<最大的E1分组个数

#define  KMTAPI_ROUTELIST_MAX_NUM   16       ///<最大的路由个数
#define  KMTAPI_VIDSRC_MAX_NUM	20    //最大视频源个数

#define  KMTAPI_BANNER_INFO_LIST_MAX_NUM	4    //最大横幅个数

#define  KMTAPI_USB_PARTITION_MAX_NUM 16 //USB最大分区数
#define  KMTAPI_USB_INTERFACE_MAX_NUM 4 //USB接口最大个数

////sec
#define  KMTAPI_SEC_CAID_LEN     20 //商密caid的长度
#define  KMTAPI_SEC_CAID_MAX_NUM 64 //商密caid的个数

///电子白板
#define	 KMTAPI_DCS_PIC_MAX			200
#define  KMTAPI_DCS_POINT_MAX                        3000
#define  KMTAPI_DCS_INVALID_MSG_SEQUENCE 0xFFFFFFFF

#define	 KMTAPI_DCS_MATRIXVALUE		9

//ai展示最大的列表数目
#define  KMTAPI_MAX_AISHOW_LIST_NUM              (u16)6
/**@}*/

/**@}*/
#endif //_MTAPI_DEF_H_