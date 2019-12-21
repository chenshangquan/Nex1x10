#ifndef _MTBLLACCESSMSG_H_
#define _MTBLLACCESSMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMtAccessMsg
{
    EV_BLL_BGN(ACCESS) = EVSEG_BLL_ACCESS_BGN,
#endif//_MESSAGE_HELP_

	/*<<�ն˿ͻ����˺���֤����>>
	*loginuser_fullinfo ���˺���֤�û���ϸ��Ϣ
	*���䷽��mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_BLL_MTCLogin_Req)
	BODY(mt::TUserFullInfo, loginuser_fullinfo)

	/*<<�ն˿ͻ����˺���֤Ӧ��>>
	*login_rsp ���˺���֤Ӧ����
	*���䷽��access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_BLL_MTCLogin_Rsp)
	BODY(mt::TUserReqResult, loginuser_rsp)

	/*<<�ն���ӿͻ����˺�����>>
	*adduser_fullinfo ���ն���ӿͻ����˺���Ϣ
	*���䷽��mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_BLL_MTCAddUser_Req)
	BODY(mt::TMultiUserFullInfo, adduser_fullinfo)

	/*<<�ն˶Կͻ����˺Ž������Ӧ��>>
	*adduser_rsp ���ն˶Կͻ����˺Ž������Ӧ����
	*���䷽��access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_BLL_MTCAddUser_Rsp)
	BODY(mt::TMultiUserReqResult, adduser_rsp)

	/*<<�ն˶Կͻ����˺Ž�������˺���Ϣ֪ͨ>>
	*adduser_ntf ���ն˶Կͻ����˺Ž�������˺���Ϣ
	*���䷽��access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_BLL_MTCAddUser_Ntf)
	BODY(mt::TMultiUserFullInfo, adduser_ntf)

	/*<<�ն˶Կͻ����˺Ž����޸�����>>
	*muser_fullinfo �������޸�����ͻ����˺���Ϣ
	*���䷽��mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_BLL_MTCMUser_Req)
	BODY(mt::TMultiUserFullInfo, muser_fullinfo)

	/*<<�ն˶Կͻ����˺Ž����޸�Ӧ��>>
	*muser_rsp ���ն˶Կͻ����˺Ž����޸�Ӧ����
	*���䷽��access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_BLL_MTCMUser_Rsp)
	BODY(mt::TMultiUserReqResult, muser_rsp)

	/*<<�ն˶Կͻ����˺Ž����޸��˺���Ϣ֪ͨ>>
	*muser_ntf ���ն˶Կͻ����˺Ž����޸��˺���Ϣ
	*���䷽��access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_BLL_MTCMUser_Ntf)
	BODY(mt::TMultiUserFullInfo, muser_ntf)

	/*<<�ն˶Կͻ����˺Ž���ɾ������>>
	*duser ������ɾ������ͻ����˺�ID��Ϣ
	*���䷽��mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_BLL_MTCDUser_Req)
	BODY(mt::TMultiU32, duserids)

	/*<<�ն˶Կͻ����˺Ž���ɾ��Ӧ��>>
	*duser_rsp ���ն˶Կͻ����˺Ž���ɾ��Ӧ����
	*���䷽��access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_BLL_MTCDUser_Rsp)
	BODY(mt::TMultiUserReqResult, duser_rsp)

	/*<<�ն˶Կͻ����˺Ž���ɾ���˺���Ϣ֪ͨ>>
	*duser_ntf ���ն˶Կͻ����˺Ž���ɾ���˺���Ϣ
	*���䷽��access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_BLL_MTCDUser_Ntf)
	BODY(mt::TMultiUserFullInfo, duser_ntf)

	/*<<�ն˶Կͻ����˺Ž��в�ѯ����>>
	*���䷽��mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_BLL_MTCSUser_Req)

	/*<<�ն˶Կͻ����˺Ž��в�ѯӦ��>>
	*duser_rsp ���ն˶Կͻ����˺Ž��в�ѯӦ����
	*���䷽��access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_BLL_MTCSUser_Rsp)
	BODY(mt::TMultiUserFullInfo, duser_rsp)

	/*<<�ն˿ͻ����˺�ע������>>
	*user_name ���û���
	*���䷽��mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_BLL_MTCLogOut_Cmd)
	BODY(mt::TString, user_name)

	/*<<�ն˿ͻ����˺�ע��֪ͨ>>
	*Ev_MT_BLL_MTCLogOut_Ntf ���˺���֤�û���ϸ��Ϣ
	*logoutuser_fullinfo ��ע���˺��û���ϸ��Ϣ
	*���䷽��access->dispatch->������
	*/
	MESSAGE(Ev_MT_BLL_MTCLogOut_Ntf)
	BODY(mt::TUserFullInfo, logoutuser_fullinfo)

	/*<<skyshare��¼״̬֪ͨ>>
	*Ev_MT_MTCSkyShareLoginState_Ntf ��skyshare��¼״̬
	*loginstate ����¼״̬
	*���䷽��access->dispatch->������
	*/
	MESSAGE(Ev_MT_BLL_MTCSkyShareLoginState_Ntf)
	BODY(mt::TBOOL32, loginstate)

	/*<<����skyshare��¼״̬>>
	*���䷽��mtc->dispatch->service
	*/
	MESSAGE(Ev_MT_BLL_MTCGetSkyShareLoginState_Req)

	/*<<mtc��¼���>>
	*Ev_MT_BLL_NewMtcLogin_Rsp ��
	*tLoginRet ����¼���
	*/
	MESSAGE( Ev_MT_BLL_NewMtcLogin_Rsp  )
	BODY(mt::TMtcLoginRet, tLoginRet)


    /*<<mtc��������>>
	*Ev_MT_BLL_HandShake_Req ��
	*tLoginRet ����¼���
	*/
	MESSAGE( Ev_MT_BLL_HandShake_Req  )

	/*<<mtc������Ӧ>>
	*Ev_MT_BLL_HandShake_Rsp ��
	*tLoginRet ����¼���
	*/
	MESSAGE( Ev_MT_BLL_HandShake_Rsp  )
	BODY(mt::THandShakeParam, tParam)

	/*<<��ռ֪ͨ>>
	*Ev_MT_BLL_HandShake_Rsp ��
	*tLoginRet ����¼���
	*/
	MESSAGE( Ev_MT_BLL_HaveBeenKicked_Ntf )
	BODY(mt::TMtcBaseInfo, tlocal)
	BODY(mt::TMtcBaseInfo, tkicker)

	/*<<����̬��  ��������Э��>>
	*Ev_MT_BLL_GetDynamicPwd_Cmd ��
	*/
	MESSAGE( Ev_MT_BLL_GetDynamicPwd_Cmd )
	
	/*<<��̬����֪ͨ  ��������Э��>>
	*Ev_MT_BLL_GetDynamicPwd_Ntf ��
	*tDynamic ����̬����
	*/
	MESSAGE( Ev_MT_BLL_GetDynamicPwd_Ntf )
	BODY(mt::TString, tDynamic)

	/*<<��̬����У�飬 ��������Э��>>
	*/
	MESSAGE( Ev_MT_BLL_CheckDynamicPwd_Cmd )
	
	/*<<��̬����У����֪ͨ�� ��������Э��>>
	*bRet ��У����
	*/
	MESSAGE( Ev_MT_BLL_CheckDynamicPwd_Ntf )
	BODY(mt::TBOOL32, bRet)

	/*<<��ȡ�ն˰汾��Ϣ�ȣ��û���¼ǰ����>>
	*/
	MESSAGE( Ev_MT_BLL_GetMTInfo_Req)

	/*<<�ն˰汾��Ϣ��Ӧ>>
	*/
	MESSAGE( Ev_MT_BLL_GetMTInfo_Rsp)
	BODY(mt::TMtVersionInfo, tInfo)
	
	MESSAGE( Ev_MT_BLL_GetTrueRandBytes_Req)
	BODY(mt::TU16, tLen)

	MESSAGE( Ev_MT_BLL_GetTrueRandBytes_Rsp)
	BODY(mt::TBytes, tRandBytes )

	/*��������SM4 key����Ϣ֪ͨ
	*/
	MESSAGE( Ev_MT_BLL_ResetSecKey_Ntf)
	BODY(mt::TU32, result)
	BODY(mt::TBOOL32, bKeepAccount)

	//��̬������������������Э��
	MESSAGE( Ev_MT_BLL_CleanDynamicPwd_Cmd )

	//��̬�������֪ͨ�� ��������Э��
	MESSAGE( Ev_MT_BLL_CleanDynamicPwd_Ntf)

	/*<<mtc��Ϣ�б�����
	*/
	MESSAGE(Ev_MT_BLL_GetMtcInfoList_Req)

	/*<<mtc��Ϣ�б���Ӧ
	*/
	MESSAGE(Ev_MT_BLL_GetMtcInfoList_Rsp)

	/*<<����̬����  ���ڵ�¼>>
	*Ev_MT_BLL_GetLoginDynamicPwd_Cmd ��
	*/
	MESSAGE( Ev_MT_BLL_GetLoginDynamicPwd_Cmd )
	
	/*<<��̬����֪ͨ  ���ڵ�¼>>
	*Ev_MT_BLL_GetLoginDynamicPwd_Ntf ��
	*tDynamic ����̬����
	*/
	MESSAGE( Ev_MT_BLL_GetLoginDynamicPwd_Ntf )
	BODY(mt::TString, tDynamic)

	//��ȡwebmtc (ǰ��)��¼״̬������, ����osd�����������
	MESSAGE( Ev_MT_BLL_GetWebMtcLoginState_Req )

	//��ȡwebmtc (ǰ��)��¼״̬��Ӧ
	MESSAGE( Ev_MT_BLL_GetWebMtcLoginState_Rsp )
	BODY(mt::TBOOL32, bLogin)

	//webmtc (ǰ��)��¼״̬֪ͨ
	MESSAGE( Ev_MT_BLL_GetWebMtcLoginState_Ntf )
	BODY(mt::TBOOL32, bLogin)

	//�����û���¼����ʣ��ʱ��
	MESSAGE( Ev_MT_BLL_GetUserPwdRestTime_Req )

	//�����û���¼����ʣ��ʱ�����Ӧ
	MESSAGE( Ev_MT_BLL_GetUserPwdRestTime_Rsp )
	BODY(mt::TU32, tdwRestTime)
	BODY(mt::TUserFullInfo, tUserFullInfo)

	//osd����û���¼��������
	MESSAGE( Ev_MT_BLL_SetUserLoginUnLock_Cmd )

	//osd����û���¼����֪ͨ
	MESSAGE( Ev_MT_BLL_SetUserLoginUnLock_Ntf )

	//osd��ȡ�û���¼����״̬������
	MESSAGE( Ev_MT_BLL_GetUserLoginLockState_Req )

	//osd��ȡ�û���¼����״̬����Ӧ
	MESSAGE( Ev_MT_BLL_GetUserLoginLockState_Rsp )
	BODY(mt::TBOOL32, bLock)

	//�û���¼����״̬��֪ͨ
	MESSAGE( Ev_MT_BLL_GetUserLoginLockState_Ntf )
	BODY(mt::TBOOL32, bLock)

	//osd���ù���Ա�û�������������
	MESSAGE( Ev_MT_BLL_ResetAdminUserInfo_Cmd )

	//osd���ù���Ա�û����������֪ͨ
	MESSAGE( Ev_MT_BLL_ResetAdminUserInfo_Ntf )
	BODY(mt::TMultiUserFullInfo, resetmuser_ntf)

#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(ACCESS) = EVSEG_BLL_ACCESS_END
};
#endif//_MESSAGE_HELP_

#define Is_BLL_Access_Msg(m) ((m) >= EV_BLL_BGN(ACCESS) && (m) <= EV_BLL_END(ACCESS))

#endif//_MTBLLACCESSMSG_H_