#if !defined(_MTREST_H_)
#define _MTREST_H_
#include "kdvtype.h"
#include "mtstruct.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL32 MTCBB_API RestStart(TMdlStartParam &tMdlStartParam);

BOOL32 MTCBB_API RestStop();

#ifdef __cplusplus
}
#endif

#endif // _MTREST_H_