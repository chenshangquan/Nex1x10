/*******************************************************************************//**
*@file          nvapi_kernel.h
*@brief         提供nv终端核心业务的启动控制接口
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _NVAPI_KERNEL_H_
#define _NVAPI_KERNEL_H_
/**@addtogroup api API接口
*@{
*/

/**@addtogroup kernelapi 终端内核API
*@{
*/

#include <string.h>
#include "nvapi_export.h"
#include "nvapi_typedef.h"
#include "nvapi_struct.h"


/**
* KdvNv_NvStart
* @brief  启动一个nv终端
*
* @param	[in] TTerminalInfo_Api 终端信息
*           (
*           其中，achTypeName按照具体的需求文档填写（以最新的为准：终端设备类型名称.xlsx）
*           )
* @return	u32 返回启动结果
* @note KdvNv_NvStop
*/
KdvNvAPI u32 KdvNvCALL KdvNv_NvStart( /*IN CONST nv::TTerminalInfo tTerminalInfo*/ );



/**
* KdvNv_NvStart
* @brief 停止一个nv终端
*
* @param	[in] void
* @return	u32 返回启动结果
* @note KdvNv_NvStart
*/
KdvNvAPI u32 KdvNvCALL KdvNv_NvStop();




/**
* KdvNv_SetSysWorkPathPrefix
* @brief 设置路径前缀
*
* @param	[in]  pszPathPrefix    路径前缀，utf8编码
* @return	 u32 返回启动结果
* @note  不支持多进程部署方式，仅windows、移动android平台有效
*/
KdvNvAPI u32 KdvNvCALL KdvNv_SetSysWorkPathPrefix( IN CONST s8 *pszPathPrefix );


typedef void (*NV_PVIDEOI420CALLBACK_KERNEL)(u8* pData, s32 nData, s16 nWidth, s16 nHeight, u32 dwContext);
typedef void (*NV_PAUDIOPCMCALLBACK_KERNEL)(u8 *pBuf, s32 nSize, u32 dwSampleRate, u32 dwBitWidth, u32 dwChannel, u32 dwContext);


/**
* KdvNv_SetAudioDecPCMCallBack
* @brief 设置音频解码器帧回调函数
*
* @param	[in]  pAudioCallBack    
* @return	 u32 返回启动结果
* @note  ， 仅（win32）
*/
KdvNvAPI u32 KdvNvCALL KdvNv_SetAudioDecPCMCallBack( IN NV_PAUDIOPCMCALLBACK_KERNEL pAudioCallBack );

/**
* KdvNv_SetVideoDecI420CallBack
* @brief 设置视频解码器帧回调函数
*
* @param	[in]  pVideoI420CallBack    
* @return	 u32 返回启动结果
* @note  ， 仅（win32）
*/
KdvNvAPI u32 KdvNvCALL KdvNv_SetVideoDecI420CallBack( IN NV_PVIDEOI420CALLBACK_KERNEL pVideoI420CallBack );

/**@}*/

/**@}*/
#endif //_NVAPI_KERNEL_H_