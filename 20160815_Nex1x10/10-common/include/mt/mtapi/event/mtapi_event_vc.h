/*******************************************************************************//**
*@file          mtapi_event_vc.h
*@brief         ʵ��MTAPI MtVideoConfSdk ��UI(�۲���)�¼�֪ͨ�Ķ���
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_EVENT_VC_H_
#define _MTAPI_EVENT_VC_H_
/**@addtogroup event �¼�
*@{
*/

/**@addtogroup vcevent �����¼�
*@{
*/

#include "mtapi_event_def.h"

enum EmMtApiVCEv
{
	EV_UI_BGN(MTAPI_VC)  =	EVSEG_MTAPI_VC_BGN,

/**
  @brief    Э��ջ��ʼ���ɹ����	
  
	MainBuf(#EmConfProtocol_Api, emProtocol)\n
    SubBuf(#EmStackInitFailReason_Api, emReason)
	@verbatim
    {
        "MainParam" : {
            "basetype" : 0
        },
        "AssParam" : {
            "basetype" : 0
        }
    }
  @endverbatim
*/	
	Ev_MtApi_Vc_StackInitRes_Ntf,  


/**
  @brief    ��������(��Ե�)֪ͨ
  
    MainBuf(#EmMtCallDisReason_Api, emDisReason)

  @verbatim
	{
		"basetype":0
	}
  @endverbatim
*/	
	Ev_MtApi_Vc_P2P_Ended_Ntf,  

/**
  @brief    ��������(���)֪ͨ
  
	MainBuf(#EmMtCallDisReason_Api, emDisReason) 

	@verbatim
	{
		"basetype":0
	}
  @endverbatim
*/	
	Ev_MtApi_Vc_MulConf_Ended_Ntf,  

/**
  @brief    ȡ������֪ͨ��˼�ǣ� �����ڽ���֮ǰ���Ҷ��ˣ� ���߶Զ˾ܾ������߳�ʱ�� �����Լ������Ҷ�	
  
	MainBuf(#EmMtCallDisReason_Api, emDisReason)

	@verbatim
	{
		"basetype":0
	}
  @endverbatim
*/	
	Ev_MtApi_Vc_Conf_Canceled_Ntf,  
	 
/**
  @brief    ����������	
  
    MainBuf(#TMtCallLinkSate_Api, ptMtCallLinkSate_Api)

	@verbatim
	{
		"emCallingType":0,
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
		},
		"emSipConnect": 0
	}
  @endverbatim
*/	
	Ev_MtApi_Vc_Conf_Calling_Ntf,  

/**
  @brief    ���е��� 
  
   MainBuf(#TMtCallLinkSate_Api, ptMtCallLinkSate_Api)
	
	@verbatim
	{
		"emCallingType":0,
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
	Ev_MtApi_Vc_Conf_InComing_Ntf,  

/**
  @brief    ��ʼ��Ե���� 
  
    MainBuf(#TMtCallLinkSate_Api, ptMtCallLinkSate_Api)
	
	@verbatim
	{
		"emCallingType":0,
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
	Ev_MtApi_Vc_P2P_Started_Ntf,  

/**
  @brief    ��ʼ������ 	
  
   MainBuf(#TMtCallLinkSate_Api, ptMtCallLinkSate_Api)
	
	@verbatim
	{
		"emCallingType":0,
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
	Ev_MtApi_Vc_MulConf_Started_Ntf,  

	
/**
  @brief    �������״̬����Ҫ�ظ�rsp 	
  
   MainBuf(#TMtCallLinkSate_Api, ptMtCallLinkSate_Api)
	
	@verbatim
	{
		"emCallingType":0,
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
	Ev_MtApi_Vc_CallLinkState_Rsp,

/**
  @brief    ֪ͨ��ǰ��������	
  
	MainBuf(#EmMtConfType_Api, emMtConfType_Api)\n
    SubBuf(#u16, wBitrate) 
  @verbatim
    {
        "MainParam" : {
            "basetype" : 0
        },
        "AssParam" : {
            "basetype" : 0
        }
    }
  @endverbatim
*/	
	Ev_MtApi_Vc_NotifyConfType_Ntf,


/**
  @brief    ����ĺ���֪ͨ	
  

	MainBuf(#TMtMissCallParam_Api, ptMtMissCallParam_Api) 

	@verbatim
	{
		"dwCallRate": 1,
		"tPeerAddr": {
		    "emIpType": 1,
		    "dwIp": 1,
		    "achIpV6": "",
		    "dwPort": 1
		 },
	    "tPeerAlias": {
            "arrAlias": [
                {
                    "emAliasType": 1,
                    "achAlias": ""
                }
            ]
        }
    }
  @endverbatim
*/	
	Ev_MtApi_Vc_CallMissed_Ntf,

/**
  @brief  ��ǰ�����Ƿ����֪ͨ
  
	MainBuf(#BOOL32, bIsEncrypt) 

	@verbatim
	{
		"basetype":true
	}
  @endverbatim
*/	
	Ev_MtApi_Vc_CallEncrypt_Ntf,

	/**
  @brief  ��ǰ�����Ƿ���ܻظ�
  
	MainBuf(#BOOL32, bIsEncrypt) 

	@verbatim
	{
		"basetype":true
	}
  @endverbatim
*/	
	Ev_MtApi_Vc_CallEncrypt_Rsp,

/**
  @brief   ��������״̬��Ӧ
  
	MainBuf(#TMtAssVidStatusList_Api, ptMtAssVidStatusList) 

	@verbatim
	{
		"arrTAssVidStatus": [
			{
				"emChanState": 0,
				"emVidLab": 0,
				"bActive": true
			}
		]
	}
  @endverbatim
*/
	Ev_MtApi_Vc_AssSndSream_Status_Rsp,


/**
  @brief    ��������״̬֪ͨ
  
	MainBuf(#TMtAssVidStatusList_Api, ptMtAssVidStatusList_Api) 

	@verbatim
	{
		"arrTAssVidStatus": [
			{
				"emChanState": 0,
				"emVidLab": 0,
				"bActive": true
			}
		]
	}
  @endverbatim
*/
	Ev_MtApi_Vc_AssSndSream_Status_Ntf,

/**
  @brief    ��������״̬��Ӧ
  
	MainBuf(#TMtAssVidStatusList_Api, ptMtAssVidStatusList) 

	@verbatim
	{
		"arrTAssVidStatus": [
			{
				"emChanState": 0,
				"emVidLab": 0,
				"bActive": true
			}
		]
	}
  @endverbatim
*/
	Ev_MtApi_Vc_AssRcvSream_Status_Rsp,

/**
  @brief    ��������״̬֪ͨ	
  
	MainBuf(#TMtAssVidStatusList_Api, ptMtAssVidStatusList_Api) 

	@verbatim
	{
		"arrTAssVidStatus": [
			{
				"emChanState": 0,
				"emVidLab": 0,
				"bActive": true
			}
		]
	}
  @endverbatim
*/
	Ev_MtApi_Vc_AssRcvSream_Status_Ntf,


	//��ȡ�����б�. ��������emConfList_Not_Finished_Api����ʾ����û���ս����������������ʾ�����ս���
	//���ݱ�����sdk�У� ��Ҫ�ٵ�����KdvMt_ConfGetCurConfList
/**
  @brief   ��ȡ�û������б�֪ͨ
  
    MainBuf(#EmConfListType_Api, emType)\n
    SubBuf(#EmConfListRspErr_Api, emRspErr)

	@verbatim
	{
        "MainParam" : {
            "basetype" : 0
        },
        "AssParam" : {
            "basetype" : 0
        }
    }
  @endverbatim
*/
	Ev_MtApi_Vc_ConfList_Rsp,

/**
  @brief   Ԥ���������֪ͨ	
  
   MainBuf(#EmMtJoinCreateConfRsp_Api, emRet)

	@verbatim
	{
		"basetype":0
	}
  @endverbatim
*/
	Ev_MtApi_Vc_PreJoinConfResult_Ntf,

/**
  @brief  Ԥ����������֪ͨ
  
   MainBuf(#EmMtJoinCreateConfRsp_Api, emRet) 

	@verbatim
	{
		"basetype":0
	}
  @endverbatim
*/
	Ev_MtApi_Vc_PreCreateConfResult_Ntf,


/**
  @brief    ���������ϸ��Ϣ��Ӧ
  
   MainBuf(#EmMtConfDetailErr_Api, emRes)\n
   SubBuf(#TMtConfDetailInfo_Api*, ptMtConfDetailInfo_Api) 

	@verbatim
	{
		"MainParam" : {
			"basetype":0
		},
		"AssParam" : {
			"tConfBaseInfo": {
				"achConfName": "str",
				"achConfE164": "str",
				"achDomainGuid": "str",
				"achDomainName": "str",
				"achDomainMoId": "str"
			},
			"dwConfStyle": 0,
			"achShortNo": "str",
			"dwEncryptMode": 0,
			"dwBitrate": 0,
			"emConfResultion": 0,
			"emVidResolution": 0,
			"dwOpenMode": 0,
			"bIsDiscussConf": true,
			"tStartTime": {
				"wYear": 0,
				"byMonth": 0,
				"byDay": 0,
				"byHour": 0,
				"byMinute": 0,
				"bySecond": 0,
				"wMicroSecond": 0
			},
			"dwDuration": 0,
			"achMasterMtAlias": "str",
			"emAssStreamMode": 0,
			"bIsSatdcastMode": true,
			"bIsPublicConf": true,
	        "bConfNoDisturb": true,
	        "bNeedPwd"      : true
		}
	}
  @endverbatim
*/
	Ev_MtApi_Vc_GetConfDetailInfo_Ntf,
	
/**
  @brief  ��ȡ���õ��ܵĻ���������֪ͨ	
  
	MainBuf(#u32, dwTotalRoomNum)\n
    SubBuf(#u32, dwUsedRoomNum)

	@verbatim
	{
		"MainParam" : {
			"basetype": 0,
		},
		"AssParam" : {
			"basetype": 0,
		}
	}
  @endverbatim
*/
	Ev_MtApi_Vc_RoomNum_Ntf,
	
/**
  @brief    ����ģ�������֪ͨ	
  
	MainBuf(#u32, dwErrCode) 

	@verbatim
	{
		"basetype": 0,
	}
  @endverbatim
*/
	Ev_MtApi_Vc_ErrorCode_Ntf,
	
/**
  @brief  �ն˱��֪ͨ   ��׼
  
   MainBuf(#TMtId_Api, ptMtId_Api) 

	@verbatim
	{
		"dwMcuId": 0,
		"dwTerId": 0
	}
  @endverbatim
*/
	Ev_MtApi_Vc_TerLabel_Ntf,

/**
  @brief  �ն˱��֪ͨ   ��׼
  
   MainBuf(#TMtId_Api, ptMtId_Api) 

	@verbatim
	{
		"dwMcuId": 0,
		"dwTerId": 0
	}
  @endverbatim
*/
	Ev_MtApi_Vc_TerLabel_Rsp,

/**
  @brief    ��ǰ�������������ն�֪ͨ ��� KMTAPI_MAX_CONF_MT_MEMBER_NUM, sip�����з���ͨ������  ��׼
  
	MainBuf(#TMTEntityInfo_Api[], ptMtEntityInfo_Api) \n
    SubBuf(#u32, dwCount)//�����С

	@verbatim
	{
		"atMtEntitiy": [
			{
				"tMtAddr": {
					"emIpType": 0,
					"dwIp": 0,
					"achIpV6": "str",
					"dwPort": 0
				},
				"emModel": 0,
				"tMtAlias": {
					"arrAlias": [
						{
							"emAliasType": 0,
							"achAlias": "str"
						}
					]
				},
				"emMtType": 0,
				"bAudOnly": true,
				"dwMcuId": 0,
				"dwTerId": 0,
				"atLoc":[
					{
					   "emDirect" : 1,
					   "emMediatype"��1,
					   "emStream_id": 1,
					   "achStream_Alias": ""
					}
		        ]
			}
		]
	}
  @endverbatim
*/
	Ev_MtApi_Vc_OnLineTerList_Ntf,

/**
  @brief    �ն˼���֪ͨ
  
   MainBuf(#TMTEntityInfo_Api, ptMTEntityInfo_Api) 

	@verbatim
	{
				"tMtAddr": {
					"emIpType": 0,
					"dwIp": 0,
					"achIpV6": "str",
					"dwPort": 0
				},
				"emModel": 0,
				"tMtAlias": {
					"arrAlias": [
						{
							"emAliasType": 0,
							"achAlias": "str"
						}
					]
				},
				"emMtType": 0,
				"bAudOnly": true,
				"dwMcuId": 0,
				"dwTerId": 0,
				"atLoc":[
					{
					   "emDirect" : 1,
					   "emMediatype": 1,
					   "emStream_id": 1,
					   "achStream_Alias": ""
					}
			     ]
	}
  @endverbatim
*/
	Ev_MtApi_Vc_TerJoin_Ntf,

/**
  @brief    �ն��˳�֪ͨ	  ��׼
  
   MainBuf(#TMtId_Api, ptMtId_Api) 

	@verbatim
	{
		"dwMcuId": 0,
		"dwTerId": 0
	}
  @endverbatim
*/
	Ev_MtApi_Vc_TerLeft_Ntf,


/**
  @brief  ��ǰ�������������ն�֪ͨ  ��׼
  
	MainBuf(#TMTEntityInfo_Api[], atMtEntityInfo_Api)\n
    SubBuf(#u32, dwCount)//�����С

	@verbatim
	{
		"atMtEntitiy": [
			{
				"tMtAddr": {
					"emIpType": 0,
					"dwIp": 0,
					"achIpV6": "str",
					"dwPort": 0
				},
				"emModel": 0,
				"tMtAlias": {
					"arrAlias": [
						{
							"emAliasType": 0,
							"achAlias": "str"
						}
					]
				},
				"emMtType": 0,
				"bAudOnly": true,
				"dwMcuId": 0,
				"dwTerId": 0,
	            "tList" : {
				      "atLoc" : [
					        {
					           "emDirect" : 1,
					           "emMediatype"��1,
					           "emStream_id": 1,
					           "emStream_Alias": ""
					        }
					  ]
	             }
			}
		]
	}
  @endverbatim
*/
	Ev_MtApi_Vc_OnLineTerList_Rsp,

