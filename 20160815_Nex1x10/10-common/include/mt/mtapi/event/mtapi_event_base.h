/*******************************************************************************//**
*@file          mtapi_event_base.h
*@brief         实现MTAPI BaseSdk 给UI(观察者)事件通知的定义
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_EVENT_BASE_H_
#define _MTAPI_EVENT_BASE_H_
/**@addtogroup event 事件
*@{
*/

/**@addtogroup baseevent 基础事件
*@{
*/

#include "mtapi_event_def.h"


enum EmMtApiBaseEv
{
	EV_UI_BGN(MTAPI_BASE)  = EV_MTAPI_EVENT_BGN,

	/**
	@brief    终端客户端账号验证应答，且对应于Ev_MT_MTCLogin_Rsp	
	
	MainBuf(#TMTLoginMtResult_Api)

	@verbatim
	{
	   "bLogin": true,
	   "bKickOther": true, 
	   "tLoginParam":
	   {
	     "achIp": "",
         "emAppType":1,
         "emAuthType":1,
         "achUserName":""		 
	   },
	"tKickee":
	{
	     "achIp": "",
         "emAppType":1,
         "emAuthType":1,
         "achUserName":""		 
	   },
	  "bNameExist": true,
	  "dwLoginErrCnt":1,
	  "dwLoginTime":1
	}
	
	@endverbatim
	*/
	Ev_MtApi_Base_MTCLogin_Rsp,

	/**	
	@brief    断链通知，且对应于OSP_DISCONNECT
	*/
	Ev_MtApi_Base_MTDisconnect_Ntf,

	/**	
	@brief    添加用户响应,Ev_MT_MTCAddUser_Rsp
	
	MainBuf(#u32, dwErrCode)

	@verbatim
	{
		"basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_MTCAddUser_Rsp,  
	
	/**	
	@brief添加用户通知, Ev_MT_MTCAddUser_Ntf
	
	MainBuf(#u32, dwCount)

	@verbatim
	{
	    "basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_MTCAddUser_Ntf,
	
	/**	
	@brief    修改用户响应,Ev_MT_MTCMUser_Rsp
	
	MainBuf(#u32, dwErrCode)

	@verbatim
	{
	   "basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_MTCMUser_Rsp,
	
	/**		
	@brief    修改用户通知,Ev_MT_MTCMUser_Ntf
	
	MainBuf(#u32, dwCount)

	@verbatim
	{
	   "basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_MTCMUser_Ntf,

	/**		
	@brief    删除用户响应,Ev_MT_MTCDUser_Rsp
	
	MainBuf(#u32, dwErrCode)

	@verbatim
	{
	   "basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_MTCDUser_Rsp,

	/**		
	@brief    删除用户通知,Ev_MT_MTCDUser_Ntf
	
	MainBuf(#u32, dwCount)

	@verbatim
	{
	    "basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_MTCDUser_Ntf,

	/**	
	@brief    查询用户响应,Ev_MT_MTCSUser_Rsp
	
	MainBuf(#u32, dwCount)

	@verbatim
	{
	    "basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_MTCSUser_Rsp,

	/**	
	@brief    注销响应,Ev_MtApi_Base_MTCLogOut_Ntf
	
	MainBuf(#TMtcBaseInfo, local)\n
	MainBuf(#BOOL32, is_kicked)\n
	MainBuf(#TMtcBaseInfo, tkicker)

	@verbatim
	{
		"local":
		{
			"achIp":"",
			"emAppType":1,
			"emAuthType":1,
			"achUserName":""
		},
		"is_kicked": true, 
		"tkicker":
		{
			"achIp":"",
			"emAppType":1,
			"emAuthType":1,
			"achUserName":""
		}
	}
	@endverbatim
	*/
	Ev_MtApi_Base_MTCLogOut_Ntf,

	/**	
	@brief    UI同步通知，且对应于Ev_Conf_UISynchronize_Ntf
	MainBuf(#s32 ,nReason)

	@verbatim
	{
	"basetype": 0
	}
	@endverbatim
	*/

	Ev_MtApi_Base_UISynchronize_Ntf,

	/**	
	@brief    发送待机倒计时通知(仅Embed)，且对应于Ev_MT_BLL_CodecSleepFailReason_Ntf	
	
	MainBuf(#TS32, tnReason)

	@verbatim
	{
	    "basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SleepFailReason_Ntf,

	/**	
	@brief    发送待机倒计时通知(仅Embed)，且对应于Ev_MT_CodecSleepState_Ntf	
	
	MainBuf(#BOOL32, bInSleep)

	@verbatim
	{
	    "basetype": false
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SleepState_Ntf,

	/**	
	@brief    升级检测结果通知，对应于Ev_MT_CheckUpgradeResult_Ntf
	
	MainBuf(#u32) 检测结果

	@verbatim
	{
		"basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_CheckUpgradeResult_Ntf,

	/**	
	@brief    最新版本信息通知，且对应于Ev_MT_UpgradeVersionInfo_Ntf
	
	MainBuf(#TMTUpgradeVersionInfoList_Api, tUpgradeVerInfoList) 版本信息

	@verbatim
	{
		"MainParam" :
		{
		    "basetype" : 0, //0表示获取成功，非0表示错误码
		},
		"AssParam" : 
		{
			[
				{
					"dwVer_id": 0,
					"achOemMark": "",
					"achDevType": "",
					"emUpgradeVerLevel": 0,
					"achCurSoftVer": "",
					"achVerNotes": "",
					"dwSize" : 0,
					"achFileName" : "",
					"emUpgradeAttr" : 0,
					"tGrayRange" : {
						"achMoidList" : "",
						"achE164List" : ""
					},
					"byCnt": 0,
					"bNewestVersion": false
				},
				{
					"dwVer_id": 0,
					"achOemMark": "",
					"achDevType": "",
					"emUpgradeVerLevel": 0,
					"achCurSoftVer": "",
					"achVerNotes": "",
					"dwSize" : 0,
					"achFileName" : "",
					"emUpgradeAttr" : 0,
					"tGrayRange" : {
						"achMoidList" : "",
						"achE164List" : ""
					},
					"byCnt": 0,
					"bNewestVersion": false
				}
			]
		}
	}
	@endverbatim
	*/
	Ev_MtApi_Base_UpgradeVersionInfo_Ntf,

	/**	
	@brief    最新版本信息通知，且对应于Ev_MT_UpgradeVersionInfo_Ntf
	
	MainBuf(#TMTUpgradeVersionInfoList_Api, tUpgradeVerInfoList) 版本信息

	@verbatim
	{
		"MainParam" :
		{
		    "basetype" : 0, //0表示获取成功，非0表示错误码
		},
		"AssParam" : 
		{
			[
				{
					"dwVer_id": 0,
					"achOemMark": "",
					"achDevType": "",
					"emUpgradeVerLevel": 0,
					"achCurSoftVer": "",
					"achVerNotes": "",
					"dwSize" : 0,
					"achFileName" : "",
					"emUpgradeAttr" : 0,
					"tGrayRange" : {
						"achMoidList" : "",
						"achE164List" : ""
					},
					"byCnt": 0,
					"bNewestVersion": false
				},
				{
					"dwVer_id": 0,
					"achOemMark": "",
					"achDevType": "",
					"emUpgradeVerLevel": 0,
					"achCurSoftVer": "",
					"achVerNotes": "",
					"dwSize" : 0,
					"achFileName" : "",
					"emUpgradeAttr" : 0,
					"tGrayRange" : {
						"achMoidList" : "",
						"achE164List" : ""
					},
					"byCnt": 0,
					"bNewestVersion": false
				}
			]
		}
	}
	@endverbatim
	*/
	Ev_MtApi_Base_AutoLoadUpgradeFileOk_Ntf,
	/**	
	@brief    文件下载状态通知，且对应于Ev_MT_UpgradeFileDownloadInfo_Ntf	
	
	MainBuf(#TMTUpgradeDownloadInfo_Api, tDownLoadInfo) 下载状态

	@verbatim
	{
	   "dwErrcode" : 0,
		"dwTotalPercent": 0,
		"dwCurPercent": 0,
		"achCurFileName": "str"
	}
	@endverbatim
	*/
	Ev_MtApi_Base_UpgradeFileDownloadInfo_Ntf,

	/**
	@brief    文件下载完毕通知，且对应于Ev_MT_UpgradeFileDownloadOk_Ntf
	*/
	Ev_MtApi_Base_UpgradeFileDownloadOk_Ntf,

	/**
	@brief    与服务器断链通知，且对应于Ev_MT_BLL_UpgradeDisconnectServer_Ntf
	*/
	Ev_MtApi_Base_UpgradeDisconnectServer_Ntf,

	/**	
	@brief    更新系统文件状态通知，且对应于Ev_MT_UpgradeSysFileUpdateStatus_Ntf
	
	MainBuf(#u32, wResult) 更新文件状态错误码  MT_SUCESS: 成功，失败错误码：ERR_UPGRADE_IOS_UPGRADE_FAILED、ERR_UPGRADE_FPGA_UPGRADE_FAILED、
	ERR_UPGRADE_WHOLEUPGRADE_FAILED、ERR_UPGRADE_WHOLEUPGRADE_FAILED、ERR_UPGRADE_FILE_CHECK_FAILED、ERR_UPGRADE_INVALID_FILE

	@verbatim
	{
		"basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_UpgradeSysFileUpdateStatus_Ntf,

	/**	
	@brief    检查U盘升级包响应
	
	MainBuf(#UpgradeFileInfo_Api)\n
	SubBuf(#TMTUpgradeVersionInfoList_Api)

	@verbatim
	{
		"MainParam" : 
		{
			"bIsFound" : false,
			"achFilePath" : ""
		}
		"AssParam" :
		{
		"tVerList": [
			{
				"dwVer_id": 0,
				"achOemMark": "",
				"achDevType": "",
				"emUpgradeVerLevel": 0,
				"achCurSoftVer": "",
				"achVerNotes": "",
				"dwSize" : 0,
				"achFileName" : "",
				"emUpgradeAttr" : 0,
				"tGrayRange" : {
				    "achMoidList" : "",
				    "achE164List" : ""
				}
			}
		]
		}
	}
	@endverbatim
	*/
	Ev_MtApi_Base_UsbUpgradeFileCheck_Rsp,

	/**	
	@brief    待机状态通知(仅Embed)，且对应于Ev_MT_BLL_SleepCountDown_Ntf
	
	MainBuf(#u16, wSleepRemainTime) 待机剩余时间	

	@verbatim
	{
		"basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SleepCountDown_Ntf,

	/**	
	@brief    待机响应(仅Embed)
	
	MainBuf(#BOOL32) 是否允许待机 \n
	MainBuf(#s32) 待机失败原因

	@verbatim
	{
	    MainParam: 
		{
			"basetype": false
		},
		AssParam:
		{
			"basetype": 0
		}
	}	
	@endverbatim
	*/
	Ev_MtApi_Base_CodecDspSleep_Rsp,

	/**	
	@brief    网络抓包状态通知 Ev_MT_NetCaptureState_Ntf
	
	MainBuf(#u32)

	@verbatim
	{
	    "basetype": 0 //错误码，见EmNetCapErrcode_Api
	}
	@endverbatim
	*/
	Ev_MtApi_Base_NetCaptureState_Ntf,

	/**	
	@brief    导出抓包文件响应 Ev_MT_ExportNetCapture_Rsp
	
	MainBuf(#u32, dwErrCode)

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ExportNetCapture_Rsp,
	
	/**	
	@brief    导出日志文件进度通知 Ev_MT_ExportLogProgress_Ntf
	
	MainBuf(#u32, dwPercent)

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ExportLogProgress_Ntf,

	/**	
	@brief    导出日志文件响应 Ev_MT_ExportLog_Rsp
	
	MainBuf(#u32, dwErrCode)

	@verbatim
	{
	    "basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ExportLog_Rsp,

	/**	
	@brief    带宽检测结果通知 Ev_MT_BandwidthTestResult_Ntf
	
	MainBuf(#TMTNetStatus_Api, tMTNetStatus)

	@verbatim
	{
		"bTimeout": true,
		"tSendBandwidth": 
		{
			"dwBandWidth": 1024,
			"dwDropRate": 5
		},
		"tRecvBandWidth": 
		{
			"dwBandWidth": 1024,
			"dwDropRate": 5
		}
	}
	@endverbatim
	*/
	Ev_MtApi_Base_BandwidthTestResult_Ntf,

	/** 	
	@brief    端口配置通知
	
	MainBuf(#TTcpUdpBasePortCfg_Api, tPortCfg)

	@verbatim
	{
		"bAuto": true,
		"wTcpBasePort": 0,
		"wUdpBasePort": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_TcpUdpPortCfg_Ntf,

	/** 	
	@brief    获取端口配置响应
	
	MainBuf(#TTcpUdpBasePortCfg_Api, tPortCfg)

	@verbatim
	{
		"bAuto": true,
		"wTcpBasePort": 0,
		"wUdpBasePort": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetTcpUdpPortCfg_Rsp,

	/**
	@brief    滚动短消息配置通知 
	
	MainBuf(#TRollMsgCfg_Api, tRollCfg)

	@verbatim
	{
		"emSize": 0,
		"emColor": 0,
		"embackgroundcolor":0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_HoriRollMsgCfg_Ntf,

	/**
	@brief    获取滚动短消息配置响应
	
	MainBuf(#TRollMsgCfg_Api, tRollCfg)

	@verbatim
	{
		"emSize": 0,
		"emColor": 0,
		"embackgroundcolor":0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetHoriRollMsgCfg_Rsp, 

	/**
	@brief    日志配置通知
	
	MainBuf(#BOOL32, bEnableFileLog)

	@verbatim
	{
		"basetype": 0,
	}
	@endverbatim
	*/
	Ev_MtApi_Base_LogStatusCfg_Ntf,

	/**
	@brief    获取日志配置响应
	
	MainBuf(#BOOL32, bEnableFileLog)

	@verbatim
	{
		"basetype": 0,
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetLogStatusCfg_Rsp,

	/**
	@brief    设置qos配置通知
	
	MainBuf(#TMTIPQoS_Api, tQosCfg)

	@verbatim
	{
		"emType": 0,
		"emTos": 0,
		"tDiffServiceParam": {
			"dwSignalling": 0,
			"dwData": 0,
			"dwAudio": 0,
			"dwVideo": 0
		},
		"tIpPrecedenceParam": {
			"dwSignalling": 0,
			"dwData": 0,
			"dwAudio": 0,
			"dwVideo": 0
		}
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetIPQoSCfg_Ntf,

	/**
	@brief    获取qos配置响应
	
	MainBuf(#TMTIPQoS_Api,  tQosCfg)

	@verbatim
	{
		"emType": 0,
		"emTos": 0,
		"tDiffServiceParam": {
			"dwSignalling": 0,
			"dwData": 0,
			"dwAudio": 0,
			"dwVideo": 0
		},
		"tIpPrecedenceParam": {
			"dwSignalling": 0,
			"dwData": 0,
			"dwAudio": 0,
			"dwVideo": 0
		}
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetIPQoSCfg_Rsp,

	/**
	@brief    设置MTU配置通知
	
	MainBuf(#u32,  dwMtuCfg)

	@verbatim
	{
		"basetype": 0,
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetMTUCfg_Ntf,

	/**
	@brief    获取MTU配置响应
	
	MainBuf(#u32,  dwMtuCfg)

	@verbatim
	{
		"basetype": 0,
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetMTUCfg_Rsp,

	/**
	@brief    设置nat配置通知
	
	MainBuf(#TMTNat_Api,  tNatCfg)

	@verbatim
	{
	    "bEnable": true,
	    "dwIp": 2354
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetNATCfg_Ntf,

	/**
	@brief    获取nat配置响应
	
	MainBuf(#TMTNat_Api,  tNatCfg)

	@verbatim
	{
	    "bEnable": true,
	    "dwIp": 2354
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetNATCfg_Rsp,

	/**
	@brief    设置xap列表配置通知
	
	MainBuf(#TMtXAPSvrList_Api,  xapSvrList)

	@verbatim
	{
	    "bAutoSelect": false,
	    "byCurIndex": 1,
	    "arrMtXAPSvr": [
	        {
	            "emAddrType": 1,
				"achAlias" : "",
	            "achDomain": "",
	            "dwIp": 2324
	        }
	    ]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetXAPListCfg_Ntf,

	/**
	@brief    获取xap列表配置响应
	
	MainBuf(#TMtXAPSvrList_Api,  xapSvrList)

	@verbatim
	{
	    "bAutoSelect": false,
	    "byCurIndex": 1,
	    "arrMtXAPSvr": [
	        {
	            "emAddrType": 1,
				"achAlias" : "",
	            "achDomain": "",
	            "dwIp": 2324
	        }
	    ]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetXAPListCfg_Rsp,

	/**
	@brief    设置当前xap通知
	
	MainBuf(#TMtAPSSvrAddr_Api,  xapAddr)

	@verbatim
	{
	    "achDomain" : "", 
	    "dwIp"     : 2 
	}	
	@endverbatim
	*/
	Ev_MtApi_Base_SetCurXAPCfg_Ntf,

	/**
	@brief    获取当前xap响应
	
	MainBuf(#TMtAPSSvrAddr_Api,  xapAddr)

	@verbatim
	{
	    "achDomain" : "", 
	    "dwIp"     : 2 
	}	
	@endverbatim
	*/
	Ev_MtApi_Base_GetCurXAPCfg_Rsp,	

	/**
	@brief    获取xmpp信息响应
	
	MainBuf(#TMtXMPPInfo_Api,  xmppInfo)

	@verbatim
	{
	    "achDomain": "",
	    "dwIp": 235234,
	    "dwPort": 123,
	    "achName": "",
	    "achPassword": ""
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetXNURt_Rsp,
   
    /**
	@brief    获取NS指针响应（新加）
	
	MainBuf(#TMtNSADDRInfo_Api,  NsAddrInfo)

	@verbatim
	{
        "achDomain": "",
        "dwIp": ,
        "dwPort": ,
        "dwTlsProt": 
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetNSRt_Rsp,
 
	/**
	@brief    设置CSU配置通知
	
	MainBuf(#TMtCSUAddr_Api, tCsuCfg)

	@verbatim
	{
		"bUsedCSU": true,
		"achDomain": "",
		"dwIp": 0,
		"achNumber": "",
		"achPassword": "",
		"dwPort":0
		"dwTimeToLive":0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetCSUCfg_Ntf,
 
	/**
	@brief    获取CSU配置响应
	
	MainBuf(#TMtCSUAddr_Api, tCsuCfg)

	@verbatim
	{
		"bUsedCSU": true,
		"achDomain": "",
		"dwIp": 0,
		"achNumber": "",
		"achPassword": "",
		"dwPort":0
		"dwTimeToLive":0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetCSUCfg_Rsp,

	/**
	@brief    设置SUS配置通知
	
	MainBuf(#TMTSUSAddr_Api, tSusCfg)

	@verbatim
	{
		"achDomain": "",
		"dwIP": 0,
		"bUseDefaultAddr": true,
		"achCustomDomain" : "",
		"dwCustomIp" : 0,
		"dwPort" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetSUSCfg_Ntf,
 
	/**
	@brief    获取SUS配置响应
	
	MainBuf(#TMTSUSAddr_Api, tSusCfg)

	@verbatim
	{
		"achDomain": "",
		"dwIP": 0,
		"bUseDefaultAddr": true,
		"achCustomDomain" : "",
		"dwCustomIp" : 0,
		"dwPort" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetSUSCfg_Rsp,

	/**
	@brief    设置SUS手动配置通知
	
	MainBuf(#TMTSUSAddr_Api, tSusCfg)

	@verbatim
	{
		"achDomain": "",
		"dwIP": 0,
		"bUseDefaultAddr": true,
		"achCustomDomain" : "",
		"dwCustomIp" : 0,
		"dwPort" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetSusManuCfg_Ntf,
 
	/**
	@brief    获取SUS手动配置响应
	
	MainBuf(#TMTSUSAddr_Api, tSusCfg)

	@verbatim
	{
		"achDomain": "",
		"dwIP": 0,
		"bUseDefaultAddr": true,
		"achCustomDomain" : "",
		"dwCustomIp" : 0,
		"dwPort" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetSusManuCfg_Rsp,

	/**	
	@brief    设置NMS配置通知，对应Ev_MT_BLL_SetNMSCfg_Ntf
	
	MainBuf(#TMtNMAAddr_Api, tMtNMAAddr)

	@verbatim
	{
	    "dwIp": 235234,
	    "achDomain": "",
		"dwPort" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetNMSCfg_Ntf,

	/**	
	@brief    获取NMS配置响应，对应Ev_MT_BLL_GetNMSCfg_Rsp
	
	MainBuf(#TMtNMAAddr_Api, tMtNMAAddr)

	@verbatim
	{
	    "dwIp": 235234,
	    "achDomain": "",
		"dwPort" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetNMSCfg_Rsp,

		/**	
	@brief    设置NMS手动配置通知，对应Ev_MT_BLL_SetNmsManuCfg_Ntf
	
	MainBuf(#TMtNMAAddr_Api, tMtNMAAddr)

	@verbatim
	{
	    "dwIp": 235234,
	    "achDomain": "",
		"dwPort" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetNmsManuCfg_Ntf,

	/**	
	@brief    获取NMS手动配置响应，对应Ev_MT_BLL_GetNmsManuCfg_Rsp
	
	MainBuf(#TMtNMAAddr_Api, tMtNMAAddr)

	@verbatim
	{
	    "dwIp": 235234,
	    "achDomain": "",
		"dwPort" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetNmsManuCfg_Rsp,

	/**	
	@brief    设置NTS配置通知，对应Ev_MT_BLL_SetNTSCfg_Ntf
	
	MainBuf(#TMtNTSAddr_Api, tMtNTSAddr)

	@verbatim
	{
	    "achDomain": "",
	    "dwIp": 0,
		"dwPort" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetNTSCfg_Ntf,

	/**	
	@brief    获取NTS配置响应，对应Ev_MT_BLL_GetNTSCfg_Rsp
	
	MainBuf(#TMtNTSAddr_Api, tMtNTSAddr)

	@verbatim
	{
	    "achDomain": "",
	    "dwIp": 0,
		"dwPort" : 0,
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetNTSCfg_Rsp,

		/**	
	@brief    设置NTS手动配置通知，对应Ev_MT_BLL_SetNtsManuCfg_Ntf
	
	MainBuf(#TMtNTSAddr_Api, tMtNTSAddr)

	@verbatim
	{
	    "achDomain": "",
	    "dwIp": 0,
		"dwPort" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetNtsManuCfg_Ntf,

	/**	
	@brief    获取NTS手动配置响应，对应Ev_MT_BLL_GetNtsManuCfg_Rsp
	
	MainBuf(#TMtNTSAddr_Api, tMtNTSAddr)

	@verbatim
	{
	    "achDomain": "",
	    "dwIp": 0,
		"dwPort" : 0,
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetNtsManuCfg_Rsp,

	/**	
	@brief    设置NTP配置通知，对应Ev_MT_BLL_SetNTPCfg_Ntf
	
	MainBuf(#TMtNTPAddr_Api, tMtNTPAddr)

	@verbatim
	{
	    "achDomain": "",
	    "dwIp": 2314214,
		"dwPort": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetNTPCfg_Ntf,

	/**	
	@brief    获取NTP配置响应，对应Ev_MT_BLL_GetNTPCfg_Rsp
	
	MainBuf(#TMtNTPAddr_Api, tMtNTPAddr)

	@verbatim
	{
	    "achDomain": "",
	    "dwIp": 2314214,
		"dwPort": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetNTPCfg_Rsp,

	/**	
	@brief    设置NTP手动配置通知，对应Ev_MT_BLL_SetNtpManuCfg_Ntf
	
	MainBuf(#TMtNTPAddr_Api, tMtNTPAddr)

	@verbatim
	{
	    "achDomain": "",
	    "dwIp": 2314214,
		"dwPort": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetNtpManuCfg_Ntf,

	/**	
	@brief    获取NTP手动配置响应，对应Ev_MT_BLL_GetNtpManuCfg_Rsp
	
	MainBuf(#TMtNTPAddr_Api, tMtNTPAddr)

	@verbatim
	{
	    "achDomain": "",
	    "dwIp": 2314214,
		"dwPort": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetNtpManuCfg_Rsp,

	/**	
	@brief    设置VOD配置通知，对应Ev_MT_BLL_SetVODCfg_Ntf
	
	MainBuf(#TMtVODSvrCfg_Api, tMtVODSvrCfg)

	@verbatim
	{
	    "bEnable": true,
	    "achDomain": "",
	    "dwIp": 2314214,
	    "wPort": 12,
	    "achUsername": "",
	    "achPassword": ""
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetVODCfg_Ntf,

	/**	
	@brief    获取VOD配置响应，对应Ev_MT_BLL_GetVODCfg_Rsp
	
	MainBuf(#TMtVODSvrCfg_Api, tMtVODSvrCfg)

	@verbatim
	{
	    "bEnable": true,
	    "achDomain": "",
	    "dwIp": 2314214,
	    "wPort": 12,
	    "achUsername": "",
	    "achPassword": ""
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetVODCfg_Rsp,
	
	/**
	@brief    设置vrs服务器通知，对应Ev_MT_BLL_SetVRSCfg_Ntf
	
	MainBuf(#TMtVRSSvrCfg_Api, tMtVRSSvrCfg)

	@verbatim
	{
	    "bEnable": true,
	    "bCustom": true,
    	"achDomain": "",
	    "dwIp": 234234,
	    "achCustomAddr": "",
    	"wPort": 2300,
	    "achUsername": "",
	    "achPassword": ""
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetVRSCfg_Ntf,

	/**
	@brief    获取vrs服务器响应，对应Ev_MT_BLL_GetVRSCfg_Rsp
	
	MainBuf(#TMtVRSSvrCfg_Api, tMtVRSSvrCfg)

	@verbatim
	{
	    "bEnable": true,
	    "bCustom": true,
    	"achDomain": "",
    	"dwIp": 234234,
	    "achCustomAddr": "",
	    "wPort": 2300,
	    "achUsername": "",
	    "achPassword": ""
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetVRSCfg_Rsp,

	/**
	@brief    流媒体配置通知，对应Ev_MT_BLL_SetStreamMediaCfg_Ntf
	
	MainBuf(#TMTStreamMedia_Api, tMTStreamMedia)

	@verbatim
	{
	    "bEnable": true,
	    "bForwardLocalVideo": true,
	    "dwMultCastIP": 3433434,
	    "dwPort": 7200,
	    "dwTTL": 64,
	    "achChnlName": "",
	    "achPassword": ""
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetStreamMediaCfg_Ntf,

	/**
	@brief    获取流媒体配置响应，对应Ev_MT_BLL_GetStreamMediaCfg_Rsp
	
	MainBuf(#TMTStreamMedia_Api, tMTStreamMedia)

	@verbatim
	{
	    "bEnable": true,
	    "bForwardLocalVideo": true,
	    "dwMultCastIP": 3433434,
	    "dwPort": 7200,
	    "dwTTL": 64,
	    "achChnlName": "",
	    "achPassword": ""
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetStreamMediaCfg_Rsp,

	/**
	@brief    sip配置通知，对应Ev_MT_BLL_SetSipSvrCfg_Ntf
	
	MainBuf(#TMtSipSvrAddr_Api, tMtSipSvrAddr)

	@verbatim
	{
	    "bEnable": true,
	    "achDomain": "",
	    "dwIp": 0,
	    "dwPort": 0,
	    "achPassword": "",
	    "dwExpire": 0,
	    "achValidateName": "",
	    "dwHostPort": 0,
		"achAuthName":""
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetSipSvrCfg_Ntf,

	/**
	@brief    获取sip配置响应，对应
	
	MainBuf(#TMtSipSvrAddr_Api, tMtSipSvrAddr)

	@verbatim
	{
	    "bEnable": true,
	    "achDomain": "",
	    "dwIp": 0,
	    "dwPort": 0,
	    "achPassword": "",
	    "dwExpire": 0,
	    "achValidateName": "",
	    "dwHostPort": 0,
		"achAuthName":""
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetSipSvrCfg_Rsp,

	/**
	@brief    获取API服务器配置响应， 对应Ev_MT_BLL_GetPlatformApiRt_Rsp
	
	MainBuf(#TMtPlatformApiAddr_Api, tMtPlatformApiAddr)

	@verbatim
	{
	    "achDomain": "",
	    "dwIp": 34535656
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetPlatformApiRt_Rsp, 

	/**
	@brief  Socket5配置通知， 对应Ev_MT_BLL_SetSocks5PxyCfg_Ntf
	
	MainBuf(#TSocks5ProxyCfg_Api, tSocks5ProxyCfg)

	@verbatim
	{
	    "tServerAddr" : 
	    {
	        "emIpType" : 0,                  
	        "dwIp" : 0,                            
	        "achIpV6" : "", 
	        "dwPort" : 0                      
	    }, 
	    "achUserName" : "",   
	    "achPassword" : ""       
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetSocks5PxyCfg_Ntf,

	/**
	@brief  获取Socket5配置响应， 对应Ev_MT_BLL_GetSocks5PxyCfg_Rsp
	
	MainBuf(#TSocks5ProxyCfg_Api, tSocks5ProxyCfg)

	@verbatim
	{
	    "tServerAddr" : 
	    {
	        "emIpType" : 0,                  
	        "dwIp" : 0,                            
	        "achIpV6" : "", 
	        "dwPort" : 0                      
	    }, 
	    "achUserName" : "",   
	    "achPassword" : ""       
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetSocks5PxyCfg_Rsp,

	/**
	@brief  设置终端服务器登录状态通知， 对应Ev_MT_BLL_SetSvrLoginStatusRt_Ntf
	
	MainBuf(#TMtSvrStateList_Api,tMtSvrStateList)

	@verbatim
	{
	    "arrSvrState": 
	    [
	    {
	        "emSvrType" : 0,
	        "emSvrState" : 0
	    }
    	],
    	"byCnt": 1
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetSvrLoginStatusRt_Ntf,

	
	/**
	@brief  获取终端服务器登录状态响应， 对应Ev_MT_BLL_GetSvrLoginStatusRt_Rsp
	
	MainBuf(#TMtSvrStateList_Api,tMtSvrStateList)

	@verbatim
	{
	    "arrSvrState": 
	    [
	    {
	        "emSvrType" : 0,
	        "emSvrState" : 0
    	}
	    ],
	    "byCnt": 1
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetSvrLoginStatusRt_Rsp,

	/**
	@brief  设置终端用户登录权限配置通知， 对应Ev_MT_BLL_SetUserPrevilegeRt_Ntf
	
	MainBuf(#TMtUserPrevilege_Api,tMtUserPrevilege)

	@verbatim
	{
	    "bDefaultServiceDomainAdmin" : true,    
	    "bDefaultUserDomainAdmin" : true,     	
	    "bEnableBMC" : true,     				
	    "bEnableCall" : true,     				
	    "bEnableDCS" : true,     				
	    "bEnableHD" : true,     				
	    "bEnableIncoming" : true,     			
	    "bEnableMeeting" : true,     			
	    "bEnableMeetingSMS" : true,     		
	    "bEnableNM" : true,     				
	    "bEnableOut" : true,     				
	    "bEnableRoam" : true,     				
	    "bEnableSatellite" : true,     		
	    "bEnableSatelliteP2P" : true,     		
	    "bEnableUMC" : true,     				
	    "bEnableVRS" : true,     				
	    "bEnableWeibo" : true,     			
	    "bEnableAdmin" : true,     			
	    "bServiceDomainAdmin" : true,     		
	    "bUserDomainAdmin" : true,     		
	    "bWeiboAdmin" : true,
	    "bSelfBuilt" : true, 					
	    "bPortMedia" : true,
        "bEnableAutoCreateMeeting":true,
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetUserPrevilegeRt_Ntf,

	/**
	@brief  获取终端用户登录权限配置响应， 对应Ev_MT_BLL_GetUserPrevilegeRt_Rsp
	
	MainBuf(#TMtUserPrevilege_Api,tMtUserPrevilege)

	@verbatim
	{
	    "bDefaultServiceDomainAdmin" : true,    
	    "bDefaultUserDomainAdmin" : true,     	
	    "bEnableBMC" : true,     				
	    "bEnableCall" : true,     				
	    "bEnableDCS" : true,     				
	    "bEnableHD" : true,     				
	    "bEnableIncoming" : true,     			
	    "bEnableMeeting" : true,     			
	    "bEnableMeetingSMS" : true,     		
	    "bEnableNM" : true,     				
	    "bEnableOut" : true,     				
	    "bEnableRoam" : true,     				
	    "bEnableSatellite" : true,     		
	    "bEnableSatelliteP2P" : true,     		
	    "bEnableUMC" : true,     				
	    "bEnableVRS" : true,     				
	    "bEnableWeibo" : true,     			
	    "bEnableAdmin" : true,     			
	    "bServiceDomainAdmin" : true,     		
	    "bUserDomainAdmin" : true,     		
	    "bWeiboAdmin" : true,
	    "bSelfBuilt" : true, 					
	    "bPortMedia" : true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetUserPrevilegeRt_Rsp,

	/**
	@brief  设置登陆APS返回的用户信息通知， 对应Ev_MT_BLL_SetUserInfoFromApsRt_Ntf
	
	MainBuf(#TMTUserInfoFromAps_Api, tMTUserInfoFromAps)

	@verbatim
	{
	    "achE164" : "str",
	    "achEmail" : "str",
	    "achJid" : "str",
	    "achMoid" : "str",
	    "achXmppPwd" : "str"
	    "achAccount" : "str"
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetUserInfoFromApsRt_Ntf,

	/**
	@brief  获取登陆APS返回的用户信息响应， 对应Ev_MT_BLL_GetUserInfoFromApsRt_Rsp
	
	MainBuf(#TMTUserInfoFromAps_Api, tMTUserInfoFromAps)

	@verbatim
	{
	    "achE164" : "str",
	    "achEmail" : "str",
	    "achJid" : "str",
	    "achMoid" : "str",
	    "achXmppPwd" : "str"
	    "achAccount" : "str"
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetUserInfoFromApsRt_Rsp,

    /**
	@brief  设置H323配置信息响应通知， 对应Ev_MT_BLL_SetH323Cfg_Ntf
	
	MainBuf(#TMtH323Cfg_Api, tMtH323Cfg)

	@verbatim
	{
	    "bEnableH239" : 0,
	    "dwCallPriority" : 0
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetH323Cfg_Ntf,

    /**
	@brief  获取H323配置信息响应， 对应Ev_MT_BLL_GetH323Cfg_Rsp
	
	MainBuf(#TMtH323Cfg_Api, tMtH323Cfg)

	@verbatim
	{
	    "bEnableH239" : 0,
	    "dwCallPriority" : 0
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetH323Cfg_Rsp,

    /**
	@brief  设置SIP配置命令通知， 对应Ev_MT_BLL_SetSipCfg_Ntf
	
	MainBuf(#TMtSipCfg_Api, tMtSipCfg)

	@verbatim
	{
	    "bEnableBfcp" : true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetSipCfg_Ntf,

    /**
	@brief  获取SIP配置命令响应， 对应Ev_MT_BLL_GetSipCfg_Rsp
	
	MainBuf(#TMtSipCfg_Api, tMtSipCfg)

	@verbatim
	{
	    "bEnableBfcp" : true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetSipCfg_Rsp,

    /**
	@brief  设置内置MC通知， 对应Ev_MT_BLL_SetMCCfg_Ntf
	
	MainBuf(#BOOL32, bEnableMC)
    {
        "basetype": true
    }
	@endverbatim
	*/	
	Ev_MtApi_Base_SetMCCfg_Ntf,

