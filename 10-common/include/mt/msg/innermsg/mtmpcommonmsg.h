#ifndef _MTMPCOMMONMSG_H_
#define _MTMPCOMMONMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMPCommonMsg
{
    EV_BGN(MPCOMMON) = EVSEG_MPCOMMON_BGN,
#endif

	/*<<���͹ؼ�֡����>>
	*codec_type ����������
	*encoder_id ����������
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecFastUpdate_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<��Ƶ��������Ҫ�ؼ�֪֡ͨ>>
	*codec_type ����������
	*encoder_id ����������
	*��Ϣ���� ��mtmp==>dispatch==>service
	*/
	MESSAGE(Ev_MT_CodecNeedKeyFrame_Ntf)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, decoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<���ñ�������>>
	*codec_type ����������
	*encoder_id ����������
	*bitrate    ������
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecSetBitrate_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TU16, bitrate)

	/*<<��������ֱ���>>
	*codec_type ����������
	*encoder_id ����������
	*width      ����
	*height     ����
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecSetEncRes_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TU16, width)
	BODY(mt::TU16, height)

	/*<<��������֡��>>
	*codec_type ����������
	*encoder_id ����������
	*fps        ��֡��
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecSetEncFps_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TU8, fps)

	/*<<���ñ�������ַ����>>
	*codec_type ����������
	*encoder_id ����������
	*rtp_local_addr   ������rtp���ı��ص�ַ
	*rtcp_local_addr  �����ͽ���rtcp���ı��ص�ַ
	*rtp_remote_addr  ������rtp����Զ��Ŀ�ĵ�ַ
	*rtcp_remote_addr ������rtcp����Զ��Ŀ�ĵ�ַ
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetChanSndAddr_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TNetAddr, rtp_local_addr)
	BODY(mt::TNetAddr, rtcp_local_addr)
	BODY(mt::TNetAddr, rtp_remote_addr)
	BODY(mt::TNetAddr, rtcp_remote_addr)	//

	/*<<���ý�������ַ����>>
	*codec_type ����������
	*encoder_id ����������
	*rtp_local_addr   ������rtp���ı��ص�ַ
	*rtcp_local_addr  ������rtcp���ı��ص�ַ
	*rtp_remote_addr  �����ʹ򶯰���Զ�˵�ַ���˿�Ϊ0��ʾ�����ʹ򶯰��������ʹ򶯰�
	*rtcp_remote_addr ������rtcp����Զ��Ŀ�ĵ�ַ��Ҳ����������backrtcp��ַ
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetChanRcvAddr_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, decoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex	
	BODY(mt::TNetAddr, rtp_local_addr)
	BODY(mt::TNetAddr, rtcp_local_addr)
	BODY(mt::TNetAddr, rtp_remote_addr)//
	BODY(mt::TNetAddr, rtcp_remote_addr)

	/*<<���ö����ش�����>>
	*prs_param �������ش�����
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetPrsParam_Cmd)
	BODY(mt::TPrsParam, prs_param)

	/*<<����ƽ������>>
	*enable_smooth_send ���Ƿ�����ƽ������
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetSmoothSend_Cmd)
	BODY(mt::TBOOL32, enable_smooth_send)	

	/*<<���ö�̬�غ�>> Ӧ���ڷ���
	*codec_type  ����������
	*encoder_id  ����������
	*payload_map ����̬�غ�ӳ��
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetDynamicPayload_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TDynamicPayload, payload_map) //��̬�غ�ӳ��


	/*<<���ö�̬�غ�>> Ӧ���ڽ���
	*codec_type  ����������
	*encoder_id  ����������
	*payload_map_list����̬�غ�ӳ��list
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetRecvDynamicPayload_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TRpDynamicPayload, payload_map_list) //��̬�غ�ӳ��list



	/*<<�����������ӳټ����Ų���>>
	*codec_type		����������
	*encoder_id		����������
	*ucPolicy		�����Ų���
	*dwSoftlimit    ��������
	*dwHardlimit    ��Ӳ����
	
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetMaxDelay_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TU32, ucPolicy) ////���Ų���
	/*
	0 UNKNOWN 
	1 QUALITY 
	2 QUALITY_NOAVS
	3 SPEED
	4 BALANCE 
	*/
	BODY(mt::TS32, dwSoftlimit)
	BODY(mt::TS32, dwHardlimit)


	/*<<������Կ>>
	*codec_type ����������
	*encoder_id ����������
	*key        ����Կ
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetEncryptKey_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TEncryptKey, key)

	/*<<������Ƶ�������>>
	*codec_type ����������
	*encoder_id ����������
	*vid_enc_param ����Ƶ�������
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetVidEncParam_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TVidEncParam, vid_enc_param)

	/*<<������Ƶ�����������ָ���������>>
	*codec_type ����������
	*encoder_id ����������
	*lost_pack_strategy �������ָ�����
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetVidDecLostPackStrategy_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, decoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TS32, lost_pack_strategy) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmLostPackStrategy	
	BODY(mt::TBOOL32, is_rtcp_sendfastupdate) ///�Ƿ���rtcp���͹ؼ�֡����

	/*<<������Ƶ�����������>>
	*codec_type ����������
	*encoder_id ����������
	*aud_enc_param ����Ƶ�������
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecSetAudEncParam_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TAudEncDecParam, aud_enc_param)

	/*<<������Ƶ�����������>>
	*codec_type ����������
	*encoder_id ����������
	*aud_dec_param ����Ƶ�������
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecSetAudDecParam_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TAudEncDecParam, aud_dec_param)

	/*<<��ʼ��������>>
	*codec_type ����������
	*encoder_id ����������
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecChanStart_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<ֹͣ��������>>
	*codec_type ����������
	*encoder_id ����������
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecChanStop_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<��ʼ�������ĳһ·VOD������>>
	*codec_type ����������
	*encoder_id ����������
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecVodStreamStart_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<�л�VOD�㲥Դ����>>
	*codec_type ����������
	*encoder_id ����������
	*��Ϣ���� ��mtvod==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecVodSwitchStream_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<ֹͣ�������ĳһ·VOD������>>
	*codec_type ����������
	*encoder_id ����������
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecVodStreamStop_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<��ʼ��ý���鲥����>>
	*codec_type ����������
	*encoder_id ����������
	*rtp_snd_addr  ��rtp���͵�ַ
	*rtcp_snd_addr ��rtcp���͵�ַ
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecStreamMediaStart_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TNetAddr, rtp_snd_addr)
	BODY(mt::TNetAddr, rtcp_snd_addr)

	/*<<ֹͣ��ý���鲥����>>
	*codec_type ����������
	*encoder_id ����������
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecStreamMediaStop_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<��ʼĳһ·�������>>
	*codec_type ����������
	*encoder_id ����������
	*monitor_addr  ����ؽ��յ�ַ
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecMonitorStart_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TRtpRtcpPair, monitor_addr)

	/*<<ֹͣĳһ·�������>>
	*codec_type ����������
	*encoder_id ����������
	*monitor_addr  ����ؽ��յ�ַ,Ψһȷ��ĳһ·���
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecMonitorStop_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TRtpRtcpPair, monitor_addr)

	
	/*<<��ʾ���е�ת����ת���б�>>
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecMonitorShowList_Cmd)


	/*<<��ʼĳһ·¼������>>
	*codec_type ����������
	*encoder_id ����������
	*record_addr   ��¼����յ�ַ
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecRecordStart_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TRtpRtcpPair, record_addr)

	/*<<ֹͣĳһ·¼������>>
	*codec_type ����������
	*encoder_id ����������
	*record_addr : ¼����յ�ַ,Ψһȷ��ĳһ·¼��
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecRecordStop_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TRtpRtcpPair, record_addr)

	/*<<��ȡ��ز�������>>
	*codec_type ����������
	*encoder_id ����������
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecGetMonitorParam_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<��ز���֪ͨ>>
	*codec_type ����������
	*encoder_id ����������
	*media_type    ��ý������
	*media_pt      ����̬�غ�
	*key           ����Կ
	*g7221_reverse ��g7221�Ƿ�ת
	*aac_chan_num  ��aac������
	*aac_sf        ��aac������
	*tMonitorLocalRtpPort:����rtp�˿ں�
	*tMonitorLocalRtcpPort:����rtcp�˿ں�
	*��Ϣ���� ��mtmp==>dispatch==>service
	*/
    MESSAGE(Ev_MT_CodecMonitorParam_Ntf)	
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TU8, media_type)
	BODY(mt::TRpDynamicPayload, media_pt)
	BODY(mt::TEncryptKey, key)
	BODY(mt::TBOOL32, g7221_reverse)
	BODY(mt::EmAacChnlNum, aac_chan_num)
	BODY(mt::EmAacSampFreq, aac_sf)
	BODY(mt::TU32, tMonitorLocalRtpPort)
	BODY(mt::TU32, tMonitorLocalRtcpPort)

	/*<<���Ҫ��ؼ�֡����>>
	*codec_type ����������
	*encoder_id ����������
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecMonitorFastUpdate_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<����������>>
	*decoder_id   ��������id����ʶ�ڼ�·������������
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecViewLocal_Cmd)
	BODY(mt::TS32, decoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<��Զ������>>
	decoder_id   ��������id����ʶ�ڼ�·��������Զ��
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecViewOther_Cmd)
	BODY(mt::TS32, decoder_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<g7221�ֽ���ת����>>
	*codec_type ����������
	*encoder_id ����������
	*on ��TRUE-��ת FALSE-����ת
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetReverseG7221_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TBOOL32, on)

	/*<<5���ڶ���֪ͨ>>
	*lost ��TRUE-���� FALSE-������
	*��Ϣ���� ��mtmp==>dispatch==>service
	*/
    MESSAGE(Ev_MT_CodecLostPack_Ntf)
	BODY(mt::TBOOL32, lost)	

	/*<<��������>>	
	*on ����ʼorȡ������
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecQuiet_Cmd)
	BODY(mt::TBOOL32, on)

	/*<<��������>>
	*on ����ʼorȡ������
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecMute_Cmd)
	BODY(mt::TBOOL32, on)

	/*<<����Ans��������>>
	*enable  ���Ƿ�����
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecANS_Cmd)
	BODY(mt::TBOOL32, enable)
	
	/*<<����AEC��������>>
	*enable  ���Ƿ�����
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecAec_Cmd)
	BODY(mt::TBOOL32, enable)

	/*<<����AGC��������>>
	*enable  ���Ƿ�����
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecAgc_Cmd)
	BODY(mt::TBOOL32, enable)

	/*<<����AEC΢����������>>
	*auto  ���Ƿ�����Ӧ
	*value ��΢��ֵ
	*��Ϣ���� ��sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetAECParam_Cmd)
	BODY(mt::TBOOL32, auto)
	BODY(mt::TU32, value)

	/*<<����������������>>
	*level ���������ȵȼ�(0�ر��������ȣ���0������������)
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetAudPrecedence_Cmd)
	BODY(mt::TU8, level)

	/*<<��ȡ��Ƶ�����������>>
	*codec_type ����������
	*encoder_id ����������
	*start  : TRUE��ʾ������FALSE��ʾֹͣ
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecGetAudOutPower_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TBOOL32, start)

	/*<<��Ƶ�������֪ͨ>>
	*codec_type ����������
	*encoder_id ����������
	*��Ϣ���� ��mtmp==>dispatch==>service
	*/
	MESSAGE(Ev_MT_CodecAudOutPower_Ntf)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TU32, power)

	/*<<��ȡ��Ƶ���빦������>>
	*codec_type ����������
	*encoder_id ����������
	*start  : TRUE��ʾ������FALSE��ʾֹͣ
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecGetAudInPower_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TBOOL32, start)

	/*<<��Ƶ���빦��֪ͨ>>
	*codec_type ����������
	*encoder_id ����������
	*power  ����Ƶ���빦��
	*��Ϣ���� ��mtmp==>dispatch==>service
	*/
	MESSAGE(Ev_MT_CodecAudInPower_Ntf)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TU32, power)

	/*<<������Ƶ������������>>
	*vol : ����
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetAudInVol_Cmd)
	BODY(mt::TU32, vol)

	/*<<������Ƶ�����������>>
	*vol : ����
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetAudOutVol_Cmd)
	BODY(mt::TU32, vol)

	/*<<��ȡ��Ƶ�����������>>
	*codec_type ����������
	*encoder_id ����������
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecGetAudOutVol_Req)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<��ȡ��Ƶ���������Ӧ>>
	*codec_type ����������
	*encoder_id ����������
	*vol    : ����
	*��Ϣ���� ��mtmp==>dispatch==>service
	*/
	MESSAGE(Ev_MT_CodecGetAudOutVol_Rsp)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TU32, vol)

	/*<<���ý������鲥���յ�ַ����>>
	*codec_type ����������
	*encoder_id ����������
	*ip         ���鲥��ַIP
	*port       ���鲥��ַ�˿�
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetMultiCastAddr_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TU32, ip)
	BODY(mt::TU16, port)

	/*<<���Ƶ�һ������Ƶ���������;�̬ͼƬ����>>
	*static_pic_cfg : ���;�̬ͼƬ��Ϣ
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecSndStaticPic_Cmd)	
	BODY(mt::TStaticPicCfg, static_pic_cfg)

	/*<<���Ƶ�һ������Ƶ��������ʼ�ɼ�����>>
	*enable : TRUE��ʼ�ɼ���FALSEֹͣ�ɼ�
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecStartVidCap_Cmd)
	BODY(mt::TBOOL32, enable)

	/*<<̨���������>> (��win32)
	*enable : �Ƿ��������
	*logo_param : ̨�����
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecSetAddLogoIntoEncStream_Cmd)	
	BODY(mt::TBOOL32, enable)
	BODY(mt::TMtFullLogoParam, logo_param)


	/*<<���÷��Ͱ���ǣ�֧��ƽ̨�˿ڸ���>>
	*codec_type ����������
	*encoder_id ����������
	*e164_param        ��e164��
	*stream_id         ������Ψһ��ʶ
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetStreamID_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TString, e164_param)//e164��
	BODY(mt::TU32, stream_id)//����Ψһ��ʶ

	/*<<�Ƿ�nat��Խ����>>
	*codec_type ����������
	*encoder_id ����������
	*is_nattraversal   ���Ƿ�nat��Խ
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecIsNatTraversal_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TBOOL32, is_nattraversal)//�Ƿ�nat��Խ
	BODY(mt::TNetAddr, rtp_local_addr)
	BODY(mt::TNetAddr, rtcp_local_addr)
	BODY(mt::TNetAddr, rtp_remote_addr)
	BODY(mt::TNetAddr, rtcp_remote_addr)

	/*<<��ȡ��ǰ�������״ֵ̬>>
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
	MESSAGE( Ev_MT_CodecGetBweStatus_Cmd)
	
	/*<<��ȡ��ǰ�������״ֵ̬>>
	*bwe_status �������ֵ
	*��Ϣ���� ��mtmp==>dispatch==>mtservice
	*/
	MESSAGE( Ev_MT_CodecBweStatus_Ntf)
	BODY(mt::TCodecBweStatus,  bwe_status)

	/*<<����qos>>
	*tQos   Qosֵ
	*��Ϣ���� ��mtservice==>dispatch==>mtmp
	*/
	MESSAGE( Ev_MT_CodecSetQos_Cmd )      
	BODY(mt::TMTIPQoS,  tQos)

	/*<<���� �Ƿ����RTP��չͷ>>
	*   tEnable: �Ƿ����
	*��Ϣ���� ��mtservice==>dispatch==>mtmp
	*/
	MESSAGE( Ev_MT_CodecSetBEnableRtpExStrip_Cmd )      
	BODY(mt::TBOOL32,  tEnable)

	/*<<���� ����rtcp ����ʽ>>
	tStatusֵ���£�
	*                      RTCP_OFF          = 0, ������RTCP
	*					   RTCP_COMPOUND     = 1, ����RTCP���ϰ�
	*					   RTCP_NONCOMPOUND  = 2, ������RTCP���ϰ�
	*��Ϣ���� ��mtservice==>dispatch==>mtmp
	*/
	MESSAGE( Ev_MT_CodecSetRtcpStatus_Cmd )
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TU32,  tStatus)



	/*<<���ý���ص���������>>
	*codec_type ����������
	*encoder_id ����������
	*start  : TRUE��ʾ������FALSE��ʾֹͣ
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecSetDecFrameCallBack_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TBOOL32, start)



	/*<<������ƵԴ�仯֪ͨ>>
	*video_ignal  ��TRUE��ʾ���źţ�FALSE��ʾ���ź�
	*��Ϣ���� ��mtmp==>dispatch==>service
	*/
	MESSAGE(Ev_MT_CodecVideoSignal_Ntf)
	BODY(mt::TBOOL32, video_ignal)

	/*<<��ǰ����״̬>>
	* mt_assstream_status ����ǰ������״̬
	* ��Ϣ���� ��conf==>dispatch==>mtmp
	*/
	MESSAGE( Ev_MT_Codec_AssSndSream_Status_Ntf )             //
	BODY(mt::TS32, chan_state) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmMtChanState


	/*<<�����Ƿ�֧��720P> �����ֻ�TT��
	* mt_assstream_status ��
	* ��Ϣ���� ��conf==>dispatch==>mtmp

	*/
	MESSAGE( Ev_MT_Codec_ReducePriomVideoEncRes_Ntf )             
	BODY(mt::TBOOL32, cpu_ability) //

		/*<<Զ���Ի�״ָ̬ʾ>> 
	* emCodeType: codec ����
	* emCodeIdx:  codec ����
	* bResult �� ����/�ر�
	* ��Ϣ���� ��conf==>dispatch==>mtmp
	*/
	MESSAGE( Ev_MT_Codec_RemoteLoop_Ntf )
	BODY( mt::TU32,    emCodeType)
	BODY( mt::TU32,    emCodeIdx)
	BODY( mt::TBOOL32, bResult)

	/*<<�����Ƿ���fec>> 
	* bSnd:      �Ƿ��Ƿ���ͨ������Ӧ���еķ���/����ͨ��
	* benable �� ����/�ر�
	* ��Ϣ���� ��conf==>dispatch==>mtmp
	*/
	MESSAGE( Ev_MT_Codec_EnableFec )
	BODY( mt::TBOOL32,  bSnd )
	BODY( mt::TBOOL32,  benable )

		
	/*<<̨���������>> (��Mobil)
	*enable : �Ƿ��������
	*RpLogo_param : ̨�����
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecSetAddMobilLogoIntoEncStream_Cmd)	
	BODY(mt::TBOOL32, enable)
	BODY(mt::TRpMtFullLogoParam, RpLogo_param)

	/*<<�ն˶�������>> (��EMBED)
	*enable : TRUE:������FALSE:�ر�
	*��Ϣ���� ��service==>dispatch==>mtmp
    *������Ϣ����֪ͨx700��������������������֪ͨ�������򽻻�
	*/
	MESSAGE(Ev_MT_BLL_CodecStartMultiStream_Ntf)	
	BODY(mt::TBOOL32, enable)
	
	/*<<����srtp��Կ>>
	*codec_type ����������
	*encoder_id ����������
	*key        ����Կ
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetSrtpCrypto_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TSrtpCrypto, tMtSrtpParam)

	////��������tosֵ
	MESSAGE(Ev_MT_CodecTos_Cmd )
	BODY(mt::TU8,   byAud)
	BODY(mt::TU8,   byVid)
	
	/*<<Ͷ��״̬֪ͨ>>
	*/
	MESSAGE(Ev_MT_MtQkState_Ntf)
	BODY(mt::TMtQkState , state)  // ����Ͷ����״̬
	


#if !defined(_MESSAGE_HELP_)
    EV_END(MPCOMMON) = EVSEG_MPCOMMON_END
};
#endif

#define Is_MPCommon_Msg(m) ((m) >= Ev_MT_BGN(MPCOMMON) && (m) <= Ev_MT_END(MPCOMMON))

#endif // _MTMPCOMMONMSG_H_