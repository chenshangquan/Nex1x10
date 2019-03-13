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
��Ҫ�޸ģ�/���ӶԲ�����96000��192000��֧��Compile
V1.0.0.1_0310
1 ��44100����Ƶ�����ϣ�ֱ����ƽ����ת��
2 
V1.0.0.1_0323
1 ��44100����Ƶ�����ϣ�����448ת��
V1.0.0.1_0508
1 �ڻص����������ӷ���������������
V1.0.0.1_0509
1 �ڻص����������ӷ���������������,������Ϊʵ��ת����Ĳ����ʣ�Ŀǰ����48000
1.0.0.1_0510
1 �޸�����Ƶ�ɼ��������Ӷ�̬�����Ƶ�����ʵ�֧��
1.0.0.1_0511
1 �޸�����Ƶ�ɼ����������������Ҫ�ϱ����ϱ�ʱ���ûص�����-1�ĳ���
1.0.0.1_1017
1 �޸�����Ƶ�ɼ������ı�ɼ��������ɼ�����������������о�������
1.0.0.1_1020
1 ���Ӳ��Դ��룬���ѡ�������
1.0.0.1_1108
1 �޸Ĵ��룬����ֹͣʱ��Щ����
1.0.0.1_1116
1 �޸��������ĵ���
2 ��������Ĵ�����ڵ������߳���
1.0.0.1_1125
1 �����˿�ָ����жϣ�������ֱ���
2 �޸Ĵ��룬�ڻص�ʱ֪ͨ�ϲ�Ϊ��ʱ���ϲ�����
1.0.0.1_0118
1 ������XPϵͳ���ж�
2 ����XPϵͳ�µ���Ƶ�ɼ�����
1.0.0.1_0314
1 ���Ӵ�����־
2 �ж�XPϵͳ������������
1.0.0.1_0323
1 �޸���XPϵͳ����Щ������֧��
--*/


#define AUDIO_CAPTURE_RATE_44100     44100
#define AUDIO_CAPTURE_RATE_48000     48000
#define AUDIO_CAPTURE_RATE_96000     96000
#define AUDIO_CAPTURE_RATE_192000    192000



#pragma comment(lib, "Avrt.lib")

#pragma comment(lib, "msacm32.lib")


#define AUDIO_VERSION_DESC   "V1.0.1.1_0510"    //�汾�ţ��汾����ʱ��
//�޸�����
//�޸�����Ƶ�ɼ����������������Ҫ�ϱ����ϱ�ʱ���ûص�����-1�ĳ���
//
#define AUDIO_VERSION_COMPILE   "2018-05-10 15:09:12"    //�汾�ţ��汾����ʱ��


struct render_thread_data
{
	HANDLE hEventStarted;
	HANDLE hEventStop;
	HWND hWndMessage;
	IMMDevice* pDevice;
	DWORD dwUser;         //������Ϣ�����ڴ����Զ�������
};

class  CAudioCapture
{
public:
	CAudioCapture(void);
	~CAudioCapture();
public:
	 /*������Ƶ�ص�����
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

