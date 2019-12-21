/*******************************************************************************//**
*@file          nvapi_sdkmsg.h
*@brief         ���ڶ����Ϣ��Ķ�д
*
*@author        youjiaxing
*@version       1.0    
*@date          20180612
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _NVAPISDKMSG_H_
#define _NVAPISDKMSG_H_
/**@addtogroup common ���ݽṹ
*@{
*/

/**@addtogroup other ��
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
*@author        youjiaxing
*@version       1.0    
*@date          20180612	
*@note          
***********************************************************************************/
class CNvSdkMsg
{
public:
	CNvSdkMsg()
	{
		m_wWritePos = 0;
		m_wReadPos  = 0;
	}

	~CNvSdkMsg()
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
    *@author        youjiaxing   
    *@date          20180612
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
    *@author        youjiaxing    
    *@date          20180612
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

	/*******************************************************************************//**
    *@brief         �������
    *
    *
    *@author        youjiaxing    
    *@date          20180612
    *@return        �ɹ�����TRUE,ʧ�ܷ���FALSE
    *@note          
    ***********************************************************************************/
	BOOL32 clear()
	{
		m_wWritePos = 0;
		m_wReadPos = 0;
		memset(m_abyBuf, 0, sizeof(m_abyBuf));
		return TRUE;
	}

private:
	u8                       m_abyBuf[MAX_SDKMSG_LEN];
	u16                      m_wWritePos;
	u16                      m_wReadPos;
};
#endif
#endif