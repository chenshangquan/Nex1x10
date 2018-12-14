#ifndef _MTMPEMBEDMSG_H_
#define _MTMPEMBEDMSG_H_

#include "mtmsgid.h"
#include "struct.pb.h"

#if !defined(_MESSAGE_HELP_)
enum EmMPEmbedMsg
{
    EV_BGN(MPEMBED) = EVSEG_MPEMBED_BGN,
#endif
	
	/*<<��������>>
	*��Ϣ���� ��misc==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecDspSleep_Cmd)

	/*<<��������>>
	*��Ϣ���� ��misc==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecDspWakeup_Cmd)

	/*<<��������>>
	*��Ϣ���� ��misc==>dispatch==>mtmp
	*is_sleep : TRUE��ʾ����˯��״̬��FALSE��ʾ���뻽��״̬
	*/
    MESSAGE(Ev_MT_CodecSleepState_Ntf)
	BODY(mt::TBOOL32, is_sleep)

	/*<<��������������������Ч��������Ч��������>>
	*sound_type : �������� ������������Ч��������Ч
	*sound_id : ������ʶ
	*play    ��TRUE-���� FALSE-ֹͣ����
	*��Ϣ���� ��mtservice==>mtmp
	*see Ev_MT_CodecLocalSoundPlay_Ntf
	*/
    MESSAGE(Ev_MT_CodecLocalSoundPlay_Cmd)
	BODY(mt::TS32, sound_type) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmLocalSoundType
	BODY(mt::TS32, sound_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmLocalSoundIndex
	BODY(mt::TBOOL32, play)

	/*<<��������������������Ч��������Ч����״̬��ʾ(��ʱֻ�������������ϱ�)>>
	*sound_type : �������� ������������Ч��������Ч
	*sound_id : ������ʶ
	*play    ��TRUE-���� FALSE-ֹͣ����
	*��Ϣ���� ��mtmp==>mtservice
	*see Ev_MT_CodecLocalSoundPlay_Cmd
	*/
    MESSAGE(Ev_MT_CodecLocalSoundPlay_Ntf)
	BODY(mt::TS32, sound_type) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmLocalSoundType
	BODY(mt::TS32, sound_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmLocalSoundIndex
	BODY(mt::TBOOL32, play)

	/*<<��������������������Ч��������Ч���Ų�ѯ����(������Ч�Ͷ�����Ч�����Ǹ��̲�������ʱ���ṩ��ѯ)>>
	*sound_type : �������� ������������Ч��������Ч
	*sound_id : ������ʶ
	*play    ��TRUE-���� FALSE-ֹͣ����
	*��Ϣ���� ��mtservice==>mtmp
	*see Ev_MT_CodecGetLocalSoundPlayState_Rsp
	*/
    MESSAGE(Ev_MT_CodecGetLocalSoundPlayState_Req)
	BODY(mt::TS32, sound_type) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmLocalSoundType
	BODY(mt::TS32, sound_id)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmLocalSoundIndex

	/*<<��������������������Ч��������Ч���Ų�ѯ��Ӧ(������Ч�Ͷ�����Ч�����Ǹ��̲�������ʱ���ṩ��ѯ)>>
	*sound_type : �������� ������������Ч��������Ч
	*sound_id : ������ʶ
	*play    ��TRUE-���� FALSE-ֹͣ����
	*��Ϣ���� ��mtmp==>mtservice
	*see Ev_MT_CodecGetLocalSoundPlayState_Req
	*/
    MESSAGE(Ev_MT_CodecGetLocalSoundPlayState_Rsp)
	BODY(mt::TS32, sound_type) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmLocalSoundType
	BODY(mt::TS32, sound_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmLocalSoundIndex
	BODY(mt::TBOOL32, play)

	/*<<���롢��������>>
	*calltype    ��TRUE-���� FALSE-����
	*play    ��TRUE-���� FALSE-ֹͣ����
	*��Ϣ���� ��mtservice==>mtmp
	*see 
	*/
    MESSAGE(Ev_MT_CodecRingPlay_Cmd)
	BODY(mt::TBOOL32, callin)
	BODY(mt::TBOOL32, play)

	/*<<���ö໭��������>>
	*��Ϣ���� ��mtservice==>mtmp
	*see Ev_MT_CodecSetPIP_Rsp
	*/
    MESSAGE(Ev_MT_CodecSetPIP_Req)
	BODY(mt::TMtPIPMode, pip_mode)

	/*<<���ö໭������Ӧ>>
	*��Ϣ���� ��mtmp==>mtservice
	*see Ev_MT_CodecSetPIP_Req
	*/
    MESSAGE(Ev_MT_CodecSetPIP_Rsp)
	BODY(mt::TMtPIPMode, pip_mode)

	/*<<��ѯ�໭��������>>
	*��Ϣ���� ��mtservice==>mtmp
	*see Ev_MT_CodecQueryPIP_Rsp
	*/
    MESSAGE(Ev_MT_CodecQueryPIP_Req)

	/*<<��ѯ�໭������Ӧ>>
	*��Ϣ���� ��mtmp==>mtservice
	*see Ev_MT_CodecQueryPIP_Req
	*/
    MESSAGE(Ev_MT_CodecQueryPIP_Rsp)
	BODY(mt::TMtPIPMode, pip_mode)

	/*<<�໭����״̬֪ͨ>>
	*��Ϣ���� ��mtmp==>mtservice
	*/
    MESSAGE(Ev_MT_CodecPIPState_Ntf)
	BODY(mt::TMtPIPMode, pip_mode)

	/*<<�������л�����>>
	*��Ϣ���� ��sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSwitchPIP_Cmd)

	/*<<ɫ����������>>
	*on ������orֹͣ
	*��Ϣ���� ��sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecRibbonTest_Cmd)
	BODY(mt::TBOOL32, on)

	/*<<ɫ������״̬֪ͨ>>
	*on ���Ƿ���ɫ������
	*��Ϣ���� ��mtmp==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_CodecRibbonTest_Ntf)
	BODY(mt::TBOOL32, on)		

	/*<<ɫ������״̬��ѯ����>>
	*��Ϣ���� ��mtservice==>mtmp
	* see Ev_MT_CodecRibbonTestStatus_Rsp
	*/
    MESSAGE(Ev_MT_CodecRibbonTestStatus_Req)

	/*<<ɫ������״̬��ѯ��Ӧ>>
	*on ���Ƿ���ɫ������
	*��Ϣ���� ��mtmp==>mtservice
	* see Ev_MT_CodecRibbonTestStatus_Req
	*/
    MESSAGE(Ev_MT_CodecRibbonTestStatus_Rsp)
	BODY(mt::TBOOL32, on)	

	/*<<���û���ϳɷ��>>
	*vmp_type ������ϳɷ��
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_VMPSetType_Cmd)
	BODY(mt::TU32, vmp_type)

	/*<<���÷��͵�ַ>>
	*send_addr �����úϳ���Ƶ�ķ��͵�ַ
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_VMPSetSendAddr_Cmd)
	BODY(mt::TNetAddr, send_addr)

	/*<<���úϳ���Ƶ�ı������>>
	*vid_enc_param ���������
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_VMPSetVidEncParam_Cmd)
	BODY(mt::TVidEncParam, vid_enc_param)

	/*<<��ʼ����ϳ�>>
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_VMPStart_Cmd)

	/*<<ֹͣ����ϳ�>>
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_VMPStop_Cmd)

	/*<<��Ӻϳɳ�Ա>>
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_VMPAddMem_Cmd)
	BODY(mt::TMultiVMPMemParam, vmp_memparams)

	/*<<ɾ���ϳɳ�Ա>>
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_VMPDelMem_Cmd)
	BODY(mt::TMultiU32, chan_indexs)//���Ǹ�repeated��

	/*<<���͹ؼ�֡>>
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_VMPSendFastUpdate_Cmd)

	/*<<������������>>
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_VMPSetBitrate_Cmd)
	BODY(mt::TU16, bitrate)


	//mixer
	/*<<���û������>>
	*mixer_depth ���������
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_MixerSetDepth_Cmd)
	BODY(mt::TU32, mixer_depth)
	/*<<���÷��͵�ַ>>
	*send_addr �����úϳ���Ƶ�ķ��͵�ַ
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_MixerSetSendAddr_Cmd)
	BODY(mt::TNetAddr, send_addr)
	/*<<���û����ı������>>
	*vid_enc_param ���������
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_MixerSetVidEncParam_Cmd)
	BODY(mt::TAudEncDecParam, Aud_enc_param)
	/*<<��ʼ����>>
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_MixerStart_Cmd)

	/*<<ֹͣ����>>
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_MixerStop_Cmd)

	/*<<��ӻ�����Ա��Ա>>
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_MixerAddMem_Cmd)
	BODY(mt::TMultiMixerMemParam, mixer_memparams)

	/*<<ɾ���ϳɳ�Ա>>
	*���䷽��mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_MixerDelMem_Cmd)
	BODY(mt::TMultiU32, chan_indexs)//���Ǹ�repeated��

	/*<<��·��������Ի�>>
	*���䷽��mtservice->mtmp
	* see Ev_MT_LocalSingleLoop_Ntf
	*/
	MESSAGE( Ev_MT_LocalSingleLoop_Cmd )
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TBOOL32,   bStart)

	/*<<��·��������Ի�>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_LocalSingleLoop_Cmd
	*/
	MESSAGE( Ev_MT_LocalSingleLoop_Ntf)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TBOOL32,   bStart)

	/*<<����ת����ģ���Ի�>>
	*���䷽��mtservice->mtmp
	* see Ev_MT_SimulatLocalSingleLoop_Cmd
	*/
	MESSAGE( Ev_MT_SimulatLocalSingleLoop_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TBOOL32,   bStart)

	/*<<��Ƶ�Ի�>>
	*���䷽��mtservice->mtmp
	* see Ev_MT_AudioLoop_Ntf
	*/
	MESSAGE( Ev_MT_AudioLoop_Cmd )
	BODY(mt::TBOOL32,   bStart)

	/*<<��Ƶ�Ի�״̬��ʾ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_AudioLoop_Cmd
	*/
	MESSAGE( Ev_MT_AudioLoop_Ntf)
	BODY(mt::TBOOL32,   bStart)
	
	/*<<��Ƶ����������ѯ����>>
	*���䷽��mtservice->mtmp
	* see Ev_MT_MtmpAudioInVolume_Rsp
	*/
	MESSAGE( Ev_MT_MtmpAudioInVolume_Req )

	/*<<��Ƶ����������ѯ��Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_MtmpAudioInVolume_Req
	*/
	MESSAGE( Ev_MT_MtmpAudioInVolume_Rsp)
	BODY(mt::TU8,   byVol)

	/*<<���������ѯ����>>
	*���䷽��mtservice->mtmp
	* see Ev_MT_MtmpMicVolumeDetect_Rsp
	*/
	MESSAGE( Ev_MT_MtmpMicVolumeDetect_Req )
	BODY(mt::TS32, mic)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmHDAudPortIn

	/*<<���������ѯ��Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_MtmpMicVolumeDetect_Req
	*/
	MESSAGE( Ev_MT_MtmpMicVolumeDetect_Rsp )
	BODY(mt::TS32, mic)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmHDAudPortIn
	BODY(mt::TU8,   byVol)


    /*<<��˷�����>>
	*���䷽��mtservice->mtmp
	* see Ev_MT_CodecSetMicGain_Ntf
	*/
	MESSAGE( Ev_MT_CodecSetMicGain_Cmd )
	BODY(mt::TU32, vol)

	/*<<��˷�����֪ͨ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_CodecSetMicGain_Cmd
	*/
	MESSAGE( Ev_MT_CodecSetMicGain_Ntf )
	BODY(mt::TU32, vol)




	/*<<��Ƶ����ӿ�״̬��ѯ����>>
	*���䷽��mtsdk->mtservice->mtmp
	* see Ev_MT_MtmpAudioInputState_Rsp
	*/
	MESSAGE( Ev_MT_MtmpAudioInputState_Req )
	BODY(mt::TMultiAudInputState,   tInput_State)

	/*<<��Ƶ����ӿ�״̬��ѯ��Ӧ>>
	*���䷽��mtmp->mtservice->mtsdk
	* see Ev_MT_MtmpAudioInputState_Req
	*/
	MESSAGE( Ev_MT_MtmpAudioInputState_Rsp )
	BODY(mt::TMultiAudInputState,   tInput_State)

	/*<<��Ƶ����ӿ�״̬��ѯ����>>
	*���䷽��mtsdk->mtservice->mtmp
	* see Ev_MT_MtmpAudioOutputState_Rsp
	*/
	MESSAGE( Ev_MT_MtmpAudioOutputState_Req )
	BODY(mt::TMultiAudOutputState,   tOutput_State)

	/*<<��Ƶ����ӿ�״̬��ѯ��Ӧ>>
	*���䷽��mtmp->mtservice->mtsdk
	* see Ev_MT_MtmpAudioOutputState_Req
	*/
	MESSAGE( Ev_MT_MtmpAudioOutputState_Rsp )
	BODY(mt::TMultiAudOutputState,   tOutput_State)

	/*<<��Ƶ�ӿ�������ѯ����>>
	*���䷽��mtservice->mtmp
	* see Ev_MT_MtmpVideoInPortCap_Rsp
	*/
	MESSAGE( Ev_MT_MtmpVideoInPortCap_Req )

	/*<<��Ƶ�ӿ�������ѯ��Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_MtmpVideoInPortCap_Req
	*/
	MESSAGE( Ev_MT_MtmpVideoInPortCap_Rsp )
	BODY(mt::TMTHDVidInPortCapList, cap_list)

    /*<<��Ƶ�ӿ����������ϱ�>>
	*���䷽��mtservice->mtmp
	* see 
	*/
	MESSAGE( Ev_MT_MtmpVideoInPortCap_Cmd )

	/*<<��Ƶ�ӿ����������ϱ�>>
	*���䷽��mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_MtmpVideoInPortCap_Ntf )
	BODY(mt::TMTHDVidInPortCapList, cap_list)

	/*<<������Ƶ����ӿ�����>>
	*���䷽��mtsdk->mtservice->mtmp
	* see Ev_MT_CodecSetVidInPortCfg_Ntf
	*/
	MESSAGE(Ev_MT_CodecSetVidInPortCfg_Cmd)
	BODY(mt::TMTHDVidInPort, port_list)

	/*<<������Ƶ����ӿ���Ӧ>>
	*���䷽��mtmp->mtservice->mtsdk
	* see Ev_MT_CodecSetVidInPortCfg_Cmd
	*/
	MESSAGE(Ev_MT_CodecSetVidInPortCfg_Ntf)
	BODY(mt::TMTHDVidInPort, port_list)

	/*<<���ö�����������>>
	*���䷽��mtsdk->mtservice->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_CodecSetMultiVideoCfg_Cmd)
	BODY(mt::TMTHDMultiVideo, multi_video)

	/*<<�������������������>>
	*���䷽��mtsdk->mtservice->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_CodecSetVideoMatrixSchemeCfg_Cmd)
	BODY(mt::TMTAllVideoMatrixScheme, matrix_scheme)

	/*<<������Ƶ����ӿ�>>
	*���䷽��mtservice->mtmp
	* see 
	*/
	MESSAGE( Ev_MT_CodecSetAudInPortList_Cmd )
	BODY(mt::TMTHDAudInPortList, tPortList)

	/*<<������Ƶ����ӿ�>>
	*���䷽��mtservice->mtmp
	* see 
	*/
	MESSAGE( Ev_MT_CodecSetAudOutPortList_Cmd )
	BODY(mt::TMTHDAudOutPortList, tPortList)

	/*<<��ƵԴ�ֱ��ʲ�ѯ>>
	*���䷽��mtservice->mtmp
	* see Ev_MT_MtmpVidSrcStatus_Rsp
	*/
	MESSAGE( Ev_MT_MtmpVidSrcStatus_Req )

	/*<<��ƵԴ�ֱ��ʲ�ѯ��Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_MtmpVidSrcStatus_Req
	*/
	MESSAGE( Ev_MT_MtmpVidSrcStatus_Rsp )
	BODY(mt::TMtVidSrcInfoList, src_info_list)

	/*<<��ƵԴ�ֱ����ϱ�>>
	*���䷽��mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_MtmpVidSrcStatus_Ntf )
	BODY(mt::TMtVidSrcInfoList, src_info_list)

	/*<<��Ƶ����ӿڷֱ��ʲ�ѯ>>
	*���䷽��mtservice->mtmp
	* see Ev_MT_MtmpVidInPortRes_Rsp
	*/
	MESSAGE( Ev_MT_MtmpVidInPortRes_Req )

	/*<<��Ƶ����ӿڷֱ��ʲ�ѯ��Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_MtmpVidInPortRes_Req
	*/
	MESSAGE( Ev_MT_MtmpVidInPortRes_Rsp )
	BODY(mt::TMtVidInPortResInfoList, src_info_list)

	/*<<��Ƶ����ӿڷֱ����ϱ�>>
	*���䷽��mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_MtmpVidInPortRes_Ntf )
	BODY(mt::TMtVidInPortResInfoList, src_info_list)

	/*<<��ѯSDI�ӿ���������>>
	*���䷽��mtservice->mtmp
	* see Ev_MT_MtmpGetSdiInOut_Rsp
	*/
	MESSAGE( Ev_MT_MtmpGetSdiInOut_Req )

	/*<<��ѯSDI�ӿ�������Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_MtmpGetSdiInOut_Req
	*/
	MESSAGE( Ev_MT_MtmpGetSdiInOut_Rsp )
	BODY(mt::TS32, sdi_inout) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmSdiInOut

	/*<<Fxo����>>
	*���䷽��mtservice->mtmp
	* see 
	*/
	MESSAGE( Ev_MT_FxoMakeCall_Cmd )
	BODY(mt::TString, achPeerNumber)

	/*<<Fxo���н���>>
	*���䷽��mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_FxoCallIncoming_Ntf )
	BODY(mt::TString, achPeerNumber)	//�ײ���ʱ��ȡ�����Զ˺���

	/*<<Fxo ���ܺ���>>
	*���䷽��mtservice->mtmp
	* see 
	*/
	MESSAGE( Ev_MT_FxoAccept_Cmd )

	/*<<Fxo �ܾ�����>>
	*���䷽��mtservice->mtmp
	* see 
	*/
	MESSAGE( Ev_MT_FxoReject_Cmd )

	/*<<Fxo �Ҷϵ绰>>
	*���䷽��mtservice->mtmp
	* see 
	*/
	MESSAGE( Ev_MT_FxoHangup_Cmd )

	/*<<Fxo����״̬��Ϣ�ϱ�>>
	*���䷽��mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_FxoCallLinkState_Ntf )
	BODY(mt::TFxoState, tFxo_state)

	/*<<Fxo���д������ϱ�>>
	*���䷽��mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_FxoCallErrorCode_Ntf )
	BODY(mt::TU32, error_code)	//0:δ�ӵ绰��

	/*<<�����������>>
	*���䷽��mtervice->mtmp
	* see Ev_MT_CodecSnapshot_Rsp
	*/
	MESSAGE( Ev_MT_CodecSnapshot_Req )
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, coder_id) //����һ·�Ŀ��ա�ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<���������Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_CodecSnapshot_Req
	*/
	MESSAGE( Ev_MT_CodecSnapshot_Rsp )
	BODY(mt::TU32, snapshot_state) //��������״̬ 0���ɹ� 1���������������� 2�����̿ռ䲻�� 3:�ɼ�����ͼ�� 4: �Զ������� 5:�ϴ���ftp������ʧ��
	BODY(mt::TSnapshotFileInfo, file_info) //Я�������ļ�����Ϣ

