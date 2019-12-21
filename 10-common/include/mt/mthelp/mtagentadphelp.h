#if !defined(_MTAGENTHELP_H_)
#define _MTAGENTHELP_H_
#include "osp.h"

//Ä£¿éµ÷ÊÔÃüÁî
API void mtagentadpver();
API void mtagentadphelp();

API void mtagentadpreg();
API void mtagentadplogout();
API void mtagentadprptsconsvr();
API void mtagentadprptconsvr();
API void mtagentadprptdconsvr();
API void mtagentadprptalarm( u32 dwCodeId, u8 byStatus );
API void mtagentadprptver( u8 byRecommand );
API void mtagentadprpteptlog( );
API void mtagentadprptpfminfo( );
API void mtagentadpreportconfinfo( u8 byStatus);

#endif // _MTAGENTHELP_H_