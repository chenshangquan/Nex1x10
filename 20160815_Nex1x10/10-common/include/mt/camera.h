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
* @brief   ����camera
* 
* @param   [in] tMdlStartParam ��������
* @return  BOOL32 TRUE:�ɹ��� FALSE:ʧ��
------------------------------------------------------------------------*/
BOOL32 MTCBB_API CameraStart(TMdlStartParam &tMdlStartParam);

/**----------------------------------------------------------------------
* AgentStop
* 
* @brief   ֹͣcamera
* 
* @param   ��
* @return  BOOL32 TRUE:�ɹ��� FALSE:ʧ��
------------------------------------------------------------------------*/
BOOL32 MTCBB_API CameraStop();

#ifdef __cplusplus
}
#endif

#endif // _CAMERA_H_