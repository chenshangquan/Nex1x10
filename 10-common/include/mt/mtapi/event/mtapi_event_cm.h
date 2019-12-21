/*******************************************************************************//**
*@file          mtapi_event_cm.h
*@brief         ʵ��MTAPI MtContactMgrSdk ��UI(�۲���)�¼�֪ͨ�Ķ���
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_EVENT_CM_H_
#define _MTAPI_EVENT_CM_H_
/**@addtogroup event �¼�
*@{
*/

/**@addtogroup cmevent ��ϵ���¼�
*@{
*/

#include "mtapi_event_def.h"


enum EmMtApiCMEv
{
	EV_UI_BGN(MTAPI_CM)  = EVSEG_MTAPI_CM_BGN,

/**
  @brief    ����һ����¼Ӧ��	
  
    MainBuf(#TMTRecordErrInfo_Api )\n
	SubBuf(#TMTCallRecord_Api ) 
  
  @verbatim
  {
	"MainParam":
	{
	"emError": 1
	},
	"AssParam": 
	{
	"dwSn": 1,
	"emCallRecordType": 1,
	"emCallType": 1,
	"achDescribe": "",
	"emConfMode": 0,
	"achH323Id": "",
	"emAddrType": 1,
	"achE164": 0,
	"achIp": "",
	"achPhoneNumber": "",
	"dwRate": 1,
	"dwTime": 1
	}
   }
  @endverbatim
*/
	Ev_MtApi_RecordInsert_Rsp,

/**
  @brief    ����һ����¼֪ͨ	
  
  MainBuf(#TMTCallRecord_Api )
 
  @verbatim
  {
      "dwSn": 1,
      "emCallRecordType": 1,
      "emCallType": 1,
      "achDescribe": "",
	  "emConfMode": 0,
      "achH323Id": "",
      "emAddrType": 1,
      "achE164": 0,
      "achIp": "",
      "achPhoneNumber": "",
      "dwRate": 1,
      "dwTime": 1
   }
@endverbatim
*/
	Ev_MtApi_RecordInsert_Ntf,

	/**
  @brief    �޸�һ����¼Ӧ��	
  
    MainBuf(#TMTRecordErrInfo_Api )\n
	SubBuf(#TMTCallRecord_Api ) 
  
  @verbatim
  {
	"MainParam":
	{
	"emError": 1
	},
	"AssParam": 
	{
	"dwSn": 1,
	"emCallRecordType": 1,
	"emCallType": 1,
	"achDescribe": "",
	"emConfMode": 0,
	"achH323Id": "",
	"emAddrType": 1,
	"achE164": 0,
	"achIp": "",
	"achPhoneNumber": "",
	"dwRate": 1,
	"dwTime": 1
	}
   }
  @endverbatim
*/
	Ev_MtApi_RecordModify_Rsp,

	/**
  @brief    �޸�һ����¼֪ͨ	
  
  MainBuf(#TMTCallRecord_Api )
   
  @verbatim
  {
      "dwSn": 1,
      "emCallRecordType": 1,
      "emCallType": 1,
      "achDescribe": "",
	  "emConfMode": 0,
      "achH323Id": "",
      "emAddrType": 1,
      "achE164": 0,
      "achIp": "",
      "achPhoneNumber": "",
      "dwRate": 1,
      "dwTime": 1
   }
@endverbatim
*/
	Ev_MtApi_RecordModify_Ntf,

/**
  @brief    ����������ѯ��Ӧ��¼Ӧ��	
  
  MainBuf(#TMTRecordErrInfo_Api)\n
  SubBuf(#TMTCallRecordList_Api)

  @verbatim
  {
  "MainParam":
  {
	"emError": 1
  },
  "AssParam": 
  {
	"atRecord": [
		{
			"dwSn": 1,
			"emCallRecordType": 1,
			"emCallType": 1,
			"achDescribe": "",
			 "emConfMode": 0,
			"achH323Id": "",
			"emAddrType": 1,
			"achE164": 0,
			"achIp": "",
			"achPhoneNumber": "",
			"dwRate": 1,
			"dwTime": 1
		}
		]
  }
 }
@endverbatim
*/	

	Ev_MtApi_RecordGetInfoByIndex_Rsp,

	/**
  @brief    ����������ѯ��Ӧ��¼Ӧ�������ʶ	
  
  MainBuf()
  
  @verbatim
  {
  }
@endverbatim
*/	

	Ev_MtApi_RecordGetInfoByIndex_Fin_Rsp,


/**
 @brief    ���ݹؼ�ֵ��ѯ��Ӧ��¼Ӧ��
 
 MainBuf(#TMTRecordErrInfo_Api)\n
 SubBuf(#TRecordSearchInfoAndList_Api)

	@verbatim
{
  "MainParam":
 {
  "emError": 1
  },
  "AssParam": 
  {
  "tSearchInfo":
   {
   "emType": 1,
    "tRecord": 
    {
     "dwSn": 1,
     "emCallRecordType": 1,
     "emCallType": 1,
     "achDescribe": "",
	  "emConfMode": 0,
     "achH323Id": "",
     "emAddrType": 1,
     "achE164": 1,
     "achIp": "",
     "achPhoneNumber": "",
     "dwRate": 1,
     "dwTime": 1
    }
   },
   "tRecordList": 
  {
   "atRecord":
  [
    {
     "dwSn": 1,
     "emCallRecordType": 1,
     "emCallType": 1,
     "achDescribe": "",
	  "emConfMode": 0,
     "achH323Id": "",
     "emAddrType": 1,
     "achE164": 1,
     "achIp": "",
     "achPhoneNumber": "",
     "dwRate": 1,
     "dwTime": 1
    }
   ]
  }
 }
}
@endverbatim
*/
	
