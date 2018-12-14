/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   �˿ڹ������ͷ�ļ�
 * @author  �Ĵ���
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
* @param	[in] bUseRandPort	�Ƿ���������˿�
* @param	[in] wTcpStartPort  tcp��ʼ�˿�
* @param	[in] wUdpStartPort  udp��ʼ�˿�
*
* @return	NV_SUCCESS �ɹ�
*           NV_FAILED  ʧ��
**************************************************************/
NVCBB_API u32 nvPortInit(BOOL32 bUseRandPort, u16 wTcpStartPort, u16 wUdpStartPort);


/** ***********************************************************
* 
* @brief    �ж϶˿��Ƿ����
*
* @param	[in]  wPort Ҫ���Ķ˿�
*
* @return	TRUE���˿ڿ���   FALSE���˿ڲ�����
*
**************************************************************/
NVCBB_API BOOL32 nvIsPortFree(u16 wPort);


/** ***********************************************************
* 
* @brief    ������ж˿�
*
* @param	[out]  pawPort ����õĶ˿�
* @param	[in]   byNum   Ҫ���������
*
* @return	TRUE���ɹ�   FALSE��ʧ��
*
**************************************************************/
NVCBB_API BOOL32 nvAllocFreePort(u16 *pawPort, u8 byNum);


/** ***********************************************************
* 
* @brief    ������ж˿�
*
* @param	[out]  pawPort ����õĶ˿�
* @param	[in]   byNum   Ҫ���������
*
* @return	TRUE���ɹ�   FALSE��ʧ��
*
**************************************************************/
NVCBB_API BOOL32 nvAllocFreePort(nv::TNVPortPairAllocReqInfo &tReqInfo, nv::TNVPortPairAllocRspInfo &tRspInfo);
/*---------------------------------------------------------------------------*/
/**
* @brief   ҵ������˿�
*
* @param	[in]  tRspInfo Ҫ�ͷŶ˿ڶ�
*
* @return  void
*/
/*---------------------------------------------------------------------------*/
NVCBB_API void nvFreeUsedPort( const nv::TNVPortPairAllocRspInfo &tRspInfo );


/** ***********************************************************
* 
* @brief    ������ж˿�����
*
* @param	[in]   tReqInfo  Ҫ����˿���Ϣ
* @param	[out]  tRspInfo  ����õĶ˿���Ϣ
* @param	[out]  bTcpPort  Ҫ����Ķ˿������Ƿ�Ϊtcp�˿�
*
* @return	TRUE���ɹ�   FALSE��ʧ��
*
**************************************************************/
NVCBB_API BOOL32 nvAllocFreePortRange(nv::TNVPortRangeAllocReqInfo &tReqInfo, nv::TNVPortRangeAllocRspInfo &tRspInfo);
/*---------------------------------------------------------------------------*/
/**
* @brief   ҵ������˿�
*
* @param	[in]  tRspInfo Ҫ�ͷ�ĳһ��Χֵ�Ķ˿�
*
* @return  void
*/
/*---------------------------------------------------------------------------*/
NVCBB_API void nvFreeUsedPortRange( const nv::TNVPortRangeAllocRspInfo &tRspInfo );

};





//////////////////////////////�̶��˿�key����//////////////////////////
#define Port_Pxy "Port_Pxy"


#endif