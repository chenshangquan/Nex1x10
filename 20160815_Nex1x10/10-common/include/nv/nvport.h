/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   端口管理组件头文件
 * @author  瞿戴沣
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * 
 */
/*---------------------------------------------------------------------------*/
#ifndef _NVPORT_H_
#define _NVPORT_H_

#include "kdvtype.h"
#include "nvenum.pb.h"
#include "nvstruct.pb.h"
#include "nvmacro.h"

namespace NVPORT {


/** ***********************************************************
* 
* @brief    
* @param	[in] bUseRandPort	是否启用随机端口
* @param	[in] wTcpStartPort  tcp起始端口
* @param	[in] wUdpStartPort  udp起始端口
*
* @return	NV_SUCCESS 成功
*           NV_FAILED  失败
**************************************************************/
NVCBB_API u32 nvPortInit(BOOL32 bUseRandPort, u16 wTcpStartPort, u16 wUdpStartPort);


/** ***********************************************************
* 
* @brief    判断端口是否可用
*
* @param	[in]  wPort 要检测的端口
*
* @return	TRUE：端口空闲   FALSE：端口不可用
*
**************************************************************/
NVCBB_API BOOL32 nvIsPortFree(u16 wPort);


/** ***********************************************************
* 
* @brief    分配空闲端口
*
* @param	[out]  pawPort 分配好的端口
* @param	[in]   byNum   要分配的数量
*
* @return	TRUE：成功   FALSE：失败
*
**************************************************************/
NVCBB_API BOOL32 nvAllocFreePort(u16 *pawPort, u8 byNum);


/** ***********************************************************
* 
* @brief    分配空闲端口
*
* @param	[out]  pawPort 分配好的端口
* @param	[in]   byNum   要分配的数量
*
* @return	TRUE：成功   FALSE：失败
*
**************************************************************/
NVCBB_API BOOL32 nvAllocFreePort(nv::TNVPortPairAllocReqInfo &tReqInfo, nv::TNVPortPairAllocRspInfo &tRspInfo);
/*---------------------------------------------------------------------------*/
/**
* @brief   业务层分配端口
*
* @param	[in]  tRspInfo 要释放端口对
*
* @return  void
*/
/*---------------------------------------------------------------------------*/
NVCBB_API void nvFreeUsedPort( const nv::TNVPortPairAllocRspInfo &tRspInfo );


/** ***********************************************************
* 
* @brief    分配空闲端口区间
*
* @param	[in]   tReqInfo  要分配端口信息
* @param	[out]  tRspInfo  分配好的端口信息
* @param	[out]  bTcpPort  要分配的端口类型是否为tcp端口
*
* @return	TRUE：成功   FALSE：失败
*
**************************************************************/
NVCBB_API BOOL32 nvAllocFreePortRange(nv::TNVPortRangeAllocReqInfo &tReqInfo, nv::TNVPortRangeAllocRspInfo &tRspInfo);
/*---------------------------------------------------------------------------*/
/**
* @brief   业务层分配端口
*
* @param	[in]  tRspInfo 要释放某一范围值的端口
*
* @return  void
*/
/*---------------------------------------------------------------------------*/
NVCBB_API void nvFreeUsedPortRange( const nv::TNVPortRangeAllocRspInfo &tRspInfo );

};





//////////////////////////////固定端口key定义//////////////////////////
#define Port_Pxy "Port_Pxy"


#endif