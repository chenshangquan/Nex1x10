/*=============================================================================
	ģ���ࣺ
	������ Link
	���ã� ����ڵ�
	˵���� �����ر��ʼ����Ҫ����TӦ�����ṩ��Ӧ���޲������캯��
=============================================================================*/
template <class T>
class ArrayNode
{
private:
    T m_Data;                                   // ���ڱ�����Ԫ�ص�����
    u32 m_dwNextId;                             // ָ���̽���ָ��
	
public:      
    ArrayNode() { m_dwNextId = 0; }    
    ArrayNode(const T &Data, u32 dwNextId = 0)
    {
        SetData( Data );
        SetNext( dwNextId );
    }
    
    T * GetData( void ) { return &m_Data; }    
    void SetData( const T &Data ) { m_Data = Data; }    
    u32 GetNext( void ) { return ntohl(m_dwNextId); }
    void SetNext( u32 dwNextId ) { m_dwNextId = htonl(dwNextId); }
}
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
;

/*=============================================================================
	ģ���ࣺ
	������ LinkArray
	���ã� ����һ����������
	˵���� 1�������ر��ʼ����Ҫ����TӦ�����ṩ��Ӧ���޲������캯��
	2��Ԫ��TӦ֧����������� == : ��Ҫ��ȡ��
	3��2009-02-26��ȡ�� IsExist �� GetPos ����������Ϊ������������Ҫ ��T ����
	����� == ��ͨ���Բ�ǿ
=============================================================================*/
template <class T, u32 dwArrayLen=1>
class LinkArray
{
private: 
    ArrayNode<T> m_atLinkArray[dwArrayLen];
    u32     m_dwHeadId;
    u32     m_dwTailId;                                  // �������ͷ��βID��, �����ŵ���ID�ż�1

private: 
    u32     GetIdByLink( ArrayNode<T> * pCur )
    {
        u32 dwArraySize = sizeof(m_atLinkArray)/sizeof(m_atLinkArray[0]);
        u32 dwIdx = 0;
        for ( dwIdx = 0; dwIdx < dwArraySize; dwIdx++ )
        {
            if ( pCur == &(m_atLinkArray[dwIdx]) )
            {
                return (dwIdx+1);
            }
        } 
        return 0;
    }
    ArrayNode<T> * GetLinkById( u32 dwId )
    {
        if ( 0 == dwId || dwId > sizeof(m_atLinkArray)/sizeof(m_atLinkArray[0]) )
        {
            return NULL;
        }
        ArrayNode<T> * pCur = &(m_atLinkArray[dwId-1]);
        return pCur;
    }

    u32     GetHeadId( void ) const { return ntohl(m_dwHeadId); }
    void    SetHeadId( u32 dwHeadId ) { m_dwHeadId = htonl(dwHeadId); }

    u32     GetTailId( void ) const { return ntohl(m_dwTailId); }
    void    SetTailId( u32 dwTailId ) { m_dwTailId = htonl(dwTailId); }

