#ifndef _MTDSC_H_
#define _MTDSC_H_
#include <string>
#include "kdvtype.h"
#include "mtdscommon.h"
#include "mtmacro.h"

/**----------------------------------------------------------------------
* mtDscSet
* 
* @brief   写入一条数据到数据共享服务器
* 
* @param   [in] strKey 数据的key
* @param   [in] pData  一块buf，包含待写入的数据
* @param   [in] dwSize 待写入的数据大小
* @return  BOOL32 DSE_OK:成功处理 DSE_ERROR:写入失败
------------------------------------------------------------------------*/
MTCBB_API u32 mtDscSet(KEY strKey, void *pData, u32 dwSize);

/**----------------------------------------------------------------------
* mtDscGet
* 
* @brief   从数据共享服务器读取一条数据
* 
* @param   [in] strKey 数据的key
* @param   [inout] pData  一块buf，用于接收数据
* @param   [inout] dwSize 传入时为pData对应buf的大小，返回时为得到数据的实际大小
* @return  BOOL32 DSE_OK:成功处理 DSE_BUF:传入的buf太小，此时dwSize会返回实际需要的大小 DSE_ERROR:其他失败情况
------------------------------------------------------------------------*/
MTCBB_API u32 mtDscGet(KEY strKey, void *pData, u32 &dwSize);

#endif // _MTDSC_H_