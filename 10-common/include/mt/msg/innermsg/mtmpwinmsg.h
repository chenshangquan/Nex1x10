#ifndef _MTMPWINMSG_H_
#define _MTMPWINMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMPWinMsg
{
    EV_BGN(MPWIN) = EVSEG_MPWIN_BGN,
#endif

	/*<<���ý��������Ŵ�������>>
	*codec_type ����������
	*encoder_id ����������
	*hwnd       �����ھ��
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetPlayHWND_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TS32, hwnd)

	/*<<��ղɼ����Ŵ�������>>
	*codec_type ����������
	*encoder_id ����������
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecClearWindow_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex

	/*<<���ñ�����Ԥ����������>>
	*codec_type ����������
	*encoder_id ����������
	*hwnd       �����ھ��
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetPreviewHWND_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TS32, hwnd)

	/*<<����ֻ��ؼ�֡����>>
	*codec_type ����������
	*encoder_id ����������
	*on         ���Ƿ�ֻ��ؼ�֡
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecDecOnlyKeyFrame_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TBOOL32, on)

	/*<<TL��ȡ��Ƶ�����豸�б�����>>
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecGetWaveInDevList_Cmd)

	/*<<TL��Ƶ�����豸�б�֪ͨ>>
	*device_list ����Ƶ�����豸�б�
	*��Ϣ���� ��mtmp==>dispatch==>service
	*/
    MESSAGE(Ev_MT_CodecWaveInDevList_Ntf)
	BODY(mt::TDevInfoList, device_list)	

	/*<<TL������Ƶ�����豸����>>
	*which_device ���豸��ʶ
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetWaveInDev_Cmd)
	BODY(mt::TDevInfo, which_device)	

	/*<<TL��ȡ��ǰ��Ƶ�����豸����>>
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecGetCurWaveInDev_Cmd)

	/*<<TL��ǰ��Ƶ�����豸֪ͨ>>
	*wave_in_dev ����ǰ��Ƶ�����豸
	*��Ϣ���� ��mtmp==>dispatch==>service
	*/
    MESSAGE(Ev_MT_CodecCurWaveInDev_Ntf)
	BODY(mt::TDevInfo, wave_in_dev)

	/*<<TL������Ƶ����豸����>>
	*which_device ���豸��ʶ
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetWaveOutDev_Cmd)
	BODY(mt::TDevInfo, which_device)

	/*<<TL��ȡ��Ƶ����豸�б�����>>
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecGetWaveOutDevList_Cmd)

	/*<<TL��Ƶ����豸�б�֪ͨ>>
	*device_list ����Ƶ����豸�б�
	*��Ϣ���� ��mtmp==>dispatch==>service
	*/
    MESSAGE(Ev_MT_CodecWaveOutDevList_Ntf)
	BODY(mt::TDevInfoList, device_list)

	/*<<TL��ȡ��ǰ��Ƶ����豸����>>
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecGetCurWaveOutDev_Cmd)

	/*<<TL��ǰ��Ƶ����豸֪ͨ>>
	*wave_out_dev ����ǰ��Ƶ����豸
	*��Ϣ���� ��mtmp==>dispatch==>service
	*/
    MESSAGE(Ev_MT_CodecCurWaveOutDev_Ntf)
	BODY(mt::TDevInfo, wave_out_dev)

	/*<<TL��ȡ��Ƶ�����豸�б�����>>
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecGetVidCapDevList_Cmd)

	/*<<TL��Ƶ�����豸�б�֪ͨ>>
	*device_list ����Ƶ�����豸�б�
	*��Ϣ���� ��mtmp==>dispatch==>service
	*/
    MESSAGE(Ev_MT_CodecVidCapDevList_Ntf)
	BODY(mt::TDevInfoList, device_list)

	/*<<TL������Ƶ�����豸����>>
	*which_device ���豸��ʶ
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetVidCapDev_Cmd)
	BODY(mt::TDevInfo, which_device)

	/*<<TL��ȡ��ǰ��Ƶ�ɼ��豸����>>
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecGetCurVidCapDev_Cmd)

	/*<<TL��ǰ��Ƶ�ɼ��豸֪ͨ>>
	*vid_cap_dev ����ǰ��Ƶ�ɼ��豸
	*��Ϣ���� ��mtmp==>dispatch==>service
	*/
    MESSAGE(Ev_MT_CodecCurVidCapDev_Ntf)
	BODY(mt::TDevInfo, vid_cap_dev)

	/*<<TL��/�ر���Ƶ�ɼ���������>>
	*codec_type ����������
	*encoder_id ����������
	*on       ��TRUE �������ԣ�FALSE ֹͣ����
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecAudCapTest_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TBOOL32, on)

	/*<<TL��/�ر���Ƶ���Ų�������>>
	*codec_type ����������
	*encoder_id ����������
	*on       ��TRUE �������ԣ�FALSE ֹͣ����
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecAudPlayTest_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TBOOL32, on)

	/*<<TLý���¼�֪ͨ>>
	*event_id ���¼���ʶ
	*��Ϣ���� ��mtmp==>dispatch==>service
	*/
    MESSAGE(Ev_MT_CodecEvent_Ntf)
	BODY(mt::TS32, event_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecEvent

	/*<<TL��Ƶ�������¼�֪ͨ>>
	*insert_list   ���²������Ƶ�ɼ��豸�б�
	*remove_list   ���°γ�����Ƶ�ɼ��豸�б�
	*��Ϣ���� ��mtmp==>dispatch==>service
	*/
    MESSAGE(Ev_MT_CodecAudCapDevChange_Ntf)
	BODY(mt::TDevInfoList, insert_list)
	BODY(mt::TDevInfoList, remove_list)

	/*<<TL��Ƶ�������¼�֪ͨ>>
	*insert_list   ���²������Ƶ�ɼ��豸�б�
	*remove_list   ���°γ�����Ƶ�ɼ��豸�б�
	*��Ϣ���� ��mtmp==>dispatch==>service
	*/
    MESSAGE(Ev_MT_CodecVidCapDevChange_Ntf)
	BODY(mt::TDevInfoList, insert_list)
	BODY(mt::TDevInfoList, remove_list)

	/*<<TL��ʼ��Ƶ�ɼ�ʧ��֪ͨ>>
	*��Ϣ���� ��mtmp==>dispatch==>service
	*/
    MESSAGE(Ev_MT_CodecStartVidCapFailed_Ntf)

	/*<<��Ƶ�ɼ���������>>
	*codec_type ����������
	*encoder_id ����������
	*is_start   ��true�����ɼ���falseֹͣ�ɼ�
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecVidCapCtrl_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TBOOL32, is_start)

	/*<<ץͼ����>>
	*codec_type ����������
	*encoder_id ����������
	*hwnd       �����ھ����������ʾץ����ͼƬ
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecGrabPic_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TS32, hwnd)

	/*<<ץͼ����������>>
	*codec_type ����������
	*encoder_id ����������
	*pic_format ��ͼƬ�ļ���ʽ��emJPEG jpeg��emBMP bmp
	*file_name  ��ͼƬ�ļ������·��������
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSavePic_Cmd)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TS32, pic_format) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmPicFormat
	BODY(mt::TString, file_name)

	/*<<ץͼ�������������֪ͨ>>
	*codec_type ����������
	*encoder_id ����������
	*pic_format ��ͼƬ�ļ���ʽ��emJPEG jpeg��emBMP bmp
	*file_name  ��ͼƬ�ļ������·��������
	*��Ϣ���� ��mtmp==>dispatch==>service
	*/
    MESSAGE(Ev_MT_CodecSavePic_Ntf)
	BODY(mt::TS32, codec_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent
	BODY(mt::TS32, codec_id) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex
	BODY(mt::TS32, pic_format) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmPicFormat
	BODY(mt::TString, file_name)

	/*<<��ʼ¼������>>
	*rec_param ��¼�����
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecStartRec_Cmd)
	BODY(mt::TRecordParam, rec_param)

	/*<<ֹͣ¼������>>
	*is_local ��trueֹͣ����¼��falseֹͣԶ��¼��
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecStopRec_Cmd)
	BODY(mt::TBOOL32, is_local)

	/*<<��ͣ¼������>>
	*is_local ��true��ͣ����¼��false��ͣԶ��¼��
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecPauseRec_Cmd)
	BODY(mt::TBOOL32, is_local)

	/*<<����¼������>>
	*is_local ��true��������¼��false����Զ��¼��
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecResumeRec_Cmd)
	BODY(mt::TBOOL32, is_local)

	/*<<����¼����̿ռ�澯��ֵ����>>
	*rec_alarm ���澯��ֵ����
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetRecAlarmLevel_Cmd)
	BODY(mt::TRecordDiskAlarmLevel, rec_alarm)

	/*<<¼����̿ռ�澯֪ͨ>>
	*alarm_level ��ʣ����̿ռ�
	*��Ϣ���� ��mtmp==>dispatch==>service
	*/
    MESSAGE(Ev_MT_CodecRecDiskAlarm_Ntf)
	BODY(mt::TS32, alarm_level)

	/*<<��������ͷͼ���������>>
	*image_param ������ͷͼ�����
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetCameraParam_Cmd)
	BODY(mt::TImageParam, image_param)

	/*<<��ȡ����ͷͼ���������>>
	*image_param_type ������ͷͼ���������
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecGetCameraParam_Req)
	BODY(mt::TS32, image_param_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmImgParam

	/*<<��ȡ����ͷͼ�������Ӧ>>
	*image_param ������ͷͼ�����
	*��Ϣ���� ��mtmp==>dispatch==>service
	*/
    MESSAGE(Ev_MT_CodecGetCameraParam_Rsp)
	BODY(mt::TImageParam, image_param)

	/*<<��ȡ����ͷĬ��ͼ���������>>
	*image_param_type ������ͷͼ���������
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecGetDefaultCameraParam_Req)
	BODY(mt::TS32, image_param_type)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmImgParam

	/*<<��ȡ����ͷĬ��ͼ�������Ӧ>>
	*def_img_param ������ͷĬ��ͼ�����
	*��Ϣ���� ��mtmp==>dispatch==>service
	*/
    MESSAGE(Ev_MT_CodecGetDefaultCameraParam_Rsp)
	BODY(mt::TDefaultImageParam, def_img_param)

#if !defined(_MESSAGE_HELP_)
    EV_END(MPWIN) = EVSEG_MPWIN_END
};
#endif

#define Is_MPWin_Msg(m) ((m) >= Ev_MT_BGN(MPWIN) && (m) <= Ev_MT_END(MPWIN))

#endif // _MTMPWINMSG_H_