	//���ù�
	Ev_MtApi_Vc_OffLineTerList_Ntf,   //�ݲ�����

	//���ù�
	Ev_MtApi_Vc_OffLineTerList_Rsp,   //�ݲ�����

/**
  @brief    ������Ϣ   �Ǳ�
  
	MainBuf(#TMtConfInfo_Api, tMtConfInfo_Api) 

	@verbatim
	{
		"tStartTime": {
			"wYear": 0,
			"byMonth": 0,
			"byDay": 0,
			"byHour": 0,
			"byMinute": 0,
			"bySecond": 0,
			"wMicroSecond": 0
		},
		"wDuration": 0,
		"wBitRate": 0,
		"wSecBitRate": 0,
		"emPriVideoResolution": 0,
		"emAssVideoResolution": 0,
		"dwTalkHoldTime": 0,
		"achConfPwd": "",
		"achConfName": "",
		"achConfE164": "",
		"tChairman": {
			"dwMcuId": 0,
			"dwTerId": 0
		},
		"tSpeaker": {
			"dwMcuId": 0,
			"dwTerId": 0
		},
		"tVmpParam": {
            "emVmpMode": 1,
            "bIsBroadcast": true,
            "bAddMmbAlias": true,
            "emStyle": 1,
            "atVmpItem": [
                 {
                     "tMtid": {
                        "dwMcuId": 192,
                        "dwTerId": 12
                     },
                    "emStream_id": 1,
                    "emMmbType": 1,
					"dwVmpItem_Idx":1
                }
            ]
         },
		"tMixParam": {
			"emDiscussMode": 0,
			"arrTMtMember": [
				{
					"dwMcuId": 0,
					"dwTerId": 0
				}
			]
		},
		"bIsSatdcastMode": true,
		"emOpenMode": 0,
		"bOccupy_Vpu": true,
		"emDual_mode": 0,
		"bAllInitDumb": true,
		"bConfNoDisTurb": true,
        "bPortMode" : true,
		"bForceBroadcast" :true
	}

  @endverbatim
*/
	Ev_MtApi_Vc_ConfInfo_Ntf,
	
/**
  @brief    ��������Ϣ֪ͨ   �Ǳ�
  
	MainBuf(#TMtId_Api, tMtId_Api) 

	@verbatim
	{
		"tSpeaker": {
			"dwMcuId": 0,
			"dwTerId": 0
		},
		"tChairman": {
			"dwMcuId": 0,
			"dwTerId": 0
		},
		"emDiscuss_mode": 0,
		"emVmp_mode": 0
	}
  @endverbatim
*/
	Ev_MtApi_Vc_SimpleConfInfo_Ntf,

/**
  @brief    ������Ϣ�ظ�  �Ǳ�
  
	MainBuf(#TMtConfInfo_Api, tMtConfInfo_Api) 
  @verbatim
    {
        "tStartTime": {
        "wYear": 0,
        "byMonth": 0,
        "byDay": 0,
        "byHour": 0,
        "byMinute": 0,
        "bySecond": 0,
        "wMicroSecond": 0
        },
        "wDuration": 0,
        "wBitRate": 0,
        "wSecBitRate": 0,
        "emPriVideoResolution": 0,
        "emAssVideoResolution": 0,
        "dwTalkHoldTime": 0,
        "achConfPwd": "",
        "achConfName": "",
        "achConfE164": "",
        "tChairman": {
            "dwMcuId": 0,
            "dwTerId": 0
        },
        "tSpeaker": {
            "dwMcuId": 0,
            "dwTerId": 0
        },
        "tVmpParam": {
            "emVmpMode": 1,
            "bIsBroadcast": true,
            "bAddMmbAlias": true,
            "emStyle": 1,
            "atVmpItem": [
                {
                    "tMtid": {
                        "dwMcuId": 192,
                        "dwTerId": 12
                    },
                    "emStream_id": 1,
                    "emMmbType": 1,
					"dwVmpItem_Idx", 1
                }
            ]
        },
        "tMixParam": {
            "emDiscussMode": 0,
            "arrTMtMember": [
                {
                    "dwMcuId": 0,
                    "dwTerId": 0
                }
            ]
        },
        "bIsSatdcastMode": true,
        "emOpenMode": 0,
        "bOccupy_Vpu": true,
        "emDual_mode": 0,
        "bAllInitDumb": true,
        "bConfNoDisTurb": true,
        "bPortMode" : true,
		"bForceBroadcast" :true
    }
  @endverbatim
*/
	Ev_MtApi_Vc_ConfInfo_Rsp,

/**
  @brief   ����ʣ��ʱ��֪ͨ   �Ǳ�
  
	MainBuf(#u32, dwConfRemainTime) 
	
  @verbatim
	{
			"basetype": 0,
		}
  @endverbatim
*/
	Ev_MtApi_Vc_ConfWillEnd_Ntf,

/**
  @brief    mc�����ն���������  ��׼
  @verbatim
  @endverbatim
*/
	Ev_MtApi_Vc_McReqTerPwd_Ntf,


/**
  @brief    ǿ�ƹҶ��ն�ʧ��  ��׼
  @verbatim
  @endverbatim
*/
	Ev_MtApi_Vc_DropTerReject_Ntf,

/**
  @brief    ��ϯ�����ն�ʧ��     �Ǳ�
  
  MainBuf(#TMtAddr_Api, tMtAddr_Api)\n
  SubBuf(#EmMtCallDisReason_Api, emMtCallDisReason_Api)
  @verbatim
  {
	  "MainParam": {
	      "emAddrType": 1,
	      "tIP" : {
	        "emIpType": 1,
	        "dwIp": 12345,
	        "achIpV6": "sdffsdf",
	        "dwPort": 60000
	      },
	      "achAlias": ""
	  },
	  "AssParam" : {
	      "basetype" : 0
	  }
  }
  @endverbatim
*/
	Ev_MtApi_Vc_ChairInviteMtFailed_Ntf,

/**
  @brief    ���鷢��ʧ��    �Ǳ�

  MainBuf(#EmMtConfFailureReason_Api, emReason)
  @verbatim
  {
		"basetype": 0,
  }
  @endverbatim
*/
	Ev_MtApi_Vc_ConfFailed_Ntf,

/**
  @brief    �����ӳ�֪ͨ, ��λΪ����   �Ǳ�

  MainBuf(#u16, dwDelay_time)

  @verbatim
	{
		"basetype": 0
	}
  @endverbatim
*/
	Ev_MtApi_Vc_ConfDelay_Ntf,

/**
  @brief    ����ʣ��ʱ��֪ͨ	
  
  MainBuf(#u16, dwRest_time)
  @verbatim
  {
      "basetype" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_RestTime_Ntf,

/**
  @brief    �ӳ�����ʱ����

	MainBuf(#BOOL32, bResult)
  @verbatim
    {
		"basetype": true
	}
  @endverbatim
*/
	Ev_MtApi_Vc_ProlongResult_Ntf,

/**
  @brief    �޸Ļ������ƣ� �������룬 ����˫����ʽ���������ʱ�䣬�ظ�������һ��    �Ǳ�
  
  MainBuf(#EmMtModifyConfInfoType_Api, emType)\n
  SubBuf(#BOOL32, bResult)//�޸��Ƿ�ɹ����
  @verbatim
  {
       "MainParam" : {
           "basetype" : 0
       },
       "AssParam" : {
           "basetype" : true
       }
  }
  @endverbatim
*/
	Ev_MtApi_Vc_ModifyConfResult_Ntf,


/**
  @brief    ��ϯ�յ�����������	��׼
  
	MainBuf(#TMtId_Api, ptMtId_Api)

	@verbatim
	{
		"dwMcuId": 0,
		"dwTerId": 0
	}
  @endverbatim
*/
	Ev_MtApi_Vc_ApplySpeak_Ntf,

/**
  @brief    ������λ��֪ͨ   �Ǳ�
  
	MainBuf(#TMtId_Api, tMtId_Api)

	@verbatim
	{
		"dwMcuId": 0,
		"dwTerId": 0
	}
  @endverbatim
*/
	Ev_MtApi_Vc_SpeakerPos_Ntf,

/**
  @brief    ���㲥֪ͨ  ��׼
  @verbatim
  @endverbatim
*/
	Ev_MtApi_Vc_SeenByAll_Ntf,

	/**
  @brief    ���뷢���˳�ʱ
  @verbatim
  @endverbatim
*/
	Ev_MtApi_Vc_ApplySpeakTimerOut_Ntf,
	
	/**
  @brief    ������ϯ��ʱ
  @verbatim
  @endverbatim
*/
	Ev_MtApi_Vc_ApplyChairTimerOut_Ntf,
	
		/**
  @brief    ����廰��ʱ
  @verbatim
  @endverbatim
*/
	Ev_MtApi_Vc_ApplyChiemeInTimerOut_Ntf,
	
/**
  @brief    ȡ��������ָʾ
  @verbatim
  @endverbatim
*/
	Ev_MtApi_Vc_CancelSeenByAll_Ntf,


/**
  @brief    ��ϯָ�������˽��֪ͨ  ��׼
  
  MainBuf(#BOOL32, bResult)//�Ƿ�ɹ����
  @verbatim
  {
	  "basetype": true
  }
  @endverbatim
*/
	Ev_MtApi_Vc_BroadcastResult_Ntf,


/**
  @brief    ��ǰ������ƵԴ֪ͨ  ��׼
  
   MainBuf(#TMTChanVidSrcList_Api, tChanVidSrcList_Api)

	@verbatim
	{
		"atList": [
			{
				"emChanIdx": 0,
				"tMtid": {
					"dwMcuId": 0,
					"dwTerId": 2
				}
			}
		 ]
	 }
  @endverbatim
*/
	Ev_MtApi_Vc_YouAreSeeing_Ntf,

/**
  @brief    ��ǰ������ƵԴ֪ͨ   ��׼
  
   MainBuf(#TMTChanVidSrcList_Api, tChanVidSrcList_Api)
   @verbatim
   {
       "atList": [
           {
                "emChanIdx": 0,
                "tMtid": {
                    "dwMcuId": 0,
                    "dwTerId": 2
                }
           }
       ]
   }
  @endverbatim
*/
	Ev_MtApi_Vc_YouAreSeeing_Rsp,


/**
  @brief   ��ϯ�յ������ն�������ϯ	  �Ǳ�
   MainBuf(#TMtId_Api, tMtId_Api)

  @verbatim
	{
		"dwMcuId": 0,
		"dwTerId": 0
	}
  @endverbatim
*/
	Ev_MtApi_Vc_ApplyChair_Ntf,


/**
  @brief    ��ϯλ��֪ͨ	 ��׼
  
   MainBuf(#TMtId_Api, tMtId_Api)

  @verbatim
	{
		"dwMcuId": 0,
		"dwTerId": 0
	}
  @endverbatim
*/
	Ev_MtApi_Vc_ChairPos_Ntf,

/**
  @brief    ������ϯ�Ƿ�ɹ� �� ��������ϯ����  ��׼
  
   MainBuf(#BOOL32, bGet)//�Ƿ�����ϯ����
  @verbatim
  {
	  "basetype" : true
  }
  @endverbatim
*/
	Ev_MtApi_Vc_ChairTokenGet_Ntf,

/**
  @brief   ѡ�����

   MainBuf(#BOOL32, bResult) //ѡ���ɹ���� ��׼ \n
   SubBuf(#TMtId, tMtId)
   @verbatim
   {
	    "MainParam" : {
			"basetype": true
		},
	   "AssParam" : {
		    "dwMcuId": 0,
		    "dwTerId": 0
	   }
    }
  @endverbatim
*/
	Ev_MtApi_Vc_SendThisTerResult_Ntf,

/**
  @brief    ���ն˱������ն�ѡ��֪ͨ   ��׼
  
	@verbatim

  @endverbatim
*/
	Ev_MtApi_Vc_SeenByOther_Ntf,

/**
  @brief    ���ն˱������ն�ȡ��ѡ��	 ��׼
  
  @endverbatim
*/
	Ev_MtApi_Vc_CancelSeenByOther_Ntf,


/**
  @brief    �����ն�����ϯ����廰   �Ǳ�
  
  MainBuf(#TMtId_Api, tMtId_Api)

  @verbatim
	{
		"dwMcuId": 0,
		"dwTerId": 0
	}
  @endverbatim
*/
	Ev_MtApi_Vc_ApplyChimeIn_Ntf,

/**
  @brief    ��ǰ�ն˲廰״̬֪ͨ	  �Ǳ�
  
   MainBuf(#BOOL32, bInChime)//�Ƿ����ڲ廰
   @verbatim
  {
    "basetype" : true
  }
  @endverbatim
*/
	Ev_MtApi_Vc_ChimeInState_Ntf,

/**
  @brief    ��ǰ�ն˲廰ʧ��  �Ǳ�
  @verbatim
  @endverbatim
*/
	Ev_MtApi_Vc_ChimeInFailed_Ntf,

/**
  @brief    ����ն�״̬֪ͨ	  �Ǳ�
  
   MainBuf(#TMtEntityStatus_Api, tMtEntityStatus_Api)
   @verbatim
  {
		 "dwMcuId": 192,
    "dwTerId": 12,
    "tStatus": {
        "emMtModel": 1,
        "byEncVol": 12,
        "byDecVol": 12,
        "bIsMute": true,
        "bIsQuiet": true,
        "bMatrixStatus": true,
        "emViewedType": 0,
        "tVideoInfoList": {
            "atVideoInfo": [
                {
                    "emChanIdx": 0,
                    "dwVideoSrc": 0,
                    "bFeccEnable": true,
                    "bHasVideo": true
                }
            ]
        }
    }
  }
  @endverbatim
*/
	Ev_MtApi_Vc_GetTerStatus_Ntf,

/**
  @brief   ��õ�ǰ�����ն�״̬ ��� KMTAPI_MAX_CONF_MT_MEMBER_NUM

   MainBuf(#TMtEntityStatus_Api[], atMtEntityStatus_Api) \n
   SubBuf(#u32, dwCount)  //atMtEntityStatus_Api �����С

   @verbatim
	{
		"atMtEntityStatus": [
			{
			     "dwMcuId": 192,
    "dwTerId": 12,
    "tStatus": {
        "emMtModel": 1,
        "byEncVol": 12,
        "byDecVol": 12,
        "bIsMute": true,
        "bIsQuiet": true,
        "bMatrixStatus": true,
        "emViewedType": 0,
        "tVideoInfoList": {
            "atVideoInfo": [
                {
                    "emChanIdx": 0,
                    "dwVideoSrc": 0,
                    "bFeccEnable": true,
                    "bHasVideo": true
                }
            ]
        }
    }
			}
		]
	}
  @endverbatim
*/
	Ev_MtApi_Vc_GetTerStatusList_Rsp,

/**
  @brief    ��ѯ״̬�ϱ�	
  
   MainBuf(# TMtPollInfo_Api, ptMtPollInfo_Api)
   @verbatim
   {
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
  @endverbatim
*/
	Ev_MtApi_Vc_PollState_Ntf,

/**
  @brief    ��ѯ״̬�ϱ�	
  
   MainBuf(# TMtPollInfo_Api, tMtPollInfo_Api)
   @verbatim
   {
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
  @endverbatim
*/
	Ev_MtApi_Vc_PollState_Rsp,

