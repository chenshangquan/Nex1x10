/*=============================================================================================
模块名   : 公共头文件
文件名   : mtdskey.h
功能     : 配置数据项和运行时数据项的key定义
作者     : qianling
版权     : <Copyright(C) 2003-2015 Suzhou Keda Technology Co., Ltd. All rights reserved.>
----------------------------------------------------------------------------------------------
日期     : 2015/05/05
版本     : 5.0
修改人   : ruiyigen
走读人   :
修改说明 : 配置数据和运行时数据的定义整理
=============================================================================================*/
#ifndef _MTDSKEY_H_
#define _MTDSKEY_H_
#include "kdvtype.h"

//1.修改老的Key名会导致mtconfigmsg.h中的消息名变化，请注意

//2.Key的数据含义：
// _Cfg_ 代表  配置数据，会保存
// _Rt_  代表  运行时数据，不会保存

//3.Key对应的结构体，请这样写 (value:XXX) configservice脚本运行时会提取XXX放到msgbody中

//例子：                                       //必须使用英文:
//Qos配置           emMt_Cfg_IPQoS             //(value: TMTIPQoS)
//运行时服务器登录状态 emMt_Rt_SvrLoginStatus  //(value: TMtSvrStateTable)

//4.慎用/**/多行注释脚本暂不识别 



//开始标记请勿修改
#define BGN_KEY

/*************************组件配置数据项Key开始********************/									      								           
#define	emMt_Cfg_IPQoS                    "emMt_Cfg_IPQoS"                         //QoS配置 (value: TMTIPQoS)
#define	emMt_Cfg_MTU                      "emMt_Cfg_MTU"                           //TCP/IP 最大传输单元 (value: TU32)
#define	emMt_Cfg_NAT                      "emMt_Cfg_NAT"                           //设置静态NAT(value: TMTNat)			          
#define	emMt_Cfg_APSList                  "emMt_Cfg_APSList"                       //配置的APS列表 (value: TMtAPSSvrList)
#define emMt_Cfg_LastSuccessApsAddr       "emMt_Cfg_LastSuccessApsAddr"            // (value: TMtAPSAddrCfgs)   //上次登录成功APS服务器地址(废弃)
#define emMt_Cfg_BackUpAPSList            "emMt_Cfg_BackUpAPSList"                 // (value: TMtAPSAddrCfgs)   //上次登录成功APS服务器地址

#define emMt_Cfg_GK                       "emMt_Cfg_GK"                            //(value: TMtCSUAddr)      //手动输入的gk地址
#define emMt_Cfg_SipSvrManu               "emMt_Cfg_SipSvrManu"                    //(value: TMtSipSvrAddr)  //手动输入的sip服务器地址
#define	emMt_Cfg_SipSvr                   "emMt_Cfg_SipSvr"                        //设置Sip服务器 (value: TMtSipSvrAddr)

#define	emMt_Cfg_CSU                      "emMt_Cfg_CSU"                           //(value: TMtCSUAddr)  //GK 地址      //行业：UI配置； 企业：XAP登陆成功后获取
#define	emMt_Cfg_SUS                      "emMt_Cfg_SUS"                           //(value: TMtSUSAddr)  //升级服务器地址 //行业：UI配置； 企业：XAP登陆成功后获取
#define	emMt_Cfg_SusManu             "emMt_Cfg_SusManu"                           //(value: TMtSUSAddr)  //手动输入的升级服务器地址
#define	emMt_Cfg_NMS                      "emMt_Cfg_NMS"                           //(value: TMtNMSAddr)  //网管服务器地址 //行业：UI配置； 企业：XAP登陆成功后获取
#define	emMt_Cfg_NmsManu            "emMt_Cfg_NmsManu"                           //(value: TMtNMSAddr)  //手动输入的网管服务器地址
#define	emMt_Cfg_NTS                      "emMt_Cfg_NTS"                           //(value: TMtNTSAddr)  //测速服务器地址 //行业：UI配置； 企业：XAP登陆成功后获取
#define	emMt_Cfg_NtsManu              "emMt_Cfg_NtsManu"                           //(value: TMtNTSAddr)  //手动输入的测速服务器地址
#define	emMt_Cfg_NTP                      "emMt_Cfg_NTP"                           //(value: TMtNTPAddr) //时间同步服务器地址   //行业：UI配置； 企业：UI配置
#define	emMt_Cfg_NtpManu              "emMt_Cfg_NtpManu"                           //(value: TMtNTPAddr) //手动输入的时间同步服务器地址
#define	emMt_Cfg_VOD                      "emMt_Cfg_VOD"                           //(value: TMtVODSvrCfg)  //VOD服务器地址
#define	emMt_Cfg_VRS                      "emMt_Cfg_VRS"                           //(value: TMtVRSSvrCfg) //录播
#define	emMt_Cfg_DCS                      "emMt_Cfg_DCS"                           //(value: TMtDCSSvrAddr) //数据会议								          								           
#define	emMt_Cfg_StreamMedia              "emMt_Cfg_StreamMedia"                   //设置获取流媒体配置信息(value: TMTStreamMedia)

