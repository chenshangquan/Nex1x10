/**===========================================================================
 * @file    $Id$
 * @brief   负责IM业务模块的错误码定义
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _MTERRORCODE_MTIM_H_
#define _MTERRORCODE_MTIM_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief 错误码规则(10进制表示)
 *	 99                   99                    9             9999
 *	模块        +      子业务分类      +     错误等级    +   分配数量
 *(2位/100个)        （2位/100个）          （1位/10个）     (4位/10000个)
 */

/** MTCONF业务模块的子业务模块ID定义, 新增子业务分类定义只能往后追加 */
enum EM_ERR_SUBMOD_IM
{
	emErrSubModIm_ok			   = 0,
	emErrSubModIm_already_inited   = 1,    // 已经初始化--1
	emErrSubModIm_not_inited		= 2,	// 没有初始化--2
	emErrSubModIm_invalid_argument	= 3,    // 无效参数--3
	emErrSubModIm_invalid_jid 		= 4,                           // 无效的jid格式--4
	emErrSubModIm_not_enough_mem 	= 5,                        // 没有内存--5
	emErrSubModIm_failed_to_init_ssl = 6,                    // 初始化ssl失败--6
	emErrSubModIm_too_long_string = 7,                       // 字符串太长--7
	emErrSubModIm_already_exists = 8,                        // 已经存在，不需添加--8
	emErrSubModIm_no_such_friend = 9,                        // 没有找到好友--9
	emErrSubModIm_no_such_group = 10,                         // 没有找到组--10
	emErrSubModIm_not_login = 11,                             // 还没有登录--11
	emErrSubModIm_not_chatroom_service = 12,                  // 没有chatroom服务--12
	emErrSubModIm_room_not_ready = 13,                        // 房间没有准备好--13
	emErrSubModIm_invitee_already_in_room = 14,               // 群里已存在此联系人--14
	emErrSubModIm_not_owner = 15,                             // --15
	emErrSubModIm_no_such_participant = 16,                   // --16
	emErrSubModIm_invalid_room = 17,                          // --非法的群id--17
	emErrSubModIm_not_found = 18,                             // --18
	emErrSubModIm_invalid_presence = 19,                      // 非法的状态--19
	emErrSubModIm_no_file_share_ability = 20,                 // 自己没有文件传输能力--20
	emErrSubModIm_peer_no_file_share_ability = 21,            // 对方没有文件传输能力--21
	emErrSubModIm_dms_private_data_not_ready = 22,            // 私有数据没有准备好--22
	emErrSubModIm_dms_no_such_parent_group = 23,              // 父组不存在--23
	emErrSubModIm_dms_reach_max_sub_group_count = 24,         // 子组数目已经最大化--24
	emErrSubModIm_dms_reach_max_sub_member_count = 25,        // 组成员数目已经最大化--25
	emErrSubModIm_dms_no_such_group = 26,                     // 组不存在--26
	emErrSubModIm_dms_has_sub_group = 27,                     // 子组已存在--27
	emErrSubModIm_dms_not_enough_buff = 28,                   // 缓存满--28
	emErrSubModIm_dms_friend_already_in_the_group = 29,       // 组内已存在此联系人--29
	emErrSubModIm_dms_cannot_add_self = 30,                   // 不能添加自己为组成员--30
	emErrSubModIm_dms_no_such_friend = 31,                    // 不存在此联系人--31
	emErrSubModIm_dms_move_method_forbidden = 32,             // 非法操作--32
	emErrSubModIm_dms_forbid_add_subgroup = 33,               // 禁止在“未分组”添加子组--33

	emErrSubModIm_no_pubsub_service = 34,                     // --34
	emErrSubModIm_dms_reach_max_total_members_count = 35,     // 达到最大成员数--35
	emErrSubModIm_not_persistent_room = 36,                   // 不是持久性房间--36
	emErrSubModIm_param_buff_full = 37,                       // 参数buff已满（请再次调用） --37
	emErrSubModIm_cannot_invite_self = 38,                    // 不能邀请自己到聊天室
	emErrSubModIm_invalid_handle = 39,                        // 无效句柄( happ, 多人聊天句柄， 文件传输句柄 )--38
	emErrSubModIm_disconnected = 40,                          // 链接已断开
	emErrSubModIm_reach_max_temp_chatroom_limit = 41,         // 创建非视频聊天室(临时的或固定的上限)
	emErrSubModIm_reach_max_persistent_chatroom_limit = 42,   // 创建非视频聊天室(临时的或固定的上限)
	emErrSubModIm_chatroom_roster_not_ready = 43,             // 还没有获取聊天室的成员列表
	emErrSubModIm_chatroom_roster_is_full = 44,               // 聊天室的成员个数已满(192个)

