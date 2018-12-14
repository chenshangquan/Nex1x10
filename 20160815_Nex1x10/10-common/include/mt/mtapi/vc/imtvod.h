/**===========================================================================
 * @file    $Id$
 * @brief   ����MtVideoConfApi�ն���Ƶ��/ֱ��������ع��ܽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTVOD_H_
#define _I_MTVOD_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_vc.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtVod
 * @brief   ����MtVideoConfApi�ն���Ƶ��/ֱ��������ع��ܽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtVod : public IMtApiIF
{
public:
	//��¼VRSƽ̨����
	virtual u32 VrsLoginCmd( const TVodLoginInfo_Api *ptVrsLoginInfo ) = 0;
	//�����ļ����б�
	virtual u32 VrsGetFolderInfoCmd(  ) = 0;
	//����ĳһ�ļ����µĽ�Ŀ�б�
	virtual u32 VrsGetPrgsInfoCmd( const TVodGetPrgsReq_Api *ptVrsGetPrgsReq ) = 0;
	//�����ѯĳһ�ļ����µ��ļ�
	virtual u32 VrsSearchFilesInfoCmd( const TVodSearchFilesReq_Api ptVrsSearchFilesReq ) = 0;
	//����ֱ�����б�
	virtual u32 VrsGetRoomListInfoCmd( ) = 0;
	//����ԤԼֱ�����б�
	virtual u32 VrsGetReserveRoomListInfoCmd(/* const TVodGetReserveRoomListReq_Api *ptVrsGetReserveRoomListReq */) = 0;
	virtual u32 VrsNewGetResRoomListInfoCmd(const TVodGetResRoomReq_Api tVrsGetReserveRoomListReq ) = 0;

	//��ʼ�㲥����
	virtual u32 StartPlayVodCmd( const s8* pszUrl ) = 0;
	//�µĿ�ʼ�㲥����
	virtual u32 NewStartPlayVodCmd( const s8* pszUrl,const BOOL32 bFalg ) = 0;
	//��ȡ��ǰ�ѵ㲥�ĵ㲥��Ϣ
	virtual u32 GetRunVodInfoReq() = 0;
	//��ȡ�㲥Դ����Ϣ����
	virtual u32 GetVodInfoReq( const u32 dwVodId ) = 0;
	//ֹͣ�㲥����
	virtual u32 StopPlayVodCmd( const u32 dwVodId ) = 0;
	//�µ�ֹͣ�㲥����
	virtual u32 NewStopPlayVodCmd( const u32 dwVodId,const BOOL32 bFlag ) = 0;
	//��ͣ�㲥����
	virtual u32 PausePlayVodCmd( const u32 dwVodId ) = 0;
	//�ָ��㲥����
	virtual u32 ResumePlayVodCmd( const u32 dwVodId ) = 0;
	//�ı�㲥����
	virtual u32 ChangeVodSpeedCmd( const u32 dwVodId, const s8 chSpeedScale ) = 0;
	//�ı�㲥����
	virtual u32 ChangeVodProcessCmd( const u32 dwVodId, const u32 dwTime ) = 0;
	//�㲥Դָ��������
	virtual u32 StartPlayVodStreamCmd( const u32 dwVodId, const u8 byStremId ) = 0;
    //��ȡ�㲥Դ��Ϣ
	virtual u32 GetVodStreamInfoReq( const u32 dwVodId, const u8 byStremId ) = 0;
	//ֹͣ�㲥Դָ��������
	virtual u32 StopPlayVodStreamCmd( const u32 dwVodId, const u8 byStremId ) = 0;

public:
	//��ȡ�㲥����״̬
	virtual TVodPlayInfo_Api GetVodPlayInfo()  = 0;
	//��ȡ�����еĵ㲥��Ϣ
	virtual TMultiVodPlayInfo_Api GetRuningMultVodPlayInfo()  = 0;

};

#endif // _I_MTVOD_H_