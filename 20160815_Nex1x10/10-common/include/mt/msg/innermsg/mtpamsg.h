#ifndef _MTPAMSG_H_
#define _MTPAMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMtpaMsg
{

	//会议子系统用到的所有的消息都在这里， 这里需要区分，mtconf模块， mth323用到的， 内置mc用到的消息。
	EV_BGN(MTPA) = EVSEG_MTPA_BGN,
#endif
	
	/*
    mtconf ------------------------------->mtpa--------------------------->mth323/mtsip/mtsat
		1.    Ev_Mtpa_XXXX_Cmd                    1.    Ev_Mtpa_XXXX_Cmd
    mtconf <------------------------------ mtpa<---------------------------mth323/mtsip/mtsat
        2.     Ev_Mtpa_XXXX_Ntf                   2.    Ev_Mtpa_XXXX_Ntf
	*/
	
	
	/*1. Ev_Mtpa_XXX_Cmd */

	/*<<开始呼叫，需要把能力集带下去>>
	* call_handler ：呼叫句柄
	* make_call_param ：   呼叫参数
	* mt_repeated_cap;     多个能力集，根据厂商来
	*/
	MESSAGE(Ev_Mtpa_MakeCall_Cmd)
	BODY(mt::TMtCallParam, make_call_param)
	BODY(mt::TRpMtCap,     mt_repeated_cap)

	/*<<接受呼叫>>
	* call_handler ：   呼叫句柄
	* make_call_param ：呼叫参数
	* mt_cap :          能力集
	*/
	MESSAGE(Ev_Mtpa_AcceptCall_Cmd)
	BODY(mt::TMtCallParam, make_call_param )
	BODY(mt::TRpMtCap,     mt_repeated_cap )

	/*<<挂断呼叫>>
	* call_handler：呼叫句柄
	* hangup_reason：挂断原因
	*/
	MESSAGE(Ev_Mtpa_Hangup_Cmd)
	BODY(mt::TU32, hangup_reason)   //EmMtCallDisReason

	/*<<开始双流>>
	* tVidLab ： 双流的lab,主要是标识， pc辅流, 还是video辅流
	  暂且认为这条消息是标准的，就是只发一路双流，对于后续的sip 多路双流，提供其他消息
	*/
	MESSAGE(Ev_Mtpa_OpenAssStream_Cmd)
	BODY(mt::TU32,			tVidLab )        //EmMtVidLabel

	
	/*<<激活双流>>
	* bActive ： 是否激活
	*/
	MESSAGE( Ev_Mtpa_ChanActive_Cmd )
	BODY(mt::TMtConfHandle, chan_handler)    //通道句柄
	BODY(mt::TBOOL32,       bActive )        //是否激活


	/*<< 关闭通道句柄 >>
	* chan_handler : 通道句柄
	*/
	MESSAGE(Ev_Mtpa_CloseStream_Cmd)
	BODY(mt::TMtConfHandle,    chan_handler)         //关通道句柄

	/*<<收到呼叫>>
	* callparam :    呼叫参数
	*/
	MESSAGE(Ev_Mtpa_CallIncoming_Ntf)
	BODY(mt::TMtCallParam, callparam)

	/*<< 245connected 消息用于内置mc >>
	*/
	MESSAGE(Ev_Mtpa_h245Connected_Ntf)


	/*<<收到呼叫>>
	* 暂时用在pa内部发给自己处理， sip双流到来消息
	*/
	MESSAGE( Ev_Mtpa_DualIncoming_Ntf )

	/*<<呼叫建立>>
	* chan_handler : 呼叫句柄
	* callparam ：  呼叫参数
	*/
	MESSAGE(Ev_Mtpa_CallConnected_Ntf )
	BODY(mt::TMtCallParam, callparam)

	/*<<呼叫挂断>>
	* discon_reason ： 挂断原因
	*/
	MESSAGE(Ev_Mtpa_CallDisconnected_Ntf)
	BODY(mt::TU32, discon_reason)           // EmMtCallDisReason


	/*<<呼叫错过消息>>
	* chan_handler  :  呼叫句柄
	* discon_reason ： 挂断原因
	*/
	MESSAGE( Ev_Mtpa_CallMissed_Ntf)   //非idle状态，收到其他呼叫信息mtpa会挂断这个呼叫， 同时上报界面
	BODY(mt::TMtCallParam, callparam )

	/*<<通道建立>>
	* chan_handler  :  通道句柄
	* chan_addr  ：    通道地址
	* chan_param :     通道参数
	*/
	MESSAGE(Ev_Mtpa_ChanConnected_Ntf)    ////如果是 fecc通道， 不需要第三个参数
	BODY(mt::TMtConfHandle, chan_handler)    
	BODY(mt::TMtChanAddr, chan_addr)
	BODY(mt::TMtAVChanParam, chan_param)

	/*<<通道断掉>>
	* chan_handler     :  通道句柄
	* chan_dis_reason  ： 通道挂断原因
	*/
	MESSAGE(Ev_Mtpa_ChanDisConnected_Ntf)
	BODY(mt::TMtConfHandle, chan_handler)
	//BODY(mt::TU32, chan_dis_reason)           // EmMtChanDisReason,后续扩展用

	/*<<通道active或非active消息>>
	* chan_handler     :    通道句柄
	* active_or_inactive  ：通道状态
	*/
	MESSAGE(Ev_Mtpa_ChanRecvState_Ntf)
	BODY(mt::TMtConfHandle, chan_handler )
	BODY(mt::TBOOL32, active_or_inactive)
	
	/*<<请求关键帧>>
	* chan_handler     :    通道句柄
	*/
	MESSAGE(Ev_Mtpa_IFrame_Request_Cmd)
	BODY(mt::TMtConfHandle, chan_handler )

	/*<<对端请求关键帧>>
	* chan_handler     :    通道句柄
	*/
	MESSAGE(Ev_Mtpa_IFrame_Request_Ntf)
	BODY(mt::TMtConfHandle, chan_handler )


	/*<<对端调整码率>>
	* chan_handler     :    通道句柄
	* chan_bitrate      ：  bitrate
	*/
	MESSAGE(Ev_Mtpa_FlowControl_Ntf)
	BODY(mt::TMtConfHandle, chan_handler )
	BODY(mt::TU16,          chan_bitrate )

	/*<<调整对端码率>>
	* chan_handler     :    通道句柄
	* chan_bitrate     ：   birate
	*/
	MESSAGE(Ev_Mtpa_FlowControl_Cmd)
	BODY(mt::TMtConfHandle, chan_handler )
	BODY(mt::TU16,          chan_bitrate )

	/*<<告知对端本方发送码率>>
	* chan_handler     :    通道句柄
	* chan_bitrate     ：   birate
	*/
	MESSAGE(Ev_Mtpa_FlowControlIndition_Cmd)
	BODY(mt::TMtConfHandle, chan_handler )
	BODY(mt::TU16,          chan_bitrate )


	MESSAGE( Ev_Mtpa_UpLoadBitrateLessThan64_Ntf )
	MESSAGE( Ev_Mtpa_DownLoadBitrateLessThan64_Ntf )


	/*能力改变, 用在双流优选，内置mc
	* tMtCap   : 改变后的能力，暂时只关心改变后的双流能力
	*/
	MESSAGE( Ev_Mtpa_ChangeCap_Cmd )
	BODY(mt::TRpMtCap,    tMtCap )



	//注册相关，消息一条
	MESSAGE(Ev_Mtpa_RegistReq_Cmd)
	BODY(mt::TU32,       conf_protocol)   //EmConfProtocol
	BODY(mt::TMtRegistReq,  regist_req)

	MESSAGE(Ev_Mtpa_AuthResult_Ntf)       //授权结果
	BODY(mt::TBOOL32,     bauthsuc)       //是否授权

	MESSAGE(Ev_Mtpa_RegResult_Ntf)       //注册结果
	BODY(mt::TU32,  conf_protocol) 
	BODY(mt::TBOOL32,     bregsuc)       //注册是否成功, 失败的话下面失败原因
	BODY(mt::TU32,        bReason)       //EmRegFailedReason


	MESSAGE( Ev_Mtpa_UnRegistReq_Cmd )     //取消注册
	BODY(mt::TU32, conf_protocol)

	MESSAGE(Ev_Mtpa_UnRegResult_Ntf)       //取消注册结果
	BODY(mt::TU32,     conf_protocol) 
	BODY(mt::TBOOL32,  bunRegsuc)          //取消注册是否成功
	BODY(mt::TU32,     unRegFailedReason)  //取消失败原因


	///注册非标信令，应定义在Ev_Mtpa_RasMessBegin 和Ev_Mtpa_RasMessEnd之间
	///
	MESSAGE(Ev_Mtpa_RasMess_Bgn)

	MESSAGE(Ev_Mtpa_RasJoinConf_Req)
	BODY( mt::TMtJoinConfParam, joinconf_param )

	////加入会议响应
	/*
	* errcode     :    错误码
	* conf_e164   ：   会议的e164号码
	*/
	MESSAGE(Ev_Mtpa_JoinConfResult_Rsp)
	BODY( mt::TU32, errcode)
	BODY( mt::TString, conf_e164 )

	MESSAGE( Ev_Mtpa_RasClearJoinConf_Cmd )

	MESSAGE( Ev_Mtpa_RasCreateConf_Req )      //创建会议请求
    BODY( mt::TMtCallParam, call_param)


	////召集会议响应
	/*
	* errcode     :    错误码
	* conf_e164   ：   会议的e164号码
	*/
	MESSAGE(Ev_Mtpa_CreateConfResult_Rsp)     //创建会议结果
	BODY( mt::TU32, errcode)
	BODY( mt::TString, conf_e164 )

	MESSAGE( Ev_Mtpa_RasClearCreateConf_Cmd)

	MESSAGE( Ev_Mtpa_GetConfList_Req )
	BODY(mt::TU32,    conf_req_type)        //EmConfListType, book, idle, hold,

	MESSAGE(Ev_Mtpa_ConfList_Rsp)
	BODY(mt::TU32,  conf_req_type)          //EmConfListType
	BODY(mt::TU32,  conf_req_error)         //EmConfListRspErr
	BODY(mt::TRpMtConfNameInfo, confList)   //多个包

	MESSAGE(Ev_Mtpa_GetConfDetailInfo_Req)
	BODY(mt::TString,     conf_e164)                //会议e164号

	MESSAGE(Ev_Mtpa_GetConfDetailInfo_Rsp)

	//获取会议室数量
	MESSAGE(Ev_Mtpa_GetRoomNum_Req)
	
	MESSAGE(Ev_Mtpa_RoomNum_Rsp)
	BODY(mt::TU32,       total_num)            //总数量
	BODY(mt::TU32,       useConfNum)           //已用数量

	////请求gk与会成员列表，用于兼容
	MESSAGE( Ev_Mtpa_GetGkRegMtList_Req )
	///gk回复
	MESSAGE( Ev_Mtpa_GetGkRegMtList_Rsp )
	BODY(mt::TRpMtInfo,       mt_info)             //终端别名信息
	BODY(mt::TBOOL32,         bfinished)           //是否结束

	MESSAGE( Ev_Mtpa_RasMess_End ) 



	//////下面是会控消息

	/*<<开始多点会议提示 mc<->mt >>
	*/
	MESSAGE( Ev_Mtpa_MccStart_Ntf )

	/*<<终端离开 >>
	* tMtid  :      终端编号
	*/
	MESSAGE( Ev_Mtpa_TerLeft_Ntf)
	BODY( mt::TMtId, tMtid )

	/*<<终端加入 >>
	* tMtid  :      终端编号
	*/
	MESSAGE( Ev_Mtpa_TerJoin_Ntf)
	BODY( mt::TMtId, tMtid )

	/*<<MC分配终端编号 >>
	* tMtid  :      终端编号
	*/
	MESSAGE( Ev_Mtpa_AssignTerId_Ntf)
	BODY( mt::TMtId, tMtid )

	/*<<请求终端列表 >>
	*/
	MESSAGE( Ev_Mtpa_TerList_Req )
	
	/*<< mc回复终端列表 >>
	* tRpMtId: 多个mtid终端
	*/
	MESSAGE( Ev_Mtpa_TerList_Rsp )
	BODY( mt::TRpMtId, tRpMtId )


	/*<<请求终端列表 >>
	*/
	MESSAGE( Ev_Mtpa_OffLineTerList_Req )
	
	/*<< mc回复终端列表 >>
	* tRpMtId: 多个mtid终端
	*/
	MESSAGE( Ev_Mtpa_OffLineTerList_Rsp )
	BODY( mt::TRpMtId, tRpMtId)


	/*<<回复终端信息，非标消息,对应协议栈的 h_ctrl_RequestTerminalInfoResponce>>
	*/
	MESSAGE( Ev_Mtpa_GetTerminalInfo_Rsp )
	BODY(mt::TBOOL32,   bAll)
	BODY(mt::TU32,      tErrCode)      //EmGetListRspErr
	BODY(mt::TRpMtInfo, Rpmt_info)

    
	////Ev_Mtpa_GetTerminalInfo_Req为非标消息
	/*<<请求mc所有与会终端名字 >>
	*/
	MESSAGE( Ev_Mtpa_GetTerminalInfo_Req )
	BODY(mt::TMtId,   tMtId)  ///


	////Ev_Mtpa_TerGetAllTerName_Req为标准消息 标准信令
	/*<<请求mc所有与会终端名字 >>
	*/
	MESSAGE( Ev_Mtpa_TerGetAllTerName_Req )

	/*<<mc回复 与会终端名字 >>
	*Rpmt_info:  多个终端名字
	*/
	MESSAGE( Ev_Mtpa_TerGetAllTerName_Rsp)
	BODY(mt::TRpMtInfo, Rpmt_info)




	/*<<mc请求当前终端名字 >>
	*/
	MESSAGE( Ev_Mtpa_McGetTerName_Req)

	/*<<终端回应 当前终端名字 >>
	* tMtInfo: 终端名字
	*/
	MESSAGE( Ev_Mtpa_McGetTerName_Rsp)
	BODY( mt::TMtInfo, tMtInfo)

	/*<<当前终端请求其他终端的名字 >>
	* tMtId:    终端id
	*/
	MESSAGE( Ev_Mtpa_TerGetOhterTerName_Req )
	BODY( mt::TMtId,  tMtId)
    
	/*<< mc响应 >>
	* tMtId:    终端id
	*/
	MESSAGE( Ev_Mtpa_TerGetOhterTerName_Rsp )
	BODY( mt::TMtInfo,  tMtInfo)


	/*<< 强制挂断某终端 >>
	* tMtId:    终端id
	*/
	MESSAGE( Ev_Mtpa_DropTer_Cmd )
	BODY( mt::TMtId, tMtId)

	/*<< 强制挂断某终端失败 >>
	*/
	MESSAGE( Ev_Mtpa_DropTerRej_Ntf )

	/*<< 主席挂断会议 >>
	*/
	MESSAGE( Ev_Mtpa_EndConf_Cmd )

	/*<< mc请求终端输入密码 >>
	*/
	MESSAGE( Ev_Mtpa_McGetTerPwd_Req )

	/*<< 终端响应输入密码 >>
	*/
	MESSAGE( Ev_Mtpa_McGetTerPwd_Rsp )
	BODY( mt::TMtId,   tMtid)
	BODY( mt::TBytes,  tPassword)


	/*<< 终端申请发言 mt<->mc >>
	*/
	MESSAGE(Ev_Mtpa_ApplyMcSpeak_Req )

	/*<< 终端申请发言 mc->chair >>
	* mc转给chair
	*/
	MESSAGE(Ev_Mtpa_TerApplySpeak_Ntf )
	BODY( mt::TMtId,   tMtid)

	/*<< 主席申请指定发言 chair->mc>>
	*/
	MESSAGE(Ev_Mtpa_Broadcast_Req )
	BODY( mt::TMtId,   tMtid)

	/*<< mc回复是否同意主席指定发言 chair<->mc>>
	*/
	MESSAGE(Ev_Mtpa_Broadcast_Rsp )
	BODY( mt::TBOOL32, bGranted)

	/*<< 主席同意发言chair<->mc>>
	*/
	MESSAGE(Ev_Mtpa_Broadcast_Cmd )
	BODY( mt::TMtId,   tMtid)

	/*<< 主席取消发言chair<->mc>>
	*/
	MESSAGE(Ev_Mtpa_CancelBroadcast_Cmd )
	BODY( mt::TMtId,   tMtid)


	/*<< 被广播通知 mt<-mc>>
	*/
	MESSAGE( Ev_Mtpa_SeenByAll_Ntf )

	/*<< 取消被广播通知 mt<->mc>>
	*/
	MESSAGE( Ev_Mtpa_CancelSeenByAll_Ntf )

	/*<< 发言人位置通知 mt<->mc>>
	*/
	MESSAGE( Ev_Mtpa_Speaker_Ntf ) /////非标的
	BODY( mt::TMtId,   tMtid)

	/*<< 正在观看的视频源通知 mt<->mc>>
	tMtid:  视频源的mt_id
	*/
	MESSAGE( Ev_Mtpa_YouAreSeeing_Ntf ) /////非标的
	BODY(mt::TMtId,     tMtId )
	BODY(mt::TU32,      tChanId ) ////sip可能是多流的， 每一流都会上来，通道id从1开始
   
	/*<<终端申请主席 ter->mc >>
	*/
	MESSAGE( Ev_Mtpa_MakeMeChair_Req )
	
	/*<<mc回复终端申请主席是否成功 mc->ter  >>
	*/
	MESSAGE( Ev_Mtpa_MakeMeChair_Rsp )
	BODY(mt::TBOOL32,  bGranted)

	/*<<终端撤销主席令牌 chiar->mc >>
	*/
	MESSAGE( Ev_Mtpa_WithdrawChair_Cmd )

	/*<<mc撤销主席令牌指示 mc->chair >>
	*/
	MESSAGE( Ev_Mtpa_WithdrawChair_Ntf )
	

	/*<<终端查询主席位置 ter->mc >>
	*/
	MESSAGE( Ev_Mtpa_WhoIsChair_Req )

	/*<<mc回复主席位置 mc->ter >>
	* chair_mtid     :    主席位置
	*/
	MESSAGE( Ev_Mtpa_ChairPos_Rsp )    ///主席位置改变， 应该mc会推这条消息
	BODY(mt::TMtId,   chair_mtid)


	/*<<主席令牌转移，指定主席 chair->mc  >>  //这条也用来回复，是否同意其他终端申请主席
	* chair_mtid     :    主席位置
	*/
	MESSAGE( Ev_Mtpa_ChairTransfer_Req )
	BODY(mt::TMtId,   chair_mtid)
	
	/*<<有终端申请主席  mc->chair >>
	* mtid     :    mtid
	*/
	MESSAGE( Ev_Mtpa_ChairApply_Ntf )
	BODY(mt::TMtId,   mtid)

	/*<<主席选看终端 >>
	*/
	MESSAGE( Ev_Mtpa_SendThisTer_Cmd )
	BODY(mt::TMtId,  tMtid)
	BODY(mt::TU32,   tMediaType) //EmMediaType 

	/*<<主席选看终端结果 >>
	*/
	MESSAGE( Ev_Mtpa_SendThisTer_Rsp )
	BODY(mt::TBOOL32,  bResult)



	/*<<主席取消选看终端 >>
	*/
	MESSAGE( Ev_Mtpa_CancelSendThisTer_Cmd )

	/*<<被选看通知 >>
	*/
	MESSAGE( Ev_Mtpa_SeenByOther_Ntf )
	

	/*<<取消被选看通知 >>
	*/
	MESSAGE( Ev_Mtpa_CancelSeenByOther_Ntf )





	///////////////////////////////////////////非标消息

	
	/*<<终端申请插话 mt->mc >>
	*/
	MESSAGE( Ev_Mtpa_ApplyChiemeIn_Cmd )


	/*<<有终端申请插话 mc->chair >>
	*/
	MESSAGE( Ev_Mtpa_ApplyChimeIn_Ntf )
	

	/*<<主席指定，同意插话 chair->mt >>
	*/
	MESSAGE( Ev_Mtpa_ChiemeIn_Cmd )
	BODY(mt::TMtId,           mtid)

	/*<<终端插话状态 chair->mt >>
	*/
	MESSAGE( Ev_Mtpa_ChimeInState_Ntf )
	BODY(mt::TBOOL32,       bResult)

	/*<<终端插话失败 chair->mt >>
	*/
	MESSAGE( Ev_Mtpa_ChimeFailed_Ntf )
	



	

	/*<<MC请求终端状态 >>
	*/
	MESSAGE( Ev_Mtpa_McGetTerStatus_Req )

	/*<< 终端状态应答 >>
	* Mt_status     :    终端状态
	*/
	MESSAGE( Ev_Mtpa_McGetTerStatus_Rsp)
	BODY(mt::TTerStatus,       Mt_status)             

	/*<< 终端状态应答 >>  用在内置mc，或者点对点
	* Mt_status     :   终端状态
	*/
	MESSAGE( Ev_Mtpa_McTerStatus_Rsp)
	BODY(mt::TTerStatus,   Mt_status)             



	/*<<终端请求其他终端状态 >>
	*/
	MESSAGE( Ev_Mtpa_TerGetTerStatus_Req )
	BODY(mt::TMtId,                 mtid)

	/*<<mc回复主席请求其他终端状态 >>
	*/
	MESSAGE( Ev_Mtpa_TerGetTerStatus_Rsp )
	BODY(mt::TMtId,                 mtid)
	BODY(mt::TTerStatus,      ter_status)



	/*<<MC请求终端视频源应答 >>
	* Mt_Video_alias     :    终端视频源名称
	*/
	MESSAGE( Ev_Mtpa_VideoAlias_Rsp )
	BODY(mt::TRpMtVideoAlias,  video_info)

	/*<<MC请求终端视频源 >>
	*/
	MESSAGE( Ev_Mtpa_VideoAlias_Req )


		/*<<MC请求终端视频源应答 >>
	* Mt_Video_alias     :    终端视频源名称
	*/
	MESSAGE( Ev_Mtpa_TerGetTerAlias_Req )
	BODY(mt::TRpMtVideoAlias,  video_info)

	/*<<MC请求终端视频源 >>
	*/
	MESSAGE( Ev_Mtpa_TerGetTerAlias_Rsp )



	/*<<对端视频源指示 >>
	* peer_info     :    对端终端视频源名称
	*/
	MESSAGE(Ev_Mtpa_PeerVideoAlias_Ntf)
	BODY(mt::TRpMtVideoAlias, peer_info)

	/*<<对端视频源指示 >>
	* tVideo_Src:    对端终端视频源索引
	*/
	MESSAGE( Ev_Mtpa_PeerVideoSrc_Ntf )
	BODY(TRpVideoInfo, tRpVideoInfo)
	

	/*<<发送短消息 >>
	* short_mess     :    短消息
	*/
	MESSAGE( Ev_Mtpa_SMS_Cmd )
	BODY(mt::TShortMsg,  short_msg)

	/*<<短消息提示 >>
	* short_mess     :    短消息
	*/
	MESSAGE( Ev_Mtpa_SMS_Ntf )
	BODY(mt::TShortMsg,  short_msg)

	
	/*<<主席邀请终端 >>
	* tMtaddr     :    终端地址
	*/
	MESSAGE( Ev_Mtpa_ChairInviteTer_Req )   //没有回复
	BODY(mt::TMtAddr,    tMtaddr)

	/*<<主席邀请终端失败 >>
	* tMtaddr     :    终端地址
	*/
	MESSAGE( Ev_Mtpa_ChairInviteFailed_Ntf )   //没有回复
	BODY(mt::TMtAddr,    tMtaddr)
	BODY(mt::TU32,       tReason) //EmMtCallDisReason

	/*<< 会议发生错误 >>
	*/
	MESSAGE( Ev_Mtpa_ConfFailed_Ntf )
	BODY(mt::TU32,      emFailedReason)  //EmMtConfFailureReason

	/*<< 主席呼叫离线终端 >>
	*/
	MESSAGE( Ev_Mtpa_CallOfflineTer_Cmd )
	BODY( mt::TMtId,   mtid)



	/*<<获取会议信息请求 >>
	*/
	MESSAGE( Ev_Mtpa_GetConfInfo_Req )
    
	/*<<获取会议信息回复 >>
	*/
	MESSAGE(Ev_Mtpa_GetConfInfo_Rsp)
	BODY(mt::TMtConfInfo,  conf_info)
	
	/*<<简单会议信息通知 >>
	*/
	MESSAGE(Ev_Mtpa_SimpleConfInfo_Ntf)
	BODY(mt::TMtSimpConfInfo,  simple_conf_info)

	/*<<会议即将结束提示 >>
	*/
	MESSAGE(Ev_Mtpa_ConfWillEnd_Ntf)
	BODY(mt::TU32,      tRemain_minutes)
	
	/*<<会议延长时间请求 >>
	*/
	MESSAGE(Ev_Mtpa_ReqProlong_Req)
	BODY(mt::TU16,      tLongTime)

	/*<<会议延长时间应答 >>
	*/
	MESSAGE(Ev_Mtpa_ReqProlong_Rsp)
	BODY(mt::TBOOL32,      bGranted)

	/*<<修改会议名字 >>
	*/
	MESSAGE(Ev_Mtpa_ModifyConfName_Req)
	BODY(mt::TString,      tName)

	/*<<修改会议密码 >>
	*/
	MESSAGE(Ev_Mtpa_ModifyConfPwd_Req)
	BODY( mt::TBOOL32,     bUsed)
	BODY(mt::TBytes,      tPwd)

	/*<<修改会议双流模式 >>
	*/
	MESSAGE(Ev_Mtpa_ModifyConfDualMode_Req)
	BODY( mt::TU32, emMtDualMode )

	/*<<修改会议持续时间 >>
	*/
	MESSAGE(Ev_Mtpa_ModifyDuration_Req)
	BODY( mt::TU16, wTime )

	/*<<修改会议是否会议哑音 >>
	*/
	MESSAGE(Ev_Mtpa_SetConfDumb_Req)
	BODY( mt::TBOOL32, bDumb )

	/*<<修改会议是否开启免打扰 >>
	*/
	MESSAGE(Ev_Mtpa_SetConfNoDisturb_Req)
	BODY( mt::TBOOL32, bEnable )


	/*<<修改会议画面合成是否显示成员别名 >>
	*/
	MESSAGE( Ev_Mtpa_ModifyVmpShowAlias_Req )
	BODY( mt::TBOOL32, bShow )

	/*<<修改会议属性回复 >>
	*/
	MESSAGE(Ev_Mtpa_ModifyConf_Rsp)
	BODY( mt::EmMtModifyConfInfoType, emModifyType )
	BODY( mt::TBOOL32, bResult )



 	/*对端能力指示*/
 	MESSAGE( Ev_Mtpa_PeerCapabilities_Ntf  ) ///暂时不用了。

	/*mcu通知指示*/
	MESSAGE( Ev_Mtpa_McInfoTer_Ntf  )
	BODY(mt::TU32, tNtfType)//
	BODY(mt::TU16, tBitrate)

	/*mcu调整分辨率*/
	MESSAGE( Ev_Mtpa_McAdjustRes_Ntf  )
	BODY(mt::TU32, chanltype) //EmMtLogChnnlType
	BODY(mt::TU32,        tW)
	BODY(mt::TU32,        tH)
	BODY(mt::TU32, tChanIndex)
	
	/*mcu调整帧率*/ 
	MESSAGE( Ev_Mtpa_McAdjustFps_Ntf  )
	BODY(mt::TU32,        fps)


	///////////////////画面合成和混音的消息


	/*<< 开始语音激励 >>
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_StartVAC_Req )

	/*<< 开始语音激励应答 >>
	* bResult : 结果
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_StartVACResult_Ntf )
	BODY(mt::TBOOL32, bResult)


	/*<< 停止语音激励 >>
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_StopVAC_Req )

	/*<< 停止语音激励结果 >>
	* bResult : 结果
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_StopVACResult_Ntf )
	BODY(mt::TBOOL32, bResult)


	/*<< 开始混音请求 >>
	* tparam : 混音参数
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_StartMix_Req )
	BODY(mt::TMtMixParam, tparam)

	/*<< 开始讨论模式结果 >>
	* bResult : 结果
	* mix_mode : 混音模式
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_StartMixResult_Ntf )
	BODY(mt::TBOOL32, bResult)
	BODY(mt::TU32,    mix_mode) //EmMtMixType


	/*<< 停止讨论模式请求 >>
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_StopMix_Req )

	/*<< 停止讨论模式结果 >>
	* bResult : 结果
	* mix_mode : 混音模式
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_StopMixResult_Ntf )
	BODY( mt::TBOOL32, bResult )
	BODY(mt::TU32,    mix_mode) //EmMtMixType

	/*<< 添加混音成员 >>
	* tmixparam:  多个混音成员
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_MakeTerChimeIn_Cmd )
	BODY(mt::TMtMixParam, tmixparam)

	/*<< 删除混音成员 >>
	* mtid:  终端id
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_RemoveTerChimeIn_Cmd )
	BODY(mt::TMtId, mtid)




	/*<< 开始自动多画面合成请求 >>
	* vmp_param: 画面合成参数
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_StartVMP_Req)
	BODY( mt::TMtVmpParam, vmp_param )

		/*<< 开始自动多画面合成请求 >>
	* vmp_param: 画面合成参数
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_StartCustomVMP_Req)
	BODY( mt::TMtVmpParam, vmp_param )


	/*<< 开始会议画面合成应答 >>
	* bResult : 结果    
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_StartVMPResult_Rsp)
	BODY( mt::TBOOL32,     bResult )

	/*<< 开始自主画面合成应答 >>
	* bResult : 结果    
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_StartCustomVMPResult_Rsp )
	BODY( mt::TBOOL32,     bResult )


	/*<< 停止自动多画面合成请求 >>
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_StopVMP_Req)
	
		/*<< 停止自动多画面合成请求 >>
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_StopCustomVMP_Req)

	/*<< 停止画面合成应答 >> 
	* bResult : 结果
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_StopVMPResult_Rsp)
	BODY(mt::TBOOL32, bResult)

	/*<< 停止自主画面合成应答 >> 
	* bResult : 结果
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_StopCustomVMPResult_Rsp)
	BODY(mt::TBOOL32, bResult)


	/*<< 设置画面合成参数 >>
	* vmp_param: 画面合成参数
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_SetVMPParam_Req )    //只针对科达终端
	BODY( mt::TMtVmpParam, vmp_param)     

	/*<< 设置画面合成参数 >>
	* vmp_param: 画面合成参数
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_SetCustomVMPParam_Req )    //只针对科达终端
	BODY( mt::TMtVmpParam, vmp_param)  

	/*<< 设置画面合成参数应答 >>
	* bResult : 结果
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_SetVMPParamResult_Rsp)
	BODY( mt::TBOOL32,    bResult )

	/*<< 设置画面合成参数应答 >>
	* bResult : 结果
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_SetCustomVMPParamResult_Rsp)
	BODY( mt::TBOOL32,    bResult ) 



	/*<< 开始自动多画面合成应答 >>
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_StartVMPResult_Ntf)  ///mtpa收到sip来的会控，内部用的

	/*<< 开始自动多画面合成应答 >>
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_StopVMPResult_Ntf)  ///mtpa收到sip来的会控，内部用的

	/*<< 开始自动多画面合成应答 >>
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_SetVMPParamResult_Ntf)  ///mtpa收到sip来的会控，内部用的


	/*<< 开始自动多画面合成应答 >>
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_StartCustomVMPResult_Ntf)  ///mtpa收到sip来的会控，内部用的

	/*<< 开始自动多画面合成应答 >>
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_StopCustomVMPResult_Ntf)  ///mtpa收到sip来的会控，内部用的

	/*<< 开始自动多画面合成应答 >>
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_SetCustomVMPParamResult_Ntf)  ///mtpa收到sip来的会控，内部用的



	/*<< 获取画面合成参数 >>
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_GetVMPParam_Cmd )

	/*<< 获取画面合成参数响应 >>
	* vmp_param ： 画面合成参数
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_Mtpa_GetVMPParamResult_Ntf )
	BODY( mt::TMtVmpParam, vmp_param)


	/*<< 混音成员通知 >>
	*/
	MESSAGE(Ev_Mtpa_DiscussParam_Ntf)
	
	/*<< 远端哑音 >>
	* tMtid:  终端id
	* bMute： 是否哑音
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_MakeTerMute_Cmd )
	BODY(mt::TMtId,   tMtId)
	BODY(mt::TBOOL32, bMute)


	/*<< 远端哑音指示 >>
	* tMtid:  终端id
	* bEnable： 
	* 消息流向 ： mt<->mc mc告诉终端哑音的结果
	*/
	MESSAGE( Ev_Mtpa_MakeTerMute_Ntf )
	BODY(mt::TMtId,   tMtId)
	BODY(mt::TBOOL32, bEnable)



	/*<< 远端静音 >>
	* tMtid:  终端id
	* bQuiet： 是否静音
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_MakeTerQuiet_Cmd )
	BODY(mt::TMtId,   tMtId)
	BODY(mt::TBOOL32, bQuiet)

	/*<< 远端静音指示 >>
	* tMtid:  终端id
	* bEnable： 是否静音
	* 消息流向 ： mt<->mc  mc告诉终端静音的结果 
	*/
	MESSAGE( Ev_Mtpa_MakeTerQuiet_Ntf )
	BODY(mt::TMtId,   tMtId)
	BODY(mt::TBOOL32, bEnable)


	/*<< 切换画面合成风格 >>
	* is_multipic: 是否多画面
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_SwitchBroadCastStyle_Cmd )
	BODY(mt::TBOOL32, is_multipic)

	/*<<主席强制广播 >>
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_StartForceBroadcast_Cmd ) 
	
	/*<<主席取消强制广播 >>
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_StopForceBroadcast_Cmd )  


	/*<< 终端（仅限主席MT）选看画面合成请求 >>
	* bStart:  TRUE 选看画面合成，FALSE 取消选看画面合成
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_SelectVmp_Req )
	BODY( mt::TBOOL32, bStart)

	/*<< 终端（仅限主席MT）选看画面合成请求 >>
	* bStart:  TRUE 选看画面合成，FALSE 取消选看画面合成
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_Mtpa_SelectVmp_Rsp )
	BODY( mt::TBOOL32, bResult)


	/*
		Ev_Mtpa_FeccMsg_Ntf, Ev_Mtpa_FeccMsg_Cmd,  fecc远遥命令, fecc的消息， 只是发送到conf，和内置mc, 
		在conf 和内置mc模块内，再转给device模块，用的是 device定义的消息
	*/

	/*<< 远摇信令 >>
	* feccStruct: fecc结构体
	* tDstId:     目的id
	* tSrcId:     源id
	* 消息流向 ：mtpa==>dispatch==>mtmc/mtconf
	*/
	MESSAGE( Ev_Mtpa_FeccMsg_Ntf )
	BODY( mt::TMtFeccMsg,  feccStruct )
	BODY( mt::TMtId  ,     tDstId )
	BODY( mt::TMtId  ,     tSrcId )

	/*<< 远摇信令 >>
	* feccStruct: fecc结构体
	* tDstId:     目的id
	* tSrcId:     源id
	* 消息流向 ：mtmc/mtconf==>dispatch==>mtpa
	*/
	MESSAGE( Ev_Mtpa_FeccMsg_Cmd )
	BODY( mt::TMtFeccMsg,  feccStruct )
	BODY( mt::TMtId  ,     tDstId )
	BODY( mt::TMtId  ,     tSrcId )




	////点名暂时不做， mcs上会用到
	/*<<点名请求 >>
	* tMtId： mtid
	*/
	MESSAGE( Ev_Mtpa_RollCall_Cmd ) //暂时不用
	BODY(mt::TMtId,   tMtId)

// 	/*<<点名请求结果 >>
// 	* tMtid:   mtid
// 	* bResult: 点名结果
// 	*/
// 	MESSAGE( Ev_Mtpa_RollCallResult_Ntf )//暂时不用
// 	BODY(mt::TMtId,   tMtId)
// 	BODY(mt::TBOOL32, bResult)
	
	/*<< 语音终端做发言人显示图片 mc->mt >>
	* tMtid:   mtid
	* bResult: 点名结果
	*/
	MESSAGE( Ev_Mtpa_VoiceSpeaker_Cmd )
	BODY(mt::TBOOL32,   is_voice_speaker)

	MESSAGE( Ev_Mtpa_SetStaticNet_Cmd ) ///暂时设置到323协议栈
	MESSAGE( Ev_Mtpa_SetQos_Cmd )      //设置到323协议栈
	
	MESSAGE( Ev_Mtpa_RemoteLoop_Cmd ) ///远端自环 开始/停止
	BODY(mt::TBOOL32,   bStart)

	MESSAGE( Ev_Mtpa_RemoteLoop_Ntf) //远端自环状态提示
	BODY(mt::TBOOL32,   bStart)


	MESSAGE( Ev_Mtpa_ConfDelay_Ntf) ///会议延长提示
	BODY(mt::TU16,    delay_time)

	////会议剩余时间
	MESSAGE( Ev_Mtpa_ConfRestTime_Ntf ) 
	BODY(mt::TU16,    rest_time)

	////只有h323会发这条上去， 收到对端能集后，是否支持音视频通道
	MESSAGE( Ev_Mtpa_NotifyConfType_Ntf)
	BODY(mt::TU32,   emMtConfType)
	BODY(mt::TU16,   bitrate)

	MESSAGE( Ev_Mtpa_StackInitFailedReason_Ntf )
	BODY(mt::TU32,   emProtocol)
	BODY(mt::TU32,   emStackInitFailReason)

	MESSAGE( Ev_Mtpa_DualStreamSender_Ntf )
	BODY(mt::TMtId,   tMtid)
	BODY(mt::TBOOL32, tGrabbed)///是否被抢发 

	MESSAGE( Ev_Mtpa_StackOnOff_Cmd )  
	BODY(mt::TU32,    emProtocol) //协议
	BODY(mt::TBOOL32, bStart) //start/stop

	MESSAGE( Ev_Mtpa_SetStack_Cmd )  
	BODY(mt::TU32,    emProtocol) //协议
	BODY(mt::TBOOL32, bStand)     //start/stop

	/*<<主席指定vip列表 chair->mc >>
	* mt_id :  指定终端的列表
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_Mtpa_ChairSpecVip_Req ) //非标
	BODY(mt::TRpMtId, mt_id)


	/*<<mc回应主席指定vip列表 chair<-mc >>
	* tResult :  是否同意
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_Mtpa_McRspChairVip_Rsp ) //非标
	BODY(mt::TBOOL32, tResult)

	/*<<mc通知终端当前vip列表 ter<-mc >>
	* mt_id :  指定终端的列表
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_Mtpa_McInfoTerVip_Ntf ) //非标
	BODY(mt::TRpMtId, mt_id)

	/////白板会议创建通知
	MESSAGE( Ev_Mtpa_DataConfCreatedNtf_Cmd )
	BODY(mt::TString, conf_name) //白板会议名字

	///加入白板会议命令 用在点对点
	MESSAGE( Ev_Mtpa_JoinDataConf_Cmd )
	BODY(mt::TString, conf_name) //白板会议名字

	///收到对端的加入白板会议命令 或者mcu, 或者对端
	MESSAGE( Ev_Mtpa_JoinDataConf_Ntf )
	BODY(mt::TString, conf_name)  //白板会议名字

	///mc请求终端发/关 双流
	MESSAGE( Ev_Mtpa_McReqTerSendAss_Cmd )
	BODY(mt::TBOOL32, tStart)  //发/关
	
	///暂时用在sip 多流通知对端 当前的通道名字
	MESSAGE( Ev_Mtpa_NotifyPeerLocAlias_Cmd )
	BODY( mt::TRpMtLoc, tRpMtLoc )

	///指定选看某终端某通道 用在多流
	MESSAGE( Ev_Mtpa_SelectViewChan_Cmd )
	BODY( mt::TMtId, tMtid )
	BODY( mt::TU32,  viewtype )
	BODY( mt::TU32,  viewchan )


	///取消选看某一路选看
	MESSAGE( Ev_Mtpa_CacelSelecttViewChan_Cmd )
	BODY( mt::TU32,  viewtype )
	BODY( mt::TU32,  viewchan )


	/*<<设置Conf 发送通道地址参数>>   用在内置mc
	*codec_type       ：通道类型标识
	*encoder_id       ：通道索引标识
	*rtp_local_addr   ：发送rtp包的本地地址
	*rtcp_local_addr  ：发送接收rtcp包的本地地址
	*rtp_remote_addr  ：发送rtp包的远端目的地址
	*rtcp_remote_addr ：发送rtcp包的远端目的地址
	*消息流向 ：mtmc==>dispatch==>mtconf
	*/
    MESSAGE(Ev_Mtpa_ConfSetChanSndAddr_Cmd)
	BODY(mt::TS32, chan_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmMtChanType
	BODY(mt::TS32, chan_idx) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmBitStreamIndex
	BODY(mt::TNetAddr, rtp_local_addr)
	BODY(mt::TNetAddr, rtcp_local_addr)
	BODY(mt::TNetAddr, rtp_remote_addr)
	BODY(mt::TNetAddr, rtcp_remote_addr)	

	/*<<设置Conf  接收通道地址参数>>
	*codec_type       ：通道类型标识
	*encoder_id       ：通道索引标识
	*rtp_local_addr   ：接收rtp包的本地地址
	*rtcp_local_addr  ：接收rtcp包的本地地址
	*rtp_remote_addr  ：发送打动包的远端地址，端口为0表示不发送打动包，否则发送打动包
	*rtcp_remote_addr ：发送rtcp包的远端目的地址，也即解码器的backrtcp地址
	*消息流向 ：service==>dispatch==>mtmp
	*/
    MESSAGE(Ev_Mtpa_ConfSetChanRcvAddr_Cmd)
	BODY(mt::TS32, chan_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmMtChanType
	BODY(mt::TS32, chan_idx) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmBitStreamIndex	
	BODY(mt::TNetAddr, rtp_local_addr)
	BODY(mt::TNetAddr, rtcp_local_addr)
	BODY(mt::TNetAddr, rtp_remote_addr)
	BODY(mt::TNetAddr, rtcp_remote_addr)


	/*<<主席指定终端发双流 chair->mc >>
	* mt_id :  终端的id
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_Mtpa_ChairSpecTerSendAss_Cmd )
	BODY(mt::TMtId, mt_id)


	/*<<终端设置FeccStreamId >>
	* e164 :        终端的e164号	
	* dwStreamid :  非标streamid
	* bSnd :        是否是发送通道
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_Mtpa_FeccStreamId_Cmd )
	BODY(mt::TMtConfHandle, tHander)
	BODY(mt::TString, e164 )
	BODY(mt::TU32,    dwStreamid)
	BODY(mt::TBOOL32,  bSnd)

	////设置dtmf密码
	MESSAGE(Ev_Mtpa_PasswordDtmf_Cmd)
	BODY(mt::TString, tPwd)

	///mc设置音量
	MESSAGE(Ev_Mtpa_McSetAudioVolume_Cmd)
	BODY(mt::TBOOL32, tVolout)
	BODY(mt::TU32,    tVolume)

	/////非标fecc
	MESSAGE( Ev_Mtpa_NonStandFecc_Ntf)
	BODY(mt::TBytes, tBytes)

	/////主流关闭通知
	MESSAGE( Ev_Mtpa_PrimoVideoOff_Ntf)
	BODY(mt::TBytes, tBytes)


	/*<<MC请求终端的丢包率 >>
	*/
	MESSAGE( Ev_Mtpa_McReqLossRate_Cmd )

	/*<<MT回复Mc终端丢包率 >>
	*/
	MESSAGE( Ev_Mtpa_MtRspMcLossRate_Ntf ) 
	BODY(mt::TMtTerLossRate,    tLoseRate) 

	/*<<对端带宽通知>>
	*/
	MESSAGE( Ev_Mtpa_PeerBandWidth_Ntf)
	BODY(mt::TU16, recv_bitrate)
	BODY(mt::TU16, send_bitrate)

	/*<<上报 本端带宽>>
	*/
	MESSAGE( Ev_Mtpa_NotifyPeerBandWidth_Cmd)
	BODY(mt::TU16, recv_bitrate)
	BODY(mt::TU16, send_bitrate)

	////设置通道打洞
	MESSAGE( Ev_Mtpa_SetNatTraversal_Cmd )
	BODY(mt::TMtConfHandle, tHander)

	///终端支持Fec
	MESSAGE( Ev_Mtpa_TerSendFecToPeer_Cmd )
	BODY(mt::TBOOL32,  bSupport )

	///终端支持Fec
	MESSAGE( Ev_Mtpa_PeerIsSupportFec_Ntf )
	BODY(mt::TBOOL32,  bSupport )


	///通知上层开通道完毕
	MESSAGE( Ev_Mtpa_ChanConnectedEnd_Ntf )	

	MESSAGE( Ev_Mtpa_SetH323Tos_Cmd )
	BODY(mt::TU8,  tTosValue )

	MESSAGE( Ev_Mtpa_SetFeccTos_Cmd )
	BODY(mt::TU8,  tTosValue )

	/*<<MC请求终端的实时信息 >>
	*/
	MESSAGE( Ev_Mtpa_McGetMtRealtimeInfo_Cmd )
	BODY(mt::TBytes, tInfoType)

#if !defined(_MESSAGE_HELP_)
	EV_END(MTPA) = EVSEG_MTPA_END
};
#endif

#define Is_Mtpa_Msg(m) ((m) >= EV_BGN(MTPA) && (m) <= EV_END(MTPA))

#endif