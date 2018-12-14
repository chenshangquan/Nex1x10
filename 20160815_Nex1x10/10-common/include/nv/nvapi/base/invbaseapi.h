/**===========================================================================
 * @file    $Id$
 * @brief   ����NVAPI�Ự����Ľӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_NVBASEAPI_H_
#define _I_NVBASEAPI_H_

#include <map>

#include "nvapi_typedef.h"
#include "nvapi_def.h"
#include "nvapi_export.h"

#include "invbasefset.h"
#include "nvlock.h"

//������ʹ�õķ�ʽĬ��Ϊ��̬��ʽ
#if defined( _USRDLL )
//��̬��
#if defined( _KDV_NVBASEAPI_EXP_ )
#define KdvNvBaseAPI __declspec( dllexport )
#else
#define KdvNvBaseAPI __declspec( dllimport )
#endif
#else
//��̬��
#define  KdvNvBaseAPI
#endif

/**---------------------------------------------------------------------------
 * @class   Interface INvBaseApi
 * @brief   ����NVAPI�Ự����Ľӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class INvBaseApi : public INvApiIF
{
public:
	virtual ~INvBaseApi(){};
	
	/**
	* InitParam
	* @brief  BaseApi�ĳ�ʼ������
	*
	* @param  [in]   [in] emMode: emNvLocMode_Api: ��C/Sģʽ��emNvRnvMode_Api��C/Sģʽ
	* @return void 
	* @note 
	*
	*/
	virtual void InitParam( const EmNvApiMode_Api emMode  = emNvLocMode_Api ) = 0;

	/**
	* GetApiMode
	* @brief  ��ȡapiģʽ
	*
	* @return emMode: emNvLocMode_Api: ��C/Sģʽ��emNvRnvMode_Api��C/Sģʽ 
	* @note 
	*
	*/
	virtual EmNvApiMode_Api GetApiMode() = 0;

	/**
	* CreateSession
	* @brief  �´���һ��Session
	*
	* @param  [out]   dwSSID   ���ش����� SESSIONID
	* @param  [in]    tConnectInfo  ������Ϣ 
	* @return u32  NV_SUCCESS���ɹ� ������������
	* @note C/Sģʽ��Ҫ�������Ӵ����Ѵ�����ֱ�ӷ���
	*
	*/
	virtual u32  CreateSession( SessionID& dwSSID, 
								const nv::TNVUserConnectInfo &tConnectInfo) = 0;
	
	/**
	* GetSession
	* @brief  ͨ���ն�IP�����Ѵ�����Session
	*
	* @param  [in]    strNvIp  Ҫ���ҵ��ն�IP 
	* @return  SessionID  ���ض�Ӧ��SessionID, ������ΪINVALID_SESSIONID
	*
	*
	*/
	virtual SessionID GetSession( const nvstring &strNvIp) const  = 0;


	/**
	* GetSession
	* @brief  ͨ���������Ҷ�Ӧ��SessionID
	*
	* @param  [in]    dwIdx  �Ự�б����� 
	* @return  SessionID  ���ض�Ӧ��SessionID, ������ΪINVALID_SESSIONID
	*
	*
	*/
	virtual SessionID GetSession( const u32 dwIdx ) const  = 0;


	/**
	* DestorySession
	* @brief  ͨ��SessionID�ͷ�һ���Ѵ�����Session
	*
	* @param  [in]    SessionID  �ỰID 
	* @return  u32   �����ͷŽ��
	*
	*/
	virtual u32  DestorySession( SessionID dwSSID ) = 0; 

	/**
	* GetMaxSessionCnt
	* @brief  ��ȡ���֧�ֵĻỰ����
	*
	* @param  [in]   void 
	* @return  u32   �������֧�ֵ�session����
	*
	*/
	virtual u16  GetMaxSessionCnt( ) const = 0;

	/**
	* GetUsedSessionCnt
	* @brief  ��ȡ�Ѿ����ڵĻỰ����
	*
	* @param  [in]   void 
	* @return  u32   �����Ѿ����ڵĻỰ����
	*
	*/
	virtual u16  GetUsedSessionCnt( ) const = 0;


	/**
	* RegDispMsg
	* @brief  ע��NvDispatch��Ϣ�ص�
	*
	* @param  [in]   NV_CID           SDK��CID eg: INvXXXApi��CID
	* @param  [in]   pcbDispCallBack  �ص���ַ
	* @return  u32   ����ע����
	*
	*/
	virtual BOOL32  RegDispMsg( NV_UUID NV_CID , NOTIFY_NVAPI_CALLBACK pDispCB  ) = 0;

	/**
	* UnRegDispMsg
	* @brief  ��ע��NvDispatch��Ϣ�ص�
	*
	* @param  [in]   NV_CID   SDK��CID eg: INvXXXApi��CID
	* @return  u32   ���ط�ע����
	*
	*/
	virtual BOOL32  UnRegDispMsg( NV_UUID NV_CID ) = 0;
 
	/**
	* OnDispCallBackNotify
	* @brief  ��Ӧ������nvapiע���callback
	*
	* @param  [in]   pcNvMsg    ��Ӧ����Ϣ
	* @param  [in]   dwSrcId    ԴNodeID(����)
	* @param  [in]   dwSrcNode  ԴIID(����)
	* @param  [in]   SSID       sessionid
	* @return  u32   ���ط�ע����
	*
	*/
	virtual BOOL32  OnDispCallBackNotify( void* pcNvMsg, u32 dwSrcId, u32 dwSrcNode,SessionID SSID  ) = 0;
};

