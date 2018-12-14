/**===========================================================================
 * @file    $Id$
 * @brief   ����MtImAPi �ļ�������ع��ܽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTFILETRANSFER_H_
#define _I_MTFILETRANSFER_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_im.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtFileTransfer
 * @brief   ����MtImAPi �ļ�������ع��ܽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtFileTransfer : public IMtApiIF
{
public:
	//�ļ�/�ļ��д�������
	virtual u32 ImSendFileReq( const u32 dwHandle, const TImFileShareReq_Api& tImFileShareReq_Api ) = 0;

	//����/�ܾ��Զ˵��ļ�/�ļ��д�������
	virtual u32 ImAcceptFileReq( const u32 dwHandle, const u32 dwSessionID, const BOOL32 bRecv, const BOOL32 bSetSavePath, const char * pachPath ) = 0;

	//�ж��ļ�/�ļ��д�������
	virtual u32 ImCancelFileReq( const u32 dwHandle, const u32 dwSessionID ) = 0;

	//�����ļ�����·������
	virtual u32 ImSetFileSavePathReq( const u32 dwHandle, const char * pachPath ) = 0;

	//�����ļ�/�ļ��д�������
	virtual u32 ImSendGroupChatFileCmd( const u32 dwHandle, const TImGroupChatFileShareReq_Api& tImGroupChatFileShareReq_Api ) = 0;

	//iosϵͳ����������ʱĿ¼Req(ֻ����IOSϵͳ)
	virtual u32 ImIosSetTempPathCmd( const u32 dwHandle, const char * pachPath ) = 0;

	//�����ļ������������
	virtual u32 ImSetFileTransferBitRateReq( const u32 dwRate ) = 0;

private:

};

#endif // _I_MTFILETRANSFER_H_