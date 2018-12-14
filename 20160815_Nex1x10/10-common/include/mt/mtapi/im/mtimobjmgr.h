/**===========================================================================
 * @file    $Id$
 * @brief   负责MtImAPI业务功能模块对象创建管理
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _MTIMOBJMGR_H_
#define _MTIMOBJMGR_H_

#include "mtapi_typedef.h"
#include "mtapi_uuid.h"
#include "mtapi_if.h"

namespace mtapi
{
	u32 CreateImObject( MT_UUID CID, IMtApiIF*& pOut, const void* pContext );
};

#endif // _MTIMOBJMGR_H_