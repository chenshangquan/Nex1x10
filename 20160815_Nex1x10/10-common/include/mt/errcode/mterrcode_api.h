/**===========================================================================
 * @file    $Id$
 * @brief   负责终端错误码管理模块的接口操作
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

//调用者使用的方式默认为静态方式
#if defined( _USRDLL ) || defined( _MT_ERRCODE_IMP_ )
	//动态库
	#if defined( _MT_ERRCODE_EXP_ )
	    #define KdvMtEcAPI extern "C" __declspec( dllexport )
	#else
		#define KdvMtEcAPI extern "C" __declspec( dllimport )
	#endif
#else
	//静态库
	#define  KdvMtEcAPI extern "C"
#endif


#define KdvMtEcCALL 


/**
* mtErrCodeApiInit
* @brief 错误码模块功能初始化
*
* @param	[in] pchErrDescFilePath  错误码描述文件路径，如需要获取错误码描述必填
* @return	u32  0 ： 操作成功， 非0：初始化失败
*
*/
KdvMtEcAPI u32 KdvMtEcCALL mtErrCodeApiInit(const s8* pchErrDescFilePath = "");


/**
* mtErrCodeApiIsInitd
* @brief  是否已经初始化过
*
* @param	[in] void
* @return	BOOL32  TRUE ： 已经初始化  FALSE：尚未初始化
*
*/
KdvMtEcAPI BOOL32 KdvMtEcCALL mtErrCodeApiIsInitd( );


/**
* mtErrCodeApiExit
* @brief 错误码模块功能退出
*
* @param	[in] void
* @return	u32  0 ： 操作成功， 非0：初始化失败
*
*/
KdvMtEcAPI u32 KdvMtEcCALL mtErrCodeApiExit();

/**
* mtErrCodeMakeErrID
* @brief  创建错误码
*
* @param	[in] byModule      错误码模块ID
* @param	[in] bySubModule   错误码模块下的子业务模块ID
* @param	[in] wSubErrID     错误码ID
* @param	[in] byLevel       错误等级(默认为0，信息类)
* @return	u32  生成的唯一错误码ID
*
*/
KdvMtEcAPI u32 KdvMtEcCALL mtErrCodeMakeErrID( u8 byModule, u8 bySubModule, u16 wSubErrID, u8 byLevel = 0 );


/**
* mtErrCodeGetDetailByErrID
* @brief  根据错误ID获取对应的详细分类信息
*
* @param	[in]  dwErrorID     错误码ID
* @param	[out] byModule     错误码模块ID
* @param	[out] bySubModule  错误码模块下的子业务模块ID
* @param	[out] wSubErrID    错误码ID
* @param	[out] byLevel      错误等级
* @return	u32  0:执行成功    非0:执行失败，见错误码
*
*/
KdvMtEcAPI u32 KdvMtEcCALL mtErrCodeGetDetailByErrID( u32 dwErrorID, u8& byModule, u8& bySubModule, u16& wSubErrID, u8& byLevel );


/**
* mtErrCodeGetModuleByErrID
* @brief  根据错误ID获取对应模块信息
*
* @param	[in]  dwErrorID     错误码ID
* @param	[out] byModule      错误码模块ID
* @return	u32  0:执行成功    非0:执行失败，见错误码
*
*/
KdvMtEcAPI u32 KdvMtEcCALL mtErrCodeGetModuleByErrID( u32 dwErrorID, u8& byModule );


/**
* mtErrCodeGetSubModuleByErrID
* @brief  根据错误ID获取对应的子业务分类信息
*
* @param	[in]  dwErrorID     错误码ID
* @param	[out] bySubModule   错误码模块下的子业务模块ID
* @return	u32  0:执行成功    非0:执行失败，见错误码
*
*/
KdvMtEcAPI u32 KdvMtEcCALL mtErrCodeGetSubModuleByErrID( u32 dwErrorID, u8& bySubModule );



/**
* mtErrCodeGetSubErrIDByErrID
* @brief  根据错误ID获取对应的子错误码ID信息
*
* @param	[in]  dwErrorID     错误码ID
* @param	[out] wSubErrID     错误码模块下的子业务模块ID
* @return	u32  0:执行成功    非0:执行失败，见错误码
*
*/
KdvMtEcAPI u32 KdvMtEcCALL mtErrCodeGetSubErrIDByErrID( u32 dwErrorID, u16& bySubErrID );



/**
* mtErrCodeGetLevelByErrID
* @brief  根据错误ID获取对应的错误等级信息
*
* @param	[in]  dwErrorID     错误码ID
* @param	[out] byLevel       错误等级
* @return	u32  0:执行成功    非0:执行失败，见错误码
*
*/
KdvMtEcAPI u32 KdvMtEcCALL mtErrCodeGetLevelByErrID( u32 dwErrorID, u8& byLevel );



/**
* mtErrCodeGetErrDescByErrID
* @brief  根据错误ID获取对应的错误描述信息
*
* @param	[in]     dwErrID       错误ID（全格式的）
* @param	[in]     pchDestBuf    接收错误描述的buf
* @param	[in/out] wBufSize      buf大小，调用后是返回实际内容大小
* @param	[in]     pchLangType   要获取的语种信息
* @return	u32  0:执行成功    非0:执行失败，见错误码
* @note     要返回错误码描述，调用mtErrCodeApiInit接口时，表现设置错误描述路径
*
*/
KdvMtEcAPI u32 KdvMtEcCALL mtErrCodeGetErrDescByErrID(u32 dwErrID, s8* pchDestBuf, u16& wBufSize, const s8* pchLangType = "zh_cn" );


 
#endif //_MTERRORCODE_API_H_