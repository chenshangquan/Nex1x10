/**===========================================================================
 * @file    $Id$
 * @brief   负责终端网管功能的接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_NVTERCTRL_H_
#define _I_NVTERCTRL_H_

#include "nvapi_typedef.h"
#include "nvapi_if.h"
#include "nvapi_event_base.h"




/**---------------------------------------------------------------------------
 * @class   Interface INvTerCtrl
 * @brief   负责终端通用功能的接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class INvTerCtrl : public INvApiIF
{
public:

	virtual u32 GetAssSndSreamStatusReq( ) = 0;
	virtual u32 GetAssRcvSreamStatusReq( ) = 0;
	virtual u32 GetCallLinkStateReq( ) = 0;
	virtual u32 GetMTCLoginStateReq( ) = 0;
	virtual u32 VideoAssStreamCmd( const nv::TBOOL32 tbStart ) = 0;
	virtual u32 GetAnswerModeReq() = 0;
	virtual u32 GetTerminalNameReq() = 0;
	virtual u32 InquireHDMtStartSucess() = 0;
	virtual u32 SendLocalSmsCmd( const nv::TString tSms) = 0;
	virtual u32 SetTerNatIp( const nv::TBOOL32 tbNatEnable, const nv::TString tNatIp) = 0;
	virtual u32 SetTerAutoSleepCmd( const nv::TNVMtAutoSleepCfg tAutoSleep) = 0;
	virtual u32 GetTerAutoSleepReq() = 0;
	virtual u32 ResetTerCfgCmd(const nv::TBOOL32 tDelCfg) = 0;
	virtual u32 SetTerTimeCfgCmd(const nv::TNVCfgMtSystemTime tCfg) = 0;
	virtual u32 SetTerSysTimeDataReq(const nv::TNVTime tTime) = 0;
	virtual u32 GetTerIpReq() = 0;
	virtual u32 GetTerHWInfoCmd() = 0;
	virtual u32 SetTerLocalSoundPlayCmd(const nv::TNVMtLocalSoundPaly tSoundPlay) = 0;
	virtual u32 TerAudioOutPowerTestCmd(const nv::TNVMtAudioTestCfg tCfg) = 0;
	virtual u32 TerAudioInPowerTestCmd(const nv::TNVMtAudioTestCfg tCfg) = 0;
	virtual u32 TerAudioInputStateReq(const nv::TNVMtMutiAudInState  tState) = 0;
	virtual u32 GetLoginApsParamCfgReq() = 0;
	virtual u32 GetCallProtocolCfgReq() = 0;
	virtual u32 GetXAPListCfgReq() = 0;
	virtual u32 GetH323PxyCfgReq() = 0;
	virtual u32 GetGKCfgReq() = 0;
	virtual u32 GetManuSipSvrCfgReq() = 0;
	virtual u32 GetLoginPlatformSrvCfgReq() = 0;
	virtual u32 GetForceH323StackCfgReq() = 0;
	virtual u32 GetAccountInfoReq(const nv::TNVMtAccountManager tInfo) = 0;
	virtual u32 SetTerminalNameCfgCmd(const nv::TNVTerminalName tInfo) = 0;
	virtual u32 SetTerLoginPlatformSrvCfgCmd(const nv::TBOOL32 tInfo) = 0;
	virtual u32 SetLoginApsParamCfgCmd(const nv::TNVApsLoginParam tInfo) = 0;
	virtual u32 ForceSetH323StackCfgCmd(const nv::TNVForceSetH323Stack tInfo) = 0;
	virtual u32 SetXAPListCfgCmd(const nv::TNVMtXAPSvrList tInfo) = 0;
	virtual u32 SetH323PxyCfgCmd(const nv::TNVH323PxyCfg tInfo) = 0;
	virtual u32 SetH460CfgCmd(const nv::TNVH460PxyCfg tInfo) = 0;
	virtual u32 GetH460CfgReq() = 0;
	virtual u32 SetSipSvrCfgCmd(const nv::TNVSipSrvCfg tInfo) = 0;
	virtual u32 GetAudInPortListCfgReq() = 0;
	virtual u32 AutoAudioDelayCheckCmd(const nv::TBOOL32 tInfo) = 0;
	virtual u32 GetCallBitRateCfgReq() = 0;
	virtual u32 SetCallBitRateCfgCmd(const nv::TU32 tInfo) = 0;
	virtual u32 GetSvrStateListReq( ) = 0;
	virtual u32 SetCSUCfgCmd(const nv::TNVMtCSUAddr tInfo) = 0;
	virtual u32 GetTerSdiInOutReq( ) = 0;
	virtual u32 GetMicrophoneConnectStatusReq( ) = 0;
	virtual u32 GetPri1stVidInPortCfgReq( ) = 0;
	virtual u32 GetAssVidInPortCfgReq( ) = 0;
	virtual u32 GetPri2ndVidInPortCfgReq( ) = 0;
	virtual u32 SetAudInPortListCfgCmd(const nv::TNVMtAudInPortList tInfo) = 0;
	virtual u32 SetWizardResultCmd( ) = 0;
	virtual u32 GetGKRegistRtReq( ) = 0;
	virtual u32 GetSipRegistRtReq( ) = 0;
	virtual u32 GetNvIsConnectTerReq( ) = 0;
	virtual u32 SetSkipTerWizardCmd( ) = 0;
	virtual u32 GetImixSerialNumReq( ) = 0;
public:

};

#endif // _I_NVCOMMON_H_