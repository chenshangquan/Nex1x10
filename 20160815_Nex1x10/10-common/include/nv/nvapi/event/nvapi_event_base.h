/*******************************************************************************//**
*@file          nvapi_event_base.h
*@brief         实现NVAPI BaseSdk 给UI(观察者)事件通知的定义
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _NVAPI_EVENT_BASE_H_
#define _NVAPI_EVENT_BASE_H_
/**@addtogroup event 事件
*@{
*/

/**@addtogroup baseevent 基础事件
*@{
*/

#include "nvapi_event_def.h"


enum EmNvApiBaseEv
{
	EV_UI_BGN(NVAPI_BASE)  = EV_NVAPI_EVENT_BGN,

	/**
	@brief    终端客户端账号验证应答，且对应于Ev_NV_NVCLogin_Rsp	
	
	BODY(nv::TNVUserReqResult, loginuser_rsp)

	*/
	Ev_NvApi_Base_NVCLogin_Rsp,

	/**	
	@brief    断链通知，且对应于OSP_DISCONNECT
	*/
	Ev_NvApi_Base_NVDisconnect_Ntf,

	/**	
	@brief    添加用户响应,Ev_NV_NVCAddUser_Rsp
	
	BODY(nv::TNVMultiUserReqResult, adduser_rsp)

	*/
	Ev_NvApi_Base_NVCAddUser_Rsp,  
	
	/**	
	@brief添加用户通知, Ev_NV_NVCAddUser_Ntf
	
	BODY(nv::TNVMultiUserFullInfo, adduser_ntf)

	*/
	Ev_NvApi_Base_NVCAddUser_Ntf,
	
	/**	
	@brief    修改用户响应,Ev_NV_NVCMUser_Rsp
	
	BODY(nv::TNVMultiUserReqResult, muser_rsp)

	*/
	Ev_NvApi_Base_NVCMUser_Rsp,
	
	/**		
	@brief    修改用户通知,Ev_NV_NVCMUser_Ntf
	
	BODY(nv::TNVMultiUserFullInfo, muser_ntf)
	*/
	Ev_NvApi_Base_NVCMUser_Ntf,

	/**		
	@brief    删除用户响应,Ev_NV_NVCDUser_Rsp
	
	BODY(nv::TNVMultiUserReqResult, duser_rsp)
	*/
	Ev_NvApi_Base_NVCDUser_Rsp,

	/**		
	@brief    删除用户通知,Ev_NV_NVCDUser_Ntf
	
	BODY(nv::TNVMultiUserFullInfo, duser_ntf)
	*/
	Ev_NvApi_Base_NVCDUser_Ntf,

	/**	
	@brief    查询用户响应,Ev_NV_NVCSUser_Rsp
	
	BODY(nv::TNVMultiUserFullInfo, duser_rsp)
	*/
	Ev_NvApi_Base_NVCSUser_Rsp,

	/**	
	@brief    注销响应,Ev_NvApi_Base_NVCLogOut_Ntf
	
	BODY(nv::TString, user_name)
	*/
	Ev_NvApi_Base_NVCLogOut_Ntf,

	/**	
	@brief    UI同步通知，且对应于Ev_Conf_UISynchronize_Ntf
	BODY(nv::TS32,       reason) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvUISynchronizeReason
	*/

	Ev_NvApi_Base_UISynchronize_Ntf, 

	/**	
	@brief    发送待机倒计时通知(仅Embed)，且对应于Ev_NV_BLL_CodecSleepFailReason_Ntf	
	
	BODY(nv::TS32, fail_reason) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmSleepFailReason
	*/
	Ev_NvApi_Base_SleepFailReason_Ntf,

	/**	
	@brief    发送待机倒计时通知(仅Embed)，且对应于Ev_NV_CodecSleepState_Ntf	
	
	BODY(nv::TBOOL32, is_sleep) is_sleep : TRUE表示进入睡眠状态，FALSE表示进入唤醒状态
	*/
	Ev_NvApi_Base_SleepState_Ntf,

	/**	
	@brief    升级检测结果通知，对应于Ev_NV_CheckUpgradeResult_Ntf
	
	BODY(nv::TU32, errorcode) //错误码 NV_SUCCESS:成功
	                          //ERR_UPGRADE_CONNECT_SERVER_FAILED 连接服务器失败
							  //ERR_UPGRADE_UNKNOWN 未知错误
							  //...
	*/
	Ev_NvApi_Base_CheckUpgradeResult_Ntf,

	/**	
	@brief    最新版本信息通知，且对应于Ev_NV_UpgradeVersionInfo_Ntf
	
	BODY(TNVDevUpgrade, ver_info)
	*/
	Ev_NvApi_Base_UpgradeVersionInfo_Ntf,

	/**	
	@brief    最新版本信息通知，且对应于Ev_NV_BLL_AutoLoadUpgradeFileOk_Ntf
	
	BODY(TNVUpgradeVersionInfoList, ver_info)
	*/
	Ev_NvApi_Base_AutoLoadUpgradeFileOk_Ntf,
	/**	
	@brief    文件下载状态通知，且对应于Ev_NV_UpgradeFileDownloadInfo_Ntf	
	
	BODY( TU8, info )	//下载进度信息
	*/
	Ev_NvApi_Base_UpgradeFileDownloadInfo_Ntf,

	/**
	@brief    文件下载完毕通知，且对应于Ev_NV_UpgradeFileDownloadOk_Ntf
	*/
	Ev_NvApi_Base_UpgradeFileDownloadOk_Ntf,
	
	/**
	@brief    升级异常时 升级包已下载 提醒是否安装通知
	*/	
	Ev_NvApi_Base_UpgradeExceptionPackageIsReady_Ntf,

