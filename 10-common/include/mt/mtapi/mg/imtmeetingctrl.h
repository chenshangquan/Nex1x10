/**===========================================================================
 * @file    $Id$
 * @brief   ����MtMeetingMgrAPi ����ճ���ع��ܽӿڶ���
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
 * @brief    ����MtMeetingMgrAPi ����ճ���ع��ܽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtMeetingCtrl : public IMtApiIF
{
public:
	//��¼���ͷ���������
	virtual u32 PushSrvLoginReq(const TMTPushSrvReq_Api& tTMTPushSrvReq_Api) = 0;

	//�ǳ����ͷ���������
	virtual u32 PushSrvLogoutReq(const s8* pachAliDeviceId) = 0;

	// ��ȡ�����б�����
	virtual u32 RestGetMeetingListReq(const TMTMeetingList_Api& tMtMeetingList_Api) = 0;

	// ��ȡ������ϸ��Ϣ����
	virtual u32 RestGetMeetingInfoReq(const u32 dwConfID) = 0;

	// ��ȡ������Ԥ����Ϣ����
	virtual u32 RestGetBookingInfoReq(const TMTBookingInfo_Api& tMtBookingInfo_Api) = 0;

	// ��ȡĳ�˵Ļ�����Ϣ����
	virtual u32 RestGetMeetingListOfPersonReq(const TMTMeetingListOfPerson_Api& tMtMeetingListOfPerson_Api) = 0;

	// ������������
	virtual u32 RestAddMeetingReq(const TMTAddMeeting_Api& tMtAddMeeting_Api) = 0;

	// �޸Ļ�������
	virtual u32 RestModifyMeetingReq(const TMTModifyMeeting_Api& tMtModifyMeeting_Api) = 0;

	// ɾ����������
	virtual u32 RestDeleteMeetingReq(const u32 dwConfID) = 0;

	// ��ʼ��������
	virtual u32 RestStartMeetingReq(const u32 dwConfID) = 0;

	// ������������
	virtual u32 RestEndMeetingReq(const u32 dwConfID) = 0;

	// ���鷴������
	virtual u32 RestMeetingFeedReq(const TMTMeetingFeed_Api& tMtMeetingFeed_Api) = 0;

	// ��ȡ���л���������
	virtual u32 RestQueryFreeRoomsReq(const TMTQueryFreeRooms_Api& tMtQueryFreeRooms_Api) = 0;

	// ��ȡ�Ƽ����������������
	virtual u32 RestGetRecommendedVirtualRoomReq(const TMTRecommendedVirtualRoom_Api& tMtRecommendedVirtualRoom_Api) = 0;

	// ��ȡ�����Ļ���������
	virtual u32 RestGetNormalRoomsReq(const TMTNormalRooms_Api& tMtNormalRooms_Api) = 0;

	// ����Id��ȡ����������
	virtual u32 RestGetRoomInfoReq(const u32 dwConfID) = 0;

	// ����������������������
	virtual u32 RestGetRoomListByNameReq(const TMTRoomListByName_Api& tMtRoomListByName_Api) = 0;

	// ���ݻ�������Դ��������������
	virtual u32 RestQueryRoomsReq(const TMTQueryRooms_Api& tMtQueryRooms_Api) = 0;

	// ��ȡ����ģ���б�����
	virtual u32 RestGetTemplateListReq(const TMTNormalRooms_Api& tMtNormalRooms_Api) = 0;

	// ��ȡ����ģ����Ϣ����
	virtual u32 RestGetTemplateInfoReq(const s8* pszTemplateId) = 0;

	// ��������֪ͨ����
	virtual u32 RestCreateMeetingNotifyReq(const TMTCreateMeetingNotify_Api& tMtMeetingNotify_Api) = 0;

	// ��ȡ��ҵ���������������
	virtual u32 RestGetMeetingDeadLineReq( ) = 0;

	// ��������������
	virtual u32 RestLockRoomReq(const TMTLockRoom_Api& tMtLockRoom_Api) = 0;

	// ListNotifyByMax����
	virtual u32 RestListNotifysByMaxReq(const TListNotifyByMax_Api& tListNotifyByMax_Api) = 0;

	// ����ID��ȡ֪ͨ����
	virtual u32 RestGetNotifyByIdReq(const u32 dwConfID) = 0;

	// IfExistLockByFormkey����
	virtual u32 RestIfExistLockByFormkeyReq(const TIfExistLockByFormkey_Api& tIfExistLockByFormkey_Api) = 0;

	// ɾ���Ѷ�����������
	virtual u32 RestDeleteBookedRoomReq(const u32 dwConfID) = 0;

	// GetRegular����
	virtual u32 RestGetRegularReq(const u32 dwConfID) = 0;

	// �����������
	virtual u32 RestMeetingUnlockReq(const TMeetingUnlock_Api& tMeetingUnlock_Api) = 0;

	// ���ᷴ������
	virtual u32 RestMeetingRegularFeedReq(const TRegularFeed_Api& tRegularFeed_Api) = 0;

	// ��ȡ�û�������ҵ���п��õĻ�������������
	virtual u32 RestQueryMeetingRegionsReq() = 0;

	// ������������������
	virtual u32 RestLockMeetingRoomsReq(const TMTLockRooms_Api& tMtLockRooms_Api) = 0;

	// ������ʼ��������
	virtual u32 RestStartMeetingNowReq(const u32 dwConfID) = 0;

	// ����֪ͨ�������֪ͨ����
	virtual u32 RestAppClearNotifyReq(const TAppClearNotify_Api tAppClearNotify) = 0;

	// �����������֪ͨ����
	virtual u32 RestAppClearAllMeetingNotifyReq() = 0;

	// ��ȡ@���ޡ���˿�ȳ�ʼ��Ϣ����
	virtual u32 RestAppGetAllNotifyReq() = 0;

	// ���ƽ̨account token����
	virtual u32 RestGetPlatformAccountTokenReq(const s8* pszSrvAddr) = 0;

	// ��ȡ����ģ���б�
	virtual u32 RestGetPersonalTemplateListReq(const TMTGetPerTemplateList_Api tGetPerTemplateList) = 0;

	// ���ݸ���ģ��id��ȡģ������
	virtual u32 RestGetPersonalTemplateByIDReq(const u32 dwTemplateID) = 0;

	// ��������ģ��
	virtual u32 RestAddPersonalTemplateReq(const TMTPerTemplate_Api tMTPerTemplate) = 0;

	// �޸ĸ���ģ��
	virtual u32 RestUpdatePersonalTemplateReq(const TMTPerTemplate_Api tMTPerTemplate) = 0;

	// ɾ������ģ��
	virtual u32 RestDelPersonalTemplateReq(const u32 dwTemplateID) = 0;

	//��ȡ����ģ���б�
	virtual u32 RestGetPublicTemplateListReq(const TMTGetPubTemplateList_Api tGetPubTemplateList) = 0;

	// ���ݹ���ģ��id��ȡģ������
	virtual u32 RestGetPublicTemplateByIDReq(const s8 *pchTemplateKey) = 0;

	// ��������ģ��
	virtual u32 RestAddPublicTemplateReq(const TMTPubTemplate_Api tMTPubTemplate) = 0;

	//�޸Ĺ���ģ��
	virtual u32 RestUpdatePublicTemplateReq(const TMTPubTemplate_Api tMTPubTemplate) = 0;

    //ɾ������ģ��
	virtual u32 RestDelPublicTemplateReq(const s8 *pchTemplateKey) = 0;


    // ��������ģ��
    virtual u32 RestCreatePersonalTemplateReq(const TMTPeronalTemplate_Api *ptMTPeronalTemplate) = 0;

    // �޸ĸ���ģ�� new API
    virtual u32 RestModifyPersonalTemplateReq(const TMTPeronalTemplate_Api *ptMTPeronalTemplate) = 0;

    // ��ȡ����ģ���б�
    virtual u32 RestGetPersonalTemplatesListReq(const TMTGetPerTemplateList_Api tGetPerTemplateList) = 0;

    // ���ݸ���ģ��id��ȡģ������
    virtual u32 RestGetPerTemplateByIDReq(const s8 *pchTemplateID) = 0;

    // ɾ������ģ��
    virtual u32 RestDeletePersonalTemplateReq(const s8 *pchTemplateID) = 0;

    //��ȡ����ģ���б�
    virtual u32 RestGetCommonTemplateListReq(const TMTGetPubTemplateList_Api tGetPubTemplateList) = 0;

    // ��������ģ��
    virtual u32 RestCreateCommonTemplateReq(const TMTCommonTemplate_Api tMTCommonTemplate) = 0;

    // ���ݹ���ģ��id��ȡģ������
    virtual u32 RestGetCommonTemplateByIDReq(const s8 *pchTemplateKey) = 0;

    //�޸Ĺ���ģ��
    virtual u32 RestModifyCommonTemplateReq(const TMTCommonTemplate_Api tMTComTemplate) = 0;

    //ɾ������ģ��
    virtual u32 RestDeleteCommonTemplateReq(const s8 *pchTemplateKey) = 0;

    //��ȡԤԼ�����б�
    virtual u32 RestGetBookConferenceListReq(const TMTConditionOfConfList_Api tConditionOfConfList) = 0;

    // ����ԤԼ����id��ȡ������Ϣ
    virtual u32 RestGetBookConferenceInfoByIDReq(const s8 *pchConfID) = 0;

    //��������
    virtual u32 RestCreateConferenceReq(const TMTInstantConference_Api &tMTInstantConference) = 0;

    //��������
    virtual u32 RestStopConferenceReq(const s8 *pchConfID) = 0;

    //��ȡ��ʱ�����б�
    virtual u32 RestGetConferenceListReq(const TMTGetIntanceConfList_Api &tConditionOfConfList) = 0;

    //���ݻ���ID,��ȡ��ʱ������Ϣ
    virtual u32 RestGetInstantConfInfoByIDReq(const s8 *pchConfID) = 0;

    //��ȡ�򵥸���ģ������
    virtual u32 RestGetSimplePerTemplateByIDReq(const s8 *pchTemplateID) = 0;

    //��ȡ����ģ��λ���Ա
    virtual u32 RestGetInviteMembersOfPerTemplateReq(const TMTGetPerTemplateInfo_Api &tGetPerTemplateInfo_Api) = 0;

    //��ȡ����ģ�������Ϣ
    virtual u32 RestGetMixInfoOfPerTemplateReq(const TMTGetPerTemplateInfo_Api &tGetPerTemplateInfo_Api) = 0;

    //��ȡ����ģ��VMP��Ϣ
    virtual u32 RestGetVMPInfoOfPerTemplateReq(const TMTGetPerTemplateInfo_Api &tGetPerTemplateInfo_Api) = 0;

    //��ȡ����ģ����ѯ��Ϣ
    virtual u32 RestGetPollInfoOfPerTemplateReq(const TMTGetPerTemplateInfo_Api &tGetPerTemplateInfo_Api) = 0;

    //��ȡ����ģ��vip
    virtual u32 RestGetVIPInfoOfPerTemplateReq(const TMTGetPerTemplateInfo_Api &tGetPerTemplateInfo_Api) = 0;

    //��ʼ¼��
    virtual u32 RestStartRecordReq(const TMTStartRecord_Api &tStartRecord_Api) = 0;

    //����¼��
    virtual u32 RestStopRecordReq(const TMTStopRecord_Api &tStopRecord_Api) = 0;

    //��ȡ¼��״̬
    virtual u32 RestGetRecordStateReq(const s8 *pchConfID, const s8 * pchRecordID) = 0;
    //�޸�¼��״̬
    virtual u32 RestModifyRecordStateReq(const TMTModifyRecordState_Api &tRecordState_Api) = 0;

    //��ȡ¼���б�
    virtual u32 RestGetRecordListReq(const s8 *pchConfID) = 0;
    //��ȡ���������ն��б�
    virtual u32 RestGetConfTerminalListReq(const s8 *pchConfID) = 0;

	// �ٿ��������������
//	virtual u32 RestCreateVirtualConfReq(const TMTCreateVConf_Api& tMtCreateVConf_Api) = 0;

	// ��ȡ�������������
	virtual	u32 RestGetVConfDetailInfoReq(const s8 *pchVConfID) = 0;

	// ��ȡ��Դռ�����
	virtual	u32 RestGetVConfResourceReq() = 0;

	// ��ȡ����������б�
	virtual	u32 RestGetVConfListReq(const TMTVConfListReq_Api& tMTVConfListReq_Api) = 0;
};

#endif // _I_MTMEETINGCTRL_H_