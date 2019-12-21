#ifndef _NV_BLL_CONFIG_MSG_H_
#define _NV_BLL_CONFIG_MSG_H_
///////////////////////////////////////////////////////////////
//默认 配置消息 定义
///////////////////////////////////////////////////////////////
//脚本 gen_cfg_files 根据 nvdskey.h 自动生成,请勿手动修改
///////////////////////////////////////////////////////////////

#include "nvmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLNvConfigMsg
{
    EV_BLL_BGN(CONFIG) = EVSEG_BLL_CONFIG_BGN,
#endif


    /*
    * key : emNv_Cfg_Port
    */
    MESSAGE(Ev_NV_BLL_SetPortCfg_Cmd)
    BODY(nv::TNvPortCfg, )

    MESSAGE(Ev_NV_BLL_SetPortCfg_Ntf)
    BODY(nv::TNvPortCfg, )

    MESSAGE(Ev_NV_BLL_GetPortCfg_Req)

    MESSAGE(Ev_NV_BLL_GetPortCfg_Rsp)
    BODY(nv::TNvPortCfg, )


    /*
    * key : emNv_Cfg_SysCtrlDefSrvInfo
    */
    MESSAGE(Ev_NV_BLL_SetSysCtrlDefSrvInfoCfg_Cmd)
    BODY(nv::TNVMutiTServiceDefInfo, )

    MESSAGE(Ev_NV_BLL_SetSysCtrlDefSrvInfoCfg_Ntf)
    BODY(nv::TNVMutiTServiceDefInfo, )

    MESSAGE(Ev_NV_BLL_GetSysCtrlDefSrvInfoCfg_Req)

    MESSAGE(Ev_NV_BLL_GetSysCtrlDefSrvInfoCfg_Rsp)
    BODY(nv::TNVMutiTServiceDefInfo, )


    /*
    * key : emNv_Cfg_SysCtrlDefSrvNum
    */
    MESSAGE(Ev_NV_BLL_SetSysCtrlDefSrvNumCfg_Cmd)
    BODY(nv::TU32, )

    MESSAGE(Ev_NV_BLL_SetSysCtrlDefSrvNumCfg_Ntf)
    BODY(nv::TU32, )

    MESSAGE(Ev_NV_BLL_GetSysCtrlDefSrvNumCfg_Req)

    MESSAGE(Ev_NV_BLL_GetSysCtrlDefSrvNumCfg_Rsp)
    BODY(nv::TU32, )


    /*
    * key : emNv_Cfg_SUS
    */
    MESSAGE(Ev_NV_BLL_SetSUSCfg_Cmd)
    BODY(nv::TNVSUSAddr, )

    MESSAGE(Ev_NV_BLL_SetSUSCfg_Ntf)
    BODY(nv::TNVSUSAddr, )

    MESSAGE(Ev_NV_BLL_GetSUSCfg_Req)

    MESSAGE(Ev_NV_BLL_GetSUSCfg_Rsp)
    BODY(nv::TNVSUSAddr, )


    /*
    * key : emNv_Cfg_TerIp
    */
    MESSAGE(Ev_NV_BLL_SetTerIpCfg_Cmd)
    BODY(nv::TString, )

    MESSAGE(Ev_NV_BLL_SetTerIpCfg_Ntf)
    BODY(nv::TString, )

    MESSAGE(Ev_NV_BLL_GetTerIpCfg_Req)

    MESSAGE(Ev_NV_BLL_GetTerIpCfg_Rsp)
    BODY(nv::TString, )


    /*
    * key : emNv_Cfg_ImixIp
    */
    MESSAGE(Ev_NV_BLL_SetImixIpCfg_Cmd)
    BODY(nv::TNVNetUsedInfo, )

    MESSAGE(Ev_NV_BLL_SetImixIpCfg_Ntf)
    BODY(nv::TNVNetUsedInfo, )

    MESSAGE(Ev_NV_BLL_GetImixIpCfg_Req)

    MESSAGE(Ev_NV_BLL_GetImixIpCfg_Rsp)
    BODY(nv::TNVNetUsedInfo, )


    /*
    * key : emNv_Cfg_LogSerIp
    */
    MESSAGE(Ev_NV_BLL_SetLogSerIpCfg_Cmd)
    BODY(nv::TString, )

    MESSAGE(Ev_NV_BLL_SetLogSerIpCfg_Ntf)
    BODY(nv::TString, )

    MESSAGE(Ev_NV_BLL_GetLogSerIpCfg_Req)

    MESSAGE(Ev_NV_BLL_GetLogSerIpCfg_Rsp)
    BODY(nv::TString, )


    /*
    * key : emNv_Cfg_EmailSerIp
    */
    MESSAGE(Ev_NV_BLL_SetEmailSerIpCfg_Cmd)
    BODY(nv::TString, )

    MESSAGE(Ev_NV_BLL_SetEmailSerIpCfg_Ntf)
    BODY(nv::TString, )

    MESSAGE(Ev_NV_BLL_GetEmailSerIpCfg_Req)

    MESSAGE(Ev_NV_BLL_GetEmailSerIpCfg_Rsp)
    BODY(nv::TString, )


    /*
    * key : emNv_Cfg_Log
    */
    MESSAGE(Ev_NV_BLL_SetLogCfg_Cmd)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_SetLogCfg_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_GetLogCfg_Req)

    MESSAGE(Ev_NV_BLL_GetLogCfg_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emNv_Cfg_TimeZone
    */
    MESSAGE(Ev_NV_BLL_SetTimeZoneCfg_Cmd)
    BODY(nv::TS32, )

    MESSAGE(Ev_NV_BLL_SetTimeZoneCfg_Ntf)
    BODY(nv::TS32, )

    MESSAGE(Ev_NV_BLL_GetTimeZoneCfg_Req)

    MESSAGE(Ev_NV_BLL_GetTimeZoneCfg_Rsp)
    BODY(nv::TS32, )


    /*
    * key : emNv_Cfg_Screen
    */
    MESSAGE(Ev_NV_BLL_SetScreenCfg_Cmd)
    BODY(nv::TNVScreenParamList, )

    MESSAGE(Ev_NV_BLL_SetScreenCfg_Ntf)
    BODY(nv::TNVScreenParamList, )

    MESSAGE(Ev_NV_BLL_GetScreenCfg_Req)

    MESSAGE(Ev_NV_BLL_GetScreenCfg_Rsp)
    BODY(nv::TNVScreenParamList, )


    /*
    * key : emNv_Cfg_ScreenNum
    */
    MESSAGE(Ev_NV_BLL_SetScreenNumCfg_Cmd)
    BODY(nv::TU32, )

    MESSAGE(Ev_NV_BLL_SetScreenNumCfg_Ntf)
    BODY(nv::TU32, )

    MESSAGE(Ev_NV_BLL_GetScreenNumCfg_Req)

    MESSAGE(Ev_NV_BLL_GetScreenNumCfg_Rsp)
    BODY(nv::TU32, )


    /*
    * key : emNv_Cfg_BackstageUpgrade
    */
    MESSAGE(Ev_NV_BLL_SetBackstageUpgradeCfg_Cmd)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_SetBackstageUpgradeCfg_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_GetBackstageUpgradeCfg_Req)

    MESSAGE(Ev_NV_BLL_GetBackstageUpgradeCfg_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emNv_Cfg_QuickShareVersionInfo
    */
    MESSAGE(Ev_NV_BLL_SetQuickShareVersionInfoCfg_Cmd)
    BODY(nv::TNVDevUpgrade, )

    MESSAGE(Ev_NV_BLL_SetQuickShareVersionInfoCfg_Ntf)
    BODY(nv::TNVDevUpgrade, )

    MESSAGE(Ev_NV_BLL_GetQuickShareVersionInfoCfg_Req)

    MESSAGE(Ev_NV_BLL_GetQuickShareVersionInfoCfg_Rsp)
    BODY(nv::TNVDevUpgrade, )


    /*
    * key : emNv_Cfg_ImixVersionInfo
    */
    MESSAGE(Ev_NV_BLL_SetImixVersionInfoCfg_Cmd)
    BODY(nv::TNVDevUpgrade, )

    MESSAGE(Ev_NV_BLL_SetImixVersionInfoCfg_Ntf)
    BODY(nv::TNVDevUpgrade, )

    MESSAGE(Ev_NV_BLL_GetImixVersionInfoCfg_Req)

    MESSAGE(Ev_NV_BLL_GetImixVersionInfoCfg_Rsp)
    BODY(nv::TNVDevUpgrade, )


    /*
    * key : emNv_Cfg_IsUpgradeFileDownloadFinish
    */
    MESSAGE(Ev_NV_BLL_SetIsUpgradeFileDownloadFinishCfg_Cmd)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_SetIsUpgradeFileDownloadFinishCfg_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_GetIsUpgradeFileDownloadFinishCfg_Req)

    MESSAGE(Ev_NV_BLL_GetIsUpgradeFileDownloadFinishCfg_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emNv_Cfg_IsUpgradeFinish
    */
    MESSAGE(Ev_NV_BLL_SetIsUpgradeFinishCfg_Cmd)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_SetIsUpgradeFinishCfg_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_GetIsUpgradeFinishCfg_Req)

    MESSAGE(Ev_NV_BLL_GetIsUpgradeFinishCfg_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emNv_Cfg_PreCheckUpgradeInfo
    */
    MESSAGE(Ev_NV_BLL_SetPreCheckUpgradeInfoCfg_Cmd)
    BODY(nv::TNVUpgradeClientInfo, )

    MESSAGE(Ev_NV_BLL_SetPreCheckUpgradeInfoCfg_Ntf)
    BODY(nv::TNVUpgradeClientInfo, )

    MESSAGE(Ev_NV_BLL_GetPreCheckUpgradeInfoCfg_Req)

    MESSAGE(Ev_NV_BLL_GetPreCheckUpgradeInfoCfg_Rsp)
    BODY(nv::TNVUpgradeClientInfo, )


    /*
    * key : emNv_Cfg_CodecAudOutVol
    */
    MESSAGE(Ev_NV_BLL_SetCodecAudOutVolCfg_Cmd)
    BODY(nv::nv, )

    MESSAGE(Ev_NV_BLL_SetCodecAudOutVolCfg_Ntf)
    BODY(nv::nv, )

    MESSAGE(Ev_NV_BLL_GetCodecAudOutVolCfg_Req)

    MESSAGE(Ev_NV_BLL_GetCodecAudOutVolCfg_Rsp)
    BODY(nv::nv, )


    /*
    * key : emNv_Cfg_CodecQuiet
    */
    MESSAGE(Ev_NV_BLL_SetCodecQuietCfg_Cmd)
    BODY(nv::nv, )

    MESSAGE(Ev_NV_BLL_SetCodecQuietCfg_Ntf)
    BODY(nv::nv, )

    MESSAGE(Ev_NV_BLL_GetCodecQuietCfg_Req)

    MESSAGE(Ev_NV_BLL_GetCodecQuietCfg_Rsp)
    BODY(nv::nv, )


    /*
    * key : emNv_Cfg_IsFullScreen
    */
    MESSAGE(Ev_NV_BLL_SetIsFullScreenCfg_Cmd)
    BODY(nv::nv, )

    MESSAGE(Ev_NV_BLL_SetIsFullScreenCfg_Ntf)
    BODY(nv::nv, )

    MESSAGE(Ev_NV_BLL_GetIsFullScreenCfg_Req)

    MESSAGE(Ev_NV_BLL_GetIsFullScreenCfg_Rsp)
    BODY(nv::nv, )


    /*
    * key : emNv_Cfg_VidResResizeMode
    */
    MESSAGE(Ev_NV_BLL_SetVidResResizeModeCfg_Cmd)
    BODY(nv::nv, )

    MESSAGE(Ev_NV_BLL_SetVidResResizeModeCfg_Ntf)
    BODY(nv::nv, )

    MESSAGE(Ev_NV_BLL_GetVidResResizeModeCfg_Req)

    MESSAGE(Ev_NV_BLL_GetVidResResizeModeCfg_Rsp)
    BODY(nv::nv, )


    /*
    * key : emNv_Cfg_IsMtDualLeft
    */
    MESSAGE(Ev_NV_BLL_SetIsMtDualLeftCfg_Cmd)
    BODY(nv::nv, )

    MESSAGE(Ev_NV_BLL_SetIsMtDualLeftCfg_Ntf)
    BODY(nv::nv, )

    MESSAGE(Ev_NV_BLL_GetIsMtDualLeftCfg_Req)

    MESSAGE(Ev_NV_BLL_GetIsMtDualLeftCfg_Rsp)
    BODY(nv::nv, )


    /*
    * key : emNv_Cfg_IsUserCorrect
    */
    MESSAGE(Ev_NV_BLL_SetIsUserCorrectCfg_Cmd)
    BODY(nv::nv, )

    MESSAGE(Ev_NV_BLL_SetIsUserCorrectCfg_Ntf)
    BODY(nv::nv, )

    MESSAGE(Ev_NV_BLL_GetIsUserCorrectCfg_Req)

    MESSAGE(Ev_NV_BLL_GetIsUserCorrectCfg_Rsp)
    BODY(nv::nv, )


    /*
    * key : emNv_Cfg_TerPwd
    */
    MESSAGE(Ev_NV_BLL_SetTerPwdCfg_Cmd)
    BODY(nv::TString, )

    MESSAGE(Ev_NV_BLL_SetTerPwdCfg_Ntf)
    BODY(nv::TString, )

    MESSAGE(Ev_NV_BLL_GetTerPwdCfg_Req)

    MESSAGE(Ev_NV_BLL_GetTerPwdCfg_Rsp)
    BODY(nv::TString, )


    /*
    * key : emNv_Cfg_ReStartImix
    */
    MESSAGE(Ev_NV_BLL_SetReStartImixCfg_Cmd)
    BODY(nv::nv, )

    MESSAGE(Ev_NV_BLL_SetReStartImixCfg_Ntf)
    BODY(nv::nv, )

    MESSAGE(Ev_NV_BLL_GetReStartImixCfg_Req)

    MESSAGE(Ev_NV_BLL_GetReStartImixCfg_Rsp)
    BODY(nv::nv, )


    /*
    * key : emNv_Rt_SysCtrlSrvInfo
    */
    MESSAGE(Ev_NV_BLL_SetSysCtrlSrvInfoRt_Ntf)
    BODY(nv::TNVMutiTServiceInfoRtData, )

    MESSAGE(Ev_NV_BLL_GetSysCtrlSrvInfoRt_Req)

    MESSAGE(Ev_NV_BLL_GetSysCtrlSrvInfoRt_Rsp)
    BODY(nv::TNVMutiTServiceInfoRtData, )


    /*
    * key : emNv_Rt_SysCtrlSrvNum
    */
    MESSAGE(Ev_NV_BLL_SetSysCtrlSrvNumRt_Ntf)
    BODY(nv::TU32, )

    MESSAGE(Ev_NV_BLL_GetSysCtrlSrvNumRt_Req)

    MESSAGE(Ev_NV_BLL_GetSysCtrlSrvNumRt_Rsp)
    BODY(nv::TU32, )


    /*
    * key : emNv_Rt_TerlInfo
    */
    MESSAGE(Ev_NV_BLL_SetTerlInfoRt_Ntf)
    BODY(nv::TNVTerminalInfo, )

    MESSAGE(Ev_NV_BLL_GetTerlInfoRt_Req)

    MESSAGE(Ev_NV_BLL_GetTerlInfoRt_Rsp)
    BODY(nv::TNVTerminalInfo, )


    /*
    * key : emNv_Rt_SysUpgrade
    */
    MESSAGE(Ev_NV_BLL_SetSysUpgradeRt_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_GetSysUpgradeRt_Req)

    MESSAGE(Ev_NV_BLL_GetSysUpgradeRt_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emNv_Rt_CallState
    */
    MESSAGE(Ev_NV_BLL_SetCallStateRt_Ntf)
    BODY(nv::TS32, )

    MESSAGE(Ev_NV_BLL_GetCallStateRt_Req)

    MESSAGE(Ev_NV_BLL_GetCallStateRt_Rsp)
    BODY(nv::TS32, )


    /*
    * key : emNv_Rt_IsSleep
    */
    MESSAGE(Ev_NV_BLL_SetIsSleepRt_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_GetIsSleepRt_Req)

    MESSAGE(Ev_NV_BLL_GetIsSleepRt_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emNv_Rt_IsSendDual
    */
    MESSAGE(Ev_NV_BLL_SetIsSendDualRt_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_GetIsSendDualRt_Req)

    MESSAGE(Ev_NV_BLL_GetIsSendDualRt_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emNv_Rt_IsRcvDual
    */
    MESSAGE(Ev_NV_BLL_SetIsRcvDualRt_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_GetIsRcvDualRt_Req)

    MESSAGE(Ev_NV_BLL_GetIsRcvDualRt_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emNv_Rt_IsLoginMt
    */
    MESSAGE(Ev_NV_BLL_SetIsLoginMtRt_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_GetIsLoginMtRt_Req)

    MESSAGE(Ev_NV_BLL_GetIsLoginMtRt_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emNv_Rt_CodecStatistic
    */
    MESSAGE(Ev_NV_BLL_SetCodecStatisticRt_Ntf)
    BODY(nv::TNVCodecStatistic, )

    MESSAGE(Ev_NV_BLL_GetCodecStatisticRt_Req)

    MESSAGE(Ev_NV_BLL_GetCodecStatisticRt_Rsp)
    BODY(nv::TNVCodecStatistic, )


    /*
    * key : emNv_Rt_IsMute
    */
    MESSAGE(Ev_NV_BLL_SetIsMuteRt_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_GetIsMuteRt_Req)

    MESSAGE(Ev_NV_BLL_GetIsMuteRt_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emNv_Rt_QuickShareLoginInfo
    */
    MESSAGE(Ev_NV_BLL_SetQuickShareLoginInfoRt_Ntf)
    BODY(nv::TNVLoginInfos, )

    MESSAGE(Ev_NV_BLL_GetQuickShareLoginInfoRt_Req)

    MESSAGE(Ev_NV_BLL_GetQuickShareLoginInfoRt_Rsp)
    BODY(nv::TNVLoginInfos, )


    /*
    * key : emNv_Rt_ImixVidSrcSignal
    */
    MESSAGE(Ev_NV_BLL_SetImixVidSrcSignalRt_Ntf)
    BODY(nv::TNVImixVidSrcSignalList, )

    MESSAGE(Ev_NV_BLL_GetImixVidSrcSignalRt_Req)

    MESSAGE(Ev_NV_BLL_GetImixVidSrcSignalRt_Rsp)
    BODY(nv::TNVImixVidSrcSignalList, )


    /*
    * key : emNv_Rt_IsQuite
    */
    MESSAGE(Ev_NV_BLL_SetIsQuiteRt_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_GetIsQuiteRt_Req)

    MESSAGE(Ev_NV_BLL_GetIsQuiteRt_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emNv_Rt_IsPowerTurnOff
    */
    MESSAGE(Ev_NV_BLL_SetIsPowerTurnOffRt_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_GetIsPowerTurnOffRt_Req)

    MESSAGE(Ev_NV_BLL_GetIsPowerTurnOffRt_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emNv_Rt_IsSharing
    */
    MESSAGE(Ev_NV_BLL_SetIsSharingRt_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_GetIsSharingRt_Req)

    MESSAGE(Ev_NV_BLL_GetIsSharingRt_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emNv_Rt_ImixVidSrcStatus
    */
    MESSAGE(Ev_NV_BLL_SetImixVidSrcStatusRt_Ntf)
    BODY(nv::TNVVidInPortResInfoList, )

    MESSAGE(Ev_NV_BLL_GetImixVidSrcStatusRt_Req)

    MESSAGE(Ev_NV_BLL_GetImixVidSrcStatusRt_Rsp)
    BODY(nv::TNVVidInPortResInfoList, )


    /*
    * key : emNv_Rt_NetUsedInfo
    */
    MESSAGE(Ev_NV_BLL_SetNetUsedInfoRt_Ntf)
    BODY(nv::UnknownProtoMsg, )

    MESSAGE(Ev_NV_BLL_GetNetUsedInfoRt_Req)

    MESSAGE(Ev_NV_BLL_GetNetUsedInfoRt_Rsp)
    BODY(nv::UnknownProtoMsg, )


    /*
    * key : emNv_Rt_IsLocalSharing
    */
    MESSAGE(Ev_NV_BLL_SetIsLocalSharingRt_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_GetIsLocalSharingRt_Req)

    MESSAGE(Ev_NV_BLL_GetIsLocalSharingRt_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emNv_Rt_IsPowerUpgrade
    */
    MESSAGE(Ev_NV_BLL_SetIsPowerUpgradeRt_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_GetIsPowerUpgradeRt_Req)

    MESSAGE(Ev_NV_BLL_GetIsPowerUpgradeRt_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emNv_Rt_IsCheckResult
    */
    MESSAGE(Ev_NV_BLL_SetIsCheckResultRt_Ntf)
    BODY(nv::TS32, )

    MESSAGE(Ev_NV_BLL_GetIsCheckResultRt_Req)

    MESSAGE(Ev_NV_BLL_GetIsCheckResultRt_Rsp)
    BODY(nv::TS32, )


    /*
    * key : emNv_Rt_IsCheckTpad
    */
    MESSAGE(Ev_NV_BLL_SetIsCheckTpadRt_Ntf)
    BODY(nv::TNVDevUpgrade, )

    MESSAGE(Ev_NV_BLL_GetIsCheckTpadRt_Req)

    MESSAGE(Ev_NV_BLL_GetIsCheckTpadRt_Rsp)
    BODY(nv::TNVDevUpgrade, )


    /*
    * key : emNv_Rt_IsOpenFtp
    */
    MESSAGE(Ev_NV_BLL_SetIsOpenFtpRt_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_GetIsOpenFtpRt_Req)

    MESSAGE(Ev_NV_BLL_GetIsOpenFtpRt_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emNv_Rt_FtpLoginInfo
    */
    MESSAGE(Ev_NV_BLL_SetFtpLoginInfoRt_Ntf)
    BODY(nv::TNVFtpLoginInfos, )

    MESSAGE(Ev_NV_BLL_GetFtpLoginInfoRt_Req)

    MESSAGE(Ev_NV_BLL_GetFtpLoginInfoRt_Rsp)
    BODY(nv::TNVFtpLoginInfos, )


    /*
    * key : emNv_Rt_PlayZoomMode
    */
    MESSAGE(Ev_NV_BLL_SetPlayZoomModeRt_Ntf)
    BODY(nv::TS32, )

    MESSAGE(Ev_NV_BLL_GetPlayZoomModeRt_Req)

    MESSAGE(Ev_NV_BLL_GetPlayZoomModeRt_Rsp)
    BODY(nv::TS32, )


    /*
    * key : emNv_Rt_MiniVidInfo
    */
    MESSAGE(Ev_NV_BLL_SetMiniVidInfoRt_Ntf)
    BODY(nv::TNVMiniVidInfo, )

    MESSAGE(Ev_NV_BLL_GetMiniVidInfoRt_Req)

    MESSAGE(Ev_NV_BLL_GetMiniVidInfoRt_Rsp)
    BODY(nv::TNVMiniVidInfo, )


    /*
    * key : emNv_Rt_ImixVerInfo
    */
    MESSAGE(Ev_NV_BLL_SetImixVerInfoRt_Ntf)
    BODY(nv::TNVImixVerInfo, )

    MESSAGE(Ev_NV_BLL_GetImixVerInfoRt_Req)

    MESSAGE(Ev_NV_BLL_GetImixVerInfoRt_Rsp)
    BODY(nv::TNVImixVerInfo, )


    /*
    * key : emNv_Rt_MtInfo
    */
    MESSAGE(Ev_NV_BLL_SetMtInfoRt_Ntf)
    BODY(nv::TNVMtInfo, )

    MESSAGE(Ev_NV_BLL_GetMtInfoRt_Req)

    MESSAGE(Ev_NV_BLL_GetMtInfoRt_Rsp)
    BODY(nv::TNVMtInfo, )


    /*
    * key : emNv_Rt_AppUpgrade
    */
    MESSAGE(Ev_NV_BLL_SetAppUpgradeRt_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_GetAppUpgradeRt_Req)

    MESSAGE(Ev_NV_BLL_GetAppUpgradeRt_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emNv_Rt_QkUpgrade
    */
    MESSAGE(Ev_NV_BLL_SetQkUpgradeRt_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_GetQkUpgradeRt_Req)

    MESSAGE(Ev_NV_BLL_GetQkUpgradeRt_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emNv_Rt_IsToolbarLogin
    */
    MESSAGE(Ev_NV_BLL_SetIsToolbarLoginRt_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_GetIsToolbarLoginRt_Req)

    MESSAGE(Ev_NV_BLL_GetIsToolbarLoginRt_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emNv_Rt_PadIsDown
    */
    MESSAGE(Ev_NV_BLL_SetPadIsDownRt_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_GetPadIsDownRt_Req)

    MESSAGE(Ev_NV_BLL_GetPadIsDownRt_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emNv_Rt_PadLoginInfo
    */
    MESSAGE(Ev_NV_BLL_SetPadLoginInfoRt_Ntf)
    BODY(nv::TNVPadLoginInfos, )

    MESSAGE(Ev_NV_BLL_GetPadLoginInfoRt_Req)

    MESSAGE(Ev_NV_BLL_GetPadLoginInfoRt_Rsp)
    BODY(nv::TNVPadLoginInfos, )


    /*
    * key : emNv_Rt_RouterIsDown
    */
    MESSAGE(Ev_NV_BLL_SetRouterIsDownRt_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_GetRouterIsDownRt_Req)

    MESSAGE(Ev_NV_BLL_GetRouterIsDownRt_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emNv_Rt_TerminalName
    */
    MESSAGE(Ev_NV_BLL_SetTerminalNameRt_Ntf)
    BODY(nv::TNVTerminalName, )

    MESSAGE(Ev_NV_BLL_GetTerminalNameRt_Req)

    MESSAGE(Ev_NV_BLL_GetTerminalNameRt_Rsp)
    BODY(nv::TNVTerminalName, )


    /*
    * key : emHD_Cfg_EthnetCfg
    */
    MESSAGE(Ev_NV_BLL_HD_SetEthnetCfgCfg_Cmd)
    BODY(nv::TNVEthnetCfg, )

    MESSAGE(Ev_NV_BLL_HD_SetEthnetCfgCfg_Ntf)
    BODY(nv::TNVEthnetCfg, )

    MESSAGE(Ev_NV_BLL_HD_GetEthnetCfgCfg_Req)

    MESSAGE(Ev_NV_BLL_HD_GetEthnetCfgCfg_Rsp)
    BODY(nv::TNVEthnetCfg, )


    /*
    * key : emHD_Cfg_LastDisplay
    */
    MESSAGE(Ev_NV_BLL_HD_SetLastDisplayCfg_Cmd)
    BODY(nv::TNVLastDisplay, )

    MESSAGE(Ev_NV_BLL_HD_SetLastDisplayCfg_Ntf)
    BODY(nv::TNVLastDisplay, )

    MESSAGE(Ev_NV_BLL_HD_GetLastDisplayCfg_Req)

    MESSAGE(Ev_NV_BLL_HD_GetLastDisplayCfg_Rsp)
    BODY(nv::TNVLastDisplay, )


    /*
    * key : emHD_Cfg_HdmiSwitch
    */
    MESSAGE(Ev_NV_BLL_HD_SetHdmiSwitchCfg_Cmd)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_HD_SetHdmiSwitchCfg_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_HD_GetHdmiSwitchCfg_Req)

    MESSAGE(Ev_NV_BLL_HD_GetHdmiSwitchCfg_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emHD_Rt_AppRunInfo
    */
    MESSAGE(Ev_NV_BLL_HD_SetAppRunInfoRt_Ntf)
    BODY(nv::TNVMutiTServiceInfoRtData, )

    MESSAGE(Ev_NV_BLL_HD_GetAppRunInfoRt_Req)

    MESSAGE(Ev_NV_BLL_HD_GetAppRunInfoRt_Rsp)
    BODY(nv::TNVMutiTServiceInfoRtData, )


    /*
    * key : emHD_Rt_IsWifi
    */
    MESSAGE(Ev_NV_BLL_HD_SetIsWifiRt_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_HD_GetIsWifiRt_Req)

    MESSAGE(Ev_NV_BLL_HD_GetIsWifiRt_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emHD_Rt_AutoUpgrade
    */
    MESSAGE(Ev_NV_BLL_HD_SetAutoUpgradeRt_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_HD_GetAutoUpgradeRt_Req)

    MESSAGE(Ev_NV_BLL_HD_GetAutoUpgradeRt_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emHD_Rt_IsMfgTest
    */
    MESSAGE(Ev_NV_BLL_HD_SetIsMfgTestRt_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_HD_GetIsMfgTestRt_Req)

    MESSAGE(Ev_NV_BLL_HD_GetIsMfgTestRt_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emHD_Rt_NetCaping
    */
    MESSAGE(Ev_NV_BLL_HD_SetNetCapingRt_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_HD_GetNetCapingRt_Req)

    MESSAGE(Ev_NV_BLL_HD_GetNetCapingRt_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emHD_Rt_BrdInfo
    */
    MESSAGE(Ev_NV_BLL_HD_SetBrdInfoRt_Ntf)
    BODY(nv::TNVBrdInfo, )

    MESSAGE(Ev_NV_BLL_HD_GetBrdInfoRt_Req)

    MESSAGE(Ev_NV_BLL_HD_GetBrdInfoRt_Rsp)
    BODY(nv::TNVBrdInfo, )


    /*
    * key : emHD_Rt_UsbStatus
    */
    MESSAGE(Ev_NV_BLL_HD_SetUsbStatusRt_Ntf)
    BODY(nv::TNVUsbStatus, )

    MESSAGE(Ev_NV_BLL_HD_GetUsbStatusRt_Req)

    MESSAGE(Ev_NV_BLL_HD_GetUsbStatusRt_Rsp)
    BODY(nv::TNVUsbStatus, )


    /*
    * key : emHD_Rt_SnapExporting
    */
    MESSAGE(Ev_NV_BLL_HD_SetSnapExportingRt_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_HD_GetSnapExportingRt_Req)

    MESSAGE(Ev_NV_BLL_HD_GetSnapExportingRt_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emHD_Rt_EthnetCurIp
    */
    MESSAGE(Ev_NV_BLL_HD_SetEthnetCurIpRt_Ntf)
    BODY(nv::TU32, )

    MESSAGE(Ev_NV_BLL_HD_GetEthnetCurIpRt_Req)

    MESSAGE(Ev_NV_BLL_HD_GetEthnetCurIpRt_Rsp)
    BODY(nv::TU32, )


    /*
    * key : emHD_Rt_Is1080PVer
    */
    MESSAGE(Ev_NV_BLL_HD_SetIs1080PVerRt_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_HD_GetIs1080PVerRt_Req)

    MESSAGE(Ev_NV_BLL_HD_GetIs1080PVerRt_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emHD_Rt_IsOpenMiniVid
    */
    MESSAGE(Ev_NV_BLL_HD_SetIsOpenMiniVidRt_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_HD_GetIsOpenMiniVidRt_Req)

    MESSAGE(Ev_NV_BLL_HD_GetIsOpenMiniVidRt_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emQK_Cfg_VersionInfo
    */
    MESSAGE(Ev_NV_BLL_QK_SetVersionInfoCfg_Cmd)
    BODY(nv::TString, )

    MESSAGE(Ev_NV_BLL_QK_SetVersionInfoCfg_Ntf)
    BODY(nv::TString, )

    MESSAGE(Ev_NV_BLL_QK_GetVersionInfoCfg_Req)

    MESSAGE(Ev_NV_BLL_QK_GetVersionInfoCfg_Rsp)
    BODY(nv::TString, )


    /*
    * key : emQK_Cfg_IsUpgradeFileDownloadFinish
    */
    MESSAGE(Ev_NV_BLL_QK_SetIsUpgradeFileDownloadFinishCfg_Cmd)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_QK_SetIsUpgradeFileDownloadFinishCfg_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_QK_GetIsUpgradeFileDownloadFinishCfg_Req)

    MESSAGE(Ev_NV_BLL_QK_GetIsUpgradeFileDownloadFinishCfg_Rsp)
    BODY(nv::TBOOL32, )


    /*
    * key : emQK_Cfg_IsUpgradeFinish
    */
    MESSAGE(Ev_NV_BLL_QK_SetIsUpgradeFinishCfg_Cmd)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_QK_SetIsUpgradeFinishCfg_Ntf)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_BLL_QK_GetIsUpgradeFinishCfg_Req)

    MESSAGE(Ev_NV_BLL_QK_GetIsUpgradeFinishCfg_Rsp)
    BODY(nv::TBOOL32, )



#if !defined(_MESSAGE_HELP_)
     EV_BLL_END(CONFIG) = EVSEG_BLL_CONFIG_END
};
#endif

#define Is_BLL_NvConfig_Msg(m) ((m) >= EV_BLL_BGN(CONFIG) && (m) <= EV_BLL_END(CONFIG))

#endif //_NV_BLL_CONFIG_MSG_H_

