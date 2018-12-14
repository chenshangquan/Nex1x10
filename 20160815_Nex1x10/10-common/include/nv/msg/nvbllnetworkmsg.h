#ifndef _NVBLLNETWORKMSG_H_
#define _NVBLLNETWORKMSG_H_

#include "nvmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLNvNetworkMsg
{
    EV_BLL_BGN(NETWORK) = EVSEG_BLL_NETWORK_BGN,
#endif

	/*********************************����ģ�������ϢBegin***************************************/

	/*<<���õ�ǰ����ʱ����Ϣ>>
	*BODY ��  tmttime ʱ����Ϣ  
	*���䷽��sdk->dispatch->nvservice
	*/
	MESSAGE(Ev_NV_BLL_SetSysDataTime_Req)
	BODY(nv::TNVTime, tmttime )
	
	
	/*<<���õ�ǰ����ʱ����Ϣ��Ӧ>>
	*BODY ��   result ���ý�� 0�ɹ� ����������
	           tmttime ʱ����Ϣ 
	*���䷽��nvservice->dispatch->sdk
	*/
	MESSAGE(Ev_NV_BLL_SetSysDataTimeResult_Rsp)
	BODY(nv::TU32, result)
	BODY(nv::TNVTime, tmttime )


    /*<<���õ�ǰ����ʱ��֪ͨ>>
	*BODY ��   tmttime ʱ����Ϣ 
	*���䷽��nvservice->dispatch->sdk
	* see
	*/
	MESSAGE(Ev_NV_BLL_SetSysDataTime_Ntf)
	BODY(nv::TNVTime, tmttime )
	
	/*<<Ping�� ��������>>
	* ----------------------------------------------------------
	* ������pingtestparam    PING������Ϣ
	* ----------------------------------------------------------
	*���䷽��mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_NET_PingTestResult_Rsp
	*/
	MESSAGE(Ev_NV_BLL_NET_PingTest_Req)
	BODY(nv::TNVPingTestParam, pingtestparam )
	

	/*<<Ping�� ��Ӧ���>>
	* ----------------------------------------------------------
	* ������pingresult   PING�����Ϣ
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice->mtsdk
	* see Ev_MT_BLL_NET_PingTest_Req
	*/
	MESSAGE(Ev_NV_BLL_NET_PingTestResult_Rsp)
	BODY(nv::TNVPingResult, pingresult )
	
	/*<<��ȡ��ǰ����ʱ����Ϣ>>
	*BODY ��  tmttime ʱ����Ϣ  
	*���䷽��sdk->dispatch->nvservice
	*/
	MESSAGE(Ev_NV_BLL_GetSysDataTime_Req)
	
	/*<<��ȡ��ǰ����ʱ����Ϣ>>
	*BODY ��  tmttime ʱ����Ϣ  
	*���䷽��nvservice->dispatch->sdk
	*/
	MESSAGE(Ev_NV_BLL_GetSysDataTime_Rsp)
	BODY(nv::TU32, result)
	BODY(nv::TNVTime, tmttime )
	
	/*<<�򿪹ر�ftp>>
	*BODY ��  bopen true���򿪣�false�ر� 
	*���䷽��sdk->dispatch->nvservice
	*/
	MESSAGE(Ev_NV_BLL_OpenFtp_Cmd)
	BODY(nv::TBOOL32, bopen )

	/*<<�򿪹ر�ftp֪ͨ>>
	*BODY ��  bopen true���򿪣�false�ر� 
	*���䷽��nvservice->dispatch->sdk
	*/
	MESSAGE(Ev_NV_BLL_OpenFtp_Nty)
	BODY(nv::TBOOL32, bopen )

	/*<<ѯ��ftp״̬>>
	*
	*���䷽��sdk->dispatch->nvservice
	*/
	MESSAGE(Ev_NV_BLL_GetFtpState_Req)

	/*<<ѯ��ftp״̬��Ӧ>>
	*BODY ��  bopen true���򿪣�false�ر� 
	*���䷽��nvservice->dispatch->sdk
	*/
	MESSAGE(Ev_NV_BLL_GetFtpState_Rsp)
	BODY(nv::TBOOL32, bopen )
	
#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(NETWORK) = EVSEG_BLL_NETWORK_END
};
#endif

#define Is_BLL_Network_Msg(m) ((m) >= EV_BLL_BGN(NETWORK) && (m) <= EV_BLL_END(NETWORK))

#endif