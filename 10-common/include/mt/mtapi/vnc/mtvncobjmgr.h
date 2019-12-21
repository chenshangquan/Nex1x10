/**===========================================================================
 * @file    $Id$
 * @brief   ����MtVncAPIҵ����ģ����󴴽�����
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _MTVNCOBJMGR_H_
#define _MTVNCOBJMGR_H_

#include "mtapi_typedef.h"
#include "mtapi_uuid.h"
#include "mtapi_if.h"

namespace mtapi
{
	u32 CreateVncObject( MT_UUID CID, IMtApiIF*& pOut, const void* pContext );
};

#endif // _MTVNCOBJMGR_H_