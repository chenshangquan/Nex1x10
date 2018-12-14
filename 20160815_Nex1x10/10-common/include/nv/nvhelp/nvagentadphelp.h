#if !defined(_NVAGENTHELP_H_)
#define _NVAGENTHELP_H_
#include "osp.h"

//Ä£¿éµ÷ÊÔÃüÁî
API void nvagentadpver();
API void nvagentadphelp();

API void nvagentadpreg();
API void nvagentadplogout();
API void nvagentadprptsconsvr();
API void nvagentadprptconsvr();
API void nvagentadprptdconsvr();
API void nvagentadprptalarm( u32 dwCodeId, u8 byStatus );
API void nvagentadprptver( u8 byRecommand );
API void nvagentadprpteptlog( );
API void nvagentadprptpfminfo( );
API void nvagentadpreportconfinfo( u8 byStatus);

#endif // _NVAGENTHELP_H_