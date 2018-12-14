#if !defined(_MTMPHELP_H_)
#define _MTMPHELP_H_
#include "osp.h"                           
extern void mtmpregcmd();

extern s8* GetMpVer();

API void mtmphelp();
API void mtmpver();
API void mtmpshowcodecon();
API void mtmpshowcodecoff();
#endif // _MTMPHELP_H_