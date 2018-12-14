/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   线程阻塞查询接口封装
 * @author  瞿戴沣
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * 
 */
/*---------------------------------------------------------------------------*/


#ifndef _MTBLOCKMANAGER_H_
#define _MTBLOCKMANAGER_H_

#include "kdvtype.h"
#include "mtmacro.h"
/******************************************************************************
* @namespace    MTUTILS
******************************************************************************/
namespace MTUTILS {


class MTCBB_API CRegBlockInfo
{
public:
	CRegBlockInfo();
	~CRegBlockInfo();

public:

	/*!**********************************************************
	* 
	* @brief   注册阻塞接口信息
	*
	* @param   [in] pchInterfaceInfo:  该接口的详细描述信息
	*
	* @return  MT_SUCCESS: 成功  
			   MT_FAILED:  失败
	*************************************************************/
	u32 RegBlockInfo(s8 *pchInterfaceInfo, ...);


	/*!**********************************************************
	* 
	* @brief   注销阻塞接口信息 (未手动调用的话会在变量析构时执行)
	*
	* @param   [in] 无
	* 
	* @return  MT_SUCCESS: 成功  
			   MT_FAILED:  失败
	*************************************************************/
	u32 UnRegBlockInfo();

private:
	s32 m_nBlockId;
	BOOL32 m_bReged;
};


/*!**********************************************************
* @fn      u32 BlkRegTskIdName(u32 dwThreadId, const s8 *pchTskName)
* @brief   注册任务ID与名称的关联信息
* @param   [in] dwThreadId:  线程ID
* @param   [in] pchTskName:   APP名称
* @return  MT_SUCCESS: 成功  
           MT_FAILED: 失败
*************************************************************/
u32 BlkRegTskIdName(u32 dwThreadId, const s8 *pchTskName);


typedef s32 (*PRINTFUNC)(const char *szFormat, ...);

/*!**********************************************************
* @fn      void BlkSetPrintFunc(PRINTFUNC pfPrintFunc);
* @brief   设置线程阻塞信息打印接口
* @param   [in] 打印接口函数指针
* @return  无
*************************************************************/
MTCBB_API void BlkSetPrintFunc(PRINTFUNC pfPrintFunc);


/*!**********************************************************
* @fn      u32 BlkGetBlockInfo(s8 achBuf[], u32 dwLen, u32 &dwOutLen)
* @brief   获取当前线程阻塞信息
* @param   [in] achBuf:    信息缓冲区  
* @param   [in] dwLen:     缓冲区长度
* @param   [in] dwOutLen:  获取的信息的实际长度
* @return  MT_SUCCESS: 成功  
           MT_FAILED: 失败
*************************************************************/
u32 BlkGetBlockInfo(s8 achBuf[], u32 dwLen, u32 &dwOutLen);


/*!**********************************************************
* @fn      void BlkShowBlockInfo()
* @brief   调用指定的打印函数接口打印出线程阻塞信息
* @return  无
*************************************************************/
MTCBB_API void BlkShowBlockInfo();

}



#endif //_MTBLOCKMANAGER_H_