/**===========================================================================
 * @file    $Id$
 * @brief   负责MtBaseApi终端网络相关功能接口定义
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
 * @brief   负责MtBaseApi终端网络相关功能接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class IMtNetwork: public IMtApiIF
{
public:

	//PPPoE 拨号连接请求
	virtual u32 PPPoEConnectCmd() = 0;

	//PPPoE 断开请求
	virtual u32 PPPoEDisConnectCmd() = 0;

	//PPPoE 连接状态查询
	virtual u32 PPPoEGetLinkStateReq() = 0;

	//PPPoE 统计信息查询
	virtual u32 PPPoEGetStatisInfoReq(CONST u32 dwEthId) = 0;

	//dhcp租约和状态信息查询
	virtual u32 EthernetGetDHCPLeaseInfoReq(CONST u32 dwEthId) = 0;

	//获取所有路由请求
	virtual u32 RouteGetAllRouteReq() = 0;

	//新增一条路由请求
	virtual u32 RouteAddRouteReq(CONST TRouteItemInfo_Api  & tRouteInfo) = 0;

	//删除一条路由请求
	virtual u32 RouteDelRouteReq(CONST TRouteItemInfo_Api  & tRouteInfo) = 0;

	//修改一条路由请求
	virtual u32 RouteModifyRouteReq(CONST TRouteItemInfo_Api &  tOldRouteInfo,CONST TRouteItemInfo_Api  & tNewRouteInfo) = 0;

	//Wifi 热点扫描请求
	virtual u32 WIFIStartScanReq() = 0;

	//Wifi 工作模式查询请求
	virtual u32 WIFIGetWorkModeReq() = 0;

	//Wifi 热点连接请求
	virtual u32 WIFIConnectCmd( CONST TWifiConnParam_Api & tWifiParam ) = 0;

	//Wifi 断开热点连接请求
	virtual u32 WIFIDisConnectCmd() = 0;

	//Wifi 连接状态查询
	virtual u32 WifiGetLinkStateReq() = 0;	

	//Wifi 获取当前连接的Wifi客户端属性请求
	virtual u32 WifiGetModClientPropertyReq() = 0;

	//Wifi 获取当前连接的Wifi客户端详细信息请求
	virtual u32 WifiGetWifiCurConnectedInfoReq() = 0;

	//Wifi 当前连接的Wifi统计信息查询请求
	virtual u32 WifiGetCurWifiStatisInfoReq() = 0;

	//MobileData 工作模式信息查询请求
	virtual u32 MobileDataGetWorkModeReq() = 0;

	//MobileData 查询移动数据连接后详细消息请求
	virtual u32 MobileDataGetDetailInfoReq() = 0;

	//MobileData 当前连接的移动数据统计信息查询请求
	virtual u32 MobileDataGetCurStatisInfoReq() = 0;

	//ping包测试命令
	virtual u32 PingTestReq(CONST TPingTestParam_Api &tPingTestParam) = 0; 

	//PPPoE 状态获取
	virtual TPPPoEState_Api GetPPPoELinkState() = 0;
	//获取热点扫描结果
	virtual TWifiScanResultList_Api GetWifiScanList() = 0;
	//当前连接状态
	virtual TWifiCurDetailInfo_Api GetWifiCurDetailInfo() = 0;
	//Wifi统计信息
	virtual TWifiStatisInfo_Api GetWifiStatisInfo() = 0;
	//获取以太网首选IP参数
	virtual u32 EthernetGetPreferredIpParamReq(const u32 dwEthId) = 0;
	//查询DNS对应的IP信息请求
	virtual u32 EthernetGetIpByDNSInfoReq(const TDNSNameToIpInfo_Api &tDnsName) = 0;

	//设置当前日期时间信息
	virtual u32 SetSysDataTimeReq(const TMTTime_Api &tTime) = 0;

	//查询当前日期时间信息
	virtual u32 GetSysDataTimeReq() = 0;

	//查询当前NTP服务开启状态请求
	virtual u32 GetNTPSvrParamReq() = 0;

	//设置NTP服务开启关闭状态
	virtual u32 SetNTPSvrParamReq(const TMTNTPInfo_Api &tNtpInfo) = 0;

	//当前日期时间信息 状态获取
	virtual TMTTime_Api GetSysDataTime() = 0;

	//当前NTP服务开启状态获取
	virtual TMTNTPInfo_Api GetNTPSvrParam() = 0;

	virtual u32 SetFtpTelnetAccountInfoReq(TMTFtpTelnetAccountInfo_Api tAccountInfo) = 0;
    virtual u32 SetWIFIModClientPropertyCmd(const TWifiConfiguration_Api tWifiConfig) = 0;
    virtual u32 GetEthernetLinkStateReq() = 0;
	virtual u32 SetWirelessScreenCmd( const BOOL32 bStart ) = 0;
	virtual TWifiWirelessScreenInfo_Api GetWirelessScreen() = 0;
	virtual u32 GetWirelessScreenReq() = 0;
	virtual u32 SetWifiHotForgetReq( const u32 dwHotspotId )  = 0;
	virtual u32 RouteGetDefaultRouteReq( ) = 0;

	//新增一条ftp/telnet限定ip请求
	virtual u32 FtpTelnetAddIpItemReq(CONST TMtLimitIpInfo_Api  & tIpInfo) = 0;
	
	//删除一条ftp/telnet限定ip请求
	virtual u32 FtpTelnetDelIpItemReq(CONST TMtLimitIpInfo_Api  & tIpInfo) = 0;
	
	//修改一条ftp/telnet限定ip请求
	virtual u32 FtpTelnetModifyIpItemReq(CONST TMtLimitIpInfo_Api &  tOldIpInfo,CONST TMtLimitIpInfo_Api  & tNewIpInfo) = 0;
	//设置ftp/telnet限定ip段配置信息
	virtual u32 FtpTelnetSetLimitIpCfgCmd(CONST TMtLimitIpInfoList_Api & tIpInfo) = 0;
};

#endif // _I_MTNETWORK_H_