	/**
  @brief    ��ǰ������ѯ���ն�֪ͨ	
  
   MainBuf(# TMtId_Api, tMtid)
   @verbatim
   {
		 "dwMcuId": 192,
		 "dwTerId": 12
   }
  @endverbatim
*/
	Ev_MtApi_Vc_PollingMt_Ntf,


/**
  @brief    ��һ·��Ƶ���ͽ���ͨ���ر�	
  @verbatim
  @endverbatim
*/

	Ev_MtApi_Vc_PrimoVideoOff_Ntf,

	//Ev_Conf_RollCallResult_Ntf   ��ʱ����
	Ev_MtApi_Vc_RollCallResult_Ntf,


	////////////////////////////////����ϳɣ� �������
/**
  @brief  ��ʼvac���     �Ǳ�
  
  MainBuf(#BOOL32, bResult) \n
  SubBuf(#BOOL32, bVac)//�Ƿ���������
  @verbatim
  {
       "MainParam" : {
           "basetype" : true
       },
       "AssParam" : {
           "basetype" : true
       }
  }   
  @endverbatim
*/
	Ev_MtApi_Vc_StartVACResult_Ntf,

/**
  @brief   ֹͣvac���   �Ǳ�
  
  MainBuf(#BOOL32, bResult)\n
  SubBuf(#BOOL32, bVac)//�Ƿ���������
  @verbatim
  {
       "MainParam" : {
            "basetype" : true
        },
       "AssParam" : {
            "basetype" : true
        }
  } 
  @endverbatim
*/
	Ev_MtApi_Vc_StopVACResult_Ntf,

/**
  @brief   ��ʼ����ģʽ���  �Ǳ�
 
  MainBuf(#BOOL32, bResult) \n
  SubBuf(#BOOL32, bDiscussMode)
  @verbatim
  {
        "MainParam" : {
            "basetype" : true
        },
        "AssParam" : {
            "basetype" : true
        }
  }
  @endverbatim
*/
	Ev_MtApi_Vc_StartDiscussResult_Ntf,

/**
  @brief    ֹͣ����ģʽ���	 �Ǳ�

  MainBuf(#BOOL32, bResult) \n
  SubBuf(#BOOL32, bDiscussMode)
  @verbatim
  {
        "MainParam" : {
            "basetype" : true
        },
        "AssParam" : {
            "basetype" : true
        }
  }
  @endverbatim
*/
	Ev_MtApi_Vc_StopDiscussResult_Ntf,

/**
  @brief    ��ʼ���ƻ������	  �Ǳ�
  
  MainBuf(#BOOL32,bResult) \n
  SubBuf(#BOOL32, bCustomMix)
  @verbatim
  {
        "MainParam" : {
            "basetype" : true
        },
        "AssParam" : {
            "basetype" : true
        }
  }
  @endverbatim
*/
	Ev_MtApi_Vc_StartCustomMixResult_Ntf,

/**
  @brief    ֹͣ���ƻ������	 �Ǳ�
  
  MainBuf(#BOOL32,bResult) \n 
  SubBuf(#BOOL32, bCustomMix)
  @verbatim
  {
        "MainParam" : {
            "basetype" : true
        },
        "AssParam" : {
            "basetype" : true
        }
  }
  @endverbatim
*/
	Ev_MtApi_Vc_StopCustomMixResult_Ntf,


	/* 
	   CustomVMP     ��ʾ��������ϳ�
	   ConfVMP:      ��ʾ���黭��ϳ�
	*/

/**
  @brief    ��ʼ���黭��ϳɽ��	 �Ǳ�

  MainBuf(#BOOL32, bResult)
  @verbatim
  {
       "basetype":true
  }
  @endverbatim
*/
	Ev_MtApi_Vc_StartConfVMPResult_Ntf,

/**
  @brief    ֹͣ���黭��ϳɽ��   �Ǳ�
  
  MainBuf(#BOOL32, bResult)
  @verbatim
  {
       "basetype":true
  }
  @endverbatim
*/

	Ev_MtApi_Vc_StopConfVMPResult_Ntf,

/**
  @brief    ���û��黭��ϳɽ��	  �Ǳ�
  
  MainBuf(#BOOL32, bResult)
  @verbatim
  {
       "basetype":true
  }
  @endverbatim
*/
	Ev_MtApi_Vc_SetConfVMPResult_Ntf,

/**
  @brief    ��ʼ��������ϳɽ��    �Ǳ�
  
  MainBuf(#BOOL32, bResult)
  @verbatim
  {
       "basetype":true
  }
  @endverbatim
*/
	Ev_MtApi_Vc_StartCustomVMPResult_Ntf,

/**
  @brief    ֹͣ��������ϳɽ��	  �Ǳ�
  
  MainBuf(#BOOL32, bResult)
  @verbatim
  {
       "basetype":true
  }
  @endverbatim
*/
	Ev_MtApi_Vc_StopCustomVMPResult_Ntf,	

/**
  @brief    ������������ϳɽ��	  �Ǳ�
  
  MainBuf(#BOOL32, bResult)
  @verbatim
  {
       "basetype":true
  }
  @endverbatim
*/
	Ev_MtApi_Vc_SetCustomVMPResult_Ntf,


/**
  @brief    ��ȡ���黭��ϳɽ��    �Ǳ�
  
  MainBuf(#TMtVmpParam_Api, tMtVmpParam_Api)	

  @verbatim
	{
          "emVmpMode": 1,
          "bIsBroadcast": true,
          "bAddMmbAlias": true,
          "emStyle": 1,
          "atVmpItem": [
              {
                 "tMtid": {
                    "dwMcuId": 192,
                    "dwTerId": 12
                 },
                 "emStream_id": 1,
                 "emMmbType": 1,
				 "dwVmpItem_Idx": 1
              }
          ]
    }
  @endverbatim
*/
	Ev_MtApi_Vc_GetConfVMPResult_Ntf,

	/**
  @brief    ��ȡ��������ϳɽ��   �Ǳ�
  
  MainBuf(#TMtCustomVmpParam_Api, tMtCustomVmpParam)

  @verbatim
	{
	    "emVmpMode": 1,
	    "emStyle": 1,
	    "atVmpItem": [
             {
                 "tMtid": {
                    "dwMcuId": 192,
                    "dwTerId": 12
                 },
                "emStream_id": 1,
                "emMmbType": 1,
				"dwVmpItem_Idx": 1
             }
         ]
	}
  @endverbatim
*/
	Ev_MtApi_Vc_GetCustomVMPResult_Ntf,

/**
  @brief    ��ȡ��������ϳɽ��    �Ǳ�
  
  MainBuf(#TMtCustomVmpParam_Api, tMtCustomVmpParam)

  @verbatim
	{
	    "emVmpMode": 1,
	    "emStyle": 1,
	    "atVmpItem": [
             {
                 "tMtid": {
                    "dwMcuId": 192,
                    "dwTerId": 12
                 },
                "emStream_id": 1,
                "emMmbType": 1,
				"dwVmpItem_Idx": 1
             }
         ]
	}
  @endverbatim
*/
	Ev_MtApi_Vc_GetCustomVMPResult_Rsp,

/**
  @brief    ѡ����黭��ϳɽ��	  �Ǳ�
  
  MainBuf(#BOOL32, bResult)
  @verbatim
  {
	   "basetype":true
  }
  @endverbatim
*/
	Ev_MtApi_Vc_SelectConfVmpResult_Ntf,

/**
  @brief    ������Ա����֪ͨ    �Ǳ�
  
   MainBuf(#TMtMixParam_Api, tMtMixParam_Api)	

  @verbatim
	{
	    "tMixParam": {
		    "emDiscussMode": 0,
			"arrTMtMember": [
		        {
			        "dwMcuId": 0,
				    "dwTerId": 0
		        }
		    ]
	    }
	}
  @endverbatim
*/
	Ev_MtApi_Vc_MixParam_Ntf,

/**
  @brief    ������Ա�����ظ�	   �Ǳ�
  
  MainBuf(#TMtMixParam_Api, tMtMixParam_Api)

  @verbatim
	{
	    "tMixParam": {
		    "emDiscussMode": 0,
			"arrTMtMember": [
		        {
			        "dwMcuId": 0,
				    "dwTerId": 0
		        }
		     ]
	    }
	}
  @endverbatim
*/
	Ev_MtApi_Vc_MixParam_Rsp,



/**
  @brief    ����Ϣ֪ͨ     �Ǳ�
  
  MainBuf(#TShortMsg_Api, tShortMsg_Api)

  @verbatim
	{
		"emType": 0,
		"tSrcMtId": {
			"dwMcuId": 0,
			"dwTerId": 0
		},
		"byDstNum": 0,
		"arrMtDst": [
			{
				"dwMcuId": 0,
				"dwTerId": 0
			}
		],
		"bySpeed": 0,
		"byRollTimes": 0,
		"achText": ""
	}
  @endverbatim
*/
	Ev_MtApi_Vc_SMS_Ntf,

/**
  @brief    ע��ɹ���ԭ����emRegSuccess_Api	
  
  MainBuf(#EmConfProtocol_Api, emConfProtocol_Api)\n
  SubBuf(#EmRegFailedReason_Api, emRegFailedReason_Api)
  @verbatim
  {
       "MainParam" : {
           "basetype" : 0
       },
       "AssParam" : {
           "basetype" : 0
       }
  }
  @endverbatim
*/
	Ev_MtApi_Vc_RegResult_Ntf,

/**
  @brief    ע��ɹ���ԭ����emRegSuccess_Api	
  
  MainBuf(#EmConfProtocol_Api, emConfProtocol_Api)\n
  SubBuf(#EmRegFailedReason_Api, emRegFailedReason_Api)
  @verbatim
  {
        "MainParam" : {
        "basetype" : 0
        },
         "AssParam" : {
         "basetype" : 0
        }
  }
  @endverbatim
*/
	Ev_MtApi_Vc_RegResult_Rsp,


/**
  @brief    �յ�mcuת�������ļ���װ��������	
  
  MainBuf(#s8*, pchConfName)\n
  SubBuf(#s8*, pchConfE164)
  @verbatim
  {
        "MainParam" : {
            "basetype" : "str"
        },
        "AssParam" : {
            "basetype" : "str"
        }
  }
  @endverbatim
*/
	Ev_MtApi_Vc_JoinDataConf_Ntf,

/**
  @brief    �յ�UI ��ǰ���е�calllid�����ڰװ����	
  
  MainBuf(#s8*, pchCallId)
  @verbatim
  {
      "basetype" : "str"
  }
  @endverbatim
*/
	Ev_MtApi_Vc_Callid_Ntf,

/**
  @brief    mcu �ظ���ϯ�� �Ƿ�ͬ������vip�б�    //add from here  �Ǳ�
  
  MainBuf(#BOOL32, bResult)
  @verbatim
  {
      "basetype":true
  }
  @endverbatim
*/
	Ev_MtApi_Vc_SetVipListResult_Ntf,

/**
  @brief    mcu ֪ͨ�նˣ� ��ǰvip�б�	�Ǳ�

  MainBuf(#TMtIdList_Api, tTMtIdList_Api) 
  @verbatim
  {
      "MainParam" : {
            "tMtId_Api" : [
                {
                    "dwMcuId" : 1,
                    "dwTerId" : 1
                }
            ]
      }
  }
  @endverbatim
*/
	Ev_MtApi_Vc_VipList_Ntf,

/**
  @brief    �ظ���ǰvip�б�	 �Ǳ�
  
  MainBuf(#TMtIdList_Api, tTMtIdList_Api)  
  @verbatim
  {
      "MainParam" : {
          "tMtId_Api" : [
              {
                  "dwMcuId" : 1,
                  "dwTerId" : 1
              }
          ]
      }
  }
  @endverbatim
*/
	Ev_MtApi_Vc_VipList_Rsp,

/**
  @brief    ˫�����ͷ�֪ͨ 	

  MainBuf(#TMtId_Api, tMtId_Api) \n
  SubBuf(#BOOL32, bGrabbed)//�Ƿ�ǰ�ն˱�����
  @verbatim
  {
       "MainParam" : {
           "dwMcuId" : 0,
           "dwTerId" : 0
       },
       "AssParam" : {
            "basetype" : true
       }
  }
  @endverbatim
*/
	Ev_MtApi_Vc_AssStreamSender_Ntf,

