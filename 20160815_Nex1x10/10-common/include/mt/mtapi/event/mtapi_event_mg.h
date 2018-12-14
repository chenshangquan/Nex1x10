/*******************************************************************************//**
*@file          mtapi_event_mg.h
*@brief         ʵ��MTAPI MtMeetingMgrSdk ��UI(�۲���)�¼�֪ͨ�Ķ���
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_EVENT_MG_H_
#define _MTAPI_EVENT_MG_H_
/**@addtogroup event �¼�
*@{
*/

/**@addtogroup mgevent ����¼�
*@{
*/

#include "mtapi_event_def.h"


enum EmMtApiMGEv
{
	EV_UI_BGN(MTAPI_MG)  = EVSEG_MTAPI_MG_BGN,

	
/**
  @brief    ��ȡ�����б���Ӧ
  
	MainBuf(#TMgErrKeyPair_Api) \n
	SubBuf(#TMTMeetingLists_Api) 
	Json��ʽ���£�

  @verbatim
	{
		"MainParam":
		{
			"tMgErrKeyPair_Api": {
				"dwKey": 1,
					"tErrInfo": {
						"achErrorInfo": "",
							"eApiType": 1,
							"dwErrorID": 1,
							"dwNackEventId": 1,
							"adwParams": [
						{
							"basetype": 1
						},
						{
							"basetype": 1
							},
							{
								"basetype": 1
							},
							{
								"basetype": 1
								}
							]
				}
			}
		},
		"AssParam": 
		{
			"tMTMeetingLists_Api": {
				"tRelatedRooms": {
					"nCount": 0,
        			"atItems": {
			            "nID": 0,
            			"achname": "",
 			           "achRegionName": ""
			        }
			    },
			    "tMeetings": {
			        "nCount": 0,
			        "atItems": {
 			           "nID": 0,
 			           "achSubject": "",
  			          "achStartTime": "",
  			          "achEndTime": "",
  			          "achOrganizerMoid": "",
  			          "nStatus": 0,
   			         "nIsVideoMeeting": 0,
    			        "emFeedbackStatus": 0,
    			        "nRegularID": 0,
    			        "tRoomIDs": {
    			            "nCount": 0,
     			           "anItems": [
     			               0,
    			                0
    			            ]
    			        }
    			    }
   				}
			}
		}
	}
  @endverbatim
*/
	
