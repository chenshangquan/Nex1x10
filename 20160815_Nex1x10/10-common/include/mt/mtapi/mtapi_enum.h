/*******************************************************************************//**
*@file          mtapi_enum.h
*@brief         提供mtapi所有的枚举定义
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_ENUM_H_
#define _MTAPI_ENUM_H_
/**@addtogroup common 公用
*@{
*/

/**@addtogroup enum 枚举定义
*@{
*/

#include "kdvtype.h"
 
/** mtapi使用方式 */
enum EmMtApiMode_Api
{
	emMtLocMode_Api = 0,       ///< 本地模式(终端)
	emMtRmtMode_Api,           ///< 远程模式(终控)
};

/////用下面枚举， EmMtcType_Api 这个枚举在重构access后废掉
enum EmClientAppType_Api 
{
	emClientAppOsd_Api = 0,
	emClientAppWebService_Api = 1,
	emClientAppSkyShare_Api = 2,
	emClientAppSkyRemote_Api = 3,
	emClientAppSkyMTC_Api =4,
	emClientAppSkyWindows_Api=5,
	emClientAppSkyAndroid_Api=6,
	emClientAppSkyIOS_Api =7,
	emClientAppThirdParty_Api =8,
	emClientAppNexVison_Api = 9,
	emClientAppMTCEnd_Api = 10,
};

enum EmAuthType_Api
{
	emUserNamePwdAuth_Api =0,
	emInnerPwdAuth_Api =1,
	emDynamicAuth_Api =2,
	emAuthEnd_Api =3,
};

/** 数据的操作分类 */
enum EmDataOptType_Api
{
	emDataOptTypeNone_Api = 0,  ///< 修改操作
	emDataOptTypeAdd_Api,       ///< 添加操作
	emDataOptTypeDel_Api,       ///< 删除操作
	emDataOptTypeMod_Api,       ///< 修改操作
	emDataOptTypeInit_Api,      ///< 初始化操作
	emDataOptTypeReset_Api,	    ///< 重置操作
};

/**终端型号*/
enum EmMtModel_Api
{
	emModelBegin_Api        = 0,      ///<起始值
	emSkyWindows_Api        = 1,      ///<桌面终端 自建
	emSkyIPad_Api           = 2,      ///<移动终端ipad 自建
	emSkyIPhone_Api         = 3,      ///<移动终端iphone 自建
	emSkyAndroidPad_Api     = 7,      ///<移动终端androidpad 自建
	emSkyAndroidPhone_Api   = 8,      ///<移动终端androidphone 自建
	emX500_1080P60_Api      = 9,      ///<硬终端X500 自建
	emX500_1080P30_Api      = 10,     ///<硬终端X500 自建
	emX500_720P60_Api       = 11,     ///<硬终端X500 自建
	emX500_mo_1080P_Api     = 12,     ///<硬终端X500 租赁
	emX500_mo_720P_Api      = 13,     ///<硬终端X500 租赁
	emX500_oem_1080P_Api    = 14,     ///<硬终端X500 自建
	emX500_oem_mo_1080P_Api = 15,     ///<硬终端X500 租赁


	emTrueLink_Api              = 16,       ///<桌面终端 租赁
	emTrueTouchIpad_Api         = 17,       ///<移动终端ipad 租赁
	emTrueTouchIphone_Api       = 18,       ///<移动终端iphone 租赁
	emTrueTouchAndroidPhone_Api = 19,       ///<移动终端androidphone 租赁
	emTrueTouchAndroidPad_Api   = 20,       ///<移动终端androidpad   租赁

	emH950_1080P60_Api, ///<硬终端 自建

	emTrueLinkTV_Api           = 22,       ///<移动终端TV盒子 租赁

	emX700_4k30_Api = 23,               //x700-4k30 自建
	emX700_oem_4k30_Api = 24,           //x700-4k30 oem 自建
	emX500_4k30_Api = 25,               //x500-4k30 自建
	emX500_oem_4k30_Api = 26,           //x500-4k30 oem 自建

	emX300_1080P60_Api = 27,            //x300-1080P60  自建
	emX300_1080P30_Api = 28,            //x300-1080P30  自建
	emX300_720P60_Api = 29,             //x300-720P60   自建
	emX300_oem_1080P60_Api = 30,        //x300-1080P60 oem 自建

	emX500_1080P_60_Api = 31,           //x500-1080P-1080P60  自建  SKY X500-1080P 终端 和从9-15的x500终端不一样，芯片不一样
	emX500_1080P_30_Api = 32,           //x500-1080P-1080P30  自建
	emX500_oem_1080P_60_Api = 33,       //x500-1080P-1080P60 oem 自建

	em300_1080P30_Api = 34,             //300-1080P30  自建
	em300_720P60_Api = 35,              //300-720P60  自建
	em300_oem_1080P30_Api = 36,         //300-1080P30  oem 自建
	em300L_1080P30_Api = 37,            //300L-1080P30  自建
	em300L_720P60_Api = 38,             //300L-720P60  自建
	em300L_oem_1080P30_Api = 39,        //300L-1080P30  oem 自建
	em300_1080P60_Api = 40,             //300-1080P60  自建
	em300_720P30_Api = 41,              //300-720P30   自建
	em300L_1080P60_Api = 42,            //300-1080P60  自建(目前还没用到)
	em300L_720P30_Api = 43,             //300-720P30   自建(目前还没用到)
	emX300_720P30_Api = 44,             //x300-720P30   自建
	emX500_720P_30_Api = 45,            //x500-720P-720P30  自建(目前还没用到)
	emX500_720P_60_Api = 46,            //x500-720P-720P60  自建(目前还没用到)
	em100_1080P30_12X_Api = 47,         //100_1080P30_12X      自建
	em100_1080P30_3X_Api = 48,          //100_1080P30_3X       自建
	em100L_720P_Api = 49,               //100L_720P            自建
	em100_oem_1080P30_3X_Api = 50,      //100_oem_1080P30_3X   自建
	emSkyWindows_s_Api       = 51,      ///< 商密桌面终端 自建
	emSkyIPad_s_Api          = 52,      ///< 商密移动终端ipad 自建
	emSkyIPhone_s_Api        = 53,      ///< 商密移动终端iphone 自建
	emSkyAndroidPad_s_Api    = 54,      ///< 商密移动终端androidpad 自建
	emSkyAndroidPhone_s_Api  = 55,       ///< 商密移动终端androidphone 自建

	emX300_1080P60_s_Api	= 56,       // 商密硬终端 sky_x300_1080P60_s 
	emX500_1080P60_s_Api	= 57,       // 商密硬终端 sky_x500_1080P60_s
	em300_1080P60_s_Api		= 58,       // 商密硬终端 sky_300_1080P60_s
	emX700_s_Api			= 59,       // 商密硬终端 sky_x700_s
	emX500_4K_s_Api			= 60,       // 商密硬终端 sky_x500_4k_s
	em100_1080P30_12X_s_Api = 61,		// 商密硬终端 sky_100_1080P30_12x_s

	emX300_1080P60_cs_Api	 = 62,      // 渠道版本 sky_x300_1080P60_cs 
	emX500_1080P60_cs_Api	 = 63,      // 渠道版本 sky_x500_1080P60_cs
	em300_1080P60_cs_Api	 = 64,      // 渠道版本 sky_300_1080P60_cs
	emX700_cs_Api			 = 65,      // 渠道版本 sky_x700_cs
	emX500_4K_cs_Api		 = 66,      // 渠道版本 sky_x500_4k_cs
	em100_1080P30_12X_cs_Api = 67,      // 渠道版本 sky_100_1080P30_12x_cs

	em100_1080P30_12X_H5_Api = 68,      // SKY 100-1080P30-12x-H5,支持H265
	em100_1080P30_3X_H5_Api =  69,      // SKY 100-1080P30-3x-H5

	em100_DX_1080P30_12X_Api = 70,		//SKY 100-DX-1080P30-12x（不支持WIFI）
	em100_DX_1080P30_3X_Api  = 71,
	em100L_DX_720P_Api        = 72
};

/** 多点会议中终端类型 */
enum EmMtType_Api
{
	EmMt_Type_Mt_Api = 0,        ///<普通终端
	EmMt_Type_PHONE_Api = 1,     ///<电话终端
	EmMt_Type_SATD_Api  = 2,     ///<卫星终端
	EmMt_Type_MMCU_Api  = 3,     ///上级MCU
	EmMt_Type_SMCU_Api  = 4,     ///下级MCU
	EmMt_Type_VRSREC_Api= 5,     ///vrs新录播设备

	EmMt_Type_Other_Api       = 10, ///<其他终端
};

/** 端口类型 */
enum EmMtPortType_Api 
{
	emPortInvalid_Api = 0,        ///无效值
	emPortTcpForH323_Api,         ///<H323 TCP
	emPortMP_Api,                 ///<MP
	emPortAudioEncoder_Api,       ///<音频编码
	emPortAudioDecoder_Api,       ///<音频解码
	emPortVideoEncoder_Api,       ///<视频编码
	emPortVideoDecoder_Api,       ///<视频解码
	emPortFwdPcAssStream_Api,     ///<PC辅流
	emPortFwdAudioLoop_Api,       ///<音频回环
	emPortFwdVdieoLoop_Api,       ///<视频回环
	emPortInnerMcAudio_Api,       ///<内置MC音频
	emPortInnerMcVideo_Api,       ///<内置MC视频
	emPortMcVmpRecv_Api,          ///<画面合成接收
	emPortMcVmpResult_Api,        
	emPortMcMixerRecv_Api,        ///<混音接收
	emPortMcMixerResult_Api,	  
	emPortMcMixerResultNChan_Api, 
	emPortInnerProxy_Api,         ///<内置代理
	emNetBuf_Api,                 ///<NetBuf
	emNetbufAudio_Api,            ///<NetBuf音频
	emNetbufVideo_Api,            ///<NetBuf视频
};

/** 编解码器具体哪一路*/
enum EmCodecComponentIndex_Api
{
	em1st_Api = 0,         ///<第1路
	em2nd_Api,             ///<第2路
	em3rd_Api,             ///<第3路
	em4th_Api,             ///<第4路
	em5th_Api,             ///<第5路
	em6th_Api,             ///<第6路
	em7th_Api,             ///<第7路
	em8th_Api,             ///<第8路
	em9th_Api,             ///<第9路
};

/** codec组件 */
enum EmCodecComponent_Api
{
	emVidMainEncoder_Api   = 0,      ///<主流视频编码器
	emVidMainDecoder_Api   = 1,      ///<主流视频解码器
	emAudMainEncoder_Api   = 2,      ///<主流音频编码器
	emAudMainDecoder_Api   = 3,      ///<主流音频解码器
	emAudMainMixer_Api     = 4,      ///<主流混音器
	emVidMainMixer_Api     = 5,      ///<主流画面合成器
	emVidAssEncoder_Api    = 6,      ///<辅流视频编码器
	emVidAssDecoder_Api    = 7,      ///<辅流视频解码器
	emAudAssEncoder_Api    = 8,      ///<辅流音频编码器
	emAudAssDecoder_Api    = 9,      ///<辅流音频编码器
	emAudAssMixer_Api      = 10,     ///<辅流混音器
	emVidAssMixer_Api      = 11,     ///<辅流画面合成器
	emCodecInvalid_Api     = 20,     ///<无效值
};

/** 消息来源 */
enum EmMsgFromSource_Api
{
	emMsgFromInvalid_Api = 0,			///<无效值
	emMsgFromWebMtc_Api = 1,			///<WebMtc
	emMsgFromOsd_Api = 2				///<Osd
};

/** 视频端口 */
enum EmVidPort_Api
{
	emH600VidInHDMI_Api = 0,  ///<HDMI输入
	emH600VidInVGA_Api,       ///<VGA输入
	emH600VidInC_Api,         ///<C端子输入
	emH600VidOutDVI_Api,      ///<DVI输出
	emH600VidOutHDMI_Api,     ///<HDMI输出
	emH700VidInDVI_Api,       ///<DVI输入
};
 
/** 通道类型 */
enum EmMtChanType_Api
{
	emChanSendAudio_Api = 0,  ///<音频发送
	emChanRecvAudio_Api,      ///<音频接收
	emChanSendVideo_Api,      ///<视频发送
	emChanRecvVideo_Api,      ///<视频接收
	emChanSendAssAudio_Api,   ///<音频辅流
	emChanRecvAssAudio_Api,   ///<音频辅流
	emChanSendAssVideo_Api,   ///<视频辅流
	emChanRecvAssVideo_Api,   ///<视频辅流
	emChanSendFecc_Api,       ///<FECC发送
	emChanRecvFecc_Api,       ///<FECC接收
	emChanSendT120_Api,       ///<T120发送
	emChanRecvT120_Api,       ///<T120接收
	emChanTypeEnd_Api,        ///<通道类型结束
};

/** TRSP状态 */
enum EmRtspStatus_Api
{
	emRtspInit_Api = 1,      ///<初始化
	emRtspPreReady_Api,      ///<预准备
	emRtspReady_Api,         ///<准备
	emRtspPlaying_Api,       ///<播放
	emRtspPause_Api,         ///<暂停
	emRtspResume_Api,        ///<恢复
	emRtspAdjustSpeed_Api,   ///<调整播放速度
	emRtspAdjustProcess_Api, ///<调整播放进度
};

/** 双流类型*/
enum EmMtAssStreamType_Api
{
	emAssStreamBegin_Api = 0,  ///< 起始值
	emPcAssStream_Api,         ///< pc辅流
	emVideoAssStream_Api,      ///< video辅流
}; 

/** 会议类型*/
enum EmMtConfType_Api
{
	emConfType_Video_Api = 0, ///< 视频 或 共享模式
	emConfType_Audio_Api = 1, ///< 纯音频
};

/** vid能力标签 */
enum EmMtVidLabel_Api   
{
	emVidLabBegin_Api = 0,     ///<起始值
	emPcStreamVidLab_Api = 20,      ///< pc双流标签
	emVideoStreamVidLab_Api = 21,   ///< video双流标签
};

/** aud 能力标签 */
enum EmMtAudLabel_Api    
{
	emAudLabBegin_Api = 0,    ///<起始值
};

/** 媒体类型 */
enum EmMtMediaType_Api
{
	emMediaBegin_Api = 0, ///< 非音视频
	emMediaVideo_Api,     ///< 视频
	emMediaAudio_Api,     ///< 音频
	emMediaAV_Api,        ///< 音频和视频
	emMediaAssVideo_Api,  ///< 辅流视频
};

/** 位置 */
enum EmSite_Api
{
	emLocal_Api = 0,     ///< 本地
	emRemote_Api,        ///< 远端
};

/**通道类型 */
enum EmMtMediaDirection_Api
{
	emDirectionBegin_Api = 0, ///<无效值
	emChannelSend_Api,        ///<发送
	emChannelRecv_Api,        ///<接收
};

/** aaclc、aacld的声道数 */
enum EmAacChnlNum_Api
{
	emCnNumCust_Api = 0, ///<无效值
	emCnNum1_Api,        ///<单声道
	emCnNum2_Api,        ///<双声道
	emCnNum3_Api,        ///<三声道
	emCnNum4_Api,        ///<四声道
	emCnNum5_Api,        ///<五声道
	emCnNum5dot1_Api,    ///<5.1声道
	emCnNum7dot1_Api,    ///<7.1声道
};

/** aaclc、aacld采样码率 */
enum EmAacSampFreq_Api
{
	emASF96000_Api = 0,   ///<96000Hz
	emASF88200_Api,       ///<88200Hz
	emASF64000_Api,       ///<64000Hz
	emASF48000_Api,       ///<48000Hz
	emASF44100_Api,       ///<44100Hz
	emASF32000_Api,       ///<32000Hz
	emASF24000_Api,       ///<24000Hz
	emASF22050_Api,       ///<22050Hz
	emASF16000_Api,       ///<16000Hz
	emASF12000_Api,       ///<12000Hz
	emASF11025_Api,       ///<11025Hz
	emASF8000_Api,        ///<8000Hz
};

/** 通道状态 */
enum EmMtChanState_Api 
{
	emChanIdle_Api = 0,   ///< 空闲状态
	emChanConnected_Api,  ///< 连接状态
	emChanActive_Api,     ///< 激活状态 暂未使用
	emChanInActive_Api,   ///< 闲置状态 暂未使用
};
 
/** 323呼叫状态 */
enum EmH323CallState_Api       
{
	emCallStateIdle_Api = 0,            ///< 空闲状态
	emCallStateCreating_Api,            ///< 创建呼叫
	emCallStateArqOutgoing_Api,         ///< 发出arq状态
	emCallStateCallOuting_Api,          ///< 呼出状态
	emCallStateCallincoming_Api,        ///< 呼入状态
	emCallStateCallAccepted_Api,        ///< UI同意呼叫状态
	emCallStateHanguping_Api,           ///< 主动挂断，等待底层挂断
	emCallStateConnected_Api,           ///< h225建立成功状态
};

/** 短消息业务类型 */
enum EmSMSType_Api
{
	emSMSSingleLine_Api = 0,   ///< 短消息
	emSMSPageTitle_Api,        ///< 翻页字幕
	emSMSRollTitle_Api,        ///< 滚动字幕
	emSMSStaticTitle_Api,      ///< 静态字幕
	emSMSUpRollTitle_Api,      ///< 向上滚动短消息
};

/** 滚动短消息速度级别 */
enum EmRollMsgSpeed_Api
{
	emROLL_SPEED_1_Api = 1,	///< 最慢
	emROLL_SPEED_2_Api = 2,	///< 稍慢
	emROLL_SPEED_3_Api = 3,	///< 中速
	emROLL_SPEED_4_Api = 4,	///< 稍快
	emROLL_SPEED_5_Api = 5,	///< 最快
};

/** 参加会议创会结果 */
enum EmMtJoinCreateConfRsp_Api
{
	emJoinCreat_Success_Api = 0,                    ///<成功
	emJoinCreat_Serdb_err_Api,                      ///<服务器数据库错误
	emJoinCreat_Timeout_err_Api,                    ///<超时
	emJoinCreat_Note164_err_Api,                    ///<E164号码错误
	emJoinCreat_Data_err_Api,                       ///<数据错误
	emJoinCreat_Mcu_noidlevpu_Api,			        ///< 没有足够能力的空闲媒体处理器, 5.0不需要
	emJoinCreat_Mcu_minimediaconfmtnum_Api,	        ///< 超过小型媒体会议入会终端限制, 5.0不需要
	emJoinCreat_Mcu_maxconfnum_Api,			        ///< 已达最大会议数
	emJoinCreat_Mcu_encrypeerr_Api,			        ///< 与会议加密模式不符, 5.0不需要
	emJoinCreat_Mcu_confnotexist_Api,		        ///< 会议不存在
	emJoinCreat_Mcu_undefined_Api,                  ///< 未知错误
	emJoinCreat_Gk_mpcd_disconnected_Api,           ///< mpcd热备重启
	emJoinCreat_Mcu_maxmtnum_Api,			        ///< 终端数已达最大上限
	emJoinCreat_Mcu_pwderr_Api,			            ///< 密码错误
	emJoinCreat_Mcu_nsatpms_Api,                    ///< 无卫星权限
	emJoinCreat_Mcu_nsatdaddr_Api,		            ///< 没有组播地址
	emJoinCreat_E164_repeat_Api,                    ///< e164号码重复
	emJoinCreat_CallNumExceed_Api,                  ///< 呼叫数超限       ,5.0不需要
	emJoinCreat_Mcu_NoDisturbReject_Api = 18,       ///< 会议免打扰拒绝
	emJoinCreat_Mcu_ConfResuming_Api    = 19,       ///< mcu正在恢复中
	emJoinCreat_Mcu_NoPermission_Api	= 20		///< 没有创会权限
};

/** 会议信息错误信息 */
enum EmMtConfDetailErr_Api
{
	emConfDetail_Err_Success_Api = 0,		       ///< 获取会议详细信息成功
	emConfDetail_Err_Ser_db_Api,			       ///< 数据库错误
	emConfDetail_Err_Timeout_Api,			       ///< 服务器响应超时
	emConfDetail_Err_Note164_Api,		           ///< 通知E164号错误
	emConfDetail_Err_Data_Api,				       ///< 数据错误
	emConfDetail_Err_Isover_Api,		           ///< 会议已结束
	emConfDetail_Err_Unknown_Api,			       ///< 未知
};

/** 辅流控制模式 */
enum EmMtAssVidMode_Api
{
	MT_DUAL_MODE_SPEAKER_Api = 0,			       ///< 只有主席能发辅流
	MT_DUAL_MODE_EVERYONE_Api,				       ///< 任何人都能发辅流
	MT_DUAL_MODE_INVALID_Api,                      ///<无效值
};
 
/** 对话模式 */
enum EmMtPairTalkOperationType_Api
{
	emMtPairTalkOperationTypeBegin_Api = 0,     ///<起始值
	emMtPairTalkOperationTypeChairStart_Api,	///< 主席开启对话模式
	emMtPairTalkOperationTypeChairStop_Api,		///< 主席停止对话模式
	emMtPairTalkOperationTypeChairJoin_Api,		///< 主席加入对话模式
	emMtPairTalkOperationTypeChairQuit_Api,		///< 主席退出对话模式
	emMtPairTalkOperationTypeAudienceJoin_Api,	///< 普通终端加入对话模式
	emMtPairTalkOperationTypeAudienceQuit_Api,	///< 普通终端退出对话模式
	emMtPairTalkOperationTypeEnd_Api,           ///<结束值
};

/** 呼叫方式 */
enum EmMtCallMode_Api
{
	emJoin_Api = 0,  ///<参加会议
	emCreate_Api,    ///<创建会议
	emInvite_Api,    ///<邀请
};

