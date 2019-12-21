#ifndef _MTBLLVODMSG_H_
#define _MTBLLVODMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMtVodMsg
{
    EV_BLL_BGN(MTVOD) = EVSEG_BLL_MTSEC_BGN,
#endif//_MESSAGE_HELP_

	/*<<商密设置许可证是否可用>>
	*bValidate：是否验证通过
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_BLL_DeviceLicenseIsValidate_Ntf)
	BODY(mt::TBOOL32, bValidate)
	

	/*<<导入ca证书>>
	*CaCertFileName ：导入的ca证书存放完整路径文件名
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_BLL_ImportCACert_Cmd)
	BODY(mt::TString, CaCertFileName)
	

	/*<<导出ca证书请求>>
	*CaCertFileName ：导出的ca证书存放完整路径文件名
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_BLL_ExportCACert_Req)
	BODY(mt::TString, CaCertFileName)

	/*<<导出ca证书响应>>
	*bResult ：是否成功
	*消息流向 ：mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_ExportCACert_Rsp)
	BODY(mt::TBOOL32, bResult)


	/*<<导入设备证书>>
	*DeviceCertFileName ：导入的ca证书存放完整路径文件名
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_BLL_ImportDeviceCert_Cmd)
	BODY(mt::TString, DeviceCertFileName)
	

	/*<<导出设备证书>>
	*DeviceCertFileName ：导出的ca证书存放完整路径文件名
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_BLL_ExportDeviceCert_Req)
	BODY(mt::TString, DeviceCertFileName)

	/*<<导出设备证书响应>>
	*bResult ：是否成功
	*消息流向 ：mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_ExportDeviceCert_Rsp)
	BODY(mt::TBOOL32, bResult)
	

	/*<<请求生成设备证书>>
	*DeviceCertFileName ：证书文件名路径
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_BLL_CreateDeviceCert_Req )
	BODY(mt::TString, DeviceCertFileName)

	/*<<生成设备证书响应>>
	*bResult ：是否成功
	*消息流向 ：mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_CreateDeviceCert_Rsp)
	BODY(mt::TBOOL32, bResult)


	/*<<查询ca证书信息>>
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_BLL_QueryCACertInfo_Req)

	/*<<查询ca证书信息>>
	tCertInfo: ca证书信息
	*消息流向 ：mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_QueryCACertInfo_Rsp)
	BODY(mt::TMtSecCertInfo, tCertInfo)


	/*<<查询设备证书信息>>
	*消息流向 ：service==>dispatch==>mtsec
	*/
    MESSAGE(Ev_MT_BLL_QueryDeviceCertInfo_Req)

	/*<<查询设备证书信息>>
	tCertInfo: 设备证书信息
	*消息流向 ：mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_QueryDeviceCertInfo_Rsp)
	BODY(mt::TMtSecCertInfo, tCertInfo)


	/*<<输入动态口令>>
	tDynamicPwd: 动态口令密码
	*消息流向 ：mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_EnterDynamicPassword_Cmd )
	BODY(mt::TBytes, tDynamicPwd)

	
	/*<本端或者对端认证结果>>
	bLocal:   是否是本端
	bResult： 是否认证通过
	*消息流向 ：mtsec==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_VerifyDynamicPwdRes_Ntf )
	BODY(mt::TBOOL32, bLocal)
	BODY(mt::TBOOL32, bResult)

    /*<<商密功能测试>>
	*消息流向 ：mfgtest==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_SecbizTest_Req)

	/*<<商密功能测试结果>>
	bResult:  测试结果
	*消息流向 ：service==>dispatch==>mfgtest
	*/
    MESSAGE(Ev_MT_BLL_SecbizTestResult_Rsp)
	BODY(mt::TBOOL32, bResult)
	
#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(MTVOD) = EVSEG_BLL_MTSEC_BGN
};
#endif//_MESSAGE_HELP_

#define Is_BLL_Vod_Msg(m) ((m) >= EV_BLL_BGN(MTVOD) && (m) <= EV_BLL_END(MTVOD))

#endif//_MTBLLVODMSG_H_