	Ev_MtApi_RestGetMeetingList_Rsp,

/**
  @brief    ��ȡ������ϸ��Ϣ��Ӧ	
  
	MainBuf(#TRestErrorInfo_Api) \n
	SubBuf(#TMTConfInfoById_Api) \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam":
		{
			"tRestErrorInfo_Api": {
				"achErrorInfo": "",
    			"eApiType": 0,
    			"dwErrorID": 0,
   				"dwNackEventId": 0,
    			"adwParams": [
        				0,
        				0
    				]
				}
		},
		"AssParam": 
		{
			"tMTConfInfoById_Api": {
				"dwId": 1,
				"dwStatus": 1,
				"dwIsVideo": 1,
				"achSubject": "",
				"achStartTime": "",
				"achEndTime": "",
				"achOrganizerMoid": "",
				"achOrganizer": 1,
				"achOrganizerMail": "",
				"achPhone": "",
				"achMobile": "",
				"achBrief": "",
				"m_tMTConfInfoRooms": {
					"m_tMTRoomInfo": [
					{
						"dwId": 1,
						"achName": "",
						"achRegionName": ""
					},
					{
						"dwId": 1,
						"achName": "",
						"achRegionName": ""
					}
				]
				},
				"m_tMTVideoConfInfo": {
					"dwShortNO": 1,
					"dwState": 1,
					"dwIsAutoCall": 1,
					"achE164": "",
					"achTemplate_id": "",
					"achTemplate_name": "",
                    "achPassword": "",
                    "emMeetingSafe" : 1,
                    "emEncryptedType" : 1,
                    "achEncryptedKey" : "str",
                    "emMeetingType" : 1,
                    "emClosedMeeting" : 1,
                    "emVideoQuality" : 1,
                    "emDualMode" : 1,
                    "bInitMute" : true,
                    "bPublicMeeting" : true,
                    "dwMeetingScale": 0,
                    "dwOneReforming": 0,
                    "dwVideoCount" : 1,
                    "atVideoFormatList" : [
                    {
                    "emVideoFormat" : 1,
                    "emVideoProfile" : 1,
                    "emResolution" : 1,
                    "dwFrame" : 1,
                    "dwRate" : 1
                    }
                    ],
                    "dwAudioCount" : 1,
                    "atAudioFormatList" : [
                    {
                    "emAudioFormat" : 1,
                    "emAaccnnlNum" : 1
                    }
                    ],
                    "dwDualCount" : 1,
                    "atDualFormatList" : [
                    {
                    "dwFrame" : 1,
                    "emResolution" : 1,
                    "emVideoFormat" : 1
                    }
                    ],
                    "tMixInfo" : 
                    {
                    "bEnable" : false,
                    "emMode" : 0,
                    "atMixMemberList" : [
                    {
                    "achName" : "str",
                    "achAccount" : "",
                    "emAccountType" : 0
                    }
                    ]
                    }
                    "tVmp" : 
                    {
                    "bEnable" : true,
                    "emStyle" : 1,
                    "bVoiceHint" : true,
                    "bShowMTName" : true,
                    "bIsBroadcast" : false,
                    "dwMemberCount" : 1,
                    "atMemberList" : [
                    {
                    "achName" : "str",
                    "achAccount" : "str",
                    "emAccountType" : 1,
                    "emFollowType" : 1,
                    "dwIndex" : 1
                    }
                    ]
                    },
                    "tPoll" : 
                    {
                    "bEnable" : true,
                    "dwNum" : 1,
                    "dwInterval" : 1,
                    "bSpeaker" : true,
                    "dwMemberCount" : 1,
                    "atMemberList" : [
                    {
                    "achName" : "str",
                    "achAccount" : "str",
                    "emAccountType" : 1
                    }
                    ]
                    },
                    "dwVipCount" : 1,
                    "atVipList" : [
                    {
                    "achName" : "str",
                    "achAccount" : "str",
                    "emAccountType" : 1
                    }
                    ],
                    "tSpeaker" :
                    {
                    "achName" : "str",
                    "achAccount" : "str",
                    "emAccountType" : 1
                    },
                    "tAdmin" : {
                    "achName" : "str",
                    "achAccount" : "str",
                    "emAccountType" : 1
                    },
                    "dwCallTimes" : 1,
                    "dwCallInterval" : 1,
                    "bCallChase" : true,
                    "bVoiceInspireEnable" : true,
                    "dwVoiceInspireTime": 0
                    "emCascadeMode" : 1,
                    "bCascadeUpload" : true,
                    "bCascadeReturn" : true,
                    "dwCascadeReturnPara" : 1,
                    "tRecord" : {
                    "bDoubleFlow" : true, 
                    "bEnable" : true,
                    "bMain" : true,
                    "bPublish" : true
                    },
                    "tMultiCast" : {
                    "achMulticastAddr" : "str",
                    "bEnable" : true,
                    "dwPort" : 1
                    },
                    "tSatellite" : {
                    "bEnable" : true,
                    "achMulticastAddr" : "str",
                    "dwPort" : 1,
                    "dwReturnNum" : 1
                    },
                    "dwCallChaseMemberCount" : 1,
                    "atCallChaseList" : [
                    {
                    "achName" : "str",
                    "achAccount" : "str",
                    "emAccountType" : 1
                    }
                    ]
					}
				}
			}
		}
  @endverbatim
*/	
	Ev_MtApi_RestGetMeetingInfo_Rsp,

/**
  @brief    ��ȡ�����������Ϣ��Ӧ
  
	MainBuf(#TMTConfInfoParticipants_Api) \n
	Json��ʽ���£�

  @verbatim
	{
	    "dwParticipantCount": 0,
		"achConfE164": "",
	    "tMTParticipantInfo": {
		    "achMoId": "",
			"achEmail": "",
	        "achName": "",
		    "achParticipantNo": "",
			"dwIsParticipant": 0,
	        "dwParticipantType": 0
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestGetParticipants_Rsp,

/**
  @brief    ��ȡ�����������Ϣ������Ӧ
*/	
	Ev_MtApi_RestGetParticipants_Fin_Rsp,

/**
  @brief    ��ȡ������Ԥ����ϢӦ��	
  
	MainBuf(#TMgErrKeyPair_Api) \n
	SubBuf(#TMTMeetingLists_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam":
		{
			"tMgErrKeyPair_Api": {
				"dwKey": 1,
					"tErrInfo": {
						"achErrorInfo": "",
							"eApiType": 1,
							"dwErrorID": 1,
							"dwNackEventId": 1,
							"adwParams": [
						{
							"basetype": 1
						},
						{
							"basetype": 1
							},
							{
								"basetype": 1
							},
							{
								"basetype": 1
								}
							]
				}
			}
		},
		"AssParam": 
		{
			"tMTMeetingLists_Api": {
				"tRelatedRooms": {
					"nCount": 0,
        			"atItems": {
			            "nID": 0,
            			"achname": "",
 			           "achRegionName": ""
			        }
			    },
			    "tMeetings": {
			        "nCount": 0,
			        "atItems": {
 			           "nID": 0,
 			           "achSubject": "",
  			          "achStartTime": "",
  			          "achEndTime": "",
  			          "achOrganizerMoid": "",
  			          "nStatus": 0,
   			         "nIsVideoMeeting": 0,
    			        "emFeedbackStatus": 0,
    			        "nRegularID": 0,
    			        "tRoomIDs": {
    			            "nCount": 0,
     			           "anItems": [
     			               0,
    			                0
    			            ]
    			        }
    			    }
   				}
			}
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestGetBookingInfo_Rsp,


/**
  @brief    ��ȡ������Ԥ����ϢӦ��
  

  MainBuf(#TMgErrKeyPair_Api)\n
  SubBuf(#TMTMeetingLists_Api) \n 
	Json��ʽ���£�

  @verbatim
	{
		"MainParam":
		{
			"tMgErrKeyPair_Api": {
				"dwKey": 1,
					"tErrInfo": {
						"achErrorInfo": "",
							"eApiType": 1,
							"dwErrorID": 1,
							"dwNackEventId": 1,
							"adwParams": [
						{
							"basetype": 1
						},
						{
							"basetype": 1
							},
							{
								"basetype": 1
							},
							{
								"basetype": 1
								}
							]
				}
			}
		},
		"AssParam": 
		{
			"tMTMeetingLists_Api": {
				"tRelatedRooms": {
					"nCount": 0,
        			"atItems": {
			            "nID": 0,
            			"achname": "",
 			           "achRegionName": ""
			        }
			    },
			    "tMeetings": {
			        "nCount": 0,
			        "atItems": {
 			           "nID": 0,
 			           "achSubject": "",
  			          "achStartTime": "",
  			          "achEndTime": "",
  			          "achOrganizerMoid": "",
  			          "nStatus": 0,
   			         "nIsVideoMeeting": 0,
    			        "emFeedbackStatus": 0,
    			        "nRegularID": 0,
    			        "tRoomIDs": {
    			            "nCount": 0,
     			           "anItems": [
     			               0,
    			                0
    			            ]
    			        }
    			    }
   				}
			}
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestGetMeetingListOfPerson_Rsp,

/**
  @brief    ��������Ӧ��	
  
	MainBuf(#TMgErrKeyPair_Api) \n
	SubBuf(#u32) \n
	Json��ʽ���£�

  @verbatim
	{
		"dwKey": 1,
			"tErrInfo": {
				"achErrorInfo": "",
					"eApiType": 1,
					"dwErrorID": 1,
					"dwNackEventId": 1,
					"adwParams": [
				{
					"basetype": 1
				},
				{
					"basetype": 1
					},
					{
						"basetype": 1
					},
					{
						"basetype": 1
						}
					]
			}
	}
  @endverbatim
*/	
	Ev_MtApi_RestAddMeeting_Rsp,


/**
  @brief    �޸Ļ���Ӧ��	
  
	MainBuf(#TMgErrKeyPair_Api) \n
	SubBuf(#u32) \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam" :
		{
			"dwKey": 1,
			"tErrInfo": {
				"achErrorInfo": "",
				"eApiType": 1,
				"dwErrorID": 1,
				"dwNackEventId": 1,
				"adwParams": [
				{
					"basetype": 1
				},
				{
					"basetype": 1
				},
				{
					"basetype": 1
				},
				{
					"basetype": 1
				}
				]
			}
		},
		"AssParam" :
		{
			"basetype" : 0  //meetingid
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestModifyMeeting_Rsp,

/**
  @brief    ɾ������Ӧ��	
  
	MainBuf(#TMgErrKeyPair_Api) \n
	SubBuf(#u32) \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam" :
		{
			"dwKey": 1,
			"tErrInfo": {
				"achErrorInfo": "",
				"eApiType": 1,
				"dwErrorID": 1,
				"dwNackEventId": 1,
				"adwParams": [
				{
					"basetype": 1
				},
				{
					"basetype": 1
				},
				{
					"basetype": 1
				},
				{
					"basetype": 1
				}
				]
			}
		},
		"AssParam" :
		{
			"basetype" : 0  //meetingid
		}
	}
  @endverbatim
*/	
	Ev_MtApi_DeleteMeeting_Rsp,

/**
  @brief    ��ʼ����Ӧ��	
  
	MainBuf(#TMgErrKeyPair_Api) \n
	SubBuf(#u32) \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam" :
		{
			"dwKey": 1,
			"tErrInfo": {
				"achErrorInfo": "",
				"eApiType": 1,
				"dwErrorID": 1,
				"dwNackEventId": 1,
				"adwParams": [
				{
					"basetype": 1
				},
				{
					"basetype": 1
				},
				{
					"basetype": 1
				},
				{
					"basetype": 1
				}
				]
			}
		},
		"AssParam" :
		{
			"basetype" : 0  //meetingid
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestStartMeeting_Rsp,

/**
  @brief    ��������Ӧ��	
  
	MainBuf(#TMgErrKeyPair_Api) \n
	SubBuf(#u32) \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam" :
		{
			"dwKey": 1,
			"tErrInfo": {
				"achErrorInfo": "",
				"eApiType": 1,
				"dwErrorID": 1,
				"dwNackEventId": 1,
				"adwParams": [
				{
					"basetype": 1
				},
				{
					"basetype": 1
				},
				{
					"basetype": 1
				},
				{
					"basetype": 1
				}
				]
			}
		},
		"AssParam" :
		{
			"basetype" : 0  //meetingid
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestEndMeeting_Rsp,

/**
  @brief    ��������Ӧ��	
  
	MainBuf(#TRestErrorInfo_Api) \n
	SubBuf(#TMTMeetingFeed_Api)  \n
	Json��ʽ���£�
  @verbatim
	{
		"MainParam":
		{
			"tRestErrorInfo_Api": {
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
			}
		},
		"AssParam": 
		{
			"tMTMeetingFeed_Api": {
				"dwMeetingId": 0,
    			"dwAccept": 0,
    			"dwJoinType": 0,
    			"dwReasonId": 0,
    			"achParticipateNo": ""
			}
		}
  @endverbatim
*/	
	Ev_MtApi_RestMeetingFeed_Rsp,

/**
  @brief    ��ȡ���л�����Ӧ��	
  
	MainBuf(#TMgErrKeyPair_Api) \n
	SubBuf(#TMTRoomList_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam":
		{
			"tMgErrKeyPair_Api": {
				"dwKey": 1,
					"tErrInfo": {
						"achErrorInfo": "",
							"eApiType": 1,
							"dwErrorID": 1,
							"dwNackEventId": 1,
							"adwParams": [
						{
							"basetype": 1
						},
						{
							"basetype": 1
							},
							{
								"basetype": 1
							},
							{
								"basetype": 1
								}
							]
				}
			}
		},
		"AssParam": 
		{
			"tMTRoomList_Api": {
				"tRooms": {
				"nCount": 0,
				"atItems": {
					"nID": 0,
					"nPeopleAdmit": 0,
					"nDeviceMask": 0,
					"achName": "",
					"achRegionName": "",
					"achStartTime": "",
					"achEndTime": ""
					}
				},
				"dwTotal": 0
			}
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestQueryFreeRooms_Rsp,

	Ev_MtApi_RestQueryFreeRoomsFin_Rsp,


/**
  @brief    ��ȡ�Ƽ������������Ӧ��
  
	MainBuf(#TMgErrKeyPair_Api) \n
	SubBuf(#u32)  \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam" :
		{
		"dwKey": 1,
			"tErrInfo": {
			"achErrorInfo": "",
				"eApiType": 1,
				"dwErrorID": 1,
				"dwNackEventId": 1,
				"adwParams": [
				{
					"basetype": 1
				},
				{
					"basetype": 1
				},
				{
					"basetype": 1
				},
				{
					"basetype": 1
				}
				]
			}
		},
		"AssParam" :
		{
			"basetype" : 0 //roomid
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestGetRecommendedVirtualRoom_Rsp,


/**
  @brief    ��ȡ�����Ļ�����Ӧ��	
  
	MainBuf(#TMgErrKeyPair_Api) \n
	SubBuf(#TMTNormalRoomList_Api )  \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam":
		{
			"tMgErrKeyPair_Api": {
				"dwKey": 1,
					"tErrInfo": {
						"achErrorInfo": "",
							"eApiType": 1,
							"dwErrorID": 1,
							"dwNackEventId": 1,
							"adwParams": [
						{
							"basetype": 1
						},
						{
							"basetype": 1
							},
							{
								"basetype": 1
							},
							{
								"basetype": 1
								}
							]
				}
			}
		},
		"AssParam": 
		{
			"tMtNormalRoomList_Api": {
				"dwStart": 0,
    			"dwCount": 0,
    			"tRooms": {
        			"nCount": 0,
        			"atItems": {
            			"nID": 0,
            			"achname": "",
            			"achRegionName": ""
        			}
    			}
			}
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestGetNormalRooms_Rsp,


/**
  @brief    �����Ļ���������֪ͨ	
  
	MainBuf(#u32) \n
	SubBuf(#u32)  \n
	Json��ʽ���£�

	@verbatim
	{
		"MainParam":
		{
			"basetype": 0
		},
		"AssParam": 
		{
			"basetype": 0
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestGetNormalRoomsIndex_Ntf,


/**
  @brief    �����Ļ�������������֪ͨ	
  
	MainBuf(#u32) \n
	SubBuf(#u32)  \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam":
		{
			"basetype": 0
		},
		"AssParam": 
		{
			"basetype": 0
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestGetNormalRooms_Fin_Ntf,

/**
  @brief    ����Id��ȡ������Ӧ��	
  
	MainBuf(#TMgErrKeyPair_Api) \n
	SubBuf(#TMTRoomInfo_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam":
		{
			"tMgErrKeyPair_Api": {
				"dwKey": 1,
					"tErrInfo": {
						"achErrorInfo": "",
							"eApiType": 1,
							"dwErrorID": 1,
							"dwNackEventId": 1,
							"adwParams": [
						{
							"basetype": 1
						},
						{
							"basetype": 1
							},
							{
								"basetype": 1
							},
							{
								"basetype": 1
								}
							]
				}
			}
		},
		"AssParam": 
		{
			"tMTRoomInfo_Api": {
				"dwId": 0,
				"achName": "",
				"achRegionName": ""
			}
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestGetRoomInfo_Rsp,

/**
  @brief    ������������������Ӧ��	
  
	MainBuf(#TMgErrKeyPair_Api) \n
	SubBuf(#TMTShortRooms_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam":
		{
			"tMgErrKeyPair_Api": {
				"dwKey": 1,
					"tErrInfo": {
						"achErrorInfo": "",
							"eApiType": 1,
							"dwErrorID": 1,
							"dwNackEventId": 1,
							"adwParams": [
						{
							"basetype": 1
						},
						{
							"basetype": 1
							},
							{
								"basetype": 1
							},
							{
								"basetype": 1
								}
							]
				}
			}
		},
		"AssParam": 
		{
			"tMtShortRooms_Api": {
				"nCount": 0,
				"atItems": {
					"nID": 0,
					"achname": "",
					"achRegionName": ""
				}
			}
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestGetRoomListByName_Rsp,

/**
  @brief    �����������������ҽ���֪ͨ	
  @verbatim
	BODY: ��
  @endverbatim
*/	
	Ev_MtApi_RestGetRoomListByName_Fin_Ntf,

/**
  @brief  ���ݻ�������Դ����������Ӧ��
  
	MainBuf(#TMgErrKeyPair_Api) \n
	SubBuf(#TMTShortRooms_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam":
		{
			"tMgErrKeyPair_Api": {
				"dwKey": 1,
					"tErrInfo": {
						"achErrorInfo": "",
							"eApiType": 1,
							"dwErrorID": 1,
							"dwNackEventId": 1,
							"adwParams": [
						{
							"basetype": 1
						},
						{
							"basetype": 1
							},
							{
								"basetype": 1
							},
							{
								"basetype": 1
								}
							]
				}
			}
		},
		"AssParam": 
		{
			"tMtShortRooms_Api": {
				"nCount": 0,
				"atItems": {
					"nID": 0,
					"achname": "",
					"achRegionName": ""
				}
			}
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestQueryRooms_Rsp,


/**
  @brief    ��ȡ����ģ���б�Ӧ��	
  
	MainBuf(#TMgErrKeyPair_Api) \n
	SubBuf(#TMTTemplateList_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam":
		{
			"tMgErrKeyPair_Api": {
				"dwKey": 1,
					"tErrInfo": {
						"achErrorInfo": "",
							"eApiType": 1,
							"dwErrorID": 1,
							"dwNackEventId": 1,
							"adwParams": [
						{
							"basetype": 1
						},
						{
							"basetype": 1
							},
							{
								"basetype": 1
							},
							{
								"basetype": 1
								}
							]
				}
			}
		},
		"AssParam": 
		{
			"tMtTemplateList_Api": {
				"tTemplates": {
        			"nCount": 0,
        			"atItems": {
            			"achTemplateID": "",
            			"achTemplateName": ""
        				}
    				}
				}
			}
		}
	}
  @endverbatim
*/
	Ev_MtApi_RestGetTemplateList_Rsp,

/**
  @brief   ��ȡ����ģ���б�Ӧ��
  
	MainBuf(#TMgErrKeyPair_Api) \n
	SubBuf(#TMTTemplateInfo_Api)  \n
	Json��ʽ���£�
	
  @verbatim
	{
		"MainParam":
		{
			"tMgErrKeyPair_Api": {
				"dwKey": 1,
					"tErrInfo": {
						"achErrorInfo": "",
							"eApiType": 1,
							"dwErrorID": 1,
							"dwNackEventId": 1,
							"adwParams": [
						{
							"basetype": 1
						},
						{
							"basetype": 1
							},
							{
								"basetype": 1
							},
							{
								"basetype": 1
								}
							]
				}
			}
		},
		"AssParam": 
		{
			"tMtTemplateInfo_Api": {
				"achTemplateID": "",
				"achTemplateName": "",
				"achTemplateResolution": "",
				"achBandwidth": "",
				"tPersons": {
					"atItems": [
						{
							"TMTPerson_Api": {
								"achMoId": "",
								"achEmail": "",
								"achName": "",
								"achParticipantNo": "",
								"bIsParticipant": 0,
								"dwParticipantType": 1
								}
							}
						]
					}
				}
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestGetTemplateInfo_Rsp,

/**
  @brief   ��ȡ����ģ����Ϣ����֪ͨ	
  
	MainBuf(#u32)  \n
	Json��ʽ���£�

  @verbatim
	{
			"basetype": 0
	}
  @endverbatim
*/	
	Ev_MtApi_RestGetTemplateInfo_Fin_Ntf,

/**
  @brief    ��������֪ͨӦ��	
  
	MainBuf(#TMgErrKeyPair_Api) \n
	SubBuf(#u32) \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam" :
		{
			"dwKey": 1,
			"tErrInfo": 
			{
				"achErrorInfo": "",
				"eApiType": 1,
				"dwErrorID": 1,
				"dwNackEventId": 1,
				"adwParams": [
				{
					"basetype": 1
				},
				{
					"basetype": 1
				},
				{
					"basetype": 1
				},
				{
					"basetype": 1
				}
				]
			}
		},
		"AssParam" : 
		{
			"basetype" : 0 //meetingid
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestCreateMeetingNotify_Rsp,


/**
  @brief   ��ȡ��ҵ�����������Ӧ��
  
	MainBuf(#TRestErrorInfo_Api) \n
	SubBuf(#s8)  \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam":
		{
			"tRestErrorInfo_Api": {
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
			}
		},
		"AssParam": 
		{
			"strDeadLine": ""
		}
  @endverbatim
*/	
	Ev_MtApi_RestGetMeetingDeadLine_Rsp,

/**
  @brief    ����������Ӧ��	
  
	MainBuf(#TRestErrorInfo_Api) \n
	SubBuf(#s8) \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam":
		{
			"tRestErrorInfo_Api": {
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
			}
		},
		"AssParam": 
		{
			"strMeetingFormKey": ""
		}
  @endverbatim
*/	
	Ev_MtApi_RestLockRoom_Rsp,

/**
  @brief    �������ͻ�ȡ֪ͨ��Ӧ	
  
	MainBuf(#TRestErrorInfo_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
	}
  @endverbatim
*/	
	Ev_MtApi_RestGetListNotifysByNType_Rsp,


/**
  @brief    ����ID��ȡ֪ͨӦ��  ��������¶����һ���ṹ��
  
	MainBuf(#TGetNotifyById_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam" :
		{
			......//MainBuf����
		},
		"AssParam" :
		{
			......//SubBuf���ݣ�����tGetNotifyById_Api.tConfInfo.dwMessgaeType����ֵ���жϵ�ǰ������
		}
	}
	@endverbatim
	MainBuf��Json��ʽ�� \n
	@verbatim
	{
		"tErrInfo": 
		{
			"achErrorInfo": "",
			"emApiType": 0,
			"dwErrorID": 0,
			"dwNackEventId": 0,
			"adwParams": [
			{
				"basetype" : 0,
				"basetype" : 0,
				"basetype" : 0,
				"basetype" : 0
			}
			]
		},
		"tConfInfo:
		{
			"dwId": 0,
			"achReceiverMoId": "",
			"dwMessgaeType": 0,
			"achCompanyMoId": "",
			"achCreateTime" : ""
	    }
	}
	@endverbatim

	������ӵ�����һ���ṹ�壬����tGetNotifyById_Api.tConfInfo.dwMessgaeType����ֵ���жϣ� \n
	102������� \n
	SubBuf(TMTContentCreateMeeting_Api) \n
	Json��ʽ��\n
	@verbatim
	{
		"dwMeetingId" : 0,
		"achSubject" : "",
		"achStartTime" : "",
		"achEndTime" : "",
		"bIsVideoMeeting" : false,
		"achPhone" : "",
		"achMobilePhone" : "",
		"achOrganizer" : "",
		"achOrganigerMoid" : "",
		"tMTConfInfoRooms" : {
			"atMTRoomInfo": [
			{
				"dwId": 1,
					"achName": "",
					"achRegionName": ""
			}
			]
		}
	}
	@endverbatim
	
	103������� \n
	SubBuf(TMTContentUpdateMeeting_Api) \n
	Json��ʽ�� \n
	@verbatim 
	{
		"dwMeetingId" : 0,
		"achSubject" : "",
		"achStartTime" : "",
		"achEndTime" : "",
		"achOrganigerMoid" : "",
		"achBrief" : "",
		"achBeforeSubject" : "",
		"tMTConfInfoRooms" : {
			"atMTRoomInfo": [
			{
				"dwId": 1,
					"achName": "",
					"achRegionName": ""
			}
			]
		}
	}
	@endverbatim

	104��108��116������� \n
	SubBuf(TMTContentOutMeeting_Api) \n
	Json��ʽ�� \n
	@verbatim
	{
		"dwMeetingId" : 0,
		"achSubject" : "",
		"achOrganigerMoid" : ""
	}
	@endverbatim

	110������� \n
	SubBuf(TMTContentNotStartMeeting_Api) \n
	Json��ʽ \n
	@verbatim
	{
		"dwMeetingId" : "",
		"achSubject" : "",
		"achStartTime" : "",
		"achEndTime" : "",
		"achOrganigerMoid" : "",
		"tMTConfInfoRooms" : {
			"atMTRoomInfo": [
			{
				"dwId": 1,
					"achName": "",
					"achRegionName": ""
			}
			]
		}
	}
	@endverbatim

	111������� \n
	SubBuf(TMTContentDeadlineChanged_Api) \n
	Json��ʽ�� \n
	@verbatim
	{
		"achDeadline" : ""
	}
	@endverbatim

	105������� \n
	SubBuf(TMTContentRegularMeeting_Api) \n
	Json��ʽ \n
	@verbatim
	{
		"dwRegularId" : 0,
		"achOrganizerMoid" : "",
		"achSubject" : "",
		"achOrganizerMail" : "",
		"achOrganizer" : "",
		"achPhone" : "",
		"achBrief" : "",
		"dwStatus" : 0,
		"achMobilePhone" : "",
		"bIsVideoMeeting" : false,
		"achStartTime" : "",
		"achEndTime" : "",
		"achStartDate" : "",
		"dwRepeatType" : 0,
		"dwFrequency" : 0,
		"achWeekDays" : "",
		"achEndDate" : "",
		"adwMeetingId" : [
		{
		    "basetype" : 0
		}
		]
	}
	@endverbatim

	106��107�����: \n
	SubBuf(TMTContentRegularId_Api) \n
	Json��ʽ�� \n
	@verbatim
	{
		"dwRegularId" : 0
	}
	@endverbatim

	112������� \n
	SubBuf(TMTContentFeedback_Api) \n
	Json��ʽ�� \n
	@verbatim
	{
		"dwMeetingId" : 0,
		"achMoid" : "",
		"emIsParticipated" : 0,
		"dwParticipateType" : 0,
		"dwReasonId" : 0,
		"bIsVideoMeeting" : false
	}
	@endverbatim

	113��114������� \n 
	SubBuf(TMTContentRoomId_Api) \n
	Json��ʽ�� \n
	@verbatim
	{
		"dwRoomId" : 0
	}
	@endverbatim
	
	109������� \n
	SubBuf(TMTContentMeetingId_Api) \n
	Json��ʽ�� \n
	{
		"dwMeetingId" : 0
	}

	115��117��118��119�������\n
	SubBuf(TMTContentStartMeeting_Api) \n
	Json��ʽ�� \n
	@verbatim
	{
		"dwMeetingId" : 0,
		"achSubject" : "",
		"achStartTime" : "",
		"achEndTime" : "",
		"achOrganizerMoid" : ""
	}

  @endverbatim
*/	
	Ev_MtApi_RestGetNotifyById_Rsp,

/**
  @brief    IfExistLockByFormkeyӦ��
  
	MainBuf(#TRestErrorInfo_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
	}
  @endverbatim
*/	
	Ev_MtApi_IfExistLockByFormkey_Rsp,

/**
  @brief    ɾ���Ѷ�������Ӧ��	
  
	MainBuf(#TRestErrorInfo_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
	}
  @endverbatim
*/	
	Ev_MtApi_DeleteBookedRoom_Rsp,

/**
  @brief    GetRegularӦ��(���ᣩ
  
	MainBuf(#TMgErrKeyPair_Api) \n
	SubBuf(#TMTRegularInfo_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam":
		{
			"tMgErrKeyPair_Api": {
				"dwKey": 1,
					"tErrInfo": {
						"achErrorInfo": "",
							"eApiType": 1,
							"dwErrorID": 1,
							"dwNackEventId": 1,d
							"adwParams": [
						{
							"basetype": 1
						},
						{
							"basetype": 1
							},
							{
								"basetype": 1
							},
							{
								"basetype": 1
								}
							]
				}
			}
		},
		"AssParam": 
		{
			"tMtRegularInfo_Api": {
				"dwId": 1,
				"achSubject": "",
				"achStartTime": "",
				"achEndTime": "",
				"dwStatus": 1,
				"achOrganizer": "",
				"achOrganizerMail": "",
				"achPhone": "",
				"achMobile": "",
				"achBrief": "",
				"dwIsVideo": 1,
				"achStartDate": "",
				"achEndDate": "",
				"dwRepeatType": 1,
				"dwFrequency": 1,
				"achWeekDays": "",
				"tMeetingIDs": {
					"adwItems": [
					{
						"basetype": 1
					},
					{
						"basetype": 1
						}
					]
				}
			}
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestGetRegular_Rsp,

/**
  @brief   �������Ӧ��	
  
	MainBuf(#TRestErrorInfo_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
	}
  @endverbatim
*/	
	Ev_MtApi_RestMeetingUnlock_Rsp,

/**
  @brief    ���ᷴ��Ӧ��	
  
	MainBuf(#TRestErrorInfo_Api) \n
	SubBuf(#TRegularFeedAck_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam":
		{
			"tRestErrorInfo_Api": {
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
			}
		},
		"AssParam": 
		{
			"TRegularFeedAck_Api": {
				"dwRegularId": 1,
				"dwJoinType": 1,
				"bAccept": 1
			}
		}
  @endverbatim
*/	
	Ev_MtApi_RestMeetingRegularFeed_Rsp,


/**
  @brief    ��ȡ�û�������ҵ���п��õĻ���������Ӧ��
  
	MainBuf(#TRestErrorInfo_Api) \n
	SubBuf(#TMTRegions_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam":
		{
			"tRestErrorInfo_Api": {
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
			}
		},
		"AssParam": 
		{
			"tMTRegions_Api": {
				"achCompanyId": "",
					"atItems": [
					{
						"dwId": 1,
						"achName": ""
					}
					]
			}
		}
  @endverbatim
*/	
	Ev_MtApi_RestQueryMeetingRegions_Rsp,

/**
  @brief    ��ȡ�û�������ҵ���п��õĻ������������Ӧ��
  @verbatim
	BODY: ��
  @endverbatim
*/	
	Ev_MtApi_RestQueryMeetingRegions_Fin_Rsp,

/**
  @brief    ��������������Ӧ��
  
	MainBuf(#TMgErrKeyPair_Api) \n
	SubBuf(#TMTRoomLockResultItems_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam":
		{
			"tMgErrKeyPair_Api": {
				"dwKey": 1,
					"tErrInfo": {
						"achErrorInfo": "",
							"eApiType": 1,
							"dwErrorID": 1,
							"dwNackEventId": 1,
							"adwParams": [
						{
							"basetype": 1
						},
						{
							"basetype": 1
							},
							{
								"basetype": 1
							},
							{
								"basetype": 1
								}
							]
				}
			}
		},
		"AssParam": 
		{
			"tMTRoomLockResultItems_Api": {
				"dwSuccess": 1,
				"achMeetingFormkey": "",
				"achStartTime": "",
				"achEndTime": "",
				"atItems": [
					{
						"dwId": 1,
						"dwResult": 1,
						"achName": ""
					}
				]
			}
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestLockMeetingRooms_Rsp,
	
/**
  @brief    ������������������Ӧ��
  
	BODY: ��
  @endverbatim
*/	
	Ev_MtApi_RestLockMeetingRooms_Fin_Rsp,

/**
  @brief    ������ʼ����Ӧ��
  
	MainBuf(#TRestErrorInfo_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
	}
  @endverbatim
*/	
	Ev_MtApi_RestStartMeetingNow_Rsp,
	
/**
  @brief   ������Ϣ֪ͨ
  
	MainBuf(#u32) \n
	SubBuf(#TMeetingNotify_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam":
		{
			"basetype": 0
		},
		"AssParam": 
		{
			"tMeetingNotify_Api": {
				"emNotifyType": 1,
				"achMoId": "",
				"dwNotifyId": 1,
				"dwNum": 1
			}
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestMeeting_Ntf,
	
/**
  @brief    ����֪ͨ�������֪ͨӦ��
  
	MainBuf(#TMgErrKeyPair_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
		"dwKey": 1,
		"tErrInfo": 
		{
			"achErrorInfo": "",
			"eApiType": 1,
			"dwErrorID": 1,
			"dwNackEventId": 1,
			"adwParams": [
			{
				"basetype": 1
			},
			{
				"basetype": 1
			},
			{
				"basetype": 1
			},
			{
				"basetype": 1
			}
			]
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestAppClearNotify_Rsp,
	
/**
  @brief    �����������֪ͨӦ��
  
	MainBuf(#TRestErrorInfo_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
	}
  @endverbatim
*/	
	Ev_MtApi_RestAppClearAllMeetingNotify_Rsp,

/**
  @brief    ����֪ͨ�������֪ͨӦ��	
  
	MainBuf(#TMgErrKeyPair_Api) \n
	SubBuf(#TAppGetAllNotifysAck_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam":
		{
			"tMgErrKeyPair_Api": {
				"dwKey": 1,
					"tErrInfo": {
						"achErrorInfo": "",
							"eApiType": 1,
							"dwErrorID": 1,
							"dwNackEventId": 1,
							"adwParams": [
						{
							"basetype": 1
						},
						{
							"basetype": 1
							},
							{
								"basetype": 1
							},
							{
								"basetype": 1
								}
							]
				}
			}
		},
		"AssParam": 
		{
		    "tNotifyList": [
		    {
		        "dwNotifyCnt":1,
		        "emNotifyType": 0
		    }
		    ]
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestAppGetAllNotify_Rsp,
	
/**
  @brief    ��û���ƽ̨account tokenӦ��
  
	MainBuf(#TRestErrorInfo_Api)  \n
	Json��ʽ���£�
  @verbatim
	{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
	}
  @endverbatim
*/	
	Ev_MtApi_RestGetPlatformAccountToken_Rsp,
	
/**
  @brief    ��������Ϣ֪ͨ	
  
	MainBuf(#TMTShortRooms_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
		"nCount": 0,
		"atItems": {
			"nID": 0,
			"achname": "",
			"achRegionName": ""
			}
	}
  @endverbatim
*/	
	Ev_MtApi_RestGetMeetingShortRoom_Ntf,
	
/**
  @brief    ��������Ϣ֪ͨ
  
	MainBuf(#TMTShortRooms_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
		"nCount": 0,
		"atItems": {
			"nID": 0,
			"achname": "",
			"achRegionName": ""
			}
	}
  @endverbatim
*/	
	Ev_MtApi_RestGetBookingShortRoom_Ntf,
	
/**
  @brief    ��������Ϣ֪ͨ	
  
	MainBuf(#TMTShortRooms_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
		"nCount": 0,
		"atItems": {
			"nID": 0,
			"achname": "",
			"achRegionName": ""
			}
	}
  @endverbatim
*/	
	Ev_MtApi_RestGetPersonShortRoom_Ntf,
	
/**
  @brief    ��������Ϣ֪ͨ
  
	MainBuf(#TMTRoomIDs_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
		"count": 0,
		"items": [
				0,
				0,
			]	
	}
  @endverbatim
*/	
	Ev_MtApi_RestGetMeetingRoomId_Ntf,
	
/**
  @brief    ��������Ϣ֪ͨ	
  
	MainBuf(#TMTShortRooms_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
		"nCount": 0,
		"atItems": {
			"nID": 0,
			"achname": "",
			"achRegionName": ""
			}
	}
  @endverbatim
*/	
	Ev_MtApi_RestGetBookingRoomId_Ntf,
	
/**
  @brief    ��������Ϣ֪ͨ
  
	MainBuf(#TMTShortRooms_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
		"nCount": 0,
		"atItems": {
			"nID": 0,
			"achname": "",
			"achRegionName": ""
			}
	}
  @endverbatim
*/	
	Ev_MtApi_RestGetPersonRoomId_Ntf,
	
/**
  @brief    ��������Ϣ֪ͨ	
  
	MainBuf(#TMTShortMeetings_Api) \n
	Json��ʽ���£�

  @verbatim
	{
		"nCount": 0,
		"atItems": {
			"nID": 0,
			"achSubject": "",
			"achStartTime": "",
			"achEndTime": "",
			"achOrganizerMoid": "",
			"nStatus": "", 
			"nIsVideoMeeting": "",
			"emFeedbackStatus": "",
			"nRegularID": "",
			"tRoomIDs": {
				"nCount": 0,
				"anItems": 0
				}
			}
	}
  @endverbatim
*/	
	Ev_MtApi_RestGetShortMeeting_Ntf,
	
/**
  @brief   ��������Ϣ֪ͨ
  
	MainBuf(#TMTShortMeetings_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
		"nCount": 0,
		"atItems": {
			"nID": 0,
			"achSubject": "",
			"achStartTime": "",
			"achEndTime": "",
			"achOrganizerMoid": "",
			"nStatus": "", 
			"nIsVideoMeeting": "",
			"emFeedbackStatus": "",
			"nRegularID": "",
			"tRoomIDs": {
				"nCount": 0,
				"anItems": 0
				}
			}
	}
  @endverbatim
*/
	Ev_MtApi_RestGetBookingShortMeeting_Ntf,
	
/**
  @brief    ��������Ϣ֪ͨ
  
	MainBuf(#TMTShortMeetings_Api)  \n
	Json��ʽ���£�

  @verbatim
	{
		"nCount": 0,
		"atItems": {
			"nID": 0,
			"achSubject": "",
			"achStartTime": "",
			"achEndTime": "",
			"achOrganizerMoid": "",
			"nStatus": "", 
			"nIsVideoMeeting": "",
			"emFeedbackStatus": "",
			"nRegularID": "",
			"tRoomIDs": {
				"nCount": 0,
				"anItems": 0
				}
			}
	}
  @endverbatim
*/
	Ev_MtApi_RestGetPersonShortMeeting_Ntf,
	
/**
  @brief    �����б�֪ͨ	
  @verbatim
	BODY: ��
  @endverbatim
*/	
	Ev_MtApi_RestGetMeetingList_Fin_Ntf,
	
/**
  @brief    �����б�֪ͨ
  @verbatim
	BODY: ��
  @endverbatim
*/
	Ev_MtApi_RestGetBookingInfo_Fin_Ntf,
	
/**
  @brief    �����б�֪ͨ	
  @verbatim
	BODY: ��
  @endverbatim
*/	
	Ev_MtApi_RestGetMeetingListOfPerson_Fin_Ntf,


/**
  @brief     ��ȡ����ģ���б���Ӧ	
  
	 MainBuf(#TRestErrorInfo_Api)\n
	 SubBuf(#TMTPerTemplateList_Api)\n
	 Json��ʽ��
  @verbatim
	 {
		 "MainParam"��
		{
				"achErrorInfo": "",
    			"eApiType": 0,
    			"dwErrorID": 0,
   				"dwNackEventId": 0,
    			"adwParams": [
        				0,
        				0
    				]
		},
		"AssParam"��
		{
			"atPerTemplateDetail" : [
			{
				"tPersonalTemplate" :
				{
					"dwTemplateid" : 0,
					"achName" : "",
					"dwDuration" : 0,
					"dwBitrate" : 0,
					"emResolution" : 0
				},
				"atMembers" :[
				{
					"achName" : "",
					"achAccount" : "",
					"dwType" : 0
				}
				]
			}
			]
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestGetPersonalTemplateList_Rsp,


/**
  @brief     ��ȡ����ģ���б������Ӧ 
  @verbatim
	BODY: ��
  @endverbatim
*/	
	Ev_MtApi_RestGetPersonalTemplateList_Fin_Rsp,


/**
  @brief     ���ݸ���ģ��id��ȡģ��������Ӧ 
  
	MainBuf(#TRestErrorInfo_Api)\n
    SubBuf(#TMTPerTemplateInfo_Api)\n
  @verbatim
	��
		"MainParam"��
		{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
			]
		}��
		"AssParam"��
		{
			"dwTemplateid" : 0,
			"achName" : "str",
			"dwDuration" : 1,
			"dwBitrate" : 1,
			"emMeetingSafe" : 1,
			"achPassword" : "str",
			"emEncryptedType" : 1,
			"achEncryptedKey" : "str",
			"emMeetingType" : 1,
			"emClosedMeeting" : 1,
			"emVideoQuality" : 1,
			"emDualMode" : 1,
			"bInitMute" : true,
			"bPublicMeeting" : true,
            "dwMeetingScale": 0,
            "dwOneReforming": 0,
            "achPresetedNumber": "",
			"dwVideoCount" : 1,
			"atVideoFormatList" : [
			{
				"emVideoFormat" : 1,
				"emVideoProfile" : 1,
				"emResolution" : 1,
				"dwFrame" : 1,
				"dwRate" : 1
			}
			],
			"dwAudioCount" : 1,
			"atAudioFormatList" : [
			{
				"emAudioFormat" : 1,
				"emAaccnnlNum" : 1
			}
			],
			"dwDualCount" : 1,
			"atDualFormatList" : [
			{
				"dwFrame" : 1,
				"emResolution" : 1,
				"emVideoFormat" : 1
			}
			],
			"dwMemberCount" : 1,
			"atMembers" : [
			{
				"achName" : "str",
				"achAccount" : "str",
				"emAccountType" : 1
			}
			],
			"tMixInfo" : 
			{
				"bEnable" : false,
				"emMode" : 0,
				"atMixMemberList" : [
				{
				    "achName" : "str",
					"achAccount" : "",
					"emAccountType" : 0
				}
				]
			}
			"tVmp" : 
			{
				"bEnable" : true,
				"emStyle" : 1,
				"bVoiceHint" : true,
				"bShowMTName" : true,
                "bIsBroadcast" : false,
				"dwMemberCount" : 1,
				"atMemberList" : [
				{
					"achName" : "str",
					"achAccount" : "str",
					"emAccountType" : 1,
					"emFollowType" : 1,
					"dwIndex" : 1
				}
				]
			},
			"tPoll" : 
			{
				"bEnable" : true,
				"dwNum" : 1,
				"dwInterval" : 1,
				"bSpeaker" : true,
				"dwMemberCount" : 1,
				"atMemberList" : [
				{
					"achName" : "str",
					"achAccount" : "str",
					"emAccountType" : 1
				}
				]
			},
			"dwVipCount" : 1,
			"atVipList" : [
			{
				"achName" : "str",
				"achAccount" : "str",
				"emAccountType" : 1
			}
			],
			"tSpeaker" :
			{
				"achName" : "str",
				"achAccount" : "str",
				"emAccountType" : 1
			},
			"tAdmin" : {
				"achName" : "str",
				"achAccount" : "str",
				"emAccountType" : 1
			},
			"dwCallTimes" : 1,
			"dwCallInterval" : 1,
			"bCallChase" : true,
			"bVoiceInspireEnable" : true,
            "dwVoiceInspireTime": 0,
			"emCascadeMode" : 1,
			"bCascadeUpload" : true,
			"bCascadeReturn" : true,
			"dwCascadeReturnPara" : 1,
			"tRecord" : {
				"bDoubleFlow" : true, 
				"bEnable" : true,
				"bMain" : true,
				"bPublish" : true
			},
			"tMultiCast" : {
				"achMulticastAddr" : "str",
				"bEnable" : true,
				"dwPort" : 1
			},
			"tSatellite" : {
				"bEnable" : true,
				"achMulticastAddr" : "str",
				"dwPort" : 1,
				"dwReturnNum" : 1
			},
			"dwCallChaseMemberCount" : 1,
			"atCallChaseList" : [
			{
				"achName" : "str",
				"achAccount" : "str",
				"emAccountType" : 1
			}
			]
		}
	��
  @endverbatim
*/	
	Ev_MtApi_RestGetPersonalTemplateByID_Rsp,


/**
  @brief    ��������ģ����Ӧ 
  
	MainBuf(#TRestErrorInfo_Api)\n
	SubBuf(#u32)\n
	Json��ʽ��

  @verbatim
	{
		"MainParam"��
		{
				"achErrorInfo": "",
    			"eApiType": 0,
    			"dwErrorID": 0,
   				"dwNackEventId": 0,
    			"adwParams": [
        				0,
        				0
    				]
		},
		"AssParam" :
		{
			"basetype": 0 // dwID
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestAddPersonalTemplate_Rsp,

/**
  @brief    ��������ģ��֪ͨ������棩
  
	 MainBuf(#u32)
  @verbatim
	 {
	     "basetype": 0 // dwID
	 }	
  @endverbatim
*/	
	Ev_MtApi_RestAddPersonalTemplate_Ntf,

/**
  @brief    ���¸���ģ����Ӧ	
 
	MainBuf(#TRestErrorInfo_Api)\n
    SubBuf(#u32)\n
	Json��ʽ��

  @verbatim
	{
		"MainParam"��
		{
				"achErrorInfo": "",
    			"eApiType": 0,
    			"dwErrorID": 0,
   				"dwNackEventId": 0,
    			"adwParams": [
        				0,
        				0
    				]
		},
		"AssParam" :
		{
			"basetype": 0 // dwID
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestUpdatePersonalTemplate_Rsp,

/**
  @brief    ���¸���ģ����Ӧ������棩	
  
	 MainBuf(#u32)
  @verbatim
	 {
	     "basetype": 0 // dwID
	 }
  @endverbatim
*/
	Ev_MtApi_RestUpdatePersonalTemplate_Ntf, 

/**
  @brief    ɾ������ģ����Ӧ
  
	 MainBuf(#TRestErrorInfo_Api)\
	 SubBuf(#u32)\n
	 Json��ʽ���£�
  @verbatim
	 {
		"MainParam" :
		{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
		},
		"AssParam" :
		{
			"basetype": 0 // dwID
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestDelPersonalTemplate_Rsp,

/**
  @brief    ɾ������ģ����Ӧ������棩	
  
	 MainBuf(#u32)
  @verbatim
	 {
	     "basetype": 0 // dwID
	 }
  @endverbatim
*/	
	Ev_MtApi_RestDelPersonalTemplate_Ntf, 

/**
  @brief    ��ȡ����ģ���б���Ӧ	
  
	MainBuf(#TRestErrorInfo_Api) \n
    SubBuf(#TMTPubTemplateList_Api) \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam" :
		{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
		},
		"AssParam" :
		{
			"atPubTemplateSimpleInfo" :[
			{
			"achTemplateKey" : "",
			"achName" : "",
			"dwDuration" : 0,
			"dwBitrate" : 0,
			"emResolution" : 0
			}
			]
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestGetPublicTemplateList_Rsp,

/**
  @brief    ��ȡ����ģ���б������Ӧ 
  @verbatim
	BODY: ��
  @endverbatim
*/	
	Ev_MtApi_RestGetPublicTemplateList_Fin_Rsp,

/**
  @brief    ���ݹ���ģ��id��ȡģ��������Ӧ 	
  
	 MainBuf(#TRestErrorInfo_Api) \n
	 SubBuf(#TMTPubTemplateInfo_Api) \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam" :
		{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
		},
		"AssParam" :
		{
			"achTemplateKey" : "",
			"achName" : "",
			"dwDuration" : 0,
			"dwBitrate" : 0,
			"emMeetingSafe" : 0,
			"achPassword" : "",
			"emEncryptedType" : 0,
			"achEncryptedKey" : "",
			"emMeetingType" : 0,
			"tSatellite" :
			{
			   "bEnable" : false,
			   "achMulticastAddr" : "",
			   "dwPort" : 0,
			   "dwReturnNum" : 0
			},
			"bPublicMeeting" : false,
			"emMixMode" : 0,
			"atVideoFormatList" : [
			{
				"emVideoFormat" : 0,
				"emVideoProfile" : 0,
				"emResolution" : 0,
				"dwFrame" : 0,
				"dwRate" : 0
			}
			],
			"atAudioFormatList" : [
			{
				"emAudioFormat" : 0,
				"emAaccnnlNum" : 0
			}
			],
			"dwCallTimes" : 0,
			"dwCallInterval" : 0,
			"bInitMute" : false,
			"emVideoQuality" : 0,
			"emDualMode" : 0,
			"bVoiceInspireEnable" : false,
            "dwVoiceInspireTime" : 0,
			"emCascadeMode" : 0,
			"bCascadeUpload" : false,
			"bCascadeReturn" : false,
			"dwCascadeReturnPara" : 0,
            "dwMeetingScale" : 0,
            "bOneReforming" : false,
			"tRecord" :
			{
				"bDoubleFlow" : false,
				"bEnable" : false,
				"bMain" : false,
				"bPublish" : false
			},
			"tMultiCast" :
			{
				"achMulticastAddr" : "",
				"bEnable" : false,
				"dwPort" : 0
			},
			"atDualFormatList":[
			{
				"dwFrame" : 0,
				"emResolution" : 0,
				"emVideoFormat" : 0
			}
			],
			"emClosedMeeting" : 0
		}
	��
  @endverbatim
*/	
	Ev_MtApi_RestGetPublicTemplateByID_Rsp,

/**
  @brief   ��������ģ����Ӧ 	
  
	 MainBuf(#TRestErrorInfo_Api) \n
	 SubBuf(#s8) \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam" :
		{
				"achErrorInfo": "",
    			"eApiType": 0,
    			"dwErrorID": 0,
   				"dwNackEventId": 0,
    			"adwParams": [
        				0,
        				0
    				]
		},
		"AssParam" :
		{
			"basetype" : "" //strKey
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestAddPublicTemplate_Rsp,

/**
  @brief    ��������ģ��֪ͨ������棩
  
	MainBuf(#s8)
  @verbatim
	 {
	     "basetype" : "" //strKey
	 }
  @endverbatim
*/	
	Ev_MtApi_RestAddPublicTemplate_Ntf,

/**
  @brief   ���¹���ģ����Ӧ	
  
	 MainBuf(#TRestErrorInfo_Api) \n
	 SubBuf(#s8) \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam"
		{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
		},
		"AssParam" :
		{
			"basetype" : "" //strKey
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestUpdatePublicTemplate_Rsp,

/**
  @brief    ���¹���ģ����Ӧ������棩
  
	 MainBuf(#s8)
  @verbatim
	 {
	     "basetype" : "" //strKey
     }
  @endverbatim
*/	
	Ev_MtApi_RestUpdatePublicTemplate_Ntf, 

/**
  @brief    ɾ������ģ����Ӧ 	
  
	 MainBuf(#TRestErrorInfo_Api) \n
	 SubBuf(#s8) \n
	Json��ʽ���£�

  @verbatim
	{
		"MainParam" :
		{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
		},
		"AssParam" :
		{
			"basetype" : "" //strKey
		}
	}
  @endverbatim
*/	
	Ev_MtApi_RestDelPublicTemplate_Rsp,

/**
  @brief    ɾ������ģ����Ӧ������棩
  
	 MainBuf(#s8)
  @verbatim
	 {
	     "basetype" : "" //strKey
	 }
  @endverbatim
*/	
	Ev_MtApi_RestDelPublicTemplate_Ntf, 

