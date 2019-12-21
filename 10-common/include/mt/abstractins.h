/**===========================================================================
 * @file    abstractins.h
 * @brief   提供抽象的实例接口
 * @author  ruiyigen
 * @date    20140707
 * @version 5.0 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
============================================================================*/
#ifndef _ABSTRACTINS_H_
#define _ABSTRACTINS_H_
#include "osp.h"
#include "mtmsg.h"
#include <deque>
#include "mtmacro.h"

#define MAX_RECENT_MSG_NUM 10
/**---------------------------------------------------------------------------
 * @class   CAbstractIns
 * @brief   抽象实例类
 * @author  ruiyigen
 * @version 5.0
 * @date    20140707
 ---------------------------------------------------------------------------*/
class MTCBB_API CAbstractIns : public CInstance
{
	friend class CAbstractMsgHandler;

private:
	virtual void InstanceEntry(CMessage *const pcMsg);
	virtual void DaemonInstanceEntry(CMessage *const pcMsg, CApp *pcApp);

	void         AddRecentMsg(std::string strMsgId);

protected:
	         CAbstractIns();
	virtual ~CAbstractIns();	

	virtual BOOL32 InsInit(u32 dwParam);
	virtual void   InsExit();
	virtual BOOL32 DaemonInsInit(u32 dwParam, CApp *pcApp);
	virtual void   DaemonInsExit();

	virtual BOOL32 MessageProc(mtmsg::CMtMsg *pcMtMsg, u32 dwSrcId, u32 dwSrcNode);
	virtual BOOL32 DaemonMessageProc(mtmsg::CMtMsg *pcMtMsg, CApp *pcApp, u32 dwSrcId, u32 dwSrcNode);

	virtual BOOL32 MessageProc(CMessage *const pcMsg);
	virtual BOOL32 DaemonMessageProc(CMessage *const pcMsg, CApp *pcApp);

public:
	void           ShowRecentMsgs();

private:
	enum EmInsState
	{
		emInsIdle    = 0,
		emInsWorking = 1
	};

	EmInsState              m_emInsState;
	CApp                    *m_pcApp;	
	std::deque<std::string> m_dqRecentMsgs; //记录每个实例最近处理的消息
};

/**----------------------------------------------------------------------
* CreateApp
* 
* @brief   创建APP
* 
* @param   [in] pcApp       CApp对象指针
* @param   [in] pszName     应用名称
* @param   [in] wAppId      应用号
* @param   [in] byPri       优先级
* @param   [in] wQueueSize  消息队列大小
* @param   [in] dwStackSize 堆栈大小
* @param   [in] dwParam     自定义参数
* @return  BOOL32 TRUE:成功处理， FALSE:处理失败
------------------------------------------------------------------------*/
MTCBB_API BOOL32 CreateApp(CApp *pcApp, const s8 *pszName, u16 wAppId, u8 byPri = 80, u16 wQueueSize = 80, u32 dwStackSize = 200<<10, u32 dwParam = 0);

/**----------------------------------------------------------------------
* QuitApp
* 
* @brief   应用退出
* 
* @param   [in] pcApp CApp对象指针
* @return  BOOL32 TRUE:成功处理， FALSE:处理失败
------------------------------------------------------------------------*/
MTCBB_API BOOL32 QuitApp(CApp *pcApp);

#endif