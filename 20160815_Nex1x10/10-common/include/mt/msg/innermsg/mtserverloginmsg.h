#ifndef _MTSERVERLOGINMSG_H_
#define _MTSERVERLOGINMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMtServerLoginMsg
{
	EV_BGN(MT_SERVERLOGIN) = EVSEG_LOGSERVER_BGN,
#endif

	/*<<��¼��������>>
	* 
	* 
	* UI-->�������-->��������¼��ϵͳ
	*/
//	MESSAGE(Ev_MT_Login_Tactics_Cmd)
//	BODY(mt::TMtLoginTacticsTable, )
	
	//���/�ռ�   ������������¼��Ϣ

	/*<<�ն� ��¼>>
	* 
	* 
	* UI-->�������-->��������¼��ϵͳ
	*/
	MESSAGE(Ev_MT_Login_Cmd)
	BODY(mt::TMtSvrListFromSDK, login_param)

	/*<<�ն� ע��>>
	* 
	* 
	* UI-->�������-->��������¼��ϵͳ
	*/
	MESSAGE(Ev_MT_Logout_Cmd)
	BODY(mt::TMtSvrListFromSDK, logout_param)

	/*<<������ ��¼����>>
	*��������¼��ϵͳ-->�������->�����ϵͳ
	*/
	MESSAGE(Ev_MT_Svr_Login_Cmd)
	BODY(mt::TMtSvrType, )

	/*<<������ ע������>>
	*��������¼��ϵͳ-->�������->�����ϵͳ
	*/
	MESSAGE(Ev_MT_Svr_Logout_Cmd)
	//BODY(mt::TU32, sqn);
	BODY(mt::TMtSvrType, )

	/*<<ĳ������ ״̬�ı�>>
	*�����ϵͳ-->�������-->��������¼��ϵͳ
	*/
	MESSAGE(Ev_MT_Svr_State_Ntf)
	//BODY(mt::TU32, sqn);
	BODY(mt::EmServerType, server_type)
	BODY(mt::EmServerState, login_state)

	/*<<ĳ������ ״̬�ı�>>
	*��������¼��ϵͳ --> UI
	*/
	MESSAGE(Ev_MT_Svr_Login_Result_Ntf)
	BODY(mt::TMtSvrLoginResultToSDK,)
	

    /*<<������������������>>
	*��������¼��ϵͳ --> dispatch --> UI
	*/
	MESSAGE(Ev_MT_Domain_Translation_Req)
	BODY(mt::TMTDomainTranslateReqToUI, )

	/*<<�����������������>>
	*UI --> dispatch --> ��������¼��ϵͳ 
	*/
	MESSAGE(Ev_MT_Domain_Translation_Rsp)
	BODY(mt::TMTDomainTranslateRspFromUI, )

	/*<<����������from CB>>
	*��������¼��ϵͳ --> dispatch
	*/
//	MESSAGE(Ev_MT_Dns_Api_Cb_Rsp)

	/*<<Aps��¼����>>
	*��������¼��ϵͳ --> dispatch
	*/
	MESSAGE(Ev_MT_LoginApsSvr_Req)
	BODY(mt::TU32, sqn)

	/*<<Aps��¼��Ӧ>>
	*Aps adpt --> dispatch
	*/
	MESSAGE(Ev_MT_LoginApsSvr_Rsp)
	BODY(mt::TU32, sqn)
	BODY(mt::TU32,)

	/*<<������������Ӧ>>
	*����������ģ�� --> dispatch
	*/
	MESSAGE(Ev_MT_ServerState_Ntf)
	BODY(mt::TU32,)
	BODY(mt::TU32,)

#if !defined(_MESSAGE_HELP_)
	EV_END(MT_SERVERLOGIN) = EVSEG_LOGSERVER_END
};
#endif

#endif //_MTSERVERLOGINMSG_H_