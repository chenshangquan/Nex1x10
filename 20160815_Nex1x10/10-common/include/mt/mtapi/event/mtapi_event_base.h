/*******************************************************************************//**
*@file          mtapi_event_base.h
*@brief         ʵ��MTAPI BaseSdk ��UI(�۲���)�¼�֪ͨ�Ķ���
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_EVENT_BASE_H_
#define _MTAPI_EVENT_BASE_H_
/**@addtogroup event �¼�
*@{
*/

/**@addtogroup baseevent �����¼�
*@{
*/

#include "mtapi_event_def.h"


enum EmMtApiBaseEv
{
	EV_UI_BGN(MTAPI_BASE)  = EV_MTAPI_EVENT_BGN,

	/**
	@brief    �ն˿ͻ����˺���֤Ӧ���Ҷ�Ӧ��Ev_MT_MTCLogin_Rsp	
	
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
	@brief    ����֪ͨ���Ҷ�Ӧ��OSP_DISCONNECT
	*/
	Ev_MtApi_Base_MTDisconnect_Ntf,

	/**	
	@brief    ����û���Ӧ,Ev_MT_MTCAddUser_Rsp
	
	MainBuf(#u32, dwErrCode)

	@verbatim
	{
		"basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_MTCAddUser_Rsp,  
	
	/**	
	@brief����û�֪ͨ, Ev_MT_MTCAddUser_Ntf
	
	MainBuf(#u32, dwCount)

	@verbatim
	{
	    "basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_MTCAddUser_Ntf,
	
	/**	
	@brief    �޸��û���Ӧ,Ev_MT_MTCMUser_Rsp
	
	MainBuf(#u32, dwErrCode)

	@verbatim
	{
	   "basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_MTCMUser_Rsp,
	
	/**		
	@brief    �޸��û�֪ͨ,Ev_MT_MTCMUser_Ntf
	
	MainBuf(#u32, dwCount)

	@verbatim
	{
	   "basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_MTCMUser_Ntf,

	/**		
	@brief    ɾ���û���Ӧ,Ev_MT_MTCDUser_Rsp
	
	MainBuf(#u32, dwErrCode)

	@verbatim
	{
	   "basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_MTCDUser_Rsp,

	/**		
	@brief    ɾ���û�֪ͨ,Ev_MT_MTCDUser_Ntf
	
	MainBuf(#u32, dwCount)

	@verbatim
	{
	    "basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_MTCDUser_Ntf,

	/**	
	@brief    ��ѯ�û���Ӧ,Ev_MT_MTCSUser_Rsp
	
	MainBuf(#u32, dwCount)

	@verbatim
	{
	    "basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_MTCSUser_Rsp,

	/**	
	@brief    ע����Ӧ,Ev_MtApi_Base_MTCLogOut_Ntf
	
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
	@brief    UIͬ��֪ͨ���Ҷ�Ӧ��Ev_Conf_UISynchronize_Ntf
	MainBuf(#s32 ,nReason)

	@verbatim
	{
	"basetype": 0
	}
	@endverbatim
	*/

	Ev_MtApi_Base_UISynchronize_Ntf,

	/**	
	@brief    ���ʹ�������ʱ֪ͨ(��Embed)���Ҷ�Ӧ��Ev_MT_BLL_CodecSleepFailReason_Ntf	
	
	MainBuf(#TS32, tnReason)

	@verbatim
	{
	    "basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SleepFailReason_Ntf,

	/**	
	@brief    ���ʹ�������ʱ֪ͨ(��Embed)���Ҷ�Ӧ��Ev_MT_CodecSleepState_Ntf	
	
	MainBuf(#BOOL32, bInSleep)

	@verbatim
	{
	    "basetype": false
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SleepState_Ntf,

	/**	
	@brief    ���������֪ͨ����Ӧ��Ev_MT_CheckUpgradeResult_Ntf
	
	MainBuf(#u32) �����

	@verbatim
	{
		"basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_CheckUpgradeResult_Ntf,

	/**	
	@brief    ���°汾��Ϣ֪ͨ���Ҷ�Ӧ��Ev_MT_UpgradeVersionInfo_Ntf
	
	MainBuf(#TMTUpgradeVersionInfoList_Api, tUpgradeVerInfoList) �汾��Ϣ

	@verbatim
	{
		"MainParam" :
		{
		    "basetype" : 0, //0��ʾ��ȡ�ɹ�����0��ʾ������
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
	@brief    ���°汾��Ϣ֪ͨ���Ҷ�Ӧ��Ev_MT_UpgradeVersionInfo_Ntf
	
	MainBuf(#TMTUpgradeVersionInfoList_Api, tUpgradeVerInfoList) �汾��Ϣ

	@verbatim
	{
		"MainParam" :
		{
		    "basetype" : 0, //0��ʾ��ȡ�ɹ�����0��ʾ������
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
	@brief    �ļ�����״̬֪ͨ���Ҷ�Ӧ��Ev_MT_UpgradeFileDownloadInfo_Ntf	
	
	MainBuf(#TMTUpgradeDownloadInfo_Api, tDownLoadInfo) ����״̬

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
	@brief    �ļ��������֪ͨ���Ҷ�Ӧ��Ev_MT_UpgradeFileDownloadOk_Ntf
	*/
	Ev_MtApi_Base_UpgradeFileDownloadOk_Ntf,

	/**
	@brief    �����������֪ͨ���Ҷ�Ӧ��Ev_MT_BLL_UpgradeDisconnectServer_Ntf
	*/
	Ev_MtApi_Base_UpgradeDisconnectServer_Ntf,

	/**	
	@brief    ����ϵͳ�ļ�״̬֪ͨ���Ҷ�Ӧ��Ev_MT_UpgradeSysFileUpdateStatus_Ntf
	
	MainBuf(#u32, wResult) �����ļ�״̬������  MT_SUCESS: �ɹ���ʧ�ܴ����룺ERR_UPGRADE_IOS_UPGRADE_FAILED��ERR_UPGRADE_FPGA_UPGRADE_FAILED��
	ERR_UPGRADE_WHOLEUPGRADE_FAILED��ERR_UPGRADE_WHOLEUPGRADE_FAILED��ERR_UPGRADE_FILE_CHECK_FAILED��ERR_UPGRADE_INVALID_FILE

	@verbatim
	{
		"basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_UpgradeSysFileUpdateStatus_Ntf,

	/**	
	@brief    ���U����������Ӧ
	
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
	@brief    ����״̬֪ͨ(��Embed)���Ҷ�Ӧ��Ev_MT_BLL_SleepCountDown_Ntf
	
	MainBuf(#u16, wSleepRemainTime) ����ʣ��ʱ��	

	@verbatim
	{
		"basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SleepCountDown_Ntf,

	/**	
	@brief    ������Ӧ(��Embed)
	
	MainBuf(#BOOL32) �Ƿ�������� \n
	MainBuf(#s32) ����ʧ��ԭ��

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
	@brief    ����ץ��״̬֪ͨ Ev_MT_NetCaptureState_Ntf
	
	MainBuf(#u32)

	@verbatim
	{
	    "basetype": 0 //�����룬��EmNetCapErrcode_Api
	}
	@endverbatim
	*/
	Ev_MtApi_Base_NetCaptureState_Ntf,

	/**	
	@brief    ����ץ���ļ���Ӧ Ev_MT_ExportNetCapture_Rsp
	
	MainBuf(#u32, dwErrCode)

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ExportNetCapture_Rsp,
	
	/**	
	@brief    ������־�ļ�����֪ͨ Ev_MT_ExportLogProgress_Ntf
	
	MainBuf(#u32, dwPercent)

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ExportLogProgress_Ntf,

	/**	
	@brief    ������־�ļ���Ӧ Ev_MT_ExportLog_Rsp
	
	MainBuf(#u32, dwErrCode)

	@verbatim
	{
	    "basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ExportLog_Rsp,

	/**	
	@brief    ��������֪ͨ Ev_MT_BandwidthTestResult_Ntf
	
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
	@brief    �˿�����֪ͨ
	
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
	@brief    ��ȡ�˿�������Ӧ
	
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
	@brief    ��������Ϣ����֪ͨ 
	
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
	@brief    ��ȡ��������Ϣ������Ӧ
	
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
	@brief    ��־����֪ͨ
	
	MainBuf(#BOOL32, bEnableFileLog)

	@verbatim
	{
		"basetype": 0,
	}
	@endverbatim
	*/
	Ev_MtApi_Base_LogStatusCfg_Ntf,

	/**
	@brief    ��ȡ��־������Ӧ
	
	MainBuf(#BOOL32, bEnableFileLog)

	@verbatim
	{
		"basetype": 0,
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetLogStatusCfg_Rsp,

	/**
	@brief    ����qos����֪ͨ
	
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
	@brief    ��ȡqos������Ӧ
	
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
	@brief    ����MTU����֪ͨ
	
	MainBuf(#u32,  dwMtuCfg)

	@verbatim
	{
		"basetype": 0,
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetMTUCfg_Ntf,

	/**
	@brief    ��ȡMTU������Ӧ
	
	MainBuf(#u32,  dwMtuCfg)

	@verbatim
	{
		"basetype": 0,
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetMTUCfg_Rsp,

	/**
	@brief    ����nat����֪ͨ
	
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
	@brief    ��ȡnat������Ӧ
	
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
	@brief    ����xap�б�����֪ͨ
	
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
	@brief    ��ȡxap�б�������Ӧ
	
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
	@brief    ���õ�ǰxap֪ͨ
	
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
	@brief    ��ȡ��ǰxap��Ӧ
	
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
	@brief    ��ȡxmpp��Ϣ��Ӧ
	
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
	@brief    ��ȡNSָ����Ӧ���¼ӣ�
	
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
	@brief    ����CSU����֪ͨ
	
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
	@brief    ��ȡCSU������Ӧ
	
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
	@brief    ����SUS����֪ͨ
	
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
	@brief    ��ȡSUS������Ӧ
	
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
	@brief    ����SUS�ֶ�����֪ͨ
	
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
	@brief    ��ȡSUS�ֶ�������Ӧ
	
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
	@brief    ����NMS����֪ͨ����ӦEv_MT_BLL_SetNMSCfg_Ntf
	
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
	@brief    ��ȡNMS������Ӧ����ӦEv_MT_BLL_GetNMSCfg_Rsp
	
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
	@brief    ����NMS�ֶ�����֪ͨ����ӦEv_MT_BLL_SetNmsManuCfg_Ntf
	
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
	@brief    ��ȡNMS�ֶ�������Ӧ����ӦEv_MT_BLL_GetNmsManuCfg_Rsp
	
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
	@brief    ����NTS����֪ͨ����ӦEv_MT_BLL_SetNTSCfg_Ntf
	
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
	@brief    ��ȡNTS������Ӧ����ӦEv_MT_BLL_GetNTSCfg_Rsp
	
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
	@brief    ����NTS�ֶ�����֪ͨ����ӦEv_MT_BLL_SetNtsManuCfg_Ntf
	
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
	@brief    ��ȡNTS�ֶ�������Ӧ����ӦEv_MT_BLL_GetNtsManuCfg_Rsp
	
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
	@brief    ����NTP����֪ͨ����ӦEv_MT_BLL_SetNTPCfg_Ntf
	
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
	@brief    ��ȡNTP������Ӧ����ӦEv_MT_BLL_GetNTPCfg_Rsp
	
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
	@brief    ����NTP�ֶ�����֪ͨ����ӦEv_MT_BLL_SetNtpManuCfg_Ntf
	
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
	@brief    ��ȡNTP�ֶ�������Ӧ����ӦEv_MT_BLL_GetNtpManuCfg_Rsp
	
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
	@brief    ����VOD����֪ͨ����ӦEv_MT_BLL_SetVODCfg_Ntf
	
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
	@brief    ��ȡVOD������Ӧ����ӦEv_MT_BLL_GetVODCfg_Rsp
	
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
	@brief    ����vrs������֪ͨ����ӦEv_MT_BLL_SetVRSCfg_Ntf
	
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
	@brief    ��ȡvrs��������Ӧ����ӦEv_MT_BLL_GetVRSCfg_Rsp
	
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
	@brief    ��ý������֪ͨ����ӦEv_MT_BLL_SetStreamMediaCfg_Ntf
	
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
	@brief    ��ȡ��ý��������Ӧ����ӦEv_MT_BLL_GetStreamMediaCfg_Rsp
	
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
	@brief    sip����֪ͨ����ӦEv_MT_BLL_SetSipSvrCfg_Ntf
	
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
	@brief    ��ȡsip������Ӧ����Ӧ
	
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
	@brief    ��ȡAPI������������Ӧ�� ��ӦEv_MT_BLL_GetPlatformApiRt_Rsp
	
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
	@brief  Socket5����֪ͨ�� ��ӦEv_MT_BLL_SetSocks5PxyCfg_Ntf
	
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
	@brief  ��ȡSocket5������Ӧ�� ��ӦEv_MT_BLL_GetSocks5PxyCfg_Rsp
	
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
	@brief  �����ն˷�������¼״̬֪ͨ�� ��ӦEv_MT_BLL_SetSvrLoginStatusRt_Ntf
	
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
	@brief  ��ȡ�ն˷�������¼״̬��Ӧ�� ��ӦEv_MT_BLL_GetSvrLoginStatusRt_Rsp
	
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
	@brief  �����ն��û���¼Ȩ������֪ͨ�� ��ӦEv_MT_BLL_SetUserPrevilegeRt_Ntf
	
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
	@brief  ��ȡ�ն��û���¼Ȩ��������Ӧ�� ��ӦEv_MT_BLL_GetUserPrevilegeRt_Rsp
	
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
	@brief  ���õ�½APS���ص��û���Ϣ֪ͨ�� ��ӦEv_MT_BLL_SetUserInfoFromApsRt_Ntf
	
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
	@brief  ��ȡ��½APS���ص��û���Ϣ��Ӧ�� ��ӦEv_MT_BLL_GetUserInfoFromApsRt_Rsp
	
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
	@brief  ����H323������Ϣ��Ӧ֪ͨ�� ��ӦEv_MT_BLL_SetH323Cfg_Ntf
	
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
	@brief  ��ȡH323������Ϣ��Ӧ�� ��ӦEv_MT_BLL_GetH323Cfg_Rsp
	
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
	@brief  ����SIP��������֪ͨ�� ��ӦEv_MT_BLL_SetSipCfg_Ntf
	
	MainBuf(#TMtSipCfg_Api, tMtSipCfg)

	@verbatim
	{
	    "bEnableBfcp" : true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetSipCfg_Ntf,

    /**
	@brief  ��ȡSIP����������Ӧ�� ��ӦEv_MT_BLL_GetSipCfg_Rsp
	
	MainBuf(#TMtSipCfg_Api, tMtSipCfg)

	@verbatim
	{
	    "bEnableBfcp" : true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetSipCfg_Rsp,

    /**
	@brief  ��������MC֪ͨ�� ��ӦEv_MT_BLL_SetMCCfg_Ntf
	
	MainBuf(#BOOL32, bEnableMC)
    {
        "basetype": true
    }
	@endverbatim
	*/	
	Ev_MtApi_Base_SetMCCfg_Ntf,

