#include "osp.h"

NVCBB_API void intRpcClinet( u32 dwPort );

class CRpcClientMutexCtrl
{
public:
	CRpcClientMutexCtrl();

	~CRpcClientMutexCtrl();
};

class CRpcClientLock
{
public:
	CRpcClientLock(SEMHANDLE &semMutex)
	{
		m_psemMutex = NULL;
		if (semMutex != NULL)
		{
			m_psemMutex = &semMutex;
			OspSemTake(*m_psemMutex);
		}
	}

	~CRpcClientLock()
	{
		if (m_psemMutex != NULL)
		{
			OspSemGive(*m_psemMutex);
		}
	}

private:
	SEMHANDLE *m_psemMutex;
};

extern SEMHANDLE g_semRpcClientMutex;