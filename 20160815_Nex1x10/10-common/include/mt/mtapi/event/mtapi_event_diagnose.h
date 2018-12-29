/*******************************************************************************//**
*@file          mtapi_event_diagnose.h
*@brief         ʵ��MTAPI MtDiagnoseSdk ��UI(�۲���)�¼�֪ͨ�Ķ���
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_EVENT_DIAGNOSE_H_
#define _MTAPI_EVENT_DIAGNOSE_H_
/**@addtogroup event �¼�
*@{
*/

/**@addtogroup dgevent ����¼�
*@{
*/

#include "mtapi_event_def.h"


enum EmMtApiDiagnoseEv
{
	EV_UI_BGN(MTAPI_DIAGNOSE)  = EVSEG_MTAPI_DIAGNOSE_BGN,
	
	
/**
  @brief    ��ȡϵͳ����ʱ����Ӧ	

  MainBuf(#u32)
  @verbatim
  {
  "basetype": 0
  }
  @endverbatim
*/
	Ev_MtApi_DiagnoseGetMTRunTime_Rsp,

	/**
  @brief    ��ȡ�ն���Ϣ
  
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
  @brief    ��ȡ�˿�ռ��Ӧ��
  
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
  @brief    ��ȡ����롢�������ϳɡ�����ͳ����Ϣ����
  

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
  @brief   ��ȡ���������Ӧ��
  
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
  @brief   ��ȡ������Ϣ
  
	@verbatim

	BODY: �������ģ��,��δ�ṩ
  @endverbatim
*/
	Ev_MtApi_DiagnoseGetEthInfo_Ntf,

/**
  @brief    ����������֪ͨ
  
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
  @brief    ��˷�����֪ͨ
  
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
  @brief    ɫ�����֪ͨ	

  

  @verbatim
	BODY: ��
  @endverbatim
*/
	Ev_MtApi_Diagnose_CodecRibbonTest_Ntf,


	/**
	@brief    �Զ�����ʱ�Ӽ��֪ͨ	
	
	MainBuf(#u32, state ) // state(EmAudioDelayCheckState)�����״̬
	SubBuf(#u32, result) //result����EmAudioDelayCheckStateΪemAudioDelayCheckedʱ����ֵ��Ч����ʾʱ��ֵ
	*             ��EmAudioDelayCheckStateΪemAudioDelayFailedʱ����ֵ��Ч����ʾʧ�ܴ�����
  
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
  @brief    ���ػػ�֪ͨ
  
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
  @brief    ���ػػ�֪ͨ
  
  MainBuf(#BOOL32*, bStart)
  @verbatim
  {
	  "basetype": false
  }
  @endverbatim
*/	
	Ev_MtApi_Diagnose_LocalLoop_Ntf,

/**
  @brief   Զ�˻ػ�֪ͨ
  
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
  @brief    ��Ƶ����������Ӧ
  
  MainBuf(#u8)
  
  @verbatim
  {
  "basetype": 0
  }
  @endverbatim
*/	
	Ev_MtApi_MtmpAudioInVolume_Rsp,

/**
  @brief    ���������ѯ��Ӧ
  
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
  @brief    ��Ƶ����ӿ�״̬��Ӧ	
  
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
  @brief    ��Ƶ����ӿ�״̬��Ӧ	
  
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
  @brief    ��ѯ��Ƶ����ֱ�����Ӧ
  
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
  @brief    ��ѯ��Ƶ����ֱ�����Ӧ
  
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
  @brief    ��ѯ��Ƶ����ֱ�����Ӧ
  
  MainBuf(#EmSdiInOut_Api)
  @verbatim
  {
  "basetype" :0
  }
  @endverbatim
*/	
	Ev_MtApi_MtmpGetSdiInOut_Rsp,
/**
  @brief   ��ѯcpu���ڴ�ʹ�������Ӧ
  
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
  @brief   ��ȡ�����Ի�״̬��Ӧ
  
  MainBuf(#BOOL32)
  @verbatim
  {
      "basetype" : false 
  }
  @endverbatim
*/
	Ev_MTApi_Diagnose_LocalLoopState_Rsp,

/**
  @brief   ��ƵԴ�ֱ��ʲ�ѯ��Ӧ
  
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
  @brief   ��ƵԴ�ֱ����ϱ�
  
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
  @brief   ɫ������״̬��ѯ��Ӧ
  
  MainBuf(#BOOL32)
  @verbatim
  {
      "basetype" : false 
  }
  @endverbatim
*/
    Ev_MTApi_Diagnose_RibbonTestStatus_Rsp,

/**
  @brief   ���U����Ӧ
  
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
  @brief   ���U��֪ͨ
  
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
  @brief   Ŀ¼�ṹ��ѯ��Ӧ
  
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
		1.�ṩ���򵼽����ѯ����ӿڵķֱ��� \n
		2.�ṩ����ƵԴѡ����棬��ʾ����Ƶ�ӿ��Ƿ����źţ����Ƿ��зֱ�������ʾ�Ƿ����źš�
  
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
		1.�ṩ���򵼽����ѯ����ӿڵķֱ���\n
		2.�ṩ����ƵԴѡ����棬��ʾ����Ƶ�ӿ��Ƿ����źţ����Ƿ��зֱ�������ʾ�Ƿ����źš�
  
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
  @brief   ��ѯEPLD/CPLD�汾��Ӧ
  
  MainBuf(#u32)
  @verbatim
  {
    "basetype" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Diagnose_InquirePldVersion_Rsp,

/**
  @brief   ��ѯFPGA�汾��Ӧ
  
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
  @brief  ��ѯ�ն˳����Ƿ�ȫ�������ɹ���Ӧ
  
   MainBuf(#BOOL32)
  @verbatim
  {
    "basetype" : false
  }
  @endverbatim
*/
	Ev_MtApi_Diagnose_InquireHDMtStartSucess_Rsp,

/**
  @brief  �ն˳���ȫ�������ɹ�֪ͨ
  
  @verbatim

  @endverbatim
*/
	Ev_MtApi_Diagnose_HDMtStartSucess_Ntf,

