/*******************************************************************************//**
*@file          mtapi_struct.h
*@brief         提供mtapi对外的结构体定义
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_STRUCT_H_
#define _MTAPI_STRUCT_H_
/**@addtogroup common 公用
*@{
*/

/**@addtogroup struct 结构定义
*@{
*/

#include <string.h> //linux中包含memset
#include "mtapi_enum.h"
#include "mtapi_def.h"


/** 带宽信息 */
typedef struct tagTMTNetBandWidth_Api 
{
	u32 dwBandWidth;		           ///< 带宽, 单位KB/s
	u32 dwDropRate;		               ///< 该带宽对应的丢包率, 单位千分之几 
public:
	tagTMTNetBandWidth_Api(){ memset( this, 0, sizeof( struct tagTMTNetBandWidth_Api ) ); }
}*PTMTNetBandWidth_Api, TMTNetBandWidth_Api;


/** 带宽状态*/
typedef struct tagTMTNetStatus_Api
{
	BOOL32 bTimeout;					    ///< 此次带宽检测是否超时
	TMTNetBandWidth_Api tSendBandwidth;	    ///< 发送带宽(上行), 单位KB/s
	TMTNetBandWidth_Api tRecvBandWidth;	    ///< 接收带宽(下行), 单位KB/s 
public:
	tagTMTNetStatus_Api(){memset( this, 0, sizeof( struct tagTMTNetStatus_Api ) ); }
}*PTMTNetStatus_Api, TMTNetStatus_Api;

/** 用户信息 */
typedef struct tagTUserFullInfo_Api
{
	u32           dwUserID;                                  ///< 用户唯一标示符
	s8            achUsrName[KMTAPI_MAX_USERNAME_LEN+1];     ///< 用户名
	s8            achUsrPwd[KMTAPI_MAX_USERPWD_LEN+1];       ///< 密码（加密了）sm3传的是64字节的16进制字符串，md5传的是32字节的16进制字符串
	                                                         ///< 16进制字符串统一小写表示
	u32           dwRights;                                  ///< 用户权限（admin用户和普通用户）
	s8            achFullUsrName[KMTAPI_MAX_FULL_USERNAME_LEN+1];///< 完整用户名
	s8            achUsrDesc[KMTAPI_MAX_USER_DESCRIPTION_LEN+1]; ///< 用户描述
public:
	tagTUserFullInfo_Api(){ memset( this, 0, sizeof( struct tagTUserFullInfo_Api ) );}
}*PTUserFullInfo_Api, TUserFullInfo_Api;

/** 多用户信息 */
typedef struct tagTMultiUserFullInfo_Api
{
	TUserFullInfo_Api    arrTUserInfo[KMTAPI_MAX_MUTLIUSERINFO_NUM];     ///< 用户信息
	u16                  byCnt;                                          ///< 实际数量
public:
	tagTMultiUserFullInfo_Api(){ memset( this, 0, sizeof( struct tagTMultiUserFullInfo_Api) ); }
}*PTMultiUserFullInfo_Api, TMultiUserFullInfo_Api;

/** 用户ID */
typedef struct tagTMTUsersId_Api
{
	u8  byCnt;                                                               ///< 实际数量
	u32 adwId[KMTAPI_MAX_MUTLIUSERINFO_NUM]; ///< 用户ID
public:
	tagTMTUsersId_Api() { memset( this, 0, sizeof( struct tagTMTUsersId_Api)); }
}*PTMTUsersId_Api, TMTUsersId_Api;

/** 用户请求结果*/
typedef struct tagTUserReqResult_Api
{
	TUserFullInfo_Api    tUserInfo;                                 ///< 用户信息
	u32                  dwUserReqRst;                              ///< 对应用户请求结果
public:
	tagTUserReqResult_Api(){ memset( this, 0, sizeof( struct tagTUserReqResult_Api ) ); }
}*PTUserReqResult_Api, TUserReqResult_Api;

/** 多用户请求结果 */
typedef struct tagTMultiUserReqResult_Api
{
	TUserReqResult_Api  arrMultUserReqRslt[KMTAPI_MAX_MUTLIUSERINFO_NUM]; ///< 用户请求结果
	u8 byCnt;                                                             ///< 数量
public:
	tagTMultiUserReqResult_Api(){memset( this, 0, sizeof( struct tagTMultiUserReqResult_Api ) ); }
}*PTMultiUserReqResult_Api, TMultiUserReqResult_Api;




/** AEC微调参数信息 */
typedef struct tagTAdjustAecParamCfg_Api
{
	BOOL32           bAuto;                             ///< 是否自动
	u32              dwVal;                             ///< 自动参数微调值
	BOOL32           bEnable;							///<是否开启AEC
	u32              dwManualVal;                       ///< 手动参数微调值

public:
	tagTAdjustAecParamCfg_Api(){ memset( this, 0, sizeof( struct tagTAdjustAecParamCfg_Api) ); }
}*PTAdjustAecParamCfg_Api,TAdjustAecParamCfg_Api;


/** 桌面终端音视频设备列表 */
typedef struct tagTDevInfo_Api
{
	s8              achDevName[KMTAPI_MAX_MT_ALIAS_LEN+1];           ///< 设备名称，可能会重复
	s8              achDevGuid[KMTAPI_MAX_DEVICE_GUID_LEN+1];        ///< 设备GUID，具有唯一性
public:
	tagTDevInfo_Api(){ memset( this, 0, sizeof(tagTDevInfo_Api) ); }
}*PTDevInfo_Api, TDevInfo_Api;

/** 设备列表信息 */
typedef struct tagTDevInfoList_Api
{
	TDevInfo_Api        arrTDevInfo[KMTAPI_MAX_DEVICE_LIST_NUM]; ///< 多个设备列表信息
	u8              byCnt;                                       ///< 实际列表数量
public:
	tagTDevInfoList_Api(){ memset( this, 0, sizeof( struct tagTDevInfoList_Api) ); }
}*PTDevInfoList_Api, TDevInfoList_Api;



/** 视频编解码状态 */
typedef struct tagTMtVideoCodecStatus_Api
{
	BOOL32                  bRuning;           ///< 是否在工作
	EmVidFormat_Api         emFormat;          ///< 视频编码格式
	EmMtResolution_Api   emRes;                ///< 视频编码格式
	u16                     wBitrate;          ///< 视频编码码率(单位:kbps)
	u16                     wAverageBitrate;   ///< 主视频编平均码码率(单位:kbps)
	BOOL32                  IsEncrypt;         ///< 主视频编码是否加密
	EmEncryptArithmetic_Api emArithmetic;	   ///< 主视编码使用的加密算法	

public:
	tagTMtVideoCodecStatus_Api()
	{ 
		memset ( this ,0 ,sizeof( struct tagTMtVideoCodecStatus_Api) );
	}
}*PTMtVideoCodecStatus_Api,TMtVideoCodecStatus_Api ;


/** 终端编号 */
typedef struct tagTMtId_Api
{
	u32         dwMcuId;                ///< mcu 号码
	u32         dwTerId;                ///< 终端 号码
public:
	tagTMtId_Api(){ memset( this ,0 ,sizeof( struct tagTMtId_Api ) );	}

}*PTMtId_Api, TMtId_Api;

/** 终端编号列表 */
typedef struct tagTMtIdList_Api
{
	TMtId_Api  atList[KMTAPI_MAX_CONF_MT_MEMBER_NUM]; ///< 终端编号列表信息
	u32 dwCount;                                                                       ///< 实际个数
public:
	tagTMtIdList_Api(){ memset( this ,0 ,sizeof( struct tagTMtIdList_Api ) );	}

}*PTMtIdList_Api, TMtIdList_Api;


/** 选看终端参数 */
typedef struct tagTViewTerParam_Api
{
	TMtId_Api                  tTer;                             ///< 终端
	EmMtMediaType_Api          emViewType;       ///< 音频/视频/音视频
	BOOL32                     bViewAllChan;              ///< 是否选看这个终端的所有通道
	EmCodecComponentIndex_Api  emChanIdx;  ///< 如果否,具体通道id
public:
	tagTViewTerParam_Api()
	{ 
		memset( this ,0 ,sizeof( struct tagTViewTerParam_Api ) );
		emViewType = emMediaAV_Api;
		bViewAllChan = TRUE;
		emChanIdx = em1st_Api; 
	}

}*PTViewTerParam_Api, TViewTerParam_Api;



/** 创会信息列表 */
typedef struct tagTCallInfoList_Api
{
	s8 aaCallInfoList[KMTAPI_COUNT_128][KMTAPI_MAX_MT_ALIAS_LEN+1]; ///< 列表信息
	u8 byCnt;                                                                                                 ///< 列表个数
public:
	tagTCallInfoList_Api()
	{
		memset( aaCallInfoList, 0, sizeof(aaCallInfoList) );
		byCnt = 0;
	}
}*PTCallInfoList_Api, TCallInfoList_Api;


/** 组合类型(net地址) */
typedef struct tagTNetAddr_Api
{
	EmIpAddrType_Api  emIpType;                          ///< IP地址类型V4/V6
	u32           dwIp;                                               ///< IP地址(网络序)
	s8            achIpV6[KMTAPI_BUF_128_LEN+1];   ///< IPV6信息
	u32           dwPort;                                           ///< 端口
public:
	tagTNetAddr_Api()
	{ 
		memset( this ,0 ,sizeof( struct tagTNetAddr_Api ) );	
		emIpType = emIpV4_Api;
	}
}*PTNetAddr_Api, TNetAddr_Api;


/** 终端别名信息 */
typedef struct tagTMtAlias_Api
{
	EmMtAliasType_Api emAliasType;                               ///< 别名类型
	s8            achAlias[KMTAPI_MAX_MT_ALIAS_LEN+1];  ///< 别名信息
public:
	tagTMtAlias_Api(){ memset( this ,0 ,sizeof( struct tagTMtAlias_Api ) );	}
}*PTMtAlias,TMtAlias_Api;

/** 终端别名列表 */
typedef struct tagTMultMtAlias_Api
{
	TMtAlias_Api      arrAlias[KMTAPI_MAX_MT_ALIAS_NUM];      ///< 对端别名，可以多个alias, e164
	u8                byCnt;                                                               ///< 实际别名个数
public:
	tagTMultMtAlias_Api(){ memset( this ,0 ,sizeof( struct tagTMultMtAlias_Api ) );	}
}*PTMultMtAlias_Api,TMultMtAlias_Api;



/** 终端地址 */
typedef struct tagTMtAddr_Api
{
	EmMtAddrType_Api    emAddrType;			 	                 ///< 地址类型 ip or alias or e164
	TNetAddr_Api		tIP;					                                 ///< 终端IP信息 
	s8			    achAlias[KMTAPI_MAX_MT_ALIAS_LEN+1];    ///< 终端别名
public:
	tagTMtAddr_Api(){memset( this ,0 ,sizeof( struct tagTMtAddr_Api));	}
}*PTMtAddr_Api,TMtAddr_Api;

/** 视频源信息 */
typedef struct tagVideoSourceInfo_Api
{
	u8  byVideoPort;                                           ///< 视频源索引
	s8  achPortName[ KMTAPI_BUF_128_LEN+1];  ///< 名称
public:
	tagVideoSourceInfo_Api() { memset( this, 0, sizeof(tagVideoSourceInfo_Api) ); } 

}TVideoSourceInfo_Api;

/** 视频源列表信息 */
typedef struct tagMultiVideoSourceInfo_Api
{
	TVideoSourceInfo_Api atVidSource[ KMTAPI_COUNT_32 ]; ///< 列表信息
	u8 byCnt;                                                                          ///< 列表个数
public:
	tagMultiVideoSourceInfo_Api() { memset( this, 0, sizeof(tagMultiVideoSourceInfo_Api) ); } 
}TMultiVideoSourceInfo_Api;


typedef struct tagVideoAlias_Api 
{
	EmCodecComponent_Api         emType;                //视频源种类
	EmCodecComponentIndex_Api    emIdx;                 //视频源id
	TMultiVideoSourceInfo_Api    tMultiVideoSource;     //多个视频源    

public:
	tagVideoAlias_Api() { memset( this, 0, sizeof(tagVideoAlias_Api) ); } 

}TVideoAlias_Api;

typedef struct tagMultiVideoAlias_Api
{
	TVideoAlias_Api  atVideoAlias[KMTAPI_MAX_ENCODE_NUM];
	u8 byCnt;

public:
	tagMultiVideoAlias_Api() { memset( this, 0, sizeof(tagMultiVideoAlias_Api) ); } 

}TMultiVideoAlias_Api;





/** 当前视频源信息 */
typedef struct tagTVideoInfo_Api
{
	EmCodecComponentIndex_Api  emChanIdx;    ///< 某一路
	u32      dwVideoSrc;                                         ///< 当前的本地视频源，不是枚举，是数字索引
	BOOL32   bFeccEnable;                                    ///< 是否允许远摇
	BOOL32   bHasVideo;                                      ///< 是否有视频源

public:
	tagTVideoInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTVideoInfo_Api )); }

}*PTVideoInfo_Api, TVideoInfo_Api;

/** 当前视频源信息列表 */
typedef struct tagTMultiVideoInfo_Api
{
	TVideoInfo_Api  atVideoInfo[KMTAPI_COUNT_8];   ///< 列表信息，最多8个通道，仅限主流
	u32 dwCount;                                                        ///< 列表个数

public:
	tagTMultiVideoInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTMultiVideoInfo_Api )); }

}*PTMultiVideoInfo_Api , TMultiVideoInfo_Api;

/** 终端状态，从平台取的数据 */
typedef struct tagTTerStatus_Api
{
	EmMtModel_Api  emMtModel;	              ///< 终端型号
	u8		byEncVol;				                         ///< 当前编码音量(单位:等级)
	u8		byDecVol;				                         ///< 当前解码音量(单位:等级)
	BOOL32	bIsMute;				                 ///< 是否哑音	
	BOOL32	bIsQuiet;				                ///< 是否静音	
	BOOL32	bMatrixStatus;			            ///< 外置矩阵状态		(TRUE ok FALSE err)
	EmMtMediaType_Api  emViewedType; ///< 被选看类型
	TMultiVideoInfo_Api tVideoInfoList;     ///< 视频源列表

public:
	tagTTerStatus_Api(){ memset ( this ,0 ,sizeof( struct tagTTerStatus_Api ));}
}*PTTerStatus_Api, TTerStatus_Api;


/** 终端状态信息结构 */
typedef struct tagTMtEntityStatus_Api
{
	u32              dwMcuId;    ///< mcu ID
	u32              dwTerId;      ///< mt ID
	TTerStatus_Api   tStatus; ///< 会议成员终端状态信息
public:
	tagTMtEntityStatus_Api(){ memset( this ,0 ,sizeof( struct tagTMtEntityStatus_Api ) );	}
}*PTMtEntityStatus_Api, TMtEntityStatus_Api;

/** 终端状态信息列表 */
typedef struct tagTMtEntityStatusList_Api
{
	TMtEntityStatus_Api   atMtEntityStatus[KMTAPI_MAX_CONF_MT_MEMBER_NUM]; ///< 列表信息
	u32 dwCount;                                                                                                        ///< 列表个数
public:
	tagTMtEntityStatusList_Api(){ memset( this ,0 ,sizeof( struct tagTMtEntityStatusList_Api ) );	}
}TMtEntityStatusList_Api;


/** 5.0 非标 ras加会参数 */ 
typedef struct tagTMtJoinConfParam_Api
{
	u16     wCallRate;                                                          ///< 呼叫码率
	s8      achConfE164[KMTAPI_MAX_CONF_E164_LEN+1]; ///< 会议号码
	s8      achConfPwd[KMTAPI_MAXLEN_PASSWORD+1];    ///< 会议密码
	s8      achConfName[KMTAPI_MAX_CONF_NAME_LEN+1]; ///< 会议名称
	BOOL32  bDialJoinConf;                                               ///< 是否电话入会
	s8      achDialNum[KMTAPI_BUF_32_LEN+1];                ///< 如果电话入会，电话号码
	s8      achAiConfName[KMTAPI_MAX_CONF_NAME_LEN+1]; ///ai 会议名中去掉“ ”， “-”， “_”, 数字转成中文
public:
	tagTMtJoinConfParam_Api()
	{
		wCallRate = 0;
		memset( achConfName, 0, sizeof(achConfName) );
		memset(achConfPwd, 0, sizeof(achConfPwd) );
		memset(achConfE164, 0, sizeof(achConfE164) );
		bDialJoinConf = FALSE;                           ///<默认视频入会
		memset(achDialNum, 0, sizeof(achDialNum) );
		memset(achAiConfName, 0, sizeof(achAiConfName) );
	}
}*PTMtJoinConfParam_Api, TMtJoinConfParam_Api;


/** setup创会的参数  老的平台会议名称用gb2312表示，64位，最多能表示32个汉字，
所以sdk层是utf-8表示，sdk层第97后字节之后都被截掉了 暂时不改*/  

typedef struct tagTMtSetupCreatConfParam_Api
{
	EmMtAddrType_Api     emCallAddrType;                                            ///< 指定下呼叫类型， ip/alias/e164， 有可能ip和别名都有
	TNetAddr_Api         tCalledAddr;                                               ///< 被叫地址
	TMultMtAlias_Api     tCalledAlias;                                              ///< 被叫别名
	TMtAddr_Api          atMtList[KMTAPI_MAX_CONF_MT_MEMBER_NUM];                   ///< 邀请终端列表
	u16                  wMtMemberCnt;                                              ///< 邀请终端个数
	u16                      wCallRate;                                              ///< 会议的呼叫速率(kbps)  
	s8                       achConfId[KMTAPI_MAX_CONF_ID_LEN+1];                    ///< 会议ID
	s8                       achConfName[KMTAPI_MAX_CONF_NAME_LEN+1];                ///< 会议名称
	s8                       achConfNumber[KMTAPI_MAX_CONF_E164_LEN+1];              ///< 会议号码
	s8                       achConfPwd[KMTAPI_MAXLEN_PASSWORD+1];                   ///< 会议密码
	BOOL32                   bIsNeedPwd;                                             ///< 是否需要密码
	u32                      dwConfDuration;		                                 //< 会议持续时间		
	BOOL32                   bIsAutoVmp;		  	                                 ///< 是否自动画面合成
	BOOL32                   bIsMix;	  		                                     ///< 是否混音
	EmEncryptArithmetic_Api  emEncType;                                              ///< 加密算法   
	EmVidFormat_Api       emVidFormat;		                                         ///< 会议视频格式(VIDEO_H261等)
	EmMtResolution_Api    emResolution;		                                         ///< 会议视频分辨率(VIDEO_CIF等)
	EmVidFormat_Api       emAssVidFormat;		                                     ///< 辅流格式
	EmMtResolution_Api    emAssVidRes;	                                             ///< 辅流分辨率
	u32	                  dwAssVidFps;		                                                     ///< 辅流帧率 
	EmAudFormat_Api       emAudFormat;		                                         ///< 会议音频格式(AUDIO_MP3等)
	EmAacChnlNum_Api      emChnl_num;                                               ///< 如果是lc,ld，声道数
	EmH264Profile_Api     emVidH264Profile;                                          //H264profile格式  这个格式是主流video的格式
public:	
	tagTMtSetupCreatConfParam_Api(){ memset( this ,0 ,sizeof( struct tagTMtSetupCreatConfParam_Api ) );	}
}*PTMtSetupCreateConfParam_Api, TMtSetupCreateConfParam_Api;

/** 日期时间 */
typedef struct tagTMTTime_Api
{
	u16 wYear;               ///< 年份
	u8  byMonth;           ///< 月份
	u8  byDay;               ///< 日期
	u8  byHour;             ///< 小时
	u8  byMinute;          ///< 分钟
	u8  bySecond;          ///< 秒
	u16 wMicroSecond; ///< 微秒
public:
	tagTMTTime_Api(){ memset( this ,0 ,sizeof( struct tagTMTTime_Api ) );	}
}*PTMTTime_Api, TMTTime_Api;

/** 终端当前呼叫状态,所有呼叫状态的上报都用这个 */
typedef struct tagTMtCallLinkSate_Api
{
	EmMtCallingType_Api   emCallingType;                              ///<呼叫类型
	EmMtCallState_Api     emCallState;                                ///< 呼叫状态
	EmConfProtocol_Api    emConfProtocol;                             ///< 呼叫协议
	BOOL32                bIsCaller;                                  ///< TRUE = 主叫  FALSE=被叫
	EmMtCallDisReason_Api emCallDisReason;                            ///< 呼叫挂断原因
	u32                   dwCallUpRate;                               ///< 终端内部调整后获得的最小的可用上行的码率
	u32                   dwCallDownRate;                             ///< 终端内部调整后获得的最小的可用下行的码率
	u32                   dwCallRate;                                 ///< 主呼： UI设置的呼叫码率, 被呼： 平台或者对端呼叫过来的码率     
	EmMtModel_Api         emPeerModel;                                ///<  对端的型号，如果外厂商，平台，不兼容的老的终端产品，为emModelBegin_Api
	u32                   dwPeerVendor;                               ///< 对端厂商
	s8                    achPeerProductId[KMTAPI_BUF_32_LEN+1];      ///< 对端productid  
	EmEndpointType_Api    emEndpointType;                             ///< 对端类型，mt,或者mcu 
	TNetAddr_Api		  tPeerAddr;   	                              ///< 对端IP地址(网络序)
	TMultMtAlias_Api      tPeerAlias;                                 ///< 对端别名，可以多个alias, e164
	TMTTime_Api           tConfEstablishedTime;                       ///< 会议成功建立的时间， 是个本地时间
	s8                    achPeerVersionId[KMTAPI_BUF_32_LEN+1];      ///< 对端VersionId
	BOOL32                bIsPeerStackAfter5p0;                       ///< 判断对端是否是5.0
	EmSipConnectType_Api  emSipConnect;                               ///< sip连接类型
	BOOL32                bPeerSptSubMtlist;                          ///< 对端是否支持订阅终端列表
public:
	tagTMtCallLinkSate_Api(){ memset( this ,0 ,sizeof( struct tagTMtCallLinkSate_Api ) );	}
}*PTMtCallLinkSate_Api, TMtCallLinkSate_Api;

/** 错过呼叫的呼叫参数 */
typedef struct tagTMtMissCallParam_Api
{
	u32                   dwCallRate;       ///< 呼叫码率
	TNetAddr_Api		  tPeerAddr;   ///< 对端IP地址(网络序)
	TMultMtAlias_Api      tPeerAlias; ///< 对端别名，可以多个alias, e164
public:
	tagTMtMissCallParam_Api(){ memset( this ,0 ,sizeof( struct tagTMtMissCallParam_Api ) );	}
}TMtMissCallParam_Api;

/** 通道信息 */
typedef struct tagTMtLoc_Api
{
	EmMtMediaDirection_Api      emDirect;                                   ///< 通道类型
	EmMtMediaType_Api           emMediatype;                              ///< 媒体类型
	EmCodecComponentIndex_Api   emStream_id;                        ///< 通道id 从0开始  
	s8                          achStream_Alias[KMTAPI_BUF_32_LEN+1] ; ///< 通道别名
public:
	tagTMtLoc_Api(){ memset( this ,0 ,sizeof( struct tagTMtLoc_Api ) );	}
}*PTMtLoc_Api, TMtLoc_Api;


/** 只用在兼容gk，获取联系人列表用到 */
typedef struct tagTMtDetialInfo_Api
{
	s8            achAlias[KMTAPI_MAX_MT_ALIAS_LEN+1]; ///< 别名信息
	s8            achE164[KMTAPI_MAX_MT_ALIAS_LEN+1]; ///< e164信息
public:
	tagTMtDetialInfo_Api(){ memset( this ,0 ,sizeof( struct tagTMtDetialInfo_Api ) );	}
}TMtDetialInfo_Api;

/** 联系人信息列表 */
typedef struct tagTMtDetialInfoList_Api
{
	TMtDetialInfo_Api atDetialMtInfo[KMTAPI_COUNT_512]; ///< 列表信息
	s32 nCount;                                                                     ///< 列表个数
public:
	tagTMtDetialInfoList_Api(){ memset( this ,0 ,sizeof( struct tagTMtDetialInfoList_Api ) );	}
}TMtDetialInfoList_Api;


/** 终端信息结构 */
typedef struct tagTMTEntityInfo_Api
{
	TNetAddr_Api     tMtAddr;            ///< IP地址
	EmMtModel_Api    emModel;            ///< 型号，暂时底层没有实现这个字段 
	TMultMtAlias_Api tMtAlias;	         ///< 别名，可以多个alias, e164
	EmMtType_Api     emMtType;           ///< 与会终端的类型
	BOOL32           bAudOnly;		     ///< 与会终端是否为为只发送音频码流 0-不只发送音频(音频和视频)，1-只发送音频
	u32              dwMcuId;            ///< mcu ID
	u32              dwTerId;            ///< mt ID
	TMtLoc_Api atLoc[KMTAPI_MAX_CONF_VID_CHANNEL_NUM];  ///< 通道情况,用在多流,一路主流不考虑此字段, 暂时终端只报发送通道
	u8 byLocCount;                                                                         ///< 通道个数
public:
	tagTMTEntityInfo_Api(){ memset( this ,0 ,sizeof( struct tagTMTEntityInfo_Api ) );	}
}*PTMTEntityInfo_Api, TMTEntityInfo_Api;

/** 终端信息列表 */
typedef struct tagTMTEntityInfoList_Api
{
	TMTEntityInfo_Api atMtEntitiy[KMTAPI_MAX_CONF_MT_MEMBER_NUM]; ///< 列表信息
	u32               dwCount;                                                                             ///< 列表个数
public:
	tagTMTEntityInfoList_Api(){ memset( this ,0 ,sizeof( struct tagTMTEntityInfoList_Api ) );	}
}TMTEntityInfoList_Api;

/** 用于you are seeing， 每一路主流接收通道对应的视频源 */
typedef struct tagTMTChanVidSrc_Api 
{
	EmCodecComponentIndex_Api  emChanIdx; ///< 编解码器具体哪一路
	TMtId_Api                  tMtid;                          ///< 终端编号
public:
	tagTMTChanVidSrc_Api(){ memset( this ,0 ,sizeof( struct tagTMTChanVidSrc_Api ) );	}
}*PTMTChanVidSrc_Api, TMTChanVidSrc_Api;

/** 用于you are seeing， 每一路主流接收通道对应的视频源列表 */
typedef struct tagTMTChanVidSrcList_Api 
{
	TMTChanVidSrc_Api atList[KMTAPI_MAX_CONF_VID_CHANNEL_NUM]; ///< 列表信息
	u8  byCount;                                                                                         ///< 列表个数
public:
	tagTMTChanVidSrcList_Api(){ memset( this ,0 ,sizeof( struct tagTMTChanVidSrcList_Api ) );	}
}*PTMTChanVidSrcList_Api, TMTChanVidSrcList_Api;


/** NTP和时间设置信息 */
typedef struct tagTMTNTPInfo_Api
{
	BOOL32 bUsedNtp;										                             ///< 是否使用NTP服务器 true:启用 false不启用，
	s8     achDomainName[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< 域名 OR IP  used_ntp为true生效
	u32	   dwInterval;										                                  ///< 刷新间隔 ms 
	u32 dwPort;                                                                                ///< 端口
public:
	tagTMTNTPInfo_Api(){ memset( this, 0, sizeof( struct tagTMTNTPInfo_Api)); }
}*PTMTNTPInfo_Api, TMTNTPInfo_Api;

/** 会议基础信息 */
typedef struct tagTMtNewConfBaseInfo_Api
{
	s8  achConfName[KMTAPI_MAX_MT_ALIAS_LEN+1];               ///< 会议名称
	s8  achConfE164[KMTAPI_MAX_MT_E164_LEN+1];                ///< 会议号码
	s8  achDomainGuid[KMTAPI_MAX_DEVICE_GUID_LEN+1];		  ///< guid
	s8  achDomainName[KMTAPI_MAX_DOMAIN_NAME_LEN+1];          ///< 域名
	s8  achDomainMoId[KMTAPI_MAX_DOMAIN_MOID_LEN+1];          ///< 域的MOID
public:
	tagTMtNewConfBaseInfo_Api(){ memset( this ,0 ,sizeof( struct tagTMtNewConfBaseInfo_Api ) );	}
}*PTMtNewConfBaseInfo_Api, TMtNewConfBaseInfo_Api;

/** 会议详细信息 */
typedef struct tagTMtConfDetailInfo_Api
{
	TMtNewConfBaseInfo_Api  tConfBaseInfo;	                                 ///< 基础信息
	u32   dwConfStyle;					                                     ///< 1-召开中会议，2-空闲会议, 3-预约会议, 4-模板	
	s8    achShortNo[KMTAPI_MAX_MT_E164_LEN+1];                              ///< 短号	
	EmEncryptArithmetic_Api   emEncryptMode;	                             ///< 会议加密模式: 0-不加密, 1-des加密,2-aes加密
	u32   dwBitrate;						                                 ///< 会议码率(单位:Kbps,1K=1024)
	EmMtClarity_Api emConfResultion;                                         ///< 会议模式, 高清，标清，自定义的
	EmMtResolution_Api   emVidResolution;	                                 ///< 分辨率 VIDEO_FORMAT_AUTO, ...
	EmMtOpenMode_Api     emOpenMode;                                         ///< 开放模式
	BOOL32 bIsDiscussConf;					                                 ///< 是否讨论会议: 0-不是讨论会议(演讲会议) 1-讨论会议	
	TMTTime_Api  tStartTime;					                             ///< 开始时间
	u32   dwDuration;						                                 ///< 持续时间(分钟)	
	s8    achMasterMtAlias[KMTAPI_MAX_MT_ALIAS_LEN+1];                       ///< 创会人别名字符串
	EmMtDualMode_Api   emAssStreamMode;		                                 ///< 会议的双流发起方式: 0-发言人 1-任意终端
	BOOL32  bIsSatdcastMode;                                                 ///< 是否卫星会议
	BOOL32  bIsPublicConf;                                                   ///< 是否开放会议室属性
	BOOL32  bPortMode;                                                       ///< 是否是端口会议
	BOOL32  bConfNoDisturb;                                                  ///< 是否免打扰
	BOOL32  bNeedPwd;                                                        ///< 是否密码会议
	u32		dwMeetingScale;													 ///< 会议规模,0：空，1：4方视频会议,2：8方视频会议,3：大型视频会议

public:
	tagTMtConfDetailInfo_Api(){ memset( this ,0 ,sizeof( struct tagTMtConfDetailInfo_Api ) );	}
}*PTMtConfDetailInfo_Api, TMtConfDetailInfo_Api;

/** 对端能力信息 */
typedef struct tagTPeerCapabilityInfo_Api
{
	BOOL32 bMix;                  ///< 混音
	BOOL32 bVAC;                 ///< 语音激励
	BOOL32 bCustomVMP;     ///< 定制画面合成
	BOOL32 bAutoVMP;          ///< 自动画面合成
	BOOL32 bEndConf;            ///< 结束会议
	BOOL32 bInvateMt;            ///< 邀请终端
	BOOL32 bDropMt;              ///< 删除终端
	BOOL32 bSelSpeaker;         ///< 指定/取消发言人
	BOOL32 bSelChair;             ///< 指定/放弃主席
	BOOL32 bSelSource;           ///< 选看终端
	BOOL32 bFECC;                  ///< 远程摄像头遥控
	BOOL32 bQuiet;                  ///< 远端静音
	BOOL32 bMute;                  ///< 远端哑音
	BOOL32 bConfReq;             ///< 会议申请处理
	BOOL32 bOnlineList;           ///< 在线终端列表
	BOOL32 bOfflineList;           ///< 离线终端列表
	BOOL32 bPicSwitch;            ///< 画面切换
	BOOL32 bSelSpeakingUser; ///< 点名 
	BOOL32 bForceBroadcast;   ///< 强制广播
public:
	tagTPeerCapabilityInfo_Api(){memset(this ,0 ,sizeof( struct tagTPeerCapabilityInfo_Api)); }
}*PTPeerCapabilityInfo_Api,TPeerCapabilityInfo_Api;

/** 画面合成参数 */
typedef struct tagTMtVmpItem_Api
{
	u32                         dwVmpItem_Idx;               ///< 在画面合成中的位置, 不要用外面的数组的下标  
	EmMtVMPMmbType_Api          emMmbType;  ///< 如果type是emVMPMmbMCSspec_Api, 平台会关心tMtid字段;如果type不是emVMPMmbMCSspec_Api， 平台不关心tMtid字段
	TMtId_Api                   tMtid;                            ///< 画面合成成员
	EmCodecComponentIndex_Api   emStream_id; ///< 通道id 从0开始, 用在多流中，没有多流可以忽略
public:
	tagTMtVmpItem_Api()
	{ 
		memset ( this ,0 ,sizeof( struct tagTMtVmpItem_Api) );
		emMmbType = emVMPMmbMCSspec_Api; 
	}
}*PTMtVmpItem_Api, TMtVmpItem_Api;

/** 自主画面合成参数 */
typedef struct tagTMtCustomVmpParam_Api
{
	EmMtVmpMode_Api emVmpMode;                                                  ///< vmp方式， 自动还是其他方式
	EmMtVmpStyle_Api emStyle;                                                             ///< 画面合成风格
	TMtVmpItem_Api  atVmpItem[KMTAPI_MAX_VMP_MEMBER_NUM]; ///< 画面合成成员
	u32  dwCount;                                                                                  ///< 合成成员数组个数
public:
	tagTMtCustomVmpParam_Api(){ memset ( this ,0 ,sizeof( struct tagTMtCustomVmpParam_Api) );}
}*PTMtCustomVmpParam_Api,TMtCustomVmpParam_Api ;

/** 会议画面合成参数 */
typedef struct tagTMtVmpParam_Api
{
	EmMtVmpMode_Api emVmpMode; ///< vmp方式， 自动还是其他方式:如果emVmpMode是emMt_VMP_MODE_AUTO_Api,emStyle 也填自动 emMt_VMP_STYLE_DYNAMIC;如果 emVmpMode 是emMt_VMP_MODE_CTRL_Api，emStyle 选择画面合成风格
	EmMtVmpStyle_Api emStyle;            ///< 画面合成风格	     
	BOOL32     bIsBroadcast;                  ///< 是否广播
	BOOL32     bAddMmbAlias;              ///< 合成图像是否叠加合成成员别名
	TMtVmpItem_Api  atVmpItem[KMTAPI_MAX_VMP_MEMBER_NUM]; ///< 画面合成成员
	u32  dwCount;                                                                                  ///< 数组个数
public:
	tagTMtVmpParam_Api()
	{ 
		memset ( this ,0 ,sizeof( struct tagTMtVmpParam_Api) );
		emVmpMode = emMt_VMP_MODE_AUTO_Api;
		emStyle = emMt_VMP_STYLE_DYNAMIC_Api;
	}
}*PTMtVmpParam_Api,TMtVmpParam_Api ;

/** 轮询信息 */
typedef struct tagTMtPollInfo_Api
{
	EmMtMediaType_Api emMode; ///< 轮询模式 emMediaVide /emMediaAV 
	EmAction_Api      emStat;          ///< emStart/  emStop/  emPause 轮询状态
	u16               wKeepTime;          ///< 终端轮询的保留时间 单位:秒(s)
	u8			      byMtNum;		         ///< 参加轮询的终端个数
	TMtId_Api	      arrTMtId[ KMTAPI_MAX_POLL_NUM ]; ///< 参加轮询的终端
	u8                byPollSchemeId;                                    ///< 轮询方案id, 用于mtc同步  
public:
	tagTMtPollInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTMtPollInfo_Api) );}
}*PTMtPollInfo_Api,TMtPollInfo_Api ;

/** 轮询方案 */
typedef struct tagTMTChrmanPollScheme_Api
{
	s8 achName[KMTAPI_BUF_32_LEN+1]; ///< 方案名称
	TMtPollInfo_Api tPollInfo;                    ///< 轮询信息
public:
	tagTMTChrmanPollScheme_Api() { memset( this, 0, sizeof( struct tagTMTChrmanPollScheme_Api ));}
}*PTMTChrmanPollScheme_Api, TMTChrmanPollScheme_Api;

/** 轮询方案列表 */
typedef struct tagTMTChrmanPollSchemeList_Api
{
	TMTChrmanPollScheme_Api atPollInfo[KMTAPI_MAX_POLL_SCHEME]; ///< 列表信息
	u8 byCnt;                                                                                             ///< 列表个数
public:
	tagTMTChrmanPollSchemeList_Api() { memset( this, 0, sizeof( struct tagTMTChrmanPollSchemeList_Api ));}
}*PTMTChrmanPollSchemeList_Api, TMTChrmanPollSchemeList_Api;

/** 混音参数 */ 
typedef struct tagTMtMixParam_Api
{
	EmMtMixType_Api  emDiscussMode;                                                ///< 混音方式
	TMtId_Api        arrTMtMember[KMTAPI_MAX_MIX_MEMBER_NUM]; ///< 混音成员
	u8               byCnt;                                                                            ///< 实际个数
public:
	tagTMtMixParam_Api(){ memset ( this ,0 ,sizeof( struct tagTMtMixParam_Api ) );}
}*PTMtMixParam_Api, TMtMixParam_Api;

/** 定义会议信息 */
typedef struct tagTMtConfInfo_Api
{
	TMTTime_Api        tStartTime;                                                     ///< 开始时间，控制台填0为立即开始
	u16                wDuration;                                                            ///< 持续时间(分钟)，0表示不自动停止
	u16                wBitRate;                                                               ///< 会议码率(单位:Kbps,1K=1024)
	u16                wSecBitRate;                                                          ///< 双速会议的第2码率(单位:Kbps,为0表示是单速会议)
	EmMtResolution_Api emPriVideoResolution;                                ///< 主视频格式
	EmMtResolution_Api emAssVideoResolution;                                ///< 辅视频格式
	u16                dwTalkHoldTime;                                                    ///< 最小发言持续时间(单位:秒)
	s8                 achConfPwd[KMTAPI_MAXLEN_PASSWORD+1];       ///< 会议密码
	s8                 achConfName[KMTAPI_MAX_CONF_NAME_LEN+1]; ///< 会议名
	s8                 achConfE164[KMTAPI_MAX_CONF_E164_LEN+1];      ///< 会议的E164号码	
	TMtId_Api 	       tChairman;	                                                         ///< 主席终端，MCU号为0表示无主席
	TMtId_Api	       tSpeaker;		                                                         ///< 发言终端，MCU号为0表示无发言人
	TMtVmpParam_Api    tVmpParam;                                                ///< 当前视频复合参数，仅视频复合时有效
	TMtMixParam_Api    tMixParam;                                                   ///< 混音参数
	BOOL32             bIsSatdcastMode;                                                ///< 是否支持卫星分散会议：0-不支持，1-支持
	EmMtOpenMode_Api   emOpenMode;                                         ///< 会议开放方式
	BOOL32             bOccupy_Vpu;                                                     ///< 是否占用图像处理（包括画面合成和适配）能力
	EmMtDualMode_Api   emDual_mode;                                           ///< 双流模式
	BOOL32             bAllInitDumb;                                                      ///< 终端入会后是否初始哑音 0-不哑音 1-哑音
	BOOL32             bConfNoDisTurb;                                                ///< 会议是否是 免打扰模式
	BOOL32             bPortMode;                                                        ///< 是否是端口模式会议
	BOOL32             bForceBroadcast;                                                 ///<  是否是强制广播
	EmRecordState_Api  emRecord_mode;                                      ///< 录像模式，0-不录像 1-录像 2-录像暂停
public:
	tagTMtConfInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTMtConfInfo_Api) );}
}*PTMtConfInfo_Api,TMtConfInfo_Api ;



/** 简单confinfo */
typedef struct tagTMtSimpConfInfo_Api
{
	TMtId_Api  tSpeaker;                           ///< 发言人id
	TMtId_Api  tChairman;                         ///< 主席id
	EmMtMixType_Api   emDiscuss_mode ; ///< 混音方式
	EmMtVmpMode_Api   emVmp_mode;  ///< vmp方式， 自动还是其他方式
public:
	tagTMtSimpConfInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTMtSimpConfInfo_Api) );}
}*PTMtSimpConfInfo_Api, TMtSimpConfInfo_Api;


/** 会议基本信息， 接收平台过来的已经创建好的会议信息 */
typedef struct tagTMtConfNameInfo_Api  
{
	s8                 achConfName[KMTAPI_MAX_CONF_NAME_LEN+1]; ///< 会议名
	s8                 achConfE164[KMTAPI_MAX_CONF_E164_LEN+1];      ///< 会议的E164号码
	u32			       dwMtNum;		                                                     ///< 入会终端数
	u32			       dwRemainTime;			                                             ///< 会议剩余时间
	EmMtOpenMode_Api   emOpenMode;						                     ///< 开放方式
	EmMtClarity_Api    emConfClarity;			 		                                 ///< 会议模式
	TMTTime_Api	       tConfStartTime;	  						                     ///< 会议开始时间
	BOOL32             bIsSatdcaseMode;                                                ///< 是否支持卫星分散会议：0-不支持，1-支持
	BOOL32             bIsPublicConf;                                                      ///< 是否为开放会议：0-不是，1-是
	BOOL32             bNeedPwd;                                                           ///<是否为密码会议：0-不是，1-是
public:
	tagTMtConfNameInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTMtConfNameInfo_Api ) );}
}*PTMtConfNameInfo_Api,TMtConfNameInfo_Api;

/** 已创建好的会议信息列表 */
typedef struct tagTMtConfNameInfoList_Api 
{
	TMtConfNameInfo_Api arrConfNameInfo[KMTAPI_MAX_CONFLIST_NUM]; ///< 列表信息
	u32 dwCount;                                                                                             ///< 列表个数
public:
	tagTMtConfNameInfoList_Api(){ memset ( this ,0 ,sizeof( struct tagTMtConfNameInfoList_Api ) );}
}TMtConfNameInfoList_Api;

/** 短消息 */
typedef struct tagTShortMsg_Api
{
	EmSMSType_Api         emType;                                            ///< 消息类型
	TMtId_Api             tSrcMtId;                                                ///< 发送消息的终端
	u8                    byDstNum;                                                  ///< 接收消息的终端个数
	TMtId_Api             arrMtDst[KMTAPI_MAX_SMSDST_NUM]; ///< 接收消息的终端列表
	EmRollMsgSpeed_Api    emSpeed;                                       ///< 速度 (1-5)
	u8                    byRollTimes;                                                ///< 滚动次数
	s8                    achText[KMTAPI_MAX_SMSTEXT_LEN+1];    ///< 消息文本
public:
	tagTShortMsg_Api(){ memset ( this ,0 ,sizeof( struct tagTShortMsg_Api) );}
}*PTShortMsg_Api,TShortMsg_Api;

/** RTPRTCP对信息*/ 
typedef struct tagTRtpRtcpPair_Api
{
	TNetAddr_Api tRtpAddr;   ///< RTP地址
	TNetAddr_Api tRtcpAddr; ///< RTCP地址
public:
	tagTRtpRtcpPair_Api(){ memset ( this ,0 ,sizeof( struct tagTRtpRtcpPair_Api) );}
}*PTRtpRtcpPair_Api, TRtpRtcpPair_Api;

/** 密钥 */
typedef struct tagTEncryptKey_Api
{
	u8 byLen;                                                           ///< 密钥长度
	u8 abyKey[KMTAPI_MAX_ENCRYPTKEY_LEN+1]; ///< 密钥
public:
	tagTEncryptKey_Api(){ memset( this ,0 ,sizeof( struct  tagTEncryptKey_Api ) );}	
}*PTEncryptKey_Api,TEncryptKey_Api;

/** 动态载荷 */
typedef struct tagTMTDynamicPayload_Api
{
	u32 dwKeyRmtActivePT; //远端码流的载荷值
	u32 dwKeyRealPT;      //本地实际载荷值
public:
	tagTMTDynamicPayload_Api() { memset ( this ,0 ,sizeof( struct tagTMTDynamicPayload_Api ) ); }
}*PTDynamicPayload_Api, TDynamicPayload_Api;

/** 码流图像参数 */
typedef struct tagTMTStreamParam_Api
{
	EmCodecComponent_Api emCodecType;       ///< 类型标识
	EmCodecComponentIndex_Api emCodecIdx; ///< id
	u8                byMediaType;                            ///< 媒体类型
	u8                byPlayLoad;                               ///< 动态载荷
	TEncryptKey_Api   tEncryptKey;                      ///< 密钥
	BOOL32            bIsg7221Reverse;                  ///< g7221是否翻转
	EmAacChnlNum_Api  emAacChanNum;        ///< aac声道数  
	EmAacSampFreq_Api emAacSampFreq;        ///< aac采样率
	u8                  byPayloadCnt;                //媒体个数
	TDynamicPayload_Api atPayload[KMTAPI_COUNT_8];	 //媒体类型
	u32					dwLocRtpPort;
	u32					dwLocRtcpPort;
public:
	tagTMTStreamParam_Api(){ memset ( this ,0 ,sizeof( struct tagTMTStreamParam_Api ) );}
}*PTMTStreamParam_Api,TMTStreamParam_Api;

/** 视频源信息(仅Embed) */
typedef struct tagTMTVidSrcItem_Api
{
	EmCodecComponentIndex_Api    emCodecIdx; ///< 编码器标识
	EmVidPort_Api                emVidPort;                 ///< 视频源端口
	BOOL32                       bSignal;                         ///< 是否有信号
public:
	tagTMTVidSrcItem_Api(){ memset ( this ,0 ,sizeof( struct tagTMTVidSrcItem_Api ) );}
}*PTMTVidSrcItem_Api,TMTVidSrcItem_Api;


/** 码流信息 */
typedef struct tagTStreamInfo_Api
{
	u32 dwStreamId;                                                ///< 码流标识
	EmMtChanType_Api emStreamType;                  ///< 码流类型
	EmCodecComponentIndex_Api emBitStreamIdx; ///< 对应终端第几路码流
	u32 dwBandWidth;                                             ///< kilobits-per-second,
	s32 nSpeedScale;                                                ///< 速率 比例，一倍速率、两倍速率
	u32 dwStartTime;                                               ///< 开始时间，单位ms
	u32 dwEndTime;                                                ///< 结束时间，单位ms
	u32 dwCurTime;                                                ///< 当前时间，单位ms
	u32 dwMediaType;                                            ///< 媒体类型（如：MEDIA_TYPE_H264、MEDIA_TYPE_G7221等）
	u32 dwVideoWidth;                                           ///< 视频宽（只有视频使用）
	u32 dwVideoHeight;                                          ///< 视频长（只有视频使用）
	u32 dwVideoFps;                                               ///< 帧率（只有视频使用）
	EmRtspStatus_Api emStatus;                              ///< 状态
	BOOL32 bIsLiveBroadcast;                                  ///< 是否为直播
public:
	tagTStreamInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTStreamInfo_Api ) );}
}*PTStreamInfo_Api, TStreamInfo_Api;

/** vod服务器登录信息 */
typedef struct tagTVodLoginInfo_Api
{
	u32 dwIp;                                                   ///< IP地址(大端)
	s8 achUserName[KMTAPI_BUF_64_LEN+1]; ///< 用户名
	s8 achPassword[KMTAPI_BUF_64_LEN+1];   ///< 密码
public:
	tagTVodLoginInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTVodLoginInfo_Api ) );}
}*PTVodLoginInfo_Api, TVodLoginInfo_Api;

/** 文件夹信息 */ 
typedef struct tagTVodFolderInfo_Api
{
	u32 dwFolderId;				                              ///< 文件夹ID
	s8 achFolderName[KMTAPI_BUF_128_LEN+1]; ///< 文件夹名称
	u32	dwPrgCount;				                          ///< 文件数量
public:
	tagTVodFolderInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTVodFolderInfo_Api ) );}
}*PTVodFolderInfo_Api, TVodFolderInfo_Api;

/** 文件夹信息列表 */ 
typedef struct tagTVodFoldersInfo_Api
{
	TVodFolderInfo_Api atFolderInfo[KMTAPI_MAX_VODFILE_CNT]; ///< 列表信息
	u32 dwCnt;                                                                                ///< 列表个数
public:
	tagTVodFoldersInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTVodFoldersInfo_Api ) );}
}*PTVodFoldersInfo_Api,TVodFoldersInfo_Api;

/** vrs某一文件夹下的节目列表请求信息 */ 
typedef struct tagTVodGetPrgsReq_Api
{
	u32	dwFolderId;		                       ///< 文件夹ID
	u32	dwPrgsPage;		                       ///< 每个页面显示几个节目
	u32	dwPageId;			                   ///< 请求的是哪一页
	s8  achIncludeName[KMTAPI_BUF_128_LEN+1];  ///< 搜索文件名
	u32 dwPrgTypeMask;                         ///< 过滤某种格式的文件,0 所有,1是asf,2是MP4
	u32 dwStartTime;                           ///< 起始时间  时间戳
	u32 dwEndTime;                             ///< 终止时间  时间戳
public:
	tagTVodGetPrgsReq_Api(){ memset ( this ,0 ,sizeof( struct tagTVodGetPrgsReq_Api ) );}
}*PTVodGetPrgsReq_Api, TVodGetPrgsReq_Api;

/** vrs某一文件夹下查询录像文件信息 */   //该结构体重复,目前不用
typedef struct tagTVodSearchFilesReq_Api
{
	u32	dwFolderId;		                       ///< 文件夹ID
	u32	dwPrgsPage;		                       ///< 每个页面显示几个节目
	u32	dwPageId;			                   ///< 请求的是哪一页
	s8  achIncludeName[KMTAPI_BUF_128_LEN+1];  ///< 搜索文件名
public:
	tagTVodSearchFilesReq_Api(){ memset ( this ,0 ,sizeof( struct tagTVodSearchFilesReq_Api ) );}
}*PTVodSearchFilesReq_Api, TVodSearchFilesReq_Api;

/** 节目详细信息 */ 
typedef struct tagTVodPrgDetailInfo_Api
{
	u32 dwIp;				                                     ///< IP
	u32	dwPrgDuration;	                             ///< 节目时长（秒）
	u32	dwPrgIndex;		                                 ///< 节目索引
	u32	dwPrgId;			                                 ///< 节目ID
	s8 achPrgName[KMTAPI_BUF_128_LEN+1]; ///< 节目文件名
	u32	dwPrgSize;		                                  ///< 节目大小（BYTE）
	s8	achPrgType[KMTAPI_BUF_128_LEN+1];   ///< 节目文件后缀
	s8	achPath[KMTAPI_BUF_128_LEN+1];  	      ///< 存放的相对路径
	u32 dwPrgsInfoIndex;                                 ///< 所属基本节目信息在列表中的索引
public:
	tagTVodPrgDetailInfo_Api() { memset( this, 0, sizeof( struct tagTVodPrgDetailInfo_Api ) ); }
}*PTVodPrgDetailInfo_Api, TVodPrgDetailInfo_Api;

/** 节目详细信息列表 */
typedef struct tagTVodPrgsDetailInfo_Api
{
	TVodPrgDetailInfo_Api atPrgDetail[KMTAPI_MAX_VODDETAIL_CNT]; ///< 节目具体信息列表
	u32 dwCnt;                                                                                       ///< 节目具体信息个数
public:
	tagTVodPrgsDetailInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTVodPrgsDetailInfo_Api ) );}
}*PTVodPrgsDetailInfo_Api, TVodPrgsDetailInfo_Api;

/** 节目基本信息 */
typedef struct tagTVodPrgBaseInfo_Api
{
	u32 dwCreateTime;		                           ///< 节目创建时间
	u32 dwIssueTime;		                               ///< 节目发布时间
	s8	achPrgAlias[KMTAPI_BUF_128_LEN+1]; ///< 节目显示名称
	u32	dwPrgAllDuration;	                            ///< 节目总时长（秒）
	u32	dwPrgAllSize;		                            ///< 节目总大小
	s8	achPrgDesc[KMTAPI_BUF_512_LEN+1]; ///< 节目描述
	u32	dwPrgId;                        			        ///< 节目ID
	u32	dwPrgState;                         		        ///< 节目状态
	s8  achStreamJsonPath[KMTAPI_BUF_128_LEN+1];             //< 节目源描述文件
public:
	tagTVodPrgBaseInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTVodPrgBaseInfo_Api ) );}
}*PTVodPrgBaseInfo_Api, TVodPrgBaseInfo_Api;

/** 节目基本信息列表 */
typedef struct tagTVodPrgsBaseInfo_Api
{
	TVodPrgBaseInfo_Api atPrgBase[KMTAPI_MAX_VODPRG_CNT]; ///< 列表信息
	u32 dwCnt;                                                                               ///< 列表个数
public:
	tagTVodPrgsBaseInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTVodPrgsBaseInfo_Api ) );}
}*PTVodPrgsBaseInfo_Api, TVodPrgsBaseInfo_Api;

/** 直播室信息 */ 
typedef struct tagTVodRoomState_Api
{
	u32	dwElapse;			                                      ///< 节目已播放的时间
	s8 achLCastPoint[KMTAPI_BUF_128_LEN+1];   ///< 直播地址
	u32	dwPrgId;			                                      ///< 节目ID
	u32	dwRoomId;			                                  ///< 直播室ID
	s8	achRoomName[KMTAPI_BUF_128_LEN+1]; ///< 直播室名称
	u32	dwUsrGrpId;		                                      ///< 直播室所属用户组
	u32 dwLiveTime;                             // 开始播放时间
	s8  achLiveStreamPath[KMTAPI_BUF_128_LEN+1];             // 直播源描述文件
	s8  achRoomIdStr[KMTAPI_BUF_128_LEN+1];   ///< 直播室ID,以后用字符串标识
public:
	tagTVodRoomState_Api(){ memset ( this ,0 ,sizeof( struct tagTVodRoomState_Api ) );}
}*PTVodRoomState_Api, TVodRoomState_Api;

/** 直播列表信息 */ 
typedef struct tagTVodRoomsState_Api
{
	TVodRoomState_Api atRoomstate[KMTAPI_MAX_DIRECTBROADCAST_CNT]; ///< 列表信息
	u32 dwCnt;                                                                                                   ///< 列表个数
public:
	tagTVodRoomsState_Api(){ memset ( this ,0 ,sizeof( struct tagTVodRoomsState_Api ) );}
}*PTVodRoomsState_Api, TVodRoomsState_Api;

/** 预约直播室信息 */ 
typedef struct tagTVodRoomCfg_Api
{
	u32	dwIp;				                                  ///< 服务器IP(大端)
	s8 achPath[KMTAPI_BUF_128_LEN+1];		  ///< 文件路径
	s8 achPrgAlias[KMTAPI_BUF_128_LEN+1];   ///< 节目显示名称
	u32 dwPrgId;			                                  ///< 节目ID
	s8 achPrgName[KMTAPI_BUF_128_LEN+1]; ///< 节目名称
	u32 dwResTime;		                                  ///< 预约播放时间
	u32	dwRoomId;			                              ///< 预约直播室的ID
	u32 dwUsrGrpId;		                                  ///< 预约直播室所属用户组ID
public:
	tagTVodRoomCfg_Api(){ memset ( this ,0 ,sizeof( struct tagTVodRoomCfg_Api ) );}
}*PTVodRoomCfg_Api, TVodRoomCfg_Api;

/** 预约直播室信息列表 */ 
typedef struct tagTVodRoomsCfg_Api
{
	TVodRoomCfg_Api atRoomcfg[KMTAPI_MAX_DIRECTBROADCAST_CNT]; ///< 列表信息
	u32 dwCnt;                                                                                              ///< 列表个数
public:
	tagTVodRoomsCfg_Api()
	{
		dwCnt = 0;
	}
}*PTVodRoomsCfg_Api, TVodRoomsCfg_Api;

/** 单VOD播放信息 */
typedef struct tagTVodPlayInfo_Api
{
	s8               achPlayUrl[KMTAPI_BUF_256_LEN+1];                                                 ///< 点播地址
	u32              dwVodId;                                                                                          ///< 点播地址标识
	TStreamInfo_Api  arrTStreamInfo[KMTAPI_MAX_VOD_STREAM_CHANNEL_NUM]; ///< 码流状态
	u8               byCnt;                                                                                                ///< 码流路数
	EmRtspStatus_Api emStatus;                                                                                 ///< 状态
	BOOL32           bIsLiveBroadcast;                                                                           ///< 是否为直播
public:
	tagTVodPlayInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTVodPlayInfo_Api ) );}
}*PTVodPlayInfo_Api,TVodPlayInfo_Api;

/** 多VOD播放信息 */
typedef struct tagTMultiVodPlayInfo_Api
{
	TVodPlayInfo_Api arrTVodInfo[KMTAPI_MAX_VOD_STREAM_NUM]; ///< VOD信息
	u8 byCnt;                                                                                         ///< 实际路数
public:
	tagTMultiVodPlayInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTMultiVodPlayInfo_Api ) );}
}*PTMultiVodPlayInfo_Api,TMultiVodPlayInfo_Api;

/** 视频点播源信息 */
typedef struct tagTMTVodStream_Api
{
	u32         dwVodId;      ///< vodid
	u32         dwStreamId; ///< vodid下的streamid
public:
	tagTMTVodStream_Api(){ memset ( this ,0 ,sizeof( struct tagTMTVodStream_Api ) );}
}*PTMTVodStream_Api,TMTVodStream_Api;

/** 视频点播源流信息 */
typedef struct tagTMTVodStreamInfo_Api
{
	u32         dwVodId;                 ///< vodid
	TStreamInfo_Api tStreamInfo; ///< stream信息
public:
	tagTMTVodStreamInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTMTVodStreamInfo_Api ) );}
}*PTMTVodStreamInfo_Api,TMTVodStreamInfo_Api;

/** 台标位置坐标 */
typedef struct tagTMTSymboPoint_Api
{
	u16 X; ///< X坐标
	u16 Y; ///< Y坐标
public:
	tagTMTSymboPoint_Api(){ memset( this ,0 ,sizeof( struct  tagTMTSymboPoint_Api ) );}
}*PTMTSymboPoint_Api,TMTSymboPoint_Api;

/** 显示设置信息数据结构定义 */
typedef struct tagTMTOsdCfg_Api
{
	BOOL32  bIsAutoPip;                                       ///< 是否启用自动画中画
	BOOL32  bIsShowConfLapse;                           ///< 是否显示会议时间
	BOOL32  bIsShowSysTime;                               ///< 是否显示系统时间
	BOOL32  bIsShowState;                                   ///< 是否显示状态标志
	EmLabelType_Api         emLabelType;               ///< 台标类型
	TMTSymboPoint_Api       tLableCoordinate;      ///< 自定义台标位置
	EmLabelPosType_Api      emLabelPosType;        ///< 终端别名台标位置
	EmDualVideoShowMode_Api emDualMode;     ///< 双流显示方式
	EmDisplayRatio_Api      emPrimaryDisplayRatio; ///< 第一路显示比例模式
	EmDisplayRatio_Api      emSecondDisplayRatio; ///< 第二路显示比例模式
public:
	tagTMTOsdCfg_Api(){ memset( this ,0 ,sizeof( struct  tagTMTOsdCfg_Api ) );}
}*PTMTOsdCfg_Api, TMTOsdCfg_Api;

/** 非对称网络支持 */
typedef struct tagTAsymmetricNetInfo_Api
{
	BOOL32   bIsEnable;        ///< 是否启用不对称网络
	u32      dwUplinkRate;     ///< 上行码率，单位kbps
	u32      dwDownlinkRate; ///< 下行码率，单位kbps
public:
	tagTAsymmetricNetInfo_Api(){ memset( this ,0 ,sizeof( struct tagTAsymmetricNetInfo_Api ) ); }
}*PTAsymmetricNetInfo_Api,TAsymmetricNetInfo_Api; 

/** mc丢包重传参数 */
typedef struct tagTMTMcRSParam_Api
{
	u32  dwFirstTimeSpan;      ///< 第一个重传检测点(ms)
	u32  dwSecondTimeSpan; ///< 第二个重传检测点(ms)
	u32  dwThirdTimeSpan;    ///< 第三个重传检测点(ms)
	u32  dwRejectTimeSpan;  ///< 过期丢弃的时间跨度(ms)
public:
	tagTMTMcRSParam_Api()
	{
		dwFirstTimeSpan  = 40;
		dwSecondTimeSpan = 2000;
		dwThirdTimeSpan  = 0;
		dwRejectTimeSpan = 0;
	}
}*PTMTMcRSParam_Api, TMTMcRSParam_Api;

/** FEC配置信息结构 */
typedef struct tagTMTFecInfo_Api
{
	BOOL32   bEnableFec;      ///< 视频是否使用前向纠错
	u8       byAlgorithm;         ///< 设置fec算法 0:NONE 1:RAID5 2:RAID6
	u16      wPackLen;            ///< 设置fec的切包长度
	BOOL32   bIntraFrame;     ///< 是否帧内fec
	u32      dwDataPackNum; ///< 设置fec的x包数据包
	u32      dwCrcPackNum;   ///< 设置fec的y包冗余包
public:
	tagTMTFecInfo_Api(){ memset( this, 0, sizeof( struct tagTMTFecInfo_Api ) ); }
}*PTMTFecInfo_Api,TMTFecInfo_Api;

/** QoS服务类型对应的参数 */
typedef struct tagTMTQosParam_Api
{
	u32 dwSignalling;  ///< 信令QOS值 范围
	u32 dwData;         ///< 数据信道（用于摄像头远摇）QOS值 范围
	u32 dwAudio;       ///< 语音QOS值 范围
	u32 dwVideo;       ///< 视频QOS值 范围
public:
	tagTMTQosParam_Api(){ memset( this, 0, sizeof( struct tagTMTQosParam_Api ) ); }
}*PTMTQosParam_Api, TMTQosParam_Api;

/** QOS信息数据结构 */
typedef struct tagTMTIPQoS_Api
{
	EmQoS_Api       emType;                          ///< QoS服务类型
	EmTOS_Api       emTos;                             ///< 质量保证类型
	TMTQosParam_Api tDiffServiceParam;      ///< QOS类型服务为区分服务时对应的参数
	TMTQosParam_Api tIpPrecedenceParam;  ///< QOS类型服务为IP优先时对应的参数
public:
	tagTMTIPQoS_Api(){ memset( this ,0 ,sizeof( struct  tagTMTIPQoS_Api ) );}
}*PTMTIPQoS_Api, TMTIPQoS_Api; 

/** 丢包重传参数 */
typedef struct tagTPrsParam_Api
{
	BOOL32 bEnable;                 ///< 是否启用                  
	u32    dwFirstTimeSpan;       ///< 第一个重传检测点(ms)
	u32    dwSecondTimeSpan;  ///< 第二个重传检测点(ms)
	u32    dwThirdTimeSpan;      ///< 第三个重传检测点(ms)
	u32    dwRejectTimeSpan;     ///< 过期丢弃的时间跨度(ms)
	u32    dwSendBufTimeSpan; ///< 发送缓存           default 1000
	BOOL32 bUseSmoothSend;  ///< 启用平滑发送
public:
	tagTPrsParam_Api()
	{
		bEnable = FALSE;
		dwFirstTimeSpan  = 40;
		dwSecondTimeSpan = 2000;
		dwThirdTimeSpan  = 0;
		dwRejectTimeSpan = 0;
		dwSendBufTimeSpan = 1000;
		bUseSmoothSend = FALSE;
	}
}*PTPrsParam_Api,TPrsParam_Api;


/** 视频编码器参数配置 */
typedef struct tagTMTVideoEncoderParamCfg_Api
{
	EmCodecComponentIndex_Api emCodecIdx; ///< 对应编码器索引
	u32 dwH265IKeyInterval;                                ///< H265关键帧间隔	
	u32 dwH265QualMaxValue;	                          ///< H265最大量化参数
	u32 dwH265QualMinValue;	                          ///< H265最小量化参数
	u32 dwH264IKeyInterval;                                 ///< H264关键帧间隔	
	u32 dwH264QualMaxValue;	                           ///< H264最大量化参数
	u32 dwH264QualMinValue;	                           ///< H264最小量化参数
	u32 dwKeyFrameInterval;	                               ///< 非H264 H265关键帧间隔
	u32 dwQualMinValue;                                     ///< 非H264 H265最小量化参数
	u32 dwQualMaxValue;		                               ///< 非H264 H265最大量化参数
	u32 dwFrameRate1080p;	                               ///< 1080p分辨率下帧率, 优选帧率
	u32 dwFrameRate720p;	                                   ///< 720p分辨率下帧率(针对高清终端)
    u32 dwFrameRateGT720p;                                ///< VGA制式，分辨率大于720p时的帧率
    u32 dwFrameRateLT720p;                                 ///< VGA制式，分辨率小于720p时的帧率
	u32 dwFrameRate4k;	                               ///< 1080p分辨率下帧率, 优选帧率
	BOOL32  bSkip;										///是否跳帧 用于android 移动端 超码率问题
	float   fRatio;									///丢帧倍率 用于android 移动端 超码率问题
public:
	tagTMTVideoEncoderParamCfg_Api(){ memset( this ,0 ,sizeof( struct  tagTMTVideoEncoderParamCfg_Api ) );}
}*PTMTVideoEncoderParamCfg_Api, TMTVideoEncoderParamCfg_Api;

/** 视频解码器参数配置 */
typedef struct tagTMTVideoDecoderParamCfg_Api
{
	EmCodecComponentIndex_Api emCodecIdx;     ///< 对应解码器索引
	EmLostPackStrategy_Api    emLostPackStrategy; ///< 解码器丢包恢复策略
public:
	tagTMTVideoDecoderParamCfg_Api(){ memset( this ,0 ,sizeof( struct  tagTMTVideoDecoderParamCfg_Api ) );}
}*PTMTVideoDecoderParamCfg_Api,TMTVideoDecoderParamCfg_Api;

/** 音频优选 */
typedef struct tagTMTAudioPriorCfg_Api
{
	EmAudFormat_Api   emAudioFormat;         ///< 音频优选格式
	EmAacChnlNum_Api  emAacChannelNum; ///< AAC优选声道
	EmAacSampFreq_Api emAaSampFreq;       ///< AAC优选采样码率
public:
	tagTMTAudioPriorCfg_Api(){ memset( this ,0 ,sizeof( struct  tagTMTAudioPriorCfg_Api ) );}
}*PTMTAudioPriorCfg_Api, TMTAudioPriorCfg_Api;

/** 视频优选参数 */
typedef struct tagTVidPriorParam_Api
{
	EmVidFormat_Api    emVideoFormat;   ///<视频优选协议
	EmMtResolution_Api emVideoRes;      ///<分辨率优选协议
public:
	tagTVidPriorParam_Api(){ memset( this ,0 ,sizeof( struct  tagTVidPriorParam_Api ) );}
}*PTVidPriorParam_Api, TVidPriorParam_Api;

/** 主流优选（主流可能存在多路，所以用数组） */
typedef struct tagTMTPriVideoPriorCfg_Api
{
	TVidPriorParam_Api atVideoPriorParam[KMTAPI_MAX_MULTI_CHANNEL_NUM];  ///< 最多5个成员
	u8 byCnt;                                                                                                             ///< 多流个数
public:
	tagTMTPriVideoPriorCfg_Api(){ memset( this ,0 ,sizeof( struct  tagTVidPriorParam_Api ) );}
}*PTMTPriVideoPriorCfg_Api, TMTPriVidPriorCfg_Api;

/** TCP/UDP起始配置信息 */
typedef struct tagTTcpUdpBasePortCfg_Api
{
	BOOL32     bAuto;          ///< 是否启用随机端口
	u16        wTcpBasePort;  ///< tcp起始端口
	u16        wUdpBasePort; ///< udp起始端口
public:
	tagTTcpUdpBasePortCfg_Api(){ memset( this ,0 ,sizeof( struct  tagTTcpUdpBasePortCfg_Api ) );}
}*PTTcpUdpBasePortCfg_Api,TTcpUdpBasePortCfg_Api;

/** 滚动短消息配置信息 */
typedef struct tagTRollMsgCfg_Api
{
	EmFontSize_Api  emSize;     ///< 字体大小
	EmFontColor_Api emColor; ///< 字体颜色
	EmFontColor_Api emBackGroundColor;///<背景颜色
public:
	tagTRollMsgCfg_Api(){ memset( this ,0 ,sizeof( struct  tagTRollMsgCfg_Api ) );}
}*PTRollMsgCfg_Api,TRollMsgCfg_Api;

/**  视频编码参数 */
typedef struct tagTVidEncParam_Api
{
	EmEncodeMode_Api emEncMode;      ///< 图像压缩码率控制参数
	EmVidFormat_Api  emVidFormat;        ///< 图像编码类型
	u32              dwMaxKeyFrameInterval; ///< I帧间最大P帧数目
	u32              dwMaxQuant;                  ///< 最大量化参数(1-31)
	u32              dwMinQuant;                  ///< 最小量化参数(1-31)
	u32              dwFrameRate;                 ///< 帧率(default:25)
	u32              dwBitrate;                       ///< 编码比特率(Kbps)
	u32              dwH264Profile;               ///< 编码能力级别 1:LV_QUALITY_PRIOR,2:LV_SPEED_PRIOR,3:LV_HPSINGLE_PRIOR,4:LV_HPMULTE_PRIOR
	u32              dwWidth;                       ///< 图像编码宽度
	u32              dwHeight;                      ///< 图像编码高度
public:
	tagTVidEncParam_Api(){ memset( this ,0 ,sizeof( struct  tagTVidEncParam_Api ) );}
}*PTVidEncParam_Api, TVidEncParam_Api;

////暂时用于ipc
typedef struct tagTMTStreamChanParam_Api
{
	TVidEncParam_Api  tEncParam;   ///< 通道的编码格式
	TNetAddr_Api      tTransRtp;   ///< 终端收rtp地址
	u32               dwPayload;   ///< 码流的 payload
public:
	tagTMTStreamChanParam_Api() { memset( this ,0 ,sizeof( struct  tagTMTStreamChanParam_Api ) ); }

}*PTMTStreamChanParam_Api,TMTStreamChanParam_Api;


/** PC双流通道参数所有信息结构 */
typedef struct tagTMTPcAssStreamChanParam_Api 
{
	TNetAddr_Api       tTransRtp;      ///< mt转发rtp地址
	TNetAddr_Api       tTransRtcp;     ///< mt转发rtcp地址 
	TVidEncParam_Api   tEncParam; ///< 通道的编码格式
	u32                dwPlayLoad;         ///< 通道payload
	TEncryptKey_Api    tEncryptKey;  ///< 加密密码
public:
	tagTMTPcAssStreamChanParam_Api(){ memset( this ,0 ,sizeof( struct  tagTMTPcAssStreamChanParam_Api ) );}
}*PTMTPcAssStreamChanParam_Api,TMTPcAssStreamChanParam_Api;

/** PC桌面共享时，发送端PC的相关参数:系统分辨率,本端地址 */
typedef struct tagTPCSysParam_Api
{
	u16                   wScrWidth;                               ///< 屏幕宽
	u16                   wScrHeight;                              ///< 屏幕高
	u8                    byMaxH263CapSVGA;                ///< 获取H.263/SVGA下的最大捕捉能力
	u8                    byMaxH263CapXGA;                  ///< 获取H.263/XGA下的最大捕捉能力
	u8                    byMaxH264CapSVGA;                ///< 设置H.264/SVGA下的最大捕捉能力
	u8                    byMaxH264CapXGA;                   ///< 设置H.264/XGA下的最大捕捉能力
	u32                   dwMtAddr;                                 ///< 目标终端的IP信息(网络序)
	EmMtResolution_Api emVidRes;                          ///< 屏幕分辨率
	TNetAddr_Api          tPcNetAddr;                         ///< 本端地址
	EmCodecComponent_Api  emCodecComponent; ///< 编解码发送类型
	EmMtVideoPort_Api     emMtVideoPort;               ///< 音视频端口
public:
	tagTPCSysParam_Api()
	{ 
		memset( this ,0 , sizeof( struct  tagTPCSysParam_Api ) );
		emMtVideoPort    = /*emMtPC_Api*/emMtVidInvalid_Api;
		emCodecComponent = emVidMainEncoder_Api;
	}
}*PTPCSysParam_Api, TPCSysParam_Api;

/** 编码器统计信息 */
typedef struct tagTCodecPackStat_Api
{
	u32    dwBitrate;             ///< 实时码率
	u32    dwAvrBitrate;        ///< 平均码率
	u32    dwLostPacks;         ///< 丢包数
	u32    dwTotalPacks;        ///< 收发包数
	u32    dwFrames;             ///< 收发帧数
	u32    dwLostFrameRate; ///< 丢帧率(2秒)%d 
public:
	tagTCodecPackStat_Api(){memset(this ,0 ,sizeof( struct tagTCodecPackStat_Api)); }
}*PTCodecPackStat_Api,TCodecPackStat_Api;

/** socket5代理信息 */
typedef struct tagTMTOspSock5Proxy_Api
{
	u32 dwProxyIp;                                                                  ///< 代理IP(网络序)
	u32 dwProxyPort;                                                               ///< 代理端口
	u32 dwAuthenNum;                                                           ///< 认证次数
	s8  achAuthenMethod[KMTAPI_BUF_128_LEN+1];               ///< 认证方法
	s8  achUserName[KMTAPI_IM_SOCK5_USERNAME_LEN+1]; ///< 用户名
	s8  achPassword[KMTAPI_IM_SOCK5_PASSWORD_LEN+1];  ///< 密码
public:
	tagTMTOspSock5Proxy_Api(){ memset( this ,0 ,sizeof( struct  tagTMTOspSock5Proxy_Api ) );}
}*PTMTOspSock5Proxy_Api, TMTOspSock5Proxy_Api;

/** 升级服务器信息 */
typedef struct tagTMTSUSAddr_Api
{
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1];           ///< 域名
	u32 dwIP;                                                                                 ///< ip (使用网络序)
	u32 dwPort;
	BOOL32 bUseDefaultAddr;                                                        ///< 使用默认地址
	s8 achCustomDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< 用户自定义域名
	u32 dwCustomIp;                                                                      ///<用户自定义ip
public:
	tagTMTSUSAddr_Api(){ memset( this ,0 ,sizeof( struct  tagTMTSUSAddr_Api ) );}
}*PTMTSUSAddr_Api,TMTSUSAddr_Api;

/** 升级时需提供的升级服务器信息 */
typedef struct tagTMTUpgradeNetParam_Api
{
	u32    dwServerIp;                            ///< sus服务器IP (网络序)
	u32    dwPort;
	BOOL32 bUsedProxy;                       ///< 是否启用代理服务器
	TMTOspSock5Proxy_Api tProxyInfo; ///< 启用代理的话 代理服务器信息
	s8	achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1];   ///< 域名
public:
	tagTMTUpgradeNetParam_Api(){ memset( this ,0 ,sizeof( struct  tagTMTUpgradeNetParam_Api ) );}
}*PTMTUpgradeNetParam_Api,TMTUpgradeNetParam_Api;

/** 升级时需提供的设备信息 */
typedef struct tagTMTUpgradeDeviceInfo_Api
{
	s8 achDevType[KMTAPI_MAX_DEV_TYPE_NAME_LEN+1];   ///< 设备类型
	s8 achOemMark[KMTAPI_MAX_DEV_OEM_MARK_LEN+1]; ///< 设备OEM标识
	s8 achE164[KMTAPI_MAX_MT_E164_LEN+1];                      ///< 设备164标识
	s8 achCurSoftVer[KMTAPI_MAX_DEV_SOFT_VER_LEN+1];   ///< 设备目前软件版本
	u32 dwDevIp;                                                                     ///< 终端IP (网络序)
public:
	tagTMTUpgradeDeviceInfo_Api(){ memset( this ,0 ,sizeof( struct  tagTMTUpgradeDeviceInfo_Api ) );}
}*PTMTUpgradeDeviceInfo_Api,TMTUpgradeDeviceInfo_Api;

/** 升级时需提供给升级组件的信息 */
typedef struct tagTMTUpgradeClientInfo_Api
{
	TMTUpgradeNetParam_Api   tServerInfo;  ///< sus服务器信息
	TMTUpgradeDeviceInfo_Api tDevInfo;       ///< 设备信息
public:
	tagTMTUpgradeClientInfo_Api(){ memset( this ,0 ,sizeof( struct  tagTMTUpgradeClientInfo_Api ) );}
}*PTMTUpgradeClientInfo_Api,TMTUpgradeClientInfo_Api;

/** 升级灰度发布范围 */
typedef struct tagTMTUpgradeGrayRange_Api
{
	s8 achMoidList[KMTAPI_MAXLEN_SUS_MOIDLIST+1]; ///< moid列表
	s8 achE164List[KMTAPI_MAXLEN_SUS_E164LIST+1];    ///< e164列表
public:
	tagTMTUpgradeGrayRange_Api() { memset( this, 0, sizeof(struct tagTMTUpgradeGrayRange_Api) ); }
}*PTMTUpgradeGrayRange_Api, TMTUpgradeGrayRange_Api;

/** 检测升级得到的单个版本的信息 */
typedef struct tagTMTUpgradeVersionInfo_Api
{
	u32     dwVer_id ;   		                                                              ///< 版本唯一标识
	s8      achOemMark[KMTAPI_MAX_DEV_OEM_MARK_LEN+1];     ///< 设备OEM标识
	s8      achDevType[KMTAPI_MAX_DEV_TYPE_NAME_LEN+1];	      ///< 设备类型
	EmUpgradeVerLevel_Api emUpgradeVerLevel;                            ///< 升级类型
	s8      achCurSoftVer[KMTAPI_MAX_DEV_SOFT_VER_LEN+1];       ///< 设备目前软件版本
	s8      achVerNotes[KMTAPI_MAX_VER_RELEASE_NOTES_LEN+1]; ///< 版本说明信息
	u32     dwSize;                                                                             ///< 版本大小
	s8      achFileName[KMTAPI_BUF_256_LEN + 1];                          ///< 文件名
	EmUpgradeReleaseAttr_Api emUpgradeAttr;                               ///< 升级属性
	TMTUpgradeGrayRange_Api tGrayRange;                                   ///< 灰度发布范围
public:
	tagTMTUpgradeVersionInfo_Api(){ memset( this ,0 ,sizeof( struct  tagTMTUpgradeVersionInfo_Api ) );}
}*PTMTUpgradeVersionInfo_Api,TMTUpgradeVersionInfo_Api;

/** 检测升级得到的版本列表 */
typedef struct tagTMTUpgradeVersionInfoList_Api
{
	TMTUpgradeVersionInfo_Api tVerList[KMTAPI_MAX_UPGRATE_VER_LIST_NUM]; ///< 版本列表
	BOOL32 bNewestVersion;                                                                                  ///< 是否为最新版本
	u8  byCnt;                                                                                                          ///< 列表个数
public:
	tagTMTUpgradeVersionInfoList_Api(){ memset( this ,0 ,sizeof( struct  tagTMTUpgradeVersionInfoList_Api ) );}
}*PTMTUpgradeVersionInfoList_Api,TMTUpgradeVersionInfoList_Api;

/** 升级是下载进度信息 */
typedef struct tagTMTUpgradeDownloadInfo_Api
{
	u32  dwErrcode;                                                                       ///< 错误码
	u32  dwTotalPercent;	                                                            ///< 文件下载总进度
	u32  dwCurPercent;	                                                                ///< 当前文件的下载进度
	s8   achCurFileName[KMTAPI_MAX_PATH_FILE_NAME_LEN+1]; ///< 当前正在下载的文件名
public:
	tagTMTUpgradeDownloadInfo_Api(){ memset( this ,0 ,sizeof( struct  tagTMTUpgradeDownloadInfo_Api ) );}
}*PTMTUpgradeDownloadInfo_Api, TMTUpgradeDownloadInfo_Api;

/** XNU服务器(XMPP登录)配置 */
typedef struct tagTMtXMPPInfo_Api
{
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< 域名
	u32 dwIp;                                                                       ///< ip (网络序)
	u32 dwPort;                                                                    ///< 端口
	s8  achName[KMTAPI_MAX_USERNAME_LEN+1];            ///< 用户名(jid)
	s8  achPassword[KMTAPI_MAX_USERPWD_LEN+1];         ///< 密码
public:
	tagTMtXMPPInfo_Api(){ memset( this ,0 ,sizeof( struct  tagTMtXMPPInfo_Api ) );}
}*PTMtXMPPInfo_Api, TMtXMPPInfo_Api;

/** 获取NS地址 (新加)*/
typedef struct tagTMtNSADDRInfo_Api
{
    s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< 域名
    u32 dwIp;                                    ///< ip (网络序)
    u32 dwPort;                                 ///< 端口
    u32 dwTlsProt;                              ///tls
public:
    tagTMtNSADDRInfo_Api(){ memset( this ,0 ,sizeof( struct  tagTMtNSADDRInfo_Api ) );}
}TMtNSADDRInfo_Api, *PTMtNSADDRInfo_Api;


/** CSU服务器 */
typedef struct tagTMtCSUAddr_Api
{
	BOOL32 bUsedCSU;                             ///< 是否使用CSU
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< GK域名
	u32 dwIp;                                    ///< GKIp (网络序)
	u32 dwPort;                                  ///< GK端口， 如果不填，标准是1720， 非标的是用平台返回的值
	s8 achNumber[KMTAPI_MAX_DOMAIN_NAME_LEN+1];  ///< 注册时使用的号码
	s8 achPassword[KMTAPI_MAX_USERPWD_LEN+1];    ///< 密码
	u32 dwTimeToLive;                            ///< GK保活超时时间 单位(s)
	s8  achAuthName[KMTAPI_MAX_DOMAIN_NAME_LEN]; ///< 认证名称, 填写密码后会用到认证名称
public:
	tagTMtCSUAddr_Api(){ memset( this ,0 ,sizeof( struct  tagTMtCSUAddr_Api ) );}
}*PTMtCSUAddr_Api, TMtCSUAddr_Api;

/** 网管服务器地址 */
typedef struct tagTMtNMAAddr_Api
{
	u32 dwIp;                                                                       ///< 网管服务器Ip (网络序)
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< 域名	
	u32 dwPort;                                                                   ///< 端口
public:
	tagTMtNMAAddr_Api(){ memset( this ,0 ,sizeof( struct  tagTMtNMAAddr_Api ) );}
}*PTMtNMAAddr_Api, TMtNMAAddr_Api;

/** 登录Nms所需要的客户端硬件信息参数 */ 
typedef struct tagTNMSClientHWInfo_Api 
{
	s8 achOS[KMTAPI_BUF_128_LEN + 1];          ///< 操作系统
	s8 achCpuType[KMTAPI_BUF_128_LEN + 1]; ///< cpu型号
	u32 dwCpuFreq;                                          ///< cpu主频(Mhz)
	u32 dwMemory;                                          ///< 内存总量(M)
	u32 dwCpuNum;                                         ///< cpu核数
public:
	tagTNMSClientHWInfo_Api(){ memset( this ,0 ,sizeof( struct  tagTNMSClientHWInfo_Api ) );}
}*PTNMSClientHWInfo_Api, TNMSClientHWInfo_Api;

/** NMS登录结果 */
typedef struct tagTNMSLogInResult_Api
{
	BOOL32  bLoginOk; ///<NMS登录结果
	u32		dwReason; ///<若登录失败，该字段表明了失败原因
public:
	tagTNMSLogInResult_Api(){ memset( this ,0 ,sizeof( struct  tagTNMSLogInResult_Api ) );}
}*PTNMSLogInResult_Api, TNMSLogInResult_Api;

/** NTS测试服务器登录配置 */
typedef struct tagTMtNTSAddr_Api
{
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< 域名
	u32 dwIp;                                                                      ///< Ip (网络序)
	u32 dwPort;
public:
	tagTMtNTSAddr_Api(){ memset( this ,0 ,sizeof( struct  tagTMtNTSAddr_Api ) );}
}*PTMtNTSAddr_Api, TMtNTSAddr_Api;

/** NAT信息配置 */
typedef struct tagTMTNat_Api
{
	BOOL32   bEnable; ///< 是否启用
	u32      dwIp;         ///< NAT Ip地址  (网络序)
public:
	tagTMTNat_Api(){ memset( this ,0 ,sizeof( struct  tagTMTNat_Api ) );}
}*PTMTNat_Api, TMTNat_Api;

/** XAP登录配置 */
typedef struct tagTMtXAPSvr_Api
{
	EmServerAddrType_Api emAddrType;                             ///< 地址类型
	s8  achAlias[KMTAPI_BUF_64_LEN+1];                            ///< 别名
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< 域名
	u32 dwIp;                                                                       ///< ip (网络序)
	BOOL32 bIsIpSvr;                             ///< 是否是IP类型的aps服务器
    u32 dwPort;                                  ///端口号
public:
	tagTMtXAPSvr_Api(){ memset( this ,0 ,sizeof( struct  tagTMtXAPSvr_Api ) );}
}*PTMtXAPSvr_Api, TMtXAPSvr_Api;

/** APS地址信息 */
typedef struct tagTMtAPSSvrAddr_Api
{
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< 域名
	u32 dwIp;                                                                       ///< ip (网络序)
    u32 dwPort;                                  ///< 端口号
public:
	tagTMtAPSSvrAddr_Api(){ memset( this ,0 ,sizeof( struct  tagTMtAPSSvrAddr_Api ) );}
}*PTMtAPSSvrAddr_Api, TMtAPSSvrAddr_Api;

/** XAP登录配置 列表*/
typedef struct tagTMtXAPSvrList_Api
{
	BOOL32         bAutoSelect;							                          ///< 是否自动选择服务器登陆
	u8             byCurIndex;                                                           ///< 当前生效的地址索引
	TMtXAPSvr_Api  arrMtXAPSvr[KMTAPI_MAX_XAP_LIST_NUM];  ///< XAP登录列表
	u8             byCnt;                                                                    ///< 实际个数
public:
	tagTMtXAPSvrList_Api(){ memset( this ,0 ,sizeof( struct  tagTMtXAPSvrList_Api ) );}
}*PTMtXAPSvrList_Api, TMtXAPSvrList_Api;

/** NTP登录配置 */
typedef struct tagTMtNTPAddr_Api	
{
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< 域名
	u32 dwIp;                                                                       ///< ip (网络序)
	u32 dwPort;                                                                    ///< 端口
public:
	tagTMtNTPAddr_Api(){ memset( this ,0 ,sizeof( struct  tagTMtNTPAddr_Api ) );}
}*PTMtNTPAddr_Api, TMtNTPAddr_Api;

/** VOD服务器地址 */
typedef struct tagTMtVODSvrCfg_Api
{
	BOOL32 bEnable;                                                           ///< 是否启用
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< 域名
	u32 dwIp;                                                                       ///< ip (网络序)
	u16 wPort;                                                                      ///< 端口
	s8 achUsername[KMTAPI_MAX_USERNAME_LEN + 1];    ///< 用户名
	s8 achPassword[KMTAPI_MAX_USERPWD_LEN + 1];       ///< 密码
public:
	tagTMtVODSvrCfg_Api(){ memset( this ,0 ,sizeof( struct  tagTMtVODSvrCfg_Api ) );}
}*PTMtVODSvrCfg_Api, TMtVODSvrCfg_Api;

/** VRS服务器地址 */
typedef struct tagTMtVRSSvrCfg_Api
{
	BOOL32 bEnable;                                    ///< 是否启用
	BOOL32 bCustom;                                    ///< 是否自定义  TRUE:自定义 FALSE 自动
	s8     achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1];       ///< 登陆平台拿到的vod服务器地址
	u32    dwIp;                                                                             ///< ip (网络序)
	s8     achCustomAddr[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< 自定义服务器地址(bCustom为true的时候设置)
	u32    dwPort;                                                                            ///< 端口
	s8     achUsername[KMTAPI_MAX_FULL_USERNAME_LEN + 1];         ///< 用户名
	s8     achPassword[KMTAPI_MAX_USERPWD_LEN + 1];             ///< 密码
public:
	tagTMtVRSSvrCfg_Api(){ memset( this ,0 ,sizeof( struct  tagTMtVRSSvrCfg_Api ) );}
}*PTMtVRSSvrCfg_Api, TMtVRSSvrCfg_Api;

/** 流媒体 */
typedef struct tagTMTStreamMedia_Api
{
	BOOL32    bEnable;                                                                  ///< 是否启用
	BOOL32    bForwardLocalVideo;                                               ///< 是否转发本地视频
	u32       dwMultCastIP;                                                             ///< 组播IP地址 (网络序)
	u32       dwPort;                                                                        ///< 端口号
	u32       dwTTL;                                                                          ///< TTL值
	s8        achChnlName[KMTAPI_MAX_CHANNEL_NAME_LEN+1]; ///< 频道名称
	s8        achPassword[KMTAPI_MAX_CHANNEL_PWD_LEN+1];     ///< 密码
public:
	tagTMTStreamMedia_Api(){ memset( this ,0 ,sizeof( struct  tagTMTStreamMedia_Api ) );}
}*PTMTStreamMedia_Api, TMTStreamMedia_Api;

/** 平台API地址 */
typedef struct tagTMtPlatformApiAddr_Api
{
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< 域名
	u32 dwIp;                                                                       ///< ip (网络序)
public:
	tagTMtPlatformApiAddr_Api(){ memset( this ,0 ,sizeof( struct  tagTMtPlatformApiAddr_Api ) );}
}*PTMtPlatformApiAddr_Api, TMtPlatformApiAddr_Api;

/** 微博地址 */
typedef struct tagTMtMicroBlogAddr_Api
{
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< 域名
	u32 dwIp;                                                                       ///< ip (网络序)
public:
	tagTMtMicroBlogAddr_Api(){ memset( this ,0 ,sizeof( struct  tagTMtMicroBlogAddr_Api ) );}
}*PTMtMicroBlogAddr_Api, TMtMicroBlogAddr_Api;

/** Sip服务器配置 */
//当没有填写dwIp这个字段时，才会解析achPxyDomain sip代理服务器域名
typedef struct tagTMtSipSvrAddr_Api
{
	BOOL32 bEnable;										  ///< 是否注册sip代理服务器
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1];          ///< 服务器域名
	u32 dwIp;                                             ///< sip 代理服务器ip (网络序)
	u32 dwPort;                                           ///< 服务器端口, 如果上层设置为0， 底层为默认值5060
	s8  achPassword[KMTAPI_MAX_USERPWD_LEN+1];            ///< 注册密码
	u32 dwExpire;                                         ///< 过期时间，底层保活时间，如果是0， 底层为默认值20, 单位为s
	s8  achValidateName[KMTAPI_MAX_DOMAIN_NAME_LEN+1];    ///< 验证名称, 注册的名称， sip注册只能注册一个名称，别名/e164号
	u32 dwHostPort;                                       ///< 主机端口, 本机起的sip协议栈监听端口，　默认为5060
	s8  achAuthName[KMTAPI_MAX_DOMAIN_NAME_LEN];          ///< 认证的名称
	u32 dwTlsPort;                                        ///< 服务器tls端口, 如果上层设置为0， 底层为默认值5061
	u32 dwGtlsPort;                                       ///< 服务器gtls端口, 如果上层设置为0， 底层为默认值5061
	s8  achPxyDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1];       ///< sip代理服务器域名
public:
	tagTMtSipSvrAddr_Api(){ memset( this ,0 ,sizeof( struct  tagTMtSipSvrAddr_Api ) );}
}*PTMtSipSvrAddr_Api, TMtSipSvrAddr_Api;

/** Sip代理配置 */
typedef struct tagTMtSipProxyCfg_Api
{
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1];  ///< 服务器域名
	u32 dwIp;                                                                       ///< 服务器ip (网络序)
	u32 dwPort;                                                                   ///< 服务器端口
public:
	tagTMtSipProxyCfg_Api(){ memset( this ,0 ,sizeof( struct  tagTMtSipProxyCfg_Api ) );}
}*PTMtSipProxyCfg_Api, TMtSipProxyCfg_Api;

/** H323代理服务器配置 */
typedef struct tagTMtH323PxyCfg
{
	BOOL32 bEnable;								                            ///< 是否启用
	u32 dwSrvIp;                                                                 ///< 服务器ip (网络序)
	u32 dwSrvPort;                                                              ///< 服务器端口
	s8 achNumber[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< 注册时使用的号码
	s8 achPassword[KMTAPI_MAX_USERPWD_LEN+1];         ///< 密码
public:
	tagTMtH323PxyCfg(){ memset( this ,0 ,sizeof( struct  tagTMtH323PxyCfg ) );}
}*PTMtH323PxyCfg_Api, TMtH323PxyCfg_Api;

/** Meeting服务器配置 */
typedef struct tagTMtMeetingSvrAddr_Api
{
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< 服务器域名
	u32 dwIp;                                                                      ///< 服务器ip (网络序)
	u32 dwPort;
public:
	tagTMtMeetingSvrAddr_Api(){ memset( this ,0 ,sizeof( struct  tagTMtMeetingSvrAddr_Api ) );}
}*PTMtMeetingSvrAddr_Api, TMtMeetingSvrAddr_Api;

/** H460代理服务器配置 */
typedef struct tagTMtH460PxyCfg
{
	BOOL32 bEnable;								                            ///< 是否启用
	u32 dwSrvIp;                                                                 ///< 服务器ip (网络序)
	s8 achNumber[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< 注册时使用的号码
	s8 achPassword[KMTAPI_MAX_USERPWD_LEN+1];         ///< 密码
public:
	tagTMtH460PxyCfg(){ memset( this ,0 ,sizeof( struct  tagTMtH460PxyCfg ) );}
}*PTMtH460PxyCfg_Api, TMtH460PxyCfg_Api;

/** socks5代理配置 */ 
typedef struct tagTSocks5ProxyCfg_Api
{
	TNetAddr_Api tServerAddr;                                                ///< socks5代理服务器地址
	s8  achUserName[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< 服务器域名
	s8  achPassword[KMTAPI_MAX_USERPWD_LEN+1];            ///< 密码
public:
	tagTSocks5ProxyCfg_Api(){ memset( this ,0 ,sizeof( struct tagTSocks5ProxyCfg_Api ) );}
}*PTSocks5ProxyCfg_Api,TSocks5ProxyCfg_Api;

/** 服务器状态项 */
typedef struct tagTMtSvrState_Api
{
	EmServerType_Api  emSvrType; ///< 描述服务器
	EmServerState_Api emSvrState; ///< 状态        
public:
	tagTMtSvrState_Api(){ memset( this ,0 ,sizeof( struct tagTMtSvrState_Api ) );}
}*PTMtSvrState_Api,TMtSvrState_Api;

/** 服务器状态表 */
typedef struct tagTMtSvrStateList_Api
{
	TMtSvrState_Api arrSvrState[KMTAPI_MAX_SVRSTATE_LIST_NUM]; ///< 服务器状态列表
	u8              byCnt;                                                                         ///< 实际个数
public:
	tagTMtSvrStateList_Api(){ memset( this ,0 ,sizeof( struct tagTMtSvrStateList_Api ) );}
}*PTMtSvrStateList_Api,TMtSvrStateList_Api;

/** Xap登录成功后获取的用户权限信息 */
typedef struct tagTMtUserPrevilege_Api
{
	BOOL32 bDefaultServiceDomainAdmin; ///< 默认的服务域管理
	BOOL32 bDefaultUserDomainAdmin;     ///< 默认的用户域管理
	BOOL32 bEnableBMC;     				         ///< BMC权限
	BOOL32 bEnableCall;     			             ///< 开通电话会议
	BOOL32 bEnableDCS;     				         ///< DCS权限
	BOOL32 bEnableHD;     				        ///< 支持高清视频会议
	BOOL32 bEnableIncoming;     		        ///< 开通入局权限
	BOOL32 bEnableMeeting;     			    ///< 开通会议管理
	BOOL32 bEnableMeetingSMS;     		    ///< 会管短信权限
	BOOL32 bEnableNM;     				        ///< NM权限
	BOOL32 bEnableOut;     				       ///< 开通出局权限
	BOOL32 bEnableRoam;     			       ///< 开通漫游权限
	BOOL32 bEnableSatellite;     		          ///< 卫星线路权限
	BOOL32 bEnableSatelliteP2P;     	      ///< 卫星线路点对点
	BOOL32 bEnableUMC;     				      ///< UMC权限
	BOOL32 bEnableVRS;     				      ///< VRS权限
	BOOL32 bEnableWeibo;     			      ///< 开通微博
	BOOL32 bEnableAdmin;     			      ///< 会议管理员
	BOOL32 bServiceDomainAdmin;     	  ///< 服务域管理员
	BOOL32 bUserDomainAdmin;     		  ///< 用户域管理员
	BOOL32 bWeiboAdmin;     			      ///< 微博管理员
	BOOL32 bSelfBuilt; 					         ///< 平台属性：是否自建平台
	BOOL32 bPortMedia; 		                 ///< 平台属性：端口会议
    BOOL32 bEnableAutoCreateMeeting;           /// 创会权限 （仅支持平台5.2之后版本）
public:
	tagTMtUserPrevilege_Api(){ memset( this ,0 ,sizeof( struct tagTMtUserPrevilege_Api ) );}
}*PTMtUserPrevilege_Api,TMtUserPrevilege_Api;

/** aps登录获取到的用户信息 */
typedef struct tagTMTUserInfoFromAps_Api
{
	s8 achE164[KMTAPI_MAX_MT_E164_LEN+1];            ///< E164
	s8 achEmail[KMTAPI_MAX_EMAIL_LEN+1];               ///< 邮箱
	s8 achJid[KMTAPI_IM_MAX_ID_LEN + 1];                  ///< Jid
	s8 achMoid[KMTAPI_MAX_DOMAIN_MOID_LEN+1]; ///< Moid
	s8 achXmppPwd[KMTAPI_BUF_64_LEN + 1];              ///< XMPP密码
	s8 achAccount[KMTAPI_BUF_128_LEN + 1];               ///< 自定义账号
    u32 dwRegMode;                                 // 1:使用164号注册，2使用m_szMoid注册
    s8  achCTime[KMTAPI_BUF_16_LEN+1];             //用户创建时间格式 20170908120506(年月日时分秒)
    BOOL32 bIsGuest;                               //FALSE表示普通用户 TRUE表示来宾用户 
public:
	tagTMTUserInfoFromAps_Api(){ memset( this ,0 ,sizeof( struct tagTMTUserInfoFromAps_Api ) );}
}*PTMTUserInfoFromAps_Api, TMTUserInfoFromAps_Api;

/** H323配置 */
typedef struct tagTMtH323Cfg_Api	
{
	BOOL32 bEnableH239; ///< h239方式 
	u32    dwCallPriority;    ///< 呼叫优先级， 用于强拆， 这里范围是1-255
public:
	tagTMtH323Cfg_Api(){ memset( this ,0 ,sizeof( struct tagTMtH323Cfg_Api ) );}
}*PTMtH323Cfg_Api,TMtH323Cfg_Api;

/** 音频选项 */
typedef struct tagTMTAudioOptions_Api
{
	BOOL32 bEnableAEC; ///< 回声消除
	BOOL32 bEnableAGC; ///< 自动增益补偿
	BOOL32 bEnableANS; ///< 背景噪音抑制
public:
	tagTMTAudioOptions_Api(){ memset( this ,0 ,sizeof( struct tagTMTAudioOptions_Api ) );}
}*PTMTAudioOptions_Api,TMTAudioOptions_Api;

/** 自动呼叫 */
typedef struct tagTMTAutoCall_Api
{
	BOOL32  bIsAutoCallEnable;                                      ///< 是否启用自动呼叫
	s8      achTerName[KMTAPI_MAX_MT_ALIAS_LEN+1]; ///< 自动呼叫的终端名
	u32     dwCallRate;                                                     ///< 自动呼叫码率
public:
	tagTMTAutoCall_Api(){ memset( this ,0 ,sizeof( struct tagTMTAutoCall_Api ) );}
}*PTMTAutoCall_Api,TMTAutoCall_Api;

/** 发送视频通道比例策略 */
typedef struct tagTVidBitRationCfg_Api
{
	EmVidRationStrategy_Api     emRationStrategy; ///< 策略，辅视频优先，还是主视频优先，还是自定义，如果自定义填下面的参数
	u32    adwMainVidRation[KMTAPI_COUNT_8];   ///< 主视频每个通道的比例
	u32    dwMainCount;                                        ///< 共有多少个主视频
	u32    adwAssVidRation[KMTAPI_COUNT_8];     ///< 辅视频每个通道的比例
	u32    dwAssCount;                                           ///< 共有多少个辅视频
public:
	tagTVidBitRationCfg_Api(){ memset( this ,0 ,sizeof( struct tagTVidBitRationCfg_Api ) );}
}*PTVidBitRationCfg_Api ,TVidBitRationCfg_Api;

/** 终端名称 */
typedef struct tagTMtTerminalName_Api
{
	s8 	    achE164[KMTAPI_MAX_MT_E164_LEN+1];     ///< 终端E164号码
	s8      achTerlAlias[KMTAPI_MAX_MT_ALIAS_LEN+1]; ///< 终端名称
public:
	tagTMtTerminalName_Api(){ memset( this ,0 ,sizeof( struct tagTMtTerminalName_Api ) );}
}*PTMtTerminalName_Api,TMtTerminalName_Api;

/** 终端信息 */
typedef struct tagTTerminalInfo_Api
{
	EmMtModel_Api emMtModel;                                                               ///< 终端型号
	s8 	          achTypeName[KMTAPI_MAX_MT_TYPE_NAME_LEN+1];        ///< 终端型号名称
	s8            achHardwareVer[KMTAPI_MAX_MT_HARDWARE_VER_LEN+1]; ///< 硬件版本
	s8            achSoftwareVer[KMTAPI_MAX_MT_SOFTWARE_VER_LEN+1];   ///< 软件版本
	s8            achOEMName[KMTAPI_MAX_MT_OEM_NAME_LEN+1];           ///< 厂商信息
	s8            achFPGA1Ver[KMTAPI_BUF_32_LEN+1];                                     ///< FPGA1版本
	s8            achFPGA2Ver[KMTAPI_BUF_32_LEN+1];                                     ///< FPGA2版本
	s8            achCPLDVer[KMTAPI_BUF_32_LEN+1];                                     ///< CPLD版本
	s8            achSerialNum[KMTAPI_BUF_32_LEN+1];                                   ///< 序列号
    s8            achInfraredVer[KMTAPI_BUF_32_LEN+1];                                  ///< 红外单片机版本号
	s8            achFPGA3Ver[KMTAPI_BUF_32_LEN+1];                                     ///< FPGA3版本
	s8            achFPGA4Ver[KMTAPI_BUF_32_LEN+1];                                     ///< FPGA4版本
	s8			  achPTZVer[KMTAPI_BUF_32_LEN+1];                                       ///< PTZ版本号，仅 sky300支持
public:
	tagTTerminalInfo_Api(){ memset( this ,0 ,sizeof( struct tagTTerminalInfo_Api ) );}
}*PTTerminalInfo_Api,TTerminalInfo_Api;


///////////////////////////////////////////////////////////////////////

//added by ydwu 2014.06.17 begin
/** 基本结构体 */
typedef struct tagTImComm_Api
{
	u32 dwErrID;                                                ///< 错误ID
	u32 dwHandle;                                             ///< 句柄　
	u32 dwReserved;                                          ///< 预留扩展用
	s8  achReserved[ KMTAPI_BUF_256_LEN+1 ];	///< 预留扩展用
public:
	tagTImComm_Api() { memset( this, 0, sizeof(tagTImComm_Api) ); }
}*PTTImComm_Api, TImComm_Api;

/** 用户登录 */
typedef struct tagTImUserLogin_Api
{
	s8   achNO[ KMTAPI_IM_MAX_ID_LEN + 1];                                    ///< 登录口号(格式为"用户名@域名")
	s8   achUserPwd[KMTAPI_MAX_MT_PWD_LEN + 1];                        ///< 密码
	s8   achStunAddr[KMTAPI_IM_MAX_ADDRESS_LEN + 1];                 ///< stun server ip address
	s8   achDefaultSaveDir[KMTAPI_IM_MAX_PATH_LEN + 1];               ///< default save directory
	s8   achEnterpriseName[KMTAPI_IM_ENTERPRISE_NAME_LEN + 1]; ///< 企业名称(用于创建组织架构聊天室)
	s8   achPicSaveDir[KMTAPI_IM_MAX_PATH_LEN + 1];                      ///< 保存截图的路径(绝对路径)
	s8   achResource[KMTAPI_IM_MAX_RESOURCE_LEN + 1];                ///< 资源            
	s8   achSock5Username[KMTAPI_IM_SOCK5_USERNAME_LEN + 1]; ///< sock5用户名
	s8   achSock5Password[KMTAPI_IM_SOCK5_PASSWORD_LEN + 1];  ///< sock5密码
	s8   achConfigPath[KMTAPI_IM_MAX_PATH_LEN + 1];                     ///< 保存用户配置的路径
	s8   achSock5Addr[KMTAPI_IM_SOCK5_ADDR_NAME_LEN + 1];       ///< sock5地址
	u32 dwImIP;                                                                                   ///< 服务器ip地址
	u16 wPort;                                                                                      ///< 服务器端口
	u16 wStunPort;                                                                               ///< stun port
	u16 wSock5Port;                                                                             ///< sock5端口
	u8  byPwdLen;                                                                                ///< 密码长度	
	BOOL32 bFileShareEnable;                                                             ///< 是否启用xmpp文件传输
	BOOL32 bAudioCapability;                                                             ///< 是否有音频能力(硬件)
	BOOL32 bVideoCapability;                                                             ///< 是否有视频能力(硬件)
	BOOL32 bInstant;                                                                          ///< 是否立即登录
	BOOL32 bUseSock5;                                                                      ///< 是否启用sock5代理
	BOOL32 bCompression;                                                                 ///< 是否使用zlib压缩流	
public:
	tagTImUserLogin_Api() 
	{ 
		memset( this, 0, sizeof(tagTImUserLogin_Api) ); 
		bAudioCapability = TRUE;                             ///< 默认终端都有音频、视频能力
		bVideoCapability = TRUE;
		bInstant         = TRUE;
	}
}*PTImUserLogin_Api, TImUserLogin_Api;


/** 用户自定义信息 */
typedef struct tagTImSelfDefInfo_Api
{ 
	s8 achNO[ KMTAPI_IM_MAX_ID_LEN + 1];                            ///< 用户唯一标识
	s8 achNickName[KMTAPI_MAX_DEV_TYPE_NAME_LEN + 1]; ///< 用户昵称	
	u16 wPictureIndex;						                                        ///< 个人图像序号	
	BOOL32  bCustomePic;                                                         ///< 是否使用自定义头像
public:
	tagTImSelfDefInfo_Api() { memset( this, 0, sizeof(tagTImSelfDefInfo_Api) ); }
}*PTImSelfDefInfo_Api, TImSelfDefInfo_Api;

/** 用户自定义图片 */
typedef struct tagTImSelfDefPic_Api
{
	u32   dwCustomPicSize;                                                                      ///< 使用的自定义头像数据大小
	s8    abyCustomPicData[KMTAPI_IM_MAX_HEAD_PORTRAIT_LEN + 1]; ///< 自定义头像数据
public:
	tagTImSelfDefPic_Api() { memset( this, 0, sizeof(tagTImSelfDefPic_Api) ); }
}*PTImSelfDefPic_Api, TImSelfDefPic_Api;

/** 组信息 */
typedef struct tagTImGroupInfo_Api
{
	s8 achGroupSn[KMTAPI_IM_MAX_U64STRING_LEN + 1];           ///< 用户组序号
	s8 achGroupName[KMTAPI_IM_MAX_GROUPNAME_LEN + 1];  ///< 用户组名称
	s8 achParentGroupSn[KMTAPI_IM_MAX_U64STRING_LEN + 1]; ///< 父组序号
	u16 wGroupLevel;                                                                    ///< 组的层级
public:
	tagTImGroupInfo_Api() { memset( this, 0, sizeof(tagTImGroupInfo_Api) ); }
}*PTImGroupInfo_Api, TImGroupInfo_Api;

/** 组列表信息 */
typedef struct tagTImGroupList_Api
{
	u32 dwArraySize;                                                                                ///< 列表个数
	TImGroupInfo_Api atArray[KMTAPI_IM_MAX_GROUPINFO_LIST_LEN]; ///< 列表信息
public:
	tagTImGroupList_Api() { memset( this, 0, sizeof(tagTImGroupList_Api) ); }
}*PTImGroupList_Api, TImGroupList_Api;

/** 序列号 */
typedef struct tagTImSn_Api 
{
	s8 achSn[KMTAPI_IM_MAX_U64STRING_LEN + 1];  ///<　序列号
public:
	tagTImSn_Api() { memset( this, 0, sizeof(tagTImSn_Api) ); }
}*PTImSn_Api, TImSn_Api;

/** 移动成员信息 */
typedef struct tagTImMoveMember_Api
{
	s8 achMemberSn[KMTAPI_IM_MAX_U64STRING_LEN + 1];               ///< 成员序号
	s8 achOldGroupSn[KMTAPI_IM_MAX_U64STRING_LEN + 1];             ///< 老的组序列号
	s8 achNewGroupSn[KMTAPI_IM_MAX_U64STRING_LEN + 1];            ///< 新的组序列号
public:
	tagTImMoveMember_Api() { memset( this, 0, sizeof(tagTImMoveMember_Api) ); }
}*PTImMoveMember_Api, TImMoveMember_Api;

/** 用户状态 */
typedef struct tagTImUserState_Api
{
	s8 achNO[ KMTAPI_IM_MAX_ID_LEN + 1];	                     ///< 用户唯一标识
	EmMtOnlineState_Api emState;                                     ///< 用户状态
public:
	tagTImUserState_Api() 
	{ 
		memset( this, 0, sizeof(tagTImUserState_Api) ); 
		emState = EM_STATE_OFFLINE_Api;                            
	}
}*PTImUserState_Api, TImUserState_Api;

/** 设置自己的状态 */
typedef struct tagTImSetUserState_Api
{
	s8 achNO[ KMTAPI_IM_MAX_ID_LEN + 1];                    ///< 用户唯一标识
	EmMtOnlineState_Api emState;                                    ///< 用户状态
	BOOL32            bStateValid;                                         ///< 用户状态是否有效
	BOOL32            bGkConnected;                                   ///< 是否连上GK
	BOOL32            bGkConnectedValid;                           ///< GK连接状态是否有效
public:
	tagTImSetUserState_Api() 
	{ 
		memset( this, 0, sizeof(tagTImSetUserState_Api) ); 
		emState            = EM_STATE_OFFLINE_Api;
		bGkConnected      = FALSE;                          ///< 默认没有连上GK
		bStateValid       = TRUE;
		bGkConnectedValid = TRUE;
	}
}*PTImSetUserState_Api, TImSetUserState_Api;

/** 设备在线状态 */
typedef struct tagTDeviceOnlineState_Api
{
	s8 achNO[ KMTAPI_IM_MAX_ID_LEN + 1];	 ///< 用户唯一标识
	EmMtImTerminalType_Api emDeviceType; ///< 设备类型
	EmMtOnlineState_Api emState;                 ///< 在线状态
	EmMtOnlineState_Api emMaxState;          ///< 最高级别在线状态	
	BOOL32 bSelf;                                          ///< 是否自已
	BOOL32 bFirst;                                         ///< 是否第一次状态改变(例如第一次登录的状态改变)
	BOOL32 bFileShare;                                  ///< P2P文件传输能力
	BOOL32 bAudioCapability;                       ///< 音频能力
	BOOL32 bVideoCapability;                       ///< 视频能力
	BOOL32 bGkConnected;                          ///< 连上GK否
	BOOL32 bMaxAudio;                               ///< 音频可呼叫(至少有一终端既连上GK又有音频能力)
	BOOL32 bMaxVideo;                               ///< 视频可呼叫(至少有一终端既连上GK又有音频能力)
	BOOL32 bLoginBeforeMe;                       ///< 是否在自己之前登录(依赖于bFirst为TRUE, 其他时候忽略不计)
public:
	tagTDeviceOnlineState_Api() 
	{ 
		memset( this, 0, sizeof(tagTDeviceOnlineState_Api) ); 
		emState = EM_STATE_OFFLINE_Api;
		emMaxState = EM_STATE_OFFLINE_Api;
	}
}*PDeviceOnlineState_Api, TDeviceOnlineState_Api;

/** 用户状态列表 */
typedef struct tagTImUserStateList_Api
{
	u32 dwArraySize;                                                                                   ///< 列表个数
	TImUserState_Api atArray[KMTAPI_IM_MAX_ONLINESTATE_LIST_NUM]; ///< 列表信息
public:
	tagTImUserStateList_Api() { memset( this, 0, sizeof(tagTImUserStateList_Api) ); }
}*PTImUserStateList_Api, TImUserStateList_Api;

/** 用户所在的终端状态 */
typedef struct tagTSubState_Api
{
	EmMtImTerminalType_Api  emMtType; ///< 用户所在的终端类型
	EmMtOnlineState_Api     emMtState;    ///< 用户在该终端类型上的状态	
	BOOL32 bAudioCapability;                    ///< 音频能力(硬件)
	BOOL32 bVideoCapability;                    ///< 视频能力(硬件)
	BOOL32 bGkConnected;                       ///< 是否连上GK	
public:
	tagTSubState_Api()
	{
		memset( this, 0, sizeof(tagTSubState_Api) );
		emMtState = EM_STATE_OFFLINE_Api;
		bAudioCapability = FALSE;
		bVideoCapability = FALSE;
		bGkConnected = FALSE;
	}
}*PTSubState_Api, TSubState_Api;

/** 用户状态( 带上4种终端类型 ) */
typedef struct tagTImUserStateEx_Api
{
	s8                    achNO[ KMTAPI_IM_MAX_ID_LEN + 1];	      ///< 用户唯一标识
	EmMtOnlineState_Api   emState;                                         ///< 用户状态(最高状态)
	BOOL32                bMaxAudio;                                             ///< 既有音频能力，又连上GK
	BOOL32                bMaxVideo;                                             ///< 既有视频能力，又连上GK
	u32					  dwStateCount;                                           ///< 状态个数
	TSubState_Api         atMtState[KMTAPI_IM_MAX_MT_TYPE]; ///< tl, tp, td, ts状态
public:
	tagTImUserStateEx_Api() 
	{ 
		memset( this, 0, sizeof(tagTImUserStateEx_Api) ); 
		emState = EM_STATE_OFFLINE_Api;
		bMaxAudio = FALSE;
		bMaxVideo = FALSE;
	}
}*PTImUserStateEx_Api, TImUserStateEx_Api;

/** 用户状态列表( 带上终端类型 ) */
typedef struct tagTImUserStateListEx_Api
{
	u32 dwArraySize;                                                                                      ///< 列表个数
	TImUserStateEx_Api atArray[KMTAPI_IM_MAX_ONLINESTATE_LIST_NUM]; ///< 列表信息
public:
	tagTImUserStateListEx_Api() { memset( this, 0, sizeof(tagTImUserStateListEx_Api) ); }
}*PTImUserStateListEx_Api, TImUserStateListEx_Api;

/** 点对点聊天内容类 */
typedef struct tagTImChatBuf_Api
{
	u16 wMsgLen;                                                                               ///< 消息长度
	s8  achMsgBody[KMTAPI_IM_MAX_SENDMESSAGE_BUF_LEN + 1]; ///< 消息体
public:
	tagTImChatBuf_Api() { memset( this, 0, sizeof(tagTImChatBuf_Api) ); }
}*PTImChatBuf_Api, TImChatBuf_Api;

/** 点对点聊天消息 */
typedef struct tagTImP2PChatMessage_Api
{
	s8 achDstNO[ KMTAPI_IM_MAX_ID_LEN + 1];    ///< 用户唯一标识
	s8 achSrcNO[ KMTAPI_IM_MAX_ID_LEN + 1];    ///< 用户唯一标识
	EmMtImTerminalType_Api emImMtType;          ///< 消息发送者终端类型
	u32  dwContextId;                                            ///< 聊天消息用户自定义数据
	TImChatBuf_Api tMessageBuf;                         ///< 消息体
    s8 achMsgID[KMTAPI_BUF_32_LEN+1];                           //消息Id
public:
	tagTImP2PChatMessage_Api() { memset( this, 0, sizeof(tagTImP2PChatMessage_Api) ); }
}*PTImP2PChatMessage_Api, TImP2PChatMessage_Api;

/** ID */
typedef struct tagTImNO_Api
{
	s8 achNO[ KMTAPI_IM_MAX_ID_LEN + 1];       ///< 邮箱id
public:
	tagTImNO_Api() { memset( this, 0, sizeof(tagTImNO_Api) ); }
}*PTImNO_Api, TImNO_Api;

/** ID列表 */
typedef struct tagTImNOList_Api
{
	u32 dwArraySize;                                                            ///< 列表个数
	TImNO_Api atArray[KMTAPI_IM_MAX_USER_LIST_NUM]; ///< 列表信息
public:
	tagTImNOList_Api() { memset( this, 0, sizeof(tagTImNOList_Api) ); }
}*PTImNOList_Api, TImNOList_Api;


/** Room ID */
typedef struct tagTRoomId_Api
{
	s8 achRoomId[KMTAPI_IM_MAX_CHATROOM_ID_LEN + 1]; ///< RoomID
public:
	tagTRoomId_Api(){ memset( this, 0, sizeof(*this) ); }
}*PTRoomId_Api, TRoomId_Api;

/** 多人聊天信息结构体 */
typedef struct tagTImMultiChatCreateInfo_Api
{
	s8 achChatName[KMTAPI_IM_MAX_MULTI_CHAT_NAME_LEN + 1]; ///< 多人聊天会话名称(可不填); 
	s8 achConfE164[KMTAPI_MAX_CONF_E164_LEN + 1];                      ///< 会议的E164号，当EmMultiChatType为会议类型时才有意义
	s8 achRoomId[KMTAPI_IM_MAX_CHATROOM_ID_LEN + 1];             ///< 群聊室的ID(用在下一次上线确定是否为相同的聊天室)
	s8 achInviterNO[ KMTAPI_IM_MAX_ID_LEN + 1];                             ///< 邀请人的ID
	u32 dwSessionID;                                                                            ///< 会话ID
	u32 dwClientID;                                                                              ///< 创建多人会话时，客户端指定的唯一标志	
	BOOL32  bPersistent;                                                                      ///< 是否固定群
	BOOL32  bOwner;                                                                           ///< 是否群的创建人，
	EmMtMultiChatType_Api emMultiChatType;                                   ///< 多人聊天会话, 普通类型，会议类型....
public:
	tagTImMultiChatCreateInfo_Api() 
	{ memset( this, 0, sizeof(tagTImMultiChatCreateInfo_Api) ); emMultiChatType = EM_MULTICHAT_NORMAL_Api; }
}*PTImMultiChatCreateInfo_Api, TImMultiChatCreateInfo_Api;

/** 多人聊天增加成员结构体 */
typedef struct tagTImMultiChatMemberInfo_Api
{
	u32 dwSessionID;
	TImNOList_Api tNOList;                  ///< 要添加的多人聊天的成员  	
	TRoomId_Api tRoomId;                    ///< 可选的，room id
public:
	tagTImMultiChatMemberInfo_Api() { memset( this, 0, sizeof(tagTImMultiChatMemberInfo_Api) ); }
}*PTImMultiChatMemberInfo_Api, TImMultiChatMemberInfo_Api;

/** 多人聊天增加成员结构体Ex */
typedef struct tagTImMultiChatMemberInfoEx_Api
{
	u32   dwSessionID;
	s8    achNO[ KMTAPI_IM_MAX_ID_LEN + 1]; ///< 邮箱id
	BOOL32  bOwner;                                        ///< 是否聊天室创建人
	BOOL32  bSelf;                                             ///< 是否自己
	EmMtImTerminalType_Api  emMtType;        ///< 终端类型
	EmMtOnlineState_Api     emState;               ///< 终端状态
	EmMtOnlineState_Api     emMaxState;        ///< 最高级别在线状态
	TRoomId_Api             tRoomId;
public:
	tagTImMultiChatMemberInfoEx_Api() { memset( this, 0, sizeof(tagTImMultiChatMemberInfoEx_Api) ); }
}*PTImMultiChatMemberInfoEx_Api, TImMultiChatMemberInfoEx_Api;

/** 多人聊天消息 */
typedef struct tagTImMultiChatMessage_Api
{
	u32 dwSessionID;                                           ///< 多人聊天会话ID
	u32        dwContextId;                                   ///< 用户自定义数据
	s8 achSrcNO[ KMTAPI_IM_MAX_ID_LEN + 1]; ///< 消息源
	EmMtImTerminalType_Api emImMtType;       ///< 终端类型
	TImChatBuf_Api tMessageBuf;                       ///< 消息体  
	TRoomId_Api    tRoomId;                               ///< 可选的
    s8 achMsgID[KMTAPI_BUF_32_LEN+1];                        ///消息Id
public:
	tagTImMultiChatMessage_Api() { memset( this, 0, sizeof( tagTImMultiChatMessage_Api)); }
}*PTImMultiChatMessage_Api, TImMultiChatMessage_Api;

/** 多人聊天发送图片的唯一标志 */
typedef struct tagTMultiChatPicId_Api
{
	s8                      achNO[ KMTAPI_IM_MAX_ID_LEN + 1]; ///< 用户唯一标识
	s8                      achSid[KMTAPI_IM_MAX_SID_LEN + 1]; ///< sid
	u32                     dwSessionID;                                       ///< 多人聊天会话ID
	EmMtImTerminalType_Api  emDeviceType;                     ///< 设备类型
	TRoomId_Api             tRoomId;                                       ///< 可选的	
public:
	tagTMultiChatPicId_Api()
	{
		memset( this, 0, sizeof(*this) );
	}
}*PTTMultiChatPicId_Api, TMultiChatPicId_Api;

/** 在线状态缓存 */
typedef struct tagTDeviceOnlineStateCacheItem_Api
{
	u32 dwApp;                             ///< 缓存账号
	TDeviceOnlineState_Api tStatus;        ///< 缓存状态	
public:
	tagTDeviceOnlineStateCacheItem_Api()
	{
		dwApp = 0;
	}
}*PTDeviceOnlineStateCacheItem_Api, TDeviceOnlineStateCacheItem_Api;

/** 在线状态缓存列表 */
typedef struct tagTDeviceOnlineStateCacheList_Api
{
	u32                             dwArraySize;                                                                                           ///< 列表大小
	TDeviceOnlineStateCacheItem_Api atArray[KMTAPI_IM_MAX_MEMBER_STATUS_CACHE_NUM+1]; ///< 在线状态缓存列表
public:
	tagTDeviceOnlineStateCacheList_Api() { dwArraySize = 0; }
}*PTDeviceOnlineStateCacheList_Api, TDeviceOnlineStateCacheList_Api;

/** 文件共享请求 */
typedef struct tagTImFileShareReq_Api
{
	s8     achDestNO[ KMTAPI_IM_MAX_ID_LEN + 1];     ///< 对端的Im账号
	s8     achFilePath[KMTAPI_IM_SENDER_PATH_LEN + 1]; ///< 文件绝对路径名
	u32    nFileType;                                                       ///< 0: 文件夹；1：文件；2：图片
	u32    dwFileSize;                                                      ///< 文件大小(单位：字节)
	u32	   dwContextid;                                                 ///< 上层应用设置的上下文id
	BOOL32 bOverWrite;                                                 ///< 指定接收方是否要覆盖已有的同名文件
public:
	tagTImFileShareReq_Api() 
	{ 
		memset( this, 0, sizeof(tagTImFileShareReq_Api) ); 
		nFileType = 1;
	}
}*PTImFileShareReq_Api, TImFileShareReq_Api;

/** 文件共享offer请求 */
typedef struct tagTImFileShareOfferInfo_Api
{
	s8     achPeerNO[ KMTAPI_IM_MAX_ID_LEN + 1];       ///< 对端的Im账号
	s8     achFileName[KMTAPI_IM_RECV_PATH_LEN + 1]; ///< 文件名(不含路径)
	u32    nFileType;                                                         ///< 0: 文件夹；1：文件；2：图片
	u32    dwFileSize;                                                        ///< 文件大小(单位：字节)
	BOOL32 bSender;                                                       ///< 自己是否是发送者
public:
	tagTImFileShareOfferInfo_Api() 
	{ 
		memset( this, 0, sizeof(tagTImFileShareOfferInfo_Api) ); 
		nFileType = 1;
	}
}*PTImFileShareOfferInfo_Api, TImFileShareOfferInfo_Api;

/** 多人聊天文件共享请求 */
typedef struct tagTImGroupChatFileShareReq_Api
{
	s8     achFilePath[KMTAPI_IM_SENDER_PATH_LEN + 1]; ///< 文件绝对路径名
	u32    dwSessionID;                                                  ///< 多人聊天id
	u32    nFileType;                                                       ///< 0: 文件夹；1：文件；2：图片
	u32    dwFileSize;                                                      ///< 文件大小(单位：字节)
	u32		dwContextid;
	s8     achPicsessionid[ KMTAPI_BUF_32_LEN + 1 ];
	TRoomId_Api tRoomId;                                            ///< 可选的
public:
	tagTImGroupChatFileShareReq_Api() { memset( this, 0, sizeof(*this) ); nFileType = 1; }
}*PTImGroupChatFileShareReq_Api, TImGroupChatFileShareReq_Api;

/** 聊天室信息 */
typedef struct tagTImChatRoomInfo_Api
{
	u32     dwSessionID;
	s8      achChatName[KMTAPI_IM_MAX_MULTI_CHAT_NAME_LEN + 1];
	TRoomId_Api tRoomId;
public:
	tagTImChatRoomInfo_Api()
	{
		memset( this, 0, sizeof(*this) );
	}
}*PTImChatRoomInfo_Api, TImChatRoomInfo_Api;

/** 拒绝结构体 */
typedef struct tagTDeclineInfo_Api
{
	s8 achChatName[KMTAPI_IM_MAX_MULTI_CHAT_NAME_LEN + 1]; ///< 多人聊天会话名称(可不填); 
	s8 achRoomId[KMTAPI_IM_MAX_CHATROOM_ID_LEN + 1];             ///< 群聊室的ID(用在下一次上线确定是否为相同的聊天室)   
	s8 achDeclineNO[ KMTAPI_IM_MAX_ID_LEN + 1];                            ///< 拒绝人的ID
	EImDeclineReason_Api   emReason;                                                 ///< 拒绝的原因
public:
	tagTDeclineInfo_Api() 
	{ memset( this, 0, sizeof(tagTDeclineInfo_Api) ); }
}*PTDeclineInfo_Api, TDeclineInfo_Api;

/** 多人聊天成员列表(非进入聊天室内) */
typedef struct tagTImMultiChatRosterItem_Api
{
	s8      achNO[ KMTAPI_IM_MAX_ID_LEN + 1]; ///< 邮箱id
	BOOL32  bOwner;                                          ///< 是否聊天室创建人
	BOOL32  bSelf;                                               ///< 是否自己
public:
	tagTImMultiChatRosterItem_Api() { memset( this, 0, sizeof(tagTImMultiChatRosterItem_Api) ); }
}*PTImMultiChatRosterItem_Api, TImMultiChatRosterItem_Api;

/** 多人聊天RosterItem列表 */
typedef struct tagTImMultiChatRosterItemList_Api
{
	u32                            dwSessionId;                           
	u32                            dwArraySize;                              
	TImMultiChatRosterItem_Api     atArray[KMTAPI_IM_MAX_ROSTER_ITEMS_PER_BATCH];   
	TRoomId_Api                    tRoomId;

public:
	tagTImMultiChatRosterItemList_Api() { memset( this, 0, sizeof(tagTImMultiChatRosterItemList_Api) ); }
}*PTImMultiChatRosterItemList_Api, TImMultiChatRosterItemList_Api;

/** 输入状态 */
typedef struct tagTImCharState_Api
{
	s8 achPerrNO[ KMTAPI_IM_MAX_ID_LEN + 1]; ///< 对端的Im账号
	EmMtImTerminalType_Api emImMtType;         ///< 终端类型
	EmImCharState_Api       emCharState;             ///< 输入状态
public:
	tagTImCharState_Api() 
	{ 
		memset( this, 0, sizeof(tagTImCharState_Api) ); 
	}
}*PTImCharState_Api, TImCharState_Api;

/** 闪屏 */
typedef  struct  tagTImSplash_Api
{
	s8                     achPeerNO[ KMTAPI_IM_MAX_ID_LEN + 1];  ///< 对端的Im账号
	EmMtImTerminalType_Api emImMtType;                              ///< 终端类型
	u32                    dwSplashType;                                            ///< 闪屏类型
public:
	tagTImSplash_Api( ) { memset( this, 0, sizeof(*this) ); }
}*PTImSplash_Api, TImSplash_Api;

/** 自定义配置项 */
typedef struct tagTImCustomCfgItem_Api
{
	s8 achKey[KMTAPI_IM_MAX_CONFIG_KEY_LEN + 1];
	s8 achValue[KMTAPI_IM_MAX_CONFIG_VALUE_LEN + 1];	
public:
	tagTImCustomCfgItem_Api()
	{
		memset( this, 0, sizeof(*this) );
	}
}*PTImCustomCfgItem_Api, TImCustomCfgItem_Api;

/** 自定义配置 */
typedef struct tagTImCustomCfg_Api
{
	TImCustomCfgItem_Api atItems[KMTAPI_IM_MAX_CONFIG_ITEMS_PER_BATCH];
	u32 dwItemsCnt;     ///< 数组大小
	BOOL32 bGet;        ///< 是获取还是设置
public:
	tagTImCustomCfg_Api()
	{
		dwItemsCnt = 0;
		bGet       = FALSE;
	}
}*PTImCustomCfg_Api, TImCustomCfg_Api;

/** 设置是否屏蔽讨论组 */
typedef struct tagTImScreenChatroom_Api
{
	BOOL32  bScreen;                                      ///< 是否屏蔽( TRUE, 屏蔽； FALSE, 取消屏蔽 )
	s8    achRoomId[KMTAPI_IM_MAX_CHATROOM_ID_LEN + 1];   ///< 屏蔽的讨论组的room id(非session id)
public:
	tagTImScreenChatroom_Api()
	{
		memset( this, 0, sizeof(*this) );
	}
}*PTImScreenChatroom_Api, TImScreenChatroom_Api;

/*讨论组列表*/
typedef struct tagTImScreenedChatrooms_Api
{
	s8 aachRoomId[KMTAPI_BUF_32_LEN][KMTAPI_IM_MAX_CHATROOM_ID_LEN + 1];
	u8 byCnt;
public:
	tagTImScreenedChatrooms_Api()
	{
		memset( this, 0, sizeof(*this) );
	}
}*PTImScreenedChatrooms_Api, TImScreenedChatrooms_Api;

/** 设置是否屏蔽讨论组(真实屏蔽，无流量) */
typedef struct tagTImScreenChatroomR_Api
{
	BOOL32 bScreen;                                                                               ///< 是否屏蔽( TRUE, 屏蔽； FALSE, 取消屏蔽 )
	s8     aachRoomIds[KMTAPI_IM_MAX_CHATROOM_SCREEN_NUM][KMTAPI_IM_MAX_CHATROOM_ID_LEN + 1]; ///< 屏蔽的讨论组的room ids(非session ids)
	u32    dwCount;
public:
	tagTImScreenChatroomR_Api()
	{
		memset( this, 0, sizeof(*this) );
	}
}*PTImScreenChatroomR_Api, TImScreenChatroomR_Api;

/** 部门信息 */
typedef struct tagTMTWbParseKedaDept_Api
{
	u32 dwDepartmentId;                                                ///< 如“51”
	s8  achDepartmentName[KMTAPI_BUF_128_LEN + 1]; ///< 部门名字如“软件二部”
	s8  achFullPath[KMTAPI_BUF_1024_LEN+1];				  ///< 部门名称路径
	s8  achDeptPosition[KMTAPI_BUF_128_LEN+1];		      ///< 部门职位

public:
	tagTMTWbParseKedaDept_Api(){ memset(this, 0, sizeof(tagTMTWbParseKedaDept_Api) ); }
}*PTMTWbParseKedaDept_Api, TMTWbParseKedaDept_Api;

/** 部门信息列表 */
typedef struct tagTMTWbParseKedaDepts_Api
{
	u32						dwDeptNum;					                 	         	                                                     ///< 部门数目（一个人可能同时属于多个部门）
	TMTWbParseKedaDept_Api	atMtWbParseKedaDept[KMTAPI_IM_MAX_WBPARSEKEDADEPT_NUM];	 ///< 部门详细信息
public:
	tagTMTWbParseKedaDepts_Api(){ memset(this, 0, sizeof(tagTMTWbParseKedaDepts_Api) ); }
}*PTMTWbParseKedaDepts_Api, TMTWbParseKedaDepts_Api;

/** 用户信息，此结构体总字节数为1411，用OSP传送最多每次传15个 */
typedef struct tagTMTWbParse_Keda_EntUser_Api
{
	s8 achMoid[KMTAPI_BUF_64_LEN + 1];                     ///< 账号moid
	s8 achJid[KMTAPI_BUF_256_LEN + 1];                       ///< xmpp账号
	s8 achAccount[KMTAPI_BUF_128_LEN + 1];               ///< 自定义账号
	s8 achentMail[KMTAPI_BUF_128_LEN + 1];                ///< 邮箱,微博登录账号
	s8 achE164[KMTAPI_BUF_64_LEN + 1];                       ///< E164号
	s8 achMobileNum[KMTAPI_BUF_64_LEN + 1];            ///< 联系电话
	s8 achUserDomainMoid[KMTAPI_BUF_64_LEN + 1];    ///< 企业moid
	s8 achUserDomainName[KMTAPI_BUF_128_LEN + 1]; ///< 企业名
	s8 achDeviceGuid[KMTAPI_BUF_64_LEN + 1];		     ///< 终端GUID
	s8 achNuServerID [KMTAPI_BUF_64_LEN + 1];		     ///< 所属NU服务器ID
	s8 achDeviceType[KMTAPI_BUF_64_LEN + 1];		     ///< 终端类型
	BOOL32 bEnable;				                                         ///< 禁用/启用，0/1
	BOOL32 bLimited;                                                     ///< 是否受限
	s8 achentName[KMTAPI_BUF_128_LEN + 1];		  	    ///< 姓名
	s8 achBrief[KMTAPI_BUF_512_LEN + 1];     		        ///< 一句话介绍
	s8 achJobNum[KMTAPI_BUF_64_LEN + 1];			        ///< 用户编号/工号
	BOOL32 bMale;                                                        ///< 性别(1/0,男/女)
	s8 achextNum[KMTAPI_BUF_128_LEN + 1];               ///< 分机
	s8 achSeat[KMTAPI_BUF_256_LEN + 1];				        ///< 座位
	s8 achOfficeLocation[KMTAPI_BUF_512_LEN + 1];	    ///< 办公地址
	s8 achDateOfBirth[KMTAPI_BUF_64_LEN + 1];		    ///< 出生日期
	s8 achFax[KMTAPI_BUF_64_LEN + 1];				        ///< 传真
	s8 achRestrictUsedOn[KMTAPI_BUF_256_LEN + 1];	///< E164号限制登录的设备类型（列表）
	s8 achPortrait32[KMTAPI_BUF_256_LEN + 1];		        ///< 32位头像，实际地址
	s8 achPortrait40[KMTAPI_BUF_256_LEN + 1];  		    ///< 40位头像
	s8 achPortrait64[KMTAPI_BUF_256_LEN + 1];  		    ///< 64位头像
	s8 achPortrait128[KMTAPI_BUF_256_LEN + 1]; 		    ///< 128位头像
	s8 achPortrait256[KMTAPI_BUF_256_LEN + 1]; 		    ///< 128位头像
	BOOL32 bEnableWeibo;                                            ///< 微博权限(0/1,没有/有)
	BOOL32 bEnableMeetingsms;                                   ///< 发送会管短信权限(0/1,没有/有)
	BOOL32 bEnableMeeting;                                         ///< 会议管理权限(0/1,没有/有)
	BOOL32 bEnableHD;                                                 ///< 高清权限(0/1,没有/有)
    BOOL32 bEnableFullHD;                                           ///< 全高清权限(0/1,没有/有)
    BOOL32 bEnableUltraHD;                                         ///< 4K权限(0/1,没有/有)
	BOOL32 bEnableCall;                                                ///< 电话呼叫权限(0/1,没有/有)
	BOOL32 bEnableRoam;                                            ///< 漫游权限(0/1,没有/有)
	BOOL32 bEnableSatellite;                                         ///< 卫星线路权限(0/1,没有/有) 
	BOOL32 bEnableSatellitep2p;                                   ///< 卫星线路点对点会议权限(0/1,没有/有)
	BOOL32 bWeiboAdmin;   	                                       ///< 微博管理员权限(0/1,没有/有)
	BOOL32 bMeetingAdmin;   	                                   ///< 会议管理员权限(0/1,没有/有) 
	BOOL32 bEnableBMC;   	                                       ///< BMC权限(0/1,没有/有)  
	BOOL32 bEnableUMC;   	                                       ///< UMC权限(0/1,没有/有)
	BOOL32 bEnableDCS;                                              ///< DCS权限(0/1,没有/有)
	BOOL32 bEnableVRS;   	                                           ///< VRS权限(0/1,没有/有)
	BOOL32 bEnableNM;   		                                       ///< NM权限(0/1,没有/有)
	BOOL32 bEnableVenueMonitor;   	    	                   ///< 会场监控权限(0/1,没有/有)
	BOOL32 bDefaultUserDomainAdmin;   		               ///< 默认的用户域管理员(0/1,没有/有)
	BOOL32 bEnableOut;   		                                       ///< 出局权限(0/1,没有/有)
	BOOL32 bEnableIncoming;                                      ///< 入局权限(0/1,没有/有)
	BOOL32 bDCSAdmin;   		                                      ///< dcs管理员(0/1,没有/有)
	BOOL32 bVRSAdmin;   		                                      ///< vrs管理员(0/1,没有/有)
	BOOL32 bNMAdmin;   		                                      ///< nm管理员(0/1,没有/有)
	BOOL32 bEnableVideo;   		                                  ///< VRS子权限(录像)(0/1,没有/有)
	BOOL32 bEnableLive;   		                                      ///< VRS子权限(直播)(0/1,没有/有)
	BOOL32 bEnablePlay;   		                                      ///< VRS子权限(放像)(0/1,没有/有)
	BOOL32 bCMSApproval;   		                              ///< 会管会议审批权限(0/1,没有/有)	
	BOOL32 bEditName;   		                              ///< 修改姓名权限(0/1,没有/有)
    BOOL32 bEnableUnicat;                                   ///VRS子权限(点播)
    BOOL32 bEnableDownLoad;                                 ///VRS子权限(下载)
	TMTWbParseKedaDepts_Api  tMtWbParseKedaDepts; ///< 所在部门信息
public:
	tagTMTWbParse_Keda_EntUser_Api() { memset( this, 0, sizeof(tagTMTWbParse_Keda_EntUser_Api) ); }
}*PTMTWbParse_Keda_EntUser_Api, TMTWbParse_Keda_EntUser_Api;

/** 成员信息 */
typedef struct tagTImMemberInfo_Api
{
public:
	s8 achMemberSn[KMTAPI_IM_MAX_U64STRING_LEN + 1];     ///< 成员序列号
	s8 achGroupSn[KMTAPI_IM_MAX_U64STRING_LEN + 1];		 ///< 成员所在组的组序号
	s8 achMemberNO[ KMTAPI_IM_MAX_ID_LEN + 1];                ///< 成员的Xmpp Jid号(用户名@域名)
	s8 achMarkName[KMTAPI_MAX_DEV_TYPE_NAME_LEN + 1]; ///< 成员名称 
	EmMtMemberType_Api emMemberType;			                     ///< 成员类型
	u16 wBitRate;                                                                        ///< 呼叫码率
	TMTWbParse_Keda_EntUser_Api tWeiboInfo;                         ///< 联系人微博信息
	BOOL32  bNoQuery;                                                              ///< 是否不查Account	
public:
	tagTImMemberInfo_Api() { memset( this, 0, sizeof(tagTImMemberInfo_Api) ); }
}*PTImMemberInfo_Api, TImMemberInfo_Api;

/** 成员列表 */
typedef struct tagTImMemberList_Api
{
	u32 dwArraySize;                                                                                           ///< 成员个数
	TImMemberInfo_Api atArray[KMTAPI_IM_MAX_QUERY_USERONLINE_NUM]; ///< 成员列表
public:
	tagTImMemberList_Api() { memset( this, 0, sizeof(tagTImMemberList_Api) ); }
}*PTImMemberList_Api, TImMemberList_Api;

/** 好友的详细信息 */
typedef struct tagTImMemberFullInfo_Api
{
	TImMemberInfo_Api tMemberinfo;        ///< 好友基本信息 
	EmMtOnlineState_Api emMemberState; ///< 好友的状态信息
	BOOL32 bMaxAudio;                              ///< 既有音频能力，又连上GK
	BOOL32 bMaxVideo;                              ///< 既有视频能力，又连上GK
	u32			  dwStateCount;
	TSubState_Api atMtState[KMTAPI_IM_MAX_MT_TYPE]; ///< tl, tp, td, ts状态
public:
	tagTImMemberFullInfo_Api() { memset( this, 0, sizeof(tagTImMemberFullInfo_Api) ); }
}*PTImMemberFullInfo_Api, TImMemberFullInfo_Api;

typedef struct tagTPersistentChatroomItem_Api
{
	s8 achRoomId[KMTAPI_IM_MAX_CHATROOM_ID_LEN + 1];           ///< 聊天室的ID(用在下一次上线确定是否为相同的聊天室)
	s8 achChatName[KMTAPI_IM_MAX_MULTI_CHAT_NAME_LEN + 1];     ///< 聊天室名称

public:
	tagTPersistentChatroomItem_Api()
	{
		memset( this, 0, sizeof(*this) );
	}
}*PTPersistentChatroomItem_Api, TPersistentChatroomItem_Api;

/** 通知上次登录保存的固定讨论组信息或请求进入保存的讨论组 */
typedef struct tagTPersistentChatroomList_Api
{
	u32                         dwArraySize;
	TPersistentChatroomItem_Api atArray[KMTAPI_IM_MAX_PERSISTENT_CHATROOM_NUM];

public:
	tagTPersistentChatroomList_Api() { dwArraySize = 0; }
}*PTPersistentChatroomList_Api, TPersistentChatroomList_Api;

/** 批量添加的单个成员信息 */
typedef struct tagTBatchAddContactsItem_Api
{
public:
	s8 achMemberNO[ KMTAPI_IM_MAX_ID_LEN + 1];	       ///< 成员的Xmpp Jid号(用户名@域名)
	s8 achMarkName[KMTAPI_MAX_DEV_TYPE_NAME_LEN + 1];  ///< 成员名称 
	s8 achE164[KMTAPI_BUF_64_LEN + 1];                 ///< E164号
	EmMtMemberType_Api emMemberType;			 ///< 成员类型
	u16 wBitRate;                                ///< 呼叫码率

public:
	tagTBatchAddContactsItem_Api() { memset( this, 0, sizeof(tagTBatchAddContactsItem_Api) ); }
}*PTBatchAddContactsItem_Api, TBatchAddContactsItem_Api;

/** 批量添加联系人到一个组 */
typedef struct tagTBatchAddContacts_Api
{
	TBatchAddContactsItem_Api atBatchContacts[KMTAPI_IM_MAX_BATCH_USERS_NUM];   ///< 批量添加的联系人
	u32                       dwCount;                                          ///< 批量联系人的个数
	s8                        achDestGroupSn[KMTAPI_IM_MAX_U64STRING_LEN + 1];  ///< 添加到哪个组

public:
	tagTBatchAddContacts_Api()
	{
		memset( this, 0, sizeof(*this) );
	}
}*PTBatchAddContacts_Api, TBatchAddContacts_Api;

/** 批量删除联系人 */
typedef struct tagTBatchDelContacts_Api
{
public:
	TImSn_Api atBatchContacts[KMTAPI_IM_MAX_BATCH_USERS_NUM]; ///< 批量删除的联系人
	u32 dwCount;                                              ///< 批量联系人的个数

public:
	tagTBatchDelContacts_Api() { memset( this, 0, sizeof(tagTBatchDelContacts_Api) ); }
}*PTBatchDelContacts_Api, TBatchDelContacts_Api;

/** 批量移动联系人 */
typedef struct tagTBatchMoveContacts_Api
{
public:
	TImSn_Api atBatchContacts[KMTAPI_IM_MAX_BATCH_USERS_NUM]; ///< 批量移动的联系人
	u32 dwCount;                                              ///< 批量联系人的个数
	s8 achDestGroupSn[KMTAPI_IM_MAX_U64STRING_LEN + 1];       ///< 移动到哪个组

public:
	tagTBatchMoveContacts_Api() { memset( this, 0, sizeof(tagTBatchMoveContacts_Api) ); }
}*PTBatchMoveContacts_Api, TBatchMoveContacts_Api;

/** 微博错误信息结构体 */
typedef struct tagTRestErrorInfo_Api
{
	s8 achErrorInfo[KMTAPI_BUF_256_LEN + 1];  ///< 错误描述
	EmAPIType_Api  emApiType;                 ///< 对应的api 类型
	u32      dwErrorID;                       ///< 错误码
	u32      dwNackEventId;                   ///< 对应的nack event id
	u32      dwParamCount;
	u32      adwParams[4];                    ///< 保留的参数

public:
	tagTRestErrorInfo_Api(){ memset( this ,0 ,sizeof(tagTRestErrorInfo_Api) );}
}*PTRestErrorInfo_Api,TRestErrorInfo_Api;

/** 查找用户信息 */
typedef struct tagTMTSearchUserInfo_Api
{
	EmMtOperateUserInfo_Api	emOperateUser;
	u32						dwXmppNo;
	TImMemberInfo_Api	    tImMemberInfo;
public:
	tagTMTSearchUserInfo_Api()
	{
		dwXmppNo = 0;
		emOperateUser = MT_OPERATE_USER_ADD_Api;
	}
}*PTMTSearchUserInfo_Api, TMTSearchUserInfo_Api;

/** 好友信息 */
typedef struct tagTFriendConferenceInfo_Api
{
	s8 achPeerId[ KMTAPI_IM_MAX_ID_LEN + 1]; 
	s8 achConfE164[KMTAPI_MAX_CONF_E164_LEN + 1];         ///< 会议E164号
	s8 achRoomId[KMTAPI_IM_MAX_CHATROOM_ID_LEN + 1];      ///< 会议对应的Im讨论组id
	s8 achChatName[KMTAPI_IM_MAX_MULTI_CHAT_NAME_LEN + 1];///< 会议名称

	EmMtImTerminalType_Api emPeerType;                    ///< 好友终端类型

	tagTFriendConferenceInfo_Api()
	{
		memset( this, 0, sizeof(*this) );
	}
}*PTFriendConferenceInfo_Api, TFriendConferenceInfo_Api;

/** 自定义 */
typedef struct tagTImSelfDef_Api
{
	TImSelfDefInfo_Api tImSelfDefInfo_Api;
	TImSelfDefPic_Api tImSelfDefPic_Api;
public:
	tagTImSelfDef_Api() { memset( this, 0, sizeof(tagTImSelfDef_Api) ); }

}*PTImSelfDef_Api, TImSelfDef_Api;

/** 接受文件 */
typedef struct tagTImAcceptFile_Api
{
	BOOL32 bRecv;
	BOOL32 bSetSavePath;
	s8 achPath[KMTAPI_MAX_PATH_FILE_NAME_LEN + 1];

public:
	tagTImAcceptFile_Api() { memset( this, 0, sizeof(tagTImAcceptFile_Api) ); }
}*PTImAcceptFile_Api, TImAcceptFile_Api;

/** 聊天室图片 */
typedef struct tagTImChatroomPicture_Api
{
	TMultiChatPicId_Api tMultiChatPicId_Api;
	s8 achPath[KMTAPI_MAX_PATH_FILE_NAME_LEN + 1];
public:
	tagTImChatroomPicture_Api() { memset( this, 0, sizeof(tagTImChatroomPicture_Api) ); }

}*PTImChatroomPicture_Api, TImChatroomPicture_Api;

typedef struct tagTMTAccountManagerSystem_Api
{
	s8 achusername[ KMTAPI_IM_MAX_ID_LEN + 1];           ///< 账号，可以是E164号码或邮箱
	s8 achpassword[KMTAPI_BUF_64_LEN + 1];               ///< 密码
	s8 achmobileNum[KMTAPI_MT_MAX_TELEPHONE_LEN + 1];    ///< 联系电话，可选
	s8 achextNum[KMTAPI_BUF_64_LEN + 1];             ///< 分机，可选
	s8 achseat[KMTAPI_BUF_64_LEN + 1];               ///< 座位号，可选
	s8 achbrief[KMTAPI_IM_MAX_BRIEF_LEN + 1];        ///< 一句话介绍, 支持70个汉字，可选
	s8 achposition[KMTAPI_BUF_64_LEN + 1];           ///< 职位，可选
	s8 achName[KMTAPI_IM_REST_COMMON_BUF_LEN + 1];   ///< 姓名，可选
	s8 achAPIAddr[KMTAPI_BUF_64_LEN + 1];			 ///< API地址
	s8 achEmail[KMTAPI_BUF_128_LEN + 1];			 ///< 邮箱

	BOOL32 bMale;                                    ///< 性别，可选
	BOOL32 bIsAdding;

	u32   dwBitMask;
	u32   dwContextId;                               ///< 用户自定义的参数
public:
	tagTMTAccountManagerSystem_Api() { memset( this, 0, sizeof(tagTMTAccountManagerSystem_Api) );  }
}*PTMTAccountManagerSystem_Api, TMTAccountManagerSystem_Api;

/** 文件传输 */
typedef struct tagTImFileShareProgress_Api
{
	s8     achCurFileName[KMTAPI_IM_RECV_PATH_LEN + 1];  ///< 当前传输的文件名(不含路径)
	u32    dwPercent;                                   ///< 传输进度0~100
	u32    dwTransferSize;                              ///< 已经传输大小
	u32    dwTrasferRate;                               ///< 传输速率
public:
	tagTImFileShareProgress_Api() { memset( this, 0, sizeof(tagTImFileShareProgress_Api) ); }
}*PTImFileShareProgress_Api, TImFileShareProgress_Api;


typedef struct tagTChatroomMemberCacheItem_Api
{
	EmImBatchMsgType_Api emEventId; ///< 事件id  
	u32 dwApp;                                         ///< 账号id
	TImMultiChatMemberInfoEx_Api tInfo; ///< 数据

public:
	tagTChatroomMemberCacheItem_Api()
	{
		dwApp     = 0;
	}
}*PTChatroomMemberCacheItem_Api, TChatroomMemberCacheItem_Api;

/** 批量通知讨论组成员消息 */
typedef struct tagTChatroomMemberCacheList_Api
{
	u32 dwArraySize;
	TChatroomMemberCacheItem_Api atArray[KMTAPI_IM_MAX_CHATROOM_MEMBER_CACHE_ARRAY_SIZE];
public:
	tagTChatroomMemberCacheList_Api() { dwArraySize = 0; }
}*PTChatroomMemberCacheList_Api, TChatroomMemberCacheList_Api;
//added by ydwu 2014.06.17 end


//by-qwchan-part-mtmeetingctrl begin

typedef struct tagTMTCreateConfMember_Api
{
	s8	achName[ KMTAPI_BUF_128_LEN+1 ];        //平台过来 填的是一般都是 164号 和 别名
	s8	achAccount[ KMTAPI_BUF_64_LEN+1 ];      //平台过来填的一般都是moid
	EmMtAddrType_Api emAccountType;             ///类型
public:
	tagTMTCreateConfMember_Api(){memset( this, 0, sizeof(tagTMTCreateConfMember_Api) ); }
}*PTMTCreateConfMember_Api, TMTCreateConfMember_Api;

typedef struct tagTMTInviteMember_Api
{
    s8	achName[ KMTAPI_BUF_128_LEN+1 ];        //平台过来 填的是一般都是 164号 和 别名
    s8	achAccount[ KMTAPI_BUF_64_LEN+1 ];      //平台过来填的一般都是moid
    EmMtAddrType_Api emAccountType;             //帐号类型
    EmConfProtocol_Api emProtocol;              //呼叫协议 323 SIP
public:
    tagTMTInviteMember_Api(){memset( this, 0, sizeof(tagTMTInviteMember_Api) ); }
}*PTMTInviteMember_Api, TMTInviteMember_Api;

typedef struct tagTMTVideoFormatList_Api
{
	EmVidFormat_Api		emVideoFormat;
	EmH264Profile_Api	emVideoProfile;
	EmMtResolution_Api	emResolution;	
	u32					dwFrame;
	u32					dwRate;

public:
	tagTMTVideoFormatList_Api()
	{
		memset( this, 0, sizeof(tagTMTVideoFormatList_Api) ); 
		emVideoProfile = emBaseline_Api;
	}
}*PTMTVideoFormatList_Api, TMTVideoFormatList_Api;

typedef struct tagTMTAudioFormatList_Api
{
	EmAudFormat_Api		emAudioFormat;
	EmAacChnlNum_Api	emAaccnnlNum;

public:
	tagTMTAudioFormatList_Api(){memset( this, 0, sizeof(tagTMTAudioFormatList_Api) ); }
}*PTMTAudioFormatList_Api, TMTAudioFormatList_Api;

/** 主播设置 */
typedef struct tagTMTCreateConfMultiCast_Api
{
	s8 achMulticastAddr[KMTAPI_BUF_64_LEN+1];    ///<地址
	BOOL32 bEnable;                              ///<是否激活:1是，0否
	u32 dwPort;                                  ///<端口
public:
	tagTMTCreateConfMultiCast_Api() { memset( this, 0, sizeof(tagTMTCreateConfMultiCast_Api) ); }
}*PTMTCreateConfMultiCast_Api, TMTCreateConfMultiCast_Api;

typedef struct tagTMTConfPollInfo_Api
{
    BOOL32 bEnable;   ///<是否启用：1是0否
    EmPollMode_Api emMode;  ///<轮询模式 1-仅图像轮询 3-音视频轮询
    u32 dwNum;        ///<轮询次数，0无限次轮询
    u32 dwInterval;   ///<轮询间隔时间(秒)
    u32 dwMemberCount;///<成员个数
    TMTCreateConfMember_Api atMemberList[KMTAPI_COUNT_100];///<轮询成员列表
public:
    tagTMTConfPollInfo_Api() { memset( this, 0, sizeof(tagTMTConfPollInfo_Api) ); }
}*PTMTConfPollInfo_Api, TMTConfPollInfo_Api;
/** 画面合成成员列表 */
typedef struct tagTMTTemplateVmpMember_Api
{
	s8 achName[KMTAPI_BUF_128_LEN+1];      ///<账号名称
	s8	achAccount[ KMTAPI_BUF_64_LEN+1 ]; ///<账号
	EmMtAddrType_Api emAccountType;        ///<帐号类型
	EmMtVMPMmbType_Api emFollowType;       ///<跟随类型
	u32 dwIndex;                                            ///<在画画合成中的位置
    TMTConfPollInfo_Api tPoll;            ///<轮询设置
public:
	tagTMTTemplateVmpMember_Api() { memset( this, 0, sizeof(tagTMTTemplateVmpMember_Api) ); }
}*PTMTTemplateVmpMember_Api, TMTTemplateVmpMember_Api;

/** 画面合成设置 */
typedef struct tagTMTCreateConfVmp_Api
{
	BOOL32 bEnable;          ///<是否启用
	EmMtVmpStyle_Api emStyle;///<风格
	BOOL32 bVoiceHint;       ///<是否识别声音来源:1是0否
	BOOL32 bShowMTName;      ///<是否显示别名：1是0否
	BOOL32 bIsBroadcast;     ///<是否广播

	u32 dwMemberCount;       ///<成员个数
	TMTTemplateVmpMember_Api atMemberList[KMTAPI_COUNT_192];///<画面合成成员列表
public:
	tagTMTCreateConfVmp_Api() { memset( this, 0, sizeof(tagTMTCreateConfVmp_Api) ); }
}*PTMTCreateConfVmp_Api, TMTCreateConfVmp_Api;

/**轮询设置  */
typedef struct tagTMTCreateConfPoll_Api
{
	BOOL32 bEnable;   ///<是否启用：1是0否
	u32 dwNum;        ///<轮询次数，0无限次轮询
	u32 dwInterval;   ///<轮询间隔时间(秒)
	BOOL32 bSpeaker;  ///<是否发言:1是，0否

	u32 dwMemberCount;///<成员个数
	TMTCreateConfMember_Api atMemberList[KMTAPI_COUNT_192];///<轮询成员列表
public:
	tagTMTCreateConfPoll_Api() { memset( this, 0, sizeof(tagTMTCreateConfPoll_Api) ); }
}*PTMTCreateConfPoll_Api, TMTCreateConfPoll_Api;

typedef struct tagTMTDualFormatList_Api
{
	u32		dwFrame;							    ///< 帧率
	EmMtResolution_Api emResolution;				///< 分辨率
	EmVidFormat_Api	   emVideoFormat;				///< 视频格式

public:
	tagTMTDualFormatList_Api(){ memset( this ,0 ,sizeof(tagTMTDualFormatList_Api) );}

}*PTMTDualFormatList_Api, TMTDualFormatList_Api;

typedef struct tagTMTCreateRecordRecord_Api
{
	BOOL32 bDoubleFlow;			    ///< 是否设置双流，1是，0否
	BOOL32 bEnable;				    ///< 是否启用录像设置，1是，0否
	BOOL32 bMain;					///< 是否设置主流，1是，0否
	BOOL32 bPublish;				///< 是否发布录像，1是，0否
public:
	tagTMTCreateRecordRecord_Api(){ memset( this ,0 ,sizeof(tagTMTCreateRecordRecord_Api) );}

}*PTMTCreateRecordRecord_Api, TMTCreateRecordRecord_Api;

typedef struct tagTMTCreateConfSatellite_Api
{
	BOOL32 bEnable;				///< 是否启用卫星设置，1是，0否
	s8  achMulticastAddr[ KMTAPI_BUF_64_LEN+1 ];		///< 卫星IP地址
	u32 dwPort;					///< 端口
	u32 dwReturnNum;			///< 回传数
public:
	tagTMTCreateConfSatellite_Api(){ memset( this ,0 ,sizeof(tagTMTCreateConfSatellite_Api) );}

}*PTMTCreateConfSatellite_Api, TMTCreateConfSatellite_Api;

typedef struct tagTMTVrsAlias_Api
{
	EmVrsAliasType_Api    emRecAliasType;         ///< 录像机别名类型 0-初始值， 1-IP, 2-E164 平台依据类型获取对应的别名信息
	s8     achRecIpAddr[ KMTAPI_BUF_64_LEN+1 ];		///< 录像机ip
	s8	   achRecE164Addr[ KMTAPI_BUF_64_LEN+1 ];	///< 录像机别名E164

public:
	tagTMTVrsAlias_Api(){ memset( this ,0 ,sizeof(tagTMTVrsAlias_Api) );}

}*PTMTVrsAlias_Api, TMTVrsAlias_Api;

typedef struct tagTMTCreateAutoRecAttrb_Api  
{
	BOOL32 bAutoRec;			   //是否会议开启自动录像 0-不支持 1-支持
	EmRecordPubMode_Api  emPublishMode; //0-不发布 1-立即发布，新录播直播标志 2.-录像完毕之后发布，新录播发布标志 3-直播+发布
	BOOL32 bRecMainVideo;		   //是否录主格式码流(视频+音频)
	BOOL32 bRecdStream;			   //是否录双流(仅双流)
	TMTVrsAlias_Api tVrsAlias;	   //录像机别名信息

public:
	tagTMTCreateAutoRecAttrb_Api(){ memset( this ,0 ,sizeof(tagTMTCreateAutoRecAttrb_Api) );}

}*PTMTCreateAutoRecAttrb_Api, TMTCreateAutoRecAttrb_Api;


/**5.0 非标ras创会的参数  */
typedef struct tagTMtCreateConfParam_Api
{
	s8				                achName[ KMTAPI_BUF_128_LEN+1 ];        ///<会议名字
	u32				                dwDuration;                             ///<会议持续时长
	u32				                dwBitrate;                              ///<会议码率
	EmMtOpenMode_Api		        emMeetingSafe;                          ///<会议安全mode
	s8								achPassword[ KMTAPI_BUF_32_LEN+1 ];     ///<会议密码，如果为0，表示没有不需要密码
	EmEncryptArithmetic_Api			emEncryptedType;                        ///<会议加密方式
	s8								achEncryptedKey[ KMTAPI_BUF_32_LEN+1 ]; ///<会议秘钥
	EmMeetingSafeType_Api		    emMeetingType;                          ///<会议是否是 端口会议          
	EmClosedMeeting_Api             emClosedMeeting;                        ///<会议免打扰，1开启，0关闭
	EmVideoQuality_Api              emVideoQuality;                         ///<视频质量,0：质量优先；1：速度优先
	EmMtDualMode_Api                emDualMode;                             ///<双流权限
	BOOL32                          bInitMute;                              ///<初始化哑音：1是，0否
	BOOL32							bPublicMeeting;                         ///<是否是公共会议室

	/**音视频格式 */
	u32						        dwVideoCount;
	TMTVideoFormatList_Api          atVideoFormatList[KMTAPI_COUNT_16];
	u32						        dwAudioCount;
	TMTAudioFormatList_Api          atAudioFormatList[KMTAPI_COUNT_16];
	u32                             dwDualCount;
	TMTDualFormatList_Api           atDualFormatList[KMTAPI_COUNT_8];      ///< 双流频格式列表

	/**参会成员列表 */
	u32						        dwMemberCount;
	TMTCreateConfMember_Api         atMembers[KMTAPI_COUNT_192];   ///< 参会成员列表


	/**混音,画面合成参数 */
	EmMtMixType_Api		    emMixMode;                             ///< 混音方式 注:定制混音与语音激励不能同时开 
	u32                     dwMixMemberCount;                      ///< 定制混音 成员数
	TMTCreateConfMember_Api atMixMemberList[KMTAPI_COUNT_192];     ///< 制定混音时的混音成员列表
	TMTCreateConfVmp_Api    tVmp;                                  ///< 画面合成设置

	TMTCreateConfPoll_Api   tPoll;                                 ///< 轮询设置
	u32                     dwVipCount;
	TMTCreateConfMember_Api atVipList[KMTAPI_COUNT_192];           ///< vip成员列表


	TMTCreateConfMember_Api tSpeaker;   ///< 发言人
	TMTCreateConfMember_Api tAdmin;     ///< 管理方
	u32 dwCallTimes;                    ///< 呼叫次数
	u32 dwCallInterval;                 ///< 呼叫间隔(秒)
	BOOL32 bCallChase;                  ///< 是否追呼：1是，0否
	BOOL32 bVoiceInspireEnable;         ///< 是否开启语言激励：1是，0否
	EmRestCascadeMode_Api emCascadeMode;///< 级联模式,0简单级联，1合并级联
	BOOL32 bCascadeUpload;              ///< 是否级联上传:1是，0否
	BOOL32 bCascadeReturn;              ///< 是否级联回传:1是，0否
	u32 dwCascadeReturnPara;            ///< 级联回传带宽参数
	TMTCreateRecordRecord_Api      tRecord;                    ///< 录像设置 
	TMTCreateConfMultiCast_Api     tMultiCast;                 ///< 主播设置
	TMTCreateConfSatellite_Api	   tSatellite;                 ///<卫星会议设置
	u32 dwCallChaseMemberCount;
	TMTCreateConfMember_Api atCallChaseList[KMTAPI_COUNT_192]; ///< 追呼为是时的追呼成员列表

	//new
	u32					   dwMixVacInterval ;                       //语音激励敏感度
	BOOL32 				   bOneReforming;                           //是否归一重整     
	s8					   achConfE164[ KMTAPI_BUF_32_LEN+1 ];      //会议e164 、会管的预分配号码
	u32					   dwMeetingScale;                          ///< 会议规模,0：空，1：4方视频会议,2：8方视频会议,3：大型视频会议


public:
	tagTMtCreateConfParam_Api(){memset( this, 0, sizeof(tagTMtCreateConfParam_Api) ); }

}*PTMtCreateConfParam_Api, TMtCreateConfParam_Api;

/**  用于根据模板id获取详情 */
typedef struct tagTMTGetMixInfo_Api
{
	BOOL32			bEnable;			///< 是否开启混音1：是，0：否
	EmMtMixType_Api emMode;		        ///< 0-不混音，1-讨论开始，2-定制混音

	u32 dwMixMemberCount;
	TMTCreateConfMember_Api atMixMemberList[KMTAPI_COUNT_64]; ///< 混音列表
public:
	tagTMTGetMixInfo_Api(){ memset( this ,0 ,sizeof(tagTMTGetMixInfo_Api) );}
}*PTMTGetMixInfo_Api, TMTGetMixInfo_Api;

/**个人模板详情 */
typedef struct tagTMTPerTemplateInfo_Api
{
	u32				         dwTemplateid;
	s8				                achName[ KMTAPI_BUF_128_LEN+1 ];        ///<会议名字
	u32				                dwDuration;                             ///<会议持续时长
	u32				                dwBitrate;                              ///<会议码率
	EmMtOpenMode_Api		        emMeetingSafe;                          ///<会议安全mode
	s8								achPassword[ KMTAPI_BUF_32_LEN+1 ];     ///<会议密码，如果为0，表示没有不需要密码
	EmEncryptArithmetic_Api			emEncryptedType;                        ///<会议加密方式
	s8								achEncryptedKey[ KMTAPI_BUF_32_LEN+1 ]; ///<会议秘钥
	EmMeetingSafeType_Api		    emMeetingType;                          ///<会议是否是 端口会议          
	EmClosedMeeting_Api             emClosedMeeting;                        ///<会议免打扰，1开启，0关闭
	EmVideoQuality_Api              emVideoQuality;                         ///<视频质量,0：质量优先；1：速度优先
	EmMtDualMode_Api                emDualMode;                             ///<双流权限
	BOOL32                          bInitMute;                              ///< 初始化哑音：1是，0否
	BOOL32							bPublicMeeting;                   ///< 是否是公共会议室
    u32 dwMeetingScale;                                                   ///< 会议规模,0：空，1：4方视频会议,2：8方视频会议,3：大型视频会议
    u32 dwOneReforming;                                                 ///< 归一重整,0:关闭; 1:开启
    s8 achPresetedNumber[ KMTAPI_BUF_16_LEN ];        ///< 预分配会议号

	/**音视频格式 */
	u32						        dwVideoCount;
	TMTVideoFormatList_Api          atVideoFormatList[KMTAPI_COUNT_16];
	u32						        dwAudioCount;
	TMTAudioFormatList_Api          atAudioFormatList[KMTAPI_COUNT_16];
	u32                             dwDualCount;
	TMTDualFormatList_Api           atDualFormatList[KMTAPI_COUNT_8];      ///< 双流频格式列表

	/**参会成员列表 */
	u32						        dwMemberCount;
	TMTCreateConfMember_Api         atMembers[KMTAPI_COUNT_256];   ///< 参会成员列表


	/**混音,画面合成参数 */
	TMTGetMixInfo_Api		    tMixInfo;                             ///< 混音相关信息
	TMTCreateConfVmp_Api    tVmp;                                  ///< 画面合成设置

	TMTCreateConfPoll_Api   tPoll;                                 ///< 轮询设置
	u32                     dwVipCount;
	TMTCreateConfMember_Api atVipList[KMTAPI_COUNT_256];           ///< vip成员列表


	TMTCreateConfMember_Api tSpeaker;   ///< 发言人
	TMTCreateConfMember_Api tAdmin;     ///< 管理方
	u32 dwCallTimes;                    ///< 呼叫次数
	u32 dwCallInterval;                 ///< 呼叫间隔(秒)
	BOOL32 bCallChase;                  ///< 是否追呼：1是，0否
	BOOL32 bVoiceInspireEnable;         ///< 是否开启语言激励：1是，0否
    u32         dwVoiceInspireTime;         ///< 语音激励敏感度
	EmRestCascadeMode_Api emCascadeMode;///< 级联模式,0简单级联，1合并级联
	BOOL32 bCascadeUpload;              ///< 是否级联上传:1是，0否
	BOOL32 bCascadeReturn;              ///< 是否级联回传:1是，0否
	u32 dwCascadeReturnPara;            ///< 级联回传带宽参数
	TMTCreateRecordRecord_Api      tRecord;                    ///< 录像设置 
	TMTCreateConfMultiCast_Api     tMultiCast;                 ///< 主播设置
	TMTCreateConfSatellite_Api	   tSatellite;                 ///<卫星会议设置
	u32 dwCallChaseMemberCount;
	TMTCreateConfMember_Api atCallChaseList[KMTAPI_COUNT_128]; ///< 追呼为是时的追呼成员列表
	BOOL32						bEncryptedAuth;                         ///< 是否双向认证 0-关闭 1-开启

public:
	tagTMTPerTemplateInfo_Api(){memset( this, 0, sizeof(tagTMTPerTemplateInfo_Api) ); }
}*PTMTPerTemplateInfo_Api, TMTPerTemplateInfo_Api;


typedef struct tagTMTPerTemplateSimpleInfo_Api
{
	u32		dwTemplateid;						///< 个人模板ID
	s8		achName[ KMTAPI_BUF_128_LEN+1 ];    ///< 名称
	u32		dwDuration;							///< 会议时长，预留
	u32		dwBitrate;							///< 会议码率
	EmMtResolution_Api		emResolution;		///< 会议分辨率，各个类型的数据参照公共模板

public:
	tagTMTPerTemplateSimpleInfo_Api(){memset( this, 0, sizeof(tagTMTPerTemplateSimpleInfo_Api) ); }
}*PTMTPerTemplateSimpleInfo_Api, TMTPerTemplateSimpleInfo_Api;


typedef struct tagTMTPerTemplateDetail_Api
{
	TMTPerTemplateSimpleInfo_Api tPersonalTemplate;
	u32							dwCount;
	TMTCreateConfMember_Api		atMembers[KMTAPI_COUNT_256];

public:
	tagTMTPerTemplateDetail_Api(){memset( this, 0, sizeof(tagTMTPerTemplateDetail_Api) ); }
}*PTMTPerTemplateDetail_Api, TMTPerTemplateDetail_Api;

typedef struct tagTMTPerTemplateList_Api
{
	u32							dwCount;
	TMTPerTemplateDetail_Api	atPerTemplateDetail[KMTAPI_MG_MAX_TEMPLATE_LIST_NUM];

public:
	tagTMTPerTemplateList_Api(){memset( this, 0, sizeof(tagTMTPerTemplateList_Api) ); }
}*PTMTPerTemplateList_Api, TMTPerTemplateList_Api;


/** 创建会议通知 */
typedef struct tagTMTCreateMeetingNotify_Api
{
	u32		dwId;
	u32		dwNotifyMask;
	u32     dwTitleType;
public:
	tagTMTCreateMeetingNotify_Api(){memset( this, 0, sizeof(tagTMTCreateMeetingNotify_Api) ); }
}*PTMTCreateMeetingNotify_Api, TMTCreateMeetingNotify_Api;

/** 会议列表 */
typedef struct tagTMTMeetingList_Api
{
	s8			achStartDay[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];	    ///< 会议开始日期
	s8			achEndDay[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];		///< 会议结束日期
	BOOL32		bIsConfirm;									///< 是否确认参加
	u32			dwStart;									///< 会议的开始行
	u32			dwCount;									///< 获取的会议数
	u32			dwOrder;									///< 会议开始时间排序，0代表升序，1代表降序
public:
	tagTMTMeetingList_Api(){memset( this, 0, sizeof(tagTMTMeetingList_Api) ); }
}*PTMTMeetingList_Api, TMTMeetingList_Api;

/** TMTShortRoom_Api */
typedef struct tagTMTShortRoom_Api
{
	s32		nID;
	s8		achname[KMTAPI_MAX_CONF_NAME_LEN+1];
	s8		achRegionName[KMTAPI_MG_MAX_REGIONNAME_LEN+1];
public:
	tagTMTShortRoom_Api(){ memset( this ,0 ,sizeof(tagTMTShortRoom_Api) );}
}*PTMTShortRoom_Api,TMTShortRoom_Api;

/** TMTShortRooms_Api */
typedef struct tagTMTShortRooms_Api
{
	s32					nCount;
	TMTShortRoom_Api	atItems[KMTAPI_MG_MAX_SHORTROOMS_NUM];
public:
	tagTMTShortRooms_Api(){ memset( this ,0 ,sizeof(tagTMTShortRooms_Api) );}
}*PTMTShortRooms_Api,TMTShortRooms_Api;

/** TMTRoomIDs_Api */
typedef struct tagTMTRoomIDs_Api
{
	s32		nCount;
	s32		anItems[KMTAPI_MG_MAX_MEETING_ROOM_NUM];
public:
	tagTMTRoomIDs_Api(){ memset( this ,0 ,sizeof(tagTMTRoomIDs_Api) );}
}*PTMTRoomIDs_Api,TMTRoomIDs_Api;

/** TMTShortMeeting_Api */
typedef struct tagTMTShortMeeting_Api
{
	s32				nID;
	s8				achSubject[ KMTAPI_MG_MAX_MEETING_SUBJECT_LEN+1];
	s8				achStartTime[ KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	s8				achEndTime[ KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	s8				achOrganizerMoid[KMTAPI_MAX_DOMAIN_MOID_LEN+1];
	s32				nStatus;
	s32				nIsVideoMeeting;
	EmParticipatResponse_Api				emFeedbackStatus;
	s32				nRegularID;
	TMTRoomIDs_Api	tRoomIDs;
public:
	tagTMTShortMeeting_Api(){ memset( this ,0 ,sizeof(tagTMTShortMeeting_Api) );}
}*PTMTShortMeeting_Api,TMTShortMeeting_Api;

/** TMTShortMeetings_Api */
typedef struct tagTMTShortMeetings_Api
{
	u32					nCount;
	TMTShortMeeting_Api	atItems[KMTAPI_MG_MAX_SHORTMEETINGS_NUM];
public:
	tagTMTShortMeetings_Api(){ memset( this ,0 ,sizeof(tagTMTShortMeetings_Api) );}
}*PTMTShortMeetings_Api,TMTShortMeetings_Api;

/** TMTMeetingLists_Api */
typedef struct tagTMTMeetingLists_Api
{
	TMTShortRooms_Api      tRelatedRooms;
	TMTShortMeetings_Api   tMeetings;
public:
	tagTMTMeetingLists_Api(){ memset( this ,0 ,sizeof(tagTMTMeetingLists_Api) );}
}*PTMTMeetingLists_Api,TMTMeetingLists_Api;

typedef struct tagTMTParticipantInfo_Api
{
	s8		achMoId[KMTAPI_MAX_DOMAIN_MOID_LEN+1];
	s8      achEmail[KMTAPI_MAX_EMAIL_LEN+1];
	s8      achName[KMTAPI_MAX_CONF_NAME_LEN+1];
	s8      achParticipantNo[KMTAPI_MG_MAX_PARTICIPANTNO_LEN+1];
	EmParticipatResponse_Api     emParticipantResponse;
	u32     dwParticipantType;
public:
	tagTMTParticipantInfo_Api(){ memset( this, 0, sizeof(tagTMTParticipantInfo_Api) ); }
}*PTMTParticipantInfo_Api, TMTParticipantInfo_Api;

/** 根据Id获取会议详细信息(参与人信息) */
typedef struct tagTMTConfInfoParticipants_Api
{
	u32						dwParticipantCount;
	s8						achConfE164[KMTAPI_MAX_MT_E164_LEN+1];
	u32						dwID;
	u8						byCnt;				///< 参与人个数
	TMTParticipantInfo_Api	tMTParticipantInfo[KMTAPI_MG_MAX_PARTICIPANT_NUM];
public:
	tagTMTConfInfoParticipants_Api(){ memset( this ,0 ,sizeof(tagTMTConfInfoParticipants_Api) );}
}*PTMTConfInfoParticipants_Api,TMTConfInfoParticipants_Api;

/** 会议室预定信息 */
typedef struct tagTMTBookingInfo_Api
{
	u32		  dwMeetingRoomId;								            ///< 会议室ID
	s8		  achStartDay[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];		///< 会议开始时间
	s8		  achEndDay[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];		    ///< 会议结束时间
	u32		  dwStart;										///< 会议的开始行
	u32		  dwCount;										///< 获取的会议数
	u32		  dwOrder;										///< 会议开始时间排序, 0代表升序, 1代表降序
public:
	tagTMTBookingInfo_Api(){ memset( this ,0 ,sizeof(tagTMTBookingInfo_Api) );}
}*PTMTBookingInfo_Api,TMTBookingInfo_Api;

/** 获取某人的会议信息 */
typedef struct tagTMTMeetingListOfPerson_Api
{
	s8		achMoId[KMTAPI_MAX_DOMAIN_MOID_LEN+1];
	s8		achStartDay[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	s8		achEndDay[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	u32		dwStart;
	u32		dwCount;
	u32		dwOrder;
public:
	tagTMTMeetingListOfPerson_Api(){ memset( this ,0 ,sizeof(tagTMTMeetingListOfPerson_Api) );}
}*PTMTMeetingListOfPerson_Api,TMTMeetingListOfPerson_Api;

typedef struct tagTMTTemplateAccount_Api
{
    s8		achAccount[ KMTAPI_BUF_64_LEN+1 ];		///< 账号
    EmMtAddrType_Api		emAccountType;			///< 账号类型
public:
    tagTMTTemplateAccount_Api(){ memset( this ,0 ,sizeof(tagTMTTemplateAccount_Api) );}

}*PTMTTemplateAccount_Api, TMTTemplateAccount_Api;

/**  用于创建修改模板 */
typedef struct tagTMTSetMixInfo_Api
{
    BOOL32			bEnable;			///< 是否开启混音1：是，0：否
    EmMtMixType_Api emMode;		        ///< 0-不混音，1-讨论开始，2-定制混音

    u32 dwMixMemberCount;
    TMTTemplateAccount_Api atMixMemberList[KMTAPI_COUNT_64]; ///<  混音列表
public:
    tagTMTSetMixInfo_Api(){ memset( this ,0 ,sizeof(tagTMTSetMixInfo_Api) );}
}*PTMTSetMixInfo_Api, TMTSetMixInfo_Api;

/** 虚拟会议室配置 */
typedef struct tagTVMeetingParam_Api
{
    EmClosedMeeting_Api emClosedMeeting;                 ///< 会议免打扰，1开启，0关闭
    EmMtDualMode_Api    emDualmode;						///< 双流设置
    s8							          achEncryptedkey[ KMTAPI_BUF_32_LEN+1 ];				///< AES加密KEY
    EmEncryptArithmetic_Api		emEncryptedtype;    ///< 传输加密类型
    BOOL32						            bInitmute;                 ///< 初始化哑音  1是，0否
    EmMtOpenMode_Api	            emMeetingsafe;		 ///< 会议安全
    EmMeetingSafeType_Api	    emMeetingtype;	     ///< 1 端口会议   0 传统媒体会议
    u32         dwMeetingScale;                                             ///< 会议规模,0：空，1：4方视频会议,2：8方视频会议,3：大型视频会议
    u32         dwOneReforming;                                           ///< 归一重整,0:关闭; 1:开启
    BOOL32 bVoiceInspireEnable;                                       ///< 是否开启语言激励：1是，0否
    u32         dwVoiceInspireTime;                                       ///< 语言激励敏感度
    s8	            achPassword[ KMTAPI_BUF_128_LEN+1 ];	    ///< 密码
    BOOL32  bPublicmeeting;					                            ///< 是否公共会议室  1是，0否
    u32         dwVipNum;						                                ///< VIP账号数量
    TMTTemplateAccount_Api		   atViplist[KMTAPI_COUNT_256];	    ///< VIP账号
    TMTCreateRecordRecord_Api   tRecord;     ///< 录像设置 
    TMTCreateConfSatellite_Api	   tSatellite;    ///< 卫星会议设置
    TMTTemplateAccount_Api		   tSpeaker;    ///< 发言人
    TMTTemplateAccount_Api		   tAdmin;      ///< 管理方
    u32                                             dwVFormatNum;
    TMTVideoFormatList_Api		   atVideoFormatList[KMTAPI_COUNT_16];
    u32                                             dwDualFormatNum;
    TMTDualFormatList_Api            atDualFormatList[KMTAPI_COUNT_8];
    u32                                             dwAFormatNum;
    TMTAudioFormatList_Api          atAudioFormatList[KMTAPI_COUNT_16];
    TMTSetMixInfo_Api				   tMixInfo;    ///< 混音设置
    TMTCreateConfVmp_Api           tVmp;        ///< 画面合成设置
    TMTCreateConfPoll_Api             tPoll;         ///< 轮询设置
public:
	tagTVMeetingParam_Api(){ memset( this ,0 ,sizeof(tagTVMeetingParam_Api) );}
}*PTVMeetingParam_Api,TVMeetingParam_Api;


/** 创建会议 */
typedef struct tagTMTAddMeeting_Api
{
	s8					achSubject[KMTAPI_MG_MAX_MEETING_SUBJECT_LEN+1];
	s8					achDay[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	s8					achStartShortTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	s8					achEndShortTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];

	u32                 dwRoomsCount;
	u32					adwRooms[KMTAPI_MG_MAX_ROOMS_NUM];
	s8					achPhone[KMTAPI_MT_MAX_TELEPHONE_LEN+1];
	s8					achMobile[KMTAPI_MT_MAX_TELEPHONE_LEN+1];
	u32					dwParticipantCnt;
	s8					achParticipants[KMTAPI_MG_MAX_PARTICIPANT_NUM][KMTAPI_MAX_DOMAIN_MOID_LEN+1];
	s8					achBrief[KMTAPI_MG_MAX_MEETING_BRIEF_LEN+1];
	u32					dwIsVideoMeeting;
	u32					dwIsAutoCall;
	s8					achTemplateId[KMTAPI_MG_MAX_TEMPLATE_ID_LEN+1];
	u32					dwVroomId;
	u32					dwNotifyType;
	s8					achMeetingFormKey[KMTAPI_MG_MAX_COMMON_BUF_LEN+1];
	BOOL32				bIsSendSMS;                                           ///< 是否发送短信
	TVMeetingParam_Api	tVMeetingParam;
public:
	tagTMTAddMeeting_Api(){ memset( this ,0 ,sizeof(tagTMTAddMeeting_Api) );}
}*PTMTAddMeeting_Api,TMTAddMeeting_Api;

/** 修改会议 */
typedef struct tagTMTModifyMeeting_Api
{
	u32						dwMeetingId;
	s8						achSubject[KMTAPI_MG_MAX_MEETING_SUBJECT_LEN+1];
	s8						achDay[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	s8						achStartShortTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	s8						achEndShortTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];

	u32                     dwRoomsCount;
	u32						adwRooms[KMTAPI_MG_MAX_ROOMS_NUM];
	s8						achPhone[KMTAPI_MT_MAX_TELEPHONE_LEN+1];
	s8						achMobile[KMTAPI_MT_MAX_TELEPHONE_LEN+1];
	u32						dwParticipantCnt;
	s8						achParticipants[KMTAPI_MG_MAX_MODIFY_PARTICIPANT_NUM][KMTAPI_MAX_DOMAIN_MOID_LEN+1];
	s8						achBrief[KMTAPI_MG_MAX_MEETING_BRIEF_LEN+1];
	u32						dwIsVideoMeeting;
	u32						dwIsAutoCall;
	s8						achTemplateId[KMTAPI_MG_MAX_TEMPLATE_ID_LEN+1];
	u32						dwVroomId;
	u32						dwNotifyType;
	s8						achMeetingFormKey[KMTAPI_MG_MAX_COMMON_BUF_LEN+1];
	BOOL32					bIsSendSMS;                                 ///< 是否发送短信
	TVMeetingParam_Api		tVMeetingParam;
public:
	tagTMTModifyMeeting_Api(){ memset( this ,0 ,sizeof(tagTMTModifyMeeting_Api) );}
}*PTMTModifyMeeting_Api,TMTModifyMeeting_Api;

/** 会议反馈 */
typedef struct tagTMTMeetingFeed_Api
{
	u32		dwMeetingId;
	u32		dwAccept;
	u32		dwJoinType;
	u32     dwReasonId;

	s8      achParticipateNo[KMTAPI_MG_MAX_COMMON_BUF_LEN+1];
public:
	tagTMTMeetingFeed_Api(){ memset( this ,0 ,sizeof(tagTMTMeetingFeed_Api) );}
}*PTMTMeetingFeed_Api,TMTMeetingFeed_Api;

/** 获取空闲会议室 */
typedef struct tagTMTQueryFreeRooms_Api
{
	u32		dwRoomsNum;
	u32		adwRooms[KMTAPI_MG_MAX_ROOMS_NUM];
	s8		achStartTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	s8		achEndTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	u32		dwStart;
	u32		dwCount;
	u32		dwOrder;
	u32		dwPeopleAdmint;
	u32		dwDeviceIdMask;
	u32		dwRegionNum;
	u32		adwRegionIds[KMTAPI_MG_MAX_REGIONS_NUM];
public:
	tagTMTQueryFreeRooms_Api(){ memset( this ,0 ,sizeof(tagTMTQueryFreeRooms_Api) );}
}*PTMTQueryFreeRooms_Api,TMTQueryFreeRooms_Api;

typedef struct tagTMTRoom_Api
{
	s32		nID;
	s32		nPeopleAdmit;
	s32		nDeviceMask;

	s8		achName[ KMTAPI_MAX_CONF_NAME_LEN+1 ];
	s8		achRegionName[ KMTAPI_MG_MAX_REGIONNAME_LEN+1 ];
	s8		achStartTime[  KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1 ];
	s8		achEndTime[  KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1 ];

public:
	tagTMTRoom_Api(){ memset( this ,0 ,sizeof(tagTMTRoom_Api) );}
}*PTMTRoom_Api,TMTRoom_Api;

typedef struct tagTMTRooms_Api
{
	s32				nCount;
	TMTRoom_Api		atItems[KMTAPI_MG_MAX_ROOMS_NUM];
public:
	tagTMTRooms_Api(){ memset( this ,0 ,sizeof(tagTMTRooms_Api) );}
}*PTMTRooms_Api,TMTRooms_Api;

typedef struct tagTMTRoomList_Api
{
	TMTRooms_Api		tRooms;
	u32					dwTotal;
public:
	tagTMTRoomList_Api(){ memset( this ,0 ,sizeof(tagTMTRoomList_Api) );}
}*PTMTRoomList_Api,TMTRoomList_Api;

/** 获取推荐的虚拟会议室 */
typedef struct tagTMTRecommendedVirtualRoom_Api
{
	s8		achStartTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	s8		achEndTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
public:
	tagTMTRecommendedVirtualRoom_Api(){ memset( this ,0 ,sizeof(tagTMTRecommendedVirtualRoom_Api) );}
}*PTMTRecommendedVirtualRoom_Api,TMTRecommendedVirtualRoom_Api;

/** 获取正常的会议室 */
typedef struct tagTMTNormalRooms_Api
{
	u32		dwStart;
	u32		dwCount;
	u32		dwOrder;
public:
	tagTMTNormalRooms_Api(){ memset( this ,0 ,sizeof(tagTMTNormalRooms_Api) );}
}*PTMTNormalRooms_Api,TMTNormalRooms_Api;

typedef struct tagTMTNormalRoomList_Api
{
	u32						dwStart;
	u32						dwCount;
	TMTShortRooms_Api		tRooms;
public:
	tagTMTNormalRoomList_Api(){ memset( this ,0 ,sizeof(tagTMTNormalRoomList_Api) );}
}*PTMTNormalRoomList_Api,TMTNormalRoomList_Api;

/** 会议室信息 */
typedef struct tagTMTRoomInfo_Api
{
	u32		dwId;
	s8		achName[KMTAPI_MAX_CONF_NAME_LEN+1];
	s8		achRegionName[KMTAPI_MG_MAX_REGIONNAME_LEN+1];
public:
	tagTMTRoomInfo_Api(){ memset( this ,0 ,sizeof(tagTMTRoomInfo_Api) );}
}*PTMTRoomInfo_Api,TMTRoomInfo_Api;

/** 根据名称搜索会议室 */
typedef struct tagTMTRoomListByName_Api
{
	u32		dwStart;
	u32		dwCount;
	u32		dwOrder;
	s8		achName[KMTAPI_MG_MAX_MEETING_NAME_LEN+1];
public:
	tagTMTRoomListByName_Api(){ memset( this ,0 ,sizeof(tagTMTRoomListByName_Api) );}
}*PTMTRoomListByName_Api,TMTRoomListByName_Api;

/** 根据会议室资源搜索会议室 */
typedef struct tagTMTQueryRooms_Api
{
	u32		dwStart;
	u32		dwCount;
	u32		dwOrder;
	u32		dwPeopleAdmit;
	u32		dwDeviceIdMask;
public:
	tagTMTQueryRooms_Api(){ memset( this ,0 ,sizeof(tagTMTQueryRooms_Api) );}
}*PTMTQueryRooms_Api,TMTQueryRooms_Api;


typedef struct tagTMTTemplate_Api
{
	s8      achTemplateID[KMTAPI_CM_MAX_TEMPLATE_ID_LEN+1];
	s8      achTemplateName[KMTAPI_CM_MAX_TEMPLATE_NAME_LEN+1];
public:
	tagTMTTemplate_Api(){ memset( this ,0 ,sizeof(tagTMTTemplate_Api) );}
}*PTMTTemplate_Api,TMTTemplate_Api;


typedef struct tagTMTTemplates_Api
{
	u32           			nCount;
	TMTTemplate_Api       	atItems[KMTAPI_MG_MAX_TEMPLATES_NUM];///< chqw:这里的结构体数组元素最大个数暂时使用MT_MAX_COUNT（因为终端相应的定义直接使用repeated）
public:
	tagTMTTemplates_Api(){ memset( this ,0 ,sizeof(tagTMTTemplates_Api) );}
}*PTMTTemplates_Api,TMTTemplates_Api;

typedef struct tagTMTTemplateList_Api
{
	TMTTemplates_Api	tTemplates;
public:
	tagTMTTemplateList_Api(){ memset( this ,0 ,sizeof(tagTMTTemplateList_Api) );}
}*PTMTTemplateList_Api,TMTTemplateList_Api;

typedef struct tagTMTPerson_Api
{
	s8				achMoId[KMTAPI_MAX_DOMAIN_MOID_LEN+1];
	s8				achEmail[KMTAPI_MAX_EMAIL_LEN+1];
	s8				achName[KMTAPI_MAX_MT_E164_LEN+1];
	s8				achParticipantNo[KMTAPI_MAX_DOMAIN_MOID_LEN+1];
	BOOL32   		bIsParticipant;
	u32				dwParticipantType;
public:
	tagTMTPerson_Api(){ memset( this ,0 ,sizeof(tagTMTPerson_Api) );}
}*PTMTPerson_Api,TMTPerson_Api;

typedef struct tagTMTPersons_Api
{
	u32					dwCount;
	TMTPerson_Api		atItems[KMTAPI_MG_MAX_MEETING_PERSON_NUM];
public:
	tagTMTPersons_Api(){ memset( this ,0 ,sizeof(tagTMTPersons_Api) );}
}*PTMTPersons_Api,TMTPersons_Api;

typedef struct tagTMTTemplateInfo_Api
{
	s8		achTemplateID[KMTAPI_CM_MAX_TEMPLATE_ID_LEN+1];
	s8		achTemplateName[KMTAPI_CM_MAX_TEMPLATE_NAME_LEN+1];
	s8		achTemplateResolution[KMTAPI_BUF_32_LEN+1];
	s8		achBandwidth[KMTAPI_BUF_32_LEN+1];
	TMTPersons_Api	tPersons;
public:
	tagTMTTemplateInfo_Api(){ memset( this ,0 ,sizeof(tagTMTTemplateInfo_Api) );}
}*PTMTTemplateInfo_Api,TMTTemplateInfo_Api;

/** 锁定会议室 */
typedef struct tagTMTLockRoom_Api
{
	s32     nRoomId;
	s8		achStartTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	s8		achEndTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
public:
	tagTMTLockRoom_Api(){ memset( this ,0 ,sizeof(tagTMTLockRoom_Api) );}
}*PTMTLockRoom_Api,TMTLockRoom_Api;

typedef struct tagTListNotifyByMax_Api
{
	u32     dwId;                          ///<这个是指消息的
	u32     dwMessageType;
public:
	tagTListNotifyByMax_Api(){ memset( this ,0 ,sizeof(tagTListNotifyByMax_Api) );}
}*PTListNotifyByMax_Api,TListNotifyByMax_Api;

typedef struct tagTIfExistLockByFormkey_Api
{
	s8       achFormkey[KMTAPI_MG_MAX_COMMON_BUF_LEN+1];
public:
	tagTIfExistLockByFormkey_Api(){ memset( this ,0 ,sizeof(tagTIfExistLockByFormkey_Api) );}
}*PTIfExistLockByFormkey_Api,TIfExistLockByFormkey_Api;

/** 例会包含的会议Id */
typedef struct tagTMTMeetingIDs_Api
{
	u32		dwCount;							        	///< 例会包含的会议个数
	u32		adwItems[KMTAPI_MG_MAX_REGULAR_NUM];			///< 会议Id
public:
	tagTMTMeetingIDs_Api(){ memset( this ,0 ,sizeof(tagTMTMeetingIDs_Api) );}
}*PTMTMeetingIDs_Api,TMTMeetingIDs_Api;

/** 根据Id获取例会信息 */
typedef struct tagTMTRegularInfo_Api
{
	u32							dwId;												 ///< 例会Id
	s8							achSubject[ KMTAPI_MG_MAX_MEETING_SUBJECT_LEN+1];	 ///< 主题
	s8							achStartTime[ KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1]; ///< 开始时间
	s8							achEndTime[ KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];	 ///< 结束时间
	u32							dwStatus;										     ///< 例会状态
	s8							achOrganizer[KMTAPI_MG_MAX_ORGANIZER_LEN+1];		 ///< 组织人
	s8							achOrganizerMail[KMTAPI_MG_ORGANIZERMAIL_LEN+1];	 ///< 组织人email
	s8							achPhone[KMTAPI_MT_MAX_TELEPHONE_LEN+1];			 ///< 组织人电话
	s8							achMobile[KMTAPI_MT_MAX_TELEPHONE_LEN+1];			 ///< 组织人手机
	s8							achBrief[KMTAPI_MG_MAX_MEETING_BRIEF_LEN+1];		 ///< 内容
	u32							dwIsVideo;											 ///< 是否是视频会议
	s8							achStartDate[ KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1]; ///< 开始日期
	s8							achEndDate[ KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];	 ///< 结束日期
	u32							dwRepeatType;										 ///< 重复规则	
	u32							dwFrequency;										 ///< 重复频率
	s8							achWeekDays[KMTAPI_MG_MAX_COMMON_BUF_LEN+1];		 ///< 例会重复规则要执行的时间点
	TMTMeetingIDs_Api			tMeetingIDs;

public:
	tagTMTRegularInfo_Api(){ memset( this ,0 ,sizeof(tagTMTRegularInfo_Api) );}
}*PTMTRegularInfo_Api,TMTRegularInfo_Api;

typedef struct tagTMeetingUnlock_Api
{
	s8        achMeetingFormKey[KMTAPI_MG_MAX_COMMON_BUF_LEN+1];

public:
	tagTMeetingUnlock_Api(){ memset( this ,0 ,sizeof(tagTMeetingUnlock_Api) );}
}*PTMeetingUnlock_Api,TMeetingUnlock_Api;

typedef struct tagTRegularFeed_Api
{
	u32				dwRegularId;
	u32				dwJoinType;
	u32				dwRejectReason;
	BOOL32			bAccept;
	s8				achParticipantNo[KMTAPI_MG_MAX_COMMON_BUF_LEN+1];

public:
	tagTRegularFeed_Api(){ memset( this ,0 ,sizeof(tagTRegularFeed_Api) );}
}*PTRegularFeed_Api,TRegularFeed_Api;

typedef struct tagTMTRegion_Api
{
	u32				dwId;
	s8		        achName[KMTAPI_MG_MAX_MEETING_REGION_NAME_LEN+1];

public:
	tagTMTRegion_Api(){ memset( this ,0 ,sizeof(tagTMTRegion_Api) );}
}*PTMTRegion_Api,TMTRegion_Api;

typedef struct tagTMTRegions_Api
{
	u32                     dwCount;
	TMTRegion_Api			atItems[KMTAPI_MG_MAX_MEETING_REGION_NUM];
	s8				        achCompanyId[KMTAPI_MG_MAX_MEETING_COMPANY_NAME_LEN+1];

public:
	tagTMTRegions_Api(){ memset( this ,0 ,sizeof(tagTMTRegions_Api) );}
}*PTMTRegions_Api,TMTRegions_Api;

typedef struct tagTMTLockRooms_Api
{
	s32			anRoomIds[KMTAPI_MG_MAX_ROOMS_NUM];
	u32			dwRoomIdsCnt;
	s8			achStartTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	s8			achEndTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];

public:
	tagTMTLockRooms_Api(){ memset( this ,0 ,sizeof(tagTMTLockRooms_Api) );}
}*PTMTLockRooms_Api,TMTLockRooms_Api;

typedef struct tagTMTRoomLockResultItem_Api
{
	u32					dwId;
	u32					dwResult;

	s8			        achName[KMTAPI_MG_MAX_ROOM_NAME_LEN+1];
public:
	tagTMTRoomLockResultItem_Api(){ memset( this ,0 ,sizeof(tagTMTRoomLockResultItem_Api) );}
}*PTMTRoomLockResultItem_Api,TMTRoomLockResultItem_Api;

typedef struct tagTMTRoomLockResultItems_Api
{
	u32								dwCount;
	u32								dwSuccess;
	s8						        achMeetingFormkey[KMTAPI_MG_MAX_ROOM_NAME_LEN+1];
	s8			                    achStartTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	s8			                    achEndTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	TMTRoomLockResultItem_Api		atItems[KMTAPI_MG_MAX_ROOMS_LOCK_RESULT_NUM];

public:
	tagTMTRoomLockResultItems_Api(){ memset( this ,0 ,sizeof(tagTMTRoomLockResultItems_Api) );}
}*PTMTRoomLockResultItems_Api,TMTRoomLockResultItems_Api;

typedef struct tagTMeetingNotify_Api
{
	EmRestMeetingNotifyType_Api     emNotifyType;
	s8								achMoId[KMTAPI_MAX_DOMAIN_MOID_LEN+1];
	u32								dwNotifyId;
	u32								dwNum;

public:
	tagTMeetingNotify_Api(){ memset( this ,0 ,sizeof(tagTMeetingNotify_Api) );}
}*PTMeetingNotify_Api,TMeetingNotify_Api;

typedef struct tagTAppClearNotify_Api
{
	s8        achNotifyType[KMTAPI_GM_NOTIFY_SIZE+1];
public:
	tagTAppClearNotify_Api(){ memset( this ,0 ,sizeof(tagTAppClearNotify_Api) );}
}*PTAppClearNotify_Api,TAppClearNotify_Api;

/** TRestErrorInfo_Api字段和u32字段结合(多数消息中会用到) */
typedef struct tagTMgErrKeyPair_Api
{
	TRestErrorInfo_Api		tErrInfo;			///< 错误信息
	u32						dwKey;				///< 会议列表

public:
	tagTMgErrKeyPair_Api(){ memset( this ,0 ,sizeof(tagTMgErrKeyPair_Api) );}
}*PTMgErrKeyPair_Api,TMgErrKeyPair_Api;


typedef struct tagTMTGetPerTemplateList_Api
{
	u32 dwStart;			///< 个人模板的开始行，默认为0，即从符合条件的数据中的第几行取数据，0为第一行数据
	u32 dwCount;			///< 获取的个人模板数，默认为10，即在包含start在内的后count条数据，如果参数为0表示获取所有个人模板
	u32 dwOrder;			///< 根据个人模板的最后修改时间排序，0代表升序，1代表降序，默认为0

public:
	tagTMTGetPerTemplateList_Api(){ memset( this ,0 ,sizeof(tagTMTGetPerTemplateList_Api) );}
}*PTMTGetPerTemplateList_Api, TMTGetPerTemplateList_Api;

typedef struct tagTMTPerTemplate_Api
{
	TMTTemplateAccount_Api		tAdmin;							///< 管理方
	u32							dwBitrate;						///< 会议码率
	EmMtDualMode_Api			emDualmode;						///< 双流设置
	u32							dwDuration;						///< 时长
	s8							achEncryptedkey[ KMTAPI_BUF_32_LEN+1 ];				///< AES加密KEY
	EmEncryptArithmetic_Api		emEncryptedtype;				///< 传输加密类型
	BOOL32						bInitmute;						///< 初始化哑音  1是，0否
	EmMtOpenMode_Api	emMeetingsafe;					        ///< 会议安全
	EmMeetingSafeType_Api	emMeetingtype;				    	///< 1 端口会议   0 传统媒体会议
	u32							dwMemberNum;					///< 参会人数量
	TMTTemplateAccount_Api		atMembers[ KMTAPI_COUNT_256];	///< 参会人
	TMTSetMixInfo_Api				tMixInfo;						///< 混音设置
	s8							achName[ KMTAPI_BUF_128_LEN+1 ];						///< 模板名称
	s8							achPassword[ KMTAPI_BUF_128_LEN+1 ];					///< 密码
	BOOL32						bPublicmeeting;					///< 是否公共会议室  1是，0否
	EmMtResolution_Api			emResolution;					///< 会议分辨率
	TMTCreateRecordRecord_Api		tRecord;				    ///< 录像设置 
	TMTCreateConfSatellite_Api	tSatellite;				///< 卫星会议设置
	TMTTemplateAccount_Api		tSpeaker;				///< 发言人
    TMTCreateConfVmp_Api        tVmp;          ///< 画面合成设置
	u32							dwTemplateid;			///< ID号（添加的时候，不填，修改的时候填）

	u32 dwVFormatNum;
	TMTVideoFormatList_Api			tVideoFormatList[KMTAPI_COUNT_16];

	u32 dwAFormatNum;
	TMTAudioFormatList_Api			tAudioFormatList[KMTAPI_COUNT_16];

	u32 dwDualFormatNum;
	TMTDualFormatList_Api			tDualFormatList[KMTAPI_COUNT_8];

	u32 dwVipNum;						///< VIP账号数量
	TMTTemplateAccount_Api			atViplist[KMTAPI_COUNT_256];			///< VIP账号

	EmClosedMeeting_Api emClosedMeeting;                 ///< 会议免打扰，1开启，0关闭
    u32 dwMeetingScale;                                                   ///< 会议规模,0：空，1：4方视频会议,2：8方视频会议,3：大型视频会议
    u32 dwOneReforming;                                                 ///< 归一重整,0:关闭; 1:开启
    BOOL32 bVoiceInspireEnable;                                     ///< 是否开启语音激励
    u32 dwVoiceInspireTime;                                             ///< 语音激励敏感度
public:
	tagTMTPerTemplate_Api()
	{ 
		memset( this ,0 ,sizeof(tagTMTPerTemplate_Api) );
		emMeetingsafe = emMt_Open_Api;
	}
}*PTMTPerTemplate_Api, TMTPerTemplate_Api;

/*************************************************************************************/
/* 虚拟会议室 */


typedef struct tagTMTVConfMember_Api
{
	s8		achName[ KMTAPI_BUF_128_LEN+1 ];			///< 名称
	s8		achAccount[ KMTAPI_BUF_128_LEN+1 ];			///< 帐号
	EmMtAddrType_Api	emAccountType;					///< 帐号类型
	EmConfProtocol_Api	emProtocol;						///< 呼叫协议

public:
	tagTMTVConfMember_Api(){ memset( this ,0 ,sizeof(tagTMTVConfMember_Api) );}
}*PTMTVConfMember_Api, TMTVConfMember_Api;

typedef struct tagTMTCreateVConf_Api
{
	u32		dwVConfId;									///< 虚拟会议室id
	s8		achVConfName[ KMTAPI_BUF_64_LEN+1] ;		///< 会议名称
	u32		dwDuration;									///< 会议时长(0为永久会议)
	
	u32					dwMemberNum;
	TMTVConfMember_Api	atMember[ KMTAPI_COUNT_192+1 ];

public:
	tagTMTCreateVConf_Api(){ memset( this ,0 ,sizeof(tagTMTCreateVConf_Api) );}
}*PTMTCreateVConf_Api, TMTCreateVConf_Api;

typedef struct tagTMTVConfResult_Api
{
	BOOL32	bSuccess;									///< 是否成功
	u32		dwErrorCode;								///< 错误码
	s8		achDescription[ KMTAPI_BUF_64_LEN +1 ];		///< 结果描述
	s8		acTemplateId[ KMTAPI_BUF_64_LEN+1 ];		///< 模板ID
public:
	tagTMTVConfResult_Api(){ memset( this ,0 ,sizeof(tagTMTVConfResult_Api) );}
}*PTMTVConfResult_Api, TMTVConfResult_Api;

typedef struct tagTMTVConfListReq_Api
{
	u32		dwCount;									///< 获取的虚拟会议数，默认为10，即在包含start在内的后count条数据，如果参数为0表示获取所有虚拟会议室
	u32		dwOrder;									///< 根据虚拟会议的时间排序，默认为0 	0-升序；	1-降序；
	u32		dwStart;									///< 虚拟会议的开始行，默认为0，即从符合条件的数据中的第几行取数据，0为第一行数据

public:
	tagTMTVConfListReq_Api(){ memset( this ,0 ,sizeof(tagTMTVConfListReq_Api) );}
}*PTMTVConfListReq_Api, TMTVConfListReq_Api;

typedef struct tagTMTVConfInfo_Api
{
	s8		achConfId[ KMTAPI_GM_MAX_E164+1 ];				///< 虚拟会议唯一标识
	s8		achConfE164[ KMTAPI_GM_MAX_E164+1 ];			///< 虚拟会议号码
	s8		achVirualRoomName[ KMTAPI_BUF_64_LEN+1 ];		///< 虚拟会议室名称 最大字符长度：64个字符
	s8		achConfName[ KMTAPI_BUF_64_LEN+1 ];				///< 会议主题，针对使用中的虚拟会议室，如果空闲则为空

	EmMtOpenMode_Api	emSafeConf;							///< 会议安全
	EmMtVConfStatus_Api		emConfStatus;						///< 会议状态
	EmMtMaxJoinMt_Api		emMaxJoinMt;						///< 最大与会终端数

	s8		achEncryptedKey[ KMTAPI_BUF_16_LEN+1 ];			///< 传输加密AES加密密钥

	u32		dwBitrate;										///< 会议码率
	BOOL32	bExclusive;										///< 是否是专属会议室 

	u32					dwExUsrNum;
	TMTVConfMember_Api	atExUser[ KMTAPI_COUNT_192+1 ];		///< 专属人员列表

	EmMtResolution_Api	emResolution;						///< 分辨率

public:
	tagTMTVConfInfo_Api(){ memset( this ,0 ,sizeof(tagTMTVConfInfo_Api) );}
}*PTMTVConfInfo_Api, TMTVConfInfo_Api;

typedef struct tagTMTVConfList_Api
{
	u32		dwTotal;
	TMTVConfInfo_Api	atConfInfo[ KMTAPI_COUNT_4+1 ];

public:
	tagTMTVConfList_Api(){ memset( this ,0 ,sizeof(tagTMTVConfList_Api) );}
}*PTMTVConfList_Api, TMTVConfList_Api;

typedef struct tagTMTVConfResource_Api
{
	s8		achName[KMTAPI_BUF_128_LEN+1];
	EmMtResolution_Api		emResolution;
	EmMtMaxJoinMt_Api		emMaxJoinMt;
	u32		dwTotal;	///< 资源总数
	u32		dwUsed;		///< 资源已占用数
			
public:
	tagTMTVConfResource_Api(){ memset( this ,0 ,sizeof(tagTMTVConfResource_Api) );}
}*PTMTVConfResource_Api, TMTVConfResource_Api;

typedef struct tagTMTVConfResources_Api
{
	u32		dwNum;		
	TMTVConfResource_Api		atResource[ KMTAPI_COUNT_192+1 ];
	EmResourceType_Api			emResourceType;

public:
	tagTMTVConfResources_Api(){ memset( this ,0 ,sizeof(tagTMTVConfResources_Api) );}
}*PTMTVConfResources_Api, TMTVConfResources_Api;

typedef struct tagTMTVConfRecord_Api
{
	EmPublishMode_Api emPublishMode;                        ///< 发布模式
	EmRecordMode_Api  emRecordMode;                         ///< 录像模式
	BOOL32		bDoubleFlow;									///< 是否内容共享录像
	BOOL32		bAnonymous;									///< 是否支持免登陆观看直播
	
	s8			achVrsId[ KMTAPI_BUF_128_LEN +1 ];			///< VRS的moid

public:
	tagTMTVConfRecord_Api(){ memset( this ,0 ,sizeof(tagTMTVConfRecord_Api) );}
}*PTMTVConfRecord_Api, TMTVConfRecord_Api;

/**虚拟会议室详情 */
typedef struct tagTMTVConfDetailInfo_Api
{
	s8				                achVirtualRoomName[ KMTAPI_BUF_128_LEN+1 ];        ///< 虚拟会议室名称
	s8								achConfE164[ KMTAPI_GM_MAX_E164+1 ];
	u32				                dwDuration;                             ///< 会议持续时长(0是永久会议)
	u32				                dwBitrate;                              ///< 会议码率

	u32						        dwVideoCount;
	TMTVideoFormatList_Api          atVideoFormatList[KMTAPI_COUNT_16];

	s8				            	achConfName[ KMTAPI_BUF_128_LEN+1 ];    ///< 会议名称
	EmMeetingSafeType_Api		    emMeetingType;                          ///< 会议是否是 端口会议
	EmMtOpenMode_Api		        emMeetingSafe;                          ///< 会议安全mode

	EmMtVConfStatus_Api				emConfStatus;							///< 会议状态
	EmMtMaxJoinMt_Api				emMaxJoinMt;							///< 最大与会终端数 

	EmRestCascadeMode_Api emCascadeMode;///< 级联模式,0简单级联，1合并级联
	BOOL32 bCascadeUpload;              ///< 是否级联上传:1是，0否
	BOOL32 bCascadeReturn;              ///< 是否级联回传:1是，0否
	u32 dwCascadeReturnPara;            ///< 级联回传带宽参数

	BOOL32                          bInitMute;                              ///< 初始化哑音：1是，0否
	BOOL32 							bMuteFilter;							///< 是否开启全场哑音例外：1-开启；0-不开启

	TMTGetMixInfo_Api		    tMixInfo;                             		///< 混音相关信息

	EmVmpMode_Api				emVmpMode; ///<画面合成模式，1-会控指定;2-自动

//	TMTConfVMPInfo_Api			tVmp;                                  			///< 画面合成模式

	TMTVConfRecord_Api      tRecord;                    					///< 录像设置 

	BOOL32 							bPreoccpuyResource; 					///< 是否预占资源 

	EmEncryptArithmetic_Api			emEncryptedType;                        ///< 会议加密方式
	s8								achEncryptedKey[ KMTAPI_BUF_32_LEN+1 ]; ///< 会议秘钥

	EmMtDualMode_Api                emDualMode;                             ///< 双流权限

	EmAnswerMode_Api				emAnswerMode; 							///< 呼叫模式
	u32								dwCallTimes;							///< 呼叫次数
	u32								dwCallInterval;							///< 呼叫间隔(秒)
	BOOL32							bVoiceInspireEnable;					///< 是否开启语言激励：1是，0否
	u32								dwOneReforming;                         ///< 归一重整,0:关闭; 1:开启

	EmMtFecMode_Api					emFecMode;							///< FEC开关
	BOOL32							bExclusive;							///< 是否是专属虚拟会议室

	u32					dwExUsrNum;
	TMTVConfMember_Api	atExUser[ KMTAPI_COUNT_192+1 ];		///< 专属人员列表

public:
	tagTMTVConfDetailInfo_Api(){memset( this, 0, sizeof(tagTMTVConfDetailInfo_Api) ); }
}*PTMTVConfDetailInfo_Api, TMTVConfDetailInfo_Api;


/*************************************************************************************/
/* 混音信息 */
typedef struct tagTMTConfMixInfo_Api
{
    EmMtMixType_Api emMode;                                   ///< 0-不混音，1-讨论开始，2-定制混音
    u32 dwMixMemberCount;                                     ///< 成员数量
    TMTCreateConfMember_Api atMixMemberList[KMTAPI_COUNT_64]; ///< 混音列表
public:
    tagTMTConfMixInfo_Api(){ memset( this ,0 ,sizeof(tagTMTConfMixInfo_Api) );}
}*PTMTConfMixInfo_Api, TMTConfMixInfo_Api;

/* 混音信息 概要*/
typedef struct tagTMTConfMixBrief_Api
{
    EmMtMixType_Api emMode;                                   ///< 0-不混音，1-智能混音，2-定制混音
public:
    tagTMTConfMixBrief_Api(){ emMode = emMcuNoMix_Api; }
}*PTMTConfMixBrief_Api, TMTConfMixBrief_Api;

/*卫星会议设置*/
typedef struct tagTMTConfSatelliteInfo_Api
{
    s8  achMulticastAddr[ KMTAPI_BUF_64_LEN+1 ];    ///< 卫星IP地址
    u32 dwPort;                                     ///< 端口
    u32 dwReturnNum;                                ///< 回传数
public:
    tagTMTConfSatelliteInfo_Api(){ memset( this ,0 ,sizeof(tagTMTConfSatelliteInfo_Api) );}
}*PTMTConfSatelliteInfo_Api, TMTConfSatelliteInfo_Api;

/* 录像设置 */
typedef struct tagTMTConfRecordInfo_Api
{
    BOOL32 bDoubleFlow;			    ///< 是否设置双流，1是，0否
    BOOL32 bMain;					///< 是否设置主流，1是，0否
    BOOL32 bPublish;				///< 是否发布录像，1是，0否
public:
    tagTMTConfRecordInfo_Api(){ memset( this ,0 ,sizeof(tagTMTConfRecordInfo_Api) );}
}*PTMTConfRecordInfo_Api, TMTConfRecordInfo_Api;

/** 组播设置 */
typedef struct tagTMTConfMultiCastInfo_Api
{
    s8 achMulticastAddr[KMTAPI_BUF_64_LEN+1];    ///<地址
    u32 dwPort;                                  ///<端口
public:
    tagTMTConfMultiCastInfo_Api() { memset( this, 0, sizeof(tagTMTConfMultiCastInfo_Api) ); }
}*PTMTConfMultiCastInfo_Api, TMTConfMultiCastInfo_Api;

//画面合成参数(新增结构体)
typedef struct tagTMTNameStyle_Api
{
    u32 dwFontSize; ///台标字体大小 0-小；1-中；2-大；
    u32 dwPosition; ///台标显示位置，默认为1 0-左上角；1-左下角；2-右上角；3-右下角；4-底部中间；
    s8  achFontColor[KMTAPI_COUNT_32];  ///台标字体三原色#RGB格式，十六进制表示，默认为：#FFFFFF白色
public:
    tagTMTNameStyle_Api() { memset( this, 0, sizeof(tagTMTNameStyle_Api) ); }
}*PTMTNameStyle_Api, TMTNameStyle_Api;

/** 画面合成设置 */
typedef struct tagTMTConfVMPInfo_Api
{
    BOOL32 bEnable;          ///<是否启用：1是0否
    EmVmpMode_Api    emMode; ///<画面合成模式，1-会控指定;2-自动
    EmMtVmpStyle_Api emStyle;///<风格
    BOOL32 bVoiceHint;       ///<是否识别声音来源:1是0否
    BOOL32 bShowMTName;      ///<是否显示别名：1是0否
    BOOL32 bIsBroadcast;     ///<是否广播
    u32 dwMemberCount;       ///<成员个数
    TMTTemplateVmpMember_Api atMemberList[KMTAPI_MAX_VMP_MEMBER_NUM];///<画面合成成员列表
    TMTNameStyle_Api         atNameStyle;   ///画面合成台标参数
public:
    tagTMTConfVMPInfo_Api() { memset( this, 0, sizeof(tagTMTConfVMPInfo_Api) ); }
}*PTMTConfVMPInfo_Api, TMTConfVMPInfo_Api;

/** 画面合成设置 概要*/
typedef struct tagTMTConfVMPBrief_Api
{
    BOOL32           bEnable;  ///<是否启用：1是0否
    EmVmpMode_Api    emMode;   ///<画面合成模式，1-会控指定;2-自动
public:
    tagTMTConfVMPBrief_Api() { bEnable = FALSE; emMode = emScreenVmp_Api; }
}*PTMTConfVMPBrief_Api, TMTConfVMPBrief_Api;

/**轮询设置  */
/*typedef struct tagTMTConfPollInfo_Api
{
    BOOL32 bEnable;   ///<是否启用：1是0否
    EmPollMode_Api emMode;  ///<轮询模式 1-仅图像轮询 3-音视频轮询
    u32 dwNum;        ///<轮询次数，0无限次轮询
    u32 dwInterval;   ///<轮询间隔时间(秒)
    u32 dwMemberCount;///<成员个数
    TMTCreateConfMember_Api atMemberList[KMTAPI_COUNT_192];///<轮询成员列表
public:
    tagTMTConfPollInfo_Api() { memset( this, 0, sizeof(tagTMTConfPollInfo_Api) ); }
}*PTMTConfPollInfo_Api, TMTConfPollInfo_Api;
*/
/*录像设置*/
typedef struct tagTMTRecordAttribute_Api
{
    EmPublishMode_Api emPublishMode;                        ///< 发布模式
    EmRecordMode_Api  emRecordMode;                         ///< 录像模式
    BOOL32            bAnonymous;                                   ///< 是否支持免登陆观看直播 FALSE-不支持；TRUE-支持；
    BOOL32            bDualStream;                          ///<是否内容共享录像0-否；1-是；(新增)
    s8                achVrsId[KMTAPI_BUF_64_LEN+1];        ///VRS的moid
public:
    tagTMTRecordAttribute_Api() { memset( this, 0, sizeof(tagTMTRecordAttribute_Api) ); }
}*PTMTRecordAttribute_Api, TMTRecordAttribute_Api;
/*录像设置 概要*/
typedef struct tagTMTRecordAttributeBrief_Api
{
    EmRecordMode_Api  emRecordMode;                     ///< 录像模式
    s8                achVRSID[KMTAPI_BUF_64_LEN+1];	///< VRS的moid
public:
    tagTMTRecordAttributeBrief_Api() { memset( this, 0, sizeof(tagTMTRecordAttributeBrief_Api) ); }
}*PTMTRecordAttributeBrief_Api, TMTRecordAttributeBrief_Api;

typedef struct tagTMTDCSAttribute_Api
{
    EmDcsConfMode_Api emDCSMode;           ///< 数据协作模式
public:
    tagTMTDCSAttribute_Api() { emDCSMode = emConfModeStop_Api; }
}*PTMTDCSAttribute_Api, TMTDCSAttribute_Api;

/*个人模板 - 对应新的平台API*/
typedef struct tagTMTPeronalTemplate_Api
{
    s8						    achTemplateID[KMTAPI_BUF_128_LEN+1];	///< ID号（添加的时候，不填，修改的时候填）
    s8							achName[ KMTAPI_BUF_128_LEN+1 ];		///< 模板名称
    u32							dwBitrate;						        ///< 会议码率
    EmClosedMeeting_Api         emCloseConf;                            ///< 会议免打扰，1开启，0关闭
    EmMtOpenMode_Api	        emSafeConf;					            ///< 会议安全

    s8							achPassword[ KMTAPI_BUF_128_LEN+1 ];    ///< 密码
    EmEncryptArithmetic_Api		emEncryptedtype;                        ///< 传输加密类型
    EmMeetingSafeType_Api	    emMeetingtype;                          ///< 1 端口会议   0 传统媒体会议
    u32                         dwCallTimes;                            ///<  呼叫次数
    u32                         dwCallInterval;                         ///<  呼叫间隔(秒)

    BOOL32						bInitmute;                              ///<  初始化哑音  1是，0否
    BOOL32                      bInitSilence;                           ///< 初始化静音1是，0否
    EmVideoQuality_Api          emVidoQuality;                          ///< 视频质量,0：质量优先；1：速度优先
    u32                         dwOneReforming;                         ///< 归一重整,0:关闭; 1:开启
    s8							achEncryptedkey[ KMTAPI_BUF_32_LEN+1 ]; ///< AES加密KEY

    EmMtDualMode_Api			emDualmode;						        ///< 双流设置
    BOOL32                      bVoiceActivityDetection;                ///< 是否开启语言激励，1是，0否
    u32                         dwVacinterval;                          ///< 语音激励敏感度(s)，支持5、15、30、60
    EmRestCascadeMode_Api       emCascadeMode;                          ///< 级联模式,0简单级联，1合并级联
    BOOL32                      bCascadeUpload;                         ///< 是否级联上传:1是，0否

    BOOL32                      bCascadeReturn;                         ///< 是否级联回传:1是，0否
    u32                         dwCascadeReturnPara;                    ///< 级联回传带宽参数
    BOOL32						bPublicConf;                            ///< 是否公共会议室  1是，0否
    u32                         dwMaxJoinMt;                            ///< 最大与会终端数，（会议规模,0：空，4：4方视频会议,8：8方视频会议,192：大型视频会议）
    BOOL32                      bAutoEnd;                               ///< 是否自动结会：1是，0否

    BOOL32                      bPreoccpuyResouce;                      ///< 预占资源 0-不预占 1-预占
    TMTCreateConfMember_Api     tSpeaker;                               ///< 发言人
    TMTCreateConfMember_Api     tChairman;                              ///< 主席
    TMTConfMixInfo_Api          tMix;                                   ///< 混音信息

    u32                         dwVFormatNum;
    TMTVideoFormatList_Api      atVideoFormatList[KMTAPI_COUNT_16];     ///< 主视频格式列表

    u32                         dwIMemberNum;
    TMTInviteMember_Api         atInviteMembers[ KMTAPI_COUNT_256];     ///< 参会成员

    TMTConfVMPInfo_Api          tVmp;                                   ///< 画面合成设置
    
    u32                         dwVipNum;
    TMTCreateConfMember_Api     atViplist[KMTAPI_COUNT_256];            ///< VIP账号
    
    TMTConfPollInfo_Api       tPoll;                                    ///< 轮询设置
	BOOL32						bEncryptedAuth;                         ///< 是否双向认证 0-关闭 1-开启
    EmCallMode_Api              emCallMode;                             ///< 呼叫模式；
    TMTRecordAttribute_Api      tRecordAttr;                            ///< 录像设置
    TMTDCSAttribute_Api         tDCSAttr;                               ///< 数据协作
    EmMtFecMode_Api             emFecMode;                              ///< FEC开关
    BOOL32                      bMuteFilter;                            ///是否开启全场哑音例外 0-不对任何人例外；1-对发言方和管理方例外；
    BOOL32                      bDoubleFlow;                            ///成为发言人后立即发起内容共享0-否；1-是；
    u32                         dwDuration;                             ///会议时长
    TMTCreateConfMember_Api     atKeepCallingMembers[KMTAPI_COUNT_256]; ///追呼成员数组
    u32                         dwKeepCallNum;                          //追呼成员个数
public:
	tagTMTPeronalTemplate_Api()
	{ 
		memset( this ,0 ,sizeof(tagTMTPeronalTemplate_Api) );
        emSafeConf = emMt_Open_Api;
	}
}*PTMTPeronalTemplate_Api, TMTPeronalTemplate_Api;

/*简单个人模板-对应新的平台API*/
typedef struct tagTMTSimplePeronalTemplate_Api
{
    s8						    achTemplateID[KMTAPI_BUF_128_LEN+1];	///< ID号（添加的时候，不填，修改的时候填）
    s8							achName[ KMTAPI_BUF_128_LEN+1 ];		///< 模板名称
    u32							dwBitrate;						        ///< 会议码率
    EmClosedMeeting_Api         emCloseConf;                            ///< 会议免打扰，1开启，0关闭
    
    EmMtOpenMode_Api	        emSafeConf;					            ///< 会议安全
    s8							achPassword[ KMTAPI_BUF_128_LEN+1 ];    ///< 密码
    EmEncryptArithmetic_Api		emEncryptedtype;                        ///< 传输加密类型
    EmMeetingSafeType_Api	    emMeetingtype;                          ///< 1 端口会议   0 传统媒体会议
    u32                         dwCallTimes;                            ///< 呼叫次数
    
    u32                         dwCallInterval;                         ///< 呼叫间隔(秒)
    BOOL32						bInitmute;                              ///< 初始化哑音  1是，0否
    BOOL32                      bInitSilence;                           ///< 初始化静音1是，0否
    EmVideoQuality_Api          emVidoQuality;                          ///<视频质量,0：质量优先；1：速度优先
    
    u32                         dwOneReforming;                         ///< 归一重整,0:关闭; 1:开启
    s8							achEncryptedkey[ KMTAPI_BUF_32_LEN+1 ]; ///< AES加密KEY
    EmMtDualMode_Api			emDualmode;						        ///< 双流设置
    BOOL32                      bVoiceActivityDetection;                ///< 是否开启语言激励，1是，0否
    EmRestCascadeMode_Api       emCascadeMode;                          ///< 级联模式,0简单级联，1合并级联
    
    BOOL32                      bCascadeUpload;                         ///< 是否级联上传:1是，0否
    BOOL32                      bCascadeReturn;                         ///< 是否级联回传:1是，0否
    u32                         dwCascadeReturnPara;                    ///< 级联回传带宽参数
    u32                         dwMaxJoinMt;                            ///< 最大与会终端数（会议规模,0：空，4：4方视频会议,8：8方视频会议,192：大型视频会议）
    u32                         dwInviteNum;                            ///< 与会人总数

    u32                         dwMixNum;                               ///< 混音成员总数
    u32                         dwVmpNum;                               ///< 画面合成成员总数
    u32                         dwVipNum;                               ///< vip总数
    u32                         dwPollNum;                              ///< 轮询成员总数
    TMTCreateConfMember_Api     tSpeaker;                               ///< 发言人

    TMTCreateConfMember_Api     tChairman;                              ///< 主席
    BOOL32						bPublicConf;                            ///< 是否公共会议室  1是，0否

    u32                         dwVFormatNum;
    TMTVideoFormatList_Api      atVideoFormatList[KMTAPI_COUNT_16];     ///< 主视频格式列表
    EmCallMode_Api              emCallMode;                             ///< 呼叫模式 
    EmMtFecMode_Api             emFecMode;                              ///< FEC开关
    BOOL32                      bMuteFilter;                            ///<是否开启全场哑音例外 0-不开启；1-开启；
    BOOL32                      bDoubleFlow;                            ///<成为发言人后立即发起内容共享0-否；1-是；
    BOOL32                      bEncryptedAuth;                         ///<终端双向认证 0-关闭；1-开启；
public:
    tagTMTSimplePeronalTemplate_Api()
    { 
        memset( this ,0 ,sizeof(tagTMTSimplePeronalTemplate_Api) );
        emSafeConf = emMt_Open_Api;
    }
}*PTMTSimplePeronalTemplate_Api, TMTSimplePeronalTemplate_Api;

/*个人模板列表成员*/
typedef struct tagTMTPersonalTemplateMember_Api
{
    s8						    achTemplateID[KMTAPI_BUF_128_LEN+1];	///< ID号
    s8							achName[ KMTAPI_BUF_128_LEN+1 ];		///< 模板名称
    u32							dwBitrate;						        ///< 会议码率
    EmClosedMeeting_Api         emCloseConf;                            ///< 会议免打扰，1开启，0关闭
    EmMtOpenMode_Api	        emSafeConf;					            ///< 会议安全

    EmEncryptArithmetic_Api		emEncryptedtype;                        ///< 传输加密类型
    EmMeetingSafeType_Api	    emMeetingtype;                          ///< 1 端口会议   0 传统媒体会议
    BOOL32						bInitmute;                              ///< 初始化哑音  1是，0否
    BOOL32                      bInitSilence;                           ///< 初始化静音1是，0否
    EmVideoQuality_Api          emVidoQuality;                          ///< 视频质量,0：质量优先；1：速度优先

    u32                         dwOneReforming;                         ///< 归一重整,0:关闭; 1:开启
    s8							achEncryptedkey[ KMTAPI_BUF_32_LEN+1 ]; ///< AES加密KEY
    EmMtDualMode_Api			emDualmode;						        ///< 双流设置
    BOOL32                      bVoiceActivityDetection;                ///< 是否开启语言激励，1是，0否
    BOOL32						bPublicConf;                            ///< 是否公共会议室  1是，0否 
    EmMtResolution_Api			emResolution;					        ///< 会议分辨率
    u32                         dwMaxJoinMt;                            ///< 最大与会终端数 （会议规模,0：空，4：4方视频会议,8：8方视频会议,192：大型视频会议）
	BOOL32						bEncryptedAuth;                         ///< 是否双向认证 0-关闭 1-开启
public:
    tagTMTPersonalTemplateMember_Api(){memset( this, 0, sizeof(tagTMTPersonalTemplateMember_Api) ); }
}*PTMTPersonalTemplateMember_Api, TMTPersonalTemplateMember_Api;

/*个人模板列表 */
typedef struct tagTMTPersonalTemplatesList_Api
{
    u32                             dwCount;
    TMTPersonalTemplateMember_Api	atPersonalTemplateMember[KMTAPI_MG_MAX_TEMPLATE_LIST_NUM];

public:
    tagTMTPersonalTemplatesList_Api(){memset( this, 0, sizeof(tagTMTPersonalTemplatesList_Api) ); }
}*PTMTPersonalTemplatesList_Api, TMTPersonalTemplatesList_Api;

/*公共模板 对应新的平台API*/
typedef struct tagTMTCommonTemplate_Api
{
    s8                          achTemplateID[KMTAPI_BUF_128_LEN+1];    ///< 公共模板名称;（添加的时候，不填，修改的时候填）
    s8							achName[ KMTAPI_BUF_128_LEN+1 ];		///< 模板名称
    u32							dwBitrate;						        ///< 会议码率
    EmClosedMeeting_Api         emCloseConf;                            ///< 会议免打扰，1开启，0关闭
    EmMtOpenMode_Api	        emSafeConf;					            ///< 会议安全

    s8							achPassword[ KMTAPI_BUF_128_LEN+1 ];    ///< 密码  (查询时不返回)
    EmEncryptArithmetic_Api		emEncryptedtype;                        ///< 传输加密类型
    EmMeetingSafeType_Api	    emMeetingtype;                          ///< 1 端口会议   0 传统媒体会议
    BOOL32						bPublicConf;                            ///< 是否公共会议室  1是，0否
    u32                         dwCallTimes;                            ///< 呼叫次数

    u32                         dwCallInterval;                         ///< 呼叫间隔(秒)
    BOOL32						bInitmute;                              ///< 初始化哑音  1是，0否
    BOOL32                      bInitSilence;                           ///< 初始化静音1是，0否
    EmVideoQuality_Api          emVidoQuality;                          ///< 视频质量,0：质量优先；1：速度优先
    u32                         dwOneReforming;                         ///< 归一重整,0:关闭; 1:开启

    s8							achEncryptedkey[ KMTAPI_BUF_32_LEN+1 ]; ///< AES加密KEY
    EmMtDualMode_Api			emDualmode;						        ///< 双流设置
    BOOL32                      bVoiceActivityDetection;                ///< 是否开启语言激励，1是，0否
    u32                         dwVacinterval;                          ///< 语音激励敏感度(s)，支持5、15、30、60
    EmRestCascadeMode_Api       emCascadeMode;                          ///< 级联模式,0简单级联，1合并级联

    BOOL32                      bCascadeUpload;                         ///< 是否级联上传:1是，0否
    BOOL32                      bCascadeReturn;                         ///< 是否级联回传:1是，0否
    u32                         dwCascadeReturnPara;                    ///< 级联回传带宽参数
    u32                         dwMaxJoinMt;                            ///< 最大与会终端数 （会议规模,0：空，4：4方视频会议,8：8方视频会议,192：大型视频会议）
    BOOL32                      bAutoEnd;                               ///< 是否自动结会：1是，0否 

    BOOL32                      bPreoccpuyResouce;                      ///< 预占资源 0-不预占 1-预占 
    u32                         dwVFormatNum;
    TMTVideoFormatList_Api      atVideoFormatList[KMTAPI_COUNT_16];     ///< 主视频格式列表
	BOOL32						bEncryptedAuth;                         ///< 是否双向认证 0-关闭 1-开启

    TMTDCSAttribute_Api         tDCSAttr;                               ///< 数据协作
    EmMtFecMode_Api             emFecMode;                              ///< FEC开关
    TMTConfVMPBrief_Api         tVMP;                                   ///< 画面合成设置
    TMTConfMixBrief_Api         tMIX;                                   ///< 混音设置
    BOOL32                      bDoubleFlow;                            ///< 成为发言人后立即发起内容共享
    BOOL32                      bMuteFilter;                            ///是否开启全场哑音例外 0-不对任何人例外；1-对发言方和管理方例外；
    u32                         dwDuration;                             ///会议时长,0是永久会议
    EmCallMode_Api              emCallMode;                             ///< 呼叫模式；
    TMTRecordAttributeBrief_Api tRecordAttr;                            ///录像设置 
public:
    tagTMTCommonTemplate_Api()
    { 
        memset( this ,0 ,sizeof(tagTMTCommonTemplate_Api) );
        emSafeConf = emMt_Open_Api;
    }
}*PTMTCommonTemplate_Api, TMTCommonTemplate_Api;

/*获取公共模板列表成员*/
typedef struct tagTMTCommonTemplateMember_Api
{
    s8							achTemplateID[KMTAPI_BUF_128_LEN+1];    ///< ID号
    s8							achName[ KMTAPI_BUF_128_LEN+1 ];		///< 模板名称
    u32							dwBitrate;						        ///< 会议码率
    EmClosedMeeting_Api         emCloseConf;                            ///< 会议免打扰，1开启，0关闭

    EmMtOpenMode_Api	        emSafeConf;					            ///< 会议安全
    EmEncryptArithmetic_Api		emEncryptedtype;                        ///< 传输加密类型
    EmMeetingSafeType_Api	    emMeetingtype;                          ///< 1 端口会议   0 传统媒体会议
    BOOL32						bInitmute;                              ///< 初始化哑音  1是，0否
    BOOL32                      bInitSilence;                           ///< 初始化静音1是，0否

    EmVideoQuality_Api          emVidoQuality;                          ///< 视频质量,0：质量优先；1：速度优先
    u32                         dwOneReforming;                         ///< 归一重整,0:关闭; 1:开启
    s8							achEncryptedkey[ KMTAPI_BUF_32_LEN+1 ]; ///< AES加密KEY
    EmMtDualMode_Api			emDualmode;						        ///< 双流设置
    BOOL32                      bVoiceActivityDetection;                ///< 是否开启语言激励，1是，0否

    BOOL32						bPublicConf;                            ///< 是否公共会议室  1是，0否 
    EmMtResolution_Api			emResolution;					        ///< 会议分辨率
    u32                         dwMaxJoinMt;                            ///< 最大与会终端数 （会议规模,0：空，4：4方视频会议,8：8方视频会议,192：大型视频会议）
	BOOL32						bEncryptedAuth;                         ///< 是否双向认证 0-关闭 1-开启	
public:
    tagTMTCommonTemplateMember_Api(){memset( this, 0, sizeof(tagTMTCommonTemplateMember_Api) ); }
}*PTMTCommonTemplateMember_Api, TMTCommonTemplateMember_Api;

/*公共模板列表 */
typedef struct tagTMTCommonTemplatesList_Api
{
    u32                             dwCount;
    TMTCommonTemplateMember_Api     atCommonTemplateMember[KMTAPI_MG_MAX_TEMPLATE_LIST_NUM];

public:
    tagTMTCommonTemplatesList_Api(){memset( this, 0, sizeof(tagTMTCommonTemplatesList_Api) ); }
}*PTMTCommonTemplatesList_Api, TMTCommonTemplatesList_Api;

/*会议发起者*/
typedef struct tagTMTConfInitiator_Api
{
    s8                  achName[ KMTAPI_BUF_128_LEN+1 ];             ///< 平台过来 填的是一般都是 164号 和 别名
    s8                  achAccount[ KMTAPI_BUF_64_LEN+1 ];           ///< 平台过来填的一般都是moid
    EmMtAddrType_Api    emAccountType;                               ///< 类型
    s8                  achTelephone[KMTAPI_MT_MAX_TELEPHONE_LEN+1]; ///< 座机
    s8                  achMobile[KMTAPI_MT_MAX_TELEPHONE_LEN+1];    ///< 手机

public:
    tagTMTConfInitiator_Api(){memset( this, 0, sizeof(tagTMTConfInitiator_Api) ); }
}*PTMTConfInitiator_Api, TMTConfInitiator_Api;

/*会议列表元素 对应新的平台API*/
typedef struct tagTMTConferenceElement_Api
{
    s8							achName[ KMTAPI_BUF_128_LEN+1 ];		///< 模板名称
    s8                          achConfID[KMTAPI_BUF_64_LEN+1];         ///< 会议号
    EmMeetingSafeType_Api	    emConfType;                             ///< 1 端口会议   0 传统媒体会议
    s8                          achStartTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1]; ///< 会议开始时间
    s8                          achEndTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1]; ///< 会议结束时间
    
    u32							dwDuration;						        ///< 时长
    u32							dwBitrate;						        ///< 会议码率
    EmClosedMeeting_Api         emCloseConf;                            ///< 会议免打扰，1开启，0关闭
    EmMtOpenMode_Api	        emSafeConf;					            ///< 会议安全
    EmEncryptArithmetic_Api		emEncryptedtype;                        ///< 传输加密类型

    s8							achPassword[ KMTAPI_BUF_128_LEN+1 ];    ///< 密码----
    BOOL32						bInitmute;                              ///< 初始化哑音  1是，0否
    BOOL32                      bInitSilence;                           ///< 初始化静音1是，0否
    EmVideoQuality_Api          emVidoQuality;                          ///< 视频质量,0：质量优先；1：速度优先
    u32                         dwOneReforming;                         ///< 归一重整,0:关闭; 1:开启--
    
    s8							achEncryptedkey[ KMTAPI_BUF_32_LEN+1 ]; ///< AES加密KEY
    EmMtDualMode_Api			emDualmode;						        ///< 双流设置
    BOOL32                      bVoiceActivityDetection;                ///< 是否开启语言激励，1是，0否
    BOOL32						bPublicConf;                            ///< 是否公共会议室  1是，0否
    u32                         dwInvitedMtNum;                         ///< 邀请终端数量---
    
    u32                         dwMaxJoinMt;                            ///< 最大与会终端数 （会议规模,0：空，4：4方视频会议,8：8方视频会议,192：大型视频会议）
    TMTConfInitiator_Api        tConfInitiator;                         ///< 会议发起者
	BOOL32						bEncryptedAuth;                         ///< 是否双向认证 0-关闭 1-开启

public:
    tagTMTConferenceElement_Api()
    { 
        memset( this ,0 ,sizeof(tagTMTConferenceElement_Api) );
        emSafeConf = emMt_Open_Api;
    }
}*PTMTConferenceElement_Api, TMTConferenceElement_Api;

/*预约会议列表 */
typedef struct tagTMTBookConferenceList_Api
{
    u32                     dwTotal; //预约会议的总数
    u32                     dwCount; //atBookConference 实际数量
    TMTConferenceElement_Api   atBookConference[KMTAPI_MG_MAX_TEMPLATE_LIST_NUM];

public:
    tagTMTBookConferenceList_Api(){memset( this, 0, sizeof(tagTMTBookConferenceList_Api) ); }
}*PTMTBookConferenceList_Api, TMTBookConferenceList_Api;

/*即时会议列表元素 对应新的平台API*/
typedef struct tagTMTInstantConfElement_Api
{
    s8							achName[ KMTAPI_BUF_128_LEN+1 ];		 ///< 模板名称
    s8                          achVirtualRoomName[ KMTAPI_BUF_128_LEN+1 ]; ///< 虚拟会议室名称
    s8                          achConfID[KMTAPI_BUF_64_LEN+1];         ///< 会议号
    BOOL32                      bVoiceInspireEnable;                    ///< 是否开启语言激励，1是，0否
    u32                         dwVacinterval;                          ///< 语音激励敏感度(s)，支持5、15、30、60, 开启语音激励时有效
    EmMeetingSafeType_Api	    emConfType;                             ///< 1 端口会议   0 传统媒体会议
    s8                          achStartTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1]; ///< 会议开始时间

    s8                          achEndTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1]; ///< 会议结束时间
    u32							dwDuration;						        ///< 时长
    u32							dwBitrate;						        ///< 会议码率
    EmClosedMeeting_Api         emCloseConf;                            ///< 会议免打扰，1开启，0关闭
    EmMtOpenMode_Api	        emSafeConf;					            ///< 会议安全

    BOOL32                      bAutoEnd;                               ///< 自动结会(少于两个终端时自动结会) 0-不自动结会 1-自动结会
    BOOL32                      bPreoccupyResource;                     ///< 预占资源(创会时就预占音视频适配器) 0-不预占 1-预占
    EmEncryptArithmetic_Api		emEncryptedtype;                        ///< 传输加密类型
    BOOL32						bInitmute;                              ///< 初始化哑音  1是，0否
    BOOL32                      bInitSilence;                           ///< 初始化静音1是，0否

    EmVideoQuality_Api          emVidoQuality;                          ///< 视频质量,0：质量优先；1：速度优先
    s8							achEncryptedkey[ KMTAPI_BUF_32_LEN+1 ]; ///< AES加密KEY
    EmMtDualMode_Api			emDualmode;						        ///< 双流设置
    BOOL32						bPublicConf;                            ///< 是否公共会议室  TRUE是，FALSE否
    u32                         dwMaxJoinMt;                            ///< 最大与会终端数 （会议规模,0：空，4：4方视频会议,8：8方视频会议,192：大型视频会议）

    TMTConfInitiator_Api        tConfInitiator;                         ///< 会议发起者
    u32                         dwConfLevel;                            ///会议级别：1-255, 值越小, 级别越高(用于抢呼已在其他会议里的终端
    BOOL32                      bNeedPassword;                          ///是否需要密码
    BOOL32                      bForceBroadcast;                        ///是否强制广播 FALSE-不强制广播；TRUE-强制广播；
	BOOL32						bEncryptedAuth;                         ///< 是否双向认证 0-关闭 1-开启
    EmMtFecMode_Api             emFecMode;                              ///< FEC开关
    BOOL32                      bDoubleFlow;                            ///成为发言人后立即发起内容共享 0-否 1-是（新加）
    BOOL32                      bMuteFilter;                            ///全场哑音例外，参数为1时，若执行全场哑音操作，主席和发言人不会被哑音，若执行单个哑音操作时可以被哑音 0-否 1-是（新加）

public:
    tagTMTInstantConfElement_Api()
    { 
        memset( this ,0 ,sizeof(tagTMTInstantConfElement_Api) );
        emSafeConf = emMt_Open_Api;
    }
}*PTMTInstantConfElement_Api, TMTInstantConfElement_Api;

//获取即时会议列表条件
typedef struct tagTMTGetIntanceConfList_Api
{
    u32     dwStart;      ///< 获取的视频会议列表的起始会议位置, 0表示第一个会议, 默认为0
    u32     dwCount;      ///< 获取的视频会议的个数, 即包括start在内的后count个会议, 0代表获取所有会议, 默认为10
public:
    tagTMTGetIntanceConfList_Api(){memset( this, 0, sizeof(tagTMTGetIntanceConfList_Api) ); }
}*PTMTGetIntanceConfList_Api, TMTGetIntanceConfList_Api;

/*即时会议列表 */
typedef struct tagTMTInstantConferenceList_Api
{
    u32                         dwTotal;  //即时会议的总数
    u32                         dwCount;  //atInstantConf 实际参数个数
    TMTInstantConfElement_Api   atInstantConf[KMTAPI_MG_MAX_TEMPLATE_LIST_NUM];

public:
    tagTMTInstantConferenceList_Api(){memset( this, 0, sizeof(tagTMTInstantConferenceList_Api) ); }
}*PTMTInstantConferenceList_Api, TMTInstantConferenceList_Api;

/** 获取会议列表条件 */
typedef struct tagTMTConditionOfConfList_Api
{
    s8      achStartTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];  ///< 会议开始日期，不填表示从服务器当前时间开始
    s8      achEndTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];    ///< 会议结束日期，不填表示从开始时间以后的所有
    u32     dwStart;                                             ///< 默认为0，即从符合条件的数据中的第几行取数据，0为第一行数据
    u32     dwCount;                                             ///< 默认为10，即在包含start在内的后count条数据，如果参数为0表示获取所有
    u32     dwOrder;                                             ///< 0代表升序，1代表降序，默认为0
public:
    tagTMTConditionOfConfList_Api(){memset( this, 0, sizeof(tagTMTConditionOfConfList_Api) ); }
}*PTMTConditionOfConfList_Api, TMTConditionOfConfList_Api;

/*预约会议信息 对应新的平台API*/
typedef struct tagTMTBookConferenceInfo_Api
{
    s8							achName[ KMTAPI_BUF_128_LEN+1 ];		///< 会议名称
    s8                          achConfID[KMTAPI_BUF_64_LEN+1];         ///< 会议号
    EmMeetingSafeType_Api	    emConfType;                             ///< 1 端口会议   0 传统媒体会议
    s8                          achStartTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1]; ///< 会议开始时间
    s8                          achEndTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];   ///< 会议结束时间

    u32							dwDuration;						        ///< 时长
    u32							dwBitrate;						        ///< 会议码率
    EmClosedMeeting_Api         emCloseConf;                            ///< 会议免打扰，1开启，0关闭
    EmMtOpenMode_Api	        emSafeConf;					            ///< 会议安全
    s8							achPassword[ KMTAPI_BUF_128_LEN+1 ];    ///< 密码

    EmEncryptArithmetic_Api		emEncryptedtype;                        ///< 传输加密类型
    s8							achEncryptedkey[ KMTAPI_BUF_32_LEN+1 ]; ///< AES加密KEY
    u32                         dwCallTimes;                            ///< 呼叫次数
    u32                         dwCallInterval;                         ///< 呼叫间隔(秒)
    BOOL32						bInitmute;                              ///< 初始化哑音  1是，0否

    BOOL32                      bInitSilence;                           ///< 初始化静音1是，0否
    EmVideoQuality_Api          emVidoQuality;                          ///< 视频质量,0：质量优先；1：速度优先
    EmMtDualMode_Api			emDualmode;						        ///< 双流设置
    BOOL32                      bVoiceActivityDetection;                ///< 是否开启语言激励，1是，0否
    EmRestCascadeMode_Api       emCascadeMode;                          ///< 级联模式,0简单级联，1合并级联

    BOOL32                      bCascadeUpload;                         ///< 是否级联上传:1是，0否
    BOOL32                      bCascadeReturn;                         ///< 是否级联回传:1是，0否
    u32                         dwCascadeReturnPara;                    ///< 级联回传带宽参数
    BOOL32						bPublicConf;                            ///< 是否公共会议室  1是，0否
    BOOL32                      bVmpEnable;                             ///< 是否在合成 1是 0 否

    BOOL32                      bMixEnable;                             ///< 是否在混音 1是 0否
    BOOL32                      bPollEnable;                            ///< 是否在轮询 1是 0否
    u32                         dwInvitedMtNum;                         ///< 邀请终端数量
    u32                         dwMaxJoinMt;                            ///< 最大与会终端数 （会议规模,0：空，4：4方视频会议,8：8方视频会议,192：大型视频会议）
    TMTConfInitiator_Api        tConfInitiator;                         ///< 会议发起者

    TMTCreateConfMember_Api     tSpeaker;                               ///< 发言人
    TMTCreateConfMember_Api     tChairman;                              ///< 发言人
    u32                         dwVFormatNum;
    TMTVideoFormatList_Api      atVideoFormatList[KMTAPI_COUNT_16];     ///< 主视频格式列表

    u32                         dwOneReforming;                         ///< 归一重整,0:关闭; 1:开启
    BOOL32                      bAutoEnd;                               ///< 是否自动结会：1是，0否 
    BOOL32                      bPreoccpuyResouce;                      ///< 预占资源 0-不预占 1-预占 
	BOOL32						bEncryptedAuth;                         ///< 是否双向认证 0-关闭 1-开启
    EmMtFecMode_Api             emFecMode;                              ///< FEC开关
    BOOL32                      bDoubleFlow;                            ///成为发言人后立即发起内容共享
    BOOL32                      bMuteFilter;                             ///是否开启全场哑音例外
public:
    tagTMTBookConferenceInfo_Api()
    { 
        memset( this ,0 ,sizeof(tagTMTBookConferenceInfo_Api) );
        emSafeConf = emMt_Open_Api;
    }
}*PTMTBookConferenceInfo_Api, TMTBookConferenceInfo_Api;

/*即时会议 对应新的平台API*/
typedef struct tagTMTInstantConference_Api
{
    s8							achName[ KMTAPI_BUF_128_LEN+1 ];		///< 会议名称
    u32							dwDuration;						        ///< 时长
    u32							dwBitrate;						        ///< 会议码率
    EmClosedMeeting_Api         emCloseConf;                            ///< 会议免打扰，1开启，0关闭
    EmMtOpenMode_Api	        emSafeConf;					            ///< 会议安全
   
    s8							achPassword[ KMTAPI_BUF_128_LEN+1 ];    ///< 密码
    EmEncryptArithmetic_Api		emEncryptedtype;                        ///< 传输加密类型
    EmMeetingSafeType_Api	    emMeetingtype;                          ///< 1 端口会议   0 传统媒体会议
    u32                         dwCallTimes;                            ///< 呼叫次数
    u32                         dwCallInterval;                         ///< 呼叫间隔(秒)

    BOOL32						bInitmute;                              ///< 初始化哑音  1是，0否
    BOOL32                      bInitSilence;                           ///< 初始化静音1是，0否
    EmVideoQuality_Api          emVidoQuality;                          ///< 视频质量,0：质量优先；1：速度优先
    s8							achEncryptedkey[ KMTAPI_BUF_32_LEN+1 ]; ///< AES加密KEY
    EmMtDualMode_Api			emDualmode;						        ///< 双流设置
   
    BOOL32                      bVoiceActivityDetection;                ///< 是否开启语言激励，1是，0否
    u32                         dwVacinterval;                          ///< 语音激励敏感度(s)，支持5、15、30、60
    EmRestCascadeMode_Api       emCascadeMode;                          ///< 级联模式,0简单级联，1合并级联
    BOOL32                      bCascadeUpload;                         ///< 是否级联上传:1是，0否
    BOOL32                      bCascadeReturn;                         ///< 是否级联回传:1是，0否
    u32                         dwCascadeReturnPara;                    ///< 级联回传带宽参数
    
    u32                         dwMaxJoinMt;                            ///< 最大与会终端数 （会议规模,0：空，4：4方视频会议,8：8方视频会议,192：大型视频会议）
    BOOL32                      bAutoEnd;                               ///< 是否自动结会：1是，0否
    BOOL32                      bPreoccpuyResouce;                      ///< 预占资源 0-不预占 1-预占
    TMTCreateConfMember_Api     tSpeaker;                               ///< 发言人
    TMTCreateConfMember_Api     tChairman;                              ///< 发言人

    BOOL32						bPublicConf;                            ///< 是否公共会议室  1是，0否
    TMTConfMixInfo_Api          tMix;                                   ///< 混音信息

    u32                         dwVFormatNum;
    TMTVideoFormatList_Api      atVideoFormatList[KMTAPI_COUNT_16];     ///< 主视频格式列表

    u32                         dwIMemberNum;
    TMTInviteMember_Api         atInviteMembers[ KMTAPI_COUNT_192];     ///< 参会成员

    TMTConfVMPInfo_Api          tVmp;                                   ///< 画面合成设置

    u32                         dwVipNum;
    TMTCreateConfMember_Api     atViplist[KMTAPI_COUNT_192];            ///< VIP账号

    TMTConfPollInfo_Api         tPoll;                                  ///< 轮询设置
	BOOL32						bEncryptedAuth;                         ///< 是否双向认证 0-关闭 1-开启
    EmCallMode_Api              emCallMode;                             ///< 呼叫模式 
    TMTRecordAttribute_Api      tRecordAttr;                            ///< 录像设置
    TMTDCSAttribute_Api         tDCSAttr;                               ///< 数据协作
	EmVConfCreateType_Api		emVConfCreateType;						///< 创会类型，如果不填则是默认的实时会议
	s8							achVConfId[KMTAPI_BUF_64_LEN+1];		///< 根据 虚拟会议室ID创会（emVConfCreateType填emCreateVirtualConf_Api） 
                                                                        ///< 根据 模板ID创会（emVConfCreateType填emCreateConfByTemplate_Api）
    EmMtFecMode_Api             emFecMode;                              ///< FEC开关
    BOOL32                      bDoubleFlow;                            ///<成为发言人后立即发起内容共享，默认为0,0-否；1-是；
    BOOL32                      bMuteFilter;                             ///<是否开启全场哑音例外，默认为0,0-不开启；1-开启；
    TMTCreateConfMember_Api     atKeepCallingMembers[KMTAPI_KEEP_CALLING_NUM];  ///< 追呼成员数组 (暂定2个)
    u32                         dwKeepCallingMemberNum;                  ///< 追呼成员个数
public:
    tagTMTInstantConference_Api()
    { 
        memset( this ,0 ,sizeof(tagTMTInstantConference_Api) );
        emSafeConf = emMt_Open_Api;
    }
}*PTMTInstantConference_Api, TMTInstantConference_Api;

/*即时会议信息 对应新的平台API*/
typedef struct tagTMTInstantConferenceInfo_Api
{
    s8							achName[ KMTAPI_BUF_128_LEN+1 ];		///< 会议名称
    s8				            achVirtualRoomName[ KMTAPI_BUF_128_LEN+1 ];        ///< 虚拟会议室名称
    s8                          achConfID[KMTAPI_BUF_64_LEN+1];         ///< 会议号
    EmMeetingSafeType_Api	    emConfType;                             ///< 1 端口会议   0 传统媒体会议
    s8                          achStartTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1]; ///< 会议开始时间
    s8                          achEndTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];   ///< 会议结束时间

    u32							dwDuration;						        ///< 时长
    u32							dwBitrate;						        ///< 会议码率
    EmClosedMeeting_Api         emCloseConf;                            ///< 会议免打扰，1开启，0关闭
    EmMtOpenMode_Api	        emSafeConf;					            ///< 会议安全
    EmEncryptArithmetic_Api		emEncryptedtype;                        ///< 传输加密类型

    u32                         dwCallTimes;                            ///< 呼叫次数
    u32                         dwCallInterval;                         ///< 呼叫间隔(秒)
    BOOL32						bInitmute;                              ///< 初始化哑音  1是，0否
    BOOL32                      bInitSilence;                           ///< 初始化静音1是，0否

    EmVideoQuality_Api          emVidoQuality;                          ///< 视频质量,0：质量优先；1：速度优先
    s8							achEncryptedkey[ KMTAPI_BUF_32_LEN+1 ]; ///< AES加密KEY
    EmMtDualMode_Api			emDualmode;						        ///< 双流设置
    BOOL32						bPublicConf;                            ///< 是否公共会议室  1是，0否
    BOOL32                      bAutoEnd;                               ///< 是否自动结会：1是，0否

    BOOL32                      bPreoccpuyResouce;                      ///< 预占资源 0-不预占 1-预占
    u32                         dwMaxJoinMt;                            ///< 最大与会终端数 （会议规模,0：空，4：4方视频会议,8：8方视频会议,192：大型视频会议）
    BOOL32                      bVoiceInspireEnable;                    ///< 是否开启语言激励，1是，0否
    TMTConfInitiator_Api        tConfInitiator;                         ///< 会议发起者
    u32                         dwVFormatNum;
    TMTVideoFormatList_Api      atVideoFormatList[KMTAPI_COUNT_16];     ///< 主视频格式列表
   
    BOOL32                      bVmpEnable;                             ///< 是否在合成 1是 0 否
    BOOL32                      bMixEnable;                             ///< 是否在混音 1是 0否
    BOOL32                      bPollEnable;                            ///< 是否在轮询 1是 0否
    BOOL32                      bNeedPassword;                          ///< 是否需要密码 1是,0否
    EmRestCascadeMode_Api       emCascadeMode;                          ///< 级联模式,0简单级联，1合并级联

    BOOL32                      bCascadeUpload;                         ///< 是否级联上传:1是，0否
    BOOL32                      bCascadeReturn;                         ///< 是否级联回传:1是，0否
    u32                         dwCascadeReturnPara;                    ///< 级联回传带宽参数
    u32                         dwVacinterval;                          ///< 语音激励敏感度(s)，支持5、15、30、60, 开启语音激励时有效
    u32                         dwConfLevel;                            ///< 会议级别：1-255, 值越小, 级别越高(用于抢呼已在其他会议里的终端)
	BOOL32						bEncryptedAuth;                         ///< 是否双向认证 0-关闭 1-开启
    BOOL32                      bForceBroadcast;                        ///< 是否强制广播 FALSE-不强制广播；TRUE-强制广播；
    EmCallMode_Api              emCallMode;                             ///< 呼叫模式
    EmMtFecMode_Api             emFecMode;                              ///< FEC开关
    BOOL32                      bDoubleFlow;                            ///成为发言人后立即发起内容共享 0-否 1-是
    BOOL32                      bMuteFilter;                            ///全场哑音例外，参数为1时，若执行全场哑音操作，主席和发言人不会被哑音，若执行单个哑音操作时可以被哑音  0-否；1-是；
public:
    tagTMTInstantConferenceInfo_Api()
    { 
        memset( this ,0 ,sizeof(tagTMTInstantConferenceInfo_Api) );
        emSafeConf = emMt_Open_Api;
    }
}*PTMTInstantConferenceInfo_Api, TMTInstantConferenceInfo_Api;

/*获取个人模板成员信息-条件*/
typedef struct tagTMTGetPerTemplateInfo_Api
{
    s8  achTemplateID[KMTAPI_BUF_128_LEN+1];	///< 模板ID
    u32 dwStart;        ///<  默认为0，即从符合条件的数据中的第几行取数据，0为第一行数据
    u32 dwCount;        ///<  默认为10，即在包含start在内的后count条数据，如果参数为0表示获取所有
    u32 dwOrder;        ///<  保留
public:
    tagTMTGetPerTemplateInfo_Api(){memset(this, 0, sizeof(tagTMTGetPerTemplateInfo_Api));}
}*PTMTGetPerTemplateInfo_Api, TMTGetPerTemplateInfo_Api;

/*个人模板参会人员列表*/
typedef struct tagTMTPerInviteMemberList_Api
{ 
    s8                          achTemplateID[KMTAPI_BUF_128_LEN+1];	///< 模板ID
    u32                         dwCount;                                ///<  人员数
    TMTInviteMember_Api         atInviteMembers[ KMTAPI_COUNT_256];     ///< 参会成员

public:
    tagTMTPerInviteMemberList_Api(){memset(this, 0, sizeof(tagTMTPerInviteMemberList_Api));}
}*PTMTPerInviteMemberList_Api, TMTPerInviteMemberList_Api;

/*个人模板混音信息*/
typedef struct tagTMTGetPerMixInfo_Api
{ 
    s8                  achTemplateID[KMTAPI_BUF_128_LEN+1];    ///< 模板ID
    TMTConfMixInfo_Api  tMix;                                   ///< 混音信息
public:
    tagTMTGetPerMixInfo_Api(){memset(this, 0, sizeof(tagTMTGetPerMixInfo_Api));}
}*PTMTGetPerMixInfo_Api, TMTGetPerMixInfo_Api;

/*个人模板VMP信息*/
typedef struct tagTMTGetPerVMPInfo_Api
{ 
    s8	                    achTemplateID[KMTAPI_BUF_128_LEN+1];	///< 模板ID
    TMTConfVMPInfo_Api      tVMP;                                   ///< 画面合成设置
public:
    tagTMTGetPerVMPInfo_Api(){memset(this, 0, sizeof(tagTMTGetPerVMPInfo_Api));}
}*PTMTGetPerVMPInfo_Api, TMTGetPerVMPInfo_Api;

/*获取个人模板轮询信息*/
typedef struct tagTMTGetPerPollInfo_Api
{ 
    s8	                    achTemplateID[KMTAPI_BUF_128_LEN+1];	///< 模板ID
    TMTConfPollInfo_Api     tPoll;                                  ///< 板轮询信息
public:
    tagTMTGetPerPollInfo_Api(){memset(this, 0, sizeof(tagTMTGetPerPollInfo_Api));}
}*PTMTGetPerPollInfo_Api, TMTGetPerPollInfo_Api;

/*获取个人模板vip*/
typedef struct tagTMTGetPerVIPInfo_Api
{ 
    s8	                    achTemplateID[KMTAPI_BUF_128_LEN+1];	///< 模板ID
    u32                     dwCount;                                ///< 成员数
    TMTCreateConfMember_Api atVIP[KMTAPI_COUNT_256];                ///< VIP账号
public:
    tagTMTGetPerVIPInfo_Api(){memset(this, 0, sizeof(tagTMTGetPerVIPInfo_Api));}
}*PTMTGetPerVIPInfo_Api, TMTGetPerVIPInfo_Api;

/** 公共信息 */
typedef struct tagTMTCommonConfInfo_Api
{
	u32		dwId;										///<通知ID
	s8		achReceiverMoId[KMTAPI_GM_MAX_MOID+1];		///<结束人MOID
	u32     dwMessgaeType;								///<通知类型
	s8		achCompanyMoId[KMTAPI_GM_MAX_MOID+1];		///<接收人所属公司moid
	s8		achCreateTime[KMTAPI_GM_MAX_DATETIME+1];	///<通知在服务器端创建的时间
public: 
	tagTMTCommonConfInfo_Api(){ memset( this, 0, sizeof(tagTMTCommonConfInfo_Api) ); }
}*PTMTCommonConfInfo_Api, TMTCommonConfInfo_Api;


/** 公共信息 */
typedef struct tagTGetNotifyById_Api
{
	TRestErrorInfo_Api	  tErrInfo;
	TMTCommonConfInfo_Api tConfInfo;

public: 
	tagTGetNotifyById_Api(){ memset( this, 0, sizeof(tagTGetNotifyById_Api) ); }
}*PTGetNotifyById_Api, TGetNotifyById_Api;

/** 根据Id获取会议详细信息(预占的会议室) */
typedef struct tagTMTConfInfoRooms_Api
{
	u32		dwRoomCount;
	TMTRoomInfo_Api atMTRoomInfo[KMTAPI_GM_MAX_ROOM_NUM];

public:
	tagTMTConfInfoRooms_Api(){ memset( this, 0, sizeof(tagTMTConfInfoRooms_Api) ); }
}*PTMTConfInfoRooms_Api, TMTConfInfoRooms_Api;


/** 适用于messgaeType为102 */
typedef struct tagTMTContentCreateMeeting_Api
{
	u32		dwMeetingId; ///<会议ID
	s8			achSubject[KMTAPI_GM_MAX_SUBJECT+1]; ///<主题
	s8			achStartTime[KMTAPI_GM_MAX_DATETIME+1];///<开始时间
	s8			achEndTime[KMTAPI_GM_MAX_DATETIME+1];			///<结束时间
	BOOL32 bIsVideoMeeting; ///<是否是视频会议
	s8			achPhone[KMTAPI_GM_MAX_PHONE+1];				///<分机
	s8			achMobilePhone[KMTAPI_GM_MAX_MOBILE+1];			///<电话
	s8			achOrganizer[KMTAPI_GM_MAX_ORGANIZER+1];		///<创建人
	s8			achOrganigerMoid[KMTAPI_GM_MAX_MOID+1];			///<创建人moid
	TMTConfInfoRooms_Api tMTConfInfoRooms;			     	///<欲占会议室
public:
	tagTMTContentCreateMeeting_Api() { memset(this, 0, sizeof(tagTMTContentCreateMeeting_Api)); }
}*PTMTContentCreateMeeting_Api, TMTContentCreateMeeting_Api;

/** 适用于messgaeType为103 */
typedef struct tagTMTContentUpdateMeeting_Api
{
	u32   dwMeetingId; ///<会议ID
	s8     achSubject[KMTAPI_GM_MAX_SUBJECT+1]; ///<主题
	s8     achStartTime[KMTAPI_GM_MAX_DATETIME+1];///<开始时间
	s8		achEndTime[KMTAPI_GM_MAX_DATETIME+1];			///<结束时间
	s8		achOrganigerMoid[KMTAPI_GM_MAX_MOID+1];			///<创建人moid
	s8     achBrief[KMTAPI_MG_MAX_MEETING_BRIEF_LEN+1]; ///<会议概要
	s8     achBeforeSubject[KMTAPI_GM_MAX_SUBJECT+1]; ///<修改前的主题
	TMTConfInfoRooms_Api tMTConfInfoRooms;			     	///<欲占会议室
public:
	tagTMTContentUpdateMeeting_Api() { memset(this, 0, sizeof(tagTMTContentUpdateMeeting_Api)); }
}*PTMTContentUpdateMeeting_Api, TMTContentUpdateMeeting_Api;


/** 适用于messgaeType为104、108、116 */
typedef struct tagTMTContentOutMeeting_Api
{
	u32   dwMeetingId; ///<会议ID
	s8     achSubject[KMTAPI_GM_MAX_SUBJECT+1]; ///<主题
	s8		achOrganigerMoid[KMTAPI_GM_MAX_MOID+1];			///<创建人moid
public:
	tagTMTContentOutMeeting_Api() { memset(this, 0, sizeof(tagTMTContentOutMeeting_Api)); }
}*PTMTContentOutMeeting_Api, TMTContentOutMeeting_Api;

/** 适用于messgaeType为110 */
typedef struct tagTMTContentNotStartMeeting_Api
{
	u32   dwMeetingId; ///<会议ID
	s8     achSubject[KMTAPI_GM_MAX_SUBJECT+1]; ///<主题
	s8     achStartTime[KMTAPI_GM_MAX_DATETIME+1];///<开始时间
	s8		achEndTime[KMTAPI_GM_MAX_DATETIME+1];			///<结束时间
	s8		achOrganigerMoid[KMTAPI_GM_MAX_MOID+1];			///<创建人moid
	TMTConfInfoRooms_Api tMTConfInfoRooms;			     	///<欲占会议室
public:
	tagTMTContentNotStartMeeting_Api() { memset(this, 0, sizeof(tagTMTContentNotStartMeeting_Api)); }
}*PTMTContentNotStartMeeting_Api, TMTContentNotStartMeeting_Api;

/** 适用于messgaeType为111 */
typedef struct tagTMTContentDeadlineChanged_Api
{
	s8 achDeadline[KMTAPI_GM_MAX_DATETIME+1];///<现在的预定期限
public:
	tagTMTContentDeadlineChanged_Api() { memset(this, 0, sizeof(tagTMTContentDeadlineChanged_Api)); }
}*PTMTContentDeadlineChanged_Api, TMTContentDeadlineChanged_Api;

/** 适用于messgaeType为105 */
typedef struct tagTMTContentRegularMeeting_Api
{
	u32 dwRegularId;
	s8		achOrganizerMoid[KMTAPI_GM_MAX_MOID+1];			///<创建人moid
	s8     achSubject[KMTAPI_GM_MAX_SUBJECT+1]; ///<主题
	s8		achOrganizerMail[KMTAPI_MG_ORGANIZERMAIL_LEN+1]; ///<组织人Email
	s8			achOrganizer[KMTAPI_GM_MAX_ORGANIZER+1];		///<创建人
	s8			achPhone[KMTAPI_GM_MAX_PHONE+1];				///<分机
	s8     achBrief[KMTAPI_MG_MAX_MEETING_BRIEF_LEN+1]; ///<会议概要
	u32 dwStatus; ///<例会状态
	s8			achMobilePhone[KMTAPI_GM_MAX_MOBILE+1];			///<电话
	BOOL32 bIsVideoMeeting; ///<是否是视频会议
	s8     achStartTime[KMTAPI_GM_MAX_DATETIME+1];///<开始时间
	s8		achEndTime[KMTAPI_GM_MAX_DATETIME+1];			///<结束时间
	s8     achStartDate[KMTAPI_GM_MAX_DATETIME+1];///<开始日期
	u32 dwRepeatType; ///<重复规则
	u32 dwFrequency; ///<重复频率
	s8     achWeekDays[KMTAPI_GM_MAX_DATETIME+1]; ///<例会重复规则要执行的时间点
	s8		achEndDate[KMTAPI_GM_MAX_DATETIME+1];			///<结束日期
	u32  adwMeetingId[KMTAPI_GM_MAX_REGULAR_MEETING_COUNT]; //会议ID
	u16 wMeetingCount;
public:
	tagTMTContentRegularMeeting_Api() { memset(this, 0, sizeof(tagTMTContentRegularMeeting_Api)); }
}*PTMTContentRegularMeeting_Api, TMTContentRegularMeeting_Api;

/** 适用于messgaeType为106、107 */
typedef struct tagTMTContentRegularId_Api
{
	u32 dwRegularId;
public:
	tagTMTContentRegularId_Api() { memset(this, 0, sizeof(tagTMTContentRegularId_Api)); }
}*PTMTContentRegularId_Api, TMTContentRegularId_Api;

/** 适用于messgaeType为112 */
typedef struct tagTMTContentFeedback_Api
{
	u32   dwMeetingId; ///<反馈的会议ID
	s8		achMoid[KMTAPI_GM_MAX_MOID+1];			///<反馈人的moid
	EmParticipatResponse_Api emIsParticipated; ///<是否参加
	u32 dwParticipateType; ///<与会方式
	u32 dwReasonId; ///<拒绝原因
	BOOL32 bIsVideoMeeting; ///<是否是视频会议
public:
	tagTMTContentFeedback_Api() { memset(this, 0, sizeof(tagTMTContentFeedback_Api)); }
}*PTMTContentFeedback_Api, TMTContentFeedback_Api;

/** 适用于messgaeType为113、114 */
typedef struct tagTMTContentRoomId_Api
{
	u32 dwRoomId;
public:
	tagTMTContentRoomId_Api() { memset(this, 0, sizeof(tagTMTContentRoomId_Api)); }
}*PTMTContentRoomId_Api, TMTContentRoomId_Api;

/** 适用于messgaeType为109 */
typedef struct tagTMTContentMeetingId_Api
{
	u32 dwMeetingId;
public:
	tagTMTContentMeetingId_Api() { memset(this, 0, sizeof(tagTMTContentMeetingId_Api)); }
}*PTMTContentMeetingId_Api, TMTContentMeetingId_Api;


/** 115、117、118、119 */
typedef struct tagTMTContentStartMeeting_Api
{
	u32   dwMeetingId; ///<会议ID
	s8     achSubject[KMTAPI_GM_MAX_SUBJECT+1]; ///<主题
	s8     achStartTime[KMTAPI_GM_MAX_DATETIME+1];///<开始时间
	s8		achEndTime[KMTAPI_GM_MAX_DATETIME+1];			///<结束时间
	s8		achOrganizerMoid[KMTAPI_GM_MAX_MOID+1];			///<创建人moid
public:
	tagTMTContentStartMeeting_Api() { memset(this, 0, sizeof(tagTMTContentStartMeeting_Api)); }
}*PTMTContentStartMeeting_Api, TMTContentStartMeeting_Api;


/**根据ID获取会议室 */
typedef struct tagTMTRoomInfoById_Api
{					
	u32		dwId;											///<会议室ID
	s8		achName[KMTAPI_MG_MAX_MT_NAME+1];				///<会议室名称
	u32		dwPeopleAdmit;									///<会议室容纳人数
	u32		dwArea;											///<会议室面积
	s8		achPhone[KMTAPI_MG_MAX_MT_PHONE+1];				///<会议室电话
	u32		dwHasVideo;										///<是否有视频会议
	s8		achE164[KMTAPI_GM_MAX_E164+1];						
	s8		achDeviceAdmin[KMTAPI_MG_MAX_MT_NAME+1];		///<设备管理员
	s8		achAdminPhone[KMTAPI_MG_MAX_MT_PHONE+1];		///<设备管理员电话
	s8		achRemark[KMTAPI_MG_MAX_MT_REMARK+1];			///<备注
	u32		dwDeviceMask;									///<设备类型
public:
	tagTMTRoomInfoById_Api(){ memset( this, 0, sizeof(tagTMTRoomInfoById_Api) ); }
}*PTMTRoomInfoById_Api, TMTRoomInfoById_Api;
//by-qwchan-part-mtmeetingctrl end



//by-qwchan-part-mtlocalcontact begin

/**呼叫记录 */
typedef struct tagTMTCallRecord_Api
{
	u32							dwSn;					///< 唯一标识符（时间生成）
	EmMtCallRecordType_Api		emCallRecordType;   	///< 呼入，呼出，未接
	EmMtCallType_Api			emCallType;				///< 视频呼叫还是音频呼叫
	s8					        achDescribe[KMTAPI_MAX_DEV_DESC_LEN+1];			///< 条目描述
	EmConfMode_Api				emConfMode;										///< 会议类型（多点/非多点）
	s8 				            achH323Id[KMTAPI_MAX_MT_ALIAS_LEN+1];           ///< H323ID
	EmMtAddrType_Api			emAddrType;				                        ///< 是E164，还是电话，还是IP
	s8 				            achE164[KMTAPI_MAX_MT_E164_LEN+1];       	    ///< 填写相应E164
	s8 				            achIp[KMTAPI_MAX_MT_IP_LEN+1];       			///< 填写相应IP
	s8 				            achPhoneNumber[KMTAPI_MT_MAX_TELEPHONE_LEN+1];  ///< 填写相应电话
	s8 				            achMemoname[KMTAPI_MAX_DEV_MEMO_LEN+1];         ///< 填写备注名
	u32							dwRate;					                        ///< 码率
	u32							dwTime; 			                        	///< 呼叫时间

public:
	tagTMTCallRecord_Api(){ memset( this ,0 ,sizeof(tagTMTCallRecord_Api) );}
}*PTMTCallRecord_Api,TMTCallRecord_Api;

typedef struct tagTMTRecordSearch_Api
{
	EmMtRecordSearchType_Api	emType;
	TMTCallRecord_Api			tRecord;

public:
	tagTMTRecordSearch_Api(){ memset( this ,0 ,sizeof(tagTMTRecordSearch_Api) );}
}*PTMTRecordSearch_Api,TMTRecordSearch_Api;

typedef struct tagTAddrBookGroupInfo_Api
{
	u32				dwGroupSn;						               ///< 用户组序号
	s8		        achGroupName[KMTAPI_CM_MAX_GROUP_NAME_LEN+1];  ///< 用户组名称
	u32				dwParentGroupSn;  				               ///< 父组序号
	u32				dwGroupLevel;					               ///< 组的层级

public:
	tagTAddrBookGroupInfo_Api(){ memset( this ,0 ,sizeof(tagTAddrBookGroupInfo_Api) );}
}*PTAddrBookGroupInfo_Api,TAddrBookGroupInfo_Api;

typedef struct tagTAddrBookRosterInfo_Api
{
	u32					dwParentGroupSn;  			            ///< 父组序号
	u32					dwSn;						            ///< 当前人员的SN号
	s8			        achName[KMTAPI_BUF_128_LEN+1];		    ///< 条目名称
	s8			        achH323Id[KMTAPI_MAX_MT_ALIAS_LEN+1];	///< H323ID
	s8			        achE164[KMTAPI_MAX_MT_E164_LEN+1];		///< E164
	s8			        achIp[KMTAPI_MAX_MT_IP_LEN+1];			///< IP
	u32					dwRate;						            ///< 码率
	s8			        achDescribe[KMTAPI_MAX_DEV_DESC_LEN+1];	///< 条目描述
	s8                  achTele[KMTAPI_MAX_TELE_INFO_LEN+1];    ///< 电话

public:
	tagTAddrBookRosterInfo_Api(){ memset( this ,0 ,sizeof(tagTAddrBookRosterInfo_Api) );}
}*PTAddrBookRosterInfo_Api,TAddrBookRosterInfo_Api;

typedef struct tagTMTRecordErrInfo_Api
{
	EmMtRecordErr_Api	emError;

public:
	tagTMTRecordErrInfo_Api(){ memset( this ,0 ,sizeof(tagTMTRecordErrInfo_Api) );}
}*PTMTRecordErrInfo_Api,TMTRecordErrInfo_Api;

typedef struct tagTMTCallRecordList_Api
{
	u8          byCnt;
	TMTCallRecord_Api			atRecord[KMTAPI_CM_MAX_RECORD_NUM];
public:
	tagTMTCallRecordList_Api(){ memset( this ,0 ,sizeof(tagTMTCallRecordList_Api) );}
}*PTMTCallRecordList_Api,TMTCallRecordList_Api;

typedef struct tagTRecordSearchInfoAndList_Api
{
	TMTRecordSearch_Api			tSearchInfo;						///< 记录搜索信息
	TMTCallRecordList_Api		tRecordList;						///< 记录搜索结果列表

public:
	tagTRecordSearchInfoAndList_Api(){ memset( this ,0 ,sizeof(tagTRecordSearchInfoAndList_Api) );}
}*PTRecordSearchInfoAndList_Api,TRecordSearchInfoAndList_Api;

typedef struct tagTAddrBookRosterList_Api
{
	u8		byCnt;
	TAddrBookRosterInfo_Api		atArray[KMTAPI_CM_MAX_ROSTER_NUM];

public:
	tagTAddrBookRosterList_Api(){ memset( this ,0 ,sizeof(tagTAddrBookRosterList_Api) );}
}*PTAddrBookRosterList_Api,TAddrBookRosterList_Api;

typedef struct tagTAddrBookGroupList_Api
{
	u8    byCnt;
	TAddrBookGroupInfo_Api		atArray[KMTAPI_CM_MAX_GROUP_NUM];

public:
	tagTAddrBookGroupList_Api(){ memset( this ,0 ,sizeof(tagTAddrBookGroupList_Api) );}
}*PTAddrBookGroupList_Api,TAddrBookGroupList_Api;

typedef struct tagTGroupAndRosterList_Api
{
	TAddrBookGroupList_Api			tGroupList;			///< 错误描述
	TAddrBookRosterList_Api			tRosterList;		///< 错误描述

public:
	tagTGroupAndRosterList_Api(){ memset( this ,0 ,sizeof(tagTGroupAndRosterList_Api) );}
}*PTGroupAndRosterList_Api,TGroupAndRosterList_Api;

typedef struct tagTAppGetAllNotifysAck_Api
{
	u32 dwNotifyCnt;
	EmRestNotifyType_Api emNotifyType;
public:
	tagTAppGetAllNotifysAck_Api(){ memset( this ,0 ,sizeof(tagTAppGetAllNotifysAck_Api) );}
}*PTAppGetAllNotifysAck_Api,TAppGetAllNotifysAck_Api;

typedef struct tagTAppGetAllNotifysAckList_Api
{
	u8 byListCnt;
	TAppGetAllNotifysAck_Api tNotifyList[KMTAPI_COUNT_8];
public:
	tagTAppGetAllNotifysAckList_Api() { memset( this, 0, sizeof(tagTAppGetAllNotifysAckList_Api) );}
}*PTAppGetAllNotifysAckList_Api, TAppGetAllNotifysAckList_Api;

/** 视频会议信息 */
typedef struct tagTMTVideoConferenceInfo_Api
{
	u32		dwShortNO;
	u32		dwState;
	u32		dwIsAutoCall;
	s8		achE164[KMTAPI_GM_MAX_E164+1];
	s8		achTemplate_id[KMTAPI_GM_MAX_TEMPLATEID+1];
	s8		achTemplate_name[KMTAPI_GM_MAX_TEMPLATENAME+1];
	s8		achPassword[KMTAPI_GM_MAX_COMMON+1];
    EmMtOpenMode_Api		        emMeetingSafe;                          ///<会议安全mode
    EmEncryptArithmetic_Api			emEncryptedType;                        ///<会议加密方式
    s8								achEncryptedKey[ KMTAPI_BUF_32_LEN+1 ]; ///<会议秘钥
    EmMeetingSafeType_Api		    emMeetingType;                          ///<会议是否是 端口会议          
    EmClosedMeeting_Api             emClosedMeeting;                        ///<会议免打扰，1开启，0关闭
    EmVideoQuality_Api              emVideoQuality;                         ///<视频质量,0：质量优先；1：速度优先
    EmMtDualMode_Api                emDualMode;                             ///<双流权限
    BOOL32                          bInitMute;                              ///< 初始化哑音：1是，0否
    BOOL32							bPublicMeeting;                   ///< 是否是公共会议室
    u32 dwMeetingScale;                                                   ///< 会议规模,0：空，1：4方视频会议,2：8方视频会议,3：大型视频会议
    u32 dwOneReforming;                                                 ///< 归一重整,0:关闭; 1:开启
    u32						        dwVideoCount;
    TMTVideoFormatList_Api          atVideoFormatList[KMTAPI_COUNT_16];
    u32						        dwAudioCount;
    TMTAudioFormatList_Api          atAudioFormatList[KMTAPI_COUNT_16];
    u32                             dwDualCount;
    TMTDualFormatList_Api           atDualFormatList[KMTAPI_COUNT_8];      ///< 双流频格式列表
    TMTGetMixInfo_Api		    tMixInfo;                             ///< 混音相关信息
    TMTCreateConfVmp_Api    tVmp;                                  ///< 画面合成设置

    TMTCreateConfPoll_Api   tPoll;                                 ///< 轮询设置
    u32                     dwVipCount;
    TMTCreateConfMember_Api atVipList[KMTAPI_COUNT_256];           ///< vip成员列表


    TMTCreateConfMember_Api tSpeaker;   ///< 发言人
    TMTCreateConfMember_Api tAdmin;     ///< 管理方
    u32 dwCallTimes;                    ///< 呼叫次数
    u32 dwCallInterval;                 ///< 呼叫间隔(秒)
    BOOL32 bCallChase;                  ///< 是否追呼：1是，0否
    BOOL32 bVoiceInspireEnable; ///< 是否开启语言激励：1是，0否
    u32 dwVoiceInspireTime;         ///< 语言激励敏感度
    EmRestCascadeMode_Api emCascadeMode;///< 级联模式,0简单级联，1合并级联
    BOOL32 bCascadeUpload;              ///< 是否级联上传:1是，0否
    BOOL32 bCascadeReturn;              ///< 是否级联回传:1是，0否
    u32 dwCascadeReturnPara;            ///< 级联回传带宽参数
    TMTCreateRecordRecord_Api      tRecord;                    ///< 录像设置 
    TMTCreateConfMultiCast_Api     tMultiCast;                 ///< 主播设置
    TMTCreateConfSatellite_Api	   tSatellite;                 ///<卫星会议设置
    u32 dwCallChaseMemberCount;
    TMTCreateConfMember_Api atCallChaseList[KMTAPI_COUNT_128]; ///< 追呼为是时的追呼成员列表

public:
	tagTMTVideoConferenceInfo_Api(){ memset( this, 0, sizeof(tagTMTVideoConferenceInfo_Api) ); }
}*PTMTVideoConferenceInfo_Api, TMTVideoConferenceInfo_Api;


/** 根据Id获取会议详细信息(基本信息+会议室信息) */
typedef struct tagTMTConfInfoById_Api
{
	u32	dwId;										    	///<会议ID
	u32	dwStatus;	
	u32	dwIsVideo;

	s8	achSubject[KMTAPI_GM_MAX_SUBJECT+1];				///<会议主题
	s8	achStartTime[KMTAPI_GM_MAX_DATETIME+1];				///<开始时间
	s8	achEndTime[KMTAPI_GM_MAX_DATETIME+1];				///<结束时间
	s8	achOrganizerMoid[KMTAPI_GM_MAX_MOID+1];
	s8	achOrganizer[KMTAPI_GM_MAX_ORGANIZER+1];
	s8	achOrganizerMail[KMTAPI_GM_MAX_ORGANIZERMAIL+1];
	s8	achPhone[KMTAPI_GM_MAX_PHONE+1];
	s8	achMobile[KMTAPI_GM_MAX_MOBILE+1];
	s8	achBrief[KMTAPI_MG_MAX_MEETING_BRIEF_LEN+1];

	TMTConfInfoRooms_Api tMTConfInfoRooms;
	TMTVideoConferenceInfo_Api tMTVideoConfInfo;

public:
	tagTMTConfInfoById_Api(){ memset( this, 0, sizeof(tagTMTConfInfoById_Api) ); }
}*PTMTConfInfoById_Api, TMTConfInfoById_Api;

typedef struct tagTRegularFeedAck_Api
{
	u32    dwRegularId;
	u32    dwJoinType;
	BOOL32 bAccept;

public:
	tagTRegularFeedAck_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTRegularFeedAck_Api, TRegularFeedAck_Api;

//by-qwchan-part-mtlocalcontact end

//by-lw-part-mtsysctrl begin
/** 子系统信息 */
typedef struct tagTStartUpServiceInfo_Api
{
	u32 dwMtAid;			                                                        ///< 每个子系统代表的MTAID号
	s8  achPath[KMTAPI_MAX_PATH_FILE_NAME_LEN+1];			                        ///<  子系统库的完整路径
	s8 achSysalias[KMTAPI_SYS_MAX_SYSNAME_LEN+1];			                        ///<  子系统别名
	EmMtSysStartMod_Api emStartmod;    		                                        ///<  子系统启动方式（线程加载/进程加载）
	s8 achSrtfuncname[KMTAPI_SYS_MAX_STARTFUN_NAME_LEN+1];		                    ///<  启动函数名称
	s8 achEndfuncname[KMTAPI_SYS_MAX_STOPFUN_NAME_LEN+1];		                    ///<  结束函数名称
public:
	tagTStartUpServiceInfo_Api()	{ memset( this, 0, sizeof(*this) ); }

}*PTStartUpServiceInfo_Api, TStartUpServiceInfo_Api;

typedef struct tagTMutiTStartUpServiceInfo_Api
{
	tagTStartUpServiceInfo_Api    atSvcInfo[KMTAPI_SYS_MAX_MTSERVICE_NUM];        ///< 子系统信息
	u16                           byCnt;                                          ///< 子系统数量
public:
	tagTMutiTStartUpServiceInfo_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTMutiTStartUpServiceInfo_Api, TMutiTStartUpServiceInfo_Api;

/** 保持心跳信息 */
typedef struct  tagTSrvKeepLiveInfo_Api
{
	s8 achSysalias[KMTAPI_SYS_MAX_SYSNAME_LEN+1];
	u32 dwMtAid;
	u32 dwTime;
public:
	tagTSrvKeepLiveInfo_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTSrvKeepLiveInfo_Api, TSrvKeepLiveInfo_Api;


/** 保存在默认映射表中的一个子系统内容 */
typedef struct tagTServiceDefInfo_Api
{
	u32 dwIndex;			                                                        ///<  索引号
	s8 achPath[KMTAPI_MAX_PATH_FILE_NAME_LEN+1];			                        ///<  子系统库的完整路径
	s8 achSysalias[KMTAPI_SYS_MAX_SYSNAME_LEN+1];			                        ///<  子系统别名
	EmMtSysStartMod_Api emStartmod;		                                            ///<  子系统启动方式（线程加载/进程加载）
	s8 achSrtfuncname[KMTAPI_SYS_MAX_STARTFUN_NAME_LEN+1];		                    ///<  启动函数名称
	s8 achEndfuncname[KMTAPI_SYS_MAX_STOPFUN_NAME_LEN+1];		                    ///<  结束函数名称
public:
	tagTServiceDefInfo_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTServiceDefInfo_Api, TServiceDefInfo_Api;

/** 多个保存在默认映射表中的子系统列表 */
typedef struct tagTMutiTServiceDefInfo_Api
{
	TServiceDefInfo_Api    atSvcDefInfo[KMTAPI_SYS_MAX_MTSERVICE_NUM];        ///< 子系统信息
	u16                    byCnt;                                             ///< 子系统数量
public:
	tagTMutiTServiceDefInfo_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTMutiTServiceDefInfo_Api, TMutiTServiceDefInfo_Api;

/**  用于界面传参数下来 */
typedef struct tagTMTInfo_Api
{
	u32		dwpid;
	u32		dwhid;
	s8		achname[KMTAPI_BUF_64_LEN+1];   ///< 终端名字
public:
	tagTMTInfo_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTMTInfo_Api, TMTInfo_Api;

typedef struct tagTMTUsedPort_Api
{
	u32 dwPort;
	s8  achName[KMTAPI_BUF_64_LEN+1];
public:
	tagTMTUsedPort_Api() { memset( this, 0, sizeof( *this)); }
}*PTMTUsedPort_Api, TMTUsedPort_Api;

typedef struct tagTMTUsedPortList_Api
{
	EmPortType_Api emPortType;
	TMTUsedPort_Api atTMTUsedPort[KMTAPI_MAX_PORT_NUM];
	u8 byCount;
public:
	tagTMTUsedPortList_Api() { memset( this, 0, sizeof( *this)); }
}*PTMTUsedPortList_Api, TMTUsedPortList_Api;


typedef struct tagTMTTotalUsedPort_Api
{
	TMTUsedPortList_Api atMTUsedPortList[emPortTypeEnd_Api];
	u8 byCount;

public:
	tagTMTTotalUsedPort_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTTotalUsedPort_Api, TMTTotalUsedPort_Api;

typedef struct tagTMTSrvInfo_Api
{
	s8                 achName[KMTAPI_BUF_32_LEN+1];
	s8                 achDomain[KMTAPI_BUF_128_LEN+1];
	EmServerType_Api   emSrvType;
	u32                dwIP;
	EmServerState_Api  emState;
	BOOL32             bUsed;
public:
	tagTMTSrvInfo_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTSrvInfo_Api,TMTSrvInfo_Api;

typedef struct tagTMTSrvInfoList_Api
{
	u8    byCnt ;  ///<实际服务器个数
	TMTSrvInfo_Api atServerList[KMTAPI_MAX_SERVER_NUM];
public:
	tagTMTSrvInfoList_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTSrvInfoList_Api,TMTSrvInfoList_Api;

typedef struct tagTMtSvrType_Api
{
	u32 dwSqn;                     ///<序列号
	EmServerType_Api emSrvType;    ///<服务器类型

public:
	tagTMtSvrType_Api() { memset( this, 0, sizeof(*this)); }

}TMtSvrType_Api;

typedef struct tagTMTServiceInfo_Api
{
	u32 dwIndex;			///< 索引号
	u32 dwMtaid;			///< 每个子系统代表的MTAID号
	s8  achPath[KMTAPI_MAX_PATH_FILE_NAME_LEN+1];			///<  子系统库的完整路径
	s8  achSysAlias[KMTAPI_BUF_32_LEN+1];			        ///<  子系统别名
	EmMtSysStartMod_Api      emStartmod;		            ///<  子系统启动方式（静态库加载/动态库加载/进程加载）
	s8 achSrtFuncName[KMTAPI_BUF_32_LEN+1+1];		        ///<  启动函数名称
	s8 achEndFuncName[KMTAPI_BUF_32_LEN+1+1];	        	///<  结束函数名称
	EmMtSysSrvState_Api      emSrvState;		            ///<  子系统状态（空闲/是否绑定/运行/停止/异常）
	EmMtSysKeepLiveState_Api emSrvLiveState;	            ///<  子系统存活状态（准备就绪/存活/异常）
	u32 dwDetectTime;			          ///<  子系统心跳检测频率
	u32 dwTimeStamp;			          ///<  用于检测心跳的时间戳
	u32 dwDllHandler;		              ///<  加载动态库创建的句柄，用于销毁
	u32 dwProcesspId;          			  ///<  进程号
	s8  achVersion[KMTAPI_BUF_16_LEN+1];  ///<  版本号
public:
	tagTMTServiceInfo_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTServiceInfo_Api, TMTServiceInfo_Api; 

typedef struct tagTMutiTServiceInfoRtData_Api
{
	TMTServiceInfo_Api atSrvInfo[KMTAPI_MAX_APP_NUM];
	u8 byCnt;
public:
	tagTMutiTServiceInfoRtData_Api() { memset( this, 0, sizeof(*this)); }
}*PTMutiTServiceInfoRtData_Api,TMutiTServiceInfoRtData_Api;


/** 一个通道的信息*/
typedef struct  tagTMTOneChanDSInfo_Api
{
	EmMtChanState_Api       emState;           ///<chan状态
	EmMtChanType_Api        emChanType;        ///<通道类型
	EmChanIndex_Api         emIndex;
	BOOL32                  bActive;                                   ///<active还是非active,  默认科达产品， 收到conneceted消息， chanactive为true
	s8                      abyEncryKey[KMTAPI_BUF_64_LEN+1];          ///<是否加密，长度为0 表示不加密
	EmAudFormat_Api         emAudFormat;          ///<音频格式
	EmAacChnlNum_Api        emAacChnlNum;         ///<aac声道数

	EmMtVidLabel_Api        emVidLabel;           ///<label
	EmVidFormat_Api         emVidFormat;          ///<格式
	EmMtResolution_Api      emVidResolution;      ///<分辨率
	u32                     dwFrame;              ///<帧率
	u32                     dwH264Profile;        ///<264profile值
	EmEncryptArithmetic_Api emEncrypt;            ///<加密类型
	u16                     wChanBitrate;         ///<通道码率
public:
	tagTMTOneChanDSInfo_Api() { memset( this, 0, sizeof( *this )); }
}*PTMTOneChanDSInfo_Api, TMTOneChanDSInfo_Api;

/** 所有的通道信息*/
typedef struct tagTMutiChanDsInfo_Api
{
	u8 byCnt;
	TMTOneChanDSInfo_Api  atChanInfo[KMTAPI_MAX_MULTI_CHANNEL_NUM];
public:
	tagTMutiChanDsInfo_Api() { memset( this, 0, sizeof(*this)); }
}*PTMutiChanDsInfo_Api, TMutiChanDsInfo_Api;


//by-lw-part-mtsysctrl end

//by-lw-part-硬终端 begin

/** 视频输出制式（只有硬终端使用）*/
typedef struct tagTHDMTVideoOutPortMode_Api
{
	EmHDVideoOutputMode_Api emFirst_priom_video_res;         ///<第一路主视频video输出分辨率
	EmHDVideoOutputMode_Api emFirst_priom_vga_res;           ///<第一路主视频vga输出分辨率
	EmHDVideoOutputMode_Api emSecond_priom_video_res;        ///<第二路主视频video输出分辨率
	EmHDVideoOutputMode_Api emSecond_priom_vga_res;          ///<第二路主视频vga输出分辨率
	EmHDVideoOutputMode_Api emAss_video_res;                 ///<辅视频输出分辨率
public:
	tagTHDMTVideoOutPortMode_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTHDMTVideoOutPortMode_Api, THDMTVideoOutPortMode_Api;

/** 当前使用的横幅id号*/
typedef struct tagTHDMTEnablePresetBanner_Api
{
	u32 dwBannerIndex;     ///<当前使用的横幅id号
	BOOL32 bEnable;        ///<是否启用此id的横幅
public:
	tagTHDMTEnablePresetBanner_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTHDMTEnablePresetBanner_Api, THDMTEnablePresetBanner_Api;

/** 台标和横幅的文字及格式*/
typedef struct tagTHDMTStringAndTextFormat_Api
{
	s8  achFacenametype[KMTAPI_BUF_16_LEN+1]; ///<字体类型
	s8  achTextcolor[KMTAPI_BUF_16_LEN+1];    ///<字体颜色
	s8  achTextsize[KMTAPI_BUF_16_LEN+1];     ///<字体大小
	BOOL32 bTextBold;       ///<粗体
	BOOL32 bTextItalic ;    ///<斜体
	BOOL32 bTextUnderline;  ///<下划线
	s8 achTextContent[KMTAPI_BUF_1024_LEN+1];   ///<文字内容
    BOOL32 bIsWrap; ///< 自动换行
public:
	tagTHDMTStringAndTextFormat_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTHDMTStringAndTextFormat, THDMTStringAndTextFormat_Api;




/** 横幅*/
typedef struct tagTHDMTBannerInfo_Api
{
	BOOL32 bEnable;			                        ///< 使能(MT_ENABLE/MT_DISABLE)
	u32 dwUseType;				                    ///<使用类型(0:文字横幅，1:自定义图片横幅)
	s8  achBkColor[KMTAPI_BUF_32_LEN+1];			///< 背景色
	EmHDTextAlign_Api emTextAlign;	                ///< 文字对齐模式(TEXT_ALIGN_LEFT/TEXT_ALIGN_CENTER/TEXT_ALIGN_RIGHT)
	EmHDRollMode_Api emRollMode;		            ///< 滚动模式(ROLL_NOT_ROLL/ROLL_RIGHT_LEFT/ROLL_DOWN_UP)
	u32 dwTransParent;                              ///< 透明度
	EmHDRollSpeed_Api emRollSpeed;		            ///< 滚动速度(ROLL_SPEED_SLOW/ROLL_SPEED_NORMAL/ROLL_SPEED_FAST/ROLL_SPEED_FASTER)
	u32 dwRollNum;			                        ///< 滚动次数(0:表示无限制滚动,1~255:表示用户指定的滚动次数)
	u32	dwStayTime;			                        ///< 停留时间(0:表示不停留,1~255:表示用户指定的时间,单位秒)
	TMTSymboPoint_Api tBannerCoordinate;            ///<横幅位置坐标位置
	u32	dwDisplayWidth;		                        ///< 字幕显示区域的宽(以象素为单位)
	u32 dwDisplayHeight;	                        ///< 字幕显示区域的高(指行高,以象素为单位)
	u32 dwTextLineSpace;			                ///<行间距，默认单倍行距，(0:代表1.0，1:代表1.5,以此类推)
	u32 dwTextDisplayRatio;                         ///<显示比例(百分比,默认100)
	THDMTStringAndTextFormat_Api  atBannerContext[KMTAPI_COUNT_64]; ///<存放横幅内容,以及文字格式,使用repeated是由于每一行文字都可以设置不同的大小等文字格式
	u8 byCnt;
	s8  achPictureName[KMTAPI_BUF_256_LEN+1];	    ///<使用图片时，图片的名称
	s8  achPresetBannerName[KMTAPI_BUF_128_LEN+1];	///<方案名称
	u32 dwPresetBannerIndex;	                    ///<方案(从0开始)
	u32 dwTextLineNum; ///<文字横幅显示文字的行数（默认1行）
public:
	tagTHDMTBannerInfo_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTHDMTBannerInfo_Api, THDMTBannerInfo_Api;

/** 横幅列表*/
typedef struct tag_THDMTBannerInfoList_Api
{
	THDMTBannerInfo_Api atMtBannerInfoList[KMTAPI_BANNER_INFO_LIST_MAX_NUM];
	u8 byCnt;
public:
	tag_THDMTBannerInfoList_Api() { memset( this, 0, sizeof(*this));}
}*PTHDMTBannerInfoList_Api, THDMTBannerInfoList_Api;


/** 台标*/
typedef struct tagTHDMTLabelInfo_Api
{
	EmLabelType_Api       emLabelType;      ///<台标类型
	TMTSymboPoint_Api  tLableCoordinate;    ///< 自定义台标位置
	EmLabelPosType_Api    emLabelPosType;   ///<终端别名台标位置
	THDMTStringAndTextFormat_Api atCustomLabelContent[KMTAPI_BUF_16_LEN]; ///<自定义台标内容
	u8 byCnt;
	s8 achPicName[KMTAPI_BUF_128_LEN + 1];          //使用自定义图片时，图片的名称
	s8 achAutoTextContent[KMTAPI_BUF_128_LEN + 1];  //终端别名台标内容
public:
	tagTHDMTLabelInfo_Api()	{ memset( this, 0, sizeof(*this) ); }
}*TTHDMTLabelInfo_Api, THDMTLabelInfo_Api;

/** 自动待机*/
typedef struct tagTHDMTAutoSleep_Api
{
	BOOL32 bEnable;             ///<是否开启自动待机功能
	u32  dwTimeOut;             ///<待机前等待时间
	BOOL32 bAllowCall;			///<待机时是否允许呼叫
public:
	tagTHDMTAutoSleep_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTHDMTAutoSleep_Api, THDMTAutoSleep_Api;

/** 系统时间*/
typedef struct tagTHDMTCfgSystemTime_Api
{
	BOOL32 bSyncServer;                      ///< 是否同步服务器时间	
	EmTimeZone_Api emTimeZoneType;           ///<当前时区
public:
	tagTHDMTCfgSystemTime_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTHDMTCfgSystemTime_Api, THDMTCfgSystemTime_Api;

/** 音频输入端口*/
typedef struct tagTMTHDAudInPort_Api
{
	EmHDAudPortIn_Api aemAudInPortList[KMTAPI_BUF_32_LEN];            ///<音频输入接口
	u8 byCnt;
public:
	tagTMTHDAudInPort_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTMTHDAudInPort_Api, TMTHDAudInPort_Api;

/** 音频输入端口*/
typedef struct tagTMTHDAudInPortList_Api
{
	TMTHDAudInPort_Api tPriMicPortList;  ///<主麦克音频输入接口
	TMTHDAudInPort_Api tLineInPortList;  ///<线性音频输入接口
	BOOL32 bIsAuxMic; ///<AUX_TRS3.5是否为mic
	BOOL32 bIsLineMic; ///<LINE_RCA是否为mic
public:
	tagTMTHDAudInPortList_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTMTHDAudInPortList_Api, TMTHDAudInPortList_Api;


typedef struct tagTMTHDVidInPortCap_Api
{
	EmHDVideoType_Api emVideoType; ///<视频源种类
	EmMtVideoPort_Api atVideoPort[KMTAPI_MAX_VIDEO_PORT];  ///<视频输入接口
	u8                    byCnt;
public:
	tagTMTHDVidInPortCap_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTMTHDVidInPortCap_Api, TMTHDVidInPortCap_Api;

/**视频接口能力列表*/
typedef struct tagTMTHDVidInPortCapList_Api
{
	TMTHDVidInPortCap_Api atVideoCapList[KMTAPI_MAX_VIDEO_CAP_LIST];
	u8                    byCnt;
public:
	tagTMTHDVidInPortCapList_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTMTHDVidInPortCapList_Api, TMTHDVidInPortCapList_Api;


/**音频输出端口*/
typedef struct  tagTHDMTHDAudOutPortList_Api
{
	EmHDAudPortOut_Api aemAudOutPortList[KMTAPI_BUF_32_LEN]; ///<音频输出接口
	u8 byCnt;
public:
	tagTHDMTHDAudOutPortList_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTHDMTHDAudOutPortList_Api, THDMTHDAudOutPortList_Api;

/** 主或辅视频输入端口*/
typedef struct tagTHDMTHDVidInPort_Api
{
	EmHDVideoType_Api emVideoType;               ///<视频源种类
	EmMtVideoPort_Api emVideoInPort;             ///<视频输入接口
public:
	tagTHDMTHDVidInPort_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTHDMTHDVidInPort_Api, THDMTHDVidInPort_Api;

/** 多视或多流*/
typedef struct tagTMTHDMultiVideo_Api
{
	EmHDMultiVideoSwitch_Api emMVType;                             ///<多流多视种类
	EmHDMultiViewMP_Api emVMPType;                                 ///<多视的画面风格
	EmMtVideoPort_Api aemVideoInPortList[KMTAPI_BUF_32_LEN];       ///<视频输入接口,允许多个
	u8 byCnt;
public:
	tagTMTHDMultiVideo_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTMTHDMultiVideo_Api, TMTHDMultiVideo_Api;

/** 视频输出显示比例*/
typedef struct tagTHDMTDisplayRatio_Api
{
	EmHDVideoType_Api emVideoType;                                     ///<视频种类
	EmDisplayRatio_Api emRatio;                                        ///<视频输出显示比例
public:
	tagTHDMTDisplayRatio_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTHDMTDisplayRatio_Api, THDMTDisplayRatio_Api;

typedef struct tagTMTVidInPortMode_Api
{
	EmMtVideoPort_Api emVideoInPort;   ///<视频输入口
	EmHDVideoPortMode_Api emInPortMode;	///<输入口类型
public:
	tagTMTVidInPortMode_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTVidInPortMode_Api, TMTVidInPortMode_Api;

typedef struct tagTMTVidOutPortMode_Api
{
	EmHDVideoOutPortType_Api emVideoOutPort; ///<视频输出口
	EmHDVideoPortMode_Api emOutPortMode;	 ///<输出口类型
public:
	tagTMTVidOutPortMode_Api() { memset(this, 0, sizeof(*this)); }
}*PTMTVidOutPortMode_Api, TMTVidOutPortMode_Api;

typedef struct tagTMTVideoOutPort2InPort_Api
{
	EmHDVideoOutPortType_Api emVideoOutPort; ///<视频输出口
	EmHDVideoSourceType_Api emVideoOutType;	 ///<输出口对应的输入口内容
public:
	tagTMTVideoOutPort2InPort_Api() { memset(this, 0, sizeof(*this));}
}*PTMTVideoOutPort2InPort_Api, TMTVideoOutPort2InPort_Api;

typedef struct tagTMTVideoMatrixScheme_Api
{
	u32 dwSchemeID;                         ///<矩阵id
	s8	achSchemeName[KMTAPI_BUF_64_LEN+1]; ///<矩阵名字
	u8 byInPortCnt; 
	TMTVidInPortMode_Api atInPortMode[KMTAPI_BUF_32_LEN];           ///<视频输入口模式
	u8 byOutPortCnt; 
	TMTVidOutPortMode_Api atOutPortMode[KMTAPI_BUF_32_LEN];         ///<视频输出口模式
	u8 byOutPort2InPortCnt;
	TMTVideoOutPort2InPort_Api atOutPort2InPort[KMTAPI_BUF_32_LEN]; ///<输出接口对应的输入图像
public:
	tagTMTVideoMatrixScheme_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTVideoMatrixScheme_Api, TMTVideoMatrixScheme_Api;

/** 所有视频矩阵模板*/
typedef struct tagTHDMTAllVideoMatrixScheme_Api
{
	u32 dwSchemeID;                                                            ///<当前启用的矩阵模版id
	TMTVideoMatrixScheme_Api atMatrixScheme[KMTAPI_BUF_256_LEN];               ///<所以矩阵模版
	u8 byCnt;                                                                  ///<模板总数
public:
	tagTHDMTAllVideoMatrixScheme_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTHDMTAllVideoMatrixScheme_Api, THDMTAllVideoMatrixScheme_Api;

/** 无图像显示策略*/
typedef struct tagTHDMTLastDisplay_Api
{
	EmHDLastDisplay_Api emLastDisplayType;                   ///<显示模式
	u32 dwWaitTimer;                                         ///<无图像策略等待时间（秒）
public:
	tagTHDMTLastDisplay_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTHDMTLastDisplay_Api, THDMTLastDisplay_Api;

/** 图像降噪等级*/
typedef struct tagTHDMTImageNoise_Api
{
	EmHDImageNoise_Api emNoiseLevel;                             ///<降噪等级
public:
	tagTHDMTImageNoise_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTHDMTImageNoise_Api, THDMTImageNoise_Api;

/** 视频变形拉伸*/
typedef struct tagTMTHDImageDeformationTensile_Api
{
	EmCodecComponent_Api emCodecType;                                ///<视频种类
	EmCodecComponentIndex_Api emCodecIndex; ///<码流索引
	u32 dwHoriNum; ///<水平拉伸，取数16为中值，大于中值则表示放大，小于表示缩小
	u32 dwVertiNum; ///<垂直拉伸，取数16为中值，大于中值则表示放大，小于表示缩小
public:
	tagTMTHDImageDeformationTensile_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTHDImageDeformationTensile_Api, TMTHDImageDeformationTensile_Api;

/** 视频等比缩放*/
typedef struct tagTMTHDImageGeometricScaling_Api
{
	EmCodecComponent_Api emCodecType;                                ///<视频种类
	EmCodecComponentIndex_Api emCodecIndex; ///<码流索引
	u32 dwNumber;                                                 ///<取一个数为中值，大于中值则表示放大，小于表示缩小
public:
	tagTMTHDImageGeometricScaling_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTHDImageGeometricScaling_Api, TMTHDImageGeometricScaling_Api;

/** 摄像机配置*/
typedef struct tagTMTHDCameraCfg_Api
{
	EmMtVideoPort_Api emVideoPortIndex;
	s8 achCameraTypeName[KMTAPI_BUF_256_LEN+1];                   ///<摄像机类型(摄像机名字由业务主动上报，配置文件默认为通用)
	u32 dwAddress;                                                ///<菊花链位置
	u32 dwSpeed;                                                  ///<速度（快、中、慢）
	EmHDSerialType_Api emSerialType;                              ///<串口类型
	u32 dwIp;													  ///<智能摄像机IP
	u32 dwPort;													  ///<智能摄像机端口
public:
	tagTMTHDCameraCfg_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTHDCameraCfg_Api, TMTHDCameraCfg_Api;

/** 摄像机配置列表*/
typedef struct tagTMTHDCameraList_Api
{
	TMTHDCameraCfg_Api atCameralist[KMTAPI_BUF_32_LEN];            ///<摄像机配置
	u8 byCnt;
public:
	tagTMTHDCameraList_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTHDCameraList_Api, TMTHDCameraList_Api;

/** 串口配置*/
typedef struct tagTMTHDSerialCtrl
{
	EmHDSerialType_Api emSerialType;                                ///<串口类型 
	u32 dwBandRate;                                                 ///<波特率
	u32 dwByteSize;                                                 ///<数据位
	EmHDStopBits_Api emStopBits;                                    ///<停止位
	EmHDParityCheck_Api emParityCheck;                              ///<校验算法
public:
	tagTMTHDSerialCtrl() { memset( this, 0, sizeof(*this)); }
}*PTMTHDSerialCtrl_Api, TMTHDSerialCtrl_Api;

typedef struct tagTMTHDSerialList_Api
{
	TMTHDSerialCtrl_Api atSeriallist[KMTAPI_BUF_32_LEN];            ///<串口
	u8 byCnt;
public:
	tagTMTHDSerialList_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTHDSerialList_Api, TMTHDSerialList_Api;



//by-lw-part-硬终端 end

typedef struct tagTMTBandWidthTest_Api
{
	BOOL32 bEnable;
	u32    dwUpWidth;
	u32    dwDownWidth;
public:
	tagTMTBandWidthTest_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTBandWidthTest_Api, TMTBandWidthTest_Api;

typedef struct tagTMTCallBitRate_Api
{
	u32 dwRateCount;
	u32 adwRate[KMTAPI_BUF_16_LEN];
public:
	tagTMTCallBitRate_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTCallBitRate_Api, TMTCallBitRate_Api;

/** 登录策略*/
typedef struct tagTMTLoginTactic_Api
{
	EmServerType_Api emSvrType;                             ///<描述服务器
	EmServerType_Api aemPreSvrList[KMTAPI_MAX_DECODE_NUM];  ///<前置服务器列表
	u8               byCnt;                                 ///<前置服务器列表长度
	BOOL32           bUsed;
public:
	tagTMTLoginTactic_Api() { memset( this , 0, sizeof(*this)); }
}*PTMTLoginTactic_Api, TMTLoginTactic_Api;

typedef struct tagTMtLoginTacticsTable_Api
{
	u32					dwCount;
	TMTLoginTactic_Api atLoginTactic[emServerTypeEnd_Api];
public:
	tagTMtLoginTacticsTable_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtLoginTacticsTable_Api, TMtLoginTacticsTable_Api;


typedef struct tagTMTAllVideoDecoderParamCfg_Api
{
	u32 dwDecodeNum;
	TMTVideoDecoderParamCfg_Api atDecodeParam[KMTAPI_MAX_DECODE_NUM];
public:
	tagTMTAllVideoDecoderParamCfg_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTAllVideoDecoderParamCfg, TMTAllVideoDecoderParamCfg_Api;


typedef struct tagTMTSatelliteFlag_Api
{
	BOOL32  bSatelliteMt;       ///<是否是卫星终端
	BOOL32  bP2PEnable;         ///<卫星终端是否有点对点会议权限
public:
	tagTMTSatelliteFlag_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTSatelliteFlag_Api, TMTSatelliteFlag_Api;

typedef struct tagTMTAudioPower_Api
{
	EmCodecComponent_Api emStreamType;
	EmCodecComponentIndex_Api emStreamIdx;
	u32 dwPower;
public:
	tagTMTAudioPower_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTAudioPower_Api, TMTAudioPower_Api;


/** 登陆云平台密码*/
typedef struct tagTMtLoginPlatformPwdCfg_Api
{
	BOOL32 bIsModifyEnable;                           ///<是否允许修改密码
	s8 achPassword[KMTAPI_MAX_USERPWD_LEN+1];         ///<密码
public:
	tagTMtLoginPlatformPwdCfg_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtLoginPlatformPwdCfg_Api, TMtLoginPlatformPwdCfg_Api;

typedef struct tagTMtAudEncStatistic_Api
{
	EmCodecComponentIndex_Api emAudEncId; ///<音频编码器id
	u32                       dwEncRate;  ///<编码码率
	EmAudFormat_Api emAudEncType;         ///<音频协议
	BOOL32			bAudioEncStart;      ///<是否开始音频编码
	EmAacChnlNum_Api  emChnl_num;           ///< 如果是lc,ld，声道数


public:
	tagTMtAudEncStatistic_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtAudEncStatistic_Api, TMtAudEncStatistic_Api;

typedef struct tagTMtAudDecStatistic_Api
{
	EmCodecComponentIndex_Api emAudDecId;  ///<音频解码器id
	u32                dwDecRate;          ///<解码码率
	u32                dwRecFrames;        ///<收到的帧数
	u32                dwLostPackRatio;    ///<丢包率, 指经过丢包重传处理后的丢包率
	u32                dwPhysicalLostPackRatio; ///<物理丢包率，指未经过丢包重传处理的丢包率
	u32                dwLostPacks;        ///<丢包总数
	EmAudFormat_Api emAudDecType;          ///<音频协议
	BOOL32			bAudioDecStart;		   ///<是否开始音频解码
	EmAacChnlNum_Api      emChnl_num;           ///< 如果是lc,ld，声道数
	EmAudFormat_Api emAudChanDecType;         ///<通道音频协议
public:
	tagTMtAudDecStatistic_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtAudDecStatistic_Api, TMtAudDecStatistic_Api;

typedef struct tagTMtVidEncStatistic_Api
{
	EmCodecComponentIndex_Api emVidEncId;  ///<视频编码器id
	u32                dwEncBitrate;       ///<编码码率
	u32                dwFrameRate;        ///<编码帧率
	u32                dwVidWidth;         ///<码流宽度(分辨率)
	u32                dwVidHeight;        ///<码流高度(分辨率)
	EmVidFormat_Api    emVidEncType;          ///<视频协议
	BOOL32			   bVideoEncStart;     ///<是否开始视频编码
	EmH264Profile_Api	emVideoProfile;			///<264profile值

public:
	tagTMtVidEncStatistic_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtVidEncStatistic_Api, TMtVidEncStatistic_Api;


typedef struct tagTMtVidDecStatistic_Api
{
	EmCodecComponentIndex_Api emVidDecId;  ///<视频解码器id
	u32                dwDecBitrate;       ///<解码码率
	u32                dwRcvFrames;        ///<收到的帧数	
	u32                dwLostPackRatio;    ///<丢包率, 指经过丢包重传处理后的丢包率
	u32                dwPhysicalLostPackRatio; ///<物理丢包率，指未经过丢包重传处理的丢包率
	u32                dwLostPacks;   ///<丢包总数
	u32                dwFrameRate;   ///<解码帧率
	u32                dwVidWidth;    ///<码流宽度(分辨率)
	u32                dwVidHeight;   ///<码流高度(分辨率)
	EmVidFormat_Api	emVidDecType;     ///<视频协议
	BOOL32			bVideoDecStart;	  ///<是否开始视频解码
	EmH264Profile_Api	emVideoProfile;			///<264profile值
public:
	tagTMtVidDecStatistic_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtVidDecStatistic_Api, TMtVidDecStatistic_Api;

typedef struct tagTMtAudMixStatistic_Api
{
	EmCodecComponentIndex_Api emAudMixId;
public:
	tagTMtAudMixStatistic_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtAudMixStatistic_Api, TMtAudMixStatistic_Api;

typedef struct tagTMtVidMixStatistic_Api
{
	EmCodecComponentIndex_Api emVidMixId;
public:
	tagTMtVidMixStatistic_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtVidMixStatistic_Api, TMtVidMixStatistic_Api;

typedef struct tagTMtCodecStatistic_Api
{
	TMtAudEncStatistic_Api atMainAudEncStatic[KMTAPI_MAX_ENCODE_NUM];
	u8 byMainAudEncCount;
	TMtAudEncStatistic_Api atAssAudEncStatic[KMTAPI_MAX_ENCODE_NUM];
	u8 byAssAudEncCount;
	TMtAudDecStatistic_Api atMainAudDecStatic[KMTAPI_MAX_DECODE_NUM];
	u8 byMainAudDecCount;
	TMtAudDecStatistic_Api atAssAudDecStatic[KMTAPI_MAX_DECODE_NUM];
	u8 byAssAudDecCount;
	TMtVidEncStatistic_Api atMainVidEncStatic[KMTAPI_MAX_ENCODE_NUM];
	u8 byMainVidEncCount;
	TMtVidEncStatistic_Api atAssVidEncStatic[KMTAPI_MAX_ENCODE_NUM];
	u8 byAssVidEncCount;
	TMtVidDecStatistic_Api atMainVidDecStatic[KMTAPI_MAX_DECODE_NUM];
	u8 byMainVidDecCount;
	TMtVidDecStatistic_Api atAssVidDecStatic[KMTAPI_MAX_DECODE_NUM];
	u8 byAssVidDecCount;
	TMtAudMixStatistic_Api atMainAudMixStatic[KMTAPI_MAX_ENCODE_NUM];
	u8 byMainAudMixCount;
	TMtAudMixStatistic_Api atAssAudMixStatic[KMTAPI_MAX_ENCODE_NUM];
	u8 byAssAudMixCount;
	TMtVidMixStatistic_Api atMainVidMixStatic[KMTAPI_MAX_DECODE_NUM];
	u8 byMainVidMixCount;
	TMtVidMixStatistic_Api atAssVidMixStatic[KMTAPI_MAX_DECODE_NUM];
	u8 byAssVidMixCount;

public:
	tagTMtCodecStatistic_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtCodecStatistic_Api, TMtCodecStatistic_Api;

/** DCS 服务器地址 */
typedef struct tagTMtDCSSvrAddr_Api
{
	s8 achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1];       ///<域名
	u32 dwIp;                                         ///<ip
	BOOL32 bUseDefAddr;                               ///<是否使用默认地址
	s8 achCustomDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///<用户自定义域名
	u32 dwCustomIp;                                   ///<用户自定义ip
	u32 dwPort;
public:
	tagTMtDCSSvrAddr_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtDCSSvrAddr_Api, TMtDCSSvrAddr_Api;

/** 所有视频解码器参数 */
typedef struct tagTMTAllVideoEncoderParamCfg_Api
{
	TMTVideoEncoderParamCfg_Api atParamArray[KMTAPI_MAX_MULTI_CHANNEL_NUM];           ///<编码器参数
	u8 byCnt;                                                                         ///<编码器个数
public:
	tagTMTAllVideoEncoderParamCfg_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTAllVideoEncoderParamCfg_Api, TMTAllVideoEncoderParamCfg_Api;



typedef struct tagTMTCodecVidSrcInfo_Api
{
	EmCodecComponentIndex_Api emCodecCpIndex; ///<编码器索引
	EmVidPort_Api emVidPort;                  ///<端口
public:
	tagTMTCodecVidSrcInfo_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTCodecVidSrcInfo_Api, TMTCodecVidSrcInfo_Api;


/** 内置mc运行信息 */
typedef struct tagTInnerMCRunInfo_Api
{
	BOOL32 bMcIsExist;		       ///<是否存在内置mc功能
	BOOL32 bMcIsActive;		       ///<内置mc是否激活
	BOOL32 bMcIsInconf;            ///<内置mc是否正在开会
	u32 dwMcMemMaxNum;             ///<内置mc支持最大数目
public:
	tagTInnerMCRunInfo_Api() { memset( this, 0, sizeof(*this)); }
}*PTInnerMCRunInfo_Api, TInnerMCRunInfo_Api;


/** 内置mc辅流配置 */
typedef struct tagTMTInnerMcAssVidCfg_Api
{
	EmVidFormat_Api emAssVideoFormat;              ///<辅流格式
	EmMtResolution_Api emAssVideoRes;              ///<辅流分辨率
	u32 dwAssVideoFramerate;                       ///<辅流帧率
public:
	tagTMTInnerMcAssVidCfg_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTInnerMcAssVidCfg_Api, TMTInnerMcAssVidCfg_Api;

/** VGA图像调节 */
typedef struct tagTMTVgaImageAdjustCfg_Api
{
	BOOL32 bVga1FilterState;                   ///<VGA1滤波状态
	u32 dwVga1PhaseClock; 	                   ///<VGA1相位时钟
	s32 nVga1ImageOffset; 	                   ///<VGA1图像偏移

	BOOL32 bVga2FilterState;                   ///<VGA1滤波状态
	u32 dwVga2PhaseClock; 	                   ///<VGA1相位时钟
	s32 nVga2ImageOffset; 	                   ///<VGA1图像偏移
public:
	tagTMTVgaImageAdjustCfg_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTVgaImageAdjustCfg_Api, TMTVgaImageAdjustCfg_Api;

/** 视频源标签 */
typedef struct tagTMTVideoSrcTag_Api
{
	EmMtVideoPort_Api emVideoPortId;
	s8 achVideoPortTag[KMTAPI_BUF_128_LEN+1];
public:
	tagTMTVideoSrcTag_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTVideoSrcTag_Api, TMTVideoSrcTag_Api;

typedef struct tagTMTVideoSrcTagList_Api
{
	u8 byCnt;
	TMTVideoSrcTag_Api atVidSrcTag[KMTAPI_MAX_VIDEO_SRC_NUM];
public:
	tagTMTVideoSrcTagList_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTVideoSrcTagList_Api, TMTVideoSrcTagList_Api;
/** Ftp快照信息 */
typedef struct tagTMTSnapShotFtpCfg_Api
{
	BOOL32 bIsEnable;                                    ///<是否启用快照FTP服务
	u32 dwIpAddr;                                        ///<地址
	u32 dwPort;                                          ///<端口
	s8 achUploadPath[KMTAPI_MAX_PATH_FILE_NAME_LEN+1];   ///<上传路径
	s8 achUserName[KMTAPI_MAX_FULL_USERNAME_LEN+1];      ///<用户名
	s8 achPassWord[KMTAPI_MAXLEN_PASSWORD+1];            ///<密码
public:
	tagTMTSnapShotFtpCfg_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTSnapShotFtpCfg_Api, TMTSnapShotFtpCfg_Api;

/** 恢复配置默认值信息 */
typedef struct tagTMTRestoreDefaultCfgInfo_Api
{
	s8 aachKeyList[KMTAPI_COUNT_256][KMTAPI_BUF_64_LEN + 1];  ///<恢复默认值的key列表
	u32 dwCnt;
public:
	tagTMTRestoreDefaultCfgInfo_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTRestoreDefaultCfgInfo_Api, TMTRestoreDefaultCfgInfo_Api;

/** 条件查询*/
typedef struct tagTMTConditionQuery_Api
{
	s8  achEmail[KMTAPI_MAX_EMAIL_LEN+1];		        ///< 用户账号emai
	s8  achE164[KMTAPI_MAX_MT_E164_LEN+1];			    ///< 用户账号e164
	s8  achName[KMTAPI_MAX_MT_ALIAS_LEN+1];			    ///< 用户名
	s8  achAccount[KMTAPI_MAX_MT_ALIAS_LEN+1];			///< 自定义账号
	s8  achMobilePhone[KMTAPI_MT_MAX_TELEPHONE_LEN+1];  ///< 用户手机(企业外不需要)
	u32 dwInEnt;			                            ///< 查询企业范围：0表示企业外，1表示企业内
	u32 dwStartRow;		                                ///< 起始，例如：0（表示从第1条开始），10（表示从第11条开始），依次类推
	u32 dwPageSize;		                                ///< 返回条数，例如：10
public:
	tagTMTConditionQuery_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTConditionQuery_Api, TMTConditionQuery_Api;


typedef struct tagTMTQueryUser_Api
{
	u32 dwUserNum ;
	s8  aachUserNo[KMTAPI_MAX_USER_NUM][KMTAPI_MAX_MT_ALIAS_LEN+1];
public:
	tagTMTQueryUser_Api( ) { memset( this, 0, sizeof(*this)); }
}*PTMTQueryUser_Api, TMTQueryUser_Api;

/** 请求用户头像*/
typedef struct tagTMTQueryPortrait_Api
{
	EmMtPortrait_Api	emPortrait;
	s8    achPortraitStr[KMTAPI_BUF_128_LEN+1];
	s8	  achFileName[KMTAPI_BUF_64_LEN+1];
	u64	  dwRequestPointer;
public:
	tagTMTQueryPortrait_Api( ) { memset( this, 0, sizeof( *this )); }
}*PTMTQueryPortrait_Api, TMTQueryPortrait_Api;

/** 修改用户头像*/
typedef struct tagTMTModifyPortrait_Api
{
	u32   dwX1;
	u32   dwY1;
	u32   dwWidth;
	u32   dwHeith;
	u32   dwLen;
	s8    achPath[KMTAPI_BUF_256_LEN+1];
public:
	tagTMTModifyPortrait_Api( ) { memset( this, 0, sizeof( *this)); }
}*PTMTModifyPortrait_Api, TMTModifyPortrait_Api;

/** 个人介绍*/
typedef struct tagTMTModifyBrief_Api
{
	s8 achUserName[KMTAPI_MAX_MT_ALIAS_LEN+1];
	s8 achBrief[KMTAPI_BUF_64_LEN+1];
public:
	tagTMTModifyBrief_Api() { memset( this, 0, sizeof( *this)); }
}*PTMTModifyBrief_Api, TMTModifyBrief_Api;

/** 姓名模糊查找本企业联系人*/
typedef struct tagTMTUserListByStr_Api 
{
	s8	achUserName[KMTAPI_MAX_MT_ALIAS_LEN+1];    ///< 查询者账号，可以是E164号码或邮箱
	s8	achStr[KMTAPI_BUF_32_LEN+1];               ///< 模糊匹配的字符串，例如：“孙”
	u32 dwStartRow;                                ///< 起始行，例如：0
	u32 dwPageSize;                                ///< 返回条数，例如：10
public:
	tagTMTUserListByStr_Api() { memset( this, 0, sizeof( *this )); }
}*PTMTUserListByStr_Api, TMTUserListByStr_Api;

/** 联系人认证模式*/
typedef struct tagTMTSetAuthMode_Api
{
	s8  achJid[KMTAPI_BUF_64_LEN+1];					///< 账号对应的jid
	u32 dwAuthMode;					                    ///< 添加联系人认证模式：(0:无需认证；1:待认证；2:拒绝接受)
public:
	tagTMTSetAuthMode_Api() { memset( this, 0, sizeof( *this )); }
}*PTMTSetAuthMode_Api, TMTSetAuthMode_Api;

/** 服务器列表*/
typedef struct tagTMtSvrList_Api
{
	EmServerType_Api aemServerList[emServerTypeEnd_Api]; ///< 服务器列表
	u8				 byCnt;                              ///< 列表中的实际个数

	tagTMtSvrList_Api() { memset(this, 0, sizeof(tagTMtSvrList_Api)); }

}*PTMtSvrList_Api, TMtSvrList_Api;

/** APS登陆参数*/
typedef struct tagTMTApsLoginParam_Api
{
	s8 achUsername[KMTAPI_BUF_128_LEN+1]; ///< 用户名
	s8 achPassword[KMTAPI_BUF_64_LEN+1]; ///< 明文密码
	s8 achSoftwareVer[KMTAPI_MAX_DEV_SOFT_VER_LEN+1];
	s8 achModelName[KMTAPI_MAX_MT_TYPE_NAME_LEN+1];
	s8 achOemInfo[KMTAPI_MAX_MT_OEM_NAME_LEN+1];
	s8 achMd5Password[KMTAPI_BUF_32_LEN+1];///< MD5加密密码,用于设置加密密码,是明文密码的MD5加密

	tagTMTApsLoginParam_Api() { memset(this, 0, sizeof(tagTMTApsLoginParam_Api)); }

}*PTMTApsLoginParam_Api, TMTApsLoginParam_Api;

typedef struct tagTMtApsLoginErrcode_Api
{
	BOOL32  bSucess;       ///<是否成功 若失败 通过下面的错误码获取错误信息
	u32		dwHttpErrcode; ///<http错误码 200表示链接服务器成功 其他表明连接服务器失败
	u32		dwApsErroce;   ///<bSucess为FALSE http错误码为200的情况下 服务器返回的错误码,参考EmLoginAPSErrorId_Api

	tagTMtApsLoginErrcode_Api() { memset(this, 0, sizeof(tagTMtApsLoginErrcode_Api)); }

}*PTMtApsLoginErrcode_Api, TMtApsLoginErrcode_Api;

/** 修改账号密码*/
typedef struct tagTMTModifyPwd_Api
{
	s8 achUserName[KMTAPI_MAX_MT_ALIAS_LEN+1];    ///< 用户帐号，可以是E164号或者邮箱
	s8 achOldPwd[KMTAPI_BUF_32_LEN+1];            ///< 老密码
	s8 achNewPwd[KMTAPI_BUF_32_LEN+1];		      ///< 新密码
	tagTMTModifyPwd_Api() { memset( this, 0, sizeof( tagTMTModifyPwd_Api) ); }
}*PTMTModifyPwd_Api, TMTModifyPwd_Api;

typedef struct tagTMTAddressBook_Api
{
	s8 achId[KMTAPI_BUF_64_LEN+1];				    ///<ID
	s8 achAccount[KMTAPI_BUF_128_LEN+1];
	s8 achName[KMTAPI_BUF_128_LEN+1];				///<name
	s8 achEmail[KMTAPI_BUF_64_LEN + 1];				///<邮箱地址
	s8 achE164[KMTAPI_BUF_16_LEN+1];				///<成员的E164号
	s8 achMobilePhone[KMTAPI_BUF_32_LEN+1];			///<成员的电话号码 	
	s8 achExtNum[KMTAPI_BUF_64_LEN+1];				///<扩展号码
	tagTMTAddressBook_Api( ) { memset( this, 0, sizeof( *this )); }
}*PTMTAddressBook_Api, TMTAddressBook_Api;

/** 地址簿信息*/
typedef struct tagTMTAddressBooks_Api
{
	u32 dwAddressNum;
	TMTAddressBook_Api atAddress[KMTAPI_MAX_ADDRESS_NUM];
	tagTMTAddressBooks_Api() { memset( this , 0, sizeof( *this )); }
}*PTMTAddressBooks_Api,TMTAddressBooks_Api;

/** 分页查询用户域共享地址簿信息*/
typedef struct tagTMTAddressBooksForPage_Api
{
	u32 dwTotalNum; ///<地址簿总数
	u32 dwAddressNum; ///<当前查询的个数
	TMTAddressBook_Api atAddress[KMTAPI_MAX_ADDRESS_NUM];
	tagTMTAddressBooksForPage_Api() { memset( this , 0, sizeof( *this )); }
}*PTMTAddressBooksForPage_Api,TMTAddressBooksForPage_Api;

/** 部门信息*/
typedef struct tagTMTWbParse_Keda_Department_Api
{
	u32 dwDepartmentId;                                        
	s8	achDepartmentName[KMTAPI_BUF_64_LEN + 1];   
	u32	dwParentId;                                            
	s8	achLeaf[KMTAPI_BUF_64_LEN + 1];                       
    u32 dwSeqNumber;
public:
	tagTMTWbParse_Keda_Department_Api() { memset( this, 0, sizeof(tagTMTWbParse_Keda_Department_Api )); }
}*PTMTWbParse_Keda_Department_Api, TMTWbParse_Keda_Department_Api;

typedef struct tagTMTWbParse_Keda_Departments_Api
{
	u32 						dwDepartmentNum;           
	TMTWbParse_Keda_Department_Api 	atDepartment[KMTAPI_MAX_DEPARTMENT_COUNT]; 

public:
	tagTMTWbParse_Keda_Departments_Api() { memset( this, 0, sizeof(tagTMTWbParse_Keda_Departments_Api) ); }
}*PTMTWbParse_Keda_Departments_Api, TMTWbParse_Keda_Departments_Api;


typedef	struct tagTMTWbParse_Keda_EntUsers_Api
{
	u32	dwUserNum;
	TMTWbParse_Keda_EntUser_Api atEntUser[KMTAPI_MAX_USER_DETAIL_INFO];

public:
	tagTMTWbParse_Keda_EntUsers_Api(){ memset(this, 0, sizeof(tagTMTWbParse_Keda_EntUsers_Api) );}
}*PTMTWbParse_Keda_EntUsers_Api, TMTWbParse_Keda_EntUsers_Api;

typedef	struct tagTMTWBParse_Keda_QueryUsers_Api
{
	u32 					dwTotalCount;
	TMTWbParse_Keda_EntUsers_Api 	tUsers;
public:
	tagTMTWBParse_Keda_QueryUsers_Api() { memset( this, 0, sizeof( *this )); }
}*PTMTWBParse_Keda_QueryUsers_Api, TMTWBParse_Keda_QueryUsers_Api;

typedef	struct tagTMTWbParse_Keda_SearchUsers_Api
{
	u32	dwTotalCount;
	s8  achStr[KMTAPI_BUF_64_LEN+1];
	TMTWbParse_Keda_EntUsers_Api tEntUsers;
public:
	tagTMTWbParse_Keda_SearchUsers_Api(){ memset(this, 0, sizeof(tagTMTWbParse_Keda_SearchUsers_Api) );}
}*PTMTWbParse_Keda_SearchUsers_Api, TMTWbParse_Keda_SearchUsers_Api;

typedef struct tagTMTWbParse_Keda_UserProfile_Api
{
	s8 achUserId[KMTAPI_BUF_64_LEN+1];		 ///< 用户数字id，如“124”
	s8 achJobTitle[KMTAPI_BUF_64_LEN+1];	 ///< 职位，如“云协师”）
	s8 achLocation[KMTAPI_BUF_64_LEN+1];	 ///< 位置，如“3F-10L-04m”
	s8 achWorkPhone[KMTAPI_BUF_64_LEN+1];	 ///< 工作电话，如“8484”
	s8 achMobilePhone[KMTAPI_BUF_64_LEN+1];  ///< 移动电话，如“130xxxx8137”
public:
	tagTMTWbParse_Keda_UserProfile_Api() { memset(this, 0, sizeof(tagTMTWbParse_Keda_UserProfile_Api) ); }
}*PTMTWbParse_Keda_UserProfile_Api, TMTWbParse_Keda_UserProfile_Api;

typedef struct tagTMTWbParse_Keda_User_Api
{
	s8 achMoid[KMTAPI_BUF_64_LEN+1];				 ///< 账号moid
	s8 achJid[KMTAPI_BUF_256_LEN+1];	             ///< xmpp账号
	s8 achAccount[KMTAPI_BUF_128_LEN+1];	         ///< 自定义账号
	s8 achEmail[KMTAPI_BUF_128_LEN+1];			     ///< 电子邮件，如“sunfei@kedacom.com”
	s8 achE164[KMTAPI_BUF_64_LEN+1];	             ///< E164
	s8 achMobile[KMTAPI_BUF_64_LEN+1];               ///< 联系电话
	s8 achDeviceType[KMTAPI_BUF_16_LEN+1];			 ///< 设备类型
	s8 achName[KMTAPI_BUF_128_LEN+1];                ///< 微博昵称（科达都为实名，如“孙飞”）
	s8 achExtNum[KMTAPI_BUF_128_LEN+1];				 ///< 分机
	s8 achSeat[KMTAPI_BUF_256_LEN+1];				 ///< 座位号
	s8 achBrief[KMTAPI_BUF_512_LEN+1];			     ///< 简介
	s8 achPortrait40[KMTAPI_BUF_256_LEN+1];	         ///< 用户头像（40像素）
	s8 achPortrait64[KMTAPI_BUF_256_LEN+1];          ///< 用户头像（64像素）
	s8 achPortrait128[KMTAPI_BUF_256_LEN+1];         ///< 用户头像（64像素）
	u32 dwDepartmentID;								 ///< 部门ID
public:
	tagTMTWbParse_Keda_User_Api() { memset(this, 0, sizeof(tagTMTWbParse_Keda_User_Api )); }
}*PTMTWbParse_Keda_User_Api, TMTWbParse_Keda_User_Api;

/////////////////////////////////////////////////////////////////////////
// 部门组织架构
/////////////////////////////////////////////////////////////////////////
typedef struct tagTMTWbParse_Keda_departmentUsers_Api
{
	u32 dwUserNum;
	TMTWbParse_Keda_User_Api atUser[KMTAPI_MAX_EMPLOYEE_COUNT]; 

public:
	tagTMTWbParse_Keda_departmentUsers_Api() { memset( this, 0, sizeof(tagTMTWbParse_Keda_departmentUsers_Api) ); }
}*PTMTWbParse_Keda_departmentUsers_Api, TMTWbParse_Keda_departmentUsers_Api;



typedef struct tagTMTCameraUpgrade_Api
{
	EmEquipmentUpgrading_Api emCameraType;	            ///< 升级摄像头类型
	BOOL32	bAction;	                                ///< 开始or停止
	s8 achFileName[KMTAPI_MAX_PATH_FILE_NAME_LEN+1];    ///< 升级文件名路径

public:
	tagTMTCameraUpgrade_Api() { memset( this, 0, sizeof(tagTMTCameraUpgrade_Api) ); }
}*PTMTCameraUpgrade_Api, TMTCameraUpgrade_Api;

typedef struct tagTMTKeyPressInfo_Api
{
	BOOL32 bKeyDown;               ///<keydown or keyup
	u32 dwKeySource;               ///<按键来源，遥控器种类暂时都写成2
	u32 dwKeyCode;                 ///<按键键值，参考EmRemoteScanCode_Api
	u32 dwKeyCount;                ///<按键计数
	EmKeyState_Api emKeyState;
public:
	tagTMTKeyPressInfo_Api() { memset( this, 0, sizeof(tagTMTKeyPressInfo_Api) ); }
}*PTMTKeyPressInfo_Api, TMTKeyPressInfo_Api;

/** Ethnet 以太网模式列表*/
typedef struct tagTEthnetWorkModeList_Api
{
	EmEthnetWorkMode_Api  emCard1Workmode;     ///<(网卡1模式) 0-自动, 1-10M全双工 2-10M半双工,3-100M全双工 4-100M半双工,5-1000M全双工 6-1000M半双工
	EmEthnetWorkMode_Api  emCard2Workmode;     ///<(网卡2模式) 0-自动, 1-10M全双工 2-10M半双工,3-100M全双工 4-100M半双工,5-1000M全双工 6-1000M半双工
public:
	tagTEthnetWorkModeList_Api() { memset( this, 0, sizeof(tagTEthnetWorkModeList_Api) ); }
}*PTEthnetWorkModeList_Api, TEthnetWorkModeList_Api;


/** Ethnet 以太网网卡信息*/
typedef struct tagTEthnetCardInfo_Api
{ 
	BOOL32 bEnableIpDhcp;    ///<是否DHCP获取IP	
	u32 dwStaticIp;          ///<IP地址（手动分配）
	u32 dwStaticMask;        ///<子网掩码	  
	u32 dwStaticGW;          ///<网关        
	u32 dwDhcpIp;            ///<IP地址（动态分配）
	u32 dwDhcpMask;          ///<子网掩码	  
	u32 dwDhcpGW;            ///<网关

	BOOL32 bEnableDnsDhcp;   ///<是否DHCP获取DNS        
	u32 dwStaticDns;         ///<DNS （手动分配）
	u32 dwStaticDnsBackup;   ///<DNS备份	
	u32 dwDhcpDns;           ///<DNS （动态分配）
	u32 dwDhcpDnsBackup;     ///<DNS备份
public:
	tagTEthnetCardInfo_Api() { memset( this, 0, sizeof(tagTEthnetCardInfo_Api) ); }
}*PTEthnetCardInfo_Api, TEthnetCardInfo_Api;


/** Ethnet 以太网信息*/
typedef struct tagTEthnetCfg_Api
{
	EmEthInterfaceMode_Api emEthBackupMD;    ///<(EmEthInterfaceMode) 0-备份，1-多网口
	u32 dwCurCardId;                         ///<网卡ID  0-网卡1  1-网卡2 
	TEthnetCardInfo_Api tEth1;               ///<网卡1 配置信息
	TEthnetCardInfo_Api tEth2;               ///<网卡2 配置信息
public:
	tagTEthnetCfg_Api() { memset( this, 0, sizeof(tagTEthnetCfg_Api) ); }
}*PTEthnetCfg_Api, TEthnetCfg_Api;


/** PPPoE拨号信息*/
typedef struct tagTEthnetPPPoECfg_Api
{
	BOOL32 bEnable;                                    ///<是否启用PPPoE false-关闭，true-启用
	s8 achUserName[KMTAPI_BUF_64_LEN+1];               ///<用户名
	s8 achPassword[KMTAPI_BUF_64_LEN+1];               ///<密码
	BOOL32 bAutoDial;                                  ///<拨号方式 true:自动 false:手动
public:
	tagTEthnetPPPoECfg_Api() { memset( this, 0, sizeof(tagTEthnetPPPoECfg_Api) ); }
}*PTEthnetPPPoECfg_Api, TEthnetPPPoECfg_Api;

/** PPPoE连接后详细信息*/
typedef struct tagTPPPoEState_Api
{
	EmPPPoELinkState_Api emState;               ///<连接状态
	u32 dwIp;                                   ///<当前IP地址
	u32 dwGateway;                              ///<网关
	u32 dwDns;                                  ///<DNS 
	u32 dwDnsBackup;                            ///<DNS备份
	EmPPPoELinkErrReason_Api emReason;          ///<失败原因 
public:
	tagTPPPoEState_Api() { memset( this, 0, sizeof(tagTPPPoEState_Api) ); }
}*PTPPPoEState_Api, TPPPoEState_Api;


/** Wifi作为AP工作模式时的AP配置*/
typedef struct tagTWifiApConfiguration_Api
{
	s8 achSsid[KMTAPI_SSID_MAX_LEN+1];            ///<wifi-ap热点名称
	EmWifiApKeyType_Api emCapabilities;         ///<安全与加密类型
	s8 achKey[KMTAPI_BUF_64_LEN+1];             ///<加密时的密码
	u32 dwDhcpStartIp;                          ///<DHCP起始IP
	u32 dwDhcpEndIp;                            ///<DHCP结束IP
	u32 dwIp;                                   ///<设备IP
	u32 dwMask;                                 ///<设备子网掩码
	EmWifiFrequencyBandType_Api emFrequencyBand; ///<wifi频段
public:
	tagTWifiApConfiguration_Api() { memset( this, 0, sizeof(tagTWifiApConfiguration_Api) ); }
}*PTWifiApConfiguration_Api, TWifiApConfiguration_Api;

/** Wifi启用状态与工作模式*/
typedef struct tagTWifiWorkMode_Api
{
	EmWifiWorkMode_Api       emWifiWKMD;  ///<Wifi工作模式配置     
	TWifiApConfiguration_Api tWifiApCfg;  ///<当wifi_workmode为emWifiWorkModeWifiAp_Api时,生效
public:
	tagTWifiWorkMode_Api() { memset( this, 0, sizeof(tagTWifiWorkMode_Api) ); }
}*PTWifiWorkMode_Api, TWifiWorkMode_Api;

/** Wifi作为客户端工作模式时的配置*/
typedef struct tagTWifiConfiguration_Api
{
	BOOL32 bEnableAutoConn;       ///<是否自动连接，默认开启
	BOOL32 bEnableAutoIp;         ///<是否自动获取ip,默认开启
	u32 dwIp;                     ///<IP地址
	u32 dwMask;                   ///<子网掩码	  
	u32 dwGateway;                ///<网关
public:
	tagTWifiConfiguration_Api() { memset( this, 0, sizeof(tagTWifiConfiguration_Api) ); }
}*PTWifiConfiguration_Api, TWifiConfiguration_Api;


/** Wifi 扫描结果信息*/
typedef struct tagTWifiScanResult_Api
{
	s8 achSsid[KMTAPI_SSID_MAX_LEN+1];        ///<wifi-ap热点名称
	EmWifiKeyType_Api emKeyType;            ///<加密类型  
	EmWifiSignalLevel_Api emSignalLevel;    ///<信号强度
	BOOL32 bIsSave;                         ///<本地保存过的 true-保存使用过  false-未使用过
	s32 nNetworkId;                         ///<保存的连接标识 issave为true时生效
public:
	tagTWifiScanResult_Api() { memset( this, 0, sizeof(tagTWifiScanResult_Api) ); }
}*PTWifiScanResult_Api, TWifiScanResult_Api;


/** Wifi 扫描结果列表*/ 
typedef struct tagTWifiScanResultList_Api
{
	TWifiScanResult_Api atScanList[KMTAPI_BUF_32_LEN];      ///<wifi扫描列表
	u8 byCnt;
public:
	tagTWifiScanResultList_Api() { memset( this, 0, sizeof(tagTWifiScanResultList_Api) ); }
}*PTWifiScanResultList_Api, TWifiScanResultList_Api;


/** 当前Wifi连接的详细信息*/
typedef struct tagTWifiCurDetailInfo_Api
{
	EmWifiLinkState_Api  emState;                ///<连接状态
	s32 nNetworkId;                              ///<当前得到的连接ID标识
	s8 achSsid[KMTAPI_SSID_MAX_LEN+1];             ///<wifi-ap热点名称
	s8 achBSsid[KMTAPI_SSID_MAX_LEN+1];            ///<wifi-ap BSSID
	s8 achMacAddress[KMTAPI_BUF_64_LEN+1];       ///<当前AP的MAC
	u32 dwIp;                                    ///<当前IP地址
	u32 dwMask;                                  ///<子网掩码	  
	u32 dwGateway;                               ///<网关	
	EmWifiLinkErrReason_Api emReason;            ///<失败原因 
public:
	tagTWifiCurDetailInfo_Api() { memset( this, 0, sizeof(tagTWifiCurDetailInfo_Api) ); }
}*PTWifiCurDetailInfo_Api, TWifiCurDetailInfo_Api;


/** 当前Wifi连接的统计信息*/
typedef struct tagTWifiStatisInfo_Api
{
	s8 achSsid[KMTAPI_SSID_MAX_LEN+1];            ///<wifi-ap热点名称
	s32 nNetworkId;                             ///<当前得到的连接ID标识
	EmWifiSignalLevel_Api emSignalLevel;        ///<信号强度
	u32 dwDownTotalBytes;                       ///<下行总流量 Byte
	u32 dwUpTotalBytes;                         ///<上行总流量 Byte
public:
	tagTWifiStatisInfo_Api() { memset( this, 0, sizeof(tagTWifiStatisInfo_Api) ); }
}*PTWifiStatisInfo_Api, TWifiStatisInfo_Api;



/** Wifi 连接参数*/
typedef struct tagTWifiConnParam_Api
{
	BOOL32 bIsSave;                               ///<本地是否保存过的 true-保存使用过  false-未使用过
	s8 achSsid[KMTAPI_SSID_MAX_LEN+1];              ///<wifi-ap热点名称 (issave为false时生效)
	EmWifiKeyType_Api emKeyType;                  ///<加密类型 (issave为false时生效)       
	s8 achPassword[KMTAPI_BUF_64_LEN+1];          ///<登录密码,未加密为空 (issave为false时生效)
	s32 nNetworkId;                               ///<保存的连接标识 (issave为true时生效)
public:
	tagTWifiConnParam_Api() { memset( this, 0, sizeof(tagTWifiConnParam_Api) ); }
}*PTWifiConnParam_Api, TWifiConnParam_Api;


/** MobileData 配置*/
typedef struct tagTMobileDataWorkMode_Api
{
	BOOL32 bEnable;                             ///<0-关闭， 1-启用
public:
	tagTMobileDataWorkMode_Api() { memset( this, 0, sizeof(tagTMobileDataWorkMode_Api) ); }
}*PTMobileDataWorkMode_Api, TMobileDataWorkMode_Api;




/** MobileData 连接信息配置*/
typedef struct tagTMobileDataCurDetailInfo_Api
{
	EmMobileDataLinkState_Api emState;                    ///<连接状态 
	EmMobileDataNetType_Api   emNetType;                  ///<运营商类型
	EmMobileDataNetGenerationType_Api emGenerationType;   ///<版本信息 
	s8 achSsid[KMTAPI_SSID_MAX_LEN+1];                      ///<接入点名称
	u32 dwIp;                                             ///<当前IP地址
	s8 achConnTime[KMTAPI_BUF_64_LEN+1];                  ///<连接时间
	EmMobileDataLinkErrReason_Api emReason;               ///<失败原因 
public:
	tagTMobileDataCurDetailInfo_Api() { memset( this, 0, sizeof(tagTMobileDataCurDetailInfo_Api) ); }
}*PTMobileDataCurDetailInfo_Api, TMobileDataCurDetailInfo_Api;


/** MobileData 统计配置*/
typedef struct tagTMobileDataStatisInfo_Api
{
	EmMobileDataLinkState_Api emSignalLevel;                ///<信号强度
	u32 dwUpBandwidth;                                      ///<上传速率Kbps
	u32 dwDownBandwidth;                                    ///<下载速率Kbps
	u32 dwUpBytes;                                          ///<上传总流量Byte
	u32 dwDownBytes;                                        ///<下载总流量Byte
public:
	tagTMobileDataStatisInfo_Api() { memset( this, 0, sizeof(tagTMobileDataStatisInfo_Api) ); }
}*PTMobileDataStatisInfo_Api, TMobileDataStatisInfo_Api;


/** 对外通讯IP信息*/
typedef struct tagTNetUsedInfo_Api
{		
	EmNetAdapterWorkType_Api emUsedType;   ///<当前使用的网络类型 
	u32 dwIp;                              ///<IP地址
	u32 dwMask;                            ///<子网掩码	  
	u32 dwGateway;                         ///<网关        	
	u32 dwDns;                             ///<DNS
	u32 dwDnsBackup;                       ///<DNS备份
public:
	tagTNetUsedInfo_Api() { memset( this, 0, sizeof(tagTNetUsedInfo_Api) ); }
}*PTNetUsedInfo_Api, TNetUsedInfo_Api;


/** 单个预置位名称配置*/
typedef struct tagTMTPreSetNameInfo_Api
{
	u32 dwPresetIndex;                       ///<预置位索引
	s8 achPresetName[KMTAPI_BUF_64_LEN+1];   ///<预置位名称
public:
	tagTMTPreSetNameInfo_Api() { memset( this, 0, sizeof(tagTMTPreSetNameInfo_Api) ); }
}*PTMTPreSetNameInfo_Api, TMTPreSetNameInfo_Api;

/** 所有预置位名称配置*/
typedef struct tagTAllMTPreSetNameInfoCfg_Api
{
	u16 byPri1stPresetCnt;				///<第一路主流预置位实际大小
	TMTPreSetNameInfo_Api atPri1stPresetNameInfo[KMTAPI_MAX_CAMERA_PRESET_NUM];   ///<第一路主流所有预置位信息
    u16 byPri2ndPresetCnt;				///<第二路主流预置位实际大小
    TMTPreSetNameInfo_Api atPri2ndPresetNameInfo[KMTAPI_MAX_CAMERA_PRESET_NUM];   ///<第二路主流所有预置位信息
	u16 byPri3rdPresetCnt;				///<第三路辅流预留位实际大小
	TMTPreSetNameInfo_Api atPri3rdPresetNameInfo[KMTAPI_MAX_CAMERA_PRESET_NUM];   ///<第三路辅流所有预留位信息
public:
	tagTAllMTPreSetNameInfoCfg_Api() 
	{
		byPri1stPresetCnt = 0;
        byPri2ndPresetCnt = 0;
		byPri3rdPresetCnt = 0;
	}
}*PTAllMTPreSetNameInfoCfg_Api, TAllMTPreSetNameInfoCfg_Api;

/** 监控设备组信息*/
typedef struct tagTMTMonitorGroup_Api
{
	s8 achId[KMTAPI_BUF_64_LEN+1];
	s8 achGroupId[KMTAPI_BUF_64_LEN+1];
	s8 achGroupName[KMTAPI_BUF_64_LEN+1];
	s8 achParentId[KMTAPI_BUF_64_LEN+1];
	s8 achLeaf[KMTAPI_BUF_64_LEN+1];
public:
	tagTMTMonitorGroup_Api(){ memset( this, 0, sizeof(tagTMTMonitorGroup_Api) ); }
}*PTMTMonitorGroup_Api, TMTMonitorGroup_Api;

typedef struct tagTMTMonitorGroups_Api
{
	u32	dwGroupCount;
	TMTMonitorGroup_Api atMonitorGroup[KMTAPI_MAX_MONITOR_GROUP_COUNT];
public:
	tagTMTMonitorGroups_Api(){ memset( this, 0, sizeof(tagTMTMonitorGroups_Api) ); }
}*PTMTMonitorGroups_Api, TMTMonitorGroups_Api;

/** 监控设备信息*/
typedef struct tagTMTMonitorDevice_Api
{
	s8	achGroupId[ KMTAPI_BUF_64_LEN+1 ];		///<当前设备属于设备组的ID
	s8	achId[ KMTAPI_BUF_64_LEN+1 ];
	s8	achDeviceGUID[ KMTAPI_BUF_64_LEN+1 ];
	s8	achName[ KMTAPI_BUF_128_LEN+1 ];
	s8	achE164[ KMTAPI_MAX_MT_E164_LEN+1 ];
	s8	achDeviceType[ KMTAPI_BUF_128_LEN+1 ];
	s8	achDescription[ KMTAPI_BUF_256_LEN+1 ];
	s8  achNote[ KMTAPI_BUF_256_LEN+1 ];
public:
	tagTMTMonitorDevice_Api(){ memset( this, 0, sizeof(tagTMTMonitorDevice_Api) ); }
}*PTMTMonitorDevice_Api, TMTMonitorDevice_Api;

typedef struct tagTMTMonitorDevices_Api
{
	u32	dwDeviceCount;
	TMTMonitorDevice_Api atMonitorDevice[KMTAPI_MAX_MONITOR_DEVICE_COUNT];
public:
	tagTMTMonitorDevices_Api(){ memset( this, 0, sizeof(tagTMTMonitorDevices_Api) ); }
}*PTMTMonitorDevices_Api, TMTMonitorDevices_Api;

typedef struct tagTMTVersion_Api
{
	s8 abyVersion[KMTAPI_BUF_32_LEN+1];
public:
	tagTMTVersion_Api() { memset( this, 0, sizeof(tagTMTVersion_Api)); }
}*PTTMTVersion_Api, TMTVersion_Api;

/** 修改登陆密码信息结构*/
typedef struct tagTMTModifyPwdInfo_Api
{
	s8 achUserName[KMTAPI_MAX_USERNAME_LEN+1];
	s8 achOldPwd[KMTAPI_MAX_USERPWD_LEN+1];
	s8 achNewPwd[KMTAPI_MAX_USERPWD_LEN+1];

public:
	tagTMTModifyPwdInfo_Api() { memset( this, 0, sizeof(tagTMTModifyPwdInfo_Api)); }
}*PTMTModifyPwdInfo_Api, TMTModifyPwdInfo_Api;

/** 多人聊天成员增加通知(用于在聊天框里显示"某某进入聊天室")*/ 
typedef struct tagTMTImMultiChatAddMemberNtf_Api
{
	u32   dwSessionId;                   ///< 聊天室id
	s8    achMail[KMTAPI_BUF_64_LEN+1];  ///<邮箱id
	TRoomId_Api  tRoomId;
public:
	tagTMTImMultiChatAddMemberNtf_Api() { memset( this, 0, sizeof(tagTMTImMultiChatAddMemberNtf_Api)); }
}*PTMTImMultiChatAddMemberNtf_Api,TMTImMultiChatAddMemberNtf_Api;

typedef struct tagTMTWeiboLogin_Api
{
	s8 achUserName[KMTAPI_BUF_128_LEN+1];
	s8 achPassword[KMTAPI_MAX_USERPWD_LEN+1];
public:
	tagTMTWeiboLogin_Api() { memset( this, 0, sizeof(tagTMTWeiboLogin_Api)); }
}*PTMTWeiboLogin_Api, TMTWeiboLogin_Api;

typedef struct tagTMTSysHint_Api
{
	EmHintCode_Api emHintCode;             ///<提示码
	s8 achExtraParam[KMTAPI_BUF_64_LEN+1]; ///<附加参数
public:
	tagTMTSysHint_Api() { memset( this, 0, sizeof(tagTMTSysHint_Api)); }
}*PTMTSysHint_Api, TMTSysHint_Api;

typedef struct tagTRecordParam
{   /** 仅windows平台*/
	s8     achFilePath[KMTAPI_BUF_256_LEN+1];  ///<录像文件存放路径
	BOOL32 bLocal;                             ///<是否录本地
	BOOL32 bHasAud;                            ///<是否带音频
	BOOL32 bHasAuxVid;                         ///<是否带双流，仅bLocal为true时有效
	s8     achFileName[KMTAPI_BUF_128_LEN+1];  ///<录像文件名
public:
	tagTRecordParam() { memset( this, 0, sizeof(tagTRecordParam)); }
}*PTRecordParam_Api, TRecordParam_Api;

typedef struct tagTRecordDiskAlarmLevel
{   /** 仅windows平台*/
	s8  achPartName[KMTAPI_BUF_256_LEN+1];  ///<分区名如c:
	u32 dwAlarmLevel1;                      ///<一级告警阈值，单位M，例如20M
	u32 dwAlarmLevel2;                      ///<二级告警阈值，单位M，例如10M
public:
	tagTRecordDiskAlarmLevel() { memset( this, 0, sizeof(tagTRecordDiskAlarmLevel)); }
}*PTRecordDiskAlarmLevel_Api, TRecordDiskAlarmLevel_Api;

typedef struct tagTMTCameraTypeInfo_Api
{
	s8   achName[KMTAPI_MAX_DEV_TYPE_NAME_LEN+1];///<摄像头类型名
	u32  dwMaxAddr; 		                   	///<摄像头最大地址值
	u32  dwMaxSpeedLevel;	                    ///<摄像头最大速度级别 
public:
	tagTMTCameraTypeInfo_Api() { memset( this, 0, sizeof(tagTMTCameraTypeInfo_Api)); }
}*PTMTCameraTypeInfo_Api, TMTCameraTypeInfo_Api;

typedef struct tagTMTCameraTypeList_Api
{
	u8 byCnt;                                                           ///<实际的摄像头个数
	TMTCameraTypeInfo_Api atCameraTypeList[KMTAPI_MAX_CAMERA_TYPE_NUM]; ///<所有摄像头的能力类型
public:
	tagTMTCameraTypeList_Api() { memset( this, 0, sizeof(tagTMTCameraTypeList_Api)); }
}*PTMTCameraTypeList_Api, TMTCameraTypeList_Api;

typedef struct tagTMTMultiRes_Api
{
	EmMtResolution_Api aemRes[KMTAPI_BUF_32_LEN];
	u8 byCnt;
public:
	tagTMTMultiRes_Api() { memset( this, 0, sizeof(tagTMTMultiRes_Api)); }
}*PTMTMultiRes_Api, TMTMultiRes_Api;

/** 网管告警*/
typedef struct tagTAlarmTrap_Api
{
	u32 dwAlarmCode;                         ///<告警码
	u32 dwAlarmState;                        ///<告警状态	
	u32 dwThreshHoldVal;                     ///<当前阈值
public:
	tagTAlarmTrap_Api() { memset( this, 0, sizeof(tagTAlarmTrap_Api)); }
}*PTAlarmTrap_Api, TAlarmTrap_Api;

/** cpu上报网管信息*/
typedef struct tagTCPUReportData_Api
{
	u32 dwTotalCpuUseage;                    ///<CPU整体使用率
	u32 adwCpuCoreUseage[KMTAPI_BUF_64_LEN]; ///<CPU每个核的使用率
	u8 byCnt;
	u32 dwMemUsage;                          ///<内存使用率
	BOOL32 bInConf;                          ///<是否在会议中
	s8 achRptTime[KMTAPI_BUF_64_LEN+1];      ///<上报时间 HH:MM:SS，相对于东八区的时间
public:
	tagTCPUReportData_Api() { memset( this, 0, sizeof(tagTCPUReportData_Api)); }
}*PTCPUReportData_Api, TCPUReportData_Api;

/** 登录时上报网管信息*/
typedef struct tagTLogInReportData_Api
{
	u32 dwMemSize;       ///<物理内存大小
	u32 dwUpBandWidth;   ///<上行带宽
	u32 dwDownBandWidth; ///<下行带宽
	u32 dwIp;      ///<终端的IP
	u32 dwDnsIp;   ///<DNS的IP
	u32 dwXapIp;   ///<XAP服务器IP
	u32 dwCoreNum; ///<CPU核数
	u32 dwCpuFreq; ///<CPU主频
	s8 achCpuType[KMTAPI_BUF_64_LEN+1]; ///<CPU型号
	s8 achVer[KMTAPI_BUF_64_LEN+1];     ///<终端版本号
	s8 achRptTime[KMTAPI_BUF_64_LEN+1]; ///<上报时间 HH:MM:SS，相对于东八区的时间
public:
	tagTLogInReportData_Api() { memset( this, 0, sizeof(tagTLogInReportData_Api)); }
}*PTLogInReportData_Api, TLogInReportData_Api;

/** 网络变化时上报网管的信息*/
typedef struct tagTNetChangeReportData_Api
{
	u32 dwUpBandWidth;   ///<上行带宽
	u32 dwDownBandWidth; ///<下行带宽
	u32 dwIp;    ///<终端的IP
	u32 dwDnsIp; ///<DNS的IP
	u32 dwXapIp; ///<XAP服务器IP
	s8 achRptTime[KMTAPI_BUF_64_LEN+1]; ///<上报时间 2014-06-16/09:57:50，相对于东八区的时间
public:
	tagTNetChangeReportData_Api() { memset( this, 0, sizeof(tagTNetChangeReportData_Api)); }
}*PTNetChangeReportData_Api, TNetChangeReportData_Api;

/** 入会时上报网管的信息*/
typedef struct tagTEnterConfReportData_Api
{
	u32 dwCallRsate;   ///<呼叫码率
public:
	tagTEnterConfReportData_Api() { memset( this, 0, sizeof(tagTEnterConfReportData_Api)); }
}*PTEnterConfReportData_Api, TEnterConfReportData_Api;

/** 异常文件上报网管*/
typedef struct tagTExceptionFileReportData_Api
{
	s8  achCrashLog[KMTAPI_BUF_1024_LEN * 5]; ///<异常日志
	u16 wCrashLogLen;
	s8  achVer[KMTAPI_BUF_64_LEN + 1];        ///<终端版本号
	s8  achRptTime[KMTAPI_BUF_64_LEN + 1];    ///<上报时间 2014-06-16/09:57:50，相对于东八区的时间
public:
	tagTExceptionFileReportData_Api() { memset( this, 0, sizeof(tagTExceptionFileReportData_Api)); }
}*PTExceptionFileReportData_Api, TExceptionFileReportData_Api;

typedef struct tagTNewUpgradeVersion_Api
{
	u32 dwLevel;
	s8  achSusIp[KMTAPI_BUF_64_LEN + 1];    ///<升级服务器ip地址
	s8  achVer[KMTAPI_BUF_64_LEN + 1];      ///<新版本的版本号
	s8  achOemStr[KMTAPI_BUF_64_LEN + 1];   ///<oem字符串
public:
	tagTNewUpgradeVersion_Api() { memset( this, 0, sizeof(tagTNewUpgradeVersion_Api));}
}*PTNewUpgradeVersion_Api, TNewUpgradeVersion_Api;

typedef struct tagTAudInputState_Api
{
	BOOL32 bUsed;                         ///<是否插入或有信号
	EmHDAudPortIn_Api emAudInputType;     ///<输入接口类型
public:
	tagTAudInputState_Api() { memset( this, 0, sizeof(tagTAudInputState_Api));}
}*PTAudInputState_Api, TAudInputState_Api;

typedef struct tagTMultiAudInputState_Api
{
	u8 byCnt;
	TAudInputState_Api atAudInputState[KMTAPI_MAX_AUDIO_IN_NUM];  ///<音频输入接口状态
public:
	tagTMultiAudInputState_Api() { memset( this, 0, sizeof(tagTMultiAudInputState_Api)); }
}*PTMultiAudInputState_Api, TMultiAudInputState_Api;

typedef struct tagTAudOutputState_Api
{
	BOOL32 bUsed;                           ///<是否插入或有信号
	EmHDAudPortOut_Api emAudOutputType;     ///<输出接口类型
public:
	tagTAudOutputState_Api() { memset( this, 0, sizeof(tagTAudOutputState_Api)); }
}*PTAudOutputState_Api, TAudOutputState_Api;

typedef struct tagTMultiAudOutputState_Api
{
	u8 byCnt;
	TAudOutputState_Api atAudOutputState[KMTAPI_MAX_AUDIO_OUT_NUM];     ///<音频输出接口状态
public:
	tagTMultiAudOutputState_Api() { memset( this, 0, sizeof(tagTMultiAudOutputState_Api)); }
}*PTMultiAudOutputState, TMultiAudOutputState_Api;

/** 终端编号 */
typedef struct tagTAudOutVol_Api
{
	EmCodecComponent_Api        emCodecType;                ///< 类型
	EmCodecComponentIndex_Api emCodecId; ///< Id
	u32         dwVol;                 ///< 音量
public:
	tagTAudOutVol_Api(){ memset( this ,0 ,sizeof( struct tagTAudOutVol_Api ) );	}

}*PTAudOutVol_Api, TAudOutVol_Api;


/** 网络参数 */
typedef struct tagTNetParam_Api {
	u8               byRemoteNum;                           ///<实际远端地址个数,发送可以

	/** 最多KMTAPI_MAX_NET_DEST_NUM，接收暂时只支持1个 */
	TRtpRtcpPair_Api tLocalNet;                             ///<当地地址对
	TRtpRtcpPair_Api atRemoteNet[KMTAPI_MAX_NET_DEST_NUM];  ///<远端地址对

public:
	tagTNetParam_Api(){ memset( this ,0 ,sizeof( struct tagTNetParam_Api ) ); }
}*PTNetParam_Api, TNetParam_Api;

/** 编码器状态(仅windows双流使用) */
typedef struct tagTMtVncVidEncStatus_Api
{
	BOOL32 			    bVideoSignal;		  ///<是否有视频信号
	BOOL32	            bVideoCapStart;       ///<是否开始视频捕获
	BOOL32			    bVideoEncStart;       ///<是否开始视频编码
	BOOL32			    bNetSndVideoStart;    ///<是否开始视频发送

	TVidEncParam_Api	tVideoEncParam;       ///<视频编码参数
	TNetParam_Api       tVideoSendAddr;       ///<视频发送地址
	u32                 dwSetEncParam;        ///<设置硬件编码参数次数
	u32                 dwVideoSend;          ///<已发送的视频包数
public:
	tagTMtVncVidEncStatus_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtVncVidEncStatus_Api, TMtVncVidEncStatus_Api;

/** 编码器状态(仅windows双流使用) */
typedef struct tagTMtVncVidEncStatis_Api
{
	u8                  byVideoFrameRate;     ///<视频帧率
	u32                 dwVideoBitRate;       ///<视频码流速度
	u32                 dwVideoPackLose;      ///<视频丢帧数
	u32                 dwVideoPackError;     ///<视频错帧数
	u32                 dwAvrVideoBitRate;    ///<1分钟内视频编码平均码率
public:
	tagTMtVncVidEncStatis_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtVncVidEncStatis_Api, TMtVncVidEncStatis_Api;

/** FXO呼叫状态 */
typedef struct tagTFxoState_Api
{
	EmFxoState_Api emState;		          ///<Fxo状态
public:
	tagTFxoState_Api(){ memset( this ,0 ,sizeof( struct tagTFxoState_Api ) );	}
}*PTFxoState_Api, TFxoState_Api;

/** 快照文件信息 */
typedef struct tagTSnapshotFileInfo_Api
{
	s8 achFilePath[KMTAPI_BUF_64_LEN+1]; ///<文件所在路径 
	s8 achFileName[KMTAPI_BUF_64_LEN+1]; ///<文件名
	TMTTime_Api  tFileCreateTime;         ///<文件创建时间
public:
	tagTSnapshotFileInfo_Api(){ memset( this ,0 ,sizeof( struct tagTSnapshotFileInfo_Api ) );	}
}*PTSnapshotFileInfo_Api, TSnapshotFileInfo_Api;



typedef struct tagTSnapshotFileList_Api
{
	TSnapshotFileInfo_Api        arrTSnapshotFileInfo[KMTAPI_MAX_SNAPSHOT_LIST_NUM];  ///< 多个快照列表信息
	u8              byCnt;                                                            ///< 实际列表数量
public:
	tagTSnapshotFileList_Api(){ memset( this, 0, sizeof( struct tagTSnapshotFileList_Api) ); }
}*PTSnapshotFileList_Api, TSnapshotFileList_Api;


/** 图像参数，仅windows平台 */
typedef struct tagTImageParam_Api
{
	EmImgParam_Api emImgParamType;  ///< 图像参数类型
	u32            dwVal;           ///< 参数值
	BOOL32         bAuto;           ///< 是否自动
public:
	tagTImageParam_Api(){ memset( this ,0 ,sizeof( struct tagTImageParam_Api ) );	}

}*PTImageParam_Api, TImageParam_Api;

/** 图像默认参数，仅windows平台 */
typedef struct tagTDefaultImageParam_Api
{
	EmImgParam_Api emImgParamType;  ///< 图像参数类型
	u32            dwMinVal;        ///< 参数最小值
	u32            dwMaxVal;        ///< 参数最大值
	u32            dwDefVal;        ///< 参数默认值
	u32            dwStep;          ///< 参数步进值
public:
	tagTDefaultImageParam_Api(){ memset( this ,0 ,sizeof( struct tagTDefaultImageParam_Api ) );	}

}*PTDefaultImageParam_Api, TDefaultImageParam_Api;

/** ping命令的选项*/
typedef struct tagTPingCmdOption_Api
{
	u32 dwPackSize;          ///< 要ping的数据报的大小，以字节为单位
	u32 dwTimeOut;           ///< ping的超时值，以秒为单位
	u32 dwTTL;               ///< TTL值
	u32 dwCount;             ///< PING的次数
public:
	tagTPingCmdOption_Api() { memset( this, 0, sizeof(tagTPingCmdOption_Api) ); }
}*PTPingCmdOption_Api, TPingCmdOption_Api;

/** ping命令的选项*/
typedef struct tagTPingTestParam_Api
{
	s8 achDstInfo[KMTAPI_BUF_32_LEN+1];                      ///< ping目标(ip/dns)
	TPingCmdOption_Api tPingOption;   ///< ping命令的选项
	u32 dwUserId;                     ///< 用于标识调用者的UID，暂未使用
public:
	tagTPingTestParam_Api() { memset( this, 0, sizeof(tagTPingTestParam_Api) ); }
}*PTPingTestParam_Api, TPingTestParam_Api;

/** ping的结果*/
typedef struct tagTPingResult_Api
{
	EmPingErrcode_Api emPingErrCode;
	u32 dwTTL;   
	u32 dwTripTime;
	u32 dwUserId;
	u32 dwErrType;
	u32 dwErrCode;
public:
	tagTPingResult_Api() { memset( this, 0, sizeof(tagTPingResult_Api) ); }
}*PTPingResult_Api, TPingResult_Api;

/** DNS查询IP */
typedef  struct tagTDNSNameToIpInfo_Api
{
	s8 achDnsName[KMTAPI_BUF_32_LEN+1];                //DNS名称
public:
	tagTDNSNameToIpInfo_Api() { memset( this, 0, sizeof(tagTDNSNameToIpInfo_Api) ); }
}*PTDNSNameToIpInfo_Api, TDNSNameToIpInfo_Api;

/** DNS查询IP */
typedef struct tagTDNSNameToIpResult_Api
{
	s8 achDnsName[KMTAPI_BUF_32_LEN+1];                ///<DNS名称
	u32 dwIp;                      ///<查询到的ip地址，网络序
	u32 dwErrorCode;              ///<错误代码
public:
	tagTDNSNameToIpResult_Api() { memset(this, 0, sizeof(tagTDNSNameToIpResult_Api) ); }
}*PTDNSNameToIpResult_Api, TDNSNameToIpResult_Api;

/** ip mac冲突信息*/
typedef struct tagTNetConfilictedInfo_Api
{
	EmNetConflictType_Api emConflictType;  ///< 冲突类型
	s8  achMac[KMTAPI_BUF_256_LEN];        ///< 发生冲突的接口的当前mac地址
	s8  achIp[KMTAPI_BUF_256_LEN];         ///< 发生冲突的接口的当前ip地址
public:
	tagTNetConfilictedInfo_Api() { memset( this, 0, sizeof(tagTNetConfilictedInfo_Api) ); }
}*PTNetConfilictedInfo_Api, TNetConfilictedInfo_Api;

/**  ethernet DHCP 状态信息*/
typedef struct tagTDHCPStateInfo_Api
{	
	u32 dwState;
public:
	tagTDHCPStateInfo_Api() { memset( this, 0, sizeof(tagTDHCPStateInfo_Api) ); }
}*PTDHCPStateInfo_Api, TDHCPStateInfo_Api;

/**  ethernet DHCP 状态信息*/
typedef struct tagTDHCPLeaseInfo_Api
{	
	u32 dwEthId;        ///< 以太网接口ID
	u32 dwIp;           ///< ip地址
	u32 dwMask;         ///< 掩码
	u32 dwGateway;      ///< 网关
	u32 dwDuration;     ///< 到期时间
	u32 dwDnsNum;       ///< dns数量
	u32 adwDnsServerList[KMTAPI_MAX_ETH_DNSLIST_NUM];  ///< dns列表 
public:
	tagTDHCPLeaseInfo_Api() { memset( this, 0, sizeof(tagTDHCPLeaseInfo_Api) ); }
}*PTDHCPLeaseInfo_Api, TDHCPLeaseInfo_Api;

/** 单个ethernet 接口信息*/
typedef struct tagTEthnetInterfaceParam_Api
{
	u32 dwIp;                            ///< IP地址(网络序)
	u32 dwMask;                          ///< 子网掩码  (网络序)  
	s8  achMac[KMTAPI_BUF_256_LEN+1];    ///<  MAC地址
public:
	tagTEthnetInterfaceParam_Api() {memset( this, 0, sizeof(tagTEthnetInterfaceParam_Api) );}
}*PTEthnetInterfaceParam_Api, TEthnetInterfaceParam_Api;

/**  PPPoE 统计信息*/
typedef struct tagTPPPoEStatis_Api
{	
	u32 dwLinkTime;       ///< 链路建立的时间
	u32 dwLinkDowntimes;  ///< 链路断链的次数统计
	u32 dwNumPkgSent;     ///< 总共发送的数据包数--包括各类协议包以及上层业务程序的数据包/
	u32 dwNumPkgRecved;   ///< 总共接收的数据包数
	u32 dwNumBytesSent;   ///< 总共发送的字节数
	u32 dwNumBytesRecved; ///< 总共接收的字节数
public:
	tagTPPPoEStatis_Api() { memset( this, 0, sizeof(tagTPPPoEStatis_Api) ); }
}*PTPPPoEStatis_Api, TPPPoEStatis_Api;

/**  路由表配置参数*/
typedef struct tagTRouteItemInfo_Api
{	
	u32 dwInterface;    ///< 网络接口，表示该条路由经由哪个接口转发出去
	u32 dwDstNetwork;   ///< 路由的目标网络
	u32 dwDstNetMask;   ///< 路由的目标网络掩码
	u32 dwGateway;      ///< 路由网关
	u32 dwPriority;     ///< 优先级，值越低表示该条路由优先级越高，默认0，最大255
public:
	tagTRouteItemInfo_Api() { memset( this, 0, sizeof(tagTRouteItemInfo_Api) ); }
}*PTRouteItemInfo_Api, TRouteItemInfo_Api;

/**  路由表配置参数集合*/
typedef struct tagTRouteItemInfoList_Api
{	
	TRouteItemInfo_Api atRouteList[KMTAPI_MAX_ROUTEITEM_CNT]; ///< 路由表集合
	u32 dwCnt;                                                ///< 路由个数
public:
	tagTRouteItemInfoList_Api() { memset( this, 0, sizeof(tagTRouteItemInfoList_Api) ); }
}*PTRouteItemInfoList_Api, TRouteItemInfoList_Api;

/** E1单元*/
typedef struct tagTE1Unit_Api
{
	u32 dwE1ID;
	u32 dwUsedFlag;       ///< 使用标志,置1使用，下面参数有效；0不使用，下面参数无效
	u32 dwE1TSMask;       ///< E1时隙分配说明,详见下
	u32 dwProtocolType;   ///< 接口协议封装类型, 如果是单E1连接可以指定PPP/HDLC，如果是多E1捆绑连接必须是PPP协议
	u32 dwEchoInterval;   ///< echo请求时间间隔，秒为单位，有效范围0-256，填默认值2即可
	u32 dwEchoMaxRetry;   ///< echo最大重发次数，有效范围0-256，填默认值5即可
public:
	tagTE1Unit_Api() {memset(this, 0, sizeof(tagTE1Unit_Api));}
}*PTE1Unit_Api, TE1Unit_Api;

/** E1分组信息*/
typedef struct tagTE1Group_Api
{
	BOOL32 bEnable;                                    ///<是否启用
	u32 dwUnitNum;                                     ///<使用E1单元个数
	u32 dwIsBind;                                      ///<是否绑定
	u32 dwGroupID;                                     ///<组编号
	u32 dwIpAddr;                                      ///<ip地址，网络序
	u32 dwMask;                                        ///<掩码，网络序 
	u32 dwAuthType;                                    ///<PPP链接的验证方法PAP/CHAP,默认填MP_AUTHENTICATION_PAP
	u32 dwFragMinPackageLen;                           ///<最小分片包长，字节为单位，范围20~1500，默认填20
	s8   achServerUsrName[KMTAPI_E1_USRNAME_LEN+1];    ///<服务端用户名称，用来验证对端的数据
	s8   achServerUsrPwd[KMTAPI_E1_USRPSW_LEN+1];      ///<服务端用户密码，用来验证对端的数据
	s8   achClientUsrName[KMTAPI_E1_USRNAME_LEN+1];    ///<客户端用户名称，用来被对端验证
	s8   achClientUsrPwd[KMTAPI_E1_USRPSW_LEN+1];      ///<客户端用户密码，用来被对端验证
	TE1Unit_Api atE1UnitList[KMTAPI_E1_MAX_UNIT_NUM];  ///<每个被捆绑的serial同步接口链路参数
public:
	tagTE1Group_Api() {memset(this, 0, sizeof(tagTE1Group_Api));}
}*PTE1Group_Api, TE1Group_Api;

/** E1配置信息*/
typedef struct tagTE1Cfg_Api
{
	BOOL32 bEncrypt; ///< 是否加密
	u32 dwClockType; ///< 时钟类型

	u32 dwGroupCount;
	TE1Group_Api atE1GroupList[KMTAPI_E1_MAX_GROUP_NUM];///< 所有分组信息
public:
	tagTE1Cfg_Api() {memset( this, 0, sizeof(tagTE1Cfg_Api) );}
}*PTE1Cfg_Api, TE1Cfg_Api;


typedef struct tagTMTGetPubTemplateList_Api
{
	u32 dwStart;  ///<  公共模板的开始行，默认为0，即从符合条件的数据中的第几行取数据，0为第一行数据
	u32 dwCount;  ///<  获取的公共模板数，默认为10，即在包含start在内的后count条数据，如果参数为0表示获取所有公共模板
	u32 dwOrder;  ///<  根据公共模板的创建时间排序，0代表升序，1代表降序，默认为0
public:
	tagTMTGetPubTemplateList_Api(){memset(this, 0, sizeof(tagTMTGetPubTemplateList_Api));}
}*PTMTGetPubTemplateList_Api, TMTGetPubTemplateList_Api;

typedef struct tagTMTPubTemplateSimpleInfo_Api
{
	s8 achTemplateKey[KMTAPI_BUF_128_LEN+1];           ///<  公共模板唯一标识-E164号
	s8 achName[KMTAPI_BUF_128_LEN+1];                  ///<  公共模板名称
	u32 dwDuration;                                    ///<  会议时长
	u32 dwBitrate;                                     ///<  会议码率
	EmMtResolution_Api		emResolution;		       ///<  会议分辨率
public:
	tagTMTPubTemplateSimpleInfo_Api(){memset(this, 0, sizeof(tagTMTPubTemplateSimpleInfo_Api));}
}*PTMTPubTemplateSimpleInfo_Api, TMTPubTemplateSimpleInfo_Api;

typedef struct tagTMTPubTemplateList_Api
{
	u32 dwCount;	
	TMTPubTemplateSimpleInfo_Api atPubTemplateSimpleInfo[KMTAPI_COUNT_16];
public:
	tagTMTPubTemplateList_Api(){memset( this, 0, sizeof(tagTMTPubTemplateList_Api) );}
}*PTMTPubTemplateList_Api, TMTPubTemplateList_Api;

typedef struct tagTMTPubTemplateInfo_Api
{
	s8 achTemplateKey[KMTAPI_BUF_128_LEN+1];       ///<  公共模板唯一标识-E164号
	s8 achName[KMTAPI_BUF_128_LEN+1];              ///<  公共模板名称
	u32 dwDuration;                                ///<  会议时长
	u32 dwBitrate;                                 ///<  会议码率
	EmMtOpenMode_Api emMeetingSafe;                ///< 会议安全
	s8	achPassword[ KMTAPI_BUF_32_LEN+1 ];        ///< 会议密码
	EmEncryptArithmetic_Api emEncryptedType;       ///< 传输加密类型
	s8	achEncryptedKey[ KMTAPI_BUF_32_LEN+1 ];    ///< 传输加密Key
	EmMeetingSafeType_Api emMeetingType;           ///< 会议类型
	TMTCreateConfSatellite_Api				tSatellite;    ///< 卫星会议设置
	BOOL32 bPublicMeeting;                                 ///< 是否公共会议室，1是，0否
	EmMtMixType_Api emMixMode;                             ///< 混音模式

	u32						dwVideoCount;
	TMTVideoFormatList_Api atVideoFormatList[KMTAPI_COUNT_16]; ///<主视频格式列表

	u32						dwAudioCount;
	TMTAudioFormatList_Api atAudioFormatList[KMTAPI_COUNT_16]; ///<音频格式格式列表

	u32 dwCallTimes;     ///< 呼叫次数
	u32 dwCallInterval;  ///< 呼叫间隔(秒)
	BOOL32 bInitMute;    ///< 初始化哑音：1是，0否
	EmVideoQuality_Api emVideoQuality;     ///< 视频质量,0：质量优先；1：速度优先
	EmMtDualMode_Api emDualMode;           ///< 双流权限。0：发言会场；1：任意会场;
	BOOL32 bVoiceInspireEnable;            ///< 是否开启语言激励：1是，0否
    u32 dwVoiceInspireTime;                    ///< 语言激励敏感度
	EmRestCascadeMode_Api emCascadeMode;   ///< 级联模式,0简单级联，1合并级联
	BOOL32 bCascadeUpload;                 ///< 是否级联上传:1是，0否
	BOOL32 bCascadeReturn;                 ///< 是否级联回传:1是，0否
	u32 dwCascadeReturnPara;               ///< 级联回传带宽参数
    u32 dwMeetingScale;                        ///< 会议规模,0：空，1：4方视频会议,2：8方视频会议,3：大型视频会议
    BOOL32 bOneReforming;                 ///< 归一重整,0:关闭; 1:开启
	TMTCreateRecordRecord_Api tRecord;     ///< 录像设置
	TMTCreateConfMultiCast_Api tMultiCast; ///< 主播设置

	u32 dwDualCount;
	TMTDualFormatList_Api atDualFormatList[KMTAPI_COUNT_8];///<双流格式列表

	EmClosedMeeting_Api emClosedMeeting;                   ///< 会议免打扰，1开启，0关闭
public:
	tagTMTPubTemplateInfo_Api(){memset( this, 0, sizeof(tagTMTPubTemplateInfo_Api) );}
}*PTMTPubTemplateInfo_Api, TMTPubTemplateInfo_Api;

typedef struct tagTMTPubTemplate_Api
{
	s8 achName[KMTAPI_BUF_128_LEN+1];        ///<  公共模板名称
	EmMeetingSafeType_Api emMeetingType;     ///< 会议类型
	u32 dwBitrate;                           ///< 会议码率
	EmMtResolution_Api emResolution;         ///< 分辨率
	EmMtOpenMode_Api emMeetingSafe;          ///< 会议安全
	EmEncryptArithmetic_Api emEncryptedType; ///< 传输加密类型
	s8	achEncryptedKey[ KMTAPI_BUF_32_LEN+1 ];   ///< 传输加密Key
	EmMtDualMode_Api emDualMode;                  ///< 双流权限
	u32 dwDuration;                               ///< 时长（分钟）
	EmMtMixType_Api emMixMode;                    ///< 混音模式
	TMTCreateConfSatellite_Api tSatellite;        ///<  卫星会议设置
	BOOL32 bPublicMeeting;                        ///< 是否公共会议室，1是，0否

	u32 dwVideoCount;
	TMTVideoFormatList_Api atVideoFormatList[KMTAPI_COUNT_16]; ///<主视频格式列表

	u32 dwAudioCount;
	TMTAudioFormatList_Api atAudioFormatList[KMTAPI_COUNT_16]; ///<音频格式格式列表

	u32 dwDualCount;
	TMTDualFormatList_Api atDualFormatList[KMTAPI_COUNT_8];

	EmClosedMeeting_Api emClosedMeeting;        ///< 会议免打扰，1开启，0关闭
	BOOL32						bEncryptedAuth;                         ///< 是否双向认证 0-关闭 1-开启
public:
	tagTMTPubTemplate_Api(){memset( this, 0, sizeof(tagTMTPubTemplate_Api) );}
}*PTMTPubTemplate_Api, TMTPubTemplate_Api;

typedef struct tagTMTCpuAndMemState_Api
{
	u32 dwCpuIdlePercent;///< CPU空闲百分比，0－100
	u32 dwMemTotalSize;  ///< 物理内存大小(KByte)
	u32 dwMemAllocSize;  ///< 已使用内存(KBytes)
	u32 dwMemFreeSize;   ///< 可用内存(KBytes)
public:
	tagTMTCpuAndMemState_Api(){memset( this, 0, sizeof(tagTMTCpuAndMemState_Api) );}
}*PTMTCpuAndMemState_Api, TMTCpuAndMemState_Api;

/** 台标融入码流的相关信息设置 */
typedef struct tagTMtTranspDColor_Api
{
	u32 dwRColor;          ///<R背景
	u32 dwGColor;          ///<G背景
	u32 dwBColor;          ///<B背景	
	u32 dwTransparency;    ///<透明度(0表示全透明，255表示不透明，1~254表示部分透明)
public:
	tagTMtTranspDColor_Api() { memset( this, 0, sizeof(tagTMtTranspDColor_Api) ); }
}*PTMtTranspDColor_Api, TMtTranspDColor_Api;

typedef struct tagTMtAddLogoParam_Api
{
	float fXPosRate;		    ///<宽度比例，xpos = 底图宽*fXPosRate
	float fYPosRate;		    ///<高度比例，ypos = 底图宽*fYPosRate
	u32 dwLogobgWidth;	        ///<参考底图的宽
	u32 dwLogobgHeight;	        ///<参考底图的高	
	TMtTranspDColor_Api tBackBGDColor;    
public:
	tagTMtAddLogoParam_Api() { memset( this, 0, sizeof(tagTMtAddLogoParam_Api) ); }
}*PTMtAddLogoParam_Api, TMtAddLogoParam_Api;

typedef struct tagTMtFullLogoParam_Api
{
	s8  achBmpPath[KMTAPI_MAX_PATH_FILE_NAME_LEN+1];	///<图片文件地址
	TMtAddLogoParam_Api tLogoParam;
public:
	tagTMtFullLogoParam_Api() { memset( this, 0, sizeof(tagTMtFullLogoParam_Api) ); }
}*PTMtFullLogoParam_Api, TMtFullLogoParam_Api;

typedef struct tagTMtFullLogoParamList_Api
{
	TMtFullLogoParam_Api atLogoParamList[KMTAPI_MAX_CONF_MT_MEMBER_NUM];
	u32 dwCount;
public:
	tagTMtFullLogoParamList_Api() { memset( this, 0, sizeof(tagTMtFullLogoParamList_Api) ); }
}*PTMtFullLogoParamList_Api, TMtFullLogoParamList_Api;


typedef struct tagTMTCameraPresetPicList_Api
{
	s8 aachPresetPicName[KMTAPI_COUNT_128][KMTAPI_BUF_64_LEN + 1]; ///<预置位图片名字
	u32 dwPresetPicCnt;///<预置位图片个数
public:
	tagTMTCameraPresetPicList_Api() { memset( this, 0, sizeof(tagTMTCameraPresetPicList_Api) ); }
}*PTMTCameraPresetPicList_Api, TMTCameraPresetPicList_Api;


/** cometd消息格式 */
typedef struct tagTMTCometdMessage_Api
{
	EmRestMeetingNotifyType_Api emNotifyType; ///<消息类型
	u32 dwNotifyId;                                              ///<通知id
	u32 dwNum;                                                   ///<消息数量
public:
	tagTMTCometdMessage_Api() { memset( this, 0, sizeof(tagTMTCometdMessage_Api) ); }
}*PTMTCometdMessage_Api, TMTCometdMessage_Api;

/** cometd消息列表 */
typedef struct tagTMTCometdMessageList_Api
{
	TMTCometdMessage_Api atCometdMessageList[KMTAPI_COUNT_32]; ///<消息列表
	u32 dwListNum;											  ///<列表个数
public:
	tagTMTCometdMessageList_Api() { memset( this, 0, sizeof(tagTMTCometdMessageList_Api) ); }
}*PTMTCometdMessageList_Api, TMTCometdMessageList_Api;

/** Sip配置 */
typedef struct tagTMtSipCfg_Api
{ 
	BOOL32 bEnableBfcp;
public:
	tagTMtSipCfg_Api() { memset( this, 0, sizeof(struct tagTMtSipCfg_Api) ); }
}*PTMtSipCfg_Api, TMtSipCfg_Api;

/** 终端设备性能 */
typedef struct tagTMtPFMInfo_Api
{ 
	u32 dwCpuUseRate;        ///<cpu使用百分比
	u32 dwDiskUseRate;       ///<硬盘使用百分比
	u32 dwMemUseRate;        ///<内存使用百分比
public:
	tagTMtPFMInfo_Api() { memset( this, 0, sizeof(struct tagTMtPFMInfo_Api) ); }
}*PTMtPFMInfo_Api, TMtPFMInfo_Api;

typedef struct tagTMtVidSrcInfo_Api
{
	EmCodecComponent_Api emCodecType;	///<视频采集类型
	EmCodecComponentIndex_Api emCodecId;	///< 视频采集编号 
	u32 dwVideoWidth;	///< 视频宽，像素为单位,为0表示无信号 
	u32 dwVideoHeight;	///< 视频高，行为单位,为0表示无信号
	BOOL32 bVideoProgressive;	///< 逐行或隔行，TRUE=逐行；FALSE=隔行
	u32 dwFrameRate;	///< 帧率，逐行时=场频，隔行时=场频/2，即60i=30P,为0表示无信号
public:
	tagTMtVidSrcInfo_Api() { memset( this, 0, sizeof(tagTMtVidSrcInfo_Api) ); }
}*PTMtVidSrcInfo_Api, TMtVidSrcInfo_Api;

typedef struct tagTMtVidSrcInfoList_Api
{
	u8 byCnt;
	TMtVidSrcInfo_Api atInfoList[KMTAPI_VIDSRC_MAX_NUM]; ///<视频源信息
public:
	tagTMtVidSrcInfoList_Api() { memset( this, 0, sizeof(tagTMtVidSrcInfoList_Api) ); }
}*PTMtVidSrcInfoList_Api, TMtVidSrcInfoList_Api;

typedef struct tagUpgradeFileInfo_Api
{
	BOOL32 bIsFound; ///<是否找到升级包
	s8 achFilePath[KMTAPI_BUF_128_LEN+1]; ///<升级包路径
public:
	tagUpgradeFileInfo_Api() { memset( this, 0, sizeof(tagUpgradeFileInfo_Api) ); }
}UpgradeFileInfo_Api, *PUpgradeFileInfo_Api;

/** U盘信息 */
typedef struct tagTMTUsbPartition_Api
{
	s8 achPath[KMTAPI_BUF_32_LEN+1];           ///<分区挂载的路径
	s8 achName[KMTAPI_BUF_32_LEN+1];           ///<分区的名称
	u32 dwTotalSpace;         ///<分区总大小KB
	u32 dwAvailableSpace;     ///<分区剩余空间KB
}*PTMTUsbPartition_Api, TMTUsbPartition_Api;

typedef struct tagTMTUsbInfo_Api
{
	u32 dwUsbId; ///<ID
	BOOL32 bIsUsed; ///<是否有U盘插入
	u8 byCnt;
	TMTUsbPartition_Api atPartition[KMTAPI_USB_PARTITION_MAX_NUM]; ///<U盘挂载根目录
public:
	tagTMTUsbInfo_Api() { memset( this, 0, sizeof(tagTMTUsbInfo_Api) ); }
}*PTMTUsbInfo_Api, TMTUsbInfo_Api;

typedef struct tagTMTUsbStatus_Api
{
	u8 byCnt;
	TMTUsbInfo_Api atUsbInfo[KMTAPI_USB_INTERFACE_MAX_NUM];
public:
	tagTMTUsbStatus_Api() { memset( this, 0, sizeof(tagTMTUsbStatus_Api) ); }
}*PTMTUsbStatus_Api, TMTUsbStatus_Api;

typedef struct tagTMTPathStructureUnit_Api
{
	EmSystemFileType_Api emFileType; ///<是否为文件夹
	s8 achFilePath[KMTAPI_BUF_128_LEN+1];
public:
	tagTMTPathStructureUnit_Api() { memset( this, 0, sizeof(tagTMTPathStructureUnit_Api) ); }
}*PTMTPathStructureUnit_Api, TMTPathStructureUnit_Api;

typedef struct tagTMTPathStructureDetail_Api
{
	u32 dwCnt;
	TMTPathStructureUnit_Api atPathUint[KMTAPI_COUNT_512];
public:
	tagTMTPathStructureDetail_Api() { memset( this, 0, sizeof(tagTMTPathStructureDetail_Api) ); }
}*PTMTPathStructureDetail_Api, TMTPathStructureDetail_Api;

typedef struct tagTMtVidInPortResInfo_Api
{
	EmMtVideoPort_Api emVideoPort; ///<视频源端口
	u32                           dwVideoWidth; ///<视频宽，像素为单位,为0表示无信号
	u32                           dwVideoHeight; ///<视频高，行为单位,为0表示无信号
	BOOL32                    bVideoProgressive; ///<逐行或隔行，TRUE=逐行；FALSE=隔行
	u32                           dwFrameRate; ///<帧率，逐行时=场频，隔行时=场频/2，即60i=30P,为0表示无信号
public:
	tagTMtVidInPortResInfo_Api() { memset( this, 0, sizeof(tagTMtVidInPortResInfo_Api) ); }
}*PTMtVidInPortResInfo_Api, TMtVidInPortResInfo_Api;

typedef struct tagTMtVidInPortResInfoList_Api
{
	u32 dwCount;
	TMtVidInPortResInfo_Api atVidInPortStatus[KMTAPI_COUNT_32]; ///<视频源信息
public:
	tagTMtVidInPortResInfoList_Api() { memset( this, 0, sizeof(tagTMtVidInPortResInfoList_Api) ); }
}*PTMtVidInPortResInfoList_Api, TMtVidInPortResInfoList_Api;


typedef struct tagTMTResizeMode_Api
{
	EmResizeMode_Api emResizeMode; ///<解码后处理策略
public:
	tagTMTResizeMode_Api() { memset( this, 0, sizeof(tagTMTResizeMode_Api) ); }
}*PTMTResizeMode_Api, TMTResizeMode_Api;


/** 能力集相关 */

typedef struct tagTVidDes_Api
{
	EmMtResolution_Api  emRes;         ///<分辨率
	u32                 dwMpi;         ///<帧率 如果是 格式是264,265， 传下去的是实际的fps， 否则，传下去的是 30除以 实际的帧数
	u32                 dwMax_BitRate; ///<支持最大码率
public:
	tagTVidDes_Api() { memset( this, 0, sizeof(tagTVidDes_Api) ); }
}*PTVidDes_Api, TVidDes_Api;

typedef struct tagTVidFormatCap_Api
{
	EmVidFormat_Api             emFormat;
	TVidDes_Api                 atItem[KMTAPI_COUNT_16];
	u32 dwItemCount;
	EmH264Profile_Api           emH264Profile; ///<264 profile
	EmH264AdditionalModes_Api   emH264Modes;   ///<264 svc mode
	EmH265Profile_Api           emH265Profile; ///<265 profile

public:
	tagTVidFormatCap_Api() { memset( this, 0, sizeof(tagTVidFormatCap_Api) ); }
}*PTVidFormatCap_Api, TVidFormatCap_Api;

/** 一路视频通道的能力 */
typedef struct tagTVidCapList_Api         
{	
	TVidFormatCap_Api atVidList[KMTAPI_COUNT_16];
	u32 dwCount;
	EmMtVidLabel_Api   emVidLab;  ///<暂时只针对发送辅流能力，区分video辅流和pc辅流

public:
	tagTVidCapList_Api() { memset( this, 0, sizeof(tagTVidCapList_Api) ); }

}*PTVidCapList_Api, TVidCapList_Api;


typedef struct tagTAudDes_Api
{
	EmAudFormat_Api   emFormat;
	u32               dwPack_time;  
	EmAacChnlNum_Api  emChnl_num;      ///<只针对lc, ld
public:
	tagTAudDes_Api() 
	{ 
		memset( this, 0, sizeof(tagTAudDes_Api) );
		dwPack_time = 30;
		emChnl_num = emCnNumCust_Api;
	}
}*PTAudDes_Api, TAudDes_Api;

/** 一路音频通道的能力 */
typedef struct tagTAudCapList_Api         
{	
	TAudDes_Api atAudList[KMTAPI_COUNT_16];
	u32 dwCount;
public:
	tagTAudCapList_Api() { memset( this, 0, sizeof(tagTAudCapList_Api) ); }

}*PTAudCapList_Api, TAudCapList_Api;

typedef struct tagTMtSendCap_Api
{
	TAudCapList_Api  atMain_aud_send_cap[KMTAPI_MAX_CONF_AUD_CHANNEL_NUM];     ///<多路发送能力
	TVidCapList_Api  atMain_vid_send_cap[KMTAPI_MAX_CONF_VID_CHANNEL_NUM];     
	TAudCapList_Api  atAss_aud_send_cap[KMTAPI_MAX_CONF_ASSAUD_CHANNEL_NUM];
	TVidCapList_Api  atAss_vid_send_cap[KMTAPI_MAX_CONF_ASSVID_CHANNEL_NUM];
	u32 dwMainAudSndCount;
	u32 dwMainVidSndCount;
	u32 dwAssAudSndCount;
	u32 dwAssVidSndCount;

public:
	tagTMtSendCap_Api() { memset( this, 0, sizeof(tagTMtSendCap_Api) ); }
}*PTMtSendCap_Api, TMtSendCap_Api;


typedef struct tagTMtRecvCap_Api
{
	TAudCapList_Api  atMain_aud_recv_cap[KMTAPI_MAX_CONF_AUD_CHANNEL_NUM];     ///<多路发送能力
	TVidCapList_Api  atMain_vid_recv_cap[KMTAPI_MAX_CONF_VID_CHANNEL_NUM];     
	TAudCapList_Api  atAss_aud_recv_cap[KMTAPI_MAX_CONF_ASSAUD_CHANNEL_NUM];
	TVidCapList_Api  atAss_vid_recv_cap[KMTAPI_MAX_CONF_ASSVID_CHANNEL_NUM];
	u32 dwMainAudRcvCount;
	u32 dwMainVidRcvCount;
	u32 dwAssAudRcvCount;
	u32 dwAssVidRcvCount;

public:
	tagTMtRecvCap_Api() { memset( this, 0, sizeof(tagTMtRecvCap_Api) ); }

}*PTMtRecvCap_Api, TMtRecvCap_Api;


typedef struct tagTCloudRecordState
{
	BOOL32             bCloudRecord;
	TMTTime_Api        tStartRecordTime;    ///<  开始录像时间， 是个本地时间

public:
	tagTCloudRecordState() { memset( this, 0, sizeof(tagTCloudRecordState) ); }

}*PTCloudRecordState_Api, TCloudRecordState_Api;

/** 快速呼叫信息*/
typedef struct tagTFastCall_Api
{
	u32 dwCallRate;			                                                  ///< 呼叫码率(kbps)
	EmMtAddrType_Api   emCallType;	                                 ///< 呼叫方式(ip, e164, alias)
	u32 dwPeerAddr;			                                                ///< 对端IP地址(网络序)
	s8 achPeerE164[KMTAPI_MAX_MT_E164_LEN+1];			///< 对端E164号
	s8 achPeerAlias[KMTAPI_MAX_MT_ALIAS_LEN+1];		    ///< 对端别名
public:
	tagTFastCall_Api() {memset(this, 0, sizeof(tagTFastCall_Api));}
}*PTFastCall_Api, TFastCall_Api;

/** 快速呼叫配置*/
typedef struct tagTFastCallList_Api
{
	u32 dwListCnt;                                                                      ///< 快速呼叫配置列表
	TFastCall_Api atFastCallList[KMTAPI_FAST_CALL_LIST_CNT];		///< 快速呼叫配置列表
public:
	tagTFastCallList_Api() {memset(this, 0, sizeof(tagTFastCallList_Api));}
}*PTFastCallList_Api, TFastCallList_Api;

/** Ev_MtApi_Diagnose_FileExistCheck_Rsp消息体 */
typedef struct tagTFileCheckRspBody_Api
{
	BOOL32 bExist;
	u32 dwFileSize;
	s8 achFullPathName[KMTAPI_BUF_256_LEN+1];
public:
	tagTFileCheckRspBody_Api() {memset(this, 0, sizeof(tagTFileCheckRspBody_Api));}
}*PTFileCheckRspBody_Api, TFileCheckRspBody_Api;

/** FTP/TELNET 登录信息*/
typedef struct tagTMTFtpTelnetAccountInfo_Api
{
	s8 achUserName[KMTAPI_BUF_32_LEN+1];    ///< 用户名
	s8 achPassword[KMTAPI_BUF_32_LEN+1];     ///< 密码
public:
	tagTMTFtpTelnetAccountInfo_Api() { memset(this, 0, sizeof(tagTMTFtpTelnetAccountInfo_Api) ); }
}*PTMTFtpTelnetAccountInfo_Api, TMTFtpTelnetAccountInfo_Api;

/** 单个麦克状态信息*/
typedef struct tagTMTMicStatus_Api
{
	u32 dwMicId;   ///< 麦克id，参考EmMicDevId_Api
	u32 dwStatus;  ///< 状态
public:
	tagTMTMicStatus_Api() { memset(this, 0, sizeof(tagTMTMicStatus_Api) ); }
}*PTMTMicStatus_Api, TMTMicStatus_Api;

/** 全部的麦克状态信息*/
typedef struct tagTMTAllMicStatus_Api
{
	TMTMicStatus_Api atMicStatus[KMTAPI_COUNT_16];
	u32 dwCnt;
public:
	tagTMTAllMicStatus_Api() { memset(this, 0, sizeof(tagTMTAllMicStatus_Api) ); }
}*PTMTAllMicStatus_Api, TMTAllMicStatus_Api;

typedef struct tagMtcBaseInfo_Api
{
	s8                      achIp[KMTAPI_BUF_32_LEN+1];			//mtc的ip
	EmClientAppType_Api     emAppType;							//客户端类型
	EmAuthType_Api          emAuthType;							//认证方式
	s8                      achUserName[KMTAPI_BUF_32_LEN+1];	//用户名

	tagMtcBaseInfo_Api()
	{
		achIp[0]=0;
		emAppType = emClientAppMTCEnd_Api;
		emAuthType = emAuthEnd_Api;
		achUserName[0]=0;
	}

}*PTMtcBaseInfo_Api, TMtcBaseInfo_Api;

/**  终端登录结果的消息体结构*/
typedef struct tagTMTLoginMtResult_Api
{
	BOOL32             bLogin;                                                    ///< 登录结果(TRUE:成功 FALSE:失败)
	TMtcBaseInfo_Api   tLoginParam;                                               ///< 登录名
	BOOL32             bKickOther;                                                ///< 是否抢占其他人
	TMtcBaseInfo_Api   tKickee;                                                   ///< 被抢占人的基本信息

	BOOL32             bNameExist;                                                ///< 登陆名是否存在
	u32                dwLoginErrCnt;                                             ///< 登陆失败次数
	u32                dwLoginTime;                                               ///< 距离第三次失败已经过了多长时间

	u32				   dwMaxLoginCnt;											  ///< 最大登录次数,超过这个次数就被锁定一定的时间
	u32				   dwMaxLockTime;											  ///< 最大锁定时间
	
	EmMtcLoginFailReason_Api emFailReason;										  ///< 如果登录成功，请忽略这个原因
public:
	tagTMTLoginMtResult_Api() { memset(this, 0, sizeof(tagTMTLoginMtResult_Api)); }
}*PTMTLoginMtResult_Api, TMTLoginMtResult_Api;

/**  终端射频的配对状态*/
typedef struct tagTMTRfMatchState_Api
{
	EmMicDevId_Api emMicId;     ///< 麦克ID
	BOOL32              bMatched;   ///< 是否已配对
	u32                     dwMatchId; ///< 配对ID
public:
	tagTMTRfMatchState_Api() { memset(this, 0, sizeof(tagTMTRfMatchState_Api)); }
}*PTMTRfMatchState_Api, TMTRfMatchState_Api;

/**  终端射频的配对状态列表*/
typedef struct tagTMTRfMatchStateList_Api
{
	u32 dwCnt;
	TMTRfMatchState_Api atStateList[KMTAPI_COUNT_16];
public:
	tagTMTRfMatchStateList_Api() { memset(this, 0, sizeof(tagTMTRfMatchStateList_Api)); }
}*PTMTRfMatchStateList_Api, TMTRfMatchStateList_Api;

/** 抓包文件信息*/
typedef struct tagTNetCapFileInfo_Api
{
	s8    achFileName[KMTAPI_BUF_64_LEN+1]; ///< 文件名
	u32 dwFileSize;                                               ///< 文件大小
public:
	tagTNetCapFileInfo_Api() { memset(this, 0, sizeof(tagTNetCapFileInfo_Api));}
}*PTNetCapFileInfo_Api, TNetCapFileInfo_Api;

/** 抓包文件信息列表*/
typedef struct tagTNetCapFileList_Api
{
	s8                               achFilePath[KMTAPI_BUF_64_LEN+1]; ///< 文件路径
	u8                               byFileCnt;                                              ///< 文件个数
	TNetCapFileInfo_Api atFileList[KMTAPI_COUNT_8];              ///< 文件列表
public:
	tagTNetCapFileList_Api() { memset(this, 0, sizeof(tagTNetCapFileList_Api)); }
}*PTNetCapFileList_Api, TNetCapFileList_Api;

/** 麦克版本信息*/
typedef struct tagTMicVersionInfo_Api
{
	u32 dwMicId;                                                 ///< 麦克id，参考EmMicDevId_Api
	s8    achVersion[KMTAPI_BUF_256_LEN+1]; ///< 版本号
public:
	tagTMicVersionInfo_Api() { memset(this, 0, sizeof(tagTMicVersionInfo_Api)); }
}*PTMicVersionInfo_Api, TMicVersionInfo_Api;

/** 麦克版本信息列表*/
typedef struct tagTMicVersionList_Api
{
	u8 byCnt;                                                                              ///< 列表个数
	TMicVersionInfo_Api atVersionList[KMTAPI_COUNT_16]; ///< 版本信息列表
public:
	tagTMicVersionList_Api() { memset(this, 0, sizeof(tagTMicVersionList_Api)); }
}*PTMicVersionList_Api, TMicVersionList_Api;

/** 登录服务器连接测试结果*/
typedef struct tagTServerTestResult_Api
{
	u32         dwUserId;      ///< 参考EmPingUserId_Api
	BOOL32 bResult;         ///< 测试结果
public:
	tagTServerTestResult_Api() { memset(this, 0, sizeof(tagTServerTestResult_Api)); }
}*PTServerTestResult_Api, TServerTestResult_Api;

/** 麦克风升级状态*/
typedef struct tagTMicUpgradeState_Api
{
    u32 dwMicId;      ///< 麦克id(参考EmMicDevId_Api)
    u32 dwState;       ///< 状态(参考EmMicUpgradeState_Api)
    u32 dwProgress; ///< 进度(dwState为emUploading_Api时有效)
public:
    tagTMicUpgradeState_Api() { memset(this, 0, sizeof(tagTMicUpgradeState_Api)); }
}*PTMicUpgradeState_Api, TMicUpgradeState_Api;

/** 麦克风升级状态列表*/
typedef struct tagTMicUpgradeStateList_Api
{
    u8 dwCnt;                                                                          ///< 总数
    TMicUpgradeState_Api atStateList[KMTAPI_COUNT_8]; ///< 状态列表
public:
    tagTMicUpgradeStateList_Api() { memset(this, 0, sizeof(tagTMicUpgradeStateList_Api)); }
}*PTMicUpgradeStateList_Api, TMicUpgradeStateList_Api;

/** 麦克风安装状态*/
typedef struct tagTMicInstall_Api
{
    u32 dwMicId; ///< 麦克id(参考EmMicDevId_Api)
    u32 dwState; ///< 是否安装(0:不安装 1:安装)
public:
    tagTMicInstall_Api() { memset(this, 0, sizeof(tagTMicInstall_Api)); }
}*PTMicInstall_Api, TMicInstall_Api;

/** 麦克风安装状态列表*/
typedef struct tagTMicInstallList_Api
{
    u32 dwCnt;                                                             ///< 总数
    TMicInstall_Api atInstallList[KMTAPI_COUNT_8]; ///< 安装列表
public:
    tagTMicInstallList_Api() { memset(this, 0, sizeof(tagTMicInstallList_Api)); }
}*PTMicInstallList_Api, TMicInstallList_Api;

/** 是否强制设置H323协议栈为非标/标准*/
typedef struct tagTForceSetH323Stack_Api
{
	BOOL32 bEnable;         ///< 是否强制设置
	BOOL32 bStand;          ///< TRUE:标准 FALSE:非标
public:
	tagTForceSetH323Stack_Api() { memset(this, 0, sizeof(tagTForceSetH323Stack_Api)); }
}*PTForceSetH323Stack_Api, TForceSetH323Stack_Api;

/** 视频输出标签 */
typedef struct tagTMTVideoOutTag_Api
{
	EmHDVideoOutPortType_Api emVideoPortId;
	s8 achVideoPortTag[KMTAPI_BUF_128_LEN+1];
public:
	tagTMTVideoOutTag_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTVideoOutTag_Api, TMTVideoOutTag_Api;

typedef struct tagTMTVideoOutTagList_Api
{
	u8 byCnt;
	TMTVideoOutTag_Api atVidOutTag[KMTAPI_MAX_VIDEO_OUT_NUM];
public:
	tagTMTVideoOutTagList_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTVideoOutTagList_Api, TMTVideoOutTagList_Api;

typedef struct tagTMTFpgaVersionList_Api
{
	u8 byCnt;
	u32 atFpgaVersion[KMTAPI_MAX_VIDEO_OUT_NUM];
public:
	tagTMTFpgaVersionList_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTFpgaVersionList_Api, TMTFpgaVersionList_Api;

typedef struct tagTMTEndPointInfo_Api
{
	s8	achId[KMTAPI_BUF_32_LEN+1];		//终端的id, 当前仅支持e164号
	u32 dwIdLen;						//终端id的长度
	u32 dwStreamId;						//流id
public:
	tagTMTEndPointInfo_Api() { memset( this, 0, sizeof(*this) ); }
}*PTMTEndPointInfo_Api, TMTEndPointInfo_Api;

typedef struct tagTMTNatTraversalInfo_Api
{
	BOOL32		  bEnable;		//是否启用nat穿越
	TNetParam_Api tNetParam;	//地址信息
public:
	tagTMTNatTraversalInfo_Api() { memset( this, 0, sizeof(*this) ); }
}*PTMTNatTraversalInfo_Api, TMTNatTraversalInfo_Api;

/** vrs预约直播室列表请求信息 */ 
typedef struct tagTVodGetResRoomReq_Api
{
	u32	dwNums1Page;		                       ///< 每个页面显示几个节目
	u32	dwPageId;			                   ///< 请求的是哪一页
	s8  achIncludeName[KMTAPI_BUF_128_LEN+1];  ///< 搜索文件名
public:
	tagTVodGetResRoomReq_Api(){ memset ( this ,0 ,sizeof( struct tagTVodGetResRoomReq_Api ) );}
}*PTVodGetResRoomReq_Api, TVodGetResRoomReq_Api;

/** 预约直播室信息 */ 
typedef struct tagTVodResRoomDetail_Api
{
	s8 achConfName[KMTAPI_BUF_128_LEN+1];                     ///< 节目名称
	s8 achStartTime[KMTAPI_BUF_128_LEN+1];                    ///< 预约播放时间
public:
	tagTVodResRoomDetail_Api(){ memset ( this ,0 ,sizeof( struct tagTVodResRoomDetail_Api ) );}
}*PTVodResRoomDetail_Api, TVodResRoomDetail_Api;

/** 预约直播室信息列表 */ 
typedef struct tagTVodResRoomsDetail_Api
{
	TVodResRoomDetail_Api atRoomDetail[KMTAPI_MAX_DIRECTBROADCAST_CNT]; ///< 列表信息
	u32 dwCnt;      ///< 列表个数
                                                                                        
public:
	tagTVodResRoomsDetail_Api()
	{
		dwCnt = 0;
	}
}*PTVodResRoomsDetail_Api, TVodResRoomsDetail_Api;

/**  音频编码参数 */
typedef struct tagTAudEncParam_Api
{
	EmAudFormat_Api   emAudFormat;
	EmAacChnlNum_Api  emAacChnlNum;		//当字段aud_format等于emAMpegAACLC或emAMpegAACLD时才有效
	EmAacSampFreq_Api emAacSampFreq;    //当字段aud_format等于emAMpegAACLC或emAMpegAACLD时才有效
	u32				  dwAacRate;		//当字段aud_format等于emAMpegAACLC或emAMpegAACLD时才有效
	u32				  dwG7221Rate; 	    //当字段aud_format等于emAG7221时才有效
public:
	tagTAudEncParam_Api(){ memset( this ,0 ,sizeof( struct  tagTAudEncParam_Api ) );}
}*PTAudEncParam_Api, TAudEncParam_Api;


/** 无线投屏状态信息 */
typedef struct TagTWifiWirelessScreenInfo_Api	
{
	EmWirelessScreenState_Api  	   emWirelessScreenState;       //是否启用无线投屏 true:启用 false不启用
	u32 					       dwWirelessScreenDeviceNum;	//无线投屏配对设备数量
	EmWirelessScreenErrReason_Api  emWirelessScreenErrReason;	//无线投屏失败错误码
public:
	TagTWifiWirelessScreenInfo_Api(){ memset( this, 0, sizeof( struct TagTWifiWirelessScreenInfo_Api )); }
}*PTWifiWirelessScreenInfo_Api,TWifiWirelessScreenInfo_Api;

/** 导入配置文件的响应信息 */
typedef struct tagTImportMtcfgInfo_Api
{
	EmFileExImErr_Api	emImportErr;  //导入配置文件的错误码
	EmMtModel_Api		emFileModel;  //配置文件型号                                                          
	EmMtModel_Api		emMtModel;	  //终端型号
public:
	tagTImportMtcfgInfo_Api(){ memset( this, 0, sizeof(struct tagTImportMtcfgInfo_Api) ); }
}*PTImportMtcfgInfo_Api, TImportMtcfgInfo_Api;

/**  硬终端本地录像状态错误码信息 */
typedef struct tagTMTVidRecErrInfo_Api
{
	u32							dwChanIdx;		//通道号
	EmVideoRecordErrorNum_Api	emErrNum;
public:
	tagTMTVidRecErrInfo_Api(){ memset( this, 0, sizeof(struct tagTMTVidRecErrInfo_Api) ); }
}*PTMTVidRecErrInfo_Api, TMTVidRecErrInfo_Api;

//商密相关
typedef struct tagTMtSecCertDistinctName_Api
{
	s8 achCountryName[KMTAPI_BUF_64_LEN+1];			// 国家（如中国"CN"），必需，固定2个字符国家代号
	s8 achStateOrProvinceName[KMTAPI_BUF_64_LEN+1];	// 州或省，可选
	s8 achLocalityName[KMTAPI_BUF_64_LEN+1];			// 城市，可选
	s8 achOrganizationName[KMTAPI_BUF_64_LEN+1];		// 组织（如公司），必需
	s8 achOrganizationUnitName[KMTAPI_BUF_64_LEN+1];	// 组织单元（如部门），可选
	s8 achCommonName[KMTAPI_BUF_64_LEN+1];			// 通用名（如域名、IP地址、用户名），必需
	s8 achSerialNumber[KMTAPI_BUF_64_LEN+1];			// 设备序列号
	s8 achEmailAddress[KMTAPI_BUF_64_LEN+1];			// Email地址
public:
	tagTMtSecCertDistinctName_Api(){ memset( this ,0 ,sizeof( struct tagTMtSecCertDistinctName_Api ) ); }
}*PTMtSecCertDistinctName_Api, TMtSecCertDistinctName_Api;

typedef struct tagTMtSecCertValidity_Api
{           
	s8 achNotTimeBefore[KMTAPI_BUF_256_LEN+1];	///< 开始时间，格式为：yymmddhhmmssZ，最后的Z表示格林威治标准时间
	s8 achNotTimeAfter[KMTAPI_BUF_256_LEN+1];	///< 过期时间，格式为：yymmddhhmmssZ，最后的Z表示格林威治标准时间
public:
	tagTMtSecCertValidity_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtSecCertValidity_Api, TMtSecCertValidity_Api;

/** 商密证书ID */
typedef struct tagTMtSecCerId_Api
{
	u8 byLen;                               ///< ID长度
	u8 abyId[KMTAPI_SEC_CAID_LEN+1];		///< ID
public:
	tagTMtSecCerId_Api(){ memset( this, 0, sizeof( struct  tagTMtSecCerId_Api ) ); }	
}*PTMtSecCerId_Api, TMtSecCerId_Api;

typedef struct tagTMtSecCertInfo_Api
{
	s32 nVersion;										   // 证书版本，0表示V1，2表示V3
	s8 achSerialNumber[KMTAPI_BUF_256_LEN+1];              ///< 序列号长度，HEX格式，一般最长20字节
	s8 achSignAlg[KMTAPI_BUF_256_LEN+1];                   ///< 签名算法（字符串）
	TMtSecCertDistinctName_Api   tSecCertDistinctName;     ///< 签发者信息
	TMtSecCertValidity_Api       tSecCertValidity;         ///< 有效期
	TMtSecCertDistinctName_Api   tSecCertUsrName;          ///< 使用者信息
	EmSecCertFormat_Api          emFormat;				   // 证书格式，参见TSecCertFormat
	s8 achPubKeyAlg[KMTAPI_BUF_32_LEN+1];			          ///< 公钥算法（字符串）
	TMtSecCerId_Api              tSecCaId;                ////指纹id
public:
	tagTMtSecCertInfo_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtSecCertInfo_Api, TMtSecCertInfo_Api;

/* 商密 本端或对端认证结果 */
typedef struct tagTMTSecDynPwdCerRet_Api
{
	BOOL32 bLocal;	//是否为本端
	BOOL32 bCerRet;	//是否认证通过
public:
	tagTMTSecDynPwdCerRet_Api(){ memset( this, 0, sizeof(struct tagTMTSecDynPwdCerRet_Api) ); }
}*PTMTSecDynPwdCerRet_Api, TMTSecDynPwdCerRet_Api;

/* 辅视频源的状态信息 */
typedef struct tagTMTAssVidPortStatus_Api
{
	s32		nVgaState;		//Vga是否插入 1:插入 0:未插入 
	s32     nHdmiState;		//Hdmi是否插入1:插入 0:未插入
public:
	tagTMTAssVidPortStatus_Api(){ memset( this, 0, sizeof(struct tagTMTAssVidPortStatus_Api) ); }
}*PTMTAssVidPortStatus_Api, TMTAssVidPortStatus_Api;

/** 商密证书ID列表 */
typedef struct tagTMtCertIDList_Api
{
	u8				byCount;
	TMtSecCerId_Api	atIdList[KMTAPI_SEC_CAID_MAX_NUM];
public:
	tagTMtCertIDList_Api(){ memset( this ,0 ,sizeof( struct tagTMtCertIDList_Api ) );	}
}*PTMtCertIDList_Api, TMtCertIDList_Api;

//开启录像终端成员
typedef struct tagTMTRecordMembers_Api
{
    s8 achMtID[KMTAPI_BUF_64_LEN+1];    //终端ID
public:
    tagTMTRecordMembers_Api() { memset(this, 0, sizeof(struct tagTMTRecordMembers_Api)); }
}*PTMTRecordMembers_Api, TMTRecordMembers_Api;

///开启录像
typedef struct tagTMTStartRecord_Api
{
    s8 achConfID[KMTAPI_BUF_16_LEN+1];                      ///< 会议ID
    s8 achVideoName[KMTAPI_BUF_128_LEN+1];                  ///< 录像保存的文件名称
    EmRecordType_Api  emRecordType;                         ///< 录像类型
    EmPublishMode_Api emPublishMode;                        ///< 发布模式
    EmRecordMode_Api  emRecordMode;                         ///< 录像模式
    BOOL32    bAnonymous;                                   ///< 是否支持免登陆观看直播 FALSE-不支持；TRUE-支持；
    BOOL32    bMainStream;                                  ///< 是否录主格式码流（视频+音频） FALSE-否；TRUE-是；
    BOOL32    bDualStream;                                  ///< 是否录双流（仅双流） FALSE-否；TRUE-是；

    u16       wRecordMemberCnt;                             ///< atRecordMembers数组大小
    s8 achVrsId[KMTAPI_BUF_128_LEN+1];                      ///vrs的id信息,用于指定录像的vrs(新添加的字段)
    TMTRecordMembers_Api atRecordMembers[KMTAPI_COUNT_64];  ///< 开启录像终端数组
public:
    tagTMTStartRecord_Api() { memset(this, 0, sizeof(struct tagTMTStartRecord_Api)); }
}*PTMTStartRecord_Api, TMTStartRecord_Api;

//停止录像
typedef struct tagTMTStopRecord_Api
{
    s8      achConfID[KMTAPI_BUF_16_LEN+1];                  ///< 会议ID
    s8      achRecordID[KMTAPI_BUF_32_LEN+1];                ///< 录像id
    EmRecordMode_Api   emRecordMode;                         ///< 录像模式
public:
    tagTMTStopRecord_Api() { memset(this, 0, sizeof(struct tagTMTStopRecord_Api)); }
}*PTMTStopRecord_Api, TMTStopRecord_Api;

///录像状态信息
typedef struct tagTMTRecordStateInfo_Api
{
    s8 achVideoName[KMTAPI_BUF_128_LEN+1];                  ///< 录像保存的文件名称
    EmRecordType_Api  emRecordType;                         ///< 录像类型
    EmRecordState_Api emRecordState;                        ///< 录像状态
    EmPublishMode_Api emPublishMode;                        ///< 发布模式
    EmRecordMode_Api  emRecordMode;                         ///< 录像模式

    BOOL32    bAnonymous;                                   ///< 是否支持免登陆观看直播 FALSE-不支持；TRUE-支持；
    BOOL32    bMainStream;                                  ///< 是否录主格式码流（视频+音频） FALSE-否；TRUE-是；
    BOOL32    bDualStream;                                  ///< 是否录双流（仅双流） FALSE-否；TRUE-是；
    u32       dwCurrentProgress;                            ///< 当前录像进度, 单位为: 秒

    u16       wRecordMemberCnt;                             ///< atRecordMembers数组大小
    TMTRecordMembers_Api atRecordMembers[KMTAPI_COUNT_64];  ///< 开启录像终端数组
public:
    tagTMTRecordStateInfo_Api() { memset(this, 0, sizeof(struct tagTMTRecordStateInfo_Api)); }
}*PTMTRecordStateInfo_Api, TMTRecordStateInfo_Api;

//修改录像状态
typedef struct tagTMTModifyRecordState_Api
{
    s8      achConfID[KMTAPI_BUF_16_LEN+1];                  ///< 会议ID
    s8      achRecordID[KMTAPI_BUF_32_LEN+1];                ///< 录像id
    EmRecordCmd_Api    emRecordCmd;                          ///< 录像操作指令
    EmRecordMode_Api   emRecordMode;                         ///< 录像模式
public:
    tagTMTModifyRecordState_Api() { memset(this, 0, sizeof(struct tagTMTModifyRecordState_Api)); }
}*PTMTModifyRecordState_Api, TMTModifyRecordState_Api;

///录像列表成员
typedef struct tagTMTRecordListMember_Api
{
    s8 achRecordID[KMTAPI_BUF_32_LEN+1];                    ///< 录像id
    s8 achVideoName[KMTAPI_BUF_128_LEN+1];                  ///< 录像保存的文件名称
    EmRecordType_Api  emRecordType;                         ///< 录像类型
    EmRecordState_Api emRecordState;                        ///< 录像状态
    EmPublishMode_Api emPublishMode;                        ///< 发布模式
    EmRecordMode_Api  emRecordMode;                         ///< 录像模式

    BOOL32    bAnonymous;                                   ///< 是否支持免登陆观看直播 FALSE-不支持；TRUE-支持；
    BOOL32    bMainStream;                                  ///< 是否录主格式码流（视频+音频） FALSE-否；TRUE-是；
    BOOL32    bDualStream;                                  ///< 是否录双流（仅双流） FALSE-否；TRUE-是；
    u32       dwCurrentProgress;                            ///< 当前录像进度, 单位为: 秒

    u16       wRecordMemberCnt;                             ///< atRecordMembers数组大小
    TMTRecordMembers_Api atRecordMembers[KMTAPI_COUNT_64];  ///< 开启录像终端数组
public:
    tagTMTRecordListMember_Api() { memset(this, 0, sizeof(struct tagTMTRecordListMember_Api)); }
}*PTMTRecordListMember_Api, TMTRecordListMember_Api;

///录像信息列表
typedef struct tagTMTRecordList_Api
{
    u32       dwRecordMemberCnt;                                  ///< atRecordListMember数组大小
    TMTRecordListMember_Api atRecordListMember[KMTAPI_COUNT_8];   ///< 录像列表成员
public:
    tagTMTRecordList_Api() { memset(this, 0, sizeof(struct tagTMTRecordList_Api)); }
}*PTMTRecordList_Api, TMTRecordList_Api;

///会议终端信息
typedef struct tagTMTConfTerminalInfo_Api
{
    s8                 achAlias[KMTAPI_BUF_128_LEN+1];     ///< 终端别名
    s8                 achMtID[KMTAPI_BUF_32_LEN+1];       ///< 终端ID
    s8                 achE164[KMTAPI_MAX_MT_E164_LEN+1];  ///< 终端E164号
    s8                 achIP[KMTAPI_BUF_16_LEN+1];         ///< 终端IP
    u32                dwBitrate;                          ///< 呼叫码率

    BOOL32             bOnline;                            ///< 是否在线 TRUE-在线；FALSE-不在线
    BOOL32             bSilence;                           ///< TRUE-静音，FALSE-不静音
    BOOL32             bMute;                              ///< TRUE-哑音，FALSE-不哑音
    BOOL32             bDual;                              ///< 是否在发送双流; TRUE-是，FALSE-否
    BOOL32             bMix;                               ///< 是否在混音; TRUE-是，FALSE-否

    BOOL32             bVMP;                               ///< 是否在合成; TRUE-是，FALSE-否
    BOOL32             bInspection;                        ///< 是否在选看; TRUE-是，FALSE-否
    BOOL32             bRecord;                            ///< 是否在录像; TRUE-是，FALSE-否
    BOOL32             bPoll;                              ///< 是否在轮询; TRUE-是，FALSE-否
    BOOL32             bUpload;                            ///< 是否在上传; TRUE-是，FALSE-否

    EmMtType_Api       emMtType;                           ///< 终端类型
    EmCallMode_Api     emCallMode;                         ///< 呼叫模式 
    EmConfProtocol_Api emProtocol;                         ///< 呼叫协议

public:
    tagTMTConfTerminalInfo_Api() { memset(this, 0, sizeof(struct tagTMTConfTerminalInfo_Api)); }
}*PTMTConfTerminalInfo_Api, TMTConfTerminalInfo_Api;

///会议终端列表
typedef struct tagTMTConfTerminalList_Api
{
    u32       dwCount;                                            ///< atConfTerminalList数组大小
    TMTConfTerminalInfo_Api atConfTerminalList[KMTAPI_COUNT_8];   ///< 会议终端信息列表成员
public:
    tagTMTConfTerminalList_Api() { memset(this, 0, sizeof(struct tagTMTConfTerminalList_Api)); }
}*PTMTConfTerminalList_Api, TMTConfTerminalList_Api;

/** 网络抓包状态信息 */
typedef struct tagTMtNetCapStateInfo_Api
{
	u32			dwState;  //0:操作成功, 1:抓包停止, 2:导出失败, 3:空间不足, 4:文件不存在, 5:路径不存在, 6:正在运行 
	TMTTime_Api	tCurTime;
public:
	tagTMtNetCapStateInfo_Api(){ memset( this ,0 ,sizeof( struct tagTMtNetCapStateInfo_Api ) );	}
}*PTMtNetCapStateInfo_Api, TMtNetCapStateInfo_Api;

/** 当前抓包状态信息 */
typedef struct tagTMtCurCapStatusInfo_Api
{
	u32			dwState;	// 1:正在抓包  0:没有抓包
	TMTTime_Api	tStartTime;	// 抓包开始时间
	u32			dwLastTime;	// 上次抓包时间（单位：毫秒）
	u32			dwStartTime; //开始抓包时间（新版本使用 单位：秒）						
public:
	tagTMtCurCapStatusInfo_Api(){ memset( this ,0 ,sizeof( struct tagTMtCurCapStatusInfo_Api ) ); }
}*PTMtCurCapStatusInfo_Api, TMtCurCapStatusInfo_Api;

/** 商密设备证书信息(标准或国密) */
typedef struct tagTMtSecDevCertInfo_Api
{
	u32				   dwDevCertType;	// 设备证书类型, 1:标准TLS, 2:国密签名，3:国密加密 
	TMtSecCertInfo_Api tCertInfo;		// 证书信息
public:
	tagTMtSecDevCertInfo_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtSecDevCertInfo_Api, TMtSecDevCertInfo_Api;

/** 限定ip段信息 */
typedef struct tagTMtLimitIpInfo_Api
{
	//EmLimitIpType_Api	emLimitType;	//ip限定类型
	u32  				dwStartIp;		//起始ip
	u32  				dwEndIp;		//终止ip
public:
	tagTMtLimitIpInfo_Api(){ memset( this ,0 ,sizeof( struct tagTMtLimitIpInfo_Api ) );	}
}*PTMtLimitIpInfo_Api, TMtLimitIpInfo_Api;

/** 限定ip配置列表 */
typedef struct tagTMtLimitIpInfoList_Api
{
	BOOL32				bEnable;		//0-关闭， 1-启用
	EmLimitIpType_Api	emLimitType;	//ip限定类型
	TMtLimitIpInfo_Api  atIpItemInfo[KMTAPI_MAX_FTPTELNET_LIMIT_IPITEM_CNT];
	u32					dwCnt;
public:
	tagTMtLimitIpInfoList_Api(){ memset( this ,0 ,sizeof( struct tagTMtLimitIpInfoList_Api ) );	}
}*PTMtLimitIpInfoList_Api, TMtLimitIpInfoList_Api;

/** 供网呈使用的串口读写结构体 */
typedef struct tagTMtSerialOptParam_Api
{
	s32		nSerialType;	   //串口类型
	s32     nOperateType;	   //操作类型
	u32     dwListenTime;	   //监听时间(毫秒)
	u8		byLen;             //指令个数
	u8      abyOrder[ KMTAPI_BUF_128_LEN + 1 ];   //操作指令
public:
	tagTMtSerialOptParam_Api(){ memset( this ,0 ,sizeof( struct tagTMtSerialOptParam_Api ) ); }
}*PTMtSerialOptParam_Api, TMtSerialOptParam_Api;

/** 供网呈使用 选择串口使用的回复信息 */
typedef struct tagTMtChooseSerialUse_Api
{
	TMTHDSerialCtrl_Api		tSerialInfo;	   //串口信息
	BOOL32					bIsUse;			   //串口是否使用
	s32						nRet;              //处理结果
public:
	tagTMtChooseSerialUse_Api(){ memset( this ,0 ,sizeof( struct tagTMtChooseSerialUse_Api ) ); }
}*PTMtChooseSerialUse_Api, TMtChooseSerialUse_Api;

/** 创建设备证书信息 */
typedef struct tagTMtSecCreateCertReq_Api
{
	BOOL32  bSignCert;	//是否为签名证书 创建设备证书-->False 创建签名证书-->True
	BOOL32  bResetPwd;	//是否为重新生成密钥
	s8      achDeviceCertFileName[ KMTAPI_BUF_256_LEN + 1 ];
	TMtSecCertDistinctName_Api tSecCertDetail;
public:
	tagTMtSecCreateCertReq_Api(){ memset( this ,0 ,sizeof( struct tagTMtSecCreateCertReq_Api ) ); }
}*PTMtSecCreateCertReq_Api, TMtSecCreateCertReq_Api;

///Vrs登陆成功返回用户信息
typedef struct tagTMTVrsUserInfo_Api
{
	s8                 achToken[KMTAPI_BUF_64_LEN+1];     ///< token
	s8                 achUserDomainMoid[KMTAPI_BUF_32_LEN+1];     ///< userdomainmoid
	s8                 achUserMoid[KMTAPI_BUF_32_LEN+1];     ///< usermoid
public:
	tagTMTVrsUserInfo_Api() { memset(this, 0, sizeof(struct tagTMTVrsUserInfo_Api)); }
}*PTMTVrsUserInfo_Api, TMTVrsUserInfo_Api;

///登陆策略结构
typedef struct tagTMTLoginStrategy_Api
{
	u32                dwLoginCount;   //登录次数(3 -- 10 次)
	u32                dwWaitTime;     //最后一次登录失败需要等待时间(3 -- 10 分钟)
public:
	tagTMTLoginStrategy_Api() { memset(this, 0, sizeof(struct tagTMTLoginStrategy_Api)); }
}*PTMTLoginStrategy_Api, TMTLoginStrategy_Api;






//////////////////////////////////////////////////////////////////////////
// 以下是电子白板结构体

typedef struct tagTDCSRegInfo_Api
{
	s8					achIp[KMTAPI_BUF_128_LEN+1];
	u32					dwPort;
	EmDcsType_Api		emMtType;

	tagTDCSRegInfo_Api() { memset(this, 0, sizeof(tagTDCSRegInfo_Api)); }

}*PTDCSRegInfo_Api, TDCSRegInfo_Api;



typedef struct tagTDCSResult_Api
{
	BOOL32		bSucces;
	u32			dwErrorCode;
	s8			achConfE164[KMTAPI_BUF_64_LEN+1];

	tagTDCSResult_Api() { memset(this, 0, sizeof(tagTDCSResult_Api)); }

}*PTDCSResult_Api, TDCSResult_Api;


typedef struct tagTDCSSetConfInfoResult_Api
{
	BOOL32     	bSucces;
	u32			dwErrorCode;

	s8			achConfE164[KMTAPI_BUF_64_LEN+1];
	s8			achConfName[KMTAPI_BUF_256_LEN+1];
	EmDcsConfMode_Api	emConfMode;
	EmDcsConfType_Api	emConfType;

	tagTDCSSetConfInfoResult_Api() { memset(this, 0, sizeof(tagTDCSSetConfInfoResult_Api)); }

}*PTDCSSetConfInfoResult_Api, TDCSSetConfInfoResult_Api;

typedef struct tagTDCSBoardResult_Api
{
	BOOL32     	bSucces;
	u32			dwErrorCode;

	s8			achConfE164[KMTAPI_BUF_64_LEN+1];
	s8  		achTabId[KMTAPI_BUF_64_LEN+1];
	u32			dwPageId;

	tagTDCSBoardResult_Api() { memset(this, 0, sizeof(tagTDCSBoardResult_Api)); }

}*PTDCSBoardResult_Api, TDCSBoardResult_Api;

//登录APS服务器所需的用户名密码
typedef struct tagTDCSApsLoginParam_Api
{
	s8 achUsername[KMTAPI_BUF_128_LEN+1]; ///< 用户名
	s8 achPassword[KMTAPI_BUF_64_LEN+1]; ///< 明文密码

	tagTDCSApsLoginParam_Api() { memset(this, 0, sizeof(tagTDCSApsLoginParam_Api)); }

}*PTDCSApsLoginParam_Api, TDCSApsLoginParam_Api;

typedef struct tagTDCSOperReq_Api
{
	s8			 achConfE164[KMTAPI_BUF_64_LEN+1];
	s8  		 achTabId[KMTAPI_BUF_64_LEN+1];
	u32			 dwWbPageid;

	tagTDCSOperReq_Api() { memset(this, 0, sizeof(tagTDCSOperReq_Api)); }

}*PTDCSOperReq_Api, TDCSOperReq_Api;

typedef struct tagTDCSFileInfo_Api
{
	s8		achFilePathName[KMTAPI_BUF_512_LEN+1];
	s8		achWbPicentityId[KMTAPI_BUF_64_LEN+1];			// 如果是图片，则会有pic id，否则为空
	s8		achTabid[KMTAPI_BUF_64_LEN+1];
    BOOL32 bElementCacheFile; ///< 是否为图元缓存文件
    u32 dwFileSize;

	tagTDCSFileInfo_Api() { memset( this, 0, sizeof( tagTDCSFileInfo_Api ) ); }

}*PTDCSFileInfo_Api, TDCSFileInfo_Api;


typedef struct tagTDCSConfUserInfo_Api
{
	s8			 achE164[KMTAPI_MAX_MT_E164_LEN+1];
	s8			 achName[KMTAPI_BUF_256_LEN+1];     			// 只有在添加与会方，删除与会方用到
	EmDcsType_Api emMttype;
//	EmDcsRole_Api emRole;         		// 只有在会议里才生效
	BOOL32		 bOnline; 			// 暂时只在获取与会人员列表中有效
	BOOL32		 bIsOper;
	BOOL32		 bIsConfAdmin;

	tagTDCSConfUserInfo_Api() { memset(this, 0, sizeof(tagTDCSConfUserInfo_Api)); }

}*PTDCSConfUserInfo_Api, TDCSConfUserInfo_Api;

typedef struct tagTDCSCreateConf_Api
{
	EmDcsConfType_Api	 emConfType;
	s8					 achConfE164[KMTAPI_BUF_64_LEN+1];
	s8					 achConfName[KMTAPI_BUF_128_LEN+1];
	EmDcsConfMode_Api	 emConfMode;

	u32					 dwListNum;
	TDCSConfUserInfo_Api	 atUserList[KMTAPI_COUNT_192+1];

	s8					achConfAdminE164[KMTAPI_MAX_MT_E164_LEN+1];
	EmDcsType_Api		emAdminMtType;

	tagTDCSCreateConf_Api() { memset(this, 0, sizeof(tagTDCSCreateConf_Api)); }

}*PTDCSCreateConf_Api, TDCSCreateConf_Api;

typedef struct tagTDCSConfAddr_Api
{
	s8		 achIp[KMTAPI_BUF_64_LEN+1];
	s8		 achDomain[KMTAPI_BUF_256_LEN+1];
	u32		 dwPort;

	tagTDCSConfAddr_Api() { memset(this, 0, sizeof(tagTDCSConfAddr_Api)); }

}*PTDCSConfAddr_Api, TDCSConfAddr_Api;

typedef struct tagTDCSCreateConfResult_Api
{
	s8		 achConfE164[KMTAPI_BUF_64_LEN+1];
	s8		 achConfName[KMTAPI_BUF_128_LEN+1];
	BOOL32	 bSuccess;
	u32		 dwErrorCode;

	EmDcsConfMode_Api	emConfMode;
	EmDcsConfType_Api	emConfType; 

	TDCSConfAddr_Api    tConfAddr;

	BOOL32	 bCreator;  ///< 自己是否是这个数据会议的创建者

	tagTDCSCreateConfResult_Api() { memset(this, 0, sizeof(tagTDCSCreateConfResult_Api)); }

}*PTDCSCreateConfResult_Api, TDCSCreateConfResult_Api;

typedef struct tagTDCSInviteUsr_Api
{
	s8			 achConfE164[KMTAPI_BUF_64_LEN+1];
//	s8			 achConfName[KMTAPI_BUF_128_LEN+1];
	TDCSConfAddr_Api     tConfAddr;

	tagTDCSInviteUsr_Api() { memset(this, 0, sizeof(tagTDCSInviteUsr_Api)); }

}*PTDCSInviteUsr_Api, TDCSInviteUsr_Api;

typedef struct tagTDCSJoinConfResult_Api
{
	s8		 achConfE164[KMTAPI_BUF_64_LEN+1];
	s8		 achConfName[KMTAPI_BUF_128_LEN+1];
	EmDcsConfMode_Api	emConfMode;
	EmDcsConfType_Api	emConfType;
	BOOL32	 bSuccess;
	u32 	 dwErrorCode;
	//EmDcsRole_Api	 emRole;
	BOOL32	 bIsOper;
	BOOL32   bIsConfAdmin;

	tagTDCSJoinConfResult_Api() { memset(this, 0, sizeof(tagTDCSJoinConfResult_Api)); }

}*PTDCSJoinConfResult_Api, TDCSJoinConfResult_Api;

typedef struct tagTDCSRejectJoinConf_Api
{
	s8 									achConfE164[KMTAPI_BUF_64_LEN+1];
	EmDcsRejectJoinConfCode_Api  		emReason;

	tagTDCSRejectJoinConf_Api() { memset(this, 0, sizeof(tagTDCSRejectJoinConf_Api)); }

}*PTDCSRejectJoinConf_Api, TDCSRejectJoinConf_Api;

typedef struct tagTDCSMemberInfo_Api
{
	s8					 achConfE164[KMTAPI_BUF_64_LEN+1];

	u32					 dwListNum;
	TDCSConfUserInfo_Api	 atUserList[KMTAPI_COUNT_192+1];

	tagTDCSMemberInfo_Api() { memset(this, 0, sizeof(tagTDCSMemberInfo_Api)); }

}*PTDCSMemberInfo_Api, TDCSMemberInfo_Api;

typedef struct tagTDCSConfInfo_Api
{
	s8	 achConfE164[KMTAPI_BUF_64_LEN+1];
	s8	 achConfName[KMTAPI_BUF_128_LEN+1];
	EmDcsConfMode_Api		 emConfMode;
	EmDcsConfType_Api		 emConfType;

	tagTDCSConfInfo_Api() { memset(this, 0, sizeof(tagTDCSConfInfo_Api)); }

}*PTDCSConfInfo_Api, TDCSConfInfo_Api;


typedef struct tagTDCSOperator_Api
{
	s8		achConfE164[KMTAPI_BUF_64_LEN+1];

	u32							dwListNum;
	TDCSConfUserInfo_Api		atOperList[KMTAPI_COUNT_192+1];

	tagTDCSOperator_Api() { memset(this, 0, sizeof(tagTDCSOperator_Api)); }
}*PTDCSOperator_Api, TDCSOperator_Api;

// typedef struct tagTDCSSetUserRole_Api
// {
// 	s8			 achConfE164[KMTAPI_BUF_64_LEN+1];
// 
// 	u32			 dwListNum;
// 	TDCSConfUserInfo_Api	 atUserList[KMTAPI_COUNT_192+1];   // 这里需要填写用户角色
// 
// 	tagTDCSSetUserRole_Api() { memset(this, 0, sizeof(tagTDCSSetUserRole_Api)); }
// 
// }*PTDCSSetUserRole_Api, TDCSSetUserRole_Api;

typedef struct tagTDCSGetUserList_Api
{
	u32				 dwListNum;
	TDCSConfUserInfo_Api atUserList[KMTAPI_COUNT_192+1];   // 这里有用户角色以及在线状态

	tagTDCSGetUserList_Api() { memset(this, 0, sizeof(tagTDCSGetUserList_Api)); }

}*PTDCSGetUserList_Api, TDCSGetUserList_Api;

typedef struct tagTDCSBoardInfo_Api
{
	s8				 achWbName[KMTAPI_BUF_256_LEN+1];
	EmDcsWbMode_Api	 emWbMode;
	u32 			 dwWbPageNum;
	u32				 dwWbCreateTime;		// 平台成功响应后，平台填写
	s8  			 achTabId[KMTAPI_BUF_64_LEN+1];			// 终端填写
//	s8				 achImagePath[KMTAPI_BUF_512_LEN+1];			// 平台成功响应后，平台填写
//	s8				 achElementPath[KMTAPI_BUF_512_LEN+1];		// 平台成功响应后，平台填写
	u32 			 dwPageId;				
	u32				 dwWbSerialNumber;		// 白板序列号，递增，标记白板创建序号

	s8					achWbCreatorE164[KMTAPI_MAX_MT_E164_LEN+1];
	u32					dwWbWidth;
	u32					dwWbHeight;
	s8					achElementUrl[KMTAPI_BUF_512_LEN+1];
	s8					achDownloadUrl[KMTAPI_BUF_512_LEN+1];
	s8					achUploadUrl[KMTAPI_BUF_512_LEN+1];
//	u32					dwInconvert;

	u32					dwWbAnonyId;			// 平台成功响应后，平台填写（仅限于白板模式）

	tagTDCSBoardInfo_Api() { memset(this, 0, sizeof(tagTDCSBoardInfo_Api)); }

}*PTDCSBoardInfo_Api, TDCSBoardInfo_Api;

typedef struct tagTDCSNewWhiteBoard_Api
{
	s8				 achConfE164[KMTAPI_BUF_64_LEN+1];
	TDCSBoardInfo_Api tBoardinfo;

	tagTDCSNewWhiteBoard_Api() { memset(this, 0, sizeof(tagTDCSNewWhiteBoard_Api)); }

}*PTDCSNewWhiteBoard_Api, TDCSNewWhiteBoard_Api;

typedef struct tagTDCSGetAllBoard_Api
{
	s8				 achConfE164[KMTAPI_BUF_64_LEN+1];

	u32				 dwBoardNum;
	TDCSBoardInfo_Api atBoardInfo[KMTAPI_COUNT_64+1];

	tagTDCSGetAllBoard_Api() { memset(this, 0, sizeof(tagTDCSGetAllBoard_Api)); }

}*PTDCSGetAllBoard_Api, TDCSGetAllBoard_Api;

typedef struct tagTDCSSwitchReq_Api
{
	s8		 achConfE164[KMTAPI_BUF_64_LEN+1];
	s8  	achTabId[KMTAPI_BUF_64_LEN+1];
	u32 	 dwWbPageId;

	tagTDCSSwitchReq_Api() { memset(this, 0, sizeof(tagTDCSSwitchReq_Api)); }

}*PTDCSSwitchReq_Api, TDCSSwitchReq_Api;

typedef struct tagTDCSUserInfo_Api
{
	s8		 achConfE164[KMTAPI_BUF_64_LEN+1];
	s8		 achConfName[KMTAPI_BUF_128_LEN+1];
	TDCSConfUserInfo_Api	 tUserInfo;

	tagTDCSUserInfo_Api() { memset(this, 0, sizeof(tagTDCSUserInfo_Api)); }

}*PTDCSUserInfo_Api, TDCSUserInfo_Api;


typedef struct tagTDCSUserInfos_Api
{
	s8 			 achConfE164[KMTAPI_BUF_64_LEN+1];
	s8 			 achConfName[KMTAPI_BUF_128_LEN+1];

	u32					 dwListNum;
	TDCSConfUserInfo_Api	 atUserInfoList[KMTAPI_COUNT_192+1];

	tagTDCSUserInfos_Api() { memset(this, 0, sizeof(tagTDCSUserInfos_Api)); }

}*PTDCSUserInfos_Api, TDCSUserInfos_Api;


typedef struct tagTDCSUserRole_Api
{
	s8 					 achConfE164[KMTAPI_BUF_64_LEN+1];

	u32					 dwListNum;
	TDCSConfUserInfo_Api	 atUserInfoList[KMTAPI_COUNT_192+1];

	tagTDCSUserRole_Api() { memset(this, 0, sizeof(tagTDCSUserRole_Api)); }

}*PTDCSUserRole_Api, TDCSUserRole_Api;


typedef struct tagTDCSOperContent_Api
{
	EmDcsOper_Api	emOper;
	u32				dwMsgId;
	s8				achTabId[KMTAPI_BUF_64_LEN+1];
	u32				dwWbPageId;
	u32				dwMsgSequence;
	s8				achConfE164[KMTAPI_BUF_64_LEN+1];
	s8				achFromE164[KMTAPI_BUF_64_LEN+1];

	BOOL32			bCacheElement;			// 是否是服务器缓存的图元

	tagTDCSOperContent_Api() { memset(this, 0, sizeof(tagTDCSOperContent_Api)); }

}*PTDCSOperContent_Api, TDCSOperContent_Api;

typedef struct tagTDCSWbPoint_Api
{
	s32	 nPosx;
	s32	 nPosy;

	tagTDCSWbPoint_Api() { memset(this, 0, sizeof(tagTDCSWbPoint_Api)); }

}*PTDCSWbPoint_Api, TDCSWbPoint_Api;

typedef struct tagTDCSWbEntity_Api
{
	s8	 achEntityId[KMTAPI_BUF_64_LEN+1];    // 现在使用GUID来填写
	BOOL32 bLock;

	tagTDCSWbEntity_Api() { memset(this, 0, sizeof(tagTDCSWbEntity_Api)); }

}*PTDCSWbEntity_Api, TDCSWbEntity_Api;


typedef struct tagTDCSWbLine_Api
{
	TDCSWbEntity_Api	 tEntity;     // 基本信息
	TDCSWbPoint_Api 	 tBeginPt;    // 起点坐标
	TDCSWbPoint_Api 	 tEndPt;      // 终端坐标
	u32				 dwLineWidth;	// 线宽
	u32 			 dwRgb;        // 颜色

	tagTDCSWbLine_Api() { memset(this, 0, sizeof(tagTDCSWbLine_Api)); }

}*PTDCSWbLine_Api, TDCSWbLine_Api;

typedef struct tagTDCSWbCircle_Api
{
	TDCSWbEntity_Api  tEntity;         // 基本信息
	TDCSWbPoint_Api  tBeginPt;        // 起点坐标
	TDCSWbPoint_Api  tEndPt;          // 终端坐标
	u32			 dwLineWidth;		 // 线宽
	u32 		 dwRgb;           // 颜色

	tagTDCSWbCircle_Api() { memset(this, 0, sizeof(tagTDCSWbCircle_Api)); }

}*PTDCSWbCircle_Api, TDCSWbCircle_Api;

typedef struct tagTDCSWbRectangle_Api
{
	TDCSWbEntity_Api  tEntity;         // 基本信息
	TDCSWbPoint_Api  tBeginPt;        // 起点坐标
	TDCSWbPoint_Api  tEndPt;          // 终端坐标
	u32			 dwLineWidth;		 // 线宽
	u32 		 dwRgb;           // 颜色

	tagTDCSWbRectangle_Api() { memset(this, 0, sizeof(tagTDCSWbRectangle_Api)); }

}*PTDCSWbRectangle_Api, TDCSWbRectangle_Api;

// 铅笔图元类（画曲线）
typedef struct tagTDCSWbPencil_Api
{
	TDCSWbEntity_Api  tEntity;      // 基本信息

	u32				 dwPointNum;
	TDCSWbPoint_Api 	 atPList[KMTAPI_DCS_POINT_MAX+1]; 		 // 曲线点信息列表

	u32				 dwLineWidth;	 // 线宽
	u32 			 dwRgb;          // 颜色 

	tagTDCSWbPencil_Api() { memset(this, 0, sizeof(tagTDCSWbPencil_Api)); }

}*PTDCSWbPencil_Api, TDCSWbPencil_Api;

// 彩笔图元类（画彩色曲线）
typedef struct tagTDCSWbColorPen_Api
{
	TDCSWbEntity_Api  tEntity;                // 基本信息

	u32				 dwColorPenNum;
	TDCSWbPoint_Api	 atCPList[KMTAPI_DCS_POINT_MAX+1];                  // 曲线点信息列表 
	u32				 dwLineWidth;	           // 线宽
	u32 			 dwRgb;     

	tagTDCSWbColorPen_Api() { memset(this, 0, sizeof(tagTDCSWbColorPen_Api)); }

}*PTDCSWbColorPen_Api, TDCSWbColorPen_Api;

// 图片图元类
typedef struct tagTDCSWbImage_Api
{
	TDCSWbEntity_Api	tEntity;				// 基本信息
	TDCSWbPoint_Api 	tBoardPt;				// 边界矩形左上角坐标
	u32 				dwWidth;				// 边界矩形宽度
	u32 				dwHeight;				// 边界矩形宽度
	EmDcsWbImageState_Api 					emNetworkstate;			// 网络状态信息
	s8 					achFileName[KMTAPI_BUF_256_LEN+1];          // 文件名（utf8编码）
	BOOL32				bBkImg;					// 是否文档底图

	tagTDCSWbImage_Api() { memset(this, 0, sizeof(tagTDCSWbImage_Api)); }

}*PTDCSWbImage_Api, TDCSWbImage_Api;

// 线绘图操作详细信息（已经白板会议中，每操作一次对应的操作信息）
typedef struct tagTDCSWbLineOperInfo_Api
{
	s8  			 achTabId[KMTAPI_BUF_64_LEN+1];            // 白板tab id（guid）
	u32 			 dwSubPageId;        // 子页面id
	TDCSWbLine_Api 	 tLine;             // 线操作信息

	tagTDCSWbLineOperInfo_Api() { memset(this, 0, sizeof(tagTDCSWbLineOperInfo_Api)); }

}*PTDCSWbLineOperInfo_Api, TDCSWbLineOperInfo_Api;

// 圆绘图操作详细信息（已经白板会议中，每操作一次对应的操作信息）
typedef struct tagTDCSWbCircleOperInfo_Api
{
	s8  			 achTabId[KMTAPI_BUF_64_LEN+1];            // 白板tab id（guid）
	u32 			 dwSubPageId;        // 子页面id
	TDCSWbCircle_Api  tCircle;           // 圆操作信息

	tagTDCSWbCircleOperInfo_Api() { memset(this, 0, sizeof(tagTDCSWbCircleOperInfo_Api)); }

}*PTDCSWbCircleOperInfo_Api, TDCSWbCircleOperInfo_Api;

// 矩形绘图操作详细信息（已经白板会议中，每操作一次对应的操作信息）
typedef struct tagTDCSWbRectangleOperInfo_Api
{
	s8  			 achTabId[KMTAPI_BUF_64_LEN+1];            // 白板tab id（guid）
	u32 			 dwSubPageId;        // 子页面id
	TDCSWbRectangle_Api  tRectangle;           // 矩形操作信息

	tagTDCSWbRectangleOperInfo_Api() { memset(this, 0, sizeof(tagTDCSWbRectangleOperInfo_Api)); }

}*PTDCSWbRectangleOperInfo_Api, TDCSWbRectangleOperInfo_Api;



// 铅笔绘图操作详细信息（已经白板会议中，每操作一次对应的操作信息）
typedef struct tagTDCSWbPencilOperInfo_Api
{
	s8  			 achTabId[KMTAPI_BUF_64_LEN+1];            // 白板tab id（guid）
	u32 			 dwSubPageId;        // 子页面id
	TDCSWbPencil_Api  tPencil;           // 铅笔操作信息

	tagTDCSWbPencilOperInfo_Api() { memset(this, 0, sizeof(tagTDCSWbPencilOperInfo_Api)); }

}*PTDCSWbPencilOperInfo_Api, TDCSWbPencilOperInfo_Api;

// 彩笔绘图操作详细信息（已经白板会议中，每操作一次对应的操作信息）
typedef struct tagTDCSWbColorPenOperInfo_Api
{
	s8  			 achTabId[KMTAPI_BUF_64_LEN+1];            // 白板tab id（guid）
	u32 			 dwSubPageId;        // 子页面id
	TDCSWbColorPen_Api	 tColorPen;         // 彩笔操作信息

	tagTDCSWbColorPenOperInfo_Api() { memset(this, 0, sizeof(tagTDCSWbColorPenOperInfo_Api)); }

}*PTDCSWbColorPenOperInfo_Api, TDCSWbColorPenOperInfo_Api;

typedef struct tagTDCSWbImageOperInfo_Api
{
	s8				 achTabId[KMTAPI_BUF_64_LEN+1];                // 白板tab id（guid）
	u32				 dwSubPageId;            // 子页面id
	TDCSWbImage_Api	 tImage;            	// 图片图元操作信息

	tagTDCSWbImageOperInfo_Api() { memset(this, 0, sizeof(tagTDCSWbImageOperInfo_Api)); }

}*PTDCSWbImageOperInfo_Api, TDCSWbImageOperInfo_Api;

// 标记当前操作文档的tab页和subpage
typedef struct tagTDCSWbTabPageIdInfo_Api
{
	s8 	 achTabId[KMTAPI_BUF_64_LEN+1];    		// 白板tab id（guid）
	u32  dwSubPageId;   	// 子页id

	tagTDCSWbTabPageIdInfo_Api() { memset(this, 0, sizeof(tagTDCSWbTabPageIdInfo_Api)); }

}*PTDCSWbTabPageIdInfo_Api, TDCSWbTabPageIdInfo_Api;

typedef struct tagTDCSScrollScreenInfo_Api
{
	s8 			achTabId[KMTAPI_BUF_64_LEN+1]; 		//tab白板页
	u32			dwSubPageId;						//子页ID
	TDCSWbPoint_Api			tPoint;		//滚动到的目标点坐标

	tagTDCSScrollScreenInfo_Api() { memset(this, 0, sizeof(tagTDCSScrollScreenInfo_Api)); }
}*PTDCSScrollScreenInfo_Api, TDCSScrollScreenInfo_Api;

// 删除tab页携带的信息
// typedef struct tagTDCSWbRemovePageIdInfo_Api
// {
// 	s8 	 achTabId[KMTAPI_BUF_256_LEN+1];   			// 白板tab id（guid）
// 	s8 	 achNextTabPageId[KMTAPI_BUF_256_LEN+1];   	// 下一个tab白板页id
// 
// 	tagTDCSWbRemovePageIdInfo_Api() { memset(this, 0, sizeof(tagTDCSWbRemovePageIdInfo_Api)); }
// 
// }*PTDCSWbRemovePageIdInfo_Api, TDCSWbRemovePageIdInfo_Api;


// 白板页信息，在创建白板、更新白板信息等时候使用
// typedef struct tagTDCSWbTabPageInfo_Api
// {
// 	s8 	 achTabId[KMTAPI_BUF_256_LEN+1];             		// 白板tab id（guid），由创建方生成
// 	u32  dwSubPageCount;         	// 子页页数，非文档模式则页数为1
// 	u32  dwMode;                 	// 白板模式：白板或文档
// 	s8 	 achName[KMTAPI_BUF_256_LEN+1];           		// 白板名称，m_bAnoymous为true时，此项为空（utf8编码）
// 	u32  dwAnoymousTabIndex;    	// 不具名Tab页索引，用于没有设定白板名称的白板，用于其名称的构建，比如“新建白板3”，服务器会做修正
// 	u32  dwCanvasWidth;          	// 画布宽度(文档发起方的屏幕宽度)
// 	u32  dwCanvasHeight;         	// 画布高度(文档发起方的屏幕高度)
// 	u32	 dwOwnerIndex;           	// 该白板TAB页文档属主在服务器上的userindex，由服务器填充，填充后通知客户端更新，如果文档属主退出会议，则要标注余下的页面为属主离开状态
// 	u32  dwTime;                	// 创建时间标识，由服务器填充，填充后通知知客户端更新（用于标识白板创建的先后时间，新创建的放在最左边）
// 	BOOL32 bInconvert;         	// office文档是否在转化中
// 
// 	tagTDCSWbTabPageInfo_Api() { memset(this, 0, sizeof(tagTDCSWbTabPageInfo_Api)); }
// 
// }*PTDCSWbTabPageInfo_Api, TDCSWbTabPageInfo_Api;

// 白板中添加子页信息，打开文档时，根据文档的总页数在当前白板中添加多个子页
typedef struct tagTDCSWbAddSubPageInfo_Api
{
	s8 	 achTabId[KMTAPI_BUF_64_LEN+1];             // 白板tab id（guid）
	u32  dwSubPageCount;       // 子页总数，即打开的文档的总页数

	tagTDCSWbAddSubPageInfo_Api() { memset(this, 0, sizeof(tagTDCSWbAddSubPageInfo_Api)); }

}*PTDCSWbAddSubPageInfo_Api, TDCSWbAddSubPageInfo_Api;


// 切换白板页信息，切换白板页包括两种情况：
// 1)在当前白板中从一个子页切换到另一子页，即前后翻页，或者翻到指定的页面；
// 2)切换到另一个白板中
// typedef struct tagTDCSWbSwitchPageInfo_Api
// {
// 	s8 	 achTabId[KMTAPI_BUF_64_LEN+1];             // 白板tab id（guid）
// 	u32  dwSubPageId;              // 子页id
// 
// 	tagTDCSWbSwitchPageInfo_Api() { memset(this, 0, sizeof(tagTDCSWbSwitchPageInfo_Api)); }
// 
// }*PTDCSWbSwitchPageInfo_Api, TDCSWbSwitchPageInfo_Api;

// 客户端给服务器发送请求目标页图片请求
// typedef struct tagTDCSWbReqPageImage_Api
// {
// 	s8 	 achImgId[KMTAPI_BUF_256_LEN+1];         // 请求的图片图元id（guid）
// 	s8 	 achTabId[KMTAPI_BUF_64_LEN+1];         // 白板tab id（guid）
// 	u32  dwSubPageId;        // 当前子页id
// 	u32  dwOwnerIndex;       // 该白板页文档属主在服务器上的userindex，服务器收到请求后，需要给该index对应的属主发请求
// 
// 	tagTDCSWbReqPageImage_Api() { memset(this, 0, sizeof(tagTDCSWbReqPageImage_Api)); }
// 
// }*PTDCSWbReqPageImage_Api, TDCSWbReqPageImage_Api;

// 矩形擦除
typedef struct tagTDCSWbEraseOperInfo_Api
{
	s8 				achTabId[KMTAPI_BUF_64_LEN+1];            // 白板tab id（guid）
	u32				dwSubPageId;	
	TDCSWbPoint_Api	 tBeginPt;          // 矩形擦除区域的开始坐标（此参数矩形擦除使用）
	TDCSWbPoint_Api	 tEndPt;            // 矩形擦除区域的结束坐标（此参数矩形擦除使用）

	BOOL32			bNexVision;				// 是否是网呈终端

	tagTDCSWbEraseOperInfo_Api() { memset(this, 0, sizeof(tagTDCSWbEraseOperInfo_Api)); }

}*PTDCSWbEraseOperInfo_Api, TDCSWbEraseOperInfo_Api;

// 放大/缩小、横向/纵向自适应
typedef struct tagTDCSWbZoomInfo_Api
{
	s8 	 achTabId[KMTAPI_BUF_64_LEN+1];       // 白板tab id（guid）
	u32  dwZoom;           // 当前页缩放倍数，取百分制，例如100.0，对应100%

	tagTDCSWbZoomInfo_Api() { memset(this, 0, sizeof(tagTDCSWbZoomInfo_Api)); }

}*PTDCSWbZoomInfo_Api, TDCSWbZoomInfo_Api;



// 全屏显示/100比例显示
typedef struct tagTDCSWbDisPlayInfo_Api
{
	s8 				achTabId[KMTAPI_BUF_64_LEN+1];		//tab白板页
	u32				dwSubPageId;		//子页ID
	s8				aachMatrixValue[ KMTAPI_DCS_MATRIXVALUE+1 ][KMTAPI_BUF_32_LEN+1];		

	tagTDCSWbDisPlayInfo_Api() { memset(this, 0, sizeof(tagTDCSWbDisPlayInfo_Api)); }

}*PTDCSWbDisPlayInfo_Api, TDCSWbDisPlayInfo_Api;


// 区域矩形擦除
typedef struct tagTDCSWbReginEraseOperInfo_Api
{
	s8 					achTabId[KMTAPI_BUF_64_LEN+1];            // 白板tab id（guid）
	u32 				dwSubPageId;   	// 子页id
	s8					achGraphsId[KMTAPI_BUF_128_LEN+1];		// 图元ID
	u32					dwEraseWidth;
	u32					dwEraseHeight;

	u32					dwPointCount;
	TDCSWbPoint_Api		atPoint[KMTAPI_DCS_POINT_MAX+1];

	tagTDCSWbReginEraseOperInfo_Api() { memset(this, 0, sizeof(tagTDCSWbReginEraseOperInfo_Api)); }

}*PTDCSWbReginEraseOperInfo_Api, TDCSWbReginEraseOperInfo_Api;

//插入图片
typedef struct tagTDCSWbInsertPicOperInfo_Api
{
	s8 					achTabId[KMTAPI_BUF_64_LEN+1];            // 白板tab id（guid）
	u32 				dwSubPageId;   	// 子页id
	s8					achImgId[KMTAPI_BUF_128_LEN+1];		// 图元ID
	u32					dwImgWidth;
	u32					dwImgHeight;
	TDCSWbPoint_Api		tPoint;
	s8					achPicName[KMTAPI_BUF_128_LEN+1];

	s8					aachMatrixValue[ KMTAPI_DCS_MATRIXVALUE+1 ][KMTAPI_BUF_32_LEN+1];

	tagTDCSWbInsertPicOperInfo_Api() { memset(this, 0, sizeof(tagTDCSWbInsertPicOperInfo_Api)); }

}*PTDCSWbInsertPicOperInfo_Api, TDCSWbInsertPicOperInfo_Api;


typedef struct tagTDCSWbGraphsInfo_Api
{
	s8					achGraphsId[KMTAPI_BUF_128_LEN+1];		// 图元ID
	s8					aachMatrixValue[ KMTAPI_DCS_MATRIXVALUE+1 ][KMTAPI_BUF_32_LEN+1];

	tagTDCSWbGraphsInfo_Api() { memset(this, 0, sizeof(tagTDCSWbGraphsInfo_Api)); }
}*PTDCSWbGraphsInfo_Api, TDCSWbGraphsInfo_Api;

// 选中图片（准备进行操作）
typedef struct tagTDCSWbPitchPicOperInfo_Api
{
	s8 					achTabId[KMTAPI_BUF_64_LEN+1];            // 白板tab id（guid）
	u32 				dwSubPageId;   	// 子页id

	u32					dwGraphsCount;
	TDCSWbGraphsInfo_Api	atGraphsInfo[KMTAPI_DCS_PIC_MAX+1];

	tagTDCSWbPitchPicOperInfo_Api() { memset(this, 0, sizeof(tagTDCSWbPitchPicOperInfo_Api)); }

}*PTDCSWbPitchPicOperInfo_Api, TDCSWbPitchPicOperInfo_Api;


// 选中删除图片
typedef struct tagTDCSWbDelPicOperInfo_Api
{
	s8 					achTabId[KMTAPI_BUF_64_LEN+1];            // 白板tab id（guid）
	u32 				dwSubPageId;   	// 子页id

	u32					dwGraphsCount;
	s8					achGraphsId[KMTAPI_DCS_POINT_MAX+1][KMTAPI_BUF_128_LEN+1];

	tagTDCSWbDelPicOperInfo_Api() { memset(this, 0, sizeof(tagTDCSWbDelPicOperInfo_Api)); }

}*PTDCSWbDelPicOperInfo_Api, TDCSWbDelPicOperInfo_Api;













// 发送图片文件的信息
// typedef struct tagTDCSWbSendImgFileInfo_Api
// {
// 	u32	 dwFileSize;          // 文件大小
// 	s8 	 achFileId[KMTAPI_BUF_128_LEN+1];       // 图片文件id（即图片图元id）
// 	s8 	 achFileName[KMTAPI_BUF_512_LEN+1];    // 文件完整路径（utf8编码）
// 
// 	tagTDCSWbSendImgFileInfo_Api() { memset(this, 0, sizeof(tagTDCSWbSendImgFileInfo_Api)); }
// 
// }*PTDCSWbSendImgFileInfo_Api, TDCSWbSendImgFileInfo_Api;

typedef struct tagTDCSOperNtf_Api
{
	EmDcsOper_Api emOper;
	u32 		 dwMsgId;
	s8			achTabId[KMTAPI_BUF_64_LEN+1];
	u32 		 dwWbPageId;

	tagTDCSOperNtf_Api() { memset(this, 0, sizeof(tagTDCSOperNtf_Api)); }

}*PTDCSOperNtf_Api, TDCSOperNtf_Api;

typedef struct tagTDCSConnectResult_Api
{
	BOOL32 		bSuccess;
	EmDcsConnectErrCode_Api		emErrorCode;

	tagTDCSConnectResult_Api() { memset(this, 0, sizeof(tagTDCSConnectResult_Api)); }

}*PTDCSConnectResult_Api, TDCSConnectResult_Api;


typedef struct tagTDCSImageUrl_Api
{
	s8			achConfE164[KMTAPI_BUF_64_LEN+1];
	s8			achTabId[KMTAPI_BUF_64_LEN+1];
	u32			dwPageId;
	s8			achPicUrl[KMTAPI_BUF_256_LEN+1];
	s8			achWbPicentityId[KMTAPI_BUF_64_LEN+1];		// 图片ID

	tagTDCSImageUrl_Api() { memset(this, 0, sizeof(tagTDCSImageUrl_Api)); }

}*PTDCSImageUrl_Api, TDCSImageUrl_Api;

typedef struct tagTDCSFileLoadResult_Api
{
    BOOL32		bSuccess;
    BOOL32		bElementFile;
    s8          achFilePathName[KMTAPI_BUF_512_LEN+1];
	s8			achWbPicentityId[KMTAPI_BUF_64_LEN+1];
	s8			achTabid[KMTAPI_BUF_64_LEN+1];

    tagTDCSFileLoadResult_Api() { memset( this, 0, sizeof( tagTDCSFileLoadResult_Api ) ); }

}*PTDCSFileLoadResult_Api, TDCSFileLoadResult_Api;

//用户域信息
typedef struct tagTMTUserDomainInfo_Api
{
    s8  achMoid[KMTAPI_BUF_64_LEN + 1];         ///< 用户域moid
    s8  achName[KMTAPI_BUF_128_LEN + 1];        ///< 用户域名称
    s8  achGroupName[KMTAPI_BUF_128_LEN + 1];   ///< 集团名称
    s8  achParentId[KMTAPI_BUF_64_LEN+1];       ///< 父用户域的moid，空值代表顶级
    u32 dwVersion;                              ///< 版本号

    tagTMTUserDomainInfo_Api() { memset( this, 0, sizeof( tagTMTUserDomainInfo_Api ) ); }

}*PTMTUserDomainInfo_Api, TMTUserDomainInfo_Api;

typedef struct tagTMTUserDomains_Api
{
    u32 dwCount;                                           ///< atUserDomain数据填充数量
    TMTUserDomainInfo_Api atUserDomain[KMTAPI_COUNT_16];   ///< 用户域信息

    tagTMTUserDomains_Api() { memset( this, 0, sizeof( tagTMTUserDomains_Api ) ); }

}*PTMTUserDomains_Api, TMTUserDomains_Api;

//用户域部门信息
typedef struct tagTMTUserDomainDepartmentInfo_Api
{
    s8      achMoid[KMTAPI_BUF_64_LEN + 1];             ///< 部门moid
    u32     dwDepartmentId;                             ///< 部门ID
    s8      achDepartmentName[KMTAPI_BUF_128_LEN + 1];  ///< 部门名称
    u32     dwParentId;                                 ///< 父节点的部门ID
    BOOL32  bLeaf;                                      ///< 是否含有子节点：ture：没有；false：有

    tagTMTUserDomainDepartmentInfo_Api() { memset( this, 0, sizeof( tagTMTUserDomainDepartmentInfo_Api ) ); }

}*PTMTUserDomainDepartmentInfo_Api, TMTUserDomainDepartmentInfo_Api;

//用户域部门信息集合
typedef struct tagTMTUserDomainDepartments_Api
{
    u32 dwCount;                                                     ///< atUserDomainDept数据填充数量
    TMTUserDomainDepartmentInfo_Api atUserDomainDept[KMTAPI_COUNT_16];   ///< 用户域部门信息

    tagTMTUserDomainDepartments_Api() { memset( this, 0, sizeof( tagTMTUserDomainDepartments_Api ) ); }

}*PTMTUserDomainDepartments_Api, TMTUserDomainDepartments_Api;

/** 操作指令 */
typedef struct tagTMTOrder_Api
{
	u8	byCount;							//指令个数
	u8  abyOrder[ KMTAPI_BUF_128_LEN + 1 ]; //指令内容  
public:
	tagTMTOrder_Api(){ memset( this ,0 ,sizeof( struct tagTMTOrder_Api ) ); }
}*PTMTOrder_Api, TMTOrder_Api;

/*集团公共群组*/
typedef struct tagTMTPublicGroupInfo_Api
{
    s8  achMoid[KMTAPI_BUF_64_LEN+1];				   ///< 群组moid
    s8  achName[KMTAPI_BUF_128_LEN+1];                 ///< 群组名称
    s8  achParentMoid[KMTAPI_BUF_64_LEN+1];			   ///< 父群组moid
public:
    tagTMTPublicGroupInfo_Api() { memset( this, 0, sizeof(tagTMTPublicGroupInfo_Api) ); }
}*PTMTPublicGroupInfo_Api, TMTPublicGroupInfo_Api;

/*集团公共群组*/
typedef struct tagTMTPublicGroups_Api
{
    u32 dwGroupNum;                                          //账号信息 数组实际数量
    TMTPublicGroupInfo_Api atGroupInfo[KMTAPI_COUNT_16];     //账号信息
public:
    tagTMTPublicGroups_Api() { memset( this, 0, sizeof(tagTMTPublicGroups_Api) ); }
}*PTMTPublicGroups_Api, TMTPublicGroups_Api;

/*集团公共群组人员信息*/
typedef struct tagMTPublicGroupUserInfo_Api
{
    s8 achMoid[KMTAPI_BUF_64_LEN+1];				 ///< 账号moid
    s8 achJid[KMTAPI_BUF_256_LEN+1];	             ///< xmpp账号
    s8 achAccount[KMTAPI_BUF_128_LEN+1];	         ///< 自定义账号
    s8 achEmail[KMTAPI_BUF_128_LEN+1];			     ///< 电子邮件，如“sunfei@kedacom.com”
    s8 achE164[KMTAPI_BUF_64_LEN+1];	             ///< E164
    s8 achMobile[KMTAPI_BUF_64_LEN+1];               ///< 联系电话
    s8 achName[KMTAPI_BUF_128_LEN+1];                ///< 姓名
    s8 achGroupMoid[KMTAPI_BUF_64_LEN+1];		     ///< 群组moid
    s8 achExtNum[KMTAPI_BUF_128_LEN+1];				 ///< 分机
    s8 achSeat[KMTAPI_BUF_256_LEN+1];				 ///< 座位号
    s8 achBrief[KMTAPI_BUF_512_LEN+1];			     ///< 简介
    s8 achPortrait40[KMTAPI_BUF_256_LEN+1];	         ///< 用户头像（40像素）
    s8 achPortrait64[KMTAPI_BUF_256_LEN+1];          ///< 用户头像（64像素）
    s8 achPortrait128[KMTAPI_BUF_256_LEN+1];         ///< 用户头像（64像素）
public:
    tagMTPublicGroupUserInfo_Api() { memset(this, 0, sizeof(tagMTPublicGroupUserInfo_Api )); }
}*PTMTPublicGroupUserInfo_Api, TMTPublicGroupUserInfo_Api;

/*集团公共群组所有人员信息*/
typedef struct tagTMTPublicGroupUsers_Api
{
    u32 dwUserNum;                                          //人员信息,数组实际数量
    TMTPublicGroupUserInfo_Api atUserInfo[KMTAPI_COUNT_16]; //人员信息
public:
    tagTMTPublicGroupUsers_Api() { memset( this, 0, sizeof(tagTMTPublicGroupUsers_Api) ); }
}*PTMTPublicGroupUsers_Api, TMTPublicGroupUsers_Api;


typedef struct tagTMTPushSrvReq_Api
{
	s8 		achUserName[KMTAPI_BUF_64_LEN+1];		///< 用户名
	s8		achPassword[KMTAPI_BUF_64_LEN+1];		///< 密码
	s8		achVersion[KMTAPI_BUF_64_LEN+1];		///< 版本号
	s8		achUserMoid[KMTAPI_BUF_64_LEN+1];		///< 用户moid
	s8		achE164[KMTAPI_MAX_MT_E164_LEN+1]; 		///< E164
	s8		achMtType[KMTAPI_BUF_64_LEN+1];			///< 移动终端类型（PHONE/PAD）
	s8		achAliDeviceId[KMTAPI_BUF_64_LEN+1];	///< 阿里云分配的设备标识（终端连接阿里云服务器，阿里云给终端设备分配的唯一标识，推送通知时使用）
	s8		achAliAppkey[KMTAPI_BUF_64_LEN+1];		///< 阿里云推送应用的AppKey，推送通知时使用
	s8		achMtsysType[KMTAPI_BUF_64_LEN+1];		///< 移动终端使用的操作系统（ANDROID，IOS）
	s8		achMtsyslan[KMTAPI_BUF_64_LEN+1];		///< 移动终端使用的操作系统语言（CHINESE，ENGLISH）
	s8		achDeviceId[KMTAPI_BUF_64_LEN+1];		///< 设备标识（不同于alideviceid，等同于UPU在线终端中deviceid）
	u32		dwSrvIp;								///< 推送服务器IP
	s8		achJid[KMTAPI_BUF_64_LEN+1];			///< JID
public:
    tagTMTPushSrvReq_Api() { memset( this, 0, sizeof(tagTMTPushSrvReq_Api) ); }
	
}*PTMTPushSrvReq_Api, TMTPushSrvReq_Api;


typedef struct tagTMTPushSrvResult_Api
{
	BOOL32 	bSuccess;
	u32 	dwErrCode; 
	
public:
    tagTMTPushSrvResult_Api() { memset( this, 0, sizeof(tagTMTPushSrvResult_Api) ); }
	
}*PTMTPushSrvResult_Api, TMTPushSrvResult_Api;

/* ISP 图像降噪信息 */
typedef struct tagTMTIspImgNFInfo_Api 
{
	EmNFType_Api emType;	//降噪类型
	u8			 byValue;	//降噪值
public:
	tagTMTIspImgNFInfo_Api() { memset( this, 0, sizeof(struct tagTMTIspImgNFInfo_Api) ); }
}*PTMTIspImgNFInfo_Api, TMTIspImgNFInfo_Api;

/* ISP 图像锐度信息，暂时为一个u8字段，以后可能扩展 */
typedef struct tagTMTIspImgSharpnessInfo_Api 
{
	u8			 byValue;	//锐度值
public:
	tagTMTIspImgSharpnessInfo_Api() { memset( this, 0, sizeof(struct tagTMTIspImgSharpnessInfo_Api) ); }
}*PTMTIspImgSharpnessInfo_Api, TMTIspImgSharpnessInfo_Api;

/* ISP 图像曝光增益限制 */
typedef struct tagTMTIspImgExposureGain_Api
{
	EmExposureGainType_Api	emType;	//增益类型
	EmExposureGain_Api      emGain; //增益值
public:
	tagTMTIspImgExposureGain_Api() { memset( this, 0, sizeof(struct tagTMTIspImgExposureGain_Api) ); }
}*PTMTIspImgExposureGain_Api, TMTIspImgExposureGain_Api;

/* ISP 图像白平衡增益限制,用于手动模式 */
typedef struct tagTMTIspImgWBAGainInfo_Api
{
	EmWBAGainType_Api	emType;	//增益类型
	u32					dwGain; //增益值
public:
	tagTMTIspImgWBAGainInfo_Api() { memset( this, 0, sizeof(struct tagTMTIspImgWBAGainInfo_Api) ); }
}*PTMTIspImgWBAGainInfo_Api, TMTIspImgWBAGainInfo_Api;



typedef struct tagGmTestResult_Api
{
	EmEncryptArithmetic_Api emEncrypt;
	s32 	    dwErrorCode;   //0 代表成功  ，其他代表失败
	tagGmTestResult_Api() { memset(this, 0, sizeof(tagGmTestResult_Api)); }

}*PTtagGmTestResult_Api, TGmTestResult_Api;

// 国密自测试以及随机数自测试结果
typedef struct tagGmAndRandomNumTest_Api
{
	u32      dwListNum;
	TGmTestResult_Api  atGmTestResult[KMTAPI_COUNT_8 + 1];

	s32  dwRandomNumTestResult;
	tagGmAndRandomNumTest_Api() { memset(this, 0, sizeof(tagGmAndRandomNumTest_Api)); }

}*PTGmAndRandomNumTest_Api, TGmAndRandomNumTest_Api;

typedef struct tagTDcsCacheElementParseResult_Api
{
    s8 achTabId[KMTAPI_BUF_64_LEN+1]; ///< 子页所在的白板id
    u32 dwMsgSequence;                           ///< 最后一个图元的序号
    BOOL32 bParseSuccess;                        ///< 解析成功
    tagTDcsCacheElementParseResult_Api() { memset( this, 0, sizeof( tagTDcsCacheElementParseResult_Api ) ); }
}*PTDcsCacheElementParseResult_Api, TDcsCacheElementParseResult_Api;


typedef struct tagTMtQtAddr_Api
{ 
	BOOL32  bEnable;
	s8      achQtIp[KMTAPI_BUF_32_LEN+1];         //qt ip 
	u32     dwQtPort;                             //qt port 
	s8      achQtUserName[KMTAPI_BUF_128_LEN+1];  //qt 用户名
	s8      achQtPassword[KMTAPI_BUF_128_LEN+1];  //qt 密码
	tagTMtQtAddr_Api() { memset( this, 0, sizeof( tagTMtQtAddr_Api ) ); }
}*PTMtQtAddr_Api, TMtQtAddr_Api;

typedef struct TagTMtSecKeyUpdatePolicy_Api
{
	EmSecKeyUpdateMode_Api   emSecKeyUpdateMode;   //按时间更新密钥还是按包数更新密钥
	u32               dwKeyUpdatePeriod;   //多长更新一次(s)
	u32               dwKeyUpdatePackCnt;   //多少包更新一次
	TagTMtSecKeyUpdatePolicy_Api() { memset( this, 0, sizeof( TagTMtSecKeyUpdatePolicy_Api ) ); }
}*PTMtSecKeyUpdatePolicy_Api,TMtSecKeyUpdatePolicy_Api;

//摄像机图像模式
typedef struct tagTMtCameraImgInfo_Api
{
	EmCameraImgMode_Api emImgMode;
public:
	tagTMtCameraImgInfo_Api() { memset( this, 0, sizeof(struct tagTMtCameraImgInfo_Api) ); }
}*PTMtCameraImgInfo_Api, TMtCameraImgInfo_Api;

//设置摄像机场景模式的返回信息
typedef struct tagTMtCameraSceneModeInfo_Api
{
	u32						dwVidIdx;		//摄像机No
	EmCameraSceneMode_Api	emSceneMode;	//场景模式
	u32						dwRet;			//结果
public:
	tagTMtCameraSceneModeInfo_Api() { memset( this, 0, sizeof(struct tagTMtCameraSceneModeInfo_Api) ); }
}*PTMtCameraSceneModeInfo_Api, TMtCameraSceneModeInfo_Api;

// 摄像机场景模式能力
typedef struct tagTMtCameraSceneModeCapList_Api
{
	u32 dwVidIdx;						//摄像机编号
	u8	byCnt;							// 能力个数 
	u8	abySceneList[KMTAPI_COUNT_16];	// EmCameraSceneMode_Api
public:
	tagTMtCameraSceneModeCapList_Api() { memset( this, 0, sizeof(struct tagTMtCameraSceneModeCapList_Api) ); }
}*PTMtCameraSceneModeCapList_Api, TMtCameraSceneModeCapList_Api;

//渠道终端的license证书信息
typedef struct tagTMtAgentLicenseInfo_Api
{
	EmLicenseKeyCheckValue_Api emCheckValue;	//证书验证结果
	EmVersionType_Api          emVerType;		//版本类型
	EmMtModel_Api			   emMtModel;		//设备型号
	BOOL32					   bChannelAccess;	//渠道授权
	BOOL32					   bHybridcloudAccess;	//混合云登录授权
	BOOL32					   bPubliccloudAccess;	//公有云登陆授权
	s8			achMtDeviceId[KMTAPI_BUF_128_LEN];  //设备序列号
	s8			achUserType[KMTAPI_BUF_128_LEN];            //用户类型
	s8			achContractNode[KMTAPI_BUF_128_LEN];        //合同号
	s8			achCustomerName[KMTAPI_BUF_128_LEN];        //客户名称
	s8			achCustomerAddress[KMTAPI_BUF_128_LEN];     //客户地址
	s8			achSerler[KMTAPI_BUF_128_LEN];				//销售人员
	s8			achDescription[KMTAPI_BUF_128_LEN];			//备注

public:
	tagTMtAgentLicenseInfo_Api() { memset( this, 0, sizeof(struct tagTMtAgentLicenseInfo_Api) ); }
}*PTMtAgentLicenseInfo_Api, TMtAgentLicenseInfo_Api;

/** VGA输出图像调节 */	
typedef struct tagTMTVgaImgOutAdjustCfg_Api
{
	s32 nVga1ImgOffset; 	   ///<VGA1图像偏移
	s32 nVga2ImgOffset; 	   ///<VGA2图像偏移
public:
	tagTMTVgaImgOutAdjustCfg_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTVgaImgOutAdjustCfg_Api, TMTVgaImgOutAdjustCfg_Api;

typedef struct tagTMtcLoginParam_Api
{
	EmClientAppType_Api   emAppType;
	EmAuthType_Api        emAuthMode;
	s8                    achUsrName[KMTAPI_BUF_32_LEN+1];  
	s8                    achPwd[KMTAPI_BUF_64_LEN+1];
	s8                    achMtIp[KMTAPI_BUF_32_LEN+1];
	u16                   wMtListenPort;
public:
	tagTMtcLoginParam_Api()
	{
		memset( this, 0, sizeof(struct tagTMtcLoginParam_Api) );
		
		emAuthMode = emAuthEnd_Api;
		emAppType = emClientAppMTCEnd_Api;
		wMtListenPort = KMTAPI_MT_LISTEN_PORT;
	}

}*PTMtcLoginParam_Api,TMtcLoginParam_Api;

//Mtc信息列表
typedef struct tagTMtcBaseInfoList_Api 
{
	TMtcBaseInfo_Api atMtcList[KMTAPI_COUNT_16];
	u8				 byCnt;
public:
	tagTMtcBaseInfoList_Api() { memset( this, 0, sizeof(struct tagTMtcBaseInfoList_Api) ); }
}*PTMtcBaseInfoList_Api, TMtcBaseInfoList_Api;

////终端版本信息
typedef struct tagTMtVersionInfo_Api
{
	s8              achMtIp[KMTAPI_BUF_128_LEN+1];      //终端ip
	s8				achVersion[KMTAPI_BUF_128_LEN+1];   ///终端版本 
	EmMtModel_Api	emModel;						    ///终端型号
	BOOL32			bIsSupportSec;					    ///是否支持商密 
	
	TMtcBaseInfoList_Api tMtcList;						//mtc信息列表
public:
	tagTMtVersionInfo_Api() { memset( this, 0, sizeof(struct tagTMtVersionInfo_Api) ); }
}*PTMtVersionInfo_Api, TMtVersionInfo_Api;


typedef struct tagTServerLoginPort
{
    u32 dwHttpPort;      //http协议端口
    u32 dwHttpsPort;     //https协议端口
    tagTServerLoginPort()
	{ 
		dwHttpPort  = 60080;
		dwHttpsPort = 60090;
	}
}*PTServerLoinPort, TServerLoginPort_Api;

// 内置摄像机采集制式
typedef struct tagTCameraVidStd_Api
{
	EmCameraVidStd_Api emVidType;    
	s8                 achVidName[128+1];    
	tagTCameraVidStd_Api(){ memset(this, 0, sizeof(tagTCameraVidStd_Api)); }
}*PTCameraVidStd_Api, TCameraVidStd_Api;


//srtp参数上报
typedef struct TagTMtSrtpCrypto_Api
{
	EmSrtpCryptoType_Api emSrtpCryptoType;    ///秘钥类型
	EmSrtpAuthType_Api emSrtpAuthType;        ///秘钥类型
	u32 dwSrtpTag;                            ///tag值
	s8  achCryptoKey[KMTAPI_BUF_64_LEN+1];    ///秘钥key值
	s8  achCryptoKeyId[KMTAPI_BUF_64_LEN+1];  ///私钥keyid
	u32 dwCryptoKeyIdLen;                     ///keyid长度
	s8  achBkRtcpCryptoKey[KMTAPI_BUF_64_LEN+1]; //bkrtcp key 

	TagTMtSrtpCrypto_Api(){ memset(this,0,sizeof(TagTMtSrtpCrypto_Api)); }
}*PTMtSrtpCrypto_Api,TMtSrtpCrypto_Api;

typedef struct tagTAgentLogFileInfo_Api
{
    s8  achFileName[KMTAPI_BUF_64_LEN+1];  //压缩文件名称
    s8  achFilePath[KMTAPI_BUF_128_LEN+1]; //文件路径以斜杠结尾“/xxx/xxx/”
    tagTAgentLogFileInfo_Api(){ memset(this, 0, sizeof(tagTAgentLogFileInfo_Api)); }
}*PTAgentLogFileInfo_Api, TAgentLogFileInfo_Api;

//投屏器状态信息
typedef struct tagTMtQkState_Api
{
	u32             dwQkId;		//投屏器序号
	EmQkState_Api	emState;    //状态
	s8				achPcName[KMTAPI_BUF_128_LEN+1];   //Pc名称
	s8				achQkVer[KMTAPI_BUF_128_LEN+1];    //版本
	tagTMtQkState_Api(){ memset( this,0,sizeof(tagTMtQkState_Api) ); }
}*PTMtQkState_Api, TMtQkState_Api;

typedef struct tagTAgentPackFileState_Api
{
    EmAgentPackFileState_Api emPackState;
public:
    tagTAgentPackFileState_Api(){ memset(this, 0, sizeof(tagTAgentPackFileState_Api)); }
}*PTAgentPackFileState_Api, TAgentPackFileState_Api;

//是否拔插量子uk返回结果
typedef struct TagTMtQtUk_Api
{	u16    wRes;                      ///1表示存在， 0表示不存在
	BOOL32 bPull;                     ///是否插拔uk 1表示插uk
	TagTMtQtUk_Api(){ memset(this,0,sizeof(TagTMtQtUk_Api)); }
}*PTMtQtUk_Api,TMtQtUk_Api;

//麦克风状态
typedef struct tagTAgentMicStatus_Api
{
	s8     achName[KMTAPI_BUF_16_LEN+1]; //麦克风名称
	BOOL32 bStatus;         //麦克风状态，TRUE-正常，FALSE-异常
public:
	tagTAgentMicStatus_Api(){ memset( this, 0, sizeof(tagTAgentMicStatus_Api) );}
}*PTAgentMicStatus_Api, TAgentMicStatus_Api;

//扬声器状态
typedef struct tagTAgentLoudspeakerStatus_Api
{
	s8     achName[KMTAPI_BUF_16_LEN+1]; //扬声器名称
	BOOL32 bStatus;                      //扬声器状态，TRUE-正常，FALSE-异常
public:
	tagTAgentLoudspeakerStatus_Api(){ memset( this, 0, sizeof(tagTAgentLoudspeakerStatus_Api) );}
}*PTAgentLoudspeakerStatus_Api, TAgentLoudspeakerStatus_Api;

//（网管）终端诊断信息
typedef struct tagTAgentDevicePFMInfo_Api
{
	u32 dwCpuUseRate;      //cpu使用百分比
	u32 dwMicNum;   //麦克风atMicDeviceInfo数组大小
	TAgentMicStatus_Api atMicDeviceInfo[KMTAPI_MAX_NUM_5]; //麦克风状态
	u32 dwLoudspeakerNum; //扬声器atLoudspeakerInfo数组大小
	TAgentLoudspeakerStatus_Api atLoudspeakerInfo[KMTAPI_MAX_NUM_5]; //扬声器状态
public:
	tagTAgentDevicePFMInfo_Api(){ memset(this, 0, sizeof(tagTAgentDevicePFMInfo_Api)); }
}*PTAgentDevicePFMInfo_Api, TAgentDevicePFMInfo_Api;

typedef struct TagTMtSecAdateCreatRes_Api
{
	s8      achQtServerSockPath[KMTAPI_BUF_128_LEN+1];  
	BOOL32  bSuccess;
	u16     wTestQtDeviceRes;
	TagTMtSecAdateCreatRes_Api() { memset( this, 0, sizeof( TagTMtSecAdateCreatRes_Api ) ); }
}*PTMtSecAdateCreatRes_Api,TMtSecAdateCreatRes_Api;

//新添加的删除电子白板时通知与会方时使用
typedef struct tagTDCSDelWhiteBoardInfo_Api
{
    s8					achConfE164[KMTAPI_BUF_64_LEN+1];
    s8                  achTabId[KMTAPI_BUF_64_LEN+1];
    s8                  achFromE164[KMTAPI_BUF_64_LEN+1];	
    tagTDCSDelWhiteBoardInfo_Api() { memset(this, 0, sizeof(tagTDCSDelWhiteBoardInfo_Api)); }

}*PTDCSDelWhiteBoardInfo_Api, TDCSDelWhiteBoardInfo_Api;

typedef struct tagTPlatformInfo_Api
{
    s8      achVersion[KMTAPI_BUF_32_LEN+1];    //平台版本号
    u32     dwIP;                               //当前登录的平台IP
    EmResourceType_Api emResourceType;
    tagTPlatformInfo_Api() { memset(this, 0, sizeof(tagTPlatformInfo_Api)); }
}*PTPlatformInfo, TPlatformInfo_Api;

/** 一路辅流状态 */
typedef struct tagTAssVidStatus_Api
{
	EmMtChanState_Api   emChanState;     ///< TRUE, 当前终端有辅流， FLASE, 当前没有辅流
	EmMtVidLabel_Api    emVidLab;        ///< 辅流的vid标签
	BOOL32              bActive;         ///< 当通道为接收通道，才会用到,标识发送方是否激活通道
	TMtcBaseInfo_Api    tPcAssSrc;       ///< 发双流源

public:
	tagTAssVidStatus_Api()
	{ 
		emChanState = emChanIdle_Api;
		emVidLab    = emVidLabBegin_Api;
		bActive     = FALSE;
	}
}*PTAssVidStatus_Api, TAssVidStatus_Api;

/** 当前的辅视频开启情况,暂时用到一路 */
typedef struct tagTMtAssVidStatusList_Api
{
	TAssVidStatus_Api  arrTAssVidStatus[KMTAPI_MAX_CONF_ASSVID_CHANNEL_NUM];  ///< 多路辅流状态(发送or接收)
	u8                 byCnt;                                                                                                    ///< 实际路数
public:
	tagTMtAssVidStatusList_Api(){ byCnt = 0; }
}*PTMtAssVidStatusList_Api, TMtAssVidStatusList_Api;


typedef struct tagTMtShowAndPlayAud_Api
{
	s8 achShowAud[KMTAPI_BUF_256_LEN+1];    ///< ai要展示的音频中文
	s8 achPlayAud[KMTAPI_BUF_256_LEN+1];     ///< ai要播放的音频
public:
	tagTMtShowAndPlayAud_Api(){ memset( this, 0, sizeof(tagTMtShowAndPlayAud_Api) );}
}*PTMtShowAndPlayAud_Api, TMtShowAndPlayAud_Api;


typedef struct tagTMtAiJoinConfInfo_Api
{
	TMtShowAndPlayAud_Api tShowAndPlayAud;
	TMtJoinConfParam_Api atJoinConfParam[KMTAPI_MAX_AISHOW_LIST_NUM];
	u8  byCnt;
public:
	tagTMtAiJoinConfInfo_Api(){ memset( this, 0, sizeof(tagTMtAiJoinConfInfo_Api) );}
}*PTMtAiJoinConfInfo_Api, TMtAiJoinConfInfo_Api;

typedef struct tagTMtInviteInfo_Api
{
	s8      achInviteE164[KMTAPI_MAX_CONF_E164_LEN+1]; ///< 号码
	s8      achInviteName[KMTAPI_MAX_CONF_NAME_LEN+1];    ///< 名称
	s8      achInviteIp[KMTAPI_BUF_32_LEN+1]; ///< ip
	EmAiContactType_Api emAiContactType;   //联系人类型
public:
	tagTMtInviteInfo_Api(){ memset( this, 0, sizeof(tagTMtInviteInfo_Api) );}
}*PTMtInviteInfo_Api, TMtInviteInfo_Api;


typedef struct tagTMtAiInviteParam_Api
{
	TMtShowAndPlayAud_Api tShowAndPlayAud;
	TMtInviteInfo_Api atInviteInfo[KMTAPI_MAX_AISHOW_LIST_NUM];
	u8  byCnt;
public:
	tagTMtAiInviteParam_Api(){ memset( this, 0, sizeof(tagTMtAiInviteParam_Api) );}
}*PTMtAiInviteParam_Api, TMtAiInviteParam_Api;


typedef struct tagTMtAiSelectParam_Api
{
	TMtShowAndPlayAud_Api tShowAndPlayAud;
	EmAiActionState_Api emAiActionState;
	u32  dwIndex; 
public:
	tagTMtAiSelectParam_Api(){ memset( this, 0, sizeof(tagTMtAiSelectParam_Api) );}
}*PTMtAiSelectParam_Api, TMtAiSelectParam_Api;

typedef struct tagTMtAiAssParam_Api
{
	TMtShowAndPlayAud_Api tShowAndPlayAud;
	EmAiAssState_Api emAiAssState; 
public:
	tagTMtAiAssParam_Api(){ memset( this, 0, sizeof(tagTMtAiAssParam_Api) );}
}*PTMtAiAssParam_Api, TMtAiAssParam_Api;


typedef struct tagTMtAiSureOrNotParam_Api
{
	TMtShowAndPlayAud_Api tShowAndPlayAud;
	EmAiActionState_Api emAiActionState;
	BOOL32  bSure; 
public:
	tagTMtAiSureOrNotParam_Api(){ memset( this, 0, sizeof(tagTMtAiSureOrNotParam_Api) );}
}*PTMtAiSureOrNotParam_Api, TMtAiSureOrNotParam_Api;

typedef struct tagTMtAiVoiceParam_Api
{
	TMtShowAndPlayAud_Api tShowAndPlayAud;
	BOOL32  bUp;                   //调大还是调小 
public:
	tagTMtAiVoiceParam_Api(){ memset( this, 0, sizeof(tagTMtAiVoiceParam_Api) );}
}*PTMtAiVoiceParam_Api, TMtAiVoiceParam_Api;

typedef struct tagTMtAiSelectViewParam_Api
{
	TMtShowAndPlayAud_Api tShowAndPlayAud;
	BOOL32 bExist;
	TMtId_Api tMtId; 
	BOOL32 bSelectView;
public:
	tagTMtAiSelectViewParam_Api(){ memset( this, 0, sizeof(tagTMtAiSelectViewParam_Api) );}
}*PTMtAiSelectViewParam_Api, TMtAiSelectViewParam_Api;


typedef struct tagTMtCameraLastPos_Api
{
	BOOL32		bUse;					////<是否启用上次关机前位置.废弃了，需求变化
	s32			nPosX;					////<x坐标
	s32			nPosY;					////<y坐标
	s32			nType;					////<0上次关机前位置 1默认位置 2第一个预置位
public:
	tagTMtCameraLastPos_Api(){ memset( this, 0, sizeof(tagTMtCameraLastPos_Api) );}
}*PTMtCameraLastPos_Api, TMtCameraLastPos_Api;



/** ai信息配置 */
typedef struct tagTMtAiInfoCfg_Api
{
	BOOL32 bUsedVoiceAide;             ///< 是否使用语音助手
	BOOL32 bUsedCountOfPeople;         ///< 是否使用人数统计
	BOOL32 bUsedFaceSign;              ///< 是否使用人脸签到
	BOOL32 bUsedElectNameplate;        ///< 是否使用电子铭牌
public:
	tagTMtAiInfoCfg_Api(){ memset( this ,0 ,sizeof( struct  tagTMtAiInfoCfg_Api ) );}
}*PTMtAiInfoCfg_Api, TMtAiInfoCfg_Api;

///<从此往下是定义的有关AICamera模块的结构体
typedef struct tagTMtHDCameraAiCfg_Api
{
	u32  dwVideoIndex;							 ///<索引
	u32  dwIp;									///<网络序的IP地址
	u32  dwPort;							    ///<连接端口
public:
	tagTMtHDCameraAiCfg_Api(){ memset( this ,0 ,sizeof( struct  tagTMtHDCameraAiCfg_Api ) );}
}*PTMtHDCameraAiCfg_Api, TMtHDCameraAiCfg_Api;

/** 摄像机AI配置列表 */
typedef struct tagTMtHDCameraAiList_Api
{
	u32					 dwCameraAiNum;
	TMtHDCameraAiCfg_Api atAiCameraList[KMTAPI_BUF_32_LEN+1]; 
public:
	tagTMtHDCameraAiList_Api(){ memset( this ,0 ,sizeof( struct  tagTMtHDCameraAiList_Api ) );}
}*PTMtHDCameraAiList_Api, TMtHDCameraAiList_Api;

///<人数统计
typedef struct tagTMtPeopleCountingResult_Api
{
	u32					 dwVideoIndex; //<索引
	u32					 dwPeopleNum; //<人数统计结果
public:
	tagTMtPeopleCountingResult_Api(){ memset( this ,0 ,sizeof( struct  tagTMtPeopleCountingResult_Api ) );}
}*PTMtPeopleCountingResult_Api, TMtPeopleCountingResult_Api;

///<人脸信息
typedef struct tagTMtFaceCheckInInfo_Api
{
	s8					 achName[KMTAPI_BUF_32_LEN+1]; ///<姓名
	s8					 achTime[KMTAPI_BUF_32_LEN+1]; ///<时间
	s8					 achPosition[KMTAPI_BUF_32_LEN+1];///<员工职位
public:
	tagTMtFaceCheckInInfo_Api(){ memset( this ,0 ,sizeof( struct  tagTMtFaceCheckInInfo_Api ) );}
}*PTMtFaceCheckInInfo_Api, TMtFaceCheckInInfo_Api;

///<人脸签到通知信息
typedef struct tagTMtFaceCheckInList_Api
{
	u32					 dwVideoIndex; ///<索引
	u32					 dwFaceCheckNum; ///<人脸签到人数
	TMtFaceCheckInInfo_Api atFaceCheckInfoList[KMTAPI_BUF_32_LEN+1]; ///<人脸签到通知信息列表
public:
	tagTMtFaceCheckInList_Api(){ memset( this ,0 ,sizeof( struct  tagTMtFaceCheckInList_Api ) );}
}*PTMtFaceCheckInList_Api, TMtFaceCheckInList_Api;

//osd快捷键配置
typedef struct tagTMtShortCutKey_Api
{
	EmShortCutKeyType_Api emKeyType;	////< 快捷键类型
	EmShortCutKeyFuc_Api  emKeyFuc;		////< 快捷键功能
public:
	tagTMtShortCutKey_Api(){ memset( this, 0, sizeof(tagTMtShortCutKey_Api) );}
}*PTMtTMtShortCutKey_Api, TMtShortCutKey_Api;

typedef struct tagTMtShortCutKeyList_Api
{
	TMtShortCutKey_Api atShortCutKey[KMTAPI_COUNT_4];
	u8 byCnt;
public:
	tagTMtShortCutKeyList_Api(){ memset( this, 0, sizeof(tagTMtShortCutKeyList_Api) );}
}*PTMtShortCutKeyList_Api, TMtShortCutKeyList_Api;


/**@}*/

/**@}*/
#endif //!_MTAPI_STRUCT_H_
