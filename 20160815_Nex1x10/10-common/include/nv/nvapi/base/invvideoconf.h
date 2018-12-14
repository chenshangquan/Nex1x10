/**===========================================================================
 * @file    $Id$
 * @brief   负责终端视频接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_NVVIDEOCONF_H_
#define _I_NVVIDEOCONF_H_

#include "nvapi_typedef.h"
#include "nvapi_if.h"
#include "nvapi_event_base.h"




/**---------------------------------------------------------------------------
 * @class   Interface INvVideoConf
 * @brief   负责终端通用功能的接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class INvVideoConf : public INvApiIF
{
public:
	virtual u32 ViewPicCmd( IN CONST nv::TS32 &tPic ) = 0;
	virtual u32 GetPicReq(  ) = 0;
	virtual u32 SendPCNameCmd(IN CONST s8 *pch, IN CONST s8 *pVision) = 0;
	virtual u32 SendInputEventCmd(IN CONST nv::TNVInputEvents &tInput) = 0;
	virtual u32 SendQuickShareSendAddrCmd(IN CONST nv::TNVRtpRtcpPair &tVidAddr, IN CONST nv::TNVRtpRtcpPair &tAudAddr) = 0;
	virtual u32 QuickShareViewPicCmd() = 0;
	virtual u32 QuickShareViewPicStopCmd() = 0;
	virtual u32 QuickShareCheckUpgradeCmd() = 0;
	virtual u32 GetNvmpVidSrcStatusReq(IN CONST nv::TBOOL32 tbTest) = 0;
	virtual u32 SetSharingOptionCmd(IN CONST nv::TBOOL32 tbCfg) = 0;
	virtual u32 GetShaingOptionCfgReq() = 0;
	virtual u32 CodecQuietCmd(IN CONST nv::TBOOL32 tbQuit) = 0;
	virtual u32 GetCodecQuietReq() = 0;
	virtual u32 CodecSetAudOutVolCmd(IN CONST nv::TU32 tbVol) = 0;
	virtual u32 CodecGetAudOutVolReq() = 0;
	virtual u32 SetFullScreenCmd(IN CONST nv::TBOOL32 tbFull) = 0;
	virtual u32 GetFullScreenReq() = 0;
	virtual u32 CodecSnapshotReq(IN CONST nv::TString tSnapName, IN CONST nv::TS32 tCodeId) = 0;
	virtual u32 CodecGetAllAudInPowerCmd() = 0;
	virtual u32 CodecRingPlay(IN CONST nv::TBOOL32 tbPlay) = 0;
	virtual u32 SetHdmiSwitchCmd(IN CONST nv::TBOOL32 tbUp, IN CONST BOOL32 bOnly) = 0;
	virtual u32 QKSendVidSrcStatusCmd(IN CONST nv::TNvVidSrcInfo tInfo) = 0;
	virtual u32 SetShowRectCmd(IN CONST nv::TBOOL32 tbMini) = 0;
	virtual u32 AnswerCallCmd(IN CONST nv::TBOOL32 tbAnswerCall) = 0;
	virtual u32 SetOutclrspaceCmd( IN CONST nv::TS32 tnYuv) = 0;
	virtual u32 GetMtPicReq( ) = 0;
	virtual u32 SetPlayZoomModeCmd( IN CONST nv::TS32 tnZoom) = 0;
	virtual u32 GetPlayZoomModeReq( ) = 0;
	virtual u32 SetVidFreezePrmCmd( IN CONST nv::TNVVidFreezePrm tFree) = 0;
	virtual u32 SetVidMiniVidCmd( IN CONST nv::TNVMiniVidInfo tInfo) = 0;
	virtual u32 GetMiniVidInfoReq( ) = 0;
	virtual u32 GetVidFreezePrmReq( ) = 0;
	virtual u32 NotifyImixNexTransmitterStateCmd( IN CONST nv::TBOOL32 tbNtState ) = 0;
	virtual u32 NotifyImixUDiskStateNty(IN CONST nv::TU32 tdwUDiskInx, IN CONST nv::TBOOL32 tbUDiskState ) = 0;
	virtual u32 ClearSrcTypeStateCmd(IN CONST nv::TNVClearSrcType tSrcType ) = 0; 
	virtual u32 DLNASrcStateNty(IN CONST nv::TBOOL32 tbIsHas ) = 0;
	virtual u32 SendPCStartPPTCmd( ) = 0;
	virtual u32 SendPCStopPPTCmd( ) = 0;
	virtual u32 QKNotifyHeartBeat( ) = 0;
	virtual u32 PPTPageTurningCmd(IN CONST nv::TS32 tPageTurning ) = 0;
	virtual u32 ViewWhiteBoardCmd(IN CONST nv::TBOOL32 tView ) = 0;
	virtual u32 NotifyIsShowGreenWin(IN CONST nv::TBOOL32 tShow ) = 0;
	virtual u32 LeaveSrceenDrawCmd( ) = 0;
	virtual u32 QkGetTerNameReq( ) = 0;
	virtual u32 QkCodecConsultResultNty(IN CONST nv::TBOOL32 tResult ) = 0;
	virtual u32 QkCodecResResultNty(IN CONST nv::TBOOL32 tResult ) = 0;
	virtual u32 QkCodecFrameResultNty(IN CONST nv::TBOOL32 tResult ) = 0;
	virtual u32 QkCodecBitRateResultNty(IN CONST nv::TBOOL32 tResult ) = 0;
	virtual u32 SetAmplifierStatusCmd(IN CONST nv::TBOOL32 tOpen ) = 0;
	virtual u32 SetImixLocalEchoCmd(IN CONST nv::TBOOL32 tOpen ) = 0;
public:

};

#endif // _I_NVVIDEOCONF_H_