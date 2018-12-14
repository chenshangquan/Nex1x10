/**===========================================================================
 * @file    $Id$
 * @brief   ����MtImAPi IM����������ع��ܽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTCHAT_H_
#define _I_MTCHAT_H_

#include "mtapi_typedef.h"
#include "mtapi_struct.h"
#include "mtapi_if.h"
#include "mtapi_event_im.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtChat
 * @brief   ����MtImAPi IM����������ع��ܽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtChat : public IMtApiIF
{
public:
	//�����¼XMPP������
	virtual u32 ImUserLoginReq( const TImUserLogin_Api& tImUserLogin_Api ) = 0;

	//��ȡ�����ҷ���״̬����
	virtual u32 ImGetChatRoomServiceAvailableReq() = 0;

	//ע������ 
	virtual u32 ImLogOutCmd( const u32 dwHandle ) = 0;

	//�����ѯ�Լ����Զ�����Ϣ
	virtual u32 ImQuerySelfDefInfoReq( const u32 dwHandle ) = 0;

	//�����޸��Լ����Զ�����Ϣ
	virtual u32 ImModifySelfDefInfoReq( const u32 dwHandle, const TImSelfDefInfo_Api& tImSelfDefInfo_Api, const TImSelfDefPic_Api& tImSelfDefPic_Api ) = 0;

	//��ѯĳЩ�û����Զ�����Ϣ����
	virtual u32 ImQueryUserSelfDefInfoReq( const u32 dwHandle, const TImNOList_Api& tImNOList_Api ) = 0;

	//�����ѯ����Ϣ
	virtual u32 ImQueryGroupInfoReq( const u32 dwHandle ) = 0;

	//�����ѯĳ���������Ϣ
	virtual u32 ImQueryGroupInfoByGroupSnReq( const u32 dwHandle, const TImSn_Api& tImSn_Api ) = 0;

	//��������Ϣ����
	virtual u32 ImAddGroupInfoReq( const u32 dwHandle, const TImGroupInfo_Api& tImGroupInfo_Api ) = 0;

	//ɾ������Ϣ����
	virtual u32 ImDelGroupInfoReq( const u32 dwHandle, const TImSn_Api& tImSn_Api,const BOOL32 bReserved ) = 0;

	//�޸�����Ϣ����
	virtual u32 ImModifyGroupInfoReq( const u32 dwHandle, const TImGroupInfo_Api& tImGroupInfo_Api ) = 0;

	//��ѯĳ���µ���ϵ���б���Ϣ����
	virtual u32 ImQueryMemberInfoByGroupSnReq( const u32 dwHandle, const TImSn_Api& tImSn_Api ) = 0;

	//������ϵ������
	virtual u32 ImAddMemberInfoReq( const u32 dwHandle, const TImMemberInfo_Api& tImMemberInfo_Api ) = 0;

	//������ϵ������
	virtual u32 ImCopyMemberReq( const u32 dwHandle, const TImMemberInfo_Api& tImMemberInfo_Api ) = 0;

	//ɾ����ϵ������
	virtual u32 ImDelMemberInfoReq( const u32 dwHandle, const TImSn_Api& tImSn_Api ) = 0;

	//�޸���ϵ������    
	virtual u32 ImModifyMemberInfoReq( const u32 dwHandle, const TImMemberInfo_Api& tImMemberInfo_Api ) = 0;

	//�ƶ���ϵ������    
	virtual u32 ImMoveMemberInfoReq( const u32 dwHandle, const TImMoveMember_Api& tImMemberInfo_Api ) = 0;

	//��ѯĳ���³�Ա������״̬����
	virtual u32 ImQueryOnlineStateByGroupSnReq( const u32 dwHandle, const TImSn_Api& tImSn_Api ) = 0;

	//�����ѯĳ���³�Ա������״̬Req(�����ն�����)���� 
	virtual u32 ImQueryOnlineStateByGroupSnExReq( const u32 dwHandle, const TImSn_Api& tImSn_Api ) = 0;

	//�޸��Լ���״̬����
	virtual u32 ImModifySelfStateReq( const u32 dwHandle, const TImSetUserState_Api& tImSetUserState_Api ) = 0;

	//���͵�Ե���Ϣ����
	virtual u32 ImSendP2PMessageReq( const u32 dwHandle, const TImP2PChatMessage_Api& tImP2PChatMessage_Api ) = 0;

	//����������������
	virtual u32 ImMulitChatCreateReq( const u32 dwHandle, const TImMultiChatCreateInfo_Api& tImMulitChatCreateInfo_Api ) = 0;

	//����������������
	virtual u32 ImMulitChatDestroyCmd( const u32 dwHandle, const u32 dwChatID, const TRoomId_Api& tRoomId_Api ) = 0;

	//�����������ӳ�Ա����
	virtual u32 ImMulitChatAddMemberReq( const u32 dwHandle, const TImMultiChatMemberInfo_Api& tImMultiChatMemberInfo_Api ) = 0;

	//��������ɾ����Ա����
	virtual u32 ImMulitChatDelMemberReq( const u32 dwHandle, const TImMultiChatMemberInfo_Api& tImMultiChatMemberInfo_Api ) = 0;

	//�˳�������������
	virtual u32 ImMulitChatQuitReq( const u32 dwHandle, const u32 dwChatID, const TRoomId_Api& tRoomId_Api ) = 0;

	//�������췢����Ϣ����
	virtual u32 ImSendMulitSMSReq( const u32 dwHandle, const TImMultiChatMessage_Api& tImMultiChatMessage_Api ) = 0;

	//ɾ�����û����к�������
	virtual u32 ImClearDirReq( const u32 dwHandle ) = 0;

	//�ٴγ��Ե�¼
	virtual u32 ImRetryLoginCmd( const u32 dwHandle ) = 0;

	//ios���ù̶�Ⱥ������Ϣ�Ѷ�����
	virtual u32 ImSetChatroomMessagesReadFlagReq( const u32 dwHandle ) = 0;

	//����һЩ�û���״̬
	virtual u32 ImGetUsersStateReq( const u32 dwHandle, const TImNOList_Api& tImNOList_Api ) = 0;

	//����һЩ�û���״̬Req(�����ն�����)
	virtual u32 ImGetUsersStateExReq( const u32 dwHandle, const TImNOList_Api& tImNOList_Api ) = 0;

	//�޸ķ�����������
	virtual u32 ImSetChatroomReq( const u32 dwHandle, const TImChatRoomInfo_Api& tImChatRoomInfo_Api ) = 0;

	//�������֮ǰ����Ĺ̶�������
	virtual u32 ImQueryEnterSavedPersistentChatroomsReq( const u32 dwHandle, const TPersistentChatroomList_Api& tPersistentChatroomList_Api ) = 0;

	//��֪Im���ϲ�Ӧ�ã���¼��׼��������
	virtual u32 ImSetReadyReq( const u32 dwHandle ) = 0;

	//��֪�Է��Լ��ļ�������״̬����
	virtual u32 ImSendCharStateReq( const u32 dwHandle, const TImCharState_Api& tImCharState_Api ) = 0;

	//��֪�Է���������
	virtual u32 ImSendSplashReq( const u32 dwHandle, const TImSplash_Api& tImSplash_Api ) = 0;

	//����/��ȡ�Զ�����������
	virtual u32 ImConfigReq( const u32 dwHandle, const TImCustomCfg_Api& tImCustomCfg_Api ) = 0;

	//��������������
	virtual u32 ImScreenChatromReq( const u32 dwHandle, const TImScreenChatroom_Api& tImScreenChatroom_Api ) = 0;

	//��ȡ������������������
	virtual u32 GetScreenedChatromsReq( const u32 dwHandle ) = 0;

	//��ȡ������ʱ������
	virtual u32 GetServerTimeReq( const u32 dwHandle ) = 0;

	//�޸�ʱ������
	virtual u32 ModifyTimeZoneCmd( ) = 0;

	//��ȡ���������в����߳�Ա����
	virtual u32 ImMulitChatGetRostersReq( const u32 dwHandle, const u32 dwChatID, const TRoomId_Api& tRoomId_Api ) = 0;

	//��ȡĳ�˲μӵ���Ƶ������Ϣ����
	virtual u32 ImGetFriendConferenceReq( const u32 dwHandle, const TImNO_Api& tImNO ) = 0;

	//��ʱ��עĳ��ϵ������
	virtual u32 ImTempSubscribeReq( const u32 dwHandle, const TImNO_Api& tImNO ) = 0;

	//ȡ����ʱ��עĳ��ϵ������
	virtual u32 ImUnTempSubscribeReq( const u32 dwHandle, const TImNO_Api& tImNO ) = 0;

	//���������ϵ�˵�һ��������
	virtual u32 ImBatchAddContactsReq( const u32 dwHandle, const TBatchAddContacts_Api& tBatchAddContacts_Api ) = 0;

	//����ɾ����ϵ������
	virtual u32 ImBatchDelContactsReq( const u32 dwHandle, const TBatchDelContacts_Api& tBatchDelContacts_Api ) = 0;

	//�����ƶ���ϵ�˵�һ��������
	virtual u32 ImBatchMoveContactsReq( const u32 dwHandle, const TBatchMoveContacts_Api& tBatchMoveContacts_Api ) = 0;

	//��ȡ��֯�ܹ���Ա״̬��Ϣ
	virtual u32 ImGetOrganizationStateReq( const u32 dwHandle, const s8 * pchImNO ) = 0;

	//��������������(��ʵ���Σ�������)
	virtual u32 ImScreenChatRomRReq(const u32 dwHandle, const TImScreenChatroomR_Api &tChatRoom) = 0;

    //��ȡ�̶�����������
    virtual u32 ImGetHoldPersistentRoomReq(const u32 dwHandle) = 0;
};

#endif // _I_MTCHAT_H_