	/**
  @brief  ����ļ���Ӧ

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
  @brief  ������ַ�����
  
  MainBuf(#EmFileCopyErr_Api)
  @verbatim
  {
    "basetype" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Diagnose_AddrBookExport_Rsp,

	/**
  @brief ������ַ������(�ٷֱ�)
  
  MainBuf(#u32)
  @verbatim
  {
    "basetype" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Diagnose_AddrBookExportProgress_Ntf,

		/**
  @brief  �����ַ�����
  
  MainBuf(#EmFileCopyErr_Api)
  @verbatim
  {
    "basetype" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Diagnose_AddrBookImport_Rsp,

	/**
  @brief �����ַ������(�ٷֱ�)
  
  MainBuf(#u32)
  @verbatim
  {
    "basetype" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Diagnose_AddrBookImportProgress_Ntf,

	/**
  @brief   ��ȡ��Ƶ Զ���Ի�״̬��Ӧ
  
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
    @brief   ��˷�����״̬Ӧ��
    
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
    @brief   ��˷�����״̬֪ͨ
    
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
    @brief   ��˷����ߵ���Ӧ��
    
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
    @brief   ��˷����ߵ���֪ͨ
    
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
    @brief   ��˷���°��ϴ�״̬Ӧ��
    
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
    @brief   ��˷���°��ϴ�״̬֪ͨ
    
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
    @brief   ��˷�����֪ͨ
    
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
    @brief   ������Ƶ�ȵ�Ӧ��
    
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
    @brief   ��Ƶ״̬Ӧ��
    
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
    @brief   �ն���Ƶ���״̬�б�֪ͨ
    
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
    @brief   OSD��͸������Ӧ
    
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
    @brief   OSD�����Ƿ����������֪ͨ
    
    MainBuf(#BOOL32)

	@verbatim
	{
		"basetype": false
	}
    @endverbatim
*/
	Ev_MTApi_Diagnose_OsdSnapshotBrowse_Ntf,

/**
    @brief   ��ʾ��ͬ��֪ͨ
    
    @endverbatim
*/
	Ev_MTApi_Diagnose_SyncTooltipBox_Ntf,

/**
    @brief   ������˷�������ͣ�����һ��֪ͨ
    
    MainBuf(#BOOL32)

	@verbatim
	{
		"basetype": false
	}
    @endverbatim
*/
	Ev_MTApi_Diagnose_WirelessMicrophoneBatteryLow_Ntf,

/**
    @brief   ��ȡץ���ļ��б��������Ӧ
   
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
    @brief   ��˷�汾��ϢӦ��
    
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
    @brief   ��˷�汾��Ϣ֪ͨ
    
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
    @brief   ��ȡ�ն��Ƿ���ץ��״̬����Ӧ
    
    MainBuf(#u32)
	@verbatim
    {
        "basetype" : 0  // 1:����ץ��  0:û��ץ��
    }
    @endverbatim
*/
	Ev_MTApi_Diagnose_GetCurCapStatus_Rsp,

/**
    @brief   ��¼���������Ӳ��Խ���ϱ�
    
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
    @brief   <<��˷�״̬Ӧ��>>
    
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
    @brief   <<��˷�״̬֪ͨ>>
    
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
    @brief   <<��˷��ϴ������ϱ�>>

    MainBuf(#u32)
	@verbatim
    {
        "basetype": 0
    }
    @endverbatim
*/
	Ev_MTApi_Diagnose_MicrophoneUpload_Ntf,

/**
    @brief   <<������˷������ļ���Ӧ>>
    MainBuf(#EmFileCopyErr_Api)
    @verbatim
    {
        "basetype": 0
    }
    @endverbatim
*/
	Ev_MTApi_Diagnose_MicUpgradeFileImport_Rsp,

/**
    @brief   <<������˷������ļ�����>>
    MainBuf(#u32)
    @verbatim
    {
        "basetype": 0
    }
    @endverbatim
*/
    Ev_MTApi_Diagnose_MicUpgradeFileImportProgress_Ntf,

/**
    @brief   <<����������־�ļ���Ӧ>>
    MainBuf(#EmFileCopyErr_Api)
    @verbatim
    {
        "basetype": 0
    }
    @endverbatim
*/
	Ev_MTApi_Diagnose_ExportAllFiles_Rsp,

/**
    @brief   <<������־����>>
    MainBuf(#u32)
    @verbatim
    {
        "basetype": 0
    }
    @endverbatim
*/
    Ev_MTApi_Diagnose_ExportAllFilesProgress_Ntf,

