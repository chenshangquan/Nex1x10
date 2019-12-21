/**===========================================================================
 * @file    mth323.h
 * @brief   mth323模块启动和退出函数
 * @author  wuhu
 * @date    
 * @version  
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _MT_H323_H_
#define _MT_H323_H_
#include "kdvtype.h"
#include "mtmacro.h"
/**----------------------------------------------------------------------
* MtH323Start
* 
* @brief   mth323模块启动接口
* 
* @param   [in] pvParam 启动参数
* @return  BOOL32 TRUE:成功启动， FALSE:启动失败
* @see     MtH323Stop()
------------------------------------------------------------------------*/
extern "C" MTCBB_API BOOL32 MtH323Start(void *pvParam);

/**----------------------------------------------------------------------
* MtH323Stop
* 
* @brief   mth323模块退出接口
* 
* @param   void
* @return  BOOL32 TRUE:成功退出， FALSE:退出失败
* @see     MtH323Stop()
------------------------------------------------------------------------*/
extern "C" MTCBB_API BOOL32 MtH323Stop();



#endif  //_MT_H323_H_