#if !defined(_NVMCSERVICEHELP_H_)
#define _NVMCSERVICEHELP_H_
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
* nvmcserviceregcmd
* 
* @brief   ע��osp��������
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
extern void nvmcserviceregcmd();

/**----------------------------------------------------------------------
* nvmcservicehelp
* 
* @brief   nvmcserviceģ���������
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvmchelp();
/**----------------------------------------------------------------------
* nvmcservicever
* 
* @brief   nvmcservice�汾����ʾ
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvmcver();

#endif // _NVMCSERVICEHELP_H_