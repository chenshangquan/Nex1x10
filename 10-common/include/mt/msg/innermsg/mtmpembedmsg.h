#ifndef _MTMPEMBEDMSG_H_
#define _MTMPEMBEDMSG_H_

#include "mtmsgid.h"
#include "struct.pb.h"

#if !defined(_MESSAGE_HELP_)
enum EmMPEmbedMsg
{
    EV_BGN(MPEMBED) = EVSEG_MPEMBED_BGN,
#endif
	
	/*<<待机命令>>
	*消息流向 ：misc==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecDspSleep_Cmd)

	/*<<唤醒命令>>
	*消息流向 ：misc==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecDspWakeup_Cmd)

	/*<<唤醒命令>>
	*消息流向 ：misc==>dispatch==>mtmp
	*is_sleep : TRUE表示进入睡眠状态，FALSE表示进入唤醒状态
	*/
    MESSAGE(Ev_MT_CodecSleepState_Ntf)
	BODY(mt::TBOOL32, is_sleep)

	/*<<本地铃声试听、按键音效、动画音效播放命令>>
	*sound_type : 声音种类 铃声、按键音效、动画音效
	*sound_id : 声音标识
	*play    ：TRUE-播放 FALSE-停止播放
	*消息流向 ：mtservice==>mtmp
	*see Ev_MT_CodecLocalSoundPlay_Ntf
	*/
    MESSAGE(Ev_MT_CodecLocalSoundPlay_Cmd)
	BODY(mt::TS32, sound_type) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmLocalSoundType
	BODY(mt::TS32, sound_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmLocalSoundIndex
	BODY(mt::TBOOL32, play)

	/*<<本地铃声试听、按键音效、动画音效播放状态提示(暂时只有铃声试听才上报)>>
	*sound_type : 声音种类 铃声、按键音效、动画音效
	*sound_id : 声音标识
	*play    ：TRUE-播放 FALSE-停止播放
	*消息流向 ：mtmp==>mtservice
	*see Ev_MT_CodecLocalSoundPlay_Cmd
	*/
    MESSAGE(Ev_MT_CodecLocalSoundPlay_Ntf)
	BODY(mt::TS32, sound_type) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmLocalSoundType
	BODY(mt::TS32, sound_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmLocalSoundIndex
	BODY(mt::TBOOL32, play)

	/*<<本地铃声试听、按键音效、动画音效播放查询请求(按键音效和动画音效由于是个短操作，暂时不提供查询)>>
	*sound_type : 声音种类 铃声、按键音效、动画音效
	*sound_id : 声音标识
	*play    ：TRUE-播放 FALSE-停止播放
	*消息流向 ：mtservice==>mtmp
	*see Ev_MT_CodecGetLocalSoundPlayState_Rsp
	*/
    MESSAGE(Ev_MT_CodecGetLocalSoundPlayState_Req)
	BODY(mt::TS32, sound_type) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmLocalSoundType
	BODY(mt::TS32, sound_id)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmLocalSoundIndex

	/*<<本地铃声试听、按键音效、动画音效播放查询响应(按键音效和动画音效由于是个短操作，暂时不提供查询)>>
	*sound_type : 声音种类 铃声、按键音效、动画音效
	*sound_id : 声音标识
	*play    ：TRUE-播放 FALSE-停止播放
	*消息流向 ：mtmp==>mtservice
	*see Ev_MT_CodecGetLocalSoundPlayState_Req
	*/
    MESSAGE(Ev_MT_CodecGetLocalSoundPlayState_Rsp)
	BODY(mt::TS32, sound_type) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmLocalSoundType
	BODY(mt::TS32, sound_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmLocalSoundIndex
	BODY(mt::TBOOL32, play)

	/*<<呼入、呼出响铃>>
	*calltype    ：TRUE-呼入 FALSE-呼出
	*play    ：TRUE-播放 FALSE-停止播放
	*消息流向 ：mtservice==>mtmp
	*see 
	*/
    MESSAGE(Ev_MT_CodecRingPlay_Cmd)
	BODY(mt::TBOOL32, callin)
	BODY(mt::TBOOL32, play)

	/*<<设置多画面风格请求>>
	*消息流向 ：mtservice==>mtmp
	*see Ev_MT_CodecSetPIP_Rsp
	*/
    MESSAGE(Ev_MT_CodecSetPIP_Req)
	BODY(mt::TMtPIPMode, pip_mode)

	/*<<设置多画面风格响应>>
	*消息流向 ：mtmp==>mtservice
	*see Ev_MT_CodecSetPIP_Req
	*/
    MESSAGE(Ev_MT_CodecSetPIP_Rsp)
	BODY(mt::TMtPIPMode, pip_mode)

	/*<<查询多画面风格请求>>
	*消息流向 ：mtservice==>mtmp
	*see Ev_MT_CodecQueryPIP_Rsp
	*/
    MESSAGE(Ev_MT_CodecQueryPIP_Req)

	/*<<查询多画面风格响应>>
	*消息流向 ：mtmp==>mtservice
	*see Ev_MT_CodecQueryPIP_Req
	*/
    MESSAGE(Ev_MT_CodecQueryPIP_Rsp)
	BODY(mt::TMtPIPMode, pip_mode)

	/*<<多画面风格状态通知>>
	*消息流向 ：mtmp==>mtservice
	*/
    MESSAGE(Ev_MT_CodecPIPState_Ntf)
	BODY(mt::TMtPIPMode, pip_mode)

	/*<<交换画中画命令>>
	*消息流向 ：sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSwitchPIP_Cmd)

	/*<<色带测试命令>>
	*on ：开启or停止
	*消息流向 ：sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecRibbonTest_Cmd)
	BODY(mt::TBOOL32, on)

	/*<<色带测试状态通知>>
	*on ：是否在色带测试
	*消息流向 ：mtmp==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_CodecRibbonTest_Ntf)
	BODY(mt::TBOOL32, on)		

	/*<<色带测试状态查询请求>>
	*消息流向 ：mtservice==>mtmp
	* see Ev_MT_CodecRibbonTestStatus_Rsp
	*/
    MESSAGE(Ev_MT_CodecRibbonTestStatus_Req)

	/*<<色带测试状态查询响应>>
	*on ：是否在色带测试
	*消息流向 ：mtmp==>mtservice
	* see Ev_MT_CodecRibbonTestStatus_Req
	*/
    MESSAGE(Ev_MT_CodecRibbonTestStatus_Rsp)
	BODY(mt::TBOOL32, on)	

	/*<<设置画面合成风格>>
	*vmp_type ：画面合成风格
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_VMPSetType_Cmd)
	BODY(mt::TU32, vmp_type)

	/*<<设置发送地址>>
	*send_addr ：设置合成视频的发送地址
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_VMPSetSendAddr_Cmd)
	BODY(mt::TNetAddr, send_addr)

	/*<<设置合成视频的编码参数>>
	*vid_enc_param ：编码参数
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_VMPSetVidEncParam_Cmd)
	BODY(mt::TVidEncParam, vid_enc_param)

	/*<<开始画面合成>>
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_VMPStart_Cmd)

	/*<<停止画面合成>>
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_VMPStop_Cmd)

	/*<<添加合成成员>>
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_VMPAddMem_Cmd)
	BODY(mt::TMultiVMPMemParam, vmp_memparams)

	/*<<删除合成成员>>
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_VMPDelMem_Cmd)
	BODY(mt::TMultiU32, chan_indexs)//（是个repeated）

	/*<<发送关键帧>>
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_VMPSendFastUpdate_Cmd)

	/*<<调整编码码率>>
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_VMPSetBitrate_Cmd)
	BODY(mt::TU16, bitrate)


	//mixer
	/*<<设置混音深度>>
	*mixer_depth ：混音深度
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_MixerSetDepth_Cmd)
	BODY(mt::TU32, mixer_depth)
	/*<<设置发送地址>>
	*send_addr ：设置合成视频的发送地址
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_MixerSetSendAddr_Cmd)
	BODY(mt::TNetAddr, send_addr)
	/*<<设置混音的编码参数>>
	*vid_enc_param ：编码参数
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_MixerSetVidEncParam_Cmd)
	BODY(mt::TAudEncDecParam, Aud_enc_param)
	/*<<开始混音>>
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_MixerStart_Cmd)

	/*<<停止混音>>
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_MixerStop_Cmd)

	/*<<添加混音成员成员>>
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_MixerAddMem_Cmd)
	BODY(mt::TMultiMixerMemParam, mixer_memparams)

	/*<<删除合成成员>>
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_MixerDelMem_Cmd)
	BODY(mt::TMultiU32, chan_indexs)//（是个repeated）

	/*<<单路编解码器自环>>
	*传输方向：mtservice->mtmp
	* see Ev_MT_LocalSingleLoop_Ntf
	*/
	MESSAGE( Ev_MT_LocalSingleLoop_Cmd )
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TBOOL32,   bStart)

	/*<<单路编解码器自环>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_LocalSingleLoop_Cmd
	*/
	MESSAGE( Ev_MT_LocalSingleLoop_Ntf)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TBOOL32,   bStart)

	/*<<码流转发的模拟自环>>
	*传输方向：mtservice->mtmp
	* see Ev_MT_SimulatLocalSingleLoop_Cmd
	*/
	MESSAGE( Ev_MT_SimulatLocalSingleLoop_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TBOOL32,   bStart)

	/*<<音频自环>>
	*传输方向：mtservice->mtmp
	* see Ev_MT_AudioLoop_Ntf
	*/
	MESSAGE( Ev_MT_AudioLoop_Cmd )
	BODY(mt::TBOOL32,   bStart)

	/*<<音频自环状态提示>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_AudioLoop_Cmd
	*/
	MESSAGE( Ev_MT_AudioLoop_Ntf)
	BODY(mt::TBOOL32,   bStart)
	
	/*<<音频输入音量查询请求>>
	*传输方向：mtservice->mtmp
	* see Ev_MT_MtmpAudioInVolume_Rsp
	*/
	MESSAGE( Ev_MT_MtmpAudioInVolume_Req )

	/*<<音频输入音量查询响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_MtmpAudioInVolume_Req
	*/
	MESSAGE( Ev_MT_MtmpAudioInVolume_Rsp)
	BODY(mt::TU8,   byVol)

	/*<<麦克音量查询请求>>
	*传输方向：mtservice->mtmp
	* see Ev_MT_MtmpMicVolumeDetect_Rsp
	*/
	MESSAGE( Ev_MT_MtmpMicVolumeDetect_Req )
	BODY(mt::TS32, mic)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmHDAudPortIn

	/*<<麦克音量查询响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_MtmpMicVolumeDetect_Req
	*/
	MESSAGE( Ev_MT_MtmpMicVolumeDetect_Rsp )
	BODY(mt::TS32, mic)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmHDAudPortIn
	BODY(mt::TU8,   byVol)


    /*<<麦克风增益>>
	*传输方向：mtservice->mtmp
	* see Ev_MT_CodecSetMicGain_Ntf
	*/
	MESSAGE( Ev_MT_CodecSetMicGain_Cmd )
	BODY(mt::TU32, vol)

	/*<<麦克风增益通知>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_CodecSetMicGain_Cmd
	*/
	MESSAGE( Ev_MT_CodecSetMicGain_Ntf )
	BODY(mt::TU32, vol)




	/*<<音频输入接口状态查询请求>>
	*传输方向：mtsdk->mtservice->mtmp
	* see Ev_MT_MtmpAudioInputState_Rsp
	*/
	MESSAGE( Ev_MT_MtmpAudioInputState_Req )
	BODY(mt::TMultiAudInputState,   tInput_State)

	/*<<音频输入接口状态查询响应>>
	*传输方向：mtmp->mtservice->mtsdk
	* see Ev_MT_MtmpAudioInputState_Req
	*/
	MESSAGE( Ev_MT_MtmpAudioInputState_Rsp )
	BODY(mt::TMultiAudInputState,   tInput_State)

	/*<<音频输出接口状态查询请求>>
	*传输方向：mtsdk->mtservice->mtmp
	* see Ev_MT_MtmpAudioOutputState_Rsp
	*/
	MESSAGE( Ev_MT_MtmpAudioOutputState_Req )
	BODY(mt::TMultiAudOutputState,   tOutput_State)

	/*<<音频输出接口状态查询响应>>
	*传输方向：mtmp->mtservice->mtsdk
	* see Ev_MT_MtmpAudioOutputState_Req
	*/
	MESSAGE( Ev_MT_MtmpAudioOutputState_Rsp )
	BODY(mt::TMultiAudOutputState,   tOutput_State)

	/*<<视频接口能力查询请求>>
	*传输方向：mtservice->mtmp
	* see Ev_MT_MtmpVideoInPortCap_Rsp
	*/
	MESSAGE( Ev_MT_MtmpVideoInPortCap_Req )

	/*<<视频接口能力查询响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_MtmpVideoInPortCap_Req
	*/
	MESSAGE( Ev_MT_MtmpVideoInPortCap_Rsp )
	BODY(mt::TMTHDVidInPortCapList, cap_list)

    /*<<视频接口能力主动上报>>
	*传输方向：mtservice->mtmp
	* see 
	*/
	MESSAGE( Ev_MT_MtmpVideoInPortCap_Cmd )

	/*<<视频接口能力主动上报>>
	*传输方向：mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_MtmpVideoInPortCap_Ntf )
	BODY(mt::TMTHDVidInPortCapList, cap_list)

	/*<<设置视频输入接口命令>>
	*传输方向：mtsdk->mtservice->mtmp
	* see Ev_MT_CodecSetVidInPortCfg_Ntf
	*/
	MESSAGE(Ev_MT_CodecSetVidInPortCfg_Cmd)
	BODY(mt::TMTHDVidInPort, port_list)

	/*<<设置视频输入接口响应>>
	*传输方向：mtmp->mtservice->mtsdk
	* see Ev_MT_CodecSetVidInPortCfg_Cmd
	*/
	MESSAGE(Ev_MT_CodecSetVidInPortCfg_Ntf)
	BODY(mt::TMTHDVidInPort, port_list)

	/*<<设置多流多视命令>>
	*传输方向：mtsdk->mtservice->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_CodecSetMultiVideoCfg_Cmd)
	BODY(mt::TMTHDMultiVideo, multi_video)

	/*<<设置输入输出矩阵命令>>
	*传输方向：mtsdk->mtservice->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_CodecSetVideoMatrixSchemeCfg_Cmd)
	BODY(mt::TMTAllVideoMatrixScheme, matrix_scheme)

	/*<<设置音频输入接口>>
	*传输方向：mtservice->mtmp
	* see 
	*/
	MESSAGE( Ev_MT_CodecSetAudInPortList_Cmd )
	BODY(mt::TMTHDAudInPortList, tPortList)

	/*<<设置音频输出接口>>
	*传输方向：mtservice->mtmp
	* see 
	*/
	MESSAGE( Ev_MT_CodecSetAudOutPortList_Cmd )
	BODY(mt::TMTHDAudOutPortList, tPortList)

	/*<<视频源分辨率查询>>
	*传输方向：mtservice->mtmp
	* see Ev_MT_MtmpVidSrcStatus_Rsp
	*/
	MESSAGE( Ev_MT_MtmpVidSrcStatus_Req )

	/*<<视频源分辨率查询响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_MtmpVidSrcStatus_Req
	*/
	MESSAGE( Ev_MT_MtmpVidSrcStatus_Rsp )
	BODY(mt::TMtVidSrcInfoList, src_info_list)

	/*<<视频源分辨率上报>>
	*传输方向：mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_MtmpVidSrcStatus_Ntf )
	BODY(mt::TMtVidSrcInfoList, src_info_list)

	/*<<视频输入接口分辨率查询>>
	*传输方向：mtservice->mtmp
	* see Ev_MT_MtmpVidInPortRes_Rsp
	*/
	MESSAGE( Ev_MT_MtmpVidInPortRes_Req )

	/*<<视频输入接口分辨率查询响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_MtmpVidInPortRes_Req
	*/
	MESSAGE( Ev_MT_MtmpVidInPortRes_Rsp )
	BODY(mt::TMtVidInPortResInfoList, src_info_list)

	/*<<视频输入接口分辨率上报>>
	*传输方向：mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_MtmpVidInPortRes_Ntf )
	BODY(mt::TMtVidInPortResInfoList, src_info_list)

	/*<<查询SDI接口数量请求>>
	*传输方向：mtservice->mtmp
	* see Ev_MT_MtmpGetSdiInOut_Rsp
	*/
	MESSAGE( Ev_MT_MtmpGetSdiInOut_Req )

	/*<<查询SDI接口数量响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_MtmpGetSdiInOut_Req
	*/
	MESSAGE( Ev_MT_MtmpGetSdiInOut_Rsp )
	BODY(mt::TS32, sdi_inout) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmSdiInOut

	/*<<Fxo呼叫>>
	*传输方向：mtservice->mtmp
	* see 
	*/
	MESSAGE( Ev_MT_FxoMakeCall_Cmd )
	BODY(mt::TString, achPeerNumber)

	/*<<Fxo呼叫进入>>
	*传输方向：mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_FxoCallIncoming_Ntf )
	BODY(mt::TString, achPeerNumber)	//底层暂时获取不到对端号码

	/*<<Fxo 接受呼叫>>
	*传输方向：mtservice->mtmp
	* see 
	*/
	MESSAGE( Ev_MT_FxoAccept_Cmd )

	/*<<Fxo 拒绝接听>>
	*传输方向：mtservice->mtmp
	* see 
	*/
	MESSAGE( Ev_MT_FxoReject_Cmd )

	/*<<Fxo 挂断电话>>
	*传输方向：mtservice->mtmp
	* see 
	*/
	MESSAGE( Ev_MT_FxoHangup_Cmd )

	/*<<Fxo呼叫状态信息上报>>
	*传输方向：mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_FxoCallLinkState_Ntf )
	BODY(mt::TFxoState, tFxo_state)

	/*<<Fxo呼叫错误码上报>>
	*传输方向：mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_FxoCallErrorCode_Ntf )
	BODY(mt::TU32, error_code)	//0:未接电话线

	/*<<拍摄快照请求>>
	*传输方向：mtervice->mtmp
	* see Ev_MT_CodecSnapshot_Rsp
	*/
	MESSAGE( Ev_MT_CodecSnapshot_Req )
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, coder_id) //拍哪一路的快照。枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<拍摄快照响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_CodecSnapshot_Req
	*/
	MESSAGE( Ev_MT_CodecSnapshot_Rsp )
	BODY(mt::TU32, snapshot_state) //快照拍摄状态 0：成功 1：其他人正在拍照 2：磁盘空间不足 3:采集不到图像 4: 对端无码流 5:上传到ftp服务器失败
	BODY(mt::TSnapshotFileInfo, file_info) //携带新拍文件的信息