#define	emMt_Cfg_Socks5Pxy                "emMt_Cfg_Socks5Pxy"                     //设置Socket5代理配置 (value: TSocks5Cfg)
#define	emMt_Cfg_SvrLoginTactics          "emMt_Cfg_SvrLoginTactics"               //设置登录策略 (value: TMtLoginTacticsTable)			      								           
#define	emMt_Cfg_H323                     "emMt_Cfg_H323"                          //设置H323配置 (value: TMtH323Cfg)
#define emMt_Cfg_Sip                        "emMt_Cfg_Sip"                             //设置SIP配置 (value : TMtSipCfg) 
#define	emMt_Cfg_MC                       "emMt_Cfg_MC"                            //设置内置MC配置 (value: TInnerMCParam)			       									           
#define	emMt_Cfg_AudVolIn	              "emMt_Cfg_AudVolIn"                      //输入音量(value: TU32)
#define	emMt_Cfg_AudVolOut	              "emMt_Cfg_AudVolOut"                     //输出音量(value: TU32)   
#define	emMt_Cfg_Ans                      "emMt_Cfg_Ans"                           //自动噪音抑制(value: TBOOL32 )
#define	emMt_Cfg_Agc                      "emMt_Cfg_Agc"                           //自动增益控制(value: TBOOL32 )
#define	emMt_Cfg_Aec                      "emMt_Cfg_Aec"                           //自动回声抵消(value: TAdjustAecParamCfg )
#define	emMt_Cfg_LostPktResend            "emMt_Cfg_LostPktResend"                 //丢包重传参数配置 (value: TPrsParam)
#define	emMt_Cfg_PriVidEncParam           "emMt_Cfg_PriVidEncParam"                //主视频编码器参数  (value: TMTAllVideoEncoderParamCfg)
#define	emMt_Cfg_AssVidEncParam           "emMt_Cfg_AssVidEncParam"                //辅视频编码器参数  (value: TMTAllVideoEncoderParamCfg)
#define	emMt_Cfg_VideoDecParam            "emMt_Cfg_VideoDecParam"                 //视频解码器参数  (value: TMTAllVideoDecoderParamCfg)
#define	emMt_Cfg_AudioPrior               "emMt_Cfg_AudioPrior"                    //音频优选(value: TMTAudioPriorCfg)
#define	emMt_Cfg_PriVidPrior              "emMt_Cfg_PriVidPrior"                   //主流优选(value: TMTMainVideoPriorCfg)
#define	emMt_Cfg_PcAssVidPrior            "emMt_Cfg_PcAssVidPrior"                 //pc辅流优选(value: TVidPriorParam)
#define	emMt_Cfg_VidAssVidPrior           "emMt_Cfg_VidAssVidPrior"                //vido辅流优选(value: TVidPriorParam) 									      								           
#define	emMt_Cfg_PlayAniSoundInIdle       "emMt_Cfg_PlayAniSoundInIdle"            //空闲状态下是否允许播放动画音效会议中不播放空闲状态默认播放(value: TBOOL32)
#define	emMt_cfg_CodecVideoSrc            "emMt_cfg_CodecVideoSrc"                 //视频源 (value: TMTCodecVidSrcInfo)
#define	emMt_Cfg_ChrmanPollSchemes        "emMt_Cfg_ChrmanPollSchemes"             //主席轮询方案(value: TMTChrmanPollSchemeList)
#define	emMt_Cfg_ChrmanOperate	          "emMt_Cfg_ChrmanOperate"                 //设置是否是主席操作(value: TBOOL32)
#define	emMt_Cfg_ShowConfState            "emMt_Cfg_ShowConfState"                 //设置是否显示会议状态 (value: TBOOL32)
#define	emMt_Cfg_ShowConfTime             "emMt_Cfg_ShowConfTime"                  //设置是否显示会议时间 (value: TBOOL32)
#define emMt_Cfg_ShowConfName           "emMt_Cfg_ShowConfName"                //设置是否显示会议名称 (value: TBOOL32)
#define	emMt_Cfg_ShowSystimeTime          "emMt_Cfg_ShowSystimeTime"               //设置是否显示系统时间 (value: TBOOL32)
#define	emMt_Cfg_ShowShortMsgInConf       "emMt_Cfg_ShowShortMsgInConf"            //会议中是否显示短消息 (value: TBOOL32)
#define	emMt_Cfg_ShowAppTips              "emMt_Cfg_ShowAppTips"                   //是否显示申请提示 (value: TBOOL32)
#define	emMt_Cfg_StaticPic                "emMt_Cfg_StaticPic"                     //启用静态图片 (value: TStaticPicCfg)
#define	emMt_Cfg_Telephone                "emMt_Cfg_Telephone"                     //设置是否启用电话功能配置    (value: TBOOL32)
#define	emMt_Cfg_AutoCall                 "emMt_Cfg_AutoCall"                      //自动呼叫配置 (value: TMTAutoCall)
#define	emMt_Cfg_FECC                     "emMt_Cfg_FECC"                          //是否允许远遥 (value: TBOOL32)
#define	emMt_Cfg_AutoLogin                "emMt_Cfg_AutoLogin"                     //设置服务器是否自动登录  (value: TBOOL32)
#define	emMt_Cfg_AsymmetricNet            "emMt_Cfg_AsymmetricNet"                 //非对称网络  (value: TMtAsymmetricNetInfo)
#define	emMt_Cfg_UseCallFW                "emMt_Cfg_UseCallFW"                     //设置是否开启来电防火墙  (value: TBOOL32)
#define	emMt_Cfg_BandWidthTest            "emMt_Cfg_BandWidthTest"                 //设置是否自动带宽检测  (value: TBOOL32)
#define	emMt_Cfg_MCResendParam            "emMt_Cfg_MCResendParam"                 //MC丢包重传参数  (value: TMTMcRSParam)
#define	emMt_Cfg_DualStramSrcAdj          "emMt_Cfg_DualStramSrcAdj"               //设置是否开启自动双流源  (value: TBOOL32)
#define	emMt_Cfg_CallProtocol             "emMt_Cfg_CallProtocol"                  //主呼协议  (value: TMTCallerProtocol)
#define	emMt_Cfg_EncryptType              "emMt_Cfg_EncryptType"                   //设置会议加密类型  (value: TMTEncryptType)
#define	emMt_Cfg_KeepAliveItrvl           "emMt_Cfg_KeepAliveItrvl"                //设置呼叫链路保活时间 断链检测时间间隔配置(秒) (value: TU32)
#define	emMt_Cfg_FEC                      "emMt_Cfg_FEC"                           //fec (value: TMTFecInfo)
#define	emMt_Cfg_CallRateLv               "emMt_Cfg_CallRateLv"                    //TL高中低档会议码率(value: TU32)
#define	emMt_Cfg_VidBitRation             "emMt_Cfg_VidBitRation"                  //视频发送配置(value: TVidBitRationCfg )
#define	emMt_Cfg_TerminalName             "emMt_Cfg_TerminalName"                  //(value: TMtTerminalName)
#define	emMt_Cfg_LoginPwd                 "emMt_Cfg_LoginPwd"                      //企业:登录云门户密码(value: TMtLoginPlatformPwdCfg) 
#define	emMt_Cfg_Email                    "emMt_Cfg_Email"                         //设置邮箱 (value: TString)
#define	emMt_Cfg_Port                     "emMt_Cfg_Port"                          //设置TCP/UDP起始端口配置信息 (value: TMTPortCfg)
#define	emMt_Cfg_Log                      "emMt_Cfg_Log"                           //日志配置 (value: TBOOL32)
#define	emMt_Cfg_LoginIMParam		      "emMt_Cfg_LoginIMParam"                  //登录IM所需要的参数 (value: TImUserLogin)	
#define	emMt_Cfg_SysCtrlDefSrvInfo	      "emMt_Cfg_SysCtrlDefSrvInfo"             //默认启动映射表 (value: TMutiTServiceDefInfo)
#define	emMt_Cfg_SysCtrlDefSrvNum	      "emMt_Cfg_SysCtrlDefSrvNum"              //默认映射表中模块个数 (value: TU32)
#define	emMt_Cfg_AnswerMode               "emMt_Cfg_AnswerMode"                    ///接听模式配置 EmAnswerMode (value:TU32)
#define	emMt_Cfg_CallBitrate              "emMt_Cfg_CallBitrate"                   ///默认码率和三个常用码率的配置	(value:TMultiU32)
#define	emMt_Cfg_AutoSendSharedContent    "emMt_Cfg_AutoSendSharedContent"         //自动发送内容共享	(value:TBOOL32)
#define	emMt_Cfg_LoginPlatformSrv         "emMt_Cfg_LoginPlatformSrv"              //是否允许登陆平台服务	(value:TBOOL32)
#define	emMt_Cfg_H460					  "emMt_Cfg_H460"                          //H460配置 (value: TMtH460PxyCfg) 
#define	emMt_Cfg_H323Pxy				  "emMt_Cfg_H323Pxy"                       //H323代理配置 (value: TMtH323PxyCfg) 
#define	emMt_Cfg_SmoothSend			      "emMt_Cfg_SmoothSend"                    //平滑发送开关 (value:TBOOL32)
#define	emMt_Cfg_UseTelnet				  "emMt_Cfg_UseTelnet"                     //使用telnet开关 (value:TBOOL32)
#define	emMt_Cfg_UseHTTP				  "emMt_Cfg_UseHTTP"                       //使用Http开关 (value:TBOOL32)
#define	emMt_Cfg_UseFtp				      "emMt_Cfg_UseFtp"                        //使用FTP开关 (value:TBOOL32)
#define	emMt_Cfg_TelnetFtpUserInfo	      "emMt_Cfg_TelnetFtpUserInfo"             //telnet和FTP登陆的账户名、密码 (value:TMTFtpTelnetAccountInfo)
#define	emMt_Cfg_H264Svc				  "emMt_Cfg_H264Svc"                       //H.264 SVC  (value:TBOOL32)
#define	emMt_Cfg_InnerMcAssVidCfg         "emMt_Cfg_InnerMcAssVidCfg"              //内置mc辅流参数设置 (value:TMTInnerMcAssVidCfg)
#define	emMt_Cfg_ApsLoginParam			  "emMt_Cfg_ApsLoginParam"                 //登录Aps所需要的参数 (value: TMtApsLoginParam)
#define	emMt_Cfg_SusLoginParam			  "emMt_Cfg_SusLoginParam"                 //登录Sus所需要的参数 (value: TMTUpgradeClientInfo)
#define	emMt_Cfg_NmsClientHWInfo		  "emMt_Cfg_NmsClientHWInfo"               //登录Nms所需要的客户端硬件信息参数 (value: TNMSClientHWInfo)
#define	emMt_Cfg_NewExceptionTime         "emMt_Cfg_NewExceptionTime"              //最新奔溃时间(value:TString)//这个不需要在base模块中提供接口，因为通过agent上报中已经提供接口，在内部自动保存
#define emMt_Cfg_HasWizardConfiged		  "emMt_Cfg_HasWizardConfiged"			   //终端是否已走完设置向导(value:TBOOL32)
#define	emMt_Cfg_CurVidCapDev             "emMt_Cfg_CurVidCapDev"                  //视频采集设备(value: TDevInfo)		//仅TL使用	   
#define emMt_Cfg_ServerLoginPort          "emMt_Cfg_ServerLoginPort"               //服务器登录端口(value:TServerLoginPort)
#define	emMt_Cfg_ConfOccupy			      "emMt_Cfg_ConfOccupy"					   //会议强拆配置 (value:TBOOL32)
#define  emMt_Cfg_EnableHTTPS                 "emMt_Cfg_EnableHTTPS"                  //是否使用HTTPS协议与服务器通信(value:TBOOL32)
#define emMt_Cfg_MtModel				  "emMt_Cfg_MtModel"					   //终端型号(value:TU32)
#define	emMt_Cfg_ShowInOutConf            "emMt_Cfg_ShowInOutConf"                 //设置是否显示与会方入会或离会的提示 (value: TBOOL32)
#define	emMt_Cfg_ShowMtTime				  "emMt_Cfg_ShowMtTime"					   //设置是否显示终端界面时间 (value: TBOOL32)
#define emMt_Cfg_LoginStrategy            "emMt_Cfg_LoginStrategy"                 //设置登录策略(value: TLoginStrategy)
#define emMt_Cfg_ShowHomeButton			  "emMt_Cfg_ShowHomeButton"				   //设置OSD界面是否显示Home按钮(value: TBOOL32)
#define emMt_Cfg_ShowAssVidInVmp		  "emMt_Cfg_ShowAssVidInVmp"			   //设置在画面合成中是否显示本地硬双流源(value: TBOOL32)
#define emMt_Cfg_IMIXCtrlOsdFunc	      "emMt_Cfg_IMIXCtrlOsdFunc"			   //网呈IMIX通过发指令控制osd的某些功能(value:TMTOrder)
#define emMt_Cfg_HttpsCertificateType	  "emMt_Cfg_HttpsCertificateType"		   ////终端使用的证书类型(value:TU32)
#define emMt_Cfg_VidEncQcMode             "emMt_Cfg_VidEncQcMode"				   //视频编码质量控制类型(value: TU32)
#define emMt_Cfg_ShowLostPkt			  "emMt_Cfg_ShowLostPkt"				   //是否显示丢包闪电图标(value: TBOOL32)
#define emMt_Cfg_AiInfo			          "emMt_Cfg_AiInfo"				           //ai信息配置(value: TMtAiInfoCfg)
#define emMt_Cfg_UserLoginPwdTimeout	  "emMt_Cfg_UserLoginPwdTimeout"		   //用户登录密码过期时间 以月为单位(value: TU32)
#define emMt_Cfg_EnableSecure			  "emMt_Cfg_EnableSecure"				   //是否启用商密功能(value: TBOOL32)
#define emMt_Cfg_ShortCutKey			  "emMt_Cfg_ShortCutKey"				   //快捷键功能配置(value: TMtShortCutKeyList)
#define	emMt_Cfg_AiCameraInfo              "emMt_Cfg_AiCameraInfo"                 //(value: TMTHDCameraAiList)智能摄像机配置
#define emMt_Cfg_TRtpSamePort              "emMt_Cfg_TRtpSamePort"                  //原先是debug配置，现在已升级为正式配置,是否收发端口复用(value: TBOOL32)
#define emMt_Cfg_FunctionIcon              "emMt_Cfg_FunctionIcon"                 //功能图标是否显示(value:TMtFunctionIconList )

