#ifndef _NVBLLACCESSMSG_H_
#define _NVBLLACCESSMSG_H_

#include "nvmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLNvAccessMsg
{
    EV_BLL_BGN(ACCESS) = EVSEG_BLL_ACCESS_BGN,
#endif//_MESSAGE_HELP_

	/*<<�ն˿ͻ����˺���֤����>>
	*loginuser_fullinfo ���˺���֤�û���ϸ��Ϣ
	*���䷽��nvc->dispatch->access
	*/
	MESSAGE(Ev_NV_BLL_NVCLogin_Req)
	BODY(nv::TUserFullInfo, loginuser_fullinfo)

	/*<<�ն˿ͻ����˺���֤Ӧ��>>
	*login_rsp ���˺���֤Ӧ����
	*���䷽��access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_BLL_NVCLogin_Rsp)
	BODY(nv::TUserReqResult, loginuser_rsp)

	/*<<�ն���ӿͻ����˺�����>>
	*adduser_fullinfo ���ն���ӿͻ����˺���Ϣ
	*���䷽��nvc->dispatch->access
	*/
	MESSAGE(Ev_NV_BLL_NVCAddUser_Req)
	BODY(nv::TMultiUserFullInfo, adduser_fullinfo)

	/*<<�ն˶Կͻ����˺Ž������Ӧ��>>
	*adduser_rsp ���ն˶Կͻ����˺Ž������Ӧ����
	*���䷽��access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_BLL_NVCAddUser_Rsp)
	BODY(nv::TMultiUserReqResult, adduser_rsp)

	/*<<�ն˶Կͻ����˺Ž�������˺���Ϣ֪ͨ>>
	*adduser_ntf ���ն˶Կͻ����˺Ž�������˺���Ϣ
	*���䷽��access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_BLL_NVCAddUser_Ntf)
	BODY(nv::TMultiUserFullInfo, adduser_ntf)

	/*<<�ն˶Կͻ����˺Ž����޸�����>>
	*muser_fullinfo �������޸�����ͻ����˺���Ϣ
	*���䷽��nvc->dispatch->access
	*/
	MESSAGE(Ev_NV_BLL_NVCMUser_Req)
	BODY(nv::TMultiUserFullInfo, muser_fullinfo)

	/*<<�ն˶Կͻ����˺Ž����޸�Ӧ��>>
	*muser_rsp ���ն˶Կͻ����˺Ž����޸�Ӧ����
	*���䷽��access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_BLL_NVCMUser_Rsp)
	BODY(nv::TMultiUserReqResult, muser_rsp)

	/*<<�ն˶Կͻ����˺Ž����޸��˺���Ϣ֪ͨ>>
	*muser_ntf ���ն˶Կͻ����˺Ž����޸��˺���Ϣ
	*���䷽��access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_BLL_NVCMUser_Ntf)
	BODY(nv::TMultiUserFullInfo, muser_ntf)

	/*<<�ն˶Կͻ����˺Ž���ɾ������>>
	*duser ������ɾ������ͻ����˺�ID��Ϣ
	*���䷽��nvc->dispatch->access
	*/
	MESSAGE(Ev_NV_BLL_NVCDUser_Req)
	BODY(nv::TMultiU32, duserids)

	/*<<�ն˶Կͻ����˺Ž���ɾ��Ӧ��>>
	*duser_rsp ���ն˶Կͻ����˺Ž���ɾ��Ӧ����
	*���䷽��access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_BLL_NVCDUser_Rsp)
	BODY(nv::TMultiUserReqResult, duser_rsp)

	/*<<�ն˶Կͻ����˺Ž���ɾ���˺���Ϣ֪ͨ>>
	*duser_ntf ���ն˶Կͻ����˺Ž���ɾ���˺���Ϣ
	*���䷽��access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_BLL_NVCDUser_Ntf)
	BODY(nv::TMultiUserFullInfo, duser_ntf)

	/*<<�ն˶Կͻ����˺Ž��в�ѯ����>>
	*���䷽��nvc->dispatch->access
	*/
	MESSAGE(Ev_NV_BLL_NVCSUser_Req)

	/*<<�ն˶Կͻ����˺Ž��в�ѯӦ��>>
	*duser_rsp ���ն˶Կͻ����˺Ž��в�ѯӦ����
	*���䷽��access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_BLL_NVCSUser_Rsp)
	BODY(nv::TMultiUserFullInfo, duser_rsp)

	/*<<�ն˿ͻ����˺�ע������>>
	*user_name ���û���
	*���䷽��nvc->dispatch->access
	*/
	MESSAGE(Ev_NV_BLL_NVCLogOut_Cmd)
	BODY(nv::TString, user_name)

	/*<<�ն˿ͻ����˺�ע��֪ͨ>>
	*Ev_NV_BLL_NVCLogOut_Ntf ���˺���֤�û���ϸ��Ϣ
	*logoutuser_fullinfo ��ע���˺��û���ϸ��Ϣ
	*���䷽��access->dispatch->������
	*/
	MESSAGE(Ev_NV_BLL_NVCLogOut_Ntf)
	BODY(nv::TUserFullInfo, logoutuser_fullinfo)

	/*<<��������״̬�ظ�>>
	*
	*/
	MESSAGE(Ev_NV_BLL_MfgTest_Ntf)
	BODY(nv::TBOOL32, bMftTest)

	/*<<��������״̬�ظ�>>
	*
	*/
	MESSAGE(Ev_NV_BLL_MfgTest_Rsp)
	BODY(nv::TBOOL32, bMftTest)

	/*<<imix�汾������>>
	*
	*/
	MESSAGE(Ev_NV_BLL_NVVersion_Req)

	/*<<imix�汾�Ż�Ӧ>>
	*
	*/
	MESSAGE(Ev_NV_BLL_NVVersion_Rsp)
	BODY(nv::TString, imix_ver)

	/*<<imix�Ƿ���JDƽ̨�İ汾һ��>>
	*
	*/
	MESSAGE(Ev_NV_BLL_NVVerIsSameAsJDServer_Req)

	/*<<imix��JDƽ̨�İ汾�ȽϺ�Ļ�Ӧ>>
	*
	*/
	MESSAGE(Ev_NV_BLL_NVVerIsSameAsJDServer_Rsp)
	BODY(nv::TBOOL32, bIsSame)

	/*<<imix�Ƿ��JDƽ̨���°汾>>
	*
	*/
	MESSAGE(Ev_NV_BLL_NVIsUpgradeFromJDServer_Cmd)
	BODY(nv::TBOOL32, bIsUpgrade)

	/*<<imix��JDƽ̨���ذ汾����֪ͨ>>
	*
	*/
	MESSAGE(Ev_NV_BLL_NVDownloadFromJDServer_Nty)
	BODY(nv::TU32, dwSchedule)

	/*<<imix��JDƽ̨���ذ汾���֪ͨ>>
	*
	*/
	MESSAGE(Ev_NV_BLL_NVDownloadResultFromJD_Nty)
	BODY(nv::TBOOL32, tbResult)

	/*<<����Ͷ��������������>>
	*login_rsp ���˺���֤Ӧ����
	*���䷽��access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_BLL_NVSetQKHbParm_Cmd)
	BODY(nv::TU16, wHb)
	BODY(nv::TU8, wHb)

#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(ACCESS) = EVSEG_BLL_ACCESS_END
};
#endif//_MESSAGE_HELP_

#define Is_BLL_Access_Msg(m) ((m) >= EV_BLL_BGN(ACCESS) && (m) <= EV_BLL_END(ACCESS))

#endif//_NVBLLACCESSMSG_H_