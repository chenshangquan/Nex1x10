/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   终端日志模块
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
 * 
 */
/*---------------------------------------------------------------------------*/
#ifndef _NVLOG_H_
#define _NVLOG_H_
#include "kdvtype.h"
#include "nvmacro.h"
#include <string>
#include "logmod.h"

/*******************************************************************************/

#define DEFAULT_LOG_SWITCH 1

namespace NVLOG {

/*---------------------------------------------------------------------------*/
/**
 * @class Class CNvLog
 * @brief 日志打印类
 * @author $Author$
 * @version $Revision$
 * @data $Date$
 * @note 需要使用日志接口的类可以继承自此类
 */
/*---------------------------------------------------------------------------*/
 class NVCBB_API CNvLog
{
public:	
	/** ***********************************************************
	* 
	* @brief    构造函数
	*
	* @param	无
	* @return	无
	*
	**************************************************************/
	CNvLog(){}

	/** ***********************************************************
	* 
	* @brief    析构函数
	*
	* @param	无
	* @return	无
	*
	**************************************************************/
	~CNvLog(){}

public:
	/** ***********************************************************
	* 
	* @brief    Error等级日志打印接口,带换行符
	*
	* @param	[in] pchFnv     变长参数
	* @return	无
	*
	**************************************************************/
	void Error(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Warning等级日志打印接口,带换行符
	*
	* @param	[in] pchFnv     变长参数
	* @return	无
	*
	**************************************************************/
	void Warning(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Hint等级日志打印接口,带换行符
	*
	* @param	[in] pchFnv     变长参数
	* @return	无
	*
	**************************************************************/
	void Hint(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Debug等级日志打印接口,带换行符
	*
	* @param	[in] pchFnv     变长参数
	* @return	无
	*
	**************************************************************/
	void Debug(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Trace等级日志打印接口,带换行符
	*
	* @param	[in] pchFnv     变长参数
	* @return	无
	*
	**************************************************************/
	void Trace(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Error等级日志打印接口,不带换行符
	*
	* @param	[in] pchFnv     变长参数
	* @return	无
	*
	**************************************************************/
	void ErrorNoln(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Warning等级日志打印接口,不带换行符
	*
	* @param	[in] pchFnv     变长参数
	* @return	无
	*
	**************************************************************/
	void WarningNoln(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Hint等级日志打印接口,不带换行符
	*
	* @param	[in] pchFnv     变长参数
	* @return	无
	*
	**************************************************************/
	void HintNoln(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Debug等级日志打印接口,不带换行符
	*
	* @param	[in] pchFnv     变长参数
	* @return	无
	*
	**************************************************************/
	void DebugNoln(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Trace等级日志打印接口,不带换行符
	*
	* @param	[in] pchFnv     变长参数
	* @return	无
	*
	**************************************************************/
	void TraceNoln(const s8 *pchFormat, ...);

public:
	/** ***********************************************************
	* 
	* @brief    设定类所属日志模块
	*
	* @param	[in] emModule  日志模块ID
	* @return	无
	*
	**************************************************************/
	void SetLogMoudle(std::string strLogger){ m_strLogger = strLogger; }

	/** ***********************************************************
	* 
	* @brief    获取所属日志模块ID
	*
	* @param	无
	* @return	所属日志模块ID
	*
	**************************************************************/
	std::string GetModuleId(){ return m_strLogger; }

private:
	std::string m_strLogger; ///< 类所属模块ID
};


/** ***********************************************************
* 
* @brief    初始化日志模块
*
* @param	[in] strCfgFilePath            日志配置文件，utf8编码
* @param	[in] bToFileLogServer          TRUE 文件日志输出到日志服务器，FALSE 文件日志输出到本地
* @return	NV_SUCCESS 成功
*           NV_FAILED  失败
**************************************************************/
NVCBB_API u32 nvInitLogModule(std::string strSvrIp = "", std::string strCfgFilePath = "", BOOL32 bToFileLogServer = FALSE, std::string strCltTag = "");

/** ***********************************************************
* 
* @brief    初始化日志模块,可选择连接日志服务器的端口
*
* @param	[in] strCfgFilePath            日志配置文件，utf8编码
* @param	[in] bToFileLogServer          TRUE 文件日志输出到日志服务器，FALSE 文件日志输出到本地
* @return	NV_SUCCESS 成功
*           NV_FAILED  失败
**************************************************************/
NVCBB_API u32 nvInitLogModuleOfPort(std::string strSvrIp = "", std::string strCfgFilePath = "", BOOL32 bToFileLogServer = FALSE, std::string strCltTag = "", u32 dwPort = 10000);


/** ***********************************************************
* 
* @brief    注册日志模块
*
* @param	[in] emModule        日志模块ID
* @param	[in] pchModuleName   模块名称
* @param	[in] bOn             是否开启模块打印
* @return	NV_SUCCESS 成功
*           NV_FAILED  失败
**************************************************************/
NVCBB_API u32 nvRegLogModule(std::string strLogger, s8 *pchModuleName, BOOL32 bOn = FALSE);

/** ***********************************************************
* 
* @brief    放开打印接口
* 
* @param	[in] strModule       日志模块ID
* @return	无
* @note     此打印接口不受调试命令控制
*
**************************************************************/
NVCBB_API void NvLogOn(std::string strModule = "");

/** ***********************************************************
* 
* @brief    关闭打印接口
* 
* @param	[in] strModule       日志模块ID
* @return	无
* @note     此打印接口不受调试命令控制
*
**************************************************************/
NVCBB_API void NvLogOff(std::string strModule = "");

/** ***********************************************************
* 
* @brief    放开debug打印接口
* 
* @param	[in] strModule       日志模块ID
* @return	无
* @note     此打印接口不受调试命令控制
*
**************************************************************/
NVCBB_API void NvDebugOn(std::string strModule = "");

/** ***********************************************************
* 
* @brief    关闭debug打印接口
* 
* @param	[in] strModule       日志模块ID
* @return	无
* @note     此打印接口不受调试命令控制
*
**************************************************************/
NVCBB_API void NvDebugOff(std::string strModule = "");

/** ***********************************************************
* 
* @brief    Error等级日志打印接口,带换行符
*
* @param	[in] emModule   日志模块ID
* @param	[in] pchFnv     变长参数
* @return	无
*
**************************************************************/
NVCBB_API void NvLogErr(std::string strLogger, const s8 *pchFnv, ...);


/** ***********************************************************
* 
* @brief    Warning等级日志打印接口,带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFnv     变长参数
* @return	无
*
**************************************************************/
NVCBB_API void NvLogWarn(std::string strLogger, const s8 *pchFnv, ...);


/** ***********************************************************
* 
* @brief    Hint等级日志打印接口,带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFnv     变长参数
* @return	无
*
**************************************************************/
NVCBB_API void NvLogHint(std::string strLogger, const s8 *pchFnv, ...);


/** ***********************************************************
* 
* @brief    Debug等级日志打印接口,带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFnv     变长参数
* @return	无
* @note     Debug等级打印不会输出到日志文件
*
**************************************************************/
NVCBB_API void NvLogDebug(std::string strLogger, const s8 *pchFnv, ...);	


/** ***********************************************************
* 
* @brief    Trace等级日志打印接口,带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFnv     变长参数
* @return	无
* @note     Trace等级打印不会输出到日志文件
*
**************************************************************/
NVCBB_API void NvLogTrace(std::string strLogger, const s8 *pchFnv, ...);



/** ***********************************************************
* 
* @brief    Error等级日志打印接口,不带换行符
*
* @param	[in] emModule   日志模块ID
* @param	[in] pchFnv     变长参数
* @return	无
*
**************************************************************/
NVCBB_API void NvLogErrNoln(std::string strLogger, const s8 *pchFnv, ...);


/** ***********************************************************
* 
* @brief    Warning等级日志打印接口,不带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFnv     变长参数
* @return	无
*
**************************************************************/
NVCBB_API void NvLogWarnNoln(std::string strLogger, const s8 *pchFnv, ...);


/** ***********************************************************
* 
* @brief    Hint等级日志打印接口,不带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFnv     变长参数
* @return	无
*
**************************************************************/
NVCBB_API void NvLogHintNoln(std::string strLogger, const s8 *pchFnv, ...);


/** ***********************************************************
* 
* @brief    Debug等级日志打印接口,不带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFnv     变长参数
* @return	无
* @note     Debug等级打印不会输出到日志文件
*
**************************************************************/
NVCBB_API void NvLogDebugNoln(std::string strLogger, const s8 *pchFnv, ...);	


/** ***********************************************************
* 
* @brief    Trace等级日志打印接口,不带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFnv     变长参数
* @return	无
* @note     Trace等级打印不会输出到日志文件
*
**************************************************************/
NVCBB_API void NvLogTraceNoln(std::string strLogger, const s8 *pchFnv, ...);

/** ***********************************************************
* 
* @brief    设置文件日志开关
* 
* @param	[in] bEnable   日志内容是否写入日志文件
* @return	无
*
**************************************************************/
NVCBB_API void nvSetFileLogEnable(BOOL32 bEnable);

}


/** ***********************************************************
* 
* @brief    打印接口
* 
* @param	[in] pchFnv   要打印信息 变长参数
* @return	无
* @note     此打印接口不受调试命令控制
*
**************************************************************/
NVCBB_API void nvPrintf(const s8 *pchFnv, ...);



/** ***********************************************************
* 
* @brief    打印接口(结尾自动加上换行符)
* 
* @param	[in] pchFnv   要打印信息 变长参数
* @return	无
* @note     此打印接口不受调试命令控制
*
**************************************************************/
NVCBB_API void nvPrintfln(const s8 *pchFnv, ...);


#endif  //_NVLOG_H_
































#if 0
/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   终端日志模块
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
 * 
 */
/*---------------------------------------------------------------------------*/
#ifndef _NVLOG_H_
#define _NVLOG_H_
#include "kdvtype.h"
#include "nvmacro.h"

/******** 日志枚举定义 *********************************************************/

/** 日志模块ID 增加模块再次添加对应模块ID */
enum EmNvLogModule
{
	MDL_BGN = 0,

	MDL_DRIVER,		           ///< 该模块ID专门给驱动组打印接口到日志使用
	MDL_SYSCTRL,	           ///< 系统控制子系统
	MDL_IM,			           ///< Im子系统
	MDL_REST,                  ///< REST子系统
	MDL_DSCLIENT,              ///< 数据共享客户端
	MDL_DSSERVER,              ///< 数据共享服务端
	MDL_CFG,                   ///< 配置管理
	MDL_MP,                    ///< 媒体处理组件 (nvmp)
	MDL_NVDEVICE,	           ///< 硬终端设备管理(nvdevice)
	MDL_NVMFGTEST,             ///< 硬终端生产测试模块	
	MDL_NVCONF,                ///< nvservice里的conf模块 
	MDL_NVPA,                  ///< nvpa模块 
	MDL_NVH323,                ///< nvh323模块 
	MDL_NVMC,                  ///< nvmc模块 	
	MDL_NVDISPATCH,            ///<消息调度模块
	MDL_NVACCESS,              ///<终端客户端接入模块
	MDL_AGENT,                 ///<网管模块（nvagent）
	MDL_AGENTADP,              ///<网管适配模块（nvagentadp）
	MDL_MISC,		           ///< 小业务子系统
	MDL_NVVOD,		           ///< 点播系统
	MDL_UPGRADE,	           ///< 升级子系统
	MDL_MCSERVICE,	           ///< 内置mc模块
	MDL_RECORD,                ///< 本地地址簿&呼叫记录
	MDL_NVSERVICE,             ///< nvservice模块
	MDL_NVAPI,                 ///< nvapi对外封装API模块
	MDL_NVAPI_BS,              ///< nvbaseapi终端baseapi模块
	MDL_NVAPI_VC,              ///< nvvcapi VideoConference视频会议控制模块
	MDL_NVAPI_IM,              ///< nvimapi即时通讯模块
	MDL_NVAPI_CM,              ///< nvcmapi ContactManager联系人管理模块
	MDL_NVAPI_MG,              ///< nvmgapi MeetingManager会议室管理模块
	MDL_NVAPI_VNC,             ///< nvvncapi PC虚拟桌面模块
	MDL_NVAPI_DC,              ///< nvdataconf 数据会议模块
	MDL_NVAPI_DIAGNOSE,        ///< nvdiagnoseapi 诊断模块
	MDL_RPCCLIENT,             ///<nvrpcclient模块
	MDL_RPCSERVER,             ///<nvrpcserver模块
	MDL_XMLRPC,                ///<xmlrpcc++模块
	MDL_SATSERVICE,            ///<sat service
	MDL_SATSTACK,              ///<sat stack
	MDL_DIAGNOSE,              ///<nvdiagnose模块
	MDL_NVUI,                  ///<nvui
	MDL_NVUI_CONF,             ///<点对点多点会议相关
	MDL_NVUI_CFG,              ///<配置相关
	MDL_NVUI_VOD,              ///<VOD相关
	MDL_NVUI_CAM,              ///<摄像机相关
	MDL_NVUI_MON,              ///<监控相关
	MDL_NVUI_REMOTE,           ///<遥控器
	MDL_NVUI_DG,               ///<统计诊断
	MDL_NVUI_CM,               ///<联系人(本地、共享、云端、呼叫记录)
	MDL_NVUI_MG,               ///<会议日程
	MDL_NVUI_IM,               ///<IM,通讯消息
	MDL_NVUI_DC,               ///<数据会议(数据协同)
	MDL_NVUI_NET,              ///<网络相关
	MDL_NETMAGAGE,             ///<网络组件模块
	MDL_NVCAPI_JNI,            ///<jni模块

	MDL_END
};

/** 日志打印等级 */
enum EmNvLogType
{
	emNvLogBgn,
	emNvLogError,   ///< 错误日志
	emNvLogWarn,    ///< 警告日志
	emNvLogHint,    ///< 提示日志
	emNvLogDebug,   ///< 调试日志
	emNvLogTrace,   ///< 临时/定时器打印
	emNvLogEnd
};

/*******************************************************************************/


namespace NVLOG {


/*---------------------------------------------------------------------------*/
/**
 * @class Class CNvLog
 * @brief 日志打印类
 * @author $Author$
 * @version $Revision$
 * @data $Date$
 * @note 需要使用日志接口的类可以继承自此类
 */
/*---------------------------------------------------------------------------*/
 class NVCBB_API CNvLog
{
public:
	/** ***********************************************************
	* 
	* @brief    构造函数
	*
	* @param	无
	* @return	无
	*
	**************************************************************/
	CNvLog(){}

	/** ***********************************************************
	* 
	* @brief    析构函数
	*
	* @param	无
	* @return	无
	*
	**************************************************************/
	~CNvLog(){}

public:
	/** ***********************************************************
	* 
	* @brief    Error等级日志打印接口,带换行符
	*
	* @param	[in] pchFnv     变长参数
	* @return	无
	*
	**************************************************************/
	void Error(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Warning等级日志打印接口,带换行符
	*
	* @param	[in] pchFnv     变长参数
	* @return	无
	*
	**************************************************************/
	void Warning(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Hint等级日志打印接口,带换行符
	*
	* @param	[in] pchFnv     变长参数
	* @return	无
	*
	**************************************************************/
	void Hint(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Debug等级日志打印接口,带换行符
	*
	* @param	[in] pchFnv     变长参数
	* @return	无
	*
	**************************************************************/
	void Debug(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Trace等级日志打印接口,带换行符
	*
	* @param	[in] pchFnv     变长参数
	* @return	无
	*
	**************************************************************/
	void Trace(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Error等级日志打印接口,不带换行符
	*
	* @param	[in] pchFnv     变长参数
	* @return	无
	*
	**************************************************************/
	void ErrorNoln(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Warning等级日志打印接口,不带换行符
	*
	* @param	[in] pchFnv     变长参数
	* @return	无
	*
	**************************************************************/
	void WarningNoln(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Hint等级日志打印接口,不带换行符
	*
	* @param	[in] pchFnv     变长参数
	* @return	无
	*
	**************************************************************/
	void HintNoln(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Debug等级日志打印接口,不带换行符
	*
	* @param	[in] pchFnv     变长参数
	* @return	无
	*
	**************************************************************/
	void DebugNoln(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Trace等级日志打印接口,不带换行符
	*
	* @param	[in] pchFnv     变长参数
	* @return	无
	*
	**************************************************************/
	void TraceNoln(const s8 *pchFormat, ...);

public:
	/** ***********************************************************
	* 
	* @brief    设定类所属日志模块
	*
	* @param	[in] emModule  日志模块ID
	* @return	无
	*
	**************************************************************/
	void SetLogMoudle(EmNvLogModule emMoudleID){ m_emMoudleID = emMoudleID; }

	/** ***********************************************************
	* 
	* @brief    获取所属日志模块ID
	*
	* @param	无
	* @return	所属日志模块ID
	*
	**************************************************************/
	EmNvLogModule GetModuleId(){ return m_emMoudleID; }

private:
	EmNvLogModule m_emMoudleID; ///< 类所属模块ID
};


/** ***********************************************************
* 
* @brief    初始化日志模块
*
* @param	[in] pszCfgFileFullPath        日志配置文件，utf8编码
* @return	NV_SUCCESS 成功
*           NV_FAILED  失败
**************************************************************/
NVCBB_API u32 nvInitLogModule(const s8* pszCfgFileFullPath = NULL);


/** ***********************************************************
* 
* @brief    注册日志模块
*
* @param	[in] emModule        日志模块ID
* @param	[in] pchModuleName   模块名称
* @param	[in] bOn             是否开启模块打印
* @return	NV_SUCCESS 成功
*           NV_FAILED  失败
**************************************************************/
NVCBB_API u32 nvRegLogModule(EmNvLogModule emModule, s8 *pchModuleName, BOOL32 bOn = FALSE);


/** ***********************************************************
* 
* @brief    Error等级日志打印接口,带换行符
*
* @param	[in] emModule   日志模块ID
* @param	[in] pchFnv     变长参数
* @return	无
*
**************************************************************/
NVCBB_API void NvLogErr(EmNvLogModule emModule, const s8 *pchFnv, ...);


/** ***********************************************************
* 
* @brief    Warning等级日志打印接口,带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFnv     变长参数
* @return	无
*
**************************************************************/
NVCBB_API void NvLogWarn(EmNvLogModule emModule, const s8 *pchFnv, ...);


/** ***********************************************************
* 
* @brief    Hint等级日志打印接口,带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFnv     变长参数
* @return	无
*
**************************************************************/
NVCBB_API void NvLogHint(EmNvLogModule emModule, const s8 *pchFnv, ...);


/** ***********************************************************
* 
* @brief    Debug等级日志打印接口,带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFnv     变长参数
* @return	无
* @note     Debug等级打印不会输出到日志文件
*
**************************************************************/
NVCBB_API void NvLogDebug(EmNvLogModule emModule, const s8 *pchFnv, ...);	


/** ***********************************************************
* 
* @brief    Trace等级日志打印接口,带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFnv     变长参数
* @return	无
* @note     Trace等级打印不会输出到日志文件
*
**************************************************************/
NVCBB_API void NvLogTrace(EmNvLogModule emModule, const s8 *pchFnv, ...);



/** ***********************************************************
* 
* @brief    Error等级日志打印接口,不带换行符
*
* @param	[in] emModule   日志模块ID
* @param	[in] pchFnv     变长参数
* @return	无
*
**************************************************************/
NVCBB_API void NvLogErrNoln(EmNvLogModule emModule, const s8 *pchFnv, ...);


/** ***********************************************************
* 
* @brief    Warning等级日志打印接口,不带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFnv     变长参数
* @return	无
*
**************************************************************/
NVCBB_API void NvLogWarnNoln(EmNvLogModule emModule, const s8 *pchFnv, ...);


/** ***********************************************************
* 
* @brief    Hint等级日志打印接口,不带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFnv     变长参数
* @return	无
*
**************************************************************/
NVCBB_API void NvLogHintNoln(EmNvLogModule emModule, const s8 *pchFnv, ...);


/** ***********************************************************
* 
* @brief    Debug等级日志打印接口,不带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFnv     变长参数
* @return	无
* @note     Debug等级打印不会输出到日志文件
*
**************************************************************/
NVCBB_API void NvLogDebugNoln(EmNvLogModule emModule, const s8 *pchFnv, ...);	


/** ***********************************************************
* 
* @brief    Trace等级日志打印接口,不带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFnv     变长参数
* @return	无
* @note     Trace等级打印不会输出到日志文件
*
**************************************************************/
NVCBB_API void NvLogTraceNoln(EmNvLogModule emModule, const s8 *pchFnv, ...);

/** ***********************************************************
* 
* @brief    设置文件日志开关
* 
* @param	[in] bEnable   日志内容是否写入日志文件
* @return	无
*
**************************************************************/
NVCBB_API void nvSetFileLogEnable(BOOL32 bEnable);

}


/** ***********************************************************
* 
* @brief    打印接口
* 
* @param	[in] pchFnv   要打印信息 变长参数
* @return	无
* @note     此打印接口不受调试命令控制
*
**************************************************************/
NVCBB_API void nvPrintf(const s8 *pchFnv, ...);



/** ***********************************************************
* 
* @brief    打印接口(结尾自动加上换行符)
* 
* @param	[in] pchFnv   要打印信息 变长参数
* @return	无
* @note     此打印接口不受调试命令控制
*
**************************************************************/
NVCBB_API void nvPrintfln(const s8 *pchFnv, ...);


#endif  //_NVLOG_H_
#endif

