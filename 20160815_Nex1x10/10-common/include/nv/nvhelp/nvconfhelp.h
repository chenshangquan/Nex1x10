#if !defined(_NVCONFHELP_H_)
#define _NVCONFHELP_H_
#include "osp.h"


enum nvconf_dump
{
	dump_showcallstate,    ///show call state
	dump_showreg,
	dump_SetSipMulti,
	dump_SetSipNoMulti,
    dump_showCallCapbility,
    dump_showConfCtrlInfi,
	dump_showVidSrcInfo,     ///视频源相关信息
};

extern void nvconfregcmd();

API void nvconfhelp();
API void nvconfver();
API void nvconfcall();
API void nvconfcap();
API void nvconfctrlinfo();

#endif // _NVCONFHELP_H_