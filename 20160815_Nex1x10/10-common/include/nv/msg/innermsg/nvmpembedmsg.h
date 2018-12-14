#ifndef _NVMPEMBEDMSG_H_
#define _NVMPEMBEDMSG_H_

#include "nvmsgid.h"
#include "nvstruct.pb.h"

#if !defined(_MESSAGE_HELP_)
enum EmMPEmbedMsg
{
    EV_BGN(MPEMBED) = EVSEG_MPEMBED_BGN,
#endif
	
	/*<<���ý�������ַ����>>
	*codec_type ����������
	*encoder_id ����������
	*rtp_local_addr   ������rtp���ı��ص�ַ
	*rtcp_local_addr  ������rtcp���ı��ص�ַ
	*rtp_remote_addr  �����ʹ򶯰���Զ�˵�ַ���˿�Ϊ0��ʾ�����ʹ򶯰��������ʹ򶯰�
	*rtcp_remote_addr ������rtcp����Զ��Ŀ�ĵ�ַ��Ҳ����������backrtcp��ַ
	*��Ϣ���� ��service==>dispatch==>nvmp
	*/
    MESSAGE(Ev_NV_CodecSetChanRcvAddr_Cmd)
	BODY(nv::TS32, codec_type)//ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvCodecComponent
	BODY(nv::TS32, decoder_id) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvCodecComponentIndex	
	BODY(nv::TNVNetAddr, rtp_local_addr)
	BODY(nv::TNVNetAddr, rtcp_local_addr)
	BODY(nv::TNVNetAddr, rtp_remote_addr)//
	BODY(nv::TNVNetAddr, rtcp_remote_addr)
	
	/*<<��ʼ��������>
	*codec_type ����������
	*encoder_id ����������
	*��Ϣ���� ��service==>dispatch==>nvmp
	*/
    MESSAGE(Ev_NV_CodecChanStart_Cmd)
	BODY(nv::TS32, codec_type)//ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvCodecComponent
	BODY(nv::TS32, codec_id) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvCodecComponentIndex

	/*<<ֹͣ��������>>
	*codec_type ����������
	*encoder_id ����������
	*��Ϣ���� ��service==>dispatch==>nvmp
	*/
    MESSAGE(Ev_NV_CodecChanStop_Cmd)
	BODY(nv::TS32, codec_type)//ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvCodecComponent
	BODY(nv::TS32, codec_id) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvCodecComponentIndex
	
	/*<<���͹ؼ�֡����>>
	*codec_type ����������
	*encoder_id ����������
	*��Ϣ���� ��service==>dispatch==>nvmp
	*/
	MESSAGE(Ev_NV_CodecFastUpdate_Cmd)
	BODY(nv::TS32, codec_type)//ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvCodecComponent
	BODY(nv::TS32, encoder_id) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvCodecComponentIndex
	
	/*<<��Ƶ��������Ҫ�ؼ�֪֡ͨ>>
	*codec_type ����������
	*encoder_id ����������
	*��Ϣ���� ��nvmp==>dispatch==>service
	*/
	MESSAGE(Ev_NV_CodecNeedKeyFrame_Ntf)
	BODY(nv::TS32, codec_type)//ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvCodecComponent
	BODY(nv::TS32, decoder_id) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvCodecComponentIndex
	
	/*<<���ö����ش�����>>
	*prs_param �������ش��Δ�
	*��Ϣ���� ��service==>dispatch==>nvmp
	*/
    MESSAGE(Ev_NV_CodecSetPrsParam_Cmd)
	BODY(nv::TNVPrsParam, prs_param)
	
	/*<<���ö�̬���^>
	*codec_type ����������
	*encoder_id ����������
	*payload       ����̬���^
	*media_type    ���ö�̬�غɶ�Ӧ��ý�����ͣ����Խ�������Ч
	*��Ϣ���� ��service==>dispatch==>nvmp
	*/
    MESSAGE(Ev_NV_CodecSetDynamicPayload_Cmd)
	BODY(nv::TS32, codec_type)//ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvCodecComponent
	BODY(nv::TS32, codec_id) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvCodecComponentIndex
	BODY(nv::TU32, payload) 
	BODY(nv::TS32, media_type)
	
