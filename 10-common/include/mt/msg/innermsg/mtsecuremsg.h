#ifndef _MTSECUREMSG_H_
#define _MTSECUREMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMtVodMsg
{
    EV_BGN(MTVOD) = EVSEG_MTSECURE_BGN,
#endif//_MESSAGE_HELP_
	
	/*<<�����������֤�Ƿ����>>
	*bValidate���Ƿ���֤ͨ��
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_DeviceLicenseIsValidate_Ntf)
	BODY(mt::TBOOL32, bValidate)
	

	/*<<����ca֤��>>
	*CaCertFileName �������ca֤��������·���ļ���
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_ImportCACert_Cmd)
	BODY(mt::TString, CaCertFileName)
	

	/*<<����ca֤������>>
	*CaCertFileName ��������ca֤��������·���ļ���
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_ExportAllCACert_Req)
	BODY(mt::TString, CaCertFileName)

	/*<<����ca֤����Ӧ>>
	*bResult ���Ƿ�ɹ�
	*��Ϣ���� ��mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_ExportAllCACert_Rsp)
	BODY(mt::TBOOL32, bResult)


	/*<<�����豸֤��>>
	*DeviceCertFileName �������ca֤��������·���ļ���
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_ImportDeviceCert_Cmd)
	BODY(mt::TString, DeviceCertFileName)
	

	/*<<�����豸֤��>>
	*DeviceCertFileName ��������ca֤��������·���ļ���
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_ExportDeviceCert_Req)
	BODY(mt::TString, DeviceCertFileName)

	/*<<�����豸֤����Ӧ>>
	*bResult ���Ƿ�ɹ�
	*��Ϣ���� ��mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_ExportDeviceCert_Rsp)
	BODY(mt::TBOOL32, bResult)
	

	/*<<���������豸֤��>>
	*DeviceCertFileName ��֤���ļ���·��
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_CreateDeviceCert_Req )
	BODY(mt::TString, DeviceCertFileName)

	/*<<�����豸֤����Ӧ>>
	*bResult ���Ƿ�ɹ�
	*��Ϣ���� ��mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_CreateDeviceCert_Rsp)
	BODY(mt::TBOOL32, bResult)


	/*<<��ѯca֤����Ϣ>>
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_QueryCACertInfo_Req)

	/*<<��ѯca֤����Ϣ>>
	tCertInfo: ca֤����Ϣ
	*��Ϣ���� ��mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_QueryCACertInfo_Rsp)
	BODY(mt::TMtSecCertInfo, tCertInfo)


	/*<<��ѯ�豸֤����Ϣ>>
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_QueryDeviceCertInfo_Req)

	/*<<��ѯ�豸֤����Ϣ>>
	tCertInfo: �豸֤����Ϣ
	*��Ϣ���� ��mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_QueryDeviceCertInfo_Rsp)
	BODY(mt::TMtSecCertInfo, tCertInfo)


	/*<<��̬����info����>>
	tUserName: �û���
	tPwd:      ��̬����
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_GetDynPwdInfo_Req)
	BODY(mt::TString, tUserName)
	BODY(mt::TBytes, tPwd)


	/*<<��̬����infoӦ��>>
	tXmlInfo:  �Ǳ�info
	*��Ϣ���� ��mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_GetDynPwdInfo_Rsp)
	BODY(mt::TString, tXmlInfo)


	/*<<����info ����>>
	tXmlInfo:  �Ǳ�info
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_ParseSecInfo_Cmd)
	BODY(mt::TString, tXmlInfo)

	/*<<����info �������>>
	dwType:   ���ֱ��ص���֤���ǶԶ˵���֤ 1Ϊ���ص���֤�� 2Ϊ�Զ˵���֤
	bResult:  ��֤���
	tBuf��   ����ǶԶ���֤�����ת����ȥ��xml
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_ParseSecInfoResult_Ntf)
	BODY(mt::TU32, dwType)
	BODY(mt::TBOOL32, bResult)
	BODY(mt::TString, tBuf)


/////////xin

	/*<<��ȡca֤��ID�б�>>
	*CaCertFileName ��������ca֤��������·���ļ���
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_GetCACertIDList_Req)

	/*<<��ȡca֤��ID�б���Ӧ>>
	*bResult ���Ƿ�ɹ�
	*��Ϣ���� ��mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_GetCACertIDList_Rsp)
	BODY(mt::TS32, nCertIDCount)
	BODY(mt::TRpMtSecCaIDList, tRpIDList)

	/*<<����ID����ca֤������>>
	*CaCertFileName ��������ca֤��������·���ļ���
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_ExportCACertByID_Req)
	BODY(mt::TString, tSecCaID)
	BODY(mt::TString, DeviceCertFileName)

	/*<<����ID����ca֤����Ӧ>>
	*bResult ���Ƿ�ɹ�
	*��Ϣ���� ��mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_ExportCACertByID_Rsp)
	BODY(mt::TBOOL32, bResult)

	/*<<����IDɾ��ca֤������>>
	*CaCertFileName ��������ca֤��������·���ļ���
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_DeleteCACertByID_Req)
	BODY(mt::TString, tSecCaID)

	/*<<����IDɾ��ca֤����Ӧ>>
	*bResult ���Ƿ�ɹ�
	*��Ϣ���� ��mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_DeleteCACertByID_Rsp)
	BODY(mt::TBOOL32, bResult)

//////////////////////////////////////////////////////////////////////////
	/*<<�����豸֤��>>
	*DeviceCertFileName �������֤��������·���ļ���
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_ImportSignCert_Cmd)
	BODY(mt::TString, DeviceCertFileName)

	/*<<�����豸֤��>>
	*DeviceCertFileName �������֤��������·���ļ���
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_ImportEncPEMCert_Cmd)
	BODY(mt::TString, DeviceCertFileName)

	/*<<�����豸֤��>>
	*DeviceCertFileName �������֤��������·���ļ���
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_ImportEncCertWithKey_Cmd)
	BODY(mt::TString, DeviceCertFileName)
	BODY(mt::TString, tPassword)

	/*<<����֤������>>
	*CaCertFileName ��������֤��������·���ļ���
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_ExportSignCert_Req)
	BODY(mt::TString, DeviceCertFileName)

	/*<����֤����Ӧ>>
	*bResult ���Ƿ�ɹ�
	*��Ϣ���� ��mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_ExportSignCert_Rsp)
	BODY(mt::TBOOL32, bResult)

	/*<<����֤������>>
	*CaCertFileName ��������֤��������·���ļ���
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_ExportEncCert_Req)
	BODY(mt::TString, DeviceCertFileName)

	/*<����֤����Ӧ>>
	*bResult ���Ƿ�ɹ�
	*��Ϣ���� ��mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_ExportEncCert_Rsp)
	BODY(mt::TBOOL32, bResult)

	/*<<���������豸֤��>>
	*DeviceCertFileName ��֤���ļ���·��
	*��Ϣ���� ��service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_CreateSignCert_Req )
	BODY(mt::TString, DeviceCertFileName)

	/*<<�����豸֤����Ӧ>>
	*bResult ���Ƿ�ɹ�
	*��Ϣ���� ��mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_CreateSignCert_Rsp)
	BODY(mt::TBOOL32, bResult)

    /*<<���ܹ��ܲ���>>
	*��Ϣ���� ��mfgtest==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_SecbizTest_Req)

	/*<<���ܹ��ܲ��Խ��>>
	bResult:  ���Խ��
	*��Ϣ���� ��mfgtest==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_SecbizTestResult_Rsp)
	BODY(mt::TBOOL32, bResult)

	 /*<<���ܹ����������֤������>>
	*��Ϣ���� ��mfgtest==>dispatch==>mtsec
	*/
	MESSAGE(Ev_MT_CreateLicenseCert_Req)
	BODY(mt::TMtSecCreateCertReq, tInfo)

	/*<<���ܹ����������֤����Ӧ>>
	*��Ϣ���� ��mfgtest==>dispatch==>mtsec
	*/
	MESSAGE(Ev_MT_CreateLicenseCert_Rsp)
	BODY(mt::TBOOL32, bResult)
	BODY(mt::TString, DeviceCertFileName)

	/*<<���ܹ��� �������֤��>>
	*��Ϣ���� ��mfgtest==>dispatch==>mtsec
	*/
	MESSAGE(Ev_MT_ImportLicenseCert_Cmd)
	BODY(mt::TString, ptFilePath)


#if !defined(_MESSAGE_HELP_)
    EV_END(MTVOD) = EVSEG_MTSECURE_END
};
#endif//_MESSAGE_HELP_

#define Is_Vod_Msg(m) ((m) >= EV_BGN(MTVOD) && (m) <= EV_END(MTVOD))

#endif//_MTVODMSG_H_