	/**
	@brief    与服务器断链通知，且对应于Ev_NV_BLL_UpgradeDisconnectServer_Ntf
	*/
	Ev_NvApi_Base_UpgradeDisconnectServer_Ntf,

	/**	
	@brief    更新系统文件状态通知，且对应于Ev_NV_UpgradeSysFileUpdateStatus_Ntf
	
	 BODY(nv::TS32, upgrade_notify)   //nv::EmUpgradeNotify
	*/
	Ev_NvApi_Base_UpgradeSysFileUpdateStatus_Ntf,

	/**	
	@brief    升级总包包含哪些子包，且对应于Ev_NV_BLL_UpgradePackageContent_Ntf
	
	 BODY(nv::TNVUpgradePackageContent, upgrade_package) 
	*/
	Ev_NvApi_Base_UpgradePackageContent_Ntf,
	
		/**	
	@brief    更新系统文件状态通知，且对应于Ev_NV_UpgradeSysFileUpdateStatus_Ntf
	*/
	Ev_NvApi_Base_UpgradeFinishGoingToReboot_Ntf,

	/**	
	@brief    版本信息通知给无线投屏，且对应于Ev_NvApi_Base_UpdateSystem2QuickShare_Ntf
	
	 BODY(nv::TNVDevUpgrade, tDevup)
	*/
    Ev_NvApi_Base_UpdateSystem2QuickShare_Ntf,
    
	/**
	@brief  设置系统升级状态，对应Ev_MT_BLL_SetSysUpgradeRt_Ntf
	
	BODY(nv::TBOOL32, bSysUpgrade)

	*/	
	Ev_NvApi_Base_SetSysUpgradeRt_Ntf,
	
	/**	
	@brief    检查U盘升级包响应
	
	BODY(nv::TBOOL32, file_found)
    BODY(nv::TString, file_path)
    BODY(nv::TNVUpgradeVersionInfoList, upgrade_info)
	*/
	Ev_NvApi_Base_UsbUpgradeFileCheck_Rsp,

	/**	
	@brief    待机状态通知(仅Embed)，且对应于Ev_NV_BLL_SleepCountDown_Ntf
	
	BODY(nv::TU16, count_down)	 待机剩余时间	

	*/
	Ev_NvApi_Base_SleepCountDown_Ntf,

	/**	
	@brief    待机响应(仅Embed)
	
	BODY(nv::TBOOL32, is_sucess)
	BODY(nv::TS32, fail_reason) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmSleepFailReason
	@endverbatim
	*/
	Ev_NvApi_Base_CodecDspSleep_Rsp,
	
		/**		
	@brief    系统消息提示
	
	BODY(nv::TNVSysHint, sys_hint)

	*/
	Ev_NvApi_SysHint_Ntf,
	
	/**		
	@brief   开始终端服务，对应Ev_NV_BLL_SrvStartResult_Ntf
	
	BODY(nv::TBOOL32, SrvStartRlt)
	BODY(nv::TNVSrvKeepLiveInfo, SrvKeepLiveInfo)
	*/		
	Ev_NvApi_Base_SrvStartResult_Ntf,
	
	/**		
	@brief   停止终端服务，对应Ev_NV_BLL_SrvEndtResult_Ntf
	
	BODY(nv::TBOOL32, SrvEndRlt)
	BODY(nv::TU32, Nvaid)
	*/		
	Ev_NvApi_Base_SrvEndtResult_Ntf,
	
	/**
	@brief    日志配置通知
	
	BODY(nv::TBOOL32, bEnableFileLog)

	*/
	Ev_NvApi_Base_LogStatusCfg_Ntf,

	/**
	@brief    获取日志配置响应
	
	BODY(nv::TBOOL32, bEnableFileLog)
	*/
	Ev_NvApi_Base_GetLogStatusCfg_Rsp,
	
	/**		
	@brief    终端 IP配置通知
	
	BODY(nv::TString, ip)
	*/
	Ev_NvApi_Base_TerIpCfg_Ntf,

	/**		
	@brief    终端 IP配置响应
	
	BODY(nv::TString, ip)
	*/
	Ev_NvApi_Base_GetTerIpCfg_Rsp,
	/**		
	@brief    Imix IP配置通知
	
	BODY(nv::TString, ip)
	*/
	Ev_NvApi_Base_ImixIpCfg_Ntf,

	/**		
	@brief    获取Imix IP配置响应
	
	BODY(nv::TString, ip)
	*/
	Ev_NvApi_Base_GetImixIpCfg_Rsp,

	/**		
	@brief    日志服务器 IP配置通知
	
	BODY(nv::TString, ip)
	*/
	Ev_NvApi_Base_LogSerIpCfg_Ntf,

	/**		
	@brief    获取日志服务器 IP配置响应
	
	BODY(nv::TString, ip)
	*/
	Ev_NvApi_Base_GetLogSerIpCfg_Rsp,

	/**		
	@brief    邮件服务器 IP配置通知
	
	BODY(nv::TString, ip)
	*/
	Ev_NvApi_Base_EmailSerIpCfg_Ntf,

	/**		
	@brief    获取邮件服务器 IP配置响应
	
	BODY(nv::TString, ip)
	*/
	Ev_NvApi_Base_GetEmailSerIpCfg_Rsp,

	/**		
	@brief    后台升级配置通知
	
	BODY(nv::TBOOL32, tb)
	*/
	Ev_NvApi_Base_SetBackstageUpgradeCfg_Ntf,

	/**		
	@brief    获取后台升级配置响应
	
	BODY(nv::TBOOL32, tb)
	*/
	Ev_NvApi_Base_GetBackstageUpgradeCfg_Rsp,
	
