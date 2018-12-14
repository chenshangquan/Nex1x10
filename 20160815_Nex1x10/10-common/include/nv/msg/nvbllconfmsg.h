#ifndef _NVBLLCONFMSG_H_
#define _NVBLLCONFMSG_H_

#include "nvmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLNvConfMsg
{

	
	EV_BLL_BGN(CONF) = EVSEG_BLL_CONF_BGN,
#endif
	
	/*<<获取终端主视频显示画面>>
	*传输方向：sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_GetMtPic_Req)
	
	/*<<获取终端主视频显示画面回复>>
	*传输方向：sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_GetMtPic_Rsp)
	BODY(nv::TS32, pic) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvImixVidSrcType
	
	/*<<当前终端主视频显示画面通知>>
	*传输方向：sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_SetMtPic_Ntf)
	BODY(nv::TS32, pic) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvImixVidSrcType
	
#if !defined(_MESSAGE_HELP_)
	EV_BLL_END(CONF) = EVSEG_BLL_CONF_END
};
#endif

#define Is_BLL_Nvconf_Msg(m) ((m) >= EV_BLL_BGN(CONF) && (m) <= EV_BLL_END(CONF))

#endif