#ifndef _MTBLLMCSERVICEMSG_H_
#define _MTBLLMCSERVICEMSG_H_

#include "mtmsgid.h"
#include "struct.pb.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMtMcServiceMsg
{
    EV_BLL_BGN(MTMCSERVICE) = EVSEG_BLL_MTMCSERVICE_BGN,
#endif//_MESSAGE_HELP_

	/*<<��Ե���չ����������>>
	*call_info ����Ե������չ�����飬Ҫ���еĵ������ն���Ϣ��ֻҪָ�����е�ַ�Ϳ����ˣ�
	*���䷽��ui->dispatch->mtmcservice
	*/
    MESSAGE(Ev_MT_BLL_McAdHoc_Cmd)
	BODY(mt::TMultiMtCallParam, call_info)

	/*<<��Ե���չ��������֪ͨ>>
	*result_code ����Ե������չ������������
	*���䷽��mtmcservice->dispatch->ui
	*/
    MESSAGE(Ev_MT_BLL_McAdHoc_Ntf)//��ʱû���ã������
	BODY(mt::TU32, result_code)

	/*<<����mc����>>
	*mc_param ������mc����
	*���䷽��ui->dispatch->mtmcservice
	*/
	MESSAGE( Ev_MT_BLL_McSetParam_Cmd )
	BODY(mt::TInnerMCParam, mc_param)

	/*<<mc�ͻ���������й㲥��ѯ>>
	*poll_time ����ѯʱ�䣬����
	*poll_broadcast ���Ƿ���ѯ
	*���䷽��mcc->dispatch->mc
	*/
	MESSAGE( Ev_MT_BLL_McPollBroadCast_Cmd )
	BODY(mt::TBOOL32, poll_broadcast)
	BODY(mt::TU32, poll_time)
	 /*<<mc��֮mc�ͻ�����ѯ���>>
	*poll_broadcast ���Ƿ���ѯ
	*���䷽��mc->dispatch->mcc
	*/
	MESSAGE( Ev_MT_BLL_McPollBroadCast_Ntf )
	BODY(mt::TBOOL32, poll_broadcast)

	/*<<Mc�����ն� >>
	* call_info     :    �ն˵�ַ
	*/
	MESSAGE( Ev_MT_BLL_McInviteTer_Cmd )
	BODY(mt::TMultiMtCallParam, call_info)

	/*<<�����ն�ʧ�� >>
	* tMtaddr     :    �ն˵�ַ
	*/
	MESSAGE( Ev_MT_BLL_McInviteFailed_Ntf )   //��ʱ�����⣬���޸�
	BODY(mt::TMtAddr,    tMtaddr)
	BODY(mt::TU32,       tReason) //EmMtCallDisReason

	/*<<Mc��������(û�лظ�) >>
	* call_info     :    �ն˵�ַ
	*/
	MESSAGE( Ev_MT_BLL_McCreateConf_Cmd )
	BODY(mt::TMultiMtCallParam, call_info)

	/*<<Mc�Ҷ��ն�(û�лظ�) >>
	* call_info     :    �ն˵�ַ
	*/
	MESSAGE( Ev_MT_BLL_McDropTer_Cmd )
	BODY(mt::TMtId, tMtId)

	/*<<Mc�Ҷ��ն�(û�лظ�) >>
	*/
	MESSAGE( Ev_MT_BLL_McEndConf_Cmd )
	

#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(MTMCSERVICE) = EVSEG_BLL_MTMCSERVICE_END
};
#endif//_MTBLLMCSERVICEMSG_H_

#define Is_BLL_MtMcService_Msg(m) ((m) >= EV_BLL_BGN(MTMCSERVICE) && (m) <= EV_BLL_END(MTMCSERVICE))

#endif//_MTBLLMCSERVICEMSG_H_