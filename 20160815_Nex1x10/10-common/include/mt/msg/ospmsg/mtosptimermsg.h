#ifndef _MTOSPTIMERMSG_H_
#define _MTOSPTIMERMSG_H_

#include "kdvtype.h"
#include "mtospmsgid.h"

//OSP的定时器消息统一在此定义
enum EmMtOspMsgTimer
{
	Ev_OspTimer_Start = EVSEG_MTOSPMSG_TIMER_BGN,

	Ev_Conf_CreateConf_Timer,        //创建会议超时定时器 

	Ev_Conf_JoinConf_Timer,          //加入会议超时定时

	/* 系统控制定时器 */
	Ev_SysCtrl_Timer_KeepAlive,		///< 定时扫描各个子系统是否存活的定时器

	Ev_Im_Timer_RetryLoginXmpp,		///< 重连XMPP定时器

	Ev_Im_Timer_Ping,				///< Ping定时器

	Ev_Im_Timer_OneSecond,          ///< 一秒定时器
	
	Ev_Im_Timer_MemberStatus, 		///< 用户状态定时器
	
	Ev_Rest_Timer_KeepPlatformSrvAlive, 		///< 保持和API平台的心跳 

	Ev_Timer_KeepAlive,				///< 每个模块定时扫描上报自己是存活的

	Ev_Timer_OperationCount,		///< 用于判断待机用的定时器

	/*网管子系统定时器消息定义开始*/
	Ev_OspTimer_GuardCheck,        ///<网管登录成功后一直检测的内容(暂时没有这个需求)
	Ev_OspTimer_GuardConfCheck,    ///<会议开始后一直检测的定时器
	Ev_OspTimer_CheckConnectNMS,   ///<检查链接网管服务器是否链接上的定时器
	Ev_OspTimer_CheckRegNMS,       ///<检查登录网管服务器是否登录上的定时器
	Ev_OspTimer_NMSHeartBeat,      ///<保持网管服务器心跳的定时器
	Ev_OspTimer_CheckCodecStatis,      ///<获取音视频统计信息定时器
    Ev_OspTimer_AgentUploadFile,  ///上传文件标志
	/*网管子系统定时器消息定义结束*/

	Ev_OspTimer_MtStandbyCountDown,		///< 终端待机倒计时
	Ev_OspTimer_MtAutoStandbyCheck,		    ///< 自动待机检测定时器
	Ev_OspTimer_MtStandbyWakeupCheck,		///< 待机/唤醒超时检测定时器
	Ev_OspTimer_MtCaptureStateCheck,		///< 抓包状态检测

	Ev_H323_ConfEstablish_Timer,             ///<323模块， 呼叫建立超时没有收到connect,或disconnect
	Ev_H323_DisConnect_Timer,                ///<323模块， 挂断呼出去超时没收到disconnect
	Ev_H323_SendTroudTrip_Timer,             ///<323模块， 发送troudtrip定时器
	Ev_H323_RasLRRQTimer,                    ///<323模块， ras 轻量级注册定时器
	Ev_H239_TokenReqTimer,                   ///<323模块， h239申请token定时器
	Ev_H239_TokenOwerIndcateTimer,           ///<323模块， h239ower定时器
	Ev_H225_KeepAliveTimer,                  ///<323模块， 用于460中保活225信令 
	Ev_H245_KeepAliveTimer,                  ///<323模块， 用于460中保活245信令
	Ev_H323_AskVcsPermitTimer,               ///<323模块， 用于强拆，发出askVcsReq后，超时没收到rsp

	Ev_Misc_BandwidthTestTimer,      ///< 带宽检测超时
	Ev_Misc_BandwidthTestRetryTimer, ///< 带宽检测重试定时器

	Ev_Upgrade_CheckUpgradeTimer,    //空闲时检测更新的定时器

