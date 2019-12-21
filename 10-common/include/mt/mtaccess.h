/**===========================================================================
 * @file    mtaccess.h
 * @brief   
 * @author  longwei
 * @date    
 * @version  
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/
#ifndef _MTACCESS_H_
#define _MTACCESS_H_
#include "kdvtype.h"
#include "mtstruct.h"

extern "C"
{

/**----------------------------------------------------------------------
* MtAccessStart
* 
* @brief   �ն˿ͻ��˽���ģ�������ӿ�
* 
* @param   [in] tMdlStartparam ��������
* @return  BOOL32 TRUE:�ɹ������� FALSE:����ʧ��
* @see     MtAccessStop()
------------------------------------------------------------------------*/
MTCBB_API BOOL32 MtAccessStart(TMdlStartParam &tMdlStartparam);

/**----------------------------------------------------------------------
* MtAccessStop
* 
* @brief   ��Ϣ����ģ���˳��ӿ�
* 
* @param   void
* @return  BOOL32 TRUE:�ɹ��˳��� FALSE:�˳�ʧ��
* @see     MtAccessStart()
------------------------------------------------------------------------*/
MTCBB_API BOOL32 MtAccessStop();

};

#endif