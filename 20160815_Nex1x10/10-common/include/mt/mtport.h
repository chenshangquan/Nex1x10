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
#ifndef _MTPORT_H_
#define _MTPORT_H_

#include "kdvtype.h"
#include "enum.pb.h"
#include "struct.pb.h"
#include "mtmacro.h"

namespace MTPORT {


/** ***********************************************************
* 
* @brief    
* @param	[in] bUseRandPort	�Ƿ���������˿�
* @param	[in] wTcpStartPort  tcp��ʼ�˿�
* @param	[in] wUdpStartPort  udp��ʼ�˿�
*
* @return	MT_SUCCESS �ɹ�
*           MT_FAILED  ʧ��
**************************************************************/
MTCBB_API u32 mtPortInit(BOOL32 bUseRandPort, u16 wTcpStartPort, u16 wUdpStartPort);


/** ***********************************************************
* 
* @brief    �ж϶˿��Ƿ����
*
* @param	[in]  wPort Ҫ���Ķ˿�
*
* @return	TRUE���˿ڿ���   FALSE���˿ڲ�����
*
**************************************************************/
MTCBB_API BOOL32 mtIsPortFree(u16 wPort);


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
MTCBB_API BOOL32 mtAllocFreePort(u16 *pawPort, u8 byNum);


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
MTCBB_API BOOL32 mtAllocFreePort(mt::TMTPortPairAllocReqInfo &tReqInfo, mt::TMTPortPairAllocRspInfo &tRspInfo);
/*---------------------------------------------------------------------------*/
/**
* @brief   ҵ������˿�
*
* @param	[in]  tRspInfo Ҫ�ͷŶ˿ڶ�
*
* @return  void
*/
/*---------------------------------------------------------------------------*/
MTCBB_API void mtFreeUsedPort( const mt::TMTPortPairAllocRspInfo &tRspInfo );


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
MTCBB_API BOOL32 mtAllocFreePortRange(mt::TMTPortRangeAllocReqInfo &tReqInfo, mt::TMTPortRangeAllocRspInfo &tRspInfo);
/*---------------------------------------------------------------------------*/
/**
* @brief   ҵ������˿�
*
* @param	[in]  tRspInfo Ҫ�ͷ�ĳһ��Χֵ�Ķ˿�
*
* @return  void
*/
/*---------------------------------------------------------------------------*/
MTCBB_API void mtFreeUsedPortRange( const mt::TMTPortRangeAllocRspInfo &tRspInfo );

};





//////////////////////////////�̶��˿�key����//////////////////////////
#define Port_Pxy "Port_Pxy"


#endif