/*************************组件运行时数据项Key开始********************/
#define	emMt_Rt_CurAPS                    "emMt_Rt_CurAPS"                         //(value: TMtAPSSvrAddr)  //当前手动选择的XAP服务器，或自动登录成功的xap
#define	emMt_Rt_XNU                       "emMt_Rt_XNU"                            //(value: TMtXMPPInfo) //聊天服务器信息  //企业：XAP登陆成功后获取
#define	emMt_Rt_APS                       "emMt_Rt_APS"                            //(value:  TMtAPSAddrFromSrv) //从APS服务器上拿到的APS服务器列表
#define	emMt_Rt_PlatformApi               "emMt_Rt_PlatformApi"                    //(value: TMtPlatformApiAddr)   //平台服务接口地址 //企业：XAP登陆成功后获取
#define	emMt_Rt_MeetingCtrl		          "emMt_Rt_MeetingCtrl"                    ///< (value: TMtMeetingSvrAddr) //Meeting服务器的地址信息
#define	emMt_Rt_MicroBlog                 "emMt_Rt_MicroBlog"                      //(value: TMtPlatformWeiboAddr) //平台微博接口地址 //企业：XAP登陆成功后获取		          								           
#define	emMt_Rt_SvrLoginStatus            "emMt_Rt_SvrLoginStatus"                 //(value: TMtSvrStateTable)								          								           
#define	emMt_Rt_UserPrevilege             "emMt_Rt_UserPrevilege"                  //登陆APS返回的用户权限(value: TMTUserPrevilege) 								          								           
#define	emMt_Rt_UserInfoFromAps           "emMt_Rt_UserInfoFromAps"                //登陆APS返回的用户信息 (value: TMTUserInfoFromAps) 			      								           
#define	emMt_Rt_MCInfo                    "emMt_Rt_MCInfo"                         //内置mc的运行信息(value: TInnerMCRunInfo)
#define	emMt_Rt_CallInfo                  "emMt_Rt_CallInfo"                       //当前的呼叫info (value: TMtCallLinkSate)
#define	emMt_Rt_ChanInfo                  "emMt_Rt_ChanInfo"                       //当前的通道info， (value: TMutiChanDsInfo)
#define	emMt_Rt_IsSatelliteMT             "emMt_Rt_IsSatelliteMT"                  //是否是卫星终端， 从平台获取(value: TMTSatelliteFlag)
#define	emMt_Rt_SysUpgrade                "emMt_Rt_SysUpgrade"                     //系统升级状态 (value: TBOOL32)
#define	emMt_Rt_ConfUsedPorts             "emMt_Rt_ConfUsedPorts"                  //会议业务占用的端口  (value: TMTUsedPortList)
#define	emMt_Rt_McUsedPorts               "emMt_Rt_McUsedPorts"                    //mc业务占用的端口   (value: TMTUsedPortList)
#define	emMt_Rt_VodUsedPorts              "emMt_Rt_VodUsedPorts"                   //vod业务占用的端口   (value: TMTUsedPortList)
#define	emMt_Rt_ImUsedPorts               "emMt_Rt_ImUsedPorts"                    //聊天业务占用的端口   (value: TMTUsedPortList)
#define	emMt_Rt_BandWidth                 "emMt_Rt_BandWidth"                      //自动带宽检测结果  (value: TMTNetStatus)								      								           
#define	emMt_Rt_SysCtrlSrvInfo		      "emMt_Rt_SysCtrlSrvInfo"                 //运行时映射表 (value: TMutiTServiceInfoRtData)
#define	emMt_Rt_SysCtrlSrvNum		      "emMt_Rt_SysCtrlSrvNum"                  //运行时映射表中模块个数 (value: TU32)
#define	emMt_Rt_IsH323StackStand          "emMt_Rt_IsH323StackStand"               //323协议栈是否标准的( value: TBOOL32) 标准注册到1719，非标注册到1759
#define	emMt_Rt_H323CallingPort           "emMt_Rt_H323CallingPort"                //323协议栈侦听端口( value: TU16)
#define	emMt_Rt_H323TcpBasePort           "emMt_Rt_H323TcpBasePort"                //323协议栈245起始端口( value: TU16)
#define	emMt_Rt_H323TcpEndPort            "emMt_Rt_H323TcpEndPort"                 //323协议栈245结束端口( value: TU16)
#define	emMt_Rt_H323pxyBasePort               "emMt_Rt_H323pxyBasePort"                    //323pxy占用起始端口（ value: TU16 ）
#define	emMt_Rt_H323pxyEndPort               "emMt_Rt_H323pxyEndPort"                    //323pxy占用起始端口（ value: TU16 ）
#define	emMt_Rt_SipbfcpPort               "emMt_Rt_SipbfcpPort"                    //sip bfcp端口（ value: TU16）
#define emMt_Rt_IsSipRigisted             "emMt_Rt_IsSipRigisted"                  //sip是否注册上（ value: TBOOL32 ）
#define emMt_Rt_IsGkRigisted              "emMt_Rt_IsGkRigisted"                   //gk是否注册上（value: TBOOL32 ）
#define emMt_Rt_CameraCtrlSite            "emMt_Rt_CameraCtrlSite"                 //摄像头控制本地还是远端 (value: TU32) 实际为 枚举EmSite
#define	emMt_Rt_TerlInfo                  "emMt_Rt_TerlInfo"                       //(value: TTerminalInfo)
#define	emMt_Rt_NetUsedInfo               "emMt_Rt_NetUsedInfo"                    //当前对外通讯的网络IP详细信息(value:TNetUsedInfo)
#define	emMt_Rt_CodecStatistic            "emMt_Rt_CodecStatistic"                 //编解码统计信息(value:TCodecStatistic)
#define emMt_Rt_IsMute                    "emMt_Rt_IsMute"                         //当前是否哑音(value: TBOOL32)    
#define emMt_Rt_IsQuite                   "emMt_Rt_IsQuite"                        //当前是否静音(value: TBOOL32)
#define emMt_Rt_TotalSndBitrate           "emMt_Rt_TotalSndBitrate"                //当前可用的发送的总的码率(value:TU16)
#define emMt_Rt_TotalRcvBitrate           "emMt_Rt_TotalRcvBitrate"                //当前可用的接收的总的码率(value:TU16)

