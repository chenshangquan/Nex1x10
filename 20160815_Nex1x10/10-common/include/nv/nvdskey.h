/*=============================================================================================
模块名   : 公共头文件
文件名   : nvdskey.h
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
#ifndef _NVDSKEY_H_
#define _NVDSKEY_H_
#include "kdvtype.h"

//1.修改老的Key名会导致nvconfigmsg.h中的消息名变化，请注意

//2.Key的数据含义：
// _Cfg_ 代表  配置数据，会保存
// _Rt_  代表  运行时数据，不会保存

//3.Key对应的结构体，请这样写 (value:XXX) configservice脚本运行时会提取XXX放到msgbody中

//例子：                                       //必须使用英文:
//Qos配置           emNv_Cfg_IPQoS             //(value: TNVIPQoS)
//运行时服务器登录状态 emNv_Rt_SvrLoginStatus  //(value: TNvSvrStateTable)

//4.慎用/**/多行注释脚本暂不识别 



//开始标记请勿修改
#define BGN_KEY

/*************************组件配置数据项Key开始********************/									      								           
#define	emNv_Cfg_Port                     "emNv_Cfg_Port"                          //设置TCP/UDP起始端口配置信息 (value: TNvPortCfg)
#define	emNv_Cfg_SysCtrlDefSrvInfo	      "emNv_Cfg_SysCtrlDefSrvInfo"             //默认启动映射表 (value: TNVMutiTServiceDefInfo)
#define	emNv_Cfg_SysCtrlDefSrvNum	      "emNv_Cfg_SysCtrlDefSrvNum"              //默认映射表中模块个数 (value: TU32)
#define	emNv_Cfg_SUS                      "emNv_Cfg_SUS"                           //(value: TNVSUSAddr)  //升级服务器地址 //行业：UI配置； 企业：XAP登陆成功后获取
#define	emNv_Cfg_TerIp                    "emNv_Cfg_TerIp"                         //运行时X500终端ip (value: TString)
#define	emNv_Cfg_ImixIp                   "emNv_Cfg_ImixIp"                        //设置IMIX ip (value: TNVNetUsedInfo)
#define emNv_Cfg_LogSerIp                 "emNv_Cfg_LogSerIp"                      //设置日志服务器 ip (value: TString)
#define emNv_Cfg_EmailSerIp               "emNv_Cfg_EmailSerIp"                    //设置邮件服务器 ip (value: TString)
#define	emNv_Cfg_Log                      "emNv_Cfg_Log"                           //设置日志开关 (value: TBOOL32)
#define	emNv_Cfg_TimeZone                 "emNv_Cfg_TimeZone"                      //设置时区 (value: TS32)
#define	emNv_Cfg_Screen                   "emNv_Cfg_Screen"                      //设置显示器参数 (value: TNVScreenParamList)
#define	emNv_Cfg_ScreenNum                "emNv_Cfg_ScreenNum"                      //设置显示器个数 (value: TU32)
#define	emNv_Cfg_BackstageUpgrade         "emNv_Cfg_BackstageUpgrade"              //设置后台升级 (value: TBOOL32)
#define	emNv_Cfg_QuickShareVersionInfo    "emNv_Cfg_QuickShareVersionInfo"              //无线投屏版本信息 (value: TNVDevUpgrade)
#define emNv_Cfg_ImixVersionInfo          "emNv_Cfg_NextVisionVersionInfo"              //Imix版本信息 (value: TNVDevUpgrade)

#define	emNv_Cfg_IsUpgradeFileDownloadFinish   "emNv_Cfg_IsUpgradeFileDownloadFinish"       //文件是否下载完毕 (value: TBOOL32)
#define	emNv_Cfg_IsUpgradeFinish               "emNv_Cfg_IsUpgradeFinish"                   //是否升级完毕 (value: TBOOL32)
#define	emNv_Cfg_PreCheckUpgradeInfo           "emNv_Cfg_PreCheckUpgradeInfo"               //上次检查更新信息 (value: TNVUpgradeClientInfo)
#define emNv_Cfg_CodecAudOutVol           "emNv_Cfg_CodecAudOutVol"                //输出音量(value: nv::TU32)
#define emNv_Cfg_CodecQuiet               "emNv_Cfg_CodecQuiet"                    //静音(value: nv::TBOOL32)
#define emNv_Cfg_IsFullScreen             "emNv_Cfg_IsFullScreen"                  //是否全屏显示(value: nv::TBOOL32)
#define emNv_Cfg_VidResResizeMode         "emNv_Cfg_VidResResizeMode"               //非1080分辨率时播放策略(value: nv::TS32)
#define emNv_Cfg_IsMtDualLeft             "emNv_Cfg_IsMtDualLeft"               //终端外接源显示位置(value: nv::TBOOL32)
#define emNv_Cfg_IsUserCorrect            "emNv_Cfg_IsUserCorrect"               //user目录空间足够否(value: nv::TBOOL32)
#define	emNv_Cfg_TerPwd                    "emNv_Cfg_TerPwd"                         //运行时终端密码 (value: TString)
#define emNv_Cfg_ReStartImix              "emNv_Cfg_ReStartImix"                  //重新启动imix(value: nv::TBOOL32)
#define emNv_Cfg_IsOpenAmplifier           "emNv_Cfg_IsOpenAmplifier"               //是否开启功放(value:TBOOL32)
#define emNv_Cfg_IsLocalEcho               "emNv_Cfg_IsLocalEcho"                   //imix右边屏是否本地回显(value:TBOOL32)

