#if !defined(_MTSERVICE_H_)
#define _MTSERVICE_H_

#include "kdvtype.h"
#include "mtstruct.h"
#include "abstractins.h"
#include "enum.pb.h"
#include "mtservice_api.h"

#ifdef __cplusplus
extern "C" {
#endif


MTCBB_API BOOL32 MtServiceStart(TMdlStartParam &tMdlStartParam);

MTCBB_API BOOL32 MtServiceStop();


#ifdef __cplusplus
}
#endif

#endif // _MTSERVICE_H_