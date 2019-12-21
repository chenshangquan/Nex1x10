
/*=======================================================================
模块名      : SUS
文件名      : structsusnack.h
相关文件    :
文件实现功能:

作者        : 吴月龙
版本        : V1.0  Copyright(C) 2005-2010 Suzhou Keda Technology Co.Ltd
              All rights reserved.
--------------------------------------------------------------------------
修改记录:
日  期      版本        修改人      修改内容
2013/03/08  1.0         吴月龙      创建
=======================================================================*/

#ifndef _STRUCT_SUS_NACK_H_
#define _STRUCT_SUS_NACK_H_

#include "structdevicever.h"

#ifdef _XML_CONVERT_
#include "xmlstructconvert.h"
#endif

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



class CSusBaseNack
{
public:
    CSusBaseNack();    
	virtual ~CSusBaseNack();

    void Init();
    
    u32 GetErrorId() const { return m_dwErrorId; }
    void SetErrorId(u32 dwErrID) { m_dwErrorId = dwErrID; }    
public:
#ifdef _XML_CONVERT_
    TIXML_STRING StructToXml();    
    BOOL32 XmlToStruct(const char* xmlString);
#endif	//_XML_CONVERT_
    
protected:
    u32 m_dwErrorId;
} PACKED;

inline CSusBaseNack::CSusBaseNack()
{
    Init();
}

inline CSusBaseNack::~CSusBaseNack()
{
}

inline void CSusBaseNack::Init()
{
    m_dwErrorId = 0;
}

#ifdef _XML_CONVERT_
inline TIXML_STRING CSusBaseNack::StructToXml()
{
    CXmlStructConvert xmltool;
    BOOL32 bRet = xmltool.InitStructToXml();
    if (!bRet)
    {
        TIXML_STRING strEmpty;
        strEmpty.clear();
        return strEmpty;
    }
    
    xmltool.AddSiblingElementAndValue("m_dwErrorId", this->m_dwErrorId);  
    
    TIXML_STRING xmlStr = xmltool.ConvertXMLToString();
    return xmlStr;
}

inline BOOL32 CSusBaseNack::XmlToStruct(const char* xmlString)
{
    CXmlStructConvert xmltool;
    BOOL32 bRet = xmltool.InitXmlToStruct(xmlString);
    if (!bRet)
    {
        return FALSE;
    }
    
    u32 dwU32Temp = 0;    
    xmltool.GetValueByElementName("m_dwErrorId", dwU32Temp);    
    this->m_dwErrorId = dwU32Temp;
    
    return TRUE;
}
#endif	//_XML_CONVERT_


//类T必须已经实现了StructToXml()与XmlToStruct()函数
template <class T>
class CSusDetailNack : public CSusBaseNack
{
public:
    CSusDetailNack()
    {
        Init();
    }
    void Init()
    {
        CSusBaseNack::Init();
    }
    
    T GetDetailInfo() const 
    { 
        return m_tDetailInfo; 
    }
    
    void SetDetailInfo(const T& tInfo) 
    { 
        m_tDetailInfo = tInfo;
    }
public:
#ifdef _XML_CONVERT_
    TIXML_STRING StructToXml()
    {
        CXmlStructConvert xmltool;
        
        CSusBaseNack baseClass = CSusBaseNack(*this);
        BOOL32 bRet = xmltool.InitStructToXmlByBaseClass(baseClass);
        if (!bRet)
        {
            TIXML_STRING strEmpty;
            strEmpty.clear();
            return strEmpty;
        }
        
        xmltool.AddNestedSiblingElement("m_tDetailInfo", this->m_tDetailInfo);  
        
        TIXML_STRING xmlStr = xmltool.ConvertXMLToString();
        return xmlStr;
    }
    
    BOOL32 XmlToStruct(const char* xmlString)
    {
        CXmlStructConvert xmltool;
        BOOL32 bRet = xmltool.InitXmlToStructByBaseClass(xmlString, (*this), CSusBaseNack(*this));
        if (!bRet)
        {
            return FALSE;
        }      
        
        xmltool.GetNestedSiblingElement(xmlString, "m_tDetailInfo", this->m_tDetailInfo);    
        
        return TRUE;
    }
#endif	//_XML_CONVERT_

private:
    T m_tDetailInfo;   
} PACKED;


typedef CSusDetailNack<CSusDevVerInfo>  CDevVerNack;


#ifdef WIN32
#pragma pack( pop )
#endif

#endif  /*_DMS_NACK_STRUCT_H_*/
//END FILE