	/**
  @brief    ��ȡ��ǰ˫�����ͷ��ظ�

  MainBuf(#TMtId_Api, tMtId_Api)
  @verbatim
  {
	  "dwMcuId" : 0,
	  "dwTerId" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_GetDualStreamSender_Rsp,

/**
  @brief     ��ϯָ���ն˷�˫�� �����ϱ��� ����ͬ��
  
  MainBuf(#TMtId_Api, tMtId_Api) 
  @verbatim
  {
       "dwMcuId" : 0,
       "dwTerId" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_ChairSpecTerSendAss_Ntf,
	Ev_MtApi_Vc_ChairSpecTerSendAssParam_Rsp,


/**
  @brief    ��ȡ������ϵ���б�	
  
  MainBuf(#TMtDetialInfoList_Api, tMtDetialInfoList) \n
  SubBuf(#BOOL32, bFinished)
  @verbatim
  {
       "MainParam" : {
           "atDetialMtInfo" : [
                {
                    "achAlias" : "str",
                    "achE164" : "str"
                }
           ]
       },
       "AssParam" : {
           "basetype" : true
       }
  }
  @endverbatim
*/
	Ev_MtApi_Vc_GetGkMtlist_Ntf,


/**
  @brief    �Զ���ƵԴ��Ϣ	
  

  MainBuf(#TMultiVideoAlias_Api, tMultiAlias)
	
  @verbatim
	{
    "atVideoAlias": [
        {
            "emType": 1,
            "emIdx": 0,
            "tMultiVideoSource": {
                "atVidSource": [
                    {
                        "byVideoPort": 0,
                        "achPortName": ""
                    }
                ]
            }
        }
    ]
   }
  @endverbatim
*/
	Ev_MtApi_Vc_PeerVidSouce_Rsp,

/**
  @brief    �Զ���ƵԴ��Ϣ	
  
  MainBuf(#TMultiVideoAlias_Api, tMultiAlias)
	
  @verbatim
	{
    "atVideoAlias": [
        {
            "emType": 1,
            "emIdx": 0,
            "tMultiVideoSource": {
                "atVidSource": [
                    {
                        "byVideoPort": 0,
                        "achPortName": ""
                    }
                ]
            }
        }
    ]
   }
  @endverbatim
*/
	Ev_MtApi_Vc_PeerVidSouce_Ntf,

	/**
  @brief    ѡ�������ϱ�	
  
  MainBuf(#BOOL32, param) ��ǰ�Ƿ���ѡ�� \n
  SubBuf(#TViewTerParam_Api, param) ��ǰѡ������\n
  @verbatim
  {    "MainParam" : {
         "basetype" : true
       },
       "AssParam" : {
           "tTer" :  {
	    "dwMcuId": 192,
	    "dwTerId": 10
	    },
        "emViewType": 1,
	    "bViewAllChan": true,
	    "emChanIdx": 1
       }
	}
  @endverbatim
*/
	Ev_MtApi_Vc_ViewMtParam_Ntf,

/**
  @brief    ѡ�������ϱ�	
  
  MainBuf(#BOOL32, param)  ��ǰ�Ƿ���ѡ��\n
  SubBuf(#TViewTerParam_Api, param) ��ǰѡ������
  @verbatim
 {
       "MainParam" : {
         "basetype" : true
       },
       "AssParam" : {
           "tTer" :  {
	    "dwMcuId": 192,
	    "dwTerId": 10
	    },
        "emViewType": 1,
	    "bViewAllChan": true,
	    "emChanIdx": 1
       }
  }
  @endverbatim
*/
	Ev_MtApi_Vc_ViewMtParam_Rsp,


	//////////////////////////////////////////////////////////////////������vod �� codec
	

/**
  @brief   ��¼Vodƽ̨��Ӧ������
  
  MainBuf(#u32, dwErrorId)

	@verbatim
	{
		"basetype": 12
	}
  @endverbatim
*/
	Ev_MtApi_Vc_VodLogin_Ntf,

/**
  @brief   ��¼Vodƽ̨��Ӧ�˺�Ȩ��
  
  MainBuf(#u32, dwErrorId)

	@verbatim
	{
		"basetype": 12
	}
  @endverbatim
*/
	Ev_MtApi_Vc_VrsRightMask_Ntf,

/**
  @brief   ע��Vodƽ̨��Ӧ
  
  MainBuf(#u32, dwErrorId)

	@verbatim
	{
		"basetype": 12
	}
  @endverbatim
*/
	Ev_MtApi_Vc_VodLogout_Ntf,

/**
  @brief    �����ļ����б��Ӧ
  
  MainBuf(#u32, dwErrorId) \n
  SubBuf(#TVodFoldersInfo_Api, ptInfo)

  @verbatim
	{
		"MainParam": {
			"basetype": 12
		},
		"AssParam": {
			"atFolderInfo": [
			    {
				    "dwFolderId": 0,
				    "achFolderName": "",
				    "dwPrgCount": 0
			    }
			]
		}
	}
  @endverbatim
*/
	Ev_MtApi_Vc_VodGetFolderInfo_Ntf,

	Ev_MtApi_Vc_VodGetFolderInfo_Fin_Ntf, 

/**
  @brief    ����ĳһ�ļ����µĽ�Ŀ�б��Ӧ
  
  MainBuf(#u32, dwErrId) \n
  MainBuf(#TVodPrgsBaseInfo_Api, tBaseInfo)������Ϣ \n
  MainBuf(#TVodGetPrgsReq_Api, tPrgs) 
  
  @verbatim
  {
		"dwErrId": 12,
		"tBaseInfo": {
			"atPrgBase" : [
			{
				"dwCreateTime" : 0,
				"dwIssueTime" : 0,
				"achPrgAlias" : "",
				"dwPrgAllDuration" : 0,
				"dwPrgAllSize" : 0,
				"achPrgDesc" : "",
				"dwPrgId" : 0,
				"dwPrgState" : 0
			}
			]
		},
		"tPrgs" : {
			"dwFolderId": 0,
			"dwPrgsPage": 0,
			"dwPageId": 0
		}
	}
  @endverbatim
*/
	Ev_MtApi_Vc_VodGetPrgsInfo_Ntf,

/**
  @brief    ����ĳһ�ļ����µĽ�Ŀ�б��Ӧ
  
  MainBuf(#u32, dwErrId) ������Ŀ��Ϣ������ \n
  MainBuf(#TVodPrgsDetailInfo_Api, tDetailInfo)������Ϣ \n
  MainBuf(#TVodGetPrgsReq_Api, tPrgs) 
  @verbatim
  {
		"dwErrId": 12,
		"tDetailInfo" : {
			"atPrgDetail" : [
			{
				"dwIp" : 0,
				"dwPrgDuration" : 0,
				"dwPrgIndex" : 0,
				"dwPrgId" : 0,
				"achPrgName" : "",
				"dwPrgSize" : 0,
				"achPrgType" : 0,
				"achPath" : 0,
				"dwPrgsInfoIndex" : 0
			}
			]
		},
		"tPrgs" : {
			"dwFolderId": 0,
			"dwPrgsPage": 0,
			"dwPageId": 0
		}
	}
  @endverbatim
*/
	Ev_MtApi_Vc_VodGetPrgsDetailInfo_Ntf,

