/**===========================================================================
 * @file    $Id$
 * @brief   负责MtMeetingMgrAPi 会管日程相关功能接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTMEETINGCTRL_H_
#define _I_MTMEETINGCTRL_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_mg.h"
#include "mtapi_struct.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtMeetingCtrl
 * @brief    负责MtMeetingMgrAPi 会管日程相关功能接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtMeetingCtrl : public IMtApiIF
{
public:
	//登录推送服务器请求
	virtual u32 PushSrvLoginReq(const TMTPushSrvReq_Api& tTMTPushSrvReq_Api) = 0;

	//登出推送服务器请求
	virtual u32 PushSrvLogoutReq(const s8* pachAliDeviceId) = 0;

	// 获取会议列表请求
	virtual u32 RestGetMeetingListReq(const TMTMeetingList_Api& tMtMeetingList_Api) = 0;

	// 获取会议详细信息请求
	virtual u32 RestGetMeetingInfoReq(const u32 dwConfID) = 0;

	// 获取会议室预定信息请求
	virtual u32 RestGetBookingInfoReq(const TMTBookingInfo_Api& tMtBookingInfo_Api) = 0;

	// 获取某人的会议信息请求
	virtual u32 RestGetMeetingListOfPersonReq(const TMTMeetingListOfPerson_Api& tMtMeetingListOfPerson_Api) = 0;

	// 创建会议请求
	virtual u32 RestAddMeetingReq(const TMTAddMeeting_Api& tMtAddMeeting_Api) = 0;

	// 修改会议请求
	virtual u32 RestModifyMeetingReq(const TMTModifyMeeting_Api& tMtModifyMeeting_Api) = 0;

	// 删除会议请求
	virtual u32 RestDeleteMeetingReq(const u32 dwConfID) = 0;

	// 开始会议请求
	virtual u32 RestStartMeetingReq(const u32 dwConfID) = 0;

	// 结束会议请求
	virtual u32 RestEndMeetingReq(const u32 dwConfID) = 0;

	// 会议反馈请求
	virtual u32 RestMeetingFeedReq(const TMTMeetingFeed_Api& tMtMeetingFeed_Api) = 0;

	// 获取空闲会议室请求
	virtual u32 RestQueryFreeRoomsReq(const TMTQueryFreeRooms_Api& tMtQueryFreeRooms_Api) = 0;

	// 获取推荐的虚拟会议室请求
	virtual u32 RestGetRecommendedVirtualRoomReq(const TMTRecommendedVirtualRoom_Api& tMtRecommendedVirtualRoom_Api) = 0;

	// 获取正常的会议室请求
	virtual u32 RestGetNormalRoomsReq(const TMTNormalRooms_Api& tMtNormalRooms_Api) = 0;

	// 根据Id获取会议室请求
	virtual u32 RestGetRoomInfoReq(const u32 dwConfID) = 0;

	// 根据名称搜索会议室请求
	virtual u32 RestGetRoomListByNameReq(const TMTRoomListByName_Api& tMtRoomListByName_Api) = 0;

	// 根据会议室资源搜索会议室请求
	virtual u32 RestQueryRoomsReq(const TMTQueryRooms_Api& tMtQueryRooms_Api) = 0;

	// 获取会议模板列表请求
	virtual u32 RestGetTemplateListReq(const TMTNormalRooms_Api& tMtNormalRooms_Api) = 0;

	// 获取会议模板信息请求
	virtual u32 RestGetTemplateInfoReq(const s8* pszTemplateId) = 0;

	// 创建会议通知请求
	virtual u32 RestCreateMeetingNotifyReq(const TMTCreateMeetingNotify_Api& tMtMeetingNotify_Api) = 0;

	// 获取企业会议管理期限请求
	virtual u32 RestGetMeetingDeadLineReq( ) = 0;

	// 锁定会议室请求
	virtual u32 RestLockRoomReq(const TMTLockRoom_Api& tMtLockRoom_Api) = 0;

	// ListNotifyByMax请求
	virtual u32 RestListNotifysByMaxReq(const TListNotifyByMax_Api& tListNotifyByMax_Api) = 0;

	// 根据ID获取通知请求
	virtual u32 RestGetNotifyByIdReq(const u32 dwConfID) = 0;

	// IfExistLockByFormkey请求
	virtual u32 RestIfExistLockByFormkeyReq(const TIfExistLockByFormkey_Api& tIfExistLockByFormkey_Api) = 0;

	// 删除已订会议室请求
	virtual u32 RestDeleteBookedRoomReq(const u32 dwConfID) = 0;

	// GetRegular请求
	virtual u32 RestGetRegularReq(const u32 dwConfID) = 0;

	// 会议解锁请求
	virtual u32 RestMeetingUnlockReq(const TMeetingUnlock_Api& tMeetingUnlock_Api) = 0;

	// 例会反馈请求
	virtual u32 RestMeetingRegularFeedReq(const TRegularFeed_Api& tRegularFeed_Api) = 0;

	// 获取用户所在企业所有可用的会议室区域请求
	virtual u32 RestQueryMeetingRegionsReq() = 0;

	// 会议室批量加锁请求
	virtual u32 RestLockMeetingRoomsReq(const TMTLockRooms_Api& tMtLockRooms_Api) = 0;

	// 立即开始会议请求
	virtual u32 RestStartMeetingNowReq(const u32 dwConfID) = 0;

	// 根据通知类型清除通知请求
	virtual u32 RestAppClearNotifyReq(const TAppClearNotify_Api tAppClearNotify) = 0;

	// 清除会议所有通知请求
	virtual u32 RestAppClearAllMeetingNotifyReq() = 0;

	// 获取@、赞、粉丝等初始消息请求
	virtual u32 RestAppGetAllNotifyReq() = 0;

	// 获得平台account token请求
	virtual u32 RestGetPlatformAccountTokenReq(const s8* pszSrvAddr) = 0;

	// 获取个人模板列表
	virtual u32 RestGetPersonalTemplateListReq(const TMTGetPerTemplateList_Api tGetPerTemplateList) = 0;

	// 根据个人模板id获取模板详情
	virtual u32 RestGetPersonalTemplateByIDReq(const u32 dwTemplateID) = 0;

	// 创建个人模板
	virtual u32 RestAddPersonalTemplateReq(const TMTPerTemplate_Api tMTPerTemplate) = 0;

	// 修改个人模板
	virtual u32 RestUpdatePersonalTemplateReq(const TMTPerTemplate_Api tMTPerTemplate) = 0;

	// 删除个人模板
	virtual u32 RestDelPersonalTemplateReq(const u32 dwTemplateID) = 0;

	//获取公共模板列表
	virtual u32 RestGetPublicTemplateListReq(const TMTGetPubTemplateList_Api tGetPubTemplateList) = 0;

	// 根据公共模板id获取模板详情
	virtual u32 RestGetPublicTemplateByIDReq(const s8 *pchTemplateKey) = 0;

	// 创建公共模板
	virtual u32 RestAddPublicTemplateReq(const TMTPubTemplate_Api tMTPubTemplate) = 0;

	//修改公共模板
	virtual u32 RestUpdatePublicTemplateReq(const TMTPubTemplate_Api tMTPubTemplate) = 0;

    //删除公共模板
	virtual u32 RestDelPublicTemplateReq(const s8 *pchTemplateKey) = 0;


    // 创建个人模板
    virtual u32 RestCreatePersonalTemplateReq(const TMTPeronalTemplate_Api *ptMTPeronalTemplate) = 0;

    // 修改个人模板 new API
    virtual u32 RestModifyPersonalTemplateReq(const TMTPeronalTemplate_Api *ptMTPeronalTemplate) = 0;

    // 获取个人模板列表
    virtual u32 RestGetPersonalTemplatesListReq(const TMTGetPerTemplateList_Api tGetPerTemplateList) = 0;

    // 根据个人模板id获取模板详情
    virtual u32 RestGetPerTemplateByIDReq(const s8 *pchTemplateID) = 0;

    // 删除个人模板
    virtual u32 RestDeletePersonalTemplateReq(const s8 *pchTemplateID) = 0;

    //获取公共模板列表
    virtual u32 RestGetCommonTemplateListReq(const TMTGetPubTemplateList_Api tGetPubTemplateList) = 0;

    // 创建公共模板
    virtual u32 RestCreateCommonTemplateReq(const TMTCommonTemplate_Api tMTCommonTemplate) = 0;

    // 根据公共模板id获取模板详情
    virtual u32 RestGetCommonTemplateByIDReq(const s8 *pchTemplateKey) = 0;

    //修改公共模板
    virtual u32 RestModifyCommonTemplateReq(const TMTCommonTemplate_Api tMTComTemplate) = 0;

    //删除公共模板
    virtual u32 RestDeleteCommonTemplateReq(const s8 *pchTemplateKey) = 0;

    //获取预约会议列表
    virtual u32 RestGetBookConferenceListReq(const TMTConditionOfConfList_Api tConditionOfConfList) = 0;

    // 根据预约会议id获取会议信息
    virtual u32 RestGetBookConferenceInfoByIDReq(const s8 *pchConfID) = 0;

    //创建会议
    virtual u32 RestCreateConferenceReq(const TMTInstantConference_Api &tMTInstantConference) = 0;

    //结束会议
    virtual u32 RestStopConferenceReq(const s8 *pchConfID) = 0;

    //获取即时会议列表
    virtual u32 RestGetConferenceListReq(const TMTGetIntanceConfList_Api &tConditionOfConfList) = 0;

    //根据会议ID,获取即时会议信息
    virtual u32 RestGetInstantConfInfoByIDReq(const s8 *pchConfID) = 0;

    //获取简单个人模板详情
    virtual u32 RestGetSimplePerTemplateByIDReq(const s8 *pchTemplateID) = 0;

    //获取个人模板参会人员
    virtual u32 RestGetInviteMembersOfPerTemplateReq(const TMTGetPerTemplateInfo_Api &tGetPerTemplateInfo_Api) = 0;

    //获取个人模板混音信息
    virtual u32 RestGetMixInfoOfPerTemplateReq(const TMTGetPerTemplateInfo_Api &tGetPerTemplateInfo_Api) = 0;

    //获取个人模板VMP信息
    virtual u32 RestGetVMPInfoOfPerTemplateReq(const TMTGetPerTemplateInfo_Api &tGetPerTemplateInfo_Api) = 0;

    //获取个人模板轮询信息
    virtual u32 RestGetPollInfoOfPerTemplateReq(const TMTGetPerTemplateInfo_Api &tGetPerTemplateInfo_Api) = 0;

    //获取个人模板vip
    virtual u32 RestGetVIPInfoOfPerTemplateReq(const TMTGetPerTemplateInfo_Api &tGetPerTemplateInfo_Api) = 0;

    //开始录像
    virtual u32 RestStartRecordReq(const TMTStartRecord_Api &tStartRecord_Api) = 0;

    //结束录像
    virtual u32 RestStopRecordReq(const TMTStopRecord_Api &tStopRecord_Api) = 0;

    //获取录像状态
    virtual u32 RestGetRecordStateReq(const s8 *pchConfID, const s8 * pchRecordID) = 0;
    //修改录像状态
    virtual u32 RestModifyRecordStateReq(const TMTModifyRecordState_Api &tRecordState_Api) = 0;

    //获取录像列表
    virtual u32 RestGetRecordListReq(const s8 *pchConfID) = 0;
    //获取本级会议终端列表
    virtual u32 RestGetConfTerminalListReq(const s8 *pchConfID) = 0;

	// 召开虚拟会议室请求
//	virtual u32 RestCreateVirtualConfReq(const TMTCreateVConf_Api& tMtCreateVConf_Api) = 0;

	// 获取虚拟会议室详情
	virtual	u32 RestGetVConfDetailInfoReq(const s8 *pchVConfID) = 0;

	// 获取资源占用情况
	virtual	u32 RestGetVConfResourceReq() = 0;

	// 获取虚拟会议室列表
	virtual	u32 RestGetVConfListReq(const TMTVConfListReq_Api& tMTVConfListReq_Api) = 0;
};

#endif // _I_MTMEETINGCTRL_H_