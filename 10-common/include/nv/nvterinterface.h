/**===========================================================================
 * @file    nvterinterface.h
 * @brief   
 * @author  yanglei
 * @date    
 * @version  
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/
#ifndef _NVTERINTERFACE_H_
#define _NVTERINTERFACE_H_
#include "kdvtype.h"
#include "nvstruct.h"
#include "nvmacro.h"

//#include "osp.h"
//#include "kdvtype.h"
extern "C"
{
	/**----------------------------------------------------------------------
	* NvTerinterfaceStart
	* 
	* @brief   终端客户端接入模块启动接口
	* 
	* @param   [in] tMdlStartparam 启动参数
	* @return  BOOL32 TRUE:成功启动， FALSE:启动失败
	* @see     NvTerinterfaceStop()
	------------------------------------------------------------------------*/
	NVCBB_API BOOL32 NvTerinterfaceStart(TMdlStartParam &tMdlStartparam);

	/**----------------------------------------------------------------------
	* NvTerinterfaceStop
	* 
	* @brief   消息调度模块退出接口
	* 
	* @param   void
	* @return  BOOL32 TRUE:成功退出， FALSE:退出失败
	* @see     NvTerinterfaceStart()
	------------------------------------------------------------------------*/
	NVCBB_API BOOL32 NvTerinterfaceStop();


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