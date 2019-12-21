/**===========================================================================
 * @file    $Id$
 * @brief   负责NVTERINTERFACE业务模块的错误码定义
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _NVERRORCODE_NVTERINTERFACE_H_
#define _NVERRORCODE_NVTERINTERFACE_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief 错误码规则(10进制表示)
 *	 99                   99                    9             9999
 *	模块        +      子业务分类      +     错误等级    +   分配数量
 *(2位/100个)        （2位/100个）          （1位/10个）     (4位/10000个)
 */

/** NVACCESS业务模块的子业务模块ID定义, 新增子业务分类定义只能往后追加 */
enum EM_ERR_SUBMOD_NVTERINTERFACE
{
    emErrSubModNvTerinterface_Base = 0,              ///< NvTerinterface基础子业务模块
};

//////////////////////////////////////////////////////////// Base //////////////////////////////////////////////////////////////////////////////////////
/** NvTerinterface业务模块基本错误码定义 */


/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _NVTERINTERFACE_H_