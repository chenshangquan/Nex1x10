/**===========================================================================
 * @file    mtagent.h
 * @brief   提供mtagent模块对外接口
 * @author  ruiyigen
 * @date    20140707
 * @version 5.0 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
============================================================================*/
#if !defined(_MTAGENT_H_)
#define _MTAGENT_H_
#include "kdvtype.h"
#include "mtstruct.h"


#ifdef __cplusplus
extern "C" {
#endif

/**----------------------------------------------------------------------
* AgentStart
* 
* @brief   启动mtagent
* 
* @param   [in] tMdlStartParam 启动参数
* @return  BOOL32 TRUE:成功， FALSE:失败
------------------------------------------------------------------------*/
BOOL32 MTCBB_API AgentStart(TMdlStartParam &tMdlStartParam);

/**----------------------------------------------------------------------
* AgentStop
* 
* @brief   停止mtagent
* 
* @param   无
* @return  BOOL32 TRUE:成功， FALSE:失败
------------------------------------------------------------------------*/
BOOL32 MTCBB_API AgentStop();

#ifdef __cplusplus
}
#endif

#endif // _MTAGENT_H_