	/**
  @brief    ��ȡcometd֪ͨ��Ӧ
  
	 MainBuf(#TMTCometdMessageList_Api)
  @verbatim
	 {
		 "atCometdMessageList" : [
		 {
			 "emNotifyType" : 0,
			 "dwNotifyId" : 0,
			 "dwNum" : 0
		 }
		 ]
	 }
  @endverbatim
*/	
	Ev_MtApi_Mg_GetCometdMessage_Ntf, 

    /**
    @brief    ��������ģ����Ӧ 
  
	MainBuf(#TRestErrorInfo_Api)\n
	SubBuf(#s8)\n
	Json��ʽ��

    @verbatim
	{
		"MainParam"��
		{
				"achErrorInfo": "",
    			"eApiType": 0,
    			"dwErrorID": 0,
   				"dwNackEventId": 0,
    			"adwParams": [
        				0,
        				0
    				]
		},
		"AssParam" :
		{
			"basetype": 0 // templateID
		}
	}
    @endverbatim
   */	
	Ev_MtApi_RestCreatePersonalTemplate_Rsp,

    /**
    @brief    ��������ģ��֪ͨ������棩
  
	MainBuf(#s8)
      @verbatim
	     {
	         "basetype": 0 // templateID
	     }	
      @endverbatim
    */	
	Ev_MtApi_RestCreatePersonalTemplate_Ntf,

