#if !defined(_MTRECORD_H_)
#define _MTRECORD_H_

#include "kdvtype.h"
#include "mtstruct.h"



#ifdef __cplusplus
extern "C" {
#endif

MTCBB_API BOOL32 RecordStart(TMdlStartParam &tMdlStartParam);

MTCBB_API BOOL32 RecordStop();


#ifdef __cplusplus
}
#endif

#endif // _MTRECORD_H_