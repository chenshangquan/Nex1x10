#if !defined(_NVMPHELP_H_)
#define _NVMPHELP_H_
#include "osp.h"                           
extern void nvmpregcmd();

extern s8* GetMpVer();

API void nvmphelp();
API void nvmpver();
API void nvmpshowcodecon();
API void nvmpshowcodecoff();
#endif // _NVMPHELP_H_