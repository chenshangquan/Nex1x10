#if !defined(_NVH323HELP_H_)
#define _NVH323HELP_H_
#include "osp.h"

enum nvh323_dump
{
	dump_showcallstate,
	dump_showstackrun,
	dump_showreg,
	dump_setstack,
    dump_set5p0,	
	dump_setold,
};

/**----------------------------------------------------------------------
* nvh323regcmd
* 
* @brief   ×¢²áospµ÷ÊÔÃüÁî
* 
* @param   void
* @return  void
------------------------------------------------------------------------*/
extern void nvh323regcmd();

API void nvh323help();
API void nvh323ver();
API void nvh323stack();
API void nvh323call();
API void nvh323reg();
API void nvh323setstack( BOOL32 bStand);



#endif // _NVH323HELP_H_