extern "C"
{
//�ص�����
/**----------------------------------------------------------------------
	* CreateInstance
	* 
	* @brief    ����ʵ���Ļص�����
	* 
	* @param	[in] dwSSID 
	------------------------------------------------------------------------*/
KdvNvBaseAPI typedef u32 (CreateInstance)( IN CONST SessionID dwSSID );

/**----------------------------------------------------------------------
	* DestoryInstance
	* 
	* @brief    ����ʵ���Ļص�����
	* 
	* @param	[in] dwSSID 
	------------------------------------------------------------------------*/
KdvNvBaseAPI typedef u32 (DestoryInstance)( IN CONST SessionID dwSSID );

/**----------------------------------------------------------------------
	* RegisterCreateInstance
	* 
	* @brief    ע��һ����������ʵ������
	* 
	* @param	[in] pf ע�ắ��
	* @param	[in] pchName ע�ắ������
	* @return	void
	------------------------------------------------------------------------*/
KdvNvBaseAPI void RegisterCreateInstance( CreateInstance *pf, char* pchName );
/**----------------------------------------------------------------------
	* LogOutCreateInstance
	* 
	* @brief    ע��һ����������ʵ������
	* 
	* @param	[in] pf ע�ắ������
	* @return	void
	------------------------------------------------------------------------*/
KdvNvBaseAPI void LogOutCreateInstance( CreateInstance *pf );
/**----------------------------------------------------------------------
	* RegisterDestoryInstance
	* 
	* @brief    ע��һ�����ٹ���ʵ������
	* 
	* @param	[in] pf ע�ắ��
	* @param	[in] pchName ע�ắ������
	* @return	void
	------------------------------------------------------------------------*/
KdvNvBaseAPI void RegisterDestoryInstance( DestoryInstance *pf, char* pchName );

/**----------------------------------------------------------------------
	* LogOutDestoryInstance
	* 
	* @brief    ע��һ�����ٹ���ʵ������
	* 
	* @param	[in] pf ע�ắ������
	* @return	void
	------------------------------------------------------------------------*/
KdvNvBaseAPI void LogOutDestoryInstance( DestoryInstance *pf );

KdvNvBaseAPI typedef std::map<SessionID, INvBaseFSet* >  MapNvBSSession;

};

extern "C" KdvNvBaseAPI INvBaseApi*        g_pcNvBsApiIF;            ///< baseapiģ��api�ӿ�ָ��
extern "C" KdvNvBaseAPI MapNvBSSession     g_mapINvBaseSession;      ///< baseapi����NV�Ự����  
extern "C" KdvNvBaseAPI COspLock g_cLock;
#endif // _I_NVBASEAPI_H_