	Ev_MtApi_RecordGetInfoByKeyWord_Rsp,

/**
  @brief    ���ݹؼ�ֵ��ѯ��Ӧ��¼Ӧ�𣨷ְ����� )	
  @verbatim
	BODY: ��
  @endverbatim
*/
	Ev_MtApi_RecordGetInfoByKeyWord_Fin_Rsp,

/**
  @brief    �����Ӧ�� 	
  
  MainBuf(#TMTRecordErrInfo_Api)\n
  SubBuf(#TAddrBookGroupInfo_Api)
  
	@verbatim
  {
  "MainParam":
  {
  "emError": 1
  },
  "AssParam": 
  {
  "dwGroupSn": 1,
  "achGroupName": "",
  "dwParentGroupSn": 1,
  "dwGroupLevel": 1
  }
  }
  @endverbatim
*/
	Ev_MtApi_AddrBookAddGroup_Rsp,

/**
  @brief    �����֪ͨ  	
  
  MainBuf(#TAddrBookGroupInfo_Api)
  
  @verbatim
  {
  "MainParam":
  {
  "dwGroupSn": 1,
  "achGroupName": "",
  "dwParentGroupSn": 1,
  "dwGroupLevel": 1	   
  }
  }
  @endverbatim
*/
	Ev_MtApi_AddrBookAddGroup_Ntf,
/**
  @brief    ɾ����Ӧ��  	
  
  MainBuf(#TMTRecordErrInfo_Api )\n
  SubBuf(#u32)
  
  @verbatim
  {
  "MainParam":
  {
  "emError": 1
  },
  "AssParam": 
  {
  "basetype": 1
  }
  }
  @endverbatim
*/
	Ev_MtApi_AddrBookDelGroup_Rsp,
/**
  @brief    ɾ����֪ͨ  	
  
  MainBuf(#u32)
  
  @verbatim
  {
  "MainParam":
  {
  "basetype": 1
  },
  }
  @endverbatim
*/
	Ev_MtApi_AddrBookDelGroup_Ntf,
/**
  @brief    �޸���Ӧ��  	
  
  MainBuf(#TMTRecordErrInfo_Api )\n
  SubBuf(#TAddrBookGroupInfo_Api)
  
  @verbatim
  {
  "MainParam":
  {
  "emError": 1
  },
  "AssParam": 
  {
  "dwGroupSn": 1,
  "achGroupName": "",
  "dwParentGroupSn": 1,
  "dwGroupLevel": 1
  }
  }
  @endverbatim
*/
	Ev_MtApi_AddrBookModifyGroup_Rsp,
/**
  @brief    �޸���֪ͨ  	
  
  MainBuf(#TAddrBookGroupInfo_Api)
  
  @verbatim
  {
  "MainParam":
  {
  "dwGroupSn": 1,
  "achGroupName": "",
  "dwParentGroupSn": 1,
  "dwGroupLevel": 1
  }
  }
  @endverbatim
*/
	Ev_MtApi_AddrBookModifyGroup_Ntf,
/**
  @brief    �����ϵ��Ӧ��  	
  
  MainBuf(#TMTRecordErrInfo_Api)\n
  SubBuf(#TAddrBookRosterInfo_Api)
  
  @verbatim
  {
  "MainParam":
  {
  "emError": 1
  },
  "AssParam": 
  {
  "dwParentGroupSn": 1,
  "dwSn": "",
  "achName": "",
  "achH323Id": "",
  "achE164": "",
  "achIp": "",
  "dwRate": 1,
  "achDescribe": ""
  "achTele":""
  }
  }
  @endverbatim
*/	
	Ev_MtApi_AddrBookAddRoster_Rsp,

/**
  @brief    �����ϵ��֪ͨ  	
  
  MainBuf(#TAddrBookRosterInfo_Api)
  
  @verbatim
  {
  "MainParam":
  {
  "dwParentGroupSn": 1,
  "dwSn": "",
  "achName": "",
  "achH323Id": "",
  "achE164": "",
  "achIp": "",
  "dwRate": 1,
  "achDescribe": ""
  "achTele":""
  }
  }
  @endverbatim
*/		
	Ev_MtApi_AddrBookAddRoster_Ntf,
/**
  @brief    ɾ����ϵ��Ӧ��	
  
  MainBuf(#TMTRecordErrInfo_Api)\n
  SubBuf(#u32)
  
  @verbatim
  {
  "MainParam":
  {
  "emError": 1
  },
  "AssParam": 
  {
  "basetype": 1
  }
  }
  @endverbatim
*/
	
	Ev_MtApi_AddrBookDelRoster_Rsp,

/**
  @brief    ɾ����ϵ��Ӧ��	
  
  MainBuf(#u32)
  
  @verbatim
  {
  "MainParam":
  {
  "basetype": 1
  }
  }
  @endverbatim
*/	
	Ev_MtApi_AddrBookDelRoster_Ntf,

/**
  @brief    �޸���ϵ��Ӧ��	
  
  MainBuf(#TMTRecordErrInfo_Api)\n
  SubBuf(#TAddrBookRosterInfo_Api)
  
  @verbatim
  {
  "MainParam":
  {
  "emError": 1
  },
  "AssParam": 
  {
  "dwParentGroupSn": 1,
  "dwSn": "",
  "achName": "",
  "achH323Id": "",
  "achE164": "",
  "achIp": "",
  "dwRate": 1,
  "achDescribe": ""
  "achTele":""
  }
  }
  @endverbatim
*/	
	Ev_MtApi_AddrBookModifyRoster_Rsp,

/**
  @brief    �޸���ϵ��Ӧ��	
  
  MainBuf(#TAddrBookRosterInfo_Api)
  
  @verbatim
  {
  "MainParam":
  {
  "dwParentGroupSn": 1,
  "dwSn": "",
  "achName": "",
  "achH323Id": "",
  "achE164": "",
  "achIp": "",
  "dwRate": 1,
  "achDescribe": ""
  "achTele":""
  }
  }
  @endverbatim
*/	
	Ev_MtApi_AddrBookModifyRoster_Ntf,

/**
  @brief    ����������ȡ��ϵ��Ӧ��	
  
  MainBuf(#TMTRecordErrInfo_Api)\n
  SubBuf(#TAddrBookRosterList_Api)
  
  @verbatim
  {
  "MainParam":
  {
  "emError": 1
  },
  "AssParam": 
  {
  "byCnt":0,
  "atArray": 
  [
  {
  "dwParentGroupSn": 1,
  "dwSn": "",
  "achName": "",
  "achH323Id": "",
  "achE164": "",
  "achIp": "",
  "dwRate": 1,
  "achDescribe": ""
  "achTele":""
  },
  {
  "dwParentGroupSn": 1,
  "dwSn": "",
  "achName": "",
  "achH323Id": "",
  "achE164": "",
  "achIp": "",
  "dwRate": 1,
  "achDescribe": ""
  "achTele":""
  }
  ]
  }
  }
  @endverbatim
*/	
	Ev_MtApi_AddrBookGetRosterInfoByIndex_Rsp,