/*************************组件运行时数据项Key开始********************/
#define	emNv_Rt_SysCtrlSrvInfo		      "emNv_Rt_SysCtrlSrvInfo"                 //运行时映射表 (value: TNVMutiTServiceInfoRtData)
#define	emNv_Rt_SysCtrlSrvNum		      "emNv_Rt_SysCtrlSrvNum"                  //运行时映射表中模块个数 (value: TU32)
#define	emNv_Rt_TerlInfo                  "emNv_Rt_TerlInfo"                       //(value: TNVTerminalInfo)
#define	emNv_Rt_SysUpgrade                "emNv_Rt_SysUpgrade"                     //系统升级状态 (value: TBOOL32)
#define	emNv_Rt_CallState                 "emNv_Rt_CallState"                     //呼叫状态 (value: TS32)
#define	emNv_Rt_IsSleep                   "emNv_Rt_IsSleep"                       //待机状态 (value: TBOOL32)
#define	emNv_Rt_IsSendDual                "emNv_Rt_IsSendDual"                    //是否发送双流 (value: TBOOL32)
#define	emNv_Rt_IsRcvDual                 "emNv_Rt_IsRcvDual"                     //是否接收双流 (value: TBOOL32)
#define	emNv_Rt_IsLoginMt                 "emNv_Rt_IsLoginMt"                     //是否登入x500终端 (value: TBOOL32)
#define	emNv_Rt_CodecStatistic            "emNv_Rt_CodecStatistic"                 //编解码统计信息(value:TNVCodecStatistic)
#define	emNv_Rt_IsMute                    "emNv_Rt_IsMute"                       //是否哑音 (value: TBOOL32)
#define emNv_Rt_QuickShareLoginInfo       "emNv_Rt_QuickShareLoginInfo"            //无线投屏登入信息 (value:TNVLoginInfos)
#define emNv_Rt_ImixVidSrcSignal          "emNv_Rt_ImixVidSrcSignal"               //imix视频源信号 (value:TNVImixVidSrcSignalList)
#define emNv_Rt_IsQuite                   "emNv_Rt_IsQuite"                        //当前是否静音(value: TBOOL32)
#define emNv_Rt_IsPowerTurnOff            "emNv_Rt_IsPowerTurnOff"                  //当前是否正在关机(value: TBOOL32)
#define emNv_Rt_IsSharing                 "emNv_Rt_IsSharing"                      //是否共享 (value: TBOOL32)
#define emNv_Rt_ImixVidSrcStatus          "emNv_Rt_ImixVidSrcStatus"               //视频源信息 (value:TNVVidInPortResInfoList)
#define emNv_Rt_NetUsedInfo               "emNv_Rt_NetUsedInfo"                    //当前对外通讯的网络IP详细信息（value：TNVNetUsedInfo
#define emNv_Rt_IsLocalSharing            "emNv_Rt_IsLocalSharing"                 //是否共享 (value: TBOOL32)
#define emNv_Rt_IsPowerUpgrade            "emNv_Rt_IsPowerUpgrade"                 //是否升级 (value: TBOOL32)
#define emNv_Rt_IsCheckResult             "emNv_Rt_IsCheckResult"                  //检查更新结果(value: TS32)
#define emNv_Rt_IsCheckTpad               "emNv_Rt_IsCheckTpad"                    //Tpad检查更新(value:TNVDevUpgrade )
#define emNv_Rt_IsOpenFtp                 "emNv_Rt_IsOpenFtp"                      //ftp开关状态(value:TBOOL32 )
#define emNv_Rt_FtpLoginInfo              "emNv_Rt_FtpLoginInfo"                   //登入模块使用ftp信息(value:TNVFtpLoginInfos )
#define	emNv_Rt_PlayZoomMode              "emNv_Rt_PlayZoomMode"                     //播放设备的显示比例(value: TS32)
#define	emNv_Rt_MiniVidInfo               "emNv_Rt_MiniVidInfo"                     //小图像操作(value: TNVMiniVidInfo)
#define	emNv_Rt_ImixVerInfo               "emNv_Rt_ImixVerInfo"                     //imix版本信息(value: TNVImixVerInfo)
#define	emNv_Rt_MtInfo                    "emNv_Rt_MtInfo"                          //MT信息(value: TNVMtInfo)
#define	emNv_Rt_AppUpgrade                "emNv_Rt_AppUpgrade"                     //应用升级状态 (value: TBOOL32)
#define	emNv_Rt_QkUpgrade                 "emNv_Rt_QkUpgrade"                     //投屏器升级状态 (value: TBOOL32)
#define	emNv_Rt_IsToolbarLogin            "emNv_Rt_IsToolbarLogin"                 //toolbar登入状态 (value: TBOOL32)
#define	emNv_Rt_PadIsDown                 "emNv_Rt_PadIsDown"                     //pad升级文件是否正在下载中 (value: TBOOL32)
#define emNv_Rt_PadLoginInfo              "emNv_Rt_PadLoginInfo"                  //pad登录信息(value:TNVPadLoginInfos)
#define emNv_Rt_RouterIsDown              "emNv_Rt_RouterIsDown"                  //路由器升级文件是否正在下载中(value: TBOOL32)
#define emNv_Rt_TerminalName              "emNv_Rt_TerminalName"                  //终端别名(value:TNVTerminalName)
#define emNv_Rt_ChangeLocalEcho           "emNv_Rt_ChangeLocalEcho"               //是否从回显切走
#define emNv_Rt_ImixSerialNum             "emNv_Rt_ImixSerialNum"                 //imix序列号