	/**		
	@brief   登入终端状态上报
	
	BODY(NV::TBOOL32, is_login)

	*/
	Ev_NvApi_Base_MTCLogin_Ntf,
	
	/**		
	@brief   当前的呼叫状态上报
	
	BODY(nv::TS32, callsate)	//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvCallState

	*/
	Ev_NvApi_Base_CallLinkState_Ntf,
	
	/**		
	@brief   当前的双流状态上报
	
	BODY(NV::TBOOL32, is_senddual)
	BODY(NV::TS32, vid_lab) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvVidLabel

	*/
	Ev_NvApi_Base_AssSndSream_Status_Ntf,
	
	/**		
	@brief   当前的双流状态上报
	
	BODY(NV::TBOOL32, is_rcvdual)

	*/
	Ev_NvApi_Base_AssRcvSream_Status_Ntf,
	
	/**	
	@brief    注销响应,Ev_NvApi_Base_SetSysDataTimeResult_Rsp
	
	BODY(nv::TU32, result)
	BODY(nv::TNVTime, tmttime )
	*/
	Ev_NvApi_Base_SetSysDataTimeResult_Rsp,

	/**
	@brief    时区配置通知
	
	BODY(nv::TS32, timezoon)

	*/
	Ev_NvApi_Base_SetTimeZoneCfg_Ntf,
	
	/**
	@brief    获取时区响应
	
	BODY(nv::TS32, timezoon)
	*/
	Ev_NvApi_Base_GetTimeZoneCfg_Rsp,

	/**
	@brief    切换画面响应
	
	BODY(nv::TS32, pic) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvImixVidSrcType
	BODY(nv::TS32, reason) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvViewReason
	*/
	Ev_NvApi_Base_ViewPic_Ntf,

	/**
	@brief    Imix主动发送当前画面给UI
	
	BODY(nv::TS32, pic) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvImixVidSrcType
	*/
	Ev_NvApi_Base_ViewPicPosToUI_Ntf,
	
	/**
	@brief    获取画面响应
	
	BODY(nv::TS32, pic) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvImixVidSrcType
	*/
	Ev_NvApi_Base_GetPic_Rsp,

	/**
	@brief    发送计算机名响应
	
	BODY(nv::TString, tStr) //计算机名
	*/
	Ev_NvApi_Base_SendPCName_Ntf,
	
	/**
	@brief    发送触控信息响应
	
	BODY(nv::TNVInputEvents, tInput) //触控信息
	*/
	Ev_NvApi_Base_SendInputEvent_Ntf,

	/**
	@brief    发送无线投屏列表
	
	BODY(nv::TNVLoginInfos, tLogins) //列表信息
	*/
	Ev_NvApi_Base_SendQuickShareList_Ntf,

	/**
	@brief    发送触控信息给无线投屏
	
	BODY(nv::TNVInputEvents, tInput) //触控信息
	*/
	Ev_NvApi_Base_SendInputEventToQuickShare_Ntf,

	/**
	@brief   无线投屏发送本地rtp地址和端口响应
	*/
	Ev_NvApi_Base_SendQuickShareSendAddr_Ntf,
	
	/**
	@brief   无线投屏主动切源响应
	BODY(nv::TS32, reason) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvViewReason
	*/
	Ev_NvApi_Base_QuickShareViewPic_Ntf,	

	/**
	@brief   无线投屏主动停止投屏响应
	BODY(nv::TS32, pic) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvImixVidSrcType
	BODY(nv::TS32, reason) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvViewReason
	*/
	Ev_NvApi_Base_QuickShareViewPicStop_Ntf,
	
	/**
	@brief    Imix 主动发送本地rtp地址和端口给无线投屏
	
	BODY(nv::TNVRtpRtcpPair, tAddr) //视频地址
	BODY(nv::TNVRtpRtcpPair, tAddr) //音频地址
	*/
	Ev_NvApi_Base_SendImixRcvAddrToQuickShare_Ntf,

	/**
	@brief    Imix 主动给无线投屏发送关键帧的请求
	
	*/
	Ev_NvApi_Base_SendIFrameRequestToQuickShare_Ntf,

	/**
	@brief    Imix 主动给无线投屏停止发送码流
	
	*/
	Ev_NvApi_Base_StopTransferCodeStream_Ntf,
	
	/**
	@brief    设置显示器配置通知
	
	BODY(nv::TNVScreenParamList, screen)

	*/
	Ev_NvApi_Base_SetScreenCfg_Ntf,

	/**
	@brief    获取显示器配置通知
	
	BODY(nv::TNVScreenParamList, screen)

	*/
	Ev_NvApi_Base_GetScreenCfg_Rsp,

	/**
	@brief    终端版本信息通知
	
	BODY(nv::TNVTerminalInfo, terinfo)

	*/
	Ev_NvApi_Base_SetTerlInfoRt_Ntf,

	/**
	@brief    获取终端版本信息通知
	
	BODY(nv::TNVTerminalInfo, terinfo)

	*/
	Ev_NvApi_Base_GetTerlInfoRt_Rsp,

	/**
	@brief    设置显示器屏数通知
	
	BODY(nv::TU32, screen)

	*/
	Ev_NvApi_Base_SetScreenNumCfg_Ntf,

	/**
	@brief    获取显示器屏数通知
	
	BODY(nv::TU32, screen)

	*/
	Ev_NvApi_Base_GetScreenNumCfg_Rsp,

	/**
	@brief    设置共享通知
	
	BODY(nv::TBOOL32, tbCfg)

	*/
	Ev_NvApi_Base_SetIsSharing_Ntf,

	/***
	@brief    获取共享通知

	BODY(nv::TBOOL32, tbCfg)

	*/
	Ev_NvApi_Base_GetIsSharing_Rsp,