	/**
  @brief    ����������ȡ��ϵ��Ӧ��	������ʶ
  
  MainBuf()
  
  @verbatim
  {

  }
  @endverbatim
*/	
	Ev_MtApi_AddrBookGetRosterInfoByIndex_Fin_Rsp,

/**
  @brief    ����������ȡ��Ӧ��	
  
  MainBuf(#TMTRecordErrInfo_Api)\n
  SubBuf(#TAddrBookGroupInfo_Api)
  
  @verbatim
  {
  "MainParam":
  {
  "emError": 1
  },
  "AssParam": 
  {
    "byCnt": 0,
	"tAddrBookGroupInfo_Api": [
	{
		"dwGroupSn": 1,
		"achGroupName": "",
		"dwParentGroupSn": 1,
		"dwGroupLevel": 1
		}
		]
  }
  }
  @endverbatim
*/	
	Ev_MtApi_AddrBookGetGroupInfoByIndex_Rsp,

/**
  @brief    ������Ż�ȡ��ϵ��Ӧ�𣨷ְ���	
  
  MainBuf(#TMTRecordErrInfo_Api)\n
  SubBuf(#TAddrBookRosterList_Api)
  
  @verbatim
  {
  "MainParam":
  {
  "emError": 1
  },
  "AssParam": 
  {
  "byCnt":0,
  "atArray": 
  [
  {
  "dwParentGroupSn": 1,
  "dwSn": "",
  "achName": "",
  "achH323Id": "",
  "achE164": "",
  "achIp": "",
  "dwRate": 1,
  "achDescribe": ""
  "achTele":""
  },
  {
  "dwParentGroupSn": 1,
  "dwSn": "",
  "achName": "",
  "achH323Id": "",
  "achE164": "",
  "achIp": "",
  "dwRate": 1,
  "achDescribe": ""
  "achTele":""
  }
  ]
  }
  }
  @endverbatim
*/	
	Ev_MtApi_AddrBookGetRosterInfoByGroupSn_Rsp,

/**
  @brief    ������Ż�ȡ��ϵ�˷ְ�����֪ͨ
  
  MainBuf(#u32)
  
  @verbatim
  {
  "basetype": 0
  }
  @endverbatim
*/	
	Ev_MtApi_AddrBookGetRosterInfoByGroupSn_Fin_Rsp,

/**
  @brief    ������Ż�ȡ����ϢӦ�𣨷ְ� )	
  
  MainBuf(#TMTRecordErrInfo_Api)\n
  SubBuf(#TAddrBookGroupList_Api)
  
  @verbatim
  {
  "MainParam":
  {
  "emError": 1
  },
  "AssParam": 
  {
  "atArray": 
  [
  {
  "dwGroupSn": 1,
  "achGroupName": "",
  "dwParentGroupSn": 1,
  "dwGroupLevel": 1
  }
  ]
  }
  }
  @endverbatim
*/	
	Ev_MtApi_AddrBookGetGroupInfoByGroupSn_Rsp,

/**
  @brief    ������Ż�ȡ����Ϣ�ְ�����֪ͨ	
  
  MainBuf(#u32)
  
  @verbatim
  {
  "basetype": 0
  }
  @endverbatim
*/	
	Ev_MtApi_AddrBookGetGroupInfoByGroupSn_Fin_Rsp,

/**
  @brief    ���ļ������¸��µ�ַ��������Ӧ������������	
  
  MainBuf(#TMTRecordErrInfo_Api)
  
  @verbatim
  {
  "emError": 1
  }
  @endverbatim
*/	
	Ev_MtApi_AddrBookLoadLocalRosterInfo_Rsp,

