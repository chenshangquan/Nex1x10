/**===========================================================================
 * @file    sysctrlloadlib.h 
 * @brief   系统控制加载静态库处理
 * @author  wangfeifei
 * @date    
 * @version  
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _NVSYSCTRLLOADLIB_H_
#define _NVSYSCTRLLOADLIB_H_

#include "nvmacro.h"
#include "kdvtype.h"
#include "osp.h"
#include "nvconst.h"
#include "nvstruct.h"

/* 启动函数 */
typedef BOOL32 (*PFStartFunc)(TMdlStartParam &tMdlStartParam);

/* 结束函数 */
typedef BOOL32 (*PFEndFunc)(/*void *pvParam*/);

/* 用于保存加载的静态库的别名，对应启动函数，结束函数  */
typedef struct tagTNVSysStaticLibInfo
{
	s8			achAlias[NV_STR_LEN_32+1];		///< 子系统别名
	PFStartFunc pfStartFunc;					///< 启动函数指针
	PFEndFunc	pfEndFunc;						///< 结束函数指针

public:

	tagTNVSysStaticLibInfo() { memset( this, 0, sizeof(tagTNVSysStaticLibInfo) ); }

}TNVSysStaticLibInfo, *PTTNVSysStaticLibInfo; 

/* TNVSysSrvInfo的列表  */
typedef struct tagTNVSysStaticLibList
{
	/* 这里的数量，也即索引号 */
	u32		dwNum;									///< 已绑定的数量
	TNVSysStaticLibInfo	atNVSysStaticLibInfo[NV_SYS_NUM_MAX];	///< 多个TNVsysStaticLibInfo

public:

	tagTNVSysStaticLibList() { memset( this, 0, sizeof(tagTNVSysStaticLibList) ); }

}TNVSysStaticLibList, *PTTNVSysStaticLibList; 


/* 用于处理加载静态库 */
class CSysCtrlLoadLib
{

public:

	/** ************************************************************
	* CSysCtrlLoadLib 
	* 
	* @brief	 构造函数
	* 
	* @param	无
	************************************************************* */
	CSysCtrlLoadLib();

	/** ************************************************************
	* ~CSysCtrlLoadLib 
	* 
	* @brief	 析构函数
	* 
	* @param	无
	************************************************************* */
	~CSysCtrlLoadLib();

public:

	/** ************************************************************
 	* @brief	GetInstance
 	* 
 	* @brief    获取类指针
 	* 
 	* @param    无
	* @return	CSysCtrlLoadLib	类指针
	************************************************************* */
NVCBB_API 	static CSysCtrlLoadLib* GetInstance();

	/** ************************************************************
 	* @brief	OnAdd
 	* 
 	* @brief    添加静态库的信息
 	* 
 	* @param   [in]		achAlias：子系统别名
	*		   [in]		pfStartFunc：启动函数指针
	*		   [in]		pfEndFunc：结束函数指针
	* @return	BOOL32	是否添加成功
	************************************************************* */
NVCBB_API	BOOL32	OnAdd(const s8* pchAlias, PFStartFunc pfStartFunc, PFEndFunc pfEndFunc);


	/** ************************************************************
 	* @brief	GetStaticLibNum
 	* 
 	* @brief    获取已绑定的静态库的总数
 	* 
 	* @param    无
	* @return	u32		已绑定的静态库的总数
	************************************************************* */
	u32		GetStaticLibNum();


	/** ************************************************************
 	* @brief	GetStaticLibList
 	* 
 	* @brief    获取保存已绑定的静态库的数组指针
 	* 
 	* @param    无
	* @return	TNVSysSrvList*	已绑定的静态库的数组指针
	************************************************************* */
	TNVSysStaticLibList*	GetStaticLibList();

	void Clear();


private:

	/* 这是一个单例，保存了当前类的指针 */
	static CSysCtrlLoadLib* m_pCLoadlibPointer;

	/* 用于保存各个子系统需要绑定的静态库信息 */
	TNVSysStaticLibList m_tNVSysStaticLibList;

};


#endif // _NVSYSCTRLLOADLIB_H_