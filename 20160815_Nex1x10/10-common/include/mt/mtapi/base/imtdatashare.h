/**===========================================================================
 * @file    $Id$
 * @brief   负责终端数据中心数据操作的接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTDATASHARE_H_
#define _I_MTDATASHARE_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtEntity
 * @brief   负责终端数据中心数据操作的接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtDataShare : public IMtApiIF
{
public:
	//还原默认值
	virtual u32 RestoreDefaultCfgInfo( const TMTRestoreDefaultCfgInfo_Api &tCfg);

	//设置Qos配置命令 emMt_Cfg_IPQoS
	virtual u32 SetIPQoSCfgCmd( const TMTIPQoS_Api& tCfg );
	//获取Qos配置信息 emMt_Cfg_IPQoS
	virtual TMTIPQoS_Api GetIPQosCfg()=0;
	//设置MTU TCP/IP最大传输单元配置命令 emMt_Cfg_MTU
	virtual u32 SetMTUCfgCmd( const u32 dwMTU );
	// 获取TCP/IP最大传输单元MTU emMt_Cfg_MTU
	virtual u32 GetMTUCfg()=0;
	//设置NAT配置命令 emMt_Cfg_NAT
	virtual u32 SetNatCfgCmd( const TMTNat_Api& tCfg );
	//获取NAT配置 emMt_Cfg_NAT
	virtual TMTNat_Api GetNatCfg()=0;

	//
	//TL获取当前视频采集设备命令 (仅WIN32)
	virtual TDevInfo_Api GetCurVidCapDevCfg() = 0;

	//设置XAPList配置命令 emMt_Cfg_APSList
	virtual u32 SetXAPListCfgCmd( const TMtXAPSvrList_Api& tCfg );
	//获取XAP服务器列表emMt_Cfg_APSList
	virtual TMtXAPSvrList_Api GetXAPSvrList()=0;
	//获取当前使用的XAP服务器信息 emMt_Rt_CurAPS
	virtual TMtAPSSvrAddr_Api GetCurUsdXAPSvrRtCfg()=0;
	
	//获取XMPP登录配置 emMt_Rt_XNU
	virtual TMtXMPPInfo_Api GetXMPPCfg()=0;
    
    //获取NS服务IP
    virtual TMtNSADDRInfo_Api GetNSRtCfg()=0;

	//emMt_Rt_APS只有底层使用，不提供给界面

	//CSU服务器配置命令 emMt_Cfg_CSU
	virtual u32 SetCSUCfgCmd( const TMtCSUAddr_Api& tCfg );
	//获取CSU地址配置 emMt_Cfg_CSU
	virtual TMtCSUAddr_Api GetCSUAdrCfg()=0;
	virtual TMtCSUAddr_Api GetGkAdrCfg()= 0;
	//设置gk地址
	virtual u32 SetGKCfgCmd( const TMtCSUAddr_Api& tCfg );

	//SUS服务器配置命令 emMt_Cfg_SUS
	virtual u32 SetSUSCfgCmd( const TMTSUSAddr_Api& tCfg );

	virtual u32 SetSusManuCfgCmd( const TMTSUSAddr_Api& tCfg );

	//获取SUS升级服务器配置信息 emMt_Cfg_SUS
	virtual TMTSUSAddr_Api GetSUSSvrCfg()=0;

	virtual TMTSUSAddr_Api GetSusManuSvrCfg() = 0;

	//网管服务器配置命令 emMt_Cfg_NMS
	virtual u32 SetSNMPCfgCmd( const TMtNMAAddr_Api& tCfg );

	virtual u32 SetSNMPManuCfgCmd( const TMtNMAAddr_Api& tCfg );

	//获取网管服务器配置信息 emMt_Cfg_NMS
	virtual TMtNMAAddr_Api GetNMSSvrCfg()=0;

	virtual TMtNMAAddr_Api GetNmsManuSvrCfg() = 0;

	//测速服务器配置命令 emMt_Cfg_NTS
	virtual u32 SetNTSCfgCmd( const TMtNTSAddr_Api& tCfg );

	virtual u32 SetNtsManuCfgCmd( const TMtNTSAddr_Api& tCfg );

	//获取测速服务器配置 emMt_Cfg_NTS
	virtual TMtNTSAddr_Api GetNTSAdrCfg()=0;

	virtual TMtNTSAddr_Api GetNtsManuAdrCfg() = 0;

	//NTP服务器配置命令 emMt_Cfg_NTP
	virtual u32 SetNTPCfgCmd( const TMtNTPAddr_Api& tCfg );

	virtual u32 SetNtpManuCfgCmd( const TMtNTPAddr_Api& tCfg );

	//获取NTP服务器配置信息 emMt_Cfg_NTP
	virtual TMtNTPAddr_Api GetNTPSvrCfg()=0;

	virtual TMtNTPAddr_Api GetNtpManuCfg() = 0;

	//VOD服务器配置命令 emMt_Cfg_VOD
	virtual u32 SetVODCfgCmd( const TMtVODSvrCfg_Api& tCfg );
	//VRS服务器配置命令 emMt_Cfg_VRS
	virtual u32 SetVRSCfgCmd( const TMtVRSSvrCfg_Api& tCfg );
	//获取VOD服务器配置信息 emMt_Cfg_VOD
	virtual TMtVODSvrCfg_Api GetVODSvrCfg()=0;
	//获取VRS服务器配置信息
	virtual TMtVRSSvrCfg_Api GetVRSSvrCfg() = 0;

	//设置数据会议 emMt_Cfg_DCS (value: TMtDCSSvrAddr) 
	virtual u32 SetDCSCfgCmd( const TMtDCSSvrAddr_Api& tCfg );
	//获取数据会议 emMt_Cfg_DCS (value: TMtDCSSvrAddr) 
	virtual TMtDCSSvrAddr_Api GetDCSCfg()=0;

	//StreamPlayer流媒体配置命令 emMt_Cfg_StreamMedia
	virtual u32 SetStreamPlayerCfgCmd( const TMTStreamMedia_Api& tCfg );
	//获取流媒体配置信息 emMt_Cfg_StreamMedia
	virtual TMTStreamMedia_Api GetStreamPlayerCfg()=0;
	
	//获取平台服务接口地址 emMt_Rt_PlatformApi
	virtual TMtPlatformApiAddr_Api GetPlatformApiRtCfg( ) = 0;

	//获取微博服务器 emMt_Rt_MicroBlog
	virtual TMtMicroBlogAddr_Api GetMicroBlogRtCfg( ) = 0;

	//Sip服务器配置命令 emMt_Cfg_SipSvr
	virtual u32 SetSipSvrCfgCmd( const TMtSipSvrAddr_Api& tCfg );

	virtual u32 SetManuSipSvrCfgCmd( const TMtSipSvrAddr_Api& tCfg );

	//获取Sip服务器配置信息 emMt_Cfg_SipSvr
	virtual TMtSipSvrAddr_Api GetSipSvrCfg()=0;

	virtual TMtSipSvrAddr_Api GetSipSvrManuCfg() = 0;

	//Socket5代理配置命令 emMt_Cfg_Socks5Pxy
	virtual u32 SetSocks5PxyCfgCmd( const TSocks5ProxyCfg_Api& tCfg );
	//获取Socket5配置信息 emMt_Cfg_Socks5Pxy
	virtual TSocks5ProxyCfg_Api GetSocks5ProxyCfg()=0;

	//登录策略emMt_Cfg_SvrLoginTactics
	virtual u32 SetLoginTacticsCfgCmd( const TMtLoginTacticsTable_Api & tLoginCfg );
	virtual TMtLoginTacticsTable_Api GetLoginTacticsCfg( ) = 0;


	//获取终端服务器登录状态信息 emMt_Rt_SvrLoginStatus
	virtual TMtSvrStateList_Api GetSvrStateList()=0;

	//获取登陆APS返回的用户权限(value: TMTUserPrevilege)  emMt_Rt_UserPrevilege
	virtual TMtUserPrevilege_Api GetUserPrevilegeCfg()=0;

	//登陆APS返回的用户信息 (value: TMTUserInfoFromAps) emMt_Rt_UserInfoFromAps
	virtual TMTUserInfoFromAps_Api GetUserInfoFromApsRt()=0;

	//设置H323配置命令 emMt_Cfg_H323
	virtual u32 SetH323CfgCmd( const TMtH323Cfg_Api& tCfg );
	//获取H323配置信息 emMt_Cfg_H323
	virtual TMtH323Cfg_Api GetH323Cfg()=0;

	//设置SIP配置命令 emMt_Cfg_Sip
	virtual u32 SetSipCfgCmd(const TMtSipCfg_Api &tCfg);
	//获取SIP配置信息 emMt_Cfg_Sip
	virtual TMtSipCfg_Api GetSipCfg() = 0;
	
	//设置内置MC配置命令 emMt_Cfg_MC
	virtual u32 SetMCCfgCmd( const BOOL32 bEnable );
	// 配置是否启用内置MC emMt_Cfg_MC
	virtual BOOL32 IsUsedMC()=0;

	//设置音频输入音量配置命令 emMt_Cfg_AudVolIn
	virtual u32 SetAudVolInCfgCmd( const u32 dwVolIn );
	// 获取音频输入音量 emMt_Cfg_AudVolIn
	virtual u32 GetAudInVolCfg()=0;
	//设置音频输出音量配置命令 emMt_Cfg_AudVolOut
	virtual u32 SetAudVolOutCfgCmd( const u32 dwVolOut );
	// 获取音频输出音量 emMt_Cfg_AudVolOut
	virtual u32 GetAudOutVolCfg()=0;
	//设置自动噪声增益 emMt_Cfg_Ans
	virtual u32 SetAudAnsCfg( const BOOL32 bAns );
	//获取自动噪声增益 emMt_Cfg_Ans
	virtual BOOL32 GetAudAnsCfg( ) = 0;
	//设置自动增益控制 emMt_Cfg_Agc
	virtual u32 SetAudAgcCfg( const BOOL32 bAgc );
	//获取自动增益控制 emMt_Cfg_Agc
	virtual BOOL32 GetAudAgcCfg( ) = 0;
	//设置自动回声抵消 emMt_Cfg_Aec
	virtual u32 SetAudAecCfg( const TAdjustAecParamCfg_Api & bAec );
	//获取自动回声抵消 emMt_Cfg_Aec
	virtual TAdjustAecParamCfg_Api GetAudAecCfg() = 0;
	//设置丢包重传参数配置命令emMt_Cfg_LostPktResend
	virtual u32 SetLostPackResendCfgCmd( const TPrsParam_Api& tCfg );
	//获取丢包重传参数配置信息emMt_Cfg_LostPktResend
	virtual TPrsParam_Api GetLostPackResendCfg()=0;
	//设置音质优先配置命令emMt_Cfg_AudioPrecedence
	virtual u32 SetAudioPrecedenceCfgCmd( const BOOL32  emCfg );
	// 配置音质优先emMt_Cfg_AudioPrecedence
	virtual BOOL32 GetAudioPrecedence()=0;

	//设置主视频编码器参数  (value: TMTAllVideoEncoderParamCfg) emMt_Cfg_PriVidEncParam
	virtual u32 SetPriVidEncParamCfgCmd( const TMTAllVideoEncoderParamCfg_Api& tCfg );
	//获取主视频编码器参数  (value: TMTAllVideoEncoderParamCfg) emMt_Cfg_PriVidEncParam
	virtual TMTAllVideoEncoderParamCfg_Api GetPriVidEncParamCfg()=0;
	//设置辅视频编码器参数  (value: TMTAllVideoEncoderParamCfg)emMt_Cfg_AssVidEncParam
	virtual u32 SetAssVidEncParamCfgCmd( const TMTAllVideoEncoderParamCfg_Api& tCfg );
	//获取辅视频编码器参数  (value: TMTAllVideoEncoderParamCfg)emMt_Cfg_AssVidEncParam
	virtual TMTAllVideoEncoderParamCfg_Api GetAssVidEncParamCfg()=0;
	//设置视频解码器参数  (value: TMTAllVideoDecoderParamCfg)emMt_Cfg_VideoDecParam
	virtual u32 SetVideoDecParamCfgCmd( const TMTAllVideoDecoderParamCfg_Api& tCfg );
	//获取视频解码器参数  (value: TMTAllVideoDecoderParamCfg)emMt_Cfg_VideoDecParam
	virtual TMTAllVideoDecoderParamCfg_Api GetVideoDecParamCfg()=0;

	// 设置音频优选 emMt_Cfg_AudioPrior
	virtual u32 SetAudioPriorCfgCmd( const TMTAudioPriorCfg_Api &tCfg );
	// 获取音频优先模式 emMt_Cfg_AudioPrior
	virtual TMTAudioPriorCfg_Api GetAudioPriorCfg()=0;
	// 设置主流优选 emMt_Cfg_PriVidPrior
	virtual u32 SetPriVidPriorCfgCmd( const TMTPriVidPriorCfg_Api &tCfg );
	// 获取主流优选 emMt_Cfg_PriVidPrior
	virtual TMTPriVidPriorCfg_Api GetPriVidPriorCfg()=0;
	// 设置Pc辅流优选 emMt_Cfg_PcAssVidPrior
	virtual u32 SetPcAssVideoPriorCfgCmd( const TVidPriorParam_Api &tCfg );
	// 获取Pc辅流优选 emMt_Cfg_PcAssVidPrior
	virtual TVidPriorParam_Api GetPcAssVideoPriorCfg()=0;
	// 设置Vid辅流优选 emMt_Cfg_VidAssVidPrior
	virtual u32 SetVidAssVideoPriorCfgCmd( const TVidPriorParam_Api &tCfg );
	// 获取Vid辅流优选 emMt_Cfg_VidAssVidPrior
	virtual TVidPriorParam_Api GetVidAssVideoPriorCfg()=0;

	//设置会议中是否允许播放动画音效(value: TBOOL32)emMt_Cfg_PlayAniSoundInIdle
	virtual u32 SetPlayAniSoundInIdleCfgCmd( const BOOL32 bCfg );
	//获取会议中是否允许播放动画音效(value: TBOOL32)emMt_Cfg_PlayAniSoundInIdle
	virtual BOOL32 GetPlayAniSoundInIdleCfg()=0;
	//设置视频源 (value: TMTCodecVidSrcInfo) emMt_cfg_CodecVideoSrc
	virtual u32 SetCodecVideoSrcCfgCmd( const TMTCodecVidSrcInfo_Api& tCfg );
	//获取视频源 (value: TMTCodecVidSrcInfo) emMt_cfg_CodecVideoSrc
	virtual TMTCodecVidSrcInfo_Api GetCodecVideoSrcCfg()=0;

	//内置mc的运行信息(value: TInnerMCRunInfo) emMt_Rt_MCInfo
	virtual TInnerMCRunInfo_Api GetMCInfoRt()=0;

	// 获取呼叫信息 emMt_Rt_CallInfo
	virtual TMtCallLinkSate_Api GetCallInfoRt()=0;

	//当前的通道info， (value: TMutiChanDsInfo) emMt_Rt_ChanInfo
	virtual TMutiChanDsInfo_Api GetChanInfoRt()=0;

	//是否是卫星终端， 从平台获取(value: TMTSatelliteFlag) emMt_Rt_IsSatelliteMT
	virtual TMTSatelliteFlag_Api GetIsSatelliteMTRt()=0;

	//设置主席轮询方案   (value: TMTChrmanPollSchemeList) emMt_Cfg_ChrmanPollSchemes
	virtual u32 SetChrmanPollSchemesCfgCmd( const TMTChrmanPollSchemeList_Api& tCfg );
	//获取主席轮询方案   (value: TMTChrmanPollSchemeList) emMt_Cfg_ChrmanPollSchemes
	virtual TMTChrmanPollSchemeList_Api GetChrmanPollSchemesCfg()=0;

	//设置主席操作配置命令 emMt_Cfg_ChrmanOperate
	virtual u32 SetChairmanOperateCfgCmd( const BOOL32  bEnable );
	// 配置是否主席操作 emMt_Cfg_ChrmanOperate
	virtual BOOL32 IsUsedChairmanOptCtrl()=0;
	//设置会议状态显示配置命令 emMt_Cfg_ShowConfState
	virtual u32 SetShowConfStateCfgCmd( const BOOL32  bEnable );
	// 配置是否显示会议状态 emMt_Cfg_ShowConfState
	virtual BOOL32 IsUsedShowConfState()=0;

	//设置显示会议时间 (value: TBOOL32)emMt_Cfg_ShowConfTime
	virtual u32 SetShowConfTimeCfgCmd( const BOOL32 bCfg );
	//获取显示会议时间 (value: TBOOL32)emMt_Cfg_ShowConfTime
	virtual BOOL32 GetShowConfTimeCfg()=0;
    //设置显示系统时间 (value: TBOOL32)emMt_Cfg_ShowSystimeTime
	virtual u32 SetShowSystimeTimeCfgCmd( const BOOL32 bCfg );
	//获取显示系统时间 (value: TBOOL32)emMt_Cfg_ShowSystimeTime
	virtual BOOL32 GetShowSystimeTimeCfg()=0;
	//设置会议中是否显示短消息 (value: TBOOL32)emMt_Cfg_ShowShortMsgInConf
	virtual u32 SetShowShortMsgInConfCfgCmd( const BOOL32 bCfg );
	//获取会议中是否显示短消息 (value: TBOOL32)
	virtual BOOL32 GetShowShortMsgInConfCfg()=0;
	//设置是否显示申请提示 (value: TBOOL32)emMt_Cfg_ShowAppTips
	virtual u32 SetShowAppTipsCfgCmd( const BOOL32 bCfg );
	//获取是否显示申请提示 (value: TBOOL32)emMt_Cfg_ShowAppTips
	virtual BOOL32 GetShowAppTipsCfg()=0;

	//设置发送静态图片配置命令 emMt_Cfg_StaticPic
	virtual u32 SetStaticPicCfgCmd( const BOOL32  bEnable, const s8 *pszPicPath );
	// 配置是否启用发送静态图片 emMt_Cfg_StaticPic
	virtual BOOL32 IsUsedSendStaticPic()=0;
	//设置是否启用电话功能配置命令 emMt_Cfg_Telephone
	virtual u32 SetTelephoneCfgCmd( const BOOL32  bEnable );
	// 配置是否启用电话呼叫 emMt_Cfg_Telephone
	virtual BOOL32 IsUsedUsedTelphonc()=0;
	//设置自动呼叫配置命令 emMt_Cfg_AutoCall
	virtual u32 SetAutoCallCfgCmd( const TMTAutoCall_Api& tCfg );
	//获取自动呼叫配置信息 emMt_Cfg_AutoCall
	virtual TMTAutoCall_Api GetAutoCallCfg()=0;

	//设置是否允许远遥 (value: TBOOL32) emMt_Cfg_FECC 
	virtual u32 SetFECCCfgCmd( const BOOL32 bCfg );
	//获取是否允许远遥 (value: TBOOL32) emMt_Cfg_FECC 
	virtual BOOL32 GetFECCCfg()=0;

	//设置自动登录服务器配置命令 emMt_Cfg_AutoLogin
	virtual u32 SetAutoLoginCfgCmd( const BOOL32 bEnable );
	// 配置是否启用自动登录服务器 emMt_Cfg_AutoLogin
	virtual BOOL32 IsAutoLogin()=0;
	//设置非对称网络配置命令 emMt_Cfg_AsymmetricNet
	virtual u32 SetAsymmetricNetCfgCmd( const TAsymmetricNetInfo_Api& tCfg );
	//获取非对称网络配置信息 emMt_Cfg_AsymmetricNet
	virtual TAsymmetricNetInfo_Api GetAsymmetricNetInfoCfg()=0;
	//设置来电防火墙配置命令 emMt_Cfg_UseCallFW
	virtual u32 SetIncomingCallFWCfgCmd( const BOOL32 bEnable );
	// 配置是否启用来点防火墙 emMt_Cfg_UseCallFW
	virtual BOOL32 IsUsedCallFirewall()=0;
	//设置当前是否启用带宽检测配置命令 emMt_Cfg_BandWidthTest
	virtual u32 SetBandwidthCheckCfgCmd( const BOOL32 bEnable );
	// 配置是否启用自动带宽检测 emMt_Cfg_BandWidthTest
	virtual BOOL32 IsAutoBandwidthCheck()=0;
	//设置内置MC丢包重传参数配置命令 emMt_Cfg_MCResendParam
	virtual u32 SetMCRSParamCfgCmd( const TMTMcRSParam_Api& tCfg );
	//获取内置MC丢包重传参数配置信息 emMt_Cfg_MCResendParam
	virtual TMTMcRSParam_Api GetMcRSParamCfg()=0;
	//设置自动双流源配置命令 emMt_Cfg_DualStramSrcAdj
	virtual u32 SetAssStreamSrcAdjustCfgCmd( const BOOL32 bEnable );
	// 配置是否启用启动双流源 emMt_Cfg_DualStramSrcAdj
	virtual BOOL32 IsUsedAssStreamSrcAuto()=0;
	//设置呼叫协议类型配置命令 emMt_Cfg_CallProtocol
	virtual u32 SetCallProtocolCfgCmd( const EmConfProtocol_Api  emProtocol );
	// 获取呼叫协议类型 emMt_Cfg_CallProtocol
	virtual EmConfProtocol_Api GetConfCallProtocol()=0;
	// 获取会议加密类型 emMt_Cfg_EncryptType
	virtual u32 SetConfEncryptTypeCfgCmd( const EmEncryptArithmetic_Api emEncrypt );
	// 获取会议加密类型 emMt_Cfg_EncryptType
	virtual EmEncryptArithmetic_Api GetConfEncryptTypeCfg()=0;
	//设置断链检测时间间隔配置(秒) emMt_Cfg_KeepAliveItrvl
	virtual u32 SetKeepAliveItrvlCfgCmd( const u32 dwSec );
	// 获取断链检测时间配置 emMt_Cfg_KeepAliveItrvl
	virtual u32 GetKeepAliveIntervalCfg()=0;
	//设置Sip断链检测时间间隔配置(秒) emMt_Cfg_SipKeepAliveItrvl
	virtual u32 SetSipKeepAliveItrvlCfgCmd( const u32 dwSec );
	// 获取断链检测时间配置 emMt_Cfg_SipKeepAliveItrvl
	virtual u32 GetSipKeepAliveIntervalCfg()=0;
	//设置FEC配置命令 emMt_Cfg_FEC
	virtual u32 SetFecInfoCfgCmd( const TMTFecInfo_Api& tCfg );
	//获取FEC配置信息 emMt_Cfg_FEC
	virtual TMTFecInfo_Api GetFecInfoCfg()=0;
	//设置高中低档的会议码率配置命令(小于64任务是纯音频呼叫)emMt_Cfg_CallRateLv
	virtual u32 SetCallRateLevelCmd( const u32  dwCallRate );
	// 获取会议呼叫码率 emMt_Cfg_CallRateLv
	virtual u32 GetConfCallRateCfg()=0;
	//设置双流码率比例配置命令 emMt_Cfg_VidBitRation
	virtual u32 SetVidBitRationCfgCmd( const TVidBitRationCfg_Api& tCfg );
	//获取辅流发送比例配置信息 emMt_Cfg_VidBitRation
	virtual TVidBitRationCfg_Api GetVidBitRationCfg()=0;
	//获取终端版本厂商相关信息 emMt_Rt_TerlInfo
	virtual TTerminalInfo_Api GetTerminalInfoCfg()=0;
	//设置终端名称信息配置命令 emMt_Cfg_TerminalName
	virtual u32 SetTerminalNameCfgCmd( const TMtTerminalName_Api& tCfg );
	//获取终端名称配置信息 emMt_Cfg_TerminalName
	virtual TMtTerminalName_Api GetTerminalNameCfg()=0;

	//登陆密码
	virtual u32 SetTerminalLoginPwdCfgCmd( const TMtLoginPlatformPwdCfg_Api& tCfg );
	//获取登陆密码emMt_Cfg_LoginPwd
	virtual TMtLoginPlatformPwdCfg_Api GetTerminalLoginPwdCfg()=0;

	//设置邮箱 (value: TString) emMt_Cfg_Email
	virtual u32 SetEmailCfgCmd( const s8* pchCfg );
	//获取邮箱 (value: TString) emMt_Cfg_Email
	virtual u32 GetEmailCfg( s8* pchEmail, u8 byCnt )=0;

	//设置TCP/UDP起始端口配置信息 emMt_Cfg_Port
	virtual u32 SetUdpTcpBasePortCfg( const TTcpUdpBasePortCfg_Api &tCfg );
	//获取TCP/UDP起始端口配置信息 emMt_Cfg_Port
	virtual TTcpUdpBasePortCfg_Api GetUdpTcpBasePortCfg()=0;
	// 配置是否启用文件日志 emMt_Cfg_Log
	virtual u32 SetIsUsedFileLogon( BOOL32 bUsed );
	// 获取是否启用文件日志 emMt_Cfg_Log
	virtual BOOL32 IsUsedFileLogon()=0;

	//系统升级状态 (TBOOL32)emMt_Rt_SysUpgrade
	virtual BOOL32 GetSysUpgradeRt( ) = 0;
	//会议业务占用的端口  (value: TMTUsedPortList)emMt_Rt_ConfUsedPorts
	virtual TMTUsedPortList_Api GetConfUsedPortsRt( ) = 0;
	//mc业务占用的端口   (value: TMTUsedPortList)emMt_Rt_McUsedPorts
	virtual TMTUsedPortList_Api GetMcUsedPortsRt( ) = 0;
	//vod业务占用的端口   (value: TMTUsedPortList)emMt_Rt_VodUsedPorts
	virtual TMTUsedPortList_Api GetVodUsedPortsRt( ) = 0;
	//聊天业务占用的端口   (value: TMTUsedPortList)emMt_Rt_ImUsedPorts
	virtual TMTUsedPortList_Api GetImUsedPortsRt( ) = 0;
	//登录IM所需要的参数 (value: TImUserLogin)emMt_Rt_LoginIM
	virtual TImUserLogin_Api GetLoginIMParamCfg( ) = 0;

	//带宽检测 emMt_Rt_BandWidth
	virtual TMTNetStatus_Api GetBandWidth( ) = 0;

	//运行时映射表 (value: TMutiTServiceInfoRtData) emMt_Rt_SysCtrlSrvInfo
	virtual TMutiTServiceInfoRtData_Api GetSysCtrlSrvInfoRt()=0;
	//运行时映射表中模块个数 (value: TU32) emMt_Rt_SysCtrlSrvNum
	virtual u32 GetSysCtrlSrvNumRt()=0;
	//设置默认启动映射表 (value: TMutiTServiceDefInfo) emMt_Cfg_SysCtrlDefSrvInfo
	virtual u32 SetSysCtrlDefSrvInfoCfgCmd( const TMutiTServiceDefInfo_Api& tCfg );
	//获取启动映射表 (value: TMutiTServiceDefInfo) emMt_Cfg_SysCtrlDefSrvInfo
	virtual TMutiTServiceDefInfo_Api GetSysCtrlDefSrvInfoCfg()=0;
	//设置默认映射表中模块个数 (value: TU32) emMt_Cfg_SysCtrlDefSrvNum
	virtual u32 SetSysCtrlDefSrvNumCfgCmd( const u32 dwCfg );
	//获取默认映射表中模块个数 (value: TU32) emMt_Cfg_SysCtrlDefSrvNum
	virtual u32 GetSysCtrlDefSrvNumCfg()=0;

	//应答模式emMt_Cfg_AnswerMode
	virtual u32 SetAnswerModeCfgCmd( const u32 & dwAnswerMode );
	virtual u32 GetAnswerModeCfg( ) = 0;

	//呼叫码率emMt_Cfg_CallBitrate
	virtual u32 SetCallBitRateCfgCmd( const TMTCallBitRate_Api & tCallRate );
	virtual TMTCallBitRate_Api GetCallBitRateCfg( ) = 0;

	//自动发送内容共享 emMt_Cfg_AutoSendSharedContent	(value:TBOOL32)
	virtual u32 SetAutoSendSharedContentCfgCmd( const BOOL32 bAuto );
	virtual BOOL32 GetAutoSendSharedContentCfg( ) = 0;
	//是否允许登陆平台服务 emMt_Cfg_LoginPlatformSrv(value:TBOOL32)
	virtual u32 SetLoginPlatformSrvCfgCmd( const BOOL32 bLogin );
	virtual BOOL32 GetLoginPlatformSrvCfg( ) = 0;
	
	//平滑发送 (value:TU32)
	virtual u32 SetSmoothSendCfgCmd( const u32 &dwSmoothSendLevel );
	virtual u32 GetSmoothSendCfg( ) = 0;
	//emMt_Cfg_UseTelnet,				///<使用telnet开关 (value:TBOOL32)
	virtual u32 SetUseTelnetCfgCmd( const BOOL32 bUse );
	virtual BOOL32 GetUseTelnetCfg( ) = 0;
	//emMt_Cfg_UseHTTP,				///<使用Http开关 (value:TBOOL32)
	virtual u32 SetUseHTTPCfgCmd( const BOOL32 bUse );
	virtual BOOL32 GetUseHTTPCfg( ) = 0;
	//emMt_Cfg_UseFtp,				///<使用FTP开关 (value:TBOOL32)
	virtual u32 SetUseFtpCfgCmd( const BOOL32 bUse );
	virtual BOOL32 GetUseFtpSrvCfg( ) = 0;

	//323协议栈是否标准的( value: TBOOL32), 标准注册到1719，非标注册到1759 emMt_Rt_IsH323StackStand
	virtual BOOL32 GetIsH323StackStandRt()=0;
	//323协议栈侦听端口( value: TU16) emMt_Rt_H323CallingPort
	virtual u16 GetH323CallingPortRt()=0;
	//设置H.264 SVC  (value:TBOOL32)emMt_Cfg_H264Svc
	virtual u32 SetH264SvcCfgCmd( const BOOL32 bCfg );
	//获取H.264 SVC  (value:TBOOL32)emMt_Cfg_H264Svc
	virtual BOOL32 GetH264SvcCfg()=0;
	//设置视频载荷自适应  (value:TBOOL32)emMt_Cfg_LoadAdaptiveVideo
	virtual u32 SetLoadAdaptiveVideoCfgCmd( const BOOL32 bCfg );
	//获取视频载荷自适应  (value:TBOOL32)emMt_Cfg_LoadAdaptiveVideo
	virtual BOOL32 GetLoadAdaptiveVideoCfg()=0;
	//设置内置mc辅流参数设置 (value:TMTInnerMcAssVidCfg)emMt_Cfg_InnerMcAssVidCfg
	virtual u32 SetInnerMcAssVidCfgCmd( const TMTInnerMcAssVidCfg_Api& tCfg );
	//获取内置mc辅流参数设置 (value:TMTInnerMcAssVidCfg)emMt_Cfg_InnerMcAssVidCfg
	virtual TMTInnerMcAssVidCfg_Api GetInnerMcAssVidCfg()=0;

	//H460配置 (value:TMtH460PxyCfg)emMt_Cfg_H460
	virtual u32 SetH460CfgCmd( const TMtH460PxyCfg_Api& tCfg );
	//H460配置 (value:TMtH460PxyCfg)emMt_Cfg_H460
	virtual TMtH460PxyCfg_Api GetH460Cfg()=0;
	//H323代理配置 (value:TMtH323PxyCfg)emMt_Cfg_H323Pxy
	virtual u32 SetH323PxyCfgCmd( const TMtH323PxyCfg_Api& tCfg );
	//H323代理配置 (value:TMtH323PxyCfg)emMt_Cfg_H323Pxy
	virtual TMtH323PxyCfg_Api GetH323PxyCfg()=0;

	//会议服务器 (value: TMtMeetingSvrAddr)emMt_Rt_MeetingCtrl
	virtual TMtMeetingSvrAddr_Api GetMeetingCtrlSrvRt() = 0;

	///< 登录IM所需要的参数 (value: TImUserLogin) emMt_Cfg_LoginIMParam
	virtual u32 SetImLoginParamCfgCmd(const TImUserLogin_Api& tCfg);

	///< 登录Aps所需要的参数 (value: TMTApsLoginParam) emMt_Cfg_ApsLoginParam
	virtual u32 SetApsLoginParamCfgCmd(const TMTApsLoginParam_Api& tCfg);

	///< 获取登录Aps所需要的参数 (value: TMTApsLoginParam) emMt_Cfg_ApsLoginParam
	virtual TMTApsLoginParam_Api GetApsLoginParamCfg() = 0;

	///< 登录Sus所需要的参数 (value: TMTUpgradeClientInfo) emMt_Cfg_SusLoginParam
	virtual u32 SetSusLoginParamCfgCmd(const TMTUpgradeClientInfo_Api& tCfg);

	///< 登录Nms所需要的客户端硬件信息参数 (value: TNMSClientHWInfo) emMt_Cfg_NmsClientHWInfo
	virtual u32 SetNmsClientHWInfoCfgCmd(const TNMSClientHWInfo_Api& tCfg);


	/********************硬终端产品Key开始********************/

	//设置滚动短消息配置命令emHD_Cfg_ShortMsg
	virtual u32 SetHoriRollMsgCfgCmd( const TRollMsgCfg_Api& tCfg );
	//获取滚动短消息配置信息emHD_Cfg_ShortMsg
	virtual TRollMsgCfg_Api GetRollMsgCfg()=0;
	
	/**********用户设置**************/
	// 设置双流显示模式 emHD_Cfg_DispMode
	virtual u32 SetHDDispModeCfgCmd( const EmDualVideoShowMode_Api emMode );
	// 获取双流显示模式 emHD_Cfg_DispMode
	virtual EmDualVideoShowMode_Api GetHDDispModeCfg()=0;

	// 设置视频输出制式 emHD_Cfg_HDResOutput
	virtual u32 SetHDResOutputCfgCmd( const THDMTVideoOutPortMode_Api &tVideoMode );
	// 获取视频输出制式 emHD_Cfg_HDResOutput
	virtual THDMTVideoOutPortMode_Api GetHDResOutputCfg()=0;

	// 设置是否开启自动画中画 emHD_Cfg_AutoPIP
	virtual u32 SetHDAutoPIPCfgCmd( const BOOL32 bAuto );
	// 获取是否开启自动画中画 emHD_Cfg_AutoPIP
	virtual BOOL32 IsHDAutoPIPCfg()=0;

	// 设置呼入铃声 emHD_Cfg_CallInRing
	virtual u32 SetHDCallInRingCfgCmd( const u32 dwValue );
	// 获取呼入铃声 emHD_Cfg_CallInRing
	virtual u32 GetHDCallInRingCfg()=0;

	// 设置呼出铃声 emHD_Cfg_CallOutRing
	virtual u32 SetHDCallOutRingCfgCmd( const u32 dwValue );
	// 获取呼出铃声 emHD_Cfg_CallInRing
	virtual u32 GetHDCallOutRingCfg()=0;

	//播放呼入铃声(value: TU32) emHD_Rt_CallInRing
	virtual u32 GetCallInRingRt()=0;
	//播放呼出铃声(value: TU32) emHD_Rt_CallOutRing
	virtual u32 GetCallOutRingRt()=0;
	//设置播放按键音(value: TU32) emHD_Cfg_KeyboardRing
	virtual u32 SetKeyboardRingCfgCmd( const u32 dwCfg );
	//获取播放按键音(value: TU32) emHD_Cfg_KeyboardRing
	virtual u32 GetKeyboardRingCfg()=0;

	// 设置当前使用的横幅id号 emHD_Cfg_EnablePresetBanner
	virtual u32 SetHDPresetBannerCfgCmd( const THDMTEnablePresetBanner_Api &tValue );
	// 获取当前使用的横幅id号 emHD_Cfg_EnablePresetBanner
	virtual THDMTEnablePresetBanner_Api GetHDPresetBannerCfg()=0;

	// 设置Osd横幅配置 emHD_Cfg_OsdBannerInfo
	virtual u32 SetHDOsdBannerInfoCfgCmd( const THDMTBannerInfo_Api &tValue );
	// 获取Osd横幅配置 emHD_Cfg_OsdBannerInfo
	virtual tagTHDMTBannerInfo_Api GetHDOsdBannerInfoCfg()=0;


	// 设置Mtc横幅配置 emHD_Cfg_MtcBannerInfo
	virtual u32 SetHDMtcBannerInfoCfgCmd( const THDMTBannerInfoList_Api &tValue );
	// 获取Mtc横幅配置 emHD_Cfg_MtcBannerInfo
	virtual u32 GetHDMtcBannerInfoCfg( THDMTBannerInfoList_Api  &tValue )=0;
	
	// 设置台标配置 emHD_Cfg_LabelInfo
	virtual u32 SetHDLabelInfoCfgCmd( const THDMTLabelInfo_Api &tValue );
	// 获取台标配置 emHD_Cfg_LabelInfo
	virtual THDMTLabelInfo_Api GetHDLabelInfoCfg()=0;

	// 设置自动待机配置 emHD_Cfg_AutoSleep
	virtual u32 SetHDAutoSleepCfgCmd( const THDMTAutoSleep_Api &tValue );
	// 获取自动待机配置 emHD_Cfg_AutoSleep
	virtual THDMTAutoSleep_Api GetHDAutoSleepCfg()=0;

	// 设置时间配置 emHD_Cfg_SysTime
	virtual u32 SetHDSysTimeCfgCmd( const THDMTCfgSystemTime_Api &tValue );
	// 获取时间配置 emHD_Cfg_SysTime
	virtual THDMTCfgSystemTime_Api GetHDSysTimeCfg()=0;


	/**********管理员设置**********/
	// 设置麦克增益 emHD_Cfg_MicGain
	virtual u32 SetHDMicGainCfgCmd( const u32 &dwValue );
	// 获取麦克增益 emHD_Cfg_MicGain
	virtual u32 GetHDMicGainCfg()=0;
	
	// 设置回声抵消自适应 emHD_Cfg_AecDebug
	virtual u32 SetHDAecDebugCfgCmd( const u32 &dwValue );
	// 获取回声抵消自适应 emHD_Cfg_AecDebug
	virtual u32 GetHDAecDebugCfg()=0;
	
	// 设置音频输入接口 emHD_Cfg_AudInPortList
	virtual u32 SetHDAudInPortListCfgCmd( const TMTHDAudInPortList_Api &tPortList );
	// 获取音频输入接口 emHD_Cfg_AudInPortList
	virtual TMTHDAudInPortList_Api GetHDAudInPortListCfg()=0;
	// 设置音频输出接口 emHD_Cfg_AudOutPortList
	virtual u32 SetHDAudOutPortListCfgCmd( const THDMTHDAudOutPortList_Api &tPortList );
	// 获取音频输出接口 emHD_Cfg_AudOutPortList
	virtual THDMTHDAudOutPortList_Api GetHDAudOutPortListCfg()=0;

	// 设置第一路主视频输入端口 emHD_Cfg_Pri1stVidInPort
	virtual u32 SetHDPri1stVidInPortCfgCmd( const THDMTHDVidInPort_Api &tPort );
	// 获取第一路主视频输入端口 emHD_Cfg_Pri1stVidInPort
	virtual THDMTHDVidInPort_Api GetHDPri1stVidInPortCfg()=0;

	//设置第二路主辅视频输入端口(value: TMTHDVidInPort ) emHD_Cfg_Pri2ndVidInPort
	virtual u32 SetHDPri2ndVidInPortCfgCmd( const THDMTHDVidInPort_Api &tPort );
	//获取第二路主辅视频输入端口(value: TMTHDVidInPort ) emHD_Cfg_Pri2ndVidInPort
	virtual THDMTHDVidInPort_Api GetHDPri2ndVidInPortCfg()=0;
	//设置辅视频输入端口(value: TMTHDVidInPort ) emHD_Cfg_AssVidInPort
	virtual u32 SetHDAssVidInPortCfgCmd( const THDMTHDVidInPort_Api &tPort );
	//获取辅视频输入端口(value: TMTHDVidInPort ) emHD_Cfg_AssVidInPort
	virtual THDMTHDVidInPort_Api GetHDAssVidInPortCfg()=0;

	// 设置多视或多流 emHD_Cfg_MultiVideo
	virtual u32 SetHDMultiVideotCfgCmd( const TMTHDMultiVideo_Api &tMultiVideo );
	// 设置多视或多流 emHD_Cfg_MultiVideo
	virtual TMTHDMultiVideo_Api GetHDMultiVideoCfg()=0;

	// 设置视频矩阵 emHD_Cfg_VideoMatrixScheme
	virtual u32 SetHDVideoMatrixSchemeCfgCmd( const THDMTAllVideoMatrixScheme_Api &tValue );
	// 获取视频矩阵 emHD_Cfg_VideoMatrixScheme
	virtual THDMTAllVideoMatrixScheme_Api GetHDVideoMatrixSchemeListCfg()=0;

	// 设置无图像显示策略 emHD_Cfg_LastDisplay
	virtual u32 SetHDLastDisplayCfgCmd( const THDMTLastDisplay_Api &tValue );
	// 获取无图像显示策略 emHD_Cfg_LastDisplay
	virtual THDMTLastDisplay_Api GetHDLastDisplayListCfg()=0;

	// 设置图像降噪等级 emHD_Cfg_ImageNoiseLevel
	virtual u32 SetHDImageNoiseLevelCfgCmd( const THDMTImageNoise_Api &tValue );
	// 获取图像降噪等级 emHD_Cfg_ImageNoiseLevel
	virtual THDMTImageNoise_Api GetHDImageNoiseLevelCfg()=0;

	// 设置图像增强开关 emHD_Cfg_ImageEnhancement
	virtual u32 SetHDImageEnhancementCfgCmd( const BOOL32 bValue );
	// 获取图像增强开关 emHD_Cfg_ImageEnhancement
	virtual BOOL32 GetHDImageEnhancementCfg()=0;

	//设置第一路主视频变形拉伸(value: TMTHDImageDeformationTensile ) emHD_Cfg_Pri1stDeformationTensile
	virtual u32 SetHDPri1stDeformationTensileCfgCmd( const TMTHDImageDeformationTensile_Api &tCfg );
	//获取第一路主视频变形拉伸(value: TMTHDImageDeformationTensile ) emHD_Cfg_Pri1stDeformationTensile
	virtual TMTHDImageDeformationTensile_Api GetHDPri1stDeformationTensileCfg()=0;

	//设置第二路主视频变形拉伸(value: TMTHDImageDeformationTensile ) emHD_Cfg_Pri2ndDeformationTensile
	virtual u32 SetHDPri2ndDeformationTensileCfgCmd( const TMTHDImageDeformationTensile_Api &tCfg );
	//获取第二路主视频变形拉伸(value: TMTHDImageDeformationTensile ) emHD_Cfg_Pri2ndDeformationTensile
	virtual TMTHDImageDeformationTensile_Api GetHDPri2ndDeformationTensileCfg()=0;

	//设置辅视频变形拉伸(value: TMTHDImageDeformationTensile ) emHD_Cfg_AssDeformationTensile
	virtual u32 SetHDAssDeformationTensileCfgCmd( const TMTHDImageDeformationTensile_Api &tCfg );
	//获取辅视频变形拉伸(value: TMTHDImageDeformationTensile ) emHD_Cfg_AssDeformationTensile
	virtual TMTHDImageDeformationTensile_Api GetHDAssDeformationTensileCfg()=0;

	//设置第一路主视频等比缩放(value: TMTHDImageGeometricScaling ) emHD_Cfg_Pri1stGeometricScaling
	virtual u32 SetHDPri1stGeometricScalingCfgCmd( const TMTHDImageGeometricScaling_Api &tCfg );
	//获取第一路主视频等比缩放(value: TMTHDImageGeometricScaling ) emHD_Cfg_Pri1stGeometricScaling
	virtual TMTHDImageGeometricScaling_Api GetHDPri1stGeometricScalingCfg()=0;

	//设置第二路主视频等比缩放(value: TMTHDImageGeometricScaling ) emHD_Cfg_Pri2ndGeometricScaling
	virtual u32 SetHDPri2ndGeometricScalingCfgCmd( const TMTHDImageGeometricScaling_Api &tCfg );
	//获取第二路主视频等比缩放(value: TMTHDImageGeometricScaling ) emHD_Cfg_Pri2ndGeometricScaling
	virtual TMTHDImageGeometricScaling_Api GetHDPri2ndGeometricScalingCfg()=0;

	//设置辅视频等比缩放(value: TMTHDImageGeometricScaling )emHD_Cfg_AssGeometricScaling
	virtual u32 SetHDAssGeometricScalingCfgCmd( const TMTHDImageGeometricScaling_Api &tCfg );
	//获取辅视频等比缩放(value: TMTHDImageGeometricScaling )emHD_Cfg_AssGeometricScaling
	virtual TMTHDImageGeometricScaling_Api GetHDAssGeometricScalingCfg()=0;

	//设置第一路主视频裁边像素(value: TU32 )emHD_Cfg_EdgePixel
	virtual u32 SetHDEdgePixelCfgCmd( const u32 &dwCfg );
	//获取第一路主视频裁边像素(value: TU32 )emHD_Cfg_EdgePixel
	virtual u32 GetHDEdgePixelCfg()=0;

	//设置摄像机配置(value: TMTHDCameraList )emHD_Cfg_CameraList
	virtual u32 SetHDCameraListCfgCmd( const TMTHDCameraList_Api &tCfg );
	//获取摄像机配置(value: TMTHDCameraList )emHD_Cfg_CameraList
	virtual TMTHDCameraList_Api GetHDCameraListCfg()=0;

	//设置串口配置(value: TMTHDSerialCtrl )emHD_Cfg_SerialCtrl
	virtual u32 SetHDSerialCtrlCfgCmd( const TMTHDSerialCtrl_Api &tCfg );
	//获取串口配置(value: TMTHDSerialCtrl )emHD_Cfg_SerialCtrl
	virtual TMTHDSerialCtrl_Api GetHDSerialCtrlCfg()=0;
	//设置串口列表(value: TMTHDSerialList)emHD_Cfg_SerialList
	virtual u32 SetSerialListCfgCmd(const TMTHDSerialList_Api &tCfg);
	//获取串口列表(value: TMTHDSerialList)emHD_Cfg_SerialList
	virtual TMTHDSerialList_Api GetSerialListCfg()=0;
	//设置VGA图像调节 (value:TMTVgaImageAdjustCfg)emHD_Cfg_VGAImageAdjust
	virtual u32 SetVGAImageAdjustCfgCmd( const TMTVgaImageAdjustCfg_Api& tCfg );
	//获取VGA图像调节 (value:TMTVgaImageAdjustCfg)emHD_Cfg_VGAImageAdjust
	virtual TMTVgaImageAdjustCfg_Api GetVGAImageAdjustCfg()=0;
	//设置视频源标签 (value:TMTVideoSrcTagList)emHD_Cfg_VideoSrcTag
	virtual u32 SetVideoSrcTagCfgCmd( const TMTVideoSrcTagList_Api& tCfg );
	//设置视频输出标签 (value:TMTVideoOutTagList)emHD_Cfg_VideoOutag
	virtual u32 SetVideoOutTagCfgCmd( const TMTVideoOutTagList_Api& tCfg );
	//设置SDI一进一出或者两进(value: TU32)emHD_Cfg_SDIOneInOneOutOrTwoIn
	virtual u32 SetSDIOneInOneOutOrTwoInCfgCmd( const u32& dwtype );

	virtual u32 SetHDResizeModeCfgCmd(const TMTResizeMode_Api &tCfg);
	virtual TMTResizeMode_Api GetHDResizeModeCfg() = 0;
	
	//获取视频源标签 (value:TMTVideoSrcTagList)emHD_Cfg_VideoSrcTag
	virtual TMTVideoSrcTagList_Api  GetVideoSrcTagCfg()=0;
	//获取视频输出标签 (value:TMTVideoOutTagList)emHD_Cfg_VideoOutTag
	virtual TMTVideoOutTagList_Api  GetVideoOutTagCfg()=0;
	//获取SDI一进一出或者两进(value: TU32)emHD_Cfg_SDIOneInOneOutOrTwoIn
	virtual u32  GetSDIOneInOneOutOrTwoInCfg()=0;
	
	//设置快照FTP (value:TMTSnapShotFtpCfg)emHD_Cfg_SnapShotFtpCfg
	virtual u32 SetSnapShotFtpCfgCfgCmd( const TMTSnapShotFtpCfg_Api& tCfg );
	//获取快照FTP (value:TMTSnapShotFtpCfg)emHD_Cfg_SnapShotFtpCfg
	virtual TMTSnapShotFtpCfg_Api GetSnapShotFtpCfgCfg()=0;
	//设置VGA输出亮度(value: TU32)emHD_Cfg_VgaOutBright
	virtual u32 SetVgaOutBrightCfgCmd(const u32 &dwCfg);
	//获取VGA输出亮度(value: TU32)emHD_Cfg_VgaOutBright
	virtual u32 GetVgaOutBrightCfg() = 0;
    //设置VGA输出对比度 (value : TU32)emHD_Cfg_VgaOutContrast
	virtual u32 SetVgaOutContrastCfgCmd(const u32 &dwCfg);
	//设置VGA输出饱和度 (value : TU32)emHD_Cfg_VgaOutSaturation
	virtual u32 SetVgaOutSaturationCfgCmd(const u32 &dwCfg);

	//设置视频亮度、对比度、饱和度
	virtual u32 SetVidImgParamCmd(const EmCodecComponent_Api emCodecType,const EmCodecComponentIndex_Api emCodecIdx,const EmImgParam_Api emMsgSrc ,const u32 dwValue);


	//设置视频亮度、对比度、饱和度 (value : TU32)emHD_Cfg_VgaOutSaturation
	//virtual u32 SetVidImgParamCmd(const u32 &dwCfg);
	//获取VGA输出对比度 (value : TU32)emHD_Cfg_VgaOutContrast
	virtual u32 GetVgaOutContrastCfg() = 0;

	//获取VGA输出饱和度 (value : TU32)emHD_Cfg_VgaOutSaturation
	virtual u32 GetVgaOutSaturationCfg() = 0;


	//设置预置位名称设置   (value:TMTAllPreSetNameInfoCfg) emHD_Cfg_PresetNameInfo
	virtual u32 SetPresetNameInfoCfgCmd( const TAllMTPreSetNameInfoCfg_Api& tCfg );
	//获取预置位名称设置   (value:TMTAllPreSetNameInfoCfg) emHD_Cfg_PresetNameInfo
	virtual TAllMTPreSetNameInfoCfg_Api GetPresetNameInfoCfg()=0;
	
	//网络设置相关
	//< 路由配置信息(value: TRouteItemInfoList) emHD_Cfg_RouteCfgList
    virtual u32 SetRouteCfgListCfgCmd(const TRouteItemInfoList_Api &tCfg);
	virtual TRouteItemInfoList_Api GetRouteCfgListCfg() = 0;

	//< 以太网工作模式(value:TEthnetWorkModeList) emHD_Cfg_EthWorkModeList
	virtual u32 SetEthWorkModeListCfgCmd( const TEthnetWorkModeList_Api& tCfg );
	virtual TEthnetWorkModeList_Api GetEthWorkModeListCfg()=0;

	//< 以太网信息(value:TEthnetCfg) emHD_Cfg_EthnetCfg
	virtual u32 SetEthnetCfgCmd( const TEthnetCfg_Api& tCfg );
	virtual TEthnetCfg_Api GetEthnetCfg()=0;

	//< PPPoE拨号信息(value:TEthnetPPPoECfg) emHD_Cfg_EthPPPoECfg
	virtual u32 SetEthPPPoECfgCmd( const TEthnetPPPoECfg_Api& tCfg );
	virtual TEthnetPPPoECfg_Api GetEthPPPoECfg()=0;

	//< Wifi工作模式 (value:TWifiWorkMode) emHD_Cfg_WifiWorkMode
	virtual u32 SetWifiWorkModeCfgCmd( const TWifiWorkMode_Api& tCfg );
	virtual TWifiWorkMode_Api GetWifiWorkModeCfg()=0;

	//< Wifi-AP配置信息 (value:TWifiApConfiguration) emHD_Cfg_WifiApCfg
	virtual u32 SetWifiApCfgCmd( const TWifiApConfiguration_Api& tCfg );
	virtual TWifiApConfiguration_Api GetWifiApCfg()=0;

	//< Wifi作为client已连接后的配置信息 (value:TWifiConfiguration) emHD_Cfg_WifiClientCfg
	virtual u32 SetWifiClientCfgCmd( const TWifiConfiguration_Api& tCfg );
	virtual TWifiConfiguration_Api GetWifiClientCfg()=0;

	//< E1的配置信息 (value:TE1Cfg) emHD_Cfg_E1Cfg
	virtual u32 SetE1CfgCmd( const TE1Cfg_Api& tCfg );
	virtual TE1Cfg_Api GetE1Cfg() = 0;

	//< Wifi作为client连接后的详细信息(value:TWifiCurDetailInfo) emHD_Rt_WifiCurConnectedInfo
	virtual TWifiCurDetailInfo_Api GetWifiCurConnectedInfoRt()=0;

	//< 移动数据3G/4G工作模式 (value:TMobileDataWorkMode) emHD_Cfg_MobileDataWorkMode
	virtual u32 SetMobileDataWorkModeCfgCmd( const TMobileDataWorkMode_Api& tCfg );
	virtual TMobileDataWorkMode_Api GetMobileDataWorkModeCfg()=0;

	//< 移动数据3G/4G连接后的详细信息(value:TMobileDataCurDetailInfo) emHD_Rt_MobileDataConnectedInfo
	virtual TMobileDataCurDetailInfo_Api GetMobileDataConnectedInfoRt()=0;

	//< 当前对外通讯的网络IP详细信息(value:TNetUsedInfo) emHD_Rt_NetUsedInfo
	virtual TNetUsedInfo_Api GetNetUsedInfoRt()=0;



	// 设置主视频第一路显示比率 emHD_Cfg_MainFstDisplayRatio
	virtual u32 SetHDMainPriDisplayRatioCfgCmd( const THDMTDisplayRatio_Api &tDisplayRatio );
	// 获取主视频第一路显示比率 emHD_Cfg_MainFstDisplayRatio
	virtual THDMTDisplayRatio_Api GetHDMainPriDisplayRatioCfg()=0;

	// 设置主视频第二路显示比率 emHD_Cfg_MainSecDisplayRatio
	virtual u32 SetHDMainSecDisplayRatioCfgCmd( const THDMTDisplayRatio_Api &tDisplayRatio );
	// 获取主视频第二路显示比率 emHD_Cfg_MainSecDisplayRatio
	virtual THDMTDisplayRatio_Api GetHDMainSecDisplayRatioCfg()=0;

	// 设置辅视频显示比率 emHD_Cfg_AssDisplayRatio
	virtual u32 SetHDAssDisplayRatioCfgCmd( const THDMTDisplayRatio_Api &tDisplayRatio );
	// 获取辅视频显示比率 emHD_Cfg_AssDisplayRatio
	virtual THDMTDisplayRatio_Api GetHDAssDisplayRatioCfg()=0;

	//设置VGA输出图像调节 emHD_Cfg_VGAImageOutAdjust
	virtual u32 SetVGAImgOutAdjustCfgCmd( const TMTVgaImgOutAdjustCfg_Api tCfg );
	//获取VGA输出图像调节参数
	virtual TMTVgaImgOutAdjustCfg_Api GetVGAImgOutAdjustCfg() = 0;

	virtual u32 SetInCameraVidStdCfgCmd( const TCameraVidStd_Api tCfg );
	virtual TCameraVidStd_Api GetInCameraVidStdCfg() = 0;

    virtual u32 SetEnableHTTPSCfgCmd( IN CONST BOOL32 bEnable );
    virtual BOOL32 GetEnableHTTPSCfg() = 0;

	virtual BOOL32 GetIsImixTerCfg() = 0;
	virtual BOOL32 GetIsExportingNetCapRtCfg() = 0;

	virtual u32 SetCameraLastPosCfgCmd( const TMtCameraLastPos_Api tCfg );
	virtual TMtCameraLastPos_Api GetCameraLastPosCfg() = 0;

	virtual u32 SetShowLostPktCfgCmd( const BOOL32 bShow );
	virtual BOOL32 GetShowLostPktCfg() = 0;

	virtual u32 SetUserLoginPwdTimeoutCfgCmd( const u32 dwTime );
	virtual u32 GetUserLoginPwdTimeoutCfg() = 0;

	virtual u32    SetEnableSecureCfgCmd( IN CONST BOOL32 bEnable );
	virtual BOOL32 GetEnableSecureCfg() = 0;

	virtual u32    SetShortCutKeyCfgCmd( IN CONST TMtShortCutKeyList_Api tCfg );
	virtual TMtShortCutKeyList_Api GetShortCutKeyCfg() = 0;

	virtual u32 SetUseOspTelnetCfgCmd( const BOOL32 bUse );

	virtual u32 SetCameraEnableDigZoomCfgCmd( IN CONST BOOL32 bEnable );
	virtual BOOL32 GetCameraEnableDigZoomCfg() = 0;

	virtual u32    SetFunctionIconCfgCmd( IN CONST TMtFunctionIcon_Api tCfg );
	virtual TMtFunctionIcon_Api GetFunctionIconCfg( IN CONST EmFunctionIcon_Api emSignType ) = 0;


	/********************硬终端产品Key结束********************/

	virtual u32 SetMtWizardResultCfgCmd( CONST BOOL32 &bIsConfiged);
	virtual BOOL32 GetMtWizardResultCfg() = 0;

	virtual u32 SetFastCallListCfgCmd(IN CONST TFastCallList_Api tFastCallList);
	virtual TFastCallList_Api GetFastCallListCfg() = 0;

	virtual u32 SetShowConfNameCfgCmd(CONST BOOL32 &bShow);
	virtual BOOL32 GetShowConfNameCfg() = 0;

	virtual u32 SetTelnetFtpUserInfoCfgCmd(IN CONST TMTFtpTelnetAccountInfo_Api tInfo);
	virtual TMTFtpTelnetAccountInfo_Api GetTelnetFtpUserInfoCfg() = 0;

	virtual u32 ForceSetH323StackCfgCmd(IN CONST TForceSetH323Stack_Api tCfg);
	virtual TForceSetH323Stack_Api GetForceH323StackCfg()=0;

    virtual u32 SetServerLoginPortCfgCmd( IN CONST TServerLoginPort_Api &tPort);
    virtual TServerLoginPort_Api GetServerLoginPortCfg() = 0;
	
	virtual u32 SetTRtpSamePortCfgCmd( const BOOL32& bSamePort );
	virtual BOOL32 GetTRtpSamePortCfg() = 0;
	
	virtual u32 SetConfVcsOccupyCmd( const BOOL32 bEnable );

	//设置 是否启用IPW连接方式
	virtual u32 SetEnableIpwTypeCmd( const BOOL32 bEnable );
	//获取 是否启用IPW连接方式
	virtual BOOL32 GetEnableIpwTypeCfg() = 0;

	//设置摄像头反向正向
	virtual u32 SetCameraContrlExchangeCfgCmd( const BOOL32 bDirection );
	//获取摄像头反向正向
	virtual BOOL32 GetCameraContrlExchangeCfg() = 0;
	//设置摄像头是否倒装
	virtual u32 SetCameraHeadStandCfgCmd( const BOOL32 bHeadStand);
	//设置摄像机是否倒装
	virtual BOOL32 GetCameraHeadStandCfg() = 0;

	//设置是否显示与会方入会/离会的提示
	virtual u32 SetShowInOutConfCfgCmd( const BOOL32 bShow );
	//获取是否显示与会方入会/离会的提示
	virtual BOOL32 GetShowInOutConfCfg() = 0;

	//设置是否显示终端界面时间
	virtual u32 SetShowMtTimeCfgCmd( const BOOL32 bShow );
	//获取是否显示终端界面时间
	virtual BOOL32 GetShowMtTimeCfg() = 0;

	//设置商密 sip连接方式
	virtual u32 SetSipConnectCfgCmd( const EmSipConnectType_Api emSipConnectType );
	//获取商密 sip连接方式
	virtual EmSipConnectType_Api GetSipConnectCfg() = 0;

	virtual u32 SetEnableStrongAutCmd( IN CONST BOOL32 bEnableAut );
	virtual BOOL32 GetEnableStrongAut() = 0;
	virtual BOOL32 GetIsBusiSecMtCfg() = 0;
	virtual BOOL32 GetLicenseIsValidCfg() = 0;
	virtual u32	   SetbEnableTlsCertCmd( IN CONST BOOL32 bEnable );
	virtual u32    SetbEnableGMTlsCertCmd( IN CONST BOOL32 bEnable );
	virtual BOOL32 GetbEnableTlsCertCfg() = 0;
	virtual BOOL32 GetbEnableGMTlsCertCfg() = 0;

	//网呈使用的串口读写接口
	virtual u32 ChooseSerialUseCmd( IN CONST TMTHDSerialCtrl_Api tInfo, IN CONST BOOL32 bIsUse );
	virtual u32 OperaterSerialCmd( IN CONST TMtSerialOptParam_Api &tParam );
	//设置登录策略
	virtual u32 SetLoginStrategyCfgCmd( const TMTLoginStrategy_Api tLoginStrategy );
	virtual TMTLoginStrategy_Api GetLoginStrategyCfg() = 0;
	//设置是否显示Home按钮
	virtual u32 SetShowHomeButtonCfgCmd( const BOOL32 bShow );
	//获取是否显示Home按钮
	virtual BOOL32 GetShowHomeButtonCfg() = 0;

	virtual u32		SetShowAssVidInVmpCfgCmd( const BOOL32 bShow );
	virtual BOOL32  GetShowAssVidInVmpCfg() = 0;
	virtual u32     SetIMIXCtrlOsdFuncCfgCmd( const TMTOrder_Api tCfg );
	virtual TMTOrder_Api GetIMIXCtrlOsdFuncCfg() = 0;
	virtual u32          SetHttpsCertTypeCfgCmd( const u8 byType );
	virtual u8           GetHttpsCertTypeCfg() = 0;
	virtual u32          SetVidEncQcModeCfgCmd( const EmVideoQuality_Api emQcMode );
	virtual EmVideoQuality_Api GetVidEncQcModeCfg() = 0;
	virtual BOOL32			   GetIsSupportWirelessCfg() = 0;
	virtual u32 SetQtSettingCfgCmd(const TMtQtAddr_Api tMtQtAddr );
	virtual TMtQtAddr_Api GetQtSettingCfg() = 0;

	virtual u32 SetQtKeyUpdateModeCfgCmd(const TMtSecKeyUpdatePolicy_Api tMtSecKeyUpdatePolicy );
	virtual TMtSecKeyUpdatePolicy_Api GetQtKeyUpdateModeCfg() = 0;
	virtual s32 GetIdleAssStreamStatusRtCfg() = 0;
	virtual TMtAgentLicenseInfo_Api GetChannelLicenseRtCfg() = 0;

