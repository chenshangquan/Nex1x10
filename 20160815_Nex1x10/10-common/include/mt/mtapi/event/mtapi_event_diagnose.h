/*******************************************************************************//**
*@file          mtapi_event_diagnose.h
*@brief         实现MTAPI MtDiagnoseSdk 给UI(观察者)事件通知的定义
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_EVENT_DIAGNOSE_H_
#define _MTAPI_EVENT_DIAGNOSE_H_
/**@addtogroup event 事件
*@{
*/

/**@addtogroup dgevent 诊断事件
*@{
*/

#include "mtapi_event_def.h"


enum EmMtApiDiagnoseEv
{
	EV_UI_BGN(MTAPI_DIAGNOSE)  = EVSEG_MTAPI_DIAGNOSE_BGN,
	
	
/**
  @brief    获取系统运行时间响应	

  MainBuf(#u32)
  @verbatim
  {
  "basetype": 0
  }
  @endverbatim
*/
	Ev_MtApi_DiagnoseGetMTRunTime_Rsp,

	/**
  @brief    获取终端信息
  
  MainBuf(#TTerminalInfo_Api)
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
	Ev_MtApi_DiagnoseGetTerInfo_Rsp,
	
/**
  @brief    获取端口占用应答
  
  MainBuf(#TMTTotalUsedPort_Api)
  @verbatim
  
  {
  "atMTUsedPortList" :
  [
  {
  "emPortType" :
  "atTMTUsedPort":
  [
  {
  "dwPort" :0,
  "achName" : "str"
  }
  ]
  }
  ]
  }
  @endverbatim
*/	
	Ev_MtApi_DiagnoseGetPortInfo_Rsp,

/**
  @brief    获取编解码、混音、合成、网络统计信息请求
  

	MainBuf(#TMtCodecStatistic_Api)
	
	@verbatim
	{
		"atAudEncStatic" :
		[
		    {
		    	"emAudEncId" : 0,
			    "dwEncRate" : 0,
				"emAudEncType" : 0
	    	}
		],
		"atAudDecStatic" :
		[
		    {
				"emAudDecId" : 0,
				"dwDecRate" : 0,
				"dwRecFrames" : 0,
				"dwLostPackRatio" : 0,
				"dwLostPacks" : 0,
				"emAudDecType" : 0
		    }
		],
		"atVidEncStatic" :
		[
		{
			"emVidEncId" : 0,
			"dwEncBitrate" : 0,
			"dwFrameRate" : 0,
			"dwVidWidth" : 0,
			"dwVidHeight" : 0,
			"emVidEncType" : 0
		}
		],
		"atVidDecStatic" :
		[
		    {
			  "emVidDecId" : 1,
			   "dwDecBitrate" : 2,
			   "dwRcvFrames" : 3,
			   "dwLostPackRatio" : 4,
			   "dwPhysicalLostPackRatio" : 5
			   "dwLostPacks" : 6,
			   "dwFrameRate" : 7,
			   "dwVidWidth" : 8,
			   "dwVidHeight" : 9,
			   "emVidDecType" : 0
		    }
		],
		"atAudMixStatic" :
		[
		    {
			    "emAudMixId": 0
		    }
		],
		"atVidMixStatic" :
		[
		    {
			   "emVidMixId": 0
		    }
		]
	}
  @endverbatim
*/	
	Ev_MtApi_DiagnoseCodecGetStatistic_Rsp,

/**
  @brief   获取服务器情况应答
  
  MainBuf(#TMTSrvInfoList_Api)
  
  @verbatim
  {
  "atServerList": [
  {
  "achName": "",
  "achDomain": "",
  "dwIP": 1,
  "emState": 1,
  "bUsed": 1
  },
  {
  "achName": "",
  "achDomain": "",
  "dwIP": 1,
  "emState": 1,
  "bUsed": 1
  }
  ]
  }
  @endverbatim
*/	
	Ev_MtApi_DiagnoseGetSrvInfo_Rsp,

/**
  @brief   获取网卡信息
  
	@verbatim

	BODY: 网络管理模块,暂未提供
  @endverbatim
*/
	Ev_MtApi_DiagnoseGetEthInfo_Ntf,

/**
  @brief    扬声器音量通知
  
  MainBuf(#TMTAudioPower_Api )
  @verbatim
  {
  "emStreamType":0
  "emStreamIdx" :0,
  "dwPower": 0
  }
  @endverbatim
*/	
	Ev_MtApi_Diagnose_CodecAudOutPower_Ntf,


/**
  @brief    麦克风音量通知
  
  MainBuf(#TMTAudioPower_Api )
  @verbatim
  {
  "emStreamType":0
  "emStreamIdx" :0,
  "dwPower": 0
  }
  @endverbatim
*/	
	Ev_MtApi_Diagnose_CodecAudInPower_Ntf,

/**
  @brief    色带诊断通知	

  

  @verbatim
	BODY: 无
  @endverbatim
*/
	Ev_MtApi_Diagnose_CodecRibbonTest_Ntf,


