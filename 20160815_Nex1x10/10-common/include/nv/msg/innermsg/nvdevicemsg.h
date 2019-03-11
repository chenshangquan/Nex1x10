#ifndef _NVDEVICEMSG_H_
#define _NVDEVICEMSG_H_

#include "nvmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmNvDeviceMsg
{
    EV_BGN(DEVICE) = EVSEG_DEVICE_BGN,
#endif
	
	/*<<调节亮度>>
	*消息流向 nvservice==>dispatch==>nvdevice
	* Screen_type: 屏幕类型
	* brightness: 亮度 
	*/
    MESSAGE(Ev_NV_SetTvBrightness_Req)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TU32, brightness)
	
	/*<<调节亮度>>
	*消息流向nvdevice==>dispatch==> nvservice
	result 
	* Screen_type: 屏幕类型
	* brightness: 亮度 
	*/
    MESSAGE(Ev_NV_SetTvBrightness_Rsp)
	BODY(nv::TBOOL32, result)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TU32, brightness)
	
	/*<<调节对比度>>
	*消息流向 nvservice==>dispatch==>nvdevice
	* Screen_type: 屏幕类型
	* contrast: 对比度
	*/
    MESSAGE(Ev_NV_SetTvContraste_Req)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TU32, contrast)
	
	/*<<调节对比度>>
	*消息流向nvdevice==>dispatch==> nvservice
	result 
	* Screen_type: 屏幕类型
	* contrast: 对比度
	*/
    MESSAGE(Ev_NV_SetTvContraste_Rsp)
	BODY(nv::TBOOL32, result)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TU32, contrast)
	
	/*<<调节饱和度>>
	*消息流向 nvservice==>dispatch==>nvdevice
	* Screen_type: 屏幕类型
	* saturation: 饱和度
	*/
    MESSAGE(Ev_NV_SetTvSaturation_Req)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TU32, saturation)
	
	/*<<调节饱和度>>
	*消息流向nvservice==>dispatch==>sdk
	result 
	* Screen_type: 屏幕类型
	* saturation: 饱和度
	*/
    MESSAGE(Ev_NV_SetTvSaturation_Rsp)
	BODY(nv::TBOOL32, result)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TU32, saturation)
	
	/*<<调节清晰度>>
	*消息流向 nvservice==>dispatch==>nvdevice
	* Screen_type: 屏幕类型
	* clarity: 清晰度
	*/
    MESSAGE(Ev_NV_SetTvClarity_Req)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TU32, clarity)
	
	/*<<调节清晰度>>
	*消息流向nvdevice==>dispatch==> nvservice
	result 
	* Screen_type: 屏幕类型
	* clarity: 清晰度
	*/
    MESSAGE(Ev_NV_SetTvClarity_Rsp)
	BODY(nv::TBOOL32, result)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TU32, clarity)
	
	/*<<调节色温>>
	*消息流向 nvservice==>dispatch==>nvdevice
	* Screen_type: 屏幕类型
	* color_temp: 色温
	*/
    MESSAGE(Ev_NV_SetTvColortemp_Req)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TS32, color_temp)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenColorTemperature
	
	/*<<调节色温>>
	*消息流向nvdevice==>dispatch==> nvservice
	result 
	* Screen_type: 屏幕类型
	* color_temp: 色温
	*/
    MESSAGE(Ev_NV_SetTvColortemp_Rsp)
	BODY(nv::TBOOL32, result)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TS32, color_temp)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenColorTemperature
	
	/*<<调节显示比例>>
	*消息流向 nvservice==>dispatch==>nvdevice
	* Screen_type: 屏幕类型
	* displayratio: 显示比例
	*/
    MESSAGE(Ev_NV_SetTvDisplayratio_Req)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TS32, displayratio)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvTvDisplayRatio
	
	/*<<调节显示比例>>
	*消息流向nvdevice==>dispatch==> nvservice
	result 
	* Screen_type: 屏幕类型
	* displayratio: 显示比例
	*/
    MESSAGE(Ev_NV_SetTvDisplayratio_Rsp)
	BODY(nv::TBOOL32, result)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TS32, displayratio)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvTvDisplayRatio
	
	MESSAGE(Ev_NV_DeviceSerialTest_Req)
	BODY(nv::TS32, Serial_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNVSerialMode

	MESSAGE(Ev_NV_DeviceSerialTest_Rsp)
	BODY(nv::TBOOL32, result)
	BODY(nv::TS32, Serial_type)	
	
	/*<<串口码值上报消息>>
	*uart_type : 串口类型
	*code : 单字节码值
	*消息流向 : deivce内部
	*/
	MESSAGE(Ev_NV_DeviceSerialRecvByte_Ntf)
	BODY(nv::TU8, uart_type)
	BODY(nv::TU8, code)

	/*<<串口空值上报消息>>
	*uart_type : 串口类型
	*消息流向 : deivce内部
	*/
	MESSAGE(Ev_NV_DeviceSerialRecvNone_Ntf)
	BODY(nv::TU8, uart_type)
	
	/*<<通知iface切换hdmi矩阵>>
	*is_imix : 1：切到imix，0.切到hdmi
	*消息流向 : nvservice==>dispatch==>nvdevice
	*/
	MESSAGE(Ev_NV_SetIfaceSwitchHdmi_Cmd)
	BODY(nv::TBOOL32, is_imix)
	
	/*<<iface指令通知>>
	*code : iface指令
	*消息流向 : deivce内部
	*/
	MESSAGE(Ev_NV_IfaceInstruction_Ntf)
	BODY(nv::TS32, code) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvIfaceInstruction
	
	MESSAGE(Ev_NV_DeviceSerial_Req)
	BODY(nv::TU32, Serial_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNVSerialMode
	BODY(nv::TBOOL32, bIsRs232)
	
	/*<<查询swb版本>>
	*消息流向 : deivce内部
	*/
	MESSAGE(Ev_NV_GetSwbVer_Req)
	
	/*<<查询iface版本>>
	*消息流向 : deivce内部
	*/
	MESSAGE(Ev_NV_GetIfaceVer_Req)
	
	/*<<设置Nova路由器>>
	*消息流向 : deivce内部
	*/
	MESSAGE(Ev_NV_SetNova_Req)
	BODY(nv::TString, tbCmd)
	BODY(nv::TBOOL32, bIsSend)
	/*<<查询Nova路由器>>
	*消息流向 : deivce内部
	*/
	MESSAGE(Ev_NV_GetNova_Req)
	BODY(nv::TString, tbCmd)
	BODY(nv::TBOOL32, bIsSend)
	
	/*<<查询swb版本>>
	*消息流向 : deivce内部
	*/
	MESSAGE(Ev_NV_GetSwbVer_Rsp)
	BODY(nv::TString, tCmd)
	
	/*<<切换电视机输入源>>
	*input : 电视机源
	*消息流向 : nvservice==>dispatch==>nvdevice
	*/
	MESSAGE(Ev_NV_SetTvInput_Cmd)
	BODY(nv::TS32, input) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvTvInputSelect
	
	/*<<通知是否升级开关>>
	*is_upgrade : TRUE：升级，FALSE.不升级
	*消息流向 : nvupgrade==>dispatch==>nvdevice
	*/
	MESSAGE(Ev_NV_IsUpgradePower_Cmd)
	BODY(nv::TBOOL32, is_upgrade)
	
	MESSAGE(Ev_NV_TvTest_Cmd)
	BODY(nv::TU8, cmd1)
	BODY(nv::TU8, cmd2)

	/*<<设置Nova路由器>>
	*消息流向 : 
	*/
	MESSAGE(Ev_NV_SetNova_Cmd)
	
	/*<<打开关闭电视机无信号>>
	*消息流向 nvservice=>dispatch==>nvdevice
	* Screen_type: 屏幕类型
	* open: 打开关闭电视机无信号
	*/
    MESSAGE(Ev_NV_SetTvSignal_Cmd)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::BOOL32, open)
	
	/*<<打开关闭电视机无信号通知>>
	*消息流向 nvdevice=>dispatch==>nvservice
	* Screen_type: 屏幕类型
	* open: 打开关闭电视机无信号
	*/
    MESSAGE(Ev_NV_SetTvSignal_Ntf)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::BOOL32, open)
	
	/*<<界面下电通知>>
	*BODY ：
	*nvservice==>dispatch==>nvdevice
	*/
	MESSAGE(Ev_NV_NvcSetTurnOff_Cmd)
	BODY(nv::TBOOL32, is_turnoff)

	/*<<界面自动关机倒计时请求>>
	*BODY ：
	*nvservice==>dispatch==>nvdevice
	*/
	MESSAGE(Ev_NV_StartShutdownCount_Req)

	/*<<自动关机倒计时回应>>
	*BODY ：is_start：是否可以开始倒计时
	*nvdevice==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_StartShutdownCount_Rsp)
	BODY(nv::TBOOL32, is_start)

	/*<<自动关机倒计时命令>>
	*BODY ：is_start:0:停止倒计时，1：开始倒计时
	*nvservice==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_ShutdownCount_Cmd)
	BODY(nv::TBOOL32, is_start)

	/*<<自动关机倒计时结束通知>>
	*nvdevice==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_StopShutdownCount_Nty)

	/*<<自动关机命令>>
	*nvservice==>dispatch==>nvdevice
	*/
	MESSAGE(Ev_NV_AutoShutdown_Cmd)
	
	/*<<电视机取消静音通知>>
	*BODY ：
	*nvservice==>dispatch==>nvdevice
	*/
	MESSAGE(Ev_NV_SetTvChanceQuite_Cmd)
	BODY(nv::TBOOL32, is_imix)

	/*<<总开关开机100s内再次按下通知>>
	*BODY ：
	*nvdevice==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_SwbRepeatTurnOn_Nty)
	
	/*<<总开关在系统开机时按键小于3秒通知>>
	*BODY ：
	*nvdevice==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_SwbKey_Nty)
	
	/*<<通知总开关待机关机状态>>
	*nvservice==>dispatch==>nvdevice
	*/
	MESSAGE(Ev_NV_SetSwbState_Cmd)
	BODY(nv::TS32, state)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvSwbState

	/*<<终端待机完成后通知imix整体下电>>
	*nvterinterface==>dispatch==>nvdevice
	*/
	MESSAGE(Ev_NV_AllImixShutdown_Cmd)

	/*<<设置Nova路由器重启>>
	*消息流向 : 
	*/
	MESSAGE(Ev_NV_SetNovaReboot_Cmd)
	
#if !defined(_MESSAGE_HELP_)
    EV_END(DEVICE) = EVSEG_DEVICE_END
};
#endif

#define Is_Device_Msg(m) ((m) >= EV_BGN(DEVICE) && (m) <= EV_END(DEVICE))

#endif