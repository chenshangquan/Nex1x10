/*******************************************************************************//**
*@file          mtapi_event_cm.h
*@brief         实现MTAPI MtContactMgrSdk 给UI(观察者)事件通知的定义
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_EVENT_CM_H_
#define _MTAPI_EVENT_CM_H_
/**@addtogroup event 事件
*@{
*/

/**@addtogroup cmevent 联系人事件
*@{
*/

#include "mtapi_event_def.h"


enum EmMtApiCMEv
{
	EV_UI_BGN(MTAPI_CM)  = EVSEG_MTAPI_CM_BGN,

/**
  @brief    增加一条记录应答	
  
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
  @brief    增加一条记录通知	
  
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
  @brief    修改一条记录应答	
  
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
  @brief    修改一条记录通知	
  
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
  @brief    根据索引查询对应记录应答	
  
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
  @brief    根据索引查询对应记录应答结束标识	
  
  MainBuf()
  
  @verbatim
  {
  }
@endverbatim
*/	

	Ev_MtApi_RecordGetInfoByIndex_Fin_Rsp,


/**
 @brief    根据关键值查询对应记录应答
 
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
  @brief    根据关键值查询对应记录应答（分包结束 )	
  @verbatim
	BODY: 无
  @endverbatim
*/
	Ev_MtApi_RecordGetInfoByKeyWord_Fin_Rsp,

/**
  @brief    添加组应答 	
  
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
  @brief    添加组通知  	
  
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
  @brief    删除组应答  	
  
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
  @brief    删除组通知  	
  
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
  @brief    修改组应答  	
  
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
  @brief    修改组通知  	
  
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
  @brief    添加联系人应答  	
  
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
  @brief    添加联系人通知  	
  
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
  @brief    删除联系人应答	
  
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
  @brief    删除联系人应答	
  
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
  @brief    修改联系人应答	
  
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
  @brief    修改联系人应答	
  
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
  @brief    根据索引获取联系人应答	
  
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
  @brief    根据索引获取联系人应答	结束标识
  
  MainBuf()
  
  @verbatim
  {

  }
  @endverbatim
*/	
	Ev_MtApi_AddrBookGetRosterInfoByIndex_Fin_Rsp,

/**
  @brief    根据索引获取组应答	
  
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
  @brief    根据组号获取联系人应答（分包）	
  
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
  @brief    根据组号获取联系人分包结束通知
  
  MainBuf(#u32)
  
  @verbatim
  {
  "basetype": 0
  }
  @endverbatim
*/	
	Ev_MtApi_AddrBookGetRosterInfoByGroupSn_Fin_Rsp,

/**
  @brief    根据组号获取组信息应答（分包 )	
  
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
  @brief    根据组号获取组信息分包结束通知	
  
  MainBuf(#u32)
  
  @verbatim
  {
  "basetype": 0
  }
  @endverbatim
*/	
	Ev_MtApi_AddrBookGetGroupInfoByGroupSn_Fin_Rsp,

/**
  @brief    从文件中重新更新地址簿的内容应答（无需重启）	
  
  MainBuf(#TMTRecordErrInfo_Api)
  
  @verbatim
  {
  "emError": 1
  }
  @endverbatim
*/	
	Ev_MtApi_AddrBookLoadLocalRosterInfo_Rsp,

