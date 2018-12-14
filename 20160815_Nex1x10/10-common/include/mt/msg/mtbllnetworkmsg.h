#ifndef _MTBLLBLLNETWORKMSG_H_
#define _MTBLLBLLNETWORKMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMtNetworkMsg
{
    EV_BLL_BGN(NETWORK) = EVSEG_BLL_NETWORK_BGN,
#endif

	/*********************************����ģ�������ϢBegin***************************************/
    /*<<��ȡָ���ӿ�Ethernet ������ѡIP/MASK��Ϣ>>
	*BODY ��ethernetid  ָ������ID
	*���䷽��mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_Ethernet_GetPreferredIpParam_Rsp
	*/
	MESSAGE(Ev_MT_BLL_Ethernet_GetPreferredIpParam_Req)
	BODY(mt::TU32, ethernetid)


	/*<<��ȡָ���ӿ�Ethernet ������ѡIP/MASK��Ϣ���֪ͨ>>
	*BODY ��result  0�ɹ�  ����������
	        ethernetid  ָ������ID
	        TEthnetInterfaceParam  ��ѡ����IP/mask/mac��Ϣ

	*���䷽��mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_Ethernet_GetPreferredIpParam_Req
	*/
	MESSAGE(Ev_MT_BLL_Ethernet_GetPreferredIpParam_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TU32, ethernetid)
	BODY(mt::TEthnetInterfaceParam, TEthnetInterfaceParam)



    /*<<��ѯָ���ӿ�Ethernet������dhcp��Լ��״̬��Ϣ>>
	*BODY ��ethernetid  ָ������ID
	*���䷽��mtsdk->mtservice->dispatch->net
	* see  
	*/
	MESSAGE(Ev_MT_BLL_Ethernet_GetDHCPLeaseInfo_Req)
	BODY(mt::TU32, ethernetid)


    /*<<��ѯָ���ӿ�Ethernet������dhcp��Լ��Ϣ>>
	*BODY �� result  0�ɹ�   ����������
	         TDHCPStateInfo  DHCP״̬��Ϣ
	         TDHCPLeaseInfo  DHCP��Լ��Ϣ
	*���䷽��net->dispatch->mtservice->mtsdk
	* see  
	*/
	MESSAGE(Ev_MT_BLL_Ethernet_GetDHCPLeaseInfo_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TDHCPStateInfo, TDHCPStateInfo)
	BODY(mt::TDHCPLeaseInfo, TDHCPLeaseInfo)


    /*<<Ethernet������dhcp��Լ��Ϣ֪ͨ>>
	*BODY �� TDHCPStateInfo  DHCP״̬��Ϣ
	         TDHCPLeaseInfo  DHCP��Լ��Ϣ
	         reason          �쳣ʱ��ԭ��
	*���䷽��net->dispatch->mtservice->mtsdk
	* see  
	*/
	MESSAGE(Ev_MT_BLL_Ethernet_DHCPLeaseInfo_Ntf)
	BODY(mt::TDHCPStateInfo, TDHCPStateInfo)
	BODY(mt::TDHCPLeaseInfo, TDHCPLeaseInfo)
	BODY(mt::TU32, reason)


    /*<<��ѯָ���ӿ�Ethernet ��������״̬>>
	*���䷽��sdk->dispatch->mtservice
	* see Ev_MT_BLL_Ethernet_GetLinkState_Rsp
	*/
	MESSAGE(Ev_MT_BLL_Ethernet_GetLinkState_Req)


	/*<<��ѯָ���ӿ�Ethernet ��������״̬�����Ӧ>>
	*BODY ��eth0_state  ����1״̬  true:����  false:�Ͽ�
            eth1_state  ����2״̬  true:����  false:�Ͽ�

	*���䷽��mtservice->dispatch->sdk
	* see Ev_MT_BLL_Ethernet_GetLinkState_Req
	*/
	MESSAGE(Ev_MT_BLL_Ethernet_GetLinkState_Rsp)
    BODY(mt::TBOOL32, eth0_state)
    BODY(mt::TBOOL32, eth1_state)


    /*<<ָ���ӿ�Ethernet ��������״̬֪ͨ>>
	*BODY ��eth0_state  ����1״̬  true:����  false:�Ͽ�
            eth1_state  ����2״̬  true:����  false:�Ͽ�

	*���䷽��mtservice->dispatch->sdk
	*/
	MESSAGE(Ev_MT_BLL_Ethernet_LinkState_Ntf)
    BODY(mt::TBOOL32, eth0_state)
    BODY(mt::TBOOL32, eth1_state)

    /*<<PPPoE ������������>>
	*BODY ����
	*���䷽��mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_PPPoE_LinkState_Ntf
	*/
	MESSAGE(Ev_MT_BLL_PPPoE_Connect_Cmd)
//  BODY(mt::TEthnetPPPoECfg, pppoecfg)


	/*<<PPPoE �Ͽ�����>>
	*BODY ����
	*���䷽��mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_PPPoE_LinkState_Ntf
	*/
	MESSAGE(Ev_MT_BLL_PPPoE_DisConnect_Cmd)


	/*<<PPPoE ����״̬��ѯ>>
	*BODY ����
	*���䷽��mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_PPPoE_LinkState_Ntf
	*/
	MESSAGE(Ev_MT_BLL_PPPoE_GetLinkState_Req)
	


    /*<<PPPoE ����״̬��ѯ��Ӧ>>
	*BODY ��TPPPoEState  ����״̬��Ϣ
	*���䷽��net->dispatch->mtservice->mtsdk
	* see Ev_MT_BLL_PPPoE_GetLinkState_Req
	*/
	MESSAGE(Ev_MT_BLL_PPPoE_GetLinkState_Rsp)
	BODY(mt::TPPPoEState, pppoestate)

	
	/*<<PPPoE ����״̬֪ͨ>>
	*BODY ��pppoestate        PPPoE״̬
	*���䷽��net->dispatch->mtservice->mtsdk
	* see Ev_MT_BLL_PPPoE_Connect_Cmd,Ev_MT_BLL_PPPoE_DisConnect_Cmd
	*/
	MESSAGE(Ev_MT_BLL_PPPoE_LinkState_Ntf)
	BODY(mt::TPPPoEState, pppoestate)



	/*<<PPPoE ���Ӻ�ͳ����Ϣ��ѯ>>
	*BODY ��ethernetid  ָ������ID
	*���䷽��mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_PPPoE_GetStatisInfo_Rsp
	*/
	MESSAGE(Ev_MT_BLL_PPPoE_GetStatisInfo_Req)
	BODY(mt::TU32, ethernetid)

	
	/*<<PPPoE ���Ӻ�ͳ����Ϣ��ѯ��Ӧ>>
	*BODY ��pppoestatis    ����ͳ����Ϣ
	*���䷽��net->dispatch->mtservice->mtsdk
	* see Ev_MT_BLL_PPPoE_GetStatisInfo_Req
	*/
	MESSAGE(Ev_MT_BLL_PPPoE_GetStatisInfo_Rsp)
	BODY(mt::TPPPoEStatis, pppoestatis)

	/*<<��ȡĬ��·������>>
	*BODY ����
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_BLL_ROUTE_GetDefaultRoute_Req
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_GetDefaultRoute_Req)

 
	/*<<��ȡĬ��·����Ӧ>>
	*BODY ��TRouteItemInfo ·����Ϣ
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_BLL_ROUTE_GetDefaultRoute_Rsp
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_GetDefaultRoute_Rsp)
	BODY(mt::TRouteItemInfo, TRouteItemInfo )

	
	/*<<��ȡ����·������>>
	*BODY ����
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_BLL_ROUTE_GetAllRoute_Rsp
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_GetAllRoute_Req)

 
	/*<<��ȡ����·��������Ӧ>>
	*BODY ��TRouteItemInfoList ·���б���Ϣ
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_BLL_ROUTE_GetAllRoute_Req
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_GetAllRoute_Rsp)
	BODY(mt::TRouteItemInfoList, TRouteItemInfoList )


    /*<<����һ��·������>>
	*BODY ��tRouteItemInfo ����·����Ϣ
	*���䷽��sdk->dispatch->mtservice
	* see Ev_MT_BLL_ROUTE_AddRouteResult_Rsp
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_AddRoute_Req)
	BODY(mt::TRouteItemInfo, tRouteItemInfo )


	/*<<����һ��·��������Ӧ>>
	*BODY ��result: true:��ӳɹ� false:���ʧ��
    *BODY ��tRouteItemInfo ����·����Ϣ
	*���䷽��mtservice->dispatch->sdk
	* see Ev_MT_BLL_ROUTE_AddRoute_Req
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_AddRouteResult_Rsp)
	BODY(mt::TBOOL32, result )
    BODY(mt::TRouteItemInfo, tRouteItemInfo )


    /*<<����һ��·��֪ͨ>>
	*BODY ��tRouteItemInfo ����·����Ϣ
    *���䷽��mtservice->dispatch->sdk
    * see
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_AddRoute_Ntf)
    BODY(mt::TRouteItemInfo, tRouteItemInfo )



    /*<<ɾ��һ��·������>>
	*BODY ��tRouteItemInfo ɾ����·����Ϣ
	*���䷽��sdk->dispatch->mtservice
	* see Ev_MT_BLL_ROUTE_DelRouteResult_Rsp
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_DelRoute_Req)
	BODY(mt::TRouteItemInfo, tRouteItemInfo )

 
	/*<<ɾ��һ��·��������Ӧ>>
	*BODY ��result: true:ɾ���ɹ� false:ɾ��ʧ��
    *BODY ��tRouteItemInfo ɾ����·����Ϣ
	*���䷽��mtservice->dispatch->sdk
	* see Ev_MT_BLL_ROUTE_DelRoute_Req
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_DelRouteResult_Rsp)
	BODY(mt::TBOOL32, result )
    BODY(mt::TRouteItemInfo, tRouteItemInfo )


    /*<<ɾ��һ��·��֪ͨ>>
    *BODY ��tRouteItemInfo ɾ����·����Ϣ
	*���䷽��mtservice->dispatch->sdk
	* see Ev_MT_BLL_ROUTE_DelRoute_Cmd
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_DelRoute_Ntf)
    BODY(mt::TRouteItemInfo, tRouteItemInfo )




    /*<<�޸�һ��·������>>
	*BODY ��oldRouteItemInfo Ҫ�޸ĵ�·����Ϣ
            newRouteItemInfo �޸ĺ��·����Ϣ
	*���䷽��sdk->dispatch->mtservice
	* see Ev_MT_BLL_ROUTE_ModifyRouteResult_Rsp
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_ModifyRoute_Req)
    BODY(mt::TRouteItemInfo, oldRouteItemInfo )
    BODY(mt::TRouteItemInfo, newRouteItemInfo )

 
	/*<<�޸�һ��·��������Ӧ>>
	*BODY ��result      true:�޸ĳɹ� false:�޸�ʧ��
    *       oldRouteItemInfo Ҫ�޸ĵ�·����Ϣ
    *       newRouteItemInfo �޸ĺ��·����Ϣ
	*���䷽��mtservice->dispatch->sdk
	* see Ev_MT_BLL_ROUTE_ModifyRoute_Req
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_ModifyRouteResult_Rsp)
	BODY(mt::TBOOL32, result )
    BODY(mt::TRouteItemInfo, oldRouteItemInfo )
    BODY(mt::TRouteItemInfo, newRouteItemInfo )


    /*<<�޸�һ��·��֪ͨ>>
	*BODY ��oldRouteItemInfo Ҫ�޸ĵ�·����Ϣ
    *       newRouteItemInfo �޸ĺ��·����Ϣ
	*���䷽��mtservice->dispatch->sdk
	*/
	MESSAGE(Ev_MT_BLL_ROUTE_ModifyRoute_Ntf)
    BODY(mt::TRouteItemInfo, oldRouteItemInfo )
    BODY(mt::TRouteItemInfo, newRouteItemInfo )




    /*<<Wifi ����ģʽ��Ϣ��ѯ>>
	*BODY ����
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_BLL_WIFI_GetWorkMode_Rsp
	*/
	MESSAGE(Ev_MT_BLL_WIFI_GetWorkMode_Req)

	
	/*<<Wifi ����ģʽ��Ϣ��Ӧ>>
	* ----------------------------------------------------------
	* ��������TWifiWorkMode��	��ǰWifi����ģʽ
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_BLL_WIFI_GetWorkMode_Req
	*/
	MESSAGE(Ev_MT_BLL_WIFI_GetWorkMode_Rsp)
	BODY(mt::TWifiWorkMode, TWifiWorkMode)




	/*<<Wifi �ȵ�ɨ������>>
	*BODY ����
	*���䷽��mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_WIFI_ScanResult_Rsp
	*/
	MESSAGE(Ev_MT_BLL_WIFI_StartScan_Req)


	/*<<Wifi �ȵ�ɨ����֪ͨ>>
	* ----------------------------------------------------------
	* ������wifiscanresultlist��	ɨ�赽��ѡWIFI����б�
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice->mtsdk
	* see Ev_MT_BLL_WIFI_StartScan_Req
	*/
	MESSAGE(Ev_MT_BLL_WIFI_ScanResult_Rsp)
	BODY(mt::TWifiScanResultList, wifiscanresultlist)

	/*<<������������Wifi����ģʽ����>>
	* ----------------------------------------------------------
	* ������TWifiWorkMode
	* ----------------------------------------------------------
	*���䷽��mtmfgtest->mtsdk->mtservice
	* see 
	*/
	MESSAGE(Ev_MT_BLL_Mtmfgtest_SetWifiWorkModeCfg_Cmd)
	BODY(mt::TBOOL32, bStart)

	/*<<Wifi �ȵ���������>>
	* ----------------------------------------------------------
	* ������wificonnparam��	wifi�������Ӳ���
	* ----------------------------------------------------------
	*���䷽��mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_WIFI_LinkState_Ntf
	*/
	MESSAGE(Ev_MT_BLL_WIFI_Connect_Cmd)
	BODY(mt::TWifiConnParam, wificonnparam)


	/*<<Wifi �ȵ�Ͽ�����>>
	* ----------------------------------------------------------
	* ��������
	* ----------------------------------------------------------
	*���䷽��mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_WIFI_LinkState_Ntf	      
	*/
	MESSAGE(Ev_MT_BLL_WIFI_Disconnect_Cmd)
	
	

    /*<<Wifi ����״̬��ѯ>>
	*BODY ����
	*���䷽��mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_WIFI_LinkState_Ntf
	*/
	MESSAGE(Ev_MT_BLL_WIFI_GetLinkState_Req)



    /*<<Wifi ����״̬��ѯ֪ͨ>>
	* ----------------------------------------------------------
	* ������TWifiCurDetailInfo��	Wifi��������״̬��Ϣ
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_WIFI_GetLinkState_Req
	*/
	MESSAGE(Ev_MT_BLL_WIFI_LinkState_Rsp)
	BODY(mt::TWifiCurDetailInfo, wificurdetailinfo)

	
	/*<<Wifi �ȵ�����״̬֪ͨ>>
	* ----------------------------------------------------------
	* ������wificurdetailinfo��	Wifi�������ӽ����Ϣ
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice->mtsdk
	* see Ev_MT_BLL_WIFI_Connect_Cmd, Ev_MT_BLL_WIFI_Disconnect_Cmd
	*/
	MESSAGE(Ev_MT_BLL_WIFI_LinkState_Ntf)
	BODY(mt::TWifiCurDetailInfo, wificurdetailinfo)

	 /*<<Wifi ������������>>
	* ----------------------------------------------------------
	* ������TU32��	wifi�ȵ�id
	* ----------------------------------------------------------
	*���䷽��mtsdk->dispatch->mtservice
	* see Ev_MT_BLL_WIFI_Forget_Rsp	      
	*/
	MESSAGE(Ev_MT_BLL_WIFI_Forget_Req)
	BODY(mt::TU32, hotspotId)

     /*<<Wifi ����������Ӧ>>
	* ----------------------------------------------------------
	* ������TBOOL32��	���ý��
	* ������TU32��		wifi�ȵ�id
	* ----------------------------------------------------------
	*���䷽��mtservice->dispatch->mtsdk
	* see Ev_MT_BLL_WIFI_Forget_Req	      
	*/
	MESSAGE(Ev_MT_BLL_WIFI_Forget_Rsp)
    BODY(mt::TBOOL32, result)
	BODY(mt::TU32, hotspotId)
	
	/*<<Wifi ��ȡ��ǰ���ӵ�Wifi�ͻ�����������>>
	* ----------------------------------------------------------
	* �������� 
	* ----------------------------------------------------------
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_BLL_WIFI_GetModClientProperty_Rsp
	*/
	MESSAGE(Ev_MT_BLL_WIFI_GetModClientProperty_Req)
	
	
	/*<<Wifi ��ȡ��ǰ���ӵ�Wifi�ͻ�����������֪ͨ>>
	* ----------------------------------------------------------
	* ������TWifiConfiguration:    Wifi���ӵĿͻ���������Ϣ 
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_BLL_WIFI_ModClientProperty_Cmd
	*/
	MESSAGE(Ev_MT_BLL_WIFI_GetModClientProperty_Rsp)
	BODY(mt::TWifiConfiguration, TWifiConfiguration)
	
	
	/*<<Wifi ��ȡ��ǰ���ӵ�Wifi�ͻ�����ϸ��Ϣ����>>
	* ----------------------------------------------------------
	* �������� 
	* ----------------------------------------------------------
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_BLL_WIFI_GetWifiCurConnectedInfo_Rsp
	*/
	MESSAGE(Ev_MT_BLL_WIFI_GetWifiCurConnectedInfo_Req)
	
	
	/*<<Wifi ��ȡ��ǰ���ӵ�Wifi�ͻ�����ϸ��Ϣ����֪ͨ>>
	* ----------------------------------------------------------
	* ������TWifiCurDetailInfo:    Wifi���ӵĿͻ�����ϸ��Ϣ 
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_BLL_WIFI_GetWifiCurConnectedInfo_Req
	*/
	MESSAGE(Ev_MT_BLL_WIFI_GetWifiCurConnectedInfo_Rsp)
	BODY(mt::TWifiCurDetailInfo, TWifiCurDetailInfo)
	
	
	/*<<Wifi ��ǰ���ӵ�Wifiͳ����Ϣ��ѯ����>>
	* ----------------------------------------------------------
	* ��������
	* ----------------------------------------------------------
	*���䷽��mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_WIFI_GetCurWifiStatisInfo_Rsp
	*/
	MESSAGE(Ev_MT_BLL_WIFI_GetCurWifiStatisInfo_Req)
 
	
	/*<<Wifi �ȵ����ӽ��״̬��Ӧ>>
	* ----------------------------------------------------------
	* ������wifistatisinfo��	��ǰWifi��ͳ����Ϣ ���ź�ǿ�ȣ��������ܴ���
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice->mtsdk
	* see Ev_MT_BLL_WIFI_GetCurWifiStatisInfo_Req
	*/
	MESSAGE(Ev_MT_BLL_WIFI_GetCurWifiStatisInfo_Rsp)
	BODY(mt::TWifiStatisInfo, wifistatisinfo)

	/*<<��ȡ����Ͷ����Ϣ����>>
	*���䷽��mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_WIFI_GetWirelessScreen_Rsp
	*/
	MESSAGE(Ev_MT_BLL_WIFI_GetWirelessScreen_Req)

	/*<<��ȡ����Ͷ����Ϣ������Ӧ>>
	*BODY ��TWifiWirelessScreenInfo  ����Ͷ����Ϣ
	*���䷽��net->dispatch->mtservice->mtsdk
	* see Ev_MT_BLL_WIFI_GetWirelessScreen_Req
	*/
	MESSAGE(Ev_MT_BLL_WIFI_GetWirelessScreen_Rsp)
	BODY(mt::TWifiWirelessScreenInfo, TWifiWirelessScreenInfo)

	/*<<������ֹͣ����Ͷ������>>
	*BODY ��bStart  true:����  false:ֹͣ
	*���䷽��mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_WIFI_WirelessScreenStateChange_Ntf
	*/
	MESSAGE(Ev_MT_BLL_WIFI_SetWirelessScreen_Cmd)
	BODY(mt::TBOOL32, bStart)

	/*<<����Ͷ��״̬�ı�֪ͨ>>
	* ----------------------------------------------------------
	* ������TWifiWirelessScreenInfo������Ͷ����Ϣ
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice->mtsdk
	* see Ev_MT_BLL_WIFI_SetWirelessScreen_Cmd
	*/
	MESSAGE(Ev_MT_BLL_WIFI_WirelessScreenStateChange_Ntf)
	BODY(mt::TWifiWirelessScreenInfo, TWifiWirelessScreenInfo)	

    /*<<MobileData  �ƶ��������Ӻ���ϸ״̬֪ͨ>>
	* ----------------------------------------------------------
	* ��������TMobileDataCurDetailInfo��	��ǰ�ƶ����ݵ���ϸ��Ϣ
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_BLL_MOBILEDATA_ChangeWorkMode_Cmd
	*/
	MESSAGE(Ev_MT_BLL_MOBILEDATA_LinkState_Ntf)
	BODY(mt::TMobileDataCurDetailInfo, TMobileDataCurDetailInfo)




    /*<<MobileData ����ģʽ��Ϣ��ѯ>>
	*BODY ����
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_BLL_MOBILEDATA_GetWorkMode_Rsp
	*/
	MESSAGE(Ev_MT_BLL_MOBILEDATA_GetWorkMode_Req)

	
	/*<<MobileData  ����ģʽ��Ϣ��ѯ��Ӧ>>
	* ----------------------------------------------------------
	* ��������TWifiWorkMode��	��ǰWifi����ģʽ
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_BLL_MOBILEDATA_GetWorkMode_Req
	*/
	MESSAGE(Ev_MT_BLL_MOBILEDATA_GetWorkMode_Rsp)
	BODY(mt::TMobileDataWorkMode, TMobileDataWorkMode)



	/*<<MobileData ��ѯ�ƶ��������Ӻ���ϸ��Ϣ>>
	* ----------------------------------------------------------
	* ������
	* ----------------------------------------------------------
	*���䷽��mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_MOBILEDATA_GetDetailInfo_Rsp
	*/
	MESSAGE(Ev_MT_BLL_MOBILEDATA_GetDetailInfo_Req)

	
	/*<<MobileData  �ƶ��������Ӻ���ϸ��Ϣ��Ӧ>>
	* ----------------------------------------------------------
	* ������mobiledatacurdetailinfo   ��ǰ�ƶ����ݵ���ϸ��Ϣ
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice->mtsdk
	* see Ev_MT_BLL_MOBILEDATA_GetDetailInfo_Req
	*/
	MESSAGE(Ev_MT_BLL_MOBILEDATA_GetDetailInfo_Rsp)
	BODY(mt::TMobileDataCurDetailInfo, mobiledatacurdetailinfo)


	/*<<MobileData ��ǰ���ӵ��ƶ�����ͳ����Ϣ��ѯ����>>
	* ----------------------------------------------------------
	* ��������
	* ----------------------------------------------------------
	*���䷽��mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_MOBILEDATA_GetCurStatisInfo_Rsp
	*/
	MESSAGE(Ev_MT_BLL_MOBILEDATA_GetCurStatisInfo_Req)
 
	
	/*<<MobileData ��ǰ���ӵ��ƶ�����ͳ����Ϣ��ѯ��Ӧ>>
	* ----------------------------------------------------------
	* ������mobiledatastatisinfo   ��ǰWifi��ͳ����Ϣ ���ź�ǿ�ȣ��������ܴ���
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice->mtsdk
	* see Ev_MT_BLL_MOBILEDATA_GetCurStatisInfo_Req
	*/
	MESSAGE(Ev_MT_BLL_MOBILEDATA_GetCurStatisInfo_Rsp)
	BODY(mt::TMobileDataStatisInfo, mobiledatastatisinfo)



	/*<<IP/MAC��ͻ ״̬֪ͨ>>
	* ----------------------------------------------------------
	*���� ��netconflictedinfo    ��ͻ��Ϣ
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice->mtsdk
	* see 
	*/
	MESSAGE(Ev_MT_BLL_NET_IPMACConflicted_Ntf)
	BODY(mt::TNetConfilictedInfo, netconflictedinfo )


	/*<<Ping�� ��������>>
	* ----------------------------------------------------------
	* ������pingtestparam    PING������Ϣ
	* ----------------------------------------------------------
	*���䷽��mtsdk->mtservice->dispatch->net
	* see Ev_MT_BLL_NET_PingTestResult_Rsp
	*/
	MESSAGE(Ev_MT_BLL_NET_PingTest_Req)
	BODY(mt::TPingTestParam, pingtestparam )
	

	/*<<Ping�� ��Ӧ���>>
	* ----------------------------------------------------------
	* ������pingresult   PING�����Ϣ
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice->mtsdk
	* see Ev_MT_BLL_NET_PingTest_Req
	*/
	MESSAGE(Ev_MT_BLL_NET_PingTestResult_Rsp)
	BODY(mt::TPingResult, pingresult )


	/*<<��ѯDNS��Ӧ��IP��Ϣ����>>
	* ----------------------------------------------------------
	* ������TDNSNameToIpInfo Ҫ��ѯ��DNS��Ϣ
	* ----------------------------------------------------------
	*���䷽��sdk->mtservice->dispatch->net
	* see Ev_MT_BLL_Ethernet_GetIpByDNSInfo_Rsp
	*/
	MESSAGE(Ev_MT_BLL_Ethernet_GetIpByDNSInfo_Req)
	BODY(mt::TDNSNameToIpInfo, TDNSNameToIpInfo)
 
	
	/*<<��ѯDNS��Ӧ��IP��Ϣ������Ӧ>>
	* ----------------------------------------------------------
	* ������TDNSNameToIpResult��	DNS��ѯ����IP�����Ϣ
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice->sdk
	* see Ev_MT_BLL_Ethernet_GetIpByDNSInfo_Req
	*/
	MESSAGE(Ev_MT_BLL_Ethernet_GetIpByDNSInfo_Rsp)
	BODY(mt::TDNSNameToIpResult, TDNSNameToIpResult)



    /*<<���õ�ǰ����ʱ����Ϣ>>
	*BODY ��  tmttime ʱ����Ϣ  
	*���䷽��sdk->dispatch->mtservice
	* see Ev_MT_BLL_SetSysDataTimeResult_Rsp
	*/
	MESSAGE(Ev_MT_BLL_SetSysDataTime_Req)
	BODY(mt::TMTTime, tmttime )
	
	
	/*<<���õ�ǰ����ʱ����Ϣ��Ӧ>>
	*BODY ��   result ���ý�� 0�ɹ� ����������
	           tmttime ʱ����Ϣ 
	*���䷽��mtservice->dispatch->sdk
	* see Ev_MT_BLL_SetSysDataTime_Req
	*/
	MESSAGE(Ev_MT_BLL_SetSysDataTimeResult_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTTime, tmttime )


    /*<<���õ�ǰ����ʱ��֪ͨ>>
	*BODY ��   tmttime ʱ����Ϣ 
	*���䷽��mtservice->dispatch->sdk
	* see
	*/
	MESSAGE(Ev_MT_BLL_SetSysDataTime_Ntf)
	BODY(mt::TMTTime, tmttime )


	
	
	/*<<��ѯ��ǰ����ʱ����Ϣ>>
	*BODY ��    
	*���䷽��sdk->dispatch->mtservice
	* see Ev_MT_BLL_GetSysDataTime_Rsp
	*/
	MESSAGE(Ev_MT_BLL_GetSysDataTime_Req)
	
	
	/*<<��ѯ��ǰ����ʱ����Ϣ��Ӧ>>
	*BODY ��result ��ȡ��� 0�ɹ� ����������
	        tmttime ʱ����Ϣ 
	*���䷽��mtservice->dispatch->sdk
	* see Ev_MT_BLL_GetSysDataTime_Req
	*/
	MESSAGE(Ev_MT_BLL_GetSysDataTime_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTTime, tmttime )



	/*<<����NTP�������ر�״̬>>
	*BODY ��  TMTNTPInfo NTP������״̬ 
	*���䷽��sdk->dispatch->mtservice
	* see Ev_MT_BLL_SetNTPSvrParamResult_Rsp
	*/
	MESSAGE(Ev_MT_BLL_SetNTPSvrParam_Req)
	BODY(mt::TMTNTPInfo, TMTNTPInfo )
	
	
	/*<<����NTP�������ر�״̬��Ӧ>>
	*BODY ��   result ���ý�� 0�ɹ� ����������
	           TMTNTPInfo NTP������Ϣ 
	*���䷽��mtservice->dispatch->sdk
	* see Ev_MT_BLL_SetNTPSvrParam_Req
	*/
	MESSAGE(Ev_MT_BLL_SetNTPSvrParamResult_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTNTPInfo, TMTNTPInfo )



    /*<<����NTP�������ر�״̬֪ͨ>>
	*BODY ��   TMTNTPInfo NTP������Ϣ 
	*���䷽��mtservice->dispatch->sdk
	* see
	*/
	MESSAGE(Ev_MT_BLL_SetNTPSvrParam_Ntf)
	BODY(mt::TMTNTPInfo, TMTNTPInfo )

	
	
	/*<<��ѯ��ǰNTP������״̬����>>
	*BODY ��    
	*���䷽��sdk->dispatch->mtservice
	* see Ev_MT_BLL_GetNTPSvrParam_Rsp
	*/
	MESSAGE(Ev_MT_BLL_GetNTPSvrParam_Req)
	
	
	/*<<��ѯ��ǰNTP������״̬��Ӧ>>
	*BODY ��result ��ȡ��� 0�ɹ� ����������
	        TMTNTPInfo NTP������Ϣ 
	*���䷽��mtservice->dispatch->sdk
	* see Ev_MT_BLL_GetNTPSvrParam_Req
	*/
	MESSAGE(Ev_MT_BLL_GetNTPSvrParam_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTNTPInfo, TMTNTPInfo )




    /*<<Telnet������/ֹͣ����>>
	*BODY ��  bStart  true:����  false:ֹͣ  
	*���䷽��sdk->dispatch->mtservice
	* see Ev_MT_BLL_Net_TelnetService_Ntf
	*/
	MESSAGE(Ev_MT_BLL_Net_TelnetService_Cmd)
	BODY(mt::TBOOL32, bStart )
	
	
	/*<<Telnet������/ֹͣ״̬֪ͨ>>
	*BODY ��reason    0:�ɹ�, 1,����ʧ�ܣ�2,ֹͣʧ��, ����������
	        bStarted  ��ǰ״̬ true:����״̬  false:ֹͣ״̬  
	*���䷽��mtservice->dispatch->sdk
	* see Ev_MT_BLL_Net_TelnetService_Cmd
	*/
	MESSAGE(Ev_MT_BLL_Net_TelnetService_Ntf)
	BODY(mt::TU32, reason)
	BODY(mt::TBOOL32, bStarted )

	
	/*<<Ftp������/ֹͣ����>>
	*BODY ��  bStart  true:����  false:ֹͣ  
	*���䷽��sdk->dispatch->mtservice
	* see Ev_MT_BLL_Net_FtpService_Ntf
	*/
	MESSAGE(Ev_MT_BLL_Net_FtpService_Cmd)
	BODY(mt::TBOOL32, bStart )
	
	
	/*<<Ftp������/ֹͣ״̬֪ͨ>>
	*BODY ��reason    0:�ɹ�, 1,����ʧ�ܣ�2,ֹͣʧ��, ����������
	        bStarted  ��ǰ״̬ true:����״̬  false:ֹͣ״̬  
	*���䷽��mtservice->dispatch->sdk
	* see Ev_MT_BLL_Net_FtpService_Cmd
	*/
	MESSAGE(Ev_MT_BLL_Net_FtpService_Ntf)
	BODY(mt::TU32, reason)
	BODY(mt::TBOOL32, bStarted )

	
	/*<<Http������/ֹͣ����>>
	*BODY ��  bStart  true:����  false:ֹͣ  
	*���䷽��sdk->dispatch->mtservice
	* see Ev_MT_BLL_Net_HttpService_Ntf
	*/
	MESSAGE(Ev_MT_BLL_Net_HttpService_Cmd)
	BODY(mt::TBOOL32, bStart )
	
	
	/*<<Http������/ֹͣ״̬֪ͨ>>
	*BODY ��reason    0:�ɹ�, 1,����ʧ�ܣ�2,ֹͣʧ��, ����������
	        bStarted  ��ǰ״̬ true:����״̬  false:ֹͣ״̬  
	*���䷽��mtservice->dispatch->sdk
	* see Ev_MT_BLL_Net_HttpService_Cmd
	*/
	MESSAGE(Ev_MT_BLL_Net_HttpService_Ntf)
	BODY(mt::TU32, reason)
	BODY(mt::TBOOL32, bStarted )



    /*<<����TimeZone��Ϣ>>
	*BODY ��  TMTTimeZoneInfo ʱ����Ϣ 
	*���䷽��sdk->dispatch->mtservice
	* see Ev_MT_BLL_SetTimeZone_Rsp
	*/
	MESSAGE(Ev_MT_BLL_SetTimeZone_Req)
	BODY(mt::TMTTimeZoneInfo, TMTTimeZoneInfo )
	
	
	/*<<����TimeZone��Ϣ��Ӧ>>
	*BODY ��   result ���ý�� 0�ɹ� ����������
	           TMTTimeZoneInfo ʱ����Ϣ 
	*���䷽��mtservice->dispatch->sdk
	* see Ev_MT_BLL_SetTimeZone_Req
	*/
	MESSAGE(Ev_MT_BLL_SetTimeZone_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTTimeZoneInfo, TMTTimeZoneInfo )
	
	
	/*<<��ѯ��ǰTimeZone��Ϣ����>>
	*BODY ��    
	*���䷽��sdk->dispatch->mtservice
	* see Ev_MT_BLL_GetTimeZone_Rsp
	*/
	MESSAGE(Ev_MT_BLL_GetTimeZone_Req)
	
	
	/*<<��ѯ��ǰTimeZone��Ϣ��Ӧ>>
	*BODY ��result ��ȡ��� 0�ɹ� ����������
	        TMTTimeZoneInfo ʱ����Ϣ  
	*���䷽��mtservice->dispatch->sdk
	* see Ev_MT_BLL_GetTimeZone_Req
	*/
	MESSAGE(Ev_MT_BLL_GetTimeZone_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTTimeZoneInfo, TMTTimeZoneInfo )



    /*<<����Ftp/Telnet�˺���Ϣ>>
	*BODY ��  TMTFtpTelnetAccountInfo �˺���Ϣ 
	*���䷽��sdk->dispatch->mtservice
	* see Ev_MT_BLL_SetFtpTelnetAccountInfo_Rsp
	*/
	MESSAGE(Ev_MT_BLL_SetFtpTelnetAccountInfo_Req)
	BODY(mt::TMTFtpTelnetAccountInfo, TMTFtpTelnetAccountInfo )
	
	
	/*<<����Ftp/Telnet�˺���Ϣ��Ӧ>>
	*BODY ��   result ���ý�� 0�ɹ� ����������
	           TMTFtpTelnetAccountInfo �˺���Ϣ 
	*���䷽��mtservice->dispatch->sdk
	* see Ev_MT_BLL_SetFtpTelnetAccountInfo_Req
	*/
	MESSAGE(Ev_MT_BLL_SetFtpTelnetAccountInfo_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTFtpTelnetAccountInfo, TMTFtpTelnetAccountInfo )

    /*<<���������л���Ϣ֪ͨ>>
	*BODY ��   TEthnetCfg ��̫����Ϣ 
	*���䷽��mtservice->dispatch->sdk
	* see 
	*/
    MESSAGE(Ev_MT_BLL_HD_EthnetCardChange_Ntf)
    BODY(mt::TEthnetCfg, TEthnetCfg)

	/*<<�����޶�IP����������>>
	*BODY ��tLimitedIpCfg �޶�IP��������Ϣ
    *���䷽��sdk->dispatch->mtservice
    * see Ev_MT_BLL_Net_SetLimitedIpCfg_Ntf
    */
	MESSAGE(Ev_MT_BLL_Net_SetLimitedIpCfg_Cmd)
	BODY(mt::TLimitedIpCfg, TLimitedIpCfg)

	/*<<�����޶�IP������֪ͨ>>
	*BODY ��tLimitedIpCfg �޶�IP��������Ϣ
    *���䷽��sdk->dispatch->mtservice
    * see Ev_MT_BLL_Net_SetLimitedIpCfg_Ntf
    */
	MESSAGE(Ev_MT_BLL_Net_SetLimitedIpCfg_Ntf)
	BODY(mt::TBOOL32, result)

	/*<<����һ���޶�ip������>>
	*BODY ��TLimitedIpItemInfo �����޶�IP����Ϣ
    *���䷽��mtservice->dispatch->net
    * see Ev_MT_BLL_Net_AddLimitedIpResult_Rsp
    */
	MESSAGE(Ev_MT_BLL_Net_AddLimitedIp_Req)
	BODY(mt::TLimitedIpItemInfo, TLimitedIpItemInfo)

	/*<<����һ���޶�ip����Ӧ>>
	*BODY ��result: true:��ӳɹ� false:���ʧ��
	*BODY ��TLimitedIpItemInfo �����޶�IP����Ϣ
    *���䷽��mtservice->dispatch->net
    * see Ev_MT_BLL_Net_AddLimitedIp_Req
    */
	MESSAGE(Ev_MT_BLL_Net_AddLimitedIpResult_Rsp)
	BODY(mt::TBOOL32, result)
	BODY(mt::TLimitedIpItemInfo, TLimitedIpItemInfo)

	/*<<����һ���޶�ip��֪ͨ>>
	*BODY ��TLimitedIpItemInfo �����޶�IP����Ϣ
    *���䷽��mtservice->dispatch->net
    */
	MESSAGE(Ev_MT_BLL_Net_AddLimitedIpResult_Ntf)
	BODY(mt::TLimitedIpItemInfo, TLimitedIpItemInfo)

	/*<<ɾ��һ���޶�ip������>>
	*BODY ��TLimitedIpItemInfo Ҫɾ�����޶�IP����Ϣ
    *���䷽��mtservice->dispatch->net
    * see Ev_MT_BLL_FtpTelnet_DelLimitedIp_Rsp
    */
	MESSAGE(Ev_MT_BLL_Net_DelLimitedIp_Req)
	BODY(mt::TLimitedIpItemInfo, TLimitedIpItemInfo)

	/*<<ɾ��һ���޶�ip����Ӧ>>
	*BODY ��result: true:ɾ���ɹ� false:ɾ��ʧ��
	*BODY ��TLimitedIpItemInfo Ҫɾ�����޶�IP����Ϣ
    *���䷽��mtservice->dispatch->net
    * see Ev_MT_BLL_FtpTelnet_DelLimitedIp_Req
    */
	MESSAGE(Ev_MT_BLL_Net_DelLimitedIpResult_Rsp)
	BODY(mt::TBOOL32, result)
	BODY(mt::TLimitedIpItemInfo, TLimitedIpItemInfo)

	/*<<ɾ��һ���޶�ip��֪ͨ>>
	*BODY ��TLimitedIpItemInfo Ҫɾ�����޶�IP����Ϣ
    *���䷽��mtservice->dispatch->net
    */
	MESSAGE(Ev_MT_BLL_Net_DelLimitedIpResult_Ntf)
	BODY(mt::TLimitedIpItemInfo, TLimitedIpItemInfo)

	/*<<�޸�һ���޶�ip������>>
	*BODY ��oldLimitedIpItemInfo �޸�ǰ���޶�IP����Ϣ
	*BODY ��newLimitedIpItemInfo �޸ĺ���޶�IP����Ϣ
    *���䷽��mtservice->dispatch->net
    * see Ev_MT_BLL_FtpTelnet_ModLimitedIp_Rsp
    */
	MESSAGE(Ev_MT_BLL_Net_ModLimitedIp_Req)
	BODY(mt::TLimitedIpItemInfo, oldLimitedIpItemInfo)
	BODY(mt::TLimitedIpItemInfo, newLimitedIpItemInfo)

	/*<<�޸�һ���޶�ip����Ӧ>>
	*BODY ��result: true:�޸ĳɹ� false:�޸�ʧ��
	*BODY ��oldLimitedIpItemInfo �޸�ǰ���޶�IP����Ϣ
	*BODY ��newLimitedIpItemInfo �޸ĺ���޶�IP����Ϣ
    *���䷽��mtservice->dispatch->net
    * see Ev_MT_BLL_FtpTelnet_ModLimitedIp_Req
    */
	MESSAGE(Ev_MT_BLL_Net_ModLimitedIpResult_Rsp)
	BODY(mt::TBOOL32, result)
	BODY(mt::TLimitedIpItemInfo, oldLimitedIpItemInfo)
	BODY(mt::TLimitedIpItemInfo, newLimitedIpItemInfo)

	/*<<�޸�һ���޶�ip��֪ͨ>>
	*BODY ��oldLimitedIpItemInfo �޸�ǰ���޶�IP����Ϣ
	*BODY ��newLimitedIpItemInfo �޸ĺ���޶�IP����Ϣ
    *���䷽��mtservice->dispatch->net
    * see 
    */
	MESSAGE(Ev_MT_BLL_Net_ModLimitedIpResult_Ntf)
	BODY(mt::TLimitedIpItemInfo, oldLimitedIpItemInfo)
	BODY(mt::TLimitedIpItemInfo, newLimitedIpItemInfo)

    /*<<����ָ���ӿ�Ethernet��������Ϣ���֪ͨ>>
	*BODY ��result  0�ɹ�  ����������
	        ethernetid  ����ʱָ��������ID
	*���䷽��mtservice->dispatch->sdk
	* see Ev_MT_Ethernet_SetIpParam_Cmd
	*/
    MESSAGE(Ev_MT_BLL_Ethernet_SetIpParamResult_Ntf)
    BODY(mt::TU32, result)
    BODY(mt::TU32, ethernetid)

	 /*<<֪ͨ�ն�ˢ�¶�ȡLICENSE>>
	 *���䷽��mtservice<-dispatch<-sdk
	*/
    MESSAGE(Ev_MT_BLL_ReadLicense_Cmd)


	 /*<<�ն˶�ȡLICENSE���֪֪ͨͨ>>
	 *���䷽��mtservice->dispatch->sdk
	*/
    MESSAGE(Ev_MT_BLL_ReadLicense_Ntf)
	BODY(mt::TLicense, tLicense)
	
	
	/*<<��ʼ��ر�HID��д>>
    *���䷽��mt->dispatch->net
    */
    MESSAGE(Ev_MT_BLL_StartHID_Cmd)
    BODY(mt::TBOOL32, bstart)

    /*<<HID���ݴ���>>
    *���䷽��mt->dispatch->net
    */
    MESSAGE(Ev_MT_BLL_HIDMt2Net_Cmd)
    BODY(mt::TString, tHIDinfo)

    /*<<HID���ݴ���>>
    *���䷽��net->dispatch->mt
    */
    MESSAGE(Ev_MT_BLL_HIDNet2Mt_Ntf)
    BODY(mt::TBytes, tHIDinfo)

	
#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(NETWORK) = EVSEG_BLL_NETWORK_END
};
#endif

#define Is_BLL_Network_Msg(m) ((m) >= EV_BLL_BGN(NETWORK) && (m) <= EV_BLL_END(NETWORK))

#endif