	Ev_MtApi_Vc_VodGetPrgsInfo_Fin_Ntf,

/**
  @brief    ����ֱ�����б��Ӧ
  
   MainBuf(#u32, dwErrorId) \n
   SubBuf(#TVodRoomsState_Api, tInfo)

  @verbatim
	{
		"MainParam": {
			"basetype": 12
		},
		"AssParam": {
			"atRoomstate": [
			    {
				    "dwElapse": 0,
				    "achLCastPoint": "",
				    "dwPrgId": 0,
				    "dwRoomId": 0,
				    "achRoomName": "",
				    "dwUsrGrpId": 0,
					"dwLiveTime": 0,
					"achLiveStreamPath": ""
			    }
			]
		}
	}
  @endverbatim
*/
	Ev_MtApi_Vc_VodGetRoomListInfo_Ntf,
	Ev_MtApi_Vc_VodGetRoomListInfo_Fin_Ntf,

/**
  @brief    ����ԤԼֱ�����б��Ӧ �Ͻӿڱ��� �������ʹ���½ӿ�
  
   MainBuf(#u32, dwErrorId) \n
   SubBuf(#TVodRoomsCfg_Api, ptInfo)

	@verbatim
	{
		"MainParam": {
			"basetype": 12
		},
		"AssParam": {
			"atRoomcfg": [
			    {
				    "dwIp": 0,
				    "achPath": "",
				    "achPrgAlias": "",
				    "dwPrgId": 0,
				    "achPrgName": "",
				    "dwResTime": 0,
				    "dwRoomId": 0,
				    "dwUsrGrpId": 0
			    }
			]
		}
	}
  @endverbatim
*/
	Ev_MtApi_Vc_VodGetReserveRoomListInfo_Ntf,
	Ev_MtApi_Vc_VodGetReserveRoomListInfo_Fin_Ntf,

/**
  @brief    �㲥���֪ͨ
  
   MainBuf(#u32, dwErrorId) \n
   SubBuf(#s8*, pchPlayUrl)

  @verbatim
	{
		"MainParam": {
			"basetype": 12
		},
		"AssParam": {
			"basetype": ""
		}
	}
  @endverbatim
*/
	Ev_MtApi_Vc_VODPlay_Ntf,

/**
  @brief    �㲥����״̬֪ͨ
  
  MainBuf(#TVodPlayInfo_Api, tInfo)

  @verbatim
	{
		"achPlayUrl" : "",
		"dwVodId" : 0,
		"arrTStreamInfo":[
		    {
			    "dwStreamId":0,
			    "emStreamType":0,
			    "emBitStreamIdx":0,
			    "dwBandWidth":0,
			    "nSpeedScale":0,
			    "dwStartTime":0,
			    "dwEndTime":0,
			    "dwCurTime":0,
			    "dwMediaType":0,
			    "dwVideoWidth":0,
			    "dwVideoHeight":0,
			    "dwVideoFps":0,
			    "emStatus":0,
			    "bIsLiveBroadcast":true
		    }
		],
		"byCnt" : 0,
		"emStatus" : 0,
		"bIsLiveBroadcast":true
	}
  @endverbatim
*/
	Ev_MtApi_Vc_VODStatus_Ntf,

/**
  @brief    ��ȡ�ѵ㲥�ĵ㲥��Ϣ��Ӧ
  
  MainBuf(#TMultiVodPlayInfo_Api, tInfo)
  @verbatim
  {
		"arrTVodInfo":[
			{
					"achPlayUrl":"",
					"dwVodId":0 ,
					"arrTStreamInfo":	[
					    {
						    "dwStreamId":0,
						    "emStreamType":0,
						    "emBitStreamIdx":0,
						    "dwBandWidth":0,
						    "nSpeedScale":0,
						    "dwStartTime":0,
						    "dwEndTime":0,
						    "dwCurTime":0,
						    "dwMediaType":0,
						    "dwVideoWidth":0,
						    "dwVideoHeight":0,
						    "dwVideoFps":0,
						    "emStatus":0,
						    "bIsLiveBroadcast":true
					    }
				    ],
					"byCnt":0,
					"emStatus":0,
					"bIsLiveBroadcast":true
			 }
		]
  }
  @endverbatim
*/
	Ev_MtApi_Vc_GetRunVODInfo_Rsp,


/**
  @brief    ��ȡ�㲥Դ��Ϣ��Ӧ
  
   MainBuf(#u32, dwVodId) \n
   SubBuf(#TVodPlayInfo_Api, tInfo)

  @verbatim
	{
		"MainParam": {
			"basetype": 12
		},
		"AssParam": {
			"achPlayUrl":"",
			"dwVodId":0 ,
			"arrTStreamInfo":	[
			    {
				    "dwStreamId":0,
				    "emStreamType":0,
				    "emBitStreamIdx":0,
				    "dwBandWidth":0,
				    "nSpeedScale":0,
				    "dwStartTime":0,
				    "dwEndTime":0,
				    "dwCurTime":0,
				    "dwMediaType":0,
				    "dwVideoWidth":0,
				    "dwVideoHeight":0,
				    "dwVideoFps":0,
				    "emStatus":0,
				    "bIsLiveBroadcast":true
			    }
		    ],
			"emStatus":0,
			"bIsLiveBroadcast":true
		}
	}
  @endverbatim
*/
	Ev_MtApi_Vc_GetVODInfo_Rsp,

/**
  @brief    ֹͣ�㲥���֪ͨ
  
   MainBuf(#u32, dwVodId)\n
   SubBuf(#u32, dwErrId)

  @verbatim
	{
		"MainParam": {
			"basetype": 12
		},
		"AssParam": {
			"basetype": 12
		}
	}
  @endverbatim
*/
	Ev_MtApi_Vc_VODOver_Ntf,

/**
  @brief    ��ͣ�㲥���֪ͨ
  
  MainBuf(#u32, dwVodId) \n
  SubBuf(#u32, dwErrId)

  @verbatim
	{
		"MainParam": {
			"basetype": 12
		},
		"AssParam": {
			"basetype": 12
		}
	}
  @endverbatim
*/
	Ev_MtApi_Vc_VODPause_Ntf,

/**
  @brief    �ָ��㲥���֪ͨ
  
  MainBuf(#u32, dwVodId) \n
  SubBuf(#u32, dwErrId)

  @verbatim
	{
		"MainParam": {
			"basetype": 12
		},
		"AssParam": {
			"basetype": 12
		}
	}
  @endverbatim
*/
	Ev_MtApi_Vc_VODResume_Ntf,

/**
  @brief    �ı�㲥���ʽ��֪ͨ
  
  MainBuf(#u32, dwVodId)\n
  SubBuf(#u32, dwErrId)

  @verbatim
	{
		"MainParam": {
			"basetype": 12
		},
		"AssParam": {
			"basetype": 12
		}
	}
  @endverbatim
*/
	Ev_MtApi_Vc_VODChangeSpeed_Ntf,

/**
  @brief    �ı�㲥���Ƚ��֪ͨ
  
  MainBuf(#CSdkMsg, cSdkMsg)\n

  @verbatim
	{
		"dwVodId": 0,
		"dwErrId": 0,
		"dwStartTime": 0,
	}
  @endverbatim
*/
	Ev_MtApi_Vc_VODChangeProcess_Ntf,

/**
  @brief    �㲥Դָ�������Ž��֪ͨ
  
   MainBuf(#u32, dwVodId) \n
   SubBuf(#TMTVodStream_Api , tInfo)

  @verbatim
	{
		"MainParam": {
			"basetype": 12
		},
		"AssParam": {
			"dwVodId":0 ,
			"dwStreamId":0	
		}
	}
  @endverbatim
*/
	Ev_MtApi_Vc_VODStreamPlay_Ntf,


/**
  @brief    �㲥Դָ��������״̬֪ͨ
  
   MainBuf(#u32, dwVodId) \n
   SubBuf(#TStreamInfo_Api , tInfo)

  @verbatim
	{
		"MainParam": {
			"basetype": 12
		},
		"AssParam": {	
				"dwStreamId":0,
				"emStreamType":0,
				"emBitStreamIdx":0,
				"dwBandWidth":0,
				"nSpeedScale":0,
				"dwStartTime":0,
				"dwEndTime":0,
				"dwCurTime":0,
				"dwMediaType":0,
				"dwVideoWidth":0,
				"dwVideoHeight":0,
				"dwVideoFps":0,
				"emStatus":0,
				"bIsLiveBroadcast":true
		}
	}
  @endverbatim
*/
	Ev_MtApi_Vc_VODStreamStatus_Ntf,


/**
  @brief    ��ȡ�㲥��ϢӦ��
  
   MainBuf(#u32, dwErrorId)\n
   SubBuf(#TMTVodStreamInfo_Api, tInfo)

  @verbatim
	{
		"MainParam": {
			"basetype": 12
		},
		"AssParam": {
			"dwVodId":0 ,
			"tStreamInfo":	{
				"dwStreamId":0,
				"emStreamType":0,
				"emBitStreamIdx":0,
				"dwBandWidth":0,
				"nSpeedScale":0,
				"dwStartTime":0,
				"dwEndTime":0,
				"dwCurTime":0,
				"dwMediaType":0,
				"dwVideoWidth":0,
				"dwVideoHeight":0,
				"dwVideoFps":0,
				"emStatus":0,
				"bIsLiveBroadcast":true
	        }
		}
	}
  @endverbatim
*/
	Ev_MtApi_Vc_GetVODStreamInfo_Rsp,

/**
  @brief    ָ����ֹͣ�㲥֪ͨ
  
   MainBuf(#u32, dwErrorId)\n
   SubBuf(#TMTVodStream_Api, tInfo)

  @verbatim
	{
		"MainParam": {
			"basetype": 12
		},
		"AssParam": {
			"dwVodId":0 ,
			"dwStreamId":0
		}
	}
  @endverbatim
*/
	Ev_MtApi_Vc_VODStreamOver_Ntf,
	
	
/**
  @brief    ��������֪ͨ
  
  MainBuf(#TMTStreamParam_Api, tMtStreamParam_Api)

  @verbatim
	{
	    "emCodecType": 2,
	    "emCodecIdx": 2,
	    "byMediaType": 106,
	    "byPlayLoad": 106,
	    "tEncryptKey": {
	        "byLen": 20,
	        "byKey": "adbdfdlf"
	    },
	    "bIsg7221Reverse": true,
	    "emAacChanNum": 1,
	    "emAacSampFreq": 1
	}
  @endverbatim
*/
	Ev_MtApi_Vc_CodecMonitorParam_Ntf,

/**
  @brief    ����֪ͨ
  
   MainBuf(#BOOL32, bIsLostPack)

  @verbatim
	{
	    "basetype":true
	}
  @endverbatim
*/
	Ev_MtApi_Vc_CodecLostPack_Ntf,

/**
  @brief    Ev_MT_CodecVidCapDevList_Ntf (��Win32)	
  
   MainBuf(#TDevInfoList_Api, tDevInfoList_Api)

  @verbatim
	{
	    "arrTDevInfo": [
	        {
	            "achDevName": "",
	            "achDevGuid": ""
  	        }
	    ]
	}
  @endverbatim
*/
	Ev_MtApi_Vc_CodecVidCapDevList_Ntf,


/**
  @brief    ��ȡ��ǰ��Ƶ�ɼ��豸���� (��WIN32)	
  
   MainBuf(#TDevInfo_Api, tDevInfo)

  @verbatim
	{
		"achDevName": "",
		"achDevGuid": ""
	}
  @endverbatim
*/
	Ev_MtApi_Vc_CodecCurVidCapDev_Ntf,

/**     
  @brief   ����״̬֪ͨ
  
   MainBuf(#BOOL32, bMicMute)

  @verbatim
	{
		"basetype": true
	}
  @endverbatim
*/
	Ev_MtApi_Vc_CodecMute_Ntf,

/**     
  @brief   ����״̬֪ͨ
  
   MainBuf(#BOOL32, bQuiet)

  @verbatim
	{
		"basetype": true
	}
  @endverbatim
*/
	Ev_MtApi_Vc_CodecQuiet_Ntf,


/**
  @brief    ��Ƶ�����豸�б�֪ͨ(��win32)
  
   MainBuf(#TDevInfoList_Api, tDevInfoList)

  @verbatim
	{
	    "arrTDevInfo": [
	        {
	            "achDevName": "",
	            "achDevGuid": ""
	        }
	    ]
	}
  @endverbatim
*/
	Ev_MtApi_Vc_CodecWaveInDevList_Ntf,

/**
  @brief    ��Ƶ����豸�б�֪ͨ(��win32)	
  
   MainBuf(#TDevInfoList_Api, tDevInfoList) 

  @verbatim
	{
	    "arrTDevInfo": [
	        {
	            "achDevName": "",
	            "achDevGuid": ""
  	        }
	    ]
    }
  @endverbatim
*/
	Ev_MtApi_Vc_CodecWaveOutDevList_Ntf,

/**
  @brief    ��ȡ��ǰ����Ƶ�����豸֪ͨ(��WIN32)
  
   MainBuf(#TDevInfo_Api, tDevinfo)

  @verbatim
	{
		"achDevName": "",
		"achDevGuid": ""
	}
  @endverbatim
*/
	Ev_MtApi_Vc_CodecCurWaveInDev_Ntf,


/**
  @brief  ��ȡ��ǰ����Ƶ����豸֪ͨ
  
   MainBuf(#TDevInfo_Api, tDevinfo)

  @verbatim
	{
		"achDevName": "",
		"achDevGuid": ""
	}
  @endverbatim
*/
	Ev_MtApi_Vc_CodecCurWaveOutDev_Ntf,

/**
  @brief    ��ȡ��Ƶ���������Ӧ����windowsƽ̨)
  
   MainBuf(#TAudOutVol_Api, tAudOutVol_Api)
   @verbatim
   {
       "wDecId" : 0,
       "byVol" : 0
   }
  @endverbatim
*/
	Ev_MtApi_Vc_CodecGetAudOutVol_Rsp,
	

/**
  @brief   ���������Ӧ		
  
   MainBuf(#u32, dwResult) // ��������״̬ 0���ɹ� 1���������������� 2�����̿ռ䲻�� 3:�ɼ�����ͼ�� 4: �Զ������� 5:�ϴ���ftp������ʧ��\n
   MainBuf(#TSnapshotFileInfo_Api, tFileInfo)

	@verbatim
	{
	   "dwResult": 0,
	   "tSnapshotFileInfo":{
			"achFilePath" : "",
			"achFileName" : "",
			"tFileCreateTime" : {
				"wYear": 0,
				"byMonth": 0,
				"byDay": 0,
				"byHour": 0,
				"byMinute": 0,
				"bySecond": 0,
				"wMicroSecond": 0
			}
	   }
	}
  @endverbatim
*/
	Ev_MtApi_Vc_CodecSnapshot_Rsp,


	/**
  @brief   ��ѯ��������ļ���Ӧ		
  
   MainBuf(#u32, dwResult) //��ѯ״̬��� 0���ɹ� 1��ʧ�� \n
   MainBuf(#TSnapshotFileInfo_Api, tFileInfo)

   @verbatim
	{
	   "dwResult": 0,
	   "tSnapshotFileInfo":{
			"achFilePath" : "",
			"achFileName" : "",
			"tFileCreateTime" : {
				"wYear": 0,
				"byMonth": 0,
				"byDay": 0,
				"byHour": 0,
				"byMinute": 0,
				"bySecond": 0,
				"wMicroSecond": 0
			}
	   }
	}
  @endverbatim
*/
	Ev_MtApi_Vc_CodecSnapshotQueryLatestFile_Rsp,

