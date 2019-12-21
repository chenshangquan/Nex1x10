/**===========================================================================
 * @file    mth323.h
 * @brief   mth323ģ���������˳�����
 * @author  wuhu
 * @date    
 * @version  
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _MT_MTAI_H_
#define _MT_MTAI_H_
#include "kdvtype.h"
#include "mtmacro.h"
/**----------------------------------------------------------------------
* MtaiStart
* 
* @brief   mth323ģ�������ӿ�
* 
* @param   [in] pvParam ��������
* @return  BOOL32 TRUE:�ɹ������� FALSE:����ʧ��
* @see     MtH323Stop()
------------------------------------------------------------------------*/
extern "C" MTCBB_API BOOL32 MtAiStart(void *pvParam);

/**----------------------------------------------------------------------
* MtH323Stop
* 
* @brief   mth323ģ���˳��ӿ�
* 
* @param   void
* @return  BOOL32 TRUE:�ɹ��˳��� FALSE:�˳�ʧ��
* @see     MtH323Stop()
------------------------------------------------------------------------*/
extern "C" MTCBB_API BOOL32 MtAiStop();



#endif  //_MT_MTAI_H_