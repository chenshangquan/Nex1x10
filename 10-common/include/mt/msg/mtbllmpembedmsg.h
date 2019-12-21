#ifndef _MTBLLMPEMBEDMSG_H_
#define _MTBLLMPEMBEDMSG_H_

#include "mtmsgid.h"
#include "struct.pb.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMPEmbedMsg
{
    EV_BLL_BGN(MPEMBED) = EVSEG_BLL_MPEMBED_BGN,
#endif
	
	/*<<��������>>
	*��Ϣ���� ��misc==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecDspSleep_Req)

	/*<<������Ӧ>>
	*��Ϣ���� ��misc==>dispatch==>mtmp
	* is_sucess: �Ƿ��������
	* fail_reason: ����ʧ��ԭ��
	*/
    MESSAGE(Ev_MT_BLL_CodecDspSleep_Rsp)
	BODY(mt::TBOOL32, is_sucess)
	BODY(mt::TS32, fail_reason) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmSleepFailReason

	/*<<��������>>
	*��Ϣ���� ��misc==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecDspWakeup_Cmd)

	/*<<����״̬�ϱ�>>
	*��Ϣ���� ��misc==>dispatch==>mtmp
	*is_sleep : TRUE��ʾ����˯��״̬��FALSE��ʾ���뻽��״̬
	*/
    MESSAGE(Ev_MT_BLL_CodecSleepState_Ntf)
	BODY(mt::TBOOL32, is_sleep)

	/*<<����ʧ��ԭ���ϱ�>>
	*��Ϣ���� ��misc==>dispatch==>mtmp
	*fail_reason : ʧ��ԭ��
	*/
    MESSAGE(Ev_MT_BLL_CodecSleepFailReason_Ntf)
	BODY(mt::TS32, fail_reason) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmSleepFailReason

	/*<<��������������������Ч��������>>
	*sound_type : �������� ������������Ч��������Ч
	*sound_id : ������ʶ
	*play    ��TRUE-���� FALSE-ֹͣ����
	*��Ϣ���� ��sdk==>mtservice
	*see Ev_MT_BLL_CodecLocalSoundPlay_Ntf
	*/
    MESSAGE(Ev_MT_BLL_CodecLocalSoundPlay_Cmd)
	BODY(mt::TS32, sound_type) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmLocalSoundType
	BODY(mt::TS32, sound_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmLocalSoundIndex
	BODY(mt::TBOOL32, play)

    /*<<��������������������Чֻ����һ������>>
	*sound_type : �������� ������������Ч��������Ч
	*sound_id : ������ʶ
	*play    ��TRUE-���� FALSE-ֹͣ����
	*��Ϣ���� ��sdk==>mtservice
	*see Ev_MT_BLL_CodecLocalSoundPlay_Ntf
	*/
    MESSAGE(Ev_MT_BLL_CodecLocalSoundPlayOnce_Cmd)
	BODY(mt::TS32, sound_type) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmLocalSoundType
	BODY(mt::TS32, sound_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmLocalSoundIndex
	BODY(mt::TBOOL32, play)

	/*<<��������������������Ч����״̬��ʾ>>
	*sound_type : �������� ������������Ч��������Ч
	*sound_id : ������ʶ
	*play    ��TRUE-���� FALSE-ֹͣ����
	*��Ϣ���� ��mtservice==>sdk
	*see Ev_MT_BLL_CodecLocalSoundPlay_Cmd
	*/
    MESSAGE(Ev_MT_BLL_CodecLocalSoundPlay_Ntf)
	BODY(mt::TS32, sound_type) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmLocalSoundType
	BODY(mt::TS32, sound_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmLocalSoundIndex
	BODY(mt::TBOOL32, play)

	/*<<����������������Ч��������Ч���Ų�ѯ����(������Ч�Ͷ�����Ч�����Ǹ��̲�������ʱ���ṩ��ѯ)>>
	*sound_type : �������� ������������Ч��������Ч
	*sound_id : ������ʶ
	*play    ��TRUE-���� FALSE-ֹͣ����
	*��Ϣ���� ��sdk==>mtservice
	*see Ev_MT_BLL_CodecGetLocalSoundPlayState_Rsp
	*/
    MESSAGE(Ev_MT_BLL_CodecGetLocalSoundPlayState_Req)
	BODY(mt::TS32, sound_type) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmLocalSoundType
	BODY(mt::TS32, sound_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmLocalSoundIndex

	/*<<����������������Ч��������Ч���Ų�ѯ��Ӧ(������Ч�Ͷ�����Ч�����Ǹ��̲�������ʱ���ṩ��ѯ)>>
	*sound_type : �������� ������������Ч��������Ч
	*sound_id : ������ʶ
	*play    ��TRUE-���� FALSE-ֹͣ����
	*��Ϣ���� ��mtservice==>sdk
	*see Ev_MT_BLL_CodecGetLocalSoundPlayState_Req
	*/
    MESSAGE(Ev_MT_BLL_CodecGetLocalSoundPlayState_Rsp)
	BODY(mt::TS32, sound_type) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmLocalSoundType
	BODY(mt::TS32, sound_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmLocalSoundIndex
	BODY(mt::TBOOL32, play)

	/*<<���ö໭��������>>
	*��Ϣ���� ��sdk==>dispatch==>mtservice
	*see Ev_MT_BLL_CodecSetPIP_Rsp
	*/
    MESSAGE(Ev_MT_BLL_CodecSetPIP_Req)
	BODY(mt::TMtPIPMode, pip_mode)

	/*<<���ö໭������Ӧ>>
	*��Ϣ���� ��mtservice==>dispatch==>sdk
	*see Ev_MT_BLL_CodecSetPIP_Req
	*/
    MESSAGE(Ev_MT_BLL_CodecSetPIP_Rsp)
	BODY(mt::TMtPIPMode, pip_mode)

	/*<<��ѯ�໭��������>>
	*��Ϣ���� ��sdk==>dispatch==>mtservice
	*see Ev_MT_BLL_CodecQueryPIP_Rsp
	*/
    MESSAGE(Ev_MT_BLL_CodecQueryPIP_Req)

	/*<<��ѯ�໭������Ӧ>>
	*��Ϣ���� ��mtservice==>dispatch==>sdk
	*see Ev_MT_BLL_CodecQueryPIP_Req
	*/
    MESSAGE(Ev_MT_BLL_CodecQueryPIP_Rsp)
	BODY(mt::TMtPIPMode, pip_mode)

	/*<<�໭����״̬֪ͨ>>
	*��Ϣ���� ��mtservice==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecPIPState_Ntf)
	BODY(mt::TMtPIPMode, pip_mode)

	/*<<�������л�����>>
	*��Ϣ���� ��sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecSwitchPIP_Cmd)

	/*<<ɫ����������>>
	*on ������orֹͣ
	*��Ϣ���� ��sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecRibbonTest_Cmd)
	BODY(mt::TBOOL32, on)

	/*<<ɫ������״̬֪ͨ>>
	*on ���Ƿ���ɫ������
	*��Ϣ���� ��mtmp==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecRibbonTest_Ntf)
	BODY(mt::TBOOL32, on)		

	/*<<ɫ������״̬��ѯ����>>
	*��Ϣ���� ��sdk==>dispatch==>mtmp
	* see Ev_MT_BLL_CodecRibbonTestStatus_Rsp
	*/
    MESSAGE(Ev_MT_BLL_CodecRibbonTestStatus_Req)

	/*<<ɫ������״̬��ѯ��Ӧ>>
	*on ���Ƿ���ɫ������
	*��Ϣ���� ��mtmp==>dispatch==>sdk
	* see Ev_MT_BLL_CodecRibbonTestStatus_Req
	*/
    MESSAGE(Ev_MT_BLL_CodecRibbonTestStatus_Rsp)
	BODY(mt::TBOOL32, on)		

	/*<<���û���ϳɷ��>>
	*vmp_type ������ϳɷ��
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VMPSetType_Cmd)
	BODY(mt::TU32, vmp_type)

	/*<<���÷��͵�ַ>>
	*send_addr �����úϳ���Ƶ�ķ��͵�ַ
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VMPSetSendAddr_Cmd)
	BODY(mt::TNetAddr, send_addr)

	/*<<���úϳ���Ƶ�ı������>>
	*vid_enc_param ���������
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VMPSetVidEncParam_Cmd)
	BODY(mt::TVidEncParam, vid_enc_param)

	/*<<��ʼ����ϳ�>>
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VMPStart_Cmd)

	/*<<ֹͣ����ϳ�>>
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VMPStop_Cmd)

	/*<<��Ӻϳɳ�Ա>>
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VMPAddMem_Cmd)
	BODY(mt::TMultiVMPMemParam, vmp_memparams)

	/*<<ɾ���ϳɳ�Ա>>
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VMPDelMem_Cmd)
	BODY(mt::TMultiU32, chan_indexs)//���Ǹ�repeated��

	/*<<���͹ؼ�֡>>
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VMPSendFastUpdate_Cmd)

	/*<<������������>>
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VMPSetBitrate_Cmd)
	BODY(mt::TU16, bitrate)


	//mixer
	/*<<���û������>>
	*mixer_depth ���������
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_MixerSetDepth_Cmd)
	BODY(mt::TU32, mixer_depth)
	/*<<���÷��͵�ַ>>
	*send_addr �����úϳ���Ƶ�ķ��͵�ַ
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_MixerSetSendAddr_Cmd)
	BODY(mt::TNetAddr, send_addr)
	/*<<���û����ı������>>
	*vid_enc_param ���������
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_MixerSetVidEncParam_Cmd)
	BODY(mt::TAudEncDecParam, Aud_enc_param)
	/*<<��ʼ����>>
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_MixerStart_Cmd)

	/*<<ֹͣ����>>
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_MixerStop_Cmd)

	/*<<��ӻ�����Ա��Ա>>
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_MixerAddMem_Cmd)
	BODY(mt::TMultiMixerMemParam, mixer_memparams)

	/*<<ɾ���ϳɳ�Ա>>
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_MixerDelMem_Cmd)
	BODY(mt::TMultiU32, chan_indexs)//���Ǹ�repeated��

	/*<<���������Ի�>>
	*���䷽��mtsdk->mtservice->mtmp
	* see Ev_MT_BLL_LocalLoop_Ntf
	*/
	MESSAGE( Ev_MT_BLL_LocalLoop_Cmd )
	BODY(mt::TBOOL32,   bStart)

	/*<<���������Ի���Ӧ>>
	*���䷽��mtmp->mtservice->mtsdk
	* see Ev_MT_BLL_LocalLoop_Cmd
	*/
	MESSAGE( Ev_MT_BLL_LocalLoop_Ntf)
	BODY(mt::TBOOL32,   bStart)

	/*<<��ȡ�����Ի�״̬����>>
	*���䷽��mtsdk->mtservice->mtmp
	* see Ev_MT_BLL_GetLocalLoopState_Rsp
	*/
	MESSAGE( Ev_MT_BLL_GetLocalLoopState_Req )

	/*<<��ȡ�����Ի�״̬��Ӧ>>
	*���䷽��mtmp->mtservice->mtsdk
	* see Ev_MT_BLL_GetLocalLoopState_Req
	*/
	MESSAGE( Ev_MT_BLL_GetLocalLoopState_Rsp)
	BODY(mt::TBOOL32,   bStart)

	/*<<��ȡ��Ƶ Զ���Ի�״̬����>>
	*���䷽��mtsdk->mtservice->mtmp
	* see Ev_MT_BLL_GetRemoteLoopState_Rsp
	*/
	MESSAGE( Ev_MT_BLL_GetRemoteLoopState_Req )

	/*<<��ȡ��Ƶ Զ���Ի�״̬��Ӧ>>
	*���䷽��mtmp->mtservice->mtsdk
	* see Ev_MT_BLL_GetRemoteLoopState_Req
	*/
	MESSAGE( Ev_MT_BLL_GetRemoteLoopState_Rsp)
	BODY(mt::TS32, codec_type)//mt::EmCodecComponent
	BODY(mt::TS32, codec_id)//mt::EmCodecComponentIndex
	BODY(mt::TBOOL32,   bStart)

	/*<<��·��������Ի�>>
	*���䷽��mtsdk->mtservice->mtmp
	* see Ev_MT_BLL_LocalSingleLoop_Ntf
	*/
	MESSAGE( Ev_MT_BLL_LocalSingleLoop_Cmd )
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TBOOL32,   bStart)

	/*<<��·��������Ի�>>
	*���䷽��mtmp->mtservice->mtsdk
	* see Ev_MT_BLL_LocalSingleLoop_Cmd
	*/
	MESSAGE( Ev_MT_BLL_LocalSingleLoop_Ntf)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TBOOL32,   bStart)
	
	/*<<��Ƶ�Ի�>>
	*���䷽��mtsdk/mtmfgtest->mtservice
	* see Ev_MT_BLL_AudioLoop_Ntf
	*/
	MESSAGE( Ev_MT_BLL_AudioLoop_Cmd )
	BODY(mt::TBOOL32,   bStart)

	/*<<��Ƶ�Ի�״̬��ʾ>>
	*���䷽��mtservice->mtsdk/mtmfgtest
	* see Ev_MT_BLL_AudioLoop_Cmd
	*/
	MESSAGE( Ev_MT_BLL_AudioLoop_Ntf)
	BODY(mt::TBOOL32,   bStart)

	/*<<��Ƶ����������ѯ����>>
	*���䷽��mtsdk->mtservice->mtmp
	* see Ev_MT_BLL_MtmpAudioInVolume_Rsp
	*/
	MESSAGE( Ev_MT_BLL_MtmpAudioInVolume_Req )

	/*<<��Ƶ����������ѯ��Ӧ>>
	*���䷽��mtmp->mtservice->mtsdk
	* see Ev_MT_BLL_MtmpAudioInVolume_Req
	*/
	MESSAGE( Ev_MT_BLL_MtmpAudioInVolume_Rsp)
	BODY(mt::TU8,   byVol)

	/*<<���������ѯ����>>
	*���䷽��mtsdk->mtservice->mtmp
	* see Ev_MT_BLL_MtmpMicVolumeDetect_Rsp
	*/
	MESSAGE( Ev_MT_BLL_MtmpMicVolumeDetect_Req )
	BODY(mt::TS32, mic)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmHDAudPortIn

	/*<<���������ѯ��Ӧ>>
	*���䷽��mtmp->mtservice->mtsdk
	* see Ev_MT_BLL_MtmpMicVolumeDetect_Req
	*/
	MESSAGE( Ev_MT_BLL_MtmpMicVolumeDetect_Rsp )
	BODY(mt::TS32, mic)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmHDAudPortIn
	BODY(mt::TU8,   byVol)

	/*<<��Ƶ����ӿ�״̬��ѯ����>>
	*���䷽��mtsdk->mtservice->mtmp
	* see Ev_MT_BLL_MtmpAudioInputState_Rsp
	*/
	MESSAGE( Ev_MT_BLL_MtmpAudioInputState_Req )
	BODY(mt::TMultiAudInputState,   tInput_State)

	/*<<��Ƶ����ӿ�״̬��ѯ��Ӧ>>
	*���䷽��mtmp->mtservice->mtsdk
	* see Ev_MT_BLL_MtmpAudioInputState_Req
	*/
	MESSAGE( Ev_MT_BLL_MtmpAudioInputState_Rsp )
	BODY(mt::TMultiAudInputState,   tInput_State)

	/*<<��Ƶ����ӿ�״̬��ѯ����>>
	*���䷽��mtsdk->mtservice->mtmp
	* see Ev_MT_BLL_MtmpAudioOutputState_Rsp
	*/
	MESSAGE( Ev_MT_BLL_MtmpAudioOutputState_Req )
	BODY(mt::TMultiAudOutputState,   tOutput_State)

	/*<<��Ƶ����ӿ�״̬��ѯ��Ӧ>>
	*���䷽��mtmp->mtservice->mtsdk
	* see Ev_MT_BLL_MtmpAudioOutputState_Req
	*/
	MESSAGE( Ev_MT_BLL_MtmpAudioOutputState_Rsp )
	BODY(mt::TMultiAudOutputState,   tOutput_State)

	/*<<��Ƶ�ӿ�������ѯ����>>
	*���䷽��mtsdk->mtservice
	* see Ev_MT_BLL_MtmpVideoInPortCap_Rsp
	*/
	MESSAGE( Ev_MT_BLL_MtmpVideoInPortCap_Req )

	/*<<��Ƶ�ӿ�������ѯ��Ӧ>>
	*���䷽��mtservice->mtsdk
	* see Ev_MT_BLL_MtmpVideoInPortCap_Req
	*/
	MESSAGE( Ev_MT_BLL_MtmpVideoInPortCap_Rsp )
	BODY(mt::TMTHDVidInPortCapList, cap_list)

	/*<<��Ƶ�ӿ������ϱ�>>
	*���䷽��mtservice->mtsdk
	* see Ev_MT_BLL_MtmpVideoInPortCap_Ntf
	*/
	MESSAGE( Ev_MT_BLL_MtmpVideoInPortCap_Ntf )
	BODY(mt::TMTHDVidInPortCapList, cap_list)

	/*<<��ƵԴ�ֱ��ʲ�ѯ>>
	*���䷽��mtsdk->mtservice
	* see Ev_MT_BLL_MtmpVidSrcStatus_Rsp
	*/
	MESSAGE( Ev_MT_BLL_MtmpVidSrcStatus_Req )

	/*<<��ƵԴ�ֱ��ʲ�ѯ��Ӧ>>
	*���䷽��mtservice->mtsdk
	* see Ev_MT_BLL_MtmpVidSrcStatus_Req
	*/
	MESSAGE( Ev_MT_BLL_MtmpVidSrcStatus_Rsp )
	BODY(mt::TMtVidSrcInfoList, src_info_list)

	/*<<��ƵԴ�ֱ����ϱ�>>
	*���䷽��mtservice->mtsdk
	* see 
	*/
	MESSAGE( Ev_MT_BLL_MtmpVidSrcStatus_Ntf )
	BODY(mt::TMtVidSrcInfoList, src_info_list)

	/*<<��Ƶ����ӿڷֱ��ʲ�ѯ>>
	*���䷽��mtsdk->mtservice
	* see Ev_MT_BLL_MtmpVidInPortRes_Rsp
	*/
	MESSAGE( Ev_MT_BLL_MtmpVidInPortRes_Req )

	/*<<��Ƶ����ӿڷֱ��ʲ�ѯ��Ӧ>>
	*���䷽��mtservice->mtsdk
	* see Ev_MT_BLL_MtmpVidInPortRes_Req
	*/
	MESSAGE( Ev_MT_BLL_MtmpVidInPortRes_Rsp )
	BODY(mt::TMtVidInPortResInfoList, src_info_list)

	/*<<��Ƶ����ӿڷֱ����ϱ�>>
	*���䷽��mtservice->mtsdk
	* see 
	*/
	MESSAGE( Ev_MT_BLL_MtmpVidInPortRes_Ntf )
	BODY(mt::TMtVidInPortResInfoList, src_info_list)

	/*<<��ѯSDI�ӿ���������>>
	*���䷽��mtsdk->mtservice
	* see Ev_MT_BLL_MtmpGetSdiInOut_Rsp
	*/
	MESSAGE( Ev_MT_BLL_MtmpGetSdiInOut_Req )

	/*<<��ѯSDI�ӿ�������Ӧ>>
	*���䷽��mtservice->mtsdk
	* see Ev_MT_BLL_MtmpGetSdiInOut_Req
	*/
	MESSAGE( Ev_MT_BLL_MtmpGetSdiInOut_Rsp )
	BODY(mt::TS32, sdi_inout) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmSdiInOut

	/*<<Fxo����>>
	*���䷽��mtsdk->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_BLL_FxoMakeCall_Cmd )
	BODY(mt::TString, achPeerNumber)

	/*<<Fxo����>>
	*���䷽��mtservice->mtsdk
	* see 
	*/
	MESSAGE( Ev_MT_BLL_FxoMakeCall_Ntf )
	BODY(mt::TString, achPeerNumber)

	/*<<Fxo���н���>>
	*���䷽��mtservice->mtsdk
	* see 
	*/
	MESSAGE( Ev_MT_BLL_FxoCallIncoming_Ntf )
	BODY(mt::TString, achPeerNumber)	//�ײ���ʱ��ȡ�����Զ˺���

	/*<<Fxo ���ܺ���>>
	*���䷽��mtsdk->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_BLL_FxoAccept_Cmd )

	/*<<Fxo �ܾ�����>>
	*���䷽��mtsdk->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_BLL_FxoReject_Cmd )

	/*<<Fxo �Ҷϵ绰>>
	*���䷽��mtsdk->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_BLL_FxoHangup_Cmd )

	/*<<Fxo����״̬��Ϣ�ϱ�>>
	*���䷽��mtservice->mtsdk
	* see 
	*/
	MESSAGE( Ev_MT_BLL_FxoCallLinkState_Ntf )
	BODY(mt::TFxoState, tFxo_state)

	/*<<Fxo���д������ϱ�>>
	*���䷽��mtservice->mtsdk
	* see 
	*/
	MESSAGE( Ev_MT_BLL_FxoCallErrorCode_Ntf )
	BODY(mt::TU32, error_code)	//0:δ�ӵ绰��

	/*<<�����������>>
	*���䷽��mtervice->mtmp
	* see Ev_MT_BLL_CodecSnapshot_Rsp
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshot_Req )
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, coder_id) //����һ·�Ŀ��ա�ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<���������Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_BLL_CodecSnapshot_Req
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshot_Rsp )
	BODY(mt::TU32, snapshot_state) //��������״̬ 0���ɹ� 1���������������� 2�����̿ռ䲻�� 3:�ɼ�����ͼ�� 4: �Զ������� 5:�ϴ���ftp������ʧ��
	BODY(mt::TSnapshotFileInfo, file_info) //Я�������ļ�����Ϣ

	/*<<�����ɿ����ϱ�>>
	*���䷽��mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshot_Ntf )
	BODY(mt::TSnapshotFileInfo, file_info) //Я�������ļ�����Ϣ

	/*<<��ѯ��������ļ�����>>
	*���䷽�� mtsdk->mtservice
	* see Ev_MT_BLL_CodecSnapshotQueryLatestFile_Rsp
	*/ 
	MESSAGE( Ev_MT_BLL_CodecSnapshotQueryLatestFile_Req )

	/*<<��ѯ��������ļ���Ӧ>>
	*���䷽��mtservice->mtsdk
	* see Ev_MT_BLL_CodecSnapshotQueryLatestFile_Req
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotQueryLatestFile_Rsp )
	BODY(mt::TU32, result) //��ѯ״̬��� 0���ɹ� 1��ʧ��
	BODY(mt::TSnapshotFileInfo, file_info) //Я�����������ļ�����Ϣ

	/*<<��ѯ�����ļ��б���Ϣ����>>
	*���䷽��mtervice->mtmp
	* see Ev_MT_BLL_CodecSnapshotQueryFileList_Rsp
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotQueryFileList_Req )

	/*<<��ѯ�����ļ��б���Ϣ��Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_BLL_CodecSnapshotQueryFileList_Req
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotQueryFileList_Rsp )
	BODY(mt::TS32, report_state) //һ����Ϣ�ϱ������ļ��б�ʱЯ����Ϣ���кţ����кŴ�1��ʼ�����������յ����һ����ϢʱЯ��-1��ֻ�ϱ�һ����ϢʱЯ��0��
	BODY(mt::TSnapshotFileList, file_info)//�ļ��б�

	/*<<ɾ��һ�ſ�������>>
	*���䷽��mtervice->mtmp
	* see Ev_MT_BLL_CodecSnapshotDelOneFile_Rsp
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotDelOneFile_Req )
	BODY(mt::TSnapshotFileInfo, file_info) //�ļ���Ϣ

	/*<<ɾ��һ�ſ�����Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_BLL_CodecSnapshotDelOneFile_Req
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotDelOneFile_Rsp )
	BODY(mt::TBOOL32, del_state) //�Ƿ�ɾ���ɹ�
	BODY(mt::TSnapshotFileInfo, file_info)//��ɾ�����ļ���Ϣ

	/*<<һ�ſ��ձ�ɾ���ϱ�>>
	*���䷽��mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotDelOneFile_Ntf )
	BODY(mt::TSnapshotFileInfo, file_info)//��ɾ�����ļ���Ϣ

	/*<<������һ�ſ�������>>
	*���䷽��mtervice->mtmp
	* see Ev_MT_BLL_CodecSnapshotRenameOneFile_Req
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotRenameOneFile_Req )
	BODY(mt::TSnapshotFileInfo, file_info_old) //������ǰ���ļ���Ϣ
	BODY(mt::TSnapshotFileInfo, file_info_new) //����������ļ���Ϣ

	/*<<������һ�ſ�����Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_BLL_CodecSnapshotRenameOneFile_Rsp
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotRenameOneFile_Rsp )
	BODY(mt::TBOOL32, rename_state) //�Ƿ��������ɹ�
	BODY(mt::TSnapshotFileInfo, file_info_old)//������ǰ���ļ���Ϣ
	BODY(mt::TSnapshotFileInfo, file_info_new)//����������ļ���Ϣ

	/*<<һ�ſ��ձ��������ϱ�>>
	*���䷽��mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotRenameOneFile_Ntf )
	BODY(mt::TSnapshotFileInfo, file_info_old)//������ǰ���ļ���Ϣ
	BODY(mt::TSnapshotFileInfo, file_info_new)//����������ļ���Ϣ

	/*<<ɾ�����п����ļ�����>>
	*���䷽��mtervice->mtmp
	* see Ev_MT_BLL_CodecSnapshotDelAllFile_Rsp
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotDelAllFile_Req )

	/*<<ɾ�����п����ļ���Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_BLL_CodecSnapshotDelAllFile_Req
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotDelAllFile_Rsp )
	BODY(mt::TBOOL32, del_state) //�Ƿ�ɾ���ɹ�

	/*<<���п����ļ����֪ͨ>>
	*���䷽��mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotDelAllFile_Ntf )

	/*<<����һ�ſ����ļ�����>>
	*���䷽��mtervice->mtmp
	* see Ev_MT_BLL_CodecSnapshotExportOneFile_Rsp
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotExportOneFile_Req )
	BODY(mt::TSnapshotFileInfo, file_info) //��Ҫ�������ļ���Ϣ
    BODY(mt::TString, dst_path)            //��Ҫ����Ŀ���ļ���

	/*<<����һ�ſ����ļ���Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_BLL_CodecSnapshotExportOneFile_Req
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotExportOneFile_Rsp )
	BODY(mt::TS32, export_state) //����״̬ mt::EmFileCopyErr
	BODY(mt::TSnapshotFileInfo, file_info) //�Ѿ������ļ�����Ϣ

	/*<<�������п����ļ�����>>
	*���䷽��mtervice->mtmp
	* see Ev_MT_BLL_CodecSnapshotExportAllFile_Rsp
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotExportAllFile_Req )
    BODY(mt::TString, dst_path)            //��Ҫ����Ŀ���ļ���

	/*<<�������п����ļ���Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_BLL_CodecSnapshotExportAllFile_Req
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotExportAllFile_Rsp )
	BODY(mt::TS32, export_state) //����״̬ mt::EmFileCopyErr

	/*<<�������п����ļ�ʱ��ֹͣ�������յ�����>>
	*���䷽��sdk->mtervice
	* see Ev_MT_BLL_CodecStopSnapshotExport_Ntf
	*/
	MESSAGE( Ev_MT_BLL_CodecStopSnapshotExport_Cmd )

	/*<<�������п����ļ�ʱ��ֹͣ�������յ���Ӧ>>
	*���䷽��mtservice->sdk
	* see Ev_MT_BLL_CodecStopSnapshotExport_Cmd
	*/
	MESSAGE( Ev_MT_BLL_CodecStopSnapshotExport_Ntf )

    /*<<�������ս���>>
	*���䷽��mtservice->sdk
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotExportProgress_Ntf )
	BODY(mt::TU32, progress) //��������(�ٷֱ�)



    /*<<����ftp>>
	*���䷽��sdk->mtservice
	*index : ��ǰ������Ԥ��λ����
	* see Ev_MT_BLL_CodecFtpJpeg_Ntf
	*/
	MESSAGE( Ev_MT_BLL_CodecFtpJpeg_Cmd )
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, coder_id) //����һ·�Ŀ��ա�ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<����ftp>>
	*���䷽��mtservice->sdk
	*index : ��ǰ������Ԥ��λ����
	* see Ev_MT_BLL_CodecFtpJpeg_Cmd
	*/
	MESSAGE( Ev_MT_BLL_CodecFtpJpeg_Ntf )
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, coder_id) //����һ·�Ŀ��ա�ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TBOOL32, is_sucess) //�Ƿ�����ɹ�


	/*<<����������־�ļ�����>>
	*���䷽��mtervice->mtmp
	* see Ev_MT_BLL_ExportAllLogFile_Rsp
	*/
	MESSAGE( Ev_MT_BLL_ExportAllLogFile_Req )
    BODY(mt::TString, dst_path)            //��Ҫ����Ŀ���ļ���

	/*<<����������־�ļ���Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_BLL_ExportAllLogFile_Req
	*/
	MESSAGE( Ev_MT_BLL_ExportAllLogFile_Rsp )
	BODY(mt::TS32, export_state) //����״̬ mt::EmFileCopyErr

	/*<<������־����>>
	*���䷽��mtservice->sdk
	*/
	MESSAGE( Ev_MT_BLL_AllLogFileExportProgress_Ntf )
	BODY(mt::TU32, progress) //��������(�ٷֱ�)

    /*<<�������ͼƬ���㹦��>>
	*���䷽��mtervice->mtmp
	* see Ev_MT_BLL_CodecMonitorPic_Ntf
	*/
    MESSAGE( Ev_MT_BLL_CodecMonitorPic_Cmd )
    BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
    BODY(mt::TS32, coder_id) //����һ·�Ŀ��ա�ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TBOOL32, opt)//TRUE����   FALSE�ر�
    BODY(mt::TS32, pic_index)//��һ�λ�ȡ���յ�index 0/1

	/*<<�������ͼƬ���㹦����Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_BLL_CodecMonitorPic_Cmd
	*/
    MESSAGE( Ev_MT_BLL_CodecMonitorPic_Ntf )
    BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
    BODY(mt::TS32, coder_id) //����һ·�Ŀ��ա�ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
    BODY(mt::TBOOL32, status)//TRUE����   FALSE�ر�

    /*<<��ѯ���ͼƬ���㹦���Ƿ���>>
	*���䷽��mtervice->mtmp
	* see Ev_MT_BLL_CodecMonitorPicStatus_Rsp
	*/
    MESSAGE( Ev_MT_BLL_CodecMonitorPicStatus_Req )
    BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
    BODY(mt::TS32, coder_id) //����һ·�Ŀ��ա�ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<��ѯ���ͼƬ���㹦����Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_BLL_CodecMonitorPicStatus_Req
	*/
    MESSAGE( Ev_MT_BLL_CodecMonitorPicStatus_Rsp )
    BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
    BODY(mt::TS32, coder_id) //����һ·�Ŀ��ա�ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TBOOL32, status)//TRUE����   FALSE�ر�

        /*<<ͼƬ��ȡ>>
	*���䷽��mtsdk->mtservice
	* see Ev_MT_BLL_CodecPicGet_Rsp
	*/
    MESSAGE( Ev_MT_BLL_CodecPicGet_Req )
    BODY(mt::TS32, index)//��ȡ�ļ��ͼƬindex 0/1

	/*<<ͼƬ��ȡ��Ӧ>>
	*���䷽��mtservice->mtsdk
	* see Ev_MT_BLL_CodecPicGet_Req
	*/
    MESSAGE( Ev_MT_BLL_CodecPicGet_Rsp )
	BODY(mt::TBOOL32, result)//��ȡ���


	/*<<������ƵԴѡ��ָ��>>
	*encoder_id    ����һ·����ƵԴ���ڶ�·����ƵԴ
	*��Ϣ���� ��mtsdk==>dispatch==>service
	* see Ev_MT_BLL_CodecSelectLocalVideoView_Ntf
	*/
    MESSAGE(Ev_MT_BLL_CodecSelectLocalVideoView_Cmd)
	BODY(mt::TS32, encoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCameraView

	/*<<������ƵԴѡ��֪ͨ>>
	*encoder_id    ����һ·����ƵԴ���ڶ�·����ƵԴ
	*��Ϣ���� ��service==>dispatch==>mtsdk
	* see Ev_MT_BLL_CodecSelectLocalVideoView_Cmd
	*/
    MESSAGE(Ev_MT_BLL_CodecSelectLocalVideoView_Ntf)
	BODY(mt::TS32, encoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCameraView

	/*<<������ƵԴѡ�����ݲ�ѯ����>>
	*encoder_id    ����һ·����ƵԴ���ڶ�·����ƵԴ
	*��Ϣ���� ��mtsdk==>dispatch==>service
	* see Ev_MT_BLL_CodecGetLocalVideoView_Rsp
	*/
    MESSAGE(Ev_MT_BLL_CodecGetLocalVideoView_Req)

	/*<<������ƵԴѡ�����ݲ�ѯ��Ӧ>>
	*encoder_id    ����һ·����ƵԴ���ڶ�·����ƵԴ
	*��Ϣ���� ��service==>dispatch==>mtsdk
	* see Ev_MT_BLL_CodecGetLocalVideoView_Req
	*/
    MESSAGE(Ev_MT_BLL_CodecGetLocalVideoView_Rsp)
	BODY(mt::TS32, encoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<ˢ��̨��>>
	*pic_file_name    ����̨��ͼƬ���ļ���
	*��Ϣ���� ��mtsdk==>dispatch==>service
	* see 
	*/
    MESSAGE(Ev_MT_BLL_CodecLabelUpdate_Cmd)
	BODY(mt::TString, pic_file_name)

	/*<<ˢ�º��>>
	*pic_file_name    ���º��ͼƬ���ļ���
	*��Ϣ���� ��mtsdk==>dispatch==>service
	* see 
	*/
    MESSAGE(Ev_MT_BLL_CodecBannerUpdate_Cmd)
	BODY(mt::TString, pic_file_name)

	/*<<������Ƶ���ȡ��Աȶȡ����Ͷ�>>
	*��Ϣ���� ��mtsdk==>dispatch==>service
	* see Ev_MT_BLL_SetVidImgParam_Ntf
	*/
    MESSAGE(Ev_MT_BLL_SetVidImgParam_Cmd)
	BODY(mt::TS32, codec_type)//�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TS32, param_type) //�ô�ʵ��Ϊmt::EmImgParam
	BODY(mt::TU32, param_value)//����ֵ

	/*<<������Ƶ���ȡ��Աȶȡ����Ͷ��ϱ�>>
	*��Ϣ���� ��service==>dispatch==>mtsdk
	* see Ev_MT_BLL_SetVidImgParam_Cmd
	*/
    MESSAGE(Ev_MT_BLL_SetVidImgParam_Ntf)
	BODY(mt::TS32, codec_type)//�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TS32, param_type) //�ô�ʵ��Ϊmt::EmImgParam
	BODY(mt::TU32, param_value)//����ֵ

	/*<<��ѯ��Ƶ���ȡ��Աȶȡ����Ͷ�����>>
	*��Ϣ���� ��mtsdk==>dispatch==>service
	* see Ev_MT_BLL_GetVidImgParam_Rsp
	*/
    MESSAGE(Ev_MT_BLL_GetVidImgParam_Req)
	BODY(mt::TS32, codec_type)//�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TS32, param_type) //�ô�ʵ��Ϊmt::EmImgParam

	/*<<��ѯ��Ƶ���ȡ��Աȶȡ����Ͷ���Ӧ>>
	*��Ϣ���� ��service==>dispatch==>mtsdk
	* see Ev_MT_BLL_GetVidImgParam_Req
	*/
    MESSAGE(Ev_MT_BLL_GetVidImgParam_Rsp)
	BODY(mt::TS32, codec_type)//�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TS32, param_type) //�ô�ʵ��Ϊmt::EmImgParam
	BODY(mt::TU32, param_value)//����ֵ


    /*<<�������ر�OSD��͸����>>
	*��Ϣ���� ��mtsdk==>dispatch==>service
	* see Ev_MT_BLL_SetOsdTransparent_Rsp
	*/
    MESSAGE(Ev_MT_BLL_SetOsdTransparent_Req)
	BODY(mt::TBOOL32, trans)

	/*<<�������ر�OSD��͸��Ӧ>>
	*��Ϣ���� ��service==>dispatch==>mtsdk
	* see Ev_MT_BLL_SetOsdTransparent_Req
	*/
    MESSAGE(Ev_MT_BLL_SetOsdTransparent_Rsp)
    BODY(mt::TBOOL32, trans)
    BODY(mt::TS32, result)


    /*<<OSD�����Ƿ����������>>
	*��Ϣ���� ��mtsdk==>dispatch==>service
	* see Ev_MT_BLL_OsdSnapshotBrowse_Ntf
	*/
    MESSAGE(Ev_MT_BLL_OsdSnapshotBrowse_Cmd)
	BODY(mt::TBOOL32, browsing)

	/*<<OSD�����Ƿ����������֪ͨ>>
	*��Ϣ���� ��service==>dispatch==>mtsdk
	* see Ev_MT_BLL_OsdSnapshotBrowse_Cmd
	*/
    MESSAGE(Ev_MT_BLL_OsdSnapshotBrowse_Ntf)
    BODY(mt::TBOOL32, browsing)



	/*<<��ȡ������Ӧ��Ԥ��λ����>>
	*��Ϣ���� ��mtsdk==>dispatch==>service
	* see Ev_MT_BLL_CurPresetIndex_Rsp
	*/
    MESSAGE(Ev_MT_BLL_GetCurCodecPresetIndex_Req)
	BODY(mt::EmCodecComponentIndex, codec_index)

	/*<<������Ӧ��Ԥ��λ�ظ�>>
	*��Ϣ���� ��service==>dispatch==>mtsdk
	* see Ev_MT_BLL_GetCurPresetIndex_Req
	*/
    MESSAGE(Ev_MT_BLL_CurCodecPresetIndex_Rsp)
	BODY(mt::EmCodecComponentIndex, codec_index)
    BODY(mt::TU32, pre_set_index)

	/*<< �Զ�����ʱ�Ӽ������ >>
	*[��Ϣ��]
	*    + start: ��ʼ��ֹͣ
	*[��Ϣ����]
	*    mtsdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_AutoAudioDelayCheckCmd)
	BODY(mt::TBOOL32, start)

	/*<< �Զ�����ʱ�Ӽ��֪ͨ >>
	*[��Ϣ��]
	*    + state(EmAudioDelayCheckState)�����״̬
	*    + result����EmAudioDelayCheckStateΪemAudioDelayCheckedʱ����ֵ��Ч����ʾʱ��ֵ
	*             ��EmAudioDelayCheckStateΪemAudioDelayFailedʱ����ֵ��Ч����ʾʧ�ܴ�����
	*[��Ϣ����]
	*    mtservice==>dispatch==>mtsdk
	*/
	MESSAGE(Ev_MT_BLL_AutoAudioDelayCheckNtf)
	BODY(mt::TU32, state)
	BODY(mt::TU32, result)

    /*<������ر�OSD����֪ͨ>
    *���䷽��mtservice->sdk
    *see Ev_MT_BLL_CodecOsdSnapshot_Cmd
    */
    MESSAGE(Ev_MT_BLL_CodecOsdSnapShotOpen_Ntf)
    BODY(mt::TBOOL32, opt)  // TRUE�� FLASE�ر�

    /*<OSD��������>
    *���䷽��sdk->mtservice
    *
    */
    MESSAGE(Ev_MT_BLL_CodecOsdSnapshot_Cmd)

	/*<������б��ϱ�>
    *���䷽��mtservice->sdk
    *
    */
	MESSAGE(Ev_MT_BLL_HD_GetCameraListCfg_Ntf)
    BODY(mt::TMTHDCameraList, opt)  


	/*<�����Ƿ���ʾosd>
    *���䷽��sdk->mtservice
    *
    */
    MESSAGE(Ev_MT_BLL_CodecSetShowOsd_Cmd)
	BODY(mt::TBOOL32, bShow)  // TRUE�� FLASE�ر�

	/*<֪ͨ�Ƿ���ʾosd>
    *���䷽��sdk->mtservice
    *
    */
    MESSAGE(Ev_MT_BLL_CodecIsShowOsd_Ntf)
	BODY(mt::TBOOL32, bShow)  // TRUE�� FLASE�ر�


	/*<��ʼ����¼������>
	*���䷽��sdk->mtservice
	*
	*/
	MESSAGE(EV_MT_BLL_Record_Start_Cmd)
	BODY(mt::TString, tPathName)  // ����¼���ļ���

	/*<��ʼ����¼��ظ�>
	*���䷽��mtservice->sdk
	*
	*/
	MESSAGE(EV_MT_BLL_Record_Start_Ntf)
	BODY(mt::TBOOL32, bSuccess)  // ��ʼ¼��ɹ���ʧ��


	/*<ֹͣ����¼������>
	*���䷽��sdk->mtservice
	*
	*/
	MESSAGE(EV_MT_BLL_Record_Stop_Cmd)

	/*<ֹͣ����¼��ظ�>
	*���䷽��mtservice->sdk
	*
	*/
	MESSAGE(EV_MT_BLL_Record_Stop_Ntf)
	BODY(mt::TBOOL32, bSuccess)  // ֹͣ¼��ɹ���ʧ��


	/*<��ͣ¼������>
	*���䷽��sdk->mtservice
	*
	*/
	MESSAGE(EV_MT_BLL_Record_Pause_Cmd)

	/*<��ͣ����¼��ظ�>
	*���䷽��mtservice->sdk
	*
	*/
	MESSAGE(EV_MT_BLL_Record_Pause_Ntf)
	BODY(mt::TBOOL32, bSuccess)  // ��ͣ¼��ɹ���ʧ��


	/*<��������¼������>
	*���䷽��sdk->mtservice
	*
	*/
	MESSAGE(EV_MT_BLL_Record_Continue_Cmd)

	/*<��������¼��ظ�>
	*���䷽��mtservice->sdk
	*
	*/
	MESSAGE(EV_MT_BLL_Record_Continue_Ntf)
	BODY(mt::TBOOL32, bSuccess)  // ����¼��ɹ���ʧ��

	
	/*<ʣ��¼��ʱ��ظ�>
    *���䷽��mtservice -> sdk
    */
    MESSAGE(EV_MT_BLL_Record_RemainTime_Ntf)	
	BODY(mt::TU32, dwRemainTime )  //ʣ������

	/*<¼������е�״̬֪ͨ>
    *���䷽��mtservice -> sdk
    */
	MESSAGE(EV_MT_BLL_Record_Status_Ntf)
	BODY(mt::TU32, dwChanIndex)  // ͨ����
	BODY(mt::TU32, dwValue)		// ¼���״̬, ��Ӧ EmVideoRecordErrorNum_Api 

	/*<��ȡ����¼��״̬������>
    *���䷽��sdk -> mtservice
    */
	MESSAGE(EV_MT_BLL_Record_Status_Req)

	/*<��ȡ����¼��״̬�Ļظ�>
    *���䷽�� mtservice -> sdk
    */
	MESSAGE(EV_MT_BLL_Record_Status_Rsp)
	BODY(mt::TU32, dwSpaceSzie)  

	/*<��ȡ����¼��ʼʱ�������>
    *���䷽��sdk -> mtservice
    */
	MESSAGE(EV_MT_BLL_Record_Start_time_Cmd)

	/*<��ȡ����¼��ʼʱ���֪ͨ>
    *���䷽��mtservice -> sdk
    */
	MESSAGE(EV_MT_BLL_Record_Start_time_Ntf)
	BODY(mt::TMTTime, tStartTime)  

    /*<<��ȡ����ƵԴ�Ƿ���Դ����>>
	*���䷽��mtservice_hd->mtmp
	* see Ev_MT_AssVideoPortStatus_Rsp
	*/
	MESSAGE( Ev_MT_BLL_AssVideoPortStatus_Req )

	/*<<��ȡ����ƵԴ�Ƿ���Դ��Ӧ>>
	*���䷽��mtmp->mtservice_hd
	* see Ev_MT_AssVideoPortStatus_Req
	*/
	MESSAGE( Ev_MT_BLL_AssVideoPortStatus_Rsp )
	BODY(mt::TS32, vga_state) //Vga�Ƿ����1:���� 0:δ����
    BODY(mt::TS32, hdmi_state) //Hdmi�Ƿ����1:���� 0:δ����

    /*<<����OSD>>
	*���䷽��mtservice_hd->mtmp
	* see 
	*/
	MESSAGE( Ev_MT_BLL_CodecSetOsdOpen_Cmd )

    /*<<����OSD>>
	*���䷽��mtmp->mtservice_hd
	* see 
	*/
	MESSAGE( Ev_MT_BLL_CodecSetOsdOpen_Ntf )
    BODY(mt::TBOOL32, bSuccess)

	/*<<�ر�OSD>>
	*���䷽��mtservice_hd->mtmp
	* see 
	*/
	MESSAGE( Ev_MT_BLL_CodecSetOsdClose_Cmd )

    /*<<�ر�OSD>>
	*���䷽��mtmp->mtservice_hd
	* see 
	*/
	MESSAGE( Ev_MT_BLL_CodecSetOsdClose_Ntf )
    BODY(mt::TBOOL32, bSuccess)

    /*<<˫��ģʽ��˫���µڶ����Ƿ���ʾԶ�˸�������>>
	*��Ϣ���� ��mtservice_hd==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_ShowRemoteAssVideo_Cmd)
	BODY(mt::TBOOL32, showRemoteAssVideo)

    /*<Ӳ��оƬ��ȡ����>
    *���䷽��mtservice=>dispatch=>mtmpapp
    */
    MESSAGE(EV_MT_BLL_HwChipInfoInquire_Req)

	/*<Ӳ��оƬ��ȡ����ظ�>
    *���䷽��mtmpapp=>dispatch=>mtservice
    */
    MESSAGE(EV_MT_BLL_HwChipInfoInquire_Rsp)		
	BODY( mt::TMtHwChipInfoList, hwchipinfolist )

	/*<Ӳ��оƬ��ȡ��Ӧ>
    *���䷽�� mtmpapp=>dispatch=>mtservice
    */
    MESSAGE(EV_MT_BLL_HwChipInfoInquire_Ntf)		
	BODY( mt::TMtHwChipInfoList, hwchipinfolist )
	
	/*<���ظ���������ȡ����>
    *���䷽��sdk=>dispatch=>mtservice
    */
    MESSAGE(EV_MT_BLL_GetSubAudExpansion_Req)

	/*<���ظ���������ȡ����ظ�>
    *���䷽��mtservice=>dispatch=>sdk
    */
    MESSAGE(EV_MT_BLL_GetSubAudExpansion_Rsp)		
	BODY( mt::TBOOL32, bSubAudExpansion )
	
	/*<���ظ�����������>
    *���䷽�� sdk=>dispatch=>mtservice
    */
    MESSAGE(EV_MT_BLL_SetSubAudExpansion_Cmd)		
	BODY( mt::TBOOL32, bSubAudExpansion )

	/*<���ظ�������������Ӧ>
    *���䷽�� mtservice=>dispatch=>sdk
    */
    MESSAGE(EV_MT_BLL_SetSubAudExpansion_Ntf)		
	BODY( mt::TBOOL32, bSubAudExpansion )
	BODY( mt::TU32, result )

	/*<<��ȡ��Ƶ Զ���Ի�״̬����>>
	*���䷽��mtsdk->mtservice->mtmp
	* see Ev_MT_BLL_GetAudRmtLoopState_Rsp
	*/
	MESSAGE( Ev_MT_BLL_GetAudRmtLoopState_Req )

	/*<<��ȡ��Ƶ Զ���Ի�״̬��Ӧ>>
	*���䷽��mtmp->mtservice->mtsdk
	* see Ev_MT_BLL_GetAudRmtLoopState_Req
	*/
	MESSAGE( Ev_MT_BLL_GetAudRmtLoopState_Rsp)
	BODY(mt::TS32, codec_type)//mt::EmCodecComponent
	BODY(mt::TS32, codec_id)//mt::EmCodecComponentIndex
	BODY(mt::TBOOL32,   bStart)

    /*<<<����֪ͨ����>>
    * ��Ϣ���� ��mtservice==>dispatch==>mtsdk
    */
    MESSAGE(Ev_MT_BLL_VidStreamAppear_Ntf)
    BODY(mt::TS32, type) //���ֵ����ȷ���ǻص��յ�����ʱ���ϱ���������ʱ���ϱ�



    /*<<����Isp����>>
    *��Ϣ���� ��mtsdk==>dispatch==>service
    * see Ev_MT_BLL_SetIspParam_Ntf
    */
    MESSAGE(Ev_MT_BLL_SetIspParam_Cmd)
    BODY(mt::TS32, codec_type)//�ô�ʵ��Ϊmt::EmCodecComponent
    BODY(mt::TS32, codec_id) //�ô�ʵ��Ϊmt::EmCodecComponentIndex
    BODY(mt::TS32, param_type) //�ô�ʵ��Ϊmt::EmIspImgInf
    BODY(mt::TU32, param_value)//����ֵ

    /*<<����Isp����>>
    *��Ϣ���� ��service==>dispatch==>mtsdk
    * see Ev_MT_BLL_SetIspParam_Cmd
    */
    MESSAGE(Ev_MT_BLL_SetIspParam_Ntf)
    BODY(mt::TS32, codec_type)//�ô�ʵ��Ϊmt::EmCodecComponent
    BODY(mt::TS32, codec_id) //�ô�ʵ��Ϊmt::EmCodecComponentIndex
    BODY(mt::TS32, param_type) //�ô�ʵ��Ϊmt::EmIspImgInf
    BODY(mt::TU32, param_value)//����ֵ

    /*<<��ѯIsp����>>
    *��Ϣ���� ��mtsdk==>dispatch==>service
    * see Ev_MT_BLL_GetIspParam_Rsp
    */
    MESSAGE(Ev_MT_BLL_GetIspParam_Req)
    BODY(mt::TS32, codec_type)//�ô�ʵ��Ϊmt::EmCodecComponent
    BODY(mt::TS32, codec_id) //�ô�ʵ��Ϊmt::EmCodecComponentIndex
    BODY(mt::TS32, param_type) //�ô�ʵ��Ϊmt::EmIspImgInf

    /*<<��ѯIsp����>>
    *��Ϣ���� ��service==>dispatch==>mtsdk
    * see Ev_MT_BLL_GetIspParam_Req
    */
    MESSAGE(Ev_MT_BLL_GetIspParam_Rsp)
    BODY(mt::TS32, codec_type)//�ô�ʵ��Ϊmt::EmCodecComponent
    BODY(mt::TS32, codec_id) //�ô�ʵ��Ϊmt::EmCodecComponentIndex
    BODY(mt::TS32, param_type) //�ô�ʵ��Ϊmt::EmIspImgInf
    BODY(mt::TU32, param_value)//����ֵ

	/*<<��Ƶ�ļ���������>>
	*���䷽��mtai->mtmp
	* see 
	*/
	MESSAGE( Ev_MT_BLL_PlayAudio_Cmd )
	BODY(mt::EmAiAudioType, emAiAudio)


#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(MPEMBED) = EVSEG_BLL_MPCOMMON_END
};
#endif

#define Is_BLL_MPEmbed_Msg(m) ((m) >= EV_BLL_BGN(MPEMBED) && (m) <= EV_BLL_END(MPEMBED))

#endif // _MTBLLMPEMBEDMSG_H_