#ifndef _MTBLLCONFMSG_H_
#define _MTBLLCONFMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMtConfMsg
{

	//������ϵͳ�õ������е���Ϣ������� ������Ҫ���֣�mtconfģ�飬 mth323�õ��ģ� ����mc�õ�����Ϣ��
	EV_BLL_BGN(CONF) = EVSEG_BLL_CONF_BGN,
#endif
	
	/*
    UI --------------------> mtconf 
		 Ev_MT_BLL_Conf_XXX_Cmd	          
    UI <-------------------- mtconf 
         Ev_MT_BLL_Conf_XXX_Ntf	       
	*/


	/*<<��ʼ����>>
	* make_call_param �����в���
	*��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE(Ev_MT_BLL_Conf_MakeCall_Cmd)
	BODY(mt::TMtCallParam, make_call_param)

	/*<<���ܺ���>>
	*��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE(Ev_MT_BLL_Conf_AcceptCall_Cmd)

	/*<<�ܾ�����>>
	*��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_RejectCall_Cmd )

	/*<<�ҶϺ���>>
	* hangup_reason ���Ҷ�ԭ��
	*��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE(Ev_MT_BLL_Conf_HangupCall_Cmd)
	BODY(mt::TU32, hangup_reason)              //ö��ֵͳһʹ��mt::TU32�����䣬�ô�ʵ��Ϊmt::EmMtCallDisReason
	

	/*<<��ǰ�ĺ���״̬�ϱ�>>
	* callsate ���ϱ��ĺ��в���
	*��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_Conf_CallLinkState_Ntf)         //post to UI  ��ǰ����״̬
	BODY(mt::TMtCallLinkSate, callsate)

	/*<<��ǰ�ĺ���״̬����>>
	*��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_CallLinkState_Req)

	/*<<��ǰ�ĺ���״̬Ӧ��>>
	*��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_CallLinkState_Rsp)
	BODY(mt::TMtCallLinkSate, callsate)

	/*<<����ĺ����ϱ�>>
	* call_param ������ĺ��в���
	*��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_Conf_CallMissed_Ntf)         //��idle״̬���յ�����������Ϣmtpa��Ҷ�������У� ͬʱ�ϱ�����
	BODY(mt::TMtCallParam, call_param)


	/*<<���������>>
	* call_param �������ĺ��в����� ������������������ �ͺ��еĶ���ն���
	*��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_P2pToMultiCall_Cmd )          
	BODY(mt::TMtCallParam, call_param)


	/*<<��ǰ�����Ƿ����>>
	* bEncrypt ���Ƿ����
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_Conf_CallEncrypt_Ntf)
	BODY(mt::TBOOL32, bEncrypt)

	
	/*<<����ǰ�����Ƿ����>>
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_CallEncrypt_Req )

	/*<<�ظ���ǰ�����Ƿ����>>
	* bEncrypt ���Ƿ����
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_CallEncrypt_Rsp)
    BODY(mt::TBOOL32, bEncrypt)

	/*<<Զ���Ի�����>> ͬʱ������Ƶ�Ի�����Ƶ�Ի�
	* bStart �� ����/�ر�
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_RemoteLoop_Cmd )
	BODY( mt::TBOOL32, bStart)


	/*<<Զ���Ի�״ָ̬ʾ>> 
	* emCodeType: codec ����
	* emCodeIdx:  codec ����
	* bResult �� ����/�ر�
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_RemoteLoop_Ntf )
	BODY( mt::TU32,    emCodeType)
	BODY( mt::TU32,    emCodeIdx)
	BODY( mt::TBOOL32, bResult)

	/*<<callid֪ͨ�ϲ㣬���ڰװ����>> 
	* callid  ���128λ
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_Callid_Ntf )
	BODY( mt::TString,  callid)

	//////////////////////////////////////////////////////////pc video˫���õ�����Ϣ


// 	/*<<֪ͨpcdv��ǰmt״̬>> ���ݹ�������õ�
// 	* mtstatus ����ǰ�ϱ���pcdv��mt״̬
// 	* ��Ϣ���� ��conf==>dispatch==>sdk==>pcdv
// 	*/
// 	MESSAGE(Ev_MT_BLL_Conf_PcdvMtStatus_Ntf)            //post to pcdv ��ǰmt״̬,����disconnect����connect��
// 	BODY(mt::TMtStatusToPcdv, mtstatus)


	/*<<��ǰ����״̬>>
	* mt_assstream_status ����ǰ������״̬
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_AssSndSream_Status_Ntf )             //�㲥���н��棬����pcdv, mtc, ��֪���浱ǰ�ն˵�˫�����
	BODY(mt::TMtAssSndVidStatus, mt_assstream_status)

	/*<<��ǰ����״̬>>
	* mt_assstream_status ����ǰ������״̬
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_AssRcvSream_Status_Ntf)              //�㲥���н��棬����pcdv, mtc, ��֪���浱ǰ�ն˵�˫�����
	BODY(mt::TMtAssRcvVidStatus, mt_assstream_status)


	/*<<����ǰ��������״̬>>
	* mt_assstream_status ����ǰ������״̬
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_AssSndSream_Status_Req)             //��������ǰ�ն˵�˫���������
	

	/*<<����ǰ��������״̬>>
	* mt_assstream_status ����ǰ������״̬
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_AssRcvSream_Status_Req)             //��������ǰ�ն˵�˫���������
	
	/*<<Ӧ��ǰ��������״̬>>
	* mt_assstream_status ����ǰ������״̬
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_AssSndSream_Status_Rsp)             //�㲥���н��棬����pcdv, mtc, ��֪���浱ǰ�ն˵�˫�����
	BODY(mt::TMtAssSndVidStatus, mt_assstream_status)

	/*<<Ӧ��ǰ��������״̬>>
	* mt_assstream_status ����ǰ������״̬
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_AssRcvSream_Status_Rsp)             //�㲥���н��棬����pcdv, mtc, ��֪���浱ǰ�ն˵�˫�����
	BODY(mt::TMtAssRcvVidStatus, mt_assstream_status)

	/*<<video˫�����������>>
	* bOpen �������߹�
	* ��Ϣ���� ��sdk==>dispatch==>conf  �� mtmp==>dispatch==>mtservice
	*/
	MESSAGE( Ev_MT_BLL_Conf_VideoAssStream_Cmd )
	BODY(mt:TBOOL32,  bOpen)                       //true : open��  false: close
	BODY(mt::TBOOL32, bScreen)			//�Ƿ�ΪͶ����ҵ��������Ϣ��������body�����û�����body����UI����Ӳ˫��


	/*<<pc˫�����������>>
	* bOpen �������߹�
	* tPcRtcp �� pc��rtcp��ַ
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_PcAssStream_Cmd )
	BODY(mt:TBOOL32,  bOpen)                       //true : open��  false: close
	BODY(mt:TNetAddr, tPcRtcp)                     //pcRtcp��ַ  

	/*<< ����ͨ������ʱ����pc˫��ͨ���� >>
	* bActive �������߹�
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE(Ev_MT_BLL_Conf_ChanActive_Cmd)
	BODY(mt:TBOOL32,  bActive)                //true : open��  false: close

	/*<<pc˫��ͨ�������ϱ�>>
	* mt_Forward_Rtp ��mtת��rtp��ַ
	* mt_Forward_Rtcp �� mtת��rtcp��ַ
	* enc_param ��     ͨ���ı����ʽ
	* payload : ͨ��payload   
	* key     ����������
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_PcAssStream_ChanParam_Ntf )   //ͨ����������Ϣ
	BODY(mt::TNetAddr, mt_Forward_Rtp)
	BODY(mt::TNetAddr, mt_Forward_Rtcp)
	BODY(mt::TVidEncParam,  enc_param)     
	BODY(mt::TU32,  payload)   
	BODY(mt::TEncryptKey, key)  

	/*<<���� �Ƿ����RTP��չͷ>>
	*   tEnable: �Ƿ����
	*��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_Pc_SetBEnableRtpExStrip_Cmd )      
	BODY(mt::TBOOL32,  tEnable)

	/*<<���ö����ش�����>>
	*prs_param �������ش�����
	*��Ϣ���� ��conf==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_Conf_Pc_SetPrsParam_Cmd)
	BODY(mt::TPrsParam, prs_param)



	/*<<pc˫��֪ͨ���濪ʼ����>>
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_PcAssStream_StartEnc_Ntf)         //��ʼ����

	/*<<pc˫��֪ͨ����ֹͣ����>>
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_PcAssStream_StopEnc_Ntf)           //ֹͣ����
	
	/*<<pc˫��֪ͨ��������ؼ�֡>>
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_PcAssStream_IFrameRequest_Ntf)     //����ؼ�֡

	/*<<pc˫��֪ͨ�������bitrate>>
	* bitrate �� ����������
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_PcAssStream_SetBitrate_Ntf)        //����bitrate
	BODY(mt::TU16, bitrate)

	/*<<˫������ʧ�ܣ� û�е�ͨ��Э��>> ԭ������� ����С��192k, ״̬����
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_AssStreamSendFailed_Ntf)        

	//////////////////////////////////////////////////////////////pc video˫���õ�����Ϣ
	

	/*<<��������б�>>
	* conf_req_type �� ��������б�����
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
    MESSAGE( Ev_MT_BLL_Conf_GetConfList_Cmd)       //��������б�, ���ܹ��ȷ�ϣ�5.0�У��ն˲�������all�ˡ�
	BODY(mt::TU32,    conf_req_type)        //EmConfListType�� all, book, idle, hold,


	/*<<�ظ������б�>>             //note, ����ƽ̨����
	* conf_req_type �� ��������б�����
	* conf_req_error:  ��������
	* confList      �� ���confname
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_ConfList_Ntf)          //�ظ������б�, 
	BODY(mt::TU32,  conf_req_type)          //EmConfListType
	BODY(mt::TU32,  conf_req_error)         //EmConfListRspErr
	BODY(mt::TRpMtConfNameInfo, confList)   //�����


	/*<<��������б�>>
	* conf_req_type �� ��������б�����
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
    MESSAGE( Ev_MT_BLL_Conf_GetConfList_Req)       //��������б�, ���ܹ��ȷ�ϣ�5.0�У��ն˲�������all�ˡ�
	BODY(mt::TU32,    conf_req_type)        //EmConfListType�� all, book, idle, hold,


	/*<<�ظ������б�>>            
	* conf_req_type �� ��������б�����
	* conf_req_error:  ��������
	* confList      �� ���confname
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_ConfList_Rsp )          //�ظ������б�, 
	BODY(mt::TU32,  conf_req_type)          //EmConfListType
	BODY(mt::TU32,  conf_req_error)         //EmConfListRspErr
	BODY(mt::TRpMtConfNameInfo, confList)   //�����


	/*<<ras �������>>
	* joinconf_param �� �������Ĳ���
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE(Ev_MT_BLL_Conf_JoinConf_Cmd)            //ѡ������б������� 
	BODY(mt::TMtJoinConfParam,    joinconf_param)         //ѡ��Ļ���e164����
	
	/*<<���������>>
	* fialed_reason  �� ʧ��ԭ��
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_PreJoinConfResult_Ntf)           //ȫ֪ͨUI, ����mtpa
	BODY(mt::TU32,        failed_reason)              //EmMtJoinCreatConfRsp

	
	/*<<ras ��������>>
	* call_param  �� ���в���
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_CreateConf_Cmd )           //������������, ����mtpa
    BODY( mt::TMtCallParam, call_param)


	/*<<��������ظ�>>
	* fialed_reason  �� ʧ��ԭ��
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_PreCreateConfResult_Ntf )     //ֻ��failed�Ż�֪ͨUI
	BODY(mt::TU32,        failed_reason)        //EmMtJoinCreateConfRsp

    /*<<���������ϸ��Ϣ>>
	* conf_e164  �� ����e164����
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetConfDetailInfo_Cmd )        //������ϸ������Ϣ
	BODY(mt::TString,     conf_e164)                //����e164��

	/*<<������ϸ��ϢӦ��>>
	* failed_reason  �� ʧ��ԭ��
	* detail_info    �� ������ϸ��Ϣ
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetConfDetailInfo_Ntf)         //��ϸ������ϢӦ��
	BODY(mt::TU32,            failed_reason)               //EmMtConfDetailErr 
	BODY(mt::TMtConfDetailInfo, detail_info)     

	/*<<����ǰ����������>>
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetRoomNum_Cmd)           //����ǰ����������

	/*<<��ǰ����������Ӧ��>>
	* total_num   �� ������
	* useConfNum  �� ��������
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_RoomNum_Ntf)          //��ǰ����������Ӧ��
	BODY(mt::TU32,       total_num)            //������
	BODY(mt::TU32,       useConfNum)           //��������

	/*<<����ͬ������>>
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_UISynchronize_Cmd)           //����ͬ������
	BODY(mt::TS32,       reason)            //ͬ��ԭ��

	/*<<���ڽ���ͬ��>>  //note 
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_UISynchronize_Ntf)        //���ڽ���ͬ��
	BODY(mt::TS32,       reason)            //ͬ��ԭ��

	/*<<Confģ��������ϱ�>>    
	* dwErrorCode:  ����mtErrCodeMakeErrID���ɵĴ�����
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_ErrorCode_Ntf )
	BODY( mt::TU32, dwErrorCode)



// 
// 	/*<<ע������>>
// 	* ��Ϣ���� ��dispatch==>conf
// 	*/
// 	MESSAGE( Ev_MT_BLL_Conf_Reg_Cmd )          
// 	BODY(mt::TU32,    tConfProtocol)     //EmConfProtocol
// 
// 	/*<<ȡ��ע������>>  ȡ��ע�ᣬ�õ�����һ�ε�gk��ַ������ȡ��ע�᲻��Ҫ����gk��ַ��ȥ
// 	* ��Ϣ���� ��dispatch==>conf
// 	*/
// 	MESSAGE( Ev_MT_BLL_Conf_UnReg_Cmd )        //ȡ��ע������ 
// 	BODY(mt::TU32,    tConfProtocol)    //EmConfProtocol
	

	/*<<ע��������>>
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_RegResult_Req )
	BODY(mt::TU32,    tConfProtocol)        //EmConfProtocol

	/*<<ע����rsp>>
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_RegResult_Rsp )    //ע����
	BODY(mt::TU32,    tConfProtocol)           //EmConfProtocol
	BODY(mt::TBOOL32, bRegSuc      )           //ע��ɹ����


	/*<<ע�����ϱ�>>
	* ��Ϣ���� ��conf==>dispatch==>mtmeetingservice
	*/
	MESSAGE( Ev_MT_BLL_Conf_RegResult_Ntf)     //ע����
	BODY(mt::TU32,    tConfProtocol)    //EmConfProtocol
	BODY(mt::TBOOL32, bRegSuc      )    //ע��ɹ����ʧ�ܵĻ��� ʧ��ԭ������
	BODY(mt::TU32,    bReason      )    //EmRegFailedReason

	/*<<ȡ��ע�����ϱ�>>
	* ��Ϣ���� ��conf==>dispatch==>mtmeetingservice
	*/
	MESSAGE( Ev_MT_BLL_Conf_UnRegResult_Ntf)   //ȡ��ע����
	BODY(mt::TU32,    tConfProtocol)    //EmConfProtocol
	BODY(mt::TBOOL32, bUnRegSuc    )    //ȡ��ע��ɹ����


 	/*<<�ϱ�pc˫�������������>>
 	* ��Ϣ���� ��sdk==>dispatch==>conf
 	*/
 	MESSAGE( Ev_MT_BLL_Conf_MtRePortPCEncStatis_Cmd )  //����mtc��pcdv, ��������Ϣ�� ˭��˫��������������Ϣ
	BODY(mt::TVidEncStatistic,    tEncStatistic)    //ͳ������

	/*conf����Ҫ�ṩ�����ģ���������ϵ�����Todo*/



	//////////////����Ϊ������Ƶ���Ϣ
	/*1	�����ն��б��ն�����,���������Ϣ����*/

	/*<<�����ն˱��>>
	* mt_id:  ������ն˱��\
	* tChairRspToken: ��ǰ�Ƿ�������ϯ�ǳɹ���
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_TerLabel_Ntf )
	BODY(mt::TMtId,  mt_id)
	BODY(mt::TBOOL32, tChairRspToken)

	/*<<�����ն˱��>>
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_TerLabel_Req )
	
	/*<<�����ն˱�Żظ�>>
	* ��Ϣ���� ��sdk<==dispatch<==conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_TerLabel_Rsp)
	BODY(mt::TMtId,  mt_id)


	/*<< �ն��˳�>>
	* ��Ϣ���� ��sdk<==dispatch<==conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_TerLeft_Ntf)
	BODY(mt::TMtId,  mt_id)


	/*<< �ն˼���>>
	* ��Ϣ���� ��sdk<==dispatch<==conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_TerJoin_Ntf )
	BODY(mt::TMtInfo,  mt_info)




// 	/*<<���������ն�����>>
// 	* ��Ϣ���� ��sdk==>dispatch==>conf
// 	*/
// 	MESSAGE( Ev_MT_BLL_Conf_TerGetAllTerName_Cmd )

	
	/*<<����ǰ�������������ն�>>
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
    MESSAGE( Ev_MT_BLL_Conf_OnLineTerList_Req )   ///req��Ϣֻ������mtc��¼ʱ�����󱣴���mtconf�е�����ն��б�����

	/*<<����ǰ�������������ն�>>
	* mt_info:  ���в������ն���Ϣ
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
    MESSAGE( Ev_MT_BLL_Conf_OnLineTerList_Rsp )
	BODY(mt::TRpMtInfo,  mt_info)

	/*<<��ǰ�������������ն�>>
	* mt_info:  ���в������ն���Ϣ
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
    MESSAGE( Ev_MT_BLL_Conf_OnLineTerList_Ntf )   ///��������б� UI����Ҫ��online_cmd��Ϣ�� ��Ϊmtconf���Ӧ�ն��б�ֻҪ�б仯���ͻᷢntf��ȥ 
	BODY(mt::TRpMtInfo,  mt_info)

	
	/*<<����ǰ�������в������ն�>>
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
    MESSAGE( Ev_MT_BLL_Conf_OffLineTerList_Req ) ///req��Ϣֻ������mtc��¼ʱ�����󱣴���mtconf�е������ն��б����ݣ� �ظ���ӦEv_MT_BLL_Conf_OffLineTerList_Rsp
	
	/*<<����ǰ�������в������ն�>>
	* mt_info:  ���в������ն���Ϣ
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
    MESSAGE( Ev_MT_BLL_Conf_OffLineTerList_Rsp )
	BODY(mt::TRpMtInfo,  mt_info)

	/*<<��ǰ�������в������ն�>>
	* mt_info:  ���в������ն���Ϣ
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
    MESSAGE( Ev_MT_BLL_Conf_OffLineTerList_Ntf )   ///mtconf�������ȥ��ƽ̨����ģ�����Ľ����ntf��ȥ�ġ�
	BODY(mt::TRpMtInfo,  mt_info)


	////����Ҫ�ˡ�
	/*<<Mc�����ն���������>>
	* mt_info:  mt��������Ϣ
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	//MESSAGE(Ev_MT_BLL_Conf_McReqTerName_Cmd)
	//BODY(mt::TMtInfo, mt_info)
	
	
	/*<<�ն�Ӧ��mc ����>>
	* mt_info:  mt��������Ϣ
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	//MESSAGE(Ev_MT_BLL_Conf_TerRspMcName_Cmd)
	//BODY(mt::TMtInfo, mt_info)



// 	/*<<��ȡ�����ն���>>
// 	* mt_id:  mtid
// 	* ��Ϣ���� ��sdk==>dispatch==>conf
// 	*/
// 	MESSAGE( Ev_MT_BLL_Conf_TerGetOtherTerName_Cmd)
// 	BODY( mt::TMtId, mt_id )

// 	/*<<�Զ˻�������ָʾ>>
// 	* peer_info:  �Զ˻�������
// 	* ��Ϣ���� ��conf==>dispatch==>sdk
// 	*/
// 	MESSAGE( Ev_MT_BLL_Conf_PeerCap_Ntf ) ///��ʱ����
//     BODY( mt::TPeerCapabilityInfo, peer_info )
// 
// 	/*<<�Զ˻�����������>>
// 	* ��Ϣ���� ��sdk==>dispatch==>conf
// 	*/
// 	MESSAGE( Ev_MT_BLL_Conf_PeerCap_Req) ///��ʱ����
// 
// 	/*<<�Զ˻�������Ӧ��>>
// 	* ��Ϣ���� ��conf==>dispatch==>sdk
// 	*/
// 	MESSAGE( Ev_MT_BLL_Conf_PeerCap_Rsp) ///��ʱ����
	
	///ȷ����3.

	/*<<���������Ϣ>>
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetConfInfo_Cmd )
	

	///////note  ����ƽ̨��ͬʱ����
	/*<<��ǰ������Ϣ>>
	* conf_info:  ��ǰ������Ϣ
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_ConfInfo_Ntf )
	BODY(mt::TMtConfInfo, conf_info)

	/*<<��ǰ������Ϣ>>
	* sim_conf_info:  �򵥻�����Ϣ
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*
	h_ctrl_SimpleConfInfoInd,               //mcu֪ͨ�ն˸��»�����Ϣ      MC->ter
	*/
	MESSAGE( Ev_MT_BLL_Conf_SimpleConfInfo_Ntf )   
	BODY(mt::TMtSimpConfInfo, sim_conf_info)



	/*<<����ǰ������Ϣ>>
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_ConfInfo_Req )

	/*<<�ظ���ǰ������Ϣ>>
	* conf_info
	* bRecvSimpleInfo: �Ƿ��յ�simconfinfo
	* simp_conf_info�� �򵥻�����Ϣ
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_ConfInfo_Rsp)
    BODY(mt::TMtConfInfo, conf_info)
	BODY(mt::TBOOL32,     bRecvSimpleInfo)
	BODY(mt::TMtSimpConfInfo, simp_conf_info)


    /*<<���鼴������ָʾ>>
	* time:  ��ʣ��ʱ��
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ConfWillEnd_Ntf)
	BODY(mt::TU16, time )

	/*<<�����Ƿ�Ҫ��������>>
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_IsEnterPassword_Req)   ///����mtc�����նˣ�����conf���Ƿ�Ҫ�����������
	
	/*<<�ظ��Ƿ�Ҫ��������>>
	* bEnterPassword: �Ƿ�Ҫ��������
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_IsEnterPassword_Rsp)  ///����mtc�����նˣ�mtconf�ظ� �Ƿ�����������룬 Ȼ��mtc�ٷ���Ev_MT_BLL_Conf_MtRspPassword_Cmd
	BODY(mt::TBOOL32,  bEnterPassword )

	/*<<������������>>
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_McReqPassword_Cmd)

	/*<<��������Ӧ��>>
	* conf_pwd:  ��������
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_MtRspPassword_Cmd)
	BODY(mt::TBytes, conf_pwd )



	/* 2. ��ϯ��ز���*/

    /*<<ǿ���ն��˳�, chair->mc>>
	* mt_id   : �ն�id
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_DropTer_Cmd)
	BODY( mt::TMtId, mt_id )

	/*<<ǿ���ն��˳�ʧ��, mc->chair >>
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_DropTerReject_Ntf )
	
	/*<<��������, chair->mc >>
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_EndConf_Cmd )


	////note, �ӳ�ʱ�����ָ��������ƽ̨
	/*<<��ϯ�ӳ�����>>
	* time:  �ӳ���ʱ�� /����
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ReqProlong_Cmd)
	BODY(mt::TU16, time )

	/*<<�����ӳ�Ӧ��>>
	* bResult:  �Ƿ�ͬ��
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ProlongResult_Ntf)
	BODY(mt::TBOOL32, bResult )



	
	/*<<��ϯ�����ն� chair->mc >>
	* mt_addr:  �ն˵�ַ
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_ChairInviteTer_Cmd)
	BODY(mt::TMtAddr, mt_addr )

	/*<<��ϯ�����ն�ʧ�� mc->chair>>
	* mt_addr:  �ն˵�ַ
	* tReason:  ʧ��ԭ��
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_ChairInviteFailed_Ntf)   
	BODY(mt::TMtAddr, mt_addr )
	BODY(mt::TU32,    tReason) //EmMtCallDisReason


// 	/*<<��ϯ�����ն�ʧ��, ʧ��ԭ�� mc->chair>>
// 	* emReason: ʧ��ԭ��
// 	* ��Ϣ���� ��conf==>dispatch==>sdk
// 	*/
// 	MESSAGE( Ev_MT_BLL_ConfTerJoinConfFailed_Ntf )     //// chenlijun 20121204 Bug00102382 TL2.5:TL����AES���ܣ��ټ�������AES�նˣ����벻�ɹ���Ҳû��������ʧ�ܵ���ʾ
// 	BODY( mt::EmMtConfFailureReason, emReason )


	/*<<���鷢������, ʧ��ԭ�� mc->mt>>
	* emReason: ʧ��ԭ��
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_ConfFailed_Ntf )     
	BODY( mt::EmMtConfFailureReason, emReason )


	/*<<��ϯ���������ն� >>
	* mt_id: �����ն�id
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_CallOfflineTer_Cmd)
	BODY( mt::TMtId, mt_id )

	/*
	ԭ����Ev_MT_BLL_Conf_ModifyConfName_Cmd�� Ev_MT_BLL_ConfModifyConfDuration_Cmd��
	Ev_MT_BLL_Conf_ModifyConfPwd_Cmd�� Ev_MT_BLL_Conf_ModifyDualMode_Cmd
	��Ϣ�ȴ��ظ��� Ev_MT_BLL_Conf_ModifyConfResult_Ntf
	*/
    
	/*<<�޸Ļ��黭��ϳ��Ƿ���ʾ��Ա���� >>
	* bShow: �Ƿ���ʾ
	* content: 
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_ModifyVmpShowAlias_Cmd )
	BODY( mt::TBOOL32, bShow )


	/*<<�޸Ļ������� >>
	* emModifyType: �޸�type
	* content: 
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_ModifyConfName_Cmd )
	BODY( mt::TString,   content ) 

	/*<<�޸Ļ���ʱ�� >>
	* wTime: ����
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_ModifyConfDuration_Cmd)
	BODY( mt::TU16, wTime)

	/*<<�޸Ļ���ʱ�� >>
	* bDumb: �Ƿ�����
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_SetConfDumb_Cmd)
	BODY( mt::TBOOL32, bDumb)

	/*<<�޸Ļ����Ƿ������ >>
	* bEnable: �Ƿ���
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_SetConfNoDisturb_Cmd)
	BODY( mt::TBOOL32, bEnable)


	/*<<�޸Ļ������� >>
	* bUsePwd:  �Ƿ�������
	* tpwd:     ��������
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_ModifyConfPwd_Cmd)
	BODY( mt::TBOOL32, bUsePwd)
	BODY( mt::TBytes,  tPwd)

	/*<<�޸Ļ���˫������ >>
	* emMtDualMode:  ˫������
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_ModifyDualMode_Cmd )
	BODY( mt::TU32, emMtDualMode)  //emMtDualMode

	/*<<�޸Ļ�����Ӧ�� >>
	* emModifyType: �޸�����
	* bResult:      �ɹ����
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_ModifyConfResult_Ntf )
	BODY( mt::TU32,   tModifyType ) //EmMtModifyConfInfoType_Api
	BODY( mt::TBOOL32, bResult )



	/*3 ������ز���*/

	/*<<���뷢���� mt->mc >>
	* note : conf�㲻����ʱ���� ��Ϊ��ͬ�Ľ��涨ʱ���Բ�һ��
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ApplySpeak_Cmd )   /////���ͬ�������� Ev_MT_BLL_Conf_IsSeenByAll_Ntf�� ��ͬ�⣬ ƽ̨û�лظ�, 

	/*<<�յ����뷢�������� mc->chair >>
	* mt_id :  �����˵�id
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ApplySpeak_Ntf )
	BODY(mt::TMtId, mt_id)

	/*<<��ϯͬ�ⷢ�� chair->mc >>
	* mt_id :  �����˵�id
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ChairAgreeSpeak_Cmd )
	BODY(mt::TMtId, mt_id)

	/*<<������λ��ָʾ mc->mt >> 
	* mt_id :  �����˵�id
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_SpeakerPos_Ntf )       
	BODY(mt::TMtId, mt_id)


	/*<<��Ϊ������ָʾ mc->mt>> 
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_SeenByAll_Ntf )
	
	/*<<ȡ��������ָʾ mc->mt>> 
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_CancelSeenByAll_Ntf )

	/*<<���뷢���˳�ʱָʾ>> 
	* ��Ϣ���� ��dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ApplySpeakTimerOut_Ntf )

	/*<<������ϯ��ʱָʾ>> 
	* ��Ϣ���� ��dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ApplyChairTimerOut_Ntf )
	
	/*<<����廰��ʱָʾ>> 
	* ��Ϣ���� ��dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ApplyChiemeTimerOut_Ntf )
	

	/*<<��ϯָ������������ >>
	* mt_id :  �����˵�id
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ChairAssignSpeak_Cmd )   //��Ҫ��ƽ̨�ظ�Ev_MT_BLL_Conf_BroadcastResult_Ntfͬ�⻹�ǲ�ͬ��
	BODY(mt::TMtId, mt_id)

	/*<<��ϯָ�������˽�� chair->mc >>
	* bResult :  ָ���ɹ���ʧ��
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ChairAssignSpeakRes_Ntf )
	BODY(mt::TBOOL32,  bResult)

	/*<<��ϯȡ�������� chair->mc >>
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_CancelBroadcast_Cmd )

	/*<<Դλ��ָʾ mc->mt >>
	* mt_seeing :  ��·��ƵԴ
	* ��Ϣ����  �� conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_YouAreSeeing_Ntf )
	BODY(mt::TRpMtSeeing, mt_seeing)

	/*<<������ƵԴλ�� mc->mt >>
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_YouAreSeeing_Req ) 
	
	/*<<�ظ���ƵԴλ�� mc->mt >>
	* mt_id :  ��ƵԴ�ն˵�id
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_YouAreSeeing_Rsp )
	BODY(mt::TRpMtSeeing, mt_seeing)



	/*3 ��ϯ������ز���*/
	/*<<������ϯ���� mt->mc >>
	*note : conf�㲻����ʱ����
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ApplyChair_Cmd )  
	
	
	/*<< ������ϯ�ظ�����ϯ���Ƹı� mc->mt >>
	*note : conf�㲻����ʱ����
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_GetChairToken_Ntf )
	BODY(mt::TBOOL32, bGet)

	/*<<���ն�������ϯ mc->chair >>
	* mt_id:  mt_id
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ApplyChairInd_Ntf) //�Ǳ�
	BODY(mt::TMtId, mt_id)

	/*<<�ͷ���ϯ���� chair->mc >>
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_WithdrawChair_Cmd )
	
	/*<<��ϯλ�ò�ѯ mt->mc >>
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_WhoIsChair_Cmd )

	/*<<��ϯλ��ָʾ mc->mt >>
	* mt_id :  ��ϯ�ն˵�id
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_Chair_Ntf )
	BODY(mt::TMtId, mt_id)


	/*<<��ϯת������ chair->mc >>
	* mt_id :  ָ���ն˵�id
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ChairTransfer_Cmd ) //�Ǳ�
	BODY(mt::TMtId, mt_id)

	/*<<��ϯָ��vip�б� chair->mc >>
	* mt_id :  ָ���ն˵��б�
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ChairSpecVip_Cmd ) //�Ǳ�
	BODY(mt::TRpMtId, mt_id)

	/*<<mc��Ӧ��ϯָ��vip�б� chair<-mc >>
	* tResult :  �Ƿ�ͬ��
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_SetVipResult_Ntf ) //�Ǳ�
	BODY(mt::TBOOL32, tResult)

	/*<<mc֪ͨ�ն˵�ǰvip�б� ter<-mc >>
	* mt_id :  ָ���ն˵��б�
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_McInfoTerVip_Ntf ) //�Ǳ�
	BODY(mt::TRpMtId, mt_id)

	/*<<����ǰvip�б�  >>
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_VipList_Req ) //�Ǳ�


	/*<<�ظ���ǰvip�б� >>
	* mt_id :  ָ���ն˵��б�
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_VipList_Rsp ) //�Ǳ�
	BODY(mt::TRpMtId, mt_id)


	/*4 ѡ��,�廰����ѯ, ��������*/

	/*<<ѡ���ն� chair->mc >>
	* TViewTerParam :  ѡ���ն�param
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_SendThisTer_Cmd )
	BODY(mt::TViewTerParam, viewparam)
	
	/*<<ѡ���ն� chair->mc >>
    * bView :  ��ǰ�Ƿ���ѡ��
	* TViewTerParam :  ѡ���ն�param
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 	MESSAGE( Ev_MT_BLL_Conf_SendThisTer_Ntf )
	BODY(mt::BOOL32, bView)
	BODY(mt::TViewTerParam, viewparam)

	/*<<ѡ���ն� chair->mc >>
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_GetSendThisTerParam_Req )

		/*<<ѡ���ն� chair->mc >>
	* TViewTerParam :  ѡ���ն�param
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_GetSendThisTerParam_Rsp )
	BODY(mt::TViewTerParam, viewparam)

	/*<<ѡ���ն˽�� mc->chair >>
	* bResult: ѡ���ɹ����
	* mt_id :  ѡ���ն˵�id
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_SendThisTerResult_Ntf ) 
	BODY(mt::TBOOL32, bResult)
	BODY(mt::TMtId,   mt_id)

	/*<<ȡ��ѡ�� chair->mc >>
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_CancelSendThisTer_Cmd )  
	
	/*<<���ն˱�ѡ�� mc->mt >>
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_SeenByOther_Ntf)
	
	/*<<���ն�ȡ����ѡ�� mc->mt >>
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_CancelSeenByOther_Ntf)
	
	/*<<����廰 mt->mc >>
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ApplyChiemeIn_Cmd ) //conf�㲻����ʱ���� ��Ϊ��ͬ�Ľ��涨ʱ���Բ�һ��

	/*<<���ն�����廰 mc->chair >>
	* mt_id :  ����廰�ն˵�id
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ApplyChimeIn_Ntf )
	BODY(mt::TMtId, mt_id)
	
	/*<<��ϯͬ��廰���� chair->mc >> 
	* mt_id :  ����廰�ն˵�id
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_ChiemeIn_Cmd )    //ָ���廰�� ����ͬһ����Ϣ
	BODY(mt::TMtId, mt_id)

	/*<<�ն˲廰״̬ mc->ter >>
	* bResult : �Ƿ����ڲ廰
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_ChimeInState_Ntf )
	BODY(mt:BOOL32, bResult)

	/*<<�ն˲廰ʧ�� mc->ter >>
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_ChimeInFailed_Ntf )
	
// 	/*<<��ϯָ���廰���� chair->mc >>
// 	* mt_id :  ����廰�ն˵�id
// 	* ��Ϣ���� ��sdk==>dispatch==>conf
// 	*/
// 	MESSAGE( Ev_MT_BLL_Conf_ReqChiemeIn_Cmd )   //�ִ���û�д������Ϣ
// 	BODY(mt::TMtId, mt_id)


	//////��ѯ����Ӧ��
	//////ToDo

	/*<<��ϯ��ѯ�ն����� chair->mc >>
	* poll_info : ��ѯ����
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_Poll_Cmd )
    BODY(mt::TMtPollInfo, poll_info)

	/*<<��ϯ��ѯ״̬�ϱ� conf->sdk >>
	* poll_info : ��ѯ����
	* ��Ϣ���� �� conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_PollState_Ntf )
    BODY(mt::TMtPollInfo, poll_info)

	/*<<��ϯ��ѯ�ն˲������� >>
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_PollState_Req )

	/*<<��ϯ��ѯ�ն˲������� >>
	* poll_info : ��ѯ����
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_PollState_Rsp )
	BODY(mt::TMtPollInfo, poll_info)


	/*<<��ǰ������ѯ�ն�֪ͨ conf->sdk >>
	* tMtId :     ������ѯ�յ��ն�
	* ��Ϣ���� �� conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_PollingMt_Ntf )
    BODY( mt::TMtId, tMtId )

	/*
	note:  ״̬�б�ƽ̨û����Ϣ��һ����ȡ���е��б�����TerStatusList_Req����ȡ�������ն���ߵ�һ�����б�������ȫ����
	*/

	/*<<��ѯ����ն�״̬ chair->mc >>
	* tMtId : �ն�id
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_TerGetTerStatus_Cmd)
	BODY(mt::TMtId,   tMtId)

	/*<<��ѯ����ն�״̬Ӧ�� mc->chair >>
	* tMtId : �ն�id
	* tTerStatus: �ն�״̬
	* ��Ϣ���� �� conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_TerGetTerStatus_Ntf)
	BODY(mt::TMtEntityStatus,   tMtStatus)
	

	/*<<�����ն�״̬�б� >>
	* tMtId : �ն�id
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetTerStatusList_Req )

	/*<<��ѯ����ն�״̬Ӧ�� mc->chair >>
	* tMtId : �ն�id
	* tTerStatus: �ն�״̬
	* ��Ϣ���� �� conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetTerStatusList_Rsp)
	BODY(mt::TRpMtEntityStatus,   tRpMtStatus)

	/*<<ͬ��sdk�㻺��Ļ����б�  >>
	* ��Ϣ���� �� conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_RemoveConfList_Cmd)
	
// 	////������ʱ������ mcs�ϻ��õ�
// 	/*<<�������� >>
// 	* tMtId�� mtid
// 	* ��Ϣ���� �� sdk==>dispatch==>conf
// 	*/
// 	MESSAGE( Ev_MT_BLL_Conf_RollCall_Cmd ) //��ʱ����
// 	BODY(mt::TMtId,   tMtId)
// 
// 	/*<<���������� >>
// 	* tMtid:   mtid
// 	* bResult: �������
// 	* ��Ϣ���� �� conf==>dispatch==>sdk
// 	*/
// 	MESSAGE( Ev_MT_BLL_Conf_RollCallResult_Ntf )//��ʱ����
// 	BODY(mt::TMtId,   tMtId)
// 	BODY(mt::TBOOL32, bResult)


	/*<<��ϯǿ�ƹ㲥 >>
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_StartForceBroadcast_Cmd ) ///��ʱ����
	
	/*<<��ϯǿ��ȡ���㲥 >>
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_StopForceBroadcast_Cmd )  ///��ʱ����



	/*5 ����ϳɣ���������*/

	/*<< ��ʼ�������� >>
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_StartVAC_Cmd )

	/*<< ��ʼ��������Ӧ�� >>
	* bResult : ���
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_StartVACResult_Ntf )
	BODY(mt::TBOOL32, bResult)


	/*<< ֹͣ�������� >>
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_StopVAC_Cmd )

	/*<< ֹͣ����������� >>
	* bResult : ���
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_StopVACResult_Ntf )
	BODY(mt::TBOOL32, bResult)


	/*<< ��ʼ����ģʽ���� >>
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_StartDiscuss_Cmd )  //����Ҫ����������������discuss��ȫ������

	/*<< ��ʼ����ģʽ��� >>
	* bResult : ���
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_StartDiscussResult_Ntf )
	BODY(mt::TBOOL32, bResult)


	/*<< ֹͣ����ģʽ���� >>
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_StopDiscuss_Cmd )

	/*<< ֹͣ����ģʽ��� >>
	* bResult : ���
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_StopDiscussResult_Ntf )
	BODY(mt::TBOOL32, bResult)

	/*<< ��ʼ�������� >>
	* TRpMtId:  �����ն���
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_StartCustomMix_Cmd)
	BODY(mt::TRpMtId, tRpMtId )

	/*<< ��ʼ����Ӧ�� >>
	* bResult:   ���
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_StartCustomMixResult_Ntf)
	BODY(mt::BOOL32, bResult)


	/*<< ֹͣ�������� >>
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_StopCustomMix_Cmd)

	/*<< ֹͣ����Ӧ�� >>
	* bResult:   ���
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_StopCustomMixResult_Ntf)
	BODY(mt::BOOL32, bResult)


	/*<< ��ӻ�����Ա >>
	* tRpMtId:  ���������Ա
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_MakeTerChimeIn_Cmd )
	BODY(mt::TRpMtId, tRpMtId )

	/*<< ɾ��������Ա >>
	* tRpMtId:  ���������Ա
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_RemoveTerChimeIn_Cmd )
	BODY(mt::TRpMtId, tRpMtId )

	
	/*<< ���������ϱ� >>
	* tmixparam:  ��������
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_MixParam_Ntf )
	BODY(mt::TMtMixParam, tmixparam)

	/*<< ������Ա���� >>
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_MixParam_Req )
	
	/*<< ������Ա�ظ� >>
	* mix_param:  ��������
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_MixParam_Rsp )
	BODY(mt::TMtMixParam, mix_param)

	/*<< ��������ϳɲ������� >>
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_CustomVmpParam_Req )
	
	/*<< ��������ϳɲ���Ӧ�� >>
	* vmp_param:  ��������ϳɲ���
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_CustomVmpParam_Rsp )
	BODY(mt::TMtVmpParam, vmp_param)
	

	///��������ϳ�

	/*
	Note��  PreResult ��ƽ̨ҵ��Ļظ� ͬ����߾ܾ�
	        Result:   ��ƽ̨�ײ�Ļظ���������ͬ����߾ܾ�
	*/

	/*<< ��ʼ����໭��ϳ����� >>
	* vmp_param: ����ϳɲ���
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_StartVMP_Cmd)
	BODY( mt::TMtVmpParam, vmp_param )

	/*<< ��ʼ�����໭��ϳ����� >>
	* vmp_param: ����ϳɲ���
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_StartCustomVMP_Cmd )
	BODY( mt::TMtVmpParam, vmp_param )



	/*<< ��ʼ���黭��ϳ�Ӧ�� >>
	* bResult : ���
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_StartVMPResult_Ntf)
	BODY( mt::TBOOL32,     bResult )

	/*<< ��ʼ�����໭��ϳ�Ӧ�� >>
	* bResult : ���
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_StartCustomVMPResult_Ntf)
	BODY( mt::TBOOL32,     bResult )


	/*<< ֹͣ����໭��ϳ����� >>
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_StopVMP_Cmd)
	
	/*<< ֹͣ��������ϳ����� >>
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_StopCustomVMP_Cmd)


	/*<< ֹͣ����໭��ϳ�Ӧ�� >>
	* bResult : ���
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_StopVMPResult_Ntf)
	BODY(mt::TBOOL32, bResult)

	
	/*<< ֹͣ�Զ��໭��ϳ�Ӧ�� >>
	* bResult : ���
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_StopCustomVMPResult_Ntf)
	BODY(mt::TBOOL32, bResult)


	/*<< ���û���ϳɲ��� >>
	* vmp_param: ����ϳɲ���
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_SetVMPParam_Cmd )    //ֻ��Կƴ��ն�
	BODY( mt::TMtVmpParam, vmp_param)     

		/*<< ���û���ϳɲ��� >>
	* vmp_param: ����ϳɲ���
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_SetCustomVMPParam_Cmd )    //ֻ��Կƴ��ն�
	BODY( mt::TMtVmpParam, vmp_param) 


	/*<< ���û��黭��ϳɲ���Ӧ�� >>
	* bResult : ���
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_SetVMPParamResult_Ntf)
	BODY( mt::TBOOL32,    bResult )

	/*<< ������������ϳɲ���Ӧ�� >>
	* bResult : ���
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_SetCustomVMPParamResult_Ntf)
	BODY( mt::TBOOL32,    bResult )

	/*<< ͬ��sdk����ϳɲ��� >>
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_SyncVMPParam_Cmd)
	
	/*<< ��ȡ����ϳɲ��� >>
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetVMPParam_Cmd )

	/*<< ��ȡ����ϳɲ�����Ӧ >>
	* vmp_param �� ����ϳɲ���
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetVMPParamResult_Ntf )
	BODY( mt::TMtVmpParam, vmp_param)

	/*<< ��ȡ��������ϳɲ�����Ӧ >>
	* vmp_param �� ����ϳɲ���
	* ��Ϣ���� �� conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetCustomVMPParamResult_Ntf )
	BODY( mt::TMtVmpParam, vmp_param)
	
	/*<< Զ������ >>
	* tMtid:  �ն�id
	* bMute�� �Ƿ�����
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_MakeTerMute_Cmd )
	BODY(mt::TMtId,   tMtId)
	BODY(mt::TBOOL32, bMute)


	/*<< Զ�˾��� >>
	* tMtid:  �ն�id
	* bQuiet�� �Ƿ���
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_MakeTerQuiet_Cmd )
	BODY(mt::TMtId,   tMtId)
	BODY(mt::TBOOL32, bQuiet)

	////ƽ̨��ͨ�� ����Ƿ�أ����������Ƿ���
	/*<< �л�����ϳɷ�� >>
	* is_multipic:  �Ƿ�໭��
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_SwitchBroadCastStyle_Cmd )
	BODY(mt::TBOOL32, is_multipic)

	/*<< �նˣ�������ϯMT��ѡ������ϳ����� >>
	* bStart:  TRUE ѡ������ϳɣ�FALSE ȡ��ѡ������ϳ�
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_mtSelectVmp_Cmd)
	BODY( mt::TBOOL32, bStart)

	/*<< �նˣ�������ϯMT��ѡ������ϳ���Ӧ >>
	* bStart:  TRUE ѡ������ϳɣ�FALSE ȡ��ѡ������ϳ�
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_SelectVmpResult_Ntf)
	BODY( mt::TBOOL32, bStart)


	/*<< ����Ϣ >>
	* short_mess:  ����Ϣ����
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_SMS_Cmd)         /////������ƽ̨
	BODY(mt::TShortMsg, short_msg)


	/*<< ����Ϣָʾ >>
	* short_mess:  ����Ϣ����
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_SMS_Ntf)        ////������ƽ̨
	BODY(mt::TShortMsg, short_msg)

	/*<< ����Զ���ƵԴ��Ϣ >>
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_PeerVideoAlias_Req )

	/*<< �Զ���ƵԴ��Ϣ��Ӧ >>
	* peer_info:  �Զ���ƵԴ��Ϣ
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_PeerVideoAlias_Rsp )
	BODY(mt::TRpMtVideoAlias, peer_info)

	/*<< �Զ���ƵԴ��Ϣ��Ӧ >>
	* peer_info:  �Զ���ƵԴ��Ϣ
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_PeerVideoAlias_Ntf )
	BODY(mt::TRpMtVideoAlias, peer_info)
    


	////////////////////Զҡ���conf������Ǳ��ط���Զҡ������ƶԶˣ�
	///////////////////�Զ˹�����Զҡ���conf������󣬿�������ͷ,Ӧ����device�Ǳ߶���
	/*<< ѡ���������ͷ���� >>
	* tDest_Mtid:    Ŀ��id
	* byCameraIndex: ����ͷ����
	* ��Ϣ���� ��device/?==>dispatch==>mtconf
	*/
	MESSAGE( Ev_MT_BLL_Conf_FeccCameraSelect_Cmd )
	BODY(mt::TMtId,   tDest_Mtid )
	BODY(mt::TU8,     byCameraIndex)

	 /*<< ����ͷ�۽����� >>
	* tDest_Mtid:    Ŀ��id
	* bNearFocus,    TRUE=���� , FALSE=Զ��
	* tAction:       ������ emStart/emStop
	* ��Ϣ���� ��device/?==>dispatch==>mtconf
	*/
    MESSAGE( Ev_MT_BLL_Conf_FeccCameraFocus_Cmd )
    BODY(mt::TMtId,   tDest_Mtid )
    BODY(mt::TBOOL32, bNearFocus )
    BODY(mt::TU32,    tAction)     //EmAction


	/*<< ����ͷ�Զ��۽����� >>
	* tDest_Mtid:    Ŀ��id
	* ��Ϣ���� ��device/?==>dispatch==>mtconf
	*/
	MESSAGE( Ev_MT_BLL_Conf_FeccCameraAutoFocus_Cmd )
	BODY(mt::TMtId,   tDest_Mtid )

	/*<< ������Ұ���� >>
	* tDest_Mtid:    Ŀ��id
	* bZoomIn:       TRUE= �Ŵ� /FALSE=��С
	* tAction:       emStart/emStop
	* ��Ϣ���� ��device/?==>dispatch==>mtconf
	*/
	MESSAGE( Ev_MT_BLL_Conf_FeccCameraZoom_Cmd)
	BODY(mt::TMtId,   tDest_Mtid )
	BODY(mt::TBOOL32, bZoomIn )
	BODY(mt::TU32,    tAction)     //EmAction

	/*<< �������ȵ������� >>
	* tDest_Mtid:    Ŀ��id
	* bLight:       TRUE= ����  FALSE=����
	* tAction:       emStart/emStop
	* ��Ϣ���� ��device/?==>dispatch==>mtconf
	*/
	MESSAGE(Ev_MT_BLL_Conf_FeccCameraBright_Cmd)
	BODY(mt::TMtId,   tDest_Mtid )
	BODY(mt::TBOOL32,   bLight )
	BODY(mt::TU32,     tAction)     //EmAction

	/*<< Ԥ��λ���� >>
	* tDest_Mtid:    Ŀ��id
	* bLight:        TRUE= �洢 FALSE=����Ԥ��λ
	* byIndex        Ԥ��λ���� 1-16
	* ��Ϣ���� ��device/?==>dispatch==>mtconf
	*/
	MESSAGE(Ev_MT_BLL_Conf_FeccCameraPreset_Cmd)
	BODY(mt::TMtId,   tDest_Mtid )
	BODY(mt::TBOOL32, bSave )
	BODY(mt::TU8,     byIndex)

	/*<< ����ͷ�ƶ����� >>
	* tDest_Mtid:    Ŀ��id
	* tDirection:    �ƶ�����
	* tAction:       emStart/emStop
	* ��Ϣ���� ��device/?==>dispatch==>mtconf
	*/
	MESSAGE(Ev_MT_BLL_Conf_FeccCameraPantilt_Cmd )
	BODY(mt::TMtId,   tDest_Mtid )
	BODY(mt::TU32,    tDirection ) //EmDirection
	BODY(mt::TU32,    tAction)     //EmAction

	/*<< ѡ����ƵԴ >>
	* tDest_Mtid:    Ŀ��id
	* byVideoSrcIndex:  ѡ����ƵԴ
	* ��Ϣ���� ��device/?==>dispatch==>mtconf
	*/
	MESSAGE(Ev_MT_BLL_Conf_FeccVideoSourceSel_Cmd)   ////ֻѡ������Ƶ
	BODY(mt::TMtId,   tDest_Mtid )
	BODY(mt::TU8,     byVideoSrcIndex)


	/*<<�����ӳ�֪ͨ>>
	* time:  �ӳ���ʱ��(����)
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ConfDelay_Ntf)
	BODY(mt::TU16, time )

	/*<<�����������ֱ���>>
	* tMtRpRes : ����֧�ֵķֱ���
	* ����֧�ֵķֱ��ʣ���ʱ�ײ�ֻ�Ǹ���264�ķֱ���
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_AdjustH264CapRes_Cmd )
	BODY(mt::TMtRpRes, tMtRpRes )


	/*<<�ر�������Ƶͨ������>>  
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_MainVideoOff_Cmd )


	/*<<����ʣ��ʱ��>>  
	* rest_time : ����ʣ��ʱ��
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_RestTime_Ntf )
	BODY(mt::TU16, rest_time )

	
	////ֻ��h323�ᷢ������ȥ�� ֧�ֵĻ�������
	MESSAGE( Ev_MT_BLL_Conf_NotifyConfType_Ntf )
	BODY(mt::TU32,   emMtConfType)
	BODY(mt::TU16,   bitrate)

	////Э��ջ��ʼ��ʧ��ԭ��
	MESSAGE( Ev_MT_BLL_Conf_StackInitFailedReason_Ntf )
	BODY(mt::TU32,   emProtocol) //EmConfProtocol
	BODY(mt::TU32,   emStackInitFailReason) //EmStackInitFailReason

	////˫�����ͷ�֪ͨ
	MESSAGE( Ev_MT_BLL_Conf_DualStreamSender_Ntf )
	BODY(mt::TMtId,  tMtid)
	BODY(mt::TBOOL32, tGrabbed) /////�Ƿ�ǰ�ն˱�����

	////��ȡ��ǰ˫�����ͷ�����
	MESSAGE( Ev_MT_BLL_Conf_GetDualStreamSender_Req )

	////��ȡ��ǰ˫�����ͷ��ظ�
	MESSAGE( Ev_MT_BLL_Conf_GetDualStreamSender_Rsp )
	BODY(mt::TMtId,  tMtid)

	/*<<���÷��Ͱ���ǣ�֧��ƽ̨�˿ڸ���>>
	*e164_param        ��e164��
	*stream_id         ������Ψһ��ʶ
	*��Ϣ���� ��service==>dispatch==>vnc
	*/
    MESSAGE(Ev_MT_BLL_Conf_SetStreamID_Cmd)
	BODY(mt::TString, e164_param)//e164��
	BODY(mt::TU32, stream_id)//����Ψһ��ʶ

	/*<<�Ƿ�nat��Խ����>>
	*is_nattraversal   ���Ƿ�nat��Խ
	*��Ϣ���� ��service==>dispatch==>vnc
	*/
    MESSAGE(Ev_MT_BLL_Conf_IsNatTraversal_Cmd)
	BODY(mt::TBOOL32, is_nattraversal)//�Ƿ�nat��Խ
	BODY(mt::TNetAddr, rtp_local_addr)
	BODY(mt::TNetAddr, rtcp_local_addr)
	BODY(mt::TNetAddr, rtp_remote_addr)
	BODY(mt::TNetAddr, rtcp_remote_addr)
	////��һ·��Ƶ���ͽ���ͨ���رգ���������
	MESSAGE( Ev_MT_BLL_Conf_PrimoVideoOff_Ntf )
	
	/////Э��ջ������ ��stop/start��ȥ
	MESSAGE( Ev_MT_BLL_Conf_StackOnOff_Cmd )
	BODY(mt::TU32,    emProtocol) //Э��
	BODY(mt::TBOOL32, bStart) //start/stop
	

	/////����Э��ջ��׼/�Ǳ�
	MESSAGE( Ev_MT_BLL_Conf_SetStack_Cmd )
	BODY(mt::TU32,    emProtocol) //Э��
	BODY(mt::TBOOL32, bStart) //start/stop
	

	/////�װ���鴴��֪ͨ
	MESSAGE( Ev_MT_BLL_Conf_DataConfCreatedNtf_Cmd )
	BODY(mt::TString, conf_name) //�װ��������
	BODY(mt::TString, conf_e164) //�װ����e164

	///����װ�������� ���ڵ�Ե�
	MESSAGE( Ev_MT_BLL_Conf_JoinDataConf_Cmd )
	BODY(mt::TString, conf_name) //�װ��������
	BODY(mt::TString, str)       //

	///�յ��Զ˵ļ���װ�������� ����mcu, ���߶Զ�
	MESSAGE( Ev_MT_BLL_Conf_JoinDataConf_Ntf )
	BODY(mt::TString, conf_name)  //�װ��������
	BODY(mt::TString, str)        //

	
	/*<<��ϯָ���ն˷�˫�� chair->mc >>
	* mt_id :  �ն˵�id
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ChairSpecTerSendAss_Cmd )
	BODY(mt::TMtId, mt_id)

	/*<<��ϯָ���ն˷�˫�� chair->mc >> ����ͬ����
	* mt_id :  �ն˵�id
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ChairSpecTerSendAss_Ntf )
	BODY(mt::TMtId, mt_id)

	/*<<��ϯָ���ն˷�˫�� chair->mc >> ����ͬ�����������
	* mt_id :  �ն˵�id
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ChairSpecTerSendAssParam_Req )

	/*<<��ϯָ���ն˷�˫�� chair->mc >> ����ͬ�����������
	* mt_id :  �ն˵�id
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ChairSpecTerSendAssParam_Rsp )
	BODY(mt::TMtId, mt_id)

    //<<��ϯ���õ绰�˻���غ�>> -- add by zwf
    MESSAGE( Ev_MT_BLL_Conf_ChairSetRecallDial_Cmd )
    BODY(mt::TBOOL32, bRecall)

    //<<��ϯ���õ绰�˻���غ�֪ͨ>> -- add by zwf
    MESSAGE( Ev_MT_BLL_Conf_ChairSetRecallDial_Ntf )
    BODY(mt::TBOOL32, bRecall)

    //<< �绰�˻�� ֪ͨ�����棬 ��������Ƿ��غ�>> -- add by zwf
    MESSAGE( Ev_MT_BLL_Conf_IsRecallDial_Ntf )
    BODY(mt::TString, tDialNum)   ////�绰����

    //<<��ϯ�ڽ���ѡ���Ƿ��غ������²�>> -- add by zwf
    MESSAGE( Ev_MT_BLL_Conf_RecallDial_Cmd )
    BODY(mt::TBOOL32, bRecall)
    BODY(mt::TString, tDialNum)

    //<<�²��յ���ϯ�ڽ�����غ�ѡ���֪ͨ���н���>> -- add by zwf
    MESSAGE( Ev_MT_BLL_Conf_IsRecallDialResult_Ntf )
    BODY(mt::TBOOL32, bRecall)
    BODY(mt::TString, tDialNum)


	////����gk����Ա�б����ڼ���
	MESSAGE( Ev_MT_BLL_Conf_GetGkRegMtList_Cmd )
	///gk�ظ�
	MESSAGE( Ev_MT_BLL_Conf_GetGkRegMtList_Ntf )
	BODY(mt::TRpMtInfo,       mt_info)             //�ն˱�����Ϣ
	BODY(mt::TBOOL32,         bfinished)           //�Ƿ����


    //<< ��ʼ�����ƶ�¼�� >> -- add by zwf
    MESSAGE( Ev_MT_BLL_Conf_StartSpareCloudRecord_Cmd )
    BODY(mt::TMtCallParam, record_param)

    //<< ֹͣ�����ƶ�¼�� >> -- add by zwf
    MESSAGE( Ev_MT_BLL_Conf_StopSpareCloudRecord_Cmd )
    BODY(mt::TU32, hangup_reason)

    //<< �����ƶ�¼��״̬֪ͨ >> -- add by zwf
    MESSAGE( Ev_MT_BLL_Conf_SpareCloudRecordState_Ntf )
    BODY(mt::TCloudRecordState, tCloudRecordState)
    
	//<< �����ƶ�¼��״̬֪ͨ >> -- add by zwf
	MESSAGE( Ev_MT_BLL_Conf_SpareCloudRecordState_Rsp )
	BODY(mt::TCloudRecordState, tCloudRecordState)


	//<< ֹͣ�����ƶ�¼�� >> -- add by zwf
	MESSAGE( Ev_MT_BLL_Conf_GetSpareCloudRecordState_Req )


	MESSAGE(Ev_MT_BLL_Conf_AuthResult_Ntf)       //��Ȩ���
	BODY(mt::TBOOL32,     bauthsuc)              //�Ƿ���Ȩ


	/*<<�Զ���ƵԴָʾ >>
	* tRpVideoInfo:    �Զ���ƵԴ����
	*/
	MESSAGE( Ev_MT_BLL_Conf_PeerVideoSrc_Ntf )
	BODY(TRpVideoInfo, tRpVideoInfo)

	/*<<ƽ̨�ظ��ն�tmtid������Ƶ�б� >>
	* tMtId       :    �ն�id
	* tRpVideoInfo:    ��ƵԴ����
	*/
	MESSAGE( Ev_MT_BLL_Conf_TerGetTerVideoAlias_Ntf )
	BODY(TMtId,        tMtId )
	BODY(TRpVideoInfo, tRpVideoInfo)


	/*<<��ǰ��������ƵԴ�б� >>
	* tRpVideoInfo:    ��ƵԴ����
	*/
	MESSAGE( Ev_MT_BLL_Conf_TerGetTerVideoAlias_Cmd )
	BODY(TMtId,        tMtId )
	

	/*<<�Զ���ƵԴָʾ >>
	* tRpVideoInfo:    �Զ���ƵԴ����
	*/
	MESSAGE( Ev_MT_BLL_Conf_PeerVideoSrc_Req )

	/*<<�Զ���ƵԴָʾ >>
	* tRpVideoInfo:    �Զ���ƵԴ����
	*/
	MESSAGE( Ev_MT_BLL_Conf_PeerVideoSrc_Rsp )
	BODY(TRpVideoInfo, tRpVideoInfo)


	/////UI����������ȥ
	MESSAGE(Ev_MT_BLL_Conf_SetCallCap_Cmd)    
	BODY(mt::TMtCap,     tCap)              //������
	BODY(mt::TU32,    tPro)              //����Э��

	////����dtmf����
	MESSAGE(Ev_MT_BLL_Conf_PasswordDtmf_Cmd)
	BODY(mt::TString, tPwd)

	//��ȡ��ǰ��ѯ�ն�����
	MESSAGE(Ev_MT_BLL_Conf_GetCurPollMt_Req)

	//��ȡ��ǰ��ѯ�ն���Ӧ
	MESSAGE(Ev_MT_BLL_Conf_GetCurPollMt_Rsp)
	BODY(mt::TMtId, tMt)

	///pc�Ƿ�enable fec
	MESSAGE(Ev_MT_BLL_Conf_Pc_EnableFec_Cmd)
	BODY(mt::TBOOL32, bEnable)

	///ͬ��sdk�㻺��
	MESSAGE(Ev_MT_BLL_Conf_SyncApplyerList_Ntf)
	BODY(mt::TU32,    type) //����
	
	/*<<peermt�ظ��ն�Ԥ��λ�б� >>
	*/
	MESSAGE( Ev_MT_BLL_Conf_TerCameroPos_Ntf )
	BODY(mt::TMTAllPreSetNameInfoCfg, tCfg)

	/*<<mc�ظ��ն�Ԥ��λ�б� >>
	*/
	MESSAGE( Ev_MT_BLL_Conf_TerGetTerCameraPos_Ntf )
	BODY(mt::TMtId, tMtId)
	BODY(mt::TMTAllPreSetNameInfoCfg, tCfg)


	/*<< ����һ·����>>
	* bOpen �������߹�
	* tPcRtcp �� pc��rtcp��ַ
	* emCodecType: ��������
	* emCodecIdx�� ��������
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_PlayStream_Cmd )
	BODY(mt:TBOOL32,  bOpen)                       //true : open��  false: close
	BODY(mt:TNetAddr, tPcRtcp)                     //pcRtcp��ַ  
	BODY(mt::TU32,   emCodecType)                  //emCodecType
	BODY(mt::TU32,   emCodecIdx)                   //emCodecIdx

	/*<<TT����IPW��ʽ����Ƶͨ�������ϱ�>>
	* codec_type ����������
	* encoder_id ����������
	* rtp_local_addr   ������rtp���ı��ص�ַ
	* rtcp_local_addr  �����ͽ���rtcp���ı��ص�ַ
	* rtp_remote_addr  ������rtp����Զ��Ŀ�ĵ�ַ
	* rtcp_remote_addr ������rtcp����Զ��Ŀ�ĵ�ַ
	* aud_enc_param ����Ƶ�������
	* bG7221Reverse : g7221��ת��־
	* payload : ��̬�غ�
	* key : ��Կ
	* ��Ϣ���� ��service==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_AudEncChanParam_Ntf )   //��Ƶͨ����������Ϣ
	BODY(mt::TS32, codec_type) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TNetAddr, rtp_local_addr)
	BODY(mt::TNetAddr, rtcp_local_addr)
	BODY(mt::TNetAddr, rtp_remote_addr)
	BODY(mt::TNetAddr, rtcp_remote_addr)
	BODY(mt::TAudEncDecParam, aud_enc_param)
	BODY(mt:TBOOL32,  bG7221Reverse) 
	BODY(mt::TDynamicPayload, payload) 
	BODY(mt::TEncryptKey, key)

	/*<<TT����IPW��ʽ����Ƶͨ�������ϱ�>>
	* codec_type ����������
	* encoder_id ����������
	* rtp_local_addr   ������rtp���ı��ص�ַ
	* rtcp_local_addr  �����ͽ���rtcp���ı��ص�ַ
	* rtp_remote_addr  ������rtp����Զ��Ŀ�ĵ�ַ
	* rtcp_remote_addr ������rtcp����Զ��Ŀ�ĵ�ַ
	* vid_enc_param ����Ƶ�������
	* payload : ��̬�غ�
	* key : ��Կ
	* ��Ϣ���� ��service==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_VidEncChanParam_Ntf )   //��Ƶͨ����������Ϣ
	BODY(mt::TS32, codec_type) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TNetAddr, rtp_local_addr)
	BODY(mt::TNetAddr, rtcp_local_addr)
	BODY(mt::TNetAddr, rtp_remote_addr)
	BODY(mt::TNetAddr, rtcp_remote_addr)
	BODY(mt::TVidEncParam, vid_enc_param)
	BODY(mt::TDynamicPayload, payload) 
	BODY(mt::TEncryptKey, key)

	/*<<TT����IPW��ʽ, �Ƿ�nat��Խ�ϱ�>>
	* codec_type ����������
	* encoder_id ����������
	* is_nattraversal   ���Ƿ�nat��Խ
	* rtp_local_addr   ������rtp���ı��ص�ַ
	* rtcp_local_addr  �����ͽ���rtcp���ı��ص�ַ
	* rtp_remote_addr  ������rtp����Զ��Ŀ�ĵ�ַ
	* rtcp_remote_addr ������rtcp����Զ��Ŀ�ĵ�ַ
	*��Ϣ���� ��service==>dispatch==>sdk
	*/
    MESSAGE( Ev_MT_BLL_Conf_IsNatTraver_Ntf )
	BODY(mt::TS32, codec_type)  //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, encoder_id)  //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TBOOL32, is_nattraversal) //�Ƿ�nat��Խ
	BODY(mt::TNetAddr, rtp_local_addr)
	BODY(mt::TNetAddr, rtcp_local_addr)
	BODY(mt::TNetAddr, rtp_remote_addr)
	BODY(mt::TNetAddr, rtcp_remote_addr)

	/*<<TT����IPW��ʽ, ��ʼ�����ϱ�>>
	* codec_type ����������
	* encoder_id ����������
	*��Ϣ���� ��service==>dispatch==>sdk
	*/
    MESSAGE( Ev_MT_BLL_Conf_StartEnc_Ntf )
	BODY(mt::TS32, codec_type) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	
	/*<<TT����IPW��ʽ, ֹͣ�����ϱ�>>
	* codec_type ����������
	* encoder_id ����������
	*��Ϣ���� ��service==>dispatch==>sdk
	*/
    MESSAGE( Ev_MT_BLL_Conf_StopEnc_Ntf )
	BODY(mt::TS32, codec_type) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<TT����IPW��ʽ, mcu�����ֱ���>>
	* codec_type ����������
	* encoder_id ����������
	* width : ���
	* height ���߶�
	*��Ϣ���� ��service==>dispatch==>sdk
	*/
    MESSAGE( Ev_MT_BLL_Conf_SetEncRes_Ntf )
	BODY(mt::TS32, codec_type) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TU16, width)
	BODY(mt::TU16, height)

	/*<<TT����IPW��ʽ, mcu����֡��>>
	* codec_type ����������
	* encoder_id ����������
	* fps : ֡��
	*��Ϣ���� ��service==>dispatch==>sdk
	*/
    MESSAGE( Ev_MT_BLL_Conf_SetEncFps_Ntf )
	BODY(mt::TS32, codec_type) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TU8,  fps)

	/*<<TT����IPW��ʽ, ���ñ�������>>
	*codec_type ����������
	*encoder_id ����������
	*bitrate    ������
	*��Ϣ���� ��service==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_SetBitrate_Ntf )
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TU16, bitrate)

	/*<<TT����IPW��ʽ, ����ؼ�֡>>
	*codec_type ����������
	*encoder_id ����������
	*��Ϣ���� ��service==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_FastUpdate_Ntf )
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<����ǰ�����������>>
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetEncryptType_Req )

	/*<<��ǰ�������������Ӧ>>
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetEncryptType_Rsp )    
	BODY(mt::TU32, tdwEncryptType)   //mt::EmSrtpCryptoType 

	/*<<����ǰ����callid>>
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetCallId_Req )

	/*<<��ǰ����callid��Ӧ>>
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetCallId_Rsp )
	BODY(mt::TString, tStrCallId)

	/*<<ͨ��osd����/�ر�pc˫�������ʱ����sky100��sky100��֧��Ӳ˫��>>
	* bOpen �������߹�
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_OsdCtrlPcAssStream_Cmd )
	BODY(mt:TBOOL32,  bOpen)                       //true : open��  false: close

	/*<<<ͨ��osd����/�ر�pc˫��֪ͨ>>
	* bOpen �������߹�
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_OsdCtrlPcAssStream_Ntf )
	BODY(mt:TBOOL32,  bOpen)                       //true : open��  false: close
	
	/*<<<����ȡ������֪ͨ>>
	* ��Ϣ���� ��mp==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_ConfNotKeepAlive_Ntf )

	/*<<�Ƿ���ƽ̨���ն��б�>>
	*��Ϣ���� ui -> mtservice
	*/
	MESSAGE( Ev_MT_BLL_Conf_SubMtList_Cmd )
	BODY(mt:TBOOL32,  bSub ) 

	MESSAGE( Ev_MT_BLL_Conf_SrtpCrypto_Ntf)     ///��srtp��һЩ������������
	BODY(mt::TSrtpCrypto,     tSrtpCrypto) 


	/*<<��ȡ�Ƿ�ر���������>>
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetCloseMainVid_Req)             

	/*<<<��ȡ�Ƿ�ر�������Ӧ>>
	* bClose ���Ƿ������
	* ��Ϣ���� ��conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetCloseMainVid_Rsp )
	BODY(mt:TBOOL32,  bClose)                       //true : close��

	/*<<����ͷ�Ƿ�����������ѯ>>
	*��Ϣ���� : sdk==>dispatch==>device
	*/
	MESSAGE(Ev_MT_BLL_GetIsCameraUpgrading_Req)

	/*<<����ͷ�Ƿ�����������ѯ�ظ�>>
	*is_upgrading : TRUE��ʾ����������FALSE��ʾ��������
	*��Ϣ���� : device==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_GetIsCameraUpgrading_Rsp)
	BODY(mt::TBOOL32, is_upgrading)

	/*<<���³��̼��������Ϣ>>
	*��Ϣ���� : conf==>dispatch==>device
	*/
	MESSAGE(Ev_MT_BLL_Conf_SetVendorCheckConfig_Cmd)
	BODY(mt::TVendorCheckConfig,  tVenCheckCfg)

	/*<<���³��̼��������Ϣ֪ͨ>>
	*��Ϣ���� : device==>dispatch==>conf
	*/
	MESSAGE(Ev_MT_BLL_Conf_SetVendorCheckConfig_Ntf)
	BODY(mt::TBOOL32,  is_peerkdvdevice)

	
#if !defined(_MESSAGE_HELP_)
	EV_BLL_END(CONF) = EVSEG_BLL_CONF_END
};
#endif

#define Is_BLL_Mtconf_Msg(m) ((m) >= EV_BLL_BGN(CONF) && (m) <= EV_BLL_END(CONF))

#endif