    /**
	@brief  ��ȡ����MC������Ӧ�� ��ӦEv_MT_BLL_GetMCCfg_Rsp
	
	@verbatim

	MainBuf(#BOOL32 ,bEnableMC)
    {
        "basetype": true
    }
	@endverbatim
	*/	
	Ev_MtApi_Base_GetMCCfg_Rsp,

    /**
	@brief   ��Ƶ����������������֪ͨ�� ��ӦEv_MT_BLL_SetAudVolInCfg_Ntf
	�����ķ�ΧΪ[0,31],��Ӧ���ϲ�Ľ�����

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
	@brief   ��ȡ��Ƶ����������Ӧ�� ��ӦEv_MT_BLL_GetAudVolInCfg_Rsp
	�����ķ�ΧΪ[0,31],��Ӧ���ϲ�Ľ�����

	MainBuf(#u32, dwAudInVol)

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetAudVolInCfg_Rsp,

    /**
	@brief   ������Ƶ���������������֪ͨ�� ��ӦEv_MT_BLL_SetAudVolOutCfg_Ntf
	�����ķ�ΧΪ[0,31],��Ӧ���ϲ�Ľ�����

	MainBuf(#u32 ,dwAudOutVol )

	@verbatim
	{
	    "basetype": 0
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetAudVolOutCfg_Ntf,

    /**
	@brief    ��ȡ��Ƶ�������������Ӧ�� ��ӦEv_MT_BLL_GetAudVolOutCfg_Rsp
	�����ķ�ΧΪ[0,31],��Ӧ���ϲ�Ľ�����

	MainBuf(#u32, dwAudOutVol)

	@verbatim
	{
	    "basetype": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetAudVolOutCfg_Rsp,
 
	/**		
	@brief    �����ش�����,Ev_MT_BLL_SetLostPktResendCfg_Ntf
	
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
	@brief    �����ش�����, Ev_MT_BLL_GetLostPktResendCfg_Rsp
	
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
	@brief    ����������������֪ͨ,��ӦEv_MT_BLL_SetAudioPrecedenceCfg_Ntf
	
	MainBuf(#BOOL32, bCfg)

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetAudioPrecedenceCfg_Ntf,

	/**		
	@brief    ��ȡ������������������Ӧ,��ӦEv_MT_BLL_GetAudioPrecedenceCfg_Rsp
	
	MainBuf(#BOOL32 ,bAudioPreceCfg)

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetAudioPrecedenceCfg_Rsp,
	
	/**		
	@brief    ������Ƶ��ѡ֪ͨ,��ӦEv_MT_BLL_SetAudioPriorCfg_Ntf
	
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
	@brief    ��ȡ��Ƶ����������Ӧ,��ӦEv_MT_BLL_GetAudioPriorCfg_Rsp
	
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
	@brief    ��������Ƶ��ѡ֪ͨ,��ӦEv_MT_BLL_SetPriVidPriorCfg_Ntf
	
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
	@brief     ��ȡ������ѡ������Ӧ,��ӦEv_MT_BLL_GetPriVidPriorCfg_Rsp
	
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
	@brief     ����Pc����Ƶ��ѡ֪ͨ,��ӦemMt_Cfg_PcAssVidPrior
	
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
	@brief      ��ȡPc������������Ӧ,��ӦEv_MT_BLL_GetPcAssVidPriorCfg_Rsp
	
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
	@brief      ����Vid����Ƶ��ѡ֪ͨ,��ӦemMt_Cfg_VidAssVidPrior
	
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
	@brief      ��ȡVid������������Ӧ,��ӦEv_MT_BLL_GetVidAssVidPriorCfg_Rsp
	
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
	@brief      ���ú�����Ϣ֪ͨ,��ӦEv_MT_BLL_SetCallInfoRt_Ntf
	
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
	@brief     ��ȡ������Ϣ������Ӧ,��ӦEv_MT_BLL_GetCallInfoRt_Rsp
	
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
	@brief      ������ϯ������������֪ͨ,��ӦEv_MT_BLL_SetChrmanOperateCfg_Ntf
	
	MainBuf(#BOOL32 ,bEnableChairmanOptCfg )

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetChrmanOperateCfg_Ntf,

	/**		
	@brief      ��ȡ��ϯ��������������Ӧ,��ӦEv_MT_BLL_GetChrmanOperateCfg_Rsp
	
	MainBuf(#BOOL32 ,bEnableChairmanOptCfg)

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetChrmanOperateCfg_Rsp,

	/**		
	@brief     �����Ƿ����״̬��ʾ��������,��ӦEv_MT_BLL_SetShowConfStateCfg_Ntf
	
	MainBuf(#BOOL32 ,bShowConfStateCfg )

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetShowConfStateCfg_Ntf,

	/**		
	@brief     ��ȡ����״̬��ʾ����������Ӧ,��ӦEv_MT_BLL_GetShowConfStateCfg_Rsp
	
	MainBuf(#BOOL32, bShowConfStateCfg)

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetShowConfStateCfg_Rsp,

	/**	
	@brief    �����Զ����л�����Ӧ��Ev_MT_BLL_SetStaticPicCfg_Ntf
	
	MainBuf(#BOOL32, bSend)

	@verbatim
	{
		"basetype": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetStaticPicCfg_Ntf,

	/**	
	@brief    �����Զ����л�����Ӧ��Ev_MT_BLL_GetStaticPicCfg_Rsp
	
	MainBuf(#BOOL32, bSend)

	@verbatim
	{
		"basetype": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetStaticPicCfg_Rsp,
	
	/**	
	@brief    �����Ƿ����õ绰�������������Ӧ��Ev_MT_BLL_SetTelephoneCfg_Ntf
	
	MainBuf(#BOOL32 ,bIsUsedTelphone)

	@verbatim
	{
		"basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetTelephoneCfg_Ntf,

	/**	
	@brief    ��ȡ���õ绰��������������Ӧ����Ӧ��Ev_MT_BLL_GetTelephoneCfg_Rsp
	
	MainBuf(#BOOL32 ,bIsUsedTelphone)

	@verbatim
	{
		"basetype": true
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetTelephoneCfg_Rsp,

	/**	
	@brief    �����Զ��������������Ӧ��Ev_MT_BLL_SetAutoCallCfg_Ntf
	
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
	@brief    ��ȡ�Զ������������󣬶�Ӧ��Ev_MT_BLL_GetAutoCallCfg_Rsp
	
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
	@brief   �����Ƿ��Զ���¼���������������Ӧ��Ev_MT_BLL_SetAutoLoginCfg_Ntf
	
	MainBuf(#BOOL32, bAutoLoginCfg)

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetAutoLoginCfg_Ntf,

	/**	
	@brief   ��ȡ�Զ���¼����������������Ӧ����Ӧ��Ev_MT_BLL_GetAutoLoginCfg_Rsp
	
	MainBuf(#BOOL32, bAutoLoginCfg)

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetAutoLoginCfg_Rsp,

	/**	
	@brief   ���÷ǶԳ��������������Ӧ��Ev_MT_BLL_SetAsymmetricNetCfg_Ntf
	
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
	@brief   ��ȡ�ǶԳ���������������Ӧ����Ӧ��Ev_MT_BLL_GetAsymmetricNetCfg_Rsp
	
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
	@brief   �����Ƿ������������ǽ���������Ӧ��Ev_MT_BLL_SetUseCallFWCfg_Ntf
	
	MainBuf(#BOOL32, bEnableCallFWCfg )

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetUseCallFWCfg_Ntf,

	/**	
	@brief   ��ȡ�������ǽ����������Ӧ����Ӧ��Ev_MT_BLL_GetUseCallFWCfg_Rsp
	
	MainBuf(#BOOL32, bEnableCallFWCfg)

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetUseCallFWCfg_Rsp,

	/**	
	@brief   ���õ�ǰ�Ƿ����ô��������������Ӧ��Ev_MT_BLL_SetBandWidthTestCfg_Ntf
	
	MainBuf(#BOOL32, bEnableBWTestCfg )

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetBandWidthTestCfg_Ntf,

	/**	
	@brief   ��ȡ��ǰ�Ƿ����ô������������󣬶�Ӧ��Ev_MT_BLL_GetBandWidthTestCfg_Rsp
	
	MainBuf(#BOOL32, bEnableBWTestCfg)

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetBandWidthTestCfg_Rsp,

	/**	
	@brief   ��������MC�����ش��������������Ӧ��Ev_MT_BLL_SetMCResendParamCfg_Ntf
	
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
	@brief   ��ȡ����MC�����ش���������������Ӧ����Ӧ��Ev_MT_BLL_GetMCResendParamCfg_Rsp
	
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
	@brief   ��ȡ����MC�����ش���������������Ӧ����Ӧ��Ev_MT_BLL_GetMCResendParamCfg_Rsp
	
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
	@brief   ��ȡ����MC�����ش���������������Ӧ����Ӧ��Ev_MT_BLL_GetAssVideoParamCfg_Rsp
	
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
	@brief   �����Ƿ������Զ�˫��Դ���������Ӧ��Ev_MT_BLL_SetDualStramSrcAdjCfg_Ntf
	
	MainBuf(#BOOL32, bEnableAssStreamSrcCfg )

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetDualStramSrcAdjCfg_Ntf,

	/**	
	@brief   ��ȡ�Զ�˫��Դ�������󣬶�Ӧ��Ev_MT_BLL_GetDualStramSrcAdjCfg_Rsp
	
	MainBuf(#BOOL32, bEnableAssStreamSrcCfg)

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetDualStramSrcAdjCfg_Rsp,

	/**	
	@brief   ���ú���Э���������������Ӧ��Ev_MT_BLL_SetCallProtocolCfg_Ntf
	
	MainBuf(#EmConfProtocol_Api, emCallProtocol)

	@verbatim
	{
	    "emCallProtocol":enum
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetCallProtocolCfg_Ntf,

	/**	
	@brief    ��ȡ����Э����������������Ӧ����Ӧ��Ev_MT_BLL_GetCallProtocolCfg_Rsp
	
	MainBuf(#EmConfProtocol_Api ,emCallProtocol)

	@verbatim
	{
	     "m_emCallProtocol":enum
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetCallProtocolCfg_Rsp,

	/**	
	@brief    ���ü������������Ӧ��Ev_MT_BLL_SetEncryptTypeCfg_Ntf
	
	MainBuf(#EmEncryptArithmetic_Api, emEncrypt )

	@verbatim
	{
	    "emEncrypt":enum
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetEncryptTypeCfg_Ntf,

	/**	
	@brief    ��ȡ�����������������Ӧ����Ӧ��Ev_MT_BLL_GetEncryptTypeCfg_Rsp
	
	MainBuf(#EmEncryptArithmetic_Api, emEncrypt)

	@verbatim
	{
        "m_emEncrypt":enum
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetEncryptTypeCfg_Rsp,

	/**	
	@brief    ���ö������ʱ��������(��)����Ӧ��Ev_MT_BLL_SetKeepAliveItrvlCfg_Ntf
	
	MainBuf(#u32 ,dwKeepAliveItv )

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetKeepAliveItrvlCfg_Ntf,

	/**	
	@brief    ��ȡ�������ʱ�����������󣬶�Ӧ��Ev_MT_BLL_GetKeepAliveItrvlCfg_Rsp
	
	MainBuf(#u32 ,dwKeepAliveItv)

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetKeepAliveItrvlCfg_Rsp,

	
	/**	
	@brief    ���ö������ʱ��������(��)����Ӧ��Ev_MT_BLL_SetSipKeepAliveItrvlCfg_Ntf
	
	MainBuf(#u32 ,dwKeepAliveItv )

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetSipKeepAliveItrvlCfg_Ntf,

	/**	
	@brief    ��ȡ�������ʱ�����������󣬶�Ӧ��Ev_MT_BLL_GetSipKeepAliveItrvlCfg_Rsp
	
	MainBuf(#u32 ,dwKeepAliveItv)

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetSipKeepAliveItrvlCfg_Rsp,

	/**	
	@brief    ����FEC���������Ӧ��Ev_MT_BLL_SetFECCfg_Ntf
	
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
	@brief    ��ȡ����FEC�������󣬶�Ӧ��Ev_MT_BLL_GetFECCfg_Rsp
	
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
	@brief    ���ø��е͵��Ļ���������������(С��64�����Ǵ���Ƶ����)����Ӧ��Ev_MT_BLL_SetCallRateLvCfg_Ntf
	
	MainBuf(#u32 ,dwCallRate)

	@verbatim
	{
	     "basetype": 0 
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetCallRateLvCfg_Ntf,

	/**	
	@brief     ��ȡ���е͵��Ļ���������������(С��64�����Ǵ���Ƶ����)��Ӧ����Ӧ��Ev_MT_BLL_GetCallRateLvCfg_Rsp
	
	MainBuf(#u32 ,dwCallRateLevel)

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetCallRateLvCfg_Rsp,

	/**		
	@brief   ˫�����ͱ���, ��ӦEv_MT_BLL_SetVidBitRationCfg_Ntf
	
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
	@brief   ˫�����ͱ��ʣ���ӦEv_MT_BLL_GetVidBitRationCfg_Rsp
	
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
	@brief  �����ն˰汾���������Ϣ����ӦEv_MT_BLL_SetTerlInfoRt_Ntf
	
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
	@brief  ��ȡ�ն˰汾��Ϣ��������(RT)��Ӧ����ӦEv_MT_BLL_GetTerlInfoRt_Rsp
	
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
	@brief  �����ն�������Ϣ���������ӦEv_MT_BLL_SetUserNameCfg_Ntf
	
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
	@brief  ��ȡ�ն�������Ϣ����������Ӧ����ӦEv_MT_BLL_GetUserNameCfg_Rsp
	
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
	@brief   ��ʼ�ն˷��񣬶�ӦEv_MT_BLL_SrvStartResult_Ntf
	
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
	@brief   ֹͣ�ն˷��񣬶�ӦEv_MT_BLL_SrvEndtResult_Ntf
	
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
	@brief   ����Ӧ��ģʽ���������ӦEv_MT_BLL_SetAnswerModeCfg_Ntf
	
	MainBuf(#u32, dwAnswerMode )

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/	   
	Ev_MtApi_Base_SetAnswerModeCfg_Ntf,

	/**		
	@brief    ��ȡӦ��ģʽ������Ӧ����ӦEv_MT_BLL_GetAnswerModeCfg_Req
	
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
	@brief    ���ú�����������֪ͨ
	
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
	@brief    ��ȡ��������������Ӧ
	
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
	@brief    �����Զ��������ݹ�����ӦEv_MT_BLL_SetAutoSendSharedContentCfg_Ntf
	
	MainBuf(#BOOL32, bAuto)

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetAutoSendSharedContentCfg_Ntf,

	/**
	@brief    ��ȡ�Զ��������ݹ�����ӦEv_MT_BLL_GetAutoSendSharedContentCfg_Rsp
	
	MainBuf(#BOOL32 ,bAutoSendSharedContent)

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetAutoSendSharedContentCfg_Rsp,

	/**
	@brief    �����Ƿ������½ƽ̨���񣬶�ӦEv_MT_BLL_SetLoginPlatformSrvCfg_Ntf
	
	MainBuf(#BOOL32, bLogin )

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetLoginPlatformSrvCfg_Ntf,

	/**
	@brief    ��ȡ�Ƿ������½ƽ̨���񣬶�ӦEv_MT_BLL_GetLoginPlatformSrvCfg_Rsp
	
	MainBuf(#BOOL32 ,bLoginPlatformSrv)

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetLoginPlatformSrvCfg_Rsp,

	/**
	@brief   ����ƽ�����͵ȼ�����ӦwParam(u32, dwSmooth )
	
	MainBuf(#u32 ,dwSmoothSendLevel)

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetSmoothSendCfg_Ntf,

	/**
	@brief   ��ȡƽ�����͵ȼ���Ӧ����ӦEv_MT_BLL_GetSmoothSendCfg_Rsp
	
	MainBuf(#u32, dwSmoothSendLevel)

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetSmoothSendCfg_Rsp,

	/**
	@brief   ����telnet���أ���ӦEv_MT_BLL_SetUseTelnetCfg_Ntf
	
	MainBuf(#BOOL32, bUsed )

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetUseTelnetCfg_Ntf,

	/**
	@brief   ��ȡtelnet����������Ӧ����ӦEv_MT_BLL_GetUseTelnetCfg_Rsp
	
	MainBuf(#BOOL32, bUseTelnet )

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetUseTelnetCfg_Rsp,

	/**
	@brief   ����Http���أ���ӦEv_MT_BLL_SetUseHTTPCfg_Ntf
	
	MainBuf(#BOOL32, bUsed )

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetUseHTTPCfg_Ntf,

	/**
	@brief   ��ȡHttp����������Ӧ����ӦEv_MT_BLL_GetUseHTTPCfg_Rsp
	
	MainBuf(#BOOL32, bUseHTTP )

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetUseHTTPCfg_Rsp,

	/**
	@brief   ����FTP���أ���ӦEv_MT_BLL_SetUseFtpCfg_Ntf
	
	MainBuf(#BOOL32, bUsed  )

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetUseFtpCfg_Ntf,

	/**
	@brief   ��ȡFTP����������Ӧ����ӦEv_MT_BLL_GetUseFtpCfg_Rsp
	
	MainBuf(#BOOL32 ,bUseFtp)

	@verbatim
	{
         "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetUseFtpCfg_Rsp,

	/**
	@brief   ����API������������Ϣ����ӦEv_MT_BLL_SetPlatformApiRt_Ntf
	
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
	@brief   ����΢��������������Ϣ����ӦEv_MT_BLL_SetMicroBlogRt_Ntf
	
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
	@brief   ��ȡ΢����������ַ��Ӧ����ӦEv_MT_BLL_GetMicroBlogRt_Rsp
	
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
	@brief   ���õ�¼���ԣ���ʱ���ã�����ӦEv_MT_BLL_SetSvrLoginTacticsCfg_Ntf
	
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
	@brief   ��ȡ��¼������Ӧ����ӦEv_MT_BLL_GetSvrLoginTacticsCfg_Rsp
	
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
	@brief   �����Զ��������ƣ���ӦEv_MT_BLL_SetAnsCfg_Ntf
	
	MainBuf(#BOOL32 ,bAns )

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetAnsCfg_Ntf,

	/**
	@brief  ��ȡ�Զ�������������������Ӧ����ӦEv_MT_BLL_GetAnsCfg_Rsp
	
	MainBuf(#BOOL32, bAns)

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetAnsCfg_Rsp,

	/**
	@brief  �����Զ�������ƣ���ӦEv_MT_BLL_SetAgcCfg_Ntf
	
	MainBuf(#BOOL32, bAgc )

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetAgcCfg_Ntf,

	/**
	@brief  ��ȡ�Զ������������������Ӧ����ӦEv_MT_BLL_GetAgcCfg_Rsp
	
	MainBuf(#BOOL32, bAgc)

	@verbatim
	{
	    "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetAgcCfg_Rsp,


	/**
	@brief  �����Զ�������������ӦEv_MT_BLL_SetAecCfg_Ntf
	
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
	@brief  ��ȡ�Զ�����������Ӧ����ӦEv_MT_BLL_GetAnsCfg_Rsp
	
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
	@brief  ����MC��Ϣ����ӦEv_MT_BLL_SetMCInfoRt_Ntf
	
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
	@brief  ��ȡMC������Ӧ����ӦEv_MT_BLL_GetMCInfoRt_Rsp
	
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
	@brief  ����ͨ����Ϣ����ӦEv_MT_BLL_SetChanInfoRt_Ntf
	
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
	@brief  ��ȡͨ����Ϣ������Ӧ����ӦEv_MT_BLL_GetChanInfoRt_Rsp
	
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
	@brief  ���õ�¼���룬��ӦEv_MT_BLL_SetLoginPwdCfg_Ntf
	
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
	@brief  ��ȡ��¼����������Ӧ����ӦEv_MT_BLL_GetLoginPwdCfg_Rsp
	
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
	@brief  �����豸�ͺţ���ӦEv_MT_BLL_SetModelCfg_Ntf
	*/	
	Ev_MtApi_Base_SetModelCfg_Ntf,

