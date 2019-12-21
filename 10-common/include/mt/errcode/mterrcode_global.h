/**===========================================================================
 * @file    $Id$
 * @brief   负责终端全局错误码定义
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _MTERRORCODE_GLOBAL_H_
#define _MTERRORCODE_GLOBAL_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief 错误码规则(10进制表示)
 *	 99                   99                    9             9999
 *	模块        +      子业务分类      +     错误等级    +   分配数量
 *(2位/100个)        （2位/100个）          （1位/10个）     (4位/10000个)
 */

/** Global错误码子模块ID定义, 新增子业务分类定义只能往后追加 */
enum EM_ERR_SUBMOD_GLOBAL
{
    emErrSubModGlobal = 0,        ///< 终端错误码子模块，较少，暂就一类
};


/** Global模块错误码定义 */
#define  MT_SUCCESS                                  (u32)0                                             ///< 操作成功  
#define  MT_FAILED                                   (u32)1                                             ///< 操作失败  
/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _MTERRORCODE_GLOBAL_H_