/**===========================================================================
 * @file    $Id$
 * @brief   负责MtMcservice业务模块的错误码定义
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _MTERRORCODE_MTMCSERVICE_H_
#define _MTERRORCODE_MTMCSERVICE_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief 错误码规则(10进制表示)
 *	 99                   99                    9             9999
 *	模块        +      子业务分类      +     错误等级    +   分配数量
 *(2位/100个)        （2位/100个）          （1位/10个）     (4位/10000个)
 */

/** MTACCESS业务模块的子业务模块ID定义, 新增子业务分类定义只能往后追加 */
enum EM_ERR_SUBMOD_MTMCSERVICE
{
    emErrSubModMtMcservice_Base = 0,              ///< mtmcservice基础子业务模块
};

//////////////////////////////////////////////////////////// Base //////////////////////////////////////////////////////////////////////////////////////
/** mtmcservice业务模块基本错误码定义 */
enum EmMtMcErrorId
{
	ERR_MTMCSERVICE_BASE_NOTPERMIT_ADHOT = 1,                                             ///< 不允许点对点扩展成多点
	ERR_MTMCSERVICE_BASE_HAS_ADHOT,                                                       ///< 已经是多点会议了
	ERR_MTMCSERVICE_BASE_HASNOT_RESOURCE,                                                 ///< 没有资源，即所有的endpoint都是非空闲状态
	ERR_MTMCSERVICE_BASE_CALLING_FAILED,
};

/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _MTERRORCODE_MTMCSERVICE_H_