/** 呼叫协议 */
enum EmConfProtocol_Api
{
	emProtocolBegin_Api = 0,  ///<起始值
	em323_Api,                ///<H323
	emsip_Api,                ///<SIP
	emsat_Api,                ///<SAT
	emtip_Api,                ///<TIP
};

/** 会议分辨率， 高清， 标清 */
enum EmMtClarity_Api
{
	emMode_HD_Api = 1,		  ///< 高清  720p
	emMode_SD_Api,		      ///< 标清  W4CIF,4CIF归为“ 标清”
	emMode_Fluency_Api,       ///< 流畅  WCIF，CIF归为“流畅”
	emMode_Custom_Api,		  ///< 自定义
	emMode_FHD_Api,           ///< 全高清  1080P
	emMode_UHD_Api,           ///< 超高清
};

/** 呼叫地址类型 */
enum EmMtAddrType_Api 
{
	emAddrIP_Api = 0,   ///<IP地址   
	emAddrE164_Api,     ///<E164号
	emAddrAlias_Api,    ///<别名
	emDialNum_Api,      ///<拨号
	emSipAddr_Api,      ///<SIP地址
	emAddrMoid_Api,     ///<MOID
    emNoSysMailbox_Api, ///<非系统邮箱
};

/** 别名类型 */
enum EmMtAliasType_Api
{
	emAliasBegin_Api = 0, ///<起始值
	emAliasE164_Api,      ///<E164
	emAliasH323_Api,      ///<别名类型，sip的别名也用这个
	emAliasEmail_Api,     ///<邮箱
	emAliasEpID_Api,      ///<EP ID (注册GK回复该类型, 上层用不到)
	emAliasGKID_Api,      ///<GK ID
};

/** 会议类型 */
enum EmConfSpecial_Api
{
	emNormalConf_Api = 0,              ///< 普通会议
	emSatelliteConf_Api,               ///< 卫星会议
};

/**应答方式*/
enum EmAnswerMode_Api
{
	emAnswerModeAuto_Api     = 0,     ///<自动应答
	emAnswerModeManu_Api     = 1,     ///<手动应答
	emAnswerModeNegative_Api = 2,     ///<免打扰
};

/**h.264profile */
enum EmH264Profile_Api 
{ 
	emBaseline_Api = 1,    ///<baseline
	emMain_Api     = 2,    ///<main
	emExtended_Api = 4,    ///<extend
	emHigh_Api     = 8,    ///<high
	emHigh10_Api   = 16,   ///<high 10
	emHigh422_Api  = 32,   ///<high 422
	emHigh444_Api  = 64,   ///<high 444
};

/**h.264 附加模式 */
enum EmH264AdditionalModes_Api
{
	emModeNone_Api = 0,   ///<无
	emModeRCD0_Api = 64,  ///<RCD0
	emModeSBP_Api  = 32,  ///<SBP
	emModeSHP_Api  = 16   ///<SHP
};

/**h.265 profile*/
enum EmH265Profile_Api 
{
	emProfileMain_Api      = 0,  ///<main
	emProfileMain10_Api    = 1,  ///<main 10
	emProfileMainStill_Api = 2   ///<main still
};

/** 视频格式 */
enum EmVidFormat_Api
{
	emVH261_Api = 0,      ///<H261
	emVH262_Api,          ///<H262
	emVH263_Api,          ///<H263
	emVH263plus_Api,      ///<H263+
	emVH264_Api,          ///<H264
	emVHMPEG4_Api,        ///<MPEG4
	emVH265_Api,          ///<H265
	emVEnd_Api, ///< 枚举结束标识
};

/** 音频格式 */
enum EmAudFormat_Api
{
	emAG711a_Api = 0,   ///<G711A
	emAG711u_Api,       ///<G711U
	emAG722_Api,        ///<G722
	emAG7231_Api,       ///<G7231
	emAG728_Api,        ///<G728
	emAG729_Api,        ///<G729
	emAMP3_Api,         ///<MP3
	emAG721_Api,        ///<协议不支持， 协议还有一个g723， 编码可能不支持
	emAG7221_Api,       ///<G7221
	emAG719_Api,        ///<G719
	emAMpegAACLC_Api,   ///<MpegAACLC
	emAMpegAACLD_Api,   ///<MpegAACLD
	emAOpus_Api,        ///<Opus
	emAudEnd_Api, ///< 枚举结束标识
};

/** 因为代码中强转， 所有分辨率的值要和conf中定义的值一样 */
enum EmMtResolution_Api
{
	emMtResAuto_Api             = 0,   ///<自适应
	emMtSQCIF_Api               = 1,   ///<SQCIF 88x72
	emMtQCIF_Api                = 2,   ///<QCIF 176x144
	emMtCIF_Api                 = 3,   ///<CIF 352x288
	emMt2CIF_Api                = 4,   ///<2CIF 352x576
	emMt4CIF_Api                = 5,   ///<4CIF 704x576
	emMt16CIF_Api               = 6,   ///<16CIF 1408x1152


	emMtVGA352x240_Api          = 7,   ///<352x240  对应平台SIF
	emMt2SIF_Api                = 8,   ///<对应平台2SIF，具体不知道多少*多少                  
	emMtVGA704x480_Api          = 9,   ///<704x480  对应平台4SIF
	emMtVGA640x480_Api          = 10,  ///<VGA 640x480                   
	emMtVGA800x600_Api          = 11,  ///<SVGA 800x600                     
	emMtVGA1024x768_Api         = 12,  ///<XGA 1024x768                     

	emMtVWCIF_Api               = 13,  ///<WCIF 512*288

	/** 仅用于终端分辨率改变 */	
	emMtVSQCIF112x96_Api        = 14,  ///<SQCIF(112*96)
	emMtVSQCIF96x80_Api         = 15,  ///<SQCIF(96*80) 

	/** 高清分辨率 */	
	emMtVW4CIF_Api              = 16,  ///<Wide 4CIF(1024*576)
	emMtHD720p1280x720_Api      = 17,  ///<720p 1280x720
	emMtVGA1280x1024_Api        = 18,  ///<SXGA 1280x1024
	emMtVGA1600x1200_Api        = 19,  ///<UXGA 1600x1200
	emMtHD1080i1920x1080_Api    = 20,  ///<1080i 1920x1080
	emMtHD1080p1920x1080_Api    = 21,  ///<1080p 1920x1080          
	emMtVGA1280x800_Api         = 22,  ///<WXGA 1280x800
	emMtVGA1440x900_Api         = 23,  ///<WSXGA 1440x900                     
	emMtVGA1280x960_Api         = 24,  ///<XVGA  1280x960                     

	/** 非标分辨率（1080p底图）－用于终端分辨率改变 */                     
	emMtV1440x816_Api           = 25,  ///<1440×816(3/4)
	emMt1280x720_Api            = 26,  ///<1280×720(2/3)
	emMtV960x544_Api            = 27,  ///<960×544(1/2)
	emMtV640x368_Api            = 28,  ///<640×368(1/3)
	emMtV480x272_Api            = 29,  ///<480×272(1/4)
	emMt384x272_Api             = 30,  ///<384×272(1/5)
	emMt640x544_Api             = 31,  ///<640x544                       
	emMt320x272_Api             = 32,  ///<320x272

    /** 非标分辨率（720p底图） －用于终端分辨率改变 */
	emMt_720_960x544_Api            = 33, ///<960×544(3/4)
	emMt_720_864x480_Api            = 34, ///<864×480(2/3)
	emMt_720_640x368_Api            = 35, ///<640×368(1/2)
	emMt_720_432x240_Api            = 36, ///<432×240(1/3)
	emMt_720_320x192_Api            = 37, ///<320×192(1/4)

	/** 非标分辨率 */
	emMtVGA480x352_Api          = 38,     ///<480×352, iPad专用


	emMtHD480i720x480_Api       = 39,   ///<480i720x480
	emMtHD480p720x480_Api       = 40,   ///<480p720x480
	emMtHD576i720x576_Api       = 41,   ///<576i720x576
	emMtHD576p720x576_Api       = 42,   ///<576p720x576              
	emMtVGA1280x768_Api         = 43,   ///<WXGA1280x768
	emMtVGA1366x768_Api         = 44,   ///<WXGA1366x768
	emMtVGA1280x854_Api         = 45,   ///<WSXGA1280x854
	emMtVGA1680x1050_Api        = 46,   ///<WSXGA+1680x1050
	emMtVGA1920x1200_Api        = 47,   ///<WUXGA1920x1200
	emMtV3840x2160_Api          = 48,   ///<4Kx2K3840x2160
	emMt1280x600_Api            = 49,   //1280*600
	emMt1360x768_Api            = 50,  //1360*768
	emMtVRes3840x2160_Api       = 51,   //3840*2160
	emMtVRes4096x2048_Api       = 52,   //4096*2048
	emMtVRes4096x2160_Api       = 53,   //4096*2160
	emMtVRes4096x2304_Api       = 54,   //4096*2304

	emMtVResEnd_Api             = 100,	///<结束值
};

/** conf呼叫类型, 区分加会，创会，主呼，被呼 */
enum EmMtCallingType_Api   
{
	emJoinConf_Api = 0,      ///<ras非标加入会议，等待mcu 呼叫  
	emCreateConf_Api,     ///<ras非标创建会议，等待mcu 呼叫
	emOutCall_Api,              ///<呼出
	emIncomingCall_Api,            ///<呼入

};

/** conf呼叫状态 */
enum EmMtCallState_Api   
{
	emCallIdle_Api = 0, 
	emCallRasConfJoining_Api,      ///<ras非标加入会议，等待mcu 呼叫  
	emCallRasConfCreating_Api,     ///<ras非标创建会议，等待mcu 呼叫
	emCallOuting_Api,              ///<呼出
	emCallIncoming_Api,            ///<呼入
	emCallAccepted_Api,            ///<接收
	emCallHanging_Api,             ///<挂断
	emCallConnected_Api,           ///<h323 是 225connected, sip是呼叫信令交互完
	emCallP2P_Api,                 ///<点对点
	emCallMCC_Api,                 ///<多点
};

/** 混音类型 */
enum EmMtMixType_Api 
{
	emMcuNoMix_Api = 0,                 ///< 不混音
	mcuWholeMix_Api,                    ///< 全体混音（智能混音）
	mcuPartMix_Api,                     ///< 定制混音
	mcuVacMix_Api,                      ///< VAC 
	mcuVacWholeMix_Api,                 ///< 带Vac的全体混音
    emMcuSmartMix_Api,                  ///< 智能混音(不启用)
}; 

/** 呼叫断开原因， 跟组件中的值一一对应*/
enum EmMtCallDisReason_Api
{
	emDisconnect_Busy_Api = 0,              ///< 对端忙
	emDisconnect_Normal_Api,                ///< 正常挂断
	emDisconnect_Rejected_Api,              ///< 对端拒绝
	emDisconnect_Unreachable_Api,           ///< 对端不可达
	emDisconnect_Local_Api,                 ///< 本地原因
	emDisconnect_Unknown_Api,               ///< 未知原因
	emDisconnect_custom_Api,                ///< 自定义原因
	emDisconnect_AdaptiveBusy_Api ,		    ///< 接入电话终端失败
	emDisconnect_Occupy_Api, //其他终端或者mcu抢断


	/** 下面原因是自定义的,上面是与协议栈对应起来的标准的原因*/
	emDisconnect_Joinconftimeout_Api = 20,	///< 参加会议超时
	emDisconnect_Createconftimeout_Api,		///< 召集会议超时
	emDisconnect_Nomediaresource_Api,		///< 没有媒体资源
	emDisconnect_Exceedmaxinconfmtnum_Api,	///< 超过会议最大终端数（参加会议时）
	emDisconnect_Exceedmaxconfnum_Api,	    ///< 超过会议最大数（创建会议时）
	emDisconnect_EncrypeErr_Api,            ///< 与会议加密模式不符
	emDisconnect_P2Ptimeout_Api,            ///< 点对点呼叫超时
	emDisconnect_MccDrop_Api,               ///< 会控挂断
	emDisconnect_ChairDrop_Api,             ///< 主席挂断
	emDisconnect_MMcuDrop_Api,              ///< 上级会议挂断
	emDisconnect_ConfRelease_Api,           ///< 会议结束挂断
	emDisconnect_PeerInConf_Api,            ///< 正在会议中
	emDisconnect_PeerNoDisturb_Api,         ///< 免打扰
	emDisconnect_NotInPeerContact_Api,      ///< 非好友
	emDisconnect_PeerNoP2PPermission_Api,   ///< 对端无点对点权限
	emDisconnect_PeerOnSleeping_Api,		///< 对端正在待机
	emDisconnect_ConfAutoRelease_Api,		///< 会议自动结束挂断
	emDisconnect_REASON_BUSYEXT_Api,        ///< 终端忙,带终端目前所在会议的级别及会议名称(邀请终端失败时原因)
	emDisconnect_REASON_REMOTERECONNECT_Api,///< 本端行政级别低，由远端自动发起重连(邀请终端失败时原因)
	emDisConnect_CallNumExceed_Api,         ///< 呼叫数超限
	emDisConnect_NotRegedToCallFailed_Api,///< 本地没有注册成功导致呼叫别名或者e164号码有问题

	emDisConnect_LocalVodPlaying_Api,           //本地正在vod点播中
	
	/////sec 注册失败reason
	emDisConnect_SecCrtNotFind_Api    = 42,   ///ca证书找不到
	emDisConnect_SecCrtVerifyFail_Api = 43,  ///证书验证失败
	emDisConnect_SecCrtExpired_Api    = 44,   ///证书过期 有效期错误
	emDisConnect_SecCrtFormatError_Api = 45,   ///证书格式错误
	emDisConnect_SecLoadCertFailed_Api = 46,   ///证书加载失败
	emDisConnect_SecEncTypeError_Api = 47,     ////加密类型不一致
	emDisConnect_AuthenticationErr_Api = 48,       ///强认证报错 一般是终端未强认证主呼强认证会议
	emDisConnect_MtHasInConf_Api = 49,      ///主席邀请同一个终端入会提示
	emDisConnect_MtEviction_Api  = 50,      /// 强拆方式主动退会
	emDisConnect_SoftIntegrityTestErr_Api = 51,  ///软件完整性自测试失败
	emDisConnect_GmTestErr_Api            = 52,  ///国密算法自测试失败
	emDisConnect_RandomNumTestErr_Api     = 53,  ///随机数自测试失败

	emDisConnect_StrongAuthButIpCallErr_Api = 54, ///强认证，不允许ip呼叫
	emDisConnect_ChannelNoAuth_Api			= 55, /// 渠道产品未经授权
	emDisconnect_CancleInputPwd_Api         = 57, ///< 取消输入会议密码
	emDisconnect_End = 100,                 ///< 前面用于扩展
};

/** 同步原因 */
enum EmUISynchronizeReason_Api
{
	emSynchronize_ApplyChair_Api = 0,       ///< 申请主席
	emSynchronize_ApplyChime_Api,		   ///< 申请插话
	emSynchronize_ApplySpeaker_Api,		   ///< 申请发言人
	emSynchronize_Upgrade_Api,			   ///< 升级
	emSynchronize_BeginDspSleep_Api,	   ///< 开始待机倒计时
	emSynchronize_CancelDspSleeep_Api,     ///< 取消待机倒计时
	emSynchronize_ApsLogin_Api,			   ///< 云登陆
	emSynchronize_ProlongConfTime_Api,	   ///< 会议延长
	emSynchronize_EnterConfPassword_Api,   ///< 输入会议密码
	emSynchronize_CancelEnterConfPassword_Api,   ///< 取消输入会议密码
    emSynchronize_RecountAutoSleepTime_Api, ///< 重新计算待机时间
};

/** 端点类型 */
enum EmEndpointType_Api
{
	emEndpointTypeUnknown_Api   = 0,      ///<未知类型
	emEndpointTypeMT_Api	    = 0x01,   ///<终端
	emEndpointTypeMCU_Api	    = 0x02,   ///<MCU
	emEndpointTypeGK_Api        = 0x04,   ///<GK
};

/** 注册失败原因 */
enum EmRegFailedReason_Api
{
	emGKFailedBegin_Api = 0,         ///<起始值
	emGKUnReachable_Api = 1,         ///<对端不可达
	emInvalidAliase_Api = 2,         ///<无效的别名
	emDupAlias_Api = 3,              ///<别名重复
	emInvalidCallAddress_Api = 4,    ///<无效的呼叫地址
	emResourceUnavailable_Api = 5,   ///<资源不可用
	//emUnknown_Api = 6,               ///<未知原因,不用
	emRegNumberFull_Api = 7,         ///<注册数量满，PCMT绑定GK失败消息提示
	emGKSecurityDenial_Api = 8,      ///<GK注册权限失败
	emGKDismatch_Api = 9,            ///<GK不是运营版本,服务器不匹配
	emUnRegGKReq_Api = 10,           ///<GK被抢登后，要求注销GK
	emRRQCreateHRASFailed_Api = 11,  ///<rrq创建句柄失败
	emRRQSendFailed_Api = 12,        ///<rrq发送失败

	emSipFailedBegin_Api =50,        ///<sip注册失败原因开始
	emSipLocalNormalUnreg_Api = 51,           ///<未注册
	emSipInvalidUserNameAndPassword_Api =52,  ///<无效的用户名和密码
	emSipRegistrarUnReachable_Api = 53,       ///<注册不可达
	emSipInvalidAlias_Api = 54,               ///<无效的别名
	emSipUnknownReason_Api = 55,              ///<未知原因
	emSipRegisterFailed_Api = 56,             ///<注册失败
	emSipRegisterNameDup_Api = 57,            ///<注册名称重复

	/////sec 注册失败reason
	emSecCrtNotFind_Api    = 58,   ///ca证书找不到
	emSecCrtVerifyFail_Api = 59,   ///证书验证失败
	emSecCrtExpired_Api    = 60,   ///证书过期 有效期错误
	emSecCrtFormatError_Api    = 61,   ///证书格式错误
	emSecLoadCertFailed_Api    = 62,
	
	emUnRegSuc_Api = 90,                     ///< 取消注册成功
	emRegSuccess_Api =100,                   ///<注册成功， sip和323都是这个
};

/** 轮询操作 */
enum EmAction_Api
{
	emActionBegin_Api = 0, ///<无效值
	emStart_Api = 1,       ///<开始
	emStop_Api,            ///<停止
	emPause_Api,           ///<暂停
	emResume_Api,          ///<恢复
};

/** 画面合成风格定义 */
enum EmMtVmpStyle_Api
{
	emInvalid_Style_Api = 0,            ///<非法值
	emMt_VMP_STYLE_DYNAMIC_Api = 1,		///<动态分屏(仅自动合成时有效)
	emMt_VMP_STYLE_1_Api = 2,			///<一画面全屏
	emMt_VMP_STYLE_2_1X2_Api = 3,		///<两画面: 2等大，居中(1行2列)
	emMt_VMP_STYLE_2_B1_S1RD_Api = 4,	///<两画面: 1大1小，1大全屏，1小右下
	emMt_VMP_STYLE_3_1U_2D1X2_Api = 5,	///<三画面: 等大，1上，2下(1行2列)
	emMt_VMP_STYLE_3_B1L_S2R2X1_Api = 6,	///<三画面: 1大2小，1大左，2小右(2行1列)
	emMt_VMP_STYLE_3_1L_2R2X1_Api = 7,	    ///<三画面: 等大，1左，2右(2行1列)
	emMt_VMP_STYLE_3_B1_S2LD1X2_Api = 8,	///<三画面: 1大2小，1大全屏，2小左下(1行2列)
	emMt_VMP_STYLE_3_3X1_Api = 9,		    ///<三画面: 等大，3行1列
	emMt_VMP_STYLE_4_2X2_Api = 10,			///<四画面: 等大，2行2列
	emMt_VMP_STYLE_4_B1L_S3R3X1_Api = 11,	///<四画面: 1大3小，1大左，3小右(3行1列)
	emMt_VMP_STYLE_4_B1U_S3D1X3_Api = 12,	///<四画面: 1大3小，1大上，3小下(1行3列)
	emMt_VMP_STYLE_5_B1L_S4R4X1_Api = 13,	///<五画面: 1大4小，1大左，4小右(4行1列)
	emMt_VMP_STYLE_5_B1U_S4D1X4_Api = 14,	///<五画面: 1大4小，1大上，4小下(1行4列)
	emMt_VMP_STYLE_5_B2U1X2_S3D1X3_Api = 15,	    ///<五画面: 2大3小，2大上(1行2列)，3小下(1行3列)
	emMt_VMP_STYLE_6_B1LU_S2RU2X1_S3D1X3_Api = 16,	///<六画面: 1大5小，1大左上，2小右上(2行1列)，3小下(1行3列)
	emMt_VMP_STYLE_6_B2U1X2_S4D1X4_Api = 17,	    ///<六画面: 2大4小，2大上(1行2列), 4小下(1行4列)
	emMt_VMP_STYLE_6_2X3_Api = 18,					///<六画面: 等大，2行3列
	emMt_VMP_STYLE_6_B1U_S5D1X5_Api = 19,			///<六画面: 1大5小，1大上，5小下(1行5列)
	emMt_VMP_STYLE_7_B2U1X2_B1LD_S4RD2X2_Api = 20,			///<七画面: 3大4小，2大上(1行2列)，1大左下，4小右下(2行2列)
	emMt_VMP_STYLE_7_S2LU2X1_B1MU_S2RU2X1_B2D1X2_Api = 21,	///<七画面: 3大4小，2小左上(2行1列)，1大中上，2小右上(2行1列)，2大下(1行2列)
	emMt_VMP_STYLE_7_B1U_S6D1X6_Api = 22,					///<七画面: 1大6小，1大上，6小下(1行6列)
	emMt_VMP_STYLE_8_B1LU_S3RU3X1_S4D1X4_Api = 23,			///<八画面: 1大7小，1大左上，3小右上(3行1列)，4小下(1行4列)
	emMt_VMP_STYLE_8_B4L2X2_S4R4X1_Api = 24,			    ///<八画面: 4大4小，4大左(2行2列)，4小右(4行1列)
	emMt_VMP_STYLE_9_3X3_Api = 25,					        ///<九画面: 等大，3行3列
	emMt_VMP_STYLE_9_S4U1X4_B1M_S4D1X4_Api = 26,		    ///<九画面: 1大8小，4小上(1行4列)，1大中，4小下(1行4列)
	emMt_VMP_STYLE_10_B2L2X1_S8R4X2_Api = 27,		        ///<十画面: 2大8小，2大左(2行1列)，8小右(4行2列)
	emMt_VMP_STYLE_10_B2U1X2_S8D2X4_Api = 28,		        ///<十画面: 2大8小，2大上(1行2列)，8小下(2行4列)
	emMt_VMP_STYLE_10_S4U1X4_B2M1X2_S4D1X4_Api = 29,	    ///<十画面: 2大8小，4小上(1行4列)，2大中(1行2列)，4小下(1行4列)
	emMt_VMP_STYLE_10_S4L4X1_B2M2X1_S4R4X1_Api = 30,	    ///<十画面: 2大8小，4小左(4行1列)，2大中(2行1列)，4小右(4行1列)
	emMt_VMP_STYLE_11_S5U1X5_B1M_S5D1X5_Api = 31,	///<十一画面: 1大10小，5小上(1行5列)，大1中，5小下(1行5列)
	emMt_VMP_STYLE_11_B1U_S10D2X5_Api = 32,			///<十一画面: 1大10小，1大上，10小下(2行5列)
	emMt_VMP_STYLE_12_B2U1X2_B1LD_S9RD3X3_Api = 33,	///<十二画面: 3大9小，2大上(1行2列)，1大左下，9小右下(3行3列)
	emMt_VMP_STYLE_12_B1LU_S5RU4X1_S6D1X6_Api = 34,	///<十二画面: 1大11小，大1左上，5小右上(4行1列)，5小下(1行5列)
	emMt_VMP_STYLE_13_B1LU_S4RU2X2_S8D2X4_Api = 35,	///<十三画面: 1大12小，大1左上，4小右上(2行2列)，8小下(2行4列)
	emMt_VMP_STYLE_13_S4U1X4_S2LM2X1_B1MM_S2LM2X1_S4D1X4_Api = 36,
	///<十三画面: 1大12小，4小上(1行4列)，2小左中(2行1列)，1大中中，2小右中(2行1列), 4小下(1行4列)

