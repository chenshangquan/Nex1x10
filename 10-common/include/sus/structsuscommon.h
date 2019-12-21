
/*=======================================================================
模块名      :SUS
文件名      :structsuscommon.h
相关文件    :
文件实现功能:SUS通用通信结构体定义

作者        : 
版本        : V1.0  Copyright(C) 2005-2010 Suzhou Keda Technology Co.Ltd
              All rights reserved.
--------------------------------------------------------------------------
修改记录:
日  期      版本        修改人      修改内容
2012/02/22  1.0					      创建
=======================================================================*/


#ifndef _STRUCT_SUS_COMMON_H_
#define _STRUCT_SUS_COMMON_H_

#include <vector>
#include <string>
#include "structtassus.h"
#include "constsus.h"
#include "structdevicever.h"


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




class CSusQueryCondition
{
public:
    enum EmQueryMask
    {
        EmQueryMask_NULL                = 0x00000000, 
        EmQueryMask_SN                  = 0x00000001, 
        EmQueryMask_OemMarkLsit         = 0x00000002, 
        EmQueryMask_DevType             = 0x00000004, 
        EmQueryMask_ReleaseAttribute    = 0x00000008, 
        EmQueryMask_SoftVer             = 0x00000010, 
    };

//     enum EmVerAttribute		//版本发布属性条件标识
//     {
//         EmVerAttribute_Null             = 0x0000,
//         EmVerAttribute_Common           = 0x0001,
//         EmVerAttribute_Recommend        = 0x0002,
//         EmVerAttribute_GrayRelease      = 0x0004	
//     };

public:
    CSusQueryCondition();
    void Init();

    u32 GetSn() const;
    void SetSn(u32 dwSn);
    BOOL32 IsQueryBySn() const;
    
    COemMarkList GetOemMarkList() const;
    void SetOemMarkList(const COemMarkList& tOemMark);
    void SetOemMarkList(const COemMark& tOemMark);
    BOOL32 IsQueryByMarkList() const;
   
    const s8* GetDevType() const;
    void SetDevType(const s8* szType);
    BOOL32 IsQueryByDevType() const;
    
    const s8* GetSoftVer() const;
    void SetSoftVer(const s8* szSoftVer);
    BOOL32 IsQueryBySoftVer() const;
    
	void SetReleaseAttribute(CSusDevVerInfo::EMReleaseAttribute wReleaseAttribute);
	void AddReleaseAttribute(CSusDevVerInfo::EMReleaseAttribute wReleaseAttribute);
    void DelReleaseAttribute(CSusDevVerInfo::EMReleaseAttribute wReleaseAttribute);
    u16  GetReleaseAttribute() const;
    BOOL32 IsQueryByReleaseAttribute() const;



private:
    u32 m_dwQueryMask;  //查询条件标识

    u32 m_dwSn;  //版本序列号(全局唯一标识)
    COemMarkList m_tOemMarkList;    //版本OEM标识
    s8 m_szDevType[MAXLEN_SUS_DEV_NAME + 1];	//版本所属设备类型
	u16 m_wReleaseAttribute;	//版本发布属性
    s8 m_szSoftVer[MAXLEN_SUS_SOFTVER + 1];	//软件版本号
}PACKED;

inline CSusQueryCondition::CSusQueryCondition()
{
    Init();
}

inline void CSusQueryCondition::Init()
{
    m_dwQueryMask = EmQueryMask_NULL;
    m_dwSn = 0;
	m_wReleaseAttribute = CSusDevVerInfo::EmSusVer_Begin;
    memset(m_szDevType, 0, sizeof(m_szDevType));
    memset(m_szSoftVer, 0, sizeof(m_szSoftVer));
}

inline u32 CSusQueryCondition::GetSn() const 
{ 
    return m_dwSn; 
}

inline void CSusQueryCondition::SetSn(u32 dwSn) 
{ 
    m_dwSn = dwSn;    
    m_dwQueryMask |= EmQueryMask_SN;
}

inline BOOL32 CSusQueryCondition::IsQueryBySn() const
{
    if(m_dwQueryMask & EmQueryMask_SN)
    {
        return TRUE;
    }

    return FALSE;
}


inline COemMarkList CSusQueryCondition::GetOemMarkList() const 
{ 
    return m_tOemMarkList; 
}

