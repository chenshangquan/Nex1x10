/*******************************************************************************//**
*@file          mtapi_event_vc.h
*@brief         实现MTAPI MtVideoConfSdk 给UI(观察者)事件通知的定义
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_EVENT_VC_H_
#define _MTAPI_EVENT_VC_H_
/**@addtogroup event 事件
*@{
*/

/**@addtogroup vcevent 会议事件
*@{
*/

#include "mtapi_event_def.h"

enum EmMtApiVCEv
{
	EV_UI_BGN(MTAPI_VC)  =	EVSEG_MTAPI_VC_BGN,

/**
  @brief    协议栈初始化成功与否	
  
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
  @brief    结束会议(点对点)通知
  
    MainBuf(#EmMtCallDisReason_Api, emDisReason)

  @verbatim
	{
		"basetype":0
	}
  @endverbatim
*/	
	Ev_MtApi_Vc_P2P_Ended_Ntf,  

/**
  @brief    结束会议(多点)通知
  
	MainBuf(#EmMtCallDisReason_Api, emDisReason) 

	@verbatim
	{
		"basetype":0
	}
  @endverbatim
*/	
	Ev_MtApi_Vc_MulConf_Ended_Ntf,  

/**
  @brief    取消呼叫通知意思是： 呼叫在建立之前，挂断了， 或者对端拒绝，或者超时， 或者自己主动挂断	
  
	MainBuf(#EmMtCallDisReason_Api, emDisReason)

	@verbatim
	{
		"basetype":0
	}
  @endverbatim
*/	
	Ev_MtApi_Vc_Conf_Canceled_Ntf,  
	 
/**
  @brief    呼叫连接中	
  
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
  @brief    呼叫到来 
  
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
  @brief    开始点对点会议 
  
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
  @brief    开始多点会议 	
  
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
  @brief    请求呼叫状态，需要回复rsp 	
  
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
  @brief    通知当前会议类型	
  
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
  @brief    错过的呼叫通知	
  

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
  @brief  当前会议是否加密通知
  
	MainBuf(#BOOL32, bIsEncrypt) 

	@verbatim
	{
		"basetype":true
	}
  @endverbatim
*/	
	Ev_MtApi_Vc_CallEncrypt_Ntf,

