#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "mtstruct.h"
#include "kdvtype.h"
#include "mtmacro.h"

#ifdef __cplusplus
extern "C" {
#endif

/**----------------------------------------------------------------------
* AgentStart
* 
* @brief   启动camera
* 
* @param   [in] tMdlStartParam 启动参数
* @return  BOOL32 TRUE:成功， FALSE:失败
------------------------------------------------------------------------*/
BOOL32 MTCBB_API CameraStart(TMdlStartParam &tMdlStartParam);

/**----------------------------------------------------------------------
* AgentStop
* 
* @brief   停止camera
* 
* @param   无
* @return  BOOL32 TRUE:成功， FALSE:失败
------------------------------------------------------------------------*/
BOOL32 MTCBB_API CameraStop();

#ifdef __cplusplus
}
#endif

#endif // _CAMERA_H_