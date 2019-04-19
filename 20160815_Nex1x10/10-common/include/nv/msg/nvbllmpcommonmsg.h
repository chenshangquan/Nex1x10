#ifndef _NVBLLMPCOMMONMSG_H_
#define _NVBLLMPCOMMONMSG_H_

#include "nvmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMPCommonMsg
{
    EV_BLL_BGN(MPCOMMON) = EVSEG_BLL_MPCOMMON_BGN,
#endif

	/*<<切换画面命令>>
	* pic ：选看画面内容
	*消息流向 sdk ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_BLL_NV_ViewPic_Cmd)         
	BODY(nv::TS32, pic) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvImixVidSrcType
	
	/*<<切换画面回复>>
	* pic ：选看画面内容
	* is_sucess ：是否切换成功
	*消息流向 nvservice ==>dispatch==>sdk
	*/
	MESSAGE(Ev_BLL_NV_ViewPic_Ntf)         
	BODY(nv::TS32, pic) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvImixVidSrcType
	BODY(nv::TS32, reason) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvWvsViewReason
	
	/*<<Imix 主动发送源位置给界面>>
	* pic ：画面内容
	*消息流向 nvservice ==>dispatch==>sdk
	*/
	MESSAGE(Ev_BLL_NV_ViewPicPosToUI_Ntf)         
	BODY(nv::TS32, pic) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvImixVidSrcType
	
	/*<<发送计算机名称命令>>
	*消息流向 sdk ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_BLL_NV_SendPCName_Cmd)   
	BODY(nv::TString, tStr)
	BODY(nv::TString, tVision)
	
	/*<<发送计算机名称命令回复>>
	*消息流向 nvservice ==>sdk
	*/
	MESSAGE(Ev_BLL_NV_SendPCName_Ntf)   
	BODY(nv::TString, tStr) 
	
	/*<<发送触控信息命令>>
	*消息流向 sdk ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_BLL_NV_SendInputEvent_Cmd)   
	BODY(nv::TNVInputEvents, tInput) 
	
	/*<<发送触控信息命令回复>>
	*消息流向 nvservice ==>sdk
	*/
	MESSAGE(Ev_BLL_NV_SendInputEvent_Ntf)   
	BODY(nv::TNVInputEvents, tInput)
	
	/*<<Imix 主动发送无线投屏设备列表给界面>>
	*消息流向 nvservice ==>sdk
	*/
	MESSAGE(Ev_BLL_NV_SendQuickShareList_Ntf)   
	BODY(nv::TNVLoginInfos, tLogins) 
	
	/*<<无线投屏发送本地rtp地址和端口命令>>
	*消息流向 sdk ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_BLL_NV_SendQuickShareSendAddr_Cmd)  
	BODY(nv::TNVTransAddr, tAddr) 
	
	/*<<无线投屏发送本地rtp地址和端口命令回复>>
	*消息流向 sdk ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_BLL_NV_SendQuickShareSendAddr_Ntf)  
	BODY(nv::TNVTransAddr, tAddr) 
	
	/*<<无线投屏主动请求切源命令>>
	*消息流向 sdk ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_BLL_NV_QuickShareViewPic_Cmd)  

	/*<<无线投屏主动请求切源命令回复>>
	*消息流向 nvservice ==>sdk
	*/
	MESSAGE(Ev_BLL_NV_QuickShareViewPic_Ntf)  
	BODY(nv::TS32, reason) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvWvsViewReason
	
	/*<<无线投屏主动停止切源命令>>
	*消息流向 sdk ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_BLL_NV_QuickShareViewPicStop_Cmd)  

	/*<<无线投屏主动停止切源命令回复>>
	*消息流向 nvservice ==>sdk
	*/
	MESSAGE(Ev_BLL_NV_QuickShareViewPicStop_Ntf)  
	BODY(nv::TS32, pic) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvImixVidSrcType
	BODY(nv::TS32, reason) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvWvsViewReason
	
	/*<<无线投屏检查更新命令>>
	*消息流向 sdk ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_BLL_NV_QuickShareCheckUpgrade_Cmd)
	
	/*<<Imix 主动发送触控信息给无线投屏>>
	*消息流向 nvservice ==>sdk
	*/
	MESSAGE(Ev_BLL_NV_SendInputEventToQuickShare_Ntf)   
	BODY(nv::TNVInputEvents, tInput) 

	/*<<Imix 主动发送本地rtp地址和端口给无线投屏>>
	*消息流向 nvservice ==>sdk
	*/
	MESSAGE(Ev_BLL_NV_SendImixRcvAddrToQuickShare_Ntf)  
	BODY(nv::TNVRtpRtcpPair, tVidAddr) 
	BODY(nv::TNVRtpRtcpPair, tAudAddr)
	
	/*<<Imix 主动给无线投屏发送请求关键帧>>
	*消息流向 nvservice ==>sdk
	*/
	MESSAGE(Ev_BLL_NV_SendIFrameRequestToQuickShare_Ntf)   
	
	/*<<Imix 主动给无线投屏停止发送码流>>
	*消息流向 nvservice ==>sdk
	*/
	MESSAGE(Ev_BLL_NV_StopTransferCodeStream_Ntf)  
	
	/*<<查询当前显示画面内容>>
	*消息流向 sdk ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_BLL_NV_GetPic_Req)         
	
	/*<<查询当前显示画面内容>>
	*消息流向 nvservice ==>dispatch==>sdk
	*/
	MESSAGE(Ev_BLL_NV_GetPic_Rsp)   
	BODY(nv::TS32, pic) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvImixVidSrcType
	
	/*<<当前画面状态通知>>
	* pic ：选看画面内容
	*消息流向 nvservice ==>dispatch==>sdk
	*/
	MESSAGE(Ev_BLL_NV_PicStatus_Ntf)         
	BODY(nv::TS32, pic) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvImixVidSrcType
	/*<<手动呼叫选择>>
	*消息流向 sdk ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_CallAnswer_Cmd)
	BODY(nv::TBOOL32, tAnswerCall )	
	
	/*<<无线投屏切源通知>>
	*消息流向 nvservice ==>sdk
	*/
	MESSAGE(Ev_BLL_NV_QuickShareViewPre_Ntf)  
	BODY(nv::TS32, reason) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvWvsViewReason

	/*<<无线投屏发送pc开始播放PPT命令>>
	*消息流向 sdk ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_BLL_NV_QKSendPCStartPPT_Cmd)

	/*<<无线投屏发送pc停止播放PPT命令>>
	*消息流向 sdk ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_BLL_NV_QKSendPCStopPPT_Cmd)

	/*<<无线投屏发送心跳通知>>
	*消息流向 sdk ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_BLL_NV_QKSendHeartBeat_Ntf)

	/*<<imix发送心跳通知给无线投屏>>
	*消息流向 sdk ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_BLL_NV_ImixSendToQKHeartBeat_Nty)

	/*<<imix发送ppt翻页命令给无线投屏>>
	*消息流向 sdk ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_BLL_NV_SendPPTPageTurn_Cmd)
	BODY(nv::TS32, reason) //枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvPPTPageTurning

	/*<<无线投屏询问终端别名>>
	*消息流向 sdk ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_BLL_NV_QkGetTerName_Req)

	/*<<imix发送终端别名给无线投屏>>
	*消息流向 nvservice ==>dispatch==>sdk
	*/
	MESSAGE(Ev_BLL_NV_QkGetTerName_Rsp)
	BODY(nv::TString, tTerName)

	/*<<无线投屏sdk发送需要编码协商通知给无线投屏>>
	*消息流向 qksdk ==>dispatch==>qk
	*/
	MESSAGE(Ev_BLL_NV_QKNeedCodeConsult_Ntf)

	/*<<无线投屏sdk发送编码协商参数给无线投屏>>
	*消息流向 qksdk ==>dispatch==>qk
	*tParam:编码参数
	*/
	MESSAGE(Ev_BLL_NV_QKCodeParam_Cmd)
	BODY(nv::TQKCodeParam, tParam)

	/*<<无线投屏sdk发送编码分辨率给无线投屏>>
	*消息流向 qksdk ==>dispatch==>qk
	*tRes:编码分辨率
	*/
	MESSAGE(Ev_BLL_NV_QKCodeRes_Cmd)
	BODY(nv::TS32, tRes)

	/*<<无线投屏sdk发送编码帧率给无线投屏>>
	*消息流向 qksdk ==>dispatch==>qk
	*tFrame:编码帧率
	*/
	MESSAGE(Ev_BLL_NV_QKCodeFrameRate_Cmd)
	BODY(nv::TU32, tFrame)

	/*<<无线投屏sdk发送编码码率给无线投屏>>
	*消息流向 qksdk ==>dispatch==>qk
	*tBitRate:编码码率
	*/
	MESSAGE(Ev_BLL_NV_QKCodeBitRate_Cmd)
	BODY(nv::TU32, tBitRate)

	/*<<无线投屏发送编码协商结果给无线投屏sdk>>
	*消息流向 qk ==>dispatch==>qksdk
	*tbResult:成功与否的结果
	*/
	MESSAGE(Ev_BLL_NV_CodecConsultResult_Nty)
	BODY(nv::TBOOL32, tbResult)

	/*<<无线投屏发送编码分辨率设置结果给无线投屏sdk>>
	*消息流向 qk ==>dispatch==>qksdk
	*tbResult:成功与否的结果
	*/
	MESSAGE(Ev_BLL_NV_CodecResResult_Nty)
	BODY(nv::TBOOL32, tbResult)

	/*<<无线投屏发送编码帧率设置结果给无线投屏sdk>>
	*消息流向 qk ==>dispatch==>qksdk
	*tbResult:成功与否的结果
	*/
	MESSAGE(Ev_BLL_NV_CodecFrameResult_Nty)
	BODY(nv::TBOOL32, tbResult)

	/*<<无线投屏发送编码码率设置结果给无线投屏sdk>>
	*消息流向 qk ==>dispatch==>qksdk
	*tbResult:成功与否的结果
	*/
	MESSAGE(Ev_BLL_NV_CodecBitRateResult_Nty)
	BODY(nv::TBOOL32, tbResult)

	/*<<无线投屏sdk发送是否支持投屏>>
	*消息流向 qksdk ==>dispatch==>qk
	*tEnable:是否支持投屏
	*tReason:不支持投屏的原因
	*/
	MESSAGE(Ev_BLL_NV_QKEnableView_Cmd)
	BODY(nv::TBOOL32, tEnable)
	BODY(nv::TS32, tReason)
	
#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(MPCOMMON) = EVSEG_BLL_MPCOMMON_END
};
#endif

#define Is_BLL_MPCommon_Msg(m) ((m) >= EV_BLL_BGN(MPCOMMON) && (m) <= EV_BLL_END(MPCOMMON))

#endif // _NVMPCOMMONMSG_H_
