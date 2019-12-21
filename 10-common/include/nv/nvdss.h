#ifndef _NVDSS_H_
#define _NVDSS_H_
#include "kdvtype.h"
#include "nvmacro.h"

NVCBB_API BOOL32 InitDSS( u16 &wDssPort );

NVCBB_API void QuitDSS();

#endif // _NVDSS_H_