/**===========================================================================
 * @file    $Id$
 * @brief   ����MTAPI�Ự����Ľӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTBASEAPI_H_
#define _I_MTBASEAPI_H_

#include <map>

#include "mtapi_typedef.h"
#include "mtapi_def.h"
#include "mtapi_export.h"

#include "imtbasefset.h"
#include "mtlock.h"

//������ʹ�õķ�ʽĬ��Ϊ��̬��ʽ
#if defined( _USRDLL )
//��̬��
#if defined( _KDV_MTBASEAPI_EXP_ )
#define KdvMtBaseAPI __declspec( dllexport )
#else
#define KdvMtBaseAPI __declspec( dllimport )
#endif
#else
//��̬��
#define  KdvMtBaseAPI
#endif

/**---------------------------------------------------------------------------
 * @class   Interface IMtBaseApi
 * @brief   ����MTAPI�Ự����Ľӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class IMtBaseApi : public IMtApiIF
{
public:
	virtual ~IMtBaseApi(){};
	
	/**
	* InitParam
	* @brief  BaseApi�ĳ�ʼ������
	*
	* @param  [in]   [in] emMode: emMtLocMode_Api: ��C/Sģʽ��emMtRmtMode_Api��C/Sģʽ
	* @return void 
	* @note 
	*
	*/
	virtual void InitParam( const EmMtApiMode_Api emMode  = emMtLocMode_Api ) = 0;

	/**
	* GetApiMode
	* @brief  ��ȡapiģʽ
	*
	* @return emMode: emMtLocMode_Api: ��C/Sģʽ��emMtRmtMode_Api��C/Sģʽ 
	* @note 
	*
	*/
	virtual EmMtApiMode_Api GetApiMode() = 0;

	virtual u32 CreateSession2( SessionID& dwSSID, TMtcLoginParam_Api *ptParam ) =0;

	virtual u32 GetMtVersionInfoReq( const s8* pchMtIp ) = 0;

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
	* OspDisConnectDestorySession
	* @brief  osp������Ϣ������ͨ��SessionID�ͷ�һ���Ѵ�����Session
	*
	* @param  [in]    SessionID  �ỰID 
	* 
	*
	*/
	virtual u32  OspDisConnectDestorySession( SessionID dwSSID ) = 0; 

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
	* @brief  ע��MtDispatch��Ϣ�ص�
	*
	* @param  [in]   MT_CID           SDK��CID eg: IMtXXXApi��CID
	* @param  [in]   pcbDispCallBack  �ص���ַ
	* @return  u32   ����ע����
	*
	*/
	virtual BOOL32  RegDispMsg( MT_UUID MT_CID , NOTIFY_MTAPI_CALLBACK pDispCB  ) = 0;

	/**
	* UnRegDispMsg
	* @brief  ��ע��MtDispatch��Ϣ�ص�
	*
	* @param  [in]   MT_CID   SDK��CID eg: IMtXXXApi��CID
	* @return  u32   ���ط�ע����
	*
	*/
	virtual BOOL32  UnRegDispMsg( MT_UUID MT_CID ) = 0;
 
	/**
	* OnDispCallBackNotify
	* @brief  ��Ӧ������mtapiע���callback
	*
	* @param  [in]   pcMtMsg    ��Ӧ����Ϣ
	* @param  [in]   dwSrcId    ԴNodeID(����)
	* @param  [in]   dwSrcNode  ԴIID(����)
	* @param  [in]   SSID       sessionid
	* @return  u32   ���ط�ע����
	*
	*/
	virtual BOOL32  OnDispCallBackNotify( void* pcMtMsg, u32 dwSrcId, u32 dwSrcNode,SessionID SSID  ) = 0;
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
KdvMtBaseAPI typedef u32 (CreateInstance)( IN CONST SessionID dwSSID );

/**----------------------------------------------------------------------
	* DestoryInstance
	* 
	* @brief    ����ʵ���Ļص�����
	* 
	* @param	[in] dwSSID 
	------------------------------------------------------------------------*/
KdvMtBaseAPI typedef u32 (DestoryInstance)( IN CONST SessionID dwSSID );

/**----------------------------------------------------------------------
	* RegisterCreateInstance
	* 
	* @brief    ע��һ����������ʵ������
	* 
	* @param	[in] pf ע�ắ��
	* @param	[in] pchName ע�ắ������
	* @return	void
	------------------------------------------------------------------------*/
KdvMtBaseAPI void RegisterCreateInstance( CreateInstance *pf, char* pchName );
/**----------------------------------------------------------------------
	* LogOutCreateInstance
	* 
	* @brief    ע��һ����������ʵ������
	* 
	* @param	[in] pf ע�ắ������
	* @return	void
	------------------------------------------------------------------------*/
KdvMtBaseAPI void LogOutCreateInstance( CreateInstance *pf );
/**----------------------------------------------------------------------
	* RegisterDestoryInstance
	* 
	* @brief    ע��һ�����ٹ���ʵ������
	* 
	* @param	[in] pf ע�ắ��
	* @param	[in] pchName ע�ắ������
	* @return	void
	------------------------------------------------------------------------*/
KdvMtBaseAPI void RegisterDestoryInstance( DestoryInstance *pf, char* pchName );

/**----------------------------------------------------------------------
	* LogOutDestoryInstance
	* 
	* @brief    ע��һ�����ٹ���ʵ������
	* 
	* @param	[in] pf ע�ắ������
	* @return	void
	------------------------------------------------------------------------*/
KdvMtBaseAPI void LogOutDestoryInstance( DestoryInstance *pf );

KdvMtBaseAPI typedef std::map<SessionID, IMtBaseFSet* >  MapMtBSSession;

};

extern "C" KdvMtBaseAPI IMtBaseApi*        g_pcMtBsApiIF;            ///< baseapiģ��api�ӿ�ָ��
extern "C" KdvMtBaseAPI MapMtBSSession     g_mapIMtBaseSession;      ///< baseapi����MT�Ự����  
extern "C" KdvMtBaseAPI COspLock g_cLock;
extern "C" KdvMtBaseAPI IMtApiMap<DestoryInstance *, char*> g_mapDestoryInstance;
#endif // _I_MTBASEAPI_H_