	emMt_VMP_STYLE_13_B4LU2X2_S4RU4X1_S5D1X5_Api = 37,				///<十三画面: 4大9小，4大左上(2行2列)，4小右上(4行1列)，5小下(1行5列)
	emMt_VMP_STYLE_14_B2LU1X2_S2RU2X1_S10D2X5_Api = 38,				///<十四画面: 2大12小，2大左上(1行2列)，2小右上(2行1列)，10小下(2行5列)
	emMt_VMP_STYLE_14_S5U1X5_B1LM_S2MM2X1_B1RM_S5D1X5_Api = 39,		///<十四画面: 2大12小，5小上(1行5列)，1大左中，2小中中(2行1列)，1大右中，5小下(1行5列)
	emMt_VMP_STYLE_15_B3U1X3_S12D2X6_Api = 40,						///<十五画面: 3大12小，3大上(1行3列)，12小下(2行6列)
	emMt_VMP_STYLE_15_S4U1X4_S3LM3X1_B1MM_S3RM3X1_S4D1X4_Api = 41,	
	///<十五画面: 1大14小，4小上(1行4列)，3小左中(3行1列)，1大中中，3小右中(3行1列)，4小下(1行4列)
	
	emMt_VMP_STYLE_16_4X4_Api = 42,									///<十六画面: 16等分，4x4
	emMt_VMP_STYLE_16_B1LU_S7RU7X1_S8D1X8_Api = 43,					///<十六画面: 1大15小，1大左上，7小右上(7行1列)，8小下(1行8列)
	emMt_VMP_STYLE_17_S5U1X5_S3LM3X1_B1MM_S3RM3X1_S5D1X5_Api = 44,	
	///<十七画面: 1大16小，5小上(1行5列)，3小左中(3行1列)，1大中中，3小右中(3行1列)，5小下(1行5列)
    
	emMt_VMP_STYLE_17_B1LU_S6RU3X2_S10D2X5_Api = 45,	    ///<十七画面: 1大16小，1大左上，6小右上(3行2列)，10小下(2行5列)
	emMt_VMP_STYLE_17_B2U1X2_S15D3X5_Api = 46,			    ///<十七画面: 2大15小，2大上(1行2列)，15小下(5列3行)
	emMt_VMP_STYLE_18_S6U1X6_B6M2X3_S6D1X6_Api = 47,		///<十八画面: 6大12小，6小上(1行6列)，6大居中(2行3列)，6小下(1行6列)
	emMt_VMP_STYLE_18_B6U2X3_S12D2X6_Api = 48,			    ///<十八画面: 6大12小，6大上(2行3列)，12小下(2行6列)
	emMt_VMP_STYLE_18_S6L6X1_B6M3X2_S6R6X1_Api = 49,		///<十八画面: 6大12小，6小左(6行1列)，6大中(3行2列)，6小右(6行1列)
	emMt_VMP_STYLE_19_B2LU1X2_S2RU2X1_S15D3X5_Api = 50,   	///<十九画面: 2大17小，2大左上(1行2列)，2小右上(2行1列)，15小下(3行5列)
	emMt_VMP_STYLE_19_B2LU2X1_S12RU4X3_S5D1X5_Api = 51,	    ///<十九画面: 2大17小，2大左上(2行1列)，12小右上(4行3列)，5小下(1行5列)
	emMt_VMP_STYLE_20_B2U1X2_S18D3X6_Api = 52,			    ///<二十画面: 2大18小，2大上(1行2列)，18小下(3行6列)
	emMt_VMP_STYLE_20_S6U1X6_B2M1X2_S12D2X6_Api = 53,	    ///<二十画面: 2大18小，6小上(1行6列)，2大中(1行2列)，12小下(2行6列)
	emMt_VMP_STYLE_21_S6U1X6_S4LM4X1_B1MM_S4RM4X1_S6D1X6_Api = 54,	
	///<二十一画面: 1大20小，6小上(1行6列)，4小左中(4行1列)，1大中中，4小右中(4行1列)，6小下(1行6列)

	emMt_VMP_STYLE_21_B1LU_S8RU4X2_S12D2X6_Api = 55,				///<二十一画面: 1大20小，1大左上，8小右上(4行2列)，12小下(2行6列)
	emMt_VMP_STYLE_22_B1LU_S6RU2X3_S15D3X5_Api = 56,			    ///<二十二画面: 1大21小，1大左上，6小右上(2行3列)，15小下(3行5列)
	emMt_VMP_STYLE_23_4U1X4_15M3X5_4D1X4_Api = 57,					///<二十三画面: 23同大，4上(1行4列)，15中(3行5列)，4下(1行4列)
	emMt_VMP_STYLE_23_B2U1X2_S4LM2X2_B1MM_S4RM2X2_S12D2X6_Api = 58,	
	///<二十三画面: 3大20小，2大上(1行2列)，4小左中(2行2列)，1大中中，4小右中(2行2列)，12小下(2行6列)
	
	emMt_VMP_STYLE_24_S6U1X6_S4LM4X1_B4MM2X2_S4RM4X1_S6D1X6_Api = 59,
	///<二十四画面: 4大20小，6小上(1行6列)，4小左中(4行1列)，4大中中(2行2列)，4小右中(4行1列) 下(1行6列)
	emMt_VMP_STYLE_25_5X5_Api = 60,									///<二十五画面: 等大，5行5列
	emMt_VMP_STYLE_25_S3LU3X1_B1MU_S3RU3X1_S18D3X6_Api = 61,			
	///<二十五画面: 1大24小，3小左上(3行1列)，1大中上，3小右上(3行1列)，18小下(3行6列)
	emMt_VMP_STYLE_2_B1_S1RU_Api = 62,						//两画面: 1大1小，1大全屏，1小右上
	emMt_VMP_STYLE_2_B1_S1LD_Api = 63,						// 两画面: 1大1小，1大全屏，1小左下
	emMt_VMP_STYLE_2_B1_S1L_Api = 64,						// 两画面: 1大1小，1大全屏，1小左上

	emMt_VMP_STYLE_20_5X4_Api = 100,                                 ///<二十画面，等分5*4， 兼容老的行业平台，5.0平台没有  
};

/** 画面合成成员类型定义 */
enum EmMtVMPMmbType_Api
{
	emVmpMmbType_NULL_Api  = 0,   ///< 无效值
	emVMPMmbMCSspec_Api = 1,      ///< 会控指定 
	emVMPMmbSpeaker_Api = 2,      ///< 发言人跟随
	emVMPMmbChairman_Api =3,      ///< 主席跟随
	emVMPMmbPoll_Api = 4,         ///< 轮询视频跟随
	emVMPMmbVAC_Api = 5,	      ///< 语音激励(会控不要用此类型)
	emVMPMmbCHLPOLL_Api   = 6,    ///< vmp单通道轮询
	emVMPMmbDSTREAM_Api   = 7,    ///< 双流跟随
	emVMPMmbVCSPEC_Api    = 8,    ///< 会议业务指定
};
 
/** 文件系统类型 */
enum EmFileSys_Api
{
	emRAWFS_Api =1,          ///< raw file system [ramdisk + rawblock + tffs]
	emTFFS_Api,              ///< tffs
};

/**  会议模式 */
enum EmConfMode_Api
{
	emConfNone_Api = 0,    ///< 无效值
	emP2PConf_Api,         ///< 点对点会议
	emMCCConf_Api,         ///< 多点会议
	emFXOConf_Api,         ///< 电话会议
};
 
/** 终端视频端口 */
enum EmMtVideoPort_Api
{
	emMtVidInvalid_Api = 0,
	emMtVidMultiView_Api = 1,
	emMtVidInnerCamera_Api = 2,   
	emMtVidDVI1_Api = 3,  
	emMtVidDVI2_Api = 4,  
	emMtVidDVI3_Api = 5,  
	emMtVidDVI4_Api = 6,  
	emMtVidHDMI1_Api = 7,
	emMtVidHDMI2_Api = 8, 
	emMtVidHDMI3_Api = 9,
	emMtVidHDMI4_Api = 10,
	emMtVidYPbPr1_Api = 11,
	emMtVidYPbPr2_Api = 12,
	emMtVidYPbPr3_Api = 13,
	emMtVidYPbPr4_Api = 14,
	emMtVidVGA1_Api = 15,
	emMtVidVGA2_Api = 16,
	emMtVidVGA3_Api = 17,
	emMtVidVGA4_Api = 18,
	emMtVidC1_Api = 19,
	emMtVidC2_Api = 20,
	emMtVidC3_Api = 21,
	emMtVidS1_Api = 22,
	emMtVidS2_Api = 23,
	emMtVidS3_Api = 24,
	emMtVidHDBaseT1_Api = 25,
	emMtVidHDBaseT2_Api = 26,
	emMtVidHDBaseT3_Api = 27,
	emMtVidHDBaseT4_Api = 28,
	emMtVidSDI1_Api = 29,
	emMtVidSDI2_Api = 30,
	emMtVidSDI3_Api = 31,
	emMtVidSDI4_Api = 32,
};

/** 加密算法 */
enum EmEncryptArithmetic_Api
{
	emEncryptNone_Api = 0,    ///< 不加密
	emDES_Api,                ///< DES加密
	emAES_Api,                ///< AES加密(128bit)
	emSM1_Api,
	emSM4_Api,
	emSM2_Api,
	emSM3_Api,
	emAuto_Api         =10  ,

};

/** 协议栈初始化 */
enum  EmStackInitFailReason_Api
{
	emH323InitSuccess_Api                  = 1,   ///< 成功
	emH323InitFailed_MemoryProblem_Api     = 2,   ///< 内存错误
	emH323InitFailed_ConfigProblem_Api     = 3,   ///< 配置错误
	emH323InitFailed_NetWorkProblem_Api    = 4,   ///< 网络错误
	emH323InitFailed_InitAgain_Api         = 5,   ///< 多次初始化
	emH323InitFailed_GenConfigFail_Api     = 6,   ///< 
	emH323InitFailed_InitSemFail_Api       = 7,   ///< 
	emH323InitFailed_NewConnInfoFail_Api   = 8,   ///< 
	emH323InitFailed_SetCBFail_Api         = 9,   ///< 
	emH323InitFailed_Unknown_Api           = 10,  ///< 未知错误

	/////sip初始化结果 
	emSipInitSuccess_Api                   = 30,  ///< sip初始化成功
	emSipInitFailed_Api                    = 31,  ///< sip初始化失败


	/////323pxy 初始化结果
	emH323PxyClient_Running_Api            = 50,  ///< 代理成功连接到server, 
	emH323PxyClient_NotRunning_Api         = 51,  ///< 运行失败，有可能没有连接server,
};

/** IP地址类型 */
enum EmIpAddrType_Api
{
	emIpV4_Api = 0,      ///< IPV4
	emIpV6_Api,          ///< IPV6
};

/** 会议类型 */
enum EmConfListType_Api
{
	emConfListType_Hold_Api = 0,      ///< 正在召开
	emConfListType_Book_Api,		  ///< 预约
	emConfListType_Tmplt_Api,	      ///< 模板
	emConfListType_End_Api,           ///< 枚举结束值
};

/** 获取会议列表错误码 */
enum EmConfListRspErr_Api
{
	emConfList_Finished_Api = 0,	          ///< 获取会议列表成功并结束
	emConfList_Not_Finished_Api = 1,          ///< 超过消息体大小，余下分包传送
	
	emConfList_UnCompleted_Api = 2,           ///< 部分获取会议列表（ ras超时没有收到finished，有可能有网络丢包现象）
	/** 下面三个是收到平台来的错误码 */
	emConfList_SerDbErr_Api  = 3,			  ///< 获取会议列表失败——数据库错误
	emConfList_Timeout_Api = 4,		          ///< 获取会议列表失败——服务器响应超时
	emConfList_UnknownErr_Api = 5,            ///< 获取会议列表失败（未知原因）
};

/** OSD台标类型  */
enum EmLabelType_Api
{
	emLabelAuto_Api = 0,      ///< 自动
	emLabelUserDef_Api,       ///< 自定义
	emLabelUserDefPic_Api,    ///< 自定义图片
	emLabelOff_Api,           ///< 关闭
};

/** OSD台标位置 */
enum EmLabelPosType_Api
{ 
	emTopLeft_Api = 0,     ///< 左上
	emTopRight_Api,         ///< 右上
	emBottomLeft_Api,      ///< 左下
	emBottomRight_Api,    ///< 右下
	emCustom_Api,           ///< 自定义
};

/**双流显示模式 */
enum EmDualVideoShowMode_Api
{
	emDualVideoOnSigleScreen_Api  = 1,  ///< 单屏双显
	emEachVideoOwnScreen_Api,           ///< 双屏双显
	emTripleVideoOnSingleScn_Api,       ///< 单屏三显
	emThreeVideoOnThreeScreen_Api,      ///< 三屏三显
};

/** 画中画显示模式 */
enum EmPiPMode_Api {
	emPiPInvalid_Api     = 0,				//无效的画中画
	emPiPClose_Api       = 1,				//画中画关闭						 (一画面 关闭多画面显示)
	emPIPLeftRight_Api   = 2,				//两画面，左右对等					（两画面 左右对等）
	emPiPRightBottom_Api = 3,				//画中画小画面显示在右下角			（两画面 一大一小 右下）
	emPiPLeftBottom_Api  = 4,				//画中画小画面显示在左下角			（两画面 一大一小 左下）
	emPiPLeftTop_Api     = 5,				//画中画小画面显示在左上角			（两画面 一大一小 左上）
	emPiPRightTop_Api    = 6,				//画中画小画面显示在右上角			（两画面 一大一小 右上）
	emPiPTwoSmallLeftInOneBig_Api = 7,		//一大两小，大画面包含两个小画面(小画面靠左)	（三画面  画中画）
	emPiPTwoSmallRightInOneBig_Api = 8,		//一大两小，大画面包含两个小画面(小画面靠右)	（三画面  画中画）
	emPiPOneBigAndTwoSmall_Api = 9,			//一大两小，大画面左，右侧画外有两个小画面		（三画面  画外画 左大右两小）
	emPiPThree_Api = 10						//三画面,品字形									（三画面  品字形）
};

/** 显示比例 */
enum EmDisplayRatio_Api
{
	emDR4to3_Api  = 0,   ///<4:3
	emDR16to9_Api,       ///<16:9
	emDRAuto_Api,        ///<自动
};

/** 铃声*/
enum EmMtRing_Api
{
	emRingNone_Api = 1,
	emRing_Api,             ///< ring.pcm
	emRing1_Api,            ///< ring_1.pcm
	emRing2_Api,            ///< ring_2.pcm
	emRing3_Api,            ///< ring_3.pcm
	emRing4_Api,            ///< ring_4.pcm
	emRingHighTemp_Api,     ///< ringhightemp.pcm
	emRingUsrDef1_Api,      ///< 自定义铃声1
	emRingUsrDef2_Api,      ///< 自定义铃声2
	emRingUsrDef3_Api,      ///< 自定义铃声3
	emRingUsrDef4_Api,      ///< 自定义铃声4
	emRingUsrDef5_Api,      ///< 自定义铃声5
};

/** QoS类型*/
enum EmQoS_Api
{
	emDiffServ_Api = 0,    ///< 区分服务
	emIPPrecedence_Api,    ///< IP优先
};

/** TOS类型*/
enum EmTOS_Api
{
	emTOSNone_Api = 0,    ///< 不使用
	emTOSMinCost_Api,     ///< 最小开销
	emTOSMaxReliable_Api, ///< 最高可靠性
	emTOSMaxThruput_Api,  ///< 最大吞吐量
	emTOSMinDelay_Api,    ///< 最小延迟
};

/* 丢包重传时所选择的网络类型 */
enum EmNetType_Api
{
	emInternet_Api = 0,  //Interent
	emSpecial_Api,       //
	emVPN_Api,           //VPN
};

/** 编码方式 */
enum EmEncodeMode_Api
{
	emQualityFirst_Api = 0,  ///<质量优先
	emSpeedFirst_Api,        ///<速度优先
};

/** 解码器丢包恢复策略 */
enum EmLostPackStrategy_Api
{
	emLPSQualityFirst_Api = 0,  ///<质量优先
	emLPSSpeedSlow_Api,         ///<慢
	emLPSSpeedNormal_Api,       ///<正常
	emLPSSpeedFast_Api,         ///<快
};

/** 升级包版本等级 */
enum EmUpgradeVerLevel_Api
{
	emUpgradeLevelForced_Api = 0,  ///< 强制
	emUpgradeLevelSuggested_Api,   ///< 建议
	emUpgradeLevelNormal_Api,      ///< 普通
};

/** 版本发布属性 */
enum EmUpgradeReleaseAttr_Api
{
	emUpgradeAttr_Api                     = 0,
	emUpgradeAttrCommon_Api       = 1,	///< 普通版本
	emUpgradeAttrRecommend_Api  = 2,	///< 推荐版本
	emUpgradeAttrGray_Api              = 4,	///< 灰度版本
};

/** 用户会议信息操作类型 */
enum EmMtModifyConfInfoType_Api {
	MT_MODIFY_BEGIN_Api = 0,
	MT_MODIFY_CONF_NAMETYPE_Api,         ///<会议名称类型
	MT_MODIFY_CONF_DURATIONTYPE_Api,     ///<会议持续时间
	MT_MODIFY_CONF_PWDTYPE_Api,          ///<会议密码
	MT_MODIFY_CONF_DUAL_MODETYPE_Api,    ///<双流发送模式(发言人 or 所有人)
	MT_MODIFY_CONF_VMP_SHOW_ALIAS_Api,   ///<画面合成中是否显示别名
	MT_MODIFY_CONF_OPENMODE_Api,	     ///<修改会议的openmode-暂不支持
	MT_MODIFY_CONF_DUMB_Api,	         ///<修改会议全体哑音
	MT_MODIFY_CONF_NoDisturb_Api,	     ///<修改会议是否终端免打扰（对应平台是否封闭）
};

