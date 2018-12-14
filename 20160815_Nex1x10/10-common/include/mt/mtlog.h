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
 * @brief ��־��ӡ��
 * @author $Author$
 * @version $Revision$
 * @data $Date$
 * @note ��Ҫʹ����־�ӿڵ�����Լ̳��Դ���
 */
/*---------------------------------------------------------------------------*/
 class MTCBB_API CMtLog
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
	CMtLog(){}

	/** ***********************************************************
	* 
	* @brief    ��������
	*
	* @param	��
	* @return	��
	*
	**************************************************************/
	~CMtLog(){}

public:
	/** ***********************************************************
	* 
	* @brief    Error�ȼ���־��ӡ�ӿ�,�����з�
	*
	* @param	[in] pchFmt     �䳤����
	* @return	��
	*
	**************************************************************/
	void Error(const s8 *pchFormat, ...);
	void Error2(const std::string strNote, const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Warning�ȼ���־��ӡ�ӿ�,�����з�
	*
	* @param	[in] pchFmt     �䳤����
	* @return	��
	*
	**************************************************************/
	void Warning(const s8 *pchFormat, ...);
	void Warning2(const std::string strNote, const s8 *pchFormat, ... );

	/** ***********************************************************
	* 
	* @brief    Hint�ȼ���־��ӡ�ӿ�,�����з�
	*
	* @param	[in] pchFmt     �䳤����
	* @return	��
	*
	**************************************************************/
	void Hint(const s8 *pchFormat, ...);
	void Hint2(const std::string strNote, const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Debug�ȼ���־��ӡ�ӿ�,�����з�
	*
	* @param	[in] pchFmt     �䳤����
	* @return	��
	*
	**************************************************************/
	void Debug(const s8 *pchFormat, ...);
	void Debug2(const std::string strNote, const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Trace�ȼ���־��ӡ�ӿ�,�����з�
	*
	* @param	[in] pchFmt     �䳤����
	* @return	��
	*
	**************************************************************/
	void Trace(const s8 *pchFormat, ...);
	void Trace2(const std::string strNote, const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Error�ȼ���־��ӡ�ӿ�,�������з�
	*
	* @param	[in] pchFmt     �䳤����
	* @return	��
	*
	**************************************************************/
	void ErrorNoln(const s8 *pchFormat, ...);
	void ErrorNoln2(const std::string strNote, const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Warning�ȼ���־��ӡ�ӿ�,�������з�
	*
	* @param	[in] pchFmt     �䳤����
	* @return	��
	*
	**************************************************************/
	void WarningNoln(const s8 *pchFormat, ...);
	void WarningNoln2(const std::string strNote,const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Hint�ȼ���־��ӡ�ӿ�,�������з�
	*
	* @param	[in] pchFmt     �䳤����
	* @return	��
	*
	**************************************************************/
	void HintNoln(const s8 *pchFormat, ...);
	void HintNoln2(const std::string strNote, const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Debug�ȼ���־��ӡ�ӿ�,�������з�
	*
	* @param	[in] pchFmt     �䳤����
	* @return	��
	*
	**************************************************************/
	void DebugNoln(const s8 *pchFormat, ...);
	void DebugNoln2(const std::string strNote, const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Trace�ȼ���־��ӡ�ӿ�,�������з�
	*
	* @param	[in] pchFmt     �䳤����
	* @return	��
	*
	**************************************************************/
	void TraceNoln(const s8 *pchFormat, ...);
	void TraceNoln2(const std::string strNote, const s8 *pchFormat, ...);

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
* @return	MT_SUCCESS �ɹ�
*           MT_FAILED  ʧ��
**************************************************************/
MTCBB_API u32 mtInitLogModule(std::string strCfgFilePath = "", BOOL32 bToFileLogServer = FALSE, std::string strCltTag = "");


/** ***********************************************************
* 
* @brief    ע����־ģ��
*
* @param	[in] emModule        ��־ģ��ID
* @param	[in] pchModuleName   ģ������
* @param	[in] bOn             �Ƿ���ģ���ӡ
* @return	MT_SUCCESS �ɹ�
*           MT_FAILED  ʧ��
**************************************************************/
MTCBB_API u32 mtRegLogModule(std::string strLogger, s8 *pchModuleName, BOOL32 bOn = FALSE);


/** ***********************************************************
* 
* @brief    Error�ȼ���־��ӡ�ӿ�,�����з�
*
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFmt     �䳤����
* @return	��
*
**************************************************************/
MTCBB_API void MtLogErr(std::string strLogger, const s8 *pchFmt, ...);
MTCBB_API void MtLogErr2(std::string strLogger, std::string strNote, const s8 *pchFmt, ...);

/** ***********************************************************
* 
* @brief    Warning�ȼ���־��ӡ�ӿ�,�����з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFmt     �䳤����
* @return	��
*
**************************************************************/
MTCBB_API void MtLogWarn(std::string strLogger, const s8 *pchFmt, ...);
MTCBB_API void MtLogWarn2(std::string strLogger, std::string strNote, const s8 *pchFmt, ...);

/** ***********************************************************
* 
* @brief    Hint�ȼ���־��ӡ�ӿ�,�����з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFmt     �䳤����
* @return	��
*
**************************************************************/
MTCBB_API void MtLogHint(std::string strLogger, const s8 *pchFmt, ...);
MTCBB_API void MtLogHint2(std::string strLogger, std::string strNote, const s8 *pchFmt, ...);

/** ***********************************************************
* 
* @brief    Debug�ȼ���־��ӡ�ӿ�,�����з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFmt     �䳤����
* @return	��
* @note     Debug�ȼ���ӡ�����������־�ļ�
*
**************************************************************/
MTCBB_API void MtLogDebug(std::string strLogger, const s8 *pchFmt, ...);	
MTCBB_API void MtLogDebug2(std::string strLogger, std::string strNote, const s8 *pchFmt, ...);

/** ***********************************************************
* 
* @brief    Trace�ȼ���־��ӡ�ӿ�,�����з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFmt     �䳤����
* @return	��
* @note     Trace�ȼ���ӡ�����������־�ļ�
*
**************************************************************/
MTCBB_API void MtLogTrace(std::string strLogger, const s8 *pchFmt, ...);
MTCBB_API void MtLogTrace2(std::string strLogger, std::string strNote, const s8 *pchFmt, ...);


/** ***********************************************************
* 
* @brief    Error�ȼ���־��ӡ�ӿ�,�������з�
*
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFmt     �䳤����
* @return	��
*
**************************************************************/
MTCBB_API void MtLogErrNoln(std::string strLogger, const s8 *pchFmt, ...);
MTCBB_API void MtLogErrNoln2(std::string strLogger, std::string strNote, const s8 *pchFmt, ...);

/** ***********************************************************
* 
* @brief    Warning�ȼ���־��ӡ�ӿ�,�������з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFmt     �䳤����
* @return	��
*
**************************************************************/
MTCBB_API void MtLogWarnNoln(std::string strLogger, const s8 *pchFmt, ...);
MTCBB_API void MtLogWarnNoln2(std::string strLogger, std::string strNote, const s8 *pchFmt, ...);

/** ***********************************************************
* 
* @brief    Hint�ȼ���־��ӡ�ӿ�,�������з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFmt     �䳤����
* @return	��
*
**************************************************************/
MTCBB_API void MtLogHintNoln(std::string strLogger, const s8 *pchFmt, ...);
MTCBB_API void MtLogHintNoln2(std::string strLogger, std::string strNote, const s8 *pchFmt, ...);

/** ***********************************************************
* 
* @brief    Debug�ȼ���־��ӡ�ӿ�,�������з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFmt     �䳤����
* @return	��
* @note     Debug�ȼ���ӡ�����������־�ļ�
*
**************************************************************/
MTCBB_API void MtLogDebugNoln(std::string strLogger, const s8 *pchFmt, ...);	
MTCBB_API void MtLogDebugNoln2(std::string strLogger, std::string strNote, const s8 *pchFmt, ...);	

/** ***********************************************************
* 
* @brief    Trace�ȼ���־��ӡ�ӿ�,�������з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFmt     �䳤����
* @return	��
* @note     Trace�ȼ���ӡ�����������־�ļ�
*
**************************************************************/
MTCBB_API void MtLogTraceNoln(std::string strLogger, const s8 *pchFmt, ...);
MTCBB_API void MtLogTraceNoln2(std::string strLogger, std::string strNote, const s8 *pchFmt, ...);

/** ***********************************************************
* 
* @brief    �����ļ���־����
* 
* @param	[in] bEnable   ��־�����Ƿ�д����־�ļ�
* @return	��
*
**************************************************************/
MTCBB_API void mtSetFileLogEnable(BOOL32 bEnable);

}


/** ***********************************************************
* 
* @brief    ��ӡ�ӿ�
* 
* @param	[in] pchFmt   Ҫ��ӡ��Ϣ �䳤����
* @return	��
* @note     �˴�ӡ�ӿڲ��ܵ����������
*
**************************************************************/
MTCBB_API void mtPrintf(const s8 *pchFmt, ...);
MTCBB_API void mtPrintf2(std::string strNote, const s8 *pchFmt, ...);

/** ***********************************************************
* 
* @brief    ��ӡ�ӿ�(����ʱ����Ϣ)
* 
* @param	[in] pchFmt   Ҫ��ӡ��Ϣ �䳤����
* @return	��
* @note     �˴�ӡ�ӿڲ��ܵ����������
*
**************************************************************/
MTCBB_API void mtPrintfNoTime(const s8 *pchFmt, ...);
MTCBB_API void mtPrintfNoTime2(std::string strNote, const s8 *pchFmt, ...);

/** ***********************************************************
* 
* @brief    ��ӡ�ӿ�(��β�Զ����ϻ��з�)
* 
* @param	[in] pchFmt   Ҫ��ӡ��Ϣ �䳤����
* @return	��
* @note     �˴�ӡ�ӿڲ��ܵ����������
*
**************************************************************/
MTCBB_API void mtPrintfln(const s8 *pchFmt, ...);
MTCBB_API void mtPrintfln2(std::string strNote, const s8 *pchFmt, ...);

#endif  //_MTLOG_H_
































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
#ifndef _MTLOG_H_
#define _MTLOG_H_
#include "kdvtype.h"
#include "mtmacro.h"

/******** ��־ö�ٶ��� *********************************************************/

/** ��־ģ��ID ����ģ���ٴ���Ӷ�Ӧģ��ID */
enum EmMtLogModule
{
	MDL_BGN = 0,

	MDL_DRIVER,		           ///< ��ģ��IDר�Ÿ��������ӡ�ӿڵ���־ʹ��
	MDL_SYSCTRL,	           ///< ϵͳ������ϵͳ
	MDL_IM,			           ///< Im��ϵͳ
	MDL_REST,                  ///< REST��ϵͳ
	MDL_DSCLIENT,              ///< ���ݹ���ͻ���
	MDL_DSSERVER,              ///< ���ݹ�������
	MDL_CFG,                   ///< ���ù���
	MDL_MP,                    ///< ý�崦����� (mtmp)
	MDL_MTDEVICE,	           ///< Ӳ�ն��豸����(mtdevice)
	MDL_MTMFGTEST,             ///< Ӳ�ն���������ģ��	
	MDL_MTCONF,                ///< mtservice���confģ�� 
	MDL_MTPA,                  ///< mtpaģ�� 
	MDL_MTH323,                ///< mth323ģ�� 
	MDL_MTMC,                  ///< mtmcģ�� 	
	MDL_MTDISPATCH,            ///<��Ϣ����ģ��
	MDL_MTACCESS,              ///<�ն˿ͻ��˽���ģ��
	MDL_AGENT,                 ///<����ģ�飨mtagent��
	MDL_AGENTADP,              ///<��������ģ�飨mtagentadp��
	MDL_MISC,		           ///< Сҵ����ϵͳ
	MDL_MTVOD,		           ///< �㲥ϵͳ
	MDL_UPGRADE,	           ///< ������ϵͳ
	MDL_MTMC,	           ///< ����mcģ��
	MDL_RECORD,                ///< ���ص�ַ��&���м�¼
	MDL_MTSERVICE,             ///< mtserviceģ��
	MDL_MTAPI,                 ///< mtapi�����װAPIģ��
	MDL_MTAPI_BS,              ///< mtbaseapi�ն�baseapiģ��
	MDL_MTAPI_VC,              ///< mtvcapi VideoConference��Ƶ�������ģ��
	MDL_MTAPI_IM,              ///< mtimapi��ʱͨѶģ��
	MDL_MTAPI_CM,              ///< mtcmapi ContactManager��ϵ�˹���ģ��
	MDL_MTAPI_MG,              ///< mtmgapi MeetingManager�����ҹ���ģ��
	MDL_MTAPI_VNC,             ///< mtvncapi PC��������ģ��
	MDL_MTAPI_DC,              ///< mtdataconf ���ݻ���ģ��
	MDL_MTAPI_DIAGNOSE,        ///< mtdiagnoseapi ���ģ��
	MDL_RPCCLIENT,             ///<mtrpcclientģ��
	MDL_RPCSERVER,             ///<mtrpcserverģ��
	MDL_XMLRPC,                ///<xmlrpcc++ģ��
	MDL_SATSERVICE,            ///<sat service
	MDL_SATSTACK,              ///<sat stack
	MDL_DIAGNOSE,              ///<mtdiagnoseģ��
	MDL_MTUI,                  ///<mtui
	MDL_MTUI_CONF,             ///<��Ե���������
	MDL_MTUI_CFG,              ///<�������
	MDL_MTUI_VOD,              ///<VOD���
	MDL_MTUI_CAM,              ///<��������
	MDL_MTUI_MON,              ///<������
	MDL_MTUI_REMOTE,           ///<ң����
	MDL_MTUI_DG,               ///<ͳ�����
	MDL_MTUI_CM,               ///<��ϵ��(���ء������ƶˡ����м�¼)
	MDL_MTUI_MG,               ///<�����ճ�
	MDL_MTUI_IM,               ///<IM,ͨѶ��Ϣ
	MDL_MTUI_DC,               ///<���ݻ���(����Эͬ)
	MDL_MTUI_NET,              ///<�������
	MDL_NETMAGAGE,             ///<�������ģ��
	MDL_MTCAPI_JNI,            ///<jniģ��

	MDL_END
};

/** ��־��ӡ�ȼ� */
enum EmMtLogType
{
	emMtLogBgn,
	emMtLogError,   ///< ������־
	emMtLogWarn,    ///< ������־
	emMtLogHint,    ///< ��ʾ��־
	emMtLogDebug,   ///< ������־
	emMtLogTrace,   ///< ��ʱ/��ʱ����ӡ
	emMtLogEnd
};

/*******************************************************************************/


namespace MTLOG {


/*---------------------------------------------------------------------------*/
/**
 * @class Class CMtLog
 * @brief ��־��ӡ��
 * @author $Author$
 * @version $Revision$
 * @data $Date$
 * @note ��Ҫʹ����־�ӿڵ�����Լ̳��Դ���
 */
/*---------------------------------------------------------------------------*/
 class MTCBB_API CMtLog
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
	CMtLog(){}

	/** ***********************************************************
	* 
	* @brief    ��������
	*
	* @param	��
	* @return	��
	*
	**************************************************************/
	~CMtLog(){}

public:
	/** ***********************************************************
	* 
	* @brief    Error�ȼ���־��ӡ�ӿ�,�����з�
	*
	* @param	[in] pchFmt     �䳤����
	* @return	��
	*
	**************************************************************/
	void Error(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Warning�ȼ���־��ӡ�ӿ�,�����з�
	*
	* @param	[in] pchFmt     �䳤����
	* @return	��
	*
	**************************************************************/
	void Warning(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Hint�ȼ���־��ӡ�ӿ�,�����з�
	*
	* @param	[in] pchFmt     �䳤����
	* @return	��
	*
	**************************************************************/
	void Hint(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Debug�ȼ���־��ӡ�ӿ�,�����з�
	*
	* @param	[in] pchFmt     �䳤����
	* @return	��
	*
	**************************************************************/
	void Debug(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Trace�ȼ���־��ӡ�ӿ�,�����з�
	*
	* @param	[in] pchFmt     �䳤����
	* @return	��
	*
	**************************************************************/
	void Trace(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Error�ȼ���־��ӡ�ӿ�,�������з�
	*
	* @param	[in] pchFmt     �䳤����
	* @return	��
	*
	**************************************************************/
	void ErrorNoln(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Warning�ȼ���־��ӡ�ӿ�,�������з�
	*
	* @param	[in] pchFmt     �䳤����
	* @return	��
	*
	**************************************************************/
	void WarningNoln(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Hint�ȼ���־��ӡ�ӿ�,�������з�
	*
	* @param	[in] pchFmt     �䳤����
	* @return	��
	*
	**************************************************************/
	void HintNoln(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Debug�ȼ���־��ӡ�ӿ�,�������з�
	*
	* @param	[in] pchFmt     �䳤����
	* @return	��
	*
	**************************************************************/
	void DebugNoln(const s8 *pchFormat, ...);

	/** ***********************************************************
	* 
	* @brief    Trace�ȼ���־��ӡ�ӿ�,�������з�
	*
	* @param	[in] pchFmt     �䳤����
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
	void SetLogMoudle(EmMtLogModule emMoudleID){ m_emMoudleID = emMoudleID; }

	/** ***********************************************************
	* 
	* @brief    ��ȡ������־ģ��ID
	*
	* @param	��
	* @return	������־ģ��ID
	*
	**************************************************************/
	EmMtLogModule GetModuleId(){ return m_emMoudleID; }

private:
	EmMtLogModule m_emMoudleID; ///< ������ģ��ID
};


/** ***********************************************************
* 
* @brief    ��ʼ����־ģ��
*
* @param	[in] pszCfgFileFullPath        ��־�����ļ���utf8����
* @return	MT_SUCCESS �ɹ�
*           MT_FAILED  ʧ��
**************************************************************/
MTCBB_API u32 mtInitLogModule(const s8* pszCfgFileFullPath = NULL);


/** ***********************************************************
* 
* @brief    ע����־ģ��
*
* @param	[in] emModule        ��־ģ��ID
* @param	[in] pchModuleName   ģ������
* @param	[in] bOn             �Ƿ���ģ���ӡ
* @return	MT_SUCCESS �ɹ�
*           MT_FAILED  ʧ��
**************************************************************/
MTCBB_API u32 mtRegLogModule(EmMtLogModule emModule, s8 *pchModuleName, BOOL32 bOn = FALSE);


/** ***********************************************************
* 
* @brief    Error�ȼ���־��ӡ�ӿ�,�����з�
*
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFmt     �䳤����
* @return	��
*
**************************************************************/
MTCBB_API void MtLogErr(EmMtLogModule emModule, const s8 *pchFmt, ...);


/** ***********************************************************
* 
* @brief    Warning�ȼ���־��ӡ�ӿ�,�����з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFmt     �䳤����
* @return	��
*
**************************************************************/
MTCBB_API void MtLogWarn(EmMtLogModule emModule, const s8 *pchFmt, ...);


/** ***********************************************************
* 
* @brief    Hint�ȼ���־��ӡ�ӿ�,�����з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFmt     �䳤����
* @return	��
*
**************************************************************/
MTCBB_API void MtLogHint(EmMtLogModule emModule, const s8 *pchFmt, ...);


/** ***********************************************************
* 
* @brief    Debug�ȼ���־��ӡ�ӿ�,�����з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFmt     �䳤����
* @return	��
* @note     Debug�ȼ���ӡ�����������־�ļ�
*
**************************************************************/
MTCBB_API void MtLogDebug(EmMtLogModule emModule, const s8 *pchFmt, ...);	


/** ***********************************************************
* 
* @brief    Trace�ȼ���־��ӡ�ӿ�,�����з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFmt     �䳤����
* @return	��
* @note     Trace�ȼ���ӡ�����������־�ļ�
*
**************************************************************/
MTCBB_API void MtLogTrace(EmMtLogModule emModule, const s8 *pchFmt, ...);



/** ***********************************************************
* 
* @brief    Error�ȼ���־��ӡ�ӿ�,�������з�
*
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFmt     �䳤����
* @return	��
*
**************************************************************/
MTCBB_API void MtLogErrNoln(EmMtLogModule emModule, const s8 *pchFmt, ...);


/** ***********************************************************
* 
* @brief    Warning�ȼ���־��ӡ�ӿ�,�������з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFmt     �䳤����
* @return	��
*
**************************************************************/
MTCBB_API void MtLogWarnNoln(EmMtLogModule emModule, const s8 *pchFmt, ...);


/** ***********************************************************
* 
* @brief    Hint�ȼ���־��ӡ�ӿ�,�������з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFmt     �䳤����
* @return	��
*
**************************************************************/
MTCBB_API void MtLogHintNoln(EmMtLogModule emModule, const s8 *pchFmt, ...);


/** ***********************************************************
* 
* @brief    Debug�ȼ���־��ӡ�ӿ�,�������з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFmt     �䳤����
* @return	��
* @note     Debug�ȼ���ӡ�����������־�ļ�
*
**************************************************************/
MTCBB_API void MtLogDebugNoln(EmMtLogModule emModule, const s8 *pchFmt, ...);	


/** ***********************************************************
* 
* @brief    Trace�ȼ���־��ӡ�ӿ�,�������з�
* 
* @param	[in] emModule   ��־ģ��ID
* @param	[in] pchFmt     �䳤����
* @return	��
* @note     Trace�ȼ���ӡ�����������־�ļ�
*
**************************************************************/
MTCBB_API void MtLogTraceNoln(EmMtLogModule emModule, const s8 *pchFmt, ...);

/** ***********************************************************
* 
* @brief    �����ļ���־����
* 
* @param	[in] bEnable   ��־�����Ƿ�д����־�ļ�
* @return	��
*
**************************************************************/
MTCBB_API void mtSetFileLogEnable(BOOL32 bEnable);

}


/** ***********************************************************
* 
* @brief    ��ӡ�ӿ�
* 
* @param	[in] pchFmt   Ҫ��ӡ��Ϣ �䳤����
* @return	��
* @note     �˴�ӡ�ӿڲ��ܵ����������
*
**************************************************************/
MTCBB_API void mtPrintf(const s8 *pchFmt, ...);



/** ***********************************************************
* 
* @brief    ��ӡ�ӿ�(��β�Զ����ϻ��з�)
* 
* @param	[in] pchFmt   Ҫ��ӡ��Ϣ �䳤����
* @return	��
* @note     �˴�ӡ�ӿڲ��ܵ����������
*
**************************************************************/
MTCBB_API void mtPrintfln(const s8 *pchFmt, ...);


#endif  //_MTLOG_H_
#endif

