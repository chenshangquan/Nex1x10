#if !defined(_MTACCESSHELP_H_)
#define _MTACCESSHELP_H_
#include "osp.h"

/**----------------------------------------------------------------------
* mtaccessregcmd
* 
* @brief   ע��osp��������
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
extern void mtaccessregcmd();

/**----------------------------------------------------------------------
* mtaccesshelp
* 
* @brief   accessģ���������
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void mtaccesshelp();
/**----------------------------------------------------------------------
* mtaccessver
* 
* @brief   access�汾����ʾ
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void mtaccessver();
/**----------------------------------------------------------------------
* showlogininfo
* 
* @brief   ��ʾ��¼�û���Ϣ
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void showlogininfo();
/**----------------------------------------------------------------------
* showuserinfo
* 
* @brief   ��ʾ�����û���Ϣ
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void showuserinfo();
/**----------------------------------------------------------------------
* adduser
* 
* @brief   ����û�
* 
* @param   pcUserName �û���
* @param   pcPassword ����
* @param   byActor Ȩ��
* @return  void
* @see     
------------------------------------------------------------------------*/
API void adduser( char* pcUserName, char *pcPassword, u8 byActor );
/**----------------------------------------------------------------------
* deluser
* 
* @brief   ɾ���û�
* 
* @param   dwGuid �û�Ψһ��ʾ
* @return  void
* @see     
------------------------------------------------------------------------*/
API void deluser( u32 dwGuid );

API void loginunlock(char* pcPassword);
/**----------------------------------------------------------------------
* GetMtAccessVer
* 
* @brief   ��ȡ�汾��Ϣ
* 
* @return  s8*
* @see     
------------------------------------------------------------------------*/
extern s8* GetMtAccessVer();

#endif // _MTACCESSHELP_H_