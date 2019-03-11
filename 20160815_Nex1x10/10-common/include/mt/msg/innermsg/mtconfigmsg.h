#ifndef _MT_CONFIG_MSG_H_
#define _MT_CONFIG_MSG_H_
///////////////////////////////////////////////////////////////
//默认 配置消息 定义
///////////////////////////////////////////////////////////////
//脚本 gen_cfg_files 根据 mtdskey.h 自动生成,请勿手动修改
///////////////////////////////////////////////////////////////
//自定义 配置消息 定义，请在mtconfigexmsg.h添加，并增加Set/Get消息处理函数
///////////////////////////////////////////////////////////////

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMtConfigMsg
{
    EV_BGN(CONFIG) = EVSEG_CONFIG_BGN,
#endif


    /*
    * key : emMt_Cfg_IPQoS
    */
    MESSAGE(Ev_MT_SetIPQoSCfg_Cmd)
    BODY(mt::TMTIPQoS, )

    MESSAGE(Ev_MT_SetIPQoSCfg_Ntf)
    BODY(mt::TMTIPQoS, )


    /*
    * key : emMt_Cfg_MTU
    */
    MESSAGE(Ev_MT_SetMTUCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_SetMTUCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_NAT
    */
    MESSAGE(Ev_MT_SetNATCfg_Cmd)
    BODY(mt::TMTNat, )

    MESSAGE(Ev_MT_SetNATCfg_Ntf)
    BODY(mt::TMTNat, )


    /*
    * key : emMt_Cfg_APSList
    */
    MESSAGE(Ev_MT_SetAPSListCfg_Cmd)
    BODY(mt::TMtAPSSvrList, )

    MESSAGE(Ev_MT_SetAPSListCfg_Ntf)
    BODY(mt::TMtAPSSvrList, )


    /*
    * key : emMt_Cfg_LastSuccessApsAddr
    */
    MESSAGE(Ev_MT_SetLastSuccessApsAddrCfg_Cmd)
    BODY(mt::TMtAPSAddrCfgs, )

    MESSAGE(Ev_MT_SetLastSuccessApsAddrCfg_Ntf)
    BODY(mt::TMtAPSAddrCfgs, )


    /*
    * key : emMt_Cfg_BackUpAPSList
    */
    MESSAGE(Ev_MT_SetBackUpAPSListCfg_Cmd)
    BODY(mt::TMtAPSAddrCfgs, )

    MESSAGE(Ev_MT_SetBackUpAPSListCfg_Ntf)
    BODY(mt::TMtAPSAddrCfgs, )


    /*
    * key : emMt_Cfg_GK
    */
    MESSAGE(Ev_MT_SetGKCfg_Cmd)
    BODY(mt::TMtCSUAddr, )

    MESSAGE(Ev_MT_SetGKCfg_Ntf)
    BODY(mt::TMtCSUAddr, )


    /*
    * key : emMt_Cfg_SipSvrManu
    */
    MESSAGE(Ev_MT_SetSipSvrManuCfg_Cmd)
    BODY(mt::TMtSipSvrAddr, )

    MESSAGE(Ev_MT_SetSipSvrManuCfg_Ntf)
    BODY(mt::TMtSipSvrAddr, )


    /*
    * key : emMt_Cfg_SipSvr
    */
    MESSAGE(Ev_MT_SetSipSvrCfg_Cmd)
    BODY(mt::TMtSipSvrAddr, )

    MESSAGE(Ev_MT_SetSipSvrCfg_Ntf)
    BODY(mt::TMtSipSvrAddr, )


    /*
    * key : emMt_Cfg_CSU
    */
    MESSAGE(Ev_MT_SetCSUCfg_Cmd)
    BODY(mt::TMtCSUAddr, )

    MESSAGE(Ev_MT_SetCSUCfg_Ntf)
    BODY(mt::TMtCSUAddr, )


    /*
    * key : emMt_Cfg_SUS
    */
    MESSAGE(Ev_MT_SetSUSCfg_Cmd)
    BODY(mt::TMtSUSAddr, )

    MESSAGE(Ev_MT_SetSUSCfg_Ntf)
    BODY(mt::TMtSUSAddr, )


    /*
    * key : emMt_Cfg_SusManu
    */
    MESSAGE(Ev_MT_SetSusManuCfg_Cmd)
    BODY(mt::TMtSUSAddr, )

    MESSAGE(Ev_MT_SetSusManuCfg_Ntf)
    BODY(mt::TMtSUSAddr, )


    /*
    * key : emMt_Cfg_NMS
    */
    MESSAGE(Ev_MT_SetNMSCfg_Cmd)
    BODY(mt::TMtNMSAddr, )

    MESSAGE(Ev_MT_SetNMSCfg_Ntf)
    BODY(mt::TMtNMSAddr, )


    /*
    * key : emMt_Cfg_NmsManu
    */
    MESSAGE(Ev_MT_SetNmsManuCfg_Cmd)
    BODY(mt::TMtNMSAddr, )

    MESSAGE(Ev_MT_SetNmsManuCfg_Ntf)
    BODY(mt::TMtNMSAddr, )


    /*
    * key : emMt_Cfg_NTS
    */
    MESSAGE(Ev_MT_SetNTSCfg_Cmd)
    BODY(mt::TMtNTSAddr, )

    MESSAGE(Ev_MT_SetNTSCfg_Ntf)
    BODY(mt::TMtNTSAddr, )


    /*
    * key : emMt_Cfg_NtsManu
    */
    MESSAGE(Ev_MT_SetNtsManuCfg_Cmd)
    BODY(mt::TMtNTSAddr, )

    MESSAGE(Ev_MT_SetNtsManuCfg_Ntf)
    BODY(mt::TMtNTSAddr, )


    /*
    * key : emMt_Cfg_NTP
    */
    MESSAGE(Ev_MT_SetNTPCfg_Cmd)
    BODY(mt::TMtNTPAddr, )

    MESSAGE(Ev_MT_SetNTPCfg_Ntf)
    BODY(mt::TMtNTPAddr, )


    /*
    * key : emMt_Cfg_NtpManu
    */
    MESSAGE(Ev_MT_SetNtpManuCfg_Cmd)
    BODY(mt::TMtNTPAddr, )

    MESSAGE(Ev_MT_SetNtpManuCfg_Ntf)
    BODY(mt::TMtNTPAddr, )


    /*
    * key : emMt_Cfg_VOD
    */
    MESSAGE(Ev_MT_SetVODCfg_Cmd)
    BODY(mt::TMtVODSvrCfg, )

    MESSAGE(Ev_MT_SetVODCfg_Ntf)
    BODY(mt::TMtVODSvrCfg, )


    /*
    * key : emMt_Cfg_VRS
    */
    MESSAGE(Ev_MT_SetVRSCfg_Cmd)
    BODY(mt::TMtVRSSvrCfg, )

    MESSAGE(Ev_MT_SetVRSCfg_Ntf)
    BODY(mt::TMtVRSSvrCfg, )


    /*
    * key : emMt_Cfg_DCS
    */
    MESSAGE(Ev_MT_SetDCSCfg_Cmd)
    BODY(mt::TMtDCSSvrAddr, )

    MESSAGE(Ev_MT_SetDCSCfg_Ntf)
    BODY(mt::TMtDCSSvrAddr, )


    /*
    * key : emMt_Cfg_StreamMedia
    */
    MESSAGE(Ev_MT_SetStreamMediaCfg_Cmd)
    BODY(mt::TMTStreamMedia, )

    MESSAGE(Ev_MT_SetStreamMediaCfg_Ntf)
    BODY(mt::TMTStreamMedia, )


    /*
    * key : emMt_Cfg_Socks5Pxy
    */
    MESSAGE(Ev_MT_SetSocks5PxyCfg_Cmd)
    BODY(mt::TSocks5Cfg, )

    MESSAGE(Ev_MT_SetSocks5PxyCfg_Ntf)
    BODY(mt::TSocks5Cfg, )


    /*
    * key : emMt_Cfg_SvrLoginTactics
    */
    MESSAGE(Ev_MT_SetSvrLoginTacticsCfg_Cmd)
    BODY(mt::TMtLoginTacticsTable, )

    MESSAGE(Ev_MT_SetSvrLoginTacticsCfg_Ntf)
    BODY(mt::TMtLoginTacticsTable, )


    /*
    * key : emMt_Cfg_H323
    */
    MESSAGE(Ev_MT_SetH323Cfg_Cmd)
    BODY(mt::TMtH323Cfg, )

    MESSAGE(Ev_MT_SetH323Cfg_Ntf)
    BODY(mt::TMtH323Cfg, )


    /*
    * key : emMt_Cfg_Sip
    */
    MESSAGE(Ev_MT_SetSipCfg_Cmd)
    BODY(mt::TMtSipCfg, )

    MESSAGE(Ev_MT_SetSipCfg_Ntf)
    BODY(mt::TMtSipCfg, )


    /*
    * key : emMt_Cfg_MC
    */
    MESSAGE(Ev_MT_SetMCCfg_Cmd)
    BODY(mt::TInnerMCParam, )

    MESSAGE(Ev_MT_SetMCCfg_Ntf)
    BODY(mt::TInnerMCParam, )


    /*
    * key : emMt_Cfg_AudVolIn
    */
    MESSAGE(Ev_MT_SetAudVolInCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_SetAudVolInCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_AudVolOut
    */
    MESSAGE(Ev_MT_SetAudVolOutCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_SetAudVolOutCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_Ans
    */
    MESSAGE(Ev_MT_SetAnsCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetAnsCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_Agc
    */
    MESSAGE(Ev_MT_SetAgcCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetAgcCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_Aec
    */
    MESSAGE(Ev_MT_SetAecCfg_Cmd)
    BODY(mt::TAdjustAecParamCfg, )

    MESSAGE(Ev_MT_SetAecCfg_Ntf)
    BODY(mt::TAdjustAecParamCfg, )


    /*
    * key : emMt_Cfg_LostPktResend
    */
    MESSAGE(Ev_MT_SetLostPktResendCfg_Cmd)
    BODY(mt::TPrsParam, )

    MESSAGE(Ev_MT_SetLostPktResendCfg_Ntf)
    BODY(mt::TPrsParam, )


    /*
    * key : emMt_Cfg_PriVidEncParam
    */
    MESSAGE(Ev_MT_SetPriVidEncParamCfg_Cmd)
    BODY(mt::TMTAllVideoEncoderParamCfg, )

    MESSAGE(Ev_MT_SetPriVidEncParamCfg_Ntf)
    BODY(mt::TMTAllVideoEncoderParamCfg, )


    /*
    * key : emMt_Cfg_AssVidEncParam
    */
    MESSAGE(Ev_MT_SetAssVidEncParamCfg_Cmd)
    BODY(mt::TMTAllVideoEncoderParamCfg, )

    MESSAGE(Ev_MT_SetAssVidEncParamCfg_Ntf)
    BODY(mt::TMTAllVideoEncoderParamCfg, )


    /*
    * key : emMt_Cfg_VideoDecParam
    */
    MESSAGE(Ev_MT_SetVideoDecParamCfg_Cmd)
    BODY(mt::TMTAllVideoDecoderParamCfg, )

    MESSAGE(Ev_MT_SetVideoDecParamCfg_Ntf)
    BODY(mt::TMTAllVideoDecoderParamCfg, )


    /*
    * key : emMt_Cfg_AudioPrior
    */
    MESSAGE(Ev_MT_SetAudioPriorCfg_Cmd)
    BODY(mt::TMTAudioPriorCfg, )

    MESSAGE(Ev_MT_SetAudioPriorCfg_Ntf)
    BODY(mt::TMTAudioPriorCfg, )


    /*
    * key : emMt_Cfg_PriVidPrior
    */
    MESSAGE(Ev_MT_SetPriVidPriorCfg_Cmd)
    BODY(mt::TMTMainVideoPriorCfg, )

    MESSAGE(Ev_MT_SetPriVidPriorCfg_Ntf)
    BODY(mt::TMTMainVideoPriorCfg, )


    /*
    * key : emMt_Cfg_PcAssVidPrior
    */
    MESSAGE(Ev_MT_SetPcAssVidPriorCfg_Cmd)
    BODY(mt::TVidPriorParam, )

    MESSAGE(Ev_MT_SetPcAssVidPriorCfg_Ntf)
    BODY(mt::TVidPriorParam, )


    /*
    * key : emMt_Cfg_VidAssVidPrior
    */
    MESSAGE(Ev_MT_SetVidAssVidPriorCfg_Cmd)
    BODY(mt::TVidPriorParam, )

    MESSAGE(Ev_MT_SetVidAssVidPriorCfg_Ntf)
    BODY(mt::TVidPriorParam, )


    /*
    * key : emMt_Cfg_PlayAniSoundInIdle
    */
    MESSAGE(Ev_MT_SetPlayAniSoundInIdleCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetPlayAniSoundInIdleCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_cfg_CodecVideoSrc
    */
    MESSAGE(Ev_MT_SetCodecVideoSrcCfg_Cmd)
    BODY(mt::TMTCodecVidSrcInfo, )

    MESSAGE(Ev_MT_SetCodecVideoSrcCfg_Ntf)
    BODY(mt::TMTCodecVidSrcInfo, )


    /*
    * key : emMt_Cfg_ChrmanPollSchemes
    */
    MESSAGE(Ev_MT_SetChrmanPollSchemesCfg_Cmd)
    BODY(mt::TMTChrmanPollSchemeList, )

    MESSAGE(Ev_MT_SetChrmanPollSchemesCfg_Ntf)
    BODY(mt::TMTChrmanPollSchemeList, )


    /*
    * key : emMt_Cfg_ChrmanOperate
    */
    MESSAGE(Ev_MT_SetChrmanOperateCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetChrmanOperateCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_ShowConfState
    */
    MESSAGE(Ev_MT_SetShowConfStateCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetShowConfStateCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_ShowConfTime
    */
    MESSAGE(Ev_MT_SetShowConfTimeCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetShowConfTimeCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_ShowConfName
    */
    MESSAGE(Ev_MT_SetShowConfNameCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetShowConfNameCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_ShowSystimeTime
    */
    MESSAGE(Ev_MT_SetShowSystimeTimeCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetShowSystimeTimeCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_ShowShortMsgInConf
    */
    MESSAGE(Ev_MT_SetShowShortMsgInConfCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetShowShortMsgInConfCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_ShowAppTips
    */
    MESSAGE(Ev_MT_SetShowAppTipsCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetShowAppTipsCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_StaticPic
    */
    MESSAGE(Ev_MT_SetStaticPicCfg_Cmd)
    BODY(mt::TStaticPicCfg, )

    MESSAGE(Ev_MT_SetStaticPicCfg_Ntf)
    BODY(mt::TStaticPicCfg, )


    /*
    * key : emMt_Cfg_Telephone
    */
    MESSAGE(Ev_MT_SetTelephoneCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetTelephoneCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_AutoCall
    */
    MESSAGE(Ev_MT_SetAutoCallCfg_Cmd)
    BODY(mt::TMTAutoCall, )

    MESSAGE(Ev_MT_SetAutoCallCfg_Ntf)
    BODY(mt::TMTAutoCall, )


    /*
    * key : emMt_Cfg_FECC
    */
    MESSAGE(Ev_MT_SetFECCCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetFECCCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_AutoLogin
    */
    MESSAGE(Ev_MT_SetAutoLoginCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetAutoLoginCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_AsymmetricNet
    */
    MESSAGE(Ev_MT_SetAsymmetricNetCfg_Cmd)
    BODY(mt::TMtAsymmetricNetInfo, )

    MESSAGE(Ev_MT_SetAsymmetricNetCfg_Ntf)
    BODY(mt::TMtAsymmetricNetInfo, )


    /*
    * key : emMt_Cfg_UseCallFW
    */
    MESSAGE(Ev_MT_SetUseCallFWCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetUseCallFWCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_BandWidthTest
    */
    MESSAGE(Ev_MT_SetBandWidthTestCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetBandWidthTestCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_MCResendParam
    */
    MESSAGE(Ev_MT_SetMCResendParamCfg_Cmd)
    BODY(mt::TMTMcRSParam, )

    MESSAGE(Ev_MT_SetMCResendParamCfg_Ntf)
    BODY(mt::TMTMcRSParam, )


    /*
    * key : emMt_Cfg_DualStramSrcAdj
    */
    MESSAGE(Ev_MT_SetDualStramSrcAdjCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetDualStramSrcAdjCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_CallProtocol
    */
    MESSAGE(Ev_MT_SetCallProtocolCfg_Cmd)
    BODY(mt::TMTCallerProtocol, )

    MESSAGE(Ev_MT_SetCallProtocolCfg_Ntf)
    BODY(mt::TMTCallerProtocol, )


    /*
    * key : emMt_Cfg_EncryptType
    */
    MESSAGE(Ev_MT_SetEncryptTypeCfg_Cmd)
    BODY(mt::TMTEncryptType, )

    MESSAGE(Ev_MT_SetEncryptTypeCfg_Ntf)
    BODY(mt::TMTEncryptType, )


    /*
    * key : emMt_Cfg_KeepAliveItrvl
    */
    MESSAGE(Ev_MT_SetKeepAliveItrvlCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_SetKeepAliveItrvlCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_FEC
    */
    MESSAGE(Ev_MT_SetFECCfg_Cmd)
    BODY(mt::TMTFecInfo, )

    MESSAGE(Ev_MT_SetFECCfg_Ntf)
    BODY(mt::TMTFecInfo, )


    /*
    * key : emMt_Cfg_CallRateLv
    */
    MESSAGE(Ev_MT_SetCallRateLvCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_SetCallRateLvCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_VidBitRation
    */
    MESSAGE(Ev_MT_SetVidBitRationCfg_Cmd)
    BODY(mt::TVidBitRationCfg, )

    MESSAGE(Ev_MT_SetVidBitRationCfg_Ntf)
    BODY(mt::TVidBitRationCfg, )


    /*
    * key : emMt_Cfg_TerminalName
    */
    MESSAGE(Ev_MT_SetTerminalNameCfg_Cmd)
    BODY(mt::TMtTerminalName, )

    MESSAGE(Ev_MT_SetTerminalNameCfg_Ntf)
    BODY(mt::TMtTerminalName, )


    /*
    * key : emMt_Cfg_LoginPwd
    */
    MESSAGE(Ev_MT_SetLoginPwdCfg_Cmd)
    BODY(mt::TMtLoginPlatformPwdCfg, )

    MESSAGE(Ev_MT_SetLoginPwdCfg_Ntf)
    BODY(mt::TMtLoginPlatformPwdCfg, )


    /*
    * key : emMt_Cfg_Email
    */
    MESSAGE(Ev_MT_SetEmailCfg_Cmd)
    BODY(mt::TString, )

    MESSAGE(Ev_MT_SetEmailCfg_Ntf)
    BODY(mt::TString, )


    /*
    * key : emMt_Cfg_Port
    */
    MESSAGE(Ev_MT_SetPortCfg_Cmd)
    BODY(mt::TMTPortCfg, )

    MESSAGE(Ev_MT_SetPortCfg_Ntf)
    BODY(mt::TMTPortCfg, )


    /*
    * key : emMt_Cfg_Log
    */
    MESSAGE(Ev_MT_SetLogCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetLogCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_LoginIMParam
    */
    MESSAGE(Ev_MT_SetLoginIMParamCfg_Cmd)
    BODY(mt::TImUserLogin, )

    MESSAGE(Ev_MT_SetLoginIMParamCfg_Ntf)
    BODY(mt::TImUserLogin, )


    /*
    * key : emMt_Cfg_SysCtrlDefSrvInfo
    */
    MESSAGE(Ev_MT_SetSysCtrlDefSrvInfoCfg_Cmd)
    BODY(mt::TMutiTServiceDefInfo, )

    MESSAGE(Ev_MT_SetSysCtrlDefSrvInfoCfg_Ntf)
    BODY(mt::TMutiTServiceDefInfo, )


    /*
    * key : emMt_Cfg_SysCtrlDefSrvNum
    */
    MESSAGE(Ev_MT_SetSysCtrlDefSrvNumCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_SetSysCtrlDefSrvNumCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_AnswerMode
    */
    MESSAGE(Ev_MT_SetAnswerModeCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_SetAnswerModeCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_CallBitrate
    */
    MESSAGE(Ev_MT_SetCallBitrateCfg_Cmd)
    BODY(mt::TMultiU32, )

    MESSAGE(Ev_MT_SetCallBitrateCfg_Ntf)
    BODY(mt::TMultiU32, )


    /*
    * key : emMt_Cfg_AutoSendSharedContent
    */
    MESSAGE(Ev_MT_SetAutoSendSharedContentCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetAutoSendSharedContentCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_LoginPlatformSrv
    */
    MESSAGE(Ev_MT_SetLoginPlatformSrvCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetLoginPlatformSrvCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_H460
    */
    MESSAGE(Ev_MT_SetH460Cfg_Cmd)
    BODY(mt::TMtH460PxyCfg, )

    MESSAGE(Ev_MT_SetH460Cfg_Ntf)
    BODY(mt::TMtH460PxyCfg, )


    /*
    * key : emMt_Cfg_H323Pxy
    */
    MESSAGE(Ev_MT_SetH323PxyCfg_Cmd)
    BODY(mt::TMtH323PxyCfg, )

    MESSAGE(Ev_MT_SetH323PxyCfg_Ntf)
    BODY(mt::TMtH323PxyCfg, )


    /*
    * key : emMt_Cfg_SmoothSend
    */
    MESSAGE(Ev_MT_SetSmoothSendCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetSmoothSendCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_UseTelnet
    */
    MESSAGE(Ev_MT_SetUseTelnetCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetUseTelnetCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_UseHTTP
    */
    MESSAGE(Ev_MT_SetUseHTTPCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetUseHTTPCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_UseFtp
    */
    MESSAGE(Ev_MT_SetUseFtpCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetUseFtpCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_TelnetFtpUserInfo
    */
    MESSAGE(Ev_MT_SetTelnetFtpUserInfoCfg_Cmd)
    BODY(mt::TMTFtpTelnetAccountInfo, )

    MESSAGE(Ev_MT_SetTelnetFtpUserInfoCfg_Ntf)
    BODY(mt::TMTFtpTelnetAccountInfo, )


    /*
    * key : emMt_Cfg_H264Svc
    */
    MESSAGE(Ev_MT_SetH264SvcCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetH264SvcCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_InnerMcAssVidCfg
    */
    MESSAGE(Ev_MT_SetInnerMcAssVidCfgCfg_Cmd)
    BODY(mt::TMTInnerMcAssVidCfg, )

    MESSAGE(Ev_MT_SetInnerMcAssVidCfgCfg_Ntf)
    BODY(mt::TMTInnerMcAssVidCfg, )


    /*
    * key : emMt_Cfg_ApsLoginParam
    */
    MESSAGE(Ev_MT_SetApsLoginParamCfg_Cmd)
    BODY(mt::TMtApsLoginParam, )

    MESSAGE(Ev_MT_SetApsLoginParamCfg_Ntf)
    BODY(mt::TMtApsLoginParam, )


    /*
    * key : emMt_Cfg_SusLoginParam
    */
    MESSAGE(Ev_MT_SetSusLoginParamCfg_Cmd)
    BODY(mt::TMTUpgradeClientInfo, )

    MESSAGE(Ev_MT_SetSusLoginParamCfg_Ntf)
    BODY(mt::TMTUpgradeClientInfo, )


    /*
    * key : emMt_Cfg_NmsClientHWInfo
    */
    MESSAGE(Ev_MT_SetNmsClientHWInfoCfg_Cmd)
    BODY(mt::TNMSClientHWInfo, )

    MESSAGE(Ev_MT_SetNmsClientHWInfoCfg_Ntf)
    BODY(mt::TNMSClientHWInfo, )


    /*
    * key : emMt_Cfg_NewExceptionTime
    */
    MESSAGE(Ev_MT_SetNewExceptionTimeCfg_Cmd)
    BODY(mt::TString, )

    MESSAGE(Ev_MT_SetNewExceptionTimeCfg_Ntf)
    BODY(mt::TString, )


    /*
    * key : emMt_Cfg_HasWizardConfiged
    */
    MESSAGE(Ev_MT_SetHasWizardConfigedCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetHasWizardConfigedCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_CurVidCapDev
    */
    MESSAGE(Ev_MT_SetCurVidCapDevCfg_Cmd)
    BODY(mt::TDevInfo, )

    MESSAGE(Ev_MT_SetCurVidCapDevCfg_Ntf)
    BODY(mt::TDevInfo, )


    /*
    * key : emMt_Cfg_ServerLoginPort
    */
    MESSAGE(Ev_MT_SetServerLoginPortCfg_Cmd)
    BODY(mt::TServerLoginPort, )

    MESSAGE(Ev_MT_SetServerLoginPortCfg_Ntf)
    BODY(mt::TServerLoginPort, )


    /*
    * key : emMt_Cfg_ConfOccupy
    */
    MESSAGE(Ev_MT_SetConfOccupyCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetConfOccupyCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_EnableHTTPS
    */
    MESSAGE(Ev_MT_SetEnableHTTPSCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetEnableHTTPSCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_MtModel
    */
    MESSAGE(Ev_MT_SetMtModelCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_SetMtModelCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_ShowInOutConf
    */
    MESSAGE(Ev_MT_SetShowInOutConfCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetShowInOutConfCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_ShowMtTime
    */
    MESSAGE(Ev_MT_SetShowMtTimeCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetShowMtTimeCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_LoginStrategy
    */
    MESSAGE(Ev_MT_SetLoginStrategyCfg_Cmd)
    BODY(mt::TLoginStrategy, )

    MESSAGE(Ev_MT_SetLoginStrategyCfg_Ntf)
    BODY(mt::TLoginStrategy, )


    /*
    * key : emMt_Cfg_ShowHomeButton
    */
    MESSAGE(Ev_MT_SetShowHomeButtonCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetShowHomeButtonCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_ShowAssVidInVmp
    */
    MESSAGE(Ev_MT_SetShowAssVidInVmpCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetShowAssVidInVmpCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_IMIXCtrlOsdFunc
    */
    MESSAGE(Ev_MT_SetIMIXCtrlOsdFuncCfg_Cmd)
    BODY(mt::TMTOrder, )

    MESSAGE(Ev_MT_SetIMIXCtrlOsdFuncCfg_Ntf)
    BODY(mt::TMTOrder, )


    /*
    * key : emMt_Cfg_HttpsCertificateType
    */
    MESSAGE(Ev_MT_SetHttpsCertificateTypeCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_SetHttpsCertificateTypeCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_VidEncQcMode
    */
    MESSAGE(Ev_MT_SetVidEncQcModeCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_SetVidEncQcModeCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_ShowLostPkt
    */
    MESSAGE(Ev_MT_SetShowLostPktCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetShowLostPktCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_AiInfo
    */
    MESSAGE(Ev_MT_SetAiInfoCfg_Cmd)
    BODY(mt::TMtAiInfoCfg, )

    MESSAGE(Ev_MT_SetAiInfoCfg_Ntf)
    BODY(mt::TMtAiInfoCfg, )


    /*
    * key : emMt_Cfg_UserLoginPwdTimeout
    */
    MESSAGE(Ev_MT_SetUserLoginPwdTimeoutCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_SetUserLoginPwdTimeoutCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_EnableSecure
    */
    MESSAGE(Ev_MT_SetEnableSecureCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetEnableSecureCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_ShortCutKey
    */
    MESSAGE(Ev_MT_SetShortCutKeyCfg_Cmd)
    BODY(mt::TMtShortCutKeyList, )

    MESSAGE(Ev_MT_SetShortCutKeyCfg_Ntf)
    BODY(mt::TMtShortCutKeyList, )


    /*
    * key : emMt_Cfg_AiCameraInfo
    */
    MESSAGE(Ev_MT_SetAiCameraInfoCfg_Cmd)
    BODY(mt::TMTHDCameraAiList, )

    MESSAGE(Ev_MT_SetAiCameraInfoCfg_Ntf)
    BODY(mt::TMTHDCameraAiList, )


    /*
    * key : emMt_Cfg_TRtpSamePort
    */
    MESSAGE(Ev_MT_SetTRtpSamePortCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetTRtpSamePortCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_FunctionIcon
    */
    MESSAGE(Ev_MT_SetFunctionIconCfg_Cmd)
    BODY(mt::TMtFunctionIconList, )

    MESSAGE(Ev_MT_SetFunctionIconCfg_Ntf)
    BODY(mt::TMtFunctionIconList, )


    /*
    * key : emHD_Cfg_ShortMsg
    */
    MESSAGE(Ev_HD_SetShortMsgCfg_Cmd)
    BODY(mt::TMTShortMsgCfg, )

    MESSAGE(Ev_HD_SetShortMsgCfg_Ntf)
    BODY(mt::TMTShortMsgCfg, )


    /*
    * key : emHD_Cfg_DispMode
    */
    MESSAGE(Ev_HD_SetDispModeCfg_Cmd)
    BODY(mt::TMTVideoShowMode, )

    MESSAGE(Ev_HD_SetDispModeCfg_Ntf)
    BODY(mt::TMTVideoShowMode, )


    /*
    * key : emHD_Cfg_HDResOutput
    */
    MESSAGE(Ev_HD_SetHDResOutputCfg_Cmd)
    BODY(mt::TMTVideoOutPortMode, )

    MESSAGE(Ev_HD_SetHDResOutputCfg_Ntf)
    BODY(mt::TMTVideoOutPortMode, )


    /*
    * key : emHD_Cfg_AutoPIP
    */
    MESSAGE(Ev_HD_SetAutoPIPCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_HD_SetAutoPIPCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Cfg_CallInRing
    */
    MESSAGE(Ev_HD_SetCallInRingCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_HD_SetCallInRingCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emHD_Cfg_CallOutRing
    */
    MESSAGE(Ev_HD_SetCallOutRingCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_HD_SetCallOutRingCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emHD_Cfg_KeyboardRing
    */
    MESSAGE(Ev_HD_SetKeyboardRingCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_HD_SetKeyboardRingCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emHD_Cfg_EnablePresetBanner
    */
    MESSAGE(Ev_HD_SetEnablePresetBannerCfg_Cmd)
    BODY(mt::TMTEnablePresetBanner, )

    MESSAGE(Ev_HD_SetEnablePresetBannerCfg_Ntf)
    BODY(mt::TMTEnablePresetBanner, )


    /*
    * key : emHD_Cfg_MtcBannerInfo
    */
    MESSAGE(Ev_HD_SetMtcBannerInfoCfg_Cmd)
    BODY(mt::TMTBannerInfoList, )

    MESSAGE(Ev_HD_SetMtcBannerInfoCfg_Ntf)
    BODY(mt::TMTBannerInfoList, )


    /*
    * key : emHD_Cfg_OsdBannerInfo
    */
    MESSAGE(Ev_HD_SetOsdBannerInfoCfg_Cmd)
    BODY(mt::TMTBannerInfo, )

    MESSAGE(Ev_HD_SetOsdBannerInfoCfg_Ntf)
    BODY(mt::TMTBannerInfo, )


    /*
    * key : emHD_Cfg_LabelInfo
    */
    MESSAGE(Ev_HD_SetLabelInfoCfg_Cmd)
    BODY(mt::TMTLabelInfo, )

    MESSAGE(Ev_HD_SetLabelInfoCfg_Ntf)
    BODY(mt::TMTLabelInfo, )


    /*
    * key : emHD_Cfg_AutoSleep
    */
    MESSAGE(Ev_HD_SetAutoSleepCfg_Cmd)
    BODY(mt::TMTAutoSleep, )

    MESSAGE(Ev_HD_SetAutoSleepCfg_Ntf)
    BODY(mt::TMTAutoSleep, )


    /*
    * key : emHD_Cfg_SysTime
    */
    MESSAGE(Ev_HD_SetSysTimeCfg_Cmd)
    BODY(mt::TMTCfgSystemTime, )

    MESSAGE(Ev_HD_SetSysTimeCfg_Ntf)
    BODY(mt::TMTCfgSystemTime, )


    /*
    * key : emHD_Cfg_MicGain
    */
    MESSAGE(Ev_HD_SetMicGainCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_HD_SetMicGainCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emHD_Cfg_AecDebug
    */
    MESSAGE(Ev_HD_SetAecDebugCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_HD_SetAecDebugCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emHD_Cfg_AudInPortList
    */
    MESSAGE(Ev_HD_SetAudInPortListCfg_Cmd)
    BODY(mt::TMTHDAudInPortList, )

    MESSAGE(Ev_HD_SetAudInPortListCfg_Ntf)
    BODY(mt::TMTHDAudInPortList, )


    /*
    * key : emHD_Cfg_AudOutPortList
    */
    MESSAGE(Ev_HD_SetAudOutPortListCfg_Cmd)
    BODY(mt::TMTHDAudOutPortList, )

    MESSAGE(Ev_HD_SetAudOutPortListCfg_Ntf)
    BODY(mt::TMTHDAudOutPortList, )


    /*
    * key : emHD_Cfg_Pri1stVidInPort
    */
    MESSAGE(Ev_HD_SetPri1stVidInPortCfg_Cmd)
    BODY(mt::TMTHDVidInPort, )

    MESSAGE(Ev_HD_SetPri1stVidInPortCfg_Ntf)
    BODY(mt::TMTHDVidInPort, )


    /*
    * key : emHD_Cfg_Pri2ndVidInPort
    */
    MESSAGE(Ev_HD_SetPri2ndVidInPortCfg_Cmd)
    BODY(mt::TMTHDVidInPort, )

    MESSAGE(Ev_HD_SetPri2ndVidInPortCfg_Ntf)
    BODY(mt::TMTHDVidInPort, )


    /*
    * key : emHD_Cfg_Pri3rdVidInPort
    */
    MESSAGE(Ev_HD_SetPri3rdVidInPortCfg_Cmd)
    BODY(mt::TMTHDVidInPort, )

    MESSAGE(Ev_HD_SetPri3rdVidInPortCfg_Ntf)
    BODY(mt::TMTHDVidInPort, )


    /*
    * key : emHD_Cfg_AssVidInPort
    */
    MESSAGE(Ev_HD_SetAssVidInPortCfg_Cmd)
    BODY(mt::TMTHDVidInPort, )

    MESSAGE(Ev_HD_SetAssVidInPortCfg_Ntf)
    BODY(mt::TMTHDVidInPort, )


    /*
    * key : emHD_Cfg_MultiVideo
    */
    MESSAGE(Ev_HD_SetMultiVideoCfg_Cmd)
    BODY(mt::TMTHDMultiVideo, )

    MESSAGE(Ev_HD_SetMultiVideoCfg_Ntf)
    BODY(mt::TMTHDMultiVideo, )


    /*
    * key : emHD_Cfg_VideoMatrixScheme
    */
    MESSAGE(Ev_HD_SetVideoMatrixSchemeCfg_Cmd)
    BODY(mt::TMTAllVideoMatrixScheme, )

    MESSAGE(Ev_HD_SetVideoMatrixSchemeCfg_Ntf)
    BODY(mt::TMTAllVideoMatrixScheme, )


    /*
    * key : emHD_Cfg_LastDisplay
    */
    MESSAGE(Ev_HD_SetLastDisplayCfg_Cmd)
    BODY(mt::TMTLastDisplay, )

    MESSAGE(Ev_HD_SetLastDisplayCfg_Ntf)
    BODY(mt::TMTLastDisplay, )


    /*
    * key : emHD_Cfg_ImageNoiseLevel
    */
    MESSAGE(Ev_HD_SetImageNoiseLevelCfg_Cmd)
    BODY(mt::TMTHDImageNoise, )

    MESSAGE(Ev_HD_SetImageNoiseLevelCfg_Ntf)
    BODY(mt::TMTHDImageNoise, )


    /*
    * key : emHD_Cfg_ImageEnhancement
    */
    MESSAGE(Ev_HD_SetImageEnhancementCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_HD_SetImageEnhancementCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Cfg_Pri1stDeformationTensile
    */
    MESSAGE(Ev_HD_SetPri1stDeformationTensileCfg_Cmd)
    BODY(mt::TMTHDImageDeformationTensile, )

    MESSAGE(Ev_HD_SetPri1stDeformationTensileCfg_Ntf)
    BODY(mt::TMTHDImageDeformationTensile, )


    /*
    * key : emHD_Cfg_Pri2ndDeformationTensile
    */
    MESSAGE(Ev_HD_SetPri2ndDeformationTensileCfg_Cmd)
    BODY(mt::TMTHDImageDeformationTensile, )

    MESSAGE(Ev_HD_SetPri2ndDeformationTensileCfg_Ntf)
    BODY(mt::TMTHDImageDeformationTensile, )


    /*
    * key : emHD_Cfg_AssDeformationTensile
    */
    MESSAGE(Ev_HD_SetAssDeformationTensileCfg_Cmd)
    BODY(mt::TMTHDImageDeformationTensile, )

    MESSAGE(Ev_HD_SetAssDeformationTensileCfg_Ntf)
    BODY(mt::TMTHDImageDeformationTensile, )


    /*
    * key : emHD_Cfg_Pri1stGeometricScaling
    */
    MESSAGE(Ev_HD_SetPri1stGeometricScalingCfg_Cmd)
    BODY(mt::TMTHDImageGeometricScaling, )

    MESSAGE(Ev_HD_SetPri1stGeometricScalingCfg_Ntf)
    BODY(mt::TMTHDImageGeometricScaling, )


    /*
    * key : emHD_Cfg_Pri2ndGeometricScaling
    */
    MESSAGE(Ev_HD_SetPri2ndGeometricScalingCfg_Cmd)
    BODY(mt::TMTHDImageGeometricScaling, )

    MESSAGE(Ev_HD_SetPri2ndGeometricScalingCfg_Ntf)
    BODY(mt::TMTHDImageGeometricScaling, )


    /*
    * key : emHD_Cfg_Pri3rdGeometricScaling
    */
    MESSAGE(Ev_HD_SetPri3rdGeometricScalingCfg_Cmd)
    BODY(mt::TMTHDImageGeometricScaling, )

    MESSAGE(Ev_HD_SetPri3rdGeometricScalingCfg_Ntf)
    BODY(mt::TMTHDImageGeometricScaling, )


    /*
    * key : emHD_Cfg_AssGeometricScaling
    */
    MESSAGE(Ev_HD_SetAssGeometricScalingCfg_Cmd)
    BODY(mt::TMTHDImageGeometricScaling, )

    MESSAGE(Ev_HD_SetAssGeometricScalingCfg_Ntf)
    BODY(mt::TMTHDImageGeometricScaling, )


    /*
    * key : emHD_Cfg_EdgePixel
    */
    MESSAGE(Ev_HD_SetEdgePixelCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_HD_SetEdgePixelCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emHD_Cfg_CameraList
    */
    MESSAGE(Ev_HD_SetCameraListCfg_Cmd)
    BODY(mt::TMTHDCameraList, )

    MESSAGE(Ev_HD_SetCameraListCfg_Ntf)
    BODY(mt::TMTHDCameraList, )


    /*
    * key : emHD_Cfg_CameraAiList
    */
    MESSAGE(Ev_HD_SetCameraAiListCfg_Cmd)
    BODY(mt::TMTHDCameraAiList, )

    MESSAGE(Ev_HD_SetCameraAiListCfg_Ntf)
    BODY(mt::TMTHDCameraAiList, )


    /*
    * key : emHD_Cfg_SerialCtrl
    */
    MESSAGE(Ev_HD_SetSerialCtrlCfg_Cmd)
    BODY(mt::TMTHDSerialCtrl, )

    MESSAGE(Ev_HD_SetSerialCtrlCfg_Ntf)
    BODY(mt::TMTHDSerialCtrl, )


    /*
    * key : emHD_Cfg_SerialList
    */
    MESSAGE(Ev_HD_SetSerialListCfg_Cmd)
    BODY(mt::TMTHDSerialList, )

    MESSAGE(Ev_HD_SetSerialListCfg_Ntf)
    BODY(mt::TMTHDSerialList, )


    /*
    * key : emHD_Cfg_SerialMonitorList
    */
    MESSAGE(Ev_HD_SetSerialMonitorListCfg_Cmd)
    BODY(mt::TMTHDSerialMonitorList, )

    MESSAGE(Ev_HD_SetSerialMonitorListCfg_Ntf)
    BODY(mt::TMTHDSerialMonitorList, )


    /*
    * key : emHD_Cfg_VGAImageAdjust
    */
    MESSAGE(Ev_HD_SetVGAImageAdjustCfg_Cmd)
    BODY(mt::TMTVgaImageAdjustCfg, )

    MESSAGE(Ev_HD_SetVGAImageAdjustCfg_Ntf)
    BODY(mt::TMTVgaImageAdjustCfg, )


    /*
    * key : emHD_Cfg_VGAImageOutAdjust
    */
    MESSAGE(Ev_HD_SetVGAImageOutAdjustCfg_Cmd)
    BODY(mt::TMTVgaImageOutAdjustCfg, )

    MESSAGE(Ev_HD_SetVGAImageOutAdjustCfg_Ntf)
    BODY(mt::TMTVgaImageOutAdjustCfg, )


    /*
    * key : emHD_Cfg_VideoSrcTag
    */
    MESSAGE(Ev_HD_SetVideoSrcTagCfg_Cmd)
    BODY(mt::TMTVideoSrcTagList, )

    MESSAGE(Ev_HD_SetVideoSrcTagCfg_Ntf)
    BODY(mt::TMTVideoSrcTagList, )


    /*
    * key : emHD_Cfg_VideoOutTag
    */
    MESSAGE(Ev_HD_SetVideoOutTagCfg_Cmd)
    BODY(mt::TMTVideoOutTagList, )

    MESSAGE(Ev_HD_SetVideoOutTagCfg_Ntf)
    BODY(mt::TMTVideoOutTagList, )


    /*
    * key : emHD_Cfg_SnapShotFtpCfg
    */
    MESSAGE(Ev_HD_SetSnapShotFtpCfgCfg_Cmd)
    BODY(mt::TMTSnapShotFtpCfg, )

    MESSAGE(Ev_HD_SetSnapShotFtpCfgCfg_Ntf)
    BODY(mt::TMTSnapShotFtpCfg, )


    /*
    * key : emHD_Cfg_PresetNameInfo
    */
    MESSAGE(Ev_HD_SetPresetNameInfoCfg_Cmd)
    BODY(mt::TMTAllPreSetNameInfoCfg, )

    MESSAGE(Ev_HD_SetPresetNameInfoCfg_Ntf)
    BODY(mt::TMTAllPreSetNameInfoCfg, )


    /*
    * key : emHD_Cfg_MainFstDisplayRatio
    */
    MESSAGE(Ev_HD_SetMainFstDisplayRatioCfg_Cmd)
    BODY(mt::TMTDisplayRatio, )

    MESSAGE(Ev_HD_SetMainFstDisplayRatioCfg_Ntf)
    BODY(mt::TMTDisplayRatio, )


    /*
    * key : emHD_Cfg_MainSecDisplayRatio
    */
    MESSAGE(Ev_HD_SetMainSecDisplayRatioCfg_Cmd)
    BODY(mt::TMTDisplayRatio, )

    MESSAGE(Ev_HD_SetMainSecDisplayRatioCfg_Ntf)
    BODY(mt::TMTDisplayRatio, )


    /*
    * key : emHD_Cfg_MainTrdDisplayRatio
    */
    MESSAGE(Ev_HD_SetMainTrdDisplayRatioCfg_Cmd)
    BODY(mt::TMTDisplayRatio, )

    MESSAGE(Ev_HD_SetMainTrdDisplayRatioCfg_Ntf)
    BODY(mt::TMTDisplayRatio, )


    /*
    * key : emHD_Cfg_AssDisplayRatio
    */
    MESSAGE(Ev_HD_SetAssDisplayRatioCfg_Cmd)
    BODY(mt::TMTDisplayRatio, )

    MESSAGE(Ev_HD_SetAssDisplayRatioCfg_Ntf)
    BODY(mt::TMTDisplayRatio, )


    /*
    * key : emHD_Cfg_VgaOutBright
    */
    MESSAGE(Ev_HD_SetVgaOutBrightCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_HD_SetVgaOutBrightCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emHD_Cfg_VgaOutContrast
    */
    MESSAGE(Ev_HD_SetVgaOutContrastCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_HD_SetVgaOutContrastCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emHD_Cfg_VgaOutSaturation
    */
    MESSAGE(Ev_HD_SetVgaOutSaturationCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_HD_SetVgaOutSaturationCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emHD_Cfg_EthWorkModeList
    */
    MESSAGE(Ev_HD_SetEthWorkModeListCfg_Cmd)
    BODY(mt::TEthnetWorkModeList, )

    MESSAGE(Ev_HD_SetEthWorkModeListCfg_Ntf)
    BODY(mt::TEthnetWorkModeList, )


    /*
    * key : emHD_Cfg_EthnetCfg
    */
    MESSAGE(Ev_HD_SetEthnetCfgCfg_Cmd)
    BODY(mt::TEthnetCfg, )

    MESSAGE(Ev_HD_SetEthnetCfgCfg_Ntf)
    BODY(mt::TEthnetCfg, )


    /*
    * key : emHD_Cfg_EthPPPoECfg
    */
    MESSAGE(Ev_HD_SetEthPPPoECfgCfg_Cmd)
    BODY(mt::TEthnetPPPoECfg, )

    MESSAGE(Ev_HD_SetEthPPPoECfgCfg_Ntf)
    BODY(mt::TEthnetPPPoECfg, )


    /*
    * key : emHD_Cfg_WifiWorkMode
    */
    MESSAGE(Ev_HD_SetWifiWorkModeCfg_Cmd)
    BODY(mt::TWifiWorkMode, )

    MESSAGE(Ev_HD_SetWifiWorkModeCfg_Ntf)
    BODY(mt::TWifiWorkMode, )


    /*
    * key : emHD_Cfg_WifiApCfg
    */
    MESSAGE(Ev_HD_SetWifiApCfgCfg_Cmd)
    BODY(mt::TWifiApConfiguration, )

    MESSAGE(Ev_HD_SetWifiApCfgCfg_Ntf)
    BODY(mt::TWifiApConfiguration, )


    /*
    * key : emHD_Cfg_WifiClientCfg
    */
    MESSAGE(Ev_HD_SetWifiClientCfgCfg_Cmd)
    BODY(mt::TWifiConfiguration, )

    MESSAGE(Ev_HD_SetWifiClientCfgCfg_Ntf)
    BODY(mt::TWifiConfiguration, )


    /*
    * key : emHD_Cfg_MobileDataWorkMode
    */
    MESSAGE(Ev_HD_SetMobileDataWorkModeCfg_Cmd)
    BODY(mt::TMobileDataWorkMode, )

    MESSAGE(Ev_HD_SetMobileDataWorkModeCfg_Ntf)
    BODY(mt::TMobileDataWorkMode, )


    /*
    * key : emHD_Cfg_E1Cfg
    */
    MESSAGE(Ev_HD_SetE1CfgCfg_Cmd)
    BODY(mt::TE1Cfg, )

    MESSAGE(Ev_HD_SetE1CfgCfg_Ntf)
    BODY(mt::TE1Cfg, )


    /*
    * key : emHD_Cfg_RouteCfgList
    */
    MESSAGE(Ev_HD_SetRouteCfgListCfg_Cmd)
    BODY(mt::TRouteItemInfoList, )

    MESSAGE(Ev_HD_SetRouteCfgListCfg_Ntf)
    BODY(mt::TRouteItemInfoList, )


    /*
    * key : emHD_Cfg_VidInPortBright
    */
    MESSAGE(Ev_HD_SetVidInPortBrightCfg_Cmd)
    BODY(mt::TMtVideoPortParamList, )

    MESSAGE(Ev_HD_SetVidInPortBrightCfg_Ntf)
    BODY(mt::TMtVideoPortParamList, )


    /*
    * key : emHD_Cfg_VidInPortContrast
    */
    MESSAGE(Ev_HD_SetVidInPortContrastCfg_Cmd)
    BODY(mt::TMtVideoPortParamList, )

    MESSAGE(Ev_HD_SetVidInPortContrastCfg_Ntf)
    BODY(mt::TMtVideoPortParamList, )


    /*
    * key : emHD_Cfg_VidInPortSaturation
    */
    MESSAGE(Ev_HD_SetVidInPortSaturationCfg_Cmd)
    BODY(mt::TMtVideoPortParamList, )

    MESSAGE(Ev_HD_SetVidInPortSaturationCfg_Ntf)
    BODY(mt::TMtVideoPortParamList, )


    /*
    * key : emHD_Cfg_ResizeMode
    */
    MESSAGE(Ev_HD_SetResizeModeCfg_Cmd)
    BODY(mt::TMTResizeMode, )

    MESSAGE(Ev_HD_SetResizeModeCfg_Ntf)
    BODY(mt::TMTResizeMode, )


    /*
    * key : emHD_Cfg_FastCallList
    */
    MESSAGE(Ev_HD_SetFastCallListCfg_Cmd)
    BODY(mt::TFastCallList, )

    MESSAGE(Ev_HD_SetFastCallListCfg_Ntf)
    BODY(mt::TFastCallList, )


    /*
    * key : emHD_Cfg_RfMatchStateList
    */
    MESSAGE(Ev_HD_SetRfMatchStateListCfg_Cmd)
    BODY(mt::TMTRfMatchStateList, )

    MESSAGE(Ev_HD_SetRfMatchStateListCfg_Ntf)
    BODY(mt::TMTRfMatchStateList, )


    /*
    * key : emHD_Cfg_CurPresetIndex
    */
    MESSAGE(Ev_HD_SetCurPresetIndexCfg_Cmd)
    BODY(mt::TMTAllCodecPreSetIndex, )

    MESSAGE(Ev_HD_SetCurPresetIndexCfg_Ntf)
    BODY(mt::TMTAllCodecPreSetIndex, )


    /*
    * key : emHD_Cfg_SDIOneInOneOutOrTwoIn
    */
    MESSAGE(Ev_HD_SetSDIOneInOneOutOrTwoInCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_HD_SetSDIOneInOneOutOrTwoInCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emHD_Cfg_CameraNoise
    */
    MESSAGE(Ev_HD_SetCameraNoiseCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_HD_SetCameraNoiseCfg_Ntf)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraVidStd
    */
    MESSAGE(Ev_HD_SetCameraVidStdCfg_Cmd)
    BODY(mt::TMtCameraVidStd, )

    MESSAGE(Ev_HD_SetCameraVidStdCfg_Ntf)
    BODY(mt::TMtCameraVidStd, )


    /*
    * key : emHD_Cfg_CameraContrlExchange
    */
    MESSAGE(Ev_HD_SetCameraContrlExchangeCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_HD_SetCameraContrlExchangeCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Cfg_CameraImgMode
    */
    MESSAGE(Ev_HD_SetCameraImgModeCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_HD_SetCameraImgModeCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emHD_Cfg_CameraPersonFirst
    */
    MESSAGE(Ev_HD_SetCameraPersonFirstCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_HD_SetCameraPersonFirstCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_CFG_CameraHeadStand
    */
    MESSAGE(Ev_HD_SetCameraHeadStandCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_HD_SetCameraHeadStandCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Cfg_LimitedIpCfg
    */
    MESSAGE(Ev_HD_SetLimitedIpCfgCfg_Cmd)
    BODY(mt::TLimitedIpCfg, )

    MESSAGE(Ev_HD_SetLimitedIpCfgCfg_Ntf)
    BODY(mt::TLimitedIpCfg, )


    /*
    * key : emHD_Cfg_SubAudExpansion
    */
    MESSAGE(Ev_HD_SetSubAudExpansionCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_HD_SetSubAudExpansionCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Cfg_CameraSharpness
    */
    MESSAGE(Ev_HD_SetCameraSharpnessCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_HD_SetCameraSharpnessCfg_Ntf)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraISO
    */
    MESSAGE(Ev_HD_SetCameraISOCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_HD_SetCameraISOCfg_Ntf)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraExposureMode
    */
    MESSAGE(Ev_HD_SetCameraExposureModeCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_HD_SetCameraExposureModeCfg_Ntf)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraAperture
    */
    MESSAGE(Ev_HD_SetCameraApertureCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_HD_SetCameraApertureCfg_Ntf)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraShutter
    */
    MESSAGE(Ev_HD_SetCameraShutterCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_HD_SetCameraShutterCfg_Ntf)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraAotoExposureGain
    */
    MESSAGE(Ev_HD_SetCameraAotoExposureGainCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_HD_SetCameraAotoExposureGainCfg_Ntf)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraManualExposureGain
    */
    MESSAGE(Ev_HD_SetCameraManualExposureGainCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_HD_SetCameraManualExposureGainCfg_Ntf)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraBright
    */
    MESSAGE(Ev_HD_SetCameraBrightCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_HD_SetCameraBrightCfg_Ntf)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraWhiteBalance
    */
    MESSAGE(Ev_HD_SetCameraWhiteBalanceCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_HD_SetCameraWhiteBalanceCfg_Ntf)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraHue
    */
    MESSAGE(Ev_HD_SetCameraHueCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_HD_SetCameraHueCfg_Ntf)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraContrast
    */
    MESSAGE(Ev_HD_SetCameraContrastCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_HD_SetCameraContrastCfg_Ntf)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraSaturation
    */
    MESSAGE(Ev_HD_SetCameraSaturationCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_HD_SetCameraSaturationCfg_Ntf)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraBackLightSwitch
    */
    MESSAGE(Ev_HD_SetCameraBackLightSwitchCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_HD_SetCameraBackLightSwitchCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emHD_Cfg_CameraBackLightLevel
    */
    MESSAGE(Ev_HD_SetCameraBackLightLevelCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_HD_SetCameraBackLightLevelCfg_Ntf)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_Camera2dNoise
    */
    MESSAGE(Ev_HD_SetCamera2dNoiseCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_HD_SetCamera2dNoiseCfg_Ntf)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_Camera3dNoise
    */
    MESSAGE(Ev_HD_SetCamera3dNoiseCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_HD_SetCamera3dNoiseCfg_Ntf)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraRedGain
    */
    MESSAGE(Ev_HD_SetCameraRedGainCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_HD_SetCameraRedGainCfg_Ntf)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraBlueGain
    */
    MESSAGE(Ev_HD_SetCameraBlueGainCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_HD_SetCameraBlueGainCfg_Ntf)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraImgGamma
    */
    MESSAGE(Ev_HD_SetCameraImgGammaCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_HD_SetCameraImgGammaCfg_Ntf)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraImgDefog
    */
    MESSAGE(Ev_HD_SetCameraImgDefogCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_HD_SetCameraImgDefogCfg_Ntf)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraImgDigDynSwitch
    */
    MESSAGE(Ev_HD_SetCameraImgDigDynSwitchCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_HD_SetCameraImgDigDynSwitchCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Cfg_CameraImgDigDynLevel
    */
    MESSAGE(Ev_HD_SetCameraImgDigDynLevelCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_HD_SetCameraImgDigDynLevelCfg_Ntf)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraLastPosCfg
    */
    MESSAGE(Ev_HD_SetCameraLastPosCfgCfg_Cmd)
    BODY(mt::TMtCameraLastPos, )

    MESSAGE(Ev_HD_SetCameraLastPosCfgCfg_Ntf)
    BODY(mt::TMtCameraLastPos, )


    /*
    * key : emHD_Cfg_CameraEnableDigZoom
    */
    MESSAGE(Ev_HD_SetCameraEnableDigZoomCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_HD_SetCameraEnableDigZoomCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_TAudioRemoveG719
    */
    MESSAGE(Ev_MT_SetTAudioRemoveG719Cfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetTAudioRemoveG719Cfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_LoadAdaptiveVideo
    */
    MESSAGE(Ev_MT_SetLoadAdaptiveVideoCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetLoadAdaptiveVideoCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Cfg_ImageSequenceNumberType
    */
    MESSAGE(Ev_HD_SetImageSequenceNumberTypeCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_HD_SetImageSequenceNumberTypeCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_TForceRtpExStrip
    */
    MESSAGE(Ev_MT_SetTForceRtpExStripCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetTForceRtpExStripCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_TEnableDsp6678Detect
    */
    MESSAGE(Ev_MT_SetTEnableDsp6678DetectCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetTEnableDsp6678DetectCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_TG711AudioDuration
    */
    MESSAGE(Ev_MT_SetTG711AudioDurationCfg_Cmd)
    BODY(mt::UnknownProtoMsg, )

    MESSAGE(Ev_MT_SetTG711AudioDurationCfg_Ntf)
    BODY(mt::UnknownProtoMsg, )


    /*
    * key : emMt_Cfg_TAudioRemoveOPUS
    */
    MESSAGE(Ev_MT_SetTAudioRemoveOPUSCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetTAudioRemoveOPUSCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_TRemoveMultAudFormats
    */
    MESSAGE(Ev_MT_SetTRemoveMultAudFormatsCfg_Cmd)
    BODY(mt::TMultiU32, )

    MESSAGE(Ev_MT_SetTRemoveMultAudFormatsCfg_Ntf)
    BODY(mt::TMultiU32, )


    /*
    * key : emMt_Cfg_TEnableBfcpTwice
    */
    MESSAGE(Ev_MT_SetTEnableBfcpTwiceCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetTEnableBfcpTwiceCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_TEnableAudioEncParam
    */
    MESSAGE(Ev_MT_SetTEnableAudioEncParamCfg_Cmd)
    BODY(mt::TAudioEncParamList, )

    MESSAGE(Ev_MT_SetTEnableAudioEncParamCfg_Ntf)
    BODY(mt::TAudioEncParamList, )


    /*
    * key : emMt_Cfg_TSetRoundTripType
    */
    MESSAGE(Ev_MT_SetTSetRoundTripTypeCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_SetTSetRoundTripTypeCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_KedaAacSampFreq32K
    */
    MESSAGE(Ev_MT_SetKedaAacSampFreq32KCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetKedaAacSampFreq32KCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_VidDecDynamicPayload
    */
    MESSAGE(Ev_MT_SetVidDecDynamicPayloadCfg_Cmd)
    BODY(mt::TDynamicPayload, )

    MESSAGE(Ev_MT_SetVidDecDynamicPayloadCfg_Ntf)
    BODY(mt::TDynamicPayload, )


    /*
    * key : emMt_Cfg_AudDecDynamicPayload
    */
    MESSAGE(Ev_MT_SetAudDecDynamicPayloadCfg_Cmd)
    BODY(mt::TDynamicPayload, )

    MESSAGE(Ev_MT_SetAudDecDynamicPayloadCfg_Ntf)
    BODY(mt::TDynamicPayload, )


    /*
    * key : emMt_Cfg_TIgnoreBitrateZero
    */
    MESSAGE(Ev_MT_SetTIgnoreBitrateZeroCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetTIgnoreBitrateZeroCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_T323AdditionalConfig
    */
    MESSAGE(Ev_MT_SetT323AdditionalConfigCfg_Cmd)
    BODY(mt::TMultiU32, )

    MESSAGE(Ev_MT_SetT323AdditionalConfigCfg_Ntf)
    BODY(mt::TMultiU32, )


    /*
    * key : emMt_Cfg_TKeyFrameInterval
    */
    MESSAGE(Ev_MT_SetTKeyFrameIntervalCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_SetTKeyFrameIntervalCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_TAudioRemoveLCLD
    */
    MESSAGE(Ev_MT_SetTAudioRemoveLCLDCfg_Cmd)
    BODY(mt::UnknownProtoMsg, )

    MESSAGE(Ev_MT_SetTAudioRemoveLCLDCfg_Ntf)
    BODY(mt::UnknownProtoMsg, )


    /*
    * key : emMt_Cfg_AudioPrecedence
    */
    MESSAGE(Ev_MT_SetAudioPrecedenceCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetAudioPrecedenceCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_TForceSet323Stack
    */
    MESSAGE(Ev_MT_SetTForceSet323StackCfg_Cmd)
    BODY(mt::TMtForceSetH323Stack, )

    MESSAGE(Ev_MT_SetTForceSet323StackCfg_Ntf)
    BODY(mt::TMtForceSetH323Stack, )


    /*
    * key : emMt_Cfg_TEnableIpwType
    */
    MESSAGE(Ev_MT_SetTEnableIpwTypeCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetTEnableIpwTypeCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_TEnableVidBitRateCtrl
    */
    MESSAGE(Ev_MT_SetTEnableVidBitRateCtrlCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetTEnableVidBitRateCtrlCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_TVideoSliceCount
    */
    MESSAGE(Ev_MT_SetTVideoSliceCountCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_SetTVideoSliceCountCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_SipKeepAliveItrvl
    */
    MESSAGE(Ev_MT_SetSipKeepAliveItrvlCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_SetSipKeepAliveItrvlCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_TRegTimeout
    */
    MESSAGE(Ev_MT_SetTRegTimeoutCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_SetTRegTimeoutCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_AutoRas
    */
    MESSAGE(Ev_MT_SetAutoRasCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetAutoRasCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_TSipCallPort
    */
    MESSAGE(Ev_MT_SetTSipCallPortCfg_Cmd)
    BODY(mt::TMultiU32, )

    MESSAGE(Ev_MT_SetTSipCallPortCfg_Ntf)
    BODY(mt::TMultiU32, )


    /*
    * key : emMt_Cfg_SipConnection
    */
    MESSAGE(Ev_MT_SetSipConnectionCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_SetSipConnectionCfg_Ntf)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_TEnableStrongAut
    */
    MESSAGE(Ev_MT_SetTEnableStrongAutCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetTEnableStrongAutCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_UseTlsCert
    */
    MESSAGE(Ev_MT_SetUseTlsCertCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetUseTlsCertCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_UseGMTlsCert
    */
    MESSAGE(Ev_MT_SetUseGMTlsCertCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_SetUseGMTlsCertCfg_Ntf)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_QtSetting
    */
    MESSAGE(Ev_MT_SetQtSettingCfg_Cmd)
    BODY(mt::TMtQtAddr, )

    MESSAGE(Ev_MT_SetQtSettingCfg_Ntf)
    BODY(mt::TMtQtAddr, )


    /*
    * key : emMt_Cfg_QtKeyUpdateMode
    */
    MESSAGE(Ev_MT_SetQtKeyUpdateModeCfg_Cmd)
    BODY(mt::TMtSecKeyUpdatePolicy, )

    MESSAGE(Ev_MT_SetQtKeyUpdateModeCfg_Ntf)
    BODY(mt::TMtSecKeyUpdatePolicy, )



#if !defined(_MESSAGE_HELP_)
     EV_END(CONFIG) = EVSEG_CONFIG_END
};
#endif

#define Is_MtConfig_Msg(m) ((m) >= EV_BGN(CONFIG) && (m) <= EV_END(CONFIG))

#endif //_MT_CONFIG_MSG_H_