    /**
	@brief  获取内置MC配置响应， 对应Ev_MT_BLL_GetMCCfg_Rsp
	
	@verbatim

	MainBuf(#BOOL32 ,bEnableMC)
    {
        "basetype": true
    }
	@endverbatim
	*/	
	Ev_MtApi_Base_GetMCCfg_Rsp,

    /**
	@brief   音频输入音量配置命令通知， 对应Ev_MT_BLL_SetAudVolInCfg_Ntf
	音量的范围为[0,31],对应好上层的进度条

	@verbatim

	MainBuf(#u32, dwAudInVol)

	@verbatim
	{
	    "basetype": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetAudVolInCfg_Ntf,

    /**
	@brief   获取音频输入音量响应， 对应Ev_MT_BLL_GetAudVolInCfg_Rsp
	音量的范围为[0,31],对应好上层的进度条

	MainBuf(#u32, dwAudInVol)

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetAudVolInCfg_Rsp,

    /**
	@brief   设置音频输出音量配置命令通知， 对应Ev_MT_BLL_SetAudVolOutCfg_Ntf
	音量的范围为[0,31],对应好上层的进度条

	MainBuf(#u32 ,dwAudOutVol )

	@verbatim
	{
	    "basetype": 0
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetAudVolOutCfg_Ntf,

    /**
	@brief    获取音频输出音量配置响应， 对应Ev_MT_BLL_GetAudVolOutCfg_Rsp
	音量的范围为[0,31],对应好上层的进度条

	MainBuf(#u32, dwAudOutVol)

	@verbatim
	{
	    "basetype": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetAudVolOutCfg_Rsp,
 
	/**		
	@brief    丢包重传参数,Ev_MT_BLL_SetLostPktResendCfg_Ntf
	
	MainBuf(#TPrsParam_Api, tPrsParam)

	@verbatim
	{
		"bEnable": true,
		"dwFirstTimeSpan": 0,
		"dwSecondTimeSpan": 0,
		"dwThirdTimeSpan": 0,
		"dwRejectTimeSpan": 0,
		"dwSendBufTimeSpan": 0,
		"bUseSmoothSend": false
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetLostPktResendCfg_Ntf,

	/**		
	@brief    丢包重传参数, Ev_MT_BLL_GetLostPktResendCfg_Rsp
	
	MainBuf(#TPrsParam_Api, tPrsParam)

	@verbatim
	{
		"bEnable": true,
		"dwFirstTimeSpan": 0,
		"dwSecondTimeSpan": 0,
		"dwThirdTimeSpan": 0,
		"dwRejectTimeSpan": 0,
		"dwSendBufTimeSpan": 0,
		"bUseSmoothSend": false
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetLostPktResendCfg_Rsp,

	/**		
	@brief    音质优先配置命令通知,对应Ev_MT_BLL_SetAudioPrecedenceCfg_Ntf
	
	MainBuf(#BOOL32, bCfg)

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetAudioPrecedenceCfg_Ntf,

	/**		
	@brief    获取音质优先配置请求响应,对应Ev_MT_BLL_GetAudioPrecedenceCfg_Rsp
	
	MainBuf(#BOOL32 ,bAudioPreceCfg)

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetAudioPrecedenceCfg_Rsp,
	
	/**		
	@brief    设置音频优选通知,对应Ev_MT_BLL_SetAudioPriorCfg_Ntf
	
	MainBuf(#TMTAudioPriorCfg_Api ,tCfg_Api)

	@verbatim
	{
	    "emAudioFormat": 0,
	    "emAacChannelNum": 0,
    	"emAaSampFreq": 0
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetAudioPriorCfg_Ntf,

	/**		
	@brief    获取音频优先请求响应,对应Ev_MT_BLL_GetAudioPriorCfg_Rsp
	
	MainBuf(#TMTAudioPriorCfg_Api, tAudPriorCfg)

	@verbatim
	{
    	"emAudioFormat": 0,
    	"emAacChannelNum": 0,
    	"emAaSampFreq": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetAudioPriorCfg_Rsp,

	/**		
	@brief    设置主视频优选通知,对应Ev_MT_BLL_SetPriVidPriorCfg_Ntf
	
	MainBuf(#TMTPriVidPriorCfg_Api ,tCfg_Api)

	@verbatim
	{
	    "atVideoPriorParam": [
	    {
	        "emVideoFormat": 0,
           	"emVideoRes": 0,
        	"dwFramerate": 0
	    }
	    ]
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetPriVidPriorCfg_Ntf,

	/**		
	@brief     获取主流优选请求响应,对应Ev_MT_BLL_GetPriVidPriorCfg_Rsp
	
	MainBuf(#TMTPriVidPriorCfg_Api, tPriVidPriorCfg)

	@verbatim
	{
	    "atVideoPriorParam": [
	    {
	        "emVideoFormat": 0,
	        "emVideoRes": 0,
        	"dwFramerate": 0
	    }
	    ]
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetPriVidPriorCfg_Rsp,

	/**		
	@brief     设置Pc辅视频优选通知,对应emMt_Cfg_PcAssVidPrior
	
	MainBuf(#TVidPriorParam_Api, tCfg_Api)

	@verbatim
	{
	    "emVideoFormat": 0,
	    "emVideoRes": 0,
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetPcAssVidPriorCfg_Ntf,

	/**		
	@brief      获取Pc辅流优请求响应,对应Ev_MT_BLL_GetPcAssVidPriorCfg_Rsp
	
	MainBuf(#TVidPriorParam_Api, tPcAssVidPriorCfg)

	@verbatim
	{
	    "emVideoFormat": 0,
	    "emVideoRes": 0,
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetPcAssVidPriorCfg_Rsp,

	/**		
	@brief      设置Vid辅视频优选通知,对应emMt_Cfg_VidAssVidPrior
	
	MainBuf(#TVidPriorParam_Api, tCfg_Api)

	@verbatim
	{
	    "emVideoFormat": 0,
	    "emVideoRes": 0,
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetVidAssVidPriorCfg_Ntf,

	/**		
	@brief      获取Vid辅流优请求响应,对应Ev_MT_BLL_GetVidAssVidPriorCfg_Rsp
	
	MainBuf(#TVidPriorParam_Api ,tVidAssVidPriorCfg)

	@verbatim
	{
	    "emVideoFormat": 0,
	    "emVideoRes": 0,
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetVidAssVidPriorCfg_Rsp,

	/**		
	@brief      设置呼叫信息通知,对应Ev_MT_BLL_SetCallInfoRt_Ntf
	
	MainBuf(#TMtCallLinkSate_Api, tCallLinkSate)

	@verbatim
	{
	    "emCallState": 0,
	    "emConfProtocol": 0,
	    "bIsCaller": true,
	    "emCallDisReason": 0,
	    "dwCallRate": 0,
	    "dwCallUpRate": 0,
	    "dwCallDownRate": 0,
	    "achPeerProductId": "",
	    "emEndpointType": 0,
	    "emPeerModel", 0,
	    "tPeerAddr": {
	    "emIpType": 0,
	    "dwIp": 0,
	    "achIpV6": "",
	    "dwPort": 0
	    },
	    "tPeerAlias": {
	    "arrAlias": [
        {
	        "emAliasType": 0,
	        "achAlias": ""
	    }
	    ]
	    },
	    "tConfEstablishedTime":{
	    "wYear": 1912,
	    "byMonth": 12,
	    "byDay": 12,
	    "byHour": 10,
	    "byMinute": 12,
	    "bySecond": 12,
	    "wMicroSecond": 12
	    }
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetCallInfoRt_Ntf,

	/**		
	@brief     获取呼叫信息请求响应,对应Ev_MT_BLL_GetCallInfoRt_Rsp
	
	MainBuf(#TMtCallLinkSate_Api ,tCallLinkSate)

	@verbatim
	{
	    "emCallState": 0,
	    "emConfProtocol": 0,
	    "bIsCaller": true,
	    "emCallDisReason": 0,
	    "dwCallRate": 0,
	    "dwCallUpRate": 0,
	    "dwCallDownRate": 0,
	    "achPeerProductId": "",
	    "emEndpointType": 0,
	    "emPeerModel", 0,
	    "tPeerAddr": {
	    "emIpType": 0,
	    "dwIp": 0,
	    "achIpV6": "",
	    "dwPort": 0
	     },
	    "tPeerAlias": {
	    "arrAlias": [
	    {
	    "emAliasType": 0,
    	"achAlias": ""
	    }
	    ]
	    },
	    "tConfEstablishedTime":{
	    "wYear": 1912,
	    "byMonth": 12,
	    "byDay": 12,
	    "byHour": 10,
	    "byMinute": 12,
	    "bySecond": 12,
	    "wMicroSecond": 12
	    }
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetCallInfoRt_Rsp,

	/**		
	@brief      设置主席操作配置命令通知,对应Ev_MT_BLL_SetChrmanOperateCfg_Ntf
	
	MainBuf(#BOOL32 ,bEnableChairmanOptCfg )

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetChrmanOperateCfg_Ntf,

	/**		
	@brief      获取主席操作配置请求响应,对应Ev_MT_BLL_GetChrmanOperateCfg_Rsp
	
	MainBuf(#BOOL32 ,bEnableChairmanOptCfg)

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetChrmanOperateCfg_Rsp,

	/**		
	@brief     设置是否会议状态显示配置命令,对应Ev_MT_BLL_SetShowConfStateCfg_Ntf
	
	MainBuf(#BOOL32 ,bShowConfStateCfg )

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetShowConfStateCfg_Ntf,

	/**		
	@brief     获取会议状态显示配置请求响应,对应Ev_MT_BLL_GetShowConfStateCfg_Rsp
	
	MainBuf(#BOOL32, bShowConfStateCfg)

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetShowConfStateCfg_Rsp,

	/**	
	@brief    开关自动画中画，对应于Ev_MT_BLL_SetStaticPicCfg_Ntf
	
	MainBuf(#BOOL32, bSend)

	@verbatim
	{
		"basetype": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetStaticPicCfg_Ntf,

	/**	
	@brief    开关自动画中画，对应于Ev_MT_BLL_GetStaticPicCfg_Rsp
	
	MainBuf(#BOOL32, bSend)

	@verbatim
	{
		"basetype": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetStaticPicCfg_Rsp,
	
	/**	
	@brief    设置是否启用电话功能配置命令，对应于Ev_MT_BLL_SetTelephoneCfg_Ntf
	
	MainBuf(#BOOL32 ,bIsUsedTelphone)

	@verbatim
	{
		"basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetTelephoneCfg_Ntf,

	/**	
	@brief    获取启用电话功能配置请求响应，对应于Ev_MT_BLL_GetTelephoneCfg_Rsp
	
	MainBuf(#BOOL32 ,bIsUsedTelphone)

	@verbatim
	{
		"basetype": true
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetTelephoneCfg_Rsp,

	/**	
	@brief    设置自动呼叫配置命令，对应于Ev_MT_BLL_SetAutoCallCfg_Ntf
	
	MainBuf(#TMTAutoCall_Api ,tAutoCallCfg)

	@verbatim
	{
	    "bIsAutoCallEnable" : 0,
     	"achTerName" : "",
	    "dwCallRate" : 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetAutoCallCfg_Ntf,

	/**	
	@brief    获取自动呼叫配置请求，对应于Ev_MT_BLL_GetAutoCallCfg_Rsp
	
	MainBuf(#TMTAutoCall_Api, tAutoCallCfg)

	@verbatim
	{
	    "bIsAutoCallEnable" : 0,
	    "achTerName" : "",
	    "dwCallRate" : 0
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetAutoCallCfg_Rsp,

	/**	
	@brief   设置是否自动登录服务器配置命令，对应于Ev_MT_BLL_SetAutoLoginCfg_Ntf
	
	MainBuf(#BOOL32, bAutoLoginCfg)

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetAutoLoginCfg_Ntf,

	/**	
	@brief   获取自动登录服务器配置请求响应，对应于Ev_MT_BLL_GetAutoLoginCfg_Rsp
	
	MainBuf(#BOOL32, bAutoLoginCfg)

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetAutoLoginCfg_Rsp,

	/**	
	@brief   设置非对称网络配置命令，对应于Ev_MT_BLL_SetAsymmetricNetCfg_Ntf
	
	MainBuf(#TAsymmetricNetInfo_Api, tNonSymNetInfoCfg)

	@verbatim
	{
	    "bIsEnable": true,
	    "dwUplinkRate": 0,
	    "dwDownlinkRate": 0
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetAsymmetricNetCfg_Ntf,

	/**	
	@brief   获取非对称网络配置请求响应，对应于Ev_MT_BLL_GetAsymmetricNetCfg_Rsp
	
	MainBuf(#TAsymmetricNetInfo_Api, tNonSymNetInfoCfg)

	@verbatim
	{
	    "bIsEnable": true,
	    "dwUplinkRate": 0,
	    "dwDownlinkRate": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetAsymmetricNetCfg_Rsp,

	/**	
	@brief   设置是否启用来电防火墙配置命令，对应于Ev_MT_BLL_SetUseCallFWCfg_Ntf
	
	MainBuf(#BOOL32, bEnableCallFWCfg )

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetUseCallFWCfg_Ntf,

	/**	
	@brief   获取来电防火墙配置请求响应，对应于Ev_MT_BLL_GetUseCallFWCfg_Rsp
	
	MainBuf(#BOOL32, bEnableCallFWCfg)

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetUseCallFWCfg_Rsp,

	/**	
	@brief   设置当前是否启用带宽检测配置命令，对应于Ev_MT_BLL_SetBandWidthTestCfg_Ntf
	
	MainBuf(#BOOL32, bEnableBWTestCfg )

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetBandWidthTestCfg_Ntf,

	/**	
	@brief   获取当前是否启用带宽检测配置请求，对应于Ev_MT_BLL_GetBandWidthTestCfg_Rsp
	
	MainBuf(#BOOL32, bEnableBWTestCfg)

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetBandWidthTestCfg_Rsp,

	/**	
	@brief   设置内置MC丢包重传参数配置命令，对应于Ev_MT_BLL_SetMCResendParamCfg_Ntf
	
	MainBuf(#TMTMcRSParam_Api, tMcRSParamCfg)

	@verbatim
	{
	    "dwFirstTimeSpan": 0,
	    "dwSecondTimeSpan": 0,
	    "dwThirdTimeSpan": 0,
	    "dwRejectTimeSpan": 0
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetMCResendParamCfg_Ntf,

	/**	
	@brief   获取内置MC丢包重传参数配置请求响应，对应于Ev_MT_BLL_GetMCResendParamCfg_Rsp
	
	MainBuf(#TMTMcRSParam_Api, tMcRSParamCfg)

	@verbatim
	{
	    "dwFirstTimeSpan": 0,
	    "dwSecondTimeSpan": 0,
	    "dwThirdTimeSpan": 0,
	    "dwRejectTimeSpan": 0
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetMCResendParamCfg_Rsp,
	
	/**	
	@brief   获取内置MC丢包重传参数配置请求响应，对应于Ev_MT_BLL_GetMCResendParamCfg_Rsp
	
	MainBuf(#TMTMcRSParam_Api, tMcRSParamCfg)

	@verbatim
	{
	    "dwFirstTimeSpan": 0,
	    "dwSecondTimeSpan": 0,
	    "dwThirdTimeSpan": 0,
	    "dwRejectTimeSpan": 0
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetAssVideoParamCfg_Ntf,

	/**	
	@brief   获取内置MC丢包重传参数配置请求响应，对应于Ev_MT_BLL_GetAssVideoParamCfg_Rsp
	
	MainBuf(#TMTMcRSParam_Api, tMcRSParamCfg)

	@verbatim
	{
	    "dwFirstTimeSpan": 0,
	    "dwSecondTimeSpan": 0,
	    "dwThirdTimeSpan": 0,
	    "dwRejectTimeSpan": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetAssVideoParamCfg_Rsp,

	/**	
	@brief   设置是否启用自动双流源配置命令，对应于Ev_MT_BLL_SetDualStramSrcAdjCfg_Ntf
	
	MainBuf(#BOOL32, bEnableAssStreamSrcCfg )

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetDualStramSrcAdjCfg_Ntf,

	/**	
	@brief   获取自动双流源配置请求，对应于Ev_MT_BLL_GetDualStramSrcAdjCfg_Rsp
	
	MainBuf(#BOOL32, bEnableAssStreamSrcCfg)

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetDualStramSrcAdjCfg_Rsp,

	/**	
	@brief   设置呼叫协议类型配置命令，对应于Ev_MT_BLL_SetCallProtocolCfg_Ntf
	
	MainBuf(#EmConfProtocol_Api, emCallProtocol)

	@verbatim
	{
	    "emCallProtocol":enum
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetCallProtocolCfg_Ntf,

	/**	
	@brief    获取呼叫协议类型配置请求响应，对应于Ev_MT_BLL_GetCallProtocolCfg_Rsp
	
	MainBuf(#EmConfProtocol_Api ,emCallProtocol)

	@verbatim
	{
	     "m_emCallProtocol":enum
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetCallProtocolCfg_Rsp,

	/**	
	@brief    设置加密类型命令，对应于Ev_MT_BLL_SetEncryptTypeCfg_Ntf
	
	MainBuf(#EmEncryptArithmetic_Api, emEncrypt )

	@verbatim
	{
	    "emEncrypt":enum
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetEncryptTypeCfg_Ntf,

	/**	
	@brief    获取会议加密类型请求响应，对应于Ev_MT_BLL_GetEncryptTypeCfg_Rsp
	
	MainBuf(#EmEncryptArithmetic_Api, emEncrypt)

	@verbatim
	{
        "m_emEncrypt":enum
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetEncryptTypeCfg_Rsp,

	/**	
	@brief    设置断链检测时间间隔配置(秒)，对应于Ev_MT_BLL_SetKeepAliveItrvlCfg_Ntf
	
	MainBuf(#u32 ,dwKeepAliveItv )

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetKeepAliveItrvlCfg_Ntf,

	/**	
	@brief    获取断链检测时间间隔配置请求，对应于Ev_MT_BLL_GetKeepAliveItrvlCfg_Rsp
	
	MainBuf(#u32 ,dwKeepAliveItv)

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetKeepAliveItrvlCfg_Rsp,

	
	/**	
	@brief    设置断链检测时间间隔配置(秒)，对应于Ev_MT_BLL_SetSipKeepAliveItrvlCfg_Ntf
	
	MainBuf(#u32 ,dwKeepAliveItv )

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetSipKeepAliveItrvlCfg_Ntf,

	/**	
	@brief    获取断链检测时间间隔配置请求，对应于Ev_MT_BLL_GetSipKeepAliveItrvlCfg_Rsp
	
	MainBuf(#u32 ,dwKeepAliveItv)

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetSipKeepAliveItrvlCfg_Rsp,

	/**	
	@brief    设置FEC配置命令，对应于Ev_MT_BLL_SetFECCfg_Ntf
	
	MainBuf(#TMTFecInfo_Api, tFecInfoCfg)

	@verbatim
	{
	    "bEnableFec": true,
     	"byAlgorithm": 0,
    	"wPackLen": 0,
    	"bIntraFrame": true,
	    "dwDataPackNum": 0,
	    "dwCrcPackNum": 0
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetFECCfg_Ntf,

	/**	
	@brief    获取设置FEC配置请求，对应于Ev_MT_BLL_GetFECCfg_Rsp
	
	MainBuf(#TMTFecInfo_Api ,tFecInfoCfg)

	@verbatim
	{
	    "bEnableFec": true,
	    "byAlgorithm": 0,
	    "wPackLen": 0,
	    "bIntraFrame": true,
	    "dwDataPackNum": 0,
	    "dwCrcPackNum": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetFECCfg_Rsp,

	/**	
	@brief    设置高中低档的会议码率配置命令(小于64任务是纯音频呼叫)，对应于Ev_MT_BLL_SetCallRateLvCfg_Ntf
	
	MainBuf(#u32 ,dwCallRate)

	@verbatim
	{
	     "basetype": 0 
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetCallRateLvCfg_Ntf,

	/**	
	@brief     获取高中低档的会议码率配置请求(小于64任务是纯音频呼叫)响应，对应于Ev_MT_BLL_GetCallRateLvCfg_Rsp
	
	MainBuf(#u32 ,dwCallRateLevel)

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetCallRateLvCfg_Rsp,

	/**		
	@brief   双流发送比率, 对应Ev_MT_BLL_SetVidBitRationCfg_Ntf
	
	MainBuf(#TVidBitRationCfg_Api, tVidBitRationCfg)

	@verbatim
	{
	    "emRationStrategy": "",
	    "adwMainVidRation": [
	        0,
	        1
	    ],
	    "adwAssVidRation": [
	        0,
	        1
	    ]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetVidBitRationCfg_Ntf,

	/**		
	@brief   双流发送比率，对应Ev_MT_BLL_GetVidBitRationCfg_Rsp
	
	MainBuf(#TVidBitRationCfg_Api, tVidBitRationCfg)

	@verbatim
	{
	    "emRationStrategy": "",
	    "adwMainVidRation": [
	        0,
	        1
	    ],
	    "adwAssVidRation": [
	        0,
	        1
	    ]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetVidBitRationCfg_Rsp,

	/**		
	@brief  设置终端版本厂商相关信息，对应Ev_MT_BLL_SetTerlInfoRt_Ntf
	
	MainBuf(#TTerminalInfo_Api ,tTerminalInfoCfg)

	@verbatim
	{
    	"emMtModel" : 0,
	    "achTypeName" : "",
	    "achHardwareVer" : "",
	    "achSoftwareVer" : "",
	    "achOEMName" : "",
	    "achFPGA1Ver" : "",
		"achFPGA2Ver" : "",
	    "achCPLDVer" : "",
	    "achSerialNum" : "",
        "achInfraredVer": ""
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetTerlInfoRt_Ntf,

	/**		
	@brief  获取终端版本信息配置请求(RT)响应，对应Ev_MT_BLL_GetTerlInfoRt_Rsp
	
	MainBuf(#TTerminalInfo_Api, tTerminalInfoCfg)

	@verbatim
	{
	    "emMtModel" : 0,
	    "achTypeName" : "",
	    "achHardwareVer" : "",
	    "achSoftwareVer" : "",
	    "achOEMName" : "",
	    "achFPGA1Ver" : "",
		"achFPGA2Ver" : "",
	    "achCPLDVer" : "",
        "achSerialNum" : "",
        "achInfraredVer": ""
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetTerlInfoRt_Rsp,

	/**		
	@brief  设置终端名称信息配置命令，对应Ev_MT_BLL_SetUserNameCfg_Ntf
	
	MainBuf(#TMtTerminalName_Api, tTerminalNameCfg)

	@verbatim
	{
	    "achE164" : "",
	    "achTerlAlias" : ""
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetUserNameCfg_Ntf,

	/**		
	@brief  获取终端名称信息配置请求响应，对应Ev_MT_BLL_GetUserNameCfg_Rsp
	
	MainBuf(#TMtTerminalName_Api ,tTerminalNameCfg)

	@verbatim
	{
	    "achE164" : "",
	    "achTerlAlias" : ""
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetUserNameCfg_Rsp,

	/**		
	@brief   开始终端服务，对应Ev_MT_BLL_SrvStartResult_Ntf
	
	MainBuf(#BOOL32 ,bStartRlt )\n
	SubBuf(#TSrvKeepLiveInfo_Api ,tSrvKeepLiveInfo)
	@verbatim
	{
	    "basetype": true
	}
	{
	    "achSysalias": "",
	    "dwMtAid": 1,
	    "dwTime": 1
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SrvStartResult_Ntf,

	/**		
	@brief   停止终端服务，对应Ev_MT_BLL_SrvEndtResult_Ntf
	
	MainBuf(#BOOL32 ,bEndRlt )

	@verbatim
	{
	     "basetype": true
	}
	SubBuf(u32, dwMtaid)
	{
	     "basetype": 0
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SrvEndtResult_Ntf,

	/**		
	@brief   设置应答模式配置命令，对应Ev_MT_BLL_SetAnswerModeCfg_Ntf
	
	MainBuf(#u32, dwAnswerMode )

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/	   
	Ev_MtApi_Base_SetAnswerModeCfg_Ntf,

	/**		
	@brief    获取应答模式请求响应，对应Ev_MT_BLL_GetAnswerModeCfg_Req
	
	MainBuf(#u32, dwAnswerMode )

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetAnswerModeCfg_Rsp,
	
	//Ev_MT_LoginApsSvr_Rsp
	Ev_MtApi_Base_LoginApsSvr_Rsp,

	/**
	@brief    设置呼叫码率配置通知
	
	MainBuf(#TMTCallBitRate_Api, tMTCallBitRate)

	@verbatim
	{
		"adwRate" :
		[
		    {
				"dwRate" : 0
			}
		]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetCallBitrateCfg_Ntf,
	
	/**
	@brief    获取呼叫码率配置响应
	
	MainBuf(#TMTCallBitRate_Api, tMTCallBitRate)

	@verbatim
	{
		"adwRate" :
		[
		    {
				"dwRate" : 0
			}
		]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetCallBitrateCfg_Rsp,

	/**
	@brief    设置自动发送内容共享，对应Ev_MT_BLL_SetAutoSendSharedContentCfg_Ntf
	
	MainBuf(#BOOL32, bAuto)

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetAutoSendSharedContentCfg_Ntf,

	/**
	@brief    获取自动发送内容共享，对应Ev_MT_BLL_GetAutoSendSharedContentCfg_Rsp
	
	MainBuf(#BOOL32 ,bAutoSendSharedContent)

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetAutoSendSharedContentCfg_Rsp,

	/**
	@brief    设置是否允许登陆平台服务，对应Ev_MT_BLL_SetLoginPlatformSrvCfg_Ntf
	
	MainBuf(#BOOL32, bLogin )

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetLoginPlatformSrvCfg_Ntf,

	/**
	@brief    获取是否允许登陆平台服务，对应Ev_MT_BLL_GetLoginPlatformSrvCfg_Rsp
	
	MainBuf(#BOOL32 ,bLoginPlatformSrv)

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetLoginPlatformSrvCfg_Rsp,

	/**
	@brief   设置平滑发送等级，对应wParam(u32, dwSmooth )
	
	MainBuf(#u32 ,dwSmoothSendLevel)

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetSmoothSendCfg_Ntf,

	/**
	@brief   获取平滑发送等级响应，对应Ev_MT_BLL_GetSmoothSendCfg_Rsp
	
	MainBuf(#u32, dwSmoothSendLevel)

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetSmoothSendCfg_Rsp,

	/**
	@brief   设置telnet开关，对应Ev_MT_BLL_SetUseTelnetCfg_Ntf
	
	MainBuf(#BOOL32, bUsed )

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetUseTelnetCfg_Ntf,

	/**
	@brief   获取telnet开关请求响应，对应Ev_MT_BLL_GetUseTelnetCfg_Rsp
	
	MainBuf(#BOOL32, bUseTelnet )

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetUseTelnetCfg_Rsp,

	/**
	@brief   设置Http开关，对应Ev_MT_BLL_SetUseHTTPCfg_Ntf
	
	MainBuf(#BOOL32, bUsed )

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetUseHTTPCfg_Ntf,

	/**
	@brief   获取Http开关请求响应，对应Ev_MT_BLL_GetUseHTTPCfg_Rsp
	
	MainBuf(#BOOL32, bUseHTTP )

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetUseHTTPCfg_Rsp,

	/**
	@brief   设置FTP开关，对应Ev_MT_BLL_SetUseFtpCfg_Ntf
	
	MainBuf(#BOOL32, bUsed  )

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetUseFtpCfg_Ntf,

	/**
	@brief   获取FTP开关请求响应，对应Ev_MT_BLL_GetUseFtpCfg_Rsp
	
	MainBuf(#BOOL32 ,bUseFtp)

	@verbatim
	{
         "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetUseFtpCfg_Rsp,

	/**
	@brief   设置API服务器配置信息，对应Ev_MT_BLL_SetPlatformApiRt_Ntf
	
	MainBuf(#TMtPlatformApiAddr_Api, tPlatFormApiAddr)

	@verbatim
	{
	    "achDomain": "",
	    "dwIp": 34535656
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetPlatformApiRt_Ntf,

	/**
	@brief   设置微博服务器配置信息，对应Ev_MT_BLL_SetMicroBlogRt_Ntf
	
	MainBuf(#TMtMicroBlogAddr_Api ,tMicroBlogAddr)

	@verbatim
	{
	    "achDomain": "",
	    "dwIp": 34535656
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetMicroBlogRt_Ntf,

	/**
	@brief   获取微博服务器地址响应，对应Ev_MT_BLL_GetMicroBlogRt_Rsp
	
	MainBuf(#TMtMicroBlogAddr_Api ,tMicroBlogAddr)

	@verbatim
	{
	    "achDomain": "",
	    "dwIp": 34535656
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetMicroBlogRt_Rsp,

	/**
	@brief   设置登录策略（暂时不用），对应Ev_MT_BLL_SetSvrLoginTacticsCfg_Ntf
	
	MainBuf(#TMtLoginTacticsTable_Api, tLoginCfg)

	@verbatim
	{
	    "atLoginTactic" :
	    [
	    {
	        "emSvrType" : 1,
	        "aemPreSvrList" :
	    [
	    {
	        "srvtype" : 0
	    }
	    ],
	        "byCnt"  : 3,
	        "bUsed" : 4
	    }
	    ]
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetSvrLoginTacticsCfg_Ntf,

	/**
	@brief   获取登录策略响应，对应Ev_MT_BLL_GetSvrLoginTacticsCfg_Rsp
	
	MainBuf(#TMtLoginTacticsTable_Api, tLoginCfg)

	@verbatim
	{
	    "atLoginTactic" :
	    [
	    {
	        "emSvrType" : 1,
	        "aemPreSvrList" :
	        [
	        {
	            "srvtype" : 0
	        }
	        ],
	        "byCnt"  : 3,
	        "bUsed" : 4
    	}
    	]
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetSvrLoginTacticsCfg_Rsp,

	/**
	@brief   设置自动噪音抑制，对应Ev_MT_BLL_SetAnsCfg_Ntf
	
	MainBuf(#BOOL32 ,bAns )

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetAnsCfg_Ntf,

	/**
	@brief  获取自动噪声增益配置请求响应，对应Ev_MT_BLL_GetAnsCfg_Rsp
	
	MainBuf(#BOOL32, bAns)

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetAnsCfg_Rsp,

	/**
	@brief  设置自动增益控制，对应Ev_MT_BLL_SetAgcCfg_Ntf
	
	MainBuf(#BOOL32, bAgc )

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetAgcCfg_Ntf,

	/**
	@brief  获取自动增益控制配置请求响应，对应Ev_MT_BLL_GetAgcCfg_Rsp
	
	MainBuf(#BOOL32, bAgc)

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetAgcCfg_Rsp,


	/**
	@brief  设置自动回声抵消，对应Ev_MT_BLL_SetAecCfg_Ntf
	
	MainBuf(#TAdjustAecParamCfg_Api, tAec)

	@verbatim
	{
	    "bAuto": true,
		"bEnable": true,
	    "dwVal": 19
		"dwManualVal": 19
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetAecCfg_Ntf,

	/**
	@brief  获取自动回声抵消响应，对应Ev_MT_BLL_GetAnsCfg_Rsp
	
	MainBuf(#TAdjustAecParamCfg_Api, tAec)

	@verbatim
	{
	    "bAuto": true,
		"bEnable": true,
	    "dwVal": 19
		"dwManualVal": 19
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetAecCfg_Rsp,

	/**
	@brief  设置MC信息，对应Ev_MT_BLL_SetMCInfoRt_Ntf
	
	MainBuf(#TInnerMCRunInfo_Api ,tMcRunInfo)

	@verbatim
	{
	    "bMcIsExist" : true,
	    "bMcIsActive" : true,
	    "bMcIsInconf" : true,
	    "dwMcMemMaxNum" : 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetMCInfoRt_Ntf,

	/**
	@brief  获取MC配置响应，对应Ev_MT_BLL_GetMCInfoRt_Rsp
	
	MainBuf(#TInnerMCRunInfo_Api, tMcRunInfo)

	@verbatim
	{
	    "bMcIsExist" : true,
	    "bMcIsActive" : true,
	    "bMcIsInconf" : true,
	    "dwMcMemMaxNum" : 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetMCInfoRt_Rsp,

	/**
	@brief  设置通道信息，对应Ev_MT_BLL_SetChanInfoRt_Ntf
	
	MainBuf(#TMutiChanDsInfo_Api ,tMutiChanDsInfo)

	@verbatim
	{
	    "atChanInfo" :
	    [
    	{
        	"emState": 0,
	        "emChanType": 0,
	        "emIndex": 0,
	        "bActive": 0,                              
	        "abyEncryKey": "str",
	        "emAudFormat": 0,  
	        "emAacChnlNum": 0,    

        	"emVidLabel": 0,  
	        "emVidFormat": 0,
	        "emVidResolution": 0, 
	        "dwFrame": 0,
	        "dwH264Profile": 0,
	        "emEncrypt": 0, 
	        "wChanBitrate": 0
	        }
        	]
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetChanInfoRt_Ntf,

	/**
	@brief  获取通道信息配置响应，对应Ev_MT_BLL_GetChanInfoRt_Rsp
	
	MainBuf(#TMutiChanDsInfo_Api ,tMutiChanDsInfo)

	@verbatim
	{
	    "atChanInfo" :
	    [
	    {
	        "emState": 0,
	        "emChanType": 0,
	        "emIndex": 0,
	        "bActive": 0,                              
	        "abyEncryKey": "str",
	        "emAudFormat": 0,  
	        "emAacChnlNum": 0,    

         	"emVidLabel": 0,  
        	"emVidFormat": 0,
	        "emVidResolution": 0, 
	        "dwFrame": 0,
	        "dwH264Profile": 0,
	        "emEncrypt": 0, 
	        "wChanBitrate": 0
	    }
	    ]
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetChanInfoRt_Rsp,

	/**
	@brief  设置登录密码，对应Ev_MT_BLL_SetLoginPwdCfg_Ntf
	
	MainBuf(#TMtLoginPlatformPwdCfg_Api, tCfg_Api)

	@verbatim
	{
	    "bIsModifyEnable": false,
	    "achPassword": ""
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetLoginPwdCfg_Ntf,

	/**
	@brief  获取登录密码配置响应，对应Ev_MT_BLL_GetLoginPwdCfg_Rsp
	
	MainBuf(#TMtLoginPlatformPwdCfg_Api, tTerminalLoginPwd)

	@verbatim
	{
	    "bIsModifyEnable": false,
	    "achPassword": ""
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetLoginPwdCfg_Rsp,

	/**
	@brief  设置设备型号，对应Ev_MT_BLL_SetModelCfg_Ntf
	*/	
	Ev_MtApi_Base_SetModelCfg_Ntf,

