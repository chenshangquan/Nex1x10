#ifndef _NVNETMSG_H_
#define _NVNETMSG_H_

#include "nvmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmNvNetMsg
{
    EV_BGN(NETMANAGE) = EVSEG_NETWORK_BGN,
#endif//_MESSAGE_HELP_

	
	/*<<设置当前日期时间信息>>
	*BODY ：  tnvtime 时间信息  
	*传输方向：nvservice==>dispatch==>nvterinterface
	*/
	MESSAGE(Ev_NV_SetSysDataTime_Req)
	BODY(nv::TNVTime, tnvtime )
	
	
	/*<<设置当前日期时间信息响应>>
	*BODY ：   result 设置结果 0成功 其他错误码
	           tnvtime 时间信息 
	*传输方向：nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_SetSysDataTimeResult_Rsp)
	BODY(nv::TU32, result)
	BODY(nv::TNVTime, tnvtime )


    /*<<设置当前日期时间通知>>
	*BODY ：   tnvtime 时间信息 
	*传输方向：nvterinterface ==>dispatch==>nvservice
	* see
	*/
	MESSAGE(Ev_NV_SetSysDataTime_Ntf)
	BODY(nv::TNVTime, tnvtime )
	
	/*<<设置指定接口Ethernet的网卡信息结果通知>>
	*BODY ：result  0成功  其他错误码
	        ethernetid  设置时指定的网口ID
	*传输方向：net->dispatch->nvservice
	* see Ev_NV_Ethernet_SetIpParam_Cmd
	*/
	MESSAGE(Ev_NV_Ethernet_SetIpParamResult_Ntf)
	BODY(nv::TU32, result)
	BODY(nv::TU32, ethernetid)

	/*<<设置指定接口Ethernet的网卡工作模式结果通知(全双工/半双工信息等)>>
	*BODY ：result  0成功  其他错误码
	        ethernetid  设置时指定的网口ID
	*传输方向：net->dispatch->nvservice
	* see Ev_NV_Ethernet_SetEthWorkModeListCfg_Cmd
	*/
	MESSAGE(Ev_NV_Ethernet_SetEthWorkModeListCfgResult_Ntf)
	BODY(nv::TU32, result)
	BODY(nv::TU32, ethernetid)
	
	/*<<启动指定接口Ethernet网卡结果通知>>
	*BODY ：result  0成功  其他错误码
	        ethernetid  设置时指定的网口ID
	*传输方向：net->dispatch->nvservice
	* see Ev_NV_Ethernet_StartUp_Cmd
	*/
	MESSAGE(Ev_NV_Ethernet_StartUpResult_Ntf)
	BODY(nv::TU32, result)
	BODY(nv::TU32, ethernetid)
	
	/*<<设置指定接口Ethernet的网卡信息>>
	*BODY ：ethernetid  指定网口ID
	        EmEthnetParamType 参数设置类型
	        TEthnetInterfaceParam  网口IP/mask/mac信息
	*传输方向：nvservice->dispatch->net
	* see Ev_NV_Ethernet_SetIpParamResult_Ntf
	*/
	MESSAGE(Ev_NV_Ethernet_SetIpParam_Cmd)
	BODY(nv::TU32, ethernetid)
	BODY(nv::TU32, EmEthnetParamType)
	BODY(nv::TEthnetInterfaceParam, TEthnetInterfaceParam)


	/*<<删除指定接口Ethernet 网卡信息>>
	*BODY ：ethernetid  指定网口ID
	        bDelAll  :是否删除该网卡所有的IP/MASK
	        TEthnetInterfaceParam  仅bDelAll为False时生效 要删除的(网口IP/mask/mac信息)
	*传输方向：nvservice->dispatch->net
	* see Ev_NV_Ethernet_DeleteIpParamResult_Ntf
	*/
	MESSAGE(Ev_NV_Ethernet_DeleteIpParam_Cmd)
	BODY(nv::TU32, ethernetid)
	BODY(nv::TBOOL32, bDelAll)
	BODY(nv::TEthnetInterfaceParam, TEthnetInterfaceParam)


	/*<<删除指定接口Ethernet 网卡信息结果通知>>
	*BODY ：result  0成功  其他错误码
	        ethernetid  设置时指定的网口ID
	*传输方向：net->dispatch->nvservice
	* see Ev_NV_Ethernet_DeleteIpParam_Cmd
	*/
	MESSAGE(Ev_NV_Ethernet_DeleteIpParamResult_Ntf)
	BODY(nv::TU32, result)
	BODY(nv::TU32, ethernetid)


	/*<<获取指定接口Ethernet 网卡首选IP/MASK信息>>
	*BODY ：ethernetid  指定网口ID
	*传输方向：nvservice->dispatch->net
	* see Ev_NV_Ethernet_GetPreferredIpParam_Rsp
	*/
	MESSAGE(Ev_NV_Ethernet_GetPreferredIpParam_Req)
	BODY(nv::TU32, ethernetid)


	/*<<获取指定接口Ethernet 网卡首选IP/MASK信息结果通知>>
	*BODY ：result  0成功  其他错误码
	        ethernetid  指定网口ID
	        TEthnetInterfaceParam  首选网口IP/mask/mac信息

	*传输方向：net->dispatch->nvservice
	* see Ev_NV_Ethernet_GetPreferredIpParam_Req
	*/
	MESSAGE(Ev_NV_Ethernet_GetPreferredIpParam_Rsp)
	BODY(nv::TU32, result)
	BODY(nv::TU32, ethernetid)
	BODY(nv::TEthnetInterfaceParam, TEthnetInterfaceParam)


	/*<<获取指定接口Ethernet 网卡所有IP/MASK信息>>
	*BODY ：ethernetid  指定网口ID
	*传输方向：nvservice->dispatch->net
	* see Ev_NV_Ethernet_GetAllIpParam_Rsp
	*/
	MESSAGE(Ev_NV_Ethernet_GetAllIpParam_Req)
	BODY(nv::TU32, ethernetid)


	/*<<获取指定接口Ethernet 网卡所有IP/MASK信息结果通知>>
	*BODY ：result  0成功  其他错误码
	        ethernetid  指定网口ID
	        TEthnetInterfaceParamList  一组的网口IP/mask/mac信息
	*传输方向：net->dispatch->nvservice
	* see Ev_NV_Ethernet_GetAllIpParam_Req
	*/
	MESSAGE(Ev_NV_Ethernet_GetAllIpParam_Rsp)
	BODY(nv::TU32, result)
	BODY(nv::TU32, ethernetid)
	BODY(nv::TEthnetInterfaceParamList, TEthnetInterfaceParamList)



	/*<<启动指定接口Ethernet网卡>>
	*BODY ：ethernetid  指定网口ID
	*传输方向：nvservice->dispatch->net
	* see Ev_NV_Ethernet_StartUpResult_Ntf
	*/
	MESSAGE(Ev_NV_Ethernet_StartUp_Cmd)
	BODY(nv::TU32, ethernetid)	



	/*<<停止指定接口Ethernet网卡>>
	*BODY ：ethernetid  指定网口ID
	*传输方向：nvservice->dispatch->net
	* see Ev_NV_Ethernet_ShutDownResult_Ntf
	*/
	MESSAGE(Ev_NV_Ethernet_ShutDown_Cmd)
	BODY(nv::TU32, ethernetid)



	/*<<停止指定接口Ethernet网卡结果通知>>
	*BODY ：result  0成功  其他错误码
	        ethernetid  设置时指定的网口ID
	*传输方向：net->dispatch->nvservice
	* see Ev_NV_Ethernet_ShutDown_Cmd
	*/
	MESSAGE(Ev_NV_Ethernet_ShutDownResult_Ntf)
	BODY(nv::TU32, result)
	BODY(nv::TU32, ethernetid)
	
	
	/*<<开始使用指定接口Ethernet网卡DHCP功能>>
	*BODY ：ethernetid  指定网口ID
	        bUsedDefaultGateway 使用该接口的网关为系统默认路由
	*传输方向：nvservice->dispatch->net
	* see  Ev_MT_Ethernet_DHCPLeaseInfo_Ntf
	*/
	MESSAGE(Ev_NV_Ethernet_StartDHCP_Cmd)
	BODY(nv::TU32, ethernetid)
	BODY(nv::TBOOL32, bUsedDefaultGateway)

 

	/*<<停止使用指定接口Ethernet网卡DHCP功能>>
	*BODY ：ethernetid  指定网口ID
	*传输方向：nvservice->dispatch->net
	* see  Ev_MT_Ethernet_DHCPLeaseInfo_Ntf
	*/
	MESSAGE(Ev_NV_Ethernet_StopDHCP_Cmd)
	BODY(nv::TU32, ethernetid)



	/*<<指定接口Ethernet网卡DHCP续约功能>>
	*BODY ：ethernetid  指定网口ID
	*传输方向：nvservice->dispatch->net
	* see  
	*/
	MESSAGE(Ev_NV_Ethernet_RenewDHCP_Cmd)
	BODY(nv::TU32, ethernetid)
 

	/*<<DNS 服务器配置功能>>
	*BODY ：TDNSParam  DNS参数，（注:DNS不是针对具体某个网卡来设置的）
	*传输方向：nvservice->dispatch->net
	* see  
	*/
	MESSAGE(Ev_NV_Ethernet_SetDns_Cmd)
	BODY(nv::TDNSParam, TDNSParam)



	/*<<DNS 服务器配置功能结果通知>>
	*BODY ：result  0成功  其他错误码
	*传输方向：net->dispatch->nvservice
	* see  
	*/
	MESSAGE(Ev_NV_Ethernet_SetDnsResult_Ntf)
	BODY(nv::TU32, result)



	/*<<查询指定接口Ethernet网卡的dhcp租约和状态信息>>
	*BODY ：ethernetid  指定网口ID
	*传输方向：nvservice->dispatch->net
	* see  
	*/
	MESSAGE(Ev_NV_Ethernet_GetDHCPLeaseInfo_Req)
	BODY(nv::TU32, ethernetid)


	/*<<查询指定接口Ethernet网卡的dhcp租约信息>>
	*BODY ： result  0成功   其他错误码
	         TDHCPStateInfo  DHCP状态信息
	         TDHCPLeaseInfo  DHCP租约信息
	*传输方向：net->dispatch->nvservice
	* see  
	*/
	MESSAGE(Ev_NV_Ethernet_GetDHCPLeaseInfo_Rsp)
	BODY(nv::TU32, result)
	BODY(nv::TDHCPStateInfo, TDHCPStateInfo)
	BODY(nv::TDHCPLeaseInfo, TDHCPLeaseInfo)


	/*<<Ethernet网卡的dhcp租约信息通知>>
	*BODY ： TDHCPStateInfo  DHCP状态信息
	         TDHCPLeaseInfo  DHCP租约信息
	         reason          异常时的原因
	*传输方向：net->dispatch->nvservice
	* see  
	*/
	MESSAGE(Ev_NV_Ethernet_DHCPLeaseInfo_Ntf)
	BODY(nv::TDHCPStateInfo, TDHCPStateInfo)
	BODY(nv::TDHCPLeaseInfo, TDHCPLeaseInfo)
	BODY(nv::TU32, reason)
	
	/*<<设置系统的默认网关请求>>
	*BODY ： ethernetid 网口id
	         gateway: 默认网关(网络序)
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_ROUTE_SetDefaultGatewayResult_Ntf
	*/
	MESSAGE(Ev_NV_ROUTE_SetDefaultGateway_Cmd)
	BODY(nv::TU32, ethernetid)
	BODY(nv::TU32, gateway )


	/*<<设置系统的默认网关请求结果通知>>
	*BODY ：   ethernetid 网口id
	           result: true成功  false失败
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_ROUTE_SetDefaultGateway_Cmd
	*/
	MESSAGE(Ev_NV_ROUTE_SetDefaultGatewayResult_Ntf)
	BODY(nv::TU32, ethernetid)
	BODY(nv::TBOOL32, result )



	/*<<查询系统的默认网关请求>>
	*BODY ：无
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_ROUTE_GetDefaultGateway_Rsp
	*/
	MESSAGE(Ev_NV_ROUTE_GetDefaultGateway_Req)


	/*<<查询系统的默认网关请求响应>>
	*BODY ：gatewayip: 网关IP,失败0
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_ROUTE_GetDefaultGateway_Req
	*/
	MESSAGE(Ev_NV_ROUTE_GetDefaultGateway_Rsp)
	BODY(nv::TU32, gatewayip )


	/*<<删除系统的默认网关请求>>
	*BODY ：无
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_ROUTE_DelDefaultGatewayResult_Ntf
	*/
	MESSAGE(Ev_NV_ROUTE_DelDefaultGateway_Cmd)


	/*<<删除系统的默认网关请求响应>>
	*BODY ：result: true:删除成功 false:删除失败
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_ROUTE_DelDefaultGateway_Cmd
	*/
	MESSAGE(Ev_NV_ROUTE_DelDefaultGatewayResult_Ntf)
	BODY(nv::TBOOL32, result )
	
	/*<<IP设置>>
	*BODY ：result: true:删除成功 false:删除失败
	*传输方向：net->dispatch->mtservice
	* see 
	*/
	MESSAGE(Ev_NV_SetIp_Ntf)
	BODY(nv::TNVNetUsedInfo, UsedInfo )
	/*<<IP设置>>
	*BODY ：result: true:删除成功 false:删除失败
	*传输方向：net->dispatch->mtservice
	* see 
	*/
	MESSAGE(Ev_NV_BLL_SetIp_Ntf)
	BODY(nv::TNVNetUsedInfo, UsedInfo )
	/*<<Ping包设置>>
	*BODY ：result: true:删除成功 false:删除失败
	*传输方向：net->dispatch->mtservice
	* see 
	*/
	MESSAGE(Ev_NV_SetPing_Req)
	/*<<Ping包设置>>
	*BODY ：result: true:删除成功 false:删除失败
	*传输方向：net->dispatch->mtservice
	* see 
	*/
	MESSAGE(Ev_NV_BLL_SetPing_Nty)
	/*<<Ping包通知>>
	*BODY ：result: true:删除成功 false:删除失败
	*传输方向：net->dispatch->mtservice
	* see 
	*/
	MESSAGE(Ev_NV_SetPing_Rsp)
	BODY(nv::TBOOL32, result )
	/*<<Ping包通知>>
	*BODY ：result: true:删除成功 false:删除失败
	*传输方向：net->dispatch->mtservice
	* see 
	*/
	MESSAGE(Ev_NV_BLL_SetPing_Rsp)
	BODY(nv::TBOOL32, result )

	/*<<出厂设置恢复通知>>
	*BODY ：result: true:删除成功 false:删除失败
	*传输方向：net->dispatch->mtservice
	* see 
	*/
	MESSAGE(Ev_NV_SetDefault_Nty)
	/*<<出厂设置恢复通知>>
	*BODY ：result: true:删除成功 false:删除失败
	*传输方向：net->dispatch->mtservice
	* see 
	*/
	MESSAGE(Ev_NV_BLL_SetDefault_Nty)
	
	/*<<获取当前日期时间信息>>
	*BODY ：  tmttime 时间信息  
	*传输方向：nvservice->dispatch->net
	*/
	MESSAGE(Ev_NV_GetSysDataTime_Req)
	
	/*<<获取当前日期时间信息>>
	*BODY ：  tmttime 时间信息  
	*传输方向：net->dispatch->nvservice
	*/
	MESSAGE(Ev_NV_GetSysDataTime_Rsp)
	BODY(nv::TU32, result)
	BODY(nv::TNVTime, tmttime )
	
#if !defined(_MESSAGE_HELP_)
    EV_END(NETMANAGE) = EVSEG_NETWORK_END
};
#endif//_MESSAGE_HELP_

#define Is_Net_Msg(m) ((m) >= EV_BGN(NETMANAGE) && (m) <= EV_END(NETMANAGE))

#endif//_NVNETMSG_H_