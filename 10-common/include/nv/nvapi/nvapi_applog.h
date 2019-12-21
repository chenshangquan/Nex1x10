/*******************************************************************************//**
*@file          nvapi_AppLog.h
*@brief         提供给界面输出到打印日志的SDK接口
*
*@author        youjiaixng
*@version       1.0    
*@date          20180611
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
/**@addtogroup api API接口
*@{
*/

/**@addtogroup quickshareapi 
*@{
*/
#ifndef _NVAPI_APPLOG_H_
#define _NVAPI_APPLOG_H_

#include <string.h>
#include "nvapi_export.h"
#include "kdvtype.h"
#include "nvstruct.pb.h"


/*******************************************************************************//**
*@brief         初始化日志客户端模块
*KdvNv_LogInitalize
*
*@param[in]     
*@return        BOOL32  TRUE：成功， FALSE：失败
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_LogInitalize(nv::TString tIP, nv::TString tCltTag);

/*******************************************************************************//**
*@brief         注册日志模块
*KdvNv_RegLogModule
*
*@param[in]     
*@return        u32  0：成功， 1：失败
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_RegLogModule(nv::TString tModuleID, nv::TString tModuleName );

/*******************************************************************************//**
*@brief         打印输出到日志模块
*KdvNv_LogPrintf
*
*@param[in]     
*@return        u32  0：成功， 1：失败
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_LogPrintf(nv::TS32 tLevel, nv::TString tModuleID, nv::TString tLogContent);

/*******************************************************************************//**
*@brief         放开打印
*KdvNv_LogPrintf
*
*@param[in]     
*@return        u32  0：成功， 1：失败
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_LogOn(nv::TString tModuleID);

/*******************************************************************************//**
*@brief         关闭打印
*KdvNv_LogPrintf
*
*@param[in]     
*@return        u32  0：成功， 1：失败
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_LogOff(nv::TString tModuleID);

/*******************************************************************************//**
*@brief         放开debug打印
*KdvNv_LogPrintf
*
*@param[in]     
*@return        u32  0：成功， 1：失败
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_DebugOn(nv::TString tModuleID);

/*******************************************************************************//**
*@brief         关闭debug打印
*KdvNv_LogPrintf
*
*@param[in]     
*@return        u32  0：成功， 1：失败
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_DebugOff(nv::TString tModuleID);



/**@}*/
#endif 