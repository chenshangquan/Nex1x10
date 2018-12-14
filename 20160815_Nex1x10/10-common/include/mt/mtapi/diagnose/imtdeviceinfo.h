/**===========================================================================
 * @file    $Id$
 * @brief   ����MtDiagnoseApi�豸ͳ����ع��ܽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTDEVICEINFO_H_
#define _I_MTDEVICEINFO_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_diagnose.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtDeviceInfo
 * @brief   ����MtDiagnoseApi�ն��豸�����ع��ܽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class IMtDeviceInfo: public IMtApiIF
{
public:
	//��˷����
	virtual u32    AudioInPowerTestCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emStreamIdx, const BOOL32 bStart ) = 0;
	//���������
	virtual u32    AudioOutPowerTestCmd( const EmCodecComponent_Api emCodecType,const EmCodecComponentIndex_Api emStreamIdx, const BOOL32 bStart ) = 0;
	//���ػػ����ԣ���·
	virtual u32    SingleLocalLoopBackTestCmd( IN CONST BOOL32 bLoopBack, IN CONST EmCodecComponentIndex_Api emCodecId, EmCodecComponent_Api emCodecType ) = 0;
	//���ػػ�����
	virtual u32    LocalLoopBackTestCmd( IN CONST BOOL32 bLoopBack ) = 0;
	//ɫ������
	virtual u32    RibbonTestCmd( IN CONST BOOL32 bTest ) = 0;
	//�Զ�����ʱ�Ӽ������
	virtual u32 AutoAudioDelayCheckCmd( IN CONST BOOL32 bStart ) = 0;
	//�Ƿ���ɫ��������(��Embed)
	virtual BOOL32 IsInRibbonTesting() = 0;
	//Զ�˻ػ�
	virtual u32    RemoteLoopTestCmd( IN CONST BOOL32 bFarLoop ) = 0;

	//��ȡ��˷�����ֵ
	virtual TMTAudioPower_Api GetAudioInPower( ) = 0;
	//��ȡ����������ֵ
	virtual TMTAudioPower_Api GetAudioOutPower( ) = 0;

	//��Ƶ����������ѯ����
	virtual u32 AudioInVolumeReq( ) = 0;

	//��ȡ��Ƶ��������
	virtual u32 GetAudioInVolume( ) = 0;

	//��Ƶ����ӿ�״̬��ѯ����
	virtual u32 AudioInputStateReq( const TMultiAudInputState_Api & tAudInputState ) = 0;

	//��ȡ��Ƶ����ӿ�״̬
	virtual TMultiAudInputState_Api GetAudioInputState( ) = 0;

	//��Ƶ����ӿ�״̬��ѯ����
	virtual u32 AudioOutputStateReq( const TMultiAudOutputState_Api & tAudOutputState ) = 0; 

	//��ȡ��Ƶ����ӿ�״̬
	virtual TMultiAudOutputState_Api GetAudioOutputState( ) = 0;

	//��ѯSDI�ӿ���������
	virtual u32 GetSdiInOutReq( ) = 0 ;

	//���������ѯ����
	virtual u32 MicVolumeDetectReq( const EmHDAudPortIn_Api emAudPortIn ) = 0;

	//��ѯSDI�ӿ���������
	virtual EmSdiInOut_Api GetSdiInOutValue( ) = 0;

	//��Ƶ�ӿ�������ѯ����
	virtual u32 VideoInPortCap_Req( ) = 0;

	//��ȡ��Ƶ�ӿ������б�
	virtual TMTHDVidInPortCapList_Api GetVidInPortCapList( ) = 0;
	//��ѯcpu���ڴ�ʹ�����
	virtual u32 DetectCpuAndMemReq() = 0;

	//��ȡcpu���ڴ�ʹ�����
	virtual TMTCpuAndMemState_Api GetCpuAndMemUseInfo() = 0;

	virtual u32 GetLocalLoopStateReq() = 0;

	virtual u32 GetRemoteLoopStateReq() = 0;

	virtual u32 GetAudRmtLoopStateReq() = 0;

	virtual u32 GetVidSrcStatusReq() = 0;

	virtual u32 GetRibbonTestStatusReq() = 0;

	virtual u32 GetUsbStatusReq() = 0;

	virtual u32 InquirePathStructureReq(const s8 *pchSrcPath) = 0;

	virtual u32 GetVidInPortResReq() = 0;

	virtual u32 InquirePldVersionReq() = 0;
	virtual u32 GetPldVersion() = 0;
	virtual u32 InquireFpgaVersionReq() = 0;
	virtual u32 NewInquireFpgaVersionReq() = 0;
	virtual u32 GetFpga1Version() = 0;
	virtual u32 GetFpga2Version() = 0;
	virtual u32 InquireHDMtStartSucessReq() = 0;
	virtual u32 CheckFileIsExistReq(IN CONST s8 *pchPath, IN CONST s8 *pchName, IN CONST BOOL32 &bRecurse) = 0;
	virtual u32 ExportAddrBookReq(IN CONST s8 *pchPath) = 0;
	virtual u32 ImportAddrBookReq(IN CONST s8 *pchPath) = 0;
	virtual u32 GetMicrophoneConnectStatusReq() = 0;
	virtual u32 GetMicrophoneBatteryLevelReq() = 0;
	virtual u32 GetMicrophoneVersionStatusReq() = 0;
	virtual u32 MicrophoneUpgradeCmd(IN CONST TMTAllMicStatus_Api tStatus) = 0;
	virtual u32 OpenHotspotReq(IN CONST TMTAllMicStatus_Api tStatus) = 0;
	virtual u32 GetHotspotStatusReq() = 0;
	virtual u32 SetOsdTransparentReq(IN CONST BOOL32 bTrans) = 0;
    virtual u32 GetMicrophoneVersionReq() = 0;
    virtual u32 GetMicrophoneStateReq() = 0;
    virtual u32 MicrophoneUploadCmd() = 0;
    virtual u32 MicrophoneInstallCmd(TMicInstallList_Api tInstallList) = 0;
    virtual u32 MicUpgradeFileImportReq(IN CONST s8* pchFileNamePath) = 0;
    virtual u32 ExportAllLogFilesReq(IN CONST s8 *pchPath) = 0;
    virtual u32 GetE1ModuleNumReq() = 0;

	virtual u32 IspImgInfSharpnessCmd( IN CONST EmGeneralLevel_Api emGeneralLevel ) = 0;
	virtual u32 IspImgInfWhiteBalanceCmd( IN CONST EmWBAMode_Api emWBAMode ) = 0;
	virtual u32 IspImgInfShutterCmd( IN CONST EmShutterLevel_Api emShutterLevel ) = 0;
	virtual u32 IspImgInfNoiseCmd( IN CONST EmNFMode_Api emNFMode ) = 0;
	virtual u32 IspImgInfISOCmd( IN CONST EmISO_Api emISO ) = 0;	
	virtual u32 IspImgInfApertureCmd( IN CONST EmAperture_Api emAperture ) = 0;
	virtual u32 IspImgInfExposureModeCmd( IN CONST EmExposureMode_Api emExposureMode ) = 0;
	virtual u32 IspImgInfBrightnesssCmd( IN CONST EmBrightnessDirection_Api emBrightnessDirection ) = 0;

	virtual u32 GetIspImgInfSharpnessReq() = 0;
	virtual u32 GetIspImgInfWhiteBalanceReq() = 0;
	virtual u32 GetIspImgInfShutterReq() = 0;
	virtual u32 GetIspImgInfNoiseReq() = 0;
	virtual u32 GetIspImgInfISOReq() = 0;
	virtual u32 GetIspImgInfApertureReq() = 0;
	virtual u32 GetIspImgInfExposureModeReq() = 0;

	virtual EmGeneralLevel_Api GetIspImgInfSharpness() = 0;
	virtual EmWBAMode_Api GetIspImgInfWhiteBalance() = 0;
	virtual EmShutterLevel_Api GetIspImgInfShutter() = 0;
	virtual EmNFMode_Api GetIspImgInfNoise() = 0;
	virtual EmISO_Api GetIspImgInfISO() = 0;
	virtual EmAperture_Api GetIspImgInfAperture() = 0;
	virtual EmExposureMode_Api GetIspImgInfExposureMode() = 0;

	//����Ϊ������ISPͼ��ӿ�
	virtual u32 SetIspImgNoiseCmd( IN CONST TMTIspImgNFInfo_Api tInfo ) = 0;
	virtual u32 SetIspImgSharpnessCmd( IN CONST TMTIspImgSharpnessInfo_Api tInfo ) = 0;
	virtual u32 SetIspExposureGainCmd( IN CONST TMTIspImgExposureGain_Api tInfo )  = 0;
	virtual u32 SetIspWBGainCmd( IN CONST TMTIspImgWBAGainInfo_Api tInfo ) = 0;
	virtual u32 SetBackLightCmd( IN CONST BOOL32 bOn ) = 0;
	virtual u32 SetBackLightLevelCmd( IN CONST u32 dwValue ) = 0;
	virtual u32 SetDigDynSwitchCmd( IN CONST BOOL32 bOn ) = 0;
	virtual u32 SetDigDynLevelCmd( IN CONST u32 dwValue) = 0;
	virtual u32 SetIspGammaCmd( IN CONST u32 dwValue ) = 0;
	virtual u32 SetIspDefogCmd( IN CONST u32 dwValue ) = 0;
	virtual u32 SetCameraImgInfoCmd( IN CONST TMtCameraImgInfo_Api tInfo ) = 0;
	virtual u32 SetCameraPersonFirstCmd( IN CONST BOOL32 bOn ) = 0;
	virtual u32 SetShowRmtAssVidCmd( IN CONST BOOL32 bShow ) = 0;
	virtual u32 SetCameraSceneModeCmd( IN CONST u32 dwVidIdx, IN CONST EmCameraSceneMode_Api emSceneMode ) = 0;
	virtual u32 SetLocalAssAudExpCmd( const BOOL32 bOpen ) = 0;
	virtual u32 SetIspParamCmd( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecIdx, 
								IN CONST EmIspImgInf_Api emMsgSrc,IN CONST s32 nValue ) = 0;

	virtual u32 GetIspImgNoiseReq( IN CONST EmNFType_Api emType ) = 0;
	virtual u32 GetIspImgSharpnessReq() = 0;
	virtual u32 GetIspExposureGainReq( IN CONST EmExposureGainType_Api emType )  = 0;
	virtual u32 GetIspWBGainReq( IN CONST EmWBAGainType_Api emType ) = 0;
	virtual u32 GetBackLightReq( ) = 0;
	virtual u32 GetBackLightLevelReq( ) = 0;
	virtual u32 GetDigDynSwitchReq( ) = 0;
	virtual u32 GetDigDynLevelReq( ) = 0;
	virtual u32 GetIspGammaReq( ) = 0;
	virtual u32 GetIspDefogReq( ) = 0;
	virtual u32 GetCameraImgInfoReq( ) = 0;
	virtual u32 GetCameraPersonFirstReq( ) = 0;
	virtual u32 GetCameraSceneModeReq( IN CONST u32 dwVidIdx ) = 0;
	virtual u32 GetCameraUpgradePackReq( const EmMtVideoPort_Api emVidPort ) = 0;
	virtual u32 GetLocalAssAudExpReq() = 0;
	virtual u32 GetIspParamReq( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecIdx, IN CONST EmIspImgInf_Api emMsgSrc ) = 0;

	virtual TMTIspImgNFInfo_Api			GetIspImgNoise( TMTIspImgNFInfo_Api tInfo ) = 0;
	virtual TMTIspImgSharpnessInfo_Api	GetIspImgSharpness( ) = 0;
	virtual TMTIspImgExposureGain_Api	GetIspExposureGain( TMTIspImgExposureGain_Api tInfo )  = 0;
	virtual TMTIspImgWBAGainInfo_Api	GetIspWBGain( TMTIspImgWBAGainInfo_Api tInfo ) = 0;
	virtual BOOL32	GetBackLight( ) = 0;
	virtual u32		GetBackLightLevel( ) = 0;
	virtual BOOL32	GetDigDynSwitch( ) = 0;
	virtual u32		GetDigDynLevel( ) = 0;
	virtual u32		GetIspGamma( ) = 0;
	virtual u32		GetIspDefog( ) = 0;
	virtual TMtCameraImgInfo_Api	GetCameraImgInfo( ) = 0;
	virtual BOOL32	GetCameraPersonFirst( ) = 0;
	virtual BOOL32  GetLocalAssAudExp() = 0;


	//����osd�Ƿ���ʾ��رգ�������
	virtual u32 SetOsdDisplayCmd( IN CONST BOOL32 bOpen ) = 0;

private:

};

#endif // _I_MTDEVICEINFO_H_