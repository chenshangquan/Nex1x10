/**===========================================================================
 * @file    $Id$
 * @brief   �������ݹ���������ع��ܽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTRMTDATSHARE_H_
#define _I_MTRMTDATSHARE_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_base.h"
#include "imtdatashare.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtConfig
 * @brief   �����ն˻�������������ع��ܽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtRmtDataShare : public IMtDataShare
{
public:
	//��ȡQos��������
	virtual u32 GetIPQoSCfgReq() = 0;
	//��ȡMTU TCP/IP����䵥Ԫ��������
	virtual u32 GetMTUCfgReq() = 0;
	//��ȡNAT��������
	virtual u32 GetNatCfgReq() = 0;


	//��ȡXAPList��������
	virtual u32 GetXAPListCfgReq() = 0;
	//��ȡ���������
	virtual u32 GetAicameraCfgReq() = 0;
	//��ȡ��ǰʹ�õ�XAP��������������
	virtual u32 GetCurXAPCfgReq() = 0;
	//��ȡXNU������(XMPP��¼)��������
	virtual u32 GetXNUCfgReq() = 0;
    //��ȡNSָ��
    virtual u32 GetNSRtReq() = 0;
	//��ȡCSU��������������
	virtual u32 GetCSUCfgReq() = 0;
	virtual u32 GetGkCfgReq() = 0;
	//��ȡSUS��������������
	virtual u32 GetSUSCfgReq() = 0;
	virtual u32 GetSusManuCfgReq() = 0;
	//��ȡ���ܷ�������������
	virtual u32 GetSNMPCfgReq() = 0;
	virtual u32 GetSNMPManuCfgReq() = 0;
	//��ȡ���ٷ�������������
	virtual u32 GetNTSCfgReq() = 0;
	virtual u32 GetNtsManuCfgReq() = 0;
	//��ȡNTP��������������
	virtual u32 GetNTPCfgReq() = 0;
	virtual u32 GetNtpManuCfgReq() = 0;
	//��ȡVOD��������������
	virtual u32 GetVODCfgReq() = 0;
	//��ȡVRS��������������
	virtual u32 GetVRSCfgReq() = 0;

	//��ȡ���ݻ��� emMt_Cfg_DCS (value: TMtDCSSvrAddr) 
	virtual u32 GetDCSCfgReq() = 0;


	//��ȡStreamPlayer��ý����������
	virtual u32 GetStreamPlayerCfgReq() = 0;
	//��ȡAPI��������ַ����
	virtual u32 GetPlatformApiRtCfgReq() = 0;
	//��ȡ΢����������ַ
	virtual u32 GetMicroBlogRtCfgReq() = 0;
	//��ȡSip��������������
	virtual u32 GetSipSvrCfgReq() = 0;
	virtual u32 GetManuSipSvrCfgReq() = 0;
	//��ȡSocket5������������
	virtual u32 GetSocks5PxyCfgReq() = 0;
	//��ȡ��������¼״̬����(RT)
	virtual u32 GetSvrStateListReq() = 0;
	//��ȡXap��¼�ɹ����ȡ���û�Ȩ����Ϣ����(RT)
	virtual u32 GetUserPrevilegeReq() = 0;
	//��ȡ��½APS���ص��û���Ϣ����(value: TMTUserInfoFromAps) emMt_Rt_UserInfoFromAps
	virtual u32 GetUserInfoFromApsRtReq() = 0;
	//��ȡH323��������
	virtual u32 GetH323CfgReq() = 0;
	//��ȡSIP��������
	virtual u32 GetSipCfgReq() = 0;
	// ƽ�����͵ȼ� (value:TU32)
	virtual u32 GetSmoothSendCfgReq( ) = 0;
	//emMt_Cfg_UseTelnet,				///<ʹ��telnet���� (value:TBOOL32)
	virtual u32 GetUseTelnetCfgReq( ) = 0;
	//emMt_Cfg_UseHTTP,				///<ʹ��Http���� (value:TBOOL32)
	virtual u32 GetUseHTTPCfgReq( ) = 0;
	//emMt_Cfg_UseFtp,				///<ʹ��FTP���� (value:TBOOL32)
	virtual u32 GetUseFtpSrvCfgReq( ) = 0;
	//��ȡ����MC��������
	virtual u32 GetMCCfgReq() = 0;
	//��ȡ��Ƶ����������������
	virtual u32 GetAudVolInCfgReq() = 0;
	//��ȡ��Ƶ���������������
	virtual u32 GetAudVolOutCfgReq() = 0;
	//��ȡ�����ش�������������
	virtual u32 GetLostPackResendCfgReq( ) = 0;
	//��ȡ����������������
	virtual u32 GetAudioPrecedenceCfgReq( ) = 0;

	//��ȡ����Ƶ����������  (value: TMTAllVideoEncoderParamCfg) emMt_Cfg_PriVidEncParam
	virtual u32 GetPriVidEncParamCfgReq() = 0;
	//��ȡ����Ƶ����������  (value: TMTAllVideoEncoderParamCfg)emMt_Cfg_AssVidEncParam
	virtual u32 GetAssVidEncParamCfgReq() = 0;
	//��ȡ��Ƶ����������  (value: TMTAllVideoDecoderParamCfg)emMt_Cfg_VideoDecParam
	virtual u32 GetVideoDecParamCfgReq() = 0;

	// ��ȡ��Ƶ�������� emMt_Cfg_AudioPrior
	virtual u32 GetAudioPriorCfgReq()=0;
	// ��ȡ������ѡ���� emMt_Cfg_PriVidPrior
	virtual u32 GetPriVidPriorCfgReq()=0;
	// ��ȡPc������ѡ���� emMt_Cfg_PcAssVidPrior
	virtual u32 GetPcAssVideoPriorCfgReq()=0;
	// ��ȡVid������ѡ���� emMt_Cfg_VidAssVidPrior
	virtual u32 GetVidAssVideoPriorCfgReq()=0;

	//��ȡ�������Ƿ������Ŷ�����Ч(value: TBOOL32)emMt_Cfg_PlayAniSoundInIdle
	virtual u32 GetPlayAniSoundInIdleCfgReq() = 0;
	//��ȡ��ƵԴ (value: TMTCodecVidSrcInfo) emMt_cfg_CodecVideoSrc
	virtual u32 GetCodecVideoSrcCfgReq() = 0;

	//����mc��������Ϣ(value: TInnerMCRunInfo) emMt_Rt_MCInfo
	virtual u32 GetMCInfoRtReq() = 0;

	// ��ȡ������Ϣ���� emMt_Rt_CallInfo
	virtual u32 GetCallInfoRtReq()=0;

	//��ǰ��ͨ��info�� (value: TMutiChanDsInfo) emMt_Rt_ChanInfo
	virtual u32 GetChanInfoRtReq() = 0;

	//�Ƿ��������նˣ� ��ƽ̨��ȡ(value: TMTSatelliteFlag) emMt_Rt_IsSatelliteMT
	virtual u32 GetIsSatelliteMTRtReq() = 0;

	//��ȡ��ϯ��ѯ����   (value: TMTChrmanPollSchemeList) emMt_Cfg_ChrmanPollSchemes
	virtual u32 GetChrmanPollSchemesCfgReq() = 0;

	//��ȡ��ϯ������������
	virtual u32 GetChairmanOperateCfgReq() = 0;
	//��ȡ����״̬��ʾ��������
	virtual u32 GetShowConfStateCfgReq() = 0;

	//��ȡ��ʾ����ʱ�� (value: TBOOL32)emMt_Cfg_ShowConfTime
	virtual u32 GetShowConfTimeCfgReq() = 0;
	//��ȡ��ʾϵͳʱ�� (value: TBOOL32)emMt_Cfg_ShowSystimeTime
	virtual u32 GetShowSystimeTimeCfgReq() = 0;
	//��ȡ�������Ƿ���ʾ����Ϣ (value: TBOOL32)emMt_Cfg_ShowShortMsgInConf
	virtual u32 GetShowShortMsgInConfCfgReq() = 0;
	//��ȡ�Ƿ���ʾ������ʾ (value: TBOOL32)emMt_Cfg_ShowAppTips
	virtual u32 GetShowAppTipsCfgReq() = 0;

	//��ȡ���;�̬ͼƬ��������
	virtual u32 GetStaticPicCfReq() = 0;
	//��ȡ���õ绰������������
	virtual u32 GetTelephoneCfgReq() = 0;
	//��ȡ�Զ�������������
	virtual u32 GetAutoCallCfgReq() = 0;

	//��ȡ�Ƿ�����Զң (value: TBOOL32) emMt_Cfg_FECC 
	virtual u32 GetFECCCfgReq() = 0;

	//��ȡ�Զ���¼��������������
	virtual u32 GetAutoLoginCfgReq( )= 0;;
	//��ȡ�ǶԳ�������������
	virtual u32 GetAsymmetricNetCfgReq() = 0;
	//��ȡ�������ǽ��������
	virtual u32 GetIncomingCallFWCfgReq() = 0;
	//��ȡ��ǰ�Ƿ����ô�������������
	virtual u32 GetBandwidthCheckCfgReq() = 0;
	//��ȡ����MC�����ش�������������
	virtual u32 GetMCRSParamCfgReq( ) = 0;
	//��ȡ�Զ�˫��Դ��������
	virtual u32 GetAssStreamSrcAdjustCfgReq( ) = 0;
	//��ȡ����Э��������������
	virtual u32 GetCallProtocolCfgReq() = 0;
	// ��ȡ���������������
	virtual u32 GetConfEncryptTypeCfgReq()=0;
	//��ȡ�������ʱ������������
	virtual u32 GetKeepAliveItrvlCfgReq() = 0;
	//��ȡ�������ʱ������������
	virtual u32 GetSipKeepAliveItrvlCfgReq() = 0;
	//��ȡ����FEC��������
	virtual u32 GetFecInfoCfgReq( ) = 0;
	//��ȡ���е͵��Ļ���������������(С��64�����Ǵ���Ƶ����)
	virtual u32 GetCallRateLevelReq( ) = 0;
	//�Զ��������ݹ��� emMt_Cfg_AutoSendSharedContent	
	virtual u32 GetAutoSendSharedContentCfgReq( ) = 0;
	//�Ƿ������½ƽ̨���� emMt_Cfg_LoginPlatformSrv(value:TBOOL32)
	virtual u32 GetLoginPlatformSrvCfgReq( ) = 0;
	
	//��ȡ˫�����ʱ�����������
	virtual u32 GetVidBitRationCfgReq( ) = 0;
	//��ȡ�ն˰汾��Ϣ��������(RT)
	virtual u32 GetTerminalInfoReq( ) = 0;
	//��ȡ�ն�������Ϣ��������
	virtual u32 GetTerminalNameCfgReq( ) = 0;

	virtual u32 GetAnswerModeCfgReq( ) = 0;

	virtual u32 GetBandWidthReq() = 0;


	virtual u32 GetCallRateCfgReq() = 0;

	virtual u32 GetLoginTacticsCfgReq() = 0;

	//323Э��ջ�Ƿ��׼��( value: TBOOL32), ��׼ע�ᵽ1719���Ǳ�ע�ᵽ1759 emMt_Rt_IsH323StackStand
	virtual u32 GetIsH323StackStandRtReq() = 0;
	//323Э��ջ�����˿�( value: TU16) emMt_Rt_H323CallingPort
	virtual u32 GetH323CallingPortRtReq() = 0;
	//��ȡH.264 SVC  (value:TBOOL32)emMt_Cfg_H264Svc
	virtual u32 GetH264SvcCfgReq() = 0;
	//��ȡ��Ƶ�غ�����Ӧ  (value:TBOOL32)emMt_Cfg_LoadAdaptiveVideo
	virtual u32 GetLoadAdaptiveVideoCfgReq() = 0;
	//��ȡ����mc������������ (value:TMTInnerMcAssVidCfg)emMt_Cfg_InnerMcAssVidCfg
	virtual u32 GetInnerMcAssVidCfgReq() = 0;

	virtual u32 GetAudAnsCfgReq( ) = 0;
	//��ȡ�Զ������������
	virtual u32 GetAudAgcCfgReq( ) =0;
	//��ȡ�Զ���������
	virtual u32 GetAudAecCfgReq( ) = 0;

	//��ȡ���� (value: TString) emMt_Cfg_Email
	virtual u32 GetEmailCfgReq( ) = 0;

	//��ȡTCP/UDP��ʼ�˿�������Ϣ����
	virtual u32 GetUdpTcpBasePortCfgReq()=0;
	// ��ȡ�Ƿ������ļ���־����
	virtual u32 GetIsUsedFileLogonReq()=0;

	//ϵͳ����״̬ (TBOOL32)emMt_Rt_SysUpgrade
	virtual u32 GetSysUpgradeRtReq( ) = 0;
	//����ҵ��ռ�õĶ˿�  (value: TMTUsedPortList)emMt_Rt_ConfUsedPorts
	virtual u32 GetConfUsedPortsRtReq( ) = 0;
	//mcҵ��ռ�õĶ˿�   (value: TMTUsedPortList)emMt_Rt_McUsedPorts
	virtual u32 GetMcUsedPortsRtReq( ) = 0;
	//vodҵ��ռ�õĶ˿�   (value: TMTUsedPortList)emMt_Rt_VodUsedPorts
	virtual u32 GetVodUsedPortsRtReq( ) = 0;
	//����ҵ��ռ�õĶ˿�   (value: TMTUsedPortList)emMt_Rt_ImUsedPorts
	virtual u32 GetImUsedPortsRtReq( ) = 0;
	//��¼IM����Ҫ�Ĳ��� (value: TImUserLogin)emMt_Rt_LoginIM
	virtual u32 GetLoginIMParamCfgReq( ) = 0;

	//@brief    ��ȡ��¼��������
	virtual u32 GetLoginPwdCfgReq() = 0;
	//@brief    ��ȡ����
	virtual u32 GetBandWidthCfgReq() = 0;


	//����ʱӳ��� (value: TMutiTServiceInfoRtData) emMt_Rt_SysCtrlSrvInfo
	virtual u32 GetSysCtrlSrvInfoRtReq() = 0;
	//����ʱӳ�����ģ����� (value: TU32) emMt_Rt_SysCtrlSrvNum
	virtual u32 GetSysCtrlSrvNumRtReq() = 0;
	//��ȡ����ӳ��� (value: TMutiTServiceDefInfo) emMt_Cfg_SysCtrlDefSrvInfo
	virtual u32 GetSysCtrlDefSrvInfoCfgReq() = 0;
	//��ȡĬ��ӳ�����ģ����� (value: TU32) emMt_Cfg_SysCtrlDefSrvNum
	virtual u32 GetSysCtrlDefSrvNumCfgReq() = 0;

	//H460���� (value:TMtH460PxyCfg)emMt_Cfg_H460
	virtual u32 GetH460CfgReq() = 0;
	//H323���� (value:TMtH323PxyCfg)emMt_Cfg_H323Pxy
	virtual u32 GetH323PxyCfgReq() = 0;
	//��������� (value: TMtMeetingSvrAddr)emMt_Rt_MeetingCtrl
	virtual u32 GetMeetingCtrlSrvRtReq() = 0;
	// ��ȡ��¼Aps����Ҫ�Ĳ������� (value: TMTApsLoginParam) emMt_Cfg_ApsLoginParam
	virtual u32 GetApsLoginParamCfgReq() = 0;


	//������Ӳ�ն˲�Ʒ��
	//��ȡ��������Ϣ��������
	virtual u32 GetHoriRollMsgCfgReq( ) = 0;

	/**********�û�����**************/
	// ��ȡ˫����ʾģʽ���� emHD_Cfg_DispMode
	virtual u32 GetHDDispModeCfgReq( ) = 0;
	//emHD_Cfg_VidResPriorStrategy
	// ��ȡ��Ƶ�����ʽ���� emHD_Cfg_HDResOutput
	virtual u32 GetHDResOutputCfgReq( ) = 0;
	// ��ȡ�Ƿ����Զ����л����� emHD_Cfg_AutoPIP
	virtual u32 GetIsHDAutoPIPCfgReq( ) = 0;
	// ��ȡ������������ emHD_Cfg_CallInRing
	virtual u32 GetHDCallInRingCfgReq( ) = 0;
	// ��ȡ������������ emHD_Cfg_CallOutRing
	virtual u32 GetHDCallOutRingCfgReq( ) = 0;

	//���ź�������(value: TU32) emHD_Rt_CallInRing
	virtual u32 GetCallInRingRtReq() = 0;
	//���ź�������(value: TU32) emHD_Rt_CallOutRing
	virtual u32 GetCallOutRingRtReq() = 0;
	//��ȡ���Ű�����(value: TU32) emHD_Cfg_KeyboardRing
	virtual u32 GetKeyboardRingCfgReq() = 0;

	// ��ȡ��ǰʹ�õĺ��id������ emHD_Cfg_EnablePresetBanner
	virtual u32 GetHDPresetBannerCfgReq()=0;
	// ��ȡosd����������� emHD_Cfg_OsdBannerInfo
	virtual u32 GetHDOsdBannerInfoCfgReq()=0;

	// ��ȡMtc����������� emHD_Cfg_MtcBannerInfo
	virtual u32 GetHDMtcBannerInfoCfgReq()=0;
	// ��ȡ̨���������� emHD_Cfg_LabelInfo
	virtual u32 GetHDLabelInfoCfgReq()=0;
	// ��ȡ�Զ������������� emHD_Cfg_AutoSleep
	virtual u32 GetHDAutoSleepCfgReq()=0;
	// ��ȡʱ���������� emHD_Cfg_SysTime
	virtual u32 GetHDSysTimeCfgReq()=0;

	/**********����Ա����**********/
	// ��ȡ����������� emHD_Cfg_MicGain
	virtual u32 GetHDMicGainCfgReq()=0;
	// ��ȡ������������Ӧ���� emHD_Cfg_AecDebug
	virtual u32 GetHDAecDebugCfgReq()=0;
	// ��ȡ����Ƶ����ӿ����� emHD_Cfg_AudInPortList
	virtual u32 GetHDAudInPortListCfgReq()=0;
	// ��ȡ��Ƶ����ӿ����� emHD_Cfg_AudOutPortList
	virtual u32 GetHDAudOutPortListCfgReq()=0;
	// ��ȡ��һ·����Ƶ����˿����� emHD_Cfg_Pri1stVidInPort
	virtual u32 GetHDPri1stVidInPortCfgReq()=0;
	//��ȡ�ڶ�·������Ƶ����˿�(value: TMTHDVidInPort ) emHD_Cfg_Pri2ndVidInPort
	virtual u32 GetHDPri2ndVidInPortCfgReq()=0;
	//��ȡ����Ƶ����˿�(value: TMTHDVidInPort ) emHD_Cfg_AssVidInPort
	virtual u32 GetHDAssVidInPortCfgReq()=0;
	// ��ȡ���ӻ�������� emHD_Cfg_MultiVideo
	virtual u32 GetHDMultiVideoCfgReq()=0;
	// ��ȡ��Ƶ�������� emHD_Cfg_VideoMatrixScheme
	virtual u32 GetHDVideoMatrixSchemeListCfgReq()=0;
	// ��ȡ��ͼ����ʾ�������� emHD_Cfg_LastDisplay
	virtual u32 GetHDLastDisplayListCfgReq()=0;
	// ��ȡͼ����ȼ����� emHD_Cfg_ImageNoiseLevel
	virtual u32 GetHDImageNoiseLevelCfgReq()=0;
	// ��ȡͼ����ǿ�������� emHD_Cfg_ImageEnhancement
	virtual u32 GetHDImageEnhancementCfgReq()=0;

	//��ȡ��һ·����Ƶ��������(value: TMTHDImageDeformationTensile ) emHD_Cfg_Pri1stDeformationTensile
	virtual u32 GetHDPri1stDeformationTensileCfgReq()=0;

	//��ȡ�ڶ�·����Ƶ��������(value: TMTHDImageDeformationTensile ) emHD_Cfg_Pri2ndDeformationTensile
	virtual u32 GetHDPri2ndDeformationTensileCfgReq()=0;

	//��ȡ����Ƶ��������(value: TMTHDImageDeformationTensile ) emHD_Cfg_AssDeformationTensile
	virtual u32 GetHDAssDeformationTensileCfgReq()=0;

	//��ȡ��һ·����Ƶ�ȱ�����(value: TMTHDImageGeometricScaling ) emHD_Cfg_Pri1stGeometricScaling
	virtual u32 GetHDPri1stGeometricScalingCfgReq()=0;

	//��ȡ�ڶ�·����Ƶ�ȱ�����(value: TMTHDImageGeometricScaling ) emHD_Cfg_Pri2ndGeometricScaling
	virtual u32 GetHDPri2ndGeometricScalingCfgReq()=0;

	//��ȡ����Ƶ�ȱ�����(value: TMTHDImageGeometricScaling )emHD_Cfg_AssGeometricScaling
	virtual u32 GetHDAssGeometricScalingCfgReq()=0;

	//��ȡ��һ·����Ƶ�ñ�����(value: TU32 )emHD_Cfg_EdgePixel
	virtual u32 GetHDEdgePixelCfgReq()=0;

	//��ȡ���������(value: TMTHDCameraList )emHD_Cfg_CameraList
	virtual u32 GetHDCameraListCfgReq()=0;

	//��ȡ��������(value: TMTHDSerialCtrl )emHD_Cfg_SerialCtrl
	virtual u32 GetHDSerialCtrlCfgReq()=0;
	//��ȡ�����б�(value: TMTHDSerialList)
	virtual u32 GetSerialListCfgReq()=0;
	//��ȡVGAͼ����� (value:TMTVgaImageAdjustCfg)emHD_Cfg_VGAImageAdjust
	virtual u32 GetVGAImageAdjustCfgReq() = 0;
	//��ȡ��ƵԴ��ǩ (value:TMTVideoSrcTagList)emHD_Cfg_VideoSrcTag
	virtual u32 GetVideoSrcTagCfgReq() = 0;
	//��ȡ��Ƶ�����ǩ (value:TMTVideoOutTagList)emHD_Cfg_VideoOutTag
	virtual u32 GetVideoOutTagCfgReq() = 0;
	//��ȡSDIһ��һ����������(value: TU32)
	virtual u32 GetSDIOneInOneOutOrTwoInCfgReq() = 0;
	
	//��ȡ����FTP (value:TMTSnapShotFtpCfg)emHD_Cfg_SnapShotFtpCfg
	virtual u32 GetSnapShotFtpCfgCfgReq() = 0;
	//��ȡVGA������� (value : TU32)emHD_Cfg_VgaOutBright
	virtual u32 GetVgaOutBrightCfgReq() = 0;
	//��ȡVGA����Աȶ�����
	virtual u32 GetVgaOutContrastCfgReq() = 0;
	//��ȡVGA������Ͷ����� (value : TU32)emHD_Cfg_VgaOutSaturation
	virtual u32 GetVgaOutSaturationCfgReq() = 0;

	//��ѯ��Ƶ���ȡ��Աȶȡ����Ͷ�����
	virtual u32 GetVidImgParamReq(const EmCodecComponent_Api emCodecType,const EmCodecComponentIndex_Api emCodecIdx,const EmImgParam_Api emMsgSrc ) = 0;


	//��ȡԤ��λ������������   (value:TMTAllPreSetNameInfoCfg) emHD_Cfg_PresetNameInfo
	virtual u32 GetPresetNameInfoCfgReq() = 0;

	//�����������
	//< ·��������Ϣ(value: TRouteItemInfoList) emHD_Cfg_RouteCfgList
    virtual u32 GetRouteCfgListCfgReq() = 0;

	//< ��̫������ģʽ(value:TEthnetWorkModeList) emHD_Cfg_EthWorkModeList
	virtual u32 GetEthWorkModeListCfgReq()=0;

	//< ��̫����Ϣ(value:TEthnetCfg) emHD_Cfg_EthnetCfg
	virtual u32 GetEthnetCfgReq()=0;

	//< PPPoE������Ϣ(value:TEthnetPPPoECfg) emHD_Cfg_EthPPPoECfg
	virtual u32 GetEthPPPoECfgReq()=0;

	//< Wifi����ģʽ (value:TWifiWorkMode) emHD_Cfg_WifiWorkMode
	virtual u32 GetWifiWorkModeCfgReq()=0;

	//< Wifi-AP������Ϣ (value:TWifiApConfiguration) emHD_Cfg_WifiApCfg
	virtual u32 GetWifiApCfgReq()=0;

	//< Wifi��Ϊclient�����Ӻ��������Ϣ (value:TWifiConfiguration) emHD_Cfg_WifiClientCfg
	virtual u32 GetWifiClientCfgReq()=0;

	//< E1��������Ϣ (value:TE1Cfg) emHD_Cfg_E1Cfg
	virtual u32 GetE1CfgReq() = 0;

	//< Wifi��Ϊclient���Ӻ����ϸ��Ϣ(value:TWifiCurDetailInfo) emHD_Rt_WifiCurConnectedInfo
	virtual u32 GetWifiCurConnectedInfoRtReq()=0;

	//< �ƶ�����3G/4G����ģʽ (value:TMobileDataWorkMode) emHD_Cfg_MobileDataWorkMode
	virtual u32 GetMobileDataWorkModeCfgReq()=0;

	//< �ƶ�����3G/4G���Ӻ����ϸ��Ϣ(value:TMobileDataCurDetailInfo) emHD_Rt_MobileDataConnectedInfo
	virtual u32 GetMobileDataConnectedInfoRtReq()=0;

	//< ��ǰ����ͨѶ������IP��ϸ��Ϣ(value:TNetUsedInfo) emHD_Rt_NetUsedInfo
	virtual u32 GetNetUsedInfoRtReq()=0;

	// ��ȡ����Ƶ��һ·��ʾ�������� emHD_Cfg_MainFstDisplayRatio
	virtual u32 GetHDMainPriDisplayRatioCfgReq()=0;

	// ��ȡ����Ƶ�ڶ�·��ʾ�������� emHD_Cfg_MainSecDisplayRatio
	virtual u32 GetHDMainSecDisplayRatioCfgReq()=0;

	// ��ȡ����ʾ�������� emHD_Cfg_AssDisplayRatio
	virtual u32 GetHDAssDisplayRatioCfgReq()=0;

	virtual u32 GetHDResizeModeCfgReq() = 0;

	virtual u32 GetMtWizardResultCfgReq() = 0;

	virtual u32 GetGKRegistRtReq() = 0;

	//��ȡ����ƵԴ�Ƿ���Դ����
	virtual u32 GetAssVideoPortStatusReq() = 0;

	virtual u32 GetSipRegistRtReq() = 0;
    virtual u32 GetDcsRegistRtReq() = 0; //��ӵ�dcs״̬
    virtual u32 GetFastCallListCfgReq() = 0;
	virtual u32 GetImLoginHandleReq() = 0;
    virtual u32 GetEnableHTTPSCfgReq() = 0;
	virtual u32 GetShowConfNameCfgReq() = 0;
	virtual u32 GetTelnetFtpUserInfoCfgReq() = 0;
	virtual u32 GetRfMatchStateListCfgReq() = 0;
	virtual u32 GetForceH323StackCfgReq() = 0;
    virtual u32 GetServerLoginPortCfgReq() = 0;
	virtual u32 GetTRtpSamePortCfgReq() = 0;
	virtual u32 GetEnableIpwTypeCfgReq() = 0;
	virtual u32 GetCameraContrlExchangeCfgReq() = 0;
	virtual u32 GetCameraHeadStandCfgReq() = 0;
	virtual u32 GetShowInOutConfCfgReq() = 0;
	virtual u32 GetFtpTelnetLimitIpListCfgReq() = 0;
	virtual u32 GetIsBusiSecMtReq() = 0;
	virtual u32 GetSipConnectCfgReq()   = 0;
	virtual u32 GetEnableStrongAutReq() = 0;
	virtual u32 GetLicenseIsValidReq()  = 0;
	virtual u32 GetbEnableTlsCertReq()  = 0;
	virtual u32 GetbEnableGMTlsCertReq() = 0;
	virtual u32 GetShowMtTimeCfgReq() = 0;
	virtual u32 GetLoginStrategyCfgReq() = 0;
	virtual u32 GetShowHomeButtonCfgReq() = 0;
	virtual u32 GetShowAssVidInVmpCfgReq() = 0;
	virtual u32 GetIMIXCtrlOsdFuncCfgReq() = 0;
	virtual u32 GetHttpsCertTypeCfgReq()   = 0;
	virtual u32 GetVidEncQcModeCfgReq()    = 0;
	virtual u32 GetIsSupportWirelessReq()  = 0;
	virtual u32 GetQtSettingCfgReq() = 0;
	virtual u32 GetQtKeyUpdateModeCfgReq() = 0;
	virtual u32 GetIdleAssStreamStatusRtCfgReq() = 0;
	virtual u32 GetChannelLicenseRtReq() = 0;
	virtual u32 GetVGAImgOutAdjustCfgReq() = 0;
	virtual u32 GetInCameraVidStdCfgReq() = 0;
	virtual u32 GetIsImixTerReq() = 0;
	virtual u32 GetIsExportingNetCapRtReq() = 0;
	virtual u32 GetCameraLastPosCfgReq() = 0;
	virtual u32 GetShowLostPktCfgReq() = 0;
	virtual u32 GetUserLoginPwdTimeoutCfgReq() = 0;
	virtual u32 GetEnableSecureCfgReq() = 0;
	virtual u32 GetShortCutKeyCfgReq() = 0;

private:

};

#endif // _I_MTRMTDATSHARE_H_