#ifndef _MTOSPTIMERMSG_H_
#define _MTOSPTIMERMSG_H_

#include "kdvtype.h"
#include "mtospmsgid.h"

//OSP�Ķ�ʱ����Ϣͳһ�ڴ˶���
enum EmMtOspMsgTimer
{
	Ev_OspTimer_Start = EVSEG_MTOSPMSG_TIMER_BGN,

	Ev_Conf_CreateConf_Timer,        //�������鳬ʱ��ʱ�� 

	Ev_Conf_JoinConf_Timer,          //������鳬ʱ��ʱ

	/* ϵͳ���ƶ�ʱ�� */
	Ev_SysCtrl_Timer_KeepAlive,		///< ��ʱɨ�������ϵͳ�Ƿ���Ķ�ʱ��

	Ev_Im_Timer_RetryLoginXmpp,		///< ����XMPP��ʱ��

	Ev_Im_Timer_Ping,				///< Ping��ʱ��

	Ev_Im_Timer_OneSecond,          ///< һ�붨ʱ��
	
	Ev_Im_Timer_MemberStatus, 		///< �û�״̬��ʱ��
	
	Ev_Rest_Timer_KeepPlatformSrvAlive, 		///< ���ֺ�APIƽ̨������ 

	Ev_Timer_KeepAlive,				///< ÿ��ģ�鶨ʱɨ���ϱ��Լ��Ǵ���

	Ev_Timer_OperationCount,		///< �����жϴ����õĶ�ʱ��

	/*������ϵͳ��ʱ����Ϣ���忪ʼ*/
	Ev_OspTimer_GuardCheck,        ///<���ܵ�¼�ɹ���һֱ��������(��ʱû���������)
	Ev_OspTimer_GuardConfCheck,    ///<���鿪ʼ��һֱ���Ķ�ʱ��
	Ev_OspTimer_CheckConnectNMS,   ///<����������ܷ������Ƿ������ϵĶ�ʱ��
	Ev_OspTimer_CheckRegNMS,       ///<����¼���ܷ������Ƿ��¼�ϵĶ�ʱ��
	Ev_OspTimer_NMSHeartBeat,      ///<�������ܷ����������Ķ�ʱ��
	Ev_OspTimer_CheckCodecStatis,      ///<��ȡ����Ƶͳ����Ϣ��ʱ��
    Ev_OspTimer_AgentUploadFile,  ///�ϴ��ļ���־
	/*������ϵͳ��ʱ����Ϣ�������*/

	Ev_OspTimer_MtStandbyCountDown,		///< �ն˴�������ʱ
	Ev_OspTimer_MtAutoStandbyCheck,		    ///< �Զ�������ⶨʱ��
	Ev_OspTimer_MtStandbyWakeupCheck,		///< ����/���ѳ�ʱ��ⶨʱ��
	Ev_OspTimer_MtCaptureStateCheck,		///< ץ��״̬���

	Ev_H323_ConfEstablish_Timer,             ///<323ģ�飬 ���н�����ʱû���յ�connect,��disconnect
	Ev_H323_DisConnect_Timer,                ///<323ģ�飬 �ҶϺ���ȥ��ʱû�յ�disconnect
	Ev_H323_SendTroudTrip_Timer,             ///<323ģ�飬 ����troudtrip��ʱ��
	Ev_H323_RasLRRQTimer,                    ///<323ģ�飬 ras ������ע�ᶨʱ��
	Ev_H239_TokenReqTimer,                   ///<323ģ�飬 h239����token��ʱ��
	Ev_H239_TokenOwerIndcateTimer,           ///<323ģ�飬 h239ower��ʱ��
	Ev_H225_KeepAliveTimer,                  ///<323ģ�飬 ����460�б���225���� 
	Ev_H245_KeepAliveTimer,                  ///<323ģ�飬 ����460�б���245����
	Ev_H323_AskVcsPermitTimer,               ///<323ģ�飬 ����ǿ�𣬷���askVcsReq�󣬳�ʱû�յ�rsp

	Ev_Misc_BandwidthTestTimer,      ///< �����ⳬʱ
	Ev_Misc_BandwidthTestRetryTimer, ///< ���������Զ�ʱ��

	Ev_Upgrade_CheckUpgradeTimer,    //����ʱ�����µĶ�ʱ��

	Ev_Mtpa_ConfEstablish_Timer,      /*mtpa�� ���н�����ʱû���յ�connect,��disconnect,
	                                  pa���װ��Э�飬 ����conf�� mc����Ҫ��ʱ����conf, 
									  mcֻ��Ҫ��עcallconnect, calldisconnect��Ϣ*/
	Ev_Mtpa_DisConnect_Timer,         //mtpa�� �ҶϺ���ȥ��ʱû�յ�disconnect

	Ev_OspTimer_GetAllTerminalTimer,    //<����sip ����323ģ��,  ��ȡ�ն��б� ƽ̨�ְ��� ��ʱ��Ϊ����
	Ev_OspTimer_BookConfListOverTimer, 
	Ev_OspTimer_TempConfListOverTimer,
	Ev_OspTimer_HoldConfListOverTimer,
// 	Ev_OspTimer_JoinConfTimer,       ///< �Ǳ�μӻ��鶨ʱ��
// 	Ev_OspTimer_CreateConfTimer,     ///< �Ǳ괴�����鶨ʱ��

	Ev_Dns_Query_Timer,
	Ev_Mc_PollBroadcast_Timer,       //mc��ѯ�㲥��ʱ��
	Ev_Mc_PollApplyInfo_Timer,       //mc��ѯ������Ϣ
	Ev_Cfg_Persist_Timer,            //���ó־û���ʱ��

	Ev_Conf_FeccTiltUpTimer,         ///< fecc��ʱ�����յ�Զҡstart�󣬳�ʱû���յ�stop���������ʱ����
	Ev_Conf_FeccTiltDownTimer,
	Ev_Conf_FeccPanLeftTimer,
	Ev_Conf_FeccPanRightTimer,
	Ev_Conf_FeccFocusInTimer,
	Ev_Conf_FeccFocusOutTimer,
	Ev_Conf_FeccZoomInTimer,
	Ev_Conf_FeccZoomOutTimer,
	Ev_Conf_FeccBrightUpTimer,
	Ev_Conf_FeccBrightDownTimer, 
	Ev_Conf_PollTimer,               ///< conf����ѯ��ʱ��,��ʱ��ѯ��һ���ն�
	Ev_Conf_AutoCallTimer,           ///< �Զ����ж�ʱ������ʱ����  
	Ev_Conf_TerInfoRecOverTimer,     ///< terinfo��Ϣ���ְ��������������ʱû�յ�end,����Ϊ��ֹ
	

	/*mtmpģ�鶨ʱ����Ϣ���忪ʼ*/
	Ev_MP_1stDecStatis_Timer,        ///< ��һ������������ͳ�ƶ�ʱ��
	Ev_MP_2ndDecStatis_Timer,        ///< �ڶ�������������ͳ�ƶ�ʱ��
	Ev_MP_1stAskKeyFrame_Timer,        ///< ��hd900��ͨʱ��Զ�����ؼ�֡��ʱ��
	Ev_MP_CodecStatis_Timer,        ///< д�����ͳ�Ƶ����ݹ���ʱ��
	Ev_MP_FxoCheckState_Timer,        ///< fxo״̬��鶨ʱ��
    Ev_MP_FxoAutoReject_Timer,        ///< fxo��ʱ�Զ��Ҷ϶�ʱ��
	Ev_MP_SleepProtection_Timer,        ///< ����������ʱ��
	/*mtmpģ�鶨ʱ����Ϣ�������*/