/** 会议发生错误时带的失败原因 */
enum EmMtConfFailureReason_Api        
{
	emFAIL_REASON_DIFF_CONF_ENCRYPT_MODE_Api = 1,                ///<会议加密类型
	emFAIL_REASON_MT_NOT_JOINED_CONF_Api,                        ///<终端没有参加会议
	emFAIL_REASON_CONF_IS_NOT_CPING_Api,                         ///<
	emFAIL_REASON_MT_IS_NOT_CHAIR_Api,                           ///<终端非主席
	emFAIL_REASON_CONF_IS_NOT_DIALOG_MODE_Api,                   ///<会议不是对话模式
	emFAIL_REASON_NO_IDLE_CONF_RESOURCE_Api,                     ///<没有空闲的会议资源
	emFAIL_REASON_CONF_RESOURCE_LACK_Api,                        ///<缺少会议资源
	emFAIL_REASON_MT_IN_DIALOG_Api,                              ///<终端在对话模式中
	emFAIL_REASON_SEL_MT_VID_OVER_CHNNL_NUM_Api,                 ///<视频选看时，超过最大回传通道数
	emFAIL_REASON_SEL_MT_AUD_OVER_CHNNL_NUM_Api,                 ///<音频选看时，超过最大回传通道数
	emFAIL_REASON_SEL_MT_BOTH_OVER_CHNNL_NUM_Api,                ///<音视频选看时，超过最大回传通道数
	emFAIL_REASON_CAN_NOT_JION_VMP_BY_OVER_CHNNL_NUM_Api,        ///<自动、对讲画面合成时，由于回传通道数的限制未能加入到画面合成中
	emFAIL_REASON_CAN_NOT_JION_MIX_BY_OVER_CHNNL_NUM_Api,        ///<会议讨论时，由于回传通道数的限制未能加入到讨论组中
	emFAIL_REASON_CHANGE_VMP_ASK_FALSE_Api,                      ///<终端申请对话方失败
	emFAIL_REASON_CAN_NOT_JION_CTRY_VMP_BY_OVER_CHNNL_NUM_Api,   ///<会议模板定制画面合成时，由于回传通道数的限制未能加入到画面合成中
};

/** 画面合成方式 */
enum EmMtVmpMode_Api
{
	emMt_VMP_MODE_NONE_Api = 0,  ///< 不进行画面合成
	emMt_VMP_MODE_CTRL_Api,      ///< 会控或主席选择成员合成
	emMt_VMP_MODE_AUTO_Api,      ///< 动态分屏与设置成员
};

/** 双流发送模式 */
enum EmMtDualMode_Api
{
	emMt_Dual_Mode_Speaker_Api = 0,	 ///< 只有发言人能发双流(0-发言会场)
	emMt_Dual_Mode_Everyone_Api,	 ///< 任何人都能发双流(1-任意会场)
	emMt_Dual_Mode_Invalid_Api,      ///< 不支持
};

/** 会议开发模式 */
enum EmMtOpenMode_Api
{
	emMt_Open_Api = 1,                      ///< 完全开放 
	emMt_Hide_Api,                          ///< 隐藏会议，仅受邀列表里的终端可见
};

/** 服务器类型 */
enum EmServerType_Api
{
	emAPS_Api = 0, ///< 接入
	emXNU_Api = 1, ///< XMPP
	emSUS_Api = 2, ///< 升级
//	emPAS_Api = 3, ///< GK
	emNMS_Api = 3, ///< 网管
	emNTS_Api = 4, ///< 测速
	emSIP_Api = 5, ///< SIP呼叫
	emNonH323_Api = 6, ///<非标H323
	emStdH323_Api = 7, //<标准H323
	emNTP_Api = 8, ///< 时间同步
	emVOD_Api = 9, ///< VOD
	emMoMeeting_Api = 10,   ///< 会管
	emMoPlatform_Api = 11, ///< 平台
	emVRS_Api = 12,        ///< VRS
	emDCS_Api = 13,        ///< DCS
	emNS_Api  = 14,        ///<推送服务器
	emServerTypeEnd_Api = 15,    ///< 枚举结束值
};

/** 终端类型 */
enum EmMtImTerminalType_Api
{
	IM_MT_TYPE_UNKNOWN_Api  = 0,           ///< 未知
	IM_MT_TYPE_TRUE_LINK_Api,              ///< 致邻
	IM_MT_TYPE_TRUE_TOUCH_PHONE_Api,       ///< 手机-android
	IM_MT_TYPE_TRUE_TOUCH_PAD_Api,         ///< 平板-ios
	IM_MT_TYPE_TRUE_SENS_Api,              ///< 硬终端
	IM_MT_TYPE_TRUE_TOUCH_PHONE_IOS_Api,   ///< 手机-ios
	IM_MT_TYPE_TRUE_TOUCH_PAD_ANDROID_Api, ///< 平板-android
	IM_MT_TYPE_TEL_Api,					   ///< 为2.6通讯录区分终端类型，新增电话类型
	IM_MT_TYPE_TRUE_LINK_TV_Api,          ///< TV盒子
	IM_MT_TYPE_THIRDPARTY_TER_Api,         ///< 第三方终端
	IM_MT_TYPE_END_Api ///< 枚举结束值
};

/** 在线状态 */
enum EmMtOnlineState_Api
{
	EM_STATE_INVALID_Api = 0,         ///< 无状态
	EM_STATE_OFFLINE_Api,             ///< 离线
	EM_STATE_LEAVE_Api,               ///< 暂时离开
	EM_STATE_ONLINE_Api,              ///< (正常)在线
	EM_STATE_NO_DISTURB_Api,          ///< 免打扰
	EM_STATE_CONFERENCE_Api,          ///< 会议中
	EM_STATE_HIDDEN_Api,              ///< 隐身
	EM_STATE_LOGINING_Api,            ///< 登陆中
	EM_STATE_END_Api
};

/** 多人聊天类型 */
enum EmMtMultiChatType_Api
{
	EM_MULTICHAT_INVALID_Api = 0,       ///< 非法类型
	EM_MULTICHAT_NORMAL_Api,            ///< 普通类型
	EM_MULTICHAT_CONF_Api,              ///< 会议类型
	EM_MULTICHAT_END_Api                 ///< 枚举结束值
};

/** IM连结状态 */
enum EmConnectImResult_Api
{
	EM_STATE_OPEN_Api = 0,			    ///< 连接成功
	EM_STATE_CLOSED_Api     			///< 连接断开
};

/** IM错误 */
enum EmImServiceError_Api
{
	IM_SERVICE_ERR_OK_Api  = 0,                                      ///< 成功
	IM_SERVICE_ERR_PARAM_LENGTH_INCORRECT_Api  = 1000,               ///< 参数长度不对
	IM_SERVICE_ERR_REACH_MAX_LOGGING_ACCOUNT_Api,                    ///< 已经使用了最大数量账号进行登录
	IM_SERVICE_ERR_INVALID_ACCOUNT_HANDLE_Api,                       ///< 参数账号标志不对
	IM_SERVICE_ERR_INVALID_ARGUMENT_Api,                             ///< 参数不对
	IM_SERVICE_ERR_PEER_NOT_ONLINE_Api,                              ///<对端不在线
	IM_SERVICE_ERR_PEER_NO_FILE_SHARE_ABILITY_Api,                   ///<没有文件共享权限
	IM_SERVICE_ERR_NO_RESOURCE_Api,                                  ///<服务器没有资源
	IM_SERVICE_ERR_UNAUTHORIED_Api,                                  ///<未授权
	IM_SERVICE_ERR_UNSUPPORT_Api,                                    ///<不支持
	IM_SERVICE_ERR_NO_CHCHE_RES_Api,                                 ///<

	IM_SERVICE_ERR_UNKNOWN_Api = -1
};

/** Decline原因 */
enum EImDeclineReason_Api
{
	IM_DECLINE_REASON_UNKNOWN_Api,                                       ///< 未知原因
	IM_DECLINE_REASON_MAX_PERSISTENT_ROOM_COUNT_Api,                     ///< 达到固定群最大数
	IM_DECLINE_REASON_MAX_TEMPORARY_ROOM_COUNT_Api,                      ///< 达到临时群最大数
	IM_DECLINE_REASON_FROM_WEIBO_Api                                     ///< 仅微博在线时的拒绝
};

/** 输入状态 */
enum EmImCharState_Api
{
	IM_CHAR_STATE_ACTIVE_Api       = 0,
	IM_CHAR_STATE_COMPOSING_Api,                                ///< 正在输入
	IM_CHAR_STATE_PAUSED_Api                                    ///< 停止输入
};

/** 终端成员类型 */
enum EmMtMemberType_Api
{
	EM_MEMBER_INVALID_Api = 0,		
	EM_MEMBER_IM_ID_Api,            ///< XMPP JID
	EM_MEMBER_TELEPHONE_Api,		///< 电话类型	
	EM_MEMBER_FXO_Api,		        ///< FXO电话类型	
	EM_MEMBER_JID_Api               ///< Jid类型	
};

/** API类型 */
enum EmAPIType_Api
{
	emUnknown_API_Api = 0,
	emPlatform_API_Api,       ///<平台API
	emWeibo_API_Api,          ///<微博API
	emMeeting_API_Api,        ///<会议API
	emApp_API_Api
};

/** 用户信息 */
enum EmMtOperateUserInfo_Api
{
	MT_OPERATE_USER_ADD_Api = 0,			///<增加好友
	MT_OPERATE_USER_DELETE_Api,				///<删除好友
	MT_OPERATE_USER_MODIFY_Api,             ///<修改好友
	MT_OPERATE_USER_SEARCH_Api,             ///<查询好友
};

/** 呼叫时长（会议API使用）*/
enum EmCallDuration_Api
{
	emVeryShort_Api = 0, ///<最短
	emShort_Api,         ///<短
	emNormal_Api,        ///<正常
	emLong_Api,          ///<长
	emVeryLong_Api,       ///<最长
};

/** 桌面共享权限 */
enum EmDesktopShareLimit_Api
{
	emLimit_Speaker_Api = 0,  ///<仅限发言人
	emLimit_All_Api           ///<所有人
};

/** 会议模式 */
enum EmVMeetingMode_Api
{
	emModeDiscuss_Api = 0,
	emModeTraining_Api
};

/** 会议清晰度 */
enum EmVMeetingVideoModel_Api
{
	emModelFluent_Api = 1,    ///<流畅
	emModelNormalQuality_Api, ///<标清
	emModelHighQuality_Api,    ///<高清
    emModelFullHighQuality_Api,    ///<全高清
};

/** 会议通知类型 */
enum EmRestMeetingNotifyType_Api
{
	emRestMeetingNotifyTypeUnknown_Api        = 0,

	emCreateMeeting_Api = 102,                               ///<创建会议
	emUpdateMeeting_Api,                             ///<更新会议
	emDeleteMeeting_Api,                             ///<删除会议
	emCreateRegular_Api,                             ///<创建例会会议成功(对于创建会议者) / 邀请参加会议(对于被邀请方)
	emUpdateRegular_Api,                             ///<更新例会通知(未实现)
	emDeleteRegular_Api,                             ///<删除例会通知(未实现)
	emUpdateMeetingCancelPerson_Api,                 ///<更新会议时间
	emAheadOfMeeting_Api,                            ///<会议开始前15分钟提醒通知(废弃不用)
	emCancelRoom_Api,                                ///<取消会议
	emDeadLineChanged_Api,                           ///<改变会议截止时间
	emUserFeedbacked_Api,                            ///<同意参加会议
	emForbiddenRoom_Api,                             ///<会议室被禁用
	emDeleteRoom_Api,                                ///<会议室被删除
	emStartTimeAchieve_Api,                          ///<会议即将开始，请确认是否召开
	emNormalStart_Api,                               ///<会议开始通知（会议状态变为2），注:废弃不用
	emStartMeetingRemind_Api,                        ///<会议开始前2小时，提醒发起人点“正常召开”
	emStartBeforeMeeting_Api,                        ///<会议提前召开，通知参会人，会议时间会更改
	emParticipant_Meeting_Remind_Api,                 ///<会议开始前15分钟提醒，会通知参会人、创建人、管理方（如果是视频会议)
    emLive_URL_Api,                                   ///<会管向终端推送直播消息
};

/** 呼入，呼出，还是未接，全部 */
enum EmMtCallRecordType_Api
{
	emCallIn_Api 	= 0,		///< 呼入
	emCallOut_Api,				///< 呼出
	emMissed_Api,				///< 未接
	emAll_Api,					///< 全部
};

/** 呼叫类型（视频，还是音频,还是电话） */
enum EmMtCallType_Api
{
	emVideo_Api = 0,			///< 视频呼叫
	emAudio_Api,				///< 音频呼叫
	emPhone_Api,				///< 电话呼叫
};

/** 呼叫记录查找类型 */
enum EmMtRecordSearchType_Api
{
	emCallRecordType_Api = 0,	///< 根据是呼入，呼出，还是未接
	emCallType_Api,				///< 根据是视频，还是音频呼叫
	emDescribe_Api,				///< 按条目名称
};

/** 呼叫记录错误码 */
enum EmMtRecordErr_Api
{
	emRecord_Ok_Api = 0,
	emRecord_Err_Index_Api,						///< 获取时提供的索引值错误
	emRecord_Err_No_Marching_Records_Api,		///< 没有符合条件的记录
	emRecord_Err_No_Marching_Type_Api,			///< 没有符合的匹配类型
	emRecord_Err_CallRecordType_Api,			///< 呼叫记录类型异常（不在呼入，呼出，未接里）
	emRecord_Err_CallType_Api,					///< 呼叫类型异常（不在视频呼叫，音频呼叫里）
	emRecord_Err_Describe_Api,					///< 条目描述为空
	emRecord_Err_AddrType_Api,					///< 不是有效呼叫（不是E164，也不是IP，也不是电话等等）
	emRecord_Err_Addr_Api,						///< 本身呼叫内容异常（内容为空）
	emRecord_Err_Rate_Api,						///< 呼叫码率为0
	emRecord_Err_PackageNum_Api,				///< 分包数量异常
	emRecord_Err_Over_MaxLocalRecordNum_Api = 11,   ///< 超过最大联系人数量

	emRoster_Err_GroupName_NULL_Api = 100,		///< 组名为空
	emRoster_Err_GroupSn_Api,					///< 组SN号异常
	emRoster_Err_ParentGroupSn_Api,				///< 父组SN号异常
	emRoster_Err_RosterSn_Api,					///< 联系人SN号异常
	emRoster_Err_RosterName_Api,				///< 联系人条目描述异常
};

/** 子系统启动方式 */
enum EmMtSysStartMod_Api
{
	emSysStart_By_Thread_Api = 0,	    ///< 以线程方式加载
	emSysStart_By_Process_Api,		    ///< 以进程加载

	emSysStartMod_End_Api,
};

/** 子系统运行状态 */
enum EmMtSysSrvState_Api
{
	emSysSrvState_Idle_Api = 0,			///< 空闲
	emSysSrvState_Start_Api,			///< 是否绑定
	emSysSrvState_Running_Api,			///< 运行
	emSysSrvState_Stop_Api,			    ///< 停止
	emSysSrvState_Err_Api, 			    ///< 异常
};

/** 子系统存活状态 */
enum EmMtSysKeepLiveState_Api
{
	emSysKLState_Ready_Api = 0,			///< 准备就绪
	emSysKLState_Alive_Api,			    ///< 存活
	emSysKLState_Err_Api, 			    ///< 异常
};

/** 端口类型 */
enum EmPortType_Api
{
	emConfChanPort_Api = 0,     ///< 会议通道占用的udp端口,  对应媒体端口，因媒体端口不是连续的， 所有的端口号都给上去
	emImPort_Api = 1,           ///< IM (暂不使用)
	emVodPort_Api = 2,          ///< 点播 (暂不使用)
	emMcPort_Api = 3,           ///< MC (暂不使用)
	emH323CallingPort_Api = 4,  ///< H323呼叫      对应是 h225端口
	emH323TcpBasePort_Api = 5,  ///< H323起始端口  对应是 h245起始
	emH323TcpEndPort_Api = 6,   //< /H323结束端口 对应是 h245结束
	emH323PxyBasePort_Api = 7,      ///< 323代理起始media端口， 更多端口需要协议提供接口，暂时没有
	emH323PxyEndPort_Api = 8,      ///< 323代理结束media端口， 更多端口需要协议提供接口，暂时没有
	emSipBfcpPort_Api = 9,      ///< sip bfcp 
	emMTCPort_Api = 10,			///<  MTC使用端口
	emGKPort_Api = 11,			///<  本地ras端口，H323CallingPort - 1
	emSipCallingPort_Api = 12,  ///< sip呼叫端口 
	emPortTypeEnd_Api,       
};

/** 服务器连接状态 */
enum EmServerState_Api
{
	emSrvIdle_Api = 0,                  ///< 空闲     
	emSrvDnsQuerying_Api = 1,           ///< 正在解析IP
	emSrvLogging_In_Api = 2,            ///< 正在登录
	emSrvLogin_Succ_Api = 3,            ///< 登录成功
	emSrvLogging_Out_Api = 4,           ///< 正在登出
	emSrvDisconnected_Api = 5,          ///< 断链（适用于保持心跳的服务器）
	emSrvLogin_Err_Api = 6              
};

/* APS登陆服务器返回的错误码 */
enum EmApsLoginErrcode_Api {
	emApsLoginOk_Api = 0,        ///<登陆成功
	emApsLoginErrUnknown_Api = 1 ///<未知错误
};

/* 高清分辨率输出制式 */
enum EmHDVideoOutputMode_Api
{
	emVOM_HD_ORIGIN_Api = 0,
	emVOM_HD_1080p_24_Api = 1,       ///<1080P 24fps
	emVOM_HD_1080p_25_Api = 2,       ///<1080P 25fps
	emVOM_HD_1080p_30_Api = 3,       ///<1080P 30fps
	emVOM_HD_1080p_50_Api = 4,       ///<1080P 50fps
	emVOM_HD_1080p_60Hz_Api = 5,       ///<1080P 60Hz
	emVOM_HD_1080p_60fps_Api = 6,       ///<1080P 60Fps

	emVOM_HD_1080i_50_Api = 7,       ///<1080I 50Hz
	emVOM_HD_1080i_60_Api = 8,       ///<1080I 60Hz
	emVOM_HD_720p_50_Api = 9,        ///<720P  50fps
	emVOM_HD_720p_60hz_Api = 10,     ///<720P  60Hz
	emVOM_HD_720p_60fps_Api = 11,	///<720P  60fps
	emVOM_HD_576i_50_Api = 12,       ///<576I  50Hz
	emVOM_HD_1080p_29_Api = 13,      ///<1080P 29Hz
	emVOM_HD_1080p_59_Api = 14,      ///<1080P 59Hz
	emVOM_HD_576p_Api = 15,          ///<576P   
	emVOM_HD_1080p_29_97_Api = 16,   ///<1080P 29.97fps
	emVOM_HD_1080p_59_94_Api = 17,   ///<1080P 59.94fps
	emVOM_HD_VGA_60_Api = 18,        ///<VGA 60Hz
	emVOM_HD_VGA_75_Api = 19,        ///<VGA 75Hz
	emVOM_HD_SVGA_60_Api = 20,       ///<SVGA 60Hz
	emVOM_HD_SVGA_75_Api = 21,       ///<SVGA 75Hz
	emVOM_HD_XGA_60_Api = 22,        ///<XGA  60Hz
	emVOM_HD_XGA_75_Api = 23,        ///<XGA  75Hz
	emVOM_HD_SXGA_60_Api = 24,       ///<SXGA 60Hz
	emVOM_HD_WXGA1280x768_60_Api = 25,     ///<WXGA 1280x768 60Hz
	emVOM_HD_WXGA1280x768_75_Api = 26,     ///<WXGA 1280x768 75Hz
	emVOM_HD_WXGA1280x800_60_Api = 27,     ///<WXGA 1280x800 60Hz
	emVOM_HD_WXGA1280x800_75_Api = 28,     ///<WXGA 1280x800 75Hz
	emVOM_HD_WXGA1366x768_60_Api = 29,     ///<WXGA 1360x768 60Hz
	emVOM_HD_UXGA1600x1200_60_Api = 30,    ///<UXGA 1600x1200 60Hz
	emVOM_HD_WSXGA1440x900_60_Api = 31,    ///<WSXGA 1440x900 60Hz
	emVOM_HD_SXGAPLUS1680x1050_60_Api = 32, ///<SXGAPLUS 1680x1050 60Hz
	emVOM_HD_4k3860x2160_30_Api = 33,       ///<4k 3860x2160 30Hz
	emVOM_HD_4k3860x2160_60_Api = 34        ///<4k 3860x2160 60Hz

};

/** 横幅文字布局 */
enum EmHDTextAlign_Api
{
	emHDAlignLeft_Api = 0,   ///<左
	emHDAlignCenter_Api = 1, ///<中
	emHDAlignRight_Api = 2   ///<右
};

/** 横幅滚动类型 */
enum EmHDRollMode_Api
{
	emHDStatic_Api = 0,     ///<静态
	emHDRight2Left_Api = 1, ///<从右至左
	emHDDown2Up_Api = 2,    ///<从下至上
	emHDScollPage_Api = 3   ///<翻页
};


/** 横幅滚动速度 */
enum EmHDRollSpeed_Api
{
	emHDRollSlower_Api = 0, ///<较慢
	emHDRollSlow_Api = 1,   ///<慢
	emHDRollNormal_Api = 2, ///<常速
	emHDRollFast_Api = 3,   ///<快
	emHDRollFaster_Api = 4  ///<较快
};

