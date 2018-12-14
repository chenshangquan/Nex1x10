/*******************************************************************************//**
*@file          mtapi_cmapi.h
*@brief         提供mtcontactmgrapi对外接口
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_CMAPI_H_
#define _MTAPI_CMAPI_H_
/**@addtogroup api API接口
*@{
*/

/**@addtogroup cmapi 联系人API
*@{
*/

/** @page mypage1 This is a section in group 5
 *  Text of the first section
 */

/** @page mypage2 This is another section in group 5
 *  Text of the second section
 *  sdfslfjslfjsdlfj
 */



#include <string.h>
#include "mtapi_export.h"
#include "mtapi_typedef.h"
#include "mtapi_struct.h"


 

/**
* KdvMt_CMIsInited
*
* @brief mtcontactmgrapi是否进行过初始化
*
* @param	[in] void
* @return	BOOL32  TRUE ： 已初始化， FALSE：尚未初始化
* @note KdvMt_CMInitalize, KdvMt_CMUnInitalize
*/
KdvMtAPI BOOL32 KdvMtCALL KdvMt_CMIsInited();


/**
* KdvMt_CMSetNotify
*
* @brief  注册Observer(UI)通知回调(这个函数如果没有调用则使用mtbaseapi中的回调函数)
*
* @param    [in]   cbNotify  要注册的回调函数
* @return   void
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CMSetNotify( IN NOTIFY_OBSERVER_CALLBACK cbNotify );


/**
* KdvMt_CMInitalize
*
* @brief mtcontactmgrapi模块初始化（这个的调用要在mtbaseapi调用的setnotify之后）
*
* @return	u32  0: 初始化成功， 非0: 初始化失败
* @note KdvMt_CMIsInited, KdvMt_CMUnInitalize
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CMInitalize( );



/**
* KdvMt_CMUnInitalize
*
* @brief mtcontactmgrapi模块释放退出
*
* @param	[in] void
* @return	u32  0: 成功， 非0: 失败
* @note KdvMt_CMIsInited, KdvMt_CMInitalize
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CMUnInitalize();

/** 
* KdvMt_RecordInsertReq
*
* @brief  增加一条呼叫记录
*
* @param    [TMTCallRecord_Api]   tCallRecord  呼叫记录信息 
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RecordInsert_Rsp, Ev_MtApi_RecordInsert_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RecordInsertReq( const TMTCallRecord_Api & tCallRecord, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_RecordModifyReq
*
* @brief  修改一条呼叫记录
*
* @param    [TMTCallRecord_Api]   tCallRecord  呼叫记录信息 
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RecordModify_Rsp, Ev_MtApi_RecordModify_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RecordModifyReq( const TMTCallRecord_Api & tCallRecord, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_RecordDelBySnReq
* @brief  根据标示值删除对应记录
*
* @param    [u32]   dwSn  标示值 
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知： Ev_MtApi_RecordDelBySn_Rsp, Ev_MtApi_RecordDelBySn_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RecordDelBySnReq( const u32 dwSn, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_RecordGetInfoByIndexReq
*
* @brief 根据索引号获取呼叫记录信息
*
* @param    [u32]   dwStartIndex  起始索引值
* @param    [u32]   dwCount  数量
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RecordGetInfoByIndex_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RecordGetInfoByIndexReq( const u32 dwStartIndex, const u32 dwCount ,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_RecordGetInfoByKeyWordReq
*
* @brief  根据关键值查询对应记录请求
*
* @param    [TMTRecordSearch_Api]   tRecord  要查询的类型 
* @param    [u32]   每包个数
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RecordGetInfoByKeyWord_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RecordGetInfoByKeyWordReq( const TMTRecordSearch_Api & tRecord, const u32 dwNum, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_RecordSearchReq
*
* @brief  呼叫记录模糊搜索请求
*
* @param    [s8]   pachKeyWord  关键字 
		    [u32]  每包数量
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RecordSearch_Rsp, Ev_MtApi_RecordSearch_Fin_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RecordSearchReq( const s8 * pachKeyWord, const u32 dwNum, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/** 
* KdvMt_RecordSetMaxOneCallNumCmd
*
* @brief 同一个呼叫最大保留个数
*
* @param    [u32]   dwNum  最大保留个数
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RecordSetMaxOneCallNumCmd( const u32 dwNum, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_RecordNumByTypeReq
*
* @brief 根据呼叫类型获取呼叫个数
*
* @param    [EmMtCallRecordType]   emCallType  呼叫类型
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RecordNumByType_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RecordNumByTypeReq( const EmMtCallRecordType_Api emCallType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_RecordClearAllCmd
*
* @brief 删除所有呼叫记录
*
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知： Ev_MtApi_RecordClearAll_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RecordClearAllCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_AddrBookAddGroupReq
*
* @brief 地址簿:添加组
*
* @param    [TAddrBookGroupInfo_Api]   tAddrBookGroupInfo_Api  组信息 
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_AddrBookAddGroup_Rsp, Ev_MtApi_AddrBookAddGroup_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AddrBookAddGroupReq( const TAddrBookGroupInfo_Api& tAddrBookGroupInfo_Api ,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_AddrBookDelGroupReq
*
* @brief  地址簿:删除组
*
* @param    [u32]     dwGroupSn  组编号
* @param    [BOOL32]  bMoved  是否移除
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_AddrBookDelGroup_Rsp, Ev_MtApi_AddrBookDelGroup_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AddrBookDelGroupReq( const u32 dwGroupSn, const BOOL32 bMoved,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_AddrBookModifyGroupReq
*
* @brief  地址簿:修改组
*
* @param    [TAddrBookGroupInfo_Api]   tAddrBookGroupInfo_Api  组信息 
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_AddrBookModifyGroup_Rsp, Ev_MtApi_AddrBookModifyGroup_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AddrBookModifyGroupReq( const TAddrBookGroupInfo_Api& tAddrBookGroupInfo_Api,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_AddrBookAddRosterReq
*
* @brief  添加联系人请求
*
* @param    [TAddrBookRosterInfo_Api]   tAddrBookRosterInfo_Api  联系人信息 
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_AddrBookAddRoster_Rsp, Ev_MtApi_AddrBookAddRoster_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AddrBookAddRosterReq( const TAddrBookRosterInfo_Api& tAddrBookRosterInfo_Api,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_AddrBookDelRosterReq
*
* @brief  删除联系人请求
*
* @param    [u32]   dwRosterSn  联系人序号 
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_AddrBookDelRoster_Rsp, Ev_MtApi_AddrBookDelRoster_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AddrBookDelRosterReq( const u32 dwRosterSn,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_AddrBookModifyRosterReq
*
* @brief  修改联系人
*
* @param    [TAddrBookRosterInfo_Api]   tAddrBookRosterInfo_Api  联系人信息 
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_AddrBookModifyRoster_Rsp, Ev_MtApi_AddrBookModifyRoster_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AddrBookModifyRosterReq( const TAddrBookRosterInfo_Api& tAddrBookRosterInfo_Api,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_AddrBookGetRosterInfoByIndexReq
*
* @brief  根据索引获取联系人请求
*
* @param    [u32]   dwStartIndex  呼叫记录信息
* @param    [u32]   dwCount  呼叫记录信息 
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_AddrBookGetRosterInfoByIndex_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AddrBookGetRosterInfoByIndexReq( const u32 dwStartIndex, const u32 dwCount,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_AddrBookGetGroupInfoByIndexReq
*
* @brief  根据索引获取组请求
*
* @param    [u32]   dwStartIndex  起始位置 
* @param    [u32]   dwCount  数量
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_AddrBookGetGroupInfoByIndex_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AddrBookGetGroupInfoByIndexReq( const u32 dwStartIndex, const u32 dwCount,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_AddrBookGetRosterInfoByGroupSnReq
*
* @brief  根据组号获取联系人请求
*
* @param    [u32]   dwGroupSn  组号 
* @param    [u32]   dwCount  分包，每包的数量 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_AddrBookGetRosterInfoByGroupSn_Rsp, Ev_MtApi_AddrBookGetRosterInfoByGroupSn_Fin_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AddrBookGetRosterInfoByGroupSnReq( const u32 dwGroupSn, const u32 dwCount,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_AddrBookGetGroupInfoByGroupSnReq
*
* @brief  根据组号获取组信息请求
*
* @param    [u32]   dwGroupSn  呼叫记录信息 
* @param    [u32]   dwCount  分包，每包的数量 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_AddrBookGetGroupInfoByGroupSn_Rsp, Ev_MtApi_AddrBookGetGroupInfoByGroupSn_Fin_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AddrBookGetGroupInfoByGroupSnReq( const u32 dwGroupSn, const u32 dwCount , IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_AddrBookSetLocalRosterPathCmd
*
* @brief  置本地地址簿存放文件路径
*
* @param    [s8*]   pszPath  路径 
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：暂无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AddrBookSetLocalRosterPathCmd( const s8* pszPath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_AddrBookLoadLocalRosterInfoReq
*
* @brief  从文件中重新更新地址簿的内容请求（无需重启）
*
* @param    [s8*]   pszPath  路径 
			[u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_AddrBookLoadLocalRosterInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AddrBookLoadLocalRosterInfoReq( const s8* pszPath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_AddrBookSearchReq
*
* @brief  本地地址簿模糊搜索请求
*
* @param    [s8*]  pszSearchWord  关键字 
		    [u32]  每包个数
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_AddrBookSearch_Rsp, Ev_MtApi_AddrBookSearch_Fin_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AddrBookSearchReq( const s8* pszSearchWord, u32 dwNum, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_AddrBookSearchReq
*
* @brief  获取地址簿总人数请求
*
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_AddrBookGetTotalNum_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AddrBookGetTotalNumReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_AddrBookGetNumByGroupSnReq
*
* @brief  根据组Sn获取本地地址簿联系人+组的个数（不算其中嵌套组）请求
*
* @param    [u32]   dwGroupSn  组Sn
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_AddrBookGetNumByGroupSn_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AddrBookGetNumByGroupSnReq( IN CONST u32 dwGroupSn, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_GetDepartmentVersionReq
*
* @brief  获取组织架构版本号
*
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestGetDepartmentVersion_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetDepartmentVersionReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_GetSharedDirectoryVersionReq
*
* @brief  获得企业共享地址簿版本信息请求
*
* @param    [u32]   dwDepartmentID  部门ID (接口问题,此参数不用填写)
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestGetSharedDirectoryVer_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetSharedDirectoryVersionReq( u32 dwDepartmentID , IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );


/** 
* KdvMt_GetSharedDirectoryReq
*
* @brief  获得企业共享地址簿信息请求
*
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestGetSharedDirectory_Rsp, Ev_MtApi_RestGetSharedDirectory_Fin_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetSharedDirectoryReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_GetDepartmentAllReq
*
* @brief  获得公司组织架构和所有人员信息请求
*
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestGetDepartmentAll_Rsp, Ev_MtApi_RestGetDepartmentAll_Fin_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetDepartmentAllReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_GetDepartmentCompanyReq
*
* @brief  获取公司组织架构部门信息请求
*
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：	Ev_MtApi_RestGetDepartmentCompany_Rsp, Ev_MtApi_RestGetDepartmentCompany_Fin_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetDepartmentCompanyReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_GetDepartmentUserReq
*
* @brief  获取部门下人员信息(不包含子部门)请求
*
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestGetDepartmentUser_Rsp, Ev_MtApi_RestGetDepartmentUser_Fin_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetDepartmentUserReq( IN CONST u32 dwDepartmentID, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/** 
* KdvMt_ConditionQueryReq
*
* @brief  条件查询企业联系人请求
*
* @param    [TMTConditionQuery_Api]   tInfo  条件查询 
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知： Ev_MtApi_RestConditionQuery_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConditionQueryReq( IN CONST TMTConditionQuery_Api & tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/** 
* KdvMt_QueryUserInfoReq
*
* @brief  请求用户信息请求
*
* @param    [TMTQueryUser_Api]   tUser  
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestQueryUserInfo_Rsp, Ev_MtApi_RestQueryUserInfo_Fin_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_QueryUserInfoReq( IN CONST TMTQueryUser_Api & tUser, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/** 
* KdvMt_SetPortraitPathCmd
*
* @brief  设置保存头像的路径
*
* @param    [s8 *]   pchPath  路径
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetPortraitPathCmd( IN CONST s8 * pchPath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/** 
* KdvMt_GetUserPortraitReq
*
* @brief  请求用户头像请求
*
* @param    [TMTQueryPortrait_Api]   tPortrait  请求用户头像
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestGetUserPortrait_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetUserPortraitReq( IN CONST TMTQueryPortrait_Api & tPortrait, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/** 
* KdvMt_MotifyUserPortraitReq
* 
* @brief  修改用户头像请求
*
* @param    [TMTModifyPortrait_Api]   tPortrait  修改用户头像
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestMotifyUserPortrait_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MotifyUserPortraitReq( IN CONST TMTModifyPortrait_Api & tPortrait, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_UpdateUserBriefReq
* 
* @brief  修改个人介绍请求
*
* @param    [TMTModifyBrief_Api]   tBrief  个人介绍
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestUpdateBrief_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_UpdateUserBriefReq( IN CONST TMTModifyBrief_Api & tBrief, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_GetUserListByStrReq（其中，请求的size，一般为5-6个，再多，有可能会发生，OSP包过大，直接丢弃的情况，请注意）
* 
* @brief  按姓名模糊查找本企业联系人请求
*
* @param    [TMTUserListByStr_Api]   tUserList  姓名模糊查找本企业联系人
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestUserListByStr_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetUserListByStrReq( IN CONST TMTUserListByStr_Api & tUserList, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_SetAuthModeReq
* 
* @brief  设置添加联系人认证模式请求
*
* @param    [TMTSetAuthMode_Api]   tSetAuthMode 联系人认证模式
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestSetAuthMode_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetAuthModeReq( IN CONST TMTSetAuthMode_Api & tSetAuthMode, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_GetCompanyEmployeeCountReq
* 
* @brief  获得组织架构人数请求
*
* @param    [string] strUserDomainMoid  用户域ID 
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestGetCompanyEmployeeCount_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetCompanyEmployeeCountReq(IN CONST s8 *pchUserDomainMoid = NULL, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_GetAccountInfoReq
* 
* @brief  查询账号详细信息请求
*
* @param    [TMTAccountManagerSystem_Api]   tAccount  账号信息 
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestGetAccountInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetAccountInfoReq( const TMTAccountManagerSystem_Api & tAccount , IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );


/**
* KdvMt_UpdateAccountInfoReq
* 
* @brief  修改账号详细信息请求
*
* @param    [TMTAccountManagerSystem_Api]   tAccount  账号信息 
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestUpdateAccountInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_UpdateAccountInfoReq( const TMTAccountManagerSystem_Api & tAccount , IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );


/**
* KdvMt_UpdatePasswordReq
* 
* @brief  修改账号密码请求
*
* @param    [TMTModifyPwd_Api]   tPsw  密码
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestUpdatePassword_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_UpdatePasswordReq( const TMTModifyPwd_Api & tPsw , IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );


/** 
* KdvMt_PassWordByMailReq
* 
* @brief  忘记密码后的请求
*
* @param    [s8]   pchMail  邮箱
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestPassWordByMailRsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_PassWordByMailReq( const s8 * pchMail , IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );


/** 
* KdvMt_GetThirdPartyTerminalSysVersionReq
* 
* @brief  获取第三方终端设备组版本信息请求
*
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestGetThirdPartyTerminalSysVer_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetThirdPartyTerminalSysVersionReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );


/** 
* KdvMt_GetAllThirdPartyTerminalsReq
* 
* @brief  获取第三方终端设备组和设备信息请求
*
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestGetAllThirdPartyGroupsInfo_Rsp,
                  Ev_MtApi_RestGetAllThirdPartyDeviceInfo_Rsp, 
				  Ev_MtApi_RestGetAllThirdPartyTerminals_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetAllThirdPartyTerminalsReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_GetThirdPartyTerminalGroupsReq
* 
* @brief  获取第三方终端设备组信息请求
*
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestGetThirdPartyGroupsOnly_Rsp, 
                  Ev_MtApi_RestGetThirdPartyTerminalGroups_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetThirdPartyTerminalGroupsReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_GetThirdPartyTerminalsInGroupReq
* 
* @brief  获取第三方终端设备组下设备信息(不包含子分组)请求
*
* @param    [u32]   dwGroupId  设备组ID
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestGetThirdPartyDeviceOnly_Rsp,
                  Ev_MtApi_RestGetThirdPartyTerminalsInGroup_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetThirdPartyTerminalsInGroupReq( const u32 & dwGroupId , IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );


/**
* KdvMt_GetMonitorGroupVersionReq
* 
* @brief  获取监控设备组版本信息请求
*
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestGetMonitorGroupVersion_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetMonitorGroupVersionReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_GetAllMonitorsReq
* 
* @brief  获取监控设备组和设备信息请求
*
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestGetAllMonitors_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetAllMonitorsReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_GetMonitorGroupReq
* 
* @brief  获取监控设备组信息请求
*
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestGetMonitorGroups_Rsp, Ev_MtApi_RestGetMonitorGroups_Fin_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetMonitorGroupReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_GetMonitorsInGroupReq
* 
* @brief  获取监控设备组下设备信息(不包含子分组)请求
*
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestGetMonitorInGroup_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetMonitorsInGroupReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*KdvMt_InitAddrBookCmd
*@brief 初始化本地地址簿
*@param	    [s8]     pchPath 本地地址簿绝对路径（路径+全文件名）
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AddrInitAddrBookCmd(CONST s8 *pchPath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*KdvMt_AddrClearAddrBookCmd
*@brief 清理本地地址薄命令
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AddrClearAddrBookCmd(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/** 
* KdvMt_GetUserDomainAddressBookForPageReq
* 
* @brief  分页查询用户域共享地址簿信息请求
*
* @param    [u32]   dwStart  起始，例如：0（表示从第1条开始），10（表示从第11条开始），依次类推 
* @param    [u32]   dwCount  返回条数，例如：10
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestGetUserDomainAddressBookForPage_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetUserDomainAddressBookForPageReq( IN CONST u32 dwStart, IN CONST u32 dwCount, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_ResumeUserPortraitReq
* 
* @brief  恢复用户默认头像请求
*
* @param    [s8*]   pchUserName  用户名
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestResumeUserPortrait_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ResumeUserPortraitReq( IN CONST s8 *pchUserName, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_RestGetUserDomainReq
* 
* @brief  获取用户域信息请求
*
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestGetUserDomain_Rsp, Ev_MtApi_RestGetUserDomain_Fin_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RestGetUserDomainReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_RestGetUserDomainDepartmentsReq
* 
* @brief  获取指定用户域组织架构信息
*
* @param    [s8*]   pchUserDomainMoid  用户域moid
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestGetUserDomainDepartments_Rsp, Ev_MtApi_RestGetUserDomainDepartments_Fin_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RestGetUserDomainDepartmentsReq( IN CONST s8 *pchUserDomainMoid, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_RestGetAllUserDomainUserReq
* 
* @brief  获取用户域所有人员信息
*
* @param    [s8*]   pchUserDomainMoid  用户域moid 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestGetAllUserDomainUser_Rsp, Ev_MtApi_RestGetAllUserDomainUser_Fin_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RestGetAllUserDomainUserReq( IN CONST s8 *pchUserDomainMoid, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_RestGetGroupAllDepartmentUserCountReq
* 
* @brief  获得集团组织架构所有人员总数
*
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestGetGroupAllDepartmentUserCount_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RestGetGroupAllDepartmentUserCountReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_RestGetGroupReq
* 
* @brief  获取集团信息
*
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestGetGroup_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RestGetGroupReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_RestGetPublicGroupVersionReq
* 
* @brief  获取集团公共群组版本号
*
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestGetPublicGroupVersion_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RestGetPublicGroupVersionReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_RestGetPublicGroupReq
* 
* @brief  获取集团公共群组
*
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestGetPublicGroup_Rsp, Ev_MtApi_RestGetPublicGroup_Fin_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RestGetPublicGroupReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_RestGetPublicGroupUserReq
* 
* @brief  获取集团公共群组
*
* @param    [u32]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_RestGetPublicGroupUser_Rsp, Ev_MtApi_RestGetPublicGroupUser_Fin_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RestGetPublicGroupUserReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**@}*/

/**@}*/
#endif //_MTAPI_CMAPI_H_