/**===========================================================================
 * @file    $Id$
 * @brief   负责MtVncAPi 桌面共享视频采集、编码、发送等功能接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTVNCVIDENCODE_H_
#define _I_MTVNCVIDENCODE_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_vnc.h"
#ifdef _WIN32_P_
#include "codecwrapper_win32.h"
#endif

#ifdef _ANDROID_
#include "codeclib_iOS_Android.h"
#endif
/**---------------------------------------------------------------------------
 * @class   Interface IMtVncVidEncode
 * @brief   责MtVncAPi 桌面共享视频采集、编码、发送等功能接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtVncVidEncode : public IMtApiIF
{
public:
	//视频编码器初始化
	virtual u32 Init() = 0;
	//视频编码器退出
	virtual u32 Exit() = 0;

	//设置采集视频源
	virtual u32	SetDeskDrawHwnd( s32 hDeskDrawWnd ) = 0;
	//设置视频编码参数
	virtual u32	SetVideoEncParam( const TVidEncParam_Api &tVideoEncParam ) = 0;
	//设置双流采集帧率
	virtual u32 SetCapFramerate( u8 byCapFramerate) = 0 ;
	//视频是否使用前向纠错
	virtual u32	SetVidFecEnable( BOOL32 bEnableFec ) = 0;

	//是否剥掉视频RTP扩展头
	virtual u32 VideoEnableRtpExStrip(BOOL32 bEnable) =0;

	//设置fec的切包长度
	virtual u32	SetVidFecPackLen( u16 wPackLen ) = 0;
	//是否帧内fec
	virtual u32	SetVidFecIntraFrame( BOOL32 bIntraFrame ) = 0;
	//设置fec算法 FEC_MODE_RAID5
	virtual u32	SetVidFecMode( u8 byAlgorithm ) = 0;
	//设置fec的x包数据包 + y包冗余包
	virtual u32	SetVidFecXY( s32 nDataPackNum, s32 nCrcPackNum ) = 0;
	//设置视频动态载荷的PT值的设定
	virtual u32	SetVideoActivePT( u8 byRealPt,u8 byDynamicPt ) = 0;
	//设置视频编码加密key字串、加密的载荷PT值 以及 解密模式 Aes or Des
	virtual u32	SetVidEncryptKey( s8 *pchKeyBuf, u16 wKeySize, u8 byEncryptMode ) = 0;

	virtual u32	SetVidSrtpCrypto( const TMtSrtpCrypto_Api &tSrtpCrypto ) = 0;
	//设置图像的网络传送参数
	virtual u32	SetNetSndVideoParam( const TNetParam_Api &tNetSndParam ) = 0;
	//设置丢包重传参数
	virtual u32 SetNetFeedbackVideoParam( u16 wBufTimeSpan, BOOL32 bRepeatSnd = FALSE ) = 0;

	//开始采集图像
	virtual u32	StartVideoCap() = 0;
	//停止采集图像
	virtual u32	StopVideoCap() = 0;
	//开始压缩图像
	virtual u32	StartVideoEnc() = 0;
	//停止压缩图像
	virtual u32	StopVideoEnc() = 0;
	//开始发送图像
	virtual u32	StartSendVideo( int dwSSRC = 0 ) = 0;
	//停止发送图像
	virtual u32	StopSendVideo() = 0;

	//获取编码器状态
	virtual u32	GetEncoderStatus( TMtVncVidEncStatus_Api &tKdvEncStatus ) = 0;
	//获取编码器的统计信息
	virtual u32	GetEncoderStatis( TMtVncVidEncStatis_Api &tKdvEncStatis ) = 0;
	//上报业务编码统计情况
	virtual u32 ReportEncoderStatistic() = 0;

	//设置FastUpdate，MediaCtrl在75帧内编一个I帧发送
	virtual u32	SetFastUpdate( BOOL32 bIsNeedProtect = TRUE ) = 0;
	//pszEndPointId - 终端的id, 当前仅支持e164号 dwparam IdLen - 终端id的长度 dwStreamId - 流id
	virtual u32	SetVideoSendId(const s8* pszEndPointId, u32 dwStreamId) = 0;//设置发送端的id
	virtual u32	GetVideoSendId(s8* pszEndPointId, u32* pdwIdLen, u32* pdwStreamId) = 0;//获取发送端的id
	virtual u32	VideoSendEnableNatTraversal(BOOL32 bEnable, const TNetParam_Api *ptKeepAliveParam = NULL) = 0;//是否启用nat穿越

	virtual u32 SetSndNetBand(u32 dwSndNetBand) = 0;/*网络发送带宽(单位:Kbps)*/  

	//设置采集到编码缩放策略
	virtual u32     SetVidCapToEncZoomPolicy(enZoomMode_Api emZoomMode) = 0;

	//移除网络传送参数
	virtual u32		RemoveNetSndParam() = 0;
};

#endif // _I_MTVNCVIDENCODE_H_