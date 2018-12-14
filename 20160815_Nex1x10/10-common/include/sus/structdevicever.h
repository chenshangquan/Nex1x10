/*=======================================================================
模块名      :SUS
文件名      :structdevicever.h
相关文件    :
文件实现功能:版本信息

作者        : 
版本        : V1.0  Copyright(C) 2005-2010 Suzhou Keda Technology Co.Ltd
              All rights reserved.
--------------------------------------------------------------------------
修改记录:
日  期      版本        修改人      修改内容
2014/04/21  1.0					      创建
=======================================================================*/
#ifndef _STRUCT_DEVICE_VER_H
#define _STRUCT_DEVICE_VER_H


#include <string>
#include "oemmark.h"
#include "constsus.h"
#include "kdvplist.h"
//#include "suc_types.h"



#if ((defined _SUS_SERVER_) || (defined _SUS_MGR_)) 
#include <string>
#include "constself.h"
#endif

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



class CGrayReleaseRange
{
public:
    CGrayReleaseRange();
    ~CGrayReleaseRange();
    void Init();

    const s8* GetMoidList() const { return m_szMoidList; }
    void SetMoidList(const s8* szE164List);

    const s8* GetE164List(void) const { return m_szE164List; }
    void SetE164List(const s8 *pRegExpInfo);

public:
#ifdef _XML_CONVERT_
    TIXML_STRING StructToXml() const ;    
    BOOL32 XmlToStruct(const char* xmlString);
#endif	//_XML_CONVERT_

private:
    s8 m_szMoidList[MAXLEN_SUS_MOIDLIST+1];
    s8 m_szE164List[MAXLEN_SUS_E164LIST+1];

}PACKED;

inline CGrayReleaseRange::CGrayReleaseRange()
{
    Init();
}

inline CGrayReleaseRange::~CGrayReleaseRange()
{

}

inline void CGrayReleaseRange::Init()
{
    memset(m_szMoidList, 0, sizeof(m_szMoidList));
    memset(m_szE164List, 0, sizeof(m_szE164List));
}

inline void CGrayReleaseRange::SetMoidList(const s8 *szList)
{
    if (NULL == szList)
    {
        memset(m_szMoidList, 0, sizeof(m_szMoidList));
        return;
    }

    strncpy( m_szMoidList, szList, sizeof(m_szMoidList)-1 );
    m_szMoidList[sizeof(m_szMoidList)-1] = '\0'; 
}

inline void CGrayReleaseRange::SetE164List(const s8 *szList)
{
    if (NULL == szList)
    {
        memset(m_szE164List, 0, sizeof(m_szE164List));
        return;
    }

    strncpy( m_szE164List, szList, sizeof(m_szE164List)-1 );
    m_szE164List[sizeof(m_szE164List)-1] = '\0'; 
}


#ifdef _XML_CONVERT_
inline TIXML_STRING CGrayReleaseRange::StructToXml() const 
{
    CXmlStructConvert xmltool;
    BOOL32 bRet = xmltool.InitStructToXml();
    if( !bRet )
    {
        TIXML_STRING strEmpty;
        return strEmpty;
    }

    xmltool.AddSiblingElementAndValue( "m_szMoidList", m_szMoidList );   
    xmltool.AddSiblingElementAndValue( "m_szE164List", m_szE164List );

    TIXML_STRING xmlStr = xmltool.ConvertXMLToString();
    return xmlStr;
}

inline BOOL32 CGrayReleaseRange::XmlToStruct(const char* xmlString)
{
    CXmlStructConvert xmltool;
    BOOL32 bRet = xmltool.InitXmlToStruct( xmlString );
    if( bRet == FALSE )
    {
        return FALSE;
    }


    xmltool.GetValueByElementName( "m_szMoidList", m_szMoidList, sizeof(m_szMoidList) );
    xmltool.GetValueByElementName( "m_szE164List", m_szE164List, sizeof(m_szE164List) );

    return TRUE;
}
#endif	//_XML_CONVERT_

class CSusDevVerInfo 
{
public:
	 enum
    {
        Invalid_Sn = 0
    };

	enum EmDiff
	{
		EmDiff_Nothing			= 0x00000,
		EmDiff_Sn               = 0x00001,
		EmDiff_VerLevel			= 0x00002,
		EmDiff_OemMark			= 0x00004,
		EmDiff_DevType			= 0x00008,
		EmDiff_ReleaseAttribute	= 0x00010,
		EmDiff_SoftVer			= 0x00020,
		EmDiff_ReleaseNotes		= 0x00040,
		EmDiff_FileName			= 0x00080,
		EmDiff_FileSize			= 0x00100,
        EmDiff_GrayRange	    = 0x00200,  //灰度范围
	};