	/**
  @brief    ���ļ������¸��µ�ַ��������֪ͨ������������	
  
  MainBuf(#TMTRecordErrInfo_Api)
  
  @verbatim
  {
  "emError": 1
  }
  @endverbatim
*/	
	Ev_MtApi_AddrBookLoadLocalRosterInfo_Ntf,

/**
  @brief    ���ص�ַ��ģ������Ӧ��	
  
  MainBuf(#s8)\n
  SubBuf(#TGroupAndRosterList_Api)
  
  @verbatim
  {
  "MainParam":
  {
     "basetype":""
  },
  "AssParam":
  {
  "tGroupList": 
  {
  "atArray": 
  [
  {
  "dwGroupSn": 1,
  "achGroupName": "",
  "dwParentGroupSn": 1,
  "dwGroupLevel": 1
  }
  ]
  },
  "tRosterList": 
  {
  "atArray": 
  [
  {
  "dwParentGroupSn": 1,
  "dwSn": "",
  "achName": "",
  "achH323Id": "",
  "achE164": "",
  "achIp": "",
  "dwRate": 1,
  "achDescribe": ""
  "achTele":""
  }
  ]
  }
  }
  }
  
  @endverbatim
*/	
	Ev_MtApi_AddrBookSearch_Rsp,

/**
  @brief    ���ص�ַ��ģ����������֪ͨ	
  
  MainParam(#s8)
  
  @verbatim
  {
  "basetype":""
  }
  @endverbatim
*/	
	Ev_MtApi_AddrBookSearch_Fin_Rsp, 
/**
  @brief    ��ȡ��ַ����������Ӧ	
  
  MainParam(#u32)  ����� \n
  SubParam(#u32)  ��ϵ�˸���
  
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
	Ev_MtApi_AddrBookGetTotalNum_Rsp,

/**
  @brief    ��ȡ���ص�ַ����ϵ��+��ĸ���Ӧ�𣨲�������Ƕ���飩	
  
  MainParam(#u32)  ������� \n
  SubParam(#u32)  ��ϵ�˸���
  
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
	Ev_MtApi_AddrBookGetNumByGroupSn_Rsp,

	Ev_MtApi_RecordInit_Fin_Ntf,

/**
  @brief    ���м�¼ģ������Ӧ��	
  
  MainParam(#s8*) \n
  SubParam(#TMTCallRecord_Api)
  
  @verbatim
  {
  "MainParam":
  {
  "basetype": ""
  },
  "AssParam": 
  {
  "dwSn": 1,
  "emCallRecordType": 1,
  "emCallType": 1,
  "achDescribe": "",
   "emConfMode": 0,
  "achH323Id": "",
  "emAddrType": 1,
  "achE164" : 0,
  "achIp": "",
  "achPhoneNumber": "",
  "dwRate": 1,
  "dwTime": 1
  }
  }
  @endverbatim
*/	
	Ev_MtApi_RecordSearch_Rsp,

/**
  @brief   ���м�¼ģ����������Ӧ��	
  
  MainParam(#s8*)
  
  @verbatim
  {
  "MainParam":
  {
  "basetype": ""
  }
  }
  @endverbatim
*/	
	Ev_MtApi_RecordSearch_Fin_Rsp,
 
/**
  @brief    ɾ����ϵ��Ӧ��	
  
  MainParam(#TMTRecordErrInfo_Api)\n
  SubParam(#u32)
  
  @verbatim
  {
  "MainParam":
  {
  "emError": 1
  },
  "AssParam": 
  {
  "basetype": 0
  }
  @endverbatim
*/	
	Ev_MtApi_RecordDelBySn_Rsp,

/**
  @brief    ɾ����ϵ��֪ͨ	
  
  MainParam(#u32)
  
  @verbatim
  {
  "MainParam":
  {
  "basetype": 0
  }
  @endverbatim
*/	
	Ev_MtApi_RecordDelBySn_Ntf,

/**
  @brief    ���ݺ��м�¼���ͻ�ȡ��¼����Ӧ��	
  
  MainParam(#u32)
  
  @verbatim
  {
  "basetype": 0
  }
  @endverbatim
*/
	Ev_MtApi_RecordNumByType_Rsp,

/**
  @brief    ɾ�����к��м�¼֪ͨ	
  
	BODY: ��
  @endverbatim
*/
	Ev_MtApi_RecordClearAll_Ntf,

/**
  @brief    ��֯�ܹ��汾��Ϣ֪ͨ	
  
  MainParam(#TRestErrorInfo_Api)\n
  SubParam(#u64)
  
  @verbatim
  { 
  "MainParam":
  {
  "tRestErrorInfo_Api":
  {
  "achErrorInfo": "",
  "emApiType": 0,
  "dwErrorID": 0,
  "dwNackEventId": 0,
  "adwParams": 
  [
  {
  "basetype" : 0
  }
  ]
  }
  },
  "AssParam": 
  {
  "basetype": 0
  }
  }
  @endverbatim
*/	
	Ev_MtApi_RestGetDepartmentVersion_Rsp,

/**
  @brief    �����ҵ�����ַ���汾��ϢӦ��	
  
  MainParam(#TRestErrorInfo_Api)\n
  SubParam(#TMTVersion_Api)
  
  @verbatim
  {
  "MainParam":
  {
  "tRestErrorInfo_Api":
  {
  "achErrorInfo": "",
  "emApiType": 0,
  "dwErrorID": 0,
  "dwNackEventId": 0,
  "adwParams": 
  [
  {
  "basetype" : 0
  }
  ]
  }
  },
  "AssParam": 
  {
  "achVersion" : "str"
  }
  }
  @endverbatim
*/	
	Ev_MtApi_RestGetSharedDirectoryVer_Rsp,

/**
  @brief    �����ҵ�����ַ����ϢӦ��	
  
  MainParam(#TRestErrorInfo_Api)\n
  SubParam(#TMTAddressBooks_Api)
  
  @verbatim
  {
  "MainParam":
  {
  "tRestErrorInfo_Api": 
  {
  "achErrorInfo": "",
  "emApiType": 0,
  "dwErrorID": 0,
  "dwNackEventId": 0,
  "adwParams":
  [
  {
  "basetype" : 0
  }
  ]
  }
  },
  "AssParam": 
  {
  "dwAddressNum" : 0,
  "atAddress":
  [
  {
  "achId" : "str",
  "achName" : "str",
  "achEmail" : "str",
  "achE164" : "str",
  "achMobilePhone" : "str", 	
  "achExtNum" : "str"
  }
  ]
  }
  }
  @endverbatim
*/	
	Ev_MtApi_RestGetSharedDirectory_Rsp,

/**
  @brief   �����ҵ�����ַ����Ϣ����Ӧ��
  @verbatim
	BODY: ��
  @endverbatim
*/	
	Ev_MtApi_RestGetSharedDirectory_Fin_Rsp,

/**
  @brief    ��ȡ��˾��֯�ܹ�������ϢӦ�𣨷ֶ����	
  
  MainParam(#TRestErrorInfo_Api)\n
  SubParam(#TMTWbParse_Keda_Departments_Api)
  
  @verbatim
  {
  "MainParam":
  {
  "tRestErrorInfo_Api": 
  {
  "achErrorInfo": "str",
  "emApiType": 0,
  "dwErrorID": 0,
  "dwNackEventId": 0,
  "adwParams": 
  [
  {
  "basetype": 0
  }
  ]
  }
  },
  "AssParam": 
  {
  "dwDepartmentNum" : 0,           
  "tDepartment" :
  [
  {
  "dwDepartmentId" : 0,                                        
  "achDepartmentName" : 0,   
  "dwParentId" : 0,                                            
  "achLeaf" : 0,
  "dwSeqNumber" : 0
  }
  ]
  }
  }
  @endverbatim
*/	
	Ev_MtApi_RestGetDepartmentCompany_Rsp,

/**
  @brief    ��ȡ��˾��֯�ܹ�������Ϣ�ְ�������Ϣ
  @verbatim
	BODY: ��
  @endverbatim
*/	
	Ev_MtApi_RestGetDepartmentCompany_Fin_Rsp,

/**
  @brief    ��ù�˾��֯�ܹ���������Ա��ϢӦ�𣨷ֶ����
  
  MainParam(#TRestErrorInfo_Api)\n
  SubParam(#TMTWbParse_Keda_departmentUsers_Api)
  
  @verbatim
  {
  "MainParam":
  {
  "tRestErrorInfo_Api":
  {
  "achErrorInfo": "",
  "emApiType": 0,
  "dwErrorID": 0,
  "dwNackEventId": 0,
  "adwParams": 
  [
  {
  "basetype" : 0
  }
  ]
  }
  },
  "AssParam": 
  {
  "dwUserNum" : 0,
  "atUser" :
  [
  {
  "achId" : "str",
  "achUid" : "str",
  "achName" : "str",
  "achEmail" : "str",
  "achMugshot128" : "str",
  "achPersonalBriefly" : "str",
  "achOnline" : "str",
  "achDefaultUid" : "str",
  "achE164" : "str",
  "achJid" : "str",
  "bEnableWeibo" : 0,
  "dwDepartmentId": 0,
  "tProfile":
  {
  "achUserId" : "str",
  "achJobTitle" : "str",
  "achLocation" : "str",
  "achWorkPhone" : "str",
  "achMobilePhone" : "str"
  }
  }
  ]
  }
  }
  @endverbatim
*/	
	Ev_MtApi_RestGetDepartmentAll_Rsp,

/**
  @brief    ��ù�˾��֯�ܹ���������Ա��Ϣ�ְ�������Ϣ
  
	BODY: ��
  @endverbatim
*/	
	Ev_MtApi_RestGetDepartmentAll_Fin_Rsp,


/**
  @brief    ��ȡ��������Ա��Ϣ(�������Ӳ���)Ӧ�𣨷ְ���
  
  MainParam(#TRestErrorInfo_Api)\n
  SubParam(#TMTWbParse_Keda_departmentUsers_Api)
  
  @verbatim
  {
  "MainParam":
  {
  "tRestErrorInfo_Api":
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
  }
  },
  "AssParam": 
  {
  "dwUserNum" : 0,
  "atUser" :
  [
  {
  "achId" : "str",
  "achUid" : "str",
  "achName" : "str",
  "achEmail" : "str",
  "achMugshot128" : "str",
  "achPersonalBriefly" : "str",
  "achOnline" : "str",
  "achDefaultUid" : "str",
  "achE164" : "str",
  "achJid" : "str",
  "bEnableWeibo" : 0,
  "dwDepartmentId": 0,
  "tProfile":
  {
  "achUserId" : "str",
  "achJobTitle" : "str",
  "achLocation" : "str",
  "achWorkPhone" : "str",
  "achMobilePhone" : "str"
  }
  }
  ]
  }
  }
  @endverbatim
*/	
	Ev_MtApi_RestGetDepartmentUser_Rsp,

/**
  @brief    ��ȡ��������Ա��Ϣ(�������Ӳ���)�ְ�������Ϣ
  
	BODY: ��
  @endverbatim
*/
	Ev_MtApi_RestGetDepartmentUser_Fin_Rsp,

/**
  @brief    ��ȡ��������Ա��Ϣ(�����Ӳ���)Ӧ�𣨷ְ���
  
  MainParam(#TRestErrorInfo_Api)\n
  SubParam(#TMTWbParse_Keda_departmentUsers_Api)
  
  @verbatim
  {
  "MainParam":
  {
      "tRestErrorInfo_Api":
      {
          "achErrorInfo" : "",
          "adwParams" : [],
          "dwErrorID" : 1000, //success
          "dwNackEventId" : 0,
          "dwParamCount" : 0,
          "emApiType" : 0
      }
  },
  "AssParam": 
  {
      "dwUserNum" : 0,
      "atUser" :
      [
          {
              "achMoid" : "str",
              "achJid" : "str",
              "achAccount" : "str",
              "achE164" : "str",
              "achEmail" : "str",
              "achMobile" :"str",
              "achDeviceType":"str",
              "achName" : "str",
              "achExtNum" : "str",
              "achSeat" : "str",
              "achBrief" : "str",
              "achPortrait40" : "str",
              "achPortrait64": "str",
              "achPortrait128":"str"	 
              "dwDepartmentID": 0,
          }
      ]
  }
  @endverbatim
*/	
	Ev_MtApi_RestGetDepartmentAllUser_Rsp,

/**
  @brief    ��ȡ��������Ա��Ϣ(�����Ӳ���)�ְ�������Ϣ
  
	BODY: ��
  @endverbatim
*/
	Ev_MtApi_RestGetDepartmentAllUser_Fin_Rsp,

/**
  @brief    ������ѯ��ҵ��ϵ��Ӧ��
  
  MainParam(#TRestErrorInfo_Api)\n
  SubParam(#TMTWBParse_Keda_QueryUsers_Api)
  
  @verbatim
  {
  "dwTotalCount" : 0,
  "tUsers" :
  {
  "dwUserNum" : 0,
  "atEntUser" :
  [
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
  ]
  }
  }
  @endverbatim
*/	
	Ev_MtApi_RestConditionQuery_Rsp,

/**
  @brief   �����û���ϢӦ��	
  
  MainParam(#TRestErrorInfo_Api)\n
  SubParam(#TMTWbParse_Keda_EntUsers_Api)
  
  @verbatim
  {
  "MainParam":
  {
  "tRestErrorInfo_Api": 
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
  }
  },
  "AssParam": 
  {
  "dwUserNum" : 0,
  "atEntUser" :
  [
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
  ]
  }
  }
  @endverbatim
*/	
	Ev_MtApi_RestQueryUserInfo_Rsp,

/**
  @brief    ��ѯ�û���ϸ��Ϣ���Ӧ��
  
	BODY: ��
  @endverbatim
*/	
	Ev_MtApi_RestQueryUserInfo_Fin_Rsp,

/**
  @brief    �����û�ͷ��Ӧ��
  
  MainParam(#TRestErrorInfo_Api)\n
  SubParam(#TMTQueryPortrait_Api)
  
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
  "basetype" : 0
  }
  ]
  },
  "AssParam": 
  {
  "emPortrait": 0,
  "achPortraitStr": "",
  "achFileName": "",
  "dwRequestPointer": 0
  }
  }
  @endverbatim
*/	
	Ev_MtApi_RestGetUserPortrait_Rsp,

/**
  @brief    �޸��û�ͷ��Ӧ��	
  
  MainParam(#TRestErrorInfo_Api)
  
  @verbatim
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
  }
  @endverbatim
*/	
	Ev_MtApi_RestMotifyUserPortrait_Rsp,

/**
  @brief    �޸ĸ��˽���Ӧ��	
  
  MainParam(#TRestErrorInfo_Api)
  
  @verbatim
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
  }
  @endverbatim
*/	
	Ev_MtApi_RestUpdateBrief_Rsp,

/**
  @brief    ������ģ�����ұ���ҵ��ϵ��Ӧ��	
  
  MainParam(#TRestErrorInfo_Api)\n
  SubParam(#TMTWbParse_Keda_SearchUsers_Api)
  
  @verbatim
  {
  "MainParam":
  {
  "tRestErrorInfo_Api": 
  {
  "achErrorInfo": "",
  "emApiType": 0,
  "dwErrorID": 0,
  "dwNackEventId": 0,
  "adwParams": 
  [
  {
  "basetype" : 0
  }
  ]
  }
  },
  "AssParam":
  {
  "dwTotalCount" : 0,
  "achStr" : "str",
  "tEntUsers" :
  {
  "dwUserNum" : 0,
  "atEntUser" :
  [
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
  ]
  }
  }
  }
  @endverbatim
*/	
	Ev_MtApi_RestUserListByStr_Rsp,

/**
  @brief    ���������ϵ����֤ģʽӦ��	
  

  MainParam(#TRestErrorInfo_Api)
  
  @verbatim
  {
  "achErrorInfo": "",
  "emApiType": 0,
  "dwErrorID": 0,
  "dwNackEventId": 0,
  "adwParams":
  [
  {
  "basetype" : 0
  }
  ]
  }
  @endverbatim
*/	
	Ev_MtApi_RestSetAuthMode_Rsp,

/**
  @brief   �����֯�ܹ�����Ӧ��
  
  MainParam(#TRestErrorInfo_Api)\n
  SubParam(#u32)
  
  @verbatim
  {
  "MainParam":
  {
  "tRestErrorInfo_Api": 
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
  }
  },
  "AssParam":
  {
  "basetype": 0
  } 
  }
  @endverbatim
*/	
	Ev_MtApi_RestGetCompanyEmployeeCount_Rsp,

/**
  @brief    ��ѯ�˺���ϸ��ϢӦ��
  
  MainParam(#TRestErrorInfo_Api)\n
  SubParam(#TMTWbParse_Keda_EntUser_Api)
  
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
  "bEnableUnicat":0,
  "bEnableDownLoad":0,
  "tMtWbParseKedaDepts": 
  {
  "dwDeptNum": 0,
  "tMtWbParseKedaDept":
  [
  "dwDepartmentId": 0,
  "achDepartmentName": ""
  ]
  }
  }
  }
  @endverbatim
*/	
	Ev_MtApi_RestGetAccountInfo_Rsp,

/**
  @brief    �޸��˺���ϸ��ϢӦ��	
  
  MainParam(#TRestErrorInfo_Api)\n
  SubParam(#u32)
  
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
  "basetype": 0
  }
  }
  @endverbatim
*/	
	Ev_MtApi_RestUpdateAccountInfo_Rsp,

/**
  @brief    �޸��˺�����Ӧ��
  
  MainParam(#TRestErrorInfo_Api)
  
  @verbatim
  {
  "achErrorInfo": "",
  "emApiType": 0,
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
	Ev_MtApi_RestUpdatePassword_Rsp,

/**
  @brief    ����������Ӧ��
  
  MainParam(#TRestErrorInfo_Api)
  
  @verbatim
  {
  "achErrorInfo": "",
  "emApiType": 0,
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
	Ev_MtApi_RestPassWordByMail_Rsp,

/**
  @brief    ��ȡ�������ն��豸��汾��ϢӦ��	
  
  MainParam(#TRestErrorInfo_Api)\n
  SubParam(#TMTVersion_Api)
  
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
  "achVersion": "str"
  }
  }
  @endverbatim
*/	
	Ev_MtApi_RestGetThirdPartyTerminalSysVer_Rsp,

/**
  @brief    ��ȡ�������豸����ϢӦ��
  
  MainParam(#TRestErrorInfo_Api)\n
  SubParam(#TMTMonitorGroups_Api)
  
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
  "dwGroupCount": 0,
  "atMonitorGroup": 
  [
  {
  "achId": "str",
  "achGroupId": "str",
  "achGroupName": "str",
  "achParentId": "str",
  "achNewGroup": "str",
  "achLeaf": "str"
  }
  ]
  }
  }
  @endverbatim
*/	
	Ev_MtApi_RestGetAllThirdPartyGroupsInfo_Rsp,

/**
  @brief    ��ȡ�������豸��ϢӦ��
  
  MainParam(#TRestErrorInfo_Api)\n
  SubParam(#TMTMonitorDevices_Api)
  
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
  "dwDeviceCount" : 0,
  "atMonitorDevice" :
  [
  {
  "achGroupId" : "str",
  "achId" : "str",
  "achName" : "str",
  "achDeviceId" : "str",
  "achDeviceGUID" : "str",
  "achE164" : "str",
  "achDeviceType" : "str",
  "achDescription" : "str"
  }
  ]
  }
  }
  @endverbatim
*/	
	Ev_MtApi_RestGetAllThirdPartyDeviceInfo_Rsp,

/**
  @brief   ��ȡ�������ն��豸����豸��ϢӦ��
  
  MainParam(#TRestErrorInfo_Api)
  
  @verbatim
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
  }
  @endverbatim
*/	
	Ev_MtApi_RestGetAllThirdPartyTerminals_Rsp,

/**
  @brief   ��ȡ�������ն��豸����ϢӦ��
  
  MainParam(#TRestErrorInfo_Api)\n
  SubParam(#TMTMonitorGroups_Api)
  
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
  "dwGroupCount": 0,
  "atMonitorGroup": 
  [
  {
  "achId": "str",
  "achGroupId": "str",
  "achGroupName": "str",
  "achParentId": "str",
  "achNewGroup": "str",
  "achLeaf": "str"
  }
  ]
  }
  }
  @endverbatim
*/	
	Ev_MtApi_RestGetThirdPartyGroupsOnly_Rsp,

/**
  @brief    ��ȡ�������ն��豸����ϢӦ��	
  
  MainParam(#TRestErrorInfo_Api)
  
  @verbatim
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
  }
  @endverbatim
*/	
	Ev_MtApi_RestGetThirdPartyTerminalGroups_Rsp,

/**
  @brief    ��ȡ�������ն��豸�����豸��Ϣ(�������ӷ���)Ӧ��
  
  MainParam(#TRestErrorInfo_Api)\n
  SubParam(#TMTMonitorDevices_Api)
  
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
  "dwDeviceCount" : 0,
  "atMonitorDevice" :
  [
  {
  "achGroupId" : "str",
  "achId" : "str",
  "achName" : "str",
  "achDeviceId" : "str",
  "achDeviceGUID" : "str",
  "achE164" : "str",
  "achDeviceType" : "str",
  "achDescription" : "str"
  }
  ]
  }
  }
  @endverbatim
*/	
	Ev_MtApi_RestGetThirdPartyDeviceOnly_Rsp,

/**
  @brief    ��ȡ�������ն��豸�����豸��Ϣ(�������ӷ���)Ӧ��	
  
  MainParam(#TRestErrorInfo_Api)
  
  @verbatim
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
  }
  @endverbatim
*/	
	Ev_MtApi_RestGetThirdPartyTerminalsInGroup_Rsp,

/**
  @brief    ��ȡ����豸��汾��ϢӦ��	
  
  MainParam(#TRestErrorInfo_Api)\n
  SubParam(#TMTVersion_Api)
  
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
  "achVersion": "str"
  }
  }
  @endverbatim
*/	
	Ev_MtApi_RestGetMonitorGroupVersion_Rsp,

/**
  @brief    ��ȡ����豸����豸��ϢӦ��	
  
  MainParam(#TRestErrorInfo_Api)
  
  @verbatim
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
  }
  @endverbatim
*/	
	Ev_MtApi_RestGetAllMonitors_Rsp,

/**
  @brief    ��ȡ����豸����ϢӦ��	
  
  MainParam(#TRestErrorInfo_Api)\n
  SubParam(#TMTMonitorGroups_Api)
  
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
  "dwGroupCount": 0,
  "atMonitorGroup": 
  [
  {
  "achId": "str",
  "achGroupId": "str",
  "achGroupName": "str",
  "achParentId": "str",
  "achNewGroup": "str",
  "achLeaf": "str"
  }
  ]
  }
  }
  @endverbatim
*/	
	Ev_MtApi_RestGetMonitorGroups_Rsp,

/**
  @brief    ��ȡ����豸����Ϣ�ְ�����Ӧ��
  
	BODY: ��
  @endverbatim
*/	
	Ev_MtApi_RestGetMonitorGroups_Fin_Rsp,

/**
  @brief    ��ȡ����豸�����豸��Ϣ(�������ӷ���)Ӧ��	
  
  MainParam(#TRestErrorInfo_Api) \n
  SubParam(#TMTMonitorDevices_Api)
  
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
  "dwDeviceCount" : 0,
  "atMonitorDevice" :
  [
  {
  "achGroupId" : "str",
  "achId" : "str",
  "achName" : "str",
  "achDeviceId" : "str",
  "achDeviceGUID" : "str",
  "achE164" : "str",
  "achDeviceType" : "str",
  "achDescription" : "str"
  }
  ]
  }
  }
  @endverbatim
*/	
	Ev_MtApi_RestGetMonitorInGroup_Rsp,

/**
  @brief ��ȡ����豸�����豸��Ϣ(�������ӷ���)�ְ�����Ӧ��
  
	BODY: ��
  @endverbatim
*/	
	Ev_MtApi_RestGetMonitorInGroup_Fin_Rsp,

/**
@brief    �û�TokenʧЧ,rest�������µ�¼����֮���������ʾ
          Ev_MT_BLL_RestUserTokenExpired_Ntf	
  
	MainParam(#TRestErrorInfo_Api,tRestErr )
	
	@verbatim
	{
		"achErrorInfo": "",
		"emApiType": 0,
		"dwErrorID": 0,
		"dwNackEventId": 0,
		"adwParams": [
			0,
			0
		]
	}
  @endverbatim
*/	
	Ev_MtApi_RestUserTokenExpired_Ntf,

/**
@brief    �û�SessionʧЧ��rest�������µ�¼����֮���������ʾ
           Ev_MT_BLL_RestUserSessionExpired_Ntf
  
	MainParam(#TRestErrorInfo_Api,tRestErr )
	
	@verbatim
	{
		"achErrorInfo": "",
		"emApiType": 0,
		"dwErrorID": 0,
		"dwNackEventId": 0,
		"adwParams": [
			0,
			0
		]
	}
  @endverbatim
*/	
	Ev_MtApi_RestUserSessionExpired_Ntf,

