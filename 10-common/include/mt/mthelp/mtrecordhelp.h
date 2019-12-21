#if !defined(_MTRECORDHELP_H_)
#define _MTRECORDHELP_H_
#include "osp.h"

/**----------------------------------------------------------------------
* mtrecordregcmd
* 
* @brief   注册osp调试命令
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/

extern void mtrecordregcmd();
extern s8* getrecordver();


API void mtrecordhelp();
API void mtrecordver();

#endif // _MTRECORDHELP_H_