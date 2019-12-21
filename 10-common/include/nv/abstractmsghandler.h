#ifndef _ABSTRACTMSGHANDLER_H_
#define _ABSTRACTMSGHANDLER_H_
#include <map>
#include "kdvtype.h"
#include "abstractins.h"
#include "nvmsg.h"
#include "nvmacro.h"

class CAbstractMsgHandler;
typedef BOOL32 (CAbstractMsgHandler::*PFMsgFunc)(nvmsg::CNvMsg *pcNvMsg, u32 dwSrcId, u32 dwSrcNode);
typedef BOOL32 (CAbstractMsgHandler::*PFOspMsgFunc)(CMessage *const pcMsg);

class NVCBB_API CAbstractMsgHandler
{	
protected:
	CAbstractMsgHandler(CAbstractIns *pcOspIns = NULL);	

	BOOL32 RegMsgFunc(std::string strMsgId, PFMsgFunc pfMsgFunc);
	BOOL32 UnRegMsgFunc(std::string strMsgId);
	BOOL32 IsMsgFuncReg(std::string strMsgId);
	void   ClearMsgFunc();	

	BOOL32 RegOspMsgFunc(u32 dwMsgId, PFOspMsgFunc pfMsgFunc);
	BOOL32 UnRegOspMsgFunc(u32 dwMsgId);
	BOOL32 IsOspMsgFuncReg(u32 dwMsgId);
	void   ClearOspMsgFunc();

	void   SetTimer(u32 dwTimerId, u32 dwMS, u32 dwParam = 0);
	void   KillTimer(u32 dwTimerId);

public:
	virtual ~CAbstractMsgHandler();

	void SetOspIns(CAbstractIns *pcOspIns)
	{
		m_pcOspIns = pcOspIns;
	}

	virtual BOOL32 HandleMsg(nvmsg::CNvMsg *pcNvMsg, u32 dwSrcId, u32 dwSrcNode);
	virtual BOOL32 HandleMsg(CMessage *const pcMsg);
	
protected:
	CAbstractIns                        *m_pcOspIns;
	std::map<std::string, PFMsgFunc>    m_mapMsgFunc;
	std::map<u32, PFOspMsgFunc>         m_mapOspMsgFunc;
};

#endif