    /**
    @brief    ���¸���ģ����Ӧ	
 
	MainBuf(#TRestErrorInfo_Api)\n
    SubBuf(#s8)\n
	Json��ʽ��

    @verbatim
	{
		"MainParam"��
		{
				"achErrorInfo": "",
    			"eApiType": 0,
    			"dwErrorID": 0,
   				"dwNackEventId": 0,
    			"adwParams": [
        				0,
        				0
    				]
		},
		"AssParam" :
		{
			"basetype": 0 // templateID
		}
	}
    @endverbatim
    */	
	Ev_MtApi_RestModifyPersonalTemplate_Rsp,

    /**
    @brief    ���¸���ģ����Ӧ������棩	
  
	MainBuf(#s8)
    @verbatim
	     {
	         "basetype": 0 // templateID
	     }
    @endverbatim
    */
	Ev_MtApi_RestModifyPersonalTemplate_Ntf, 
    
    /**
    @brief     ��ȡ����ģ���б���Ӧ	
  
	 MainBuf(#TRestErrorInfo_Api)\n
	 SubBuf(#TMTPersonalTemplatesList_Api)\n
	 Json��ʽ��
    @verbatim
	 {
		 "MainParam"��
		{
				"achErrorInfo": "",
    			"eApiType": 0,
    			"dwErrorID": 0,
   				"dwNackEventId": 0,
    			"adwParams": [
        				0,
        				0
    				]
		},
		"AssParam"��
		{
			"atPerTemplateMember" : [
                {
                    "achTemplateID": "99",
                    "achName": "test",
                    "dwBitrate": 8128,
                    "emCloseConf": 1,
                    "emSafeConf": 0,
                    "emEncryptedtype": 2,
                    "emMeetingtype": 0,
                    "bPublicConf": 1,
                    "bInitmute": 1,
                    "bInitSilence":1,
                    "emVidoQuality": 0,
                    "dwOneReforming":1,
                    "achEncryptedkey": "234234234",
                    "emDualmode": 0,
                    "bVoiceActivityDetection": 1,
                    "emResolution":13,
                    "dwMaxJoinMt":192
                }
			]
		}
	}
    @endverbatim
    */	
    Ev_MtApi_RestGetPersonalTemplatesList_Rsp,

