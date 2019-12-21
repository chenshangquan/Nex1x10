#ifndef _MTBLLMPWINMSG_H_
#define _MTBLLMPWINMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMPWinMsg
{
    EV_BLL_BGN(MPWIN) = EVSEG_BLL_MPWIN_BGN,
#endif

	/*<<设置采集播放窗口命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*hwnd       ：窗口句柄
	*消息流向 ：sdk==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_CodecSetHWND_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TS32, hwnd)

	/*<<清空采集播放窗口命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*消息流向 ：sdk==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_CodecClearWindow_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<设置只解关键帧命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*on         ：是否只解关键帧
	*消息流向 ：sdk==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_CodecDecOnlyKeyFrame_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TBOOL32, on)

	/*<<TL获取音频输入设备列表命令>>
	*消息流向 ：sdk==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_CodecGetWaveInDevList_Cmd)

	/*<<TL音频输入设备列表通知>>
	*device_list ：音频输入设备列表
	*消息流向 ：service==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecWaveInDevList_Ntf)
	BODY(mt::TDevInfoList, device_list)	

	/*<<TL设置音频输入设备命令>>
	*which_device ：设备标识
	*消息流向 ：sdk==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_CodecSetWaveInDev_Cmd)
	BODY(mt::TDevInfo, which_device)	

	/*<<TL获取当前音频输入设备命令>>
	*消息流向 ：sdk==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_CodecGetCurWaveInDev_Cmd)

	/*<<TL当前音频输入设备通知>>
	*wave_in_dev ：当前音频输入设备
	*消息流向 ：service==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecCurWaveInDev_Ntf)
	BODY(mt::TDevInfo, wave_in_dev)

	/*<<TL设置音频输出设备命令>>
	*which_device ：设备标识
	*消息流向 ：sdk==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_CodecSetWaveOutDev_Cmd)
	BODY(mt::TDevInfo, which_device)

	/*<<TL获取音频输出设备列表命令>>
	*消息流向 ：sdk==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_CodecGetWaveOutDevList_Cmd)

	/*<<TL音频输出设备列表通知>>
	*device_list ：音频输出设备列表
	*消息流向 ：service==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecWaveOutDevList_Ntf)
	BODY(mt::TDevInfoList, device_list)

	/*<<TL获取当前音频输出设备命令>>
	*消息流向 ：sdk==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_CodecGetCurWaveOutDev_Cmd)

	/*<<TL当前音频输出设备通知>>
	*wave_out_dev ：当前音频输出设备
	*消息流向 ：service==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecCurWaveOutDev_Ntf)
	BODY(mt::TDevInfo, wave_out_dev)

	/*<<TL获取视频输入设备列表命令>>
	*消息流向 ：sdk==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_CodecGetVidCapDevList_Cmd)

	/*<<TL视频输入设备列表通知>>
	*device_list ：视频输入设备列表
	*消息流向 ：service==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecVidCapDevList_Ntf)
	BODY(mt::TDevInfoList, device_list)

	/*<<TL设置视频输入设备命令>>
	*which_device ：设备标识
	*消息流向 ：sdk==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_CodecSetVidCapDev_Cmd)
	BODY(mt::TDevInfo, which_device)

	/*<<TL获取当前视频采集设备命令>>
	*消息流向 ：sdk==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_CodecGetCurVidCapDev_Cmd)

	/*<<TL当前视频采集设备通知>>
	*vid_cap_dev ：当前视频采集设备
	*消息流向 ：service==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecCurVidCapDev_Ntf)
	BODY(mt::TDevInfo, vid_cap_dev)

	/*<<TL打开/关闭音频采集测试命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*on       ：TRUE 开启测试，FALSE 停止测试
	*消息流向 ：sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_CodecAudCapTest_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TBOOL32, on)

	/*<<TL打开/关闭音频播放测试命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*on       ：TRUE 开启测试，FALSE 停止测试
	*消息流向 ：sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_CodecAudPlayTest_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TBOOL32, on)

	/*<<TL媒体事件通知>>
	*event_id ：事件标识
	*消息流向 ：service==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecEvent_Ntf)
	BODY(mt::TS32, event_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecEvent

	/*<<TL音频输入插拔事件通知>>
	*insert_list   ：新插入的音频采集设备列表
	*remove_list   ：新拔出的音频采集设备列表
	*消息流向 ：service==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecAudCapDevChange_Ntf)
	BODY(mt::TDevInfoList, insert_list)
	BODY(mt::TDevInfoList, remove_list)

	/*<<TL视频输入插拔事件通知>>
	*insert_list   ：新插入的视频采集设备列表
	*remove_list   ：新拔出的视频采集设备列表
	*消息流向 ：service==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecVidCapDevChange_Ntf)
	BODY(mt::TDevInfoList, insert_list)
	BODY(mt::TDevInfoList, remove_list)

	/*<<TL开始视频采集失败通知>>
	*消息流向 ：service==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecStartVidCapFailed_Ntf)
	
	/*<<视频采集控制命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*is_start   ：true开启采集，false停止采集
	*消息流向 ：sdk==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_CodecVidCapCtrl_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TBOOL32, is_start)
	
	/*<<抓图命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*hwnd       ：窗口句柄，用于显示抓到的图片
	*消息流向 ：sdk==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_CodecGrabPic_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TS32, hwnd)
	
	/*<<抓图并保存命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*pic_format ：图片文件格式，emJPEG jpeg，emBMP bmp
	*file_name  ：图片文件保存的路径和名称
	*消息流向 ：sdk==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_CodecSavePic_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TS32, pic_format) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmPicFormat
	BODY(mt::TString, file_name)

	/*<<抓图并保存命令完成通知>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*pic_format ：图片文件格式，emJPEG jpeg，emBMP bmp
	*file_name  ：图片文件保存的路径和名称
	*消息流向 ：service==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecSavePic_Ntf)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TS32, pic_format) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmPicFormat
	BODY(mt::TString, file_name)
	
	/*<<开始录像命令>>
	*rec_param ：录像参数
	*消息流向 ：sdk==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_CodecStartRec_Cmd)
	BODY(mt::TRecordParam, rec_param)

	/*<<停止录像命令>>
	*is_local ：true停止本地录像，false停止远端录像
	*消息流向 ：sdk==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_CodecStopRec_Cmd)
	BODY(mt::TBOOL32, is_local)

	/*<<暂停录像命令>>
	*is_local ：true暂停本地录像，false暂停远端录像
	*消息流向 ：sdk==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_CodecPauseRec_Cmd)
	BODY(mt::TBOOL32, is_local)

	/*<<继续录像命令>>
	*is_local ：true继续本地录像，false继续远端录像
	*消息流向 ：sdk==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_CodecResumeRec_Cmd)
	BODY(mt::TBOOL32, is_local)
	
	/*<<设置录像磁盘空间告警阈值命令>>
	*rec_alarm ：告警阈值配置
	*消息流向 ：：sdk==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_CodecSetRecAlarmLevel_Cmd)
	BODY(mt::TRecordDiskAlarmLevel, rec_alarm)
	
	/*<<录像磁盘空间告警通知>>
	*alarm_level ：剩余磁盘空间
	*消息流向 service==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecRecDiskAlarm_Ntf)
	BODY(mt::TS32, alarm_level)

	/*<<设置摄像头图像参数命令>>
	*image_param ：摄像头图像参数
	*消息流向 ：sdk==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_CodecSetCameraParam_Cmd)
	BODY(mt::TImageParam, image_param)

	/*<<获取摄像头图像参数请求>>
	*image_param_type ：摄像头图像参数类型
	*消息流向 ：sdk==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_CodecGetCameraParam_Req)
	BODY(mt::TS32, image_param_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmImgParam

	/*<<获取摄像头图像参数响应>>
	*image_param ：摄像头图像参数
	*消息流向 ：service==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecGetCameraParam_Rsp)
	BODY(mt::TImageParam, image_param)

	/*<<获取摄像头默认图像参数请求>>
	*image_param_type ：摄像头图像参数类型
	*消息流向 ：sdk==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_CodecGetDefaultCameraParam_Req)
	BODY(mt::TS32, image_param_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmImgParam

	/*<<获取摄像头默认图像参数响应>>
	*def_img_param ：摄像头默认图像参数
	*消息流向 ：service==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecGetDefaultCameraParam_Rsp)
	BODY(mt::TDefaultImageParam, def_img_param)

#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(MPWIN) = EVSEG_BLL_MPWIN_END
};
#endif

#define Is_BLL_MPWin_Msg(m) ((m) >= EV_BLL_BGN(MPWIN) && (m) <= EV_BLL_END(MPWIN))

#endif // _MTMPWINMSG_H_