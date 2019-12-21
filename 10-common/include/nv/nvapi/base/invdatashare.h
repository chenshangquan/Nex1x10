/**===========================================================================
 * @file    $Id$
 * @brief   负责终端数据中心数据操作的接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_NVDATASHARE_H_
#define _I_NVDATASHARE_H_

#include "nvapi_typedef.h"
#include "nvapi_if.h"


/**---------------------------------------------------------------------------
 * @class   Interface INvEntity
 * @brief   负责终端数据中心数据操作的接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class INvDataShare : public INvApiIF
{
public:
	//还原默认值
	virtual u32 RestoreDefaultCfgInfo( const nv::TNVRestoreDefaultCfgInfo &tCfg );
	// 配置是否启用文件日志 emNv_Cfg_Log
	virtual u32 SetIsUsedFileLogon( BOOL32 bUsed );

	virtual BOOL32 SetIp(const EmNvIpType_Api, const s8 *);    //配置Ip
	virtual BOOL32 SetImixIp(const nv::TNVNetUsedInfo tNvNetInfoCfg);                     //配置Imix Ip

	// 获取是否启用文件日志 emNv_Cfg_Log
	virtual BOOL32 IsUsedFileLogon()=0;
	//设置时区
	virtual u32 SetTimeZoneCmd( const nv::EmNvTimeZone emCfg );
	//设置显示器配置
	virtual u32 SetScreenCmd( const nv::TNVScreenParamList tCfg );
	//设置显示器屏数
	virtual u32 SetScreenNumCmd( const nv::TU32 tCfg );
	//后台升级设置
	virtual u32 SetBackstageUpgradeCmd(const nv::TBOOL32 tbCfg);
	//设置非1080分辨率时显示策略
	virtual u32 SetVidResResizeModeCfgCmd(const nv::TS32 tMode);
	//设置双流外接源左右屏配置
	virtual u32 SetIsMtDualLeftCfgCmd(const nv::TBOOL32 tbCfg);
	
protected:
	virtual void BuildMsgMap();
	// 设置文件日志开关配置通知
	BOOL32 OnLogStatusCfg_Ntf( nvmsg::CNvMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnIpCfg_Ntf( nvmsg::CNvMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetTimeZoneCfg_Ntf( nvmsg::CNvMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetScreenCfg_Ntf( nvmsg::CNvMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetTerlInfoRt_Ntf( nvmsg::CNvMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetScreenNumCfg_Ntf( nvmsg::CNvMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetBackstageUpgradeCfg_Ntf( nvmsg::CNvMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnImixVidSrcSignalRt_Ntf( nvmsg::CNvMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSysUpgradeRt_Ntf( nvmsg::CNvMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetHdmiSwitchCfg_Ntf( nvmsg::CNvMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetVidResResizeModeCfg_Ntf( nvmsg::CNvMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetIsMtDualLeftCfg_Ntf( nvmsg::CNvMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
};

#endif // _I_NVDATASHARE_H_
