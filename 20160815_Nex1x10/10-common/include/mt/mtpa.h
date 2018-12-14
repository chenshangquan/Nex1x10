/**===========================================================================
 * @file    mtpa.h
 * @brief   
 * @author  wuhu
 * @date    
 * @version  
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _MT_PA_H_
#define _MT_PA_H_
#include "mtstruct.h"
#include "mtmacro.h"

/**----------------------------------------------------------------------
* MtPAStart
* 
* @brief   mtpa模块启动接口
* 
* @param   [in] pvParam 启动参数
* @return  BOOL32 TRUE:成功启动， FALSE:启动失败
* @see     MtPaStop()
------------------------------------------------------------------------*/
extern "C" MTCBB_API BOOL32 MtPaStart( TMdlStartParam &tMdlStartParam );

/**----------------------------------------------------------------------
* MtPaStop
* 
* @brief   mtpa模块退出接口
* 
* @param   void
* @return  BOOL32 TRUE:成功退出， FALSE:退出失败
* @see     MtPAStart()
------------------------------------------------------------------------*/
extern "C" MTCBB_API BOOL32 MtPaStop();

#endif  //_MT_PA_H_