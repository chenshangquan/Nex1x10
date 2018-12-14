#if !defined(_NVDISPATCHHELP_H_)
#define _NVDISPATCHHELP_H_
#include "osp.h"

/**----------------------------------------------------------------------
* nvdispatchregcmd
* 
* @brief   注册osp调试命令
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
extern void nvdispatchregcmd();

/**----------------------------------------------------------------------
* GetDispatchVer
* 
* @brief   获取版本信息
* 
* @return  s8*
* @see     
------------------------------------------------------------------------*/
extern s8* GetDispatchVer();

API void nvdispatchhelp();
API void nvdispatchver();

#endif // _NVDISPATCHHELP_H_