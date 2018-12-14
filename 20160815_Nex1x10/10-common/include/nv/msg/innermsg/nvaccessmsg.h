#ifndef _NVACCESSMSG_H_
#define _NVACCESSMSG_H_

#include "nvmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmNvAccessMsg
{
    EV_BGN(ACCESS) = EVSEG_ACCESS_BGN,
#endif//_MESSAGE_HELP_

	/*<<终端客户端账号验证请求>>
	*loginuser_fullinfo ：账号验证用户详细信息
	*传输方向：nvc->dispatch->access
	*/
	MESSAGE(Ev_NV_NVCLogin_Req)
	BODY(nv::TUserFullInfo, loginuser_fullinfo)

	/*<<终端客户端账号验证应答>>
	*login_rsp ：账号验证应答结果
	*传输方向：access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_NVCLogin_Rsp)
	BODY(nv::TUserReqResult, loginuser_rsp)

	/*<<终端添加客户端账号请求>>
	*adduser_fullinfo ：终端添加客户端账号信息
	*传输方向：nvc->dispatch->access
	*/
	MESSAGE(Ev_NV_NVCAddUser_Req)
	BODY(nv::TMultiUserFullInfo, adduser_fullinfo)

	/*<<终端对客户端账号进行添加应答>>
	*adduser_rsp ：终端对客户端账号进行添加应答结果
	*传输方向：access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_NVCAddUser_Rsp)
	BODY(nv::TMultiUserReqResult, adduser_rsp)

	/*<<终端对客户端账号进行添加账号信息通知>>
	*adduser_ntf ：终端对客户端账号进行添加账号信息
	*传输方向：access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_NVCAddUser_Ntf)
	BODY(nv::TMultiUserFullInfo, adduser_ntf)

	/*<<终端对客户端账号进行修改请求>>
	*muser_fullinfo ：进行修改请求客户端账号信息
	*传输方向：nvc->dispatch->access
	*/
	MESSAGE(Ev_NV_NVCMUser_Req)
	BODY(nv::TMultiUserFullInfo, muser_fullinfo)

	/*<<终端对客户端账号进行修改应答>>
	*muser_rsp ：终端对客户端账号进行修改应答结果
	*传输方向：access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_NVCMUser_Rsp)
	BODY(nv::TMultiUserReqResult, muser_rsp)

	/*<<终端对客户端账号进行修改账号信息通知>>
	*muser_ntf ：终端对客户端账号进行修改账号信息
	*传输方向：access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_NVCMUser_Ntf)
	BODY(nv::TMultiUserFullInfo, muser_ntf)

	/*<<终端对客户端账号进行删除请求>>
	*duser ：进行删除请求客户端账号ID信息
	*传输方向：nvc->dispatch->access
	*/
	MESSAGE(Ev_NV_NVCDUser_Req)
	BODY(nv::TMultiU32, duserids)

	/*<<终端对客户端账号进行删除应答>>
	*duser_rsp ：终端对客户端账号进行删除应答结果
	*传输方向：access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_NVCDUser_Rsp)
	BODY(nv::TMultiUserReqResult, duser_rsp)

	/*<<终端对客户端账号进行删除账号信息通知>>
	*duser_ntf ：终端对客户端账号进行删除账号信息
	*传输方向：access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_NVCDUser_Ntf)
	BODY(nv::TMultiUserFullInfo, duser_ntf)

	/*<<终端对客户端账号进行查询请求>>
	*传输方向：nvc->dispatch->access
	*/
	MESSAGE(Ev_NV_NVCSUser_Req)

	/*<<终端对客户端账号进行查询应答>>
	*duser_rsp ：终端对客户端账号进行查询应答结果
	*传输方向：access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_NVCSUser_Rsp)
	BODY(nv::TMultiUserFullInfo, duser_rsp)

	/*<<终端客户端账号注销命令>>
	*user_name ：用户名
	*传输方向：nvc->dispatch->access
	*/
	MESSAGE(Ev_NV_NVCLogOut_Cmd)
	BODY(nv::TString, user_name)

	/*<<终端客户端账号注销通知>>
	*Ev_NV_NVCLogOut_Ntf ：账号验证用户详细信息
	*logoutuser_fullinfo ：注销账号用户详细信息
	*传输方向：access->dispatch->订阅者
	*/
	MESSAGE(Ev_NV_NVCLogOut_Ntf)
	BODY(nv::TUserFullInfo, logoutuser_fullinfo)

	/*<<生产测试状态回复>>
	*
	*/
	MESSAGE(Ev_NV_MfgTest_Ntf)
	BODY(nv::TBOOL32, bMftTest)

	/*<<生产测试状态回复>>
	*
	*/
	MESSAGE(Ev_NV_MfgTest_Rsp)
	BODY(nv::TBOOL32, bMftTest)
	/*<<Tpad登录通知>>
	*
	*/
	MESSAGE(Ev_NV_TpadLogin_Ntf)
#if !defined(_MESSAGE_HELP_)
    EV_END(ACCESS) = EVSEG_ACCESS_END
};
#endif//_MESSAGE_HELP_

#define Is_Access_Msg(m) ((m) >= EV_BGN(ACCESS) && (m) <= EV_END(ACCESS))

#endif//_NVACCESSMSG_H_