	/**
  @brief   ����ftp����֪ͨ		
  
  
   MainBuf(#s32, dwCodecType) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponent \n
   MainBuf(#s32, dwCodecIdx) //����һ·�Ŀ��ա�ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCodecComponentIndex \n
   MainBuf(#BOOL32, bResult) //�Ƿ�����ɹ� 

	@verbatim
   {
   "dwCodecType": 0,
   "dwCodecIdx": 0,
   "bResult": true
   }
  @endverbatim
*/
	Ev_MtApi_Vc_CodecFtpSnapshot_Ntf,


/**
  @brief   �����ɿ����ϱ� 
  
   MainBuf(#TSnapshotFileInfo_Api , tSnapshotFileInfo)

  @verbatim
	{
		"tSnapshotFileInfo":{
		    "achFilePath" : "",
		    "achFileName" : "",
		    "tFileCreateTime" : {
			    "wYear": 0,
			    "byMonth": 0,
			    "byDay": 0,
			    "byHour": 0,
			    "byMinute": 0,
			    "bySecond": 0,
			    "wMicroSecond": 0
		    }
		}
	}
  @endverbatim
*/
	Ev_MtApi_Vc_CodecSnapshot_Ntf, 


/**
  @brief    ��ѯ�����ļ��б���Ϣ��Ӧ  
  
	////һ����Ϣ�ϱ������ļ��б�ʱЯ����Ϣ���к�chSeq �����кŴ�1��ʼ�����������յ����һ����ϢʱЯ��-1��ֻ�ϱ�һ����ϢʱЯ��0�� \n
   MainBuf(#s8, chSeq)//��Ϣ���к� \n
   SubBuf(#TSnapshotFileList_Api, tFileList)

	@verbatim
	{
	    "chSeq" : 0,
	    "tSnapshotFileList" : {
		    "arrTSnapshotFileInfo": [
			    {
				    "achFilePath": "",
				    "achFileName": "",
				    "tFileCreateTime": {
				        "wYear": 0,
				        "byMonth": 0,
				        "byDay": 0,
				        "byHour": 0,
				        "byMinute": 0,
				        "bySecond": 0,
				        "wMicroSecond": 0
				    }
			    }
		    ]
		}
	}
  @endverbatim
*/
	Ev_MtApi_Vc_CodecSnapshotQueryFileList_Rsp, 


/**
  @brief    ɾ��һ�ſ�����Ӧ  	
  
   
   MainBuf(#BOOL32, bResult) \n
   MainBuf(#TSnapshotFileInfo_Api, tFileInfo)

	@verbatim
	{
	   "bResult": true,
	   "tSnapshotFileInfo":{
			"achFilePath" : "",
			"achFileName" : "",
			"tFileCreateTime" : {
				"wYear": 0,
				"byMonth": 0,
				"byDay": 0,
				"byHour": 0,
				"byMinute": 0,
				"bySecond": 0,
				"wMicroSecond": 0
			}
	   }
	}
  @endverbatim
*/
	Ev_MtApi_Vc_CodecSnapshotDelOneFile_Rsp, 

/**
  @brief    һ�ſ��ձ�ɾ���ϱ�   
  
   MainBuf(#TSnapshotFileInfo_Api , tSnapshotFileInfo)
  @verbatim
   {
		"tSnapshotFileInfo":{
			"achFilePath" : "",
			"achFileName" : "",
			"tFileCreateTime" : {
				"wYear": 0,
				"byMonth": 0,
				"byDay": 0,
				"byHour": 0,
				"byMinute": 0,
				"bySecond": 0,
				"wMicroSecond": 0
			}
		}
	}
  @endverbatim
*/
	Ev_MtApi_Vc_CodecSnapshotDelOneFile_Ntf, 

/**
	@brief ɾ�����п����ļ���Ӧ
	
	MainBuf(#BOOL32 , pbResult)	

	@verbatim
	{
		 "bResult": true,
	}
	@endverbatim
*/
	Ev_MtApi_Vc_CodecSnapshotDelAllFile_Rsp, 

/**
  @brief    ���п����ļ����֪ͨ	
  @verbatim
  @endverbatim
*/
	Ev_MtApi_Vc_CodecSnapshotDelAllFile_Ntf, 

/**
  @brief    ����һ�ſ����ļ���Ӧ	
  
  
   MainBuf(#EmFileCopyErr_Api, emResult) \n
   MainBuf(#TSnapshotFileInfo_Api, tFileInfo)
   @verbatim
   {
        "emResult": 0,
        "tSnapshotFileInfo":{
            "achFilePath" : "",
            "achFileName" : "",
            "tFileCreateTime" : {
                "wYear": 0,
                "byMonth": 0,
                "byDay": 0,
                "byHour": 0,
                "byMinute": 0,
                "bySecond": 0,
                "wMicroSecond": 0
            }
        }
  }
  @endverbatim
*/
	Ev_MtApi_Vc_CodecSnapshotExportOneFile_Rsp,

/**
  @brief    �������п����ļ���Ӧ	
  
   MainBuf(#EmFileCopyErr_Api , emResult)	
  @verbatim
  {
      "emResult": 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_CodecSnapshotExportAllFile_Rsp,

/**
  @brief    �������ս���
  
  MainBuf(#u32)	
  @verbatim
  {
      "basetype": 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_CodecSnapshotExportProgress_Ntf,

/**
  @brief    ����ͷ����֪ͨ

  MainBuf(#EmCodecComponentIndex_Api, emVideoIndex_Api) \n
  MainBuf(#EmEquipmentUpgrading_Api, emEquipment_Api) \n
  MainBuf(#EmCameraUpgradeErrCode_Api, emErrorCode)
  @verbatim
  {
		"emVideoIndex" : 0,
		"emEquipType" : 0,
		"emErrorCode" : 0
  }

  @endverbatim
*/
	Ev_MtApi_Vc_DeviceCameraUpgrade_Ntf,

/**
  @brief    ����ͷ�汾��Ϣ��Ӧ
   
   MainBuf(#s8*, strCamVer) \n
   MainBuf(#EmCodecComponentIndex_Api, emIndex)

	@verbatim
	{
	    "MainParam" : {
			"basetype" : ""
		},
		"AssParam" : {
			"basetype" : 0
		}
	}
  @endverbatim
*/
	Ev_MtApi_Vc_DeviceCameraVersion_Rsp,

/**
  @brief    ����ң��������֪ͨ����web��ģ��ң����
  
   MainBuf(#TMTKeyPressInfo_Api, ptKeyCodeInfo)

  @verbatim
	{
	    "bKeyDown": true,
	    "dwKeySource": 1,
	    "dwKeyCode": 1,
	    "dwKeyCount": 1
	}
  @endverbatim
*/
	Ev_MtApi_Vc_DeviceKeyCodeNtf,

/**
  @brief    TLý���¼�֪ͨ
  
   MainBuf(#s32, nEvent)

  @verbatim
	{
	    "basetype": 1
	}
  @endverbatim
*/
	Ev_MtApi_Vc_CodecEvent_Ntf,
	
/**
  @brief    TL��Ƶ�������¼�֪ͨ
  
   MainBuf(#TDevInfoList_Api, insert_list) \n
   SubBuf(#TDevInfoList_Api, remove_list)//

  @verbatim
	{
	    "MainParam": {
	        "arrTDevInfo": [
	            {
	                "achDevName": "",
	                "achDevGuid": ""
	            }
	        ]
	    },
		"AssParam": {
		    "arrTDevInfo": [
		        {
		            "achDevName": "",
		            "achDevGuid": ""
		        }
		    ]
		}
	}
  @endverbatim
*/
	Ev_MtApi_Vc_CodecAudCapDevChange_Ntf,

/**
  @brief    ��Ƶ�ɼ��豸�仯֪ͨ
  
   MainBuf(#TDevInfoList_Api, insert_list) \n
   SubBuf(#TDevInfoList_Api, remove_list)//

	@verbatim
	{
	    "MainParam": {
	        "arrTDevInfo": [
	            {
	                "achDevName": "",
	                "achDevGuid": ""
	            }
	        ]
	    },
		"AssParam": {
		    "arrTDevInfo": [
		        {
		            "achDevName": "",
		            "achDevGuid": ""
		        }
		    ]
		}
	}
  @endverbatim
*/
	Ev_MtApi_Vc_CodecVidCapDevChange_Ntf,
	
/**
  @brief    ���ö໭������Ӧ
  
  MainBuf(#u32, dwPIPModem)
  @verbatim
  {
      "basetype": 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_CodecSetPIP_Rsp,

/**
  @brief    ���ö໭������Ӧ
  
  MainBuf(#u32, dwPIPModem)
  @verbatim
  {
      "basetype": 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_CodecQueryPIP_Rsp,

/**
  @brief    �໭����״̬֪ͨ
  
  MainBuf(#u32, dwPIPModem)
  @verbatim
  {
      "basetype": 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_CodecPIPState_Ntf,


/**
  @brief    ������ս��֪ͨ ��TL	
  
  MainBuf(#EmCodecComponent_Api, emCodecType) \n
  MainBuf(#EmCodecComponentIndex_Api, emCodecId) \n
  MainBuf(#EmPicFormat_Api, emPicFormat) \n
  MainBuf(#s8*, achFileName)
  
  @verbatim
  {
       "emCodecType" : 0,
       "emCodecId" : 0,
       "emPicFormat" : 0,
       "achFileName" : "str"
  }
  @endverbatim
*/
	Ev_MtApi_Vc_CodecSavePic_Ntf,
	
/**
  @brief    ����mic����	
  
  MainBuf(#EmUartNum_Api, pemUartNum) \n
  SubBuf(#BOOL32, pbResult) 
  @verbatim
  {
      "MainParam" : {
           "basetype" : 0
      },
      "AssParam" : {
           "basetype" : 0 
      }
  }
  @endverbatim
*/
	Ev_MtApi_Vc_DeviceDMicUpgrade_Ntf,

/**
  @brief    ����mic�汾��ѯ�ظ�	
  
  MainBuf(#EmUartNum_Api , pemUartNum) \n
  MainBuf(#s8*, pbyVersion)
  
  @verbatim
  {
      "MainParam": {
           "basetype": 0
      },
      "AssParam": {
           "achVersion": "str"
      }
  }
  @endverbatim
*/
	Ev_MtApi_Vc_DeviceDMicVersion_Rsp,

/**
  @brief    ����mic�����ظ�
  
  MainBuf(#EmUartNum_Api, pemUartNum) \n
  SubBuf(#BOOL32, pbResult)
  @verbatim
  {
      "MainParam" : {
          "basetype" : 0
      },
      "AssParam" : {
          "basetype" : 0 
      }
  }
  @endverbatim
*/
	Ev_MtApi_Vc_DeviceWMicUpgrade_Ntf,


/**
  @brief    ����mic�汾��ѯ�ظ�
  
  MainBuf(#EmUartNum_Api, pemUartNum) \n
  SubBuf(#s8*, pbyVersion)
  @verbatim
  {
      "MainParam": {
           "basetype": 0
      },
      "AssParam": {
           "achVersion": "str"
      }
  }
  @endverbatim
*/
	Ev_MtApi_Vc_DeviceWMicVersion_Rsp,
	
/**
  @brief    ¼����̿ռ�澯֪ͨ
  
  MainBuf(#u32, dwDiskSpace)   u32��ʾ�澯�Ĵ���ʣ��ռ䣬��windows
  @verbatim
  {
       "basetype" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_CodecRecDiskAlarm_Ntf,


	/**
  @brief   ������ƵԴѡ��֪ͨ
  
  MainBuf(#EmCameraView_Api, emCodecIdx)   
  @verbatim
  { 
       "basetype" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_CodecSelectLocalVideoView_Ntf,

		/**
  @brief   ������ƵԴѡ�����ݲ�ѯ��Ӧ
  
  MainBuf(#EmCameraView_Api, emCodecIdx)   
  @verbatim
  { 
       "basetype" : 0
  }
  @endverbatim
*/