protected:
	virtual void BuildMsgMap();
	// Qos配置通知
	BOOL32 OnIPQoSCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// TCP/IP最大传输单元MTU配置通知
	BOOL32 OnMTUCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// NAT配置通知
	BOOL32 OnNatCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// XAPP服务器列表配置通知
	BOOL32 OnXAPPListCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// 当前使用的XAPP配置通知
	BOOL32 OnXAPPCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// CSU服务器配置通知
	BOOL32 OnCSUCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	BOOL32 OnGKCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	// SUS升级服务器配置通知
	BOOL32 OnSUSCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// SNMP网管服务器配置通知
	BOOL32 OnNMSCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// NTS测速服务器配置通知
	BOOL32 OnNTSCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// NTP时钟服务器配置通知
	BOOL32 OnNTPCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//VOD服务器配置通知
	BOOL32 OnVODCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//VRS服务器配置通知
	BOOL32 OnVRSCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//StreamPlayer流媒体配置通知
	BOOL32 OnStreamPlayerCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//Sip服务器配置通知
	BOOL32 OnSipSvrCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSipSvrManuCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//Socket5代理配置通知
	BOOL32 OnSocks5PxyCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//服务器登录状态通知
	BOOL32 OnSvrStateList_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//Xap登录成功后获取的用户权限信息通知
	BOOL32 OnUserPrevilege_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//获取登陆APS返回的用户信息请求(value: TMTUserInfoFromAps) emMt_Rt_UserInfoFromAps
	BOOL32 OnUserInfoFromApsRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//H323配置通知
	BOOL32 OnH323Cfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//SIP配置通知
	BOOL32 OnSipCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//内置MC配置通知
	BOOL32 OnMCCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	//音频输入音量配置通知
	BOOL32 OnAudVolInCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	//音频输出音量配置通知
	BOOL32 OnAudVolOutCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//自动噪声增益通知
	BOOL32 OnAudAnsCfg_Ntf(  mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//自动增益控制通知
	BOOL32 OnAudAgcCfg_Ntf(  mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//自动回声抵消
	BOOL32 OnAudAecCfg_Ntf(  mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 丢包重传参数通知
	BOOL32 OnLostPackResendCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// 音质优先配置通知
	BOOL32 OnAudioPrecedenceCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 获取音频优先通知 emMt_Cfg_AudioPrior
	BOOL32 OnAudioPriorCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 获取主视频优先通知 emMt_Cfg_PriVidPrior
	BOOL32 OnPriVidPriorCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 获取Pc辅视频优先通知 emMt_Cfg_PcAssVidPrior
	BOOL32 OnPcAssVideoPriorCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 获取Vid辅视频优先通知 emMt_Cfg_VidAssVidPrior
	BOOL32 OnVidAssVideoPriorCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 主席控制配置通知
	BOOL32 OnChairmanOperateCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 会议状态显示配置通知
	BOOL32 OnShowConfStateCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 发送静态图片配置通知
	BOOL32 OnStaticPicCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 启用电话呼叫配置通知
	BOOL32 OnTelephoneCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 发送自动呼叫配置通知
	BOOL32 OnAutoCallCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//自动登录服务器配置通知
	BOOL32 OnAutoLoginCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//非对称网络配置通知
	BOOL32 OnAsymmetricNetCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//来电防火墙配置通知
	BOOL32 OnUseCallFWCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//当前是否启用自动带宽检测配置通知
	BOOL32 OnUseBandwidthTestCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// 内置MC丢包重传参数配置通知
	BOOL32 OnMCRSParamCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// 自动双流源配置通知
	BOOL32 OnDualStreamSrcAdjustCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// 呼叫协议类型配置通知
	BOOL32 OnCallProtocolCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 会议加密类型通知
	BOOL32 OnEncryptTypeCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 断链检测时间间隔配置通知
	BOOL32 OnKeepAliveItrvlCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 断链检测时间间隔配置通知
	BOOL32 OnSipKeepAliveItrvlCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// FEC配置通知
	BOOL32 OnFecInfoCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// TL高中低档会议码率设置通知
	BOOL32 OnCallRateLevelCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// 双流码率比例配置通知
	BOOL32 OnVidBitRationCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//终端版本信息通知(RT)
	BOOL32 OnTerminalInfo_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//终端名称信息配置通知
	BOOL32 OnTerminalNameCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//终端登录密码配置通知
	BOOL32 OnLoginPwdCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//tcp|udp其实端口配置通知
	BOOL32 OnTcpUdpPortCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 设置文件日志开关配置通知
	BOOL32 OnLogStatusCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//系统升级状态 (TBOOL32)emMt_Rt_SysUpgrade
	BOOL32 OnSysUpgradeRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//会议业务占用的端口  (value: TMTUsedPortList)emMt_Rt_ConfUsedPorts
	BOOL32 OnConfUsedPortsRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//mc业务占用的端口   (value: TMTUsedPortList)emMt_Rt_McUsedPorts
	BOOL32 OnMcUsedPortsRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//vod业务占用的端口   (value: TMTUsedPortList)emMt_Rt_VodUsedPorts
	BOOL32 OnVodUsedPortsRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//聊天业务占用的端口   (value: TMTUsedPortList)emMt_Rt_ImUsedPorts
	BOOL32 OnImUsedPortsRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//登录IM所需要的参数 (value: TImUserLogin)emMt_Rt_LoginIM
	BOOL32 OnLoginIMParamCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//emHD_Cfg_AnswerMode
	BOOL32 OnAnswerMode_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnBandWidth_Ntf( mtmsg::CMtMsg * pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//运行时映射表 (value: TMutiTServiceInfoRtData) emMt_Rt_SysCtrlSrvInfo
	BOOL32 OnSysCtrlSrvInfoRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//运行时映射表中模块个数 (value: TU32) emMt_Rt_SysCtrlSrvNum
	BOOL32 OnSysCtrlSrvNumRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//获取启动映射表 (value: TMutiTServiceDefInfo) emMt_Cfg_SysCtrlDefSrvInfo
	BOOL32 OnSysCtrlDefSrvInfoCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//获取默认映射表中模块个数 (value: TU32) emMt_Cfg_SysCtrlDefSrvNum
	BOOL32 OnSysCtrlDefSrvNumCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//emHD_Cfg_CallBitrate
	BOOL32 OnCallRateCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//自动发送内容共享 emMt_Cfg_AutoSendSharedContent	
	BOOL32 OnAutoSendSharedContentCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//是否允许登陆平台服务 emMt_Cfg_LoginPlatformSrv(value:TBOOL32)
	BOOL32 OnLoginPlatformSrvCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//平滑发送 (value:TU32)
	BOOL32 OnSmoothSendCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//使用telnet开关 (value:TBOOL32)
	BOOL32 OnUseTelnetCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//使用Http开关 (value:TBOOL32)
	BOOL32 OnUseHTTPCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//使用FTP开关 (value:TBOOL32)
	BOOL32 OnUseFtpCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//是否启用SIP服务 emMt_Cfg_UseSIPSrv	(value:TBOOL32)
	BOOL32 OnUseSIPSrvCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	BOOL32 OnServerLoginTacticsCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//323协议栈是否标准的( value: TBOOL32), 标准注册到1719，非标注册到1759 emMt_Rt_IsH323StackStand
	BOOL32 OnIsH323StackStandRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//323协议栈侦听端口( value: TU16) emMt_Rt_H323CallingPort
	BOOL32 OnH323CallingPortRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//获取H.264 SVC  (value:TBOOL32)emMt_Cfg_H264Svc
	BOOL32 OnH264SvcCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//获取视频载荷自适应  (value:TBOOL32)emMt_Cfg_LoadAdaptiveVideo
	BOOL32 OnLoadAdaptiveVideoCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//获取内置mc辅流参数设置 (value:TMTInnerMcAssVidCfg)emMt_Cfg_InnerMcAssVidCfg
	BOOL32 OnInnerMcAssVidCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	/*H460配置 (value:TMtH460PxyCfg)*/
	BOOL32 OnH460Cfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//H323代理配置 (value:TMtH323PxyCfg)emMt_Cfg_H323Pxy
	BOOL32 OnH323PxyCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	//PlatForm address
	BOOL32 OnPlatformCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//microblog address
	BOOL32 OnMicroBlogCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	///< 登录Sus所需要的参数 (value: TMTUpgradeClientInfo) emMt_Cfg_SusLoginParam
	BOOL32 OnSusLoginParamCfgNtf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	/********************硬终端产品Key开始********************/
	/*******************************************************/
	//emHD_Cfg_ConfDisp

	//设置滚动短消息配置命令
	BOOL32 OnHoriRollMsgCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	
	/**********用户设置**************/
	// 设置双流显示模式通知 emHD_Cfg_DispMode
	BOOL32 OnHDDispModeCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 设置视频输出制式通知 emHD_Cfg_HDResOutput
	BOOL32 OnHDResOutputCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 设置是否开启自动画中画通知 emHD_Cfg_AutoPIP
	BOOL32 OnHDAutoPIPCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 设置呼入铃声通知 emHD_Cfg_CallInRing
	BOOL32 OnHDCallInRingCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 设置呼出铃声通知 emHD_Cfg_CallOutRing
	BOOL32 OnHDCallOutRingCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 设置当前使用的横幅id号通知 emHD_Cfg_EnablePresetBanner
	BOOL32 OnHDPresetBannerCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 设置osd横幅配置通知 emHD_Cfg_OsdBannerInfo
	BOOL32 OnHDOsdBannerInfoCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	// 设置Mtc横幅配置通知 emHD_Cfg_MtcBannerInfo
	BOOL32 OnHDMtcBannerInfoCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 设置台标配置通知 emHD_Cfg_LabelInfo
	BOOL32 OnHDLabelInfoCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 设置自动待机配置通知 emHD_Cfg_AutoSleep
	BOOL32 OnHDAutoSleepCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 设置时间配置通知 emHD_Cfg_SysTime
	BOOL32 OnHDSysTimeCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	/**********管理员设置**********/
	// 设置麦克增益通知 emHD_Cfg_MicGain
	BOOL32 OnHDMicGainCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 设置回声抵消自适应通知 emHD_Cfg_AecDebug
	BOOL32 OnHDAecDebugCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 设置音频输入接口通知 emHD_Cfg_AudInPortList
	BOOL32 OnHDAudInPortListCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 设置音频输出接口通知 emHD_Cfg_AudOutPortList
	BOOL32 OnHDAudOutPortListCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 设置主或辅视频输入端口通知 emHD_Cfg_Pri1stVidInPort
	BOOL32 OnHDPri1stVidInPortCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 设置第二路主辅视频输入端口通知 emHD_Cfg_Pri2ndVidInPort
	BOOL32 OnHDPri2ndVidInPortCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 设置辅视频输入端口通知 emHD_Cfg_AssVidInPort
	BOOL32 OnHDAssVidInPortCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 设置多视或多流通知 emHD_Cfg_MultiVideo
	BOOL32 OnHDMultiVideotCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 设置视频输出显示比例通知 emHD_Cfg_DisplayRatio
	BOOL32 OnHDDisplayRatioCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 设置视频矩阵通知 emHD_Cfg_VideoMatrixScheme
	BOOL32 OnHDVideoMatrixSchemeCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 设置无图像显示策略通知 emHD_Cfg_LastDisplay
	BOOL32 OnHDLastDisplayCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 设置图像降噪等级通知 emHD_Cfg_ImageNoiseLevel
	BOOL32 OnHDImageNoiseLevelCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 图像增强开关通知 emHD_Cfg_ImageEnhancement
	BOOL32 OnHDImageEnhancementCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	//设置第一路主视频变形拉伸(value: TMTHDImageDeformationTensile ) emHD_Cfg_Pri1stDeformationTensile
	BOOL32 OnHDPri1stDeformationTensileCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//设置第二路主视频变形拉伸(value: TMTHDImageDeformationTensile ) emHD_Cfg_Pri2ndDeformationTensile
	BOOL32 OnHDPri2ndDeformationTensileCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//设置辅视频变形拉伸(value: TMTHDImageDeformationTensile ) emHD_Cfg_AssDeformationTensile
	BOOL32 OnHDAssDeformationTensileCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//设置第一路主视频等比缩放(value: TMTHDImageGeometricScaling ) emHD_Cfg_Pri1stGeometricScaling
	BOOL32 OnHDPri1stGeometricScalingCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//设置第二路主视频等比缩放(value: TMTHDImageGeometricScaling ) emHD_Cfg_Pri2ndGeometricScaling
	BOOL32 OnHDPri2ndGeometricScalingCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//设置辅视频等比缩放(value: TMTHDImageGeometricScaling )emHD_Cfg_AssGeometricScaling
	BOOL32 OnHDAssGeometricScalingCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//设置第一路主视频裁边像素(value: TU32 )emHD_Cfg_EdgePixel
	BOOL32 OnHDEdgePixelCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//设置摄像机配置(value: TMTHDCameraList )emHD_Cfg_CameraList
	BOOL32 OnHDCameraListCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//设置串口配置(value: TMTHDSerialCtrl )emHD_Cfg_SerialCtrl
	BOOL32 OnHDSerialCtrlCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );


	//设置视频亮度、对比度、饱和度上报
	BOOL32 OnHDSetVidImgParam_Ntf(mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode);
	/*******************************************************/
	//设置数据会议 emMt_Cfg_DCS (value: TMtDCSSvrAddr) 
	BOOL32 OnDCSCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//设置主视频编码器参数  (value: TMTAllVideoEncoderParamCfg) emMt_Cfg_PriVidEncParam
	BOOL32 OnPriVidEncParamCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//设置辅视频编码器参数  (value: TMTAllVideoEncoderParamCfg)emMt_Cfg_AssVidEncParam
	BOOL32 OnAssVidEncParamCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//设置视频解码器参数  (value: TMTAllVideoDecoderParamCfg)emMt_Cfg_VideoDecParam
	BOOL32 OnVideoDecParamCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//设置会议中是否允许播放动画音效(value: TBOOL32)emMt_Cfg_PlayAniSoundInIdle
	BOOL32 OnPlayAniSoundInIdleCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//设置视频源 (value: TMTCodecVidSrcInfo) emMt_cfg_CodecVideoSrc
	BOOL32 OnCodecVideoSrcCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//内置mc的运行信息(value: TInnerMCRunInfo) emMt_Rt_MCInfo
	BOOL32 OnMCInfoRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// 获取呼叫信息 emMt_Rt_CallInfo
	BOOL32 OnGetCallInfoRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//当前的通道info， (value: TMutiChanDsInfo) emMt_Rt_ChanInfo
	BOOL32 OnGetChanInfoRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//轮询信息(value: TMtPollInfo) emMt_Rt_PollInfo
	BOOL32 OnGetPollInfoRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//是否是卫星终端， 从平台获取(value: TMTSatelliteFlag) emMt_Rt_IsSatelliteMT
	BOOL32 OnGetIsSatelliteMTRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//设置主席轮询方案   (value: TMTChrmanPollSchemeList) emMt_Cfg_ChrmanPollSchemes
	BOOL32 OnChrmanPollSchemesCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//设置显示会议时间 (value: TBOOL32)emMt_Cfg_ShowConfTime
	BOOL32 OnShowConfTimeCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//设置显示系统时间 (value: TBOOL32)emMt_Cfg_ShowSystimeTime
	BOOL32 OnShowSystimeTimeCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//设置会议中是否显示短消息 (value: TBOOL32)emMt_Cfg_ShowShortMsgInConf
	BOOL32 OnShowShortMsgInConfCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//设置是否显示申请提示 (value: TBOOL32)emMt_Cfg_ShowAppTips
	BOOL32 OnShowAppTipsCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//设置是否允许远遥 (value: TBOOL32) emMt_Cfg_FECC 
    BOOL32 OnFECCCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//设置邮箱 (value: TString) emMt_Cfg_Email
    BOOL32 OnEmailCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//播放呼入铃声(value: TU32) emHD_Rt_CallInRing
	BOOL32 OnCallInRingRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//播放呼出铃声(value: TU32) emHD_Rt_CallOutRing
	BOOL32 OnCallOutRingRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//设置播放按键音(value: TU32) emHD_Cfg_KeyboardRing
	BOOL32 OnHDKeyboardRingCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//设置VGA图像调节 (value:TMTVgaImageAdjustCfg)emHD_Cfg_VGAImageAdjust
	BOOL32 OnVGAImageAdjustCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//设置视频源标签 (value:TMTVideoSrcTagList)emHD_Cfg_VideoSrcTag
	BOOL32 OnVideoSrcTagCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//设置快照FTP (value:TMTSnapShotFtpCfg)emHD_Cfg_SnapShotFtpCfg
	BOOL32 OnSnapShotFtpCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//设置VGA输出亮度 (value : TU32)emHD_Cfg_VgaOutBright
	BOOL32 OnVgaOutBrightCfg_Ntf(mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode);
	//设置VGA输出对比度 (value : TU32)emHD_Cfg_VgaOutContrast
	BOOL32 OnVgaOutContrast_Ntf(mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode);
	BOOL32 OnVgaOutSaturation_Ntf(mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode);
	//< 预置位名称设置   (value:TMTAllPreSetNameInfoCfg) emHD_Cfg_PresetNameInfo
	BOOL32 OnPresetNameInfoCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	//网络设置相关
	//< 路由配置信息(value: TRouteItemInfoList) emHD_Cfg_RouteCfgList
    BOOL32 OnRouteCfgListCfg_Ntf(mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode);
	//< 以太网工作模式(value:TEthnetWorkModeList) emHD_Cfg_EthWorkModeList
	BOOL32 OnEthWorkModeListCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//< 以太网信息(value:TEthnetCfg) emHD_Cfg_EthnetCfg
	BOOL32 OnEthnetCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//< PPPoE拨号信息(value:TEthnetPPPoECfg) emHD_Cfg_EthPPPoECfg
	BOOL32 OnEthPPPoECfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//< Wifi工作模式 (value:TWifiWorkMode) emHD_Cfg_WifiWorkMode
	BOOL32 OnWifiWorkModeCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//< Wifi-AP配置信息 (value:TWifiApConfiguration) emHD_Cfg_WifiApCfg
	BOOL32 OnWifiApCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//< Wifi作为client已连接后的配置信息 (value:TWifiConfiguration) emHD_Cfg_WifiClientCfg
	BOOL32 OnWifiClientCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//< E1的配置信息 (value:TE1Cfg) emHD_Cfg_E1Cfg
	BOOL32 OnE1Cfg_Ntf(mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode);
	//< Wifi作为client连接后的详细信息(value:TWifiCurDetailInfo) emHD_Rt_WifiCurConnectedInfo
	BOOL32 OnWifiCurConnectedInfoRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//< 移动数据3G/4G工作模式 (value:TMobileDataWorkMode) emHD_Cfg_MobileDataWorkMode
	BOOL32 OnMobileDataWorkModeCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//< 移动数据3G/4G连接后的详细信息(value:TMobileDataCurDetailInfo) emHD_Rt_MobileDataConnectedInfo
	BOOL32 OnMobileDataConnectedInfoRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//< 当前对外通讯的网络IP详细信息(value:TNetUsedInfo) emHD_Rt_NetUsedInfo
	BOOL32 OnNetUsedInfoRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );




	// 主视频第一路显示比率 emHD_Cfg_MainFstDisplayRatio
	BOOL32 OnHDMainPriDisplayRatioCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	// 主视频第二路显示比率 emHD_Cfg_MainSecDisplayRatio
	BOOL32 OnHDMainSecDisplayRatioCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	// 辅视频显示比率 emHD_Cfg_AssDisplayRatio
	BOOL32 OnHDAssDisplayRatioCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	BOOL32 OnHDResizeModeCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	/********************硬终端产品Key结束********************/

	BOOL32 OnSetMtWizardResultCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetApsLoginParamCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetFastCallListCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetShowConfNameCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetTelnetFtpUserInfoCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	BOOL32 OnForceSet323StackCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetServerLoginPortCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnTRtpSamePort_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	BOOL32 OnSetConfOccupy_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetEnableIpwTypeNtf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetCameraContrlExchangeCfgNtf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetCameraHeadStandCfgNtf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetShowInOutConfCfgNtf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
    BOOL32 OnSetEnableHTTPSCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetSipConnectCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetTEnableStrongAutCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnChooseSerialUse_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnOperaterSerial_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetUseTlsCertCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetUseGMTlsCertCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetShowMtTimeCfgNtf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetLoginStrategyCfgNtf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetShowHomeButtonCfgNtf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetShowAssVidInVmpCfgNtf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetIMIXCtrlOsdFuncCfgNtf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetHttpsCertTypeCfgNtf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetVidEncQcModeCfgNtf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetQtKeyUpdateModeCfgNtf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetQtSettingCfgNtf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	BOOL32 OnSetVGAImgOutAdjustCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetCameraVidStdCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetCameraLastPosCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetShowLostPktCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetUserLoginPwdTimeoutCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetEnableSecureCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetShortCutKeyCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetUseOspTelnetCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetCameraEnableDigZoomCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetFunctionIconCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

};

#endif // _I_MTDATASHARE_H_