/**===========================================================================
 * @file    mth323.h
 * @brief   mth323ģ���������˳�����
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
* @brief   mth323ģ�������ӿ�
* 
* @param   [in] pvParam ��������
* @return  BOOL32 TRUE:�ɹ������� FALSE:����ʧ��
* @see     MtH323Stop()
------------------------------------------------------------------------*/
extern "C" MTCBB_API BOOL32 MtH323Start(void *pvParam);

/**----------------------------------------------------------------------
* MtH323Stop
* 
* @brief   mth323ģ���˳��ӿ�
* 
* @param   void
* @return  BOOL32 TRUE:�ɹ��˳��� FALSE:�˳�ʧ��
* @see     MtH323Stop()
------------------------------------------------------------------------*/
extern "C" MTCBB_API BOOL32 MtH323Stop();



#endif  //_MT_H323_H_