	/**
  @brief  当前会议是否加密回复
  
	MainBuf(#BOOL32, bIsEncrypt) 

	@verbatim
	{
		"basetype":true
	}
  @endverbatim
*/	
	Ev_MtApi_Vc_CallEncrypt_Rsp,

/**
  @brief   辅流发送状态响应
  
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
  @brief    辅流发送状态通知
  
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
  @brief    辅流接收状态响应
  
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
  @brief    辅流接收状态通知	
  
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


	//获取会议列表. 错误码是emConfList_Not_Finished_Api，表示数据没有收结束，其他错误码表示数据收结束
	//数据保存在sdk中， 需要再调用下KdvMt_ConfGetCurConfList
/**
  @brief   获取用户会议列表通知
  
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
  @brief   预加入会议结果通知	
  
   MainBuf(#EmMtJoinCreateConfRsp_Api, emRet)

	@verbatim
	{
		"basetype":0
	}
  @endverbatim
*/
	Ev_MtApi_Vc_PreJoinConfResult_Ntf,

/**
  @brief  预创建会议结果通知
  
   MainBuf(#EmMtJoinCreateConfRsp_Api, emRet) 

	@verbatim
	{
		"basetype":0
	}
  @endverbatim
*/
	Ev_MtApi_Vc_PreCreateConfResult_Ntf,


/**
  @brief    请求会议详细信息响应
  
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
  @brief  获取可用的总的会议室数量通知	
  
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
  @brief    会议模块错误码通知	
  
	MainBuf(#u32, dwErrCode) 

	@verbatim
	{
		"basetype": 0,
	}
  @endverbatim
*/
	Ev_MtApi_Vc_ErrorCode_Ntf,
	
/**
  @brief  终端编号通知   标准
  
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
  @brief  终端编号通知   标准
  
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
  @brief    当前会议所有在线终端通知 最多 KMTAPI_MAX_CONF_MT_MEMBER_NUM, sip多流有发送通道描述  标准
  
	MainBuf(#TMTEntityInfo_Api[], ptMtEntityInfo_Api) \n
    SubBuf(#u32, dwCount)//数组大小

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
					   "emMediatype"：1,
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
  @brief    终端加入通知
  
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
  @brief    终端退出通知	  标准
  
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
  @brief  当前会议所有在线终端通知  标准
  
	MainBuf(#TMTEntityInfo_Api[], atMtEntityInfo_Api)\n
    SubBuf(#u32, dwCount)//数组大小

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
					           "emMediatype"：1,
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

	//不用管
	Ev_MtApi_Vc_OffLineTerList_Ntf,   //暂不处理

	//不用管
	Ev_MtApi_Vc_OffLineTerList_Rsp,   //暂不处理

/**
  @brief    会议信息   非标
  
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
  @brief    简答会议信息通知   非标
  
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
  @brief    会议信息回复  非标
  
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
  @brief   会议剩余时间通知   非标
  
	MainBuf(#u32, dwConfRemainTime) 
	
  @verbatim
	{
			"basetype": 0,
		}
  @endverbatim
*/
	Ev_MtApi_Vc_ConfWillEnd_Ntf,

/**
  @brief    mc请求终端输入密码  标准
  @verbatim
  @endverbatim
*/
	Ev_MtApi_Vc_McReqTerPwd_Ntf,


/**
  @brief    强制挂断终端失败  标准
  @verbatim
  @endverbatim
*/
	Ev_MtApi_Vc_DropTerReject_Ntf,

/**
  @brief    主席邀请终端失败     非标
  
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
  @brief    会议发生失败    非标

  MainBuf(#EmMtConfFailureReason_Api, emReason)
  @verbatim
  {
		"basetype": 0,
  }
  @endverbatim
*/
	Ev_MtApi_Vc_ConfFailed_Ntf,

/**
  @brief    会议延长通知, 单位为分钟   非标

  MainBuf(#u16, dwDelay_time)

  @verbatim
	{
		"basetype": 0
	}
  @endverbatim
*/
	Ev_MtApi_Vc_ConfDelay_Ntf,

/**
  @brief    会议剩余时间通知	
  
  MainBuf(#u16, dwRest_time)
  @verbatim
  {
      "basetype" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_RestTime_Ntf,

/**
  @brief    延长会议时间结果

	MainBuf(#BOOL32, bResult)
  @verbatim
    {
		"basetype": true
	}
  @endverbatim
*/
	Ev_MtApi_Vc_ProlongResult_Ntf,

/**
  @brief    修改会议名称， 会议密码， 会议双流方式，会议持续时间，回复都是这一个    非标
  
  MainBuf(#EmMtModifyConfInfoType_Api, emType)\n
  SubBuf(#BOOL32, bResult)//修改是否成功结果
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
  @brief    主席收到发言人请求	标准
  
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
  @brief    发言人位置通知   非标
  
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
  @brief    被广播通知  标准
  @verbatim
  @endverbatim
*/
	Ev_MtApi_Vc_SeenByAll_Ntf,

	/**
  @brief    申请发言人超时
  @verbatim
  @endverbatim
*/
	Ev_MtApi_Vc_ApplySpeakTimerOut_Ntf,
	
	/**
  @brief    申请主席超时
  @verbatim
  @endverbatim
*/
	Ev_MtApi_Vc_ApplyChairTimerOut_Ntf,
	
		/**
  @brief    申请插话超时
  @verbatim
  @endverbatim
*/
	Ev_MtApi_Vc_ApplyChiemeInTimerOut_Ntf,
	
/**
  @brief    取消发言人指示
  @verbatim
  @endverbatim
*/
	Ev_MtApi_Vc_CancelSeenByAll_Ntf,


/**
  @brief    主席指定发言人结果通知  标准
  
  MainBuf(#BOOL32, bResult)//是否成功结果
  @verbatim
  {
	  "basetype": true
  }
  @endverbatim
*/
	Ev_MtApi_Vc_BroadcastResult_Ntf,


/**
  @brief    当前看的视频源通知  标准
  
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
  @brief    当前看的视频源通知   标准
  
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
  @brief   主席收到其他终端申请主席	  非标
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
  @brief    主席位置通知	 标准
  
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
  @brief    申请主席是否成功 和 被撤销主席令牌  标准
  
   MainBuf(#BOOL32, bGet)//是否获得主席令牌
  @verbatim
  {
	  "basetype" : true
  }
  @endverbatim
*/
	Ev_MtApi_Vc_ChairTokenGet_Ntf,

/**
  @brief   选看结果

   MainBuf(#BOOL32, bResult) //选看成功与否 标准 \n
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
  @brief    本终端被其他终端选看通知   标准
  
	@verbatim

  @endverbatim
*/
	Ev_MtApi_Vc_SeenByOther_Ntf,

/**
  @brief    本终端被其他终端取消选看	 标准
  
  @endverbatim
*/
	Ev_MtApi_Vc_CancelSeenByOther_Ntf,


/**
  @brief    其他终端向主席申请插话   非标
  
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
  @brief    当前终端插话状态通知	  非标
  
   MainBuf(#BOOL32, bInChime)//是否正在插话
   @verbatim
  {
    "basetype" : true
  }
  @endverbatim
*/
	Ev_MtApi_Vc_ChimeInState_Ntf,

/**
  @brief    当前终端插话失败  非标
  @verbatim
  @endverbatim
*/
	Ev_MtApi_Vc_ChimeInFailed_Ntf,

/**
  @brief    获得终端状态通知	  非标
  
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
  @brief   获得当前所有终端状态 最多 KMTAPI_MAX_CONF_MT_MEMBER_NUM

   MainBuf(#TMtEntityStatus_Api[], atMtEntityStatus_Api) \n
   SubBuf(#u32, dwCount)  //atMtEntityStatus_Api 数组大小

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
  @brief    轮询状态上报	
  
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
  @brief    轮询状态上报	
  
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
  @brief    当前正在轮询的终端通知	
  
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
  @brief    第一路视频发送接收通道关闭	
  @verbatim
  @endverbatim
*/

