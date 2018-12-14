/**===========================================================================
 * @file    $Id$
 * @brief   负责终端错误码统一分配管理定义
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _NVERRORCODE_DEF_H_
#define _NVERRORCODE_DEF_H_

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
*@brief 错误码规则(10进制表示)
*	 99                   99                    9             9999
*	模块        +      子业务分类      +     错误等级    +   分配数量
*(2位/100个)        （2位/100个）          （1位/10个）     (4位/10000个)
*/

/**错误码模块ID定义, emErrorModuleUI = 30这个之前的给NVCBB使用，
再没有超过30时，可以定义到emErrorModuleUI之前，超过以后新增的模块定义只能往后追加 */
enum EM_ERROR_MODULE
{
    emErrorModuleGlobal = 0,        ///< 终端全局错误码
    emErrorModuleNVAPI,             ///< 终端NVAPI 细粒度
    emErrorModuleNVSDK,             ///< 终端NVSDK 粗粒度
    emErrorModuleDispatch,          ///< 终端调度模块
    emErrorModuleNVSysCtrl,         ///< 终端系统控制子系统
	emErrorModuleDataShare,         ///< 终端数据共享模块
    emErrorModuleIM,                ///< 终端IM子系统
    emErrorModuleDataConf,          ///< 终端数据协同子系统
    emErrorModuleMeetingMgr,        ///< 终端会管日程子系统
	emErrorModuleNVMP,              ///< 终端媒体业务子系统
	emErrorModuleSNMP,              ///< 终端网管业务子系统
	emErrorModuleDevice,            ///< 终端设备控制子系统
	emErrorModuleUpdate,            ///< 终端升级业务子系统
	emErrorModuleNetworkService,    ///< 终端网络服务接入子系统
	emErrorModuleServerLogin,      ///< 终端服务器登录子系统
	emErrorModuleMisc,              ///< 终端小业务子系统
	emErrorModuleDiagnose,          ///< 终端诊断业务子系统
	emErrorModuleToolApi,           ///< 终端工具类API实现库
	emErrorModuleAccess,            ///< 终端接入模块
	emErrorModuleNvConf,            ///< 终端会议子系统
	emErrorModuleNvVod,            ///< 终端点播子系统
	emErrorModuleNvpa,              ///<
	emErrorModuleNvmc,              ///<内置mc模块

	                                ///< 不超30，可再此前面进行NVCBB模块的扩展
	emErrorModuleUI = 30,           ///< 终端UI(保留给UI) 
	emErrorModuleMediaCtrl,         ///< 媒体控制模块(保留给媒体组)
	emErrorModuleProtocol,          ///< 网络协议模块(保留给网络协议组)
	emErrorModuleDriverCtrl,        ///< 硬件驱动模块(保留给驱动组)
	emErrorModuleHardWare,          ///< 硬件设备模块(保留给硬件组)
};

/** 错误码等级定义, 新增等级定义只能往后追加 */
enum EM_ERROR_LEVEL
{
    emErrorLevelInfo = 0,           ///< 信息提示类
    emErrorLevelWarning,            ///< 警告类
    emErrorLevelError,              ///< 错误类
    emErrorLevelSysError,           ///< 严重错误类(系统级别的) 
};

/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _NVERRORCODE_DEF_H_