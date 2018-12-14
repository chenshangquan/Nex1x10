/**===========================================================================
 * @file    nvdfclient.h
 * @brief   
 * @author  yanglei
 * @date    
 * @version  
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/
#ifndef _NVDFCLIENT_H_
#define _NVDFCLIENT_H_
#include "kdvtype.h"
#include "nvstruct.h"
#include "nvmacro.h"

typedef u32 (*GETTERIPADDR_CALLBACK)(TNVDfServiceParam_API *ptDfParam);

extern "C"
{
	/**----------------------------------------------------------------------
	* NvStartDfClient
	* 
	* @brief   �����豸���ҿͻ���
	* @param	TNVDfClientParam_API
	* @return  BOOL32 TRUE:�ɹ������� FALSE:����ʧ��
	------------------------------------------------------------------------*/
	NVCBB_API BOOL32 NvStartDfClient( TNVDfClientParam_API &tDfStartParam );

	/**----------------------------------------------------------------------
	* NvEnableAskServiceAddr
	* 
	* @brief   �Ƿ���ҷ�������ַ
	* @param	BOOL32
	* @return  BOOL32 TRUE:�ɹ������� FALSE:����ʧ��
	------------------------------------------------------------------------*/
	NVCBB_API BOOL32 NvEnableAskServiceAddr( BOOL32 bEnable );
	
	/**----------------------------------------------------------------------
	* NvStopDfClient
	* 
	* @brief   �ر��豸���ҿͻ���
	* @return  BOOL32 TRUE:�ɹ������� FALSE:����ʧ��
	------------------------------------------------------------------------*/
	NVCBB_API BOOL32 NvStopDfClient(  );
	
	
	/**----------------------------------------------------------------------
	* NvSetTerIpCallBack
	* 
	* @brief   ����ip��ַ�ص�����
	* @return  BOOL32 TRUE:�ɹ������� FALSE:����ʧ��
	------------------------------------------------------------------------*/
	NVCBB_API BOOL32 NvSetTerIpCallBack( GETTERIPADDR_CALLBACK cbIpAddr );
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