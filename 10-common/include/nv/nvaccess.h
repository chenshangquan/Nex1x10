/**===========================================================================
 * @file    nvaccess.h
 * @brief   
 * @author  longwei
 * @date    
 * @version  
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/
#ifndef _NVACCESS_H_
#define _NVACCESS_H_
#include "kdvtype.h"
#include "nvstruct.h"

extern "C"
{

/**----------------------------------------------------------------------
* NvAccessStart
* 
* @brief   终端客户端接入模块启动接口
* 
* @param   [in] tMdlStartparam 启动参数
* @return  BOOL32 TRUE:成功启动， FALSE:启动失败
* @see     NvAccessStop()
------------------------------------------------------------------------*/
NVCBB_API BOOL32 NvAccessStart(TMdlStartParam &tMdlStartparam);

/**----------------------------------------------------------------------
* NvAccessStop
* 
* @brief   消息调度模块退出接口
* 
* @param   void
* @return  BOOL32 TRUE:成功退出， FALSE:退出失败
* @see     NvAccessStart()
------------------------------------------------------------------------*/
NVCBB_API BOOL32 NvAccessStop();

};

#endif