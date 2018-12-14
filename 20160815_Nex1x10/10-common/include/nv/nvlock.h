/**===========================================================================
 * @file    $Id$
 * @brief   ×Ô¶¯Ëø·â×°
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/
#ifndef _I_NVLOCK_H_
#define _I_NVLOCK_H_

#include  "osp.h"

class COspLock
{
	SEMHANDLE m_hSem;
public:
	COspLock()
	{
		::OspSemBCreate(&m_hSem);
	}

	virtual ~COspLock()
	{
		::OspSemDelete(m_hSem);
	}
	
	BOOL32 Lock( u32 dwTimeout = INFINITE )
	{
		return ::OspSemTakeByTime(m_hSem, dwTimeout);
	}

	BOOL32 UnLock()
	{
		return ::OspSemGive(m_hSem);
	}
};

class CAutoLock
{
public:
	CAutoLock( COspLock* pcLock, u32 dwTimeOut = INFINITE ) : m_pcOspLock( pcLock )
	{
		if ( NULL != m_pcOspLock )
		{
			m_pcOspLock->Lock( dwTimeOut );
		}
	}
	virtual ~CAutoLock()
	{
		if ( NULL != m_pcOspLock )
		{
			m_pcOspLock->UnLock();
		}
	}
private:
	COspLock* m_pcOspLock;
};

#endif;//_I_NVLOCK_H_