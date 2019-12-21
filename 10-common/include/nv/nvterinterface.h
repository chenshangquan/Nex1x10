/**===========================================================================
 * @file    nvterinterface.h
 * @brief   
 * @author  yanglei
 * @date    
 * @version  
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/
#ifndef _NVTERINTERFACE_H_
#define _NVTERINTERFACE_H_
#include "kdvtype.h"
#include "nvstruct.h"
#include "nvmacro.h"

//#include "osp.h"
//#include "kdvtype.h"
extern "C"
{
	/**----------------------------------------------------------------------
	* NvTerinterfaceStart
	* 
	* @brief   �ն˿ͻ��˽���ģ�������ӿ�
	* 
	* @param   [in] tMdlStartparam ��������
	* @return  BOOL32 TRUE:�ɹ������� FALSE:����ʧ��
	* @see     NvTerinterfaceStop()
	------------------------------------------------------------------------*/
	NVCBB_API BOOL32 NvTerinterfaceStart(TMdlStartParam &tMdlStartparam);

	/**----------------------------------------------------------------------
	* NvTerinterfaceStop
	* 
	* @brief   ��Ϣ����ģ���˳��ӿ�
	* 
	* @param   void
	* @return  BOOL32 TRUE:�ɹ��˳��� FALSE:�˳�ʧ��
	* @see     NvTerinterfaceStart()
	------------------------------------------------------------------------*/
	NVCBB_API BOOL32 NvTerinterfaceStop();


};

// #ifdef __cplusplus
// extern "C" {
// #endif
// 
// 	
// 
// #ifdef __cplusplus
// }
// #endif
 #endif