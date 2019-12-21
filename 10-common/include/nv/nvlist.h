#ifndef _h_nvlist_h__
#define _h_nvlist_h__
#include "osp.h"
#include <new>

template <class Type> class CNvList;

template<class Type>
class CNvListData
{
private:
	CNvListData*	m_ptNext;    //指向下一个Block
	CNvListData*	m_ptPre;     //指向前一个Block， 此指针仅在删除使用列表时使用
	Type			m_tData;

	friend  class CNvList<Type>;

public:
	static u32		m_dwDataOffset;

public:
	CNvListData():m_ptNext(NULL), m_ptPre(NULL)	{}
	Type*			Data()	{ return &m_tData; }
	CNvListData*	Next()	{ return m_ptNext; }	

	
};
 

template<class Type>
u32 CNvListData<Type>::m_dwDataOffset = (size_t)&(((CNvListData *)0)->m_tData);


template<class Type>
class CNvList
{
public:
	typedef CNvListData<Type>	ListData;
	typedef CNvListData<Type>*	ListDataPtr;

public:
    CNvList()
		:m_dwFreeBlockNum(0)
		,m_pBuff(NULL)
		,m_ptFreeHead(NULL)
		,m_ptUsedHead(NULL)
		,m_dwBuffSize(0)
		,m_dwTotalNum(0)
	{
	}
    ~CNvList()	{ Destroy(); }
	
    BOOL32 Create(u32 dwDataNum);
    void Destroy();
    
	Type*	AllocNode();
	Type*	GetDataByIndex(u32 wIndex);		//根据物理索引获取
	Type*	Head()	{	return m_ptUsedHead == NULL ? NULL : m_ptUsedHead->Data(); }
	Type*	Next(Type* ptData);

	//释放数据块链
	u32 FreeBuff(Type* itor);	
	
    u32 GetFreeBlocks()		{ return m_dwFreeBlockNum; }
    u32 GetMinFreeBlocks()	{ return m_dwMinFreeBlocks; }
	u32 GetTotalNum()		{ return m_dwTotalNum; }
	void Show()	{OspPrintf(TRUE, FALSE, "\n  CNvList::m_dwTotalNum:%d, m_dwFreeBlockNum:%d\n", m_dwTotalNum, m_dwFreeBlockNum);}
	
protected:
	
private:    
    void*   m_pBuff;                //整个Buff的指针
	
    u32     m_dwFreeBlockNum;       //空闲块的数目
    ListDataPtr m_ptFreeHead;		//空闲块链表
	ListDataPtr m_ptUsedHead;		//使用块链表

    u32     m_dwBuffSize;           //实际分配缓冲大小
    u32     m_dwTotalNum;           //实际使用总块数
	u32     m_dwMinFreeBlocks;      //最小空闲数
    
};


template<class Type>
BOOL32 CNvList<Type>::Create(u32 dwDataNum)
{
    if (0 == dwDataNum)
    {
        return FALSE;
    }

    //判断是否需要重新分配
    if (dwDataNum > m_dwTotalNum) 
    {
        if (NULL != m_pBuff)
        {
            free(m_pBuff);
            m_pBuff = NULL;
        }
		
		u16 wPerSize = sizeof(ListData);
        m_pBuff = malloc(dwDataNum*wPerSize);
        if (m_pBuff == NULL)
        {
            OspPrintf(TRUE, FALSE, "CKdvListBuff Malloc Buff failed, size=%d\n", dwDataNum);
            return FALSE;
        }
    }
    
	m_ptUsedHead = NULL;
    //建立空链表
    ListDataPtr ptTmp = (ListDataPtr)m_pBuff;
    m_ptFreeHead = ptTmp;

	new (ptTmp->Data()) Type;
	
    for(u32 dwIndex = 1;  dwIndex < dwDataNum; dwIndex++)
    {
        ptTmp->m_ptNext = (ListDataPtr)((u8*)ptTmp + sizeof(ListData));
		new (ptTmp->m_ptNext->Data()) Type;
        ptTmp = ptTmp->m_ptNext;
    }
    ptTmp->m_ptNext = NULL;
	
    m_dwTotalNum      = dwDataNum;
    m_dwFreeBlockNum  = dwDataNum;
    m_dwMinFreeBlocks = dwDataNum;
	
    return TRUE;
}

