#ifndef _MTAGENTMSG_H_
#define _MTAGENTMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmAgentMsg
{
    EV_BGN(AGENT) = EVSEG_AGENT_BGN,
#endif

	/*<<登录NMS>>
	*snmp_cfg ：SNMP登录配置
	*消息流向 ：service==>dispatch==>mtagent
	*/
    MESSAGE(Ev_MT_AgentLogIn_Cmd)
	BODY(mt::TNMSLogInCfg, nms_login_cfg)

	/*<<登录NMS结果通知>>
	*nms_login_result ：登录结果
	*消息流向 ：mtagent==>dispatch==>service
	*/
	MESSAGE(Ev_MT_AgentLogInResult_Ntf)
	BODY(mt::TNMSLogInResult, nms_login_result)

	/*<<注销NMS>>
	*消息流向 ：service==>dispatch==>mtagent
	*/
	MESSAGE(Ev_MT_AgentLogOut_Cmd)	

	/*<<上报应该连接的服务器>>
	*消息流向 ：service==>dispatch==>mtagent
	*/
	MESSAGE(Ev_MT_Agent_Report_ShouldConSrvs_Cmd)	
	BODY(mt::TServerTypes, should_con_srvs)

	/*<<上报服务器链接信息>>
	*消息流向 ：service==>dispatch==>mtagent
	*/
	MESSAGE(Ev_MT_Agent_Report_ConSrvs_Cmd)	
	BODY(mt::TServerInfos, con_srvs)

	/*<<向NMS告警>>
	*alarm_trap ：告警结构
	*消息流向 ：service==>dispatch==>mtagent
	*/
	MESSAGE(Ev_MT_Agent_Report_Alarm_Cmd)
	BODY(mt::TAlarmTrap, alarm_trap)

	/*<<上报是否为推荐版本>>
	*netchange_rpt_data ：网络变化上报信息
	*消息流向 ：service==>dispatch==>mtagent
	*/
	MESSAGE(Ev_MT_Agent_Report_IsRecommandVer_Cmd)
	BODY(mt::TBOOL32, brecommond_ver)


	/*<<异常文件内容上报>>
	*crash_log ：异常日志
	*消息流向 ：service==>dispatch==>mtagent
	*/
	MESSAGE(Ev_MT_Agent_Report_Exception_Log_Cmd)
	BODY(mt::TExceptionFileReportData, crash_log)

	/*<<异常文件内容上报异常时间更新,通知mtservice进行配置更新>>
	*exception_time ：异常时间
	*消息流向 ：mtagent==>dispatch==>service
	*/
	MESSAGE(Ev_MT_Agent_Report_Exception_Time_Ntf)
	BODY(mt::TString, exception_time)

	/*<<通知agent会议状态>>
	*crash_log ：异常日志
	*消息流向 ：service==>dispatch==>mtagent==>mtguard
	*/
	MESSAGE(Ev_MT_Agent_ConfStatus_Cmd)
	BODY(mt::TAgentConfStatus, crash_log)

	/*<<通知agent带宽检测结果>>
	*bandwidth ：带宽检测结果
	*消息流向 ：service==>dispatch==>mtagent
	*/
	MESSAGE(Ev_MT_Agent_Bandwidth_Cmd)
	BODY(mt::TMTNetStatus, bandwidth)

	/*<<通知agent网管客户端的网络状况（网络变化的时候通知）>>
	*net_info ：网络情况
	*消息流向 ：service==>dispatch==>mtagent
	*/
	MESSAGE(Ev_MT_Agent_NetInfo_Cmd)
	BODY(mt::TNMSNetInfo, net_info)

	/*<<获取会议编解码器信息请求>>
	*消息流向 ：mtguard==>dispatch==>service
	*/
	MESSAGE(Ev_MT_Agent_CodecStatistic_Req)

	/*<<获取会议编解码器信息应答>>
	*statistic ：编解码器信息
	*消息流向 ：service==>dispatch==>mtguard
	*/
	MESSAGE(Ev_MT_Agent_CodecStatistic_Rsp)
	BODY(mt::TAgentCodecStatistic, statistic)

	/*<<终端性能信息信息通知>>
	*TMtPfmInfo ：终端性能信息信息
	*消息流向 ：UI==>service==>dispatch==>mtguard
	*/
	MESSAGE(Ev_MT_Agent_MTPFMInfo_Ntf)
	BODY(mt::TMtPfmInfo, statistic)

    /*<<终端打包状态信息上报>>
    * 消息流向 : service->agent
	* 参数 : mt::TMTAgentPackFileState   状态
	*/
    MESSAGE(Ev_MT_Agent_PackFileState_Req)
    BODY(mt::TMTAgentPackFileState, tState)

    /*<<终端打包状态信息上报返回消息>>
    * 消息流向 : agent->service
	*/
    MESSAGE(Ev_MT_Agent_PackFileState_Rsp)

    /*<<上报会议卡顿次数>>
    * 消息流向 : ->agent
	* 参数 : mt::TU32  次数
	*/
    MESSAGE(Ev_MT_Agent_BluntCount_Ntf)
    BODY(mt::TU32, tCount)

#if !defined(_MESSAGE_HELP_)
    EV_END(AGENT) = EVSEG_AGENT_END
};
#endif

#define Is_Agent_Msg(m) ((m) >= EV_BGN(AGENT) && (m) <= EV_END(AGENT))

#endif // _MTAGENTMSG_H_