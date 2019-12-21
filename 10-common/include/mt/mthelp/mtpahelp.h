#if !defined(_MTPAHELP_H_)
#define _MTPAHELP_H_
#include "osp.h"

enum mtpa_dump
{
	dump_showcallstate,
	dump_showpacfg,
	dump_showpareg,
	dump_showpastack,
};

extern s8* GetMtpaVer();
extern void mtparegcmd();

API void mtpahelp();
API void mtpaver();
API void mtpacall();
API void mtpacfg();
API void mtpastack();
API void mtpalastmsg();
API void mtpaunreg(u32 dwNum);


#endif // _MTPAHELP_H_