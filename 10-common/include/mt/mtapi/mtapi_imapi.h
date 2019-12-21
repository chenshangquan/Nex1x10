/*******************************************************************************//**
*@file          mtapi_imapi.h
*@brief         提供mtimapi对外接口
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_IMAPI_H_
#define _MTAPI_IMAPI_H_
/**@addtogroup api API接口
*@{
*/

/**@addtogroup imapi 聊天API
*@{
*/

#include <string.h>
#include "mtapi_export.h"
#include "mtapi_typedef.h"
#include "mtapi_struct.h"


 

/**
* KdvMt_IMIsInited
* @brief mtimapi是否进行过初始化
*
* @param	[in] void
* @return	BOOL32  TRUE ： 已初始化， FALSE：尚未初始化
* @note KdvMt_IMInitalize, KdvMt_IMUnInitalize
*/
KdvMtAPI BOOL32 KdvMtCALL KdvMt_IMIsInited();



/**
* KdvMt_IMInitalize
*
* @brief mtimapi模块初始化（这个的调用要在mtbaseapi调用的setnotify之后）
*
* @return	u32  0: 初始化成功， 非0: 初始化失败
* @note KdvMt_IMIsInited, KdvMt_IMUnInitalize
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMInitalize( );



/**
* KdvMt_IMUnInitalize
*
* @brief mtimapi模块释放退出
*
* @param	[in] void
* @return	u32  0: 成功， 非0: 失败
* @note KdvMt_IMIsInited, KdvMt_IMInitalize
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMUnInitalize();



/**
* KdvMt_IMSetNotify
*
* @brief  注册Observer(UI)通知回调(这个函数如果没有调用则使用mtbaseapi中的回调函数)
*
* @param    [in]   cbNotify  要注册的回调函数
* @return   void
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMSetNotify( IN NOTIFY_OBSERVER_CALLBACK cbNotify );


/**
* KdvMt_IMUserLoginReq
*
* @brief  请求登录XMPP服务器
*
* @param    [in]   tImUserLogin_Api 用户登录信息
* @param    [in]   dwSSID  MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImLogin_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMUserLoginReq( IN CONST TImUserLogin_Api& tImUserLogin_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_GetChatRoomServiceAvailable
*
* @brief  获取聊天室服务状态
*
* @param    [in]   bAvailable 是否可用
* @param    [in]   dwSSID  MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ImGetChatRoomServiceAvailableReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMtCALL KdvMt_IMLogOutCmd
*
* @brief  注销命令
*
* @param    [in]   dwHandle 句柄
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMLogOutCmd( IN CONST u32 dwHandle, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_IMQuerySelfDefInfoReq
*
* @brief  请求查询自己的自定义信息
*
* @param    [in]   dwHandle 句柄
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImQuerySelfDefInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMQuerySelfDefInfoReq( IN CONST u32 dwHandle, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMModifySelfDefInfoReq
*
* @brief  请求修改自己的自定义信息
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImSelfDefInfo_Api 自定义信息
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImModiySelfDefInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMModifySelfDefInfoReq( IN CONST u32 dwHandle, IN CONST TImSelfDefInfo_Api& tImSelfDefInfo_Api, IN CONST TImSelfDefPic_Api& tImSelfDefPic_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMQuerySpecifiedUserDefInfoReq
*
* @brief  查询指定用户的自定义信息请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   TImNOList_Api NO列表
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImQuerySpecifiedUserDefInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMQuerySpecifiedUserDefInfoReq( IN CONST u32 dwHandle, IN CONST TImNOList_Api& tImNOList_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_IMQueryGroupInfoReq
*
* @brief  请求查询组信息
*
* @param    [in]   dwHandle 句柄
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImQueryGroupInfo_Error_Rsp & Ev_MtApi_ImQueryGroupInfo_Rsp & Ev_MtApi_ImQueryGroupInfo_Fin_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMQueryGroupInfoReq( IN CONST u32 dwHandle, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMQuerySubGroupInfoByGroupSnReq
*
* @brief  请求查询某组的子组信息
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImSn_Api结构体
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImQuerySubGroupInfoByGroupSn_Error_Rsp & Ev_MtApi_ImQuerySubGroupInfoByGroupSn_Rsp & Ev_MtApi_ImQuerySubGroupInfoByGroupSn_Fin_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMQuerySubGroupInfoByGroupSnReq( IN CONST u32 dwHandle, IN CONST TImSn_Api& tImSn_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMAddGroupInfoReq
*
* @brief  创建组信息请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImGroupInfo_Api 组信息
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImAddGroupInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMAddGroupInfoReq( IN CONST u32 dwHandle, IN CONST TImGroupInfo_Api& tImGroupInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMDelGroupInfoReq
*
* @brief  删除组信息请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImDelGroupInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMDelGroupInfoReq( IN CONST u32 dwHandle, IN CONST TImSn_Api& tImSn_Api,IN CONST BOOL32 bReserved, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMModifyGroupInfoReq
*
* @brief  修改组信息请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImGroupInfo_Api 组信息
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImModifyGroupInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMModifyGroupInfoReq( IN CONST u32 dwHandle, IN CONST TImGroupInfo_Api& tImGroupInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMQueryMemberInfoByGroupSnReq
*
* @brief  查询某组下的联系人列表信息请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImSn_Api 结构体
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImQueryMemberInfoByGroupSn_Error_Rsp & Ev_MtApi_ImQueryMemberInfoByGroupSn_Rsp & Ev_MtApi_ImQueryMemberInfoByGroupSn_Fin_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMQueryMemberInfoByGroupSnReq( IN CONST u32 dwHandle, IN CONST TImSn_Api& tImSn_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMAddMemberInfoReq
*
* @brief  创建联系人请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImMemberInfo_Api 成员信息
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：成功时回复Ev_MtApi_ImAddMemberInfo_Rsp，失败时回复Ev_MtApi_ImQueryAddMemberInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMAddMemberInfoReq( IN CONST u32 dwHandle, IN CONST TImMemberInfo_Api& tImMemberInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMCopyMemberReq
*
* @brief  复制联系人请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImMemberInfo_Api 成员信息
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImCopyMember_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMCopyMemberReq( IN CONST u32 dwHandle, IN CONST TImMemberInfo_Api& tImMemberInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMDelMemberInfoReq
*
* @brief  删除联系人请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImSn_Api 结构体
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImDelMemberInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMDelMemberInfoReq( IN CONST u32 dwHandle, IN CONST TImSn_Api& tImSn_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMModifyMemberInfoReq
*
* @brief  修改联系人请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImMemberInfo_Api 成员信息
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImModifyMemberInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMModifyMemberInfoReq( IN CONST u32 dwHandle, IN CONST TImMemberInfo_Api& tImMemberInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_IMMoveMemberInfoReq
*
* @brief  移动联系人请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImMemberInfo_Api 成员信息
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImMoveMemberInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMMoveMemberInfoReq( IN CONST u32 dwHandle, IN CONST TImMoveMember_Api& tImMemberInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
* KdvMt_IMQueryOnlineStateByGroupSnReq
*
* @brief  查询某组下成员的在线状态请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImSn_Api 结构体
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImQueryOnlineStateByGroupSn_Rsp & Ev_MtApi_ImQueryOnlineStateByGroupSn_Ntf & Ev_MtApi_ImQueryOnlineStateByGroupSn_Fin_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMQueryOnlineStateByGroupSnReq( IN CONST u32 dwHandle, IN CONST TImSn_Api& tImSn_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMQueryOnlineStateByGroupSnExReq
*
* @brief  请求查询某组下成员的在线状态Req(包括终端类型)请求 
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImSn_Api 结构体
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImQueryOnlineStateByGroupSnEx_Rsp & Ev_MtApi_ImQueryOnlineStateByGroupSnEx_Ntf & Ev_MtApi_ImQueryOnlineStateByGroupSnEx_Fin_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMQueryOnlineStateByGroupSnExReq( IN CONST u32 dwHandle, IN CONST TImSn_Api& tImSn_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMModifySelfStateReq
*
* @brief  修改自己的状态请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImSetUserState_Api 用户状态
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImModifySelfState_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMModifySelfStateReq( IN CONST u32 dwHandle, IN CONST TImSetUserState_Api& tImSetUserState_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMSendP2PMessageReq
*
* @brief  发送点对点消息请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImSendP2PMessage_Rsp & Ev_MtApi_ImSendP2PMessage_Ntf & Ev_MtApi_ImSendP2PMessageInstant_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMSendP2PMessageReq( IN CONST u32 dwHandle, IN CONST TImP2PChatMessage_Api& tImP2PChatMessage_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMMulitChatCreateReq
*
* @brief  创建多人聊天请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImMulitChatCreateInfo_Api 创建群信息(只有chatname, confe164, persistent需要上层填写)
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImMulitChatCreate_Rsp & Ev_MtApi_ImMulitChatCreate_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMMulitChatCreateReq( IN CONST u32 dwHandle, IN CONST TImMultiChatCreateInfo_Api& tImMultiChatCreateInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMMulitChatDestroyReq
*
* @brief  结束多人聊天请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   dwChatID 聊天ID,对应于创建聊天室的clientid
* @param    [in]   tRoomId_Api 聊天室ID 
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImMulitChatDestroy_Rsp & Ev_MtApi_ImMulitChatDestroy_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMMulitChatDestroyReq( IN CONST u32 dwHandle, IN CONST u32 dwChatID, IN CONST TRoomId_Api& tRoomId_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMMulitChatAddMemberReq
* @brief  多人聊天增加成员请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImMultiChatMemberInfo_Api 聊天成员信息 
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImMulitChatAddMember_Rsp & Ev_MtApi_ImMulitChatAddMember_Ntf & Ev_MtApi_ImMulitChatMemberStatusChange_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMMulitChatAddMemberReq( IN CONST u32 dwHandle, IN CONST TImMultiChatMemberInfo_Api& tImMultiChatMemberInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMMulitChatDelMemberReq
* @brief  多人聊天删除成员请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImMultiChatMemberInfo_Api 聊天成员信息 
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImMulitChatDelMember_Rsp & Ev_MtApi_ImMulitChatDelMember_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMMulitChatDelMemberReq( IN CONST u32 dwHandle, IN CONST TImMultiChatMemberInfo_Api& tImMultiChatMemberInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMMulitChatQuitReq
* 
* @brief  退出多人聊天请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   dwChatID 聊天ID,对应于创建聊天室的clientid
* @param    [in]   tRoomId_Api 聊天室ID 
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImMulitChatQuit_Rsp & Ev_MtApi_ImMulitChatMemberLeave_Ntf 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMMulitChatQuitReq( IN CONST u32 dwHandle, IN CONST u32 dwChatID, IN CONST TRoomId_Api& tRoomId_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMSendMulitSMSReq
* 
* @brief  多人聊天发送消息请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImMultiChatMessage_Api 聊天消息
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImSendMulitSMS_Rsp & Ev_MtApi_ImSendMulitSMS_Ntf & Ev_MtApi_ImSendMulitSMSInstant_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMSendMulitSMSReq( IN CONST u32 dwHandle, IN CONST TImMultiChatMessage_Api& tImMultiChatMessage_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMClearDirReq
* 
* @brief  删除该用户所有好友请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImClearDir_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMClearDirReq( IN CONST u32 dwHandle, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMRetryLoginCmd
* 
* @brief  再次尝试登录
*
* @param    [in]   dwHandle 句柄
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMRetryLoginCmd( IN CONST u32 dwHandle, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMSetChatroomMessagesReadFlagReq
* 
* @brief  ios设置固定群聊天信息已读请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImSetChatroomMessagesReadFlag_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMSetChatroomMessagesReadFlagReq( IN CONST u32 dwHandle, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMGetUsersStateReq
* 
* @brief  请求一些用户的状态
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImNOList_Api NO列表
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImGetUsersState_Rsp & Ev_MtApi_ImGetUsersState_Ntf & Ev_MtApi_ImGetUsersState_Fin_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMGetUsersStateReq( IN CONST u32 dwHandle, IN CONST TImNOList_Api& tImNOList_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMGetUsersStateExReq
* 
* @brief  请求一些用户的状态Req(包括终端类型)
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImNOList_Api NO列表
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImGetUsersStateEx_Rsp & Ev_MtApi_ImGetUsersStateEx_Ntf & Ev_MtApi_ImGetUsersStateEx_Fin_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMGetUsersStateExReq( IN CONST u32 dwHandle, IN CONST TImNOList_Api& tImNOList_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMSetChatroomReq
* 
* @brief  修改房间配置请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImChatRoomInfo_Api 聊天室信息
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImSetChatroom_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMSetChatroomReq( IN CONST u32 dwHandle, IN CONST TImChatRoomInfo_Api& tImChatRoomInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMQueryEnterSavedPersistentChatroomsReq
* 
* @brief  请求进入之前保存的固定讨论组
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tPersistentChatroomList_Api 结构体
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImQueryEnterSavedPersistentChatrooms_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMQueryEnterSavedPersistentChatroomsReq( IN CONST u32 dwHandle, IN CONST TPersistentChatroomList_Api& tPersistentChatroomList_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMSetReadyReq
* 
* @brief  告知Im层上层应用，登录后准备好请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImSetReady_Rsp & Ev_MtApi_ImSetReady_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMSetReadyReq( IN CONST u32 dwHandle, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMSendCharStateReq
* 
* @brief  告知对方自己的键盘输入状态请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImCharState_Api 键盘输入状态
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImSendCharState_Rsp & Ev_MtApi_ImCharState_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMSendCharStateReq( IN CONST u32 dwHandle, IN CONST TImCharState_Api& tImCharState_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMSendSplashReq
* 
* @brief  告知对方闪屏请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImSplash_Api 闪屏信息
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImSendSplash_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMSendSplashReq( IN CONST u32 dwHandle, IN CONST TImSplash_Api& tImSplash_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMConfigReq
* 
* @brief  设置/获取自定义配置请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImCustomCfg_Api 自定义配置
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：？
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMConfigReq( IN CONST u32 dwHandle, IN CONST TImCustomCfg_Api& tImCustomCfg_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMScreenChatromReq
* 
* @brief  屏蔽讨论组请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImScreenChatroom_Api   屏蔽讨论组 
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImScreenChatrom_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMScreenChatromReq( IN CONST u32 dwHandle, IN CONST TImScreenChatroom_Api& tImScreenChatroom_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMGetScreenedChatromsReq
* 
* @brief  获取所有屏蔽讨论组请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImGetScreenedChatroms_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMGetScreenedChatromsReq( IN CONST u32 dwHandle, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMGetServerTimeReq
* 
* @brief  获取服务器时间请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImGetServerTime_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMGetServerTimeReq( IN CONST u32 dwHandle, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMModifyTimeZoneCmd
* 
* @brief  修改时区命令
*
* @param    [in]   dwSSID   MT会话ID 
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMModifyTimeZoneCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_IMMulitChatGetRostersReq（暂时用不到）
* 
* @brief  获取讨论组所有不在线成员请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   dwChatID   聊天ID,对应于创建聊天室的clientid
* @param    [in]   tRoomId_Api   聊天室ID 
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_MulitChatGetRosters_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMMulitChatGetRostersReq( IN CONST u32 dwHandle, IN CONST u32 dwChatID, IN CONST TRoomId_Api& tRoomId_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_IMGetFriendConferenceReq
* 
* @brief  获取某人参加的视频会议信息请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImNO   结构体
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImGetFriendConference_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMGetFriendConferenceReq( IN CONST u32 dwHandle, IN CONST TImNO_Api& tImNO, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMTempSubscribeReq
* 
* @brief  临时关注某联系人请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImNO   结构体
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImTempSubscribe_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMTempSubscribeReq( IN CONST u32 dwHandle, IN CONST TImNO_Api& tImNO, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMUnTempSubscribeReq
* 
* @brief  取消临时关注某联系人请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImNO   结构体
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImUnTempSubscribe_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMUnTempSubscribeReq( IN CONST u32 dwHandle, IN CONST TImNO_Api& tImNO, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMBatchAddContacts
* 
* @brief  批量添加联系人到一个组请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tBatchAddContacts_Api   批量添加联系人信息
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImBatchAddContacts_Rsp, Ev_MtApi_ImMemberAdd_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMBatchAddContacts( IN CONST u32 dwHandle, IN CONST TBatchAddContacts_Api& tBatchAddContacts_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMBatchDelContactsReq
* 
* @brief  批量删除联系人请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tBatchDelContacts_Api   批量删除联系人信息
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImBatchDelContacts_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMBatchDelContactsReq( IN CONST u32 dwHandle, IN CONST TBatchDelContacts_Api& tBatchDelContacts_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMBatchMoveContacts
* 
* @brief  批量移动联系人到一个组请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tBatchMoveContacts_Api   批量移动联系人信息
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImBatchMoveContacts_Rsp, ImMemberDelNtf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMBatchMoveContacts( IN CONST u32 dwHandle, IN CONST TBatchMoveContacts_Api& tBatchMoveContacts_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );





/**
* KdvMt_IMSendFileReq
* 
* @brief  文件/文件夹传输请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImFileShareReq_Api   文件共享请求
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImSendFile_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMSendFileReq( IN CONST u32 dwHandle, IN CONST TImFileShareReq_Api& tImFileShareReq_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMAcceptFileReq
* 
* @brief  接受/拒绝对端的文件/文件夹传输请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   dwSessionID session id
* @param    [in]   bRecv
* @param    [in]   bSetSavePath
* @param    [in]   pachPath
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImAcceptFile_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMAcceptFileReq( IN CONST u32 dwHandle, IN CONST u32 dwSessionID, IN CONST BOOL32 bRecv, IN CONST BOOL32 bSetSavePath, IN CONST char * pachPath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMCancelFileReq
* 
* @brief  中断文件/文件夹传输请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   dwSessionID session id
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImCancelFile_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMCancelFileReq( IN CONST u32 dwHandle, IN CONST u32 dwSessionID, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMSetFileSavePathReq
* 
* @brief  设置文件保存路径请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   pachPath 文件保存路径
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImSetFileSavePath_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMSetFileSavePathReq( IN CONST u32 dwHandle, IN CONST char * pachPath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMSendGroupChatFileCmd
* 
* @brief  多人文件/文件夹传输请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tImGroupChatFileShareReq_Api 结构体
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImSendGroupChatFile_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMSendGroupChatFileCmd( IN CONST u32 dwHandle, IN CONST TImGroupChatFileShareReq_Api& tImGroupChatFileShareReq_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMIosSetTempPathCmd
* 
* @brief  ios系统请求设置临时目录Req(只用于IOS系统)
*
* @param    [in]   dwHandle 句柄
* @param    [in]   pachPath 临时目录　
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMIosSetTempPathCmd( IN CONST u32 dwHandle, IN CONST char * pachPath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IMSetFileTransferBitRateReq
* 
* @brief  设置文件传输带宽请求
*
* @param    [in]   dwHandle 句柄
* @param    [in]   dwRate 　带宽
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMSetFileTransferBitRateReq( IN CONST u32 dwRate, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_IMGetOrganizationStateReq
* 
* @brief  获取组织架构成员状态信息
*
* @param    [in]   dwHandle 句柄
* @param    [in]   pchImNO  企业名称
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IMGetOrganizationStateReq( IN CONST u32 dwHandle, IN CONST s8 * pchImNO, IN CONST SessionID dwSSID  = KMTAPI_DEF_SSID );

/**
* KdvMt_ImScreenChatRomRReq
* 
* @brief  屏蔽讨论组请求(真实屏蔽，无流量)
*
* @param    [in]   dwHandle 句柄
* @param    [in]   tChatRoom  讨论组信息
* @param    [in]   dwSSID   MT会话ID 
* @return   u32  0：成功，  其他：错误码 
*
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ImScreenChatRomRReq( IN CONST u32 dwHandle, IN CONST TImScreenChatroomR_Api &tChatRoom, IN CONST SessionID dwSSID  = KMTAPI_DEF_SSID );


/**
* KdvMt_ImGetHoldPersistentRoomReq
* 
* @brief  获取固定讨论组请求
*
* @param    [in]   dwHandle 句柄
* @return   u32  0：成功，  其他：错误码 
*
* @note 响应通知：Ev_MtApi_ImGetHoldPersistentRoom_Rsp, Ev_MtApi_ImPersistentChatrooms_Ntf (分包), Ev_MtApi_ImPersistentChatrooms_Fin_Ntf (结束)
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ImGetHoldPersistentRoomReq( IN CONST u32 dwHandle, IN CONST SessionID dwSSID  = KMTAPI_DEF_SSID);

/**@}*/

/**@}*/
#endif //_MTAPI_IMAPI_H_