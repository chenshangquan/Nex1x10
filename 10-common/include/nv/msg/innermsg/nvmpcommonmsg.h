#ifndef _NVMPCOMMONMSG_H_
#define _NVMPCOMMONMSG_H_

#include "nvmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMPCommonMsg
{
    EV_BGN(MPCOMMON) = EVSEG_MPCOMMON_BGN,
#endif

	/*<<切换画面命令>>
	* pic ：选看画面内容
	* is_imix ：1切换imix输出画面，0切换终端显示画面
	* is_hdmi0 ：1：切换hdmi0,0切换hdmi1
	*消息流向 nvservice ==>dispatch==>
	*/
	MESSAGE(Ev_NV_ViewPic_Cmd)         
	BODY(nv::TS32, pic) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvImixVidSrcType
	BODY(nv::TBOOL32, is_imix)
	BODY(nv::TBOOL32, is_hdmi0)	
	BODY(nv::TBOOL32, is_FromUI)
	
	/*<<切换画面回复>>
	* pic ：选看画面内容
	* is_sucess ：是否切换成功
	*消息流向  ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_ViewPic_Ntf)         
	BODY(nv::TS32, pic) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvImixVidSrcType
	BODY(nv::TBOOL32, is_sucess)

	MESSAGE(Ev_NV_SocketReaccept_Cmd)

	/*<<当前画面状态通知>>
	* pic ：选看画面内容
	*bIsFromUI:是否来自UI的选看命令
	*消息流向 nvmp ==>dispatch==nvservice
	*/
	MESSAGE(Ev_NV_PicStatus_Ntf)         
	BODY(nv::TS32, pic) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvImixVidSrcType
	BODY(nv::TBOOL32, bIsFromUI)
	
#if !defined(_MESSAGE_HELP_)
    EV_END(MPCOMMON) = EVSEG_MPCOMMON_END
};
#endif

#define Is_MPCommon_Msg(m) ((m) >= Ev_NV_BGN(MPCOMMON) && (m) <= Ev_NV_END(MPCOMMON))

#endif // _NVMPCOMMONMSG_H_