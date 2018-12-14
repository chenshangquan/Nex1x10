#ifndef _MTBLLBLLNETWORKMSG_H_
#define _MTBLLBLLNETWORKMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMtNetworkMsg
{
    EV_BLL_BGN(NETWORK) = EVSEG_BLL_NETWORK_BGN,
#endif

	/*********************************网络模块相关消息Begin***************************************/
    /*<<获取指定接口Ethernet 网卡首选IP/MASK信息>>
	*BODY ：ethernetid  指定网口ID
	*传输方向：mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_Ethernet_GetPreferredIpParam_Rsp
	*/
	MESSAGE(Ev_MT_BLL_Ethernet_GetPreferredIpParam_Req)
	BODY(mt::TU32, ethernetid)


	/*<<获取指定接口Ethernet 网卡首选IP/MASK信息结果通知>>
	*BODY ：result  0成功  其他错误码
	        ethernetid  指定网口ID
	        TEthnetInterfaceParam  首选网口IP/mask/mac信息

	*传输方向：mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_Ethernet_GetPreferredIpParam_Req
	*/
	MESSAGE(Ev_MT_BLL_Ethernet_GetPreferredIpParam_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TU32, ethernetid)
	BODY(mt::TEthnetInterfaceParam, TEthnetInterfaceParam)



    /*<<查询指定接口Ethernet网卡的dhcp租约和状态信息>>
	*BODY ：ethernetid  指定网口ID
	*传输方向：mtsdk->mtservice->dispatch->net
	* see  
	*/
	MESSAGE(Ev_MT_BLL_Ethernet_GetDHCPLeaseInfo_Req)
	BODY(mt::TU32, ethernetid)


    /*<<查询指定接口Ethernet网卡的dhcp租约信息>>
	*BODY ： result  0成功   其他错误码
	         TDHCPStateInfo  DHCP状态信息
	         TDHCPLeaseInfo  DHCP租约信息
	*传输方向：net->dispatch->mtservice->mtsdk
	* see  
	*/
	MESSAGE(Ev_MT_BLL_Ethernet_GetDHCPLeaseInfo_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TDHCPStateInfo, TDHCPStateInfo)
	BODY(mt::TDHCPLeaseInfo, TDHCPLeaseInfo)


    /*<<Ethernet网卡的dhcp租约信息通知>>
	*BODY ： TDHCPStateInfo  DHCP状态信息
	         TDHCPLeaseInfo  DHCP租约信息
	         reason          异常时的原因
	*传输方向：net->dispatch->mtservice->mtsdk
	* see  
	*/
	MESSAGE(Ev_MT_BLL_Ethernet_DHCPLeaseInfo_Ntf)
	BODY(mt::TDHCPStateInfo, TDHCPStateInfo)
	BODY(mt::TDHCPLeaseInfo, TDHCPLeaseInfo)
	BODY(mt::TU32, reason)


    /*<<查询指定接口Ethernet 网卡连接状态>>
	*传输方向：sdk->dispatch->mtservice
	* see Ev_MT_BLL_Ethernet_GetLinkState_Rsp
	*/
	MESSAGE(Ev_MT_BLL_Ethernet_GetLinkState_Req)


	/*<<查询指定接口Ethernet 网卡连接状态结果响应>>
	*BODY ：eth0_state  网口1状态  true:插入  false:断开
            eth1_state  网口2状态  true:插入  false:断开

	*传输方向：mtservice->dispatch->sdk
	* see Ev_MT_BLL_Ethernet_GetLinkState_Req
	*/
	MESSAGE(Ev_MT_BLL_Ethernet_GetLinkState_Rsp)
    BODY(mt::TBOOL32, eth0_state)
    BODY(mt::TBOOL32, eth1_state)


    /*<<指定接口Ethernet 网卡连接状态通知>>
	*BODY ：eth0_state  网口1状态  true:插入  false:断开
            eth1_state  网口2状态  true:插入  false:断开

	*传输方向：mtservice->dispatch->sdk
	*/
	MESSAGE(Ev_MT_BLL_Ethernet_LinkState_Ntf)
    BODY(mt::TBOOL32, eth0_state)
    BODY(mt::TBOOL32, eth1_state)

    /*<<PPPoE 拨号连接请求>>
	*BODY ：无
	*传输方向：mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_PPPoE_LinkState_Ntf
	*/
	MESSAGE(Ev_MT_BLL_PPPoE_Connect_Cmd)
//  BODY(mt::TEthnetPPPoECfg, pppoecfg)


	/*<<PPPoE 断开请求>>
	*BODY ：无
	*传输方向：mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_PPPoE_LinkState_Ntf
	*/
	MESSAGE(Ev_MT_BLL_PPPoE_DisConnect_Cmd)


	/*<<PPPoE 连接状态查询>>
	*BODY ：无
	*传输方向：mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_PPPoE_LinkState_Ntf
	*/
	MESSAGE(Ev_MT_BLL_PPPoE_GetLinkState_Req)
	


    /*<<PPPoE 连接状态查询响应>>
	*BODY ：TPPPoEState  连接状态信息
	*传输方向：net->dispatch->mtservice->mtsdk
	* see Ev_MT_BLL_PPPoE_GetLinkState_Req
	*/
	MESSAGE(Ev_MT_BLL_PPPoE_GetLinkState_Rsp)
	BODY(mt::TPPPoEState, pppoestate)

	
	/*<<PPPoE 连接状态通知>>
	*BODY ：pppoestate        PPPoE状态
	*传输方向：net->dispatch->mtservice->mtsdk
	* see Ev_MT_BLL_PPPoE_Connect_Cmd,Ev_MT_BLL_PPPoE_DisConnect_Cmd
	*/
	MESSAGE(Ev_MT_BLL_PPPoE_LinkState_Ntf)
	BODY(mt::TPPPoEState, pppoestate)



	/*<<PPPoE 连接后统计信息查询>>
	*BODY ：ethernetid  指定网口ID
	*传输方向：mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_PPPoE_GetStatisInfo_Rsp
	*/
	MESSAGE(Ev_MT_BLL_PPPoE_GetStatisInfo_Req)
	BODY(mt::TU32, ethernetid)

	
	/*<<PPPoE 连接后统计信息查询响应>>
	*BODY ：pppoestatis    连接统计信息
	*传输方向：net->dispatch->mtservice->mtsdk
	* see Ev_MT_BLL_PPPoE_GetStatisInfo_Req
	*/
	MESSAGE(Ev_MT_BLL_PPPoE_GetStatisInfo_Rsp)
	BODY(mt::TPPPoEStatis, pppoestatis)

	/*<<获取默认路由请求>>
	*BODY ：无
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_BLL_ROUTE_GetDefaultRoute_Req
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_GetDefaultRoute_Req)

 
	/*<<获取默认路由响应>>
	*BODY ：TRouteItemInfo 路由信息
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_BLL_ROUTE_GetDefaultRoute_Rsp
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_GetDefaultRoute_Rsp)
	BODY(mt::TRouteItemInfo, TRouteItemInfo )

	
	/*<<获取所有路由请求>>
	*BODY ：无
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_BLL_ROUTE_GetAllRoute_Rsp
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_GetAllRoute_Req)

 
	/*<<获取所有路由请求响应>>
	*BODY ：TRouteItemInfoList 路由列表信息
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_BLL_ROUTE_GetAllRoute_Req
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_GetAllRoute_Rsp)
	BODY(mt::TRouteItemInfoList, TRouteItemInfoList )


    /*<<新增一条路由请求>>
	*BODY ：tRouteItemInfo 新增路由信息
	*传输方向：sdk->dispatch->mtservice
	* see Ev_MT_BLL_ROUTE_AddRouteResult_Rsp
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_AddRoute_Req)
	BODY(mt::TRouteItemInfo, tRouteItemInfo )


	/*<<新增一条路由请求响应>>
	*BODY ：result: true:添加成功 false:添加失败
    *BODY ：tRouteItemInfo 新增路由信息
	*传输方向：mtservice->dispatch->sdk
	* see Ev_MT_BLL_ROUTE_AddRoute_Req
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_AddRouteResult_Rsp)
	BODY(mt::TBOOL32, result )
    BODY(mt::TRouteItemInfo, tRouteItemInfo )


    /*<<新增一条路由通知>>
	*BODY ：tRouteItemInfo 新增路由信息
    *传输方向：mtservice->dispatch->sdk
    * see
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_AddRoute_Ntf)
    BODY(mt::TRouteItemInfo, tRouteItemInfo )



    /*<<删除一条路由请求>>
	*BODY ：tRouteItemInfo 删除的路由信息
	*传输方向：sdk->dispatch->mtservice
	* see Ev_MT_BLL_ROUTE_DelRouteResult_Rsp
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_DelRoute_Req)
	BODY(mt::TRouteItemInfo, tRouteItemInfo )

 
	/*<<删除一条路由请求响应>>
	*BODY ：result: true:删除成功 false:删除失败
    *BODY ：tRouteItemInfo 删除的路由信息
	*传输方向：mtservice->dispatch->sdk
	* see Ev_MT_BLL_ROUTE_DelRoute_Req
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_DelRouteResult_Rsp)
	BODY(mt::TBOOL32, result )
    BODY(mt::TRouteItemInfo, tRouteItemInfo )


    /*<<删除一条路由通知>>
    *BODY ：tRouteItemInfo 删除的路由信息
	*传输方向：mtservice->dispatch->sdk
	* see Ev_MT_BLL_ROUTE_DelRoute_Cmd
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_DelRoute_Ntf)
    BODY(mt::TRouteItemInfo, tRouteItemInfo )




    /*<<修改一条路由请求>>
	*BODY ：oldRouteItemInfo 要修改的路由信息
            newRouteItemInfo 修改后的路由信息
	*传输方向：sdk->dispatch->mtservice
	* see Ev_MT_BLL_ROUTE_ModifyRouteResult_Rsp
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_ModifyRoute_Req)
    BODY(mt::TRouteItemInfo, oldRouteItemInfo )
    BODY(mt::TRouteItemInfo, newRouteItemInfo )

 
	/*<<修改一条路由请求响应>>
	*BODY ：result      true:修改成功 false:修改失败
    *       oldRouteItemInfo 要修改的路由信息
    *       newRouteItemInfo 修改后的路由信息
	*传输方向：mtservice->dispatch->sdk
	* see Ev_MT_BLL_ROUTE_ModifyRoute_Req
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_ModifyRouteResult_Rsp)
	BODY(mt::TBOOL32, result )
    BODY(mt::TRouteItemInfo, oldRouteItemInfo )
    BODY(mt::TRouteItemInfo, newRouteItemInfo )


    /*<<修改一条路由通知>>
	*BODY ：oldRouteItemInfo 要修改的路由信息
    *       newRouteItemInfo 修改后的路由信息
	*传输方向：mtservice->dispatch->sdk
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_ModifyRoute_Ntf)
    BODY(mt::TRouteItemInfo, oldRouteItemInfo )
    BODY(mt::TRouteItemInfo, newRouteItemInfo )




    /*<<Wifi 工作模式信息查询>>
	*BODY ：无
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_BLL_WIFI_GetWorkMode_Rsp
	*/
	MESSAGE(Ev_MT_BLL_WIFI_GetWorkMode_Req)

	
	/*<<Wifi 工作模式信息响应>>
	* ----------------------------------------------------------
	* 参数：：TWifiWorkMode：	当前Wifi工作模式
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_BLL_WIFI_GetWorkMode_Req
	*/
	MESSAGE(Ev_MT_BLL_WIFI_GetWorkMode_Rsp)
	BODY(mt::TWifiWorkMode, TWifiWorkMode)




	/*<<Wifi 热点扫描请求>>
	*BODY ：无
	*传输方向：mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_WIFI_ScanResult_Rsp
	*/
	MESSAGE(Ev_MT_BLL_WIFI_StartScan_Req)


	/*<<Wifi 热点扫描结果通知>>
	* ----------------------------------------------------------
	* 参数：wifiscanresultlist：	扫描到候选WIFI结果列表
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice->mtsdk
	* see Ev_MT_BLL_WIFI_StartScan_Req
	*/
	MESSAGE(Ev_MT_BLL_WIFI_ScanResult_Rsp)
	BODY(mt::TWifiScanResultList, wifiscanresultlist)

	/*<<生产测试设置Wifi测试模式命令>>
	* ----------------------------------------------------------
	* 参数：TWifiWorkMode
	* ----------------------------------------------------------
	*传输方向：mtmfgtest->mtsdk->mtservice
	* see 
	*/
	MESSAGE(Ev_MT_BLL_Mtmfgtest_SetWifiWorkModeCfg_Cmd)
	BODY(mt::TBOOL32, bStart)

	/*<<Wifi 热点连接请求>>
	* ----------------------------------------------------------
	* 参数：wificonnparam：	wifi网络连接参数
	* ----------------------------------------------------------
	*传输方向：mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_WIFI_LinkState_Ntf
	*/
	MESSAGE(Ev_MT_BLL_WIFI_Connect_Cmd)
	BODY(mt::TWifiConnParam, wificonnparam)


	/*<<Wifi 热点断开请求>>
	* ----------------------------------------------------------
	* 参数：无
	* ----------------------------------------------------------
	*传输方向：mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_WIFI_LinkState_Ntf	      
	*/
	MESSAGE(Ev_MT_BLL_WIFI_Disconnect_Cmd)
	
	

    /*<<Wifi 连接状态查询>>
	*BODY ：无
	*传输方向：mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_WIFI_LinkState_Ntf
	*/
	MESSAGE(Ev_MT_BLL_WIFI_GetLinkState_Req)



    /*<<Wifi 连接状态查询通知>>
	* ----------------------------------------------------------
	* 参数：TWifiCurDetailInfo：	Wifi网络连接状态信息
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_WIFI_GetLinkState_Req
	*/
	MESSAGE(Ev_MT_BLL_WIFI_LinkState_Rsp)
	BODY(mt::TWifiCurDetailInfo, wificurdetailinfo)

	
	/*<<Wifi 热点连接状态通知>>
	* ----------------------------------------------------------
	* 参数：wificurdetailinfo：	Wifi网络连接结果信息
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice->mtsdk
	* see Ev_MT_BLL_WIFI_Connect_Cmd, Ev_MT_BLL_WIFI_Disconnect_Cmd
	*/
	MESSAGE(Ev_MT_BLL_WIFI_LinkState_Ntf)
	BODY(mt::TWifiCurDetailInfo, wificurdetailinfo)

	 /*<<Wifi 忘记网络请求>>
	* ----------------------------------------------------------
	* 参数：TU32：	wifi热点id
	* ----------------------------------------------------------
	*传输方向：mtsdk->dispatch->mtservice
	* see Ev_MT_BLL_WIFI_Forget_Rsp	      
	*/
	MESSAGE(Ev_MT_BLL_WIFI_Forget_Req)
	BODY(mt::TU32, hotspotId)

     /*<<Wifi 忘记网络响应>>
	* ----------------------------------------------------------
	* 参数：TBOOL32：	设置结果
	* 参数：TU32：		wifi热点id
	* ----------------------------------------------------------
	*传输方向：mtservice->dispatch->mtsdk
	* see Ev_MT_BLL_WIFI_Forget_Req	      
	*/
	MESSAGE(Ev_MT_BLL_WIFI_Forget_Rsp)
    BODY(mt::TBOOL32, result)
	BODY(mt::TU32, hotspotId)
	
	/*<<Wifi 获取当前连接的Wifi客户端属性请求>>
	* ----------------------------------------------------------
	* 参数：无 
	* ----------------------------------------------------------
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_BLL_WIFI_GetModClientProperty_Rsp
	*/
	MESSAGE(Ev_MT_BLL_WIFI_GetModClientProperty_Req)
	
	
	/*<<Wifi 获取当前连接的Wifi客户端属性请求通知>>
	* ----------------------------------------------------------
	* 参数：TWifiConfiguration:    Wifi连接的客户端属性信息 
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_BLL_WIFI_ModClientProperty_Cmd
	*/
	MESSAGE(Ev_MT_BLL_WIFI_GetModClientProperty_Rsp)
	BODY(mt::TWifiConfiguration, TWifiConfiguration)
	
	
	/*<<Wifi 获取当前连接的Wifi客户端详细信息请求>>
	* ----------------------------------------------------------
	* 参数：无 
	* ----------------------------------------------------------
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_BLL_WIFI_GetWifiCurConnectedInfo_Rsp
	*/
	MESSAGE(Ev_MT_BLL_WIFI_GetWifiCurConnectedInfo_Req)
	
	
	/*<<Wifi 获取当前连接的Wifi客户端详细信息请求通知>>
	* ----------------------------------------------------------
	* 参数：TWifiCurDetailInfo:    Wifi连接的客户端详细信息 
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_BLL_WIFI_GetWifiCurConnectedInfo_Req
	*/
	MESSAGE(Ev_MT_BLL_WIFI_GetWifiCurConnectedInfo_Rsp)
	BODY(mt::TWifiCurDetailInfo, TWifiCurDetailInfo)
	
	
	/*<<Wifi 当前连接的Wifi统计信息查询请求>>
	* ----------------------------------------------------------
	* 参数：无
	* ----------------------------------------------------------
	*传输方向：mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_WIFI_GetCurWifiStatisInfo_Rsp
	*/
	MESSAGE(Ev_MT_BLL_WIFI_GetCurWifiStatisInfo_Req)
 
	
	/*<<Wifi 热点连接结果状态响应>>
	* ----------------------------------------------------------
	* 参数：wifistatisinfo：	当前Wifi的统计信息 含信号强度，上下行总带宽
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice->mtsdk
	* see Ev_MT_BLL_WIFI_GetCurWifiStatisInfo_Req
	*/
	MESSAGE(Ev_MT_BLL_WIFI_GetCurWifiStatisInfo_Rsp)
	BODY(mt::TWifiStatisInfo, wifistatisinfo)

	/*<<获取无线投屏信息请求>>
	*传输方向：mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_WIFI_GetWirelessScreen_Rsp
	*/
	MESSAGE(Ev_MT_BLL_WIFI_GetWirelessScreen_Req)

	/*<<获取无线投屏信息请求响应>>
	*BODY ：TWifiWirelessScreenInfo  无线投屏信息
	*传输方向：net->dispatch->mtservice->mtsdk
	* see Ev_MT_BLL_WIFI_GetWirelessScreen_Req
	*/
	MESSAGE(Ev_MT_BLL_WIFI_GetWirelessScreen_Rsp)
	BODY(mt::TWifiWirelessScreenInfo, TWifiWirelessScreenInfo)

	/*<<开启或停止无线投屏命令>>
	*BODY ：bStart  true:启动  false:停止
	*传输方向：mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_WIFI_WirelessScreenStateChange_Ntf
	*/
	MESSAGE(Ev_MT_BLL_WIFI_SetWirelessScreen_Cmd)
	BODY(mt::TBOOL32, bStart)

	/*<<无线投屏状态改变通知>>
	* ----------------------------------------------------------
	* 参数：TWifiWirelessScreenInfo：无线投屏信息
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice->mtsdk
	* see Ev_MT_BLL_WIFI_SetWirelessScreen_Cmd
	*/
	MESSAGE(Ev_MT_BLL_WIFI_WirelessScreenStateChange_Ntf)
	BODY(mt::TWifiWirelessScreenInfo, TWifiWirelessScreenInfo)	

    /*<<MobileData  移动数据连接后详细状态通知>>
	* ----------------------------------------------------------
	* 参数：：TMobileDataCurDetailInfo：	当前移动数据的详细信息
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_BLL_MOBILEDATA_ChangeWorkMode_Cmd
	*/
	MESSAGE(Ev_MT_BLL_MOBILEDATA_LinkState_Ntf)
	BODY(mt::TMobileDataCurDetailInfo, TMobileDataCurDetailInfo)




    /*<<MobileData 工作模式信息查询>>
	*BODY ：无
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_BLL_MOBILEDATA_GetWorkMode_Rsp
	*/
	MESSAGE(Ev_MT_BLL_MOBILEDATA_GetWorkMode_Req)

	
	/*<<MobileData  工作模式信息查询响应>>
	* ----------------------------------------------------------
	* 参数：：TWifiWorkMode：	当前Wifi工作模式
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_BLL_MOBILEDATA_GetWorkMode_Req
	*/
	MESSAGE(Ev_MT_BLL_MOBILEDATA_GetWorkMode_Rsp)
	BODY(mt::TMobileDataWorkMode, TMobileDataWorkMode)



	/*<<MobileData 查询移动数据连接后详细消息>>
	* ----------------------------------------------------------
	* 参数：
	* ----------------------------------------------------------
	*传输方向：mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_MOBILEDATA_GetDetailInfo_Rsp
	*/
	MESSAGE(Ev_MT_BLL_MOBILEDATA_GetDetailInfo_Req)

	
	/*<<MobileData  移动数据连接后详细消息响应>>
	* ----------------------------------------------------------
	* 参数：mobiledatacurdetailinfo   当前移动数据的详细信息
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice->mtsdk
	* see Ev_MT_BLL_MOBILEDATA_GetDetailInfo_Req
	*/
	MESSAGE(Ev_MT_BLL_MOBILEDATA_GetDetailInfo_Rsp)
	BODY(mt::TMobileDataCurDetailInfo, mobiledatacurdetailinfo)


	/*<<MobileData 当前连接的移动数据统计信息查询请求>>
	* ----------------------------------------------------------
	* 参数：无
	* ----------------------------------------------------------
	*传输方向：mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_MOBILEDATA_GetCurStatisInfo_Rsp
	*/
	MESSAGE(Ev_MT_BLL_MOBILEDATA_GetCurStatisInfo_Req)
 
	
	/*<<MobileData 当前连接的移动数据统计信息查询响应>>
	* ----------------------------------------------------------
	* 参数：mobiledatastatisinfo   当前Wifi的统计信息 含信号强度，上下行总带宽
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice->mtsdk
	* see Ev_MT_BLL_MOBILEDATA_GetCurStatisInfo_Req
	*/
	MESSAGE(Ev_MT_BLL_MOBILEDATA_GetCurStatisInfo_Rsp)
	BODY(mt::TMobileDataStatisInfo, mobiledatastatisinfo)



	/*<<IP/MAC冲突 状态通知>>
	* ----------------------------------------------------------
	*参数 ：netconflictedinfo    冲突信息
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice->mtsdk
	* see 
	*/
	MESSAGE(Ev_MT_BLL_NET_IPMACConflicted_Ntf)
	BODY(mt::TNetConfilictedInfo, netconflictedinfo )


	/*<<Ping包 命令请求>>
	* ----------------------------------------------------------
	* 参数：pingtestparam    PING参数信息
	* ----------------------------------------------------------
	*传输方向：mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_NET_PingTestResult_Rsp
	*/
	MESSAGE(Ev_MT_BLL_NET_PingTest_Req)
	BODY(mt::TPingTestParam, pingtestparam )
	

	/*<<Ping包 响应结果>>
	* ----------------------------------------------------------
	* 参数：pingresult   PING结果信息
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice->mtsdk
	* see Ev_MT_BLL_NET_PingTest_Req
	*/
	MESSAGE(Ev_MT_BLL_NET_PingTestResult_Rsp)
	BODY(mt::TPingResult, pingresult )


	/*<<查询DNS对应的IP信息请求>>
	* ----------------------------------------------------------
	* 参数：TDNSNameToIpInfo 要查询的DNS信息
	* ----------------------------------------------------------
	*传输方向：sdk->mtservice->dispatch->net
	* see Ev_MT_BLL_Ethernet_GetIpByDNSInfo_Rsp
	*/
	MESSAGE(Ev_MT_BLL_Ethernet_GetIpByDNSInfo_Req)
	BODY(mt::TDNSNameToIpInfo, TDNSNameToIpInfo)
 
	
	/*<<查询DNS对应的IP信息请求响应>>
	* ----------------------------------------------------------
	* 参数：TDNSNameToIpResult：	DNS查询到的IP结果信息
	* ----------------------------------------------------------
	*传输方向：net->dispatch->mtservice->sdk
	* see Ev_MT_BLL_Ethernet_GetIpByDNSInfo_Req
	*/
	MESSAGE(Ev_MT_BLL_Ethernet_GetIpByDNSInfo_Rsp)
	BODY(mt::TDNSNameToIpResult, TDNSNameToIpResult)



    /*<<设置当前日期时间信息>>
	*BODY ：  tmttime 时间信息  
	*传输方向：sdk->dispatch->mtservice
	* see Ev_MT_BLL_SetSysDataTimeResult_Rsp
	*/
	MESSAGE(Ev_MT_BLL_SetSysDataTime_Req)
	BODY(mt::TMTTime, tmttime )
	
	
	/*<<设置当前日期时间信息响应>>
	*BODY ：   result 设置结果 0成功 其他错误码
	           tmttime 时间信息 
	*传输方向：mtservice->dispatch->sdk
	* see Ev_MT_BLL_SetSysDataTime_Req
	*/
	MESSAGE(Ev_MT_BLL_SetSysDataTimeResult_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTTime, tmttime )


    /*<<设置当前日期时间通知>>
	*BODY ：   tmttime 时间信息 
	*传输方向：mtservice->dispatch->sdk
	* see
	*/
	MESSAGE(Ev_MT_BLL_SetSysDataTime_Ntf)
	BODY(mt::TMTTime, tmttime )


	
	
	/*<<查询当前日期时间信息>>
	*BODY ：    
	*传输方向：sdk->dispatch->mtservice
	* see Ev_MT_BLL_GetSysDataTime_Rsp
	*/
	MESSAGE(Ev_MT_BLL_GetSysDataTime_Req)
	
	
	/*<<查询当前日期时间信息响应>>
	*BODY ：result 获取结果 0成功 其他错误码
	        tmttime 时间信息 
	*传输方向：mtservice->dispatch->sdk
	* see Ev_MT_BLL_GetSysDataTime_Req
	*/
	MESSAGE(Ev_MT_BLL_GetSysDataTime_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTTime, tmttime )



	/*<<设置NTP服务开启关闭状态>>
	*BODY ：  TMTNTPInfo NTP服务开启状态 
	*传输方向：sdk->dispatch->mtservice
	* see Ev_MT_BLL_SetNTPSvrParamResult_Rsp
	*/
	MESSAGE(Ev_MT_BLL_SetNTPSvrParam_Req)
	BODY(mt::TMTNTPInfo, TMTNTPInfo )
	
	
	/*<<设置NTP服务开启关闭状态响应>>
	*BODY ：   result 设置结果 0成功 其他错误码
	           TMTNTPInfo NTP参数信息 
	*传输方向：mtservice->dispatch->sdk
	* see Ev_MT_BLL_SetNTPSvrParam_Req
	*/
	MESSAGE(Ev_MT_BLL_SetNTPSvrParamResult_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTNTPInfo, TMTNTPInfo )



    /*<<设置NTP服务开启关闭状态通知>>
	*BODY ：   TMTNTPInfo NTP参数信息 
	*传输方向：mtservice->dispatch->sdk
	* see
	*/
	MESSAGE(Ev_MT_BLL_SetNTPSvrParam_Ntf)
	BODY(mt::TMTNTPInfo, TMTNTPInfo )

	
	
	/*<<查询当前NTP服务开启状态请求>>
	*BODY ：    
	*传输方向：sdk->dispatch->mtservice
	* see Ev_MT_BLL_GetNTPSvrParam_Rsp
	*/
	MESSAGE(Ev_MT_BLL_GetNTPSvrParam_Req)
	
	
	/*<<查询当前NTP服务开启状态响应>>
	*BODY ：result 获取结果 0成功 其他错误码
	        TMTNTPInfo NTP参数信息 
	*传输方向：mtservice->dispatch->sdk
	* see Ev_MT_BLL_GetNTPSvrParam_Req
	*/
	MESSAGE(Ev_MT_BLL_GetNTPSvrParam_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTNTPInfo, TMTNTPInfo )




    /*<<Telnet服务开启/停止请求>>
	*BODY ：  bStart  true:启动  false:停止  
	*传输方向：sdk->dispatch->mtservice
	* see Ev_MT_BLL_Net_TelnetService_Ntf
	*/
	MESSAGE(Ev_MT_BLL_Net_TelnetService_Cmd)
	BODY(mt::TBOOL32, bStart )
	
	
	/*<<Telnet服务开启/停止状态通知>>
	*BODY ：reason    0:成功, 1,启动失败，2,停止失败, 其他错误码
	        bStarted  当前状态 true:启动状态  false:停止状态  
	*传输方向：mtservice->dispatch->sdk
	* see Ev_MT_BLL_Net_TelnetService_Cmd
	*/
	MESSAGE(Ev_MT_BLL_Net_TelnetService_Ntf)
	BODY(mt::TU32, reason)
	BODY(mt::TBOOL32, bStarted )

	
	/*<<Ftp服务开启/停止请求>>
	*BODY ：  bStart  true:启动  false:停止  
	*传输方向：sdk->dispatch->mtservice
	* see Ev_MT_BLL_Net_FtpService_Ntf
	*/
	MESSAGE(Ev_MT_BLL_Net_FtpService_Cmd)
	BODY(mt::TBOOL32, bStart )
	
	
	/*<<Ftp服务开启/停止状态通知>>
	*BODY ：reason    0:成功, 1,启动失败，2,停止失败, 其他错误码
	        bStarted  当前状态 true:启动状态  false:停止状态  
	*传输方向：mtservice->dispatch->sdk
	* see Ev_MT_BLL_Net_FtpService_Cmd
	*/
	MESSAGE(Ev_MT_BLL_Net_FtpService_Ntf)
	BODY(mt::TU32, reason)
	BODY(mt::TBOOL32, bStarted )

	
	/*<<Http服务开启/停止请求>>
	*BODY ：  bStart  true:启动  false:停止  
	*传输方向：sdk->dispatch->mtservice
	* see Ev_MT_BLL_Net_HttpService_Ntf
	*/
	MESSAGE(Ev_MT_BLL_Net_HttpService_Cmd)
	BODY(mt::TBOOL32, bStart )
	
	
	/*<<Http服务开启/停止状态通知>>
	*BODY ：reason    0:成功, 1,启动失败，2,停止失败, 其他错误码
	        bStarted  当前状态 true:启动状态  false:停止状态  
	*传输方向：mtservice->dispatch->sdk
	* see Ev_MT_BLL_Net_HttpService_Cmd
	*/
	MESSAGE(Ev_MT_BLL_Net_HttpService_Ntf)
	BODY(mt::TU32, reason)
	BODY(mt::TBOOL32, bStarted )



    /*<<设置TimeZone信息>>
	*BODY ：  TMTTimeZoneInfo 时区信息 
	*传输方向：sdk->dispatch->mtservice
	* see Ev_MT_BLL_SetTimeZone_Rsp
	*/
	MESSAGE(Ev_MT_BLL_SetTimeZone_Req)
	BODY(mt::TMTTimeZoneInfo, TMTTimeZoneInfo )
	
	
	/*<<设置TimeZone信息响应>>
	*BODY ：   result 设置结果 0成功 其他错误码
	           TMTTimeZoneInfo 时区信息 
	*传输方向：mtservice->dispatch->sdk
	* see Ev_MT_BLL_SetTimeZone_Req
	*/
	MESSAGE(Ev_MT_BLL_SetTimeZone_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTTimeZoneInfo, TMTTimeZoneInfo )
	
	
	/*<<查询当前TimeZone信息请求>>
	*BODY ：    
	*传输方向：sdk->dispatch->mtservice
	* see Ev_MT_BLL_GetTimeZone_Rsp
	*/
	MESSAGE(Ev_MT_BLL_GetTimeZone_Req)
	
	
	/*<<查询当前TimeZone信息响应>>
	*BODY ：result 获取结果 0成功 其他错误码
	        TMTTimeZoneInfo 时区信息  
	*传输方向：mtservice->dispatch->sdk
	* see Ev_MT_BLL_GetTimeZone_Req
	*/
	MESSAGE(Ev_MT_BLL_GetTimeZone_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTTimeZoneInfo, TMTTimeZoneInfo )



    /*<<设置Ftp/Telnet账号信息>>
	*BODY ：  TMTFtpTelnetAccountInfo 账号信息 
	*传输方向：sdk->dispatch->mtservice
	* see Ev_MT_BLL_SetFtpTelnetAccountInfo_Rsp
	*/
	MESSAGE(Ev_MT_BLL_SetFtpTelnetAccountInfo_Req)
	BODY(mt::TMTFtpTelnetAccountInfo, TMTFtpTelnetAccountInfo )
	
	
	/*<<设置Ftp/Telnet账号信息响应>>
	*BODY ：   result 设置结果 0成功 其他错误码
	           TMTFtpTelnetAccountInfo 账号信息 
	*传输方向：mtservice->dispatch->sdk
	* see Ev_MT_BLL_SetFtpTelnetAccountInfo_Req
	*/
	MESSAGE(Ev_MT_BLL_SetFtpTelnetAccountInfo_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTFtpTelnetAccountInfo, TMTFtpTelnetAccountInfo )

    /*<<设置网口切换信息通知>>
	*BODY ：   TEthnetCfg 以太网信息 
	*传输方向：mtservice->dispatch->sdk
	* see 
	*/
    MESSAGE(Ev_MT_BLL_HD_EthnetCardChange_Ntf)
    BODY(mt::TEthnetCfg, TEthnetCfg)

	/*<<设置限定IP段配置命令>>
	*BODY ：tLimitedIpCfg 限定IP段配置信息
    *传输方向：sdk->dispatch->mtservice
    * see Ev_MT_BLL_Net_SetLimitedIpCfg_Ntf
    */
	MESSAGE(Ev_MT_BLL_Net_SetLimitedIpCfg_Cmd)
	BODY(mt::TLimitedIpCfg, TLimitedIpCfg)

	/*<<设置限定IP段配置通知>>
	*BODY ：tLimitedIpCfg 限定IP段配置信息
    *传输方向：sdk->dispatch->mtservice
    * see Ev_MT_BLL_Net_SetLimitedIpCfg_Ntf
    */
	MESSAGE(Ev_MT_BLL_Net_SetLimitedIpCfg_Ntf)
	BODY(mt::TBOOL32, result)

	/*<<新增一条限定ip段请求>>
	*BODY ：TLimitedIpItemInfo 新增限定IP段信息
    *传输方向：mtservice->dispatch->net
    * see Ev_MT_BLL_Net_AddLimitedIpResult_Rsp
    */
	MESSAGE(Ev_MT_BLL_Net_AddLimitedIp_Req)
	BODY(mt::TLimitedIpItemInfo, TLimitedIpItemInfo)

	/*<<新增一条限定ip段响应>>
	*BODY ：result: true:添加成功 false:添加失败
	*BODY ：TLimitedIpItemInfo 新增限定IP段信息
    *传输方向：mtservice->dispatch->net
    * see Ev_MT_BLL_Net_AddLimitedIp_Req
    */
	MESSAGE(Ev_MT_BLL_Net_AddLimitedIpResult_Rsp)
	BODY(mt::TBOOL32, result)
	BODY(mt::TLimitedIpItemInfo, TLimitedIpItemInfo)

	/*<<新增一条限定ip段通知>>
	*BODY ：TLimitedIpItemInfo 新增限定IP段信息
    *传输方向：mtservice->dispatch->net
    */
	MESSAGE(Ev_MT_BLL_Net_AddLimitedIpResult_Ntf)
	BODY(mt::TLimitedIpItemInfo, TLimitedIpItemInfo)

	/*<<删除一条限定ip段请求>>
	*BODY ：TLimitedIpItemInfo 要删除的限定IP段信息
    *传输方向：mtservice->dispatch->net
    * see Ev_MT_BLL_FtpTelnet_DelLimitedIp_Rsp
    */
	MESSAGE(Ev_MT_BLL_Net_DelLimitedIp_Req)
	BODY(mt::TLimitedIpItemInfo, TLimitedIpItemInfo)

	/*<<删除一条限定ip段响应>>
	*BODY ：result: true:删除成功 false:删除失败
	*BODY ：TLimitedIpItemInfo 要删除的限定IP段信息
    *传输方向：mtservice->dispatch->net
    * see Ev_MT_BLL_FtpTelnet_DelLimitedIp_Req
    */
	MESSAGE(Ev_MT_BLL_Net_DelLimitedIpResult_Rsp)
	BODY(mt::TBOOL32, result)
	BODY(mt::TLimitedIpItemInfo, TLimitedIpItemInfo)

	/*<<删除一条限定ip段通知>>
	*BODY ：TLimitedIpItemInfo 要删除的限定IP段信息
    *传输方向：mtservice->dispatch->net
    */
	MESSAGE(Ev_MT_BLL_Net_DelLimitedIpResult_Ntf)
	BODY(mt::TLimitedIpItemInfo, TLimitedIpItemInfo)

	/*<<修改一条限定ip段请求>>
	*BODY ：oldLimitedIpItemInfo 修改前的限定IP段信息
	*BODY ：newLimitedIpItemInfo 修改后的限定IP段信息
    *传输方向：mtservice->dispatch->net
    * see Ev_MT_BLL_FtpTelnet_ModLimitedIp_Rsp
    */
	MESSAGE(Ev_MT_BLL_Net_ModLimitedIp_Req)
	BODY(mt::TLimitedIpItemInfo, oldLimitedIpItemInfo)
	BODY(mt::TLimitedIpItemInfo, newLimitedIpItemInfo)

	/*<<修改一条限定ip段响应>>
	*BODY ：result: true:修改成功 false:修改失败
	*BODY ：oldLimitedIpItemInfo 修改前的限定IP段信息
	*BODY ：newLimitedIpItemInfo 修改后的限定IP段信息
    *传输方向：mtservice->dispatch->net
    * see Ev_MT_BLL_FtpTelnet_ModLimitedIp_Req
    */
	MESSAGE(Ev_MT_BLL_Net_ModLimitedIpResult_Rsp)
	BODY(mt::TBOOL32, result)
	BODY(mt::TLimitedIpItemInfo, oldLimitedIpItemInfo)
	BODY(mt::TLimitedIpItemInfo, newLimitedIpItemInfo)

	/*<<修改一条限定ip段通知>>
	*BODY ：oldLimitedIpItemInfo 修改前的限定IP段信息
	*BODY ：newLimitedIpItemInfo 修改后的限定IP段信息
    *传输方向：mtservice->dispatch->net
    * see 
    */
	MESSAGE(Ev_MT_BLL_Net_ModLimitedIpResult_Ntf)
	BODY(mt::TLimitedIpItemInfo, oldLimitedIpItemInfo)
	BODY(mt::TLimitedIpItemInfo, newLimitedIpItemInfo)

    /*<<设置指定接口Ethernet的网卡信息结果通知>>
	*BODY ：result  0成功  其他错误码
	        ethernetid  设置时指定的网口ID
	*传输方向：mtservice->dispatch->sdk
	* see Ev_MT_Ethernet_SetIpParam_Cmd
	*/
    MESSAGE(Ev_MT_BLL_Ethernet_SetIpParamResult_Ntf)
    BODY(mt::TU32, result)
    BODY(mt::TU32, ethernetid)

	 /*<<通知终端刷新读取LICENSE>>
	 *传输方向：mtservice<-dispatch<-sdk
	*/
    MESSAGE(Ev_MT_BLL_ReadLicense_Cmd)


	 /*<<终端读取LICENSE后的通知通知>>
	 *传输方向：mtservice->dispatch->sdk
	*/
    MESSAGE(Ev_MT_BLL_ReadLicense_Ntf)
	BODY(mt::TLicense, tLicense)
	
	
	/*<<开始或关闭HID读写>>
    *传输方向：mt->dispatch->net
    */
    MESSAGE(Ev_MT_BLL_StartHID_Cmd)
    BODY(mt::TBOOL32, bstart)

    /*<<HID数据传输>>
    *传输方向：mt->dispatch->net
    */
    MESSAGE(Ev_MT_BLL_HIDMt2Net_Cmd)
    BODY(mt::TString, tHIDinfo)

    /*<<HID数据传输>>
    *传输方向：net->dispatch->mt
    */
    MESSAGE(Ev_MT_BLL_HIDNet2Mt_Ntf)
    BODY(mt::TBytes, tHIDinfo)

	
#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(NETWORK) = EVSEG_BLL_NETWORK_END
};
#endif

#define Is_BLL_Network_Msg(m) ((m) >= EV_BLL_BGN(NETWORK) && (m) <= EV_BLL_END(NETWORK))

#endif