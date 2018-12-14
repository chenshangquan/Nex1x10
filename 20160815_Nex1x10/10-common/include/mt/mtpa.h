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
* @brief   mtpaģ�������ӿ�
* 
* @param   [in] pvParam ��������
* @return  BOOL32 TRUE:�ɹ������� FALSE:����ʧ��
* @see     MtPaStop()
------------------------------------------------------------------------*/
extern "C" MTCBB_API BOOL32 MtPaStart( TMdlStartParam &tMdlStartParam );

/**----------------------------------------------------------------------
* MtPaStop
* 
* @brief   mtpaģ���˳��ӿ�
* 
* @param   void
* @return  BOOL32 TRUE:�ɹ��˳��� FALSE:�˳�ʧ��
* @see     MtPAStart()
------------------------------------------------------------------------*/
extern "C" MTCBB_API BOOL32 MtPaStop();

#endif  //_MT_PA_H_