	/**
	@brief    自动声音时延检测通知	
	
	MainBuf(#u32, state ) // state(EmAudioDelayCheckState)：检测状态
	SubBuf(#u32, result) //result：当EmAudioDelayCheckState为emAudioDelayChecked时，此值有效，表示时延值
	*             当EmAudioDelayCheckState为emAudioDelayFailed时，此值有效，表示失败错误码
  
  @verbatim
  {
  "MainParam" :
  {
  "basetype" : 0
  },
  "AssParam" :
  {
  "basetype" : 0 
  }
  }
  @endverbatim
*/
	Ev_MtApi_Diagnose_CodecAutoAudioDelayCheck_Ntf,


/**
  @brief    本地回环通知
  
  wParam(CSdkMsg*, msg)\n
  CSdkMsg:\n
  MainBuf(#EmCodecComponent_Api, emCodecType)\n
  MainBuf(#EmCodecComponentIndex_Api, emCodecId)\n
  MainBuf(#BOOL32)
  @verbatim
  {
      "emCodecType": 0,
	  "emCodecId": 0,
	  "bStart": false
  }
  @endverbatim
*/	
	Ev_MtApi_Diagnose_LocalSingleLoop_Ntf,

/**
  @brief    本地回环通知
  
  MainBuf(#BOOL32*, bStart)
  @verbatim
  {
	  "basetype": false
  }
  @endverbatim
*/	
	Ev_MtApi_Diagnose_LocalLoop_Ntf,

/**
  @brief   远端回环通知
  
  wParam(CSdkMsg*, msg)\n
  CSdkMsg:\n
  MainBuf(#EmCodecComponent_Api, emCompType)\n
  MainBuf(#EmCodecComponentIndex_Api, emCompIndx)\n
  MainBuf(#BOOL32)
  
  @verbatim
  {
  "emCompType": 0,
  "emCompIndx": 0,
  "bResult": false
  }
  @endverbatim
*/	
	Ev_MtApi_Diagnose_RemoteLoop_Ntf,

/**
  @brief    音频输入音量响应
  
  MainBuf(#u8)
  
  @verbatim
  {
  "basetype": 0
  }
  @endverbatim
*/	
	Ev_MtApi_MtmpAudioInVolume_Rsp,

/**
  @brief    麦克音量查询响应
  
  MainBuf(#s32)\n
  SubBuf(#u8)
  
  @verbatim
  {
  "MainParam" :
  {
	"basetype" : 0
  },
  "AssParam" :
  {
	"basetype" : 0 
  }
  }
  @endverbatim
*/	
	Ev_MtApi_MtmpMicVolumeDetect_Rsp,

/**
  @brief    音频输入接口状态响应	
  
  MainBuf(#TMultiAudInputState_Api)
  @verbatim
  {
  "byCnt" : 0,
  "atAudInputState" :
  [
  {
  "bUsed" : 0,
  "emAudInputType" : 0 
  }
  ]
  }
  @endverbatim
*/	
	Ev_MtApi_MtmpAudioInputState_Rsp,

/**
  @brief    音频输出接口状态响应	
  
  MainBuf(#TMultiAudOutputState_Api)
  
  @verbatim
  {
  "byCnt" : 0,
  "atAudOutputState" : 
  [
  {
  "bUsed": 0,
  "emAudOutputType" : 0
  }
  ]
  }
  @endverbatim
*/	
	Ev_MtApi_MtmpAudioOutputState_Rsp,

/**
  @brief    查询视频输入分辨率响应
  
  MainBuf(#TMTHDVidInPortCapList_Api)
  
  @verbatim
  {
  "atVideoCapList": [
  {
  "emVideoType": 1,
  "atVideoPort": [
  0,
  1,
  2
  ]
  }
  ]
  }
  @endverbatim
*/	
	Ev_MtApi_MtmpVideoInPortCap_Ntf,


	/**
  @brief    查询视频输入分辨率响应
  
  MainBuf(#TMTHDVidInPortCapList_Api)
  @verbatim
  {
  "atVideoCapList": [
  {
  "emVideoType": 1,
  "atVideoPort": [
  0,
  1,
  2
  ]
  }
  ]
  }
  @endverbatim
*/	
	Ev_MtApi_MtmpVideoInPortCap_Rsp,


