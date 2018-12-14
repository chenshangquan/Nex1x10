/*******************************************************************************//**
*@file          mtapi_event_im.h
*@brief         实现MTAPI MtIMSdk 给UI(观察者)事件通知的定义
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_EVENT_IM_H_
#define _MTAPI_EVENT_IM_H_
/**@addtogroup event 事件
*@{
*/

/**@addtogroup imevent 聊天事件
*@{
*/

#include "mtapi_event_def.h"


enum EmMtApiIMEv
{
	EV_UI_BGN(MTAPI_IM)  = EVSEG_MTAPI_IM_BGN,

	//im相关
/**
  @brief    请求登录XMPP服务器应答
  
	MainBuf(#TImComm_Api) 
	Json格式如下：

	@verbatim
	{
		"dwErrID": 0,
		"dwHandle": 0,
		"dwReserved": 0
	}
  @endverbatim
*/
	Ev_MtApi_ImLogin_Rsp,

	
/**
  @brief   请求查询自己的自定义信息应答
  
	MainBuf(#TImComm_Api)\n
    SubBuf(#TImSelfDef_Api)
 
	Json格式如下：

	@verbatim
	{
		"MainParam":
	    {
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam":
	    {
			"tImSelfDefInfo_Api": 
	        {
				"achNO": "str",
				"achNickName": "str",
				"wPictureIndex": 0,
				"bCustomePic": true
			},
			"tImSelfDefPic_Api": 
	        {
				"dwCustomPicSize": 0,
				"abyCustomPicData": "str"
			}
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImQuerySelfDefInfo_Rsp,

	/**
  @brief   请求查询聊天室服务是否可用应答
  
 
	Json格式如下：

	@verbatim
	{
		"bAvailable":false,
	}
  @endverbatim
*/	
	Ev_MtApi_ImGetChatRoomServiceAvailable_Rsp,

/**
  @brief    请求修改自己的自定义信息应答	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImSelfDef_Api)
	 Json格式如下：

	@verbatim
	{
		"MainParam":
	    {
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam":
	    {
			"tImSelfDefInfo_Api": 
	        {
				"achNO": "str",
				"achNickName": "str",
				"wPictureIndex": 0,
				"bCustomePic": true
			},
			"tImSelfDefPic_Api": 
	        {
				"dwCustomPicSize": 0,
				"abyCustomPicData": "str"
			}
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImModiySelfDefInfo_Rsp,

/**
  @brief    请求修改自己的自定义信息应答	
  
	成功\n
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImSelfDefInfo_Api)
	Json格式如下：

	@verbatim
	{
		"MainParam": 
	    {
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
	     {
			"achNO": "str",
			"achNickName": "str",
			"wPictureIndex": 0,
			"bCustomePic": true
		 }
	}
	@endverbatim
	
	失败\n
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImNOList_Api) 
	
	@verbatim
	{
		"MainParam": 
	    {
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
	    {
			"atArray": 
	        [
				{
					"achNO": "str"
				}
			]
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImQuerySpecifiedUserDefInfo_Rsp,


/**
  @brief    请求查询组信息应答	
  
	MainBuf(#TImComm_Api) 
	Json格式如下：

	@verbatim
	{
		"dwErrID": 0,
		"dwHandle": 0,
		"dwReserved": 0
	}
  @endverbatim
*/	
	Ev_MtApi_ImQueryGroupInfo_Error_Rsp,

/**
  @brief    请求查询组信息应答	
  
	MainBuf(#u32)\n
	SubBuf(#TImGroupList_Api)\n
	Json格式如下：

	@verbatim
	{
		"MainParam": 
	     {
			"dwHandle": 0,
		 },
	    "AssParam": 
		 {
			 "atArray": 
	         [
				{
				    "achGroupSn": "str",
					"achGroupName": "str",
					"achParentGroupSn": "str",
					"wGroupLevel": 0
				}
		 ]
	     }
	}
  @endverbatim
*/	
    Ev_MtApi_ImQueryGroupInfo_Rsp,

/**
  @brief    请求查询组信息应答结束
  
	MainBuf(#u32) \n
	Json格式如下：

	@verbatim
	{
        "basetype": 0
	}
  @endverbatim
*/	
    Ev_MtApi_ImQueryGroupInfo_Fin_Rsp,

/**
  @brief    请求查询某组的子组信息应答	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImSn_Api)\n
	Json格式如下：

	@verbatim
	{
		"MainParam": 
	    {
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
	    {
			"achSn": "str"
		}
	}
  @endverbatim
*/	
    Ev_MtApi_ImQuerySubGroupInfoByGroupSn_Error_Rsp,

/**
  @brief    请求查询某组的子组信息应答
  
	MainBuf(#u32)\n
	SubBuf(#TImGroupList_Api)\n
	Json格式如下：

	@verbatim
	{
		"MainParam":
	    {
			"dwHandle": 0,
		},
		"AssParam": 
	     {
			    "atArray":
	            [
				    {
					"achGroupSn": "str",
					"achGroupName": "str",
					"achParentGroupSn": "str",
					"wGroupLevel": 0
				    }
			    ]
	      }
	}
  @endverbatim
*/	
    Ev_MtApi_ImQuerySubGroupInfoByGroupSn_Rsp,

/**
  @brief    查询子组信息成功后的分包信息	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImSn_Api)\n
	Json格式如下：

	@verbatim
	{
		"MainParam":
	    {
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
	     {
		   "achSn": "str"
		 }
	}
  @endverbatim
*/	
    Ev_MtApi_ImQuerySubGroupInfoByGroupSn_Fin_Rsp,

/**
  @brief    创建组信息应答
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImGroupInfo_Api)\n
	Json格式如下：

	@verbatim
	{
		"MainParam":
	    {
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
	     {
			"achGroupSn" : "",                   
			"achGroupName" : "",                 
			"achParentGroupSn" : "",             
			"wGroupLevel" : 0                                          
		 }
	}
  @endverbatim
*/	
	Ev_MtApi_ImAddGroupInfo_Rsp,

/**
  @brief    删除组信息应答	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImSn_Api)\n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"achSn": "str"
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImDelGroupInfo_Rsp,

/**
  @brief    修改组信息应答	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImGroupInfo_Api)\n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"achGroupSn" : "",                   
			"achGroupName" : "",                 
			"achParentGroupSn" : "",             
			"wGroupLevel" : 0                                          
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImModifyGroupInfo_Rsp,

/**
  @brief    根据组号查询成员信息应答
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImSn_Api)\n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
			}
		},
		"AssParam": 
		{
			"achSn": "str"
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImQueryMemberInfoByGroupSn_Error_Rsp,

/**
  @brief    根据组号查询成员信息应答
  
	MainBuf(#u32)\n
	SubBuf(#TImMemberList_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle": 0
		},
		"AssParam":
		{
				"dwArraySize": 0,
				"atArray": 
				[
				  {
					"achMemberSn": "",
					"achGroupSn": "",
					"achMemberNO": "",
					"achMarkName": "",
					"emMemberType": 0,
					"wBitRate": 0,
					"tWeiboInfo": 
					{
						"achMoId": "",
						"achCompanyMoId": "",
						"achcn": "",
						"achsn": "",
						"achentMail": "",
						"achEntName": "",
						"achEntRealName": "",
						"ache164": "",
						"achjid": "",
						"achmobileNum": "",
						"achextNum": "",
						"achbrief": "",
						"achposition": "",
						"achportrait40": "",
						"achportrait64": "",
						"achportrait128": "",
						"achxmpppwd": "",
						"achseat": "",
						"bEnableWeibo": 0,
						"bEnableMeeting": 0,
						"bEnableHD": 0,
						"bEnableCall": 0,
						"bEnableRoam": 0,
						"bEnableSatellite": 0,
						"bEnableSatelliteP2P": 0,
						"bMale": 0,
						"tMtWbParseKedaDepts": 
						{
							"dwDeptNum": 0,
							"atMtWbParseKedaDept":
							[
							  {
								"dwDepartmentId": 0,
								"achDepartmentName": ""
							  }
							]
						}
					},
					"bNoQuery": 0
				 }
			]
		}
	}
  @endverbatim
*/	
    Ev_MtApi_ImQueryMemberInfoByGroupSn_Rsp,

/**
  @brief    查询某组下的联系人列表信息分包信息结果通知	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImSn_Api)\n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
	    },
		"AssParam": 
		{
			"achSn": "str"
		}
	}
  @endverbatim
*/	
    Ev_MtApi_ImQueryMemberInfoByGroupSn_Fin_Rsp,

/**
  @brief    添加好友应答
  
	成功\n
	 MainBuf(#TImComm_Api)\n
	 SubBuf(#TImMemberFullInfo_Api)

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam":
		{
				"achMemberSn": "",
				"achGroupSn": "",
				"achMemberNO": "",
				"achMarkName": "",
				"emMemberType": 0,
				"wBitRate": 0,
				"tWeiboInfo": 
				{
					"achMoId": "",
					"achCompanyMoId": "",
					"achcn": "",
					"achsn": "",
					"achentMail": "",
					"achEntName": "",
					"achEntRealName": "",
					"ache164": "",
					"achjid": "",
					"achmobileNum": "",
					"achextNum": "",
					"achbrief": "",
					"achposition": "",
					"achportrait40": "",
					"achportrait64": "",
					"achportrait128": "",
					"achxmpppwd": "",
					"achseat": "",
					"bEnableWeibo": 0,
					"bEnableMeeting": 0,
					"bEnableHD": 0,
					"bEnableCall": 0,
					"bEnableRoam": 0,
					"bEnableSatellite": 0,
					"bEnableSatelliteP2P": 0,
					"bMale": 0,
					"bLimited": 0,
					"tMtWbParseKedaDepts": 
					{
						"dwDeptNum": 0,
						"atMtWbParseKedaDept": 
						[
						  {
							"dwDepartmentId": 0,
							"achDepartmentName": ""
						  }
						]
					},
					"bNoQuery": 0
				},
			   "emMemberState": 0,
			   "bMaxAudio": 0,
			   "bMaxVideo": 0,
			   "atMtState": 
			   {
			     "eMtType": 0,
				 "eMtState": 0,
				 "bAudioCapability": 0,
				 "bVideoCapability": 0,
				 "bGkConnected": 0
			   }
		     }
	}
	@endverbatim
	
	失败\n
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImMemberInfo_Api) \n
	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam":
		{
			"achMemberSn": "",
			"achGroupSn": "",
			"achMemberNO": "",
			"achMarkName": "",
			"emMemberType": 0,
			"wBitRate": 0,
			"tWeiboInfo": 
			{
				"achMoId": "",
				"achCompanyMoId": "",
				"achcn": "",
				"achsn": "",
				"achentMail": "",
				"achEntName": "",
				"achEntRealName": "",
				"ache164": "",
				"achjid": "",
				"achmobileNum": "",
				"achextNum": "",
				"achbrief": "",
				"achposition": "",
				"achportrait40": "",
				"achportrait64": "",
				"achportrait128": "",
				"achxmpppwd": "",
				"achseat": "",
				"bEnableWeibo": 0,
				"bEnableMeeting": 0,
				"bEnableHD": 0,
				"bEnableCall": 0,
				"bEnableRoam": 0,
				"bEnableSatellite": 0,
				"bEnableSatelliteP2P": 0,
				"bMale": 0,
				"bLimited": 0,
				"tMtWbParseKedaDepts": 
				{
					"dwDeptNum": 0,
					"atMtWbParseKedaDept":
					[ 
					  {
						"dwDepartmentId": 0,
						"achDepartmentName": ""
					  }
					]
				}
			},
			"bNoQuery": 0
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImAddMemberInfo_Rsp,

/**
  @brief    查询添加好友信息应答	
  
	MainBuf(#TRestErrorInfo_Api)\n
	SubBuf(#TMTSearchUserInfo_Api) \n
	Json格式如下：
	@verbatim
	{
		"MainParam":
		{
			"achErrorInfo": "",
			"emApiType": 0,
			"dwErrorID": 0,
			"dwNackEventId": 0,
			"adwParams": 
			[
				0,
				0
			]
		},
		"AssParam": 
		{
			"emOperateUser": 0,
			"dwXmppNo": 0,
			"tImMemberInfo": 
			{
				"achMemberSn": "",
				"achGroupSn": "",
				"achMemberNO": "",
				"achMarkName": "",
				"emMemberType": 0,
				"wBitRate": 0,
				"tWeiboInfo": 
				{
					"achMoId": "",
					"achCompanyMoId": "",
					"achcn": "",
					"achsn": "",
					"achentMail": "",
					"achEntName": "",
					"achEntRealName": "",
					"ache164": "",
					"achjid": "",
					"achmobileNum": "",
					"achextNum": "",
					"achbrief": "",
					"achposition": "",
					"achportrait40": "",
					"achportrait64": "",
					"achportrait128": "",
					"achxmpppwd": "",
					"achseat": "",
					"bEnableWeibo": 0,
					"bEnableMeeting": 0,
					"bEnableHD": 0,
					"bEnableCall": 0,
					"bEnableRoam": 0,
					"bEnableSatellite": 0,
					"bEnableSatelliteP2P": 0,
					"bMale": 0,
					"bLimited": 0,
					"tMtWbParseKedaDepts":
					{
						"dwDeptNum": 0,
						"atMtWbParseKedaDept": 
						 [
						   {
							  "dwDepartmentId": 0,
							  "achDepartmentName": ""
							}
						]
					},
					"bNoQuery": 0
				}
			}
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImQueryAddMemberInfo_Rsp,

/**
  @brief    复制好友应答
  
	成功
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImMemberFullInfo_Api)\n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam":
		{
			"tMemberinfo": 
			{
				"achMemberSn": "",
				"achGroupSn": "",
				"achMemberNO": "",
				"achMarkName": "",
				"emMemberType": 0,
				"wBitRate": 0,
				"tWeiboInfo": 
				{
					"achMoId": "",
					"achCompanyMoId": "",
					"achcn": "",
					"achsn": "",
					"achentMail": "",
					"achEntName": "",
					"achEntRealName": "",
					"ache164": "",
					"achjid": "",
					"achmobileNum": "",
					"achextNum": "",
					"achbrief": "",
					"achposition": "",
					"achportrait40": "",
					"achportrait64": "",
					"achportrait128": "",
					"achxmpppwd": "",
					"achseat": "",
					"bEnableWeibo": 0,
					"bEnableMeeting": 0,
					"bEnableHD": 0,
					"bEnableCall": 0,
					"bEnableRoam": 0,
					"bEnableSatellite": 0,
					"bEnableSatelliteP2P": 0,
					"bMale": 0,
					"bLimited": 0,
					"tMtWbParseKedaDepts": 
					{
						"dwDeptNum": 0,
						"atMtWbParseKedaDept": 
						[  
						  {
							"dwDepartmentId": 0,
							"achDepartmentName": ""
						  }
						]
					},
					"bNoQuery": 0
				}
			},
			"emMemberState": 0,
			"bMaxAudio": 0,
			"bMaxVideo": 0,
			"atMtState": 
			{
				"eMtType": 0,
				"eMtState": 0,
				"bAudioCapability": 0,
				"bVideoCapability": 0,
				"bGkConnected": 0
			}
		}
	}
	@endverbatim
	
	 失败\n
	 MainBuf(#TImComm_Api)\n
	 SubBuf(#TImMemberInfo_Api) \n
	 
	 @verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam":
		{
			"achMemberSn": "",
			"achGroupSn": "",
			"achMemberNO": "",
			"achMarkName": "",
			"emMemberType": 0,
			"wBitRate": 0,
			"tWeiboInfo": 
			{
				"achMoId": "",
				"achCompanyMoId": "",
				"achcn": "",
				"achsn": "",
				"achentMail": "",
				"achEntName": "",
				"achEntRealName": "",
				"ache164": "",
				"achjid": "",
				"achmobileNum": "",
				"achextNum": "",
				"achbrief": "",
				"achposition": "",
				"achportrait40": "",
				"achportrait64": "",
				"achportrait128": "",
				"achxmpppwd": "",
				"achseat": "",
				"bEnableWeibo": 0,
				"bEnableMeeting": 0,
				"bEnableHD": 0,
				"bEnableCall": 0,
				"bEnableRoam": 0,
				"bEnableSatellite": 0,
				"bEnableSatelliteP2P": 0,
				"bMale": 0,
				"bLimited": 0,
				"tMtWbParseKedaDepts": 
				{
					"dwDeptNum": 0,
					"atMtWbParseKedaDept": 
					[
					  {
						"dwDepartmentId": 0,
						"achDepartmentName": ""
					  }
					]
				}
			},
			"bNoQuery": 0
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImCopyMember_Rsp,

/**
  @brief    删除好友应答	
  
	MainBuf(#TImComm_Api)\n
    SubBuf(#TImSn_Api) \n
	Json格式如下：\n

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"achSn": "str"
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImDelMemberInfo_Rsp,

/**
  @brief    修改好友应答
  
	MainBuf(#TImComm_Api)\n
	 SubBuf(#TImMemberInfo_Api) \n
	*Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"achMemberSn": "",
			"achGroupSn": "",
			"achMemberNO": "",
			"achMarkName": "",
			"emMemberType": 0,
			"wBitRate": 0,
			"tWeiboInfo": 
			{
				"achMoId": "",
				"achCompanyMoId": "",
				"achcn": "",
				"achsn": "",
				"achentMail": "",
				"achEntName": "",
				"achEntRealName": "",
				"ache164": "",
				"achjid": "",
				"achmobileNum": "",
				"achextNum": "",
				"achbrief": "",
				"achposition": "",
				"achportrait40": "",
				"achportrait64": "",
				"achportrait128": "",
				"achxmpppwd": "",
				"achseat": "",
				"bEnableWeibo": 0,
				"bEnableMeeting": 0,
				"bEnableHD": 0,
				"bEnableCall": 0,
				"bEnableRoam": 0,
				"bEnableSatellite": 0,
				"bEnableSatelliteP2P": 0,
				"bMale": 0,
				"bLimited": 0,
				"tMtWbParseKedaDepts": 
				{
					"dwDeptNum": 0,
					"atMtWbParseKedaDept":
					[
					  {
						"dwDepartmentId": 0,
						"achDepartmentName": ""
					  }
					]
				},
				"bNoQuery": 0
			}
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImModifyMemberInfo_Rsp,

/**
  @brief    移动好友应答
  
	MainBuf(#TImComm_Api)\n
	 SubBuf(#TImMoveMember_Api) \n
	*Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"achMemberSn" : "",               
			"achOldGroupSn" : "",             
			"achNewGroupSn" : ""             

		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImMoveMemberInfo_Rsp,

/**
  @brief    成员在线状态变更通知
  
	MainBuf(#u32)\n
	SubBuf(#TDeviceOnlineState_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam"：
		{
			"achNO" : "",	                       
			"emDeviceType" : 0,                    
			"emState" : 0,                            
			"emMaxState" : 0,                         
			"bSelf" : 0,                                          
			"bFirst" : 0,                                         
			"bFileShare" : 0,                                     
			"bAudioCapability" : 0,                               
			"bVideoCapability" : 0,                               
			"bGkConnected" : 0,                                   
			"bMaxAudio" : 0,                                      
			"bMaxVideo" : 0,                                      
			"bLoginBeforeMe" : 0  
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImMemberOnlineStateChange_Ntf,

/**
  @brief    根据组ID查询在线状态应答	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImSn_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
    		"achSn": "str"
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImQueryOnlineStateByGroupSn_Rsp,
	
/**
  @brief    根据组ID查询在线状态应答通知	
  
	MainBuf(#u32)\n
    SubBuf(#TImUserStateList_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam"：
		{
			"dwArraySize" : 0,
			"atArray" : 
			[
				{
					"achNO" : "",
					"emState" : 0
				}
			]
		}
	}
  @endverbatim
*/
	Ev_MtApi_ImQueryOnlineStateByGroupSn_Ntf,
	
/**
  @brief    根据组ID查询在线状态应答通知	
  
	MainBuf(#u32)\n
	SubBuf(#TImSn_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
			"achSn" : "" 
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImQueryOnlineStateByGroupSn_Fin_Ntf,

/**
  @brief   根据组ID查询在线状态扩展消息应答
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImSn_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
		    "achSn": "str"
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImQueryOnlineStateByGroupSnEx_Rsp,
	
/**
  @brief    根据组ID查询在线状态扩展消息应答通知	
  
	MainBuf(#u32)\n
	SubBuf(#TImUserStateListEx_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
			"dwArraySize" : 0,
			"atArray" : 
			[
				{
					"achNO" : "",	
					"tState" : 0,                       
					"bMaxAudio" : 0,                    
					"bMaxVideo" : 0,                    
					"atMtState" : 
					[
						{
							"eMtType" : 0,        
							"eMtState" : 0,       
							"bAudioCapability" : 0,  
							"bVideoCapability" : 0,  
							"bGkConnected" : 0    
			 			}
					] 
				}
			]
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImQueryOnlineStateByGroupSnEx_Ntf,

/**
  @brief    根据组ID查询在线状态扩展消息应答结束通知	
  
	MainBuf(#u32)\n
	SubBuf(#TImSn_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
			"achSn" : ""  
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImQueryOnlineStateByGroupSnEx_Fin_Ntf,

/**
  @brief    修改自己状态应答
  
	MainBuf(#TImComm_Api)\n
	 SubBuf(#TImSetUserState_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
	    {
		  "dwErrID": 0,
		  "dwHandle": 0,
		  "dwReserved": 0
	    },
		"AssParam": 
		{
			"achNO" : "",                        
			"emState" : 0,                            
			"bStateValid" : 0,                         
			"bGkConnected" : 0,                        
			"bGkConnectedValid" : 0                  
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImModifySelfState_Rsp,

/**
  @brief    发送点对点消息应答
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImP2PChatMessage_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
	     {
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		 },
		"AssParam": 
		{
			"achDstNO" : "",    
			"achSrcNO" : "",	  
			"emImMtType" : 0,     
			"dwContextId" : 0,                     
			"tMessageBuf" : 
			{
				"wMsgLen" : 0,
				"achMsgBody" : ""      
			}          
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImSendP2PMessage_Rsp,

/**
  @brief    发送点对点消息应答通知	
  
	MainBuf(#u32)\n
	SubBuf(#TImP2PChatMessage_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
			"achDstNO" : "",    
			"achSrcNO" : "",	  
			"emImMtType" : 0,     
			"dwContextId" : 0,                     
			"tMessageBuf" : 
			{
				"wMsgLen" : 0,
				"achMsgBody" : ""      
			}  
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImSendP2PMessage_Ntf,

/**
  @brief    发送点对点消息应答通知	
  
	MainBuf(#u32)\n
	SubBuf(#TImP2PChatMessage_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
			"achDstNO" : "",    
			"achSrcNO" : "",	  
			"emImMtType" : 0,     
			"dwContextId" : 0,                     
			"tMessageBuf" : 
			{
				"wMsgLen" : 0,
				"achMsgBody" : ""      
			}  
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImSendP2PMessageInstant_Rsp,

/**
  @brief    创建多人聊天应答
  
    MainBuf(#TImComm_Api) \n
	SubBuf(#TImMulitChatCreateInfo_Api)\n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"achChatName" : "",
			"achConfE164" : "",     
			"achRoomId" : "",  
			"achInviterNO" : "",        

			"dwSessionID" : 0,                              
			"dwClientID" : 0,                               

			"bPersistent" : 0,                          
			"bOwner" : 0,                               

			"emMultiChatType" : 0        
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImMulitChatCreate_Rsp,

/**
  @brief    创建多人聊天通知	
  
	MainBuf(#u32) \n
	SubBuf(#TImMultiChatCreateInfo_Api) \n
	*Json格式如下：

	@verbatim
	{
		"MainParam" :
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
			"achChatName" : "",
			"achConfE164" : "",     
			"achRoomId" : "",  
			"achInviterNO" : "",        
			"dwSessionID" : 0,                              
			"dwClientID" : 0,                               
			"bPersistent" : 0,                          
			"bOwner" : 0,                               
			"emMultiChatType" : 0 
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImMulitChatCreate_Ntf,

/**
  @brief    创建多人聊天通知	
  
	MainBuf(#tImComm_Api) \n
	SubBuf(#TRoomId_Api)  \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"achRoomId" : ""
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImMulitChatDestroy_Rsp,

/**
  @brief    销毁多人聊天通知	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TRoomId_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0

		},
		"AssParam": 
		{
			"achRoomId" : ""
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImMulitChatDestroy_Ntf,

/**
  @brief    多人聊天添加成员应答
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TImMultiChatMemberInfo_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
	     {
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		 },
		"AssParam": 
		{
			"dwSessionID" : 1,
			"tNOList" :
			{
				"dwArraySize" : 2,
				"atArray" :
				[ 
				     {  
						 "achNO" : " "
					 }
				]
			},
			"tRoomId" :
			{
				"achRoomId" : " "
			}
	    }
	}
  @endverbatim
*/	
	Ev_MtApi_ImMulitChatAddMember_Rsp,

/**
  @brief    多人聊天添加成员通知
  
	MainBuf(#u32) \n
	SubBuf(#TImMultiChatMemberInfoEx_Api) \n 
	Json格式如下：

	@verbatim
	{
		"MainParam" :
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
			"dwSessionID" : 0,
			 "achNO" : "",       
			 "bOwner" : 0,                          
			  "bSelf" : 0,                           
			  "emMtType" : 0,         
			  "emState" : 0,          
			  "emMaxState" : 0,       
			  "tRoomId" : 
			   {
			      "achRoomId" : ""
			   }
		}
	}
  @endverbatim
*/
	Ev_MtApi_ImMulitChatAddMember_Ntf,

/**
  @brief    多人聊天成员状态改变通知
  
	MainBuf(#u32)\n
	SubBuf(#TImMultiChatMemberInfoEx_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam" :
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
		    "dwSessionID" : 0,
		    "achNO" : "",       
		    "bOwner" : 0,                          
		    "bSelf" : 0,                           
		    "emMtType" : 0,         
		    "emState" : 0,          
		    "emMaxState" : 0,       
		    "tRoomId" : 
		    {
		       "achRoomId" : ""
		    }
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImMulitChatMemberStatusChange_Ntf,

/**
  @brief   多人聊天T人应答
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TImMultiChatMemberInfo_Api) \n

	Json格式如下：

	@verbatim
	{
		"MainParam":
	     {
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		 },
		"AssParam": 
		{
			"dwSessionID" : 1,
			"tNOList" :
			{
				"dwArraySize" : 0,
				"atArray" :
				[ 
				     {  
						 "achNO" : " "
					 }
				]
			},
			"tRoomId" :
			{
				"achRoomId" : " "
			}
	    }
	}
  @endverbatim
*/	
	Ev_MtApi_ImMulitChatDelMember_Rsp,

/**
  @brief    多人聊天T人通知	
  
	MainBuf(#u32)\n
	SubBuf(#TImMultiChatMemberInfoEx_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam" :
		{
			"dwHandle" : 0
		},
		"AssParam" :
		{
			"dwSessionID" : 0,
			"achNO" : "",       
			"bOwner" : 0,                          
			"bSelf" : 0,                           
			"emMtType" : 0,         
			"emState" : 0,          
			"emMaxState" : 0,       
			"tRoomId" : 
			{
				"achRoomId" : ""
			}
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImMulitChatDelMember_Ntf,

/**
  @brief    退出多人聊天应答
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TRoomId_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"achRoomId" : ""
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImMulitChatQuit_Rsp,

/**
  @brief    多人聊天成员离开通知
  
	MainBuf(#u32)\n
	SubBuf(#TImMultiChatMemberInfoEx_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
			"dwSessionID" : 0,
			"achNO" : "",       
			"bOwner" : 0,                          
			"bSelf" : 0,                           
			"emMtType" : 0,         
			"emState" : 0,          
			"emMaxState" : 0,       
			"tRoomId" : 
			{
				"achRoomId" : ""
			}
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImMulitChatMemberLeave_Ntf,

/**
  @brief    发送多点消息响应	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImMultiChatMessage_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam":
		{
			"dwSessionID" : 0,                      
			"dwContextId" : 0,               
			"achSrcNO" : "",    
			"emImMtType" : 0,     
			"tMessageBuf" : 
			{
				"wMsgLen" : 0,
				"achMsgBody" : ""      
			},           
			"tRoomId" : 
			{
				"achRoomId" : ""
			}              
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImSendMulitSMS_Rsp,

/**
  @brief   发送多点消息通知	
  
	MainBuf(#u32)\n
	SubBuf(#TImMultiChatMessage_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
			"dwSessionID" : 0,                      
			"dwContextId" : 0,               
			"achSrcNO" : "",    
			"emImMtType" : 0,     
			"tMessageBuf" : 
			{
				"wMsgLen" : 0,
				"abyMsgBody" : ""      
			},           
			"tRoomId" : 
			{
				"achRoomId" : ""
			}   
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImSendMulitSMS_Ntf,

/**
  @brief    发送多点消息应答
  
	MainBuf(#u32)\n
	SubBuf(#TImMultiChatMessage_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
			"dwSessionID" : 0,                      
			"dwContextId" : 0,               
			"achSrcNO" : "",    
			"emImMtType" : 0,     
			"tMessageBuf" : 
			{
				"wMsgLen" : 0,
				"abyMsgBody" : ""      
			},           
			"tRoomId" : 
			{
				"achRoomId" : ""
			}  
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImSendMulitSMSInstant_Rsp,

/**
  @brief    发送多点消息应答	
  
	MainBuf(#TImComm_Api) \n
	Json格式如下：

	@verbatim
	{
		"dwErrID": 0,
		"dwHandle": 0,
		"dwReserved": 0
	}
  @endverbatim
*/	
	Ev_MtApi_ImClearDir_Rsp,

/**
  @brief    发送文件响应
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImFileShareReq_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam":
		{
			"achDestNO" : "",           
			"achFilePath" : "",       
			"nFileType" : 0,                                 
			"dwFileSize" : 0                               
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImSendFile_Rsp,

/**
  @brief    同意接收文件响应
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImAcceptFile_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam":
		{
			"bRecv": 0,
			"bSetSavePath": 0,
			"achPath": ""
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImAcceptFile_Rsp,

/**
  @brief    取消接收文件响应	
  
	MainBuf(#TImComm_Api) \n
	Json格式如下：

	@verbatim
	{
		"dwErrID": 0,
		"dwHandle": 0,
		"dwReserved": 0
	}
  @endverbatim
*/	
	Ev_MtApi_ImCancelFile_Rsp,

/**
  @brief    文件共享通知	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImFileShareOfferInfo_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam":
		{
			"achPeerNO" : "",           
			"achFileName" : "",       
			"nFileType" : 0,                                 
			"dwFileSize" : 0,                                
			"bSender" : 0                                   
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImFileShareOffer_Ntf,

/**
  @brief    开始文件共享通知
  
	MainBuf(#TImComm_Api) \n
	Json格式如下：

	@verbatim
	{
		"dwErrID": 0,
		"dwHandle": 0,
		"dwReserved": 0
	}
  @endverbatim
*/	
	Ev_MtApi_ImFileShareStart_Ntf,

/**
  @brief    文件共享通知	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#string) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam":
		{
			"strPath": ""
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImFileShareComplete_Ntf,

/**
  @brief    取消文件共享通知	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#BOOL) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam":
		{
			"bStop": 0
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImFileShareCancel_Ntf,

/**
  @brief    文件共享失败通知
  
	MainBuf(#TImComm_Api) \n
	Json格式如下：

	@verbatim
	{
		"dwErrID": 0,
		"dwHandle": 0,
		"dwReserved": 0
	}
  @endverbatim
*/	
	Ev_MtApi_ImFileShareFailure_Ntf,

/**
  @brief    文件共享进度通知	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImFileShareProgress_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam":
		{
			"achCurFileName": "",
			"dwPercent": 0,
			"dwTransferSize": 0,
			"dwTrasferRate": 0
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImFileShareProgress_Ntf,

/**
  @brief    设置文件保存路径响应
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#string) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam":
		{
			"strPath": ""
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImSetFileSavePath_Rsp,

/**
  @brief   添加组通知
  
	MainBuf(#u32)\n
	SubBuf(#TImGroupInfo_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
			"achGroupSn" : "",                   
			"achGroupName" : "",                 
			"achParentGroupSn" : "",             
			"wGroupLevel" : 0  
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImGroupAdd_Ntf,

/**
  @brief    删除组通知	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImSn_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"achSn": "str"
		}
	}
  @endverbatim
*/
	Ev_MtApi_ImGroupDel_Ntf,

/**
  @brief   修改组通知
  
	MainBuf(#u32)\n
	SubBuf(#TImGroupInfo_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
			"achGroupSn" : "",                   
			"achGroupName" : "",                 
			"achParentGroupSn" : "",             
			"wGroupLevel" : 0  
		}
	}
  @endverbatim
*/
	Ev_MtApi_ImGroupModify_Ntf,

/**
  @brief    添加成员通知	
  
	MainBuf(#u32)\n
	SubBuf(#TImMemberInfo_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam" :
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
				"achMemberSn": "",
				"achGroupSn": "",
				"achMemberNO": "",
				"achMarkName": "",
				"emMemberType": 0,
				"wBitRate": 0,
				"tWeiboInfo":
				{
					"achMoId": "",
					"achCompanyMoId": "",
					"achcn": "",
					"achsn": "",
					"achentMail": "",
					 "achEntName": "",
					 "achEntRealName": "",
					 "ache164": "",
					 "achjid": "",
					 "achmobileNum": "",
					 "achextNum": "",
					 "achbrief": "",
					 "achposition": "",
					 "achportrait40": "",
					 "achportrait64": "",
					 "achportrait128": "",
					 "achxmpppwd": "",
					 "achseat": "",
					 "bEnableWeibo": 0,
					 "bEnableMeeting": 0,
					 "bEnableHD": 0,
					 "bEnableCall": 0,
					 "bEnableRoam": 0,
					 "bEnableSatellite": 0,
					 "bEnableSatelliteP2P": 0,
					 "bMale": 0,
					 "tMtWbParseKedaDepts": 
					{
						"dwDeptNum": 0,
						"atMtWbParseKedaDept": 
						[
						  {
							"dwDepartmentId": 0,
							"achDepartmentName": ""
						   }
						]
					}
				},
				"bNoQuery": 0
			}
	}
  @endverbatim
*/	
	Ev_MtApi_ImMemberAdd_Ntf,

/**
  @brief    删除成员通知	
  
	MainBuf(#u32)\n
	SubBuf(#TImSn_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
			"tImSn_Api": {
				"achSn" : ""  
			}
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImMemberDel_Ntf,

/**
  @brief    修改成员通知	
  
	MainBuf(#u32)\n
	SubBuf(#TImMemberInfo_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
				 "achMemberSn": "",
			     "achGroupSn": "",
				 "achMemberNO": "",
				 "achMarkName": "",
				 "emMemberType": 0,
				 "wBitRate": 0,
				 "tWeiboInfo":
				 {
				     "achMoId": "",
					 "achCompanyMoId": "",
					 "achcn": "",
					 "achsn": "",
					 "achentMail": "",
					 "achEntName": "",
					 "achEntRealName": "",
					 "ache164": "",
					 "achjid": "",
					 "achmobileNum": "",
					"achextNum": "",
					 "achbrief": "",
					 "achposition": "",
					 "achportrait40": "",
					 "achportrait64": "",
					 "achportrait128": "",
					 "achxmpppwd": "",
					 "achseat": "",
					 "bEnableWeibo": 0,
					 "bEnableMeeting": 0,
					"bEnableHD": 0,
					 "bEnableCall": 0,
					 "bEnableRoam": 0,
					 "bEnableSatellite": 0,
					 "bEnableSatelliteP2P": 0,
					 "bMale": 0,
					 "tMtWbParseKedaDepts": 
					{
						"dwDeptNum": 0,
						"atMtWbParseKedaDept": 
						[
						  {
							"dwDepartmentId": 0,
							"achDepartmentName": ""
						  }
						]
					}
				},
				"bNoQuery": 0
		}
	}
*/	
	Ev_MtApi_ImMemberModify_Ntf,

/**
  @brief    移动成员通知	
  
	MainBuf(#u32)\n
	SubBuf(#TImMoveMember_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
			"achMemberSn" : "",               
			"achOldGroupSn" : "",             
			"achNewGroupSn" : "" 
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImMemberMove_Ntf,

/**
  @brief    进入固定房间通知	
  
	MainBuf(#u32)\n
	SubBuf(#TImMulitChatCreateInfo_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam" :
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
				"achChatName" : "",
				"achConfE164" : "",     
				"achRoomId" : "",  
				"achInviterNO" : "",        
				"dwSessionID" : 0,                              
				"dwClientID" : 0,                               
				"bPersistent" : 0,                          
				"bOwner" : 0,                               
				"emMultiChatType" : 0
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImEnterPersistentRoom_Ntf,

/**
  @brief    进入固定房间失败通知
  
	MainBuf(#u32)\n
	SubBuf(#TPersistentChatroomItem_Api)  \n
	Json格式如下：

	@verbatim
	{
		"MainParam" :
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
			"tPersistentChatroomItem_Api": {
				"achRoomId": "",
				"achChatName": ""
				}
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImEnterPersistentRoomFail_Ntf,

/**
  @brief    断链通知
  
	MainBuf(#u32)  \n
	Json格式如下：

	@verbatim
	{
		"dwHandle" : 0
	}
  @endverbatim
*/	
	Ev_MtApi_ImDisconnected_Ntf,

/**
  @brief    通知有人请求关注自己	
  
	MainBuf(#u32)\n
	SubBuf(#TImNO_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
			"achNO" : ""
		}
	}
  @endverbatim
*/
	Ev_MtApi_ImQuerySubscribe_Ntf,

/**
  @brief    发送组聊天文件响应
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TImGroupChatFileShareReq_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
		   "achFilePath" : "",       
		   "dwSessionID" : 0,                               
		   "nFileType" : 0,                                 
		   "dwFileSize" : 0,                                
		   "tRoomId" : 
		   {
		     "achRoomId" : ""
		   }                             
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImSendGroupChatFile_Rsp,


	Ev_MtApi_ImInnerNotifyCreateChatRoom_Ntf,

/**
  @brief    设置文件传输最大速率响应
  
	MainBuf(#TImComm_Api)  \n
	Json格式如下：

	@verbatim
	{
		"dwErrID": 0,
		"dwHandle": 0,
		"dwReserved": 0
	}
  @endverbatim
*/	
	Ev_MtApi_ImSetFileTransferBitRate_Rsp,

/**
  @brief    设置聊天室消息读取标志响应	
  
	MainBuf(#TImComm_Api)  \n
	Json格式如下：

	@verbatim
	{
		"dwErrID": 0,
		"dwHandle": 0,
		"dwReserved": 0
	}
  @endverbatim
*/	
	Ev_MtApi_ImSetChatroomMessagesReadFlag_Rsp,

/**
  @brief    定时PUSH 缓存的好友状态	
  
	MainBuf(#TDeviceOnlineStateCacheList_Api)  \n
	Json格式如下：

	@verbatim
	{
		"dwArraySize" : 0,
		"atArray" : 
		[
			{
				"dwApp" : 0,                             
				"tStatus" : 
				{
					"achNO" : "",	                       
					"tDeviceType" : 0,                    
					"tState" : 0,                            
					"tMaxState" : 0,                         

					"bSelf" : 0,                                          
					"bFirst" : 0,                                         
					"bFileShare" : 0,                                     
					"bAudioCapability" : 0,                               
					"bVideoCapability" : 0,                               
					"bGkConnected" : 0,                                   
					"bMaxAudio" : 0,                                      
					"bMaxVideo" : 0,                                      
					"bLoginBeforeMe" : 0                                 
				}        
			}
		]
	}
  @endverbatim
*/	
	Ev_MtApi_ImPushMemberStatus_Ntf,

/**
  @brief    成员数据准备完毕通知
  
	MainBuf(#u32)  \n
	*Json格式如下：

	@verbatim
	{
		"dwHandle" : 0
	}
  @endverbatim
*/	
	Ev_MtApi_ImMembersDataReady_Ntf,

/**
  @brief    获取成员状态应答
  
	MainBuf(#u32)\n
	SubBuf(#TImNOList_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
			"dwArraySize" : 0,
			"atArray" : 
			[
				 {
					"achNO" : ""       
				  }
			]
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImGetUsersState_Rsp,

/**
  @brief    获取成员状态通知
  
	MainBuf(#u32)\n
	SubBuf(#TImUserStateList_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
			"dwArraySize" : 0,
			"atArray" : 
			[
			   {
				 "achNO" : "",
				 "emState" : 0
			   }
			]
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImGetUsersState_Ntf,

/**
  @brief    获取成员状态结束通知	
  
	MainBuf(#u32)\n
	SubBuf(#TImNOList_Api)\n 
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
			"dwArraySize" : 0,
			"atArray" : 
			[
				 {
					"achNO" : ""       
				 }
			]
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImGetUsersState_Fin_Ntf,

/**
  @brief    获取成员状态扩展信息响应
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImNOList_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"dwArraySize" : 0,
			"atArray" : 
			[
				 {
					"achNO" : ""       
				 }
			]
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImGetUsersStateEx_Rsp,

/**
  @brief   获取成员状态扩展信息通知
  
	MainBuf(#u32)\n
	SubBuf(#TImUserStateListEx_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
			"dwArraySize" : 0,
			"atArray" : 
			[
				{
					"achNO" : "",	
					"tState" : 0,                       
					"bMaxAudio" : 0,                    
					"bMaxVideo" : 0,                    
					 "atMtState" : 
					 [
					      {
						        "eMtType" : 0,        
						        "eMtState" : 0,       
						        "bAudioCapability" : 0,  
							    "bVideoCapability" : 0,  
						        "bGkConnected" : 0    
					      }
					 ] 
				}
			]
		}
	}
  @endverbatim
*/
	Ev_MtApi_ImGetUsersStateEx_Ntf,

/**
  @brief  获取成员状态扩展信息结束通知	
  
	MainBuf(#u32)\n
	SubBuf(#TImNOList_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam" :
		{
			"dwHandle": 0
		},
		"AssParam" :
		{
			"dwArraySize" : 0,
			"atArray" : 
			[
				 {
					"achNO" : ""       
				 }
			]
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImGetUsersStateEx_Fin_Ntf,


	Ev_MtApi_ImInnerNotifyAcceptInvite_Ntf,


	Ev_MtApi_ImInnerDisconnected_Ntf,

/**
  @brief    通知安全登录(同一账号在其他地方登录)
  
	MainBuf(#u32) \n
	Json格式如下：

	@verbatim
	{
         "dwHandle" : 0
	}
  @endverbatim
*/	
	Ev_MtApi_ImNotifySecurity_Ntf,

/**
  @brief    离线消息满通知	
  
	MainBuf(#tImComm_Api) \n
	Json格式如下：

	@verbatim
	{
		"dwErrID": 0,
		"dwHandle": 0,
		"dwReserved": 0,
		"achReserved":""
	}
  @endverbatim
*/	
	Ev_MtApi_ImNotifyOfflineMsgOverflow_Ntf,

/**
  @brief    设置聊天室响应
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImChatRoomInfo_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{

			"dwSessionID" : 0,
			"achChatName" : "",
			"tRoomId" : 
			{
				"achRoomId" : ""
			}
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImSetChatroom_Rsp,

/**
  @brief    聊天室配置通知
  
	MainBuf(#u32)\n
	SubBuf(#TImChatRoomInfo_Api)\n 
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
			"dwSessionID" : 0,
			"achChatName" : "",
			"tRoomId" : 
			{
				"achRoomId" : ""
			}
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImNotifyRoomConfig_Ntf,


	Ev_MtApi_ImInnerDebug_Ntf,

	Ev_MtApi_ImInnerXmppInfo_Ntf,

/**
  @brief    拒绝邀请，消息满的通知	
  
	MainBuf(#u32)\n
	SubBuf(#TDeclineInfo_Api)  \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
			"achChatName" : "",    
			"achRoomId" : "",      
			"achDeclineNO" : "",            
			"emReason" : 0  
		}
	}
  @endverbatim
*/
	Ev_MtApi_ImDecline_Ntf,

/**
  @brief    聊天室非在线人员增加通知
  
	MainBuf(#u32) \n
	SubBuf(#TImMultiChatRosterItemList_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
			"dwSessionId" : 0,                           
			"dwArraySize" : 0,                              
			"atArray" : 
			[
			     {
					"achNO" : "", 
					"bOwner" : 0,                      
					"bSelf" : 0                       
				}
			],   
			"tRoomId" : 
			{
				"achRoomId" : ""
			}	
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImChatroomRosterItemsAdd_Ntf,

/**
  @brief    聊天室非在线人员减少通知
  
	MainBuf(#u32) \n
	SubBuf(#TImMultiChatRosterItemList_Api)  \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
				"dwSessionId" : 0,                           
				"dwArraySize" : 0,                              
				"atArray" : 
				[
				   {
					  "achNO" : "", 
					  "bOwner" : 0,                      
					  "bSelf" : 0                       
					}
				],   
				"tRoomId" : 
				{
					 "achRoomId" : ""
				}
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImChatroomRosterItemsDel_Ntf,

/**
  @brief    聊天室服务可用通知	
  
	MainBuf(#TImComm_Api)  \n
	Json格式如下：

	@verbatim
	{
		"dwErrID": 0,
		"dwHandle": 0,
		"dwReserved": 0
	}
  @endverbatim
*/	
	Ev_MtApi_ImChatroomServiceAvailable_Ntf,

/**
  @brief    聊天室图片传输开始通知	
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TMultiChatPicId_Api)  \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
		    "achNO" : "",	 
			"achSid" : "",   
			"dwSessionID" : 0,                     
			"emDeviceType" : 0,                     
			"tRoomId" : 
			{
				"achRoomId" : ""
			}                        
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImChatroomPictureOpen_Ntf,

/**
  @brief    聊天室图片传输进度通知	
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TMultiChatPicId_Api)  \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"achNO" : "",	 
			"achSid" : "",   
			"dwSessionID" : 0,                     
			"emDeviceType" : 0,                     
			"tRoomId" : 
			{
				"achRoomId" : ""
			}                        
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImChatroomPictureData_Ntf,

/**
  @brief    聊天室图片传输终止通知
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TImChatroomPicture_Api)  \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"tMultiChatPicId_Api":
			{
				"achNO": "",
				"achSid": "",
				"dwSessionID": 0,
				"emDeviceType": 0,
				"tRoomId": 
				{
				   "achRoomId": ""
				}
			},
			"achPath": ""
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImChatroomPictureClose_Ntf,

/**
  @brief   聊天室图片传输失败通知	
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TMultiChatPicId_Api)  \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"achNO" : "",	 
			"achSid" : "",   
			"dwSessionID" : 0,                     
			"emDeviceType" : 0,                     
			"tRoomId" : 
			{
				"achRoomId" : ""
			}                        
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImChatroomPictureFail_Ntf,

/**
  @brief    聊天室添加成员通知	
  
	MainBuf(#u32) \n
	SubBuf(#TMTImMultiChatAddMemberNtf_Api)  \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle": 0,
		},
		"AssParam": 
		{
			"dwSessionId" : 0,
			"achMail" : "str",
			"tRoomId" :
			{
				"achRoomId" : ""
			}
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImChatroomMemberAdd_Ntf,

/**
  @brief    聊天室成员状态批量通知	
  
	MainBuf(#TChatroomMemberCacheList_Api)  \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwArraySize": 0,
			"atArray": 
			{
				    "emEventId": 0,
					"dwApp": 0,
				    "tInfo": 
				    {
						"dwSessionID": 0,
						"achNO": "",
						"bOwner": 0,
						"bSelf": 0,
						"eMtType": 0,
						"eState": 0,
						"eMaxState": 0,
						"tRoomId": 
						{
							"achRoomId": ""
						}
					}
			}
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImChatroomMemberBatch_Ntf,

/**
  @brief    通知上次登录保存的固定讨论组信息	
  
	MainBuf(#u32) \n
	SubBuf(#TPersistentChatroomList_Api)  \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
			"dwArraySize": 0,
			"atArray": 
			[
			  {
				"achRoomId": "",
				"achChatName": ""
			  }
			]
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImPersistentChatrooms_Ntf,

/**
  @brief    通知上次登录保存的固定讨论组信息结束
  
	MainBuf(#u32)  \n
	Json格式如下：

	@verbatim
	{
		"dwHandle" : 0
	}
  @endverbatim
*/
	Ev_MtApi_ImPersistentChatrooms_Fin_Ntf,

/**
  @brief   请求进入之前保存的固定讨论组	
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TPersistentChatroomList_Api)  \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"dwArraySize": 0,
			"atArray": 
			[
			   {
				  "achRoomId": "",
				  "achChatName": ""
			   }
			]
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImQueryEnterSavedPersistentChatrooms_Rsp,

/**
  @brief    告知Im层上层应用，登录后准备好应答
  
	MainBuf(#TImComm_Api)  \n
	Json格式如下：

	@verbatim
	{
		"dwErrID": 0,
		"dwHandle": 0,
		"dwReserved": 0
	}
  @endverbatim
*/	
	Ev_MtApi_ImSetReady_Rsp,

/**
  @brief    通知数据已准备完毕
  
	MainBuf(#u32)  \n
	Json格式如下：

	@verbatim
	{
		"dwHandle" : 0
	}
  @endverbatim
*/	
	Ev_MtApi_ImSetReady_Ntf,

/**
  @brief    查询某组下成员的在线状态(根据位置)应答
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TImSn_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"achSn": "str"
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImQueryOnlineStateByGroupSnAndPosition_Rsp,

/**
  @brief    查询某组下的联系人列表信息(根据位置)应答
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TImSn_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0

		},
		"AssParam": 
		{
			"achSn": "str"
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImQueryMemberInfoByGroupSnAndPosition_Rsp,

/**
  @brief    告知对方自己的键盘输入状态应答(根据位置)应答
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TImCharState_Api)  \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"achPerrNO" : "",    
			"emImMtType" : 0,
			"eCharState" : 0     
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImSendCharState_Rsp,

/**
  @brief    联系人键盘输入状态通知
  
	MainBuf(#dwHandler) \n
	SubBuf(#TImCharState_Api)  \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle": 0,
		},
		"AssParam": 
		{
			"achPerrNO" : "",    
			"emImMtType" : 0,
			"eCharState" : 0     
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImCharState_Ntf,

/**
  @brief    告知对方闪屏应答
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TImSplash_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"achPeerNO" : "",  
			"emImMtType" : 0,
			"dwSplashType" : 0                     
		}
	}
  @endverbatim
*/
	Ev_MtApi_ImSendSplash_Rsp,

/**
  @brief    闪屏通知
  
	MainBuf(#u32) \n
	SubBuf(#TImSplash_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam":
		{
			"achPeerNO" : "",  
			"emImMtType" : 0,
			"dwSplashType" : 0   
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImSendSplash_Ntf,

/**
  @brief   设置/获取自定义配置应答
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TImCustomCfg_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"atItems" : 
			[
				{
					"achKey" : "",
					"achValue" : ""
				}
			],
			"dwItemsCnt" : 0,     
			"bGet" : 0        
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImConfig_Rsp,

/**
  @brief    自定义配置数据准备好通知	
  
	MainBuf(#u32)  \n
	Json格式如下：

	@verbatim
	{
		"dwHandle" : 0
	}
  @endverbatim
*/	
	Ev_MtApi_ImConfigDataReady_Ntf,

/**
  @brief   屏蔽讨论组应答	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImScreenChatroom_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"bScreen" : 0,                                  
			"achRoomId" : ""   
		}
	}
  @endverbatim
*/	