#define	emMt_Rt_VRS                       "emMt_Rt_VRS"                           //录播服务器地址从平台获取(value: TMtVRSSvrCfg) 
#define emMt_Rt_IMHandle              "emMt_Rt_IMHandle"                 //(value: TU32) IM模块登录句柄
#define	emMt_Rt_VodPlaying                "emMt_Rt_VodPlaying"                     //vod播放状态 (value: TBOOL32)
#define emMt_Rt_IsCloudRecord         "emMt_Rt_IsCloudRecord"                      //是否在空闲云端录像(value: TBOOL32)
#define emMt_Rt_IsVideoSignal         "emMt_Rt_IsVideoSignal"                      //主视频编码是否有视频源(value: TBOOL32)
#define emMt_Rt_IsBusiSecMt              "emMt_Rt_IsBusiSecMt"                     //是否是商密终端(value: TBOOL32)
#define emMt_Rt_IsBusiSecSoftMt          "emMt_Rt_IsBusiSecSoftMt"                 //是否是商密软终端(value: TBOOL32)
#define emMt_Rt_IsValidDevLicense        "emMt_Rt_IsValidDevLicense"			   //是否为合法的商密卡(value: TBOOL32)
#define emMt_Rt_PlatformType              "emMt_Rt_PlatformType"                     //平台类型(value: TPlatformType)

#define emMt_Rt_IsIMIXTerl               "emMt_Rt_IsIMIXTerl"			           //是否为网呈使用终端(value: TBOOL32)
#define emMt_Rt_ChannelLicense           "emMt_Rt_ChannelLicense"			       //渠道终端证书信息(value: TLicense)
#define emMt_Rt_AgentInfo				 "emMt_Rt_AgentInfo"					   //渠道产品信息(value: TMTAgentInfo)
#define emMt_Rt_HwChipInfo				 "emMt_Rt_HwChipInfo"					   //芯片信息(value: TMtHwChipInfoList)
#define	emMt_Rt_NS                        "emMt_Rt_NS"                             //(value: TMtNSAddr)   推送服务器
#define	emMt_Rt_EncryptType              "emMt_Rt_EncryptType"                     //(value: TU32) 会议加密模式
#define	emMt_Rt_LocalMtId                "emMt_Rt_LocalMtId"                       //(value: TMtId) 本地id号
#define emMt_Rt_IsSelectView             "emMt_Rt_IsSelectView"                    //当前是否选看(value: TBOOL32) 
#define emMt_Rt_ShareContactInfo         "emMt_Rt_ShareContactInfo"                 //共享联系人(value: TMTAddressBooks) 
#define emMt_Rt_LocalContactInfo         "emMt_Rt_LocalContactInfo"              //本地联系人(value: TAddrBookRosterList)
#define emMt_Rt_JoinConfListInfo         "emMt_Rt_JoinConfListInfo"                 //会议列表(value: TMtJoinConfParamList)
#define emMt_Rt_OnLineTerListInfo        "emMt_Rt_OnLineTerListInfo"                 //在线终端(value: TRpMtInfo)
#define emMt_Rt_IsConfRecording          "emMt_Rt_IsConfRecording"                  //终端是否开启云端录像(value: TBOOL32)
/*================= 分界线，以下为产品专用Key ====================*/

