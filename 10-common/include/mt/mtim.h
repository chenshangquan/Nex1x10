#if !defined(_MTIM_H_)
#define _MTIM_H_
#include "kdvtype.h"
#include "mtstruct.h"


#ifdef __cplusplus
extern "C" {
#endif

MTCBB_API BOOL32 ImStart(TMdlStartParam &tMdlStartParam);

MTCBB_API BOOL32 ImStop();

#ifdef __cplusplus
}
#endif


#endif // _MTIM_H_