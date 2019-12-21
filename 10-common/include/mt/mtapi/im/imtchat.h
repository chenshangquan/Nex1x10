/**===========================================================================
 * @file    $Id$
 * @brief   负责MtImAPi IM聊天请求相关功能接口定义
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
 * @brief   负责MtImAPi IM聊天请求相关功能接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtChat : public IMtApiIF
{
public:
	//请求登录XMPP服务器
	virtual u32 ImUserLoginReq( const TImUserLogin_Api& tImUserLogin_Api ) = 0;

	//获取聊天室服务状态请求
	virtual u32 ImGetChatRoomServiceAvailableReq() = 0;

	//注销请求 
	virtual u32 ImLogOutCmd( const u32 dwHandle ) = 0;

	//请求查询自己的自定义信息
	virtual u32 ImQuerySelfDefInfoReq( const u32 dwHandle ) = 0;

	//请求修改自己的自定义信息
	virtual u32 ImModifySelfDefInfoReq( const u32 dwHandle, const TImSelfDefInfo_Api& tImSelfDefInfo_Api, const TImSelfDefPic_Api& tImSelfDefPic_Api ) = 0;

	//查询某些用户的自定义信息请求
	virtual u32 ImQueryUserSelfDefInfoReq( const u32 dwHandle, const TImNOList_Api& tImNOList_Api ) = 0;

	//请求查询组信息
	virtual u32 ImQueryGroupInfoReq( const u32 dwHandle ) = 0;

	//请求查询某组的子组信息
	virtual u32 ImQueryGroupInfoByGroupSnReq( const u32 dwHandle, const TImSn_Api& tImSn_Api ) = 0;

	//创建组信息请求
	virtual u32 ImAddGroupInfoReq( const u32 dwHandle, const TImGroupInfo_Api& tImGroupInfo_Api ) = 0;

	//删除组信息请求
	virtual u32 ImDelGroupInfoReq( const u32 dwHandle, const TImSn_Api& tImSn_Api,const BOOL32 bReserved ) = 0;

	//修改组信息请求
	virtual u32 ImModifyGroupInfoReq( const u32 dwHandle, const TImGroupInfo_Api& tImGroupInfo_Api ) = 0;

	//查询某组下的联系人列表信息请求
	virtual u32 ImQueryMemberInfoByGroupSnReq( const u32 dwHandle, const TImSn_Api& tImSn_Api ) = 0;

	//创建联系人请求
	virtual u32 ImAddMemberInfoReq( const u32 dwHandle, const TImMemberInfo_Api& tImMemberInfo_Api ) = 0;

	//复制联系人请求
	virtual u32 ImCopyMemberReq( const u32 dwHandle, const TImMemberInfo_Api& tImMemberInfo_Api ) = 0;

	//删除联系人请求
	virtual u32 ImDelMemberInfoReq( const u32 dwHandle, const TImSn_Api& tImSn_Api ) = 0;

	//修改联系人请求    
	virtual u32 ImModifyMemberInfoReq( const u32 dwHandle, const TImMemberInfo_Api& tImMemberInfo_Api ) = 0;

	//移动联系人请求    
	virtual u32 ImMoveMemberInfoReq( const u32 dwHandle, const TImMoveMember_Api& tImMemberInfo_Api ) = 0;

	//查询某组下成员的在线状态请求
	virtual u32 ImQueryOnlineStateByGroupSnReq( const u32 dwHandle, const TImSn_Api& tImSn_Api ) = 0;

	//请求查询某组下成员的在线状态Req(包括终端类型)请求 
	virtual u32 ImQueryOnlineStateByGroupSnExReq( const u32 dwHandle, const TImSn_Api& tImSn_Api ) = 0;

	//修改自己的状态请求
	virtual u32 ImModifySelfStateReq( const u32 dwHandle, const TImSetUserState_Api& tImSetUserState_Api ) = 0;

	//发送点对点消息请求
	virtual u32 ImSendP2PMessageReq( const u32 dwHandle, const TImP2PChatMessage_Api& tImP2PChatMessage_Api ) = 0;

	//创建多人聊天请求
	virtual u32 ImMulitChatCreateReq( const u32 dwHandle, const TImMultiChatCreateInfo_Api& tImMulitChatCreateInfo_Api ) = 0;

	//结束多人聊天请求
	virtual u32 ImMulitChatDestroyCmd( const u32 dwHandle, const u32 dwChatID, const TRoomId_Api& tRoomId_Api ) = 0;

	//多人聊天增加成员请求
	virtual u32 ImMulitChatAddMemberReq( const u32 dwHandle, const TImMultiChatMemberInfo_Api& tImMultiChatMemberInfo_Api ) = 0;

	//多人聊天删除成员请求
	virtual u32 ImMulitChatDelMemberReq( const u32 dwHandle, const TImMultiChatMemberInfo_Api& tImMultiChatMemberInfo_Api ) = 0;

	//退出多人聊天请求
	virtual u32 ImMulitChatQuitReq( const u32 dwHandle, const u32 dwChatID, const TRoomId_Api& tRoomId_Api ) = 0;

	//多人聊天发送消息请求
	virtual u32 ImSendMulitSMSReq( const u32 dwHandle, const TImMultiChatMessage_Api& tImMultiChatMessage_Api ) = 0;

	//删除该用户所有好友请求
	virtual u32 ImClearDirReq( const u32 dwHandle ) = 0;

	//再次尝试登录
	virtual u32 ImRetryLoginCmd( const u32 dwHandle ) = 0;

	//ios设置固定群聊天信息已读请求
	virtual u32 ImSetChatroomMessagesReadFlagReq( const u32 dwHandle ) = 0;

	//请求一些用户的状态
	virtual u32 ImGetUsersStateReq( const u32 dwHandle, const TImNOList_Api& tImNOList_Api ) = 0;

	//请求一些用户的状态Req(包括终端类型)
	virtual u32 ImGetUsersStateExReq( const u32 dwHandle, const TImNOList_Api& tImNOList_Api ) = 0;

	//修改房间配置请求
	virtual u32 ImSetChatroomReq( const u32 dwHandle, const TImChatRoomInfo_Api& tImChatRoomInfo_Api ) = 0;

	//请求进入之前保存的固定讨论组
	virtual u32 ImQueryEnterSavedPersistentChatroomsReq( const u32 dwHandle, const TPersistentChatroomList_Api& tPersistentChatroomList_Api ) = 0;

	//告知Im层上层应用，登录后准备好请求
	virtual u32 ImSetReadyReq( const u32 dwHandle ) = 0;

	//告知对方自己的键盘输入状态请求
	virtual u32 ImSendCharStateReq( const u32 dwHandle, const TImCharState_Api& tImCharState_Api ) = 0;

	//告知对方闪屏请求
	virtual u32 ImSendSplashReq( const u32 dwHandle, const TImSplash_Api& tImSplash_Api ) = 0;

	//设置/获取自定义配置请求
	virtual u32 ImConfigReq( const u32 dwHandle, const TImCustomCfg_Api& tImCustomCfg_Api ) = 0;

	//屏蔽讨论组请求
	virtual u32 ImScreenChatromReq( const u32 dwHandle, const TImScreenChatroom_Api& tImScreenChatroom_Api ) = 0;

	//获取所有屏蔽讨论组请求
	virtual u32 GetScreenedChatromsReq( const u32 dwHandle ) = 0;

	//获取服务器时间请求
	virtual u32 GetServerTimeReq( const u32 dwHandle ) = 0;

	//修改时区命令
	virtual u32 ModifyTimeZoneCmd( ) = 0;

	//获取讨论组所有不在线成员请求
	virtual u32 ImMulitChatGetRostersReq( const u32 dwHandle, const u32 dwChatID, const TRoomId_Api& tRoomId_Api ) = 0;

	//获取某人参加的视频会议信息请求
	virtual u32 ImGetFriendConferenceReq( const u32 dwHandle, const TImNO_Api& tImNO ) = 0;

	//临时关注某联系人请求
	virtual u32 ImTempSubscribeReq( const u32 dwHandle, const TImNO_Api& tImNO ) = 0;

	//取消临时关注某联系人请求
	virtual u32 ImUnTempSubscribeReq( const u32 dwHandle, const TImNO_Api& tImNO ) = 0;

	//批量添加联系人到一个组请求
	virtual u32 ImBatchAddContactsReq( const u32 dwHandle, const TBatchAddContacts_Api& tBatchAddContacts_Api ) = 0;

	//批量删除联系人请求
	virtual u32 ImBatchDelContactsReq( const u32 dwHandle, const TBatchDelContacts_Api& tBatchDelContacts_Api ) = 0;

	//批量移动联系人到一个组请求
	virtual u32 ImBatchMoveContactsReq( const u32 dwHandle, const TBatchMoveContacts_Api& tBatchMoveContacts_Api ) = 0;

	//获取组织架构成员状态信息
	virtual u32 ImGetOrganizationStateReq( const u32 dwHandle, const s8 * pchImNO ) = 0;

	//屏蔽讨论组请求(真实屏蔽，无流量)
	virtual u32 ImScreenChatRomRReq(const u32 dwHandle, const TImScreenChatroomR_Api &tChatRoom) = 0;

    //获取固定讨论组请求
    virtual u32 ImGetHoldPersistentRoomReq(const u32 dwHandle) = 0;
};

#endif // _I_MTCHAT_H_