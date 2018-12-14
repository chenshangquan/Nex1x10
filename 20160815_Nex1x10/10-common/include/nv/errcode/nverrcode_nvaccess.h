/**===========================================================================
 * @file    $Id$
 * @brief   负责NVACCESS业务模块的错误码定义
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _NVERRORCODE_NVACCESS_H_
#define _NVERRORCODE_NVACCESS_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief 错误码规则(10进制表示)
 *	 99                   99                    9             9999
 *	模块        +      子业务分类      +     错误等级    +   分配数量
 *(2位/100个)        （2位/100个）          （1位/10个）     (4位/10000个)
 */

/** NVACCESS业务模块的子业务模块ID定义, 新增子业务分类定义只能往后追加 */
enum EM_ERR_SUBMOD_NVACCESS
{
    emErrSubModNvAccess_Base = 0,              ///< nvaccess基础子业务模块
};

//////////////////////////////////////////////////////////// Base //////////////////////////////////////////////////////////////////////////////////////
/** nvaccess业务模块基本错误码定义 */
enum EmNvAccessErrorId
{
	ERR_NVACCESS_BASE_USER_ERR = 1,                                                                                   ///< 用户名不合法
	ERR_NVACCESS_BASE_PSW_ERR,                                                                                        ///< 密码错误
	ERR_NVACCESS_BASE_ACTOR_NOTMATCH,                                                                                 ///< 账号没有该功能权限（这里是指单点登录的时候只有admin才能增、删、改用户名）
	ERR_NVACCESS_BASE_USER_DUPLICATE,                                                                                 ///< 重复账号
	ERR_NVACCESS_BASE_USER_NOTEXIST,                                                                                  ///< 账号不存在
	ERR_NVACCESS_BASE_NOT_ENOUGHMEM,                                                                                  ///< 用户超出最大用户容量
	ERR_NVACCESS_BASE_ACTOR_ONLY,                                                                                     ///< 密码错误（暂时没有使用）
	ERR_NVACCESS_BASE_OPERATE_NOTPERMIT,                                                                              ///< 没有操作权限（这里是指单点登录只有admin才能修改用户权限为admin，多点登录admin权限不能修改）
	ERR_NVACCESS_BASE_MULTILOGIN,                                                                                     ///< 重复登录（暂时没有使用）
};

/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _NVERRORCODE_NVACCESS_H_