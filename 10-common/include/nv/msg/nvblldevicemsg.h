#ifndef _NVBLLDEVICEMSG_H_
#define _NVBLLDEVICEMSG_H_

#include "nvmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLNvDeviceMsg
{
    EV_BLL_BGN(DEVICE) = EVSEG_BLL_DEVICE_BGN,
#endif

	/*<<重启终端>>
	* sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_RebootSystem_Req)

	/*<<调节亮度>>
	*消息流向 sdk==>dispatch==>nvservice
	* Screen_type: 屏幕类型
	* brightness: 亮度 
	*/
    MESSAGE(Ev_NV_BLL_SetTvBrightness_Req)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TU32, brightness)
	
	/*<<调节亮度>>
	*消息流向 nvservice==>dispatch==>sdk
	result 
	* Screen_type: 屏幕类型
	* brightness: 亮度 
	*/
    MESSAGE(Ev_NV_BLL_SetTvBrightness_Rsp)
	BODY(nv::TBOOL32, result)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TU32, brightness)
	
	/*<<调节对比度>>
	*消息流向 sdk==>dispatch==>nvservice
	* Screen_type: 屏幕类型
	* contrast: 对比度
	*/
    MESSAGE(Ev_NV_BLL_SetTvContraste_Req)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TU32, contrast)
	
	/*<<调节对比度>>
	*消息流向 nvservice==>dispatch==>sdk
	result 
	* Screen_type: 屏幕类型
	* contrast: 对比度
	*/
    MESSAGE(Ev_NV_BLL_SetTvContraste_Rsp)
	BODY(nv::TBOOL32, result)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TU32, contrast)
	
	/*<<调节饱和度>>
	*消息流向 sdk==>dispatch==>nvservice
	* Screen_type: 屏幕类型
	* saturation: 饱和度
	*/
    MESSAGE(Ev_NV_BLL_SetTvSaturation_Req)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TU32, saturation)
	
	/*<<调节饱和度>>
	*消息流向nvservice==>dispatch==>sdk
	result 
	* Screen_type: 屏幕类型
	* saturation: 饱和度
	*/
    MESSAGE(Ev_NV_BLL_SetTvSaturation_Rsp)
	BODY(nv::TBOOL32, result)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TU32, saturation)
	
	/*<<调节清晰度>>
	*消息流向 sdk==>dispatch==>nvservice
	* Screen_type: 屏幕类型
	* clarity: 清晰度
	*/
    MESSAGE(Ev_NV_BLL_SetTvClarity_Req)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TU32, clarity)
	
	/*<<调节清晰度>>
	*消息流向 nvservice==>dispatch==>sdk
	result 
	* Screen_type: 屏幕类型
	* clarity: 清晰度
	*/
    MESSAGE(Ev_NV_BLL_SetTvClarity_Rsp)
	BODY(nv::TBOOL32, result)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TU32, clarity)
	
	/*<<调节色温>>
	*消息流向 sdk==>dispatch==>nvservice
	* Screen_type: 屏幕类型
	* color_temp: 色温
	*/
    MESSAGE(Ev_NV_BLL_SetTvColortemp_Req)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TS32, color_temp)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenColorTemperature
	
	/*<<调节色温>>
	*消息流向 nvservice==>dispatch==>sdk
	result 
	* Screen_type: 屏幕类型
	* color_temp: 色温
	*/
    MESSAGE(Ev_NV_BLL_SetTvColortemp_Rsp)
	BODY(nv::TBOOL32, result)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TS32, color_temp)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenColorTemperature
	
	/*<<调节显示比例>>
	*消息流向 sdk==>dispatch==>nvservice
	* Screen_type: 屏幕类型
	* displayratio: 显示比例
	*/
    MESSAGE(Ev_NV_BLL_SetTvDisplayratio_Req)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TS32, displayratio)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvTvDisplayRatio
	
	/*<<调节显示比例>>
	*消息流向 nvservice==>dispatch==>sdk
	result 
	* Screen_type: 屏幕类型
	* displayratio: 显示比例
	*/
    MESSAGE(Ev_NV_BLL_SetTvDisplayratio_Rsp)
	BODY(nv::TBOOL32, result)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::TS32, displayratio)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvTvDisplayRatio
	
	/*------生产测试--------*/
    /*<<串口生产测试请求>>
    *serial_type : 串口种类
	*消息流向 : mfgtest->service
	* see Ev_NV_BLL_DeviceSerialTest_Rsp
	*/
    MESSAGE(Ev_NV_BLL_DeviceSerialTest_Req)
    BODY(nv::TS32, serialtype)

    /*<<查询cpu和内存使用情况响应>>
	*result : 测试结果
	*serial_type : 串口种类
	*消息流向 : service->mfgtest
	* see Ev_NV_BLL_DeviceSerialTest_Req
	*/
    MESSAGE(Ev_NV_BLL_DeviceSerialTest_Rsp)
    BODY(nv::TBOOL32, result)
    BODY(nv::TS32, serialtype)
	
	MESSAGE(Ev_NV_BLL_DeviceSerialTest_Nty)
	BODY(nv::TBOOL32, bOpen)
	//当前不允许待机
	MESSAGE(Ev_NV_BLL_NotSleep_Nty)	
	
	//获取usb名字
	MESSAGE(Ev_NV_BLL_SetUsbLabel_Cmd)	
	//当前不允许唤醒
	MESSAGE(Ev_NV_BLL_NotWake_Nty)
	//唤醒定时测试
	MESSAGE(Ev_NV_BLL_WakeTest_Nty)
	//待机定时测试
	MESSAGE(Ev_NV_BLL_SleepTest_Nty)
	
	/*<<打开关闭电视机无信号>>
	*消息流向 sdk==>dispatch==>nvservice
	* Screen_type: 屏幕类型
	* open: 打开关闭电视机无信号
	*/
    MESSAGE(Ev_NV_BLL_SetTvSignal_Cmd)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::BOOL32, open)
	
	/*<<打开关闭电视机无信号通知>>
	*消息流向 nvservice==>dispatch==>sdk
	* Screen_type: 屏幕类型
	* open: 打开关闭电视机无信号
	*/
    MESSAGE(Ev_NV_BLL_SetTvSignal_Ntf)
	BODY(nv::TS32, Screen_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
	BODY(nv::BOOL32, open)
	
	/*<<界面下电通知>>
	*BODY ：
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_NvcSetTurnOff_Cmd)
	BODY(nv::TBOOL32, is_turnoff)

	/*<<定时关机界面进入倒计时请求>>
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_StartShutdownCount_Req)

	/*<<定时关机回复界面是否可以进入倒计时回应>>
	*BODY ：is_Count;是否可以进入倒计时
	*BODY ：reason:不能进入倒计时原因
	*nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_StartShutdownCount_Rsp)
	BODY(nv::TBOOL32, is_Count)
	BODY(nv::TS32, reason)

	/*<<每1秒通知界面当前自动关机倒计时状态>>
	*BODY ：is_Count;是否正在倒计时
	*BODY ：reason:退出倒计时原因
	*nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_ShutdownCount_Nty)
	BODY(nv::TBOOL32, is_Count)
	BODY(nv::TS32, reason)

	/*<<界面自动关机命令>>
	*
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_AutoShutdown_Cmd)

	/*<<总开关开机100s内有按压时通知>>
	*
	*nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_SwbRepeatTurnOn_Nty)
	
	/*<<总开关在系统开机时按键小于3秒通知>>
	*nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_SwbKey_Nty)
	
	/*<<通知总开关待机关机状态>>
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_SetSwbState_Cmd)
	BODY(nv::TS32, state)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvSwbState
#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(DEVICE) = EVSEG_BLL_DEVICE_END
};
#endif

#define Is_BLL_Device_Msg(m) ((m) >= EV_BLL_BGN(DEVICE) && (m) <= EV_BLL_END(DEVICE))

#endif