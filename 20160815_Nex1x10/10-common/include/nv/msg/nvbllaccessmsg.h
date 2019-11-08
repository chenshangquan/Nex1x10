#ifndef _NVBLLACCESSMSG_H_
#define _NVBLLACCESSMSG_H_

#include "nvmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLNvAccessMsg
{
    EV_BLL_BGN(ACCESS) = EVSEG_BLL_ACCESS_BGN,
#endif//_MESSAGE_HELP_

	/*<<终端客户端账号验证请求>>
	*loginuser_fullinfo ：账号验证用户详细信息
	*传输方向：nvc->dispatch->access
	*/
	MESSAGE(Ev_NV_BLL_NVCLogin_Req)
	BODY(nv::TUserFullInfo, loginuser_fullinfo)

	/*<<终端客户端账号验证应答>>
	*login_rsp ：账号验证应答结果
	*传输方向：access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_BLL_NVCLogin_Rsp)
	BODY(nv::TUserReqResult, loginuser_rsp)

	/*<<终端添加客户端账号请求>>
	*adduser_fullinfo ：终端添加客户端账号信息
	*传输方向：nvc->dispatch->access
	*/
	MESSAGE(Ev_NV_BLL_NVCAddUser_Req)
	BODY(nv::TMultiUserFullInfo, adduser_fullinfo)

	/*<<终端对客户端账号进行添加应答>>
	*adduser_rsp ：终端对客户端账号进行添加应答结果
	*传输方向：access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_BLL_NVCAddUser_Rsp)
	BODY(nv::TMultiUserReqResult, adduser_rsp)

	/*<<终端对客户端账号进行添加账号信息通知>>
	*adduser_ntf ：终端对客户端账号进行添加账号信息
	*传输方向：access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_BLL_NVCAddUser_Ntf)
	BODY(nv::TMultiUserFullInfo, adduser_ntf)

	/*<<终端对客户端账号进行修改请求>>
	*muser_fullinfo ：进行修改请求客户端账号信息
	*传输方向：nvc->dispatch->access
	*/
	MESSAGE(Ev_NV_BLL_NVCMUser_Req)
	BODY(nv::TMultiUserFullInfo, muser_fullinfo)

	/*<<终端对客户端账号进行修改应答>>
	*muser_rsp ：终端对客户端账号进行修改应答结果
	*传输方向：access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_BLL_NVCMUser_Rsp)
	BODY(nv::TMultiUserReqResult, muser_rsp)

	/*<<终端对客户端账号进行修改账号信息通知>>
	*muser_ntf ：终端对客户端账号进行修改账号信息
	*传输方向：access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_BLL_NVCMUser_Ntf)
	BODY(nv::TMultiUserFullInfo, muser_ntf)

	/*<<终端对客户端账号进行删除请求>>
	*duser ：进行删除请求客户端账号ID信息
	*传输方向：nvc->dispatch->access
	*/
	MESSAGE(Ev_NV_BLL_NVCDUser_Req)
	BODY(nv::TMultiU32, duserids)

	/*<<终端对客户端账号进行删除应答>>
	*duser_rsp ：终端对客户端账号进行删除应答结果
	*传输方向：access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_BLL_NVCDUser_Rsp)
	BODY(nv::TMultiUserReqResult, duser_rsp)

	/*<<终端对客户端账号进行删除账号信息通知>>
	*duser_ntf ：终端对客户端账号进行删除账号信息
	*传输方向：access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_BLL_NVCDUser_Ntf)
	BODY(nv::TMultiUserFullInfo, duser_ntf)

	/*<<终端对客户端账号进行查询请求>>
	*传输方向：nvc->dispatch->access
	*/
	MESSAGE(Ev_NV_BLL_NVCSUser_Req)

	/*<<终端对客户端账号进行查询应答>>
	*duser_rsp ：终端对客户端账号进行查询应答结果
	*传输方向：access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_BLL_NVCSUser_Rsp)
	BODY(nv::TMultiUserFullInfo, duser_rsp)

	/*<<终端客户端账号注销命令>>
	*user_name ：用户名
	*传输方向：nvc->dispatch->access
	*/
	MESSAGE(Ev_NV_BLL_NVCLogOut_Cmd)
	BODY(nv::TString, user_name)

	/*<<终端客户端账号注销通知>>
	*Ev_NV_BLL_NVCLogOut_Ntf ：账号验证用户详细信息
	*logoutuser_fullinfo ：注销账号用户详细信息
	*传输方向：access->dispatch->订阅者
	*/
	MESSAGE(Ev_NV_BLL_NVCLogOut_Ntf)
	BODY(nv::TUserFullInfo, logoutuser_fullinfo)

	/*<<生产测试状态回复>>
	*
	*/
	MESSAGE(Ev_NV_BLL_MfgTest_Ntf)
	BODY(nv::TBOOL32, bMftTest)

	/*<<生产测试状态回复>>
	*
	*/
	MESSAGE(Ev_NV_BLL_MfgTest_Rsp)
	BODY(nv::TBOOL32, bMftTest)

	/*<<imix版本号请求>>
	*
	*/
	MESSAGE(Ev_NV_BLL_NVVersion_Req)

	/*<<imix版本号回应>>
	*
	*/
	MESSAGE(Ev_NV_BLL_NVVersion_Rsp)
	BODY(nv::TString, imix_ver)

	/*<<imix是否与JD平台的版本一致>>
	*
	*/
	MESSAGE(Ev_NV_BLL_NVVerIsSameAsJDServer_Req)

	/*<<imix与JD平台的版本比较后的回应>>
	*
	*/
	MESSAGE(Ev_NV_BLL_NVVerIsSameAsJDServer_Rsp)
	BODY(nv::TBOOL32, bIsSame)

	/*<<imix是否从JD平台更新版本>>
	*
	*/
	MESSAGE(Ev_NV_BLL_NVIsUpgradeFromJDServer_Cmd)
	BODY(nv::TBOOL32, bIsUpgrade)

	/*<<imix从JD平台下载版本进度通知>>
	*
	*/
	MESSAGE(Ev_NV_BLL_NVDownloadFromJDServer_Nty)
	BODY(nv::TU32, dwSchedule)

	/*<<imix从JD平台下载版本结果通知>>
	*
	*/
	MESSAGE(Ev_NV_BLL_NVDownloadResultFromJD_Nty)
	BODY(nv::TBOOL32, tbResult)

	/*<<设置投屏器断链检测参数>>
	*login_rsp ：账号验证应答结果
	*传输方向：access->dispatch->nvc
	*/
	MESSAGE(Ev_NV_BLL_NVSetQKHbParm_Cmd)
	BODY(nv::TU16, wHb)
	BODY(nv::TU8, wHb)

#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(ACCESS) = EVSEG_BLL_ACCESS_END
};
#endif//_MESSAGE_HELP_

#define Is_BLL_Access_Msg(m) ((m) >= EV_BLL_BGN(ACCESS) && (m) <= EV_BLL_END(ACCESS))

#endif//_NVBLLACCESSMSG_H_