	/**
	@brief  获取设备型号，对应Ev_MT_BLL_GetModelCfg_Rsp
	*/	
	Ev_MtApi_Base_GetModelCfg_Rsp,

	/**
	@brief  设置系统升级状态，对应Ev_MT_BLL_SetSysUpgradeRt_Ntf
	
	MainBuf(#BOOL32 ,bSysUpgrade)

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetSysUpgradeRt_Ntf,

	/**
	@brief   获取系统升级状态配置响应，对应Ev_MT_BLL_GetSysUpgradeRt_Rsp
	
	MainBuf(#BOOL32 ,m_bSysUpgrade)

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetSysUpgradeRt_Rsp,

	/**
	@brief   设置会议使用的端口，对应Ev_MT_BLL_SetConfUsedPortsRt_Ntf
	
	MainBuf(#TMTUsedPortList_Api ,tConfUsedPorts)

	@verbatim
	{
	    "emPortType": 1,
	    "atTMTUsedPort": [
	    {
	        "dwPort": 1,
	        "achName": ""
	    },
	    {
	        "dwPort": 1,
	        "achName": ""
	    }
	    ]
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetConfUsedPortsRt_Ntf,

	/**
	@brief    获取会议使用的端口配置响应，对应Ev_MT_BLL_GetConfUsedPortsRt_Rsp
	
	MainBuf(#TMTUsedPortList_Api ,tConfUsedPorts)

	@verbatim
	{
	    "emPortType": 1,
    	"atTMTUsedPort": [
	    {
	        "dwPort": 1,
	        "achName": ""
	    },
	    {
	        "dwPort": 1,
	        "achName": ""
	    }
	    ]
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetConfUsedPortsRt_Rsp,

	/**
	@brief    设置MC使用的端口，对应Ev_MT_BLL_SetMcUsedPortsRt_Ntf
	
	MainBuf(#TMTUsedPortList_Api, tMcUsedPorts)

	@verbatim
	{
	    "emPortType": 1,
	    "atTMTUsedPort": [
	    {
	        "dwPort": 1,
	        "achName": ""
	    },
	    {
	        "dwPort": 1,
	        "achName": ""
	    }
	    ]
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetMcUsedPortsRt_Ntf,

	/**
	@brief   获取MC使用的端口配置响应，对应Ev_MT_BLL_GetMcUsedPortsRt_Rsp
	
	MainBuf(#TMTUsedPortList_Api ,tMcUsedPorts)

	@verbatim
	{
	    "emPortType": 1,
	    "atTMTUsedPort": [
	    {
	        "dwPort": 1,
	        "achName": ""
	    },
	    {
	        "dwPort": 1,
	        "achName": ""
	    }
	    ]
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetMcUsedPortsRt_Rsp,

	/**
	@brief   设置Vod使用的端口，对应Ev_MT_BLL_SetVodUsedPortsRt_Ntf
	
	MainBuf(#TMTUsedPortList_Api ,tVodUsedPorts)

	@verbatim
	{
	    "emPortType": 1,
	    "atTMTUsedPort": [
	    {
	        "dwPort": 1,
	        "achName": ""
	    },
	    {
	        "dwPort": 1,
	        "achName": ""
	    }
	    ]
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetVodUsedPortsRt_Ntf,

	/**
	@brief    获取Vod使用的端口响应，对应Ev_MT_BLL_GetVodUsedPortsRt_Rsp
	
	MainBuf(#TMTUsedPortList_Api ,tVodUsedPorts)

	@verbatim
	{
	    "emPortType": 1,
	    "atTMTUsedPort": [
	    {
	        "dwPort": 1,
	        "achName": ""
	    },
	    {
	        "dwPort": 1,
	        "achName": ""
	    }
	    ]
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetVodUsedPortsRt_Rsp,

	/**
	@brief   设置Im使用的端口，对应Ev_MT_BLL_SetImUsedPortsRt_Ntf
	
	MainBuf(#TMTUsedPortList_Api, tImUsedPorts)

	@verbatim
	{
	    "emPortType": 1,
	    "atTMTUsedPort": [
	    {
	        "dwPort": 1,
	        "achName": ""
	    },
	    {
	        "dwPort": 1,
	        "achName": ""
	    }
	    ]
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetImUsedPortsRt_Ntf,

	/**
	@brief    获取Im使用的端口配置响应，对应Ev_MT_BLL_GetImUsedPortsRt_Rsp
	
	MainBuf(#TMTUsedPortList_Api ,tImUsedPorts)

	@verbatim
	{
	    "emPortType": 1,
	    "atTMTUsedPort": [
	    {
	        "dwPort": 1,
	        "achName": ""
	    },
	    {
	        "dwPort": 1,
	        "achName": ""
	    }
	    ]
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetImUsedPortsRt_Rsp,
	
	/**
	@brief   设置登录IM所需要的参数，对应Ev_MT_BLL_SetLoginIMParamCfg_Ntf
	
	MainBuf(#TImUserLogin_Api, tLoginIM)

	@verbatim
	{
    	"achNO" : "",
    	"achUserPwd" : "",  
    	"achStunAddr" : "", 
	    "achDefaultSaveDir" : "",
    	"achEnterpriseName" : "",
	    "achPicSaveDir" : "",
	    "achResource" : "",            
      	"achSock5Username" : "",     
    	"achSock5Password" : "",     
    	"achConfigPath" : "",              
    	"achSock5Addr" : "",        

	    "dwImIP" : 0,                                              
	    "wPort" : 0,                                               
    	"wStunPort" : 0,                                           
    	"wSock5Port" : 0,                                          
    	"byPwdLen" : 0,                                            

	    "bFileShareEnable" : 0,                                 
    	"bAudioCapability" : 0,                                 
    	"bVideoCapability" : 0,                                 
    	"bInstant" : 0,                                         
    	"bUseSock5" : 0,                                        
    	"bCompression" : 0                                     
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetLoginIMParamCfg_Ntf,

	/**
	@brief  获取登录IM所需要的参数请求响应，对应Ev_MT_BLL_GetLoginIMParamCfg_Rsp
	
	MainBuf(#TImUserLogin_Api ,tLoginIM)

	@verbatim
	{
    	"achNO" : "",
    	"achUserPwd" : "",  
    	"achStunAddr" : "", 
	    "achDefaultSaveDir" : "",
    	"achEnterpriseName" : "",
	    "achPicSaveDir" : "",
	    "achResource" : "",            
      	"achSock5Username" : "",     
    	"achSock5Password" : "",     
    	"achConfigPath" : "",              
    	"achSock5Addr" : "",        

	    "dwImIP" : 0,                                              
	    "wPort" : 0,                                               
    	"wStunPort" : 0,                                           
    	"wSock5Port" : 0,                                          
    	"byPwdLen" : 0,                                            

	    "bFileShareEnable" : 0,                                 
    	"bAudioCapability" : 0,                                 
    	"bVideoCapability" : 0,                                 
    	"bInstant" : 0,                                         
    	"bUseSock5" : 0,                                        
    	"bCompression" : 0                                     
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetLoginIMParamCfg_Rsp,

	/**
	@brief  设置登录APS所需要的参数，对应Ev_MT_BLL_SetApsLoginParamCfg_Ntf
	
	MainBuf(#TMTApsLoginParam_Api ,tApsLoginParam)

	@verbatim
	{
	    "achUsername": "name",
	    "achPassword": "pwd",
	    "achSoftwareVer": "1.1",
	    "achModelName": "hd100",
	    "achOemInfo": "kedacom"
	}
	@endverbatim
	*/	
	Ev_MTApi_Base_SetApsLoginParamCfg_Ntf,

	/**
	@brief  获取登录APS所需要的参数请求响应，对应Ev_MT_BLL_GetApsLoginParamCfg_Rsp
	
	MainBuf(#TMTApsLoginParam_Api, tApsLoginParam)

	@verbatim
	{
	    "achUsername": "name",
	    "achPassword": "pwd",
	    "achSoftwareVer": "1.1",
	    "achModelName": "hd100",
	    "achOemInfo": "kedacom"
	}
	@endverbatim
	*/	
	Ev_MTApi_Base_GetApsLoginParamCfg_Rsp,

	/**
	@brief  设置，对应Ev_MT_BLL_SetSusLoginParamCfg_Ntf
	
	MainBuf(#TMTUpgradeClientInfo_Api ,tClientInfo)

	@verbatim
	{
    	"tServerInfo": {
    	    "dwServerIp": 0,
	        "bUsedProxy": true,
	        "tProxyInfo": {
	            "dwProxyIp": 0,
	            "dwProxyPort": 0,
	            "dwAuthenNum": 0,
	            "achAuthenMethod": "",
	            "achUserName": "",
	            "achPassword": ""
	                       }
	                     },
	    "tDevInfo": {
	        "achDevType": "",
	        "achOemMark": "",
    	    "achE164": "",
	        "achCurSoftVer": "",
	        "dwDevIp": 0
	    }
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetSusLoginParamCfg_Ntf,

	/**
	@brief  设置带宽，对应Ev_MT_BLL_SetBandWidthRt_Ntf
	
	MainBuf(#TMTNetStatus_Api，tMTNetStatus)

	@verbatim
	{
	    "bTimeout": true,
	    "tSendBandwidth": 
	    {
	        "dwBandWidth": 1024,
	        "dwDropRate": 5
	    },
	    "tRecvBandWidth": 
	    {
	       "dwBandWidth": 1024,
	       "dwDropRate": 5
	    }
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetBandWidthRt_Ntf,

	/**	
	@brief    带宽检测结果 对应Ev_MT_BLL_GetBandWidthRt_Rsp
	
	MainBuf(#TMTNetStatus_Api, tMTNetStatus)

	@verbatim
	{
		"bTimeout": true,
		"tSendBandwidth": 
		{
			"dwBandWidth": 1024,
			"dwDropRate": 5
		},
		"tRecvBandWidth": 
		{
			"dwBandWidth": 1024,
			"dwDropRate": 5
		}
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetBandWidthRt_Rsp,

	/**	
	@brief    设置运行时映射表, 对应Ev_MT_BLL_SetSysCtrlSrvInfoRt_Ntf
	
	MainBuf(#TMutiTServiceInfoRtData_Api ,tSysCtrlSrvInfo)

	@verbatim
	{
	    "atSrvInfo": 
	    [
	    {
	        "dwIndex": 1,
	        "dwMtaid": 1,
	        "achPath": "str",
	        "achSysAlias": "",
	        "emStartmod": 1,
	        "achSrtFuncName" : "str",
	        "achEndFuncName": "str",
	        "emSrvState": 1,
        	"emSrvLiveState": 1,
        	"dwDetectTime": 1,
	        "dwTimeStamp": 1,
	        "dwDllHandler": 1,
	        "dwProcesspId": 1,
         	"achVersion": "str"
	    }
	    ]
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetSysCtrlSrvInfoRt_Ntf,

	/**	
	@brief     获取系统控制映射表配置, 对应Ev_MT_BLL_GetSysCtrlSrvInfoRt_Rsp
	
	MainBuf(#TMutiTServiceInfoRtData_Api, tSysCtrlSrvInfo)

	@verbatim
	{
	    "atSrvInfo": 
	    [
	    {
	        "dwIndex": 1,
	        "dwMtaid": 1,
	        "achPath": "str",
	        "achSysAlias": "",
	        "emStartmod": 1,
	        "achSrtFuncName" : "str",
	        "achEndFuncName": "str",
	        "emSrvState": 1,
        	"emSrvLiveState": 1,
        	"dwDetectTime": 1,
	        "dwTimeStamp": 1,
	        "dwDllHandler": 1,
	        "dwProcesspId": 1,
         	"achVersion": "str"
	    }
	    ]
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetSysCtrlSrvInfoRt_Rsp,

	/**	
	@brief     子系统数量, 对应Ev_MT_BLL_SetSysCtrlSrvNumRt_Ntf
	
	MainBuf(#u32, dwSysCtrlSrvNum)

	@verbatim
	{
	    "basetype": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetSysCtrlSrvNumRt_Ntf,

	/**	
	@brief      获取运行时映射表中模块个数配置, 对应Ev_MT_BLL_GetSysCtrlSrvNumRt_Rsp
	
	MainBuf(#u32, dwSysCtrlSrvNum)

	@verbatim
	{
	    "basetype": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetSysCtrlSrvNumRt_Rsp,

	/**	
	@brief     设置默认启动映射表, 对应Ev_MT_BLL_SetSysCtrlDefSrvInfoCfg_Ntf
	
	MainBuf(#TMutiTServiceDefInfo_Api, tSysCtrlDefSrvInfo)

	@verbatim
	{
	    "atSvcDefInfo": 
	    [
	    {
	        "dwIndex": "",
	        "achPath": "",
	        "achSysalias": "",
          	"emStartmod": 1,
          	"achSrtfuncname": "",
          	"achEndfuncname": ""
	    }
	    ]
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetSysCtrlDefSrvInfoCfg_Ntf,

	/**	
	@brief      获取默认启动映射表配置, 对应Ev_MT_BLL_GetSysCtrlDefSrvInfoCfg_Rsp
	
	MainBuf(#TMutiTServiceDefInfo_Api, tSysCtrlDefSrvInfo)

	@verbatim
	{
	    "atSvcDefInfo": 
	    [
	    {
	        "dwIndex": "",
	        "achPath": "",
	        "achSysalias": "",
          	"emStartmod": 1,
          	"achSrtfuncname": "",
          	"achEndfuncname": ""
	    }
	    ]
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetSysCtrlDefSrvInfoCfg_Rsp,

	/**	
	@brief      设置默认映射表中模块个数, 对应Ev_MT_BLL_SetSysCtrlDefSrvNumCfg_Ntf
	
	MainBuf(#u32 ,dwSysCtrlDefSrvNum )

	@verbatim
	{
	    "basetype": 0
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetSysCtrlDefSrvNumCfg_Ntf,
	
	/**	
	@brief      获取默认映射表中模块个数配置响应, 对应Ev_MT_BLL_GetSysCtrlDefSrvNumCfg_Rsp
	
	MainBuf(#u32, dwSysCtrlDefSrvNum)

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetSysCtrlDefSrvNumCfg_Rsp,

     /**
	@brief 获取默认映射表中模块个数配置响应, 对应Ev_MT_BLL_SetSatelliteCfg_Ntf
	*/ 
	Ev_MtApi_Base_SetSatelliteCfg_Ntf,


    /**
	@brief 获取是否卫星终端配置响应, 对应Ev_MT_BLL_GetSatelliteCfg_Rsp
	*/    
	Ev_MtApi_Base_GetSatelliteCfg_Rsp,

