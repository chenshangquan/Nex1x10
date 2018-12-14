#if !defined(_MTIMHELP_H_)
#define _MTIMHELP_H_
#include "osp.h"

/**----------------------------------------------------------------------
* mtimregcmd
* 
* @brief   ×¢²áospµ÷ÊÔÃüÁî
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
extern void mtimregcmd();

extern s8* getimver();

API void mtimhelp();
API void mtimver();
API void iminfo();
API void imstatus();
API void imchatroom();
API void imroster();
API void imdms();
API void imconfig();
API void imsetstanzaswitch(BOOL32 bOn);
API void imstarttls( BOOL32 bStartTls );
API void imsetdebugswitch( BOOL32 bOn );
API void imshowswitch( );
API void mtimlastevent();


//////////////////////////////////////////////////////////////////////////
enum EmMtImDumpEvent
{
	dump_mtim_ShowLastEvent = 99,
};

#endif // _MTIMHELP_H_