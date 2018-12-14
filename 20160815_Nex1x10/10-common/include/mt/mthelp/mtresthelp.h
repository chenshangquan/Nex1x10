#if !defined(_MTRESTHELP_H_)
#define _MTRESTHELP_H_
#include "osp.h"

/**----------------------------------------------------------------------
* mtrestregcmd
* 
* @brief   注册osp调试命令
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
extern void mtrestregcmd();
extern s8* getrestver();

API void mtresthelp();
API void mtrestver();

#endif // _MTRESTHELP_H_