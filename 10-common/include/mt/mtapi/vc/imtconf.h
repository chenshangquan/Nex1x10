/**===========================================================================
 * @file    $Id$
 * @brief   负责终端会控相关的接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTCONF_H_
#define _I_MTCONF_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_vc.h"
#include "mtapi_container.h"



/**---------------------------------------------------------------------------
 * @class   Interface IMtConf
 * @brief   负责终端会控相关的接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtConf : public IMtApiIF
{
public:
	//主动呼叫
	virtual u32 MakeCallCmd( const s8* pszCalledInfo, const u16 wRate, const EmConfProtocol_Api emPro ) = 0;
	//呼叫 上层指定呼叫类型
	virtual u32 MakeCallCmd( const TMtAddr_Api tCalledAddr, const u16 wRate, const EmConfProtocol_Api emPro ) = 0;
	//通过setup创建会议
	virtual u32 SetupCreateConf(  const TMtSetupCreateConfParam_Api& tCallParam ) = 0;

	//手动接听
	virtual u32 AcceptCmd() = 0;
	//拒绝接听
	virtual u32 RejectConfCmd() = 0;
	//挂断会议，不区分点对点和多点
	virtual u32 HangupConfCmd( const EmMtCallDisReason_Api emReason ) = 0; 
	//当前呼叫状态请求
	virtual u32 GetConfLinkStateReq() = 0;
	//请求会议列表
	virtual u32 GetConfListReq( const u32 dwCmdType ) = 0;
	//请求加入会议
	virtual u32 JoinConfCmd( CONST TMtJoinConfParam_Api& tCallParam ) = 0;
	//请求创建会议
	virtual u32 CreateConfCmd( const TMtCreateConfParam_Api& tCallParam ) = 0;
	//请求会议详细信息 
	virtual u32 GetConfDetailCmd( const s8* pszConfE164 ) = 0;
	//请求会议室数量 
	virtual u32 GetConfListNumCmd() = 0;
	//请求当前会议所有在线终端 
	virtual u32 GetOnLineTerListReq() = 0;
	//请求当前会议所有不在线终端 
	virtual u32 GetOffLineTerListReq() = 0;
	//会议信息请求
	virtual u32 GetConfInfoCmd( ) = 0;
	//会议信息请求
	virtual u32 GetConfInfoReq( ) = 0;
	//会议label请求
	virtual u32 GetSelfLabelReq( ) = 0;

	//请求发送，接收双流状态
	virtual u32 GetAssSndVidStatusReq() = 0;
	virtual u32 GetAssRcvVidStatusReq() = 0;

	//会议密码设置
	virtual u32 SetConfPwdCmd( const s8* pszPwd ) = 0;
	//挂断会议终端
	virtual u32 DropConfTerCmd( const TMtId_Api& tMtId ) = 0;
	//结束会议
	virtual u32 EndConfCmd() = 0;
	//主席延长会议
	virtual u32 ProlongConfTimeCmd( const u16 wTime ) = 0;
	//主席邀请终端
	virtual u32 InviteTerCmd( const TMtAddr_Api& tAddr, const BOOL32 bVideoCall ) = 0;
	//主席呼叫离线终端
	virtual u32 CallOffLineTerCmd( const TMtId_Api& tAddr ) = 0;
	//调整264支持的分辨率
	virtual u32 AdjustH264Res( const EmMtResolution_Api *ptRes, const u32 dwResNum ) = 0;
	//切换音频+双流模式
	virtual u32 MainVideoOff( ) = 0;
	//修改会议名称
	virtual u32 ModifyConfNameCmd( const s8* pszConfName ) = 0;
	//修改画面合成是否显示别名
	virtual u32 ModifyVmpShowAliasCmd( const BOOL32 bShow ) = 0;

	////设置协议栈标准非标
	virtual u32 SetStack( const BOOL32 bStand, const EmConfProtocol_Api emPro ) = 0;

	//重启协议栈
	virtual u32 StackOnOff( const BOOL32 bStart, const EmConfProtocol_Api emPro) = 0;

	//修改会议时间
	virtual u32 ModifyConfTimeCmd( const u16 wTime ) = 0;
	
	virtual u32 SetConfDumb( const BOOL32 bDumb ) = 0;
	virtual u32 SetConfNoDisturb( const BOOL32 bEnable ) = 0;
	//修改会议密码
	virtual u32 ModifyConfPwdCmd( const BOOL32 bUsedPwd, const s8*  pszPwd ) = 0;
	//修改双流发送类型
	virtual u32 SetAssStreamSendModCmd( const u32 dwMode ) = 0;
	//申请发言操作
	virtual u32 ApplySpeakerCmd() = 0;
	//主席同意某终端的申请发言
	virtual u32 AccpetSpeakerCmd( const TMtId_Api& tMtId ) = 0;
	//拒绝申请发言操作
	virtual u32 RejectApplySpeakerCmd() = 0;
	//主席指定发言终端
	virtual u32 ChairSpecSpeakerCmd( const TMtId_Api& tMtId ) = 0;

	//主席取消发言人
	virtual u32 ChairWithDrawSpeakerCmd() = 0;
    //获取正在观看的视频源
	virtual	u32 GetVideoSeeingReq() = 0;
	//申请主席请求
	virtual u32 ApplyChairmanCmd() = 0;
	//拒绝申请主席请求
	virtual u32 RejectApplyChairmanCmd() = 0;
	//释放主席权限
	virtual u32 WithDrawChairmanCmd() = 0;
	//主席终端查询
	virtual u32 WhoIsChairCmd() = 0;
	//主席指定新主席终端
	virtual u32 ChairSpecNewChairCmd( const TMtId_Api& tMtId  ) = 0;
	//主席指定vip终端
	virtual u32 ChairSpecVipCmd( const TMtId_Api* ptMtId, const u32 dwNum  ) = 0;

	///主席指定终端发双流
	virtual u32 ChairSpecTerSendAssCmd( const TMtId_Api& tMtId ) =0;
	virtual u32 ChairSpecTerSendAssParamReq( ) =0;

	virtual u32 GetVipList( TMtId_Api* ptMtId, u32 &dwNum ) = 0;

	virtual u32 GetVipListReq( ) = 0;

	//终端选看
	virtual u32 SeeSpecTerCmd( const TViewTerParam_Api &tParam) = 0;

	virtual u32 SeeSpecTerAss( const TMtId_Api& tMtId ) = 0;

	//取消选看
	virtual u32 CancelSeeTerCmd() = 0;
	//申请插话
	virtual u32 ApplyChimeCmd() = 0;

	//拒绝申请插话
	virtual u32 RejectApplyChimeCmd() = 0;

	//主席同意插话
	virtual u32 AcceptChimeCmd( const TMtId_Api& tMtId ) = 0;
	//主席指定插话终端
	virtual u32 ChairSpecChimeCmd( const TMtId_Api& tMtId ) = 0;
	//主席轮询
	virtual u32 MtChairPollCmd( const TMtPollInfo_Api& tMtPollInfo ) = 0;
	//获取指定终端的状态信息 ui->sdk->平台->sdk
	virtual u32 GetSpecTerStatusCmd( const TMtId_Api& tMtId ) = 0;
	//获取指定终端当前状态信息 ui->sdk
	virtual	u32  GetMtStatusByMtID( TMtEntityStatus_Api& tEntityStatusTmp, const TMtId_Api&  tMtId ) = 0;
	//获取指定终端列表状态信息
	virtual u32 GetTerListStatusReq() = 0; 
	//主席强制广播
	virtual u32 StartForceBroadcastCmd() = 0;
	//主席停止强制广播
	virtual u32 StopForceBroadcastCmd() = 0;
	//开始语音激励
	virtual u32 StartVacCmd() = 0;
	//停止语音激励
	virtual u32 StopVacCmd() = 0;
	//开始讨论模式
	virtual u32 StartDiscussCmd() = 0;
	//停止讨论模块
	virtual u32 StopDiscussCmd() = 0;

	///开始自主画面合成
	virtual u32 StartCustomVMPCmd( const TMtCustomVmpParam_Api& tMtVmpParam ) = 0;
	//停止自主画面合成(主席)
	virtual u32 StopCustomVMPCmd() = 0;
	//设置自主画面合成参数信息
	virtual u32 SetCustomVMPParamCmd( const TMtCustomVmpParam_Api& tMtVmpParam ) = 0;

	//开始会议画面合成(主席)
	virtual u32 StartConfVMPCmd( const TMtVmpParam_Api& tMtVmpParam ) = 0;
	//停止会议画面合成(主席)
	virtual u32 StopConfVMPCmd() = 0;
	//设置画面合成参数信息
	virtual u32 SetConfVMPParamCmd( const TMtVmpParam_Api& tMtVmpParam ) = 0;
	//获取画面合成参数
	virtual u32 GetConfVMPParamCmd() = 0;
	//远端哑音
	virtual u32 SetTerMuteCmd( const TMtId_Api& tMtId, const BOOL32 bMute ) = 0;	
	//远端静音
	virtual u32 SetTerQuiteCmd(const TMtId_Api& tMtId, const BOOL32 bQuiet ) = 0;
	//切换画面合成风格
	virtual u32 SwitchBroadCastStyleCmd( const BOOL32 bSingle ) = 0;
	//终端选看画面合成请求(仅限主席MT)
	virtual u32 SelectVmpCmd( const BOOL32 bStart ) = 0;
	
	//开始定制混音
	virtual u32 StartCustomMixCmd( const TMtId_Api* ptArrMt, const u8 byCount ) = 0;
	//停止定制混音
	virtual u32 StopCustomMixCmd() = 0;

	//添加混音成员
	virtual u32 AddMixMemberCmd( const TMtId_Api* ptArrMt, const u8 byCount ) = 0;
	//删除混音成员
	virtual u32 RemoveMixMemberCmd(const TMtId_Api* ptArrMt, const u8 byCount ) = 0;
	//获取混音成员列表请求
	virtual u32 GetMixMemberListReq() = 0;
	//短消息发送
	virtual u32 SendConfSmsCmd( const TShortMsg_Api& tShortMsg ) = 0;

	//Fxo呼叫
	virtual u32 FxoMakeCallCmd( const s8 * pchPeerNumber ) = 0;
	//Fxo接受呼叫
	virtual u32 FxoAcceptCmd( ) = 0;
	//Fxo拒绝接听
	virtual u32 FxoRejectCmd( ) = 0;
	//Fxo挂断电话
	virtual u32 FxoHangupCmd( ) = 0;

	//白板会议创建通知 mt -> mcu
	virtual u32 DataConfCreatedNtf( const s8* pszConf_name, const s8* pszConf_e164 ) = 0;
	//加入白板会议命令点对点 mt -> mt
	virtual u32 P2PJoinDataConfCmd( const s8* pszConf_name, const s8* pszStr ) = 0;

    //设置平台录像功能-- add by zwf
    virtual u32 RemoteRecodeCmd( const BOOL32 bStart ) = 0;

	///获取联系人列表
	virtual u32 GetGkMtlist() = 0; 
	virtual u32 GetCloseMainVidReq() = 0;
public:
	//是否点对点会议中
	virtual BOOL32 IsInP2PConf() = 0;	
	//是否点对点会议中
	virtual BOOL32 IsInMulConf() = 0;
	//是否在会议中
	virtual BOOL32 IsInConf() = 0;
	//是否呼叫/被呼叫中
	virtual BOOL32 IsCalling() = 0;

	//获取当前辅流发送状态信息
	virtual TMtAssVidStatusList_Api GetCurAssSndVidStatus() = 0;
	//获取当前辅流接收状态信息
	virtual TMtAssVidStatusList_Api GetCurAssRcvVidStatus() = 0;
	
	//当前会议是否加密
	virtual BOOL32 IsEncryptConf() = 0;

	//请求当前会议是否加密
	virtual BOOL32 IsEncryptConfReq() = 0;
	//获取数据加密类型的请求
	virtual BOOL32 GetEncryptTypeReq() = 0;
	//本地终端是否在插话
	virtual BOOL32 IsInChime() = 0;
	//本地终端是否自定义混音
	virtual BOOL32 IsCustomMix() = 0;
	//是否在主席会议的画面合成中
	virtual BOOL32 IsInChairVmp() = 0;
	//是否在自主画面合成中
	virtual BOOL32 IsInCustomVmp() = 0;
	//是否开启语音激励
	virtual BOOL32 IsInVAC() = 0;
	//是否在轮询中
	virtual BOOL32 IsInPoll() = 0;
	//获取当前正在轮询的终端
	virtual TMtId_Api GetPollingMt() = 0;
	//是否在选看
	virtual BOOL32 IsViewMt() = 0;	
	virtual TViewTerParam_Api GetViewMtParam() = 0;
	//选看请求
	virtual u32 GetViewMtParamReq() = 0;

	//是否会议讨论模式
	virtual BOOL32 IsDiscussMode() = 0;
	//是否主席选看画面合成
	virtual BOOL32 IsInChairSelVmp() = 0;
	virtual BOOL32 IsSeeSpecTerAss() = 0;
	//获取可用的总的会议室数量
	virtual u32 GetTotalRoomNum() = 0;
	//获取已用的会议室数量
	virtual u32 GetUsedRoomNum() = 0;
	//获取结束会议到计时时间
	virtual u32 GetConfRemainTime() = 0;
	//获取会议中错过的呼叫信息
	virtual TMtMissCallParam_Api GetMissedCallParam( ) = 0;
	//获取自己的mtid信息
	virtual TMtId_Api GetSelfMtID() = 0;
	//获取对端的能力信息
	virtual TPeerCapabilityInfo_Api GetPeerCapInfo() = 0;
	//获取当前会议信息
	virtual TMtConfInfo_Api GetCurConfInfo() = 0;

	virtual TMultiVideoAlias_Api GetPeerVidAlias() = 0;
	
	virtual u32  GetPeerVidAliasReq() = 0; 


	virtual TMultiVideoInfo_Api GetPeerVidSrc() =0;
	virtual u32  GetPeerVidSrcReq() = 0;
	virtual u32 GetTerVidAlias(const TMtId_Api &tMtid) = 0;
	virtual TMtCallLinkSate_Api GetCurCallInfo()=0;
	//获取当前简单会议信息
	virtual TMtSimpConfInfo_Api GetCurSimpConfInfo() = 0;

	virtual TMtConfDetailInfo_Api GetConfDetialInfo() = 0;

	//获取发言终端
	virtual TMtId_Api GetSpeaker() = 0;
	//获取主席终端
	virtual TMtId_Api GetChairman() = 0;
	//获取选看终端
	virtual TMtId_Api GetSeenMt() = 0;
	//获取当前视频源
	virtual TMtId_Api GetVideoSrcMt( EmCodecComponentIndex_Api emChanIdx = em1st_Api ) = 0;
	//获取混音参数信息
	virtual TMtMixParam_Api GetMixParam() = 0;
	//获取会议画面合成参数信息
	virtual TMtVmpParam_Api GetConfVmpParam() = 0;
	//获取自主画面合成参数信息
	virtual TMtCustomVmpParam_Api GetCustomVmpParam() =0;
	//获取轮询参数
	virtual TMtPollInfo_Api GetCurPollParam() = 0;
	virtual u32 GetPollParamReq() = 0;
	//获取自主画面合成参数信息
	virtual u32 GetCustomVmpParamReq() =0;

	//获取用户会议个数
	virtual u32 GetConfListCnt( const EmConfListType_Api emConfListType ) = 0;
	//获取用户会议列表
	virtual u32 GetConfList( const u32 dwStartIdx,  TMtConfNameInfo_Api* ptOutBuf, u32& dwCnt, const EmConfListType_Api emConfListType ) = 0;
	//获取与会成员个数
	virtual u32 GetConfMtMemberCnt() = 0;
	//获取与会成员列表
	virtual u32 GetConfMtMember( const u32 dwStartIdx,  TMTEntityInfo_Api* ptOutBuf, u32& dwCnt ) = 0;
	virtual TMTEntityInfo_Api GetEntityInfo( const TMtId_Api & tMtid ) = 0;

	//获取与会成员状态个数
	virtual u32 GetConfMtMemberStatusCnt() = 0;
	//获取与会成员状态列表
	virtual u32 GetConfMtMemberStatus( const u32 dwStartIdx,  TMtEntityStatus_Api* ptOutBuf, u32& dwCnt ) = 0;
	//获取申请发言个数
	virtual u32 GetApplySpeakerListCnt() = 0;
	//获取申请主席个数
	virtual u32 GetApplyChairmanListCnt() = 0;
	//获取申请插话个数
	virtual u32 GetApplyChaimeInListCnt() = 0;
	//获取申请发言人列表
	virtual u32 GetApplySpeakerList( const u32 dwStartIdx,  TMtId_Api* ptOutBuf, u32& dwCnt ) = 0;
	//获取申请主席列表
	virtual u32 GetApplyChairmanList( const u32 dwStartIdx,  TMtId_Api* ptOutBuf, u32& dwCnt ) = 0;
	//获取申请插话列表
	virtual u32 GetApplyChaimeInList( const u32 dwStartIdx,  TMtId_Api* ptOutBuf, u32& dwCnt ) = 0;

public:
	//获取是否电话退会后重呼
	virtual BOOL32 GetRecallDial( ) = 0;
    //设置电话退会后重呼-- add by zwf
    virtual u32 SetRecallDial( const BOOL32 bRecall ) = 0;
    //决定电话退会后是否重呼--add by zwf
    virtual u32 DetermineRecallDial( const BOOL32 bRecall, const s8 *pchDialNum ) = 0;


    //开始空闲云端录像命令 -- add by zwf
    virtual u32 StartSpareCloudRecordCmd( const s8* pszRecordInfo, const u16 wRate, const EmConfProtocol_Api emPro ) = 0;
    //停止空闲云端录像命令 -- add by zwf
    virtual u32 StopSpareCloudRecordCmd( const EmMtCallDisReason_Api emReason ) = 0;
	virtual TCloudRecordState_Api GetCurSpareCloudRecordState() =0;
	virtual TMtId_Api GetDualStreamSenderMt() =0;
	virtual u32 GetSpareCloudRecordStateReq() = 0;
	virtual u32 SetCallCap( const TMtSendCap_Api &tSendCap, const TMtRecvCap_Api &tRecvCap, const EmConfProtocol_Api emPro ) =0;
	virtual u32 GetCurPollMtReq() = 0;
	virtual u32 GetDualStreamSenderReq() = 0;
	virtual u32 SetPasswordDtmf(const s8 *pszPasswordDtmf) = 0;

	virtual u32 GetTerCameroPos(const TMtId_Api &tMtid) = 0;
	virtual u32 GetCallIdReq() = 0;
	virtual u32 SetSubMtList( const BOOL32 bSub ) =0;

};

#endif // _I_MTCONF_H_