/********************硬终端产品配置数据项Key开始********************/
#define	emHD_Cfg_ShortMsg                 "emHD_Cfg_ShortMsg"                     //短消息设置(value: TMTShortMsgCfg)
#define	emHD_Cfg_DispMode		          "emHD_Cfg_DispMode"                     //设置双流显示模式 (value: TMTVideoShowMode )
#define	emHD_Cfg_HDResOutput	          "emHD_Cfg_HDResOutput"                  //视频输出制式(value: TMTVideoOutPortMode )
#define	emHD_Cfg_AutoPIP		          "emHD_Cfg_AutoPIP"                      //开关自动画中画(value: TBOOL32)
#define	emHD_Cfg_CallInRing	              "emHD_Cfg_CallInRing"                   //设置是否有呼入铃声(value: TU32)
#define	emHD_Cfg_CallOutRing	          "emHD_Cfg_CallOutRing"                  //设置是否有呼出铃声(value: TU32)
#define	emHD_Cfg_KeyboardRing		      "emHD_Cfg_KeyboardRing"                 //播放按键音(value: TU32)
#define	emHD_Cfg_EnablePresetBanner       "emHD_Cfg_EnablePresetBanner"           //当前使用的横幅id号(value: TMTEnablePresetBanner )
#define	emHD_Cfg_MtcBannerInfo            "emHD_Cfg_MtcBannerInfo"                //mtc横幅预案配置(value: TMTBannerInfoList )
#define	emHD_Cfg_OsdBannerInfo            "emHD_Cfg_OsdBannerInfo"                //OSD横幅配置(value: TMTBannerInfo )
#define	emHD_Cfg_LabelInfo                "emHD_Cfg_LabelInfo"                    //台标配置(value: TMTLabelInfo )
#define	emHD_Cfg_AutoSleep                "emHD_Cfg_AutoSleep"                    //自动待机(value: TMTAutoSleep )
#define	emHD_Cfg_SysTime                  "emHD_Cfg_SysTime"                      //时间设置(value: TMTCfgSystemTime )
#define	emHD_Cfg_MicGain                  "emHD_Cfg_MicGain"                      //麦克增益(value: TU32 )
#define	emHD_Cfg_AecDebug                 "emHD_Cfg_AecDebug"                     //回声抵消自适应(value: TU32 )
#define	emHD_Cfg_AudInPortList            "emHD_Cfg_AudInPortList"                //主音频输入接口(value: TMTHDAudInPortList )
#define	emHD_Cfg_AudOutPortList           "emHD_Cfg_AudOutPortList"               //音频输出接口(value: TMTHDAudOutPortList )
#define	emHD_Cfg_Pri1stVidInPort          "emHD_Cfg_Pri1stVidInPort"              //设置第一路主视频输入端口(value: TMTHDVidInPort )
#define	emHD_Cfg_Pri2ndVidInPort          "emHD_Cfg_Pri2ndVidInPort"              //设置第二路主视频输入端口(value: TMTHDVidInPort )
#define	emHD_Cfg_Pri3rdVidInPort          "emHD_Cfg_Pri3rdVidInPort"              //设置第三路主视频输入端口(value: TMTHDVidInPort )
#define	emHD_Cfg_AssVidInPort             "emHD_Cfg_AssVidInPort"                 //设置辅视频输入端口(value: TMTHDVidInPort )
#define	emHD_Cfg_MultiVideo               "emHD_Cfg_MultiVideo"                   //设置多视或多流(value: TMTHDMultiVideo )
#define	emHD_Cfg_VideoMatrixScheme        "emHD_Cfg_VideoMatrixScheme"            //视频矩阵(value: TMTAllVideoMatrixScheme )
#define	emHD_Cfg_LastDisplay              "emHD_Cfg_LastDisplay"                  //无图像显示策略(value: TMTLastDisplay )
#define	emHD_Cfg_ImageNoiseLevel          "emHD_Cfg_ImageNoiseLevel"              //图像降噪等级(value: TMTHDImageNoise )
#define	emHD_Cfg_ImageEnhancement         "emHD_Cfg_ImageEnhancement"             //图像增强开关(value: TBOOL32 )
#define	emHD_Cfg_Pri1stDeformationTensile "emHD_Cfg_Pri1stDeformationTensile"     //第一路主视频变形拉伸(value: TMTHDImageDeformationTensile )
#define	emHD_Cfg_Pri2ndDeformationTensile "emHD_Cfg_Pri2ndDeformationTensile"     //第二路主视频变形拉伸(value: TMTHDImageDeformationTensile )
#define	emHD_Cfg_AssDeformationTensile    "emHD_Cfg_AssDeformationTensile"        //辅视频变形拉伸(value: TMTHDImageDeformationTensile )
#define	emHD_Cfg_Pri1stGeometricScaling   "emHD_Cfg_Pri1stGeometricScaling"       //第一路主视频等比缩放(value: TMTHDImageGeometricScaling )
#define	emHD_Cfg_Pri2ndGeometricScaling   "emHD_Cfg_Pri2ndGeometricScaling"       //第二路主视频等比缩放(value: TMTHDImageGeometricScaling )
#define	emHD_Cfg_Pri3rdGeometricScaling   "emHD_Cfg_Pri3rdGeometricScaling"       //第三路主视频等比缩放(value: TMTHDImageGeometricScaling )
#define	emHD_Cfg_AssGeometricScaling      "emHD_Cfg_AssGeometricScaling"          //辅视频等比缩放(value: TMTHDImageGeometricScaling )
#define	emHD_Cfg_EdgePixel                "emHD_Cfg_EdgePixel"                    //第一路主视频裁边像素(value: TU32 )
#define	emHD_Cfg_CameraList               "emHD_Cfg_CameraList"                   //摄像机配置(value: TMTHDCameraList )
#define	emHD_Cfg_CameraAiList             "emHD_Cfg_CameraAiList"                 //摄像机配置(value: TMTHDCameraAiList )
#define	emHD_Cfg_SerialCtrl               "emHD_Cfg_SerialCtrl"                   //串口配置(value: TMTHDSerialCtrl )
#define	emHD_Cfg_SerialList               "emHD_Cfg_SerialList"                   //串口配置(value: TMTHDSerialList )
#define	emHD_Cfg_SerialMonitorList        "emHD_Cfg_SerialMonitorList"            //串口监听配置(value: TMTHDSerialMonitorList )
#define	emHD_Cfg_VGAImageAdjust           "emHD_Cfg_VGAImageAdjust"               //VGA图像调节 (value:TMTVgaImageAdjustCfg)
#define	emHD_Cfg_VGAImageOutAdjust        "emHD_Cfg_VGAImageOutAdjust"            //VGA输出图像调节 (value:TMTVgaImageOutAdjustCfg)
#define	emHD_Cfg_VideoSrcTag              "emHD_Cfg_VideoSrcTag"                  //视频源输入标签 (value:TMTVideoSrcTagList)
#define	emHD_Cfg_VideoOutTag              "emHD_Cfg_VideoOutTag"                  //视频源输出标签 (value:TMTVideoOutTagList)
#define	emHD_Cfg_SnapShotFtpCfg           "emHD_Cfg_SnapShotFtpCfg"               //快照FTP (value:TMTSnapShotFtpCfg)
#define	emHD_Cfg_PresetNameInfo		      "emHD_Cfg_PresetNameInfo"               //预置位名称设置 (value:TMTAllPreSetNameInfoCfg)
#define	emHD_Cfg_MainFstDisplayRatio      "emHD_Cfg_MainFstDisplayRatio"          //主视频第一路显示比率 (value:TMTDisplayRatio)
#define	emHD_Cfg_MainSecDisplayRatio      "emHD_Cfg_MainSecDisplayRatio"          //主视频第二路显示比率 (value:TMTDisplayRatio)
#define	emHD_Cfg_MainTrdDisplayRatio      "emHD_Cfg_MainTrdDisplayRatio"          //主视频第三路显示比率 (value:TMTDisplayRatio)
#define	emHD_Cfg_AssDisplayRatio          "emHD_Cfg_AssDisplayRatio"              //辅视频显示比率 (value:TMTDisplayRatio)
#define	emHD_Cfg_VgaOutBright             "emHD_Cfg_VgaOutBright"                 //VGA输出亮度调节 (value:TU32 )
#define	emHD_Cfg_VgaOutContrast           "emHD_Cfg_VgaOutContrast"               //VGA输出对比度调节 (value:TU32 )
#define	emHD_Cfg_VgaOutSaturation         "emHD_Cfg_VgaOutSaturation"             //VGA输出饱和度调节 (value:TU32 )
#define	emHD_Cfg_EthWorkModeList          "emHD_Cfg_EthWorkModeList"              //以太网工作模式(value:TEthnetWorkModeList)
#define	emHD_Cfg_EthnetCfg                "emHD_Cfg_EthnetCfg"                    //以太网信息(value:TEthnetCfg)
#define	emHD_Cfg_EthPPPoECfg              "emHD_Cfg_EthPPPoECfg"                  //PPPoE拨号信息(value:TEthnetPPPoECfg)
#define	emHD_Cfg_WifiWorkMode             "emHD_Cfg_WifiWorkMode"                 //Wifi工作模式 (value:TWifiWorkMode)
#define	emHD_Cfg_WifiApCfg                "emHD_Cfg_WifiApCfg"                    //Wifi-AP配置信息 (value:TWifiApConfiguration)
#define	emHD_Cfg_WifiClientCfg            "emHD_Cfg_WifiClientCfg"                //Wifi作为client已连接后的配置信息 (value:TWifiConfiguration)
#define	emHD_Cfg_MobileDataWorkMode       "emHD_Cfg_MobileDataWorkMode"           //移动数据3G/4G工作模式 (value:TMobileDataWorkMode)
#define	emHD_Cfg_E1Cfg                    "emHD_Cfg_E1Cfg"                        //E1信息(value:TE1Cfg)
#define	emHD_Cfg_RouteCfgList             "emHD_Cfg_RouteCfgList"                 //路由配置信息(value:TRouteItemInfoList)
#define	emHD_Cfg_VidInPortBright          "emHD_Cfg_VidInPortBright"              //视频输入接口亮度 (value:TMtVideoPortParamList )
#define	emHD_Cfg_VidInPortContrast        "emHD_Cfg_VidInPortContrast"            //视频输入接口对比度 (value:TMtVideoPortParamList )
#define	emHD_Cfg_VidInPortSaturation      "emHD_Cfg_VidInPortSaturation"          //视频输入接口饱和度 (value:TMtVideoPortParamList )
#define	emHD_Cfg_ResizeMode		          "emHD_Cfg_ResizeMode"                   //设置解码后加黑边、裁边与非等比的视频处理策略 (value:TMTResizeMode)
#define emHD_Cfg_FastCallList			  "emHD_Cfg_FastCallList"				  //快速呼叫配置(value:TFastCallList)
#define emHD_Cfg_RfMatchStateList		  "emHD_Cfg_RfMatchStateList"			  //终端射频状态(value:TMTRfMatchStateList)
#define	emHD_Cfg_CurPresetIndex		      "emHD_Cfg_CurPresetIndex"               //当前预置位索引 (value:TMTAllCodecPreSetIndex)
#define	emHD_Cfg_SDIOneInOneOutOrTwoIn    "emHD_Cfg_SDIOneInOneOutOrTwoIn"        //SDI一进一出或者两进(value: TU32)
#define	emHD_Cfg_CameraNoise              "emHD_Cfg_CameraNoise"                  //降噪(value: TCameraIspParam)不再使用
#define	emHD_Cfg_CameraVidStd             "emHD_Cfg_CameraVidStd"                 //内置摄像机采集制式(value: TMtCameraVidStd)
#define emHD_Cfg_CameraContrlExchange     "emHD_Cfg_CameraContrlExchange"		  //摄像机转向反转(value: TBOOL32)
#define emHD_Cfg_CameraImgMode            "emHD_Cfg_CameraImgMode"                //摄像机图像模式(value: TU32)
#define emHD_Cfg_CameraPersonFirst        "emHD_Cfg_CameraPersonFirst"            //摄像机人物优先开关(value: TBOOL32)
#define emHD_CFG_CameraHeadStand		  "emHD_CFG_CameraHeadStand"		      //摄像机倒装(value: TBOOL32)
#define	emHD_Cfg_LimitedIpCfg			  "emHD_Cfg_LimitedIpCfg"				  //限定ip列表配置信息(value:TLimitedIpCfg)
#define	emHD_Cfg_SubAudExpansion		  "emHD_Cfg_SubAudExpansion"			  //辅流本地扩声(value:TBOOL32)

