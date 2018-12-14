#ifndef _NV_CONFIG_MSG_H_
#define _NV_CONFIG_MSG_H_
///////////////////////////////////////////////////////////////
//默认 配置消息 定义
///////////////////////////////////////////////////////////////
//脚本 gen_cfg_files 根据 nvdskey.h 自动生成,请勿手动修改
///////////////////////////////////////////////////////////////
//自定义 配置消息 定义，请在nvconfigexmsg.h添加，并增加Set/Get消息处理函数
///////////////////////////////////////////////////////////////

#include "nvmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmNvConfigMsg
{
    EV_BGN(CONFIG) = EVSEG_CONFIG_BGN,
#endif


    /*
    * key : emNv_Cfg_Port
    */
    MESSAGE(Ev_NV_SetPortCfg_Cmd)
    BODY(nv::TNvPortCfg, )

    MESSAGE(Ev_NV_SetPortCfg_Ntf)
    BODY(nv::TNvPortCfg, )


    /*
    * key : emNv_Cfg_SysCtrlDefSrvInfo
    */
    MESSAGE(Ev_NV_SetSysCtrlDefSrvInfoCfg_Cmd)
    BODY(nv::TNVMutiTServiceDefInfo, )

    MESSAGE(Ev_NV_SetSysCtrlDefSrvInfoCfg_Ntf)
    BODY(nv::TNVMutiTServiceDefInfo, )


    /*
    * key : emNv_Cfg_SysCtrlDefSrvNum
    */
    MESSAGE(Ev_NV_SetSysCtrlDefSrvNumCfg_Cmd)
    BODY(nv::TU32, )

    MESSAGE(Ev_NV_SetSysCtrlDefSrvNumCfg_Ntf)
    BODY(nv::TU32, )


    /*
    * key : emNv_Cfg_SUS
    */
    MESSAGE(Ev_NV_SetSUSCfg_Cmd)
    BODY(nv::TNVSUSAddr, )

    MESSAGE(Ev_NV_SetSUSCfg_Ntf)
    BODY(nv::TNVSUSAddr, )


    /*
    * key : emNv_Cfg_TerIp
    */
    MESSAGE(Ev_NV_SetTerIpCfg_Cmd)
    BODY(nv::TString, )

    MESSAGE(Ev_NV_SetTerIpCfg_Ntf)
    BODY(nv::TString, )


    /*
    * key : emNv_Cfg_ImixIp
    */
    MESSAGE(Ev_NV_SetImixIpCfg_Cmd)
    BODY(nv::TNVNetUsedInfo, )

    MESSAGE(Ev_NV_SetImixIpCfg_Ntf)
    BODY(nv::TNVNetUsedInfo, )


    /*
    * key : emNv_Cfg_LogSerIp
    */
    MESSAGE(Ev_NV_SetLogSerIpCfg_Cmd)
    BODY(nv::TString, )

    MESSAGE(Ev_NV_SetLogSerIpCfg_Ntf)
    BODY(nv::TString, )


    /*
    * key : emNv_Cfg_EmailSerIp
    */
    MESSAGE(Ev_NV_SetEmailSerIpCfg_Cmd)
    BODY(nv::TString, )

    MESSAGE(Ev_NV_SetEmailSerIpCfg_Ntf)
    BODY(nv::TString, )


    /*
    * key : emNv_Cfg_Log
    */
    MESSAGE(Ev_NV_SetLogCfg_Cmd)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_SetLogCfg_Ntf)
    BODY(nv::TBOOL32, )


    /*
    * key : emNv_Cfg_TimeZone
    */
    MESSAGE(Ev_NV_SetTimeZoneCfg_Cmd)
    BODY(nv::TS32, )

    MESSAGE(Ev_NV_SetTimeZoneCfg_Ntf)
    BODY(nv::TS32, )


    /*
    * key : emNv_Cfg_Screen
    */
    MESSAGE(Ev_NV_SetScreenCfg_Cmd)
    BODY(nv::TNVScreenParamList, )

    MESSAGE(Ev_NV_SetScreenCfg_Ntf)
    BODY(nv::TNVScreenParamList, )


    /*
    * key : emNv_Cfg_ScreenNum
    */
    MESSAGE(Ev_NV_SetScreenNumCfg_Cmd)
    BODY(nv::TU32, )

    MESSAGE(Ev_NV_SetScreenNumCfg_Ntf)
    BODY(nv::TU32, )


    /*
    * key : emNv_Cfg_BackstageUpgrade
    */
    MESSAGE(Ev_NV_SetBackstageUpgradeCfg_Cmd)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_SetBackstageUpgradeCfg_Ntf)
    BODY(nv::TBOOL32, )


    /*
    * key : emNv_Cfg_QuickShareVersionInfo
    */
    MESSAGE(Ev_NV_SetQuickShareVersionInfoCfg_Cmd)
    BODY(nv::TNVDevUpgrade, )

    MESSAGE(Ev_NV_SetQuickShareVersionInfoCfg_Ntf)
    BODY(nv::TNVDevUpgrade, )


    /*
    * key : emNv_Cfg_ImixVersionInfo
    */
    MESSAGE(Ev_NV_SetImixVersionInfoCfg_Cmd)
    BODY(nv::TNVDevUpgrade, )

    MESSAGE(Ev_NV_SetImixVersionInfoCfg_Ntf)
    BODY(nv::TNVDevUpgrade, )


    /*
    * key : emNv_Cfg_IsUpgradeFileDownloadFinish
    */
    MESSAGE(Ev_NV_SetIsUpgradeFileDownloadFinishCfg_Cmd)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_SetIsUpgradeFileDownloadFinishCfg_Ntf)
    BODY(nv::TBOOL32, )


    /*
    * key : emNv_Cfg_IsUpgradeFinish
    */
    MESSAGE(Ev_NV_SetIsUpgradeFinishCfg_Cmd)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_NV_SetIsUpgradeFinishCfg_Ntf)
    BODY(nv::TBOOL32, )


    /*
    * key : emNv_Cfg_PreCheckUpgradeInfo
    */
    MESSAGE(Ev_NV_SetPreCheckUpgradeInfoCfg_Cmd)
    BODY(nv::TNVUpgradeClientInfo, )

    MESSAGE(Ev_NV_SetPreCheckUpgradeInfoCfg_Ntf)
    BODY(nv::TNVUpgradeClientInfo, )


    /*
    * key : emNv_Cfg_CodecAudOutVol
    */
    MESSAGE(Ev_NV_SetCodecAudOutVolCfg_Cmd)
    BODY(nv::nv, )

    MESSAGE(Ev_NV_SetCodecAudOutVolCfg_Ntf)
    BODY(nv::nv, )


    /*
    * key : emNv_Cfg_CodecQuiet
    */
    MESSAGE(Ev_NV_SetCodecQuietCfg_Cmd)
    BODY(nv::nv, )

    MESSAGE(Ev_NV_SetCodecQuietCfg_Ntf)
    BODY(nv::nv, )


    /*
    * key : emNv_Cfg_IsFullScreen
    */
    MESSAGE(Ev_NV_SetIsFullScreenCfg_Cmd)
    BODY(nv::nv, )

    MESSAGE(Ev_NV_SetIsFullScreenCfg_Ntf)
    BODY(nv::nv, )


    /*
    * key : emNv_Cfg_VidResResizeMode
    */
    MESSAGE(Ev_NV_SetVidResResizeModeCfg_Cmd)
    BODY(nv::nv, )

    MESSAGE(Ev_NV_SetVidResResizeModeCfg_Ntf)
    BODY(nv::nv, )


    /*
    * key : emNv_Cfg_IsMtDualLeft
    */
    MESSAGE(Ev_NV_SetIsMtDualLeftCfg_Cmd)
    BODY(nv::nv, )

    MESSAGE(Ev_NV_SetIsMtDualLeftCfg_Ntf)
    BODY(nv::nv, )


    /*
    * key : emNv_Cfg_IsUserCorrect
    */
    MESSAGE(Ev_NV_SetIsUserCorrectCfg_Cmd)
    BODY(nv::nv, )

    MESSAGE(Ev_NV_SetIsUserCorrectCfg_Ntf)
    BODY(nv::nv, )


    /*
    * key : emNv_Cfg_TerPwd
    */
    MESSAGE(Ev_NV_SetTerPwdCfg_Cmd)
    BODY(nv::TString, )

    MESSAGE(Ev_NV_SetTerPwdCfg_Ntf)
    BODY(nv::TString, )


    /*
    * key : emNv_Cfg_ReStartImix
    */
    MESSAGE(Ev_NV_SetReStartImixCfg_Cmd)
    BODY(nv::nv, )

    MESSAGE(Ev_NV_SetReStartImixCfg_Ntf)
    BODY(nv::nv, )


    /*
    * key : emHD_Cfg_EthnetCfg
    */
    MESSAGE(Ev_HD_SetEthnetCfgCfg_Cmd)
    BODY(nv::TNVEthnetCfg, )

    MESSAGE(Ev_HD_SetEthnetCfgCfg_Ntf)
    BODY(nv::TNVEthnetCfg, )


    /*
    * key : emHD_Cfg_LastDisplay
    */
    MESSAGE(Ev_HD_SetLastDisplayCfg_Cmd)
    BODY(nv::TNVLastDisplay, )

    MESSAGE(Ev_HD_SetLastDisplayCfg_Ntf)
    BODY(nv::TNVLastDisplay, )


    /*
    * key : emHD_Cfg_HdmiSwitch
    */
    MESSAGE(Ev_HD_SetHdmiSwitchCfg_Cmd)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_HD_SetHdmiSwitchCfg_Ntf)
    BODY(nv::TBOOL32, )


    /*
    * key : emQK_Cfg_VersionInfo
    */
    MESSAGE(Ev_QK_SetVersionInfoCfg_Cmd)
    BODY(nv::TString, )

    MESSAGE(Ev_QK_SetVersionInfoCfg_Ntf)
    BODY(nv::TString, )


    /*
    * key : emQK_Cfg_IsUpgradeFileDownloadFinish
    */
    MESSAGE(Ev_QK_SetIsUpgradeFileDownloadFinishCfg_Cmd)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_QK_SetIsUpgradeFileDownloadFinishCfg_Ntf)
    BODY(nv::TBOOL32, )


    /*
    * key : emQK_Cfg_IsUpgradeFinish
    */
    MESSAGE(Ev_QK_SetIsUpgradeFinishCfg_Cmd)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_QK_SetIsUpgradeFinishCfg_Ntf)
    BODY(nv::TBOOL32, )

	/*
    * key : emNv_Cfg_IsOpenAmplifier
    */
    MESSAGE(Ev_Nv_SetIsOpenAmplifier_Cmd)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_Nv_SetIsOpenAmplifier_Ntf)
    BODY(nv::TBOOL32, )

	/*
    * key : emNv_Cfg_IsLocalEcho
    */
    MESSAGE(Ev_Nv_SetIsLocalEcho_Cmd)
    BODY(nv::TBOOL32, )

    MESSAGE(Ev_Nv_SetIsLocalEcho_Ntf)
    BODY(nv::TBOOL32, )



#if !defined(_MESSAGE_HELP_)
     EV_END(CONFIG) = EVSEG_CONFIG_END
};
#endif

#define Is_NvConfig_Msg(m) ((m) >= EV_BGN(CONFIG) && (m) <= EV_END(CONFIG))

#endif //_NV_CONFIG_MSG_H_

