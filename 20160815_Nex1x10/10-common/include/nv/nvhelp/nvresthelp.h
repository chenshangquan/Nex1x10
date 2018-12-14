#if !defined(_NVRESTHELP_H_)
#define _NVRESTHELP_H_
#include "osp.h"

/**----------------------------------------------------------------------
* nvrestregcmd
* 
* @brief   注册osp调试命令
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
extern void nvrestregcmd();
extern s8* getrestver();

API void nvresthelp();
API void nvrestver();

#endif // _NVRESTHELP_H_