	/**
	@brief  ��ȡ�豸�ͺţ���ӦEv_MT_BLL_GetModelCfg_Rsp
	*/	
	Ev_MtApi_Base_GetModelCfg_Rsp,

	/**
	@brief  ����ϵͳ����״̬����ӦEv_MT_BLL_SetSysUpgradeRt_Ntf
	
	MainBuf(#BOOL32 ,bSysUpgrade)

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetSysUpgradeRt_Ntf,

	/**
	@brief   ��ȡϵͳ����״̬������Ӧ����ӦEv_MT_BLL_GetSysUpgradeRt_Rsp
	
	MainBuf(#BOOL32 ,m_bSysUpgrade)

	@verbatim
	{
	     "basetype": true
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetSysUpgradeRt_Rsp,

	/**
	@brief   ���û���ʹ�õĶ˿ڣ���ӦEv_MT_BLL_SetConfUsedPortsRt_Ntf
	
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
	@brief    ��ȡ����ʹ�õĶ˿�������Ӧ����ӦEv_MT_BLL_GetConfUsedPortsRt_Rsp
	
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
	@brief    ����MCʹ�õĶ˿ڣ���ӦEv_MT_BLL_SetMcUsedPortsRt_Ntf
	
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
	@brief   ��ȡMCʹ�õĶ˿�������Ӧ����ӦEv_MT_BLL_GetMcUsedPortsRt_Rsp
	
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
	@brief   ����Vodʹ�õĶ˿ڣ���ӦEv_MT_BLL_SetVodUsedPortsRt_Ntf
	
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
	@brief    ��ȡVodʹ�õĶ˿���Ӧ����ӦEv_MT_BLL_GetVodUsedPortsRt_Rsp
	
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
	@brief   ����Imʹ�õĶ˿ڣ���ӦEv_MT_BLL_SetImUsedPortsRt_Ntf
	
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
	@brief    ��ȡImʹ�õĶ˿�������Ӧ����ӦEv_MT_BLL_GetImUsedPortsRt_Rsp
	
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
	@brief   ���õ�¼IM����Ҫ�Ĳ�������ӦEv_MT_BLL_SetLoginIMParamCfg_Ntf
	
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
	@brief  ��ȡ��¼IM����Ҫ�Ĳ���������Ӧ����ӦEv_MT_BLL_GetLoginIMParamCfg_Rsp
	
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
	@brief  ���õ�¼APS����Ҫ�Ĳ�������ӦEv_MT_BLL_SetApsLoginParamCfg_Ntf
	
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
	@brief  ��ȡ��¼APS����Ҫ�Ĳ���������Ӧ����ӦEv_MT_BLL_GetApsLoginParamCfg_Rsp
	
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
	@brief  ���ã���ӦEv_MT_BLL_SetSusLoginParamCfg_Ntf
	
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
	@brief  ���ô�����ӦEv_MT_BLL_SetBandWidthRt_Ntf
	
	MainBuf(#TMTNetStatus_Api��tMTNetStatus)

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
	@brief    �������� ��ӦEv_MT_BLL_GetBandWidthRt_Rsp
	
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
	@brief    ��������ʱӳ���, ��ӦEv_MT_BLL_SetSysCtrlSrvInfoRt_Ntf
	
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
	@brief     ��ȡϵͳ����ӳ�������, ��ӦEv_MT_BLL_GetSysCtrlSrvInfoRt_Rsp
	
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
	@brief     ��ϵͳ����, ��ӦEv_MT_BLL_SetSysCtrlSrvNumRt_Ntf
	
	MainBuf(#u32, dwSysCtrlSrvNum)

	@verbatim
	{
	    "basetype": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetSysCtrlSrvNumRt_Ntf,

	/**	
	@brief      ��ȡ����ʱӳ�����ģ���������, ��ӦEv_MT_BLL_GetSysCtrlSrvNumRt_Rsp
	
	MainBuf(#u32, dwSysCtrlSrvNum)

	@verbatim
	{
	    "basetype": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetSysCtrlSrvNumRt_Rsp,

	/**	
	@brief     ����Ĭ������ӳ���, ��ӦEv_MT_BLL_SetSysCtrlDefSrvInfoCfg_Ntf
	
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
	@brief      ��ȡĬ������ӳ�������, ��ӦEv_MT_BLL_GetSysCtrlDefSrvInfoCfg_Rsp
	
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
	@brief      ����Ĭ��ӳ�����ģ�����, ��ӦEv_MT_BLL_SetSysCtrlDefSrvNumCfg_Ntf
	
	MainBuf(#u32 ,dwSysCtrlDefSrvNum )

	@verbatim
	{
	    "basetype": 0
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_SetSysCtrlDefSrvNumCfg_Ntf,
	
	/**	
	@brief      ��ȡĬ��ӳ�����ģ�����������Ӧ, ��ӦEv_MT_BLL_GetSysCtrlDefSrvNumCfg_Rsp
	
	MainBuf(#u32, dwSysCtrlDefSrvNum)

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/		
	Ev_MtApi_Base_GetSysCtrlDefSrvNumCfg_Rsp,

     /**
	@brief ��ȡĬ��ӳ�����ģ�����������Ӧ, ��ӦEv_MT_BLL_SetSatelliteCfg_Ntf
	*/ 
	Ev_MtApi_Base_SetSatelliteCfg_Ntf,


    /**
	@brief ��ȡ�Ƿ������ն�������Ӧ, ��ӦEv_MT_BLL_GetSatelliteCfg_Rsp
	*/    
	Ev_MtApi_Base_GetSatelliteCfg_Rsp,

	/**	
	@brief     ����323Э��ջ�����˿�, ��ӦEv_MT_BLL_SetH323CallingPortRt_Ntf
	
	MainBuf(# u16, wH323CallingPort )

	@verbatim
	{
    	 "basetype": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_SetH323CallingPortRt_Ntf,

	/**	
	@brief     ��ȡ323Э��ջ�����˿�������Ӧ, ��ӦEv_MT_BLL_GetH323CallingPortRt_Rsp
	
	MainBuf(#u16, wH323CallingPort)

	@verbatim
	{
	     "basetype": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetH323CallingPortRt_Rsp,

	/**	
	@brief      ����H460����֪ͨ, ��ӦEv_MT_BLL_SetH460Cfg_Ntf
	
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
	@brief      ��ȡH460����������Ӧ, ��ӦEv_MT_BLL_GetH460Cfg_Rsp
	
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
	@brief       H323��������, ��ӦEv_MT_BLL_SetH323PxyCfg_Ntf
	
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
	@brief       ��ȡH323��������������Ӧ, ��ӦEv_MT_BLL_GetH323PxyCfg_Rsp
	
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
	@brief      Meeting����������, ��ӦEv_MT_BLL_SetMeetingCtrlRt_Ntf
	
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
	@brief      ��ȡMeeting��������Ӧ, ��ӦEv_MT_BLL_GetMeetingCtrlRt_Rsp
	
	MainBuf(#TMtMeetingSvrAddr_Api, tMeetingSvrAddr)

	@verbatim
	{
	    "achDomain" : "", 
	    "dwIp"     : 2 
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_GetMeetingCtrlRt_Rsp,

	/*********************Ӳ�ն˲�Ʒ��ʼ********************/
	/***********�û�����**************/
	/**	
	@brief      ����˫����ʾģʽ, ��ӦEv_MT_BLL_HD_SetDispModeCfg_Ntf  
	
	MainBuf(#EmDualVideoShowMode_Api, emCfg_Api )

	@verbatim
	{
	    "emCfg_Api":0 
	}
	@endverbatim
	*/		          
	Ev_MtApi_Base_Hd_SetDispModeCfg_Ntf,

	/**	
	@brief      ��ȡ˫����ʾģʽ����, ��ӦEv_MT_BLL_HD_GetDispModeCfg_Rsp   
	MainBuf(EmDualVideoShowMode_Api ,emDualShowMd)
	{
	    "m_emDualShowMd":0 
	}
	@endverbatim
	*/	         		
	Ev_MtApi_Base_Hd_GetDispModeCfg_Rsp,

	/**	
	@brief      ������Ƶ�����ʽ, ��ӦEv_MT_BLL_HD_SetHDResOutputCfg_Ntf 
	
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
	*/		         	//��Ƶ�����ʽ(value: THDMTVideoOutPortMode_Api )
	Ev_MtApi_Base_Hd_SetHDResOutputCfg_Ntf,

	/**	
	@brief      ��ȡ��Ƶ�����ʽ������Ӧ, ��ӦEv_MT_BLL_HD_GetHDResOutputCfg_Rsp   
	
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
	*/	             	//��Ƶ�����ʽ(value: THDMTVideoOutPortMode_Api )
	Ev_MtApi_Base_Hd_GetHDResOutputCfg_Rsp,

