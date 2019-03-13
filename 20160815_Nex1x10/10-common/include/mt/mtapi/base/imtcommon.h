/**===========================================================================
 * @file    $Id$
 * @brief   �����ն�ͨ�ù��ܵĽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTCOMMON_H_
#define _I_MTCOMMON_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_base.h"




/**---------------------------------------------------------------------------
 * @class   Interface IMtCommon
 * @brief   �����ն�ͨ�ù��ܵĽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class IMtCommon : public IMtApiIF
{
public:
	//֪ͨ����ʹ�õ�������Ϣ
	virtual u32 SendUsedNetInfoNtf( const TNetUsedInfo_Api& tNetUsedInfo ) = 0;

	//���������ļ�����
	virtual u32 ExportMtcfgFileReq( IN CONST s8* pchExpPath ) = 0;
	//���������ļ�����
	virtual u32	ImportMtcfgFileReq( IN CONST s8* pchImpPath, IN CONST BOOL32 bReboot ) = 0;
	//����debug�ļ�����
	virtual	u32 ExportMtDbgcfgFileReq( IN CONST s8* pchExpPath ) = 0;
	//����debug�ļ�����
	virtual u32	ImportMtDbgcfgFileReq( IN CONST s8* pchImpPath, IN CONST BOOL32 bReboot ) = 0;

	//����Ca֤������
	virtual u32 ImportCACertCmd(IN CONST s8* CaCertFileName) = 0;
	//����Ca֤������
	virtual u32 ExportAllCACertReq(IN CONST s8* CaCertFileName) = 0;
	//�����豸֤������
	virtual u32 ImportDeviceCertCmd(IN CONST s8* DeviceCertFileName) = 0;
	//�����豸֤������
	virtual u32 ExportDeviceCertReq(IN CONST s8* DeviceCertFileName) = 0;
	//�����豸֤������
	virtual u32 CreateDeviceCertReq( IN CONST TMtSecCreateCertReq_Api tReq) = 0;
	//��ѯCa֤������
	virtual u32 QueryCACertInfoReq(IN CONST TMtSecCerId_Api tCerId) = 0;
	//��ѯ�豸֤������
	virtual u32 QueryDeviceCertInfoReq(IN CONST u32 dwSecCertType) = 0;

	//����ǩ��֤������
	virtual u32 ImportSignCertCmd(IN CONST s8* pchSignCertFileName) = 0;
	//�������֤������
	virtual u32 ImportEncCertCmd(IN CONST s8* pchEncCertFileName, IN CONST BOOL32 bWithKey, IN CONST s8* pchEncCertPwd=NULL) = 0;
	//����ǩ��֤������
	virtual u32 ExportSignCertReq(IN CONST s8* pchCertFileName) = 0;
	//��������֤������
	virtual u32 ExportEncCertReq(IN CONST s8* pchCertFileName) = 0;

	//��ȡcaidlist
	virtual u32 GetCACertIDListReq()=0;
	//����id����cacert
	virtual u32 ExportCACertByIDReq(IN CONST TMtSecCerId_Api tCerId, IN CONST s8* CaCertFileName)=0;
	//����idɾ��cacert
	virtual u32 DeleteCACertByIDReq(IN CONST TMtSecCerId_Api tCerId)=0;
	virtual u32 ResumeKedaCaCertCmd()=0;

	//���ô���ʣ��ʱ�䣬��Embed
	virtual u32 SetSleepReaminTimeCmd( IN CONST u16 wSleepRemainTime )=0;
	//���ͱ��ض���Ϣ
	virtual u32 SendLocalSmsCmd( IN CONST s8 *pszLocSms )=0;
	//����Home��ť����
	virtual u32 PressHomeButtonCmd()=0;

	virtual u32 CancelStrongAuthCmd()=0;
	virtual u32 EnterDynPwdCmd(IN CONST s8* pchDynPwd) = 0;

	virtual u32 GetSoftIntegritySelfTestReq()=0;

	virtual u32 ImportPfxEncCertCmd(IN CONST s8* pchEncCertFileName) = 0;

	virtual u32 ImportKeyPairCmd(IN CONST s8* pchKeyPairFileName) = 0;

	virtual u32 GmAndRandomNumSelfTestCmd() = 0;

	virtual u32 GetGmAndRandomNumSelfTestReq() = 0;

	virtual TGmAndRandomNumTest_Api GetGmAndRandomNumSelfTest() = 0;

	virtual u32 KeyPairConsistencySelfTestCmd() = 0;

	virtual u32 GetKeyPairConsistencySelfTestReq() = 0;

	virtual EmSecErrorCode_Api GetKeyPairConsistencySelfTest() = 0;
	
	virtual u32 UpdateChannelLicenseCmd( ) = 0;

	virtual u32 ResetSecKeyCmd( IN CONST BOOL32 bKeepAccount ) =0;
	virtual u32 SetAiInfoCfgCmd( IN CONST TMtAiInfoCfg_Api tCfg ) =0;
	virtual TMtAiInfoCfg_Api GetAiInfoCfg() = 0;
	virtual u32 GetAiInfoCfgtReq() = 0;

	virtual u32 SetSkipWizardStaticImage( IN CONST BOOL32 bSkip ) = 0;

	virtual BOOL32 GetAiLoadLicenseTestCfg() = 0;
	virtual u32 GetAiLoadLicenseTestReq() = 0;

public:

};

#endif // _I_MTCOMMON_H_