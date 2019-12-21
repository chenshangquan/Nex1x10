/*=======================================================================
	ģ����      : 
	�ļ���      : kdvplist.h
	����ļ�    :
	�ļ�ʵ�ֹ���: ʵ���˶�̬�б����ݽṹ���˶�̬�б��С�����޵�

	����        : ������
	�汾        : V1.0  Copyright(C) 2005-2010 Suzhou Keda Technology Co.Ltd
				  All rights reserved.
	--------------------------------------------------------------------------
	�޸ļ�¼:
	��  ��      �汾        �޸���      �޸�����
	2010/12/27  1.0         ������      ����
=======================================================================*/
#ifndef _KDVP_LIST_H_
#define _KDVP_LIST_H_

#include <assert.h>
#include "kdvtype.h"
#ifdef _LINUX_
    #include<netinet/in.h>
#else
    #include <winsock2.h>
#endif

#ifdef _XML_CONVERT_
#include "xmlstructconvert.h"
#endif  //_XML_CONVERT_

#ifdef _JSON_CONVERT_
#include "jsonconvert.h"
#endif  //_JSON_CONVERT_

#pragma warning( disable : 4786 )


#ifdef WIN32
#pragma pack( push, 1 )
#ifndef PACKED
#define PACKED 
#endif
#endif //WIN32

#ifdef _VXWORKS_
#ifndef PACKED
#define PACKED __attribute__((__packed__))
#endif // PACKED
#endif //_VXWORKS_

#ifdef _LINUX_
#ifndef PACKED
#ifndef _EQUATOR_
#define PACKED  __attribute__((packed))
#else 
#define PACKED
#endif //EQUATOR_
#endif // PACKED 
#endif //_LINUX_

template <class T, u32 m_dwMaxSize>
class CKdvpList
{
public:
    CKdvpList()
    {
        Init();
    }
    void Init()
    {
        SetCurSize(0);
        memset(m_atArray, 0, sizeof(m_atArray));
    }

    // ����б��ڵ���Ч���ݸ���
    u32 Size() const 
    { 
        return GetCurSize(); 
    }

	// ����б���������
    u32 GetMaxListSize()const
    {
        return m_dwMaxSize;
    }

	// �б��Ƿ�Ϊ��
    BOOL32 IsEmpty() const 
    { 
        return ( 0 == GetCurSize() ); 
    }
   
    // ���ָ��λ�õ��б�Ԫ��ֵ��dwPos��0��ʼ����
    T GetValue( u32 dwPos ) const 
    {        
        assert( dwPos < GetCurSize() );
        
        return m_atArray[dwPos];
    }
    
    // �ж�ĳԪ���Ƿ����;TRUE: ����; FALSE: ������;
    BOOL32 Exist(const T& tValue) const 
    {  
        for (u32 dwIndex = 0; dwIndex < Size() ; ++dwIndex)
        {
            if (tValue == m_atArray[dwIndex])
            {
                return TRUE;
            }
        }
        
        return FALSE;
    }


	// ���б�ĩβ���һ������
    BOOL32 Append( const T& tValue ) 
    { 
		u32 dwCurSize = GetCurSize();
        if ( dwCurSize >= m_dwMaxSize )
        {
            assert(FALSE && "�����Ѿ�����!");
            return FALSE;
        }
        
        m_atArray[dwCurSize] = tValue; 
        ++dwCurSize;
		SetCurSize(dwCurSize);
        
        return TRUE;
    }
    
    // ɾ��һ���б����ݣ�dwPos��0��ʼ����
    BOOL32 Delete( const u32 &dwPos ) 
    {
		u32 dwCurSize = GetCurSize();
        if ( dwPos >= dwCurSize )
        {
            assert(FALSE && "dwPos���ڵ������鳤��!");
            return FALSE;
        }
        
        // �������������ǰ��һ��λ��
        memmove( &m_atArray[dwPos], &m_atArray[dwPos+1], sizeof(T)*(dwCurSize-dwPos-1) );
        
        // ���һ���������
        memset( &m_atArray[dwCurSize -1], 0, sizeof(T) );
        
        --dwCurSize;
		SetCurSize(dwCurSize);
        
        return TRUE;
    }
    
