/**===========================================================================
 * @file    $Id$
 * @brief   �����ն˴��������ģ��Ľӿڲ���
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _NVERRORCODE_API_H_
#define _NVERRORCODE_API_H_

#include "kdvtype.h"
#include "nverrcode_def.h"
#include "nverrcode_global.h"
#include "nverrcode_nvapi.h"
#include "nverrcode_datashare.h"
#include "nverrcode_nvaccess.h"
#include "nverrcode_nvconf.h"
#include "nverrcode_nvdispatch.h"
#include "nverrcode_nvim.h"
#include "nverrcode_nvmcservice.h"
#include "nverrcode_nvmisc.h"
#include "nverrcode_nvrest.h"
#include "nverrcode_nvsdk.h"
#include "nverrcode_nvsvrlogin.h"
#include "nverrcode_nvutils.h"
#include "nverrcode_nvvod.h"
#include "nverrcode_upgrade.h"

//������ʹ�õķ�ʽĬ��Ϊ��̬��ʽ
#if defined( _USRDLL ) || defined( _NV_ERRCODE_IMP_ )
	//��̬��
	#if defined( _NV_ERRCODE_EXP_ )
	    #define KdvNvEcAPI extern "C" __declspec( dllexport )
	#else
		#define KdvNvEcAPI extern "C" __declspec( dllimport )
	#endif
#else
	//��̬��
	#define  KdvNvEcAPI extern "C"
#endif


#define KdvNvEcCALL 


/**
* nvErrCodeApiInit
* @brief ������ģ�鹦�ܳ�ʼ��
*
* @param	[in] pchErrDescFilePath  �����������ļ�·��������Ҫ��ȡ��������������
* @return	u32  0 �� �����ɹ��� ��0����ʼ��ʧ��
*
*/
KdvNvEcAPI u32 KdvNvEcCALL nvErrCodeApiInit(const s8* pchErrDescFilePath = "");


/**
* nvErrCodeApiIsInitd
* @brief  �Ƿ��Ѿ���ʼ����
*
* @param	[in] void
* @return	BOOL32  TRUE �� �Ѿ���ʼ��  FALSE����δ��ʼ��
*
*/
KdvNvEcAPI BOOL32 KdvNvEcCALL nvErrCodeApiIsInitd( );


/**
* nvErrCodeApiExit
* @brief ������ģ�鹦���˳�
*
* @param	[in] void
* @return	u32  0 �� �����ɹ��� ��0����ʼ��ʧ��
*
*/
KdvNvEcAPI u32 KdvNvEcCALL nvErrCodeApiExit();

/**
* nvErrCodeMakeErrID
* @brief  ����������
*
* @param	[in] byModule      ������ģ��ID
* @param	[in] bySubModule   ������ģ���µ���ҵ��ģ��ID
* @param	[in] wSubErrID     ������ID
* @param	[in] byLevel       ����ȼ�(Ĭ��Ϊ0����Ϣ��)
* @return	u32  ���ɵ�Ψһ������ID
*
*/
KdvNvEcAPI u32 KdvNvEcCALL nvErrCodeMakeErrID( u8 byModule, u8 bySubModule, u16 wSubErrID, u8 byLevel = 0 );


/**
* nvErrCodeGetDetailByErrID
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
KdvNvEcAPI u32 KdvNvEcCALL nvErrCodeGetDetailByErrID( u32 dwErrorID, u8& byModule, u8& bySubModule, u16& wSubErrID, u8& byLevel );


/**
* nvErrCodeGetModuleByErrID
* @brief  ���ݴ���ID��ȡ��Ӧģ����Ϣ
*
* @param	[in]  dwErrorID     ������ID
* @param	[out] byModule      ������ģ��ID
* @return	u32  0:ִ�гɹ�    ��0:ִ��ʧ�ܣ���������
*
*/
KdvNvEcAPI u32 KdvNvEcCALL nvErrCodeGetModuleByErrID( u32 dwErrorID, u8& byModule );


/**
* nvErrCodeGetSubModuleByErrID
* @brief  ���ݴ���ID��ȡ��Ӧ����ҵ�������Ϣ
*
* @param	[in]  dwErrorID     ������ID
* @param	[out] bySubModule   ������ģ���µ���ҵ��ģ��ID
* @return	u32  0:ִ�гɹ�    ��0:ִ��ʧ�ܣ���������
*
*/
KdvNvEcAPI u32 KdvNvEcCALL nvErrCodeGetSubModuleByErrID( u32 dwErrorID, u8& bySubModule );



/**
* nvErrCodeGetSubErrIDByErrID
* @brief  ���ݴ���ID��ȡ��Ӧ���Ӵ�����ID��Ϣ
*
* @param	[in]  dwErrorID     ������ID
* @param	[out] wSubErrID     ������ģ���µ���ҵ��ģ��ID
* @return	u32  0:ִ�гɹ�    ��0:ִ��ʧ�ܣ���������
*
*/
KdvNvEcAPI u32 KdvNvEcCALL nvErrCodeGetSubErrIDByErrID( u32 dwErrorID, u16& bySubErrID );



/**
* nvErrCodeGetLevelByErrID
* @brief  ���ݴ���ID��ȡ��Ӧ�Ĵ���ȼ���Ϣ
*
* @param	[in]  dwErrorID     ������ID
* @param	[out] byLevel       ����ȼ�
* @return	u32  0:ִ�гɹ�    ��0:ִ��ʧ�ܣ���������
*
*/
KdvNvEcAPI u32 KdvNvEcCALL nvErrCodeGetLevelByErrID( u32 dwErrorID, u8& byLevel );



/**
* nvErrCodeGetErrDescByErrID
* @brief  ���ݴ���ID��ȡ��Ӧ�Ĵ���������Ϣ
*
* @param	[in]     dwErrID       ����ID��ȫ��ʽ�ģ�
* @param	[in]     pchDestBuf    ���մ���������buf
* @param	[in/out] wBufSize      buf��С�����ú��Ƿ���ʵ�����ݴ�С
* @param	[in]     pchLangType   Ҫ��ȡ��������Ϣ
* @return	u32  0:ִ�гɹ�    ��0:ִ��ʧ�ܣ���������
* @note     Ҫ���ش���������������nvErrCodeApiInit�ӿ�ʱ���������ô�������·��
*
*/
KdvNvEcAPI u32 KdvNvEcCALL nvErrCodeGetErrDescByErrID(u32 dwErrID, s8* pchDestBuf, u16& wBufSize, const s8* pchLangType = "zh_cn" );


 
#endif //_NVERRORCODE_API_H_