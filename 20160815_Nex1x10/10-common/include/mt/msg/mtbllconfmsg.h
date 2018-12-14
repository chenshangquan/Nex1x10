#ifndef _MTBLLCONFMSG_H_
#define _MTBLLCONFMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMtConfMsg
{

	//会议子系统用到的所有的消息都在这里， 这里需要区分，mtconf模块， mth323用到的， 内置mc用到的消息。
	EV_BLL_BGN(CONF) = EVSEG_BLL_CONF_BGN,
#endif
	
	/*
    UI --------------------> mtconf 
		 Ev_MT_BLL_Conf_XXX_Cmd	          
    UI <-------------------- mtconf 
         Ev_MT_BLL_Conf_XXX_Ntf	       
	*/


	/*<<开始呼叫>>
	* make_call_param ：呼叫参数
	*消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE(Ev_MT_BLL_Conf_MakeCall_Cmd)
	BODY(mt::TMtCallParam, make_call_param)

	/*<<接受呼叫>>
	*消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE(Ev_MT_BLL_Conf_AcceptCall_Cmd)

	/*<<拒绝呼叫>>
	*消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_RejectCall_Cmd )

	/*<<挂断呼叫>>
	* hangup_reason ：挂断原因
	*消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE(Ev_MT_BLL_Conf_HangupCall_Cmd)
	BODY(mt::TU32, hangup_reason)              //枚举值统一使用mt::TU32来传输，该处实际为mt::EmMtCallDisReason
	

	/*<<当前的呼叫状态上报>>
	* callsate ：上报的呼叫参数
	*消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_Conf_CallLinkState_Ntf)         //post to UI  当前呼叫状态
	BODY(mt::TMtCallLinkSate, callsate)

	/*<<当前的呼叫状态请求>>
	*消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_CallLinkState_Req)

	/*<<当前的呼叫状态应答>>
	*消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_CallLinkState_Rsp)
	BODY(mt::TMtCallLinkSate, callsate)

	/*<<错过的呼叫上报>>
	* call_param ：错过的呼叫参数
	*消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_Conf_CallMissed_Ntf)         //非idle状态，收到其他呼叫信息mtpa会挂断这个呼叫， 同时上报界面
	BODY(mt::TMtCallParam, call_param)


	/*<<单点扩多点>>
	* call_param ：扩多点的呼叫参数， 包括创建会议能力， 和呼叫的多个终端名
	*消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_P2pToMultiCall_Cmd )          
	BODY(mt::TMtCallParam, call_param)


	/*<<当前会议是否加密>>
	* bEncrypt ：是否加密
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_Conf_CallEncrypt_Ntf)
	BODY(mt::TBOOL32, bEncrypt)

	
	/*<<请求当前会议是否加密>>
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_CallEncrypt_Req )

	/*<<回复当前会议是否加密>>
	* bEncrypt ：是否加密
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_CallEncrypt_Rsp)
    BODY(mt::TBOOL32, bEncrypt)

	/*<<远端自环命令>> 同时开启音频自环，视频自环
	* bStart ： 开启/关闭
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_RemoteLoop_Cmd )
	BODY( mt::TBOOL32, bStart)


	/*<<远端自环状态指示>> 
	* emCodeType: codec 类型
	* emCodeIdx:  codec 索引
	* bResult ： 开启/关闭
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_RemoteLoop_Ntf )
	BODY( mt::TU32,    emCodeType)
	BODY( mt::TU32,    emCodeIdx)
	BODY( mt::TBOOL32, bResult)

	/*<<callid通知上层，用于白板会议>> 
	* callid  最多128位
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_Callid_Ntf )
	BODY( mt::TString,  callid)

	//////////////////////////////////////////////////////////pc video双流用到的消息


// 	/*<<通知pcdv当前mt状态>> 数据共享可以拿到
// 	* mtstatus ：当前上报到pcdv的mt状态
// 	* 消息流向 ：conf==>dispatch==>sdk==>pcdv
// 	*/
// 	MESSAGE(Ev_MT_BLL_Conf_PcdvMtStatus_Ntf)            //post to pcdv 当前mt状态,仅在disconnect，或connect后
// 	BODY(mt::TMtStatusToPcdv, mtstatus)


	/*<<当前辅流状态>>
	* mt_assstream_status ：当前辅流的状态
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_AssSndSream_Status_Ntf )             //广播所有界面，包括pcdv, mtc, 告知界面当前终端的双流情况
	BODY(mt::TMtAssSndVidStatus, mt_assstream_status)

	/*<<当前辅流状态>>
	* mt_assstream_status ：当前辅流的状态
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_AssRcvSream_Status_Ntf)              //广播所有界面，包括pcdv, mtc, 告知界面当前终端的双流情况
	BODY(mt::TMtAssRcvVidStatus, mt_assstream_status)


	/*<<请求当前辅流发送状态>>
	* mt_assstream_status ：当前辅流的状态
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_AssSndSream_Status_Req)             //界面请求当前终端的双流发送情况
	

	/*<<请求当前辅流接收状态>>
	* mt_assstream_status ：当前辅流的状态
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_AssRcvSream_Status_Req)             //界面请求当前终端的双流接收情况
	
	/*<<应答当前辅流发送状态>>
	* mt_assstream_status ：当前辅流的状态
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_AssSndSream_Status_Rsp)             //广播所有界面，包括pcdv, mtc, 告知界面当前终端的双流情况
	BODY(mt::TMtAssSndVidStatus, mt_assstream_status)

	/*<<应答当前辅流接收状态>>
	* mt_assstream_status ：当前辅流的状态
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_AssRcvSream_Status_Rsp)             //广播所有界面，包括pcdv, mtc, 告知界面当前终端的双流情况
	BODY(mt::TMtAssRcvVidStatus, mt_assstream_status)

	/*<<video双流开或关命令>>
	* bOpen ：开或者关
	* 消息流向 ：sdk==>dispatch==>conf  或 mtmp==>dispatch==>mtservice
	*/
	MESSAGE( Ev_MT_BLL_Conf_VideoAssStream_Cmd )
	BODY(mt:TBOOL32,  bOpen)                       //true : open；  false: close
	BODY(mt::TBOOL32, bScreen)			//是否为投屏，业务发这条消息会带上这个body，如果没有这个body就是UI来开硬双流


	/*<<pc双流开或关命令>>
	* bOpen ：开或者关
	* tPcRtcp ： pc的rtcp地址
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_PcAssStream_Cmd )
	BODY(mt:TBOOL32,  bOpen)                       //true : open；  false: close
	BODY(mt:TNetAddr, tPcRtcp)                     //pcRtcp地址  

	/*<< 激活通道，暂时用在pc双流通道上 >>
	* bActive ：开或者关
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE(Ev_MT_BLL_Conf_ChanActive_Cmd)
	BODY(mt:TBOOL32,  bActive)                //true : open；  false: close

	/*<<pc双流通道参数上报>>
	* mt_Forward_Rtp ：mt转发rtp地址
	* mt_Forward_Rtcp ： mt转发rtcp地址
	* enc_param ：     通道的编码格式
	* payload : 通道payload   
	* key     ：加密密码
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_PcAssStream_ChanParam_Ntf )   //通道的所有信息
	BODY(mt::TNetAddr, mt_Forward_Rtp)
	BODY(mt::TNetAddr, mt_Forward_Rtcp)
	BODY(mt::TVidEncParam,  enc_param)     
	BODY(mt::TU32,  payload)   
	BODY(mt::TEncryptKey, key)  

	/*<<设置 是否剥掉RTP扩展头>>
	*   tEnable: 是否剥掉
	*消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_Pc_SetBEnableRtpExStrip_Cmd )      
	BODY(mt::TBOOL32,  tEnable)

	/*<<设置丢包重传参数>>
	*prs_param ：丢包重传参数
	*消息流向 ：conf==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_Conf_Pc_SetPrsParam_Cmd)
	BODY(mt::TPrsParam, prs_param)



	/*<<pc双流通知界面开始编码>>
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_PcAssStream_StartEnc_Ntf)         //开始编码

	/*<<pc双流通知界面停止编码>>
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_PcAssStream_StopEnc_Ntf)           //停止编码
	
	/*<<pc双流通知界面请求关键帧>>
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_PcAssStream_IFrameRequest_Ntf)     //请求关键帧

	/*<<pc双流通知界面调整bitrate>>
	* bitrate ： 调整的码率
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_PcAssStream_SetBitrate_Ntf)        //调整bitrate
	BODY(mt::TU16, bitrate)

	/*<<双流发送失败， 没有到通道协商>> 原因包括： 码率小于192k, 状态不对
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_AssStreamSendFailed_Ntf)        

	//////////////////////////////////////////////////////////////pc video双流用到的消息
	

	/*<<请求会议列表>>
	* conf_req_type ： 请求会议列表类型
	* 消息流向 ：sdk==>dispatch==>conf
	*/
    MESSAGE( Ev_MT_BLL_Conf_GetConfList_Cmd)       //请求会议列表, 经周广程确认，5.0中，终端不会请求all了。
	BODY(mt::TU32,    conf_req_type)        //EmConfListType， all, book, idle, hold,


	/*<<回复会议列表>>             //note, 后续平台调整
	* conf_req_type ： 请求会议列表类型
	* conf_req_error:  错误类型
	* confList      ： 多个confname
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_ConfList_Ntf)          //回复会议列表, 
	BODY(mt::TU32,  conf_req_type)          //EmConfListType
	BODY(mt::TU32,  conf_req_error)         //EmConfListRspErr
	BODY(mt::TRpMtConfNameInfo, confList)   //多个包


	/*<<请求会议列表>>
	* conf_req_type ： 请求会议列表类型
	* 消息流向 ：sdk==>dispatch==>conf
	*/
    MESSAGE( Ev_MT_BLL_Conf_GetConfList_Req)       //请求会议列表, 经周广程确认，5.0中，终端不会请求all了。
	BODY(mt::TU32,    conf_req_type)        //EmConfListType， all, book, idle, hold,


	/*<<回复会议列表>>            
	* conf_req_type ： 请求会议列表类型
	* conf_req_error:  错误类型
	* confList      ： 多个confname
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_ConfList_Rsp )          //回复会议列表, 
	BODY(mt::TU32,  conf_req_type)          //EmConfListType
	BODY(mt::TU32,  conf_req_error)         //EmConfListRspErr
	BODY(mt::TRpMtConfNameInfo, confList)   //多个包


	/*<<ras 加入会议>>
	* joinconf_param ： 加入会议的参数
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE(Ev_MT_BLL_Conf_JoinConf_Cmd)            //选择会议列表加入会议 
	BODY(mt::TMtJoinConfParam,    joinconf_param)         //选择的会议e164号码
	
	/*<<加入会议结果>>
	* fialed_reason  ： 失败原因
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_PreJoinConfResult_Ntf)           //全通知UI, 复用mtpa
	BODY(mt::TU32,        failed_reason)              //EmMtJoinCreatConfRsp

	
	/*<<ras 创建会议>>
	* call_param  ： 呼叫参数
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_CreateConf_Cmd )           //创建会议请求, 复用mtpa
    BODY( mt::TMtCallParam, call_param)


	/*<<创建会议回复>>
	* fialed_reason  ： 失败原因
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_PreCreateConfResult_Ntf )     //只有failed才会通知UI
	BODY(mt::TU32,        failed_reason)        //EmMtJoinCreateConfRsp

    /*<<请求会议详细信息>>
	* conf_e164  ： 会议e164号码
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetConfDetailInfo_Cmd )        //请求详细会议信息
	BODY(mt::TString,     conf_e164)                //会议e164号

	/*<<会议详细信息应答>>
	* failed_reason  ： 失败原因
	* detail_info    ： 会议详细信息
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetConfDetailInfo_Ntf)         //详细会议信息应答
	BODY(mt::TU32,            failed_reason)               //EmMtConfDetailErr 
	BODY(mt::TMtConfDetailInfo, detail_info)     

	/*<<请求当前会议室数量>>
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetRoomNum_Cmd)           //请求当前会议室数量

	/*<<当前会议室数量应答>>
	* total_num   ： 总数量
	* useConfNum  ： 已用数量
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_RoomNum_Ntf)          //当前会议室数量应答
	BODY(mt::TU32,       total_num)            //总数量
	BODY(mt::TU32,       useConfNum)           //已用数量

	/*<<界面同步命令>>
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_UISynchronize_Cmd)           //界面同步命令
	BODY(mt::TS32,       reason)            //同步原因

	/*<<用于界面同步>>  //note 
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_UISynchronize_Ntf)        //用于界面同步
	BODY(mt::TS32,       reason)            //同步原因

	/*<<Conf模块错误码上报>>    
	* dwErrorCode:  根据mtErrCodeMakeErrID生成的错误码
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_ErrorCode_Ntf )
	BODY( mt::TU32, dwErrorCode)



// 
// 	/*<<注册命令>>
// 	* 消息流向 ：dispatch==>conf
// 	*/
// 	MESSAGE( Ev_MT_BLL_Conf_Reg_Cmd )          
// 	BODY(mt::TU32,    tConfProtocol)     //EmConfProtocol
// 
// 	/*<<取消注册命令>>  取消注册，用的是上一次的gk地址，所以取消注册不需要带带gk地址下去
// 	* 消息流向 ：dispatch==>conf
// 	*/
// 	MESSAGE( Ev_MT_BLL_Conf_UnReg_Cmd )        //取消注册命令 
// 	BODY(mt::TU32,    tConfProtocol)    //EmConfProtocol
	

	/*<<注册结果请求>>
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_RegResult_Req )
	BODY(mt::TU32,    tConfProtocol)        //EmConfProtocol

	/*<<注册结果rsp>>
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_RegResult_Rsp )    //注册结果
	BODY(mt::TU32,    tConfProtocol)           //EmConfProtocol
	BODY(mt::TBOOL32, bRegSuc      )           //注册成功与否


	/*<<注册结果上报>>
	* 消息流向 ：conf==>dispatch==>mtmeetingservice
	*/
	MESSAGE( Ev_MT_BLL_Conf_RegResult_Ntf)     //注册结果
	BODY(mt::TU32,    tConfProtocol)    //EmConfProtocol
	BODY(mt::TBOOL32, bRegSuc      )    //注册成功与否，失败的话， 失败原因下面
	BODY(mt::TU32,    bReason      )    //EmRegFailedReason

	/*<<取消注册结果上报>>
	* 消息流向 ：conf==>dispatch==>mtmeetingservice
	*/
	MESSAGE( Ev_MT_BLL_Conf_UnRegResult_Ntf)   //取消注册结果
	BODY(mt::TU32,    tConfProtocol)    //EmConfProtocol
	BODY(mt::TBOOL32, bUnRegSuc    )    //取消注册成功与否


 	/*<<上报pc双流编码诊断数据>>
 	* 消息流向 ：sdk==>dispatch==>conf
 	*/
 	MESSAGE( Ev_MT_BLL_Conf_MtRePortPCEncStatis_Cmd )  //对于mtc和pcdv, 不区分消息， 谁发双流，订阅这条消息
	BODY(mt::TVidEncStatistic,    tEncStatistic)    //统计数据

	/*conf层需要提供给诊断模块的所有诊断的数据Todo*/



	//////////////下面为会议控制的消息
	/*1	请求终端列表，终端名字,会议基本信息操作*/

	/*<<分配终端编号>>
	* mt_id:  分配的终端编号\
	* tChairRspToken: 当前是否申请主席是成功的
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_TerLabel_Ntf )
	BODY(mt::TMtId,  mt_id)
	BODY(mt::TBOOL32, tChairRspToken)

	/*<<请求终端编号>>
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_TerLabel_Req )
	
	/*<<请求终端编号回复>>
	* 消息流向 ：sdk<==dispatch<==conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_TerLabel_Rsp)
	BODY(mt::TMtId,  mt_id)


	/*<< 终端退出>>
	* 消息流向 ：sdk<==dispatch<==conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_TerLeft_Ntf)
	BODY(mt::TMtId,  mt_id)


	/*<< 终端加入>>
	* 消息流向 ：sdk<==dispatch<==conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_TerJoin_Ntf )
	BODY(mt::TMtInfo,  mt_info)




// 	/*<<请求所有终端名字>>
// 	* 消息流向 ：sdk==>dispatch==>conf
// 	*/
// 	MESSAGE( Ev_MT_BLL_Conf_TerGetAllTerName_Cmd )

	
	/*<<请求当前会议所有在线终端>>
	* 消息流向 ：sdk==>dispatch==>conf
	*/
    MESSAGE( Ev_MT_BLL_Conf_OnLineTerList_Req )   ///req消息只是用于mtc登录时，请求保存在mtconf中的与会终端列表数据

	/*<<请求当前会议所有在线终端>>
	* mt_info:  所有不在线终端信息
	* 消息流向 ：sdk==>dispatch==>conf
	*/
    MESSAGE( Ev_MT_BLL_Conf_OnLineTerList_Rsp )
	BODY(mt::TRpMtInfo,  mt_info)

	/*<<当前会议所有在线终端>>
	* mt_info:  所有不在线终端信息
	* 消息流向 ：sdk==>dispatch==>conf
	*/
    MESSAGE( Ev_MT_BLL_Conf_OnLineTerList_Ntf )   ///对于与会列表， UI不需要发online_cmd消息， 因为mtconf层对应终端列表只要有变化，就会发ntf上去 
	BODY(mt::TRpMtInfo,  mt_info)

	
	/*<<请求当前会议所有不在线终端>>
	* 消息流向 ：conf==>dispatch==>sdk
	*/
    MESSAGE( Ev_MT_BLL_Conf_OffLineTerList_Req ) ///req消息只是用于mtc登录时，请求保存在mtconf中的离线终端列表数据， 回复对应Ev_MT_BLL_Conf_OffLineTerList_Rsp
	
	/*<<请求当前会议所有不在线终端>>
	* mt_info:  所有不在线终端信息
	* 消息流向 ：conf==>dispatch==>sdk
	*/
    MESSAGE( Ev_MT_BLL_Conf_OffLineTerList_Rsp )
	BODY(mt::TRpMtInfo,  mt_info)

	/*<<当前会议所有不在线终端>>
	* mt_info:  所有不在线终端信息
	* 消息流向 ：conf==>dispatch==>sdk
	*/
    MESSAGE( Ev_MT_BLL_Conf_OffLineTerList_Ntf )   ///mtconf层会主动去向平台请求的，请求的结果会ntf上去的。
	BODY(mt::TRpMtInfo,  mt_info)


	////不需要了。
	/*<<Mc请求终端输入名字>>
	* mt_info:  mt的名字信息
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	//MESSAGE(Ev_MT_BLL_Conf_McReqTerName_Cmd)
	//BODY(mt::TMtInfo, mt_info)
	
	
	/*<<终端应答mc 名字>>
	* mt_info:  mt的名字信息
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	//MESSAGE(Ev_MT_BLL_Conf_TerRspMcName_Cmd)
	//BODY(mt::TMtInfo, mt_info)



// 	/*<<获取其他终端名>>
// 	* mt_id:  mtid
// 	* 消息流向 ：sdk==>dispatch==>conf
// 	*/
// 	MESSAGE( Ev_MT_BLL_Conf_TerGetOtherTerName_Cmd)
// 	BODY( mt::TMtId, mt_id )

// 	/*<<对端会议能力指示>>
// 	* peer_info:  对端会议能力
// 	* 消息流向 ：conf==>dispatch==>sdk
// 	*/
// 	MESSAGE( Ev_MT_BLL_Conf_PeerCap_Ntf ) ///暂时不用
//     BODY( mt::TPeerCapabilityInfo, peer_info )
// 
// 	/*<<对端会议能力请求>>
// 	* 消息流向 ：sdk==>dispatch==>conf
// 	*/
// 	MESSAGE( Ev_MT_BLL_Conf_PeerCap_Req) ///暂时不用
// 
// 	/*<<对端会议能力应答>>
// 	* 消息流向 ：conf==>dispatch==>sdk
// 	*/
// 	MESSAGE( Ev_MT_BLL_Conf_PeerCap_Rsp) ///暂时不用
	
	///确认下3.

	/*<<请求会议信息>>
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetConfInfo_Cmd )
	

	///////note  问下平台，同时整合
	/*<<当前会议信息>>
	* conf_info:  当前会议信息
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_ConfInfo_Ntf )
	BODY(mt::TMtConfInfo, conf_info)

	/*<<当前会议信息>>
	* sim_conf_info:  简单会议信息
	* 消息流向 ：conf==>dispatch==>sdk
	*
	h_ctrl_SimpleConfInfoInd,               //mcu通知终端更新会议信息      MC->ter
	*/
	MESSAGE( Ev_MT_BLL_Conf_SimpleConfInfo_Ntf )   
	BODY(mt::TMtSimpConfInfo, sim_conf_info)



	/*<<请求当前会议信息>>
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_ConfInfo_Req )

	/*<<回复当前会议信息>>
	* conf_info
	* bRecvSimpleInfo: 是否收到simconfinfo
	* simp_conf_info： 简单会议信息
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_ConfInfo_Rsp)
    BODY(mt::TMtConfInfo, conf_info)
	BODY(mt::TBOOL32,     bRecvSimpleInfo)
	BODY(mt::TMtSimpConfInfo, simp_conf_info)


    /*<<会议即将结束指示>>
	* time:  所剩的时间
	* 消息流向 ：conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ConfWillEnd_Ntf)
	BODY(mt::TU16, time )

	/*<<请求是否要输入密码>>
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_IsEnterPassword_Req)   ///用于mtc连上终端，请求conf，是否要输入会议密码
	
	/*<<回复是否要输入密码>>
	* bEnterPassword: 是否要输入密码
	* 消息流向 ：conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_IsEnterPassword_Rsp)  ///用于mtc连上终端，mtconf回复 是否输入会议密码， 然后mtc再发送Ev_MT_BLL_Conf_MtRspPassword_Cmd
	BODY(mt::TBOOL32,  bEnterPassword )

	/*<<会议密码请求>>
	* 消息流向 ：conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_McReqPassword_Cmd)

	/*<<会议密码应答>>
	* conf_pwd:  会议密码
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_MtRspPassword_Cmd)
	BODY(mt::TBytes, conf_pwd )



	/* 2. 主席相关操作*/

    /*<<强制终端退出, chair->mc>>
	* mt_id   : 终端id
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_DropTer_Cmd)
	BODY( mt::TMtId, mt_id )

	/*<<强制终端退出失败, mc->chair >>
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_DropTerReject_Ntf )
	
	/*<<结束会议, chair->mc >>
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_EndConf_Cmd )


	////note, 延长时间具体指？？问下平台
	/*<<主席延长会议>>
	* time:  延长的时间 /分钟
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ReqProlong_Cmd)
	BODY(mt::TU16, time )

	/*<<会议延长应答>>
	* bResult:  是否同意
	* 消息流向 ：conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ProlongResult_Ntf)
	BODY(mt::TBOOL32, bResult )



	
	/*<<主席邀请终端 chair->mc >>
	* mt_addr:  终端地址
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_ChairInviteTer_Cmd)
	BODY(mt::TMtAddr, mt_addr )

	/*<<主席邀请终端失败 mc->chair>>
	* mt_addr:  终端地址
	* tReason:  失败原因
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_ChairInviteFailed_Ntf)   
	BODY(mt::TMtAddr, mt_addr )
	BODY(mt::TU32,    tReason) //EmMtCallDisReason


// 	/*<<主席邀请终端失败, 失败原因 mc->chair>>
// 	* emReason: 失败原因
// 	* 消息流向 ：conf==>dispatch==>sdk
// 	*/
// 	MESSAGE( Ev_MT_BLL_ConfTerJoinConfFailed_Ntf )     //// chenlijun 20121204 Bug00102382 TL2.5:TL开启AES加密，召集其他非AES终端，邀请不成功但也没给出邀请失败的提示
// 	BODY( mt::EmMtConfFailureReason, emReason )


	/*<<会议发生错误, 失败原因 mc->mt>>
	* emReason: 失败原因
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_ConfFailed_Ntf )     
	BODY( mt::EmMtConfFailureReason, emReason )


	/*<<主席呼叫离线终端 >>
	* mt_id: 离线终端id
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_CallOfflineTer_Cmd)
	BODY( mt::TMtId, mt_id )

	/*
	原来的Ev_MT_BLL_Conf_ModifyConfName_Cmd， Ev_MT_BLL_ConfModifyConfDuration_Cmd，
	Ev_MT_BLL_Conf_ModifyConfPwd_Cmd， Ev_MT_BLL_Conf_ModifyDualMode_Cmd
	消息等待回复的 Ev_MT_BLL_Conf_ModifyConfResult_Ntf
	*/
    
	/*<<修改会议画面合成是否显示成员别名 >>
	* bShow: 是否显示
	* content: 
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_ModifyVmpShowAlias_Cmd )
	BODY( mt::TBOOL32, bShow )


	/*<<修改会议属性 >>
	* emModifyType: 修改type
	* content: 
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_ModifyConfName_Cmd )
	BODY( mt::TString,   content ) 

	/*<<修改会议时间 >>
	* wTime: 分钟
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_ModifyConfDuration_Cmd)
	BODY( mt::TU16, wTime)

	/*<<修改会议时间 >>
	* bDumb: 是否哑音
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_SetConfDumb_Cmd)
	BODY( mt::TBOOL32, bDumb)

	/*<<修改会议是否免打扰 >>
	* bEnable: 是否开启
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_SetConfNoDisturb_Cmd)
	BODY( mt::TBOOL32, bEnable)


	/*<<修改会议密码 >>
	* bUsePwd:  是否用密码
	* tpwd:     会议密码
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_ModifyConfPwd_Cmd)
	BODY( mt::TBOOL32, bUsePwd)
	BODY( mt::TBytes,  tPwd)

	/*<<修改会议双流类型 >>
	* emMtDualMode:  双流类型
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_ModifyDualMode_Cmd )
	BODY( mt::TU32, emMtDualMode)  //emMtDualMode

	/*<<修改会议名应答 >>
	* emModifyType: 修改类型
	* bResult:      成功与否
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_ModifyConfResult_Ntf )
	BODY( mt::TU32,   tModifyType ) //EmMtModifyConfInfoType_Api
	BODY( mt::TBOOL32, bResult )



	/*3 发言相关操作*/

	/*<<申请发言人 mt->mc >>
	* note : conf层不做定时器， 因为不同的界面定时策略不一样
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ApplySpeak_Cmd )   /////如果同意结果放在 Ev_MT_BLL_Conf_IsSeenByAll_Ntf， 不同意， 平台没有回复, 

	/*<<收到申请发言人请求 mc->chair >>
	* mt_id :  发言人的id
	* 消息流向 ：conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ApplySpeak_Ntf )
	BODY(mt::TMtId, mt_id)

	/*<<主席同意发言 chair->mc >>
	* mt_id :  发言人的id
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ChairAgreeSpeak_Cmd )
	BODY(mt::TMtId, mt_id)

	/*<<发言人位置指示 mc->mt >> 
	* mt_id :  发言人的id
	* 消息流向 ：conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_SpeakerPos_Ntf )       
	BODY(mt::TMtId, mt_id)


	/*<<成为发言人指示 mc->mt>> 
	* 消息流向 ：conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_SeenByAll_Ntf )
	
	/*<<取消发言人指示 mc->mt>> 
	* 消息流向 ：conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_CancelSeenByAll_Ntf )

	/*<<申请发言人超时指示>> 
	* 消息流向 ：dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ApplySpeakTimerOut_Ntf )

	/*<<申请主席超时指示>> 
	* 消息流向 ：dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ApplyChairTimerOut_Ntf )
	
	/*<<申请插话超时指示>> 
	* 消息流向 ：dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ApplyChiemeTimerOut_Ntf )
	

	/*<<主席指定发言人请求 >>
	* mt_id :  发言人的id
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ChairAssignSpeak_Cmd )   //需要等平台回复Ev_MT_BLL_Conf_BroadcastResult_Ntf同意还是不同意
	BODY(mt::TMtId, mt_id)

	/*<<主席指定发言人结果 chair->mc >>
	* bResult :  指定成功或失败
	* 消息流向 ：conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ChairAssignSpeakRes_Ntf )
	BODY(mt::TBOOL32,  bResult)

	/*<<主席取消发言人 chair->mc >>
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_CancelBroadcast_Cmd )

	/*<<源位置指示 mc->mt >>
	* mt_seeing :  多路视频源
	* 消息流向  ： conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_YouAreSeeing_Ntf )
	BODY(mt::TRpMtSeeing, mt_seeing)

	/*<<请求视频源位置 mc->mt >>
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_YouAreSeeing_Req ) 
	
	/*<<回复视频源位置 mc->mt >>
	* mt_id :  视频源终端的id
	* 消息流向 ：conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_YouAreSeeing_Rsp )
	BODY(mt::TRpMtSeeing, mt_seeing)



	/*3 主席申请相关操作*/
	/*<<申请主席申请 mt->mc >>
	*note : conf层不做定时器，
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ApplyChair_Cmd )  
	
	
	/*<< 申请主席回复，主席令牌改变 mc->mt >>
	*note : conf层不做定时器，
	* 消息流向 ：conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_GetChairToken_Ntf )
	BODY(mt::TBOOL32, bGet)

	/*<<有终端申请主席 mc->chair >>
	* mt_id:  mt_id
	* 消息流向 ：conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ApplyChairInd_Ntf) //非标
	BODY(mt::TMtId, mt_id)

	/*<<释放主席令牌 chair->mc >>
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_WithdrawChair_Cmd )
	
	/*<<主席位置查询 mt->mc >>
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_WhoIsChair_Cmd )

	/*<<主席位置指示 mc->mt >>
	* mt_id :  主席终端的id
	* 消息流向 ：conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_Chair_Ntf )
	BODY(mt::TMtId, mt_id)


	/*<<主席转移令牌 chair->mc >>
	* mt_id :  指定终端的id
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ChairTransfer_Cmd ) //非标
	BODY(mt::TMtId, mt_id)

	/*<<主席指定vip列表 chair->mc >>
	* mt_id :  指定终端的列表
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ChairSpecVip_Cmd ) //非标
	BODY(mt::TRpMtId, mt_id)

	/*<<mc回应主席指定vip列表 chair<-mc >>
	* tResult :  是否同意
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_SetVipResult_Ntf ) //非标
	BODY(mt::TBOOL32, tResult)

	/*<<mc通知终端当前vip列表 ter<-mc >>
	* mt_id :  指定终端的列表
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_McInfoTerVip_Ntf ) //非标
	BODY(mt::TRpMtId, mt_id)

	/*<<请求当前vip列表  >>
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_VipList_Req ) //非标


	/*<<回复当前vip列表 >>
	* mt_id :  指定终端的列表
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_VipList_Rsp ) //非标
	BODY(mt::TRpMtId, mt_id)


	/*4 选看,插话，轮询, 点名操作*/

	/*<<选看终端 chair->mc >>
	* TViewTerParam :  选看终端param
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_SendThisTer_Cmd )
	BODY(mt::TViewTerParam, viewparam)
	
	/*<<选看终端 chair->mc >>
    * bView :  当前是否在选看
	* TViewTerParam :  选看终端param
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 	MESSAGE( Ev_MT_BLL_Conf_SendThisTer_Ntf )
	BODY(mt::BOOL32, bView)
	BODY(mt::TViewTerParam, viewparam)

	/*<<选看终端 chair->mc >>
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_GetSendThisTerParam_Req )

		/*<<选看终端 chair->mc >>
	* TViewTerParam :  选看终端param
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_GetSendThisTerParam_Rsp )
	BODY(mt::TViewTerParam, viewparam)

	/*<<选看终端结果 mc->chair >>
	* bResult: 选看成功与否
	* mt_id :  选看终端的id
	* 消息流向 ：conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_SendThisTerResult_Ntf ) 
	BODY(mt::TBOOL32, bResult)
	BODY(mt::TMtId,   mt_id)

	/*<<取消选看 chair->mc >>
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_CancelSendThisTer_Cmd )  
	
	/*<<本终端被选看 mc->mt >>
	* 消息流向 ：conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_SeenByOther_Ntf)
	
	/*<<本终端取消被选看 mc->mt >>
	* 消息流向 ：conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_CancelSeenByOther_Ntf)
	
	/*<<申请插话 mt->mc >>
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ApplyChiemeIn_Cmd ) //conf层不做定时器， 因为不同的界面定时策略不一样

	/*<<有终端申请插话 mc->chair >>
	* mt_id :  申请插话终端的id
	* 消息流向 ：conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ApplyChimeIn_Ntf )
	BODY(mt::TMtId, mt_id)
	
	/*<<主席同意插话请求 chair->mc >> 
	* mt_id :  申请插话终端的id
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_ChiemeIn_Cmd )    //指定插话， 调用同一个消息
	BODY(mt::TMtId, mt_id)

	/*<<终端插话状态 mc->ter >>
	* bResult : 是否正在插话
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_ChimeInState_Ntf )
	BODY(mt:BOOL32, bResult)

	/*<<终端插话失败 mc->ter >>
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_ChimeInFailed_Ntf )
	
// 	/*<<主席指定插话请求 chair->mc >>
// 	* mt_id :  申请插话终端的id
// 	* 消息流向 ：sdk==>dispatch==>conf
// 	*/
// 	MESSAGE( Ev_MT_BLL_Conf_ReqChiemeIn_Cmd )   //现代码没有处理该消息
// 	BODY(mt::TMtId, mt_id)


	//////轮询请求，应答
	//////ToDo

	/*<<主席轮询终端请求 chair->mc >>
	* poll_info : 轮询参数
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_Poll_Cmd )
    BODY(mt::TMtPollInfo, poll_info)

	/*<<主席轮询状态上报 conf->sdk >>
	* poll_info : 轮询参数
	* 消息流向 ： conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_PollState_Ntf )
    BODY(mt::TMtPollInfo, poll_info)

	/*<<主席轮询终端参数请求 >>
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_PollState_Req )

	/*<<主席轮询终端参数请求 >>
	* poll_info : 轮询参数
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_PollState_Rsp )
	BODY(mt::TMtPollInfo, poll_info)


	/*<<当前正在轮询终端通知 conf->sdk >>
	* tMtId :     正在轮询终的终端
	* 消息流向 ： conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_PollingMt_Ntf )
    BODY( mt::TMtId, tMtId )

	/*
	note:  状态列表平台没有消息是一次性取所有的列表，所有TerStatusList_Req，是取保存在终端这边的一部分列表，并不是全部的
	*/

	/*<<查询别的终端状态 chair->mc >>
	* tMtId : 终端id
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_TerGetTerStatus_Cmd)
	BODY(mt::TMtId,   tMtId)

	/*<<查询别的终端状态应答 mc->chair >>
	* tMtId : 终端id
	* tTerStatus: 终端状态
	* 消息流向 ： conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_TerGetTerStatus_Ntf)
	BODY(mt::TMtEntityStatus,   tMtStatus)
	

	/*<<请求终端状态列表 >>
	* tMtId : 终端id
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetTerStatusList_Req )

	/*<<查询别的终端状态应答 mc->chair >>
	* tMtId : 终端id
	* tTerStatus: 终端状态
	* 消息流向 ： conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetTerStatusList_Rsp)
	BODY(mt::TRpMtEntityStatus,   tRpMtStatus)

	/*<<同步sdk层缓存的会议列表  >>
	* 消息流向 ： conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_RemoveConfList_Cmd)
	
// 	////点名暂时不做， mcs上会用到
// 	/*<<点名请求 >>
// 	* tMtId： mtid
// 	* 消息流向 ： sdk==>dispatch==>conf
// 	*/
// 	MESSAGE( Ev_MT_BLL_Conf_RollCall_Cmd ) //暂时不用
// 	BODY(mt::TMtId,   tMtId)
// 
// 	/*<<点名请求结果 >>
// 	* tMtid:   mtid
// 	* bResult: 点名结果
// 	* 消息流向 ： conf==>dispatch==>sdk
// 	*/
// 	MESSAGE( Ev_MT_BLL_Conf_RollCallResult_Ntf )//暂时不用
// 	BODY(mt::TMtId,   tMtId)
// 	BODY(mt::TBOOL32, bResult)


	/*<<主席强制广播 >>
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_StartForceBroadcast_Cmd ) ///暂时不用
	
	/*<<主席强制取消广播 >>
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_StopForceBroadcast_Cmd )  ///暂时不用



	/*5 画面合成，混音操作*/

	/*<< 开始语音激励 >>
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_StartVAC_Cmd )

	/*<< 开始语音激励应答 >>
	* bResult : 结果
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_StartVACResult_Ntf )
	BODY(mt::TBOOL32, bResult)


	/*<< 停止语音激励 >>
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_StopVAC_Cmd )

	/*<< 停止语音激励结果 >>
	* bResult : 结果
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_StopVACResult_Ntf )
	BODY(mt::TBOOL32, bResult)


	/*<< 开始讨论模式请求 >>
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_StartDiscuss_Cmd )  //不需要传混音个数下来，discuss是全部混音

	/*<< 开始讨论模式结果 >>
	* bResult : 结果
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_StartDiscussResult_Ntf )
	BODY(mt::TBOOL32, bResult)


	/*<< 停止讨论模式请求 >>
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_StopDiscuss_Cmd )

	/*<< 停止讨论模式结果 >>
	* bResult : 结果
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_StopDiscussResult_Ntf )
	BODY(mt::TBOOL32, bResult)

	/*<< 开始混音请求 >>
	* TRpMtId:  混音终端数
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_StartCustomMix_Cmd)
	BODY(mt::TRpMtId, tRpMtId )

	/*<< 开始混音应答 >>
	* bResult:   结果
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_StartCustomMixResult_Ntf)
	BODY(mt::BOOL32, bResult)


	/*<< 停止混音请求 >>
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_StopCustomMix_Cmd)

	/*<< 停止混音应答 >>
	* bResult:   结果
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_StopCustomMixResult_Ntf)
	BODY(mt::BOOL32, bResult)


	/*<< 添加混音成员 >>
	* tRpMtId:  多个混音成员
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_MakeTerChimeIn_Cmd )
	BODY(mt::TRpMtId, tRpMtId )

	/*<< 删除混音成员 >>
	* tRpMtId:  多个混音成员
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_RemoveTerChimeIn_Cmd )
	BODY(mt::TRpMtId, tRpMtId )

	
	/*<< 混音参数上报 >>
	* tmixparam:  混音参数
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_MixParam_Ntf )
	BODY(mt::TMtMixParam, tmixparam)

	/*<< 混音成员请求 >>
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_MixParam_Req )
	
	/*<< 混音成员回复 >>
	* mix_param:  混音参数
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_MixParam_Rsp )
	BODY(mt::TMtMixParam, mix_param)

	/*<< 自主画面合成参数请求 >>
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_CustomVmpParam_Req )
	
	/*<< 自主画面合成参数应答 >>
	* vmp_param:  自主画面合成参数
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_CustomVmpParam_Rsp )
	BODY(mt::TMtVmpParam, vmp_param)
	

	///自主画面合成

	/*
	Note：  PreResult 是平台业务的回复 同意或者拒绝
	        Result:   是平台底层的回复，真正的同意或者拒绝
	*/

	/*<< 开始会议多画面合成请求 >>
	* vmp_param: 画面合成参数
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_StartVMP_Cmd)
	BODY( mt::TMtVmpParam, vmp_param )

	/*<< 开始自主多画面合成请求 >>
	* vmp_param: 画面合成参数
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_StartCustomVMP_Cmd )
	BODY( mt::TMtVmpParam, vmp_param )



	/*<< 开始会议画面合成应答 >>
	* bResult : 结果
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_StartVMPResult_Ntf)
	BODY( mt::TBOOL32,     bResult )

	/*<< 开始自主多画面合成应答 >>
	* bResult : 结果
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_StartCustomVMPResult_Ntf)
	BODY( mt::TBOOL32,     bResult )


	/*<< 停止会议多画面合成请求 >>
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_StopVMP_Cmd)
	
	/*<< 停止自主画面合成请求 >>
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_StopCustomVMP_Cmd)


	/*<< 停止会议多画面合成应答 >>
	* bResult : 结果
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_StopVMPResult_Ntf)
	BODY(mt::TBOOL32, bResult)

	
	/*<< 停止自动多画面合成应答 >>
	* bResult : 结果
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_StopCustomVMPResult_Ntf)
	BODY(mt::TBOOL32, bResult)


	/*<< 设置画面合成参数 >>
	* vmp_param: 画面合成参数
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_SetVMPParam_Cmd )    //只针对科达终端
	BODY( mt::TMtVmpParam, vmp_param)     

		/*<< 设置画面合成参数 >>
	* vmp_param: 画面合成参数
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_SetCustomVMPParam_Cmd )    //只针对科达终端
	BODY( mt::TMtVmpParam, vmp_param) 


	/*<< 设置会议画面合成参数应答 >>
	* bResult : 结果
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_SetVMPParamResult_Ntf)
	BODY( mt::TBOOL32,    bResult )

	/*<< 设置自主画面合成参数应答 >>
	* bResult : 结果
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_SetCustomVMPParamResult_Ntf)
	BODY( mt::TBOOL32,    bResult )

	/*<< 同步sdk画面合成参数 >>
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_SyncVMPParam_Cmd)
	
	/*<< 获取画面合成参数 >>
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetVMPParam_Cmd )

	/*<< 获取画面合成参数响应 >>
	* vmp_param ： 画面合成参数
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetVMPParamResult_Ntf )
	BODY( mt::TMtVmpParam, vmp_param)

	/*<< 获取自主画面合成参数响应 >>
	* vmp_param ： 画面合成参数
	* 消息流向 ： conf==>dispatch==>sdk 
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetCustomVMPParamResult_Ntf )
	BODY( mt::TMtVmpParam, vmp_param)
	
	/*<< 远端哑音 >>
	* tMtid:  终端id
	* bMute： 是否哑音
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_MakeTerMute_Cmd )
	BODY(mt::TMtId,   tMtId)
	BODY(mt::TBOOL32, bMute)


	/*<< 远端静音 >>
	* tMtid:  终端id
	* bQuiet： 是否静音
	* 消息流向 ： sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_MakeTerQuiet_Cmd )
	BODY(mt::TMtId,   tMtId)
	BODY(mt::TBOOL32, bQuiet)

	////平台沟通， 结果是否回？？？？，是否还用
	/*<< 切换画面合成风格 >>
	* is_multipic:  是否多画面
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_SwitchBroadCastStyle_Cmd )
	BODY(mt::TBOOL32, is_multipic)

	/*<< 终端（仅限主席MT）选看画面合成请求 >>
	* bStart:  TRUE 选看画面合成，FALSE 取消选看画面合成
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_mtSelectVmp_Cmd)
	BODY( mt::TBOOL32, bStart)

	/*<< 终端（仅限主席MT）选看画面合成响应 >>
	* bStart:  TRUE 选看画面合成，FALSE 取消选看画面合成
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_SelectVmpResult_Ntf)
	BODY( mt::TBOOL32, bStart)


	/*<< 短消息 >>
	* short_mess:  短消息内容
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_SMS_Cmd)         /////兼容老平台
	BODY(mt::TShortMsg, short_msg)


	/*<< 短消息指示 >>
	* short_mess:  短消息内容
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_SMS_Ntf)        ////兼容老平台
	BODY(mt::TShortMsg, short_msg)

	/*<< 请求对端视频源信息 >>
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_PeerVideoAlias_Req )

	/*<< 对端视频源信息响应 >>
	* peer_info:  对端视频源信息
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_PeerVideoAlias_Rsp )
	BODY(mt::TRpMtVideoAlias, peer_info)

	/*<< 对端视频源信息响应 >>
	* peer_info:  对端视频源信息
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_PeerVideoAlias_Ntf )
	BODY(mt::TRpMtVideoAlias, peer_info)
    


	////////////////////远摇命令，conf定义的是本地发送远摇命令控制对端，
	///////////////////对端过来的远摇命令，conf处理完后，控制摄像头,应该是device那边定义
	/*<< 选择控制射像头命令 >>
	* tDest_Mtid:    目的id
	* byCameraIndex: 摄像头索引
	* 消息流向 ：device/?==>dispatch==>mtconf
	*/
	MESSAGE( Ev_MT_BLL_Conf_FeccCameraSelect_Cmd )
	BODY(mt::TMtId,   tDest_Mtid )
	BODY(mt::TU8,     byCameraIndex)

	 /*<< 摄像头聚焦命令 >>
	* tDest_Mtid:    目的id
	* bNearFocus,    TRUE=近焦 , FALSE=远焦
	* tAction:       操作， emStart/emStop
	* 消息流向 ：device/?==>dispatch==>mtconf
	*/
    MESSAGE( Ev_MT_BLL_Conf_FeccCameraFocus_Cmd )
    BODY(mt::TMtId,   tDest_Mtid )
    BODY(mt::TBOOL32, bNearFocus )
    BODY(mt::TU32,    tAction)     //EmAction


	/*<< 摄像头自动聚焦命令 >>
	* tDest_Mtid:    目的id
	* 消息流向 ：device/?==>dispatch==>mtconf
	*/
	MESSAGE( Ev_MT_BLL_Conf_FeccCameraAutoFocus_Cmd )
	BODY(mt::TMtId,   tDest_Mtid )

	/*<< 摄像视野命令 >>
	* tDest_Mtid:    目的id
	* bZoomIn:       TRUE= 放大 /FALSE=缩小
	* tAction:       emStart/emStop
	* 消息流向 ：device/?==>dispatch==>mtconf
	*/
	MESSAGE( Ev_MT_BLL_Conf_FeccCameraZoom_Cmd)
	BODY(mt::TMtId,   tDest_Mtid )
	BODY(mt::TBOOL32, bZoomIn )
	BODY(mt::TU32,    tAction)     //EmAction

	/*<< 摄像亮度调节命令 >>
	* tDest_Mtid:    目的id
	* bLight:       TRUE= 加亮  FALSE=减暗
	* tAction:       emStart/emStop
	* 消息流向 ：device/?==>dispatch==>mtconf
	*/
	MESSAGE(Ev_MT_BLL_Conf_FeccCameraBright_Cmd)
	BODY(mt::TMtId,   tDest_Mtid )
	BODY(mt::TBOOL32,   bLight )
	BODY(mt::TU32,     tAction)     //EmAction

	/*<< 预置位命令 >>
	* tDest_Mtid:    目的id
	* bLight:        TRUE= 存储 FALSE=调用预置位
	* byIndex        预置位索引 1-16
	* 消息流向 ：device/?==>dispatch==>mtconf
	*/
	MESSAGE(Ev_MT_BLL_Conf_FeccCameraPreset_Cmd)
	BODY(mt::TMtId,   tDest_Mtid )
	BODY(mt::TBOOL32, bSave )
	BODY(mt::TU8,     byIndex)

	/*<< 摄像头移动命令 >>
	* tDest_Mtid:    目的id
	* tDirection:    移动方向
	* tAction:       emStart/emStop
	* 消息流向 ：device/?==>dispatch==>mtconf
	*/
	MESSAGE(Ev_MT_BLL_Conf_FeccCameraPantilt_Cmd )
	BODY(mt::TMtId,   tDest_Mtid )
	BODY(mt::TU32,    tDirection ) //EmDirection
	BODY(mt::TU32,    tAction)     //EmAction

	/*<< 选择视频源 >>
	* tDest_Mtid:    目的id
	* byVideoSrcIndex:  选择视频源
	* 消息流向 ：device/?==>dispatch==>mtconf
	*/
	MESSAGE(Ev_MT_BLL_Conf_FeccVideoSourceSel_Cmd)   ////只选择主视频
	BODY(mt::TMtId,   tDest_Mtid )
	BODY(mt::TU8,     byVideoSrcIndex)


	/*<<会议延长通知>>
	* time:  延长的时间(分钟)
	* 消息流向 ：conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ConfDelay_Ntf)
	BODY(mt::TU16, time )

	/*<<调整能力集分辨率>>
	* tMtRpRes : 所有支持的分辨率
	* 所有支持的分辨率，暂时底层只是覆盖264的分辨率
	* 消息流向 ：conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_AdjustH264CapRes_Cmd )
	BODY(mt::TMtRpRes, tMtRpRes )


	/*<<关闭主流视频通道操作>>  
	* 消息流向 ：conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_MainVideoOff_Cmd )


	/*<<会议剩余时间>>  
	* rest_time : 会议剩余时间
	* 消息流向 ：conf==>dispatch==>sdk
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_RestTime_Ntf )
	BODY(mt::TU16, rest_time )

	
	////只有h323会发这条上去， 支持的会议类型
	MESSAGE( Ev_MT_BLL_Conf_NotifyConfType_Ntf )
	BODY(mt::TU32,   emMtConfType)
	BODY(mt::TU16,   bitrate)

	////协议栈初始化失败原因
	MESSAGE( Ev_MT_BLL_Conf_StackInitFailedReason_Ntf )
	BODY(mt::TU32,   emProtocol) //EmConfProtocol
	BODY(mt::TU32,   emStackInitFailReason) //EmStackInitFailReason

	////双流发送方通知
	MESSAGE( Ev_MT_BLL_Conf_DualStreamSender_Ntf )
	BODY(mt::TMtId,  tMtid)
	BODY(mt::TBOOL32, tGrabbed) /////是否当前终端被抢发

	////获取当前双流发送方请求
	MESSAGE( Ev_MT_BLL_Conf_GetDualStreamSender_Req )

	////获取当前双流发送方回复
	MESSAGE( Ev_MT_BLL_Conf_GetDualStreamSender_Rsp )
	BODY(mt::TMtId,  tMtid)

	/*<<设置发送包标记，支持平台端口复用>>
	*e164_param        ：e164号
	*stream_id         ：码流唯一标识
	*消息流向 ：service==>dispatch==>vnc
	*/
    MESSAGE(Ev_MT_BLL_Conf_SetStreamID_Cmd)
	BODY(mt::TString, e164_param)//e164号
	BODY(mt::TU32, stream_id)//码流唯一标识

	/*<<是否nat穿越设置>>
	*is_nattraversal   ：是否nat穿越
	*消息流向 ：service==>dispatch==>vnc
	*/
    MESSAGE(Ev_MT_BLL_Conf_IsNatTraversal_Cmd)
	BODY(mt::TBOOL32, is_nattraversal)//是否nat穿越
	BODY(mt::TNetAddr, rtp_local_addr)
	BODY(mt::TNetAddr, rtcp_local_addr)
	BODY(mt::TNetAddr, rtp_remote_addr)
	BODY(mt::TNetAddr, rtcp_remote_addr)
	////第一路视频发送接收通道关闭，用于致邻
	MESSAGE( Ev_MT_BLL_Conf_PrimoVideoOff_Ntf )
	
	/////协议栈重启， 先stop/start下去
	MESSAGE( Ev_MT_BLL_Conf_StackOnOff_Cmd )
	BODY(mt::TU32,    emProtocol) //协议
	BODY(mt::TBOOL32, bStart) //start/stop
	

	/////设置协议栈标准/非标
	MESSAGE( Ev_MT_BLL_Conf_SetStack_Cmd )
	BODY(mt::TU32,    emProtocol) //协议
	BODY(mt::TBOOL32, bStart) //start/stop
	

	/////白板会议创建通知
	MESSAGE( Ev_MT_BLL_Conf_DataConfCreatedNtf_Cmd )
	BODY(mt::TString, conf_name) //白板会议名字
	BODY(mt::TString, conf_e164) //白板会议e164

	///加入白板会议命令 用在点对点
	MESSAGE( Ev_MT_BLL_Conf_JoinDataConf_Cmd )
	BODY(mt::TString, conf_name) //白板会议名字
	BODY(mt::TString, str)       //

	///收到对端的加入白板会议命令 或者mcu, 或者对端
	MESSAGE( Ev_MT_BLL_Conf_JoinDataConf_Ntf )
	BODY(mt::TString, conf_name)  //白板会议名字
	BODY(mt::TString, str)        //

	
	/*<<主席指定终端发双流 chair->mc >>
	* mt_id :  终端的id
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ChairSpecTerSendAss_Cmd )
	BODY(mt::TMtId, mt_id)

	/*<<主席指定终端发双流 chair->mc >> 用于同步，
	* mt_id :  终端的id
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ChairSpecTerSendAss_Ntf )
	BODY(mt::TMtId, mt_id)

	/*<<主席指定终端发双流 chair->mc >> 用于同步，请求参数
	* mt_id :  终端的id
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ChairSpecTerSendAssParam_Req )

	/*<<主席指定终端发双流 chair->mc >> 用于同步，请求参数
	* mt_id :  终端的id
	* 消息流向 ：sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_MT_BLL_Conf_ChairSpecTerSendAssParam_Rsp )
	BODY(mt::TMtId, mt_id)

    //<<主席设置电话退会后重呼>> -- add by zwf
    MESSAGE( Ev_MT_BLL_Conf_ChairSetRecallDial_Cmd )
    BODY(mt::TBOOL32, bRecall)

    //<<主席设置电话退会后重呼通知>> -- add by zwf
    MESSAGE( Ev_MT_BLL_Conf_ChairSetRecallDial_Ntf )
    BODY(mt::TBOOL32, bRecall)

    //<< 电话退会后， 通知到界面， 界面决定是否重呼>> -- add by zwf
    MESSAGE( Ev_MT_BLL_Conf_IsRecallDial_Ntf )
    BODY(mt::TString, tDialNum)   ////电话号码

    //<<主席在界面选择是否重呼发到下层>> -- add by zwf
    MESSAGE( Ev_MT_BLL_Conf_RecallDial_Cmd )
    BODY(mt::TBOOL32, bRecall)
    BODY(mt::TString, tDialNum)

    //<<下层收到主席在界面的重呼选择后，通知所有界面>> -- add by zwf
    MESSAGE( Ev_MT_BLL_Conf_IsRecallDialResult_Ntf )
    BODY(mt::TBOOL32, bRecall)
    BODY(mt::TString, tDialNum)


	////请求gk与会成员列表，用于兼容
	MESSAGE( Ev_MT_BLL_Conf_GetGkRegMtList_Cmd )
	///gk回复
	MESSAGE( Ev_MT_BLL_Conf_GetGkRegMtList_Ntf )
	BODY(mt::TRpMtInfo,       mt_info)             //终端别名信息
	BODY(mt::TBOOL32,         bfinished)           //是否结束


    //<< 开始空闲云端录像 >> -- add by zwf
    MESSAGE( Ev_MT_BLL_Conf_StartSpareCloudRecord_Cmd )
    BODY(mt::TMtCallParam, record_param)

    //<< 停止空闲云端录像 >> -- add by zwf
    MESSAGE( Ev_MT_BLL_Conf_StopSpareCloudRecord_Cmd )
    BODY(mt::TU32, hangup_reason)

    //<< 空闲云端录像状态通知 >> -- add by zwf
    MESSAGE( Ev_MT_BLL_Conf_SpareCloudRecordState_Ntf )
    BODY(mt::TCloudRecordState, tCloudRecordState)
    
	//<< 空闲云端录像状态通知 >> -- add by zwf
	MESSAGE( Ev_MT_BLL_Conf_SpareCloudRecordState_Rsp )
	BODY(mt::TCloudRecordState, tCloudRecordState)


	//<< 停止空闲云端录像 >> -- add by zwf
	MESSAGE( Ev_MT_BLL_Conf_GetSpareCloudRecordState_Req )


	MESSAGE(Ev_MT_BLL_Conf_AuthResult_Ntf)       //授权结果
	BODY(mt::TBOOL32,     bauthsuc)              //是否授权


	/*<<对端视频源指示 >>
	* tRpVideoInfo:    对端视频源索引
	*/
	MESSAGE( Ev_MT_BLL_Conf_PeerVideoSrc_Ntf )
	BODY(TRpVideoInfo, tRpVideoInfo)

	/*<<平台回复终端tmtid的视音频列表 >>
	* tMtId       :    终端id
	* tRpVideoInfo:    视频源索引
	*/
	MESSAGE( Ev_MT_BLL_Conf_TerGetTerVideoAlias_Ntf )
	BODY(TMtId,        tMtId )
	BODY(TRpVideoInfo, tRpVideoInfo)


	/*<<当前发言人视频源列表 >>
	* tRpVideoInfo:    视频源索引
	*/
	MESSAGE( Ev_MT_BLL_Conf_TerGetTerVideoAlias_Cmd )
	BODY(TMtId,        tMtId )
	

	/*<<对端视频源指示 >>
	* tRpVideoInfo:    对端视频源索引
	*/
	MESSAGE( Ev_MT_BLL_Conf_PeerVideoSrc_Req )

	/*<<对端视频源指示 >>
	* tRpVideoInfo:    对端视频源索引
	*/
	MESSAGE( Ev_MT_BLL_Conf_PeerVideoSrc_Rsp )
	BODY(TRpVideoInfo, tRpVideoInfo)


	/////UI设置能力下去
	MESSAGE(Ev_MT_BLL_Conf_SetCallCap_Cmd)    
	BODY(mt::TMtCap,     tCap)              //能力集
	BODY(mt::TU32,    tPro)              //呼叫协议

	////设置dtmf密码
	MESSAGE(Ev_MT_BLL_Conf_PasswordDtmf_Cmd)
	BODY(mt::TString, tPwd)

	//获取当前轮询终端请求
	MESSAGE(Ev_MT_BLL_Conf_GetCurPollMt_Req)

	//获取当前轮询终端响应
	MESSAGE(Ev_MT_BLL_Conf_GetCurPollMt_Rsp)
	BODY(mt::TMtId, tMt)

	///pc是否enable fec
	MESSAGE(Ev_MT_BLL_Conf_Pc_EnableFec_Cmd)
	BODY(mt::TBOOL32, bEnable)

	///同步sdk层缓存
	MESSAGE(Ev_MT_BLL_Conf_SyncApplyerList_Ntf)
	BODY(mt::TU32,    type) //类型
	
	/*<<peermt回复终端预置位列表 >>
	*/
	MESSAGE( Ev_MT_BLL_Conf_TerCameroPos_Ntf )
	BODY(mt::TMTAllPreSetNameInfoCfg, tCfg)

	/*<<mc回复终端预置位列表 >>
	*/
	MESSAGE( Ev_MT_BLL_Conf_TerGetTerCameraPos_Ntf )
	BODY(mt::TMtId, tMtId)
	BODY(mt::TMTAllPreSetNameInfoCfg, tCfg)


	/*<< 播放一路码流>>
	* bOpen ：开或者关
	* tPcRtcp ： pc的rtcp地址
	* emCodecType: 解码类型
	* emCodecIdx： 解码索引
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_PlayStream_Cmd )
	BODY(mt:TBOOL32,  bOpen)                       //true : open；  false: close
	BODY(mt:TNetAddr, tPcRtcp)                     //pcRtcp地址  
	BODY(mt::TU32,   emCodecType)                  //emCodecType
	BODY(mt::TU32,   emCodecIdx)                   //emCodecIdx

	/*<<TT端走IPW方式，音频通道参数上报>>
	* codec_type ：码流类型
	* encoder_id ：码流索引
	* rtp_local_addr   ：发送rtp包的本地地址
	* rtcp_local_addr  ：发送接收rtcp包的本地地址
	* rtp_remote_addr  ：发送rtp包的远端目的地址
	* rtcp_remote_addr ：发送rtcp包的远端目的地址
	* aud_enc_param ：音频编码参数
	* bG7221Reverse : g7221反转标志
	* payload : 动态载荷
	* key : 秘钥
	* 消息流向 ：service==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_AudEncChanParam_Ntf )   //音频通道的所有信息
	BODY(mt::TS32, codec_type) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TNetAddr, rtp_local_addr)
	BODY(mt::TNetAddr, rtcp_local_addr)
	BODY(mt::TNetAddr, rtp_remote_addr)
	BODY(mt::TNetAddr, rtcp_remote_addr)
	BODY(mt::TAudEncDecParam, aud_enc_param)
	BODY(mt:TBOOL32,  bG7221Reverse) 
	BODY(mt::TDynamicPayload, payload) 
	BODY(mt::TEncryptKey, key)

	/*<<TT端走IPW方式，视频通道参数上报>>
	* codec_type ：码流类型
	* encoder_id ：码流索引
	* rtp_local_addr   ：发送rtp包的本地地址
	* rtcp_local_addr  ：发送接收rtcp包的本地地址
	* rtp_remote_addr  ：发送rtp包的远端目的地址
	* rtcp_remote_addr ：发送rtcp包的远端目的地址
	* vid_enc_param ：视频编码参数
	* payload : 动态载荷
	* key : 秘钥
	* 消息流向 ：service==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_VidEncChanParam_Ntf )   //视频通道的所有信息
	BODY(mt::TS32, codec_type) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TNetAddr, rtp_local_addr)
	BODY(mt::TNetAddr, rtcp_local_addr)
	BODY(mt::TNetAddr, rtp_remote_addr)
	BODY(mt::TNetAddr, rtcp_remote_addr)
	BODY(mt::TVidEncParam, vid_enc_param)
	BODY(mt::TDynamicPayload, payload) 
	BODY(mt::TEncryptKey, key)

	/*<<TT端走IPW方式, 是否nat穿越上报>>
	* codec_type ：码流类型
	* encoder_id ：码流索引
	* is_nattraversal   ：是否nat穿越
	* rtp_local_addr   ：发送rtp包的本地地址
	* rtcp_local_addr  ：发送接收rtcp包的本地地址
	* rtp_remote_addr  ：发送rtp包的远端目的地址
	* rtcp_remote_addr ：发送rtcp包的远端目的地址
	*消息流向 ：service==>dispatch==>sdk
	*/
    MESSAGE( Ev_MT_BLL_Conf_IsNatTraver_Ntf )
	BODY(mt::TS32, codec_type)  //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, encoder_id)  //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TBOOL32, is_nattraversal) //是否nat穿越
	BODY(mt::TNetAddr, rtp_local_addr)
	BODY(mt::TNetAddr, rtcp_local_addr)
	BODY(mt::TNetAddr, rtp_remote_addr)
	BODY(mt::TNetAddr, rtcp_remote_addr)

	/*<<TT端走IPW方式, 开始编码上报>>
	* codec_type ：码流类型
	* encoder_id ：码流索引
	*消息流向 ：service==>dispatch==>sdk
	*/
    MESSAGE( Ev_MT_BLL_Conf_StartEnc_Ntf )
	BODY(mt::TS32, codec_type) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	
	/*<<TT端走IPW方式, 停止编码上报>>
	* codec_type ：码流类型
	* encoder_id ：码流索引
	*消息流向 ：service==>dispatch==>sdk
	*/
    MESSAGE( Ev_MT_BLL_Conf_StopEnc_Ntf )
	BODY(mt::TS32, codec_type) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<TT端走IPW方式, mcu调整分辨率>>
	* codec_type ：码流类型
	* encoder_id ：码流索引
	* width : 宽度
	* height ：高度
	*消息流向 ：service==>dispatch==>sdk
	*/
    MESSAGE( Ev_MT_BLL_Conf_SetEncRes_Ntf )
	BODY(mt::TS32, codec_type) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TU16, width)
	BODY(mt::TU16, height)

	/*<<TT端走IPW方式, mcu调整帧率>>
	* codec_type ：码流类型
	* encoder_id ：码流索引
	* fps : 帧率
	*消息流向 ：service==>dispatch==>sdk
	*/
    MESSAGE( Ev_MT_BLL_Conf_SetEncFps_Ntf )
	BODY(mt::TS32, codec_type) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TU8,  fps)

	/*<<TT端走IPW方式, 设置编码码率>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*bitrate    ：码率
	*消息流向 ：service==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_SetBitrate_Ntf )
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex
	BODY(mt::TU16, bitrate)

	/*<<TT端走IPW方式, 请求关键帧>>
	*codec_type ：码流类型
	*encoder_id ：码流索引
	*消息流向 ：service==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_FastUpdate_Ntf )
	BODY(mt::TS32, codec_type)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent
	BODY(mt::TS32, encoder_id) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex

	/*<<请求当前会议加密类型>>
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetEncryptType_Req )

	/*<<当前会议加密类型响应>>
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetEncryptType_Rsp )    
	BODY(mt::TU32, tdwEncryptType)   //mt::EmSrtpCryptoType 

	/*<<请求当前会议callid>>
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetCallId_Req )

	/*<<当前会议callid响应>>
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetCallId_Rsp )
	BODY(mt::TString, tStrCallId)

	/*<<通过osd来打开/关闭pc双流命令，暂时用于sky100，sky100不支持硬双流>>
	* bOpen ：开或者关
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_OsdCtrlPcAssStream_Cmd )
	BODY(mt:TBOOL32,  bOpen)                       //true : open；  false: close

	/*<<<通过osd来打开/关闭pc双流通知>>
	* bOpen ：开或者关
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_OsdCtrlPcAssStream_Ntf )
	BODY(mt:TBOOL32,  bOpen)                       //true : open；  false: close
	
	/*<<<会议取消保活通知>>
	* 消息流向 ：mp==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_ConfNotKeepAlive_Ntf )

	/*<<是否订阅平台的终端列表>>
	*消息流向 ui -> mtservice
	*/
	MESSAGE( Ev_MT_BLL_Conf_SubMtList_Cmd )
	BODY(mt:TBOOL32,  bSub ) 

	MESSAGE( Ev_MT_BLL_Conf_SrtpCrypto_Ntf)     ///将srtp的一些参数报给界面
	BODY(mt::TSrtpCrypto,     tSrtpCrypto) 


	/*<<获取是否关闭主流请求>>
	* 消息流向 ：sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetCloseMainVid_Req)             

	/*<<<获取是否关闭主流回应>>
	* bClose ：是否关主流
	* 消息流向 ：conf==>dispatch==>sdk
	*/
	MESSAGE( Ev_MT_BLL_Conf_GetCloseMainVid_Rsp )
	BODY(mt:TBOOL32,  bClose)                       //true : close；

	/*<<摄像头是否正在升级查询>>
	*消息流向 : sdk==>dispatch==>device
	*/
	MESSAGE(Ev_MT_BLL_GetIsCameraUpgrading_Req)

	/*<<摄像头是否正在升级查询回复>>
	*is_upgrading : TRUE表示正在升级，FALSE表示不在升级
	*消息流向 : device==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_GetIsCameraUpgrading_Rsp)
	BODY(mt::TBOOL32, is_upgrading)

	/*<<更新厂商检测配置信息>>
	*消息流向 : conf==>dispatch==>device
	*/
	MESSAGE(Ev_MT_BLL_Conf_SetVendorCheckConfig_Cmd)
	BODY(mt::TVendorCheckConfig,  tVenCheckCfg)

	/*<<更新厂商检测配置信息通知>>
	*消息流向 : device==>dispatch==>conf
	*/
	MESSAGE(Ev_MT_BLL_Conf_SetVendorCheckConfig_Ntf)
	BODY(mt::TBOOL32,  is_peerkdvdevice)

	
#if !defined(_MESSAGE_HELP_)
	EV_BLL_END(CONF) = EVSEG_BLL_CONF_END
};
#endif

#define Is_BLL_Mtconf_Msg(m) ((m) >= EV_BLL_BGN(CONF) && (m) <= EV_BLL_END(CONF))

#endif