	/*<<�����ɿ����ϱ�>>
	*���䷽��mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_CodecSnapshot_Ntf )
	BODY(mt::TSnapshotFileInfo, file_info) //Я�������ļ�����Ϣ

    /*<<ftp���մ����ϱ�>>
	*���䷽��mtmp->mtmp
	* 
	*/
	MESSAGE( Ev_MT_CodecSendFileToFtp_Ntf )

	/*<<��ѯ�����ļ��б���Ϣ����>>
	*���䷽��mtervice->mtmp
	* see Ev_MT_CodecSnapshotQueryFileList_Rsp
	*/
	MESSAGE( Ev_MT_CodecSnapshotQueryFileList_Req )

	/*<<��ѯ�����ļ��б���Ϣ��Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_CodecSnapshotQueryFileList_Req
	*/
	MESSAGE( Ev_MT_CodecSnapshotQueryFileList_Rsp )
	BODY(mt::TS32, report_state) //һ����Ϣ�ϱ������ļ��б�ʱЯ����Ϣ���кţ����кŴ�1��ʼ�����������յ����һ����ϢʱЯ��-1��ֻ�ϱ�һ����ϢʱЯ��0��
	BODY(mt::TSnapshotFileList, file_info)

	/*<<ɾ��һ�ſ�������>>
	*���䷽��mtervice->mtmp
	* see Ev_MT_CodecSnapshotDelOneFile_Rsp
	*/
	MESSAGE( Ev_MT_CodecSnapshotDelOneFile_Req )
	BODY(mt::TSnapshotFileInfo, file_info) //�ļ���Ϣ