	enum EMSusVerLevel
	{
		EMSusVerLevel_Begin = -1,
		EmSusVerLevel_Important = 0,
		EmSusVerLevel_Suggest = 1,
		EmSusVerLevel_Normal = 2
	};

	enum EMReleaseAttribute
	{
		EmSusVer_Begin      = 0,
		EmSusVer_Common     = 0x0001,	//普通版本
		EmSusVer_Recommend  = 0x0002,	//推荐版本
		EmSusVer_GrayRelease= 0x0004	//灰度版本
	};

public:
	CSusDevVerInfo();
	~CSusDevVerInfo();
	void Init();

	bool operator < (const CSusDevVerInfo & tOther) const;
    bool operator == (const CSusDevVerInfo & tOther) const;
    bool operator != ( const CSusDevVerInfo& tOther ) const;
    u32 Compare(const CSusDevVerInfo& tOther) const;

	u32 GetSn() const;
    void SetSn(u32 dwSn);
	
    COemMark GetOemMark() const;
    const s8* GetOemMarkString() const;
    void SetOemMark(const COemMark& tOemMark);
    void SetOemMark(const s8* szOemMark);

	const s8* GetDevType() const;
	void SetDevType(const s8* szDevType);

	EMSusVerLevel GetVerLevel() const;
	const s8* GetVerLeveString() const;
    void SetVerLevel(EMSusVerLevel dwLevel);

	BOOL32 IsRecommend() const;
	BOOL32 IsGrayRelease() const;
	BOOL32 IsCommonVer() const;

	void SetReleaseAttribute(EMReleaseAttribute wReleaseAttribute);
	EMReleaseAttribute GetReleaseAttribute(void) const;

	const s8* GetSoftVer() const;
	void SetSoftVer(const s8* szSoftVer);
	BOOL32 IsSoftVerValid() const;

	const s8* GetReleaseNotes() const;
	void SetReleaseNotes(const s8* szReleaseNotes);

	const s8* GetFileName() const;
	void SetFileName(const s8* szFileName);
    const s8* GetFileOnlyName() const;          //只获取文件名称(不包含路径)

	u32 GetFileSize() const;
	void SetFileSize(const u32 dwSize);

    CGrayReleaseRange GetGrayRange() const { return m_tGrayRange; }
    void SetGrayRange(const CGrayReleaseRange& tRange) { m_tGrayRange = tRange; }

#if ((defined _SUS_SERVER_) || (defined _SUS_MGR_)) 
    std::string GetSusSaveFileName( ) const;    //保存到服务器上的文件名称
    std::string GetSusSaveFileDir() const;      //保存到服务器上的文件目录
#endif

public:
#ifdef _XML_CONVERT_
    TIXML_STRING StructToXml() const ;    
    BOOL32 XmlToStruct(const char* xmlString);
#endif	//_XML_CONVERT_

private:
	u32 m_dwSn;  //版本序列号(全局唯一标识)
    COemMark m_tOemMark;    //版本OEM标识
    s8 m_szDevType[MAXLEN_SUS_DEV_NAME + 1];	//版本所属设备类型
    EMSusVerLevel m_emVerLevel;	//版本级别
	EMReleaseAttribute m_emReleaseAttribute;	//版本发布属性
	s8 m_szSoftVer[MAXLEN_SUS_SOFTVER + 1];	//软件版本号
	s8 m_szReleaseNotes[MAXLEN_SUS_RELEASE_NOTES*2 + 1];	//发行说明  *2是为满足多国语言
    s8 m_szFileName[MAXLEN_SUS_FILENAME + 1];	//文件名
    u32 m_dwFileSize;       //文件大小(bit) u32能支持4G大小
    CGrayReleaseRange m_tGrayRange; //灰度发布范围
}PACKED;

inline CSusDevVerInfo::CSusDevVerInfo()
{
	Init();
}

inline CSusDevVerInfo::~CSusDevVerInfo()
{

}