	/**	
	@brief     设置323协议栈侦听端口, 对应Ev_MT_BLL_SetH323CallingPortRt_Ntf
	
	MainBuf(# u16, wH323CallingPort )

	@verbatim
	{
    	 "basetype": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetH323CallingPortRt_Ntf,

	/**	
	@brief     获取323协议栈侦听端口请求响应, 对应Ev_MT_BLL_GetH323CallingPortRt_Rsp
	
	MainBuf(#u16, wH323CallingPort)

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetH323CallingPortRt_Rsp,

	/**	
	@brief      设置H460配置通知, 对应Ev_MT_BLL_SetH460Cfg_Ntf
	
	MainBuf(#TMtH460PxyCfg_Api ,tH460PxyCfg)

	@verbatim
	{
	    "bEnable": true,
	    "dwSrvIp": 2345566,
	    "achNumber": "",
	    "achPassword": ""
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetH460Cfg_Ntf,

	/**	
	@brief      获取H460配置请求响应, 对应Ev_MT_BLL_GetH460Cfg_Rsp
	
	MainBuf(#TMtH460PxyCfg_Api, tH460Cfg)

	@verbatim
	{
	    "bEnable": true,
	    "dwSrvIp": 2345566,
	    "achNumber": "",
	    "achPassword": ""
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetH460Cfg_Rsp,

	/**	
	@brief       H323代理设置, 对应Ev_MT_BLL_SetH323PxyCfg_Ntf
	
	MainBuf(#TMtH323PxyCfg_Api, tH323PxyCfg)

	@verbatim
	{
    	"bEnable": true,
    	"dwSrvIp": 2345566,
    	"dwSrvPort": 234,
    	"achNumber": "",
    	"achPassword": ""
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetH323PxyCfg_Ntf,

	/**	
	@brief       获取H323代理配置请求响应, 对应Ev_MT_BLL_GetH323PxyCfg_Rsp
	
	MainBuf(#TMtH323PxyCfg_Api, tH323PxyCfg)

	@verbatim
	{
    	"bEnable": true,
    	"dwSrvIp": 2345566,
    	"dwSrvPort": 234,
    	"achNumber": "",
    	"achPassword": ""
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetH323PxyCfg_Rsp,

	/**	
	@brief      Meeting服务器设置, 对应Ev_MT_BLL_SetMeetingCtrlRt_Ntf
	
	MainBuf(#TMtMeetingSvrAddr_Api ,tMeetingSvrAddr)

	@verbatim
	{
	    "achDomain" : "", 
	    "dwIp"     : 2 
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetMeetingCtrlRt_Ntf,

	/**	
	@brief      获取Meeting服务器响应, 对应Ev_MT_BLL_GetMeetingCtrlRt_Rsp
	
	MainBuf(#TMtMeetingSvrAddr_Api, tMeetingSvrAddr)

	@verbatim
	{
	    "achDomain" : "", 
	    "dwIp"     : 2 
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetMeetingCtrlRt_Rsp,

	/*********************硬终端产品开始********************/
	/***********用户设置**************/
	/**	
	@brief      设置双流显示模式, 对应Ev_MT_BLL_HD_SetDispModeCfg_Ntf  
	
	MainBuf(#EmDualVideoShowMode_Api, emCfg_Api )

	@verbatim
	{
	    "emCfg_Api":0 
	}
	@endverbatim
	*/		          
	Ev_MtApi_Base_Hd_SetDispModeCfg_Ntf,

	/**	
	@brief      获取双流显示模式请求, 对应Ev_MT_BLL_HD_GetDispModeCfg_Rsp   
	MainBuf(EmDualVideoShowMode_Api ,emDualShowMd)
	{
	    "m_emDualShowMd":0 
	}
	@endverbatim
	*/	         		
	Ev_MtApi_Base_Hd_GetDispModeCfg_Rsp,

	/**	
	@brief      设置视频输出制式, 对应Ev_MT_BLL_HD_SetHDResOutputCfg_Ntf 
	
	MainBuf(#THDMTVideoOutPortMode_Api, tCfg_Api)

	@verbatim
	{
	    "emFirst_priom_video_res": 1,
	    "emFirst_priom_vga_res": 1,
	    "emSecond_priom_video_res": 1,
	    "emSecond_priom_vga_res": 1,
	    "emAss_video_res": 1,
	}
	@endverbatim
	*/		         	//视频输出制式(value: THDMTVideoOutPortMode_Api )
	Ev_MtApi_Base_Hd_SetHDResOutputCfg_Ntf,

	/**	
	@brief      获取视频输出制式请求响应, 对应Ev_MT_BLL_HD_GetHDResOutputCfg_Rsp   
	
	MainBuf(#THDMTVideoOutPortMode_Api, tVideoOutPortMd)

	@verbatim
	{
	    "emFirst_priom_video_res": 1,
	    "emFirst_priom_vga_res": 1,
	    "emSecond_priom_video_res": 1,
	    "emSecond_priom_vga_res": 1,
	    "emAss_video_res": 1,
	}
	@endverbatim
	*/	             	//视频输出制式(value: THDMTVideoOutPortMode_Api )
	Ev_MtApi_Base_Hd_GetHDResOutputCfg_Rsp,

	/**	
	@brief    开关自动画中画，对应于Ev_MT_BLL_HD_SetAutoPIPCfg_Ntf
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		"bUse": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetAutoPIPCfg_Ntf,

	/**	
	@brief    开关自动画中画，对应于Ev_MT_BLL_HD_GetAutoPIPCfg_Rsp
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		"bUse": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetAutoPIPCfg_Rsp,

	/**	
	@brief    呼入铃声，对应于Ev_MT_BLL_HD_SetCallInRingCfg_Ntf
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetCallInRingCfg_Ntf,

	/**	
	@brief    呼入铃声，对应于Ev_MT_BLL_HD_GetCallInRingCfg_Rsp
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetCallInRingCfg_Rsp,
	
	/**	
	@brief    呼出铃声，对应于Ev_MT_BLL_HD_SetCallOutRingCfg_Ntf
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetCallOutRingCfg_Ntf,
	
	/**	
	@brief    呼出铃声，对应于Ev_MT_BLL_HD_GetCallOutRingCfg_Rsp
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetCallOutRingCfg_Rsp,
	
	/**	
	@brief    当前使用的横幅id号,Ev_MT_BLL_HD_SetEnablePresetBannerCfg_Ntf 
	
	MainBuf(#THDMTEnablePresetBanner_Api, tHDMTEnablePresetBanner)

	@verbatim
	{
		"dwBannerIndex": 1,
		"bEnable": 1
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetEnablePresetBannerCfg_Ntf,

	/**	
	@brief    当前使用的横幅id号,Ev_MT_BLL_HD_GetEnablePresetBannerCfg_Rsp   
	
	MainBuf(#THDMTEnablePresetBanner_Api, tHDMTEnablePresetBanner)

	@verbatim
	{
		"dwBannerIndex": 1,
		"bEnable": 1
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetEnablePresetBannerCfg_Rsp,

	/**	
	@brief    横幅配置,Ev_MT_BLL_HD_SetBannerInfoCfg_Ntf  
	
	MainBuf(#THDMTBannerInfo_Api, tHDMTBannerInfo)

	@verbatim
	{
		    "bEnable": 1,
			"dwTextClr": 1,
			"dwBkgClr": 1,
			"emTextAlign": 1,
			"emRollMode": 1,
			"dwTransParent": 1,
			"emRollSpeed": 1,
			"dwRollNum": 1,
			"dwStayTime": 1,
			"dwStartXPos": 1,
			"dwStartYPos": 1,
			"dwDisplayWidth": 1,
			"dwDisplayHeight": 1,
			"achWinInfo": "",
			"achBannerText": "",
			"dwUseType": 1,
			"achPictureName": "",
			"dwTextLineSpace": 1,
			"dwTextDisplayRatio": 1,
			"achPresetBannerName": "",
			"dwPresetBannerIndex": 1,
			"dwTextLineNum" : 1
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetOsdBannerInfoCfg_Ntf,

	/**	
	@brief    横幅配置,Ev_MT_BLL_HD_GetBannerInfoCfg_Rsp  
	
	MainBuf(#THDMTBannerInfo_Api, tHDMTBannerInfo)

	@verbatim
	{
		    "bEnable": 1,
			"dwTextClr": 1,
			"dwBkgClr": 1,
			"emTextAlign": 1,
			"emRollMode": 1,
			"dwTransParent": 1,
			"emRollSpeed": 1,
			"dwRollNum": 1,
			"dwStayTime": 1,
			"dwStartXPos": 1,
			"dwStartYPos": 1,
			"dwDisplayWidth": 1,
			"dwDisplayHeight": 1,
			"achWinInfo": "",
			"achBannerText": "",
			"dwUseType": 1,
			"achPictureName": "",
			"dwTextLineSpace": 1,
			"dwTextDisplayRatio": 1,
			"achPresetBannerName": "",
			"dwPresetBannerIndex": 1,
			"dwTextLineNum" : 1
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetOsdBannerInfoCfg_Rsp,

	/**	
	@brief    mtc横幅配置  
	
	MainBuf(#THDMTBannerInfoList_Api, tHDMTBannerInfoList)

	@verbatim
	{
   "atMtBannerInfoList" : [
      {
         "achBkColor" : "",
         "achPictureName" : "",
         "achPresetBannerName" : "",
         "atBannerContext" : [
            {
               "achFacenametype" : "",
               "achTextContent" : "",
               "achTextcolor" : "",
               "achTextsize" : "",
               "bTextBold" : false,
               "bTextItalic" : false,
               "bTextUnderline" : false
            }
         ],
         "bEnable" : false,
         "dwDisplayHeight" : 0,
         "dwDisplayWidth" : 0,
         "dwPresetBannerIndex" : 0,
         "dwRollNum" : 0,
         "dwStayTime" : 0,
         "dwTextDisplayRatio" : 0,
         "dwTextLineSpace" : 0,
         "dwTransParent" : 0,
         "dwUseType" : 0,
         "emRollMode" : 0,
         "emRollSpeed" : 0,
         "emTextAlign" : 0,
         "tBannerCoordinate" : {
            "X" : 0,
            "Y" : 0
         },
		"dwTextLineNum" : 1
      }
   ]
}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetMtcBannerInfoCfg_Ntf,

	/**	
	@brief    mtc横幅配置  
	
	MainBuf(#THDMTBannerInfoList_Api, tHDMTBannerInfoList)

	@verbatim
	{
   "atMtBannerInfoList" : [
      {
         "achBkColor" : "",
         "achPictureName" : "",
         "achPresetBannerName" : "",
         "atBannerContext" : [
            {
               "achFacenametype" : "",
               "achTextContent" : "",
               "achTextcolor" : "",
               "achTextsize" : "",
               "bTextBold" : false,
               "bTextItalic" : false,
               "bTextUnderline" : false
            }
         ],
         "bEnable" : false,
         "dwDisplayHeight" : 0,
         "dwDisplayWidth" : 0,
         "dwPresetBannerIndex" : 0,
         "dwRollNum" : 0,
         "dwStayTime" : 0,
         "dwTextDisplayRatio" : 0,
         "dwTextLineSpace" : 0,
         "dwTransParent" : 0,
         "dwUseType" : 0,
         "emRollMode" : 0,
         "emRollSpeed" : 0,
         "emTextAlign" : 0,
         "tBannerCoordinate" : {
            "X" : 0,
            "Y" : 0
         },
		"dwTextLineNum" : 1
      }
   ]
   }
   @endverbatim
   */
	Ev_MtApi_Base_Hd_GetMtcBannerInfoCfg_Rsp,

	/**	
	@brief    Ev_MT_BLL_HD_SetLabelInfoCfg_Ntf    台标配置
	
	MainBuf(#THDMTLabelInfo_Api, tHDMTLabelInfo)

	@verbatim
	{
		"emLabelType" : 1,
		"tLableCoordinate" : 
		{
			"X" : 1,
			"Y" : 2
		},
		"emLabelPosType" : 3,
		"atCustomLabelContent" : [
		{
			"achFacenametype" : "",
			"achTextcolor" : "",
			"achTextsize" : "",
			"bTextBold" : false,
			"bTextItalic" : false,
			"bTextUnderline" : false,
            "achTextContent" : "",
            "bIsWrap" : false
		}
		],
		"achPicName" : ""
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetLabelInfoCfg_Ntf,

	/**	
	@brief    Ev_MT_BLL_HD_GetLabelInfoCfg_Rsp 台标配置
	
	MainBuf(#THDMTLabelInfo_Api, tHDMTLabelInfo)

	@verbatim
	{
		"emLabelType" : 1,
		"tLableCoordinate" : 
		{
			"X" : 1,
			"Y" : 2
		},
		"emLabelPosType" : 3,
		"atCustomLabelContent" : [
		{
			"achFacenametype" : "",
			"achTextcolor" : "",
			"achTextsize" : "",
			"bTextBold" : false,
			"bTextItalic" : false,
			"bTextUnderline" : false,
            "achTextContent" : "",
            "bIsWrap" : false
		}
		],
		"achPicName" : ""
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetLabelInfoCfg_Rsp,

	/**	
	@brief    Ev_MT_BLL_HD_SetAutoSleepCfg_Ntf   自动待机
	
	MainBuf(#THDMTAutoSleep_Api, tHDMTAutoSleep)

	@verbatim
	{
		"bEnable"  : 1,
		"dwTimeOut" : 2,
		"bAllowCall" : 3
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetAutoSleepCfg_Ntf,

	/**	
	@brief    Ev_MT_BLL_HD_GetAutoSleepCfg_Rsp   自动待机
	
	MainBuf(#THDMTAutoSleep_Api, tHDMTAutoSleep)

	@verbatim
	{
		"bEnable"  : 1,
		"dwTimeOut" : 2,
		"bAllowCall" : 3
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetAutoSleepCfg_Rsp,

	/**	
	@brief    时间设置通知 对应Ev_MT_BLL_HD_SetSysTimeCfg_Ntf
	
	MainBuf(#THDMTCfgSystemTime_Api, tHDMTCfgSystemTime)

	@verbatim
	{
	    "bSyncServer" : true,			
	    "emTimeZoneType" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetSysTimeCfg_Ntf,

	/**	
	@brief    获取时间设置响应 对应Ev_MT_BLL_HD_GetSysTimeCfg_Rsp
	
	MainBuf(#THDMTCfgSystemTime_Api, tHDMTCfgSystemTime)

	@verbatim
	{
	    "bSyncServer" : true,			
	    "emTimeZoneType" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetSysTimeCfg_Rsp,

	/***********管理员设置**********/
	
	/**	
	@brief    麦克增益，对应于Ev_MT_BLL_HD_SetMicGainCfg_Ntf
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetMicGainCfg_Ntf,
	
	/**	
	@brief    麦克增益，对应于Ev_MT_BLL_HD_GetMicGainCfg_Rsp
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_GetMicGainCfg_Rsp,
	
	/**	
	@brief    回声抵消自适应，对应于Ev_MT_BLL_HD_SetAecDebugCfg_Ntf	
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetAecDebugCfg_Ntf,
	
	/**	
	@brief    回声抵消自适应，对应于Ev_MT_BLL_HD_GetAecDebugCfg_Rsp
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetAecDebugCfg_Rsp,

	/**	
	@brief    Ev_MT_BLL_HD_SetAudInPortListCfg_Ntf     主音频输入接口
	
	MainBuf(#TMTHDAudInPortList_Api, tMTHDAudInPortList)

	@verbatim
	{
		"tPriMicPortList" :
		{
			"aemAudInPortList" :
			[
				{
					"basetype" : 0
				}
			]
		},
		"tLineInPortList" :
		{
			"aemAudInPortList" :
			[
				{
					"basetype" : 0
				}
			]
		},
		"bIsAuxMic" : false,
		"bIsLineMic" : false
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetAudInPortListCfg_Ntf,

	/**	
	@brief    Ev_MT_BLL_HD_GetAudInPortListCfg_Rsp    主音频输入接口
	
	MainBuf(#TMTHDAudInPortList_Api, tMTHDAudInPortList)

	@verbatim
	{
		"tPriMicPortList" :
		{
			"aemAudInPortList" :
			[
				{
					"basetype" : 0
				}
			]
		},
		"tLineInPortList" :
		{
			"aemAudInPortList" :
			[
				{
					"basetype" : 0
				}
			]
		},
		"bIsAuxMic" : false,
		"bIsLineMic" : false
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetAudInPortListCfg_Rsp,

	/**	
	@brief    音频输出接口通知,Ev_MT_BLL_HD_SetAudOutPortListCfg_Ntf
	
	MainBuf(#THDMTHDAudOutPortList_Api, tHDMTHDAudOutPortList)

	@verbatim
	{
		"byCnt" : 0,
		"aemAudOutPortList" :
		[
			0,
			0
		]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetAudOutPortListCfg_Ntf,

	/**	
	@brief    获取音频输出接口响应,Ev_MT_BLL_HD_GetAudOutPortListCfg_Rsp
	
	MainBuf(#THDMTHDAudOutPortList_Api, tHDMTHDAudOutPortList)

	@verbatim
	{
		"byCnt" : 0,
		"aemAudOutPortList" :
		[
			0,
			0
		]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetAudOutPortListCfg_Rsp,

	/**	
	@brief    设置第一路主视频输入端口(value: THDMTHDVidInPort_Api ),Ev_MT_BLL_HD_SetPri1stVidInPortCfg_Ntf
	
	MainBuf(#THDMTHDVidInPort_Api ,tCfg_Api)

	@verbatim
	{
	    "emVideoType" : 1,
	    "emVideoInPort" : 2
	}
	@endverbatim
	*/	               
	Ev_MtApi_Base_Hd_SetPri1stVidInPortCfg_Ntf,

	/**	
	@brief    获取第一路主视频输入端口请求响应(value: THDMTHDVidInPort_Api ),Ev_MT_BLL_HD_GetPri1stVidInPortCfg_Rsp   
	
	MainBuf(#THDMTHDVidInPort_Api ,tPri1stVidInPortList)

	@verbatim
	{
	    "emVideoType" : 1,
	    "emVideoInPort" : 2
	}
	@endverbatim
	*/	           
	Ev_MtApi_Base_Hd_GetPri1stVidInPortCfg_Rsp,

	/**	
	@brief    设置第二路主视频输入端口端口(value: THDMTHDVidInPort_Api ),Ev_MT_BLL_HD_SetPri2ndVidInPortCfg_Ntf       
	
	MainBuf(#THDMTHDVidInPort_Api, tCfg_Api)

	@verbatim
	{
	    "emVideoType" : 1,
	    "emVideoInPort" : 2
	}
	@endverbatim
	*/		            
	Ev_MtApi_Base_Hd_SetPri2ndVidInPortCfg_Ntf,

	/**	
	@brief    获取第二路主视频输入端口端口响应(value: THDMTHDVidInPort_Api ),Ev_MT_BLL_HD_GetPri2ndVidInPortCfg_Rsp    
	
	MainBuf(#THDMTHDVidInPort_Api, tPri2ndVidInPortList)

	@verbatim
	{
	    "emVideoType" : 1,
	    "emVideoInPort" : 2
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_GetPri2ndVidInPortCfg_Rsp,

	/**	
	@brief    设置辅视频输入端口通知(value: THDMTHDVidInPort_Api ),Ev_MT_BLL_HD_SetAssVidInPortCfg_Ntf     
	
	MainBuf(#THDMTHDVidInPort_Api ,tCfg_Api)

	@verbatim
	{
	    "emVideoType" : 1,
	    "emVideoInPort" : 2
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_SetAssVidInPortCfg_Ntf,

	/**	
	@brief    获取辅视频输入端口响应(value: THDMTHDVidInPort_Api ),Ev_MT_BLL_HD_GetAssVidInPortCfg_Rsp    
	
	MainBuf(#THDMTHDVidInPort_Api, tAssVidInPortList)

	@verbatim
	{
	    "emVideoType" : 1,
	    "emVideoInPort" : 2
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_Hd_GetAssVidInPortCfg_Rsp,

	/**	    
	@brief    设置多视或多流通知,Ev_MT_BLL_HD_SetMultiVideoCfg_Ntf
	
	MainBuf(#TMTHDMultiVideo_Api, tMTHDMultiVideo)

	@verbatim
	{
		"byCnt" : 0,
		"emMVType" : 1,
		"emVMPType" : 2,
		"aemVideoInPortList" :
		[
		    0,
			0
		]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetMultiVideoCfg_Ntf,

	/**		
	@brief    设置多视或多流响应,Ev_MT_BLL_HD_GetMultiVideoCfg_Rsp
	
	MainBuf(#TMTHDMultiVideo_Api, tMTHDMultiVideo)

	@verbatim
	{
		"byCnt" : 0,
		"emMVType" : 1,
		"emVMPType" : 2,
		"aemVideoInPortList" :
		[
		    0,
			0
		]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetMultiVideoCfg_Rsp,

	/**		
	@brief    主视频第一路显示比率,Ev_MT_BLL_HD_SetMainFstDisplayRatioCfg_Ntf
	
	MainBuf(#THDMTDisplayRatio_Api, tHDMTDisplayRatio)

	@verbatim
	{
		"emVideoType" : 1,
		"emRatio" : 2
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetMainFstDisplayRatioCfg_Ntf,

	/**		
	@brief    设置解码后加黑边、裁边与非等比的视频处理策略
	
	MainBuf(#TMTResizeMode_Api)

	@verbatim
	{
		"emResizeMode" : 1
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetResizeModeCfg_Ntf,

	/**		
	@brief    设置解码后加黑边、裁边与非等比的视频处理策略
	
	MainBuf(#TMTResizeMode_Api)

	@verbatim
	{
		"emResizeMode" : 1
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetResizeModeCfg_Rsp,

	/**	
	@brief    主视频第一路显示比率,Ev_MT_BLL_HD_GetMainFstDisplayRatioCfg_Rsp
	
	MainBuf(#THDMTDisplayRatio_Api, tHDMTDisplayRatio)

	@verbatim
	{
		"emVideoType" : 1,
		"emRatio" : 2
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetMainFstDisplayRatioCfg_Rsp,

	/**	   
	@brief    主视频第二路显示比率,Ev_MT_BLL_HD_SetMainSecDisplayRatioCfg_Ntf
	
	MainBuf(#THDMTDisplayRatio_Api, tHDMTDisplayRatio)

	@verbatim
	{
		"emVideoType" : 1,
		"emRatio" : 2
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetMainSecDisplayRatioCfg_Ntf,

	/**	  
	@brief    主视频第二路显示比率,Ev_MT_BLL_HD_GetMainSecDisplayRatioCfg_Rsp
	
	MainBuf(#THDMTDisplayRatio_Api, tHDMTDisplayRatio)

	@verbatim
	{
		"emVideoType" : 1,
		"emRatio" : 2
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetMainSecDisplayRatioCfg_Rsp,

	/**	 
	@brief    辅视频显示比率,Ev_MT_BLL_HD_SetAssDisplayRatioCfg_Ntf
	
	MainBuf(#THDMTDisplayRatio_Api, tHDMTDisplayRatio)

	@verbatim
	{
		"emVideoType" : 1,
		"emRatio" : 2
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetAssDisplayRatioCfg_Ntf,

	/**	  
	@brief    辅视频显示比率,Ev_MT_BLL_HD_GetAssDisplayRatioCfg_Rsp
	
	MainBuf(#THDMTDisplayRatio_Api, tHDMTDisplayRatio)

	@verbatim
	{
		"emVideoType" : 1,
		"emRatio" : 2
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetAssDisplayRatioCfg_Rsp,

	/**	  
	@brief    视频矩阵,Ev_MT_BLL_HD_SetVideoMatrixSchemeCfg_Ntf
	
	MainBuf(#THDMTAllVideoMatrixScheme_Api, tHDMTAllVideoMatrixScheme)

	@verbatim
	{
		"byCnt" : 1,
	    "dwSchemeID" : 1,
		"atMatrixScheme" :
		[
		   {
			    "dwSchemeID" : 0,
			    "achSchemeName" : 0,
			    "byInPortCnt" : 0,
			    "atInPortMode" :
			     [
			        {
			           "emVideoInPort": 0,
			           "emInPortMode" : 0
			        }
			      ],
			     "byOutPortCnt" : 0,
			     "atOutPortMode" :
			     [
			       {
			          "emVideoOutPort": 0,
			          "emOutPortMode" : 0
			       }
			     ],
			     "byOutPort2InPortCnt" : 0,
			     "atOutPort2InPort" :
			     [
			       {
			         "emVideoOutPort" : 0,
			          "emVideoOutType" : 0
			       }
			     ]
		    }
		]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetVideoMatrixSchemeCfg_Ntf,

	/**    
	@brief    视频矩阵,Ev_MT_BLL_HD_GetVideoMatrixSchemeCfg_Rsp
	
	MainBuf(#THDMTAllVideoMatrixScheme_Api, tHDMTAllVideoMatrixScheme)

	@verbatim
	{
		"byCnt" : 1,
	    "dwSchemeID" : 1,
		"atMatrixScheme" :
		[
		   {
			    "dwSchemeID" : 0,
			    "achSchemeName" : 0,
			    "byInPortCnt" : 0,
			    "atInPortMode" :
			     [
			        {
			           "emVideoInPort": 0,
			           "emInPortMode" : 0
			        }
			      ],
			     "byOutPortCnt" : 0,
			     "atOutPortMode" :
			     [
			       {
			          "emVideoOutPort": 0,
			          "emOutPortMode" : 0
			       }
			     ],
			     "byOutPort2InPortCnt" : 0,
			     "atOutPort2InPort" :
			     [
			       {
			         "emVideoOutPort" : 0,
			          "emVideoOutType" : 0
			       }
			     ]
		    }
		]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetVideoMatrixSchemeCfg_Rsp,

	/**	  
	@brief   无图像显示策略,Ev_MT_BLL_HD_SetLastDisplayCfg_Ntf  
	
	MainBuf(#THDMTLastDisplay_Api, tCfg_Api)

	@verbatim
	{
     	"emLastDisplayType" : 1,
    	"dwWaitTimer" : 2
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_SetLastDisplayCfg_Ntf,

	/**	  
	@brief   获取无图像显示策略响应,Ev_MT_BLL_HD_GetLastDisplayCfg_Rsp    
	
	MainBuf(#THDMTLastDisplay_Api, tLastDisplay)

	@verbatim
	{
	    "emLastDisplayType" : 1,
	    "dwWaitTimer" : 2
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_GetLastDisplayCfg_Rsp,

	/**	  
	@brief   图像降噪等级通知,Ev_MT_BLL_HD_SetImageNoiseLevelCfg_Ntf   
	
	MainBuf(#THDMTImageNoise_Api ,tCfg_Api)

	@verbatim
	{
	    "emNoiseLevel" : 1
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_SetImageNoiseLevelCfg_Ntf,

	/**	  
	@brief   获取图像降噪等级响应,Ev_MT_BLL_HD_GetImageNoiseLevelCfg_Rsp      
	
	MainBuf(#THDMTImageNoise_Api， tImageNoise)

	@verbatim
	{
	    "emNoiseLevel" : 1
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_GetImageNoiseLevelCfg_Rsp,

	/**
	@brief 图像增强开关，对应于Ev_MT_BLL_HD_SetImageEnhancementCfg_Ntf
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		"bUse": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetImageEnhancementCfg_Ntf,

	/**
	@brief 图像增强开关，对应于Ev_MT_BLL_HD_GetImageEnhancementCfg_Rsp
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		"bUse": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetImageEnhancementCfg_Rsp,

	/**
	@brief   设置第一路主视频变形拉伸通知，对应于Ev_MT_BLL_HD_SetPri1stDeformationTensileCfg_Ntf
	
	MainBuf(#TMTHDImageDeformationTensile_Api, tCfg_Api)

	@verbatim
	{
	    "emCodecType" : 1,  
	    "emCodecIndex" : 2,
	    "dwHoriNum" : 3,
	    "dwVertiNum" : 4
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_SetPri1stDeformationTensileCfg_Ntf,

	/**
	@brief  获取第一路主视频变形拉伸响应，对应于Ev_MT_BLL_HD_GetPri1stDeformationTensileCfg_Rsp
	
	MainBuf(#TMTHDImageDeformationTensile_Api ,tPri1stImageDefTens)

	@verbatim
	{
	    "emCodecType" : 1,  
	    "emCodecIndex" : 2,
	    "dwHoriNum" : 3,
	    "dwVertiNum" : 4
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_GetPri1stDeformationTensileCfg_Rsp,

	/**
	@brief  	设置第二路主视频变形拉伸通知，对应于Ev_MT_BLL_HD_SetPri2ndDeformationTensileCfg_Ntf
	
	MainBuf(#TMTHDImageDeformationTensile_Api ,tCfg_Api)

	@verbatim
	{
	    "emCodecType" : 1,  
	    "emCodecIndex" : 2,
	    "dwHoriNum" : 3,
	    "dwVertiNum" : 4
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetPri2ndDeformationTensileCfg_Ntf,

	/**
	@brief  	获取第二路主视频变形拉伸响应，对应于Ev_MT_BLL_HD_GetPri2ndDeformationTensileCfg_Rsp
	
	MainBuf(#TMTHDImageDeformationTensile_Api, tPri2ndImageDefTens)

	@verbatim
	{
	    "emCodecType" : 1,  
	    "emCodecIndex" : 2,
	    "dwHoriNum" : 3,
	    "dwVertiNum" : 4
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_GetPri2ndDeformationTensileCfg_Rsp,

	/**
	@brief  	设置辅视频变形拉伸通知，对应于Ev_MT_BLL_HD_SetAssDeformationTensileCfg_Ntf  
	
	MainBuf(#TMTHDImageDeformationTensile_Api ,tCfg_Api)

	@verbatim
	{
	    "emCodecType" : 1,  
	    "emCodecIndex" : 2,
	    "dwHoriNum" : 3,
	    "dwVertiNum" : 4
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_SetAssDeformationTensileCfg_Ntf,

	/**
	@brief  	获取辅视频变形拉伸响应，对应于Ev_MT_BLL_HD_GetAssDeformationTensileCfg_Rsp   
	
	MainBuf(#TMTHDImageDeformationTensile_Api, tAssImageDefTens)

	@verbatim
	{
	    "emCodecType" : 1,  
	    "emCodecIndex" : 2,
	    "dwHoriNum" : 3,
	    "dwVertiNum" : 4
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_GetAssDeformationTensileCfg_Rsp,

	/**
	@brief  	设置第一路主视频等比缩放通知，对应于Ev_MT_BLL_HD_SetPri1stGeometricScalingCfg_Ntf
	
	MainBuf(#TMTHDImageGeometricScaling_Api, tPri1stImageGeoScale)

	@verbatim
	{
	    "emCodecType" : 1,
	    "emCodecIndex" : 2,
	    "dwNumber" : 3
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_SetPri1stGeometricScalingCfg_Ntf,

	/**
	@brief  	获取第一路主视频等比缩放响应，对应于Ev_MT_BLL_HD_GetPri1stGeometricScalingCfg_Rsp 
	
	MainBuf(#TMTHDImageGeometricScaling_Api, tPri1stImageGeoScale)

	@verbatim
	{
	    "emCodecType" : 1,
	    "emCodecIndex" : 2,
	    "dwNumber" : 3
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_GetPri1stGeometricScalingCfg_Rsp,

	/**
	@brief  	设置第二路主视频等比缩放通知，对应于Ev_MT_BLL_HD_SetPri2ndGeometricScalingCfg_Ntf 
	
	MainBuf(#TMTHDImageGeometricScaling_Api ,tCfg_Api)

	@verbatim
	{
	    "emCodecType" : 1,
	    "emCodecIndex" : 2,
	    "dwNumber" : 3
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_SetPri2ndGeometricScalingCfg_Ntf,

	/**
	@brief  	获取第二路主视频等比缩放响应，对应于Ev_MT_BLL_HD_GetPri2ndGeometricScalingCfg_Rsp
	
	MainBuf(#TMTHDImageGeometricScaling_Api ,tPri2ndImageGeoScale)

	@verbatim
	{
	    "emCodecType" : 1,
	    "emCodecIndex" : 2,
	    "dwNumber" : 3
	}
	@endverbatim
	*/	           
	Ev_MtApi_Base_Hd_GetPri2ndGeometricScalingCfg_Rsp,

