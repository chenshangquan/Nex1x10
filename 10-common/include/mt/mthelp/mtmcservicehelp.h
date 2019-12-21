#if !defined(_MTMCSERVICEHELP_H_)
#define _MTMCSERVICEHELP_H_
#include "osp.h"

/**----------------------------------------------------------------------
* GetMcVer
* 
* @brief   获取版本信息
* 
* @return  s8*
* @see     
------------------------------------------------------------------------*/
extern s8* GetMcVer();

/**----------------------------------------------------------------------
* mtmcserviceregcmd
* 
* @brief   注册osp调试命令
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
extern void mtmcserviceregcmd();

/**----------------------------------------------------------------------
* mtmcservicehelp
* 
* @brief   mtmcservice模块命令帮助
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void mtmchelp();
/**----------------------------------------------------------------------
* mtmcservicever
* 
* @brief   mtmcservice版本号显示
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void mtmcver();

#endif // _MTMCSERVICEHELP_H_