	Ev_MtApi_Vc_PrimoVideoOff_Ntf,

	//Ev_Conf_RollCallResult_Ntf   暂时不用
	Ev_MtApi_Vc_RollCallResult_Ntf,


	////////////////////////////////画面合成， 混音会控
/**
  @brief  开始vac结果     非标
  
  MainBuf(#BOOL32, bResult) \n
  SubBuf(#BOOL32, bVac)//是否语音激励
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
  @brief   停止vac结果   非标
  
  MainBuf(#BOOL32, bResult)\n
  SubBuf(#BOOL32, bVac)//是否语音激励
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
  @brief   开始讨论模式结果  非标
 
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
  @brief    停止讨论模式结果	 非标

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
  @brief    开始定制混音结果	  非标
  
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
  @brief    停止定制混音结果	 非标
  
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
	   CustomVMP     表示自主画面合成
	   ConfVMP:      表示会议画面合成
	*/

/**
  @brief    开始会议画面合成结果	 非标

  MainBuf(#BOOL32, bResult)
  @verbatim
  {
       "basetype":true
  }
  @endverbatim
*/
	Ev_MtApi_Vc_StartConfVMPResult_Ntf,

/**
  @brief    停止会议画面合成结果   非标
  
  MainBuf(#BOOL32, bResult)
  @verbatim
  {
       "basetype":true
  }
  @endverbatim
*/