/** 音频输入接口 */
enum EmHDAudPortIn_Api
{
	emHDAudInBegin_Api = 0,     ///< X500                  X700-4K|X500-4K
	emHDAudInDMic1_Api = 1,     ///< 数字MIC1              有线MIC 1
	emHDAudInDMic2_Api = 2,     ///< 有线MIC 2             有线MIC 2
	emHDAudInXLR_Api = 3,       ///< 卡侬MIC 1             卡侬MIC 1
	emHDAudInWMic1_Api = 4, 	///< 无线MIC 1             无线MIC 1
	emHDAudInWMic2_Api = 5, 	///< 无线MIC 2             无线MIC 2
	emHDAudInWMic3_Api = 6, 	///< 无线MIC 3             无线MIC 3
	emHDAudInRCA_Api = 7,       ///< LINE 4                LINE 5
	emHDAudInTRS3_5_Api = 8,    ///< AUX 3                 AUX 3
	emHDAudInHDMI1_Api = 9,     ///< HDMI_4                HDMI_6
	emHDAudInHDMI2_Api = 10,    ///< ...                   HDMI_1
	emHDAudInHDMI3_Api = 11,    ///< ...                   HDMI_2
	emHDAudInDHDMI_Api = 12,    ///< DVI/YPbPr/VGA/HDMI 3  DVI/HDMI/VGA/YPbPr 5
	emHDAudInSDI1_Api = 13,     ///< SDI1                  SDI 3
	emHDAudInSDI2_Api = 14,     ///< SDI2                  SDI 4
	emHDAudInHDBaseT1_Api = 15, ///< HDBaseT 1             HDBaseT 1
	emHDAudInHDBaseT2_Api = 16, ///< HDBaseT 2             HDBaseT 2
	emHDAudInDsiMic1 = 17,      ///< //内置Mic1
	emHDAudInDsiMic2 = 18       ///< //内置Mic2
};

/** 音频输出接口 */
enum EmHDAudPortOut_Api
{
	emHDAudOutBegin_Api  = 0, // X500                    X700-4K|X500-4K
	emHDAudOutRCA_Api    = 1, // LINE 3                  LINE 3
	emHDAudOutTRS6_5_Api = 2, // TRS 1                   TRS 1
	emHDAudOutTRS3_5_Api = 3, // AUX 2                   AUX 2
	emHDAudOutDHDMI1_Api = 4, // DVI/YPbPr/VGA/HDMI1 1   DVI/HDMI/VGA/YPbPr 3
	emHDAudOutDHDMI2_Api = 5, // ...                     ...
	emHDAudOutHDMI_Api   = 6, // HDMI_3                  HDMI_4
	emHDAudOutSDI_Api    = 7, // SDI                     SDI 5
	emHDAudOutHDMI1_Api  = 8, // ...                     HDMI_1
	emHDAudOutHDMI2_Api  = 9  // ...                     HDMI_2

};

/** 视频类型 */
enum EmHDVideoType_Api
{
	emHD1stPriVideo_Api = 0, ///<第一路主视频
	emHD2ndPriVideo_Api = 1, ///<第二路主视频
	emHD3rdPriVideo_Api = 2, ///<第三路主视频
	emHDAssVideo_Api = 10     ///<辅视频
};

/** 多流多视开关 */
enum EmHDMultiVideoSwitch_Api
{
	emHDMultiVideoStop_Api = 0, ///<关闭多流或者多视
	emHDMultiView_Api = 1,      ///<多视
	emHDMultiStream_Api = 2     ///<多流

};

/** 多视画面风格 */
enum EmHDMultiViewMP_Api
{
	emMVMP_LeftRight_One_Api = 0, //两画面,左右对等
	emMVMP_BigSmall_RightDown_Api = 1, //一大一小，小画面右下
	emMVMP_BigSmall_LeftDown_Api = 2,//一大一小，小画面左下
	emMVMP_BigSmall_LeftUp_Api = 3,//一大一小，小画面左上
	emMVMP_BigSmall_RightUp_Api = 4, //一大一小，小画面右上	
	emMVMP_3View_1Big2Small_Api   = 5, //三视，1大2小，1左，2右(2行1列)
	emMVMP_3View_1Top2Bottom_Api  = 6, //三视，品字形，1上，2下(1行2列)
	emMVMP_SingleView_Close_Api   = 7 //单画面，即关闭多视
};

/** 视频接口模式 */
enum EmHDVideoPortMode_Api
{
	emHDVPM_Invalid_Api = 0,
	emHDVPM_Auto_Api = 1,    ///<自动
	emHDVPM_HDMI_Api = 2,    ///<HDMI
	emHDVPM_DVI_Api = 3,     ///<DVI
	emHDVPM_YPBPR_Api = 4,   ///<YPBPR
	emHDVPM_VGA_Api = 5      ///<VGA
};

/** 无图像显示输出配置 */
enum EmHDLastDisplay_Api
{
	emHD_LastFrame_Api = 0,                ///<最后一帧
	emHD_BlueScreen_Api = 1,               ///<蓝屏
	emHD_StaticBMP_Api = 2,                ///<静态图片 
	emHD_CustomBMP_Api = 3,                ///<用户自定义图片 
};

/** 图像降噪 */
enum EmHDImageNoise_Api
{
	emHDImageNoise_Disable_Api = 0,         ///<关闭
	emHDImageNoise_Low_Api = 1,             ///<微弱
	emHDImageNoise_Mid_Api = 2,             ///<弱
	emHDImageNoise_High_Api = 3,            ///<强
	emHDImageNoise_UltraHigh_Api = 4,       ///<超强
};

/** 麦克增益 */
enum EmMicGain_Api
{
	emHDMicGain_Disable_Api = 0,        ///<关闭
	emHDMicGain_Low_Api = 1,                ///<小
    emHDMicGain_Mid_Api = 2,                ///<中
	emHDMicGain_High_Api = 3,               ///<大
};

/** 变形拉伸 */
enum EmHDImageDeformationTensile_Api
{
	emImageDT_Transverse_Api = 0,       ///<左右
	emImageDT_Longitudinal_Api = 1,     ///<上下
};

/** 串口类型 */
enum EmHDSerialType_Api
{
	emRS232_Api = 0,           ///<RS232
	emRS422_Api = 1,           ///<RS422
	emRS485_Api = 2,           ///<RS485
	emSerialInfrared_Api = 3,  ///<红外串口线
	emHDBaseT1_Api = 4,        ///<HDBaseT1
	emHDBaseT2_Api = 5,        ///<HDBaseT2
	emRS232_2_Api  = 6,        ///<RS232_2
};

/** 串口停止位*/
enum EmHDStopBits_Api
{
	em1StopBit_Api     = 0,    ///<1位
	em1HalfStopBit_Api = 1,    ///<1.5位
	em2StopBit_Api     = 2,    ///<2位
};

/** 串口校验位 */
enum EmHDParityCheck_Api
{
	emNoCheck_Api   = 0,      ///<无校验
	emOddCheck_Api  = 1,      ///<奇数校验
	emEvenCheck_Api = 2,      ///<偶数校验
};

/** SDI接口数量 */
enum EmSdiInOut_Api
{
	emSdiNone_Api = 0, ///<无sdi
	emSdiTwoIn_Api = 1, ///<两进口
	emSdiOneInOneOut_Api = 2 ///<一进口一出口
};

/** VNC类型 */
enum emVncType
{
	emVncType_NULL_Api = 0,                  ///<无效
	emVncType_Desktop_Api,                   ///<桌面共享
	emVncType_App_Api,                       ///<应用程序共享
};

/** 服务器地址类型 */
enum EmServerAddrType_Api
{
	emSrvAddrTypeDefault_Api = 0, ///<默认不可修改
	emSrvAddrTypeCustom_Api = 1,  ///<用户自定义 可编辑
};

/** 323服务器类型 */
enum EmH323SrvType_Api
{
	emH323SrvH323Pxy_Api = 0,   ///<代理
	emH323SrvH323H460_Api = 1,  ///<H460
	emH323SrvH323Gk_Api = 2,    ///<GK
};

/** 音质优先 */
enum EmMtAudPrecedenceLevel_Api
{
	emAudPrecedenceLow_Api = 0,    	///< 低
	emAudPrecedenceMiddle_Api = 1,	///< 中
	emAudPrecedenceHigh_Api = 2,	///< 高
};

/** PPPoE拨号类型 */
enum EmPPPoEDialMode_Api
{
	emPPPoEDialManual_Api = 0,  ///<手动
	emPPPoEDialAuto_Api = 1,    ///<自动
};

/** 头像类型 */
enum EmMtPortrait_Api
{
	MT_PORTRAIT_32_Api = 0,	 ///< 32位头像
	MT_PORTRAIT_40_Api,      ///< 40位头像
	MT_PORTRAIT_64_Api,		 ///< 64位头像
	MT_PORTRAIT_128_Api,	 ///< 128位头像
	MT_PORTRAIT_256_Api,	 ///< 256位头像
};

/** 方向 */
enum EmDirection_Api
{
	emUP_Api     = 0,  ///<上
	emDown_Api   = 1,  ///<下
	emLeft_Api   = 2,  ///<左
	emRight_Api  = 3,  ///<右
};

/** 设备升级类型 */
enum EmEquipmentUpgrading_Api
{
	emEUbegin_Api  = 0,
	emEUHD120_Api  = 1,		///<摄像头Hd120
	emEUHD200_Api  = 2,	    ///<摄像头Hd200
	emEUHD120E_Api = 3,		///<摄像头Hd120E
	emEUHD200E_Api = 4,		///<摄像头Hd200E
};

/** 摄像头升级错误码 */
enum EmCameraUpgradeErrCode_Api
{
    emCUSuccess_Api,               ///< 升级成功
    emCUUpgrading_Api,          ///< 设备正在升级中
    emCUErrType_Api,               ///< 升级类型错误
    emCUNoDevice_Api,           ///< 设备不存在
    emCUNoUpgradeFile_Api,  ///< 升级文件不存在
    emCUFailure_Api,                ///< 升级失败
};

/** 以太网工作模式 */
enum EmEthnetWorkMode_Api
{
	emEthModeAuto_Api = 0,        ///<自动
	emEthMode10MFull_Api = 1,     ///<10M全双工
	emEthMode10MHalf_Api = 2,     ///<10M半双工
	emEthMode100MFull_Api = 3,    ///<100M全双工
	emEthMode100MHalf_Api = 4,    ///<100M半双工
	emEthMode1000MFull_Api = 5,   ///<1000M全双工
	emEthMode1000MHalf_Api = 6,   ///<1000M半双工	
};

/** 以太网多网口模式 */
enum EmEthInterfaceMode_Api
{
	emEthInterfaceModeBackup_Api = 0,       ///<备份
	emEthInterfaceModeMulti_Api = 1,        ///<多网口
	emEthInterfaceModeSigle_Api = 2         ///<单网口
};

/** PPPoE连接状态 */
enum EmPPPoELinkState_Api
{
	emPPPoELinkStateIdle_Api = 0,           ///<未连接
	emPPPoELinkStateConnecting_Api = 1,     ///<连接中
	emPPPoELinkStateDisConnecting_Api = 2,  ///<断开中
	emPPPoELinkStateConnected_Api = 3,      ///<已连接	
};

/** PPPoE连接失败原因 */
enum EmPPPoELinkErrReason_Api
{
	emPPPoELinkErrReason_None_Api = 0,      ///<连接成功
	emPPPoELinkErrReason_Failed_Api = 1,    ///<连接失败
	emPPPoELinkErrReason_Timeout_Api = 2,   ///<连接超时
	emPPPoELinkErrReason_Unknown_Api = 3,   ///<未知原因
};

/** WIFI工作模式 */
enum EmWifiWorkMode_Api
{
	emWifiWorkModeClose_Api = 0,      ///<关闭
	emWifiWorkModeWifiClient_Api = 1, ///<Wifi客户端接入
	emWifiWorkModeWifiAp_Api = 2,     ///<Wifi-AP服务          
};

/** WIFI加密模式 */
enum EmWifiKeyType_Api
{
	emWifiKeyTypeNone_Api = 0,         ///<未加密
	emWifiKeyTypeWPA_Api = 1,          ///<WPA-PSK
	emWifiKeyTypeWPA2_Api = 2,         ///<WPA2-PSK
	emWifiKeyTypeWPAWPA2_Api = 3,      ///<WPA-PSK or WPA2-PSK
	emWifiKeyTypeWEP_Api = 4,          ///<WEP
};

/** E1 Colck类型 */
enum EmE1ClockType_Api{
	emClockType_Dce_Api = 0, ///< DCE类型
	emClockType_Dte_Api = 1, ///< DTE类型
};

/** WIFI信号强度(4级) */
enum EmWifiSignalLevel_Api
{
	emWifiSignalLevelNone_Api = 0,      ///<无信号 0格信号
	emWifiSignalLevelLess_Api = 1,      ///<弱     1格信号
	emWifiSignalLevelLow_Api  = 2,      ///<低     2格信号
	emWifiSignalLevelMid_Api  = 3,      ///<中     3格信号
	emWifiSignalLevelHigh_Api = 4,      ///<高     4格信号
};

/** WIFI连接状态 */
enum EmWifiLinkState_Api
{
	emWifiLinkStateIdle_Api = 0,              ///<空闲中
	emWifiLinkStateAuthentication_Api = 1,    ///<认证中
	emWifiLinkStateBlocked_Api = 2,           ///<阻塞	
	emWifiLinkStateConnected_Api = 3,         ///<已连接	
	emWifiLinkStateConnecting_Api = 4,        ///<连接中
	emWifiLinkStateDisConnected_Api = 5,      ///<已断开
	emWifiLinkStateDisConnecting_Api = 6,     ///<断开中
	emWifiLinkStateFailed_Api = 7,            ///<失败
	emWifiLinkStateObtainingIpAddr_Api = 8,   ///<获取IP中
	emWifiLinkStateScanning_Api = 9,          ///<扫描中
	emWifiLinkStateSuspended_Api= 10,         ///<挂起暂停中
	emWifiLinkStateVerifyingPoorLink_Api = 11,///<
};

/** WIFI连接失败原因 */
enum EmWifiLinkErrReason_Api
{
	emWifiLinkErrReason_None_Api = 0,      ///<连接成功
	emWifiLinkErrReason_Failed_Api = 1,    ///<连接失败
	emWifiLinkErrReason_Timeout_Api = 2,   ///<连接超时
	emWifiLinkErrReason_Unknown_Api = 3,   ///<未知原因
};

/** WIFI-AP加密模式 */
enum EmWifiApKeyType_Api
{
	emWifiApKeyTypeNone_Api = 0,         ///<未加密
	emWifiApKeyTypeWPA2_Api = 1,         ///<WPA2-PSK AES
};

/** WIFI-频段类型 */
enum EmWifiFrequencyBandType_Api
{
	emWifiFrequencyBandType_24GHz_Api = 0,       //2.4GHz
	emWifiFrequencyBandType_50GHz_Api = 1,       //5.0GHz
}; 


/** MobileData信号强度(4级) */
enum EmMobileDataSignalLevel_Api
{
	emMobileDataSignalLevelNone_Api = 0,      ///<无信号 0格信号
	emMobileDataSignalLevelLess_Api = 1,      ///<弱     1格信号
	emMobileDataSignalLevelLow_Api  = 2,      ///<低     2格信号
	emMobileDataSignalLevelMid_Api  = 3,      ///<中     3格信号
	emMobileDataSignalLevelHigh_Api = 4,      ///<高     4格信号
}; 

/** MobileData移动数据连接状态 */
enum EmMobileDataLinkState_Api
{
	emMobileDataLinkStateUnUsed_Api = 0,         ///<未启用
	emMobileDataLinkStateIdle_Api = 1,           ///<未启用
	emMobileDataLinkStateConnecting_Api = 2,     ///<连接中
	emMobileDataLinkLinkStateConnected_Api = 3,  ///<已连接
	emMobileDataLinkLinkStateSuspended_Api = 4,  ///<挂起
	emMobileDataLinkStateDisConnecting_Api = 5,  ///<断开中
	emMobileDataLinkLinkStateDisConnected_Api=6, ///<已断开
	emMobileDataLinkLinkStateUnknown_Api = 7,    ///<未知
};

/** MobileData移动数据连接失败原因 */
enum EmMobileDataLinkErrReason_Api
{
	emMobileDataLinkErrReason_None_Api = 0,      ///<连接成功
	emMobileDataLinkErrReason_Failed_Api = 1,    ///<连接失败
	emMobileDataLinkErrReason_Timeout_Api = 2,   ///<连接超时
	emMobileDataLinkErrReason_Unknown_Api = 3,   ///<未知原因
};

/** 物理网络类型 */
enum EmNetAdapterWorkType_Api
{
	emNetAdapterWorkType_None_Api = 0,           ///<不可用
	emNetAdapterWorkType_Wifi_Api = 1,           ///<WIFI
	emNetAdapterWorkType_PPPoE_Api = 2,          ///<PPPOE
	emNetAdapterWorkType_MobileData_Api = 3,     ///<移动数据3G/4G
	emNetAdapterWorkType_EthnetCard1_Api= 4,     ///<以太网Lan1
	emNetAdapterWorkType_EthnetCard2_Api= 5,     ///<以太网Lan2
	emNetAdapterWorkType_E1_Api= 6,              ///<E1通讯
};

/** 移动网络类型 */
enum EmMobileDataNetType_Api
{
	emMobileDataNetType_None_Api = 0,    ///<未知
	emMobileDataNetType_CMCC_Api = 1,    ///<中国移动
	emMobileDataNetType_CUCC_Api = 2,    ///<中国联通
	emMobileDataNetType_CTCC_Api = 3,    ///<中国电信
};

/** 数据网络类型 */
enum EmMobileDataNetGenerationType_Api
{
	emMobileDataNetGenerationType_None_Api = 0,   ///<未知
	emMobileDataNetGenerationType_2G_Api = 1,     ///<2G
	emMobileDataNetGenerationType_3G_Api = 2,     ///<3G
	emMobileDataNetGenerationType_4G_Api = 3,     ///<4G
};

/** 串口设备号 */
enum EmUartNum_Api 
{
	emUartDMIC1_Api,   ///<数字麦克1
	emUartDMIC2_Api    ///<数字麦克2
};

/** 用来标识某一路视频的索引 */
enum EmChanIndex_Api
{
	emChan1st_Api,   ///<通道索引1
	emChan2nd_Api,   ///<通道索引2
	emChan3rd_Api,   ///<通道索引3
	emChan4th_Api,   ///<通道索引4
	emChan5th_Api,   ///<通道索引5
	emChan6th_Api,   ///<通道索引6
	emChan7th_Api,   ///<通道索引7
	emChan8th_Api,   ///<通道索引8
	emChan9th_Api    ///<通道索引9
};

/** 错误码--如果有extraparam, 则是json格式的字符串 */
enum EmHintCode_Api
{
	emHintBegin_Api = 0,                    ///<无效值
	emFailtoSendDual_Api              = 1,  ///<对端不支持当前格式和分辨率下的桌面共享
	emFailtoRecvDual_Api              = 2,  ///<带宽不足，不支持对端发起的桌面共享
	emFailtoVodLogin_Api              = 3,  ///<VOD 登录失败
	emDHCPTimeOut_Api                 = 4,  ///<获取DHCP地址超时
	emPPPoEAuthorError_Api            = 5,  ///<PPPOE身份验证错误
	emPPPoEAgentError_Api             = 6,  ///<PPPOE找不到ISP服务商
	emPPPoETimeOutError_Api           = 7,  ///<PPPOE拨号超时
	emPPPoELinkDownError_Api          = 8,  ///<PPPOE断链
	emPPPoEGeneralError_Api           = 9,  ///<PPPOE其他错误
	emFailtoSendDualAsReject_Api      = 10, ///<对端拒绝发起桌面共享,只有发言人可以发起桌面共享
	emCallRateNotValidForMc_Api       = 11, ///<呼叫码率过高,拒绝MC扩展
	emDualResNotMatchConfRes_Api      = 12, ///<桌面共享分辨率与会议要求(%s)不匹配

	emSuccedetoSendDual_Api           = 13, ///<发起桌面共享成功
	emSuccedetoRecvDual_Api           = 14, ///<接收桌面共享成功
	emSateMtNoP2pPermission_Api       = 15, ///<卫星终端没有点对点视频会议权限
	emH323UpLoadBitrateLessThan64Ind_Api = 16,     ///<上行码率小于等于64K
	emH323DownLoadBitrateLessThan64Ind_Api = 17,   ///<下行码率小于等于64k
	emAssVidHasNoSignal_Api = 18,          //辅视频没有信号

	/** mcu通知ter */
	emBePolledNext_Api = 30,                 ///<提示终端将被MCU轮训到
	 
	emHintNoOpenDSChnnlNonSpeaker_Api = 31,  ///<对端拒绝发起桌面共享,只有发言人可以发起桌面共享
	emHintNoOpenDSChnnlNonCap_Api     = 32,  ///<能力集限制，桌面共享失败!
	emHintNoOpenDSChnnlBRLow64_Api    = 33,  ///<码率小于64k，桌面共享失败!
	emHintNoOpenDSChnnlFECType_Api    = 34,  ///<提示终端打开双流通道因FEC类型不匹配
	emHintNoOpenDSChnnlNonMp_Api      = 35,  ///<提示终端打开双流通道因对应转发板不存在
	emHintNoOpenDSChnnlEncryptMode_Api = 36, ///<提示终端打开双流通道因加密模式不匹配
	emHintNoOpenDSChnnlOverSatDCastChnNum_Api = 37, ///<提示终端打开双流通道因超过了卫星分散会议的最大通道数