	/*<<������Կ>>
	*codec_type ����������
	*encoder_id ����������
	*key        ������
	*��Ϣ���� ��service==>dispatch==>nvmp
	*/
    MESSAGE(Ev_NV_CodecSetEncryptKey_Cmd)
	BODY(nv::TS32, codec_type)//ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvCodecComponent
	BODY(nv::TS32, codec_id) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvCodecComponentIndex
	BODY(nv::TNVEncryptKey, key)
	
	/*<<��ƵԴ�ֱ����ϱ�>>
	*���䷽��nvmp==>dispatch==>nvservice
	* see 
	*/
	MESSAGE( Ev_NV_NvmpVidSrcStatus_Ntf )
	BODY(nv::TNVVidInPortResInfoList, src_info_list)
	
	/*<<��ѯ��ƵԴ�ֱ���>>
	*���䷽��nvservice==>dispatch==>nvmp
	*is_test ���Ƿ���ϲ���
	* see 
	*/
	MESSAGE( Ev_NV_NvmpVidSrcStatus_Req )
	BODY(nv::TBOOL32, is_test)
	
	/*<<��ƵԴ�ֱ����ϱ�>>
	*���䷽��nvmp==>dispatch==>nvservice
	* see 
	*/
	MESSAGE( Ev_NV_NvmpVidSrcStatus_Rsp )
	BODY(nv::TNVVidInPortResInfoList, src_info_list)
	
	/*<<��ƵԴ�Ƿ���Դ����>
	*src_info ����ƵԴ��Ϣ
	*���䷽��nvmp==>dispatch==>nvservice
	* see 
	*/
	MESSAGE( Ev_NV_ImixVidSrcSignal_Ntf )
	BODY(nv::TNVImixVidSrcSignal, src_info)
	BODY(nv::TBOOL32, is_first)

	
	/*<<���þ���>>
	*is_quiet ���Ƿ��
	*���䷽��nvservice==>dispatch==>nvmp
	* see 
	*/
	MESSAGE( Ev_NV_CodecQuiet_Cmd )
	BODY(nv::TBOOL32, is_quiet)
	
	/*<<������Ƶ�����������>>
	*vol : ����
	*aud_port : ��Ƶ�˿�
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_NV_CodecSetAudOutVol_Cmd)
	BODY(nv::TU32, vol)
	BODY(nv::TS32, aud_port) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvAudPortOut

	/*<<��ȡ��Ƶ�����������>>
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_NV_CodecGetAudOutVol_Req)


	/*<<��ȡ��Ƶ���������Ӧ>>
	*vol    : ����
	*��Ϣ���� ��mtmp==>dispatch==>service
	*/
	MESSAGE(Ev_NV_CodecGetAudOutVol_Rsp)
	BODY(nv::TU32, vol)
	
	/*<<�����������>>
	*���䷽��nvervice->nvmp
	* see Ev_NV_CodecSnapshot_Rsp
	*/
	MESSAGE( Ev_NV_CodecSnapshot_Req )
	BODY(nv::TString, snapshot_name)
	BODY(nv::TS32, codec_id) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvCodecComponentIndex

	/*<<���������Ӧ>>
	*���䷽��nvmp->nvservice
	* see Ev_NV_CodecSnapshot_Req
	*/
	MESSAGE( Ev_NV_CodecSnapshot_Rsp )
	BODY(nv::TU32, snapshot_state) //��������״̬ 0���ɹ� 1��ʧ��
	BODY(nv::TString, snapshot_name)
	BODY(nv::TS32, codec_id) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvCodecComponentIndex

	/*<<��ȡ��Ƶ����>>
	*��Ϣ���� ��service==>dispatch==>nvmp
	*/
	MESSAGE(Ev_NV_CodecGetAllAudInPower_Cmd)
	
	/*<<��Ƶ����ظ�>>
	*��Ϣ���� nvmp==>dispatch==>��service
	*aud_list : ��Ƶ�ź��б�
	*/
	MESSAGE(Ev_NV_CodecGetAllAudInPower_Ntf)
	BODY(nv::TNVAudInPowerList, aud_list)
	
