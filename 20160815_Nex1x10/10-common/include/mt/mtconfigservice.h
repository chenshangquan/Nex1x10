#ifndef _MT_CONFIG_SERVICE_H_
#define _MT_CONFIG_SERVICE_H_

#include "mtstruct.h"
#include "mtlog.h"
#include "mtconst.h"
#include "osp.h"


extern "C" MTCBB_API BOOL32 ConfigServiceStart(TMdlStartParam &tMdlStartParam);
extern "C" MTCBB_API BOOL32 ConfigServiceStop();

#endif //_MT_CONFIG_SERVICE_H_