	/*<<ɾ��һ�ſ�����Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_CodecSnapshotDelOneFile_Req
	*/
	MESSAGE( Ev_MT_CodecSnapshotDelOneFile_Rsp )
	BODY(mt::TBOOL32, del_state) //�Ƿ�ɾ���ɹ�
	BODY(mt::TSnapshotFileInfo, file_info)

	/*<<һ�ſ��ձ�ɾ���ϱ�>>
	*���䷽��mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_CodecSnapshotDelOneFile_Ntf )
	BODY(mt::TSnapshotFileInfo, file_info)

	/*<<������һ�ſ�������>>
	*���䷽��mtervice->mtmp
	* see Ev_MT_CodecSnapshotRenameOneFile_Req
	*/
	MESSAGE( Ev_MT_CodecSnapshotRenameOneFile_Req )
	BODY(mt::TSnapshotFileInfo, file_info_old) //������ǰ���ļ���Ϣ
	BODY(mt::TSnapshotFileInfo, file_info_new) //����������ļ���Ϣ

	/*<<������һ�ſ�����Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_CodecSnapshotRenameOneFile_Req
	*/
	MESSAGE( Ev_MT_CodecSnapshotRenameOneFile_Rsp )
	BODY(mt::TBOOL32, rename_state) //�Ƿ��������ɹ�
	BODY(mt::TSnapshotFileInfo, file_info_old)//������ǰ���ļ���Ϣ
	BODY(mt::TSnapshotFileInfo, file_info_new)//����������ļ���Ϣ