	/**
  @brief    查询视频输入分辨率响应
  
  MainBuf(#EmSdiInOut_Api)
  @verbatim
  {
  "basetype" :0
  }
  @endverbatim
*/	
	Ev_MtApi_MtmpGetSdiInOut_Rsp,
/**
  @brief   查询cpu和内存使用情况响应
  
  MainBuf(#TMTCpuAndMemState_Api)
  @verbatim
  {
  "dwCpuIdlePercent" : 0,
  "dwMemTotalSize" : 0,
  "dwMemAllocSize" : 0,
  "dwMemFreeSize" : 0
  }
  @endverbatim
*/
	Ev_MTApi_DeviceDetectCpuAndMem_Rsp,

/**
  @brief   获取本地自环状态响应
  
  MainBuf(#BOOL32)
  @verbatim
  {
      "basetype" : false 
  }
  @endverbatim
*/
	Ev_MTApi_Diagnose_LocalLoopState_Rsp,

/**
  @brief   视频源分辨率查询响应
  
  MainBuf(#TMtVidSrcInfoList_Api)
  @verbatim
  {
		"atInfoList" : [
	
	@verbatim
	{
			"emCodecType" : 0,
			"emCodecId" : 0,
			"dwVideoWidth" : 0,
			"dwVideoHeight" : 0,
			"bVideoProgressive" : false,
			"dwFrameRate" : 0
		}
		]
  }
  @endverbatim
*/
	Ev_MTApi_Diagnose_VidSrcStatus_Rsp,

/**
  @brief   视频源分辨率上报
  
  MainBuf(#TMtVidSrcInfoList_Api)
  @verbatim
  {
		"atInfoList" : [
		{
			"emCodecType" : 0,
			"emCodecId" : 0,
			"dwVideoWidth" : 0,
			"dwVideoHeight" : 0,
			"bVideoProgressive" : false,
			"dwFrameRate" : 0
		}
		]
  }
  @endverbatim
*/
	Ev_MTApi_Diagnose_VidSrcStatus_Ntf,

/**
  @brief   色带测试状态查询响应
  
  MainBuf(#BOOL32)
  @verbatim
  {
      "basetype" : false 
  }
  @endverbatim
*/
    Ev_MTApi_Diagnose_RibbonTestStatus_Rsp,

/**
  @brief   检查U盘响应
  
    MainBuf(#TMTUsbStatus_Api)

	@verbatim
	{
	    "byCnt" : 0,
		"atUsbInfo" :[
			{
				"dwUsbId" : 0,
				"bIsUsed" : false,
				"byCnt" : 0,
				"atPartition" : [
				{
				"achPath" : "",
				"achName" : "",
				"dwTotalSpace" : 0,
				"dwAvailableSpace" : 0
				}
				]
			}
		]
	}
  @endverbatim
*/
	Ev_MtApi_Diagnose_GetUsbStatusRt_Rsp,

/**
  @brief   检查U盘通知
  
  MainBuf(#TMTUsbStatus_Api)
  @verbatim
  {
	{
	    "byCnt" : 0,
		"atUsbInfo" :[
			{
				"dwUsbId" : 0,
				"bIsUsed" : false,
				"byCnt" : 0,
				"atPartition" : [
				{
				"achPath" : "",
				"achName" : "",
				"dwTotalSpace" : 0,
				"dwAvailableSpace" : 0
				}
				]
			}
		]
	}
  }
  @endverbatim
*/
	Ev_MtApi_Diagnose_GetUsbStatusRt_Ntf,

/**
  @brief   目录结构查询响应
  
  MainBuf(#s8)\n
  SubBuf(#TMTPathStructureDetail_Api)
  @verbatim
  {
		"MainParam" :
		{
		    "basetype" : ""
		},
		"AssParam" :
		{
		"atPathUint" : [
			{
				"emFileType" : 0,
				"achFilePath" : ""
			}
		]
		}
  }
  @endverbatim
*/
	Ev_MtApi_Diagnose_InquirePathStructure_Rsp,

/**
 @brief   
		1.提供给向导界面查询输入接口的分辨率 \n
		2.提供给视频源选择界面，显示各视频接口是否有信号，以是否有分辨率来表示是否有信号。
  
    MainBuf(#TMtVidInPortResInfoList_Api)
	@verbatim
	{
	    "dwCount" : 0,
		"atVidInPortStatus" :
		[
			{
				"emVideoPort" : 0,
				"dwVideoWidth" : 0,
				"dwVideoHeight" : 0,
				"bVideoProgressive" : false,
				"dwFrameRate" : 0
			}
		]
	}
  @endverbatim
*/
	Ev_MtApi_Diagnose_GetVidInPortRes_Rsp,

/**
 @brief   
		1.提供给向导界面查询输入接口的分辨率\n
		2.提供给视频源选择界面，显示各视频接口是否有信号，以是否有分辨率来表示是否有信号。
  
    MainBuf(#TMtVidInPortResInfoList_Api)
	@verbatim
	{
	    "dwCount" : 0,
		"atVidInPortStatus" :
		[
			{
				"emVideoPort" : 0,
				"dwVideoWidth" : 0,
				"dwVideoHeight" : 0,
				"bVideoProgressive" : false,
				"dwFrameRate" : 0
			}
		]
	}
  @endverbatim
*/
	Ev_MtApi_Diagnose_GetVidInPortRes_Ntf,

/**
  @brief   查询EPLD/CPLD版本响应
  
  MainBuf(#u32)
  @verbatim
  {
    "basetype" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Diagnose_InquirePldVersion_Rsp,

/**
  @brief   查询FPGA版本响应
  
	@verbatim

  MainBuf(#u32)//FPGA1 \n
  SubBuf(#u32) //FPGA2
  {
    "Fpga1Version" : 0,
	"Fpga2Version" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Diagnose_InquireFpgaVersion_Rsp,

/**
  @brief  查询终端程序是否全部启动成功响应
  
   MainBuf(#BOOL32)
  @verbatim
  {
    "basetype" : false
  }
  @endverbatim
*/
	Ev_MtApi_Diagnose_InquireHDMtStartSucess_Rsp,

/**
  @brief  终端程序全部启动成功通知
  
  @verbatim

  @endverbatim
*/
	Ev_MtApi_Diagnose_HDMtStartSucess_Ntf,