	/**
@brief    ��������rest�������µ�¼����֮���������ʾ
           Ev_MtApi_RestApiHeartBeatErr_Ntf
  
	MainParam(#TRestErrorInfo_Api,tRestErr )
	
	@verbatim
	{
		"achErrorInfo": "",
		"emApiType": 0,
		"dwErrorID": 0,
		"dwNackEventId": 0,
		"adwParams": [
			0,
			0
		]
	}
  @endverbatim
*/	
	Ev_MtApi_RestApiHeartBeatErr_Ntf,

	/*
	@brief    ��ҳ��ѯ�û������ַ����ϢӦ��	
	
	MainParam(#TRestErrorInfo_Api)\n
	SubParam(#TMTAddressBooksForPage_Api)
	
	@verbatim
	{
		"MainParam":
		{
			"tRestErrorInfo_Api": 
			{
				"achErrorInfo": "",
				"emApiType": 0,
				"dwErrorID": 0,
				"dwNackEventId": 0,
				"adwParams":
				[
					{
						"basetype" : 0
					}
				]
			}
		},
		"AssParam": 
		{
		    "dwTotalNum" : 0,
			"dwAddressNum" : 0,
			"atAddress":
			[
			    {
				    "achId" : "str",
					"achName" : "str",
					"achEmail" : "str",
					"achE164" : "str",
					"achMobilePhone" : "str", 	
					"achExtNum" : "str"
			    }
			]
		}
	}
	@endverbatim
	*/	
	Ev_MtApi_RestGetUserDomainAddressBookForPage_Rsp,

