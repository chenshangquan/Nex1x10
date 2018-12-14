/**===========================================================================
 * @file    nvdispatch.h
 * @brief   
 * @author  longwei
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/
#ifndef _NVDISPATCH_H_
#define _NVDISPATCH_H_

#include "kdvtype.h"
#include "nvstruct.pb.h"
#include "nvstruct.h"
#include "nvmacro.h"
#include "nvmsg.h"


extern "C"
{

//�ص�����
/**----------------------------------------------------------------------
	* ExternHandler
	* 
	* @brief    �ⲿ������Ϣ�Ļص�����
	* 
	* @param	[in] pcNvMsg ������Ϣ�ľ�����Ϣ
	* @param	[in] dwSrcId ������Ϣ��appinstid
	* @param	[in] dwSrcNode ������Ϣ��nodeid
	* @return	BOOL32 TRUE:�Ѿ������ˣ�����Ҫ�������������������Ϣ�� FALSE:��Ҫ���������������Ϣ
	------------------------------------------------------------------------*/
// NVCBB_API typedef BOOL32 (ExternHandler)(nvmsg::CNvMsg *pcNvMsg, u32 dwSrcId, u32 dwSrcNode);

/**----------------------------------------------------------------------
	* RegisterExternHandler
	* 
	* @brief    ע���ⲿ��Ϣ����Ļص�����
	* 
	* @param	[in] pcNvMsg ������Ϣ�ľ�����Ϣ
	* @param	[in] dwSrcId ������Ϣ��appinstid
	* @param	[in] dwSrcNode ������Ϣ��nodeid
	* @return	void
	------------------------------------------------------------------------*/
/*NVCBB_API void RegisterExternHandler( ExternHandler *pfHandle );*/

/**----------------------------------------------------------------------
* NvDispatchStart
* 
* @brief   ��Ϣ����ģ�������ӿ�
* 
* @param   [in] tMdlStartparam ��������
* @return  BOOL32 TRUE:�ɹ������� FALSE:����ʧ��
* @see     NvDispatchStop()
------------------------------------------------------------------------*/
NVCBB_API BOOL32 NvDispatchStart(TMdlStartParam &tMdlStartparam );

/**----------------------------------------------------------------------
* NvDispatchStop
* 
* @brief   ��Ϣ����ģ���˳��ӿ�
* 
* @param   void
* @return  BOOL32 TRUE:�ɹ��˳��� FALSE:�˳�ʧ��
* @see     NvDispatchStart()
------------------------------------------------------------------------*/
NVCBB_API BOOL32 NvDispatchStop();

};

#endif // _NVDISPATCH_H_