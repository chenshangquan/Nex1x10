/**===========================================================================
 * @file    $Id$
 * @brief   �����ն�����MC��صĽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTMC_H_
#define _I_MTMC_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_vc.h"
#include "mtapi_container.h"



/**---------------------------------------------------------------------------
 * @class   Interface IMtMc
 * @brief   �����ն�����MC��صĽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date$
 * @note    
 ---------------------------------------------------------------------------*/

class IMtMc : public IMtApiIF
{
public:
	//��Ե���չ����������
	virtual u32 McAdHocCmd( const s8* pszCalledInfo ) = 0;
	//Mc�����ն�
	virtual u32 McInviteTerCmd( const s8* pszCalledInfo ) = 0;
	//�Ҷϻ����ն�
	virtual u32 McDropConfTerCmd( const TMtId_Api& tMtId ) = 0;
	//��������
	virtual u32 McEndConfCmd() = 0;
	//��������
	virtual u32 McCreateConfCmd( const s8 aaszCalledInfo[][KMTAPI_MAX_MT_ALIAS_LEN+1], u8 byCnt ) = 0;
	//������ѯ
	virtual u32 McMcPollBroadCastCmd( BOOL32 bPoll, u32 dwMsTime ) = 0;
};

#endif // _I_MTMC_H_