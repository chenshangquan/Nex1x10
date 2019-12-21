/*******************************************************************************//**
*@file          mtapi_event_im.h
*@brief         ʵ��MTAPI MtIMSdk ��UI(�۲���)�¼�֪ͨ�Ķ���
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_EVENT_IM_H_
#define _MTAPI_EVENT_IM_H_
/**@addtogroup event �¼�
*@{
*/

/**@addtogroup imevent �����¼�
*@{
*/

#include "mtapi_event_def.h"


enum EmMtApiIMEv
{
	EV_UI_BGN(MTAPI_IM)  = EVSEG_MTAPI_IM_BGN,

	//im���
/**
  @brief    �����¼XMPP������Ӧ��
  
	MainBuf(#TImComm_Api) 
	Json��ʽ���£�

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
  @brief   �����ѯ�Լ����Զ�����ϢӦ��
  
	MainBuf(#TImComm_Api)\n
    SubBuf(#TImSelfDef_Api)
 
	Json��ʽ���£�

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
  @brief   �����ѯ�����ҷ����Ƿ����Ӧ��
  
 
	Json��ʽ���£�

	@verbatim
	{
		"bAvailable":false,
	}
  @endverbatim
*/	
	Ev_MtApi_ImGetChatRoomServiceAvailable_Rsp,

/**
  @brief    �����޸��Լ����Զ�����ϢӦ��	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImSelfDef_Api)
	 Json��ʽ���£�

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
  @brief    �����޸��Լ����Զ�����ϢӦ��	
  
	�ɹ�\n
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImSelfDefInfo_Api)
	Json��ʽ���£�

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
	
	ʧ��\n
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
  @brief    �����ѯ����ϢӦ��	
  
	MainBuf(#TImComm_Api) 
	Json��ʽ���£�

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
  @brief    �����ѯ����ϢӦ��	
  
	MainBuf(#u32)\n
	SubBuf(#TImGroupList_Api)\n
	Json��ʽ���£�

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
  @brief    �����ѯ����ϢӦ�����
  
	MainBuf(#u32) \n
	Json��ʽ���£�

	@verbatim
	{
        "basetype": 0
	}
  @endverbatim
*/	
    Ev_MtApi_ImQueryGroupInfo_Fin_Rsp,

/**
  @brief    �����ѯĳ���������ϢӦ��	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImSn_Api)\n
	Json��ʽ���£�

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
  @brief    �����ѯĳ���������ϢӦ��
  
	MainBuf(#u32)\n
	SubBuf(#TImGroupList_Api)\n
	Json��ʽ���£�

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
  @brief    ��ѯ������Ϣ�ɹ���ķְ���Ϣ	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImSn_Api)\n
	Json��ʽ���£�

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
  @brief    ��������ϢӦ��
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImGroupInfo_Api)\n
	Json��ʽ���£�

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
  @brief    ɾ������ϢӦ��	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImSn_Api)\n
	Json��ʽ���£�

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
  @brief    �޸�����ϢӦ��	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImGroupInfo_Api)\n
	Json��ʽ���£�

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
  @brief    ������Ų�ѯ��Ա��ϢӦ��
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImSn_Api)\n
	Json��ʽ���£�

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
  @brief    ������Ų�ѯ��Ա��ϢӦ��
  
	MainBuf(#u32)\n
	SubBuf(#TImMemberList_Api) \n
	Json��ʽ���£�

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
  @brief    ��ѯĳ���µ���ϵ���б���Ϣ�ְ���Ϣ���֪ͨ	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImSn_Api)\n
	Json��ʽ���£�

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
  @brief    ��Ӻ���Ӧ��
  
	�ɹ�\n
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
	
	ʧ��\n
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
  @brief    ��ѯ��Ӻ�����ϢӦ��	
  
	MainBuf(#TRestErrorInfo_Api)\n
	SubBuf(#TMTSearchUserInfo_Api) \n
	Json��ʽ���£�
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
  @brief    ���ƺ���Ӧ��
  
	�ɹ�
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImMemberFullInfo_Api)\n
	Json��ʽ���£�

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
	
	 ʧ��\n
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
  @brief    ɾ������Ӧ��	
  
	MainBuf(#TImComm_Api)\n
    SubBuf(#TImSn_Api) \n
	Json��ʽ���£�\n

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
  @brief    �޸ĺ���Ӧ��
  
	MainBuf(#TImComm_Api)\n
	 SubBuf(#TImMemberInfo_Api) \n
	*Json��ʽ���£�

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
  @brief    �ƶ�����Ӧ��
  
	MainBuf(#TImComm_Api)\n
	 SubBuf(#TImMoveMember_Api) \n
	*Json��ʽ���£�

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
  @brief    ��Ա����״̬���֪ͨ
  
	MainBuf(#u32)\n
	SubBuf(#TDeviceOnlineState_Api) \n
	Json��ʽ���£�

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam"��
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
  @brief    ������ID��ѯ����״̬Ӧ��	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImSn_Api) \n
	Json��ʽ���£�

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
  @brief    ������ID��ѯ����״̬Ӧ��֪ͨ	
  
	MainBuf(#u32)\n
    SubBuf(#TImUserStateList_Api) \n
	Json��ʽ���£�

	@verbatim
	{
		"MainParam":
		{
			"dwHandle" : 0
		},
		"AssParam"��
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
  @brief    ������ID��ѯ����״̬Ӧ��֪ͨ	
  
	MainBuf(#u32)\n
	SubBuf(#TImSn_Api) \n
	Json��ʽ���£�

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
  @brief   ������ID��ѯ����״̬��չ��ϢӦ��
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImSn_Api) \n
	Json��ʽ���£�

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
  @brief    ������ID��ѯ����״̬��չ��ϢӦ��֪ͨ	
  
	MainBuf(#u32)\n
	SubBuf(#TImUserStateListEx_Api) \n
	Json��ʽ���£�

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
  @brief    ������ID��ѯ����״̬��չ��ϢӦ�����֪ͨ	
  
	MainBuf(#u32)\n
	SubBuf(#TImSn_Api) \n
	Json��ʽ���£�

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
  @brief    �޸��Լ�״̬Ӧ��
  
	MainBuf(#TImComm_Api)\n
	 SubBuf(#TImSetUserState_Api) \n
	Json��ʽ���£�

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
  @brief    ���͵�Ե���ϢӦ��
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImP2PChatMessage_Api) \n
	Json��ʽ���£�

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
  @brief    ���͵�Ե���ϢӦ��֪ͨ	
  
	MainBuf(#u32)\n
	SubBuf(#TImP2PChatMessage_Api) \n
	Json��ʽ���£�

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
  @brief    ���͵�Ե���ϢӦ��֪ͨ	
  
	MainBuf(#u32)\n
	SubBuf(#TImP2PChatMessage_Api) \n
	Json��ʽ���£�

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
  @brief    ������������Ӧ��
  
    MainBuf(#TImComm_Api) \n
	SubBuf(#TImMulitChatCreateInfo_Api)\n
	Json��ʽ���£�

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
  @brief    ������������֪ͨ	
  
	MainBuf(#u32) \n
	SubBuf(#TImMultiChatCreateInfo_Api) \n
	*Json��ʽ���£�

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
  @brief    ������������֪ͨ	
  
	MainBuf(#tImComm_Api) \n
	SubBuf(#TRoomId_Api)  \n
	Json��ʽ���£�

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
  @brief    ���ٶ�������֪ͨ	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TRoomId_Api) \n
	Json��ʽ���£�

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
  @brief    ����������ӳ�ԱӦ��
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TImMultiChatMemberInfo_Api) \n
	Json��ʽ���£�

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
  @brief    ����������ӳ�Ա֪ͨ
  
	MainBuf(#u32) \n
	SubBuf(#TImMultiChatMemberInfoEx_Api) \n 
	Json��ʽ���£�

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
  @brief    ���������Ա״̬�ı�֪ͨ
  
	MainBuf(#u32)\n
	SubBuf(#TImMultiChatMemberInfoEx_Api) \n
	Json��ʽ���£�

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
  @brief   ��������T��Ӧ��
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TImMultiChatMemberInfo_Api) \n

	Json��ʽ���£�

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
  @brief    ��������T��֪ͨ	
  
	MainBuf(#u32)\n
	SubBuf(#TImMultiChatMemberInfoEx_Api) \n
	Json��ʽ���£�

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
  @brief    �˳���������Ӧ��
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TRoomId_Api) \n
	Json��ʽ���£�

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
  @brief    ���������Ա�뿪֪ͨ
  
	MainBuf(#u32)\n
	SubBuf(#TImMultiChatMemberInfoEx_Api) \n
	Json��ʽ���£�

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
  @brief    ���Ͷ����Ϣ��Ӧ	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImMultiChatMessage_Api) \n
	Json��ʽ���£�

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
  @brief   ���Ͷ����Ϣ֪ͨ	
  
	MainBuf(#u32)\n
	SubBuf(#TImMultiChatMessage_Api) \n
	Json��ʽ���£�

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
  @brief    ���Ͷ����ϢӦ��
  
	MainBuf(#u32)\n
	SubBuf(#TImMultiChatMessage_Api) \n
	Json��ʽ���£�

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
  @brief    ���Ͷ����ϢӦ��	
  
	MainBuf(#TImComm_Api) \n
	Json��ʽ���£�

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
  @brief    �����ļ���Ӧ
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImFileShareReq_Api) \n
	Json��ʽ���£�

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
  @brief    ͬ������ļ���Ӧ
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImAcceptFile_Api) \n
	Json��ʽ���£�

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
  @brief    ȡ�������ļ���Ӧ	
  
	MainBuf(#TImComm_Api) \n
	Json��ʽ���£�

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
  @brief    �ļ�����֪ͨ	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImFileShareOfferInfo_Api) \n
	Json��ʽ���£�

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
  @brief    ��ʼ�ļ�����֪ͨ
  
	MainBuf(#TImComm_Api) \n
	Json��ʽ���£�

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
  @brief    �ļ�����֪ͨ	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#string) \n
	Json��ʽ���£�

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
  @brief    ȡ���ļ�����֪ͨ	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#BOOL) \n
	Json��ʽ���£�

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
  @brief    �ļ�����ʧ��֪ͨ
  
	MainBuf(#TImComm_Api) \n
	Json��ʽ���£�

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
  @brief    �ļ��������֪ͨ	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImFileShareProgress_Api) \n
	Json��ʽ���£�

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
  @brief    �����ļ�����·����Ӧ
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#string) \n
	Json��ʽ���£�

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
  @brief   �����֪ͨ
  
	MainBuf(#u32)\n
	SubBuf(#TImGroupInfo_Api) \n
	Json��ʽ���£�

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
  @brief    ɾ����֪ͨ	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImSn_Api) \n
	Json��ʽ���£�

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
  @brief   �޸���֪ͨ
  
	MainBuf(#u32)\n
	SubBuf(#TImGroupInfo_Api) \n
	Json��ʽ���£�

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
  @brief    ��ӳ�Ա֪ͨ	
  
	MainBuf(#u32)\n
	SubBuf(#TImMemberInfo_Api) \n
	Json��ʽ���£�

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
  @brief    ɾ����Ա֪ͨ	
  
	MainBuf(#u32)\n
	SubBuf(#TImSn_Api) \n
	Json��ʽ���£�

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
  @brief    �޸ĳ�Ա֪ͨ	
  
	MainBuf(#u32)\n
	SubBuf(#TImMemberInfo_Api) \n
	Json��ʽ���£�

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
  @brief    �ƶ���Ա֪ͨ	
  
	MainBuf(#u32)\n
	SubBuf(#TImMoveMember_Api) \n
	Json��ʽ���£�

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
  @brief    ����̶�����֪ͨ	
  
	MainBuf(#u32)\n
	SubBuf(#TImMulitChatCreateInfo_Api) \n
	Json��ʽ���£�

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
  @brief    ����̶�����ʧ��֪ͨ
  
	MainBuf(#u32)\n
	SubBuf(#TPersistentChatroomItem_Api)  \n
	Json��ʽ���£�

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
  @brief    ����֪ͨ
  
	MainBuf(#u32)  \n
	Json��ʽ���£�

	@verbatim
	{
		"dwHandle" : 0
	}
  @endverbatim
*/	
	Ev_MtApi_ImDisconnected_Ntf,

/**
  @brief    ֪ͨ���������ע�Լ�	
  
	MainBuf(#u32)\n
	SubBuf(#TImNO_Api) \n
	Json��ʽ���£�

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
  @brief    �����������ļ���Ӧ
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TImGroupChatFileShareReq_Api) \n
	Json��ʽ���£�

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
  @brief    �����ļ��������������Ӧ
  
	MainBuf(#TImComm_Api)  \n
	Json��ʽ���£�

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
  @brief    ������������Ϣ��ȡ��־��Ӧ	
  
	MainBuf(#TImComm_Api)  \n
	Json��ʽ���£�

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
  @brief    ��ʱPUSH ����ĺ���״̬	
  
	MainBuf(#TDeviceOnlineStateCacheList_Api)  \n
	Json��ʽ���£�

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
  @brief    ��Ա����׼�����֪ͨ
  
	MainBuf(#u32)  \n
	*Json��ʽ���£�

	@verbatim
	{
		"dwHandle" : 0
	}
  @endverbatim
*/	
	Ev_MtApi_ImMembersDataReady_Ntf,

/**
  @brief    ��ȡ��Ա״̬Ӧ��
  
	MainBuf(#u32)\n
	SubBuf(#TImNOList_Api) \n
	Json��ʽ���£�

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
  @brief    ��ȡ��Ա״̬֪ͨ
  
	MainBuf(#u32)\n
	SubBuf(#TImUserStateList_Api) \n
	Json��ʽ���£�

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
  @brief    ��ȡ��Ա״̬����֪ͨ	
  
	MainBuf(#u32)\n
	SubBuf(#TImNOList_Api)\n 
	Json��ʽ���£�

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
  @brief    ��ȡ��Ա״̬��չ��Ϣ��Ӧ
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImNOList_Api) \n
	Json��ʽ���£�

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
  @brief   ��ȡ��Ա״̬��չ��Ϣ֪ͨ
  
	MainBuf(#u32)\n
	SubBuf(#TImUserStateListEx_Api) \n
	Json��ʽ���£�

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
  @brief  ��ȡ��Ա״̬��չ��Ϣ����֪ͨ	
  
	MainBuf(#u32)\n
	SubBuf(#TImNOList_Api) \n
	Json��ʽ���£�

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
  @brief    ֪ͨ��ȫ��¼(ͬһ�˺��������ط���¼)
  
	MainBuf(#u32) \n
	Json��ʽ���£�

	@verbatim
	{
         "dwHandle" : 0
	}
  @endverbatim
*/	
	Ev_MtApi_ImNotifySecurity_Ntf,

/**
  @brief    ������Ϣ��֪ͨ	
  
	MainBuf(#tImComm_Api) \n
	Json��ʽ���£�

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
  @brief    ������������Ӧ
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImChatRoomInfo_Api) \n
	Json��ʽ���£�

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
  @brief    ����������֪ͨ
  
	MainBuf(#u32)\n
	SubBuf(#TImChatRoomInfo_Api)\n 
	Json��ʽ���£�

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
  @brief    �ܾ����룬��Ϣ����֪ͨ	
  
	MainBuf(#u32)\n
	SubBuf(#TDeclineInfo_Api)  \n
	Json��ʽ���£�

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
  @brief    �����ҷ�������Ա����֪ͨ
  
	MainBuf(#u32) \n
	SubBuf(#TImMultiChatRosterItemList_Api) \n
	Json��ʽ���£�

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
  @brief    �����ҷ�������Ա����֪ͨ
  
	MainBuf(#u32) \n
	SubBuf(#TImMultiChatRosterItemList_Api)  \n
	Json��ʽ���£�

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
  @brief    �����ҷ������֪ͨ	
  
	MainBuf(#TImComm_Api)  \n
	Json��ʽ���£�

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
  @brief    ������ͼƬ���俪ʼ֪ͨ	
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TMultiChatPicId_Api)  \n
	Json��ʽ���£�

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
  @brief    ������ͼƬ�������֪ͨ	
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TMultiChatPicId_Api)  \n
	Json��ʽ���£�

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
  @brief    ������ͼƬ������ֹ֪ͨ
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TImChatroomPicture_Api)  \n
	Json��ʽ���£�

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
  @brief   ������ͼƬ����ʧ��֪ͨ	
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TMultiChatPicId_Api)  \n
	Json��ʽ���£�

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
  @brief    ��������ӳ�Ա֪ͨ	
  
	MainBuf(#u32) \n
	SubBuf(#TMTImMultiChatAddMemberNtf_Api)  \n
	Json��ʽ���£�

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
  @brief    �����ҳ�Ա״̬����֪ͨ	
  
	MainBuf(#TChatroomMemberCacheList_Api)  \n
	Json��ʽ���£�

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
  @brief    ֪ͨ�ϴε�¼����Ĺ̶���������Ϣ	
  
	MainBuf(#u32) \n
	SubBuf(#TPersistentChatroomList_Api)  \n
	Json��ʽ���£�

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
  @brief    ֪ͨ�ϴε�¼����Ĺ̶���������Ϣ����
  
	MainBuf(#u32)  \n
	Json��ʽ���£�

	@verbatim
	{
		"dwHandle" : 0
	}
  @endverbatim
*/
	Ev_MtApi_ImPersistentChatrooms_Fin_Ntf,

/**
  @brief   �������֮ǰ����Ĺ̶�������	
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TPersistentChatroomList_Api)  \n
	Json��ʽ���£�

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
  @brief    ��֪Im���ϲ�Ӧ�ã���¼��׼����Ӧ��
  
	MainBuf(#TImComm_Api)  \n
	Json��ʽ���£�

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
  @brief    ֪ͨ������׼�����
  
	MainBuf(#u32)  \n
	Json��ʽ���£�

	@verbatim
	{
		"dwHandle" : 0
	}
  @endverbatim
*/	
	Ev_MtApi_ImSetReady_Ntf,

/**
  @brief    ��ѯĳ���³�Ա������״̬(����λ��)Ӧ��
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TImSn_Api) \n
	Json��ʽ���£�

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
  @brief    ��ѯĳ���µ���ϵ���б���Ϣ(����λ��)Ӧ��
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TImSn_Api) \n
	Json��ʽ���£�

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
  @brief    ��֪�Է��Լ��ļ�������״̬Ӧ��(����λ��)Ӧ��
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TImCharState_Api)  \n
	Json��ʽ���£�

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
  @brief    ��ϵ�˼�������״̬֪ͨ
  
	MainBuf(#dwHandler) \n
	SubBuf(#TImCharState_Api)  \n
	Json��ʽ���£�

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
  @brief    ��֪�Է�����Ӧ��
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TImSplash_Api) \n
	Json��ʽ���£�

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
  @brief    ����֪ͨ
  
	MainBuf(#u32) \n
	SubBuf(#TImSplash_Api) \n
	Json��ʽ���£�

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
  @brief   ����/��ȡ�Զ�������Ӧ��
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TImCustomCfg_Api) \n
	Json��ʽ���£�

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
  @brief    �Զ�����������׼����֪ͨ	
  
	MainBuf(#u32)  \n
	Json��ʽ���£�

	@verbatim
	{
		"dwHandle" : 0
	}
  @endverbatim
*/	
	Ev_MtApi_ImConfigDataReady_Ntf,

/**
  @brief   ����������Ӧ��	
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImScreenChatroom_Api) \n
	Json��ʽ���£�

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
  @brief    ��ȡ��������������Ӧ��
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TImScreenedChatrooms_Api)�ɹ� \n
	Json��ʽ���£�

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
	SubBuf(#TImScreenedChatroom_Api)ʧ�� \n
	Json��ʽ���£�
	
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
  @brief    ����������(������)Ӧ��
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TImScreenChatroomR_Api)  \n
	Json��ʽ���£�

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
  @brief    ��ȡ���������в����߳�ԱӦ��
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TRoomId_Api) \n
	Json��ʽ���£�

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
  @brief    ��ȡĳ�˲μӵ���Ƶ����idӦ��
  
	�ɹ�\n
	MainBuf(#TImComm_Api)\n
	SubBuf(#TFriendConferenceInfo_Api) \n
	Json��ʽ���£�

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
	
	ʧ�� \n
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
  @brief    ��ʱ��עĳ��ϵ��Ӧ��
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImNO_Api) \n
	Json��ʽ���£�\n

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
  @brief    ȡ����ʱ��עĳ��ϵ��Ӧ��
  
	MainBuf(#TImComm_Api)\n
	SubBuf(#TImNO_Api) \n
	Json��ʽ���£�\n

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
  @brief    ���������ϵ�˵�һ����Ӧ��	
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TBatchAddContacts_Api)  \n
	Json��ʽ���£�

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
  @brief    ����ɾ����ϵ��Ӧ��	
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TBatchDelContacts_Api)  \
	Json��ʽ���£�

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
  @brief    �����ƶ���ϵ��Ӧ��	
  
	MainBuf(#TImComm_Api) \n
	SubBuf(#TBatchMoveContacts_Api)  \n
	Json��ʽ���£�

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
  @brief    ��ȡ������ʱ��Ӧ��	
  
	MainBuf(#TImComm_Api)  \n
	Json��ʽ���£�

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
  @brief   ��ѯ�û���Ϣ֪ͨ	
  
	�ɹ� \n
	MainBuf(#TRestErrorInfo_Api) \n
	SubBuf(#TMTWbParse_Keda_EntUser_Api) \n
	Json��ʽ���£�

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
	
	ʧ�� \n
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
  @brief    �Ͽ����з�����֪ͨ
  
	MainBuf(#u32)  \n
	Json��ʽ���£�

	@verbatim
	{
		"dwHandle" : 0
	}
  @endverbatim
*/	
	Ev_MtApi_ImUserDisconnect_Ntf,

/**
  @brief    �Զ��������޸�֪ͨ
  
	MainBuf(#u32)\n
	SubBuf(#TImCustomCfgItem_Api) \n
	Json��ʽ���£�

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
  @brief    ��ȡ��֯�ܹ�״̬��Ӧ
  
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
  @brief    ��ȡ�̶���������Ӧ
  
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