    Ev_NET_CheckEthState_Timer,             ///< ���ڼ�ⶨʱ��
    Ev_NET_GetEthStateTimeout_Timer,            ///< ��������ѯ����״̬��ʱ��ʱ��
    Ev_Gk_Register_Again_Timer,
    Ev_Aps_Relogin_Timer,
    Ev_Gk_Relogin_Timer,                    ///< ����ģ��ʹ�õ����µ�¼GK��ʱ��
	Ev_Rest_Timer_PollCometdMessage, 		///< ��ѯƽ̨���͵Ļ���֪ͨ
	Ev_Rest_Timer_RetryLogin,               ///< ��¼ʧ�ܻ����ӶϿ�ʱ�����øö�ʱ��
	Ev_Conf_PrimoVideoOff_Timer,            ///< �����ص���2s���ٻص���UI
	Ev_Rest_Timer_RetryGetToken,            ///< ��ȡ�˻�tokenʧ��ʱ�����øö�ʱ��
	Ev_Conf_GetBweStatus_Timer,             ///< ��ʱ��ȡ������״̬ 5s
	Ev_Conf_GKUnReachble_Timer,             ///< ���gkע��ʧ��ԭ���� unreachble, ��3s��ע��
	Ev_Conf_SipUnReachble_Timer,            ///< ���sipע��ʧ��ԭ���� unreachble, ��3s��ע��
	Ev_Conf_ApplyChairTimer,                ///< UI������ϯ ��ʱ��
	Ev_Conf_ApplySpeakerTimer,              ///< UI���뷢���� ��ʱ��
	Ev_Conf_WaitForMccStartTimer,           ///< ��ʱ���û���յ�mccstart,����Ϊ�ǵ�Ե�״̬
	Ev_Conf_ApplyChiemeInTimer,             ///< UI����廰 ��ʱ��
    Ev_NET_CheckE1BandWidth_Timer,          ///< ���E1����ʱ��
    Ev_NET_Get_E1_Route_Timer,              ///< ��ȡE1·��
	Ev_Conf_LoginNextAps_Timer,             ///< ��ʱ��½��һ��aps(GK����ʹ��)
	Ev_H323_WaitLRRQRspTimer,               ///< �ȴ�RRQ�Ļظ� ��ʱֱ���ϱ�unreachable
	Ev_Vrs_KeepAliveTimer,                  ///< vodģ����vrs�������ı���
	Ev_Vrs_ReLoginVrsTimer,                 ///< �����쳣�����µ�¼
	Ev_LoginAps_Timer,						///< ��½aps(����http��Ϣ̫�ർ��ƽ̨����)
	Ev_Rest_LoginMoPlatform_Timer,			//��½΢����������ʱ��
	Ev_H323_WaitPeerAgentInfoTimer,			///< �ȴ��Զ˷���������Ʒ�ķǱ�����
	Ev_Sec_WaitStrongAut_Timer,				///< �ȴ�ƽ̨����������Ʒ�ķǱ�����
	Ev_Sec_WaitAuthCall_Timer,				///< �ȴ�ƽ̨����������Ʒ�ķǱ�����
	Ev_LoginAps_WaitCloseSockets_Timer,	 //��½apsǰ�ȴ��ر��²�����
	Ev_Dcs_Timer_RetryLoginConnect,         ///< ���Ӱװ����½���ע����·�����øö�ʱ��
	Ev_Dcs_Timer_RetryLoginSrv,             ///< ���Ӱװ�����ע������������øö�ʱ��
	Ev_Dcs_Timer_KeepSrvAlive, 				///< ���ֺ͵��Ӱװ�ƽ̨������
	Ev_Dcs_Timer_JoinConf_OverTime,			///< ���Ӱװ������鳬ʱ
	Ev_Dcs_Timer_GetConfAddr_OverTime,		///< ���Ӱװ��ȡ�����ַ��ʱ
//	Ev_Dcs_Timer_CloseConfSession,				///< ���Ӱװ��˳�/�뿪���鳬ʱ��Ҫ�ر���·�Ķ�ʱ��

    Ev_Im_Timer_RetryLoginIm,		        ///< ���ն˵ǳ��˻������µ�½ʱ���handleû���ͷţ���ôѭ���ȴ�һ��
	Ev_Dcs_Timer_RetryDownloadCacheElement,				///< �������ػ���ͼԪ���ݵĶ�ʱ��

    Ev_REST_Timer_CreateConference_OverTime,  ///<API���ᳬʱ
	Ev_LoginAps_WaitCloseOtherServer_Timer,   // �ر�����������
    Ev_LoginAps_TryIfNetConnect_Timer,	      //��½aps̽�������Ƿ�ָ�

	Ev_DynamicPwd_Timer,                      //��̬���ʱ��
	Ev_Mtpa_TlsRenegotiate_Timer,             //����Э��tls��Կ�Ķ�ʱ��
	Ev_BsHandShake_Timer,                     //sdk����handshake��Ϣ��5sδ�ظ�����Ϊ����access���նˣ� �ظ���Ϊ��newaccess���ն�
    Ev_SendIrrFrequecy_Timer,                 ///323 ����irr��ʱ��
	Ev_SipRegTimer,                           ///sip ע�ᳬʱ��ʱ��
	Ev_AiWakeupTimer,                         ///����֮����û������½��뻽��
	Ev_AiFilterAsrTimer,
	Ev_Conf_ChairRecvTerApplyChairTimer,	  ///�ն�������ϯ��ʱ�������������ϯ��sdk�㻺��
	Ev_Conf_ChairRecvTerApplySpeakTimer,      ///�ն������Ϊ�����ˣ����������ϯ��sdk�㻺��
	Ev_Conf_ChairRecvTerApplyChiemeInTimer,	  ///�ն�����廰�����������ϯ��sdk�㻺��
};

#endif