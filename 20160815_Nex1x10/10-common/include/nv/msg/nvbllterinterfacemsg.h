#ifndef _NVBLLTERINTERFACEMSG_H_
#define _NVBLLTERINTERFACEMSG_H_

#include "nvmsgid.h"
#include "nvstruct.pb.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLTerInterfaceCEMsg
{							  
    EV_BLL_BGN(TERINTERFACE) = EVSEG_BLL_TERINTERFACE_BGN,
#endif

/*<<登入终端状态上报>>
	* is_login ：是否登入终端成功
	*消息流向 nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_MTCLogin_Ntf)         
	BODY(nv::TBOOL32, is_login)
	
	
	/*<<待机请求>>
	*消息流向 sdk==>dispatch==>nvservice
	*/
    MESSAGE(Ev_NV_BLL_CodecDspSleep_Req)

	/*<<待机响应>>
	*消息流向 nvservice==>dispatch==>sdk
	* is_sucess: 是否允许待机
	* fail_reason: 待机失败原因
	*/
    MESSAGE(Ev_NV_BLL_CodecDspSleep_Rsp)
	BODY(nv::TBOOL32, is_sucess)
	BODY(nv::TS32, fail_reason) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvSleepFailReason
		
	/*<<唤醒命令>>
	*消息流向 sdk==>dispatch==>nvservice
	*/
    MESSAGE(Ev_NV_BLL_CodecDspWakeup_Cmd)

	/*<<待机状态上报>>
	*消息流向 nvservice==>dispatch==>sdk
	*is_sleep : TRUE表示进入睡眠状态，FALSE表示进入唤醒状态
	*/
    MESSAGE(Ev_NV_BLL_CodecSleepState_Ntf)
	BODY(nv::TBOOL32, is_sleep)

	/*<<待机失败原因上报>>
	*消息流向 nvservice==>dispatch==>sdk
	*fail_reason : 失败原因
	*/
    MESSAGE(Ev_NV_BLL_CodecSleepFailReason_Ntf)
	BODY(nv::TS32, fail_reason) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvSleepFailReason
	
	/*<<向ui发送待机倒计时通知>>
	* nvservice==>dispatch==>sdk
	*count_down : 倒计时时间
	*/
	MESSAGE(Ev_NV_BLL_SleepCountDown_Ntf)
	BODY(nv::TU16, count_down)	//倒计时时间

	/*<<当前的双流状态上报>>
	* is_senddual ：是否发送双流
	*消息流向 nvservice ==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_AssSndSream_Status_Ntf)         
	BODY(NV::TBOOL32, is_senddual)
	BODY(NV::TS32, vid_lab) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvVidLabel
	
	/*<<当前的双流状态上报>>
	* is_rcvdual ：是否接收双流
	*消息流向 nvservice ==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_AssRcvSream_Status_Ntf)         
	BODY(NV::TBOOL32, is_rcvdual)

	/*<<当前的呼叫状态上报>>
	* callsate ：上报的呼叫参数
	*消息流向 nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_CallLinkState_Ntf)         //post to UI  当前呼叫状态
	BODY(nv::TS32, callsate)	//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvCallState
	
	/*<<请求当前辅流发送状态>>
	* 消息流向 ：sdk==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_BLL_AssSndSream_Status_Req)             //界面请求当前终端的双流发送情况
	

	/*<<请求当前辅流接收状态>>
	* 消息流向 ：sdk==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_BLL_AssRcvSream_Status_Req)             //界面请求当前终端的双流接收情况
	
	/*<<当前的呼叫状态请求>>
	*消息流向 ：sdk==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_BLL_CallLinkState_Req)
	
	/*<<界面同步命令>>
	* reason 同步原因
	* 消息流向 ：sdk==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_BLL_UISynchronize_Cmd)           //界面同步命令
	BODY(nv::TS32,       reason)            //同步原因  枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvUISynchronizeReason

	/*<<用于界面同步>> 
	* reason 同步原因
	* 消息流向 nvservice==>dispatch==>sdk
	*/
	MESSAGE( Ev_NV_BLL_UISynchronize_Ntf)        //用于界面同步
	BODY(nv::TS32,       reason)            //同步原因  枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvUISynchronizeReason
	
	/*<<当前的登入终端状态请求>>
	*消息流向 ：sdk==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_BLL_MTCLogin_Status_Req)
	
	/*<<当前的登入终端哑音状态请求>>
	*消息流向 ：sdk==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_BLL_CodecGetLocalMicMute_Req)
	
	/*<<当前哑音状态上报>>
	* is_mute ：是否哑音
	* 消息流向 nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_CodecMute_Ntf)         
	BODY(NV::TBOOL32, is_mute)
	
	/*<<当前的双流状态上报>>
	* is_senddual ：是否发送双流
	*消息流向 nvservice ==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_AssSndSream_Status_Rsp)         
	BODY(NV::TBOOL32, is_senddual)
	BODY(NV::TS32, vid_lab) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvVidLabel
	
	/*<<当前的双流状态上报>>
	* is_rcvdual ：是否接收双流
	*消息流向 nvservice ==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_AssRcvSream_Status_Rsp)         
	BODY(NV::TBOOL32, is_rcvdual)
	
	/*<<video双流开或关命令>>
	* bOpen ：开或者关
	* 消息流向 ：sdk==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_BLL_VideoAssStream_Cmd )
	BODY(nv:TBOOL32,  bOpen)                       //true : open；  false: close
	
	/*<<关机结果上报>>
	*消息流向 nvservice==>dispatch==>sdk
	*reason : 失败原因
	*/
    MESSAGE(Ev_NV_BLL_PowerTurnOff_Ntf)
	BODY(nv::TS32, reason) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvPowerTurnOffReason
	
	/*<<关机请求>>
	*消息流向 nvservice==>dispatch==>sdk
	*/
    MESSAGE(Ev_NV_BLL_PowerTurnOff_Req)

	/*<<sdk关机回复>>
	*消息流向 sdk==>dispatch==>nvservice
	* bturnoff ：开或者关
	*/
    MESSAGE(Ev_NV_BLL_PowerTurnOff_Rsp)
	BODY(nv:TBOOL32,  bturnoff)	

	/*<<当前应答方式查询>>
	* 
	*消息流向 sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_AnswerMode_Req)
	
	/*<<获取当前日期时间信息>>
	*传输方向：sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_GetMtSysDataTime_Req)
	
	/*<<获取当前日期时间信息响应>>
	*BODY ：   result 设置结果 0成功 其他错误码
	           tmttime 时间信息 
	*传输方向：nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_GetMtSysDataTime_Rsp)
	BODY(nv::TU32, result)
	BODY(nv::TNVTime, tmttime )
	
	/*<<设置终端当前日期时间信息响应>>
	*BODY ：   result 设置结果 0成功 其他错误码
	           tmttime 时间信息 
	*传输方向：nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_SetMtSysDataTimeResult_Rsp)
	BODY(nv::TU32, result)
	BODY(nv::TNVTime, tmttime )
	
	/*<<设置终端当前日期时间通知>>
	*BODY ：   tmttime 时间信息 
	*传输方向：nvservice==>dispatch==>sdk
	* see
	*/
	MESSAGE(Ev_NV_BLL_SetMtSysDataTime_Ntf)
	BODY(nv::TNVTime, tmttime )
	
	/*<<获取终端当前时间配置信息>>
	*传输方向：sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_GetMtSysTimeCfg_Req)
	
	/*<<获取终端当前时间配置信息响应>>
	*BODY ： tmttime 时间信息
	*传输方向：nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_GetMtSysTimeCfg_Rsp)
	BODY(nv::TNVCfgMtSystemTime, tmttime )
	
	/*<<终端当前时间配置信息通知>>
	*BODY ： tmttime 时间信息
	*传输方向：nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_SetMtSysTimeCfg_Ntf)
	BODY(nv::TNVCfgMtSystemTime, tmttime )
	
	/*<<蓝色底图>>
	*BODY ： tmttime 时间信息
	*传输方向：nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_SetBluePic_Nty)
	BODY(nv:TBOOL32,  bBlue)	
	/*<<OSD通知>>
	*BODY ： tmttime 时间信息
	*传输方向：nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_SetOSD_Nty)	
	BODY(nv:TBOOL32,  bOSD)	
	
	/*<<系统消息提示>>
	*BODY ： tSysHint 消息提示
	*传输方向：nvservice ==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_MtSysHint_Ntf)
	BODY(nv::TS32, tSysHint ) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvHintCode
	
	/*<<待机状态请求>>
	*消息流向 sdk==>dispatch==>nvservice
	*/
    MESSAGE(Ev_NV_BLL_GetCodecDspSleep_Req)
	
	/*<<待机状态请求回复>>
	*消息流向 nvservice==>dispatch==>sdk
	*/
    MESSAGE(Ev_NV_BLL_GetCodecDspSleep_Rsp)
	BODY(nv:TBOOL32,  bsleep)
	
	/*<<查询终端名字>>
	*消息流向 ：sdk==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_BLL_GetTerminalName_Req)
	
	/*<<查询终端名字响应>>
	*BODY ：   name 终端名字
	*传输方向：nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_GetTerminalName_Rsp)
	BODY(nv::TNVTerminalName, name)
	
	/*<<终端名字通知>>
	*BODY ：   name 终端名字
	*传输方向：nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_SetTerminalName_Ntf)
	BODY(nv::TNVTerminalName, name)
	
	/*<<终端程序全部启动成功通知>>
	*消息流向 nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_HDMtStartSucess_Ntf) 
	
	/*<<查询终端程序是否全部启动成功>>
	*消息流向 sdk==>dispatch==>nvservice
	*/
    MESSAGE(Ev_NV_BLL_InquireHDMtStartSucess_Req)
	
	/*<<查询终端程序是否全部启动成功响应>>
	*消息流向 nvservice==>dispatch==>sdk
	*/
    MESSAGE(Ev_NV_BLL_InquireHDMtStartSucess_Rsp)
	BODY(nv:TBOOL32,  bsuc)
	
	/*<<网呈IMIX通过该接口给终端发短消息(限制512字节)，终端接收短消息后显示在OSD上）>>
	*BODY ： LocSms 本地短消息
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_SendLocalSms_Cmd)
	BODY(nv::TString, LocSms )

	/*<<设置终端NAT地址）>>
	*BODY ： NatEnable：是否启用NAT
	*BODY ： NatIP:NatIP地址 
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_SetTerNatIpCfg_Cmd)
	BODY(nv::TBOOL32, NatEnable)
	BODY(nv::TString, NatIP)

	/*<<设置终端NAT地址回应）>>
	*BODY ： NatEnable：是否启用NAT
	*BODY ： NatIP:NatIP地址 
	*nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_SetTerNatIpCfg_Rsp)
	BODY(nv::TBOOL32, bResult)
	BODY(nv::TBOOL32, NatEnable)
	BODY(nv::TU32, NatIP)

	/*<<查询IMIX版本>>
	*BODY ：
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_GetImixMode_Req)	
	
	/*<<查询IMIX版本回应）>>	
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_GetImixMode_Rsp)	
	BODY(nv::TString, ImixMode)

	/*<<设置终端自动待机）>>
	*BODY ： tcfg：自动待机信息
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_SetTerAutoSleep_Cmd)
	BODY(nv::TNVMtAutoSleepCfg, tcfg)

	/*<<设置终端自动待机通知）>>
	*BODY ： tcfg：自动待机信息
	*nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_SetTerAutoSleep_Nty)
	BODY(nv::TNVMtAutoSleepCfg, tcfg)

	/*<<查询终端自动待机信息）>>
	*BODY ：
	*nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_GetTerAutoSleep_Req)

	/*<<查询终端自动待机信息回应）>>
	*BODY ：tcfg：自动待机信息
	*nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_GetTerAutoSleep_Rsp)
	BODY(nv::TNVMtAutoSleepCfg, tcfg)

	/*<<双流发送失败原因通知>>
	*BODY ：tcfg：自动待机信息
	*nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_SendDualFailReason_Nty)
	BODY(nv::TS32, tReason)

	/*<<终端恢复出产设置命令>>
	*BODY ：tDelCfgFile：是否删除配置文件
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_ResetTerCfg_Cmd)
	BODY(nv::TBOOL32, tDelCfgFile)

	/*<<设置终端时间配置命令>>
	*BODY ：tCfg：时间信息
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_SetTerTimeCfg_Cmd)
	BODY(nv::TNVCfgMtSystemTime, tCfg)

	/*<<设置终端当前时间信息>>
	*BODY ：tCfg：时间信息
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_SetMtSysDataTime_Req)
	BODY(nv::TNVTime, tCfg)

	/*<<设置终端是否允许登录云平台>>
	*BODY ：tLogin：TRUE：允许
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_SetTerLoginPlatformSrvCfg_Cmd)
	BODY(nv::TBOOL32, tLogin)

	/*<<获取终端ip请求>>
	*BODY ：tLogin：TRUE：允许
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_GetTerIp_Req)

	/*<<获取终端ip回应>>
	*BODY ：tTerip：终端ip
	*nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_GetTerIp_Rsp)
	BODY(nv::TString, tTerIp)

	/*<<获取终端硬件信息请求>>
	*BODY ：tLogin：TRUE：允许
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_GetTerHWInfo_Cmd)

	/*<<获取终端硬件信息回应>>
	*BODY ：tInfo：终端硬件信息
	*nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_GetTerHWInfo_Nty)
	BODY(nv::TNVHWInfo, tInfo)

	/*<<设置终端本地声音播放>>
	*消息流向 sdk==>dispatch==>nvservice
	*tSoundPlay:  播放本地声音信息
	*/
	MESSAGE(Ev_NV_BLL_TerLocalSoundPlay_Cmd)
	BODY(nv::TNVMtLocalSoundPaly, tSoundPlay)

	/*<<终端本地声音播放通知>>
	*消息流向 nvservice==>dispatch==>sdk
	*tSoundPlay:  播放本地声音信息
	*/
	MESSAGE(Ev_NV_BLL_TerLocalSoundPlay_Nty)
	BODY(nv::TNVMtLocalSoundPaly, tSoundPlay)

	/*<<终端音频输出测试>>
	*消息流向 sdk==>dispatch==>nvservice
	*tCfg:  测试信息
	*/
	MESSAGE(Ev_NV_BLL_TerAudioOutPowerTest_Cmd)
	BODY(nv::TNVMtAudioTestCfg, tCfg)

	/*<<终端音频输入测试>>
	*消息流向 sdk==>dispatch==>nvservice
	*tCfg:  测试信息
	*/
	MESSAGE(Ev_NV_BLL_TerAudioInPowerTest_Cmd)
	BODY(nv::TNVMtAudioTestCfg, tCfg)

	/*<<终端音频输出测试通知>>
	*消息流向 nvservice==>dispatch==>sdk
	*tPower:  音频输出音量
	*/
	MESSAGE(Ev_NV_BLL_TerAudioOutPowerTest_Nty)
	BODY(nv::TNVMtAudioPower, tPower)

	/*<<终端音频输入测试通知>>
	*消息流向 nvservice==>dispatch==>sdk
	*tPower:  音频输入音量
	*/
	MESSAGE(Ev_NV_BLL_TerAudioInPowerTest_Nty)
	BODY(nv::TNVMtAudioPower, tPower)

	/*<<终端音频输入接口状态查询请求>>
	*消息流向 sdk==>dispatch==>nvservice
	*tSate:  状态
	*/
	MESSAGE(Ev_NV_BLL_TerAudioInputState_Req)
	BODY(nv::TNVMtMutiAudInState, tSate)

	/*<<终端音频输入接口状态查询回应>>
	*消息流向 nvservice==>dispatch==>sdk
	*tSate:  状态
	*/
	MESSAGE(Ev_NV_BLL_TerAudioInputState_Rsp)
	BODY(nv::TNVMtMutiAudInState, tSate)

	/*<<获取登录APS所需要的参数请求>>
	*消息流向 sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetLoginApsParamCfg_Req)

	/*<<获取登录APS所需要的参数回应>>
	*消息流向 nvservice==>dispatch==>sdk
	*tParm:  参数
	*/
	MESSAGE(Ev_NV_BLL_GetLoginApsParamCfg_Rsp)
	BODY(nv::TNVApsLoginParam, tParm)

	/*<<获取呼叫协议类型配置请求>>
	*消息流向 sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetCallProtocolCfg_Req)

	/*<<获取呼叫协议类型配置回应>>
	*消息流向 nvservice==>dispatch==>sdk
	*emProtocal:  nv::EmMtConfProtocol,协议类型
	*/
	MESSAGE(Ev_NV_BLL_GetCallProtocolCfg_Rsp)
	BODY(nv::TS32, emProtocal)

	/*<<获取XAPList配置请求>>
	*消息流向 sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetXAPListCfg_Req)

	/*<<获取XAPList配置请求回应>>
	*消息流向 nvservice==>dispatch==>sdk
	*tSrvList:  XAPS服务器列表
	*/
	MESSAGE(Ev_NV_BLL_GetXAPListCfg_Rsp)
	BODY(nv::TNVMtXAPSvrList, tSrvList)

	/*<<获取H323代理配置请求>>
	*消息流向 sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetH323PxyCfg_Req)

	/*<<获取H323代理配置回应>>
	*消息流向 nvservice==>dispatch==>sdk
	*tCfg:  H323代理配置信息
	*/
	MESSAGE(Ev_NV_BLL_GetH323PxyCfg_Rsp)
	BODY(nv::TNVH323PxyCfg, tCfg)

	/*<<请求获取手动设置的gk地址>>
	*消息流向 sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetGKCfg_Req)

	/*<<获取手动设置的gk地址回应>>
	*消息流向 nvservice==>dispatch==>sdk
	*tCfg:  gk地址信息
	*/
	MESSAGE(Ev_NV_BLL_GetGKCfg_Rsp)
	BODY(nv::TNVMtCSUAddr, tCfg)

	/*<<获取手动设置Sip服务器的配置>>
	*消息流向 sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetManuSipSvrCfg_Req)

	/*<<获取手动设置Sip服务器的配置回应>>
	*消息流向 nvservice==>dispatch==>sdk
	*tCfg:  Sip服务器的配置
	*/
	MESSAGE(Ev_NV_BLL_GetManuSipSvrCfg_Rsp)
	BODY(nv::TNVSipSrvCfg, tCfg)

	/*<<获取是否允许登陆平台服务请求>>
	*消息流向 sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetLoginPlatformSrvCfg_Req)

	/*<<获取是否允许登陆平台服务回应>>
	*消息流向 nvservice==>dispatch==>sdk
	*tLogin: TRUE:登录，FALSE：未登录
	*/
	MESSAGE(Ev_NV_BLL_GetLoginPlatformSrvCfg_Rsp)
	BODY(nv::TBOOL32, tLogin)

	/*<<获取是否强制设置H323协议类型请求>>
	*消息流向 sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetForceH323StackCfg_Req)

	/*<<获取是否强制设置H323协议类型回应>>
	*消息流向 nvservice==>dispatch==>sdk
	*tForceSet: TRUE:强制设置，FALSE：非强制设置
	*/
	MESSAGE(Ev_NV_BLL_GetForceH323StackCfg_Rsp)
	BODY(nv::TBOOL32, tFoeceSet)

	/*<<查询账号详细信息请求>>
	*消息流向 sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetAccountInfo_Req)
	BODY(nv::TNVMtAccountManager, tInfo)

	/*<<查询账号详细信息回应>>
	*消息流向 nvservice==>dispatch==>sdk
	*tInfo: 账号详细信息
	*/
	MESSAGE(Ev_NV_BLL_GetAccountInfo_Rsp)
	BODY(nv::TNVMtAccountManager, tInfo)

	/*<<设置终端名称信息配置命令>>
	*消息流向 sdk==>dispatch==>nvservice
	*tTerName: 终端名字
	*/
	MESSAGE(Ev_NV_BLL_SetTerminalNameCfg_Cmd)
	BODY(nv::TNVTerminalName, tTerName)

	/*<<是否允许登陆平台服务通知>>
	*消息流向 nvservice==>dispatch==>sdk
	*tLogin: TRUE:登录，FALSE：未登录
	*/
	MESSAGE(Ev_NV_BLL_SetLoginPlatformSrvCfg_Ntf)
	BODY(nv::TBOOL32, tLogin)

	/*<<设置登录APS所需要的参数命令>>
	*消息流向 sdk==>dispatch==>nvservice
	*tParam: 参数
	*/
	MESSAGE(Ev_NV_BLL_SetLoginApsParamCfg_Cmd)
	BODY(nv::TNVApsLoginParam, tParam)

	/*<<APS登陆结果响应>>
	*消息流向 nvservice==>dispatch==>sdk
	*tLogin: 登录成功或失败原因
	*/
	MESSAGE(Ev_NV_BLL_ApsLoginResult_Ntf)
	BODY(nv::TNVMtApsLoginErrcode, tLogin)
	BODY(nv::TU32, tIP)

	/*<<强制设置H323协议类型(标准/非标)命令 >>
	*注：当自建终端登陆自荐平台时，界面设置enable为true时底下才会使用bstand的值
	*消息流向 sdk==>dispatch==>nvservice
	*tParam: 参数
	*/
	MESSAGE(Ev_NV_BLL_ForceSet323StackCfg_Cmd)
	BODY(nv::TNVForceSetH323Stack, tParam)

	/*<<强制设置H323协议类型(标准/非标)通知>>
	*消息流向 nvservice==>dispatch==>sdk
	*tForce: TRUE：强制设置
	*/
	MESSAGE(Ev_NV_BLL_ForceSet323StackCfg_Ntf)
	BODY(nv::TBOOL32, tForce)

	/*<<设置XAPList配置命令 >>
	*消息流向 sdk==>dispatch==>nvservice
	*tParam: XAPList配置参数
	*/
	MESSAGE(Ev_NV_BLL_SetXAPListCfg_Cmd)
	BODY(nv::TNVMtXAPSvrList, tParam)

	/*<<设置XAPList配置通知>>
	*消息流向 nvservice==>dispatch==>sdk
	*tParam: XAPList配置参数
	*/
	MESSAGE(Ev_NV_BLL_SetXAPListCfg_Ntf)
	BODY(nv::TNVMtXAPSvrList, tParam)

	/*<<设置H323代理命令 >>
	*消息流向 sdk==>dispatch==>nvservice
	*tParam: H323配置参数
	*/
	MESSAGE(Ev_NV_BLL_SetH323PxyCfg_Cmd)
	BODY(nv::TNVH323PxyCfg, tParam)

	/*<<设置H323代理通知>>
	*消息流向 nvservice==>dispatch==>sdk
	*tParam: H323配置参数
	*/
	MESSAGE(Ev_NV_BLL_SetH323PxyCfg_Ntf)
	BODY(nv::TNVH323PxyCfg, tParam)

	/*<<设置H460代理命令 >>
	*消息流向 sdk==>dispatch==>nvservice
	*tParam: H460配置参数
	*/
	MESSAGE(Ev_NV_BLL_SetH460Cfg_Cmd)
	BODY(nv::TNVH460PxyCfg, tParam)

	/*<<设置H460代理通知>>
	*消息流向 nvservice==>dispatch==>sdk
	*tParam: H460配置参数
	*/
	MESSAGE(Ev_NV_BLL_SetH460Cfg_Ntf)
	BODY(nv::TNVH460PxyCfg, tParam)

	/*<<获取H460代理参数请求 >>
	*消息流向 sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetH460Cfg_Req)

	/*<<获取H460代理参数响应>>
	*消息流向 nvservice==>dispatch==>sdk
	*tParam: H460配置参数
	*/
	MESSAGE(Ev_NV_BLL_GetH460Cfg_Rsp)
	BODY(nv::TNVH460PxyCfg, tParam)

	/*<<注册Sip服务器配置命令 >>
	*消息流向 sdk==>dispatch==>nvservice
	*tParam: Sip服务器配置参数
	*/
	MESSAGE(Ev_NV_BLL_SetSipSvrCfg_Cmd)
	BODY(nv::TNVSipSrvCfg, tParam)

	/*<<注册Sip服务器配置通知>>
	*消息流向 nvservice==>dispatch==>sdk
	*tParam: Sip服务器配置参数
	*/
	MESSAGE(Ev_NV_BLL_SetSipSvrCfg_Ntf)
	BODY(nv::TNVSipSrvCfg, tParam)

	/*<<自动声音时延检测命令 >>
	*消息流向 sdk==>dispatch==>nvservice
	*tStart: TRUE:开始检测，FALSE：停止
	*/
	MESSAGE(Ev_NV_BLL_AutoAudioDelayCheck_Cmd)
	BODY(nv::TBOOL32, tStart)

	/*<<获取音频输入接口请求 >>
	*消息流向 sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetAudInPortListCfg_Req)

	/*<<获取音频输入接口响应>>
	*消息流向 nvservice==>dispatch==>sdk
	*tParam: 音频输入接口参数
	*/
	MESSAGE(Ev_NV_BLL_GetAudInPortListCfg_Rsp)
	BODY(nv::TNVMtAudInPortList, tParam)

	/*<<设置呼叫码率命令 >>
	*消息流向 sdk==>dispatch==>nvservice
	*tRate: 呼叫码率
	*/
	MESSAGE(Ev_NV_BLL_SetCallBitRateCfg_Cmd)
	BODY(nv::TU32, tRate)

	/*<<呼叫码率通知>>
	*消息流向 nvservice==>dispatch==>sdk
	*tRate: 呼叫码率
	*/
	MESSAGE(Ev_NV_BLL_SetCallBitRateCfg_Ntf)
	BODY(nv::TNVMtCallBitRate, tRate)

	/*<<获取呼叫码率请求 >>
	*消息流向 sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetCallBitRateCfg_Req)

	/*<<获取呼叫码率响应>>
	*消息流向 nvservice==>dispatch==>sdk
	*tRate: 呼叫码率
	*/
	MESSAGE(Ev_NV_BLL_GetCallBitRateCfg_Rsp)
	BODY(nv::TNVMtCallBitRate, tRate)

	/*<<设置声音时延检测通知>>
	*消息流向 nvservice==>dispatch==>sdk
	*tState: state(EmMtAudioDelayCheckState)：检测状态
	*tResult:当EmMtAudioDelayCheckState为emAudioDelayChecked时，此值有效，表示时延值
	         当EmMtAudioDelayCheckState为emAudioDelayFailed时，此值有效，表示失败错误码
	*/
	MESSAGE(Ev_NV_BLL_AutoAudioDelayCheck_Ntf)
	BODY(nv::TU32, tState)
	BODY(nv::TU32, tResult)

	/*<<获取服务器登录状态请求 >>
	*消息流向 sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetSvrStateList_Req)

	/*<<获取服务器登录状态响应>>
	*消息流向 nvservice==>dispatch==>sdk
	*tList: 服务器登录状态列表
	*/
	MESSAGE(Ev_NV_BLL_GetSvrStateList_Rsp)
	BODY(nv::TNVMtSvrStateList, tList)

	/*<<呼叫协议注册结果通知>>
	*消息流向 nvservice==>dispatch==>sdk
	*tProtocol: nv::EmMtConfProtocol 呼叫协议类型
	*tRegFailReason: nv::EmMtRegFailedReason 注册成功或失败原因
	*/
	MESSAGE(Ev_NV_BLL_TerRegResult_Ntf)
	BODY(nv::TS32, tProtocol)
	BODY(nv::TS32, tRegFailReason)

	/*<<终端注册CSU服务器配置命令 (GK) >>
	*消息流向 sdk==>dispatch==>nvservice
	*tAddr:终端CSU服务器配置信息
	*/
	MESSAGE(Ev_NV_BLL_SetCSUCfg_Cmd)
	BODY(nv::TNVMtCSUAddr, tAddr)

	/*<<设置CSU配置通知>>
	*消息流向 nvservice==>dispatch==>sdk
	*tAddr:终端CSU服务器配置信息
	*/
	MESSAGE(Ev_NV_BLL_SetCSUCfg_Ntf)
	BODY(nv::TNVMtCSUAddr, tAddr)

	/*<<查询SDI接口数量请求>>
	*消息流向 sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetTerSdiInOut_Req)

	/*<<查询SDI接口数量回应>>
	*消息流向 nvservice==>dispatch==>sdk
	*tType:  nv::EmMtSdiInOut  SDI接口数量 
	*/
	MESSAGE(Ev_NV_BLL_GetTerSdiInOut_Rsp)
	BODY(nv::TS32, tType)

	/*<<查询麦克风连接状态请求>>
	*消息流向 sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetMicrophoneConnectStatus_Req)

	/*<<查询麦克风连接状态回应>>
	*消息流向 nvservice==>dispatch==>sdk
	*tStatus:  全部的麦克状态信息
	*/
	MESSAGE(Ev_NV_BLL_GetMicrophoneConnectStatus_Rsp)
	BODY(nv::TNVMtAllMicStatus, tStatus)

	/*<<麦克风连接状态通知>>
	*消息流向 nvservice==>dispatch==>sdk
	*tStatus:  全部的麦克状态信息
	*/
	MESSAGE(Ev_NV_BLL_MicrophoneConnectStatus_Ntf)
	BODY(nv::TNVMtAllMicStatus, tStatus)

	/*<<获取第一路主视频输入端口请求>>
	*消息流向 sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetPri1stVidInPortCfg_Req)

	/*<<获取第一路主视频输入端口回应>>
	*消息流向 nvservice==>dispatch==>sdk
	*tPort:  主或辅视频输入端口
	*/
	MESSAGE(Ev_NV_BLL_GetPri1stVidInPortCfg_Rsp)
	BODY(nv::TNVMtHDVidInPort, tPort)

	/*<<获取辅视频输入端口请求>>
	*消息流向 sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetAssVidInPortCfg_Req)

	/*<<获取辅视频输入端口回应>>
	*消息流向 nvservice==>dispatch==>sdk
	*tPort:  主或辅视频输入端口
	*/
	MESSAGE(Ev_NV_BLL_GetAssVidInPortCfg_Rsp)
	BODY(nv::TNVMtHDVidInPort, tPort)

	/*<<获取第二路主辅视频输入端口请求>>
	*消息流向 sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetPri2ndVidInPortCfg_Req)

	/*<<获取第二路主辅视频输入端口回应>>
	*消息流向 nvservice==>dispatch==>sdk
	*tPort:  主或辅视频输入端口
	*/
	MESSAGE(Ev_NV_BLL_GetPri2ndVidInPortCfg_Rsp)
	BODY(nv::TNVMtHDVidInPort, tPort)

	/*<<设置音频输入接口命令 >>
	*消息流向 sdk==>dispatch==>nvservice
	*tList: 音频输入接口参数
	*/
	MESSAGE(Ev_NV_BLL_SetAudInPortListCfg_Cmd)
	BODY(nv::TNVMtAudInPortList, tList)

	/*<<设置音频输入接口通知>>
	*消息流向 nvservice==>dispatch==>sdk
	*tList: 音频输入接口参数
	*/
	MESSAGE(Ev_NV_BLL_SetAudInPortListCfg_Ntf)
	BODY(nv::TNVMtAudInPortList, tList)

	/*<<设置向导走完后通知终端 >>
	*消息流向 sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_SetWizardResult_Cmd)

	/*<<通知imix恢复出厂设置>>
	*消息流向nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_ResetImixSys_Ntf)

	/*<<获取终端GK是否注册请求>>
	*消息流向 sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetGKRegistRt_Req)

	/*<<获取终端GK是否注册回应>>
	*消息流向 nvservice==>dispatch==>sdk
	*tIsRegist:  是否注册
	*/
	MESSAGE(Ev_NV_BLL_GetGKRegistRt_Rsp)
	BODY(nv::TBOOL32, tIsRegist)

	/*<<获取终端Sip是否注册请求>>
	*消息流向 sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetSipRegistRt_Req)

	/*<<获取终端Sip是否注册回应>>
	*消息流向 nvservice==>dispatch==>sdk
	*tIsRegist:  是否注册
	*/
	MESSAGE(Ev_NV_BLL_GetSipRegistRt_Rsp)
	BODY(nv::TBOOL32, tIsRegist)

	/*<<重置终端通知>>
	*消息流向 nvservice==>dispatch==>sdk
	*tIsReset:  是否重置
	*/
	MESSAGE(Ev_NV_BLL_RestTer_Nty)
	BODY(nv::TBOOL32, tIsReset)

	/*<<终端遥控器音量控制通知>>
	*消息流向 nvservice==>dispatch==>sdk
	*tbVolUp:  TRUE: 音量+ FALSE: 音量-
	*/
	MESSAGE(Ev_NV_BLL_DeviceKeyVolume_Nty)
	BODY(nv::TBOOL32, tbVolUp)

	/*<<imix是否与终端连接>>
	*
	*/
	MESSAGE(Ev_NV_BLL_NVConnectTer_Req)

	/*<<imix是否与终端连接回应>>
	*
	*/
	MESSAGE(Ev_NV_BLL_NVConnectTer_Rsp)
	BODY(nv::TBOOL32, tbIsConnect)

#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(TERINTERFACE) = EVSEG_BLL_TERINTERFACE_END
};
#endif

#define Is_BLL_Terinterface_Msg(m) ((m) >= EV_BLL_BGN(TERINTERFACE) && (m) <= EV_BLL_END(TERINTERFACE))

#endif // _NVBLLTERINTERFACMSG_H_