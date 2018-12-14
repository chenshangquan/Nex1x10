#ifndef _MTBLLDCSMSG_H_
#define _MTBLLDCSMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMtDcsMsg
{
    EV_BLL_BGN(DCS) = EVSEG_BLL_DCS_BGN,
#endif


	MESSAGE(Ev_MT_BLL_DCS_BuildChain_Cmd)
	MESSAGE(Ev_MT_BLL_DCS_LoginSrv_Req)
	//MESSAGE(Ev_MT_BLL_DCS_LoginSrv_KeepAlive_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_Logout_Req)
	MESSAGE(Ev_MT_BLL_DCS_CreateConf_Req)
	MESSAGE(Ev_MT_BLL_DCS_GetConfAddr_Req)
	MESSAGE(Ev_MT_BLL_DCS_JoinConf_Req)
	MESSAGE(Ev_MT_BLL_DCS_RejectJoinConf_Cmd)
	MESSAGE(Ev_MT_BLL_DCS_QuitConf_Req)
	MESSAGE(Ev_MT_BLL_DCS_ReleaseConf_Req)
	MESSAGE(Ev_MT_BLL_DCS_AddMember_Req)
	MESSAGE(Ev_MT_BLL_DCS_DelMember_Req)
	MESSAGE(Ev_MT_BLL_DCS_SetConfInfo_Req)
	MESSAGE(Ev_MT_BLL_DCS_Add_Operator_Req)
	MESSAGE(Ev_MT_BLL_DCS_Del_Operator_Req)
	MESSAGE(Ev_MT_BLL_DCS_ApplyOper_Req)
	MESSAGE(Ev_MT_BLL_DCS_CancelOper_Req)
	MESSAGE(Ev_MT_BLL_DCS_GetUserList_Req)
	MESSAGE(Ev_MT_BLL_DCS_NewWhiteBoard_Req)
	MESSAGE(Ev_MT_BLL_DCS_DelWhiteBoard_Req)
	MESSAGE(Ev_MT_BLL_DCS_DelAllWhiteBoard_Req)
	MESSAGE(Ev_MT_BLL_DCS_GetAllWhiteBoard_Req)
	MESSAGE(Ev_MT_BLL_DCS_GetWhiteBoard_Req)
	MESSAGE(Ev_MT_BLL_DCS_GetCurWhiteBoard_Req)
	MESSAGE(Ev_MT_BLL_DCS_Switch_Req)
	MESSAGE(Ev_MT_BLL_DCS_Oper_Cmd)
	MESSAGE(Ev_MT_BLL_DCS_GetImageUrl_Req)
    MESSAGE(Ev_MT_BLL_DCS_UploadFile_Cmd)
    MESSAGE(Ev_MT_BLL_DCS_DownloadFile_Req)


	MESSAGE(Ev_MT_BLL_DCS_LoginSrv_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_Logout_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_CreateConf_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_GetConfAddr_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_InviteUser_Cmd)
	MESSAGE(Ev_MT_BLL_DCS_JoinConf_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_QuitConf_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_ReleaseConf_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_AddMember_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_DelMember_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_SetConfInfo_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_AddOperator_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_DelOperator_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_ApplyOper_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_CancelOper_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_GetUserList_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_NewWhiteBoard_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_DelWhiteBoard_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_DelAllWhiteBoard_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_GetAllWhiteBoard_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_GetWhiteBoard_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_GetCurWhiteBoard_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_Switch_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_UserJoinConf_Ntf)
	MESSAGE(Ev_MT_BLL_DCS_UserQuitConf_Ntf)
	MESSAGE(Ev_MT_BLL_DCS_ReleaseConf_Ntf)
	MESSAGE(Ev_MT_BLL_DCS_AddUserFail_Ntf)
	MESSAGE(Ev_MT_BLL_DCS_DelUserFail_Ntf)
	MESSAGE(Ev_MT_BLL_DCS_UpdateConfInfo_Ntf)
	MESSAGE(Ev_MT_BLL_DCS_UserApplyOper_Ntf)
	MESSAGE(Ev_MT_BLL_DCS_SpecOper_Ntf)
	MESSAGE(Ev_MT_BLL_DCS_CancelOper_Ntf)
	MESSAGE(Ev_MT_BLL_DCS_NewWhiteBoard_Ntf)
	MESSAGE(Ev_MT_BLL_DCS_DelWhiteBoard_Ntf)
	MESSAGE(Ev_MT_BLL_DCS_DelAllWhiteBoard_Ntf)
	MESSAGE(Ev_MT_BLL_DCS_Switch_Ntf)
	MESSAGE(Ev_MT_BLL_DCS_AddOperator_Ntf)
	MESSAGE(Ev_MT_BLL_DCS_DelOperator_Ntf)
	MESSAGE(Ev_MT_BLL_DCS_CurrentWhiteBoard_Ntf)
	MESSAGE(Ev_MT_BLL_DCS_LoginResult_Ntf)
	MESSAGE(Ev_MT_BLL_DCS_ConfResult_Ntf)
	MESSAGE(Ev_MT_BLL_DCS_Oper_Ntf)
	MESSAGE(Ev_MT_BLL_DCS_Oper_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_DownloadImage_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_DownloadImage_Ntf)
	MESSAGE(Ev_MT_BLL_DCS_UploadImage_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_UploadImage_Ntf)
    MESSAGE(Ev_MT_BLL_DCS_UploadFile_Ntf)
    MESSAGE(Ev_MT_BLL_DCS_DownloadFile_Rsp)
	MESSAGE(Ev_MT_BLL_DCS_RejectOper_Ntf)
	MESSAGE(Ev_MT_BLL_DCS_CancelManager_Ntf)
	MESSAGE(Ev_MT_BLL_DCS_SpecManager_Ntf)
	MESSAGE(Ev_MT_BLL_DCS_JoinConf_Domain_Req)

#if !defined(_MESSAGE_HELP_)
     EV_BLL_END(DCS) = EVSEG_BLL_DCS_END
};
#endif

#define Is_BLL_MtDcs_Msg(m) ((m) >= EV_BLL_BGN(DCS) && (m) <= EV_BLL_END(DCS))

#endif  // _MTBLLDCSMSG_H_