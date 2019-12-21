/*=======================================================================
	模块名      : 
	文件名      : kdvplist.h
	相关文件    :
	文件实现功能: 实现了动态列表数据结构，此动态列表大小是受限的

	作者        : 吴月龙
	版本        : V1.0  Copyright(C) 2005-2010 Suzhou Keda Technology Co.Ltd
				  All rights reserved.
	--------------------------------------------------------------------------
	修改记录:
	日  期      版本        修改人      修改内容
	2010/12/27  1.0         吴月龙      创建
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

    // 获得列表内的有效数据个数
    u32 Size() const 
    { 
        return GetCurSize(); 
    }

	// 获得列表的最大容量
    u32 GetMaxListSize()const
    {
        return m_dwMaxSize;
    }

	// 列表是否为空
    BOOL32 IsEmpty() const 
    { 
        return ( 0 == GetCurSize() ); 
    }
   
    // 获得指定位置的列表元素值，dwPos从0开始计数
    T GetValue( u32 dwPos ) const 
    {        
        assert( dwPos < GetCurSize() );
        
        return m_atArray[dwPos];
    }
    
    // 判读某元素是否存在;TRUE: 存在; FALSE: 不存在;
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


	// 在列表末尾添加一个数据
    BOOL32 Append( const T& tValue ) 
    { 
		u32 dwCurSize = GetCurSize();
        if ( dwCurSize >= m_dwMaxSize )
        {
            assert(FALSE && "数组已经满了!");
            return FALSE;
        }
        
        m_atArray[dwCurSize] = tValue; 
        ++dwCurSize;
		SetCurSize(dwCurSize);
        
        return TRUE;
    }
    
    // 删除一个列表数据，dwPos从0开始计数
    BOOL32 Delete( const u32 &dwPos ) 
    {
		u32 dwCurSize = GetCurSize();
        if ( dwPos >= dwCurSize )
        {
            assert(FALSE && "dwPos大于等于数组长度!");
            return FALSE;
        }
        
        // 将后面的数据先前搬一个位置
        memmove( &m_atArray[dwPos], &m_atArray[dwPos+1], sizeof(T)*(dwCurSize-dwPos-1) );
        
        // 最后一个数据清空
        memset( &m_atArray[dwCurSize -1], 0, sizeof(T) );
        
        --dwCurSize;
		SetCurSize(dwCurSize);
        
        return TRUE;
    }
    
    // 在第dwPos个位置前面插入数据内容为Value的新结点
    BOOL32 Insert( const u32 &dwPos, const T& tValue )    
    {
        if ( dwPos < 0 || dwPos >= m_dwMaxSize )
        {
            return FALSE;
        }

		u32 dwCurSize = GetCurSize();
		if( dwCurSize >= m_dwMaxSize )
		{
			assert(FALSE && "数组已满，不能再插入数据!");
            return FALSE;
		}
        
        // 将dwPos位置以后(包括dwPos)的数据往后移动一个位置
		for( u32 dwIndex = dwCurSize-1; dwIndex >= dwPos; dwIndex-- )
		{
			T data;
			if( GetValue( dwIndex, data ) )
			{
				m_atArray[dwIndex+1] = data;
			}
		}
        
        // 插入数据
        m_atArray[dwPos] = tValue;
        
		// 列表长度加1
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
        //转换数组
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
        //转换数组
        
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
    u32 m_dwCurSize;	//网络序  注意:必须通过Get与Set函数调用，不允许直接使用此变量
    T m_atArray[m_dwMaxSize];
}PACKED;



#ifdef WIN32
#pragma pack( pop )
#endif

#endif  // _TAS_LIST_H_
// END FILE



