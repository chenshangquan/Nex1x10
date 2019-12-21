#ifndef _MTBLLACCESSMSG_H_
#define _MTBLLACCESSMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMtAccessMsg
{
    EV_BLL_BGN(ACCESS) = EVSEG_BLL_ACCESS_BGN,
#endif//_MESSAGE_HELP_

	/*<<终端客户端账号验证请求>>
	*loginuser_fullinfo ：账号验证用户详细信息
	*传输方向：mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_BLL_MTCLogin_Req)
	BODY(mt::TUserFullInfo, loginuser_fullinfo)

	/*<<终端客户端账号验证应答>>
	*login_rsp ：账号验证应答结果
	*传输方向：access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_BLL_MTCLogin_Rsp)
	BODY(mt::TUserReqResult, loginuser_rsp)

	/*<<终端添加客户端账号请求>>
	*adduser_fullinfo ：终端添加客户端账号信息
	*传输方向：mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_BLL_MTCAddUser_Req)
	BODY(mt::TMultiUserFullInfo, adduser_fullinfo)

	/*<<终端对客户端账号进行添加应答>>
	*adduser_rsp ：终端对客户端账号进行添加应答结果
	*传输方向：access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_BLL_MTCAddUser_Rsp)
	BODY(mt::TMultiUserReqResult, adduser_rsp)

	/*<<终端对客户端账号进行添加账号信息通知>>
	*adduser_ntf ：终端对客户端账号进行添加账号信息
	*传输方向：access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_BLL_MTCAddUser_Ntf)
	BODY(mt::TMultiUserFullInfo, adduser_ntf)

	/*<<终端对客户端账号进行修改请求>>
	*muser_fullinfo ：进行修改请求客户端账号信息
	*传输方向：mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_BLL_MTCMUser_Req)
	BODY(mt::TMultiUserFullInfo, muser_fullinfo)

	/*<<终端对客户端账号进行修改应答>>
	*muser_rsp ：终端对客户端账号进行修改应答结果
	*传输方向：access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_BLL_MTCMUser_Rsp)
	BODY(mt::TMultiUserReqResult, muser_rsp)

	/*<<终端对客户端账号进行修改账号信息通知>>
	*muser_ntf ：终端对客户端账号进行修改账号信息
	*传输方向：access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_BLL_MTCMUser_Ntf)
	BODY(mt::TMultiUserFullInfo, muser_ntf)

	/*<<终端对客户端账号进行删除请求>>
	*duser ：进行删除请求客户端账号ID信息
	*传输方向：mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_BLL_MTCDUser_Req)
	BODY(mt::TMultiU32, duserids)

	/*<<终端对客户端账号进行删除应答>>
	*duser_rsp ：终端对客户端账号进行删除应答结果
	*传输方向：access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_BLL_MTCDUser_Rsp)
	BODY(mt::TMultiUserReqResult, duser_rsp)

	/*<<终端对客户端账号进行删除账号信息通知>>
	*duser_ntf ：终端对客户端账号进行删除账号信息
	*传输方向：access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_BLL_MTCDUser_Ntf)
	BODY(mt::TMultiUserFullInfo, duser_ntf)

	/*<<终端对客户端账号进行查询请求>>
	*传输方向：mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_BLL_MTCSUser_Req)

	/*<<终端对客户端账号进行查询应答>>
	*duser_rsp ：终端对客户端账号进行查询应答结果
	*传输方向：access->dispatch->mtc
	*/
	MESSAGE(Ev_MT_BLL_MTCSUser_Rsp)
	BODY(mt::TMultiUserFullInfo, duser_rsp)

	/*<<终端客户端账号注销命令>>
	*user_name ：用户名
	*传输方向：mtc->dispatch->access
	*/
	MESSAGE(Ev_MT_BLL_MTCLogOut_Cmd)
	BODY(mt::TString, user_name)

	/*<<终端客户端账号注销通知>>
	*Ev_MT_BLL_MTCLogOut_Ntf ：账号验证用户详细信息
	*logoutuser_fullinfo ：注销账号用户详细信息
	*传输方向：access->dispatch->订阅者
	*/
	MESSAGE(Ev_MT_BLL_MTCLogOut_Ntf)
	BODY(mt::TUserFullInfo, logoutuser_fullinfo)

	/*<<skyshare登录状态通知>>
	*Ev_MT_MTCSkyShareLoginState_Ntf ：skyshare登录状态
	*loginstate ：登录状态
	*传输方向：access->dispatch->订阅者
	*/
	MESSAGE(Ev_MT_BLL_MTCSkyShareLoginState_Ntf)
	BODY(mt::TBOOL32, loginstate)

	/*<<请求skyshare登录状态>>
	*传输方向：mtc->dispatch->service
	*/
	MESSAGE(Ev_MT_BLL_MTCGetSkyShareLoginState_Req)

	/*<<mtc登录结果>>
	*Ev_MT_BLL_NewMtcLogin_Rsp ：
	*tLoginRet ：登录结果
	*/
	MESSAGE( Ev_MT_BLL_NewMtcLogin_Rsp  )
	BODY(mt::TMtcLoginRet, tLoginRet)


    /*<<mtc握手请求>>
	*Ev_MT_BLL_HandShake_Req ：
	*tLoginRet ：登录结果
	*/
	MESSAGE( Ev_MT_BLL_HandShake_Req  )

	/*<<mtc握手响应>>
	*Ev_MT_BLL_HandShake_Rsp ：
	*tLoginRet ：登录结果
	*/
	MESSAGE( Ev_MT_BLL_HandShake_Rsp  )
	BODY(mt::THandShakeParam, tParam)

	/*<<抢占通知>>
	*Ev_MT_BLL_HandShake_Rsp ：
	*tLoginRet ：登录结果
	*/
	MESSAGE( Ev_MT_BLL_HaveBeenKicked_Ntf )
	BODY(mt::TMtcBaseInfo, tlocal)
	BODY(mt::TMtcBaseInfo, tkicker)

	/*<<请求动态口  用于数据协作>>
	*Ev_MT_BLL_GetDynamicPwd_Cmd ：
	*/
	MESSAGE( Ev_MT_BLL_GetDynamicPwd_Cmd )
	
	/*<<动态口令通知  用于数据协作>>
	*Ev_MT_BLL_GetDynamicPwd_Ntf ：
	*tDynamic ：动态口令
	*/
	MESSAGE( Ev_MT_BLL_GetDynamicPwd_Ntf )
	BODY(mt::TString, tDynamic)

	/*<<动态口令校验， 用于数据协作>>
	*/
	MESSAGE( Ev_MT_BLL_CheckDynamicPwd_Cmd )
	
	/*<<动态口令校验结果通知， 用于数据协作>>
	*bRet ：校验结果
	*/
	MESSAGE( Ev_MT_BLL_CheckDynamicPwd_Ntf )
	BODY(mt::TBOOL32, bRet)

	/*<<获取终端版本信息等，用户登录前调用>>
	*/
	MESSAGE( Ev_MT_BLL_GetMTInfo_Req)

	/*<<终端版本信息响应>>
	*/
	MESSAGE( Ev_MT_BLL_GetMTInfo_Rsp)
	BODY(mt::TMtVersionInfo, tInfo)
	
	MESSAGE( Ev_MT_BLL_GetTrueRandBytes_Req)
	BODY(mt::TU16, tLen)

	MESSAGE( Ev_MT_BLL_GetTrueRandBytes_Rsp)
	BODY(mt::TBytes, tRandBytes )

	/*重新设置SM4 key的消息通知
	*/
	MESSAGE( Ev_MT_BLL_ResetSecKey_Ntf)
	BODY(mt::TU32, result)
	BODY(mt::TBOOL32, bKeepAccount)

	//动态口令清除命令，用于数据协作
	MESSAGE( Ev_MT_BLL_CleanDynamicPwd_Cmd )

	//动态口令清除通知， 用于数据协作
	MESSAGE( Ev_MT_BLL_CleanDynamicPwd_Ntf)

	/*<<mtc信息列表请求
	*/
	MESSAGE(Ev_MT_BLL_GetMtcInfoList_Req)

	/*<<mtc信息列表响应
	*/
	MESSAGE(Ev_MT_BLL_GetMtcInfoList_Rsp)

	/*<<请求动态口令  用于登录>>
	*Ev_MT_BLL_GetLoginDynamicPwd_Cmd ：
	*/
	MESSAGE( Ev_MT_BLL_GetLoginDynamicPwd_Cmd )
	
	/*<<动态口令通知  用于登录>>
	*Ev_MT_BLL_GetLoginDynamicPwd_Ntf ：
	*tDynamic ：动态口令
	*/
	MESSAGE( Ev_MT_BLL_GetLoginDynamicPwd_Ntf )
	BODY(mt::TString, tDynamic)

	//获取webmtc (前端)登录状态的请求, 用于osd处理操作隔离
	MESSAGE( Ev_MT_BLL_GetWebMtcLoginState_Req )

	//获取webmtc (前端)登录状态响应
	MESSAGE( Ev_MT_BLL_GetWebMtcLoginState_Rsp )
	BODY(mt::TBOOL32, bLogin)

	//webmtc (前端)登录状态通知
	MESSAGE( Ev_MT_BLL_GetWebMtcLoginState_Ntf )
	BODY(mt::TBOOL32, bLogin)

	//请求用户登录密码剩余时间
	MESSAGE( Ev_MT_BLL_GetUserPwdRestTime_Req )

	//请求用户登录密码剩余时间的响应
	MESSAGE( Ev_MT_BLL_GetUserPwdRestTime_Rsp )
	BODY(mt::TU32, tdwRestTime)
	BODY(mt::TUserFullInfo, tUserFullInfo)

	//osd解除用户登录锁定命令
	MESSAGE( Ev_MT_BLL_SetUserLoginUnLock_Cmd )

	//osd解除用户登录锁定通知
	MESSAGE( Ev_MT_BLL_SetUserLoginUnLock_Ntf )

	//osd获取用户登录锁定状态的请求
	MESSAGE( Ev_MT_BLL_GetUserLoginLockState_Req )

	//osd获取用户登录锁定状态的响应
	MESSAGE( Ev_MT_BLL_GetUserLoginLockState_Rsp )
	BODY(mt::TBOOL32, bLock)

	//用户登录锁定状态的通知
	MESSAGE( Ev_MT_BLL_GetUserLoginLockState_Ntf )
	BODY(mt::TBOOL32, bLock)

	//osd重置管理员用户名和密码命令
	MESSAGE( Ev_MT_BLL_ResetAdminUserInfo_Cmd )

	//osd重置管理员用户名和密码的通知
	MESSAGE( Ev_MT_BLL_ResetAdminUserInfo_Ntf )
	BODY(mt::TMultiUserFullInfo, resetmuser_ntf)

#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(ACCESS) = EVSEG_BLL_ACCESS_END
};
#endif//_MESSAGE_HELP_

#define Is_BLL_Access_Msg(m) ((m) >= EV_BLL_BGN(ACCESS) && (m) <= EV_BLL_END(ACCESS))

#endif//_MTBLLACCESSMSG_H_