	/*<<新生成快照上报>>
	*传输方向：mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_CodecSnapshot_Ntf )
	BODY(mt::TSnapshotFileInfo, file_info) //携带新拍文件的信息

    /*<<ftp快照传输上报>>
	*传输方向：mtmp->mtmp
	* 
	*/
	MESSAGE( Ev_MT_CodecSendFileToFtp_Ntf )

	/*<<查询快照文件列表信息请求>>
	*传输方向：mtervice->mtmp
	* see Ev_MT_CodecSnapshotQueryFileList_Rsp
	*/
	MESSAGE( Ev_MT_CodecSnapshotQueryFileList_Req )

	/*<<查询快照文件列表信息响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_CodecSnapshotQueryFileList_Req
	*/
	MESSAGE( Ev_MT_CodecSnapshotQueryFileList_Rsp )
	BODY(mt::TS32, report_state) //一条消息上报不完文件列表时携带消息序列号（序列号从1开始计数），当收到最后一条消息时携带-1。只上报一条消息时携带0。
	BODY(mt::TSnapshotFileList, file_info)

	/*<<删除一张快照请求>>
	*传输方向：mtervice->mtmp
	* see Ev_MT_CodecSnapshotDelOneFile_Rsp
	*/
	MESSAGE( Ev_MT_CodecSnapshotDelOneFile_Req )
	BODY(mt::TSnapshotFileInfo, file_info) //文件信息

