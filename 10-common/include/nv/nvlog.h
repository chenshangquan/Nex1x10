/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   �ն���־ģ��
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
 * @brief ��־��ӡ��
 * @author $Author$
 * @version $Revision$
 * @data $Date$
 * @note ��Ҫʹ����־�ӿڵ�����Լ̳��Դ���
 */
/*---------------------------------------------------------------------------*/
 class NVCBB_API CNvLog
{
public:	
	/** ***********************************************************
	* 
	* @brief    ���캯��
	*
	* @param	��
	* @return	��
	*
	**************************************************************/
	CNvLog(){}

	/** ***********************************************************
	* 
	* @brief    ��������
	*
	* @param	��
	* @return	��
	*
	**************************************************************/
	~CNvLog(){}

public:
	/** ***********************************************************
	* 
	* @brief    Error�ȼ���־��ӡ�ӿ�,�����з�
	*
	* @param	[in] pchFnv     �䳤����
	* @return	��
	*
	**************************************************************/
	void Error(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Warning�ȼ���־��ӡ�ӿ�,�����з�
	*
	* @param	[in] pchFnv     �䳤����
	* @return	��
	*
	**************************************************************/
	void Warning(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Hint�ȼ���־��ӡ�ӿ�,�����з�
	*
	* @param	[in] pchFnv     �䳤����
	* @return	��
	*
	**************************************************************/
	void Hint(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Debug�ȼ���־��ӡ�ӿ�,�����з�
	*
	* @param	[in] pchFnv     �䳤����
	* @return	��
	*
	**************************************************************/
	void Debug(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Trace�ȼ���־��ӡ�ӿ�,�����з�
	*
	* @param	[in] pchFnv     �䳤����
	* @return	��
	*
	**************************************************************/
	void Trace(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Error�ȼ���־��ӡ�ӿ�,�������з�
	*
	* @param	[in] pchFnv     �䳤����
	* @return	��
	*
	**************************************************************/
	void ErrorNoln(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Warning�ȼ���־��ӡ�ӿ�,�������з�
	*
	* @param	[in] pchFnv     �䳤����
	* @return	��
	*
	**************************************************************/
	void WarningNoln(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Hint�ȼ���־��ӡ�ӿ�,�������з�
	*
	* @param	[in] pchFnv     �䳤����
	* @return	��
	*
	**************************************************************/
	void HintNoln(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Debug�ȼ���־��ӡ�ӿ�,�������з�
	*
	* @param	[in] pchFnv     �䳤����
	* @return	��
	*
	**************************************************************/
	void DebugNoln(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Trace�ȼ���־��ӡ�ӿ�,�������з�
	*
	* @param	[in] pchFnv     �䳤����
	* @return	��
	*
	**************************************************************/
	void TraceNoln(const s8 *pchFormat, ...);

public:
	/** ***********************************************************
	* 
	* @brief    �趨��������־ģ��
	*
	* @param	[in] emModule  ��־ģ��ID
	* @return	��
	*
	**************************************************************/
	void SetLogMoudle(std::string strLogger){ m_strLogger = strLogger; }

	/** ***********************************************************
	* 
	* @brief    ��ȡ������־ģ��ID
	*
	* @param	��
	* @return	������־ģ��ID
	*
	**************************************************************/
	std::string GetModuleId(){ return m_strLogger; }

private:
	std::string m_strLogger; ///< ������ģ��ID
};


/** ***********************************************************
* 
* @brief    ��ʼ����־ģ��
*
* @param	[in] strCfgFilePath            ��־�����ļ���utf8����
* @param	[in] bToFileLogServer          TRUE �ļ���־�������־��������FALSE �ļ���־���������
* @return	NV_SUCCESS �ɹ�
*           NV_FAILED  ʧ��
**************************************************************/
NVCBB_API u32 nvInitLogModule(std::string strSvrIp = "", std::string strCfgFilePath = "", BOOL32 bToFileLogServer = FALSE, std::string strCltTag = "");

/** ***********************************************************
* 
* @brief    ��ʼ����־ģ��,��ѡ��������־�������Ķ˿�
*
* @param	[in] strCfgFilePath            ��־�����ļ���utf8����
* @param	[in] bToFileLogServer          TRUE �ļ���־�������־��������FALSE �ļ���־���������
* @return	NV_SUCCESS �ɹ�
*           NV_FAILED  ʧ��
**************************************************************/
NVCBB_API u32 nvInitLogModuleOfPort(std::string strSvrIp = "", std::string strCfgFilePath = "", BOOL32 bToFileLogServer = FALSE, std::string strCltTag = "", u32 dwPort = 10000);


/** ***********************************************************
* 
* @brief    ע����־ģ��
*
* @param	[in] emModule        ��־ģ��ID
* @param	[in] pchModuleName   ģ������
* @param	[in] bOn             �Ƿ���ģ���ӡ
* @return	NV_SUCCESS �ɹ�
*           NV_FAILED  ʧ��
**************************************************************/
NVCBB_API u32 nvRegLogModule(std::string strLogger, s8 *pchModuleName, BOOL32 bOn = FALSE);

/** ***********************************************************
* 
* @brief    �ſ���ӡ�ӿ�
* 
* @param	[in] strModule       ��־ģ��ID
* @return	��
* @note     �˴�ӡ�ӿڲ��ܵ����������
*
**************************************************************/
NVCBB_API void NvLogOn(std::string strModule = "");

/** ***********************************************************
* 
* @brief    �رմ�ӡ�ӿ�
* 
* @param	[in] strModule       ��־ģ��ID
* @return	��
* @note     �˴�ӡ�ӿڲ��ܵ����������
*
**************************************************************/
NVCBB_API void NvLogOff(std::string strModule = "");

/** ***********************************************************
* 
* @brief    �ſ�debug��ӡ�ӿ�
* 
* @param	[in] strModule       ��־ģ��ID
* @return	��
* @note     �˴�ӡ�ӿڲ��ܵ����������
*
**************************************************************/
NVCBB_API void NvDebugOn(std::string strModule = "");

/** ***********************************************************
* 
* @brief    �ر�debug��ӡ�ӿ�
* 
* @param	[in] strModule       ��־ģ��ID
* @return	��
* @note     �˴�ӡ�ӿڲ��ܵ����������
*
**************************************************************/
NVCBB_API void NvDebugOff(std::string strModule = "");

/** ***********************************************************
* 
* @brief    Error�ȼ���־��ӡ�ӿ�,�����з�
*
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFnv     �䳤����
* @return	��
*
**************************************************************/
NVCBB_API void NvLogErr(std::string strLogger, const s8 *pchFnv, ...);


/** ***********************************************************
* 
* @brief    Warning�ȼ���־��ӡ�ӿ�,�����з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFnv     �䳤����
* @return	��
*
**************************************************************/
NVCBB_API void NvLogWarn(std::string strLogger, const s8 *pchFnv, ...);


/** ***********************************************************
* 
* @brief    Hint�ȼ���־��ӡ�ӿ�,�����з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFnv     �䳤����
* @return	��
*
**************************************************************/
NVCBB_API void NvLogHint(std::string strLogger, const s8 *pchFnv, ...);


/** ***********************************************************
* 
* @brief    Debug�ȼ���־��ӡ�ӿ�,�����з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFnv     �䳤����
* @return	��
* @note     Debug�ȼ���ӡ�����������־�ļ�
*
**************************************************************/
NVCBB_API void NvLogDebug(std::string strLogger, const s8 *pchFnv, ...);	


/** ***********************************************************
* 
* @brief    Trace�ȼ���־��ӡ�ӿ�,�����з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFnv     �䳤����
* @return	��
* @note     Trace�ȼ���ӡ�����������־�ļ�
*
**************************************************************/
NVCBB_API void NvLogTrace(std::string strLogger, const s8 *pchFnv, ...);



/** ***********************************************************
* 
* @brief    Error�ȼ���־��ӡ�ӿ�,�������з�
*
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFnv     �䳤����
* @return	��
*
**************************************************************/
NVCBB_API void NvLogErrNoln(std::string strLogger, const s8 *pchFnv, ...);


/** ***********************************************************
* 
* @brief    Warning�ȼ���־��ӡ�ӿ�,�������з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFnv     �䳤����
* @return	��
*
**************************************************************/
NVCBB_API void NvLogWarnNoln(std::string strLogger, const s8 *pchFnv, ...);


/** ***********************************************************
* 
* @brief    Hint�ȼ���־��ӡ�ӿ�,�������з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFnv     �䳤����
* @return	��
*
**************************************************************/
NVCBB_API void NvLogHintNoln(std::string strLogger, const s8 *pchFnv, ...);


/** ***********************************************************
* 
* @brief    Debug�ȼ���־��ӡ�ӿ�,�������з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFnv     �䳤����
* @return	��
* @note     Debug�ȼ���ӡ�����������־�ļ�
*
**************************************************************/
NVCBB_API void NvLogDebugNoln(std::string strLogger, const s8 *pchFnv, ...);	


/** ***********************************************************
* 
* @brief    Trace�ȼ���־��ӡ�ӿ�,�������з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFnv     �䳤����
* @return	��
* @note     Trace�ȼ���ӡ�����������־�ļ�
*
**************************************************************/
NVCBB_API void NvLogTraceNoln(std::string strLogger, const s8 *pchFnv, ...);

/** ***********************************************************
* 
* @brief    �����ļ���־����
* 
* @param	[in] bEnable   ��־�����Ƿ�д����־�ļ�
* @return	��
*
**************************************************************/
NVCBB_API void nvSetFileLogEnable(BOOL32 bEnable);

}


/** ***********************************************************
* 
* @brief    ��ӡ�ӿ�
* 
* @param	[in] pchFnv   Ҫ��ӡ��Ϣ �䳤����
* @return	��
* @note     �˴�ӡ�ӿڲ��ܵ����������
*
**************************************************************/
NVCBB_API void nvPrintf(const s8 *pchFnv, ...);



/** ***********************************************************
* 
* @brief    ��ӡ�ӿ�(��β�Զ����ϻ��з�)
* 
* @param	[in] pchFnv   Ҫ��ӡ��Ϣ �䳤����
* @return	��
* @note     �˴�ӡ�ӿڲ��ܵ����������
*
**************************************************************/
NVCBB_API void nvPrintfln(const s8 *pchFnv, ...);


#endif  //_NVLOG_H_
































#if 0
/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   �ն���־ģ��
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

/******** ��־ö�ٶ��� *********************************************************/

/** ��־ģ��ID ����ģ���ٴ���Ӷ�Ӧģ��ID */
enum EmNvLogModule
{
	MDL_BGN = 0,

	MDL_DRIVER,		           ///< ��ģ��IDר�Ÿ��������ӡ�ӿڵ���־ʹ��
	MDL_SYSCTRL,	           ///< ϵͳ������ϵͳ
	MDL_IM,			           ///< Im��ϵͳ
	MDL_REST,                  ///< REST��ϵͳ
	MDL_DSCLIENT,              ///< ���ݹ���ͻ���
	MDL_DSSERVER,              ///< ���ݹ�������
	MDL_CFG,                   ///< ���ù���
	MDL_MP,                    ///< ý�崦����� (nvmp)
	MDL_NVDEVICE,	           ///< Ӳ�ն��豸����(nvdevice)
	MDL_NVMFGTEST,             ///< Ӳ�ն���������ģ��	
	MDL_NVCONF,                ///< nvservice���confģ�� 
	MDL_NVPA,                  ///< nvpaģ�� 
	MDL_NVH323,                ///< nvh323ģ�� 
	MDL_NVMC,                  ///< nvmcģ�� 	
	MDL_NVDISPATCH,            ///<��Ϣ����ģ��
	MDL_NVACCESS,              ///<�ն˿ͻ��˽���ģ��
	MDL_AGENT,                 ///<����ģ�飨nvagent��
	MDL_AGENTADP,              ///<��������ģ�飨nvagentadp��
	MDL_MISC,		           ///< Сҵ����ϵͳ
	MDL_NVVOD,		           ///< �㲥ϵͳ
	MDL_UPGRADE,	           ///< ������ϵͳ
	MDL_MCSERVICE,	           ///< ����mcģ��
	MDL_RECORD,                ///< ���ص�ַ��&���м�¼
	MDL_NVSERVICE,             ///< nvserviceģ��
	MDL_NVAPI,                 ///< nvapi�����װAPIģ��
	MDL_NVAPI_BS,              ///< nvbaseapi�ն�baseapiģ��
	MDL_NVAPI_VC,              ///< nvvcapi VideoConference��Ƶ�������ģ��
	MDL_NVAPI_IM,              ///< nvimapi��ʱͨѶģ��
	MDL_NVAPI_CM,              ///< nvcmapi ContactManager��ϵ�˹���ģ��
	MDL_NVAPI_MG,              ///< nvmgapi MeetingManager�����ҹ���ģ��
	MDL_NVAPI_VNC,             ///< nvvncapi PC��������ģ��
	MDL_NVAPI_DC,              ///< nvdataconf ���ݻ���ģ��
	MDL_NVAPI_DIAGNOSE,        ///< nvdiagnoseapi ���ģ��
	MDL_RPCCLIENT,             ///<nvrpcclientģ��
	MDL_RPCSERVER,             ///<nvrpcserverģ��
	MDL_XMLRPC,                ///<xmlrpcc++ģ��
	MDL_SATSERVICE,            ///<sat service
	MDL_SATSTACK,              ///<sat stack
	MDL_DIAGNOSE,              ///<nvdiagnoseģ��
	MDL_NVUI,                  ///<nvui
	MDL_NVUI_CONF,             ///<��Ե���������
	MDL_NVUI_CFG,              ///<�������
	MDL_NVUI_VOD,              ///<VOD���
	MDL_NVUI_CAM,              ///<��������
	MDL_NVUI_MON,              ///<������
	MDL_NVUI_REMOTE,           ///<ң����
	MDL_NVUI_DG,               ///<ͳ�����
	MDL_NVUI_CM,               ///<��ϵ��(���ء������ƶˡ����м�¼)
	MDL_NVUI_MG,               ///<�����ճ�
	MDL_NVUI_IM,               ///<IM,ͨѶ��Ϣ
	MDL_NVUI_DC,               ///<���ݻ���(����Эͬ)
	MDL_NVUI_NET,              ///<�������
	MDL_NETMAGAGE,             ///<�������ģ��
	MDL_NVCAPI_JNI,            ///<jniģ��

	MDL_END
};

/** ��־��ӡ�ȼ� */
enum EmNvLogType
{
	emNvLogBgn,
	emNvLogError,   ///< ������־
	emNvLogWarn,    ///< ������־
	emNvLogHint,    ///< ��ʾ��־
	emNvLogDebug,   ///< ������־
	emNvLogTrace,   ///< ��ʱ/��ʱ����ӡ
	emNvLogEnd
};

/*******************************************************************************/


namespace NVLOG {


/*---------------------------------------------------------------------------*/
/**
 * @class Class CNvLog
 * @brief ��־��ӡ��
 * @author $Author$
 * @version $Revision$
 * @data $Date$
 * @note ��Ҫʹ����־�ӿڵ�����Լ̳��Դ���
 */
/*---------------------------------------------------------------------------*/
 class NVCBB_API CNvLog
{
public:
	/** ***********************************************************
	* 
	* @brief    ���캯��
	*
	* @param	��
	* @return	��
	*
	**************************************************************/
	CNvLog(){}

	/** ***********************************************************
	* 
	* @brief    ��������
	*
	* @param	��
	* @return	��
	*
	**************************************************************/
	~CNvLog(){}

public:
	/** ***********************************************************
	* 
	* @brief    Error�ȼ���־��ӡ�ӿ�,�����з�
	*
	* @param	[in] pchFnv     �䳤����
	* @return	��
	*
	**************************************************************/
	void Error(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Warning�ȼ���־��ӡ�ӿ�,�����з�
	*
	* @param	[in] pchFnv     �䳤����
	* @return	��
	*
	**************************************************************/
	void Warning(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Hint�ȼ���־��ӡ�ӿ�,�����з�
	*
	* @param	[in] pchFnv     �䳤����
	* @return	��
	*
	**************************************************************/
	void Hint(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Debug�ȼ���־��ӡ�ӿ�,�����з�
	*
	* @param	[in] pchFnv     �䳤����
	* @return	��
	*
	**************************************************************/
	void Debug(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Trace�ȼ���־��ӡ�ӿ�,�����з�
	*
	* @param	[in] pchFnv     �䳤����
	* @return	��
	*
	**************************************************************/
	void Trace(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Error�ȼ���־��ӡ�ӿ�,�������з�
	*
	* @param	[in] pchFnv     �䳤����
	* @return	��
	*
	**************************************************************/
	void ErrorNoln(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Warning�ȼ���־��ӡ�ӿ�,�������з�
	*
	* @param	[in] pchFnv     �䳤����
	* @return	��
	*
	**************************************************************/
	void WarningNoln(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Hint�ȼ���־��ӡ�ӿ�,�������з�
	*
	* @param	[in] pchFnv     �䳤����
	* @return	��
	*
	**************************************************************/
	void HintNoln(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Debug�ȼ���־��ӡ�ӿ�,�������з�
	*
	* @param	[in] pchFnv     �䳤����
	* @return	��
	*
	**************************************************************/
	void DebugNoln(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Trace�ȼ���־��ӡ�ӿ�,�������з�
	*
	* @param	[in] pchFnv     �䳤����
	* @return	��
	*
	**************************************************************/
	void TraceNoln(const s8 *pchFormat, ...);

public:
	/** ***********************************************************
	* 
	* @brief    �趨��������־ģ��
	*
	* @param	[in] emModule  ��־ģ��ID
	* @return	��
	*
	**************************************************************/
	void SetLogMoudle(EmNvLogModule emMoudleID){ m_emMoudleID = emMoudleID; }

	/** ***********************************************************
	* 
	* @brief    ��ȡ������־ģ��ID
	*
	* @param	��
	* @return	������־ģ��ID
	*
	**************************************************************/
	EmNvLogModule GetModuleId(){ return m_emMoudleID; }

private:
	EmNvLogModule m_emMoudleID; ///< ������ģ��ID
};


/** ***********************************************************
* 
* @brief    ��ʼ����־ģ��
*
* @param	[in] pszCfgFileFullPath        ��־�����ļ���utf8����
* @return	NV_SUCCESS �ɹ�
*           NV_FAILED  ʧ��
**************************************************************/
NVCBB_API u32 nvInitLogModule(const s8* pszCfgFileFullPath = NULL);


/** ***********************************************************
* 
* @brief    ע����־ģ��
*
* @param	[in] emModule        ��־ģ��ID
* @param	[in] pchModuleName   ģ������
* @param	[in] bOn             �Ƿ���ģ���ӡ
* @return	NV_SUCCESS �ɹ�
*           NV_FAILED  ʧ��
**************************************************************/
NVCBB_API u32 nvRegLogModule(EmNvLogModule emModule, s8 *pchModuleName, BOOL32 bOn = FALSE);


/** ***********************************************************
* 
* @brief    Error�ȼ���־��ӡ�ӿ�,�����з�
*
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFnv     �䳤����
* @return	��
*
**************************************************************/
NVCBB_API void NvLogErr(EmNvLogModule emModule, const s8 *pchFnv, ...);


/** ***********************************************************
* 
* @brief    Warning�ȼ���־��ӡ�ӿ�,�����з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFnv     �䳤����
* @return	��
*
**************************************************************/
NVCBB_API void NvLogWarn(EmNvLogModule emModule, const s8 *pchFnv, ...);


/** ***********************************************************
* 
* @brief    Hint�ȼ���־��ӡ�ӿ�,�����з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFnv     �䳤����
* @return	��
*
**************************************************************/
NVCBB_API void NvLogHint(EmNvLogModule emModule, const s8 *pchFnv, ...);


/** ***********************************************************
* 
* @brief    Debug�ȼ���־��ӡ�ӿ�,�����з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFnv     �䳤����
* @return	��
* @note     Debug�ȼ���ӡ�����������־�ļ�
*
**************************************************************/
NVCBB_API void NvLogDebug(EmNvLogModule emModule, const s8 *pchFnv, ...);	


/** ***********************************************************
* 
* @brief    Trace�ȼ���־��ӡ�ӿ�,�����з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFnv     �䳤����
* @return	��
* @note     Trace�ȼ���ӡ�����������־�ļ�
*
**************************************************************/
NVCBB_API void NvLogTrace(EmNvLogModule emModule, const s8 *pchFnv, ...);



/** ***********************************************************
* 
* @brief    Error�ȼ���־��ӡ�ӿ�,�������з�
*
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFnv     �䳤����
* @return	��
*
**************************************************************/
NVCBB_API void NvLogErrNoln(EmNvLogModule emModule, const s8 *pchFnv, ...);


/** ***********************************************************
* 
* @brief    Warning�ȼ���־��ӡ�ӿ�,�������з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFnv     �䳤����
* @return	��
*
**************************************************************/
NVCBB_API void NvLogWarnNoln(EmNvLogModule emModule, const s8 *pchFnv, ...);


/** ***********************************************************
* 
* @brief    Hint�ȼ���־��ӡ�ӿ�,�������з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFnv     �䳤����
* @return	��
*
**************************************************************/
NVCBB_API void NvLogHintNoln(EmNvLogModule emModule, const s8 *pchFnv, ...);


/** ***********************************************************
* 
* @brief    Debug�ȼ���־��ӡ�ӿ�,�������з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFnv     �䳤����
* @return	��
* @note     Debug�ȼ���ӡ�����������־�ļ�
*
**************************************************************/
NVCBB_API void NvLogDebugNoln(EmNvLogModule emModule, const s8 *pchFnv, ...);	


/** ***********************************************************
* 
* @brief    Trace�ȼ���־��ӡ�ӿ�,�������з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFnv     �䳤����
* @return	��
* @note     Trace�ȼ���ӡ�����������־�ļ�
*
**************************************************************/
NVCBB_API void NvLogTraceNoln(EmNvLogModule emModule, const s8 *pchFnv, ...);

/** ***********************************************************
* 
* @brief    �����ļ���־����
* 
* @param	[in] bEnable   ��־�����Ƿ�д����־�ļ�
* @return	��
*
**************************************************************/
NVCBB_API void nvSetFileLogEnable(BOOL32 bEnable);

}


/** ***********************************************************
* 
* @brief    ��ӡ�ӿ�
* 
* @param	[in] pchFnv   Ҫ��ӡ��Ϣ �䳤����
* @return	��
* @note     �˴�ӡ�ӿڲ��ܵ����������
*
**************************************************************/
NVCBB_API void nvPrintf(const s8 *pchFnv, ...);



/** ***********************************************************
* 
* @brief    ��ӡ�ӿ�(��β�Զ����ϻ��з�)
* 
* @param	[in] pchFnv   Ҫ��ӡ��Ϣ �䳤����
* @return	��
* @note     �˴�ӡ�ӿڲ��ܵ����������
*
**************************************************************/
NVCBB_API void nvPrintfln(const s8 *pchFnv, ...);


#endif  //_NVLOG_H_
#endif