	/**
  @brief  检查文件响应

  MainBuf(#TFileCheckRspBody_Api)
  @verbatim
  {
    "bExist" : false,
	"achFullPathName" : "",
	"dwFileSize" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Diagnose_FileExistCheck_Rsp,

	/**
  @brief  导出地址簿结果
  
  MainBuf(#EmFileCopyErr_Api)
  @verbatim
  {
    "basetype" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Diagnose_AddrBookExport_Rsp,

	/**
  @brief 导出地址簿进度(百分比)
  
  MainBuf(#u32)
  @verbatim
  {
    "basetype" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Diagnose_AddrBookExportProgress_Ntf,

		/**
  @brief  导入地址簿结果
  
  MainBuf(#EmFileCopyErr_Api)
  @verbatim
  {
    "basetype" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Diagnose_AddrBookImport_Rsp,

	/**
  @brief 导入地址簿进度(百分比)
  
  MainBuf(#u32)
  @verbatim
  {
    "basetype" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Diagnose_AddrBookImportProgress_Ntf,

	/**
  @brief   获取视频 远端自环状态响应
  
  wParam(CSdkMsg*, msg)\n
  CSdkMsg:\n
  MainBuf(#EmCodecComponent_Api, emCompType)\n
  MainBuf(#EmCodecComponentIndex_Api, emCompIndx)\n
  MainBuf(#BOOL32)
  @verbatim
  {
  "emCompType": 0,
  "emCompIndx": 0,
  "bResult": false
  }
  @endverbatim
*/
	Ev_MTApi_Diagnose_RemoteLoopState_Rsp,

/**
    @brief   麦克风连接状态应答
    
    MainBuf(#TMTAllMicStatus_Api)

	@verbatim
	{
		"atMicStatus" :[
			{
			    "dwMicId" : "",
			    "dwStatus" : ""
			}
		],
		"dwCnt" : 0
	}
    @endverbatim
*/
	Ev_MTApi_Diagnose_MicrophoneConnectStatus_Rsp,
	
/**
    @brief   麦克风连接状态通知
    
    MainBuf(#TMTAllMicStatus_Api)

	@verbatim
	{
		"atMicStatus" :[
			{
			    "dwMicId" : "",
			    "dwStatus" : ""
			}
		],
		"dwCnt" : 0
	}
    @endverbatim
*/
	Ev_MTApi_Diagnose_MicrophoneConnectStatus_Ntf,