	/**	
	@brief    �����Զ����л�����Ӧ��Ev_MT_BLL_HD_SetAutoPIPCfg_Ntf
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		"bUse": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetAutoPIPCfg_Ntf,

	/**	
	@brief    �����Զ����л�����Ӧ��Ev_MT_BLL_HD_GetAutoPIPCfg_Rsp
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		"bUse": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetAutoPIPCfg_Rsp,

	/**	
	@brief    ������������Ӧ��Ev_MT_BLL_HD_SetCallInRingCfg_Ntf
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetCallInRingCfg_Ntf,

	/**	
	@brief    ������������Ӧ��Ev_MT_BLL_HD_GetCallInRingCfg_Rsp
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetCallInRingCfg_Rsp,
	
	/**	
	@brief    ������������Ӧ��Ev_MT_BLL_HD_SetCallOutRingCfg_Ntf
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetCallOutRingCfg_Ntf,
	
	/**	
	@brief    ������������Ӧ��Ev_MT_BLL_HD_GetCallOutRingCfg_Rsp
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetCallOutRingCfg_Rsp,
	
	/**	
	@brief    ��ǰʹ�õĺ��id��,Ev_MT_BLL_HD_SetEnablePresetBannerCfg_Ntf 
	
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
	@brief    ��ǰʹ�õĺ��id��,Ev_MT_BLL_HD_GetEnablePresetBannerCfg_Rsp   
	
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
	@brief    �������,Ev_MT_BLL_HD_SetBannerInfoCfg_Ntf  
	
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
	@brief    �������,Ev_MT_BLL_HD_GetBannerInfoCfg_Rsp  
	
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
	@brief    mtc�������  
	
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
	@brief    mtc�������  
	
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
	@brief    Ev_MT_BLL_HD_SetLabelInfoCfg_Ntf    ̨������
	
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
	@brief    Ev_MT_BLL_HD_GetLabelInfoCfg_Rsp ̨������
	
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
	@brief    Ev_MT_BLL_HD_SetAutoSleepCfg_Ntf   �Զ�����
	
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
	@brief    Ev_MT_BLL_HD_GetAutoSleepCfg_Rsp   �Զ�����
	
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
	@brief    ʱ������֪ͨ ��ӦEv_MT_BLL_HD_SetSysTimeCfg_Ntf
	
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
	@brief    ��ȡʱ��������Ӧ ��ӦEv_MT_BLL_HD_GetSysTimeCfg_Rsp
	
	MainBuf(#THDMTCfgSystemTime_Api, tHDMTCfgSystemTime)

	@verbatim
	{
	    "bSyncServer" : true,			
	    "emTimeZoneType" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetSysTimeCfg_Rsp,

	/***********����Ա����**********/
	
	/**	
	@brief    ������棬��Ӧ��Ev_MT_BLL_HD_SetMicGainCfg_Ntf
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetMicGainCfg_Ntf,
	
	/**	
	@brief    ������棬��Ӧ��Ev_MT_BLL_HD_GetMicGainCfg_Rsp
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_GetMicGainCfg_Rsp,
	
	/**	
	@brief    ������������Ӧ����Ӧ��Ev_MT_BLL_HD_SetAecDebugCfg_Ntf	
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetAecDebugCfg_Ntf,
	
	/**	
	@brief    ������������Ӧ����Ӧ��Ev_MT_BLL_HD_GetAecDebugCfg_Rsp
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetAecDebugCfg_Rsp,

	/**	
	@brief    Ev_MT_BLL_HD_SetAudInPortListCfg_Ntf     ����Ƶ����ӿ�
	
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
	@brief    Ev_MT_BLL_HD_GetAudInPortListCfg_Rsp    ����Ƶ����ӿ�
	
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
	@brief    ��Ƶ����ӿ�֪ͨ,Ev_MT_BLL_HD_SetAudOutPortListCfg_Ntf
	
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
	@brief    ��ȡ��Ƶ����ӿ���Ӧ,Ev_MT_BLL_HD_GetAudOutPortListCfg_Rsp
	
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
	@brief    ���õ�һ·����Ƶ����˿�(value: THDMTHDVidInPort_Api ),Ev_MT_BLL_HD_SetPri1stVidInPortCfg_Ntf
	
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
	@brief    ��ȡ��һ·����Ƶ����˿�������Ӧ(value: THDMTHDVidInPort_Api ),Ev_MT_BLL_HD_GetPri1stVidInPortCfg_Rsp   
	
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
	@brief    ���õڶ�·����Ƶ����˿ڶ˿�(value: THDMTHDVidInPort_Api ),Ev_MT_BLL_HD_SetPri2ndVidInPortCfg_Ntf       
	
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
	@brief    ��ȡ�ڶ�·����Ƶ����˿ڶ˿���Ӧ(value: THDMTHDVidInPort_Api ),Ev_MT_BLL_HD_GetPri2ndVidInPortCfg_Rsp    
	
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
	@brief    ���ø���Ƶ����˿�֪ͨ(value: THDMTHDVidInPort_Api ),Ev_MT_BLL_HD_SetAssVidInPortCfg_Ntf     
	
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
	@brief    ��ȡ����Ƶ����˿���Ӧ(value: THDMTHDVidInPort_Api ),Ev_MT_BLL_HD_GetAssVidInPortCfg_Rsp    
	
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
	@brief    ���ö��ӻ����֪ͨ,Ev_MT_BLL_HD_SetMultiVideoCfg_Ntf
	
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
	@brief    ���ö��ӻ������Ӧ,Ev_MT_BLL_HD_GetMultiVideoCfg_Rsp
	
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
	@brief    ����Ƶ��һ·��ʾ����,Ev_MT_BLL_HD_SetMainFstDisplayRatioCfg_Ntf
	
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
	@brief    ���ý����Ӻڱߡ��ñ���ǵȱȵ���Ƶ�������
	
	MainBuf(#TMTResizeMode_Api)

	@verbatim
	{
		"emResizeMode" : 1
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetResizeModeCfg_Ntf,

	/**		
	@brief    ���ý����Ӻڱߡ��ñ���ǵȱȵ���Ƶ�������
	
	MainBuf(#TMTResizeMode_Api)

	@verbatim
	{
		"emResizeMode" : 1
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetResizeModeCfg_Rsp,

	/**	
	@brief    ����Ƶ��һ·��ʾ����,Ev_MT_BLL_HD_GetMainFstDisplayRatioCfg_Rsp
	
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
	@brief    ����Ƶ�ڶ�·��ʾ����,Ev_MT_BLL_HD_SetMainSecDisplayRatioCfg_Ntf
	
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
	@brief    ����Ƶ�ڶ�·��ʾ����,Ev_MT_BLL_HD_GetMainSecDisplayRatioCfg_Rsp
	
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
	@brief    ����Ƶ��ʾ����,Ev_MT_BLL_HD_SetAssDisplayRatioCfg_Ntf
	
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
	@brief    ����Ƶ��ʾ����,Ev_MT_BLL_HD_GetAssDisplayRatioCfg_Rsp
	
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
	@brief    ��Ƶ����,Ev_MT_BLL_HD_SetVideoMatrixSchemeCfg_Ntf
	
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
	@brief    ��Ƶ����,Ev_MT_BLL_HD_GetVideoMatrixSchemeCfg_Rsp
	
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
	@brief   ��ͼ����ʾ����,Ev_MT_BLL_HD_SetLastDisplayCfg_Ntf  
	
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
	@brief   ��ȡ��ͼ����ʾ������Ӧ,Ev_MT_BLL_HD_GetLastDisplayCfg_Rsp    
	
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
	@brief   ͼ����ȼ�֪ͨ,Ev_MT_BLL_HD_SetImageNoiseLevelCfg_Ntf   
	
	MainBuf(#THDMTImageNoise_Api ,tCfg_Api)

	@verbatim
	{
	    "emNoiseLevel" : 1
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_SetImageNoiseLevelCfg_Ntf,

	/**	  
	@brief   ��ȡͼ����ȼ���Ӧ,Ev_MT_BLL_HD_GetImageNoiseLevelCfg_Rsp      
	
	MainBuf(#THDMTImageNoise_Api�� tImageNoise)

	@verbatim
	{
	    "emNoiseLevel" : 1
	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_GetImageNoiseLevelCfg_Rsp,

	/**
	@brief ͼ����ǿ���أ���Ӧ��Ev_MT_BLL_HD_SetImageEnhancementCfg_Ntf
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		"bUse": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetImageEnhancementCfg_Ntf,

	/**
	@brief ͼ����ǿ���أ���Ӧ��Ev_MT_BLL_HD_GetImageEnhancementCfg_Rsp
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		"bUse": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetImageEnhancementCfg_Rsp,

	/**
	@brief   ���õ�һ·����Ƶ��������֪ͨ����Ӧ��Ev_MT_BLL_HD_SetPri1stDeformationTensileCfg_Ntf
	
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
	@brief  ��ȡ��һ·����Ƶ����������Ӧ����Ӧ��Ev_MT_BLL_HD_GetPri1stDeformationTensileCfg_Rsp
	
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
	@brief  	���õڶ�·����Ƶ��������֪ͨ����Ӧ��Ev_MT_BLL_HD_SetPri2ndDeformationTensileCfg_Ntf
	
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
	@brief  	��ȡ�ڶ�·����Ƶ����������Ӧ����Ӧ��Ev_MT_BLL_HD_GetPri2ndDeformationTensileCfg_Rsp
	
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
	@brief  	���ø���Ƶ��������֪ͨ����Ӧ��Ev_MT_BLL_HD_SetAssDeformationTensileCfg_Ntf  
	
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
	@brief  	��ȡ����Ƶ����������Ӧ����Ӧ��Ev_MT_BLL_HD_GetAssDeformationTensileCfg_Rsp   
	
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
	@brief  	���õ�һ·����Ƶ�ȱ�����֪ͨ����Ӧ��Ev_MT_BLL_HD_SetPri1stGeometricScalingCfg_Ntf
	
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
	@brief  	��ȡ��һ·����Ƶ�ȱ�������Ӧ����Ӧ��Ev_MT_BLL_HD_GetPri1stGeometricScalingCfg_Rsp 
	
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
	@brief  	���õڶ�·����Ƶ�ȱ�����֪ͨ����Ӧ��Ev_MT_BLL_HD_SetPri2ndGeometricScalingCfg_Ntf 
	
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
	@brief  	��ȡ�ڶ�·����Ƶ�ȱ�������Ӧ����Ӧ��Ev_MT_BLL_HD_GetPri2ndGeometricScalingCfg_Rsp
	
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
	@brief  	���ø���Ƶ�ȱ����ţ���Ӧ��Ev_MT_BLL_HD_SetAssGeometricScalingCfg_Ntf  
	
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
	@brief  	��ȡ����Ƶ�ȱ�������Ӧ����Ӧ��Ev_MT_BLL_HD_GetAssGeometricScalingCfg_Rsp   
	
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
	@brief ���õ�һ·����Ƶ�ñ����أ���Ӧ��Ev_MT_BLL_HD_SetEdgePixelCfg_Ntf
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetEdgePixelCfg_Ntf,
	
	/**
	@brief ���õ�һ·����Ƶ�ñ����أ���Ӧ��Ev_MT_BLL_HD_GetEdgePixelCfg_Rsp
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetEdgePixelCfg_Rsp,

	/**
	@brief ������������ã���Ӧ��Ev_MT_BLL_HD_SetCameraListCfg_Ntf  
	
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
	@brief ��ȡ�����������Ӧ����Ӧ��Ev_MT_BLL_HD_GetCameraListCfg_Rsp    
	
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
	@brief ���ô�������֪ͨ����Ӧ��Ev_MT_BLL_HD_SetSerialCtrlCfg_Ntf    
	
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
	@brief ��ȡ����������Ӧ����Ӧ��Ev_MT_BLL_HD_GetSerialCtrlCfg_Rsp 
	
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

	/*********************Ӳ�ն˲�Ʒ����********************/
	
