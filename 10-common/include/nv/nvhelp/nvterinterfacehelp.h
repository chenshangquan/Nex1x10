#if !defined(_NVTERINTERFACEHELP_H_)
#define _NVTERINTERFACEHELP_H_
#include "osp.h"

/**----------------------------------------------------------------------
* nvterinterfaceregcmd
* 
* @brief   ע��osp��������
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
extern void nvterinterfaceregcmd();

/**----------------------------------------------------------------------
* nvterinterfacehelp
* 
* @brief   terinterfaceģ���������
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvterinterfacehelp();
/**----------------------------------------------------------------------
* nvterinterfacever
* 
* @brief   terinterface�汾����ʾ
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvterinterfacever();

/**----------------------------------------------------------------------
* GetNvAccessVer
* 
* @brief   ��ȡ�汾��Ϣ
* 
* @return  s8*
* @see     
------------------------------------------------------------------------*/
extern s8* GetNvTerinterfaceVer();

#endif // _NVTERINTERFACEHELP_H_