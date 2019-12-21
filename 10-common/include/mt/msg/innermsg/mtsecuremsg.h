#ifndef _MTSECUREMSG_H_
#define _MTSECUREMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMtVodMsg
{
    EV_BGN(MTVOD) = EVSEG_MTSECURE_BGN,
#endif//_MESSAGE_HELP_
	
	/*<<商密设置许可证是否可用>>
	*bValidate：是否验证通过
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_DeviceLicenseIsValidate_Ntf)
	BODY(mt::TBOOL32, bValidate)
	

	/*<<导入ca证书>>
	*CaCertFileName ：导入的ca证书存放完整路径文件名
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_ImportCACert_Cmd)
	BODY(mt::TString, CaCertFileName)
	

	/*<<导出ca证书请求>>
	*CaCertFileName ：导出的ca证书存放完整路径文件名
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_ExportAllCACert_Req)
	BODY(mt::TString, CaCertFileName)

	/*<<导出ca证书响应>>
	*bResult ：是否成功
	*消息流向 ：mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_ExportAllCACert_Rsp)
	BODY(mt::TBOOL32, bResult)


	/*<<导入设备证书>>
	*DeviceCertFileName ：导入的ca证书存放完整路径文件名
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_ImportDeviceCert_Cmd)
	BODY(mt::TString, DeviceCertFileName)
	

	/*<<导出设备证书>>
	*DeviceCertFileName ：导出的ca证书存放完整路径文件名
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_ExportDeviceCert_Req)
	BODY(mt::TString, DeviceCertFileName)

	/*<<导出设备证书响应>>
	*bResult ：是否成功
	*消息流向 ：mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_ExportDeviceCert_Rsp)
	BODY(mt::TBOOL32, bResult)
	

	/*<<请求生成设备证书>>
	*DeviceCertFileName ：证书文件名路径
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_CreateDeviceCert_Req )
	BODY(mt::TString, DeviceCertFileName)

	/*<<生成设备证书响应>>
	*bResult ：是否成功
	*消息流向 ：mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_CreateDeviceCert_Rsp)
	BODY(mt::TBOOL32, bResult)


	/*<<查询ca证书信息>>
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_QueryCACertInfo_Req)

	/*<<查询ca证书信息>>
	tCertInfo: ca证书信息
	*消息流向 ：mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_QueryCACertInfo_Rsp)
	BODY(mt::TMtSecCertInfo, tCertInfo)


	/*<<查询设备证书信息>>
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_QueryDeviceCertInfo_Req)

	/*<<查询设备证书信息>>
	tCertInfo: 设备证书信息
	*消息流向 ：mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_QueryDeviceCertInfo_Rsp)
	BODY(mt::TMtSecCertInfo, tCertInfo)


	/*<<动态口令info请求>>
	tUserName: 用户名
	tPwd:      动态口令
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_GetDynPwdInfo_Req)
	BODY(mt::TString, tUserName)
	BODY(mt::TBytes, tPwd)


	/*<<动态口令info应答>>
	tXmlInfo:  非标info
	*消息流向 ：mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_GetDynPwdInfo_Rsp)
	BODY(mt::TString, tXmlInfo)


	/*<<商密info 解析>>
	tXmlInfo:  非标info
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_ParseSecInfo_Cmd)
	BODY(mt::TString, tXmlInfo)

	/*<<商密info 解析结果>>
	dwType:   区分本地的认证还是对端的认证 1为本地的认证， 2为对端的认证
	bResult:  认证结果
	tBuf：   如果是对端认证结果，转发出去的xml
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_ParseSecInfoResult_Ntf)
	BODY(mt::TU32, dwType)
	BODY(mt::TBOOL32, bResult)
	BODY(mt::TString, tBuf)


/////////xin

	/*<<获取ca证书ID列表>>
	*CaCertFileName ：导出的ca证书存放完整路径文件名
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_GetCACertIDList_Req)

	/*<<获取ca证书ID列表响应>>
	*bResult ：是否成功
	*消息流向 ：mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_GetCACertIDList_Rsp)
	BODY(mt::TS32, nCertIDCount)
	BODY(mt::TRpMtSecCaIDList, tRpIDList)

	/*<<根据ID导出ca证书请求>>
	*CaCertFileName ：导出的ca证书存放完整路径文件名
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_ExportCACertByID_Req)
	BODY(mt::TString, tSecCaID)
	BODY(mt::TString, DeviceCertFileName)

	/*<<根据ID导出ca证书响应>>
	*bResult ：是否成功
	*消息流向 ：mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_ExportCACertByID_Rsp)
	BODY(mt::TBOOL32, bResult)

	/*<<根据ID删除ca证书请求>>
	*CaCertFileName ：导出的ca证书存放完整路径文件名
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_DeleteCACertByID_Req)
	BODY(mt::TString, tSecCaID)

	/*<<根据ID删除ca证书响应>>
	*bResult ：是否成功
	*消息流向 ：mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_DeleteCACertByID_Rsp)
	BODY(mt::TBOOL32, bResult)

//////////////////////////////////////////////////////////////////////////
	/*<<导入设备证书>>
	*DeviceCertFileName ：导入的证书存放完整路径文件名
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_ImportSignCert_Cmd)
	BODY(mt::TString, DeviceCertFileName)

	/*<<导入设备证书>>
	*DeviceCertFileName ：导入的证书存放完整路径文件名
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_ImportEncPEMCert_Cmd)
	BODY(mt::TString, DeviceCertFileName)

	/*<<导入设备证书>>
	*DeviceCertFileName ：导入的证书存放完整路径文件名
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_ImportEncCertWithKey_Cmd)
	BODY(mt::TString, DeviceCertFileName)
	BODY(mt::TString, tPassword)

	/*<<导出证书请求>>
	*CaCertFileName ：导出的证书存放完整路径文件名
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_ExportSignCert_Req)
	BODY(mt::TString, DeviceCertFileName)

	/*<导出证书响应>>
	*bResult ：是否成功
	*消息流向 ：mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_ExportSignCert_Rsp)
	BODY(mt::TBOOL32, bResult)

	/*<<导出证书请求>>
	*CaCertFileName ：导出的证书存放完整路径文件名
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_ExportEncCert_Req)
	BODY(mt::TString, DeviceCertFileName)

	/*<导出证书响应>>
	*bResult ：是否成功
	*消息流向 ：mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_ExportEncCert_Rsp)
	BODY(mt::TBOOL32, bResult)

	/*<<请求生成设备证书>>
	*DeviceCertFileName ：证书文件名路径
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_CreateSignCert_Req )
	BODY(mt::TString, DeviceCertFileName)

	/*<<生成设备证书响应>>
	*bResult ：是否成功
	*消息流向 ：mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_CreateSignCert_Rsp)
	BODY(mt::TBOOL32, bResult)

    /*<<商密功能测试>>
	*消息流向 ：mfgtest==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_SecbizTest_Req)

	/*<<商密功能测试结果>>
	bResult:  测试结果
	*消息流向 ：mfgtest==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_SecbizTestResult_Rsp)
	BODY(mt::TBOOL32, bResult)

	 /*<<商密功能生成许可证书请求>>
	*消息流向 ：mfgtest==>dispatch==>mtsec
	*/
	MESSAGE(Ev_MT_CreateLicenseCert_Req)
	BODY(mt::TMtSecCreateCertReq, tInfo)

	/*<<商密功能生成许可证书响应>>
	*消息流向 ：mfgtest==>dispatch==>mtsec
	*/
	MESSAGE(Ev_MT_CreateLicenseCert_Rsp)
	BODY(mt::TBOOL32, bResult)
	BODY(mt::TString, DeviceCertFileName)

	/*<<商密功能 导入许可证书>>
	*消息流向 ：mfgtest==>dispatch==>mtsec
	*/
	MESSAGE(Ev_MT_ImportLicenseCert_Cmd)
	BODY(mt::TString, ptFilePath)


#if !defined(_MESSAGE_HELP_)
    EV_END(MTVOD) = EVSEG_MTSECURE_END
};
#endif//_MESSAGE_HELP_

#define Is_Vod_Msg(m) ((m) >= EV_BGN(MTVOD) && (m) <= EV_END(MTVOD))

#endif//_MTVODMSG_H_