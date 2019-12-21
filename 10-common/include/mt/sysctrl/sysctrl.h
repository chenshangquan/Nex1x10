#ifndef _MTSYSCTRL_H_
#define _MTSYSCTRL_H_

#include "mtstruct.h"
#include "mtmacro.h"


/** ************************************************************
* 
* @brief    启动系统控制子系统入口函数
*
* @param	TMdlStartParam
* @return	无
* @note     启动系统控制子系统入口函数
*
************************************************************* */
MTCBB_API BOOL32 StartMtSysCtrl(TMdlStartParam  &tMdlStartParam, mt::TTerminalInfo tInfo);



/** ************************************************************
* 
* @brief    结束系统控制子系统函数
*
* @param	无
* @return	无
* @note     启动系统控制子系统入口函数
*
************************************************************* */
MTCBB_API BOOL32 StopMtSysCtrl();


/** ************************************************************
* 
* @brief    设置工作路径，仅windows平台有效
*
* @param	[in]  pszPath    工作路径，utf8编码
* @return	无
* @note     
*
************************************************************* */
MTCBB_API void SetSysWorkPathPrefix(const s8* pszPathPrefix);

/**
* SetAudioDecPCMCallBack
* @brief 设置音频解码器帧回调函数
*
* @param	[in]  pAudioCallBack    
* @return	
* @note  ， 仅（win32）
*/

MTCBB_API void SetAudioDecPCMCallBack(const void* pAudioCallBack);

/**
* SetVideoDecI420CallBack
* @brief 设置视频解码器帧回调函数
*
* @param	
* @return	 u32 返回启动结果
* @note  ， 仅（win32）
*/
MTCBB_API void SetVideoDecI420CallBack(const void* pVideoI420CallBack);
MTCBB_API void SetMtInfo(mt::TTerminalInfo tTerInfo);

/* 
* StartSysDS
* @brief    启动系统数据共享
*
* @param	无
* @return	无
* @note     暂时用于硬终端
*/
MTCBB_API void StartSysDS();


#endif	// _MTSYSCTRL_H_