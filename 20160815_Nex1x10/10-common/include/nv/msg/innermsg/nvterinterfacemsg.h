#ifndef _NVTERINTERFACEMSG_H_
#define _NVTERINTERFACEMSG_H_

#include "nvmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmNvTerinterfaceMsg
{
    EV_BGN(TERINTERFACE) = EVSEG_TERINTERFACE_BGN,
#endif//_MESSAGE_HELP_
	
	/*<<登入终端状态上报>>
	* is_login ：是否登入终端成功
	*消息流向 nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_MTCLogin_Ntf)         
	BODY(NV::TBOOL32, is_login) 
	
	/*<<待机请求>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*/
    MESSAGE(Ev_NV_CodecDspSleep_Req)
	
	/*<<待机请求>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*/
    MESSAGE(Ev_NV_CodecDspSleep_Cmd)

	/*<<唤醒命令>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*/
    MESSAGE(Ev_NV_CodecDspWakeup_Cmd)

	/*<<待机状态上报>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*is_sleep : TRUE琛ㄧず杩涘叆鐫＄湢鐘舵�侊紝FALSE琛ㄧず杩涘叆鍞ら啋鐘舵�?
	*/
    MESSAGE(Ev_NV_CodecSleepState_Ntf)
	BODY(nv::TBOOL32, is_sleep)
	
	/*<<待机响应>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	* is_sucess: 是否允许待机
	* fail_reason: 待机失败原因
	*/
    MESSAGE(Ev_NV_CodecDspSleep_Rsp)
	BODY(nv::TBOOL32, is_sucess)
	BODY(nv::TS32, fail_reason) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvSleepFailReason
	
	/*<<待机失败原因上报>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*fail_reason : 失败原因
	*/
    MESSAGE(Ev_NV_CodecSleepFailReason_Ntf)
	BODY(nv::TS32, fail_reason) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvSleepFailReason
	
	/*<<向ui发送待机倒计时通知>>
	* nvterinterface==>dispatch==>nvservice
	*count_down : 倒计时时间
	*/
	MESSAGE(Ev_NV_SleepCountDown_Ntf)
	BODY(nv::TU16, count_down)	//倒计时时间
	
	/*<<当前的呼叫状态上报>>
	* callsate ：上报的呼叫参数
	*消息流向 nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_CallLinkState_Ntf)         //post to UI  当前呼叫状态
	BODY(nv::TS32, callsate)	//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvCallState
	BODY(nv::TString, peeralias)
	
	/*<<当前的双流状态上报>>
	* is_senddual ：是否发送双流
	*消息流向 nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_AssSndSream_Status_Ntf)         
	BODY(NV::TBOOL32, is_senddual)
	BODY(NV::TS32, vid_lab) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvVidLabel		
	
	/*<<当前的双流状态上报>>
	* is_rcvdual ：是否接收双流
	*消息流向 nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_AssRcvSream_Status_Ntf)         
	BODY(NV::TBOOL32, is_rcvdual) 
	
	/*<<请求当前辅流发送状态>>
	* 消息流向 ：nvservice==>dispatch==>nvterinterface
	*/
	MESSAGE( Ev_NV_AssSndSream_Status_Req)
	

	/*<<请求当前辅流接收状态>>
	* 消息流向 ：nvservice==>dispatch==>nvterinterface
	*/
	MESSAGE( Ev_NV_AssRcvSream_Status_Req)             
	
	/*<<当前的呼叫状态请求>>
	*消息流向 ：nvservice==>dispatch==>nvterinterface
	*/
	MESSAGE( Ev_NV_CallLinkState_Req)
	
	/*<<界面同步命令>>
	* reason 同步原因
	* 消息流向 nvservice==>dispatch==>nvterinterface
	*/
	MESSAGE( Ev_NV_UISynchronize_Cmd)           //界面同步命令
	BODY(nv::TS32,       reason)            //同步原因  枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvUISynchronizeReason

	/*<<用于界面同步>> 
	* reason 同步原因
	* 消息流向 nvterinterface==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_UISynchronize_Ntf)        //用于界面同步
	BODY(nv::TS32,       reason)            //同步原因  枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvUISynchronizeReason
	
	/*<<当前的登入终端哑音状态请求>>
	*消息流向 ：nvservice==>dispatch==>nvterinterface
	*/
	MESSAGE( Ev_NV_CodecGetLocalMicMute_Req)
	
	/*<<当前哑音状态上报>>
	* is_mute ：是否哑音
	*消息流向 nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_CodecMute_Ntf)         
	BODY(NV::TBOOL32, is_mute) 
	
	/*<<设置当前日期时间信息>>
	*BODY ：  tmttime 时间信息  
	*传输方向：nvservice==>dispatch==>nvterinterface
	*/
	MESSAGE(Ev_NV_SetMtSysDataTime_Req)
	BODY(nv::TNVTime, tmttime )
	
	
	/*<<设置当前日期时间信息响应>>
	*BODY ：   result 设置结果 0成功 其他错误码
	           tmttime 时间信息 
	*传输方向：nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_SetMtSysDataTimeResult_Rsp)
	BODY(nv::TU32, result)
	BODY(nv::TNVTime, tmttime )


    /*<<设置当前日期时间通知>>
	*BODY ：   tmttime 时间信息 
	*传输方向：nvterinterface ==>dispatch==>nvservice
	* see
	*/
	MESSAGE(Ev_NV_SetMtSysDataTime_Ntf)
	BODY(nv::TNVTime, tmttime )
	
	/*<<当前的双流状态上报>>
	* is_senddual ：是否发送双流
	*消息流向 nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_AssSndSream_Status_Rsp)         
	BODY(NV::TBOOL32, is_senddual)
	BODY(NV::TS32, vid_lab) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvVidLabel	
	
	/*<<当前的双流状态上报>>
	* is_rcvdual ：是否接收双流
	*消息流向 nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_AssRcvSream_Status_Rsp)         
	BODY(NV::TBOOL32, is_rcvdual) 
	
	/*<<当前的双流源状态上报>>
	* is_havesrc ：是否有源
	*消息流向 nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_AssVidSrc_Status_Ntf)         
	BODY(NV::TBOOL32, is_havesrc)
	
	/*<<video双流开或关命令>>
	* bOpen ：开或者关
	* 消息流向 ：nvservice==>dispatch==>nvterinterface
	*/
	MESSAGE( Ev_NV_VideoAssStream_Cmd )
	BODY(nv:TBOOL32,  bOpen)                       //true : open；  false: close
	
	/*<<系统关机命令>>
	*消息流向 nvterinterface ==>dispatch==>nvmp
	*/
	MESSAGE(Ev_NV_PowerTurnOff_Cmd)

	/*<<系统关机结果通知>>
	* reason ：结果通知
	*消息流向 nvmp ==>dispatch==>nvterinterface
	*/
	MESSAGE(Ev_NV_PowerTurnOff_Ntf)
	BODY(nv:TS32,  reason)       //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvPowerTurnOffReason

	MESSAGE(Ev_NV_SetPipMode_Req)
	BODY(nv:TS32,  pipmode)

	MESSAGE(Ev_NV_SetMartix_Req)	

	MESSAGE(Ev_NV_SetDualPort_Req)
	BODY(nv:TS32,  DualPort)	

	MESSAGE(Ev_NV_GetMartix_Req)

	MESSAGE(Ev_NV_GetSrcInfo_Req)

	/*<<当前的应答方式上报>>
	* bManuMode ：上报的应答方式
	*消息流向 nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_AnswerCallMode_Ntf)//post to UI  
	BODY(nv::TBOOL32, bManuMode)	
	
	/*<<当前的应答方式查询>>
	*消息流向 ：nvservice==>dispatch==>nvterinterface
	*/
	MESSAGE( Ev_NV_GetAnswerMode_Reg)

	MESSAGE( Ev_NV_AnswerCall_Req)//post to UI
	BODY(nv::TBOOL32, bAnswerCall)

	/*<<获取当前日期时间信息>>
	*传输方向：nvservice==>dispatch==>nvterinterface
	*/
	MESSAGE(Ev_NV_GetMtSysDataTime_Req)

	/*<<获取当前日期时间信息响应>>
	*BODY ：   result 设置结果 0成功 其他错误码
	           tmttime 时间信息 
	*传输方向：nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_GetMtSysDataTime_Rsp)
	BODY(nv::TU32, result)
	BODY(nv::TNVTime, tmttime )
	
	/*<<获取终端当前时间配置信息>>
	*传输方向：nvservice==>dispatch==>nvterinterface
	*/
	MESSAGE(Ev_NV_GetMtSysTimeCfg_Req)
	
	/*<<获取终端当前时间配置信息响应>>
	*BODY ： tmttime 时间信息
	*传输方向：nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_GetMtSysTimeCfg_Rsp)
	BODY(nv::TNVCfgMtSystemTime, tmttime )
	
	/*<<终端当前时间配置信息通知>>
	*BODY ： tmttime 时间信息
	*传输方向：nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_SetMtSysTimeCfg_Ntf)
	BODY(nv::TNVCfgMtSystemTime, tmttime )

	/*<<单屏直接强制设置看主视频>>
	*BODY ： tmttime 时间信息
	*传输方向：nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_SetOneMartix_Req)
	/*<<获取终端型号等信息>>
	*BODY ： tmttime 时间信息
	*传输方向：nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_GetMtModel_Req)
	/*<<终端控电视机待机>>
	*BODY ： tmttime 时间信息
	*传输方向：nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_SetTvSleep_Req)
	/*<<终端控电视机唤醒>>
	*BODY ： tmttime 时间信息
	*传输方向：nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_SetTvWake_Req)


	/*<<系统消息提示>>
	*BODY ： tSysHint 消息提示
	*传输方向：nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_MtSysHint_Ntf)
	BODY(nv::TS32, tSysHint ) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvHintCode
	
	/*<<当前的呼叫状态上报>>
	* callsate ：上报的呼叫参数
	*消息流向 nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_CallLinkState_Rsp)         //post to UI  当前呼叫状态
	BODY(nv::TS32, callsate)	//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvCallState
	BODY(nv::TString, peeralias)
	
	/*<<设置待机剩余时间命令（用于OSD与网呈IMIX的待机同步）>>
	*BODY ： time 待机剩余时间(秒), 注意:  wSleepRemainTime = 0，表示取消待机
	*nvservice ==>dispatch==>nvterinterface
	*/
	MESSAGE(Ev_NV_SetSleepReaminTime_Cmd)
	BODY(nv::TU16, time ) 
	
	/*<<终端程序全部启动成功通知>>
	*消息流向 nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_HDMtStartSucess_Ntf)      
	
	/*<<网呈IMIX通过该接口给终端发短消息(限制512字节)，终端接收短消息后显示在OSD上）>>
	*BODY ： LocSms 本地短消息
	*nvservice ==>dispatch==>nvterinterface
	*/
	MESSAGE(Ev_NV_SendLocalSms_Cmd)
	BODY(nv::TString, LocSms ) 
	
	/*<<查询终端名字>>
	*消息流向 ：nvservice==>dispatch==>nvterinterface
	*/
	MESSAGE( Ev_NV_GetTerminalName_Req)
	
	/*<<查询终端名字响应>>
	*BODY ：   name 终端名字
	*传输方向：nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_GetTerminalName_Rsp)
	BODY(nv::TNVTerminalName, name)
	
	/*<<终端名字通知>>
	*BODY ：   name 终端名字
	*传输方向：nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_SetTerminalName_Ntf)
	BODY(nv::TNVTerminalName, name)
	
	/*<<查询终端程序是否全部启动成功>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*/
    MESSAGE(Ev_NV_InquireHDMtStartSucess_Req)
	
	/*<<查询终端程序是否全部启动成功响应>>
	*消息流向 nvterinterface ==>dispatch==>nvservice
	*/
    MESSAGE(Ev_NV_InquireHDMtStartSucess_Rsp)
	BODY(nv:TBOOL32,  bsuc)

	MESSAGE(Ev_NV_PowerNotSleep_Ntf)

	MESSAGE(Ev_NV_InnerNotSleep_Ntf)
	
	/*<<会议状态通知>>
	*消息流向 nvterinterface ==>dispatch==>nvservice
	*/
    MESSAGE(Ev_NV_CalledNty_Ntf)
	BODY(nv:TBOOL32,  bcalled)

	MESSAGE(Ev_NV_SetMartix_Test)	

	/*<<唤醒请求>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*/
	MESSAGE(Ev_NV_CodecDspWakeup_Req)

	/*<<设置NAT地址>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*bEnable:是否启用NAT
	*dwIP:NAT IP地址
	*/
	MESSAGE(Ev_Nv_SetNatCfg_Cmd)
	BODY(nv::TBOOL32, bEnable)
	BODY(nv::TU32, dwIP)

	/*<<设置NAT地址响应>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*bResult:设置结果
	*bEnable:是否启用NAT
	*dwIP:NAT IP地址
	*/
	MESSAGE(Ev_Nv_SetNatCfg_Rsp)
	BODY(nv::TBOOL32, bResult)
	BODY(nv::TBOOL32, bEnable)
	BODY(nv::TU32, dwIP)

	/*<<设置终端画面合成是否显示本地双流源>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*bIsShow:TRUE：显示 FAULSE:隐藏
	*/
	MESSAGE(Ev_Nv_SetShowAssInVmp_Cmd)
	BODY(nv::TBOOL32, bIsShow)

	/*<<挂断终端会议>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*DisReason:挂断原因;EmMtCallDisReason_Api
	*/
	MESSAGE(Ev_NV_HangupConf_Cmd)
	BODY(nv::TS32, DisReason)

	/*<<设置终端是否自动待机>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*tcfg:自动待机信息
	*/
	MESSAGE(Ev_NV_SetAutoSleep_Cmd)
	BODY(nv::TNVMtAutoSleepCfg, tcfg)

	/*<<查询终端自动待机配置>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetAutoSleep_Req)

	/*<<设置终端是否自动待机通知>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tcfg:自动待机信息
	*/
	MESSAGE(Ev_NV_SetAutoSleep_Nty)
	BODY(nv::TNVMtAutoSleepCfg, tcfg)

	/*<<查询终端是否自动待机回应>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tcfg:自动待机信息
	*/
	MESSAGE(Ev_NV_GetAutoSleep_Rsp)
	BODY(nv::TNVMtAutoSleepCfg, tcfg)

	/*<<设置终端恢复出产设置>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*tDelcfg:是否删除配置文件
	*/
	MESSAGE(Ev_NV_ResetTerCfg_Cmd)
	BODY(nv::TBOOL32, tDelcfg)

	/*<<设置终端时间配置>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*tcfg:时间配置信息
	*/
	MESSAGE(Ev_NV_SetTerTimeCfg_Cmd)
	BODY(nv::TNVCfgMtSystemTime, tcfg)

	/*<<设置终端是否登录云平台>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*tLogin:TRUE:允许登录平台
	*/
	MESSAGE(Ev_NV_SetTerLoginPlatformSrvCfg_Cmd)
	BODY(nv::TBOOL32, tLogin)

	/*<<终端遥控器按键通知>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_DeviceKeyCode_Ntf)

	/*<<设置终端回到OSD界面命令>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_PressTerHomeButton_Cmd)

	/*<<设置终端本地声音播放>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*tSoundPlay:  播放本地声音信息
	*/
	MESSAGE(Ev_NV_TerLocalSoundPlay_Cmd)
	BODY(nv::TNVMtLocalSoundPaly, tSoundPlay)

	/*<<终端本地声音播放通知>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tSoundPlay:  播放本地声音信息
	*/
	MESSAGE(Ev_NV_TerLocalSoundPlay_Nty)
	BODY(nv::TNVMtLocalSoundPaly, tSoundPlay)

	/*<<终端音频输出测试>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*tCfg:  测试信息
	*/
	MESSAGE(Ev_NV_TerAudioOutPowerTest_Cmd)
	BODY(nv::TNVMtAudioTestCfg, tCfg)

	/*<<终端音频输入测试>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*tCfg:  测试信息
	*/
	MESSAGE(Ev_NV_TerAudioInPowerTest_Cmd)
	BODY(nv::TNVMtAudioTestCfg, tCfg)

	/*<<终端音频输出测试通知>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tPower:  音频输出音量
	*/
	MESSAGE(Ev_NV_TerAudioOutPowerTest_Nty)
	BODY(nv::TNVMtAudioPower, tPower)

	/*<<终端音频输入测试通知>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tPower:  音频输入音量
	*/
	MESSAGE(Ev_NV_TerAudioInPowerTest_Nty)
	BODY(nv::TNVMtAudioPower, tPower)

	/*<<终端音频输入接口状态查询请求>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*tSate:  状态
	*/
	MESSAGE(Ev_NV_TerAudioInputState_Req)
	BODY(nv::TNVMtMutiAudInState, tSate)

	/*<<终端音频输入接口状态查询回应>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tSate:  状态
	*/
	MESSAGE(Ev_NV_TerAudioInputState_Rsp)
	BODY(nv::TNVMtMutiAudInState, tSate)

	/*<<获取登录APS所需要的参数请求>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetLoginApsParamCfg_Req)

	/*<<获取登录APS所需要的参数回应>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tParm:  参数
	*/
	MESSAGE(Ev_NV_GetLoginApsParamCfg_Rsp)
	BODY(nv::TNVApsLoginParam, tParm)

	/*<<获取呼叫协议类型配置请求>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetCallProtocolCfg_Req)

	/*<<获取呼叫协议类型配置回应>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*emProtocal:  nv::EmMtConfProtocol,协议类型
	*/
	MESSAGE(Ev_NV_GetCallProtocolCfg_Rsp)
	BODY(nv::TS32, emProtocal)

	/*<<获取XAPList配置请求>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetXAPListCfg_Req)

	/*<<获取XAPList配置回应>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tSrvList:  XAPS服务器列表
	*/
	MESSAGE(Ev_NV_GetXAPListCfg_Rsp)
	BODY(nv::TNVMtXAPSvrList, tSrvList)

	/*<<获取H323代理配置请求>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetH323PxyCfg_Req)

	/*<<获取H323代理配置回应>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tCfg:  H323代理配置信息
	*/
	MESSAGE(Ev_NV_GetH323PxyCfg_Rsp)
	BODY(nv::TNVH323PxyCfg, tCfg)

	/*<<请求获取手动设置的gk地址>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetGKCfg_Req)

	/*<<获取手动设置的gk地址回应>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tCfg:  gk地址信息
	*/
	MESSAGE(Ev_NV_GetGKCfg_Rsp)
	BODY(nv::TNVMtCSUAddr, tCfg)

	/*<<获取手动设置Sip服务器的配置>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetManuSipSvrCfg_Req)

	/*<<获取手动设置Sip服务器的配置回应>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tCfg:  Sip服务器的配置
	*/
	MESSAGE(Ev_NV_GetManuSipSvrCfg_Rsp)
	BODY(nv::TNVSipSrvCfg, tCfg)

	/*<<获取是否允许登陆平台服务请求>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetLoginPlatformSrvCfg_Req)

	/*<<获取是否允许登陆平台服务回应>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tLogin: TRUE:登录，FALSE：未登录
	*/
	MESSAGE(Ev_NV_GetLoginPlatformSrvCfg_Rsp)
	BODY(nv::TBOOL32, tLogin)

	/*<<获取是否强制设置H323协议类型请求>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetForceH323StackCfg_Req)

	/*<<获取是否强制设置H323协议类型回应>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tForceSet: TRUE:强制设置，FALSE：非强制设置
	*/
	MESSAGE(Ev_NV_GetForceH323StackCfg_Rsp)
	BODY(nv::TBOOL32, tFoeceSet)

	/*<<查询账号详细信息请求>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetAccountInfo_Req)
	BODY(nv::TNVMtAccountManager, tInfo)

	/*<<查询账号详细信息回应>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tInfo: 账号详细信息
	*/
	MESSAGE(Ev_NV_GetAccountInfo_Rsp)
	BODY(nv::TNVMtAccountManager, tInfo)

	/*<<设置终端名称信息配置命令>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*tTerName: 终端名字
	*/
	MESSAGE(Ev_NV_SetTerminalNameCfg_Cmd)
	BODY(nv::TNVTerminalName, tTerName)

	/*<<是否允许登陆平台服务通知>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tLogin: TRUE:登录，FALSE：未登录
	*/
	MESSAGE(Ev_NV_SetLoginPlatformSrvCfg_Ntf)
	BODY(nv::TBOOL32, tLogin)

	/*<<设置登录APS所需要的参数命令>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*tParam: 参数
	*/
	MESSAGE(Ev_NV_SetLoginApsParamCfg_Cmd)
	BODY(nv::TNVApsLoginParam, tParam)

	/*<<APS登陆结果响应>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tLogin: 登录成功或失败原因
	*tIP: 
	*/
	MESSAGE(Ev_NV_ApsLoginResult_Ntf)
	BODY(nv::TNVMtApsLoginErrcode, tLogin)
	BODY(nv::TU32, tIP)

	/*<<强制设置H323协议类型(标准/非标)命令 >>
	*注：当自建终端登陆自荐平台时，界面设置enable为true时底下才会使用bstand的值
	*消息流向 nvservice==>dispatch==>nvterinterface
	*tParam: 参数
	*/
	MESSAGE(Ev_NV_ForceSet323StackCfg_Cmd)
	BODY(nv::TNVForceSetH323Stack, tParam)

	/*<<强制设置H323协议类型(标准/非标)通知>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tForce: TRUE：强制设置
	*/
	MESSAGE(Ev_NV_ForceSet323StackCfg_Ntf)
	BODY(nv::TBOOL32, tForce)

	/*<<设置XAPList配置命令 >>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*tParam: XAPList配置参数
	*/
	MESSAGE(Ev_NV_SetXAPListCfg_Cmd)
	BODY(nv::TNVMtXAPSvrList, tParam)

	/*<<设置XAPList配置通知>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tParam: XAPList配置参数
	*/
	MESSAGE(Ev_NV_SetXAPListCfg_Ntf)
	BODY(nv::TNVMtXAPSvrList, tParam)

	/*<<设置H323代理命令 >>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*tParam: H323配置参数
	*/
	MESSAGE(Ev_NV_SetH323PxyCfg_Cmd)
	BODY(nv::TNVH323PxyCfg, tParam)

	/*<<设置H323代理通知>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tParam: H323配置参数
	*/
	MESSAGE(Ev_NV_SetH323PxyCfg_Ntf)
	BODY(nv::TNVH323PxyCfg, tParam)

	/*<<设置H460代理命令 >>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*tParam: H460配置参数
	*/
	MESSAGE(Ev_NV_SetH460Cfg_Cmd)
	BODY(nv::TNVH460PxyCfg, tParam)

	/*<<设置H460代理通知>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tParam: H460配置参数
	*/
	MESSAGE(Ev_NV_SetH460Cfg_Ntf)
	BODY(nv::TNVH460PxyCfg, tParam)

	/*<<获取H460代理参数请求 >>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetH460Cfg_Req)

	/*<<获取H460代理参数响应>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tParam: H460配置参数
	*/
	MESSAGE(Ev_NV_GetH460Cfg_Rsp)
	BODY(nv::TNVH460PxyCfg, tParam)

	/*<<注册Sip服务器配置命令 >>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*tParam: Sip服务器配置参数
	*/
	MESSAGE(Ev_NV_SetSipSvrCfg_Cmd)
	BODY(nv::TNVSipSrvCfg, tParam)

	/*<<注册Sip服务器配置通知>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tParam: Sip服务器配置参数
	*/
	MESSAGE(Ev_NV_SetSipSvrCfg_Ntf)
	BODY(nv::TNVSipSrvCfg, tParam)

	/*<<自动声音时延检测命令 >>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*tStart: TRUE:开始检测，FALSE：停止
	*/
	MESSAGE(Ev_NV_AutoAudioDelayCheck_Cmd)
	BODY(nv::TBOOL32, tStart)

	/*<<获取音频输入接口请求 >>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetAudInPortListCfg_Req)

	/*<<获取音频输入接口响应>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tParam: 音频输入接口参数
	*/
	MESSAGE(Ev_NV_GetAudInPortListCfg_Rsp)
	BODY(nv::TNVMtAudInPortList, tParam)

	/*<<设置呼叫码率命令 >>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*tRate: 呼叫码率
	*/
	MESSAGE(Ev_NV_SetCallBitRateCfg_Cmd)
	BODY(nv::TU32, tRate)

	/*<<呼叫码率通知>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tRate: 呼叫码率
	*/
	MESSAGE(Ev_NV_SetCallBitRateCfg_Ntf)
	BODY(nv::TNVMtCallBitRate, tRate)

	/*<<获取呼叫码率请求 >>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetCallBitRateCfg_Req)

	/*<<获取呼叫码率响应>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tRate: 呼叫码率
	*/
	MESSAGE(Ev_NV_GetCallBitRateCfg_Rsp)
	BODY(nv::TNVMtCallBitRate, tRate)

	/*<<设置声音时延检测通知>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tState: state(EmMtAudioDelayCheckState)：检测状态
	*tResult:当EmMtAudioDelayCheckState为emAudioDelayChecked时，此值有效，表示时延值
	         当EmMtAudioDelayCheckState为emAudioDelayFailed时，此值有效，表示失败错误码
	*/
	MESSAGE(Ev_NV_AutoAudioDelayCheck_Ntf)
	BODY(nv::TU32, tState)
	BODY(nv::TU32, tResult)

	/*<<获取服务器登录状态请求 >>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetSvrStateList_Req)

	/*<<获取服务器登录状态响应>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tList: 服务器登录状态列表
	*/
	MESSAGE(Ev_NV_GetSvrStateList_Rsp)
	BODY(nv::TNVMtSvrStateList, tList)

	/*<<呼叫协议注册结果通知>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tProtocol: nv::EmMtConfProtocol 呼叫协议类型
	*tRegFailReason: nv::EmMtRegFailedReason 注册成功或失败原因
	*/
	MESSAGE(Ev_NV_TerRegResult_Ntf)
	BODY(nv::TS32, tProtocol)
	BODY(nv::TS32, tRegFailReason)

	/*<<终端注册CSU服务器配置命令 (GK) >>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*tAddr:终端CSU服务器配置信息
	*/
	MESSAGE(Ev_NV_SetCSUCfg_Cmd)
	BODY(nv::TNVMtCSUAddr, tAddr)

	/*<<设置CSU配置通知>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tAddr:终端CSU服务器配置信息
	*/
	MESSAGE(Ev_NV_SetCSUCfg_Ntf)
	BODY(nv::TNVMtCSUAddr, tAddr)

	/*<<查询SDI接口数量请求>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetTerSdiInOut_Req)

	/*<<查询SDI接口数量回应>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tType:  nv::EmMtSdiInOut  SDI接口数量 
	*/
	MESSAGE(Ev_NV_GetTerSdiInOut_Rsp)
	BODY(nv::TS32, tType)

	/*<<查询麦克风连接状态请求>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetMicrophoneConnectStatus_Req)

	/*<<查询麦克风连接状态回应>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tStatus:  全部的麦克状态信息
	*/
	MESSAGE(Ev_NV_GetMicrophoneConnectStatus_Rsp)
	BODY(nv::TNVMtAllMicStatus, tStatus)

	/*<<麦克风连接状态通知>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tStatus:  全部的麦克状态信息
	*/
	MESSAGE(Ev_NV_MicrophoneConnectStatus_Ntf)
	BODY(nv::TNVMtAllMicStatus, tStatus)

	/*<<获取第一路主视频输入端口请求>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetPri1stVidInPortCfg_Req)

	/*<<获取第一路主视频输入端口回应>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tPort:  主或辅视频输入端口
	*/
	MESSAGE(Ev_NV_GetPri1stVidInPortCfg_Rsp)
	BODY(nv::TNVMtHDVidInPort, tPort)

	/*<<获取辅视频输入端口请求>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetAssVidInPortCfg_Req)

	/*<<获取辅视频输入端口回应>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tPort:  主或辅视频输入端口
	*/
	MESSAGE(Ev_NV_GetAssVidInPortCfg_Rsp)
	BODY(nv::TNVMtHDVidInPort, tPort)

	/*<<获取第二路主辅视频输入端口请求>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetPri2ndVidInPortCfg_Req)

	/*<<获取第二路主辅视频输入端口回应>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tPort:  主或辅视频输入端口
	*/
	MESSAGE(Ev_NV_GetPri2ndVidInPortCfg_Rsp)
	BODY(nv::TNVMtHDVidInPort, tPort)

	/*<<设置音频输入接口命令 >>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*tList: 音频输入接口参数
	*/
	MESSAGE(Ev_NV_SetAudInPortListCfg_Cmd)
	BODY(nv::TNVMtAudInPortList, tList)

	/*<<设置音频输入接口通知>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tList: 音频输入接口参数
	*/
	MESSAGE(Ev_NV_SetAudInPortListCfg_Ntf)
	BODY(nv::TNVMtAudInPortList, tList)

	/*<<设置向导走完后通知终端 >>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_SetWizardResult_Cmd)

	/*<<通知imix恢复出厂设置>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_ResetImixSys_Ntf)

	/*<<获取终端GK是否注册请求>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetGKRegistRt_Req)

	/*<<获取终端GK是否注册回应>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tIsRegist:  是否注册
	*/
	MESSAGE(Ev_NV_GetGKRegistRt_Rsp)
	BODY(nv::TBOOL32, tIsRegist)

	/*<<获取终端Sip是否注册请求>>
	*消息流向 nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetSipRegistRt_Req)

	/*<<获取终端Sip是否注册回应>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tIsRegist:  是否注册
	*/
	MESSAGE(Ev_NV_GetSipRegistRt_Rsp)
	BODY(nv::TBOOL32, tIsRegist)

	/*<<重置终端通知>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tIsReset:  是否重置
	*/
	MESSAGE(Ev_NV_RestTer_Nty)
	BODY(nv::TBOOL32, tIsReset)

	/*<<终端遥控器音量控制通知>>
	*消息流向 nvterinterface==>dispatch==>nvservice
	*tbVolUp:  TRUE: 音量+ FALSE: 音量-
	*/
	MESSAGE(Ev_NV_DeviceKeyVolume_Nty)
	BODY(nv::TBOOL32, tbVolUp)

	/*<<系统关机时先通知终端待机>>
	*消息流向 nvdevice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_DeviceTurnOffToSleepMT_Nty)

#if !defined(_MESSAGE_HELP_)
    EV_END(TERINTERFACE) = EVSEG_TERINTERFACE_END
};
#endif//_MESSAGE_HELP_

#define Is_Terinterface_Msg(m) ((m) >= EV_BGN(TERINTERFACE) && (m) <= EV_END(TERINTERFACE))

#endif//_NVTERINTERFACEMSG_H_