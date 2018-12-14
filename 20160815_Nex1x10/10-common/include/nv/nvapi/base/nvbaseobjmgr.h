/**===========================================================================
 * @file    $Id$
 * @brief   负责NVBASEAPI业务功能模块对象创建管理
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _NVBASEOBJMGR_H_
#define _NVBASEOBJMGR_H_

#include "nvapi_typedef.h"
#include "nvapi_uuid.h"
#include "nvapi_if.h"

namespace nvapi
{
	u32 CreateBaseObject( NV_UUID CID, INvApiIF*& pOut, const void* pContext );
};

#endif // _NVBASEOBJMGR_H_