	emHintNoOpenFSChnnlNonCap_Api = 38,             ///<提示终端打开第一路视频通道因能力集限制失败
	emHintNoOpenFSChnnlBRLow64_Api = 39,            ///<提示终端打开第一路视频通道因通道码率小于64k
	emHintNoOpenFSChnnlEncrpytMode_Api = 40,        ///<提示终端打开第一路视频通道因加密模式不匹配
	emHintNoOpenFSChnnlFECType_Api = 41,            ///<提示终端打开第一路视频通道因FEC类型不匹配
	emHintNoOpenFSChnnlNonMp_Api = 42,              ///<提示终端打开第一路视频通道因对应的转发板不存在
	emHintNoOpenFSChnnlBROverflow_Api = 43,         ///<提示终端打开第一路视频通道因码率过大
	emHintNoOpenFSChnnlBothH263plus_Api = 44,       ///<提示终端打开第一路视频通道因通道类型和动态载荷均为H263
	emHintNoOpenFSChnnlFormat_Api = 45,	            ///<提示终端打开第一路视频通道因分辨率过大
	emHintNoOpenFSChnnlFPS_Api =46,                 ///<提示终端打开第一路视频通道因帧率过大
	emHintBRLessThanConf_Api = 47,                  ///<提示呼叫码率小于会议码率，请重新呼叫   { "wBitrate": 0}
	emHintBRLargerThanConf_Api = 48,                ///<提示呼叫码率大于会议码率，已自动调整
	emHintNoSupportOprForNoAuth_Api = 49,           ///<提示不支持该操作，权限不足，请联系管理员
	emHintQueueConfNoIdleServer_Api =50,            ///<提示无空闲服务，请稍等
	emHintQueueConfAllocatedServer_Api =51,         ///<提示正在接受服务
	emHintOldStackNotSupportSpecVip_Api = 52,       ///提示老平台不支持主席指定Vip
	emHintOldStackNotSupportModifyDumb_Api = 53,   ///提示老平台不支持会场哑音
	emHintOldStackNotSupportModifyConfPwd = 54,     //提示老平台不支持修改会议密码
	emHintOldStackNotSupportModifyConfNoDisturb = 55,    //提示老平台不支持设置会议免打扰
	emHintOldStackNotSupportModifyDuration = 56,      //提示老平台不支持延长会议时间
	emHintOldStackNotSupportModifyConfName = 57,      //提示老平台不支持修改会议名称
	emHintOldStackNotSupportSetAssStreamSendMod = 58,      //提示老平台不支持修改内容共享权限
	emHintAssVideoSourceIsSwitch_Api = 59,//辅视频源正在切换，不能发video双流
	emHintNoSendAssOnVodPlayStatus_Api  = 60,//点播状态的时候不允许发pc双流
	emHintNoSendAssOnEnterPwdStatus_Api = 61,//入多点会议时，正在输入入会密码时不能发pc双流
};

/** 图片格式 */
enum EmPicFormat_Api
{
	emJPEG_Api = 0, ///<JPEG
	emBMP_Api  = 1  ///<BMP
};

/** 视频输出接口定义 */
enum EmHDVideoOutPortType_Api
{
	emVOT_Invalid_Api,   ///<无效视频接口
	emVOT_DVI1_Api,      ///<dvi1
	emVOT_DVI2_Api,      ///<dvi2
	emVOT_DVI3_Api,      ///<dvi3
	emVOT_DVI4_Api,      ///<dvi4
	emVOT_HDMI1_Api,     ///<hdmi1
	emVOT_HDMI2_Api,     ///<hdmi2
	emVOT_HDMI3_Api,     ///<hdmi3
	emVOT_HDMI4_Api,     ///<hdmi4
	emVOT_YPbPr1_Api,    ///<YPbPr1
	emVOT_YPbPr2_Api,    ///<YPbPr2
	emVOT_YPbPr3_Api,    ///<YPbPr3
	emVOT_YPbPr4_Api,    ///<YPbPr4
	emVOT_VGA1_Api,      ///<vga1
	emVOT_VGA2_Api,      ///<vga2
	emVOT_VGA3_Api,      ///<vga3
	emVOT_VGA4_Api,      ///<vga4
	emVOT_SDI1_Api,      ///<sdi1
	emVOT_SDI2_Api,      ///<sdi2
	emVOT_SDI3_Api,      ///<sdi3
	emVOT_SDI4_Api,      ///<sdi4
	emVOT_C1_Api,        ///<cvbs1
	emVOT_C2_Api,        ///<cvbs2
	emVOT_C3_Api,        ///<cvbs3
};

/** 视频输出口的输入源定义*/
enum EmHDVideoSourceType_Api
{
	emVS_Invalid_Api = 0,           ///<无效视频源
	emVS_1stDec_Api = 1,            ///<第1路解码
	emVS_2ndDec_Api = 2,            ///<第2路解码
	emVS_3rdDec_Api = 3,            ///<第3路解码
	emVS_4thDec_Api = 4,            ///<第4路解码
	emVS_5thDec_Api = 5,            ///<第5路解码
	emVS_6thDec_Api = 6,            ///<第6路解码
	emVS_7thDec_Api = 7,            ///<第7路解码
	emVS_8thDec_Api = 8,            ///<第8路解码
	emVS_9thDec_Api = 9,            ///<第9路解码
	emVS_10thDec_Api = 10,          ///<第10路解码
	emVS_MtVidInnerCamera_Api = 11, ///<内置摄像头
	emVS_MtVidDVI1_Api = 12,
	emVS_MtVidDVI2_Api = 13, 
	emVS_MtVidDVI3_Api = 14, 
	emVS_MtVidDVI4_Api = 15, 
	emVS_MtVidHDMI1_Api = 16, 
	emVS_MtVidHDMI2_Api = 17, 
	emVS_MtVidHDMI3_Api = 18, 
	emVS_MtVidHDMI4_Api = 19, 
	emVS_MtVidYPbPr1_Api= 20,
	emVS_MtVidYPbPr2_Api = 21, 
	emVS_MtVidYPbPr3_Api = 22, 
	emVS_MtVidYPbPr4_Api = 23, 
	emVS_MtVidVGA1_Api = 24,
	emVS_MtVidVGA2_Api = 25, 
	emVS_MtVidVGA3_Api = 26, 
	emVS_MtVidVGA4_Api = 27, 
	emVS_MtVidC1_Api = 28,
	emVS_MtVidC2_Api = 29,
	emVS_MtVidC3_Api = 30,
	emVS_MtVidS1_Api = 31,
	emVS_MtVidS2_Api = 32,
	emVS_MtVidS3_Api = 33,
	emVS_MtVidHDBaseT1_Api = 34, 
	emVS_MtVidHDBaseT2_Api = 35, 
	emVS_MtVidHDBaseT3_Api = 36, 
	emVS_MtVidHDBaseT4_Api = 37, 
	emVS_MtVidSDI1_Api = 38,
	emVS_MtVidSDI2_Api = 39, 
	emVS_MtVidSDI3_Api = 40,
	emVS_MtVidSDI4_Api = 41,
};

/** 字体大小 */
enum EmFontSize_Api
{
	em1stSize_Api,    ///<字号1
	em2ndSize_Api,    ///<字号2
	em3rdSize_Api,    ///<字号3
	em4thSize_Api,    ///<字号4
	em5thSize_Api,    ///<字号5
};

/** 字体颜色 */
enum EmFontColor_Api
{
	emWhite_Api,  ///<白色
	emRed_Api,    ///<红色
	emOrange_Api, ///<橙色
	emYellow_Api, ///<黄色
	emGreen_Api,  ///<绿色
	emBlue_Api,   ///<蓝色
	emPurple_Api, ///<紫色
	emBlack_Api,  ///<黑色
};

/** FXO呼叫状态 */
enum EmFxoState_Api
{
	emFxoIdle_Api = 0,    ///<空闲
	emFxoCallIn_Api = 1,  ///<呼叫进来
	emFxoCalling_Api = 2, ///<呼叫中
	emFxoConnect_Api = 3  ///<连接
};

/** 图像参数类型 */
enum EmImgParam_Api
{
	emHue_Api          = 0,  ///<色度
	emWhiteBalance_Api = 1,  ///<白平衡
	emContrast_Api     = 2,  ///<对比度
	emSaturation_Api   = 3,  ///<饱和度
	emSharpness_Api    = 4,  ///<锐度
	emBright_Api       = 5,  ///<亮度
};

/** Ping错误码 */
enum EmPingErrcode_Api
{
	emPingReply_Api = 0,      ///<ping包正常回应
	emPingTimeout_Api = 1,    ///<ping包超时
	emPingError_Api = 2,      ///<ping包系统错误
	emPingNetUnreach_Api = 3, ///<ping包网络不可达 
};

/** mac ip冲突 */
enum EmNetConflictType_Api
{
	emConflictType_None_Api = 0, ///<未冲突
	emConflictType_Ip_Api   = 1, ///<ip冲突
	emConflictType_Mac_Api  = 2, ///<mac冲突
	emConflictType_Both_Api = 3  ///<ip和mac都冲突
};

/** 时区选项 */
enum EmTimeZone_Api
{
	emTimeZone_GMT_Api = 0,	 ///<格林威治标准时间 GMT
	emTimeZone_UTC_Api = 1,	 ///<全球标准时间 GMT 
	emTimeZone_ECT_Api = 2,  ///<欧洲中部时间 GMT+1:00 
	emTimeZone_EET_Api = 3,  ///<东欧时间 GMT+2:00 
	emTimeZone_ART_Api = 4,  ///<（阿拉伯）埃及标准时间 GMT+2:00
	emTimeZone_EAT_Api = 5,  ///<东非时间 GMT+3:00 
	emTimeZone_MET_Api = 6,  ///<中东时间 GMT+3:30 
	emTimeZone_NET_Api = 7,  ///<近东时间 GMT+4:00 
	emTimeZone_PLT_Api = 8,  ///<巴基斯坦拉合尔时间 GMT+5:00 
	emTimeZone_IST_Api = 9,  ///<印度标准时间 GMT+5:30 
	emTimeZone_BST_Api = 10, ///<孟加拉国标准时间 GMT+6:00 
	emTimeZone_VST_Api = 11, ///<越南标准时间 GMT+7:00 
	emTimeZone_CTT_Api = 12, ///<中国北京时间 GMT+8:00 
	emTimeZone_JST_Api = 13, ///<日本标准时间 GMT+9:00 
	emTimeZone_ACT_Api = 14, ///<澳大利亚中部时间 GMT+9:30 
	emTimeZone_AET_Api = 15, ///<澳大利亚东部时间 GMT+10:00
	emTimeZone_SST_Api = 16, ///<所罗门标准时间 GMT+11:00 
	emTimeZone_NST_Api = 17, ///<新西兰标准时间 GMT+12:00 
	emTimeZone_MIT_Api = 18, ///<中途岛时间 GMT-11:00 
	emTimeZone_HST_Api = 19, ///<夏威夷标准时间 GMT-10:00 
	emTimeZone_AST_Api = 20, ///<阿拉斯加标准时间 GMT-9:00 
	emTimeZone_PST_Api = 21, ///<太平洋标准时间 GMT-8:00 
	emTimeZone_PNT_Api = 22, ///<菲尼克斯标准时间 GMT-7:00 
	emTimeZone_MST_Api = 23, ///<西部山脉标准时间 GMT-7:00 
	emTimeZone_CST_Api = 24, ///<中部标准时间 GMT-6:00 
	emTimeZone_EST_Api = 25, ///<东部标准时间 GMT-5:00 
	emTimeZone_IET_Api = 26, ///<印第安那东部标准时间 GMT-5:00 
	emTimeZone_PRT_Api = 27, ///<波多黎各和美属维尔京群岛时间 GMT-4:00 
	emTimeZone_CNT_Api = 28, ///<加拿大纽芬兰时间 GMT-3:30 
	emTimeZone_AGT_Api = 29, ///<阿根廷标准时间 GMT-3:00 
	emTimeZone_BET_Api = 30, ///<巴西东部时间 GMT-3:00 
	emTimeZone_CAT_Api = 31  ///<中非时间 GMT-1:00
};

/** 平滑发送等级 */
enum EmMtSmoothSendLevel_Api
{
	emSmoothSendLevel_Off_Api = 0,    ///<关闭
	emSmoothSendLevel_High_Api = 1,   ///<高
	emSmoothSendLevel_Middle_Api = 2, ///<中
	emSmoothSendLevel_Low_Api = 3,    ///<低
};

/** 会议类型 */
enum EmMeetingSafeType_Api
{
	emRestMeetingType_Public_Api = 0,   ///< 传统媒体会议
	emRestMeetingType_Port_Api = 1,		///<端口会议
};

/** 视频质量 */
enum EmVideoQuality_Api
{
	emRestQualityPrecedence_Api = 0,    ///< 质量优先
	emRestSpeedPrecedence_Api = 1,      ///< 速度优先
	emRestUserCustom_Api      = 2       ///<用户自定义，用于android 移动端  

};

/** 级联模式 */
enum EmRestCascadeMode_Api
{
	emRestCascade_Simple_Api = 0,    ///< 简单级联
	emRestCascade_Merge_Api = 1,     ///< 合并级联
};

/** 参与会议反馈 */
enum EmParticipatResponse_Api
{
	emResponseNoFeedback_Api  = 0, ///<未反馈
	emResponseReject_Api      = 1, ///<拒绝入会
	emResponseParticipant_Api = 2, ///<入会
	emResponseCustom          = 3, ///<表示会议由当前用户创建
};

/** 会议免打扰 */
enum EmClosedMeeting_Api
{
	emClosedMeeting_Close_Api = 0, ///<关闭
	emClosedMeeting_Open_Api = 1,  ///<开启
};

/** 获取@、赞、粉丝等初始消息相关的消息类型 */
enum EmRestNotifyType_Api
{
	emUnknownType_Api = 0, ///<未知消息
	emNewFan_Api,          ///<新粉丝
	emNewFeed_Api,         ///<新消息 --目前NEW_FEED获取不到新消息数
	emNewRemindMe_Api,     ///<@我的消息
	emNewReply_Api,        ///<回复我的消息
	emGroupInvite_Api,     ///<群组邀请的消息
	emNewLike_Api,         ///<赞我的消息
	emNewPrivateMsg_Api,   ///<私信的消息
};

/** 码率分配策略 */
enum EmVidRationStrategy_Api
{
	EmAssVidPri_Api   = 0,  ///<辅流优先
	EmMainVidPri_Api  = 1,  ///<主流优先
	EmUserDefined_Api = 2,  ///<自定义比例
};

/** 升级状态通知 */
enum EmUpgradeNotify_Api
{
	emFileCheckBgn_Api = 1,              ///<文件检查开始
	emWholeUpgradeBgn_Api = 2,           ///<整体升级开始
	emFileCheckSuccess_Api = 11,         ///<文件校验成功
	emWholeUpgradeSuccess_Api = 12,      ///<整体升级成功
	emUnknownErr_Api = 21,               ///<未知错误
	emInvalidFileErr_Api = 22,           ///<升级包错误
	emLoadXmlFileErr_Api = 23,           ///<解析xml错误
	emFileCheckErr_Api = 24,             ///<文件校验失败
	emSysMountBakErr_Api = 25,           ///<挂载备份分区失败
	emUpgradeDriverModuleErr_Api = 26,   ///<驱动模块升级失败
	emUpgradeAppModuleErr_Api = 27,      ///<应用模块升级失败
	emUpgradeExeModuleErr_Api = 28,      ///<可执行模块升级失败
};

/** 文件类型 */
enum EmSystemFileType_Api
{
	emFileNormal_Api,       ///<普通文件
	emFileDirectory_Api,    ///<目录文件
	emFileLink_Api,         ///<链接文件
	emFilePipe_Api,         ///<管道
};

/** 升级类型 */
enum EmUpgradeType_Api
{
	emSusUpgrade_Api = 1,   ///<远端升级
	emLocalUpgrade_Api,     ///<本地升级
	emMtcUpgrade_Api,       ///<使用Mtc升级
};

/** 待机失败原因 */
enum EmSleepFailReason_Api
{
	emSFRNoError_Api = 0,    ///<没有失败，允许待机
	emSFRProtectionTime_Api, ///<30秒待机保护时间
	emSFRMonitor_Api,        ///<监控时不允许待机
	emSFRInConf_Api,         ///<会议中不允许待机
	emSFRLoop_Api,           ///<自环时不允许待机
	emSFRRibbonTest_Api,      ///<色带测试不允许待机
    emSFRSnapView_Api, ///< 快照浏览
    emSFRVrs_Api, ///< VRS
    emSFRUpgrade_Api, ///< 升级
    emSFRSusUpgrade_Api, ///< SUS升级
    emSFRNetCap_Api, ///< 抓包
    emSFRAddrbook_Api, ///< 地址簿导入或导出
    emSFRSnapExport_Api, ///< 快照导出
	emSFRCameraUpgrade_Api, //摄像机升级
	emSFRMicPhoneUpgrade_Api, //麦克风升级
	emSFRMtRecorde_Api,     //本地录像
	emSFRMtAssStream_Api    //skyshare双流
};

/** 解码后处理策略 */
enum EmResizeMode_Api
{
	emBlackEdge_Api = 0,    ///<加黑边
	emCutEdge_Api,          ///<裁边
	emNoProportionally_Api, ///<非等比
};

/** 本地声音类型 */
enum EmLocalSoundType_Api
{
	emLSRing_Api  = 0,	    ///<铃声
	emLSKeyTone_Api,		///<按键音
	emLSSpecialEffects_Api,	///<音效
};

/** 本地音效索引 */
enum EmLocalSoundIndex_Api
{
	emSound1st_Api = 0,    ///<索引1
	emSound2nd_Api,        ///<索引2
	emSound3rd_Api,        ///<索引3
	emSound4th_Api,        ///<索引4
	emSound5th_Api,        ///<索引5
	emSound6th_Api,        ///<索引6
	emSound7th_Api,        ///<索引7
	emSound8th_Api,        ///<索引8
	emSound9th_Api,        ///<索引9
};

/** 文件拷贝错误码 */
enum EmFileCopyErr_Api
{
	emCopySuccess_Api           = 0,     ///<成功
	emCopyUnknownErr_Api        = 1,     ///<未知错误
	emCopyNoSpace_Api           = 2,     ///<空间不足
	emCopySrcFileNotFound_Api   = 3,     ///<源文件不存在
	emCopyDstPathNotFound_Api   = 4,     ///<目标路径不存在
    emCopyStop_Api = 5,                             ///< 停止拷贝
};

/**  数字麦ID*/
enum EmMicDevId_Api
{
	emWiredMic0_Api = 0, ///< 有线麦0
	emWiredMic1_Api,       ///< 有线麦1
	emWirelessMic0_Api,   ///< 无线麦0
	emWirelessMic1_Api,   ///< 无线麦1
	emWirelessMic2_Api,   ///< 无线麦2
	emWiredMic0Cascade1_Api, ///< 有线麦0级联1
	emWiredMic0Cascade2_Api, ///< 有线麦0级联2
	emWiredMic1Cascade1_Api, ///< 有线麦1级联1
	emWiredMic1Cascade2_Api, ///< 有线麦1级联2
	emMicDevIdEnd_Api,
};

/** 遥控器按键值*/
enum EmRemoteScanCode_Api
{
    emScanCode0_Api = 0,          ///< 数字0
	emScanCode1_Api,                ///< 数字1
	emScanCode2_Api,                ///< 数字2
	emScanCode3_Api,                ///< 数字3
	emScanCode4_Api,                ///< 数字4
	emScanCode5_Api,                ///< 数字5
	emScanCode6_Api,                ///< 数字6
	emScanCode7_Api,                ///< 数字7
	emScanCode8_Api,                ///< 数字8
	emScanCode9_Api,                ///< 数字9
	emScanCodePoint_Api,          ///< .
	emScanCodeSharp_Api,         ///< #
	emScanCodeMenu_Api,         ///< 菜单
	emScanCodeBackspace_Api,  ///< 删除
	emScanCodeEnter_Api,          ///< 确定
	emScanCodeUp_Api,             ///< 上
	emScanCodeDown_Api,        ///< 下
	emScanCodeLeft_Api,           ///< 左
	emScanCodeRight_Api,         ///< 右
	emScanCodePower_Api,       ///< 电源
	emScanCodeMainVSrc_Api,  ///< 主视频源
	emScanCodeAV_Api,            ///< AV
	emScanCodeFarCtrl_Api,      ///< 远遥
	emScanCodeMute_Api,        ///< 哑音
	emScanCodeQuiet_Api,        ///< 静音
	emScanCodeVGA_Api,         ///< VGA
	emScanCodeS_Api,              ///< S端子
	emScanCodeShotSnap_Api,       ///< 快照
	emScanCodeVolumeUp_Api,     ///< 音量+
	emScanCodeVolumeDown_Api, ///< 音量-
	emScanCodeConnect_Api,         ///< 拨号
	emScanCodeDisconnect_Api,     ///< 挂断
	emScanCodeDirectory_Api,        ///< 地址簿
	emScanCodePipEnable_Api,       ///< 画中画
	emScanCodePipAdjust_Api,        ///< 画中画缩放
	emScanCodeSelfTest_Api,          ///< 自检
	emScanCodeAutoFocus_Api,      ///< 自动调焦
	emScanCodeNearZoom_Api,      ///< 近视
	emScanCodeFarZoom_Api,         ///< 远视
	emScanCodePreSave_Api,          ///< 保存预置位
	emScanCodePreMove_Api,        ///< 加载预置位
	emScanCodeChairReq_Api,        ///< 申请主席
	emScanCodeSpeakReq_Api,       ///< 申请发言
	emScanCodeQuitReq_Api,          ///< 退会
	emScanCodeState_Api,               ///< 状态
	emScanCodeHotLeft_Api,            ///< 快捷键1
	emScanCodeHotCenter_Api,       ///< 快捷键2
	emScanCodeHotRight_Api,         ///< 快捷键3
	emScanCodeHelp_Api,                ///< 帮助
	emScanCodeBrightUp_Api,         ///< 亮度+
	emScanCodeBrightDown_Api,    ///< 亮度-
	emScanCodeDual_Api,               ///< 双流
	emScanCodeReturn_Api,            ///< 返回
	emScanCodeFunc_Api,              ///< 功能
	emScanCodeSearch_Api,           ///< 搜索
	emScanCodeImixMenu_Api,			///< 用于网呈，在会议空闲时可以直接返回OSD主界面
	emScanCodeNull_Api = 98,       ///< 无键值
	emScanCodeInvalid_Api,           ///< 无效键值
};