    // ��ÿ��д洢�ռ�ID
    u32 GetIdleId(void)
    {
        u32 dwArraySize = sizeof(m_atLinkArray)/sizeof(m_atLinkArray[0]);
        u32 dwIdx = 0;
        for ( dwIdx = 0; dwIdx < dwArraySize; dwIdx++ )
        {
            if ( 0 == m_atLinkArray[dwIdx].GetNext() &&
                GetTailId() != (dwIdx+1) )
            {
                return (dwIdx+1);
            }
        }
        return 0;
    }
     // �������Ա�ָ���p��Ԫ�ص�ָ��ֵ
    ArrayNode<T> * GetLink(const u32 &dwPos)        
    {
        if ( dwPos < 0 || dwPos >= Length() )
        {
            return NULL;
        }
        
        u32 dwCount = 0;
        ArrayNode<T> *pCur = GetLinkById( GetHeadId() );
        while ( pCur != NULL && dwCount < dwPos )
        {
            u32 dwNextId = pCur->GetNext();
            pCur = GetLinkById(dwNextId);
            dwCount++;
        }       
        return pCur;
    }   

public: 
    LinkArray() { Clear(); }         // ���캯��
    ~LinkArray() { Clear(); }        // ��������
    // �ж������Ƿ�Ϊ��
    BOOL32 IsEmpty() const { return ( 0 == m_dwHeadId || 0 == m_dwTailId ); }
    // ������洢�������������Ϊ�ձ�
    void   Clear()                                    
    {
        m_dwHeadId = 0;
        m_dwTailId = 0;
        u32 dwArraySize = sizeof(m_atLinkArray)/sizeof(m_atLinkArray[0]);
        u32 dwIdx = 0;
        for ( dwIdx = 0; dwIdx < dwArraySize; dwIdx++ )
        {
            m_atLinkArray[dwIdx].SetNext( 0 );
        }
    }
    // ���ش�˳���ĵ�ǰʵ�ʳ���
    u32 Length() 
    {
        ArrayNode<T> *pCur = GetLinkById( GetHeadId() );
        u32 dwCount = 0;
        
        while ( pCur != NULL ) 
        {
            u32 dwNextId = pCur->GetNext();
            pCur = GetLinkById(dwNextId);
            dwCount++;
        }
        return dwCount;
    }    
    // �ڱ�β���һ��Ԫ��value����ĳ�����1
    BOOL32 Append(const T &Value)                      
    {
        u32 dwIdleId = GetIdleId();
        ArrayNode<T> *pCur = GetLinkById( dwIdleId );
        if ( NULL == pCur )
        {
            return FALSE;
        }       
        pCur->SetData( Value );
        pCur->SetNext( 0 );
        
        u32 dwOldTailId = GetTailId();
        SetTailId(dwIdleId);

        ArrayNode<T> * pTail = GetLinkById( dwOldTailId );
        if ( NULL != pTail )
        {
            pTail->SetNext( dwIdleId );
        }
        else
        {
            SetHeadId(dwIdleId);
        }        
        return TRUE;
    }
    // �ڵ�dwPos��λ�ò�����������ΪValue���½��
    BOOL32 Insert(const u32 &dwPos, const T &Value)    
    {
        ArrayNode<T> *pCur = NULL;
        ArrayNode<T> *pNext = NULL;
        
        u32 dwIdleId = GetIdleId();
        pNext = GetLinkById( dwIdleId ); 
        if ( NULL == pNext )
        {
            return FALSE;
        }
        
        if ( dwPos == 0 )
        {
            pNext->SetData( Value );
            pNext->SetNext( GetHeadId() );
            SetHeadId( dwIdleId );
            if ( 0 == GetTailId() )
            {
                // ԭ���ı�Ϊ��
                SetTailId( dwIdleId );
            }
        }
        else 
        {
            if ( (pCur = GetLink(dwPos-1) ) == NULL) 
            {                                                     
                return FALSE;
            }
            pNext->SetData( Value );
            pNext->SetNext( pCur->GetNext() );
            pCur->SetNext( dwIdleId );
            u32 dwPreId = GetIdByLink(pCur);
            if ( dwPreId == GetTailId() )                                          
            {
                SetTailId( dwIdleId );
            }
        }    
        return TRUE;
    }
    // ɾ��λ��i�ϵ�Ԫ�أ���ĳ��ȼ� 1
    BOOL32 Delete(const u32 &dwPos)                    
    {
        ArrayNode<T> *pCur = NULL;
        ArrayNode<T> *pPre = NULL; 
        
        pCur = GetLink( dwPos );
        if ( NULL == pCur )
        {
            return FALSE;
        }
        if ( dwPos > 0 )
        {
            pPre = GetLink( dwPos-1 );
            if ( NULL == pPre )
            {
                return FALSE;
            }
        }

        u32 dwNext = pCur->GetNext();
        pCur->SetNext( 0 );
        if ( NULL == pPre )
        {                           
            SetHeadId( dwNext );                  
        }
        else
        {
            pPre->SetNext( dwNext );         
        }
        if ( GetTailId() == GetIdByLink(pCur) )
        {
            if ( dwNext != 0 )
            {
                SetTailId( dwNext );
            }
            else
            {
                SetTailId( GetIdByLink(pPre) );
            }
        } 
        return TRUE;
    }

    // ����λ��i��Ԫ��ֵ 
    T * GetValue(const u32 &dwPos)            
    {
        ArrayNode<T> *p = GetLink(dwPos);
        if ( p == NULL )
        {
            return NULL;
        }
        else
        {
            return p->GetData();
        }
    }

	void SetValue(const u32 &dwPos, T &Value )
	{
        ArrayNode<T> *p = GetLink(dwPos);
        if ( p == NULL )
        {
            return;
        }
        else
        {
            p->SetData(Value);
        }
	}
}

#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
;