inline void CSusDevVerInfo::Init()
{
	m_dwSn = Invalid_Sn;
	m_tOemMark.Init();
	memset(m_szDevType, 0, sizeof(m_szDevType));
	m_emVerLevel = EMSusVerLevel_Begin;
	m_emReleaseAttribute = EmSusVer_Begin;
	memset(m_szSoftVer, 0, sizeof(m_szSoftVer));
	memset(m_szReleaseNotes, 0, sizeof(m_szReleaseNotes));
	memset(m_szFileName, 0, sizeof(m_szFileName));
	m_dwFileSize = 0;
    m_tGrayRange.Init();
}

inline bool CSusDevVerInfo::operator < (const CSusDevVerInfo & tOther) const
{
	if (this->GetSn() < tOther.GetSn())
    {
        return true;
    }
	
    return false;
}
inline bool CSusDevVerInfo::operator == (const CSusDevVerInfo & tOther) const
{
	if (this->GetSn() != tOther.GetSn())
	{
		return false;
	}

	if (0 != strcmp(this->GetDevType(), tOther.GetDevType()) )
	{
		return false;
	}

	if (this->GetOemMark() != tOther.GetOemMark())
    {
        return false;
    }

	if (0 != strcmp(this->GetReleaseNotes(), tOther.GetReleaseNotes()))
	{
		return false;
	}

	if (this->GetReleaseAttribute() != tOther.GetReleaseAttribute())
	{
		return false;
	}

	if (0 != strcmp(this->GetSoftVer(), tOther.GetSoftVer()))
	{
		return false;
	}

	if (0 != strcmp(this->GetFileName(), tOther.GetFileName()))
	{
		return false;
	}
	if (this->GetVerLevel() != tOther.GetVerLevel())
	{
		return false;
	}

	if (this->GetFileSize() != tOther.GetFileSize())
	{
		return false;
	}

	return true;
}

inline bool CSusDevVerInfo::operator != ( const CSusDevVerInfo& tOther ) const
{
	 return !(*this == tOther);
}

inline u32 CSusDevVerInfo::Compare(const CSusDevVerInfo& tOther) const
{
	u32 dwDifferent = EmDiff_Nothing;
	
	if ( this->GetSn() != tOther.GetSn())
	{
		dwDifferent |=EmDiff_Sn;
	}
	
    if ( this->GetVerLevel() != tOther.GetVerLevel())
    {
        dwDifferent |= EmDiff_VerLevel;
    }
	
    if (this->GetOemMark() != tOther.GetOemMark())
    {
        dwDifferent |= EmDiff_OemMark;
    }
	
    if (0 != strcmp(this->GetDevType(), tOther.GetDevType()))
    {
        dwDifferent |= EmDiff_DevType;
    }
	
	if (this->GetReleaseAttribute() != tOther.GetReleaseAttribute())
	{
		dwDifferent |= EmDiff_ReleaseAttribute;
	}
	
    if (0 != strcmp(this->GetSoftVer(), tOther.GetSoftVer()))
    {
        dwDifferent |= EmDiff_SoftVer;
    }
	
    if (0 != strcmp(this->GetReleaseNotes(), tOther.GetReleaseNotes()))
    {
        dwDifferent |= EmDiff_ReleaseNotes;
    }
	
    if (0 != strcmp(this->GetFileName(), tOther.GetFileName()))
    {
        dwDifferent |= EmDiff_FileName;
    }
	
    if (this->GetFileSize() != tOther.GetFileSize())
    {
        dwDifferent |= EmDiff_FileSize;
    }

    if ( 0 != strcmp(this->GetGrayRange().GetE164List(), tOther.GetGrayRange().GetE164List())
        || 0 != strcmp(this->GetGrayRange().GetMoidList(), tOther.GetGrayRange().GetMoidList()) )
    {
        dwDifferent |= EmDiff_GrayRange;
    }
	
	return dwDifferent;

}

inline u32 CSusDevVerInfo::GetSn() const
{
	return m_dwSn;
}
inline void CSusDevVerInfo::SetSn(u32 dwSn)
{
	m_dwSn = dwSn;
}

inline COemMark CSusDevVerInfo::GetOemMark() const
{
	return m_tOemMark;
}

inline const s8* CSusDevVerInfo::GetOemMarkString() const
{
	return m_tOemMark.GetOemMarkString();
}

inline void CSusDevVerInfo::SetOemMark(const COemMark& tOemMark)
{
	m_tOemMark = tOemMark;
}

inline void CSusDevVerInfo::SetOemMark(const s8* szOemMark)
{
	m_tOemMark.SetOemMarkString(szOemMark);

}

inline const s8* CSusDevVerInfo::GetDevType() const
{
	return m_szDevType;

}

