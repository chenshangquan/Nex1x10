#ifndef _MTACCESSMSG_H_
#define _MTACCESSMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMtAccessMsg
{
    EV_BGN(ACCESS) = EVSEG_ACCESS_BGN,
#endif//_MESSAGE_HELP_

	/*<<终端客户端账号验证请求>>
	*loginuser_fullinfo ：账号验证用户详细信息
	*传输方向：mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_MTCLogin_Req)
	BODY(mt::TUserFullInfo, loginuser_fullinfo)

	/*<<终端客户端账号验证应答>>
	*login_rsp ：账号验证应答结果
	*传输方向：access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_MTCLogin_Rsp)
	BODY(mt::TUserReqResult, loginuser_rsp)

	/*<<终端添加客户端账号请求>>
	*adduser_fullinfo ：终端添加客户端账号信息
	*传输方向：mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_MTCAddUser_Req)
	BODY(mt::TMultiUserFullInfo, adduser_fullinfo)

	/*<<终端对客户端账号进行添加应答>>
	*adduser_rsp ：终端对客户端账号进行添加应答结果
	*传输方向：access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_MTCAddUser_Rsp)
	BODY(mt::TMultiUserReqResult, adduser_rsp)

	/*<<终端对客户端账号进行添加账号信息通知>>
	*adduser_ntf ：终端对客户端账号进行添加账号信息
	*传输方向：access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_MTCAddUser_Ntf)
	BODY(mt::TMultiUserFullInfo, adduser_ntf)

	/*<<终端对客户端账号进行修改请求>>
	*muser_fullinfo ：进行修改请求客户端账号信息
	*传输方向：mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_MTCMUser_Req)
	BODY(mt::TMultiUserFullInfo, muser_fullinfo)

	/*<<终端对客户端账号进行修改应答>>
	*muser_rsp ：终端对客户端账号进行修改应答结果
	*传输方向：access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_MTCMUser_Rsp)
	BODY(mt::TMultiUserReqResult, muser_rsp)

	/*<<终端对客户端账号进行修改账号信息通知>>
	*muser_ntf ：终端对客户端账号进行修改账号信息
	*传输方向：access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_MTCMUser_Ntf)
	BODY(mt::TMultiUserFullInfo, muser_ntf)

	/*<<终端对客户端账号进行删除请求>>
	*duser ：进行删除请求客户端账号ID信息
	*传输方向：mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_MTCDUser_Req)
	BODY(mt::TMultiU32, duserids)

	/*<<终端对客户端账号进行删除应答>>
	*duser_rsp ：终端对客户端账号进行删除应答结果
	*传输方向：access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_MTCDUser_Rsp)
	BODY(mt::TMultiUserReqResult, duser_rsp)

	/*<<终端对客户端账号进行删除账号信息通知>>
	*duser_ntf ：终端对客户端账号进行删除账号信息
	*传输方向：access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_MTCDUser_Ntf)
	BODY(mt::TMultiUserFullInfo, duser_ntf)

	/*<<终端对客户端账号进行查询请求>>
	*传输方向：mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_MTCSUser_Req)

	/*<<终端对客户端账号进行查询应答>>
	*duser_rsp ：终端对客户端账号进行查询应答结果
	*传输方向：access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_MTCSUser_Rsp)
	BODY(mt::TMultiUserFullInfo, duser_rsp)

	/*<<终端客户端账号注销命令>>
	*user_name ：用户名
	*传输方向：mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_MTCLogOut_Cmd)
	BODY(mt::TString, user_name)

	/*<<终端客户端账号注销通知>>
	*Ev_MT_MTCLogOut_Ntf ：账号验证用户详细信息
	*logoutuser_fullinfo ：注销账号用户详细信息
	*传输方向：access->dispatch->订阅者
	*/
	MESSAGE(Ev_MT_MTCLogOut_Ntf)
	BODY(mt::TUserFullInfo, logoutuser_fullinfo)

	/*<<skyshare登录状态通知>>
	*Ev_MT_MTCSkyShareLoginState_Ntf ：skyshare登录状态
	*loginstate ：登录状态
	*传输方向：access->dispatch->订阅者
	*/
	MESSAGE(Ev_MT_MTCSkyShareLoginState_Ntf)
	BODY(mt::TBOOL32, loginstate)

	/*<<skyshare登录状态请求>>
	*传输方向：mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_MTCSkyShareLoginState_Req)
	
	/*<<skyshare登录状态Rsp>>
	*Ev_MT_MTCSkyShareLoginState_Rsp ：skyshare登录状态
	*loginstate ：登录状态
	*传输方向：access->dispatch->请求者
	*/
	MESSAGE(Ev_MT_MTCSkyShareLoginState_Rsp)
	BODY(mt::TBOOL32, loginstate)
#if !defined(_MESSAGE_HELP_)
    EV_END(ACCESS) = EVSEG_ACCESS_END
};
#endif//_MESSAGE_HELP_

#define Is_Access_Msg(m) ((m) >= EV_BGN(ACCESS) && (m) <= EV_END(ACCESS))

#endif//_MTACCESSMSG_H_