/** OSD穿透请求结果*/
enum EmOsdTransparentResult_Api
{
	emSuccess_Api, ///< 请求成功
	emFailed_Api,   ///< 请求失败
	emReserved_Api, ///< 预留用
};

/** 设置采集到编码缩放策略 */
enum enZoomMode_Api
{
	EN_ZOOM_FILLBLACK_Api = 0,	///<加黑边
	EN_ZOOM_CUT_Api,	///<裁边
	EN_ZOOM_SCALE_Api	///<不等比拉伸
};

/** 开始或停止抓包返回的错误码 */
enum EmNetCapErrcode_Api
{
    ERR_MTDEVICE_OPERATE_SUCCESS_Api,        ///< 操作成功
    ERR_MTDEVICE_NETCAPTURE_STOP_Api,       ///< 抓包停止
    ERR_MTDEVICE_FILE_EXPORT_FAILED_Api,     ///< 导出文件失败
    ERR_MTDEVICE_DISK_OUTOF_SPACE_Api,     ///< 磁盘空间不足
    ERR_MTDEVICE_FILE_NOT_EXIST_Api,            ///< 文件不存在
    ERR_MTDEVICE_PATH_NOT_EXIST_Api,         ///< 路径不存在
    ERR_MTDEVICE_PROCESS_IS_RUNNING_Api,  ///< 正在运行
};

/** ping操作的时候，用于标识调用者的UID*/
enum EmPingUserId_Api
{
    emPingUidLan_Api,         ///< 局域网可连接测试
    emPingUidInternet_Api,  ///< 互联网可连接测试
    emPingUidDns_Api,        ///< 服务器DNS解析测试
    emPingUidServer_Api,    ///< 当前选择的服务器可连接测试
    emPingUid4_Api,            ///< 保留，使用时添加注释
    emPingUid5_Api,            ///< 保留，使用时添加注释
    emPingUid6_Api,            ///< 保留，使用时添加注释
    emPingUid7_Api,            ///< 保留，使用时添加注释
    emPingUid8_Api,            ///< 保留，使用时添加注释
};

/** 麦克风更新状态*/
enum EmMicUpgradeState_Api
{
    emUploadEnable_Api,         ///< 可上传
    emUploading_Api,              ///< 上传中
    emInstallable_Api,              ///< 可安装
    emInstalling_Api,                ///< 安装中
    emUpgradeSuccess_Api,   ///< 安装成功
    emLatestVersion_Api,        ///< 最新版本
    emReserve1_Api,               ///< 保留
    emReserve2_Api,              ///< 保留
};

/**  登录APS结果错误码*/
enum EmLoginAPSErrorId_Api
{
    emLoginAPS_Success,                                         ///< 登录成功
    emLoginAPS_CONNECT_FAILED = 21000,         ///< 连接失败
    emLoginAPS_LOGIN_PARAM_ERROR = 22000, ///< 登录参数错误
    emLoginAPS_ACCOUNT_NAME_NOTEXIST,      ///< 用户不存在
    emLoginAPS_ACCOUNT_PWD_ERROR,              ///< 用户密码错误
    emLoginAPS_DEVTYPE_RESTRICT,                      ///< 设备类型限制
    emLoginAPS_NOTEXIST,                                     ///< 记录不存在
    emLoginAPS_ASSIGN_SRV_ERROR,                    ///< 分配服务器错误
    emLoginAPS_NO_ROAM_PRIVILEGE,                  ///< 没有漫游权限
    emLoginAPS_ACCOUNT_OR_PWD_ERROR,               ///<用户名或密码错误
    emLoginAPS_SERVER_INSIDE_ERR = 23001,      ///< 服务器内部错误
    emLoginAPS_DB_EXEC_FAIL,                               ///< 数据库执行失败
	emLoginAPS_CHANGE_APS_FAIL,                               ///< 新版本切换所有服务器
	emLoginAPS_CHANGE_GK,                               ///< 老版本aps只要切换gk
};

/////创会录像发布 //0-不发布 1-立即发布，新录播直播标志 2.-录像完毕之后发布，新录播发布标志 3-直播+发布
enum EmRecordPubMode_Api
{
	emNotPublic_Api = 0,     // 0-不发布 
	emPublicNow_Api = 1,     // 1-立即发布，新录播直播标志
	emPublicRecEnd_Api = 2,  // 2.-录像完毕之后发布，新录播发布标志
	emPublicLive_Api = 3,    // 3-直播+发布

};

/////录像机别名类型 0-初始值， 1-IP, 2-E164 平台依据类型获取对应的别名信息
enum EmVrsAliasType_Api
{
	emVrsAliasBegin_Api = 0,    ///<初始值
	emVrsAliasIP_Api = 1,      ///<IP地址   
	emVrsAliasE164_Api = 2,     ///<E164号

};

/**  批量发送IM消息对应的消息类型*/
enum EmImBatchMsgType_Api
{
    emImBatchMsgTypeMulitChatAddMember_Api,                   ///< Ev_MtApi_ImMulitChatAddMember_Ntf
    emImBatchMsgTypeMulitChatMemberStatusChange_Api,    ///< Ev_MtApi_ImMulitChatMemberStatusChange_Ntf
    emImBatchMsgTypeMulitChatMemberLeave_Api,                ///< Ev_MtApi_ImMulitChatMemberLeave_Ntf
    emImBatchMsgTypeMulitChatDelMember_Api,                    ///< Ev_MtApi_ImMulitChatDelMember_Ntf
    emImBatchMsgTypeChatroomRosterItemsAdd_Api,             ///< Ev_MtApi_ImChatroomRosterItemsAdd_Ntf
    emImBatchMsgTypeChatroomRosterItemsDel_Api,              ///< Ev_MtApi_ImChatroomRosterItemsDel_Ntf
    emImBatchMsgTypeChatroomMemberAdd_Api,                  ///< Ev_MtApi_ImChatroomMemberAdd_Ntf
};

/** 摄像机控制当前画面 */
enum EmCameraView_Api
{
    emRestoreCameraView_Api,
    em1stCameraView_Api,
    em2ndCameraView_Api,
    emCameraMultiView_Api,
};


////相关VRS接口的一系列错误码
enum EmVodErrReason_Api
{
	emNoErr_Api = 0,
	//错误原因 预留一定数量给同一类操作l
	//////////////登陆错误码///////////////////////
	emUnknown_Api       = 1, // 未知错误
	emSQLError_Api      = 2, // SQL执行错误
	emPswErr_Api        = 5, // 密码错误
	emUserNoExis_Api    = 6, // 用户名不存在
	emUserExis_Api      = 7, // 用户已存在
	emInError_Api       = 8, // 输入有误
	emNoPermission_Api  = 9, // 没有权限
	emUserInvalid_Api   = 10, // 用户失效
	emNameEmpty_Api     = 15, // 命名为空
	emUserGExis_Api     = 16,  // 用户组存在
	emNoResult_Api      = 17, // 值为空
	emUserMax_Api       = 18, // 用户超过最大个数
	emUserDomainMax_Api = 19, // 用户域超过最大个数
	emFolderExis_Api    = 30, // 文件夹已经存在
	emFolderMax_Api     = 31, // 文件夹超过最大个数
	emProgramNoExis_Api = 32, // 节目不存在
	emProgramExis_Api  = 33, // 节目存在
	emPrgRelease_Api   = 34, // 节目已经发布
	emSeializeFail_Api = 40, // 序列化失败
	emParseFail_Api    = 41, //解析失败
	emTooLarge_Api     = 42, //值超过最大限制
	emResTimeErr_Api   = 43,   //预约时间错误（预约时间早于系统时间）
	emResRoomMax_Api   = 44,   // 超出预约直播室的最大数
	emSystemResponseTimeOut_Api = 45,   // 系统响应超时
	emUserNameOrPwdInvalid_Api  = 46,    //用户名或密码错误
	emConnectSsoFail_Api     = 47,  //连接sso失败
	emTokenInvalid_Api       = 48,    //token失效
	emNoLoginVrsRight_Api    = 49, //无VRS登录权限
	emSysDebugErr_Api        = 50,//系统调试脚本执行错误

	//////////////////////////////////////
	emReadASFErr_Api       =101,	//读取Asf错误
	emSysCfgExpShErr_Api   =120,    //执行导出syscfg shell错误
	emSysCfgImpShErr_Api   =121,    //执行导入syscfg shell错误
	emKDVLogExpShErr_Api   =122,    //执行导出KdvLog shell错误
	emUpgradeAppShErr_Api  =123,    //执行升级bin shell错误

	emBeyondMaxResRoomErr_Api=200,  //超出预约直播室的限制

	emMaxRecRoom_Api  = 250,        //录像室超过最大个数,数据库端上报
	emMaxPlayRoom_Api = 260,        //放像室超过最大个数，数据库端上报

	/////////录放像机错误返回////////////////////////////////////////
	emRPResNotEnough_Api	= 24102,	//录像资源不足，录像开启失败！
	emFileNameInvalid_Api	= 24103,	//录像文件名中存在非法字符：% & * ^ ~ '" ?  / \ < > | ` ，请重新输入
	emInteriorError_Api		= 24104,		//录播服务器发生故障，无法录放像！
	emFileExist_Api			= 24105,	//文件名已经存在，请重新输入
	emFileNotExist_Api		= 24106,	//您点播的文件不存在，请重新选择
	emCapSetNotEnough_Api	= 24107,	//文件信息与对端能力比匹配，无法放像---》您点播的文件与会议不匹配，请重新选择!

	//////录放像室操作//////////////////////////////////////////////
	emRPRoomExist_Api		 = 24202,	//录放像室别名或者号码已经存在
	emRPRoomNotExist_Api	 = 24203,	//录放像室别名或者号码不存在
	emRPRoomIsFull_Api		 = 24204,	//录放像室已经满了
	emRPNotEnoughLiveRes_Api = 24205,	//直播资源不足
	emRPStateError_Api		 = 24206,	//状态错误

	//////直播室操作////////////////////////////////////////////////
	emRPBrdNotExist_Api		 = 24302,	//直播不存在
	emRPBrdExist_Api		 = 24303,	//直播已经存在
	emRPCreateBrdFailed_Api  = 24304,	//创建直播失败
	emRPLiveNotStarted_Api   = 24305,   //直播还未开始
	emRPLiveIsEnd_Api        = 24306,   //直播已结束

	///文件上传操作////////////////////////////////////////////////
	emUploadParmErr_Api         = 24402,	//上传参数解析失败
	emUploadFileNameErr_Api     = 24403,	//上传文件名错误
	emWriteFileToLocalFail_Api  = 24404,	//写上传文件到本地失败
	emUploadFileAttributeErr_Api= 24405,	//上传的文件格式错误
}; 

//// 登陆VRS后返回的用户权限
enum EmVodRightMask_Api
{
	emNoRight_Api = 0,             ////没有任何权限(一般是由于登陆失败后返回)
	emDownLoad_Api = 1,       ////下载权限
	emLiveVideo_Api = 2,           ////直播权限
	emDownAndLive_Api = 3,         ////下载+直播权限
	emPlayVideo_Api = 4,          ////视频点播权限
	emDownAndPlay_Api = 5,        ////下载+点播权限
	emLiveAndPlay_Api = 6,        ////直播+点播权限
	emDownAndLiveAndPlay_Api = 7, ////下载+直播+点播权限

};


//// VRS获取一些列表超时消息返回
enum EmVodGetListTimeOut_Api
{
	emBegin_Api = 0,                         ////没有任何权限(一般是由于登陆失败后返回)
	///emLoginTimeOut_Api = 1,               ////登录vrs超时
	emGetRoomTimeOut_Api = 2,                ////获取直播室超时
	emGetGetReserveRoomTimeOut_Api = 3,      ////获取预约直播室超时
    em_VRS_GetPrgsInfo_TimeOut_Api = 4,      ////获取文件列表超时
	////todo
};

//// 设备厂商标识信息, 和mtconst.h用u32定义的厂商标识一一对应
enum EmVendorId_Api
{
	emMicrosoftNetmeeting_Api	= 1,
	emKeda_Api					= 2,
	emHuaWei_Api				= 3,
	emPolycom_Api				= 4,
	emPolycomMCU_Api			= 5,
	emTandberg_Api				= 6,
	emRadvision_Api				= 7,
	emVcon_Api					= 8,
	emSony_Api					= 9,
	emVtel_Api					= 10,
	emZTE_Api					= 11,  //中兴
	emZTEMCU_Api				= 12,
	emCodian_Api				= 13,
	emAETHRA_Api				= 14,
	emCHAORAN_Api				= 15,  //超然
	emAVCON_Api					= 16,  //华平
	emDonJin_Api				= 17,  //东进GW
	emCisco_Api                 = 18,
	emSmartPhone_Api            = 19,
	emUNKNOWN_Api				= 50
};

//通用等级值
enum EmGeneralLevel_Api
{
	emGeneralLevel0_Api = 0,   // 低	慢
	emGeneralLevel1_Api = 1,   // 中	中
	emGeneralLevel2_Api = 2,   // 高	快
};

//感光度模式
enum EmISO_Api
{
	emISOAuto_Api = 0,
	emISO80_Api   = 1,
	emISO100_Api  = 2,
	emISO200_Api  = 3,
	emISO400_Api  = 4,
	emISO800_Api  = 5,
	emISO1250_Api = 6,
};

//曝光模式
enum EmExposureMode_Api
{
	emExMManual_Api      = 0,   //手动
	emExMAuto_Api        = 1,   //自动
	emExMAperturePri_Api = 2,   //光圈优先
	emExMShutterPri_Api  = 3,   //快门优先
	emExLowLight_Api     = 4,	//低照
	emExHDR_Api			 = 5	//HDR
};

//光圈大小
enum EmAperture_Api
{
	emF1p2_Api = 0,       //F1.2
	emF1p6_Api = 1,       //F1.6
	emF1p8_Api = 2,       //F1.8
	emF2p0_Api = 3,       //F2.0
	emF2p8_Api = 4,       //F2.8
	emF4p0_Api = 5,       //F4.0
	emF5p6_Api = 6,       //F5.6
	emF8p0_Api = 7,       //F8.0
	emF11_Api  = 8,       //F11
};

//快门类型模式
enum EmShutterType_Api
{
	emShutterTypeManual_Api = 0,    // 手动
	emShutterTypeAuto_api   = 1,    // 自动
};

//快门类型模式等级值
enum EmShutterLevel_Api
{
	emShutter8_Api     = 0,     //1/8
	emShutter15_Api    = 1,     //1/15
	emShutter30_Api    = 2,     //1/30
	emShutter60_Api    = 3,     //1/60
	emShutter100_Api   = 4,     //1/100
	emShutter125_Api   = 5,     //1/125
	emShutter250_Api   = 6,     //1/250
	emShutter500_Api   = 7,     //1/500
	emShutter1000_Api  = 8,     //1/1000
	emShutter2000_Api  = 9,     //1/2000
	emShutter4000_Api  = 10,    //1/4000
};

//白平衡模式
enum EmWBAMode_Api
{
	emWBAAuto_Api         = 0,   //自动    自动
	emWBADay_Api          = 1,   //白天    室内
	emWBACloudy_Api       = 2,   //多云    户外
	emWBAShade_Api        = 3,   //阴天    钠灯
	emWBAFluorescent_Api  = 4,   //荧光灯  无
	emWBATUngsten_Api     = 5,   //白炽灯  无
	emWBAWarmLight_Api    = 6,   //暖光灯 
	emWBAStandLight_Api   = 7,   //标准灯
	emWBANaturalLight_Api = 8,   //自然灯
	emWBASunLight_Api     = 9,   //日光灯
	emWBAManual_Api       = 10   //手动
};

//场景模式
enum EmSceneMode_Api
{
	emSceneOff_Api   = 0,   //关闭
	emSceneNight_Api = 1,   //夜间
	emSceneAuto_Api  = 2,   //自动
	emSceneWDR_Api   = 3,   //宽动态
	emSceneHCT_Api   = 4,   //高色温
};

// 降噪类型模式
enum EmNFType_Api
{
	emNFType_2D_Api = 0,    // 2D降噪
	emNFType_3D_Api = 1,    // 3D降噪
};

//降噪模式级别值
enum EmNFMode_Api
{
	emNF_Off_Api   = 0,     //关闭
	emNF_Low_Api   = 1,     //低
	emNF_Mid_Api   = 2,     //中
	emNF_High_Api  = 3,     //高
};

enum EmBrightnessDirection_Api
{
	emBrightnessUp_Api   = 0,
	emBrightnessDown_Api = 1,
};

//Isp图像参数
enum EmIspImgInf_Api
{
	IspImgInf_Noise_Api         = 0,  // 降噪(EmNFMode_Api)
	IspImgInf_Sharpness_Api     = 1,  // 锐度(EmGeneralLevel_Api)
	IspImgInf_ISO_Api           = 2,  // 感光度(EmISO_Api)
	IspImgInf_ExposureMode_Api  = 3,  // 曝光模式(EmExposureMode_Api)
	IspImgInf_Aperture_Api      = 4,  // 光圈大小(EmAperture_Api)
	IspImgInf_Shutter_Api       = 5,  // 快门速度(EmShutterLevel_Api)
	IspImgInf_Brightnesss_Api   = 6,  // 亮度调节(emFeccBrightnessUp_Api/emFeccBrightnessDown_Api)
	IspImgInf_WhiteBalance_Api  = 7,  // 白平衡(EmWBAMode_Api)
	IspImgInf_Noise_2D_Api	        = 8,  // 2D降噪(EmNFMode)
	IspImgInf_Noise_3D_Api	        = 9,  // 3D降噪(EmNFMode)
	IspImgInf_BrightnesssValue_Api	= 10, // 亮度数值，与亮度调节不同
	IspImgInf_Contrast_Api			= 11, // 对比度
	IspImgInf_Saturation_Api		= 12, // 饱和度
	IspImgInf_Sharpness_Value_Api   = 13, // 锐度数值
	IspImgInf_Hue_Api               = 14, // 色度
	IspImgInf_BackLight_Type_Api    = 15, // 背光补偿类别 0为关 1为背光补偿 2为强光抑制
	IspImgInf_BackLight_Value_Api   = 16,  // 背光补偿数值
	IspImgInf_RedGain_Api			= 17,  // 红增益 与白平衡联动
	IspImgInf_BlueGain_Api			= 18,  // 蓝增益 与白平衡联动
	IspImgInf_AotoExposureGain_Api   = 19, // 自动曝光模式增益与曝光模式联动
	IspImgInf_ManualExposureGain_Api = 20, // 手动曝光模式增益与曝光模式联动
	IspImgInf_ImgGamma_Api			 = 21, // 图像增强 
	IspImgInf_ImgDefog_Api			 = 22, // 数字去雾
	IspImgInf_DigDynSwitch_Api		 = 23, // 数字宽动态开关
	IspImgInf_DigDynLevel_Api		 = 24  // 数字宽动态等级
};

//// 文件导出/导入的错误码
enum EmFileExImErr_Api
{
	emExImSuccess_Api       = 0,     ///<成功
	emExImUnknownErr_Api    = 1,     ///<未知错误
	emSrcFileNotFound_Api	= 2,     ///<源文件不存在
	emDstPathNotFound_Api	= 3,     ///<目标路径不存在
	emFileNotMtModel_Api	= 4		 ///<待导入的文件不是终端对应的型号
};

enum EmVidDecTypeMode_Api
{
	emVideoSoftDec_Api     = 1,    //软解
	emVideoHardDec_Api     = 2,    //硬解 
	emVideoError_Api       = 3
};

//////商密 SIP连接类型
enum EmSipConnectType_Api
{
	emSipUdpConnect_Api	= 0,
	emSipTcpConnect_Api = 1,
	emSipTlsConnect_Api = 2,
	emSipGMTlsConnect_Api = 3
};


enum EmVmpMode_Api
{
    emScreenVmp_Api       = 0,  //
    emCustomScreenVmp_Api = 1,  ///<定制画面合成
    emAutoScreenVmp_Api   = 2   ///<自动画面合成
};

enum EmPollMode_Api
{
    emPollModeBegin_Api = 0,
    emVideoPoll_Api     = 1,  ///<视频轮询
    emReserveTwo_Api    = 2,  ///<如果平台发布对应2值，此项可以被替换
    emAudioPoll_Api     = 3   ///<音视频轮询
};

// 遥控器按键状态
enum EmKeyState_Api
{
	emKeyUp_Api             = 0, ///<按键松开
	emKeyDown_Api           = 1, ///<按键压下
	emKeyLongPressed_Api    = 2  ///<按键长压
};