	/*<<删除一张快照响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_CodecSnapshotDelOneFile_Req
	*/
	MESSAGE( Ev_MT_CodecSnapshotDelOneFile_Rsp )
	BODY(mt::TBOOL32, del_state) //是否删除成功
	BODY(mt::TSnapshotFileInfo, file_info)

	/*<<一张快照被删除上报>>
	*传输方向：mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_CodecSnapshotDelOneFile_Ntf )
	BODY(mt::TSnapshotFileInfo, file_info)

	/*<<重命名一张快照请求>>
	*传输方向：mtervice->mtmp
	* see Ev_MT_CodecSnapshotRenameOneFile_Req
	*/
	MESSAGE( Ev_MT_CodecSnapshotRenameOneFile_Req )
	BODY(mt::TSnapshotFileInfo, file_info_old) //重命名前的文件信息
	BODY(mt::TSnapshotFileInfo, file_info_new) //重命名后的文件信息

	/*<<重命名一张快照响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_CodecSnapshotRenameOneFile_Req
	*/
	MESSAGE( Ev_MT_CodecSnapshotRenameOneFile_Rsp )
	BODY(mt::TBOOL32, rename_state) //是否重命名成功
	BODY(mt::TSnapshotFileInfo, file_info_old)//重命名前的文件信息
	BODY(mt::TSnapshotFileInfo, file_info_new)//重命名后的文件信息

