#ifndef _MTBLLVODMSG_H_
#define _MTBLLVODMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMtVodMsg
{
    EV_BLL_BGN(MTVOD) = EVSEG_BLL_MTSEC_BGN,
#endif//_MESSAGE_HELP_

	/*<<�����������֤�Ƿ����>>
	*bValidate���Ƿ���֤ͨ��
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_BLL_DeviceLicenseIsValidate_Ntf)
	BODY(mt::TBOOL32, bValidate)
	

	/*<<����ca֤��>>
	*CaCertFileName �������ca֤��������·���ļ���
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_BLL_ImportCACert_Cmd)
	BODY(mt::TString, CaCertFileName)
	

	/*<<����ca֤������>>
	*CaCertFileName ��������ca֤��������·���ļ���
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_BLL_ExportCACert_Req)
	BODY(mt::TString, CaCertFileName)

	/*<<����ca֤����Ӧ>>
	*bResult ���Ƿ�ɹ�
	*��Ϣ���� ��mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_ExportCACert_Rsp)
	BODY(mt::TBOOL32, bResult)


	/*<<�����豸֤��>>
	*DeviceCertFileName �������ca֤��������·���ļ���
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_BLL_ImportDeviceCert_Cmd)
	BODY(mt::TString, DeviceCertFileName)
	

	/*<<�����豸֤��>>
	*DeviceCertFileName ��������ca֤��������·���ļ���
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_BLL_ExportDeviceCert_Req)
	BODY(mt::TString, DeviceCertFileName)

	/*<<�����豸֤����Ӧ>>
	*bResult ���Ƿ�ɹ�
	*��Ϣ���� ��mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_ExportDeviceCert_Rsp)
	BODY(mt::TBOOL32, bResult)
	

	/*<<���������豸֤��>>
	*DeviceCertFileName ��֤���ļ���·��
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_BLL_CreateDeviceCert_Req )
	BODY(mt::TString, DeviceCertFileName)

	/*<<�����豸֤����Ӧ>>
	*bResult ���Ƿ�ɹ�
	*��Ϣ���� ��mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_CreateDeviceCert_Rsp)
	BODY(mt::TBOOL32, bResult)


	/*<<��ѯca֤����Ϣ>>
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_BLL_QueryCACertInfo_Req)

	/*<<��ѯca֤����Ϣ>>
	tCertInfo: ca֤����Ϣ
	*��Ϣ���� ��mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_QueryCACertInfo_Rsp)
	BODY(mt::TMtSecCertInfo, tCertInfo)


	/*<<��ѯ�豸֤����Ϣ>>
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_BLL_QueryDeviceCertInfo_Req)

	/*<<��ѯ�豸֤����Ϣ>>
	tCertInfo: �豸֤����Ϣ
	*��Ϣ���� ��mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_QueryDeviceCertInfo_Rsp)
	BODY(mt::TMtSecCertInfo, tCertInfo)


	/*<<���붯̬����>>
	tDynamicPwd: ��̬��������
	*��Ϣ���� ��mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_EnterDynamicPassword_Cmd )
	BODY(mt::TBytes, tDynamicPwd)

	
	/*<���˻��߶Զ���֤���>>
	bLocal:   �Ƿ��Ǳ���
	bResult�� �Ƿ���֤ͨ��
	*��Ϣ���� ��mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_VerifyDynamicPwdRes_Ntf )
	BODY(mt::TBOOL32, bLocal)
	BODY(mt::TBOOL32, bResult)

    /*<<���ܹ��ܲ���>>
	*��Ϣ���� ��mfgtest==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_SecbizTest_Req)

	/*<<���ܹ��ܲ��Խ��>>
	bResult:  ���Խ��
	*��Ϣ���� ��service==>dispatch==>mfgtest
	*/
    MESSAGE(Ev_MT_BLL_SecbizTestResult_Rsp)
	BODY(mt::TBOOL32, bResult)
	
#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(MTVOD) = EVSEG_BLL_MTSEC_BGN
};
#endif//_MESSAGE_HELP_

#define Is_BLL_Vod_Msg(m) ((m) >= EV_BLL_BGN(MTVOD) && (m) <= EV_BLL_END(MTVOD))

#endif//_MTBLLVODMSG_H_