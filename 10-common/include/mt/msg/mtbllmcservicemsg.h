#ifndef _MTBLLMCSERVICEMSG_H_
#define _MTBLLMCSERVICEMSG_H_

#include "mtmsgid.h"
#include "struct.pb.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMtMcServiceMsg
{
    EV_BLL_BGN(MTMCSERVICE) = EVSEG_BLL_MTMCSERVICE_BGN,
#endif//_MESSAGE_HELP_

	/*<<点对点扩展多点会议请求>>
	*call_info ：点对点会议扩展多点会议，要呼叫的第三方终端信息（只要指定呼叫地址就可以了）
	*传输方向：ui->dispatch->mtmcservice
	*/
    MESSAGE(Ev_MT_BLL_McAdHoc_Cmd)
	BODY(mt::TMultiMtCallParam, call_info)

	/*<<点对点扩展多点会议结果通知>>
	*result_code ：点对点会议扩展多点会议结果编码
	*传输方向：mtmcservice->dispatch->ui
	*/
    MESSAGE(Ev_MT_BLL_McAdHoc_Ntf)//暂时没有用，待添加
	BODY(mt::TU32, result_code)

	/*<<设置mc参数>>
	*mc_param ：内置mc参数
	*传输方向：ui->dispatch->mtmcservice
	*/
	MESSAGE( Ev_MT_BLL_McSetParam_Cmd )
	BODY(mt::TInnerMCParam, mc_param)

	/*<<mc客户端请求进行广播轮询>>
	*poll_time ：轮询时间，毫秒
	*poll_broadcast ：是否轮询
	*传输方向：mcc->dispatch->mc
	*/
	MESSAGE( Ev_MT_BLL_McPollBroadCast_Cmd )
	BODY(mt::TBOOL32, poll_broadcast)
	BODY(mt::TU32, poll_time)
	 /*<<mc告之mc客户端轮询结果>>
	*poll_broadcast ：是否轮询
	*传输方向：mc->dispatch->mcc
	*/
	MESSAGE( Ev_MT_BLL_McPollBroadCast_Ntf )
	BODY(mt::TBOOL32, poll_broadcast)

	/*<<Mc邀请终端 >>
	* call_info     :    终端地址
	*/
	MESSAGE( Ev_MT_BLL_McInviteTer_Cmd )
	BODY(mt::TMultiMtCallParam, call_info)

	/*<<邀请终端失败 >>
	* tMtaddr     :    终端地址
	*/
	MESSAGE( Ev_MT_BLL_McInviteFailed_Ntf )   //暂时有问题，待修改
	BODY(mt::TMtAddr,    tMtaddr)
	BODY(mt::TU32,       tReason) //EmMtCallDisReason

	/*<<Mc创建会议(没有回复) >>
	* call_info     :    终端地址
	*/
	MESSAGE( Ev_MT_BLL_McCreateConf_Cmd )
	BODY(mt::TMultiMtCallParam, call_info)

	/*<<Mc挂断终端(没有回复) >>
	* call_info     :    终端地址
	*/
	MESSAGE( Ev_MT_BLL_McDropTer_Cmd )
	BODY(mt::TMtId, tMtId)

	/*<<Mc挂断终端(没有回复) >>
	*/
	MESSAGE( Ev_MT_BLL_McEndConf_Cmd )
	

#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(MTMCSERVICE) = EVSEG_BLL_MTMCSERVICE_END
};
#endif//_MTBLLMCSERVICEMSG_H_

#define Is_BLL_MtMcService_Msg(m) ((m) >= EV_BLL_BGN(MTMCSERVICE) && (m) <= EV_BLL_END(MTMCSERVICE))

#endif//_MTBLLMCSERVICEMSG_H_