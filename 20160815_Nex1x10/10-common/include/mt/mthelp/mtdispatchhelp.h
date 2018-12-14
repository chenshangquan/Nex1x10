#if !defined(_MTDISPATCHHELP_H_)
#define _MTDISPATCHHELP_H_
#include "osp.h"

/**----------------------------------------------------------------------
* mtdispatchregcmd
* 
* @brief   注册osp调试命令
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
extern void mtdispatchregcmd();

/**----------------------------------------------------------------------
* GetDispatchVer
* 
* @brief   获取版本信息
* 
* @return  s8*
* @see     
------------------------------------------------------------------------*/
extern s8* GetDispatchVer();

API void mtdispatchhelp();
API void mtdispatchver();

#endif // _MTDISPATCHHELP_H_