	/**
	@brief �������ݻ��飬��Ӧ��Ev_MT_BLL_SetDCSCfg_Ntf
	
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
	@brief  ��ȡ���ݻ�����Ӧ����Ӧ��Ev_MT_BLL_GetDCSCfg_Rsp
	
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
	@brief ��������Ƶ��������������Ӧ��Ev_MT_BLL_SetPriVidEncParamCfg_Ntf
	
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
	@brief   ��ȡ����Ƶ������������Ӧ����Ӧ��Ev_MT_BLL_GetPriVidEncParamCfg_Rsp
	
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
	@brief ���ø���Ƶ��������������Ӧ��Ev_MT_BLL_SetAssVidEncParamCfg_Ntf
	
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
	@brief  ��ȡ����Ƶ������������Ӧ����Ӧ��Ev_MT_BLL_GetAssVidEncParamCfg_Rsp
	
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
	@brief    ������Ƶ��������������Ӧ��Ev_MT_BLL_SetVideoDecParamCfg_Ntf
	
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
	@brief    ��ȡ��Ƶ������������Ӧ����Ӧ��Ev_MT_BLL_GetVideoDecParamCfg_Rsp
	
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
	@brief    ���û������Ƿ������Ŷ�����Ч����Ӧ��Ev_MT_BLL_SetPlayAniSoundInIdleCfg_Ntf
	
	MainBuf(#BOOL32, bEnable)

	@verbatim
	{
		"bEnable": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetPlayAniSoundInIdleCfg_Ntf,

	/**	
	@brief    ��ȡ�������Ƿ������Ŷ�����Ч��Ӧ����Ӧ��Ev_MT_BLL_GetPlayAniSoundInIdleCfg_Rsp
	
	MainBuf(#BOOL32, bEnable)

	@verbatim
	{
		"bEnable": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetPlayAniSoundInIdleCfg_Rsp,

	/**	
	@brief    ������ƵԴ֪ͨ ����Ӧ��Ev_MT_BLL_SetCodecVideoSrcCfg_Ntf
	
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
	@brief    ��ȡ��ƵԴ��Ӧ����Ӧ��Ev_MT_BLL_GetCodecVideoSrcCfg_Rsp
	
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
	@brief    �Ƿ��������նˣ� ��ƽ̨��ȡ֪ͨ����Ӧ��Ev_MT_BLL_SetIsSatelliteMTRt_Ntf  
	
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
	@brief  �Ƿ��������նˣ� ��ƽ̨��ȡ��Ӧ ����Ӧ��Ev_MT_BLL_SetIsSatelliteMTRt_Ntf  
	
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
	@brief  ������ϯ��ѯ����֪ͨ ����Ӧ��Ev_MT_BLL_SetChrmanPollSchemesCfg_Ntf       
	
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
	@brief  ������ϯ��ѯ������Ӧ����Ӧ��Ev_MT_BLL_GetChrmanPollSchemesCfg_Rsp         
	
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
	@brief    ������ʾ����ʱ�䣬��Ӧ��Ev_MT_BLL_SetShowConfTimeCfg_Ntf
	
	MainBuf(#BOOL32, bShow)

	@verbatim
	{
		"bShow": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetShowConfTimeCfg_Ntf,

	/**	
	@brief    ������ʾ����ʱ�䣬��Ӧ��Ev_MT_BLL_GetShowConfTimeCfg_Rsp
	
	MainBuf(#BOOL32, bShow)

	@verbatim
	{
		"bShow": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetShowConfTimeCfg_Rsp,

	/**	
	@brief    ������ʾϵͳʱ�䣬��Ӧ��Ev_MT_BLL_SetShowSystimeTimeCfg_Ntf
	
	MainBuf(#BOOL32, bShow)

	@verbatim
	{
		"bShow": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetShowSystimeTimeCfg_Ntf,

	/**	
	@brief    ������ʾϵͳʱ�䣬��Ӧ��Ev_MT_BLL_GetShowSystimeTimeCfg_Rsp
	
	MainBuf(#BOOL32, bShow)

	@verbatim
	{
		"bShow": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetShowSystimeTimeCfg_Rsp,

	/**	
	@brief    ���û������Ƿ���ʾ����Ϣ����Ӧ��Ev_MT_BLL_SetShowShortMsgInConfCfg_Ntf
	
	MainBuf(#BOOL32, bShow)

	@verbatim
	{
		"bShow": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetShowShortMsgInConfCfg_Ntf,

	/**	
	@brief    ���û������Ƿ���ʾ����Ϣ����Ӧ��Ev_MT_BLL_GetShowShortMsgInConfCfg_Rsp
	
	MainBuf(#BOOL32, bShow)

	@verbatim
	{
		"bShow": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetShowShortMsgInConfCfg_Rsp,

	/**	
	@brief    �����Ƿ���ʾ������ʾ����Ӧ��Ev_MT_BLL_SetShowAppTipsCfg_Ntf
	
	MainBuf(#BOOL32, bShow)

	@verbatim
	{
		"bShow": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetShowAppTipsCfg_Ntf,

	/**	
	@brief    �����Ƿ���ʾ������ʾ����Ӧ��Ev_MT_BLL_GetShowAppTipsCfg_Rsp
	
	MainBuf(#BOOL32, bShow)

	@verbatim
	{
		"bShow": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetShowAppTipsCfg_Rsp,

	/**	
	@brief    �����Ƿ�����Զң����Ӧ��Ev_MT_BLL_GetFECCCfg_Ntf
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		"bUse": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetFECCCfg_Ntf,

	/**	
	@brief    �����Ƿ�����Զң����Ӧ��Ev_MT_BLL_GetFECCCfg_Rsp
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		"bUse": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetFECCCfg_Rsp,

	/**	
	@brief    �������䣬��Ӧ��Ev_MT_BLL_SetEmailCfg_Ntf
	
	MainBuf(#u8[], achEmail)

	@verbatim
	{
		"basetype": ""
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetEmailCfg_Ntf,
	
	/**	
	@brief    ��ȡ������Ӧ����Ӧ��Ev_MT_BLL_GetEmailCfg_Rsp
	
	MainBuf(#u8[], achEmail)

	@verbatim
	{
		"basetype": ""
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetEmailCfg_Rsp,

	/**	
	@brief    �����Ƿ�����H.264 SVC����Ӧ��Ev_MT_BLL_GetH264SvcCfg_Ntf
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		"bUse": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetH264SvcCfg_Ntf,

	/**	
	@brief    �����Ƿ�����H.264 SVC����Ӧ��Ev_MT_BLL_GetH264SvcCfg_Rsp
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		"bUse": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetH264SvcCfg_Rsp,

	/**	
	@brief    ������Ƶ�غ�����Ӧ����Ӧ��Ev_MT_BLL_SetLoadAdaptiveVideoCfg_Ntf
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		"bUse": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetLoadAdaptiveVideoCfg_Ntf,

	/**	
	@brief    ������Ƶ�غ�����Ӧ����Ӧ��Ev_MT_BLL_GetLoadAdaptiveVideoCfg_Rsp
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		"bUse": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetLoadAdaptiveVideoCfg_Rsp,

	/**	
	@brief   ��������mc����������֪ͨ����Ӧ��Ev_MT_BLL_SetInnerMcAssVidCfgCfg_Ntf
	
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
	@brief   ��ȡ����mc������������������Ӧ ����Ӧ��Ev_MT_BLL_GetInnerMcAssVidCfgCfg_Rsp  
	
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
	@brief    Э��ջ�Ƿ��׼�ģ���Ӧ��Ev_MT_BLL_SetIsH323StackStandRt_Ntf
	
	MainBuf(#BOOL32, bStandard)

	@verbatim
	{
	    "bStandard": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetIsH323StackStandRt_Ntf,

	/**	
	@brief    Э��ջ�Ƿ��׼�ģ���Ӧ��Ev_MT_BLL_GetIsH323StackStandRt_Rsp
	
	MainBuf(#BOOL32, bStandard)

	@verbatim
	{
		"bStandard": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetIsH323StackStandRt_Rsp,
	
	/**	
	@brief    ���ź�����������Ӧ��Ev_MT_BLL_HD_SetCallInRingRt_Ntf
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetCallInRingRt_Ntf,
	
	/**	
	@brief    ���ź�����������Ӧ��Ev_MT_BLL_HD_GetCallInRingRt_Rsp
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetCallInRingRt_Rsp,
	
	/**	
	@brief    ���ź�����������Ӧ��Ev_MT_BLL_HD_SetCallOutRingRt_Ntf
	
	MainBuf(#u32, dwVal)	

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetCallOutRingRt_Ntf,
	
	/**	
	@brief    ���ź�����������Ӧ��Ev_MT_BLL_HD_GetCallOutRingRt_Rsp
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetCallOutRingRt_Rsp,
	
	/**	
	@brief    ���ò��Ű���������Ӧ��Ev_MT_BLL_HD_SetKeyboardRingCfg_Ntf
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetKeyboardRingCfg_Ntf,
	
	/**	
	@brief    ���ò��Ű���������Ӧ��Ev_MT_BLL_HD_GetKeyboardRingCfg_Rsp
	
	MainBuf(#u32, dwVal)

	@verbatim
	{
		"dwVal": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetKeyboardRingCfg_Rsp,

	/**	
	@brief    ����VGAͼ�����֪ͨ����Ӧ��Ev_MT_BLL_HD_SetVGAImageAdjustCfg_Ntf   
	
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
	@brief    ��ȡVGAͼ�������Ӧ����Ӧ��Ev_MT_BLL_HD_GetVGAImageAdjustCfg_Rsp    
	
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
	@brief    ������ƵԴ��ǩ (value:TMTVideoSrcTagList)emHD_Cfg_VideoSrcTag
	
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
	@brief    ��ȡ��ƵԴ��ǩ (value:TMTVideoSrcTagList)emHD_Cfg_VideoSrcTag
	
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
	@brief    ���ÿ���FTP, Ev_MT_BLL_HD_SetSnapShotFtpCfgCfg_Ntf    
	
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
	@brief    ��ȡ����FTP������Ӧ, Ev_MT_BLL_HD_GetSnapShotFtpCfg_Rsp  
	
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
	@brief    ����VGA������� , Ev_MT_BLL_HD_SetVgaOutBrightCfg_Ntf  
	
	MainBuf(#u32 ,dwCfg_Api)

	@verbatim
	{

	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_SetVgaOutBrightCfg_Ntf,  

	/**	
	@brief    ��ȡVGA�������������Ӧ ,Ev_MT_BLL_HD_GetVgaOutBrightCfg_Rsp
	
	MainBuf(#u32, dwVgaOutBright)

	@verbatim
	{

	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_GetVgaOutBrightCfg_Rsp, 

	/**	
	@brief    ����VGA����Աȶ�,Ev_MT_BLL_HD_SetVgaOutContrastCfg_Ntf
	
	MainBuf(#u32 , dwCfg_Api )

	@verbatim
	{

	}
	@endverbatim
	*/		
	Ev_MtApi_Base_Hd_SetVgaOutContrastCfg_Ntf,   

	/**	
	@brief    ��ȡVGA����Աȶ�������Ӧ,Ev_MT_BLL_HD_SetVgaOutContrastCfg_Ntf
	
	MainBuf(#u32, dwVgaOutContrast)

	@verbatim
	{

	}
	@endverbatim
	*/		
	Ev_MtApi_Base_Hd_GetVgaOutContrastCfg_Rsp,   

	/**	
	@brief    ����VGA������Ͷ�,Ev_MT_BLL_HD_SetVgaOutSaturationCfg_Ntf
	
	MainBuf(#u32, dwVgaOutContrast)

	@verbatim
	{

	}
	@endverbatim
	*/	
	Ev_MtApi_Base_Hd_SetVgaOutSaturationCfg_Ntf,    

    /**	
	@brief    ��ȡVGA������Ͷ�������Ӧ,Ev_MT_BLL_HD_GetVgaOutSaturationCfg_Rsp
	
	MainBuf(#u32 ,dwVgaOutSaturation��

	@verbatim
	{

	}
	@endverbatim
	*/		
	Ev_MtApi_Base_Hd_GetVgaOutSaturationCfg_Rsp,   

	/**	
	@brief     ������Ƶ���ȡ��Աȶȡ����Ͷ�
	
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
	@brief   ��ȡ��ѯ��Ƶ���ȡ��Աȶȡ����Ͷ���Ӧ, Ev_MT_BLL_GetVidImgParam_Rsp
	
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
	@brief   ����Ԥ��λ��������  , Ev_MT_BLL_HD_SetPresetNameInfoCfg_Ntf    
	
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
	@brief   ��ȡԤ��λ��������������Ӧ ,Ev_MT_BLL_HD_GetPresetNameInfoCfg_Rsp      
	
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
	@brief  �޸ĵ�¼������Ӧ ,Ev_MT_BLL_RestUpdatePassword_Rsp       
	
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
	@brief    APS��½�����ӦEv_MT_BLL_ApsLoginResult_Ntf
	
	MainBuf(#TMtApsLoginErrcode_Api, tMtApsLoginErrcode)
    SubBuf(#TPlatformInfo_Api, tPlf)

    @verbatim
    {
        "MainParam":
        {
            "bSucess": true,
            "dwHttpErrcode": 0,
            "dwApsErroce": 0
                        0,         //��½�ɹ�
                        1,         //δ֪����

                        10000,     //ƽ̨�ܾ���¼
                        21000,     //����ʧ��
                        22000,     //��½��������
                        22001,     //�û�������
                        22002,     //�û��������
                        22003,     //�豸��������
                        22004,     //��¼������
                        22005,     //�������������
                        22006,     //û������Ȩ��
                        22007,     //�û������������
                        23001,     //�������ڲ�����
                        23002,     //���ݿ�ִ��ʧ��
                        23003,     //�Ѿ��л�aps�����µ�½
                        23004,     //�Ѿ��л�gk�����µ�½

                        60000,     //û�е�½�Խ�ƽ̨��Ȩ��
        },
        "AssParam": 
        {
            "achVersion": string //ƽ̨�汾��
            "dwIP" : u32         //��½IP
            "emResourceType": EmResourceType_Api
        }
    }
	*/
	Ev_MtApi_Base_ApsLoginResult_Ntf,

	/**	
	@brief    ����·��������Ϣ,Ev_MT_BLL_HD_SetRouteCfgListCfg_Ntf   
	
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
	@brief    ��ȡ·��������Ϣ��Ӧ,Ev_MT_BLL_HD_GetRouteCfgListCfg_Rsp   
	
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
	@brief    ������̫������ģʽ,Ev_MT_BLL_HD_SetEthWorkModeListCfg_Ntf  
	
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
	@brief    ��ȡ��̫������ģʽ��Ӧ,Ev_MT_BLL_HD_GetEthWorkModeListCfg_Rsp  
	
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
	@brief    ������̫����Ϣ,Ev_MT_BLL_HD_SetEthnetCfgCfg_Ntf 
	
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
	@brief    ��ȡ��̫����Ϣ������Ӧ,Ev_MT_BLL_HD_GetEthnetCfgCfg_Rsp
	
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
	@brief   ����PPPoE������Ϣ,Ev_MT_BLL_HD_GetEthWorkModeListCfg_Rsp  
	
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
	@brief   ��ȡPPPoE������Ϣ��Ӧ,Ev_MT_BLL_HD_GetEthPPPoECfgCfg_Rsp   
	
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
	@brief   ����Wifi����ģʽ,Ev_MT_BLL_HD_SetWifiWorkModeCfg_Ntf   
	
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
	@brief   ��ȡWifi����ģʽ������Ӧ,Ev_MT_BLL_HD_GetWifiWorkModeCfg_Rsp   
	
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
	@brief   ����Wifi-AP������Ϣ,Ev_MT_BLL_HD_SetWifiApCfgCfg_Ntf  
	
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
	@brief   ��ȡWifi-AP������Ϣ������Ӧ,Ev_MT_BLL_HD_GetWifiApCfgCfg_Rsp   
	
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
	@brief     ����Wifi��Ϊclient�����Ӻ��������Ϣ,Ev_MT_BLL_HD_SetWifiClientCfgCfg_Ntf   
	
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
	@brief     ��ȡWifi��Ϊclient�����Ӻ��������Ϣ������Ӧ,Ev_MT_BLL_HD_GetWifiClientCfgCfg_Rsp   
	
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
	@brief    ����E1��������Ϣ,Ev_MT_BLL_HD_SetE1CfgCfg_Ntf 
	
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
	@brief    ��ȡE1��������Ϣ������Ӧ,Ev_MT_BLL_HD_GetE1CfgCfg_Rsp  
	
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
	@brief    ����Wifi��Ϊclient���Ӻ����ϸ��Ϣ,Ev_MT_BLL_HD_SetWifiCurConnectedInfoRt_Ntf 
	
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
	@brief     ��ȡWifi��Ϊclient���Ӻ����ϸ��Ϣ������Ӧ,Ev_MT_BLL_HD_GetWifiCurConnectedInfoRt_Rsp   
	
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
	@brief    �����ƶ�����3G/4G����ģʽ
	
	MainBuf(#TMobileDataWorkMode_Api, tMobileDataWorkMode)

	@verbatim
	{
	    "bEnable": true
	}
	@endverbatim
	*/ 
	Ev_MtApi_Base_Hd_SetMobileDataWorkModeCfg_Ntf,	
	
	/**	
	@brief    ��ȡ�ƶ�����3G/4G����ģʽ
	
	MainBuf(#TMobileDataWorkMode_Api, tMobileDataWorkMode)

	@verbatim
	{
	    "bEnable": true
	}
	@endverbatim
	*/ 
	Ev_MtApi_Base_Hd_GetMobileDataWorkModeCfg_Rsp,
	
	/**	
	@brief    �����ƶ�����3G/4G���Ӻ����ϸ��Ϣ
	
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
	@brief    ��ȡ�ƶ�����3G/4G���Ӻ����ϸ��Ϣ
	
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
	@brief    ���õ�ǰ����ͨѶ������IP��ϸ��Ϣ emHD_Rt_NetUsedInfo ��Ӧ��Ev_MT_BLL_HD_SetNetUsedInfoRt_Ntf
	
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
	@brief    ��ȡ��ǰ����ͨѶ������IP��ϸ��Ϣ ��Ӧ��Ev_MT_BLL_HD_GetNetUsedInfoRt_Rsp 
	
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
	@brief    ���ܷ�������¼���֪ͨ,Ev_MT_BLL_AgentLogInResult_Ntf
	
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
	@brief    ���ܷ������ǳ����֪ͨ,Ev_MT_BLL_AgentLogOutResult_Ntf
	
	MainBuf(#BOOL32, bLogoutOk)

	@verbatim
	{
	   "bLogoutOk" : true,
	}
	@endverbatim
	*/    
	Ev_MtApi_LogoutNmsServer_Ntf,

