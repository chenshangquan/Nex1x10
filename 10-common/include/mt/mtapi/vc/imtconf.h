/**===========================================================================
 * @file    $Id$
 * @brief   �����ն˻����صĽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTCONF_H_
#define _I_MTCONF_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_vc.h"
#include "mtapi_container.h"



/**---------------------------------------------------------------------------
 * @class   Interface IMtConf
 * @brief   �����ն˻����صĽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtConf : public IMtApiIF
{
public:
	//��������
	virtual u32 MakeCallCmd( const s8* pszCalledInfo, const u16 wRate, const EmConfProtocol_Api emPro ) = 0;
	//���� �ϲ�ָ����������
	virtual u32 MakeCallCmd( const TMtAddr_Api tCalledAddr, const u16 wRate, const EmConfProtocol_Api emPro ) = 0;
	//ͨ��setup��������
	virtual u32 SetupCreateConf(  const TMtSetupCreateConfParam_Api& tCallParam ) = 0;

	//�ֶ�����
	virtual u32 AcceptCmd() = 0;
	//�ܾ�����
	virtual u32 RejectConfCmd() = 0;
	//�Ҷϻ��飬�����ֵ�Ե�Ͷ��
	virtual u32 HangupConfCmd( const EmMtCallDisReason_Api emReason ) = 0; 
	//��ǰ����״̬����
	virtual u32 GetConfLinkStateReq() = 0;
	//��������б�
	virtual u32 GetConfListReq( const u32 dwCmdType ) = 0;
	//����������
	virtual u32 JoinConfCmd( CONST TMtJoinConfParam_Api& tCallParam ) = 0;
	//���󴴽�����
	virtual u32 CreateConfCmd( const TMtCreateConfParam_Api& tCallParam ) = 0;
	//���������ϸ��Ϣ 
	virtual u32 GetConfDetailCmd( const s8* pszConfE164 ) = 0;
	//������������� 
	virtual u32 GetConfListNumCmd() = 0;
	//����ǰ�������������ն� 
	virtual u32 GetOnLineTerListReq() = 0;
	//����ǰ�������в������ն� 
	virtual u32 GetOffLineTerListReq() = 0;
	//������Ϣ����
	virtual u32 GetConfInfoCmd( ) = 0;
	//������Ϣ����
	virtual u32 GetConfInfoReq( ) = 0;
	//����label����
	virtual u32 GetSelfLabelReq( ) = 0;

	//�����ͣ�����˫��״̬
	virtual u32 GetAssSndVidStatusReq() = 0;
	virtual u32 GetAssRcvVidStatusReq() = 0;

	//������������
	virtual u32 SetConfPwdCmd( const s8* pszPwd ) = 0;
	//�Ҷϻ����ն�
	virtual u32 DropConfTerCmd( const TMtId_Api& tMtId ) = 0;
	//��������
	virtual u32 EndConfCmd() = 0;
	//��ϯ�ӳ�����
	virtual u32 ProlongConfTimeCmd( const u16 wTime ) = 0;
	//��ϯ�����ն�
	virtual u32 InviteTerCmd( const TMtAddr_Api& tAddr, const BOOL32 bVideoCall ) = 0;
	//��ϯ���������ն�
	virtual u32 CallOffLineTerCmd( const TMtId_Api& tAddr ) = 0;
	//����264֧�ֵķֱ���
	virtual u32 AdjustH264Res( const EmMtResolution_Api *ptRes, const u32 dwResNum ) = 0;
	//�л���Ƶ+˫��ģʽ
	virtual u32 MainVideoOff( ) = 0;
	//�޸Ļ�������
	virtual u32 ModifyConfNameCmd( const s8* pszConfName ) = 0;
	//�޸Ļ���ϳ��Ƿ���ʾ����
	virtual u32 ModifyVmpShowAliasCmd( const BOOL32 bShow ) = 0;

	////����Э��ջ��׼�Ǳ�
	virtual u32 SetStack( const BOOL32 bStand, const EmConfProtocol_Api emPro ) = 0;

	//����Э��ջ
	virtual u32 StackOnOff( const BOOL32 bStart, const EmConfProtocol_Api emPro) = 0;

	//�޸Ļ���ʱ��
	virtual u32 ModifyConfTimeCmd( const u16 wTime ) = 0;
	
	virtual u32 SetConfDumb( const BOOL32 bDumb ) = 0;
	virtual u32 SetConfNoDisturb( const BOOL32 bEnable ) = 0;
	//�޸Ļ�������
	virtual u32 ModifyConfPwdCmd( const BOOL32 bUsedPwd, const s8*  pszPwd ) = 0;
	//�޸�˫����������
	virtual u32 SetAssStreamSendModCmd( const u32 dwMode ) = 0;
	//���뷢�Բ���
	virtual u32 ApplySpeakerCmd() = 0;
	//��ϯͬ��ĳ�ն˵����뷢��
	virtual u32 AccpetSpeakerCmd( const TMtId_Api& tMtId ) = 0;
	//�ܾ����뷢�Բ���
	virtual u32 RejectApplySpeakerCmd() = 0;
	//��ϯָ�������ն�
	virtual u32 ChairSpecSpeakerCmd( const TMtId_Api& tMtId ) = 0;

	//��ϯȡ��������
	virtual u32 ChairWithDrawSpeakerCmd() = 0;
    //��ȡ���ڹۿ�����ƵԴ
	virtual	u32 GetVideoSeeingReq() = 0;
	//������ϯ����
	virtual u32 ApplyChairmanCmd() = 0;
	//�ܾ�������ϯ����
	virtual u32 RejectApplyChairmanCmd() = 0;
	//�ͷ���ϯȨ��
	virtual u32 WithDrawChairmanCmd() = 0;
	//��ϯ�ն˲�ѯ
	virtual u32 WhoIsChairCmd() = 0;
	//��ϯָ������ϯ�ն�
	virtual u32 ChairSpecNewChairCmd( const TMtId_Api& tMtId  ) = 0;
	//��ϯָ��vip�ն�
	virtual u32 ChairSpecVipCmd( const TMtId_Api* ptMtId, const u32 dwNum  ) = 0;

	///��ϯָ���ն˷�˫��
	virtual u32 ChairSpecTerSendAssCmd( const TMtId_Api& tMtId ) =0;
	virtual u32 ChairSpecTerSendAssParamReq( ) =0;

	virtual u32 GetVipList( TMtId_Api* ptMtId, u32 &dwNum ) = 0;

	virtual u32 GetVipListReq( ) = 0;

	//�ն�ѡ��
	virtual u32 SeeSpecTerCmd( const TViewTerParam_Api &tParam) = 0;

	virtual u32 SeeSpecTerAss( const TMtId_Api& tMtId ) = 0;

	//ȡ��ѡ��
	virtual u32 CancelSeeTerCmd() = 0;
	//����廰
	virtual u32 ApplyChimeCmd() = 0;

	//�ܾ�����廰
	virtual u32 RejectApplyChimeCmd() = 0;

	//��ϯͬ��廰
	virtual u32 AcceptChimeCmd( const TMtId_Api& tMtId ) = 0;
	//��ϯָ���廰�ն�
	virtual u32 ChairSpecChimeCmd( const TMtId_Api& tMtId ) = 0;
	//��ϯ��ѯ
	virtual u32 MtChairPollCmd( const TMtPollInfo_Api& tMtPollInfo ) = 0;
	//��ȡָ���ն˵�״̬��Ϣ ui->sdk->ƽ̨->sdk
	virtual u32 GetSpecTerStatusCmd( const TMtId_Api& tMtId ) = 0;
	//��ȡָ���ն˵�ǰ״̬��Ϣ ui->sdk
	virtual	u32  GetMtStatusByMtID( TMtEntityStatus_Api& tEntityStatusTmp, const TMtId_Api&  tMtId ) = 0;
	//��ȡָ���ն��б�״̬��Ϣ
	virtual u32 GetTerListStatusReq() = 0; 
	//��ϯǿ�ƹ㲥
	virtual u32 StartForceBroadcastCmd() = 0;
	//��ϯֹͣǿ�ƹ㲥
	virtual u32 StopForceBroadcastCmd() = 0;
	//��ʼ��������
	virtual u32 StartVacCmd() = 0;
	//ֹͣ��������
	virtual u32 StopVacCmd() = 0;
	//��ʼ����ģʽ
	virtual u32 StartDiscussCmd() = 0;
	//ֹͣ����ģ��
	virtual u32 StopDiscussCmd() = 0;

	///��ʼ��������ϳ�
	virtual u32 StartCustomVMPCmd( const TMtCustomVmpParam_Api& tMtVmpParam ) = 0;
	//ֹͣ��������ϳ�(��ϯ)
	virtual u32 StopCustomVMPCmd() = 0;
	//������������ϳɲ�����Ϣ
	virtual u32 SetCustomVMPParamCmd( const TMtCustomVmpParam_Api& tMtVmpParam ) = 0;

	//��ʼ���黭��ϳ�(��ϯ)
	virtual u32 StartConfVMPCmd( const TMtVmpParam_Api& tMtVmpParam ) = 0;
	//ֹͣ���黭��ϳ�(��ϯ)
	virtual u32 StopConfVMPCmd() = 0;
	//���û���ϳɲ�����Ϣ
	virtual u32 SetConfVMPParamCmd( const TMtVmpParam_Api& tMtVmpParam ) = 0;
	//��ȡ����ϳɲ���
	virtual u32 GetConfVMPParamCmd() = 0;
	//Զ������
	virtual u32 SetTerMuteCmd( const TMtId_Api& tMtId, const BOOL32 bMute ) = 0;	
	//Զ�˾���
	virtual u32 SetTerQuiteCmd(const TMtId_Api& tMtId, const BOOL32 bQuiet ) = 0;
	//�л�����ϳɷ��
	virtual u32 SwitchBroadCastStyleCmd( const BOOL32 bSingle ) = 0;
	//�ն�ѡ������ϳ�����(������ϯMT)
	virtual u32 SelectVmpCmd( const BOOL32 bStart ) = 0;
	
	//��ʼ���ƻ���
	virtual u32 StartCustomMixCmd( const TMtId_Api* ptArrMt, const u8 byCount ) = 0;
	//ֹͣ���ƻ���
	virtual u32 StopCustomMixCmd() = 0;

	//��ӻ�����Ա
	virtual u32 AddMixMemberCmd( const TMtId_Api* ptArrMt, const u8 byCount ) = 0;
	//ɾ��������Ա
	virtual u32 RemoveMixMemberCmd(const TMtId_Api* ptArrMt, const u8 byCount ) = 0;
	//��ȡ������Ա�б�����
	virtual u32 GetMixMemberListReq() = 0;
	//����Ϣ����
	virtual u32 SendConfSmsCmd( const TShortMsg_Api& tShortMsg ) = 0;

	//Fxo����
	virtual u32 FxoMakeCallCmd( const s8 * pchPeerNumber ) = 0;
	//Fxo���ܺ���
	virtual u32 FxoAcceptCmd( ) = 0;
	//Fxo�ܾ�����
	virtual u32 FxoRejectCmd( ) = 0;
	//Fxo�Ҷϵ绰
	virtual u32 FxoHangupCmd( ) = 0;

	//�װ���鴴��֪ͨ mt -> mcu
	virtual u32 DataConfCreatedNtf( const s8* pszConf_name, const s8* pszConf_e164 ) = 0;
	//����װ���������Ե� mt -> mt
	virtual u32 P2PJoinDataConfCmd( const s8* pszConf_name, const s8* pszStr ) = 0;

    //����ƽ̨¼����-- add by zwf
    virtual u32 RemoteRecodeCmd( const BOOL32 bStart ) = 0;

	///��ȡ��ϵ���б�
	virtual u32 GetGkMtlist() = 0; 
	virtual u32 GetCloseMainVidReq() = 0;
public:
	//�Ƿ��Ե������
	virtual BOOL32 IsInP2PConf() = 0;	
	//�Ƿ��Ե������
	virtual BOOL32 IsInMulConf() = 0;
	//�Ƿ��ڻ�����
	virtual BOOL32 IsInConf() = 0;
	//�Ƿ����/��������
	virtual BOOL32 IsCalling() = 0;

	//��ȡ��ǰ��������״̬��Ϣ
	virtual TMtAssVidStatusList_Api GetCurAssSndVidStatus() = 0;
	//��ȡ��ǰ��������״̬��Ϣ
	virtual TMtAssVidStatusList_Api GetCurAssRcvVidStatus() = 0;
	
	//��ǰ�����Ƿ����
	virtual BOOL32 IsEncryptConf() = 0;

	//����ǰ�����Ƿ����
	virtual BOOL32 IsEncryptConfReq() = 0;
	//��ȡ���ݼ������͵�����
	virtual BOOL32 GetEncryptTypeReq() = 0;
	//�����ն��Ƿ��ڲ廰
	virtual BOOL32 IsInChime() = 0;
	//�����ն��Ƿ��Զ������
	virtual BOOL32 IsCustomMix() = 0;
	//�Ƿ�����ϯ����Ļ���ϳ���
	virtual BOOL32 IsInChairVmp() = 0;
	//�Ƿ�����������ϳ���
	virtual BOOL32 IsInCustomVmp() = 0;
	//�Ƿ�����������
	virtual BOOL32 IsInVAC() = 0;
	//�Ƿ�����ѯ��
	virtual BOOL32 IsInPoll() = 0;
	//��ȡ��ǰ������ѯ���ն�
	virtual TMtId_Api GetPollingMt() = 0;
	//�Ƿ���ѡ��
	virtual BOOL32 IsViewMt() = 0;	
	virtual TViewTerParam_Api GetViewMtParam() = 0;
	//ѡ������
	virtual u32 GetViewMtParamReq() = 0;

	//�Ƿ��������ģʽ
	virtual BOOL32 IsDiscussMode() = 0;
	//�Ƿ���ϯѡ������ϳ�
	virtual BOOL32 IsInChairSelVmp() = 0;
	virtual BOOL32 IsSeeSpecTerAss() = 0;
	//��ȡ���õ��ܵĻ���������
	virtual u32 GetTotalRoomNum() = 0;
	//��ȡ���õĻ���������
	virtual u32 GetUsedRoomNum() = 0;
	//��ȡ�������鵽��ʱʱ��
	virtual u32 GetConfRemainTime() = 0;
	//��ȡ�����д���ĺ�����Ϣ
	virtual TMtMissCallParam_Api GetMissedCallParam( ) = 0;
	//��ȡ�Լ���mtid��Ϣ
	virtual TMtId_Api GetSelfMtID() = 0;
	//��ȡ�Զ˵�������Ϣ
	virtual TPeerCapabilityInfo_Api GetPeerCapInfo() = 0;
	//��ȡ��ǰ������Ϣ
	virtual TMtConfInfo_Api GetCurConfInfo() = 0;

	virtual TMultiVideoAlias_Api GetPeerVidAlias() = 0;
	
	virtual u32  GetPeerVidAliasReq() = 0; 


	virtual TMultiVideoInfo_Api GetPeerVidSrc() =0;
	virtual u32  GetPeerVidSrcReq() = 0;
	virtual u32 GetTerVidAlias(const TMtId_Api &tMtid) = 0;
	virtual TMtCallLinkSate_Api GetCurCallInfo()=0;
	//��ȡ��ǰ�򵥻�����Ϣ
	virtual TMtSimpConfInfo_Api GetCurSimpConfInfo() = 0;

	virtual TMtConfDetailInfo_Api GetConfDetialInfo() = 0;

	//��ȡ�����ն�
	virtual TMtId_Api GetSpeaker() = 0;
	//��ȡ��ϯ�ն�
	virtual TMtId_Api GetChairman() = 0;
	//��ȡѡ���ն�
	virtual TMtId_Api GetSeenMt() = 0;
	//��ȡ��ǰ��ƵԴ
	virtual TMtId_Api GetVideoSrcMt( EmCodecComponentIndex_Api emChanIdx = em1st_Api ) = 0;
	//��ȡ����������Ϣ
	virtual TMtMixParam_Api GetMixParam() = 0;
	//��ȡ���黭��ϳɲ�����Ϣ
	virtual TMtVmpParam_Api GetConfVmpParam() = 0;
	//��ȡ��������ϳɲ�����Ϣ
	virtual TMtCustomVmpParam_Api GetCustomVmpParam() =0;
	//��ȡ��ѯ����
	virtual TMtPollInfo_Api GetCurPollParam() = 0;
	virtual u32 GetPollParamReq() = 0;
	//��ȡ��������ϳɲ�����Ϣ
	virtual u32 GetCustomVmpParamReq() =0;

	//��ȡ�û��������
	virtual u32 GetConfListCnt( const EmConfListType_Api emConfListType ) = 0;
	//��ȡ�û������б�
	virtual u32 GetConfList( const u32 dwStartIdx,  TMtConfNameInfo_Api* ptOutBuf, u32& dwCnt, const EmConfListType_Api emConfListType ) = 0;
	//��ȡ����Ա����
	virtual u32 GetConfMtMemberCnt() = 0;
	//��ȡ����Ա�б�
	virtual u32 GetConfMtMember( const u32 dwStartIdx,  TMTEntityInfo_Api* ptOutBuf, u32& dwCnt ) = 0;
	virtual TMTEntityInfo_Api GetEntityInfo( const TMtId_Api & tMtid ) = 0;

	//��ȡ����Ա״̬����
	virtual u32 GetConfMtMemberStatusCnt() = 0;
	//��ȡ����Ա״̬�б�
	virtual u32 GetConfMtMemberStatus( const u32 dwStartIdx,  TMtEntityStatus_Api* ptOutBuf, u32& dwCnt ) = 0;
	//��ȡ���뷢�Ը���
	virtual u32 GetApplySpeakerListCnt() = 0;
	//��ȡ������ϯ����
	virtual u32 GetApplyChairmanListCnt() = 0;
	//��ȡ����廰����
	virtual u32 GetApplyChaimeInListCnt() = 0;
	//��ȡ���뷢�����б�
	virtual u32 GetApplySpeakerList( const u32 dwStartIdx,  TMtId_Api* ptOutBuf, u32& dwCnt ) = 0;
	//��ȡ������ϯ�б�
	virtual u32 GetApplyChairmanList( const u32 dwStartIdx,  TMtId_Api* ptOutBuf, u32& dwCnt ) = 0;
	//��ȡ����廰�б�
	virtual u32 GetApplyChaimeInList( const u32 dwStartIdx,  TMtId_Api* ptOutBuf, u32& dwCnt ) = 0;

public:
	//��ȡ�Ƿ�绰�˻���غ�
	virtual BOOL32 GetRecallDial( ) = 0;
    //���õ绰�˻���غ�-- add by zwf
    virtual u32 SetRecallDial( const BOOL32 bRecall ) = 0;
    //�����绰�˻���Ƿ��غ�--add by zwf
    virtual u32 DetermineRecallDial( const BOOL32 bRecall, const s8 *pchDialNum ) = 0;


    //��ʼ�����ƶ�¼������ -- add by zwf
    virtual u32 StartSpareCloudRecordCmd( const s8* pszRecordInfo, const u16 wRate, const EmConfProtocol_Api emPro ) = 0;
    //ֹͣ�����ƶ�¼������ -- add by zwf
    virtual u32 StopSpareCloudRecordCmd( const EmMtCallDisReason_Api emReason ) = 0;
	virtual TCloudRecordState_Api GetCurSpareCloudRecordState() =0;
	virtual TMtId_Api GetDualStreamSenderMt() =0;
	virtual u32 GetSpareCloudRecordStateReq() = 0;
	virtual u32 SetCallCap( const TMtSendCap_Api &tSendCap, const TMtRecvCap_Api &tRecvCap, const EmConfProtocol_Api emPro ) =0;
	virtual u32 GetCurPollMtReq() = 0;
	virtual u32 GetDualStreamSenderReq() = 0;
	virtual u32 SetPasswordDtmf(const s8 *pszPasswordDtmf) = 0;

	virtual u32 GetTerCameroPos(const TMtId_Api &tMtid) = 0;
	virtual u32 GetCallIdReq() = 0;
	virtual u32 SetSubMtList( const BOOL32 bSub ) =0;

};

#endif // _I_MTCONF_H_