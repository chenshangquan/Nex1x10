/**===========================================================================
 * @file    $Id$
 * @brief   �����ն�ң������ع��ܿ��ƽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTREMOTECTRL_H_
#define _I_MTREMOTECTRL_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_vc.h"



/**---------------------------------------------------------------------------
 * @class   Interface IMtRemoteCtrl
 * @brief   �����ն�ң������ع��ܿ��ƽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtRemoteCtrl : public IMtApiIF
{
public:
	virtual u32 MtcRemoteCtrlCmd(TMTKeyPressInfo_Api tInfo) = 0;

private:

};

#endif // _I_MTREMOTECTRL_H_