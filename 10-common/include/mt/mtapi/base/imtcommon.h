/**===========================================================================
 * @file    $Id$
 * @brief   负责终端通用功能的接口定义
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
 * @brief   负责终端通用功能的接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class IMtCommon : public IMtApiIF
{
public:
	//通知正在使用的网络信息
	virtual u32 SendUsedNetInfoNtf( const TNetUsedInfo_Api& tNetUsedInfo ) = 0;

	//导出配置文件请求
	virtual u32 ExportMtcfgFileReq( IN CONST s8* pchExpPath ) = 0;
	//导入配置文件请求
	virtual u32	ImportMtcfgFileReq( IN CONST s8* pchImpPath, IN CONST BOOL32 bReboot ) = 0;
	//导出debug文件请求
	virtual	u32 ExportMtDbgcfgFileReq( IN CONST s8* pchExpPath ) = 0;
	//导入debug文件请求
	virtual u32	ImportMtDbgcfgFileReq( IN CONST s8* pchImpPath, IN CONST BOOL32 bReboot ) = 0;

	//导入Ca证书命令
	virtual u32 ImportCACertCmd(IN CONST s8* CaCertFileName) = 0;
	//导出Ca证书请求
	virtual u32 ExportAllCACertReq(IN CONST s8* CaCertFileName) = 0;
	//导入设备证书命令
	virtual u32 ImportDeviceCertCmd(IN CONST s8* DeviceCertFileName) = 0;
	//导出设备证书请求
	virtual u32 ExportDeviceCertReq(IN CONST s8* DeviceCertFileName) = 0;
	//创建设备证书请求
	virtual u32 CreateDeviceCertReq( IN CONST TMtSecCreateCertReq_Api tReq) = 0;
	//查询Ca证书请求
	virtual u32 QueryCACertInfoReq(IN CONST TMtSecCerId_Api tCerId) = 0;
	//查询设备证书请求
	virtual u32 QueryDeviceCertInfoReq(IN CONST u32 dwSecCertType) = 0;

	//导入签名证书命令
	virtual u32 ImportSignCertCmd(IN CONST s8* pchSignCertFileName) = 0;
	//导入加密证书命令
	virtual u32 ImportEncCertCmd(IN CONST s8* pchEncCertFileName, IN CONST BOOL32 bWithKey, IN CONST s8* pchEncCertPwd=NULL) = 0;
	//导出签名证书请求
	virtual u32 ExportSignCertReq(IN CONST s8* pchCertFileName) = 0;
	//导出加密证书请求
	virtual u32 ExportEncCertReq(IN CONST s8* pchCertFileName) = 0;

	//获取caidlist
	virtual u32 GetCACertIDListReq()=0;
	//根据id导出cacert
	virtual u32 ExportCACertByIDReq(IN CONST TMtSecCerId_Api tCerId, IN CONST s8* CaCertFileName)=0;
	//根据id删除cacert
	virtual u32 DeleteCACertByIDReq(IN CONST TMtSecCerId_Api tCerId)=0;
	virtual u32 ResumeKedaCaCertCmd()=0;

	//设置待机剩余时间，仅Embed
	virtual u32 SetSleepReaminTimeCmd( IN CONST u16 wSleepRemainTime )=0;
	//发送本地短消息
	virtual u32 SendLocalSmsCmd( IN CONST s8 *pszLocSms )=0;
	//按下Home按钮命令
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