#define	emHD_Cfg_CameraSharpness          "emHD_Cfg_CameraSharpness"              //锐度(value: TCameraIspParam)
#define	emHD_Cfg_CameraISO                "emHD_Cfg_CameraISO"                    //感光度(value: TCameraIspParam)
#define	emHD_Cfg_CameraExposureMode       "emHD_Cfg_CameraExposureMode"           //曝光模式(value: TCameraIspParam)
#define	emHD_Cfg_CameraAperture           "emHD_Cfg_CameraAperture"               //光圈大小与曝光模式关联(value: TCameraIspParam)
#define	emHD_Cfg_CameraShutter            "emHD_Cfg_CameraShutter"                //快门速度与曝光模式关联(value: TCameraIspParam)
#define emHD_Cfg_CameraAotoExposureGain	  "emHD_Cfg_CameraAotoExposureGain"       //自动曝光模式增益与曝光模式关联(value: TCameraIspParam)
#define emHD_Cfg_CameraManualExposureGain "emHD_Cfg_CameraManualExposureGain"     //手动曝光模式增益与曝光模式关联(value: TCameraIspParam)
#define	emHD_Cfg_CameraBright             "emHD_Cfg_CameraBright"                 //亮度(value: TCameraIspParam)
#define	emHD_Cfg_CameraWhiteBalance       "emHD_Cfg_CameraWhiteBalance"           //白平衡类型EmWBAMode(value: TCameraIspParam)
#define	emHD_Cfg_CameraHue                "emHD_Cfg_CameraHue"                    //色度(value: TCameraIspParam)
#define	emHD_Cfg_CameraContrast           "emHD_Cfg_CameraContrast"               //对比度(value: TCameraIspParam)
#define	emHD_Cfg_CameraSaturation         "emHD_Cfg_CameraSaturation"             //饱和度(value: TCameraIspParam)
#define emHD_Cfg_CameraBackLightSwitch    "emHD_Cfg_CameraBackLightSwitch"        //背光补偿类型(value: TU32)
#define emHD_Cfg_CameraBackLightLevel     "emHD_Cfg_CameraBackLightLevel"         //背光补偿等级(value: TCameraIspParam)
#define	emHD_Cfg_Camera2dNoise            "emHD_Cfg_Camera2dNoise"                //2D降噪(value: TCameraIspParam)
#define	emHD_Cfg_Camera3dNoise            "emHD_Cfg_Camera3dNoise"                //3D降噪(value: TCameraIspParam)
#define emHD_Cfg_CameraRedGain	          "emHD_Cfg_CameraRedGain"                //红增益(value: TCameraIspParam)
#define emHD_Cfg_CameraBlueGain	          "emHD_Cfg_CameraBlueGain"               //蓝增益(value: TCameraIspParam)
#define emHD_Cfg_CameraImgGamma           "emHD_Cfg_CameraImgGamma"               //伽马(value: TCameraIspParam)
#define emHD_Cfg_CameraImgDefog           "emHD_Cfg_CameraImgDefog"               //数字去雾(value: TCameraIspParam)
#define emHD_Cfg_CameraImgDigDynSwitch    "emHD_Cfg_CameraImgDigDynSwitch"        //数字宽动态开关(value: TBOOL32)
#define emHD_Cfg_CameraImgDigDynLevel     "emHD_Cfg_CameraImgDigDynLevel"         //数字宽动态等级(value: TCameraIspParam)
#define emHD_Cfg_CameraLastPosCfg         "emHD_Cfg_CameraLastPosCfg"             //内置摄像机开机默认位置配置(value: TMtCameraLastPos)
#define emHD_Cfg_CameraEnableDigZoom      "emHD_Cfg_CameraEnableDigZoom"          //是否开启使能数字变焦控制(value: TBOOL32)

