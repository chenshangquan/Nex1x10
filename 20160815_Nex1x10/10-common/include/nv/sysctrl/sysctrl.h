#ifndef _NVSYSCTRL_H_
#define _NVSYSCTRL_H_

#include "nvstruct.h"
#include "nvmacro.h"


/** ************************************************************
* 
* @brief    启动系统控制子系统入口函数
*
* @param	TMdlStartParam
* @return	无
* @note     启动系统控制子系统入口函数
*
************************************************************* */
NVCBB_API BOOL32 StartNvSysCtrl(TMdlStartParam  &tMdlStartParam, nv::TNVTerminalInfo tInfo);



/** ************************************************************
* 
* @brief    结束系统控制子系统函数
*
* @param	无
* @return	无
* @note     启动系统控制子系统入口函数
*
************************************************************* */
NVCBB_API BOOL32 StopNvSysCtrl();


/** ************************************************************
* 
* @brief    设置工作路径，仅windows平台有效
*
* @param	[in]  pszPath    工作路径，utf8编码
* @return	无
* @note     
*
************************************************************* */
NVCBB_API void SetSysWorkPathPrefix(const s8* pszPathPrefix);

/**
* SetAudioDecPCMCallBack
* @brief 设置音频解码器帧回调函数
*
* @param	[in]  pAudioCallBack    
* @return	
* @note  ， 仅（win32）
*/

NVCBB_API void SetAudioDecPCMCallBack(const void* pAudioCallBack);

/**
* SetVideoDecI420CallBack
* @brief 设置视频解码器帧回调函数
*
* @param	
* @return	 u32 返回启动结果
* @note  ， 仅（win32）
*/
NVCBB_API void SetVideoDecI420CallBack(const void* pVideoI420CallBack);
NVCBB_API void SetNvInfo(nv::TNVTerminalInfo tTerInfo);


#endif	// _NVSYSCTRL_H_