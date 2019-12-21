/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   公用函数
 * @author  瞿戴沣
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * 
 */
/*---------------------------------------------------------------------------*/

#ifndef _NVUTILS_H_
#define _NVUTILS_H_

#include "errcode/nverrcode_nvutils.h"

#include "utils/nvutilsblockmanager.h"		/* 线程阻塞查询接口 */

#include "utils/nvutilscharset.h"			/* 字符编码相互转换接口 */

#include "utils/nvutilsencrypt.h"			/* 字符串/文件加密解密、校验公用函数 */

#include "utils/nvutilsexception.h"			/* 异常捕获 */

#include "utils/nvutilsipstring.h"			/* ip地址相关接口 */

#include "utils/nvutilssystem.h"			/* 系统相关接口 */

#include "utils/nvutilscommon.h"			/* 一般公用函数接口 */

#include "utils/sharedmemoryblock.h"		/* 共享内存 */

#include "utils/nvutilsmedia.h"		/* 媒体 */



/** ***********************************************************
* 
* @brief    内部打印函数
*
* @param	[in] pchFnv 格式控制字符串
*
* @return	无
*           
**************************************************************/
void nvUtilsLog(const s8 *pchFnv, ...);

/**----------------------------------------------------------------------
* NvUtilsInit
* 
* @brief   基础模块初始化操作
* 
* @param	[in] pfPrintFunc 打印函数函数指针
* @return  BOOL32 TRUE:成功启动， FALSE:启动失败
* @see
------------------------------------------------------------------------*/
NVCBB_API BOOL32 NvUtilsInit( NVUTILS::PRINTFUNC pfPrintFunc );

#endif