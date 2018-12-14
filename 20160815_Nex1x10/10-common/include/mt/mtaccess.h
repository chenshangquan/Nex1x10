/**===========================================================================
 * @file    mtaccess.h
 * @brief   
 * @author  longwei
 * @date    
 * @version  
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/
#ifndef _MTACCESS_H_
#define _MTACCESS_H_
#include "kdvtype.h"
#include "mtstruct.h"

extern "C"
{

/**----------------------------------------------------------------------
* MtAccessStart
* 
* @brief   终端客户端接入模块启动接口
* 
* @param   [in] tMdlStartparam 启动参数
* @return  BOOL32 TRUE:成功启动， FALSE:启动失败
* @see     MtAccessStop()
------------------------------------------------------------------------*/
MTCBB_API BOOL32 MtAccessStart(TMdlStartParam &tMdlStartparam);

/**----------------------------------------------------------------------
* MtAccessStop
* 
* @brief   消息调度模块退出接口
* 
* @param   void
* @return  BOOL32 TRUE:成功退出， FALSE:退出失败
* @see     MtAccessStart()
------------------------------------------------------------------------*/
MTCBB_API BOOL32 MtAccessStop();

};

#endif