	/*<<��������>>
	*��Ϣ���� ��service==>dispatch==>nvmp
	*bplay 1:������0���ر�
	*/
	MESSAGE(Ev_NV_CodecRingPlay_Cmd)
	BODY(nv::TBOOL32, bplay)
	
	/*<<����HDMI���أ���������>>
	*��Ϣ���� ��service==>dispatch==>nvmp
	*bUp 1:3798���ݲ�����FPGA��0��3798���ݿ��Ծ���FPGA
	*/
	MESSAGE(Ev_NV_SetHdmiSwitch_Cmd)
	BODY(nv::TBOOL32, bUp)
	
	MESSAGE(Ev_NV_DualVidSrcSignal_Ntf)
	BODY(nv::TBOOL32, bHdmi)
	
	/*<<���ý��벥��ͼ�����ʾͼ��>>
	*��Ϣ���� ��service==>dispatch==>nvmp
	*BOOL32 bMinimize TRUE:��С��  FALSE����� 
	*/
	MESSAGE(Ev_NV_SetShowRect_Cmd)
	BODY(nv::TBOOL32, bMinimize)

	/*<<������Ƶ�˿�>>
	*��Ϣ���� ��service==>dispatch==>nvmp
	* port ��Ƶ���������
	*/
	MESSAGE(Ev_NV_CodecSetAudPort_Cmd)
	BODY(nv::TNVAudPort, port)
	
	/*<<������Ƶ�����������>>
	*��Ϣ���� ��service==>dispatch==>nvmp
	* matrix  ��Ƶ����
	* is_osd  �Ƿ���ӻ���
	*/
	MESSAGE(Ev_NV_CodecSetVidMatrix_Cmd)
	BODY(nv::TNVVideoMatrixScheme, matrix) 
	BODY(nv::TBOOL32, is_osd) 

	/*<<����ɫ��ͼ>>
	*��Ϣ���� ��service==>dispatch==>nvmp
	* matrix  ��Ƶ����
	* is_osd  �Ƿ���ӻ���
	*/
	MESSAGE(Ev_NV_BluePic_Cmd)
	BODY(nv::TBOOL32, isblue)
	/*<<��������>>
	*��Ϣ���� ��service==>dispatch==>nvmp
	* matrix  ��Ƶ����
	* is_osd  �Ƿ���ӻ���
	*/
	MESSAGE(Ev_NV_OSD_Cmd)
	BODY(nv::TBOOL32, isosd)
	
	/*<<����Ops����>>
	*��Ϣ���� ��device==>dispatch==>nvmp
	* is_osd  TRUE:�� FALSE����  
	*/
	MESSAGE(Ev_NV_SetOpsStatus_Cmd)
	BODY(nv::TBOOL32, bOpen)
	
	/*<<�������Կ��ض�д����>>
	*��Ϣ���� ��device==>dispatch==>nvmp
	* is_osd  TRUE:�� FALSE����  
	*/
	MESSAGE(Ev_NV_DeviceSerialTest_Nty)
	BODY(nv::TBOOL32, bOpen)
	
	/*<<���ò����豸����ʾ����	>>
	*���䷽��nvervice->nvmp
	* see Ev_NV_CodecSnapshot_Rsp
	*/
	MESSAGE( Ev_NV_CodecSetPlayZoomMode_Cmd )
	BODY(nv::TS32, zoon) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvZoomMode
	
	/*<<imix��socket accept����֪ͨ>>
	*��Ϣ���� ��nvmp==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_ImixSocketAccept_Nty)
	
	/*<<������Ƶ����	>>
	*���䷽��nvservice==>dispatch==>nvmp
	*/
	MESSAGE( Ev_NV_CodecSetVidFreezePrm_Cmd )
	BODY(nv::TNVVidFreezePrm, Freeze) 
	