	Ev_MtApi_Vc_CodecGetLocalVideoView_Rsp,
	

/**
  @brief    ��ʼ��Ƶ�ɼ�ʧ��֪ͨ  ��windows
  @verbatim
  @endverbatim
*/
	Ev_MtApi_Vc_CodecStartVidCapFailed_Ntf,

/**
  @brief    ����ͷ�������Ͳ�ѯ��Ӧ
  
  MainBuf(#TMTCameraTypeList_Api, tMtCameraTypeList_Api)
  @verbatim
  {
      "atCameraTypeList": [
          {
              "achName" : "str",
              "dwMaxAddr" : 0,
              "dwMaxSpeedLevel" : 0
          }
      ]
  }
  @endverbatim
*/
	Ev_MtApi_Vc_DeviceCameraTypeCapset_Rsp,

/**
  @brief    Ӳ�ն�֧�ֵ�����ͷ����	
  
  MainBuf(#TMTCameraTypeList_Api, tMtCameraTypeList_Api)
  @verbatim
  {
      "atCameraTypeList": [
          {
              "achName" : "str",
              "dwMaxAddr" : 0,
              "dwMaxSpeedLevel" : 0
          }
      ]
  }
  @endverbatim
*/
	Ev_MtApi_Vc_DeviceCameraTypeCapset_Ntf,

/**
  @brief    FXO���е���	
  
  MainBuf(#s8*, pchAlias) �Զ˱���
  @verbatim
  {
       "basetype": "str"
  }
  @endverbatim
*/
	Ev_MtApi_FxoCallIncoming_Ntf,

/**
  @brief   FXO ����״̬
  
  MainBuf(#TFxoState_Api, tMtFxoState)
  @verbatim
  {
       "emState": 0
  }
  @endverbatim
*/
	Ev_MtApi_FxoCallLinkState_Ntf,

/**
  @brief   FXO ����״̬
  
  MainBuf(#s8*)
  @verbatim
  {
       "basetype": ""
  }
  @endverbatim
*/
	Ev_MtApi_FxoMakeCall_Ntf,

/**
  @brief    ��ȡ����ͷ������Ӧ����windows
  
   MainBuf(#TImageParam_Api, tImageParam)
   @verbatim
   {
       "emImgParamType" : 0,
       "dwVal" : 0,
       "bAuto" : 0
   }
  @endverbatim
*/
	Ev_MtApi_CodecGetCameraParam_Rsp,

/**
  @brief    ��ȡĬ������ͷ������Ӧ����windows
  
   MainBuf(#TImageParam_Api, tTImageParam_Api)
   @verbatim
   {
       "emImgParamType" : 0,
       "dwVal" : 0,
       "bAuto" : 0
   }
  @endverbatim
*/
	Ev_MtApi_CodecGetDefaultCameraParam_Rsp,

/**
	@brief ����ͷԤ��λ������Ӧ

	MainBuf(#EmCodecComponentIndex_Api, vid_idx)//������ƵԴ���� \n
	MainBuf(#BOOL32, bType)//TRUE��ʾ���� FALSE��ʾ���� n
    MainBuf(#u8, byIndex)//��ǰ������Ԥ��λ����

	@verbatim
	{
		"emVideoIndex" : 0,
		"bType" : 0,
		"byIndex" : 0
	}
	@endverbatim
*/
	Ev_MtApi_Vc_DeviceCameraPreset_Rsp,

/**
  @brief    ��ȡԤ��λͼƬ��Ӧ
  
  MainBuf(#TMTCameraPresetPicList_Api, ptMtCameraPresetPicList_Api) \n
  SubBuf(#EmCodecComponentIndex_Api, emVideoIndex_Api)

	@verbatim
	{
	    "MainParam" : {
	        "dwPresetPicCnt" : 0,
			"aachPresetPicName" : [
				{
					"basetype" : ""
				}
			]
		},
		"AssParam" : {
			"basetype" : 0
		}
	}
   @endverbatim
*/
	Ev_MtApi_Vc_DeviceQueryCameraPresetPic_Rsp,

/**
  @brief    �绰�˻�� ֪ͨ�����棬 ��������Ƿ��غ�-- add by zwf
  
  MainBuf(#s8*, pchDialNum)
  @verbatim
  {
      "basetype" : "str"
  }
  @endverbatim
*/
    Ev_MtApi_Vc_IsRecallDial_Ntf,

/**
  @brief    ���õ绰�˻���غ�֪ͨ-- add by zwf	
  
  MainBuf(#BOOL32, bRecall)
  @verbatim
  {
       "basetype" : true
  }
  @endverbatim
*/  
    Ev_MtApi_Vc_SetRecallDial_Ntf,

/**
  @brief    �غ�ѡ����֪ͨ	
  
  MainBuf(#BOOL32, bRecall) \n
  SubBuf(#s8*, pchDialNum)

  @verbatim
  {
      "MainParam" : {
          "basetype" : true
      },
      "AssParam" : {
          "basetype" : "str"
      }
  }
  @endverbatim
*/
    Ev_MtApi_Vc_IsRecallDialResult_Ntf,

/**
  @brief    ������ѯ״̬����windows,mcc�ͻ���
  
   MainBuf(#BOOL32, bPollBroadCast)
  @verbatim
   {
       "basetype" : true
   }
  @endverbatim
*/
	Ev_MtApi_McPollBroadCast_Ntf,

/**
  @brief  �����ƶ�¼��״̬֪ͨ
  
  MainBuf(#TCloudRecordState_Api, tRecordState)
  @verbatim
   {
	 "bCloudRecord": true,
	 "tStartRecordTime":
	 {
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
    Ev_MtApi_Vc_Conf_SpareCloudRecordState_Ntf,


	/**
  @brief  �����ƶ�¼��״̬֪ͨ
  
   MainBuf(#TCloudRecordState_Api, tRecordState)
  @verbatim
   {
	 "bCloudRecord": true,
	 "tStartRecordTime":
	 {
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
    Ev_MtApi_Vc_Conf_SpareCloudRecordState_Rsp,

/**
  @brief   ��������ͷ�������ػ���Զ��
  
  MainBuf(#EmSite_Api, emSite)
  @verbatim
  {
  "basetype": 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_SetCamCtrlSite_Ntf,

	/**
  @brief   ��ǰ������ӦԤ��λ�ظ�
  
  MainBuf(#EmCodecComponentIndex_Api, emCodecId)
  SubBuf(#u8, byIndex)
  @verbatim
  {
  "emCodecId": 0
  "byIndex": 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_CurCodecPresetIndex_Rsp,

/**
  @brief   ע����Ȩ��֤
  
  MainBuf(#BOOL32, bAuth)
  @verbatim
  {
     "basetype" : true
  }
  @endverbatim
*/
	Ev_MtApi_Vc_RegAuthResult_Ntf,

/**
  @brief   �Զ˵�ǰ����ƵԴ������Ե�    �Ǳ�
  
  MainBuf(#TMultiVideoInfo_Api, tVideList)
  @verbatim
  {
     "atVideoInfo" :
		[
			{
			"emChanIdx" : 0,
			"dwVideoSrc" : 0,
			"bFeccEnable": true,
			"bHasVideo": true
			}
		]
  }
  @endverbatim
*/
	Ev_MtApi_Vc_PeerVideoSrc_Ntf,

	/**
  @brief   �Զ˵�ǰ����ƵԴ������Ե�   �Ǳ�
  
  MainBuf(#TMultiVideoInfo_Api, tVideList)
  @verbatim
  {
     "atVideoInfo" :
		[
			{
			"emChanIdx" : 0,
			"dwVideoSrc" : 0,
			"bFeccEnable": true,
			"bHasVideo": true
			}
		]
  }
  @endverbatim
*/
	Ev_MtApi_Vc_PeerVideoSrc_Rsp,

	/**
  @brief   ��ȡ��ǰ������ѯ���ն�
  
  MainBuf(#TMtId_Api)
  @verbatim
  {
      "dwMcuId" : 0,
	  "dwTerId" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_GetCurPollMt_Rsp,

	/**
  @brief   ��������������������Ч����״̬��ʾ
  
  MainBuf(#EmLocalSoundType_Api) \n
  MainBuf(#EmLocalSoundIndex_Api) \n
  MainBuf(#BOOL32) 
  @verbatim
  {
      "emSoundType" : 0,
	  "emSoundIdx" : 0,
	  "bPlay" : false
  }
  @endverbatim
*/
	Ev_MtApi_Vc_CodecLocalSoundPlay_Ntf,

	/**
  @brief   ����������������Ч��������Ч���Ų�ѯ��Ӧ(������Ч�Ͷ�����Ч�����Ǹ��̲�������ʱ���ṩ��ѯ)
  
  MainBuf(#EmLocalSoundType_Api) \n
  MainBuf(#EmLocalSoundIndex_Api) \n
  MainBuf(#BOOL32)
  {
      "emSoundType" : 0,
	  "emSoundIdx" : 0,
	  "bPlay" : false
  }
  @endverbatim
*/
	Ev_MtApi_Vc_CodecGetLocalSoundPlayState_Rsp,

	/**
  @brief   �������ͼƬ���㹦��֪ͨ
  
  MainBuf(#EmCodecComponent_Api)
  MainBuf(#EmCodecComponentIndex_Api)
  MainBuf(#BOOL32)
  @verbatim
  {
      "emCodecType" : 0,
	  "emCodecIdx" : 0,
	  "bOn" : false
  }
  @endverbatim
*/
	Ev_MtApi_Vc_CodecMonitorPic_Ntf,

	/**
  @brief   ��ѯ���ͼƬ���㹦����Ӧ
  
  MainBuf(#EmCodecComponent_Api) \n
  MainBuf(#EmCodecComponentIndex_Api) \n
  MainBuf(#BOOL32)
  @verbatim
  {
      "emCodecType" : 0,
	  "emCodecIdx" : 0,
	  "bOn" : false
  }
  @endverbatim
*/
	Ev_MtApi_Vc_CodecMonitorPicStatus_Rsp,

/**
  @brief �����ļ���������Ӧ
  
  MainBuf(#BOOL32) \n
  MainBuf(#TSnapshotFileInfo_Api) \n
  MainBuf(#TSnapshotFileInfo_Api)
  @verbatim
  {
    "bSuccess": false,
    "tSrcInfo":
    {
        "achFilePath" : "",
		"achFileName" : "",
		"tFileCreateTime" : 
        {
			"wYear": 0,
			"byMonth": 0,
			"byDay": 0,
			"byHour": 0,
			"byMinute": 0,
			"bySecond": 0,
			"wMicroSecond": 0
	    }
    },
    "tDstInfo":
    {
        "achFilePath" : "",
		"achFileName" : "",
		"tFileCreateTime" : 
        {
			"wYear": 0,
			"byMonth": 0,
			"byDay": 0,
			"byHour": 0,
			"byMinute": 0,
			"bySecond": 0,
			"wMicroSecond": 0
	    }
    }
}
  @endverbatim
*/
	Ev_MtApi_Vc_CodecSnapshotRename_Rsp,

/**
  @brief �����ļ�������֪ͨ

  MainBuf(#TSnapshotFileInfo_Api)
  SubBuf(#TSnapshotFileInfo_Api)
  @verbatim
  {
    "tSrcInfo":
    {
        "achFilePath" : "",
		"achFileName" : "",
		"tFileCreateTime" : 
        {
			"wYear": 0,
			"byMonth": 0,
			"byDay": 0,
			"byHour": 0,
			"byMinute": 0,
			"bySecond": 0,
			"wMicroSecond": 0
	    }
    },
    "tDstInfo":
    {
        "achFilePath" : "",
		"achFileName" : "",
		"tFileCreateTime" : 
        {
			"wYear": 0,
			"byMonth": 0,
			"byDay": 0,
			"byHour": 0,
			"byMinute": 0,
			"bySecond": 0,
			"wMicroSecond": 0
	    }
    }
}
  @endverbatim
*/
	Ev_MtApi_Vc_CodecSnapshotRename_Ntf,

/**
  @brief ֹͣ�������п����ļ���֪ͨ
  @verbatim
  @endverbatim
*/
	Ev_MtApi_Vc_CodecStopExportAllSnapshotFiles_Ntf,

	/**
  @brief ��������ƵԴ�б�����
  MainBuf(#TMtId_Api)
  SubBuf(#TMultiVideoAlias_Api)
  @verbatim
     {
       "MainParam" : {
	    "dwMcuId": 192,
	    "dwTerId": 10
       },
       "AssParam" : {
    "atVideoAlias": [
        {
            "emType": 1,
            "emIdx": 0,
            "tMultiVideoSource": {
                "atVidSource": [
                    {
                        "byVideoPort": 0,
                        "achPortName": ""
                    }
                ]
            }
        }
    ]
   }
  }

  @endverbatim
*/
	Ev_MtApi_Vc_TerGetTerVidAlias_Ntf,
	
	/**
  @brief �Զ�Ԥ��λ�б�
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
	Ev_MtApi_Vc_PeerCameroPos_Ntf,

/**
  @brief ��������ƵԴ�б�����
  MainBuf(#TMtId_Api)
  SubBuf(#TAllMTPreSetNameInfoCfg_Api ,tCfg_Api)
  @verbatim
  {
	 "MainParam" : {
		"dwMcuId": 192,
		"dwTerId": 10
	 },
	 "AssParam" : {
		 "byCnt":0,
		 "atPresetNameInfo" :[
			 {
				 "dwPresetIndex" : 0,
				 "atPresetNameInfo" : [
					 {
						 "dwPresetIndex":0,
						 "achPresetName":""
					 }
				 ]	
			 }
		]
	 }
  }
  @endverbatim
*/
	Ev_MtApi_Vc_TerGetTerCameraPos_Ntf,

/**
  @brief Fxo���д������ϱ�
  MainBuf(#u32)
  @verbatim
  {
	 "basetype" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_FxoCallErrorCode_Ntf,

/**
  @brief vrs������ʱ�������ϱ�
  MainBuf(#u32)
  @verbatim
  {
	 "basetype" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_VodGetListTimeOut_Ntf,

    /**
	@brief ������ر�OSD����֪ͨ
	
	MainBuf(#BOOL32 , pbResult)	

	@verbatim
	{
		 "bResult": true,
	}
	@endverbatim
*/
	Ev_MtApi_Vc_CodecOsdSnapShotOpen_Ntf, 

