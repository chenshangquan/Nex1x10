#ifndef _NVBLLSERVERLOGINMSG_H_
#define _NVBLLSERVERLOGINMSG_H_

#include "nvmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmNvBLLServerLoginMsg
{
	EV_BLL_BGN(NV_SERVERLOGIN) = EVSEG_BLL_LOGSERVER_BGN,
#endif

	/*<<��¼��������>>
	* 
	* 	
	//���/�ռ�   ������������¼��Ϣ

	/*<<�ն� ��¼>>
	* 
	* 
	* UI-->�������-->��������¼��ϵͳ
	*/
	MESSAGE(Ev_NV_BLL_Login_Cmd)
	BODY(nv::TNvSvrListFromSDK, login_param)

	/*<<�ն� ע��>>
	* 
	* 
	* UI-->�������-->��������¼��ϵͳ
	*/
	MESSAGE(Ev_NV_BLL_Logout_Cmd)
	BODY(nv::TNvSvrListFromSDK, logout_param)

	/*<<������ ��¼����>>
	*��������¼��ϵͳ-->�������->�����ϵͳ
	*/
//	MESSAGE(Ev_NV_BLL_Svr_Login_Cmd)
//	BODY(nv::TNvSvrType, )

	/*<<������ ע������>>
	*��������¼��ϵͳ-->�������->�����ϵͳ
	*/
//	MESSAGE(Ev_NV_BLL_Svr_Logout_Cmd)
	//BODY(nv::TU32, sqn);
//	BODY(nv::TNvSvrType, )

	/*<<ĳ������ ״̬�ı�>>
	*�����ϵͳ-->�������-->��������¼��ϵͳ
	*/
//	MESSAGE(Ev_NV_BLL_Svr_State_Ntf)
	//BODY(nv::TU32, sqn);
//	BODY(nv::EmServerType, server_type)
//	BODY(nv::EmServerState, login_state)

	/*<<ĳ������ ״̬�ı�>>
	*��������¼��ϵͳ --> UI
	*/
	MESSAGE(Ev_NV_BLL_Svr_Login_Result_Ntf)
	BODY(nv::TNvSvrLoginResultToSDK,)
	

    /*<<������������������>>
	*��������¼��ϵͳ --> dispatch --> UI
	*/
	MESSAGE(Ev_NV_BLL_Domain_Translation_Req)
	BODY(nv::TNVDomainTranslateReqToUI, )

	/*<<�����������������>>
	*UI --> dispatch --> ��������¼��ϵͳ 
	*/
	MESSAGE(Ev_NV_BLL_Domain_Translation_Rsp)
	BODY(nv::TNVDomainTranslateRspFromUI, )

	/*<<����������from CB>>
	*��������¼��ϵͳ --> dispatch
	*/
//	MESSAGE(Ev_NV_BLL_Dns_Api_Cb_Rsp)

	/*<<Aps��¼����>>
	*sdk --> dispatch
	*/
	MESSAGE(Ev_NV_BLL_LoginApsSvr_Cmd)
	BODY(nv::TNvLoginApsParam,)

	/*<<Aps�ǳ�����>>
	*sdk --> dispatch
	*/
	MESSAGE(Ev_NV_BLL_LogoutApsSvr_Cmd)


#if !defined(_MESSAGE_HELP_)
	EV_BLL_END(NV_SERVERLOGIN) = EVSEG_BLL_LOGSERVER_END
};
#endif

#endif //_NVBLLSERVERLOGINMSG_H_