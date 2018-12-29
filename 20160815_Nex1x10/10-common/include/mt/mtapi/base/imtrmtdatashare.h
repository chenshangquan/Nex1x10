/**===========================================================================
 * @file    $Id$
 * @brief   负责数据共享请求相关功能接口定义
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
 * @brief   负责终端基础配置请求相关功能接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtRmtDataShare : public IMtDataShare
{
public:
	//获取Qos配置请求
	virtual u32 GetIPQoSCfgReq() = 0;
	//获取MTU TCP/IP最大传输单元配置请求
	virtual u32 GetMTUCfgReq() = 0;
	//获取NAT配置请求
	virtual u32 GetNatCfgReq() = 0;


	//获取XAPList配置请求
	virtual u32 GetXAPListCfgReq() = 0;
	//获取摄像机配置
	virtual u32 GetAicameraCfgReq() = 0;
	//获取当前使用的XAP服务器配置请求
	virtual u32 GetCurXAPCfgReq() = 0;
	//获取XNU服务器(XMPP登录)配置请求
	virtual u32 GetXNUCfgReq() = 0;
    //获取NS指针
    virtual u32 GetNSRtReq() = 0;
	//获取CSU服务器配置请求
	virtual u32 GetCSUCfgReq() = 0;
	virtual u32 GetGkCfgReq() = 0;
	//获取SUS服务器配置请求
	virtual u32 GetSUSCfgReq() = 0;
	virtual u32 GetSusManuCfgReq() = 0;
	//获取网管服务器配置请求
	virtual u32 GetSNMPCfgReq() = 0;
	virtual u32 GetSNMPManuCfgReq() = 0;
	//获取测速服务器配置请求
	virtual u32 GetNTSCfgReq() = 0;
	virtual u32 GetNtsManuCfgReq() = 0;
	//获取NTP服务器配置请求
	virtual u32 GetNTPCfgReq() = 0;
	virtual u32 GetNtpManuCfgReq() = 0;
	//获取VOD服务器配置请求
	virtual u32 GetVODCfgReq() = 0;
	//获取VRS服务器配置请求
	virtual u32 GetVRSCfgReq() = 0;

	//获取数据会议 emMt_Cfg_DCS (value: TMtDCSSvrAddr) 
	virtual u32 GetDCSCfgReq() = 0;


	//获取StreamPlayer流媒体配置请求
	virtual u32 GetStreamPlayerCfgReq() = 0;
	//获取API服务器地址请求
	virtual u32 GetPlatformApiRtCfgReq() = 0;
	//获取微博服务器地址
	virtual u32 GetMicroBlogRtCfgReq() = 0;
	//获取Sip服务器配置请求
	virtual u32 GetSipSvrCfgReq() = 0;
	virtual u32 GetManuSipSvrCfgReq() = 0;
	//获取Socket5代理配置请求
	virtual u32 GetSocks5PxyCfgReq() = 0;
	//获取服务器登录状态请求(RT)
	virtual u32 GetSvrStateListReq() = 0;
	//获取Xap登录成功后获取的用户权限信息请求(RT)
	virtual u32 GetUserPrevilegeReq() = 0;
	//获取登陆APS返回的用户信息请求(value: TMTUserInfoFromAps) emMt_Rt_UserInfoFromAps
	virtual u32 GetUserInfoFromApsRtReq() = 0;
	//获取H323配置请求
	virtual u32 GetH323CfgReq() = 0;
	//获取SIP配置请求
	virtual u32 GetSipCfgReq() = 0;
	// 平滑发送等级 (value:TU32)
	virtual u32 GetSmoothSendCfgReq( ) = 0;
	//emMt_Cfg_UseTelnet,				///<使用telnet开关 (value:TBOOL32)
	virtual u32 GetUseTelnetCfgReq( ) = 0;
	//emMt_Cfg_UseHTTP,				///<使用Http开关 (value:TBOOL32)
	virtual u32 GetUseHTTPCfgReq( ) = 0;
	//emMt_Cfg_UseFtp,				///<使用FTP开关 (value:TBOOL32)
	virtual u32 GetUseFtpSrvCfgReq( ) = 0;
	//获取内置MC配置请求
	virtual u32 GetMCCfgReq() = 0;
	//获取音频输入音量配置请求
	virtual u32 GetAudVolInCfgReq() = 0;
	//获取音频输出音量配置请求
	virtual u32 GetAudVolOutCfgReq() = 0;
	//获取丢包重传参数配置请求
	virtual u32 GetLostPackResendCfgReq( ) = 0;
	//获取音质优先配置请求
	virtual u32 GetAudioPrecedenceCfgReq( ) = 0;

	//获取主视频编码器参数  (value: TMTAllVideoEncoderParamCfg) emMt_Cfg_PriVidEncParam
	virtual u32 GetPriVidEncParamCfgReq() = 0;
	//获取辅视频编码器参数  (value: TMTAllVideoEncoderParamCfg)emMt_Cfg_AssVidEncParam
	virtual u32 GetAssVidEncParamCfgReq() = 0;
	//获取视频解码器参数  (value: TMTAllVideoDecoderParamCfg)emMt_Cfg_VideoDecParam
	virtual u32 GetVideoDecParamCfgReq() = 0;

	// 获取音频优先请求 emMt_Cfg_AudioPrior
	virtual u32 GetAudioPriorCfgReq()=0;
	// 获取主流优选请求 emMt_Cfg_PriVidPrior
	virtual u32 GetPriVidPriorCfgReq()=0;
	// 获取Pc辅流优选请求 emMt_Cfg_PcAssVidPrior
	virtual u32 GetPcAssVideoPriorCfgReq()=0;
	// 获取Vid辅流优选请求 emMt_Cfg_VidAssVidPrior
	virtual u32 GetVidAssVideoPriorCfgReq()=0;

	//获取会议中是否允许播放动画音效(value: TBOOL32)emMt_Cfg_PlayAniSoundInIdle
	virtual u32 GetPlayAniSoundInIdleCfgReq() = 0;
	//获取视频源 (value: TMTCodecVidSrcInfo) emMt_cfg_CodecVideoSrc
	virtual u32 GetCodecVideoSrcCfgReq() = 0;

	//内置mc的运行信息(value: TInnerMCRunInfo) emMt_Rt_MCInfo
	virtual u32 GetMCInfoRtReq() = 0;

	// 获取呼叫信息请求 emMt_Rt_CallInfo
	virtual u32 GetCallInfoRtReq()=0;

	//当前的通道info， (value: TMutiChanDsInfo) emMt_Rt_ChanInfo
	virtual u32 GetChanInfoRtReq() = 0;

	//是否是卫星终端， 从平台获取(value: TMTSatelliteFlag) emMt_Rt_IsSatelliteMT
	virtual u32 GetIsSatelliteMTRtReq() = 0;

	//获取主席轮询方案   (value: TMTChrmanPollSchemeList) emMt_Cfg_ChrmanPollSchemes
	virtual u32 GetChrmanPollSchemesCfgReq() = 0;

	//获取主席操作配置请求
	virtual u32 GetChairmanOperateCfgReq() = 0;
	//获取会议状态显示配置请求
	virtual u32 GetShowConfStateCfgReq() = 0;

	//获取显示会议时间 (value: TBOOL32)emMt_Cfg_ShowConfTime
	virtual u32 GetShowConfTimeCfgReq() = 0;
	//获取显示系统时间 (value: TBOOL32)emMt_Cfg_ShowSystimeTime
	virtual u32 GetShowSystimeTimeCfgReq() = 0;
	//获取会议中是否显示短消息 (value: TBOOL32)emMt_Cfg_ShowShortMsgInConf
	virtual u32 GetShowShortMsgInConfCfgReq() = 0;
	//获取是否显示申请提示 (value: TBOOL32)emMt_Cfg_ShowAppTips
	virtual u32 GetShowAppTipsCfgReq() = 0;

	//获取发送静态图片配置请求
	virtual u32 GetStaticPicCfReq() = 0;
	//获取启用电话功能配置请求
	virtual u32 GetTelephoneCfgReq() = 0;
	//获取自动呼叫配置请求
	virtual u32 GetAutoCallCfgReq() = 0;

	//获取是否允许远遥 (value: TBOOL32) emMt_Cfg_FECC 
	virtual u32 GetFECCCfgReq() = 0;

	//获取自动登录服务器配置请求
	virtual u32 GetAutoLoginCfgReq( )= 0;;
	//获取非对称网络配置请求
	virtual u32 GetAsymmetricNetCfgReq() = 0;
	//获取来电防火墙配置请求
	virtual u32 GetIncomingCallFWCfgReq() = 0;
	//获取当前是否启用带宽检测配置请求
	virtual u32 GetBandwidthCheckCfgReq() = 0;
	//获取内置MC丢包重传参数配置请求
	virtual u32 GetMCRSParamCfgReq( ) = 0;
	//获取自动双流源配置请求
	virtual u32 GetAssStreamSrcAdjustCfgReq( ) = 0;
	//获取呼叫协议类型配置请求
	virtual u32 GetCallProtocolCfgReq() = 0;
	// 获取会议加密类型请求
	virtual u32 GetConfEncryptTypeCfgReq()=0;
	//获取断链检测时间间隔配置请求
	virtual u32 GetKeepAliveItrvlCfgReq() = 0;
	//获取断链检测时间间隔配置请求
	virtual u32 GetSipKeepAliveItrvlCfgReq() = 0;
	//获取设置FEC配置请求
	virtual u32 GetFecInfoCfgReq( ) = 0;
	//获取高中低档的会议码率配置请求(小于64任务是纯音频呼叫)
	virtual u32 GetCallRateLevelReq( ) = 0;
	//自动发送内容共享 emMt_Cfg_AutoSendSharedContent	
	virtual u32 GetAutoSendSharedContentCfgReq( ) = 0;
	//是否允许登陆平台服务 emMt_Cfg_LoginPlatformSrv(value:TBOOL32)
	virtual u32 GetLoginPlatformSrvCfgReq( ) = 0;
	
	//获取双流码率比例配置请求
	virtual u32 GetVidBitRationCfgReq( ) = 0;
	//获取终端版本信息配置请求(RT)
	virtual u32 GetTerminalInfoReq( ) = 0;
	//获取终端名称信息配置请求
	virtual u32 GetTerminalNameCfgReq( ) = 0;

	virtual u32 GetAnswerModeCfgReq( ) = 0;

	virtual u32 GetBandWidthReq() = 0;


	virtual u32 GetCallRateCfgReq() = 0;

	virtual u32 GetLoginTacticsCfgReq() = 0;

	//323协议栈是否标准的( value: TBOOL32), 标准注册到1719，非标注册到1759 emMt_Rt_IsH323StackStand
	virtual u32 GetIsH323StackStandRtReq() = 0;
	//323协议栈侦听端口( value: TU16) emMt_Rt_H323CallingPort
	virtual u32 GetH323CallingPortRtReq() = 0;
	//获取H.264 SVC  (value:TBOOL32)emMt_Cfg_H264Svc
	virtual u32 GetH264SvcCfgReq() = 0;
	//获取视频载荷自适应  (value:TBOOL32)emMt_Cfg_LoadAdaptiveVideo
	virtual u32 GetLoadAdaptiveVideoCfgReq() = 0;
	//获取内置mc辅流参数设置 (value:TMTInnerMcAssVidCfg)emMt_Cfg_InnerMcAssVidCfg
	virtual u32 GetInnerMcAssVidCfgReq() = 0;

	virtual u32 GetAudAnsCfgReq( ) = 0;
	//获取自动增益控制配置
	virtual u32 GetAudAgcCfgReq( ) =0;
	//获取自动回声抵消
	virtual u32 GetAudAecCfgReq( ) = 0;

	//获取邮箱 (value: TString) emMt_Cfg_Email
	virtual u32 GetEmailCfgReq( ) = 0;

	//获取TCP/UDP起始端口配置信息请求
	virtual u32 GetUdpTcpBasePortCfgReq()=0;
	// 获取是否启用文件日志请求
	virtual u32 GetIsUsedFileLogonReq()=0;

	//系统升级状态 (TBOOL32)emMt_Rt_SysUpgrade
	virtual u32 GetSysUpgradeRtReq( ) = 0;
	//会议业务占用的端口  (value: TMTUsedPortList)emMt_Rt_ConfUsedPorts
	virtual u32 GetConfUsedPortsRtReq( ) = 0;
	//mc业务占用的端口   (value: TMTUsedPortList)emMt_Rt_McUsedPorts
	virtual u32 GetMcUsedPortsRtReq( ) = 0;
	//vod业务占用的端口   (value: TMTUsedPortList)emMt_Rt_VodUsedPorts
	virtual u32 GetVodUsedPortsRtReq( ) = 0;
	//聊天业务占用的端口   (value: TMTUsedPortList)emMt_Rt_ImUsedPorts
	virtual u32 GetImUsedPortsRtReq( ) = 0;
	//登录IM所需要的参数 (value: TImUserLogin)emMt_Rt_LoginIM
	virtual u32 GetLoginIMParamCfgReq( ) = 0;

	//@brief    获取登录密码配置
	virtual u32 GetLoginPwdCfgReq() = 0;
	//@brief    获取带宽
	virtual u32 GetBandWidthCfgReq() = 0;


	//运行时映射表 (value: TMutiTServiceInfoRtData) emMt_Rt_SysCtrlSrvInfo
	virtual u32 GetSysCtrlSrvInfoRtReq() = 0;
	//运行时映射表中模块个数 (value: TU32) emMt_Rt_SysCtrlSrvNum
	virtual u32 GetSysCtrlSrvNumRtReq() = 0;
	//获取启动映射表 (value: TMutiTServiceDefInfo) emMt_Cfg_SysCtrlDefSrvInfo
	virtual u32 GetSysCtrlDefSrvInfoCfgReq() = 0;
	//获取默认映射表中模块个数 (value: TU32) emMt_Cfg_SysCtrlDefSrvNum
	virtual u32 GetSysCtrlDefSrvNumCfgReq() = 0;

	//H460配置 (value:TMtH460PxyCfg)emMt_Cfg_H460
	virtual u32 GetH460CfgReq() = 0;
	//H323代理 (value:TMtH323PxyCfg)emMt_Cfg_H323Pxy
	virtual u32 GetH323PxyCfgReq() = 0;
	//会议服务器 (value: TMtMeetingSvrAddr)emMt_Rt_MeetingCtrl
	virtual u32 GetMeetingCtrlSrvRtReq() = 0;
	// 获取登录Aps所需要的参数请求 (value: TMTApsLoginParam) emMt_Cfg_ApsLoginParam
	virtual u32 GetApsLoginParamCfgReq() = 0;


	//下面是硬终端产品线
	//获取滚动短消息配置请求
	virtual u32 GetHoriRollMsgCfgReq( ) = 0;

	/**********用户设置**************/
	// 获取双流显示模式请求 emHD_Cfg_DispMode
	virtual u32 GetHDDispModeCfgReq( ) = 0;
	//emHD_Cfg_VidResPriorStrategy
	// 获取视频输出制式请求 emHD_Cfg_HDResOutput
	virtual u32 GetHDResOutputCfgReq( ) = 0;
	// 获取是否开启自动画中画请求 emHD_Cfg_AutoPIP
	virtual u32 GetIsHDAutoPIPCfgReq( ) = 0;
	// 获取呼入铃声请求 emHD_Cfg_CallInRing
	virtual u32 GetHDCallInRingCfgReq( ) = 0;
	// 获取呼出铃声请求 emHD_Cfg_CallOutRing
	virtual u32 GetHDCallOutRingCfgReq( ) = 0;

	//播放呼入铃声(value: TU32) emHD_Rt_CallInRing
	virtual u32 GetCallInRingRtReq() = 0;
	//播放呼出铃声(value: TU32) emHD_Rt_CallOutRing
	virtual u32 GetCallOutRingRtReq() = 0;
	//获取播放按键音(value: TU32) emHD_Cfg_KeyboardRing
	virtual u32 GetKeyboardRingCfgReq() = 0;

	// 获取当前使用的横幅id号请求 emHD_Cfg_EnablePresetBanner
	virtual u32 GetHDPresetBannerCfgReq()=0;
	// 获取osd横幅配置请求 emHD_Cfg_OsdBannerInfo
	virtual u32 GetHDOsdBannerInfoCfgReq()=0;

	// 获取Mtc横幅配置请求 emHD_Cfg_MtcBannerInfo
	virtual u32 GetHDMtcBannerInfoCfgReq()=0;
	// 获取台标配置请求 emHD_Cfg_LabelInfo
	virtual u32 GetHDLabelInfoCfgReq()=0;
	// 获取自动待机配置请求 emHD_Cfg_AutoSleep
	virtual u32 GetHDAutoSleepCfgReq()=0;
	// 获取时间配置请求 emHD_Cfg_SysTime
	virtual u32 GetHDSysTimeCfgReq()=0;

	/**********管理员设置**********/
	// 获取麦克增益请求 emHD_Cfg_MicGain
	virtual u32 GetHDMicGainCfgReq()=0;
	// 获取回声抵消自适应请求 emHD_Cfg_AecDebug
	virtual u32 GetHDAecDebugCfgReq()=0;
	// 获取主音频输入接口请求 emHD_Cfg_AudInPortList
	virtual u32 GetHDAudInPortListCfgReq()=0;
	// 获取音频输出接口请求 emHD_Cfg_AudOutPortList
	virtual u32 GetHDAudOutPortListCfgReq()=0;
	// 获取第一路主视频输入端口请求 emHD_Cfg_Pri1stVidInPort
	virtual u32 GetHDPri1stVidInPortCfgReq()=0;
	//获取第二路主辅视频输入端口(value: TMTHDVidInPort ) emHD_Cfg_Pri2ndVidInPort
	virtual u32 GetHDPri2ndVidInPortCfgReq()=0;
	//获取辅视频输入端口(value: TMTHDVidInPort ) emHD_Cfg_AssVidInPort
	virtual u32 GetHDAssVidInPortCfgReq()=0;
	// 获取多视或多流请求 emHD_Cfg_MultiVideo
	virtual u32 GetHDMultiVideoCfgReq()=0;
	// 获取视频矩阵请求 emHD_Cfg_VideoMatrixScheme
	virtual u32 GetHDVideoMatrixSchemeListCfgReq()=0;
	// 获取无图像显示策略请求 emHD_Cfg_LastDisplay
	virtual u32 GetHDLastDisplayListCfgReq()=0;
	// 获取图像降噪等级请求 emHD_Cfg_ImageNoiseLevel
	virtual u32 GetHDImageNoiseLevelCfgReq()=0;
	// 获取图像增强开关请求 emHD_Cfg_ImageEnhancement
	virtual u32 GetHDImageEnhancementCfgReq()=0;

	//获取第一路主视频变形拉伸(value: TMTHDImageDeformationTensile ) emHD_Cfg_Pri1stDeformationTensile
	virtual u32 GetHDPri1stDeformationTensileCfgReq()=0;

	//获取第二路主视频变形拉伸(value: TMTHDImageDeformationTensile ) emHD_Cfg_Pri2ndDeformationTensile
	virtual u32 GetHDPri2ndDeformationTensileCfgReq()=0;

	//获取辅视频变形拉伸(value: TMTHDImageDeformationTensile ) emHD_Cfg_AssDeformationTensile
	virtual u32 GetHDAssDeformationTensileCfgReq()=0;

	//获取第一路主视频等比缩放(value: TMTHDImageGeometricScaling ) emHD_Cfg_Pri1stGeometricScaling
	virtual u32 GetHDPri1stGeometricScalingCfgReq()=0;

	//获取第二路主视频等比缩放(value: TMTHDImageGeometricScaling ) emHD_Cfg_Pri2ndGeometricScaling
	virtual u32 GetHDPri2ndGeometricScalingCfgReq()=0;

	//获取辅视频等比缩放(value: TMTHDImageGeometricScaling )emHD_Cfg_AssGeometricScaling
	virtual u32 GetHDAssGeometricScalingCfgReq()=0;

	//获取第一路主视频裁边像素(value: TU32 )emHD_Cfg_EdgePixel
	virtual u32 GetHDEdgePixelCfgReq()=0;

	//获取摄像机配置(value: TMTHDCameraList )emHD_Cfg_CameraList
	virtual u32 GetHDCameraListCfgReq()=0;

	//获取串口配置(value: TMTHDSerialCtrl )emHD_Cfg_SerialCtrl
	virtual u32 GetHDSerialCtrlCfgReq()=0;
	//获取串口列表(value: TMTHDSerialList)
	virtual u32 GetSerialListCfgReq()=0;
	//获取VGA图像调节 (value:TMTVgaImageAdjustCfg)emHD_Cfg_VGAImageAdjust
	virtual u32 GetVGAImageAdjustCfgReq() = 0;
	//获取视频源标签 (value:TMTVideoSrcTagList)emHD_Cfg_VideoSrcTag
	virtual u32 GetVideoSrcTagCfgReq() = 0;
	//获取视频输出标签 (value:TMTVideoOutTagList)emHD_Cfg_VideoOutTag
	virtual u32 GetVideoOutTagCfgReq() = 0;
	//获取SDI一进一出或者两进(value: TU32)
	virtual u32 GetSDIOneInOneOutOrTwoInCfgReq() = 0;
	
	//获取快照FTP (value:TMTSnapShotFtpCfg)emHD_Cfg_SnapShotFtpCfg
	virtual u32 GetSnapShotFtpCfgCfgReq() = 0;
	//获取VGA输出亮度 (value : TU32)emHD_Cfg_VgaOutBright
	virtual u32 GetVgaOutBrightCfgReq() = 0;
	//获取VGA输出对比度请求
	virtual u32 GetVgaOutContrastCfgReq() = 0;
	//获取VGA输出饱和度请求 (value : TU32)emHD_Cfg_VgaOutSaturation
	virtual u32 GetVgaOutSaturationCfgReq() = 0;

	//查询视频亮度、对比度、饱和度请求
	virtual u32 GetVidImgParamReq(const EmCodecComponent_Api emCodecType,const EmCodecComponentIndex_Api emCodecIdx,const EmImgParam_Api emMsgSrc ) = 0;


	//获取预置位名称设置请求   (value:TMTAllPreSetNameInfoCfg) emHD_Cfg_PresetNameInfo
	virtual u32 GetPresetNameInfoCfgReq() = 0;

	//网络设置相关
	//< 路由配置信息(value: TRouteItemInfoList) emHD_Cfg_RouteCfgList
    virtual u32 GetRouteCfgListCfgReq() = 0;

	//< 以太网工作模式(value:TEthnetWorkModeList) emHD_Cfg_EthWorkModeList
	virtual u32 GetEthWorkModeListCfgReq()=0;

	//< 以太网信息(value:TEthnetCfg) emHD_Cfg_EthnetCfg
	virtual u32 GetEthnetCfgReq()=0;

	//< PPPoE拨号信息(value:TEthnetPPPoECfg) emHD_Cfg_EthPPPoECfg
	virtual u32 GetEthPPPoECfgReq()=0;

	//< Wifi工作模式 (value:TWifiWorkMode) emHD_Cfg_WifiWorkMode
	virtual u32 GetWifiWorkModeCfgReq()=0;

	//< Wifi-AP配置信息 (value:TWifiApConfiguration) emHD_Cfg_WifiApCfg
	virtual u32 GetWifiApCfgReq()=0;

	//< Wifi作为client已连接后的配置信息 (value:TWifiConfiguration) emHD_Cfg_WifiClientCfg
	virtual u32 GetWifiClientCfgReq()=0;

	//< E1的配置信息 (value:TE1Cfg) emHD_Cfg_E1Cfg
	virtual u32 GetE1CfgReq() = 0;

	//< Wifi作为client连接后的详细信息(value:TWifiCurDetailInfo) emHD_Rt_WifiCurConnectedInfo
	virtual u32 GetWifiCurConnectedInfoRtReq()=0;

	//< 移动数据3G/4G工作模式 (value:TMobileDataWorkMode) emHD_Cfg_MobileDataWorkMode
	virtual u32 GetMobileDataWorkModeCfgReq()=0;

	//< 移动数据3G/4G连接后的详细信息(value:TMobileDataCurDetailInfo) emHD_Rt_MobileDataConnectedInfo
	virtual u32 GetMobileDataConnectedInfoRtReq()=0;

	//< 当前对外通讯的网络IP详细信息(value:TNetUsedInfo) emHD_Rt_NetUsedInfo
	virtual u32 GetNetUsedInfoRtReq()=0;

	// 获取主视频第一路显示比率请求 emHD_Cfg_MainFstDisplayRatio
	virtual u32 GetHDMainPriDisplayRatioCfgReq()=0;

	// 获取主视频第二路显示比率请求 emHD_Cfg_MainSecDisplayRatio
	virtual u32 GetHDMainSecDisplayRatioCfgReq()=0;

	// 获取辅显示比率请求 emHD_Cfg_AssDisplayRatio
	virtual u32 GetHDAssDisplayRatioCfgReq()=0;

	virtual u32 GetHDResizeModeCfgReq() = 0;

	virtual u32 GetMtWizardResultCfgReq() = 0;

	virtual u32 GetGKRegistRtReq() = 0;

	//获取辅视频源是否有源请求
	virtual u32 GetAssVideoPortStatusReq() = 0;

	virtual u32 GetSipRegistRtReq() = 0;
    virtual u32 GetDcsRegistRtReq() = 0; //添加的dcs状态
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