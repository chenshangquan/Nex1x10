#if !defined(_NVRECORDHELP_H_)
#define _NVRECORDHELP_H_
#include "osp.h"

/**----------------------------------------------------------------------
* nvrecordregcmd
* 
* @brief   注册osp调试命令
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/

extern void nvrecordregcmd();
extern s8* getrecordver();


API void nvrecordhelp();
API void nvrecordver();

#endif // _NVRECORDHELP_H_