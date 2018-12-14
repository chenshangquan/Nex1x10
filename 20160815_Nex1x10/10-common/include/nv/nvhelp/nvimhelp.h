#if !defined(_NVIMHELP_H_)
#define _NVIMHELP_H_
#include "osp.h"

/**----------------------------------------------------------------------
* nvimregcmd
* 
* @brief   ×¢²áospµ÷ÊÔÃüÁî
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
extern void nvimregcmd();

extern s8* getimver();

API void nvimhelp();
API void nvimver();
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
API void nvimlastevent();


//////////////////////////////////////////////////////////////////////////
enum EmNvImDumpEvent
{
	dump_nvim_ShowLastEvent = 99,
};

#endif // _NVIMHELP_H_