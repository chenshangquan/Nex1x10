/**===========================================================================
 * @file    $Id$
 * @brief   ����MtContactMgrAPIҵ����ģ����󴴽�����
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _MTCMOBJMGR_H_
#define _MTCMOBJMGR_H_

#include "mtapi_typedef.h"
#include "mtapi_uuid.h"
#include "mtapi_if.h"

namespace mtapi
{
	u32 CreateCmObject( MT_UUID CID, IMtApiIF*& pOut, const void* pContext );
};

#endif // _MTCMOBJMGR_H_