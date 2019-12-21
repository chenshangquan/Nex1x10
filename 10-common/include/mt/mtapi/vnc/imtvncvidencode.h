/**===========================================================================
 * @file    $Id$
 * @brief   ����MtVncAPi ���湲����Ƶ�ɼ������롢���͵ȹ��ܽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTVNCVIDENCODE_H_
#define _I_MTVNCVIDENCODE_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_vnc.h"
#ifdef _WIN32_P_
#include "codecwrapper_win32.h"
#endif

#ifdef _ANDROID_
#include "codeclib_iOS_Android.h"
#endif
/**---------------------------------------------------------------------------
 * @class   Interface IMtVncVidEncode
 * @brief   ��MtVncAPi ���湲����Ƶ�ɼ������롢���͵ȹ��ܽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtVncVidEncode : public IMtApiIF
{
public:
	//��Ƶ��������ʼ��
	virtual u32 Init() = 0;
	//��Ƶ�������˳�
	virtual u32 Exit() = 0;

	//���òɼ���ƵԴ
	virtual u32	SetDeskDrawHwnd( s32 hDeskDrawWnd ) = 0;
	//������Ƶ�������
	virtual u32	SetVideoEncParam( const TVidEncParam_Api &tVideoEncParam ) = 0;
	//����˫���ɼ�֡��
	virtual u32 SetCapFramerate( u8 byCapFramerate) = 0 ;
	//��Ƶ�Ƿ�ʹ��ǰ�����
	virtual u32	SetVidFecEnable( BOOL32 bEnableFec ) = 0;

	//�Ƿ������ƵRTP��չͷ
	virtual u32 VideoEnableRtpExStrip(BOOL32 bEnable) =0;

	//����fec���а�����
	virtual u32	SetVidFecPackLen( u16 wPackLen ) = 0;
	//�Ƿ�֡��fec
	virtual u32	SetVidFecIntraFrame( BOOL32 bIntraFrame ) = 0;
	//����fec�㷨 FEC_MODE_RAID5
	virtual u32	SetVidFecMode( u8 byAlgorithm ) = 0;
	//����fec��x�����ݰ� + y�������
	virtual u32	SetVidFecXY( s32 nDataPackNum, s32 nCrcPackNum ) = 0;
	//������Ƶ��̬�غɵ�PTֵ���趨
	virtual u32	SetVideoActivePT( u8 byRealPt,u8 byDynamicPt ) = 0;
	//������Ƶ�������key�ִ������ܵ��غ�PTֵ �Լ� ����ģʽ Aes or Des
	virtual u32	SetVidEncryptKey( s8 *pchKeyBuf, u16 wKeySize, u8 byEncryptMode ) = 0;

	virtual u32	SetVidSrtpCrypto( const TMtSrtpCrypto_Api &tSrtpCrypto ) = 0;
	//����ͼ������紫�Ͳ���
	virtual u32	SetNetSndVideoParam( const TNetParam_Api &tNetSndParam ) = 0;
	//���ö����ش�����
	virtual u32 SetNetFeedbackVideoParam( u16 wBufTimeSpan, BOOL32 bRepeatSnd = FALSE ) = 0;

	//��ʼ�ɼ�ͼ��
	virtual u32	StartVideoCap() = 0;
	//ֹͣ�ɼ�ͼ��
	virtual u32	StopVideoCap() = 0;
	//��ʼѹ��ͼ��
	virtual u32	StartVideoEnc() = 0;
	//ֹͣѹ��ͼ��
	virtual u32	StopVideoEnc() = 0;
	//��ʼ����ͼ��
	virtual u32	StartSendVideo( int dwSSRC = 0 ) = 0;
	//ֹͣ����ͼ��
	virtual u32	StopSendVideo() = 0;

	//��ȡ������״̬
	virtual u32	GetEncoderStatus( TMtVncVidEncStatus_Api &tKdvEncStatus ) = 0;
	//��ȡ��������ͳ����Ϣ
	virtual u32	GetEncoderStatis( TMtVncVidEncStatis_Api &tKdvEncStatis ) = 0;
	//�ϱ�ҵ�����ͳ�����
	virtual u32 ReportEncoderStatistic() = 0;

	//����FastUpdate��MediaCtrl��75֡�ڱ�һ��I֡����
	virtual u32	SetFastUpdate( BOOL32 bIsNeedProtect = TRUE ) = 0;
	//pszEndPointId - �ն˵�id, ��ǰ��֧��e164�� dwparam IdLen - �ն�id�ĳ��� dwStreamId - ��id
	virtual u32	SetVideoSendId(const s8* pszEndPointId, u32 dwStreamId) = 0;//���÷��Ͷ˵�id
	virtual u32	GetVideoSendId(s8* pszEndPointId, u32* pdwIdLen, u32* pdwStreamId) = 0;//��ȡ���Ͷ˵�id
	virtual u32	VideoSendEnableNatTraversal(BOOL32 bEnable, const TNetParam_Api *ptKeepAliveParam = NULL) = 0;//�Ƿ�����nat��Խ

	virtual u32 SetSndNetBand(u32 dwSndNetBand) = 0;/*���緢�ʹ���(��λ:Kbps)*/  

	//���òɼ����������Ų���
	virtual u32     SetVidCapToEncZoomPolicy(enZoomMode_Api emZoomMode) = 0;

	//�Ƴ����紫�Ͳ���
	virtual u32		RemoveNetSndParam() = 0;
};

#endif // _I_MTVNCVIDENCODE_H_