	Ev_MtApi_Vc_StopConfVMPResult_Ntf,

/**
  @brief    设置会议画面合成结果	  非标
  
  MainBuf(#BOOL32, bResult)
  @verbatim
  {
       "basetype":true
  }
  @endverbatim
*/
	Ev_MtApi_Vc_SetConfVMPResult_Ntf,

/**
  @brief    开始自主画面合成结果    非标
  
  MainBuf(#BOOL32, bResult)
  @verbatim
  {
       "basetype":true
  }
  @endverbatim
*/
	Ev_MtApi_Vc_StartCustomVMPResult_Ntf,

/**
  @brief    停止自主画面合成结果	  非标
  
  MainBuf(#BOOL32, bResult)
  @verbatim
  {
       "basetype":true
  }
  @endverbatim
*/
	Ev_MtApi_Vc_StopCustomVMPResult_Ntf,	

/**
  @brief    设置自主画面合成结果	  非标
  
  MainBuf(#BOOL32, bResult)
  @verbatim
  {
       "basetype":true
  }
  @endverbatim
*/
	Ev_MtApi_Vc_SetCustomVMPResult_Ntf,


/**
  @brief    获取会议画面合成结果    非标
  
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
  @brief    获取自主画面合成结果   非标
  
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
  @brief    获取自主画面合成结果    非标
  
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
  @brief    选择会议画面合成结果	  非标
  
  MainBuf(#BOOL32, bResult)
  @verbatim
  {
	   "basetype":true
  }
  @endverbatim
*/
	Ev_MtApi_Vc_SelectConfVmpResult_Ntf,

/**
  @brief    混音成员参数通知    非标
  
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
  @brief    混音成员参数回复	   非标
  
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
  @brief    短消息通知     非标
  
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
  @brief    注册成功，原因是emRegSuccess_Api	
  
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
  @brief    注册成功，原因是emRegSuccess_Api	
  
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
  @brief    收到mcu转发过来的加入白板会议命令	
  
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
  @brief    收到UI 当前呼叫的calllid，用于白板会议	
  
  MainBuf(#s8*, pchCallId)
  @verbatim
  {
      "basetype" : "str"
  }
  @endverbatim
*/
	Ev_MtApi_Vc_Callid_Ntf,

/**
  @brief    mcu 回复主席， 是否同意设置vip列表    //add from here  非标
  
  MainBuf(#BOOL32, bResult)
  @verbatim
  {
      "basetype":true
  }
  @endverbatim
*/
	Ev_MtApi_Vc_SetVipListResult_Ntf,

/**
  @brief    mcu 通知终端， 当前vip列表	非标

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
  @brief    回复当前vip列表	 非标
  
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
  @brief    双流发送方通知 	

  MainBuf(#TMtId_Api, tMtId_Api) \n
  SubBuf(#BOOL32, bGrabbed)//是否当前终端被抢发
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
  @brief    获取当前双流发送方回复

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
  @brief     主席指定终端发双流 参数上报， 用与同步
  
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
  @brief    获取在线联系人列表	
  
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
  @brief    对端视频源信息	
  

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
  @brief    对端视频源信息	
  
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
  @brief    选看参数上报	
  
  MainBuf(#BOOL32, param) 当前是否在选看 \n
  SubBuf(#TViewTerParam_Api, param) 当前选看参数\n
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
  @brief    选看参数上报	
  
  MainBuf(#BOOL32, param)  当前是否在选看\n
  SubBuf(#TViewTerParam_Api, param) 当前选看参数
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


	//////////////////////////////////////////////////////////////////下面是vod 和 codec
	

/**
  @brief   登录Vod平台回应错误码
  
  MainBuf(#u32, dwErrorId)

	@verbatim
	{
		"basetype": 12
	}
  @endverbatim
*/
	Ev_MtApi_Vc_VodLogin_Ntf,

/**
  @brief   登录Vod平台回应账号权限
  
  MainBuf(#u32, dwErrorId)

	@verbatim
	{
		"basetype": 12
	}
  @endverbatim
*/
	Ev_MtApi_Vc_VrsRightMask_Ntf,

/**
  @brief   注销Vod平台回应
  
  MainBuf(#u32, dwErrorId)

	@verbatim
	{
		"basetype": 12
	}
  @endverbatim
*/
	Ev_MtApi_Vc_VodLogout_Ntf,

/**
  @brief    请求文件夹列表回应
  
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
  @brief    请求某一文件夹下的节目列表回应
  
  MainBuf(#u32, dwErrId) \n
  MainBuf(#TVodPrgsBaseInfo_Api, tBaseInfo)基本信息 \n
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
  @brief    请求某一文件夹下的节目列表回应
  
  MainBuf(#u32, dwErrId) 所属节目信息的索引 \n
  MainBuf(#TVodPrgsDetailInfo_Api, tDetailInfo)具体信息 \n
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
  @brief    请求直播室列表回应
  
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
  @brief    请求预约直播室列表回应 老接口保留 新添加请使用新接口
  
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
  @brief    点播结果通知
  
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
  @brief    点播播放状态通知
  
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
  @brief    获取已点播的点播信息响应
  
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
  @brief    获取点播源信息响应
  
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
  @brief    停止点播结果通知
  
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
  @brief    暂停点播结果通知
  
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
  @brief    恢复点播结果通知
  
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
  @brief    改变点播速率结果通知
  
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
  @brief    改变点播进度结果通知
  
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
  @brief    点播源指定流播放结果通知
  
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
  @brief    点播源指定流播放状态通知
  
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
  @brief    获取点播信息应答
  
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
  @brief    指定流停止点播通知
  
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
  @brief    码流参数通知
  
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
  @brief    丢包通知
  
   MainBuf(#BOOL32, bIsLostPack)

  @verbatim
	{
	    "basetype":true
	}
  @endverbatim
*/
	Ev_MtApi_Vc_CodecLostPack_Ntf,

/**
  @brief    Ev_MT_CodecVidCapDevList_Ntf (仅Win32)	
  
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
  @brief    获取当前视频采集设备命令 (仅WIN32)	
  
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
  @brief   哑音状态通知
  
   MainBuf(#BOOL32, bMicMute)

  @verbatim
	{
		"basetype": true
	}
  @endverbatim
*/
	Ev_MtApi_Vc_CodecMute_Ntf,

/**     
  @brief   静音状态通知
  
   MainBuf(#BOOL32, bQuiet)

  @verbatim
	{
		"basetype": true
	}
  @endverbatim
*/
	Ev_MtApi_Vc_CodecQuiet_Ntf,


/**
  @brief    音频输入设备列表通知(仅win32)
  
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
  @brief    音频输出设备列表通知(仅win32)	
  
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
  @brief    获取当前的音频输入设备通知(仅WIN32)
  
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
  @brief  获取当前的音频输出设备通知
  
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
  @brief    获取音频输出音量响应（仅windows平台)
  
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
  @brief   拍摄快照响应		
  
   MainBuf(#u32, dwResult) // 快照拍摄状态 0：成功 1：其他人正在拍照 2：磁盘空间不足 3:采集不到图像 4: 对端无码流 5:上传到ftp服务器失败\n
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
  @brief   查询最近拍摄文件响应		
  
   MainBuf(#u32, dwResult) //查询状态结果 0：成功 1：失败 \n
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
  @brief   拍摄ftp快照通知		
  
  
   MainBuf(#s32, dwCodecType) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponent \n
   MainBuf(#s32, dwCodecIdx) //拍哪一路的快照。枚举值统一使用mt::TS32来传输，该处实际为mt::EmCodecComponentIndex \n
   MainBuf(#BOOL32, bResult) //是否拍摄成功 

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
  @brief   新生成快照上报 
  
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
  @brief    查询快照文件列表信息响应  
  
	////一条消息上报不完文件列表时携带消息序列号chSeq （序列号从1开始计数），当收到最后一条消息时携带-1。只上报一条消息时携带0。 \n
   MainBuf(#s8, chSeq)//消息序列号 \n
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
  @brief    删除一张快照响应  	
  
   
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
  @brief    一张快照被删除上报   
  
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
	@brief 删除所有快照文件响应
	
	MainBuf(#BOOL32 , pbResult)	

	@verbatim
	{
		 "bResult": true,
	}
	@endverbatim
*/
	Ev_MtApi_Vc_CodecSnapshotDelAllFile_Rsp, 

/**
  @brief    所有快照文件清空通知	
  @verbatim
  @endverbatim
*/
	Ev_MtApi_Vc_CodecSnapshotDelAllFile_Ntf, 

/**
  @brief    导出一张快照文件响应	
  
  
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
  @brief    导出所有快照文件响应	
  
   MainBuf(#EmFileCopyErr_Api , emResult)	
  @verbatim
  {
      "emResult": 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_CodecSnapshotExportAllFile_Rsp,

/**
  @brief    导出快照进度
  
  MainBuf(#u32)	
  @verbatim
  {
      "basetype": 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_CodecSnapshotExportProgress_Ntf,

/**
  @brief    摄像头升级通知

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
  @brief    摄像头版本信息回应
   
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
  @brief    虚拟遥控器按键通知，如web上模拟遥控器
  
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
  @brief    TL媒体事件通知
  
   MainBuf(#s32, nEvent)

  @verbatim
	{
	    "basetype": 1
	}
  @endverbatim
*/
	Ev_MtApi_Vc_CodecEvent_Ntf,
	
/**
  @brief    TL音频输入插拔事件通知
  
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
  @brief    视频采集设备变化通知
  
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
  @brief    设置多画面风格响应
  
  MainBuf(#u32, dwPIPModem)
  @verbatim
  {
      "basetype": 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_CodecSetPIP_Rsp,

/**
  @brief    设置多画面风格响应
  
  MainBuf(#u32, dwPIPModem)
  @verbatim
  {
      "basetype": 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_CodecQueryPIP_Rsp,

/**
  @brief    多画面风格状态通知
  
  MainBuf(#u32, dwPIPModem)
  @verbatim
  {
      "basetype": 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_CodecPIPState_Ntf,


/**
  @brief    保存快照结果通知 仅TL	
  
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
  @brief    数字mic升级	
  
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
  @brief    数字mic版本查询回复	
  
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
  @brief    无线mic升级回复
  
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
  @brief    无线mic版本查询回复
  
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
  @brief    录像磁盘空间告警通知
  
  MainBuf(#u32, dwDiskSpace)   u32表示告警的磁盘剩余空间，仅windows
  @verbatim
  {
       "basetype" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_CodecRecDiskAlarm_Ntf,


	/**
  @brief   本地视频源选看通知
  
  MainBuf(#EmCameraView_Api, emCodecIdx)   
  @verbatim
  { 
       "basetype" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_CodecSelectLocalVideoView_Ntf,

		/**
  @brief   本地视频源选看内容查询响应
  
  MainBuf(#EmCameraView_Api, emCodecIdx)   
  @verbatim
  { 
       "basetype" : 0
  }
  @endverbatim
*/

