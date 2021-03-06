#ifndef _MTBLLRESTOTHERMSG_H_
#define _MTBLLRESTOTHERMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)

enum EmBLLMtRestMsg
{
    EV_BLL_BGN(MTREST) = EVSEG_BLL_REST_BGN,
#endif

	/**********************************************************************************
	* < 销毁API句柄命令 >
	* ----------------------------------------------------------
	* 参数：TU32：					句柄
	* ----------------------------------------------------------
	* 发送方向：mtsdk -> mtim
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestDestoryHandler_Cmd)
	BODY(mt::TU32, handler)

	
	/**********************************************************************************
	* < 设置平台accountToken值请求 >
	* ----------------------------------------------------------
	* 参数：无
	* ----------------------------------------------------------
	* 发送方向：mtsdk -> mtim
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestSetPlatformAccountToken_Req)

	
	/**********************************************************************************
	* < 设置平台accountToken值应答 >
	* ----------------------------------------------------------
	* 参数：TRestErrorInfo：				错误码
		    TString：						Token值
	* ----------------------------------------------------------
	* 发送方向：mtim -> mtsdk
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestSetPlatformAccountToken_Rsp)
	BODY(mt::TRestErrorInfo, ErrorID)
	BODY(mt::TString, Token)
	
	
	/**********************************************************************************
	* < 获得平台APIaccountToken请求 >
	* ----------------------------------------------------------
	* 参数：TString：				服务器地址
	* ----------------------------------------------------------
	* 发送方向：mtsdk -> mtim
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestGetPlatformAccountToken_Req)
	BODY(mt::TString, SrvAddr)
	
	/**********************************************************************************
	* < 获得平台APIaccountToken应答 >
	* ----------------------------------------------------------
	* 参数：TRestErrorInfo：				错误码
		    TString：						Token值
	* ----------------------------------------------------------
	* 发送方向：mtim -> mtsdk
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestGetPlatformAccountToken_Rsp)
	BODY(mt::TRestErrorInfo, ErrorID)
	BODY(mt::TString, AccountToken)
	
	
	/**********************************************************************************
	* < 用户登录平台API请求 >
	* ----------------------------------------------------------
	* 参数：TMTWeiboLogin：				登录信息
	* ----------------------------------------------------------
	* 发送方向：mtsdk -> mtim
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestPlatformAPILogin_Req)
	BODY(mt::TMTWeiboLogin, TMTWeiboLogin)
	
	/**********************************************************************************
	* < 用户登录平台API应答 >
	* ----------------------------------------------------------
	* 参数：TRestErrorInfo：				错误码
		    TString：						用户名
	* ----------------------------------------------------------
	* 发送方向：mtim -> mtsdk
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestPlatformAPILogin_Rsp)
	BODY(mt::TRestErrorInfo, ErrorID)
	BODY(mt::TString, username)
	
	/**********************************************************************************
	* < 用户登出平台API>
	* ----------------------------------------------------------
	* ----------------------------------------------------------
	* 发送方向：mtsdk -> mtim
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestPlatformAPILogOut_Cmd)
	
	/**********************************************************************************
	* < 查询账号详细信息请求 >
	* ----------------------------------------------------------
	* 参数：TRestErrorInfo：				错误码
		    TString：						用户名
	* ----------------------------------------------------------
	* 发送方向：mtsdk -> mtim
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestGetAccountInfo_Req)
	BODY(mt::TMTAccountManagerSystem, TMTAccountManagerSystem)
	
	
	/**********************************************************************************
	* < 查询账号详细信息应答 >
	* ----------------------------------------------------------
	* 参数：TRestErrorInfo：				错误码
		    TMTWbParse_Keda_EntUser：		账号详细信息
	* ----------------------------------------------------------
	* 发送方向：mtim -> mtsdk
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestGetAccountInfo_Rsp)
	BODY(mt::TRestErrorInfo, ErrorID)
	BODY(mt::TMTWbParse_Keda_EntUser, TMTWbParse_Keda_EntUser)	
	
	
	/**********************************************************************************
	* < 修改账号详细信息请求 >
	* ----------------------------------------------------------
	* 参数：TRestErrorInfo：				错误码
		    TMTAccountManagerSystem：		账号信息
	* ----------------------------------------------------------
	* 发送方向：mtsdk -> mtim
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestUpdateAccountInfo_Req)
	BODY(mt::TMTAccountManagerSystem, TMTAccountManagerSystem)
	
	
	/**********************************************************************************
	* < 修改账号详细信息应答 >
	* ----------------------------------------------------------
	* 参数：TRestErrorInfo：				错误码
	*		TU32：							ContextID（对应VALUE）
	* ----------------------------------------------------------
	* 发送方向：mtim -> mtsdk
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestUpdateAccountInfo_Rsp)
	BODY(mt::TRestErrorInfo, ErrorID)
	BODY(mt::TU32, ContextID)
	
	
	/**********************************************************************************
	* < 修改账号密码请求 >
	* ----------------------------------------------------------
	* 参数：TRestErrorInfo：				错误码
		    TModifyPwd：					修改密码结构
	* ----------------------------------------------------------
	* 发送方向：mtsdk -> mtim
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestUpdatePassword_Req)
	BODY(mt::TModifyPwd, TModifyPwd)
	
	
	/**********************************************************************************
	* < 修改账号密码应答 >
	* ----------------------------------------------------------
	* 参数：TRestErrorInfo：				错误码
	*		TU32：							ContextID
	* ----------------------------------------------------------
	* 发送方向：mtim -> mtsdk
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestUpdatePassword_Rsp)
	BODY(mt::TRestErrorInfo, ErrorID)
	
	
	/**********************************************************************************
	* < 忘记密码后的请求 >
	* ----------------------------------------------------------
	* 参数：TString：					邮箱
	* ----------------------------------------------------------
	* 发送方向：mtsdk -> mtim
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestPassWordByMail_Req)
	BODY(mt::TString, mail)
	
	
	/**********************************************************************************
	* < 忘记密码后的应答 >
	* ----------------------------------------------------------
	* 参数：TRestErrorInfo：				错误码
	*		TU32：							ContextID
	* ----------------------------------------------------------
	* 发送方向：mtim -> mtsdk
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestPassWordByMail_Rsp)
	BODY(mt::TRestErrorInfo, ErrorID)
	
	
	/**********************************************************************************
	* < 获取第三方终端设备组版本信息请求 >
	* ----------------------------------------------------------
	* 参数：TMTMeetingList：				当前会议列表
	* ----------------------------------------------------------
	* 发送方向：mtsdk -> mtim
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestGetThirdPartyTerminalSysVer_Req)

	
	/**********************************************************************************
	* < 获取第三方终端设备组版本信息应答 >
	* ----------------------------------------------------------
	* 参数：TRestErrorInfo：				错误码
		    TString：						版本号
	* ----------------------------------------------------------
	* 发送方向：mtim -> mtsdk
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestGetThirdPartyTerminalSysVer_Rsp)
	BODY(mt::TRestErrorInfo, ErrorID)
	BODY(mt::TString, VerId)
	
	
	/**********************************************************************************
	* < 获取第三方终端设备组和设备信息请求 >
	* ----------------------------------------------------------
	* 参数：无
	* ----------------------------------------------------------
	* 发送方向：mtsdk -> mtim
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestGetAllThirdPartyTerminals_Req)

	
	/**********************************************************************************
	* < 获取第三方终端设备组和设备信息应答 >
	* ----------------------------------------------------------
	* 参数：TRestErrorInfo：				错误码
	* ----------------------------------------------------------
	* 发送方向：mtim -> mtsdk
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestGetAllThirdPartyTerminals_Rsp)
	BODY(mt::TRestErrorInfo, ErrorID)
	
	/**********************************************************************************
	* < 获取第三方终端设备组信息请求 >
	* ----------------------------------------------------------
	* 参数：无
	* ----------------------------------------------------------
	* 发送方向：mtsdk -> mtim
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestGetThirdPartyTerminalGroups_Req)

	
	/**********************************************************************************
	* < 获取第三方终端设备组信息应答 >
	* ----------------------------------------------------------
	* 参数：TRestErrorInfo：				错误码
	* ----------------------------------------------------------
	* 发送方向：mtim -> mtsdk
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestGetThirdPartyTerminalGroups_Rsp)
	BODY(mt::TRestErrorInfo, ErrorID)
	
	
	/**********************************************************************************
	* < 获取第三方终端设备组下设备信息(不包含子分组)请求 >
	* ----------------------------------------------------------
	* 参数：TU32：				组ID
	* ----------------------------------------------------------
	* 发送方向：mtsdk -> mtim
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestGetThirdPartyTerminalsInGroup_Req)
	BODY(mt::TU32, GroupID)

	
	/**********************************************************************************
	* < 获取第三方终端设备组下设备信息(不包含子分组)应答 >
	* ----------------------------------------------------------
	* 参数：TRestErrorInfo：				错误码
	* ----------------------------------------------------------
	* 发送方向：mtim -> mtsdk
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestGetThirdPartyTerminalsInGroup_Rsp)
	BODY(mt::TRestErrorInfo, ErrorID)

	
	/**********************************************************************************
	* < 获取监控设备组版本信息请求 >
	* ----------------------------------------------------------
	* 参数：无
	* ----------------------------------------------------------
	* 发送方向：mtsdk -> mtim
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestGetMonitorGroupVersion_Req)

	
	/**********************************************************************************
	* < 获取监控设备组版本信息应答 >
	* ----------------------------------------------------------
	* 参数：TRestErrorInfo：				错误码
		    TGetMonitorGroupVersionAck：	设备组信息
	* ----------------------------------------------------------
	* 发送方向：mtim -> mtsdk
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestGetMonitorGroupVersion_Rsp)
	BODY(mt::TRestErrorInfo, ErrorID)
	BODY(mt::TGetMonitorGroupVersionAck, TGetMonitorGroupVersionAck)
	
	
	/**********************************************************************************
	* < 获取监控设备组和设备信息请求 >
	* ----------------------------------------------------------
	* 参数：无
	* ----------------------------------------------------------
	* 发送方向：mtsdk -> mtim
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestGetAllMonitors_Req)

	
	/**********************************************************************************
	* < 获取监控设备组和设备信息应答 >
	* ----------------------------------------------------------
	* 参数：TRestErrorInfo：				错误码
	* ----------------------------------------------------------
	* 发送方向：mtim -> mtsdk
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestGetAllMonitors_Rsp)
	BODY(mt::TRestErrorInfo, ErrorID)
	
	
	/**********************************************************************************
	* < 获取监控设备组信息请求 >
	* ----------------------------------------------------------
	* 参数：无
	* ----------------------------------------------------------
	* 发送方向：mtsdk -> mtim
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestGetMonitorGroups_Req)

	
	/**********************************************************************************
	* < 获取监控设备组信息应答 >
	* ----------------------------------------------------------
	* 参数：TRestErrorInfo：				错误码
	* ----------------------------------------------------------
	* 发送方向：mtim -> mtsdk
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestGetMonitorGroups_Rsp)
	BODY(mt::TRestErrorInfo, ErrorID)
	BODY(mt::TMTMonitorGroups, TMTMonitorGroups)
	
	/**********************************************************************************
	* < 获取监控设备组信息分包结束应答 >
	* ----------------------------------------------------------
	* 参数：
	* ----------------------------------------------------------
	* 发送方向：mtim -> mtsdk
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestGetMonitorGroups_Fin_Rsp)


	/**********************************************************************************
	* < 获取监控设备组下设备信息(不包含子分组)请求 >
	* ----------------------------------------------------------
	* 参数：无
	* ----------------------------------------------------------
	* 发送方向：mtsdk -> mtim
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestGetMonitorInGroup_Req)

	
	/**********************************************************************************
	* < 获取监控设备组下设备信息(不包含子分组)应答 >
	* ----------------------------------------------------------
	* 参数：TRestErrorInfo：				错误码
	* ----------------------------------------------------------
	* 发送方向：mtim -> mtsdk
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestGetMonitorInGroup_Rsp)
	BODY(mt::TRestErrorInfo, ErrorID)
	BODY(mt::TMTMonitorDevices, TMTMonitorDevices)
	/**********************************************************************************
	* < 获取监控设备组下设备信息(不包含子分组)分包结束应答 >
	* ----------------------------------------------------------
	* 参数：
	* ----------------------------------------------------------
	* 发送方向：mtim -> mtsdk
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestGetMonitorInGroup_Fin_Rsp)
	
	/**********************************************************************************
	* < 用户Token失效，通知上层 >
	* ----------------------------------------------------------
	* 参数：TRestErrorInfo：				错误码
	* ----------------------------------------------------------
	* 发送方向：mtim -> mtsdk
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestUserTokenExpired_Ntf)
	BODY(mt::TRestErrorInfo, ErrorID)

	
	/**********************************************************************************
	* < 用户Session失效，通知上层 >
	* ----------------------------------------------------------
	* 参数：TRestErrorInfo：				错误码
	* ----------------------------------------------------------
	* 发送方向：mtim -> mtsdk
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestUserSessionExpired_Ntf)
	BODY(mt::TRestErrorInfo, ErrorID)

    /**********************************************************************************
	* < 用户SSO_COOKIE失效，通知上层 >
	* ----------------------------------------------------------
	* 参数：TRestErrorInfo：				错误码
	* ----------------------------------------------------------
	* 发送方向：mtim -> mtsdk
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestUserSSOCookieExpired_Ntf)
	BODY(mt::TRestErrorInfo, ErrorID)
	
	/**********************************************************************************
	* < 请求设备组及组内设备信息 >
	* ----------------------------------------------------------
	* 参数：TRestErrorInfo：				错误码
			TMTMonitorGroups
	* ----------------------------------------------------------
	* 发送方向：mtim -> mtsdk
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_BLL_RestGetAllThirdPartyGroupsInfo_Rsp )
	BODY(mt::TRestErrorInfo, ErrorID)
	BODY(mt::TMTMonitorGroups, 1)

	/**********************************************************************************
	* < 请求设备组及组内设备信息回复 >
	* ----------------------------------------------------------
	* 参数：TRestErrorInfo：				错误码
			TMTMonitorDevices
	* ----------------------------------------------------------
	* 发送方向：mtim -> mtsdk
	* ******************************************************************************** */	
   MESSAGE(Ev_MT_BLL_RestGetAllThirdPartyDeviceInfo_Rsp )
   BODY(mt::TRestErrorInfo, ErrorID)
   BODY(mt::TMTMonitorDevices, 1 )


