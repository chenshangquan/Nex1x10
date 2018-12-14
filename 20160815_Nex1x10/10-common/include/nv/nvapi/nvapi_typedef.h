/*******************************************************************************//**
*@file          nvapi_typedef.h
*@brief         提供nvapi所有typedef类型定义
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _NVAPI_TYPEDEF_H_
#define _NVAPI_TYPEDEF_H_
/**@addtogroup common 公用
*@{
*/

/**@addtogroup typedef 回调原型等定义
*@{
*/

#include "kdvtype.h"
#include <string>

/** 自定义std的字符串类型 */
typedef std::string  nvstring;

/** 自定义sesionid */
typedef u32  SessionID;
 
/** 使用者(UI)的回调定义(注意：回调上去的参数不允许改变其值) */
typedef u32 (*NOTIFY_NV_OBSERVER_CALLBACK)(u32 dwEvent, u8 *pbyBuf, u16 wBufLen, SessionID SID);

//升级服务器回调定义
typedef u32 (*NOTIFY_NV_UPGRADE_CALLBACK)(u32 dwEvent, u8 *pbyBuf, u16 wBufLen);
/**@}*/

/**@}*/
#endif //_NVAPI_TYPEDEF_H_