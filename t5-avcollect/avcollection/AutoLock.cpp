#include "StdAfx.h"
#include "AutoLock.h"


CAutoLock::CAutoLock(CSimpleLock *_pSLock)
:m_pSLock(_pSLock)
{
	if (_pSLock)
	{
#if 1
		_pSLock->lock();
#else
		_pSLock->trylock();
#endif
	}
}


CAutoLock::~CAutoLock(void)
{
	if (m_pSLock)
	{
		m_pSLock->unlock();
	}
}