	/**
	@brief    设置显示器亮度通知
	
	BODY(nv::TBOOL32, result)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TU32, brightness)

	*/
	Ev_NvApi_Base_SetTvBrightness_Rsp,

	/**
	@brief    设置显示器对比度通知
	
	BODY(nv::TBOOL32, result)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TU32, contrast)

	*/
	Ev_NvApi_Base_SetTvContraste_Rsp,

	/**
	@brief    设置显示器饱和度通知
	
	BODY(nv::TBOOL32, result)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TU32, saturation)

	*/
	Ev_NvApi_Base_SetTvSaturation_Rsp,
	/**
	@brief    设置显示器清晰度通知
	
	BODY(nv::TBOOL32, result)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TU32, clarity)

	*/
	Ev_NvApi_Base_SetTvClarity_Rsp,

	/**
	@brief    设置显示器色温通知
	
	BODY(nv::TBOOL32, result)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TS32, color_temp)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenColorTemperature

	*/
	Ev_NvApi_Base_SetTvColortemp_Rsp,

	/**
	@brief    设置显示器显示比例通知
	
	BODY(nv::TBOOL32, result)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TS32, displayratio)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvTvDisplayRatio

	*/
	Ev_NvApi_Base_SetTvDisplayratio_Rsp,

	/**
	@brief    视频源分辨率上报
	
	BODY(nv::TNVVidInPortResInfoList, src_info_list)

	*/
	Ev_NvApi_Base_NvmpVidSrcStatus_Ntf,

	/**
	@brief    视频源分辨率上报
	
	BODY(nv::TNVVidInPortResInfoList, src_info_list)

	*/
	Ev_NvApi_Base_NvmpVidSrcStatus_Rsp,

	/**
	@brief    当前画面内容上报
	
	BODY(nv::TS32, pic) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvImixVidSrcType

	*/
	Ev_NvApi_Base_PicStatus_Ntf,

	/**
	@brief    获取音频输出音量响应
	
	BODY(nv::TU32, vol)

	*/
	Ev_NvApi_Base_CodecGetAudOutVol_Rsp,

	/**
	@brief    获取音频输出音量响应
	
	BODY(nv::TU32, vol)

	*/
	Ev_NvApi_Base_CodecAudOutVol_Ntf,

	/**
	@brief    获取静音状态请求响应
	
	BODY(nv::TBOOL32, is_quiet)

	*/
	Ev_NvApi_Base_CodecQuiet_Rsp,

	/**
	@brief    静音状态通知
	
	BODY(nv::TBOOL32, is_quiet)

	*/
	Ev_NvApi_Base_CodecQuiet_Ntf,

	/***
	@brief    视频源信号通知

	BODY(nv::TNVImixVidSrcSignalList, src_list)

	*/
	Ev_NvApi_Base_ImixVidSrcSignalRt_Ntf,

	/***
	@brief    视频源信号通知

	BODY(nv::TNVImixVidSrcSignalList, src_list)

	*/
	Ev_NvApi_Base_GetImixVidSrcSignalRt_Rsp,

	/***
	@brief    更新状态变化通知

	BODY(nv::TBOOL32, status)

	*/
	Ev_NvApi_Base_SysUpgradeStatRt_Ntf,

	/***
	@brief    关机响应

	BODY(nv::TS32, reason) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvPowerTurnOffReason

	*/
	Ev_NvApi_Base_PowerTurnOff_Ntf,

	/**
	@brief    设置全屏通知
	
	BODY(nv::TBOOL32, is_full)

	*/
	Ev_NvApi_Base_SetFullScreen_Ntf,

	/**
	@brief    获取全屏设置响应
	
	BODY(nv::TBOOL32, is_full)

	*/
	Ev_NvApi_Base_GetFullScreen_Rsp,
	
	/***
	@brief    拍摄快照响应

	BODY(nv::TU32, snapshot_state) //快照拍摄状态 0：成功 1：失败
	BODY(nv::TString, snapshot_name) //快照全路径名字
	BODY(nv::TS32, codec_id) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvCodecComponentIndex

	*/
	Ev_NvApi_Base_CodecSnapshot_Rsp,

	/***
	@brief    关机请求

	*/
	Ev_NvApi_Base_PowerTurnOff_Rsp,

	/***
	@brief    音频输入信号回复
	BODY(nv::TNVAudInPowerList, aud_list) //音频信号列表
	*/
	Ev_NvApi_Base_CodecGetAllAudInPower_Ntf,
	/**		
	@brief   当前呼叫方式上报
	
	BODY(nv::TBOOL32, answercallmode)	//枚举值统一使用nv::TBOOL32

	*/
	Ev_NvApi_Base_AnSwerCallMode_Ntf,

/**		
	@brief    获取hdmi开关
	
	BODY(nv::TBOOL32, tb)
	*/
	Ev_NvApi_Base_GetHdmiSwitchCfg_Rsp,

	/**		
	@brief    获取hdmi开关
	
	BODY(nv::TBOOL32, tb)
	*/
	Ev_NvApi_Base_GetHdmiSwitchCfg_Ntf,

	/**	
	@brief    获取终端时间响应
	
	BODY(nv::TU32, result)
	BODY(nv::TNVTime, tmttime )
	*/
	Ev_NvApi_Base_GetMtSysDataTime_Rsp,

	/**	
	@brief    设置终端当前日期时间信息响应
	
	BODY(nv::TU32, result)
	BODY(nv::TNVTime, tmttime )
	*/
	Ev_NvApi_Base_SetMtSysDataTimeResult_Rsp,

	/**	
	@brief    设置终端当前日期时间通知
	BODY(nv::TNVTime, tmttime )
	*/
	Ev_NvApi_Base_SetMtSysDataTime_Ntf,