/********************硬终端产品运行时数据项Key开始********************/
#define	emHD_Rt_IsMfgTest		          "emHD_Rt_IsMfgTest"                     //是否读取到e2prom中的生产测试标志位(value: TBOOL32)
#define	emHD_Rt_CallInRing		          "emHD_Rt_CallInRing"                    //播放呼入铃声(value: TU32)
#define	emHD_Rt_CallOutRing	              "emHD_Rt_CallOutRing"                   //播放呼出铃声(value: TU32)
#define	emHD_Rt_VideoSourceCapInfo        "emHD_Rt_VideoSourceCapInfo"            //终端视频接口能力信息(value: TMTHDVidInPortCapList )
#define	emHD_Rt_CameraUpdating            "emHD_Rt_CameraUpdating"                //摄像机是否正在升级(value: TBOOL32 )
#define	emHD_Rt_SnapShoting               "emHD_Rt_SnapShoting"                   //正在拍摄快照 (value:TBOOL32)
#define	emHD_Rt_FxoState                  "emHD_Rt_FxoState"                      //fxo呼叫状态(value:TFxoState)
#define	emHD_Rt_LocalLoop                 "emHD_Rt_LocalLoop"                     //本地自环状态(value:TBOOL32)
#define	emHD_Rt_SnapViewing               "emHD_Rt_SnapViewing"                   //是否正在浏览快照(value:TBOOL32)
#define	emHD_Rt_SnapExporting             "emHD_Rt_SnapExporting"                 //是否正在导出快照(value:TBOOL32)
#define	emHD_Rt_NetCaping                 "emHD_Rt_NetCaping"                     //是否正在抓包(value:TBOOL32)
#define	emHD_Rt_NetCapExporting           "emHD_Rt_NetCapExporting"               //是否正在导出抓包(value:TBOOL32)
#define	emHD_Rt_AddrbookTransfering       "emHD_Rt_AddrbookTransfering"           //是否正在传输地址簿(value:TBOOL32)
#define	emHD_Rt_LogExporting              "emHD_Rt_LogExporting"                  //是否正在导出日志(value: TBOOL32 )
#define	emHD_Rt_VidSrc2FarCtrlId          "emHD_Rt_VidSrc2FarCtrlId"              //终端内部视频源与远遥id的对应关系(value: TMTVidSrc2FarCtrlIdList)
#define	emHD_Rt_MtCapGroup                "emHD_Rt_MtCapGroup"                    //硬终端音视频能力集(value: TRpMtCap)
#define	emHD_Rt_MtSipCapGroup             "emHD_Rt_MtSipCapGroup"                 //硬终端sip呼叫音视频能力集(value: TRpMtCap)
#define	emHD_Rt_EthnetCurIp               "emHD_Rt_EthnetCurIp"                   //以太网主网口信息(value:TU32)
#define	emHD_Rt_WifiCurConnectedInfo      "emHD_Rt_WifiCurConnectedInfo"          //Wifi作为client连接后的详细信息(value:TWifiCurDetailInfo)
#define	emHD_Rt_MobileDataConnectedInfo   "emHD_Rt_MobileDataConnectedInfo"       //移动数据3G/4G连接后的详细信息(value:TMobileDataCurDetailInfo)
#define	emHD_Rt_IsWifi					  "emHD_Rt_IsWifi"                        //硬件是否有wifi模块(value: TBOOL32)
#define	emHD_Rt_NetServiceStarted		  "emHD_Rt_NetServiceStarted"             //网络模块启动状态 fasle:未启动 true:已启动(value: TBOOL32)
#define	emHD_Rt_UsbStatus                 "emMt_Rt_UsbStatus"                     //USB接口状态(value:TMTUsbStatus)
#define	emHD_Rt_IsSleep                   "emHD_Rt_IsSleep"                       //当前是否待机(value:TBOOL32)
#define emHD_Rt_BrdInfo					  "emHD_Rt_BrdInfo"						  //板子信息(value:TMTBrdInfo)
#define emHD_Rt_VideoSrcRes				  "emHD_Rt_VideoSrcRes"					  //主辅视频采集制式(value:TMtVidSrcInfoList)
#define	emHD_Rt_AppRunInfo		          "emHD_Rt_AppRunInfo"                    //硬终端App运行状态 (value: TMutiTServiceInfoRtData)
#define emHD_Rt_AutoUpgrade				  "emHD_Rt_AutoUpgrade"		              //硬终端自动升级（value: TBOOL32）
#define emHD_Rt_VidDecDynamicPayload      "emHD_Rt_VidDecDynamicPayload"          //开启视频载荷自适应后，强解码流的载荷值（value: TDynamicPayload）
#define emHD_Rt_ImageSequenceNumberType   "emHD_Rt_ImageSequenceNumberType"       //视频编码参数，图像序号类型（value: TU32）
#define emHD_Rt_ImChatroomAvailable       "emHD_Rt_ImChatroomAvailable"           //聊天室服务是否可用(value: TBOOL32 )
#define emHD_Rt_IsAutoAudioDelayCheck     "emHD_Rt_IsAutoAudioDelayCheck"         //是否正在进行声场检测(value: TBOOL32 )
#define emHD_Rt_IsMfgToolConnected		  "emHD_Rt_IsMfgToolConnected"			  //是否连接生产测试工具(value: TBOOL32 )
#define emMt_Rt_CameraZoom                "emMt_Rt_CameraZoom"                    //内置摄像机视野位置(value: TU32)
#define emMt_Rt_CameraFocus               "emMt_Rt_CameraFocus"                   //内置摄像机聚焦位置(value: TU32)
#define emHD_Rt_MtRecordStatus            "emHD_Rt_MtRecordStatus"                //本地录像是否在录像中（value: EmVideoRecordStatus ）
#define emHD_Rt_MtStreamStatus            "emHD_Rt_MtStreamStatus"				  //是否空闲发双流（value:enum EmCodecComponent）
#define emHD_Rt_SkyShareVer               "emHD_Rt_SkyShareVer"                   // SkyShare版本号(value: TString)
#define emHD_Rt_SkyMtcVer                 "emHD_Rt_SkyMtcVer"                     // SkyMtc版本号(value: TString)
#define emHD_Rt_IsSupportWireless		  "emHD_Rt_IsSupportWireless"	          //是否支持无线功能(value: TBOOL32 )	
#define emHD_Rt_AudAacConfPrm		      "emHD_Rt_AudAacConfPrm"	              //AudAacConf功能(value: TAudAacConfPrmList )	
#define emHD_Rt_KdvMtModel                "emHD_Rt_KdvMtModel"                    //产品簇型号(大型号)(value: TU32)
#define emHD_Rt_MtCameraCtrlType          "emHD_Rt_MtCameraCtrlType"              //sky300终端机芯类型(value: TU32) 
#define emHD_Rt_HwSubVer				  "emHD_Rt_HwSubVer"	                  //硬件子版本号(value: TU32 )
#define emHD_Rt_MicTag				      "emHD_Rt_MicTag"	                      //麦克枚举和名称对应(value: TMTMicTagList )
#define	emHD_Rt_MicPhoneUpdating          "emHD_Rt_MicPhoneUpdating"              //麦克是否正在升级(value: TBOOL32 )
#define	emHD_Rt_OpenScanFeature           "emHD_Rt_OpenScanFeature"               //开启厂商识别(value: TBOOL32 )
#define emHD_Rt_IsMfgTestLoad             "emHD_Rt_IsMfgTestLoad"                 //加载模式(value: TBOOL32 )


