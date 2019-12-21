#if !defined(_NV_CONFIG_SERVICE_HELP_H_)
#define _NV_CONFIG_SERVICE_HELP_H_
#include "osp.h"

/**----------------------------------------------------------------------
* nvconfigregcmd
* 
* @brief   注册osp调试命令
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
extern void nvconfigregcmd();

/**----------------------------------------------------------------------
* nvconfighelp
* 
* @brief   config模块命令帮助
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvconfighelp();

/**----------------------------------------------------------------------
* nvconfigver
* 
* @brief   config模块版本信息
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvconfigver();

#endif //_NV_CONFIG_SERVICE_HELP_H_