	Ev_MtApi_Vc_CodecGetLocalVideoView_Rsp,
	

/**
  @brief    开始视频采集失败通知  仅windows
  @verbatim
  @endverbatim
*/
	Ev_MtApi_Vc_CodecStartVidCapFailed_Ntf,

/**
  @brief    摄像头能力类型查询响应
  
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
  @brief    硬终端支持的摄像头类型	
  
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
  @brief    FXO呼叫到来	
  
  MainBuf(#s8*, pchAlias) 对端别名
  @verbatim
  {
       "basetype": "str"
  }
  @endverbatim
*/
	Ev_MtApi_FxoCallIncoming_Ntf,

/**
  @brief   FXO 呼叫状态
  
  MainBuf(#TFxoState_Api, tMtFxoState)
  @verbatim
  {
       "emState": 0
  }
  @endverbatim
*/
	Ev_MtApi_FxoCallLinkState_Ntf,

/**
  @brief   FXO 呼叫状态
  
  MainBuf(#s8*)
  @verbatim
  {
       "basetype": ""
  }
  @endverbatim
*/
	Ev_MtApi_FxoMakeCall_Ntf,

/**
  @brief    获取摄像头参数响应，仅windows
  
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
  @brief    获取默认摄像头参数响应，仅windows
  
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
	@brief 摄像头预置位操作响应

	MainBuf(#EmCodecComponentIndex_Api, vid_idx)//主流视频源索引 \n
	MainBuf(#BOOL32, bType)//TRUE表示调用 FALSE表示保存 n
    MainBuf(#u8, byIndex)//当前操作的预置位索引

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
  @brief    获取预置位图片响应
  
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
  @brief    电话退会后， 通知到界面， 界面决定是否重呼-- add by zwf
  
  MainBuf(#s8*, pchDialNum)
  @verbatim
  {
      "basetype" : "str"
  }
  @endverbatim
*/
    Ev_MtApi_Vc_IsRecallDial_Ntf,

/**
  @brief    设置电话退会后重呼通知-- add by zwf	
  
  MainBuf(#BOOL32, bRecall)
  @verbatim
  {
       "basetype" : true
  }
  @endverbatim
*/  
    Ev_MtApi_Vc_SetRecallDial_Ntf,

/**
  @brief    重呼选择结果通知	
  
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
  @brief    会议轮询状态，仅windows,mcc客户端
  
   MainBuf(#BOOL32, bPollBroadCast)
  @verbatim
   {
       "basetype" : true
   }
  @endverbatim
*/
	Ev_MtApi_McPollBroadCast_Ntf,

/**
  @brief  空闲云端录像状态通知
  
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
  @brief  空闲云端录像状态通知
  
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
  @brief   设置摄像头操作本地还是远端
  
  MainBuf(#EmSite_Api, emSite)
  @verbatim
  {
  "basetype": 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_SetCamCtrlSite_Ntf,

	/**
  @brief   当前码流对应预置位回复
  
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
  @brief   注册授权认证
  
  MainBuf(#BOOL32, bAuth)
  @verbatim
  {
     "basetype" : true
  }
  @endverbatim
*/
	Ev_MtApi_Vc_RegAuthResult_Ntf,

/**
  @brief   对端当前的视频源，仅点对点    非标
  
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
  @brief   对端当前的视频源，仅点对点   非标
  
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
  @brief   获取当前正在轮询的终端
  
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
  @brief   本地铃声、按键音、音效播放状态提示
  
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
  @brief   本地铃声、按键音效、动画音效播放查询响应(按键音效和动画音效由于是个短操作，暂时不提供查询)
  
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
  @brief   开启监控图片拍摄功能通知
  
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
  @brief   查询监控图片拍摄功能响应
  
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
  @brief 快照文件重命名响应
  
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
  @brief 快照文件重命名通知

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
  @brief 停止导出所有快照文件的通知
  @verbatim
  @endverbatim
*/
	Ev_MtApi_Vc_CodecStopExportAllSnapshotFiles_Ntf,