inline void CSusDevVerInfo::SetDevType(const s8* szDevType)
{
	if (NULL == szDevType)
	{
		memset(m_szDevType, 0, sizeof(m_szDevType));
		return;
	}

	strncpy(m_szDevType, szDevType, sizeof(m_szDevType) - 1);
	m_szDevType[sizeof(m_szDevType) - 1] = '\0';
}

inline CSusDevVerInfo::EMSusVerLevel CSusDevVerInfo::GetVerLevel() const
{
	return m_emVerLevel;
}

inline const s8* CSusDevVerInfo::GetVerLeveString() const
{
	switch(GetVerLevel())
	{
	case EmSusVerLevel_Important:
		return "重要";

	case EmSusVerLevel_Suggest:
		return "建议";

	case EmSusVerLevel_Normal:
		return "普通";

	default:
		return "Unknow";
	}

}

inline void CSusDevVerInfo::SetVerLevel(EMSusVerLevel dwLevel)
{
	m_emVerLevel = dwLevel;
}

inline BOOL32 CSusDevVerInfo::IsRecommend() const
{
	return m_emReleaseAttribute == EmSusVer_Recommend ? TRUE : FALSE ;
}

inline BOOL32 CSusDevVerInfo::IsGrayRelease() const
{
	return m_emReleaseAttribute == EmSusVer_GrayRelease ? TRUE : FALSE ;
}

inline BOOL32 CSusDevVerInfo::IsCommonVer() const
{
	return m_emReleaseAttribute == EmSusVer_Common ? TRUE : FALSE;
}

inline void CSusDevVerInfo::SetReleaseAttribute(EMReleaseAttribute wReleaseAttribute)
{
	m_emReleaseAttribute = wReleaseAttribute;
}

inline CSusDevVerInfo::EMReleaseAttribute CSusDevVerInfo::GetReleaseAttribute(void) const
{
	return m_emReleaseAttribute;
}

inline const s8* CSusDevVerInfo::GetSoftVer() const
{
	return m_szSoftVer;
}

inline void CSusDevVerInfo::SetSoftVer(const s8* szSoftVer)
{
	if (NULL == szSoftVer)
	{
		memset(m_szSoftVer, 0, sizeof(m_szSoftVer));
		return;
	}

	strncpy(m_szSoftVer, szSoftVer, sizeof(m_szSoftVer) - 1);
	m_szSoftVer[sizeof(m_szSoftVer) - 1] = '\0';
}

inline BOOL32 CSusDevVerInfo::IsSoftVerValid() const
{
	if (strlen(m_szSoftVer) > 0)
	{
		return TRUE;
	}

	return FALSE;
}

inline const s8* CSusDevVerInfo::GetReleaseNotes() const
{
	return m_szReleaseNotes;
}

inline void CSusDevVerInfo::SetReleaseNotes(const s8* szReleaseNotes)
{
	if (NULL == szReleaseNotes )
	{
		memset(m_szReleaseNotes, 0, sizeof(m_szReleaseNotes));
		return;
	}

	strncpy(m_szReleaseNotes, szReleaseNotes, sizeof(m_szReleaseNotes) - 1);
	m_szReleaseNotes[sizeof(m_szReleaseNotes) - 1] = '\0';
}

inline const s8* CSusDevVerInfo::GetFileName() const
{
	return m_szFileName;
}

inline void CSusDevVerInfo::SetFileName(const s8* szFileName)
{
	if (NULL == szFileName)
	{
		memset(m_szFileName, 0, sizeof(m_szFileName));
		return;
	}

	strncpy(m_szFileName, szFileName, sizeof(m_szFileName) -1);
	m_szFileName[sizeof(m_szFileName) - 1] ='\0';
}

inline const s8* CSusDevVerInfo::GetFileOnlyName() const          //只获取文件名称(不包含路径)
{
	//增加文件名称   
    s8 chFind = '\\';	
    const s8* szFind= strrchr(m_szFileName, chFind);
    if (NULL != szFind)
    {
        return szFind+1;
    }
    
    return m_szFileName;
}
inline u32 CSusDevVerInfo::GetFileSize() const
{
	return m_dwFileSize;
}

inline void CSusDevVerInfo::SetFileSize(const u32 dwSize)
{
	m_dwFileSize = dwSize;
}

