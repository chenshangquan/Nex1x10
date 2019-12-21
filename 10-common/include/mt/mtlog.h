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
#ifndef _MTLOG_H_
#define _MTLOG_H_
#include "kdvtype.h"
#include "mtmacro.h"
#include <string>
#include "logmod.h"

/*******************************************************************************/

#define DEFAULT_LOG_SWITCH 1

namespace MTLOG {


/*---------------------------------------------------------------------------*/
/**
 * @class Class CMtLog
 * @brief 日志打印类
 * @author $Author$
 * @version $Revision$
 * @data $Date$
 * @note 需要使用日志接口的类可以继承自此类
 */
/*---------------------------------------------------------------------------*/
 class MTCBB_API CMtLog
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
	CMtLog(){}

	/** ***********************************************************
	* 
	* @brief    析构函数
	*
	* @param	无
	* @return	无
	*
	**************************************************************/
	~CMtLog(){}

public:
	/** ***********************************************************
	* 
	* @brief    Error等级日志打印接口,带换行符
	*
	* @param	[in] pchFmt     变长参数
	* @return	无
	*
	**************************************************************/
	void Error(const s8 *pchFormat, ...);
	void Error2(const std::string strNote, const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Warning等级日志打印接口,带换行符
	*
	* @param	[in] pchFmt     变长参数
	* @return	无
	*
	**************************************************************/
	void Warning(const s8 *pchFormat, ...);
	void Warning2(const std::string strNote, const s8 *pchFormat, ... );

	/** ***********************************************************
	* 
	* @brief    Hint等级日志打印接口,带换行符
	*
	* @param	[in] pchFmt     变长参数
	* @return	无
	*
	**************************************************************/
	void Hint(const s8 *pchFormat, ...);
	void Hint2(const std::string strNote, const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Debug等级日志打印接口,带换行符
	*
	* @param	[in] pchFmt     变长参数
	* @return	无
	*
	**************************************************************/
	void Debug(const s8 *pchFormat, ...);
	void Debug2(const std::string strNote, const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Trace等级日志打印接口,带换行符
	*
	* @param	[in] pchFmt     变长参数
	* @return	无
	*
	**************************************************************/
	void Trace(const s8 *pchFormat, ...);
	void Trace2(const std::string strNote, const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Error等级日志打印接口,不带换行符
	*
	* @param	[in] pchFmt     变长参数
	* @return	无
	*
	**************************************************************/
	void ErrorNoln(const s8 *pchFormat, ...);
	void ErrorNoln2(const std::string strNote, const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Warning等级日志打印接口,不带换行符
	*
	* @param	[in] pchFmt     变长参数
	* @return	无
	*
	**************************************************************/
	void WarningNoln(const s8 *pchFormat, ...);
	void WarningNoln2(const std::string strNote,const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Hint等级日志打印接口,不带换行符
	*
	* @param	[in] pchFmt     变长参数
	* @return	无
	*
	**************************************************************/
	void HintNoln(const s8 *pchFormat, ...);
	void HintNoln2(const std::string strNote, const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Debug等级日志打印接口,不带换行符
	*
	* @param	[in] pchFmt     变长参数
	* @return	无
	*
	**************************************************************/
	void DebugNoln(const s8 *pchFormat, ...);
	void DebugNoln2(const std::string strNote, const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Trace等级日志打印接口,不带换行符
	*
	* @param	[in] pchFmt     变长参数
	* @return	无
	*
	**************************************************************/
	void TraceNoln(const s8 *pchFormat, ...);
	void TraceNoln2(const std::string strNote, const s8 *pchFormat, ...);

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
* @return	MT_SUCCESS 成功
*           MT_FAILED  失败
**************************************************************/
MTCBB_API u32 mtInitLogModule(std::string strCfgFilePath = "", BOOL32 bToFileLogServer = FALSE, std::string strCltTag = "");


/** ***********************************************************
* 
* @brief    注册日志模块
*
* @param	[in] emModule        日志模块ID
* @param	[in] pchModuleName   模块名称
* @param	[in] bOn             是否开启模块打印
* @return	MT_SUCCESS 成功
*           MT_FAILED  失败
**************************************************************/
MTCBB_API u32 mtRegLogModule(std::string strLogger, s8 *pchModuleName, BOOL32 bOn = FALSE);


/** ***********************************************************
* 
* @brief    Error等级日志打印接口,带换行符
*
* @param	[in] emModule   日志模块ID
* @param	[in] pchFmt     变长参数
* @return	无
*
**************************************************************/
MTCBB_API void MtLogErr(std::string strLogger, const s8 *pchFmt, ...);
MTCBB_API void MtLogErr2(std::string strLogger, std::string strNote, const s8 *pchFmt, ...);

/** ***********************************************************
* 
* @brief    Warning等级日志打印接口,带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFmt     变长参数
* @return	无
*
**************************************************************/
MTCBB_API void MtLogWarn(std::string strLogger, const s8 *pchFmt, ...);
MTCBB_API void MtLogWarn2(std::string strLogger, std::string strNote, const s8 *pchFmt, ...);

/** ***********************************************************
* 
* @brief    Hint等级日志打印接口,带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFmt     变长参数
* @return	无
*
**************************************************************/
MTCBB_API void MtLogHint(std::string strLogger, const s8 *pchFmt, ...);
MTCBB_API void MtLogHint2(std::string strLogger, std::string strNote, const s8 *pchFmt, ...);

/** ***********************************************************
* 
* @brief    Debug等级日志打印接口,带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFmt     变长参数
* @return	无
* @note     Debug等级打印不会输出到日志文件
*
**************************************************************/
MTCBB_API void MtLogDebug(std::string strLogger, const s8 *pchFmt, ...);	
MTCBB_API void MtLogDebug2(std::string strLogger, std::string strNote, const s8 *pchFmt, ...);

/** ***********************************************************
* 
* @brief    Trace等级日志打印接口,带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFmt     变长参数
* @return	无
* @note     Trace等级打印不会输出到日志文件
*
**************************************************************/
MTCBB_API void MtLogTrace(std::string strLogger, const s8 *pchFmt, ...);
MTCBB_API void MtLogTrace2(std::string strLogger, std::string strNote, const s8 *pchFmt, ...);


/** ***********************************************************
* 
* @brief    Error等级日志打印接口,不带换行符
*
* @param	[in] emModule   日志模块ID
* @param	[in] pchFmt     变长参数
* @return	无
*
**************************************************************/
MTCBB_API void MtLogErrNoln(std::string strLogger, const s8 *pchFmt, ...);
MTCBB_API void MtLogErrNoln2(std::string strLogger, std::string strNote, const s8 *pchFmt, ...);

/** ***********************************************************
* 
* @brief    Warning等级日志打印接口,不带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFmt     变长参数
* @return	无
*
**************************************************************/
MTCBB_API void MtLogWarnNoln(std::string strLogger, const s8 *pchFmt, ...);
MTCBB_API void MtLogWarnNoln2(std::string strLogger, std::string strNote, const s8 *pchFmt, ...);

/** ***********************************************************
* 
* @brief    Hint等级日志打印接口,不带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFmt     变长参数
* @return	无
*
**************************************************************/
MTCBB_API void MtLogHintNoln(std::string strLogger, const s8 *pchFmt, ...);
MTCBB_API void MtLogHintNoln2(std::string strLogger, std::string strNote, const s8 *pchFmt, ...);

/** ***********************************************************
* 
* @brief    Debug等级日志打印接口,不带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFmt     变长参数
* @return	无
* @note     Debug等级打印不会输出到日志文件
*
**************************************************************/
MTCBB_API void MtLogDebugNoln(std::string strLogger, const s8 *pchFmt, ...);	
MTCBB_API void MtLogDebugNoln2(std::string strLogger, std::string strNote, const s8 *pchFmt, ...);	

/** ***********************************************************
* 
* @brief    Trace等级日志打印接口,不带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFmt     变长参数
* @return	无
* @note     Trace等级打印不会输出到日志文件
*
**************************************************************/
MTCBB_API void MtLogTraceNoln(std::string strLogger, const s8 *pchFmt, ...);
MTCBB_API void MtLogTraceNoln2(std::string strLogger, std::string strNote, const s8 *pchFmt, ...);

/** ***********************************************************
* 
* @brief    设置文件日志开关
* 
* @param	[in] bEnable   日志内容是否写入日志文件
* @return	无
*
**************************************************************/
MTCBB_API void mtSetFileLogEnable(BOOL32 bEnable);

}


/** ***********************************************************
* 
* @brief    打印接口
* 
* @param	[in] pchFmt   要打印信息 变长参数
* @return	无
* @note     此打印接口不受调试命令控制
*
**************************************************************/
MTCBB_API void mtPrintf(const s8 *pchFmt, ...);
MTCBB_API void mtPrintf2(std::string strNote, const s8 *pchFmt, ...);

/** ***********************************************************
* 
* @brief    打印接口(不带时间信息)
* 
* @param	[in] pchFmt   要打印信息 变长参数
* @return	无
* @note     此打印接口不受调试命令控制
*
**************************************************************/
MTCBB_API void mtPrintfNoTime(const s8 *pchFmt, ...);
MTCBB_API void mtPrintfNoTime2(std::string strNote, const s8 *pchFmt, ...);

/** ***********************************************************
* 
* @brief    打印接口(结尾自动加上换行符)
* 
* @param	[in] pchFmt   要打印信息 变长参数
* @return	无
* @note     此打印接口不受调试命令控制
*
**************************************************************/
MTCBB_API void mtPrintfln(const s8 *pchFmt, ...);
MTCBB_API void mtPrintfln2(std::string strNote, const s8 *pchFmt, ...);

#endif  //_MTLOG_H_
































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
#ifndef _MTLOG_H_
#define _MTLOG_H_
#include "kdvtype.h"
#include "mtmacro.h"

/******** 日志枚举定义 *********************************************************/

/** 日志模块ID 增加模块再次添加对应模块ID */
enum EmMtLogModule
{
	MDL_BGN = 0,

	MDL_DRIVER,		           ///< 该模块ID专门给驱动组打印接口到日志使用
	MDL_SYSCTRL,	           ///< 系统控制子系统
	MDL_IM,			           ///< Im子系统
	MDL_REST,                  ///< REST子系统
	MDL_DSCLIENT,              ///< 数据共享客户端
	MDL_DSSERVER,              ///< 数据共享服务端
	MDL_CFG,                   ///< 配置管理
	MDL_MP,                    ///< 媒体处理组件 (mtmp)
	MDL_MTDEVICE,	           ///< 硬终端设备管理(mtdevice)
	MDL_MTMFGTEST,             ///< 硬终端生产测试模块	
	MDL_MTCONF,                ///< mtservice里的conf模块 
	MDL_MTPA,                  ///< mtpa模块 
	MDL_MTH323,                ///< mth323模块 
	MDL_MTMC,                  ///< mtmc模块 	
	MDL_MTDISPATCH,            ///<消息调度模块
	MDL_MTACCESS,              ///<终端客户端接入模块
	MDL_AGENT,                 ///<网管模块（mtagent）
	MDL_AGENTADP,              ///<网管适配模块（mtagentadp）
	MDL_MISC,		           ///< 小业务子系统
	MDL_MTVOD,		           ///< 点播系统
	MDL_UPGRADE,	           ///< 升级子系统
	MDL_MTMC,	           ///< 内置mc模块
	MDL_RECORD,                ///< 本地地址簿&呼叫记录
	MDL_MTSERVICE,             ///< mtservice模块
	MDL_MTAPI,                 ///< mtapi对外封装API模块
	MDL_MTAPI_BS,              ///< mtbaseapi终端baseapi模块
	MDL_MTAPI_VC,              ///< mtvcapi VideoConference视频会议控制模块
	MDL_MTAPI_IM,              ///< mtimapi即时通讯模块
	MDL_MTAPI_CM,              ///< mtcmapi ContactManager联系人管理模块
	MDL_MTAPI_MG,              ///< mtmgapi MeetingManager会议室管理模块
	MDL_MTAPI_VNC,             ///< mtvncapi PC虚拟桌面模块
	MDL_MTAPI_DC,              ///< mtdataconf 数据会议模块
	MDL_MTAPI_DIAGNOSE,        ///< mtdiagnoseapi 诊断模块
	MDL_RPCCLIENT,             ///<mtrpcclient模块
	MDL_RPCSERVER,             ///<mtrpcserver模块
	MDL_XMLRPC,                ///<xmlrpcc++模块
	MDL_SATSERVICE,            ///<sat service
	MDL_SATSTACK,              ///<sat stack
	MDL_DIAGNOSE,              ///<mtdiagnose模块
	MDL_MTUI,                  ///<mtui
	MDL_MTUI_CONF,             ///<点对点多点会议相关
	MDL_MTUI_CFG,              ///<配置相关
	MDL_MTUI_VOD,              ///<VOD相关
	MDL_MTUI_CAM,              ///<摄像机相关
	MDL_MTUI_MON,              ///<监控相关
	MDL_MTUI_REMOTE,           ///<遥控器
	MDL_MTUI_DG,               ///<统计诊断
	MDL_MTUI_CM,               ///<联系人(本地、共享、云端、呼叫记录)
	MDL_MTUI_MG,               ///<会议日程
	MDL_MTUI_IM,               ///<IM,通讯消息
	MDL_MTUI_DC,               ///<数据会议(数据协同)
	MDL_MTUI_NET,              ///<网络相关
	MDL_NETMAGAGE,             ///<网络组件模块
	MDL_MTCAPI_JNI,            ///<jni模块

	MDL_END
};

/** 日志打印等级 */
enum EmMtLogType
{
	emMtLogBgn,
	emMtLogError,   ///< 错误日志
	emMtLogWarn,    ///< 警告日志
	emMtLogHint,    ///< 提示日志
	emMtLogDebug,   ///< 调试日志
	emMtLogTrace,   ///< 临时/定时器打印
	emMtLogEnd
};

/*******************************************************************************/


namespace MTLOG {


/*---------------------------------------------------------------------------*/
/**
 * @class Class CMtLog
 * @brief 日志打印类
 * @author $Author$
 * @version $Revision$
 * @data $Date$
 * @note 需要使用日志接口的类可以继承自此类
 */
/*---------------------------------------------------------------------------*/
 class MTCBB_API CMtLog
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
	CMtLog(){}

	/** ***********************************************************
	* 
	* @brief    析构函数
	*
	* @param	无
	* @return	无
	*
	**************************************************************/
	~CMtLog(){}

public:
	/** ***********************************************************
	* 
	* @brief    Error等级日志打印接口,带换行符
	*
	* @param	[in] pchFmt     变长参数
	* @return	无
	*
	**************************************************************/
	void Error(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Warning等级日志打印接口,带换行符
	*
	* @param	[in] pchFmt     变长参数
	* @return	无
	*
	**************************************************************/
	void Warning(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Hint等级日志打印接口,带换行符
	*
	* @param	[in] pchFmt     变长参数
	* @return	无
	*
	**************************************************************/
	void Hint(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Debug等级日志打印接口,带换行符
	*
	* @param	[in] pchFmt     变长参数
	* @return	无
	*
	**************************************************************/
	void Debug(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Trace等级日志打印接口,带换行符
	*
	* @param	[in] pchFmt     变长参数
	* @return	无
	*
	**************************************************************/
	void Trace(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Error等级日志打印接口,不带换行符
	*
	* @param	[in] pchFmt     变长参数
	* @return	无
	*
	**************************************************************/
	void ErrorNoln(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Warning等级日志打印接口,不带换行符
	*
	* @param	[in] pchFmt     变长参数
	* @return	无
	*
	**************************************************************/
	void WarningNoln(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Hint等级日志打印接口,不带换行符
	*
	* @param	[in] pchFmt     变长参数
	* @return	无
	*
	**************************************************************/
	void HintNoln(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Debug等级日志打印接口,不带换行符
	*
	* @param	[in] pchFmt     变长参数
	* @return	无
	*
	**************************************************************/
	void DebugNoln(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Trace等级日志打印接口,不带换行符
	*
	* @param	[in] pchFmt     变长参数
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
	void SetLogMoudle(EmMtLogModule emMoudleID){ m_emMoudleID = emMoudleID; }

	/** ***********************************************************
	* 
	* @brief    获取所属日志模块ID
	*
	* @param	无
	* @return	所属日志模块ID
	*
	**************************************************************/
	EmMtLogModule GetModuleId(){ return m_emMoudleID; }

private:
	EmMtLogModule m_emMoudleID; ///< 类所属模块ID
};


/** ***********************************************************
* 
* @brief    初始化日志模块
*
* @param	[in] pszCfgFileFullPath        日志配置文件，utf8编码
* @return	MT_SUCCESS 成功
*           MT_FAILED  失败
**************************************************************/
MTCBB_API u32 mtInitLogModule(const s8* pszCfgFileFullPath = NULL);


/** ***********************************************************
* 
* @brief    注册日志模块
*
* @param	[in] emModule        日志模块ID
* @param	[in] pchModuleName   模块名称
* @param	[in] bOn             是否开启模块打印
* @return	MT_SUCCESS 成功
*           MT_FAILED  失败
**************************************************************/
MTCBB_API u32 mtRegLogModule(EmMtLogModule emModule, s8 *pchModuleName, BOOL32 bOn = FALSE);


/** ***********************************************************
* 
* @brief    Error等级日志打印接口,带换行符
*
* @param	[in] emModule   日志模块ID
* @param	[in] pchFmt     变长参数
* @return	无
*
**************************************************************/
MTCBB_API void MtLogErr(EmMtLogModule emModule, const s8 *pchFmt, ...);


/** ***********************************************************
* 
* @brief    Warning等级日志打印接口,带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFmt     变长参数
* @return	无
*
**************************************************************/
MTCBB_API void MtLogWarn(EmMtLogModule emModule, const s8 *pchFmt, ...);


/** ***********************************************************
* 
* @brief    Hint等级日志打印接口,带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFmt     变长参数
* @return	无
*
**************************************************************/
MTCBB_API void MtLogHint(EmMtLogModule emModule, const s8 *pchFmt, ...);


/** ***********************************************************
* 
* @brief    Debug等级日志打印接口,带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFmt     变长参数
* @return	无
* @note     Debug等级打印不会输出到日志文件
*
**************************************************************/
MTCBB_API void MtLogDebug(EmMtLogModule emModule, const s8 *pchFmt, ...);	


/** ***********************************************************
* 
* @brief    Trace等级日志打印接口,带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFmt     变长参数
* @return	无
* @note     Trace等级打印不会输出到日志文件
*
**************************************************************/
MTCBB_API void MtLogTrace(EmMtLogModule emModule, const s8 *pchFmt, ...);



/** ***********************************************************
* 
* @brief    Error等级日志打印接口,不带换行符
*
* @param	[in] emModule   日志模块ID
* @param	[in] pchFmt     变长参数
* @return	无
*
**************************************************************/
MTCBB_API void MtLogErrNoln(EmMtLogModule emModule, const s8 *pchFmt, ...);


/** ***********************************************************
* 
* @brief    Warning等级日志打印接口,不带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFmt     变长参数
* @return	无
*
**************************************************************/
MTCBB_API void MtLogWarnNoln(EmMtLogModule emModule, const s8 *pchFmt, ...);


/** ***********************************************************
* 
* @brief    Hint等级日志打印接口,不带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFmt     变长参数
* @return	无
*
**************************************************************/
MTCBB_API void MtLogHintNoln(EmMtLogModule emModule, const s8 *pchFmt, ...);


/** ***********************************************************
* 
* @brief    Debug等级日志打印接口,不带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFmt     变长参数
* @return	无
* @note     Debug等级打印不会输出到日志文件
*
**************************************************************/
MTCBB_API void MtLogDebugNoln(EmMtLogModule emModule, const s8 *pchFmt, ...);	


/** ***********************************************************
* 
* @brief    Trace等级日志打印接口,不带换行符
* 
* @param	[in] emModule   日志模块ID
* @param	[in] pchFmt     变长参数
* @return	无
* @note     Trace等级打印不会输出到日志文件
*
**************************************************************/
MTCBB_API void MtLogTraceNoln(EmMtLogModule emModule, const s8 *pchFmt, ...);

/** ***********************************************************
* 
* @brief    设置文件日志开关
* 
* @param	[in] bEnable   日志内容是否写入日志文件
* @return	无
*
**************************************************************/
MTCBB_API void mtSetFileLogEnable(BOOL32 bEnable);

}


/** ***********************************************************
* 
* @brief    打印接口
* 
* @param	[in] pchFmt   要打印信息 变长参数
* @return	无
* @note     此打印接口不受调试命令控制
*
**************************************************************/
MTCBB_API void mtPrintf(const s8 *pchFmt, ...);



/** ***********************************************************
* 
* @brief    打印接口(结尾自动加上换行符)
* 
* @param	[in] pchFmt   要打印信息 变长参数
* @return	无
* @note     此打印接口不受调试命令控制
*
**************************************************************/
MTCBB_API void mtPrintfln(const s8 *pchFmt, ...);


#endif  //_MTLOG_H_
#endif

