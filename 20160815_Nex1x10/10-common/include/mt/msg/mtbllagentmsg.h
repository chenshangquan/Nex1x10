#ifndef _MTBLLAGENTMSG_H_
#define _MTBLLAGENTMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLAgentMsg
{
    EV_BLL_BGN(AGENT) = EVSEG_BLL_AGENT_BGN,
#endif
	/*<<登录NMS结果通知>>
	*nms_login_result ：登录结果
	*/
	MESSAGE(Ev_MT_BLL_AgentLogInResult_Ntf)
	BODY(mt::TNMSLogInResult, nms_login_result)

	/*<<注册NMS>>
	*/
	MESSAGE(Ev_MT_BLL_AgentLogIn_Cmd)
	BODY(mt::TNMSLogInCfg, nms_login_cfg)


	/*<<注销NMS>>
	*/
	MESSAGE(Ev_MT_BLL_AgentLogOut_Cmd)	

	/*<<登出NMS结果通知>>
	*nms_logout_result ：登出结果
	*/
	MESSAGE(Ev_MT_BLL_AgentLogOutResult_Ntf)
	BODY(mt::TBOOL32, nms_logout_result)

	/*<<上报应该连接的服务器>>
	*消息流向 ：mtagent==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_Agent_Report_ShouldConSrvs_Cmd)	
	BODY(mt::TServerTypes, should_con_srvs)


	/*<<异常文件内容上报>>
	*crash_log ：异常日志
	*消息流向 ：mtagent==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_Agent_Report_Exception_Log_Cmd)
	BODY(mt::TExceptionFileReportData, crash_log)

	/*<<终端性能信息信息通知>>
	*TMtPfmInfo ：终端性能信息信息
	*消息流向 ：UI==>service
	*/
	MESSAGE(Ev_MT_BLL_Agent_MTPFMInfo_Ntf)
	BODY(mt::TMtPfmInfo, statistic)

    /*<<设置终端日志路径信息>>
    * 消息流向 : sdk -> service
    * 参数 : file_path   目录
    * 参数 : file_name   文件名
	*/
    MESSAGE(Ev_MT_BLL_Agent_SetPackLogInfo_Cmd)
    BODY(mt::TString, file_path)
    BODY(mt::TString, file_name)

    /*<<设置终端日志路径信息Ntf>>
    * 消息流向 : sdk -> service
    * 参数 : mt::TU3   错误码
	*/
    MESSAGE(Ev_MT_BLL_Agent_SetPackLogInfo_Ntf)
    BODY(mt::TU32, errorcode)

    /*<<终端日志开始上传>>
    * 消息流向 : sdk -> service
	*/
    MESSAGE(Ev_MT_BLL_Agent_StartUploadLog_Req)

    /*<<终端日志上传结果>>
    * 消息流向 : service->sdk 
	* 参数 : mt::TU3   错误码
	*/
    MESSAGE(Ev_MT_BLL_Agent_StartUploadLog_Rsp)
	BODY(mt::TU32, errorcode)

    /*<<上传终端日志通知>>
	*消息流向 ：sdk==>UI
	*/
	MESSAGE(Ev_MT_BLL_Agent_PackLog_Ntf)
    /*<<终端诊断通知>>
	*消息流向 ：sdk==>UI
	*/
    MESSAGE(Ev_MT_BLL_Agent_DevicePerformance_Ntf)

    /*<<终端打包状态信息上报>>
    * 消息流向 : sdk->service
	* 参数 : mt::TMTAgentPackFileState   状态
	*/
    MESSAGE(Ev_MT_BLL_Agent_PackFileState_Req)
    BODY(mt::TMTAgentPackFileState, tState)

    /*<<终端打包状态信息上报返回消息>>
    * 消息流向 : service->sdk
	*/
    MESSAGE(Ev_MT_BLL_Agent_PackFileState_Rsp)

#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(AGENT) = EVSEG_BLL_AGENT_END
};
#endif

#define Is_BLL_Agent_Msg(m) ((m) >= EV_BLL_BGN(AGENT) && (m) <= EV_BLL_END(AGENT))

#endif // _MTBLLAGENTMSG_H_