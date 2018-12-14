/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   �����ڴ����ӿڷ�װ
 * @author  �Ĵ���
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * 
 */
/*---------------------------------------------------------------------------*/



#ifndef _SHAREDMEMORYBLOCK_H_
#define _SHAREDMEMORYBLOCK_H_

#include <string>
#include "kdvtype.h"
#include "osp.h"
#include "mtmacro.h"

#if (defined _WIN32_P_) || (defined WIN32 )

	typedef PVOID IPC_SEMHANDLE;

	const HANDLE MT_INVALID_IPC_SEMHANDLE = NULL;

#endif

#ifdef _LINUX_

	typedef int IPC_SEMHANDLE;

	const s32 MT_INVALID_IPC_SEMHANDLE = -1;
	const s32 MT_IPC_SEM_FAILED = -1;

#endif


namespace MTUTILS
{
	/*---------------------------------------------------------------------------*/
	/**
	 * 
	 * @brief ������ź����Ŀ�ƽ̨�ӿڷ�װ
	 * @version $Revision$
	 * @data $Date$
	 */
	/*---------------------------------------------------------------------------*/
	class MTCBB_API CIPCMutexSem
	{

	public:

		/** ***********************************************************
		* 
		* @brief  ���캯��
		*
		* @param	[in] strName   �ź�����������
		* @param	[in] bCreate  (TRUE�������µ��ź���  FALSE: ���Ѵ��ڵ��ź���) 
		*
		* @return	��
		*
		**************************************************************/
		CIPCMutexSem(std::string strName, BOOL32 bCreate = FALSE);
		~CIPCMutexSem();

	public:

		/** ***********************************************************
		* 
		* @brief  �ж��ź����Ƿ���Ч
		*
		* @param	[in] ��
		*
		* @return	TRUE: ��Ч    FALSE:��Ч
		*
		**************************************************************/
		BOOL32 IsValidSem(){ return (m_hSem != MT_INVALID_IPC_SEMHANDLE); }

		/** ***********************************************************
		* 
		* @brief  �ź���take���� 
		*
		* @param	[in] ��
		*
		* @return	TRUE: �ɹ�    FALSE:ʧ��
		*
		**************************************************************/
		BOOL32 TakeSem();

		/** ***********************************************************
		* 
		* @brief  �ź���give���� 
		*
		* @param	[in] ��
		*
		* @return	TRUE: �ɹ�    FALSE:ʧ��
		*
		**************************************************************/
		BOOL32 GiveSem();

	private:
		IPC_SEMHANDLE m_hSem;
		std::string m_strName;

	};



	/*---------------------------------------------------------------------------*/
	/**
	 * @class Class CSharedMemoryBlock
	 * @brief �����ڴ�����ƽ̨�ӿڷ�װ
	 * @version $Revision$
	 * @data $Date$
	 */
	/*---------------------------------------------------------------------------*/
	class MTCBB_API CSharedMemoryBlock
	{
	public:

		/** ***********************************************************
		* 
		* @brief    ���캯��
		*
		* @param	[in] strName �����ڴ������
		* @param	[in] dwSize  �����ڴ���С
		*
		* @return	��
		*
		**************************************************************/
		CSharedMemoryBlock(std::string strName, u32 dwSize);
		~CSharedMemoryBlock();


		/** ***********************************************************
		* 
		* @brief    ���乲���ڴ�
		*
		* @param	[in] bReadOnly ������ڴ��Ƿ�ֻ��
		*
		* @return	MT_SUCCESS  ����ɹ�
		*           MT_FAILED   ����ʧ��
		**************************************************************/
		u32 Attach(BOOL32 bReadOnly = FALSE);


		/** ***********************************************************
		* 
		* @brief    �ͷ��ѷ��乲���ڴ�
		*
		* @param	��
		*
		* @return	MT_SUCCESS  �ɹ�
		*           MT_FAILED   ʧ��
		**************************************************************/
		u32 Detach();


		/** ***********************************************************
		* 
		* @brief    ��ȡ�ѷ��乲���ڴ����ʼ��ַ
		*
		* @param	��
		*
		* @return	NULL   ʧ��
		*           ����   �ɹ�
		**************************************************************/
		inline u8* GetBase()
		{ 
			return m_pbyBase; 
		}


		/** ***********************************************************
		* 
		* @brief    ��ȡ�ѷ��乲���ڴ����ʼ��ַ
		*
		* @param	��
		*
		* @return	NULL   ʧ��
		*           ����   �ɹ�
		**************************************************************/
		inline const u8* GetBase() const
		{
			return m_pbyBase;
		}


		/** ***********************************************************
		* 
		* @brief    ��ȡ�ѷ��乲���ڴ�Ĵ�С
		*
		* @param	��
		*
		* @return	u32 �����ڴ�Ĵ�С
		*           
		**************************************************************/
		inline u32 GetSize() const
		{
			return m_dwSize;
		}



		/** ***********************************************************
		* 
		* @brief    ��ȡ�ѷ��乲���ڴ�ı���
		*
		* @param	��
		*
		* @return	�����ڴ�ı���
		*           
		**************************************************************/
		inline std::string GetName() const
		{
			return m_strName;
		}

	private:
		u8 *m_pbyBase;  ///< �����ڴ���ʼ��ַ
		u32 m_dwSize;	///< �����ڴ��С
		
#ifdef _LINUX_
		s32 m_hHandle;		///< Linux�����ڴ�ı�ʶ��
#else
		HANDLE m_hHandle;	///< Windows�����ڴ�ľ��
#endif
		std::string m_strName;	///< �����ڴ����
	};
}

#endif  //_SHAREDMEMORYBLOCK_H_