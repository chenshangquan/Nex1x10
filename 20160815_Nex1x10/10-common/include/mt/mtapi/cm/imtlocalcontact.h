/**===========================================================================
 * @file    $Id$
 * @brief   ����MtContactMgrApi ���ص�ַ����ؿ��ƽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTLOCALCONTACT_H_
#define _I_MTLOCALCONTACT_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_cm.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtLocalContact
 * @brief   ����MtContactMgrApi ���ص�ַ����ؿ��ƽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtLocalContact : public IMtApiIF
{
public:

	// ���������
	virtual u32 AddrBookAddGroupReq(const TAddrBookGroupInfo_Api& tAddrBookGroupInfo_Api) = 0;

	// ɾ��������
	virtual u32 AddrBookDelGroupReq(const u32 dwGroupSn, const BOOL32 bMoved) = 0;

	// �޸�������
	virtual u32 AddrBookModifyGroupReq(const TAddrBookGroupInfo_Api& tAddrBookGroupInfo_Api) = 0;

	// �����ϵ������
	virtual u32 AddrBookAddRosterReq(const TAddrBookRosterInfo_Api& tAddrBookRosterInfo_Api) = 0;

	// ɾ����ϵ������
	virtual u32 AddrBookDelRosterReq(const u32 dwRosterSn) = 0;

	// �޸���ϵ������
	virtual u32 AddrBookModifyRosterReq(const TAddrBookRosterInfo_Api& tAddrBookRosterInfo_Api) = 0;

	// ����������ȡ��ϵ������
	virtual u32 AddrBookGetRosterInfoByIndexReq(const u32 dwStartIndex, const u32 dwCount) = 0;

	// ����������ȡ������
	virtual u32 AddrBookGetGroupInfoByIndexReq(const u32 dwStartIndex, const u32 dwCount) = 0;

	// ������Ż�ȡ��ϵ������
	virtual u32 AddrBookGetRosterInfoByGroupSnReq(const u32 dwGroupSn, const u32 dwCount) = 0;

	// ������Ż�ȡ����Ϣ����
	virtual u32 AddrBookGetGroupInfoByGroupSnReq(const u32 dwGroupSn, const u32 dwCount) = 0;

	// ���ñ��ص�ַ������ļ�·��
	virtual u32 AddrBookSetLocalRosterPathCmd(const s8* pszPath) = 0;

	// ���ļ������¸��µ�ַ����������������������
	virtual u32 AddrBookLoadLocalRosterInfoReq(const s8* pszPath) = 0;

	// ���ص�ַ��ģ����������
	virtual u32 AddrBookSearchReq(const s8* pszSearchWord, u32 dwNum) = 0;

	//��ȡ��ַ������������
	virtual u32 AddrBookGetTotalNumReq( ) = 0;

	//������Sn��ȡ���ص�ַ����ϵ��+��ĸ�������������Ƕ���飩����
	virtual u32 AddrBookGetNumByGroupSnReq( u32 dwGroupSn ) = 0;

	//���ص�ַ����ʼ������
	virtual u32 AddrBookInitCmd(const s8 *pchPath) = 0;

	//�����ص�ַ������
	virtual u32 AddrBookClearCmd() = 0;

};

#endif // _I_MTLOCALCONTACT_H_