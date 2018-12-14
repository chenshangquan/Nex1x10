/**===========================================================================
 * @file    $Id$
 * @brief   ����IMҵ��ģ��Ĵ����붨��
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
 *@brief ���������(10���Ʊ�ʾ)
 *	 99                   99                    9             9999
 *	ģ��        +      ��ҵ�����      +     ����ȼ�    +   ��������
 *(2λ/100��)        ��2λ/100����          ��1λ/10����     (4λ/10000��)
 */

/** MTCONFҵ��ģ�����ҵ��ģ��ID����, ������ҵ����ඨ��ֻ������׷�� */
enum EM_ERR_SUBMOD_IM
{
	emErrSubModIm_ok			   = 0,
	emErrSubModIm_already_inited   = 1,    // �Ѿ���ʼ��--1
	emErrSubModIm_not_inited		= 2,	// û�г�ʼ��--2
	emErrSubModIm_invalid_argument	= 3,    // ��Ч����--3
	emErrSubModIm_invalid_jid 		= 4,                           // ��Ч��jid��ʽ--4
	emErrSubModIm_not_enough_mem 	= 5,                        // û���ڴ�--5
	emErrSubModIm_failed_to_init_ssl = 6,                    // ��ʼ��sslʧ��--6
	emErrSubModIm_too_long_string = 7,                       // �ַ���̫��--7
	emErrSubModIm_already_exists = 8,                        // �Ѿ����ڣ��������--8
	emErrSubModIm_no_such_friend = 9,                        // û���ҵ�����--9
	emErrSubModIm_no_such_group = 10,                         // û���ҵ���--10
	emErrSubModIm_not_login = 11,                             // ��û�е�¼--11
	emErrSubModIm_not_chatroom_service = 12,                  // û��chatroom����--12
	emErrSubModIm_room_not_ready = 13,                        // ����û��׼����--13
	emErrSubModIm_invitee_already_in_room = 14,               // Ⱥ���Ѵ��ڴ���ϵ��--14
	emErrSubModIm_not_owner = 15,                             // --15
	emErrSubModIm_no_such_participant = 16,                   // --16
	emErrSubModIm_invalid_room = 17,                          // --�Ƿ���Ⱥid--17
	emErrSubModIm_not_found = 18,                             // --18
	emErrSubModIm_invalid_presence = 19,                      // �Ƿ���״̬--19
	emErrSubModIm_no_file_share_ability = 20,                 // �Լ�û���ļ���������--20
	emErrSubModIm_peer_no_file_share_ability = 21,            // �Է�û���ļ���������--21
	emErrSubModIm_dms_private_data_not_ready = 22,            // ˽������û��׼����--22
	emErrSubModIm_dms_no_such_parent_group = 23,              // ���鲻����--23
	emErrSubModIm_dms_reach_max_sub_group_count = 24,         // ������Ŀ�Ѿ����--24
	emErrSubModIm_dms_reach_max_sub_member_count = 25,        // ���Ա��Ŀ�Ѿ����--25
	emErrSubModIm_dms_no_such_group = 26,                     // �鲻����--26
	emErrSubModIm_dms_has_sub_group = 27,                     // �����Ѵ���--27
	emErrSubModIm_dms_not_enough_buff = 28,                   // ������--28
	emErrSubModIm_dms_friend_already_in_the_group = 29,       // �����Ѵ��ڴ���ϵ��--29
	emErrSubModIm_dms_cannot_add_self = 30,                   // ��������Լ�Ϊ���Ա--30
	emErrSubModIm_dms_no_such_friend = 31,                    // �����ڴ���ϵ��--31
	emErrSubModIm_dms_move_method_forbidden = 32,             // �Ƿ�����--32
	emErrSubModIm_dms_forbid_add_subgroup = 33,               // ��ֹ�ڡ�δ���顱�������--33

	emErrSubModIm_no_pubsub_service = 34,                     // --34
	emErrSubModIm_dms_reach_max_total_members_count = 35,     // �ﵽ����Ա��--35
	emErrSubModIm_not_persistent_room = 36,                   // ���ǳ־��Է���--36
	emErrSubModIm_param_buff_full = 37,                       // ����buff���������ٴε��ã� --37
	emErrSubModIm_cannot_invite_self = 38,                    // ���������Լ���������
	emErrSubModIm_invalid_handle = 39,                        // ��Ч���( happ, ������������ �ļ������� )--38
	emErrSubModIm_disconnected = 40,                          // �����ѶϿ�
	emErrSubModIm_reach_max_temp_chatroom_limit = 41,         // ��������Ƶ������(��ʱ�Ļ�̶�������)
	emErrSubModIm_reach_max_persistent_chatroom_limit = 42,   // ��������Ƶ������(��ʱ�Ļ�̶�������)
	emErrSubModIm_chatroom_roster_not_ready = 43,             // ��û�л�ȡ�����ҵĳ�Ա�б�
	emErrSubModIm_chatroom_roster_is_full = 44,               // �����ҵĳ�Ա��������(192��)