#if ((defined _SUS_SERVER_) || (defined _SUS_MGR_)) 
inline std::string CSusDevVerInfo::GetSusSaveFileDir( ) const
{
    std::string strFilePath;
	
    strFilePath += VER_FILE_START_PATH;
    strFilePath += GetOemMarkString();
#ifdef _LINUX_
	strFilePath += "/";
    strFilePath += GetDevType();
    strFilePath += "/";
    strFilePath += GetSoftVer();    
#else
	strFilePath += "\\";
    strFilePath += GetDevType();
    strFilePath += "\\";
    strFilePath += GetSoftVer();
#endif
    
    return strFilePath;
}

inline std::string CSusDevVerInfo::GetSusSaveFileName( ) const
{
    std::string strFilePath = GetSusSaveFileDir();
	
#ifdef _LINUX_
    strFilePath += "/";    
#else
    strFilePath += "\\";
#endif
	
    //增加文件名称   
    s8 chFind = '\\';	
    const s8* szFind= strrchr(m_szFileName, chFind);
    if (NULL != szFind)
    {
        strFilePath += szFind+1;
	}
    else
    {
        strFilePath += GetFileName();
    }
    
    return strFilePath;
}          


#endif  //end _SUS_SERVER_  _SUS_MGR_

#ifdef _XML_CONVERT_
inline TIXML_STRING CSusDevVerInfo::StructToXml() const 
{
	CXmlStructConvert xmltool;
	BOOL32 bRet = xmltool.InitStructToXml();
	if( !bRet )
	{
		TIXML_STRING strEmpty;
		return strEmpty;
	}
	   
	xmltool.AddSiblingElementAndValue( "m_dwSn", m_dwSn );
	xmltool.AddNestedSiblingElement( "m_tOemMark", m_tOemMark );
	xmltool.AddSiblingElementAndValue( "m_szDevType", m_szDevType );
	xmltool.AddSiblingElementAndValue( "m_emVerLevel", m_emVerLevel );    
	xmltool.AddSiblingElementAndValue( "m_szSoftVer", m_szSoftVer );
	xmltool.AddSiblingElementAndValue( "m_emReleaseAttribute", m_emReleaseAttribute );
    xmltool.AddSiblingElementAndValue( "m_szReleaseNotes", m_szReleaseNotes );
	xmltool.AddSiblingElementAndValue( "m_szFileName", m_szFileName );
	xmltool.AddSiblingElementAndValue( "m_dwFileSize", m_dwFileSize );
    xmltool.AddNestedSiblingElement( "m_tGrayRange", m_tGrayRange );
	   
	TIXML_STRING xmlStr = xmltool.ConvertXMLToString();
	return xmlStr;
}

inline BOOL32 CSusDevVerInfo::XmlToStruct(const char* xmlString)
{
	CXmlStructConvert xmltool;
    BOOL32 bRet = xmltool.InitXmlToStruct( xmlString );
    if( bRet == FALSE )
    {
        return FALSE;
    }
    
	u32 dwTemp = 0;
    xmltool.GetValueByElementName( "m_dwSn", dwTemp );
	SetSn(dwTemp);
	
	dwTemp = 0;
    xmltool.GetValueByElementName( "m_emVerLevel", dwTemp );
	SetVerLevel((EMSusVerLevel)dwTemp);
	
	dwTemp = 0;
    xmltool.GetValueByElementName( "m_dwFileSize", dwTemp );
    SetFileSize(dwTemp);

	u16 wTemp = 0;
	xmltool.GetValueByElementName( "m_emReleaseAttribute", wTemp );
	SetReleaseAttribute((EMReleaseAttribute)wTemp);
	
	xmltool.GetNestedSiblingElement( xmlString, "m_tOemMark",  m_tOemMark );
	xmltool.GetValueByElementName("m_szDevType", m_szDevType,sizeof(m_szDevType) );
	xmltool.GetValueByElementName( "m_szSoftVer", m_szSoftVer, sizeof(m_szSoftVer) );
    xmltool.GetValueByElementName( "m_szReleaseNotes", m_szReleaseNotes, sizeof(m_szReleaseNotes) );
    xmltool.GetValueByElementName( "m_szFileName", m_szFileName, sizeof(m_szFileName) );
    xmltool.GetNestedSiblingElement( xmlString, "m_tGrayRange", m_tGrayRange );

    return TRUE;
}
#endif	//_XML_CONVERT_

typedef CKdvpList<CSusDevVerInfo, MAXNUM_SUS_DEVVER> CDeviceVerList;


#ifdef WIN32
#pragma pack( pop )
#endif

#endif // end of _STRUCT_DEVICE_VER_H