//////下面是所有的debug配置的key
/*
   这些debug的key, 有些是组件通用的debug的key,  有些key是 x500是正式key, 而windows是debug key
*/
#define  emMt_Cfg_TAudioRemoveG719       "emMt_Cfg_TAudioRemoveG719"              //通用debug， 能力是否去掉g719 (value: TBOOL32)
#define	 emMt_Cfg_LoadAdaptiveVideo      "emMt_Cfg_LoadAdaptiveVideo"             //x500是正式配置，windows是debug配置 视频载荷自适应  (value:TBOOL32)  
#define  emHD_Cfg_ImageSequenceNumberType "emMt_Cfg_ImageSequenceNumberType"      //只x500用到debug, 视频编码参数，图像序号类型（value: TU32）
#define  emMt_Cfg_TForceRtpExStrip        "emMt_Cfg_TForceRtpExStrip"             //是否强制去掉rtp 非标头部 (value: TBOOL32)
#define  emMt_Cfg_TEnableDsp6678Detect    "emMt_Cfg_TEnableDsp6678Detect"         //终端是否启动265子卡 (value: TBOOL32)
#define  emMt_Cfg_TG711AudioDuration      "emMt_Cfg_TG711AudioDuration"            //通用debug，默认G711编码支持30ms  （value: TU32）
#define  emMt_Cfg_TAudioRemoveOPUS        "emMt_Cfg_TAudioRemoveOPUS"            //通用debug，能力是否去掉Opus (value: TBOOL32)
#define  emMt_Cfg_TRemoveMultAudFormats   "emMt_Cfg_TRemoveMultAudFormats"        //通用debug, 是否去掉多种音频格式(value: TMultiU32 ）
#define  emMt_Cfg_TEnableBfcpTwice        "emMt_Cfg_TEnableBfcpTwice"              //通用debug, 是否启用bfcp2次交互方式（value: TBOOL32 ）
#define  emMt_Cfg_TEnableAudioEncParam    "emMt_Cfg_TEnableAudioEncParam"          //通用debug, 是否启用配置的音频参数(value: TAudioEncParamList)
#define  emMt_Cfg_TSetRoundTripType       "emMt_Cfg_TSetRoundTripType"          //通用debug, 设置保活方式类型(value: TU32)
#define  emMt_Cfg_KedaAacSampFreq32K      "emMt_Cfg_KedaAacSampFreq32K"           //终端音频能力的采样率是否32K(value: TBOOL32)
#define  emMt_Cfg_VidDecDynamicPayload   "emMt_Cfg_VidDecDynamicPayload"          //通用debug,  强解视频码流的载荷值(value:TDynamicPayload)
#define  emMt_Cfg_AudDecDynamicPayload   "emMt_Cfg_AudDecDynamicPayload"          //通用debug,  强解音频码流的载荷值(value:TDynamicPayload)
#define  emMt_Cfg_TIgnoreBitrateZero     "emMt_Cfg_TIgnoreBitrateZero"            //通用debug,  是否忽略码率为0的设置(value:TBOOL32)
#define  emMt_Cfg_T323AdditionalConfig   "emMt_Cfg_T323AdditionalConfig"          //通用debug,  323addtional设置(value:TMultiU32)
#define  emMt_Cfg_TKeyFrameInterval      "emMt_Cfg_TKeyFrameInterval"             //通用debug,  关键帧发送间隔时间设置(value:TU32)

//////debug key  end

/////内置mc key

#define  emMt_Rt_InnerMcAvSWPort		  "emMt_Rt_InnerMcAvSWPort"                //内置mc转发端口(value: TMtInnerMCAvSWPort)
#define  emMt_Rt_InnerMcRcvAddr  		  "emMt_Rt_InnerMcRcvAddr"                 //内置mc接收端口(value: TMtInnerMcRcvAddr)
#define  emMt_Rt_InnerMcAssRcvAddr  	  "emMt_Rt_InnerMcAssRcvAddr"              //内置mc接收端口(value: TRtpRtcpPairPort)

/////内置mc key　end


///new create by wyf
#define  emMt_Cfg_TAudioRemoveLCLD        "emMt_Cfg_TAudioRemoveLCLD"               //通用debug， 能力是否去掉lcld （value: TBOOL32）
#define  emMt_Cfg_AudioPrecedence         "emMt_Cfg_AudioPrecedence"                //音质优先 (value: TBOOL32)
#define  emMt_Cfg_TForceSet323Stack       "emMt_Cfg_TForceSet323Stack"              //强制设置协议栈 (value: TMtForceSetH323Stack)
#define  emMt_Cfg_TEnableIpwType          "emMt_Cfg_TEnableIpwType"                 //是否启用ipw方式,针对TT端，默认不启用, 为false (value: TBOOL32)
#define  emMt_Cfg_TEnableVidBitRateCtrl   "emMt_Cfg_TEnableVidBitRateCtrl"          //通用debug, 是否改变视频编码 (value: TBOOL32）
#define  emMt_Cfg_TVideoSliceCount        "emMt_Cfg_TVideoSliceCount"               //通用debug, 视频包分包数 (value: TU32）

#define	 emMt_Cfg_SipKeepAliveItrvl       "emMt_Cfg_SipKeepAliveItrvl"              //设置呼叫链路保活时间 断链检测时间间隔配置(秒) (value: TU32)
#define  emMt_Rt_TConfinfo                "emMt_Rt_TConfinfo"                       //多点会议confinfo（value: TMtConfInfo）
#define  emMt_Cfg_TRegTimeout             "emMt_Cfg_TRegTimeout"                    //通用debug, 注册超时时间( value: TU32)
#define  emMt_Cfg_AutoRas                 "emMt_Cfg_AutoRas"                        //通用debug, 是否自动ras( value: TBOOL32) 
#define  emMt_Cfg_TSipCallPort            "emMt_Cfg_SipCallPort"                    //通用debug, sip 呼叫端口( value: TMultiU32) 

////secure begin
#define  emMt_Cfg_SipConnection           "emMt_Cfg_SipConnection"                  //商密: sip连接配置 (value: TU32)
#define	 emMt_Cfg_TEnableStrongAut        "emMt_Cfg_TEnableStrongAut"               //商密: 是否启用强认证 (value: TBOOL32）
#define	 emMt_Cfg_UseTlsCert              "emMt_Cfg_UseTlsCert"                     //商密: 是否启用TLS设备证书 (value: TBOOL32）
#define	 emMt_Cfg_UseGMTlsCert            "emMt_Cfg_UseGMTlsCert"                   //商密: 是否启用GMTLS设备证书 (value: TBOOL32）
#define  emMt_Cfg_QtSetting               "emMt_Cfg_QtSetting"                      //量通server(value: TMtQtAddr)
#define  emMt_Cfg_QtKeyUpdateMode         "emMt_Cfg_QtKeyUpdateMode"                //量通key更新策略(value: TMtSecKeyUpdatePolicy)
#define  emMt_Rt_AllSelfTestInfo          "emMt_Rt_AllSelfTestInfo"                 //终端开机的所有自检结果信息(value: TAllSelfTestResult)
#define  emMt_Rt_SecRandKey               "emMt_Rt_SecRandKey"                      //设置密钥随机key（value: TString）



#define END_KEY//End Of emMtDSKey
//结束标记请勿修改

#endif //_MTDSKEY_H_
