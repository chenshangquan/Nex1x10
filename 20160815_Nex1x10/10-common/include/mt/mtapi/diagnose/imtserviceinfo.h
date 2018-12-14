/**===========================================================================
 * @file    $Id$
 * @brief   ����MtDiagnoseApi�ն˷�������Ϣͳ����ع��ܽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTSERVERINFO_H_
#define _I_MTSERVERINFO_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_diagnose.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtServerInfo
 * @brief   ����MtDiagnoseApi�ն˷�������Ϣͳ����ع��ܽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class IMtServerInfo: public IMtApiIF
{
public:
	//�����������Ϣ
	virtual u32 GetServerInfoReq(  ) = 0;
	//��ȡ��������Ϣ
	virtual TMTSrvInfoList_Api  GetServerInfo( ) = 0;

private:

};

#endif // _I_MTSERVERINFO_H_