//硬终端本地录像过程中的状态
enum EmVideoRecordErrorNum_Api 
{
	emErrorNoError_Api				= 0,  // 没有错误，正确返回
	emErrorFileNotFound_Api			= 1,  // 文件没有找到
	emErrorInvalidASFFile_Api		= 2,  // 无效的ASF文件
	emErrorObjectNotFound_Api		= 3,  // 对象没有找到
	emErrorBadIndex_Api				= 4,  // 错误的对象索引
	emErrorValueNotFound_Api		= 5,  // 没有找到相应的值
	emErrorBadArgument_Api			= 6,  // 错误的参数
	emErrorReadOnly_Api				= 7,  // 文件只读错误
	emErrorNotEnoughSpace_Api		= 8,  // 存储空间不足错误
	emErrorInternalError_Api		= 9,  // 无法申请内存的内部错误
	emErrorReadFileError_Api		= 10, // 读文件内部错误
	emErrorWriteFileError_Api		= 11, // 写文件内部错误
	emErrorSeekFileError_Api		= 12, // 查找文件错误
	emErrorCreateFileError_Api		= 13, // 创建文件错误
	emErrorCreateThreadError_Api	= 14,	
	emErrorObjectNULLError_Api		= 15, // 参数指针为空的错误
	emErrorTooMuchVideoStrream_Api	= 16,
	emErrorNotSupportedCodec_Api	= 17,
	emErrorFileEnd_Api				= 18,
	emErrorUnknownError_Api			= 19, // 无法确定的错误	
	emErrorWriteMemError_Api		= 20, // 写内存错误
	emErrorFileNameEmpty_Api		= 21, // 文件名为空
	emErrorNotDir_Api				= 22, // 路径中的目录存在但却非真正的目录
	emErrorLoop_Api					= 23, // 欲打开的文件有过多符号连接问题，上限为16符号连接
	emErrorAccess_Api				= 24, // 存取文件时被拒绝
	emErrorNameTooLong_Api		    = 25  // 参数file_name的路径名称太长
};

//无线投屏状态
enum EmWirelessScreenState_Api
{
	emWirelessScreen_enabled_Api       = 0,		//启用
	emWirelessScreen_disabled_Api      = 1		//未启用
};

//无线投屏失败原因 */
enum EmWirelessScreenErrReason_Api
{
	emWirelessScreenErrReason_None_Api 	  = 0,      //成功
	emWirelessScreenErrReason_Failed_Api  = 1,      //失败
	emWirelessScreenErrReason_Timeout_Api = 2,   	//超时
	emWirelessScreenErrReason_Unknown_Api = 3      //其他未知原因
};

//本地录像的几种状态
enum EmVideoRecordStatus_Api 
{
	emVideoRecordIdle_Api		= 0,	//空闲	
	emVideoRecordRecording_Api	= 1,	//正在录像
	emVideoRecordPause_Api		= 2		//暂停录像
};

enum EmTerControlCameraOsdType_Api 
{
	emCameraOsdMenu_Api = 0,
	emCameraOsdOk_Api = 1,
	emCameraOsdReture_Api = 2
};


/////商密相关
enum EmSecCertFormat_Api
{
	emSecCertFormartNULL_Api = 0,
	emSecCertFormartPEM_Api  = 1,
	emSecCertFormartDER_Api  = 2,
	emSecCertFormartPFX_Api  = 3,
	emSecCertFormartB64_Api  = 4
};

//录像类型 
enum EmRecordType_Api
{
    emStartRecordType_Api   = 0,
    emConferenceRecord_Api  = 1, ///会议录像
    emTerminalRecord_Api    = 2  ///终端录像
};

//发布模式
enum EmPublishMode_Api
{
    emNotPublishMode_Api  = 0, ///不发布
    emPublishMode_Api     = 1  ///发布
};

///录像模式
enum EmRecordMode_Api 
{
    emDisableRecordMode_Api = 0,  ///不开启录像或直播
    emRecordMode_Api       = 1,  ///录像
    emLiveMode_Api         = 2,  ///直播
    emRecordLiveMode_Api   = 3   ///录像+直播
};

//呼叫模式
enum EmCallMode_Api
{
    emMannualCall_Api    = 0, //手动呼叫
    emAutoCall_Api       = 1, //自动呼叫
    emTimingCall_Api     = 2, //定时呼叫
    emChasingCall_Api    = 3  //追呼
};

//录像状态信息
enum EmRecordState_Api
{
    emDoNotRecord_Api       = 0, //未录像
    emRecording_Api         = 1, //正在录像
    emSuspendRecord_Api     = 2, //暂停
    emCallingMT_Api         = 3, //正在呼叫实体
    emPrepareRecord_Api     = 4  //准备录像
};

//录像操作指令
enum EmRecordCmd_Api
{
    emRecordCmdBak_Api   = 0, //备用参数
    emPauseRecord_Api    = 1, //暂停录像
    emContinueRecord_Api = 2  //继续录像
};

//设置限定ip类型
enum EmLimitIpType_Api
{
	emLimitIpTypeWhite_Api  = 0,	//白名单
	emLimitIpTypeBlack_Api  = 1,	//黑名单
	emLimitIpTypeReset_Api  = 2		//重置
};

enum EmDigestType_Api
{
	emSm3_Api = 0,
	emMd5_Api = 1
};

///公钥私钥算法
enum EmPubPriType_Api
{
	emRsa_Api = 1,
	emSm2_Api = 2
};

//SRTP秘钥类型(数据加密类型)
enum EmSrtpCryptoType_Api 
{
	emSrtpCryptoNone_Api	     = 0,   //不加密
	emSrtpCryptoAES_CM_128_Api   = 1,
	emSrtpCryptoAES_CM_192_Api   = 2, 
	emSrtpCryptoAES_CM_256_Api   = 3,
	emSrtpCryptoAES_GCM_128_Api  = 4,
	emSrtpCryptoAES_GCM_192_Api  = 5,
	emSrtpCryptoAES_GCM_256_Api  = 6,   
	emSrtpCryptoSM4_CM_128_Api   = 7,  //SM目前只有128的  
	emSrtpCryptoSM1_CM_128_Api   = 8
};

enum EmSrtpAuthType_Api
{
	emSrtpAuthNone_Api   = 0,     //不认证
	emSrtpAuthTag_8_Api  = 1,
	emSrtpAuthTag_16_Api = 2,
	emSrtpAuthTag_32_Api = 3,
	emSrtpAuthTag_80_Api = 4,
};


//商密证书类型
enum EmSecCertType_Api
{
	emCaT_Api = 0,        ///< CA证书
	emTlsT_Api,           ///< 标准TLS证书
	emTlsWithKeyT_Api,    ///< 带私钥key的TLS证书
	emEncT_Api,           ///< 国密加密证书
	emEncWithkeyT_Api,    ///< 带私钥key的国密加密证书
	emSignT_Api,           ///< 国密签名证书
	emEncPfxT_Api,         ///< pfx格式国密加密证书  由以前的带私钥key的国密加密证书划分为 证书  和  密钥对 两步导入
	emKeyPair_Api          ///< 密钥对文件 
};




//////////////////////////////////////////////////////////////////////////
// 以下是电子白板枚举

enum EmDcsOper_Api
{
	emWbLineOperInfo_Api = 0, 	// TDCSAdpWbLineOperInfo
	emWbCircleOperInfo_Api, 	// TDCSAdpWbCircleOperInfo
	emWbRectangleOperInfo_Api, 
	emWbPencilOperInfo_Api, 	// TDCSAdpWbPencilOperInfo
	emWbColorPenOperInfo_Api, 	// TDCSAdpWbColorPenOperInfo
	emWbImageOperInfo_Api, 	// TDCSAdpWbImageOperInfo
	emWbAddSubPageInfo_Api, 	// TDCSAdpWbAddSubPageInfo
	emWbEraseOperInfo_Api, 	// TDCSAdpWbEraseOperInfo
	emWbZoomInfo_Api, 			// TDCSAdpWbZoomInfo
	emWbUndo_Api,
	emWbRedo_Api,
	emWbRotateLeft_Api,
	emWbRotateRight_Api,
	emWbClearScreen_Api,
	emWbScrollScreen_Api,
	emWbFullScreen_Api,
	emWb100ProportionScreen_Api,
	emWbReginErase_Api,
	emWbInsertPic_Api,
	emWbPitchPicZoom_Api,
	emWbPitchPicRotate_Api,
	emWbPitchPicDrag_Api,
	emWbPitchPicDel_Api,

};


enum EmDcsType_Api
{
//	emTypeTrueLink_Api = 0,			       	// 软终端
//	emTypeTruesens_Api = 1,				       	// 硬终端
//	emTypeMobile_Api = 2,                    	//移动终端
	emTypeUnknown_Api = 0,					// 未知
	emTypeTrueLink_Api = 1,			       	// 致玲
	emTypeTrueTouchPhoneIOS_Api = 2,		// 手机-IOS
	emTypeTrueTouchPadIOS_Api = 3,			// 平板-IOS
	emTypeTrueTouchPhoneAndroid_Api = 4,	// 手机-android
	emTypeTrueTouchPadAndroid_Api = 5,		// 平板-android
	emTypeTrueSens_Api = 6,					// 硬终端
	emTypeIMIX_Api = 7,						// imix
	emTypeThirdPartyTer_Api = 8,			// 第三方终端
	emTypeButt_Api = 255,					// 无效的终端型号
};

// enum EmDcsRole_Api
// {
// 	emRoleManage_Api = 0,			       	// 管理方
// 	emRoleOper_Api = 1,				       	// 协作方
// 	emRoleUser_Api = 2,                      	// 与会方
// 	emRoleErr_Api = 10,						//未填
// };

enum EmDcsConfMode_Api
{
    emConfModeStop_Api = 0,                     // 关闭数据协作
	emConfModeManage_Api = 1,			       	// 主席控制
	emConfModeAuto_Api = 2,				       	// 自动协作
};

enum EmDcsConfType_Api
{
	emConfTypeP2P_Api = 0,			       	// 点对点
	emConfTypeMCC_Api = 1,			       	// 多点
};

enum EmDcsWbMode_Api
{
	emWbModeWhiteBoard_Api = 0,			// 空白白板模式（非文档模式）
	emWBModeDOC_Api = 1,		       	// 文档
};

enum EmDcsWbEntityType_Api
{
	emUnknow_Api = 0,
	emLine_Api = 1,			// 直线
	emCircle_Api = 2,		// 圆形
	emPencil_Api = 3,		// 铅笔
	emColorPen_Api = 4,		// 水彩笔
	emImage_Api = 5,		// 图片
	emRectAngle = 6,		// 矩形
};

// 图片文件所处状态
enum EmDcsWbImageState_Api
{
	emImageStateDownloading_Api = 0,        // 文件正在接收，请耐心等待... 
	emImageStateDownLoadFail_Api = 1,		// 文件接收失败，非常抱歉！！！
	emImageStateOwnerAlreadyLeave_Api = 2,	// 文件同步失败，发起方可能已断开连接
	emImageStateDownLoadOk_Api = 3,			// 文件接收成功，即将显示
	emImageStateInit_Api = 4,		        // 初始状态
	emImageStateConvertFail_Api = 5,		// 文件转换失败，可能文件错误或已损坏
	emImageStateSelfAlreadyLeave_Api = 6,    // 文件接收未完成，已离开会议
};


enum EmDcsConnectErrCode_Api
{
	emConfSuccess_Api = 1,  // 会议服务器建链成功
	emConfFailed_Api = 2,	// 会议服务器建链失败
	emConfDisconnect_Api = 3,	// 会议服务器中途断链
	emLoginSuccess_Api = 4,		// 注册服务器建链成功
	emLoginFailed_Api = 5,		// 注册服务器建链失败
	emLoginDisconnect_Api = 6,	// 注册服务器建链中途断链
};


enum EmDcsRejectJoinConfCode_Api
{
	emRejectJoinConf_Start_Api          = 0,
	emRejectJoinConf_Busy_Api           = 1,
	emRejectJoinConf_Normal_Api         = 2,
	emRejectJoinConf_Rejected_Api       = 3,
	emRejectJoinConf_Unreachable_Api    = 4,
	emRejectJoinConf_Unknown_Api        = 5,
	emRejectJoinConf_End_Api            = 255,
};

enum EmSecErrorCode_Api
{
	emSecSucess_Api			=  0,		                    //成功

	///证书相关
	emSecCertImportFail_Api		= 1,	    //证书导入失败
	emSecCertExisted_Api        = 2,	    //证书已存在
	emSecCertTooLong_Api        = 3,	    //证书长度太长
	emSecCertFormatInvalid_Api	= 4,	    //证书格式无效
	emSecCertNotExisted_Api		= 5,	    //证书不存在
	emSecSignTestFail_Api       = 15,       //签名密钥对自测试
	emSecEncTestFail_Api        = 16,       //加密密钥对自测试


	////todo

	emSecErrorCodeEnd_Api     = 100
};

//通用曝光增益限制（手动、自动）
enum EmExposureGain_Api
{
	emGainRestrict15_Api	= 0, //15dB
	emGainRestrict18_Api	= 1, //18dB
	emGainRestrict21_Api	= 2, //21dB
	emGainRestrict24_Api	= 3, //24dB
	emGainRestrict27_Api	= 4, //27dB
	emGainRestrict30_Api	= 5, //30dB
	emGainRestrict33_Api	= 6, //33dB
	emGainRestrict36_Api	= 7, //36dB
	emGainRestrict39_Api	= 8, //39dB
	emGainRestrict42_Api	= 9, //42dB
	emGainRestrict45_Api	= 10 //45dB
};

//曝光模式增益类型
enum EmExposureGainType_Api 
{
	emExposureGainAuto_Api   = 0,	//自动模式的增益
	emExposureGainManual_Api = 1    //手动模式的增益
};

//白平衡（手动模式）增益类型
enum EmWBAGainType_Api
{
	emWBAGainRed_Api    = 0,   //红增益
	emWBAGainBlue_Api   = 1    //蓝增益
};

enum EmSecKeyUpdateMode_Api
{
	emSecKeyUpdateModeByPeriod   = 0,  // 按照时间周期更新
	emSecKeyUpdateModeByPackage  = 1  // 按照包的个数更新
};

//摄像机图像模式
enum EmCameraImgMode_Api
{
	emImgStandard_Api	= 0,	//标准
	emImgSoft_Api		= 1,	//柔和
	emImgBright_Api		= 2		//明亮
};

//摄像机 场景模式类型
enum EmCameraSceneMode_Api
{
	emCameraSceneMode_Standard_Api        = 0,		// 标准会场
	emCameraSceneMode_Projector_Api       = 1,		// 投影仪
	emCameraSceneMode_Peoplefeature_Api   = 2,		// 人物特写
	emCameraSceneMode_Peoplebacklight_Api = 3		// 人物逆光
};

enum EmVersionType_Api
{
	emChannel_Api = 0,  //CHANNEL代表渠道版本
	emOthers_Api  = 1   //暂时代表非渠道
};

enum EmLicenseKeyCheckValue_Api
{
	emWrongKey_Api   = 0,	//license错误
	emRightKey_Api   = 1,	//正确
	emNotExist_Api   = 2,	//不存在
	emParseError_Api = 3	//格式错误
};

//取消强认证理由
enum EmMtCancelAuth_Api 
{
	emAuthReasonCancel_Api	     = 1,   //主动取消
	emAuthReasonErrOverTime_Api	 = 2,   //认证失败超次数
	emAuthReasonTimeOut_Api	     = 3,   //认证超时
	emAuthReasonErrConnect_Api	 = 4,   //连接类型不对
};

// 虚拟会议室
enum EmMtVConfStatus_Api
{
	emVConf_Idle_Api = 0,				///< 0-空闲
	emVConf_Busy_Api = 1,				///< 1-使用中
};
// 摄像机方位调节错误类型
enum EmCameraPantiltErrType_Api
{
	EmCameraErrorType_unknown_Api     = 0,
	EmCameraErrorType_ZoominEnd_Api   = 1,  // 视野拉内
	EmCameraErrorType_ZoomoutEnd_Api  = 2,  // 视野拉外
	EmCameraErrorType_TiltUpEnd_Api   = 3,  // 云台到上
	EmCameraErrorType_TiltDownEnd_Api = 4,  // 云台到下
	EmCameraErrorType_PanLeftEnd_Api  = 5,  // 云台到左
	EmCameraErrorType_PanRightEnd_Api = 6   // 云台到右
};
// 最大与会终端数 
enum EmMtMaxJoinMt_Api
{
	emMaxJoinMt_8_Api = 0,				///< 8-小型8方会议
	emMaxJoinMt_32_Api = 1,				///< 32-小型32方会议
	emMaxJoinMt_64_Api = 2,				///< 64-小型64方会议
	emMaxJoinMt_192_Api = 3,				///< 192-大型192方会议
};

// 资源类型
enum EmMtVConfResources_Api
{
	emVConfResource_8_720_Api = 1,		///< 8方720P；
	emVConfResource_8_1080_Api = 2,		///< 8方1080P；
	emVConfResource_32_720_Api = 3,		///< 32方720P；
	emVConfResource_32_1080_Api = 4,	///< 32方1080P；
	emVConfResource_64_720_Api = 5,		///< 64方720P；
	emVConfResource_64_1080_Api = 6,	///< 64方1080P；
	emVConfResource_192_720_Api = 7,	///< 192方720P；
	emVConfResource_192_1080_Api = 8,	///< 192方1080P；
};

// FEC模式
enum EmMtFecMode_Api
{
	emMtFec_Close_Api = 0,
	emMtFec_Open_Api = 1,
};

// 内置摄像机采集制式
enum EmCameraVidStd_Api 
{
	emCamera_Auto_Api      = 0,
	emCamera_1080p_25_Api  = 1,
	emCamera_1080p_30_Api  = 2,
	emCamera_1080p_50_Api  = 3,
	emCamera_1080p_60_Api  = 4,
	emCamera_1080i_50_Api  = 5,
	emCamera_1080i_60_Api  = 6,
	emCamera_720p_50_Api   = 7,
	emCamera_720p_60_Api   = 8
};

enum EmVConfCreateType_Api
{
	emCreateNormalConf_Api = 0,			///< 实时会议
	emCreateVirtualConf_Api = 1,		///< 虚拟会议室
    emCreateConfByTemplate_Api = 2      ///< 根据模板ID创会
};

//投屏器状态
enum EmQkState_Api
{
	emUsbOff_Api	= 0,	//Usb断开
	emUsbOn_Api		= 1,	//Usb连入
	emUpdate_Api	= 2,	//升级中
	emWps_Api		= 3,    //Wps配对
	emWpsSucc_Api	= 4,   //Wps成功
	emApLink_Api	= 5,   //Ap连入
	emApOff_Api		= 6,   //Ap断开
	emQkStart_Api	= 7,   //开始投屏
	emQkOff_Api		= 8,   //停止投屏
	emWpsTimeOut_Api = 9,  //超时
	emUpDateSucc_Api = 10, //升级成功
	emUpDateFail_Api = 11  //升级失败
};

/** 网管文件打包错误信息*/
enum EmAgentPackFileState_Api
{
    emPackNotStart_Api    = 0,  ///< 未开始打包
    emPacking_Api         = 1,  ///< 终端正在打包
    emPackError_Api       = 2,  ///< 打包失败
};

enum EmResourceType_Api
{
	emResourceType_LimitP_Api  = 0,			///< 仅限制方数 JDMCU
	emResourceType_LimitPR_Api = 1,			///< 同时限制方数及分辨率 JDCLOUD
    emResourceType_None_Api    = 2,         ///< 平台不支持此功能
};

//mtc登录终端失败的错误码
enum EmMtcLoginFailReason_Api
{
	emPwdErr_Api 	     = 1,	//密码错误
	emTerStarting_Api    = 2,	//启动中
	emTerUpgrading_Api   = 3,   //升级中
	emFailReasonEnd_Api  = 10
};


enum EmAiActionState_Api
{
	emAiActionBegin_Api            = 0,
	emAiActionEndConf_Api          = 1,     ///< 结束会议状态
	emAiActionHungupConf_Api       = 2,     ///< 挂断会议状态
	emAiActionOpenAss_Api          = 3,     ///< 开双流状态
	emAiActionJoinConf_Api         = 4,     ///< 加入会议状态
	emAiActionInviteCall_Api       = 5,    ///< 邀请呼叫状态
	emAiActionEnd_Api              = 50,    
};

enum EmAiContactType_Api
{
	emAiContactBegin_Api    = 0,
	emAiLocalContact_Api    = 1,    //本地联系人
	emAiShareContact_Api    = 2,    //共享联系人

	emAiContactEnd_Api      =20,
};


enum EmAiAssState_Api
{
	emAiAssBegin_Api            = 0,
	emAiAssSendNormal_Api       = 1,    //正常发双流
	emAiAssNoVideoSource_Api    = 2,    //没有硬双流源
	emAiAssRob_Api              = 3,    //抢双流
	emAiAssClose_Api            = 4,    //关双流
	emAiAssEnd_Api              =20,
};

enum EmShortCutKeyType_Api
{
	emUnkown_Api			    = 0,		 ///未知
	emRedShortCutKey_Api        = 1,		 ///红色快捷键
	emYellowShortCutKey_Api     = 2,         ///黄色快捷键
	emGreenShortCutKey_Api      = 3,         ///绿色快捷键
};

enum EmShortCutKeyFuc_Api
{
	emFucBegin_Api              = 0,
	emLoop_Api                  = 1,         ///自环
	emApplyChair_Api            = 2,         ///申请主席
	emApplySpeaker_Api          = 3,         ///申请主讲
	emShowSystemInfo_Api        = 4,         ///显示系统信息
	emFullMute_Api              = 5,         ///全场哑音
	emSpeechHelper_Api          = 6,         ///语音助手
	emFaceCheckIn_Api           = 7,         ///人脸签到

	emClose_Api                 = 20,        ///关闭功能
};

enum EmApsProtocol_Api
{
    emHTTP_Api             = 0,
    emHTTPS_Api            = 1
};

enum EmFunctionIcon_Api
{
	emFunctionIconBegin_Api = 0,
	emFaceCheckIcon_Api = 1,
	// ......
};

enum EmPltSupportConfType_Api
{
    emPltConfTypeInvalid_Api   = 0, //无效
    emSupportMediaConf_Api     = 1, //仅支持传统会议
    emSupportPortConf_Api      = 2, //仅支持端口会议
    emSupportMediaPortConf_Api = 3, //支持传统会议和端口会议
};

/**@}*/

/**@}*/
#endif //_MTAPI_ENUM_H_