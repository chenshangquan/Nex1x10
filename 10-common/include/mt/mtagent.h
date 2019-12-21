/**===========================================================================
 * @file    mtagent.h
 * @brief   �ṩmtagentģ�����ӿ�
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
* @brief   ����mtagent
* 
* @param   [in] tMdlStartParam ��������
* @return  BOOL32 TRUE:�ɹ��� FALSE:ʧ��
------------------------------------------------------------------------*/
BOOL32 MTCBB_API AgentStart(TMdlStartParam &tMdlStartParam);

/**----------------------------------------------------------------------
* AgentStop
* 
* @brief   ֹͣmtagent
* 
* @param   ��
* @return  BOOL32 TRUE:�ɹ��� FALSE:ʧ��
------------------------------------------------------------------------*/
BOOL32 MTCBB_API AgentStop();

#ifdef __cplusplus
}
#endif

#endif // _MTAGENT_H_