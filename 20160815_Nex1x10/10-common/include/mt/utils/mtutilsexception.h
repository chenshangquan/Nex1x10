/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   异常捕获公用函数
 * @author  瞿戴沣
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * 
 */
/*---------------------------------------------------------------------------*/

#ifndef _MTEXCEPTION_H_
#define _MTEXCEPTION_H_


#include "kdvtype.h"
#include "mtutilstype.h"
#include "mtmacro.h"


/******************************************************************************
* @namespace    MTUTILS
******************************************************************************/
namespace MTUTILS {


/*!**********************************************************
* @fn      u32 mtInstallExceptionCatch(const s8 *pchModuleName, const s8 *pchLogPath)
* @brief   Linux系统下为可执行模块安装异常捕获
* @param   [in] pchModuleName:可执行模块名
* @param   [in] pchLogName:    异常日志文件名
* @return  MT_SUCCESS:        成功 
           MT_FAILED:         失败
*************************************************************/
MTCBB_API u32 mtInstallExceptionCatch(const s8 *pchModuleName, const s8 *pchLogName);


}




#endif //_MTEXCEPTION_H_