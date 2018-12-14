/*=======================================================================
模块名      :SUS
文件名      :structsusdev.h
相关文件    :
文件实现功能:dev与SUS通信结构体定义

作者        : 
版本        : V1.0  Copyright(C) 2005-2010 Suzhou Keda Technology Co.Ltd
              All rights reserved.
--------------------------------------------------------------------------
修改记录:
日  期      版本        修改人      修改内容
2014/04/21  1.0					      创建
=======================================================================*/


#ifndef _STRUCT_SUS_DEV_H_
#define _STRUCT_SUS_DEV_H_

#include "constsus.h"
#include "oemmark.h"


#ifdef _XML_CONVERT_
#include "xmlstructconvert.h"
#endif

//...........................................
#ifdef WIN32
#pragma pack( push )
#pragma pack( 1 )
#ifndef PACKED
#define PACKED
#endif
#endif//.....................................

//...........................................
#ifdef _LINUX_
#ifndef PACKED
#define PACKED __attribute__ ((packed)) 
#endif
#endif//.....................................


class CSusLoginInfo
{
public:
	CSusLoginInfo();
	~CSusLoginInfo();
	void Init();

    const s8* GetDevType() const;
	void SetDevType(const s8* szType);

    COemMark GetOemMark() const;
    const s8* GetOemMarkString() const;
    void SetOemMark(const COemMark& tOemMark);
    void SetOemMark(const s8* szOEMMark);

	const s8* GetE164NO() const;
	void SetE164NO(const s8* szE164NO);

	const s8* GetCurSoftVer() const;
	void SetCurSoftVer(const s8* szSoftVer);

	//此接口MT无需关心
	u32 GetDevIp() const { return ntohl(m_dwDevIp); }
	void SetDevIp(u32 dwIp) { m_dwDevIp = htonl(dwIp); }

public:
#ifdef _XML_CONVERT_
    TIXML_STRING StructToXml();    
    BOOL32 XmlToStruct(const char* xmlString);
#endif	//_XML_CONVERT_

private:
	s8 m_szDevType[MAXLEN_SUS_DEV_NAME + 1];	//设备类型
    COemMark m_tOemMark;       //设备OEM标识
	s8 m_szE164NO[MAXLEN_SUS_E164NO + 1];       //设备164标识
	s8 m_szCurSoftVer[MAXLEN_SUS_SOFTVER + 1];	//设备目前软件版本
	u32 m_dwDevIp;              //终端IP
}PACKED;

inline CSusLoginInfo::CSusLoginInfo()
{
    Init();
}

inline CSusLoginInfo::~CSusLoginInfo()
{
    
}

inline void CSusLoginInfo::Init()
{
    memset(m_szDevType, 0, sizeof(m_szDevType));
    m_tOemMark.Init();
	memset(m_szE164NO, 0, sizeof(m_szE164NO));
    memset(m_szCurSoftVer, 0, sizeof(m_szCurSoftVer));
	m_dwDevIp = 0;
}

inline const s8* CSusLoginInfo::GetDevType() const
{
    return m_szDevType;
}

inline void CSusLoginInfo::SetDevType(const s8* szType) 
{ 
	if (NULL == szType)
    {
        memset(m_szDevType, 0, sizeof(m_szDevType));
        return;
    }
    
    strncpy( m_szDevType, szType, sizeof(m_szDevType)-1 );
    m_szDevType[sizeof(m_szDevType)-1] = '\0'; 
}

inline COemMark CSusLoginInfo::GetOemMark() const
{
    return m_tOemMark;
}

inline const s8* CSusLoginInfo::GetOemMarkString() const
{
    return m_tOemMark.GetOemMarkString();
}

inline void CSusLoginInfo::SetOemMark(const COemMark& tOemMark)
{
    m_tOemMark = tOemMark;
}

inline void CSusLoginInfo::SetOemMark(const s8* szOEMMark)
{
    m_tOemMark.SetOemMarkString(szOEMMark);
}

inline const s8* CSusLoginInfo::GetE164NO() const 
{ 
    return m_szE164NO; 
}

inline void CSusLoginInfo::SetE164NO(const s8* szE164NO) 
{ 
    if (NULL == szE164NO)
    {
        memset(m_szE164NO, 0, sizeof(m_szE164NO));
        return;
    }
    
    strncpy( m_szE164NO, szE164NO, sizeof(m_szE164NO)-1 );
    m_szE164NO[sizeof(m_szE164NO)-1] = '\0'; 
}

inline const s8* CSusLoginInfo::GetCurSoftVer() const 
{ 
    return m_szCurSoftVer; 
}

inline void CSusLoginInfo::SetCurSoftVer(const s8* szSoftVer) 
{ 
    if (NULL == szSoftVer)
    {
        memset(m_szCurSoftVer, 0, sizeof(m_szCurSoftVer));
        return;
    }
    
    strncpy( m_szCurSoftVer, szSoftVer, sizeof(m_szCurSoftVer)-1 );
    m_szCurSoftVer[sizeof(m_szCurSoftVer)-1] = '\0'; 
}

