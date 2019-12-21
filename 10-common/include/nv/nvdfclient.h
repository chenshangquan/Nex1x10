/**===========================================================================
 * @file    nvdfclient.h
 * @brief   
 * @author  yanglei
 * @date    
 * @version  
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/
#ifndef _NVDFCLIENT_H_
#define _NVDFCLIENT_H_
#include "kdvtype.h"
#include "nvstruct.h"
#include "nvmacro.h"

typedef u32 (*GETTERIPADDR_CALLBACK)(TNVDfServiceParam_API *ptDfParam);

extern "C"
{
	/**----------------------------------------------------------------------
	* NvStartDfClient
	* 
	* @brief   启动设备查找客户端
	* @param	TNVDfClientParam_API
	* @return  BOOL32 TRUE:成功启动， FALSE:启动失败
	------------------------------------------------------------------------*/
	NVCBB_API BOOL32 NvStartDfClient( TNVDfClientParam_API &tDfStartParam );

	/**----------------------------------------------------------------------
	* NvEnableAskServiceAddr
	* 
	* @brief   是否查找服务器地址
	* @param	BOOL32
	* @return  BOOL32 TRUE:成功启动， FALSE:启动失败
	------------------------------------------------------------------------*/
	NVCBB_API BOOL32 NvEnableAskServiceAddr( BOOL32 bEnable );
	
	/**----------------------------------------------------------------------
	* NvStopDfClient
	* 
	* @brief   关闭设备查找客户端
	* @return  BOOL32 TRUE:成功启动， FALSE:启动失败
	------------------------------------------------------------------------*/
	NVCBB_API BOOL32 NvStopDfClient(  );
	
	
	/**----------------------------------------------------------------------
	* NvSetTerIpCallBack
	* 
	* @brief   设置ip地址回调函数
	* @return  BOOL32 TRUE:成功启动， FALSE:启动失败
	------------------------------------------------------------------------*/
	NVCBB_API BOOL32 NvSetTerIpCallBack( GETTERIPADDR_CALLBACK cbIpAddr );
};

// #ifdef __cplusplus
// extern "C" {
// #endif
// 
// 	
// 
// #ifdef __cplusplus
// }
// #endif
 #endif