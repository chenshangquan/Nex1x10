#if !defined(_NVUPGRADEHELP_H_)
#define _NVUPGRADEHELP_H_
#include "osp.h"

/**----------------------------------------------------------------------
* nvupgraderegcmd
* 
* @brief   注册osp调试命令
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
extern void nvupgraderegcmd();

/**----------------------------------------------------------------------
* nvupgradehelp
* 
* @brief   upgrade模块命令帮助
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvupgradehelp();

/**----------------------------------------------------------------------
* nvupgradever
* 
* @brief   upgrade版本号显示
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvupgradever();

/**----------------------------------------------------------------------
* nvsetbackupgrade
* 
* @brief   upgrade后台升级设置
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvsetbackupgrade(bool bCfg);

/**----------------------------------------------------------------------
* nvshowbackstageupgradecfg
* 
* @brief   upgrade显示后台升级设置
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvshowbackstageupgradecfg();

/**----------------------------------------------------------------------
* nvstartupgrade
* 
* @brief   upgrade开始升级
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvstartupgrade(u8 wType);

/**----------------------------------------------------------------------
* nvdownloadupgradepackage
* 
* @brief   upgrade下载升级包
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvdownloadupgradepackage();

/**----------------------------------------------------------------------
* nvcheckupgrade
* 
* @brief   upgrade检查升级
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvcheckupgrade(u8 byIndex);

#endif  //_NVUPGRADEHELP_H_