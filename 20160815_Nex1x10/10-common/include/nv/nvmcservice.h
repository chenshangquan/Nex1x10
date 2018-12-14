/**===========================================================================
 * @file    nvmcservice.h
 * @brief   
 * @author  longwei
 * @date    
 * @version  
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/
#ifndef _NVMCSERVICE_H_
#define _NVMCSERVICE_H_
#include "kdvtype.h"
#include "nvstruct.h"


extern "C"
{
/**----------------------------------------------------------------------
* NvMcserviceStart
* 
* @brief   终端客户端接入模块启动接口
* 
* @param   [in] tMdlStartparam 启动参数
* @return  BOOL32 TRUE:成功启动， FALSE:启动失败
* @see     NvMcserviceStop()
------------------------------------------------------------------------*/
NVCBB_API BOOL32 NvMcserviceStart(TMdlStartParam &tMdlStartparam);

/**----------------------------------------------------------------------
* NvMcserviceStop
* 
* @brief   内置mc模块退出接口
* 
* @param   void
* @return  BOOL32 TRUE:成功退出， FALSE:退出失败
* @see     NvMcserviceStart()
------------------------------------------------------------------------*/
NVCBB_API BOOL32 NvMcserviceStop();

};

#endif