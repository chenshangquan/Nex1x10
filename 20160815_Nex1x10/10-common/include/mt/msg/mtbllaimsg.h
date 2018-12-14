#ifndef _MTBLLAIMSG_H_
#define _MTBLLAIMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMtAiMsg
{
    EV_BLL_BGN(MTAI) = EVSEG_BLL_MTAIMSG_BGN,
#endif

	MESSAGE(Ev_MT_BLL_AiAudState_Ntf)
	BODY(mt::TU32, aiState)  //0, idle(not wakeup) //1 listen //2. understanding 

	MESSAGE(Ev_MT_BLL_AiNotKnow_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8

	MESSAGE(Ev_MT_BLL_AiCreateConf_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8

	MESSAGE(Ev_MT_BLL_AiJoinConf_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8
	BODY(mt::TMtJoinConfParamList, tList) ///list�б�

	MESSAGE(Ev_MT_BLL_AiInviteConf_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8
	BODY(mt::TMtAiInviteInfoList, tList) ///list�б�

	MESSAGE(Ev_MT_BLL_AiSelectNum_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8
	BODY(mt::TU32,   tEnum)        //EmAiActionState
	BODY(mt::TU32,   tNum)        ///ѡ��ĵڼ���
	
	MESSAGE(Ev_MT_BLL_AiSendAss_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8
	BODY(mt::TU32,   tEnumState)  //1, ������˫���� 2. �ж�û��Ӳ˫��Դ 3. ����˫��

	MESSAGE(Ev_MT_BLL_AiEnSureOrNot_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8
	BODY(mt::TU32, tEnum)         //EmAiActionState
	BODY(mt::TBOOL32, bSure)      ///�Ƿ�ȷ��
 
	MESSAGE(Ev_MT_BLL_AiUpDownVolume_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8
	BODY(mt::TBOOL32, tUp)         //EmAiActionState


	MESSAGE(Ev_MT_BLL_AiProlongConf_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8

	MESSAGE(Ev_MT_BLL_AiEndConf_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8

	MESSAGE(Ev_MT_BLL_AiHangConf_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8

	MESSAGE(Ev_MT_BLL_AiHangUpOrEndConf_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8

	MESSAGE(Ev_MT_BLL_AiGoodBye_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8

	MESSAGE(Ev_MT_BLL_AiApplyChair_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8

	MESSAGE(Ev_MT_BLL_AiSelectView_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8
	BODY(mt::TBOOL32, tExist)
	BODY(mt::TMtId, tmtid)

	
 #if !defined(_MESSAGE_HELP_)
     EV_BLL_END(MTAI) = EVSEG_BLL_MTAIMSG_END
};
#endif

#define Is_BLL_MtAi_Msg(m) ((m) >= EV_BLL_BGN(MTAI) && (m) <= EV_BLL_END(MTAI))

#endif