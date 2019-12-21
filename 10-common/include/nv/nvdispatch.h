/**===========================================================================
 * @file    nvdispatch.h
 * @brief   
 * @author  longwei
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/
#ifndef _NVDISPATCH_H_
#define _NVDISPATCH_H_

#include "kdvtype.h"
#include "nvstruct.pb.h"
#include "nvstruct.h"
#include "nvmacro.h"
#include "nvmsg.h"


extern "C"
{

//回调函数
/**----------------------------------------------------------------------
	* ExternHandler
	* 
	* @brief    外部处理消息的回调函数
	* 
	* @param	[in] pcNvMsg 订阅消息的具体消息
	* @param	[in] dwSrcId 订阅消息的appinstid
	* @param	[in] dwSrcNode 订阅消息的nodeid
	* @return	BOOL32 TRUE:已经处理了，不需要继续由其它处理这个消息， FALSE:需要由其它处理这个消息
	------------------------------------------------------------------------*/
// NVCBB_API typedef BOOL32 (ExternHandler)(nvmsg::CNvMsg *pcNvMsg, u32 dwSrcId, u32 dwSrcNode);

/**----------------------------------------------------------------------
	* RegisterExternHandler
	* 
	* @brief    注册外部消息处理的回调函数
	* 
	* @param	[in] pcNvMsg 订阅消息的具体消息
	* @param	[in] dwSrcId 订阅消息的appinstid
	* @param	[in] dwSrcNode 订阅消息的nodeid
	* @return	void
	------------------------------------------------------------------------*/
/*NVCBB_API void RegisterExternHandler( ExternHandler *pfHandle );*/

/**----------------------------------------------------------------------
* NvDispatchStart
* 
* @brief   消息调度模块启动接口
* 
* @param   [in] tMdlStartparam 启动参数
* @return  BOOL32 TRUE:成功启动， FALSE:启动失败
* @see     NvDispatchStop()
------------------------------------------------------------------------*/
NVCBB_API BOOL32 NvDispatchStart(TMdlStartParam &tMdlStartparam );

/**----------------------------------------------------------------------
* NvDispatchStop
* 
* @brief   消息调度模块退出接口
* 
* @param   void
* @return  BOOL32 TRUE:成功退出， FALSE:退出失败
* @see     NvDispatchStart()
------------------------------------------------------------------------*/
NVCBB_API BOOL32 NvDispatchStop();

};

#endif // _NVDISPATCH_H_