	/**	
	@brief    设置终端时间配置通知
	BODY(nv::TNVCfgMtSystemTime, tmttime )
	*/
	Ev_NvApi_Base_SetMtSysTimeCfg_Ntf,

	/**	
	@brief     设置终端时间配置通知
	BODY(nv::TNVCfgMtSystemTime, tmttime )
	*/
	Ev_NvApi_Base_GetMtSysTimeCfg_Rsp,
	/**	
	@brief     设置显示1080P蓝色底图	
	*/
	Ev_NvApi_Base_SetBluePic_Ntf,
	/**	
	@brief     设置显示Osd	
	*/
	Ev_NvApi_Base_SetOsd_Ntf,
	/**	
	@brief     设置IP	
	*/
	Ev_NvApi_Base_SetIp_Ntf,
	/**	BODY(nv::TNVNetUsedInfo, tUsedInfo )
	@brief     Ping包请求	
	*/
	Ev_NvApi_Base_Ping_Req,
	/**	
	@brief     Ping包结果回复	
	*/
	Ev_NvApi_Base_Ping_Nty,

	/**	
	@brief     设置非1080分辨率时显示策略回复
	BODY(nv::TS32, mode )
	*/
	Ev_NvApi_Base_SetVidResResizeModeCfg_Ntf,

	/**	
	@brief     查询非1080分辨率时显示策略回复
	BODY(nv::TS32, mode )
	*/
	Ev_NvApi_Base_GetVidResResizeModeCfg_Rsp,
	/**	
	@brief     回复出厂设置通知	
	*/
	Ev_NvApi_Base_SetDefault_Nty,
	/**	
	@brief     生产测试通知	
	*/
	Ev_NvApi_Base_NVMfTest_Ntf,

	/**	
	@brief     获取当前日期时间信息通知	
	BODY(nv::TU32, result)
	BODY(nv::TNVTime, tmttime )
	*/
	Ev_NvApi_Base_GetSysDataTime_Rsp,

	/**	
	@brief    无最新版本信息通知，且对应于Ev_NV_UpgradeNoVersion_Ntf	
	
	*/
	Ev_NvApi_Base_NoVersion_Ntf,

	/**	
	@brief    最新版本信息通知，且对应于Ev_NV_UpgradeVersionInfo_Ntf
	
	BODY(TNVDevUpgrade, ver_info)
	*/
	Ev_NvApi_Base_AutoUpgradeVersion_Ntf,
	
	/**
	@brief     设置终端双流源显示位置回复
	BODY(nv::TBOOL32, bleft )
	*/
	Ev_NvApi_Base_SetIsMtDualLeftCfg_Ntf,

	/**
	@brief     设置终端双流源显示位置回复
	BODY(nv::TBOOL32, bleft )
	*/
	Ev_NvApi_Base_GetIsMtDualLeftCfg_Rsp,

	/**
	@brief     当前终端主视频显示画面通知
	BODY(nv::TS32, pic)
	*/
	Ev_NvApi_Base_SetMtPic_Ntf,

	/**
	@brief     获取终端主视频显示画面回复
	BODY(nv::TS32, pic)
	*/
	Ev_NvApi_Base_GetMtPic_Rsp,

	/***
	@brief   发送无线投屏版本
	BODY(nv::TString, quickshare_version) 

	*/
	Ev_NvApi_Base_SendQuickShareVersion_Ntf,

	/***
	@brief   无线投屏版本升级进度
	BODY(nv::TU32， quickshare_downloadprogress) 

	*/
	Ev_NvApi_Base_QuickShareDownloadProgress_Ntf,

	/***
	@brief   发送无线投屏升级结果
	BODY(nv::TBOOL32, is_upgradesucess) 

	*/
	Ev_NvApi_Base_QuickShareUpgradeResult_Ntf,
	/***
	@brief     待机状态请求回复
	BODY(nv:TBOOL32,  bsleep)
	*/
	Ev_NvApi_Base_GetCodecDspSleep_Rsp,

	/***
	@brief     设置播放设备的显示比例回复
	BODY(nv::TS32, zoon)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvZoomMode
	*/
	Ev_NvApi_Base_CodecSetPlayZoomMode_Ntf,

	/***
	@brief     获取播放设备的显示比例回复
	BODY(nv::TS32, zoon)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvZoomMode
	*/
	Ev_NvApi_Base_CodecGetPlayZoomMode_Rsp,

	/**
	@brief   无线投屏主动切源响应
	BODY(nv::TS32, reason) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvViewReason
	*/
	Ev_NvApi_Base_QuickShareViewPre_Ntf,
	
	/**
	@brief   终端程序全部启动成功通知
	*/
	Ev_NvApi_Base_HDMtStartSucess_Ntf,

	/**
	@brief   查询终端名字响应
	BODY(nv::TNVTerminalName, name)
	*/
	Ev_NvApi_Base_GetTerminalName_Rsp,

	/**
	@brief   终端名字通知
	BODY(nv::TNVTerminalName, name)
	*/
	Ev_NvApi_Base_SetTerminalName_Ntf,

	/**
	@brief   查询终端程序是否全部启动成功请求
	BODY(nv:TBOOL32,  bsuc)
	*/
	Ev_NvApi_Base_InquireHDMtStartSucess_Rsp,

	/**
	@brief   当前正在唤醒，不允许待机	
	*/
	Ev_NvApi_Base_NotSleep_Nty,
	/**
	@brief   当前正在待机，不允许唤醒	
	*/
	Ev_NvApi_Base_NotWake_Nty,

	/**
	@brief   视频源不是1080	
	BODY(nv::TS32, port)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvImixVidSrcType
	*/
	Ev_NvApi_Base_CodecVidResIsNot1080_Nty,