    /**
    @brief     ��ȡ����ģ���б������Ӧ 
    @verbatim
    BODY: ��
    @endverbatim
    */	
    Ev_MtApi_RestGetPersonalTemplatesList_Fin_Rsp,

    /**
    @brief     ���ݸ���ģ��id��ȡģ��������Ӧ 
  
	MainBuf(#TRestErrorInfo_Api)\n
    SubBuf(#TMTPeronalTemplate_Api)\n
    @verbatim
	��
		"MainParam"��
		{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
			]
		}��
		"AssParam"��
		{
            "achName": "name",
            "dwBitrate": 8128,
            "emCloseConf": 1,
            "emSafeConf": 0,
            "achPassword": "22222",
            "emEncryptedtype": 2,
            "emMeetingtype": 0,
            "dwCallTimes": 0,
            "dwCallInterval": 20,
            "bInitmute": 1,
            "bInitSilence":1,
            "emVidoQuality": 1,
            "dwOneReforming":1,
            "achEncryptedkey": "234234234",
            "emDualmode": 0,
            "bVoiceActivityDetection": 1,
            "dwVacinterval":5,
            "emCascadeMode": 1,
            "bCascadeUpload": 1,
            "bCascadeReturn": 0,
            "dwCascadeReturnPara": 0,
            "dwMaxJoinMt":192,
            "bAutoEnd" : 0,
            "bPreoccpuyResouce" : 0,
            "emFecMode":1,
            "tSpeaker": {
                "achName": "mxm",
                "achAccount": "c69da1ef-5930-47e0-9a79-dfa083de0208",
                "emAccountType": 1
            },
            "chairman": {
                "achName": "mxm",
                "achAccount": "c69da1ef-5930-47e0-9a79-dfa083de0208",
                "emAccountType": 1
            },
            "public_conf": 1,
            "tMix": {
                "emMode": 1,
                "atMixMemberList": [
                {
                    "achName": "mxm",
                    "achAccount": "c69da1ef-5930-47e0-9a79-dfa083de0208",
                    "emAccountType": 1
                },
                {
                    "achName": "mxm",
                    "achAccount": "c69da1ef-5930-47e0-9a79-dfa083de0208",
                    "emAccountType": 1
                }]
            },
            "atVideoFormatList": [
            {
                "emVideoFormat": 4,
                "emResolution": 3,
                "dwFrame": 30,
                "dwRate": 8128
            },
            {
                "emVideoFormat": 4,
                "emResolution": 3,
                "dwFrame": 30,
                "dwRate": 8128
            },
            {
                "emVideoFormat": 4,
                "emResolution": 3,
                "dwFrame": 30,
                "dwRate": 8128
            },
            {
                "emVideoFormat": 4,
                "emResolution": 3,
                "dwFrame": 30,
                "dwRate": 8128
            }
            ],
            "atInviteMembers": [
            {
                "achName": "mxm",
                "achAccount": "c69da1ef-5930-47e0-9a79-dfa083de0208",
                "emAccountType": 1
                "emProtocol": 1
            },
            {
                "achName": "mxm",
                "achAccount": "c69da1ef-5930-47e0-9a79-dfa083de0208",
                "emAccountType": 1
                "emProtocol": 1
            }
            ],
            "tVmp": {
                "emMode":1,
                "emStyle": 2,
                "bVoiceHint": 0,
                "bIsBroadcast": 1,
                "bShowMTName": 0,
                "atMemberList": [
                    {
                        "achName": "mxm",
                        "achAccount": "c69da1ef-5930-47e0-9a79-dfa083de0208",
                        "emAccountType": 1,
                        "emFollowType":1,
                        "dwIndex": 0
                    },
                    {
                        "achName": "mxm",
                        "achAccount": "c69da1ef-5930-47e0-9a79-dfa083de0208",
                        "emAccountType": 1,
                        "emFollowType":1,
                        "dwIndex": 0
                    }
                ]
            },
            "atViplist": [
                {
                    "achName": "mxm",
                    "achAccount": "c69da1ef-5930-47e0-9a79-dfa083de0208",
                    "emAccountType": 1
                },
                {
                    "achName": "mxm",
                    "achAccount": "c69da1ef-5930-47e0-9a79-dfa083de0208",
                    "emAccountType": 1
                }
            ],
            "tPoll": {
                "emMode":1,
                "dwNum": 0,
                "dwInterval": 30,
                "atMemberList": [
                    {
                        "achName": "mxm",
                        "achAccount": "c69da1ef-5930-47e0-9a79-dfa083de0208",
                        "emAccountType": 1
                    },
                    {
                        "achName": "mxm",
                        "achAccount": "c69da1ef-5930-47e0-9a79-dfa083de0208",
                        "emAccountType": 1
                    }
                ]
            },
            "achTemplateID":"12"
            "emCallMode": 0,
            "tRecordAttr":{
                "emPublishMode": 1
                "emRecordMode": 1
                "bAnonymous":0
            }
		}
	��
    @endverbatim
    */	
	Ev_MtApi_RestGetPerTemplateByID_Rsp,