    // �ڵ�dwPos��λ��ǰ�������������ΪValue���½��
    BOOL32 Insert( const u32 &dwPos, const T& tValue )    
    {
        if ( dwPos < 0 || dwPos >= m_dwMaxSize )
        {
            return FALSE;
        }

		u32 dwCurSize = GetCurSize();
		if( dwCurSize >= m_dwMaxSize )
		{
			assert(FALSE && "���������������ٲ�������!");
            return FALSE;
		}
        
        // ��dwPosλ���Ժ�(����dwPos)�����������ƶ�һ��λ��
		for( u32 dwIndex = dwCurSize-1; dwIndex >= dwPos; dwIndex-- )
		{
			T data;
			if( GetValue( dwIndex, data ) )
			{
				m_atArray[dwIndex+1] = data;
			}
		}
        
        // ��������
        m_atArray[dwPos] = tValue;
        
		// �б��ȼ�1
        dwCurSize++;
		SetCurSize(dwCurSize);
        
        return TRUE;
    }
    
public:
#ifdef _XML_CONVERT_	
    TIXML_STRING StructToXml()
    {
        CXmlStructConvert xmltool;
        BOOL32 bRet = xmltool.InitStructToXml();
        if (!bRet)
        {
            TIXML_STRING strEmpty;
            strEmpty.clear();
            return strEmpty;
        }
        
        xmltool.AddSiblingElementAndValue("m_dwCurSize", GetCurSize()); 
        //ת������
        xmltool.AddNestedArraySiblingElement("m_atArray", m_atArray, GetCurSize()); 
        
        TIXML_STRING xmlStr = xmltool.ConvertXMLToString();
        return xmlStr;
    }
    
    BOOL32 XmlToStruct(const char* xmlString)
    {
        CXmlStructConvert xmltool;
        BOOL32 bRet = xmltool.InitXmlToStruct(xmlString);
        if (!bRet)
        {
            return FALSE;
        }
        
        u32 dwSize = 0;        
        xmltool.GetValueByElementName("m_dwCurSize", dwSize); 
        SetCurSize(dwSize);
        
        u32 dwRealNum = 0;
        xmltool.GetNestedArraySiblingElement(xmlString, "m_atArray", m_atArray, m_dwMaxSize, dwRealNum);
        //ת������
        
        return TRUE; 
    }
#endif  //_XML_CONVERT_
   
#ifdef _JSON_CONVERT_
    Json::Value StructToJson() const
    {
        CJsonConvert jsonTool;
        
        jsonTool.SetValue("m_dwCurSize", GetCurSize());
        jsonTool.SetNestedArrayValue("m_atArray", m_atArray, GetCurSize());
        
        return jsonTool.GetJson();
    }
    
    BOOL32 JsonToStruct(const s8* szJson)
    {
        if (NULL == szJson)
        {
            return FALSE;
        }
        
        CJsonConvert jsonTool;        
        BOOL32 bRet = jsonTool.ParseJsonStr(szJson);
        if (!bRet)
        {
            return FALSE;
        }
        
        u32 dwSize = 0;        
        jsonTool.GetValue("m_dwCurSize", dwSize);
        SetCurSize(dwSize);

        u32 dwRealNum = 0;
        jsonTool.GetNestedArrayValue("m_atArray", m_atArray, m_dwMaxSize, dwRealNum);
        
        return TRUE;
    }
#endif  //_JSON_CONVERT_

private:
	u32 GetCurSize() const { return ntohl(m_dwCurSize); }
	void SetCurSize(u32 dwNum) { m_dwCurSize = htonl(dwNum); }

private:
    u32 m_dwCurSize;	//������  ע��:����ͨ��Get��Set�������ã�������ֱ��ʹ�ô˱���
    T m_atArray[m_dwMaxSize];
}PACKED;



#ifdef WIN32
#pragma pack( pop )
#endif

#endif  // _TAS_LIST_H_
// END FILE



