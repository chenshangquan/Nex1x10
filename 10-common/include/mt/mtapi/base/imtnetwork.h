/**===========================================================================
 * @file    $Id$
 * @brief   ����MtBaseApi�ն�������ع��ܽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTNETWORK_H_
#define _I_MTNETWORK_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtNetwork
 * @brief   ����MtBaseApi�ն�������ع��ܽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class IMtNetwork: public IMtApiIF
{
public:

	//PPPoE ������������
	virtual u32 PPPoEConnectCmd() = 0;

	//PPPoE �Ͽ�����
	virtual u32 PPPoEDisConnectCmd() = 0;

	//PPPoE ����״̬��ѯ
	virtual u32 PPPoEGetLinkStateReq() = 0;

	//PPPoE ͳ����Ϣ��ѯ
	virtual u32 PPPoEGetStatisInfoReq(CONST u32 dwEthId) = 0;

	//dhcp��Լ��״̬��Ϣ��ѯ
	virtual u32 EthernetGetDHCPLeaseInfoReq(CONST u32 dwEthId) = 0;

	//��ȡ����·������
	virtual u32 RouteGetAllRouteReq() = 0;

	//����һ��·������
	virtual u32 RouteAddRouteReq(CONST TRouteItemInfo_Api  & tRouteInfo) = 0;

	//ɾ��һ��·������
	virtual u32 RouteDelRouteReq(CONST TRouteItemInfo_Api  & tRouteInfo) = 0;

	//�޸�һ��·������
	virtual u32 RouteModifyRouteReq(CONST TRouteItemInfo_Api &  tOldRouteInfo,CONST TRouteItemInfo_Api  & tNewRouteInfo) = 0;

	//Wifi �ȵ�ɨ������
	virtual u32 WIFIStartScanReq() = 0;

	//Wifi ����ģʽ��ѯ����
	virtual u32 WIFIGetWorkModeReq() = 0;

	//Wifi �ȵ���������
	virtual u32 WIFIConnectCmd( CONST TWifiConnParam_Api & tWifiParam ) = 0;

	//Wifi �Ͽ��ȵ���������
	virtual u32 WIFIDisConnectCmd() = 0;

	//Wifi ����״̬��ѯ
	virtual u32 WifiGetLinkStateReq() = 0;	

	//Wifi ��ȡ��ǰ���ӵ�Wifi�ͻ�����������
	virtual u32 WifiGetModClientPropertyReq() = 0;

	//Wifi ��ȡ��ǰ���ӵ�Wifi�ͻ�����ϸ��Ϣ����
	virtual u32 WifiGetWifiCurConnectedInfoReq() = 0;

	//Wifi ��ǰ���ӵ�Wifiͳ����Ϣ��ѯ����
	virtual u32 WifiGetCurWifiStatisInfoReq() = 0;

	//MobileData ����ģʽ��Ϣ��ѯ����
	virtual u32 MobileDataGetWorkModeReq() = 0;

	//MobileData ��ѯ�ƶ��������Ӻ���ϸ��Ϣ����
	virtual u32 MobileDataGetDetailInfoReq() = 0;

	//MobileData ��ǰ���ӵ��ƶ�����ͳ����Ϣ��ѯ����
	virtual u32 MobileDataGetCurStatisInfoReq() = 0;

	//ping����������
	virtual u32 PingTestReq(CONST TPingTestParam_Api &tPingTestParam) = 0; 

	//PPPoE ״̬��ȡ
	virtual TPPPoEState_Api GetPPPoELinkState() = 0;
	//��ȡ�ȵ�ɨ����
	virtual TWifiScanResultList_Api GetWifiScanList() = 0;
	//��ǰ����״̬
	virtual TWifiCurDetailInfo_Api GetWifiCurDetailInfo() = 0;
	//Wifiͳ����Ϣ
	virtual TWifiStatisInfo_Api GetWifiStatisInfo() = 0;
	//��ȡ��̫����ѡIP����
	virtual u32 EthernetGetPreferredIpParamReq(const u32 dwEthId) = 0;
	//��ѯDNS��Ӧ��IP��Ϣ����
	virtual u32 EthernetGetIpByDNSInfoReq(const TDNSNameToIpInfo_Api &tDnsName) = 0;

	//���õ�ǰ����ʱ����Ϣ
	virtual u32 SetSysDataTimeReq(const TMTTime_Api &tTime) = 0;

	//��ѯ��ǰ����ʱ����Ϣ
	virtual u32 GetSysDataTimeReq() = 0;

	//��ѯ��ǰNTP������״̬����
	virtual u32 GetNTPSvrParamReq() = 0;

	//����NTP�������ر�״̬
	virtual u32 SetNTPSvrParamReq(const TMTNTPInfo_Api &tNtpInfo) = 0;

	//��ǰ����ʱ����Ϣ ״̬��ȡ
	virtual TMTTime_Api GetSysDataTime() = 0;

	//��ǰNTP������״̬��ȡ
	virtual TMTNTPInfo_Api GetNTPSvrParam() = 0;

	virtual u32 SetFtpTelnetAccountInfoReq(TMTFtpTelnetAccountInfo_Api tAccountInfo) = 0;
    virtual u32 SetWIFIModClientPropertyCmd(const TWifiConfiguration_Api tWifiConfig) = 0;
    virtual u32 GetEthernetLinkStateReq() = 0;
	virtual u32 SetWirelessScreenCmd( const BOOL32 bStart ) = 0;
	virtual TWifiWirelessScreenInfo_Api GetWirelessScreen() = 0;
	virtual u32 GetWirelessScreenReq() = 0;
	virtual u32 SetWifiHotForgetReq( const u32 dwHotspotId )  = 0;
	virtual u32 RouteGetDefaultRouteReq( ) = 0;

	//����һ��ftp/telnet�޶�ip����
	virtual u32 FtpTelnetAddIpItemReq(CONST TMtLimitIpInfo_Api  & tIpInfo) = 0;
	
	//ɾ��һ��ftp/telnet�޶�ip����
	virtual u32 FtpTelnetDelIpItemReq(CONST TMtLimitIpInfo_Api  & tIpInfo) = 0;
	
	//�޸�һ��ftp/telnet�޶�ip����
	virtual u32 FtpTelnetModifyIpItemReq(CONST TMtLimitIpInfo_Api &  tOldIpInfo,CONST TMtLimitIpInfo_Api  & tNewIpInfo) = 0;
	//����ftp/telnet�޶�ip��������Ϣ
	virtual u32 FtpTelnetSetLimitIpCfgCmd(CONST TMtLimitIpInfoList_Api & tIpInfo) = 0;
};

#endif // _I_MTNETWORK_H_