	Ev_Mtpa_ConfEstablish_Timer,      /*mtpa层 呼叫建立超时没有收到connect,或disconnect,
	                                  pa会封装掉协议， 所以conf， mc不需要起定时器，conf, 
									  mc只需要关注callconnect, calldisconnect消息*/
	Ev_Mtpa_DisConnect_Timer,         //mtpa层 挂断呼出去超时没收到disconnect

	Ev_OspTimer_GetAllTerminalTimer,    //<用在sip 或者323模块,  获取终端列表， 平台分包， 超时认为结束
	Ev_OspTimer_BookConfListOverTimer, 
	Ev_OspTimer_TempConfListOverTimer,
	Ev_OspTimer_HoldConfListOverTimer,
// 	Ev_OspTimer_JoinConfTimer,       ///< 非标参加会议定时器
// 	Ev_OspTimer_CreateConfTimer,     ///< 非标创建会议定时器

	Ev_Dns_Query_Timer,
	Ev_Mc_PollBroadcast_Timer,       //mc轮询广播定时器
	Ev_Mc_PollApplyInfo_Timer,       //mc轮询申请信息
	Ev_Cfg_Persist_Timer,            //配置持久化定时器

	Ev_Conf_FeccTiltUpTimer,         ///< fecc定时器，收到远摇start后，超时没有收到stop命令，触发超时操作
	Ev_Conf_FeccTiltDownTimer,
	Ev_Conf_FeccPanLeftTimer,
	Ev_Conf_FeccPanRightTimer,
	Ev_Conf_FeccFocusInTimer,
	Ev_Conf_FeccFocusOutTimer,
	Ev_Conf_FeccZoomInTimer,
	Ev_Conf_FeccZoomOutTimer,
	Ev_Conf_FeccBrightUpTimer,
	Ev_Conf_FeccBrightDownTimer, 
	Ev_Conf_PollTimer,               ///< conf层轮询定时器,超时轮询下一个终端
	Ev_Conf_AutoCallTimer,           ///< 自动呼叫定时器，超时呼叫  
	Ev_Conf_TerInfoRecOverTimer,     ///< terinfo消息，分包收上来，如果超时没收到end,就认为截止
	

	/*mtmp模块定时器消息定义开始*/
	Ev_MP_1stDecStatis_Timer,        ///< 第一个解码器解码统计定时器
	Ev_MP_2ndDecStatis_Timer,        ///< 第二个解码器解码统计定时器
	Ev_MP_1stAskKeyFrame_Timer,        ///< 跟hd900对通时向对端请求关键帧定时器
	Ev_MP_CodecStatis_Timer,        ///< 写编解码统计到数据共享定时器
	Ev_MP_FxoCheckState_Timer,        ///< fxo状态检查定时器
    Ev_MP_FxoAutoReject_Timer,        ///< fxo超时自动挂断定时器
	Ev_MP_SleepProtection_Timer,        ///< 待机保护定时器
	/*mtmp模块定时器消息定义结束*/

