/**===========================================================================
 * @file    $Id$
 * @brief   ����MtVideoConfApi�ն���Ƶ������ع��ܽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTAUDIO_H_
#define _I_MTAUDIO_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_vc.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtAudio
 * @brief   ����MtVideoConfApi�ն���Ƶ������ع��ܽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtAudio : public IMtApiIF
{
public:
	//���ؾ�������
	virtual u32 QuiteLocalSpeakerCmd( const BOOL32 bOn ) = 0;
	//������������
	virtual u32 MuteLocalMicCmd( const BOOL32 bOn ) = 0;
	//��ȡ��Ƶ�����豸�б����� (��WIN32)
	virtual u32 GetWaveInDevListCmd() = 0;
	//��ȡ��ǰ����Ƶ�����豸(��WIN32)
	virtual u32 GetCurWaveInDevCmd( ) = 0;
	//��ȡ��Ƶ����豸�б����� (��WIN32)
	virtual u32 GetWaveOutDevListCmd() = 0;
	//��ȡ��ǰ����Ƶ����豸(��WIN32)
	virtual u32 GetCurWaveOutDevCmd() = 0;
	//������Ƶ�����豸���� (��WIN32)
	virtual u32 SetWaveInDevCmd( const TDevInfo_Api& tDevInfo ) = 0;
	//������Ƶ����豸���� (��WIN32)
	virtual u32 SetWaveOutDevCmd( const TDevInfo_Api& tDevInfo ) = 0;
	//��ȡ��Ƶ����������� (��windows��Ƕ��ʽ�豸)
	virtual u32 GetAudOutVolReq(const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecId) = 0;
	//��������������������Ч�������� (��Embed)
	virtual u32 LocalSoundPlayCmd( const EmLocalSoundType_Api emSoundType, const EmLocalSoundIndex_Api emSoundIdx, const BOOL32 bPlay ) = 0;
    //��������������������Чֻ����һ������ (��Embed)
    virtual u32 LocalSoundPlayOnceCmd( const EmLocalSoundType_Api emSoundType, const EmLocalSoundIndex_Api emSoundIdx, const BOOL32 bPlay ) = 0;
	virtual u32 GetLocalSoundPlayStateReq(const EmLocalSoundType_Api emSoundType, const EmLocalSoundIndex_Api emSoundIdx) = 0;
	//����mic����
	virtual u32 DeviceDMicUpgradeCmd( EmUartNum_Api emUartNum, s8 * pchPath ) = 0;
	//����mic�汾��ѯ
	virtual u32 DeviceDMicVersionReq( EmUartNum_Api emUartNum ) = 0;
	//����mic����
	virtual u32 DeviceWMicUpgradeCmd( EmUartNum_Api emUartNum, s8 * pchPath ) = 0;
	//����mic�汾��ѯ
	virtual u32 DeviceWMicVersionReq( EmUartNum_Api emUartNum ) = 0;

public:
	//��ȡ����
	virtual BOOL32 GetLocalSpkQuite() = 0;
	//��ȡ����
	virtual BOOL32 GetLocalMicMute() = 0;
	//�Ƿ�����
	virtual BOOL32 IsLocalMicMute() = 0;
	//�Ƿ���
	virtual BOOL32 IsLocalSpeakerQuite() = 0;
	//��ȡ��Ƶ�����豸�б�(��WIN32)
	virtual TDevInfoList_Api GetWaveInDevList() = 0;
	//��ȡ��Ƶ����豸�б�(��WIN32)
	virtual TDevInfoList_Api GetWaveOutDevList() = 0;

private:

};

#endif // _I_MTAUDIO_H_