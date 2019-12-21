#pragma once
#include "SimpleLock.h"
class CAutoLock
{
public:
	//CAutoLock(void);
	CAutoLock(CSimpleLock *_pSLock);
	~CAutoLock(void);
private:
	CSimpleLock *m_pSLock;
};

