#ifndef _NVMPEMBEDMSG_H_
#define _NVMPEMBEDMSG_H_

#include "nvmsgid.h"
#include "nvstruct.pb.h"

#if !defined(_MESSAGE_HELP_)
enum EmMPEmbedMsg
{
    EV_BGN(MPEMBED) = EVSEG_MPEMBED_BGN,
#endif
	
	/*<<设置解码器地址参数>>
	*codec_type ：码流类垿
	*encoder_id ：码流索弿
	*rtp_local_addr   ：接收rtp包的本地地址
	*rtcp_local_addr  ：接收rtcp包的本地地址
	*rtp_remote_addr  ：发送打动包的远端地址，端口为0表示不发送打动包，否则发送打动包
	*rtcp_remote_addr ：发送rtcp包的远端目的地址，也即解码器的backrtcp地址
	*消息流向 ：service==>dispatch==>nvmp
	*/
    MESSAGE(Ev_NV_CodecSetChanRcvAddr_Cmd)
	BODY(nv::TS32, codec_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvCodecComponent
	BODY(nv::TS32, decoder_id) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvCodecComponentIndex	
	BODY(nv::TNVNetAddr, rtp_local_addr)
	BODY(nv::TNVNetAddr, rtcp_local_addr)
	BODY(nv::TNVNetAddr, rtp_remote_addr)//
	BODY(nv::TNVNetAddr, rtcp_remote_addr)
	
	/*<<开始工作命仿>
	*codec_type ：码流类垿
	*encoder_id ：码流索弿
	*消息流向 ：service==>dispatch==>nvmp
	*/
    MESSAGE(Ev_NV_CodecChanStart_Cmd)
	BODY(nv::TS32, codec_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvCodecComponent
	BODY(nv::TS32, codec_id) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvCodecComponentIndex

	/*<<停止工作命令>>
	*codec_type ：码流类垿
	*encoder_id ：码流索弿
	*消息流向 ：service==>dispatch==>nvmp
	*/
    MESSAGE(Ev_NV_CodecChanStop_Cmd)
	BODY(nv::TS32, codec_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvCodecComponent
	BODY(nv::TS32, codec_id) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvCodecComponentIndex
	
	/*<<发送关键帧命令>>
	*codec_type ：码流类垿
	*encoder_id ：码流索弿
	*消息流向 ：service==>dispatch==>nvmp
	*/
	MESSAGE(Ev_NV_CodecFastUpdate_Cmd)
	BODY(nv::TS32, codec_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvCodecComponent
	BODY(nv::TS32, encoder_id) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvCodecComponentIndex
	
	/*<<视频解码器需要关键帧通知>>
	*codec_type ：码流类垿
	*encoder_id ：码流索弿
	*消息流向 ：nvmp==>dispatch==>service
	*/
	MESSAGE(Ev_NV_CodecNeedKeyFrame_Ntf)
	BODY(nv::TS32, codec_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvCodecComponent
	BODY(nv::TS32, decoder_id) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvCodecComponentIndex
	
	/*<<设置丢包重传参数>>
	*prs_param ：丢包重传参敿
	*消息流向 ：service==>dispatch==>nvmp
	*/
    MESSAGE(Ev_NV_CodecSetPrsParam_Cmd)
	BODY(nv::TNVPrsParam, prs_param)
	
	/*<<设置动态载荿>
	*codec_type ：码流类垿
	*encoder_id ：码流索弿
	*payload       ：动态载荿
	*media_type    ：该动态载荷对应的媒体类型，仅对解码器有效
	*消息流向 ：service==>dispatch==>nvmp
	*/
    MESSAGE(Ev_NV_CodecSetDynamicPayload_Cmd)
	BODY(nv::TS32, codec_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvCodecComponent
	BODY(nv::TS32, codec_id) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvCodecComponentIndex
	BODY(nv::TU32, payload) 
	BODY(nv::TS32, media_type)
	
	/*<<设置秘钥>>
	*codec_type ：码流类垿
	*encoder_id ：码流索弿
	*key        ：秘钿
	*消息流向 ：service==>dispatch==>nvmp
	*/
    MESSAGE(Ev_NV_CodecSetEncryptKey_Cmd)
	BODY(nv::TS32, codec_type)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvCodecComponent
	BODY(nv::TS32, codec_id) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvCodecComponentIndex
	BODY(nv::TNVEncryptKey, key)
	
	/*<<视频源分辨率上报>>
	*传输方向：nvmp==>dispatch==>nvservice
	* see 
	*/
	MESSAGE( Ev_NV_NvmpVidSrcStatus_Ntf )
	BODY(nv::TNVVidInPortResInfoList, src_info_list)
	
	/*<<查询视频源分辨率>>
	*传输方向：nvservice==>dispatch==>nvmp
	*is_test ：是否诊断测试
	* see 
	*/
	MESSAGE( Ev_NV_NvmpVidSrcStatus_Req )
	BODY(nv::TBOOL32, is_test)
	
	/*<<视频源分辨率上报>>
	*传输方向：nvmp==>dispatch==>nvservice
	* see 
	*/
	MESSAGE( Ev_NV_NvmpVidSrcStatus_Rsp )
	BODY(nv::TNVVidInPortResInfoList, src_info_list)
	
	/*<<视频源是否有源上抿>
	*src_info ：视频源信息
	*传输方向：nvmp==>dispatch==>nvservice
	* see 
	*/
	MESSAGE( Ev_NV_ImixVidSrcSignal_Ntf )
	BODY(nv::TNVImixVidSrcSignal, src_info)
	BODY(nv::TBOOL32, is_first)

	
	/*<<设置静音>>
	*is_quiet ：是否静響
	*传输方向：nvservice==>dispatch==>nvmp
	* see 
	*/
	MESSAGE( Ev_NV_CodecQuiet_Cmd )
	BODY(nv::TBOOL32, is_quiet)
	
	/*<<设置音频输出音量命令>>
	*vol : 音量
	*aud_port : 音频端口
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_NV_CodecSetAudOutVol_Cmd)
	BODY(nv::TU32, vol)
	BODY(nv::TS32, aud_port) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvAudPortOut

	/*<<获取音频输出音量请求>>
	*消息流向 ：service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_NV_CodecGetAudOutVol_Req)


	/*<<获取音频输出音量响应>>
	*vol    : 音量
	*消息流向 ：mtmp==>dispatch==>service
	*/
	MESSAGE(Ev_NV_CodecGetAudOutVol_Rsp)
	BODY(nv::TU32, vol)
	
	/*<<拍摄快照请求>>
	*传输方向：nvervice->nvmp
	* see Ev_NV_CodecSnapshot_Rsp
	*/
	MESSAGE( Ev_NV_CodecSnapshot_Req )
	BODY(nv::TString, snapshot_name)
	BODY(nv::TS32, codec_id) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvCodecComponentIndex

	/*<<拍摄快照响应>>
	*传输方向：nvmp->nvservice
	* see Ev_NV_CodecSnapshot_Req
	*/
	MESSAGE( Ev_NV_CodecSnapshot_Rsp )
	BODY(nv::TU32, snapshot_state) //快照拍摄状态 0：成功 1：失败
	BODY(nv::TString, snapshot_name)
	BODY(nv::TS32, codec_id) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvCodecComponentIndex

	/*<<获取音频输入>>
	*消息流向 ：service==>dispatch==>nvmp
	*/
	MESSAGE(Ev_NV_CodecGetAllAudInPower_Cmd)
	
	/*<<音频输入回复>>
	*消息流向 nvmp==>dispatch==>：service
	*aud_list : 音频信号列表
	*/
	MESSAGE(Ev_NV_CodecGetAllAudInPower_Ntf)
	BODY(nv::TNVAudInPowerList, aud_list)
	
	/*<<铃声测试>>
	*消息流向 ：service==>dispatch==>nvmp
	*bplay 1:开启，0：关闭
	*/
	MESSAGE(Ev_NV_CodecRingPlay_Cmd)
	BODY(nv::TBOOL32, bplay)
	
	/*<<设置HDMI开关，控制数据>>
	*消息流向 ：service==>dispatch==>nvmp
	*bUp 1:3798数据不经过FPGA，0：3798数据可以经过FPGA
	*/
	MESSAGE(Ev_NV_SetHdmiSwitch_Cmd)
	BODY(nv::TBOOL32, bUp)
	
	MESSAGE(Ev_NV_DualVidSrcSignal_Ntf)
	BODY(nv::TBOOL32, bHdmi)
	
	/*<<设置解码播放图像的显示图层>>
	*消息流向 ：service==>dispatch==>nvmp
	*BOOL32 bMinimize TRUE:最小化  FALSE：最大化 
	*/
	MESSAGE(Ev_NV_SetShowRect_Cmd)
	BODY(nv::TBOOL32, bMinimize)

	/*<<设置音频端口>>
	*消息流向 ：service==>dispatch==>nvmp
	* port 音频输入输出口
	*/
	MESSAGE(Ev_NV_CodecSetAudPort_Cmd)
	BODY(nv::TNVAudPort, port)
	
	/*<<设置视频输入输出矩阵>>
	*消息流向 ：service==>dispatch==>nvmp
	* matrix  视频矩阵
	* is_osd  是否叠加画面
	*/
	MESSAGE(Ev_NV_CodecSetVidMatrix_Cmd)
	BODY(nv::TNVVideoMatrixScheme, matrix) 
	BODY(nv::TBOOL32, is_osd) 

	/*<<弹蓝色底图>>
	*消息流向 ：service==>dispatch==>nvmp
	* matrix  视频矩阵
	* is_osd  是否叠加画面
	*/
	MESSAGE(Ev_NV_BluePic_Cmd)
	BODY(nv::TBOOL32, isblue)
	/*<<叠加文字>>
	*消息流向 ：service==>dispatch==>nvmp
	* matrix  视频矩阵
	* is_osd  是否叠加画面
	*/
	MESSAGE(Ev_NV_OSD_Cmd)
	BODY(nv::TBOOL32, isosd)
	
	/*<<设置Ops开关>>
	*消息流向 ：device==>dispatch==>nvmp
	* is_osd  TRUE:开 FALSE：关  
	*/
	MESSAGE(Ev_NV_SetOpsStatus_Cmd)
	BODY(nv::TBOOL32, bOpen)
	
	/*<<生产测试开关读写串口>>
	*消息流向 ：device==>dispatch==>nvmp
	* is_osd  TRUE:开 FALSE：关  
	*/
	MESSAGE(Ev_NV_DeviceSerialTest_Nty)
	BODY(nv::TBOOL32, bOpen)
	
	/*<<设置播放设备的显示比例	>>
	*传输方向：nvervice->nvmp
	* see Ev_NV_CodecSnapshot_Rsp
	*/
	MESSAGE( Ev_NV_CodecSetPlayZoomMode_Cmd )
	BODY(nv::TS32, zoon) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvZoomMode
	
	/*<<imix的socket accept数据通知>>
	*消息流向 ：nvmp==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_ImixSocketAccept_Nty)
	
	/*<<设置视频冻结	>>
	*传输方向：nvservice==>dispatch==>nvmp
	*/
	MESSAGE( Ev_NV_CodecSetVidFreezePrm_Cmd )
	BODY(nv::TNVVidFreezePrm, Freeze) 
	
	/*<<imix的socket listen数据通知>>
	*消息流向 ：nvmp==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_ImixSocketListen_Nty)
	
	/*<<视频源不是1080	>>
	*传输方向：nvmp==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_CodecVidResIsNot1080_Nty )
	BODY(nv::TS32, port)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvImixVidSrcType	
	
	/*<<小图像操作	>>
	*传输方向：nvservice==>dispatch==>nvmp
	*/
	MESSAGE( Ev_NV_CodecSetMiniVid_Cmd )
	BODY(nv::TNVMiniVidInfo, info)
	
	/*<<小图像操作通知	>>
	*传输方向：nvmp==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_CodecSetMiniVid_Ntf )
	BODY(nv::TNVMiniVidInfo, info)
	
	/*<<视频冻结状态查询	>>
	*传输方向：nvservice==>dispatch==>nvmp
	*/
	MESSAGE( Ev_NV_CodecGetVidFreezePrm_Req )

	/*<<视频冻结状态查询回复	>>
	*传输方向：nvmp==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_CodecGetVidFreezePrm_Rsp )
	BODY(nv::TU32, Freeze)
	
	/*<<小图像状态查询	>>
	*传输方向：nvservice==>dispatch==>nvmp
	*/
	MESSAGE( Ev_NV_GetMiniVidInfoRt_Req )

	/*<<小图像状态查询回复	>>
	*传输方向：nvmp==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_GetMiniVidInfoRt_Rsp )
	BODY(nv::TNVMiniVidInfo, info)
	
	/*<<画面选看状态通知>>
	*传输方向：nvmp==>dispatch==>nvservice
	* bstart  TRUE：开始切换画面 FALSE：结束画面切换
	*/
	MESSAGE( Ev_NV_ViewPicState_Nty )
	BODY(nv::TBOOL32, bstart)

	/*<<画线命令	>>
	*传输方向：nvservice==>dispatch==>nvmp
	*/
	MESSAGE( Ev_NV_DrawLine_Cmd )
	BODY(nv::TNVVidLineOverlap, info)
	
	/*<<解码器异常通知>>
	*传输方向：nvmp==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_CodecError_Nty )
	
	/*<<设置功放板静音	>>
	*传输方向：nvservice==>dispatch==>nvmp
	*/
	MESSAGE( Ev_NV_SetAmplifierStatus_Cmd )
	BODY(nv::TBOOL32, bmute)

	/*<<设置HDMI是否输出音频	>>
	*传输方向：nvservice==>dispatch==>nvmp
	*/
	MESSAGE( Ev_NV_SetHDMIAudioMute_Cmd )
	BODY(nv::TBOOL32, bmute)
	
	/*<<通知imix业务当前是否显示绿色弹窗>>
	*传输方向：nvservice==>dispatch==>nvmp
	*tShow: 是否打开绿色弹窗
	*/
	MESSAGE( Ev_NV_NotifyIsShowGreenWin_Cmd )
	BODY(nv::TBOOL32, tShow)

	/*<<设置HDMI1是否输出视频>>
	*传输方向：nvservice==>dispatch==>nvmp
	*tView: 是否输出HDMI1视频
	*/
	MESSAGE( Ev_NV_SetHDMI1VidPlyPortStd_Cmd )
	BODY(nv::TBOOL32, tShow)

	/*<<回显时收到终端检测到辅流源状态的通知>>
	*传输方向：nvterinterface==>dispatch==>nvmp
	*tHasSrc: 是否输出HDMI1视频
	*/
	MESSAGE( Ev_NV_TerVidSrcStatus_Nty )
	BODY(nv::TBOOL32, tHasSrc)
	
#if !defined(_MESSAGE_HELP_)
    EV_END(MPEMBED) = EVSEG_MPCOMMON_END
};
#endif

#define Is_MPEmbed_Msg(m) ((m) >= Ev_NV_BGN(MPEMBED) && (m) <= Ev_NV_END(MPEMBED))

#endif // _NVMPEMBEDMSG_H_