	/**
	@brief  	设置辅视频等比缩放，对应于Ev_MT_BLL_HD_SetAssGeometricScalingCfg_Ntf  
	
	MainBuf(#TMTHDImageGeometricScaling_Api ,tCfg_Api)

	@verbatim
	{
	    "emCodecType" : 1,
	    "emCodecIndex" : 2,
	    "dwNumber" : 3
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_SetAssGeometricScalingCfg_Ntf,

	/**
	@brief  	获取辅视频等比缩放响应，对应于Ev_MT_BLL_HD_GetAssGeometricScalingCfg_Rsp   
	
	MainBuf(#TMTHDImageGeometricScaling_Api, tAssImageGeoScale)

	@verbatim
	{
	    "emCodecType" : 1,
	    "emCodecIndex" : 2,
	    "dwNumber" : 3
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_GetAssGeometricScalingCfg_Rsp,
	
	/**
	@brief 设置第一路主视频裁边像素，对应于Ev_MT_BLL_HD_SetEdgePixelCfg_Ntf
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetEdgePixelCfg_Ntf,
	
	/**
	@brief 设置第一路主视频裁边像素，对应于Ev_MT_BLL_HD_GetEdgePixelCfg_Rsp
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetEdgePixelCfg_Rsp,

	/**
	@brief 设置摄像机配置，对应于Ev_MT_BLL_HD_SetCameraListCfg_Ntf  
	
	MainBuf(#TMTHDCameraList_Api ,tCfg_Api)

	@verbatim
	{
	    "byCnt" : 0, 
	    "atCameralist" : 
	    [
	    {
	        "emVideoPortIndex" : 0,
	        "achCameraTypeName" : 1,
        	"dwAddress" : 2,
         	"dwSpeed" : 3,
        	"emSerialType" : 0
      	}
    	]
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_SetCameraListCfg_Ntf,

	/**
	@brief 获取摄像机配置响应，对应于Ev_MT_BLL_HD_GetCameraListCfg_Rsp    
	
	MainBuf(#TMTHDCameraList_Api, tCameraList)

	@verbatim
	{
	    "byCnt" : 0, 
	    "atCameralist" : 
	    [
	    {
	        "emVideoPortIndex" : 0,
	        "achCameraTypeName" : 1,
	        "dwAddress" : 2,
	        "dwSpeed" : 3,
	        "emSerialType" : 0
	    }
	    ]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetCameraListCfg_Rsp,

	/**
	@brief 设置串口配置通知，对应于Ev_MT_BLL_HD_SetSerialCtrlCfg_Ntf    
	
	MainBuf(#TMTHDSerialCtrl_Api ,tCfg_Api)

	@verbatim
	{
	    "emSerialType" : 1,
	    "dwBandRate" : 2,
	    "dwByteSize" : 3,
	    "emStopBits" : 4,
	    "emParityCheck" : 5
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_SetSerialCtrlCfg_Ntf,

	/**
	@brief 获取串口配置响应，对应于Ev_MT_BLL_HD_GetSerialCtrlCfg_Rsp 
	
	MainBuf(#TMTHDSerialCtrl_Api ,tSerial)

	@verbatim
	{
	    "emSerialType" : 1,
	    "dwBandRate" : 2,
	    "dwByteSize" : 3,
	    "emStopBits" : 4,
	    "emParityCheck" : 5
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_Hd_GetSerialCtrlCfg_Rsp,

	/*********************硬终端产品结束********************/
	
	/**
	@brief 设置数据会议，对应于Ev_MT_BLL_SetDCSCfg_Ntf
	
	MainBuf(#TMtDCSSvrAddr_Api, tMtDCSSvrAddr)

	@verbatim
	{
		"Domain" : "",
		"ip" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetDCSCfg_Ntf,
	
	/**
	@brief  获取数据会议响应，对应于Ev_MT_BLL_GetDCSCfg_Rsp
	
	MainBuf(#TMtDCSSvrAddr_Api, tMtDCSSvrAddr)

	@verbatim
	{
		"Domain" : "",
		"ip" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetDCSCfg_Rsp,
	
	/**
	@brief 设置主视频编码器参数，对应于Ev_MT_BLL_SetPriVidEncParamCfg_Ntf
	
	MainBuf(#TMTAllVideoEncoderParamCfg_Api, tMTAllVideoEncoderParamCfg)

	@verbatim
	{
		"atParamArray" :
		[
			{
				"emCodecIdx": 0,
				"dwH265IKeyInterval": 0,
				"dwH265QualMaxValue": 0,
				"dwH265QualMinValue": 0,
				"dwH264IKeyInterval": 0,
				"dwH264QualMaxValue": 0,
				"dwH264QualMinValue": 0,
				"dwKeyFrameInterval": 0,
				"dwQualMinValue": 0,
				"dwQualMaxValue": 0,
				"dwFrameRate1080p": 0,
				"dwFrameRate720p": 0,
                "dwFrameRateGT720p": 0,
                "dwFrameRateLT720p": 0
			}
		]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetPriVidEncParamCfg_Ntf,
	
	/**
	@brief   获取主视频编码器参数响应，对应于Ev_MT_BLL_GetPriVidEncParamCfg_Rsp
	
	MainBuf(#TMTAllVideoEncoderParamCfg_Api, tMTAllVideoEncoderParamCfg)

	@verbatim
	{
		"atParamArray" :
		[
			{
				"emCodecIdx": 0,
				"dwH265IKeyInterval": 0,
				"dwH265QualMaxValue": 0,
				"dwH265QualMinValue": 0,
				"dwH264IKeyInterval": 0,
				"dwH264QualMaxValue": 0,
				"dwH264QualMinValue": 0,
				"dwKeyFrameInterval": 0,
				"dwQualMinValue": 0,
				"dwQualMaxValue": 0,
				"dwFrameRate1080p": 0,
                "dwFrameRate720p": 0,
                "dwFrameRateGT720p": 0,
                "dwFrameRateLT720p": 0
			}
		]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetPriVidEncParamCfg_Rsp,
	
	/**
	@brief 设置辅视频编码器参数，对应于Ev_MT_BLL_SetAssVidEncParamCfg_Ntf
	
	MainBuf(#TMTAllVideoEncoderParamCfg_Api, tMTAllVideoEncoderParamCfg)

	@verbatim
	{
		"atParamArray" :
		[
			{
					"emCodecIdx": 0,
					"dwH265IKeyInterval": 0,
					"dwH265QualMaxValue": 0,
					"dwH265QualMinValue": 0,
					"dwH264IKeyInterval": 0,
					"dwH264QualMaxValue": 0,
					"dwH264QualMinValue": 0,
					"dwKeyFrameInterval": 0,
					"dwQualMinValue": 0,
					"dwQualMaxValue": 0,
					"dwFrameRate1080p": 0,
                    "dwFrameRate720p": 0,
                    "dwFrameRateGT720p": 0,
                    "dwFrameRateLT720p": 0
			}
		]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetAssVidEncParamCfg_Ntf,
	
	/**
	@brief  获取辅视频编码器参数响应，对应于Ev_MT_BLL_GetAssVidEncParamCfg_Rsp
	
	MainBuf(#TMTAllVideoEncoderParamCfg_Api, tMTAllVideoEncoderParamCfg)

	@verbatim
	{
			"atParamArray" :
			[
				{
					"emCodecIdx": 0,
					"dwH265IKeyInterval": 0,
					"dwH265QualMaxValue": 0,
					"dwH265QualMinValue": 0,
					"dwH264IKeyInterval": 0,
					"dwH264QualMaxValue": 0,
					"dwH264QualMinValue": 0,
					"dwKeyFrameInterval": 0,
					"dwQualMinValue": 0,
					"dwQualMaxValue": 0,
					"dwFrameRate1080p": 0,
                    "dwFrameRate720p": 0,
                    "dwFrameRateGT720p": 0,
                    "dwFrameRateLT720p": 0
				}
			]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetAssVidEncParamCfg_Rsp,
	
	/**	
	@brief    设置视频解码器参数，对应于Ev_MT_BLL_SetVideoDecParamCfg_Ntf
	
	MainBuf(#TMTAllVideoDecoderParamCfg_Api, tMTAllVideoDecoderParamCfg)

	@verbatim
	{
		"atDecodeParam" :
		[
			{
				"emCodecIdx": 0,
				"emLostPackStrategy": 0
			}
		]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetVideoDecParamCfg_Ntf,

	/**	
	@brief    获取视频解码器参数响应，对应于Ev_MT_BLL_GetVideoDecParamCfg_Rsp
	
	MainBuf(#TMTAllVideoDecoderParamCfg_Api, tMTAllVideoDecoderParamCfg)	

	@verbatim
	{
		"atDecodeParam" :
		[
			{
				"emCodecIdx": 0,
				"emLostPackStrategy": 0
			}
		]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetVideoDecParamCfg_Rsp,

	/**	
	@brief    设置会议中是否允许播放动画音效，对应于Ev_MT_BLL_SetPlayAniSoundInIdleCfg_Ntf
	
	MainBuf(#BOOL32, bEnable)

	@verbatim
	{
		"bEnable": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetPlayAniSoundInIdleCfg_Ntf,

	/**	
	@brief    获取会议中是否允许播放动画音效响应，对应于Ev_MT_BLL_GetPlayAniSoundInIdleCfg_Rsp
	
	MainBuf(#BOOL32, bEnable)

	@verbatim
	{
		"bEnable": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetPlayAniSoundInIdleCfg_Rsp,

	/**	
	@brief    设置视频源通知 ，对应于Ev_MT_BLL_SetCodecVideoSrcCfg_Ntf
	
	MainBuf(#TMTCodecVidSrcInfo_Api,tCfg_Api)

	@verbatim
	{
	    "emCodecCpIndex" : 0,
	    "emVidPort" : 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetCodecVideoSrcCfg_Ntf,

	/**	
	@brief    获取视频源响应，对应于Ev_MT_BLL_GetCodecVideoSrcCfg_Rsp
	
	MainBuf(#TMTCodecVidSrcInfo_Api ,tCodVidSrcInfo)

	@verbatim
	{
	    "emCodecCpIndex" : 0,
	    "emVidPort" : 0
	}
	@endverbatim
	*/	                                
	Ev_MtApi_Base_GetCodecVideoSrcCfg_Rsp,

	/**	
	@brief    是否是卫星终端， 从平台获取通知，对应于Ev_MT_BLL_SetIsSatelliteMTRt_Ntf  
	
	MainBuf(#TMTSatelliteFlag_Api, tSateFlag)

	@verbatim
	{
	    "bSatelliteMt" : 1,
	    "bP2PEnable" : 2
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetIsSatelliteMTRt_Ntf,

	/**	
	@brief  是否是卫星终端， 从平台获取响应 ，对应于Ev_MT_BLL_SetIsSatelliteMTRt_Ntf  
	
	MainBuf(#TMTSatelliteFlag_Api, tSateFlag)

	@verbatim
	{
	    "bSatelliteMt" : 1,
	    "bP2PEnable" : 2
	}
	@endverbatim
	*/		                               
	Ev_MtApi_Base_GetIsSatelliteMTRt_Rsp,

	/**	
	@brief  设置主席轮询方案通知 ，对应于Ev_MT_BLL_SetChrmanPollSchemesCfg_Ntf       
	
	MainBuf(#TMTChrmanPollSchemeList_Api, tCfg_Api)

	@verbatim
	{
	    "atPollInfo": [
	    {
	        "achName": "",
	        "tPollInfo": {
	        "emMode": 1,
	        "emStat": 1,
          	"wKeepTime": 12,
	        "arrTMtId": [
	        {
	            "dwMcuId": 192,
	            "dwTerId": 12
	        }
	                   ]
	                      }
	    }
	                  ]
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetChrmanPollSchemesCfg_Ntf,

	/**	
	@brief  设置主席轮询方案响应，对应于Ev_MT_BLL_GetChrmanPollSchemesCfg_Rsp         
	
	MainBuf(#TMtCallLinkSate_Api ,tCallLinkSate)

	@verbatim
	{
	    "atPollInfo": [
	    {
	        "achName": "",
	        "tPollInfo": {
	        "emMode": 1,
	        "emStat": 1,
	        "wKeepTime": 12,
	        "arrTMtId": [
	        {
	            "dwMcuId": 192,
	            "dwTerId": 12
	        }
	                    ]
	                       }
	    }
	                  ]
	}
	@endverbatim
	*/	                         
	Ev_MtApi_Base_GetChrmanPollSchemesCfg_Rsp,

	/**	
	@brief    设置显示会议时间，对应于Ev_MT_BLL_SetShowConfTimeCfg_Ntf
	
	MainBuf(#BOOL32, bShow)

	@verbatim
	{
		"bShow": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetShowConfTimeCfg_Ntf,

	/**	
	@brief    设置显示会议时间，对应于Ev_MT_BLL_GetShowConfTimeCfg_Rsp
	
	MainBuf(#BOOL32, bShow)

	@verbatim
	{
		"bShow": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetShowConfTimeCfg_Rsp,

	/**	
	@brief    设置显示系统时间，对应于Ev_MT_BLL_SetShowSystimeTimeCfg_Ntf
	
	MainBuf(#BOOL32, bShow)

	@verbatim
	{
		"bShow": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetShowSystimeTimeCfg_Ntf,

	/**	
	@brief    设置显示系统时间，对应于Ev_MT_BLL_GetShowSystimeTimeCfg_Rsp
	
	MainBuf(#BOOL32, bShow)

	@verbatim
	{
		"bShow": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetShowSystimeTimeCfg_Rsp,

	/**	
	@brief    设置会议中是否显示短消息，对应于Ev_MT_BLL_SetShowShortMsgInConfCfg_Ntf
	
	MainBuf(#BOOL32, bShow)

	@verbatim
	{
		"bShow": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetShowShortMsgInConfCfg_Ntf,

	/**	
	@brief    设置会议中是否显示短消息，对应于Ev_MT_BLL_GetShowShortMsgInConfCfg_Rsp
	
	MainBuf(#BOOL32, bShow)

	@verbatim
	{
		"bShow": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetShowShortMsgInConfCfg_Rsp,

	/**	
	@brief    设置是否显示申请提示，对应于Ev_MT_BLL_SetShowAppTipsCfg_Ntf
	
	MainBuf(#BOOL32, bShow)

	@verbatim
	{
		"bShow": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetShowAppTipsCfg_Ntf,

	/**	
	@brief    设置是否显示申请提示，对应于Ev_MT_BLL_GetShowAppTipsCfg_Rsp
	
	MainBuf(#BOOL32, bShow)

	@verbatim
	{
		"bShow": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetShowAppTipsCfg_Rsp,

	/**	
	@brief    设置是否允许远遥，对应于Ev_MT_BLL_GetFECCCfg_Ntf
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		"bUse": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetFECCCfg_Ntf,

	/**	
	@brief    设置是否允许远遥，对应于Ev_MT_BLL_GetFECCCfg_Rsp
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		"bUse": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetFECCCfg_Rsp,

	/**	
	@brief    设置邮箱，对应于Ev_MT_BLL_SetEmailCfg_Ntf
	
	MainBuf(#u8[], achEmail)

	@verbatim
	{
		"basetype": ""
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetEmailCfg_Ntf,
	
	/**	
	@brief    获取邮箱响应，对应于Ev_MT_BLL_GetEmailCfg_Rsp
	
	MainBuf(#u8[], achEmail)

	@verbatim
	{
		"basetype": ""
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetEmailCfg_Rsp,

	/**	
	@brief    设置是否启用H.264 SVC，对应于Ev_MT_BLL_GetH264SvcCfg_Ntf
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		"bUse": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetH264SvcCfg_Ntf,

	/**	
	@brief    设置是否启用H.264 SVC，对应于Ev_MT_BLL_GetH264SvcCfg_Rsp
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		"bUse": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetH264SvcCfg_Rsp,

	/**	
	@brief    设置视频载荷自适应，对应于Ev_MT_BLL_SetLoadAdaptiveVideoCfg_Ntf
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		"bUse": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetLoadAdaptiveVideoCfg_Ntf,

	/**	
	@brief    设置视频载荷自适应，对应于Ev_MT_BLL_GetLoadAdaptiveVideoCfg_Rsp
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		"bUse": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetLoadAdaptiveVideoCfg_Rsp,

	/**	
	@brief   设置内置mc辅流参数设通知，对应于Ev_MT_BLL_SetInnerMcAssVidCfgCfg_Ntf
	
	MainBuf(#TMTInnerMcAssVidCfg_Api ,tInnerMcAssVidCfg)

	@verbatim
	{
	    "emAssVideoFormat" : 0,
	    "emAssVideoRes" : 0,
	    "dwAssVideoFramerate" : 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetInnerMcAssVidCfgCfg_Ntf,

	/**	
	@brief   获取内置mc辅流参数设置请求响应 ，对应于Ev_MT_BLL_GetInnerMcAssVidCfgCfg_Rsp  
	
	MainBuf(#TMTInnerMcAssVidCfg_Api ,tInnerMcAssVidCfg)

	@verbatim
	{
	    "emAssVideoFormat" : 0,
	    "emAssVideoRes" : 0,
	    "dwAssVideoFramerate" : 0
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetInnerMcAssVidCfgCfg_Rsp,

	/**	
	@brief    协议栈是否标准的，对应于Ev_MT_BLL_SetIsH323StackStandRt_Ntf
	
	MainBuf(#BOOL32, bStandard)

	@verbatim
	{
	    "bStandard": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetIsH323StackStandRt_Ntf,

	/**	
	@brief    协议栈是否标准的，对应于Ev_MT_BLL_GetIsH323StackStandRt_Rsp
	
	MainBuf(#BOOL32, bStandard)

	@verbatim
	{
		"bStandard": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetIsH323StackStandRt_Rsp,
	
	/**	
	@brief    播放呼入铃声，对应于Ev_MT_BLL_HD_SetCallInRingRt_Ntf
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetCallInRingRt_Ntf,
	
	/**	
	@brief    播放呼入铃声，对应于Ev_MT_BLL_HD_GetCallInRingRt_Rsp
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetCallInRingRt_Rsp,
	
	/**	
	@brief    播放呼出铃声，对应于Ev_MT_BLL_HD_SetCallOutRingRt_Ntf
	
	MainBuf(#u32, dwVal)	

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetCallOutRingRt_Ntf,
	
	/**	
	@brief    播放呼出铃声，对应于Ev_MT_BLL_HD_GetCallOutRingRt_Rsp
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetCallOutRingRt_Rsp,
	
	/**	
	@brief    设置播放按键音，对应于Ev_MT_BLL_HD_SetKeyboardRingCfg_Ntf
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetKeyboardRingCfg_Ntf,
	
	/**	
	@brief    设置播放按键音，对应于Ev_MT_BLL_HD_GetKeyboardRingCfg_Rsp
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetKeyboardRingCfg_Rsp,

	/**	
	@brief    设置VGA图像调节通知，对应于Ev_MT_BLL_HD_SetVGAImageAdjustCfg_Ntf   
	
	MainBuf(#TMTVgaImageAdjustCfg_Api ,tCfg_Api)

	@verbatim
	{
	    "bVga1FilterState" : 0,
    	"dwVga1PhaseClock" : 0,
    	"nVga1ImageOffset" : 0,

    	"bVga2FilterState" : 0,
    	"dwVga2PhaseClock" : 0,
    	"nVga2ImageOffset" : 0
	}
	@endverbatim
	*/	 
	Ev_MtApi_Base_Hd_SetVGAImageAdjustCfg_Ntf,

	/**	
	@brief    获取VGA图像调节响应，对应于Ev_MT_BLL_HD_GetVGAImageAdjustCfg_Rsp    
	
	MainBuf(#TMTVgaImageAdjustCfg_Api, tVGAImageAdjust)

	@verbatim
	{
	    "bVga1FilterState" : 0,
    	"dwVga1PhaseClock" : 0,
    	"nVga1ImageOffset" : 0,

    	"bVga2FilterState" : 0,
    	"dwVga2PhaseClock" : 0,
    	"nVga2ImageOffset" : 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_GetVGAImageAdjustCfg_Rsp,

	/**	
	@brief    设置视频源标签 (value:TMTVideoSrcTagList)emHD_Cfg_VideoSrcTag
	
	MainBuf(#TMTVideoSrcTagList_Api)

	@verbatim
	{
	    "byCnt" : 0,
		"atVidSrcTag" :
		[
			{
				"emVideoPortId" : 0,
				"achVideoPortTag" : ""
			}
		]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetVideoSrcTagCfg_Ntf,

	/**	
	@brief    获取视频源标签 (value:TMTVideoSrcTagList)emHD_Cfg_VideoSrcTag
	
	MainBuf(#TMTVideoSrcTagList_Api)

	@verbatim
	{
	    "byCnt" : 0,
		"atVidSrcTag" :
		[
			{
				"emVideoPortId" : 0,
				"achVideoPortTag" : ""
			}
		]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetVideoSrcTagCfg_Rsp,

	/**	
	@brief    设置快照FTP, Ev_MT_BLL_HD_SetSnapShotFtpCfgCfg_Ntf    
	
	MainBuf(#TMTSnapShotFtpCfg_Api, tCfg_Api)

	@verbatim
	{
	    "bIsEnable" : 1,
	    "dwIpAddr" : 2,
	    "dwPort" : 3,
	    "achUploadPath" : "",
	    "achUserName" : "",
	    "achPassWord" : ""
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetSnapShotFtpCfg_Ntf,

	/**	
	@brief    获取快照FTP请求响应, Ev_MT_BLL_HD_GetSnapShotFtpCfg_Rsp  
	
	MainBuf(#TMTSnapShotFtpCfg_Api, tSnapShotFtpCfg)

	@verbatim
	{
	    "bIsEnable" : 1,
	    "dwIpAddr" : 2,
	    "dwPort" : 3,
	    "achUploadPath" : "",
	    "achUserName" : "",
	    "achPassWord" : ""
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_GetSnapShotFtpCfg_Rsp,

	/**	
	@brief    设置VGA输出亮度 , Ev_MT_BLL_HD_SetVgaOutBrightCfg_Ntf  
	
	MainBuf(#u32 ,dwCfg_Api)

	@verbatim
	{

	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_SetVgaOutBrightCfg_Ntf,  

	/**	
	@brief    获取VGA输出亮度请求响应 ,Ev_MT_BLL_HD_GetVgaOutBrightCfg_Rsp
	
	MainBuf(#u32, dwVgaOutBright)

	@verbatim
	{

	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_GetVgaOutBrightCfg_Rsp, 

	/**	
	@brief    设置VGA输出对比度,Ev_MT_BLL_HD_SetVgaOutContrastCfg_Ntf
	
	MainBuf(#u32 , dwCfg_Api )

	@verbatim
	{

	}
	@endverbatim
	*/		
	Ev_MtApi_Base_Hd_SetVgaOutContrastCfg_Ntf,   

	/**	
	@brief    获取VGA输出对比度请求响应,Ev_MT_BLL_HD_SetVgaOutContrastCfg_Ntf
	
	MainBuf(#u32, dwVgaOutContrast)

	@verbatim
	{

	}
	@endverbatim
	*/		
	Ev_MtApi_Base_Hd_GetVgaOutContrastCfg_Rsp,   

	/**	
	@brief    设置VGA输出饱和度,Ev_MT_BLL_HD_SetVgaOutSaturationCfg_Ntf
	
	MainBuf(#u32, dwVgaOutContrast)

	@verbatim
	{

	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_SetVgaOutSaturationCfg_Ntf,    

    /**	
	@brief    获取VGA输出饱和度请求响应,Ev_MT_BLL_HD_GetVgaOutSaturationCfg_Rsp
	
	MainBuf(#u32 ,dwVgaOutSaturation）

	@verbatim
	{

	}
	@endverbatim
	*/		
	Ev_MtApi_Base_Hd_GetVgaOutSaturationCfg_Rsp,   

	/**	
	@brief     设置视频亮度、对比度、饱和度
	
	MainBuf(#EmCodecComponent_Api) \n
	MainBuf(#EmCodecComponentIndex_Api) \n
	MainBuf(#EmImgParam_Api) \n
	MainBuf(#s32)

	@verbatim
	{
	"codec_type":0,
	"codec_id":0,
	"param_type":0,
	"param_value":0,
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetVidImgParam_Ntf,	

	/**	
	@brief   获取查询视频亮度、对比度、饱和度响应, Ev_MT_BLL_GetVidImgParam_Rsp
	
	MainBuf(EmCodecComponent_Api)
	MainBuf(EmCodecComponentIndex_Api)
	MainBuf(EmImgParam_Api)
	MainBuf(#s32)

	@verbatim
	{
	"codec_type":0,
	"codec_id":0,
	"param_type":0,
	"param_value":0,
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetVidImgParam_Rsp,    

	/**	
	@brief   设置预置位名称设置  , Ev_MT_BLL_HD_SetPresetNameInfoCfg_Ntf    
	
	MainBuf(#TAllMTPreSetNameInfoCfg_Api ,tCfg_Api)

	@verbatim
	{
        "byPri1stPresetCnt" : 0,
	    "atPri1stPresetNameInfo" :
	    [
	    {
	        "dwPresetIndex" : 0,
	        "achPresetName" : "preset"
	    }
	    ],
        "byPri2ndPresetCnt" : 0,
	    "atPri2ndPresetNameInfo" :
	    [
	    {
	        "dwPresetIndex" : 0,
	        "achPresetName" : "preset"
	    }
	    ]
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_SetPresetNameInfoCfg_Ntf,
	
	/**	
	@brief   获取预置位名称设置请求响应 ,Ev_MT_BLL_HD_GetPresetNameInfoCfg_Rsp      
	
	MainBuf(#TAllMTPreSetNameInfoCfg_Api ,tPreSetNameInfoList)

	@verbatim
	{
        "byPri1stPresetCnt" : 0,
	    "atPri1stPresetNameInfo" :
	    [
	    {
	        "dwPresetIndex" : 0,
	        "achPresetName" : "preset"
	    }
	    ],
        "byPri2ndPresetCnt" : 0,
	    "atPri2ndPresetNameInfo" :
	    [
	    {
	        "dwPresetIndex" : 0,
	        "achPresetName" : "preset"
	    }
	    ]
	}
	@endverbatim
	*/	                              
	Ev_MtApi_Base_Hd_GetPresetNameInfoCfg_Rsp,