    /**
    @brief     ��ȡ����ģ���б���Ӧ	
  
	 MainBuf(#TRestErrorInfo_Api)\n
	 SubBuf(#TMTCommonTemplatesList_Api)\n
	 Json��ʽ��
    @verbatim
	 {
		 "MainParam"��
		{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
		},
		"AssParam"��
		{
			"atCommonTemplateMember" : [
                {
                    "achTemplateID": "9975111",
                    "achName": "test",
                    "dwBitrate": 8128,
                    "emCloseConf": 1,
                    "emSafeConf": 0,
                    "emEncryptedtype": 2,
                    "emMeetingtype": 0,
                    "bPublicConf": 1,
                    "bInitmute": 1,
                    "bInitSilence":1,
                    "emVidoQuality": 0,
                    "dwOneReforming":1,
                    "achEncryptedkey": "234234234",
                    "emDualmode": 0,
                    "bVoiceActivityDetection": 1,
                    "emResolution":13,
                    "dwMaxJoinMt":192
                }
			]
		}
	}
    @endverbatim
    */	
    Ev_MtApi_RestGetCommonTemplateList_Rsp,

    /**
      @brief     ��ȡ����ģ���б������Ӧ 
      @verbatim
	    BODY: ��
      @endverbatim
    */	
    Ev_MtApi_RestGetCommonTemplateList_Fin_Rsp,

    /**
    @brief   ��������ģ����Ӧ 	
  
	MainBuf(#TRestErrorInfo_Api) \n
	 SubBuf(#s8) \n
	Json��ʽ���£�

      @verbatim
	    {
		    "MainParam" :
		    {
				    "achErrorInfo": "",
    			    "eApiType": 0,
    			    "dwErrorID": 0,
   				    "dwNackEventId": 0,
    			    "adwParams": [
        				    0,
        				    0
    				    ]
		    },
		    "AssParam" :
		    {
			    "basetype" : "" //strKey
		    }
	    }
      @endverbatim
    */	
	Ev_MtApi_RestCreateCommonTemplate_Rsp,

    /**
    @brief    ��������ģ��֪ͨ������棩
  
	MainBuf(#s8)
    @verbatim
	     {
	         "basetype" : "" //templateID
	     }
    @endverbatim
    */	
	Ev_MtApi_RestCreateCommonTemplate_Ntf,

    /**
    @brief    ���ݹ���ģ��id��ȡģ��������Ӧ 	
  
	 MainBuf(#TRestErrorInfo_Api) \n
	 SubBuf(#TMTCommonTemplate_Api) \n
	 Json��ʽ���£�

    @verbatim
	{
		"MainParam" :
		{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
		},
		"AssParam" :
        {
            "achTemplateID":"1212"
            "achName": "name",
            "dwBitrate": 8128,
            "emCloseConf": 1,
            "emSafeConf": 0,
            "achPassword": "22222",
            "emEncryptedtype": 2,
            "emMeetingtype": 0,
            "dwCallTimes": 0,
            "dwCallInterval": 20,
            "bInitmute": 1,
            "bInitSilence":1,
            "emVidoQuality": 1,
            "dwOneReforming":1,
            "achEncryptedkey": "234234234",
            "emDualmode": 0,
            "bVoiceActivityDetection": 1,
            "dwVacinterval":5,
            "emCascadeMode": 1,
            "bCascadeUpload": 1,
            "bCascadeReturn": 0,
            "dwCascadeReturnPara": 0,
            "dwMaxJoinMt":192,
            "bAutoEnd" : 0,
            "bPreoccpuyResouce" : 0,
            "public_conf": 1,
            "emFecMode":1,
            "tVMP":{ 
                "bEnable":1,
                "emMode":EmVmpMode_Api
            }
            "tMIX":{ 
                "emMode":EmMtMixType_Api
            }
            "atVideoFormatList": [
                {
                    "emVideoFormat": 4,
                    "emResolution": 3,
                    "dwFrame": 30,
                    "dwRate": 8128
                },
                {
                    "emVideoFormat": 4,
                    "emResolution": 3,
                    "dwFrame": 30,
                    "dwRate": 8128
                },
                {
                    "emVideoFormat": 4,
                    "emResolution": 3,
                    "dwFrame": 30,
                    "dwRate": 8128
                },
                {
                    "emVideoFormat": 4,
                    "emResolution": 3,
                    "dwFrame": 30,
                    "dwRate": 8128
                }
            ]
        }
	��
    @endverbatim
    */	
    Ev_MtApi_RestGetCommonTemplateByID_Rsp,

    /**
    @brief   ���¹���ģ����Ӧ	
  
	 MainBuf(#TRestErrorInfo_Api) \n
	 SubBuf(#s8) \n
	Json��ʽ���£�

    @verbatim
	{
		"MainParam"
		{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
		},
		"AssParam" :
		{
			"basetype" : "" //strKey
		}
	}
    @endverbatim
    */	
    Ev_MtApi_RestModifyCommonTemplate_Rsp,

    /**
    @brief    ���¹���ģ����Ӧ������棩
  
	 MainBuf(#s8)
    @verbatim
	 {
	     "basetype" : "" //strKey
     }
    @endverbatim
    */	
    Ev_MtApi_RestModifyCommonTemplate_Ntf,

    /**
    @brief    ��ȡԤԼ�����б���Ӧ 	
  
	 MainBuf(#TRestErrorInfo_Api) \n
	 SubBuf(#TMTBookConferenceList_Api) \n
	Json��ʽ���£�

    @verbatim
	{
		"MainParam" :
		{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
		},
		"AssParam" :
        {
            "dwTotal" : 5
            "dwCount":4,
            [
                {
                    "achName": "name",
                    "achConfID":"1212",
                    "emConfType":1,
                    "achStartTime":"2016-11-11T15:30:00+08:00",
                    "achEndTime": "2016-11-11T19:30:00+08:00",
                    "dwDuration": 240,
                    "dwBitrate": 8128,
                    "emCloseConf": 1,
                    "emSafeConf": 0,
                    "emEncryptedtype": 2,
                    "achPassword": "22222",
                    "bInitmute": 1,
                    "bInitSilence":1,
                    "emVidoQuality": 1,
                    "dwOneReforming":1,
                    "achEncryptedkey": "234234234",
                    "emDualmode": 0,
                    "bVoiceActivityDetection": 1,
                    "public_conf": 1,
                     "dwInvitedMtNum": 12,
                    "dwMaxJoinMt":192,
                    "tConfInitiator": {
                        "achName": "mxm",
                        "achAccount": "c69da1ef-5930-47e0-9a79-dfa083de0208",
                        "emAccountType": 1,
                        "achTelephone": "85181157",
                        "achMobile": "13852521511"
                    }
                }
            ]
        }
	��
    @endverbatim
    */	
    Ev_MtApi_RestGetBookConferenceList_Rsp,

    /**
      @brief     ��ȡԤԼ�����б������Ӧ 
      @verbatim
	    BODY: ��
      @endverbatim
    */	
    Ev_MtApi_RestGetBookConferenceList_Fin_Rsp,

    /**
    @brief    ����ԤԼ����id��ȡ����������Ӧ 	
  
	 MainBuf(#TRestErrorInfo_Api) \n
	 SubBuf(#TMTBookConferenceInfo_Api) \n
	Json��ʽ���£�

    @verbatim
	{
		"MainParam" :
		{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
		},
		"AssParam" :
        {
            "achName": "name",
            "achConfID":"1212",
            "emConfType":1,
            "achStartTime":"2016-11-11T15:30:00+08:00",
            "achEndTime": "2016-11-11T19:30:00+08:00",
            "dwDuration": 240,
            "dwBitrate": 8128,
            "emCloseConf": 1,
            "emSafeConf": 0,
            "achPassword": "22222",
            "emEncryptedtype": 2,
            "achEncryptedkey": "234234234",
            "dwCallTimes": ,
            "dwCallInterval",
            "bInitmute": 1,
            "bInitSilence":1,
            "emVidoQuality": 1,
            "emDualmode": 0,
            "bVoiceActivityDetection": 1,
            "emCascadeMode" : 1,
            "bCascadeUpload" : true,
            "bCascadeReturn" : true,
            "dwCascadeReturnPara" : 1,
            "public_conf": 1,
            "bVmpEnable":1,
            "bMixEnable":1,
            "bPollEnable":1,
            "dwInvitedMtNum": 12,
            "dwMaxJoinMt":192,
            "emFecMode":1,
            "tConfInitiator": {
                "achName": "mxm",
                "achAccount": "c69da1ef-5930-47e0-9a79-dfa083de0208",
                "emAccountType": 1,
                "achTelephone": "85181157",
                "achMobile": "13852521511"
            },
            "tSpeaker": {
                "achName": "mxm",
                "achAccount": "c69da1ef-5930-47e0-9a79-dfa083de0208",
                "emAccountType": 1
            },
            "chairman": {
                "achName": "mxm",
                "achAccount": "c69da1ef-5930-47e0-9a79-dfa083de0208",
                "emAccountType": 1
            },
            "atVideoFormatList": [
                {
                    "emVideoFormat": 4,
                    "emResolution": 3,
                    "dwFrame": 30,
                    "dwRate": 8128
                },
                {
                    "emVideoFormat": 4,
                    "emResolution": 3,
                    "dwFrame": 30,
                    "dwRate": 8128
                },
                {
                    "emVideoFormat": 4,
                    "emResolution": 3,
                    "dwFrame": 30,
                    "dwRate": 8128
                },
                {
                    "emVideoFormat": 4,
                    "emResolution": 3,
                    "dwFrame": 30,
                    "dwRate": 8128
                }
            ],
            "dwOneReforming":1,
            "bAutoEnd":1,
            "bPreoccpuyResouce":0
        }
	��
    @endverbatim
    */	
    Ev_MtApi_RestGetBookConferenceInfoByID_Rsp,

