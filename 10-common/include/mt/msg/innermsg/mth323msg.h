#ifndef _H323MSG_H_
#define _H323MSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMtH323Msg
{

	//会议子系统用到的所有的消息都在这里， 这里需要区分，mtconf模块， mth323用到的， 内置mc用到的消息。
	EV_BGN(H323) = EVSEG_H323_BGN,
#endif
	
	/*
    mth323--------------------->stackout  
	        Ev_H323_XXX_Cmd      
    mth323<--------------------stackin/stackout
            Ev_H323_XXXX_Ntf
	
	*/
	

	/*<< 协议栈启动 >>
	* 消息流向 ：stackin ==> stackin
	*/
	MESSAGE( Ev_H323_StackRuning_Cmd )

	/*<< 创建新呼叫 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：mth323service ==> stackout
	*/
	MESSAGE( Ev_H323_NewCall_Cmd )
	BODY( mt::TH323StackHandle, tHandle)

	/*<< 发出新呼叫 >>
	* tHandle:    协议栈句柄
	* tCallParam：协议栈呼叫参数
	* 消息流向 ：mth323service ==> stackout
	*/
	MESSAGE( Ev_H323_MakeCall_Cmd )
	BODY( mt::TH323StackHandle, tHandle)
	BODY( mt::TBytes,  tCallParam)  //TCALLPARM


	/*<< 发出新呼叫 >>
	* tHandle:     协议栈句柄
	* hangup_reason：挂断原因
	* 消息流向 ：mth323service ==> stackout
	*/
	MESSAGE( Ev_H323_HangupCall_Cmd )
	BODY( mt::TH323StackHandle, tHandle)
	BODY( mt::TU32,  hangup_reason)


	/*<< 接受新呼叫 >>
	* tHandle:     协议栈句柄
	* tCallParam： 协议栈呼叫参数
	* 消息流向 ：mth323service ==> stackout
	*/
	MESSAGE( Ev_H323_AcceptCall_Cmd )
	BODY( mt::TH323StackHandle, tHandle)
	BODY( mt::TBytes,  tCallParam) //TNODEINFO


	/*<< 新呼叫到来 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_NewCall_Ntf )
	BODY( mt::TH323StackHandle, tHandle)

	/*<< 460newcall >>
	* 当收到sci消息，被叫端需要发460call到对端，主动发tcp链接到对端，但这是需要先newcall, 后续对端真正setup时，不会有newcall上来
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_460NewCall_Ntf )
	BODY( mt::TH323StackHandle, tHandle)


	/*<< callincoming >>
	* tHandle:  协议栈句柄
	* tCallParam: 协议栈呼叫参数
	* 消息流向 ：stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_CallIncoming_Ntf)
	BODY( mt::TH323StackHandle, tHandle)
	BODY( mt::TBytes,   tCallParam) //TCALLPARM

	/*<< 呼叫connected >>
	* tHandle:  协议栈句柄
	* tCallParam: 协议栈呼叫参数
	* 消息流向 ：stackin==>mth323service
	*/
	MESSAGE( Ev_H323_CallConnected_Ntf)
	BODY( mt::TH323StackHandle, tHandle)
	BODY( mt::TBytes,  tCallParam) //TNODEINFO

	/*<< 呼叫disconnected >>
	* tHandle:  协议栈句柄
	* tCallParam: 呼叫参数
	* 消息流向 ：stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_CallDisconnected_Ntf )
	BODY( mt::TH323StackHandle, tHandle)
	


	///ras相关

	/*<< sci消息 >>
	* tSciinfo: sci消息体
	* 消息流向 ：stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasSci_Ntf)
	BODY( mt::TBytes, tSciinfo)    //TSCIINFO

	/*<< scr消息 >>
	* tSciinfo: sci消息体
	* 消息流向 ：stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasScr_Cmd)
	BODY( mt::TBytes, tScr)    //TSCIINFO



	/*<< 注册请求 >>
	* reg_info: 注册是否成功
	* rcf_info  rcf_info
	* 消息流向 ：stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasRrq_Req)
	BODY( mt::TBytes, tRrq )    //TRRQINFO
 	
	/*<< 注册结果 >>
	* tHandle:  协议栈句柄
	* reg_info: 注册是否成功
	* rcf_info  rcf_info
	* 消息流向 ：stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasGKState_Rsp )
	BODY(mt::TGkRegInfo, reg_info)
	BODY(mt::TMtRCFInfo, rcf_info)


	/*<< ucf通知 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasUCF_Ntf )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< urj通知 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasURJ_Ntf )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< Urq通知 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasUrq_Req ) 


	/*<< acf通知 >>
	* tHandle:  协议栈句柄
	* acf_info: acf结果
	* 消息流向 ：stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasACF_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY(mt::TMtACFInfo, acf_info)

	/*<< arj通知 >>
	* tHandle:  协议栈句柄
	* acf_info: acf结果
	* 消息流向 ：stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasARJ_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY(mt::TU32, failed_reason)
	
	/*<< drq通知 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasDRQ_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	
	/*<< ucf通知 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasDCF_Ntf )
	BODY( mt::TH323StackHandle, tHandle )

	

	/*<< arq请求 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasArq_Req) 


	/*<< drq通知 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasDrq_Req) 


	MESSAGE( Ev_H323_RasConfDetailInfo_Req )
	BODY( mt::TBytes,   tNSMinfo)   //TNSMINFO

	MESSAGE( Ev_H323_RasConfDetailInfo_Rsp )
	BODY( mt::TBytes,   tNSMinfo)   //TNSMINFO

	MESSAGE( Ev_H323_RasRoomNum_Req )
	BODY( mt::TBytes,   tNSMinfo)   //TNSMINFO

	MESSAGE( Ev_H323_RasRoomNum_Rsp )
	BODY( mt::TBytes,   tNSMinfo)   //TNSMINFO


	MESSAGE( Ev_H323_RasJoinConf_Req )
	BODY( mt::TBytes,        tNSMinfo)   //TNSMINFO
	
	MESSAGE( Ev_H323_RasJoinConf_Rsp )
	BODY( mt::TBytes,        tNSMinfo)   //TNSMINFO

	MESSAGE( Ev_H323_RasCreateConf_Req )
	BODY( mt::TBytes,        tNSMinfo)   //TNSMINFO

	MESSAGE( Ev_H323_RasCreateConf_Rsp )
	BODY( mt::TBytes,        tNSMinfo)   //TNSMINFO


	MESSAGE( Ev_H323_RasConfList_Req )
	BODY( mt::TBytes,        tNSMinfo)   //TNSMINFO

	MESSAGE( Ev_H323_RasConfList_Rsp )
	BODY( mt::TBytes,        tNSMinfo)   //TNSMINFO

	MESSAGE( Ev_H323_RasGKRegMtListInfo_Req )
	BODY( mt::TBytes,        tNSMinfo)   //TNSMINFO

	MESSAGE( Ev_H323_RasGKRegMtListInfo_Rsp )


	/* chan 消息*/
	//chan消息应该在[Ev_H323_ChanBegin, Ev_H323_ChanEnd]
	MESSAGE( Ev_H323_ChanBegin)

	/*<< 接收新通道到来命令 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackin==>mth323service
	*/
	MESSAGE( Ev_H323_ChanIncomingNew_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	
	/*<< 新创建发送通道命令 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout<==mth323service
	*/
	MESSAGE( Ev_H323_ChanOutgoingNew_Cmd )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< 发送新通道到来命令 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout==>mth323service
	*/
	MESSAGE( Ev_H323_ChanOutgoingNew_Ntf )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< 通道请求 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout<==>mth323service
	*/
	MESSAGE( Ev_H323_ChanOpen_Req )
	BODY( mt::TH323StackHandle, tHandle )


	/*<< 通道应答 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout<==>mth323service
	*/
	MESSAGE( Ev_H323_ChanOpenAck_Rsp )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< 通道应答拒绝 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout<==>mth323service
	*/
	MESSAGE( Ev_H323_ChanOpenReject_Rsp )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< 关闭通道 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout<==>mth323service
	*/
	MESSAGE( Ev_H323_ChanClose_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	

	/*<< 激活接收通道状态 >>
	* tHandle:  协议栈句柄
	* bActive:  通道状态
	* 消息流向 ：stackout<==>mth323service
	*/
	MESSAGE( Ev_H323_ChanActive_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBOOL32, bActive )

	/*<< 图像更新命令 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout<==>mth323service
	*/
	MESSAGE( Ev_H323_ChanVCU_Cmd )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< 流量控制命令 >>
	* tHandle:  协议栈句柄
	* dwBitrate: 码率
	* 消息流向 ：stackout<==>mth323service
	*/
	MESSAGE( Ev_H323_ChanFlowCtrl_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TU16,           wBitrate )


	/*<< chan connected >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackin==>mth323service
	*/
	MESSAGE( Ev_H323_ChanConnected_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	

	/*<< chan release>>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackin==>mth323service
	*/
	MESSAGE( Ev_H323_ChanRelease_Ntf )
	BODY( mt::TH323StackHandle, tHandle )


	/*<< 获取动态载荷 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackin==>mth323service
	*/
	MESSAGE( Ev_H323_ChanDynamicPayload_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TU8,           byDynamicPT)

	/*<<  获取加密同步参数 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackin==>mtH323service
	*/
	MESSAGE( Ev_H323_ChanEncryptSync_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,           tEncryptSync) //TEncryptSync

	/*<<  获取逻辑通道参数 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackin==>mth323service
	*/
	MESSAGE( Ev_H323_ChanParam_Ntf)
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,           tEncryptSync) //TChanParam

	/*<< 得到对端RTP地址     NETADDR >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackin==>mth323service
	*/
	MESSAGE( Ev_H323_ChanSetRTPAddr_Ntf )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< 得到对端RTCP地址     NETADDR >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackin==>mth323service
	*/
	MESSAGE( Ev_H323_ChanSetRTCPAddr_Ntf )
	BODY( mt::TH323StackHandle, tHandle )


	/*<< 得到460打洞地址     NETADDR >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackin==>mth323service
	*/
	MESSAGE( Ev_H323_ChanSetKeepAliveAddr_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	
	
	/*<< 远摇信令 >>*/
	MESSAGE( Ev_H323_ChanFecc_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TMtFeccMsg,  feccStruct )
	BODY( mt::TMtId  ,     tDstId )
	BODY( mt::TMtId  ,     tSrcId )

	MESSAGE(Ev_H323_ChanEnd)

	/*<< roundtrip命令 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout/stackin<==mth323service
	*/
	MESSAGE( Ev_H245_RoundTrip_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TU32,   dwroundtrip_delay)

	/*<< roundtrip回复 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H245_RoundTrip_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TS32,   dwroundtrip_delay)

	/*<< 245链建立 >>
	* tHandle:  协议栈句柄
	* tcp_addr: 地址用于手机，后续建立通道时填写的本地地址
	* 消息流向 ：stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H245_TcpConnected_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TNetAddr,      tcp_addr)

	/*<< 主从决定命令 >>
	* tHandle:  协议栈句柄
	* t_ramdom_value: 主从决定随机值
	* t_TerType:     终端类型值
	* 消息流向 ：stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H245_MasterSlave_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TU32,        tTerType )
	BODY( mt::TU32,        tRamdom_value)


	/*<< 主从决定结果 >>
	* tHandle:  协议栈句柄
	* tResult:  主从决定结果
	* 消息流向 ：stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H245_MasterSlaveResult_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TU32,             tResult )
	
	/*<< 进入通道打开模式 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H245_ChanEntryMode_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	
	/*<< 能力集 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout/stackin<==>mth323service
	*/
	MESSAGE( Ev_H245_CapNotify_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
    BODY( mt::TBytes, tCapset)	

	/*<< 能力集同意或拒绝 >>
	* tHandle:  协议栈句柄
	* bAccept:  是否同意
	* 消息流向 ：stackout/stackin<==>mth323service
	*/
	MESSAGE( Ev_H245_CapCese_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBOOL32,           bAccept)

	MESSAGE( Ev_H245_MccStart_Ntf )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< 请求终端列表 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout<==mth323service
	*/
	MESSAGE( Ev_H245_TerList_Req )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< 请求终端列表 >>
	* tHandle:  协议栈句柄
	* terIdList: 列表list
	* 消息流向 ：stackin==>mth323service
	*/
	MESSAGE( Ev_H245_TerList_Rsp)
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,        terIdList  )   //TTERLABEL

	
	/*<< 请求终端列表 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout<==mth323service
	*/
	MESSAGE( Ev_H245_OffLineTerList_Req )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< 请求终端列表 >>
	* tHandle:  协议栈句柄
	* terIdList: 列表list
	* 消息流向 ：stackin==>mth323service
	*/
	MESSAGE( Ev_H245_OffLineTerList_Rsp)
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,        terIdList  )   //TTERLABEL


	/*<< mcu分配终端编号 >>
	* tHandle:  协议栈句柄
	* terminalId:  终端id
	* 消息流向 ：stackout/stackin<==>mth323service
	*/
	MESSAGE( Ev_H245_AssignTerId_Ntf)
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,       terminalId  )   //TTERLABEL


	MESSAGE( Ev_H239_Message_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,           t239Info)

	MESSAGE( Ev_H239_Message_Ntf )  
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,           t239Info)

	

	/*<< 终端请求当前列表所有终端名字 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout<==mth323service
	*/
	MESSAGE( Ev_H245_TerGetAllTerName_Req )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< mc回复当前列表所有终端名字 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout<==mth323service
	*/
	MESSAGE( Ev_H245_TerGetAllTerName_Rsp )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,          pbyBuf)     //多个TTERINFO tTerInfo

	/*<< mc请求当前终端名字 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackin==>mth323service
	*/
	MESSAGE( Ev_H245_McGetTerName_Req )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< 终端回复mc当前的名字 >>
	* tHandle:  协议栈句柄
	* tbytes ：　终端的名字
	* 消息流向 ：stackin==>mth323service
	*/
	MESSAGE( Ev_H245_McGetTerName_Rsp )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,         tbytes)  //TTERINFO

	/*<< 终端请求另一个终端的名字 >>
	* tHandle:  协议栈句柄
	* tbytes ： TTERLABEL
	* 消息流向 ：stackin==>mth323service
	*/
	MESSAGE(Ev_h245_TerGetOtherTerName_Req)
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TMtId,            tMtid)  

	/*<< mc回应 另一个终端的名字 >>
	* tHandle:  协议栈句柄
	* tbytes ： TTERINFO
	* 消息流向 ：stackin==>mth323service
	*/
	MESSAGE(Ev_h245_TerGetOtherTerName_Rsp)
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,            tbytes)  //TTERINFO


	/*<< 终端加入会议 >>
	* tHandle:  协议栈句柄
	* tMtid ：　终端id
	* 消息流向 ：stackin==>mth323service
	*/
	MESSAGE( Ev_H245_TerJoined_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TMtId,           tMtid)  //TTERLABEL


	/*<< 终端离开会议 >>
	* tHandle:  协议栈句柄
	* tMtid ：　终端id
	* 消息流向 ：stackin==>mth323service
	*/
	MESSAGE( Ev_H245_TerLeft_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TMtId,           tMtid)  //TTERLABEL


	/*<< 强制终端退出 >>
	* tHandle:  协议栈句柄
	* tMtId ：　终端id
	* 消息流向 ：stackout<==mth323service
	*/
	MESSAGE( Ev_H245_DropTer_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TMtId,            tMtid)  

	/*<< 强制终端退出失败 >>
	* tHandle:  协议栈句柄
	*/
	MESSAGE( Ev_H245_DropTerReject_Ntf )
	BODY( mt::TH323StackHandle, tHandle )



	/*<< 强制结束会议 >>
	* tHandle:  协议栈句柄
	*/
	MESSAGE( Ev_H245_EndConf_Cmd )
	BODY( mt::TH323StackHandle, tHandle )

	/*<<mc请求会议密码 >>
	* tHandle:  协议栈句柄
	*/
	MESSAGE( Ev_H245_Password_Req )
	BODY( mt::TH323StackHandle, tHandle )
	
	/*<<终端回复会议密码 >>
	* tHandle:  协议栈句柄
	* tbytes：  会议密码
	*/
	MESSAGE( Ev_H245_Password_Rsp )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,           tbytes)  //TPassRsp




	/*<< 终端申请发言 mt<->mc>>
	*  终端申请，mc收到申请都是这个消息
	*/
	MESSAGE( Ev_H245_ApplyMcSpeak_Req )

	/*<< 终端申请发言 mc->chair >>
	* note：  mc转给chair
	*/
	MESSAGE( Ev_H245_TerApplySpeak_Ntf )
	BODY( mt::TMtId,   tMtid)

	/*<< mc回复是否同意发言 mc->chair >>
	* bGranted: 是否同意
	*/
	MESSAGE(Ev_H245_Broadcast_Rsp )
	BODY( mt::TBOOL32,   bGranted)

	/*<< 主席申请指定发言 chair -mc>>
	*/
	MESSAGE(Ev_H245_Broadcast_Req )
	BODY( mt::TMtId,   tMtid)

	/*<< 主席同意发言>>
	*/
	MESSAGE(Ev_H245_Broadcast_Cmd )
	BODY( mt::TMtId,   tMtid)

	/*<< 主席取消发言>>
	*/
	MESSAGE(Ev_H245_CancelBroadcast_Cmd )
	BODY( mt::TMtId,   tMtid)


	/*<< 广播源指示mc<->mt >>
	*/
	MESSAGE(Ev_H245_SeenByAll_Ntf )


	/*<< 取消广播源指示mc<->mt >>
	*/
	MESSAGE(Ev_H245_CancelSeenByAll_Ntf )

	/*<< 发言人位置指示mc<->mt >>     ///非标的
	*/
	MESSAGE( Ev_h245_Speaker_Ntf )

	/*<< 视频源mc<->mt >>
	*/
	MESSAGE( Ev_h245_YouAreSeeing_Ntf)
	

	/*<< 终端申请主席 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout<==mth323service
	*/
	MESSAGE( Ev_H245_MakeMeChair_Req )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< 终端申请主席应答 >>
	* tHandle:  协议栈句柄
	* tResult:  是否同意
	* 消息流向 ：stackout<==mth323service
	*/
	MESSAGE( Ev_H245_MakeMeChair_Rsp )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBOOL32,          tResult )

	/*<< 撤销主席令牌 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout<==mth323service
	*/
	MESSAGE( Ev_H245_WithdrawChair_Cmd )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< 主席撤销指示 >>
	*/
	MESSAGE( Ev_H245_WithdrawChair_Ntf )

	/*<< 有终端申请主席 >>
	*/
	MESSAGE( Ev_H245_ChairApply_Ntf )
	

	/*<< 终端请求当前主席位置 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout<==mth323service
	*/
	MESSAGE( Ev_H245_WhoIsChair_Req )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< mc回复当前主席位置 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout<==mth323service
	*/
	MESSAGE( Ev_H245_Chair_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,          pbyBuf)     //TTERINFO tTerInfo

	/*<< 主席选看 >>*/
	MESSAGE( Ev_H245_SendThisTer_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,            pbyBuf)     //TTERLABEL

	/*<< 主席选看应答 >>*/
	MESSAGE( Ev_H245_SendThisTer_Rsp )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBOOL32,          bResult)     //bResult


	/*<< 主席取消选看 >>*/
	MESSAGE( Ev_H245_CancelSendThisTer_Cmd )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< 提示被选看 >>*/
	MESSAGE( Ev_H245_SeenByOther_Ntf )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< 提示取消被选看 >>*/
	MESSAGE( Ev_H245_CancelSeenByOther_Ntf )
	BODY( mt::TH323StackHandle, tHandle )


	/////////////////////////////////////////下面是非标的
	
	/*<< 终端申请插话mt->mc >>*/
	MESSAGE( Ev_H245_ChairTransfer_Req )
	BODY( mt::TH323StackHandle, tHandle )	
	

	/*<< 终端申请插话mt->mc >>*/
	MESSAGE( Ev_H245_ApplyChiemeIn_Req )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< 有终端申请插话 mc->chair >>*/
	MESSAGE( Ev_H245_ApplyChimeIn_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,            tbytes)     //TTERLABEL


	/*<< 同意插话 chair->mc >>*/
	MESSAGE( Ev_H245_ChiemeIn_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,            tbytes)     //TTERLABEL

	/*<< 终端插话状态 mc->ter >>*/
	MESSAGE( Ev_H245_ChimeInState_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,            tbytes)     //BOOL32

	/*<< 插话失败 mc->ter >>*/
	MESSAGE( Ev_H245_ChimeFailed_Ntf )
	BODY( mt::TH323StackHandle, tHandle )


	/*<< 非标主席选看 >>*/
	MESSAGE( Ev_H245_ChairView_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,            tbytes)     //TTERLABEL+mediaType
	
	/*<< 非标主席选看某一路 >>*/
	MESSAGE( Ev_H245_ChairViewChan_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,            tbytes)     //

	/*<< 非标主席取消选看某一路 >>*/
	MESSAGE( Ev_H245_CancelChairViewChan_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,            tbytes)     //
	
	/*<< 对端视频源名称提示 >>
	* tHandle:  协议栈句柄
	* alias:    对端名称
	* 消息流向 ：stackout/stackin<==>mth323service
	*/
	MESSAGE( Ev_H245_PeerVideoAlias_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,           alias)

	/*<< 对端请求视频源名称 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout/stackin<==>mth323service
	*/
	MESSAGE( Ev_H245_VideoAlias_Req )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< 视频源名称响应 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout/stackin<==>mth323service
	*/
	MESSAGE( Ev_H245_VideoAlias_Rsp )
	BODY( mt::TH323StackHandle, tHandle )
	

	/*<< 主席请求mc对端请求视频源名称 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout/stackin<==>mth323service
	*/
	MESSAGE( Ev_H245_TerGetTerVideoAlias_Req )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< mc回复主席  >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout/stackin<==>mth323service
	*/
	MESSAGE( Ev_H245_TerGetTerVideoAlias_Rsp )
	BODY( mt::TH323StackHandle, tHandle )



	/*<< mc请求终端状态 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout/stackin<==>mth323service
	*/
	MESSAGE( Ev_H245_McTerStatus_Req )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< 终端状态回应 >>
	* tHandle:  协议栈句柄
	* 消息流向 ：stackout/stackin<==>mth323service
	*/
	MESSAGE( Ev_H245_McTerStatus_Rsp )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,      tTerStatus)  //TTerStatus


	/*<< 主席请求终端状态 >>
	*/
	MESSAGE( Ev_H245_TerGetTerStatus_Req )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,      ter_id)  //TMtid
	
	/*<< mc应答终端状态 >>
	*/
	MESSAGE( Ev_H245_TerGetTerStatus_Rsp )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,      ter_id)  //TMtid



	MESSAGE( Ev_H245_SMS_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,          pbyBuf)  

	/*<< 获取会议信息请求 >>
	*/
	MESSAGE( Ev_h245_ConfInfo_Req )

	/*<< 获取会议信息应答 >>
	*/
	MESSAGE( Ev_h245_ConfInfo_Rsp )

	/*<< 获取简单会议信息 >>
	*/
	MESSAGE( Ev_h245_SimpleConfInfo_Ntf )

	/*<< 终端带宽通知 >>
	*/
	MESSAGE( Ev_h245_terBandWidth_Ntf )

	/*会议即将结束*/
	MESSAGE( Ev_h245_ConfWillEnd_Ntf )

	/*请求延长会议时间*/
	MESSAGE( Ev_h245_ReqProlong_Req )

	/*应答延长会议时间*/
	MESSAGE( Ev_h245_ReqProlong_Rsp )

	/*邀请终端*/
	MESSAGE( Ev_h245_ChairInviteTer_Req )
	
	/*邀请终端失败*/
	MESSAGE( Ev_h245_ChairInviteFailed_Ntf )

	/*会议发生错误*/
	MESSAGE( Ev_h245_ConfFailed_Ntf)

	/*呼叫离线终端*/
	MESSAGE( Ev_h245_CallOfflineTer_Cmd)

	/*修改会议属性*/
	MESSAGE( Ev_h245_ModifyConf_Req)

	/*修改会议属性*/
	MESSAGE( Ev_h245_ModifyConf_Rsp)

	/*对端能力指示*/
	MESSAGE( Ev_h245_PeerCapabilities_Ntf  )
	
	/*mcu通知指示*/
	MESSAGE( Ev_h245_McInfoTer_Ntf  )

	/*mcu调整分辨率*/
	MESSAGE( Ev_h245_McAdjustRes_Ntf  )

	/*mcu调整帧率*/
	MESSAGE( Ev_h245_McAdjustFps_Ntf  )

	/*mcu调整第一路帧率*/
	MESSAGE( Ev_h245_McAdjustMainVideoFps_Ntf  )

	////////////画面合成， 混音

	/*<< 开始语音激励 >>
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_h245_StartVAC_Req )

	/*<< 开始语音激励应答 >>
	*/
	MESSAGE( Ev_h245_StartVACResult_Ntf )



	/*<< 停止语音激励 >>
	*/
	MESSAGE( Ev_h245_StopVAC_Req )

	/*<< 停止语音激励结果 >>
	*/
	MESSAGE( Ev_h245_StopVACResult_Ntf )


	/*<< 开始讨论模式请求 >>
	*/
	MESSAGE( Ev_h245_StartMix_Req )

	/*<< 开始讨论模式结果 >>
	*/
	MESSAGE( Ev_h245_StartMixResult_Ntf )
	

	/*<< 停止讨论模式请求 >>
	*/
	MESSAGE( Ev_h245_StopMix_Req )

	/*<< 停止讨论模式结果 >>
	*/
	MESSAGE( Ev_h245_StopMixResult_Ntf )

	/*<< 开始自动多画面合成请求 >>
	*/
	MESSAGE( Ev_h245_StartVMP_Req)

	/*<< 开始自动多画面合成应答 >>
	*/
	MESSAGE( Ev_h245_StartVMPResult_Ntf )

	/*<< 开始自动多画面合成应答 >>
	*/
	MESSAGE( Ev_h245_StartVMPResult_Rsp )


	/*<< 停止自动多画面合成请求 >>
	*/
	MESSAGE( Ev_h245_StopVMP_Req)

	
	/*<< 停止自动多画面合成应答 >>
	*/
	MESSAGE( Ev_h245_StopVMPResult_Ntf)

	/*<< 停止自动多画面合成应答 >>
	*/
	MESSAGE( Ev_h245_StopVMPResult_Rsp )

	/*<< 设置画面合成参数 >>
	*/
	MESSAGE( Ev_h245_SetVMPParam_Req )     //只针对科达终端

	/*<< 设置画面合成参数应答 >>
	*/
	MESSAGE( Ev_h245_SetVMPParamResult_Ntf)

	/*<< 设置画面合成参数应答 >>
	*/
	MESSAGE( Ev_h245_SetVMPParamResult_Rsp)

	/*<< 获取画面合成参数 >>
	*/
	MESSAGE( Ev_h245_GetVMPParam_Cmd )

	/*<< 获取画面合成参数响应 >>
	*/
	MESSAGE( Ev_h245_GetVMPParamResult_Rsp )

	/*<< 混音成员通知 >>
	*/
	MESSAGE( Ev_h245_DiscussParam_Ntf )

	/*<< 移除混音成员 >>
	*/
	MESSAGE( Ev_h245_RemoveTerChimeIn_Cmd )
	
	/*<< 哑音cmd >>
	*/
	MESSAGE( Ev_h245_MakeTerMute_Cmd )
	
	/*<< 静音cmd >>
	*/
	MESSAGE( Ev_h245_MakeTerQuiet_Cmd )


	/*<< 切换画面合成风格 >>
	* is_multipic:  是否多画
	*/
	MESSAGE( Ev_h245_SwitchBroadCastStyle_Cmd )
	BODY(mt::TBOOL32, is_multipic)


	/*<< 请求对方是否同意强拆 >>
	* body 还没定
	*/
	MESSAGE( Ev_h245_mtAskOccupyPermit_Req )

	/*<< 对方回复是否同意强拆 >>
	* body 还没定
	*/
	MESSAGE( Ev_h245_mtAskOccupyPermit_Rsp )
	
	/*<< 平台设置组播地址 >>
	* TCHANMULTICAST 组播地址
	*/
	MESSAGE( Ev_h245_SetChanMultiCastAddr_Cmd )
	BODY( TCHANMULTICAST, tChanAddr)

	/*
	终端（仅限主席MT）选看画面合成请求
	*/
	MESSAGE( Ev_h245_mtSelectVmp_Req )
	BODY( mt::TBOOL32,  bStart)
	/*
	终端（仅限主席MT）选看画面合成请求
	*/
	MESSAGE( Ev_h245_mtSelectVmp_Rsp )
	BODY( mt::TBOOL32,  bResult)

	/*
	主席终端强制开始广播
	*/
	MESSAGE( Ev_h245_ForceBroadcast_Cmd )

	/*
	 非标请求终端信息
	*/
	MESSAGE( Ev_H245_GetTerminalInfo_Cmd )

	/*
	 非标终端信息应答
	*/
	MESSAGE( Ev_H245_GetTerminalInfo_Ntf )

	
	/*mcu请求终端发双流*/
	MESSAGE( Ev_H245_McReqTerSendAss_Cmd)

	/*码率指示*/
	MESSAGE( Ev_H245_FlowCtrlIndition_Cmd)

	/*开始环回*/
	MESSAGE( Ev_h323_StartLoopBackTest_Req )

	/*停止环回*/
	MESSAGE( Ev_h323_StopLoopBackTest_Req )

	MESSAGE( Ev_H323_LoopBackStatus_Ntf )

	////会议延长
	MESSAGE( Ev_H245_ConfDelay_Ntf)

	///confinfo通知
	MESSAGE( Ev_H245_confInfo_Ntf )


	////////////////////5.0新增的，自主画面合成相关
	/////开启自主画面合成，请求
	MESSAGE( Ev_H245_StartMtVmp_Req )

	/////开启自主画面合成回复
	MESSAGE( Ev_H245_StartMtVmp_Rsp )

	/////开启自主画面合成通知
	MESSAGE( Ev_H245_StartMtVmp_Ntf )


	/////停止画面合成
	MESSAGE( Ev_H245_StopMtVmp_Req )

	/////停止自主画面合成
	MESSAGE( Ev_H245_StopMtVmp_Rsp )

	/////停止自主画面合成
	MESSAGE( Ev_H245_StopMtVmp_Ntf )


	/////改变自主画面合成
	MESSAGE( Ev_H245_ChangeMtVmp_Req )

	/////改变自主画面合成
	MESSAGE( Ev_H245_ChangeMtVmp_Rsp )

	/////改变自主画面合成
	MESSAGE( Ev_H245_ChangeMtVmp_Ntf )


	/*<<主席指定vip列表 chair->mc >>
	* mt_id :  指定终端的列表
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_H245_ChairSpecVip_Req ) //非标
	
	/*<<mc回应主席指定vip列表 chair<-mc >>
	* mt_id :  指定终端的列表
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_H245_McRspChairVip_Rsp ) //非标

	/*<<mc通知终端当前vip列表 ter<-mc >>
	* mt_id :  指定终端的列表
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_H245_McInfoTerVip_Ntf ) //非标

	/////白板会议创建通知
	MESSAGE( Ev_H245_DataConfCreatedNtf_Cmd )
	BODY(mt::TString, conf_name) //白板会议名字

	///加入白板会议命令 用在点对点
	MESSAGE( Ev_H245_JoinDataConf_Cmd )
	BODY(mt::TString, conf_name) //白板会议名字

	///收到对端的加入白板会议命令 或者mcu, 或者对端
	MESSAGE( Ev_H245_JoinDataConf_Ntf )
	BODY(mt::TString, conf_name)  //白板会议名字

    //主席指定终端发双流
    MESSAGE( Ev_H245_ChairSpecTerSendAss_Cmd )
    BODY(mt::TMtId, tMtId)

	//终端通知平台通道情况
	MESSAGE( Ev_H245_NotifyPeerLocAlias_Cmd )

	//fecc streamid 
	MESSAGE( Ev_H245_FeccStreamId_Cmd )

	////设置dtmf密码
	MESSAGE(Ev_H245_PasswordDtmf_Cmd)
	BODY(mt::TBytes, tDtmfPwd)

	///mc设置音量
	MESSAGE(Ev_H245_McSetAudioVolume_Cmd)
	BODY(mt::TBytes, tvol)


	///mc请求终端的丢包率
	MESSAGE(Ev_H245_McReqTerLossRate_Req )


	///终端回复mc 终端的丢包率
	MESSAGE(Ev_H245_McReqTerLossRate_Rsp )
	BODY(mt::TBytes, tRsp)


	///fecc 打洞
	MESSAGE( Ev_H245_FeccHole_Cmd  )
    BODY(mt::TBytes, tvol)

	///终端渠道产品信息通知
	MESSAGE( Ev_h245_MtAgentInfo_Ntf )

	///对端渠道产品信息通知
	MESSAGE( Ev_H245_PeerAgentInfo_Ntf )

	///mc请求终端实时信息
	MESSAGE( Ev_H245_McGetMtRealtimeInfo_Cmd )
	BODY(mt::TBytes, tInfoType)

	//平台云类型通知， 0-私有云 1-公有云 2-混合云
	MESSAGE( Ev_H245_McuCloudType_Ntf )
	BODY(mt::TU32, dwCloudType)

#if !defined(_MESSAGE_HELP_)
	EV_END(H323) = EVSEG_H323_END
};
#endif

#define Is_MtH323_Msg(m) ((m) >= EV_BGN(H323) && (m) <= EV_END(H323))

#endif  //_H323MSG_H_