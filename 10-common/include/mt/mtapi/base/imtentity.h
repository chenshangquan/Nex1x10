/**===========================================================================
 * @file    $Id$
 * @brief   负责终端自身基础功能控制的接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTENTITY_H_
#define _I_MTENTITY_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_base.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtEntity
 * @brief   负责终端自身基础功能控制的接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtEntity : public IMtApiIF
{
public:
	//终端待机命令 (仅Embed)
	virtual u32 MtSleepCmd() = 0;
	//终端唤醒命令 (仅Embed)
	virtual u32 MtWakeupCmd() = 0;
	//终端重启命令
	virtual u32 MtRebootCmd() = 0;
	//恢复出厂设置
	virtual u32 MtResetCmd( const BOOL32 bDelCfgFile ) = 0;
 
	//检测更新命令
	virtual u32 CheckUpgradeCmd( const TMTUpgradeClientInfo_Api& tInfo ) = 0;
	//取消检测更新命令
	virtual u32 CancelCheckUpgradeCmd( ) = 0;
	//开始下载文件命令
	virtual u32 StartDownloadUpgradeFileCmd( const s8* pchSaveFilePath, const u32 dwVerId ) = 0;
	//取消下载文件命令
	virtual u32 CancelDownloadUpgradeFileCmd() = 0;
	//开始升级命令
	virtual u32 StartUpgradeCmd(EmUpgradeType_Api emUpgradeType) = 0;

	virtual u32 UsbUpgradeFileCheckReq(const s8 *pchFilePath) = 0;


public:
	//是否待机(仅Embed)
	virtual BOOL32 IsSleeped() = 0;
	//获取待机倒计时剩余时间(仅Embed)
	virtual u16 GetSleepReaminTime() = 0;
    virtual u32 GetSkyShareVerReq() = 0;
	virtual u32 GetSkyMtcVerRtReq() = 0;
	virtual u32 ResetOsdAdminPwdCmd() = 0;
	virtual u32 SetDeviceCameraSleepCmd( const BOOL32 bSleep ) = 0;

	//界面同步命令
	virtual u32 UISynchronize_Cmd( const EmUISynchronizeReason_Api emReason ) = 0 ;

private:

};

#endif // _I_MTENTITY1_H_