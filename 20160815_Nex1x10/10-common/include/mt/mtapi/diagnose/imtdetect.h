/**===========================================================================
 * @file    $Id$
 * @brief   负责MtBaseApi终端诊断控制相关功能接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTDETECT_H_
#define _I_MTDETECT_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_base.h"
#include "mtapi_event_diagnose.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtDetect
 * @brief   负责MMtBaseApi终端抓包、日志以及带宽检测诊断控制相关功能接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtDetect : public IMtApiIF
{
public:
	//开启抓包命令
	virtual u32 StartNetCaptureCmd() = 0;
	//停止抓包命令
	virtual u32 StopNetCaptureCmd() = 0;
	//导出抓包文件请求
	virtual u32 ExportNetCaptureReq(IN CONST s8 *pchExportPath) = 0;
	//导出日志文件请求
	virtual u32 ExportLogReq(IN CONST s8 *pchExportPath) = 0;
	//带宽检测命令
	virtual u32 BandwidthCheckCmd(u32 dwIp) = 0;
    virtual u32 SetOsdSnapshotBrowseStateCmd(BOOL32 bBrowse) = 0;
    virtual u32 SetSyncTooltipBoxCmd(IN CONST s8 *pchUserId) = 0;
    virtual u32 GetNetCapFileListReq() = 0;
    virtual u32 DeleteNetCapFileCmd() = 0;
    virtual u32 ResetUserFileimgCmd(u32 dwFileType) = 0;
    virtual u32 GetNetCapStatusReq() = 0;
    virtual u32 ServerLinkTestCmd(BOOL32 bStart) = 0;
    virtual u32 ThreadDetectRegCmd(TMTServiceInfo_Api tInfo) = 0;
    virtual u32 ThreadDetectUpdateCmd(u32 dwAppId) = 0;

	//获取debug文件是否存在的请求
	virtual u32 GetIsDbgCfgExistReq() = 0;
	//获取麦克风信息
	virtual u32 GetMicrophoneInfoReq() = 0;
	//导出诊断信息文件命令
	virtual u32 ExportDiagInfoFileCmd(IN CONST s8 *pchExportPath) = 0;
	virtual u32 GetPacketDurationTimeReq() = 0;
	virtual u32 ElectricFanCmd(IN CONST BOOL32 bElectricFan) = 0;
	virtual u32 GetElectricFanTimeReq() = 0;

public:
	//获取抓包状态信息
	virtual TMtNetCapStateInfo_Api GetNetCaptureState() = 0;
	//获取带宽检测结果
	virtual TMTNetStatus_Api GetBandwidthTestResult() = 0;
	//获取当前抓包信息
	virtual TMtCurCapStatusInfo_Api GetCutCapStatusInfo() = 0;
private:


};

#endif // _I_MTDETECT_H_