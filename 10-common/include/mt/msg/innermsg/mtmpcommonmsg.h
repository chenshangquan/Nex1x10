#ifndef _MTMPCOMMONMSG_H_
#define _MTMPCOMMONMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMPCommonMsg
{
    EV_BGN(MPCOMMON) = EVSEG_MPCOMMON_BGN,
#endif

	/*<<发送关键帧命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*消息流向 ：service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecFastUpdate_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<视频解码器需要关键帧通知>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*消息流向 ：mtmp==>dispatch==>service
	*/
	MESSAGE(Ev_MT_CodecNeedKeyFrame_Ntf)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, decoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<设置编码码率>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*bitrate    ：码率
	*消息流向 ：service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecSetBitrate_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TU16, bitrate)

	/*<<调整编码分辨率>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*width      ：宽
	*height     ：高
	*消息流向 ：service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecSetEncRes_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TU16, width)
	BODY(mt::TU16, height)

	/*<<调整编码帧率>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*fps        ：帧率
	*消息流向 ：service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecSetEncFps_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TU8, fps)

	/*<<设置编码器地址参数>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*rtp_local_addr   ：发送rtp包的本地地址
	*rtcp_local_addr  ：发送接收rtcp包的本地地址
	*rtp_remote_addr  ：发送rtp包的远端目的地址
	*rtcp_remote_addr ：发送rtcp包的远端目的地址
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetChanSndAddr_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TNetAddr, rtp_local_addr)
	BODY(mt::TNetAddr, rtcp_local_addr)
	BODY(mt::TNetAddr, rtp_remote_addr)
	BODY(mt::TNetAddr, rtcp_remote_addr)	//

	/*<<设置解码器地址参数>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*rtp_local_addr   ：接收rtp包的本地地址
	*rtcp_local_addr  ：接收rtcp包的本地地址
	*rtp_remote_addr  ：发送打动包的远端地址，端口为0表示不发送打动包，否则发送打动包
	*rtcp_remote_addr ：发送rtcp包的远端目的地址，也即解码器的backrtcp地址
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetChanRcvAddr_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, decoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex	
	BODY(mt::TNetAddr, rtp_local_addr)
	BODY(mt::TNetAddr, rtcp_local_addr)
	BODY(mt::TNetAddr, rtp_remote_addr)//
	BODY(mt::TNetAddr, rtcp_remote_addr)

	/*<<设置丢包重传参数>>
	*prs_param ：丢包重传参数
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetPrsParam_Cmd)
	BODY(mt::TPrsParam, prs_param)

	/*<<设置平滑发送>>
	*enable_smooth_send ：是否启用平滑发送
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetSmoothSend_Cmd)
	BODY(mt::TBOOL32, enable_smooth_send)	

	/*<<设置动态载荷>> 应用在发送
	*codec_type  ：码流类型
	*encoder_id  ：码流索引
	*payload_map ：动态载荷映射
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetDynamicPayload_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TDynamicPayload, payload_map) //动态载荷映射


	/*<<设置动态载荷>> 应用在接收
	*codec_type  ：码流类型
	*encoder_id  ：码流索引
	*payload_map_list：动态载荷映射list
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetRecvDynamicPayload_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TRpDynamicPayload, payload_map_list) //动态载荷映射list



	/*<<设置最大接收延迟及播放策略>>
	*codec_type		：码流类型
	*encoder_id		：码流索引
	*ucPolicy		：播放策略
	*dwSoftlimit    ：软上限
	*dwHardlimit    ：硬上限
	
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetMaxDelay_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TU32, ucPolicy) ////播放策略
	/*
	0 UNKNOWN 
	1 QUALITY 
	2 QUALITY_NOAVS
	3 SPEED
	4 BALANCE 
	*/
	BODY(mt::TS32, dwSoftlimit)
	BODY(mt::TS32, dwHardlimit)


	/*<<设置秘钥>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*key        ：秘钥
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetEncryptKey_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TEncryptKey, key)

	/*<<设置视频编码参数>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*vid_enc_param ：视频编码参数
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetVidEncParam_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TVidEncParam, vid_enc_param)

	/*<<设置视频解码器丢包恢复策略命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*lost_pack_strategy ：丢包恢复策略
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetVidDecLostPackStrategy_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, decoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TS32, lost_pack_strategy) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmLostPackStrategy	
	BODY(mt::TBOOL32, is_rtcp_sendfastupdate) ///是否用rtcp发送关键帧请求

	/*<<设置音频编码参数命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*aud_enc_param ：音频编码参数
	*消息流向 ：service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecSetAudEncParam_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TAudEncDecParam, aud_enc_param)

	/*<<设置音频解码参数命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*aud_dec_param ：音频解码参数
	*消息流向 ：service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecSetAudDecParam_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TAudEncDecParam, aud_dec_param)

	/*<<开始工作命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecChanStart_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<停止工作命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecChanStop_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<开始解码接收某一路VOD流命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecVodStreamStart_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<切换VOD点播源命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*消息流向 ：mtvod==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecVodSwitchStream_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<停止解码接收某一路VOD流命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecVodStreamStop_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<开始流媒体组播命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*rtp_snd_addr  ：rtp发送地址
	*rtcp_snd_addr ：rtcp发送地址
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecStreamMediaStart_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TNetAddr, rtp_snd_addr)
	BODY(mt::TNetAddr, rtcp_snd_addr)

	/*<<停止流媒体组播命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecStreamMediaStop_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<开始某一路监控命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*monitor_addr  ：监控接收地址
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecMonitorStart_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TRtpRtcpPair, monitor_addr)

	/*<<停止某一路监控命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*monitor_addr  ：监控接收地址,唯一确定某一路监控
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecMonitorStop_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TRtpRtcpPair, monitor_addr)

	
	/*<<显示所有的转发的转发列表>>
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecMonitorShowList_Cmd)


	/*<<开始某一路录像命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*record_addr   ：录像接收地址
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecRecordStart_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TRtpRtcpPair, record_addr)

	/*<<停止某一路录像命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*record_addr : 录像接收地址,唯一确定某一路录像
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecRecordStop_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TRtpRtcpPair, record_addr)

	/*<<获取监控参数命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecGetMonitorParam_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<监控参数通知>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*media_type    ：媒体类型
	*media_pt      ：动态载荷
	*key           ：秘钥
	*g7221_reverse ：g7221是否翻转
	*aac_chan_num  ：aac声道数
	*aac_sf        ：aac采样率
	*tMonitorLocalRtpPort:本地rtp端口号
	*tMonitorLocalRtcpPort:本地rtcp端口号
	*消息流向 ：mtmp==>dispatch==>service
	*/
    MESSAGE(Ev_MT_CodecMonitorParam_Ntf)	
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TU8, media_type)
	BODY(mt::TRpDynamicPayload, media_pt)
	BODY(mt::TEncryptKey, key)
	BODY(mt::TBOOL32, g7221_reverse)
	BODY(mt::EmAacChnlNum, aac_chan_num)
	BODY(mt::EmAacSampFreq, aac_sf)
	BODY(mt::TU32, tMonitorLocalRtpPort)
	BODY(mt::TU32, tMonitorLocalRtcpPort)

	/*<<监控要求关键帧命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecMonitorFastUpdate_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<看本地命令>>
	*decoder_id   ：解码器id，标识第几路解码器看本地
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecViewLocal_Cmd)
	BODY(mt::TS32, decoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<看远端命令>>
	decoder_id   ：解码器id，标识第几路解码器看远端
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecViewOther_Cmd)
	BODY(mt::TS32, decoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<g7221字节序翻转命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*on ：TRUE-翻转 FALSE-不翻转
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetReverseG7221_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TBOOL32, on)

	/*<<5秒内丢包通知>>
	*lost ：TRUE-丢包 FALSE-不丢包
	*消息流向 ：mtmp==>dispatch==>service
	*/
    MESSAGE(Ev_MT_CodecLostPack_Ntf)
	BODY(mt::TBOOL32, lost)	

	/*<<静音命令>>	
	*on ：开始or取消静音
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecQuiet_Cmd)
	BODY(mt::TBOOL32, on)

	/*<<哑音命令>>
	*on ：开始or取消哑音
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecMute_Cmd)
	BODY(mt::TBOOL32, on)

	/*<<设置Ans启用命令>>
	*enable  ：是否启用
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecANS_Cmd)
	BODY(mt::TBOOL32, enable)
	
	/*<<设置AEC启用命令>>
	*enable  ：是否启用
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecAec_Cmd)
	BODY(mt::TBOOL32, enable)

	/*<<设置AGC启用命令>>
	*enable  ：是否启用
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecAgc_Cmd)
	BODY(mt::TBOOL32, enable)

	/*<<设置AEC微调参数命令>>
	*auto  ：是否自适应
	*value ：微调值
	*消息流向 ：sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetAECParam_Cmd)
	BODY(mt::TBOOL32, auto)
	BODY(mt::TU32, value)

	/*<<设置音质优先命令>>
	*level ：音质优先等级(0关闭音质优先，非0启用音质优先)
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetAudPrecedence_Cmd)
	BODY(mt::TU8, level)

	/*<<获取音频输出功率命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*start  : TRUE表示启动，FALSE表示停止
	*消息流向 ：service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecGetAudOutPower_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TBOOL32, start)

	/*<<音频输出功率通知>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*消息流向 ：mtmp==>dispatch==>service
	*/
	MESSAGE(Ev_MT_CodecAudOutPower_Ntf)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TU32, power)

	/*<<获取音频输入功率命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*start  : TRUE表示启动，FALSE表示停止
	*消息流向 ：service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecGetAudInPower_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TBOOL32, start)

	/*<<音频输入功率通知>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*power  ：音频输入功率
	*消息流向 ：mtmp==>dispatch==>service
	*/
	MESSAGE(Ev_MT_CodecAudInPower_Ntf)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TU32, power)

	/*<<设置音频输入音量命令>>
	*vol : 音量
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetAudInVol_Cmd)
	BODY(mt::TU32, vol)

	/*<<设置音频输出音量命令>>
	*vol : 音量
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetAudOutVol_Cmd)
	BODY(mt::TU32, vol)

	/*<<获取音频输出音量请求>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*消息流向 ：service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecGetAudOutVol_Req)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<获取音频输出音量响应>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*vol    : 音量
	*消息流向 ：mtmp==>dispatch==>service
	*/
	MESSAGE(Ev_MT_CodecGetAudOutVol_Rsp)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TU32, vol)

	/*<<设置解码器组播接收地址命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*ip         ：组播地址IP
	*port       ：组播地址端口
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetMultiCastAddr_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TU32, ip)
	BODY(mt::TU16, port)

	/*<<控制第一个主视频编码器发送静态图片命令>>
	*static_pic_cfg : 发送静态图片信息
	*消息流向 ：service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecSndStaticPic_Cmd)	
	BODY(mt::TStaticPicCfg, static_pic_cfg)

	/*<<控制第一个主视频编码器开始采集命令>>
	*enable : TRUE开始采集，FALSE停止采集
	*消息流向 ：service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecStartVidCap_Cmd)
	BODY(mt::TBOOL32, enable)

	/*<<台标加入码流>> (仅win32)
	*enable : 是否加入码流
	*logo_param : 台标参数
	*消息流向 ：service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecSetAddLogoIntoEncStream_Cmd)	
	BODY(mt::TBOOL32, enable)
	BODY(mt::TMtFullLogoParam, logo_param)


	/*<<设置发送包标记，支持平台端口复用>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*e164_param        ：e164号
	*stream_id         ：码流唯一标识
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetStreamID_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TString, e164_param)//e164号
	BODY(mt::TU32, stream_id)//码流唯一标识

	/*<<是否nat穿越设置>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*is_nattraversal   ：是否nat穿越
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecIsNatTraversal_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TBOOL32, is_nattraversal)//是否nat穿越
	BODY(mt::TNetAddr, rtp_local_addr)
	BODY(mt::TNetAddr, rtcp_local_addr)
	BODY(mt::TNetAddr, rtp_remote_addr)
	BODY(mt::TNetAddr, rtcp_remote_addr)

	/*<<获取当前带宽检测的状态值>>
	*消息流向 ：service==>dispatch==>mtmp
	*/
	MESSAGE( Ev_MT_CodecGetBweStatus_Cmd)
	
	/*<<获取当前带宽检测的状态值>>
	*bwe_status 带宽检测的值
	*消息流向 ：mtmp==>dispatch==>mtservice
	*/
	MESSAGE( Ev_MT_CodecBweStatus_Ntf)
	BODY(mt::TCodecBweStatus,  bwe_status)

	/*<<设置qos>>
	*tQos   Qos值
	*消息流向 ：mtservice==>dispatch==>mtmp
	*/
	MESSAGE( Ev_MT_CodecSetQos_Cmd )      
	BODY(mt::TMTIPQoS,  tQos)

	/*<<设置 是否剥掉RTP扩展头>>
	*   tEnable: 是否剥掉
	*消息流向 ：mtservice==>dispatch==>mtmp
	*/
	MESSAGE( Ev_MT_CodecSetBEnableRtpExStrip_Cmd )      
	BODY(mt::TBOOL32,  tEnable)

	/*<<设置 发送rtcp 包方式>>
	tStatus值如下：
	*                      RTCP_OFF          = 0, 不启用RTCP
	*					   RTCP_COMPOUND     = 1, 发送RTCP复合包
	*					   RTCP_NONCOMPOUND  = 2, 不发送RTCP复合包
	*消息流向 ：mtservice==>dispatch==>mtmp
	*/
	MESSAGE( Ev_MT_CodecSetRtcpStatus_Cmd )
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TU32,  tStatus)



	/*<<设置解码回调函数开关>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*start  : TRUE表示启动，FALSE表示停止
	*消息流向 ：service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecSetDecFrameCallBack_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TBOOL32, start)



	/*<<主流视频源变化通知>>
	*video_ignal  ：TRUE表示有信号，FALSE表示无信号
	*消息流向 ：mtmp==>dispatch==>service
	*/
	MESSAGE(Ev_MT_CodecVideoSignal_Ntf)
	BODY(mt::TBOOL32, video_ignal)

	/*<<当前辅流状态>>
	* mt_assstream_status ：当前辅流的状态
	* 消息流向 ：conf==>dispatch==>mtmp
	*/
	MESSAGE( Ev_MT_Codec_AssSndSream_Status_Ntf )             //
	BODY(mt::TS32, chan_state) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmMtChanState


	/*<<主流是否不支持720P> （仅手机TT）
	* mt_assstream_status ：
	* 消息流向 ：conf==>dispatch==>mtmp

	*/
	MESSAGE( Ev_MT_Codec_ReducePriomVideoEncRes_Ntf )             
	BODY(mt::TBOOL32, cpu_ability) //

		/*<<远端自环状态指示>> 
	* emCodeType: codec 类型
	* emCodeIdx:  codec 索引
	* bResult ： 开启/关闭
	* 消息流向 ：conf==>dispatch==>mtmp
	*/
	MESSAGE( Ev_MT_Codec_RemoteLoop_Ntf )
	BODY( mt::TU32,    emCodeType)
	BODY( mt::TU32,    emCodeIdx)
	BODY( mt::TBOOL32, bResult)

	/*<<设置是否开启fec>> 
	* bSnd:      是否是发送通道，对应所有的发送/接收通道
	* benable ： 开启/关闭
	* 消息流向 ：conf==>dispatch==>mtmp
	*/
	MESSAGE( Ev_MT_Codec_EnableFec )
	BODY( mt::TBOOL32,  bSnd )
	BODY( mt::TBOOL32,  benable )

		
	/*<<台标加入码流>> (仅Mobil)
	*enable : 是否加入码流
	*RpLogo_param : 台标参数
	*消息流向 ：service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecSetAddMobilLogoIntoEncStream_Cmd)	
	BODY(mt::TBOOL32, enable)
	BODY(mt::TRpMtFullLogoParam, RpLogo_param)

	/*<<终端多流开关>> (仅EMBED)
	*enable : TRUE:开启，FALSE:关闭
	*消息流向 ：service==>dispatch==>mtmp
    *这条消息用于通知x700交换主二跟辅解码器的通知，开启则交换
	*/
	MESSAGE(Ev_MT_BLL_CodecStartMultiStream_Ntf)	
	BODY(mt::TBOOL32, enable)
	
	/*<<设置srtp秘钥>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*key        ：秘钥
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_CodecSetSrtpCrypto_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TSrtpCrypto, tMtSrtpParam)

	////设置网络tos值
	MESSAGE(Ev_MT_CodecTos_Cmd )
	BODY(mt::TU8,   byAud)
	BODY(mt::TU8,   byVid)
	
	/*<<投屏状态通知>>
	*/
	MESSAGE(Ev_MT_MtQkState_Ntf)
	BODY(mt::TMtQkState , state)  // 单个投屏器状态
	


#if !defined(_MESSAGE_HELP_)
    EV_END(MPCOMMON) = EVSEG_MPCOMMON_END
};
#endif

#define Is_MPCommon_Msg(m) ((m) >= Ev_MT_BGN(MPCOMMON) && (m) <= Ev_MT_END(MPCOMMON))

#endif // _MTMPCOMMONMSG_H_