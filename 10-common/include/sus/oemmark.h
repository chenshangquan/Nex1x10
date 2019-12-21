/*=======================================================================
ģ����      : sus
�ļ���      : oemmark.h
����ļ�    :
�ļ�ʵ�ֹ���: ��װOEM��ʶ��,�ṩһЩ�ӿ��Է���Բ���

����        : ������
�汾        : V1.0  Copyright(C) 2005-2010 Suzhou Keda Technology Co.Ltd
              All rights reserved.
--------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2013/03/02  1.0         ������      ����
=======================================================================*/

#ifndef _SUS_OEM_MARK_H_
#define _SUS_OEM_MARK_H_

//#include "operationconst.h"

#ifdef _XML_CONVERT_
#include "xmlstructconvert.h"
#endif	//_XML_CONVERT_

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

//Keda�����汾��OEM��ʶ
#define  KEDACOM_NORMAL_OEMMARK         (const s8*)"kedacom"

//OEM��ʶ����󳤶�
#define OPERATION_MAXLEN_OEMMARK                    (u16)16




class COemMark
{
public:
    COemMark();
	COemMark(const s8* szOemMark);

    void Init(void);

    //����������
    bool operator == ( const COemMark& tOther ) const;     
    bool operator != ( const COemMark& tOther ) const;    
    bool operator < ( const COemMark& tOther ) const;

    const s8* GetOemMarkString() const;
    void SetOemMarkString(const s8* szOemMark);

public:
#ifdef _XML_CONVERT_
    TIXML_STRING StructToXml() const;
    BOOL32 XmlToStruct(const char* xmlString);
#endif	//_XML_CONVERT_

private:
    s8 m_szOemMark[OPERATION_MAXLEN_OEMMARK+1];
}PACKED ;


inline COemMark::COemMark()
{
    Init();
}

inline COemMark::COemMark(const s8* szOemMark)
{
	Init();
	SetOemMarkString(szOemMark);	
}


inline void COemMark::Init( void )
{
    strncpy(m_szOemMark, KEDACOM_NORMAL_OEMMARK, sizeof(m_szOemMark)-1);
    m_szOemMark[sizeof(m_szOemMark)-1] = '\0';
}


inline bool COemMark::operator == ( const COemMark& tOther ) const
{
    if (strcmp(m_szOemMark, tOther.GetOemMarkString()) == 0) 
    {
        return true;
    }

    return false;
}

inline bool COemMark::operator != ( const COemMark& tOther ) const
{
    return !(*this == tOther);
}

inline bool COemMark::operator < (const COemMark& tOther) const
{
    int nCmp = strcmp( m_szOemMark, tOther.GetOemMarkString() );
    return nCmp < 0;
}


inline const s8* COemMark::GetOemMarkString() const 
{ 
    return m_szOemMark; 
}

inline void COemMark::SetOemMarkString(const s8* szOemMark) 
{
    if (NULL == szOemMark || 0 == strlen(szOemMark))
    {
        szOemMark = KEDACOM_NORMAL_OEMMARK;
    }
    
    strncpy(m_szOemMark, szOemMark, sizeof(m_szOemMark)-1);
    m_szOemMark[sizeof(m_szOemMark)-1] = '\0';
    
    return;
}

#ifdef _XML_CONVERT_
inline TIXML_STRING COemMark::StructToXml() const
{
    CXmlStructConvert xmltool;
    BOOL32 bRet = xmltool.InitStructToXml();
    if (!bRet)
    {
        TIXML_STRING strEmpty;
        strEmpty.clear();
        return strEmpty;
    }
    
    xmltool.AddSiblingElementAndValue("m_szOemMark", GetOemMarkString()); 
    
    TIXML_STRING xmlStr = xmltool.ConvertXMLToString();
    return xmlStr;
}

inline BOOL32 COemMark::XmlToStruct(const char* xmlString)
{
    CXmlStructConvert xmltool;
    BOOL32 bRet = xmltool.InitXmlToStruct(xmlString);
    if (!bRet)
    {
        return FALSE;
    }
    
    s8 szOemMark[OPERATION_MAXLEN_OEMMARK+1] = {0};
    xmltool.GetValueByElementName("m_szOemMark", szOemMark, sizeof(szOemMark)); 
	SetOemMarkString(szOemMark);
    
    return TRUE;
}
#endif	//_XML_CONVERT_



#ifdef WIN32
#pragma pack( pop )
#endif

#endif /*_SUS_OEM_MARK_H_*/
//END FILE
