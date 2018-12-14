/*******************************************************************************//**
*@file          mtapi_sdkmsg.h
*@brief         ���ڶ����Ϣ��Ķ�д
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPISDKMSG_H_
#define _MTAPISDKMSG_H_
/**@addtogroup common ����
*@{
*/

/**@addtogroup other ����
*@{
*/

#include <queue>
#include "kdvtype.h"

#define MAX_SDKMSG_LEN (24 * 1024)

#if defined(__cplusplus)

/*******************************************************************************//**
*@class         CSdkMsg
*@brief         ���ڶ����Ϣ��Ķ�д
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
    *@brief         дһ����Ϣ��
    *
    *
    *@author        ruiyigen   
    *@date          20150328
    *@param[in]     pvBody ��Ϣ��ͷָ��
    *@param[in]     wLen   ��Ϣ�峤��
    *@return        �ɹ�����TRUE,ʧ�ܷ���FALSE
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
    *@brief         ��һ����Ϣ��
    *
    *
    *@author        ruiyigen   
    *@date          20150328
    *@param[inout]  pvBuf     ָ��һ��buffer�����ڽ���һ����Ϣ��
    *@param[inout]  wLen      ���Ĵ�С
    *@return        �ɹ�����TRUE,ʧ�ܷ���FALSE
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

//����C���ԵĻ�����ֱ��ʹ�����������괦��һ��buffer�еĶ��body
/*******************************************************************************//**
*@brief         ���һ����Ϣ��
*
*
*@author        ruiyigen   
*@date          20150328
*@param[inout]  pbyBuf   bufferͷָ��
*@param[in]     pbyBody  ��Ϣ��ͷָ��
*@param[in]     wBodyLen ��Ϣ�峤��        
***********************************************************************************/
#define WRITE_BODY(pbyBuf, pbyBody, wBodyLen) memcpy(pbyBuf, pbyBody, wBodyLen)

/*******************************************************************************//**
*@brief         ��ȡһ����Ϣ��
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     pbyBuf   bufferͷָ��
*@param[inout]  pbyBody  ��Ϣ��ͷָ��
*@param[in]     wBodyLen ��Ϣ�峤��          
***********************************************************************************/
#define READ_BODY(pbyBuf, pbyBody, wBodyLen)  memcpy(pbyBody, pbyBuf, wBodyLen)

/**@}*/

/**@}*/
#endif // _MTAPISDKMSG_H_