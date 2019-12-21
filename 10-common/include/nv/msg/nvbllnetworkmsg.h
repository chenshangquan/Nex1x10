#ifndef _NVBLLNETWORKMSG_H_
#define _NVBLLNETWORKMSG_H_

#include "nvmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLNvNetworkMsg
{
    EV_BLL_BGN(NETWORK) = EVSEG_BLL_NETWORK_BGN,
#endif

	/*********************************网络模块相关消息Begin***************************************/

	/*<<设置当前日期时间信息>>
	*BODY ：  tmttime 时间信息  
	*传输方向：sdk->dispatch->nvservice
	*/
	MESSAGE(Ev_NV_BLL_SetSysDataTime_Req)
	BODY(nv::TNVTime, tmttime )
	
	
	/*<<设置当前日期时间信息响应>>
	*BODY ：   result 设置结果 0成功 其他错误码
	           tmttime 时间信息 
	*传输方向：nvservice->dispatch->sdk
	*/
	MESSAGE(Ev_NV_BLL_SetSysDataTimeResult_Rsp)
	BODY(nv::TU32, result)
	BODY(nv::TNVTime, tmttime )


    /*<<设置当前日期时间通知>>
	*BODY ：   tmttime 时间信息 
	*传输方向：nvservice->dispatch->sdk
	* see
	*/
	MESSAGE(Ev_NV_BLL_SetSysDataTime_Ntf)
	BODY(nv::TNVTime, tmttime )
	
	/*<<Ping包 命令请求>>
	* ----------------------------------------------------------
	* 参数：pingtestparam    PING参数信息
	* ----------------------------------------------------------
	*传输方向：mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_NET_PingTestResult_Rsp
	*/
	MESSAGE(Ev_NV_BLL_NET_PingTest_Req)
	BODY(nv::TNVPingTestParam, pingtestparam )
	

	/*<<Ping包 响应结果>>
	* ----------------------------------------------------------
	* 参数：pingresult   PING结果信息
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice->mtsdk
	* see Ev_MT_BLL_NET_PingTest_Req
	*/
	MESSAGE(Ev_NV_BLL_NET_PingTestResult_Rsp)
	BODY(nv::TNVPingResult, pingresult )
	
	/*<<获取当前日期时间信息>>
	*BODY ：  tmttime 时间信息  
	*传输方向：sdk->dispatch->nvservice
	*/
	MESSAGE(Ev_NV_BLL_GetSysDataTime_Req)
	
	/*<<获取当前日期时间信息>>
	*BODY ：  tmttime 时间信息  
	*传输方向：nvservice->dispatch->sdk
	*/
	MESSAGE(Ev_NV_BLL_GetSysDataTime_Rsp)
	BODY(nv::TU32, result)
	BODY(nv::TNVTime, tmttime )
	
	/*<<打开关闭ftp>>
	*BODY ：  bopen true：打开，false关闭 
	*传输方向：sdk->dispatch->nvservice
	*/
	MESSAGE(Ev_NV_BLL_OpenFtp_Cmd)
	BODY(nv::TBOOL32, bopen )

	/*<<打开关闭ftp通知>>
	*BODY ：  bopen true：打开，false关闭 
	*传输方向：nvservice->dispatch->sdk
	*/
	MESSAGE(Ev_NV_BLL_OpenFtp_Nty)
	BODY(nv::TBOOL32, bopen )

	/*<<询问ftp状态>>
	*
	*传输方向：sdk->dispatch->nvservice
	*/
	MESSAGE(Ev_NV_BLL_GetFtpState_Req)

	/*<<询问ftp状态回应>>
	*BODY ：  bopen true：打开，false关闭 
	*传输方向：nvservice->dispatch->sdk
	*/
	MESSAGE(Ev_NV_BLL_GetFtpState_Rsp)
	BODY(nv::TBOOL32, bopen )
	
#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(NETWORK) = EVSEG_BLL_NETWORK_END
};
#endif

#define Is_BLL_Network_Msg(m) ((m) >= EV_BLL_BGN(NETWORK) && (m) <= EV_BLL_END(NETWORK))

#endif