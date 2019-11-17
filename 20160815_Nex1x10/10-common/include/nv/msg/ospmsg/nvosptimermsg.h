#ifndef _NVOSPTIMERMSG_H_
#define _NVOSPTIMERMSG_H_

#include "kdvtype.h"
#include "nvospmsgid.h"

//OSP的定时器消息统一在此定义
enum EmNvOspMsgTimer
{
	Ev_Nv_OspTimer_Start = EVSEG_NVOSPMSG_TIMER_BGN,

	/* 系统控制定时器 */
	Ev_Nv_SysCtrl_Timer_KeepAlive,      ///< 定时扫描各个子系统是否存活的定时器

	Ev_Nv_Timer_KeepAlive,				///< 每个模块定时扫描上报自己是存活的

	Ev_Nv_Timer_OperationCount,        ///< 用于判断待机用的定时器
	Ev_Nv_Timer_ConnectTer,            ///< 用于定时链接x500终端定时器
	Ev_Nv_Timer_RegUpdateSer,          ///<用于注册升级服务器定时器

	Ev_Nv_Timer_UpgradeFileDownload,   ///<用于定时下载升级文件定时器
	Ev_Nv_Timer_CheckQuickShareUpdate,	//<用于定时检测无线投屏升级进度
	Ev_Nv_Timer_AutoShutDownCount,      //<用于定时关机倒计时定时器>
	Ev_Nv_Timer_AllUpgradeState,        //用于检测一键升级的状态
	//kdvquickshare相关
	Ev_Nv_Timer_QuickShareConnectImix, /*< 用于定时链接imix终端定时器*/
	Ev_Nv_Timer_FlashControl,		   /*用于发射器灯光1s闪烁控制*/ 
	Ev_Nv_Timer_QuickShareSendPcName,  /*用于发射器发送PC名字给Imix*/ 
	Ev_Nv_Timer_MtDualVidSrc,   //用于终端双流检测
	Ev_Nv_Timer_MtDualVidSrcSignal,   //用于终端双流检测是否有源
	Ev_Nv_Timer_GetTerminalIp,  /*用于获取终端设备信息*/
	Ev_Nv_Timer_WakeUpProtect,  /*唤醒保护*/
	Ev_Nv_Timer_SleepProtect,  /*待机保护*/
	Ev_Nv_Timer_GetMtVidSrcResWaiting,  /*获取终端源分辨率等待时间x300需要*/
	Ev_Nv_Timer_GetSendDualState, /*发送双流请求后通过查询双流状态来判断*/
	Ev_Nv_Timer_QuickShareHeatToPc, /*用于定时发心跳包给PC软件*/
	Ev_Nv_Timer_QuickShareChecKWifiState, /*用于判断是否wifi处于假死状态*/
	Ev_Nv_Timer_QuickShareFlashChecKWifiState, /*用于判断是否wifi处于假死状态*/
	Ev_Nv_Timer_QuickShareUsbChecKWifiState, /*用于判断是否wifi处于假死状态*/
	Ev_Nv_Timer_CodecErrorViewPic, //解码出错重启后画面切换
	//Ev_Nv_Timer_QuickShareHeartToImix, /*用于定时发心跳包给Imix*/
	//serviceconf相关
	Ev_Nv_Timer_WhiteBoard,        //远程白板定时器，在5s内有双流时不切换双流画面
	Ev_Nv_Timer_ChanceTvQuite,//取消电视机静音定时器
	Ev_Nv_Timer_ChangeEchoOrDual,        //切终端源（包括回显和双流源）的定时器
	Ev_Nv_Timer_CloseHDMI0ToRecDule,     //接收双流先让imix输出到电视机黑屏的定时器
	Ev_Nv_Timer_SetMulConfPip,     //多点会议时，开启终端自动多画面合成定时器

	Ev_Nv_Timer_RcvDualTimer,       //接收双流定时器
	Ev_Nv_Timer_X700ChangeLocalEcho,       //x700在入会时切回显的定时器
	Ev_Nv_Timer_QKConnectImixFail, /*< 定时监测投屏器连接终端是否失败*/
};

#endif