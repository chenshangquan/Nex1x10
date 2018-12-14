/*******************************************************************************//**
*@file          mtapi_vncapi.h
*@brief         提供mtvncapi PC桌面共享对外接口
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_VNCAPI_H_
#define _MTAPI_VNCAPI_H_
/**@addtogroup api API接口
*@{
*/

/**@addtogroup vncapi 客户端双流API
*@{
*/

#include <string.h>
#include "mtapi_export.h"
#include "mtapi_typedef.h"
#include "mtapi_struct.h"


 

/**
* KdvMt_VNCIsInited
* @brief mtvncapi是否进行过初始化
*
* @param	[in] void
* @return	BOOL32  TRUE ： 已初始化， FALSE：尚未初始化
* @note KdvMt_VNCInitalize,MTAPI_VNCUnInitalize
*/
KdvMtAPI BOOL32 KdvMtCALL KdvMt_VNCIsInited();



/**
* KdvMt_VNCInitalize
* @brief mtvcapi模块初始化（这个的调用要在mtbaseapi调用的setnotify之后）
*
* @return	u32  0: 初始化成功， 非0: 初始化失败
* @note KdvMt_VNCIsInited, KdvMt_VNCUnInitalize
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCInitalize( );



/**
* KdvMt_VNCUnInitalize
* @brief mtvcapi模块释放退出
*
* @return	u32  0: 成功， 非0: 失败
* @note KdvMt_VNCInitalize, KdvMt_VNCIsInited
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCUnInitalize();



/**
* KdvMt_VNCSetNotify
* @brief  注册Observer(UI)通知回调(这个函数如果没有调用则使用mtbaseapi中的回调函数)
*
* @param    [in]   cbNotify  要注册的回调函数
* @return   void
* @note
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCSetNotify( IN CONST NOTIFY_OBSERVER_CALLBACK cbNotify );



/**
* KdvMt_VNCGetAssSndVidStatusReq
* @brief   请求终端辅流发送状态
*
* @param    [in]   dwSSID      MT会话ID 
* @return   u32    0：获取成功  其他错误码
* @note 回复通知：Ev_MtApi_Vnc_AssSndSream_Status_Ntf、Ev_MtApi_Vnc_AssSndSream_Status_Rsp
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCGetAssSndVidStatusReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_VNCGetAssSndVidStatus
* @brief  获取终端辅流发送状态
*
* @param    [out]  tAssSndVidStatusList 终端video辅流发送状态信息
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
* @note 更新内容消息：Ev_MtApi_Vnc_AssSndSream_Status_Ntf、Ev_MtApi_Vnc_AssSndSream_Status_Rsp
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCGetAssSndVidStatus( OUT TMtAssVidStatusList_Api& tAssSndVidStatusList, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
* KdvMt_VNCGetAssSndVidStatusReq
* @brief   请求终端辅流接受状态
*
* @param    [in]   dwSSID      MT会话ID 
* @return   u32    0：获取成功  其他错误码
* @note 回复通知：Ev_MtApi_Vnc_AssRcvSream_Status_Ntf、Ev_MtApi_Vnc_AssRcvSream_Status_Rsp
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCGetAssRcvVidStatusReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_VNCGetAssRcvVidStatus
* @brief  获取终端辅流接收状态
*
* @param    [out]  tAssRcvVidStatusList 终端video辅流接收状态信息
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
* @note 更新内容消息：Ev_MtApi_Vnc_AssRcvSream_Status_Ntf、Ev_MtApi_Vnc_AssRcvSream_Status_Rsp
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCGetAssRcvVidStatus(  OUT TMtAssVidStatusList_Api& tAssRcvVidStatusList, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
* KdvMt_VNCSndPcAssStreamReq
* @brief   PC桌面共享发送请求(发送双流前通过KdvMt_CFGGetCallInfoRt获取呼叫状态，以及双流状态来决定是否发送双流)
*
* @param    [in]   tPcRtcp     开启PC桌面共享的PC IP(网络序)和端口信息
* @param    [in]   bStart      TURE:开始， FALSE：停止
* @param    [in]   dwSSID      MT会话ID 
* @return   u32    0：获取成功  其他错误码
* @note 回复通知：(Ev_MtApi_Vnc_PcAssStream_ChanParam_Ntf、Ev_MtApi_Vnc_PcAssStream_StartEnc_Ntf、Ev_MtApi_Vnc_PcAssStream_IFrameRequest_Ntf、Ev_MtApi_Vnc_PcAssStream_SetBitrate_Ntf)/Ev_MtApi_Vnc_PcAssStream_StopEnc_Ntf
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCSndPcAssStreamReq( IN CONST TNetAddr_Api& tPcRtcp, IN CONST BOOL32 bStart, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_VNCPlayStream
* @brief   播放一路码流，(KdvMt_CFGGetCallInfoRt获取呼叫状态，只能空闲状态播放码流 )
*
* @param    [in]   tPcRtcp       开启PC桌面共享的PC IP(网络序)和端口信息
* @param    [in]   bStart        TURE:开始， FALSE：停止
* @param    [in]   emCodecType   解码类型，主解码器或者辅解码器
* @param    [in]   emVideoIndex  解码类型，解码器索引
* @param    [in]   dwSSID        MT会话ID 
* @return   u32    0：获取成功   其他错误码
* @note 回复通知：(Ev_MtApi_Vnc_PcAssStream_ChanParam_Ntf、Ev_MtApi_Vnc_PcAssStream_StartEnc_Ntf、Ev_MtApi_Vnc_PcAssStream_IFrameRequest_Ntf、Ev_MtApi_Vnc_PcAssStream_SetBitrate_Ntf)/Ev_MtApi_Vnc_PcAssStream_StopEnc_Ntf
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCPlayStream( IN CONST TNetAddr_Api& tPcRtcp, IN CONST BOOL32 bStart, 
	                                        IN CONST EmCodecComponent_Api emCodecType,
	                                        IN CONST EmCodecComponentIndex_Api emVideoIndex,
	                                        IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_VNCSetChanActive
* @brief   设置通道激活状态
*
* @param    [in]   bActive     通道激活状态
* @param    [in]   bStart      TURE:开始， FALSE：停止
* @param    [in]   dwSSID      MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCSetChanActive( IN CONST BOOL32& bActive, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_VNCGetPcAssStreamChanParam
* @brief  获取PC桌面共享所有通道参数
*
* @param    [out]  tAssStreamChanParam PC桌面共享所有通道参数信息
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
* @note 更新内容消息：Ev_MtApi_Vnc_PcAssStream_ChanParam_Ntf
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCGetPcAssStreamChanParam( OUT TMTPcAssStreamChanParam_Api& tAssStreamChanParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
* KdvMt_VNCSetDeskDrawHwnd
* @brief  设置采集视频源
*
* @param    [in]   nDeskDrawWnd     采集句柄
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCSetDeskDrawHwnd( s32 nDeskDrawWnd, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
* KdvMt_VNCSetVideoEncParam
* @brief  设置视频编码参数
*
* @param    [in]   tVideoEncParam   编码参数
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCSetVideoEncParam( const TVidEncParam_Api &tVideoEncParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_VNCSetCapFramerate
* @brief  设置视频编码参数
*
* @param    [in]   byCapFramerate   采集帧率
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCSetCapFramerate( u8 byCapFramerate, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
* KdvMt_VNCSetVideoEncParam
* @brief  视频是否使用前向纠错
*
* @param    [in]   bEnableFec       是否使用前向纠错
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCSetVidFecEnable( BOOL32 bEnableFec, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_VideoEnableRtpExStrip
* @brief  是否剥掉视频RTP扩展头
*
* @param    [in]   bEnable       是否剥掉视频RTP扩展头
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VideoEnableRtpExStrip( BOOL32 bEnable, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_VNCSetVidFecPackLen
* @brief  设置fec的切包长度
*
* @param    [in]   wPackLen         切包长度
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCSetVidFecPackLen( u16 wPackLen, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
* KdvMt_VNCSetVidFecIntraFrame
* @brief  是否帧内fec
*
* @param    [in]   bIntraFrame      是否帧内fec
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCSetVidFecIntraFrame( BOOL32 bIntraFrame, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
* KdvMt_VNCSetVidFecMode
* @brief  设置fec算法 FEC_MODE_RAID5
*
* @param    [in]   byAlgorithm      fec算法
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCSetVidFecMode( u8 byAlgorithm, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
* KdvMt_VNCSetVidFecXY
* @brief  设置fec的x包数据包 + y包冗余包
*
* @param    [in]   nDataPackNum     x包数据包
* @param    [in]   nCrcPackNum      y包冗余包
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCSetVidFecXY( s32 nDataPackNum, s32 nCrcPackNum, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
* KdvMt_VNCSetVideoActivePT
* @brief  设置视频动态载荷的PT值的设定
*
* @param    [in]   byRealPt     本地动态载荷的PT值
* @param    [in]   byDynamicPt  对端动态载荷的PT值
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCSetVideoActivePT( u8 byRealPt,u8 byDynamicPt, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
* KdvMt_VNCSetVidEncryptKey
* @brief  设置视频编码加密key字串、加密的字符串大小 以及 加密模式 Aes or Des
*
* @param    [in]   pchKeyBuf        密key字串
* @param    [in]   wKeySize         密key字串大小
* @param    [in]   byEncryptMode    加密模式
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCSetVidEncryptKey( s8 *pchKeyBuf, u16 wKeySize, u8 byEncryptMode, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_VNCSetVidSrtpCrypto
* @brief  设置视频编码srtp参数
* @param    [in]   tSrtpCrypto      srtp参数
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCSetVidSrtpCrypto( const TMtSrtpCrypto_Api &tSrtpCrypto, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_VNCSetNetSndVideoParam
* @brief  设置图像的网络传送参数
*
* @param    [in]   tNetSndParam     网络参数
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCSetNetSndVideoParam( const TNetParam_Api &tNetSndParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
* KdvMt_VNCSetNetFeedbackVideoParam
* @brief  设置丢包重传参数
*
* @param    [in]   wBufTimeSpan     间隔
* @param    [in]   bRepeatSnd       是否重发
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCSetNetFeedbackVideoParam( u16 wBufTimeSpan, BOOL32 bRepeatSnd = FALSE, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_VNCStartVideoCap
* @brief  开始采集图像
*
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCStartVideoCap( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
* KdvMt_VNCStopVideoCap
* @brief  停止采集图像
*
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCStopVideoCap( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
* KdvMt_VNCStartVideoEnc
* @brief  开始压缩图像
*
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCStartVideoEnc( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
* KdvMt_VNCStopVideoEnc
* @brief  停止压缩图像
*
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCStopVideoEnc( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
* KdvMt_VNCStartSendVideo
* @brief  开始发送图像
*
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCStartSendVideo( int dwSSRC = 0, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_VNCStopSendVideo
* @brief  停止发送图像
*
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCStopSendVideo( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
* KdvMt_VNCGetEncoderStatus
* @brief  获取编码器状态
*
* @param    [in]   tKdvEncStatus    视频编码状态信息
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCGetEncoderStatus( TMtVncVidEncStatus_Api &tKdvEncStatus, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
* KdvMt_VNCGetEncoderStatis
* @brief  获取编码器的统计信息
*
* @param    [in]   tKdvEncStatis    视频编码统计信息
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCGetEncoderStatis( TMtVncVidEncStatis_Api &tKdvEncStatis, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_VNCReportEncoderStatistic
* @brief  上报业务辅视频编码统计情况
*
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCReportEncoderStatistic( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_VNCSetFastUpdate
* @brief  设置FastUpdate，MediaCtrl在75帧内编一个I帧发送
*
* @param    [in]   bIsNeedProtect   是否需要，默认为TRUE
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCSetFastUpdate( BOOL32 bIsNeedProtect, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_VNCSetVideoSendId
* @brief  设置发送端的id
*
* @param    [in]   pszEndPointId     终端的id, 当前仅支持e164号（如果为NULL，清空标识，停止码流的时候要清空标识）
* @param    [in]   dwStreamId        流id
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCSetVideoSendId( const s8* pszEndPointId, u32 dwStreamId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_VNCSetSndNetBand
* @brief  设置网络发送带宽
*
* @param    [in]   dwSndNetBand     网络发送带宽
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCSetSndNetBand( u32 dwSndNetBand,  IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );
/**
* KdvMt_VNCGetVideoSendId
* @brief  获取发送端的id
*
* @param    [out]   pszEndPointId   终端的id, 当前仅支持e164号
* @param    [out]   pdwIdLen        终端id的长度
* @param    [out]   pdwStreamId     流id
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCGetVideoSendId( s8* pszEndPointId, u32* pdwIdLen, u32* pdwStreamId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_VNCVideoSendEnableNatTraversal
* @brief  是否启用nat穿越（停止码流的时候要停止启用nat穿越）
*
* @param    [in]   bEnable          是否穿越
* @param    [in]   ptNetParam       地址
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/

KdvMtAPI u32 KdvMtCALL KdvMt_VNCVideoSendEnableNatTraversal( BOOL32 bEnable,TNetParam_Api *ptNetParam = NULL,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_VNCVideoSetVidCapToEncZoomPolicy
* @brief  设置采集到编码缩放策略
*
* @param    [in]   emZoomMode          采集到编码缩放策略
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCVideoSetVidCapToEncZoomPolicy( enZoomMode_Api emZoomMode, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_VNCRemoveNetSndParam
* @brief  移除网络传送参数
*
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VNCRemoveNetSndParam( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**@}*/

/**@}*/
#endif //_MTAPI_VNCAPI_H_
