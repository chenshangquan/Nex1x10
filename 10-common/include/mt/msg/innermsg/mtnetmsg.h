#ifndef _MTNETMSG_H_
#define _MTNETMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMtNetMsg
{
    EV_BGN(NETMANAGE) = EVSEG_NETWORK_BGN,
#endif//_MESSAGE_HELP_

	/*<<设置指定接口Ethernet的网卡工作模式(全双工/半双工信息等)>>
	*BODY ：ethernetid  指定网口ID
	        EmEthnetWorkMode 工作模式
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_Ethernet_SetEthWorkModeListCfgResult_Ntf
	*/
	MESSAGE(Ev_MT_Ethernet_SetEthWorkModeListCfg_Cmd)
	BODY(mt::TU32, ethernetid)
	BODY(mt::TU32, EmEthnetWorkMode)
	
	/*<<设置指定接口Ethernet的网卡工作模式结果通知(全双工/半双工信息等)>>
	*BODY ：result  0成功  其他错误码
	        ethernetid  设置时指定的网口ID
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_Ethernet_SetEthWorkModeListCfg_Cmd
	*/
	MESSAGE(Ev_MT_Ethernet_SetEthWorkModeListCfgResult_Ntf)
	BODY(mt::TU32, result)
	BODY(mt::TU32, ethernetid)
	
	/*<<获取所有Ethernet的网卡工作模式 (全双工/半双工信息等)>>
	*BODY ：null
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_Ethernet_GetEthWorkModeListCfg_Rsp
	*/
	MESSAGE(Ev_MT_Ethernet_GetEthWorkModeListCfg_Req)

	
	/*<<获取所以Ethernet的网卡工作模式结果通知(全双工/半双工信息等)>>
	*BODY ：result  0成功  其他错误码
	        TEthnetWorkModeList 所有网卡工作模式列表信息
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_Ethernet_GetEthWorkModeListCfg_Req
	*/
	MESSAGE(Ev_MT_Ethernet_GetEthWorkModeListCfg_Rsp)
	BODY(mt::TEthnetWorkModeList, )
	
	
    
	/*<<设置指定接口Ethernet的网卡信息>>
	*BODY ：ethernetid  指定网口ID
	        EmEthnetParamType 参数设置类型
	        TEthnetInterfaceParam  网口IP/mask/mac信息
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_Ethernet_SetIpParamResult_Ntf
	*/
	MESSAGE(Ev_MT_Ethernet_SetIpParam_Cmd)
	BODY(mt::TU32, ethernetid)
	BODY(mt::TU32, EmEthnetParamType)
	BODY(mt::TEthnetInterfaceParam, TEthnetInterfaceParam)


	/*<<设置指定接口Ethernet的网卡信息结果通知>>
	*BODY ：result  0成功  其他错误码
	        ethernetid  设置时指定的网口ID
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_Ethernet_SetIpParam_Cmd
	*/
	MESSAGE(Ev_MT_Ethernet_SetIpParamResult_Ntf)
	BODY(mt::TU32, result)
	BODY(mt::TU32, ethernetid)


	/*<<删除指定接口Ethernet 网卡信息>>
	*BODY ：ethernetid  指定网口ID
	        bDelAll  :是否删除该网卡所有的IP/MASK
	        TEthnetInterfaceParam  仅bDelAll为False时生效 要删除的(网口IP/mask/mac信息)
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_Ethernet_DeleteIpParamResult_Ntf
	*/
	MESSAGE(Ev_MT_Ethernet_DeleteIpParam_Cmd)
	BODY(mt::TU32, ethernetid)
	BODY(mt::TBOOL32, bDelAll)
	BODY(mt::TEthnetInterfaceParam, TEthnetInterfaceParam)


	/*<<删除指定接口Ethernet 网卡信息结果通知>>
	*BODY ：result  0成功  其他错误码
	        ethernetid  设置时指定的网口ID
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_Ethernet_DeleteIpParam_Cmd
	*/
	MESSAGE(Ev_MT_Ethernet_DeleteIpParamResult_Ntf)
	BODY(mt::TU32, result)
	BODY(mt::TU32, ethernetid)


	/*<<获取指定接口Ethernet 网卡首选IP/MASK信息>>
	*BODY ：ethernetid  指定网口ID
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_Ethernet_GetPreferredIpParam_Rsp
	*/
	MESSAGE(Ev_MT_Ethernet_GetPreferredIpParam_Req)
	BODY(mt::TU32, ethernetid)


	/*<<获取指定接口Ethernet 网卡首选IP/MASK信息结果通知>>
	*BODY ：result  0成功  其他错误码
	        ethernetid  指定网口ID
	        TEthnetInterfaceParam  首选网口IP/mask/mac信息

	*传输方向：net->dispatch->mtservice
	* see Ev_MT_Ethernet_GetPreferredIpParam_Req
	*/
	MESSAGE(Ev_MT_Ethernet_GetPreferredIpParam_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TU32, ethernetid)
	BODY(mt::TEthnetInterfaceParam, TEthnetInterfaceParam)


	/*<<获取指定接口Ethernet 网卡所有IP/MASK信息>>
	*BODY ：ethernetid  指定网口ID
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_Ethernet_GetAllIpParam_Rsp
	*/
	MESSAGE(Ev_MT_Ethernet_GetAllIpParam_Req)
	BODY(mt::TU32, ethernetid)


	/*<<获取指定接口Ethernet 网卡所有IP/MASK信息结果通知>>
	*BODY ：result  0成功  其他错误码
	        ethernetid  指定网口ID
	        TEthnetInterfaceParamList  一组的网口IP/mask/mac信息
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_Ethernet_GetAllIpParam_Req
	*/
	MESSAGE(Ev_MT_Ethernet_GetAllIpParam_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TU32, ethernetid)
	BODY(mt::TEthnetInterfaceParamList, TEthnetInterfaceParamList)



	/*<<启动指定接口Ethernet网卡>>
	*BODY ：ethernetid  指定网口ID
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_Ethernet_StartUpResult_Ntf
	*/
	MESSAGE(Ev_MT_Ethernet_StartUp_Cmd)
	BODY(mt::TU32, ethernetid)



	/*<<启动指定接口Ethernet网卡结果通知>>
	*BODY ：result  0成功  其他错误码
	        ethernetid  设置时指定的网口ID
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_Ethernet_StartUp_Cmd
	*/
	MESSAGE(Ev_MT_Ethernet_StartUpResult_Ntf)
	BODY(mt::TU32, result)
	BODY(mt::TU32, ethernetid)



	/*<<停止指定接口Ethernet网卡>>
	*BODY ：ethernetid  指定网口ID
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_Ethernet_ShutDownResult_Ntf
	*/
	MESSAGE(Ev_MT_Ethernet_ShutDown_Cmd)
	BODY(mt::TU32, ethernetid)



	/*<<停止指定接口Ethernet网卡结果通知>>
	*BODY ：result  0成功  其他错误码
	        ethernetid  设置时指定的网口ID
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_Ethernet_ShutDown_Cmd
	*/
	MESSAGE(Ev_MT_Ethernet_ShutDownResult_Ntf)
	BODY(mt::TU32, result)
	BODY(mt::TU32, ethernetid)
 

	/*<<开始使用指定接口Ethernet网卡DHCP功能>>
	*BODY ：ethernetid  指定网口ID
	        bUsedDefaultGateway 使用该接口的网关为系统默认路由
	*传输方向：mtservice->dispatch->net
	* see  Ev_MT_Ethernet_DHCPLeaseInfo_Ntf
	*/
	MESSAGE(Ev_MT_Ethernet_StartDHCP_Cmd)
	BODY(mt::TU32, ethernetid)
	BODY(mt::TBOOL32, bUsedDefaultGateway)

 

	/*<<停止使用指定接口Ethernet网卡DHCP功能>>
	*BODY ：ethernetid  指定网口ID
	*传输方向：mtservice->dispatch->net
	* see  Ev_MT_Ethernet_DHCPLeaseInfo_Ntf
	*/
	MESSAGE(Ev_MT_Ethernet_StopDHCP_Cmd)
	BODY(mt::TU32, ethernetid)



	/*<<指定接口Ethernet网卡DHCP续约功能>>
	*BODY ：ethernetid  指定网口ID
	*传输方向：mtservice->dispatch->net
	* see  
	*/
	MESSAGE(Ev_MT_Ethernet_RenewDHCP_Cmd)
	BODY(mt::TU32, ethernetid)
 

	/*<<DNS 服务器配置功能>>
	*BODY ：TDNSParam  DNS参数，（注:DNS不是针对具体某个网卡来设置的）
	*传输方向：mtservice->dispatch->net
	* see  
	*/
	MESSAGE(Ev_MT_Ethernet_SetDns_Cmd)
	BODY(mt::TDNSParam, TDNSParam)



	/*<<DNS 服务器配置功能结果通知>>
	*BODY ：result  0成功  其他错误码
	*传输方向：net->dispatch->mtservice
	* see  
	*/
	MESSAGE(Ev_MT_Ethernet_SetDnsResult_Ntf)
	BODY(mt::TU32, result)



	/*<<查询指定接口Ethernet网卡的dhcp租约和状态信息>>
	*BODY ：ethernetid  指定网口ID
	*传输方向：mtservice->dispatch->net
	* see  
	*/
	MESSAGE(Ev_MT_Ethernet_GetDHCPLeaseInfo_Req)
	BODY(mt::TU32, ethernetid)


	/*<<查询指定接口Ethernet网卡的dhcp租约信息>>
	*BODY ： result  0成功   其他错误码
	         TDHCPStateInfo  DHCP状态信息
	         TDHCPLeaseInfo  DHCP租约信息
	*传输方向：net->dispatch->mtservice
	* see  
	*/
	MESSAGE(Ev_MT_Ethernet_GetDHCPLeaseInfo_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TDHCPStateInfo, TDHCPStateInfo)
	BODY(mt::TDHCPLeaseInfo, TDHCPLeaseInfo)


	/*<<Ethernet网卡的dhcp租约信息通知>>
	*BODY ： TDHCPStateInfo  DHCP状态信息
	         TDHCPLeaseInfo  DHCP租约信息
	         reason          异常时的原因
	*传输方向：net->dispatch->mtservice
	* see  
	*/
	MESSAGE(Ev_MT_Ethernet_DHCPLeaseInfo_Ntf)
	BODY(mt::TDHCPStateInfo, TDHCPStateInfo)
	BODY(mt::TDHCPLeaseInfo, TDHCPLeaseInfo)
	BODY(mt::TU32, reason)


	/*<<PPPoE 拨号连接请求>>
	*BODY ：TPPPoEConnectParam  pppoe连接参数
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_PPPoE_LinkState_Ntf
	*/
	MESSAGE(Ev_MT_PPPoE_Connect_Cmd)
	BODY(mt::TPPPoEConnectParam, TPPPoEConnectParam)


	/*<<PPPoE 断开请求>>
	*BODY ：ethernetid  指定网口ID
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_PPPoE_LinkState_Ntf
	*/
	MESSAGE(Ev_MT_PPPoE_DisConnect_Cmd)
	BODY(mt::TU32, ethernetid)


	/*<<PPPoE 连接状态查询>>
	*BODY ：ethernetid  指定网口ID
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_PPPoE_GetLinkState_Rsp
	*/
	MESSAGE(Ev_MT_PPPoE_GetLinkState_Req)
	BODY(mt::TU32, ethernetid)

	
	/*<<PPPoE 连接状态查询响应>>
	*BODY ：TPPPoEState  连接状态信息
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_PPPoE_GetLinkState_Req
	*/
	MESSAGE(Ev_MT_PPPoE_GetLinkState_Rsp)
	BODY(mt::TPPPoEState, TPPPoEState)


	/*<<PPPoE 连接状态通知>>
	*BODY ：TPPPoEState  连接状态信息
	*传输方向：net->dispatch->mtservice
	* see   Ev_MT_PPPoE_Connect_Cmd
	        Ev_MT_PPPoE_DisConnect_Cmd
	*/
	MESSAGE(Ev_MT_PPPoE_LinkState_Ntf)
	BODY(mt::TPPPoEState, TPPPoEState)



	/*<<PPPoE 连接后统计信息查询>>
	*BODY ：ethernetid  指定网口ID
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_PPPoE_GetStatisInfo_Rsp
	*/
	MESSAGE(Ev_MT_PPPoE_GetStatisInfo_Req)
	BODY(mt::TU32, ethernetid)

	
	/*<<PPPoE 连接后统计信息查询响应>>
	*BODY ：TPPPoEStatis  连接统计信息
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_PPPoE_GetStatisInfo_Req
	*/
	MESSAGE(Ev_MT_PPPoE_GetStatisInfo_Rsp)
	BODY(mt::TPPPoEStatis, TPPPoEStatis)



	/*<<PPPoE 版本信息查询>>
	*BODY ：无
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_PPPoE_GetVersion_Rsp
	*/
	MESSAGE(Ev_MT_PPPoE_GetVersion_Req)

	
	/*<<PPPoE 版本信息查询响应>>
	*BODY ：TPPPoEStatis  连接状态统计信息
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_PPPoE_GetVersion_Req
	*/
	MESSAGE(Ev_MT_PPPoE_GetVersion_Rsp)
	BODY(mt::TPPPoEVersion, TPPPoEVersion)


 	/*<<获取指定E1带宽请求>>
	*BODY ：EmE1InterfaceType E1 interface type
	        interfaceUnit 指定接口号，同mSerialId
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_E1_GetBandwidth_Rsp
	*/
	MESSAGE(Ev_MT_E1_GetBandwidth_Req)
	BODY(mt::TU32, EmE1InterfaceType )
	BODY(mt::TU32, interfaceUnit)

	
	/*<<获取指定E1带宽请求响应>>
	*BODY ：bandwidth_value 返回带宽值
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_E1_GetBandwidth_Req
	*/
	MESSAGE(Ev_MT_E1_GetBandwidth_Rsp)
	BODY(mt::TU32, bandwidth_value)

	/*<<E1带宽通知>>
	*BODY ：bandwidth
	*传输方向：net->dispatch->mtservice
	* see 
	*/
	MESSAGE(Ev_MT_E1_GetBandwidth_Ntf)
	BODY(mt::TU32, bandwidth)



	/*<<获取指定E1接口远端ip请求>>
	*BODY ：EmE1InterfaceType E1 interface type
	        interfaceUnit 指定接口号，同mSerialId
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_E1_GetRemoteIp_Rsp
	*/
	MESSAGE(Ev_MT_E1_GetRemoteIp_Req)
	BODY(mt::TU32, EmE1InterfaceType )
	BODY(mt::TU32, interfaceUnit)

	
	/*<<获取指定E1接口远端ip请求响应>>
	*BODY ：remoteip 返回远端IP（网络序）
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_E1_GetRemoteIp_Req
	*/
	MESSAGE(Ev_MT_E1_GetRemoteIp_Rsp)
	BODY(mt::TU32, remoteip)


	/*<<添加dce或者dte 请求>>
	*BODY ：e1: E1接口号
	        EmE1ClockType: clock类型 ("dce"或"dte")
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_E1_SetClockResult_Ntf
	*/
	MESSAGE(Ev_MT_E1_SetClock_Cmd)
	BODY(mt::TU32, e1 )
	BODY(mt::TU32, EmE1ClockType)


	/*<<添加dce或者dte 请求结果通知>>
	*BODY ：result: true成功 false失败
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_E1_SetClock_Cmd
	*/
	MESSAGE(Ev_MT_E1_SetClockResult_Ntf)
	BODY(mt::TBOOL32, result )



	/*<<创建一个E1单链路连接通道 请求>>
	*BODY ：chainId: 链路通道ID，范围[0~ 8) 该ID具有唯一性，用来标识每个单链路连接通道，不可冲突
	        TE1SingleChainInfo: 链路参数
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_E1_ChainOptResult_Ntf
	*/
	MESSAGE(Ev_MT_E1_OpenSingleChain_Cmd)
	BODY(mt::TU32, chainId )
	BODY(mt::TE1SingleChainInfo, TE1SingleChainInfo)


	/*<<关闭一个E1单链路连接通道 请求>>
	*BODY ：chainId: 链路通道ID
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_E1_ChainOptResult_Ntf
	*/
	MESSAGE(Ev_MT_E1_CloseSingleChain_Cmd)
	BODY(mt::TU32, chainId )



	/*<<创建一个E1多链路连接通道 请求>>
	*BODY ：chainId: 链路通道ID，范围[0~ 8) 该ID具有唯一性，用来标识每个单链路连接通道，不可冲突
	        TE1MultiChainInfo: 多链路参数
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_E1_ChainOptResult_Ntf
	*/
	MESSAGE(Ev_MT_E1_OpenMultiChain_Cmd)
	BODY(mt::TU32, chainId )
	BODY(mt::TE1MultiChainInfo, TE1MultiChainInfo)


	/*<<关闭一个E1多链路连接通道 请求>>
	*BODY ：chainId: 链路通道ID
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_E1_ChainOptResult_Ntf
	*/
	MESSAGE(Ev_MT_E1_CloseMultiChain_Cmd)
	BODY(mt::TU32, chainId )


	/*<<打开/关闭一个E1单链路或多链路请求时的结果通知>>
	*BODY ：EmE1ChainOptType :  链路通道请求类型
	        EmE1LinkErrReason:  打开或关闭结果
	*传输方向：net->dispatch->mtservice
	* see     Ev_MT_E1_OpenSingleChain_Cmd
	          Ev_MT_E1_CloseSingleChain_Cmd
	          Ev_MT_E1_OpenMultiChain_Cmd
	          Ev_MT_E1_CloseMultiChain_Cmd
	*/
	MESSAGE(Ev_MT_E1_ChainOptResult_Ntf)
	BODY(mt::TU32, EmE1ChainOptType )
	BODY(mt::TU32, EmE1LinkErrReason )

	
 
	/*<<设置系统的默认网关请求>>
	*BODY ： ethernetid 网口id
	         gateway: 默认网关(网络序)
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_ROUTE_SetDefaultGatewayResult_Ntf
	*/
	MESSAGE(Ev_MT_ROUTE_SetDefaultGateway_Cmd)
	BODY(mt::TU32, ethernetid)
	BODY(mt::TU32, gateway )


	/*<<设置系统的默认网关请求结果通知>>
	*BODY ：   ethernetid 网口id
	           result: true成功  false失败
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_ROUTE_SetDefaultGateway_Cmd
	*/
	MESSAGE(Ev_MT_ROUTE_SetDefaultGatewayResult_Ntf)
	BODY(mt::TU32, ethernetid)
	BODY(mt::TBOOL32, result )



	/*<<查询系统的默认网关请求>>
	*BODY ：无
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_ROUTE_GetDefaultGateway_Rsp
	*/
	MESSAGE(Ev_MT_ROUTE_GetDefaultGateway_Req)


	/*<<查询系统的默认网关请求响应>>
	*BODY ：gatewayip: 网关IP,失败0
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_ROUTE_GetDefaultGateway_Req
	*/
	MESSAGE(Ev_MT_ROUTE_GetDefaultGateway_Rsp)
	BODY(mt::TU32, gatewayip )


	/*<<删除系统的默认网关请求>>
	*BODY ：无
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_ROUTE_DelDefaultGatewayResult_Ntf
	*/
	MESSAGE(Ev_MT_ROUTE_DelDefaultGateway_Cmd)


	/*<<删除系统的默认网关请求响应>>
	*BODY ：result: true:删除成功 false:删除失败
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_ROUTE_DelDefaultGateway_Cmd
	*/
	MESSAGE(Ev_MT_ROUTE_DelDefaultGatewayResult_Ntf)
	BODY(mt::TBOOL32, result )



	/*<<新增一条路由请求>>
	*BODY ：TRouteItemInfo 新增路由信息
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_ROUTE_AddRouteResult_Rsp
	*/
	MESSAGE(Ev_MT_ROUTE_AddRoute_Req)
	BODY(mt::TRouteItemInfo, TRouteItemInfo )


	/*<<新增一条路由请求响应>>
	*BODY ：result: true:添加成功 false:添加失败
	TRouteItemInfo 添加的路由条目 
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_ROUTE_AddRoute_Req
	*/
	MESSAGE(Ev_MT_ROUTE_AddRouteResult_Rsp)
	BODY(mt::TBOOL32, result )
	BODY(mt::TRouteItemInfo, TRouteItemInfo )


	/*<<删除一条路由请求>>
	*BODY ：TRouteItemInfo 要删除的路由信息
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_ROUTE_DelRouteResult_Rsp
	*/
	MESSAGE(Ev_MT_ROUTE_DelRoute_Req)
	BODY(mt::TRouteItemInfo, TRouteItemInfo )

 
	/*<<删除一条路由请求响应>>
	*BODY ：result: true:删除成功 false:删除失败
	        TRouteItemInfo 被删除的路由条目
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_ROUTE_DelRoute_Req
	*/
	MESSAGE(Ev_MT_ROUTE_DelRouteResult_Rsp)
	BODY(mt::TBOOL32, result )
	BODY(mt::TRouteItemInfo, TRouteItemInfo )


	/*<<修改一条路由信息请求>>
	*BODY ：oldRouteItemInfo 被修前的路由信息
	        newRouteItemInfo 修改后的路由信息 
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_ROUTE_ModifyRouteResult_Rsp
	*/
	MESSAGE(Ev_MT_ROUTE_ModifyRoute_Req)
	BODY(mt::TRouteItemInfo, oldRouteItemInfo )
	BODY(mt::TRouteItemInfo, newRouteItemInfo )

 
	/*<<修改一条路由信息请求响应>>
	*BODY ：result: true:删除成功 false:删除失败
	*       oldRouteItemInfo 被修前的路由信息
	        newRouteItemInfo 修改后的路由信息 
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_ROUTE_ModifyRoute_Req
	*/
	MESSAGE(Ev_MT_ROUTE_ModifyRouteResult_Rsp)
	BODY(mt::TBOOL32, result )
	BODY(mt::TRouteItemInfo, oldRouteItemInfo )
	BODY(mt::TRouteItemInfo, newRouteItemInfo )
	
	
	/*<<获取默认路由请求>>
	*BODY ：无
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_ROUTE_GetDefaultRoute_Req
	*/
	MESSAGE(Ev_MT_ROUTE_GetDefaultRoute_Req)

 
	/*<<获取默认路由响应>>
	*BODY ：TRouteItemInfo 路由信息
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_ROUTE_GetDefaultRoute_Rsp
	*/
	MESSAGE(Ev_MT_ROUTE_GetDefaultRoute_Rsp)
	BODY(mt::TRouteItemInfo, TRouteItemInfo )

	/*<<获取所有路由请求>>
	*BODY ：无
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_ROUTE_GetAllRoute_Rsp
	*/
	MESSAGE(Ev_MT_ROUTE_GetAllRoute_Req)

 
	/*<<获取所有路由请求响应>>
	*BODY ：TRouteItemInfoList 路由列表信息
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_ROUTE_GetAllRoute_Req
	*/
	MESSAGE(Ev_MT_ROUTE_GetAllRoute_Rsp)
	BODY(mt::TRouteItemInfoList, TRouteItemInfoList )



	/*<<PING测试请求>>
	*BODY ：TPingTestParam PING参数信息
	*传输方向：service->dispatch->net
	* see Ev_MT_PING_PingTestResult_Rsp
	*/
	MESSAGE(Ev_MT_PING_PingTest_Req)
	BODY(mt::TPingTestParam, TPingTestParam )
	


	/*<<PING测试请求结果通知>>
	*BODY ：TPingResult  PING结果信息
	*传输方向：net->dispatch->service
	* see Ev_MT_PING_PingTest_Req
	*/
	MESSAGE(Ev_MT_PING_PingTestResult_Rsp)
	BODY(mt::TPingResult, TPingResult )


	/*<<ip mac冲突通知>>
	*BODY ：TNetConfilictedInfo  冲突信息
	*传输方向：net->dispatch->service
	* see 
	*/
	MESSAGE(Ev_MT_NET_IPMACConfilicted_Ntf)
	BODY(mt::TNetConfilictedInfo, TNetConfilictedInfo )
	
 
	 
 	/*<<Wifi 工作模式控制>>
	*BODY ：TWifiWorkMode
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_WIFI_ChangeWorkMode_Ntf
	*/
	MESSAGE(Ev_MT_WIFI_ChangeWorkMode_Cmd)
	BODY(mt::TWifiWorkMode, TWifiWorkMode)
	
	/*<<Wifi 工作模式状态通知>>
	* ----------------------------------------------------------
	*BODY：result: 设置结果信息
	*BODY：TWifiWorkMode：	当前Wifi工作模式
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_WIFI_ChangeWorkMode_Cmd
	*/
	MESSAGE(Ev_MT_WIFI_ChangeWorkMode_Ntf)
	BODY(mt::TWifiWorkMode, TWifiWorkMode)
	BODY(mt::TBOOL32, result)	
	
	/*<<Wifi 工作模式信息查询>>
	*BODY ：无
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_WIFI_GetWorkMode_Rsp
	*/
	MESSAGE(Ev_MT_WIFI_GetWorkMode_Req)

	
	/*<<Wifi 工作模式信息响应>>
	* ----------------------------------------------------------
	* 参数：：TWifiWorkMode：	当前Wifi工作模式
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_WIFI_GetWorkMode_Req
	*/
	MESSAGE(Ev_MT_WIFI_GetWorkMode_Rsp)
	BODY(mt::TWifiWorkMode, TWifiWorkMode)
	

	/*<<Wifi 热点扫描请求>>
	*BODY ：无
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_WIFI_ScanResult_Rsp
	*/
	MESSAGE(Ev_MT_WIFI_StartScan_Req)


	/*<<Wifi 热点扫描结果通知>>
	* ----------------------------------------------------------
	* 参数：TWifiScanResultList：	扫描到候选WIFI结果列表
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_WIFI_StartScan_Req
	*/
	MESSAGE(Ev_MT_WIFI_ScanResult_Rsp)
	BODY(mt::TWifiScanResultList, TWifiScanResultList)


	/*<<Wifi 热点连接请求>>
	* ----------------------------------------------------------
	* 参数：TWifiConnParam：	wifi网络连接参数
	* ----------------------------------------------------------
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_WIFI_LinkState_Ntf	      
	*/
	MESSAGE(Ev_MT_WIFI_Connect_Cmd)
	BODY(mt::TWifiConnParam, TWifiConnParam)
	
	
	/*<<Wifi 热点断开请求>>
	* ----------------------------------------------------------
	* 参数：无：	断开当前连接
	* ----------------------------------------------------------
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_WIFI_LinkState_Ntf	      
	*/
	MESSAGE(Ev_MT_WIFI_DisConnect_Cmd)
 
 
    /*<<Wifi 忘记网络请求>>
	* ----------------------------------------------------------
	* 参数：TU32：	wifi热点id
	* ----------------------------------------------------------
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_WIFI_Forget_Rsp	      
	*/
	MESSAGE(Ev_MT_WIFI_Forget_Req)
	BODY(mt::TU32, hotspotId)

     /*<<Wifi 忘记网络响应>>
	* ----------------------------------------------------------
	* 参数：TBOOL32：	设置结果
	* 参数：TU32：		wifi热点id
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_WIFI_Forget_Req	      
	*/
	MESSAGE(Ev_MT_WIFI_Forget_Rsp)
    BODY(mt::TBOOL32, result)
	BODY(mt::TU32, hotspotId)
	
	/*<<Wifi 连接状态查询>>
	*BODY ：无
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_WIFI_LinkState_Rsp
	*/
	MESSAGE(Ev_MT_WIFI_GetLinkState_Req)
	
	
	/*<<Wifi 连接状态查询通知>>
	* ----------------------------------------------------------
	* 参数：TWifiCurDetailInfo：	Wifi网络连接状态信息
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_WIFI_GetLinkState_Req
	*/
	MESSAGE(Ev_MT_WIFI_LinkState_Rsp)
	BODY(mt::TWifiCurDetailInfo, TWifiCurDetailInfo)
	
	
	/*<<Wifi 连接结果状态通知>>
	* ----------------------------------------------------------
	* 参数：TWifiCurDetailInfo：	Wifi网络连接结果信息
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_WIFI_Connect_Cmd
	      Ev_MT_WIFI_DisConnect_Cmd 
	*/
	MESSAGE(Ev_MT_WIFI_LinkState_Ntf)
	BODY(mt::TWifiCurDetailInfo, TWifiCurDetailInfo)
	
	
	/*<<Wifi 当前连接的Wifi客户端属性请求>>
	* ----------------------------------------------------------
	* 参数：TWifiConfiguration:    Wifi连接的客户端属性信息 
	* ----------------------------------------------------------
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_WIFI_ModClientProperty_Ntf
	*/
	MESSAGE(Ev_MT_WIFI_ModClientProperty_Cmd)
	BODY(mt::TWifiConfiguration, TWifiConfiguration)
  
  
  	/*<<Wifi 当前连接的Wifi客户端属性修改结果通知>>
	* ----------------------------------------------------------
	* 参数：TBOOL32:               修改结果                 
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_WIFI_ModClientProperty_Cmd
	*/
	MESSAGE(Ev_MT_WIFI_ModClientProperty_Ntf)
	BODY(mt::TBOOL32, )
	BODY(mt::TWifiConfiguration, TWifiConfiguration)
	
	
	/*<<Wifi 获取当前连接的Wifi客户端属性请求>>
	* ----------------------------------------------------------
	* 参数：无 
	* ----------------------------------------------------------
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_WIFI_GetModClientProperty_Rsp
	*/
	MESSAGE(Ev_MT_WIFI_GetModClientProperty_Req)
	
	
	/*<<Wifi 获取当前连接的Wifi客户端属性请求通知>>
	* ----------------------------------------------------------
	* 参数：TWifiConfiguration:    Wifi连接的客户端属性信息 
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_WIFI_ModClientProperty_Cmd
	*/
	MESSAGE(Ev_MT_WIFI_GetModClientProperty_Rsp)
	BODY(mt::TWifiConfiguration, TWifiConfiguration)
	
	
	/*<<Wifi 获取当前连接的Wifi客户端详细信息请求>>
	* ----------------------------------------------------------
	* 参数：无 
	* ----------------------------------------------------------
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_WIFI_GetWifiCurConnectedInfo_Rsp
	*/
	MESSAGE(Ev_MT_WIFI_GetWifiCurConnectedInfo_Req)
	
	
	/*<<Wifi 获取当前连接的Wifi客户端详细信息请求通知>>
	* ----------------------------------------------------------
	* 参数：TWifiCurDetailInfo:    Wifi连接的客户端详细信息 
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_WIFI_GetWifiCurConnectedInfo_Req
	*/
	MESSAGE(Ev_MT_WIFI_GetWifiCurConnectedInfo_Rsp)
	BODY(mt::TWifiConfiguration, TWifiConfiguration)
	
	
	/*<<Wifi 当前连接的Wifi统计信息查询请求>>
	* ----------------------------------------------------------
	* 参数：无
	* ----------------------------------------------------------
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_WIFI_GetCurWifiStatisInfo_Rsp
	*/
	MESSAGE(Ev_MT_WIFI_GetCurWifiStatisInfo_Req)
 
	
	/*<<Wifi 当前连接的Wifi统计信息查询响应>>
	* ----------------------------------------------------------
	* 参数：TWifiStatisInfo：	当前Wifi的统计信息 含信号强度，上下行总带宽
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_WIFI_GetCurWifiStatisInfo_Req
	*/
	MESSAGE(Ev_MT_WIFI_GetCurWifiStatisInfo_Rsp)
	BODY(mt::TWifiStatisInfo, TWifiStatisInfo)
	
	/*<<获取无线投屏信息请求>>
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_WIFI_GetWirelessScreen_Rsp
	*/
	MESSAGE(Ev_MT_WIFI_GetWirelessScreen_Req)

	/*<<获取无线投屏信息响应>>
	*BODY ：TWifiWirelessScreenInfo  无线投屏信息
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_WIFI_GetWirelessScreen_Req
	*/
	MESSAGE(Ev_MT_WIFI_GetWirelessScreen_Rsp)
	BODY(mt::TWifiWirelessScreenInfo, TWifiWirelessScreenInfo)

	/*<<开启或停止无线投屏命令>>
    *BODY ：bStart  true:启动  false:停止
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_WIFI_WirelessScreenStateChange_Ntf
	*/
	MESSAGE(Ev_MT_WIFI_SetWirelessScreen_Cmd)
    BODY(mt::TBOOL32, bStart)

	/*<<无线投屏状态改变通知>>
    *BODY ：TWifiWirelessScreenInfo  无线投屏信息
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_WIFI_SetWirelessScreen_Cmd
	*/
	MESSAGE(Ev_MT_WIFI_WirelessScreenStateChange_Ntf)
	BODY(mt::TWifiWirelessScreenInfo, TWifiWirelessScreenInfo)
	
	/*<<MobileData 工作模式设置>>
	*BODY ：TMobileDataWorkMode
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_MOBILEDATA_ChangeWorkMode_Ntf
	      Ev_MT_MOBILEDATA_LinkState_Ntf   
	*/
	MESSAGE(Ev_MT_MOBILEDATA_ChangeWorkMode_Cmd)
	BODY(mt::TMobileDataWorkMode, TMobileDataWorkMode)
	
	
	/*<<MobileData 工作模式设置结果通知>>
	* ----------------------------------------------------------
	* 参数：：TBOOL32:   设置结果          
	          TWifiWorkMode：	当前Wifi工作模式
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_MOBILEDATA_ChangeWorkMode_Cmd
	*/
	MESSAGE(Ev_MT_MOBILEDATA_ChangeWorkMode_Ntf)
	BODY(mt::TBOOL32, )
	BODY(mt::TMobileDataWorkMode, TMobileDataWorkMode)
	
	
	/*<<MobileData 工作模式信息查询>>
	*BODY ：无
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_MOBILEDATA_GetWorkMode_Rsp
	*/
	MESSAGE(Ev_MT_MOBILEDATA_GetWorkMode_Req)

	
	/*<<MobileData  工作模式信息查询响应>>
	* ----------------------------------------------------------
	* 参数：：TWifiWorkMode：	当前Wifi工作模式
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_MOBILEDATA_GetWorkMode_Req
	*/
	MESSAGE(Ev_MT_MOBILEDATA_GetWorkMode_Rsp)
	BODY(mt::TMobileDataWorkMode, TMobileDataWorkMode)
	
	
	
	/*<<MobileData  移动数据连接后详细状态通知>>
	* ----------------------------------------------------------
	* 参数：：TMobileDataCurDetailInfo：	当前移动数据的详细信息
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_MOBILEDATA_ChangeWorkMode_Cmd
	*/
	MESSAGE(Ev_MT_MOBILEDATA_LinkState_Ntf)
	BODY(mt::TMobileDataCurDetailInfo, TMobileDataCurDetailInfo)
	
	
	
	/*<<MobileData 查询移动数据连接后详细消息>>
	*BODY ：无
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_MOBILEDATA_GetDetailInfo_Rsp
	*/
	MESSAGE(Ev_MT_MOBILEDATA_GetDetailInfo_Req)

	
	/*<<MobileData  移动数据连接后详细消息响应>>
	* ----------------------------------------------------------
	* 参数：：TMobileDataCurDetailInfo：	当前移动数据的详细信息
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_MOBILEDATA_GetDetailInfo_Req
	*/
	MESSAGE(Ev_MT_MOBILEDATA_GetDetailInfo_Rsp)
	BODY(mt::TMobileDataCurDetailInfo, TMobileDataCurDetailInfo)
	
	
	
	/*<<MobileData 当前连接的移动数据统计信息查询请求>>
	* ----------------------------------------------------------
	* 参数：无
	* ----------------------------------------------------------
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_MOBILEDATA_GetCurStatisInfo_Rsp
	*/
	MESSAGE(Ev_MT_MOBILEDATA_GetCurStatisInfo_Req)
 
	
	/*<<MobileData 当前连接的移动数据统计信息查询响应>>
	* ----------------------------------------------------------
	* 参数：TMobileDataStatisInfo：	当前Wifi的统计信息 含信号强度，上下行总带宽
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_MOBILEDATA_GetCurStatisInfo_Req
	*/
	MESSAGE(Ev_MT_MOBILEDATA_GetCurStatisInfo_Rsp)
	BODY(mt::TMobileDataStatisInfo, TMobileDataStatisInfo)
	
	
	
	/*<<查询DNS对应的IP信息请求>>
	* ----------------------------------------------------------
	* 参数：TDNSNameToIpInfo 要查询的DNS信息
	* ----------------------------------------------------------
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_Ethernet_GetIpByDNSInfo_Rsp
	*/
	MESSAGE(Ev_MT_Ethernet_GetIpByDNSInfo_Req)
	BODY(mt::TDNSNameToIpInfo, TDNSNameToIpInfo)
 
	
	/*<<查询DNS对应的IP信息请求响应>>
	* ----------------------------------------------------------
	* 参数：TDNSNameToIpResult：	DNS查询到的IP结果信息
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_Ethernet_GetIpByDNSInfo_Req
	*/
	MESSAGE(Ev_MT_Ethernet_GetIpByDNSInfo_Rsp)
	BODY(mt::TDNSNameToIpResult, TDNSNameToIpResult)
	
	
	
	/*<<查询指定接口Ethernet 网卡连接状态>>
	*BODY ：ethernetid  指定网口ID
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_Ethernet_GetLinkState_Rsp
	*/
	MESSAGE(Ev_MT_Ethernet_GetLinkState_Req)
	BODY(mt::TU32, ethernetid)


	/*<<查询指定接口Ethernet 网卡连接状态结果响应>>
	*BODY ：result  0成功  其他错误码
	        ethernetid  指定网口ID
	        bOn  true:插入  false:断开

	*传输方向：net->dispatch->mtservice
	* see Ev_MT_Ethernet_GetLinkState_Req
	*/
	MESSAGE(Ev_MT_Ethernet_GetLinkState_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TU32, ethernetid)
	BODY(mt::TBOOL32, bOn )
	
	
	/*<<Ethernet 网卡连接状态改变通知>>
	*BODY ：ethernetid  改变的网口ID
	        bOn  true:插入  false:断开

	*传输方向：net->dispatch->mtservice
	* see 
	*/
	MESSAGE(Ev_MT_Ethernet_LinkState_Ntf)
	BODY(mt::TU32, ethernetid)
	BODY(mt::TBOOL32, bOn )
	

	/*<<查找网络服务模块是否是否已经启动>>
	*BODY ：    
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_NetServiceStarted_Rsp
	*/
	MESSAGE(Ev_MT_NetServiceStarted_Req)
	
	
	/*<<查询网络服务模块启动状态>>
	*BODY ：bOn  true:启动完成  false:尚未启动完成
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_NetServiceStarted_Req
	*/
	MESSAGE(Ev_MT_NetServiceStarted_Rsp)
	BODY(mt::TBOOL32, bStarted )
	
	
	/*<<网络服务模块启动完成通知>>
	*BODY ：bOn  true:启动完成  false:尚未启动完成
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_NetServiceStarted_Req
	      Ev_MT_NetServiceStarted_Rsp
	*/
	MESSAGE(Ev_MT_NetServiceStarted_Ntf)
	BODY(mt::TBOOL32, bStarted )
	
	
	/*<<设置当前日期时间信息>>
	*BODY ：  TMTTime 时间信息  
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_SetSysDataTimeResult_Rsp
	*/
	MESSAGE(Ev_MT_SetSysDataTime_Req)
	BODY(mt::TMTTime, TMTTime )
	
	
	/*<<设置当前日期时间信息响应>>
	*BODY ：   result 设置结果 0成功 其他错误码
	           TMTTime 时间信息 
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_SetSysDataTime_Cmd
	*/
	MESSAGE(Ev_MT_SetSysDataTimeResult_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTTime, TMTTime )
	
	
	/*<<查询当前日期时间信息>>
	*BODY ：    
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_GetSysDataTime_Rsp
	*/
	MESSAGE(Ev_MT_GetSysDataTime_Req)
	
	
	/*<<查询当前日期时间信息响应>>
	*BODY ：result 获取结果 0成功 其他错误码
	        TMTTime  时间信息
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_GetSysDataTime_Req
	*/
	MESSAGE(Ev_MT_GetSysDataTime_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTTime, TMTTime )


	/*<<设置NTP服务开启关闭状态>>
	*BODY ：  TMTNTPInfo NTP服务开启状态 
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_SetNTPSvrParamResult_Rsp
	*/
	MESSAGE(Ev_MT_SetNTPSvrParam_Req)
	BODY(mt::TMTNTPInfo, TMTNTPInfo )
	
	
	/*<<设置NTP服务开启关闭状态响应>>
	*BODY ：   result 设置结果 0成功 其他错误码
	           TMTNTPInfo NTP参数信息 
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_SetNTPSvrParam_Req
	*/
	MESSAGE(Ev_MT_SetNTPSvrParamResult_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTNTPInfo, TMTNTPInfo )
	
	
	/*<<查询当前NTP服务开启状态请求>>
	*BODY ：    
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_GetNTPSvrParam_Rsp
	*/
	MESSAGE(Ev_MT_GetNTPSvrParam_Req)
	
	
	/*<<查询当前NTP服务开启状态响应>>
	*BODY ：result 获取结果 0成功 其他错误码
	        TMTNTPInfo NTP参数信息 
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_GetNTPSvrParam_Req
	*/
	MESSAGE(Ev_MT_GetNTPSvrParam_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTNTPInfo, TMTNTPInfo )
	


	/*<<Telnet服务开启/停止请求>>
	*BODY ：  bStart  true:启动  false:停止  
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_Net_TelnetService_Ntf
	*/
	MESSAGE(Ev_MT_Net_TelnetService_Cmd)
	BODY(mt::TBOOL32, bStart )
	
	
	/*<<Telnet服务开启/停止状态通知>>
	*BODY ：reason    0:成功, 1,启动失败，2,停止失败, 其他错误码
	        bStarted  当前状态 true:启动状态  false:停止状态  
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_Net_TelnetService_Cmd
	*/
	MESSAGE(Ev_MT_Net_TelnetService_Ntf)
	BODY(mt::TU32, reason)
	BODY(mt::TBOOL32, bStarted )

	
	/*<<Ftp服务开启/停止请求>>
	*BODY ：  bStart  true:启动  false:停止  
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_Net_FtpService_Ntf
	*/
	MESSAGE(Ev_MT_Net_FtpService_Cmd)
	BODY(mt::TBOOL32, bStart )
	
	
	/*<<Ftp服务开启/停止状态通知>>
	*BODY ：reason    0:成功, 1,启动失败，2,停止失败, 其他错误码
	        bStarted  当前状态 true:启动状态  false:停止状态  
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_Net_FtpService_Cmd
	*/
	MESSAGE(Ev_MT_Net_FtpService_Ntf)
	BODY(mt::TU32, reason)
	BODY(mt::TBOOL32, bStarted )

	
	/*<<Http服务开启/停止请求>>
	*BODY ：  bStart  true:启动  false:停止  
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_Net_HttpService_Ntf
	*/
	MESSAGE(Ev_MT_Net_HttpService_Cmd)
	BODY(mt::TBOOL32, bStart )
	
	
	/*<<Http服务开启/停止状态通知>>
	*BODY ：reason    0:成功, 1,启动失败，2,停止失败, 其他错误码
	        bStarted  当前状态 true:启动状态  false:停止状态  
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_Net_HttpService_Cmd
	*/
	MESSAGE(Ev_MT_Net_HttpService_Ntf)
	BODY(mt::TU32, reason)
	BODY(mt::TBOOL32, bStarted )



	/*<<设置TimeZone信息>>
	*BODY ：  TMTTimeZoneInfo 时区信息 
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_SetTimeZone_Rsp
	*/
	MESSAGE(Ev_MT_SetTimeZone_Req)
	BODY(mt::TMTTimeZoneInfo, TMTTimeZoneInfo )
	
	
	/*<<设置TimeZone信息响应>>
	*BODY ：   result 设置结果 0成功 其他错误码
	           TMTTimeZoneInfo 时区信息 
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_SetTimeZone_Req
	*/
	MESSAGE(Ev_MT_SetTimeZone_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTTimeZoneInfo, TMTTimeZoneInfo )
	
	
	/*<<查询当前TimeZone信息请求>>
	*BODY ：    
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_GetTimeZone_Rsp
	*/
	MESSAGE(Ev_MT_GetTimeZone_Req)
	
	
	/*<<查询当前TimeZone信息响应>>
	*BODY ：result 获取结果 0成功 其他错误码
	        TMTTimeZoneInfo 时区信息  
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_GetTimeZone_Req
	*/
	MESSAGE(Ev_MT_GetTimeZone_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTTimeZoneInfo, TMTTimeZoneInfo )



	/*<<设置Ftp/Telnet账号信息>>
	*BODY ：  TMTFtpTelnetAccountInfo 账号信息 
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_SetFtpTelnetAccountInfo_Rsp
	*/
	MESSAGE(Ev_MT_SetFtpTelnetAccountInfo_Req)
	BODY(mt::TMTFtpTelnetAccountInfo, TMTFtpTelnetAccountInfo )
	
	
	/*<<设置Ftp/Telnet账号信息响应>>
	*BODY ：   result 设置结果 0成功 其他错误码
	           TMTFtpTelnetAccountInfo 账号信息 
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_SetFtpTelnetAccountInfo_Req
	*/
	MESSAGE(Ev_MT_SetFtpTelnetAccountInfo_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTFtpTelnetAccountInfo, TMTFtpTelnetAccountInfo )

    /*<<获取E1所有路由请求>>
	*BODY ：无
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_ROUTE_GetE1AllRoute_Rsp
	*/
	MESSAGE(Ev_MT_ROUTE_GetE1AllRoute_Req)

 
	/*<<获取E1所有路由请求响应>>
	*BODY ：TE1RouteItemInfoList 路由列表信息
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_ROUTE_GetE1AllRoute_Req
	*/
	MESSAGE(Ev_MT_ROUTE_GetE1AllRoute_Rsp)
	BODY(mt::TE1RouteItemInfoList, TE1RouteItemInfoList )

    /*<<查询当前E1链路信息>>
    *BODY ：E1GroupId E1分组ID:0,1,2,3; 当值取4时，则获取全部分组
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_GetE1LinkInfo_Rsp
	*/
	MESSAGE(Ev_MT_GetE1LinkInfo_Req)
    BODY(mt::TU32, E1GroupId)

    /*<<查询当前E1链路信息响应>>
	*BODY ：result 获取结果 0联通 1断链
    *BODY ：E1GroupId E1分组ID:0,1,2,3; 当值取4时，则获取全部分组
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_GetE1LinkInfo_Rsp
	*/
	MESSAGE(Ev_MT_GetE1LinkInfo_Rsp)
    BODY(mt::TU32, E1GroupId)
	BODY(mt::TU32, result)

    /*<<E1链路信息通知>>
    *BODY ：result 获取结果 0联通 1断链
    *BODY ：E1GroupId E1分组ID:0,1,2,3; 当值取4时，则获取全部分组
    *传输方向：net->dispatch->mtservice
    * see Ev_MT_GetE1LinkInfo_Req
    */
	MESSAGE(Ev_MT_Net_E1LinkInfo_Ntf)
	BODY(mt::TU32, result)

    /*<<终端类型通知>>
    *传输方向：mtservice->dispatch->net
    * see Ev_MT_SetTerlModel_Cmd
    */
	MESSAGE(Ev_MT_SetTerlModel_Cmd)
	BODY(mt::TU32, terlmodel)

	/*<<新增一条限定ip段请求>>
	*BODY ：TLimitedIpItemInfo 新增限定IP段信息
    *传输方向：mtservice->dispatch->net
    * see Ev_MT_Net_AddLimitedIpResult_Rsp
    */
	MESSAGE(Ev_MT_Net_AddLimitedIp_Req)
	BODY(mt::TLimitedIpItemInfo, TLimitedIpItemInfo)

	/*<<新增一条限定ip段响应>>
	*BODY ：result: true:添加成功 false:添加失败
	*BODY ：TLimitedIpItemInfo 新增限定IP段信息
    *传输方向：net->dispatch->mtservice
    * see Ev_MT_Net_AddLimitedIp_Req
    */
	MESSAGE(Ev_MT_Net_AddLimitedIpResult_Rsp)
	BODY(mt::TBOOL32, result)
	BODY(mt::TLimitedIpItemInfo, TLimitedIpItemInfo)

	/*<<删除一条限定ip段请求>>
	*BODY ：TLimitedIpItemInfo 要删除的限定IP段信息
    *传输方向：mtservice->dispatch->net
    * see Ev_MT_Net_DelLimitedIpResult_Rsp
    */
	MESSAGE(Ev_MT_Net_DelLimitedIp_Req)
	BODY(mt::TLimitedIpItemInfo, TLimitedIpItemInfo)

	/*<<删除一条限定ip段响应>>
	*BODY ：result: true:删除成功 false:删除失败
	*BODY ：TLimitedIpItemInfo 要删除的限定IP段信息
    *传输方向：net->dispatch->mtservice
    * see Ev_MT_Net_DelLimitedIp_Req
    */
	MESSAGE(Ev_MT_Net_DelLimitedIpResult_Rsp)
	BODY(mt::TBOOL32, result)
	BODY(mt::TLimitedIpItemInfo, TLimitedIpItemInfo)

	/*<<修改一条限定ip段请求>>
	*BODY ：oldLimitedIpItemInfo 修改前的限定IP段信息
	*BODY ：newLimitedIpItemInfo 修改后的限定IP段信息
    *传输方向：mtservice->dispatch->net
    * see Ev_MT_Net_ModLimitedIpResult_Rsp
    */
	MESSAGE(Ev_MT_Net_ModLimitedIp_Req)
	BODY(mt::TLimitedIpItemInfo, oldLimitedIpItemInfo)
	BODY(mt::TLimitedIpItemInfo, newLimitedIpItemInfo)

	/*<<修改一条限定ip段响应>>
	*BODY ：result: true:修改成功 false:修改失败
	*BODY ：oldLimitedIpItemInfo 修改前的限定IP段信息
	*BODY ：newLimitedIpItemInfo 修改后的限定IP段信息
    *传输方向：net->dispatch->mtservice
    * see Ev_MT_Net_ModLimitedIp_Req
    */
	MESSAGE(Ev_MT_Net_ModLimitedIpResult_Rsp)
	BODY(mt::TBOOL32, result)
	BODY(mt::TLimitedIpItemInfo, oldLimitedIpItemInfo)
	BODY(mt::TLimitedIpItemInfo, newLimitedIpItemInfo)

	/*<<更新限定限定ip段请求>>
	*BODY ：tOptType 更新类型（1:增加 2:删除 3:修改）
	*BODY ：TLimitedIpCfg 限定ip配置
	*BODY ：TLimitedIpItemInfo 需要增加或删除或修改的限定ip段
	*BODY ：modLimitedIpItemInfo 只有在修改操作时是要修改后的目的限定ip段，其他情况和TLimitedIpItemInfo一致
    *传输方向：mtservice->dispatch->net
    * see Ev_MT_Net_UpdateLimitedIpResult_Rsp
    */
	MESSAGE(Ev_MT_Net_UpdateLimitedIp_Req)
	BODY(mt::TU32, tOptType)
	BODY(mt::TLimitedIpCfg, TLimitedIpCfg)
	BODY(mt::TLimitedIpItemInfo, TLimitedIpItemInfo)
	BODY(mt::TLimitedIpItemInfo, modLimitedIpItemInfo)

	/*<<更新限定限定ip段响应>>
	*BODY ：result: true:修改成功 false:修改失败
	*BODY ：tOptType 更新类型（1:增加 2:删除 3:修改）
	*BODY ：TLimitedIpItemInfo 需要增加或删除或修改的限定ip段
	*BODY ：modLimitedIpItemInfo 只有在修改操作时是要修改后的目的限定ip段, 其他情况和TLimitedIpItemInfo一致
    *传输方向：mtservice->dispatch->net
    * see Ev_MT_Net_UpdateLimitedIp_Req
    */
	MESSAGE(Ev_MT_Net_UpdateLimitedIp_Rsp)
	BODY(mt::TBOOL32, result)
	BODY(mt::TU32, tOptType)
	BODY(mt::TLimitedIpItemInfo, TLimitedIpItemInfo)
	BODY(mt::TLimitedIpItemInfo, modLimitedIpItemInfo)

	 /*<<设置osd的分辨率命令>>
    *BODY ：EmVideoOutPutMode 输出分辨率枚举
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_HiSetHDResOutputResult_Ntf
	*/
	MESSAGE(Ev_MT_HiSetHDResOutput_Cmd)
    BODY(mt::TU32, EmVideoOutPutMode)

    /*<<设置osd的分辨率结果通知>>
	*BODY ：result 获取结果 0成功 1失败
    *BODY ：EmVideoOutPutMode 输出分辨率枚举
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_HiSetHDResOutput_Cmd
	*/
	MESSAGE(Ev_MT_HiSetHDResOutputResult_Ntf)
	BODY(mt::TU32, result)
	BODY(mt::TU32, EmVideoOutPutMode)


	/*<<通知终端刷新读取LICENSE>>
	 *传输方向：mtlicense<-dispatch<-mtservice
	*/
    MESSAGE(Ev_MT_ReadLicense_Cmd)


	 /*<<终端读取LICENSE后的通知通知>>
	 *传输方向：mtlicense->dispatch->mtservice
	*/
    MESSAGE(Ev_MT_ReadLicense_Ntf)
       
    /*<<开始或关闭HID读写>>
    *传输方向：net->dispatch->mt
    */
    MESSAGE(Ev_MT_StartHID_Ntf)
    BODY(mt::TBOOL32, bstart)

    /*<<HID数据传输>>
    *传输方向：mtmp->dispatch->net
    */
    MESSAGE(Ev_MT_HIDMt2Net_Cmd)
    BODY(mt::TString, tHIDinfo)

    /*<<HID数据传输>>
    *传输方向：net->dispatch->mtmp
    */
    MESSAGE(Ev_MT_HIDNet2Mt_Ntf)
    BODY(mt::TBytes, tHIDinfo)

#if !defined(_MESSAGE_HELP_)
    EV_END(NETMANAGE) = EVSEG_NETWORK_END
};
#endif//_MESSAGE_HELP_

#define Is_Net_Msg(m) ((m) >= EV_BGN(NETMANAGE) && (m) <= EV_END(NETMANAGE))

#endif//_MTNETMSG_H_