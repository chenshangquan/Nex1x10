#ifndef _NV_CONFIG_SERVICE_H_
#define _NV_CONFIG_SERVICE_H_

#include "nvstruct.h"
#include "nvlog.h"
#include "nvconst.h"
#include "osp.h"


extern "C" NVCBB_API BOOL32 ConfigServiceStart(TMdlStartParam &tMdlStartParam);
extern "C" NVCBB_API BOOL32 ConfigServiceStop();

#endif //_NV_CONFIG_SERVICE_H_