	/**
	@brief   小图像通知
	BODY(nv::TNVMiniVidInfo, info)
	*/
	Ev_NvApi_Base_SetMiniVidInfoRt_Ntf,

	/**
	@brief   小图像通知
	BODY(nv::TNVMiniVidInfo, info)
	*/
	Ev_NvApi_Base_GetMiniVidInfoRt_Rsp,

	/**
	@brief   版本信息通知
	BODY(nv::TNVImixVerInfo, info)
	*/
	Ev_NvApi_Base_GetImixVerInfoRt_Rsp,

	/**
	@brief   设置终端NAT响应
	*/
	Ev_NvApi_Base_SetTerNatIpCfg_Rsp,

	/**
	@brief   视频冻结状态查询回复
	BODY(nv::TU32, Freeze)
	*/
	Ev_NvApi_Base_CodecGetVidFreezePrm_Rsp,

	/**
	@brief   打开关闭电视机无信号通知
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::BOOL32, open)
	*/
	Ev_NvApi_Base_SetTvSignal_Ntf,

	/**
	@brief   IMIX版本查询回复
	BODY(nv::TString, tMode)
	*/
	Ev_NvApi_Base_ImixMode_Rsp,
	/**
	@brief	通知UI当前pc软件状态
	BODY(nv::BOOL32, NtState)
	*/
	Ev_NvApi_Base_NotifyImixNTState_Nty,

	/**
	@brief	画面选看状态通知
	BODY(nv::TBOOL32, bstart) TRUE：开始切换画面 FALSE：结束画面切换
	*/
	Ev_NvApi_Base_ViewPicState_Nty,

	/**
	@brief   设置终端自动待机通知
	*/
	Ev_NvApi_Base_SetTerAutoSleep_Nty,

	/**
	@brief   查询终端自动待机回应
	*/
	Ev_NvApi_Base_GetTerAutoSleep_Rsp,

	/**
	@brief	退出批注原因通知
	BODY(nv::TS32, reason) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvLeaveDrawReason	
	*/
	Ev_NvApi_Base_LeaveDrawReason_Nty,

	/**
	@brief	双流发送失败原因通知
	BODY(nv::TS32, reason) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvHintCode	
	*/
	Ev_NvApi_Base_SendDualFailReason_Nty,
	
	/**
	@brief	解码器异常通知
	*/
	Ev_NvApi_Base_CodecError_Nty,

	/**
	@brief	imix收到qk心跳通知后的消息通知
	*/
	Ev_NvApi_Base_ImixSendToQKHeartBeat_Nty,

	/**
	@brief	imix通知界面无线投屏播放ppt状态
	BODY(nv::TBOOL32, tIsView)0：不看ppt，1：看ppt
	*/
	Ev_NvApi_Base_QKIsViewPPT_Nty,

	/**
	@brief	imix发送无线投屏ppt翻页命令
	BODY(nv::TS32, tPageTurn)该处实际为nv::EmNvPPTPageTurning
	*/
	Ev_NvApi_Base_SendPPTPageTurn_Cmd,

	/**
	@brief	imix回应界面是否开始关机倒计时
	*BODY(nv::TBOOL32, tIsStart)
	*BODY(nv::TS32, tReason)该处实际为nv::EmNvAutoShutdownFailReason
	*/
	Ev_NvApi_Base_StartShutdownCount_Rsp,

	/**
	@brief	imix每秒通知界面关机倒计时
	*BODY(nv::TBOOL32, tIsCount)是否继续倒计时
	*BODY(nv::TS32, tReason)该处实际为nv::EmNvAutoShutdownFailReason
	*/
	Ev_NvApi_Base_ShutdownCount_Nty,

	/**
	@brief	imix回应qk版本信息
	*BODY(nv::TString, version)投屏器版本
	*/
	Ev_NvApi_Base_GetQkVersion_Rsp,

	/**
	@brief	imix通知界面一键升级包的子包
	*BODY(nv::TNVAllUpgradePackageContent, upgrade_package)
	*/
	Ev_NvApi_Base_AllUpgradePackageContent_Ntf,

	/**
	@brief	imix通知界面开始升级路由器
	*BODY(nv::TNVAllUpgradePackageContent, upgrade_package)
	*/
	Ev_NvApi_Base_StartUpgradeRouter_Ntf,

	/**
	@brief	获取终端ip回应
	*BODY(nv::TNVString, tTerip)
	*/
	Ev_NvApi_Base_GetTerIp_Rsp,

	/**
	@brief	总开关开机100s内再次按压时通知
	*
	*/
	Ev_NvApi_Base_SwbRepeatTurnOn_Nty,

	/**
	@brief   nv版本信息回应
	BODY(nv::TString, imix_ver)
	*/
	Ev_NvApi_Base_GetNvVerInfo_Rsp,

	/**
	@brief   终端硬件信息回应
	BODY(nv::TNVHWInfo, HWInfo)
	*/
	Ev_NvApi_Base_GetTerHWInfo_Nty,

	/**
	@brief   终端播放本地声音通知
	BODY(nv::TNVMtLocalSoundPaly, tPlayInfo)
	*/
	Ev_NvApi_Base_LocalSoundPlay_Nty,

	/**
	@brief   终端音频输出诊断通知
	BODY(nv::TNVMtAudioPower, tPower)
	*/
	Ev_NvApi_Base_TerAudioOutPowerTest_Nty,

	/**
	@brief   终端音频输入诊断通知
	BODY(nv::TNVMtAudioPower, tPower)
	*/
	Ev_NvApi_Base_TerAudioInPowerTest_Nty,

	/**
	@brief   终端音频输入接口状态回应
	BODY(nv::TNVMtMutiAudInState, tState)
	*/
	Ev_NvApi_Base_TerAudioInputState_Rsp,

