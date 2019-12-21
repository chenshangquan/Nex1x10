#ifndef _MTNETMSG_H_
#define _MTNETMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMtNetMsg
{
    EV_BGN(NETMANAGE) = EVSEG_NETWORK_BGN,
#endif//_MESSAGE_HELP_

	/*<<����ָ���ӿ�Ethernet����������ģʽ(ȫ˫��/��˫����Ϣ��)>>
	*BODY ��ethernetid  ָ������ID
	        EmEthnetWorkMode ����ģʽ
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_Ethernet_SetEthWorkModeListCfgResult_Ntf
	*/
	MESSAGE(Ev_MT_Ethernet_SetEthWorkModeListCfg_Cmd)
	BODY(mt::TU32, ethernetid)
	BODY(mt::TU32, EmEthnetWorkMode)
	
	/*<<����ָ���ӿ�Ethernet����������ģʽ���֪ͨ(ȫ˫��/��˫����Ϣ��)>>
	*BODY ��result  0�ɹ�  ����������
	        ethernetid  ����ʱָ��������ID
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_Ethernet_SetEthWorkModeListCfg_Cmd
	*/
	MESSAGE(Ev_MT_Ethernet_SetEthWorkModeListCfgResult_Ntf)
	BODY(mt::TU32, result)
	BODY(mt::TU32, ethernetid)
	
	/*<<��ȡ����Ethernet����������ģʽ (ȫ˫��/��˫����Ϣ��)>>
	*BODY ��null
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_Ethernet_GetEthWorkModeListCfg_Rsp
	*/
	MESSAGE(Ev_MT_Ethernet_GetEthWorkModeListCfg_Req)

	
	/*<<��ȡ����Ethernet����������ģʽ���֪ͨ(ȫ˫��/��˫����Ϣ��)>>
	*BODY ��result  0�ɹ�  ����������
	        TEthnetWorkModeList ������������ģʽ�б���Ϣ
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_Ethernet_GetEthWorkModeListCfg_Req
	*/
	MESSAGE(Ev_MT_Ethernet_GetEthWorkModeListCfg_Rsp)
	BODY(mt::TEthnetWorkModeList, )
	
	
    
	/*<<����ָ���ӿ�Ethernet��������Ϣ>>
	*BODY ��ethernetid  ָ������ID
	        EmEthnetParamType ������������
	        TEthnetInterfaceParam  ����IP/mask/mac��Ϣ
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_Ethernet_SetIpParamResult_Ntf
	*/
	MESSAGE(Ev_MT_Ethernet_SetIpParam_Cmd)
	BODY(mt::TU32, ethernetid)
	BODY(mt::TU32, EmEthnetParamType)
	BODY(mt::TEthnetInterfaceParam, TEthnetInterfaceParam)


	/*<<����ָ���ӿ�Ethernet��������Ϣ���֪ͨ>>
	*BODY ��result  0�ɹ�  ����������
	        ethernetid  ����ʱָ��������ID
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_Ethernet_SetIpParam_Cmd
	*/
	MESSAGE(Ev_MT_Ethernet_SetIpParamResult_Ntf)
	BODY(mt::TU32, result)
	BODY(mt::TU32, ethernetid)


	/*<<ɾ��ָ���ӿ�Ethernet ������Ϣ>>
	*BODY ��ethernetid  ָ������ID
	        bDelAll  :�Ƿ�ɾ�����������е�IP/MASK
	        TEthnetInterfaceParam  ��bDelAllΪFalseʱ��Ч Ҫɾ����(����IP/mask/mac��Ϣ)
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_Ethernet_DeleteIpParamResult_Ntf
	*/
	MESSAGE(Ev_MT_Ethernet_DeleteIpParam_Cmd)
	BODY(mt::TU32, ethernetid)
	BODY(mt::TBOOL32, bDelAll)
	BODY(mt::TEthnetInterfaceParam, TEthnetInterfaceParam)


	/*<<ɾ��ָ���ӿ�Ethernet ������Ϣ���֪ͨ>>
	*BODY ��result  0�ɹ�  ����������
	        ethernetid  ����ʱָ��������ID
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_Ethernet_DeleteIpParam_Cmd
	*/
	MESSAGE(Ev_MT_Ethernet_DeleteIpParamResult_Ntf)
	BODY(mt::TU32, result)
	BODY(mt::TU32, ethernetid)


	/*<<��ȡָ���ӿ�Ethernet ������ѡIP/MASK��Ϣ>>
	*BODY ��ethernetid  ָ������ID
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_Ethernet_GetPreferredIpParam_Rsp
	*/
	MESSAGE(Ev_MT_Ethernet_GetPreferredIpParam_Req)
	BODY(mt::TU32, ethernetid)


	/*<<��ȡָ���ӿ�Ethernet ������ѡIP/MASK��Ϣ���֪ͨ>>
	*BODY ��result  0�ɹ�  ����������
	        ethernetid  ָ������ID
	        TEthnetInterfaceParam  ��ѡ����IP/mask/mac��Ϣ

	*���䷽��net->dispatch->mtservice
	* see Ev_MT_Ethernet_GetPreferredIpParam_Req
	*/
	MESSAGE(Ev_MT_Ethernet_GetPreferredIpParam_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TU32, ethernetid)
	BODY(mt::TEthnetInterfaceParam, TEthnetInterfaceParam)


	/*<<��ȡָ���ӿ�Ethernet ��������IP/MASK��Ϣ>>
	*BODY ��ethernetid  ָ������ID
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_Ethernet_GetAllIpParam_Rsp
	*/
	MESSAGE(Ev_MT_Ethernet_GetAllIpParam_Req)
	BODY(mt::TU32, ethernetid)


	/*<<��ȡָ���ӿ�Ethernet ��������IP/MASK��Ϣ���֪ͨ>>
	*BODY ��result  0�ɹ�  ����������
	        ethernetid  ָ������ID
	        TEthnetInterfaceParamList  һ�������IP/mask/mac��Ϣ
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_Ethernet_GetAllIpParam_Req
	*/
	MESSAGE(Ev_MT_Ethernet_GetAllIpParam_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TU32, ethernetid)
	BODY(mt::TEthnetInterfaceParamList, TEthnetInterfaceParamList)



	/*<<����ָ���ӿ�Ethernet����>>
	*BODY ��ethernetid  ָ������ID
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_Ethernet_StartUpResult_Ntf
	*/
	MESSAGE(Ev_MT_Ethernet_StartUp_Cmd)
	BODY(mt::TU32, ethernetid)



	/*<<����ָ���ӿ�Ethernet�������֪ͨ>>
	*BODY ��result  0�ɹ�  ����������
	        ethernetid  ����ʱָ��������ID
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_Ethernet_StartUp_Cmd
	*/
	MESSAGE(Ev_MT_Ethernet_StartUpResult_Ntf)
	BODY(mt::TU32, result)
	BODY(mt::TU32, ethernetid)



	/*<<ָֹͣ���ӿ�Ethernet����>>
	*BODY ��ethernetid  ָ������ID
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_Ethernet_ShutDownResult_Ntf
	*/
	MESSAGE(Ev_MT_Ethernet_ShutDown_Cmd)
	BODY(mt::TU32, ethernetid)



	/*<<ָֹͣ���ӿ�Ethernet�������֪ͨ>>
	*BODY ��result  0�ɹ�  ����������
	        ethernetid  ����ʱָ��������ID
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_Ethernet_ShutDown_Cmd
	*/
	MESSAGE(Ev_MT_Ethernet_ShutDownResult_Ntf)
	BODY(mt::TU32, result)
	BODY(mt::TU32, ethernetid)
 

	/*<<��ʼʹ��ָ���ӿ�Ethernet����DHCP����>>
	*BODY ��ethernetid  ָ������ID
	        bUsedDefaultGateway ʹ�øýӿڵ�����ΪϵͳĬ��·��
	*���䷽��mtservice->dispatch->net
	* see  Ev_MT_Ethernet_DHCPLeaseInfo_Ntf
	*/
	MESSAGE(Ev_MT_Ethernet_StartDHCP_Cmd)
	BODY(mt::TU32, ethernetid)
	BODY(mt::TBOOL32, bUsedDefaultGateway)

 

	/*<<ֹͣʹ��ָ���ӿ�Ethernet����DHCP����>>
	*BODY ��ethernetid  ָ������ID
	*���䷽��mtservice->dispatch->net
	* see  Ev_MT_Ethernet_DHCPLeaseInfo_Ntf
	*/
	MESSAGE(Ev_MT_Ethernet_StopDHCP_Cmd)
	BODY(mt::TU32, ethernetid)



	/*<<ָ���ӿ�Ethernet����DHCP��Լ����>>
	*BODY ��ethernetid  ָ������ID
	*���䷽��mtservice->dispatch->net
	* see  
	*/
	MESSAGE(Ev_MT_Ethernet_RenewDHCP_Cmd)
	BODY(mt::TU32, ethernetid)
 

	/*<<DNS ���������ù���>>
	*BODY ��TDNSParam  DNS��������ע:DNS������Ծ���ĳ�����������õģ�
	*���䷽��mtservice->dispatch->net
	* see  
	*/
	MESSAGE(Ev_MT_Ethernet_SetDns_Cmd)
	BODY(mt::TDNSParam, TDNSParam)



	/*<<DNS ���������ù��ܽ��֪ͨ>>
	*BODY ��result  0�ɹ�  ����������
	*���䷽��net->dispatch->mtservice
	* see  
	*/
	MESSAGE(Ev_MT_Ethernet_SetDnsResult_Ntf)
	BODY(mt::TU32, result)



	/*<<��ѯָ���ӿ�Ethernet������dhcp��Լ��״̬��Ϣ>>
	*BODY ��ethernetid  ָ������ID
	*���䷽��mtservice->dispatch->net
	* see  
	*/
	MESSAGE(Ev_MT_Ethernet_GetDHCPLeaseInfo_Req)
	BODY(mt::TU32, ethernetid)


	/*<<��ѯָ���ӿ�Ethernet������dhcp��Լ��Ϣ>>
	*BODY �� result  0�ɹ�   ����������
	         TDHCPStateInfo  DHCP״̬��Ϣ
	         TDHCPLeaseInfo  DHCP��Լ��Ϣ
	*���䷽��net->dispatch->mtservice
	* see  
	*/
	MESSAGE(Ev_MT_Ethernet_GetDHCPLeaseInfo_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TDHCPStateInfo, TDHCPStateInfo)
	BODY(mt::TDHCPLeaseInfo, TDHCPLeaseInfo)


	/*<<Ethernet������dhcp��Լ��Ϣ֪ͨ>>
	*BODY �� TDHCPStateInfo  DHCP״̬��Ϣ
	         TDHCPLeaseInfo  DHCP��Լ��Ϣ
	         reason          �쳣ʱ��ԭ��
	*���䷽��net->dispatch->mtservice
	* see  
	*/
	MESSAGE(Ev_MT_Ethernet_DHCPLeaseInfo_Ntf)
	BODY(mt::TDHCPStateInfo, TDHCPStateInfo)
	BODY(mt::TDHCPLeaseInfo, TDHCPLeaseInfo)
	BODY(mt::TU32, reason)


	/*<<PPPoE ������������>>
	*BODY ��TPPPoEConnectParam  pppoe���Ӳ���
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_PPPoE_LinkState_Ntf
	*/
	MESSAGE(Ev_MT_PPPoE_Connect_Cmd)
	BODY(mt::TPPPoEConnectParam, TPPPoEConnectParam)


	/*<<PPPoE �Ͽ�����>>
	*BODY ��ethernetid  ָ������ID
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_PPPoE_LinkState_Ntf
	*/
	MESSAGE(Ev_MT_PPPoE_DisConnect_Cmd)
	BODY(mt::TU32, ethernetid)


	/*<<PPPoE ����״̬��ѯ>>
	*BODY ��ethernetid  ָ������ID
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_PPPoE_GetLinkState_Rsp
	*/
	MESSAGE(Ev_MT_PPPoE_GetLinkState_Req)
	BODY(mt::TU32, ethernetid)

	
	/*<<PPPoE ����״̬��ѯ��Ӧ>>
	*BODY ��TPPPoEState  ����״̬��Ϣ
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_PPPoE_GetLinkState_Req
	*/
	MESSAGE(Ev_MT_PPPoE_GetLinkState_Rsp)
	BODY(mt::TPPPoEState, TPPPoEState)


	/*<<PPPoE ����״̬֪ͨ>>
	*BODY ��TPPPoEState  ����״̬��Ϣ
	*���䷽��net->dispatch->mtservice
	* see   Ev_MT_PPPoE_Connect_Cmd
	        Ev_MT_PPPoE_DisConnect_Cmd
	*/
	MESSAGE(Ev_MT_PPPoE_LinkState_Ntf)
	BODY(mt::TPPPoEState, TPPPoEState)



	/*<<PPPoE ���Ӻ�ͳ����Ϣ��ѯ>>
	*BODY ��ethernetid  ָ������ID
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_PPPoE_GetStatisInfo_Rsp
	*/
	MESSAGE(Ev_MT_PPPoE_GetStatisInfo_Req)
	BODY(mt::TU32, ethernetid)

	
	/*<<PPPoE ���Ӻ�ͳ����Ϣ��ѯ��Ӧ>>
	*BODY ��TPPPoEStatis  ����ͳ����Ϣ
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_PPPoE_GetStatisInfo_Req
	*/
	MESSAGE(Ev_MT_PPPoE_GetStatisInfo_Rsp)
	BODY(mt::TPPPoEStatis, TPPPoEStatis)



	/*<<PPPoE �汾��Ϣ��ѯ>>
	*BODY ����
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_PPPoE_GetVersion_Rsp
	*/
	MESSAGE(Ev_MT_PPPoE_GetVersion_Req)

	
	/*<<PPPoE �汾��Ϣ��ѯ��Ӧ>>
	*BODY ��TPPPoEStatis  ����״̬ͳ����Ϣ
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_PPPoE_GetVersion_Req
	*/
	MESSAGE(Ev_MT_PPPoE_GetVersion_Rsp)
	BODY(mt::TPPPoEVersion, TPPPoEVersion)


 	/*<<��ȡָ��E1��������>>
	*BODY ��EmE1InterfaceType E1 interface type
	        interfaceUnit ָ���ӿںţ�ͬmSerialId
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_E1_GetBandwidth_Rsp
	*/
	MESSAGE(Ev_MT_E1_GetBandwidth_Req)
	BODY(mt::TU32, EmE1InterfaceType )
	BODY(mt::TU32, interfaceUnit)

	
	/*<<��ȡָ��E1����������Ӧ>>
	*BODY ��bandwidth_value ���ش���ֵ
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_E1_GetBandwidth_Req
	*/
	MESSAGE(Ev_MT_E1_GetBandwidth_Rsp)
	BODY(mt::TU32, bandwidth_value)

	/*<<E1����֪ͨ>>
	*BODY ��bandwidth
	*���䷽��net->dispatch->mtservice
	* see 
	*/
	MESSAGE(Ev_MT_E1_GetBandwidth_Ntf)
	BODY(mt::TU32, bandwidth)



	/*<<��ȡָ��E1�ӿ�Զ��ip����>>
	*BODY ��EmE1InterfaceType E1 interface type
	        interfaceUnit ָ���ӿںţ�ͬmSerialId
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_E1_GetRemoteIp_Rsp
	*/
	MESSAGE(Ev_MT_E1_GetRemoteIp_Req)
	BODY(mt::TU32, EmE1InterfaceType )
	BODY(mt::TU32, interfaceUnit)

	
	/*<<��ȡָ��E1�ӿ�Զ��ip������Ӧ>>
	*BODY ��remoteip ����Զ��IP��������
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_E1_GetRemoteIp_Req
	*/
	MESSAGE(Ev_MT_E1_GetRemoteIp_Rsp)
	BODY(mt::TU32, remoteip)


	/*<<���dce����dte ����>>
	*BODY ��e1: E1�ӿں�
	        EmE1ClockType: clock���� ("dce"��"dte")
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_E1_SetClockResult_Ntf
	*/
	MESSAGE(Ev_MT_E1_SetClock_Cmd)
	BODY(mt::TU32, e1 )
	BODY(mt::TU32, EmE1ClockType)


	/*<<���dce����dte ������֪ͨ>>
	*BODY ��result: true�ɹ� falseʧ��
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_E1_SetClock_Cmd
	*/
	MESSAGE(Ev_MT_E1_SetClockResult_Ntf)
	BODY(mt::TBOOL32, result )



	/*<<����һ��E1����·����ͨ�� ����>>
	*BODY ��chainId: ��·ͨ��ID����Χ[0~ 8) ��ID����Ψһ�ԣ�������ʶÿ������·����ͨ�������ɳ�ͻ
	        TE1SingleChainInfo: ��·����
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_E1_ChainOptResult_Ntf
	*/
	MESSAGE(Ev_MT_E1_OpenSingleChain_Cmd)
	BODY(mt::TU32, chainId )
	BODY(mt::TE1SingleChainInfo, TE1SingleChainInfo)


	/*<<�ر�һ��E1����·����ͨ�� ����>>
	*BODY ��chainId: ��·ͨ��ID
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_E1_ChainOptResult_Ntf
	*/
	MESSAGE(Ev_MT_E1_CloseSingleChain_Cmd)
	BODY(mt::TU32, chainId )



	/*<<����һ��E1����·����ͨ�� ����>>
	*BODY ��chainId: ��·ͨ��ID����Χ[0~ 8) ��ID����Ψһ�ԣ�������ʶÿ������·����ͨ�������ɳ�ͻ
	        TE1MultiChainInfo: ����·����
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_E1_ChainOptResult_Ntf
	*/
	MESSAGE(Ev_MT_E1_OpenMultiChain_Cmd)
	BODY(mt::TU32, chainId )
	BODY(mt::TE1MultiChainInfo, TE1MultiChainInfo)


	/*<<�ر�һ��E1����·����ͨ�� ����>>
	*BODY ��chainId: ��·ͨ��ID
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_E1_ChainOptResult_Ntf
	*/
	MESSAGE(Ev_MT_E1_CloseMultiChain_Cmd)
	BODY(mt::TU32, chainId )


	/*<<��/�ر�һ��E1����·�����·����ʱ�Ľ��֪ͨ>>
	*BODY ��EmE1ChainOptType :  ��·ͨ����������
	        EmE1LinkErrReason:  �򿪻�رս��
	*���䷽��net->dispatch->mtservice
	* see     Ev_MT_E1_OpenSingleChain_Cmd
	          Ev_MT_E1_CloseSingleChain_Cmd
	          Ev_MT_E1_OpenMultiChain_Cmd
	          Ev_MT_E1_CloseMultiChain_Cmd
	*/
	MESSAGE(Ev_MT_E1_ChainOptResult_Ntf)
	BODY(mt::TU32, EmE1ChainOptType )
	BODY(mt::TU32, EmE1LinkErrReason )

	
 
	/*<<����ϵͳ��Ĭ����������>>
	*BODY �� ethernetid ����id
	         gateway: Ĭ������(������)
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_ROUTE_SetDefaultGatewayResult_Ntf
	*/
	MESSAGE(Ev_MT_ROUTE_SetDefaultGateway_Cmd)
	BODY(mt::TU32, ethernetid)
	BODY(mt::TU32, gateway )


	/*<<����ϵͳ��Ĭ������������֪ͨ>>
	*BODY ��   ethernetid ����id
	           result: true�ɹ�  falseʧ��
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_ROUTE_SetDefaultGateway_Cmd
	*/
	MESSAGE(Ev_MT_ROUTE_SetDefaultGatewayResult_Ntf)
	BODY(mt::TU32, ethernetid)
	BODY(mt::TBOOL32, result )



	/*<<��ѯϵͳ��Ĭ����������>>
	*BODY ����
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_ROUTE_GetDefaultGateway_Rsp
	*/
	MESSAGE(Ev_MT_ROUTE_GetDefaultGateway_Req)


	/*<<��ѯϵͳ��Ĭ������������Ӧ>>
	*BODY ��gatewayip: ����IP,ʧ��0
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_ROUTE_GetDefaultGateway_Req
	*/
	MESSAGE(Ev_MT_ROUTE_GetDefaultGateway_Rsp)
	BODY(mt::TU32, gatewayip )


	/*<<ɾ��ϵͳ��Ĭ����������>>
	*BODY ����
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_ROUTE_DelDefaultGatewayResult_Ntf
	*/
	MESSAGE(Ev_MT_ROUTE_DelDefaultGateway_Cmd)


	/*<<ɾ��ϵͳ��Ĭ������������Ӧ>>
	*BODY ��result: true:ɾ���ɹ� false:ɾ��ʧ��
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_ROUTE_DelDefaultGateway_Cmd
	*/
	MESSAGE(Ev_MT_ROUTE_DelDefaultGatewayResult_Ntf)
	BODY(mt::TBOOL32, result )



	/*<<����һ��·������>>
	*BODY ��TRouteItemInfo ����·����Ϣ
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_ROUTE_AddRouteResult_Rsp
	*/
	MESSAGE(Ev_MT_ROUTE_AddRoute_Req)
	BODY(mt::TRouteItemInfo, TRouteItemInfo )


	/*<<����һ��·��������Ӧ>>
	*BODY ��result: true:��ӳɹ� false:���ʧ��
	TRouteItemInfo ��ӵ�·����Ŀ 
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_ROUTE_AddRoute_Req
	*/
	MESSAGE(Ev_MT_ROUTE_AddRouteResult_Rsp)
	BODY(mt::TBOOL32, result )
	BODY(mt::TRouteItemInfo, TRouteItemInfo )


	/*<<ɾ��һ��·������>>
	*BODY ��TRouteItemInfo Ҫɾ����·����Ϣ
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_ROUTE_DelRouteResult_Rsp
	*/
	MESSAGE(Ev_MT_ROUTE_DelRoute_Req)
	BODY(mt::TRouteItemInfo, TRouteItemInfo )

 
	/*<<ɾ��һ��·��������Ӧ>>
	*BODY ��result: true:ɾ���ɹ� false:ɾ��ʧ��
	        TRouteItemInfo ��ɾ����·����Ŀ
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_ROUTE_DelRoute_Req
	*/
	MESSAGE(Ev_MT_ROUTE_DelRouteResult_Rsp)
	BODY(mt::TBOOL32, result )
	BODY(mt::TRouteItemInfo, TRouteItemInfo )


	/*<<�޸�һ��·����Ϣ����>>
	*BODY ��oldRouteItemInfo ����ǰ��·����Ϣ
	        newRouteItemInfo �޸ĺ��·����Ϣ 
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_ROUTE_ModifyRouteResult_Rsp
	*/
	MESSAGE(Ev_MT_ROUTE_ModifyRoute_Req)
	BODY(mt::TRouteItemInfo, oldRouteItemInfo )
	BODY(mt::TRouteItemInfo, newRouteItemInfo )

 
	/*<<�޸�һ��·����Ϣ������Ӧ>>
	*BODY ��result: true:ɾ���ɹ� false:ɾ��ʧ��
	*       oldRouteItemInfo ����ǰ��·����Ϣ
	        newRouteItemInfo �޸ĺ��·����Ϣ 
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_ROUTE_ModifyRoute_Req
	*/
	MESSAGE(Ev_MT_ROUTE_ModifyRouteResult_Rsp)
	BODY(mt::TBOOL32, result )
	BODY(mt::TRouteItemInfo, oldRouteItemInfo )
	BODY(mt::TRouteItemInfo, newRouteItemInfo )
	
	
	/*<<��ȡĬ��·������>>
	*BODY ����
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_ROUTE_GetDefaultRoute_Req
	*/
	MESSAGE(Ev_MT_ROUTE_GetDefaultRoute_Req)

 
	/*<<��ȡĬ��·����Ӧ>>
	*BODY ��TRouteItemInfo ·����Ϣ
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_ROUTE_GetDefaultRoute_Rsp
	*/
	MESSAGE(Ev_MT_ROUTE_GetDefaultRoute_Rsp)
	BODY(mt::TRouteItemInfo, TRouteItemInfo )

	/*<<��ȡ����·������>>
	*BODY ����
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_ROUTE_GetAllRoute_Rsp
	*/
	MESSAGE(Ev_MT_ROUTE_GetAllRoute_Req)

 
	/*<<��ȡ����·��������Ӧ>>
	*BODY ��TRouteItemInfoList ·���б���Ϣ
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_ROUTE_GetAllRoute_Req
	*/
	MESSAGE(Ev_MT_ROUTE_GetAllRoute_Rsp)
	BODY(mt::TRouteItemInfoList, TRouteItemInfoList )



	/*<<PING��������>>
	*BODY ��TPingTestParam PING������Ϣ
	*���䷽��service->dispatch->net
	* see Ev_MT_PING_PingTestResult_Rsp
	*/
	MESSAGE(Ev_MT_PING_PingTest_Req)
	BODY(mt::TPingTestParam, TPingTestParam )
	


	/*<<PING����������֪ͨ>>
	*BODY ��TPingResult  PING�����Ϣ
	*���䷽��net->dispatch->service
	* see Ev_MT_PING_PingTest_Req
	*/
	MESSAGE(Ev_MT_PING_PingTestResult_Rsp)
	BODY(mt::TPingResult, TPingResult )


	/*<<ip mac��ͻ֪ͨ>>
	*BODY ��TNetConfilictedInfo  ��ͻ��Ϣ
	*���䷽��net->dispatch->service
	* see 
	*/
	MESSAGE(Ev_MT_NET_IPMACConfilicted_Ntf)
	BODY(mt::TNetConfilictedInfo, TNetConfilictedInfo )
	
 
	 
 	/*<<Wifi ����ģʽ����>>
	*BODY ��TWifiWorkMode
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_WIFI_ChangeWorkMode_Ntf
	*/
	MESSAGE(Ev_MT_WIFI_ChangeWorkMode_Cmd)
	BODY(mt::TWifiWorkMode, TWifiWorkMode)
	
	/*<<Wifi ����ģʽ״̬֪ͨ>>
	* ----------------------------------------------------------
	*BODY��result: ���ý����Ϣ
	*BODY��TWifiWorkMode��	��ǰWifi����ģʽ
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_WIFI_ChangeWorkMode_Cmd
	*/
	MESSAGE(Ev_MT_WIFI_ChangeWorkMode_Ntf)
	BODY(mt::TWifiWorkMode, TWifiWorkMode)
	BODY(mt::TBOOL32, result)	
	
	/*<<Wifi ����ģʽ��Ϣ��ѯ>>
	*BODY ����
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_WIFI_GetWorkMode_Rsp
	*/
	MESSAGE(Ev_MT_WIFI_GetWorkMode_Req)

	
	/*<<Wifi ����ģʽ��Ϣ��Ӧ>>
	* ----------------------------------------------------------
	* ��������TWifiWorkMode��	��ǰWifi����ģʽ
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_WIFI_GetWorkMode_Req
	*/
	MESSAGE(Ev_MT_WIFI_GetWorkMode_Rsp)
	BODY(mt::TWifiWorkMode, TWifiWorkMode)
	

	/*<<Wifi �ȵ�ɨ������>>
	*BODY ����
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_WIFI_ScanResult_Rsp
	*/
	MESSAGE(Ev_MT_WIFI_StartScan_Req)


	/*<<Wifi �ȵ�ɨ����֪ͨ>>
	* ----------------------------------------------------------
	* ������TWifiScanResultList��	ɨ�赽��ѡWIFI����б�
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_WIFI_StartScan_Req
	*/
	MESSAGE(Ev_MT_WIFI_ScanResult_Rsp)
	BODY(mt::TWifiScanResultList, TWifiScanResultList)


	/*<<Wifi �ȵ���������>>
	* ----------------------------------------------------------
	* ������TWifiConnParam��	wifi�������Ӳ���
	* ----------------------------------------------------------
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_WIFI_LinkState_Ntf	      
	*/
	MESSAGE(Ev_MT_WIFI_Connect_Cmd)
	BODY(mt::TWifiConnParam, TWifiConnParam)
	
	
	/*<<Wifi �ȵ�Ͽ�����>>
	* ----------------------------------------------------------
	* �������ޣ�	�Ͽ���ǰ����
	* ----------------------------------------------------------
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_WIFI_LinkState_Ntf	      
	*/
	MESSAGE(Ev_MT_WIFI_DisConnect_Cmd)
 
 
    /*<<Wifi ������������>>
	* ----------------------------------------------------------
	* ������TU32��	wifi�ȵ�id
	* ----------------------------------------------------------
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_WIFI_Forget_Rsp	      
	*/
	MESSAGE(Ev_MT_WIFI_Forget_Req)
	BODY(mt::TU32, hotspotId)

     /*<<Wifi ����������Ӧ>>
	* ----------------------------------------------------------
	* ������TBOOL32��	���ý��
	* ������TU32��		wifi�ȵ�id
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_WIFI_Forget_Req	      
	*/
	MESSAGE(Ev_MT_WIFI_Forget_Rsp)
    BODY(mt::TBOOL32, result)
	BODY(mt::TU32, hotspotId)
	
	/*<<Wifi ����״̬��ѯ>>
	*BODY ����
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_WIFI_LinkState_Rsp
	*/
	MESSAGE(Ev_MT_WIFI_GetLinkState_Req)
	
	
	/*<<Wifi ����״̬��ѯ֪ͨ>>
	* ----------------------------------------------------------
	* ������TWifiCurDetailInfo��	Wifi��������״̬��Ϣ
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_WIFI_GetLinkState_Req
	*/
	MESSAGE(Ev_MT_WIFI_LinkState_Rsp)
	BODY(mt::TWifiCurDetailInfo, TWifiCurDetailInfo)
	
	
	/*<<Wifi ���ӽ��״̬֪ͨ>>
	* ----------------------------------------------------------
	* ������TWifiCurDetailInfo��	Wifi�������ӽ����Ϣ
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_WIFI_Connect_Cmd
	      Ev_MT_WIFI_DisConnect_Cmd 
	*/
	MESSAGE(Ev_MT_WIFI_LinkState_Ntf)
	BODY(mt::TWifiCurDetailInfo, TWifiCurDetailInfo)
	
	
	/*<<Wifi ��ǰ���ӵ�Wifi�ͻ�����������>>
	* ----------------------------------------------------------
	* ������TWifiConfiguration:    Wifi���ӵĿͻ���������Ϣ 
	* ----------------------------------------------------------
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_WIFI_ModClientProperty_Ntf
	*/
	MESSAGE(Ev_MT_WIFI_ModClientProperty_Cmd)
	BODY(mt::TWifiConfiguration, TWifiConfiguration)
  
  
  	/*<<Wifi ��ǰ���ӵ�Wifi�ͻ��������޸Ľ��֪ͨ>>
	* ----------------------------------------------------------
	* ������TBOOL32:               �޸Ľ��                 
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_WIFI_ModClientProperty_Cmd
	*/
	MESSAGE(Ev_MT_WIFI_ModClientProperty_Ntf)
	BODY(mt::TBOOL32, )
	BODY(mt::TWifiConfiguration, TWifiConfiguration)
	
	
	/*<<Wifi ��ȡ��ǰ���ӵ�Wifi�ͻ�����������>>
	* ----------------------------------------------------------
	* �������� 
	* ----------------------------------------------------------
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_WIFI_GetModClientProperty_Rsp
	*/
	MESSAGE(Ev_MT_WIFI_GetModClientProperty_Req)
	
	
	/*<<Wifi ��ȡ��ǰ���ӵ�Wifi�ͻ�����������֪ͨ>>
	* ----------------------------------------------------------
	* ������TWifiConfiguration:    Wifi���ӵĿͻ���������Ϣ 
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_WIFI_ModClientProperty_Cmd
	*/
	MESSAGE(Ev_MT_WIFI_GetModClientProperty_Rsp)
	BODY(mt::TWifiConfiguration, TWifiConfiguration)
	
	
	/*<<Wifi ��ȡ��ǰ���ӵ�Wifi�ͻ�����ϸ��Ϣ����>>
	* ----------------------------------------------------------
	* �������� 
	* ----------------------------------------------------------
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_WIFI_GetWifiCurConnectedInfo_Rsp
	*/
	MESSAGE(Ev_MT_WIFI_GetWifiCurConnectedInfo_Req)
	
	
	/*<<Wifi ��ȡ��ǰ���ӵ�Wifi�ͻ�����ϸ��Ϣ����֪ͨ>>
	* ----------------------------------------------------------
	* ������TWifiCurDetailInfo:    Wifi���ӵĿͻ�����ϸ��Ϣ 
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_WIFI_GetWifiCurConnectedInfo_Req
	*/
	MESSAGE(Ev_MT_WIFI_GetWifiCurConnectedInfo_Rsp)
	BODY(mt::TWifiConfiguration, TWifiConfiguration)
	
	
	/*<<Wifi ��ǰ���ӵ�Wifiͳ����Ϣ��ѯ����>>
	* ----------------------------------------------------------
	* ��������
	* ----------------------------------------------------------
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_WIFI_GetCurWifiStatisInfo_Rsp
	*/
	MESSAGE(Ev_MT_WIFI_GetCurWifiStatisInfo_Req)
 
	
	/*<<Wifi ��ǰ���ӵ�Wifiͳ����Ϣ��ѯ��Ӧ>>
	* ----------------------------------------------------------
	* ������TWifiStatisInfo��	��ǰWifi��ͳ����Ϣ ���ź�ǿ�ȣ��������ܴ���
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_WIFI_GetCurWifiStatisInfo_Req
	*/
	MESSAGE(Ev_MT_WIFI_GetCurWifiStatisInfo_Rsp)
	BODY(mt::TWifiStatisInfo, TWifiStatisInfo)
	
	/*<<��ȡ����Ͷ����Ϣ����>>
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_WIFI_GetWirelessScreen_Rsp
	*/
	MESSAGE(Ev_MT_WIFI_GetWirelessScreen_Req)

	/*<<��ȡ����Ͷ����Ϣ��Ӧ>>
	*BODY ��TWifiWirelessScreenInfo  ����Ͷ����Ϣ
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_WIFI_GetWirelessScreen_Req
	*/
	MESSAGE(Ev_MT_WIFI_GetWirelessScreen_Rsp)
	BODY(mt::TWifiWirelessScreenInfo, TWifiWirelessScreenInfo)

	/*<<������ֹͣ����Ͷ������>>
    *BODY ��bStart  true:����  false:ֹͣ
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_WIFI_WirelessScreenStateChange_Ntf
	*/
	MESSAGE(Ev_MT_WIFI_SetWirelessScreen_Cmd)
    BODY(mt::TBOOL32, bStart)

	/*<<����Ͷ��״̬�ı�֪ͨ>>
    *BODY ��TWifiWirelessScreenInfo  ����Ͷ����Ϣ
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_WIFI_SetWirelessScreen_Cmd
	*/
	MESSAGE(Ev_MT_WIFI_WirelessScreenStateChange_Ntf)
	BODY(mt::TWifiWirelessScreenInfo, TWifiWirelessScreenInfo)
	
	/*<<MobileData ����ģʽ����>>
	*BODY ��TMobileDataWorkMode
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_MOBILEDATA_ChangeWorkMode_Ntf
	      Ev_MT_MOBILEDATA_LinkState_Ntf   
	*/
	MESSAGE(Ev_MT_MOBILEDATA_ChangeWorkMode_Cmd)
	BODY(mt::TMobileDataWorkMode, TMobileDataWorkMode)
	
	
	/*<<MobileData ����ģʽ���ý��֪ͨ>>
	* ----------------------------------------------------------
	* ��������TBOOL32:   ���ý��          
	          TWifiWorkMode��	��ǰWifi����ģʽ
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_MOBILEDATA_ChangeWorkMode_Cmd
	*/
	MESSAGE(Ev_MT_MOBILEDATA_ChangeWorkMode_Ntf)
	BODY(mt::TBOOL32, )
	BODY(mt::TMobileDataWorkMode, TMobileDataWorkMode)
	
	
	/*<<MobileData ����ģʽ��Ϣ��ѯ>>
	*BODY ����
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_MOBILEDATA_GetWorkMode_Rsp
	*/
	MESSAGE(Ev_MT_MOBILEDATA_GetWorkMode_Req)

	
	/*<<MobileData  ����ģʽ��Ϣ��ѯ��Ӧ>>
	* ----------------------------------------------------------
	* ��������TWifiWorkMode��	��ǰWifi����ģʽ
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_MOBILEDATA_GetWorkMode_Req
	*/
	MESSAGE(Ev_MT_MOBILEDATA_GetWorkMode_Rsp)
	BODY(mt::TMobileDataWorkMode, TMobileDataWorkMode)
	
	
	
	/*<<MobileData  �ƶ��������Ӻ���ϸ״̬֪ͨ>>
	* ----------------------------------------------------------
	* ��������TMobileDataCurDetailInfo��	��ǰ�ƶ����ݵ���ϸ��Ϣ
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_MOBILEDATA_ChangeWorkMode_Cmd
	*/
	MESSAGE(Ev_MT_MOBILEDATA_LinkState_Ntf)
	BODY(mt::TMobileDataCurDetailInfo, TMobileDataCurDetailInfo)
	
	
	
	/*<<MobileData ��ѯ�ƶ��������Ӻ���ϸ��Ϣ>>
	*BODY ����
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_MOBILEDATA_GetDetailInfo_Rsp
	*/
	MESSAGE(Ev_MT_MOBILEDATA_GetDetailInfo_Req)

	
	/*<<MobileData  �ƶ��������Ӻ���ϸ��Ϣ��Ӧ>>
	* ----------------------------------------------------------
	* ��������TMobileDataCurDetailInfo��	��ǰ�ƶ����ݵ���ϸ��Ϣ
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_MOBILEDATA_GetDetailInfo_Req
	*/
	MESSAGE(Ev_MT_MOBILEDATA_GetDetailInfo_Rsp)
	BODY(mt::TMobileDataCurDetailInfo, TMobileDataCurDetailInfo)
	
	
	
	/*<<MobileData ��ǰ���ӵ��ƶ�����ͳ����Ϣ��ѯ����>>
	* ----------------------------------------------------------
	* ��������
	* ----------------------------------------------------------
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_MOBILEDATA_GetCurStatisInfo_Rsp
	*/
	MESSAGE(Ev_MT_MOBILEDATA_GetCurStatisInfo_Req)
 
	
	/*<<MobileData ��ǰ���ӵ��ƶ�����ͳ����Ϣ��ѯ��Ӧ>>
	* ----------------------------------------------------------
	* ������TMobileDataStatisInfo��	��ǰWifi��ͳ����Ϣ ���ź�ǿ�ȣ��������ܴ���
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_MOBILEDATA_GetCurStatisInfo_Req
	*/
	MESSAGE(Ev_MT_MOBILEDATA_GetCurStatisInfo_Rsp)
	BODY(mt::TMobileDataStatisInfo, TMobileDataStatisInfo)
	
	
	
	/*<<��ѯDNS��Ӧ��IP��Ϣ����>>
	* ----------------------------------------------------------
	* ������TDNSNameToIpInfo Ҫ��ѯ��DNS��Ϣ
	* ----------------------------------------------------------
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_Ethernet_GetIpByDNSInfo_Rsp
	*/
	MESSAGE(Ev_MT_Ethernet_GetIpByDNSInfo_Req)
	BODY(mt::TDNSNameToIpInfo, TDNSNameToIpInfo)
 
	
	/*<<��ѯDNS��Ӧ��IP��Ϣ������Ӧ>>
	* ----------------------------------------------------------
	* ������TDNSNameToIpResult��	DNS��ѯ����IP�����Ϣ
	* ----------------------------------------------------------
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_Ethernet_GetIpByDNSInfo_Req
	*/
	MESSAGE(Ev_MT_Ethernet_GetIpByDNSInfo_Rsp)
	BODY(mt::TDNSNameToIpResult, TDNSNameToIpResult)
	
	
	
	/*<<��ѯָ���ӿ�Ethernet ��������״̬>>
	*BODY ��ethernetid  ָ������ID
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_Ethernet_GetLinkState_Rsp
	*/
	MESSAGE(Ev_MT_Ethernet_GetLinkState_Req)
	BODY(mt::TU32, ethernetid)


	/*<<��ѯָ���ӿ�Ethernet ��������״̬�����Ӧ>>
	*BODY ��result  0�ɹ�  ����������
	        ethernetid  ָ������ID
	        bOn  true:����  false:�Ͽ�

	*���䷽��net->dispatch->mtservice
	* see Ev_MT_Ethernet_GetLinkState_Req
	*/
	MESSAGE(Ev_MT_Ethernet_GetLinkState_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TU32, ethernetid)
	BODY(mt::TBOOL32, bOn )
	
	
	/*<<Ethernet ��������״̬�ı�֪ͨ>>
	*BODY ��ethernetid  �ı������ID
	        bOn  true:����  false:�Ͽ�

	*���䷽��net->dispatch->mtservice
	* see 
	*/
	MESSAGE(Ev_MT_Ethernet_LinkState_Ntf)
	BODY(mt::TU32, ethernetid)
	BODY(mt::TBOOL32, bOn )
	

	/*<<�����������ģ���Ƿ��Ƿ��Ѿ�����>>
	*BODY ��    
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_NetServiceStarted_Rsp
	*/
	MESSAGE(Ev_MT_NetServiceStarted_Req)
	
	
	/*<<��ѯ�������ģ������״̬>>
	*BODY ��bOn  true:�������  false:��δ�������
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_NetServiceStarted_Req
	*/
	MESSAGE(Ev_MT_NetServiceStarted_Rsp)
	BODY(mt::TBOOL32, bStarted )
	
	
	/*<<�������ģ���������֪ͨ>>
	*BODY ��bOn  true:�������  false:��δ�������
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_NetServiceStarted_Req
	      Ev_MT_NetServiceStarted_Rsp
	*/
	MESSAGE(Ev_MT_NetServiceStarted_Ntf)
	BODY(mt::TBOOL32, bStarted )
	
	
	/*<<���õ�ǰ����ʱ����Ϣ>>
	*BODY ��  TMTTime ʱ����Ϣ  
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_SetSysDataTimeResult_Rsp
	*/
	MESSAGE(Ev_MT_SetSysDataTime_Req)
	BODY(mt::TMTTime, TMTTime )
	
	
	/*<<���õ�ǰ����ʱ����Ϣ��Ӧ>>
	*BODY ��   result ���ý�� 0�ɹ� ����������
	           TMTTime ʱ����Ϣ 
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_SetSysDataTime_Cmd
	*/
	MESSAGE(Ev_MT_SetSysDataTimeResult_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTTime, TMTTime )
	
	
	/*<<��ѯ��ǰ����ʱ����Ϣ>>
	*BODY ��    
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_GetSysDataTime_Rsp
	*/
	MESSAGE(Ev_MT_GetSysDataTime_Req)
	
	
	/*<<��ѯ��ǰ����ʱ����Ϣ��Ӧ>>
	*BODY ��result ��ȡ��� 0�ɹ� ����������
	        TMTTime  ʱ����Ϣ
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_GetSysDataTime_Req
	*/
	MESSAGE(Ev_MT_GetSysDataTime_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTTime, TMTTime )


	/*<<����NTP�������ر�״̬>>
	*BODY ��  TMTNTPInfo NTP������״̬ 
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_SetNTPSvrParamResult_Rsp
	*/
	MESSAGE(Ev_MT_SetNTPSvrParam_Req)
	BODY(mt::TMTNTPInfo, TMTNTPInfo )
	
	
	/*<<����NTP�������ر�״̬��Ӧ>>
	*BODY ��   result ���ý�� 0�ɹ� ����������
	           TMTNTPInfo NTP������Ϣ 
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_SetNTPSvrParam_Req
	*/
	MESSAGE(Ev_MT_SetNTPSvrParamResult_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTNTPInfo, TMTNTPInfo )
	
	
	/*<<��ѯ��ǰNTP������״̬����>>
	*BODY ��    
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_GetNTPSvrParam_Rsp
	*/
	MESSAGE(Ev_MT_GetNTPSvrParam_Req)
	
	
	/*<<��ѯ��ǰNTP������״̬��Ӧ>>
	*BODY ��result ��ȡ��� 0�ɹ� ����������
	        TMTNTPInfo NTP������Ϣ 
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_GetNTPSvrParam_Req
	*/
	MESSAGE(Ev_MT_GetNTPSvrParam_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTNTPInfo, TMTNTPInfo )
	


	/*<<Telnet������/ֹͣ����>>
	*BODY ��  bStart  true:����  false:ֹͣ  
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_Net_TelnetService_Ntf
	*/
	MESSAGE(Ev_MT_Net_TelnetService_Cmd)
	BODY(mt::TBOOL32, bStart )
	
	
	/*<<Telnet������/ֹͣ״̬֪ͨ>>
	*BODY ��reason    0:�ɹ�, 1,����ʧ�ܣ�2,ֹͣʧ��, ����������
	        bStarted  ��ǰ״̬ true:����״̬  false:ֹͣ״̬  
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_Net_TelnetService_Cmd
	*/
	MESSAGE(Ev_MT_Net_TelnetService_Ntf)
	BODY(mt::TU32, reason)
	BODY(mt::TBOOL32, bStarted )

	
	/*<<Ftp������/ֹͣ����>>
	*BODY ��  bStart  true:����  false:ֹͣ  
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_Net_FtpService_Ntf
	*/
	MESSAGE(Ev_MT_Net_FtpService_Cmd)
	BODY(mt::TBOOL32, bStart )
	
	
	/*<<Ftp������/ֹͣ״̬֪ͨ>>
	*BODY ��reason    0:�ɹ�, 1,����ʧ�ܣ�2,ֹͣʧ��, ����������
	        bStarted  ��ǰ״̬ true:����״̬  false:ֹͣ״̬  
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_Net_FtpService_Cmd
	*/
	MESSAGE(Ev_MT_Net_FtpService_Ntf)
	BODY(mt::TU32, reason)
	BODY(mt::TBOOL32, bStarted )

	
	/*<<Http������/ֹͣ����>>
	*BODY ��  bStart  true:����  false:ֹͣ  
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_Net_HttpService_Ntf
	*/
	MESSAGE(Ev_MT_Net_HttpService_Cmd)
	BODY(mt::TBOOL32, bStart )
	
	
	/*<<Http������/ֹͣ״̬֪ͨ>>
	*BODY ��reason    0:�ɹ�, 1,����ʧ�ܣ�2,ֹͣʧ��, ����������
	        bStarted  ��ǰ״̬ true:����״̬  false:ֹͣ״̬  
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_Net_HttpService_Cmd
	*/
	MESSAGE(Ev_MT_Net_HttpService_Ntf)
	BODY(mt::TU32, reason)
	BODY(mt::TBOOL32, bStarted )



	/*<<����TimeZone��Ϣ>>
	*BODY ��  TMTTimeZoneInfo ʱ����Ϣ 
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_SetTimeZone_Rsp
	*/
	MESSAGE(Ev_MT_SetTimeZone_Req)
	BODY(mt::TMTTimeZoneInfo, TMTTimeZoneInfo )
	
	
	/*<<����TimeZone��Ϣ��Ӧ>>
	*BODY ��   result ���ý�� 0�ɹ� ����������
	           TMTTimeZoneInfo ʱ����Ϣ 
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_SetTimeZone_Req
	*/
	MESSAGE(Ev_MT_SetTimeZone_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTTimeZoneInfo, TMTTimeZoneInfo )
	
	
	/*<<��ѯ��ǰTimeZone��Ϣ����>>
	*BODY ��    
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_GetTimeZone_Rsp
	*/
	MESSAGE(Ev_MT_GetTimeZone_Req)
	
	
	/*<<��ѯ��ǰTimeZone��Ϣ��Ӧ>>
	*BODY ��result ��ȡ��� 0�ɹ� ����������
	        TMTTimeZoneInfo ʱ����Ϣ  
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_GetTimeZone_Req
	*/
	MESSAGE(Ev_MT_GetTimeZone_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTTimeZoneInfo, TMTTimeZoneInfo )



	/*<<����Ftp/Telnet�˺���Ϣ>>
	*BODY ��  TMTFtpTelnetAccountInfo �˺���Ϣ 
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_SetFtpTelnetAccountInfo_Rsp
	*/
	MESSAGE(Ev_MT_SetFtpTelnetAccountInfo_Req)
	BODY(mt::TMTFtpTelnetAccountInfo, TMTFtpTelnetAccountInfo )
	
	
	/*<<����Ftp/Telnet�˺���Ϣ��Ӧ>>
	*BODY ��   result ���ý�� 0�ɹ� ����������
	           TMTFtpTelnetAccountInfo �˺���Ϣ 
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_SetFtpTelnetAccountInfo_Req
	*/
	MESSAGE(Ev_MT_SetFtpTelnetAccountInfo_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTFtpTelnetAccountInfo, TMTFtpTelnetAccountInfo )

    /*<<��ȡE1����·������>>
	*BODY ����
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_ROUTE_GetE1AllRoute_Rsp
	*/
	MESSAGE(Ev_MT_ROUTE_GetE1AllRoute_Req)

 
	/*<<��ȡE1����·��������Ӧ>>
	*BODY ��TE1RouteItemInfoList ·���б���Ϣ
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_ROUTE_GetE1AllRoute_Req
	*/
	MESSAGE(Ev_MT_ROUTE_GetE1AllRoute_Rsp)
	BODY(mt::TE1RouteItemInfoList, TE1RouteItemInfoList )

    /*<<��ѯ��ǰE1��·��Ϣ>>
    *BODY ��E1GroupId E1����ID:0,1,2,3; ��ֵȡ4ʱ�����ȡȫ������
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_GetE1LinkInfo_Rsp
	*/
	MESSAGE(Ev_MT_GetE1LinkInfo_Req)
    BODY(mt::TU32, E1GroupId)

    /*<<��ѯ��ǰE1��·��Ϣ��Ӧ>>
	*BODY ��result ��ȡ��� 0��ͨ 1����
    *BODY ��E1GroupId E1����ID:0,1,2,3; ��ֵȡ4ʱ�����ȡȫ������
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_GetE1LinkInfo_Rsp
	*/
	MESSAGE(Ev_MT_GetE1LinkInfo_Rsp)
    BODY(mt::TU32, E1GroupId)
	BODY(mt::TU32, result)

    /*<<E1��·��Ϣ֪ͨ>>
    *BODY ��result ��ȡ��� 0��ͨ 1����
    *BODY ��E1GroupId E1����ID:0,1,2,3; ��ֵȡ4ʱ�����ȡȫ������
    *���䷽��net->dispatch->mtservice
    * see Ev_MT_GetE1LinkInfo_Req
    */
	MESSAGE(Ev_MT_Net_E1LinkInfo_Ntf)
	BODY(mt::TU32, result)

    /*<<�ն�����֪ͨ>>
    *���䷽��mtservice->dispatch->net
    * see Ev_MT_SetTerlModel_Cmd
    */
	MESSAGE(Ev_MT_SetTerlModel_Cmd)
	BODY(mt::TU32, terlmodel)

	/*<<����һ���޶�ip������>>
	*BODY ��TLimitedIpItemInfo �����޶�IP����Ϣ
    *���䷽��mtservice->dispatch->net
    * see Ev_MT_Net_AddLimitedIpResult_Rsp
    */
	MESSAGE(Ev_MT_Net_AddLimitedIp_Req)
	BODY(mt::TLimitedIpItemInfo, TLimitedIpItemInfo)

	/*<<����һ���޶�ip����Ӧ>>
	*BODY ��result: true:��ӳɹ� false:���ʧ��
	*BODY ��TLimitedIpItemInfo �����޶�IP����Ϣ
    *���䷽��net->dispatch->mtservice
    * see Ev_MT_Net_AddLimitedIp_Req
    */
	MESSAGE(Ev_MT_Net_AddLimitedIpResult_Rsp)
	BODY(mt::TBOOL32, result)
	BODY(mt::TLimitedIpItemInfo, TLimitedIpItemInfo)

	/*<<ɾ��һ���޶�ip������>>
	*BODY ��TLimitedIpItemInfo Ҫɾ�����޶�IP����Ϣ
    *���䷽��mtservice->dispatch->net
    * see Ev_MT_Net_DelLimitedIpResult_Rsp
    */
	MESSAGE(Ev_MT_Net_DelLimitedIp_Req)
	BODY(mt::TLimitedIpItemInfo, TLimitedIpItemInfo)

	/*<<ɾ��һ���޶�ip����Ӧ>>
	*BODY ��result: true:ɾ���ɹ� false:ɾ��ʧ��
	*BODY ��TLimitedIpItemInfo Ҫɾ�����޶�IP����Ϣ
    *���䷽��net->dispatch->mtservice
    * see Ev_MT_Net_DelLimitedIp_Req
    */
	MESSAGE(Ev_MT_Net_DelLimitedIpResult_Rsp)
	BODY(mt::TBOOL32, result)
	BODY(mt::TLimitedIpItemInfo, TLimitedIpItemInfo)

	/*<<�޸�һ���޶�ip������>>
	*BODY ��oldLimitedIpItemInfo �޸�ǰ���޶�IP����Ϣ
	*BODY ��newLimitedIpItemInfo �޸ĺ���޶�IP����Ϣ
    *���䷽��mtservice->dispatch->net
    * see Ev_MT_Net_ModLimitedIpResult_Rsp
    */
	MESSAGE(Ev_MT_Net_ModLimitedIp_Req)
	BODY(mt::TLimitedIpItemInfo, oldLimitedIpItemInfo)
	BODY(mt::TLimitedIpItemInfo, newLimitedIpItemInfo)

	/*<<�޸�һ���޶�ip����Ӧ>>
	*BODY ��result: true:�޸ĳɹ� false:�޸�ʧ��
	*BODY ��oldLimitedIpItemInfo �޸�ǰ���޶�IP����Ϣ
	*BODY ��newLimitedIpItemInfo �޸ĺ���޶�IP����Ϣ
    *���䷽��net->dispatch->mtservice
    * see Ev_MT_Net_ModLimitedIp_Req
    */
	MESSAGE(Ev_MT_Net_ModLimitedIpResult_Rsp)
	BODY(mt::TBOOL32, result)
	BODY(mt::TLimitedIpItemInfo, oldLimitedIpItemInfo)
	BODY(mt::TLimitedIpItemInfo, newLimitedIpItemInfo)

	/*<<�����޶��޶�ip������>>
	*BODY ��tOptType �������ͣ�1:���� 2:ɾ�� 3:�޸ģ�
	*BODY ��TLimitedIpCfg �޶�ip����
	*BODY ��TLimitedIpItemInfo ��Ҫ���ӻ�ɾ�����޸ĵ��޶�ip��
	*BODY ��modLimitedIpItemInfo ֻ�����޸Ĳ���ʱ��Ҫ�޸ĺ��Ŀ���޶�ip�Σ����������TLimitedIpItemInfoһ��
    *���䷽��mtservice->dispatch->net
    * see Ev_MT_Net_UpdateLimitedIpResult_Rsp
    */
	MESSAGE(Ev_MT_Net_UpdateLimitedIp_Req)
	BODY(mt::TU32, tOptType)
	BODY(mt::TLimitedIpCfg, TLimitedIpCfg)
	BODY(mt::TLimitedIpItemInfo, TLimitedIpItemInfo)
	BODY(mt::TLimitedIpItemInfo, modLimitedIpItemInfo)

	/*<<�����޶��޶�ip����Ӧ>>
	*BODY ��result: true:�޸ĳɹ� false:�޸�ʧ��
	*BODY ��tOptType �������ͣ�1:���� 2:ɾ�� 3:�޸ģ�
	*BODY ��TLimitedIpItemInfo ��Ҫ���ӻ�ɾ�����޸ĵ��޶�ip��
	*BODY ��modLimitedIpItemInfo ֻ�����޸Ĳ���ʱ��Ҫ�޸ĺ��Ŀ���޶�ip��, ���������TLimitedIpItemInfoһ��
    *���䷽��mtservice->dispatch->net
    * see Ev_MT_Net_UpdateLimitedIp_Req
    */
	MESSAGE(Ev_MT_Net_UpdateLimitedIp_Rsp)
	BODY(mt::TBOOL32, result)
	BODY(mt::TU32, tOptType)
	BODY(mt::TLimitedIpItemInfo, TLimitedIpItemInfo)
	BODY(mt::TLimitedIpItemInfo, modLimitedIpItemInfo)

	 /*<<����osd�ķֱ�������>>
    *BODY ��EmVideoOutPutMode ����ֱ���ö��
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_HiSetHDResOutputResult_Ntf
	*/
	MESSAGE(Ev_MT_HiSetHDResOutput_Cmd)
    BODY(mt::TU32, EmVideoOutPutMode)

    /*<<����osd�ķֱ��ʽ��֪ͨ>>
	*BODY ��result ��ȡ��� 0�ɹ� 1ʧ��
    *BODY ��EmVideoOutPutMode ����ֱ���ö��
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_HiSetHDResOutput_Cmd
	*/
	MESSAGE(Ev_MT_HiSetHDResOutputResult_Ntf)
	BODY(mt::TU32, result)
	BODY(mt::TU32, EmVideoOutPutMode)


	/*<<֪ͨ�ն�ˢ�¶�ȡLICENSE>>
	 *���䷽��mtlicense<-dispatch<-mtservice
	*/
    MESSAGE(Ev_MT_ReadLicense_Cmd)


	 /*<<�ն˶�ȡLICENSE���֪֪ͨͨ>>
	 *���䷽��mtlicense->dispatch->mtservice
	*/
    MESSAGE(Ev_MT_ReadLicense_Ntf)
       
    /*<<��ʼ��ر�HID��д>>
    *���䷽��net->dispatch->mt
    */
    MESSAGE(Ev_MT_StartHID_Ntf)
    BODY(mt::TBOOL32, bstart)

    /*<<HID���ݴ���>>
    *���䷽��mtmp->dispatch->net
    */
    MESSAGE(Ev_MT_HIDMt2Net_Cmd)
    BODY(mt::TString, tHIDinfo)

    /*<<HID���ݴ���>>
    *���䷽��net->dispatch->mtmp
    */
    MESSAGE(Ev_MT_HIDNet2Mt_Ntf)
    BODY(mt::TBytes, tHIDinfo)

#if !defined(_MESSAGE_HELP_)
    EV_END(NETMANAGE) = EVSEG_NETWORK_END
};
#endif//_MESSAGE_HELP_

#define Is_Net_Msg(m) ((m) >= EV_BGN(NETMANAGE) && (m) <= EV_END(NETMANAGE))

#endif//_MTNETMSG_H_