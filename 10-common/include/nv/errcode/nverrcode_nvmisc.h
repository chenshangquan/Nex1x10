/**===========================================================================
 * @file    $Id$
 * @brief   小业务模块错误码定义
 * @author  瞿戴沣
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _NVERRORCODE_NVMISC_H_
#define _NVERRORCODE_NVMISC_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief 错误码规则(10进制表示)
 *	 99                   99                    9             9999
 *	模块        +      子业务分类      +     错误等级    +   分配数量
 *(2位/100个)        （2位/100个）          （1位/10个）     (4位/10000个)
 */

/** nvutils错误码子模块ID定义, 新增子业务分类定义只能往后追加 */
enum EM_ERR_SUBMOD_Misc
{
    emErrSubModMisc = 0,        ///< 终端错误码子模块
};


/** nvutils模块错误码定义 */
enum EmErrcodeUtils
{
  ERR_NVMISC_DISK_OUTOF_SPACE,                ///< 磁盘空间不足
  ERR_NVMISC_NETCAPTURE_STOP,                 ///< 抓包停止
  ERR_NVMISC_CREATPROCESS_FAILED,             ///< 启动进程失败
  ERR_NVMISC_FILE_NOT_EXIST,                  ///< 文件不存在
  ERR_NVMISC_FILE_EXPORT_FAILED,              ///< 导出文件失败
  ERR_NVMISC_PATH_NOT_EXIST,                  ///< 路径不存在
  ERR_NVMISC_PROCESS_IS_RUNNING,              ///< 正在运行
};



/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _NVERRORCODE_NVUTILS_H_