    Ev_NET_CheckEthState_Timer,             ///< 网口检测定时器
    Ev_NET_GetEthStateTimeout_Timer,            ///< 向驱动查询网口状态超时定时器
    Ev_Gk_Register_Again_Timer,
    Ev_Aps_Relogin_Timer,
    Ev_Gk_Relogin_Timer,                    ///< 网络模块使用的重新登录GK定时器
	Ev_Rest_Timer_PollCometdMessage, 		///< 轮询平台推送的会议通知
	Ev_Rest_Timer_RetryLogin,               ///< 登录失败或连接断开时，设置该定时器
	Ev_Conf_PrimoVideoOff_Timer,            ///< 主流关掉后，2s后再回调给UI
	Ev_Rest_Timer_RetryGetToken,            ///< 获取账户token失败时，设置该定时器
	Ev_Conf_GetBweStatus_Timer,             ///< 定时获取带宽检测状态 5s
	Ev_Conf_GKUnReachble_Timer,             ///< 如果gk注册失败原因是 unreachble, 隔3s再注册
	Ev_Conf_SipUnReachble_Timer,            ///< 如果sip注册失败原因是 unreachble, 隔3s再注册
	Ev_Conf_ApplyChairTimer,                ///< UI申请主席 定时器
	Ev_Conf_ApplySpeakerTimer,              ///< UI申请发言人 定时器
	Ev_Conf_WaitForMccStartTimer,           ///< 超时如果没有收到mccstart,会认为是点对点状态
	Ev_Conf_ApplyChiemeInTimer,             ///< UI申请插话 定时器
    Ev_NET_CheckE1BandWidth_Timer,          ///< 检测E1带宽定时器
    Ev_NET_Get_E1_Route_Timer,              ///< 获取E1路由
	Ev_Conf_LoginNextAps_Timer,             ///< 超时登陆下一个aps(GK备份使用)
	Ev_H323_WaitLRRQRspTimer,               ///< 等待RRQ的回复 超时直接上报unreachable
	Ev_Vrs_KeepAliveTimer,                  ///< vod模块与vrs服务器的保活
	Ev_Vrs_ReLoginVrsTimer,                 ///< 网络异常后重新登录
	Ev_LoginAps_Timer,						///< 登陆aps(避免http消息太多导致平台崩溃)
	Ev_Rest_LoginMoPlatform_Timer,			//登陆微博服务器定时器
	Ev_H323_WaitPeerAgentInfoTimer,			///< 等待对端发送渠道产品的非标信令
	Ev_Sec_WaitStrongAut_Timer,				///< 等待平台发送渠道产品的非标信令
	Ev_Sec_WaitAuthCall_Timer,				///< 等待平台发送渠道产品的非标信令
	Ev_LoginAps_WaitCloseSockets_Timer,	 //登陆aps前等待关闭下层连接
	Ev_Dcs_Timer_RetryLoginConnect,         ///< 电子白板重新建链注册链路，设置该定时器
	Ev_Dcs_Timer_RetryLoginSrv,             ///< 电子白板重新注册服务器，设置该定时器
	Ev_Dcs_Timer_KeepSrvAlive, 				///< 保持和电子白板平台的心跳
	Ev_Dcs_Timer_JoinConf_OverTime,			///< 电子白板加入会议超时
	Ev_Dcs_Timer_GetConfAddr_OverTime,		///< 电子白板获取会议地址超时
//	Ev_Dcs_Timer_CloseConfSession,				///< 电子白板退出/离开会议超时需要关闭链路的定时器

    Ev_Im_Timer_RetryLoginIm,		        ///< 当终端登出账户，重新登陆时如果handle没有释放，那么循环等待一下
	Ev_Dcs_Timer_RetryDownloadCacheElement,				///< 重试下载缓存图元数据的定时器

    Ev_REST_Timer_CreateConference_OverTime,  ///<API创会超时
	Ev_LoginAps_WaitCloseOtherServer_Timer,   // 关闭其他服务器
    Ev_LoginAps_TryIfNetConnect_Timer,	      //登陆aps探测网络是否恢复

	Ev_DynamicPwd_Timer,                      //动态口令定时器
	Ev_Mtpa_TlsRenegotiate_Timer,             //重新协商tls密钥的定时器
	Ev_BsHandShake_Timer,                     //sdk发送handshake消息后，5s未回复，认为是老access的终端， 回复认为是newaccess的终端
    Ev_SendIrrFrequecy_Timer,                 ///323 发送irr定时器
	Ev_SipRegTimer,                           ///sip 注册超时定时器
	Ev_AiWakeupTimer,                         ///唤醒之后多久没命令，重新进入唤醒
	Ev_AiFilterAsrTimer,
	Ev_Conf_ChairRecvTerApplyChairTimer,	  ///终端申请主席定时器，用于清空主席端sdk层缓存
	Ev_Conf_ChairRecvTerApplySpeakTimer,      ///终端申请成为发言人，用于清空主席端sdk层缓存
	Ev_Conf_ChairRecvTerApplyChiemeInTimer,	  ///终端申请插话，用于清空主席端sdk层缓存
};

#endif