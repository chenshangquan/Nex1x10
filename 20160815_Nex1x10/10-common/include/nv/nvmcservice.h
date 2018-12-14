/**===========================================================================
 * @file    nvmcservice.h
 * @brief   
 * @author  longwei
 * @date    
 * @version  
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/
#ifndef _NVMCSERVICE_H_
#define _NVMCSERVICE_H_
#include "kdvtype.h"
#include "nvstruct.h"


extern "C"
{
/**----------------------------------------------------------------------
* NvMcserviceStart
* 
* @brief   �ն˿ͻ��˽���ģ�������ӿ�
* 
* @param   [in] tMdlStartparam ��������
* @return  BOOL32 TRUE:�ɹ������� FALSE:����ʧ��
* @see     NvMcserviceStop()
------------------------------------------------------------------------*/
NVCBB_API BOOL32 NvMcserviceStart(TMdlStartParam &tMdlStartparam);

/**----------------------------------------------------------------------
* NvMcserviceStop
* 
* @brief   ����mcģ���˳��ӿ�
* 
* @param   void
* @return  BOOL32 TRUE:�ɹ��˳��� FALSE:�˳�ʧ��
* @see     NvMcserviceStart()
------------------------------------------------------------------------*/
NVCBB_API BOOL32 NvMcserviceStop();

};

#endif