	/*<<imix��socket listen����֪ͨ>>
	*��Ϣ���� ��nvmp==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_ImixSocketListen_Nty)
	
	/*<<��ƵԴ����1080	>>
	*���䷽��nvmp==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_CodecVidResIsNot1080_Nty )
	BODY(nv::TS32, port)//ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvImixVidSrcType	
	
	/*<<Сͼ�����	>>
	*���䷽��nvservice==>dispatch==>nvmp
	*/
	MESSAGE( Ev_NV_CodecSetMiniVid_Cmd )
	BODY(nv::TNVMiniVidInfo, info)
	
	/*<<Сͼ�����֪ͨ	>>
	*���䷽��nvmp==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_CodecSetMiniVid_Ntf )
	BODY(nv::TNVMiniVidInfo, info)
	
	/*<<��Ƶ����״̬��ѯ	>>
	*���䷽��nvservice==>dispatch==>nvmp
	*/
	MESSAGE( Ev_NV_CodecGetVidFreezePrm_Req )

	/*<<��Ƶ����״̬��ѯ�ظ�	>>
	*���䷽��nvmp==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_CodecGetVidFreezePrm_Rsp )
	BODY(nv::TU32, Freeze)
	
	/*<<Сͼ��״̬��ѯ	>>
	*���䷽��nvservice==>dispatch==>nvmp
	*/
	MESSAGE( Ev_NV_GetMiniVidInfoRt_Req )

	/*<<Сͼ��״̬��ѯ�ظ�	>>
	*���䷽��nvmp==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_GetMiniVidInfoRt_Rsp )
	BODY(nv::TNVMiniVidInfo, info)
	
	/*<<����ѡ��״̬֪ͨ>>
	*���䷽��nvmp==>dispatch==>nvservice
	* bstart  TRUE����ʼ�л����� FALSE�����������л�
	*/
	MESSAGE( Ev_NV_ViewPicState_Nty )
	BODY(nv::TBOOL32, bstart)

	/*<<��������	>>
	*���䷽��nvservice==>dispatch==>nvmp
	*/
	MESSAGE( Ev_NV_DrawLine_Cmd )
	BODY(nv::TNVVidLineOverlap, info)
	
	/*<<�������쳣֪ͨ>>
	*���䷽��nvmp==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_CodecError_Nty )
	
	/*<<���ù��Ű徲��	>>
	*���䷽��nvservice==>dispatch==>nvmp
	*/
	MESSAGE( Ev_NV_SetAmplifierStatus_Cmd )
	BODY(nv::TBOOL32, bmute)

	/*<<����HDMI�Ƿ������Ƶ	>>
	*���䷽��nvservice==>dispatch==>nvmp
	*/
	MESSAGE( Ev_NV_SetHDMIAudioMute_Cmd )
	BODY(nv::TBOOL32, bmute)
	
	/*<<֪ͨimixҵ��ǰ�Ƿ���ʾ��ɫ����>>
	*���䷽��nvservice==>dispatch==>nvmp
	*tShow: �Ƿ����ɫ����
	*/
	MESSAGE( Ev_NV_NotifyIsShowGreenWin_Cmd )
	BODY(nv::TBOOL32, tShow)

	/*<<����HDMI1�Ƿ������Ƶ>>
	*���䷽��nvservice==>dispatch==>nvmp
	*tView: �Ƿ����HDMI1��Ƶ
	*/
	MESSAGE( Ev_NV_SetHDMI1VidPlyPortStd_Cmd )
	BODY(nv::TBOOL32, tShow)

	/*<<����ʱ�յ��ն˼�⵽����Դ״̬��֪ͨ>>
	*���䷽��nvterinterface==>dispatch==>nvmp
	*tHasSrc: �Ƿ����HDMI1��Ƶ
	*/
	MESSAGE( Ev_NV_TerVidSrcStatus_Nty )
	BODY(nv::TBOOL32, tHasSrc)
	
#if !defined(_MESSAGE_HELP_)
    EV_END(MPEMBED) = EVSEG_MPCOMMON_END
};
#endif

#define Is_MPEmbed_Msg(m) ((m) >= Ev_NV_BGN(MPEMBED) && (m) <= Ev_NV_END(MPEMBED))

#endif // _NVMPEMBEDMSG_H_