#ifndef _MTBLLMPCOMMONMSG_H_
#define _MTBLLMPCOMMONMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMPCommonMsg
{
    EV_BLL_BGN(MPCOMMON) = EVSEG_BLL_MPCOMMON_BGN,
#endif

	/*<<��ʼ�������ĳһ·VOD������>>
	*codec_type ����������
	*encoder_id ����������
	*��Ϣ���� ��vod==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecVodStreamStart_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<ֹͣ�������ĳһ·VOD������>>
	*codec_type ����������
	*encoder_id ����������
	*��Ϣ���� ��vod==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecVodStreamStop_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<��ʼ��ý���鲥����>>
	*codec_type ����������
	*encoder_id ����������
	*rtp_snd_addr  ��rtp���͵�ַ
	*rtcp_snd_addr ��rtcp���͵�ַ
	*��Ϣ���� ��sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecStreamMediaStart_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TNetAddr, rtp_snd_addr)
	BODY(mt::TNetAddr, rtcp_snd_addr)

	/*<<ֹͣ��ý���鲥����>>
	*codec_type ����������
	*encoder_id ����������
	*��Ϣ���� ��sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecStreamMediaStop_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<��ʼĳһ·�������>>
	*codec_type ����������
	*encoder_id ����������
	*monitor_addr  ����ؽ��յ�ַ
	*��Ϣ���� ��sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecMonitorStart_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TRtpRtcpPair, monitor_addr)

	/*<<ֹͣĳһ·�������>>
	*codec_type ����������
	*encoder_id ����������
	*monitor_addr  ����ؽ��յ�ַ,Ψһȷ��ĳһ·���
	*��Ϣ���� ��sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecMonitorStop_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TRtpRtcpPair, monitor_addr)

	/*<<��ʼĳһ·¼������>>
	*codec_type ����������
	*encoder_id ����������
	*record_addr   ��¼����յ�ַ
	*��Ϣ���� ��sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecRecordStart_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TRtpRtcpPair, record_addr)

	/*<<ֹͣĳһ·¼������>>
	*codec_type ����������
	*encoder_id ����������
	*record_addr : ¼����յ�ַ,Ψһȷ��ĳһ·¼��
	*��Ϣ���� ��sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecRecordStop_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TRtpRtcpPair, record_addr)

	/*<<��ȡ��ز�������>>
	*codec_type ����������
	*encoder_id ����������
	*��Ϣ���� ��sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecGetMonitorParam_Cmd)
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
	*tMonitorLocalRtpPort:	����rtp�˿ں�
	*tMonitorLocalRtcpPort:	����rtcp�˿ں�
	*��Ϣ���� ��mtmp==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecMonitorParam_Ntf)	
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
	*��Ϣ���� ��sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecMonitorFastUpdate_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<5���ڶ���֪ͨ>>
	*lost ��TRUE-���� FALSE-������
	*��Ϣ���� ��mtmp==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecLostPack_Ntf)
	BODY(mt::TBOOL32, lost)	

	/*<<��������>>	
	*on ����ʼorȡ������
	*��Ϣ���� ��sdk/conf==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecQuiet_Cmd)
	BODY(mt::TBOOL32, on)

	/*<<����״̬֪ͨ>>
	*on ������״̬
	*��Ϣ���� ��mtmp==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecQuiet_Ntf)
	BODY(mt::TBOOL32, on)

	/*<<��������>>
	*on ����ʼorȡ������
	*��Ϣ���� ��sdk/conf==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecMute_Cmd)
	BODY(mt::TBOOL32, on)

	/*<<����״̬֪ͨ>>
	*on ������״̬
	*��Ϣ���� ��mtmp==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecMute_Ntf)
	BODY(mt::TBOOL32, on)

	/*<<����״̬֪ͨ>>
	*on ������״̬
	*��Ϣ���� ��mtservice==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecQuiet_Rsp)
	BODY(mt::TBOOL32, on)

	/*<<����״̬֪ͨ>>
	*on ������״̬
	*��Ϣ���� ��mtservice==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecMute_Rsp)
	BODY(mt::TBOOL32, on)

	/*<<����AEC΢����������>>
	*auto  ���Ƿ�����Ӧ
	*value ��΢��ֵ
	*��Ϣ���� ��sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecSetAECParam_Cmd)
	BODY(mt::TBOOL32, auto)
	BODY(mt::TU32, value)

	/*<<AEC΢������֪ͨ>>
	*auto  ���Ƿ�����Ӧ
	*value ��΢��ֵ
	*��Ϣ���� ��mtmp==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecAECParam_Ntf)
	BODY(mt::TBOOL32, auto)
	BODY(mt::TU32, value)	

	/*<<��ȡ��Ƶ�����������>>
	*codec_type ����������
	*encoder_id ����������
	*start  : TRUE��ʾ������FALSE��ʾֹͣ
	*��Ϣ���� ��sdk==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_BLL_CodecGetAudOutPower_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TBOOL32, start)

	/*<<��Ƶ�������֪ͨ>>
	*codec_type ����������
	*encoder_id ����������
	*power  ����Ƶ�������
	*��Ϣ���� ��mtmp==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_CodecAudOutPower_Ntf)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TU32, power)

	/*<<��ȡ��Ƶ���빦������>>
	*codec_type ����������
	*encoder_id ����������
	*��Ϣ���� ��sdk==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_BLL_CodecGetAudInPower_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TBOOL32, start)
	
	/*<<��ȡ��Ƶ�����������,windows��Ƕ��ʽƽ̨>>
	˵��:Ƕ��ʽ�ն�ʹ�õ�ʱ��ID��0
	*codec_type ����������
	*encoder_id ����������
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_BLL_CodecGetAudOutVol_Req)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<��ȡ��Ƶ���������Ӧ,��windowsƽ̨>>
	*codec_type ����������
	*encoder_id ����������
	*vol    : ����
	*��Ϣ���� ��mtmp==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_CodecGetAudOutVol_Rsp)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TU32, vol)

	/*<<��Ƶ���빦��֪ͨ>>
	*codec_type ����������
	*encoder_id ����������
	*power  ����Ƶ���빦��
	*��Ϣ���� ��mtmp==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_CodecAudInPower_Ntf)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TU32, power)	

	/*<<���Ƶ�һ������Ƶ���������;�̬ͼƬ����>>
	*enable : TRUE���ͣ�FALSEֹͣ����
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_BLL_CodecSndStaticPic_Cmd)
	BODY(mt::TBOOL32, enable)

	/*<<���Ƶ�һ������Ƶ��������ʼ�ɼ�����>>
	*enable : TRUE��ʼ�ɼ���FALSEֹͣ�ɼ�
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_BLL_CodecStartVidCap_Cmd)
	BODY(mt::TBOOL32, enable)

	/*<<̨���������>> (��win32)
	*enable : �Ƿ��������
	*logo_param : ̨�����
	*��Ϣ���� ��sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_CodecSetAddLogoIntoEncStream_Cmd)	
	BODY(mt::TBOOL32, enable)
	BODY(mt::TMtFullLogoParam, logo_param)


	/*<<���ý���ص���������>>
	*codec_type ����������
	*encoder_id ����������
	*start  : TRUE��ʾ������FALSE��ʾֹͣ
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_BLL_CodecSetDecFrameCallBack_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TBOOL32, start)

	/*<<̨���������>> (mobil)
	*enable : �Ƿ��������
	*RpLogo_param : ̨�����(����)
	*��Ϣ���� ��sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_CodecSetMobilAddLogoIntoEncStream_Cmd)	
	BODY(mt::TBOOL32, enable)
	BODY(mt::TRpMtFullLogoParam, RpLogo_param)

	/*<<����ؼ�֡>>
	*codec_type ����������
	*encoder_id ����������
	*��Ϣ���� ��sdp==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_CodecIFramRequest_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	
		/*<<Ͷ��״̬֪ͨ>>
	*/
	MESSAGE(Ev_MT_BLL_MtQkState_Ntf)
	BODY(mt::TMtQkState , state)  // ����Ͷ����״̬

#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(MPCOMMON) = EVSEG_BLL_MPCOMMON_END
};
#endif

#define Is_BLL_MPCommon_Msg(m) ((m) >= EV_BLL_BGN(MPCOMMON) && (m) <= EV_BLL_END(MPCOMMON))

#endif // _MTMPCOMMONMSG_H_