	/*<<ɾ�����п����ļ�����>>
	*���䷽��mtervice->mtmp
	* see Ev_MT_CodecSnapshotDelAllFile_Rsp
	*/
	MESSAGE( Ev_MT_CodecSnapshotDelAllFile_Req )

	/*<<ɾ�����п����ļ���Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_CodecSnapshotDelAllFile_Req
	*/
	MESSAGE( Ev_MT_CodecSnapshotDelAllFile_Rsp )
	BODY(mt::TBOOL32, del_state) //�Ƿ�ɾ���ɹ�

	/*<<���п����ļ����֪ͨ>>
	*���䷽��mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_CodecSnapshotDelAllFile_Ntf )

	/*<<����һ�ſ����ļ�����>>
	*���䷽��mtervice->mtmp
	* see Ev_MT_CodecSnapshotExportOneFile_Rsp
	*/
	MESSAGE( Ev_MT_CodecSnapshotExportOneFile_Req )
	BODY(mt::TSnapshotFileInfo, file_info) //�ļ���Ϣ

	/*<<����һ�ſ����ļ���Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_CodecSnapshotExportOneFile_Req
	*/
	MESSAGE( Ev_MT_CodecSnapshotExportOneFile_Rsp )
	BODY(mt::TBOOL32, export_state) //�Ƿ񵼳��ɹ�
	BODY(mt::TSnapshotFileInfo, file_info)

	/*<<�������п����ļ�����>>
	*���䷽��mtervice->mtmp
	* see Ev_MT_CodecSnapshotExportAllFile_Rsp
	*/
	MESSAGE( Ev_MT_CodecSnapshotExportAllFile_Req )

	/*<<�������п����ļ���Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_CodecSnapshotExportAllFile_Req
	*/
	MESSAGE( Ev_MT_CodecSnapshotExportAllFile_Rsp )
	BODY(mt::TS32, export_state) //����״̬ mt::EmFileCopyErr


    /*<<�������ս���>>
	*���䷽��mtmp->mtservice
	*/
	MESSAGE( Ev_MT_CodecSnapshotExportProgress_Ntf )
	BODY(mt::TU32, progress) //��������(�ٷֱ�)

	/*<<����������־�ļ�����>>
	*���䷽��mtervice->mtmp
	* see Ev_MT_ExportAllLogFile_Rsp
	*/
	MESSAGE( Ev_MT_ExportAllLogFile_Req )