	/**
    @brief   麦克风无线电量应答
    
    MainBuf(#TMTAllMicStatus_Api)

	@verbatim
	{
		"atMicStatus" :[
			{
			    "dwMicId" : "",
			    "dwStatus" : ""
			}
		],
		"dwCnt" : 0
	}
    @endverbatim
*/
	Ev_MTApi_Diagnose_MicrophoneBatteryLevel_Rsp,
	
/**
    @brief   麦克风无线电量通知
    
    MainBuf(#TMTAllMicStatus_Api)

	@verbatim
	{
		"atMicStatus" :[
			{
			    "dwMicId" : "",
			    "dwStatus" : ""
			}
		],
		"dwCnt" : 0
	}
    @endverbatim
*/
	Ev_MTApi_Diagnose_MicrophoneBatteryLevel_Ntf,

/**
    @brief   麦克风更新包上传状态应答
    
    MainBuf(#TMTAllMicStatus_Api)

	@verbatim
	{
		"atMicStatus" :[
			{
			    "dwMicId" : "",
			    "dwStatus" : ""
			}
		],
		"dwCnt" : 0
	}
    @endverbatim
*/
	Ev_MTApi_Diagnose_MicrophoneVersionStatus_Rsp,
	
/**
    @brief   麦克风更新包上传状态通知
    
    MainBuf(#TMTAllMicStatus_Api)

	@verbatim
	{
		"atMicStatus" :[
			{
			    "dwMicId" : "",
			    "dwStatus" : ""
			}
		],
		"dwCnt" : 0
	}
    @endverbatim
*/
	Ev_MTApi_Diagnose_MicrophoneVersionStatus_Ntf,

/**
    @brief   麦克风升级通知
    
    MainBuf(#TMTAllMicStatus_Api)

	@verbatim
	{
		"atMicStatus" :[
			{
			    "dwMicId" : "",
			    "dwStatus" : ""
			}
		],
		"dwCnt" : 0
	}
    @endverbatim
*/
	Ev_MTApi_Diagnose_MicrophoneUpgrade_Ntf,

/**
    @brief   开启射频热点应答
    
    MainBuf(#TMTAllMicStatus_Api)

	@verbatim
	{
		"atMicStatus" :[
			{
			    "dwMicId" : "",
			    "dwStatus" : ""
			}
		],
		"dwCnt" : 0
	}
    @endverbatim
*/
	Ev_MTApi_Diagnose_OpenHotspot_Rsp,

/**
    @brief   射频状态应答
    
    MainBuf(#TMTAllMicStatus_Api)

	@verbatim
	{
		"atMicStatus" :[
			{
			    "dwMicId" : "",
			    "dwStatus" : ""
			}
		],
		"dwCnt" : 0
	}
    @endverbatim
*/
	Ev_MTApi_Diagnose_GetHotspotStatus_Rsp,

/**
    @brief   终端射频配对状态列表通知
    
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
	Ev_MTApi_Diagnose_SetRfMatchStateListCfg_Ntf,

/**
    @brief   OSD穿透开关响应
    
    MainBuf(#BOOL32)\n
	SubBuf(#EmOsdTransparentResult_Api)

	@verbatim
	{
		"bTrans": false,
		"emResult": 0
	}
    @endverbatim
*/
	Ev_MTApi_Diagnose_SetOsdTransparent_Rsp,

/**
    @brief   OSD界面是否在浏览快照通知
    
    MainBuf(#BOOL32)

	@verbatim
	{
		"basetype": false
	}
    @endverbatim
*/
	Ev_MTApi_Diagnose_OsdSnapshotBrowse_Ntf,

/**
    @brief   提示框同步通知
    
    @endverbatim
*/
	Ev_MTApi_Diagnose_SyncTooltipBox_Ntf,

/**
    @brief   无线麦克风电量过低（低于一格）通知
    
    MainBuf(#BOOL32)

	@verbatim
	{
		"basetype": false
	}
    @endverbatim
*/
	Ev_MTApi_Diagnose_WirelessMicrophoneBatteryLow_Ntf,

/**
    @brief   获取抓包文件列表请求的响应
   
    MainBuf(#TNetCapFileList_Api)
	@verbatim
    {
        "achFilePath" : "",
        "byFileCnt" : 0,
        "atFileList" :
        [
            {
                "achFileName" : "",
                "dwFileSize" : 0        
            }
        ]
    }
    @endverbatim
*/
	Ev_MTApi_Diagnose_GetNetCapFileList_Rsp,

/**
    @brief   麦克风版本信息应答
    
    MainBuf(#TMicVersionList_Api)
	@verbatim
    {
        "byCnt" : 0,
        "atVersionList" :
        [
            {
                "dwMicId" : 0,
                "achVersion" : ""
            }
        ]
    }
    @endverbatim
*/
	Ev_MTApi_Diagnose_GetMicrophoneVerInfo_Rsp,

/**
    @brief   麦克风版本信息通知
    
    MainBuf(#TMicVersionList_Api)
	@verbatim
    {
        "byCnt" : 0,
        "atVersionList" :
        [
            {
                "dwMicId" : 0,
                "achVersion" : ""
            }
        ]
    }
    @endverbatim
*/
	Ev_MTApi_Diagnose_MicrophoneVerInfo_Ntf,

/**
    @brief   获取终端是否在抓包状态的响应
    
    MainBuf(#u32)
	@verbatim
    {
        "basetype" : 0  // 1:正在抓包  0:没有抓包
    }
    @endverbatim
*/
	Ev_MTApi_Diagnose_GetCurCapStatus_Rsp,

/**
    @brief   登录服务器连接测试结果上报
    
    MainBuf(#TServerTestResult_Api)
	@verbatim
    {
        "dwUserId" : 0,
        "bResult" : false
    }
    @endverbatim
*/
	Ev_MTApi_Diagnose_ServerTest_Ntf,

/**
    @brief   <<麦克风状态应答>>
    
    MainBuf(#TMicUpgradeStateList_Api)
	@verbatim
    {
        "dwCnt" : 0,
        "atStateList": 
        [
            {
                "dwMicId" : 0,
                "dwState" : 0,
                "dwProgress" : 0
            }
        ]
    }
    @endverbatim
*/
	Ev_MTApi_Diagnose_MicrophoneState_Rsp,

/**
    @brief   <<麦克风状态通知>>
    
    MainBuf(#EmMicUpgradeState_Api)
	@verbatim
    {
        "dwCnt" : 0,
        "atStateList": 
        [
            {
                "dwMicId" : 0,
                "dwState" : 0,
                "dwProgress" : 0
            }
        ]
    }
    @endverbatim
*/
	Ev_MTApi_Diagnose_MicrophoneState_Ntf,

/**
    @brief   <<麦克风上传进度上报>>

    MainBuf(#u32)
	@verbatim
    {
        "basetype": 0
    }
    @endverbatim
*/
	Ev_MTApi_Diagnose_MicrophoneUpload_Ntf,

/**
    @brief   <<导入麦克风升级文件响应>>
    MainBuf(#EmFileCopyErr_Api)
    @verbatim
    {
        "basetype": 0
    }
    @endverbatim
*/
	Ev_MTApi_Diagnose_MicUpgradeFileImport_Rsp,

/**
    @brief   <<导入麦克风升级文件进度>>
    MainBuf(#u32)
    @verbatim
    {
        "basetype": 0
    }
    @endverbatim
*/
    Ev_MTApi_Diagnose_MicUpgradeFileImportProgress_Ntf,

/**
    @brief   <<导出所有日志文件响应>>
    MainBuf(#EmFileCopyErr_Api)
    @verbatim
    {
        "basetype": 0
    }
    @endverbatim
*/
	Ev_MTApi_Diagnose_ExportAllFiles_Rsp,

/**
    @brief   <<导出日志进度>>
    MainBuf(#u32)
    @verbatim
    {
        "basetype": 0
    }
    @endverbatim
*/
    Ev_MTApi_Diagnose_ExportAllFilesProgress_Ntf,