	/**	
	@brief    API��������¼���
	
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
	@brief    ϵͳ��Ϣ��ʾ,achExtraParam: ���Ǹ�json��ʽ��str
	
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
	@brief    ��ȡDHCP��Լ��Ϣ��Ӧ
	
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
	@brief    DHCP��Լ��Ϣ֪ͨ
		
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
	@brief    ��ȡ��̫����ѡ������Ӧ
	
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
	@brief    PPPoE ��ȡ����״̬��Ӧ
	
	MainBuf(#TPPPoEState_Api, tPPPoEState)

	@verbatim
	{
		"emState": 0,
		"dwIp" : 0,  
		"dwGateway" : 0,
		"dwDns" : 0,
		"dwDnsBackup"��: 0,
		"emReason" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_PPPoE_GetLinkState_Rsp, 

	/**	
	@brief    PPPoE ����״̬֪ͨ
	
	MainBuf(#TPPPoEState_Api, tPPPoEState)

	@verbatim
	{
		"emState": 0,
		"dwIp" : 0,  
		"dwGateway" : 0,
		"dwDns" : 0,
		"dwDnsBackup"��: 0,
		"emReason" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_PPPoE_LinkState_Ntf, 

	/**	
	@brief    PPPoE ���Ӻ��ȡͳ����Ϣ��Ӧ
	
	MainBuf(#TPPPoEStatis_Api, tPPPoEStatis)

	@verbatim
	{
		"dwLinkTime": 0,
		"dwLinkDowntimes" : 0,  
		"dwNumPkgSent" : 0,
		"dwNumPkgRecved" : 0,
		"dwNumBytesSent"��: 0,
		"dwNumBytesRecved" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_PPPoE_GetStatisInfo_Rsp,

	/**	
	@brief    ��ȡ����·��������Ӧ
	
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
	@brief    ����һ��·��������Ӧ
	
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
	@brief   ����һ��·��֪ͨ
	
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
	@brief    ��ȡ����·��������Ӧ
	
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
	@brief    ɾ��һ��·��֪ͨ
	
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
	@brief    �޸�һ��·��֪ͨ
	
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
	@brief    �޸�һ��·��������Ӧ
	
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
	@brief    Wifi ����ģʽ��Ϣ��Ӧ
	
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
	@brief    Wifi �ȵ�ɨ����֪ͨ
	
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
	@brief    Wifi �ȵ����ӽ��״̬��Ӧ
	
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
	@brief    Wifi �ȵ����ӽ��״̬֪ͨ
	
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
	@brief    Wifi ��ȡ��ǰ���ӵ�Wifi�ͻ���������Ӧ
	
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
	@brief    Wifi ��ȡ��ǰ���ӵ�Wifi�ͻ�����ϸ��Ϣ��Ӧ
	
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
	@brief    Wifi �ȵ����ӽ��״̬��Ӧ
	
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
	@brief    MobileData �ƶ��������Ӻ���ϸ״̬֪ͨ
	
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
	@brief    MobileData ����ģʽ��Ϣ��ѯ��Ӧ
	
	MainBuf(#TMobileDataWorkMode_Api, tMobileDataWorkMode)

	@verbatim
	{
	    "bEnable": true
	}
	@endverbatim
	*/
	Ev_MtApi_MOBILEDATA_GetWorkMode_Rsp,

	/**	
	@brief    MobileData �ƶ��������Ӻ���ϸ��Ϣ��Ӧ
	
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
	@brief    MobileData ��ǰ���ӵ��ƶ�����ͳ����Ϣ��ѯ��Ӧ
	
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
	@brief    �ն����°汾֪ͨ
	
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
	@brief    Nms��Ϣ֪ͨ
	
	MainBuf(#s8[], achNmsMsg)

	@verbatim
	{
	    "basetype": ""
	}
	@endverbatim
	*/
	Ev_MtApi_AgentNmsMsg_Ntf,

	/**	
	@brief    ping���Խ��֪ͨ
	
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
	@brief    ip mac��ͻ֪ͨ
	
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
	@brief    ��ѯDNS��Ӧ��IP��Ϣ������Ӧ
	
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
	@brief    ���õ�ǰ����ʱ��֪ͨ
	
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
	@brief    ���õ�ǰ����ʱ����Ϣ��Ӧ
	
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
	@brief    ��ѯ��ǰ����ʱ����Ϣ��Ӧ
	
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
	@brief    ����NTP�������ر�״̬��Ӧ
	
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
	@brief    ����NTP�������ر�״̬֪ͨ
	
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
	@brief    ��ѯ��ǰNTP������״̬��Ӧ
	
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
	@brief    ����CSU����֪ͨ
	
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
	@brief    ��ȡCSU������Ӧ
	
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
	@brief    �ն�������������֪ͨ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"basetype": true
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetHasWizardConfigedCfg_Ntf,

	/**
	@brief   ��ѯ�ն��������Ƿ���������Ӧ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"basetype": false
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetHasWizardConfigedCfg_Rsp,


	/**
	@brief    �ֶ����õ�sip����������֪ͨ
	
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
	@brief    �ֶ����õ�sip����������֪ͨ
	
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
	@brief    ��ѯ�ն��Ƿ�ע����gk��Ӧ
	
	MainBuf(#BOOL32)

	@verbatim
	{
        "basetype" : false
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetIsGkRigistedRt_Rsp,

	/**
	@brief    ��ѯ�ն��Ƿ�ע����sip��Ӧ
	
	MainBuf(#BOOL32)

	@verbatim
	{
        "basetype" : false
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetIsSipRigistedRt_Rsp,

	/**
	@brief    ���ÿ��ٺ���֪ͨ
	
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
	@brief    ��ȡ���ٺ���������Ӧ
	
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
	@brief    ��ȡIMģ���¼�����Ӧ
	
	MainBuf(#u32)

	@verbatim
	{
		"basetype" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetIMHandleRt_Rsp,

		/**
	@brief    �����Ƿ���ʾ��������֪ͨ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"basetype" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetShowConfNameCfg_Ntf,

	/**
	@brief    ��ȡ�Ƿ���ʾ��������������Ӧ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"basetype" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetShowConfNameCfg_Rsp,

	/**
	@brief    ����Ftp/Telnet�˺���Ϣ��Ӧ
	
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
	@brief    ����Ftp/Telnet��¼���û���������֪ͨ
	
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
	@brief    ��ȡFtp/Telnet��¼���û�����������Ӧ
	
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
	@brief    ��ȡ�ն���Ƶ���״̬�б���Ӧ
	
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
	@brief    ��̫������״̬�仯֪ͨ
	
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
	@brief    ������֪ͨ
	
	MainBuf(#u32)

	@verbatim
	{
        "basetype" : 0
	}
	@endverbatim
	*/
	Ev_MTApi_Base_PackageLostRatio_Ntf,

    /**
	@brief    �����Ƿ�ʹ��HTTPS֪ͨ
	@verbatim
	MainBuf(BOOL32)
	{
		"basetype" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetEnableHTTPSCfg_Ntf,

    /**
	@brief    ��ȡ�Ƿ�ʹ��HTTPS����Ӧ��
	@verbatim
	MainBuf(BOOL32)
	{
		"basetype" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetEnableHTTPSCfg_Rsp,

	/**
	@brief    ���õ�ǰwifi����֪ͨ
	
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
	@brief    ��ȡ������̫����������״̬��Ӧ
	
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
	@brief    �����Ƿ�ǿ������323Э��ջ֪ͨ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"basetype" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ForceSet323StackCfg_Ntf,

		/**
	@brief    �����Ƿ�ǿ������323Э��ջ֪ͨ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"basetype" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetForceH323StackCfg_Rsp,

	/**
	@brief    ���÷�������¼�˿ڵ�֪ͨ
	
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
	@brief    ���÷�������¼�˿ڵ���Ӧ
	
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
	@brief    ��̫�������л�,Ev_MT_BLL_HD_EthnetCardChange_Ntf 
	
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
	@brief    ������Ƶ�����ǩ (value:TMTVideoOutTagList)emHD_Cfg_VideoOutTag
	
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
	@brief    ��ȡ��Ƶ�����ǩ (value:TMTVideoOutTagList)emHD_Cfg_VideoOutTag
	
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
	@brief    ����SDIһ��һ����������(value: TU32)
	
	MainBuf(#u32)

	@verbatim
	{
	    dwTpye: 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetSDIOneInOneOutOrTwoInCfg_Ntf,

	/**	
	@brief    ��ȡSDIһ��һ����������(value: TU32)
	
	MainBuf(#u32)

	@verbatim
	{
		dwTpye: 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetSDIOneInOneOutOrTwoInCfg_Rsp,


		/**	
	@brief    ������Ƶ�����ǩ (value:TMTHDSerialList)emHD_Cfg_SerialList
	
	MainBuf(#TMTHDSerialList_Api)

	@verbatim
	{
		"byCnt" : 0,
		"atVidOutTag" :
		[
			{
				emSerialType��                                
				dwBandRate��                                                
				dwByteSize��                                                
				emStopBits��                                   
				emParityCheck��                         
			}
		]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetSerialListCfg_Ntf,

	/**	
	@brief    ��ȡ�����б� (value:TMTHDSerialList)emHD_Cfg_SerialList
	
	MainBuf(#TMTHDSerialList_Api)

	@verbatim
	{
	    "byCnt" : 0,
		"atVidOutTag" :
		[
			{
				emSerialType��                                
				dwBandRate��                                                
				dwByteSize��                                                
				emStopBits��                                   
				emParityCheck��                         
			}
		]
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetSerialListCfg_Rsp,
/**
  @brief   ������˳����������Ƿ��¼
  
  MainBuf(#BOOL32)
  @verbatim
  {
    "registerstate" : false
  }
  @endverbatim
*/
	Ev_MtApi_Base_MfgTestRegisterInOrOut_Ntf,


	/**
	@brief    ���ö˿ڸ��õ�֪ͨ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bSamePort" : 0
	}
	@endverbatim
	*/
    Ev_MtApi_Base_SetTRtpSamePortCfg_Ntf,


	/**
	@brief    ��ȡ�˿ڸ��õ�֪ͨ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bSamePort" : 0
	}
	@endverbatim
	*/
    Ev_MtApi_Base_GetTRtpSamePortCfg_Rsp,

		/**
	@brief    �����Ƿ�������ǿ���֪ͨ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bEnable" : 0
	}
	@endverbatim
	*/
    Ev_MtApi_Base_SetConfOccupyCfg_Ntf,

		/**
	@brief    ���������ļ�����Ӧ
	
	MainBuf(#EmFileCopyErr_Api)

	@verbatim
	{
		"emCopySuccess_Api" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ExportMtcfg_Rsp,

	/**
	@brief    ���������ļ�����Ӧ
	
	MainBuf(#EmFileCopyErr_Api)

	@verbatim
	{
		"emCopySuccess_Api" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ImportMtcfg_Rsp,

		/**
	@brief    ����debug�ļ�����Ӧ
	
	MainBuf(#EmFileCopyErr_Api)

	@verbatim
	{
		"emCopySuccess_Api" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ExportMtDbgcfg_Rsp,

	/**
	@brief    ����debug�ļ�����Ӧ
	
	MainBuf(#EmFileCopyErr_Api)

	@verbatim
	{
		"emCopySuccess_Api" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ImportMtDbgcfg_Rsp,

	/**
	@brief    �����Ƿ���IPW��ʽ��֪ͨ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bEnable" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetEnableIpwType_Ntf,

	/**
	@brief    ��ȡ�Ƿ���IPW��ʽ����Ӧ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bEnable" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetEnableIpwType_Rsp,

	
	/**
	@brief    ��������ͷ������
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bDirection" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetCameraContrlExchangeCfg_Ntf,

	/**
	@brief    ��ȡ����ͷ������
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bDirection" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetCameraContrlExchangeCfg_Rsp,

	/**
	@brief    ��������ͷ�Ƿ�װ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bHeadStand" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetCameraHeadStandCfg_Ntf,

	/**
	@brief    ��ȡ����ͷ�Ƿ�װ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bHeadStand" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetCameraHeadStandCfg_Rsp,

	/**	
	@brief    ��������Ͷ�������Ӧ
	
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
	@brief    �����Ƿ���ʾ��᷽���/�����ʾ��֪ͨ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bShow" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetShowInOutConfCfg_Ntf,

	/**
	@brief    ��ȡ�Ƿ���ʾ��᷽���/�����ʾ�Ļظ�
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bShow" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetShowInOutConfCfg_Rsp,

	/**
	@brief    ����osd log��ӡ���Ƶ�֪ͨ
	
	MainBuf(#u32)

	@verbatim
	{
		"dwLogId": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetOsdLogCtrl_Ntf,

	/**
	@brief    ����ftp/telnet�޶�ip��Ӧ
	
	MainBuf(#BOOL32, bResult);
	MainBuf(#TMtLimitIpInfo_Api, tInfo);

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_FtpTelnet_AddLimitIp_Rsp,

	/**
	@brief    ɾ��ftp/telnet�޶�ip��Ӧ
	
	MainBuf(#BOOL32, bResult);
	MainBuf(#TMtLimitIpInfo_Api, tInfo);

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_FtpTelnet_DelLimitIp_Rsp,

	/**
	@brief    �޸�ftp/telnet�޶�ip��Ӧ
	
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
	@brief    ����ftp/telnet�޶�ip֪ͨ
	
	MainBuf(#TMtLimitIpInfo_Api, tInfo);

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_FtpTelnet_AddLimitIp_Ntf,

	/**
	@brief    ɾ��ftp/telnet�޶�ip֪ͨ
	
	MainBuf(#TMtLimitIpInfo_Api, tInfo);

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_FtpTelnet_DelLimitIp_Ntf,

	/**
	@brief    �޸�ftp/telnet�޶�ip֪ͨ
	
	MainBuf(#TMtLimitIpInfo_Api, tOldInfo);
	MainBuf(#TMtLimitIpInfo_Api, tNewInfo);

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_FtpTelnet_ModLimitIp_Ntf,

	/**	
	@brief    ��ȡftp/telnet�޶�ip�б���Ӧ
	
	MainBuf(#TMtLimitIpInfoList_Api)

	@verbatim
	{
	    
	}
	@endverbatim
	*/		
	Ev_Mtapi_Base_Hd_GetFtpTelnetLimitIpListCfg_Rsp,

	/**	
	@brief    ��ui��������ϵͳ֪ͨ
	
	MainBuf( )	//����Ϣ��

	@verbatim
	{

	}
	@endverbatim
	*/		
	Ev_MtApi_Base_OqcResetSystem_Ntf,

	//  ����
	/**
    @brief   ����Ca֤���Ƿ�ɹ�
  
    MainBuf(#BOOL32)
    @verbatim
    {
      "exportcaresult" : false
    }
    @endverbatim
    */
	Ev_MtApi_Base_ExportAllCACert_Rsp,

	/**
    @brief   �����豸֤���Ƿ�ɹ�
  
    MainBuf(#BOOL32)
    @verbatim
    {
      "exportdeviceresult" : false
    }
    @endverbatim
    */
	Ev_MtApi_Base_ExportDeviceCert_Rsp,

