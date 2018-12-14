/*******************************************************************************//**
*@file          mtapi_sdkmsg.h
*@brief         用于多个消息体的读写
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPISDKMSG_H_
#define _MTAPISDKMSG_H_
/**@addtogroup common 公用
*@{
*/

/**@addtogroup other 其他
*@{
*/

#include <queue>
#include "kdvtype.h"

#define MAX_SDKMSG_LEN (24 * 1024)

#if defined(__cplusplus)

/*******************************************************************************//**
*@class         CSdkMsg
*@brief         用于多个消息体的读写
*
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328	
*@note          
***********************************************************************************/
class CSdkMsg
{
public:
	CSdkMsg()
	{
		m_wWritePos = 0;
		m_wReadPos  = 0;
	}

	~CSdkMsg()
	{

	}

	void* GetBuffer(u16 &wBufLen)
	{
		if (0 == m_wWritePos)
		{
			return NULL;
		}

		wBufLen = m_wWritePos;

		return m_abyBuf;
	}

	BOOL32 SetBuffer(const void *pvBuf, const u16 wBufLen)
	{
		if (wBufLen > sizeof(m_abyBuf))
		{
			return FALSE;
		}

		memcpy(m_abyBuf, pvBuf, wBufLen);

		m_wReadPos  = 0;
		m_wWritePos = wBufLen;

		return TRUE;
	}

    /*******************************************************************************//**
    *@brief         写一个消息体
    *
    *
    *@author        ruiyigen   
    *@date          20150328
    *@param[in]     pvBody 消息体头指针
    *@param[in]     wLen   消息体长度
    *@return        成功返回TRUE,失败返回FALSE
    *@note          
    ***********************************************************************************/
	BOOL32 Write(void *pvBody, u16 wLen)
	{
		if ((m_wWritePos + wLen) > sizeof(m_abyBuf))
		{
			return FALSE;
		}

		memcpy(m_abyBuf + m_wWritePos, pvBody, wLen);

		m_wWritePos += wLen;	

		return TRUE;
	}

	/*******************************************************************************//**
    *@brief         读一个消息体
    *
    *
    *@author        ruiyigen   
    *@date          20150328
    *@param[inout]  pvBuf     指向一块buffer，用于接收一个消息体
    *@param[inout]  wLen      读的大小
    *@return        成功返回TRUE,失败返回FALSE
    *@note          
    ***********************************************************************************/
	BOOL32 Read(void *pvBuf, u16 wLen)
	{
		if ((m_wReadPos + wLen) > sizeof(m_abyBuf))
		{
			return FALSE;
		}

		memcpy(pvBuf, m_abyBuf + m_wReadPos, wLen);

		m_wReadPos += wLen;

		return TRUE;
	}

private:
	u8                       m_abyBuf[MAX_SDKMSG_LEN];
	u16                      m_wWritePos;
	u16                      m_wReadPos;
};

template < class T >
T SAFE_CAST( T &t, u8 *p )
{
	if (NULL == p) return t;
	memcpy( &t, p, sizeof( T ) );
	return t;
}

#endif // __cplusplus

//对于C语言的话可以直接使用下面两个宏处理一块buffer中的多个body
/*******************************************************************************//**
*@brief         添加一个消息体
*
*
*@author        ruiyigen   
*@date          20150328
*@param[inout]  pbyBuf   buffer头指针
*@param[in]     pbyBody  消息体头指针
*@param[in]     wBodyLen 消息体长度        
***********************************************************************************/
#define WRITE_BODY(pbyBuf, pbyBody, wBodyLen) memcpy(pbyBuf, pbyBody, wBodyLen)

/*******************************************************************************//**
*@brief         读取一个消息体
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     pbyBuf   buffer头指针
*@param[inout]  pbyBody  消息体头指针
*@param[in]     wBodyLen 消息体长度          
***********************************************************************************/
#define READ_BODY(pbyBuf, pbyBody, wBodyLen)  memcpy(pbyBody, pbyBuf, wBodyLen)

/**@}*/

/**@}*/
#endif // _MTAPISDKMSG_H_