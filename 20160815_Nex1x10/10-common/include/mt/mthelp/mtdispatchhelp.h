#if !defined(_MTDISPATCHHELP_H_)
#define _MTDISPATCHHELP_H_
#include "osp.h"

/**----------------------------------------------------------------------
* mtdispatchregcmd
* 
* @brief   ע��osp��������
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
extern void mtdispatchregcmd();

/**----------------------------------------------------------------------
* GetDispatchVer
* 
* @brief   ��ȡ�汾��Ϣ
* 
* @return  s8*
* @see     
------------------------------------------------------------------------*/
extern s8* GetDispatchVer();

API void mtdispatchhelp();
API void mtdispatchver();

#endif // _MTDISPATCHHELP_H_