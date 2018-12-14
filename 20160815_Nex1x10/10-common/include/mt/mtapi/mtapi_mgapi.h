/*******************************************************************************//**
*@file          mtapi_mgapi.h
*@brief         提供mtmeetingmgrapi对外接口
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_MGAPI_H_
#define _MTAPI_MGAPI_H_
/**@addtogroup api API接口
*@{
*/

/**@addtogroup mgapi 会管API
*@{
*/

#include <string.h>
#include "mtapi_export.h"
#include "mtapi_typedef.h"
#include "mtapi_struct.h"


 

/**
* KdvMt_MGIsInited
*
* @brief mtmeetingmgrapi是否进行过初始化
*
* @param	[in] void
* @return	BOOL32  TRUE ： 已初始化， FALSE：尚未初始化
* @note KdvMt_MGInitalize, KdvMt_MGUnInitalize
*/
KdvMtAPI BOOL32 KdvMtCALL KdvMt_MGIsInited();



/**
* KdvMt_MGInitalize
*
* @brief mtmeetingmgrapi模块初始化（这个的调用要在mtbaseapi调用的setnotify之后）
*
* @return	u32  0: 初始化成功， 非0: 初始化失败
* @note KdvMt_MGIsInited, KdvMt_MGUnInitalize
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGInitalize( );



/**
* KdvMt_MGUnInitalize
*
* @brief mtmeetingmgrapi模块释放退出
*
* @param	[in] void
* @return	u32  0: 成功， 非0: 失败
* @note KdvMt_MGIsInited, KdvMt_MGInitalize
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGUnInitalize();


/**
* KdvMt_MGSetNotify
*
* @brief  注册Observer(UI)通知回调(这个函数如果没有调用则使用mtbaseapi中的回调函数)
*
* @param    [in]   cbNotify  要注册的回调函数
* @return   void
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGSetNotify( IN NOTIFY_OBSERVER_CALLBACK cbNotify );



/**
* KdvMt_MGSetNotify
*
* @brief  获取会议室列表请求
*
* @param    [in]   tMtMeetingList_Api  虚拟会议室请求信息
* @param    [in]     dwSSID  MT会话ID 
* @return   void
* @note		响应消息：Ev_MtApi_RestGetMeetingList_Rsp（错误的时候才会发）
					 Ev_MtApi_RestGetMeetingShortRoom_Ntf
					 Ev_MtApi_RestGetMeetingRoomId_Ntf
					 Ev_MtApi_RestGetShortMeeting_Ntf
					 Ev_MtApi_RestGetMeetingList_Fin_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetMeetingListReq( IN CONST TMTMeetingList_Api& tMtMeetingList_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


//by-qwchan-part-mtmeetingctrl begin

/**
* KdvMt_MGRestGetMeetingInfoReq
*
* @deprecated 此接口为兼容老版本，建议使用新版本接口
* @brief  获取会议详细信息请求
*
* @param	[in]	dwConfID-->会议ID号
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetMeetingInfo_Rsp
                                     Ev_MtApi_RestGetParticipants_Rsp（出错不会发）
                                     Ev_MtApi_RestGetParticipants_Fin_Rsp（出错不会发）
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetMeetingInfoReq( IN CONST u32 dwConfID, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetBookingInfoReq
*
* @brief  获取会议室预定信息请求
*
* @param	[in]	tMtBookingInfo_Api-->会议室预定信息过滤条件
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetBookingInfo_Rsp（错误的时候才会发）
					 Ev_MtApi_RestGetBookingShortRoom_Ntf
					 Ev_MtApi_RestGetBookingRoomId_Ntf
					 Ev_MtApi_RestGetBookingShortMeeting_Ntf
					 Ev_MtApi_RestGetBookingInfo_Fin_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetBookingInfoReq( IN CONST TMTBookingInfo_Api& tMtBookingInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetMeetingListOfPersonReq
*
* @brief  获取某人的会议信息请求
*
* @param	[in]	tMtMeetingListOfPerson_Api-->某人的会议信息过滤条件
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetMeetingListOfPerson_Rsp（错误的时候才会发）
					 Ev_MtApi_RestGetPersonShortRoom_Ntf
					 Ev_MtApi_RestGetPersonRoomId_Ntf
					 Ev_MtApi_RestGetPersonShortMeeting_Ntf
					 Ev_MtApi_RestGetMeetingListOfPerson_Fin_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetMeetingListOfPersonReq( IN CONST TMTMeetingListOfPerson_Api& tMtMeetingListOfPerson_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestAddMeetingReq（以后这个接口将会去掉，暂时因为TT那边在用，所以没有删，今后统一走会议业务创会接口: KdvMt_ConfCreateConfCmd）
*
* @brief  创建会议请求
*
* @param	[in]	tMtAddMeeting_Api-->创建的参数
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestAddMeeting_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestAddMeetingReq( IN CONST TMTAddMeeting_Api& tMtAddMeeting_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestModifyMeetingReq
*
* @brief  修改会议请求
*
* @param	[in]	tMtModifyMeeting_Api-->修改的参数
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestModifyMeeting_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestModifyMeetingReq( IN CONST TMTModifyMeeting_Api& tMtModifyMeeting_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestDeleteMeetingReq
*
* @brief  删除会议请求
*
* @param	[in]	dwConfID-->删除的会议ID号
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DeleteMeeting_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestDeleteMeetingReq( IN CONST u32 dwConfID, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestStartMeetingReq
*
* @brief  开始会议请求
*
* @param	[in]	dwConfID-->会议ID号
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestStartMeeting_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestStartMeetingReq( IN CONST u32 dwConfID, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestEndMeetingReq
*
* @deprecated 此接口为兼容老版本，建议使用新版本接口
* @brief  结束会议请求
*
* @param	[in]	dwConfID-->会议ID号
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestEndMeeting_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestEndMeetingReq( IN CONST u32 dwConfID, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestMeetingFeedReq
*
* @brief  会议反馈请求
*
* @param	[in]	tMtMeetingFeed_Api-->反馈参数
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestMeetingFeed_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestMeetingFeedReq( IN CONST TMTMeetingFeed_Api& tMtMeetingFeed_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestQueryFreeRoomsReq
*
* @brief  获取空闲会议室请求
*
* @param	[in]	tMtQueryFreeRooms_Api-->空闲会议室过滤条件
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestQueryFreeRooms_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestQueryFreeRoomsReq( IN CONST TMTQueryFreeRooms_Api& tMtQueryFreeRooms_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetRecommendedVirtualRoomReq
*
* @brief  获取推荐的虚拟会议室请求
*
* @param	[in]	tMtRecommendedVirtualRoom_Api-->会议室过滤条件
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetRecommendedVirtualRoom_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetRecommendedVirtualRoomReq( IN CONST TMTRecommendedVirtualRoom_Api& tMtRecommendedVirtualRoom_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetNormalRoomsReq
*
* @brief  获取正常的会议室请求
*
* @param	[in]	tMtNormalRooms_Api-->会议室过滤条件
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetNormalRooms_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetNormalRoomsReq( IN CONST TMTNormalRooms_Api& tMtNormalRooms_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetRoomInfoReq
*
* @brief  根据Id获取会议室请求
*
* @param	[in]	dwConfID-->会议ID号
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetRoomInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetRoomInfoReq( IN CONST u32 dwConfID, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetRoomListByNameReq
*
* @brief  根据名称搜索会议室请求
*
* @param	[in]	tMtRoomListByName_Api-->会议室过滤条件
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetRoomListByName_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetRoomListByNameReq( IN CONST TMTRoomListByName_Api& tMtRoomListByName_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestQueryRoomsReq
*
* @brief  根据会议室资源搜索会议室请求
*
* @param	[in]	tMtQueryRooms_Api-->会议室过滤条件
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestQueryRooms_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestQueryRoomsReq( IN CONST TMTQueryRooms_Api& tMtQueryRooms_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetTemplateListReq
*
* @brief  获取会议模板列表请求
*
* @param	[in]	tMtNormalRooms_Api-->会议模板列表过滤条件
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetTemplateList_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetTemplateListReq( IN CONST TMTNormalRooms_Api& tMtNormalRooms_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetTemplateInfoReq
*
* @brief  获取会议模板信息请求
*
* @param	[in]	tstrTemplateId_Api-->会议模板名称
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetTemplateInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetTemplateInfoReq( IN CONST s8* pszTemplateId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestCreateMeetingNotifyReq
*
* @brief  创建会议通知请求
*
* @param	[in]	tMtMeetingNotify_Api-->通知的参数设置
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestCreateMeetingNotify_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestCreateMeetingNotifyReq( IN CONST TMTCreateMeetingNotify_Api& tMtMeetingNotify_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetMeetingDeadLineReq
*
* @brief  获取企业会议管理期限请求
*
* @param	[in]	无
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetMeetingDeadLine_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetMeetingDeadLineReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestLockRoomReq
*
* @brief  锁定会议室请求
*
* @param	[in]	tMtLockRoom_Api-->锁定信息
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestLockRoom_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestLockRoomReq( IN CONST TMTLockRoom_Api& tMtLockRoom_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetListNotifysByNTypeReq
*
* @brief  获取某一类型的会议通知
*
* @param	[in]	tListNotifyByMax_Api-->请求参数
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetListNotifysByNType_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetListNotifysByNTypeReq( IN CONST TListNotifyByMax_Api& tListNotifyByMax_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetNotifyByIdReq
*
* @brief  根据ID获取通知请求
*
* @param	[in]	dwConfID-->会议ID号
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetNotifyById_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetNotifyByIdReq( IN CONST u32 dwConfID, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestIfExistLockByFormkeyReq
*
* @brief  IfExistLockByFormkey请求
*
* @param	[in]	tIfExistLockByFormkey_Api-->请求参数
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_IfExistLockByFormkey_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestIfExistLockByFormkeyReq( IN CONST TIfExistLockByFormkey_Api& tIfExistLockByFormkey_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestDeleteBookedRoomReq
*
* @brief  删除已订会议室请求
*
* @param	[in]	dwConfID-->会议ID号
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DeleteBookedRoom_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestDeleteBookedRoomReq( IN CONST u32 dwConfID, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetRegularReq
*
* @brief  GetRegular请求
*
* @param	[in]	dwConfID-->会议ID号
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetRegular_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetRegularReq( IN CONST u32 dwConfID, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestMeetingUnlockReq
*
* @brief  会议解锁请求
*
* @param	[in]	tMeetingUnlock_Api-->会议解锁信息
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestMeetingUnlock_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestMeetingUnlockReq( IN CONST TMeetingUnlock_Api& tMeetingUnlock_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestMeetingRegularFeedReq
*
* @brief  例会反馈请求
*
* @param	[in]	tRegularFeed_Api-->理会反馈参数
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestMeetingRegularFeed_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestMeetingRegularFeedReq( IN CONST TRegularFeed_Api& tRegularFeed_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestQueryMeetingRegionsReq
*
* @brief  获取用户所在企业所有可用的会议室区域请求
*
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestQueryMeetingRegions_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestQueryMeetingRegionsReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestLockMeetingRoomsReq
*
* @brief  会议室批量加锁请求
*
* @param	[in]	tMtLockRooms_Api-->批量会议室信息
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestLockMeetingRooms_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestLockMeetingRoomsReq( IN CONST TMTLockRooms_Api& tMtLockRooms_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestStartMeetingNowReq
*
* @brief  立即开始会议请求
*
* @param	[in]	dwConfID-->会议ID号
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestStartMeetingNow_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestStartMeetingNowReq( IN CONST u32 dwConfID, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_MGRestAppClearNotifyReq
*
* @brief  根据通知类型清除通知请求
*
* @param	[in]	tAppClearNotify-->通知类型
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestAppClearNotify_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestAppClearNotifyReq( IN CONST TAppClearNotify_Api tAppClearNotify, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestAppClearAllMeetingNotifyReq
*
* @brief  清除会议所有通知请求
*
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestAppClearAllMeetingNotify_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestAppClearAllMeetingNotifyReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestAppGetAllNotifyReq
*
* @brief  获取所有通知消息请求
*
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestAppGetAllNotify_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestAppGetAllNotifyReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_MGRestGetPlatformAccountTokenReq
*
* @brief  获得平台account token请求
*
* @param	[in]	pszSrvAddr-->服务器地址
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetPlatformAccountToken_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetPlatformAccountTokenReq(IN CONST s8* pszSrvAddr, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetPersonalTemplateListReq
*
* @deprecated 此接口为兼容老版本，建议使用新版本接口
*
* @brief  获取个人模板列表
*
* @param	[in]	tGetPerTemplateList-->模板信息
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetPersonalTemplateList_Rsp, Ev_MtApi_RestGetPersonalTemplateList_Fin_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetPersonalTemplateListReq( IN CONST TMTGetPerTemplateList_Api tGetPerTemplateList, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_MGRestGetPersonalTemplateByIDReq
*
** @deprecated 此接口为兼容老版本，建议使用新版本接口
*
* @brief  根据个人模板id获取模板详情
*
* @param	[in]	dwTemplateID-->模板id
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetPersonalTemplateByID_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetPersonalTemplateByIDReq( IN CONST u32 dwTemplateID, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_MGRestAddPersonalTemplateReq
*
* @deprecated 此接口为兼容老版本，建议使用新版本接口
*
* @brief  创建个人模板
*
* @param	[in]	tMTPerTemplate-->模板信息
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestAddPersonalTemplate_Rsp, Ev_MtApi_RestAddPersonalTemplate_Ntf
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestAddPersonalTemplateReq( IN CONST TMTPerTemplate_Api tMTPerTemplate, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_MGRestAddPersonalTemplateReq
*
* @deprecated 此接口为兼容老版本，建议使用新版本接口
*
* @brief  修改个人模板
*
* @param	[in]	tMTPerTemplate-->模板信息
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestUpdatePersonalTemplate_Rsp, Ev_MtApi_RestUpdatePersonalTemplate_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestUpdatePersonalTemplateReq( IN CONST TMTPerTemplate_Api tMTPerTemplate, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestDelPersonalTemplateReq
*
** @deprecated 此接口为兼容老版本，建议使用新版本接口
*
* @brief  删除个人模板
*
* @param	[in]	dwTemplateID-->模板id
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestDelPersonalTemplate_Rsp, Ev_MtApi_RestDelPersonalTemplate_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestDelPersonalTemplateReq( IN CONST u32 dwTemplateID, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetPublicTemplateListReq
*
* @deprecated 此接口为兼容老版本，建议使用新版本接口
* @brief  获取公共模板列表
*
* @param	[in]	tGetPubTemplateList-->模板信息
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetPublicTemplateList_Rsp, Ev_MtApi_RestGetPublicTemplateList_Fin_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetPublicTemplateListReq( IN CONST TMTGetPubTemplateList_Api tGetPubTemplateList, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_MGRestGetPublicTemplateByIDReq
*
* @deprecated 此接口为兼容老版本，建议使用新版本接口
* @brief  根据公共模板id获取模板详情
*
* @param	[in]	pchTemplateKey-->模板id
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetPublicTemplateByID_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetPublicTemplateByIDReq( IN CONST s8 *pchTemplateKey, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_MGRestAddPublicTemplateReq
*
* @deprecated 此接口为兼容老版本，建议使用新版本接口
* @brief  创建公共模板
*
* @param	[in]	tMTPubTemplate-->模板信息
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestAddPublicTemplate_Rsp, Ev_MtApi_RestAddPublicTemplate_Ntf
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestAddPublicTemplateReq( IN CONST TMTPubTemplate_Api tMTPubTemplate, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_MGRestUpdatePublicTemplateReq
*
* @deprecated 此接口为兼容老版本，建议使用新版本接口
* @brief  修改公共模板
*
* @param	[in]	tMTPubTemplate-->模板信息
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestUpdatePublicTemplate_Rsp, Ev_MtApi_RestUpdatePublicTemplate_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestUpdatePublicTemplateReq( IN CONST TMTPubTemplate_Api tMTPubTemplate, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestDelPublicTemplateReq
*
* @deprecated 此接口为兼容老版本，建议使用新版本接口
* @brief  删除公共模板
*
* @param	[in]	pchTemplateKey-->模板id
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestDelPublicTemplate_Rsp, Ev_MtApi_RestDelPublicTemplate_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestDelPublicTemplateReq( IN CONST s8 *pchTemplateKey, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

//by-qwchan-part-mtmeetingctrl end

/***************************************new api*****************************************************/
/**
* KdvMt_MGRestCreatePersonalTemplateReq
*
* @brief  创建个人模板 (平台新API)
*
* @param	[in]	tMTPerTemplate-->模板信息
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestCreatePersonalTemplate_Rsp, Ev_MtApi_RestCreatePersonalTemplate_Ntf
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestCreatePersonalTemplateReq( IN CONST TMTPeronalTemplate_Api *ptMTPeronalTemplate, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestModifyPersonalTemplateReq
*
* @brief  修改个人模板
*
* @param	[in]	tMTPeronalTemplate-->模板信息
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestModifyPersonalTemplate_Rsp, Ev_MtApi_RestModifyPersonalTemplate_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestModifyPersonalTemplateReq( IN CONST TMTPeronalTemplate_Api *ptMTPeronalTemplate, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_MGRestGetPersonalTemplatesListReq
*
* @brief  获取个人模板列表
*
* @param	[in]	tGetPerTemplateList-->模板信息
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetPersonalTemplatesList_Rsp, Ev_MtApi_RestGetPersonalTemplatesList_Fin_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetPersonalTemplatesListReq( IN CONST TMTGetPerTemplateList_Api tGetPerTemplateList, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_MGRestGetPerTemplateByIDReq
*
* @brief  根据个人模板id获取模板详情
*
* @param	[in]	dwTemplateID-->模板id
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetPerTemplateByID_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetPerTemplateByIDReq( IN CONST s8 *pchTemplateID, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetPerTemplateByIDReq
*
* @brief  删除个人模板
*
* @param	[in]	dwTemplateID-->模板id
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestDeletePersonalTemplate_Rsp, Ev_MtApi_RestDeletePersonalTemplate_Ntf
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestDeletePersonalTemplateReq( IN CONST s8 *pchTemplateID, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetCommonTemplateListReq
*
* @brief  获取公共模板列表
*
* @param	[in]	tGetPubTemplateList-->模板信息
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetCommonTemplateList_Rsp, Ev_MtApi_RestGetCommonTemplateList_Fin_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetCommonTemplateListReq( IN CONST TMTGetPubTemplateList_Api tGetPubTemplateList, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestCreateCommonTemplateReq
*
* @brief  创建公共模板
*
* @param	[in]	tMTCommonTemplate-->模板信息
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestCreateCommonTemplate_Rsp, Ev_MtApi_RestCreateCommonTemplate_Ntf
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestCreateCommonTemplateReq( IN CONST TMTCommonTemplate_Api tMTCommonTemplate, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_MGRestGetCommonTemplateByIDReq
*
* @brief  根据公共模板id获取模板详情
*
* @param	[in]	pchTemplateKey-->模板id
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetCommonTemplateByID_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetCommonTemplateByIDReq( IN CONST s8 *pchTemplateKey, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestModifyCommonTemplateReq
*
* @brief  修改公共模板
*
* @param	[in]	tMTPubTemplate-->模板信息
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestModifyCommonTemplate_Rsp, Ev_MtApi_RestModifyCommonTemplate_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestModifyCommonTemplateReq( IN CONST TMTCommonTemplate_Api tMTComTemplate, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestDeleteCommonTemplateReq
*
* @brief  删除公共模板
*
* @param	[in]	pchTemplateKey-->模板id
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestDeleteCommonTemplate_Rsp, Ev_MtApi_RestDeleteCommonTemplate_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestDeleteCommonTemplateReq( IN CONST s8 *pchTemplateKey, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetBookConferenceListReq
*
* @brief  获取预约会议列表
*
* @param	[in]	tGetPubTemplateList-->模板信息
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetBookConferenceList_Rsp, Ev_MtApi_RestGetBookConferenceList_Fin_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetBookConferenceListReq( IN CONST TMTConditionOfConfList_Api tConditionOfConfList, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetBookConferenceInfoByIDReq
*
* @brief  根据预约会议id获取会议信息
*
* @param	[in]	pchConfID-->id
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetBookConferenceInfoByID_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetBookConferenceInfoByIDReq( IN CONST s8 *pchConfID, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestCreateConferenceReq
*
* @brief  创建会议
*
* @param	[in]	tMTInstantConference-->会议信息
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestCreateConference_Rsp, Ev_MtApi_RestCreateConference_Ntf
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestCreateConferenceReq( IN CONST TMTInstantConference_Api &tMTInstantConference, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_MGRestStopConferenceReq
*
* @brief  结束会议
*
* @param	[in]	pchConfID-->会议ID
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestStopConference_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestStopConferenceReq( IN CONST s8 *pchConfID, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetConferenceListReq
*
* @brief  获取即时会议列表
*
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetConferenceList_Rsp, Ev_MtApi_RestGetConferenceList_Fin_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetConferenceListReq(IN CONST TMTGetIntanceConfList_Api tConditionOfConfList, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetInstantConfInfoByIDReq
*
* @brief  根据id获取即时会议信息
*
* @param	[in]	pchConfID-->id
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetInstantConfInfoByID_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetInstantConfInfoByIDReq( IN CONST s8 *pchConfID, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_MGRestGetSimplePerTemplateByIDReq
*
* @brief  获取简单个人模板详情
*
* @param	[in]	dwTemplateID-->id
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetSimplePerTemplateByID_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetSimplePerTemplateByIDReq( IN CONST s8 *pchTemplateID, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetInviteMembersOfPerTemplateReq
*
* @brief  获取个人模板参会人员
*
* @param	[in]	tGetPerTemplateInfo_Api-->查询条件
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetInviteMembersOfPerTemplate_Rsp,Ev_MtApi_RestGetInviteMembersOfPerTemplate_Fin_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetInviteMembersOfPerTemplateReq( IN CONST TMTGetPerTemplateInfo_Api &tGetPerTemplateInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetMixInfoOfPerTemplateReq
*
* @brief  获取个人模板混音信息
*
* @param	[in]	tGetPerTemplateInfo_Api-->查询条件
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetMixInfoOfPerTemplate_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetMixInfoOfPerTemplateReq( IN CONST TMTGetPerTemplateInfo_Api &tGetPerTemplateInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetVMPInfoOfPerTemplateReq
*
* @brief  获取个人模板VMP信息
*
* @param	[in]	tGetPerTemplateInfo_Api-->查询条件
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetMixInfoOfPerTemplate_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetVMPInfoOfPerTemplateReq( IN CONST TMTGetPerTemplateInfo_Api &tGetPerTemplateInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetPollInfoOfPerTemplateReq
*
* @brief  获取个人模板轮询信息
*
* @param	[in]	tGetPerTemplateInfo_Api-->查询条件
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetPollInfoOfPerTemplate_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetPollInfoOfPerTemplateReq( IN CONST TMTGetPerTemplateInfo_Api &tGetPerTemplateInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetVIPInfoOfPerTemplateReq
*
* @brief  获取个人模板vip
*
* @param	[in]	tGetPerTemplateInfo_Api-->查询条件
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetVIPInfoOfPerTemplate_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetVIPInfoOfPerTemplateReq( IN CONST TMTGetPerTemplateInfo_Api &tGetPerTemplateInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_MGRestStartRecordReq
*
* @brief  开启录像
*
* @param	[in]	tStartRecord_Api-->开启条件
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestStartRecord_Rsp, Ev_MtApi_RestStartRecord_Ntf
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestStartRecordReq( IN CONST TMTStartRecord_Api &tStartRecord_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestStopRecordReq
*
* @brief  关闭录像
*
* @param	[in]	tStopRecord_Api-->关闭条件
* @param	[in]	dwSSID-->MT会话ID 
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestStopRecord_Rsp, Ev_MtApi_RestStopRecord_Ntf
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestStopRecordReq( IN CONST TMTStopRecord_Api &tStopRecord_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_MGRestGetRecordStateReq
*
* @brief    获取录像状态
*
* @param	[in]	pchConfID-->会议ID
* @param	[in]	dwRecordID-->录像ID 
* @return	u32     0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetRecordState_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetRecordStateReq( IN CONST s8 *pchConfID, IN CONST s8 *pchRecordID, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestModifyRecordStateReq
*
* @brief    修改录像状态
*
* @param	[in]	tRecordState_Api-->修改参数
* @return	u32     0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestModifyRecordState_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestModifyRecordStateReq( IN CONST TMTModifyRecordState_Api &tRecordState_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetRecordListReq
*
* @brief    获取录像列表
*
* @param	[in]	pchConfID-->会议ID
* @return	u32     0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetRecordList_Rsp, Ev_MtApi_RestGetRecordList_Fin_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetRecordListReq( IN CONST s8 *pchConfID, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetConfTerminalListReq
*
* @brief    获取本级会议终端列表
*
* @param	[in]	pchConfID-->会议ID
* @return	u32     0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetConfTerminalList_Rsp, Ev_MtApi_RestGetConfTerminalList_Fin_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetConfTerminalListReq( IN CONST s8 *pchConfID, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_MGPushSrvLoginReq
*
* @brief    推送服务器登录请求
*
* @param	[in]	TMTPushSrvReq_Api-->请求注册信息
* @return	u32     0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_PushSrvLogin_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGPushSrvLoginReq( IN CONST TMTPushSrvReq_Api &tPushSrvReq_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_MGPushSrvLogoutReq
*
* @brief    推送服务器登出请求
*
* @param	[in]	pchAliDeviceId-->通过阿里云SDK获取
* @return	u32     0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_PushSrvLogout_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGPushSrvLogoutReq( IN CONST s8 *pchAliDeviceId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );
/**
* KdvMt_MGRestCreateVirtualConfReq
*
* @brief    召开虚拟会议室请求
*
* @param	[in]	TMTCreateVConf_Api-->召开虚拟会议室信息
* @return	u32     0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestCreateVirtualConf_Rsp
*/ 
//KdvMtAPI u32 KdvMtCALL KdvMt_MGRestCreateVirtualConfReq(IN CONST TMTCreateVConf_Api& tMtCreateVConf_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_MGRestGetVConfDetailInfoReq
*
* @brief    获取虚拟会议室详情
*
* @param	[in]	s8 -->虚拟会议室ID
* @return	u32     0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetVConfDetailInfo_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetVConfDetailInfoReq(IN CONST s8 *pchVConfID, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_MGRestGetVConfResourceReq
*
* @brief    获取资源占用情况
*
* @param	[in]	无
* @return	u32     0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetVConfResource_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetVConfResourceReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

// 
/**
* KdvMt_MGRestGetVConfListReq
*
* @brief    获取虚拟会议室列表
*
* @param	[in]	TMTVConfListReq_Api -->获取虚拟会议室列表请求
* @return	u32     0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_RestGetVConfList_Rsp, Ev_MtApi_RestGetVConfList_Fin_Rsp
*/ 
KdvMtAPI u32 KdvMtCALL KdvMt_MGRestGetVConfListReq(IN CONST TMTVConfListReq_Api& tMTVConfListReq_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**@}*/

/**@}*/
#endif //_MTAPI_MGAPI_H_