	/**
  @brief 发言人视频源列表索引
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
  @brief 对端预置位列表
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
  @brief 发言人视频源列表索引
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
  @brief Fxo呼叫错误码上报
  MainBuf(#u32)
  @verbatim
  {
	 "basetype" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_FxoCallErrorCode_Ntf,

/**
  @brief vrs操作超时错误码上报
  MainBuf(#u32)
  @verbatim
  {
	 "basetype" : 0
  }
  @endverbatim
*/
	Ev_MtApi_Vc_VodGetListTimeOut_Ntf,

    /**
	@brief 开启或关闭OSD快照通知
	
	MainBuf(#BOOL32 , pbResult)	

	@verbatim
	{
		 "bResult": true,
	}
	@endverbatim
*/
	Ev_MtApi_Vc_CodecOsdSnapShotOpen_Ntf, 

	/**
  @brief    请求预约直播室列表回应
  
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
	@brief 开启或关闭Osd 通知
	
	MainBuf(#BOOL32 , bShow)	

	@verbatim
	{
		 "bShow": true,
	}
	@endverbatim
*/
	Ev_MtApi_Vc_CodecIsShowOsd_Ntf,

/**
	@brief 音频通道所有参数通知,用于IPW
	
	MainBuf(#s32, nCompType)  编码或解码	
	MainBuf(#s32, nCompIndex) 第几路
	MainBuf(#TNetAddr_Api, tLocalRtp)
	MainBuf(#TNetAddr_Api, tLocalRtcp)
	MainBuf(#TNetAddr_Api, tPeerRtp)
	MainBuf(#TNetAddr_Api, tPeerRtcp)
	MainBuf(#TAudEncParam_Api, tAudEncParam)
	MainBuf(#BOOL32,bG7221Reverse)   如果音频不为G7221，就不用关心这个字段的值
	MainBuf(#TDynamicPayload_Api, tPayload)
	MainBuf(#TEncryptKey_Api, tEncryptKey)

	@verbatim
	{
		 
	}
	@endverbatim
*/
	Ev_MtApi_Vc_AudEncChanParam_Ntf,

/**
	@brief 视频通道所有参数通知,用于IPW
	
	MainBuf(#s32, nCompType)	编码或解码
	MainBuf(#s32, nCompIndex)	第几路
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
	@brief 是否需要nat穿越的通知,用于IPW
	
	MainBuf(#s32, nCompType)	编码或解码
	MainBuf(#s32, nCompIndex)	第几路
	MainBuf(#BOOL32, bEnable)   是否启用穿越
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
	@brief 开始编码的通知,用于IPW

	MainBuf(#s32, nCompType)	编码或解码
	MainBuf(#s32, nCompIndex)	第几路
	
	@verbatim
	{
		
	}
	@endverbatim
*/
	Ev_MtApi_Vc_StartEnc_Ntf,

/**
	@brief 停止编码的通知,用于IPW

	MainBuf(#s32, nCompType)	编码或解码
	MainBuf(#s32, nCompIndex)	第几路

	@verbatim
	{
		
	}
	@endverbatim
*/
	Ev_MtApi_Vc_StopEnc_Ntf,

/**
	@brief mcu调整编码分辨率,用于IPW

	MainBuf(#s32, nCompType)	编码
	MainBuf(#s32, nCompIndex)	第几路
	MainBuf(#u16, wWidth)	    宽度
	MainBuf(#u16, wHeight)	    高度

	@verbatim
	{
		
	}
	@endverbatim
*/
	Ev_MtApi_Vc_SetEncRes_Ntf,

/**
	@brief mcu调整编码帧率,用于IPW

	MainBuf(#s32, nCompType)	编码
	MainBuf(#s32, nCompIndex)	第几路
	MainBuf(#u8,  byFps)	    帧率

	@verbatim
	{
		
	}
	@endverbatim
*/
	Ev_MtApi_Vc_SetEncFps_Ntf,

/**
	@brief 对端调整编码码率,用于IPW

	MainBuf(#s32, nCompType)	编码
	MainBuf(#s32, nCompIndex)	第几路
	MainBuf(#u16, wBitrate)	    编码码率

	@verbatim
	{
		
	}
	@endverbatim
*/
	Ev_MtApi_Vc_SetEncBitrate_Ntf,

/**
	@brief 对端请求发送关键帧,用于IPW

	MainBuf(#s32, nCompType)	编码
	MainBuf(#s32, nCompIndex)	第几路

	@verbatim
	{
		
	}
	@endverbatim
*/
	Ev_MtApi_Vc_FastUpdate_Ntf,

/**
	@brief 硬终端开始本地录像回复

	MainBuf(#BOOL32 , bSuccess)	
	@verbatim
	{
		
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_StartLocalRec_Ntf,

/**
	@brief 硬终端停止本地录像回复

	MainBuf(#BOOL32 , bSuccess)	
	@verbatim
	{
		
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_StopLocalRec_Ntf,

/**
	@brief 硬终端暂停本地录像回复

	MainBuf(#BOOL32 , bSuccess)	
	@verbatim
	{
		
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_PauseLocalRec_Ntf,

/**
	@brief 硬终端继续本地录像回复

	MainBuf(#BOOL32 , bSuccess)	
	@verbatim
	{
		
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_ContinueLocalRec_Ntf,

/**
	@brief 硬终端本地录像剩余时间通知，秒

	MainBuf(#u32 , dwRemainTime) 	
	@verbatim
	{
		
	}
	@endverbatim
*/ 


