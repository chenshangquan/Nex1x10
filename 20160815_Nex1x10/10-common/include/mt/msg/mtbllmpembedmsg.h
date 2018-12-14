#ifndef _MTBLLMPEMBEDMSG_H_
#define _MTBLLMPEMBEDMSG_H_

#include "mtmsgid.h"
#include "struct.pb.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMPEmbedMsg
{
    EV_BLL_BGN(MPEMBED) = EVSEG_BLL_MPEMBED_BGN,
#endif
	
	/*<<待机请求>>
	*消息流向 ：misc==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecDspSleep_Req)

	/*<<待机响应>>
	*消息流向 ：misc==>dispatch==>mtmp
	* is_sucess: 是否允许待机
	* fail_reason: 待机失败原因
	*/
    MESSAGE(Ev_MT_BLL_CodecDspSleep_Rsp)
	BODY(mt::TBOOL32, is_sucess)
	BODY(mt::TS32, fail_reason) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmSleepFailReason

	/*<<唤醒命令>>
	*消息流向 ：misc==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecDspWakeup_Cmd)

	/*<<待机状态上报>>
	*消息流向 ：misc==>dispatch==>mtmp
	*is_sleep : TRUE表示进入睡眠状态，FALSE表示进入唤醒状态
	*/
    MESSAGE(Ev_MT_BLL_CodecSleepState_Ntf)
	BODY(mt::TBOOL32, is_sleep)

	/*<<待机失败原因上报>>
	*消息流向 ：misc==>dispatch==>mtmp
	*fail_reason : 失败原因
	*/
    MESSAGE(Ev_MT_BLL_CodecSleepFailReason_Ntf)
	BODY(mt::TS32, fail_reason) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmSleepFailReason

	/*<<本地铃声、按键音、音效播放命令>>
	*sound_type : 声音种类 铃声、按键音效、动画音效
	*sound_id : 声音标识
	*play    ：TRUE-播放 FALSE-停止播放
	*消息流向 ：sdk==>mtservice
	*see Ev_MT_BLL_CodecLocalSoundPlay_Ntf
	*/
    MESSAGE(Ev_MT_BLL_CodecLocalSoundPlay_Cmd)
	BODY(mt::TS32, sound_type) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmLocalSoundType
	BODY(mt::TS32, sound_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmLocalSoundIndex
	BODY(mt::TBOOL32, play)

    /*<<本地铃声、按键音、音效只播放一次命令>>
	*sound_type : 声音种类 铃声、按键音效、动画音效
	*sound_id : 声音标识
	*play    ：TRUE-播放 FALSE-停止播放
	*消息流向 ：sdk==>mtservice
	*see Ev_MT_BLL_CodecLocalSoundPlay_Ntf
	*/
    MESSAGE(Ev_MT_BLL_CodecLocalSoundPlayOnce_Cmd)
	BODY(mt::TS32, sound_type) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmLocalSoundType
	BODY(mt::TS32, sound_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmLocalSoundIndex
	BODY(mt::TBOOL32, play)

	/*<<本地铃声、按键音、音效播放状态提示>>
	*sound_type : 声音种类 铃声、按键音效、动画音效
	*sound_id : 声音标识
	*play    ：TRUE-播放 FALSE-停止播放
	*消息流向 ：mtservice==>sdk
	*see Ev_MT_BLL_CodecLocalSoundPlay_Cmd
	*/
    MESSAGE(Ev_MT_BLL_CodecLocalSoundPlay_Ntf)
	BODY(mt::TS32, sound_type) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmLocalSoundType
	BODY(mt::TS32, sound_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmLocalSoundIndex
	BODY(mt::TBOOL32, play)

	/*<<本地铃声、按键音效、动画音效播放查询请求(按键音效和动画音效由于是个短操作，暂时不提供查询)>>
	*sound_type : 声音种类 铃声、按键音效、动画音效
	*sound_id : 声音标识
	*play    ：TRUE-播放 FALSE-停止播放
	*消息流向 ：sdk==>mtservice
	*see Ev_MT_BLL_CodecGetLocalSoundPlayState_Rsp
	*/
    MESSAGE(Ev_MT_BLL_CodecGetLocalSoundPlayState_Req)
	BODY(mt::TS32, sound_type) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmLocalSoundType
	BODY(mt::TS32, sound_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmLocalSoundIndex

	/*<<本地铃声、按键音效、动画音效播放查询响应(按键音效和动画音效由于是个短操作，暂时不提供查询)>>
	*sound_type : 声音种类 铃声、按键音效、动画音效
	*sound_id : 声音标识
	*play    ：TRUE-播放 FALSE-停止播放
	*消息流向 ：mtservice==>sdk
	*see Ev_MT_BLL_CodecGetLocalSoundPlayState_Req
	*/
    MESSAGE(Ev_MT_BLL_CodecGetLocalSoundPlayState_Rsp)
	BODY(mt::TS32, sound_type) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmLocalSoundType
	BODY(mt::TS32, sound_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmLocalSoundIndex
	BODY(mt::TBOOL32, play)

	/*<<设置多画面风格请求>>
	*消息流向 ：sdk==>dispatch==>mtservice
	*see Ev_MT_BLL_CodecSetPIP_Rsp
	*/
    MESSAGE(Ev_MT_BLL_CodecSetPIP_Req)
	BODY(mt::TMtPIPMode, pip_mode)

	/*<<设置多画面风格响应>>
	*消息流向 ：mtservice==>dispatch==>sdk
	*see Ev_MT_BLL_CodecSetPIP_Req
	*/
    MESSAGE(Ev_MT_BLL_CodecSetPIP_Rsp)
	BODY(mt::TMtPIPMode, pip_mode)

	/*<<查询多画面风格请求>>
	*消息流向 ：sdk==>dispatch==>mtservice
	*see Ev_MT_BLL_CodecQueryPIP_Rsp
	*/
    MESSAGE(Ev_MT_BLL_CodecQueryPIP_Req)

	/*<<查询多画面风格响应>>
	*消息流向 ：mtservice==>dispatch==>sdk
	*see Ev_MT_BLL_CodecQueryPIP_Req
	*/
    MESSAGE(Ev_MT_BLL_CodecQueryPIP_Rsp)
	BODY(mt::TMtPIPMode, pip_mode)

	/*<<多画面风格状态通知>>
	*消息流向 ：mtservice==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecPIPState_Ntf)
	BODY(mt::TMtPIPMode, pip_mode)

	/*<<交换画中画命令>>
	*消息流向 ：sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecSwitchPIP_Cmd)

	/*<<色带测试命令>>
	*on ：开启or停止
	*消息流向 ：sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecRibbonTest_Cmd)
	BODY(mt::TBOOL32, on)

	/*<<色带测试状态通知>>
	*on ：是否在色带测试
	*消息流向 ：mtmp==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecRibbonTest_Ntf)
	BODY(mt::TBOOL32, on)		

	/*<<色带测试状态查询请求>>
	*消息流向 ：sdk==>dispatch==>mtmp
	* see Ev_MT_BLL_CodecRibbonTestStatus_Rsp
	*/
    MESSAGE(Ev_MT_BLL_CodecRibbonTestStatus_Req)

	/*<<色带测试状态查询响应>>
	*on ：是否在色带测试
	*消息流向 ：mtmp==>dispatch==>sdk
	* see Ev_MT_BLL_CodecRibbonTestStatus_Req
	*/
    MESSAGE(Ev_MT_BLL_CodecRibbonTestStatus_Rsp)
	BODY(mt::TBOOL32, on)		

	/*<<设置画面合成风格>>
	*vmp_type ：画面合成风格
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VMPSetType_Cmd)
	BODY(mt::TU32, vmp_type)

	/*<<设置发送地址>>
	*send_addr ：设置合成视频的发送地址
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VMPSetSendAddr_Cmd)
	BODY(mt::TNetAddr, send_addr)

	/*<<设置合成视频的编码参数>>
	*vid_enc_param ：编码参数
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VMPSetVidEncParam_Cmd)
	BODY(mt::TVidEncParam, vid_enc_param)

	/*<<开始画面合成>>
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VMPStart_Cmd)

	/*<<停止画面合成>>
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VMPStop_Cmd)

	/*<<添加合成成员>>
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VMPAddMem_Cmd)
	BODY(mt::TMultiVMPMemParam, vmp_memparams)

	/*<<删除合成成员>>
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VMPDelMem_Cmd)
	BODY(mt::TMultiU32, chan_indexs)//（是个repeated）

	/*<<发送关键帧>>
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VMPSendFastUpdate_Cmd)

	/*<<调整编码码率>>
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VMPSetBitrate_Cmd)
	BODY(mt::TU16, bitrate)


	//mixer
	/*<<设置混音深度>>
	*mixer_depth ：混音深度
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_MixerSetDepth_Cmd)
	BODY(mt::TU32, mixer_depth)
	/*<<设置发送地址>>
	*send_addr ：设置合成视频的发送地址
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_MixerSetSendAddr_Cmd)
	BODY(mt::TNetAddr, send_addr)
	/*<<设置混音的编码参数>>
	*vid_enc_param ：编码参数
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_MixerSetVidEncParam_Cmd)
	BODY(mt::TAudEncDecParam, Aud_enc_param)
	/*<<开始混音>>
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_MixerStart_Cmd)

	/*<<停止混音>>
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_MixerStop_Cmd)

	/*<<添加混音成员成员>>
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_MixerAddMem_Cmd)
	BODY(mt::TMultiMixerMemParam, mixer_memparams)

	/*<<删除合成成员>>
	*传输方向：mc->dispatch->mtmp
	* see 
	*/
	MESSAGE(Ev_MT_BLL_MixerDelMem_Cmd)
	BODY(mt::TMultiU32, chan_indexs)//（是个repeated）

	/*<<开启本地自环>>
	*传输方向：mtsdk->mtservice->mtmp
	* see Ev_MT_BLL_LocalLoop_Ntf
	*/
	MESSAGE( Ev_MT_BLL_LocalLoop_Cmd )
	BODY(mt::TBOOL32,   bStart)

	/*<<开启本地自环响应>>
	*传输方向：mtmp->mtservice->mtsdk
	* see Ev_MT_BLL_LocalLoop_Cmd
	*/
	MESSAGE( Ev_MT_BLL_LocalLoop_Ntf)
	BODY(mt::TBOOL32,   bStart)

	/*<<获取本地自环状态请求>>
	*传输方向：mtsdk->mtservice->mtmp
	* see Ev_MT_BLL_GetLocalLoopState_Rsp
	*/
	MESSAGE( Ev_MT_BLL_GetLocalLoopState_Req )

	/*<<获取本地自环状态响应>>
	*传输方向：mtmp->mtservice->mtsdk
	* see Ev_MT_BLL_GetLocalLoopState_Req
	*/
	MESSAGE( Ev_MT_BLL_GetLocalLoopState_Rsp)
	BODY(mt::TBOOL32,   bStart)

	/*<<获取视频 远端自环状态请求>>
	*传输方向：mtsdk->mtservice->mtmp
	* see Ev_MT_BLL_GetRemoteLoopState_Rsp
	*/
	MESSAGE( Ev_MT_BLL_GetRemoteLoopState_Req )

	/*<<获取视频 远端自环状态响应>>
	*传输方向：mtmp->mtservice->mtsdk
	* see Ev_MT_BLL_GetRemoteLoopState_Req
	*/
	MESSAGE( Ev_MT_BLL_GetRemoteLoopState_Rsp)
	BODY(mt::TS32, codec_type)//mt::EmCodecComponent
	BODY(mt::TS32, codec_id)//mt::EmCodecComponentIndex
	BODY(mt::TBOOL32,   bStart)

	/*<<单路编解码器自环>>
	*传输方向：mtsdk->mtservice->mtmp
	* see Ev_MT_BLL_LocalSingleLoop_Ntf
	*/
	MESSAGE( Ev_MT_BLL_LocalSingleLoop_Cmd )
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TBOOL32,   bStart)

	/*<<单路编解码器自环>>
	*传输方向：mtmp->mtservice->mtsdk
	* see Ev_MT_BLL_LocalSingleLoop_Cmd
	*/
	MESSAGE( Ev_MT_BLL_LocalSingleLoop_Ntf)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TBOOL32,   bStart)
	
	/*<<音频自环>>
	*传输方向：mtsdk/mtmfgtest->mtservice
	* see Ev_MT_BLL_AudioLoop_Ntf
	*/
	MESSAGE( Ev_MT_BLL_AudioLoop_Cmd )
	BODY(mt::TBOOL32,   bStart)

	/*<<音频自环状态提示>>
	*传输方向：mtservice->mtsdk/mtmfgtest
	* see Ev_MT_BLL_AudioLoop_Cmd
	*/
	MESSAGE( Ev_MT_BLL_AudioLoop_Ntf)
	BODY(mt::TBOOL32,   bStart)

	/*<<音频输入音量查询请求>>
	*传输方向：mtsdk->mtservice->mtmp
	* see Ev_MT_BLL_MtmpAudioInVolume_Rsp
	*/
	MESSAGE( Ev_MT_BLL_MtmpAudioInVolume_Req )

	/*<<音频输入音量查询响应>>
	*传输方向：mtmp->mtservice->mtsdk
	* see Ev_MT_BLL_MtmpAudioInVolume_Req
	*/
	MESSAGE( Ev_MT_BLL_MtmpAudioInVolume_Rsp)
	BODY(mt::TU8,   byVol)

	/*<<麦克音量查询请求>>
	*传输方向：mtsdk->mtservice->mtmp
	* see Ev_MT_BLL_MtmpMicVolumeDetect_Rsp
	*/
	MESSAGE( Ev_MT_BLL_MtmpMicVolumeDetect_Req )
	BODY(mt::TS32, mic)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmHDAudPortIn

	/*<<麦克音量查询响应>>
	*传输方向：mtmp->mtservice->mtsdk
	* see Ev_MT_BLL_MtmpMicVolumeDetect_Req
	*/
	MESSAGE( Ev_MT_BLL_MtmpMicVolumeDetect_Rsp )
	BODY(mt::TS32, mic)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmHDAudPortIn
	BODY(mt::TU8,   byVol)

	/*<<音频输入接口状态查询请求>>
	*传输方向：mtsdk->mtservice->mtmp
	* see Ev_MT_BLL_MtmpAudioInputState_Rsp
	*/
	MESSAGE( Ev_MT_BLL_MtmpAudioInputState_Req )
	BODY(mt::TMultiAudInputState,   tInput_State)

	/*<<音频输入接口状态查询响应>>
	*传输方向：mtmp->mtservice->mtsdk
	* see Ev_MT_BLL_MtmpAudioInputState_Req
	*/
	MESSAGE( Ev_MT_BLL_MtmpAudioInputState_Rsp )
	BODY(mt::TMultiAudInputState,   tInput_State)

	/*<<音频输出接口状态查询请求>>
	*传输方向：mtsdk->mtservice->mtmp
	* see Ev_MT_BLL_MtmpAudioOutputState_Rsp
	*/
	MESSAGE( Ev_MT_BLL_MtmpAudioOutputState_Req )
	BODY(mt::TMultiAudOutputState,   tOutput_State)

	/*<<音频输出接口状态查询响应>>
	*传输方向：mtmp->mtservice->mtsdk
	* see Ev_MT_BLL_MtmpAudioOutputState_Req
	*/
	MESSAGE( Ev_MT_BLL_MtmpAudioOutputState_Rsp )
	BODY(mt::TMultiAudOutputState,   tOutput_State)

	/*<<视频接口能力查询请求>>
	*传输方向：mtsdk->mtservice
	* see Ev_MT_BLL_MtmpVideoInPortCap_Rsp
	*/
	MESSAGE( Ev_MT_BLL_MtmpVideoInPortCap_Req )

	/*<<视频接口能力查询响应>>
	*传输方向：mtservice->mtsdk
	* see Ev_MT_BLL_MtmpVideoInPortCap_Req
	*/
	MESSAGE( Ev_MT_BLL_MtmpVideoInPortCap_Rsp )
	BODY(mt::TMTHDVidInPortCapList, cap_list)

	/*<<视频接口能力上报>>
	*传输方向：mtservice->mtsdk
	* see Ev_MT_BLL_MtmpVideoInPortCap_Ntf
	*/
	MESSAGE( Ev_MT_BLL_MtmpVideoInPortCap_Ntf )
	BODY(mt::TMTHDVidInPortCapList, cap_list)

	/*<<视频源分辨率查询>>
	*传输方向：mtsdk->mtservice
	* see Ev_MT_BLL_MtmpVidSrcStatus_Rsp
	*/
	MESSAGE( Ev_MT_BLL_MtmpVidSrcStatus_Req )

	/*<<视频源分辨率查询响应>>
	*传输方向：mtservice->mtsdk
	* see Ev_MT_BLL_MtmpVidSrcStatus_Req
	*/
	MESSAGE( Ev_MT_BLL_MtmpVidSrcStatus_Rsp )
	BODY(mt::TMtVidSrcInfoList, src_info_list)

	/*<<视频源分辨率上报>>
	*传输方向：mtservice->mtsdk
	* see 
	*/
	MESSAGE( Ev_MT_BLL_MtmpVidSrcStatus_Ntf )
	BODY(mt::TMtVidSrcInfoList, src_info_list)

	/*<<视频输入接口分辨率查询>>
	*传输方向：mtsdk->mtservice
	* see Ev_MT_BLL_MtmpVidInPortRes_Rsp
	*/
	MESSAGE( Ev_MT_BLL_MtmpVidInPortRes_Req )

	/*<<视频输入接口分辨率查询响应>>
	*传输方向：mtservice->mtsdk
	* see Ev_MT_BLL_MtmpVidInPortRes_Req
	*/
	MESSAGE( Ev_MT_BLL_MtmpVidInPortRes_Rsp )
	BODY(mt::TMtVidInPortResInfoList, src_info_list)

	/*<<视频输入接口分辨率上报>>
	*传输方向：mtservice->mtsdk
	* see 
	*/
	MESSAGE( Ev_MT_BLL_MtmpVidInPortRes_Ntf )
	BODY(mt::TMtVidInPortResInfoList, src_info_list)

	/*<<查询SDI接口数量请求>>
	*传输方向：mtsdk->mtservice
	* see Ev_MT_BLL_MtmpGetSdiInOut_Rsp
	*/
	MESSAGE( Ev_MT_BLL_MtmpGetSdiInOut_Req )

	/*<<查询SDI接口数量响应>>
	*传输方向：mtservice->mtsdk
	* see Ev_MT_BLL_MtmpGetSdiInOut_Req
	*/
	MESSAGE( Ev_MT_BLL_MtmpGetSdiInOut_Rsp )
	BODY(mt::TS32, sdi_inout) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmSdiInOut

	/*<<Fxo呼叫>>
	*传输方向：mtsdk->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_BLL_FxoMakeCall_Cmd )
	BODY(mt::TString, achPeerNumber)

	/*<<Fxo呼叫>>
	*传输方向：mtservice->mtsdk
	* see 
	*/
	MESSAGE( Ev_MT_BLL_FxoMakeCall_Ntf )
	BODY(mt::TString, achPeerNumber)

	/*<<Fxo呼叫进入>>
	*传输方向：mtservice->mtsdk
	* see 
	*/
	MESSAGE( Ev_MT_BLL_FxoCallIncoming_Ntf )
	BODY(mt::TString, achPeerNumber)	//底层暂时获取不到对端号码

	/*<<Fxo 接受呼叫>>
	*传输方向：mtsdk->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_BLL_FxoAccept_Cmd )

	/*<<Fxo 拒绝接听>>
	*传输方向：mtsdk->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_BLL_FxoReject_Cmd )

	/*<<Fxo 挂断电话>>
	*传输方向：mtsdk->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_BLL_FxoHangup_Cmd )

	/*<<Fxo呼叫状态信息上报>>
	*传输方向：mtservice->mtsdk
	* see 
	*/
	MESSAGE( Ev_MT_BLL_FxoCallLinkState_Ntf )
	BODY(mt::TFxoState, tFxo_state)

	/*<<Fxo呼叫错误码上报>>
	*传输方向：mtservice->mtsdk
	* see 
	*/
	MESSAGE( Ev_MT_BLL_FxoCallErrorCode_Ntf )
	BODY(mt::TU32, error_code)	//0:未接电话线

	/*<<拍摄快照请求>>
	*传输方向：mtervice->mtmp
	* see Ev_MT_BLL_CodecSnapshot_Rsp
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshot_Req )
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, coder_id) //拍哪一路的快照。枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<拍摄快照响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_BLL_CodecSnapshot_Req
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshot_Rsp )
	BODY(mt::TU32, snapshot_state) //快照拍摄状态 0：成功 1：其他人正在拍照 2：磁盘空间不足 3:采集不到图像 4: 对端无码流 5:上传到ftp服务器失败
	BODY(mt::TSnapshotFileInfo, file_info) //携带新拍文件的信息

	/*<<新生成快照上报>>
	*传输方向：mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshot_Ntf )
	BODY(mt::TSnapshotFileInfo, file_info) //携带新拍文件的信息

	/*<<查询最近拍摄文件请求>>
	*传输方向： mtsdk->mtservice
	* see Ev_MT_BLL_CodecSnapshotQueryLatestFile_Rsp
	*/ 
	MESSAGE( Ev_MT_BLL_CodecSnapshotQueryLatestFile_Req )

	/*<<查询最近拍摄文件响应>>
	*传输方向：mtservice->mtsdk
	* see Ev_MT_BLL_CodecSnapshotQueryLatestFile_Req
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotQueryLatestFile_Rsp )
	BODY(mt::TU32, result) //查询状态结果 0：成功 1：失败
	BODY(mt::TSnapshotFileInfo, file_info) //携带最新拍摄文件的信息

	/*<<查询快照文件列表信息请求>>
	*传输方向：mtervice->mtmp
	* see Ev_MT_BLL_CodecSnapshotQueryFileList_Rsp
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotQueryFileList_Req )

	/*<<查询快照文件列表信息响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_BLL_CodecSnapshotQueryFileList_Req
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotQueryFileList_Rsp )
	BODY(mt::TS32, report_state) //一条消息上报不完文件列表时携带消息序列号（序列号从1开始计数），当收到最后一条消息时携带-1。只上报一条消息时携带0。
	BODY(mt::TSnapshotFileList, file_info)//文件列表

	/*<<删除一张快照请求>>
	*传输方向：mtervice->mtmp
	* see Ev_MT_BLL_CodecSnapshotDelOneFile_Rsp
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotDelOneFile_Req )
	BODY(mt::TSnapshotFileInfo, file_info) //文件信息

	/*<<删除一张快照响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_BLL_CodecSnapshotDelOneFile_Req
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotDelOneFile_Rsp )
	BODY(mt::TBOOL32, del_state) //是否删除成功
	BODY(mt::TSnapshotFileInfo, file_info)//被删除的文件信息

	/*<<一张快照被删除上报>>
	*传输方向：mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotDelOneFile_Ntf )
	BODY(mt::TSnapshotFileInfo, file_info)//被删除的文件信息

	/*<<重命名一张快照请求>>
	*传输方向：mtervice->mtmp
	* see Ev_MT_BLL_CodecSnapshotRenameOneFile_Req
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotRenameOneFile_Req )
	BODY(mt::TSnapshotFileInfo, file_info_old) //重命名前的文件信息
	BODY(mt::TSnapshotFileInfo, file_info_new) //重命名后的文件信息

	/*<<重命名一张快照响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_BLL_CodecSnapshotRenameOneFile_Rsp
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotRenameOneFile_Rsp )
	BODY(mt::TBOOL32, rename_state) //是否重命名成功
	BODY(mt::TSnapshotFileInfo, file_info_old)//重命名前的文件信息
	BODY(mt::TSnapshotFileInfo, file_info_new)//重命名后的文件信息

	/*<<一张快照被重命名上报>>
	*传输方向：mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotRenameOneFile_Ntf )
	BODY(mt::TSnapshotFileInfo, file_info_old)//重命名前的文件信息
	BODY(mt::TSnapshotFileInfo, file_info_new)//重命名后的文件信息

	/*<<删除所有快照文件请求>>
	*传输方向：mtervice->mtmp
	* see Ev_MT_BLL_CodecSnapshotDelAllFile_Rsp
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotDelAllFile_Req )

	/*<<删除所有快照文件响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_BLL_CodecSnapshotDelAllFile_Req
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotDelAllFile_Rsp )
	BODY(mt::TBOOL32, del_state) //是否删除成功

	/*<<所有快照文件清空通知>>
	*传输方向：mtmp->mtservice
	* see 
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotDelAllFile_Ntf )

	/*<<导出一张快照文件请求>>
	*传输方向：mtervice->mtmp
	* see Ev_MT_BLL_CodecSnapshotExportOneFile_Rsp
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotExportOneFile_Req )
	BODY(mt::TSnapshotFileInfo, file_info) //需要导出的文件信息
    BODY(mt::TString, dst_path)            //需要导出目标文件夹

	/*<<导出一张快照文件响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_BLL_CodecSnapshotExportOneFile_Req
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotExportOneFile_Rsp )
	BODY(mt::TS32, export_state) //导出状态 mt::EmFileCopyErr
	BODY(mt::TSnapshotFileInfo, file_info) //已经导出文件的信息

	/*<<导出所有快照文件请求>>
	*传输方向：mtervice->mtmp
	* see Ev_MT_BLL_CodecSnapshotExportAllFile_Rsp
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotExportAllFile_Req )
    BODY(mt::TString, dst_path)            //需要导出目标文件夹

	/*<<导出所有快照文件响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_BLL_CodecSnapshotExportAllFile_Req
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotExportAllFile_Rsp )
	BODY(mt::TS32, export_state) //导出状态 mt::EmFileCopyErr

	/*<<导出所有快照文件时的停止导出快照的命令>>
	*传输方向：sdk->mtervice
	* see Ev_MT_BLL_CodecStopSnapshotExport_Ntf
	*/
	MESSAGE( Ev_MT_BLL_CodecStopSnapshotExport_Cmd )

	/*<<导出所有快照文件时的停止导出快照的响应>>
	*传输方向：mtservice->sdk
	* see Ev_MT_BLL_CodecStopSnapshotExport_Cmd
	*/
	MESSAGE( Ev_MT_BLL_CodecStopSnapshotExport_Ntf )

    /*<<导出快照进度>>
	*传输方向：mtservice->sdk
	*/
	MESSAGE( Ev_MT_BLL_CodecSnapshotExportProgress_Ntf )
	BODY(mt::TU32, progress) //导出进度(百分比)



    /*<<快照ftp>>
	*传输方向：sdk->mtservice
	*index : 当前操作的预置位索引
	* see Ev_MT_BLL_CodecFtpJpeg_Ntf
	*/
	MESSAGE( Ev_MT_BLL_CodecFtpJpeg_Cmd )
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, coder_id) //拍哪一路的快照。枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<快照ftp>>
	*传输方向：mtservice->sdk
	*index : 当前操作的预置位索引
	* see Ev_MT_BLL_CodecFtpJpeg_Cmd
	*/
	MESSAGE( Ev_MT_BLL_CodecFtpJpeg_Ntf )
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, coder_id) //拍哪一路的快照。枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TBOOL32, is_sucess) //是否拍摄成功


	/*<<导出所有日志文件请求>>
	*传输方向：mtervice->mtmp
	* see Ev_MT_BLL_ExportAllLogFile_Rsp
	*/
	MESSAGE( Ev_MT_BLL_ExportAllLogFile_Req )
    BODY(mt::TString, dst_path)            //需要导出目标文件夹

	/*<<导出所有日志文件响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_BLL_ExportAllLogFile_Req
	*/
	MESSAGE( Ev_MT_BLL_ExportAllLogFile_Rsp )
	BODY(mt::TS32, export_state) //导出状态 mt::EmFileCopyErr

	/*<<导出日志进度>>
	*传输方向：mtservice->sdk
	*/
	MESSAGE( Ev_MT_BLL_AllLogFileExportProgress_Ntf )
	BODY(mt::TU32, progress) //导出进度(百分比)

    /*<<开启监控图片拍摄功能>>
	*传输方向：mtervice->mtmp
	* see Ev_MT_BLL_CodecMonitorPic_Ntf
	*/
    MESSAGE( Ev_MT_BLL_CodecMonitorPic_Cmd )
    BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
    BODY(mt::TS32, coder_id) //拍哪一路的快照。枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TBOOL32, opt)//TRUE开启   FALSE关闭
    BODY(mt::TS32, pic_index)//下一次获取快照的index 0/1

	/*<<开启监控图片拍摄功能响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_BLL_CodecMonitorPic_Cmd
	*/
    MESSAGE( Ev_MT_BLL_CodecMonitorPic_Ntf )
    BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
    BODY(mt::TS32, coder_id) //拍哪一路的快照。枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
    BODY(mt::TBOOL32, status)//TRUE开启   FALSE关闭

    /*<<查询监控图片拍摄功能是否开启>>
	*传输方向：mtervice->mtmp
	* see Ev_MT_BLL_CodecMonitorPicStatus_Rsp
	*/
    MESSAGE( Ev_MT_BLL_CodecMonitorPicStatus_Req )
    BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
    BODY(mt::TS32, coder_id) //拍哪一路的快照。枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<查询监控图片拍摄功能响应>>
	*传输方向：mtmp->mtservice
	* see Ev_MT_BLL_CodecMonitorPicStatus_Req
	*/
    MESSAGE( Ev_MT_BLL_CodecMonitorPicStatus_Rsp )
    BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
    BODY(mt::TS32, coder_id) //拍哪一路的快照。枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TBOOL32, status)//TRUE开启   FALSE关闭

        /*<<图片获取>>
	*传输方向：mtsdk->mtservice
	* see Ev_MT_BLL_CodecPicGet_Rsp
	*/
    MESSAGE( Ev_MT_BLL_CodecPicGet_Req )
    BODY(mt::TS32, index)//获取的监控图片index 0/1

	/*<<图片获取相应>>
	*传输方向：mtservice->mtsdk
	* see Ev_MT_BLL_CodecPicGet_Req
	*/
    MESSAGE( Ev_MT_BLL_CodecPicGet_Rsp )
	BODY(mt::TBOOL32, result)//获取结果


	/*<<本地视频源选看指令>>
	*encoder_id    ：第一路主视频源、第二路主视频源
	*消息流向 ：mtsdk==>dispatch==>service
	* see Ev_MT_BLL_CodecSelectLocalVideoView_Ntf
	*/
    MESSAGE(Ev_MT_BLL_CodecSelectLocalVideoView_Cmd)
	BODY(mt::TS32, encoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCameraView

	/*<<本地视频源选看通知>>
	*encoder_id    ：第一路主视频源、第二路主视频源
	*消息流向 ：service==>dispatch==>mtsdk
	* see Ev_MT_BLL_CodecSelectLocalVideoView_Cmd
	*/
    MESSAGE(Ev_MT_BLL_CodecSelectLocalVideoView_Ntf)
	BODY(mt::TS32, encoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCameraView

	/*<<本地视频源选看内容查询请求>>
	*encoder_id    ：第一路主视频源、第二路主视频源
	*消息流向 ：mtsdk==>dispatch==>service
	* see Ev_MT_BLL_CodecGetLocalVideoView_Rsp
	*/
    MESSAGE(Ev_MT_BLL_CodecGetLocalVideoView_Req)

	/*<<本地视频源选看内容查询响应>>
	*encoder_id    ：第一路主视频源、第二路主视频源
	*消息流向 ：service==>dispatch==>mtsdk
	* see Ev_MT_BLL_CodecGetLocalVideoView_Req
	*/
    MESSAGE(Ev_MT_BLL_CodecGetLocalVideoView_Rsp)
	BODY(mt::TS32, encoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<刷新台标>>
	*pic_file_name    ：新台标图片的文件名
	*消息流向 ：mtsdk==>dispatch==>service
	* see 
	*/
    MESSAGE(Ev_MT_BLL_CodecLabelUpdate_Cmd)
	BODY(mt::TString, pic_file_name)

	/*<<刷新横幅>>
	*pic_file_name    ：新横幅图片的文件名
	*消息流向 ：mtsdk==>dispatch==>service
	* see 
	*/
    MESSAGE(Ev_MT_BLL_CodecBannerUpdate_Cmd)
	BODY(mt::TString, pic_file_name)

	/*<<设置视频亮度、对比度、饱和度>>
	*消息流向 ：mtsdk==>dispatch==>service
	* see Ev_MT_BLL_SetVidImgParam_Ntf
	*/
    MESSAGE(Ev_MT_BLL_SetVidImgParam_Cmd)
	BODY(mt::TS32, codec_type)//该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //该处实际为mt::EmCodecComponentIndex
	BODY(mt::TS32, param_type) //该处实际为mt::EmImgParam
	BODY(mt::TU32, param_value)//参数值

	/*<<设置视频亮度、对比度、饱和度上报>>
	*消息流向 ：service==>dispatch==>mtsdk
	* see Ev_MT_BLL_SetVidImgParam_Cmd
	*/
    MESSAGE(Ev_MT_BLL_SetVidImgParam_Ntf)
	BODY(mt::TS32, codec_type)//该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //该处实际为mt::EmCodecComponentIndex
	BODY(mt::TS32, param_type) //该处实际为mt::EmImgParam
	BODY(mt::TU32, param_value)//参数值

	/*<<查询视频亮度、对比度、饱和度请求>>
	*消息流向 ：mtsdk==>dispatch==>service
	* see Ev_MT_BLL_GetVidImgParam_Rsp
	*/
    MESSAGE(Ev_MT_BLL_GetVidImgParam_Req)
	BODY(mt::TS32, codec_type)//该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //该处实际为mt::EmCodecComponentIndex
	BODY(mt::TS32, param_type) //该处实际为mt::EmImgParam

	/*<<查询视频亮度、对比度、饱和度响应>>
	*消息流向 ：service==>dispatch==>mtsdk
	* see Ev_MT_BLL_GetVidImgParam_Req
	*/
    MESSAGE(Ev_MT_BLL_GetVidImgParam_Rsp)
	BODY(mt::TS32, codec_type)//该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //该处实际为mt::EmCodecComponentIndex
	BODY(mt::TS32, param_type) //该处实际为mt::EmImgParam
	BODY(mt::TU32, param_value)//参数值


    /*<<开启、关闭OSD穿透请求>>
	*消息流向 ：mtsdk==>dispatch==>service
	* see Ev_MT_BLL_SetOsdTransparent_Rsp
	*/
    MESSAGE(Ev_MT_BLL_SetOsdTransparent_Req)
	BODY(mt::TBOOL32, trans)

	/*<<开启、关闭OSD穿透响应>>
	*消息流向 ：service==>dispatch==>mtsdk
	* see Ev_MT_BLL_SetOsdTransparent_Req
	*/
    MESSAGE(Ev_MT_BLL_SetOsdTransparent_Rsp)
    BODY(mt::TBOOL32, trans)
    BODY(mt::TS32, result)


    /*<<OSD界面是否在浏览快照>>
	*消息流向 ：mtsdk==>dispatch==>service
	* see Ev_MT_BLL_OsdSnapshotBrowse_Ntf
	*/
    MESSAGE(Ev_MT_BLL_OsdSnapshotBrowse_Cmd)
	BODY(mt::TBOOL32, browsing)

	/*<<OSD界面是否在浏览快照通知>>
	*消息流向 ：service==>dispatch==>mtsdk
	* see Ev_MT_BLL_OsdSnapshotBrowse_Cmd
	*/
    MESSAGE(Ev_MT_BLL_OsdSnapshotBrowse_Ntf)
    BODY(mt::TBOOL32, browsing)



	/*<<获取码流对应的预置位请求>>
	*消息流向 ：mtsdk==>dispatch==>service
	* see Ev_MT_BLL_CurPresetIndex_Rsp
	*/
    MESSAGE(Ev_MT_BLL_GetCurCodecPresetIndex_Req)
	BODY(mt::EmCodecComponentIndex, codec_index)

	/*<<码流对应的预置位回复>>
	*消息流向 ：service==>dispatch==>mtsdk
	* see Ev_MT_BLL_GetCurPresetIndex_Req
	*/
    MESSAGE(Ev_MT_BLL_CurCodecPresetIndex_Rsp)
	BODY(mt::EmCodecComponentIndex, codec_index)
    BODY(mt::TU32, pre_set_index)

	/*<< 自动声音时延检测命令 >>
	*[消息体]
	*    + start: 开始或停止
	*[消息方向]
	*    mtsdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_AutoAudioDelayCheckCmd)
	BODY(mt::TBOOL32, start)

	/*<< 自动声音时延检测通知 >>
	*[消息体]
	*    + state(EmAudioDelayCheckState)：检测状态
	*    + result：当EmAudioDelayCheckState为emAudioDelayChecked时，此值有效，表示时延值
	*             当EmAudioDelayCheckState为emAudioDelayFailed时，此值有效，表示失败错误码
	*[消息方向]
	*    mtservice==>dispatch==>mtsdk
	*/
	MESSAGE(Ev_MT_BLL_AutoAudioDelayCheckNtf)
	BODY(mt::TU32, state)
	BODY(mt::TU32, result)

    /*<开启或关闭OSD快照通知>
    *传输方向：mtservice->sdk
    *see Ev_MT_BLL_CodecOsdSnapshot_Cmd
    */
    MESSAGE(Ev_MT_BLL_CodecOsdSnapShotOpen_Ntf)
    BODY(mt::TBOOL32, opt)  // TRUE打开 FLASE关闭

    /*<OSD快照命令>
    *传输方向：sdk->mtservice
    *
    */
    MESSAGE(Ev_MT_BLL_CodecOsdSnapshot_Cmd)

	/*<摄像机列表上报>
    *传输方向：mtservice->sdk
    *
    */
	MESSAGE(Ev_MT_BLL_HD_GetCameraListCfg_Ntf)
    BODY(mt::TMTHDCameraList, opt)  


	/*<设置是否显示osd>
    *传输方向：sdk->mtservice
    *
    */
    MESSAGE(Ev_MT_BLL_CodecSetShowOsd_Cmd)
	BODY(mt::TBOOL32, bShow)  // TRUE打开 FLASE关闭

	/*<通知是否显示osd>
    *传输方向：sdk->mtservice
    *
    */
    MESSAGE(Ev_MT_BLL_CodecIsShowOsd_Ntf)
	BODY(mt::TBOOL32, bShow)  // TRUE打开 FLASE关闭


	/*<开始本地录像命令>
	*传输方向：sdk->mtservice
	*
	*/
	MESSAGE(EV_MT_BLL_Record_Start_Cmd)
	BODY(mt::TString, tPathName)  // 保存录像文件名

	/*<开始本地录像回复>
	*传输方向：mtservice->sdk
	*
	*/
	MESSAGE(EV_MT_BLL_Record_Start_Ntf)
	BODY(mt::TBOOL32, bSuccess)  // 开始录像成功或失败


	/*<停止本地录像命令>
	*传输方向：sdk->mtservice
	*
	*/
	MESSAGE(EV_MT_BLL_Record_Stop_Cmd)

	/*<停止本地录像回复>
	*传输方向：mtservice->sdk
	*
	*/
	MESSAGE(EV_MT_BLL_Record_Stop_Ntf)
	BODY(mt::TBOOL32, bSuccess)  // 停止录像成功或失败


	/*<暂停录像命令>
	*传输方向：sdk->mtservice
	*
	*/
	MESSAGE(EV_MT_BLL_Record_Pause_Cmd)

	/*<暂停本地录像回复>
	*传输方向：mtservice->sdk
	*
	*/
	MESSAGE(EV_MT_BLL_Record_Pause_Ntf)
	BODY(mt::TBOOL32, bSuccess)  // 暂停录像成功或失败


	/*<继续本地录像命令>
	*传输方向：sdk->mtservice
	*
	*/
	MESSAGE(EV_MT_BLL_Record_Continue_Cmd)

	/*<继续本地录像回复>
	*传输方向：mtservice->sdk
	*
	*/
	MESSAGE(EV_MT_BLL_Record_Continue_Ntf)
	BODY(mt::TBOOL32, bSuccess)  // 继续录像成功或失败

	
	/*<剩余录像时间回复>
    *传输方向：mtservice -> sdk
    */
    MESSAGE(EV_MT_BLL_Record_RemainTime_Ntf)	
	BODY(mt::TU32, dwRemainTime )  //剩余秒数

	/*<录像过程中的状态通知>
    *传输方向：mtservice -> sdk
    */
	MESSAGE(EV_MT_BLL_Record_Status_Ntf)
	BODY(mt::TU32, dwChanIndex)  // 通道号
	BODY(mt::TU32, dwValue)		// 录像的状态, 对应 EmVideoRecordErrorNum_Api 

	/*<获取本地录像状态的请求>
    *传输方向：sdk -> mtservice
    */
	MESSAGE(EV_MT_BLL_Record_Status_Req)

	/*<获取本地录像状态的回复>
    *传输方向： mtservice -> sdk
    */
	MESSAGE(EV_MT_BLL_Record_Status_Rsp)
	BODY(mt::TU32, dwSpaceSzie)  

	/*<获取本地录像开始时间的命令>
    *传输方向：sdk -> mtservice
    */
	MESSAGE(EV_MT_BLL_Record_Start_time_Cmd)

	/*<获取本地录像开始时间的通知>
    *传输方向：mtservice -> sdk
    */
	MESSAGE(EV_MT_BLL_Record_Start_time_Ntf)
	BODY(mt::TMTTime, tStartTime)  

    /*<<获取辅视频源是否有源请求>>
	*传输方向：mtservice_hd->mtmp
	* see Ev_MT_AssVideoPortStatus_Rsp
	*/
	MESSAGE( Ev_MT_BLL_AssVideoPortStatus_Req )

	/*<<获取辅视频源是否有源响应>>
	*传输方向：mtmp->mtservice_hd
	* see Ev_MT_AssVideoPortStatus_Req
	*/
	MESSAGE( Ev_MT_BLL_AssVideoPortStatus_Rsp )
	BODY(mt::TS32, vga_state) //Vga是否插入1:插入 0:未插入
    BODY(mt::TS32, hdmi_state) //Hdmi是否插入1:插入 0:未插入

    /*<<开启OSD>>
	*传输方向：mtservice_hd->mtmp
	* see 
	*/
	MESSAGE( Ev_MT_BLL_CodecSetOsdOpen_Cmd )

    /*<<开启OSD>>
	*传输方向：mtmp->mtservice_hd
	* see 
	*/
	MESSAGE( Ev_MT_BLL_CodecSetOsdOpen_Ntf )
    BODY(mt::TBOOL32, bSuccess)

	/*<<关闭OSD>>
	*传输方向：mtservice_hd->mtmp
	* see 
	*/
	MESSAGE( Ev_MT_BLL_CodecSetOsdClose_Cmd )

    /*<<关闭OSD>>
	*传输方向：mtmp->mtservice_hd
	* see 
	*/
	MESSAGE( Ev_MT_BLL_CodecSetOsdClose_Ntf )
    BODY(mt::TBOOL32, bSuccess)

    /*<<双屏模式收双流下第二屏是否显示远端辅流开关>>
	*消息流向 ：mtservice_hd==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_ShowRemoteAssVideo_Cmd)
	BODY(mt::TBOOL32, showRemoteAssVideo)

    /*<硬件芯片获取请求>
    *传输方向：mtservice=>dispatch=>mtmpapp
    */
    MESSAGE(EV_MT_BLL_HwChipInfoInquire_Req)

	/*<硬件芯片获取请求回复>
    *传输方向：mtmpapp=>dispatch=>mtservice
    */
    MESSAGE(EV_MT_BLL_HwChipInfoInquire_Rsp)		
	BODY( mt::TMtHwChipInfoList, hwchipinfolist )

	/*<硬件芯片获取响应>
    *传输方向 mtmpapp=>dispatch=>mtservice
    */
    MESSAGE(EV_MT_BLL_HwChipInfoInquire_Ntf)		
	BODY( mt::TMtHwChipInfoList, hwchipinfolist )
	
	/*<本地辅流扩声获取请求>
    *传输方向：sdk=>dispatch=>mtservice
    */
    MESSAGE(EV_MT_BLL_GetSubAudExpansion_Req)

	/*<本地辅流扩声获取请求回复>
    *传输方向：mtservice=>dispatch=>sdk
    */
    MESSAGE(EV_MT_BLL_GetSubAudExpansion_Rsp)		
	BODY( mt::TBOOL32, bSubAudExpansion )
	
	/*<本地辅流扩声设置>
    *传输方向 sdk=>dispatch=>mtservice
    */
    MESSAGE(EV_MT_BLL_SetSubAudExpansion_Cmd)		
	BODY( mt::TBOOL32, bSubAudExpansion )

	/*<本地辅流扩声设置响应>
    *传输方向 mtservice=>dispatch=>sdk
    */
    MESSAGE(EV_MT_BLL_SetSubAudExpansion_Ntf)		
	BODY( mt::TBOOL32, bSubAudExpansion )
	BODY( mt::TU32, result )

	/*<<获取音频 远端自环状态请求>>
	*传输方向：mtsdk->mtservice->mtmp
	* see Ev_MT_BLL_GetAudRmtLoopState_Rsp
	*/
	MESSAGE( Ev_MT_BLL_GetAudRmtLoopState_Req )

	/*<<获取音频 远端自环状态响应>>
	*传输方向：mtmp->mtservice->mtsdk
	* see Ev_MT_BLL_GetAudRmtLoopState_Req
	*/
	MESSAGE( Ev_MT_BLL_GetAudRmtLoopState_Rsp)
	BODY(mt::TS32, codec_type)//mt::EmCodecComponent
	BODY(mt::TS32, codec_id)//mt::EmCodecComponentIndex
	BODY(mt::TBOOL32,   bStart)

    /*<<<码流通知界面>>
    * 消息流向 ：mtservice==>dispatch==>mtsdk
    */
    MESSAGE(Ev_MT_BLL_VidStreamAppear_Ntf)
    BODY(mt::TS32, type) //这个值用于确认是回调收到码流时候上报还是其他时候上报



    /*<<设置Isp参数>>
    *消息流向 ：mtsdk==>dispatch==>service
    * see Ev_MT_BLL_SetIspParam_Ntf
    */
    MESSAGE(Ev_MT_BLL_SetIspParam_Cmd)
    BODY(mt::TS32, codec_type)//该处实际为mt::EmCodecComponent
    BODY(mt::TS32, codec_id) //该处实际为mt::EmCodecComponentIndex
    BODY(mt::TS32, param_type) //该处实际为mt::EmIspImgInf
    BODY(mt::TU32, param_value)//参数值

    /*<<设置Isp参数>>
    *消息流向 ：service==>dispatch==>mtsdk
    * see Ev_MT_BLL_SetIspParam_Cmd
    */
    MESSAGE(Ev_MT_BLL_SetIspParam_Ntf)
    BODY(mt::TS32, codec_type)//该处实际为mt::EmCodecComponent
    BODY(mt::TS32, codec_id) //该处实际为mt::EmCodecComponentIndex
    BODY(mt::TS32, param_type) //该处实际为mt::EmIspImgInf
    BODY(mt::TU32, param_value)//参数值

    /*<<查询Isp参数>>
    *消息流向 ：mtsdk==>dispatch==>service
    * see Ev_MT_BLL_GetIspParam_Rsp
    */
    MESSAGE(Ev_MT_BLL_GetIspParam_Req)
    BODY(mt::TS32, codec_type)//该处实际为mt::EmCodecComponent
    BODY(mt::TS32, codec_id) //该处实际为mt::EmCodecComponentIndex
    BODY(mt::TS32, param_type) //该处实际为mt::EmIspImgInf

    /*<<查询Isp参数>>
    *消息流向 ：service==>dispatch==>mtsdk
    * see Ev_MT_BLL_GetIspParam_Req
    */
    MESSAGE(Ev_MT_BLL_GetIspParam_Rsp)
    BODY(mt::TS32, codec_type)//该处实际为mt::EmCodecComponent
    BODY(mt::TS32, codec_id) //该处实际为mt::EmCodecComponentIndex
    BODY(mt::TS32, param_type) //该处实际为mt::EmIspImgInf
    BODY(mt::TU32, param_value)//参数值

	/*<<音频文件播放命令>>
	*传输方向：mtai->mtmp
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