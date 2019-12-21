/**===========================================================================
 * @file    $Id$
 * @brief   ����MtContactMgrApi ���м�¼��ؽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTCALLRECORD_H_
#define _I_MTCALLRECORD_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_cm.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtCallRecord
 * @brief   ����MtContactMgrApi ���м�¼��ؽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtCallRecord : public IMtApiIF
{
public:
	// ����һ����¼����
	virtual u32 RecordInsertReq(const TMTCallRecord_Api& tMTCallRecord_Api) = 0;

	// �޸�һ����¼����
	virtual u32 RecordModifyReq(const TMTCallRecord_Api& tMTCallRecord_Api) = 0;

	// ���ݱ�ʾֵɾ����Ӧ��¼
	virtual u32 RecordDelBySnReq(const u32 dwSn) = 0;

	// ����������ѯ��Ӧ��¼����
	virtual u32 RecordGetInfoByIndexReq(const u32 dwStartIndex, const u32 dwCount) = 0;

	// ���ݹؼ�ֵ��ѯ��Ӧ��¼����
	virtual u32 RecordGetInfoByKeyWordReq(const TMTRecordSearch_Api& tMTRecordSearch_Api, const u32 dwNum) = 0;

	// ���м�¼ģ����������
	virtual u32 RecordSearchReq(const s8* pszSearchWord, const u32 dwNum) = 0;

	// ͬһ������󱣴����
	virtual u32 RecordSetMaxOneCallNumCmd( const u32 dwNum ) = 0;

	// ���ñ��غ��м�¼����ļ�·��
	virtual u32 RecordSetCallRecordPathCmd(const s8* pszPath) = 0;

	//���ݺ������ͻ�ȡ���и���
	virtual u32 RecordNumByTypeReq( const EmMtCallRecordType_Api emCallType ) = 0;
	
	//ɾ�����к��м�¼
	virtual u32 RecordClearAllCmd() = 0;

};

#endif // _I_MTCALLRECORD_H_