	Ev_MtApi_Vc_RemainTimeLocalRec_Ntf,


/**
	@brief 硬终端本地录像过程中状态上报

	MainBuf(#EmVideoRecordErrorNum_Api, emErrcode)	
	@verbatim
	{
		
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_LocalRecStatus_Ntf,

/**
	@brief 获取本地录像状态的回复(是否在录像)

	MainBuf(#EmVideoRecordStatus_Api , emRecStatus)	
	@verbatim
	{
		
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_StartLocalRec_Rsp,

/**
	@brief 获取本地开始录像时间的通知

	MainBuf(#TMTTime_Api, tStartTime)	
	@verbatim
	{
		
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_LocalRecStartTime_Ntf,

/**
	@brief 图片获取相应


	MainBuf(#BOOL32, result)	
	@verbatim
	{
		result:0
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_CodecPicGet_Rsp,


/**
	@brief 获取哑音状态的响应

	MainBuf(#BOOL32, result)	
	@verbatim
	{
		result:0
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_CodecGetMute_Rsp,

/**
	@brief 获取静音状态的响应

	MainBuf(#BOOL32, result)	
	@verbatim
	{
		result:0
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_CodecGetQuiet_Rsp,

/**
	@brief 获取获取摄像头控制是远端，还是本地的响应

	MainBuf(#EmSite_Api, emSite)	
	@verbatim
	{
		emSite:0
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_GetCameraCtrlSiteRt_Rsp,

/**
	@brief 获取加密属性的响应

	MainBuf(#EmSrtpCryptoType_Api, emEncryType)	
	@verbatim
	{
		emEncryType: 0
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_GetEncryptType_Rsp,

	/**	
	@brief    TL界面需要登陆vrs后返回的token值
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
	@brief 会议空闲双流状态通知

	MainBuf(#s32)	
	@verbatim
	{
		nCompType: 1   //编码或解码第几路，注意：nCompType=20 表示双流停止
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_MtStreamStatusRt_Ntf,

	/**	
	@brief    通知上层编码参数, 暂时用在ipc
		
	MainBuf(#TMTStreamChanParam_Api, tParam)
	MainBuf(#EmCodecComponent_Api, emCodecType)
	MainBuf(#EmCodecComponentIndex_Api, emCodecIndex)

	@verbatim
	{	
		"tParam"：{
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
	@brief    通知上层开始编码, 暂时用在ipc
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
	@brief    通知上层停止编码, 暂时用在ipc
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
	@brief    通知上层设置码率, 暂时用在ipc
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
	@brief    通知上层对端调整分辨率, 暂时用在ipc
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
	@brief    通知上层对端调整帧率, 暂时用在ipc
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
	@brief    通知上层对端请求关键帧, 暂时用在ipc
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
	  @brief    收到UI 当前呼叫的calllid，用于白板会议	
  
	  MainBuf(#s8*, pchCallId)
	  @verbatim
	  {
		  "basetype" : "str"
	  }
	  @endverbatim
	*/
	Ev_MtApi_Vc_Callid_Rsp,

