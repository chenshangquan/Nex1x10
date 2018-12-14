#if !defined(_NVTERINTERFACEHELP_H_)
#define _NVTERINTERFACEHELP_H_
#include "osp.h"

/**----------------------------------------------------------------------
* nvterinterfaceregcmd
* 
* @brief   注册osp调试命令
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
extern void nvterinterfaceregcmd();

/**----------------------------------------------------------------------
* nvterinterfacehelp
* 
* @brief   terinterface模块命令帮助
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvterinterfacehelp();
/**----------------------------------------------------------------------
* nvterinterfacever
* 
* @brief   terinterface版本号显示
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvterinterfacever();

/**----------------------------------------------------------------------
* GetNvAccessVer
* 
* @brief   获取版本信息
* 
* @return  s8*
* @see     
------------------------------------------------------------------------*/
extern s8* GetNvTerinterfaceVer();

#endif // _NVTERINTERFACEHELP_H_