	/*
	@brief    �ָ��û�Ĭ��ͷ��Ӧ��
	
	MainParam(#TRestErrorInfo_Api)
	
	@verbatim
	{
		"achErrorInfo": "",
		"emApiType": 0,
		"dwErrorID": 0,
		"dwNackEventId": 0,
		"adwParams":
		[
			{
				"basetype" : 0
			}
		]
	}
	@endverbatim
	*/	
	Ev_MtApi_RestResumeUserPortrait_Rsp,

    /*
	@brief    ��ȡ�û�����Ϣ
	
	MainParam(#TRestErrorInfo_Api)\n
	SubParam(#TMTUserDomains_Api)
	
	@verbatim
	{
		"MainParam":
		{
			"tRestErrorInfo_Api": 
			{
				"achErrorInfo": "",
				"emApiType": 0,
				"dwErrorID": 0,
				"dwNackEventId": 0,
				"adwParams":
				[
				]
			}
		},
		"AssParam": 
		{
		    "dwCount" : 0,
            "atUserDomain":
			[
			    {
				    "achMoid" : "str",
					"achName" : "str",
					"achGroupName" : "str",
					"achParentId" : "str",
					"dwVersion" : 0,
			    }
			]
		}
	}
	@endverbatim
	*/	
    Ev_MtApi_RestGetUserDomain_Rsp,
    /**
      @brief ��ȡ�û�����Ϣ ����
  
	    BODY: ��
      @endverbatim
    */
    Ev_MtApi_RestGetUserDomain_Fin_Rsp,

