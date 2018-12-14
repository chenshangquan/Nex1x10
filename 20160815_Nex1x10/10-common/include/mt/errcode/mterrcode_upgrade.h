/**===========================================================================
 * @file    $Id$
 * @brief   升级子系统错误码定义
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _MTERRORCODE_MTUPGRADE_H_
#define _MTERRORCODE_MTUPGRADE_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief 错误码规则(10进制表示)
 *	 99                   99                    9             9999
 *	模块        +      子业务分类      +     错误等级    +   分配数量
 *(2位/100个)        （2位/100个）          （1位/10个）     (4位/10000个)
 */

/** 升级子系统错误码子模块ID定义, 新增子业务分类定义只能往后追加 */
enum EM_ERR_SUBMOD_UPGRADE
{
    emErrSubModUpgrade = 0,        ///< 终端错误码子模块
};


/** 升级子系统模块错误码定义 */
enum EmMtUpgradeErrCode
{
	ERR_UPGRADE_UNKNOWN,                  ///< 未知错误
	ERR_UPGRADE_INVALID_FILE,	          ///< 非法文件
	ERR_UPGRADE_INVALID_PATH,	          ///< 非法路径
	ERR_UPGRADE_INVALID_SN,	              ///< 非法版本序列号
	ERR_UPGRADE_CONNECT_SERVER_FAILED,    ///< 连接服务器失败
	ERR_UPGRADE_SYS_BACKUP_FAILED,		  ///< 系统备份失败
	ERR_UPGRADE_SYS_MOUNTAPPBAK_FAILED,	  ///< 备份APP分区挂载失败
	ERR_UPGRADE_FILE_CHECK_FAILED,		  ///< 文件校验失败
	ERR_UPGRADE_WHOLEUPGRADE_FAILED,	  ///< 整体升级失败
	ERR_UPGRADE_IOS_UPGRADE_FAILED,		  ///< IOS升级失败
	ERR_UPGRADE_FPGA_UPGRADE_FAILED,	  ///< fpga升级失败
	ERR_UPGRADE_DISK_SPACE_NOT_ENOUGH,	  ///< 磁盘空间不足
	ERR_UPGRADE_MAX_SERVICE_SESSION_ERR, //服务器已达最大容量限制
	ERR_UPGRADE_TIMEOUT,  //操作超时
	ERR_UPGRADE_NOT_PREPARED_NOW_ERR,  //服务器尚未启动完毕
	ERR_UPGRADE_FILE_NOT_EXIST_ERR, //指定文件不存在
	ERR_UPGRADE_DEV_NOT_EXIST_ERR, //服务器中无此设备的版本
	ERR_UPGRADE_OEMREMARK_NOT_MATCH,  //OEM标识不匹配
    ERR_UPGRADE_DNS_ERR,                 ///解析域名失败
};


/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _MTERRORCODE_MTUPGRADE_H_