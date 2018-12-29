#ifndef _MT_BLL_CONFIG_MSG_H_
#define _MT_BLL_CONFIG_MSG_H_
///////////////////////////////////////////////////////////////
//默认 配置消息 定义
///////////////////////////////////////////////////////////////
//脚本 gen_cfg_files 根据 mtdskey.h 自动生成,请勿手动修改
///////////////////////////////////////////////////////////////

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMtConfigMsg
{
    EV_BLL_BGN(CONFIG) = EVSEG_BLL_CONFIG_BGN,
#endif


    /*
    * key : emMt_Cfg_IPQoS
    */
    MESSAGE(Ev_MT_BLL_SetIPQoSCfg_Cmd)
    BODY(mt::TMTIPQoS, )

    MESSAGE(Ev_MT_BLL_SetIPQoSCfg_Ntf)
    BODY(mt::TMTIPQoS, )

    MESSAGE(Ev_MT_BLL_GetIPQoSCfg_Req)

    MESSAGE(Ev_MT_BLL_GetIPQoSCfg_Rsp)
    BODY(mt::TMTIPQoS, )


    /*
    * key : emMt_Cfg_MTU
    */
    MESSAGE(Ev_MT_BLL_SetMTUCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_SetMTUCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_GetMTUCfg_Req)

    MESSAGE(Ev_MT_BLL_GetMTUCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_NAT
    */
    MESSAGE(Ev_MT_BLL_SetNATCfg_Cmd)
    BODY(mt::TMTNat, )

    MESSAGE(Ev_MT_BLL_SetNATCfg_Ntf)
    BODY(mt::TMTNat, )

    MESSAGE(Ev_MT_BLL_GetNATCfg_Req)

    MESSAGE(Ev_MT_BLL_GetNATCfg_Rsp)
    BODY(mt::TMTNat, )


    /*
    * key : emMt_Cfg_APSList
    */
    MESSAGE(Ev_MT_BLL_SetAPSListCfg_Cmd)
    BODY(mt::TMtAPSSvrList, )

    MESSAGE(Ev_MT_BLL_SetAPSListCfg_Ntf)
    BODY(mt::TMtAPSSvrList, )

    MESSAGE(Ev_MT_BLL_GetAPSListCfg_Req)

    MESSAGE(Ev_MT_BLL_GetAPSListCfg_Rsp)
    BODY(mt::TMtAPSSvrList, )


    /*
    * key : emMt_Cfg_LastSuccessApsAddr
    */
    MESSAGE(Ev_MT_BLL_SetLastSuccessApsAddrCfg_Cmd)
    BODY(mt::TMtAPSAddrCfgs, )

    MESSAGE(Ev_MT_BLL_SetLastSuccessApsAddrCfg_Ntf)
    BODY(mt::TMtAPSAddrCfgs, )

    MESSAGE(Ev_MT_BLL_GetLastSuccessApsAddrCfg_Req)

    MESSAGE(Ev_MT_BLL_GetLastSuccessApsAddrCfg_Rsp)
    BODY(mt::TMtAPSAddrCfgs, )


    /*
    * key : emMt_Cfg_BackUpAPSList
    */
    MESSAGE(Ev_MT_BLL_SetBackUpAPSListCfg_Cmd)
    BODY(mt::TMtAPSAddrCfgs, )

    MESSAGE(Ev_MT_BLL_SetBackUpAPSListCfg_Ntf)
    BODY(mt::TMtAPSAddrCfgs, )

    MESSAGE(Ev_MT_BLL_GetBackUpAPSListCfg_Req)

    MESSAGE(Ev_MT_BLL_GetBackUpAPSListCfg_Rsp)
    BODY(mt::TMtAPSAddrCfgs, )


    /*
    * key : emMt_Cfg_GK
    */
    MESSAGE(Ev_MT_BLL_SetGKCfg_Cmd)
    BODY(mt::TMtCSUAddr, )

    MESSAGE(Ev_MT_BLL_SetGKCfg_Ntf)
    BODY(mt::TMtCSUAddr, )

    MESSAGE(Ev_MT_BLL_GetGKCfg_Req)

    MESSAGE(Ev_MT_BLL_GetGKCfg_Rsp)
    BODY(mt::TMtCSUAddr, )


    /*
    * key : emMt_Cfg_SipSvrManu
    */
    MESSAGE(Ev_MT_BLL_SetSipSvrManuCfg_Cmd)
    BODY(mt::TMtSipSvrAddr, )

    MESSAGE(Ev_MT_BLL_SetSipSvrManuCfg_Ntf)
    BODY(mt::TMtSipSvrAddr, )

    MESSAGE(Ev_MT_BLL_GetSipSvrManuCfg_Req)

    MESSAGE(Ev_MT_BLL_GetSipSvrManuCfg_Rsp)
    BODY(mt::TMtSipSvrAddr, )


    /*
    * key : emMt_Cfg_SipSvr
    */
    MESSAGE(Ev_MT_BLL_SetSipSvrCfg_Cmd)
    BODY(mt::TMtSipSvrAddr, )

    MESSAGE(Ev_MT_BLL_SetSipSvrCfg_Ntf)
    BODY(mt::TMtSipSvrAddr, )

    MESSAGE(Ev_MT_BLL_GetSipSvrCfg_Req)

    MESSAGE(Ev_MT_BLL_GetSipSvrCfg_Rsp)
    BODY(mt::TMtSipSvrAddr, )


    /*
    * key : emMt_Cfg_CSU
    */
    MESSAGE(Ev_MT_BLL_SetCSUCfg_Cmd)
    BODY(mt::TMtCSUAddr, )

    MESSAGE(Ev_MT_BLL_SetCSUCfg_Ntf)
    BODY(mt::TMtCSUAddr, )

    MESSAGE(Ev_MT_BLL_GetCSUCfg_Req)

    MESSAGE(Ev_MT_BLL_GetCSUCfg_Rsp)
    BODY(mt::TMtCSUAddr, )


    /*
    * key : emMt_Cfg_SUS
    */
    MESSAGE(Ev_MT_BLL_SetSUSCfg_Cmd)
    BODY(mt::TMtSUSAddr, )

    MESSAGE(Ev_MT_BLL_SetSUSCfg_Ntf)
    BODY(mt::TMtSUSAddr, )

    MESSAGE(Ev_MT_BLL_GetSUSCfg_Req)

    MESSAGE(Ev_MT_BLL_GetSUSCfg_Rsp)
    BODY(mt::TMtSUSAddr, )


    /*
    * key : emMt_Cfg_SusManu
    */
    MESSAGE(Ev_MT_BLL_SetSusManuCfg_Cmd)
    BODY(mt::TMtSUSAddr, )

    MESSAGE(Ev_MT_BLL_SetSusManuCfg_Ntf)
    BODY(mt::TMtSUSAddr, )

    MESSAGE(Ev_MT_BLL_GetSusManuCfg_Req)

    MESSAGE(Ev_MT_BLL_GetSusManuCfg_Rsp)
    BODY(mt::TMtSUSAddr, )


    /*
    * key : emMt_Cfg_NMS
    */
    MESSAGE(Ev_MT_BLL_SetNMSCfg_Cmd)
    BODY(mt::TMtNMSAddr, )

    MESSAGE(Ev_MT_BLL_SetNMSCfg_Ntf)
    BODY(mt::TMtNMSAddr, )

    MESSAGE(Ev_MT_BLL_GetNMSCfg_Req)

    MESSAGE(Ev_MT_BLL_GetNMSCfg_Rsp)
    BODY(mt::TMtNMSAddr, )


    /*
    * key : emMt_Cfg_NmsManu
    */
    MESSAGE(Ev_MT_BLL_SetNmsManuCfg_Cmd)
    BODY(mt::TMtNMSAddr, )

    MESSAGE(Ev_MT_BLL_SetNmsManuCfg_Ntf)
    BODY(mt::TMtNMSAddr, )

    MESSAGE(Ev_MT_BLL_GetNmsManuCfg_Req)

    MESSAGE(Ev_MT_BLL_GetNmsManuCfg_Rsp)
    BODY(mt::TMtNMSAddr, )


    /*
    * key : emMt_Cfg_NTS
    */
    MESSAGE(Ev_MT_BLL_SetNTSCfg_Cmd)
    BODY(mt::TMtNTSAddr, )

    MESSAGE(Ev_MT_BLL_SetNTSCfg_Ntf)
    BODY(mt::TMtNTSAddr, )

    MESSAGE(Ev_MT_BLL_GetNTSCfg_Req)

    MESSAGE(Ev_MT_BLL_GetNTSCfg_Rsp)
    BODY(mt::TMtNTSAddr, )


    /*
    * key : emMt_Cfg_NtsManu
    */
    MESSAGE(Ev_MT_BLL_SetNtsManuCfg_Cmd)
    BODY(mt::TMtNTSAddr, )

    MESSAGE(Ev_MT_BLL_SetNtsManuCfg_Ntf)
    BODY(mt::TMtNTSAddr, )

    MESSAGE(Ev_MT_BLL_GetNtsManuCfg_Req)

    MESSAGE(Ev_MT_BLL_GetNtsManuCfg_Rsp)
    BODY(mt::TMtNTSAddr, )


    /*
    * key : emMt_Cfg_NTP
    */
    MESSAGE(Ev_MT_BLL_SetNTPCfg_Cmd)
    BODY(mt::TMtNTPAddr, )

    MESSAGE(Ev_MT_BLL_SetNTPCfg_Ntf)
    BODY(mt::TMtNTPAddr, )

    MESSAGE(Ev_MT_BLL_GetNTPCfg_Req)

    MESSAGE(Ev_MT_BLL_GetNTPCfg_Rsp)
    BODY(mt::TMtNTPAddr, )


    /*
    * key : emMt_Cfg_NtpManu
    */
    MESSAGE(Ev_MT_BLL_SetNtpManuCfg_Cmd)
    BODY(mt::TMtNTPAddr, )

    MESSAGE(Ev_MT_BLL_SetNtpManuCfg_Ntf)
    BODY(mt::TMtNTPAddr, )

    MESSAGE(Ev_MT_BLL_GetNtpManuCfg_Req)

    MESSAGE(Ev_MT_BLL_GetNtpManuCfg_Rsp)
    BODY(mt::TMtNTPAddr, )


    /*
    * key : emMt_Cfg_VOD
    */
    MESSAGE(Ev_MT_BLL_SetVODCfg_Cmd)
    BODY(mt::TMtVODSvrCfg, )

    MESSAGE(Ev_MT_BLL_SetVODCfg_Ntf)
    BODY(mt::TMtVODSvrCfg, )

    MESSAGE(Ev_MT_BLL_GetVODCfg_Req)

    MESSAGE(Ev_MT_BLL_GetVODCfg_Rsp)
    BODY(mt::TMtVODSvrCfg, )


    /*
    * key : emMt_Cfg_VRS
    */
    MESSAGE(Ev_MT_BLL_SetVRSCfg_Cmd)
    BODY(mt::TMtVRSSvrCfg, )

    MESSAGE(Ev_MT_BLL_SetVRSCfg_Ntf)
    BODY(mt::TMtVRSSvrCfg, )

    MESSAGE(Ev_MT_BLL_GetVRSCfg_Req)

    MESSAGE(Ev_MT_BLL_GetVRSCfg_Rsp)
    BODY(mt::TMtVRSSvrCfg, )


    /*
    * key : emMt_Cfg_DCS
    */
    MESSAGE(Ev_MT_BLL_SetDCSCfg_Cmd)
    BODY(mt::TMtDCSSvrAddr, )

    MESSAGE(Ev_MT_BLL_SetDCSCfg_Ntf)
    BODY(mt::TMtDCSSvrAddr, )

    MESSAGE(Ev_MT_BLL_GetDCSCfg_Req)

    MESSAGE(Ev_MT_BLL_GetDCSCfg_Rsp)
    BODY(mt::TMtDCSSvrAddr, )


    /*
    * key : emMt_Cfg_StreamMedia
    */
    MESSAGE(Ev_MT_BLL_SetStreamMediaCfg_Cmd)
    BODY(mt::TMTStreamMedia, )

    MESSAGE(Ev_MT_BLL_SetStreamMediaCfg_Ntf)
    BODY(mt::TMTStreamMedia, )

    MESSAGE(Ev_MT_BLL_GetStreamMediaCfg_Req)

    MESSAGE(Ev_MT_BLL_GetStreamMediaCfg_Rsp)
    BODY(mt::TMTStreamMedia, )


    /*
    * key : emMt_Cfg_Socks5Pxy
    */
    MESSAGE(Ev_MT_BLL_SetSocks5PxyCfg_Cmd)
    BODY(mt::TSocks5Cfg, )

    MESSAGE(Ev_MT_BLL_SetSocks5PxyCfg_Ntf)
    BODY(mt::TSocks5Cfg, )

    MESSAGE(Ev_MT_BLL_GetSocks5PxyCfg_Req)

    MESSAGE(Ev_MT_BLL_GetSocks5PxyCfg_Rsp)
    BODY(mt::TSocks5Cfg, )


    /*
    * key : emMt_Cfg_SvrLoginTactics
    */
    MESSAGE(Ev_MT_BLL_SetSvrLoginTacticsCfg_Cmd)
    BODY(mt::TMtLoginTacticsTable, )

    MESSAGE(Ev_MT_BLL_SetSvrLoginTacticsCfg_Ntf)
    BODY(mt::TMtLoginTacticsTable, )

    MESSAGE(Ev_MT_BLL_GetSvrLoginTacticsCfg_Req)

    MESSAGE(Ev_MT_BLL_GetSvrLoginTacticsCfg_Rsp)
    BODY(mt::TMtLoginTacticsTable, )


    /*
    * key : emMt_Cfg_H323
    */
    MESSAGE(Ev_MT_BLL_SetH323Cfg_Cmd)
    BODY(mt::TMtH323Cfg, )

    MESSAGE(Ev_MT_BLL_SetH323Cfg_Ntf)
    BODY(mt::TMtH323Cfg, )

    MESSAGE(Ev_MT_BLL_GetH323Cfg_Req)

    MESSAGE(Ev_MT_BLL_GetH323Cfg_Rsp)
    BODY(mt::TMtH323Cfg, )


    /*
    * key : emMt_Cfg_Sip
    */
    MESSAGE(Ev_MT_BLL_SetSipCfg_Cmd)
    BODY(mt::TMtSipCfg, )

    MESSAGE(Ev_MT_BLL_SetSipCfg_Ntf)
    BODY(mt::TMtSipCfg, )

    MESSAGE(Ev_MT_BLL_GetSipCfg_Req)

    MESSAGE(Ev_MT_BLL_GetSipCfg_Rsp)
    BODY(mt::TMtSipCfg, )


    /*
    * key : emMt_Cfg_MC
    */
    MESSAGE(Ev_MT_BLL_SetMCCfg_Cmd)
    BODY(mt::TInnerMCParam, )

    MESSAGE(Ev_MT_BLL_SetMCCfg_Ntf)
    BODY(mt::TInnerMCParam, )

    MESSAGE(Ev_MT_BLL_GetMCCfg_Req)

    MESSAGE(Ev_MT_BLL_GetMCCfg_Rsp)
    BODY(mt::TInnerMCParam, )


    /*
    * key : emMt_Cfg_AudVolIn
    */
    MESSAGE(Ev_MT_BLL_SetAudVolInCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_SetAudVolInCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_GetAudVolInCfg_Req)

    MESSAGE(Ev_MT_BLL_GetAudVolInCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_AudVolOut
    */
    MESSAGE(Ev_MT_BLL_SetAudVolOutCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_SetAudVolOutCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_GetAudVolOutCfg_Req)

    MESSAGE(Ev_MT_BLL_GetAudVolOutCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_Ans
    */
    MESSAGE(Ev_MT_BLL_SetAnsCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetAnsCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetAnsCfg_Req)

    MESSAGE(Ev_MT_BLL_GetAnsCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_Agc
    */
    MESSAGE(Ev_MT_BLL_SetAgcCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetAgcCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetAgcCfg_Req)

    MESSAGE(Ev_MT_BLL_GetAgcCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_Aec
    */
    MESSAGE(Ev_MT_BLL_SetAecCfg_Cmd)
    BODY(mt::TAdjustAecParamCfg, )

    MESSAGE(Ev_MT_BLL_SetAecCfg_Ntf)
    BODY(mt::TAdjustAecParamCfg, )

    MESSAGE(Ev_MT_BLL_GetAecCfg_Req)

    MESSAGE(Ev_MT_BLL_GetAecCfg_Rsp)
    BODY(mt::TAdjustAecParamCfg, )


    /*
    * key : emMt_Cfg_LostPktResend
    */
    MESSAGE(Ev_MT_BLL_SetLostPktResendCfg_Cmd)
    BODY(mt::TPrsParam, )

    MESSAGE(Ev_MT_BLL_SetLostPktResendCfg_Ntf)
    BODY(mt::TPrsParam, )

    MESSAGE(Ev_MT_BLL_GetLostPktResendCfg_Req)

    MESSAGE(Ev_MT_BLL_GetLostPktResendCfg_Rsp)
    BODY(mt::TPrsParam, )


    /*
    * key : emMt_Cfg_PriVidEncParam
    */
    MESSAGE(Ev_MT_BLL_SetPriVidEncParamCfg_Cmd)
    BODY(mt::TMTAllVideoEncoderParamCfg, )

    MESSAGE(Ev_MT_BLL_SetPriVidEncParamCfg_Ntf)
    BODY(mt::TMTAllVideoEncoderParamCfg, )

    MESSAGE(Ev_MT_BLL_GetPriVidEncParamCfg_Req)

    MESSAGE(Ev_MT_BLL_GetPriVidEncParamCfg_Rsp)
    BODY(mt::TMTAllVideoEncoderParamCfg, )


    /*
    * key : emMt_Cfg_AssVidEncParam
    */
    MESSAGE(Ev_MT_BLL_SetAssVidEncParamCfg_Cmd)
    BODY(mt::TMTAllVideoEncoderParamCfg, )

    MESSAGE(Ev_MT_BLL_SetAssVidEncParamCfg_Ntf)
    BODY(mt::TMTAllVideoEncoderParamCfg, )

    MESSAGE(Ev_MT_BLL_GetAssVidEncParamCfg_Req)

    MESSAGE(Ev_MT_BLL_GetAssVidEncParamCfg_Rsp)
    BODY(mt::TMTAllVideoEncoderParamCfg, )


    /*
    * key : emMt_Cfg_VideoDecParam
    */
    MESSAGE(Ev_MT_BLL_SetVideoDecParamCfg_Cmd)
    BODY(mt::TMTAllVideoDecoderParamCfg, )

    MESSAGE(Ev_MT_BLL_SetVideoDecParamCfg_Ntf)
    BODY(mt::TMTAllVideoDecoderParamCfg, )

    MESSAGE(Ev_MT_BLL_GetVideoDecParamCfg_Req)

    MESSAGE(Ev_MT_BLL_GetVideoDecParamCfg_Rsp)
    BODY(mt::TMTAllVideoDecoderParamCfg, )


    /*
    * key : emMt_Cfg_AudioPrior
    */
    MESSAGE(Ev_MT_BLL_SetAudioPriorCfg_Cmd)
    BODY(mt::TMTAudioPriorCfg, )

    MESSAGE(Ev_MT_BLL_SetAudioPriorCfg_Ntf)
    BODY(mt::TMTAudioPriorCfg, )

    MESSAGE(Ev_MT_BLL_GetAudioPriorCfg_Req)

    MESSAGE(Ev_MT_BLL_GetAudioPriorCfg_Rsp)
    BODY(mt::TMTAudioPriorCfg, )


    /*
    * key : emMt_Cfg_PriVidPrior
    */
    MESSAGE(Ev_MT_BLL_SetPriVidPriorCfg_Cmd)
    BODY(mt::TMTMainVideoPriorCfg, )

    MESSAGE(Ev_MT_BLL_SetPriVidPriorCfg_Ntf)
    BODY(mt::TMTMainVideoPriorCfg, )

    MESSAGE(Ev_MT_BLL_GetPriVidPriorCfg_Req)

    MESSAGE(Ev_MT_BLL_GetPriVidPriorCfg_Rsp)
    BODY(mt::TMTMainVideoPriorCfg, )


    /*
    * key : emMt_Cfg_PcAssVidPrior
    */
    MESSAGE(Ev_MT_BLL_SetPcAssVidPriorCfg_Cmd)
    BODY(mt::TVidPriorParam, )

    MESSAGE(Ev_MT_BLL_SetPcAssVidPriorCfg_Ntf)
    BODY(mt::TVidPriorParam, )

    MESSAGE(Ev_MT_BLL_GetPcAssVidPriorCfg_Req)

    MESSAGE(Ev_MT_BLL_GetPcAssVidPriorCfg_Rsp)
    BODY(mt::TVidPriorParam, )


    /*
    * key : emMt_Cfg_VidAssVidPrior
    */
    MESSAGE(Ev_MT_BLL_SetVidAssVidPriorCfg_Cmd)
    BODY(mt::TVidPriorParam, )

    MESSAGE(Ev_MT_BLL_SetVidAssVidPriorCfg_Ntf)
    BODY(mt::TVidPriorParam, )

    MESSAGE(Ev_MT_BLL_GetVidAssVidPriorCfg_Req)

    MESSAGE(Ev_MT_BLL_GetVidAssVidPriorCfg_Rsp)
    BODY(mt::TVidPriorParam, )


    /*
    * key : emMt_Cfg_PlayAniSoundInIdle
    */
    MESSAGE(Ev_MT_BLL_SetPlayAniSoundInIdleCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetPlayAniSoundInIdleCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetPlayAniSoundInIdleCfg_Req)

    MESSAGE(Ev_MT_BLL_GetPlayAniSoundInIdleCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_cfg_CodecVideoSrc
    */
    MESSAGE(Ev_MT_BLL_SetCodecVideoSrcCfg_Cmd)
    BODY(mt::TMTCodecVidSrcInfo, )

    MESSAGE(Ev_MT_BLL_SetCodecVideoSrcCfg_Ntf)
    BODY(mt::TMTCodecVidSrcInfo, )

    MESSAGE(Ev_MT_BLL_GetCodecVideoSrcCfg_Req)

    MESSAGE(Ev_MT_BLL_GetCodecVideoSrcCfg_Rsp)
    BODY(mt::TMTCodecVidSrcInfo, )


    /*
    * key : emMt_Cfg_ChrmanPollSchemes
    */
    MESSAGE(Ev_MT_BLL_SetChrmanPollSchemesCfg_Cmd)
    BODY(mt::TMTChrmanPollSchemeList, )

    MESSAGE(Ev_MT_BLL_SetChrmanPollSchemesCfg_Ntf)
    BODY(mt::TMTChrmanPollSchemeList, )

    MESSAGE(Ev_MT_BLL_GetChrmanPollSchemesCfg_Req)

    MESSAGE(Ev_MT_BLL_GetChrmanPollSchemesCfg_Rsp)
    BODY(mt::TMTChrmanPollSchemeList, )


    /*
    * key : emMt_Cfg_ChrmanOperate
    */
    MESSAGE(Ev_MT_BLL_SetChrmanOperateCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetChrmanOperateCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetChrmanOperateCfg_Req)

    MESSAGE(Ev_MT_BLL_GetChrmanOperateCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_ShowConfState
    */
    MESSAGE(Ev_MT_BLL_SetShowConfStateCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetShowConfStateCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetShowConfStateCfg_Req)

    MESSAGE(Ev_MT_BLL_GetShowConfStateCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_ShowConfTime
    */
    MESSAGE(Ev_MT_BLL_SetShowConfTimeCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetShowConfTimeCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetShowConfTimeCfg_Req)

    MESSAGE(Ev_MT_BLL_GetShowConfTimeCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_ShowConfName
    */
    MESSAGE(Ev_MT_BLL_SetShowConfNameCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetShowConfNameCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetShowConfNameCfg_Req)

    MESSAGE(Ev_MT_BLL_GetShowConfNameCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_ShowSystimeTime
    */
    MESSAGE(Ev_MT_BLL_SetShowSystimeTimeCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetShowSystimeTimeCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetShowSystimeTimeCfg_Req)

    MESSAGE(Ev_MT_BLL_GetShowSystimeTimeCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_ShowShortMsgInConf
    */
    MESSAGE(Ev_MT_BLL_SetShowShortMsgInConfCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetShowShortMsgInConfCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetShowShortMsgInConfCfg_Req)

    MESSAGE(Ev_MT_BLL_GetShowShortMsgInConfCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_ShowAppTips
    */
    MESSAGE(Ev_MT_BLL_SetShowAppTipsCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetShowAppTipsCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetShowAppTipsCfg_Req)

    MESSAGE(Ev_MT_BLL_GetShowAppTipsCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_StaticPic
    */
    MESSAGE(Ev_MT_BLL_SetStaticPicCfg_Cmd)
    BODY(mt::TStaticPicCfg, )

    MESSAGE(Ev_MT_BLL_SetStaticPicCfg_Ntf)
    BODY(mt::TStaticPicCfg, )

    MESSAGE(Ev_MT_BLL_GetStaticPicCfg_Req)

    MESSAGE(Ev_MT_BLL_GetStaticPicCfg_Rsp)
    BODY(mt::TStaticPicCfg, )


    /*
    * key : emMt_Cfg_Telephone
    */
    MESSAGE(Ev_MT_BLL_SetTelephoneCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetTelephoneCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetTelephoneCfg_Req)

    MESSAGE(Ev_MT_BLL_GetTelephoneCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_AutoCall
    */
    MESSAGE(Ev_MT_BLL_SetAutoCallCfg_Cmd)
    BODY(mt::TMTAutoCall, )

    MESSAGE(Ev_MT_BLL_SetAutoCallCfg_Ntf)
    BODY(mt::TMTAutoCall, )

    MESSAGE(Ev_MT_BLL_GetAutoCallCfg_Req)

    MESSAGE(Ev_MT_BLL_GetAutoCallCfg_Rsp)
    BODY(mt::TMTAutoCall, )


    /*
    * key : emMt_Cfg_FECC
    */
    MESSAGE(Ev_MT_BLL_SetFECCCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetFECCCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetFECCCfg_Req)

    MESSAGE(Ev_MT_BLL_GetFECCCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_AutoLogin
    */
    MESSAGE(Ev_MT_BLL_SetAutoLoginCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetAutoLoginCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetAutoLoginCfg_Req)

    MESSAGE(Ev_MT_BLL_GetAutoLoginCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_AsymmetricNet
    */
    MESSAGE(Ev_MT_BLL_SetAsymmetricNetCfg_Cmd)
    BODY(mt::TMtAsymmetricNetInfo, )

    MESSAGE(Ev_MT_BLL_SetAsymmetricNetCfg_Ntf)
    BODY(mt::TMtAsymmetricNetInfo, )

    MESSAGE(Ev_MT_BLL_GetAsymmetricNetCfg_Req)

    MESSAGE(Ev_MT_BLL_GetAsymmetricNetCfg_Rsp)
    BODY(mt::TMtAsymmetricNetInfo, )


    /*
    * key : emMt_Cfg_UseCallFW
    */
    MESSAGE(Ev_MT_BLL_SetUseCallFWCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetUseCallFWCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetUseCallFWCfg_Req)

    MESSAGE(Ev_MT_BLL_GetUseCallFWCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_BandWidthTest
    */
    MESSAGE(Ev_MT_BLL_SetBandWidthTestCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetBandWidthTestCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetBandWidthTestCfg_Req)

    MESSAGE(Ev_MT_BLL_GetBandWidthTestCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_MCResendParam
    */
    MESSAGE(Ev_MT_BLL_SetMCResendParamCfg_Cmd)
    BODY(mt::TMTMcRSParam, )

    MESSAGE(Ev_MT_BLL_SetMCResendParamCfg_Ntf)
    BODY(mt::TMTMcRSParam, )

    MESSAGE(Ev_MT_BLL_GetMCResendParamCfg_Req)

    MESSAGE(Ev_MT_BLL_GetMCResendParamCfg_Rsp)
    BODY(mt::TMTMcRSParam, )


    /*
    * key : emMt_Cfg_DualStramSrcAdj
    */
    MESSAGE(Ev_MT_BLL_SetDualStramSrcAdjCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetDualStramSrcAdjCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetDualStramSrcAdjCfg_Req)

    MESSAGE(Ev_MT_BLL_GetDualStramSrcAdjCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_CallProtocol
    */
    MESSAGE(Ev_MT_BLL_SetCallProtocolCfg_Cmd)
    BODY(mt::TMTCallerProtocol, )

    MESSAGE(Ev_MT_BLL_SetCallProtocolCfg_Ntf)
    BODY(mt::TMTCallerProtocol, )

    MESSAGE(Ev_MT_BLL_GetCallProtocolCfg_Req)

    MESSAGE(Ev_MT_BLL_GetCallProtocolCfg_Rsp)
    BODY(mt::TMTCallerProtocol, )


    /*
    * key : emMt_Cfg_EncryptType
    */
    MESSAGE(Ev_MT_BLL_SetEncryptTypeCfg_Cmd)
    BODY(mt::TMTEncryptType, )

    MESSAGE(Ev_MT_BLL_SetEncryptTypeCfg_Ntf)
    BODY(mt::TMTEncryptType, )

    MESSAGE(Ev_MT_BLL_GetEncryptTypeCfg_Req)

    MESSAGE(Ev_MT_BLL_GetEncryptTypeCfg_Rsp)
    BODY(mt::TMTEncryptType, )


    /*
    * key : emMt_Cfg_KeepAliveItrvl
    */
    MESSAGE(Ev_MT_BLL_SetKeepAliveItrvlCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_SetKeepAliveItrvlCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_GetKeepAliveItrvlCfg_Req)

    MESSAGE(Ev_MT_BLL_GetKeepAliveItrvlCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_FEC
    */
    MESSAGE(Ev_MT_BLL_SetFECCfg_Cmd)
    BODY(mt::TMTFecInfo, )

    MESSAGE(Ev_MT_BLL_SetFECCfg_Ntf)
    BODY(mt::TMTFecInfo, )

    MESSAGE(Ev_MT_BLL_GetFECCfg_Req)

    MESSAGE(Ev_MT_BLL_GetFECCfg_Rsp)
    BODY(mt::TMTFecInfo, )


    /*
    * key : emMt_Cfg_CallRateLv
    */
    MESSAGE(Ev_MT_BLL_SetCallRateLvCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_SetCallRateLvCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_GetCallRateLvCfg_Req)

    MESSAGE(Ev_MT_BLL_GetCallRateLvCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_VidBitRation
    */
    MESSAGE(Ev_MT_BLL_SetVidBitRationCfg_Cmd)
    BODY(mt::TVidBitRationCfg, )

    MESSAGE(Ev_MT_BLL_SetVidBitRationCfg_Ntf)
    BODY(mt::TVidBitRationCfg, )

    MESSAGE(Ev_MT_BLL_GetVidBitRationCfg_Req)

    MESSAGE(Ev_MT_BLL_GetVidBitRationCfg_Rsp)
    BODY(mt::TVidBitRationCfg, )


    /*
    * key : emMt_Cfg_TerminalName
    */
    MESSAGE(Ev_MT_BLL_SetTerminalNameCfg_Cmd)
    BODY(mt::TMtTerminalName, )

    MESSAGE(Ev_MT_BLL_SetTerminalNameCfg_Ntf)
    BODY(mt::TMtTerminalName, )

    MESSAGE(Ev_MT_BLL_GetTerminalNameCfg_Req)

    MESSAGE(Ev_MT_BLL_GetTerminalNameCfg_Rsp)
    BODY(mt::TMtTerminalName, )


    /*
    * key : emMt_Cfg_LoginPwd
    */
    MESSAGE(Ev_MT_BLL_SetLoginPwdCfg_Cmd)
    BODY(mt::TMtLoginPlatformPwdCfg, )

    MESSAGE(Ev_MT_BLL_SetLoginPwdCfg_Ntf)
    BODY(mt::TMtLoginPlatformPwdCfg, )

    MESSAGE(Ev_MT_BLL_GetLoginPwdCfg_Req)

    MESSAGE(Ev_MT_BLL_GetLoginPwdCfg_Rsp)
    BODY(mt::TMtLoginPlatformPwdCfg, )


    /*
    * key : emMt_Cfg_Email
    */
    MESSAGE(Ev_MT_BLL_SetEmailCfg_Cmd)
    BODY(mt::TString, )

    MESSAGE(Ev_MT_BLL_SetEmailCfg_Ntf)
    BODY(mt::TString, )

    MESSAGE(Ev_MT_BLL_GetEmailCfg_Req)

    MESSAGE(Ev_MT_BLL_GetEmailCfg_Rsp)
    BODY(mt::TString, )


    /*
    * key : emMt_Cfg_Port
    */
    MESSAGE(Ev_MT_BLL_SetPortCfg_Cmd)
    BODY(mt::TMTPortCfg, )

    MESSAGE(Ev_MT_BLL_SetPortCfg_Ntf)
    BODY(mt::TMTPortCfg, )

    MESSAGE(Ev_MT_BLL_GetPortCfg_Req)

    MESSAGE(Ev_MT_BLL_GetPortCfg_Rsp)
    BODY(mt::TMTPortCfg, )


    /*
    * key : emMt_Cfg_Log
    */
    MESSAGE(Ev_MT_BLL_SetLogCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetLogCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetLogCfg_Req)

    MESSAGE(Ev_MT_BLL_GetLogCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_LoginIMParam
    */
    MESSAGE(Ev_MT_BLL_SetLoginIMParamCfg_Cmd)
    BODY(mt::TImUserLogin, )

    MESSAGE(Ev_MT_BLL_SetLoginIMParamCfg_Ntf)
    BODY(mt::TImUserLogin, )

    MESSAGE(Ev_MT_BLL_GetLoginIMParamCfg_Req)

    MESSAGE(Ev_MT_BLL_GetLoginIMParamCfg_Rsp)
    BODY(mt::TImUserLogin, )


    /*
    * key : emMt_Cfg_SysCtrlDefSrvInfo
    */
    MESSAGE(Ev_MT_BLL_SetSysCtrlDefSrvInfoCfg_Cmd)
    BODY(mt::TMutiTServiceDefInfo, )

    MESSAGE(Ev_MT_BLL_SetSysCtrlDefSrvInfoCfg_Ntf)
    BODY(mt::TMutiTServiceDefInfo, )

    MESSAGE(Ev_MT_BLL_GetSysCtrlDefSrvInfoCfg_Req)

    MESSAGE(Ev_MT_BLL_GetSysCtrlDefSrvInfoCfg_Rsp)
    BODY(mt::TMutiTServiceDefInfo, )


    /*
    * key : emMt_Cfg_SysCtrlDefSrvNum
    */
    MESSAGE(Ev_MT_BLL_SetSysCtrlDefSrvNumCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_SetSysCtrlDefSrvNumCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_GetSysCtrlDefSrvNumCfg_Req)

    MESSAGE(Ev_MT_BLL_GetSysCtrlDefSrvNumCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_AnswerMode
    */
    MESSAGE(Ev_MT_BLL_SetAnswerModeCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_SetAnswerModeCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_GetAnswerModeCfg_Req)

    MESSAGE(Ev_MT_BLL_GetAnswerModeCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_CallBitrate
    */
    MESSAGE(Ev_MT_BLL_SetCallBitrateCfg_Cmd)
    BODY(mt::TMultiU32, )

    MESSAGE(Ev_MT_BLL_SetCallBitrateCfg_Ntf)
    BODY(mt::TMultiU32, )

    MESSAGE(Ev_MT_BLL_GetCallBitrateCfg_Req)

    MESSAGE(Ev_MT_BLL_GetCallBitrateCfg_Rsp)
    BODY(mt::TMultiU32, )


    /*
    * key : emMt_Cfg_AutoSendSharedContent
    */
    MESSAGE(Ev_MT_BLL_SetAutoSendSharedContentCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetAutoSendSharedContentCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetAutoSendSharedContentCfg_Req)

    MESSAGE(Ev_MT_BLL_GetAutoSendSharedContentCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_LoginPlatformSrv
    */
    MESSAGE(Ev_MT_BLL_SetLoginPlatformSrvCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetLoginPlatformSrvCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetLoginPlatformSrvCfg_Req)

    MESSAGE(Ev_MT_BLL_GetLoginPlatformSrvCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_H460
    */
    MESSAGE(Ev_MT_BLL_SetH460Cfg_Cmd)
    BODY(mt::TMtH460PxyCfg, )

    MESSAGE(Ev_MT_BLL_SetH460Cfg_Ntf)
    BODY(mt::TMtH460PxyCfg, )

    MESSAGE(Ev_MT_BLL_GetH460Cfg_Req)

    MESSAGE(Ev_MT_BLL_GetH460Cfg_Rsp)
    BODY(mt::TMtH460PxyCfg, )


    /*
    * key : emMt_Cfg_H323Pxy
    */
    MESSAGE(Ev_MT_BLL_SetH323PxyCfg_Cmd)
    BODY(mt::TMtH323PxyCfg, )

    MESSAGE(Ev_MT_BLL_SetH323PxyCfg_Ntf)
    BODY(mt::TMtH323PxyCfg, )

    MESSAGE(Ev_MT_BLL_GetH323PxyCfg_Req)

    MESSAGE(Ev_MT_BLL_GetH323PxyCfg_Rsp)
    BODY(mt::TMtH323PxyCfg, )


    /*
    * key : emMt_Cfg_SmoothSend
    */
    MESSAGE(Ev_MT_BLL_SetSmoothSendCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetSmoothSendCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetSmoothSendCfg_Req)

    MESSAGE(Ev_MT_BLL_GetSmoothSendCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_UseTelnet
    */
    MESSAGE(Ev_MT_BLL_SetUseTelnetCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetUseTelnetCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetUseTelnetCfg_Req)

    MESSAGE(Ev_MT_BLL_GetUseTelnetCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_UseHTTP
    */
    MESSAGE(Ev_MT_BLL_SetUseHTTPCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetUseHTTPCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetUseHTTPCfg_Req)

    MESSAGE(Ev_MT_BLL_GetUseHTTPCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_UseFtp
    */
    MESSAGE(Ev_MT_BLL_SetUseFtpCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetUseFtpCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetUseFtpCfg_Req)

    MESSAGE(Ev_MT_BLL_GetUseFtpCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_TelnetFtpUserInfo
    */
    MESSAGE(Ev_MT_BLL_SetTelnetFtpUserInfoCfg_Cmd)
    BODY(mt::TMTFtpTelnetAccountInfo, )

    MESSAGE(Ev_MT_BLL_SetTelnetFtpUserInfoCfg_Ntf)
    BODY(mt::TMTFtpTelnetAccountInfo, )

    MESSAGE(Ev_MT_BLL_GetTelnetFtpUserInfoCfg_Req)

    MESSAGE(Ev_MT_BLL_GetTelnetFtpUserInfoCfg_Rsp)
    BODY(mt::TMTFtpTelnetAccountInfo, )


    /*
    * key : emMt_Cfg_H264Svc
    */
    MESSAGE(Ev_MT_BLL_SetH264SvcCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetH264SvcCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetH264SvcCfg_Req)

    MESSAGE(Ev_MT_BLL_GetH264SvcCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_InnerMcAssVidCfg
    */
    MESSAGE(Ev_MT_BLL_SetInnerMcAssVidCfgCfg_Cmd)
    BODY(mt::TMTInnerMcAssVidCfg, )

    MESSAGE(Ev_MT_BLL_SetInnerMcAssVidCfgCfg_Ntf)
    BODY(mt::TMTInnerMcAssVidCfg, )

    MESSAGE(Ev_MT_BLL_GetInnerMcAssVidCfgCfg_Req)

    MESSAGE(Ev_MT_BLL_GetInnerMcAssVidCfgCfg_Rsp)
    BODY(mt::TMTInnerMcAssVidCfg, )


    /*
    * key : emMt_Cfg_ApsLoginParam
    */
    MESSAGE(Ev_MT_BLL_SetApsLoginParamCfg_Cmd)
    BODY(mt::TMtApsLoginParam, )

    MESSAGE(Ev_MT_BLL_SetApsLoginParamCfg_Ntf)
    BODY(mt::TMtApsLoginParam, )

    MESSAGE(Ev_MT_BLL_GetApsLoginParamCfg_Req)

    MESSAGE(Ev_MT_BLL_GetApsLoginParamCfg_Rsp)
    BODY(mt::TMtApsLoginParam, )


    /*
    * key : emMt_Cfg_SusLoginParam
    */
    MESSAGE(Ev_MT_BLL_SetSusLoginParamCfg_Cmd)
    BODY(mt::TMTUpgradeClientInfo, )

    MESSAGE(Ev_MT_BLL_SetSusLoginParamCfg_Ntf)
    BODY(mt::TMTUpgradeClientInfo, )

    MESSAGE(Ev_MT_BLL_GetSusLoginParamCfg_Req)

    MESSAGE(Ev_MT_BLL_GetSusLoginParamCfg_Rsp)
    BODY(mt::TMTUpgradeClientInfo, )


    /*
    * key : emMt_Cfg_NmsClientHWInfo
    */
    MESSAGE(Ev_MT_BLL_SetNmsClientHWInfoCfg_Cmd)
    BODY(mt::TNMSClientHWInfo, )

    MESSAGE(Ev_MT_BLL_SetNmsClientHWInfoCfg_Ntf)
    BODY(mt::TNMSClientHWInfo, )

    MESSAGE(Ev_MT_BLL_GetNmsClientHWInfoCfg_Req)

    MESSAGE(Ev_MT_BLL_GetNmsClientHWInfoCfg_Rsp)
    BODY(mt::TNMSClientHWInfo, )


    /*
    * key : emMt_Cfg_NewExceptionTime
    */
    MESSAGE(Ev_MT_BLL_SetNewExceptionTimeCfg_Cmd)
    BODY(mt::TString, )

    MESSAGE(Ev_MT_BLL_SetNewExceptionTimeCfg_Ntf)
    BODY(mt::TString, )

    MESSAGE(Ev_MT_BLL_GetNewExceptionTimeCfg_Req)

    MESSAGE(Ev_MT_BLL_GetNewExceptionTimeCfg_Rsp)
    BODY(mt::TString, )


    /*
    * key : emMt_Cfg_HasWizardConfiged
    */
    MESSAGE(Ev_MT_BLL_SetHasWizardConfigedCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetHasWizardConfigedCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetHasWizardConfigedCfg_Req)

    MESSAGE(Ev_MT_BLL_GetHasWizardConfigedCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_CurVidCapDev
    */
    MESSAGE(Ev_MT_BLL_SetCurVidCapDevCfg_Cmd)
    BODY(mt::TDevInfo, )

    MESSAGE(Ev_MT_BLL_SetCurVidCapDevCfg_Ntf)
    BODY(mt::TDevInfo, )

    MESSAGE(Ev_MT_BLL_GetCurVidCapDevCfg_Req)

    MESSAGE(Ev_MT_BLL_GetCurVidCapDevCfg_Rsp)
    BODY(mt::TDevInfo, )


    /*
    * key : emMt_Cfg_ServerLoginPort
    */
    MESSAGE(Ev_MT_BLL_SetServerLoginPortCfg_Cmd)
    BODY(mt::TServerLoginPort, )

    MESSAGE(Ev_MT_BLL_SetServerLoginPortCfg_Ntf)
    BODY(mt::TServerLoginPort, )

    MESSAGE(Ev_MT_BLL_GetServerLoginPortCfg_Req)

    MESSAGE(Ev_MT_BLL_GetServerLoginPortCfg_Rsp)
    BODY(mt::TServerLoginPort, )


    /*
    * key : emMt_Cfg_ConfOccupy
    */
    MESSAGE(Ev_MT_BLL_SetConfOccupyCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetConfOccupyCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetConfOccupyCfg_Req)

    MESSAGE(Ev_MT_BLL_GetConfOccupyCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_EnableHTTPS
    */
    MESSAGE(Ev_MT_BLL_SetEnableHTTPSCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetEnableHTTPSCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetEnableHTTPSCfg_Req)

    MESSAGE(Ev_MT_BLL_GetEnableHTTPSCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_MtModel
    */
    MESSAGE(Ev_MT_BLL_SetMtModelCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_SetMtModelCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_GetMtModelCfg_Req)

    MESSAGE(Ev_MT_BLL_GetMtModelCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_ShowInOutConf
    */
    MESSAGE(Ev_MT_BLL_SetShowInOutConfCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetShowInOutConfCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetShowInOutConfCfg_Req)

    MESSAGE(Ev_MT_BLL_GetShowInOutConfCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_ShowMtTime
    */
    MESSAGE(Ev_MT_BLL_SetShowMtTimeCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetShowMtTimeCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetShowMtTimeCfg_Req)

    MESSAGE(Ev_MT_BLL_GetShowMtTimeCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_LoginStrategy
    */
    MESSAGE(Ev_MT_BLL_SetLoginStrategyCfg_Cmd)
    BODY(mt::TLoginStrategy, )

    MESSAGE(Ev_MT_BLL_SetLoginStrategyCfg_Ntf)
    BODY(mt::TLoginStrategy, )

    MESSAGE(Ev_MT_BLL_GetLoginStrategyCfg_Req)

    MESSAGE(Ev_MT_BLL_GetLoginStrategyCfg_Rsp)
    BODY(mt::TLoginStrategy, )


    /*
    * key : emMt_Cfg_ShowHomeButton
    */
    MESSAGE(Ev_MT_BLL_SetShowHomeButtonCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetShowHomeButtonCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetShowHomeButtonCfg_Req)

    MESSAGE(Ev_MT_BLL_GetShowHomeButtonCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_ShowAssVidInVmp
    */
    MESSAGE(Ev_MT_BLL_SetShowAssVidInVmpCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetShowAssVidInVmpCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetShowAssVidInVmpCfg_Req)

    MESSAGE(Ev_MT_BLL_GetShowAssVidInVmpCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_IMIXCtrlOsdFunc
    */
    MESSAGE(Ev_MT_BLL_SetIMIXCtrlOsdFuncCfg_Cmd)
    BODY(mt::TMTOrder, )

    MESSAGE(Ev_MT_BLL_SetIMIXCtrlOsdFuncCfg_Ntf)
    BODY(mt::TMTOrder, )

    MESSAGE(Ev_MT_BLL_GetIMIXCtrlOsdFuncCfg_Req)

    MESSAGE(Ev_MT_BLL_GetIMIXCtrlOsdFuncCfg_Rsp)
    BODY(mt::TMTOrder, )


    /*
    * key : emMt_Cfg_HttpsCertificateType
    */
    MESSAGE(Ev_MT_BLL_SetHttpsCertificateTypeCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_SetHttpsCertificateTypeCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_GetHttpsCertificateTypeCfg_Req)

    MESSAGE(Ev_MT_BLL_GetHttpsCertificateTypeCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_VidEncQcMode
    */
    MESSAGE(Ev_MT_BLL_SetVidEncQcModeCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_SetVidEncQcModeCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_GetVidEncQcModeCfg_Req)

    MESSAGE(Ev_MT_BLL_GetVidEncQcModeCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_ShowLostPkt
    */
    MESSAGE(Ev_MT_BLL_SetShowLostPktCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetShowLostPktCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetShowLostPktCfg_Req)

    MESSAGE(Ev_MT_BLL_GetShowLostPktCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_AiInfo
    */
    MESSAGE(Ev_MT_BLL_SetAiInfoCfg_Cmd)
    BODY(mt::TMtAiInfoCfg, )

    MESSAGE(Ev_MT_BLL_SetAiInfoCfg_Ntf)
    BODY(mt::TMtAiInfoCfg, )

    MESSAGE(Ev_MT_BLL_GetAiInfoCfg_Req)

    MESSAGE(Ev_MT_BLL_GetAiInfoCfg_Rsp)
    BODY(mt::TMtAiInfoCfg, )


    /*
    * key : emMt_Cfg_UserLoginPwdTimeout
    */
    MESSAGE(Ev_MT_BLL_SetUserLoginPwdTimeoutCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_SetUserLoginPwdTimeoutCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_GetUserLoginPwdTimeoutCfg_Req)

    MESSAGE(Ev_MT_BLL_GetUserLoginPwdTimeoutCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_EnableSecure
    */
    MESSAGE(Ev_MT_BLL_SetEnableSecureCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetEnableSecureCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetEnableSecureCfg_Req)

    MESSAGE(Ev_MT_BLL_GetEnableSecureCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_ShortCutKey
    */
    MESSAGE(Ev_MT_BLL_SetShortCutKeyCfg_Cmd)
    BODY(mt::TMtShortCutKeyList, )

    MESSAGE(Ev_MT_BLL_SetShortCutKeyCfg_Ntf)
    BODY(mt::TMtShortCutKeyList, )

    MESSAGE(Ev_MT_BLL_GetShortCutKeyCfg_Req)

    MESSAGE(Ev_MT_BLL_GetShortCutKeyCfg_Rsp)
    BODY(mt::TMtShortCutKeyList, )


    /*
    * key : emMt_Cfg_AiCameraInfo
    */
    MESSAGE(Ev_MT_BLL_SetAiCameraInfoCfg_Cmd)
    BODY(mt::TMTHDCameraAiList, )

    MESSAGE(Ev_MT_BLL_SetAiCameraInfoCfg_Ntf)
    BODY(mt::TMTHDCameraAiList, )

    MESSAGE(Ev_MT_BLL_GetAiCameraInfoCfg_Req)

    MESSAGE(Ev_MT_BLL_GetAiCameraInfoCfg_Rsp)
    BODY(mt::TMTHDCameraAiList, )


    /*
    * key : emMt_Rt_CurAPS
    */
    MESSAGE(Ev_MT_BLL_SetCurAPSRt_Ntf)
    BODY(mt::TMtAPSSvrAddr, )

    MESSAGE(Ev_MT_BLL_GetCurAPSRt_Req)

    MESSAGE(Ev_MT_BLL_GetCurAPSRt_Rsp)
    BODY(mt::TMtAPSSvrAddr, )


    /*
    * key : emMt_Rt_XNU
    */
    MESSAGE(Ev_MT_BLL_SetXNURt_Ntf)
    BODY(mt::TMtXMPPInfo, )

    MESSAGE(Ev_MT_BLL_GetXNURt_Req)

    MESSAGE(Ev_MT_BLL_GetXNURt_Rsp)
    BODY(mt::TMtXMPPInfo, )


    /*
    * key : emMt_Rt_APS
    */
    MESSAGE(Ev_MT_BLL_SetAPSRt_Ntf)
    BODY(mt::TMtAPSAddrFromSrv, )

    MESSAGE(Ev_MT_BLL_GetAPSRt_Req)

    MESSAGE(Ev_MT_BLL_GetAPSRt_Rsp)
    BODY(mt::TMtAPSAddrFromSrv, )


    /*
    * key : emMt_Rt_PlatformApi
    */
    MESSAGE(Ev_MT_BLL_SetPlatformApiRt_Ntf)
    BODY(mt::TMtPlatformApiAddr, )

    MESSAGE(Ev_MT_BLL_GetPlatformApiRt_Req)

    MESSAGE(Ev_MT_BLL_GetPlatformApiRt_Rsp)
    BODY(mt::TMtPlatformApiAddr, )


    /*
    * key : emMt_Rt_MeetingCtrl
    */
    MESSAGE(Ev_MT_BLL_SetMeetingCtrlRt_Ntf)
    BODY(mt::TMtMeetingSvrAddr, )

    MESSAGE(Ev_MT_BLL_GetMeetingCtrlRt_Req)

    MESSAGE(Ev_MT_BLL_GetMeetingCtrlRt_Rsp)
    BODY(mt::TMtMeetingSvrAddr, )


    /*
    * key : emMt_Rt_MicroBlog
    */
    MESSAGE(Ev_MT_BLL_SetMicroBlogRt_Ntf)
    BODY(mt::TMtPlatformWeiboAddr, )

    MESSAGE(Ev_MT_BLL_GetMicroBlogRt_Req)

    MESSAGE(Ev_MT_BLL_GetMicroBlogRt_Rsp)
    BODY(mt::TMtPlatformWeiboAddr, )


    /*
    * key : emMt_Rt_SvrLoginStatus
    */
    MESSAGE(Ev_MT_BLL_SetSvrLoginStatusRt_Ntf)
    BODY(mt::TMtSvrStateTable, )

    MESSAGE(Ev_MT_BLL_GetSvrLoginStatusRt_Req)

    MESSAGE(Ev_MT_BLL_GetSvrLoginStatusRt_Rsp)
    BODY(mt::TMtSvrStateTable, )


    /*
    * key : emMt_Rt_UserPrevilege
    */
    MESSAGE(Ev_MT_BLL_SetUserPrevilegeRt_Ntf)
    BODY(mt::TMTUserPrevilege, )

    MESSAGE(Ev_MT_BLL_GetUserPrevilegeRt_Req)

    MESSAGE(Ev_MT_BLL_GetUserPrevilegeRt_Rsp)
    BODY(mt::TMTUserPrevilege, )


    /*
    * key : emMt_Rt_UserInfoFromAps
    */
    MESSAGE(Ev_MT_BLL_SetUserInfoFromApsRt_Ntf)
    BODY(mt::TMTUserInfoFromAps, )

    MESSAGE(Ev_MT_BLL_GetUserInfoFromApsRt_Req)

    MESSAGE(Ev_MT_BLL_GetUserInfoFromApsRt_Rsp)
    BODY(mt::TMTUserInfoFromAps, )


    /*
    * key : emMt_Rt_MCInfo
    */
    MESSAGE(Ev_MT_BLL_SetMCInfoRt_Ntf)
    BODY(mt::TInnerMCRunInfo, )

    MESSAGE(Ev_MT_BLL_GetMCInfoRt_Req)

    MESSAGE(Ev_MT_BLL_GetMCInfoRt_Rsp)
    BODY(mt::TInnerMCRunInfo, )


    /*
    * key : emMt_Rt_CallInfo
    */
    MESSAGE(Ev_MT_BLL_SetCallInfoRt_Ntf)
    BODY(mt::TMtCallLinkSate, )

    MESSAGE(Ev_MT_BLL_GetCallInfoRt_Req)

    MESSAGE(Ev_MT_BLL_GetCallInfoRt_Rsp)
    BODY(mt::TMtCallLinkSate, )


    /*
    * key : emMt_Rt_ChanInfo
    */
    MESSAGE(Ev_MT_BLL_SetChanInfoRt_Ntf)
    BODY(mt::TMutiChanDsInfo, )

    MESSAGE(Ev_MT_BLL_GetChanInfoRt_Req)

    MESSAGE(Ev_MT_BLL_GetChanInfoRt_Rsp)
    BODY(mt::TMutiChanDsInfo, )


    /*
    * key : emMt_Rt_IsSatelliteMT
    */
    MESSAGE(Ev_MT_BLL_SetIsSatelliteMTRt_Ntf)
    BODY(mt::TMTSatelliteFlag, )

    MESSAGE(Ev_MT_BLL_GetIsSatelliteMTRt_Req)

    MESSAGE(Ev_MT_BLL_GetIsSatelliteMTRt_Rsp)
    BODY(mt::TMTSatelliteFlag, )


    /*
    * key : emMt_Rt_SysUpgrade
    */
    MESSAGE(Ev_MT_BLL_SetSysUpgradeRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetSysUpgradeRt_Req)

    MESSAGE(Ev_MT_BLL_GetSysUpgradeRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Rt_ConfUsedPorts
    */
    MESSAGE(Ev_MT_BLL_SetConfUsedPortsRt_Ntf)
    BODY(mt::TMTUsedPortList, )

    MESSAGE(Ev_MT_BLL_GetConfUsedPortsRt_Req)

    MESSAGE(Ev_MT_BLL_GetConfUsedPortsRt_Rsp)
    BODY(mt::TMTUsedPortList, )


    /*
    * key : emMt_Rt_McUsedPorts
    */
    MESSAGE(Ev_MT_BLL_SetMcUsedPortsRt_Ntf)
    BODY(mt::TMTUsedPortList, )

    MESSAGE(Ev_MT_BLL_GetMcUsedPortsRt_Req)

    MESSAGE(Ev_MT_BLL_GetMcUsedPortsRt_Rsp)
    BODY(mt::TMTUsedPortList, )


    /*
    * key : emMt_Rt_VodUsedPorts
    */
    MESSAGE(Ev_MT_BLL_SetVodUsedPortsRt_Ntf)
    BODY(mt::TMTUsedPortList, )

    MESSAGE(Ev_MT_BLL_GetVodUsedPortsRt_Req)

    MESSAGE(Ev_MT_BLL_GetVodUsedPortsRt_Rsp)
    BODY(mt::TMTUsedPortList, )


    /*
    * key : emMt_Rt_ImUsedPorts
    */
    MESSAGE(Ev_MT_BLL_SetImUsedPortsRt_Ntf)
    BODY(mt::TMTUsedPortList, )

    MESSAGE(Ev_MT_BLL_GetImUsedPortsRt_Req)

    MESSAGE(Ev_MT_BLL_GetImUsedPortsRt_Rsp)
    BODY(mt::TMTUsedPortList, )


    /*
    * key : emMt_Rt_BandWidth
    */
    MESSAGE(Ev_MT_BLL_SetBandWidthRt_Ntf)
    BODY(mt::TMTNetStatus, )

    MESSAGE(Ev_MT_BLL_GetBandWidthRt_Req)

    MESSAGE(Ev_MT_BLL_GetBandWidthRt_Rsp)
    BODY(mt::TMTNetStatus, )


    /*
    * key : emMt_Rt_SysCtrlSrvInfo
    */
    MESSAGE(Ev_MT_BLL_SetSysCtrlSrvInfoRt_Ntf)
    BODY(mt::TMutiTServiceInfoRtData, )

    MESSAGE(Ev_MT_BLL_GetSysCtrlSrvInfoRt_Req)

    MESSAGE(Ev_MT_BLL_GetSysCtrlSrvInfoRt_Rsp)
    BODY(mt::TMutiTServiceInfoRtData, )


    /*
    * key : emMt_Rt_SysCtrlSrvNum
    */
    MESSAGE(Ev_MT_BLL_SetSysCtrlSrvNumRt_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_GetSysCtrlSrvNumRt_Req)

    MESSAGE(Ev_MT_BLL_GetSysCtrlSrvNumRt_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emMt_Rt_IsH323StackStand
    */
    MESSAGE(Ev_MT_BLL_SetIsH323StackStandRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetIsH323StackStandRt_Req)

    MESSAGE(Ev_MT_BLL_GetIsH323StackStandRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Rt_H323CallingPort
    */
    MESSAGE(Ev_MT_BLL_SetH323CallingPortRt_Ntf)
    BODY(mt::TU16, )

    MESSAGE(Ev_MT_BLL_GetH323CallingPortRt_Req)

    MESSAGE(Ev_MT_BLL_GetH323CallingPortRt_Rsp)
    BODY(mt::TU16, )


    /*
    * key : emMt_Rt_H323TcpBasePort
    */
    MESSAGE(Ev_MT_BLL_SetH323TcpBasePortRt_Ntf)
    BODY(mt::TU16, )

    MESSAGE(Ev_MT_BLL_GetH323TcpBasePortRt_Req)

    MESSAGE(Ev_MT_BLL_GetH323TcpBasePortRt_Rsp)
    BODY(mt::TU16, )


    /*
    * key : emMt_Rt_H323TcpEndPort
    */
    MESSAGE(Ev_MT_BLL_SetH323TcpEndPortRt_Ntf)
    BODY(mt::TU16, )

    MESSAGE(Ev_MT_BLL_GetH323TcpEndPortRt_Req)

    MESSAGE(Ev_MT_BLL_GetH323TcpEndPortRt_Rsp)
    BODY(mt::TU16, )


    /*
    * key : emMt_Rt_H323pxyBasePort
    */
    MESSAGE(Ev_MT_BLL_SetH323pxyBasePortRt_Ntf)
    BODY(mt::TU16, )

    MESSAGE(Ev_MT_BLL_GetH323pxyBasePortRt_Req)

    MESSAGE(Ev_MT_BLL_GetH323pxyBasePortRt_Rsp)
    BODY(mt::TU16, )


    /*
    * key : emMt_Rt_H323pxyEndPort
    */
    MESSAGE(Ev_MT_BLL_SetH323pxyEndPortRt_Ntf)
    BODY(mt::TU16, )

    MESSAGE(Ev_MT_BLL_GetH323pxyEndPortRt_Req)

    MESSAGE(Ev_MT_BLL_GetH323pxyEndPortRt_Rsp)
    BODY(mt::TU16, )


    /*
    * key : emMt_Rt_SipbfcpPort
    */
    MESSAGE(Ev_MT_BLL_SetSipbfcpPortRt_Ntf)
    BODY(mt::TU16, )

    MESSAGE(Ev_MT_BLL_GetSipbfcpPortRt_Req)

    MESSAGE(Ev_MT_BLL_GetSipbfcpPortRt_Rsp)
    BODY(mt::TU16, )


    /*
    * key : emMt_Rt_IsSipRigisted
    */
    MESSAGE(Ev_MT_BLL_SetIsSipRigistedRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetIsSipRigistedRt_Req)

    MESSAGE(Ev_MT_BLL_GetIsSipRigistedRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Rt_IsGkRigisted
    */
    MESSAGE(Ev_MT_BLL_SetIsGkRigistedRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetIsGkRigistedRt_Req)

    MESSAGE(Ev_MT_BLL_GetIsGkRigistedRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Rt_CameraCtrlSite
    */
    MESSAGE(Ev_MT_BLL_SetCameraCtrlSiteRt_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_GetCameraCtrlSiteRt_Req)

    MESSAGE(Ev_MT_BLL_GetCameraCtrlSiteRt_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emMt_Rt_TerlInfo
    */
    MESSAGE(Ev_MT_BLL_SetTerlInfoRt_Ntf)
    BODY(mt::TTerminalInfo, )

    MESSAGE(Ev_MT_BLL_GetTerlInfoRt_Req)

    MESSAGE(Ev_MT_BLL_GetTerlInfoRt_Rsp)
    BODY(mt::TTerminalInfo, )


    /*
    * key : emMt_Rt_NetUsedInfo
    */
    MESSAGE(Ev_MT_BLL_SetNetUsedInfoRt_Ntf)
    BODY(mt::TNetUsedInfo, )

    MESSAGE(Ev_MT_BLL_GetNetUsedInfoRt_Req)

    MESSAGE(Ev_MT_BLL_GetNetUsedInfoRt_Rsp)
    BODY(mt::TNetUsedInfo, )


    /*
    * key : emMt_Rt_CodecStatistic
    */
    MESSAGE(Ev_MT_BLL_SetCodecStatisticRt_Ntf)
    BODY(mt::TCodecStatistic, )

    MESSAGE(Ev_MT_BLL_GetCodecStatisticRt_Req)

    MESSAGE(Ev_MT_BLL_GetCodecStatisticRt_Rsp)
    BODY(mt::TCodecStatistic, )


    /*
    * key : emMt_Rt_IsMute
    */
    MESSAGE(Ev_MT_BLL_SetIsMuteRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetIsMuteRt_Req)

    MESSAGE(Ev_MT_BLL_GetIsMuteRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Rt_IsQuite
    */
    MESSAGE(Ev_MT_BLL_SetIsQuiteRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetIsQuiteRt_Req)

    MESSAGE(Ev_MT_BLL_GetIsQuiteRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Rt_TotalSndBitrate
    */
    MESSAGE(Ev_MT_BLL_SetTotalSndBitrateRt_Ntf)
    BODY(mt::TU16, )

    MESSAGE(Ev_MT_BLL_GetTotalSndBitrateRt_Req)

    MESSAGE(Ev_MT_BLL_GetTotalSndBitrateRt_Rsp)
    BODY(mt::TU16, )


    /*
    * key : emMt_Rt_TotalRcvBitrate
    */
    MESSAGE(Ev_MT_BLL_SetTotalRcvBitrateRt_Ntf)
    BODY(mt::TU16, )

    MESSAGE(Ev_MT_BLL_GetTotalRcvBitrateRt_Req)

    MESSAGE(Ev_MT_BLL_GetTotalRcvBitrateRt_Rsp)
    BODY(mt::TU16, )


    /*
    * key : emMt_Rt_VRS
    */
    MESSAGE(Ev_MT_BLL_SetVRSRt_Ntf)
    BODY(mt::TMtVRSSvrCfg, )

    MESSAGE(Ev_MT_BLL_GetVRSRt_Req)

    MESSAGE(Ev_MT_BLL_GetVRSRt_Rsp)
    BODY(mt::TMtVRSSvrCfg, )


    /*
    * key : emMt_Rt_IMHandle
    */
    MESSAGE(Ev_MT_BLL_SetIMHandleRt_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_GetIMHandleRt_Req)

    MESSAGE(Ev_MT_BLL_GetIMHandleRt_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emMt_Rt_VodPlaying
    */
    MESSAGE(Ev_MT_BLL_SetVodPlayingRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetVodPlayingRt_Req)

    MESSAGE(Ev_MT_BLL_GetVodPlayingRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Rt_IsCloudRecord
    */
    MESSAGE(Ev_MT_BLL_SetIsCloudRecordRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetIsCloudRecordRt_Req)

    MESSAGE(Ev_MT_BLL_GetIsCloudRecordRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Rt_IsVideoSignal
    */
    MESSAGE(Ev_MT_BLL_SetIsVideoSignalRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetIsVideoSignalRt_Req)

    MESSAGE(Ev_MT_BLL_GetIsVideoSignalRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Rt_IsBusiSecMt
    */
    MESSAGE(Ev_MT_BLL_SetIsBusiSecMtRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetIsBusiSecMtRt_Req)

    MESSAGE(Ev_MT_BLL_GetIsBusiSecMtRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Rt_IsBusiSecSoftMt
    */
    MESSAGE(Ev_MT_BLL_SetIsBusiSecSoftMtRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetIsBusiSecSoftMtRt_Req)

    MESSAGE(Ev_MT_BLL_GetIsBusiSecSoftMtRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Rt_IsValidDevLicense
    */
    MESSAGE(Ev_MT_BLL_SetIsValidDevLicenseRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetIsValidDevLicenseRt_Req)

    MESSAGE(Ev_MT_BLL_GetIsValidDevLicenseRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Rt_PlatformType
    */
    MESSAGE(Ev_MT_BLL_SetPlatformTypeRt_Ntf)
    BODY(mt::TPlatformType, )

    MESSAGE(Ev_MT_BLL_GetPlatformTypeRt_Req)

    MESSAGE(Ev_MT_BLL_GetPlatformTypeRt_Rsp)
    BODY(mt::TPlatformType, )


    /*
    * key : emMt_Rt_IsIMIXTerl
    */
    MESSAGE(Ev_MT_BLL_SetIsIMIXTerlRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetIsIMIXTerlRt_Req)

    MESSAGE(Ev_MT_BLL_GetIsIMIXTerlRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Rt_ChannelLicense
    */
    MESSAGE(Ev_MT_BLL_SetChannelLicenseRt_Ntf)
    BODY(mt::TLicense, )

    MESSAGE(Ev_MT_BLL_GetChannelLicenseRt_Req)

    MESSAGE(Ev_MT_BLL_GetChannelLicenseRt_Rsp)
    BODY(mt::TLicense, )


    /*
    * key : emMt_Rt_AgentInfo
    */
    MESSAGE(Ev_MT_BLL_SetAgentInfoRt_Ntf)
    BODY(mt::TMTAgentInfo, )

    MESSAGE(Ev_MT_BLL_GetAgentInfoRt_Req)

    MESSAGE(Ev_MT_BLL_GetAgentInfoRt_Rsp)
    BODY(mt::TMTAgentInfo, )


    /*
    * key : emMt_Rt_HwChipInfo
    */
    MESSAGE(Ev_MT_BLL_SetHwChipInfoRt_Ntf)
    BODY(mt::TMtHwChipInfoList, )

    MESSAGE(Ev_MT_BLL_GetHwChipInfoRt_Req)

    MESSAGE(Ev_MT_BLL_GetHwChipInfoRt_Rsp)
    BODY(mt::TMtHwChipInfoList, )


    /*
    * key : emMt_Rt_NS
    */
    MESSAGE(Ev_MT_BLL_SetNSRt_Ntf)
    BODY(mt::TMtNSAddr, )

    MESSAGE(Ev_MT_BLL_GetNSRt_Req)

    MESSAGE(Ev_MT_BLL_GetNSRt_Rsp)
    BODY(mt::TMtNSAddr, )


    /*
    * key : emMt_Rt_EncryptType
    */
    MESSAGE(Ev_MT_BLL_SetEncryptTypeRt_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_GetEncryptTypeRt_Req)

    MESSAGE(Ev_MT_BLL_GetEncryptTypeRt_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emMt_Rt_LocalMtId
    */
    MESSAGE(Ev_MT_BLL_SetLocalMtIdRt_Ntf)
    BODY(mt::TMtId, )

    MESSAGE(Ev_MT_BLL_GetLocalMtIdRt_Req)

    MESSAGE(Ev_MT_BLL_GetLocalMtIdRt_Rsp)
    BODY(mt::TMtId, )


    /*
    * key : emMt_Rt_IsSelectView
    */
    MESSAGE(Ev_MT_BLL_SetIsSelectViewRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetIsSelectViewRt_Req)

    MESSAGE(Ev_MT_BLL_GetIsSelectViewRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Rt_ShareContactInfo
    */
    MESSAGE(Ev_MT_BLL_SetShareContactInfoRt_Ntf)
    BODY(mt::TMTAddressBooks, )

    MESSAGE(Ev_MT_BLL_GetShareContactInfoRt_Req)

    MESSAGE(Ev_MT_BLL_GetShareContactInfoRt_Rsp)
    BODY(mt::TMTAddressBooks, )


    /*
    * key : emMt_Rt_LocalContactInfo
    */
    MESSAGE(Ev_MT_BLL_SetLocalContactInfoRt_Ntf)
    BODY(mt::TAddrBookRosterList, )

    MESSAGE(Ev_MT_BLL_GetLocalContactInfoRt_Req)

    MESSAGE(Ev_MT_BLL_GetLocalContactInfoRt_Rsp)
    BODY(mt::TAddrBookRosterList, )


    /*
    * key : emMt_Rt_JoinConfListInfo
    */
    MESSAGE(Ev_MT_BLL_SetJoinConfListInfoRt_Ntf)
    BODY(mt::TMtJoinConfParamList, )

    MESSAGE(Ev_MT_BLL_GetJoinConfListInfoRt_Req)

    MESSAGE(Ev_MT_BLL_GetJoinConfListInfoRt_Rsp)
    BODY(mt::TMtJoinConfParamList, )


    /*
    * key : emMt_Rt_OnLineTerListInfo
    */
    MESSAGE(Ev_MT_BLL_SetOnLineTerListInfoRt_Ntf)
    BODY(mt::TRpMtInfo, )

    MESSAGE(Ev_MT_BLL_GetOnLineTerListInfoRt_Req)

    MESSAGE(Ev_MT_BLL_GetOnLineTerListInfoRt_Rsp)
    BODY(mt::TRpMtInfo, )


    /*
    * key : emHD_Cfg_ShortMsg
    */
    MESSAGE(Ev_MT_BLL_HD_SetShortMsgCfg_Cmd)
    BODY(mt::TMTShortMsgCfg, )

    MESSAGE(Ev_MT_BLL_HD_SetShortMsgCfg_Ntf)
    BODY(mt::TMTShortMsgCfg, )

    MESSAGE(Ev_MT_BLL_HD_GetShortMsgCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetShortMsgCfg_Rsp)
    BODY(mt::TMTShortMsgCfg, )


    /*
    * key : emHD_Cfg_DispMode
    */
    MESSAGE(Ev_MT_BLL_HD_SetDispModeCfg_Cmd)
    BODY(mt::TMTVideoShowMode, )

    MESSAGE(Ev_MT_BLL_HD_SetDispModeCfg_Ntf)
    BODY(mt::TMTVideoShowMode, )

    MESSAGE(Ev_MT_BLL_HD_GetDispModeCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetDispModeCfg_Rsp)
    BODY(mt::TMTVideoShowMode, )


    /*
    * key : emHD_Cfg_HDResOutput
    */
    MESSAGE(Ev_MT_BLL_HD_SetHDResOutputCfg_Cmd)
    BODY(mt::TMTVideoOutPortMode, )

    MESSAGE(Ev_MT_BLL_HD_SetHDResOutputCfg_Ntf)
    BODY(mt::TMTVideoOutPortMode, )

    MESSAGE(Ev_MT_BLL_HD_GetHDResOutputCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetHDResOutputCfg_Rsp)
    BODY(mt::TMTVideoOutPortMode, )


    /*
    * key : emHD_Cfg_AutoPIP
    */
    MESSAGE(Ev_MT_BLL_HD_SetAutoPIPCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_SetAutoPIPCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetAutoPIPCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetAutoPIPCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Cfg_CallInRing
    */
    MESSAGE(Ev_MT_BLL_HD_SetCallInRingCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_SetCallInRingCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_GetCallInRingCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCallInRingCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emHD_Cfg_CallOutRing
    */
    MESSAGE(Ev_MT_BLL_HD_SetCallOutRingCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_SetCallOutRingCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_GetCallOutRingCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCallOutRingCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emHD_Cfg_KeyboardRing
    */
    MESSAGE(Ev_MT_BLL_HD_SetKeyboardRingCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_SetKeyboardRingCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_GetKeyboardRingCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetKeyboardRingCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emHD_Cfg_EnablePresetBanner
    */
    MESSAGE(Ev_MT_BLL_HD_SetEnablePresetBannerCfg_Cmd)
    BODY(mt::TMTEnablePresetBanner, )

    MESSAGE(Ev_MT_BLL_HD_SetEnablePresetBannerCfg_Ntf)
    BODY(mt::TMTEnablePresetBanner, )

    MESSAGE(Ev_MT_BLL_HD_GetEnablePresetBannerCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetEnablePresetBannerCfg_Rsp)
    BODY(mt::TMTEnablePresetBanner, )


    /*
    * key : emHD_Cfg_MtcBannerInfo
    */
    MESSAGE(Ev_MT_BLL_HD_SetMtcBannerInfoCfg_Cmd)
    BODY(mt::TMTBannerInfoList, )

    MESSAGE(Ev_MT_BLL_HD_SetMtcBannerInfoCfg_Ntf)
    BODY(mt::TMTBannerInfoList, )

    MESSAGE(Ev_MT_BLL_HD_GetMtcBannerInfoCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetMtcBannerInfoCfg_Rsp)
    BODY(mt::TMTBannerInfoList, )


    /*
    * key : emHD_Cfg_OsdBannerInfo
    */
    MESSAGE(Ev_MT_BLL_HD_SetOsdBannerInfoCfg_Cmd)
    BODY(mt::TMTBannerInfo, )

    MESSAGE(Ev_MT_BLL_HD_SetOsdBannerInfoCfg_Ntf)
    BODY(mt::TMTBannerInfo, )

    MESSAGE(Ev_MT_BLL_HD_GetOsdBannerInfoCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetOsdBannerInfoCfg_Rsp)
    BODY(mt::TMTBannerInfo, )


    /*
    * key : emHD_Cfg_LabelInfo
    */
    MESSAGE(Ev_MT_BLL_HD_SetLabelInfoCfg_Cmd)
    BODY(mt::TMTLabelInfo, )

    MESSAGE(Ev_MT_BLL_HD_SetLabelInfoCfg_Ntf)
    BODY(mt::TMTLabelInfo, )

    MESSAGE(Ev_MT_BLL_HD_GetLabelInfoCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetLabelInfoCfg_Rsp)
    BODY(mt::TMTLabelInfo, )


    /*
    * key : emHD_Cfg_AutoSleep
    */
    MESSAGE(Ev_MT_BLL_HD_SetAutoSleepCfg_Cmd)
    BODY(mt::TMTAutoSleep, )

    MESSAGE(Ev_MT_BLL_HD_SetAutoSleepCfg_Ntf)
    BODY(mt::TMTAutoSleep, )

    MESSAGE(Ev_MT_BLL_HD_GetAutoSleepCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetAutoSleepCfg_Rsp)
    BODY(mt::TMTAutoSleep, )


    /*
    * key : emHD_Cfg_SysTime
    */
    MESSAGE(Ev_MT_BLL_HD_SetSysTimeCfg_Cmd)
    BODY(mt::TMTCfgSystemTime, )

    MESSAGE(Ev_MT_BLL_HD_SetSysTimeCfg_Ntf)
    BODY(mt::TMTCfgSystemTime, )

    MESSAGE(Ev_MT_BLL_HD_GetSysTimeCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetSysTimeCfg_Rsp)
    BODY(mt::TMTCfgSystemTime, )


    /*
    * key : emHD_Cfg_MicGain
    */
    MESSAGE(Ev_MT_BLL_HD_SetMicGainCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_SetMicGainCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_GetMicGainCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetMicGainCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emHD_Cfg_AecDebug
    */
    MESSAGE(Ev_MT_BLL_HD_SetAecDebugCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_SetAecDebugCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_GetAecDebugCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetAecDebugCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emHD_Cfg_AudInPortList
    */
    MESSAGE(Ev_MT_BLL_HD_SetAudInPortListCfg_Cmd)
    BODY(mt::TMTHDAudInPortList, )

    MESSAGE(Ev_MT_BLL_HD_SetAudInPortListCfg_Ntf)
    BODY(mt::TMTHDAudInPortList, )

    MESSAGE(Ev_MT_BLL_HD_GetAudInPortListCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetAudInPortListCfg_Rsp)
    BODY(mt::TMTHDAudInPortList, )


    /*
    * key : emHD_Cfg_AudOutPortList
    */
    MESSAGE(Ev_MT_BLL_HD_SetAudOutPortListCfg_Cmd)
    BODY(mt::TMTHDAudOutPortList, )

    MESSAGE(Ev_MT_BLL_HD_SetAudOutPortListCfg_Ntf)
    BODY(mt::TMTHDAudOutPortList, )

    MESSAGE(Ev_MT_BLL_HD_GetAudOutPortListCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetAudOutPortListCfg_Rsp)
    BODY(mt::TMTHDAudOutPortList, )


    /*
    * key : emHD_Cfg_Pri1stVidInPort
    */
    MESSAGE(Ev_MT_BLL_HD_SetPri1stVidInPortCfg_Cmd)
    BODY(mt::TMTHDVidInPort, )

    MESSAGE(Ev_MT_BLL_HD_SetPri1stVidInPortCfg_Ntf)
    BODY(mt::TMTHDVidInPort, )

    MESSAGE(Ev_MT_BLL_HD_GetPri1stVidInPortCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetPri1stVidInPortCfg_Rsp)
    BODY(mt::TMTHDVidInPort, )


    /*
    * key : emHD_Cfg_Pri2ndVidInPort
    */
    MESSAGE(Ev_MT_BLL_HD_SetPri2ndVidInPortCfg_Cmd)
    BODY(mt::TMTHDVidInPort, )

    MESSAGE(Ev_MT_BLL_HD_SetPri2ndVidInPortCfg_Ntf)
    BODY(mt::TMTHDVidInPort, )

    MESSAGE(Ev_MT_BLL_HD_GetPri2ndVidInPortCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetPri2ndVidInPortCfg_Rsp)
    BODY(mt::TMTHDVidInPort, )


    /*
    * key : emHD_Cfg_Pri3rdVidInPort
    */
    MESSAGE(Ev_MT_BLL_HD_SetPri3rdVidInPortCfg_Cmd)
    BODY(mt::TMTHDVidInPort, )

    MESSAGE(Ev_MT_BLL_HD_SetPri3rdVidInPortCfg_Ntf)
    BODY(mt::TMTHDVidInPort, )

    MESSAGE(Ev_MT_BLL_HD_GetPri3rdVidInPortCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetPri3rdVidInPortCfg_Rsp)
    BODY(mt::TMTHDVidInPort, )


    /*
    * key : emHD_Cfg_AssVidInPort
    */
    MESSAGE(Ev_MT_BLL_HD_SetAssVidInPortCfg_Cmd)
    BODY(mt::TMTHDVidInPort, )

    MESSAGE(Ev_MT_BLL_HD_SetAssVidInPortCfg_Ntf)
    BODY(mt::TMTHDVidInPort, )

    MESSAGE(Ev_MT_BLL_HD_GetAssVidInPortCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetAssVidInPortCfg_Rsp)
    BODY(mt::TMTHDVidInPort, )


    /*
    * key : emHD_Cfg_MultiVideo
    */
    MESSAGE(Ev_MT_BLL_HD_SetMultiVideoCfg_Cmd)
    BODY(mt::TMTHDMultiVideo, )

    MESSAGE(Ev_MT_BLL_HD_SetMultiVideoCfg_Ntf)
    BODY(mt::TMTHDMultiVideo, )

    MESSAGE(Ev_MT_BLL_HD_GetMultiVideoCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetMultiVideoCfg_Rsp)
    BODY(mt::TMTHDMultiVideo, )


    /*
    * key : emHD_Cfg_VideoMatrixScheme
    */
    MESSAGE(Ev_MT_BLL_HD_SetVideoMatrixSchemeCfg_Cmd)
    BODY(mt::TMTAllVideoMatrixScheme, )

    MESSAGE(Ev_MT_BLL_HD_SetVideoMatrixSchemeCfg_Ntf)
    BODY(mt::TMTAllVideoMatrixScheme, )

    MESSAGE(Ev_MT_BLL_HD_GetVideoMatrixSchemeCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetVideoMatrixSchemeCfg_Rsp)
    BODY(mt::TMTAllVideoMatrixScheme, )


    /*
    * key : emHD_Cfg_LastDisplay
    */
    MESSAGE(Ev_MT_BLL_HD_SetLastDisplayCfg_Cmd)
    BODY(mt::TMTLastDisplay, )

    MESSAGE(Ev_MT_BLL_HD_SetLastDisplayCfg_Ntf)
    BODY(mt::TMTLastDisplay, )

    MESSAGE(Ev_MT_BLL_HD_GetLastDisplayCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetLastDisplayCfg_Rsp)
    BODY(mt::TMTLastDisplay, )


    /*
    * key : emHD_Cfg_ImageNoiseLevel
    */
    MESSAGE(Ev_MT_BLL_HD_SetImageNoiseLevelCfg_Cmd)
    BODY(mt::TMTHDImageNoise, )

    MESSAGE(Ev_MT_BLL_HD_SetImageNoiseLevelCfg_Ntf)
    BODY(mt::TMTHDImageNoise, )

    MESSAGE(Ev_MT_BLL_HD_GetImageNoiseLevelCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetImageNoiseLevelCfg_Rsp)
    BODY(mt::TMTHDImageNoise, )


    /*
    * key : emHD_Cfg_ImageEnhancement
    */
    MESSAGE(Ev_MT_BLL_HD_SetImageEnhancementCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_SetImageEnhancementCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetImageEnhancementCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetImageEnhancementCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Cfg_Pri1stDeformationTensile
    */
    MESSAGE(Ev_MT_BLL_HD_SetPri1stDeformationTensileCfg_Cmd)
    BODY(mt::TMTHDImageDeformationTensile, )

    MESSAGE(Ev_MT_BLL_HD_SetPri1stDeformationTensileCfg_Ntf)
    BODY(mt::TMTHDImageDeformationTensile, )

    MESSAGE(Ev_MT_BLL_HD_GetPri1stDeformationTensileCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetPri1stDeformationTensileCfg_Rsp)
    BODY(mt::TMTHDImageDeformationTensile, )


    /*
    * key : emHD_Cfg_Pri2ndDeformationTensile
    */
    MESSAGE(Ev_MT_BLL_HD_SetPri2ndDeformationTensileCfg_Cmd)
    BODY(mt::TMTHDImageDeformationTensile, )

    MESSAGE(Ev_MT_BLL_HD_SetPri2ndDeformationTensileCfg_Ntf)
    BODY(mt::TMTHDImageDeformationTensile, )

    MESSAGE(Ev_MT_BLL_HD_GetPri2ndDeformationTensileCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetPri2ndDeformationTensileCfg_Rsp)
    BODY(mt::TMTHDImageDeformationTensile, )


    /*
    * key : emHD_Cfg_AssDeformationTensile
    */
    MESSAGE(Ev_MT_BLL_HD_SetAssDeformationTensileCfg_Cmd)
    BODY(mt::TMTHDImageDeformationTensile, )

    MESSAGE(Ev_MT_BLL_HD_SetAssDeformationTensileCfg_Ntf)
    BODY(mt::TMTHDImageDeformationTensile, )

    MESSAGE(Ev_MT_BLL_HD_GetAssDeformationTensileCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetAssDeformationTensileCfg_Rsp)
    BODY(mt::TMTHDImageDeformationTensile, )


    /*
    * key : emHD_Cfg_Pri1stGeometricScaling
    */
    MESSAGE(Ev_MT_BLL_HD_SetPri1stGeometricScalingCfg_Cmd)
    BODY(mt::TMTHDImageGeometricScaling, )

    MESSAGE(Ev_MT_BLL_HD_SetPri1stGeometricScalingCfg_Ntf)
    BODY(mt::TMTHDImageGeometricScaling, )

    MESSAGE(Ev_MT_BLL_HD_GetPri1stGeometricScalingCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetPri1stGeometricScalingCfg_Rsp)
    BODY(mt::TMTHDImageGeometricScaling, )


    /*
    * key : emHD_Cfg_Pri2ndGeometricScaling
    */
    MESSAGE(Ev_MT_BLL_HD_SetPri2ndGeometricScalingCfg_Cmd)
    BODY(mt::TMTHDImageGeometricScaling, )

    MESSAGE(Ev_MT_BLL_HD_SetPri2ndGeometricScalingCfg_Ntf)
    BODY(mt::TMTHDImageGeometricScaling, )

    MESSAGE(Ev_MT_BLL_HD_GetPri2ndGeometricScalingCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetPri2ndGeometricScalingCfg_Rsp)
    BODY(mt::TMTHDImageGeometricScaling, )


    /*
    * key : emHD_Cfg_Pri3rdGeometricScaling
    */
    MESSAGE(Ev_MT_BLL_HD_SetPri3rdGeometricScalingCfg_Cmd)
    BODY(mt::TMTHDImageGeometricScaling, )

    MESSAGE(Ev_MT_BLL_HD_SetPri3rdGeometricScalingCfg_Ntf)
    BODY(mt::TMTHDImageGeometricScaling, )

    MESSAGE(Ev_MT_BLL_HD_GetPri3rdGeometricScalingCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetPri3rdGeometricScalingCfg_Rsp)
    BODY(mt::TMTHDImageGeometricScaling, )


    /*
    * key : emHD_Cfg_AssGeometricScaling
    */
    MESSAGE(Ev_MT_BLL_HD_SetAssGeometricScalingCfg_Cmd)
    BODY(mt::TMTHDImageGeometricScaling, )

    MESSAGE(Ev_MT_BLL_HD_SetAssGeometricScalingCfg_Ntf)
    BODY(mt::TMTHDImageGeometricScaling, )

    MESSAGE(Ev_MT_BLL_HD_GetAssGeometricScalingCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetAssGeometricScalingCfg_Rsp)
    BODY(mt::TMTHDImageGeometricScaling, )


    /*
    * key : emHD_Cfg_EdgePixel
    */
    MESSAGE(Ev_MT_BLL_HD_SetEdgePixelCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_SetEdgePixelCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_GetEdgePixelCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetEdgePixelCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emHD_Cfg_CameraList
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraListCfg_Cmd)
    BODY(mt::TMTHDCameraList, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraListCfg_Ntf)
    BODY(mt::TMTHDCameraList, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraListCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraListCfg_Rsp)
    BODY(mt::TMTHDCameraList, )


    /*
    * key : emHD_Cfg_CameraAiList
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraAiListCfg_Cmd)
    BODY(mt::TMTHDCameraAiList, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraAiListCfg_Ntf)
    BODY(mt::TMTHDCameraAiList, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraAiListCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraAiListCfg_Rsp)
    BODY(mt::TMTHDCameraAiList, )


    /*
    * key : emHD_Cfg_SerialCtrl
    */
    MESSAGE(Ev_MT_BLL_HD_SetSerialCtrlCfg_Cmd)
    BODY(mt::TMTHDSerialCtrl, )

    MESSAGE(Ev_MT_BLL_HD_SetSerialCtrlCfg_Ntf)
    BODY(mt::TMTHDSerialCtrl, )

    MESSAGE(Ev_MT_BLL_HD_GetSerialCtrlCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetSerialCtrlCfg_Rsp)
    BODY(mt::TMTHDSerialCtrl, )


    /*
    * key : emHD_Cfg_SerialList
    */
    MESSAGE(Ev_MT_BLL_HD_SetSerialListCfg_Cmd)
    BODY(mt::TMTHDSerialList, )

    MESSAGE(Ev_MT_BLL_HD_SetSerialListCfg_Ntf)
    BODY(mt::TMTHDSerialList, )

    MESSAGE(Ev_MT_BLL_HD_GetSerialListCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetSerialListCfg_Rsp)
    BODY(mt::TMTHDSerialList, )


    /*
    * key : emHD_Cfg_SerialMonitorList
    */
    MESSAGE(Ev_MT_BLL_HD_SetSerialMonitorListCfg_Cmd)
    BODY(mt::TMTHDSerialMonitorList, )

    MESSAGE(Ev_MT_BLL_HD_SetSerialMonitorListCfg_Ntf)
    BODY(mt::TMTHDSerialMonitorList, )

    MESSAGE(Ev_MT_BLL_HD_GetSerialMonitorListCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetSerialMonitorListCfg_Rsp)
    BODY(mt::TMTHDSerialMonitorList, )


    /*
    * key : emHD_Cfg_VGAImageAdjust
    */
    MESSAGE(Ev_MT_BLL_HD_SetVGAImageAdjustCfg_Cmd)
    BODY(mt::TMTVgaImageAdjustCfg, )

    MESSAGE(Ev_MT_BLL_HD_SetVGAImageAdjustCfg_Ntf)
    BODY(mt::TMTVgaImageAdjustCfg, )

    MESSAGE(Ev_MT_BLL_HD_GetVGAImageAdjustCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetVGAImageAdjustCfg_Rsp)
    BODY(mt::TMTVgaImageAdjustCfg, )


    /*
    * key : emHD_Cfg_VGAImageOutAdjust
    */
    MESSAGE(Ev_MT_BLL_HD_SetVGAImageOutAdjustCfg_Cmd)
    BODY(mt::TMTVgaImageOutAdjustCfg, )

    MESSAGE(Ev_MT_BLL_HD_SetVGAImageOutAdjustCfg_Ntf)
    BODY(mt::TMTVgaImageOutAdjustCfg, )

    MESSAGE(Ev_MT_BLL_HD_GetVGAImageOutAdjustCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetVGAImageOutAdjustCfg_Rsp)
    BODY(mt::TMTVgaImageOutAdjustCfg, )


    /*
    * key : emHD_Cfg_VideoSrcTag
    */
    MESSAGE(Ev_MT_BLL_HD_SetVideoSrcTagCfg_Cmd)
    BODY(mt::TMTVideoSrcTagList, )

    MESSAGE(Ev_MT_BLL_HD_SetVideoSrcTagCfg_Ntf)
    BODY(mt::TMTVideoSrcTagList, )

    MESSAGE(Ev_MT_BLL_HD_GetVideoSrcTagCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetVideoSrcTagCfg_Rsp)
    BODY(mt::TMTVideoSrcTagList, )


    /*
    * key : emHD_Cfg_VideoOutTag
    */
    MESSAGE(Ev_MT_BLL_HD_SetVideoOutTagCfg_Cmd)
    BODY(mt::TMTVideoOutTagList, )

    MESSAGE(Ev_MT_BLL_HD_SetVideoOutTagCfg_Ntf)
    BODY(mt::TMTVideoOutTagList, )

    MESSAGE(Ev_MT_BLL_HD_GetVideoOutTagCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetVideoOutTagCfg_Rsp)
    BODY(mt::TMTVideoOutTagList, )


    /*
    * key : emHD_Cfg_SnapShotFtpCfg
    */
    MESSAGE(Ev_MT_BLL_HD_SetSnapShotFtpCfgCfg_Cmd)
    BODY(mt::TMTSnapShotFtpCfg, )

    MESSAGE(Ev_MT_BLL_HD_SetSnapShotFtpCfgCfg_Ntf)
    BODY(mt::TMTSnapShotFtpCfg, )

    MESSAGE(Ev_MT_BLL_HD_GetSnapShotFtpCfgCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetSnapShotFtpCfgCfg_Rsp)
    BODY(mt::TMTSnapShotFtpCfg, )


    /*
    * key : emHD_Cfg_PresetNameInfo
    */
    MESSAGE(Ev_MT_BLL_HD_SetPresetNameInfoCfg_Cmd)
    BODY(mt::TMTAllPreSetNameInfoCfg, )

    MESSAGE(Ev_MT_BLL_HD_SetPresetNameInfoCfg_Ntf)
    BODY(mt::TMTAllPreSetNameInfoCfg, )

    MESSAGE(Ev_MT_BLL_HD_GetPresetNameInfoCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetPresetNameInfoCfg_Rsp)
    BODY(mt::TMTAllPreSetNameInfoCfg, )


    /*
    * key : emHD_Cfg_MainFstDisplayRatio
    */
    MESSAGE(Ev_MT_BLL_HD_SetMainFstDisplayRatioCfg_Cmd)
    BODY(mt::TMTDisplayRatio, )

    MESSAGE(Ev_MT_BLL_HD_SetMainFstDisplayRatioCfg_Ntf)
    BODY(mt::TMTDisplayRatio, )

    MESSAGE(Ev_MT_BLL_HD_GetMainFstDisplayRatioCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetMainFstDisplayRatioCfg_Rsp)
    BODY(mt::TMTDisplayRatio, )


    /*
    * key : emHD_Cfg_MainSecDisplayRatio
    */
    MESSAGE(Ev_MT_BLL_HD_SetMainSecDisplayRatioCfg_Cmd)
    BODY(mt::TMTDisplayRatio, )

    MESSAGE(Ev_MT_BLL_HD_SetMainSecDisplayRatioCfg_Ntf)
    BODY(mt::TMTDisplayRatio, )

    MESSAGE(Ev_MT_BLL_HD_GetMainSecDisplayRatioCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetMainSecDisplayRatioCfg_Rsp)
    BODY(mt::TMTDisplayRatio, )


    /*
    * key : emHD_Cfg_MainTrdDisplayRatio
    */
    MESSAGE(Ev_MT_BLL_HD_SetMainTrdDisplayRatioCfg_Cmd)
    BODY(mt::TMTDisplayRatio, )

    MESSAGE(Ev_MT_BLL_HD_SetMainTrdDisplayRatioCfg_Ntf)
    BODY(mt::TMTDisplayRatio, )

    MESSAGE(Ev_MT_BLL_HD_GetMainTrdDisplayRatioCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetMainTrdDisplayRatioCfg_Rsp)
    BODY(mt::TMTDisplayRatio, )


    /*
    * key : emHD_Cfg_AssDisplayRatio
    */
    MESSAGE(Ev_MT_BLL_HD_SetAssDisplayRatioCfg_Cmd)
    BODY(mt::TMTDisplayRatio, )

    MESSAGE(Ev_MT_BLL_HD_SetAssDisplayRatioCfg_Ntf)
    BODY(mt::TMTDisplayRatio, )

    MESSAGE(Ev_MT_BLL_HD_GetAssDisplayRatioCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetAssDisplayRatioCfg_Rsp)
    BODY(mt::TMTDisplayRatio, )


    /*
    * key : emHD_Cfg_VgaOutBright
    */
    MESSAGE(Ev_MT_BLL_HD_SetVgaOutBrightCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_SetVgaOutBrightCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_GetVgaOutBrightCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetVgaOutBrightCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emHD_Cfg_VgaOutContrast
    */
    MESSAGE(Ev_MT_BLL_HD_SetVgaOutContrastCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_SetVgaOutContrastCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_GetVgaOutContrastCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetVgaOutContrastCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emHD_Cfg_VgaOutSaturation
    */
    MESSAGE(Ev_MT_BLL_HD_SetVgaOutSaturationCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_SetVgaOutSaturationCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_GetVgaOutSaturationCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetVgaOutSaturationCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emHD_Cfg_EthWorkModeList
    */
    MESSAGE(Ev_MT_BLL_HD_SetEthWorkModeListCfg_Cmd)
    BODY(mt::TEthnetWorkModeList, )

    MESSAGE(Ev_MT_BLL_HD_SetEthWorkModeListCfg_Ntf)
    BODY(mt::TEthnetWorkModeList, )

    MESSAGE(Ev_MT_BLL_HD_GetEthWorkModeListCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetEthWorkModeListCfg_Rsp)
    BODY(mt::TEthnetWorkModeList, )


    /*
    * key : emHD_Cfg_EthnetCfg
    */
    MESSAGE(Ev_MT_BLL_HD_SetEthnetCfgCfg_Cmd)
    BODY(mt::TEthnetCfg, )

    MESSAGE(Ev_MT_BLL_HD_SetEthnetCfgCfg_Ntf)
    BODY(mt::TEthnetCfg, )

    MESSAGE(Ev_MT_BLL_HD_GetEthnetCfgCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetEthnetCfgCfg_Rsp)
    BODY(mt::TEthnetCfg, )


    /*
    * key : emHD_Cfg_EthPPPoECfg
    */
    MESSAGE(Ev_MT_BLL_HD_SetEthPPPoECfgCfg_Cmd)
    BODY(mt::TEthnetPPPoECfg, )

    MESSAGE(Ev_MT_BLL_HD_SetEthPPPoECfgCfg_Ntf)
    BODY(mt::TEthnetPPPoECfg, )

    MESSAGE(Ev_MT_BLL_HD_GetEthPPPoECfgCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetEthPPPoECfgCfg_Rsp)
    BODY(mt::TEthnetPPPoECfg, )


    /*
    * key : emHD_Cfg_WifiWorkMode
    */
    MESSAGE(Ev_MT_BLL_HD_SetWifiWorkModeCfg_Cmd)
    BODY(mt::TWifiWorkMode, )

    MESSAGE(Ev_MT_BLL_HD_SetWifiWorkModeCfg_Ntf)
    BODY(mt::TWifiWorkMode, )

    MESSAGE(Ev_MT_BLL_HD_GetWifiWorkModeCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetWifiWorkModeCfg_Rsp)
    BODY(mt::TWifiWorkMode, )


    /*
    * key : emHD_Cfg_WifiApCfg
    */
    MESSAGE(Ev_MT_BLL_HD_SetWifiApCfgCfg_Cmd)
    BODY(mt::TWifiApConfiguration, )

    MESSAGE(Ev_MT_BLL_HD_SetWifiApCfgCfg_Ntf)
    BODY(mt::TWifiApConfiguration, )

    MESSAGE(Ev_MT_BLL_HD_GetWifiApCfgCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetWifiApCfgCfg_Rsp)
    BODY(mt::TWifiApConfiguration, )


    /*
    * key : emHD_Cfg_WifiClientCfg
    */
    MESSAGE(Ev_MT_BLL_HD_SetWifiClientCfgCfg_Cmd)
    BODY(mt::TWifiConfiguration, )

    MESSAGE(Ev_MT_BLL_HD_SetWifiClientCfgCfg_Ntf)
    BODY(mt::TWifiConfiguration, )

    MESSAGE(Ev_MT_BLL_HD_GetWifiClientCfgCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetWifiClientCfgCfg_Rsp)
    BODY(mt::TWifiConfiguration, )


    /*
    * key : emHD_Cfg_MobileDataWorkMode
    */
    MESSAGE(Ev_MT_BLL_HD_SetMobileDataWorkModeCfg_Cmd)
    BODY(mt::TMobileDataWorkMode, )

    MESSAGE(Ev_MT_BLL_HD_SetMobileDataWorkModeCfg_Ntf)
    BODY(mt::TMobileDataWorkMode, )

    MESSAGE(Ev_MT_BLL_HD_GetMobileDataWorkModeCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetMobileDataWorkModeCfg_Rsp)
    BODY(mt::TMobileDataWorkMode, )


    /*
    * key : emHD_Cfg_E1Cfg
    */
    MESSAGE(Ev_MT_BLL_HD_SetE1CfgCfg_Cmd)
    BODY(mt::TE1Cfg, )

    MESSAGE(Ev_MT_BLL_HD_SetE1CfgCfg_Ntf)
    BODY(mt::TE1Cfg, )

    MESSAGE(Ev_MT_BLL_HD_GetE1CfgCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetE1CfgCfg_Rsp)
    BODY(mt::TE1Cfg, )


    /*
    * key : emHD_Cfg_RouteCfgList
    */
    MESSAGE(Ev_MT_BLL_HD_SetRouteCfgListCfg_Cmd)
    BODY(mt::TRouteItemInfoList, )

    MESSAGE(Ev_MT_BLL_HD_SetRouteCfgListCfg_Ntf)
    BODY(mt::TRouteItemInfoList, )

    MESSAGE(Ev_MT_BLL_HD_GetRouteCfgListCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetRouteCfgListCfg_Rsp)
    BODY(mt::TRouteItemInfoList, )


    /*
    * key : emHD_Cfg_VidInPortBright
    */
    MESSAGE(Ev_MT_BLL_HD_SetVidInPortBrightCfg_Cmd)
    BODY(mt::TMtVideoPortParamList, )

    MESSAGE(Ev_MT_BLL_HD_SetVidInPortBrightCfg_Ntf)
    BODY(mt::TMtVideoPortParamList, )

    MESSAGE(Ev_MT_BLL_HD_GetVidInPortBrightCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetVidInPortBrightCfg_Rsp)
    BODY(mt::TMtVideoPortParamList, )


    /*
    * key : emHD_Cfg_VidInPortContrast
    */
    MESSAGE(Ev_MT_BLL_HD_SetVidInPortContrastCfg_Cmd)
    BODY(mt::TMtVideoPortParamList, )

    MESSAGE(Ev_MT_BLL_HD_SetVidInPortContrastCfg_Ntf)
    BODY(mt::TMtVideoPortParamList, )

    MESSAGE(Ev_MT_BLL_HD_GetVidInPortContrastCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetVidInPortContrastCfg_Rsp)
    BODY(mt::TMtVideoPortParamList, )


    /*
    * key : emHD_Cfg_VidInPortSaturation
    */
    MESSAGE(Ev_MT_BLL_HD_SetVidInPortSaturationCfg_Cmd)
    BODY(mt::TMtVideoPortParamList, )

    MESSAGE(Ev_MT_BLL_HD_SetVidInPortSaturationCfg_Ntf)
    BODY(mt::TMtVideoPortParamList, )

    MESSAGE(Ev_MT_BLL_HD_GetVidInPortSaturationCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetVidInPortSaturationCfg_Rsp)
    BODY(mt::TMtVideoPortParamList, )


    /*
    * key : emHD_Cfg_ResizeMode
    */
    MESSAGE(Ev_MT_BLL_HD_SetResizeModeCfg_Cmd)
    BODY(mt::TMTResizeMode, )

    MESSAGE(Ev_MT_BLL_HD_SetResizeModeCfg_Ntf)
    BODY(mt::TMTResizeMode, )

    MESSAGE(Ev_MT_BLL_HD_GetResizeModeCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetResizeModeCfg_Rsp)
    BODY(mt::TMTResizeMode, )


    /*
    * key : emHD_Cfg_FastCallList
    */
    MESSAGE(Ev_MT_BLL_HD_SetFastCallListCfg_Cmd)
    BODY(mt::TFastCallList, )

    MESSAGE(Ev_MT_BLL_HD_SetFastCallListCfg_Ntf)
    BODY(mt::TFastCallList, )

    MESSAGE(Ev_MT_BLL_HD_GetFastCallListCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetFastCallListCfg_Rsp)
    BODY(mt::TFastCallList, )


    /*
    * key : emHD_Cfg_RfMatchStateList
    */
    MESSAGE(Ev_MT_BLL_HD_SetRfMatchStateListCfg_Cmd)
    BODY(mt::TMTRfMatchStateList, )

    MESSAGE(Ev_MT_BLL_HD_SetRfMatchStateListCfg_Ntf)
    BODY(mt::TMTRfMatchStateList, )

    MESSAGE(Ev_MT_BLL_HD_GetRfMatchStateListCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetRfMatchStateListCfg_Rsp)
    BODY(mt::TMTRfMatchStateList, )


    /*
    * key : emHD_Cfg_CurPresetIndex
    */
    MESSAGE(Ev_MT_BLL_HD_SetCurPresetIndexCfg_Cmd)
    BODY(mt::TMTAllCodecPreSetIndex, )

    MESSAGE(Ev_MT_BLL_HD_SetCurPresetIndexCfg_Ntf)
    BODY(mt::TMTAllCodecPreSetIndex, )

    MESSAGE(Ev_MT_BLL_HD_GetCurPresetIndexCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCurPresetIndexCfg_Rsp)
    BODY(mt::TMTAllCodecPreSetIndex, )


    /*
    * key : emHD_Cfg_SDIOneInOneOutOrTwoIn
    */
    MESSAGE(Ev_MT_BLL_HD_SetSDIOneInOneOutOrTwoInCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_SetSDIOneInOneOutOrTwoInCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_GetSDIOneInOneOutOrTwoInCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetSDIOneInOneOutOrTwoInCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emHD_Cfg_CameraNoise
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraNoiseCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraNoiseCfg_Ntf)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraNoiseCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraNoiseCfg_Rsp)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraVidStd
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraVidStdCfg_Cmd)
    BODY(mt::TMtCameraVidStd, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraVidStdCfg_Ntf)
    BODY(mt::TMtCameraVidStd, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraVidStdCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraVidStdCfg_Rsp)
    BODY(mt::TMtCameraVidStd, )


    /*
    * key : emHD_Cfg_CameraContrlExchange
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraContrlExchangeCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraContrlExchangeCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraContrlExchangeCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraContrlExchangeCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Cfg_CameraImgMode
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraImgModeCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraImgModeCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraImgModeCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraImgModeCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emHD_Cfg_CameraPersonFirst
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraPersonFirstCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraPersonFirstCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraPersonFirstCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraPersonFirstCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_CFG_CameraHeadStand
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraHeadStandCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraHeadStandCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraHeadStandCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraHeadStandCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Cfg_LimitedIpCfg
    */
    MESSAGE(Ev_MT_BLL_HD_SetLimitedIpCfgCfg_Cmd)
    BODY(mt::TLimitedIpCfg, )

    MESSAGE(Ev_MT_BLL_HD_SetLimitedIpCfgCfg_Ntf)
    BODY(mt::TLimitedIpCfg, )

    MESSAGE(Ev_MT_BLL_HD_GetLimitedIpCfgCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetLimitedIpCfgCfg_Rsp)
    BODY(mt::TLimitedIpCfg, )


    /*
    * key : emHD_Cfg_SubAudExpansion
    */
    MESSAGE(Ev_MT_BLL_HD_SetSubAudExpansionCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_SetSubAudExpansionCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetSubAudExpansionCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetSubAudExpansionCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Cfg_CameraSharpness
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraSharpnessCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraSharpnessCfg_Ntf)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraSharpnessCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraSharpnessCfg_Rsp)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraISO
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraISOCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraISOCfg_Ntf)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraISOCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraISOCfg_Rsp)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraExposureMode
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraExposureModeCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraExposureModeCfg_Ntf)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraExposureModeCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraExposureModeCfg_Rsp)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraAperture
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraApertureCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraApertureCfg_Ntf)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraApertureCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraApertureCfg_Rsp)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraShutter
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraShutterCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraShutterCfg_Ntf)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraShutterCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraShutterCfg_Rsp)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraAotoExposureGain
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraAotoExposureGainCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraAotoExposureGainCfg_Ntf)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraAotoExposureGainCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraAotoExposureGainCfg_Rsp)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraManualExposureGain
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraManualExposureGainCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraManualExposureGainCfg_Ntf)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraManualExposureGainCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraManualExposureGainCfg_Rsp)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraBright
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraBrightCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraBrightCfg_Ntf)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraBrightCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraBrightCfg_Rsp)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraWhiteBalance
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraWhiteBalanceCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraWhiteBalanceCfg_Ntf)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraWhiteBalanceCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraWhiteBalanceCfg_Rsp)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraHue
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraHueCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraHueCfg_Ntf)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraHueCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraHueCfg_Rsp)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraContrast
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraContrastCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraContrastCfg_Ntf)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraContrastCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraContrastCfg_Rsp)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraSaturation
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraSaturationCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraSaturationCfg_Ntf)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraSaturationCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraSaturationCfg_Rsp)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraBackLightSwitch
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraBackLightSwitchCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraBackLightSwitchCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraBackLightSwitchCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraBackLightSwitchCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emHD_Cfg_CameraBackLightLevel
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraBackLightLevelCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraBackLightLevelCfg_Ntf)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraBackLightLevelCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraBackLightLevelCfg_Rsp)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_Camera2dNoise
    */
    MESSAGE(Ev_MT_BLL_HD_SetCamera2dNoiseCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_SetCamera2dNoiseCfg_Ntf)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_GetCamera2dNoiseCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCamera2dNoiseCfg_Rsp)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_Camera3dNoise
    */
    MESSAGE(Ev_MT_BLL_HD_SetCamera3dNoiseCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_SetCamera3dNoiseCfg_Ntf)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_GetCamera3dNoiseCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCamera3dNoiseCfg_Rsp)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraRedGain
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraRedGainCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraRedGainCfg_Ntf)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraRedGainCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraRedGainCfg_Rsp)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraBlueGain
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraBlueGainCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraBlueGainCfg_Ntf)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraBlueGainCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraBlueGainCfg_Rsp)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraImgGamma
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraImgGammaCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraImgGammaCfg_Ntf)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraImgGammaCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraImgGammaCfg_Rsp)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraImgDefog
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraImgDefogCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraImgDefogCfg_Ntf)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraImgDefogCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraImgDefogCfg_Rsp)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraImgDigDynSwitch
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraImgDigDynSwitchCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraImgDigDynSwitchCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraImgDigDynSwitchCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraImgDigDynSwitchCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Cfg_CameraImgDigDynLevel
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraImgDigDynLevelCfg_Cmd)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraImgDigDynLevelCfg_Ntf)
    BODY(mt::TCameraIspParam, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraImgDigDynLevelCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraImgDigDynLevelCfg_Rsp)
    BODY(mt::TCameraIspParam, )


    /*
    * key : emHD_Cfg_CameraLastPosCfg
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraLastPosCfgCfg_Cmd)
    BODY(mt::TMtCameraLastPos, )

    MESSAGE(Ev_MT_BLL_HD_SetCameraLastPosCfgCfg_Ntf)
    BODY(mt::TMtCameraLastPos, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraLastPosCfgCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraLastPosCfgCfg_Rsp)
    BODY(mt::TMtCameraLastPos, )


    /*
    * key : emHD_Rt_IsMfgTest
    */
    MESSAGE(Ev_MT_BLL_HD_SetIsMfgTestRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetIsMfgTestRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetIsMfgTestRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Rt_CallInRing
    */
    MESSAGE(Ev_MT_BLL_HD_SetCallInRingRt_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_GetCallInRingRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCallInRingRt_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emHD_Rt_CallOutRing
    */
    MESSAGE(Ev_MT_BLL_HD_SetCallOutRingRt_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_GetCallOutRingRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCallOutRingRt_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emHD_Rt_VideoSourceCapInfo
    */
    MESSAGE(Ev_MT_BLL_HD_SetVideoSourceCapInfoRt_Ntf)
    BODY(mt::TMTHDVidInPortCapList, )

    MESSAGE(Ev_MT_BLL_HD_GetVideoSourceCapInfoRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetVideoSourceCapInfoRt_Rsp)
    BODY(mt::TMTHDVidInPortCapList, )


    /*
    * key : emHD_Rt_CameraUpdating
    */
    MESSAGE(Ev_MT_BLL_HD_SetCameraUpdatingRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetCameraUpdatingRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetCameraUpdatingRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Rt_SnapShoting
    */
    MESSAGE(Ev_MT_BLL_HD_SetSnapShotingRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetSnapShotingRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetSnapShotingRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Rt_FxoState
    */
    MESSAGE(Ev_MT_BLL_HD_SetFxoStateRt_Ntf)
    BODY(mt::TFxoState, )

    MESSAGE(Ev_MT_BLL_HD_GetFxoStateRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetFxoStateRt_Rsp)
    BODY(mt::TFxoState, )


    /*
    * key : emHD_Rt_LocalLoop
    */
    MESSAGE(Ev_MT_BLL_HD_SetLocalLoopRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetLocalLoopRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetLocalLoopRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Rt_SnapViewing
    */
    MESSAGE(Ev_MT_BLL_HD_SetSnapViewingRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetSnapViewingRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetSnapViewingRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Rt_SnapExporting
    */
    MESSAGE(Ev_MT_BLL_HD_SetSnapExportingRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetSnapExportingRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetSnapExportingRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Rt_NetCaping
    */
    MESSAGE(Ev_MT_BLL_HD_SetNetCapingRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetNetCapingRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetNetCapingRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Rt_NetCapExporting
    */
    MESSAGE(Ev_MT_BLL_HD_SetNetCapExportingRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetNetCapExportingRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetNetCapExportingRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Rt_AddrbookTransfering
    */
    MESSAGE(Ev_MT_BLL_HD_SetAddrbookTransferingRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetAddrbookTransferingRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetAddrbookTransferingRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Rt_VidSrc2FarCtrlId
    */
    MESSAGE(Ev_MT_BLL_HD_SetVidSrc2FarCtrlIdRt_Ntf)
    BODY(mt::TMTVidSrc2FarCtrlIdList, )

    MESSAGE(Ev_MT_BLL_HD_GetVidSrc2FarCtrlIdRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetVidSrc2FarCtrlIdRt_Rsp)
    BODY(mt::TMTVidSrc2FarCtrlIdList, )


    /*
    * key : emHD_Rt_MtCapGroup
    */
    MESSAGE(Ev_MT_BLL_HD_SetMtCapGroupRt_Ntf)
    BODY(mt::TRpMtCap, )

    MESSAGE(Ev_MT_BLL_HD_GetMtCapGroupRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetMtCapGroupRt_Rsp)
    BODY(mt::TRpMtCap, )


    /*
    * key : emHD_Rt_MtSipCapGroup
    */
    MESSAGE(Ev_MT_BLL_HD_SetMtSipCapGroupRt_Ntf)
    BODY(mt::TRpMtCap, )

    MESSAGE(Ev_MT_BLL_HD_GetMtSipCapGroupRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetMtSipCapGroupRt_Rsp)
    BODY(mt::TRpMtCap, )


    /*
    * key : emHD_Rt_EthnetCurIp
    */
    MESSAGE(Ev_MT_BLL_HD_SetEthnetCurIpRt_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_GetEthnetCurIpRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetEthnetCurIpRt_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emHD_Rt_WifiCurConnectedInfo
    */
    MESSAGE(Ev_MT_BLL_HD_SetWifiCurConnectedInfoRt_Ntf)
    BODY(mt::TWifiCurDetailInfo, )

    MESSAGE(Ev_MT_BLL_HD_GetWifiCurConnectedInfoRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetWifiCurConnectedInfoRt_Rsp)
    BODY(mt::TWifiCurDetailInfo, )


    /*
    * key : emHD_Rt_MobileDataConnectedInfo
    */
    MESSAGE(Ev_MT_BLL_HD_SetMobileDataConnectedInfoRt_Ntf)
    BODY(mt::TMobileDataCurDetailInfo, )

    MESSAGE(Ev_MT_BLL_HD_GetMobileDataConnectedInfoRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetMobileDataConnectedInfoRt_Rsp)
    BODY(mt::TMobileDataCurDetailInfo, )


    /*
    * key : emHD_Rt_IsWifi
    */
    MESSAGE(Ev_MT_BLL_HD_SetIsWifiRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetIsWifiRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetIsWifiRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Rt_NetServiceStarted
    */
    MESSAGE(Ev_MT_BLL_HD_SetNetServiceStartedRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetNetServiceStartedRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetNetServiceStartedRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Rt_UsbStatus
    */
    MESSAGE(Ev_MT_BLL_HD_SetUsbStatusRt_Ntf)
    BODY(mt::TMTUsbStatus, )

    MESSAGE(Ev_MT_BLL_HD_GetUsbStatusRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetUsbStatusRt_Rsp)
    BODY(mt::TMTUsbStatus, )


    /*
    * key : emHD_Rt_IsSleep
    */
    MESSAGE(Ev_MT_BLL_HD_SetIsSleepRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetIsSleepRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetIsSleepRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Rt_BrdInfo
    */
    MESSAGE(Ev_MT_BLL_HD_SetBrdInfoRt_Ntf)
    BODY(mt::TMTBrdInfo, )

    MESSAGE(Ev_MT_BLL_HD_GetBrdInfoRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetBrdInfoRt_Rsp)
    BODY(mt::TMTBrdInfo, )


    /*
    * key : emHD_Rt_VideoSrcRes
    */
    MESSAGE(Ev_MT_BLL_HD_SetVideoSrcResRt_Ntf)
    BODY(mt::TMtVidSrcInfoList, )

    MESSAGE(Ev_MT_BLL_HD_GetVideoSrcResRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetVideoSrcResRt_Rsp)
    BODY(mt::TMtVidSrcInfoList, )


    /*
    * key : emHD_Rt_AppRunInfo
    */
    MESSAGE(Ev_MT_BLL_HD_SetAppRunInfoRt_Ntf)
    BODY(mt::TMutiTServiceInfoRtData, )

    MESSAGE(Ev_MT_BLL_HD_GetAppRunInfoRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetAppRunInfoRt_Rsp)
    BODY(mt::TMutiTServiceInfoRtData, )


    /*
    * key : emHD_Rt_AutoUpgrade
    */
    MESSAGE(Ev_MT_BLL_HD_SetAutoUpgradeRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetAutoUpgradeRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetAutoUpgradeRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Rt_VidDecDynamicPayload
    */
    MESSAGE(Ev_MT_BLL_HD_SetVidDecDynamicPayloadRt_Ntf)
    BODY(mt::TDynamicPayload, )

    MESSAGE(Ev_MT_BLL_HD_GetVidDecDynamicPayloadRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetVidDecDynamicPayloadRt_Rsp)
    BODY(mt::TDynamicPayload, )


    /*
    * key : emHD_Rt_ImageSequenceNumberType
    */
    MESSAGE(Ev_MT_BLL_HD_SetImageSequenceNumberTypeRt_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_GetImageSequenceNumberTypeRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetImageSequenceNumberTypeRt_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emHD_Rt_ImChatroomAvailable
    */
    MESSAGE(Ev_MT_BLL_HD_SetImChatroomAvailableRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetImChatroomAvailableRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetImChatroomAvailableRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Rt_IsAutoAudioDelayCheck
    */
    MESSAGE(Ev_MT_BLL_HD_SetIsAutoAudioDelayCheckRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetIsAutoAudioDelayCheckRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetIsAutoAudioDelayCheckRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Rt_IsMfgToolConnected
    */
    MESSAGE(Ev_MT_BLL_HD_SetIsMfgToolConnectedRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetIsMfgToolConnectedRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetIsMfgToolConnectedRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Rt_CameraZoom
    */
    MESSAGE(Ev_MT_BLL_SetCameraZoomRt_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_GetCameraZoomRt_Req)

    MESSAGE(Ev_MT_BLL_GetCameraZoomRt_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emMt_Rt_CameraFocus
    */
    MESSAGE(Ev_MT_BLL_SetCameraFocusRt_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_GetCameraFocusRt_Req)

    MESSAGE(Ev_MT_BLL_GetCameraFocusRt_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emHD_Rt_MtRecordStatus
    */
    MESSAGE(Ev_MT_BLL_HD_SetMtRecordStatusRt_Ntf)
    BODY(mt::UnknownProtoMsg, )

    MESSAGE(Ev_MT_BLL_HD_GetMtRecordStatusRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetMtRecordStatusRt_Rsp)
    BODY(mt::UnknownProtoMsg, )


    /*
    * key : emHD_Rt_MtStreamStatus
    */
    MESSAGE(Ev_MT_BLL_HD_SetMtStreamStatusRt_Ntf)
    BODY(mt::enum, )

    MESSAGE(Ev_MT_BLL_HD_GetMtStreamStatusRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetMtStreamStatusRt_Rsp)
    BODY(mt::enum, )


    /*
    * key : emHD_Rt_SkyShareVer
    */
    MESSAGE(Ev_MT_BLL_HD_SetSkyShareVerRt_Ntf)
    BODY(mt::TString, )

    MESSAGE(Ev_MT_BLL_HD_GetSkyShareVerRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetSkyShareVerRt_Rsp)
    BODY(mt::TString, )


    /*
    * key : emHD_Rt_SkyMtcVer
    */
    MESSAGE(Ev_MT_BLL_HD_SetSkyMtcVerRt_Ntf)
    BODY(mt::TString, )

    MESSAGE(Ev_MT_BLL_HD_GetSkyMtcVerRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetSkyMtcVerRt_Rsp)
    BODY(mt::TString, )


    /*
    * key : emHD_Rt_IsSupportWireless
    */
    MESSAGE(Ev_MT_BLL_HD_SetIsSupportWirelessRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetIsSupportWirelessRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetIsSupportWirelessRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Rt_AudAacConfPrm
    */
    MESSAGE(Ev_MT_BLL_HD_SetAudAacConfPrmRt_Ntf)
    BODY(mt::TAudAacConfPrmList, )

    MESSAGE(Ev_MT_BLL_HD_GetAudAacConfPrmRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetAudAacConfPrmRt_Rsp)
    BODY(mt::TAudAacConfPrmList, )


    /*
    * key : emHD_Rt_KdvMtModel
    */
    MESSAGE(Ev_MT_BLL_HD_SetKdvMtModelRt_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_GetKdvMtModelRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetKdvMtModelRt_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emHD_Rt_MtCameraCtrlType
    */
    MESSAGE(Ev_MT_BLL_HD_SetMtCameraCtrlTypeRt_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_GetMtCameraCtrlTypeRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetMtCameraCtrlTypeRt_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emHD_Rt_HwSubVer
    */
    MESSAGE(Ev_MT_BLL_HD_SetHwSubVerRt_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_GetHwSubVerRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetHwSubVerRt_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emHD_Rt_MicTag
    */
    MESSAGE(Ev_MT_BLL_HD_SetMicTagRt_Ntf)
    BODY(mt::TMTMicTagList, )

    MESSAGE(Ev_MT_BLL_HD_GetMicTagRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetMicTagRt_Rsp)
    BODY(mt::TMTMicTagList, )


    /*
    * key : emHD_Rt_MicPhoneUpdating
    */
    MESSAGE(Ev_MT_BLL_HD_SetMicPhoneUpdatingRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetMicPhoneUpdatingRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetMicPhoneUpdatingRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Rt_OpenScanFeature
    */
    MESSAGE(Ev_MT_BLL_HD_SetOpenScanFeatureRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetOpenScanFeatureRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetOpenScanFeatureRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Rt_IsMfgTestLoad
    */
    MESSAGE(Ev_MT_BLL_HD_SetIsMfgTestLoadRt_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_HD_GetIsMfgTestLoadRt_Req)

    MESSAGE(Ev_MT_BLL_HD_GetIsMfgTestLoadRt_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_TAudioRemoveG719
    */
    MESSAGE(Ev_MT_BLL_SetTAudioRemoveG719Cfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetTAudioRemoveG719Cfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetTAudioRemoveG719Cfg_Req)

    MESSAGE(Ev_MT_BLL_GetTAudioRemoveG719Cfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_LoadAdaptiveVideo
    */
    MESSAGE(Ev_MT_BLL_SetLoadAdaptiveVideoCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetLoadAdaptiveVideoCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetLoadAdaptiveVideoCfg_Req)

    MESSAGE(Ev_MT_BLL_GetLoadAdaptiveVideoCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emHD_Cfg_ImageSequenceNumberType
    */
    MESSAGE(Ev_MT_BLL_HD_SetImageSequenceNumberTypeCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_SetImageSequenceNumberTypeCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_HD_GetImageSequenceNumberTypeCfg_Req)

    MESSAGE(Ev_MT_BLL_HD_GetImageSequenceNumberTypeCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_TForceRtpExStrip
    */
    MESSAGE(Ev_MT_BLL_SetTForceRtpExStripCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetTForceRtpExStripCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetTForceRtpExStripCfg_Req)

    MESSAGE(Ev_MT_BLL_GetTForceRtpExStripCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_TEnableDsp6678Detect
    */
    MESSAGE(Ev_MT_BLL_SetTEnableDsp6678DetectCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetTEnableDsp6678DetectCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetTEnableDsp6678DetectCfg_Req)

    MESSAGE(Ev_MT_BLL_GetTEnableDsp6678DetectCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_TG711AudioDuration
    */
    MESSAGE(Ev_MT_BLL_SetTG711AudioDurationCfg_Cmd)
    BODY(mt::UnknownProtoMsg, )

    MESSAGE(Ev_MT_BLL_SetTG711AudioDurationCfg_Ntf)
    BODY(mt::UnknownProtoMsg, )

    MESSAGE(Ev_MT_BLL_GetTG711AudioDurationCfg_Req)

    MESSAGE(Ev_MT_BLL_GetTG711AudioDurationCfg_Rsp)
    BODY(mt::UnknownProtoMsg, )


    /*
    * key : emMt_Cfg_TAudioRemoveOPUS
    */
    MESSAGE(Ev_MT_BLL_SetTAudioRemoveOPUSCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetTAudioRemoveOPUSCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetTAudioRemoveOPUSCfg_Req)

    MESSAGE(Ev_MT_BLL_GetTAudioRemoveOPUSCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_TRemoveMultAudFormats
    */
    MESSAGE(Ev_MT_BLL_SetTRemoveMultAudFormatsCfg_Cmd)
    BODY(mt::TMultiU32, )

    MESSAGE(Ev_MT_BLL_SetTRemoveMultAudFormatsCfg_Ntf)
    BODY(mt::TMultiU32, )

    MESSAGE(Ev_MT_BLL_GetTRemoveMultAudFormatsCfg_Req)

    MESSAGE(Ev_MT_BLL_GetTRemoveMultAudFormatsCfg_Rsp)
    BODY(mt::TMultiU32, )


    /*
    * key : emMt_Cfg_TEnableBfcpTwice
    */
    MESSAGE(Ev_MT_BLL_SetTEnableBfcpTwiceCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetTEnableBfcpTwiceCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetTEnableBfcpTwiceCfg_Req)

    MESSAGE(Ev_MT_BLL_GetTEnableBfcpTwiceCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_TEnableAudioEncParam
    */
    MESSAGE(Ev_MT_BLL_SetTEnableAudioEncParamCfg_Cmd)
    BODY(mt::TAudioEncParamList, )

    MESSAGE(Ev_MT_BLL_SetTEnableAudioEncParamCfg_Ntf)
    BODY(mt::TAudioEncParamList, )

    MESSAGE(Ev_MT_BLL_GetTEnableAudioEncParamCfg_Req)

    MESSAGE(Ev_MT_BLL_GetTEnableAudioEncParamCfg_Rsp)
    BODY(mt::TAudioEncParamList, )


    /*
    * key : emMt_Cfg_TSetRoundTripType
    */
    MESSAGE(Ev_MT_BLL_SetTSetRoundTripTypeCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_SetTSetRoundTripTypeCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_GetTSetRoundTripTypeCfg_Req)

    MESSAGE(Ev_MT_BLL_GetTSetRoundTripTypeCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_KedaAacSampFreq32K
    */
    MESSAGE(Ev_MT_BLL_SetKedaAacSampFreq32KCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetKedaAacSampFreq32KCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetKedaAacSampFreq32KCfg_Req)

    MESSAGE(Ev_MT_BLL_GetKedaAacSampFreq32KCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_VidDecDynamicPayload
    */
    MESSAGE(Ev_MT_BLL_SetVidDecDynamicPayloadCfg_Cmd)
    BODY(mt::TDynamicPayload, )

    MESSAGE(Ev_MT_BLL_SetVidDecDynamicPayloadCfg_Ntf)
    BODY(mt::TDynamicPayload, )

    MESSAGE(Ev_MT_BLL_GetVidDecDynamicPayloadCfg_Req)

    MESSAGE(Ev_MT_BLL_GetVidDecDynamicPayloadCfg_Rsp)
    BODY(mt::TDynamicPayload, )


    /*
    * key : emMt_Cfg_AudDecDynamicPayload
    */
    MESSAGE(Ev_MT_BLL_SetAudDecDynamicPayloadCfg_Cmd)
    BODY(mt::TDynamicPayload, )

    MESSAGE(Ev_MT_BLL_SetAudDecDynamicPayloadCfg_Ntf)
    BODY(mt::TDynamicPayload, )

    MESSAGE(Ev_MT_BLL_GetAudDecDynamicPayloadCfg_Req)

    MESSAGE(Ev_MT_BLL_GetAudDecDynamicPayloadCfg_Rsp)
    BODY(mt::TDynamicPayload, )


    /*
    * key : emMt_Cfg_TIgnoreBitrateZero
    */
    MESSAGE(Ev_MT_BLL_SetTIgnoreBitrateZeroCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetTIgnoreBitrateZeroCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetTIgnoreBitrateZeroCfg_Req)

    MESSAGE(Ev_MT_BLL_GetTIgnoreBitrateZeroCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_T323AdditionalConfig
    */
    MESSAGE(Ev_MT_BLL_SetT323AdditionalConfigCfg_Cmd)
    BODY(mt::TMultiU32, )

    MESSAGE(Ev_MT_BLL_SetT323AdditionalConfigCfg_Ntf)
    BODY(mt::TMultiU32, )

    MESSAGE(Ev_MT_BLL_GetT323AdditionalConfigCfg_Req)

    MESSAGE(Ev_MT_BLL_GetT323AdditionalConfigCfg_Rsp)
    BODY(mt::TMultiU32, )


    /*
    * key : emMt_Rt_InnerMcAvSWPort
    */
    MESSAGE(Ev_MT_BLL_SetInnerMcAvSWPortRt_Ntf)
    BODY(mt::TMtInnerMCAvSWPort, )

    MESSAGE(Ev_MT_BLL_GetInnerMcAvSWPortRt_Req)

    MESSAGE(Ev_MT_BLL_GetInnerMcAvSWPortRt_Rsp)
    BODY(mt::TMtInnerMCAvSWPort, )


    /*
    * key : emMt_Rt_InnerMcRcvAddr
    */
    MESSAGE(Ev_MT_BLL_SetInnerMcRcvAddrRt_Ntf)
    BODY(mt::TMtInnerMcRcvAddr, )

    MESSAGE(Ev_MT_BLL_GetInnerMcRcvAddrRt_Req)

    MESSAGE(Ev_MT_BLL_GetInnerMcRcvAddrRt_Rsp)
    BODY(mt::TMtInnerMcRcvAddr, )


    /*
    * key : emMt_Rt_InnerMcAssRcvAddr
    */
    MESSAGE(Ev_MT_BLL_SetInnerMcAssRcvAddrRt_Ntf)
    BODY(mt::TRtpRtcpPairPort, )

    MESSAGE(Ev_MT_BLL_GetInnerMcAssRcvAddrRt_Req)

    MESSAGE(Ev_MT_BLL_GetInnerMcAssRcvAddrRt_Rsp)
    BODY(mt::TRtpRtcpPairPort, )


    /*
    * key : emMt_Cfg_TAudioRemoveLCLD
    */
    MESSAGE(Ev_MT_BLL_SetTAudioRemoveLCLDCfg_Cmd)
    BODY(mt::UnknownProtoMsg, )

    MESSAGE(Ev_MT_BLL_SetTAudioRemoveLCLDCfg_Ntf)
    BODY(mt::UnknownProtoMsg, )

    MESSAGE(Ev_MT_BLL_GetTAudioRemoveLCLDCfg_Req)

    MESSAGE(Ev_MT_BLL_GetTAudioRemoveLCLDCfg_Rsp)
    BODY(mt::UnknownProtoMsg, )


    /*
    * key : emMt_Cfg_AudioPrecedence
    */
    MESSAGE(Ev_MT_BLL_SetAudioPrecedenceCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetAudioPrecedenceCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetAudioPrecedenceCfg_Req)

    MESSAGE(Ev_MT_BLL_GetAudioPrecedenceCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_TForceSet323Stack
    */
    MESSAGE(Ev_MT_BLL_SetTForceSet323StackCfg_Cmd)
    BODY(mt::TMtForceSetH323Stack, )

    MESSAGE(Ev_MT_BLL_SetTForceSet323StackCfg_Ntf)
    BODY(mt::TMtForceSetH323Stack, )

    MESSAGE(Ev_MT_BLL_GetTForceSet323StackCfg_Req)

    MESSAGE(Ev_MT_BLL_GetTForceSet323StackCfg_Rsp)
    BODY(mt::TMtForceSetH323Stack, )


    /*
    * key : emMt_Cfg_TEnableIpwType
    */
    MESSAGE(Ev_MT_BLL_SetTEnableIpwTypeCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetTEnableIpwTypeCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetTEnableIpwTypeCfg_Req)

    MESSAGE(Ev_MT_BLL_GetTEnableIpwTypeCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_TEnableVidBitRateCtrl
    */
    MESSAGE(Ev_MT_BLL_SetTEnableVidBitRateCtrlCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetTEnableVidBitRateCtrlCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetTEnableVidBitRateCtrlCfg_Req)

    MESSAGE(Ev_MT_BLL_GetTEnableVidBitRateCtrlCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_TVideoSliceCount
    */
    MESSAGE(Ev_MT_BLL_SetTVideoSliceCountCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_SetTVideoSliceCountCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_GetTVideoSliceCountCfg_Req)

    MESSAGE(Ev_MT_BLL_GetTVideoSliceCountCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_SipKeepAliveItrvl
    */
    MESSAGE(Ev_MT_BLL_SetSipKeepAliveItrvlCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_SetSipKeepAliveItrvlCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_GetSipKeepAliveItrvlCfg_Req)

    MESSAGE(Ev_MT_BLL_GetSipKeepAliveItrvlCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emMt_Rt_TConfinfo
    */
    MESSAGE(Ev_MT_BLL_SetTConfinfoRt_Ntf)
    BODY(mt::UnknownProtoMsg, )

    MESSAGE(Ev_MT_BLL_GetTConfinfoRt_Req)

    MESSAGE(Ev_MT_BLL_GetTConfinfoRt_Rsp)
    BODY(mt::UnknownProtoMsg, )


    /*
    * key : emMt_Cfg_TRtpSamePort
    */
    MESSAGE(Ev_MT_BLL_SetTRtpSamePortCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetTRtpSamePortCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetTRtpSamePortCfg_Req)

    MESSAGE(Ev_MT_BLL_GetTRtpSamePortCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_TRegTimeout
    */
    MESSAGE(Ev_MT_BLL_SetTRegTimeoutCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_SetTRegTimeoutCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_GetTRegTimeoutCfg_Req)

    MESSAGE(Ev_MT_BLL_GetTRegTimeoutCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_AutoRas
    */
    MESSAGE(Ev_MT_BLL_SetAutoRasCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetAutoRasCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetAutoRasCfg_Req)

    MESSAGE(Ev_MT_BLL_GetAutoRasCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_TSipCallPort
    */
    MESSAGE(Ev_MT_BLL_SetTSipCallPortCfg_Cmd)
    BODY(mt::TMultiU32, )

    MESSAGE(Ev_MT_BLL_SetTSipCallPortCfg_Ntf)
    BODY(mt::TMultiU32, )

    MESSAGE(Ev_MT_BLL_GetTSipCallPortCfg_Req)

    MESSAGE(Ev_MT_BLL_GetTSipCallPortCfg_Rsp)
    BODY(mt::TMultiU32, )


    /*
    * key : emMt_Cfg_SipConnection
    */
    MESSAGE(Ev_MT_BLL_SetSipConnectionCfg_Cmd)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_SetSipConnectionCfg_Ntf)
    BODY(mt::TU32, )

    MESSAGE(Ev_MT_BLL_GetSipConnectionCfg_Req)

    MESSAGE(Ev_MT_BLL_GetSipConnectionCfg_Rsp)
    BODY(mt::TU32, )


    /*
    * key : emMt_Cfg_TEnableStrongAut
    */
    MESSAGE(Ev_MT_BLL_SetTEnableStrongAutCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetTEnableStrongAutCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetTEnableStrongAutCfg_Req)

    MESSAGE(Ev_MT_BLL_GetTEnableStrongAutCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_UseTlsCert
    */
    MESSAGE(Ev_MT_BLL_SetUseTlsCertCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetUseTlsCertCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetUseTlsCertCfg_Req)

    MESSAGE(Ev_MT_BLL_GetUseTlsCertCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_UseGMTlsCert
    */
    MESSAGE(Ev_MT_BLL_SetUseGMTlsCertCfg_Cmd)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_SetUseGMTlsCertCfg_Ntf)
    BODY(mt::TBOOL32, )

    MESSAGE(Ev_MT_BLL_GetUseGMTlsCertCfg_Req)

    MESSAGE(Ev_MT_BLL_GetUseGMTlsCertCfg_Rsp)
    BODY(mt::TBOOL32, )


    /*
    * key : emMt_Cfg_QtSetting
    */
    MESSAGE(Ev_MT_BLL_SetQtSettingCfg_Cmd)
    BODY(mt::TMtQtAddr, )

    MESSAGE(Ev_MT_BLL_SetQtSettingCfg_Ntf)
    BODY(mt::TMtQtAddr, )

    MESSAGE(Ev_MT_BLL_GetQtSettingCfg_Req)

    MESSAGE(Ev_MT_BLL_GetQtSettingCfg_Rsp)
    BODY(mt::TMtQtAddr, )


    /*
    * key : emMt_Cfg_QtKeyUpdateMode
    */
    MESSAGE(Ev_MT_BLL_SetQtKeyUpdateModeCfg_Cmd)
    BODY(mt::TMtSecKeyUpdatePolicy, )

    MESSAGE(Ev_MT_BLL_SetQtKeyUpdateModeCfg_Ntf)
    BODY(mt::TMtSecKeyUpdatePolicy, )

    MESSAGE(Ev_MT_BLL_GetQtKeyUpdateModeCfg_Req)

    MESSAGE(Ev_MT_BLL_GetQtKeyUpdateModeCfg_Rsp)
    BODY(mt::TMtSecKeyUpdatePolicy, )


    /*
    * key : emMt_Rt_AllSelfTestInfo
    */
    MESSAGE(Ev_MT_BLL_SetAllSelfTestInfoRt_Ntf)
    BODY(mt::TAllSelfTestResult, )

    MESSAGE(Ev_MT_BLL_GetAllSelfTestInfoRt_Req)

    MESSAGE(Ev_MT_BLL_GetAllSelfTestInfoRt_Rsp)
    BODY(mt::TAllSelfTestResult, )


    /*
    * key : emMt_Rt_SecRandKey
    */
    MESSAGE(Ev_MT_BLL_SetSecRandKeyRt_Ntf)
    BODY(mt::UnknownProtoMsg, )

    MESSAGE(Ev_MT_BLL_GetSecRandKeyRt_Req)

    MESSAGE(Ev_MT_BLL_GetSecRandKeyRt_Rsp)
    BODY(mt::UnknownProtoMsg, )



#if !defined(_MESSAGE_HELP_)
     EV_BLL_END(CONFIG) = EVSEG_BLL_CONFIG_END
};
#endif

#define Is_BLL_MtConfig_Msg(m) ((m) >= EV_BLL_BGN(CONFIG) && (m) <= EV_BLL_END(CONFIG))

#endif //_MT_BLL_CONFIG_MSG_H_

