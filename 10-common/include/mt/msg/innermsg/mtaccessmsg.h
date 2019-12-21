#ifndef _MTACCESSMSG_H_
#define _MTACCESSMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMtAccessMsg
{
    EV_BGN(ACCESS) = EVSEG_ACCESS_BGN,
#endif//_MESSAGE_HELP_

	/*<<�ն˿ͻ����˺���֤����>>
	*loginuser_fullinfo ���˺���֤�û���ϸ��Ϣ
	*���䷽��mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_MTCLogin_Req)
	BODY(mt::TUserFullInfo, loginuser_fullinfo)

	/*<<�ն˿ͻ����˺���֤Ӧ��>>
	*login_rsp ���˺���֤Ӧ����
	*���䷽��access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_MTCLogin_Rsp)
	BODY(mt::TUserReqResult, loginuser_rsp)

	/*<<�ն���ӿͻ����˺�����>>
	*adduser_fullinfo ���ն���ӿͻ����˺���Ϣ
	*���䷽��mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_MTCAddUser_Req)
	BODY(mt::TMultiUserFullInfo, adduser_fullinfo)

	/*<<�ն˶Կͻ����˺Ž������Ӧ��>>
	*adduser_rsp ���ն˶Կͻ����˺Ž������Ӧ����
	*���䷽��access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_MTCAddUser_Rsp)
	BODY(mt::TMultiUserReqResult, adduser_rsp)

	/*<<�ն˶Կͻ����˺Ž�������˺���Ϣ֪ͨ>>
	*adduser_ntf ���ն˶Կͻ����˺Ž�������˺���Ϣ
	*���䷽��access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_MTCAddUser_Ntf)
	BODY(mt::TMultiUserFullInfo, adduser_ntf)

	/*<<�ն˶Կͻ����˺Ž����޸�����>>
	*muser_fullinfo �������޸�����ͻ����˺���Ϣ
	*���䷽��mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_MTCMUser_Req)
	BODY(mt::TMultiUserFullInfo, muser_fullinfo)

	/*<<�ն˶Կͻ����˺Ž����޸�Ӧ��>>
	*muser_rsp ���ն˶Կͻ����˺Ž����޸�Ӧ����
	*���䷽��access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_MTCMUser_Rsp)
	BODY(mt::TMultiUserReqResult, muser_rsp)

	/*<<�ն˶Կͻ����˺Ž����޸��˺���Ϣ֪ͨ>>
	*muser_ntf ���ն˶Կͻ����˺Ž����޸��˺���Ϣ
	*���䷽��access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_MTCMUser_Ntf)
	BODY(mt::TMultiUserFullInfo, muser_ntf)

	/*<<�ն˶Կͻ����˺Ž���ɾ������>>
	*duser ������ɾ������ͻ����˺�ID��Ϣ
	*���䷽��mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_MTCDUser_Req)
	BODY(mt::TMultiU32, duserids)

	/*<<�ն˶Կͻ����˺Ž���ɾ��Ӧ��>>
	*duser_rsp ���ն˶Կͻ����˺Ž���ɾ��Ӧ����
	*���䷽��access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_MTCDUser_Rsp)
	BODY(mt::TMultiUserReqResult, duser_rsp)

	/*<<�ն˶Կͻ����˺Ž���ɾ���˺���Ϣ֪ͨ>>
	*duser_ntf ���ն˶Կͻ����˺Ž���ɾ���˺���Ϣ
	*���䷽��access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_MTCDUser_Ntf)
	BODY(mt::TMultiUserFullInfo, duser_ntf)

	/*<<�ն˶Կͻ����˺Ž��в�ѯ����>>
	*���䷽��mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_MTCSUser_Req)

	/*<<�ն˶Կͻ����˺Ž��в�ѯӦ��>>
	*duser_rsp ���ն˶Կͻ����˺Ž��в�ѯӦ����
	*���䷽��access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_MTCSUser_Rsp)
	BODY(mt::TMultiUserFullInfo, duser_rsp)

	/*<<�ն˿ͻ����˺�ע������>>
	*user_name ���û���
	*���䷽��mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_MTCLogOut_Cmd)
	BODY(mt::TString, user_name)

	/*<<�ն˿ͻ����˺�ע��֪ͨ>>
	*Ev_MT_MTCLogOut_Ntf ���˺���֤�û���ϸ��Ϣ
	*logoutuser_fullinfo ��ע���˺��û���ϸ��Ϣ
	*���䷽��access->dispatch->������
	*/
	MESSAGE(Ev_MT_MTCLogOut_Ntf)
	BODY(mt::TUserFullInfo, logoutuser_fullinfo)

	/*<<skyshare��¼״̬֪ͨ>>
	*Ev_MT_MTCSkyShareLoginState_Ntf ��skyshare��¼״̬
	*loginstate ����¼״̬
	*���䷽��access->dispatch->������
	*/
	MESSAGE(Ev_MT_MTCSkyShareLoginState_Ntf)
	BODY(mt::TBOOL32, loginstate)

	/*<<skyshare��¼״̬����>>
	*���䷽��mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_MTCSkyShareLoginState_Req)
	
	/*<<skyshare��¼״̬Rsp>>
	*Ev_MT_MTCSkyShareLoginState_Rsp ��skyshare��¼״̬
	*loginstate ����¼״̬
	*���䷽��access->dispatch->������
	*/
	MESSAGE(Ev_MT_MTCSkyShareLoginState_Rsp)
	BODY(mt::TBOOL32, loginstate)
#if !defined(_MESSAGE_HELP_)
    EV_END(ACCESS) = EVSEG_ACCESS_END
};
#endif//_MESSAGE_HELP_

#define Is_Access_Msg(m) ((m) >= EV_BGN(ACCESS) && (m) <= EV_END(ACCESS))

#endif//_MTACCESSMSG_H_