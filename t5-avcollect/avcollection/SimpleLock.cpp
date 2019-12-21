#include "StdAfx.h"
#include "SimpleLock.h"


CSimpleLock::CSimpleLock(void)
{
	InitializeCriticalSection(&m_CtiticalSection);
}


CSimpleLock::~CSimpleLock(void)
{
	DeleteCriticalSection(&m_CtiticalSection);
}

void CSimpleLock::lock()
{
	EnterCriticalSection(&m_CtiticalSection);
}

void CSimpleLock::trylock()
{
#if(_WIN32_WINNT >= 0x0400)
	TryEnterCriticalSection(&m_CtiticalSection);
#else
	EnterCriticalSection(&m_CtiticalSection);
#endif
}

void CSimpleLock::unlock()
{
	LeaveCriticalSection(&m_CtiticalSection);
}
