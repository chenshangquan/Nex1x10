#if !defined(_NVPAHELP_H_)
#define _NVPAHELP_H_
#include "osp.h"

enum nvpa_dump
{
	dump_showcallstate,
	dump_showpacfg,
};

extern s8* GetNvpaVer();
extern void nvparegcmd();

API void nvpahelp();
API void nvpaver();
API void nvpacall();
API void nvpacfg();

#endif // _NVPAHELP_H_