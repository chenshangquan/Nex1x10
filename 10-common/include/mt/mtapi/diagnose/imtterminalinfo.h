/**===========================================================================
 * @file    $Id$
 * @brief   ����MtDiagnoseApi�ն�ϵͳ��ع��ܽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTTERMINALINFO_H_
#define _I_MTTERMINALINFO_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_diagnose.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtTerminalInfo
 * @brief   ����MtDiagnoseApi�ն˺�����Ϣͳ����ع��ܽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class IMtTerminalInfo: public IMtApiIF
{
public:
	//����ϵͳ����ʱ��
	virtual u32 GetMtRunTimeReq(  ) = 0;

	//�����ն���Ϣ
	virtual u32 GetMtTerInfoReq(  ) = 0;
	//��ȡϵͳ����ʱ��
	virtual u32 GetMtRunTime( ) = 0 ;
	//��ȡ�ն���Ϣ
	virtual TTerminalInfo_Api GetTerInfo( ) = 0;
public:

private:

};

#endif // _I_MTTERMINALINFO_H_