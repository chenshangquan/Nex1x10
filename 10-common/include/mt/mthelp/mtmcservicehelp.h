#if !defined(_MTMCSERVICEHELP_H_)
#define _MTMCSERVICEHELP_H_
#include "osp.h"

/**----------------------------------------------------------------------
* GetMcVer
* 
* @brief   ��ȡ�汾��Ϣ
* 
* @return  s8*
* @see     
------------------------------------------------------------------------*/
extern s8* GetMcVer();

/**----------------------------------------------------------------------
* mtmcserviceregcmd
* 
* @brief   ע��osp��������
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
extern void mtmcserviceregcmd();

/**----------------------------------------------------------------------
* mtmcservicehelp
* 
* @brief   mtmcserviceģ���������
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void mtmchelp();
/**----------------------------------------------------------------------
* mtmcservicever
* 
* @brief   mtmcservice�汾����ʾ
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void mtmcver();

#endif // _MTMCSERVICEHELP_H_