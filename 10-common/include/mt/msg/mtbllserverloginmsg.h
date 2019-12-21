#ifndef _MTBLLSERVERLOGINMSG_H_
#define _MTBLLSERVERLOGINMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMtBLLServerLoginMsg
{
	EV_BLL_BGN(MT_SERVERLOGIN) = EVSEG_BLL_LOGSERVER_BGN,
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
	MESSAGE(Ev_MT_BLL_Login_Cmd)
	BODY(mt::TMtSvrListFromSDK, login_param)

	/*<<�ն� ע��>>
	* 
	* 
	* UI-->�������-->��������¼��ϵͳ
	*/
	MESSAGE(Ev_MT_BLL_Logout_Cmd)
	BODY(mt::TMtSvrListFromSDK, logout_param)

	/*<<������ ��¼����>>
	*��������¼��ϵͳ-->�������->�����ϵͳ
	*/
//	MESSAGE(Ev_MT_BLL_Svr_Login_Cmd)
//	BODY(mt::TMtSvrType, )

	/*<<������ ע������>>
	*��������¼��ϵͳ-->�������->�����ϵͳ
	*/
//	MESSAGE(Ev_MT_BLL_Svr_Logout_Cmd)
	//BODY(mt::TU32, sqn);
//	BODY(mt::TMtSvrType, )

	/*<<ĳ������ ״̬�ı�>>
	*�����ϵͳ-->�������-->��������¼��ϵͳ
	*/
//	MESSAGE(Ev_MT_BLL_Svr_State_Ntf)
	//BODY(mt::TU32, sqn);
//	BODY(mt::EmServerType, server_type)
//	BODY(mt::EmServerState, login_state)

	/*<<APS��������½���>>
	*mtservice --> UI
	*/
	MESSAGE(Ev_MT_BLL_ApsLoginResult_Ntf)
	BODY(mt::TMtApsLoginErrcode,)
    BODY(mt::TMtPlatformInfo, )
	/*<<ĳ������ ״̬�ı�>>
	*��������¼��ϵͳ --> UI
	*/
	MESSAGE(Ev_MT_BLL_Svr_Login_Result_Ntf)
	BODY(mt::TMtSvrLoginResultToSDK,)
	

    /*<<������������������>>
	*��������¼��ϵͳ --> dispatch --> UI
	*/
	MESSAGE(Ev_MT_BLL_Domain_Translation_Req)
	BODY(mt::TMTDomainTranslateReqToUI, )

	/*<<�����������������>>
	*UI --> dispatch --> ��������¼��ϵͳ 
	*/
	MESSAGE(Ev_MT_BLL_Domain_Translation_Rsp)
	BODY(mt::TMTDomainTranslateRspFromUI, )

	/*<<����������from CB>>
	*��������¼��ϵͳ --> dispatch
	*/
//	MESSAGE(Ev_MT_BLL_Dns_Api_Cb_Rsp)

	/*<<Aps��¼����>>
	*sdk --> dispatch
	*/
	MESSAGE(Ev_MT_BLL_LoginApsSvr_Cmd)
	BODY(mt::TMtLoginApsParam,)

	/*<<Aps�ǳ�����>>
	*sdk --> dispatch
	*/
	MESSAGE(Ev_MT_BLL_LogoutApsSvr_Cmd)

    
	/*<<��ȡ��½aps�󣬷�������Ϣ>>
	*sdk --> dispatch
	*/
	MESSAGE(Ev_MT_BLL_GetAPSPlatformInfo_Req)

    /*<<��ȡ��½aps�󣬷�������Ϣ���ؽ��>>
	*mtservice --> UI
	*/
	MESSAGE(Ev_MT_BLL_GetAPSPlatformInfo_Rsp)
    BODY(mt::TMtPlatformInfo, )

#if !defined(_MESSAGE_HELP_)
	EV_BLL_END(MT_SERVERLOGIN) = EVSEG_BLL_LOGSERVER_END
};
#endif

#endif //_MTBLLSERVERLOGINMSG_H_