/**===========================================================================
 * @file    mtmp.h
 * @brief   提供mtmp模块对外接口
 * @author  ruiyigen
 * @date    20140707
 * @version 5.0
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
============================================================================*/
#if !defined(_MTMP_H_)
#define _MTMP_H_
#include "kdvtype.h"
#include "mtstruct.h"
#include "mtmacro.h"


#ifdef __cplusplus
extern "C" {
#endif

/**----------------------------------------------------------------------
* MtMpStart
* 
* @brief   启动mtmp
* 
* @param   [in] tMdlStartParam 启动参数
* @return  BOOL32 TRUE:成功， FALSE:失败
------------------------------------------------------------------------*/
BOOL32 MTCBB_API MtMpStart(TMdlStartParam &tMdlStartParam);

/**----------------------------------------------------------------------
* MtMpStop
* 
* @brief   停止mtmp
* 
* @param   无
* @return  BOOL32 TRUE:成功， FALSE:失败
------------------------------------------------------------------------*/
BOOL32 MTCBB_API MtMpStop();

#ifdef __cplusplus
}
#endif

void mtmpregcmd();

#endif // _MTMP_H_