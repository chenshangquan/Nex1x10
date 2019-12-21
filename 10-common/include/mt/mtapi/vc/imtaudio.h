/**===========================================================================
 * @file    $Id$
 * @brief   负责MtVideoConfApi终端音频控制相关功能接口定义
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
 * @brief   负责MtVideoConfApi终端音频控制相关功能接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtAudio : public IMtApiIF
{
public:
	//本地静音命令
	virtual u32 QuiteLocalSpeakerCmd( const BOOL32 bOn ) = 0;
	//本地哑音命令
	virtual u32 MuteLocalMicCmd( const BOOL32 bOn ) = 0;
	//获取音频输入设备列表命令 (仅WIN32)
	virtual u32 GetWaveInDevListCmd() = 0;
	//获取当前的音频输入设备(仅WIN32)
	virtual u32 GetCurWaveInDevCmd( ) = 0;
	//获取音频输出设备列表命令 (仅WIN32)
	virtual u32 GetWaveOutDevListCmd() = 0;
	//获取当前的音频输出设备(仅WIN32)
	virtual u32 GetCurWaveOutDevCmd() = 0;
	//设置音频输入设备命令 (仅WIN32)
	virtual u32 SetWaveInDevCmd( const TDevInfo_Api& tDevInfo ) = 0;
	//设置音频输出设备命令 (仅WIN32)
	virtual u32 SetWaveOutDevCmd( const TDevInfo_Api& tDevInfo ) = 0;
	//获取音频输出音量请求 (仅windows和嵌入式设备)
	virtual u32 GetAudOutVolReq(const EmCodecComponent_Api emCodecType, const EmCodecComponentIndex_Api emCodecId) = 0;
	//本地铃声、按键音、音效播放命令 (仅Embed)
	virtual u32 LocalSoundPlayCmd( const EmLocalSoundType_Api emSoundType, const EmLocalSoundIndex_Api emSoundIdx, const BOOL32 bPlay ) = 0;
    //本地铃声、按键音、音效只播放一次命令 (仅Embed)
    virtual u32 LocalSoundPlayOnceCmd( const EmLocalSoundType_Api emSoundType, const EmLocalSoundIndex_Api emSoundIdx, const BOOL32 bPlay ) = 0;
	virtual u32 GetLocalSoundPlayStateReq(const EmLocalSoundType_Api emSoundType, const EmLocalSoundIndex_Api emSoundIdx) = 0;
	//数字mic升级
	virtual u32 DeviceDMicUpgradeCmd( EmUartNum_Api emUartNum, s8 * pchPath ) = 0;
	//数字mic版本查询
	virtual u32 DeviceDMicVersionReq( EmUartNum_Api emUartNum ) = 0;
	//无线mic升级
	virtual u32 DeviceWMicUpgradeCmd( EmUartNum_Api emUartNum, s8 * pchPath ) = 0;
	//无线mic版本查询
	virtual u32 DeviceWMicVersionReq( EmUartNum_Api emUartNum ) = 0;

public:
	//获取静音
	virtual BOOL32 GetLocalSpkQuite() = 0;
	//获取哑音
	virtual BOOL32 GetLocalMicMute() = 0;
	//是否哑音
	virtual BOOL32 IsLocalMicMute() = 0;
	//是否静音
	virtual BOOL32 IsLocalSpeakerQuite() = 0;
	//获取音频输入设备列表(仅WIN32)
	virtual TDevInfoList_Api GetWaveInDevList() = 0;
	//获取音频输出设备列表(仅WIN32)
	virtual TDevInfoList_Api GetWaveOutDevList() = 0;

private:

};

#endif // _I_MTAUDIO_H_