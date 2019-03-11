/**===========================================================================
 * @file    $Id$
 * @brief   负责终端码流监控图像相关功能接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTMONITOR_H_
#define _I_MTMONITOR_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_vc.h"
#include "mtapi_container.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtMonitor
 * @brief   负责终端码流监控图像相关功能接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtMonitor : public IMtApiIF
{
public:
	//video双流开始/停止命令
	virtual u32 VideoAssStreamCmd( const BOOL32 bStart ) = 0;
	//开始码流广播命令
	virtual u32 StartStreamBroadcastCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx, const TNetAddr_Api& tRtpAddr, const TNetAddr_Api& tRtcpAddr ) = 0;
	//停止码流广播命令
	virtual u32 StopStreamBroadcastCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx ) = 0;
	//转发某一路码流命令
	virtual u32 StartStreamTransCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx, const TRtpRtcpPair_Api& tRtpRtcpAddr ) = 0;
	
	virtual u32 IFrameRuestCmd(const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx) = 0;

	//停止某一路码流命令
	virtual u32 StopStreamTransCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx, const TRtpRtcpPair_Api& tRtpRtcpAddr ) = 0;
	//开始某一路录像命令
	virtual u32 StartRecoderCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx, const TRtpRtcpPair_Api& tRtpRtcpAddr ) = 0;
	//停止某一路录像命令
	virtual u32 StopRecoderCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx, const TRtpRtcpPair_Api& tRtpRtcpAddr ) = 0;
	//获取监控参数命令
	virtual u32 GetMonitorParamCmd(  const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx ) = 0;
	//请求某一路码流关键帧命令
	virtual u32 SendFastUpdateCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx ) = 0;
	//设置采集播放窗口命令 (仅WIN32)
	virtual u32 SetPlayHwndCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx, const u32 hWnd ) = 0;

	//清空采集播放窗口命令(仅WIN32)
	virtual u32 ClearWindowCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx ) = 0;
	//采集控制命令 (仅WIN32)
	virtual u32 VidCapCtrlCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx, const BOOL32 bStartCap ) = 0;
	//抓图命令 (仅WIN32)
	virtual u32 GrabPicCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx, const u32 hWnd ) = 0;
	//保存抓图命令 (仅WIN32)
	virtual u32 SavePicCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx, const EmPicFormat_Api emPicFormat, const s8 *pszPicPathName ) = 0;
	//设置只解关键帧命令 (仅WIN32)
	virtual u32 SetDecOnlyKeyFrameCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx, const BOOL32 bOn ) = 0;
	//获取视频输入设备列表命令 (仅WIN32)
	virtual u32 GetVidCapDevListCmd( ) = 0;
	//设置多画面风格请求
	virtual u32 SetPIPReq(const EmPiPMode_Api emPiPMode)=0;
	//查询多画面风格请求
	virtual u32 QueryPIPReq()=0;
	//本地视频源选看内容查询请求
	virtual u32 GetLocalVideoViewReq()=0;
	//TL获取当前视频采集设备命令 (仅WIN32)
	virtual u32 GetCurVidCapDevCmd() = 0;
	//设置视频输入设备命令 (仅WIN32)
	virtual u32 SetVidCapDevCmd( const TDevInfo_Api& tDevInfo ) = 0;
	//移动画中画命令 (仅Embed)
	virtual u32 MovePIPCmd( ) = 0;
	//交换画中画命令 (仅Embed)
	virtual u32 SwitchPIPCmd( ) = 0;
	//本地视频源选看指令
	virtual u32 SelectLocalVideoViewCmd( const EmCameraView_Api& tCfg ) = 0;
	//开始录像命令(windows平台)
	virtual u32 StartRecCmd(const TRecordParam_Api &tRecParam) = 0;
	//停止录像命令(windows平台)
	virtual u32 StopRecCmd(const BOOL32 bLocal) = 0;
	//暂停录像命令(windows平台)
	virtual u32 PauseRecCmd(const BOOL32 bLocal) = 0;
	//继续录像命令(windows平台)
	virtual u32 ResumeRecCmd(const BOOL32 bLocal) = 0;
	//设置录像磁盘告警阈值命令(windows平台)
	virtual u32 SetRecDiskAlarmLevelCmd(const TRecordDiskAlarmLevel_Api &tRecAlarmParam) = 0;
   //设置台标加入码流
	virtual u32 SetAddLogoIntoEncStreamCmd(const BOOL32 bAddIntoStream, const TMtFullLogoParam_Api &tLogoParam) = 0;

	virtual u32 SetMobilAddLogoIntoEncStreamCmd( const BOOL32 bAddIntoStream, const TMtFullLogoParam_Api* ptArrFullLogoParam, u8 byCnt ) = 0;
	
	virtual u32 SetMonitorPicShotCmd(EmCodecComponent_Api emCodecType, EmCodecComponentIndex_Api emCodecId, BOOL32 bOn,s32 nIndex) = 0;

	virtual u32 GetMonitorPicShotStatusReq(EmCodecComponent_Api emCodecType, EmCodecComponentIndex_Api emCodecId) = 0;

	virtual u32 MediaDecCallBackControlCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emStreamIdx, const BOOL32 bStart ) = 0;
    
	virtual u32 CodecSetShowOsd(BOOL32 bShow )=0;

	//开始本地录像命令(仅硬终端)
	virtual u32 StartLocalRecCmd(const s8 *pszRecPathName) = 0;
	//停止本地录像命令(仅硬终端)
	virtual u32 StopLocalRecCmd( ) = 0;
	//暂停本地录像命令(仅硬终端)
	virtual u32 PauseLocalRecCmd( ) = 0;
	//继续本地录像命令(仅硬终端)
	virtual u32 ContinueLocalRecCmd( ) = 0;
	//获取本地录像状态的请求
	virtual u32 GetLocalRecStatusReq( ) = 0;
	//获取本地录像开始时间的请求
	virtual u32 GetLocalRecStartTimeCmd( ) = 0;
	//图片获取
	virtual u32 CodecPicGetReq( s32 nIndex ) = 0;
public:
	//5S内当前是否丢包
	virtual BOOL32 IsStreamLostPack()  = 0;
	//当前码流监控参数获取
	//获取视频输入设备列表(仅WIN32)
	virtual TDevInfoList_Api GetVidCapDevList() = 0;
	//通过osd来打开/关闭pc双流，暂时用于sky100，sky100不支持硬双流
	virtual u32 OsdCtrlPcAssStreamCmd( const BOOL32 bOpen ) = 0;
private:

};

#endif // _I_MTMONITOR_H_