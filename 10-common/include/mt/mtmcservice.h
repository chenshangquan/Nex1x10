/**===========================================================================
 * @file    mtmcservice.h
 * @brief   
 * @author  longwei
 * @date    
 * @version  
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/
#ifndef _MTMCSERVICE_H_
#define _MTMCSERVICE_H_
#include "kdvtype.h"
#include "mtstruct.h"


extern "C"
{
/**----------------------------------------------------------------------
* MtMcserviceStart
* 
* @brief   �ն˿ͻ��˽���ģ�������ӿ�
* 
* @param   [in] tMdlStartparam ��������
* @return  BOOL32 TRUE:�ɹ������� FALSE:����ʧ��
* @see     MtMcserviceStop()
------------------------------------------------------------------------*/
MTCBB_API BOOL32 MtMcserviceStart(TMdlStartParam &tMdlStartparam);

/**----------------------------------------------------------------------
* MtMcserviceStop
* 
* @brief   ����mcģ���˳��ӿ�
* 
* @param   void
* @return  BOOL32 TRUE:�ɹ��˳��� FALSE:�˳�ʧ��
* @see     MtMcserviceStart()
------------------------------------------------------------------------*/
MTCBB_API BOOL32 MtMcserviceStop();

};

#endif