	/*<<����������־�ļ���Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_ExportAllLogFile_Req
	*/
	MESSAGE( Ev_MT_ExportAllLogFile_Rsp )
	BODY(mt::TS32, export_state) //����״̬ mt::EmFileCopyErr

	/*<<������־����>>
	*���䷽��mtmp->mtservice
	*/
	MESSAGE( Ev_MT_AllLogFileExportProgress_Ntf )
	BODY(mt::TU32, progress) //��������(�ٷֱ�)

	/*<<����ftp>>
	*���䷽��mtervice->mtmp
	*index : ��ǰ������Ԥ��λ����
	* see Ev_MT_CodecFtpJpeg_Ntf
	*/
	MESSAGE( Ev_MT_CodecFtpJpeg_Cmd )
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, coder_id) //����һ·�Ŀ��ա�ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<����ftp>>
	*���䷽��mtmp->mtservice
	*index : ��ǰ������Ԥ��λ����
	* see Ev_MT_CodecFtpJpeg_Cmd
	*/
	MESSAGE( Ev_MT_CodecFtpJpeg_Ntf )
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, coder_id) //����һ·�Ŀ��ա�ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TBOOL32, is_sucess) //�Ƿ�����ɹ�

	/*<<��������ͷԤ��λͼƬ����>>
	*���䷽��mtdevice->mtmp
	*index : ��ǰ������Ԥ��λ����
	* see Ev_MT_CodecCameraPic_Ntf
	*/
	MESSAGE( Ev_MT_CodecCameraPic_Cmd )
    BODY(mt::TS32, vid_idx) // �ĵڼ��������
	//BODY(mt::TS32, coder_id) //����һ·�Ŀ��ա�ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	//BODY(mt::TS32, video_port)//��Ӧ������ͷ���á�ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmMtVideoPort
	BODY(mt::TS32, save_idx)//����ĵڼ���Ԥ��λ

	/*<<��������ͷԤ��λͼƬ��Ӧ>>
	*���䷽��mtmp->mtservice
	*index : ��ǰ������Ԥ��λ����
	* see Ev_MT_CodecCameraPic_Cmd
	*/
	MESSAGE( Ev_MT_CodecCameraPic_Ntf )
	BODY(mt::TS32, coder_id) //����һ·�Ŀ��ա�ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TS32, video_port)//��Ӧ������ͷ���á�ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmMtVideoPort
	BODY(mt::TS32, save_idx)//����ĵڼ���Ԥ��λ
	BODY(mt::TBOOL32, is_sucess) //�Ƿ�����ɹ�


    /*<<�������ͼƬ���㹦��>>
	*���䷽��mtervice->mtmp
	* see Ev_MT_CodecMonitorPic_Ntf
	*/
    MESSAGE( Ev_MT_CodecMonitorPic_Cmd )
    BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
    BODY(mt::TS32, coder_id) //����һ·�Ŀ��ա�ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TBOOL32, opt)//TRUE����   FALSE�ر�
    BODY(mt::TS32, pic_index)//��һ�λ�ȡ���յ�index 0/1

	/*<<�������ͼƬ���㹦����Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_CodecMonitorPic_Cmd
	*/
    MESSAGE( Ev_MT_CodecMonitorPic_Ntf )
    BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
    BODY(mt::TS32, coder_id) //����һ·�Ŀ��ա�ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TBOOL32, status)//TRUE����   FALSE�ر�

    /*<<ͼƬ��ȡ>>
	*���䷽��mtservice->mtmp
	* see Ev_MT_CodecPicGet_Rsp
	*/
    MESSAGE( Ev_MT_CodecPicGet_Req )
    BODY(mt::TS32, index)//��ȡ�ļ��ͼƬindex 0/1

	/*<<ͼƬ��ȡ��Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_CodecPicGet_Req
	*/
    MESSAGE( Ev_MT_CodecPicGet_Rsp )
	BODY(mt::TBOOL32, result)//��ȡ���

    /*<<��ѯ���ͼƬ���㹦���Ƿ���>>
	*���䷽��mtervice->mtmp
	* see Ev_MT_CodecMonitorPicStatus_Rsp
	*/
    MESSAGE( Ev_MT_CodecMonitorPicStatus_Req )
    BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
    BODY(mt::TS32, coder_id) //����һ·�Ŀ��ա�ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<��ѯ���ͼƬ���㹦����Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_CodecMonitorPicStatus_Req
	*/
    MESSAGE( Ev_MT_CodecMonitorPicStatus_Rsp )
    BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
    BODY(mt::TS32, coder_id) //����һ·�Ŀ��ա�ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TBOOL32, status)//TRUE����   FALSE�ر�




	/*<<������ƵԴѡ��ָ��>>
	*encoder_id    ����һ·����ƵԴ���ڶ�·����ƵԴ
	*��Ϣ���� ��service==>dispatch==>mtmp
	* see Ev_MT_CodecSelectLocalVideoView_Ntf
	*/
    MESSAGE(Ev_MT_CodecSelectLocalVideoView_Cmd)
	BODY(mt::TS32, encoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<������ƵԴѡ��֪ͨ>>
	*encoder_id    ����һ·����ƵԴ���ڶ�·����ƵԴ
	*��Ϣ���� ��mtmp==>dispatch==>service
	* see Ev_MT_CodecSelectLocalVideoView_Cmd
	*/
    MESSAGE(Ev_MT_CodecSelectLocalVideoView_Ntf)
	BODY(mt::TS32, encoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<������ƵԴѡ�����ݲ�ѯ����>>
	*encoder_id    ����һ·����ƵԴ���ڶ�·����ƵԴ
	*��Ϣ���� ��service==>dispatch==>mtmp
	* see Ev_MT_CodecGetLocalVideoView_Rsp
	*/
    MESSAGE(Ev_MT_CodecGetLocalVideoView_Req)

	/*<<������ƵԴѡ�����ݲ�ѯ��Ӧ>>
	*encoder_id    ����һ·����ƵԴ���ڶ�·����ƵԴ
	*��Ϣ���� ��mtmp==>dispatch==>service
	* see Ev_MT_CodecGetLocalVideoView_Req
	*/
    MESSAGE(Ev_MT_CodecGetLocalVideoView_Rsp)
	BODY(mt::TS32, encoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<ˢ��̨��>>
	*pic_file_name    ����̨��ͼƬ���ļ���
	*��Ϣ���� ��service==>dispatch==>mtmp
	* see 
	*/
    MESSAGE(Ev_MT_CodecLabelUpdate_Cmd)
	BODY(mt::TMTLabelInfo, TMTLabelInfo)
    BODY(mt::TBOOL32, openlabel)   // �Ƿ���Ҫ��̨��

	/*<<ˢ�º��>>
	*pic_file_name    ���º��ͼƬ���ļ���
	*��Ϣ���� ��service==>dispatch==>mtmp
	* see 
	*/
    MESSAGE(Ev_MT_CodecBannerUpdate_Cmd)
	BODY(mt::TMTBannerInfo, TMTBannerInfo)
    BODY(mt::TMultiU32, actual_linenum)

	/*<<������Ƶ��ʾ����>>
	*display_ratio    ����ʾ����
	*��Ϣ���� ��service==>dispatch==>mtmp
	* see 
	*/
    MESSAGE(Ev_MT_CodecSetDisplayRatio_Cmd)
    BODY(mt::TMTDisplayRatio, display_ratio)

	/*<<��Ƶ��������ӿ�����֪ͨ��Ϣ>>
	*port_mode    ���ӿ�ģʽ
	*��Ϣ���� ��mtmp�ڲ�ʹ��
	* see 
	*/
    MESSAGE(Ev_MT_CodecVideoInOutPortMode_Ntf)
    BODY(mt::TMTVideoInOutPortModeList, port_mode)

	/*<<������Ƶ���ȡ��Աȶȡ����Ͷ�>>
	*��Ϣ���� ��service==>dispatch==>mtmp
	* see 
	*/
    MESSAGE(Ev_MT_CodecSetVidImgParam_Cmd)
	BODY(mt::TS32, codec_type)//�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TS32, param_type) //�ô�ʵ��Ϊmt::EmImgParam
	BODY(mt::TU32, param_value)//����ֵ

	/*<<������Ƶ����ֱ���>>
	*��Ϣ���� ��service==>dispatch==>mtmp
	* see 
	*/
	MESSAGE(Ev_MT_CodecSetHDResOutput_Cmd)
	BODY(mt::TMTVideoOutPortMode, video_mode)

	/*<<������Ƶ��������>>
	*��Ϣ���� ��service==>dispatch==>mtmp
	* see 
	*/
    MESSAGE(Ev_MT_CodecSetDeformationTensile_Cmd)
    BODY(mt::TMTHDImageDeformationTensile, Tensile)

	/*<<������Ƶ�ȱ�����>>
	*��Ϣ���� ��service==>dispatch==>mtmp
	* see 
	*/
    MESSAGE(Ev_MT_CodecSetGeometricScaling_Cmd)
    BODY(mt::TMTHDImageGeometricScaling, Scaling)

	/*<<����ͼ����ȼ�>>
	*��Ϣ���� ��service==>dispatch==>mtmp
	* see 
	*/
    MESSAGE(Ev_MT_CodecSetImageNoiseLevel_Cmd)
    BODY(mt::TMTHDImageNoise, Noise)

	/*<<���ý����Ӻڱߡ��ñ���ǵȱȵ���Ƶ�������>>
	*��Ϣ���� ��service==>dispatch==>mtmp
	* see 
	*/
    MESSAGE(Ev_MT_CodecSetResizeMode_Cmd)
    BODY(mt::TMTResizeMode, ResizeMode)

	/*<<����VGA������ȡ��Աȶȡ����Ͷ�>>
	*��Ϣ���� ��service==>dispatch==>mtmp
	* see 
	*/
    MESSAGE(Ev_MT_CodecSetVgaOutImgParam_Cmd)
	BODY(mt::TS32, param_type) //�ô�ʵ��Ϊmt::EmImgParam
	BODY(mt::TU32, param_value)//����ֵ



	/*<<��ѯ��������ļ�����>>
	*���䷽��mtervice->mtmp
	* see Ev_MT_CodecSnapshotQueryLatestFile_Rsp
	*/ 
	MESSAGE( Ev_MT_CodecSnapshotQueryLatestFile_Req )

	/*<<��ѯ��������ļ���Ӧ>>
	*���䷽��mtmp->mtservice
	* see Ev_MT_CodecSnapshotQueryLatestFile_Req
	*/
	MESSAGE( Ev_MT_CodecSnapshotQueryLatestFile_Rsp )
	BODY(mt::TU32, result) //��ѯ״̬��� 0���ɹ� 1��ʧ��
	BODY(mt::TSnapshotFileInfo, file_info) //Я�����������ļ�����Ϣ

    /*<<��ȡ����ƵԴ�Ƿ���Դ����>>
	*���䷽��mtservice_hd->mtmp
	* see Ev_MT_AssVideoPortStatus_Rsp
	*/
	MESSAGE( Ev_MT_AssVideoPortStatus_Req )

	/*<<��ȡ����ƵԴ�Ƿ���Դ��Ӧ>>
	*���䷽��mtmp->mtservice_hd
	* see Ev_MT_AssVideoPortStatus_Req
	*/
	MESSAGE( Ev_MT_AssVideoPortStatus_Rsp )
	BODY(mt::TS32, vga_state) //Vga�Ƿ����1:���� 0:δ����
    BODY(mt::TS32, hdmi_state) //Hdmi�Ƿ����1:���� 0:δ����

	/*<<����OSD>>
	*���䷽��mtmfgtest/mtservice->mtmp
	* see 
	*/
	MESSAGE( Ev_MT_CodecSetOsdOpen_Cmd )

    /*<<����OSD>>
	*���䷽��mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_CodecSetOsdOpen_Ntf )
    BODY(mt::TBOOL32, bSuccess)

	/*<<�ر�OSD>>
	*���䷽��mtmfgtest/mtservice->mtmp
	* see 
	*/
	MESSAGE( Ev_MT_CodecSetOsdClose_Cmd )

    /*<<�ر�OSD>>
	*���䷽��mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_CodecSetOsdClose_Ntf )
    BODY(mt::TBOOL32, bSuccess)

    /*<<�������ر�OSD��͸����>>
	*��Ϣ���� ��mtservice==>dispatch==>mtmpapp
	* see Ev_MT_SetOsdTransparent_Rsp
	*/
    MESSAGE(Ev_MT_SetOsdTransparent_Req)
	BODY(mt::TBOOL32, trans)

	/*<<�������ر�OSD��͸��Ӧ>>
	*��Ϣ���� ��mtmpapp==>dispatch==>mtservice
	* see Ev_MT_SetOsdTransparent_Req
	*/
    MESSAGE(Ev_MT_SetOsdTransparent_Rsp)
    BODY(mt::TBOOL32, trans)
    BODY(mt::TS32, result)

	/*<<������ͼ����ʾ����>>
	*��Ϣ���� ��mtservice==>dispatch==>mtmpapp
	* see 
	*/
    MESSAGE(Ev_MT_SetLastDisplayCfg_Cmd)
    BODY(mt::TMTLastDisplay, )

	/*<<VGAͼ�����>>
	*��Ϣ���� ��mtservice==>dispatch==>mtmpapp
	* see 
	*/
    MESSAGE(Ev_MT_SetVGAImageAdjustCfg_Cmd)
    BODY(mt::TMTVgaImageAdjustCfg, )

	/*<< �Զ�����ʱ�Ӽ������ >>
	*[��Ϣ��]
	*    + start: ��ʼ��ֹͣ
	*[��Ϣ����]
	*    mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_AutoAudioDelayCheckCmd)
	BODY(mt::TBOOL32, start)

	/*<< �Զ�����ʱ�Ӽ��֪ͨ >>
	*[��Ϣ��]
	*    + state(EmAudioDelayCheckState)�����״̬
	*    + result����EmAudioDelayCheckStateΪemAudioDelayCheckedʱ����ֵ��Ч����ʾʱ��ֵ
	*             ��EmAudioDelayCheckStateΪemAudioDelayFailedʱ����ֵ��Ч����ʾʧ�ܴ�����
	*[��Ϣ����]
	*    mtmpapp=>dispatch=>mtservice
	*/
	MESSAGE(Ev_MT_AutoAudioDelayCheckNtf)
	BODY(mt::TU32, state)
	BODY(mt::TU32, result)


    /*<<���л���ʾ����>>
	*��Ϣ���� ��mtservice==>dispatch==>mtmpapp
	*/
    MESSAGE(Ev_MT_SetAutoPip_Cmd)
	BODY(mt::TBOOL32, autopip)

    /*<������ر�OSD����֪ͨ>
    *���䷽��mtmpapp=>dispatch=>mtservice
    *see Ev_MT_CodecOsdSnapshot_Cmd
    */
    MESSAGE(Ev_MT_CodecOsdSnapShotOpen_Ntf)
    BODY(mt::TBOOL32, opt)  // TRUE�� FLASE�ر�

    /*<<����OSD������������>>
	*���䷽��mtservice=>dispatch=>mtmpapp
	* see Ev_MT_CodecOsdSnapshotOpen_Ntf
	*/
    MESSAGE(Ev_MT_CodecOsdSnapshot_Cmd)

    	/*<�����Ƿ���ʾosd>
    *���䷽��mtservice->mtmpapp
    *
    */
    MESSAGE(Ev_MT_CodecSetShowOsd_Cmd)
	BODY(mt::TBOOL32, bShow)  // TRUE�� FLASE�ر�

	/*<֪ͨ�Ƿ���ʾosd>
    *���䷽��mtmpapp->mtservice
    *
    */
    MESSAGE(Ev_MT_CodecIsShowOsd_Ntf)
	BODY(mt::TBOOL32, bShow)  // TRUE�� FLASE�ر�

    /*<SDI�������״̬�ı�>
    *���䷽��mtservice->mtservice_hd
    *
    */
    MESSAGE(Ev_MT_SDIOutputStateUpdate_Cmd)
    BODY(mt::TBOOL32, bSdiOutOff)  // sdi������Ƿ��

	/*<����¼�񿪹�>
    *���䷽��mtmpapp=>mtasfRecord
    */
    MESSAGE(EV_MT_Record_Start_Cmd)
	BODY(mt::TString, PathName)  // ����¼���ļ���

	 /*<����¼�񿪹ؽ���ظ�>
    *���䷽��mtasfapp=>mtmpapp    mtasfapp=>dispatch
    */
    MESSAGE(EV_MT_Record_Start_Ntf)               
	BODY(mt::TBOOL32, opt)  // �ɹ���

	/*<�ر�¼�񿪹�>
    *���䷽��mtmpapp=>mtasfapp
    */
    MESSAGE(EV_MT_Record_Stop_Cmd)         
	BODY(NULL,NULL )  // 

	/*<�ر�¼�񿪹ػظ�>
    *���䷽��mtasfapp=>dispatch
    */
    MESSAGE(EV_MT_Record_Stop_Ntf)       
	BODY(mt::TBOOL32,NULL )  // 

	/*<�����Ƶ¼����>
    *���䷽��mtmpapp=>mtasfapp
    */
    MESSAGE(EV_MT_Record_AddStream_Audio_Cmd)
	BODY( TAddRecordAudioMediaInfo, tAddRecordAudioMediaInfoMess )  // �����Ƶ���Ľ�ṹ

	/*<�����Ƶ¼����>
    *���䷽��mtmpapp=>mtasfapp
    */
    MESSAGE(EV_MT_Record_AddStream_Video_Cmd)
	BODY( TAddRecordVideoMediaInfo, tAddRecordVideoMediaInfoMess )  // �����Ƶ���Ľ�ṹ

	/*<���¼�����ظ�>
    *���䷽��mtasfapp=>mtmpapp
    */
    MESSAGE(EV_MT_Record_AddStream_Ntf)
	BODY( u32 && TBOOL32 ,NULL )  //  ������Ľ�ṹ		

	/*<д��¼�����ݵ��ļ�>
    *���䷽��mtmpapp=>mtasfapp
    */
    MESSAGE(EV_MT_Record_WriteRecord_Cmd)
	BODY( NULL, NULL )  // д�����ݵĽṹ

		/*<д��¼�����ݵ��ļ�>
    *���䷽��mtmpapp=>mtasfapp
    */
    MESSAGE(EV_MT_Record_WriteRecord_Ntf)
	BODY( NULL, NULL )  // д�����ݵĽṹ

	/*<¼�����ݷ����仯>
    *���䷽��mtmpapp=>mtmpapp
    */
    MESSAGE(EV_MT_Record_DataChange_Ntf)		
	BODY(NULL,NULL )  //  ��

	/*<¼��״̬��Ӧ>
    *���䷽��mtasfapp=>dispatch
    */
    MESSAGE(EV_MT_Record_Status_Ntf)
	BODY(mt::u32, dwStreamNum)  // �ĸ�λ�ó���������
	BODY(mt::u32, dwStatus)  // ¼���״̬

		/*<��ͣ¼��>
    *���䷽��dispatch=>mtmpappp
    */
    MESSAGE(EV_MT_Record_Pause_Cmd)			
	BODY( NULL, NULL )  // 

	/*<��ͣ¼��ظ�>
    *���䷽��mtmpapp=>dispatch
    */
    MESSAGE(EV_MT_Record_Pause_Ntf)			
	BODY( mt::TBOOL32, NULL )  // 

	/*<����¼��>
    *���䷽��dispatch=>mtmpappp
    */
    MESSAGE(EV_MT_Record_Continue_Cmd)		
	BODY( NULL, NULL )  // 

	/*<����¼��ظ�>
    *���䷽��mtmpapp=>dispatch
    */
    MESSAGE(EV_MT_Record_Continue_Ntf)		
	BODY( mt::TBOOL32, NULL )  // 

	/*<���洢�ռ�����>
    *���䷽��dispatch=>mtmpapp=>mtasfapp
    */
    MESSAGE(EV_MT_Record_Check_StorageSpace_Req)		
	BODY( NULL, NULL )  //

	/*<���洢�ռ�ظ�>
    *���䷽��dispatch <= mtasfapp
    */
    MESSAGE(EV_MT_Record_Check_StorageSpace_Rsp)		
	BODY( U32, dwSpaceSize )  //

	/*<ʣ��¼��ʱ��ظ�>
    *���䷽�� dispatch <= mtasfapp
    */
    MESSAGE(EV_MT_Record_RemainTime_Ntf)		
	BODY( U32, dwRemainTime )  // ʣ��ʱ�� S

	/*<ʣ��¼��ʱ�䶨ʱ��>
    *���䷽��videorecord->dispatch
    */
    MESSAGE(EV_MT_Record_Remain_Timer)		// ntf
	BODY( NULL, NULL )  // 

	/*<ʣ��¼��ռ䶨ʱ��>
    *���䷽��videorecord->dispatch
    */
    MESSAGE(EV_MT_Record_CheckSpace_Timer)		// ntf
	BODY( NULL, NULL )  //

	/*<����¼���Ѿ�¼��ʱ��>
    *���䷽��videorecord->dispatch
    */
    MESSAGE(EV_MT_Record_Start_time_Cmd)		
	BODY( NULL , NULL )  // 

	/*<�ظ�¼���Ѿ�¼��ʱ��>
    *���䷽��videorecord->dispatch
    */
    MESSAGE(EV_MT_Record_Start_time_Ntf)		
	BODY( mt::TU32 , tdwRecordTime )  // �Ѿ�¼��ʱ�� ������

		/*<����¼��>
    *���䷽��mtmpapp=>mtasfRecord
    */
    MESSAGE(EV_MT_Record_ReStart_Cmd)
	BODY(mt::TString, PathName)  // ����¼���ļ���

	/*<¼��Ӧ��ʱ��>
    *���䷽��videorecord->dispatch
    */
    MESSAGE( EV_MT_Record_CheckRespond_Timer )		// ntf
	BODY( NULL, NULL )  //

    /*<����ϴ����õ�̨����Ϣ>
    *���䷽��mtmpapp=>mtservice_hd
    */
    MESSAGE(EV_MT_Clear_Label_Cmd)

    /*<sdi״̬�仯����Դ��Ϣ>
    *���䷽��mtmpapp=>mtservice_hd
    */
    MESSAGE(EV_MT_SDIInputPortNumChange_Cmd)
    BODY(mt::TS32, SdiInout)  // sdi�������״̬

    /*<<˫��ģʽ��˫���µڶ����Ƿ���ʾԶ�˸�������>>
	*��Ϣ���� ��mtservice==>dispatch==>mtmpapp
	*/
    MESSAGE(Ev_MT_ShowRemoteAssVideo_Cmd)
	BODY(mt::TBOOL32, showRemoteAssVideo)

    /*<Ӳ��оƬ��ȡ����>
    *���䷽��mtservice=>dispatch=>mtmpapp
    */
    MESSAGE(EV_MT_HwChipInfoInquire_Req)

	/*<Ӳ��оƬ��ȡ����ظ�>
    *���䷽��mtmpapp=>dispatch=>mtservice
    */
    MESSAGE(EV_MT_HwChipInfoInquire_Rsp)		
	BODY( mt::TMtHwChipInfoList, hwchipinfolist )

	/*<Ӳ��оƬ��ȡ��Ӧ>
    *���䷽�� mtmpapp=>dispatch=>mtservice
    */
    MESSAGE(EV_MT_HwChipInfoInquire_Ntf)		
	BODY( mt::TMtHwChipInfoList, hwchipinfolist )
	
	/*<���ظ�����������>
    *���䷽�� sdk=>dispatch=>mtservice
    */
    MESSAGE(EV_MT_SetSubAudExpansion_Cmd)		
	BODY( mt::TBOOL32, bSubAudExpansion )

	/*<���ظ�������������Ӧ>
    *���䷽�� mtservice=>dispatch=>sdk
    */
    MESSAGE(EV_MT_SetSubAudExpansion_Ntf)		
	BODY( mt::TBOOL32, bSubAudExpansion )
	BODY( mt::TU32, result )
	
	/*<<<����ȡ������֪ͨ>>
	* ��Ϣ���� ��mp==>dispatch==>mtservice
	*/
	MESSAGE( Ev_MT_ConfNotKeepAlive_Ntf )

    /*<<<����֪ͨ����>>
    * ��Ϣ���� ��mtmp==>dispatch==>mtservice
    */
    MESSAGE(Ev_MT_VidStreamAppear_Ntf)
    BODY(mt::TS32, type)  //���ֵ����ȷ���ǻص��յ�����ʱ���ϱ���������ʱ���ϱ�

#if !defined(_MESSAGE_HELP_)
    EV_END(MPEMBED) = EVSEG_MPCOMMON_END
};
#endif

#define Is_MPEmbed_Msg(m) ((m) >= Ev_MT_BGN(MPEMBED) && (m) <= Ev_MT_END(MPEMBED))

#endif // _MTMPEMBEDMSG_H_