	/*<<删除所有快照文件请求>>
	*传输方向：mtervice->mtmp
	* see Ev_MT_CodecSnapshotDelAllFile_Rsp
	*/
	MESSAGE( Ev_MT_CodecSnapshotDelAllFile_Req )

	/*<<删除所有快照文件响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_CodecSnapshotDelAllFile_Req
	*/
	MESSAGE( Ev_MT_CodecSnapshotDelAllFile_Rsp )
	BODY(mt::TBOOL32, del_state) //是否删除成功

	/*<<所有快照文件清空通知>>
	*传输方向：mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_CodecSnapshotDelAllFile_Ntf )

	/*<<导出一张快照文件请求>>
	*传输方向：mtervice->mtmp
	* see Ev_MT_CodecSnapshotExportOneFile_Rsp
	*/
	MESSAGE( Ev_MT_CodecSnapshotExportOneFile_Req )
	BODY(mt::TSnapshotFileInfo, file_info) //文件信息

	/*<<导出一张快照文件响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_CodecSnapshotExportOneFile_Req
	*/
	MESSAGE( Ev_MT_CodecSnapshotExportOneFile_Rsp )
	BODY(mt::TBOOL32, export_state) //是否导出成功
	BODY(mt::TSnapshotFileInfo, file_info)

	/*<<导出所有快照文件请求>>
	*传输方向：mtervice->mtmp
	* see Ev_MT_CodecSnapshotExportAllFile_Rsp
	*/
	MESSAGE( Ev_MT_CodecSnapshotExportAllFile_Req )

	/*<<导出所有快照文件响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_CodecSnapshotExportAllFile_Req
	*/
	MESSAGE( Ev_MT_CodecSnapshotExportAllFile_Rsp )
	BODY(mt::TS32, export_state) //导出状态 mt::EmFileCopyErr


    /*<<导出快照进度>>
	*传输方向：mtmp->mtservice
	*/
	MESSAGE( Ev_MT_CodecSnapshotExportProgress_Ntf )
	BODY(mt::TU32, progress) //导出进度(百分比)