	Ev_MtApi_ImScreenChatrom_Rsp,

/**
  @brief    获取所有屏蔽讨论组应答
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TImScreenedChatrooms_Api)成功 \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"aachRoomId": [
			"",
			""
			]
		}
	}
	@endverbatim	
	
	MainBuf(#TImComm_Api) \n
	SubBuf(#TImScreenedChatroom_Api)失败 \n
	Json格式如下：
	
	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"bScreen" : false,                                  
			"aachRoomIds" : [
			{
			"basetype" : ""
			}
			], 
			"dwCount" : 0
		}
	}

  @endverbatim
*/	
	Ev_MtApi_ImGetScreenedChatroms_Rsp,

/**
  @brief    屏蔽讨论组(无流量)应答
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TImScreenChatroomR_Api)  \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"bScreen" : false,                                  
			"aachRoomIds" : [
			{
			"basetype" : ""
			}
			], 
			"dwCount" : 0
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImScreenChatromR_Rsp,

/**
  @brief    获取讨论组所有不在线成员应答
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TRoomId_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"achRoomId" : ""
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImMulitChatGetRosters_Rsp,

/**
  @brief    获取某人参加的视频会议id应答
  
	成功\n
	MainBuf(#TImComm_Api)\n
	SubBuf(#TFriendConferenceInfo_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam": 
		{
			"dwErrID" : 0,
			"dwHandle" : 0,
			"dwReserved" : 0
		},
		"AssParam": 
		{
			"achPeerId": "",
			"achConfE164": "",
			"achRoomId": "",
			"achChatName": "",
			"emPeerType": 0

		}
	}
	@endverbatim
	
	失败 \n
	MainBuf(#TImComm_Api) \n
	SubBuf(#TImNO_Api) \n
	
	@verbatim
	{
		"MainParam": 
		{
			"dwErrID" : 0,
			"dwHandle" : 0,
			"dwReserved" : 0
		},
		"AssParam": 
		{
			"achNO" : ""      
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImGetFriendConference_Rsp,


	Ev_MtApi_ImInnerGroupChat_Ntf,


	Ev_MtApi_ImInnerChat_Ntf,

/**
  @brief    临时关注某联系人应答
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImNO_Api) \n
	Json格式如下：\n

	@verbatim
	{
	    "MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"achNO" : ""      
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImTempSubscribe_Rsp,

/**
  @brief    取消临时关注某联系人应答
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImNO_Api) \n
	Json格式如下：\n

	@verbatim
	{
	    "MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"achNO" : ""      
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImUnTempSubscribe_Rsp,

/**
  @brief    批量添加联系人到一个组应答	
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TBatchAddContacts_Api)  \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
		  "atBatchContacts":
		  {
			 "achMemberNO": "",
			 "achMarkName": "",
			 "emMemberType": 0,
			 "wBitRate": 0
			},
			"dwCount": 0,
			"achDestGroupSn": ""
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImBatchAddContacts_Rsp,

/**
  @brief    批量删除联系人应答	
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TBatchDelContacts_Api)  \
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"atBatchContacts": 
			{
				"achSn": ""
			},
			"dwCount": 0
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImBatchDelContacts_Rsp,

/**
  @brief    批量移动联系人应答	
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TBatchMoveContacts_Api)  \n
	Json格式如下：

	@verbatim
	{
		"MainParam":
		{
		    "dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
		},
		"AssParam": 
		{
			"atBatchContacts":
			{
				"achSn": ""
			},
			"dwCount": 0,
			"achDestGroupSn": ""
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImBatchMoveContacts_Rsp,

/**
  @brief    获取服务器时间应答	
  
	MainBuf(#TImComm_Api)  \n
	Json格式如下：

	@verbatim
	{
			"dwErrID": 0,
			"dwHandle": 0,
			"dwReserved": 0
	}
  @endverbatim
*/	
	Ev_MtApi_ImGetServerTime_Rsp,

/**
  @brief   查询用户信息通知	
  
	成功 \n
	MainBuf(#TRestErrorInfo_Api) \n
	SubBuf(#TMTWbParse_Keda_EntUser_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam": 
		{
			"achErrorInfo": "",
			"emApiType": 0,
			"dwErrorID": 0,
			"dwNackEventId": 0,
			"adwParams": 
			[
			   {
                  "basetype": 0
			   }
			]
		},
		"AssParam": 
		{
			"tMTWbParse_Keda_EntUser_Api": 
			{
				"achMoId": "",
				"achCompanyMoId": "",
				"achcn": "",
				"achsn": "",
				"achentMail": "",
				"achEntName": "",
			    "achEntRealName": "",
			    "ache164": "",
			    "achjid": "",
			    "achmobileNum": "",
				"achextNum": "",
				"achbrief": "",
    			"achposition": "",
    			"achportrait40": "",
    			"achportrait64": "",
    			"achportrait128": "",
    			"achxmpppwd": "",
    			"achseat": "",
    			"bEnableWeibo": 0,
    			"bEnableMeeting": 0,
    			"bEnableHD": 0,
    			"bEnableCall": 0,
    			"bEnableRoam": 0,
    			"bEnableSatellite": 0,
    			"bEnableSatelliteP2P": 0,
    			"bMale": 0,
				"bLimited": 0,
    			"tMtWbParseKedaDepts": 
	 			{
        			"dwDeptNum": 0,
        			"atMtWbParseKedaDept":
		 			[ 
					  {
            			"dwDepartmentId": 0,
            			"achDepartmentName": ""
					  }
         			]
     			}
			}
		}
	}
	@endverbatim
	
	失败 \n
	MainBuf(#TRestErrorInfo_Api) \n
	SubBuf(#TMTAccountManagerSystem_Api) 
	
	@verbatim
	{
		"MainParam":
		{
			"achErrorInfo": "",
			"emApiType": 0,
			"dwErrorID": 0,
			"dwNackEventId": 0,
			"adwParams": 
			[
			    {
				   "basetype": 0
				}
			]
		},
		"AssParam": 
		{
				"achusername": "",
    			"achpassword": "",
    			"achmobileNum": "",
    			"achextNum": "",
    			"achseat": "",
    			"achbrief": "",
    			"achposition": "",
   			    "achName": "",
    			"achAPIAddr": "",
    			"bMale": 0,
    			"bIsAdding": 0,
    			"dwBitMask": 0,
    			"dwContextId": 0

		}
	}
  @endverbatim
*/
	Ev_MtApi_ImQueryAccountInfo_Rsp,

/**
  @brief    断开所有服务器通知
  
	MainBuf(#u32)  \n
	Json格式如下：

	@verbatim
	{
		"dwHandle" : 0
	}
  @endverbatim
*/	
	Ev_MtApi_ImUserDisconnect_Ntf,

/**
  @brief    自定义配置修改通知
  
	MainBuf(#u32)\n
	SubBuf(#TImCustomCfgItem_Api) \n
	Json格式如下：

	@verbatim
	{
		"MainParam" :
		{
			"dwHandle" : 0
		},
		"AssParam" :
		{
			"achKey" : "",
			"achValue" : ""
		}
	}
  @endverbatim
*/	
	Ev_MtApi_ImConfigItemChange_Ntf,

/**
  @brief    获取组织架构状态响应
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#s8*)

	@verbatim
	{
	    "MainParam":
	    {
	       "dwErrID": 0,
	       "dwHandle": 0,
	       "dwReserved": 0
	     },
	    "AssParam": 
	    {
		    "basetype": 0
	    }
	}
  @endverbatim
*/	
	Ev_MtApi_ImGetOrganizationState_Rsp,

    /**
  @brief    获取固定讨论组响应
  
	MainBuf(#TImComm_Api) \n

	@verbatim
	{
	    "MainParam":
	    {
	       "dwErrID": 0,
	       "dwHandle": 0,
	       "dwReserved": 0
	     }
	}
  @endverbatim
*/	
	Ev_MtApi_ImGetHoldPersistentRoom_Rsp,

    EV_UI_END(MTAPI_IM) = EVSEG_MTAPI_IM_END
};

#define Is_MtApiIM_Msg(m) ((m) >= EV_UI_BGN(MTAPI_IM) && (m) <= EV_UI_END(MTAPI_IM))

/**@}*/

/**@}*/
#endif // _MTAPI_EVENT_IM_H_
