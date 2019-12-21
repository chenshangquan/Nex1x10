#ifndef _NVACCESSMSG_H_
#define _NVACCESSMSG_H_

#include "nvmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmNvAccessMsg
{
    EV_BGN(ACCESS) = EVSEG_ACCESS_BGN,
#endif//_MESSAGE_HELP_

	/*<<�ն˿ͻ����˺���֤����>>
	*loginuser_fullinfo ���˺���֤�û���ϸ��Ϣ
	*���䷽��nvc->dispatch->access
	*/
	MESSAGE(Ev_NV_NVCLogin_Req)
	BODY(nv::TUserFullInfo, loginuser_fullinfo)

	/*<<�ն˿ͻ����˺���֤Ӧ��>>
	*login_rsp ���˺���֤Ӧ����
	*���䷽��access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_NVCLogin_Rsp)
	BODY(nv::TUserReqResult, loginuser_rsp)

	/*<<�ն���ӿͻ����˺�����>>
	*adduser_fullinfo ���ն���ӿͻ����˺���Ϣ
	*���䷽��nvc->dispatch->access
	*/
	MESSAGE(Ev_NV_NVCAddUser_Req)
	BODY(nv::TMultiUserFullInfo, adduser_fullinfo)

	/*<<�ն˶Կͻ����˺Ž������Ӧ��>>
	*adduser_rsp ���ն˶Կͻ����˺Ž������Ӧ����
	*���䷽��access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_NVCAddUser_Rsp)
	BODY(nv::TMultiUserReqResult, adduser_rsp)

	/*<<�ն˶Կͻ����˺Ž�������˺���Ϣ֪ͨ>>
	*adduser_ntf ���ն˶Կͻ����˺Ž�������˺���Ϣ
	*���䷽��access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_NVCAddUser_Ntf)
	BODY(nv::TMultiUserFullInfo, adduser_ntf)

	/*<<�ն˶Կͻ����˺Ž����޸�����>>
	*muser_fullinfo �������޸�����ͻ����˺���Ϣ
	*���䷽��nvc->dispatch->access
	*/
	MESSAGE(Ev_NV_NVCMUser_Req)
	BODY(nv::TMultiUserFullInfo, muser_fullinfo)

	/*<<�ն˶Կͻ����˺Ž����޸�Ӧ��>>
	*muser_rsp ���ն˶Կͻ����˺Ž����޸�Ӧ����
	*���䷽��access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_NVCMUser_Rsp)
	BODY(nv::TMultiUserReqResult, muser_rsp)

	/*<<�ն˶Կͻ����˺Ž����޸��˺���Ϣ֪ͨ>>
	*muser_ntf ���ն˶Կͻ����˺Ž����޸��˺���Ϣ
	*���䷽��access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_NVCMUser_Ntf)
	BODY(nv::TMultiUserFullInfo, muser_ntf)

	/*<<�ն˶Կͻ����˺Ž���ɾ������>>
	*duser ������ɾ������ͻ����˺�ID��Ϣ
	*���䷽��nvc->dispatch->access
	*/
	MESSAGE(Ev_NV_NVCDUser_Req)
	BODY(nv::TMultiU32, duserids)

	/*<<�ն˶Կͻ����˺Ž���ɾ��Ӧ��>>
	*duser_rsp ���ն˶Կͻ����˺Ž���ɾ��Ӧ����
	*���䷽��access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_NVCDUser_Rsp)
	BODY(nv::TMultiUserReqResult, duser_rsp)

	/*<<�ն˶Կͻ����˺Ž���ɾ���˺���Ϣ֪ͨ>>
	*duser_ntf ���ն˶Կͻ����˺Ž���ɾ���˺���Ϣ
	*���䷽��access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_NVCDUser_Ntf)
	BODY(nv::TMultiUserFullInfo, duser_ntf)

	/*<<�ն˶Կͻ����˺Ž��в�ѯ����>>
	*���䷽��nvc->dispatch->access
	*/
	MESSAGE(Ev_NV_NVCSUser_Req)

	/*<<�ն˶Կͻ����˺Ž��в�ѯӦ��>>
	*duser_rsp ���ն˶Կͻ����˺Ž��в�ѯӦ����
	*���䷽��access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_NVCSUser_Rsp)
	BODY(nv::TMultiUserFullInfo, duser_rsp)

	/*<<�ն˿ͻ����˺�ע������>>
	*user_name ���û���
	*���䷽��nvc->dispatch->access
	*/
	MESSAGE(Ev_NV_NVCLogOut_Cmd)
	BODY(nv::TString, user_name)

	/*<<�ն˿ͻ����˺�ע��֪ͨ>>
	*Ev_NV_NVCLogOut_Ntf ���˺���֤�û���ϸ��Ϣ
	*logoutuser_fullinfo ��ע���˺��û���ϸ��Ϣ
	*���䷽��access->dispatch->������
	*/
	MESSAGE(Ev_NV_NVCLogOut_Ntf)
	BODY(nv::TUserFullInfo, logoutuser_fullinfo)

	/*<<��������״̬�ظ�>>
	*
	*/
	MESSAGE(Ev_NV_MfgTest_Ntf)
	BODY(nv::TBOOL32, bMftTest)

	/*<<��������״̬�ظ�>>
	*
	*/
	MESSAGE(Ev_NV_MfgTest_Rsp)
	BODY(nv::TBOOL32, bMftTest)
	/*<<Tpad��¼֪ͨ>>
	*
	*/
	MESSAGE(Ev_NV_TpadLogin_Ntf)
#if !defined(_MESSAGE_HELP_)
    EV_END(ACCESS) = EVSEG_ACCESS_END
};
#endif//_MESSAGE_HELP_

#define Is_Access_Msg(m) ((m) >= EV_BGN(ACCESS) && (m) <= EV_END(ACCESS))

#endif//_NVACCESSMSG_H_