	emErrSubModIm_failed_to_open_file = 45,                  // 打开文件失败
	emErrSubModIm_busy = 46,                                 // 正忙
	emErrSubModIm_no_such_chatroom = 47,                     // 没有这样的房间
	emErrSubModIm_not_allowed = 48,                          // 不允许
	emErrSubModIm_char_state_not_changed = 49,               // 输入状态没有改变
	emErrSubModIm_config_not_ready = 50,                     // 私有数据中的配置还没有获取到
	emErrSubModIm_not_get_server_time = 51,                  // 还没有获取到服务器时间
	emErrSubModIm_chat_msg_no_response = 52,                 // 发送聊天消息后没有回复是否发送成功
	emErrSubModIm_parent_group_not_supported = 53,           // ROSTER不支持父组
	emErrSubModIm_roster_group_exists = 54,                  // ROSTER组已经存在
	emErrSubModIm_no_such_roster_group = 55,                 // ROSTER组不存在
	emErrSubModIm_roster_group_to_be_deleted = 56,           // 将要被删除的ROSTER组
	emErrSubModIm_roster_contact_exists = 57,		     // ROSTER里已经存在联系人
	emErrSubModIm_roster_no_contact = 58,                    // ROSTER里不存在该联系人
	emErrSubModIm_roster_not_ready = 59,                     // 还没有获取到roster数据
	emErrSubModIm_roster_unscribed_contact = 60,             // 没有订阅状态的联系人
	emErrSubModIm_cant_modify_special_group = 61,            // 不能修改“未分组”
	emErrSubModIm_roster_group_name_conflict = 62,           // 联系人组名冲突
	emErrSubModIm_room_exists = 63,                          // 房间已经存在
	emErrSubModIm_partial_error = 64,

	// roster里已经存在该联系人

	emErrSubModIm_service_param_length_incorrect   = 1000,  	// 参数长度不对
	emErrSubModIm_service_reach_max_logging_account = 1001,                      // 已经使用了最大数量账号进行登录
	emErrSubModIm_service_invalid_account_handle = 1002,                         // 参数账号标志不对
	emErrSubModIm_service_invalid_argument = 1003,                               // 参数不对
	emErrSubModIm_service_peer_not_online = 1004,
	emErrSubModIm_service_peer_no_file_share_ability = 1005,
	emErrSubModIm_service_no_resource = 1006,
	emErrSubModIm_failed_to_create_or_join_chatroom = 1007,                      // 创建或加入多人聊天失败
	emErrSubModIm_service_unauthoried = 1008,
	emErrSubModIm_unsupport = 1009,                                              // 目前不支持的
	emErrSubModIm_no_chche_res = 1010,
	emErrSubModIm_file_share_no_space = 1011,                                    // 磁盘空间满
	emErrSubModIm_file_share_disconnected = 1012,                                // 传输网络断开
	emErrSubModIm_file_share_not_found = 1013,                                   // 文件没有找到
	emErrSubModIm_butt = 1014,
	emErrSubModIm_file_share_received = 1015,                                   // 文件被其他终端接收了


	/******************************/
	emErrSubModIm_err_login_disconnect = 2000,								 // 连接失败
	emErrSubModIm_err_overlogin = 2001,                                      // 同一账号多点登陆
	emErrSubModIm_err_param_length_incorrect = 2002,		               // 参数长度不对
	emErrSubModIm_err_reach_max_logging_account = 2003,                      // 已经使用了最大数量账号进行登录
	emErrSubModIm_err_invalid_account_handle = 2004,                         // 参数账号标志不对
	emErrSubModIm_err_invalid_argument = 2005,                               // 参数不对
	emErrSubModIm_err_peer_not_online = 2006,								   // 对端不在线
	emErrSubModIm_err_peer_no_file_share_ability = 2007,						// 对端没有共享文件的能力
	emErrSubModIm_err_no_resource = 2008,										// 没有资源
	emErrSubModIm_err_unauthoried = 2009,										// 账号没有认证通过
	emErrSubModIm_err_unknown = 2010,

};


//////////////////////////////////////////////////////////// Call //////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////  END DEFINE/////////////////////////////////////////////////

//////////////////////////////////////////////////////////// Chan //////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////


//////////////////////////////////////////////////////////// Mtpa ////////////////////////////////////////////
 
/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////
#endif // _MTERRORCODE_MTIM_H_