    /**
  @brief   查询设备含有E1模块数量, x500设备不含E1模块：0；包含：4；
  
  MainBuf(#u32)
  @verbatim
  {
    "basetype" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Diagnose_GetE1ModuleNum_Rsp,

	/**
  @brief   查询FPGA版本响应
  
	@verbatim

  MainBuf(#TMTFpgaVersionList_Api)
  {
	  "dwCnt" : 0,
	  "atFpgaVersion": 
      [
         {
			"fpgaversion": 0
         }
      ]
  }
  @endverbatim
*/
	Ev_MtApi_Diagnose_NewInquireFpgaVersion_Rsp,

	/**
	@brief 主动上报摄像机列表，对应于Ev_MT_BLL_HD_GetCameraListCfg_Ntf
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
	Ev_MtApi_Base_Hd_GetCameraListCfg_Ntf,
	/**
	@brief 
	MainBuf(#EmGeneralLevel_Api, emGeneralLevel)

	@verbatim
	{
	    "emGeneralLevel" : 0    
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_IspImgInfSharpness_Rsp,
	/**
	@brief 
	MainBuf(#EmGeneralLevel_Api, emGeneralLevel)

	@verbatim
	{
	    "emGeneralLevel" : 0    
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_IspImgInfSharpness_Ntf,
	/**
	@brief 
	MainBuf(#EmNFMode_Api, emNFMode)

	@verbatim
	{
	    "emNFMode" : 0    
	}
	@endverbatim
	*/	
	Ev_MtApi_Diagnose_IspImgInfNoise_Rsp,
	/**
	@brief 
	MainBuf(#EmNFMode_Api, emNFMode)

	@verbatim
	{
	    "emNFMode" : 0    
	}
	@endverbatim
	*/	
	Ev_MtApi_Diagnose_IspImgInfNoise_Ntf,
	/**
	@brief 
	MainBuf(#EmISO_Api, emISO)

	@verbatim
	{
	    "emISO" : 0    
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_IspImgInfISO_Rsp,
	/**
	@brief 
	MainBuf(#EmISO_Api, emISO)

	@verbatim
	{
	    "emISO" : 0    
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_IspImgInfISO_Ntf,
	/**
	@brief 
	MainBuf(#EmExposureMode_Api, emExposureMode)

	@verbatim
	{
	    "emExposureMode" : 0    
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_IspImgInfExposureMode_Rsp,
	/**
	@brief 
	MainBuf(#EmExposureMode_Api, emExposureMode)

	@verbatim
	{
	    "emExposureMode" : 0    
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_IspImgInfExposureMode_Ntf,
	/**
	@brief 
	MainBuf(#EmAperture_Api, emAperture)

	@verbatim
	{
	    "emAperture" : 0    
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_IspImgInfAperture_Rsp,
	/**
	@brief 
	MainBuf(#EmAperture_Api, emAperture)

	@verbatim
	{
	    "emAperture" : 0    
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_IspImgInfAperture_Ntf,
	/**
	@brief 
	MainBuf(#EmShutterLevel_Api, emShutterLevel)

	@verbatim
	{
	    "emShutterLevel" : 0    
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_IspImgInfShutter_Rsp,
	/**
	@brief 
	MainBuf(#EmShutterLevel_Api, emShutterLevel)

	@verbatim
	{
	    "emShutterLevel" : 0    
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_IspImgInfShutter_Ntf,
	/**
	@brief 
	MainBuf(#EmWBAMode_Api, emWBAMode)

	@verbatim
	{
	    "emWBAMode" : 0    
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_IspImgInfWhiteBalance_Rsp,
	/**
	@brief 
	MainBuf(#EmWBAMode_Api, emWBAMode)

	@verbatim
	{
	    "emWBAMode" : 0    
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_IspImgInfWhiteBalance_Ntf,

	/**
	@brief 
	MainBuf(#BOOL32, bIsExist)

	@verbatim
	{
	    "bIsExist" : FALSE   
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetIsDbgCfgExist_Rsp,

	/**
	@brief 
	MainBuf(#u32, dwPercent)

	@verbatim
	{
	    
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_ExportNetCaptureProgress_Ntf,

	/**
	@brief 
	MainBuf(#u32, dwRet)

	@verbatim
	{
	    
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_DeleteNetCapFile_Ntf,

	/**
	@brief 获取终端保存的麦克风版本信息响应
	MainBuf(#s8, achMicrophoneInfo)

	@verbatim
	{
	    
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_TermKeepMicrophoneInfo_Rsp,

	/**
	@brief 设置ISP图像降噪信息的通知
	MainBuf(#TMTIspImgNFInfo_Api, tInfo )

	@verbatim
	{
	    "emType"  : 0
		"byValue" : 1
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetIspImgNoise_Ntf,

	/**
	@brief 获取ISP图像降噪信息的响应
	MainBuf(#TMTIspImgNFInfo_Api, tInfo )

	@verbatim
	{
	    "emType"  : 0
		"byValue" : 1
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetIspImgNoise_Rsp,

	/**
	@brief 设置ISP图像锐度信息的通知
	MainBuf(#TMTIspImgSharpnessInfo_Api, tInfo )

	@verbatim
	{
		"byValue" : 1
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetIspImgSharpness_Ntf,

	/**
	@brief 获取ISP图像锐度信息的响应
	MainBuf(#TMTIspImgSharpnessInfo_Api, tInfo )

	@verbatim
	{
		"byValue" : 1
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetIspImgSharpness_Rsp,

	/**
	@brief 设置ISP图像曝光增益信息的通知
	MainBuf(#TMTIspImgExposureGain_Api, tInfo )

	@verbatim
	{
		"emType" : 0
		"emGain" : 1
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetIspImgExposureGain_Ntf,

	/**
	@brief 获取ISP图像曝光增益信息的响应
	MainBuf(#TMTIspImgExposureGain_Api, tInfo )

	@verbatim
	{
		"emType" : 0
		"emGain" : 1
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetIspImgExposureGain_Rsp,

	/**
	@brief 设置ISP图像白平衡增益信息的通知
	MainBuf(#TMTIspImgWBAGainInfo_Api, tInfo )

	@verbatim
	{
		"emType" : 0
		"emGain" : 10
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetIspImgWBAGain_Ntf,

	/**
	@brief 获取ISP图像白平衡增益信息的响应
	MainBuf(#TMTIspImgWBAGainInfo_Api, tInfo )

	@verbatim
	{
		"emType" : 0
		"emGain" : 10
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetIspImgWBAGain_Rsp,

	/**
	@brief 设置Isp伽马参数的通知
	MainBuf(#u32, dwValue )

	@verbatim
	{
		"dwValue": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetIspImgGamma_Ntf,

	/**
	@brief 获取Isp伽马参数的响应
	MainBuf(#u32, dwValue )

	@verbatim
	{
		"dwValue": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetIspImgGamma_Rsp,

	/**
	@brief 设置Isp数字去雾的通知
	MainBuf(#u32, dwValue )

	@verbatim
	{
		"dwValue": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetIspImgDefog_Ntf,

	/**
	@brief 获取Isp数字去雾的响应
	MainBuf(#u32, dwValue )

	@verbatim
	{
		"dwValue": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetIspImgDefog_Rsp,

	/**
	@brief 设置Isp数字宽动态开关通知
	MainBuf(#BOOL32, bOn )

	@verbatim
	{
		"bOn": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetIspImgDigDynSwitch_Ntf,

	/**
	@brief 获取Isp数字宽动态开关响应
	MainBuf(#BOOL32, bOn )

	@verbatim
	{
		"bOn": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetIspImgDigDynSwitch_Rsp,

	/**
	@brief 设置Isp数字宽动态等级通知
	MainBuf(#u32, dwValue )

	@verbatim
	{
		"dwValue": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetIspImgDigDynLevel_Ntf,

	/**
	@brief 获取Isp数字宽动态等级响应
	MainBuf(#u32, dwValue )

	@verbatim
	{
		"dwValue": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetIspImgDigDynLevel_Rsp,
	
	/**
	@brief 设置Isp背光补偿开关通知
	MainBuf(#BOOL32, bOn )

	@verbatim
	{
		"bOn": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetIspImgBackLightSwitch_Ntf,

	/**
	@brief 获取Isp背光补偿开关响应
	MainBuf(#BOOL32, bOn )

	@verbatim
	{
		"bOn": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetIspImgBackLightSwitch_Rsp,
	
	/**
	@brief 设置Isp背光补偿等级通知
	MainBuf(#u32, dwValue )

	@verbatim
	{
		"dwValue": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetIspImgBackLightLevel_Ntf,

	/**
	@brief 获取Isp背光补偿等级响应
	MainBuf(#u32, dwValue )

	@verbatim
	{
		"dwValue": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetIspImgBackLightLevel_Rsp,

	/**
	@brief 打开osd显示的回复
	MainBuf(#BOOL32, bSuccess )

	@verbatim
	{
		"bSuccess": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetOsdOpen_Ntf,

	/**
	@brief 关闭osd显示的回复
	MainBuf(#BOOL32, bSuccess )

	@verbatim
	{
		"bSuccess": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetOsdClose_Ntf,

	/**
	@brief 设置摄像机图像模式的通知
	MainBuf(#TMtCameraImgInfo_Api, tInfo )

	@verbatim
	{
		"emImgMode": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetCameraImgMode_Ntf,

	/**
	@brief 请求摄像机图像模式的响应
	MainBuf(#TMtCameraImgInfo_Api, tInfo )

	@verbatim
	{
		"emImgMode": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetCameraImgMode_Rsp,

	/**
	@brief 设置摄像机人物优先开关的通知
	MainBuf(#BOOL32, bOn )

	@verbatim
	{
		"bOn": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetCameraPersonFirst_Ntf,

	/**
	@brief 请求摄像机人物优先开关的响应
	MainBuf(#BOOL32, bOn )

	@verbatim
	{
		"bOn": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetCameraPersonFirst_Rsp,

	/**
	@brief 设置摄像机场景模式的通知
	MainBuf(#TMtCameraSceneModeInfo_Api )

	@verbatim
	{
		dwVidIdx: 0	
		emSceneMode: 0	
		dwRet: 0		
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetCameraSceneMode_Ntf,

	/**
	@brief 设置摄像机场景模式的通知
	MainBuf(#TMtCameraSceneModeCapList_Api )

	@verbatim
	{
		"byCnt": 0
		"abySceneList" :
		[
			{
				dwValue: 0
			}
		]
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetCameraSceneMode_Rsp,

	/**
	@brief 摄像头升级包名称获取响应
	MainBuf(#EmMtVideoPort_Api, emVidPort )
	SubBuf(#s8, achPackName);
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetCameraUpgradePack_Rsp,

	/**
	@brief 本地辅流扩声设置的回复
	MainBuf(#BOOL32, bOpen )
	SubBuf(#u32, dwRet );
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetLocalAssAudExp_Ntf,

	/**
	@brief 本地辅流扩声获取请求的响应
	MainBuf(#BOOL32, bOpen )
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetLocalAssAudExp_Rsp,

	/**
	@brief   获取音频 远端自环状态响应
  
	wParam(CSdkMsg*, msg)\n
	CSdkMsg:\n
	MainBuf(#EmCodecComponent_Api, emCompType)\n
	MainBuf(#EmCodecComponentIndex_Api, emCompIndx)\n
	MainBuf(#BOOL32)
	@verbatim
	{	
	"emCompType": 0,
	"emCompIndx": 0,
	"bResult": false
	}
	@endverbatim
	*/
	Ev_MTApi_Diagnose_AudRmtLoopState_Rsp,

