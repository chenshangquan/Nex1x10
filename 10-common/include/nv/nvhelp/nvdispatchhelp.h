#if !defined(_NVDISPATCHHELP_H_)
#define _NVDISPATCHHELP_H_
#include "osp.h"

/**----------------------------------------------------------------------
* nvdispatchregcmd
* 
* @brief   ע��osp��������
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
extern void nvdispatchregcmd();

/**----------------------------------------------------------------------
* GetDispatchVer
* 
* @brief   ��ȡ�汾��Ϣ
* 
* @return  s8*
* @see     
------------------------------------------------------------------------*/
extern s8* GetDispatchVer();

API void nvdispatchhelp();
API void nvdispatchver();

#endif // _NVDISPATCHHELP_H_