    /*
	@brief    ��ȡָ���û�����֯�ܹ���Ϣ
	
	MainParam(#TRestErrorInfo_Api)\n
	SubParam(#TMTUserDomainDepartments_Api)
	
	@verbatim
	{
		"MainParam":
		{
			"tRestErrorInfo_Api": 
			{
				"achErrorInfo": "",
				"emApiType": 0,
				"dwErrorID": 0,
				"dwNackEventId": 0,
				"adwParams":
				[
				]
			}
		},
		"AssParam": 
		{
		    "dwCount" : 0,
            "atUserDomainDept":
			[
			    {
				    "achMoid" : "str",
					"dwDepartmentId" : 1,
					"achDepartmentName" : "str",
					"dwParentId" : 1,
					"bLeaf" : 0,
			    }
			]
		}
	}
	@endverbatim
	*/
    Ev_MtApi_RestGetUserDomainDepartments_Rsp,
    /**
      @brief ��ȡָ���û�����֯�ܹ���Ϣ ����
  
	    BODY: ��
      @endverbatim
    */
    Ev_MtApi_RestGetUserDomainDepartments_Fin_Rsp,

    /**
      @brief    ��ȡ�û���������Ա��Ϣ
  
      MainParam(#TRestErrorInfo_Api)\n
      SubParam(#TMTWbParse_Keda_departmentUsers_Api)
  
      @verbatim
      {
      "MainParam":
      {
          "tRestErrorInfo_Api":
          {
              "achErrorInfo": "",
              "emApiType": 0,
              "dwErrorID": 0,
              "dwNackEventId": 0,
              "adwParams":
              [
              ]
          }
      },
      "AssParam": 
      {
          "dwUserNum" : 0,
          "atUser" :
          [
              {
                  "achMoid" : "str",
                  "achJid" : "str",
                  "achAccount" : "str",
                  "achEmail" : "str",
                  "achE164" : "str"
                  "achMobile" : "str",
                  "achName" : "str",
                  "dwDepartmentID": 0,
                  "achExtNum" : "str",
                  "achSeat" : "str",
                  "achBrief" : "str",
                  "achPortrait40" : "str",
                  "achPortrait64" : "str",
                  "achPortrait128" : "str",
              }
          ]
      }
      }
      @endverbatim
    */	
    Ev_MtApi_RestGetAllUserDomainUser_Rsp,
    /**
      @brief ��ȡ�û���������Ա��Ϣ ����
  
	    BODY: ��
      @endverbatim
    */
    Ev_MtApi_RestGetAllUserDomainUser_Fin_Rsp,

