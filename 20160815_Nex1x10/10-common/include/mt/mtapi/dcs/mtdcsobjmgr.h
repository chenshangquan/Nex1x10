/**===========================================================================
 * @file    $Id$
 * @brief   负责MtMeetingMgrAPI业务功能模块对象创建管理
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _MTMGOBJMGR_H_
#define _MTMGOBJMGR_H_

#include "mtapi_typedef.h"
#include "mtapi_uuid.h"
#include "mtapi_if.h"

namespace mtapi
{
	u32 CreateDCSObject( MT_UUID CID, IMtApiIF*& pOut, const void* pContext );
};

#endif // _MTVCOBJMGR_H_