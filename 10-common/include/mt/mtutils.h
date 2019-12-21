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

#ifndef _MTUTILS_H_
#define _MTUTILS_H_

#include "errcode/mterrcode_mtutils.h"

#include "utils/mtutilsblockmanager.h"		/* 线程阻塞查询接口 */

#include "utils/mtutilscharset.h"			/* 字符编码相互转换接口 */

#include "utils/mtutilsencrypt.h"			/* 字符串/文件加密解密、校验公用函数 */

#include "utils/mtutilsexception.h"			/* 异常捕获 */

#include "utils/mtutilsipstring.h"			/* ip地址相关接口 */

#include "utils/mtutilssystem.h"			/* 系统相关接口 */

#include "utils/mtutilscommon.h"			/* 一般公用函数接口 */

#include "utils/sharedmemoryblock.h"		/* 共享内存 */

#include "utils/mtutilsmedia.h"		/* 媒体 */



/** ***********************************************************
* 
* @brief    内部打印函数
*
* @param	[in] pchFmt 格式控制字符串
*
* @return	无
*           
**************************************************************/
void mtUtilsLog(const s8 *pchFmt, ...);

/**----------------------------------------------------------------------
* MtUtilsInit
* 
* @brief   基础模块初始化操作
* 
* @param	[in] pfPrintFunc 打印函数函数指针
* @return  BOOL32 TRUE:成功启动， FALSE:启动失败
* @see
------------------------------------------------------------------------*/
MTCBB_API BOOL32 MtUtilsInit( MTUTILS::PRINTFUNC pfPrintFunc );

#endif