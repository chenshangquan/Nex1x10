#ifndef _MTAGENTMSG_H_
#define _MTAGENTMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmAgentMsg
{
    EV_BGN(AGENT) = EVSEG_AGENT_BGN,
#endif

	/*<<��¼NMS>>
	*snmp_cfg ��SNMP��¼����
	*��Ϣ���� ��service==>dispatch==>mtagent
	*/
    MESSAGE(Ev_MT_AgentLogIn_Cmd)
	BODY(mt::TNMSLogInCfg, nms_login_cfg)

	/*<<��¼NMS���֪ͨ>>
	*nms_login_result ����¼���
	*��Ϣ���� ��mtagent==>dispatch==>service
	*/
	MESSAGE(Ev_MT_AgentLogInResult_Ntf)
	BODY(mt::TNMSLogInResult, nms_login_result)

	/*<<ע��NMS>>
	*��Ϣ���� ��service==>dispatch==>mtagent
	*/
	MESSAGE(Ev_MT_AgentLogOut_Cmd)	

	/*<<�ϱ�Ӧ�����ӵķ�����>>
	*��Ϣ���� ��service==>dispatch==>mtagent
	*/
	MESSAGE(Ev_MT_Agent_Report_ShouldConSrvs_Cmd)	
	BODY(mt::TServerTypes, should_con_srvs)

	/*<<�ϱ�������������Ϣ>>
	*��Ϣ���� ��service==>dispatch==>mtagent
	*/
	MESSAGE(Ev_MT_Agent_Report_ConSrvs_Cmd)	
	BODY(mt::TServerInfos, con_srvs)

	/*<<��NMS�澯>>
	*alarm_trap ���澯�ṹ
	*��Ϣ���� ��service==>dispatch==>mtagent
	*/
	MESSAGE(Ev_MT_Agent_Report_Alarm_Cmd)
	BODY(mt::TAlarmTrap, alarm_trap)

	/*<<�ϱ��Ƿ�Ϊ�Ƽ��汾>>
	*netchange_rpt_data ������仯�ϱ���Ϣ
	*��Ϣ���� ��service==>dispatch==>mtagent
	*/
	MESSAGE(Ev_MT_Agent_Report_IsRecommandVer_Cmd)
	BODY(mt::TBOOL32, brecommond_ver)


	/*<<�쳣�ļ������ϱ�>>
	*crash_log ���쳣��־
	*��Ϣ���� ��service==>dispatch==>mtagent
	*/
	MESSAGE(Ev_MT_Agent_Report_Exception_Log_Cmd)
	BODY(mt::TExceptionFileReportData, crash_log)

	/*<<�쳣�ļ������ϱ��쳣ʱ�����,֪ͨmtservice�������ø���>>
	*exception_time ���쳣ʱ��
	*��Ϣ���� ��mtagent==>dispatch==>service
	*/
	MESSAGE(Ev_MT_Agent_Report_Exception_Time_Ntf)
	BODY(mt::TString, exception_time)

	/*<<֪ͨagent����״̬>>
	*crash_log ���쳣��־
	*��Ϣ���� ��service==>dispatch==>mtagent==>mtguard
	*/
	MESSAGE(Ev_MT_Agent_ConfStatus_Cmd)
	BODY(mt::TAgentConfStatus, crash_log)

	/*<<֪ͨagent��������>>
	*bandwidth ����������
	*��Ϣ���� ��service==>dispatch==>mtagent
	*/
	MESSAGE(Ev_MT_Agent_Bandwidth_Cmd)
	BODY(mt::TMTNetStatus, bandwidth)

	/*<<֪ͨagent���ܿͻ��˵�����״��������仯��ʱ��֪ͨ��>>
	*net_info ���������
	*��Ϣ���� ��service==>dispatch==>mtagent
	*/
	MESSAGE(Ev_MT_Agent_NetInfo_Cmd)
	BODY(mt::TNMSNetInfo, net_info)

	/*<<��ȡ������������Ϣ����>>
	*��Ϣ���� ��mtguard==>dispatch==>service
	*/
	MESSAGE(Ev_MT_Agent_CodecStatistic_Req)

	/*<<��ȡ������������ϢӦ��>>
	*statistic �����������Ϣ
	*��Ϣ���� ��service==>dispatch==>mtguard
	*/
	MESSAGE(Ev_MT_Agent_CodecStatistic_Rsp)
	BODY(mt::TAgentCodecStatistic, statistic)

	/*<<�ն�������Ϣ��Ϣ֪ͨ>>
	*TMtPfmInfo ���ն�������Ϣ��Ϣ
	*��Ϣ���� ��UI==>service==>dispatch==>mtguard
	*/
	MESSAGE(Ev_MT_Agent_MTPFMInfo_Ntf)
	BODY(mt::TMtPfmInfo, statistic)

    /*<<�ն˴��״̬��Ϣ�ϱ�>>
    * ��Ϣ���� : service->agent
	* ���� : mt::TMTAgentPackFileState   ״̬
	*/
    MESSAGE(Ev_MT_Agent_PackFileState_Req)
    BODY(mt::TMTAgentPackFileState, tState)

    /*<<�ն˴��״̬��Ϣ�ϱ�������Ϣ>>
    * ��Ϣ���� : agent->service
	*/
    MESSAGE(Ev_MT_Agent_PackFileState_Rsp)

    /*<<�ϱ����鿨�ٴ���>>
    * ��Ϣ���� : ->agent
	* ���� : mt::TU32  ����
	*/
    MESSAGE(Ev_MT_Agent_BluntCount_Ntf)
    BODY(mt::TU32, tCount)

#if !defined(_MESSAGE_HELP_)
    EV_END(AGENT) = EVSEG_AGENT_END
};
#endif

#define Is_Agent_Msg(m) ((m) >= EV_BGN(AGENT) && (m) <= EV_END(AGENT))

#endif // _MTAGENTMSG_H_