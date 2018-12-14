#ifndef _MTBLLAGENTMSG_H_
#define _MTBLLAGENTMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLAgentMsg
{
    EV_BLL_BGN(AGENT) = EVSEG_BLL_AGENT_BGN,
#endif
	/*<<��¼NMS���֪ͨ>>
	*nms_login_result ����¼���
	*/
	MESSAGE(Ev_MT_BLL_AgentLogInResult_Ntf)
	BODY(mt::TNMSLogInResult, nms_login_result)

	/*<<ע��NMS>>
	*/
	MESSAGE(Ev_MT_BLL_AgentLogIn_Cmd)
	BODY(mt::TNMSLogInCfg, nms_login_cfg)


	/*<<ע��NMS>>
	*/
	MESSAGE(Ev_MT_BLL_AgentLogOut_Cmd)	

	/*<<�ǳ�NMS���֪ͨ>>
	*nms_logout_result ���ǳ����
	*/
	MESSAGE(Ev_MT_BLL_AgentLogOutResult_Ntf)
	BODY(mt::TBOOL32, nms_logout_result)

	/*<<�ϱ�Ӧ�����ӵķ�����>>
	*��Ϣ���� ��mtagent==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_Agent_Report_ShouldConSrvs_Cmd)	
	BODY(mt::TServerTypes, should_con_srvs)


	/*<<�쳣�ļ������ϱ�>>
	*crash_log ���쳣��־
	*��Ϣ���� ��mtagent==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_Agent_Report_Exception_Log_Cmd)
	BODY(mt::TExceptionFileReportData, crash_log)

	/*<<�ն�������Ϣ��Ϣ֪ͨ>>
	*TMtPfmInfo ���ն�������Ϣ��Ϣ
	*��Ϣ���� ��UI==>service
	*/
	MESSAGE(Ev_MT_BLL_Agent_MTPFMInfo_Ntf)
	BODY(mt::TMtPfmInfo, statistic)

    /*<<�����ն���־·����Ϣ>>
    * ��Ϣ���� : sdk -> service
    * ���� : file_path   Ŀ¼
    * ���� : file_name   �ļ���
	*/
    MESSAGE(Ev_MT_BLL_Agent_SetPackLogInfo_Cmd)
    BODY(mt::TString, file_path)
    BODY(mt::TString, file_name)

    /*<<�����ն���־·����ϢNtf>>
    * ��Ϣ���� : sdk -> service
    * ���� : mt::TU3   ������
	*/
    MESSAGE(Ev_MT_BLL_Agent_SetPackLogInfo_Ntf)
    BODY(mt::TU32, errorcode)

    /*<<�ն���־��ʼ�ϴ�>>
    * ��Ϣ���� : sdk -> service
	*/
    MESSAGE(Ev_MT_BLL_Agent_StartUploadLog_Req)

    /*<<�ն���־�ϴ����>>
    * ��Ϣ���� : service->sdk 
	* ���� : mt::TU3   ������
	*/
    MESSAGE(Ev_MT_BLL_Agent_StartUploadLog_Rsp)
	BODY(mt::TU32, errorcode)

    /*<<�ϴ��ն���־֪ͨ>>
	*��Ϣ���� ��sdk==>UI
	*/
	MESSAGE(Ev_MT_BLL_Agent_PackLog_Ntf)
    /*<<�ն����֪ͨ>>
	*��Ϣ���� ��sdk==>UI
	*/
    MESSAGE(Ev_MT_BLL_Agent_DevicePerformance_Ntf)

    /*<<�ն˴��״̬��Ϣ�ϱ�>>
    * ��Ϣ���� : sdk->service
	* ���� : mt::TMTAgentPackFileState   ״̬
	*/
    MESSAGE(Ev_MT_BLL_Agent_PackFileState_Req)
    BODY(mt::TMTAgentPackFileState, tState)

    /*<<�ն˴��״̬��Ϣ�ϱ�������Ϣ>>
    * ��Ϣ���� : service->sdk
	*/
    MESSAGE(Ev_MT_BLL_Agent_PackFileState_Rsp)

#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(AGENT) = EVSEG_BLL_AGENT_END
};
#endif

#define Is_BLL_Agent_Msg(m) ((m) >= EV_BLL_BGN(AGENT) && (m) <= EV_BLL_END(AGENT))

#endif // _MTBLLAGENTMSG_H_