    /**
    @brief   ����������Ӧ 	
  
	 MainBuf(#TRestErrorInfo_Api) \n
	 SubBuf(#s8) \n
	Json��ʽ���£�

    @verbatim
	{
		"MainParam" :
		{
				"achErrorInfo": "",
    			"eApiType": 0,
    			"dwErrorID": 0,
   				"dwNackEventId": 0,
    			"adwParams": [
        				0,
        				0
    				]
		},
		"AssParam" :
		{
			"basetype" : "" //strID
		}
	}
    @endverbatim
    */	
    Ev_MtApi_RestCreateConference_Rsp,

    /**
      @brief    ����������Ӧ֪ͨ������棩
  
	    MainBuf(#s8)
      @verbatim
	     {
	         "basetype" : "" //strID
	     }
      @endverbatim
    */	
    Ev_MtApi_RestCreateConference_Ntf,

    /**
    @brief   ����������Ӧ 	
  
	 MainBuf(#TRestErrorInfo_Api) \n
	 SubBuf(#s8) \n
	Json��ʽ���£�

    @verbatim
	{
		"MainParam" :
		{
				"achErrorInfo": "",
    			"eApiType": 0,
    			"dwErrorID": 0,
   				"dwNackEventId": 0,
    			"adwParams": [
        				0,
        				0
    				]
		},
		"AssParam" :
		{

		}
	}
    @endverbatim
    */	
    Ev_MtApi_RestStopConference_Rsp,

    /**
    @brief    ��ȡ��ʱ�����б���Ӧ 	
  
	    MainBuf(#TRestErrorInfo_Api) \n
	    SubBuf(#TMTInstantConferenceList_Api) \n
	Json��ʽ���£�

    @verbatim
	{
		"MainParam" :
		{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
		},
		"AssParam" :
        {
            "dwTotal" : 5
            "dwCount":4,
            [
                {
                    "achName": "name",
                    "achConfID":"1212",
                    "emConfType":1,
                    "achStartTime":"2016-11-11T15:30:00+08:00",
                    "achEndTime": "2016-11-11T19:30:00+08:00",
                    "dwDuration": 240,
                    "dwBitrate": 8128,
                    "emCloseConf": 1,
                    "emSafeConf": 0,
                    "emEncryptedtype": 2,
                    "achPassword": ,
                    "bInitmute": 1,
                    "bInitSilence":1,
                    "emVidoQuality": 1,
                    "dwOneReforming":,
                    "achEncryptedkey": "234234234",
                    "emDualmode": 0,
                    "bVoiceActivityDetection": 1,
                    "public_conf": 1,
                     "dwInvitedMtNum":,
                    "dwMaxJoinMt":192,
                    "bNeedPassword":
                    "bForceBroadcast":
                    "tConfInitiator": {
                        "achName": "mxm",
                        "achAccount": "c69da1ef-5930-47e0-9a79-dfa083de0208",
                        "emAccountType": 1,
                        "achTelephone": "85181157",
                        "achMobile": "13852521511"
                    }
                    "emFecMode":1,
                }
            ]
        }
	��
    @endverbatim
    */	
    Ev_MtApi_RestGetConferenceList_Rsp,

    /**
      @brief     ��ȡ��ʱ�����б������Ӧ 
      @verbatim
	    BODY: ��
      @endverbatim
    */
    Ev_MtApi_RestGetConferenceList_Fin_Rsp,

    /**
    @brief    ���ݻ���id��ȡ��ʱ����������Ӧ 	
  
	 MainBuf(#TRestErrorInfo_Api) \n
	 SubBuf(#TMTInstantConferenceInfo_Api) \n
	Json��ʽ���£�

    @verbatim
	{
        "AssParam" : {
            "achConfID" : "7770480",
            "dwConfLevel":,
            "dwVacinterval":,
            "achEncryptedkey" : "",
            "achEndTime" : "2016-12-07T11:39:37+08:00",
            "achName" : "�������",
            "achStartTime" : "2016-12-07T11:39:37+08:00",
            "atVideoFormatList" : [
                {
                    "dwFrame" : 30,
                    "dwRate" : 1024,
                    "emResolution" : 17,
                    "emVideoFormat" : 4,
                    "emVideoProfile" : 0
                }
            ],
            "bAutoEnd" : false,
            "bForceBroadcast" : true,
            "bInitSilence" : false,
            "bInitmute" : false,
            "bMixEnable" : false,
            "bPollEnable" : false,
            "bPreoccpuyResouce" : true,
            "bPublicConf" : false,
            "bVmpEnable" : false,
            "bVoiceInspireEnable" : false,
            "bNeedPassword": true,
            "dwBitrate" : 1024,
            "dwCallInterval" : 30,
            "dwCallTimes" : 0,
            "dwDuration" : 0,
            "dwMaxJoinMt" : 192,
            "dwVFormatNum" : 1,
            "emCloseConf" : 0,
            "emConfType" : 1,
            "emDualmode" : 1,
            "emEncryptedtype" : 0,
            "emSafeConf" : 1,
            "emVidoQuality" : 0,
            "tConfInitiator" : {
                "achAccount" : "b812b02c-d80e-4250-b9da-e3f8d0ea3cdf",
                "achMobile" : "",
                "achName" : "keda_user_admin1",
                "achTelephone" : "222",
                "emAccountType" : 5
            },
            emCascadeMode:,
            bCascadeUpload:,
            bCascadeReturn:,
            dwCascadeReturnPara:,
            emCallMode:,
        },
        "MainParam" : {
            "achErrorInfo" : "",
            "adwParams" : [],
            "dwErrorID" : 1000,
            "dwNackEventId" : 0,
            "dwParamCount" : 0,
            "emApiType" : 0
        }
	��
    @endverbatim
    */	
    Ev_MtApi_RestGetInstantConfInfoByID_Rsp,
    
    /**
    @brief     ��ȡ�򵥸���ģ������
  
	MainBuf(#TRestErrorInfo_Api)\n
    SubBuf(#TMTSimplePeronalTemplate_Api)\n
    @verbatim
	��
		"MainParam"��
		{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
			]
		}��
		"AssParam"��
		{
		   "dwTemplateID":12
			"achName": "name",
			"dwBitrate": 8128,
			"emCloseConf": 1,			
			"emSafeConf": 0,
			"achPassword": "22222",
			"emEncryptedtype": 2,
			"emMeetingtype": 0,
			"dwCallTimes": 0,		
			"dwCallInterval": 20,
			"bCallChase": 1,
			"bInitmute": 1,
			"bInitSilence":1,
			"emVidoQuality": 1,
            "emCallMode": 0,
			"dwOneReforming":1,
			"achEncryptedkey": "234234234",
			"emDualmode": 0,
			"bVoiceActivityDetection": 1,
			"emCascadeMode": 1,	
			"bCascadeUpload": 1,
			"bCascadeReturn": 0,
			"dwCascadeReturnPara": 0,
			"dwMaxJoinMt":192,
			"dwInviteNum": 11,		
			"dwMixNum":1,
			"dwVmpNum":1,
			"dwVipNum":1,
			"dwPollNum":1,
            "emFecMode":1,
			"tSpeaker": {
				"achName": "mxm",
				"achAccount": "c69da1ef-5930-47e0-9a79-dfa083de0208",
				"emAccountType": 1
			},
			"chairman": {
				"achName": "mxm",
				"achAccount": "c69da1ef-5930-47e0-9a79-dfa083de0208",
				"emAccountType": 1
			},
			"public_conf": 1,
			"atVideoFormatList": [
				{
					"emVideoFormat": 4,
					"emResolution": 3,
					"dwFrame": 30,
					"dwRate": 8128
				},
				{
				    "emVideoFormat": 4,
				    "emResolution": 3,
				    "dwFrame": 30,
				    "dwRate": 8128
				}
			]
		}
	��
  @endverbatim
*/	
    Ev_MtApi_RestGetSimplePerTemplateByID_Rsp,
    
    /**
    @brief     ��ȡ����ģ��λ���Ա��Ӧ
  
	MainBuf(#TRestErrorInfo_Api)\n
    SubBuf(#TMTPerInviteMemberList_Api)\n
    @verbatim
	��
		"MainParam"��
		{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
			]
		}��
		"AssParam"��
		{
		    "dwTemplateID":12
			"dwCount":2
			"atInviteMembers": [
                {
				    "achName": "mxm",
				    "achAccount": "c69da1ef-5930-47e0-9a79-dfa083de0208",
				    "emAccountType": 1
                    "emProtocol":1
			    },
                {
                    "achName": "mxm",
                    "achAccount": "c69da1ef-5930-47e0-9a79-dfa083de0208",
                    "emAccountType": 1
                    "emProtocol":1
                }
            ]
		}
	��
    @endverbatim
    */	
    Ev_MtApi_RestGetInviteMembersOfPerTemplate_Rsp,

   /**
      @brief     ��ȡ����ģ��λ���Ա������Ӧ 
      @verbatim
	    BODY: ��
      @endverbatim
    */
    Ev_MtApi_RestGetInviteMembersOfPerTemplate_Fin_Rsp,

    /**
    @brief    ɾ������ģ����Ӧ
  
	 MainBuf(#TRestErrorInfo_Api)\
	 SubBuf(#s8)\n
	 Json��ʽ���£�
    @verbatim
	 {
		"MainParam" :
		{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
		},
		"AssParam" :
		{
			"basetype": 0 // template id
		}
	}
    @endverbatim
    */	
	Ev_MtApi_RestDeletePersonalTemplate_Rsp,

    /**
    @brief    ɾ������ģ����Ӧ������棩	
  
	 MainBuf(#s8)
    @verbatim
	 {
	     "basetype": 0 // dwID
	 }
    @endverbatim
    */	
	Ev_MtApi_RestDeletePersonalTemplate_Ntf, 

    /**
    @brief    ɾ������ģ����Ӧ 	
  
	 MainBuf(#TRestErrorInfo_Api) \n
	 SubBuf(#s8) \n
	Json��ʽ���£�

    @verbatim
	{
		"MainParam" :
		{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
		},
		"AssParam" :
		{
			"basetype" : "" //strKey
		}
	}
    @endverbatim
    */	
	Ev_MtApi_RestDeleteCommonTemplate_Rsp,

    /**
    @brief    ɾ������ģ����Ӧ������棩
  
	 MainBuf(#s8)
    @verbatim
	 {
	     "basetype" : "" //strKey
	 }
    @endverbatim
    */	
	Ev_MtApi_RestDeleteCommonTemplate_Ntf,

    /**
    @brief     ��ȡ����ģ�������Ϣ
  
	MainBuf(#TRestErrorInfo_Api)\n
    SubBuf(#TMTGetMixInfo_Api)\n
    @verbatim
	��
		"MainParam"��
		{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 1000,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
			]
		}��
		"AssParam"��
		{
		    "achTemplateID":"12"
			"tMix": 
			{
				"emMode": 1,
				"dwMixMemberCount":2,
			    "atMixMemberList":			
				[
					{
						"achName": "mxm",
						"achAccount": "c69da1ef-5930-47e0-9a79-dfa083de0208",
						"emAccountType": 1
					},
					{
						"achName": "mxm",
						"achAccount": "c69da1ef-5930-47e0-9a79-dfa083de0208",
						"emAccountType": 1
					}
				]
			}
			
		}
	��
  @endverbatim
*/	
    Ev_MtApi_RestGetMixInfoOfPerTemplate_Rsp,