	/**
	@brief osd来打开/关闭pc双流通知


	MainBuf(#BOOL32, bOpen)	
	@verbatim
	{
		bOpen:0
	}
	@endverbatim
	*/ 
	Ev_MtApi_Vc_OsdCtrlPcAssStream_Ntf,

	/**
	@brief 摄像机方位调节错误类型通知

	MainBuf(#u8, byVidIdx )
	SubBuf(#EmCameraPantiltErrType_Api, emType )	
	@verbatim
	{
		
	}
	@endverbatim
	*/ 
	Ev_MtApi_Vc_DeviceCameraPantiltErr_Ntf,

	/**
	@brief    实体遥控器按键通知
  
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
	@brief 获取是否关闭主流响应

	MainBuf(#BOOL32, bVidoff)	
	@verbatim
	{
		bVidoff: 0
	}
	@endverbatim
*/ 
	Ev_MtApi_Vc_GetCloseMainVid_Rsp,

	/**
	@brief 查询摄像头是否正在升级的响应
	
	MainBuf(#BOOL32 , pbResult)	

	@verbatim
	{
		 "bResult": true,
	}
	@endverbatim
*/
	Ev_MtApi_CodecGetIsCameraUpgrading_Rsp,

	/**
    @brief 对端不是量通的通知
    @verbatim
    @endverbatim
   */
	Ev_MtApi_Vc_PeerNotQt_Ntf,

	/**
	@brief 会议加密类型的通知

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