	/**	
	@brief  修改登录密码响应 ,Ev_MT_BLL_RestUpdatePassword_Rsp       
	
	MainBuf(#TRestErrorInfo_Api ,tErrInfo)

	@verbatim
	{
	    "achErrorInfo": "",
	    "emApiType": 0,
	    "dwErrorID": 0,
	    "dwNackEventId": 0,
        "dwParamCount":0,
    	"adwParams":
    	 [
	     {
	     "basetype" : 0
	     }
	     ]
	}
	@endverbatim
	*/	 	
	Ev_MtApi_Base_RestUpdatePassword_Rsp,

	/**	
	@brief    APS登陆结果响应Ev_MT_BLL_ApsLoginResult_Ntf
	
	MainBuf(#TMtApsLoginErrcode_Api, tMtApsLoginErrcode)
    SubBuf(#TPlatformInfo_Api, tPlf)

    @verbatim
    {
        "MainParam":
        {
            "bSucess": true,
            "dwHttpErrcode": 0,
            "dwApsErroce": 0
                        0,         //登陆成功
                        1,         //未知错误

                        10000,     //平台拒绝登录
                        21000,     //连接失败
                        22000,     //登陆参数错误
                        22001,     //用户不存在
                        22002,     //用户密码错误
                        22003,     //设备类型限制
                        22004,     //记录不存在
                        22005,     //分配服务器错误
                        22006,     //没有漫游权限
                        22007,     //用户名或密码错误
                        23001,     //服务器内部错误
                        23002,     //数据库执行失败
                        23003,     //已经切换aps，重新登陆
                        23004,     //已经切换gk，重新登陆

                        60000,     //没有登陆自建平台的权限
        },
        "AssParam": 
        {
            "achVersion": string //平台版本号
            "dwIP" : u32         //登陆IP
            "emResourceType": EmResourceType_Api
        }
    }
	*/
	Ev_MtApi_Base_ApsLoginResult_Ntf,

	/**	
	@brief    设置路由配置信息,Ev_MT_BLL_HD_SetRouteCfgListCfg_Ntf   
	
	MainBuf(#TRouteItemInfoList_Api ,tCfg_Api)

	@verbatim
	{
	    "atRouteList": [
	    {
	        "dwInterface": 0,
	        "dwDstNetwork": 0,
        	"dwDstNetMask": 0,
	        "dwGateway": 0,
	        "dwPriority": 0
	    }
	                    ]
	}
	@endverbatim
	*/	
	Ev_Mtapi_Base_Hd_SetRouteCfgListCfg_Ntf,

	/**	
	@brief    获取路由配置信息响应,Ev_MT_BLL_HD_GetRouteCfgListCfg_Rsp   
	
	MainBuf(#TRouteItemInfoList_Api ,tRouteItemInfoList)

	@verbatim
	{
	    "atRouteList": [
	    {
	        "dwInterface": 0,
	        "dwDstNetwork": 0,
        	"dwDstNetMask": 0,
	        "dwGateway": 0,
	        "dwPriority": 0
	    }
	                    ]
	}
	@endverbatim
	*/		
	Ev_Mtapi_Base_Hd_GetRouteCfgListCfg_Rsp,

	/**	
	@brief    设置以太网工作模式,Ev_MT_BLL_HD_SetEthWorkModeListCfg_Ntf  
	
	MainBuf(#TEthnetWorkModeList_Api ,tCfg_Api)

	@verbatim
	{
	    "emCard1Workmode": 1,
	    "emCard2Workmode": 2
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_SetEthWorkModeListCfg_Ntf,

	/**	
	@brief    获取以太网工作模式响应,Ev_MT_BLL_HD_GetEthWorkModeListCfg_Rsp  
	
	MainBuf(#TEthnetWorkModeList_Api ,tEthWorkModeList)

	@verbatim
	{
	    "emCard1Workmode": 1,
	    "emCard2Workmode": 2
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetEthWorkModeListCfg_Rsp,

	/**	
	@brief    设置以太网信息,Ev_MT_BLL_HD_SetEthnetCfgCfg_Ntf 
	
	MainBuf(#TEthnetCfg_Api, tCfg_Api)

	@verbatim
	{
		"emEthBackupMD": 0,
		"dwCurCardId": 0,
		"tEth1": {
				"bEnableIpDhcp": true,
				"dwStaticIp": 0,
				"dwStaticMask": 0,
				"dwStaticGW": 0,
				"dwDhcpIp": 0,
				"dwDhcpMask": 0,
				"dwDhcpGW": 0,
				"bEnableDnsDhcp": true,
				"dwStaticDns": 0,
				"dwStaticDnsBackup": 0,
				"dwDhcpDns": 0,
				"dwDhcpDnsBackup": 0
		},
		"tEth2": {
			"bEnableIpDhcp": true,
			"dwStaticIp": 0,
			"dwStaticMask": 0,
			"dwStaticGW": 0,
			"dwDhcpIp": 0,
			"dwDhcpMask": 0,
			"dwDhcpGW": 0,
			"bEnableDnsDhcp": true,
			"dwStaticDns": 0,
			"dwStaticDnsBackup": 0,
			"dwDhcpDns": 0,
			"dwDhcpDnsBackup": 0
				}
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetEthnetCfgCfg_Ntf,

	/**	
	@brief    获取以太网信息请求响应,Ev_MT_BLL_HD_GetEthnetCfgCfg_Rsp
	
	MainBuf(#TEthnetCfg_Api ,tEthCfg)

	@verbatim
	{
		"emEthBackupMD": 0,
		"dwCurCardId": 0,
		"tEth1": {
				"bEnableIpDhcp": true,
				"dwStaticIp": 0,
				"dwStaticMask": 0,
				"dwStaticGW": 0,
				"dwDhcpIp": 0,
				"dwDhcpMask": 0,
				"dwDhcpGW": 0,
				"bEnableDnsDhcp": true,
				"dwStaticDns": 0,
				"dwStaticDnsBackup": 0,
				"dwDhcpDns": 0,
				"dwDhcpDnsBackup": 0
		},
		"tEth2": {
			"bEnableIpDhcp": true,
			"dwStaticIp": 0,
			"dwStaticMask": 0,
			"dwStaticGW": 0,
			"dwDhcpIp": 0,
			"dwDhcpMask": 0,
			"dwDhcpGW": 0,
			"bEnableDnsDhcp": true,
			"dwStaticDns": 0,
			"dwStaticDnsBackup": 0,
			"dwDhcpDns": 0,
			"dwDhcpDnsBackup": 0
				}
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_GetEthnetCfgCfg_Rsp,

	/**	
	@brief   设置PPPoE拨号信息,Ev_MT_BLL_HD_GetEthWorkModeListCfg_Rsp  
	
	MainBuf(#TEthnetPPPoECfg_Api ,tCfg_Api)

	@verbatim
	{
	    "bEnable": true,
	    "achUserName": "",
	    "achPassword": "",
	    "bAutoDial": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_SetEthPPPoECfgCfg_Ntf,

	/**	
	@brief   获取PPPoE拨号信息响应,Ev_MT_BLL_HD_GetEthPPPoECfgCfg_Rsp   
	
	MainBuf(#TEthnetPPPoECfg_Api, tEthPPPoeCfg)

	@verbatim
	{
	    "bEnable": true,
	    "achUserName": "",
	    "achPassword": "",
	    "bAutoDial": true
	}
	@endverbatim
	*/	                          
	Ev_MtApi_Base_Hd_GetEthPPPoECfgCfg_Rsp,

	/**	
	@brief   设置Wifi工作模式,Ev_MT_BLL_HD_SetWifiWorkModeCfg_Ntf   
	
	MainBuf(#TWifiWorkMode_Api, tCfg_Api)

	@verbatim
	{
	    "emWifiWKMD": 0,
	    "tWifiApCfg":
    	{
        	"achSsid": "",
        	"emCapabilities": 0,
        	"achKey": "",
        	"dwDhcpStartIp": 0,
        	"dwDhcpEndIp": 0,
        	"dwIp": 0,
        	"dwMask": 0
    	}
	}
	@endverbatim
	*/	                        
	Ev_MtApi_Base_Hd_SetWifiWorkModeCfg_Ntf,

	/**	
	@brief   获取Wifi工作模式请求响应,Ev_MT_BLL_HD_GetWifiWorkModeCfg_Rsp   
	
	MainBuf(#TWifiWorkMode_Api, tWifiWorkMode)

	@verbatim
	{
	    "emWifiWKMD": 0,
	    "tWifiApCfg":
    	{
        	"achSsid": "",
        	"emCapabilities": 0,
        	"achKey": "",
        	"dwDhcpStartIp": 0,
        	"dwDhcpEndIp": 0,
        	"dwIp": 0,
        	"dwMask": 0
    	}
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_GetWifiWorkModeCfg_Rsp,

	/**	
	@brief   设置Wifi-AP配置信息,Ev_MT_BLL_HD_SetWifiApCfgCfg_Ntf  
	
	MainBuf(#TWifiApConfiguration_Api, tCfg_Api)

	@verbatim
	{
	    "achSsid": "",
	    "emCapabilities": 0,
    	"achKey": "",
    	"dwDhcpStartIp": 0,
    	"dwDhcpEndIp": 0,
    	"dwIp": 0,
    	"dwMask": 0
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_Hd_SetWifiApCfgCfg_Ntf,

	/**	
	@brief   获取Wifi-AP配置信息请求响应,Ev_MT_BLL_HD_GetWifiApCfgCfg_Rsp   
	
	MainBuf(#TWifiApConfiguration_Api, tWifiApCfg)

	@verbatim
	{
	    "achSsid": "",
	    "emCapabilities": 0,
    	"achKey": "",
    	"dwDhcpStartIp": 0,
    	"dwDhcpEndIp": 0,
    	"dwIp": 0,
    	"dwMask": 0
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_Hd_GetWifiApCfgCfg_Rsp,

	/**	
	@brief     设置Wifi作为client已连接后的配置信息,Ev_MT_BLL_HD_SetWifiClientCfgCfg_Ntf   
	
	MainBuf(#TWifiConfiguration_Api ,tCfg_Api)

	@verbatim
	{
	    "bEnableAutoConn": true,
	    "bEnableAutoIp": true,
	    "dwIp": 0,
	    "dwMask": 0,
    	"dwGateway": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_SetWifiClientCfgCfg_Ntf,

	/**	
	@brief     获取Wifi作为client已连接后的配置信息请求响应,Ev_MT_BLL_HD_GetWifiClientCfgCfg_Rsp   
	
	MainBuf(#TWifiConfiguration_Api ,tCfg_Api)

	@verbatim
	{
	    "bEnableAutoConn": true,
	    "bEnableAutoIp": true,
	    "dwIp": 0,
	    "dwMask": 0,
    	"dwGateway": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_GetWifiClientCfgCfg_Rsp,

	/**	
	@brief    设置E1的配置信息,Ev_MT_BLL_HD_SetE1CfgCfg_Ntf 
	
	MainBuf(#TE1Cfg_Api ,tCfg_Api)

	@verbatim
	{
	    "bEncrypt" : false,
	    "dwClockType" : 0,
	    "atE1GroupList" : [
	        {
	            "bEnable" : false,
	            "dwUnitNum" : 0,
	            "dwIsBind" : 0,
	            "dwGroupID" : 0,
	            "dwIpAddr" : 0,
             	"dwMask" : 0,
             	"dwAuthType" : 0,
            	"dwFragMinPackageLen" : 20,
            	"achServerUsrName" : "",
            	"achServerUsrPwd" : "",
            	"achClientUsrName" : "",
            	"achClientUsrPwd" : "",
            	"atE1UnitList": [
              	{
                  	"dwE1ID" : 0,
                 	"dwUsedFlag" : 0,
                	"dwE1TSMask" : 0,
                 	"dwProtocolType" : 0,
                	"dwEchoInterval" : 0,
                 	"dwEchoMaxRetry" : 0
              	}
	                            ]
           	}
                        	]
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_HD_SetE1CfgCfg_Ntf,

	/**	
	@brief    获取E1的配置信息请求响应,Ev_MT_BLL_HD_GetE1CfgCfg_Rsp  
	
	MainBuf(#TE1Cfg_Api, tE1Cfg)

	@verbatim
	{
	    "bEncrypt" : false,
	    "dwClockType" : 0,
	    "atE1GroupList" : [
	        {
	            "bEnable" : false,
	            "dwUnitNum" : 0,
	            "dwIsBind" : 0,
	            "dwGroupID" : 0,
	            "dwIpAddr" : 0,
             	"dwMask" : 0,
             	"dwAuthType" : 0,
            	"dwFragMinPackageLen" : 20,
            	"achServerUsrName" : "",
            	"achServerUsrPwd" : "",
            	"achClientUsrName" : "",
            	"achClientUsrPwd" : "",
            	"atE1UnitList": [
              	{
                  	"dwE1ID" : 0,
                 	"dwUsedFlag" : 0,
                	"dwE1TSMask" : 0,
                 	"dwProtocolType" : 0,
                	"dwEchoInterval" : 0,
                 	"dwEchoMaxRetry" : 0
              	}
	                            ]
           	}
                        	]
	}
	@endverbatim
	*/		                                
	Ev_MtApi_Base_HD_GetE1CfgCfg_Rsp,

	/**	
	@brief    设置Wifi作为client连接后的详细信息,Ev_MT_BLL_HD_SetWifiCurConnectedInfoRt_Ntf 
	
	MainBuf(#TWifiCurDetailInfo_Api, tWifiCurDetailInfo)

	@verbatim
	{
	    "emState": 0,
    	"nNetworkId": 0,
    	"achSsid": "",
    	"achBSsid": "",
    	"achMacAddress": "",
    	"dwIp": 0,
    	"dwMask": 0,
    	"dwGateway": 0,
     	"emReason": 0
	}
	@endverbatim
	*/	               
	Ev_MtApi_Base_Hd_SetWifiCurConnectedInfoRt_Ntf,

	/**	
	@brief     获取Wifi作为client连接后的详细信息请求响应,Ev_MT_BLL_HD_GetWifiCurConnectedInfoRt_Rsp   
	
	MainBuf(#TWifiCurDetailInfo_Api, tWifiCurDetailInfo)

	@verbatim
	{
    	"emState": 0,
    	"nNetworkId": 0,
    	"achSsid": "",
    	"achBSsid": "",
    	"achMacAddress": "",
    	"dwIp": 0,
    	"dwMask": 0,
    	"dwGateway": 0,
     	"emReason": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_GetWifiCurConnectedInfoRt_Rsp,
	
	/**	
	@brief    设置移动数据3G/4G工作模式
	
	MainBuf(#TMobileDataWorkMode_Api, tMobileDataWorkMode)

	@verbatim
	{
	    "bEnable": true
	}
	@endverbatim
	*/ 
	Ev_MtApi_Base_Hd_SetMobileDataWorkModeCfg_Ntf,	
	
	/**	
	@brief    获取移动数据3G/4G工作模式
	
	MainBuf(#TMobileDataWorkMode_Api, tMobileDataWorkMode)

	@verbatim
	{
	    "bEnable": true
	}
	@endverbatim
	*/ 
	Ev_MtApi_Base_Hd_GetMobileDataWorkModeCfg_Rsp,
	
	/**	
	@brief    设置移动数据3G/4G连接后的详细信息
	
	MainBuf(#TMobileDataCurDetailInfo_Api, tMobileDataCurDetailInfo)

	@verbatim
	{
	    "emState": 0,
	    "emNetType": 0,
	    "emGenerationType": 0,
	    "achSsid": "",
	    "dwIp": 0,
	    "achConnTime": "",
	    "emReason": 0
	}
	@endverbatim
	*/ 
	Ev_MtApi_Base_Hd_SetMobileDataConnectedInfoRt_Ntf,	

	/**	
	@brief    获取移动数据3G/4G连接后的详细信息
	
	MainBuf(#TMobileDataCurDetailInfo_Api, tMobileDataCurDetailInfo)

	@verbatim
	{
	    "emState": 0,
	    "emNetType": 0,
	    "emGenerationType": 0,
	    "achSsid": "",
	    "dwIp": 0,
	    "achConnTime": "",
	    "emReason": 0
	}
	@endverbatim
	*/  
	Ev_MtApi_Base_Hd_GetMobileDataConnectedInfoRt_Rsp,

	/**	
	@brief    设置当前对外通讯的网络IP详细信息 emHD_Rt_NetUsedInfo 对应于Ev_MT_BLL_HD_SetNetUsedInfoRt_Ntf
	
	MainBuf(#TNetUsedInfo_Api, tNetUsedInfo)

	@verbatim
	{
		"emUsedType": 0,
		"dwIp": 0,
		"dwMask": 0,
		"dwGateway": 0,
		"dwDns": 0,
		"dwDnsBackup": 0
	}
	@endverbatim
	*/  
	Ev_MtApi_Base_Hd_SetNetUsedInfoRt_Ntf,

	/**	
	@brief    获取当前对外通讯的网络IP详细信息 对应于Ev_MT_BLL_HD_GetNetUsedInfoRt_Rsp 
	
	MainBuf(#TNetUsedInfo_Api, tNetUsedInfo)

	@verbatim
	{
		"emUsedType": 0,
		"dwIp": 0,
		"dwMask": 0,
		"dwGateway": 0,
		"dwDns": 0,
		"dwDnsBackup": 0
	}
	@endverbatim
	*/               
	Ev_MtApi_Base_Hd_GetNetUsedInfoRt_Rsp,

	/**	
	@brief    网管服务器登录结果通知,Ev_MT_BLL_AgentLogInResult_Ntf
	
	MainBuf(#TNMSLogInResult_Api, tNMSLogInResult)

	@verbatim
	{
	   "bLoginOk" : true,
	   "dwReason" : 1
	}
	@endverbatim
	*/    
	Ev_MtApi_Base_AgentLogInResult_Ntf,


	/**	
	@brief    网管服务器登出结果通知,Ev_MT_BLL_AgentLogOutResult_Ntf
	
	MainBuf(#BOOL32, bLogoutOk)

	@verbatim
	{
	   "bLogoutOk" : true,
	}
	@endverbatim
	*/    
	Ev_MtApi_LogoutNmsServer_Ntf,

	/**	
	@brief    API服务器登录结果
	
	MainBuf(#TRestErrorInfo_Api, tRestErrorInfo)\n
	SubBuf(#s8[], achUserName)

	@verbatim
	{
		"MainParam":
		{
		    "achErrorInfo": "",
		    "emApiType": 1,
		    "dwErrorID": 1,
		    "dwNackEventId": 1,
		    "adwParams":
		    [
		      {
		        "basetype": 1
		      }
		    ]
		},
		"AssParam": 
		{
			"achName" : "str"
		}
	}
	@endverbatim
	*/
	Ev_MtApi_RestPlatformAPILogin_Rsp,

	/**		
	@brief    系统消息提示,achExtraParam: 这是个json格式的str
	
	MainBuf(#TMTSysHint_Api, tSysHint)

	@verbatim
	{
	   "emHintCode" : 0,
	   "achExtraParam" : "str"
	}
	@endverbatim
	*/
	Ev_MtApi_SysHint_Ntf,

	/**	
	@brief    获取DHCP租约信息响应
	
	MainBuf(#u32, dwResult) \n
	MainBuf(#TDHCPStateInfo_Api, tState) \n
	MainBuf(#TDHCPLeaseInfo_Api, tLeaseInfo)

	@verbatim
	{
	    "dwResult": 0,
	    "tState": {
	        "dwState": 0
	    },
	    "tLeaseInfo": {
	        "dwEthId": 0,
	        "dwIp": 1,
	        "dwMask": 1,
	        "dwGateway": 1,
	        "dwDuration": 1,
	        "adwDnsServerList": [
	            0,
	            0
	        ]
	    }
	}
	@endverbatim
	*/
	Ev_MtApi_Ethernet_GetDHCPLeaseInfo_Rsp, 

	/**	
	@brief    DHCP租约信息通知
		
	MainBuf(TDHCPStateInfo_Api, tState)
	MainBuf(TDHCPLeaseInfo_Api, tLeaseInfo)
	MainBuf(#u32, dwReason)

	@verbatim
	{	
	    "tState": {
	        "dwState": 0
	    },
	    "tLeaseInfo": {
	        "dwEthId": 0,
	        "dwIp": 1,
	        "dwMask": 1,
	        "dwGateway": 1,
	        "dwDuration": 1,
	        "adwDnsServerList": [
	            0,
	            0
	        ]
	    },
	    "dwReason": 0,
	}
	@endverbatim
	*/
	Ev_MtApi_Ethernet_DHCPLeaseInfo_Ntf,

	/**	
	@brief    获取以太网首选参数响应
	
	MainBuf(#u32, dwResult) \n
	MainBuf(#u32, dwEthId) \n
	MainBuf(#TEthnetInterfaceParam_Api, tEthParam)

	@verbatim
	{	
	    "dwResult": 0,
	    "dwEthId" : 0,
		"tEthParam" : {
			"dwIp" : 0,
			"dwMask" : 0,
			"achMac" : ""
		}
	}
	@endverbatim
	*/
	Ev_MtApi_Ethernet_PreferredIpParam_Rsp,

	/**	
	@brief    PPPoE 获取连接状态响应
	
	MainBuf(#TPPPoEState_Api, tPPPoEState)

	@verbatim
	{
		"emState": 0,
		"dwIp" : 0,  
		"dwGateway" : 0,
		"dwDns" : 0,
		"dwDnsBackup"　: 0,
		"emReason" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_PPPoE_GetLinkState_Rsp, 

	/**	
	@brief    PPPoE 连接状态通知
	
	MainBuf(#TPPPoEState_Api, tPPPoEState)

	@verbatim
	{
		"emState": 0,
		"dwIp" : 0,  
		"dwGateway" : 0,
		"dwDns" : 0,
		"dwDnsBackup"　: 0,
		"emReason" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_PPPoE_LinkState_Ntf, 

	/**	
	@brief    PPPoE 连接后获取统计信息响应
	
	MainBuf(#TPPPoEStatis_Api, tPPPoEStatis)

	@verbatim
	{
		"dwLinkTime": 0,
		"dwLinkDowntimes" : 0,  
		"dwNumPkgSent" : 0,
		"dwNumPkgRecved" : 0,
		"dwNumBytesSent"　: 0,
		"dwNumBytesRecved" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_PPPoE_GetStatisInfo_Rsp,

	/**	
	@brief    获取所有路由请求响应
	
	MainBuf(#TRouteItemInfoList_Api, tRouteList)

	@verbatim
	{
	    "atRouteList": [
	        {
	            "dwInterface": 0,
	            "dwDstNetwork": 0,
	            "dwDstNetMask": 0,
	            "dwGateway": 0,
	            "dwPriority": 0
	        }
	    ]
	}
	@endverbatim
	*/
	Ev_MtApi_ROUTE_GetAllRoute_Rsp,

	/**	
	@brief    新增一条路由请求响应
	
	MainBuf(#BOOL32 , bResult) \n
	MainBuf(#TRouteItemInfo_Api , tRouteInfo)

	@verbatim
	{
	    "bResult": true,
	    "tRouteInfo":{
	        "dwInterface": 0,
	        "dwDstNetwork": 0,
	        "dwDstNetMask": 0,
	        "dwGateway": 0,
	        "dwPriority": 0
	    }
	}
	@endverbatim
	*/
	Ev_MtApi_ROUTE_AddRouteResult_Rsp,

	/**	
	@brief   新增一条路由通知
	
	MainBuf(#TRouteItemInfo_Api , tRouteItemInfo)

	@verbatim
	{
	    "dwInterface": 0,
	    "dwDstNetwork": 0,
	    "dwDstNetMask": 0,
	    "dwGateway": 0,
	    "dwPriority": 0
	}
	@endverbatim
	*/
	Ev_MtApi_ROUTE_AddRoute_Ntf,

	/**	
	@brief    获取所有路由请求响应
	
	MainBuf(#BOOL32 , bResult) \n
	MainBuf(#TRouteItemInfo_Api , tRouteInfo )

	@verbatim
	{
	    "bResult": true,
	    "tRouteInfo":{
	        "dwInterface": 0,
	        "dwDstNetwork": 0,
	        "dwDstNetMask": 0,
	        "dwGateway": 0,
	        "dwPriority": 0
	    }
	}
	@endverbatim
	*/
	Ev_MtApi_ROUTE_DelRouteResult_Rsp,

	/**	
	@brief    删除一条路由通知
	
	MainBuf(#TRouteItemInfo_Api , tRouteItemInfo)

	@verbatim
	{
	    "dwInterface": 0,
	    "dwDstNetwork": 0,
	    "dwDstNetMask": 0,
	    "dwGateway": 0,
	    "dwPriority": 0
	}
	@endverbatim
	*/
	Ev_MtApi_ROUTE_DelRoute_Ntf,

	/**	
	@brief    修改一条路由通知
	
	MainBuf(#TRouteItemInfo_Api , tOldRouteInfo ) \n
	MainBuf(#TRouteItemInfo_Api , tNewRouteInfo )

	@verbatim
	{
	    "tOldRouteInfo":{
	        "dwInterface": 0,
	        "dwDstNetwork": 0,
	        "dwDstNetMask": 0,
	        "dwGateway": 0,
	        "dwPriority": 0
	    }
	    "tNewRouteInfo":{
	        "dwInterface": 0,
	        "dwDstNetwork": 0,
	        "dwDstNetMask": 0,
	        "dwGateway": 0,
	        "dwPriority": 0
	    }
	}
	@endverbatim
	*/
	Ev_MtApi_ROUTE_ModifyRoute_Ntf,

	/**	
	@brief    修改一条路由请求响应
	
	MainBuf(#BOOL32 , bResult) \n
	MainBuf(#TRouteItemInfo_Api , tOldRouteInfo ) \n
	MainBuf(#TRouteItemInfo_Api , tNewRouteInfo )

	@verbatim
	{
	    "bResult": true,
	    "tOldRouteInfo":{
	        "dwInterface": 0,
	        "dwDstNetwork": 0,
	        "dwDstNetMask": 0,
	        "dwGateway": 0,
	        "dwPriority": 0
	    }
	    "tNewRouteInfo":{
	        "dwInterface": 0,
	        "dwDstNetwork": 0,
	        "dwDstNetMask": 0,
	        "dwGateway": 0,
	        "dwPriority": 0
	    }
	}
	@endverbatim
	*/
	Ev_MtApi_ROUTE_ModifyRouteResult_Rsp,

	/**	
	@brief    Wifi 工作模式信息响应
	
	MainBuf(#TWifiWorkMode_Api, tWifiWorkMode)

	@verbatim
	{
	    "emWifiWKMD": 0,
	    "tWifiApCfg": {
	        "achSsid": "",
	        "emCapabilities": 0,
	        "achKey": "",
	        "dwDhcpStartIp": 0,
	        "dwDhcpEndIp": 0,
	        "dwIp": 0,
	        "dwMask": 0
	    }
	}
	@endverbatim
	*/
	Ev_MtApi_WIFI_GetWorkMode_Rsp,

	/**	
	@brief    Wifi 热点扫描结果通知
	
	MainBuf(#TWifiScanResultList_Api, tWifiScanResultList)

	@verbatim
	{
		"byCnt" : 0,
		"atScanList" :
		[
			"achSsid" : "str",
			"emCapabilities": 0,
			"emSignalLevel" : 0,
			"bIsSave" : 0,
			"nNetworkId" : 0
		]
	}
	@endverbatim
	*/
	Ev_MtApi_WIFI_ScanResult_Rsp, 

	/**	
	@brief    Wifi 热点连接结果状态响应
	
	MainBuf(#TWifiCurDetailInfo_Api, tWifiCurDetailInfo)

	@verbatim
	{
		"emState": 0,
		"nNetworkId": 0,
		"achSsid": "",
		"achBSsid": "",
		"achMacAddress": "",
		"dwIp": 0,
		"dwMask": 0,
		"dwGateway": 0,
		"emReason": 0
	}
	@endverbatim
	*/
	Ev_MtApi_WIFI_LinkState_Rsp,
	
	/**	
	@brief    Wifi 热点连接结果状态通知
	
	MainBuf(#TWifiCurDetailInfo_Api, tWifiCurDetailInfo)

	@verbatim
	{
		"emState": 0,
		"nNetworkId": 0,
		"achSsid": "",
		"achBSsid": "",
		"achMacAddress": "",
		"dwIp": 0,
		"dwMask": 0,
		"dwGateway": 0,
		"emReason": 0
	}
	@endverbatim
	*/
	Ev_MtApi_WIFI_LinkState_Ntf, 

	/**	
	@brief    Wifi 获取当前连接的Wifi客户端属性响应
	
	MainBuf(#TWifiConfiguration_Api, tWifiConfiguration)

	@verbatim
	{
	    "bEnableAutoConn": true,
	    "bEnableAutoIp": true,
	    "dwIp": 0,
	    "dwMask": 0,
	    "dwGateway": 0
	}
	@endverbatim
	*/
	Ev_MtApi_WIFI_GetModClientProperty_Rsp,

