/**===========================================================================
 * @file    $Id$
 * @brief   �����ն˴��������ģ��Ľӿڲ���
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _MTERRORCODE_API_H_
#define _MTERRORCODE_API_H_

#include "kdvtype.h"
#include "mterrcode_def.h"
#include "mterrcode_global.h"
#include "mterrcode_mtapi.h"
#include "mterrcode_datashare.h"
#include "mterrcode_mtaccess.h"
#include "mterrcode_mtconf.h"
#include "mterrcode_mtdispatch.h"
#include "mterrcode_mtim.h"
#include "mterrcode_mtmcservice.h"
#include "mterrcode_mtmisc.h"
#include "mterrcode_mtrest.h"
#include "mterrcode_mtsdk.h"
#include "mterrcode_mtsvrlogin.h"
#include "mterrcode_mtutils.h"
#include "mterrcode_mtvod.h"
#include "mterrcode_upgrade.h"

//������ʹ�õķ�ʽĬ��Ϊ��̬��ʽ
#if defined( _USRDLL ) || defined( _MT_ERRCODE_IMP_ )
	//��̬��
	#if defined( _MT_ERRCODE_EXP_ )
	    #define KdvMtEcAPI extern "C" __declspec( dllexport )
	#else
		#define KdvMtEcAPI extern "C" __declspec( dllimport )
	#endif
#else
	//��̬��
	#define  KdvMtEcAPI extern "C"
#endif


#define KdvMtEcCALL 


/**
* mtErrCodeApiInit
* @brief ������ģ�鹦�ܳ�ʼ��
*
* @param	[in] pchErrDescFilePath  �����������ļ�·��������Ҫ��ȡ��������������
* @return	u32  0 �� �����ɹ��� ��0����ʼ��ʧ��
*
*/
KdvMtEcAPI u32 KdvMtEcCALL mtErrCodeApiInit(const s8* pchErrDescFilePath = "");


/**
* mtErrCodeApiIsInitd
* @brief  �Ƿ��Ѿ���ʼ����
*
* @param	[in] void
* @return	BOOL32  TRUE �� �Ѿ���ʼ��  FALSE����δ��ʼ��
*
*/
KdvMtEcAPI BOOL32 KdvMtEcCALL mtErrCodeApiIsInitd( );


/**
* mtErrCodeApiExit
* @brief ������ģ�鹦���˳�
*
* @param	[in] void
* @return	u32  0 �� �����ɹ��� ��0����ʼ��ʧ��
*
*/
KdvMtEcAPI u32 KdvMtEcCALL mtErrCodeApiExit();

/**
* mtErrCodeMakeErrID
* @brief  ����������
*
* @param	[in] byModule      ������ģ��ID
* @param	[in] bySubModule   ������ģ���µ���ҵ��ģ��ID
* @param	[in] wSubErrID     ������ID
* @param	[in] byLevel       ����ȼ�(Ĭ��Ϊ0����Ϣ��)
* @return	u32  ���ɵ�Ψһ������ID
*
*/
KdvMtEcAPI u32 KdvMtEcCALL mtErrCodeMakeErrID( u8 byModule, u8 bySubModule, u16 wSubErrID, u8 byLevel = 0 );


/**
* mtErrCodeGetDetailByErrID
* @brief  ���ݴ���ID��ȡ��Ӧ����ϸ������Ϣ
*
* @param	[in]  dwErrorID     ������ID
* @param	[out] byModule     ������ģ��ID
* @param	[out] bySubModule  ������ģ���µ���ҵ��ģ��ID
* @param	[out] wSubErrID    ������ID
* @param	[out] byLevel      ����ȼ�
* @return	u32  0:ִ�гɹ�    ��0:ִ��ʧ�ܣ���������
*
*/
KdvMtEcAPI u32 KdvMtEcCALL mtErrCodeGetDetailByErrID( u32 dwErrorID, u8& byModule, u8& bySubModule, u16& wSubErrID, u8& byLevel );


/**
* mtErrCodeGetModuleByErrID
* @brief  ���ݴ���ID��ȡ��Ӧģ����Ϣ
*
* @param	[in]  dwErrorID     ������ID
* @param	[out] byModule      ������ģ��ID
* @return	u32  0:ִ�гɹ�    ��0:ִ��ʧ�ܣ���������
*
*/
KdvMtEcAPI u32 KdvMtEcCALL mtErrCodeGetModuleByErrID( u32 dwErrorID, u8& byModule );


/**
* mtErrCodeGetSubModuleByErrID
* @brief  ���ݴ���ID��ȡ��Ӧ����ҵ�������Ϣ
*
* @param	[in]  dwErrorID     ������ID
* @param	[out] bySubModule   ������ģ���µ���ҵ��ģ��ID
* @return	u32  0:ִ�гɹ�    ��0:ִ��ʧ�ܣ���������
*
*/
KdvMtEcAPI u32 KdvMtEcCALL mtErrCodeGetSubModuleByErrID( u32 dwErrorID, u8& bySubModule );



/**
* mtErrCodeGetSubErrIDByErrID
* @brief  ���ݴ���ID��ȡ��Ӧ���Ӵ�����ID��Ϣ
*
* @param	[in]  dwErrorID     ������ID
* @param	[out] wSubErrID     ������ģ���µ���ҵ��ģ��ID
* @return	u32  0:ִ�гɹ�    ��0:ִ��ʧ�ܣ���������
*
*/
KdvMtEcAPI u32 KdvMtEcCALL mtErrCodeGetSubErrIDByErrID( u32 dwErrorID, u16& bySubErrID );



/**
* mtErrCodeGetLevelByErrID
* @brief  ���ݴ���ID��ȡ��Ӧ�Ĵ���ȼ���Ϣ
*
* @param	[in]  dwErrorID     ������ID
* @param	[out] byLevel       ����ȼ�
* @return	u32  0:ִ�гɹ�    ��0:ִ��ʧ�ܣ���������
*
*/
KdvMtEcAPI u32 KdvMtEcCALL mtErrCodeGetLevelByErrID( u32 dwErrorID, u8& byLevel );



/**
* mtErrCodeGetErrDescByErrID
* @brief  ���ݴ���ID��ȡ��Ӧ�Ĵ���������Ϣ
*
* @param	[in]     dwErrID       ����ID��ȫ��ʽ�ģ�
* @param	[in]     pchDestBuf    ���մ���������buf
* @param	[in/out] wBufSize      buf��С�����ú��Ƿ���ʵ�����ݴ�С
* @param	[in]     pchLangType   Ҫ��ȡ��������Ϣ
* @return	u32  0:ִ�гɹ�    ��0:ִ��ʧ�ܣ���������
* @note     Ҫ���ش���������������mtErrCodeApiInit�ӿ�ʱ���������ô�������·��
*
*/
KdvMtEcAPI u32 KdvMtEcCALL mtErrCodeGetErrDescByErrID(u32 dwErrID, s8* pchDestBuf, u16& wBufSize, const s8* pchLangType = "zh_cn" );


 
#endif //_MTERRORCODE_API_H_