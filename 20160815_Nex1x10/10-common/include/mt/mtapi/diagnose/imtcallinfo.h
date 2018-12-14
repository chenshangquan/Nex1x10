/**===========================================================================
 * @file    $Id$
 * @brief   ����MtDiagnoseApi�ն˺�����Ϣͳ����ع��ܽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTCALLINFO_H_
#define _I_MTCALLINFO_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_diagnose.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtCallInfo
 * @brief   ����MtDiagnoseApi�ն˺�����Ϣͳ����ع��ܽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class IMtCallInfo: public IMtApiIF
{
public:
	//����˿���Ϣ
	virtual u32    GetPortInfoReq(  ) = 0;
	//��ȡ�˿���Ϣ
	virtual TMTTotalUsedPort_Api GetPorInfo( ) = 0;

	//��ȡ����롢�������ϳɡ�����ͳ����Ϣ����
	virtual BOOL32 GetCallStatisticsInfoReq( ) = 0;

	//��ȡ����롢�������ϳɡ�����ͳ����Ϣ
	virtual TMtCodecStatistic_Api GetCallStatisticsInfo() =0;
};

#endif // _I_MTCALLINFO_H_