	/**	
	@brief    Wifi 获取当前连接的Wifi客户端详细信息响应
	
	MainBuf(#TWifiCurDetailInfo_Api, tWifiCurDetailInfo)

	@verbatim
	{
	    "emState": 0,
	    "nNetworkId": 0,
	    "achSsid": "",
	    "achBSsid": "",
	    "achMacAddress": "",
	    "dwIp": 0,
	    "dwMask": 0,
	    "dwGateway": 0,
	    "emReason": 0
	}
	@endverbatim
	*/
	Ev_MtApi_WIFI_GetWifiCurConnectedInfo_Rsp,
	
	/**	
	@brief    Wifi 热点连接结果状态响应
	
	MainBuf(#TWifiStatisInfo_Api, tWifiStatisInfo)

	@verbatim
	{
		"achSsid" : "str",
		"nNetworkId" :0,
		"emSignalLevel" : 0,
		"dwDownTotalBytes" : 0,
		"dwUpTotalBytes" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_WIFI_GetCurWifiStatisInfo_Rsp,

	/**	
	@brief    MobileData 移动数据连接后详细状态通知
	
	MainBuf(#TMobileDataCurDetailInfo_Api, tMobileDataCurDetailInfo)

	@verbatim
	{
	    "emState": 0,
	    "emNetType": 0,
	    "emGenerationType": 0,
	    "achSsid": "",
	    "dwIp": 0,
	    "achConnTime": "",
	    "emReason": 0
	}
	@endverbatim
	*/
	Ev_MtApi_MOBILEDATA_LinkState_Ntf,

	/**	
	@brief    MobileData 工作模式信息查询响应
	
	MainBuf(#TMobileDataWorkMode_Api, tMobileDataWorkMode)

	@verbatim
	{
	    "bEnable": true
	}
	@endverbatim
	*/
	Ev_MtApi_MOBILEDATA_GetWorkMode_Rsp,

	/**	
	@brief    MobileData 移动数据连接后详细消息响应
	
	MainBuf(#TMobileDataCurDetailInfo_Api, tMobileDataCurDetailInfo)

	@verbatim
	{
	    "emState": 0,
	    "emNetType": 0,
	    "emGenerationType": 0,
	    "achSsid": "",
	    "dwIp": 0,
	    "achConnTime": "",
	    "emReason": 0
	}
	@endverbatim
	*/
	Ev_MtApi_MOBILEDATA_GetDetailInfo_Rsp,

	/**	
	@brief    MobileData 当前连接的移动数据统计信息查询响应
	
	MainBuf(#TMobileDataStatisInfo_Api, tMobileDataStatisInfo)

	@verbatim
	{
	    "emSignalLevel": 0,
	    "dwUpBandwidth": 0,
	    "dwDownBandwidth": 0,
	    "dwUpBytes": "",
	    "dwDownBytes": 0
	}
	@endverbatim
	*/
	Ev_MtApi_MOBILEDATA_GetCurStatisInfo_Rsp,

	/**	
	@brief    终端有新版本通知
	
	MainBuf(#TNewUpgradeVersion_Api, tNewUpgradeVersion)

	@verbatim
	{
	    "dwLevel": 1,
	    "achSusIp": "172.16.1.1",
	    "achVer": "V5R0",
	    "achOemStr": ""
	}
	@endverbatim
	*/
	Ev_MtApi_AgentNewVersion_Ntf,

	/**	
	@brief    Nms消息通知
	
	MainBuf(#s8[], achNmsMsg)

	@verbatim
	{
	    "basetype": ""
	}
	@endverbatim
	*/
	Ev_MtApi_AgentNmsMsg_Ntf,

	/**	
	@brief    ping测试结果通知
	
	MainBuf(#TPingResult_Api, tPingResult)

	@verbatim
	{
	    "emPingErrCode": 0,
	    "dwTTL": 64,
	    "dwTripTime": 64,
	    "dwUserId": 64,
	    "dwErrType": 64,
	    "dwErrCode": 64
	}
	@endverbatim
	*/
	Ev_MtApi_NET_PingTestResult_Rsp, 

	/**	
	@brief    ip mac冲突通知
	
	MainBuf(#TNetConfilictedInfo_Api, tNetConfilictedInfo)

	@verbatim
	{
	    "emConflictType": 0,
		"achMac":"01-23-34-34-34-34",
		"achIp":"172.16.34.3"
	}
	@endverbatim
	*/
	Ev_MtApi_NET_IPMACConflicted_Ntf,

	/**	
	@brief    查询DNS对应的IP信息请求响应
	
	MainBuf(#TDNSNameToIpResult_Api, tDNSNameToIpResult)

	@verbatim
	{
		"achDnsName" : "",
		"dwIp" : "",
		"dwErrorCode" : ""
	}
	@endverbatim
	*/
	Ev_MTApi_Ethernet_GetIpByDNSInfo_Rsp,

	/**	
	@brief    设置当前日期时间通知
	
	MainBuf(#TMTTime_Api, tMTTime)

	@verbatim
	{
	    "wYear": 1912,
	    "byMonth": 12,
	    "byDay": 12,
	    "byHour": 10,
	    "byMinute": 12,
	    "bySecond": 12,
	    "wMicroSecond": 12
	}
	@endverbatim
	*/
	Ev_MTApi_SetSysDataTime_Ntf,

	/**	
	@brief    设置当前日期时间信息响应
	
	MainBuf(#BOOL32, bResult) \n
	MainBuf(#TMTTime_Api, tMTTime)

	@verbatim
	{
		"bResult" :true,
		"tTime" :{
		"wYear": 1912,
		"byMonth": 12,
		"byDay": 12,
		"byHour": 10,
		"byMinute": 12,
		"bySecond": 12,
		"wMicroSecond": 12
		}
	}
	@endverbatim
	*/
	Ev_MTApi_SetSysDataTimeResult_Rsp,
	
	/**	
	@brief    查询当前日期时间信息响应
	
	MainBuf(#BOOL32, bResult) \n
	MainBuf(#TMTTime_Api, tMTTime)

	@verbatim
	{
	    "bResult" :true,
	    "tTime" :{
	        "wYear": 1912,
	        "byMonth": 12,
	        "byDay": 12,
	        "byHour": 10,
	        "byMinute": 12,
	        "bySecond": 12,
	        "wMicroSecond": 12
	    }
	}
	@endverbatim
	*/
	Ev_MTApi_GetSysDataTime_Rsp,

	/**	
	@brief    设置NTP服务开启关闭状态响应
	
	MainBuf(#BOOL32, bResult) \n
	MainBuf(#TMTNTPInfo_Api, tNtpInfo)

	@verbatim
	{
	    "bResult" :true,
	    "tNtpInfo" :{
	        "achDomainName":"",
	        "dwInterval":0,
	        "bUsedNtp":true
	    }
	}
	@endverbatim
	*/
	Ev_MTApi_SetNTPSvrParamResult_Rsp,

	/**	
	@brief    设置NTP服务开启关闭状态通知
	
	MainBuf(#TMTNTPInfo_Api, tNtpInfo)

	@verbatim
	{
	    "achDomainName":"",
	    "dwInterval":0,
	    "bUsedNtp":true
	}
	@endverbatim
	*/
	Ev_MTApi_SetNTPSvrParam_Ntf,

	/**	
	@brief    查询当前NTP服务开启状态响应
	
	MainBuf(#BOOL32, bResult) \n
	MainBuf(#TMTNTPInfo_Api, tNtpInfo)

	@verbatim
	{
	    "bResult" :true,
	    "tNtpInfo" :{
	        "achDomainName":"",
	        "dwInterval":0,
	        "bUsedNtp":true
	    }
	}
	@endverbatim
	*/
	Ev_MTApi_GetNTPSvrParam_Rsp,

	/**
	@brief    设置CSU配置通知
	
	MainBuf(#TMtCSUAddr_Api, tCsuCfg)

	@verbatim
	{
		"bUsedCSU": true,
		"achDomain": "",
		"dwIp": 0,
		"achNumber": "",
		"achPassword": ""
		"dwTimeToLive":0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetGKCfg_Ntf,

	/**
	@brief    获取CSU配置响应
	
	MainBuf(#TMtCSUAddr_Api, tCsuCfg)

	@verbatim
	{
		"bUsedCSU": true,
		"achDomain": "",
		"dwIp": 0,
		"achNumber": "",
		"achPassword": ""
		"dwTimeToLive":0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetGKCfg_Rsp,

	/**
	@brief    终端设置向导已走完通知
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"basetype": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetHasWizardConfigedCfg_Ntf,

	/**
	@brief   查询终端设置向导是否已走完响应
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"basetype": false
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetHasWizardConfigedCfg_Rsp,


	/**
	@brief    手动设置的sip服务器配置通知
	
	MainBuf(#TMtSipSvrAddr_Api, tMtSipSvrAddr)

	@verbatim
	{
	"bEnable": true,
	"achDomain": "",
	"dwIp": 0,
	"dwPort": 0,
	"achPassword": "",
	"dwExpire": 0,
	"achValidateName": "",
	"dwHostPort": 0,
	"achAuthName":""
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetSipSvrManuCfg_Ntf,

	/**
	@brief    手动设置的sip服务器配置通知
	
	MainBuf(#TMtSipSvrAddr_Api, tMtSipSvrAddr)

	@verbatim
	{
	"bEnable": true,
	"achDomain": "",
	"dwIp": 0,
	"dwPort": 0,
	"achPassword": "",
	"dwExpire": 0,
	"achValidateName": "",
	"dwHostPort": 0,
	"achAuthName":""
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetSipSvrManuCfg_Rsp,

	/**
	@brief    查询终端是否注册上gk响应
	
	MainBuf(#BOOL32)

	@verbatim
	{
        "basetype" : false
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetIsGkRigistedRt_Rsp,

	/**
	@brief    查询终端是否注册上sip响应
	
	MainBuf(#BOOL32)

	@verbatim
	{
        "basetype" : false
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetIsSipRigistedRt_Rsp,

	/**
	@brief    配置快速呼叫通知
	
	MainBuf(#TFastCallList_Api)

	@verbatim
	{
		"dwListCnt" : 0,
		"atFastCallList" :
		[
		{
			"dwCallRate" : 0,
			"emCallType" : 0,
			"dwPeerAddr" : 0,
			"achPeerE164" : "",
			"achPeerAlias" : ""
		}
		]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetFastCallListCfg_Ntf,

	/**
	@brief    获取快速呼叫配置响应
	
	MainBuf(#TFastCallList_Api)

	@verbatim
	{
		"dwListCnt" : 0,
		"atFastCallList" :
		[
		{
			"dwCallRate" : 0,
			"emCallType" : 0,
			"dwPeerAddr" : 0,
			"achPeerE164" : "",
			"achPeerAlias" : ""
		}
		]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetFastCallListCfg_Rsp,

	/**
	@brief    获取IM模块登录句柄响应
	
	MainBuf(#u32)

	@verbatim
	{
		"basetype" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetIMHandleRt_Rsp,

		/**
	@brief    配置是否显示会议名称通知
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"basetype" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetShowConfNameCfg_Ntf,

	/**
	@brief    获取是否显示会议名称配置响应
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"basetype" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetShowConfNameCfg_Rsp,

	/**
	@brief    设置Ftp/Telnet账号信息响应
	
	MainBuf(#BOOL32) \n
	MainBuf(#TMTFtpTelnetAccountInfo_Api)

	@verbatim
	{
		"bResult" : false,
		"tAccountInfo": 
		{
			"achUserName" : "",
			"achPassword" : ""
		}
	}
	@endverbatim
	*/
	Ev_MTApi_Base_SetFtpTelnetAccountInfo_Rsp,

	/**
	@brief    设置Ftp/Telnet登录的用户名、密码通知
	
	MainBuf(#TMTFtpTelnetAccountInfo_Api)

	@verbatim
	{
		"achUserName" : "",
		"achPassword" : ""
	}
	@endverbatim
	*/
	Ev_MTApi_Base_SetTelnetFtpUserInfoCfg_Ntf,

	/**
	@brief    获取Ftp/Telnet登录的用户名、密码响应
	
	MainBuf(#TMTFtpTelnetAccountInfo_Api)

	@verbatim
	{
		"achUserName" : "",
		"achPassword" : ""
	}
	@endverbatim
	*/
	Ev_MTApi_Base_GetTelnetFtpUserInfoCfg_Rsp,

	/**
	@brief    获取终端射频配对状态列表响应
	
	MainBuf(#TMTRfMatchStateList_Api)

	@verbatim
	{
		"dwCnt" : 0,
		"atStateList" : [
		{
			"emMicId" : 0,
			"bMatched" : false,
			"dwMatchId" : 0
		}
		]
	}
	@endverbatim
	*/
	Ev_MTApi_Base_GetRfMatchStateListCfg_Rsp,

	/**
	@brief    以太网连接状态变化通知
	
	MainBuf(#BOOL32)\n
    SubBuf(#BOOL32)

	@verbatim
	{
        "bEth0State" : 0,
        "bEth1State" : 0
	}
	@endverbatim
	*/
	Ev_MTApi_Base_Ethernet_LinkState_Ntf,

	/**
	@brief    丢包率通知
	
	MainBuf(#u32)

	@verbatim
	{
        "basetype" : 0
	}
	@endverbatim
	*/
	Ev_MTApi_Base_PackageLostRatio_Ntf,

    /**
	@brief    设置是否使用HTTPS通知
	@verbatim
	MainBuf(BOOL32)
	{
		"basetype" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetEnableHTTPSCfg_Ntf,

    /**
	@brief    获取是否使用HTTPS配置应答
	@verbatim
	MainBuf(BOOL32)
	{
		"basetype" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetEnableHTTPSCfg_Rsp,

	/**
	@brief    设置当前wifi配置通知
	
	MainBuf(#BOOL32)\n
    SubBuf(#TWifiConfiguration_Api)

	@verbatim
	{
        "MainParam" : 
        {
            "basetype" : 0
        },
        "AssParam" : 
        {
            "tWifiConfig":
            {
		        "bEnableAutoConn": true,
		        "bEnableAutoIp": true,
		        "dwIp": 0,
		        "dwMask": 0,
		        "dwGateway": 0
            }
        }
	}
	@endverbatim
	*/
	Ev_MTApi_Base_WIFI_ModClientProperty_Ntf,

	/**
	@brief    获取所有以太网卡的连接状态响应
	
    MainBuf(#BOOL32)\n
    MainBuf(#BOOL32)

	@verbatim
	{
        "bEth0State": false,
        "bEth1State": false,
	}
	@endverbatim
	*/
	Ev_MTApi_Base_Ethernet_GetLinkState_Rsp,

		/**
	@brief    配置是否强制设置323协议栈通知
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"basetype" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ForceSet323StackCfg_Ntf,

		/**
	@brief    配置是否强制设置323协议栈通知
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"basetype" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetForceH323StackCfg_Rsp,

	/**
	@brief    配置服务器登录端口的通知
	
	MainBuf(#TServerLoginPort_Api)

	@verbatim
	{
		"dwHttpPort" : 0
        "dwHttpsPort" : 0
	}
	@endverbatim
	*/
    Ev_MtApi_Base_SetServerLoginPortCfg_Ntf,

	/**
	@brief    配置服务器登录端口的响应
	
	MainBuf(#TServerLoginPort_Api)

	@verbatim
	{
        "dwHttpPort" : 0
        "dwHttpsPort" : 0
	}
	@endverbatim
	*/
    Ev_MtApi_Base_GetServerLoginPortCfg_Rsp,

        /**	
	@brief    以太网网口切换,Ev_MT_BLL_HD_EthnetCardChange_Ntf 
	
	MainBuf(#TEthnetCfg_Api, tCfg_Api)

	@verbatim
	{
		"emEthBackupMD": 0,
		"dwCurCardId": 0,
		"tEth1": {
				"bEnableIpDhcp": true,
				"dwStaticIp": 0,
				"dwStaticMask": 0,
				"dwStaticGW": 0,
				"dwDhcpIp": 0,
				"dwDhcpMask": 0,
				"dwDhcpGW": 0,
				"bEnableDnsDhcp": true,
				"dwStaticDns": 0,
				"dwStaticDnsBackup": 0,
				"dwDhcpDns": 0,
				"dwDhcpDnsBackup": 0
		},
		"tEth2": {
			"bEnableIpDhcp": true,
			"dwStaticIp": 0,
			"dwStaticMask": 0,
			"dwStaticGW": 0,
			"dwDhcpIp": 0,
			"dwDhcpMask": 0,
			"dwDhcpGW": 0,
			"bEnableDnsDhcp": true,
			"dwStaticDns": 0,
			"dwStaticDnsBackup": 0,
			"dwDhcpDns": 0,
			"dwDhcpDnsBackup": 0
				}
	}
	@endverbatim
	*/
    Ev_MtApi_HD_EthnetCardChange_Ntf,


		/**	
	@brief    设置视频输出标签 (value:TMTVideoOutTagList)emHD_Cfg_VideoOutTag
	
	MainBuf(#TMTVideoOutTagList_Api)

	@verbatim
	{
	    "byCnt" : 0,
		"atVidOutTag" :
		[
			{
				"emVideoPortId" : 0,
				"achVideoPortTag" : ""
			}
		]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetVideoOutTagCfg_Ntf,

	/**	
	@brief    获取视频输出标签 (value:TMTVideoOutTagList)emHD_Cfg_VideoOutTag
	
	MainBuf(#TMTVideoOutTagList_Api)

	@verbatim
	{
	    "byCnt" : 0,
		"atVidOutTag" :
		[
			{
				"emVideoPortId" : 0,
				"achVideoPortTag" : ""
			}
		]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetVideoOutTagCfg_Rsp,

	/**	
	@brief    设置SDI一进一出或者两进(value: TU32)
	
	MainBuf(#u32)

	@verbatim
	{
	    dwTpye: 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetSDIOneInOneOutOrTwoInCfg_Ntf,

	/**	
	@brief    获取SDI一进一出或者两进(value: TU32)
	
	MainBuf(#u32)

	@verbatim
	{
		dwTpye: 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetSDIOneInOneOutOrTwoInCfg_Rsp,


		/**	
	@brief    设置视频输出标签 (value:TMTHDSerialList)emHD_Cfg_SerialList
	
	MainBuf(#TMTHDSerialList_Api)

	@verbatim
	{
		"byCnt" : 0,
		"atVidOutTag" :
		[
			{
				emSerialType：                                
				dwBandRate：                                                
				dwByteSize：                                                
				emStopBits：                                   
				emParityCheck：                         
			}
		]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetSerialListCfg_Ntf,

	/**	
	@brief    获取串口列表 (value:TMTHDSerialList)emHD_Cfg_SerialList
	
	MainBuf(#TMTHDSerialList_Api)

	@verbatim
	{
	    "byCnt" : 0,
		"atVidOutTag" :
		[
			{
				emSerialType：                                
				dwBandRate：                                                
				dwByteSize：                                                
				emStopBits：                                   
				emParityCheck：                         
			}
		]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetSerialListCfg_Rsp,
/**
  @brief   进入或退出生产测试是否登录
  
  MainBuf(#BOOL32)
  @verbatim
  {
    "registerstate" : false
  }
  @endverbatim
*/
	Ev_MtApi_Base_MfgTestRegisterInOrOut_Ntf,


	/**
	@brief    设置端口复用的通知
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bSamePort" : 0
	}
	@endverbatim
	*/
    Ev_MtApi_Base_SetTRtpSamePortCfg_Ntf,


	/**
	@brief    获取端口复用的通知
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bSamePort" : 0
	}
	@endverbatim
	*/
    Ev_MtApi_Base_GetTRtpSamePortCfg_Rsp,

		/**
	@brief    设置是否开启会议强拆的通知
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bEnable" : 0
	}
	@endverbatim
	*/
    Ev_MtApi_Base_SetConfOccupyCfg_Ntf,

		/**
	@brief    导出配置文件的响应
	
	MainBuf(#EmFileCopyErr_Api)

	@verbatim
	{
		"emCopySuccess_Api" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ExportMtcfg_Rsp,

	/**
	@brief    导入配置文件的响应
	
	MainBuf(#EmFileCopyErr_Api)

	@verbatim
	{
		"emCopySuccess_Api" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ImportMtcfg_Rsp,

		/**
	@brief    导出debug文件的响应
	
	MainBuf(#EmFileCopyErr_Api)

	@verbatim
	{
		"emCopySuccess_Api" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ExportMtDbgcfg_Rsp,

	/**
	@brief    导入debug文件的响应
	
	MainBuf(#EmFileCopyErr_Api)

	@verbatim
	{
		"emCopySuccess_Api" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ImportMtDbgcfg_Rsp,

	/**
	@brief    设置是否开启IPW方式的通知
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bEnable" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetEnableIpwType_Ntf,

	/**
	@brief    获取是否开启IPW方式的响应
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bEnable" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetEnableIpwType_Rsp,

	
	/**
	@brief    设置摄像头正向反向
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bDirection" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetCameraContrlExchangeCfg_Ntf,

	/**
	@brief    获取摄像头正向反向
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bDirection" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetCameraContrlExchangeCfg_Rsp,

	/**
	@brief    设置摄像头是否倒装
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bHeadStand" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetCameraHeadStandCfg_Ntf,

	/**
	@brief    获取摄像头是否倒装
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bHeadStand" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetCameraHeadStandCfg_Rsp,

	/**	
	@brief    设置无线投屏配对相应
	
	MainBuf(#TWifiWirelessScreenInfo_Api, tCfg)

	@verbatim
	{
		"dwWirelessScreenDeviceNum" :0,
		"emWirelessScreenState":0,
		"emWirelessScreenErrReason":0
	}
	@endverbatim
	*/
	Ev_MTApi_Base_SetWirelessScreenStateChange_Ntf,

	/**
	@brief    设置是否显示与会方入会/离会提示的通知
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bShow" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetShowInOutConfCfg_Ntf,

	/**
	@brief    获取是否显示与会方入会/离会提示的回复
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bShow" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetShowInOutConfCfg_Rsp,

	/**
	@brief    设置osd log打印控制的通知
	
	MainBuf(#u32)

	@verbatim
	{
		"dwLogId": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetOsdLogCtrl_Ntf,

	/**
	@brief    新增ftp/telnet限定ip响应
	
	MainBuf(#BOOL32, bResult);
	MainBuf(#TMtLimitIpInfo_Api, tInfo);

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_FtpTelnet_AddLimitIp_Rsp,

	/**
	@brief    删除ftp/telnet限定ip响应
	
	MainBuf(#BOOL32, bResult);
	MainBuf(#TMtLimitIpInfo_Api, tInfo);

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_FtpTelnet_DelLimitIp_Rsp,

	/**
	@brief    修改ftp/telnet限定ip响应
	
	MainBuf(#BOOL32, bResult);
	MainBuf(#TMtLimitIpInfo_Api, tOldInfo);
	MainBuf(#TMtLimitIpInfo_Api, tNewInfo);

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_FtpTelnet_ModLimitIp_Rsp,

	/**
	@brief    新增ftp/telnet限定ip通知
	
	MainBuf(#TMtLimitIpInfo_Api, tInfo);

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_FtpTelnet_AddLimitIp_Ntf,

	/**
	@brief    删除ftp/telnet限定ip通知
	
	MainBuf(#TMtLimitIpInfo_Api, tInfo);

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_FtpTelnet_DelLimitIp_Ntf,

	/**
	@brief    修改ftp/telnet限定ip通知
	
	MainBuf(#TMtLimitIpInfo_Api, tOldInfo);
	MainBuf(#TMtLimitIpInfo_Api, tNewInfo);

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_FtpTelnet_ModLimitIp_Ntf,

	/**	
	@brief    获取ftp/telnet限定ip列表响应
	
	MainBuf(#TMtLimitIpInfoList_Api)

	@verbatim
	{
	    
	}
	@endverbatim
	*/		
	Ev_Mtapi_Base_Hd_GetFtpTelnetLimitIpListCfg_Rsp,

	/**	
	@brief    向ui发送重置系统通知
	
	MainBuf( )	//无消息体

	@verbatim
	{

	}
	@endverbatim
	*/		
	Ev_MtApi_Base_OqcResetSystem_Ntf,

	//  商密
	/**
    @brief   导出Ca证书是否成功
  
    MainBuf(#BOOL32)
    @verbatim
    {
      "exportcaresult" : false
    }
    @endverbatim
    */
	Ev_MtApi_Base_ExportAllCACert_Rsp,

	/**
    @brief   导出设备证书是否成功
  
    MainBuf(#BOOL32)
    @verbatim
    {
      "exportdeviceresult" : false
    }
    @endverbatim
    */
	Ev_MtApi_Base_ExportDeviceCert_Rsp,

	/**
    @brief   生成设备证书是否成功
  
    MainBuf(#BOOL32)
    @verbatim
    {
      "createdeviceresult" : false
    }
    @endverbatim
    */
	Ev_MtApi_Base_CreateDeviceCert_Rsp,

	/**
    @brief   查询Ca证书信息
  
    MainBuf(#TMtSecCertInfo_Api)
    @verbatim
    {
	    achVersion;""                   ///< 版本只有1和3
	    achSerialNumber;""              ///< 序列号长度，HEX格式，一般最长20字节
	    achSignAlg;""                   ///< 签名算法（字符串）
	    tSecCertDistinctName            ///< 签发者信息
		{
		    achCountryName;	""		          ///< 国家（如中国"CN"），必需
		    achStateOrProvinceName;""		  ///< 州或省，可选
		    achLocalityName;""			      ///< 城市，可选
		    achOrganizationName;""		      ///< 组织（如公司），必需
		    achOrganizationUnitName;""	      ///< 组织单元（如部门），可选
		    achCommonName;""		          ///< 通用名（如域名、邮箱、姓名、序列号），必需

		}
	    tSecCertValidity                ///< 有效期
		{
		    achNotTimeBefore;""			      ///< 开始时间
		    achNotTimeAfter; ""		          ///< 过期时间
		}
	    tSecCertUsrName                 ///< 使用者信息
		{


		}
		achPubKey:""                    ///< 使用者公钥，DER格式，RSA2048为270字节
	    achPubKeyAlg;""                 ///< 公钥算法
    }
    @endverbatim
    */
	Ev_MtApi_Base_QueryCACertInfo_Rsp,

	/**
    @brief   查询设备证书信息
  
    MainBuf(#TMtSecDevCertInfo_Api)
    @verbatim
    {
		dwDevCertType: 1,
		tCertInfo
		{
			achVersion;""                   ///< 版本只有1和3
			achSerialNumber;""              ///< 序列号长度，HEX格式，一般最长20字节
			achSignAlg;""                   ///< 签名算法（字符串）
			tSecCertDistinctName            ///< 签发者信息
			{
				achCountryName;	""		          ///< 国家（如中国"CN"），必需
				achStateOrProvinceName;""		  ///< 州或省，可选
				achLocalityName;""			      ///< 城市，可选
				achOrganizationName;""		      ///< 组织（如公司），必需
				achOrganizationUnitName;""	      ///< 组织单元（如部门），可选
				achCommonName;""		          ///< 通用名（如域名、邮箱、姓名、序列号），必需

			}
			tSecCertValidity                ///< 有效期
			{
				achNotTimeBefore;""			      ///< 开始时间
				achNotTimeAfter; ""		          ///< 过期时间
			}
			tSecCertUsrName                 ///< 使用者信息
			{


			}
			achPubKey:""                    ///< 使用者公钥，DER格式，RSA2048为270字节
			achPubKeyAlg;""                 ///< 公钥算法
		}
    }
    @endverbatim
    */
	Ev_MtApi_Base_QueryDeviceCertInfo_Rsp,

	/**
    @brief   商密设置许可证是否可用
  
    MainBuf(#BOOL32)
    @verbatim
    {
      "bLicenseIsValidate" : FALSE
    }
    @endverbatim
    */
	Ev_MtApi_Base_DeviceLicenseIsValidate_Ntf,

	/**
    @brief   本端或者对端认证结果
  
    MainBuf(#BOOL32)
	MainBuf(#BOOL32)
    @verbatim
    {
      "bLocal" : FALSE
	  "bResult" : FALSE
    }
    @endverbatim
    */
	Ev_MtApi_Base_VerifyDynamicPwdRes_Ntf,

