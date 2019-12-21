/**===========================================================================
 * @file    $Id$
 * @brief   负责NVDISPATCH业务模块的错误码定义
 * @author  longwei
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _NVERRORCODE_NVDISPATCH_H_
#define _NVERRORCODE_NVDISPATCH_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief 错误码规则(10进制表示)
 *	 99                   99                    9             9999
 *	模块        +      子业务分类      +     错误等级    +   分配数量
 *(2位/100个)        （2位/100个）          （1位/10个）     (4位/10000个)
 */

/** NVDISPATCH业务模块的子业务模块ID定义, 新增子业务分类定义只能往后追加 */
enum EM_ERR_SUBMOD_NVDISPATCH
{
    emErrSubModNvDispatch_Base = 0,              ///< nvdispatch基础子业务模块
};

//////////////////////////////////////////////////////////// Base //////////////////////////////////////////////////////////////////////////////////////
/** nvdispatch业务模块基本错误码定义 */
enum EmNvDispatchErrorId
{
	ERR_NVDISPATCH_BASE_CHECKSUBSMSGID_SUCCESS = 1,                                                                                  ///< 校正订阅消息数据结构成功
	ERR_NVDISPATCH_BASE_CHECKSUBSMSGID_NOMSG,                                                                                        ///< 校正订阅消息数据结构失败，因为订阅消息数据结构中没有消息、
	ERR_NVDISPATCH_BASE_CHECKSUBSMSGID_ERRORMSGSEG,                                                                                  ///< 校正订阅消息数据结构失败，因为订阅消息数据结构中消息段不合法
	ERR_NVDISPATCH_BASE_SUBSUNIT_NULL,                                                                                               ///< 订阅单元为NULL
	ERR_NVDISPATCH_BASE_SUBS_SUCCESS,                                                                                                ///< 消息订阅成功
	ERR_NVDISPATCH_BASE_DISPATCH_SUCCESS,                                                                                            ///< 消息分发成功
	ERR_NVDISPATCH_BASE_DISPATCH_NULL,                                                                                               ///< 消息分发器为NULL
	ERR_NVDISPATCH_BASE_DISPATCH_NOTTDEAL,                                                                                           ///< 消息分发器不能分发这条消息
	ERR_NVDISPATCH_BASE_NVMSG_NULL,                                                                                                  ///< 处理的CNvMsg*为NULL
	ERR_NVDISPATCH_BASE_OSPMSG_NULL,                                                                                                 ///< 处理的CMessage*为NULL
	ERR_NVDISPATCH_BASE_ENCODEMSG_FAILED,                                                                                            ///< 处理的CNvMsg编码失败
	ERR_NVDISPATCH_BASE_POSTMSG_FAILED,                                                                                              ///< OSP发送消息失败
	ERR_NVDISPATCH_BASE_GETSUBSMSGSESSION_SUCCESS,                                                                                   ///< 获取订阅者成功
	ERR_NVDISPATCH_BASE_DISPATCH_FAILED,                                                                                             ///< 消息分发失败
};

/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _NVERRORCODE_NVDISPATCH_H_