  /**
  @brief   ��ü�����֯�ܹ�������Ա����
  
  MainParam(#TRestErrorInfo_Api)\n
  SubParam(#u32)
  
  @verbatim
  {
      "MainParam":
      {
          "tRestErrorInfo_Api": 
          {
              "achErrorInfo": "",
              "emApiType": 0,
              "dwErrorID": 0,
              "dwNackEventId": 0,
              "adwParams":
              [
              ]
          }
      },
      "AssParam":
      {
        "basetype": 0
      } 
  }
  @endverbatim
*/	
    Ev_MtApi_RestGetGroupAllDepartmentUserCount_Rsp,

  /**
  @brief   ��ȡ������Ϣ
  
  MainParam(#TRestErrorInfo_Api)\n
  SubParam(#s8)
  
  @verbatim
  {
      "MainParam":
      {
          "tRestErrorInfo_Api": 
          {
              "achErrorInfo": "",
              "emApiType": 0,
              "dwErrorID": 1000, //1000-success
              "dwNackEventId": 0,
              "adwParams":[]
          }
      },
      "AssParam":
      {
        "basetype": "str"
      } 
  }
  @endverbatim
*/	
    Ev_MtApi_RestGetGroup_Rsp,

  /**
  @brief   ��ȡ���Ź���Ⱥ��汾��
  
  MainParam(#TRestErrorInfo_Api)\n
  SubParam(#s8)
  
  @verbatim
  {
      "MainParam":
      {
          "tRestErrorInfo_Api": 
          {
              "achErrorInfo": "",
              "emApiType": 0,
              "dwErrorID": 1000, //1000-success
              "dwNackEventId": 0,
              "adwParams":[]
          }
      },
      "AssParam":
      {
        "basetype": 123
      } 
  }
  @endverbatim
*/	
    Ev_MtApi_RestGetPublicGroupVersion_Rsp,

     /**
      @brief    ��ȡ���Ź���Ⱥ��
  
      MainParam(#TRestErrorInfo_Api)\n
      SubParam(#TMTPublicGroups_Api)
  
      @verbatim
      {
      "MainParam":
      {
          "tRestErrorInfo_Api":
          {
              "achErrorInfo": "",
              "emApiType": 0,
              "dwErrorID": 1000, //1000-success
              "dwNackEventId": 0,
              "adwParams":[]
          }
      },
      "AssParam": 
      {
          "dwUserNum" : 0,
          "atUser" :
          [
              {
                  "achMoid" : "str",,
                  "achName" : "str",
                  "achParentMoid": "str",
              }
          ]
      }
      }
      @endverbatim
    */	
    Ev_MtApi_RestGetPublicGroup_Rsp,

    /**
      @brief ��ȡ���Ź���Ⱥ�� ����
  
	    BODY: ��
      @endverbatim
    */
    Ev_MtApi_RestGetPublicGroup_Fin_Rsp,

      /**
      @brief    ��ȡ���Ź���Ⱥ��������Ա��Ϣ
  
      MainParam(#TRestErrorInfo_Api)\n
      SubParam(#TMTPublicGroupUsers_Api)
  
      @verbatim
      {
      "MainParam":
      {
          "tRestErrorInfo_Api":
          {
              "achErrorInfo": "",
              "emApiType": 0,
              "dwErrorID": 1000, //1000-success
              "dwNackEventId": 0,
              "adwParams":[]
          }
      },
      "AssParam": 
      {
          "dwUserNum" : 0,
          "atUser" :
          [
              {
                  "achAccount" : "0000000000849",
                  "achBrief" : "",
                  "achE164" : "0000000000849",
                  "achEmail" : "",
                  "achExtNum" : "",
                  "achGroupMoid" : "hlhvdume2s0teiye9pnm0y6l",
                  "achJid" : "449ede78-30cd-4aa1-b7f2-439cfafb1ca1@hello-26",
                  "achMobile" : "",
                  "achMoid" : "449ede78-30cd-4aa1-b7f2-439cfafb1ca1",
                  "achName" : "0000000000849",
                  "achPortrait128" : "",
                  "achPortrait40" : "",
                  "achPortrait64" : "",
                  "achSeat" : ""
              }
          ]
      }
      }
      @endverbatim
    */	
    Ev_MtApi_RestGetPublicGroupUser_Rsp,

    /**
      @brief ��ȡ���Ź���Ⱥ��������Ա��Ϣ ����
  
	    BODY: ��
      @endverbatim
    */
    Ev_MtApi_RestGetPublicGroupUser_Fin_Rsp,

    /**
@brief    �û�SSO_COOKIEʧЧ��rest�������µ�¼����֮���������ʾ
           Ev_MtApi_RestUserSSOCookieExpired_Ntf
  
	MainParam(#TRestErrorInfo_Api,tRestErr )
	
	@verbatim
	{
		"achErrorInfo": "",
		"emApiType": 0,
		"dwErrorID": 0,
		"dwNackEventId": 0,
		"adwParams": [
			0,
			0
		]
	}
  @endverbatim
*/	
	Ev_MtApi_RestUserSSOCookieExpired_Ntf,

    EV_UI_END(MTAPI_CM) = EVSEG_MTAPI_CM_END
};

#define Is_MtApiCM_Msg(m) ((m) >= EV_UI_BGN(MTAPI_CM) && (m) <= EV_UI_END(MTAPI_CM))

/**@}*/

/**@}*/
#endif // _MTAPI_EVENT_CA_H_
