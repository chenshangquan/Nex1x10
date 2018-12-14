#ifndef _MTBLLMPCOMMONMSG_H_
#define _MTBLLMPCOMMONMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMPCommonMsg
{
    EV_BLL_BGN(MPCOMMON) = EVSEG_BLL_MPCOMMON_BGN,
#endif

	/*<<开始解码接收某一路VOD流命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*消息流向 ：vod==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecVodStreamStart_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<停止解码接收某一路VOD流命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*消息流向 ：vod==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecVodStreamStop_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<开始流媒体组播命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*rtp_snd_addr  ：rtp发送地址
	*rtcp_snd_addr ：rtcp发送地址
	*消息流向 ：sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecStreamMediaStart_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TNetAddr, rtp_snd_addr)
	BODY(mt::TNetAddr, rtcp_snd_addr)

	/*<<停止流媒体组播命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*消息流向 ：sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecStreamMediaStop_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<开始某一路监控命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*monitor_addr  ：监控接收地址
	*消息流向 ：sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecMonitorStart_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TRtpRtcpPair, monitor_addr)

	/*<<停止某一路监控命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*monitor_addr  ：监控接收地址,唯一确定某一路监控
	*消息流向 ：sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecMonitorStop_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TRtpRtcpPair, monitor_addr)

	/*<<开始某一路录像命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*record_addr   ：录像接收地址
	*消息流向 ：sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecRecordStart_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TRtpRtcpPair, record_addr)

	/*<<停止某一路录像命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*record_addr : 录像接收地址,唯一确定某一路录像
	*消息流向 ：sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecRecordStop_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TRtpRtcpPair, record_addr)

	/*<<获取监控参数命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*消息流向 ：sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecGetMonitorParam_Cmd)
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
	*tMonitorLocalRtpPort:	本地rtp端口号
	*tMonitorLocalRtcpPort:	本地rtcp端口号
	*消息流向 ：mtmp==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecMonitorParam_Ntf)	
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
	*消息流向 ：sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecMonitorFastUpdate_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<5秒内丢包通知>>
	*lost ：TRUE-丢包 FALSE-不丢包
	*消息流向 ：mtmp==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecLostPack_Ntf)
	BODY(mt::TBOOL32, lost)	

	/*<<静音命令>>	
	*on ：开始or取消静音
	*消息流向 ：sdk/conf==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecQuiet_Cmd)
	BODY(mt::TBOOL32, on)

	/*<<静音状态通知>>
	*on ：静音状态
	*消息流向 ：mtmp==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecQuiet_Ntf)
	BODY(mt::TBOOL32, on)

	/*<<哑音命令>>
	*on ：开始or取消哑音
	*消息流向 ：sdk/conf==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecMute_Cmd)
	BODY(mt::TBOOL32, on)

	/*<<哑音状态通知>>
	*on ：哑音状态
	*消息流向 ：mtmp==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecMute_Ntf)
	BODY(mt::TBOOL32, on)

	/*<<静音状态通知>>
	*on ：静音状态
	*消息流向 ：mtservice==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecQuiet_Rsp)
	BODY(mt::TBOOL32, on)

	/*<<哑音状态通知>>
	*on ：哑音状态
	*消息流向 ：mtservice==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecMute_Rsp)
	BODY(mt::TBOOL32, on)

	/*<<设置AEC微调参数命令>>
	*auto  ：是否自适应
	*value ：微调值
	*消息流向 ：sdk==>dispatch==>mtmp
	*/
    MESSAGE(Ev_MT_BLL_CodecSetAECParam_Cmd)
	BODY(mt::TBOOL32, auto)
	BODY(mt::TU32, value)

	/*<<AEC微调参数通知>>
	*auto  ：是否自适应
	*value ：微调值
	*消息流向 ：mtmp==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_CodecAECParam_Ntf)
	BODY(mt::TBOOL32, auto)
	BODY(mt::TU32, value)	

	/*<<获取音频输出功率命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*start  : TRUE表示启动，FALSE表示停止
	*消息流向 ：sdk==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_BLL_CodecGetAudOutPower_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TBOOL32, start)

	/*<<音频输出功率通知>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*power  ：音频输出功率
	*消息流向 ：mtmp==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_CodecAudOutPower_Ntf)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TU32, power)

	/*<<获取音频输入功率命令>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*消息流向 ：sdk==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_BLL_CodecGetAudInPower_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TBOOL32, start)
	
	/*<<获取音频输出音量请求,windows和嵌入式平台>>
	说明:嵌入式终端使用的时候ID填0
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*消息流向 ：service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_BLL_CodecGetAudOutVol_Req)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<获取音频输出音量响应,仅windows平台>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*vol    : 音量
	*消息流向 ：mtmp==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_CodecGetAudOutVol_Rsp)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TU32, vol)

	/*<<音频输入功率通知>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*power  ：音频输入功率
	*消息流向 ：mtmp==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_CodecAudInPower_Ntf)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TU32, power)	

	/*<<控制第一个主视频编码器发送静态图片命令>>
	*enable : TRUE发送，FALSE停止发送
	*消息流向 ：service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_BLL_CodecSndStaticPic_Cmd)
	BODY(mt::TBOOL32, enable)

	/*<<控制第一个主视频编码器开始采集命令>>
	*enable : TRUE开始采集，FALSE停止采集
	*消息流向 ：service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_BLL_CodecStartVidCap_Cmd)
	BODY(mt::TBOOL32, enable)

	/*<<台标加入码流>> (仅win32)
	*enable : 是否加入码流
	*logo_param : 台标参数
	*消息流向 ：sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_CodecSetAddLogoIntoEncStream_Cmd)	
	BODY(mt::TBOOL32, enable)
	BODY(mt::TMtFullLogoParam, logo_param)


	/*<<设置解码回调函数开关>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*start  : TRUE表示启动，FALSE表示停止
	*消息流向 ：service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_BLL_CodecSetDecFrameCallBack_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TBOOL32, start)

	/*<<台标加入码流>> (mobil)
	*enable : 是否加入码流
	*RpLogo_param : 台标参数(数组)
	*消息流向 ：sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_CodecSetMobilAddLogoIntoEncStream_Cmd)	
	BODY(mt::TBOOL32, enable)
	BODY(mt::TRpMtFullLogoParam, RpLogo_param)

	/*<<请求关键帧>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*消息流向 ：sdp==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_CodecIFramRequest_Cmd)
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, codec_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	
		/*<<投屏状态通知>>
	*/
	MESSAGE(Ev_MT_BLL_MtQkState_Ntf)
	BODY(mt::TMtQkState , state)  // 单个投屏器状态

#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(MPCOMMON) = EVSEG_BLL_MPCOMMON_END
};
#endif

#define Is_BLL_MPCommon_Msg(m) ((m) >= EV_BLL_BGN(MPCOMMON) && (m) <= EV_BLL_END(MPCOMMON))

#endif // _MTMPCOMMONMSG_H_