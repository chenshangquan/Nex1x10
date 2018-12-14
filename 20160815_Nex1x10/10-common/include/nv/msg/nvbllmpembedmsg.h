#ifndef _NVBLLMPEMBEDMSG_H_
#define _NVBLLMPEMBEDMSG_H_

#include "nvmsgid.h"
#include "nvstruct.pb.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMPEmbedMsg
{
    EV_BLL_BGN(MPEMBED) = EVSEG_BLL_MPEMBED_BGN,
#endif
	
	/*<<视频源分辨率上报>>
	*传输方向：nvservice==>dispatch==>sdk
	* see 
	*/
	MESSAGE( Ev_BLL_NV_NvmpVidSrcStatus_Ntf )
	BODY(nv::TNVVidInPortResInfoList, src_info_list)

	/*<<查询视频源分辨率>>
	*传输方向：sdk==>dispatch==>nvservice
	*is_test ：是否诊断测试
	* see 
	*/
	MESSAGE( Ev_BLL_NV_NvmpVidSrcStatus_Req )
	BODY(nv::TBOOL32, is_test)

	
	/*<<视频源分辨率上报>>
	*传输方向：nvservice==>dispatch==>sdk
	* see 
	*/
	MESSAGE( Ev_BLL_NV_NvmpVidSrcStatus_Rsp )
	BODY(nv::TNVVidInPortResInfoList, src_info_list)

	/*<<设置共享>>
	*is_sharing ：是否共享
	*传输方向：sdk==>dispatch==>nvservice
	* see 
	*/
	MESSAGE( Ev_BLL_NV_SetSharingOption_Cmd )
	BODY(nv::TBOOL32, is_sharing)
	
	/*<< 共享状态通知>>
	*is_sharing ：是否共享
	*传输方向：sdk==>dispatch==>nvservice
	* see 
	*/
	MESSAGE( Ev_BLL_NV_SetSharingOption_Ntf )
	BODY(nv::TBOOL32, is_sharing)
	
	/*<<设置静音>>
	*is_quiet ：是否静音
	*传输方向：sdk==>dispatch==>nvservice
	* see 
	*/
	MESSAGE( Ev_BLL_NV_CodecQuiet_Cmd )
	BODY(nv::TBOOL32, is_quiet)
	
	/*<< 静音状态通知>>
	*is_quiet ：是否静音
	*传输方向：sdk==>dispatch==>nvservice
	* see 
	*/
	MESSAGE( Ev_BLL_NV_CodecQuiet_Ntf )
	BODY(nv::TBOOL32, is_quiet)
	
	
	/*<<获取静音状态请求>>
	*传输方向：sdk==>dispatch==>nvservice
	* see 
	*/
	MESSAGE( Ev_BLL_NV_CodecGetQuiet_Req )

	/*<<获取静音状态请求响应>>
	*is_quiet ：是否静音
	*传输方向：sdk==>dispatch==>nvservice
	* see 
	*/
	MESSAGE( Ev_BLL_NV_CodecQuiet_Rsp )
	BODY(nv::TBOOL32, is_quiet)
	
	/*<<设置音频输出音量命令>>
	*vol : 音量
	*消息流向 ：sdk==>dispatch==>nvservice
	*/
    MESSAGE(Ev_BLL_NV_CodecSetAudOutVol_Cmd)
	BODY(nv::TU32, vol)

	/*<<获取音频输出音量请求>>
	*消息流向 ：sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_BLL_NV_CodecGetAudOutVol_Req)


	/*<<获取音频输出音量响应>>
	*vol    : 音量
	*消息流向 ：nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_BLL_NV_CodecGetAudOutVol_Rsp)
	BODY(nv::TU32, vol)
	
	/*<<音频输出音量通知>>
	*vol    : 音量
	*消息流向 ：nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_BLL_NV_CodecAudOutVol_Ntf)
	BODY(nv::TU32, vol)
	
	/*<<拍摄快照请求>>
	*传输方向：sdk->nvervice
	*snapshot_name : 快照全路径名字
	*codec_id : 
	* see Ev_BLL_NV_CodecSnapshot_Rsp
	*/
	MESSAGE( Ev_BLL_NV_CodecSnapshot_Req )
	BODY(nv::TString, snapshot_name)
	BODY(nv::TS32, codec_id) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvCodecComponentIndex

	/*<<拍摄快照响应>>
	*传输方向：nvservice->sdk
	*snapshot_state :快照拍摄状态 0：成功 1：失败
	*snapshot_name : 快照全路径名字
	*codec_id 
	* see Ev_BLL_NV_CodecSnapshot_Req
	*/
	MESSAGE( Ev_BLL_NV_CodecSnapshot_Rsp )
	BODY(nv::TU32, snapshot_state) //快照拍摄状态 0：成功 1：失败
	BODY(nv::TString, snapshot_name)
	BODY(nv::TS32, codec_id) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvCodecComponentIndex
	
	/*<<获取音频输入>>
	*消息流向 ：sdk==>dispatch==>service
	*/
	MESSAGE(Ev_BLL_NV_CodecGetAllAudInPower_Cmd)
	
	/*<<音频输入回复>>
	*消息流向 service==>dispatch==>sdk
	*aud_list : 音频信号列表
	*/
	MESSAGE(Ev_BLL_NV_CodecGetAllAudInPower_Ntf)
	BODY(nv::TNVAudInPowerList, aud_list)
	
	/*<<铃声测试>>
	*消息流向 ：sdk==>dispatch==>service
	*bplay 1:开启，0：关闭
	*/
	MESSAGE(Ev_BLL_NV_CodecRingPlay_Cmd)
	BODY(nv::TBOOL32, bplay)
	
	/*<<设置HDMI开关，控制数据>>
	*消息流向 ：sdk==>dispatch==>service
	*bUp 1:3798数据不经过FPGA，0：3798数据可以经过FPGA
	*/
	MESSAGE(Ev_BLL_NV_SetHdmiSwitch_Cmd)
	BODY(nv::TBOOL32, bUp)
	BODY(nv::TBOOL32, bSet)
	
	/*<<无线投屏发送视频源信息给imix>>
	*消息流向 ：sdk==>dispatch==>service
	*tInfo :包含分辨率等信息
	*/
	MESSAGE(Ev_BLL_NV_QKSendVidSrcInfo_Cmd)
	BODY(nv::TNVVidInPortResInfo, tInfo)
	
	/*<<刷新视频源信息>>
	*消息流向 ：access==>dispatch==>service
	*tInfo :包含分辨率等信息
	*/
	MESSAGE(Ev_BLL_NV_RefreshVidSrcInfo_Cmd)
	BODY(nv::TNVVidInPortResInfo, tInfo)
	
	/*<<设置解码播放图像的显示图层>>
	*消息流向 ：sdk==>dispatch==>service
	*BOOL32 bMinimize TRUE:最小化  FALSE：最大化 
	*/
	MESSAGE(Ev_BLL_NV_SetShowRect_Cmd)
	BODY(nv::TBOOL32, bMinimize)
	
		/*<<当前应答方式上报>>
	* bManuMode ：上报应答参数
	*消息流向 nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_AnswerCallMode_Ntf)
	BODY(nv::TBOOL32, bManuMode)
	
		/*<<设置yuv参数>>
	* nyuv ：yuv参数
	*消息流向 sdk==>dispatch==>service
	*/
	MESSAGE(Ev_NV_BLL_SetOutclrspace_Cmd)
	BODY(nv::TS32, nyuv)
	
	/*<<设置播放设备的显示比例	>>
	*传输方向：sdk==>dispatch==>service
	*/
	MESSAGE( Ev_BLL_NV_CodecSetPlayZoomMode_Cmd )
	BODY(nv::TS32, zoon) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvZoomMode
	
	/*<<设置播放设备的显示比例	>>
	*传输方向：sdk==>dispatch==>service
	*/
	MESSAGE( Ev_BLL_NV_CodecSetPlayZoomMode_Ntf )
	BODY(nv::TS32, zoon) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvZoomMode
	
	/*<<获取播放设备的显示比例回复	>>
	*传输方向：sdk==>dispatch==>service
	*/
	MESSAGE( Ev_BLL_NV_CodecGetPlayZoomMode_Req )
	BODY(nv::TS32, zoon) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvZoomMode
	
	/*<<获取播放设备的显示比例回复	>>
	*传输方向：sdk==>dispatch==>service
	*/
	MESSAGE( Ev_BLL_NV_CodecGetPlayZoomMode_Rsp )
	BODY(nv::TS32, zoon) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvZoomMode
	
	/*<<设置视频冻结	>>
	*传输方向：sdk==>dispatch==>service
	*/
	MESSAGE( Ev_BLL_NV_CodecSetVidFreezePrm_Cmd )
	BODY(nv::TNVVidFreezePrm, Freeze) 
	
	/*<<视频源不是1080	>>
	*传输方向：nvservice==>dispatch==>sdk
	*/
	MESSAGE( Ev_BLL_NV_CodecVidResIsNot1080_Nty )
	BODY(nv::TS32, port)//枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvImixVidSrcType	
	
	/*<<小图像操作	>>
	*传输方向：sdk==>dispatch==>service
	*/
	MESSAGE( Ev_BLL_NV_CodecSetMiniVid_Cmd )
	BODY(nv::TNVMiniVidInfo, info)
	
	/*<<视频冻结状态查询	>>
	*传输方向：sdk==>dispatch==>service
	*/
	MESSAGE( Ev_BLL_NV_CodecGetVidFreezePrm_Req )

	/*<<视频冻结状态查询回复	>>
	*传输方向：service==>dispatch==>sdk
	*/
	MESSAGE( Ev_BLL_NV_CodecGetVidFreezePrm_Rsp )
	BODY(nv::TU32, Freeze)
	
	/*<<通知Imix NT不能正常启动>>
	*dk==>dispatch==>service
	*/
	MESSAGE( Ev_BLL_NV_NotifyImixNTState_Cmd )
	BODY(nv::TBOOL32, bNtState)
	
	/*<<通知Imix NT不能正常启动>>
	*dk==>dispatch==>service
	*/
	MESSAGE( Ev_BLL_NV_NotifyImixNTState_Nty )
	BODY(nv::TBOOL32, bNtState)
	BODY(nv::TU32, node)
	
	/*<<画面选看状态通知>>
	*传输方向：nvservice==>dispatch==>sdk
	* bstart  TRUE：开始切换画面 FALSE：结束画面切换
	*/
	MESSAGE( Ev_BLL_NV_ViewPicState_Nty )
	BODY(nv::TBOOL32, bstart)

	/*<<通知Imix u盘状态>>
	*sdk==>dispatch==>service
	*dwUDiskIndex 指示哪个u盘，0：u盘1； 1：u盘2
	*bHasSrc：该u盘是否有源
	*/
	MESSAGE( Ev_BLL_NV_UDiskState_Nty )
	BODY(nv::TU32, dwUDiskIndex)
	BODY(nv::TBOOL32, bHasSrc)

	/*<<后台清理Imix源信息>>
	*sdk==>dispatch==>service
	*ClearSrcType UI清理的动态源信息
	*/
	MESSAGE( Ev_BLL_NV_ClearSrcType_Cmd )
	BODY(nv::TNVClearSrcType, ClearSrcType)

	/*<<DLNA源状态通知>>
	*sdk==>dispatch==>service
	*bIsHas 0:无源 1：有源
	*/
	MESSAGE( Ev_BLL_NV_DLNASrcState_Nty )
	BODY(nv::TBOOL32, bIsHas)
	
	/*<<退出批注原因通知>>
	*sdk==>dispatch==>service
	*nv::TS32 reason
	*/
	MESSAGE( Ev_BLL_NV_LeaveDrawReason_Nty ) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvLeaveDrawReason	
	BODY(nv::TS32, reason)

	/*<<画线命令>>
	*sdk==>dispatch==>service
	*/
	MESSAGE( Ev_BLL_NV_DrawLine_Cmd )
	BODY(nv::TNVVidLineOverlap, bInfo)
	
	/*<<解码器异常通知>>
	*传输方向：nvmp==>dispatch==>nvservice
	*/
	MESSAGE( Ev_BLL_NV_CodecError_Nty )

	/*<<通知界面当前无线投屏是否播放ppt	>>
	*传输方向：nvservice==>dispatch==>sdk
	*/
	MESSAGE( Ev_BLL_NV_QKIsViewPPT_Nty )
	BODY(nv::TBOOL32, IsViewPPT)

	/*<<PPT翻页命令消息	>>
	*传输方向：sdk==>dispatch==>service
	*tPageTurn: EmNvPPTPageTurning
	*/
	MESSAGE( Ev_BLL_NV_PPTPageTurn_Cmd )
	BODY(nv::TS32, tPageTurn)

	/*<<远程白板命令>>
	*传输方向：sdk==>dispatch==>service
	*tView: 是否打开远程白板
	*/
	MESSAGE( Ev_BLL_NV_WhiteBoard_Cmd )
	BODY(nv::TBOOL32, tView)
	
	/*<<通知imix业务当前是否显示绿色弹窗>>
	*传输方向：sdk==>dispatch==>service
	*tShow: 是否打开绿色弹窗
	*/
	MESSAGE( Ev_BLL_NV_NotifyIsShowGreenWin_Cmd )
	BODY(nv::TBOOL32, tShow)

	/*<<退出批注命令>>
	*传输方向：sdk==>dispatch==>service
	*
	*/
	MESSAGE( Ev_BLL_NV_LeaveSrceenDraw_Cmd )

	/*<<通知imix业务开启或者关闭功放>>
	*传输方向：sdk==>dispatch==>service
	*tbOpen: 是否开启
	*/
	MESSAGE( Ev_BLL_NV_SetAmplifierStatus_Cmd )
	BODY(nv::TBOOL32, tbOpen)

	/*<<通知界面开启或者关闭功放结果>>
	*传输方向：nvservice==>dispatch==>sdk
	*tbResult: 是否成功
	*/
	MESSAGE( Ev_BLL_NV_SetAmplifierStatus_Ntf )
	BODY(nv::TBOOL32, tbResult)

	/*<<imix双屏设置会议中右屏是否本地回显>>
	*消息流向 sdk==>dispatch==>service
	*tbView:是否回显
	*/
	MESSAGE(Ev_BLL_NV_SetImixLocalEcho_Cmd)
	BODY(nv::TBOOL32, tbView)

	/*<<设置会议中右屏是否本地回显结果通知>>
	*消息流向 nvservice==>dispatch==>sdk
	*tbView:是否回显
	*/
	MESSAGE(Ev_BLL_NV_SetImixLocalEcho_Nty)
	BODY(nv::TBOOL32, tbView)
	
#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(MPEMBED) = EVSEG_BLL_MPCOMMON_END
};
#endif

#define Is_BLL_MPEmbed_Msg(m) ((m) >= EV_BLL_BGN(MPEMBED) && (m) <= EV_BLL_END(MPEMBED))

#endif // _NVBLLMPEMBEDMSG_H_