	/**
	@brief 导出诊断信息文件回复
	MainBuf(#u32, dwRet )
	SubBuf(#s8, achFilePach)
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_ExportDiagInfoFile_Ntf,

	/**
	@brief 导出诊断信息文件进度通知
	MainBuf(#u32, dwPercent )
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_ExportDiagInfoProgress_Ntf,

	/**
	@brief 投屏状态通知
	MainBuf(#TMtQkState_Api, tState )
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_MtQkState_Ntf,

	/**
	@brief 当前抓包持续时间响应
	MainBuf(#u32, dwTime )
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetPacketDurationTime_Rsp,

	/**	
	@brief     设置图像亮度、对比度、饱和度等ISP参数的通知
	
	MainBuf(#EmCodecComponent_Api)
	MainBuf(#EmCodecComponentIndex_Api)
	MainBuf(#EmIspImgInf_Api)
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
	Ev_MtApi_Diagnose_SetIspParam_Ntf,	

	/**	
	@brief   获取查询视频亮度、对比度、饱和度等ISP参数的响应
	
	MainBuf(EmCodecComponent_Api)
	MainBuf(EmCodecComponentIndex_Api)
	MainBuf(EmIspImgInf_Api)
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
	Ev_MtApi_Diagnose_GetIspParam_Rsp, 

	/**
	@brief 除雾命令响应
	MainBuf(#BOOL32, bElectricFan )
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_ElectricFan_Ntf,

	/**
	@brief 当前除雾剩余时间响应
	MainBuf(#u32, dwTime )
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetElectricFanTime_Rsp,

	/**
	@brief 设置智能摄像机的通知
	MainBuf(#u32, dwTime )
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetAiCamera_Ntf,

	/**
	@brief 人数统计结果
	MainBuf(#TMtPeopleCountingResult_Api )
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_PeopleCountingResult_Ntf,
	/**
	@brief 人脸签到信息
	MainBuf(#TMtFaceCheckInList_Api )
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_FaceCheckInInfo_Ntf,

    EV_UI_END(MTAPI_DIAGNOSE) = EVSEG_MTAPI_DIAGNOSE_END
};

#define Is_MtApiDiagnose_Msg(m) ((m) >= EV_UI_BGN(MTAPI_DIAGNOSE) && (m) <= EV_UI_END(MTAPI_DIAGNOSE))

/**@}*/

/**@}*/
#endif // _MTAPI_EVENT_DIAGNOSE_H_