/*------------------------平台升级相关----------------------------*/
#define emNv_Rt_NvSusInfo                 "emNv_Rt_NvSusInfo"                     //sus服务器信息(value:TNVSUSAddr)
#define emNv_Rt_NvImixAllVerInfo          "emNv_Rt_NvImixAllVerInfo"              //当前imix所有组件的版本信息(value:TNVImixAllVerInfo)
/*================= 分界线，以下为产品专用Key ====================*/

/********************硬终端产品配置数据项Key开始********************/
#define	emHD_Cfg_EthnetCfg                "emHD_Cfg_EthnetCfg"                    //以太网信息(value:TNVEthnetCfg)
#define	emHD_Cfg_LastDisplay              "emHD_Cfg_LastDisplay"                  //无图像显示策略(value: TNVLastDisplay )
#define	emHD_Cfg_HdmiSwitch               "emHD_Cfg_HdmiSwitch"                  //设置HDMI开关，控制数据(value: TBOOL32 )

/********************硬终端产品运行时数据项Key开始********************/
#define	emHD_Rt_AppRunInfo		          "emHD_Rt_AppRunInfo"                    //硬终端App运行状态 (value: TNVMutiTServiceInfoRtData)
#define	emHD_Rt_IsWifi					  "emHD_Rt_IsWifi"                        //硬件是否有wifi模块(value: TBOOL32)
#define emHD_Rt_AutoUpgrade				  "emHD_Rt_AutoUpgrade"		              //硬终端自动升级（value: TBOOL32)
#define	emHD_Rt_IsMfgTest		          "emHD_Rt_IsMfgTest"                     //是否读取到e2prom中的生产测试标志位(value: TBOOL32)
#define	emHD_Rt_NetCaping                 "emHD_Rt_NetCaping"                     //是否正在抓包(value:TBOOL32)
#define emHD_Rt_BrdInfo					  "emHD_Rt_BrdInfo"						  //板子信息(value:TNVBrdInfo)
#define	emHD_Rt_UsbStatus                 "emMt_Rt_UsbStatus"                     //USB接口状态(value:TNVUsbStatus)
#define	emHD_Rt_SnapExporting             "emHD_Rt_SnapExporting"                 //是否正在导出快照(value:TBOOL32)
#define emHD_Rt_EthnetCurIp               "emHD_Rt_EthnetCurIp"                   //以太网主网口信息（value:TU32）
#define	emHD_Rt_Is1080PVer 		          "emHD_Rt_Is1080PVer"                     //是否是1080P版本(value: TBOOL32)
#define	emHD_Rt_IsOpenMiniVid 		      "emHD_Rt_IsOpenMiniVid"                     //是否打开小图像(value: TBOOL32)

/********************无线投屏产品配置数据项Key开始********************/
#define emQK_Cfg_VersionInfo                   "emQK_Cfg_VersionInfo"                       //无线投屏版本信息(value: TString)
#define	emQK_Cfg_IsUpgradeFileDownloadFinish   "emQK_Cfg_IsUpgradeFileDownloadFinish"       //文件是否下载完毕 (value: TBOOL32)
#define	emQK_Cfg_IsUpgradeFinish               "emQK_Cfg_IsUpgradeFinish"                   //是否升级完毕 (value: TBOOL32)

/********************无线投屏产品运行时数据项Key开始********************/

//////下面是所有的debug配置的key
/*
   这些debug的key, 有些是组件通用的debug的key,  有些key是 x500是正式key, 而windows是debug key
*/






#define END_KEY//End Of emNvDSKey
//结束标记请勿修改

#endif //_NVDSKEY_H_
