#pragma once
class CSimpleLock
{
public:
	CSimpleLock(void);
	~CSimpleLock(void);
	void lock();
	void trylock();
	void unlock();
	
private:
	CRITICAL_SECTION 	m_CtiticalSection;
};

