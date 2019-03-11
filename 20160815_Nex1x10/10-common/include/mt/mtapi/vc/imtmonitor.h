/**===========================================================================
 * @file    $Id$
 * @brief   �����ն��������ͼ����ع��ܽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTMONITOR_H_
#define _I_MTMONITOR_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_vc.h"
#include "mtapi_container.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtMonitor
 * @brief   �����ն��������ͼ����ع��ܽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtMonitor : public IMtApiIF
{
public:
	//video˫����ʼ/ֹͣ����
	virtual u32 VideoAssStreamCmd( const BOOL32 bStart ) = 0;
	//��ʼ�����㲥����
	virtual u32 StartStreamBroadcastCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx, const TNetAddr_Api& tRtpAddr, const TNetAddr_Api& tRtcpAddr ) = 0;
	//ֹͣ�����㲥����
	virtual u32 StopStreamBroadcastCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx ) = 0;
	//ת��ĳһ·��������
	virtual u32 StartStreamTransCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx, const TRtpRtcpPair_Api& tRtpRtcpAddr ) = 0;
	
	virtual u32 IFrameRuestCmd(const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx) = 0;

	//ֹͣĳһ·��������
	virtual u32 StopStreamTransCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx, const TRtpRtcpPair_Api& tRtpRtcpAddr ) = 0;
	//��ʼĳһ·¼������
	virtual u32 StartRecoderCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx, const TRtpRtcpPair_Api& tRtpRtcpAddr ) = 0;
	//ֹͣĳһ·¼������
	virtual u32 StopRecoderCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx, const TRtpRtcpPair_Api& tRtpRtcpAddr ) = 0;
	//��ȡ��ز�������
	virtual u32 GetMonitorParamCmd(  const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx ) = 0;
	//����ĳһ·�����ؼ�֡����
	virtual u32 SendFastUpdateCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx ) = 0;
	//���òɼ����Ŵ������� (��WIN32)
	virtual u32 SetPlayHwndCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx, const u32 hWnd ) = 0;

	//��ղɼ����Ŵ�������(��WIN32)
	virtual u32 ClearWindowCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx ) = 0;
	//�ɼ��������� (��WIN32)
	virtual u32 VidCapCtrlCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx, const BOOL32 bStartCap ) = 0;
	//ץͼ���� (��WIN32)
	virtual u32 GrabPicCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx, const u32 hWnd ) = 0;
	//����ץͼ���� (��WIN32)
	virtual u32 SavePicCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx, const EmPicFormat_Api emPicFormat, const s8 *pszPicPathName ) = 0;
	//����ֻ��ؼ�֡���� (��WIN32)
	virtual u32 SetDecOnlyKeyFrameCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecIdx, const BOOL32 bOn ) = 0;
	//��ȡ��Ƶ�����豸�б����� (��WIN32)
	virtual u32 GetVidCapDevListCmd( ) = 0;
	//���ö໭��������
	virtual u32 SetPIPReq(const EmPiPMode_Api emPiPMode)=0;
	//��ѯ�໭��������
	virtual u32 QueryPIPReq()=0;
	//������ƵԴѡ�����ݲ�ѯ����
	virtual u32 GetLocalVideoViewReq()=0;
	//TL��ȡ��ǰ��Ƶ�ɼ��豸���� (��WIN32)
	virtual u32 GetCurVidCapDevCmd() = 0;
	//������Ƶ�����豸���� (��WIN32)
	virtual u32 SetVidCapDevCmd( const TDevInfo_Api& tDevInfo ) = 0;
	//�ƶ����л����� (��Embed)
	virtual u32 MovePIPCmd( ) = 0;
	//�������л����� (��Embed)
	virtual u32 SwitchPIPCmd( ) = 0;
	//������ƵԴѡ��ָ��
	virtual u32 SelectLocalVideoViewCmd( const EmCameraView_Api& tCfg ) = 0;
	//��ʼ¼������(windowsƽ̨)
	virtual u32 StartRecCmd(const TRecordParam_Api &tRecParam) = 0;
	//ֹͣ¼������(windowsƽ̨)
	virtual u32 StopRecCmd(const BOOL32 bLocal) = 0;
	//��ͣ¼������(windowsƽ̨)
	virtual u32 PauseRecCmd(const BOOL32 bLocal) = 0;
	//����¼������(windowsƽ̨)
	virtual u32 ResumeRecCmd(const BOOL32 bLocal) = 0;
	//����¼����̸澯��ֵ����(windowsƽ̨)
	virtual u32 SetRecDiskAlarmLevelCmd(const TRecordDiskAlarmLevel_Api &tRecAlarmParam) = 0;
   //����̨���������
	virtual u32 SetAddLogoIntoEncStreamCmd(const BOOL32 bAddIntoStream, const TMtFullLogoParam_Api &tLogoParam) = 0;

	virtual u32 SetMobilAddLogoIntoEncStreamCmd( const BOOL32 bAddIntoStream, const TMtFullLogoParam_Api* ptArrFullLogoParam, u8 byCnt ) = 0;
	
	virtual u32 SetMonitorPicShotCmd(EmCodecComponent_Api emCodecType, EmCodecComponentIndex_Api emCodecId, BOOL32 bOn,s32 nIndex) = 0;

	virtual u32 GetMonitorPicShotStatusReq(EmCodecComponent_Api emCodecType, EmCodecComponentIndex_Api emCodecId) = 0;

	virtual u32 MediaDecCallBackControlCmd( const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emStreamIdx, const BOOL32 bStart ) = 0;
    
	virtual u32 CodecSetShowOsd(BOOL32 bShow )=0;

	//��ʼ����¼������(��Ӳ�ն�)
	virtual u32 StartLocalRecCmd(const s8 *pszRecPathName) = 0;
	//ֹͣ����¼������(��Ӳ�ն�)
	virtual u32 StopLocalRecCmd( ) = 0;
	//��ͣ����¼������(��Ӳ�ն�)
	virtual u32 PauseLocalRecCmd( ) = 0;
	//��������¼������(��Ӳ�ն�)
	virtual u32 ContinueLocalRecCmd( ) = 0;
	//��ȡ����¼��״̬������
	virtual u32 GetLocalRecStatusReq( ) = 0;
	//��ȡ����¼��ʼʱ�������
	virtual u32 GetLocalRecStartTimeCmd( ) = 0;
	//ͼƬ��ȡ
	virtual u32 CodecPicGetReq( s32 nIndex ) = 0;
public:
	//5S�ڵ�ǰ�Ƿ񶪰�
	virtual BOOL32 IsStreamLostPack()  = 0;
	//��ǰ������ز�����ȡ
	//��ȡ��Ƶ�����豸�б�(��WIN32)
	virtual TDevInfoList_Api GetVidCapDevList() = 0;
	//ͨ��osd����/�ر�pc˫������ʱ����sky100��sky100��֧��Ӳ˫��
	virtual u32 OsdCtrlPcAssStreamCmd( const BOOL32 bOpen ) = 0;
private:

};

#endif // _I_MTMONITOR_H_