	/**
  @brief    ����ԤԼֱ�����б��Ӧ
  
   MainBuf(#u32, dwErrorId) \n
   MainBuf(#TVodResRoomsDetail_Api) \n
   MainBuf(#TVodGetResRoomReq_Api)

   @verbatim
   {
   "dwErrId":0,
   "tVrsRoomsDetail_Api":{
		"atRoomDetail":[
			{
				achConfName:"",
				achStartTime:""
			}
		],		 
		"dwCnt":0
	},
	"tReqParam_Api":{
		dwNums1Page:0,
		dwPageId:0,
		achIncludeName:""
	}
   }

  @endverbatim
*/
	Ev_MtApi_Vc_VodNewGetResRoomInfo_Ntf,
	Ev_MtApi_Vc_VodNewGetResRoomInfo_Fin_Ntf,


/**
	@brief ������ر�Osd ֪ͨ
	
	MainBuf(#BOOL32 , bShow)	

	@verbatim
	{
		 "bShow": true,
	}
	@endverbatim
*/
	Ev_MtApi_Vc_CodecIsShowOsd_Ntf,

/**
	@brief ��Ƶͨ�����в���֪ͨ,����IPW
	
	MainBuf(#s32, nCompType)  ��������	
	MainBuf(#s32, nCompIndex) �ڼ�·
	MainBuf(#TNetAddr_Api, tLocalRtp)
	MainBuf(#TNetAddr_Api, tLocalRtcp)
	MainBuf(#TNetAddr_Api, tPeerRtp)
	MainBuf(#TNetAddr_Api, tPeerRtcp)
	MainBuf(#TAudEncParam_Api, tAudEncParam)
	MainBuf(#BOOL32,bG7221Reverse)   �����Ƶ��ΪG7221���Ͳ��ù�������ֶε�ֵ
	MainBuf(#TDynamicPayload_Api, tPayload)
	MainBuf(#TEncryptKey_Api, tEncryptKey)

	@verbatim
	{
		 
	}
	@endverbatim
*/
	Ev_MtApi_Vc_AudEncChanParam_Ntf,

/**
	@brief ��Ƶͨ�����в���֪ͨ,����IPW
	
	MainBuf(#s32, nCompType)	��������
	MainBuf(#s32, nCompIndex)	�ڼ�·
	MainBuf(#TNetAddr_Api, tLocalRtp)
	MainBuf(#TNetAddr_Api, tLocalRtcp)
	MainBuf(#TNetAddr_Api, tPeerRtp)
	MainBuf(#TNetAddr_Api, tPeerRtcp)
	MainBuf(#TVidEncParam_Api, tVidEncParam)
	MainBuf(#TDynamicPayload_Api, tPayload)
	MainBuf(#TEncryptKey_Api, tEncryptKey)

	@verbatim
	{
		 
	}
	@endverbatim
*/
	Ev_MtApi_Vc_VidEncChanParam_Ntf,

/**
	@brief �Ƿ���Ҫnat��Խ��֪ͨ,����IPW
	
	MainBuf(#s32, nCompType)	��������
	MainBuf(#s32, nCompIndex)	�ڼ�·
	MainBuf(#BOOL32, bEnable)   �Ƿ����ô�Խ
	MainBuf(#TNetAddr_Api, tLocalRtp)
	MainBuf(#TNetAddr_Api, tLocalRtcp)
	MainBuf(#TNetAddr_Api, tPeerRtp)
	MainBuf(#TNetAddr_Api, tPeerRtcp)

	@verbatim
	{
		 
	}
	@endverbatim
*/
	Ev_MtApi_Vc_IsNatTraver_Ntf,

/**
	@brief ��ʼ�����֪ͨ,����IPW

	MainBuf(#s32, nCompType)	��������
	MainBuf(#s32, nCompIndex)	�ڼ�·
	
	@verbatim
	{
		
	}
	@endverbatim
*/
	Ev_MtApi_Vc_StartEnc_Ntf,

/**
	@brief ֹͣ�����֪ͨ,����IPW

	MainBuf(#s32, nCompType)	��������
	MainBuf(#s32, nCompIndex)	�ڼ�·

	@verbatim
	{
		
	}
	@endverbatim
*/
	Ev_MtApi_Vc_StopEnc_Ntf,

/**
	@brief mcu��������ֱ���,����IPW

	MainBuf(#s32, nCompType)	����
	MainBuf(#s32, nCompIndex)	�ڼ�·
	MainBuf(#u16, wWidth)	    ���
	MainBuf(#u16, wHeight)	    �߶�

	@verbatim
	{
		
	}
	@endverbatim
*/
	Ev_MtApi_Vc_SetEncRes_Ntf,

/**
	@brief mcu��������֡��,����IPW

	MainBuf(#s32, nCompType)	����
	MainBuf(#s32, nCompIndex)	�ڼ�·
	MainBuf(#u8,  byFps)	    ֡��

	@verbatim
	{
		
	}
	@endverbatim
*/
	Ev_MtApi_Vc_SetEncFps_Ntf,

/**
	@brief �Զ˵�����������,����IPW

	MainBuf(#s32, nCompType)	����
	MainBuf(#s32, nCompIndex)	�ڼ�·
	MainBuf(#u16, wBitrate)	    ��������

	@verbatim
	{
		
	}
	@endverbatim
*/
	Ev_MtApi_Vc_SetEncBitrate_Ntf,

/**
	@brief �Զ������͹ؼ�֡,����IPW

	MainBuf(#s32, nCompType)	����
	MainBuf(#s32, nCompIndex)	�ڼ�·

	@verbatim
	{
		
	}
	@endverbatim
*/
	Ev_MtApi_Vc_FastUpdate_Ntf,

/**
	@brief Ӳ�ն˿�ʼ����¼��ظ�

	MainBuf(#BOOL32 , bSuccess)	
	@verbatim
	{
		
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_StartLocalRec_Ntf,

/**
	@brief Ӳ�ն�ֹͣ����¼��ظ�

	MainBuf(#BOOL32 , bSuccess)	
	@verbatim
	{
		
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_StopLocalRec_Ntf,

/**
	@brief Ӳ�ն���ͣ����¼��ظ�

	MainBuf(#BOOL32 , bSuccess)	
	@verbatim
	{
		
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_PauseLocalRec_Ntf,

/**
	@brief Ӳ�ն˼�������¼��ظ�

	MainBuf(#BOOL32 , bSuccess)	
	@verbatim
	{
		
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_ContinueLocalRec_Ntf,

/**
	@brief Ӳ�ն˱���¼��ʣ��ʱ��֪ͨ����

	MainBuf(#u32 , dwRemainTime) 	
	@verbatim
	{
		
	}
	@endverbatim
*/ 


	Ev_MtApi_Vc_RemainTimeLocalRec_Ntf,


/**
	@brief Ӳ�ն˱���¼�������״̬�ϱ�

	MainBuf(#EmVideoRecordErrorNum_Api, emErrcode)	
	@verbatim
	{
		
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_LocalRecStatus_Ntf,

/**
	@brief ��ȡ����¼��״̬�Ļظ�(�Ƿ���¼��)

	MainBuf(#EmVideoRecordStatus_Api , emRecStatus)	
	@verbatim
	{
		
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_StartLocalRec_Rsp,

/**
	@brief ��ȡ���ؿ�ʼ¼��ʱ���֪ͨ

	MainBuf(#TMTTime_Api, tStartTime)	
	@verbatim
	{
		
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_LocalRecStartTime_Ntf,

/**
	@brief ͼƬ��ȡ��Ӧ


	MainBuf(#BOOL32, result)	
	@verbatim
	{
		result:0
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_CodecPicGet_Rsp,


/**
	@brief ��ȡ����״̬����Ӧ

	MainBuf(#BOOL32, result)	
	@verbatim
	{
		result:0
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_CodecGetMute_Rsp,

/**
	@brief ��ȡ����״̬����Ӧ

	MainBuf(#BOOL32, result)	
	@verbatim
	{
		result:0
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_CodecGetQuiet_Rsp,

/**
	@brief ��ȡ��ȡ����ͷ������Զ�ˣ����Ǳ��ص���Ӧ

	MainBuf(#EmSite_Api, emSite)	
	@verbatim
	{
		emSite:0
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_GetCameraCtrlSiteRt_Rsp,

/**
	@brief ��ȡ�������Ե���Ӧ

	MainBuf(#EmSrtpCryptoType_Api, emEncryType)	
	@verbatim
	{
		emEncryType: 0
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_GetEncryptType_Rsp,

	/**	
	@brief    TL������Ҫ��½vrs�󷵻ص�tokenֵ
	MainBuf(#TMTVrsUserInfo_Api, tVrsInfo_Api)

	@verbatim
	    "achToken" : "",
		"achUserDomainMoid": "",
		"achUserMoid": "",
	}
	@endverbatim
	*/
	Ev_MtApi_Vc_Vrs_UsrInfo_Ntf,

	
/**
	@brief �������˫��״̬֪ͨ

	MainBuf(#s32)	
	@verbatim
	{
		nCompType: 1   //��������ڼ�·��ע�⣺nCompType=20 ��ʾ˫��ֹͣ
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_MtStreamStatusRt_Ntf,

	/**	
	@brief    ֪ͨ�ϲ�������, ��ʱ����ipc
		
	MainBuf(#TMTStreamChanParam_Api, tParam)
	MainBuf(#EmCodecComponent_Api, emCodecType)
	MainBuf(#EmCodecComponentIndex_Api, emCodecIndex)

	@verbatim
	{	
		"tParam"��{
			"tEncParam":{
				"emEncMode": 0,
				"emVidFormat": 0, 
				"dwMaxKeyFrameInterval": 0,
				"dwMaxQuant": 0,
				"dwMinQuant": 0,
				"dwFrameRate": 0,
				"dwBitrate": 0,
				"dwH264Profile": 0, 
				"dwWidth": 0,
				"dwHeight": 0 ,  
			}
			"tTransRtp":{
				"emIpType": 0,
				"dwIp": 0,   
				"achIpV6":"",
				"dwPort": 0,   
			}
			"dwPayload":0,
		}
	    "emCodecType" : 0,
		"emCodecIndex": 0,
	}
	@endverbatim
	*/
	Ev_MtApi_Vc_Conf_EncVidChanParam_Ntf,
	/**	
	@brief    ֪ͨ�ϲ㿪ʼ����, ��ʱ����ipc
	MainBuf(#EmCodecComponent_Api, emCodecType)
	MainBuf(#EmCodecComponentIndex_Api, emCodecIndex)

	@verbatim
	{	
	    "emCodecType" : 0,
		"emCodecIndex": 0,
	}
	@endverbatim
	*/
	Ev_MtApi_Vc_Conf_StartVidEnc_Ntf,
	/**	
	@brief    ֪ͨ�ϲ�ֹͣ����, ��ʱ����ipc
	MainBuf(#EmCodecComponent_Api, emCodecType)
	MainBuf(#EmCodecComponentIndex_Api, emCodecIndex)

	@verbatim
	{	
	    "emCodecType" : 0,
		"emCodecIndex": 0,
	}
	@endverbatim
	*/
	Ev_MtApi_Vc_Conf_StopVidEnc_Ntf,
	/**	
	@brief    ֪ͨ�ϲ���������, ��ʱ����ipc
	MainBuf(#u32, dwBitrate)
	MainBuf(#EmCodecComponent_Api, emCodecType)
	MainBuf(#EmCodecComponentIndex_Api, emCodecIndex)

	@verbatim
	{	
		"dwBitrate": 0,
	    "emCodecType" : 0,
		"emCodecIndex": 0,
	}
	@endverbatim
	*/
	Ev_MtApi_Vc_Conf_SetBitRate_Ntf,
	/**	
	@brief    ֪ͨ�ϲ�Զ˵����ֱ���, ��ʱ����ipc
	MainBuf(#u16, wWeight)
	MainBuf(#u16, wHeight)
	MainBuf(#EmCodecComponent_Api, emCodecType)
	MainBuf(#EmCodecComponentIndex_Api, emCodecIndex)

	@verbatim
	{	
		"wWeight": 0,
		"wHeight": 0,
	    "emCodecType" : 0,
		"emCodecIndex": 0,
	}
	@endverbatim
	*/
	Ev_MtApi_Vc_Conf_PeerAdjustRes_Ntf,
	/**	
	@brief    ֪ͨ�ϲ�Զ˵���֡��, ��ʱ����ipc
	MainBuf(#u32, dwFps)
	MainBuf(#EmCodecComponent_Api, emCodecType)
	MainBuf(#EmCodecComponentIndex_Api, emCodecIndex)

	@verbatim
	{	
		"dwFps": 0,
	    "emCodecType" : 0,
		"emCodecIndex": 0,
	}
	@endverbatim
	*/
	Ev_MtApi_Vc_Conf_PeerAdjustFps_Ntf,
	/**	
	@brief    ֪ͨ�ϲ�Զ�����ؼ�֡, ��ʱ����ipc
	MainBuf(#EmCodecComponent_Api, emCodecType)
	MainBuf(#EmCodecComponentIndex_Api, emCodecIndex)

	@verbatim
	    "emCodecType" : 0,
		"emCodecIndex": 0,
	}
	@endverbatim
	*/
	Ev_MtApi_Vc_Conf_PeerReqIFrame_Ntf,	

	/**
	  @brief    �յ�UI ��ǰ���е�calllid�����ڰװ����	
  
	  MainBuf(#s8*, pchCallId)
	  @verbatim
	  {
		  "basetype" : "str"
	  }
	  @endverbatim
	*/
	Ev_MtApi_Vc_Callid_Rsp,

	/**
	@brief osd����/�ر�pc˫��֪ͨ


	MainBuf(#BOOL32, bOpen)	
	@verbatim
	{
		bOpen:0
	}
	@endverbatim
	*/ 
	Ev_MtApi_Vc_OsdCtrlPcAssStream_Ntf,

	/**
	@brief �������λ���ڴ�������֪ͨ

	MainBuf(#u8, byVidIdx )
	SubBuf(#EmCameraPantiltErrType_Api, emType )	
	@verbatim
	{
		
	}
	@endverbatim
	*/ 
	Ev_MtApi_Vc_DeviceCameraPantiltErr_Ntf,

	/**
	@brief    ʵ��ң��������֪ͨ
  
	MainBuf(#TMTKeyPressInfo_Api, ptKeyCodeInfo)
	@verbatim
	{
	    "bKeyDown": true,
	    "dwKeySource": 1,
	    "dwKeyCode": 1,
	    "dwKeyCount": 1
	}
	@endverbatim
	*/
	Ev_MtApi_Vc_EntityDeviceKeyCodeNtf,

	/**
	@brief ��ȡ�Ƿ�ر�������Ӧ

	MainBuf(#BOOL32, bVidoff)	
	@verbatim
	{
		bVidoff: 0
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_GetCloseMainVid_Rsp,

	/**
	@brief ��ѯ����ͷ�Ƿ�������������Ӧ
	
	MainBuf(#BOOL32 , pbResult)	

	@verbatim
	{
		 "bResult": true,
	}
	@endverbatim
*/
	Ev_MtApi_CodecGetIsCameraUpgrading_Rsp,

	/**
    @brief �Զ˲�����ͨ��֪ͨ
    @verbatim
    @endverbatim
   */
	Ev_MtApi_Vc_PeerNotQt_Ntf,

	/**
	@brief ����������͵�֪ͨ

	MainBuf(#EmSrtpCryptoType_Api, emEncryType)	
	@verbatim
	{
		emEncryType: 0
	}
	@endverbatim
	*/ 
	Ev_MtApi_Vc_GetEncryptType_Ntf,

    EV_UI_END(MTAPI_VC) = EVSEG_MTAPI_VC_END
};

#define Is_MtApiVC_Msg(m) ((m) >= EV_UI_BGN(MTAPI_VC) && (m) <= EV_UI_END(MTAPI_VC))

/**@}*/

/**@}*/
#endif // _MTAPI_EVENT_VC_H_