	/**
	@brief    商密 强认证 需要UI输入动态口令
	
	MainBuf(#无消息体)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_PeerNeedDynPwd_Ntf,

	/**
	@brief    获取辅视频是否有源的响应
	
	MainBuf(#TMTAssVidPortStatus_Api)

	@verbatim
	{
		"nVgaState":  0 
		"nHdmiState": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetAssVideoPortStatus_Rsp,

	/**
	@brief    获取是否为商密终端的响应
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bIsSecMt": FALSE
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetIsBusiSecMt_Rsp,

	/**
	@brief    设置商密 sip连接方式的通知
	
	MainBuf(#EmSipConnectType_Api)

	@verbatim
	{
		"emSipConnectType": 0
	}
	@endverbatim
	*/
    Ev_MtApi_Base_SetSipConnectCfg_Ntf,

	/**
	@brief    获取商密 sip连接方式的响应
	
	MainBuf(#EmSipConnectType_Api)

	@verbatim
	{
		"emSipConnectType": 0
	}
	@endverbatim
	*/
    Ev_MtApi_Base_GetSipConnectCfg_Rsp,

	/**
	@brief    设置是否开启商密强认证的通知
	
	MainBuf(#TBOOL32)

	@verbatim
	{
		"bEnable": FALSE
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetEnableStrongAut_Ntf,

	/**
	@brief    获取是否开启商密强认证的响应
	
	MainBuf(#TBOOL32)

	@verbatim
	{
		"bEnable": FALSE
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetEnableStrongAut_Rsp,

	/**
	@brief    删除ca证书通知
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bRet" : FALSE
	}
	@endverbatim
	*/
    Ev_MtApi_Base_DeleteCACertByID_Rsp,

	/**
	@brief    导出ca证书通知
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bRet" : FALSE
	}
	@endverbatim
	*/
    Ev_MtApi_Base_ExportCACertByID_Rsp,

	/**
	@brief    获取caidlist通知
	
	MainBuf(#TMtCertIDList_Api)

	@verbatim
	{
		byCount: 2,                   ///< id个数
		atIdList:
		[
			{
				"byLen": 2,			///< 长度
				"abyId": 225		///< u8 的数组
			}
		]
	}
	@endverbatim
	*/
    Ev_MtApi_Base_GetCACertIDList_Rsp,
	Ev_MtApi_Base_GetCACertIDListFin_Rsp,

	/**
	@brief    导出签名证书响应
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bSuccess" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ExportSignCert_Rsp,

	/**
	@brief    导出加密证书响应
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bSuccess" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ExportEncCert_Rsp,

	/**
	@brief    设置ftp/telnet限定ip段配置信息的通知
	
	MainBuf(#BOOL32);

	@verbatim
	{
		"bRet": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_FtpTelnet__SetLimitIpCfg_Ntf,

	/**
	@brief    选择串口信息的通知，供网呈使用
	
	MainBuf(#TMtChooseSerialUse_Api);

	@verbatim
	{
		"nSerialType":	1   
		"bIsUse":	1		  
		"nRet":   1           
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ChooseSerialUse_Ntf,

	/**
	@brief    串口信息读写，供网呈使用
	
	MainBuf(#BOOL32);
	MainBuf(#TMtSerialOptParam_Api);

	@verbatim
	{
		      
	}
	@endverbatim
	*/
	Ev_MtApi_Base_OperaterSerial_Ntf,

	/**
    @brief   商密设置许可证是否可用的响应
  
    MainBuf(#BOOL32)
    @verbatim
    {
      "bLicenseIsValidate" : FALSE
    }
    @endverbatim
    */
	Ev_MtApi_Base_DeviceLicenseIsValidate_Rsp,

	/**
    @brief   设置商密 是否启用标准TLS证书的通知
  
    MainBuf(#BOOL32)
    @verbatim
    {
      "bEnable" : FALSE
    }
    @endverbatim
    */
	Ev_MtApi_Base_SetUseTlsCertCfg_Ntf,

	/**
    @brief   设置商密 是否启用国密TLS证书的通知
  
    MainBuf(#BOOL32)
    @verbatim
    {
      "bEnable" : FALSE
    }
    @endverbatim
    */
	Ev_MtApi_Base_SetUseGMTlsCertCfg_Ntf,

	/**
    @brief   获取商密 是否启用标准TLS证书的响应
  
    MainBuf(#BOOL32)
    @verbatim
    {
      "bEnable" : FALSE
    }
    @endverbatim
    */
	Ev_MtApi_Base_GetUseTlsCertCfg_Rsp,

	/**
    @brief   获取商密 是否启用国密TLS证书的响应
  
    MainBuf(#BOOL32)
    @verbatim
    {
      "bEnable" : FALSE
    }
    @endverbatim
    */
	Ev_MtApi_Base_GetUseGMTlsCertCfg_Rsp,

	/**
    @brief   获取SkyShare版本号的响应
  
    MainBuf(#s8*)
    @verbatim
    {
      "basetype" : ""
    }
    @endverbatim
    */
	Ev_MtApi_Base_GetSkyShareVerRt_Rsp,

	/**
	@brief    设置是否显示终端界面时间的回复
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bShow" : FALSE
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetShowMtTimeCfg_Ntf,

	/**
	@brief    获取是否显示终端界面时间的响应
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bShow" : FALSE
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetShowMtTimeCfg_Rsp,


	/**
	@brief    设置登录策略
	
	MainBuf(#TMTLoginStrategy_Api)

	@verbatim
	{
	    "logincount":	1   
	    "waittime":	1		     
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetLoginStrategyCfg_Ntf,

	/**
	@brief    获取登录策略响应
	
	MainBuf(#TMTLoginStrategy_Api)

	@verbatim
	{
	    "logincount":	1   
	    "waittime":	1		     
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetLoginStrategyCfg_Rsp,

	/**
	@brief    导入商密证书的通知
	
	MainBuf(#EmSecCertType_Api)
	SubBuf(#s32)
	@verbatim
	{
		"MainParam": 
		{
			emType:0  //商密证书类型
		}
		"AssParam":
		{
			nRet:0  //0表示成功，非0表示失败
		}
	@endverbatim
	*/
	Ev_MtApi_Base_ImportSecCert_Ntf,

	/**
	@brief    设置待机剩余时间的通知（由OSD设置，用于OSD与网呈IMIX的待机同步）
			  注意:  wSleepRemainTime = 0，表示取消待机

	MainBuf(#u16)
	@verbatim
	{
		wSleepReaminTime: 10   //单位：秒
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetSleepReaminTime_Ntf,

	/**
	@brief    发送本地短消息通知(最大512字节)
	
	MainBuf(#s8[], achLocSms)
	@verbatim
	{
		basetype: "";  
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SendLocalSms_Ntf,

	/**
	@brief    设置是否显示终端Home按钮的回复
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"basetype" : FALSE
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetShowHomeButtonCfg_Ntf,

	/**
	@brief    获取是否显示终端Home按钮的响应
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bShow" : FALSE
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetShowHomeButtonCfg_Rsp,

	/**
	@brief    OSD界面Home按钮按下通知
	
	MainBuf(#no)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_PressHomeButton_Ntf,

	/**	
	@brief    获取无线投屏配对的请求
	
	MainBuf(#TWifiWirelessScreenInfo_Api, tCfg)

	@verbatim
	{
		"dwWirelessScreenDeviceNum" :0,
		"emWirelessScreenState":0,
		"emWirelessScreenErrReason":0
	}
	@endverbatim
	*/
	Ev_MTApi_Base_GetWirelessScreen_Rsp,

	/**	
	@brief    skyshare状态响应,Ev_MtApi_Base_MTCSkyShareLoginState_Ntf
	
	MainBuf(#BOOL32, bloginstate)

	@verbatim
	{
		bloginstate : FALSE
	}
	@endverbatim
	*/
	Ev_MtApi_Base_MTCSkyShareLoginState_Ntf,

	/**
	@brief    设置画面合成是否显示本地硬双流源回复
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bShow" : FALSE
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetShowAssVidInVmpCfg_Ntf,

	/**
	@brief    获取画面合成是否显示本地硬双流源响应
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bShow" : FALSE
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetShowAssVidInVmpCfg_Rsp,

	/**
	@brief    设置网呈控制osd功能的回复
	
	MainBuf(#TMTOrder_Api)
	
	@verbatim
	{

	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetIMIXCtrlOsdFuncCfg_Ntf,

	/**
	@brief    获取网呈控制osd功能的响应
	
	MainBuf(#TMTOrder_Api)
	
	@verbatim
	{

	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetIMIXCtrlOsdFuncCfg_Rsp,

	/**
	@brief   设置终端使用证书类型的回复
	
	MainBuf(#u8)
	
	@verbatim
	{
		byCertType: 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetHttpsCertTypeCfg_Ntf,

	/**
	@brief    获取终端使用证书类型的响应
	
	MainBuf(#u8)
	
	@verbatim
	{
		byCertType: 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetHttpsCertTypeCfg_Rsp,

	/**
	@brief   设置视频编码质量控制类型的回复
	
	MainBuf(#EmVideoQuality_Api)
	
	@verbatim
	{
		emQcMode: 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetVidEncQcModeCfg_Ntf,

	/**
	@brief    请求视频编码质量控制类型的响应
	
	MainBuf(#EmVideoQuality_Api)
	
	@verbatim
	{
		emQcMode: 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetVidEncQcModeCfg_Rsp,

	/**
	@brief   强认证流程结束通知
	
	MainBuf(#TBOOL32, isLocal)\n
	SubBuf(#EmMtCancelAuth_Api, emMtCancelAuth_Api)
	
	@endverbatim
	*/
	Ev_MtApi_Base_StrongAuthEnd_Ntf,

	/**
	@brief    设置是否使用Ipc的通知
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bUseIpc" : 0
	}
	@endverbatim
	*/
    Ev_MtApi_Base_SetIsUseIpcCfg_Ntf,


	/**
	@brief    获取是否使用Ipc通知
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bUseIpc" : 0
	}
	@endverbatim
	*/
    Ev_MtApi_Base_GetIsUseIpcCfg_Rsp,

	/**
	@brief    获取是否使用Ipc通知
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bUseIpc" : 0
	}
	@endverbatim
	*/
    Ev_MtApi_Base_SetVidDecTypeModeCfg_Ntf,

	/**
	@brief    获取是否使用Ipc通知
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bUseIpc" : 0
	}
	@endverbatim
	*/
    Ev_MtApi_Base_GetVidDecTypeModeCfg_Rsp,


	/**
	@brief    设置渠道产品信息的通知
	
	MainBuf(#TAgentInfo_Api)

	@verbatim
	{
		
	}
	@endverbatim
	*/
    Ev_MtApi_Base_SetAgentInfo_Ntf,

	/**
	@brief    获取终端是否支持无线功能的响应
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bIsSupport": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetIsSupportWirelessRt_Rsp,

	/**
	@brief    获取软件完整性自测试响应
	
	MainBuf(#u32)

	@verbatim
	{
		"dwResult" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetSoftIntegritySelfTest_Rsp,

	/**
	@brief    获取软件完整性自测试响应
	
	MainBuf(#u32)

	@verbatim
	{
		"dwResult" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SoftIntegritySelfTest_Ntf,

	/**
	@brief   获取国密算法和随机数自测试
	
	MainBuf(#TGmAndRandomNumTest_Api)

	@verbatim
	{
		"dwListNum" : 0,
		"atGmTestResult" :
		[
		{
			"emEncrypt" : 0,
			"dwErrorCode" : 0,
		}
		]
		dwRandomNumTestResult:0,
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GmAndRandomNumSelfTest_Ntf,

	/**
	@brief    获取国密算法和随机数自测试
	
	MainBuf(#TGmAndRandomNumTest_Api)

	@verbatim
	{
		"dwListNum" : 0,
		"atGmTestResult" :
		[
		{
			"emEncrypt" : 0,
			"dwErrorCode" : 0,
		}
		]
		dwRandomNumTestResult:0,
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetGmAndRandomNumSelfTest_Rsp,

	/**
	@brief    获取设备密钥对一致性自测试
	
	MainBuf(#s32)

	@verbatim
	{
		"dwResult" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetKeyPairConsistencySelfTest_Rsp,

	/**
	@brief   设备密钥对一致性自测试
	
	MainBuf(#s32)

	@verbatim
	{
		"dwResult" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_KeyPairConsistencySelfTest_Ntf,

	/**
	@brief   wifi忘记网络热点响应
	
	MainBuf(#BOOL32)
	SubBuf(#u32)

	@verbatim
	{

	}
	@endverbatim
	*/

	Ev_MtApi_WIFI_SetHotForget_Rsp,

	/**
	@brief    设置量通登录信息
	
	MainBuf(#TMtQtAddr_Api)

	@verbatim
	{
	    "bEnable":	0   
	    "achQtIp":	""
		"dwQtPort": 0
		"achQtUserName": ""
		"achQtPassword": ""
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetQtSettingCfg_Ntf,   

	/**
	@brief    获取量通登录信息
	
	MainBuf(#TMtQtAddr_Api)

	@verbatim
	{
		"bEnable":	0   
		"achQtIp":	""
		"dwQtPort": 0
		"achQtUserName": ""
		"achQtPassword": ""
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetQtSettingCfgCfg_Rsp,


	/**
	@brief   设置量通key更新策略
	
	MainBuf(#TMtSecKeyUpdatePolicy_Api)

	@verbatim
	{
	    "emSecKeyUpdateMode":	0   
	    "dwKeyUpdatePeriod" :	0
		"dwKeyUpdatePackCnt":   0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetQtKeyUpdateModeCfg_Ntf,   

	/**
	@brief    获取量通key更新策略
	
	MainBuf(#TMtSecKeyUpdatePolicy_Api)

	@verbatim
	{
		"emSecKeyUpdateMode":	0   
		"dwKeyUpdatePeriod" :	0
		"dwKeyUpdatePackCnt":   0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetQtKeyUpdateModeCfg_Rsp,

	/**
	@brief   设置指定接口Ethernet的网卡信息结果通知
	
	MainBuf(#u32, dwRet)		 0:成功  其他错误码
	SubBuf(#u32, dwEthernetId)   设置时指定的网口ID

	@verbatim
	{
	}
	@endverbatim
	*/
	Ev_MTApi_Ethernet_SetIpParamResult_Ntf,

	/**
	@brief 会议空闲双流状态通知

	MainBuf(#s32)	
	@verbatim
	{
		basetype: 1   //EmCodecComponent_Api 编码或解码第几路，注意：nCompType=20 表示双流停止
	}
	@endverbatim
	*/ 
	Ev_MtApi_Base_GetMtStreamStatusRt_Rsp,

	/**
	@brief    量通创建是否成功
	
	MainBuf(#u32) 暂时0表示成功， 非0表示失败

	@verbatim
	{
	"basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_QtCreateRes_Ntf,

	/**
	@brief 获取渠道终端license证书信息

	MainBuf(#TMtAgentLicenseInfo_Api)	
	@verbatim
	{
		
	}
	@endverbatim
	*/ 
	Ev_MtApi_Base_GetChannelLicenseRt_Rsp,

	/**
	@brief 更新渠道终端license证书信息的回复

	MainBuf(#TMtAgentLicenseInfo_Api)	
	@verbatim
	{
		
	}
	@endverbatim
	*/ 
	Ev_MtApi_Base_UpdateChannelLicense_Ntf,

	/**
	@brief 登录时动态密码的回复

	MainBuf(#s8 )	
	@verbatim
	{
		"basetype": 1234
	}
	@endverbatim
	*/ 
	Ev_MtApi_Base_GetLoginDynamicPwd_Ntf,
	
	/**
	@brief 参加数据协作动态密码的回复

	MainBuf(#s8 )	
	@verbatim
	{
		"basetype": 1234
	}
	@endverbatim
	*/ 
	Ev_MtApi_Base_GetDataConfDynamicPwd_Ntf,

	/**
	@brief 被其他mtc抢占的通知

	MainBuf(#TMtcBaseInfo_Api tKickInfo )	
	@verbatim
	{
		
	}
	@endverbatim
	*/ 
	Ev_MtApi_Base_HaveBeenKicked_Ntf,
	
	/**
	@brief  获取终端版本号信息的响应

	Buf(#TMtVersionInfo_Api, tVerInfo )
	@verbatim
	{
		
	}
	@endverbatim
	*/ 
	Ev_MtApi_Base_GetMtBaseInfo_Rsp,

	/**	
	@brief    skyshare状态响应,Ev_MtApi_Base_MTCSkyShareLoginState_Rsp
	
	MainBuf(#BOOL32, bloginstate)

	@verbatim
	{
		bloginstate : FALSE
	}
	@endverbatim
	*/
	Ev_MtApi_Base_MTCSkyShareLoginState_Rsp,

	/**	
	@brief    校验数据协作动态口令的结果通知
	
	MainBuf(#BOOL32, bSuccess)

	@verbatim
	{
		bSuccess : FALSE
	}
	@endverbatim
	*/
	Ev_MtApi_Base_CheckDataConfDynamicPwd_Ntf,

	/**	
	@brief    设置VGA输出图像调节通知 
	
	MainBuf(#TMTVgaImgOutAdjustCfg_Api ,tCfg_Api)

	@verbatim
	{
    	"nVga1ImageOffset" : 0,
    	"nVga2ImageOffset" : 0
	}
	@endverbatim
	*/	 
	Ev_MtApi_Base_Hd_SetVGAImgOutAdjust_Ntf,

	/**	
	@brief    获取VGA输出图像调节响应  
	
	MainBuf(#TMTVgaImgOutAdjustCfg_Api ,tCfg_Api)

	@verbatim
	{
	"nVga1ImageOffset" : 0,
	"nVga2ImageOffset" : 0
	}
	@endverbatim
	*/	 
	Ev_MtApi_Base_Hd_GetVGAImgOutAdjust_Rsp,

	/**	
	@brief    清除数据协作动态口令的结果通知 （无消息体）
	
	@verbatim
	{
	}
	@endverbatim
	*/
	Ev_MtApi_Base_CleanDataConfDynamicPwd_Ntf,

	/**	
	@brief   获取真随机数响应
	
	MainBuf(#s8 ,achRand)
	SubBuf(#u16, wLen)		//随机数长度
	@verbatim
	{
		"achRand": "123456"
		wLen    : 6
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetTrueRandBytes_Rsp,


	/**
	@brief    设置是重置密钥是否成功的通知
	
	MainBuf(#u32)

	@verbatim
	{
		"basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ResetSecKey_Ntf,

	/**
	@brief    设置内置摄像机采集制式的通知
	
	MainBuf(#TCameraVidStd_Api)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetCameraVidStd_Ntf,

	/**
	@brief    获取内置摄像机采集制式的响应
	
	MainBuf(#TCameraVidStd_Api)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetCameraVidStd_Rsp,

	/**
	@brief  终端当前已连接的mtc信息列表响应

	Buf(#TMtcBaseInfoList_Api, tMtcList )
	@verbatim
	{
		
	}
	@endverbatim
	*/ 
	Ev_MtApi_Base_GetMtcInfoList_Rsp,


	/**
    @brief   遥控器版本号上报
  
    MainBuf(#s8*)
    @verbatim
    {
      "basetype" : ""
    }
    @endverbatim
    */
	Ev_MtApi_Base_DeviceRemoteCtrlVersion_Ntf,

	/**
    @brief   skyshare登出的通知，此消息是对access重构前的终端 做兼容处理的
  
    MainBuf(#TUserFullInfo_Api， tInfo)
	SubBuf(#achSkyShareIp，achIp )
    
	@verbatim
    {
    }
    @endverbatim
    */
	Ev_MtApi_Base_OldSkyShareLogOut_Ntf,

    /**	
	@brief    设置网管上报日志的文件信息Ntf
	
	MainBuf(#u32, basetype)
	@verbatim
	{
		basetype : 0 (0-成功)
	}
	@endverbatim
	*/

	Ev_MtApi_Base_Agent_SetPackLogInfo_Ntf,

    /**	
	@brief    开始上传日志响应
	
	MainBuf(#u32, basetype)
	@verbatim
	{
		basetype : 0 (0-成功)
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Agent_StartUploadLog_Rsp,


    /**	
	@brief    通知终端打包网管需要的日志
	*/
    Ev_MtApi_Base_Agent_PackLog_Ntf,

	 /**	
	@brief    获取是否为网呈终端的响应
	
	MainBuf(#BOOL32, bIsImixTer)
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetIsImixTer_Rsp,

	/**	
	@brief    恢复出厂设置的通知，对应接口 KdvMt_MTResetCmd
	
	MainBuf(#BOOL32, bDelCfgFile)
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ResetSystem_Ntf,

    /**	
	@brief    设置终端文件打包状态回复
	*/
    Ev_MtApi_Base_Agent_PackFileState_Rsp,

	/**
    @brief   获取SkyMtc版本号的响应
  
    MainBuf(#s8*)
    @verbatim
    {
      "basetype" : ""
    }
    @endverbatim
    */
	Ev_MtApi_Base_GetSkyMtcVer_Rsp,

	/**
    @brief   重置osd管理员密码的 通知，osd收到这个消息后自己去重置密码（没有数据）
  
    MainBuf(#)
    @verbatim
    {
      "basetype" : ""
    }
    @endverbatim
    */
	Ev_MtApi_Base_ResetOsdAdminPwd_Ntf,

	/**
    @brief   获取webmtc (前端)登录状态的响应
  
    MainBuf(#BOOL32, bLogin )
    @verbatim
    {
      
    }
    @endverbatim
    */
	Ev_MtApi_Base_GetWebMtcLoginState_Rsp,

	/**
    @brief   获取webmtc (前端)登录状态的通知
  
    MainBuf(#BOOL32, bLogin )
    @verbatim
    {
      
    }
    @endverbatim
    */
	Ev_MtApi_Base_GetWebMtcLoginState_Ntf,

	/**
    @brief   获取是否正在导出抓包的响应
  
    MainBuf(#BOOL32, bExportingNetCap)
    @verbatim
    {
      
    }
    @endverbatim
    */
	Ev_MtApi_GetIsExportingNetCap_Rsp,

	/**
    @brief   获取默认路由的响应
  
	MainBuf(#TRouteItemInfo_Api , tRouteInfo)
    @verbatim
    {
      
    }
    @endverbatim
    */
	Ev_MtApi_Base_GetDefRoute_Rsp,

    /**
	@brief    查询终端是否注册上dcs响应
	
	MainBuf(#BOOL32)

	@verbatim
	{
        "basetype" : false
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetIsDcsRigistedRt_Rsp,

	/**
	@brief    设置内置摄像机位置的通知
	
	MainBuf(#TCameraLastPos_Api)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetCameraLastPos_Ntf,

	/**
	@brief    获取内置摄像机位置的响应
	
	MainBuf(#TCameraLastPos_Api)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetCameraLastPos_Rsp,

    	/**	
	@brief    APS登陆结果响应Ev_MT_BLL_ApsLoginResult_Ntf
	
	MainBuf(#TMtApsLoginErrcode_Api, tMtApsLoginErrcode)
    SubBuf(#TPlatformInfo_Api, tPlf)

    @verbatim
    {
        "MainParam": 
        {
            "achVersion": string //平台版本号
            "dwIP" : u32         //登陆IP
            "emResourceType": EmResourceType_Api
        }
    }
	*/
	Ev_MtApi_Base_GetAPSPlatformInfo_Rsp,

	/**
	@brief    设置显示丢包闪电图标的通知
	
	MainBuf(#BOOL32, bShow)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetShowLostPkt_Ntf,

	/**
	@brief    获取显示丢包闪电图标的响应
	
	MainBuf(#BOOL32, bShow)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetShowLostPkt_Rsp,

	Ev_MtApi_Base_AiAudState_Ntf,
	Ev_MtApi_Base_AiNotKnow_Ntf,
	Ev_MtApi_Base_AiCreateConf_Ntf,
	Ev_MtApi_Base_AiJoinConf_Ntf,
	Ev_MtApi_Base_AiInviteConf_Ntf,
	Ev_MtApi_Base_AiSelectNum_Ntf,
	Ev_MtApi_Base_AiSendAss_Ntf,
	Ev_MtApi_Base_AiEnSureOrNot_Ntf,
	Ev_MtApi_Base_AiUpDownVolume_Ntf,
	Ev_MtApi_Base_AiProlongConf_Ntf,
	Ev_MtApi_Base_AiEndConf_Ntf,
	Ev_MtApi_Base_AiHangConf_Ntf,
	Ev_MtApi_Base_SetAiInfoCfg_Ntf,
	Ev_MtApi_Base_AiHangUpOrEndConf_Ntf,
	Ev_MtApi_Base_AiGoodBye_Ntf,

	/**
	@brief    设置用户登录密码过期时间的通知
	
	MainBuf(#u32, dwTime)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetUserLoginPwdTimeout_Ntf,

	/**
	@brief    请求用户登录密码过期时间的响应
	
	MainBuf(#u32, dwTime)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetUserLoginPwdTimeout_Rsp,

	/**
	@brief    请求用户登录密码到期时的剩余时间
	
	MainBuf(#u32, dwRestTime)
	MainBuf(#TUserFullInfo_Api, tUserFullInfo)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetUserPwdRestTime_Rsp,

	Ev_MtApi_Base_GetAiInfoCfg_Rsp,

	/**
	@brief    设置是否启用商密功能的通知
	
	MainBuf(#BOOL32)

	@verbatim
	{
        "basetype" : false
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetEnableSecureCfg_Ntf,

	/**
	@brief    获取是否启用商密功能的响应
	
	MainBuf(#BOOL32)

	@verbatim
	{
        "basetype" : false
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetEnableSecureCfg_Rsp,

	/**
	@brief    OSD设置解除用户登录锁定的通知(无消息体)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetUserLoginUnLock_Ntf,

	/**
    @brief   osd获取用户登录锁定状态的响应
  
    MainBuf(#BOOL32, bLock )
    @verbatim
    {
      
    }
    @endverbatim
    */
	Ev_MtApi_Base_GetUserLoginLockState_Rsp,

	/**
    @brief   用户登录锁定状态的通知
  
    MainBuf(#BOOL32, bLock )
    @verbatim
    {
      
    }
    @endverbatim
    */
	Ev_MtApi_Base_GetUserLoginLockState_Ntf,

	Ev_MtApi_Base_AiApplyChair_Ntf,
	Ev_MtApi_Base_AiSelectView_Ntf,

	/**
    @brief  获取摄像机配置
  
    MainBuf(#TMtHDCameraAiList_Api, bLock )
    @verbatim
    {
      
    }
    @endverbatim
    */
	Ev_MtApi_Base_GetAicameraCfg_Rsp,

	/**
	@brief    osd设置快捷键配置通知
	
	MainBuf(#TMtShortCutKeyList_Api, tMtShortCutKeyList)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetShortCutKeyCfg_Ntf,

	/**
	@brief    osd请求快捷键配置的响应
	
	MainBuf(#TMtShortCutKeyList_Api, tMtShortCutKeyList)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetShortCutKeyCfg_Rsp,

	/**
	@brief   跳过设置向导静态图片的通知
	
	MainBuf(#BOOL32, bSkip)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SkipWizardStaticImage_Ntf,

	Ev_MtApi_Base_AiResetTimer_Ntf,

	/**
	@brief    osd重置管理员用户名和密码的响应（无消息体）

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ResetAdminUserInfo_Ntf,

    /**	
	@brief    通知终端开始诊断硬件信息
	*/
    Ev_MtApi_Base_Agent_DevicePerformance_Ntf,

	/**
	@brief    量通呼叫准备密钥失败(目前不用)
	@endverbatim
	*/
	Ev_MtApi_Base_QtPrePareKeyError_Ntf,

	/**
	@brief    检测量子设备是否存在的消息返回 其他状态暂且不问

	MainBuf(#TMtQtUk_Api) 
	@verbatim
	{
		"wRes ": 0
		"bPull": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SecTestQTDevice_Rsp,

	/**
	@brief    设置是否启用OspTelnet调试功能的通知
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetUseOspTelnet_Ntf,
	
	/**
	@brief    请求OspTelnet调试功能启用状态的响应
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetUseOspTelnet_Rsp,

	/**
	@brief    设置是否开启使能数字变焦控制的通知
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetCameraEnableDigZoomCfg_Ntf,
	
	/**
	@brief    获取是否开启使能数字变焦控制的响应
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetCameraEnableDigZoomCfg_Rsp,

	/**
	@brief    设置AI功能图标是否显示的通知
	
	MainBuf(#TMtFunctionIcon_Api, tCfg)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetFunctionIconCfg_Ntf,

	/**
	@brief    获取AI功能图标是否显示的回复
	
	MainBuf(#TMtFunctionIcon_Api, tCfg)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetFunctionIconCfg_Rsp, 

    EV_UI_END(MTAPI_BASE) = EVSEG_MTAPI_BASE_END
};

#define Is_MtApiBase_Msg(m) ((m) >= EV_UI_BGN(MTAPI_BASE) && (m) <= EV_UI_END(MTAPI_BASE))

/**@}*/

/**@}*/
#endif // _MTAPI_EVENT_BASE_H_
