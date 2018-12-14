#ifndef _MTAIMSG_H_
#define _MTAIMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMtaiMsg
{

	//会议子系统用到的所有的消息都在这里， 这里需要区分，mtconf模块， mth323用到的， 内置mc用到的消息。
	EV_BGN(MTAI) = EVSEG_MTAIMSG_BGN,
#endif

	/*<<HID数据传输>>
    *传输方向：net->dispatch->mtmp
    */
    MESSAGE(Ev_MT_AiAsrMsg_Ntf)
    BODY(mt::TBytes, tBody)

	MESSAGE(Ev_MT_AiAudState_Ntf)
	BODY(mt::TU32, aiState)  //0, idle(not wakeup) //1 listen //2. understanding 

	MESSAGE(Ev_MT_AiNotKnow_Ntf)
	BODY(mt::TBytes, tVoice)      ///对应的话语 
	BODY(mt::TBytes, tPlaySound)  ///中文的utf-8

	MESSAGE(Ev_MT_AiCreateConf_Ntf)
	BODY(mt::TBytes, tVoice)      ///对应的话语 
	BODY(mt::TBytes, tPlaySound)  ///中文的utf-8

	MESSAGE(Ev_MT_AiJoinConf_Ntf)
	BODY(mt::TBytes, tVoice)      ///对应的话语 
	BODY(mt::TBytes, tPlaySound)  ///中文的utf-8
	BODY(mt::TMtJoinConfParamList, tList) ///list列表

	MESSAGE(Ev_MT_AiInviteConf_Ntf)
	BODY(mt::TBytes, tVoice)      ///对应的话语 
	BODY(mt::TBytes, tPlaySound)  ///中文的utf-8
	BODY(mt::TMtAiInviteInfoList, tList) ///list列表

	MESSAGE(Ev_MT_AiSelectNum_Ntf)
	BODY(mt::TBytes, tVoice)      ///对应的话语 
	BODY(mt::TBytes, tPlaySound)  ///中文的utf-8
	BODY(mt::TU32,   tEnum)        //EmAiActionState
	BODY(mt::TU32,   tNum)        ///选择的第几个
	
	MESSAGE(Ev_MT_AiSendAss_Ntf)
	BODY(mt::TBytes, tVoice)      ///对应的话语 
	BODY(mt::TBytes, tPlaySound)  ///中文的utf-8
	BODY(mt::TU32,   tEnumState)  //1, 正常发双流， 2. 判断没有硬双流源 3. 抢发双流

	MESSAGE(Ev_MT_AiEnSureOrNot_Ntf)
	BODY(mt::TBytes, tVoice)      ///对应的话语 
	BODY(mt::TBytes, tPlaySound)  ///中文的utf-8
	BODY(mt::TU32, tEnum)         //EmAiActionState
	BODY(mt::TBOOL32, bSure)      ///是否确认
 
	MESSAGE(Ev_MT_AiUpDownVolume_Ntf)
	BODY(mt::TBytes, tVoice)      ///对应的话语 
	BODY(mt::TBytes, tPlaySound)  ///中文的utf-8
	BODY(mt::TBOOL32, tUp)         //EmAiActionState


	MESSAGE(Ev_MT_AiProlongConf_Ntf)
	BODY(mt::TBytes, tVoice)      ///对应的话语 
	BODY(mt::TBytes, tPlaySound)  ///中文的utf-8

	MESSAGE(Ev_MT_AiEndConf_Ntf)
	BODY(mt::TBytes, tVoice)      ///对应的话语 
	BODY(mt::TBytes, tPlaySound)  ///中文的utf-8

	MESSAGE(Ev_MT_AiHangConf_Ntf)
	BODY(mt::TBytes, tVoice)      ///对应的话语 
	BODY(mt::TBytes, tPlaySound)  ///中文的utf-8

	MESSAGE(Ev_MT_AiStartVoiceAide_Cmd)
	BODY(mt::TBOOL32, tStart) ///语音助手是否启用

	MESSAGE(Ev_MT_AiHangUpOrEndConf_Ntf)
	BODY(mt::TBytes, tVoice)      ///对应的话语 
	BODY(mt::TBytes, tPlaySound)  ///中文的utf-8

	MESSAGE(Ev_MT_AiGoodBye_Ntf)
	BODY(mt::TBytes, tVoice)      ///对应的话语 
	BODY(mt::TBytes, tPlaySound)  ///中文的utf-8

	MESSAGE(Ev_MT_AiGetOnLineTerList_Cmd)

	MESSAGE(Ev_MT_AiApplyChair_Ntf)
	BODY(mt::TBytes, tVoice)      ///对应的话语 
	BODY(mt::TBytes, tPlaySound)  ///中文的utf-8
	
	MESSAGE(Ev_MT_AiSelectView_Ntf)
	BODY(mt::TBytes, tVoice)      ///对应的话语 
	BODY(mt::TBytes, tPlaySound)  ///中文的utf-8
	BODY(mt::TBOOL32, tExist)
	BODY(mt::TMtId, tmtid)

#if !defined(_MESSAGE_HELP_)
	EV_END(MTAI) = EVSEG_MTAIMSG_END
};
#endif//_MESSAGE_HELP_

#define Is_Ai_Msg(m) ((m) >= EV_BGN(MTAI) && (m) <= EV_END(MTAI))

#endif//_MTNETMSG_H_
