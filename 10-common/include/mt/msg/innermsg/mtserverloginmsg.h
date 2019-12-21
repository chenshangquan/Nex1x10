#ifndef _MTSERVERLOGINMSG_H_
#define _MTSERVERLOGINMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMtServerLoginMsg
{
	EV_BGN(MT_SERVERLOGIN) = EVSEG_LOGSERVER_BGN,
#endif

	/*<<登录策略设置>>
	* 
	* 
	* UI-->接入调度-->服务器登录子系统
	*/
//	MESSAGE(Ev_MT_Login_Tactics_Cmd)
//	BODY(mt::TMtLoginTacticsTable, )
	
	//添加/收集   单个服务器登录消息

	/*<<终端 登录>>
	* 
	* 
	* UI-->接入调度-->服务器登录子系统
	*/
	MESSAGE(Ev_MT_Login_Cmd)
	BODY(mt::TMtSvrListFromSDK, login_param)

	/*<<终端 注销>>
	* 
	* 
	* UI-->接入调度-->服务器登录子系统
	*/
	MESSAGE(Ev_MT_Logout_Cmd)
	BODY(mt::TMtSvrListFromSDK, logout_param)

	/*<<服务器 登录命令>>
	*服务器登录子系统-->接入调度->相关子系统
	*/
	MESSAGE(Ev_MT_Svr_Login_Cmd)
	BODY(mt::TMtSvrType, )

	/*<<服务器 注销命令>>
	*服务器登录子系统-->接入调度->相关子系统
	*/
	MESSAGE(Ev_MT_Svr_Logout_Cmd)
	//BODY(mt::TU32, sqn);
	BODY(mt::TMtSvrType, )

	/*<<某服务器 状态改变>>
	*相关子系统-->接入调度-->服务器登录子系统
	*/
	MESSAGE(Ev_MT_Svr_State_Ntf)
	//BODY(mt::TU32, sqn);
	BODY(mt::EmServerType, server_type)
	BODY(mt::EmServerState, login_state)

	/*<<某服务器 状态改变>>
	*服务器登录子系统 --> UI
	*/
	MESSAGE(Ev_MT_Svr_Login_Result_Ntf)
	BODY(mt::TMtSvrLoginResultToSDK,)
	

    /*<<服务器域名解析请求>>
	*服务器登录子系统 --> dispatch --> UI
	*/
	MESSAGE(Ev_MT_Domain_Translation_Req)
	BODY(mt::TMTDomainTranslateReqToUI, )

	/*<<服务器域名解析结果>>
	*UI --> dispatch --> 服务器登录子系统 
	*/
	MESSAGE(Ev_MT_Domain_Translation_Rsp)
	BODY(mt::TMTDomainTranslateRspFromUI, )

	/*<<域名解析，from CB>>
	*服务器登录子系统 --> dispatch
	*/
//	MESSAGE(Ev_MT_Dns_Api_Cb_Rsp)

	/*<<Aps登录请求>>
	*服务器登录子系统 --> dispatch
	*/
	MESSAGE(Ev_MT_LoginApsSvr_Req)
	BODY(mt::TU32, sqn)

	/*<<Aps登录响应>>
	*Aps adpt --> dispatch
	*/
	MESSAGE(Ev_MT_LoginApsSvr_Rsp)
	BODY(mt::TU32, sqn)
	BODY(mt::TU32,)

	/*<<服务器断链响应>>
	*各服务器吗模块 --> dispatch
	*/
	MESSAGE(Ev_MT_ServerState_Ntf)
	BODY(mt::TU32,)
	BODY(mt::TU32,)

#if !defined(_MESSAGE_HELP_)
	EV_END(MT_SERVERLOGIN) = EVSEG_LOGSERVER_END
};
#endif

#endif //_MTSERVERLOGINMSG_H_