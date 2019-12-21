#pragma once

#include "AVCollect.h"

#include <mmdeviceapi.h> 
#include <endpointvolume.h>
#include <audioclient.h>
#include <avrt.h>
#include "AVCollect.h"

#include "mmsystem.h"
#include "AutoLock.h"
#include "Msacm.h"
/*
Revision History:
V1.0.0.1_0218
主要修改：/增加对采样率96000，192000的支持Compile
V1.0.0.1_0310
1 在44100的音频基础上，直接拉平，不转换
2 
V1.0.0.1_0323
1 在44100的音频基础上，利用448转换
V1.0.0.1_0508
1 在回调函数中增加返回声道及采样率
V1.0.0.1_0509
1 在回调函数中增加返回声道及采样率,采样率为实际转换后的采样率，目前都是48000
1.0.0.1_0510
1 修改了音频采集处理，增加动态变更音频采样率的支持
1.0.0.1_0511
1 修改了音频采集处理，发生错误后需要上报，上报时利用回调返回-1的长度
1.0.0.1_1017
1 修改了音频采集处理，改变采集参数，采集声卡的输出，不进行静音处理
1.0.0.1_1020
1 增加测试代码，检测选择的声卡
1.0.0.1_1108
1 修改代码，增加停止时做些保护
1.0.0.1_1116
1 修改了音量的调节
2 检测音量的处理放在单独的线程中
1.0.0.1_1125
1 增加了空指针的判断，避免出现崩溃
2 修改代码，在回调时通知上层为空时，上层会崩溃
1.0.0.1_0118
1 增加了XP系统的判断
2 增加XP系统下的音频采集处理
1.0.0.1_0314
1 增加错误日志
2 判断XP系统换个函数处理
1.0.0.1_0323
1 修改在XP系统中有些函数不支持
--*/


#define AUDIO_CAPTURE_RATE_44100     44100
#define AUDIO_CAPTURE_RATE_48000     48000
#define AUDIO_CAPTURE_RATE_96000     96000
#define AUDIO_CAPTURE_RATE_192000    192000



#pragma comment(lib, "Avrt.lib")

#pragma comment(lib, "msacm32.lib")


#define AUDIO_VERSION_DESC   "V1.0.1.1_0510"    //版本号，版本生成时间
//修改内容
//修改了音频采集处理，发生错误后需要上报，上报时利用回调返回-1的长度
//
#define AUDIO_VERSION_COMPILE   "2018-05-10 15:09:12"    //版本号，版本生成时间


struct render_thread_data
{
	HANDLE hEventStarted;
	HANDLE hEventStop;
	HWND hWndMessage;
	IMMDevice* pDevice;
	DWORD dwUser;         //附加信息，便于传递自定义数据
};

class  CAudioCapture
{
public:
	CAudioCapture(void);
	~CAudioCapture();
public:
	 /*设置音频回调函数
    *******/
	bool SetAudioCallBack(PAVCALLBACK pAudioCallBack, 
		void* dwContext);

	bool Start();

	bool Initialize();
	void Stop();
	void OnThreadEnd();

	void Destroy();

	void Restart();

	///
	BOOL WaveInProcImpl(HWAVEOUT hwo, UINT uMsg, DWORD dwParam1, DWORD dwParam2);
	void StartCapt(int ide);
	void StotCapt();
private:
	bool m_bInited;

	render_thread_data m_stThdData;

	
	/////////////
	unsigned char * m_pRecoderBuf;
	WAVEHDR*m_pWaveHdr;
	int m_recoderNum;// = 0;
	int m_recoderBufLen;
	HWAVEIN m_hWaveIn;
	WAVEFORMATEX m_cWavFormat;

	bool m_bIsCapture;
	CSimpleLock			m_csAudioLock;

	bool GetIsWinXP();
};