    /**
    @brief     ��ȡ����ģ��VMP��Ϣ
  
	MainBuf(#TRestErrorInfo_Api)\n
    SubBuf(#TMTGetPerVMPInfo_Api)\n
    @verbatim
	��
		"MainParam"��
		{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
			]
		}��
		"AssParam"��
		{
		    "achTemplateID":"12"
			"tVMP": 
            {
                "emMode":,
                "emStyle": 2,
                "bVoiceHint": 0,
                "bIsBroadcast": 1,
                "bShowMTName": 0,
                "atMemberList": [
                    {
                        "achName": "mxm",
                        "achAccount": "c69da1ef-5930-47e0-9a79-dfa083de0208",
                        "emAccountType": 1,
                        "emFollowType":1,
                        "dwIndex": 0
                    },
                    {
                        "achName": "mxm",
                        "achAccount": "c69da1ef-5930-47e0-9a79-dfa083de0208",
                        "emAccountType": 1,
                        "emFollowType":1,
                        "dwIndex": 0
                    }
                ]
            }
		}
	��
  @endverbatim
*/	
    Ev_MtApi_RestGetVMPInfoOfPerTemplate_Rsp,

    /**
    @brief     ��ȡ����ģ����ѯ��Ϣ
  
	MainBuf(#TRestErrorInfo_Api)\n
    SubBuf(#TMTGetPerPollInfo_Api)\n
    @verbatim
	��
        "AssParam" : {
            "achTemplateID" : "189",
            "tPoll" : {
            "atMemberList" : [
                {
                    "achAccount" : "212fa23d-f2d0-482e-aaeb-be7d1acdb90e",
                    "achName" : "0512110000142",
                    "emAccountType" : 5
                }
            ],
            "bSpeaker" : true,
            "dwInterval" : 20,
            "dwMemberCount" : 1,
            "dwNum" : 10,
            "emMode": ,
        }
        },
        "MainParam" : {
            "achErrorInfo" : "",
            "adwParams" : [],
            "dwErrorID" : 1000,
            "dwNackEventId" : 0,
            "dwParamCount" : 0,
            "emApiType" : 0
        }
	��
    @endverbatim
    */	
    Ev_MtApi_RestGetPollInfoOfPerTemplate_Rsp,

    /**
    @brief     ��ȡ����ģ��VIP��Ϣ
  
	MainBuf(#TRestErrorInfo_Api)\n
    SubBuf(#TMTGetPerPollInfo_Api)\n
    @verbatim
	��
        "AssParam" : {
            "achTemplateID" : "189",
            "atVIP" : [
                {
                    "achAccount" : "212fa23d-f2d0-482e-aaeb-be7d1acdb90e",
                    "achName" : "0512110000142",
                    "emAccountType" : 5
                },
                {
                    "achAccount" : "29e96808-54a0-43d4-a59e-6041df01dd67",
                    "achName" : "0512110000140",
                    "emAccountType" : 5
                }
            ],
            "dwCount" : 2
        },
        "MainParam" : {
            "achErrorInfo" : "",
            "adwParams" : [],
            "dwErrorID" : 1000,
            "dwNackEventId" : 0,
            "dwParamCount" : 0,
            "emApiType" : 0
        }
	��
    @endverbatim
    */	
    Ev_MtApi_RestGetVIPInfoOfPerTemplate_Rsp,

    /**
    @brief    ��ʼ¼����Ӧ 	
  
	 MainBuf(#TRestErrorInfo_Api) \n
	 SubBuf(#s8) \n
	Json��ʽ���£�

    @verbatim
	{
		"MainParam" :
		{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
		},
		"AssParam" :
		{
			"basetype" : "3"  //achRecordID
		}
	}
    @endverbatim
    */	
    Ev_MtApi_RestStartRecord_Rsp,

    /**
    @brief    ��ʼ¼����Ӧ֪ͨ	
  
	 MainBuf(#TRestErrorInfo_Api) \n
	 SubBuf(#s8) \n
	Json��ʽ���£�
    @verbatim
	{
		"MainParam" :
		{
            "basetype" : "3"  //achRecordID
		}
	}
    @endverbatim
    */	
    Ev_MtApi_RestStartRecord_Ntf,

    /**
    @brief    ֹͣ¼����Ӧ 	
  
	 MainBuf(#TRestErrorInfo_Api) \n
	Json��ʽ���£�

    @verbatim
	{
		"MainParam" :
		{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 0,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
		}
	}
    @endverbatim
    */	
    Ev_MtApi_RestStopRecord_Rsp,

    /**
    @brief    ֹͣ¼����Ӧ֪ͨ
  
	 MainBuf(#TRestErrorInfo_Api) \n
	Json��ʽ���£�

    @verbatim
	{
		"MainParam" :
		{
		}
	}
    @endverbatim
    */	
    Ev_MtApi_RestStopRecord_Ntf,
        /**
    @brief     ��ȡ¼��״̬��Ϣ
  
	MainBuf(#TRestErrorInfo_Api)\n
    SubBuf(#TMTRecordStateInfo_Api)\n
    @verbatim
	��
        "AssParam" : {
            "achVideoName": "",
            "emRecordType":  , 
            "emRecordState": ,
            "emPublishMode": ,
            "emRecordMode": ,

            "bAnonymous": ,
            "bMainStream": ,
            "bDualStream": ,
            "dwCurrentProgress": ,

            "wRecordMemberCnt": ,
            "atRecordMembers":[
                {
                    "achMtID": "",
                },
                {
                    "achMtID": "",
                }
            ],
        },
        "MainParam" : {
            "achErrorInfo" : "",
            "adwParams" : [],
            "dwErrorID" : 1000,
            "dwNackEventId" : 0,
            "dwParamCount" : 0,
            "emApiType" : 0
        }
	��
    @endverbatim
    */	
    Ev_MtApi_RestGetRecordState_Rsp,

     /**
    @brief    �޸�¼��״̬��Ӧ 	
  
	 MainBuf(#TRestErrorInfo_Api) \n
	Json��ʽ���£�

    @verbatim
	{
		"MainParam" :
		{
			"achErrorInfo": "",
    		"eApiType": 0,
    		"dwErrorID": 1000,
   			"dwNackEventId": 0,
    		"adwParams": [
        			0,
        			0
    			]
		}
	}
    @endverbatim
    */	
    Ev_MtApi_RestModifyRecordState_Rsp,

    /**
    @brief     ��ȡ¼���б�
  
    MainBuf(#TRestErrorInfo_Api)\n
    SubBuf(#TMTRecordList_Api)\n
    @verbatim
    ��
        "AssParam" : {
            "dwRecordMemberCnt": 1,
            "atRecordListMember":[
            {
                "achRecordID": ""
                "achVideoName": "",
                "emRecordType":  , 
                "emRecordState": ,
                "emPublishMode": ,
                "emRecordMode": ,

                "bAnonymous": ,
                "bMainStream": ,
                "bDualStream": ,
                "dwCurrentProgress": ,

                "wRecordMemberCnt": ,
                "atRecordMembers":[
                    {
                        "achMtID": "",
                    },
                    {
                        "achMtID": "",
                    }
                ]
            }, ]
        },
        "MainParam" : {
            "achErrorInfo" : "",
            "adwParams" : [],
            "dwErrorID" : 1000,
            "dwNackEventId" : 0,
            "dwParamCount" : 0,
            "emApiType" : 0
        }
	��
    @endverbatim
    */	
    Ev_MtApi_RestGetRecordList_Rsp,

     /**
      @brief     ��ȡ¼���б������Ӧ 
      @verbatim
	    BODY: ��
      @endverbatim
    */
    Ev_MtApi_RestGetRecordList_Fin_Rsp,

    /**
    @brief     ��ȡ���������ն��б�
  
    MainBuf(#TRestErrorInfo_Api)\n
    SubBuf(#TMTConfTerminalList_Api)\n
    @verbatim
    ��
        "AssParam" : {
            "dwCount": 1,
            "atConfTerminalList":[
            {
                "achAlias":"shanghai",
                "achMtID":"1",
                "achE164":"123456",
                "achIP":"127.0.0.1"
                "dwBitrate":1024,
                "bOnline":0,

                "bSilence":1,
                "bMute":1,
                "bDual":0,
                "bMix":1,
                "bVMP":0,

                "bInspection":1,
                "bRecord":0,
                "bPoll":1,
                "bUpload":0,

                "emMtType":1,
                "emCallMode":0,
                "emProtocol":1
            }, ]
        },
        "MainParam" : {
            "achErrorInfo" : "",
            "adwParams" : [],
            "dwErrorID" : 1000,
            "dwNackEventId" : 0,
            "dwParamCount" : 0,
            "emApiType" : 0
        }
	��
    @endverbatim
    */	
    Ev_MtApi_RestGetConfTerminalList_Rsp,

     /**
      @brief     ��ȡ���������ն��б������Ӧ 
      @verbatim
	    BODY: ��
      @endverbatim
    */
    Ev_MtApi_RestGetConfTerminalList_Fin_Rsp,


 /**
    @brief    ��¼���ͷ�������Ӧ
  
	 MainBuf(#TMTPushSrvResult_Api) \n
	Json��ʽ���£�

    @verbatim
	{
		"MainParam" :
		{
			"bSuccess": true,
    		"dwErrCode": 0,
		}
	}
    @endverbatim
*/	
	Ev_MtApi_PushSrvLogin_Rsp,

/**
    @brief    �ǳ����ͷ�������Ӧ
  
	 MainBuf(#TMTPushSrvResult_Api) \n
	Json��ʽ���£�

    @verbatim
	{
		"MainParam" :
		{
			"bSuccess": true,
    		"dwErrCode": 0,
		}
	}
    @endverbatim
*/	
	Ev_MtApi_PushSrvLogout_Rsp,


	/**
    @brief     �ټ����������Ӧ
  
    MainBuf(#TMTVConfResult_Api)\n
    @verbatim
    ��
        "MainParam" : {
   
        }
	��
    @endverbatim
    */	
//	Ev_MtApi_RestCreateVirtualConf_Rsp,

	/**
    @brief     ��ȡ�������������
  
    MainBuf(#TMTVConfResult_Api)\n
    SubBuf(#TMTVConfDetailInfo_Api)\n
    @verbatim
    ��
        "MainParam" : {
  
        },
        "AssParam" : {
   
        }
	��
    @endverbatim
    */	
	Ev_MtApi_RestGetVConfDetailInfo_Rsp,

	/**
    @brief     ����������б�
  
    MainBuf(#TMTVConfResult_Api)\n
	SubBuf(#TMTVConfList_Api)\n
    @verbatim
    ��
        "MainParam" : {
  
        },
        "AssParam" : {
   
        }
	��
    @endverbatim
    */	
	Ev_MtApi_RestGetVConfList_Rsp,

	/**
    @brief     ����������б��ְ�������
  
    MainBuf(#TMTVConfResult_Api)\n
    @verbatim
    ��
        "MainParam" : {
  
        },
	��
    @endverbatim
    */	
	Ev_MtApi_RestGetVConfList_Fin_Rsp,


	/**
    @brief     ��ȡ��Դռ�����
  
    MainBuf(#TMTVConfResult_Api)\n
    SubBuf(#TMTVConfResources_Api)\n
    @verbatim
    ��
        "MainParam" : {
  
        },
        "AssParam" : {
   
        }
	��
    @endverbatim
    */	
	Ev_MtApi_RestGetVConfResource_Rsp,


    EV_UI_END(MTAPI_MG) = EVSEG_MTAPI_BASE_END
};

#define Is_MtApiMG_Msg(m) ((m) >= EV_UI_BGN(MTAPI_MG) && (m) <= EV_UI_END(MTAPI_MG))

/**@}*/

/**@}*/
#endif // _MTAPI_EVENT_MG_H_
