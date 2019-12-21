/**===========================================================================
 * @file    $Id$
 * @brief   ����MtVncAPi ���湲���������ݺ��������ع��ܽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTVNCCFG_H_
#define _I_MTVNCCFG_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_vnc.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtCha
 * @brief   ����MtVncAPi ���湲���������ݺ��������ع��ܽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtVncCfg : public IMtApiIF
{
public:
	//�����ն�video��������״̬
	virtual u32 GetAssSndVidStatusReq() = 0;
	//�����ն�video��������״̬
	virtual u32 GetAssRcvVidStatusReq() = 0;
	//pc���湲��ʼֹͣ����
	virtual u32 PcAssStreamReq( const TNetAddr_Api& tPcRtcp, const BOOL32 bStart ) = 0;
	virtual u32 PlayStream( const TNetAddr_Api& tPcRtcp, const BOOL32 bStart, 
		const EmCodecComponent_Api emCodecType, 
		const EmCodecComponentIndex_Api emVideoIndex ) = 0;
	//����ͨ���״̬
	virtual u32 SetChanActive( const BOOL32 bActive ) = 0;

	//��ȡ�ն�video��������״̬
	virtual TMtAssVidStatusList_Api GetAssSndVidStatus() = 0;
	//��ȡ�ն�video��������״̬
	virtual TMtAssVidStatusList_Api GetAssRcvVidStatus() = 0;
	//��ȡPC������ͨ������
	virtual TMTPcAssStreamChanParam_Api GetPcAssStreamChanParam() = 0;
};

#endif // _I_MTVNCCFG_H_