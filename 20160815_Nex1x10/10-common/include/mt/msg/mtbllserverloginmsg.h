#ifndef _MTBLLSERVERLOGINMSG_H_
#define _MTBLLSERVERLOGINMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMtBLLServerLoginMsg
{
	EV_BLL_BGN(MT_SERVERLOGIN) = EVSEG_BLL_LOGSERVER_BGN,
#endif

	/*<<登录策略设置>>
	* 
	* 	
	//添加/收集   单个服务器登录消息

	/*<<终端 登录>>
	* 
	* 
	* UI-->接入调度-->服务器登录子系统
	*/
	MESSAGE(Ev_MT_BLL_Login_Cmd)
	BODY(mt::TMtSvrListFromSDK, login_param)

	/*<<终端 注销>>
	* 
	* 
	* UI-->接入调度-->服务器登录子系统
	*/
	MESSAGE(Ev_MT_BLL_Logout_Cmd)
	BODY(mt::TMtSvrListFromSDK, logout_param)

	/*<<服务器 登录命令>>
	*服务器登录子系统-->接入调度->相关子系统
	*/
//	MESSAGE(Ev_MT_BLL_Svr_Login_Cmd)
//	BODY(mt::TMtSvrType, )

	/*<<服务器 注销命令>>
	*服务器登录子系统-->接入调度->相关子系统
	*/
//	MESSAGE(Ev_MT_BLL_Svr_Logout_Cmd)
	//BODY(mt::TU32, sqn);
//	BODY(mt::TMtSvrType, )

	/*<<某服务器 状态改变>>
	*相关子系统-->接入调度-->服务器登录子系统
	*/
//	MESSAGE(Ev_MT_BLL_Svr_State_Ntf)
	//BODY(mt::TU32, sqn);
//	BODY(mt::EmServerType, server_type)
//	BODY(mt::EmServerState, login_state)

	/*<<APS服务器登陆结果>>
	*mtservice --> UI
	*/
	MESSAGE(Ev_MT_BLL_ApsLoginResult_Ntf)
	BODY(mt::TMtApsLoginErrcode,)
    BODY(mt::TMtPlatformInfo, )
	/*<<某服务器 状态改变>>
	*服务器登录子系统 --> UI
	*/
	MESSAGE(Ev_MT_BLL_Svr_Login_Result_Ntf)
	BODY(mt::TMtSvrLoginResultToSDK,)
	

    /*<<服务器域名解析请求>>
	*服务器登录子系统 --> dispatch --> UI
	*/
	MESSAGE(Ev_MT_BLL_Domain_Translation_Req)
	BODY(mt::TMTDomainTranslateReqToUI, )

	/*<<服务器域名解析结果>>
	*UI --> dispatch --> 服务器登录子系统 
	*/
	MESSAGE(Ev_MT_BLL_Domain_Translation_Rsp)
	BODY(mt::TMTDomainTranslateRspFromUI, )

	/*<<域名解析，from CB>>
	*服务器登录子系统 --> dispatch
	*/
//	MESSAGE(Ev_MT_BLL_Dns_Api_Cb_Rsp)

	/*<<Aps登录命令>>
	*sdk --> dispatch
	*/
	MESSAGE(Ev_MT_BLL_LoginApsSvr_Cmd)
	BODY(mt::TMtLoginApsParam,)

	/*<<Aps登出命令>>
	*sdk --> dispatch
	*/
	MESSAGE(Ev_MT_BLL_LogoutApsSvr_Cmd)

    
	/*<<获取登陆aps后，服务器信息>>
	*sdk --> dispatch
	*/
	MESSAGE(Ev_MT_BLL_GetAPSPlatformInfo_Req)

    /*<<获取登陆aps后，服务器信息返回结果>>
	*mtservice --> UI
	*/
	MESSAGE(Ev_MT_BLL_GetAPSPlatformInfo_Rsp)
    BODY(mt::TMtPlatformInfo, )

#if !defined(_MESSAGE_HELP_)
	EV_BLL_END(MT_SERVERLOGIN) = EVSEG_BLL_LOGSERVER_END
};
#endif

#endif //_MTBLLSERVERLOGINMSG_H_