template<class Type>
void CNvList<Type>::Destroy()
{
	if (m_pBuff != NULL)
	{
		free(m_pBuff);
		m_pBuff = NULL;
	}
	
	m_ptFreeHead    =   NULL;
	m_ptUsedHead    =   NULL;
	m_dwFreeBlockNum    =   0;
	m_dwBuffSize        =   0;
}

template<class Type>
Type* CNvList<Type>::Next(Type* ptData)
{
	ListDataPtr Ptr = ListDataPtr(((char*)ptData) - ListData::m_dwDataOffset);
	return Ptr->m_ptNext == NULL ? NULL : Ptr->m_ptNext->Data();
}

template<class Type>
Type* CNvList<Type>::AllocNode()
{
    if (m_ptFreeHead == NULL || m_dwFreeBlockNum < 1)
    {
		OspPrintf(TRUE, FALSE, "CNvList::AllocNode() failed!\n");
        return NULL;
    }
	
    ListDataPtr ptAllocBlock = m_ptFreeHead;
	m_ptFreeHead = m_ptFreeHead->m_ptNext;	
    m_dwFreeBlockNum -= 1;

	//已使用链表管理
	ptAllocBlock->m_ptNext = m_ptUsedHead;
	ptAllocBlock->m_ptPre = NULL;
	if (m_ptUsedHead != NULL)
	{
		m_ptUsedHead->m_ptPre = ptAllocBlock;
	}

	m_ptUsedHead = ptAllocBlock;
    
    //记录最小空闲块数
    if (m_dwFreeBlockNum < m_dwMinFreeBlocks)
        m_dwMinFreeBlocks = m_dwFreeBlockNum;
	
    return ptAllocBlock->Data();
}

template<class Type>
u32 CNvList<Type>::FreeBuff(Type* Itor)
{	
	ListDataPtr Ptr = ListDataPtr(((char*)Itor) - ListData::m_dwDataOffset);
    if (Ptr == NULL)
    {
        return 0;
    }
	
	if (m_ptUsedHead == Ptr)	//表示删除m_ptUsedBuffList的头部
	{
		m_ptUsedHead = m_ptUsedHead->m_ptNext;
		if (NULL != m_ptUsedHead)
		{
			m_ptUsedHead->m_ptPre = NULL;
		}
	}
	else
	{
		Ptr->m_ptPre->m_ptNext = Ptr->m_ptNext;
		if (NULL != Ptr->m_ptNext)
		{
			Ptr->m_ptNext->m_ptPre = Ptr->m_ptPre;
		}
	}

	Ptr->m_ptPre		=   NULL;
    Ptr->m_ptNext		=   m_ptFreeHead;
    m_ptFreeHead    =   Ptr;
    m_dwFreeBlockNum    +=  1;
	
    if (m_dwFreeBlockNum > m_dwTotalNum)
    {
        OspPrintf(TRUE, FALSE, "CKdvListBuff::FreeBuff Total Block num=%d, but Free Block num=%d\n",
			m_dwTotalNum, m_dwFreeBlockNum);
     
        m_dwFreeBlockNum = m_dwTotalNum;
    }
	
    return 1;
}


template<class Type>
Type* CNvList<Type>::GetDataByIndex(u32 wIndex)
{
	
	if (wIndex >= m_dwTotalNum)
	{
		return NULL;
	}
	
    ListDataPtr ptr =  (ListDataPtr)((u8*)m_pBuff + sizeof(ListData) * wIndex);
	
	return ptr->Data();
}


#endif // _h_nvlist_h__
