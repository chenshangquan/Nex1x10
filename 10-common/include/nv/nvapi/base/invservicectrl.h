/**===========================================================================
 * @file    $Id$
 * @brief   �����ն˹��ܷ������ر���ز���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _NVBASEAPI_INTERFACE_INVSERVICECTRL_H_
#define _NVBASEAPI_INTERFACE_INVSERVICECTRL_H_

#include "nvapi_typedef.h"
#include "nvapi_if.h"
#include "nvapi_event_base.h"




/**---------------------------------------------------------------------------
 * @class   Interface INvserviceCtrl
 * @brief   �����ն˹��ܷ������ر���ز����Ľӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class INvserviceCtrl : public INvApiIF
{
public:
	/**
	*  BindDefNvService 
	* 
	* @brief �ն˰�Ĭ�ϵ��ն˷���
	* 
	* @param	void
	* @return   u32  NV_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 BindDefNvService( ) = 0; 

	/**
	*  BindDefNvService 
	* 
	* @brief �����ն˰�Ĭ�ϵ��ն˷���
	* 
	* @param	[in] tMultiServiceInfo  �������nv��Ϣ��
	* @return   u32  NV_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 BindDefNvService( IN CONST nv::TNVMutiTServiceDefInfo &tMultiDefServiceInfo ) = 0; 

	/**
	*  ModBindDefNvService 
	* 
	* @brief �޸��ն˰�Ĭ�ϵ��ն˷���
	* 
	* @param	[in] tMultiServiceInfo  �������nv��Ϣ��
	* @return   u32  NV_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 ModBindDefNvService( IN CONST nv::TNVMutiTServiceDefInfo &tMultiDefServiceInfo ) = 0; 

	/**
	*  DelBindNvService 
	* 
	* @brief ɾ���ն˰�Ĭ�ϵ��ն˷���
	* 
	* @param	[in] tMultiServiceInfo  �������nv��Ϣ��
	* @return   u32  NV_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 DelBindNvService( IN CONST nv::TString &tAlias ) = 0; 
	
	/**
	*  BindNvService 
	* 
	* @brief �����ն˰󶨵��ն˷���
	* 
	* @param	[in] tMultiServiceInfo  �������nv��Ϣ��
	* @return   u32  NV_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 BindNvService( IN CONST nv::TNVMutiTServiceInfo &tMultiServiceInfo ) = 0; 

	/**
	*  UnBindNvService 
	* 
	* @brief ����ն˰󶨵��ն˷���
	* 
	* @param	[in] tMultiAlias  ������ն˷������
	* @return   u32  NV_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 UnBindNvService( IN CONST nv::TMultiStr &tMultiAlias ) = 0; 

	/**
	*  StartNvService
	* 
	* @brief �����ն˰󶨵��ն˷���
	* 
	* @param	[in] tAlias  ������ն˷������
	* @return   u32  NV_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 StartNvService( IN CONST nv::TString &tAlias ) = 0; 

	/**
	*  StopNvService
	* 
	* @brief �����ն˰󶨵��ն˷���
	* 
	* @param	[in] tAlias  ������ն˷������
	* @return   u32  NV_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 StopNvService( IN CONST nv::TString &tAlias ) = 0; 

};

#endif // _NVBASEAPI_INTERFACE_INVSERVICECTRL_H_