/**===========================================================================
 * @file    $Id$
 * @brief   �����ն�ͨ�ù��ܵĽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTCOMMON_H_
#define _I_MTCOMMON_H_

#include "nvapi_typedef.h"
#include "nvapi_if.h"
#include "nvapi_event_base.h"




/**---------------------------------------------------------------------------
 * @class   Interface INvCommon
 * @brief   �����ն�ͨ�ù��ܵĽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class INvCommon : public INvApiIF
{
public:
	//֪ͨ����ʹ�õ�������Ϣ
	virtual u32 SendUsedNetInfoNtf( const nv::TNVNetUsedInfo& tNetUsedInfo ) = 0;
	//������־��ӡ
	virtual u32 SetLogHintCmd( const nv::TString& tLog ) = 0;
public:

};

#endif // _I_MTCOMMON_H_