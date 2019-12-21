/**===========================================================================
 * @file    $Id$
 * @brief   负责MtContactMgrApi 本地地址薄相关控制接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTLOCALCONTACT_H_
#define _I_MTLOCALCONTACT_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_cm.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtLocalContact
 * @brief   负责MtContactMgrApi 本地地址薄相关控制接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtLocalContact : public IMtApiIF
{
public:

	// 添加组请求
	virtual u32 AddrBookAddGroupReq(const TAddrBookGroupInfo_Api& tAddrBookGroupInfo_Api) = 0;

	// 删除组请求
	virtual u32 AddrBookDelGroupReq(const u32 dwGroupSn, const BOOL32 bMoved) = 0;

	// 修改组请求
	virtual u32 AddrBookModifyGroupReq(const TAddrBookGroupInfo_Api& tAddrBookGroupInfo_Api) = 0;

	// 添加联系人请求
	virtual u32 AddrBookAddRosterReq(const TAddrBookRosterInfo_Api& tAddrBookRosterInfo_Api) = 0;

	// 删除联系人请求
	virtual u32 AddrBookDelRosterReq(const u32 dwRosterSn) = 0;

	// 修改联系人请求
	virtual u32 AddrBookModifyRosterReq(const TAddrBookRosterInfo_Api& tAddrBookRosterInfo_Api) = 0;

	// 根据索引获取联系人请求
	virtual u32 AddrBookGetRosterInfoByIndexReq(const u32 dwStartIndex, const u32 dwCount) = 0;

	// 根据索引获取组请求
	virtual u32 AddrBookGetGroupInfoByIndexReq(const u32 dwStartIndex, const u32 dwCount) = 0;

	// 根据组号获取联系人请求
	virtual u32 AddrBookGetRosterInfoByGroupSnReq(const u32 dwGroupSn, const u32 dwCount) = 0;

	// 根据组号获取组信息请求
	virtual u32 AddrBookGetGroupInfoByGroupSnReq(const u32 dwGroupSn, const u32 dwCount) = 0;

	// 设置本地地址簿存放文件路径
	virtual u32 AddrBookSetLocalRosterPathCmd(const s8* pszPath) = 0;

	// 从文件中重新更新地址簿的内容请求（无需重启）
	virtual u32 AddrBookLoadLocalRosterInfoReq(const s8* pszPath) = 0;

	// 本地地址簿模糊搜索请求
	virtual u32 AddrBookSearchReq(const s8* pszSearchWord, u32 dwNum) = 0;

	//获取地址簿总人数请求
	virtual u32 AddrBookGetTotalNumReq( ) = 0;

	//根据组Sn获取本地地址簿联系人+组的个数（不算其中嵌套组）请求
	virtual u32 AddrBookGetNumByGroupSnReq( u32 dwGroupSn ) = 0;

	//本地地址簿初始化命令
	virtual u32 AddrBookInitCmd(const s8 *pchPath) = 0;

	//清理本地地址薄命令
	virtual u32 AddrBookClearCmd() = 0;

};

#endif // _I_MTLOCALCONTACT_H_