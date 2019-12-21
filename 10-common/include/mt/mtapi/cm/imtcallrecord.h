/**===========================================================================
 * @file    $Id$
 * @brief   负责MtContactMgrApi 呼叫记录相关接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTCALLRECORD_H_
#define _I_MTCALLRECORD_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_cm.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtCallRecord
 * @brief   负责MtContactMgrApi 呼叫记录相关接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtCallRecord : public IMtApiIF
{
public:
	// 增加一条记录请求
	virtual u32 RecordInsertReq(const TMTCallRecord_Api& tMTCallRecord_Api) = 0;

	// 修改一条记录请求
	virtual u32 RecordModifyReq(const TMTCallRecord_Api& tMTCallRecord_Api) = 0;

	// 根据标示值删除对应记录
	virtual u32 RecordDelBySnReq(const u32 dwSn) = 0;

	// 根据索引查询对应记录请求
	virtual u32 RecordGetInfoByIndexReq(const u32 dwStartIndex, const u32 dwCount) = 0;

	// 根据关键值查询对应记录请求
	virtual u32 RecordGetInfoByKeyWordReq(const TMTRecordSearch_Api& tMTRecordSearch_Api, const u32 dwNum) = 0;

	// 呼叫记录模糊搜索请求
	virtual u32 RecordSearchReq(const s8* pszSearchWord, const u32 dwNum) = 0;

	// 同一呼叫最大保存个数
	virtual u32 RecordSetMaxOneCallNumCmd( const u32 dwNum ) = 0;

	// 设置本地呼叫记录存放文件路径
	virtual u32 RecordSetCallRecordPathCmd(const s8* pszPath) = 0;

	//根据呼叫类型获取呼叫个数
	virtual u32 RecordNumByTypeReq( const EmMtCallRecordType_Api emCallType ) = 0;
	
	//删除所有呼叫记录
	virtual u32 RecordClearAllCmd() = 0;

};

#endif // _I_MTCALLRECORD_H_