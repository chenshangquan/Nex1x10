/**===========================================================================
 * @file    mtmp.h
 * @brief   �ṩmtmpģ�����ӿ�
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
* @brief   ����mtmp
* 
* @param   [in] tMdlStartParam ��������
* @return  BOOL32 TRUE:�ɹ��� FALSE:ʧ��
------------------------------------------------------------------------*/
BOOL32 MTCBB_API MtMpStart(TMdlStartParam &tMdlStartParam);

/**----------------------------------------------------------------------
* MtMpStop
* 
* @brief   ֹͣmtmp
* 
* @param   ��
* @return  BOOL32 TRUE:�ɹ��� FALSE:ʧ��
------------------------------------------------------------------------*/
BOOL32 MTCBB_API MtMpStop();

#ifdef __cplusplus
}
#endif

void mtmpregcmd();

#endif // _MTMP_H_