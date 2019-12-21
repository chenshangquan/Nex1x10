/**===========================================================================
 * @file    $Id$
 * @brief   �����ն˹��ܷ������ر���ز���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _MTBASEAPI_INTERFACE_IMTSERVICECTRL_H_
#define _MTBASEAPI_INTERFACE_IMTSERVICECTRL_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_base.h"




/**---------------------------------------------------------------------------
 * @class   Interface IMtserviceCtrl
 * @brief   �����ն˹��ܷ������ر���ز����Ľӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class IMtserviceCtrl : public IMtApiIF
{
public:
	/**
	*  BindDefMtService 
	* 
	* @brief �ն˰�Ĭ�ϵ��ն˷���
	* 
	* @param	void
	* @return   u32  MT_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 BindDefMtService( ) = 0; 

	/**
	*  BindDefMtService 
	* 
	* @brief �����ն˰�Ĭ�ϵ��ն˷���
	* 
	* @param	[in] tMultiServiceInfo  �������mt��Ϣ��
	* @return   u32  MT_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 BindDefMtService( IN CONST TMutiTServiceDefInfo_Api &tMultiDefServiceInfo ) = 0; 

	/**
	*  ModBindDefMtService 
	* 
	* @brief �޸��ն˰�Ĭ�ϵ��ն˷���
	* 
	* @param	[in] tMultiServiceInfo  �������mt��Ϣ��
	* @return   u32  MT_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 ModBindDefMtService( IN CONST TMutiTServiceDefInfo_Api &tMultiDefServiceInfo ) = 0; 

	/**
	*  DelBindMtService 
	* 
	* @brief ɾ���ն˰�Ĭ�ϵ��ն˷���
	* 
	* @param	[in] tMultiServiceInfo  �������mt��Ϣ��
	* @return   u32  MT_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 DelBindMtService( s8 achAlias[KMTAPI_SYS_MAX_SYSNAME_LEN] ) = 0; 
	
	/**
	*  BindMtService 
	* 
	* @brief �����ն˰󶨵��ն˷���
	* 
	* @param	[in] tMultiServiceInfo  �������mt��Ϣ��
	* @return   u32  MT_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 BindMtService( IN CONST TMutiTStartUpServiceInfo_Api &tMultiServiceInfo ) = 0; 

	/**
	*  UnBindMtService 
	* 
	* @brief ����ն˰󶨵��ն˷���
	* 
	* @param	[in] aachAlias  ������ն˷������
	* @param	[in] wCnt  ������ն˷������
	* @return   u32  MT_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 UnBindMtService( s8 aachAlias[][KMTAPI_SYS_MAX_SYSNAME_LEN], u16 wCnt ) = 0; 

	/**
	*  StartMtService
	* 
	* @brief �����ն˰󶨵��ն˷���
	* 
	* @param	[in] achAlias  ������ն˷������
	* @return   u32  MT_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 StartMtService( s8 achAlias[KMTAPI_SYS_MAX_SYSNAME_LEN] ) = 0; 

	/**
	*  StopMtService
	* 
	* @brief �����ն˰󶨵��ն˷���
	* 
	* @param	[in] achAlias  ������ն˷������
	* @return   u32  MT_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 StopMtService( s8 achAlias[KMTAPI_SYS_MAX_SYSNAME_LEN] ) = 0; 

};

#endif // _MTBASEAPI_INTERFACE_IMTSERVICECTRL_H_