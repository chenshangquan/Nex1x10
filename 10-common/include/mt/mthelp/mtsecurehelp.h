#if !defined(_MTSECUREHELP_H_)
#define _MTSECUREHELP_H_
#include "osp.h"


/**----------------------------------------------------------------------
* GetVodVer
* 
* @brief   获取版本信息
* 
* @return  s8*
* @see     
------------------------------------------------------------------------*/
extern s8* GetSecVer();

/**----------------------------------------------------------------------
* mtsecregcmd
* 
* @brief   注册osp调试命令
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
extern void mtsecregcmd();

/**----------------------------------------------------------------------
* mtvsecver
* 
* @brief   mtsec版本号显示
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void mtsecver();
API void mtsechelp();
API void mtsecimportcrt( u32 dwCrtType, s8* achPath );
API void mtsecimportPFXcrt( s8* achPwd, s8* achPath );
API void mtsecexportcrt( u32 dwCrtType, s8* achPath );
API void mtseccreatecrt( u32 dwCrtType );
API void mtsecsetsip( u32 dwConnectType, u32 dwEncType, BOOL32 bStrongAuth );


#endif // _MTSECUREHELP_H_