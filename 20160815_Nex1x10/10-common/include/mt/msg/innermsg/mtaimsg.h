#ifndef _MTAIMSG_H_
#define _MTAIMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMtaiMsg
{

	//������ϵͳ�õ������е���Ϣ������� ������Ҫ���֣�mtconfģ�飬 mth323�õ��ģ� ����mc�õ�����Ϣ��
	EV_BGN(MTAI) = EVSEG_MTAIMSG_BGN,
#endif

	/*<<HID���ݴ���>>
    *���䷽��net->dispatch->mtmp
    */
    MESSAGE(Ev_MT_AiAsrMsg_Ntf)
    BODY(mt::TBytes, tBody)

	MESSAGE(Ev_MT_AiAudState_Ntf)
	BODY(mt::TU32, aiState)  //0, idle(not wakeup) //1 listen //2. understanding 

	MESSAGE(Ev_MT_AiNotKnow_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8

	MESSAGE(Ev_MT_AiCreateConf_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8

	MESSAGE(Ev_MT_AiJoinConf_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8
	BODY(mt::TMtJoinConfParamList, tList) ///list�б�

	MESSAGE(Ev_MT_AiInviteConf_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8
	BODY(mt::TMtAiInviteInfoList, tList) ///list�б�

	MESSAGE(Ev_MT_AiSelectNum_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8
	BODY(mt::TU32,   tEnum)        //EmAiActionState
	BODY(mt::TU32,   tNum)        ///ѡ��ĵڼ���
	
	MESSAGE(Ev_MT_AiSendAss_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8
	BODY(mt::TU32,   tEnumState)  //1, ������˫���� 2. �ж�û��Ӳ˫��Դ 3. ����˫��

	MESSAGE(Ev_MT_AiEnSureOrNot_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8
	BODY(mt::TU32, tEnum)         //EmAiActionState
	BODY(mt::TBOOL32, bSure)      ///�Ƿ�ȷ��
 
	MESSAGE(Ev_MT_AiUpDownVolume_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8
	BODY(mt::TBOOL32, tUp)         //EmAiActionState


	MESSAGE(Ev_MT_AiProlongConf_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8

	MESSAGE(Ev_MT_AiEndConf_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8

	MESSAGE(Ev_MT_AiHangConf_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8

	MESSAGE(Ev_MT_AiStartVoiceAide_Cmd)
	BODY(mt::TBOOL32, tStart) ///���������Ƿ�����

	MESSAGE(Ev_MT_AiHangUpOrEndConf_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8

	MESSAGE(Ev_MT_AiGoodBye_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8

	MESSAGE(Ev_MT_AiGetOnLineTerList_Cmd)

	MESSAGE(Ev_MT_AiApplyChair_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8
	
	MESSAGE(Ev_MT_AiSelectView_Ntf)
	BODY(mt::TBytes, tVoice)      ///��Ӧ�Ļ��� 
	BODY(mt::TBytes, tPlaySound)  ///���ĵ�utf-8
	BODY(mt::TBOOL32, tExist)
	BODY(mt::TMtId, tmtid)

#if !defined(_MESSAGE_HELP_)
	EV_END(MTAI) = EVSEG_MTAIMSG_END
};
#endif//_MESSAGE_HELP_

#define Is_Ai_Msg(m) ((m) >= EV_BGN(MTAI) && (m) <= EV_END(MTAI))

#endif//_MTNETMSG_H_