	/**
  @brief    从文件中重新更新地址簿的内容通知（无需重启）	
  
  MainBuf(#TMTRecordErrInfo_Api)
  
  @verbatim
  {
  "emError": 1
  }
  @endverbatim
*/	
	Ev_MtApi_AddrBookLoadLocalRosterInfo_Ntf,

/**
  @brief    本地地址簿模糊搜索应答	
  
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
  @brief    本地地址簿模糊搜索结束通知	
  
  MainParam(#s8)
  
  @verbatim
  {
  "basetype":""
  }
  @endverbatim
*/	
	Ev_MtApi_AddrBookSearch_Fin_Rsp, 
/**
  @brief    获取地址簿总人数响应	
  
  MainParam(#u32)  组个数 \n
  SubParam(#u32)  联系人个数
  
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
  @brief    获取本地地址簿联系人+组的个数应答（不算其中嵌套组）	
  
  MainParam(#u32)  子组个数 \n
  SubParam(#u32)  联系人个数
  
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
  @brief    呼叫记录模糊搜索应答	
  
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
  @brief   呼叫记录模糊搜索结束应答	
  
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
  @brief    删除联系人应答	
  
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
  @brief    删除联系人通知	
  
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
  @brief    根据呼叫记录类型获取记录个数应答	
  
  MainParam(#u32)
  
  @verbatim
  {
  "basetype": 0
  }
  @endverbatim
*/
	Ev_MtApi_RecordNumByType_Rsp,

/**
  @brief    删除所有呼叫记录通知	
  
	BODY: 无
  @endverbatim
*/
	Ev_MtApi_RecordClearAll_Ntf,

/**
  @brief    组织架构版本信息通知	
  
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
  @brief    获得企业共享地址簿版本信息应答	
  
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
  @brief    获得企业共享地址簿信息应答	
  
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
  @brief   获得企业共享地址簿信息结束应答
  @verbatim
	BODY: 无
  @endverbatim
*/	
	Ev_MtApi_RestGetSharedDirectory_Fin_Rsp,

/**
  @brief    获取公司组织架构部门信息应答（分多包）	
  
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
  @brief    获取公司组织架构部门信息分包结束消息
  @verbatim
	BODY: 无
  @endverbatim
*/	
	Ev_MtApi_RestGetDepartmentCompany_Fin_Rsp,

/**
  @brief    获得公司组织架构和所有人员信息应答（分多包）
  
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
  @brief    获得公司组织架构和所有人员信息分包结束消息
  
	BODY: 无
  @endverbatim
*/	
	Ev_MtApi_RestGetDepartmentAll_Fin_Rsp,


/**
  @brief    获取部门下人员信息(不包含子部门)应答（分包）
  
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
  @brief    获取部门下人员信息(不包含子部门)分包结束消息
  
	BODY: 无
  @endverbatim
*/
	Ev_MtApi_RestGetDepartmentUser_Fin_Rsp,

/**
  @brief    获取部门下人员信息(包含子部门)应答（分包）
  
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
  @brief    获取部门下人员信息(包含子部门)分包结束消息
  
	BODY: 无
  @endverbatim
*/
	Ev_MtApi_RestGetDepartmentAllUser_Fin_Rsp,

/**
  @brief    条件查询企业联系人应答
  
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
  @brief   请求用户信息应答	
  
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
  @brief    查询用户详细信息完成应答
  
	BODY: 无
  @endverbatim
*/	
	Ev_MtApi_RestQueryUserInfo_Fin_Rsp,

/**
  @brief    请求用户头像应答
  
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
  @brief    修改用户头像应答	
  
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
  @brief    修改个人介绍应答	
  
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
  @brief    按姓名模糊查找本企业联系人应答	
  
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
  @brief    设置添加联系人认证模式应答	
  

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
  @brief   获得组织架构人数应答
  
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
  @brief    查询账号详细信息应答
  
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
  @brief    修改账号详细信息应答	
  
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
  @brief    修改账号密码应答
  
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
  @brief    忘记密码后的应答
  
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
  @brief    获取第三方终端设备组版本信息应答	
  
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
  @brief    获取第三方设备组信息应答
  
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
  @brief    获取第三方设备信息应答
  
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
  @brief   获取第三方终端设备组和设备信息应答
  
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
  @brief   获取第三方终端设备组信息应答
  
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
  @brief    获取第三方终端设备组信息应答	
  
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
  @brief    获取第三方终端设备组下设备信息(不包含子分组)应答
  
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
  @brief    获取第三方终端设备组下设备信息(不包含子分组)应答	
  
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
  @brief    获取监控设备组版本信息应答	
  
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
  @brief    获取监控设备组和设备信息应答	
  
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
  @brief    获取监控设备组信息应答	
  
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
  @brief    获取监控设备组信息分包结束应答
  
	BODY: 无
  @endverbatim
*/	
	Ev_MtApi_RestGetMonitorGroups_Fin_Rsp,

/**
  @brief    获取监控设备组下设备信息(不包含子分组)应答	
  
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
  @brief 获取监控设备组下设备信息(不包含子分组)分包结束应答
  
	BODY: 无
  @endverbatim
*/	
	Ev_MtApi_RestGetMonitorInGroup_Fin_Rsp,

/**
@brief    用户Token失效,rest正在重新登录，告之界面进行提示
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
@brief    用户Session失效，rest正在重新登录，告之界面进行提示
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
@brief    心跳错误，rest正在重新登录，告之界面进行提示
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
	@brief    分页查询用户域共享地址簿信息应答	
	
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
	@brief    恢复用户默认头像应答
	
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
	@brief    获取用户域信息
	
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
      @brief 获取用户域信息 结束
  
	    BODY: 无
      @endverbatim
    */
    Ev_MtApi_RestGetUserDomain_Fin_Rsp,

    /*
	@brief    获取指定用户域组织架构信息
	
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
      @brief 获取指定用户域组织架构信息 结束
  
	    BODY: 无
      @endverbatim
    */
    Ev_MtApi_RestGetUserDomainDepartments_Fin_Rsp,

    /**
      @brief    获取用户域所有人员信息
  
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
      @brief 获取用户域所有人员信息 结束
  
	    BODY: 无
      @endverbatim
    */
    Ev_MtApi_RestGetAllUserDomainUser_Fin_Rsp,

  /**
  @brief   获得集团组织架构所有人员总数
  
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
  @brief   获取集团信息
  
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
  @brief   获取集团公共群组版本号
  
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
      @brief    获取集团公共群组
  
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
      @brief 获取集团公共群组 结束
  
	    BODY: 无
      @endverbatim
    */
    Ev_MtApi_RestGetPublicGroup_Fin_Rsp,

      /**
      @brief    获取集团公共群组所有人员信息
  
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
      @brief 获取集团公共群组所有人员信息 结束
  
	    BODY: 无
      @endverbatim
    */
    Ev_MtApi_RestGetPublicGroupUser_Fin_Rsp,

    /**
@brief    用户SSO_COOKIE失效，rest正在重新登录，告之界面进行提示
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
