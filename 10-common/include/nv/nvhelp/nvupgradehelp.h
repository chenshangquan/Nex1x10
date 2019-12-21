#if !defined(_NVUPGRADEHELP_H_)
#define _NVUPGRADEHELP_H_
#include "osp.h"

/**----------------------------------------------------------------------
* nvupgraderegcmd
* 
* @brief   ע��osp��������
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
extern void nvupgraderegcmd();

/**----------------------------------------------------------------------
* nvupgradehelp
* 
* @brief   upgradeģ���������
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvupgradehelp();

/**----------------------------------------------------------------------
* nvupgradever
* 
* @brief   upgrade�汾����ʾ
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvupgradever();

/**----------------------------------------------------------------------
* nvsetbackupgrade
* 
* @brief   upgrade��̨��������
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvsetbackupgrade(bool bCfg);

/**----------------------------------------------------------------------
* nvshowbackstageupgradecfg
* 
* @brief   upgrade��ʾ��̨��������
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvshowbackstageupgradecfg();

/**----------------------------------------------------------------------
* nvstartupgrade
* 
* @brief   upgrade��ʼ����
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvstartupgrade(u8 wType);

/**----------------------------------------------------------------------
* nvdownloadupgradepackage
* 
* @brief   upgrade����������
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvdownloadupgradepackage();

/**----------------------------------------------------------------------
* nvcheckupgrade
* 
* @brief   upgrade�������
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvcheckupgrade(u8 byIndex);

#endif  //_NVUPGRADEHELP_H_