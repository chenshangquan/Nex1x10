/*******************************************************************************//**
*@file          nvapi_event_quickshare.h
*@brief         实现NVAPI QuickShareSdk 给UI(观察者)事件通知的定义
*
*@author        youjiaxing
*@version       1.0    
*@date          20180612
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _NVAPI_EVENT_QUICKSHARE_H_
#define _NVAPI_EVENT_QUICKSHARE_H_
/**@addtogroup event 事件
*@{
*/

/**@addtogroup baseevent 基础事件
*@{
*/

#include "nvapi_event_def.h"


enum EmNvApiQuickShareEv
{
	EV_UI_BGN(NVAPI_QUICKSHARE)  = EVSEG_NVAPI_QUICKSHARE_BGN,

	/**
	@brief    终端收到消息后，将该消息里的内容通过HID发送给无线投屏
	
	MainBuf(#TNVQKUsbInput_Api)
	@verbatim
	{
	    "achValue": ""
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_UsbEvent_Nty,

	/**
	@brief    通知无线投屏器版本

	MainBuf(#TNVQKUsbInput_Api)
	@verbatim
	{
		"achValue": ""
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_VerSion_Ntf,

	/**
	@brief    通知终端打开wps

	*/
	Ev_NvApi_Qk_RequstOpenWps_Cmd,

	/**
	@brief    Wps配对是否成功

	MainBuf(#BOOL32)
	@verbatim
	{
		"bSuc": TRUE:配对成功，FALSE:配对失败
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_WifiConnectState_Ntf,

	/**
	@brief    投屏器登录信息

	MainBuf(#TNVQKVidSrcSignal_Api)
	@verbatim
	{
		"dwIndex": 0 投屏器序号
		"bIsHasSrc": TRUE:有源 FALSE:无源
		"achVidName":"" 无线投屏pc name
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_Login_Ntf,

	/**
	@brief    投屏器视频源信息

	MainBuf(#TNVQKVidSrcInfo_Api)
	MainBuf(#u32)
	@verbatim
	{
		#TNVQKVidSrcInfo_Api
		{
			"dwVideoWidth":  0 视频宽，像素为单位,为0表示无信号
			"dwVideoHeight": 0 视频高，行为单位,为0表示无信号
			"dwFrameRate":   0 帧率，逐行时=场频，隔行时=场频/2，即60i=30P,为0表示无信号
		}
		#u32
		{
			dwQkIndex: 0 投屏器序号
		}
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_VidSrcInfo_Ntf,

	/**
	@brief    开始/结束 投屏通知

	MainBuf(#BOOL32)
	MainBuf(#u32)
	MainBuf(#BOOL32)
	@verbatim
	{
		"bView": TRUE:开始投屏 FALSE：结束投屏
		"dwIndex": 投屏器序号
		"bFromPC":TRUE:投屏器发起投屏 FALSE：observer发起投屏
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_StartViewQuickShare_Ntf,

	/**
	@brief    开始/结束 投屏结果通知

	MainBuf(#BOOL32)
	MainBuf(#u32)
	MainBuf(#EmNvViewQkReason_Api)
	@verbatim
	{
		"bView": TRUE:开始投屏 FALSE：结束投屏
		"dwIndex": 投屏器序号
		"emReason": 成功或失败原因
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_ViewQuickShareResult_Ntf,

	/**
	@brief    开始/停止 播放PPT通知

	MainBuf(#BOOL32)
	@verbatim
	{
		"bViewPPT": TRUE:开始 FALSE：停止
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_IsViewPpt_Ntf,

	/**
	@brief    投屏器软件在pc端是否正常打开

	MainBuf(#BOOL32)
	MainBuf(#U32)
	@verbatim
	{
		"bState": TRUE:正常打开 FALSE：没有打开
		"dwNodeId": 投屏器登录结点
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_IsNTState_Ntf,

	/**
	@brief    投屏器软件在pc端是否正常打开

	MainBuf(#EmNvQkZoomMode_Api)
	MainBuf(#U32)
	@verbatim
	{
		"EmNvQkZoomMode_Api": 播放设备显示比例
		"dwIndex": 投屏器序号
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_ZoomMode_Ntf,

	/**
	@brief    投屏器设置分辨率结果通知

	MainBuf(#u32)
	MainBuf(#BOOL32)
	@verbatim
	{
		"dwIndex": 投屏器序号
		"bResult": TRUE:设置成功 FALSE:设置失败
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_CodeRes_Ntf,

	/**
	@brief    投屏器设置帧率结果通知

	MainBuf(#u32)
	MainBuf(#BOOL32)
	@verbatim
	{
		"dwIndex": 投屏器序号
		"bResult": TRUE:设置成功 FALSE:设置失败
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_CodeFrame_Ntf,

	/**
	@brief    投屏器设置帧率结果通知

	MainBuf(#u32)
	MainBuf(#BOOL32)
	@verbatim
	{
		"dwIndex": 投屏器序号
		"bResult": TRUE:设置成功 FALSE:设置失败
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_CodeBitRate_Ntf,

	EV_UI_END(NVAPI_QUICKSHARE) = EVSEG_NVAPI_QUICKSHARE_END
	
};

#define Is_NvApiQK_Msg(m) ((m) >= EV_UI_BGN(NVAPI_QUICKSHARE) && (m) <= EV_UI_END(NVAPI_QUICKSHARE))

/**@}*/

/**@}*/
#endif // _NVAPI_EVENT_BASE_H_
