#if !defined(_MTDCS_H_)
#define _MTDCS_H_
#include "kdvtype.h"
#include "mtstruct.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL32 MTCBB_API StartMtDcs(TMdlStartParam &tMdlStartParam);

BOOL32 MTCBB_API StopMtDcs();

#ifdef __cplusplus
}
#endif

#endif // _MTDCS_H_