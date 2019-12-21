#if !defined(_MTACCESSHELP_H_)
#define _MTACCESSHELP_H_
#include "osp.h"

/**----------------------------------------------------------------------
* mtaccessregcmd
* 
* @brief   注册osp调试命令
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
extern void mtaccessregcmd();

/**----------------------------------------------------------------------
* mtaccesshelp
* 
* @brief   access模块命令帮助
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void mtaccesshelp();
/**----------------------------------------------------------------------
* mtaccessver
* 
* @brief   access版本号显示
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void mtaccessver();
/**----------------------------------------------------------------------
* showlogininfo
* 
* @brief   显示登录用户信息
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void showlogininfo();
/**----------------------------------------------------------------------
* showuserinfo
* 
* @brief   显示所有用户信息
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void showuserinfo();
/**----------------------------------------------------------------------
* adduser
* 
* @brief   添加用户
* 
* @param   pcUserName 用户名
* @param   pcPassword 密码
* @param   byActor 权限
* @return  void
* @see     
------------------------------------------------------------------------*/
API void adduser( char* pcUserName, char *pcPassword, u8 byActor );
/**----------------------------------------------------------------------
* deluser
* 
* @brief   删除用户
* 
* @param   dwGuid 用户唯一标示
* @return  void
* @see     
------------------------------------------------------------------------*/
API void deluser( u32 dwGuid );

API void loginunlock(char* pcPassword);
/**----------------------------------------------------------------------
* GetMtAccessVer
* 
* @brief   获取版本信息
* 
* @return  s8*
* @see     
------------------------------------------------------------------------*/
extern s8* GetMtAccessVer();

#endif // _MTACCESSHELP_H_