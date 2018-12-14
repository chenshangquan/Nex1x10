#ifndef _NVSERVERLOGINMSG_H_
#define _NVSERVERLOGINMSG_H_

#include "nvmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmNvServerLoginMsg
{
	EV_BGN(NV_SERVERLOGIN) = EVSEG_LOGSERVER_BGN,
#endif

	/*<<登录策略设置>>
	* 
	* 
	* UI-->接入调度-->服务器登录子系统
	*/
//	MESSAGE(Ev_NV_Login_Tactics_Cmd)
//	BODY(nv::TNvLoginTacticsTable, )
	
	//添加/收集   单个服务器登录消息

	/*<<终端 登录>>
	* 
	* 
	* UI-->接入调度-->服务器登录子系统
	*/
	MESSAGE(Ev_NV_Login_Cmd)
	BODY(nv::TNvSvrListFromSDK, login_param)

	/*<<终端 注销>>
	* 
	* 
	* UI-->接入调度-->服务器登录子系统
	*/
	MESSAGE(Ev_NV_Logout_Cmd)
	BODY(nv::TNvSvrListFromSDK, logout_param)

	/*<<服务器 登录命令>>
	*服务器登录子系统-->接入调度->相关子系统
	*/
	MESSAGE(Ev_NV_Svr_Login_Cmd)
	BODY(nv::TNvSvrType, )

	/*<<服务器 注销命令>>
	*服务器登录子系统-->接入调度->相关子系统
	*/
	MESSAGE(Ev_NV_Svr_Logout_Cmd)
	//BODY(nv::TU32, sqn);
	BODY(nv::TNvSvrType, )

	/*<<某服务器 状态改变>>
	*相关子系统-->接入调度-->服务器登录子系统
	*/
	MESSAGE(Ev_NV_Svr_State_Ntf)
	//BODY(nv::TU32, sqn);
	BODY(nv::EmServerType, server_type)
	BODY(nv::EmServerState, login_state)

	/*<<某服务器 状态改变>>
	*服务器登录子系统 --> UI
	*/
	MESSAGE(Ev_NV_Svr_Login_Result_Ntf)
	BODY(nv::TNvSvrLoginResultToSDK,)
	

    /*<<服务器域名解析请求>>
	*服务器登录子系统 --> dispatch --> UI
	*/
	MESSAGE(Ev_NV_Domain_Translation_Req)
	BODY(nv::TNVDomainTranslateReqToUI, )

	/*<<服务器域名解析结果>>
	*UI --> dispatch --> 服务器登录子系统 
	*/
	MESSAGE(Ev_NV_Domain_Translation_Rsp)
	BODY(nv::TNVDomainTranslateRspFromUI, )

	/*<<域名解析，from CB>>
	*服务器登录子系统 --> dispatch
	*/
//	MESSAGE(Ev_NV_Dns_Api_Cb_Rsp)

	/*<<Aps登录请求>>
	*服务器登录子系统 --> dispatch
	*/
	MESSAGE(Ev_NV_LoginApsSvr_Req)
	BODY(nv::TU32, sqn)

	/*<<Aps登录响应>>
	*Aps adpt --> dispatch
	*/
	MESSAGE(Ev_NV_LoginApsSvr_Rsp)
	BODY(nv::TU32, sqn)
	BODY(nv::TU32,)

#if !defined(_MESSAGE_HELP_)
	EV_END(NV_SERVERLOGIN) = EVSEG_LOGSERVER_END
};
#endif

#endif //_NVSERVERLOGINMSG_H_