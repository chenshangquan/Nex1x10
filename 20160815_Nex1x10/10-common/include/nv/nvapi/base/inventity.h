/**===========================================================================
 * @file    $Id$
 * @brief   负责终端自身基础功能控制的接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_NVENTITY_H_
#define _I_NVENTITY_H_

#include "nvapi_typedef.h"
#include "nvapi_if.h"
#include "nvapi_event_base.h"


/**---------------------------------------------------------------------------
 * @class   Interface INvEntity
 * @brief   负责终端自身基础功能控制的接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class INvEntity : public INvApiIF
{
public:
	//终端待机命令 (仅Embed)
	virtual u32 NvSleepCmd() = 0;
	//终端唤醒命令 (仅Embed)
	virtual u32 NvWakeupCmd() = 0;
	//终端重启命令
	virtual u32 NvRebootCmd() = 0;
	//恢复出厂设置
	virtual u32 NvResetCmd() = 0;
 
	//检测更新命令
	virtual u32 CheckUpgradeCmd( const nv::TNVUpgradeClientInfo& tInfo ) = 0;
	//取消检测更新命令
	virtual u32 CancelCheckUpgradeCmd( ) = 0;
	//开始下载文件命令
	virtual u32 StartDownloadUpgradeFileCmd( const nv::TString &tSaveFilePath, const u32 dwVerId ) = 0;
	//取消下载文件命令
	virtual u32 CancelDownloadUpgradeFileCmd() = 0;
	//开始升级命令
	virtual u32 StartUpgradeCmd(EmNvUpgradeType_Api emUpgradeType) = 0;
	virtual u32 UsbUpgradeFileCheckReq(const nv::TString &tstrFilePath) = 0;
	//关机回复
	virtual u32 NvTurnOffReq(const nv::TBOOL32 btTurnOff) = 0;
	//App升级状态通知
	virtual u32 NvAppUpgradeStatusNtf(const nv::TBOOL32 bUpgrade) = 0;
	//投屏器升级状态通知
	virtual u32 NvQkUpgradeStatusNtf(const nv::TBOOL32 bUpgrade) = 0;

	//无线投屏升级命令
	virtual u32 UpgradeQuickShareCmd( ) = 0;
	//获取无线投屏器版本
	virtual u32 GetQuickShareVersionCmd( ) = 0;
	virtual u32 CancelUpgradeQuickShareCmd( ) = 0;
	virtual u32 SetNovaCmd() = 0;
	virtual u32 DelAppZip() = 0;
	virtual u32 GetImixMode() = 0;
	virtual u32 GetQKVersionReq() = 0;
	virtual u32 NvAppUpgradeIsSucNtf(const nv::TBOOL32 bUpgrade) = 0;
	virtual u32 NvPadIsDownSucNtf(const nv::TBOOL32 bUpgrade) = 0;
	virtual u32 NvPadDownStateNtf(const nv::TBOOL32 bUpgrade) = 0;
	virtual u32 NvRouterIsDownSucNtf(const nv::TBOOL32 bUpgrade) = 0;
	virtual u32 NvRouterDownStateNtf(const nv::TBOOL32 bUpgrade) = 0;
	virtual u32 GetPadVersionReq() = 0;
	virtual u32 NvRouterUpgradeStateNty(const nv::TBOOL32 bState) = 0;
	//virtual u32 NvClearDataFolderSucNty(const nv::TBOOL32 bState) = 0;
	//virtual u32 NvCancelFileCmd(const nv::TString tFile) = 0;
public:
	//是否待机(仅Embed)
	virtual BOOL32 IsSleeped() = 0;
	//获取待机倒计时剩余时间(仅Embed)
	virtual u16 GetSleepReaminTime() = 0;

	//界面同步命令
	virtual u32 UISynchronize_Cmd( const EmNvUISynchronizeReason_Api emReason ) = 0 ;

private:

};

#endif // _I_NVENTITY1_H_