	/**
    @brief   �����豸֤���Ƿ�ɹ�
  
    MainBuf(#BOOL32)
    @verbatim
    {
      "createdeviceresult" : false
    }
    @endverbatim
    */
	Ev_MtApi_Base_CreateDeviceCert_Rsp,

	/**
    @brief   ��ѯCa֤����Ϣ
  
    MainBuf(#TMtSecCertInfo_Api)
    @verbatim
    {
	    achVersion;""                   ///< �汾ֻ��1��3
	    achSerialNumber;""              ///< ���кų��ȣ�HEX��ʽ��һ���20�ֽ�
	    achSignAlg;""                   ///< ǩ���㷨���ַ�����
	    tSecCertDistinctName            ///< ǩ������Ϣ
		{
		    achCountryName;	""		          ///< ���ң����й�"CN"��������
		    achStateOrProvinceName;""		  ///< �ݻ�ʡ����ѡ
		    achLocalityName;""			      ///< ���У���ѡ
		    achOrganizationName;""		      ///< ��֯���繫˾��������
		    achOrganizationUnitName;""	      ///< ��֯��Ԫ���粿�ţ�����ѡ
		    achCommonName;""		          ///< ͨ�����������������䡢���������кţ�������

		}
	    tSecCertValidity                ///< ��Ч��
		{
		    achNotTimeBefore;""			      ///< ��ʼʱ��
		    achNotTimeAfter; ""		          ///< ����ʱ��
		}
	    tSecCertUsrName                 ///< ʹ������Ϣ
		{


		}
		achPubKey:""                    ///< ʹ���߹�Կ��DER��ʽ��RSA2048Ϊ270�ֽ�
	    achPubKeyAlg;""                 ///< ��Կ�㷨
    }
    @endverbatim
    */
	Ev_MtApi_Base_QueryCACertInfo_Rsp,

	/**
    @brief   ��ѯ�豸֤����Ϣ
  
    MainBuf(#TMtSecDevCertInfo_Api)
    @verbatim
    {
		dwDevCertType: 1,
		tCertInfo
		{
			achVersion;""                   ///< �汾ֻ��1��3
			achSerialNumber;""              ///< ���кų��ȣ�HEX��ʽ��һ���20�ֽ�
			achSignAlg;""                   ///< ǩ���㷨���ַ�����
			tSecCertDistinctName            ///< ǩ������Ϣ
			{
				achCountryName;	""		          ///< ���ң����й�"CN"��������
				achStateOrProvinceName;""		  ///< �ݻ�ʡ����ѡ
				achLocalityName;""			      ///< ���У���ѡ
				achOrganizationName;""		      ///< ��֯���繫˾��������
				achOrganizationUnitName;""	      ///< ��֯��Ԫ���粿�ţ�����ѡ
				achCommonName;""		          ///< ͨ�����������������䡢���������кţ�������

			}
			tSecCertValidity                ///< ��Ч��
			{
				achNotTimeBefore;""			      ///< ��ʼʱ��
				achNotTimeAfter; ""		          ///< ����ʱ��
			}
			tSecCertUsrName                 ///< ʹ������Ϣ
			{


			}
			achPubKey:""                    ///< ʹ���߹�Կ��DER��ʽ��RSA2048Ϊ270�ֽ�
			achPubKeyAlg;""                 ///< ��Կ�㷨
		}
    }
    @endverbatim
    */
	Ev_MtApi_Base_QueryDeviceCertInfo_Rsp,

	/**
    @brief   �����������֤�Ƿ����
  
    MainBuf(#BOOL32)
    @verbatim
    {
      "bLicenseIsValidate" : FALSE
    }
    @endverbatim
    */
	Ev_MtApi_Base_DeviceLicenseIsValidate_Ntf,

	/**
    @brief   ���˻��߶Զ���֤���
  
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
	@brief    ���� ǿ��֤ ��ҪUI���붯̬����
	
	MainBuf(#����Ϣ��)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_PeerNeedDynPwd_Ntf,

	/**
	@brief    ��ȡ����Ƶ�Ƿ���Դ����Ӧ
	
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
	@brief    ��ȡ�Ƿ�Ϊ�����ն˵���Ӧ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bIsSecMt": FALSE
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetIsBusiSecMt_Rsp,

	/**
	@brief    �������� sip���ӷ�ʽ��֪ͨ
	
	MainBuf(#EmSipConnectType_Api)

	@verbatim
	{
		"emSipConnectType": 0
	}
	@endverbatim
	*/
    Ev_MtApi_Base_SetSipConnectCfg_Ntf,

	/**
	@brief    ��ȡ���� sip���ӷ�ʽ����Ӧ
	
	MainBuf(#EmSipConnectType_Api)

	@verbatim
	{
		"emSipConnectType": 0
	}
	@endverbatim
	*/
    Ev_MtApi_Base_GetSipConnectCfg_Rsp,

	/**
	@brief    �����Ƿ�������ǿ��֤��֪ͨ
	
	MainBuf(#TBOOL32)

	@verbatim
	{
		"bEnable": FALSE
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetEnableStrongAut_Ntf,

	/**
	@brief    ��ȡ�Ƿ�������ǿ��֤����Ӧ
	
	MainBuf(#TBOOL32)

	@verbatim
	{
		"bEnable": FALSE
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetEnableStrongAut_Rsp,

	/**
	@brief    ɾ��ca֤��֪ͨ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bRet" : FALSE
	}
	@endverbatim
	*/
    Ev_MtApi_Base_DeleteCACertByID_Rsp,

	/**
	@brief    ����ca֤��֪ͨ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bRet" : FALSE
	}
	@endverbatim
	*/
    Ev_MtApi_Base_ExportCACertByID_Rsp,

	/**
	@brief    ��ȡcaidlist֪ͨ
	
	MainBuf(#TMtCertIDList_Api)

	@verbatim
	{
		byCount: 2,                   ///< id����
		atIdList:
		[
			{
				"byLen": 2,			///< ����
				"abyId": 225		///< u8 ������
			}
		]
	}
	@endverbatim
	*/
    Ev_MtApi_Base_GetCACertIDList_Rsp,
	Ev_MtApi_Base_GetCACertIDListFin_Rsp,

	/**
	@brief    ����ǩ��֤����Ӧ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bSuccess" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ExportSignCert_Rsp,

	/**
	@brief    ��������֤����Ӧ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bSuccess" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ExportEncCert_Rsp,

	/**
	@brief    ����ftp/telnet�޶�ip��������Ϣ��֪ͨ
	
	MainBuf(#BOOL32);

	@verbatim
	{
		"bRet": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_FtpTelnet__SetLimitIpCfg_Ntf,

	/**
	@brief    ѡ�񴮿���Ϣ��֪ͨ��������ʹ��
	
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
	@brief    ������Ϣ��д��������ʹ��
	
	MainBuf(#BOOL32);
	MainBuf(#TMtSerialOptParam_Api);

	@verbatim
	{
		      
	}
	@endverbatim
	*/
	Ev_MtApi_Base_OperaterSerial_Ntf,

	/**
    @brief   �����������֤�Ƿ���õ���Ӧ
  
    MainBuf(#BOOL32)
    @verbatim
    {
      "bLicenseIsValidate" : FALSE
    }
    @endverbatim
    */
	Ev_MtApi_Base_DeviceLicenseIsValidate_Rsp,

	/**
    @brief   �������� �Ƿ����ñ�׼TLS֤���֪ͨ
  
    MainBuf(#BOOL32)
    @verbatim
    {
      "bEnable" : FALSE
    }
    @endverbatim
    */
	Ev_MtApi_Base_SetUseTlsCertCfg_Ntf,

	/**
    @brief   �������� �Ƿ����ù���TLS֤���֪ͨ
  
    MainBuf(#BOOL32)
    @verbatim
    {
      "bEnable" : FALSE
    }
    @endverbatim
    */
	Ev_MtApi_Base_SetUseGMTlsCertCfg_Ntf,

	/**
    @brief   ��ȡ���� �Ƿ����ñ�׼TLS֤�����Ӧ
  
    MainBuf(#BOOL32)
    @verbatim
    {
      "bEnable" : FALSE
    }
    @endverbatim
    */
	Ev_MtApi_Base_GetUseTlsCertCfg_Rsp,

	/**
    @brief   ��ȡ���� �Ƿ����ù���TLS֤�����Ӧ
  
    MainBuf(#BOOL32)
    @verbatim
    {
      "bEnable" : FALSE
    }
    @endverbatim
    */
	Ev_MtApi_Base_GetUseGMTlsCertCfg_Rsp,

	/**
    @brief   ��ȡSkyShare�汾�ŵ���Ӧ
  
    MainBuf(#s8*)
    @verbatim
    {
      "basetype" : ""
    }
    @endverbatim
    */
	Ev_MtApi_Base_GetSkyShareVerRt_Rsp,

	/**
	@brief    �����Ƿ���ʾ�ն˽���ʱ��Ļظ�
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bShow" : FALSE
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetShowMtTimeCfg_Ntf,

	/**
	@brief    ��ȡ�Ƿ���ʾ�ն˽���ʱ�����Ӧ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bShow" : FALSE
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetShowMtTimeCfg_Rsp,


	/**
	@brief    ���õ�¼����
	
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
	@brief    ��ȡ��¼������Ӧ
	
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
	@brief    ��������֤���֪ͨ
	
	MainBuf(#EmSecCertType_Api)
	SubBuf(#s32)
	@verbatim
	{
		"MainParam": 
		{
			emType:0  //����֤������
		}
		"AssParam":
		{
			nRet:0  //0��ʾ�ɹ�����0��ʾʧ��
		}
	@endverbatim
	*/
	Ev_MtApi_Base_ImportSecCert_Ntf,

	/**
	@brief    ���ô���ʣ��ʱ���֪ͨ����OSD���ã�����OSD������IMIX�Ĵ���ͬ����
			  ע��:  wSleepRemainTime = 0����ʾȡ������

	MainBuf(#u16)
	@verbatim
	{
		wSleepReaminTime: 10   //��λ����
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetSleepReaminTime_Ntf,

	/**
	@brief    ���ͱ��ض���Ϣ֪ͨ(���512�ֽ�)
	
	MainBuf(#s8[], achLocSms)
	@verbatim
	{
		basetype: "";  
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SendLocalSms_Ntf,

	/**
	@brief    �����Ƿ���ʾ�ն�Home��ť�Ļظ�
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"basetype" : FALSE
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetShowHomeButtonCfg_Ntf,

	/**
	@brief    ��ȡ�Ƿ���ʾ�ն�Home��ť����Ӧ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bShow" : FALSE
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetShowHomeButtonCfg_Rsp,

	/**
	@brief    OSD����Home��ť����֪ͨ
	
	MainBuf(#no)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_PressHomeButton_Ntf,

	/**	
	@brief    ��ȡ����Ͷ����Ե�����
	
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
	@brief    skyshare״̬��Ӧ,Ev_MtApi_Base_MTCSkyShareLoginState_Ntf
	
	MainBuf(#BOOL32, bloginstate)

	@verbatim
	{
		bloginstate : FALSE
	}
	@endverbatim
	*/
	Ev_MtApi_Base_MTCSkyShareLoginState_Ntf,

	/**
	@brief    ���û���ϳ��Ƿ���ʾ����Ӳ˫��Դ�ظ�
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bShow" : FALSE
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetShowAssVidInVmpCfg_Ntf,

	/**
	@brief    ��ȡ����ϳ��Ƿ���ʾ����Ӳ˫��Դ��Ӧ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bShow" : FALSE
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetShowAssVidInVmpCfg_Rsp,

	/**
	@brief    �������ʿ���osd���ܵĻظ�
	
	MainBuf(#TMTOrder_Api)
	
	@verbatim
	{

	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetIMIXCtrlOsdFuncCfg_Ntf,

	/**
	@brief    ��ȡ���ʿ���osd���ܵ���Ӧ
	
	MainBuf(#TMTOrder_Api)
	
	@verbatim
	{

	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetIMIXCtrlOsdFuncCfg_Rsp,

	/**
	@brief   �����ն�ʹ��֤�����͵Ļظ�
	
	MainBuf(#u8)
	
	@verbatim
	{
		byCertType: 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetHttpsCertTypeCfg_Ntf,

	/**
	@brief    ��ȡ�ն�ʹ��֤�����͵���Ӧ
	
	MainBuf(#u8)
	
	@verbatim
	{
		byCertType: 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetHttpsCertTypeCfg_Rsp,

	/**
	@brief   ������Ƶ���������������͵Ļظ�
	
	MainBuf(#EmVideoQuality_Api)
	
	@verbatim
	{
		emQcMode: 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetVidEncQcModeCfg_Ntf,

	/**
	@brief    ������Ƶ���������������͵���Ӧ
	
	MainBuf(#EmVideoQuality_Api)
	
	@verbatim
	{
		emQcMode: 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetVidEncQcModeCfg_Rsp,

	/**
	@brief   ǿ��֤���̽���֪ͨ
	
	MainBuf(#TBOOL32, isLocal)\n
	SubBuf(#EmMtCancelAuth_Api, emMtCancelAuth_Api)
	
	@endverbatim
	*/
	Ev_MtApi_Base_StrongAuthEnd_Ntf,

	/**
	@brief    �����Ƿ�ʹ��Ipc��֪ͨ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bUseIpc" : 0
	}
	@endverbatim
	*/
    Ev_MtApi_Base_SetIsUseIpcCfg_Ntf,


	/**
	@brief    ��ȡ�Ƿ�ʹ��Ipc֪ͨ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bUseIpc" : 0
	}
	@endverbatim
	*/
    Ev_MtApi_Base_GetIsUseIpcCfg_Rsp,

	/**
	@brief    ��ȡ�Ƿ�ʹ��Ipc֪ͨ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bUseIpc" : 0
	}
	@endverbatim
	*/
    Ev_MtApi_Base_SetVidDecTypeModeCfg_Ntf,

	/**
	@brief    ��ȡ�Ƿ�ʹ��Ipc֪ͨ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bUseIpc" : 0
	}
	@endverbatim
	*/
    Ev_MtApi_Base_GetVidDecTypeModeCfg_Rsp,


	/**
	@brief    ����������Ʒ��Ϣ��֪ͨ
	
	MainBuf(#TAgentInfo_Api)

	@verbatim
	{
		
	}
	@endverbatim
	*/
    Ev_MtApi_Base_SetAgentInfo_Ntf,