   	/**********************************************************************************
	* < 只请求设备组信息回复 >
	* ----------------------------------------------------------
	* 参数：TRestErrorInfo：				错误码
			TMTMonitorGroups
	* ----------------------------------------------------------
	* 发送方向：mtim -> mtsdk
	* ******************************************************************************** */	
   MESSAGE(Ev_MT_BLL_RestGetThirdPartyGroupsOnly_Rsp )
   BODY(mt::TRestErrorInfo, ErrorID)
   BODY(mt::TMTMonitorGroups, 1)

    /**********************************************************************************
	* < 只请求设备信息回复 >
	* ----------------------------------------------------------
	* 参数：TRestErrorInfo：				错误码
			TMTMonitorGroups
	* ----------------------------------------------------------
	* 发送方向：mtim -> mtsdk
	* ******************************************************************************** */	
   MESSAGE(Ev_MT_BLL_RestGetThirdPartyDeviceOnly_Rsp )
   BODY(mt::TRestErrorInfo, ErrorID)
   BODY(mt::TMTMonitorDevices, 1)

 #if !defined(_MESSAGE_HELP_)
     EV_BLL_END(MTREST) = EVSEG_BLL_REST_END
};
#endif

#define Is_BLL_MtREST_Msg(m) ((m) >= EV_BLL_BGN(MTREST) && (m) <= EV_BLL_END(MTREST))

#endif // _MTBLLRESTOTHERMSG_H_