#ifdef _XML_CONVERT_
inline TIXML_STRING CSusLoginInfo::StructToXml()
{
    CXmlStructConvert xmltool;
    BOOL32 bRet = xmltool.InitStructToXml();
    if( !bRet )
    {
        TIXML_STRING strEmpty;
        return strEmpty;
    }

    xmltool.AddSiblingElementAndValue( "m_szDevType", m_szDevType );
    xmltool.AddNestedSiblingElement( "m_tOemMark", m_tOemMark );
	xmltool.AddSiblingElementAndValue("m_szE164NO", m_szE164NO);
    xmltool.AddSiblingElementAndValue( "m_szCurSoftVer", m_szCurSoftVer );
	xmltool.AddSiblingElementAndValue( "m_dwDevIp", m_dwDevIp );
    
    TIXML_STRING xmlStr = xmltool.ConvertXMLToString();
    return xmlStr;
}

inline BOOL32 CSusLoginInfo::XmlToStruct(const char* xmlString)
{
    CXmlStructConvert xmltool;
    BOOL32 bRet = xmltool.InitXmlToStruct( xmlString );
    if( bRet == FALSE )
    {
        return FALSE;
    }
    
    xmltool.GetValueByElementName( "m_szDevType", m_szDevType, sizeof(m_szDevType) );
	xmltool.GetNestedSiblingElement(  xmlString, "m_tOemMark", m_tOemMark );   
	xmltool.GetValueByElementName( "m_szE164NO", m_szE164NO, sizeof(m_szE164NO));
    xmltool.GetValueByElementName( "m_szCurSoftVer", m_szCurSoftVer, sizeof(m_szCurSoftVer) );

	u32 dwIp;
	xmltool.GetValueByElementName("m_dwDevIp", dwIp);
	SetDevIp(dwIp);

    return TRUE;
}
#endif	//_XML_CONVERT_

//指定模块
class CAssignedModule
{
public:
    CAssignedModule();
    ~CAssignedModule();
    void Init();

    u32 GetSn() const { return m_dwSn; }
    void SetSn(u32 dwSn);

    const s8* GetModuleName() const { return m_szModuleName; }
    void SetModuleName(const s8* szName);

public:
#ifdef _XML_CONVERT_
    TIXML_STRING StructToXml();    
    BOOL32 XmlToStruct(const char* xmlString);
#endif	//_XML_CONVERT_

private:
    u32 m_dwSn;              //版本序列号(全局唯一标识)
    s8 m_szModuleName[MAXLEN_SUS_MODULE_NAME+1];    //模块名
}PACKED;


inline CAssignedModule::CAssignedModule()
{
    Init();
}

inline CAssignedModule::~CAssignedModule()
{

}

inline void CAssignedModule::Init()
{
    m_dwSn = 0;
    memset(m_szModuleName, 0, sizeof(m_szModuleName));
}

inline void CAssignedModule::SetSn(u32 dwSn)
{
    m_dwSn = dwSn;
}

inline void CAssignedModule::SetModuleName(const s8* szName) 
{
    if (NULL == szName)
    {
        memset(m_szModuleName, 0, sizeof(m_szModuleName));
        return;
    }

    strncpy(m_szModuleName, szName, sizeof(m_szModuleName)-1);
    m_szModuleName[sizeof(m_szModuleName)-1] = '\0'; 
}

#ifdef _XML_CONVERT_
inline TIXML_STRING CAssignedModule::StructToXml()
{
    CXmlStructConvert xmltool;
    BOOL32 bRet = xmltool.InitStructToXml();
    if( !bRet )
    {
        TIXML_STRING strEmpty;
        return strEmpty;
    }

    xmltool.AddSiblingElementAndValue( "m_dwSn", m_dwSn );
    xmltool.AddSiblingElementAndValue( "m_szModuleName", m_szModuleName );

    TIXML_STRING xmlStr = xmltool.ConvertXMLToString();
    return xmlStr;
}

inline BOOL32 CAssignedModule::XmlToStruct(const char* xmlString)
{
    CXmlStructConvert xmltool;
    BOOL32 bRet = xmltool.InitXmlToStruct( xmlString );
    if( bRet == FALSE )
    {
        return FALSE;
    }

    u32 dwSn = 0;
    xmltool.GetValueByElementName( "m_dwSn", dwSn );
    SetSn(dwSn);

    xmltool.GetValueByElementName( "m_szModuleName", m_szModuleName, sizeof(m_szModuleName) );
    return TRUE;
}
#endif	//_XML_CONVERT_

#ifdef WIN32
#pragma pack( pop )
#endif


#endif // _STRUCT_SUS_DEV_H_
// END FILE