	/**
	@brief    ��ȡ�ն��Ƿ�֧�����߹��ܵ���Ӧ
	
	MainBuf(#BOOL32)

	@verbatim
	{
		"bIsSupport": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetIsSupportWirelessRt_Rsp,

	/**
	@brief    ��ȡ����������Բ�����Ӧ
	
	MainBuf(#u32)

	@verbatim
	{
		"dwResult" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetSoftIntegritySelfTest_Rsp,

	/**
	@brief    ��ȡ����������Բ�����Ӧ
	
	MainBuf(#u32)

	@verbatim
	{
		"dwResult" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SoftIntegritySelfTest_Ntf,

	/**
	@brief   ��ȡ�����㷨��������Բ���
	
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
	@brief    ��ȡ�����㷨��������Բ���
	
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
	@brief    ��ȡ�豸��Կ��һ�����Բ���
	
	MainBuf(#s32)

	@verbatim
	{
		"dwResult" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetKeyPairConsistencySelfTest_Rsp,

	/**
	@brief   �豸��Կ��һ�����Բ���
	
	MainBuf(#s32)

	@verbatim
	{
		"dwResult" : 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_KeyPairConsistencySelfTest_Ntf,

	/**
	@brief   wifi���������ȵ���Ӧ
	
	MainBuf(#BOOL32)
	SubBuf(#u32)

	@verbatim
	{

	}
	@endverbatim
	*/

	Ev_MtApi_WIFI_SetHotForget_Rsp,

	/**
	@brief    ������ͨ��¼��Ϣ
	
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
	@brief    ��ȡ��ͨ��¼��Ϣ
	
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
	@brief   ������ͨkey���²���
	
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
	@brief    ��ȡ��ͨkey���²���
	
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
	@brief   ����ָ���ӿ�Ethernet��������Ϣ���֪ͨ
	
	MainBuf(#u32, dwRet)		 0:�ɹ�  ����������
	SubBuf(#u32, dwEthernetId)   ����ʱָ��������ID

	@verbatim
	{
	}
	@endverbatim
	*/
	Ev_MTApi_Ethernet_SetIpParamResult_Ntf,

	/**
	@brief �������˫��״̬֪ͨ

	MainBuf(#s32)	
	@verbatim
	{
		basetype: 1   //EmCodecComponent_Api ��������ڼ�·��ע�⣺nCompType=20 ��ʾ˫��ֹͣ
	}
	@endverbatim
	*/ 
	Ev_MtApi_Base_GetMtStreamStatusRt_Rsp,

	/**
	@brief    ��ͨ�����Ƿ�ɹ�
	
	MainBuf(#u32) ��ʱ0��ʾ�ɹ��� ��0��ʾʧ��

	@verbatim
	{
	"basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_QtCreateRes_Ntf,

	/**
	@brief ��ȡ�����ն�license֤����Ϣ

	MainBuf(#TMtAgentLicenseInfo_Api)	
	@verbatim
	{
		
	}
	@endverbatim
	*/ 
	Ev_MtApi_Base_GetChannelLicenseRt_Rsp,

	/**
	@brief ���������ն�license֤����Ϣ�Ļظ�

	MainBuf(#TMtAgentLicenseInfo_Api)	
	@verbatim
	{
		
	}
	@endverbatim
	*/ 
	Ev_MtApi_Base_UpdateChannelLicense_Ntf,

	/**
	@brief ��¼ʱ��̬����Ļظ�

	MainBuf(#s8 )	
	@verbatim
	{
		"basetype": 1234
	}
	@endverbatim
	*/ 
	Ev_MtApi_Base_GetLoginDynamicPwd_Ntf,
	
	/**
	@brief �μ�����Э����̬����Ļظ�

	MainBuf(#s8 )	
	@verbatim
	{
		"basetype": 1234
	}
	@endverbatim
	*/ 
	Ev_MtApi_Base_GetDataConfDynamicPwd_Ntf,

	/**
	@brief ������mtc��ռ��֪ͨ

	MainBuf(#TMtcBaseInfo_Api tKickInfo )	
	@verbatim
	{
		
	}
	@endverbatim
	*/ 
	Ev_MtApi_Base_HaveBeenKicked_Ntf,
	
	/**
	@brief  ��ȡ�ն˰汾����Ϣ����Ӧ

	Buf(#TMtVersionInfo_Api, tVerInfo )
	@verbatim
	{
		
	}
	@endverbatim
	*/ 
	Ev_MtApi_Base_GetMtBaseInfo_Rsp,

	/**	
	@brief    skyshare״̬��Ӧ,Ev_MtApi_Base_MTCSkyShareLoginState_Rsp
	
	MainBuf(#BOOL32, bloginstate)

	@verbatim
	{
		bloginstate : FALSE
	}
	@endverbatim
	*/
	Ev_MtApi_Base_MTCSkyShareLoginState_Rsp,

	/**	
	@brief    У������Э����̬����Ľ��֪ͨ
	
	MainBuf(#BOOL32, bSuccess)

	@verbatim
	{
		bSuccess : FALSE
	}
	@endverbatim
	*/
	Ev_MtApi_Base_CheckDataConfDynamicPwd_Ntf,

	/**	
	@brief    ����VGA���ͼ�����֪ͨ 
	
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
	@brief    ��ȡVGA���ͼ�������Ӧ  
	
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
	@brief    �������Э����̬����Ľ��֪ͨ ������Ϣ�壩
	
	@verbatim
	{
	}
	@endverbatim
	*/
	Ev_MtApi_Base_CleanDataConfDynamicPwd_Ntf,

	/**	
	@brief   ��ȡ���������Ӧ
	
	MainBuf(#s8 ,achRand)
	SubBuf(#u16, wLen)		//���������
	@verbatim
	{
		"achRand": "123456"
		wLen    : 6
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetTrueRandBytes_Rsp,


	/**
	@brief    ������������Կ�Ƿ�ɹ���֪ͨ
	
	MainBuf(#u32)

	@verbatim
	{
		"basetype": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ResetSecKey_Ntf,

	/**
	@brief    ��������������ɼ���ʽ��֪ͨ
	
	MainBuf(#TCameraVidStd_Api)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetCameraVidStd_Ntf,

	/**
	@brief    ��ȡ����������ɼ���ʽ����Ӧ
	
	MainBuf(#TCameraVidStd_Api)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetCameraVidStd_Rsp,

	/**
	@brief  �ն˵�ǰ�����ӵ�mtc��Ϣ�б���Ӧ

	Buf(#TMtcBaseInfoList_Api, tMtcList )
	@verbatim
	{
		
	}
	@endverbatim
	*/ 
	Ev_MtApi_Base_GetMtcInfoList_Rsp,


	/**
    @brief   ң�����汾���ϱ�
  
    MainBuf(#s8*)
    @verbatim
    {
      "basetype" : ""
    }
    @endverbatim
    */
	Ev_MtApi_Base_DeviceRemoteCtrlVersion_Ntf,

	/**
    @brief   skyshare�ǳ���֪ͨ������Ϣ�Ƕ�access�ع�ǰ���ն� �����ݴ����
  
    MainBuf(#TUserFullInfo_Api�� tInfo)
	SubBuf(#achSkyShareIp��achIp )
    
	@verbatim
    {
    }
    @endverbatim
    */
	Ev_MtApi_Base_OldSkyShareLogOut_Ntf,

    /**	
	@brief    ���������ϱ���־���ļ���ϢNtf
	
	MainBuf(#u32, basetype)
	@verbatim
	{
		basetype : 0 (0-�ɹ�)
	}
	@endverbatim
	*/

	Ev_MtApi_Base_Agent_SetPackLogInfo_Ntf,

    /**	
	@brief    ��ʼ�ϴ���־��Ӧ
	
	MainBuf(#u32, basetype)
	@verbatim
	{
		basetype : 0 (0-�ɹ�)
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Agent_StartUploadLog_Rsp,


    /**	
	@brief    ֪ͨ�ն˴��������Ҫ����־
	*/
    Ev_MtApi_Base_Agent_PackLog_Ntf,

	 /**	
	@brief    ��ȡ�Ƿ�Ϊ�����ն˵���Ӧ
	
	MainBuf(#BOOL32, bIsImixTer)
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetIsImixTer_Rsp,

	/**	
	@brief    �ָ��������õ�֪ͨ����Ӧ�ӿ� KdvMt_MTResetCmd
	
	MainBuf(#BOOL32, bDelCfgFile)
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ResetSystem_Ntf,

    /**	
	@brief    �����ն��ļ����״̬�ظ�
	*/
    Ev_MtApi_Base_Agent_PackFileState_Rsp,

	/**
    @brief   ��ȡSkyMtc�汾�ŵ���Ӧ
  
    MainBuf(#s8*)
    @verbatim
    {
      "basetype" : ""
    }
    @endverbatim
    */
	Ev_MtApi_Base_GetSkyMtcVer_Rsp,

	/**
    @brief   ����osd����Ա����� ֪ͨ��osd�յ������Ϣ���Լ�ȥ�������루û�����ݣ�
  
    MainBuf(#)
    @verbatim
    {
      "basetype" : ""
    }
    @endverbatim
    */
	Ev_MtApi_Base_ResetOsdAdminPwd_Ntf,

	/**
    @brief   ��ȡwebmtc (ǰ��)��¼״̬����Ӧ
  
    MainBuf(#BOOL32, bLogin )
    @verbatim
    {
      
    }
    @endverbatim
    */
	Ev_MtApi_Base_GetWebMtcLoginState_Rsp,

	/**
    @brief   ��ȡwebmtc (ǰ��)��¼״̬��֪ͨ
  
    MainBuf(#BOOL32, bLogin )
    @verbatim
    {
      
    }
    @endverbatim
    */
	Ev_MtApi_Base_GetWebMtcLoginState_Ntf,

	/**
    @brief   ��ȡ�Ƿ����ڵ���ץ������Ӧ
  
    MainBuf(#BOOL32, bExportingNetCap)
    @verbatim
    {
      
    }
    @endverbatim
    */
	Ev_MtApi_GetIsExportingNetCap_Rsp,

	/**
    @brief   ��ȡĬ��·�ɵ���Ӧ
  
	MainBuf(#TRouteItemInfo_Api , tRouteInfo)
    @verbatim
    {
      
    }
    @endverbatim
    */
	Ev_MtApi_Base_GetDefRoute_Rsp,

    /**
	@brief    ��ѯ�ն��Ƿ�ע����dcs��Ӧ
	
	MainBuf(#BOOL32)

	@verbatim
	{
        "basetype" : false
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetIsDcsRigistedRt_Rsp,

	/**
	@brief    �������������λ�õ�֪ͨ
	
	MainBuf(#TCameraLastPos_Api)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetCameraLastPos_Ntf,

	/**
	@brief    ��ȡ���������λ�õ���Ӧ
	
	MainBuf(#TCameraLastPos_Api)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetCameraLastPos_Rsp,

    	/**	
	@brief    APS��½�����ӦEv_MT_BLL_ApsLoginResult_Ntf
	
	MainBuf(#TMtApsLoginErrcode_Api, tMtApsLoginErrcode)
    SubBuf(#TPlatformInfo_Api, tPlf)

    @verbatim
    {
        "MainParam": 
        {
            "achVersion": string //ƽ̨�汾��
            "dwIP" : u32         //��½IP
            "emResourceType": EmResourceType_Api
        }
    }
	*/
	Ev_MtApi_Base_GetAPSPlatformInfo_Rsp,

	/**
	@brief    ������ʾ��������ͼ���֪ͨ
	
	MainBuf(#BOOL32, bShow)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetShowLostPkt_Ntf,

	/**
	@brief    ��ȡ��ʾ��������ͼ�����Ӧ
	
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
	@brief    �����û���¼�������ʱ���֪ͨ
	
	MainBuf(#u32, dwTime)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetUserLoginPwdTimeout_Ntf,

	/**
	@brief    �����û���¼�������ʱ�����Ӧ
	
	MainBuf(#u32, dwTime)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetUserLoginPwdTimeout_Rsp,

	/**
	@brief    �����û���¼���뵽��ʱ��ʣ��ʱ��
	
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
	@brief    �����Ƿ��������ܹ��ܵ�֪ͨ
	
	MainBuf(#BOOL32)

	@verbatim
	{
        "basetype" : false
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetEnableSecureCfg_Ntf,

	/**
	@brief    ��ȡ�Ƿ��������ܹ��ܵ���Ӧ
	
	MainBuf(#BOOL32)

	@verbatim
	{
        "basetype" : false
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetEnableSecureCfg_Rsp,

	/**
	@brief    OSD���ý���û���¼������֪ͨ(����Ϣ��)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetUserLoginUnLock_Ntf,

	/**
    @brief   osd��ȡ�û���¼����״̬����Ӧ
  
    MainBuf(#BOOL32, bLock )
    @verbatim
    {
      
    }
    @endverbatim
    */
	Ev_MtApi_Base_GetUserLoginLockState_Rsp,

	/**
    @brief   �û���¼����״̬��֪ͨ
  
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
    @brief  ��ȡ���������
  
    MainBuf(#TMtHDCameraAiList_Api, bLock )
    @verbatim
    {
      
    }
    @endverbatim
    */
	Ev_MtApi_Base_GetAicameraCfg_Rsp,

	/**
	@brief    osd���ÿ�ݼ�����֪ͨ
	
	MainBuf(#TMtShortCutKeyList_Api, tMtShortCutKeyList)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetShortCutKeyCfg_Ntf,

	/**
	@brief    osd�����ݼ����õ���Ӧ
	
	MainBuf(#TMtShortCutKeyList_Api, tMtShortCutKeyList)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetShortCutKeyCfg_Rsp,

	/**
	@brief   ���������򵼾�̬ͼƬ��֪ͨ
	
	MainBuf(#BOOL32, bSkip)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SkipWizardStaticImage_Ntf,

	Ev_MtApi_Base_AiResetTimer_Ntf,

	/**
	@brief    osd���ù���Ա�û������������Ӧ������Ϣ�壩

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_ResetAdminUserInfo_Ntf,

    /**	
	@brief    ֪ͨ�ն˿�ʼ���Ӳ����Ϣ
	*/
    Ev_MtApi_Base_Agent_DevicePerformance_Ntf,

	/**
	@brief    ��ͨ����׼����Կʧ��(Ŀǰ����)
	@endverbatim
	*/
	Ev_MtApi_Base_QtPrePareKeyError_Ntf,

	/**
	@brief    ��������豸�Ƿ���ڵ���Ϣ���� ����״̬���Ҳ���

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
	@brief    �����Ƿ�����OspTelnet���Թ��ܵ�֪ͨ
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetUseOspTelnet_Ntf,
	
	/**
	@brief    ����OspTelnet���Թ�������״̬����Ӧ
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_GetUseOspTelnet_Rsp,

	/**
	@brief    �����Ƿ���ʹ�����ֱ佹���Ƶ�֪ͨ
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_SetCameraEnableDigZoomCfg_Ntf,
	
	/**
	@brief    ��ȡ�Ƿ���ʹ�����ֱ佹���Ƶ���Ӧ
	
	MainBuf(#BOOL32, bUse)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_Hd_GetCameraEnableDigZoomCfg_Rsp,

	/**
	@brief    ����AI����ͼ���Ƿ���ʾ��֪ͨ
	
	MainBuf(#TMtFunctionIcon_Api, tCfg)

	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Base_SetFunctionIconCfg_Ntf,

	/**
	@brief    ��ȡAI����ͼ���Ƿ���ʾ�Ļظ�
	
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