    /**
  @brief   ��ѯ�豸����E1ģ������, x500�豸����E1ģ�飺0��������4��
  
  MainBuf(#u32)
  @verbatim
  {
    "basetype" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Diagnose_GetE1ModuleNum_Rsp,

	/**
  @brief   ��ѯFPGA�汾��Ӧ
  
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
	@brief �����ϱ�������б���Ӧ��Ev_MT_BLL_HD_GetCameraListCfg_Ntf
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
	@brief ��ȡ�ն˱������˷�汾��Ϣ��Ӧ
	MainBuf(#s8, achMicrophoneInfo)

	@verbatim
	{
	    
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_TermKeepMicrophoneInfo_Rsp,

	/**
	@brief ����ISPͼ������Ϣ��֪ͨ
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
	@brief ��ȡISPͼ������Ϣ����Ӧ
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
	@brief ����ISPͼ�������Ϣ��֪ͨ
	MainBuf(#TMTIspImgSharpnessInfo_Api, tInfo )

	@verbatim
	{
		"byValue" : 1
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetIspImgSharpness_Ntf,

	/**
	@brief ��ȡISPͼ�������Ϣ����Ӧ
	MainBuf(#TMTIspImgSharpnessInfo_Api, tInfo )

	@verbatim
	{
		"byValue" : 1
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetIspImgSharpness_Rsp,

	/**
	@brief ����ISPͼ���ع�������Ϣ��֪ͨ
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
	@brief ��ȡISPͼ���ع�������Ϣ����Ӧ
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
	@brief ����ISPͼ���ƽ��������Ϣ��֪ͨ
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
	@brief ��ȡISPͼ���ƽ��������Ϣ����Ӧ
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
	@brief ����Isp٤�������֪ͨ
	MainBuf(#u32, dwValue )

	@verbatim
	{
		"dwValue": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetIspImgGamma_Ntf,

	/**
	@brief ��ȡIsp٤���������Ӧ
	MainBuf(#u32, dwValue )

	@verbatim
	{
		"dwValue": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetIspImgGamma_Rsp,

	/**
	@brief ����Isp����ȥ���֪ͨ
	MainBuf(#u32, dwValue )

	@verbatim
	{
		"dwValue": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetIspImgDefog_Ntf,

	/**
	@brief ��ȡIsp����ȥ�����Ӧ
	MainBuf(#u32, dwValue )

	@verbatim
	{
		"dwValue": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetIspImgDefog_Rsp,

	/**
	@brief ����Isp���ֿ�̬����֪ͨ
	MainBuf(#BOOL32, bOn )

	@verbatim
	{
		"bOn": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetIspImgDigDynSwitch_Ntf,

	/**
	@brief ��ȡIsp���ֿ�̬������Ӧ
	MainBuf(#BOOL32, bOn )

	@verbatim
	{
		"bOn": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetIspImgDigDynSwitch_Rsp,

	/**
	@brief ����Isp���ֿ�̬�ȼ�֪ͨ
	MainBuf(#u32, dwValue )

	@verbatim
	{
		"dwValue": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetIspImgDigDynLevel_Ntf,

	/**
	@brief ��ȡIsp���ֿ�̬�ȼ���Ӧ
	MainBuf(#u32, dwValue )

	@verbatim
	{
		"dwValue": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetIspImgDigDynLevel_Rsp,
	
	/**
	@brief ����Isp���ⲹ������֪ͨ
	MainBuf(#BOOL32, bOn )

	@verbatim
	{
		"bOn": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetIspImgBackLightSwitch_Ntf,

	/**
	@brief ��ȡIsp���ⲹ��������Ӧ
	MainBuf(#BOOL32, bOn )

	@verbatim
	{
		"bOn": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetIspImgBackLightSwitch_Rsp,
	
	/**
	@brief ����Isp���ⲹ���ȼ�֪ͨ
	MainBuf(#u32, dwValue )

	@verbatim
	{
		"dwValue": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetIspImgBackLightLevel_Ntf,

	/**
	@brief ��ȡIsp���ⲹ���ȼ���Ӧ
	MainBuf(#u32, dwValue )

	@verbatim
	{
		"dwValue": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetIspImgBackLightLevel_Rsp,

	/**
	@brief ��osd��ʾ�Ļظ�
	MainBuf(#BOOL32, bSuccess )

	@verbatim
	{
		"bSuccess": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetOsdOpen_Ntf,

	/**
	@brief �ر�osd��ʾ�Ļظ�
	MainBuf(#BOOL32, bSuccess )

	@verbatim
	{
		"bSuccess": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetOsdClose_Ntf,

	/**
	@brief ���������ͼ��ģʽ��֪ͨ
	MainBuf(#TMtCameraImgInfo_Api, tInfo )

	@verbatim
	{
		"emImgMode": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetCameraImgMode_Ntf,

	/**
	@brief ���������ͼ��ģʽ����Ӧ
	MainBuf(#TMtCameraImgInfo_Api, tInfo )

	@verbatim
	{
		"emImgMode": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetCameraImgMode_Rsp,

	/**
	@brief ����������������ȿ��ص�֪ͨ
	MainBuf(#BOOL32, bOn )

	@verbatim
	{
		"bOn": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetCameraPersonFirst_Ntf,

	/**
	@brief ����������������ȿ��ص���Ӧ
	MainBuf(#BOOL32, bOn )

	@verbatim
	{
		"bOn": 0
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetCameraPersonFirst_Rsp,

	/**
	@brief �������������ģʽ��֪ͨ
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
	@brief �������������ģʽ��֪ͨ
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
	@brief ����ͷ���������ƻ�ȡ��Ӧ
	MainBuf(#EmMtVideoPort_Api, emVidPort )
	SubBuf(#s8, achPackName);
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetCameraUpgradePack_Rsp,

	/**
	@brief ���ظ����������õĻظ�
	MainBuf(#BOOL32, bOpen )
	SubBuf(#u32, dwRet );
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetLocalAssAudExp_Ntf,

	/**
	@brief ���ظ���������ȡ�������Ӧ
	MainBuf(#BOOL32, bOpen )
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetLocalAssAudExp_Rsp,

	/**
	@brief   ��ȡ��Ƶ Զ���Ի�״̬��Ӧ
  
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
	@brief ���������Ϣ�ļ��ظ�
	MainBuf(#u32, dwRet )
	SubBuf(#s8, achFilePach)
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_ExportDiagInfoFile_Ntf,

	/**
	@brief ���������Ϣ�ļ�����֪ͨ
	MainBuf(#u32, dwPercent )
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_ExportDiagInfoProgress_Ntf,

	/**
	@brief Ͷ��״̬֪ͨ
	MainBuf(#TMtQkState_Api, tState )
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_MtQkState_Ntf,

	/**
	@brief ��ǰץ������ʱ����Ӧ
	MainBuf(#u32, dwTime )
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetPacketDurationTime_Rsp,

	/**	
	@brief     ����ͼ�����ȡ��Աȶȡ����Ͷȵ�ISP������֪ͨ
	
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
	@brief   ��ȡ��ѯ��Ƶ���ȡ��Աȶȡ����Ͷȵ�ISP��������Ӧ
	
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
	@brief ����������Ӧ
	MainBuf(#BOOL32, bElectricFan )
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_ElectricFan_Ntf,

	/**
	@brief ��ǰ����ʣ��ʱ����Ӧ
	MainBuf(#u32, dwTime )
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_GetElectricFanTime_Rsp,

	/**
	@brief ���������������֪ͨ
	MainBuf(#u32, dwTime )
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_SetAiCamera_Ntf,

	/**
	@brief ����ͳ�ƽ��
	MainBuf(#TMtPeopleCountingResult_Api )
	@verbatim
	{
		
	}
	@endverbatim
	*/
	Ev_MtApi_Diagnose_PeopleCountingResult_Ntf,
	/**
	@brief ����ǩ����Ϣ
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
