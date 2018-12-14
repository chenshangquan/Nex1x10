/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   共享内存分配接口封装
 * @author  瞿戴沣
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
	 * @brief 跨进程信号量的跨平台接口封装
	 * @version $Revision$
	 * @data $Date$
	 */
	/*---------------------------------------------------------------------------*/
	class MTCBB_API CIPCMutexSem
	{

	public:

		/** ***********************************************************
		* 
		* @brief  构造函数
		*
		* @param	[in] strName   信号量对象名称
		* @param	[in] bCreate  (TRUE：创建新的信号量  FALSE: 打开已存在的信号量) 
		*
		* @return	无
		*
		**************************************************************/
		CIPCMutexSem(std::string strName, BOOL32 bCreate = FALSE);
		~CIPCMutexSem();

	public:

		/** ***********************************************************
		* 
		* @brief  判断信号量是否有效
		*
		* @param	[in] 无
		*
		* @return	TRUE: 有效    FALSE:无效
		*
		**************************************************************/
		BOOL32 IsValidSem(){ return (m_hSem != MT_INVALID_IPC_SEMHANDLE); }

		/** ***********************************************************
		* 
		* @brief  信号量take操作 
		*
		* @param	[in] 无
		*
		* @return	TRUE: 成功    FALSE:失败
		*
		**************************************************************/
		BOOL32 TakeSem();

		/** ***********************************************************
		* 
		* @brief  信号量give操作 
		*
		* @param	[in] 无
		*
		* @return	TRUE: 成功    FALSE:失败
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
	 * @brief 共享内存分配跨平台接口封装
	 * @version $Revision$
	 * @data $Date$
	 */
	/*---------------------------------------------------------------------------*/
	class MTCBB_API CSharedMemoryBlock
	{
	public:

		/** ***********************************************************
		* 
		* @brief    构造函数
		*
		* @param	[in] strName 共享内存块名称
		* @param	[in] dwSize  共享内存块大小
		*
		* @return	无
		*
		**************************************************************/
		CSharedMemoryBlock(std::string strName, u32 dwSize);
		~CSharedMemoryBlock();


		/** ***********************************************************
		* 
		* @brief    分配共享内存
		*
		* @param	[in] bReadOnly 分配的内存是否只读
		*
		* @return	MT_SUCCESS  分配成功
		*           MT_FAILED   分配失败
		**************************************************************/
		u32 Attach(BOOL32 bReadOnly = FALSE);


		/** ***********************************************************
		* 
		* @brief    释放已分配共享内存
		*
		* @param	无
		*
		* @return	MT_SUCCESS  成功
		*           MT_FAILED   失败
		**************************************************************/
		u32 Detach();


		/** ***********************************************************
		* 
		* @brief    获取已分配共享内存的起始地址
		*
		* @param	无
		*
		* @return	NULL   失败
		*           其他   成功
		**************************************************************/
		inline u8* GetBase()
		{ 
			return m_pbyBase; 
		}


		/** ***********************************************************
		* 
		* @brief    获取已分配共享内存的起始地址
		*
		* @param	无
		*
		* @return	NULL   失败
		*           其他   成功
		**************************************************************/
		inline const u8* GetBase() const
		{
			return m_pbyBase;
		}


		/** ***********************************************************
		* 
		* @brief    获取已分配共享内存的大小
		*
		* @param	无
		*
		* @return	u32 共享内存的大小
		*           
		**************************************************************/
		inline u32 GetSize() const
		{
			return m_dwSize;
		}



		/** ***********************************************************
		* 
		* @brief    获取已分配共享内存的别名
		*
		* @param	无
		*
		* @return	共享内存的别名
		*           
		**************************************************************/
		inline std::string GetName() const
		{
			return m_strName;
		}

	private:
		u8 *m_pbyBase;  ///< 共享内存起始地址
		u32 m_dwSize;	///< 共享内存大小
		
#ifdef _LINUX_
		s32 m_hHandle;		///< Linux共享内存的标识符
#else
		HANDLE m_hHandle;	///< Windows共享内存的句柄
#endif
		std::string m_strName;	///< 共享内存别名
	};
}

#endif  //_SHAREDMEMORYBLOCK_H_