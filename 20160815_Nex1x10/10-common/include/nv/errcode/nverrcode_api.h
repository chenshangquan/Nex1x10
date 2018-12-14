/**===========================================================================
 * @file    $Id$
 * @brief   负责终端错误码管理模块的接口操作
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

//调用者使用的方式默认为静态方式
#if defined( _USRDLL ) || defined( _NV_ERRCODE_IMP_ )
	//动态库
	#if defined( _NV_ERRCODE_EXP_ )
	    #define KdvNvEcAPI extern "C" __declspec( dllexport )
	#else
		#define KdvNvEcAPI extern "C" __declspec( dllimport )
	#endif
#else
	//静态库
	#define  KdvNvEcAPI extern "C"
#endif


#define KdvNvEcCALL 


/**
* nvErrCodeApiInit
* @brief 错误码模块功能初始化
*
* @param	[in] pchErrDescFilePath  错误码描述文件路径，如需要获取错误码描述必填
* @return	u32  0 ： 操作成功， 非0：初始化失败
*
*/
KdvNvEcAPI u32 KdvNvEcCALL nvErrCodeApiInit(const s8* pchErrDescFilePath = "");


/**
* nvErrCodeApiIsInitd
* @brief  是否已经初始化过
*
* @param	[in] void
* @return	BOOL32  TRUE ： 已经初始化  FALSE：尚未初始化
*
*/
KdvNvEcAPI BOOL32 KdvNvEcCALL nvErrCodeApiIsInitd( );


/**
* nvErrCodeApiExit
* @brief 错误码模块功能退出
*
* @param	[in] void
* @return	u32  0 ： 操作成功， 非0：初始化失败
*
*/
KdvNvEcAPI u32 KdvNvEcCALL nvErrCodeApiExit();

/**
* nvErrCodeMakeErrID
* @brief  创建错误码
*
* @param	[in] byModule      错误码模块ID
* @param	[in] bySubModule   错误码模块下的子业务模块ID
* @param	[in] wSubErrID     错误码ID
* @param	[in] byLevel       错误等级(默认为0，信息类)
* @return	u32  生成的唯一错误码ID
*
*/
KdvNvEcAPI u32 KdvNvEcCALL nvErrCodeMakeErrID( u8 byModule, u8 bySubModule, u16 wSubErrID, u8 byLevel = 0 );


/**
* nvErrCodeGetDetailByErrID
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
KdvNvEcAPI u32 KdvNvEcCALL nvErrCodeGetDetailByErrID( u32 dwErrorID, u8& byModule, u8& bySubModule, u16& wSubErrID, u8& byLevel );


/**
* nvErrCodeGetModuleByErrID
* @brief  根据错误ID获取对应模块信息
*
* @param	[in]  dwErrorID     错误码ID
* @param	[out] byModule      错误码模块ID
* @return	u32  0:执行成功    非0:执行失败，见错误码
*
*/
KdvNvEcAPI u32 KdvNvEcCALL nvErrCodeGetModuleByErrID( u32 dwErrorID, u8& byModule );


/**
* nvErrCodeGetSubModuleByErrID
* @brief  根据错误ID获取对应的子业务分类信息
*
* @param	[in]  dwErrorID     错误码ID
* @param	[out] bySubModule   错误码模块下的子业务模块ID
* @return	u32  0:执行成功    非0:执行失败，见错误码
*
*/
KdvNvEcAPI u32 KdvNvEcCALL nvErrCodeGetSubModuleByErrID( u32 dwErrorID, u8& bySubModule );



/**
* nvErrCodeGetSubErrIDByErrID
* @brief  根据错误ID获取对应的子错误码ID信息
*
* @param	[in]  dwErrorID     错误码ID
* @param	[out] wSubErrID     错误码模块下的子业务模块ID
* @return	u32  0:执行成功    非0:执行失败，见错误码
*
*/
KdvNvEcAPI u32 KdvNvEcCALL nvErrCodeGetSubErrIDByErrID( u32 dwErrorID, u16& bySubErrID );



/**
* nvErrCodeGetLevelByErrID
* @brief  根据错误ID获取对应的错误等级信息
*
* @param	[in]  dwErrorID     错误码ID
* @param	[out] byLevel       错误等级
* @return	u32  0:执行成功    非0:执行失败，见错误码
*
*/
KdvNvEcAPI u32 KdvNvEcCALL nvErrCodeGetLevelByErrID( u32 dwErrorID, u8& byLevel );



/**
* nvErrCodeGetErrDescByErrID
* @brief  根据错误ID获取对应的错误描述信息
*
* @param	[in]     dwErrID       错误ID（全格式的）
* @param	[in]     pchDestBuf    接收错误描述的buf
* @param	[in/out] wBufSize      buf大小，调用后是返回实际内容大小
* @param	[in]     pchLangType   要获取的语种信息
* @return	u32  0:执行成功    非0:执行失败，见错误码
* @note     要返回错误码描述，调用nvErrCodeApiInit接口时，表现设置错误描述路径
*
*/
KdvNvEcAPI u32 KdvNvEcCALL nvErrCodeGetErrDescByErrID(u32 dwErrID, s8* pchDestBuf, u16& wBufSize, const s8* pchLangType = "zh_cn" );


 
#endif //_NVERRORCODE_API_H_