	/**
	@brief   获取登录APS所需要的参数请求
	BODY(nv::TNVApsLoginParam, tParam)
	*/
	Ev_NvApi_Base_GetLoginApsParamCfg_Rsp,

	/**
	@brief   获取呼叫协议类型配置回应
	BODY(nv::TS32, emType) 此处实际为nv::EmMtConfProtocol,协议类型
	*/
	Ev_NvApi_Base_GetCallProtocolCfg_Rsp,

	/**
	@brief   获取XAPList配置回应
	BODY(nv::TNVMtXAPSvrList, tSrvList)
	*/
	Ev_NvApi_Base_GetXAPListCfg_Rsp,

	/**
	@brief   获取H323代理配置回应
	BODY(nv::TNVH323PxyCfg, tCfg)
	*/
	Ev_NvApi_Base_GetH323PxyCfg_Rsp,

	/**
	@brief   获取手动设置的gk地址回应
	BODY(nv::TNVMtCSUAddr, tCfg)
	*/
	Ev_NvApi_Base_GetGKCfg_Rsp,

	/**
	@brief   获取手动设置Sip服务器的配置回应
	BODY(nv::TNVSipSrvCfg, tCfg)
	*/
	Ev_NvApi_Base_GetManuSipSvrCfg_Rsp,

	/**
	@brief   获取是否允许登陆平台服务回应
	BODY(nv::TBOOL32, tLogin)
	*/
	Ev_NvApi_Base_GetLoginPlatformSrvCfg_Rsp,

	/**
	@brief   获取是否强制设置H323协议类型回应
	BODY(nv::TBOOL32, tFoeceSet)
	*/
	Ev_NvApi_Base_GetForceH323StackCfg_Rsp,

	/**
	@brief   查询账号详细信息回应
	BODY(nv::TNVMtAccountManager, tInfo)
	*/
	Ev_NvApi_Base_GetAccountInfo_Rsp,

	/**
	@brief   是否允许登陆平台服务通知
	BODY(nv::TBOOL32, tLogin)
	*/
	Ev_NvApi_Base_SetLoginPlatformSrvCfg_Ntf,

	/**
	@brief   APS登陆结果响应
	BODY(nv::TNVMtApsLoginErrcode, tLogin)
	BODY(nv::TU32, tIP)
	*/
	Ev_NvApi_Base_ApsLoginResult_Ntf,

	/**
	@brief   强制设置H323协议类型(标准/非标)通知
	BODY(nv::TBOOL32, tForce)
	*/
	Ev_NvApi_Base_ForceSet323StackCfg_Ntf,

	/**
	@brief   设置XAPList配置通知
	BODY(nv::TNVMtXAPSvrList, tParam)
	*/
	Ev_NvApi_Base_SetXAPListCfg_Ntf,

	/**
	@brief   设置H323代理命令通知
	BODY(nv::TNVH323PxyCfg, tParam)
	*/
	Ev_NvApi_Base_SetH323PxyCfg_Ntf,

	/**
	@brief   设置H460代理通知
	BODY(nv::TNVH460PxyCfg, tParam)
	*/
	Ev_NvApi_Base_SetH460Cfg_Ntf,

	/**
	@brief   获取H460代理参数响应
	BODY(nv::TNVH460PxyCfg, tParam)
	*/
	Ev_NvApi_Base_GetH460Cfg_Rsp,

	/**
	@brief   注册Sip服务器配置通知
	BODY(nv::TNVSipSrvCfg, tParam)
	*/
	Ev_NvApi_Base_SetSipSvrCfg_Ntf,

	/**
	@brief   获取音频输入接口响应
	BODY(nv::TNVMtAudInPortList, tParam)
	*/
	Ev_NvApi_Base_GetAudInPortListCfg_Rsp,

	/**
	@brief   呼叫码率通知
	BODY(nv::TNVMtCallBitRate, tRate)
	*/
	Ev_NvApi_Base_SetCallBitRateCfg_Ntf,

	/**
	@brief   获取呼叫码率响应
	BODY(nv::TNVMtCallBitRate, tRate)
	*/
	Ev_NvApi_Base_GetCallBitRateCfg_Rsp,

	/**
	@brief   设置声音时延检测通知
	BODY(nv::TU32, tState)    state(EmMtAudioDelayCheckState)：检测状态
	BODY(nv::TU32, tResult)   当EmMtAudioDelayCheckState为emAudioDelayChecked时，此值有效，表示时延值
	                          当EmMtAudioDelayCheckState为emAudioDelayFailed时，此值有效，表示失败错误码
	*/
	Ev_NvApi_Base_AutoAudioDelayCheck_Ntf,

	/**
	@brief   获取服务器登录状态响应
	BODY(nv::TNVMtSvrStateList, tList)
	*/
	Ev_NvApi_Base_GetSvrStateList_Rsp,

	/*
	@brief   呼叫协议注册结果通知
	BODY(nv::TS32, tProtocol)            nv::EmMtConfProtocol 呼叫协议类型
	BODY(nv::TS32, tRegFailReason)       nv::EmMtRegFailedReason 注册成功或失败原因
	*/
	Ev_NvApi_Base_TerRegResult_Ntf,

	/**
	@brief   设置CSU配置通知
	BODY(nv::TNVMtCSUAddr, tAddr)
	*/
	Ev_NvApi_Base_SetCSUCfg_Ntf,

	/**
	@brief   查询SDI接口数量回应
	BODY(nv::TS32, tType)
	*/
	Ev_NvApi_Base_GetTerSdiInOut_Rsp,

	/**
	@brief   查询麦克风连接状态回应
	BODY(nv::TNVMtAllMicStatus, tStatus)
	*/
	Ev_NvApi_Base_GetMicrophoneConnectStatus_Rsp,