	/*<<导出所有日志文件请求>>
	*传输方向：mtervice->mtmp
	* see Ev_MT_ExportAllLogFile_Rsp
	*/
	MESSAGE( Ev_MT_ExportAllLogFile_Req )

	/*<<导出所有日志文件响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_ExportAllLogFile_Req
	*/
	MESSAGE( Ev_MT_ExportAllLogFile_Rsp )
	BODY(mt::TS32, export_state) //导出状态 mt::EmFileCopyErr

	/*<<导出日志进度>>
	*传输方向：mtmp->mtservice
	*/
	MESSAGE( Ev_MT_AllLogFileExportProgress_Ntf )
	BODY(mt::TU32, progress) //导出进度(百分比)

	/*<<快照ftp>>
	*传输方向：mtervice->mtmp
	*index : 当前操作的预置位索引
	* see Ev_MT_CodecFtpJpeg_Ntf
	*/
	MESSAGE( Ev_MT_CodecFtpJpeg_Cmd )
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, coder_id) //拍哪一路的快照。枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<快照ftp>>
	*传输方向：mtmp->mtservice
	*index : 当前操作的预置位索引
	* see Ev_MT_CodecFtpJpeg_Cmd
	*/
	MESSAGE( Ev_MT_CodecFtpJpeg_Ntf )
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, coder_id) //拍哪一路的快照。枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TBOOL32, is_sucess) //是否拍摄成功

	/*<<拍摄摄像头预置位图片请求>>
	*传输方向：mtdevice->mtmp
	*index : 当前操作的预置位索引
	* see Ev_MT_CodecCameraPic_Ntf
	*/
	MESSAGE( Ev_MT_CodecCameraPic_Cmd )
    BODY(mt::TS32, vid_idx) // 拍第几个摄像机
	//BODY(mt::TS32, coder_id) //拍哪一路的快照。枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	//BODY(mt::TS32, video_port)//对应的摄像头配置。枚举值统一使用mt::TS32来传输，该处实际为mt::EmMtVideoPort
	BODY(mt::TS32, save_idx)//保存的第几个预置位

	/*<<拍摄摄像头预置位图片响应>>
	*传输方向：mtmp->mtservice
	*index : 当前操作的预置位索引
	* see Ev_MT_CodecCameraPic_Cmd
	*/
	MESSAGE( Ev_MT_CodecCameraPic_Ntf )
	BODY(mt::TS32, coder_id) //拍哪一路的快照。枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TS32, video_port)//对应的摄像头配置。枚举值统一使用mt::TS32来传输，该处实际为mt::EmMtVideoPort
	BODY(mt::TS32, save_idx)//保存的第几个预置位
	BODY(mt::TBOOL32, is_sucess) //是否拍摄成功


    /*<<开启监控图片拍摄功能>>
	*传输方向：mtervice->mtmp
	* see Ev_MT_CodecMonitorPic_Ntf
	*/
    MESSAGE( Ev_MT_CodecMonitorPic_Cmd )
    BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
    BODY(mt::TS32, coder_id) //拍哪一路的快照。枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TBOOL32, opt)//TRUE开启   FALSE关闭
    BODY(mt::TS32, pic_index)//下一次获取快照的index 0/1

	/*<<开启监控图片拍摄功能响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_CodecMonitorPic_Cmd
	*/
    MESSAGE( Ev_MT_CodecMonitorPic_Ntf )
    BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
    BODY(mt::TS32, coder_id) //拍哪一路的快照。枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TBOOL32, status)//TRUE开启   FALSE关闭

    /*<<图片获取>>
	*传输方向：mtservice->mtmp
	* see Ev_MT_CodecPicGet_Rsp
	*/
    MESSAGE( Ev_MT_CodecPicGet_Req )
    BODY(mt::TS32, index)//获取的监控图片index 0/1

	/*<<图片获取相应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_CodecPicGet_Req
	*/
    MESSAGE( Ev_MT_CodecPicGet_Rsp )
	BODY(mt::TBOOL32, result)//获取结果

    /*<<查询监控图片拍摄功能是否开启>>
	*传输方向：mtervice->mtmp
	* see Ev_MT_CodecMonitorPicStatus_Rsp
	*/
    MESSAGE( Ev_MT_CodecMonitorPicStatus_Req )
    BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
    BODY(mt::TS32, coder_id) //拍哪一路的快照。枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<查询监控图片拍摄功能响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_CodecMonitorPicStatus_Req
	*/
    MESSAGE( Ev_MT_CodecMonitorPicStatus_Rsp )
    BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
    BODY(mt::TS32, coder_id) //拍哪一路的快照。枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TBOOL32, status)//TRUE开启   FALSE关闭




	/*<<本地视频源选看指令>>
	*encoder_id    ：第一路主视频源、第二路主视频源
	*消息流向 ：service==>dispatch==>mtmp
	* see Ev_MT_CodecSelectLocalVideoView_Ntf
	*/
    MESSAGE(Ev_MT_CodecSelectLocalVideoView_Cmd)
	BODY(mt::TS32, encoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<本地视频源选看通知>>
	*encoder_id    ：第一路主视频源、第二路主视频源
	*消息流向 ：mtmp==>dispatch==>service
	* see Ev_MT_CodecSelectLocalVideoView_Cmd
	*/
    MESSAGE(Ev_MT_CodecSelectLocalVideoView_Ntf)
	BODY(mt::TS32, encoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<本地视频源选看内容查询请求>>
	*encoder_id    ：第一路主视频源、第二路主视频源
	*消息流向 ：service==>dispatch==>mtmp
	* see Ev_MT_CodecGetLocalVideoView_Rsp
	*/
    MESSAGE(Ev_MT_CodecGetLocalVideoView_Req)

	/*<<本地视频源选看内容查询响应>>
	*encoder_id    ：第一路主视频源、第二路主视频源
	*消息流向 ：mtmp==>dispatch==>service
	* see Ev_MT_CodecGetLocalVideoView_Req
	*/
    MESSAGE(Ev_MT_CodecGetLocalVideoView_Rsp)
	BODY(mt::TS32, encoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<刷新台标>>
	*pic_file_name    ：新台标图片的文件名
	*消息流向 ：service==>dispatch==>mtmp
	* see 
	*/
    MESSAGE(Ev_MT_CodecLabelUpdate_Cmd)
	BODY(mt::TMTLabelInfo, TMTLabelInfo)
    BODY(mt::TBOOL32, openlabel)   // 是否需要打开台标

	/*<<刷新横幅>>
	*pic_file_name    ：新横幅图片的文件名
	*消息流向 ：service==>dispatch==>mtmp
	* see 
	*/
    MESSAGE(Ev_MT_CodecBannerUpdate_Cmd)
	BODY(mt::TMTBannerInfo, TMTBannerInfo)
    BODY(mt::TMultiU32, actual_linenum)

	/*<<设置视频显示比率>>
	*display_ratio    ：显示比率
	*消息流向 ：service==>dispatch==>mtmp
	* see 
	*/
    MESSAGE(Ev_MT_CodecSetDisplayRatio_Cmd)
    BODY(mt::TMTDisplayRatio, display_ratio)

	/*<<视频输入输出接口类型通知消息>>
	*port_mode    ：接口模式
	*消息流向 ：mtmp内部使用
	* see 
	*/
    MESSAGE(Ev_MT_CodecVideoInOutPortMode_Ntf)
    BODY(mt::TMTVideoInOutPortModeList, port_mode)

	/*<<设置视频亮度、对比度、饱和度>>
	*消息流向 ：service==>dispatch==>mtmp
	* see 
	*/
    MESSAGE(Ev_MT_CodecSetVidImgParam_Cmd)
	BODY(mt::TS32, codec_type)//该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //该处实际为mt::EmCodecComponentIndex
	BODY(mt::TS32, param_type) //该处实际为mt::EmImgParam
	BODY(mt::TU32, param_value)//参数值

	/*<<设置视频输出分辨率>>
	*消息流向 ：service==>dispatch==>mtmp
	* see 
	*/
	MESSAGE(Ev_MT_CodecSetHDResOutput_Cmd)
	BODY(mt::TMTVideoOutPortMode, video_mode)

	/*<<设置视频变形拉伸>>
	*消息流向 ：service==>dispatch==>mtmp
	* see 
	*/
    MESSAGE(Ev_MT_CodecSetDeformationTensile_Cmd)
    BODY(mt::TMTHDImageDeformationTensile, Tensile)

	/*<<设置视频等比缩放>>
	*消息流向 ：service==>dispatch==>mtmp
	* see 
	*/
    MESSAGE(Ev_MT_CodecSetGeometricScaling_Cmd)
    BODY(mt::TMTHDImageGeometricScaling, Scaling)

	/*<<设置图像降噪等级>>
	*消息流向 ：service==>dispatch==>mtmp
	* see 
	*/
    MESSAGE(Ev_MT_CodecSetImageNoiseLevel_Cmd)
    BODY(mt::TMTHDImageNoise, Noise)

	/*<<设置解码后加黑边、裁边与非等比的视频处理策略>>
	*消息流向 ：service==>dispatch==>mtmp
	* see 
	*/
    MESSAGE(Ev_MT_CodecSetResizeMode_Cmd)
    BODY(mt::TMTResizeMode, ResizeMode)

	/*<<设置VGA输出亮度、对比度、饱和度>>
	*消息流向 ：service==>dispatch==>mtmp
	* see 
	*/
    MESSAGE(Ev_MT_CodecSetVgaOutImgParam_Cmd)
	BODY(mt::TS32, param_type) //该处实际为mt::EmImgParam
	BODY(mt::TU32, param_value)//参数值



	/*<<查询最近拍摄文件请求>>
	*传输方向：mtervice->mtmp
	* see Ev_MT_CodecSnapshotQueryLatestFile_Rsp
	*/ 
	MESSAGE( Ev_MT_CodecSnapshotQueryLatestFile_Req )

	/*<<查询最近拍摄文件响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_CodecSnapshotQueryLatestFile_Req
	*/
	MESSAGE( Ev_MT_CodecSnapshotQueryLatestFile_Rsp )
	BODY(mt::TU32, result) //查询状态结果 0：成功 1：失败
	BODY(mt::TSnapshotFileInfo, file_info) //携带最新拍摄文件的信息

    /*<<获取辅视频源是否有源请求>>
	*传输方向：mtservice_hd->mtmp
	* see Ev_MT_AssVideoPortStatus_Rsp
	*/
	MESSAGE( Ev_MT_AssVideoPortStatus_Req )

	/*<<获取辅视频源是否有源响应>>
	*传输方向：mtmp->mtservice_hd
	* see Ev_MT_AssVideoPortStatus_Req
	*/
	MESSAGE( Ev_MT_AssVideoPortStatus_Rsp )
	BODY(mt::TS32, vga_state) //Vga是否插入1:插入 0:未插入
    BODY(mt::TS32, hdmi_state) //Hdmi是否插入1:插入 0:未插入

	/*<<开启OSD>>
	*传输方向：mtmfgtest/mtservice->mtmp
	* see 
	*/
	MESSAGE( Ev_MT_CodecSetOsdOpen_Cmd )

    /*<<开启OSD>>
	*传输方向：mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_CodecSetOsdOpen_Ntf )
    BODY(mt::TBOOL32, bSuccess)

	/*<<关闭OSD>>
	*传输方向：mtmfgtest/mtservice->mtmp
	* see 
	*/
	MESSAGE( Ev_MT_CodecSetOsdClose_Cmd )

    /*<<关闭OSD>>
	*传输方向：mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_CodecSetOsdClose_Ntf )
    BODY(mt::TBOOL32, bSuccess)

    /*<<开启、关闭OSD穿透请求>>
	*消息流向 ：mtservice==>dispatch==>mtmpapp
	* see Ev_MT_SetOsdTransparent_Rsp
	*/
    MESSAGE(Ev_MT_SetOsdTransparent_Req)
	BODY(mt::TBOOL32, trans)

	/*<<开启、关闭OSD穿透响应>>
	*消息流向 ：mtmpapp==>dispatch==>mtservice
	* see Ev_MT_SetOsdTransparent_Req
	*/
    MESSAGE(Ev_MT_SetOsdTransparent_Rsp)
    BODY(mt::TBOOL32, trans)
    BODY(mt::TS32, result)

	/*<<设置无图像显示策略>>
	*消息流向 ：mtservice==>dispatch==>mtmpapp
	* see 
	*/
    MESSAGE(Ev_MT_SetLastDisplayCfg_Cmd)
    BODY(mt::TMTLastDisplay, )

	/*<<VGA图像调节>>
	*消息流向 ：mtservice==>dispatch==>mtmpapp
	* see 
	*/
    MESSAGE(Ev_MT_SetVGAImageAdjustCfg_Cmd)
    BODY(mt::TMTVgaImageAdjustCfg, )

	/*<< 自动声音时延检测命令 >>
	*[消息体]
	*    + start: 开始或停止
	*[消息方向]
	*    mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_AutoAudioDelayCheckCmd)
	BODY(mt::TBOOL32, start)

	/*<< 自动声音时延检测通知 >>
	*[消息体]
	*    + state(EmAudioDelayCheckState)：检测状态
	*    + result：当EmAudioDelayCheckState为emAudioDelayChecked时，此值有效，表示时延值
	*             当EmAudioDelayCheckState为emAudioDelayFailed时，此值有效，表示失败错误码
	*[消息方向]
	*    mtmpapp=>dispatch=>mtservice
	*/
	MESSAGE(Ev_MT_AutoAudioDelayCheckNtf)
	BODY(mt::TU32, state)
	BODY(mt::TU32, result)


    /*<<画中画显示开关>>
	*消息流向 ：mtservice==>dispatch==>mtmpapp
	*/
    MESSAGE(Ev_MT_SetAutoPip_Cmd)
	BODY(mt::TBOOL32, autopip)

    /*<开启或关闭OSD快照通知>
    *传输方向：mtmpapp=>dispatch=>mtservice
    *see Ev_MT_CodecOsdSnapshot_Cmd
    */
    MESSAGE(Ev_MT_CodecOsdSnapShotOpen_Ntf)
    BODY(mt::TBOOL32, opt)  // TRUE打开 FLASE关闭

    /*<<拍摄OSD快照请求命令>>
	*传输方向：mtservice=>dispatch=>mtmpapp
	* see Ev_MT_CodecOsdSnapshotOpen_Ntf
	*/
    MESSAGE(Ev_MT_CodecOsdSnapshot_Cmd)

    	/*<设置是否显示osd>
    *传输方向：mtservice->mtmpapp
    *
    */
    MESSAGE(Ev_MT_CodecSetShowOsd_Cmd)
	BODY(mt::TBOOL32, bShow)  // TRUE打开 FLASE关闭

	/*<通知是否显示osd>
    *传输方向：mtmpapp->mtservice
    *
    */
    MESSAGE(Ev_MT_CodecIsShowOsd_Ntf)
	BODY(mt::TBOOL32, bShow)  // TRUE打开 FLASE关闭

    /*<SDI输入输出状态改变>
    *传输方向：mtservice->mtservice_hd
    *
    */
    MESSAGE(Ev_MT_SDIOutputStateUpdate_Cmd)
    BODY(mt::TBOOL32, bSdiOutOff)  // sdi输出口是否打开

	/*<开启录像开关>
    *传输方向：mtmpapp=>mtasfRecord
    */
    MESSAGE(EV_MT_Record_Start_Cmd)
	BODY(mt::TString, PathName)  // 保存录像文件名

	 /*<开启录像开关结果回复>
    *传输方向：mtasfapp=>mtmpapp    mtasfapp=>dispatch
    */
    MESSAGE(EV_MT_Record_Start_Ntf)               
	BODY(mt::TBOOL32, opt)  // 成功？

	/*<关闭录像开关>
    *传输方向：mtmpapp=>mtasfapp
    */
    MESSAGE(EV_MT_Record_Stop_Cmd)         
	BODY(NULL,NULL )  // 

	/*<关闭录像开关回复>
    *传输方向：mtasfapp=>dispatch
    */
    MESSAGE(EV_MT_Record_Stop_Ntf)       
	BODY(mt::TBOOL32,NULL )  // 

	/*<添加音频录像流>
    *传输方向：mtmpapp=>mtasfapp
    */
    MESSAGE(EV_MT_Record_AddStream_Audio_Cmd)
	BODY( TAddRecordAudioMediaInfo, tAddRecordAudioMediaInfoMess )  // 添加音频流的结结构

	/*<添加视频录像流>
    *传输方向：mtmpapp=>mtasfapp
    */
    MESSAGE(EV_MT_Record_AddStream_Video_Cmd)
	BODY( TAddRecordVideoMediaInfo, tAddRecordVideoMediaInfoMess )  // 添加视频流的结结构

	/*<添加录像流回复>
    *传输方向：mtasfapp=>mtmpapp
    */
    MESSAGE(EV_MT_Record_AddStream_Ntf)
	BODY( u32 && TBOOL32 ,NULL )  //  添加流的结结构		

	/*<写入录像数据到文件>
    *传输方向：mtmpapp=>mtasfapp
    */
    MESSAGE(EV_MT_Record_WriteRecord_Cmd)
	BODY( NULL, NULL )  // 写入数据的结构

		/*<写入录像数据到文件>
    *传输方向：mtmpapp=>mtasfapp
    */
    MESSAGE(EV_MT_Record_WriteRecord_Ntf)
	BODY( NULL, NULL )  // 写入数据的结构

	/*<录像数据发生变化>
    *传输方向：mtmpapp=>mtmpapp
    */
    MESSAGE(EV_MT_Record_DataChange_Ntf)		
	BODY(NULL,NULL )  //  无

	/*<录像状态回应>
    *传输方向：mtasfapp=>dispatch
    */
    MESSAGE(EV_MT_Record_Status_Ntf)
	BODY(mt::u32, dwStreamNum)  // 哪个位置出现问题了
	BODY(mt::u32, dwStatus)  // 录像的状态

		/*<暂停录像>
    *传输方向：dispatch=>mtmpappp
    */
    MESSAGE(EV_MT_Record_Pause_Cmd)			
	BODY( NULL, NULL )  // 

	/*<暂停录像回复>
    *传输方向：mtmpapp=>dispatch
    */
    MESSAGE(EV_MT_Record_Pause_Ntf)			
	BODY( mt::TBOOL32, NULL )  // 

	/*<继续录像>
    *传输方向：dispatch=>mtmpappp
    */
    MESSAGE(EV_MT_Record_Continue_Cmd)		
	BODY( NULL, NULL )  // 

	/*<继续录像回复>
    *传输方向：mtmpapp=>dispatch
    */
    MESSAGE(EV_MT_Record_Continue_Ntf)		
	BODY( mt::TBOOL32, NULL )  // 

	/*<检测存储空间请求>
    *传输方向：dispatch=>mtmpapp=>mtasfapp
    */
    MESSAGE(EV_MT_Record_Check_StorageSpace_Req)		
	BODY( NULL, NULL )  //

	/*<检测存储空间回复>
    *传输方向：dispatch <= mtasfapp
    */
    MESSAGE(EV_MT_Record_Check_StorageSpace_Rsp)		
	BODY( U32, dwSpaceSize )  //

	/*<剩余录像时间回复>
    *传输方向 dispatch <= mtasfapp
    */
    MESSAGE(EV_MT_Record_RemainTime_Ntf)		
	BODY( U32, dwRemainTime )  // 剩余时间 S

	/*<剩余录像时间定时器>
    *传输方向：videorecord->dispatch
    */
    MESSAGE(EV_MT_Record_Remain_Timer)		// ntf
	BODY( NULL, NULL )  // 

	/*<剩余录像空间定时器>
    *传输方向：videorecord->dispatch
    */
    MESSAGE(EV_MT_Record_CheckSpace_Timer)		// ntf
	BODY( NULL, NULL )  //

	/*<请求录像已经录的时间>
    *传输方向：videorecord->dispatch
    */
    MESSAGE(EV_MT_Record_Start_time_Cmd)		
	BODY( NULL , NULL )  // 

	/*<回复录像已经录的时间>
    *传输方向：videorecord->dispatch
    */
    MESSAGE(EV_MT_Record_Start_time_Ntf)		
	BODY( mt::TU32 , tdwRecordTime )  // 已经录像时间 毫秒数

		/*<重启录像>
    *传输方向：mtmpapp=>mtasfRecord
    */
    MESSAGE(EV_MT_Record_ReStart_Cmd)
	BODY(mt::TString, PathName)  // 保存录像文件名

	/*<录像应答定时器>
    *传输方向：videorecord->dispatch
    */
    MESSAGE( EV_MT_Record_CheckRespond_Timer )		// ntf
	BODY( NULL, NULL )  //

    /*<清除上次设置的台标信息>
    *传输方向：mtmpapp=>mtservice_hd
    */
    MESSAGE(EV_MT_Clear_Label_Cmd)

    /*<sdi状态变化修正源信息>
    *传输方向：mtmpapp=>mtservice_hd
    */
    MESSAGE(EV_MT_SDIInputPortNumChange_Cmd)
    BODY(mt::TS32, SdiInout)  // sdi输入输出状态

    /*<<双屏模式收双流下第二屏是否显示远端辅流开关>>
	*消息流向 ：mtservice==>dispatch==>mtmpapp
	*/
    MESSAGE(Ev_MT_ShowRemoteAssVideo_Cmd)
	BODY(mt::TBOOL32, showRemoteAssVideo)

    /*<硬件芯片获取请求>
    *传输方向：mtservice=>dispatch=>mtmpapp
    */
    MESSAGE(EV_MT_HwChipInfoInquire_Req)

	/*<硬件芯片获取请求回复>
    *传输方向：mtmpapp=>dispatch=>mtservice
    */
    MESSAGE(EV_MT_HwChipInfoInquire_Rsp)		
	BODY( mt::TMtHwChipInfoList, hwchipinfolist )

	/*<硬件芯片获取响应>
    *传输方向 mtmpapp=>dispatch=>mtservice
    */
    MESSAGE(EV_MT_HwChipInfoInquire_Ntf)		
	BODY( mt::TMtHwChipInfoList, hwchipinfolist )
	
	/*<本地辅流扩声设置>
    *传输方向 sdk=>dispatch=>mtservice
    */
    MESSAGE(EV_MT_SetSubAudExpansion_Cmd)		
	BODY( mt::TBOOL32, bSubAudExpansion )

	/*<本地辅流扩声设置响应>
    *传输方向 mtservice=>dispatch=>sdk
    */
    MESSAGE(EV_MT_SetSubAudExpansion_Ntf)		
	BODY( mt::TBOOL32, bSubAudExpansion )
	BODY( mt::TU32, result )
	
	/*<<<会议取消保活通知>>
	* 消息流向 ：mp==>dispatch==>mtservice
	*/
	MESSAGE( Ev_MT_ConfNotKeepAlive_Ntf )

    /*<<<码流通知界面>>
    * 消息流向 ：mtmp==>dispatch==>mtservice
    */
    MESSAGE(Ev_MT_VidStreamAppear_Ntf)
    BODY(mt::TS32, type)  //这个值用于确认是回调收到码流时候上报还是其他时候上报

#if !defined(_MESSAGE_HELP_)
    EV_END(MPEMBED) = EVSEG_MPCOMMON_END
};
#endif

#define Is_MPEmbed_Msg(m) ((m) >= Ev_MT_BGN(MPEMBED) && (m) <= Ev_MT_END(MPEMBED))

#endif // _MTMPEMBEDMSG_H_