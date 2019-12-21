#if !defined(_NVMCSERVICEHELP_H_)
#define _NVMCSERVICEHELP_H_
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
* nvmcserviceregcmd
* 
* @brief   注册osp调试命令
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
extern void nvmcserviceregcmd();

/**----------------------------------------------------------------------
* nvmcservicehelp
* 
* @brief   nvmcservice模块命令帮助
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvmchelp();
/**----------------------------------------------------------------------
* nvmcservicever
* 
* @brief   nvmcservice版本号显示
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvmcver();

#endif // _NVMCSERVICEHELP_H_