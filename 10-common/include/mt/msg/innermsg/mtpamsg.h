#ifndef _MTPAMSG_H_
#define _MTPAMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMtpaMsg
{

	//������ϵͳ�õ������е���Ϣ������� ������Ҫ���֣�mtconfģ�飬 mth323�õ��ģ� ����mc�õ�����Ϣ��
	EV_BGN(MTPA) = EVSEG_MTPA_BGN,
#endif
	
	/*
    mtconf ------------------------------->mtpa--------------------------->mth323/mtsip/mtsat
		1.    Ev_Mtpa_XXXX_Cmd                    1.    Ev_Mtpa_XXXX_Cmd
    mtconf <------------------------------ mtpa<---------------------------mth323/mtsip/mtsat
        2.     Ev_Mtpa_XXXX_Ntf                   2.    Ev_Mtpa_XXXX_Ntf
	*/
	
	
	/*1. Ev_Mtpa_XXX_Cmd */

	/*<<��ʼ���У���Ҫ������������ȥ>>
	* call_handler �����о��
	* make_call_param ��   ���в���
	* mt_repeated_cap;     ��������������ݳ�����
	*/
	MESSAGE(Ev_Mtpa_MakeCall_Cmd)
	BODY(mt::TMtCallParam, make_call_param)
	BODY(mt::TRpMtCap,     mt_repeated_cap)

	/*<<���ܺ���>>
	* call_handler ��   ���о��
	* make_call_param �����в���
	* mt_cap :          ������
	*/
	MESSAGE(Ev_Mtpa_AcceptCall_Cmd)
	BODY(mt::TMtCallParam, make_call_param )
	BODY(mt::TRpMtCap,     mt_repeated_cap )

	/*<<�ҶϺ���>>
	* call_handler�����о��
	* hangup_reason���Ҷ�ԭ��
	*/
	MESSAGE(Ev_Mtpa_Hangup_Cmd)
	BODY(mt::TU32, hangup_reason)   //EmMtCallDisReason

	/*<<��ʼ˫��>>
	* tVidLab �� ˫����lab,��Ҫ�Ǳ�ʶ�� pc����, ����video����
	  ������Ϊ������Ϣ�Ǳ�׼�ģ�����ֻ��һ·˫�������ں�����sip ��·˫�����ṩ������Ϣ
	*/
	MESSAGE(Ev_Mtpa_OpenAssStream_Cmd)
	BODY(mt::TU32,			tVidLab )        //EmMtVidLabel

	
	/*<<����˫��>>
	* bActive �� �Ƿ񼤻�
	*/
	MESSAGE( Ev_Mtpa_ChanActive_Cmd )
	BODY(mt::TMtConfHandle, chan_handler)    //ͨ�����
	BODY(mt::TBOOL32,       bActive )        //�Ƿ񼤻�


	/*<< �ر�ͨ����� >>
	* chan_handler : ͨ�����
	*/
	MESSAGE(Ev_Mtpa_CloseStream_Cmd)
	BODY(mt::TMtConfHandle,    chan_handler)         //��ͨ�����

	/*<<�յ�����>>
	* callparam :    ���в���
	*/
	MESSAGE(Ev_Mtpa_CallIncoming_Ntf)
	BODY(mt::TMtCallParam, callparam)

	/*<< 245connected ��Ϣ��������mc >>
	*/
	MESSAGE(Ev_Mtpa_h245Connected_Ntf)


	/*<<�յ�����>>
	* ��ʱ����pa�ڲ������Լ����� sip˫��������Ϣ
	*/
	MESSAGE( Ev_Mtpa_DualIncoming_Ntf )

	/*<<���н���>>
	* chan_handler : ���о��
	* callparam ��  ���в���
	*/
	MESSAGE(Ev_Mtpa_CallConnected_Ntf )
	BODY(mt::TMtCallParam, callparam)

	/*<<���йҶ�>>
	* discon_reason �� �Ҷ�ԭ��
	*/
	MESSAGE(Ev_Mtpa_CallDisconnected_Ntf)
	BODY(mt::TU32, discon_reason)           // EmMtCallDisReason


	/*<<���д����Ϣ>>
	* chan_handler  :  ���о��
	* discon_reason �� �Ҷ�ԭ��
	*/
	MESSAGE( Ev_Mtpa_CallMissed_Ntf)   //��idle״̬���յ�����������Ϣmtpa��Ҷ�������У� ͬʱ�ϱ�����
	BODY(mt::TMtCallParam, callparam )

	/*<<ͨ������>>
	* chan_handler  :  ͨ�����
	* chan_addr  ��    ͨ����ַ
	* chan_param :     ͨ������
	*/
	MESSAGE(Ev_Mtpa_ChanConnected_Ntf)    ////����� feccͨ���� ����Ҫ����������
	BODY(mt::TMtConfHandle, chan_handler)    
	BODY(mt::TMtChanAddr, chan_addr)
	BODY(mt::TMtAVChanParam, chan_param)

	/*<<ͨ���ϵ�>>
	* chan_handler     :  ͨ�����
	* chan_dis_reason  �� ͨ���Ҷ�ԭ��
	*/
	MESSAGE(Ev_Mtpa_ChanDisConnected_Ntf)
	BODY(mt::TMtConfHandle, chan_handler)
	//BODY(mt::TU32, chan_dis_reason)           // EmMtChanDisReason,������չ��

	/*<<ͨ��active���active��Ϣ>>
	* chan_handler     :    ͨ�����
	* active_or_inactive  ��ͨ��״̬
	*/
	MESSAGE(Ev_Mtpa_ChanRecvState_Ntf)
	BODY(mt::TMtConfHandle, chan_handler )
	BODY(mt::TBOOL32, active_or_inactive)
	
	/*<<����ؼ�֡>>
	* chan_handler     :    ͨ�����
	*/
	MESSAGE(Ev_Mtpa_IFrame_Request_Cmd)
	BODY(mt::TMtConfHandle, chan_handler )

	/*<<�Զ�����ؼ�֡>>
	* chan_handler     :    ͨ�����
	*/
	MESSAGE(Ev_Mtpa_IFrame_Request_Ntf)
	BODY(mt::TMtConfHandle, chan_handler )


	/*<<�Զ˵�������>>
	* chan_handler     :    ͨ�����
	* chan_bitrate      ��  bitrate
	*/
	MESSAGE(Ev_Mtpa_FlowControl_Ntf)
	BODY(mt::TMtConfHandle, chan_handler )
	BODY(mt::TU16,          chan_bitrate )

	/*<<�����Զ�����>>
	* chan_handler     :    ͨ�����
	* chan_bitrate     ��   birate
	*/
	MESSAGE(Ev_Mtpa_FlowControl_Cmd)
	BODY(mt::TMtConfHandle, chan_handler )
	BODY(mt::TU16,          chan_bitrate )

	/*<<��֪�Զ˱�����������>>
	* chan_handler     :    ͨ�����
	* chan_bitrate     ��   birate
	*/
	MESSAGE(Ev_Mtpa_FlowControlIndition_Cmd)
	BODY(mt::TMtConfHandle, chan_handler )
	BODY(mt::TU16,          chan_bitrate )


	MESSAGE( Ev_Mtpa_UpLoadBitrateLessThan64_Ntf )
	MESSAGE( Ev_Mtpa_DownLoadBitrateLessThan64_Ntf )


	/*�����ı�, ����˫����ѡ������mc
	* tMtCap   : �ı�����������ʱֻ���ĸı���˫������
	*/
	MESSAGE( Ev_Mtpa_ChangeCap_Cmd )
	BODY(mt::TRpMtCap,    tMtCap )



	//ע����أ���Ϣһ��
	MESSAGE(Ev_Mtpa_RegistReq_Cmd)
	BODY(mt::TU32,       conf_protocol)   //EmConfProtocol
	BODY(mt::TMtRegistReq,  regist_req)

	MESSAGE(Ev_Mtpa_AuthResult_Ntf)       //��Ȩ���
	BODY(mt::TBOOL32,     bauthsuc)       //�Ƿ���Ȩ

	MESSAGE(Ev_Mtpa_RegResult_Ntf)       //ע����
	BODY(mt::TU32,  conf_protocol) 
	BODY(mt::TBOOL32,     bregsuc)       //ע���Ƿ�ɹ�, ʧ�ܵĻ�����ʧ��ԭ��
	BODY(mt::TU32,        bReason)       //EmRegFailedReason


	MESSAGE( Ev_Mtpa_UnRegistReq_Cmd )     //ȡ��ע��
	BODY(mt::TU32, conf_protocol)

	MESSAGE(Ev_Mtpa_UnRegResult_Ntf)       //ȡ��ע����
	BODY(mt::TU32,     conf_protocol) 
	BODY(mt::TBOOL32,  bunRegsuc)          //ȡ��ע���Ƿ�ɹ�
	BODY(mt::TU32,     unRegFailedReason)  //ȡ��ʧ��ԭ��


	///ע��Ǳ����Ӧ������Ev_Mtpa_RasMessBegin ��Ev_Mtpa_RasMessEnd֮��
	///
	MESSAGE(Ev_Mtpa_RasMess_Bgn)

	MESSAGE(Ev_Mtpa_RasJoinConf_Req)
	BODY( mt::TMtJoinConfParam, joinconf_param )

	////���������Ӧ
	/*
	* errcode     :    ������
	* conf_e164   ��   �����e164����
	*/
	MESSAGE(Ev_Mtpa_JoinConfResult_Rsp)
	BODY( mt::TU32, errcode)
	BODY( mt::TString, conf_e164 )

	MESSAGE( Ev_Mtpa_RasClearJoinConf_Cmd )

	MESSAGE( Ev_Mtpa_RasCreateConf_Req )      //������������
    BODY( mt::TMtCallParam, call_param)


	////�ټ�������Ӧ
	/*
	* errcode     :    ������
	* conf_e164   ��   �����e164����
	*/
	MESSAGE(Ev_Mtpa_CreateConfResult_Rsp)     //����������
	BODY( mt::TU32, errcode)
	BODY( mt::TString, conf_e164 )

	MESSAGE( Ev_Mtpa_RasClearCreateConf_Cmd)

	MESSAGE( Ev_Mtpa_GetConfList_Req )
	BODY(mt::TU32,    conf_req_type)        //EmConfListType, book, idle, hold,

	MESSAGE(Ev_Mtpa_ConfList_Rsp)
	BODY(mt::TU32,  conf_req_type)          //EmConfListType
	BODY(mt::TU32,  conf_req_error)         //EmConfListRspErr
	BODY(mt::TRpMtConfNameInfo, confList)   //�����

	MESSAGE(Ev_Mtpa_GetConfDetailInfo_Req)
	BODY(mt::TString,     conf_e164)                //����e164��

	MESSAGE(Ev_Mtpa_GetConfDetailInfo_Rsp)

	//��ȡ����������
	MESSAGE(Ev_Mtpa_GetRoomNum_Req)
	
	MESSAGE(Ev_Mtpa_RoomNum_Rsp)
	BODY(mt::TU32,       total_num)            //������
	BODY(mt::TU32,       useConfNum)           //��������

	////����gk����Ա�б����ڼ���
	MESSAGE( Ev_Mtpa_GetGkRegMtList_Req )
	///gk�ظ�
	MESSAGE( Ev_Mtpa_GetGkRegMtList_Rsp )
	BODY(mt::TRpMtInfo,       mt_info)             //�ն˱�����Ϣ
	BODY(mt::TBOOL32,         bfinished)           //�Ƿ����

	MESSAGE( Ev_Mtpa_RasMess_End ) 



	//////�����ǻ����Ϣ

	/*<<��ʼ��������ʾ mc<->mt >>
	*/
	MESSAGE( Ev_Mtpa_MccStart_Ntf )

	/*<<�ն��뿪 >>
	* tMtid  :      �ն˱��
	*/
	MESSAGE( Ev_Mtpa_TerLeft_Ntf)
	BODY( mt::TMtId, tMtid )

	/*<<�ն˼��� >>
	* tMtid  :      �ն˱��
	*/
	MESSAGE( Ev_Mtpa_TerJoin_Ntf)
	BODY( mt::TMtId, tMtid )

	/*<<MC�����ն˱�� >>
	* tMtid  :      �ն˱��
	*/
	MESSAGE( Ev_Mtpa_AssignTerId_Ntf)
	BODY( mt::TMtId, tMtid )

	/*<<�����ն��б� >>
	*/
	MESSAGE( Ev_Mtpa_TerList_Req )
	
	/*<< mc�ظ��ն��б� >>
	* tRpMtId: ���mtid�ն�
	*/
	MESSAGE( Ev_Mtpa_TerList_Rsp )
	BODY( mt::TRpMtId, tRpMtId )


	/*<<�����ն��б� >>
	*/
	MESSAGE( Ev_Mtpa_OffLineTerList_Req )
	
	/*<< mc�ظ��ն��б� >>
	* tRpMtId: ���mtid�ն�
	*/
	MESSAGE( Ev_Mtpa_OffLineTerList_Rsp )
	BODY( mt::TRpMtId, tRpMtId)


	/*<<�ظ��ն���Ϣ���Ǳ���Ϣ,��ӦЭ��ջ�� h_ctrl_RequestTerminalInfoResponce>>
	*/
	MESSAGE( Ev_Mtpa_GetTerminalInfo_Rsp )
	BODY(mt::TBOOL32,   bAll)
	BODY(mt::TU32,      tErrCode)      //EmGetListRspErr
	BODY(mt::TRpMtInfo, Rpmt_info)

    
	////Ev_Mtpa_GetTerminalInfo_ReqΪ�Ǳ���Ϣ
	/*<<����mc��������ն����� >>
	*/
	MESSAGE( Ev_Mtpa_GetTerminalInfo_Req )
	BODY(mt::TMtId,   tMtId)  ///


	////Ev_Mtpa_TerGetAllTerName_ReqΪ��׼��Ϣ ��׼����
	/*<<����mc��������ն����� >>
	*/
	MESSAGE( Ev_Mtpa_TerGetAllTerName_Req )

	/*<<mc�ظ� ����ն����� >>
	*Rpmt_info:  ����ն�����
	*/
	MESSAGE( Ev_Mtpa_TerGetAllTerName_Rsp)
	BODY(mt::TRpMtInfo, Rpmt_info)




	/*<<mc����ǰ�ն����� >>
	*/
	MESSAGE( Ev_Mtpa_McGetTerName_Req)

	/*<<�ն˻�Ӧ ��ǰ�ն����� >>
	* tMtInfo: �ն�����
	*/
	MESSAGE( Ev_Mtpa_McGetTerName_Rsp)
	BODY( mt::TMtInfo, tMtInfo)

	/*<<��ǰ�ն����������ն˵����� >>
	* tMtId:    �ն�id
	*/
	MESSAGE( Ev_Mtpa_TerGetOhterTerName_Req )
	BODY( mt::TMtId,  tMtId)
    
	/*<< mc��Ӧ >>
	* tMtId:    �ն�id
	*/
	MESSAGE( Ev_Mtpa_TerGetOhterTerName_Rsp )
	BODY( mt::TMtInfo,  tMtInfo)


	/*<< ǿ�ƹҶ�ĳ�ն� >>
	* tMtId:    �ն�id
	*/
	MESSAGE( Ev_Mtpa_DropTer_Cmd )
	BODY( mt::TMtId, tMtId)

	/*<< ǿ�ƹҶ�ĳ�ն�ʧ�� >>
	*/
	MESSAGE( Ev_Mtpa_DropTerRej_Ntf )

	/*<< ��ϯ�Ҷϻ��� >>
	*/
	MESSAGE( Ev_Mtpa_EndConf_Cmd )

	/*<< mc�����ն��������� >>
	*/
	MESSAGE( Ev_Mtpa_McGetTerPwd_Req )

	/*<< �ն���Ӧ�������� >>
	*/
	MESSAGE( Ev_Mtpa_McGetTerPwd_Rsp )
	BODY( mt::TMtId,   tMtid)
	BODY( mt::TBytes,  tPassword)


	/*<< �ն����뷢�� mt<->mc >>
	*/
	MESSAGE(Ev_Mtpa_ApplyMcSpeak_Req )

	/*<< �ն����뷢�� mc->chair >>
	* mcת��chair
	*/
	MESSAGE(Ev_Mtpa_TerApplySpeak_Ntf )
	BODY( mt::TMtId,   tMtid)

	/*<< ��ϯ����ָ������ chair->mc>>
	*/
	MESSAGE(Ev_Mtpa_Broadcast_Req )
	BODY( mt::TMtId,   tMtid)

	/*<< mc�ظ��Ƿ�ͬ����ϯָ������ chair<->mc>>
	*/
	MESSAGE(Ev_Mtpa_Broadcast_Rsp )
	BODY( mt::TBOOL32, bGranted)

	/*<< ��ϯͬ�ⷢ��chair<->mc>>
	*/
	MESSAGE(Ev_Mtpa_Broadcast_Cmd )
	BODY( mt::TMtId,   tMtid)

	/*<< ��ϯȡ������chair<->mc>>
	*/
	MESSAGE(Ev_Mtpa_CancelBroadcast_Cmd )
	BODY( mt::TMtId,   tMtid)


	/*<< ���㲥֪ͨ mt<-mc>>
	*/
	MESSAGE( Ev_Mtpa_SeenByAll_Ntf )

	/*<< ȡ�����㲥֪ͨ mt<->mc>>
	*/
	MESSAGE( Ev_Mtpa_CancelSeenByAll_Ntf )

	/*<< ������λ��֪ͨ mt<->mc>>
	*/
	MESSAGE( Ev_Mtpa_Speaker_Ntf ) /////�Ǳ��
	BODY( mt::TMtId,   tMtid)

	/*<< ���ڹۿ�����ƵԴ֪ͨ mt<->mc>>
	tMtid:  ��ƵԴ��mt_id
	*/
	MESSAGE( Ev_Mtpa_YouAreSeeing_Ntf ) /////�Ǳ��
	BODY(mt::TMtId,     tMtId )
	BODY(mt::TU32,      tChanId ) ////sip�����Ƕ����ģ� ÿһ������������ͨ��id��1��ʼ
   
	/*<<�ն�������ϯ ter->mc >>
	*/
	MESSAGE( Ev_Mtpa_MakeMeChair_Req )
	
	/*<<mc�ظ��ն�������ϯ�Ƿ�ɹ� mc->ter  >>
	*/
	MESSAGE( Ev_Mtpa_MakeMeChair_Rsp )
	BODY(mt::TBOOL32,  bGranted)

	/*<<�ն˳�����ϯ���� chiar->mc >>
	*/
	MESSAGE( Ev_Mtpa_WithdrawChair_Cmd )

	/*<<mc������ϯ����ָʾ mc->chair >>
	*/
	MESSAGE( Ev_Mtpa_WithdrawChair_Ntf )
	

	/*<<�ն˲�ѯ��ϯλ�� ter->mc >>
	*/
	MESSAGE( Ev_Mtpa_WhoIsChair_Req )

	/*<<mc�ظ���ϯλ�� mc->ter >>
	* chair_mtid     :    ��ϯλ��
	*/
	MESSAGE( Ev_Mtpa_ChairPos_Rsp )    ///��ϯλ�øı䣬 Ӧ��mc����������Ϣ
	BODY(mt::TMtId,   chair_mtid)


	/*<<��ϯ����ת�ƣ�ָ����ϯ chair->mc  >>  //����Ҳ�����ظ����Ƿ�ͬ�������ն�������ϯ
	* chair_mtid     :    ��ϯλ��
	*/
	MESSAGE( Ev_Mtpa_ChairTransfer_Req )
	BODY(mt::TMtId,   chair_mtid)
	
	/*<<���ն�������ϯ  mc->chair >>
	* mtid     :    mtid
	*/
	MESSAGE( Ev_Mtpa_ChairApply_Ntf )
	BODY(mt::TMtId,   mtid)

	/*<<��ϯѡ���ն� >>
	*/
	MESSAGE( Ev_Mtpa_SendThisTer_Cmd )
	BODY(mt::TMtId,  tMtid)
	BODY(mt::TU32,   tMediaType) //EmMediaType 

	/*<<��ϯѡ���ն˽�� >>
	*/
	MESSAGE( Ev_Mtpa_SendThisTer_Rsp )
	BODY(mt::TBOOL32,  bResult)



	/*<<��ϯȡ��ѡ���ն� >>
	*/
	MESSAGE( Ev_Mtpa_CancelSendThisTer_Cmd )

	/*<<��ѡ��֪ͨ >>
	*/
	MESSAGE( Ev_Mtpa_SeenByOther_Ntf )
	

	/*<<ȡ����ѡ��֪ͨ >>
	*/
	MESSAGE( Ev_Mtpa_CancelSeenByOther_Ntf )





	///////////////////////////////////////////�Ǳ���Ϣ

	
	/*<<�ն�����廰 mt->mc >>
	*/
	MESSAGE( Ev_Mtpa_ApplyChiemeIn_Cmd )


	/*<<���ն�����廰 mc->chair >>
	*/
	MESSAGE( Ev_Mtpa_ApplyChimeIn_Ntf )
	

	/*<<��ϯָ����ͬ��廰 chair->mt >>
	*/
	MESSAGE( Ev_Mtpa_ChiemeIn_Cmd )
	BODY(mt::TMtId,           mtid)

	/*<<�ն˲廰״̬ chair->mt >>
	*/
	MESSAGE( Ev_Mtpa_ChimeInState_Ntf )
	BODY(mt::TBOOL32,       bResult)

	/*<<�ն˲廰ʧ�� chair->mt >>
	*/
	MESSAGE( Ev_Mtpa_ChimeFailed_Ntf )
	



	

	/*<<MC�����ն�״̬ >>
	*/
	MESSAGE( Ev_Mtpa_McGetTerStatus_Req )

	/*<< �ն�״̬Ӧ�� >>
	* Mt_status     :    �ն�״̬
	*/
	MESSAGE( Ev_Mtpa_McGetTerStatus_Rsp)
	BODY(mt::TTerStatus,       Mt_status)             

	/*<< �ն�״̬Ӧ�� >>  ��������mc�����ߵ�Ե�
	* Mt_status     :   �ն�״̬
	*/
	MESSAGE( Ev_Mtpa_McTerStatus_Rsp)
	BODY(mt::TTerStatus,   Mt_status)             



	/*<<�ն����������ն�״̬ >>
	*/
	MESSAGE( Ev_Mtpa_TerGetTerStatus_Req )
	BODY(mt::TMtId,                 mtid)

	/*<<mc�ظ���ϯ���������ն�״̬ >>
	*/
	MESSAGE( Ev_Mtpa_TerGetTerStatus_Rsp )
	BODY(mt::TMtId,                 mtid)
	BODY(mt::TTerStatus,      ter_status)



	/*<<MC�����ն���ƵԴӦ�� >>
	* Mt_Video_alias     :    �ն���ƵԴ����
	*/
	MESSAGE( Ev_Mtpa_VideoAlias_Rsp )
	BODY(mt::TRpMtVideoAlias,  video_info)

	/*<<MC�����ն���ƵԴ >>
	*/
	MESSAGE( Ev_Mtpa_VideoAlias_Req )


		/*<<MC�����ն���ƵԴӦ�� >>
	* Mt_Video_alias     :    �ն���ƵԴ����
	*/
	MESSAGE( Ev_Mtpa_TerGetTerAlias_Req )
	BODY(mt::TRpMtVideoAlias,  video_info)

	/*<<MC�����ն���ƵԴ >>
	*/
	MESSAGE( Ev_Mtpa_TerGetTerAlias_Rsp )



	/*<<�Զ���ƵԴָʾ >>
	* peer_info     :    �Զ��ն���ƵԴ����
	*/
	MESSAGE(Ev_Mtpa_PeerVideoAlias_Ntf)
	BODY(mt::TRpMtVideoAlias, peer_info)

	/*<<�Զ���ƵԴָʾ >>
	* tVideo_Src:    �Զ��ն���ƵԴ����
	*/
	MESSAGE( Ev_Mtpa_PeerVideoSrc_Ntf )
	BODY(TRpVideoInfo, tRpVideoInfo)
	

	/*<<���Ͷ���Ϣ >>
	* short_mess     :    ����Ϣ
	*/
	MESSAGE( Ev_Mtpa_SMS_Cmd )
	BODY(mt::TShortMsg,  short_msg)

	/*<<����Ϣ��ʾ >>
	* short_mess     :    ����Ϣ
	*/
	MESSAGE( Ev_Mtpa_SMS_Ntf )
	BODY(mt::TShortMsg,  short_msg)

	
	/*<<��ϯ�����ն� >>
	* tMtaddr     :    �ն˵�ַ
	*/
	MESSAGE( Ev_Mtpa_ChairInviteTer_Req )   //û�лظ�
	BODY(mt::TMtAddr,    tMtaddr)

	/*<<��ϯ�����ն�ʧ�� >>
	* tMtaddr     :    �ն˵�ַ
	*/
	MESSAGE( Ev_Mtpa_ChairInviteFailed_Ntf )   //û�лظ�
	BODY(mt::TMtAddr,    tMtaddr)
	BODY(mt::TU32,       tReason) //EmMtCallDisReason

	/*<< ���鷢������ >>
	*/
	MESSAGE( Ev_Mtpa_ConfFailed_Ntf )
	BODY(mt::TU32,      emFailedReason)  //EmMtConfFailureReason

	/*<< ��ϯ���������ն� >>
	*/
	MESSAGE( Ev_Mtpa_CallOfflineTer_Cmd )
	BODY( mt::TMtId,   mtid)



	/*<<��ȡ������Ϣ���� >>
	*/
	MESSAGE( Ev_Mtpa_GetConfInfo_Req )
    
	/*<<��ȡ������Ϣ�ظ� >>
	*/
	MESSAGE(Ev_Mtpa_GetConfInfo_Rsp)
	BODY(mt::TMtConfInfo,  conf_info)
	
	/*<<�򵥻�����Ϣ֪ͨ >>
	*/
	MESSAGE(Ev_Mtpa_SimpleConfInfo_Ntf)
	BODY(mt::TMtSimpConfInfo,  simple_conf_info)

	/*<<���鼴��������ʾ >>
	*/
	MESSAGE(Ev_Mtpa_ConfWillEnd_Ntf)
	BODY(mt::TU32,      tRemain_minutes)
	
	/*<<�����ӳ�ʱ������ >>
	*/
	MESSAGE(Ev_Mtpa_ReqProlong_Req)
	BODY(mt::TU16,      tLongTime)

	/*<<�����ӳ�ʱ��Ӧ�� >>
	*/
	MESSAGE(Ev_Mtpa_ReqProlong_Rsp)
	BODY(mt::TBOOL32,      bGranted)

	/*<<�޸Ļ������� >>
	*/
	MESSAGE(Ev_Mtpa_ModifyConfName_Req)
	BODY(mt::TString,      tName)

	/*<<�޸Ļ������� >>
	*/
	MESSAGE(Ev_Mtpa_ModifyConfPwd_Req)
	BODY( mt::TBOOL32,     bUsed)
	BODY(mt::TBytes,      tPwd)

	/*<<�޸Ļ���˫��ģʽ >>
	*/
	MESSAGE(Ev_Mtpa_ModifyConfDualMode_Req)
	BODY( mt::TU32, emMtDualMode )

	/*<<�޸Ļ������ʱ�� >>
	*/
	MESSAGE(Ev_Mtpa_ModifyDuration_Req)
	BODY( mt::TU16, wTime )

	/*<<�޸Ļ����Ƿ�������� >>
	*/
	MESSAGE(Ev_Mtpa_SetConfDumb_Req)
	BODY( mt::TBOOL32, bDumb )

	/*<<�޸Ļ����Ƿ�������� >>
	*/
	MESSAGE(Ev_Mtpa_SetConfNoDisturb_Req)
	BODY( mt::TBOOL32, bEnable )


	/*<<�޸Ļ��黭��ϳ��Ƿ���ʾ��Ա���� >>
	*/
	MESSAGE( Ev_Mtpa_ModifyVmpShowAlias_Req )
	BODY( mt::TBOOL32, bShow )

	/*<<�޸Ļ������Իظ� >>
	*/
	MESSAGE(Ev_Mtpa_ModifyConf_Rsp)
	BODY( mt::EmMtModifyConfInfoType, emModifyType )
	BODY( mt::TBOOL32, bResult )



 	/*�Զ�����ָʾ*/
 	MESSAGE( Ev_Mtpa_PeerCapabilities_Ntf  ) ///��ʱ�����ˡ�

	/*mcuָ֪ͨʾ*/
	MESSAGE( Ev_Mtpa_McInfoTer_Ntf  )
	BODY(mt::TU32, tNtfType)//
	BODY(mt::TU16, tBitrate)

	/*mcu�����ֱ���*/
	MESSAGE( Ev_Mtpa_McAdjustRes_Ntf  )
	BODY(mt::TU32, chanltype) //EmMtLogChnnlType
	BODY(mt::TU32,        tW)
	BODY(mt::TU32,        tH)
	BODY(mt::TU32, tChanIndex)
	
	/*mcu����֡��*/ 
	MESSAGE( Ev_Mtpa_McAdjustFps_Ntf  )
	BODY(mt::TU32,        fps)


	///////////////////����ϳɺͻ�������Ϣ


	/*<< ��ʼ�������� >>
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_StartVAC_Req )

	/*<< ��ʼ��������Ӧ�� >>
	* bResult : ���
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_StartVACResult_Ntf )
	BODY(mt::TBOOL32, bResult)


	/*<< ֹͣ�������� >>
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_StopVAC_Req )

	/*<< ֹͣ����������� >>
	* bResult : ���
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_StopVACResult_Ntf )
	BODY(mt::TBOOL32, bResult)


	/*<< ��ʼ�������� >>
	* tparam : ��������
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_StartMix_Req )
	BODY(mt::TMtMixParam, tparam)

	/*<< ��ʼ����ģʽ��� >>
	* bResult : ���
	* mix_mode : ����ģʽ
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_StartMixResult_Ntf )
	BODY(mt::TBOOL32, bResult)
	BODY(mt::TU32,    mix_mode) //EmMtMixType


	/*<< ֹͣ����ģʽ���� >>
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_StopMix_Req )

	/*<< ֹͣ����ģʽ��� >>
	* bResult : ���
	* mix_mode : ����ģʽ
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_StopMixResult_Ntf )
	BODY( mt::TBOOL32, bResult )
	BODY(mt::TU32,    mix_mode) //EmMtMixType

	/*<< ��ӻ�����Ա >>
	* tmixparam:  ���������Ա
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_MakeTerChimeIn_Cmd )
	BODY(mt::TMtMixParam, tmixparam)

	/*<< ɾ��������Ա >>
	* mtid:  �ն�id
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_RemoveTerChimeIn_Cmd )
	BODY(mt::TMtId, mtid)




	/*<< ��ʼ�Զ��໭��ϳ����� >>
	* vmp_param: ����ϳɲ���
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_StartVMP_Req)
	BODY( mt::TMtVmpParam, vmp_param )

		/*<< ��ʼ�Զ��໭��ϳ����� >>
	* vmp_param: ����ϳɲ���
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_StartCustomVMP_Req)
	BODY( mt::TMtVmpParam, vmp_param )


	/*<< ��ʼ���黭��ϳ�Ӧ�� >>
	* bResult : ���    
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_StartVMPResult_Rsp)
	BODY( mt::TBOOL32,     bResult )

	/*<< ��ʼ��������ϳ�Ӧ�� >>
	* bResult : ���    
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_StartCustomVMPResult_Rsp )
	BODY( mt::TBOOL32,     bResult )


	/*<< ֹͣ�Զ��໭��ϳ����� >>
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_StopVMP_Req)
	
		/*<< ֹͣ�Զ��໭��ϳ����� >>
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_StopCustomVMP_Req)

	/*<< ֹͣ����ϳ�Ӧ�� >> 
	* bResult : ���
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_StopVMPResult_Rsp)
	BODY(mt::TBOOL32, bResult)

	/*<< ֹͣ��������ϳ�Ӧ�� >> 
	* bResult : ���
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_StopCustomVMPResult_Rsp)
	BODY(mt::TBOOL32, bResult)


	/*<< ���û���ϳɲ��� >>
	* vmp_param: ����ϳɲ���
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_SetVMPParam_Req )    //ֻ��Կƴ��ն�
	BODY( mt::TMtVmpParam, vmp_param)     

	/*<< ���û���ϳɲ��� >>
	* vmp_param: ����ϳɲ���
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_SetCustomVMPParam_Req )    //ֻ��Կƴ��ն�
	BODY( mt::TMtVmpParam, vmp_param)  

	/*<< ���û���ϳɲ���Ӧ�� >>
	* bResult : ���
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_SetVMPParamResult_Rsp)
	BODY( mt::TBOOL32,    bResult )

	/*<< ���û���ϳɲ���Ӧ�� >>
	* bResult : ���
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_SetCustomVMPParamResult_Rsp)
	BODY( mt::TBOOL32,    bResult ) 



	/*<< ��ʼ�Զ��໭��ϳ�Ӧ�� >>
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_StartVMPResult_Ntf)  ///mtpa�յ�sip���Ļ�أ��ڲ��õ�

	/*<< ��ʼ�Զ��໭��ϳ�Ӧ�� >>
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_StopVMPResult_Ntf)  ///mtpa�յ�sip���Ļ�أ��ڲ��õ�

	/*<< ��ʼ�Զ��໭��ϳ�Ӧ�� >>
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_SetVMPParamResult_Ntf)  ///mtpa�յ�sip���Ļ�أ��ڲ��õ�


	/*<< ��ʼ�Զ��໭��ϳ�Ӧ�� >>
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_StartCustomVMPResult_Ntf)  ///mtpa�յ�sip���Ļ�أ��ڲ��õ�

	/*<< ��ʼ�Զ��໭��ϳ�Ӧ�� >>
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_StopCustomVMPResult_Ntf)  ///mtpa�յ�sip���Ļ�أ��ڲ��õ�

	/*<< ��ʼ�Զ��໭��ϳ�Ӧ�� >>
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_SetCustomVMPParamResult_Ntf)  ///mtpa�յ�sip���Ļ�أ��ڲ��õ�



	/*<< ��ȡ����ϳɲ��� >>
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_GetVMPParam_Cmd )

	/*<< ��ȡ����ϳɲ�����Ӧ >>
	* vmp_param �� ����ϳɲ���
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_GetVMPParamResult_Ntf )
	BODY( mt::TMtVmpParam, vmp_param)


	/*<< ������Ա֪ͨ >>
	*/
	MESSAGE(Ev_Mtpa_DiscussParam_Ntf)
	
	/*<< Զ������ >>
	* tMtid:  �ն�id
	* bMute�� �Ƿ�����
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_MakeTerMute_Cmd )
	BODY(mt::TMtId,   tMtId)
	BODY(mt::TBOOL32, bMute)


	/*<< Զ������ָʾ >>
	* tMtid:  �ն�id
	* bEnable�� 
	* ��Ϣ���� �� mt<->mc mc�����ն������Ľ��
	*/
	MESSAGE( Ev_Mtpa_MakeTerMute_Ntf )
	BODY(mt::TMtId,   tMtId)
	BODY(mt::TBOOL32, bEnable)



	/*<< Զ�˾��� >>
	* tMtid:  �ն�id
	* bQuiet�� �Ƿ���
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_MakeTerQuiet_Cmd )
	BODY(mt::TMtId,   tMtId)
	BODY(mt::TBOOL32, bQuiet)

	/*<< Զ�˾���ָʾ >>
	* tMtid:  �ն�id
	* bEnable�� �Ƿ���
	* ��Ϣ���� �� mt<->mc  mc�����ն˾����Ľ�� 
	*/
	MESSAGE( Ev_Mtpa_MakeTerQuiet_Ntf )
	BODY(mt::TMtId,   tMtId)
	BODY(mt::TBOOL32, bEnable)


	/*<< �л�����ϳɷ�� >>
	* is_multipic: �Ƿ�໭��
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_SwitchBroadCastStyle_Cmd )
	BODY(mt::TBOOL32, is_multipic)

	/*<<��ϯǿ�ƹ㲥 >>
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_StartForceBroadcast_Cmd ) 
	
	/*<<��ϯȡ��ǿ�ƹ㲥 >>
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_StopForceBroadcast_Cmd )  


	/*<< �նˣ�������ϯMT��ѡ������ϳ����� >>
	* bStart:  TRUE ѡ������ϳɣ�FALSE ȡ��ѡ������ϳ�
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_SelectVmp_Req )
	BODY( mt::TBOOL32, bStart)

	/*<< �նˣ�������ϯMT��ѡ������ϳ����� >>
	* bStart:  TRUE ѡ������ϳɣ�FALSE ȡ��ѡ������ϳ�
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_SelectVmp_Rsp )
	BODY( mt::TBOOL32, bResult)


	/*
		Ev_Mtpa_FeccMsg_Ntf, Ev_Mtpa_FeccMsg_Cmd,  feccԶң����, fecc����Ϣ�� ֻ�Ƿ��͵�conf��������mc, 
		��conf ������mcģ���ڣ���ת��deviceģ�飬�õ��� device�������Ϣ
	*/

	/*<< Զҡ���� >>
	* feccStruct: fecc�ṹ��
	* tDstId:     Ŀ��id
	* tSrcId:     Դid
	* ��Ϣ���� ��mtpa==>dispatch==>mtmc/mtconf
	*/
	MESSAGE( Ev_Mtpa_FeccMsg_Ntf )
	BODY( mt::TMtFeccMsg,  feccStruct )
	BODY( mt::TMtId  ,     tDstId )
	BODY( mt::TMtId  ,     tSrcId )

	/*<< Զҡ���� >>
	* feccStruct: fecc�ṹ��
	* tDstId:     Ŀ��id
	* tSrcId:     Դid
	* ��Ϣ���� ��mtmc/mtconf==>dispatch==>mtpa
	*/
	MESSAGE( Ev_Mtpa_FeccMsg_Cmd )
	BODY( mt::TMtFeccMsg,  feccStruct )
	BODY( mt::TMtId  ,     tDstId )
	BODY( mt::TMtId  ,     tSrcId )




	////������ʱ������ mcs�ϻ��õ�
	/*<<�������� >>
	* tMtId�� mtid
	*/
	MESSAGE( Ev_Mtpa_RollCall_Cmd ) //��ʱ����
	BODY(mt::TMtId,   tMtId)

// 	/*<<���������� >>
// 	* tMtid:   mtid
// 	* bResult: �������
// 	*/
// 	MESSAGE( Ev_Mtpa_RollCallResult_Ntf )//��ʱ����
// 	BODY(mt::TMtId,   tMtId)
// 	BODY(mt::TBOOL32, bResult)
	
	/*<< �����ն�����������ʾͼƬ mc->mt >>
	* tMtid:   mtid
	* bResult: �������
	*/
	MESSAGE( Ev_Mtpa_VoiceSpeaker_Cmd )
	BODY(mt::TBOOL32,   is_voice_speaker)

	MESSAGE( Ev_Mtpa_SetStaticNet_Cmd ) ///��ʱ���õ�323Э��ջ
	MESSAGE( Ev_Mtpa_SetQos_Cmd )      //���õ�323Э��ջ
	
	MESSAGE( Ev_Mtpa_RemoteLoop_Cmd ) ///Զ���Ի� ��ʼ/ֹͣ
	BODY(mt::TBOOL32,   bStart)

	MESSAGE( Ev_Mtpa_RemoteLoop_Ntf) //Զ���Ի�״̬��ʾ
	BODY(mt::TBOOL32,   bStart)


	MESSAGE( Ev_Mtpa_ConfDelay_Ntf) ///�����ӳ���ʾ
	BODY(mt::TU16,    delay_time)

	////����ʣ��ʱ��
	MESSAGE( Ev_Mtpa_ConfRestTime_Ntf ) 
	BODY(mt::TU16,    rest_time)

	////ֻ��h323�ᷢ������ȥ�� �յ��Զ��ܼ����Ƿ�֧������Ƶͨ��
	MESSAGE( Ev_Mtpa_NotifyConfType_Ntf)
	BODY(mt::TU32,   emMtConfType)
	BODY(mt::TU16,   bitrate)

	MESSAGE( Ev_Mtpa_StackInitFailedReason_Ntf )
	BODY(mt::TU32,   emProtocol)
	BODY(mt::TU32,   emStackInitFailReason)

	MESSAGE( Ev_Mtpa_DualStreamSender_Ntf )
	BODY(mt::TMtId,   tMtid)
	BODY(mt::TBOOL32, tGrabbed)///�Ƿ����� 

	MESSAGE( Ev_Mtpa_StackOnOff_Cmd )  
	BODY(mt::TU32,    emProtocol) //Э��
	BODY(mt::TBOOL32, bStart) //start/stop

	MESSAGE( Ev_Mtpa_SetStack_Cmd )  
	BODY(mt::TU32,    emProtocol) //Э��
	BODY(mt::TBOOL32, bStand)     //start/stop

	/*<<��ϯָ��vip�б� chair->mc >>
	* mt_id :  ָ���ն˵��б�
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_Mtpa_ChairSpecVip_Req ) //�Ǳ�
	BODY(mt::TRpMtId, mt_id)


	/*<<mc��Ӧ��ϯָ��vip�б� chair<-mc >>
	* tResult :  �Ƿ�ͬ��
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_Mtpa_McRspChairVip_Rsp ) //�Ǳ�
	BODY(mt::TBOOL32, tResult)

	/*<<mc֪ͨ�ն˵�ǰvip�б� ter<-mc >>
	* mt_id :  ָ���ն˵��б�
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_Mtpa_McInfoTerVip_Ntf ) //�Ǳ�
	BODY(mt::TRpMtId, mt_id)

	/////�װ���鴴��֪ͨ
	MESSAGE( Ev_Mtpa_DataConfCreatedNtf_Cmd )
	BODY(mt::TString, conf_name) //�װ��������

	///����װ�������� ���ڵ�Ե�
	MESSAGE( Ev_Mtpa_JoinDataConf_Cmd )
	BODY(mt::TString, conf_name) //�װ��������

	///�յ��Զ˵ļ���װ�������� ����mcu, ���߶Զ�
	MESSAGE( Ev_Mtpa_JoinDataConf_Ntf )
	BODY(mt::TString, conf_name)  //�װ��������

	///mc�����ն˷�/�� ˫��
	MESSAGE( Ev_Mtpa_McReqTerSendAss_Cmd )
	BODY(mt::TBOOL32, tStart)  //��/��
	
	///��ʱ����sip ����֪ͨ�Զ� ��ǰ��ͨ������
	MESSAGE( Ev_Mtpa_NotifyPeerLocAlias_Cmd )
	BODY( mt::TRpMtLoc, tRpMtLoc )

	///ָ��ѡ��ĳ�ն�ĳͨ�� ���ڶ���
	MESSAGE( Ev_Mtpa_SelectViewChan_Cmd )
	BODY( mt::TMtId, tMtid )
	BODY( mt::TU32,  viewtype )
	BODY( mt::TU32,  viewchan )


	///ȡ��ѡ��ĳһ·ѡ��
	MESSAGE( Ev_Mtpa_CacelSelecttViewChan_Cmd )
	BODY( mt::TU32,  viewtype )
	BODY( mt::TU32,  viewchan )


	/*<<����Conf ����ͨ����ַ����>>   ��������mc
	*codec_type       ��ͨ�����ͱ�ʶ
	*encoder_id       ��ͨ��������ʶ
	*rtp_local_addr   ������rtp���ı��ص�ַ
	*rtcp_local_addr  �����ͽ���rtcp���ı��ص�ַ
	*rtp_remote_addr  ������rtp����Զ��Ŀ�ĵ�ַ
	*rtcp_remote_addr ������rtcp����Զ��Ŀ�ĵ�ַ
	*��Ϣ���� ��mtmc==>dispatch==>mtconf
	*/
    MESSAGE(Ev_Mtpa_ConfSetChanSndAddr_Cmd)
	BODY(mt::TS32, chan_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmMtChanType
	BODY(mt::TS32, chan_idx) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmBitStreamIndex
	BODY(mt::TNetAddr, rtp_local_addr)
	BODY(mt::TNetAddr, rtcp_local_addr)
	BODY(mt::TNetAddr, rtp_remote_addr)
	BODY(mt::TNetAddr, rtcp_remote_addr)	

	/*<<����Conf  ����ͨ����ַ����>>
	*codec_type       ��ͨ�����ͱ�ʶ
	*encoder_id       ��ͨ��������ʶ
	*rtp_local_addr   ������rtp���ı��ص�ַ
	*rtcp_local_addr  ������rtcp���ı��ص�ַ
	*rtp_remote_addr  �����ʹ򶯰���Զ�˵�ַ���˿�Ϊ0��ʾ�����ʹ򶯰��������ʹ򶯰�
	*rtcp_remote_addr ������rtcp����Զ��Ŀ�ĵ�ַ��Ҳ����������backrtcp��ַ
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_Mtpa_ConfSetChanRcvAddr_Cmd)
	BODY(mt::TS32, chan_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmMtChanType
	BODY(mt::TS32, chan_idx) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmBitStreamIndex	
	BODY(mt::TNetAddr, rtp_local_addr)
	BODY(mt::TNetAddr, rtcp_local_addr)
	BODY(mt::TNetAddr, rtp_remote_addr)
	BODY(mt::TNetAddr, rtcp_remote_addr)


	/*<<��ϯָ���ն˷�˫�� chair->mc >>
	* mt_id :  �ն˵�id
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_Mtpa_ChairSpecTerSendAss_Cmd )
	BODY(mt::TMtId, mt_id)


	/*<<�ն�����FeccStreamId >>
	* e164 :        �ն˵�e164��	
	* dwStreamid :  �Ǳ�streamid
	* bSnd :        �Ƿ��Ƿ���ͨ��
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_Mtpa_FeccStreamId_Cmd )
	BODY(mt::TMtConfHandle, tHander)
	BODY(mt::TString, e164 )
	BODY(mt::TU32,    dwStreamid)
	BODY(mt::TBOOL32,  bSnd)

	////����dtmf����
	MESSAGE(Ev_Mtpa_PasswordDtmf_Cmd)
	BODY(mt::TString, tPwd)

	///mc��������
	MESSAGE(Ev_Mtpa_McSetAudioVolume_Cmd)
	BODY(mt::TBOOL32, tVolout)
	BODY(mt::TU32,    tVolume)

	/////�Ǳ�fecc
	MESSAGE( Ev_Mtpa_NonStandFecc_Ntf)
	BODY(mt::TBytes, tBytes)

	/////�����ر�֪ͨ
	MESSAGE( Ev_Mtpa_PrimoVideoOff_Ntf)
	BODY(mt::TBytes, tBytes)


	/*<<MC�����ն˵Ķ����� >>
	*/
	MESSAGE( Ev_Mtpa_McReqLossRate_Cmd )

	/*<<MT�ظ�Mc�ն˶����� >>
	*/
	MESSAGE( Ev_Mtpa_MtRspMcLossRate_Ntf ) 
	BODY(mt::TMtTerLossRate,    tLoseRate) 

	/*<<�Զ˴���֪ͨ>>
	*/
	MESSAGE( Ev_Mtpa_PeerBandWidth_Ntf)
	BODY(mt::TU16, recv_bitrate)
	BODY(mt::TU16, send_bitrate)

	/*<<�ϱ� ���˴���>>
	*/
	MESSAGE( Ev_Mtpa_NotifyPeerBandWidth_Cmd)
	BODY(mt::TU16, recv_bitrate)
	BODY(mt::TU16, send_bitrate)

	////����ͨ����
	MESSAGE( Ev_Mtpa_SetNatTraversal_Cmd )
	BODY(mt::TMtConfHandle, tHander)

	///�ն�֧��Fec
	MESSAGE( Ev_Mtpa_TerSendFecToPeer_Cmd )
	BODY(mt::TBOOL32,  bSupport )

	///�ն�֧��Fec
	MESSAGE( Ev_Mtpa_PeerIsSupportFec_Ntf )
	BODY(mt::TBOOL32,  bSupport )


	///֪ͨ�ϲ㿪ͨ�����
	MESSAGE( Ev_Mtpa_ChanConnectedEnd_Ntf )	

	MESSAGE( Ev_Mtpa_SetH323Tos_Cmd )
	BODY(mt::TU8,  tTosValue )

	MESSAGE( Ev_Mtpa_SetFeccTos_Cmd )
	BODY(mt::TU8,  tTosValue )

	/*<<MC�����ն˵�ʵʱ��Ϣ >>
	*/
	MESSAGE( Ev_Mtpa_McGetMtRealtimeInfo_Cmd )
	BODY(mt::TBytes, tInfoType)

#if !defined(_MESSAGE_HELP_)
	EV_END(MTPA) = EVSEG_MTPA_END
};
#endif

#define Is_Mtpa_Msg(m) ((m) >= EV_BGN(MTPA) && (m) <= EV_END(MTPA))

#endif