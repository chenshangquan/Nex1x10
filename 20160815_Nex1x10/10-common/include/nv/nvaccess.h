/**===========================================================================
 * @file    nvaccess.h
 * @brief   
 * @author  longwei
 * @date    
 * @version  
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/
#ifndef _NVACCESS_H_
#define _NVACCESS_H_
#include "kdvtype.h"
#include "nvstruct.h"

extern "C"
{

/**----------------------------------------------------------------------
* NvAccessStart
* 
* @brief   �ն˿ͻ��˽���ģ�������ӿ�
* 
* @param   [in] tMdlStartparam ��������
* @return  BOOL32 TRUE:�ɹ������� FALSE:����ʧ��
* @see     NvAccessStop()
------------------------------------------------------------------------*/
NVCBB_API BOOL32 NvAccessStart(TMdlStartParam &tMdlStartparam);

/**----------------------------------------------------------------------
* NvAccessStop
* 
* @brief   ��Ϣ����ģ���˳��ӿ�
* 
* @param   void
* @return  BOOL32 TRUE:�ɹ��˳��� FALSE:�˳�ʧ��
* @see     NvAccessStart()
------------------------------------------------------------------------*/
NVCBB_API BOOL32 NvAccessStop();

};

#endif