inline void CSusQueryCondition::SetOemMarkList(const COemMarkList& tOemMark) 
{ 
    m_tOemMarkList = tOemMark; 
    m_dwQueryMask |= EmQueryMask_OemMarkLsit;
}

inline void CSusQueryCondition::SetOemMarkList(const COemMark& tOemMark) 
{
    m_tOemMarkList.Init();
	m_tOemMarkList.Append(tOemMark);
    m_dwQueryMask |= EmQueryMask_OemMarkLsit;
}


inline BOOL32 CSusQueryCondition::IsQueryByMarkList() const
{
    if(m_dwQueryMask & EmQueryMask_OemMarkLsit)
    {
        return TRUE;
    }
    
    return FALSE;
}

inline void CSusQueryCondition::SetReleaseAttribute(CSusDevVerInfo::EMReleaseAttribute wReleaseAttribute)
{
	m_wReleaseAttribute &= CSusDevVerInfo::EmSusVer_Begin;

	if (CSusDevVerInfo::EmSusVer_Begin != wReleaseAttribute)
	{
		m_wReleaseAttribute |= wReleaseAttribute;
		m_dwQueryMask |= EmQueryMask_ReleaseAttribute;
    }
    else
    {
        m_dwQueryMask &= ~EmQueryMask_ReleaseAttribute;
    }
}

inline void CSusQueryCondition::AddReleaseAttribute(CSusDevVerInfo::EMReleaseAttribute wReleaseAttribute)
{
    if (CSusDevVerInfo::EmSusVer_Begin != wReleaseAttribute)
    {
        m_wReleaseAttribute |= wReleaseAttribute;
        m_dwQueryMask |= EmQueryMask_ReleaseAttribute;
    }
}

inline void CSusQueryCondition::DelReleaseAttribute(CSusDevVerInfo::EMReleaseAttribute wReleaseAttribute)
{
    m_wReleaseAttribute &= ~wReleaseAttribute;
    
    if (CSusDevVerInfo::EmSusVer_Begin == m_wReleaseAttribute)
    {
        m_dwQueryMask &= ~EmQueryMask_ReleaseAttribute;
    }
}

inline u16 CSusQueryCondition::GetReleaseAttribute() const
{
	return m_wReleaseAttribute;
}

inline BOOL32 CSusQueryCondition::IsQueryByReleaseAttribute() const
{
    if(m_dwQueryMask & EmQueryMask_ReleaseAttribute)
    {
        return TRUE;
    }
    
    return FALSE;
}

inline const s8* CSusQueryCondition::GetDevType() const 
{ 
    return m_szDevType; 
}

inline void CSusQueryCondition::SetDevType(const s8* szType) 
{ 
    if (NULL == szType)
    {
		memset(m_szDevType, 0, sizeof(m_szDevType));
		return;
    }

	strncpy(m_szDevType, szType, sizeof(m_szDevType) - 1);
	m_szDevType[sizeof(m_szDevType) - 1] = '\0';

    m_dwQueryMask |= EmQueryMask_DevType;
}

inline BOOL32 CSusQueryCondition::IsQueryByDevType() const
{
    if(m_dwQueryMask & EmQueryMask_DevType)
    {
        return TRUE;
    }
    
    return FALSE;
}

inline const s8* CSusQueryCondition::GetSoftVer() const 
{
    return m_szSoftVer; 
}


inline void CSusQueryCondition::SetSoftVer(const s8* szSoftVer) 
{
    if (NULL == szSoftVer)
    {
        memset(m_szSoftVer, 0, sizeof(m_szSoftVer));
        return;
    }
    
    strncpy( m_szSoftVer, szSoftVer, sizeof(m_szSoftVer)-1 );
    m_szSoftVer[sizeof(m_szSoftVer)-1] = '\0'; 

    m_dwQueryMask |= EmQueryMask_SoftVer;
}

inline BOOL32 CSusQueryCondition::IsQueryBySoftVer() const
{
    if(m_dwQueryMask & EmQueryMask_SoftVer)
    {
        return TRUE;
    }
    
    return FALSE;
}



#ifdef WIN32
#pragma pack( pop )
#endif


#endif // _STRUCT_SUS_COMMON_H_
// END FILE



