/**===========================================================================
 * @file    $Id$
 * @brief   �����ն������������ݲ����Ľӿڶ���
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
 * @brief   �����ն������������ݲ����Ľӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtDataShare : public IMtApiIF
{
public:
	//��ԭĬ��ֵ
	virtual u32 RestoreDefaultCfgInfo( const TMTRestoreDefaultCfgInfo_Api &tCfg);

	//����Qos�������� emMt_Cfg_IPQoS
	virtual u32 SetIPQoSCfgCmd( const TMTIPQoS_Api& tCfg );
	//��ȡQos������Ϣ emMt_Cfg_IPQoS
	virtual TMTIPQoS_Api GetIPQosCfg()=0;
	//����MTU TCP/IP����䵥Ԫ�������� emMt_Cfg_MTU
	virtual u32 SetMTUCfgCmd( const u32 dwMTU );
	// ��ȡTCP/IP����䵥ԪMTU emMt_Cfg_MTU
	virtual u32 GetMTUCfg()=0;
	//����NAT�������� emMt_Cfg_NAT
	virtual u32 SetNatCfgCmd( const TMTNat_Api& tCfg );
	//��ȡNAT���� emMt_Cfg_NAT
	virtual TMTNat_Api GetNatCfg()=0;

	//
	//TL��ȡ��ǰ��Ƶ�ɼ��豸���� (��WIN32)
	virtual TDevInfo_Api GetCurVidCapDevCfg() = 0;

	//����XAPList�������� emMt_Cfg_APSList
	virtual u32 SetXAPListCfgCmd( const TMtXAPSvrList_Api& tCfg );
	//��ȡXAP�������б�emMt_Cfg_APSList
	virtual TMtXAPSvrList_Api GetXAPSvrList()=0;
	//��ȡ��ǰʹ�õ�XAP��������Ϣ emMt_Rt_CurAPS
	virtual TMtAPSSvrAddr_Api GetCurUsdXAPSvrRtCfg()=0;
	
	//��ȡXMPP��¼���� emMt_Rt_XNU
	virtual TMtXMPPInfo_Api GetXMPPCfg()=0;
    
    //��ȡNS����IP
    virtual TMtNSADDRInfo_Api GetNSRtCfg()=0;

	//emMt_Rt_APSֻ�еײ�ʹ�ã����ṩ������

	//CSU�������������� emMt_Cfg_CSU
	virtual u32 SetCSUCfgCmd( const TMtCSUAddr_Api& tCfg );
	//��ȡCSU��ַ���� emMt_Cfg_CSU
	virtual TMtCSUAddr_Api GetCSUAdrCfg()=0;
	virtual TMtCSUAddr_Api GetGkAdrCfg()= 0;
	//����gk��ַ
	virtual u32 SetGKCfgCmd( const TMtCSUAddr_Api& tCfg );

	//SUS�������������� emMt_Cfg_SUS
	virtual u32 SetSUSCfgCmd( const TMTSUSAddr_Api& tCfg );

	virtual u32 SetSusManuCfgCmd( const TMTSUSAddr_Api& tCfg );

	//��ȡSUS����������������Ϣ emMt_Cfg_SUS
	virtual TMTSUSAddr_Api GetSUSSvrCfg()=0;

	virtual TMTSUSAddr_Api GetSusManuSvrCfg() = 0;

	//���ܷ������������� emMt_Cfg_NMS
	virtual u32 SetSNMPCfgCmd( const TMtNMAAddr_Api& tCfg );

	virtual u32 SetSNMPManuCfgCmd( const TMtNMAAddr_Api& tCfg );

	//��ȡ���ܷ�����������Ϣ emMt_Cfg_NMS
	virtual TMtNMAAddr_Api GetNMSSvrCfg()=0;

	virtual TMtNMAAddr_Api GetNmsManuSvrCfg() = 0;

	//���ٷ������������� emMt_Cfg_NTS
	virtual u32 SetNTSCfgCmd( const TMtNTSAddr_Api& tCfg );

	virtual u32 SetNtsManuCfgCmd( const TMtNTSAddr_Api& tCfg );

	//��ȡ���ٷ��������� emMt_Cfg_NTS
	virtual TMtNTSAddr_Api GetNTSAdrCfg()=0;

	virtual TMtNTSAddr_Api GetNtsManuAdrCfg() = 0;

	//NTP�������������� emMt_Cfg_NTP
	virtual u32 SetNTPCfgCmd( const TMtNTPAddr_Api& tCfg );

	virtual u32 SetNtpManuCfgCmd( const TMtNTPAddr_Api& tCfg );

	//��ȡNTP������������Ϣ emMt_Cfg_NTP
	virtual TMtNTPAddr_Api GetNTPSvrCfg()=0;

	virtual TMtNTPAddr_Api GetNtpManuCfg() = 0;

	//VOD�������������� emMt_Cfg_VOD
	virtual u32 SetVODCfgCmd( const TMtVODSvrCfg_Api& tCfg );
	//VRS�������������� emMt_Cfg_VRS
	virtual u32 SetVRSCfgCmd( const TMtVRSSvrCfg_Api& tCfg );
	//��ȡVOD������������Ϣ emMt_Cfg_VOD
	virtual TMtVODSvrCfg_Api GetVODSvrCfg()=0;
	//��ȡVRS������������Ϣ
	virtual TMtVRSSvrCfg_Api GetVRSSvrCfg() = 0;

	//�������ݻ��� emMt_Cfg_DCS (value: TMtDCSSvrAddr) 
	virtual u32 SetDCSCfgCmd( const TMtDCSSvrAddr_Api& tCfg );
	//��ȡ���ݻ��� emMt_Cfg_DCS (value: TMtDCSSvrAddr) 
	virtual TMtDCSSvrAddr_Api GetDCSCfg()=0;

	//StreamPlayer��ý���������� emMt_Cfg_StreamMedia
	virtual u32 SetStreamPlayerCfgCmd( const TMTStreamMedia_Api& tCfg );
	//��ȡ��ý��������Ϣ emMt_Cfg_StreamMedia
	virtual TMTStreamMedia_Api GetStreamPlayerCfg()=0;
	
	//��ȡƽ̨����ӿڵ�ַ emMt_Rt_PlatformApi
	virtual TMtPlatformApiAddr_Api GetPlatformApiRtCfg( ) = 0;

	//��ȡ΢�������� emMt_Rt_MicroBlog
	virtual TMtMicroBlogAddr_Api GetMicroBlogRtCfg( ) = 0;

	//Sip�������������� emMt_Cfg_SipSvr
	virtual u32 SetSipSvrCfgCmd( const TMtSipSvrAddr_Api& tCfg );

	virtual u32 SetManuSipSvrCfgCmd( const TMtSipSvrAddr_Api& tCfg );

	//��ȡSip������������Ϣ emMt_Cfg_SipSvr
	virtual TMtSipSvrAddr_Api GetSipSvrCfg()=0;

	virtual TMtSipSvrAddr_Api GetSipSvrManuCfg() = 0;

	//Socket5������������ emMt_Cfg_Socks5Pxy
	virtual u32 SetSocks5PxyCfgCmd( const TSocks5ProxyCfg_Api& tCfg );
	//��ȡSocket5������Ϣ emMt_Cfg_Socks5Pxy
	virtual TSocks5ProxyCfg_Api GetSocks5ProxyCfg()=0;

	//��¼����emMt_Cfg_SvrLoginTactics
	virtual u32 SetLoginTacticsCfgCmd( const TMtLoginTacticsTable_Api & tLoginCfg );
	virtual TMtLoginTacticsTable_Api GetLoginTacticsCfg( ) = 0;


	//��ȡ�ն˷�������¼״̬��Ϣ emMt_Rt_SvrLoginStatus
	virtual TMtSvrStateList_Api GetSvrStateList()=0;

	//��ȡ��½APS���ص��û�Ȩ��(value: TMTUserPrevilege)  emMt_Rt_UserPrevilege
	virtual TMtUserPrevilege_Api GetUserPrevilegeCfg()=0;

	//��½APS���ص��û���Ϣ (value: TMTUserInfoFromAps) emMt_Rt_UserInfoFromAps
	virtual TMTUserInfoFromAps_Api GetUserInfoFromApsRt()=0;

	//����H323�������� emMt_Cfg_H323
	virtual u32 SetH323CfgCmd( const TMtH323Cfg_Api& tCfg );
	//��ȡH323������Ϣ emMt_Cfg_H323
	virtual TMtH323Cfg_Api GetH323Cfg()=0;

	//����SIP�������� emMt_Cfg_Sip
	virtual u32 SetSipCfgCmd(const TMtSipCfg_Api &tCfg);
	//��ȡSIP������Ϣ emMt_Cfg_Sip
	virtual TMtSipCfg_Api GetSipCfg() = 0;
	
	//��������MC�������� emMt_Cfg_MC
	virtual u32 SetMCCfgCmd( const BOOL32 bEnable );
	// �����Ƿ���������MC emMt_Cfg_MC
	virtual BOOL32 IsUsedMC()=0;

	//������Ƶ���������������� emMt_Cfg_AudVolIn
	virtual u32 SetAudVolInCfgCmd( const u32 dwVolIn );
	// ��ȡ��Ƶ�������� emMt_Cfg_AudVolIn
	virtual u32 GetAudInVolCfg()=0;
	//������Ƶ��������������� emMt_Cfg_AudVolOut
	virtual u32 SetAudVolOutCfgCmd( const u32 dwVolOut );
	// ��ȡ��Ƶ������� emMt_Cfg_AudVolOut
	virtual u32 GetAudOutVolCfg()=0;
	//�����Զ��������� emMt_Cfg_Ans
	virtual u32 SetAudAnsCfg( const BOOL32 bAns );
	//��ȡ�Զ��������� emMt_Cfg_Ans
	virtual BOOL32 GetAudAnsCfg( ) = 0;
	//�����Զ�������� emMt_Cfg_Agc
	virtual u32 SetAudAgcCfg( const BOOL32 bAgc );
	//��ȡ�Զ�������� emMt_Cfg_Agc
	virtual BOOL32 GetAudAgcCfg( ) = 0;
	//�����Զ��������� emMt_Cfg_Aec
	virtual u32 SetAudAecCfg( const TAdjustAecParamCfg_Api & bAec );
	//��ȡ�Զ��������� emMt_Cfg_Aec
	virtual TAdjustAecParamCfg_Api GetAudAecCfg() = 0;
	//���ö����ش�������������emMt_Cfg_LostPktResend
	virtual u32 SetLostPackResendCfgCmd( const TPrsParam_Api& tCfg );
	//��ȡ�����ش�����������ϢemMt_Cfg_LostPktResend
	virtual TPrsParam_Api GetLostPackResendCfg()=0;
	//��������������������emMt_Cfg_AudioPrecedence
	virtual u32 SetAudioPrecedenceCfgCmd( const BOOL32  emCfg );
	// ������������emMt_Cfg_AudioPrecedence
	virtual BOOL32 GetAudioPrecedence()=0;

	//��������Ƶ����������  (value: TMTAllVideoEncoderParamCfg) emMt_Cfg_PriVidEncParam
	virtual u32 SetPriVidEncParamCfgCmd( const TMTAllVideoEncoderParamCfg_Api& tCfg );
	//��ȡ����Ƶ����������  (value: TMTAllVideoEncoderParamCfg) emMt_Cfg_PriVidEncParam
	virtual TMTAllVideoEncoderParamCfg_Api GetPriVidEncParamCfg()=0;
	//���ø���Ƶ����������  (value: TMTAllVideoEncoderParamCfg)emMt_Cfg_AssVidEncParam
	virtual u32 SetAssVidEncParamCfgCmd( const TMTAllVideoEncoderParamCfg_Api& tCfg );
	//��ȡ����Ƶ����������  (value: TMTAllVideoEncoderParamCfg)emMt_Cfg_AssVidEncParam
	virtual TMTAllVideoEncoderParamCfg_Api GetAssVidEncParamCfg()=0;
	//������Ƶ����������  (value: TMTAllVideoDecoderParamCfg)emMt_Cfg_VideoDecParam
	virtual u32 SetVideoDecParamCfgCmd( const TMTAllVideoDecoderParamCfg_Api& tCfg );
	//��ȡ��Ƶ����������  (value: TMTAllVideoDecoderParamCfg)emMt_Cfg_VideoDecParam
	virtual TMTAllVideoDecoderParamCfg_Api GetVideoDecParamCfg()=0;

	// ������Ƶ��ѡ emMt_Cfg_AudioPrior
	virtual u32 SetAudioPriorCfgCmd( const TMTAudioPriorCfg_Api &tCfg );
	// ��ȡ��Ƶ����ģʽ emMt_Cfg_AudioPrior
	virtual TMTAudioPriorCfg_Api GetAudioPriorCfg()=0;
	// ����������ѡ emMt_Cfg_PriVidPrior
	virtual u32 SetPriVidPriorCfgCmd( const TMTPriVidPriorCfg_Api &tCfg );
	// ��ȡ������ѡ emMt_Cfg_PriVidPrior
	virtual TMTPriVidPriorCfg_Api GetPriVidPriorCfg()=0;
	// ����Pc������ѡ emMt_Cfg_PcAssVidPrior
	virtual u32 SetPcAssVideoPriorCfgCmd( const TVidPriorParam_Api &tCfg );
	// ��ȡPc������ѡ emMt_Cfg_PcAssVidPrior
	virtual TVidPriorParam_Api GetPcAssVideoPriorCfg()=0;
	// ����Vid������ѡ emMt_Cfg_VidAssVidPrior
	virtual u32 SetVidAssVideoPriorCfgCmd( const TVidPriorParam_Api &tCfg );
	// ��ȡVid������ѡ emMt_Cfg_VidAssVidPrior
	virtual TVidPriorParam_Api GetVidAssVideoPriorCfg()=0;

	//���û������Ƿ������Ŷ�����Ч(value: TBOOL32)emMt_Cfg_PlayAniSoundInIdle
	virtual u32 SetPlayAniSoundInIdleCfgCmd( const BOOL32 bCfg );
	//��ȡ�������Ƿ������Ŷ�����Ч(value: TBOOL32)emMt_Cfg_PlayAniSoundInIdle
	virtual BOOL32 GetPlayAniSoundInIdleCfg()=0;
	//������ƵԴ (value: TMTCodecVidSrcInfo) emMt_cfg_CodecVideoSrc
	virtual u32 SetCodecVideoSrcCfgCmd( const TMTCodecVidSrcInfo_Api& tCfg );
	//��ȡ��ƵԴ (value: TMTCodecVidSrcInfo) emMt_cfg_CodecVideoSrc
	virtual TMTCodecVidSrcInfo_Api GetCodecVideoSrcCfg()=0;

	//����mc��������Ϣ(value: TInnerMCRunInfo) emMt_Rt_MCInfo
	virtual TInnerMCRunInfo_Api GetMCInfoRt()=0;

	// ��ȡ������Ϣ emMt_Rt_CallInfo
	virtual TMtCallLinkSate_Api GetCallInfoRt()=0;

	//��ǰ��ͨ��info�� (value: TMutiChanDsInfo) emMt_Rt_ChanInfo
	virtual TMutiChanDsInfo_Api GetChanInfoRt()=0;

	//�Ƿ��������նˣ� ��ƽ̨��ȡ(value: TMTSatelliteFlag) emMt_Rt_IsSatelliteMT
	virtual TMTSatelliteFlag_Api GetIsSatelliteMTRt()=0;

	//������ϯ��ѯ����   (value: TMTChrmanPollSchemeList) emMt_Cfg_ChrmanPollSchemes
	virtual u32 SetChrmanPollSchemesCfgCmd( const TMTChrmanPollSchemeList_Api& tCfg );
	//��ȡ��ϯ��ѯ����   (value: TMTChrmanPollSchemeList) emMt_Cfg_ChrmanPollSchemes
	virtual TMTChrmanPollSchemeList_Api GetChrmanPollSchemesCfg()=0;

	//������ϯ������������ emMt_Cfg_ChrmanOperate
	virtual u32 SetChairmanOperateCfgCmd( const BOOL32  bEnable );
	// �����Ƿ���ϯ���� emMt_Cfg_ChrmanOperate
	virtual BOOL32 IsUsedChairmanOptCtrl()=0;
	//���û���״̬��ʾ�������� emMt_Cfg_ShowConfState
	virtual u32 SetShowConfStateCfgCmd( const BOOL32  bEnable );
	// �����Ƿ���ʾ����״̬ emMt_Cfg_ShowConfState
	virtual BOOL32 IsUsedShowConfState()=0;

	//������ʾ����ʱ�� (value: TBOOL32)emMt_Cfg_ShowConfTime
	virtual u32 SetShowConfTimeCfgCmd( const BOOL32 bCfg );
	//��ȡ��ʾ����ʱ�� (value: TBOOL32)emMt_Cfg_ShowConfTime
	virtual BOOL32 GetShowConfTimeCfg()=0;
    //������ʾϵͳʱ�� (value: TBOOL32)emMt_Cfg_ShowSystimeTime
	virtual u32 SetShowSystimeTimeCfgCmd( const BOOL32 bCfg );
	//��ȡ��ʾϵͳʱ�� (value: TBOOL32)emMt_Cfg_ShowSystimeTime
	virtual BOOL32 GetShowSystimeTimeCfg()=0;
	//���û������Ƿ���ʾ����Ϣ (value: TBOOL32)emMt_Cfg_ShowShortMsgInConf
	virtual u32 SetShowShortMsgInConfCfgCmd( const BOOL32 bCfg );
	//��ȡ�������Ƿ���ʾ����Ϣ (value: TBOOL32)
	virtual BOOL32 GetShowShortMsgInConfCfg()=0;
	//�����Ƿ���ʾ������ʾ (value: TBOOL32)emMt_Cfg_ShowAppTips
	virtual u32 SetShowAppTipsCfgCmd( const BOOL32 bCfg );
	//��ȡ�Ƿ���ʾ������ʾ (value: TBOOL32)emMt_Cfg_ShowAppTips
	virtual BOOL32 GetShowAppTipsCfg()=0;

	//���÷��;�̬ͼƬ�������� emMt_Cfg_StaticPic
	virtual u32 SetStaticPicCfgCmd( const BOOL32  bEnable, const s8 *pszPicPath );
	// �����Ƿ����÷��;�̬ͼƬ emMt_Cfg_StaticPic
	virtual BOOL32 IsUsedSendStaticPic()=0;
	//�����Ƿ����õ绰������������ emMt_Cfg_Telephone
	virtual u32 SetTelephoneCfgCmd( const BOOL32  bEnable );
	// �����Ƿ����õ绰���� emMt_Cfg_Telephone
	virtual BOOL32 IsUsedUsedTelphonc()=0;
	//�����Զ������������� emMt_Cfg_AutoCall
	virtual u32 SetAutoCallCfgCmd( const TMTAutoCall_Api& tCfg );
	//��ȡ�Զ�����������Ϣ emMt_Cfg_AutoCall
	virtual TMTAutoCall_Api GetAutoCallCfg()=0;

	//�����Ƿ�����Զң (value: TBOOL32) emMt_Cfg_FECC 
	virtual u32 SetFECCCfgCmd( const BOOL32 bCfg );
	//��ȡ�Ƿ�����Զң (value: TBOOL32) emMt_Cfg_FECC 
	virtual BOOL32 GetFECCCfg()=0;

	//�����Զ���¼�������������� emMt_Cfg_AutoLogin
	virtual u32 SetAutoLoginCfgCmd( const BOOL32 bEnable );
	// �����Ƿ������Զ���¼������ emMt_Cfg_AutoLogin
	virtual BOOL32 IsAutoLogin()=0;
	//���÷ǶԳ������������� emMt_Cfg_AsymmetricNet
	virtual u32 SetAsymmetricNetCfgCmd( const TAsymmetricNetInfo_Api& tCfg );
	//��ȡ�ǶԳ�����������Ϣ emMt_Cfg_AsymmetricNet
	virtual TAsymmetricNetInfo_Api GetAsymmetricNetInfoCfg()=0;
	//�����������ǽ�������� emMt_Cfg_UseCallFW
	virtual u32 SetIncomingCallFWCfgCmd( const BOOL32 bEnable );
	// �����Ƿ������������ǽ emMt_Cfg_UseCallFW
	virtual BOOL32 IsUsedCallFirewall()=0;
	//���õ�ǰ�Ƿ����ô������������� emMt_Cfg_BandWidthTest
	virtual u32 SetBandwidthCheckCfgCmd( const BOOL32 bEnable );
	// �����Ƿ������Զ������� emMt_Cfg_BandWidthTest
	virtual BOOL32 IsAutoBandwidthCheck()=0;
	//��������MC�����ش������������� emMt_Cfg_MCResendParam
	virtual u32 SetMCRSParamCfgCmd( const TMTMcRSParam_Api& tCfg );
	//��ȡ����MC�����ش�����������Ϣ emMt_Cfg_MCResendParam
	virtual TMTMcRSParam_Api GetMcRSParamCfg()=0;
	//�����Զ�˫��Դ�������� emMt_Cfg_DualStramSrcAdj
	virtual u32 SetAssStreamSrcAdjustCfgCmd( const BOOL32 bEnable );
	// �����Ƿ���������˫��Դ emMt_Cfg_DualStramSrcAdj
	virtual BOOL32 IsUsedAssStreamSrcAuto()=0;
	//���ú���Э�������������� emMt_Cfg_CallProtocol
	virtual u32 SetCallProtocolCfgCmd( const EmConfProtocol_Api  emProtocol );
	// ��ȡ����Э������ emMt_Cfg_CallProtocol
	virtual EmConfProtocol_Api GetConfCallProtocol()=0;
	// ��ȡ����������� emMt_Cfg_EncryptType
	virtual u32 SetConfEncryptTypeCfgCmd( const EmEncryptArithmetic_Api emEncrypt );
	// ��ȡ����������� emMt_Cfg_EncryptType
	virtual EmEncryptArithmetic_Api GetConfEncryptTypeCfg()=0;
	//���ö������ʱ��������(��) emMt_Cfg_KeepAliveItrvl
	virtual u32 SetKeepAliveItrvlCfgCmd( const u32 dwSec );
	// ��ȡ�������ʱ������ emMt_Cfg_KeepAliveItrvl
	virtual u32 GetKeepAliveIntervalCfg()=0;
	//����Sip�������ʱ��������(��) emMt_Cfg_SipKeepAliveItrvl
	virtual u32 SetSipKeepAliveItrvlCfgCmd( const u32 dwSec );
	// ��ȡ�������ʱ������ emMt_Cfg_SipKeepAliveItrvl
	virtual u32 GetSipKeepAliveIntervalCfg()=0;
	//����FEC�������� emMt_Cfg_FEC
	virtual u32 SetFecInfoCfgCmd( const TMTFecInfo_Api& tCfg );
	//��ȡFEC������Ϣ emMt_Cfg_FEC
	virtual TMTFecInfo_Api GetFecInfoCfg()=0;
	//���ø��е͵��Ļ���������������(С��64�����Ǵ���Ƶ����)emMt_Cfg_CallRateLv
	virtual u32 SetCallRateLevelCmd( const u32  dwCallRate );
	// ��ȡ����������� emMt_Cfg_CallRateLv
	virtual u32 GetConfCallRateCfg()=0;
	//����˫�����ʱ����������� emMt_Cfg_VidBitRation
	virtual u32 SetVidBitRationCfgCmd( const TVidBitRationCfg_Api& tCfg );
	//��ȡ�������ͱ���������Ϣ emMt_Cfg_VidBitRation
	virtual TVidBitRationCfg_Api GetVidBitRationCfg()=0;
	//��ȡ�ն˰汾���������Ϣ emMt_Rt_TerlInfo
	virtual TTerminalInfo_Api GetTerminalInfoCfg()=0;
	//�����ն�������Ϣ�������� emMt_Cfg_TerminalName
	virtual u32 SetTerminalNameCfgCmd( const TMtTerminalName_Api& tCfg );
	//��ȡ�ն�����������Ϣ emMt_Cfg_TerminalName
	virtual TMtTerminalName_Api GetTerminalNameCfg()=0;

	//��½����
	virtual u32 SetTerminalLoginPwdCfgCmd( const TMtLoginPlatformPwdCfg_Api& tCfg );
	//��ȡ��½����emMt_Cfg_LoginPwd
	virtual TMtLoginPlatformPwdCfg_Api GetTerminalLoginPwdCfg()=0;

	//�������� (value: TString) emMt_Cfg_Email
	virtual u32 SetEmailCfgCmd( const s8* pchCfg );
	//��ȡ���� (value: TString) emMt_Cfg_Email
	virtual u32 GetEmailCfg( s8* pchEmail, u8 byCnt )=0;

	//����TCP/UDP��ʼ�˿�������Ϣ emMt_Cfg_Port
	virtual u32 SetUdpTcpBasePortCfg( const TTcpUdpBasePortCfg_Api &tCfg );
	//��ȡTCP/UDP��ʼ�˿�������Ϣ emMt_Cfg_Port
	virtual TTcpUdpBasePortCfg_Api GetUdpTcpBasePortCfg()=0;
	// �����Ƿ������ļ���־ emMt_Cfg_Log
	virtual u32 SetIsUsedFileLogon( BOOL32 bUsed );
	// ��ȡ�Ƿ������ļ���־ emMt_Cfg_Log
	virtual BOOL32 IsUsedFileLogon()=0;

	//ϵͳ����״̬ (TBOOL32)emMt_Rt_SysUpgrade
	virtual BOOL32 GetSysUpgradeRt( ) = 0;
	//����ҵ��ռ�õĶ˿�  (value: TMTUsedPortList)emMt_Rt_ConfUsedPorts
	virtual TMTUsedPortList_Api GetConfUsedPortsRt( ) = 0;
	//mcҵ��ռ�õĶ˿�   (value: TMTUsedPortList)emMt_Rt_McUsedPorts
	virtual TMTUsedPortList_Api GetMcUsedPortsRt( ) = 0;
	//vodҵ��ռ�õĶ˿�   (value: TMTUsedPortList)emMt_Rt_VodUsedPorts
	virtual TMTUsedPortList_Api GetVodUsedPortsRt( ) = 0;
	//����ҵ��ռ�õĶ˿�   (value: TMTUsedPortList)emMt_Rt_ImUsedPorts
	virtual TMTUsedPortList_Api GetImUsedPortsRt( ) = 0;
	//��¼IM����Ҫ�Ĳ��� (value: TImUserLogin)emMt_Rt_LoginIM
	virtual TImUserLogin_Api GetLoginIMParamCfg( ) = 0;

	//������ emMt_Rt_BandWidth
	virtual TMTNetStatus_Api GetBandWidth( ) = 0;

	//����ʱӳ��� (value: TMutiTServiceInfoRtData) emMt_Rt_SysCtrlSrvInfo
	virtual TMutiTServiceInfoRtData_Api GetSysCtrlSrvInfoRt()=0;
	//����ʱӳ�����ģ����� (value: TU32) emMt_Rt_SysCtrlSrvNum
	virtual u32 GetSysCtrlSrvNumRt()=0;
	//����Ĭ������ӳ��� (value: TMutiTServiceDefInfo) emMt_Cfg_SysCtrlDefSrvInfo
	virtual u32 SetSysCtrlDefSrvInfoCfgCmd( const TMutiTServiceDefInfo_Api& tCfg );
	//��ȡ����ӳ��� (value: TMutiTServiceDefInfo) emMt_Cfg_SysCtrlDefSrvInfo
	virtual TMutiTServiceDefInfo_Api GetSysCtrlDefSrvInfoCfg()=0;
	//����Ĭ��ӳ�����ģ����� (value: TU32) emMt_Cfg_SysCtrlDefSrvNum
	virtual u32 SetSysCtrlDefSrvNumCfgCmd( const u32 dwCfg );
	//��ȡĬ��ӳ�����ģ����� (value: TU32) emMt_Cfg_SysCtrlDefSrvNum
	virtual u32 GetSysCtrlDefSrvNumCfg()=0;

	//Ӧ��ģʽemMt_Cfg_AnswerMode
	virtual u32 SetAnswerModeCfgCmd( const u32 & dwAnswerMode );
	virtual u32 GetAnswerModeCfg( ) = 0;

	//��������emMt_Cfg_CallBitrate
	virtual u32 SetCallBitRateCfgCmd( const TMTCallBitRate_Api & tCallRate );
	virtual TMTCallBitRate_Api GetCallBitRateCfg( ) = 0;

	//�Զ��������ݹ��� emMt_Cfg_AutoSendSharedContent	(value:TBOOL32)
	virtual u32 SetAutoSendSharedContentCfgCmd( const BOOL32 bAuto );
	virtual BOOL32 GetAutoSendSharedContentCfg( ) = 0;
	//�Ƿ������½ƽ̨���� emMt_Cfg_LoginPlatformSrv(value:TBOOL32)
	virtual u32 SetLoginPlatformSrvCfgCmd( const BOOL32 bLogin );
	virtual BOOL32 GetLoginPlatformSrvCfg( ) = 0;
	
	//ƽ������ (value:TU32)
	virtual u32 SetSmoothSendCfgCmd( const u32 &dwSmoothSendLevel );
	virtual u32 GetSmoothSendCfg( ) = 0;
	//emMt_Cfg_UseTelnet,				///<ʹ��telnet���� (value:TBOOL32)
	virtual u32 SetUseTelnetCfgCmd( const BOOL32 bUse );
	virtual BOOL32 GetUseTelnetCfg( ) = 0;
	//emMt_Cfg_UseHTTP,				///<ʹ��Http���� (value:TBOOL32)
	virtual u32 SetUseHTTPCfgCmd( const BOOL32 bUse );
	virtual BOOL32 GetUseHTTPCfg( ) = 0;
	//emMt_Cfg_UseFtp,				///<ʹ��FTP���� (value:TBOOL32)
	virtual u32 SetUseFtpCfgCmd( const BOOL32 bUse );
	virtual BOOL32 GetUseFtpSrvCfg( ) = 0;

	//323Э��ջ�Ƿ��׼��( value: TBOOL32), ��׼ע�ᵽ1719���Ǳ�ע�ᵽ1759 emMt_Rt_IsH323StackStand
	virtual BOOL32 GetIsH323StackStandRt()=0;
	//323Э��ջ�����˿�( value: TU16) emMt_Rt_H323CallingPort
	virtual u16 GetH323CallingPortRt()=0;
	//����H.264 SVC  (value:TBOOL32)emMt_Cfg_H264Svc
	virtual u32 SetH264SvcCfgCmd( const BOOL32 bCfg );
	//��ȡH.264 SVC  (value:TBOOL32)emMt_Cfg_H264Svc
	virtual BOOL32 GetH264SvcCfg()=0;
	//������Ƶ�غ�����Ӧ  (value:TBOOL32)emMt_Cfg_LoadAdaptiveVideo
	virtual u32 SetLoadAdaptiveVideoCfgCmd( const BOOL32 bCfg );
	//��ȡ��Ƶ�غ�����Ӧ  (value:TBOOL32)emMt_Cfg_LoadAdaptiveVideo
	virtual BOOL32 GetLoadAdaptiveVideoCfg()=0;
	//��������mc������������ (value:TMTInnerMcAssVidCfg)emMt_Cfg_InnerMcAssVidCfg
	virtual u32 SetInnerMcAssVidCfgCmd( const TMTInnerMcAssVidCfg_Api& tCfg );
	//��ȡ����mc������������ (value:TMTInnerMcAssVidCfg)emMt_Cfg_InnerMcAssVidCfg
	virtual TMTInnerMcAssVidCfg_Api GetInnerMcAssVidCfg()=0;

	//H460���� (value:TMtH460PxyCfg)emMt_Cfg_H460
	virtual u32 SetH460CfgCmd( const TMtH460PxyCfg_Api& tCfg );
	//H460���� (value:TMtH460PxyCfg)emMt_Cfg_H460
	virtual TMtH460PxyCfg_Api GetH460Cfg()=0;
	//H323�������� (value:TMtH323PxyCfg)emMt_Cfg_H323Pxy
	virtual u32 SetH323PxyCfgCmd( const TMtH323PxyCfg_Api& tCfg );
	//H323�������� (value:TMtH323PxyCfg)emMt_Cfg_H323Pxy
	virtual TMtH323PxyCfg_Api GetH323PxyCfg()=0;

	//��������� (value: TMtMeetingSvrAddr)emMt_Rt_MeetingCtrl
	virtual TMtMeetingSvrAddr_Api GetMeetingCtrlSrvRt() = 0;

	///< ��¼IM����Ҫ�Ĳ��� (value: TImUserLogin) emMt_Cfg_LoginIMParam
	virtual u32 SetImLoginParamCfgCmd(const TImUserLogin_Api& tCfg);

	///< ��¼Aps����Ҫ�Ĳ��� (value: TMTApsLoginParam) emMt_Cfg_ApsLoginParam
	virtual u32 SetApsLoginParamCfgCmd(const TMTApsLoginParam_Api& tCfg);

	///< ��ȡ��¼Aps����Ҫ�Ĳ��� (value: TMTApsLoginParam) emMt_Cfg_ApsLoginParam
	virtual TMTApsLoginParam_Api GetApsLoginParamCfg() = 0;

	///< ��¼Sus����Ҫ�Ĳ��� (value: TMTUpgradeClientInfo) emMt_Cfg_SusLoginParam
	virtual u32 SetSusLoginParamCfgCmd(const TMTUpgradeClientInfo_Api& tCfg);

	///< ��¼Nms����Ҫ�Ŀͻ���Ӳ����Ϣ���� (value: TNMSClientHWInfo) emMt_Cfg_NmsClientHWInfo
	virtual u32 SetNmsClientHWInfoCfgCmd(const TNMSClientHWInfo_Api& tCfg);


	/********************Ӳ�ն˲�ƷKey��ʼ********************/

	//���ù�������Ϣ��������emHD_Cfg_ShortMsg
	virtual u32 SetHoriRollMsgCfgCmd( const TRollMsgCfg_Api& tCfg );
	//��ȡ��������Ϣ������ϢemHD_Cfg_ShortMsg
	virtual TRollMsgCfg_Api GetRollMsgCfg()=0;
	
	/**********�û�����**************/
	// ����˫����ʾģʽ emHD_Cfg_DispMode
	virtual u32 SetHDDispModeCfgCmd( const EmDualVideoShowMode_Api emMode );
	// ��ȡ˫����ʾģʽ emHD_Cfg_DispMode
	virtual EmDualVideoShowMode_Api GetHDDispModeCfg()=0;

	// ������Ƶ�����ʽ emHD_Cfg_HDResOutput
	virtual u32 SetHDResOutputCfgCmd( const THDMTVideoOutPortMode_Api &tVideoMode );
	// ��ȡ��Ƶ�����ʽ emHD_Cfg_HDResOutput
	virtual THDMTVideoOutPortMode_Api GetHDResOutputCfg()=0;

	// �����Ƿ����Զ����л� emHD_Cfg_AutoPIP
	virtual u32 SetHDAutoPIPCfgCmd( const BOOL32 bAuto );
	// ��ȡ�Ƿ����Զ����л� emHD_Cfg_AutoPIP
	virtual BOOL32 IsHDAutoPIPCfg()=0;

	// ���ú������� emHD_Cfg_CallInRing
	virtual u32 SetHDCallInRingCfgCmd( const u32 dwValue );
	// ��ȡ�������� emHD_Cfg_CallInRing
	virtual u32 GetHDCallInRingCfg()=0;

	// ���ú������� emHD_Cfg_CallOutRing
	virtual u32 SetHDCallOutRingCfgCmd( const u32 dwValue );
	// ��ȡ�������� emHD_Cfg_CallInRing
	virtual u32 GetHDCallOutRingCfg()=0;

	//���ź�������(value: TU32) emHD_Rt_CallInRing
	virtual u32 GetCallInRingRt()=0;
	//���ź�������(value: TU32) emHD_Rt_CallOutRing
	virtual u32 GetCallOutRingRt()=0;
	//���ò��Ű�����(value: TU32) emHD_Cfg_KeyboardRing
	virtual u32 SetKeyboardRingCfgCmd( const u32 dwCfg );
	//��ȡ���Ű�����(value: TU32) emHD_Cfg_KeyboardRing
	virtual u32 GetKeyboardRingCfg()=0;

	// ���õ�ǰʹ�õĺ��id�� emHD_Cfg_EnablePresetBanner
	virtual u32 SetHDPresetBannerCfgCmd( const THDMTEnablePresetBanner_Api &tValue );
	// ��ȡ��ǰʹ�õĺ��id�� emHD_Cfg_EnablePresetBanner
	virtual THDMTEnablePresetBanner_Api GetHDPresetBannerCfg()=0;

	// ����Osd������� emHD_Cfg_OsdBannerInfo
	virtual u32 SetHDOsdBannerInfoCfgCmd( const THDMTBannerInfo_Api &tValue );
	// ��ȡOsd������� emHD_Cfg_OsdBannerInfo
	virtual tagTHDMTBannerInfo_Api GetHDOsdBannerInfoCfg()=0;


	// ����Mtc������� emHD_Cfg_MtcBannerInfo
	virtual u32 SetHDMtcBannerInfoCfgCmd( const THDMTBannerInfoList_Api &tValue );
	// ��ȡMtc������� emHD_Cfg_MtcBannerInfo
	virtual u32 GetHDMtcBannerInfoCfg( THDMTBannerInfoList_Api  &tValue )=0;
	
	// ����̨������ emHD_Cfg_LabelInfo
	virtual u32 SetHDLabelInfoCfgCmd( const THDMTLabelInfo_Api &tValue );
	// ��ȡ̨������ emHD_Cfg_LabelInfo
	virtual THDMTLabelInfo_Api GetHDLabelInfoCfg()=0;

	// �����Զ��������� emHD_Cfg_AutoSleep
	virtual u32 SetHDAutoSleepCfgCmd( const THDMTAutoSleep_Api &tValue );
	// ��ȡ�Զ��������� emHD_Cfg_AutoSleep
	virtual THDMTAutoSleep_Api GetHDAutoSleepCfg()=0;

	// ����ʱ������ emHD_Cfg_SysTime
	virtual u32 SetHDSysTimeCfgCmd( const THDMTCfgSystemTime_Api &tValue );
	// ��ȡʱ������ emHD_Cfg_SysTime
	virtual THDMTCfgSystemTime_Api GetHDSysTimeCfg()=0;


	/**********����Ա����**********/
	// ����������� emHD_Cfg_MicGain
	virtual u32 SetHDMicGainCfgCmd( const u32 &dwValue );
	// ��ȡ������� emHD_Cfg_MicGain
	virtual u32 GetHDMicGainCfg()=0;
	
	// ���û�����������Ӧ emHD_Cfg_AecDebug
	virtual u32 SetHDAecDebugCfgCmd( const u32 &dwValue );
	// ��ȡ������������Ӧ emHD_Cfg_AecDebug
	virtual u32 GetHDAecDebugCfg()=0;
	
	// ������Ƶ����ӿ� emHD_Cfg_AudInPortList
	virtual u32 SetHDAudInPortListCfgCmd( const TMTHDAudInPortList_Api &tPortList );
	// ��ȡ��Ƶ����ӿ� emHD_Cfg_AudInPortList
	virtual TMTHDAudInPortList_Api GetHDAudInPortListCfg()=0;
	// ������Ƶ����ӿ� emHD_Cfg_AudOutPortList
	virtual u32 SetHDAudOutPortListCfgCmd( const THDMTHDAudOutPortList_Api &tPortList );
	// ��ȡ��Ƶ����ӿ� emHD_Cfg_AudOutPortList
	virtual THDMTHDAudOutPortList_Api GetHDAudOutPortListCfg()=0;

	// ���õ�һ·����Ƶ����˿� emHD_Cfg_Pri1stVidInPort
	virtual u32 SetHDPri1stVidInPortCfgCmd( const THDMTHDVidInPort_Api &tPort );
	// ��ȡ��һ·����Ƶ����˿� emHD_Cfg_Pri1stVidInPort
	virtual THDMTHDVidInPort_Api GetHDPri1stVidInPortCfg()=0;

	//���õڶ�·������Ƶ����˿�(value: TMTHDVidInPort ) emHD_Cfg_Pri2ndVidInPort
	virtual u32 SetHDPri2ndVidInPortCfgCmd( const THDMTHDVidInPort_Api &tPort );
	//��ȡ�ڶ�·������Ƶ����˿�(value: TMTHDVidInPort ) emHD_Cfg_Pri2ndVidInPort
	virtual THDMTHDVidInPort_Api GetHDPri2ndVidInPortCfg()=0;
	//���ø���Ƶ����˿�(value: TMTHDVidInPort ) emHD_Cfg_AssVidInPort
	virtual u32 SetHDAssVidInPortCfgCmd( const THDMTHDVidInPort_Api &tPort );
	//��ȡ����Ƶ����˿�(value: TMTHDVidInPort ) emHD_Cfg_AssVidInPort
	virtual THDMTHDVidInPort_Api GetHDAssVidInPortCfg()=0;

	// ���ö��ӻ���� emHD_Cfg_MultiVideo
	virtual u32 SetHDMultiVideotCfgCmd( const TMTHDMultiVideo_Api &tMultiVideo );
	// ���ö��ӻ���� emHD_Cfg_MultiVideo
	virtual TMTHDMultiVideo_Api GetHDMultiVideoCfg()=0;

	// ������Ƶ���� emHD_Cfg_VideoMatrixScheme
	virtual u32 SetHDVideoMatrixSchemeCfgCmd( const THDMTAllVideoMatrixScheme_Api &tValue );
	// ��ȡ��Ƶ���� emHD_Cfg_VideoMatrixScheme
	virtual THDMTAllVideoMatrixScheme_Api GetHDVideoMatrixSchemeListCfg()=0;

	// ������ͼ����ʾ���� emHD_Cfg_LastDisplay
	virtual u32 SetHDLastDisplayCfgCmd( const THDMTLastDisplay_Api &tValue );
	// ��ȡ��ͼ����ʾ���� emHD_Cfg_LastDisplay
	virtual THDMTLastDisplay_Api GetHDLastDisplayListCfg()=0;

	// ����ͼ����ȼ� emHD_Cfg_ImageNoiseLevel
	virtual u32 SetHDImageNoiseLevelCfgCmd( const THDMTImageNoise_Api &tValue );
	// ��ȡͼ����ȼ� emHD_Cfg_ImageNoiseLevel
	virtual THDMTImageNoise_Api GetHDImageNoiseLevelCfg()=0;

	// ����ͼ����ǿ���� emHD_Cfg_ImageEnhancement
	virtual u32 SetHDImageEnhancementCfgCmd( const BOOL32 bValue );
	// ��ȡͼ����ǿ���� emHD_Cfg_ImageEnhancement
	virtual BOOL32 GetHDImageEnhancementCfg()=0;

	//���õ�һ·����Ƶ��������(value: TMTHDImageDeformationTensile ) emHD_Cfg_Pri1stDeformationTensile
	virtual u32 SetHDPri1stDeformationTensileCfgCmd( const TMTHDImageDeformationTensile_Api &tCfg );
	//��ȡ��һ·����Ƶ��������(value: TMTHDImageDeformationTensile ) emHD_Cfg_Pri1stDeformationTensile
	virtual TMTHDImageDeformationTensile_Api GetHDPri1stDeformationTensileCfg()=0;

	//���õڶ�·����Ƶ��������(value: TMTHDImageDeformationTensile ) emHD_Cfg_Pri2ndDeformationTensile
	virtual u32 SetHDPri2ndDeformationTensileCfgCmd( const TMTHDImageDeformationTensile_Api &tCfg );
	//��ȡ�ڶ�·����Ƶ��������(value: TMTHDImageDeformationTensile ) emHD_Cfg_Pri2ndDeformationTensile
	virtual TMTHDImageDeformationTensile_Api GetHDPri2ndDeformationTensileCfg()=0;

	//���ø���Ƶ��������(value: TMTHDImageDeformationTensile ) emHD_Cfg_AssDeformationTensile
	virtual u32 SetHDAssDeformationTensileCfgCmd( const TMTHDImageDeformationTensile_Api &tCfg );
	//��ȡ����Ƶ��������(value: TMTHDImageDeformationTensile ) emHD_Cfg_AssDeformationTensile
	virtual TMTHDImageDeformationTensile_Api GetHDAssDeformationTensileCfg()=0;

	//���õ�һ·����Ƶ�ȱ�����(value: TMTHDImageGeometricScaling ) emHD_Cfg_Pri1stGeometricScaling
	virtual u32 SetHDPri1stGeometricScalingCfgCmd( const TMTHDImageGeometricScaling_Api &tCfg );
	//��ȡ��һ·����Ƶ�ȱ�����(value: TMTHDImageGeometricScaling ) emHD_Cfg_Pri1stGeometricScaling
	virtual TMTHDImageGeometricScaling_Api GetHDPri1stGeometricScalingCfg()=0;

	//���õڶ�·����Ƶ�ȱ�����(value: TMTHDImageGeometricScaling ) emHD_Cfg_Pri2ndGeometricScaling
	virtual u32 SetHDPri2ndGeometricScalingCfgCmd( const TMTHDImageGeometricScaling_Api &tCfg );
	//��ȡ�ڶ�·����Ƶ�ȱ�����(value: TMTHDImageGeometricScaling ) emHD_Cfg_Pri2ndGeometricScaling
	virtual TMTHDImageGeometricScaling_Api GetHDPri2ndGeometricScalingCfg()=0;

	//���ø���Ƶ�ȱ�����(value: TMTHDImageGeometricScaling )emHD_Cfg_AssGeometricScaling
	virtual u32 SetHDAssGeometricScalingCfgCmd( const TMTHDImageGeometricScaling_Api &tCfg );
	//��ȡ����Ƶ�ȱ�����(value: TMTHDImageGeometricScaling )emHD_Cfg_AssGeometricScaling
	virtual TMTHDImageGeometricScaling_Api GetHDAssGeometricScalingCfg()=0;

	//���õ�һ·����Ƶ�ñ�����(value: TU32 )emHD_Cfg_EdgePixel
	virtual u32 SetHDEdgePixelCfgCmd( const u32 &dwCfg );
	//��ȡ��һ·����Ƶ�ñ�����(value: TU32 )emHD_Cfg_EdgePixel
	virtual u32 GetHDEdgePixelCfg()=0;

	//�������������(value: TMTHDCameraList )emHD_Cfg_CameraList
	virtual u32 SetHDCameraListCfgCmd( const TMTHDCameraList_Api &tCfg );
	//��ȡ���������(value: TMTHDCameraList )emHD_Cfg_CameraList
	virtual TMTHDCameraList_Api GetHDCameraListCfg()=0;

	//���ô�������(value: TMTHDSerialCtrl )emHD_Cfg_SerialCtrl
	virtual u32 SetHDSerialCtrlCfgCmd( const TMTHDSerialCtrl_Api &tCfg );
	//��ȡ��������(value: TMTHDSerialCtrl )emHD_Cfg_SerialCtrl
	virtual TMTHDSerialCtrl_Api GetHDSerialCtrlCfg()=0;
	//���ô����б�(value: TMTHDSerialList)emHD_Cfg_SerialList
	virtual u32 SetSerialListCfgCmd(const TMTHDSerialList_Api &tCfg);
	//��ȡ�����б�(value: TMTHDSerialList)emHD_Cfg_SerialList
	virtual TMTHDSerialList_Api GetSerialListCfg()=0;
	//����VGAͼ����� (value:TMTVgaImageAdjustCfg)emHD_Cfg_VGAImageAdjust
	virtual u32 SetVGAImageAdjustCfgCmd( const TMTVgaImageAdjustCfg_Api& tCfg );
	//��ȡVGAͼ����� (value:TMTVgaImageAdjustCfg)emHD_Cfg_VGAImageAdjust
	virtual TMTVgaImageAdjustCfg_Api GetVGAImageAdjustCfg()=0;
	//������ƵԴ��ǩ (value:TMTVideoSrcTagList)emHD_Cfg_VideoSrcTag
	virtual u32 SetVideoSrcTagCfgCmd( const TMTVideoSrcTagList_Api& tCfg );
	//������Ƶ�����ǩ (value:TMTVideoOutTagList)emHD_Cfg_VideoOutag
	virtual u32 SetVideoOutTagCfgCmd( const TMTVideoOutTagList_Api& tCfg );
	//����SDIһ��һ����������(value: TU32)emHD_Cfg_SDIOneInOneOutOrTwoIn
	virtual u32 SetSDIOneInOneOutOrTwoInCfgCmd( const u32& dwtype );

	virtual u32 SetHDResizeModeCfgCmd(const TMTResizeMode_Api &tCfg);
	virtual TMTResizeMode_Api GetHDResizeModeCfg() = 0;
	
	//��ȡ��ƵԴ��ǩ (value:TMTVideoSrcTagList)emHD_Cfg_VideoSrcTag
	virtual TMTVideoSrcTagList_Api  GetVideoSrcTagCfg()=0;
	//��ȡ��Ƶ�����ǩ (value:TMTVideoOutTagList)emHD_Cfg_VideoOutTag
	virtual TMTVideoOutTagList_Api  GetVideoOutTagCfg()=0;
	//��ȡSDIһ��һ����������(value: TU32)emHD_Cfg_SDIOneInOneOutOrTwoIn
	virtual u32  GetSDIOneInOneOutOrTwoInCfg()=0;
	
	//���ÿ���FTP (value:TMTSnapShotFtpCfg)emHD_Cfg_SnapShotFtpCfg
	virtual u32 SetSnapShotFtpCfgCfgCmd( const TMTSnapShotFtpCfg_Api& tCfg );
	//��ȡ����FTP (value:TMTSnapShotFtpCfg)emHD_Cfg_SnapShotFtpCfg
	virtual TMTSnapShotFtpCfg_Api GetSnapShotFtpCfgCfg()=0;
	//����VGA�������(value: TU32)emHD_Cfg_VgaOutBright
	virtual u32 SetVgaOutBrightCfgCmd(const u32 &dwCfg);
	//��ȡVGA�������(value: TU32)emHD_Cfg_VgaOutBright
	virtual u32 GetVgaOutBrightCfg() = 0;
    //����VGA����Աȶ� (value : TU32)emHD_Cfg_VgaOutContrast
	virtual u32 SetVgaOutContrastCfgCmd(const u32 &dwCfg);
	//����VGA������Ͷ� (value : TU32)emHD_Cfg_VgaOutSaturation
	virtual u32 SetVgaOutSaturationCfgCmd(const u32 &dwCfg);

	//������Ƶ���ȡ��Աȶȡ����Ͷ�
	virtual u32 SetVidImgParamCmd(const EmCodecComponent_Api emCodecType,const EmCodecComponentIndex_Api emCodecIdx,const EmImgParam_Api emMsgSrc ,const u32 dwValue);


	//������Ƶ���ȡ��Աȶȡ����Ͷ� (value : TU32)emHD_Cfg_VgaOutSaturation
	//virtual u32 SetVidImgParamCmd(const u32 &dwCfg);
	//��ȡVGA����Աȶ� (value : TU32)emHD_Cfg_VgaOutContrast
	virtual u32 GetVgaOutContrastCfg() = 0;

	//��ȡVGA������Ͷ� (value : TU32)emHD_Cfg_VgaOutSaturation
	virtual u32 GetVgaOutSaturationCfg() = 0;


	//����Ԥ��λ��������   (value:TMTAllPreSetNameInfoCfg) emHD_Cfg_PresetNameInfo
	virtual u32 SetPresetNameInfoCfgCmd( const TAllMTPreSetNameInfoCfg_Api& tCfg );
	//��ȡԤ��λ��������   (value:TMTAllPreSetNameInfoCfg) emHD_Cfg_PresetNameInfo
	virtual TAllMTPreSetNameInfoCfg_Api GetPresetNameInfoCfg()=0;
	
	//�����������
	//< ·��������Ϣ(value: TRouteItemInfoList) emHD_Cfg_RouteCfgList
    virtual u32 SetRouteCfgListCfgCmd(const TRouteItemInfoList_Api &tCfg);
	virtual TRouteItemInfoList_Api GetRouteCfgListCfg() = 0;

	//< ��̫������ģʽ(value:TEthnetWorkModeList) emHD_Cfg_EthWorkModeList
	virtual u32 SetEthWorkModeListCfgCmd( const TEthnetWorkModeList_Api& tCfg );
	virtual TEthnetWorkModeList_Api GetEthWorkModeListCfg()=0;

	//< ��̫����Ϣ(value:TEthnetCfg) emHD_Cfg_EthnetCfg
	virtual u32 SetEthnetCfgCmd( const TEthnetCfg_Api& tCfg );
	virtual TEthnetCfg_Api GetEthnetCfg()=0;

	//< PPPoE������Ϣ(value:TEthnetPPPoECfg) emHD_Cfg_EthPPPoECfg
	virtual u32 SetEthPPPoECfgCmd( const TEthnetPPPoECfg_Api& tCfg );
	virtual TEthnetPPPoECfg_Api GetEthPPPoECfg()=0;

	//< Wifi����ģʽ (value:TWifiWorkMode) emHD_Cfg_WifiWorkMode
	virtual u32 SetWifiWorkModeCfgCmd( const TWifiWorkMode_Api& tCfg );
	virtual TWifiWorkMode_Api GetWifiWorkModeCfg()=0;

	//< Wifi-AP������Ϣ (value:TWifiApConfiguration) emHD_Cfg_WifiApCfg
	virtual u32 SetWifiApCfgCmd( const TWifiApConfiguration_Api& tCfg );
	virtual TWifiApConfiguration_Api GetWifiApCfg()=0;

	//< Wifi��Ϊclient�����Ӻ��������Ϣ (value:TWifiConfiguration) emHD_Cfg_WifiClientCfg
	virtual u32 SetWifiClientCfgCmd( const TWifiConfiguration_Api& tCfg );
	virtual TWifiConfiguration_Api GetWifiClientCfg()=0;

	//< E1��������Ϣ (value:TE1Cfg) emHD_Cfg_E1Cfg
	virtual u32 SetE1CfgCmd( const TE1Cfg_Api& tCfg );
	virtual TE1Cfg_Api GetE1Cfg() = 0;

	//< Wifi��Ϊclient���Ӻ����ϸ��Ϣ(value:TWifiCurDetailInfo) emHD_Rt_WifiCurConnectedInfo
	virtual TWifiCurDetailInfo_Api GetWifiCurConnectedInfoRt()=0;

	//< �ƶ�����3G/4G����ģʽ (value:TMobileDataWorkMode) emHD_Cfg_MobileDataWorkMode
	virtual u32 SetMobileDataWorkModeCfgCmd( const TMobileDataWorkMode_Api& tCfg );
	virtual TMobileDataWorkMode_Api GetMobileDataWorkModeCfg()=0;

	//< �ƶ�����3G/4G���Ӻ����ϸ��Ϣ(value:TMobileDataCurDetailInfo) emHD_Rt_MobileDataConnectedInfo
	virtual TMobileDataCurDetailInfo_Api GetMobileDataConnectedInfoRt()=0;

	//< ��ǰ����ͨѶ������IP��ϸ��Ϣ(value:TNetUsedInfo) emHD_Rt_NetUsedInfo
	virtual TNetUsedInfo_Api GetNetUsedInfoRt()=0;



	// ��������Ƶ��һ·��ʾ���� emHD_Cfg_MainFstDisplayRatio
	virtual u32 SetHDMainPriDisplayRatioCfgCmd( const THDMTDisplayRatio_Api &tDisplayRatio );
	// ��ȡ����Ƶ��һ·��ʾ���� emHD_Cfg_MainFstDisplayRatio
	virtual THDMTDisplayRatio_Api GetHDMainPriDisplayRatioCfg()=0;

	// ��������Ƶ�ڶ�·��ʾ���� emHD_Cfg_MainSecDisplayRatio
	virtual u32 SetHDMainSecDisplayRatioCfgCmd( const THDMTDisplayRatio_Api &tDisplayRatio );
	// ��ȡ����Ƶ�ڶ�·��ʾ���� emHD_Cfg_MainSecDisplayRatio
	virtual THDMTDisplayRatio_Api GetHDMainSecDisplayRatioCfg()=0;

	// ���ø���Ƶ��ʾ���� emHD_Cfg_AssDisplayRatio
	virtual u32 SetHDAssDisplayRatioCfgCmd( const THDMTDisplayRatio_Api &tDisplayRatio );
	// ��ȡ����Ƶ��ʾ���� emHD_Cfg_AssDisplayRatio
	virtual THDMTDisplayRatio_Api GetHDAssDisplayRatioCfg()=0;

	//����VGA���ͼ����� emHD_Cfg_VGAImageOutAdjust
	virtual u32 SetVGAImgOutAdjustCfgCmd( const TMTVgaImgOutAdjustCfg_Api tCfg );
	//��ȡVGA���ͼ����ڲ���
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


	/********************Ӳ�ն˲�ƷKey����********************/

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

	//���� �Ƿ�����IPW���ӷ�ʽ
	virtual u32 SetEnableIpwTypeCmd( const BOOL32 bEnable );
	//��ȡ �Ƿ�����IPW���ӷ�ʽ
	virtual BOOL32 GetEnableIpwTypeCfg() = 0;

	//��������ͷ��������
	virtual u32 SetCameraContrlExchangeCfgCmd( const BOOL32 bDirection );
	//��ȡ����ͷ��������
	virtual BOOL32 GetCameraContrlExchangeCfg() = 0;
	//��������ͷ�Ƿ�װ
	virtual u32 SetCameraHeadStandCfgCmd( const BOOL32 bHeadStand);
	//����������Ƿ�װ
	virtual BOOL32 GetCameraHeadStandCfg() = 0;

	//�����Ƿ���ʾ��᷽���/������ʾ
	virtual u32 SetShowInOutConfCfgCmd( const BOOL32 bShow );
	//��ȡ�Ƿ���ʾ��᷽���/������ʾ
	virtual BOOL32 GetShowInOutConfCfg() = 0;

	//�����Ƿ���ʾ�ն˽���ʱ��
	virtual u32 SetShowMtTimeCfgCmd( const BOOL32 bShow );
	//��ȡ�Ƿ���ʾ�ն˽���ʱ��
	virtual BOOL32 GetShowMtTimeCfg() = 0;

	//�������� sip���ӷ�ʽ
	virtual u32 SetSipConnectCfgCmd( const EmSipConnectType_Api emSipConnectType );
	//��ȡ���� sip���ӷ�ʽ
	virtual EmSipConnectType_Api GetSipConnectCfg() = 0;

	virtual u32 SetEnableStrongAutCmd( IN CONST BOOL32 bEnableAut );
	virtual BOOL32 GetEnableStrongAut() = 0;
	virtual BOOL32 GetIsBusiSecMtCfg() = 0;
	virtual BOOL32 GetLicenseIsValidCfg() = 0;
	virtual u32	   SetbEnableTlsCertCmd( IN CONST BOOL32 bEnable );
	virtual u32    SetbEnableGMTlsCertCmd( IN CONST BOOL32 bEnable );
	virtual BOOL32 GetbEnableTlsCertCfg() = 0;
	virtual BOOL32 GetbEnableGMTlsCertCfg() = 0;

	//����ʹ�õĴ��ڶ�д�ӿ�
	virtual u32 ChooseSerialUseCmd( IN CONST TMTHDSerialCtrl_Api tInfo, IN CONST BOOL32 bIsUse );
	virtual u32 OperaterSerialCmd( IN CONST TMtSerialOptParam_Api &tParam );
	//���õ�¼����
	virtual u32 SetLoginStrategyCfgCmd( const TMTLoginStrategy_Api tLoginStrategy );
	virtual TMTLoginStrategy_Api GetLoginStrategyCfg() = 0;
	//�����Ƿ���ʾHome��ť
	virtual u32 SetShowHomeButtonCfgCmd( const BOOL32 bShow );
	//��ȡ�Ƿ���ʾHome��ť
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
	// Qos����֪ͨ
	BOOL32 OnIPQoSCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// TCP/IP����䵥ԪMTU����֪ͨ
	BOOL32 OnMTUCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// NAT����֪ͨ
	BOOL32 OnNatCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// XAPP�������б�����֪ͨ
	BOOL32 OnXAPPListCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// ��ǰʹ�õ�XAPP����֪ͨ
	BOOL32 OnXAPPCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// CSU����������֪ͨ
	BOOL32 OnCSUCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	BOOL32 OnGKCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	// SUS��������������֪ͨ
	BOOL32 OnSUSCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// SNMP���ܷ���������֪ͨ
	BOOL32 OnNMSCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// NTS���ٷ���������֪ͨ
	BOOL32 OnNTSCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// NTPʱ�ӷ���������֪ͨ
	BOOL32 OnNTPCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//VOD����������֪ͨ
	BOOL32 OnVODCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//VRS����������֪ͨ
	BOOL32 OnVRSCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//StreamPlayer��ý������֪ͨ
	BOOL32 OnStreamPlayerCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//Sip����������֪ͨ
	BOOL32 OnSipSvrCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSipSvrManuCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//Socket5��������֪ͨ
	BOOL32 OnSocks5PxyCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//��������¼״̬֪ͨ
	BOOL32 OnSvrStateList_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//Xap��¼�ɹ����ȡ���û�Ȩ����Ϣ֪ͨ
	BOOL32 OnUserPrevilege_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//��ȡ��½APS���ص��û���Ϣ����(value: TMTUserInfoFromAps) emMt_Rt_UserInfoFromAps
	BOOL32 OnUserInfoFromApsRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//H323����֪ͨ
	BOOL32 OnH323Cfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//SIP����֪ͨ
	BOOL32 OnSipCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//����MC����֪ͨ
	BOOL32 OnMCCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	//��Ƶ������������֪ͨ
	BOOL32 OnAudVolInCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	//��Ƶ�����������֪ͨ
	BOOL32 OnAudVolOutCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//�Զ���������֪ͨ
	BOOL32 OnAudAnsCfg_Ntf(  mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//�Զ��������֪ͨ
	BOOL32 OnAudAgcCfg_Ntf(  mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//�Զ���������
	BOOL32 OnAudAecCfg_Ntf(  mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// �����ش�����֪ͨ
	BOOL32 OnLostPackResendCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// ������������֪ͨ
	BOOL32 OnAudioPrecedenceCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ��ȡ��Ƶ����֪ͨ emMt_Cfg_AudioPrior
	BOOL32 OnAudioPriorCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ��ȡ����Ƶ����֪ͨ emMt_Cfg_PriVidPrior
	BOOL32 OnPriVidPriorCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ��ȡPc����Ƶ����֪ͨ emMt_Cfg_PcAssVidPrior
	BOOL32 OnPcAssVideoPriorCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ��ȡVid����Ƶ����֪ͨ emMt_Cfg_VidAssVidPrior
	BOOL32 OnVidAssVideoPriorCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ��ϯ��������֪ͨ
	BOOL32 OnChairmanOperateCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ����״̬��ʾ����֪ͨ
	BOOL32 OnShowConfStateCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ���;�̬ͼƬ����֪ͨ
	BOOL32 OnStaticPicCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ���õ绰��������֪ͨ
	BOOL32 OnTelephoneCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// �����Զ���������֪ͨ
	BOOL32 OnAutoCallCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//�Զ���¼����������֪ͨ
	BOOL32 OnAutoLoginCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//�ǶԳ���������֪ͨ
	BOOL32 OnAsymmetricNetCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//�������ǽ����֪ͨ
	BOOL32 OnUseCallFWCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//��ǰ�Ƿ������Զ�����������֪ͨ
	BOOL32 OnUseBandwidthTestCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// ����MC�����ش���������֪ͨ
	BOOL32 OnMCRSParamCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// �Զ�˫��Դ����֪ͨ
	BOOL32 OnDualStreamSrcAdjustCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// ����Э����������֪ͨ
	BOOL32 OnCallProtocolCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// �����������֪ͨ
	BOOL32 OnEncryptTypeCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// �������ʱ��������֪ͨ
	BOOL32 OnKeepAliveItrvlCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// �������ʱ��������֪ͨ
	BOOL32 OnSipKeepAliveItrvlCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// FEC����֪ͨ
	BOOL32 OnFecInfoCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// TL���е͵�������������֪ͨ
	BOOL32 OnCallRateLevelCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode ); 
	// ˫�����ʱ�������֪ͨ
	BOOL32 OnVidBitRationCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//�ն˰汾��Ϣ֪ͨ(RT)
	BOOL32 OnTerminalInfo_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//�ն�������Ϣ����֪ͨ
	BOOL32 OnTerminalNameCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//�ն˵�¼��������֪ͨ
	BOOL32 OnLoginPwdCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//tcp|udp��ʵ�˿�����֪ͨ
	BOOL32 OnTcpUdpPortCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// �����ļ���־��������֪ͨ
	BOOL32 OnLogStatusCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//ϵͳ����״̬ (TBOOL32)emMt_Rt_SysUpgrade
	BOOL32 OnSysUpgradeRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//����ҵ��ռ�õĶ˿�  (value: TMTUsedPortList)emMt_Rt_ConfUsedPorts
	BOOL32 OnConfUsedPortsRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//mcҵ��ռ�õĶ˿�   (value: TMTUsedPortList)emMt_Rt_McUsedPorts
	BOOL32 OnMcUsedPortsRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//vodҵ��ռ�õĶ˿�   (value: TMTUsedPortList)emMt_Rt_VodUsedPorts
	BOOL32 OnVodUsedPortsRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//����ҵ��ռ�õĶ˿�   (value: TMTUsedPortList)emMt_Rt_ImUsedPorts
	BOOL32 OnImUsedPortsRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//��¼IM����Ҫ�Ĳ��� (value: TImUserLogin)emMt_Rt_LoginIM
	BOOL32 OnLoginIMParamCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//emHD_Cfg_AnswerMode
	BOOL32 OnAnswerMode_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnBandWidth_Ntf( mtmsg::CMtMsg * pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//����ʱӳ��� (value: TMutiTServiceInfoRtData) emMt_Rt_SysCtrlSrvInfo
	BOOL32 OnSysCtrlSrvInfoRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//����ʱӳ�����ģ����� (value: TU32) emMt_Rt_SysCtrlSrvNum
	BOOL32 OnSysCtrlSrvNumRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//��ȡ����ӳ��� (value: TMutiTServiceDefInfo) emMt_Cfg_SysCtrlDefSrvInfo
	BOOL32 OnSysCtrlDefSrvInfoCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//��ȡĬ��ӳ�����ģ����� (value: TU32) emMt_Cfg_SysCtrlDefSrvNum
	BOOL32 OnSysCtrlDefSrvNumCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//emHD_Cfg_CallBitrate
	BOOL32 OnCallRateCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//�Զ��������ݹ��� emMt_Cfg_AutoSendSharedContent	
	BOOL32 OnAutoSendSharedContentCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//�Ƿ������½ƽ̨���� emMt_Cfg_LoginPlatformSrv(value:TBOOL32)
	BOOL32 OnLoginPlatformSrvCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//ƽ������ (value:TU32)
	BOOL32 OnSmoothSendCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//ʹ��telnet���� (value:TBOOL32)
	BOOL32 OnUseTelnetCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//ʹ��Http���� (value:TBOOL32)
	BOOL32 OnUseHTTPCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//ʹ��FTP���� (value:TBOOL32)
	BOOL32 OnUseFtpCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//�Ƿ�����SIP���� emMt_Cfg_UseSIPSrv	(value:TBOOL32)
	BOOL32 OnUseSIPSrvCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	BOOL32 OnServerLoginTacticsCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//323Э��ջ�Ƿ��׼��( value: TBOOL32), ��׼ע�ᵽ1719���Ǳ�ע�ᵽ1759 emMt_Rt_IsH323StackStand
	BOOL32 OnIsH323StackStandRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//323Э��ջ�����˿�( value: TU16) emMt_Rt_H323CallingPort
	BOOL32 OnH323CallingPortRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//��ȡH.264 SVC  (value:TBOOL32)emMt_Cfg_H264Svc
	BOOL32 OnH264SvcCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//��ȡ��Ƶ�غ�����Ӧ  (value:TBOOL32)emMt_Cfg_LoadAdaptiveVideo
	BOOL32 OnLoadAdaptiveVideoCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//��ȡ����mc������������ (value:TMTInnerMcAssVidCfg)emMt_Cfg_InnerMcAssVidCfg
	BOOL32 OnInnerMcAssVidCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	/*H460���� (value:TMtH460PxyCfg)*/
	BOOL32 OnH460Cfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//H323�������� (value:TMtH323PxyCfg)emMt_Cfg_H323Pxy
	BOOL32 OnH323PxyCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	//PlatForm address
	BOOL32 OnPlatformCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//microblog address
	BOOL32 OnMicroBlogCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	///< ��¼Sus����Ҫ�Ĳ��� (value: TMTUpgradeClientInfo) emMt_Cfg_SusLoginParam
	BOOL32 OnSusLoginParamCfgNtf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	/********************Ӳ�ն˲�ƷKey��ʼ********************/
	/*******************************************************/
	//emHD_Cfg_ConfDisp

	//���ù�������Ϣ��������
	BOOL32 OnHoriRollMsgCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	
	/**********�û�����**************/
	// ����˫����ʾģʽ֪ͨ emHD_Cfg_DispMode
	BOOL32 OnHDDispModeCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ������Ƶ�����ʽ֪ͨ emHD_Cfg_HDResOutput
	BOOL32 OnHDResOutputCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// �����Ƿ����Զ����л�֪ͨ emHD_Cfg_AutoPIP
	BOOL32 OnHDAutoPIPCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ���ú�������֪ͨ emHD_Cfg_CallInRing
	BOOL32 OnHDCallInRingCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ���ú�������֪ͨ emHD_Cfg_CallOutRing
	BOOL32 OnHDCallOutRingCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ���õ�ǰʹ�õĺ��id��֪ͨ emHD_Cfg_EnablePresetBanner
	BOOL32 OnHDPresetBannerCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ����osd�������֪ͨ emHD_Cfg_OsdBannerInfo
	BOOL32 OnHDOsdBannerInfoCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	// ����Mtc�������֪ͨ emHD_Cfg_MtcBannerInfo
	BOOL32 OnHDMtcBannerInfoCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ����̨������֪ͨ emHD_Cfg_LabelInfo
	BOOL32 OnHDLabelInfoCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// �����Զ���������֪ͨ emHD_Cfg_AutoSleep
	BOOL32 OnHDAutoSleepCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ����ʱ������֪ͨ emHD_Cfg_SysTime
	BOOL32 OnHDSysTimeCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	/**********����Ա����**********/
	// �����������֪ͨ emHD_Cfg_MicGain
	BOOL32 OnHDMicGainCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ���û�����������Ӧ֪ͨ emHD_Cfg_AecDebug
	BOOL32 OnHDAecDebugCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ������Ƶ����ӿ�֪ͨ emHD_Cfg_AudInPortList
	BOOL32 OnHDAudInPortListCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ������Ƶ����ӿ�֪ͨ emHD_Cfg_AudOutPortList
	BOOL32 OnHDAudOutPortListCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ����������Ƶ����˿�֪ͨ emHD_Cfg_Pri1stVidInPort
	BOOL32 OnHDPri1stVidInPortCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ���õڶ�·������Ƶ����˿�֪ͨ emHD_Cfg_Pri2ndVidInPort
	BOOL32 OnHDPri2ndVidInPortCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ���ø���Ƶ����˿�֪ͨ emHD_Cfg_AssVidInPort
	BOOL32 OnHDAssVidInPortCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ���ö��ӻ����֪ͨ emHD_Cfg_MultiVideo
	BOOL32 OnHDMultiVideotCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ������Ƶ�����ʾ����֪ͨ emHD_Cfg_DisplayRatio
	BOOL32 OnHDDisplayRatioCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ������Ƶ����֪ͨ emHD_Cfg_VideoMatrixScheme
	BOOL32 OnHDVideoMatrixSchemeCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ������ͼ����ʾ����֪ͨ emHD_Cfg_LastDisplay
	BOOL32 OnHDLastDisplayCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ����ͼ����ȼ�֪ͨ emHD_Cfg_ImageNoiseLevel
	BOOL32 OnHDImageNoiseLevelCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ͼ����ǿ����֪ͨ emHD_Cfg_ImageEnhancement
	BOOL32 OnHDImageEnhancementCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	//���õ�һ·����Ƶ��������(value: TMTHDImageDeformationTensile ) emHD_Cfg_Pri1stDeformationTensile
	BOOL32 OnHDPri1stDeformationTensileCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//���õڶ�·����Ƶ��������(value: TMTHDImageDeformationTensile ) emHD_Cfg_Pri2ndDeformationTensile
	BOOL32 OnHDPri2ndDeformationTensileCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//���ø���Ƶ��������(value: TMTHDImageDeformationTensile ) emHD_Cfg_AssDeformationTensile
	BOOL32 OnHDAssDeformationTensileCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//���õ�һ·����Ƶ�ȱ�����(value: TMTHDImageGeometricScaling ) emHD_Cfg_Pri1stGeometricScaling
	BOOL32 OnHDPri1stGeometricScalingCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//���õڶ�·����Ƶ�ȱ�����(value: TMTHDImageGeometricScaling ) emHD_Cfg_Pri2ndGeometricScaling
	BOOL32 OnHDPri2ndGeometricScalingCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//���ø���Ƶ�ȱ�����(value: TMTHDImageGeometricScaling )emHD_Cfg_AssGeometricScaling
	BOOL32 OnHDAssGeometricScalingCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//���õ�һ·����Ƶ�ñ�����(value: TU32 )emHD_Cfg_EdgePixel
	BOOL32 OnHDEdgePixelCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//�������������(value: TMTHDCameraList )emHD_Cfg_CameraList
	BOOL32 OnHDCameraListCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//���ô�������(value: TMTHDSerialCtrl )emHD_Cfg_SerialCtrl
	BOOL32 OnHDSerialCtrlCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );


	//������Ƶ���ȡ��Աȶȡ����Ͷ��ϱ�
	BOOL32 OnHDSetVidImgParam_Ntf(mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode);
	/*******************************************************/
	//�������ݻ��� emMt_Cfg_DCS (value: TMtDCSSvrAddr) 
	BOOL32 OnDCSCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//��������Ƶ����������  (value: TMTAllVideoEncoderParamCfg) emMt_Cfg_PriVidEncParam
	BOOL32 OnPriVidEncParamCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//���ø���Ƶ����������  (value: TMTAllVideoEncoderParamCfg)emMt_Cfg_AssVidEncParam
	BOOL32 OnAssVidEncParamCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//������Ƶ����������  (value: TMTAllVideoDecoderParamCfg)emMt_Cfg_VideoDecParam
	BOOL32 OnVideoDecParamCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//���û������Ƿ������Ŷ�����Ч(value: TBOOL32)emMt_Cfg_PlayAniSoundInIdle
	BOOL32 OnPlayAniSoundInIdleCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//������ƵԴ (value: TMTCodecVidSrcInfo) emMt_cfg_CodecVideoSrc
	BOOL32 OnCodecVideoSrcCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//����mc��������Ϣ(value: TInnerMCRunInfo) emMt_Rt_MCInfo
	BOOL32 OnMCInfoRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	// ��ȡ������Ϣ emMt_Rt_CallInfo
	BOOL32 OnGetCallInfoRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//��ǰ��ͨ��info�� (value: TMutiChanDsInfo) emMt_Rt_ChanInfo
	BOOL32 OnGetChanInfoRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//��ѯ��Ϣ(value: TMtPollInfo) emMt_Rt_PollInfo
	BOOL32 OnGetPollInfoRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//�Ƿ��������նˣ� ��ƽ̨��ȡ(value: TMTSatelliteFlag) emMt_Rt_IsSatelliteMT
	BOOL32 OnGetIsSatelliteMTRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//������ϯ��ѯ����   (value: TMTChrmanPollSchemeList) emMt_Cfg_ChrmanPollSchemes
	BOOL32 OnChrmanPollSchemesCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//������ʾ����ʱ�� (value: TBOOL32)emMt_Cfg_ShowConfTime
	BOOL32 OnShowConfTimeCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//������ʾϵͳʱ�� (value: TBOOL32)emMt_Cfg_ShowSystimeTime
	BOOL32 OnShowSystimeTimeCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//���û������Ƿ���ʾ����Ϣ (value: TBOOL32)emMt_Cfg_ShowShortMsgInConf
	BOOL32 OnShowShortMsgInConfCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//�����Ƿ���ʾ������ʾ (value: TBOOL32)emMt_Cfg_ShowAppTips
	BOOL32 OnShowAppTipsCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//�����Ƿ�����Զң (value: TBOOL32) emMt_Cfg_FECC 
    BOOL32 OnFECCCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//�������� (value: TString) emMt_Cfg_Email
    BOOL32 OnEmailCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//���ź�������(value: TU32) emHD_Rt_CallInRing
	BOOL32 OnCallInRingRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//���ź�������(value: TU32) emHD_Rt_CallOutRing
	BOOL32 OnCallOutRingRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//���ò��Ű�����(value: TU32) emHD_Cfg_KeyboardRing
	BOOL32 OnHDKeyboardRingCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//����VGAͼ����� (value:TMTVgaImageAdjustCfg)emHD_Cfg_VGAImageAdjust
	BOOL32 OnVGAImageAdjustCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//������ƵԴ��ǩ (value:TMTVideoSrcTagList)emHD_Cfg_VideoSrcTag
	BOOL32 OnVideoSrcTagCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//���ÿ���FTP (value:TMTSnapShotFtpCfg)emHD_Cfg_SnapShotFtpCfg
	BOOL32 OnSnapShotFtpCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//����VGA������� (value : TU32)emHD_Cfg_VgaOutBright
	BOOL32 OnVgaOutBrightCfg_Ntf(mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode);
	//����VGA����Աȶ� (value : TU32)emHD_Cfg_VgaOutContrast
	BOOL32 OnVgaOutContrast_Ntf(mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode);
	BOOL32 OnVgaOutSaturation_Ntf(mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode);
	//< Ԥ��λ��������   (value:TMTAllPreSetNameInfoCfg) emHD_Cfg_PresetNameInfo
	BOOL32 OnPresetNameInfoCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	//�����������
	//< ·��������Ϣ(value: TRouteItemInfoList) emHD_Cfg_RouteCfgList
    BOOL32 OnRouteCfgListCfg_Ntf(mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode);
	//< ��̫������ģʽ(value:TEthnetWorkModeList) emHD_Cfg_EthWorkModeList
	BOOL32 OnEthWorkModeListCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//< ��̫����Ϣ(value:TEthnetCfg) emHD_Cfg_EthnetCfg
	BOOL32 OnEthnetCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//< PPPoE������Ϣ(value:TEthnetPPPoECfg) emHD_Cfg_EthPPPoECfg
	BOOL32 OnEthPPPoECfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//< Wifi����ģʽ (value:TWifiWorkMode) emHD_Cfg_WifiWorkMode
	BOOL32 OnWifiWorkModeCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//< Wifi-AP������Ϣ (value:TWifiApConfiguration) emHD_Cfg_WifiApCfg
	BOOL32 OnWifiApCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//< Wifi��Ϊclient�����Ӻ��������Ϣ (value:TWifiConfiguration) emHD_Cfg_WifiClientCfg
	BOOL32 OnWifiClientCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//< E1��������Ϣ (value:TE1Cfg) emHD_Cfg_E1Cfg
	BOOL32 OnE1Cfg_Ntf(mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode);
	//< Wifi��Ϊclient���Ӻ����ϸ��Ϣ(value:TWifiCurDetailInfo) emHD_Rt_WifiCurConnectedInfo
	BOOL32 OnWifiCurConnectedInfoRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//< �ƶ�����3G/4G����ģʽ (value:TMobileDataWorkMode) emHD_Cfg_MobileDataWorkMode
	BOOL32 OnMobileDataWorkModeCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//< �ƶ�����3G/4G���Ӻ����ϸ��Ϣ(value:TMobileDataCurDetailInfo) emHD_Rt_MobileDataConnectedInfo
	BOOL32 OnMobileDataConnectedInfoRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	//< ��ǰ����ͨѶ������IP��ϸ��Ϣ(value:TNetUsedInfo) emHD_Rt_NetUsedInfo
	BOOL32 OnNetUsedInfoRt_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );




	// ����Ƶ��һ·��ʾ���� emHD_Cfg_MainFstDisplayRatio
	BOOL32 OnHDMainPriDisplayRatioCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	// ����Ƶ�ڶ�·��ʾ���� emHD_Cfg_MainSecDisplayRatio
	BOOL32 OnHDMainSecDisplayRatioCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	// ����Ƶ��ʾ���� emHD_Cfg_AssDisplayRatio
	BOOL32 OnHDAssDisplayRatioCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	BOOL32 OnHDResizeModeCfg_Ntf( mtmsg::CMtMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );

	/********************Ӳ�ն˲�ƷKey����********************/

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