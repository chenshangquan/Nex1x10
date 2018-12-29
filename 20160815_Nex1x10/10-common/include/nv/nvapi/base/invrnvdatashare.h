/**===========================================================================
 * @file    $Id$
 * @brief   负责数据共享请求相关功能接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_NVRNVDATSHARE_H_
#define _I_NVRNVDATSHARE_H_

#include "nvapi_typedef.h"
#include "nvapi_if.h"
#include "nvapi_event_base.h"
#include "invdatashare.h"


/**---------------------------------------------------------------------------
 * @class   Interface INvConfig
 * @brief   负责终端基础配置请求相关功能接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class INvRnvDataShare : public INvDataShare
{
public:
	// 获取是否启用文件日志请求
	virtual u32 GetIsUsedFileLogonReq()=0;
	virtual BOOL32 GetIpReq(const EmNvIpType_Api )=0;                       //获取Ip请求
	//获取时区
	virtual u32 GetTimeZoneReq()=0;
	//获取显示器参数
	virtual u32 GetScreenCfgReq()=0;
	//获取终端版本信息请求
	virtual u32 GetTerinfoRtReq()=0;
	//获取显示器数目
	virtual u32 GetScreenNumCfgReq()=0;
    //获取后台升级配置请求
	virtual u32 GetBackstageUpgradeCfgReq()=0;
	//获取视频信号请求
	virtual u32 GetImixVidSrcSignalRtReq()=0;
	//获取HDMI开关状态
	virtual u32 GetHdmiSwitchCfgReq()=0;
	//获取非1080分辨率时显示策略
	virtual u32 GetVidResResizeModeCfgReq() = 0;
	//获取双流外接源左右屏配置
	virtual u32 GetIsMtDualLeftCfgReq() = 0;
	//获取版本信息
	virtual u32 GetImixVerInfoRtReq() = 0;
	//获取nv版本当前信息
	virtual u32 GetNvVerInfoReq() = 0;
	//获取imix版本是否与JD平台版本一致
	virtual u32 GetNVVerIsSameAsJDServeReq(IN CONST nv::TString tRouterVer) = 0;
	//设置imix是否从JD平台下载版本
	virtual u32 SetNVIsUpgradeFromJDServerCmd(IN CONST nv::TBOOL32 tUpgrade) = 0;
private:

};

#endif // _I_NVRNVDATSHARE_H_
