#if !defined(_MTH323HELP_H_)
#define _MTH323HELP_H_
#include "osp.h"

enum mth323_dump
{
	dump_showcallstate,
	dump_showstackrun,
	dump_showreg,
	dump_setstack,
    dump_set5p0,	
	dump_setold,
};

/**----------------------------------------------------------------------
* mth323regcmd
* 
* @brief   ×¢²áospµ÷ÊÔÃüÁî
* 
* @param   void
* @return  void
------------------------------------------------------------------------*/
extern void mth323regcmd();

API void mth323help();
API void mth323ver();
API void mth323stack();
API void mth323call();
API void mth323reg();
API void mth323setstack( BOOL32 bStand);
API void mth323lastmsg();



#endif // _MTH323HELP_H_