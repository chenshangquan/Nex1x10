/**===========================================================================
 * @file    mtdispatch.h
 * @brief   
 * @author  longwei
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/
#ifndef _MTDISPATCH_H_
#define _MTDISPATCH_H_

#include "kdvtype.h"
#include "struct.pb.h"
#include "mtstruct.h"
#include "mtmacro.h"
#include "mtmsg.h"


extern "C"
{

//�ص�����
/**----------------------------------------------------------------------
	* ExternHandler
	* 
	* @brief    �ⲿ������Ϣ�Ļص�����
	* 
	* @param	[in] pcMtMsg ������Ϣ�ľ�����Ϣ
	* @param	[in] dwSrcId ������Ϣ��appinstid
	* @param	[in] dwSrcNode ������Ϣ��nodeid
	* @return	BOOL32 TRUE:�Ѿ������ˣ�����Ҫ�������������������Ϣ�� FALSE:��Ҫ���������������Ϣ
	------------------------------------------------------------------------*/
// MTCBB_API typedef BOOL32 (ExternHandler)(mtmsg::CMtMsg *pcMtMsg, u32 dwSrcId, u32 dwSrcNode);

/**----------------------------------------------------------------------
	* RegisterExternHandler
	* 
	* @brief    ע���ⲿ��Ϣ����Ļص�����
	* 
	* @param	[in] pcMtMsg ������Ϣ�ľ�����Ϣ
	* @param	[in] dwSrcId ������Ϣ��appinstid
	* @param	[in] dwSrcNode ������Ϣ��nodeid
	* @return	void
	------------------------------------------------------------------------*/
/*MTCBB_API void RegisterExternHandler( ExternHandler *pfHandle );*/

/**----------------------------------------------------------------------
* MtDispatchStart
* 
* @brief   ��Ϣ����ģ�������ӿ�
* 
* @param   [in] tMdlStartparam ��������
* @return  BOOL32 TRUE:�ɹ������� FALSE:����ʧ��
* @see     MtDispatchStop()
------------------------------------------------------------------------*/
MTCBB_API BOOL32 MtDispatchStart(TMdlStartParam &tMdlStartparam );

/**----------------------------------------------------------------------
* MtDispatchStop
* 
* @brief   ��Ϣ����ģ���˳��ӿ�
* 
* @param   void
* @return  BOOL32 TRUE:�ɹ��˳��� FALSE:�˳�ʧ��
* @see     MtDispatchStart()
------------------------------------------------------------------------*/
MTCBB_API BOOL32 MtDispatchStop();

};

#endif // _MTDISPATCH_H_