	/**
	@brief   麦克风连接状态通知
	BODY(nv::TNVMtAllMicStatus, tStatus)
	*/
	Ev_NvApi_Base_MicrophoneConnectStatus_Ntf,

	/**
	@brief   获取第一路主视频输入端口回应
	BODY(nv::TNVMtHDVidInPort, tPort)
	*/
	Ev_NvApi_Base_GetPri1stVidInPortCfg_Rsp,

	/**
	@brief   获取辅视频输入端口回应
	BODY(nv::TNVMtHDVidInPort, tPort)
	*/
	Ev_NvApi_Base_GetAssVidInPortCfg_Rsp,

	/**
	@brief   获取第二路主辅视频输入端口回应
	BODY(nv::TNVMtHDVidInPort, tPort)
	*/
	Ev_NvApi_Base_GetPri2ndVidInPortCfg_Rsp,

	/**
	@brief   获取第二路主辅视频输入端口回应
	BODY(nv::TNVMtAudInPortList, tList)
	*/
	Ev_NvApi_Base_SetAudInPortListCfg_Ntf,

	/**
	@brief	总开关在系统开机时按键小于3秒通知
	*
	*/
	Ev_NvApi_Base_SwbKey_Nty,

	/**
	@brief	imix回应qk终端别名
	*BODY(nv::TString, strTerName)终端版本信息
	*/
	Ev_NvApi_Base_QkGetTerName_Rsp,

	/**
	@brief	pad版本号请求回应
	*BODY(nv::TString, strTerName)pad版本号
	*/
	Ev_NvApi_Base_GetPadVersion_Rsp,

	/**
	@brief	通知imix恢复出厂设置
	*/
	Ev_NvApi_Base_ResetImixSys_Ntf,

	/**
	@brief	终端是否注册GK回应
	*BODY(nv::TBOOL32, tIsRegist)是否注册
	*/
	Ev_NvApi_Base_GetGKRegistRt_Rsp,

	/**
	@brief	终端是否注册Sip回应
	*BODY(nv::TBOOL32, tIsRegist)是否注册
	*/
	Ev_NvApi_Base_GetSipRegistRt_Rsp,

	/**
	@brief	设置ftp通知
	*BODY(nv::TBOOL32, tIsOpen)是否打开ftp
	*/
	Ev_NvApi_Base_OpenFtp_Nty,

	/**
	@brief	获取ftp状态回应
	*BODY(nv::TBOOL32, tIsOpen)是否打开ftp
	*/
	Ev_NvApi_Base_GetFtpState_Rsp,

	/**
	@brief	通知投屏器需要编码协商
	*/
	Ev_NvApi_Base_QKNeedCodeConsult_Ntf,

	/**
	@brief	投屏器编码参数
	*BODY(nv::TQKCodeParam, tParam)编码参数
	*/
	Ev_NvApi_Base_QKCodeParam_Cmd,

	/**
	@brief	投屏器编码分辨率
	*BODY(nv::TS32, tRes)编码分辨率
	*/
	Ev_NvApi_Base_QKCodeRes_Cmd,

	/**
	@brief	投屏器编码码率
	*BODY(nv::TU32, tFrame)编码帧率
	*/
	Ev_NvApi_Base_QKCodeFrameRate_Cmd,

	/**
	@brief	投屏器编码码率
	*BODY(nv::TU32, tRate)编码码率
	*/
	Ev_NvApi_Base_QKCodeBitRate_Cmd,

	/**
	@brief	通知界面是否需要清理data文件夹
	*BODY(nv::TBOOL32, tbNeed)TRUE: 不需要清理， FALSE:需要清理
	*/
	Ev_NvApi_Base_NeedClearDataFolder_Cmd,

	/**
	@brief	重置终端通知
	*BODY(nv::TBOOL32, tIsReset)TRUE: 终端重置， FALSE:终端未重置
	*/
	Ev_NvApi_Base_RestTer_Nty,

	/**
	@brief	终端遥控器音量控制通知
	*BODY(nv::TBOOL32, tbVolUp)TRUE: 音量+ FALSE: 音量-
	*/
	Ev_NvApi_Base_DeviceKeyVolume_Nty,

	/**
	@brief	imix连接终端回应
	*BODY(nv::TBOOL32, tbLogin)
	*/
	Ev_NvApi_Base_NVConnectTer_Rsp,

	/**
	@brief	通知界面设置功放结果
	*BODY(nv::TBOOL32, tbResult)
	*/
	Ev_NvApi_Base_SetAmplifierStatus_Ntf,

	/**
	@brief	通知界面设置本地回显结果
	*BODY(nv::TBOOL32, tbResult)
	*/
	Ev_NvApi_Base_SetImixLocalEcho_Ntf,

	/**
	@brief	imix与JD平台版本是否一致回应
	*BODY(nv::TBOOL32, tbSame)
	*/
	Ev_NvApi_Base_NVVerIsSameAsJDServer_Rsp,

	/**
	@brief	从JD平台下载版本进度通知
	*BODY(nv::TU32, tdwSchedule)
	*/
	Ev_NvApi_Base_NVDownloadFromJDServer_Nty,

	/**
	@brief	从JD平台下载版本结果通知
	*BODY(nv::TBOOL32, tbLogin)
	*/
	Ev_NvApi_Base_NVDownloadResultFromJD_Nty,

	EV_UI_END(NVAPI_BASE) = EVSEG_NVAPI_BASE_END
	
};

#define Is_NvApiBase_Msg(m) ((m) >= EV_UI_BGN(NVAPI_BASE) && (m) <= EV_UI_END(NVAPI_BASE))

/**@}*/

/**@}*/
#endif // _NVAPI_EVENT_BASE_H_