	emErrSubModIm_failed_to_open_file = 45,                  // ���ļ�ʧ��
	emErrSubModIm_busy = 46,                                 // ��æ
	emErrSubModIm_no_such_chatroom = 47,                     // û�������ķ���
	emErrSubModIm_not_allowed = 48,                          // ������
	emErrSubModIm_char_state_not_changed = 49,               // ����״̬û�иı�
	emErrSubModIm_config_not_ready = 50,                     // ˽�������е����û�û�л�ȡ��
	emErrSubModIm_not_get_server_time = 51,                  // ��û�л�ȡ��������ʱ��
	emErrSubModIm_chat_msg_no_response = 52,                 // ����������Ϣ��û�лظ��Ƿ��ͳɹ�
	emErrSubModIm_parent_group_not_supported = 53,           // ROSTER��֧�ָ���
	emErrSubModIm_roster_group_exists = 54,                  // ROSTER���Ѿ�����
	emErrSubModIm_no_such_roster_group = 55,                 // ROSTER�鲻����
	emErrSubModIm_roster_group_to_be_deleted = 56,           // ��Ҫ��ɾ����ROSTER��
	emErrSubModIm_roster_contact_exists = 57,		     // ROSTER���Ѿ�������ϵ��
	emErrSubModIm_roster_no_contact = 58,                    // ROSTER�ﲻ���ڸ���ϵ��
	emErrSubModIm_roster_not_ready = 59,                     // ��û�л�ȡ��roster����
	emErrSubModIm_roster_unscribed_contact = 60,             // û�ж���״̬����ϵ��
	emErrSubModIm_cant_modify_special_group = 61,            // �����޸ġ�δ���顱
	emErrSubModIm_roster_group_name_conflict = 62,           // ��ϵ��������ͻ
	emErrSubModIm_room_exists = 63,                          // �����Ѿ�����
	emErrSubModIm_partial_error = 64,

	// roster���Ѿ����ڸ���ϵ��

	emErrSubModIm_service_param_length_incorrect   = 1000,  	// �������Ȳ���
	emErrSubModIm_service_reach_max_logging_account = 1001,                      // �Ѿ�ʹ������������˺Ž��е�¼
	emErrSubModIm_service_invalid_account_handle = 1002,                         // �����˺ű�־����
	emErrSubModIm_service_invalid_argument = 1003,                               // ��������
	emErrSubModIm_service_peer_not_online = 1004,
	emErrSubModIm_service_peer_no_file_share_ability = 1005,
	emErrSubModIm_service_no_resource = 1006,
	emErrSubModIm_failed_to_create_or_join_chatroom = 1007,                      // ����������������ʧ��
	emErrSubModIm_service_unauthoried = 1008,
	emErrSubModIm_unsupport = 1009,                                              // Ŀǰ��֧�ֵ�
	emErrSubModIm_no_chche_res = 1010,
	emErrSubModIm_file_share_no_space = 1011,                                    // ���̿ռ���
	emErrSubModIm_file_share_disconnected = 1012,                                // ��������Ͽ�
	emErrSubModIm_file_share_not_found = 1013,                                   // �ļ�û���ҵ�
	emErrSubModIm_butt = 1014,
	emErrSubModIm_file_share_received = 1015,                                   // �ļ��������ն˽�����


	/******************************/
	emErrSubModIm_err_login_disconnect = 2000,								 // ����ʧ��
	emErrSubModIm_err_overlogin = 2001,                                      // ͬһ�˺Ŷ���½
	emErrSubModIm_err_param_length_incorrect = 2002,		               // �������Ȳ���
	emErrSubModIm_err_reach_max_logging_account = 2003,                      // �Ѿ�ʹ������������˺Ž��е�¼
	emErrSubModIm_err_invalid_account_handle = 2004,                         // �����˺ű�־����
	emErrSubModIm_err_invalid_argument = 2005,                               // ��������
	emErrSubModIm_err_peer_not_online = 2006,								   // �Զ˲�����
	emErrSubModIm_err_peer_no_file_share_ability = 2007,						// �Զ�û�й����ļ�������
	emErrSubModIm_err_no_resource = 2008,										// û����Դ
	emErrSubModIm_err_unauthoried = 2009,										// �˺�û����֤ͨ��
	emErrSubModIm_err_unknown = 2010,

};


//////////////////////////////////////////////////////////// Call //////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////  END DEFINE/////////////////////////////////////////////////

//////////////////////////////////////////////////////////// Chan //////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////


//////////////////////////////////////////////////////////// Mtpa ////////////////////////////////////////////
 
/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////
#endif // _MTERRORCODE_MTIM_H_