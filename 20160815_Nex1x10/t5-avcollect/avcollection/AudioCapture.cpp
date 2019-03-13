/*

Module Name:

    AudioCapture.cpp

Abstract:

    ��Ƶ�ɼ�����

Author:

Revision History:

--*/
#include "stdafx.h"
#include "AudioCapture.h"

#include <mmreg.h>
#include <mmdeviceapi.h>
#include <Audioclient.h>
#include <process.h>

#include <stdio.h>
//#include <VersionHelpers.h>
#include <math.h>

#include <functiondiscoverykeys.h>
#define SAFE_RELEASE(punk) if ((punk) != NULL) { (punk)->Release(); (punk) = NULL; }

//winmm �ɼ��豸
IMMDevice* g_pDevice;
// �ɼ��߳̾��
HANDLE g_hThreadRender; 
//��Ϣ���
HWND g_hWndMessage=NULL;
//�����¼����
HANDLE g_hEventStarted;
//�����¼����
HANDLE g_hEventStop;

//�ж��߳̾��
HANDLE g_hThreadJudge;
//�����л���
bool g_bIsChanged;


//ϵͳ���б�־
bool g_bIsRun;
//�ص�����
PAVCALLBACK      g_pAudioCBInfo; //����PCM����
void*            g_dwAudContext;

//�Ƿ���Ҫ��Ƶת��
bool g_bNeedChangeSampleRate;

//��Ƶת������
HACMSTREAM g_stStreamHandle;
ACMSTREAMHEADER* g_stAcmHeader;
BYTE *g_pDestData = NULL;
BYTE *g_pTstDestData = NULL;
//����ԭ������Ƶ��ʽ����, �����ж��Ƿ�ı�����Ƶ���
WAVEFORMATEX *g_pWavefx = NULL;

extern void WriteToLog(char*pLog,int nLen);

#define   Max_TempLength      100

char g_chDeviceId[Max_TempLength] ;
//�����ֽ�wchar_t*ת��Ϊ���ֽ�char*  
inline char* UnicodeToAnsi(const wchar_t* szStr)
{
	if (szStr == NULL)
	{
		return NULL;
	}
	int nLen = WideCharToMultiByte(CP_ACP, 0, szStr, -1, NULL, 0, NULL, NULL);
	if (nLen == 0)
	{
		return NULL;
	}
	char* pResult = new char[nLen];
	WideCharToMultiByte(CP_ACP, 0, szStr, -1, pResult, nLen, NULL, NULL);
	//WideCharToMultiByte(CP_ACP, 0, szStr, -1, chStr, nLen, NULL, NULL);
	return pResult;
}


//ԭʼ����
int g_nFirstChange;  //�����״βɼ�������ֵ
int g_nVolumVal;    //ԭʼDb
int g_nOrgOutVal;   //ԭʼ����
int g_nLastVal;    //���һ������
float g_nOutVal;   //��Ҫ�ı��ֵ

/*====================================================================
������		: CAudioCapture
����		: ���캯��
�㷨ʵ��	: ��
����ȫ�ֱ���: ��
�������˵��: ��
�������˵��: ��
����ֵ˵��  : ��
====================================================================*/
CAudioCapture::CAudioCapture(void)
{
	g_pAudioCBInfo=NULL; //����PCM����
	g_hThreadRender =NULL;
    g_dwAudContext=0;
	CoInitialize(NULL);
	g_bIsRun=false;

	//
	m_hWaveIn = NULL;
	m_recoderNum = 0;//2018.1.25 by yujinjin
	g_pDevice = NULL;
	m_pRecoderBuf = NULL;
}


CAudioCapture::~CAudioCapture()
{
	g_bIsRun=false;
	Destroy();
	CoUninitialize();
}

bool CAudioCapture::SetAudioCallBack(PAVCALLBACK pAudioCallBack, 
		void* dwContext)
{
	if(!pAudioCallBack)
	{
		return false;
	}

	//�ص�����
    g_pAudioCBInfo=pAudioCallBack; //����PCM����
    g_dwAudContext=dwContext;

	return true;
}

//��������л�
bool ChangeAudioOut()
{
	bool bresult = false;
	IMMDevice* pDevice = NULL;
	IMMDeviceEnumerator *pMMDeviceEnumerator = NULL;
	HRESULT hr = CoCreateInstance(
		__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL,
		__uuidof(IMMDeviceEnumerator),
		(void**)&pMMDeviceEnumerator);
	if (FAILED(hr)) return false;
	//test 1017
	
	LPWSTR pwszID = NULL;
	TCHAR chMlg[Max_TempLength] = { 0 };

	if (NULL == pMMDeviceEnumerator)
	{
		return false;
	}
	
	hr = pMMDeviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &pDevice);
	if (!pDevice)
	{
		SAFE_RELEASE(pMMDeviceEnumerator);
		return false;
	}
	//test 
	hr = pDevice->GetId(&pwszID);
	char *pchId = UnicodeToAnsi(pwszID);
	sprintf_s(chMlg, Max_TempLength, "%s", pchId);
	if (strcmp(g_chDeviceId, chMlg)!=0)
	{
		bresult = true;
		g_nFirstChange = 0;
	}
	if (pchId)
	{
		delete pchId;
	}

	IAudioEndpointVolume* pAudioEndpointVolume = 0;

	hr = pDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, NULL, (void**)&pAudioEndpointVolume);
	if (FAILED(hr)) {
		SAFE_RELEASE(pDevice);
		SAFE_RELEASE(pMMDeviceEnumerator);

		return false;
		//throw "pDevice->Active";
	}

	if (pAudioEndpointVolume)
	{
		float fVolume;
		hr = pAudioEndpointVolume->GetMasterVolumeLevelScalar(&fVolume);
		//m_nOutVal = fVolume * 100;
		int nVal = fVolume * 100;

	}

	SAFE_RELEASE(pAudioEndpointVolume);
	SAFE_RELEASE(pDevice);
	SAFE_RELEASE(pMMDeviceEnumerator);


	CoTaskMemFree(pwszID);
	pwszID = NULL;
	
	return bresult;
}
/*====================================================================
������		: GetDefaultDevice
����		: ��ȡ��Ƶ��Ĭ���豸
�㷨ʵ��	: ��
����ȫ�ֱ���: ��
�������˵��: ��
�������˵��: ��
����ֵ˵��  : ��Ƶ�豸
====================================================================*/
IMMDevice* GetDefaultDevice()
{
	IMMDevice* pDevice = NULL;
	IMMDeviceEnumerator *pMMDeviceEnumerator = NULL;
	IPropertyStore *pProps = NULL;
	LPWSTR pwszID = NULL;

	HRESULT hr = CoCreateInstance(
        __uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, 
        __uuidof(IMMDeviceEnumerator),
        (void**)&pMMDeviceEnumerator);
	if(FAILED(hr)) return NULL;

	if (NULL == pMMDeviceEnumerator)
	{
		return NULL;
	}

	hr = pMMDeviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &pDevice);
	if (FAILED(hr) && !pDevice)
	{
		SAFE_RELEASE(pMMDeviceEnumerator);
		return pDevice;
	}

	hr = pDevice->GetId(&pwszID);
	if (FAILED(hr))
	{
		SAFE_RELEASE(pDevice);
		SAFE_RELEASE(pMMDeviceEnumerator);
		return pDevice;
	}
	hr = pDevice->OpenPropertyStore(
		STGM_READ, &pProps);

	PROPVARIANT varName;
	// Initialize container for property value.  
	PropVariantInit(&varName);

	// Get the endpoint's friendly-name property.  
	if (!pProps)
	{

		hr = pProps->GetValue(PKEY_Device_FriendlyName, &varName);//�˴����Ի���豸����  
	}

	char *pchDefId = UnicodeToAnsi(pwszID);
	if (pchDefId != NULL)
	{
		sprintf_s(g_chDeviceId, Max_TempLength, "%s", pchDefId);
	}
	
	if (pchDefId)
	{
		delete[] pchDefId;
		pchDefId = NULL;
	}
	CoTaskMemFree(pwszID);
	pwszID = NULL;
	PropVariantClear(&varName);
	SAFE_RELEASE(pProps);
    //pMMDeviceEnumerator->Release();
	
	SAFE_RELEASE(pMMDeviceEnumerator);
	return pDevice;
}

/*=============================================================================
������		 AdjustFormatTo16Bits
����		�����òɼ���Ƶ��ʽ
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����WAVEFORMATEX *pwfx Ĭ�ϵ���Ƶ�ɼ�
����ֵ˵���� �ɹ�����TRUE, ʧ�ܷ���FALSE
=============================================================================*/
bool AdjustFormatTo16Bits(WAVEFORMATEX *pwfx)
{
	bool bRet(FALSE);

	
	g_bNeedChangeSampleRate=false;

	if(pwfx->wFormatTag == WAVE_FORMAT_IEEE_FLOAT)
	{
        pwfx->wFormatTag = WAVE_FORMAT_PCM;
        pwfx->wBitsPerSample = 16;
        pwfx->nBlockAlign = pwfx->nChannels * pwfx->wBitsPerSample / 8;
        pwfx->nAvgBytesPerSec = pwfx->nBlockAlign * pwfx->nSamplesPerSec;

		bRet = TRUE;
	}
	else if(pwfx->wFormatTag == WAVE_FORMAT_EXTENSIBLE)
	{
        PWAVEFORMATEXTENSIBLE pEx = reinterpret_cast<PWAVEFORMATEXTENSIBLE>(pwfx);
        if (IsEqualGUID(KSDATAFORMAT_SUBTYPE_IEEE_FLOAT, pEx->SubFormat))
		{
           pEx->SubFormat = KSDATAFORMAT_SUBTYPE_PCM;
           pEx->Samples.wValidBitsPerSample = 16;
           pwfx->wBitsPerSample = 16;

           pwfx->nBlockAlign = pwfx->nChannels * pwfx->wBitsPerSample / 8;

           pwfx->nAvgBytesPerSec = pwfx->nBlockAlign * pwfx->nSamplesPerSec;

		   char ch[Max_TempLength]={0};
		   sprintf_s(ch,"nSamplesPerSec:%d,nBlockAlign;%d\n",pwfx->nSamplesPerSec,pwfx->nBlockAlign);
		   OutputDebugString(ch);
		   bRet = TRUE;
        } 
	}
	//�������48000������Ҫת��
	if(pwfx->nSamplesPerSec !=  AUDIO_CAPTURE_RATE_48000)
	{
		g_bNeedChangeSampleRate=true;
	}

	return bRet;
}

/*=============================================================================
������		 CreateStream
����		������ת����
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����
����ֵ˵���� �ɹ�����TRUE, ʧ�ܷ���FALSE
=============================================================================*/
bool CreateStream()
{

	g_stAcmHeader =(ACMSTREAMHEADER*)malloc(sizeof(ACMSTREAMHEADER));
	if (g_pDestData == NULL)
	{
		g_pDestData = (BYTE *)malloc(480 * 10);
	}
	g_pTstDestData= (BYTE *)malloc(480*7);
	return true;
}

/*====================================================================
������		: OpenStream
����		: ����Ƶת�����
�㷨ʵ��	: ��
����ȫ�ֱ���: ��
�������˵��: WAVEFORMATEX��IN OUT����Ƶ����
�������˵��: ��
����ֵ˵��  : �����Ƿ�ɹ�
====================================================================*/
bool OpenStream(WAVEFORMATEX *wavFormat)
{
	DWORD maxSize=0;

	if (NULL == wavFormat)
	{
		return false;
	}

	MMRESULT mmr=acmMetrics(NULL,ACM_METRIC_MAX_SIZE_FORMAT,&maxSize);
	bool pass=(mmr==MMSYSERR_NOERROR);
	if(pass)
	{
		LPWAVEFORMATEX sourceFormat=(LPWAVEFORMATEX)new char[maxSize];
		LPWAVEFORMATEX destFormat=(LPWAVEFORMATEX)new char[maxSize];
		memset(sourceFormat,0,maxSize);
		memset(destFormat,0,maxSize);

		sourceFormat->wFormatTag=WAVE_FORMAT_PCM;
		sourceFormat->nChannels=wavFormat->nChannels;
		if(wavFormat->nSamplesPerSec==AUDIO_CAPTURE_RATE_44100)
		{
			sourceFormat->nSamplesPerSec= 44800;
		}
		else
		{
			sourceFormat->nSamplesPerSec= wavFormat->nSamplesPerSec;
		}

		// wavFormat->nSamplesPerSec;
		sourceFormat->wBitsPerSample=wavFormat->wBitsPerSample;
		sourceFormat->cbSize=0;
		sourceFormat->nBlockAlign = sourceFormat->nChannels * sourceFormat->wBitsPerSample / 8;
		sourceFormat->nAvgBytesPerSec = sourceFormat->nBlockAlign * sourceFormat->nSamplesPerSec;

		destFormat->wFormatTag = WAVE_FORMAT_PCM;
		destFormat->nChannels=sourceFormat->nChannels;
		destFormat->nSamplesPerSec=AUDIO_CAPTURE_RATE_48000;
		destFormat->wBitsPerSample=sourceFormat->wBitsPerSample;
		destFormat->cbSize=0;
		destFormat->nBlockAlign =  destFormat->nChannels * destFormat->wBitsPerSample / 8;
		destFormat->nAvgBytesPerSec =  destFormat->nBlockAlign * destFormat->nSamplesPerSec;

		mmr=acmStreamOpen(&g_stStreamHandle,NULL,sourceFormat,destFormat,NULL,0,0,0);
		pass=(mmr==MMSYSERR_NOERROR);

		delete[] sourceFormat;
		delete[] destFormat;
	}
	return pass;

}

//��������
int CountPcmDb(const unsigned char* ptr, size_t size,int nChannel)
{
	int ndb = 0;

	if (NULL == ptr)
	{
		return ndb;
	}

	short int value;

	int i;
	long v = 0;
	for (i = 0; i<size; i += 2* nChannel)
	{
		value = MAKEWORD(*(ptr + i), *(ptr + i + 1));
		v += abs(value);
	}

	v = v / (size / (2 * nChannel));

	if (v != 0) {
		ndb = (int)(20.0*log10((double)v / 65535.0));
	}
	else {
		ndb = -96;
	}

	return ndb;
}


//����PCM��������
//comment     : ��PCM���ݵ��������зŴ�  
//parameter   :   
//            pData   PCM����  
//            nLen    PCM���ݵĳ���  
//            nBitsPerSample  ÿ��Sample��λ����һ��Ϊ8������  
//            multiple    �Ŵ���  
//result      : S_OK �ɹ�  
int AmplifyPCMData(BYTE* pData, int nLen, int nBitsPerSample, float multiple)
{
	int nCur = 0;
	if (NULL == pData)
	{
		return nCur;
	}

	if (16 == nBitsPerSample)
	{
		while (nCur < nLen)
		{
			short* volum = (short*)(pData + nCur);
			long lnVol= (*volum) * multiple;
			//*volum = (*volum) * multiple;
			//short dwData = *volum;
			/*if (tmp > 32767)
				tmp = 32767;
			else if (tmp < -32768)
				tmp = -32768;*/

			if (lnVol < -32768)//-0x8000)
			{
				lnVol = -32768;// -0x8000;
			}
			if (lnVol > SHRT_MAX)//�����Ĵ���   
			{
				lnVol = SHRT_MAX;
			}
			*volum = (short)lnVol;
			*(short*)(pData + nCur) = *volum;
			nCur += 2;
		}

	}
	else if (8 == nBitsPerSample)
	{
		while (nCur < nLen)
		{
			BYTE* volum = pData + nCur;
			*volum = (*volum) * multiple;
			if (*volum > 255)//�����Ĵ���   
			{
				*volum = 255;
			}
			*pData = *volum;
			nCur++;
		}

	}


	/*float multiplier = pow(10, db / 20);
	for (ctr = 0;ctr < 1024;ctr++)
	{
		pcmval = pcm[ctr] * multiplier;
		if (pcmval<32767 && pcmval>-32768)
		{
			pcm[ctr] = pcmval;
		}
		else
			if (pcmval > 32767)
			{


				pcm[ctr] = 32767;


			}
			else
			{
				if (pcmval < -32768)
				{


					pcm[ctr] = -32768;


				}
			}
	}*/

	return S_OK;

}

/*====================================================================
������		: DoConverting
����		: ��Ƶת��������44100���µĲɼ�֡��ת����48000
�㷨ʵ��	: ��
����ȫ�ֱ���: ��
�������˵��: inSourceBufferԭʼ���ݣ�inSourceLength���ݳ��ȣ�outDestBufferĿ�����ݵ�ַ��ioDestLengthת��������ݳ���
�������˵��: ��
����ֵ˵��  : ����ת���ɹ�
====================================================================*/
bool DoConverting(unsigned char*inSourceBuffer,long inSourceLength,
				  unsigned char*outDestBuffer,long *ioDestLength)
{

	if (NULL == inSourceBuffer || NULL == outDestBuffer)
	{
		return false;
	}

	memset(g_stAcmHeader,0,sizeof(ACMSTREAMHEADER));
	DWORD suggestedDestSize = 0;
	acmStreamSize(g_stStreamHandle,inSourceLength,&suggestedDestSize,ACM_STREAMSIZEF_SOURCE);
	_ASSERT(suggestedDestSize<=*ioDestLength);

	//Build ACM header on buffer
	g_stAcmHeader->cbStruct  = sizeof(ACMSTREAMHEADER);
	g_stAcmHeader->cbSrcLength=inSourceLength;
	g_stAcmHeader->pbSrc = inSourceBuffer;
	g_stAcmHeader->cbDstLength=*ioDestLength;
	g_stAcmHeader->pbDst = outDestBuffer;

	//Propare the buffer for acm
	MMRESULT mmr=acmStreamPrepareHeader(g_stStreamHandle,g_stAcmHeader,0);
	bool pass=(mmr==MMSYSERR_NOERROR);
	if(pass)
	{
		mmr = acmStreamConvert(g_stStreamHandle,g_stAcmHeader,ACM_STREAMCONVERTF_BLOCKALIGN);//ACM_STREAMCONVERTF_BLOCKALIGN);
		pass=(mmr==MMSYSERR_NOERROR);
	}
	if (g_stAcmHeader)
	{
		*ioDestLength = g_stAcmHeader->cbDstLengthUsed;
	}
	//�ı�����
	//if (g_nOutVal != 1)
	//{
	//	//m_nOutVal = 1;
	//	AmplifyPCMData(outDestBuffer, *ioDestLength,16, g_nOutVal);
	//}

	
	_ASSERT(g_stAcmHeader->cbSrcLengthUsed==g_stAcmHeader->cbSrcLength);
	acmStreamUnprepareHeader(g_stStreamHandle,g_stAcmHeader,0);
	return pass;
}

bool Converting96To48(unsigned char*inSourceBuffer,long inSourceLength,
				  unsigned char*outDestBuffer,long *ioDestLength)
{
	if (NULL == inSourceBuffer || NULL == outDestBuffer)
	{
		return false;
	}

	memset(g_stAcmHeader,0,sizeof(ACMSTREAMHEADER));
	DWORD suggestedDestSize = 0;
	
	bool pass=false;

	if(!inSourceBuffer)
	{
		return pass;
	}

	if(!outDestBuffer)
	{
		return pass;
	}

	int nindex=0;
	long nlen=0;
	while (nindex<inSourceLength)
	{
		
		outDestBuffer[nlen]=inSourceBuffer[nindex+2];
		outDestBuffer[nlen+1]=inSourceBuffer[nindex+3];
		nlen=nlen +2;
		nindex=nindex+4;
	}
	//�ı�����
	/*if (g_nOutVal != 1)
	{
		AmplifyPCMData(outDestBuffer, nlen, 16, g_nOutVal);
	}*/

	*ioDestLength=nlen;
	return pass;
}

bool Converting192To48(unsigned char*inSourceBuffer,long inSourceLength,
				  unsigned char*outDestBuffer,long *ioDestLength)
{

	if (NULL == inSourceBuffer || NULL == outDestBuffer)
	{
		return false;
	}

	memset(g_stAcmHeader,0,sizeof(ACMSTREAMHEADER));
	DWORD suggestedDestSize = 0;
	
	bool pass=false;

	if(!inSourceBuffer)
	{
		return pass;
	}

	if(!outDestBuffer)
	{
		return pass;
	}

	int nindex=0;
	long nlen=0;

	while (nindex<inSourceLength)
	{
		
		outDestBuffer[nlen]=inSourceBuffer[nindex+6];
		outDestBuffer[nlen+1]=inSourceBuffer[nindex+7];
		nlen=nlen +2;
		nindex=nindex+8;
	}

	//�ı�����
	/*if (g_nOutVal != 1)
	{
		AmplifyPCMData(outDestBuffer, *ioDestLength, 16, g_nOutVal);
	}*/

	*ioDestLength=nlen;
	return pass;
}

/*=============================================================================
������		 CloseStream
����		���ر�ת����
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����
����ֵ˵���� �ɹ�����TRUE, ʧ�ܷ���FALSE
=============================================================================*/
bool CloseStream()
{
	DWORD closeSize = 0;
	MMRESULT mmr= MMSYSERR_NOERROR;
	if (g_stStreamHandle)
	{
		mmr = acmStreamClose(g_stStreamHandle, closeSize);
		g_stStreamHandle = NULL;
	}
	if(g_stAcmHeader)
	{
		free( g_stAcmHeader);
		g_stAcmHeader=NULL;
	}
	if(g_pDestData)
	{
		free( g_pDestData);
		g_pDestData=NULL;
	}

	if(g_pTstDestData)
	{
		free(g_pTstDestData);
		g_pTstDestData=NULL;
	}
	

	bool pass=(mmr==MMSYSERR_NOERROR);

	return pass;
}


/*=============================================================================
������		 CaptureAudio
����		����Ƶ��ȡ
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����HWND ��Ϣ���, IMMDevice* �ɼ��豸, HANDLE �¼�, HANDLE ֹͣ�¼�
����ֵ˵���� Ĭ�Ϸ���0
=============================================================================*/
UINT CaptureAudio(HWND hWndMessage, IMMDevice* pDevice, HANDLE hEventStarted, HANDLE hEventStop)
{
	HRESULT hr;
	IAudioClient *pAudioClient = NULL;
	WAVEFORMATEX *pwfx = NULL;
	REFERENCE_TIME hnsDefaultDevicePeriod(0);
	HANDLE hTimerWakeUp = NULL; 
	IAudioCaptureClient *pAudioCaptureClient = NULL;
	DWORD nTaskIndex = 0;
	HANDLE hTask = NULL;
	BOOL bStarted(FALSE);
	do 
	{
		if (!pDevice)
		{
			return -1;
		}
		hr = pDevice->Activate(__uuidof(IAudioClient), CLSCTX_ALL, NULL, (void**)&pAudioClient);
		if(FAILED(hr)) break;

		if (!pAudioClient)
		{
			return -1;
		}
		hr = pAudioClient->GetDevicePeriod(&hnsDefaultDevicePeriod, NULL);
		if(FAILED(hr)) break;

		hr = pAudioClient->GetMixFormat(&g_pWavefx);

		hr = pAudioClient->GetMixFormat(&pwfx);
		if (FAILED(hr)) break;

		

		if(!AdjustFormatTo16Bits(pwfx)) break;

		OpenStream(pwfx);


		hTimerWakeUp = CreateWaitableTimer(NULL, FALSE, NULL);
		if(hTimerWakeUp == NULL) break;

		SetEvent(hEventStarted);
	
		WAVEFORMATEX *ppClosestMatch=NULL;
		hr=pAudioClient->IsFormatSupported(AUDCLNT_SHAREMODE_SHARED, pwfx,&ppClosestMatch);
	
		hr = pAudioClient->Initialize(AUDCLNT_SHAREMODE_SHARED, AUDCLNT_STREAMFLAGS_LOOPBACK, 0, 0, pwfx, 0);
		if(FAILED(hr)) break;
		
		hr = pAudioClient->GetService(__uuidof(IAudioCaptureClient), (void**)&pAudioCaptureClient);
		if(FAILED(hr)) break;

		if (!pAudioCaptureClient)
		{
			if (pwfx != NULL)
			{
				CoTaskMemFree(pwfx);
				pwfx = NULL;
			}
			return -1;
		}

		/*hTask = AvSetMmThreadCharacteristics(_T("Capture"), &nTaskIndex);
		if (NULL == hTask)
		{
			DWORD dd= GetLastError();
			break;
		}*/

		LARGE_INTEGER liFirstFire;
		liFirstFire.QuadPart = -hnsDefaultDevicePeriod / 2; // negative means relative time
		LONG lTimeBetweenFires = (LONG)hnsDefaultDevicePeriod / 2 / (10 * 1000); // convert to milliseconds

		BOOL bOK = SetWaitableTimer(hTimerWakeUp,&liFirstFire,lTimeBetweenFires,NULL, NULL, FALSE);
		if(!bOK) break;

		hr = pAudioClient->Start();
		if(FAILED(hr)) break;

		bStarted = TRUE;

		HANDLE waitArray[2] = { hEventStop, hTimerWakeUp };
		DWORD dwWaitResult;
		UINT32 nNextPacketSize(0);
		BYTE *pData = NULL;
		UINT32 nNumFramesToRead;
		DWORD dwFlags;
		long lnDestLen=480*10;
		while(g_bIsRun)
		{
			dwWaitResult = WaitForMultipleObjects(sizeof(waitArray)/sizeof(waitArray[0]), waitArray, FALSE, INFINITE);
			if(WAIT_OBJECT_0 == dwWaitResult) break;

			if (WAIT_OBJECT_0 + 1 != dwWaitResult)
			{
				break;
			}

			////��������л�
			if (g_bIsChanged)
			{
				break;
			}

			if (!pAudioCaptureClient)
			{
				return -1;
			}
			hr = pAudioCaptureClient->GetNextPacketSize(&nNextPacketSize);
			if(FAILED(hr))
			{
				//���ӻص�����֪�ϲ��л�ʱ�������ִ���
				
				//if (g_pAudioCBInfo)
				//{
				//	if (g_pDestData && g_bIsRun)
				//	{

				//		//(*g_pAudioCBInfo)(g_pDestData, -1, pwfx->nChannels, (int)AUDIO_CAPTURE_RATE_48000, g_dwAudContext, 0);
				//	}
				//}
				break;
			}

			if (nNextPacketSize == 0) continue;

			hr = pAudioCaptureClient->GetBuffer(
				&pData,
				&nNumFramesToRead,
				&dwFlags,
				NULL,
				NULL
			);
			if(FAILED(hr))
			{
              /*  if (g_pAudioCBInfo && g_bIsRun && g_pDestData)
				{
					(*g_pAudioCBInfo)(g_pDestData, -1, pwfx->nChannels, (int)AUDIO_CAPTURE_RATE_48000, g_dwAudContext, 0);
				}*/
				break;
			}

			if (0 != nNumFramesToRead)
			{
				//TODO:�ش�
				if(g_pAudioCBInfo)
				{
					int nTime=GetTickCount();
					int ndataLen=nNumFramesToRead * pwfx->nBlockAlign;

					if(g_bNeedChangeSampleRate)
					{
						if(pwfx->nSamplesPerSec<=AUDIO_CAPTURE_RATE_44100)
						{
							DoConverting(pData, ndataLen, g_pDestData, &lnDestLen);  //ת����48000
							//int nbacklen=lnDestLen;//480* pwfx->nBlockAlign;

							/*{
								(*g_pAudioCBInfo)(g_pDestData,nbacklen,pwfx->nChannels,(int)AUDIO_CAPTURE_RATE_48000,g_dwAudContext,nTime);
							}*/

							
						}
						else if(pwfx->nSamplesPerSec==AUDIO_CAPTURE_RATE_96000)
						{
							Converting96To48(pData, ndataLen, g_pDestData, &lnDestLen);
							//(*g_pAudioCBInfo)(g_pDestData,lnDestLen,pwfx->nChannels,(int)AUDIO_CAPTURE_RATE_48000,g_dwAudContext,nTime);
						}
						else if(pwfx->nSamplesPerSec==AUDIO_CAPTURE_RATE_192000)
						{
							Converting192To48(pData, ndataLen, g_pDestData, &lnDestLen);
							//(*g_pAudioCBInfo)(g_pDestData,lnDestLen,pwfx->nChannels,(int)AUDIO_CAPTURE_RATE_48000,g_dwAudContext,nTime);
						}
						//if (g_nFirstChange < 2)
						//{
						//	g_nOutVal = 1;
						//	int nVol= CountPcmDb(g_pDestData, lnDestLen, pwfx->nChannels);
						//	
						//	g_nVolumVal = (g_nVolumVal + nVol) / (g_nFirstChange + 1);
						//	g_nFirstChange++;
						//}
						//else
						//{
						//	//m_nOutVal = 1;
						//	if (g_nVolumVal <= -96 && g_nOrgOutVal>0)
						//	{
						//		g_nVolumVal = -96 * g_nOrgOutVal / 100;
						//	}
						//}
						(*g_pAudioCBInfo)(g_pDestData, lnDestLen, pwfx->nChannels, (int)AUDIO_CAPTURE_RATE_48000, g_dwAudContext, nTime);
					}
					else
					{
						
						//if (g_nFirstChange < 2)
						//{
						//	int nVol = CountPcmDb(pData, ndataLen, pwfx->nChannels);

						//	g_nVolumVal = (g_nVolumVal + nVol) / (g_nFirstChange + 1);
						//	g_nFirstChange++;
						//}
						//else
						//{
						//	if (g_nVolumVal <= -96 && g_nOrgOutVal>0)
						//	{
						//		g_nVolumVal = -96 * g_nOrgOutVal / 100;
						//	}
						//}
						////�ı�����
						//if (g_nOutVal != 1)
						//{
						//	AmplifyPCMData(pData, ndataLen, 16, g_nOutVal);
						//}

						(*g_pAudioCBInfo)(pData,ndataLen,pwfx->nChannels,(int)pwfx->nSamplesPerSec,g_dwAudContext,nTime);
					}
				}
			}

			pAudioCaptureClient->ReleaseBuffer(nNumFramesToRead);
		}

	}while(FALSE);

	/*if(hTask != NULL)
	{
		AvRevertMmThreadCharacteristics(hTask);
		hTask = NULL;
	}*/

	SAFE_RELEASE(pAudioCaptureClient);
		
	/*if(pAudioCaptureClient != NULL)
	{
		pAudioCaptureClient->Release();
		pAudioCaptureClient = NULL;
	}*/

	if(pwfx != NULL)
	{
		CoTaskMemFree(pwfx);
		pwfx = NULL;
	}

	if(hTimerWakeUp != NULL)
	{
		CancelWaitableTimer(hTimerWakeUp);
		CloseHandle(hTimerWakeUp);
		hTimerWakeUp = NULL;
	}

	if(pAudioClient != NULL)
	{
		if(bStarted)
		{
			pAudioClient->Stop();
		}

		SAFE_RELEASE(pAudioClient);
		/*pAudioClient->Release();
		pAudioClient = NULL;*/
	}

	return 0;
}

/*=============================================================================
������		 JudgeAudioIsChange
����		����ԭ���ɼ�����Ƶ��ʽ�Ƚ�,�Ƿ������
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����
����ֵ˵���� �����仯Ϊtrue
=============================================================================*/
bool JudgeAudioIsChange(IMMDevice* pDevice)
{
	HRESULT hr;
	IAudioClient *pAudioClient = NULL;
	WAVEFORMATEX *pwfx = NULL;

	bool bResult(false);
	if (!pDevice)
	{
		return bResult;
	}
	
	hr = pDevice->Activate(__uuidof(IAudioClient), CLSCTX_ALL, NULL, (void**)&pAudioClient);
	if(FAILED(hr)) return bResult;

	hr = pAudioClient->GetMixFormat(&pwfx);
	if (FAILED(hr)) return bResult;

	if (!g_pWavefx)
	{

		SAFE_RELEASE(pDevice);
		return bResult;
	}

	if(g_pWavefx->nChannels!=pwfx->nChannels || g_pWavefx->nSamplesPerSec!=pwfx->nSamplesPerSec || g_pWavefx->wBitsPerSample!=pwfx->wBitsPerSample)
	{
		if(g_pWavefx != NULL)
		{
			CoTaskMemFree(g_pWavefx);
			g_pWavefx = NULL;
		}
		bResult=true;
	}
	
	return bResult;
}

/*=============================================================================
������		 JudgeTheadProc
����		����Ƶ�жϲɼ��߳�
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����
����ֵ˵����
=============================================================================*/
UINT __stdcall JudgeTheadProc(LPVOID param)
{
	int nRet = 0;
	CoInitialize(NULL);
	while (g_bIsRun)
	{

		//��������л�
		g_bIsChanged = ChangeAudioOut();
		//if (ChangeAudioOut())
		//{
		//	g_bIsChanged = true;
		//	//break;
		//}
		//else
		//{

		//}
		Sleep(500);

	}
	CoUninitialize();
	return nRet;
}

/*=============================================================================
������		 CaptureTheadProc
����		����Ƶ�ɼ��߳�
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����
����ֵ˵���� 
=============================================================================*/
UINT __stdcall CaptureTheadProc(LPVOID param)
{
	
	CoInitialize(NULL);
	render_thread_data* pData = (render_thread_data*)param;
	if (pData==NULL)
	{
		return -1;
	}
	g_bIsChanged = false;
	/*if (pData)
	{
		return -1;
	}*/
	HWND hWndMessage = pData->hWndMessage;
	HANDLE hEventStop = pData->hEventStop;
	IMMDevice* pDevice = pData->pDevice;
	HANDLE hEventStarted = pData->hEventStarted;
	if (pDevice == NULL)
	{
		return -1;
	}
	//if (hWndMessage == NULL)
	//{
	//	return -1;
	//}
	UINT nRet = CaptureAudio(hWndMessage, pDevice, hEventStarted, hEventStop);

	CoUninitialize();

	//�����ж��Ƿ����ڸı���Ƶ��ʽ���µĲ��ɼ�������ǣ����¿�ʼ�ɼ�
	//2017-10-25 �޸ģ��������ַ�ʽ�˳���ֻҪ���ڲɼ�״̬�����¿�ʼ
	if (g_bIsRun)
	{
		CAudioCapture*pAudioCapt = (CAudioCapture*)pData->dwUser;
		if (pAudioCapt)
		{
			pAudioCapt->Restart();
		}
		g_nFirstChange = 0;
	}


	return nRet;
}


//����:��ȡ��Ƶ����
//	-2 �ָ�����
//	-1 ����
//	
bool GetVolumeLevel()
{
	HRESULT hr;
	IMMDeviceEnumerator* pDeviceEnumerator = 0;
	IMMDevice* pDevice = 0;
	IAudioEndpointVolume* pAudioEndpointVolume = 0;
	IAudioClient* pAudioClient = 0;

	try {
		hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (void**)&pDeviceEnumerator);
		if (FAILED(hr))
		{
			return false;
			//throw "CoCreateInstance";
		}
		hr = pDeviceEnumerator->GetDefaultAudioEndpoint(eRender, eMultimedia, &pDevice);
		if (FAILED(hr))
		{
			SAFE_RELEASE(pDeviceEnumerator);
			return false;
			//throw "GetDefaultAudioEndpoint";
		}
		hr = pDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, NULL, (void**)&pAudioEndpointVolume);
		if (FAILED(hr))
		{
			SAFE_RELEASE(pDevice);
			SAFE_RELEASE(pDeviceEnumerator);
			return false;
			//throw "pDevice->Active";
		}

		float fVolume;
		hr = pAudioEndpointVolume->GetMasterVolumeLevelScalar(&fVolume);
		g_nOrgOutVal = fVolume * 100;
		g_nLastVal = g_nOrgOutVal;

		//hr = pAudioEndpointVolume->SetMasterVolumeLevelScalar(fVolume,&GUID_NULL);
		if (FAILED(hr)) {
			SAFE_RELEASE(pAudioEndpointVolume);
		    SAFE_RELEASE(pDevice);
			SAFE_RELEASE(pDeviceEnumerator);
			return false;
			//throw "SetMasterVolumeLevelScalar";
		}


		//pAudioClient->Release();
		/*pAudioEndpointVolume->Release();
		pDevice->Release();
		pDeviceEnumerator->Release();
*/
		SAFE_RELEASE(pAudioEndpointVolume);
		SAFE_RELEASE(pDevice);
		SAFE_RELEASE(pDeviceEnumerator);

		return true;

	}
	catch (...) {
		SAFE_RELEASE(pAudioEndpointVolume);
		SAFE_RELEASE(pDevice);
		SAFE_RELEASE(pDeviceEnumerator);

	}
	return false;
}

//����:
//	-2 �ָ�����
//	-1 ����
//	
bool SetVolumeLevel(int level)
{
	HRESULT hr;
	IMMDeviceEnumerator* pDeviceEnumerator=0;
	IMMDevice* pDevice=0;
	IAudioEndpointVolume* pAudioEndpointVolume=0;
	//IAudioClient* pAudioClient=0;

	try{
		hr = CoCreateInstance(__uuidof(MMDeviceEnumerator),NULL,CLSCTX_ALL,__uuidof(IMMDeviceEnumerator),(void**)&pDeviceEnumerator);
		if (FAILED(hr))
		{
			return false;
			//throw "CoCreateInstance";
		}
		hr = pDeviceEnumerator->GetDefaultAudioEndpoint(eRender,eMultimedia,&pDevice);
		if (FAILED(hr))
		{
	
			SAFE_RELEASE(pDeviceEnumerator);

			return false;
			//throw "GetDefaultAudioEndpoint";
		}
		if (pDevice == NULL)
		{
	
			SAFE_RELEASE(pDeviceEnumerator);

			return false;
		}
		hr = pDevice->Activate(__uuidof(IAudioEndpointVolume),CLSCTX_ALL,NULL,(void**)&pAudioEndpointVolume);
		if (FAILED(hr)) {
			
			SAFE_RELEASE(pDevice);
			SAFE_RELEASE(pDeviceEnumerator);

			return false;
			//throw "pDevice->Active";
		}
		//hr = pDevice->Activate(__uuidof(IAudioClient),CLSCTX_ALL,NULL,(void**)&pAudioClient);
		//if(FAILED(hr)) throw "pDevice->Active";

		if(level==-2){
			hr = pAudioEndpointVolume->SetMute(FALSE,NULL);
			if (FAILED(hr)) {
				SAFE_RELEASE(pAudioEndpointVolume);
				SAFE_RELEASE(pDevice);
				SAFE_RELEASE(pDeviceEnumerator);

				return false;
				//throw "SetMute";
			}
		}else if(level==-1){
			hr = pAudioEndpointVolume->SetMute(TRUE,NULL);
			if (FAILED(hr))
			{
				SAFE_RELEASE(pAudioEndpointVolume);
				SAFE_RELEASE(pDevice);
				SAFE_RELEASE(pDeviceEnumerator);

				return false;
				//throw "SetMute";
			}
		}else{
			if(level<0 || level>100){
				hr = E_INVALIDARG;
				{
					SAFE_RELEASE(pAudioEndpointVolume);
					SAFE_RELEASE(pDevice);
					SAFE_RELEASE(pDeviceEnumerator);

					return false;
					//throw "Invalid Arg";
				}
			}

			float fVolume;
			fVolume = level/100.0f;
			hr = pAudioEndpointVolume->SetMasterVolumeLevelScalar(fVolume,&GUID_NULL);
			if (FAILED(hr)) {
				SAFE_RELEASE(pAudioEndpointVolume);
				SAFE_RELEASE(pDevice);
				SAFE_RELEASE(pDeviceEnumerator);
				
				return false;
				//throw "SetMasterVolumeLevelScalar";
			}

			//pAudioClient->Release();
			SAFE_RELEASE(pAudioEndpointVolume);
			SAFE_RELEASE(pDevice);
			SAFE_RELEASE(pDeviceEnumerator);

			return true;
		}
	}
	catch(...){
		//if(pAudioClient) pAudioClient->Release();
		SAFE_RELEASE(pAudioEndpointVolume);
		SAFE_RELEASE(pDevice);
		SAFE_RELEASE(pDeviceEnumerator);

		return false;
		//throw;
	}
	return false;
}

/*=============================================================================
������		 Initialize
����		����Ƶ�ɼ���ʼ��
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����
����ֵ˵���� 
=============================================================================*/
bool CAudioCapture::Initialize()
{
	if(m_bInited) return true;
	m_bIsCapture=false;

	
	if(GetIsWinXP()==false)
	{
		do
		{
			g_pDevice = GetDefaultDevice();
			if(g_pDevice == NULL) break;

			g_hEventStop = CreateEvent(NULL, TRUE, FALSE, NULL);
			if(g_hEventStop == NULL) break;

			g_hEventStarted = CreateEvent(NULL, TRUE, FALSE, NULL);
			if(g_hEventStarted == NULL) break;

			m_bInited = TRUE;

		
	
		}while(false);
	}
	else
	{
		m_bInited = TRUE;
	}

	if(!m_bInited)
	{
		Destroy();
	}
	return m_bInited;
}

void CAudioCapture::OnThreadEnd()
{
	if(g_hThreadRender != NULL)
	{
		CloseHandle(g_hThreadRender);
		g_hThreadRender = NULL;
	}
}

/*=============================================================================
������		 Restart
����		��������Ƶ�ɼ� 
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����
����ֵ˵���� 
=============================================================================*/
void CAudioCapture::Restart()
{
	CoInitialize(NULL);

	Stop();
	Destroy();
	Sleep(200);
	Initialize();
	Start();
}

void CAudioCapture::Stop()
{
	g_bIsRun = false;

	if(!m_bInited) return;
	//g_bIsRun=false;
	StotCapt();
	
	if (g_hEventStop != NULL)
	{
		SetEvent(g_hEventStop);

	}
	if( g_hThreadRender != NULL)
	{
		
		OnThreadEnd();
	}
	CAutoLock  csLock(&m_csAudioLock);
	Sleep(100);
	CloseStream();
	//SetVolumeLevel(-2);


}

/*=============================================================================
������		 GetIsWinXP
����		���ж��Ƿ���XP
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����
����ֵ˵����
=============================================================================*/
bool CAudioCapture::GetIsWinXP()
{
	bool bRet = false;

	//2018.1.25 yujinjin   �汾����������verisonhelpers����ļ��Ϳ�
	/*if (!IsWindowsVistaOrGreater())
	{
		bRet = true;
	}*/
	

		//��ȡϵͳ�汾
	OSVERSIONINFOEX osvi;
	BOOL bOsVersionInfoEx;
	//����OSVERSIONINFOEX�ṹ����GetVersionEx()����
	//�������ʧ�ܣ��ɳ���ʹ��OSVERSIONINFO�ṹ
	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	if (!(bOsVersionInfoEx = GetVersionEx((OSVERSIONINFO*)&osvi)))
	{
		osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
		if (!GetVersionEx((OSVERSIONINFO*)&osvi))
			return false;
	}
	//windows xp������
	if (osvi.dwMajorVersion < 6 )
	{
		bRet = true;
	}		 

	return bRet;
}
bool CAudioCapture::Start()
{
	if(!m_bInited) return FALSE;
	g_nOutVal = 1;
	m_bIsCapture = true;

	if(g_hThreadRender != NULL) return TRUE;

	//SetVolumeLevel(-1);
	CreateStream();
	

	//��������ɼ�
	//�ж��Ƿ�winxp��ѡ��ɼ��ķ�ʽ
	if (GetIsWinXP())
	{
		StartCapt(1);
	}
	else
	{
	    //render_thread_data data;
	    m_stThdData.hEventStop = g_hEventStop;
	    m_stThdData.hWndMessage =g_hWndMessage;
	    m_stThdData.pDevice = g_pDevice;
	    m_stThdData.hEventStarted = g_hEventStarted;
	    m_stThdData.dwUser=(DWORD)this;

	    g_bIsRun = true;
	    g_hThreadRender = (HANDLE)_beginthreadex(NULL, 0, &CaptureTheadProc, &m_stThdData, 0, NULL);
	    if(g_hThreadRender == NULL) return FALSE;

	    g_hThreadJudge = (HANDLE)_beginthreadex(NULL, 0, &JudgeTheadProc, &m_stThdData, 0, NULL);


	    HANDLE arWaits[2] = { g_hEventStarted, g_hThreadRender };
	    DWORD dwWaitResult = WaitForMultipleObjects(sizeof(arWaits) / sizeof(arWaits[0]), arWaits, FALSE, INFINITE);
	    if (dwWaitResult != WAIT_OBJECT_0)
	    {
			Stop();
			return FALSE;
	    }
	}
	
	return TRUE;
}

void CAudioCapture::Destroy()
{
	g_bIsRun=false;

	if(g_hWndMessage != NULL
		&& ::IsWindow(g_hWndMessage))
	{
		DestroyWindow(g_hWndMessage);
	}

	g_hWndMessage = NULL;

	if(g_pDevice != NULL)
	{
		SAFE_RELEASE(g_pDevice);
		//g_pDevice = NULL;
	}

	if(g_hEventStop != NULL)
	{
		CloseHandle(g_hEventStop);
		g_hEventStop = NULL;
	}

	if(g_hEventStarted != NULL)
	{
		CloseHandle(g_hEventStarted);
		g_hEventStarted = NULL;
	}

	if(g_pWavefx != NULL)
	{
		CoTaskMemFree(g_pWavefx);
		g_pWavefx = NULL;
	}

	/*if(m_bInited) 
	{
	SetVolumeLevel(-2);
	}*/
	m_bInited = FALSE;

	if (g_stAcmHeader)
	{
		free(g_stAcmHeader);
		g_stAcmHeader = NULL;
	}

	CAutoLock  csLock(&m_csAudioLock);

	if (g_hThreadJudge)
	{
		CloseHandle(g_hThreadJudge);
		//TerminateThread(m_handleBack, 0);
		g_hThreadJudge = 0;
	}

	if (g_hThreadJudge)
	{
		CloseHandle(g_hThreadJudge);
		//TerminateThread(m_handleBack, 0);
		g_hThreadJudge = 0;
	}

	if (g_pDestData)
	{
		free(g_pDestData);
		g_pDestData = NULL;
	}

	if (g_pTstDestData)
	{
		free(g_pTstDestData);
		g_pTstDestData = NULL;
	}

	if (NULL != m_pRecoderBuf)
	{
		delete[]m_pRecoderBuf;
		m_pRecoderBuf = NULL;
	}

	if (NULL != m_pWaveHdr)
	{
		delete[]m_pWaveHdr;
		m_pWaveHdr = NULL;
	}
	
}
BOOL CAudioCapture::WaveInProcImpl(HWAVEOUT hwo, UINT uMsg, DWORD dwParam1, DWORD dwParam2)
{
	if (!g_bIsRun)
	{
		return false;
	}
	// ���Դ򿪺͹ر��豸ʱ�Ĵ���  
	if (uMsg == WIM_DATA)
	{
		LPWAVEHDR pHdr = (LPWAVEHDR)dwParam1;

		//����׼������  
		//MMRESULT mmres =  waveInPrepareHeader(m_hWaveIn, pHdr, sizeof(WAVEHDR));
		//mmres = waveInAddBuffer(m_hWaveIn, pHdr, sizeof(WAVEHDR));

		MMRESULT mmres;// = waveInUnprepareHeader(m_hWaveIn, pHdr, sizeof(WAVEHDR));
		//��������   
		//if (NULL != m_pWavFile)
		//{
		//	fwrite((unsigned char *)(pHdr->lpData), 1, pHdr->dwBytesRecorded, m_pWavFile);
		//	//wav_write_data(m_pWavFile, (unsigned char *)(pHdr->lpData), pHdr->dwBytesRecorded);
		//	//fopen_s(&m_pWavFile, "d:\\¼������.pcm", "wb");
		//	//
		//}
		if (m_bIsCapture == false)
		{
			return false;
		}
		if (g_pAudioCBInfo)
		{
			if (g_pDestData)
			{
				CAutoLock  csLock(&m_csAudioLock);
				if (m_bIsCapture)
				{
					char chLog[1024] = { 0 };
					sprintf_s(chLog, "@@@@@@@@m_bIsCapture:%d\n", m_bIsCapture);
					OutputDebugString(chLog);
					if (pHdr->dwBytesRecorded <= 0)
					{
						/*char chMsg[Max_TempLength] = { 0 };
						sprintf_s(chMsg, Max_TempLength, "waveIn get no data,dwBytesRecorded=0\n");
						WriteToLog(chMsg, strnlen_s(chMsg, Max_TempLength));*/
					}
					else
					{
						memcpy(g_pDestData, (unsigned char *)(pHdr->lpData), pHdr->dwBytesRecorded);
						(*g_pAudioCBInfo)(g_pDestData, pHdr->dwBytesRecorded, m_cWavFormat.nChannels, (int)AUDIO_CAPTURE_RATE_48000, g_dwAudContext, 0);
					}
				}
			}
			else
			{
				 
				//д��־����ʧ��
				/*char chMsg[Max_TempLength] = { 0 };
				sprintf_s(chMsg, Max_TempLength, "waveIn AddBuffer no data,please check the audio\n");
				WriteToLog(chMsg, strnlen_s(chMsg, Max_TempLength));*/

			}
		}
		//����׼������  
		//mmres = waveInPrepareHeader(m_hWaveIn, pHdr, sizeof(WAVEHDR));
		mmres = waveInAddBuffer(m_hWaveIn, pHdr, sizeof(WAVEHDR));

		if (mmres != MMSYSERR_NOERROR)
		{
			// failed, try again.  
			//д��־����ʧ��
			/*char chMsg[Max_TempLength] = { 0 };
			sprintf_s(chMsg, Max_TempLength, "waveInAddBuffer Open error,please check the audio,error:%d\n", mmres);
			WriteToLog(chMsg, strnlen_s(chMsg, Max_TempLength));*/

			//return ;
		}
		//mmres = waveInUnprepareHeader(m_hWaveIn, pHdr, sizeof(WAVEHDR));
		//MMRESULT mmres = waveInAddBuffer(m_hWaveIn, pHdr, sizeof(WAVEHDR));
	}

	return TRUE;
}

BOOL CALLBACK   WaveInProc(HWAVEOUT hwo, UINT uMsg, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2)
{
	CAudioCapture* pPlayer = (CAudioCapture*)dwInstance;
	if (pPlayer == NULL)
	{
		return false;
	}
	
	
	return pPlayer->WaveInProcImpl(hwo, uMsg, dwParam1, dwParam2);
}

void CAudioCapture::StartCapt(int ide)
{
	g_bIsRun = true;

	//�ɼ���Ƶ�ĸ�ʽ���ṹ��  
	m_cWavFormat.wFormatTag = WAVE_FORMAT_PCM;//������ʽΪPCM  
	m_cWavFormat.nSamplesPerSec = 48000;//AUDIO_CAPTURE_RATE_48000;//�����ʣ�16000��/��  
	m_cWavFormat.wBitsPerSample = 16;//�������أ�16bits/��  
	m_cWavFormat.nChannels = 2;//������������2����  
	m_cWavFormat.nBlockAlign = m_cWavFormat.wBitsPerSample/8* m_cWavFormat.nChannels;//һ����Ĵ�С������bit���ֽ�������������  
	m_cWavFormat.nAvgBytesPerSec = m_cWavFormat.nSamplesPerSec * m_cWavFormat.nBlockAlign;//ÿ��������ʣ�����ÿ���ܲɼ������ֽڵ�����  
	
	m_cWavFormat.cbSize = 0;//һ��Ϊ0

	if (m_pRecoderBuf)
	{
		delete[] m_pRecoderBuf;
		m_pRecoderBuf = NULL;
	}
	m_pRecoderBuf = new unsigned char[20 * 1920];
	m_recoderNum = 20;
	m_recoderBufLen = 4 * 1920;
	m_pWaveHdr = new WAVEHDR[20];
	memset(m_pRecoderBuf, 0, 20 * 1920);
	memset(m_pWaveHdr, 0, sizeof(WAVEHDR) * 20);
	////WAVE_MAPPER
	MMRESULT mmres = waveInOpen(&m_hWaveIn, WAVE_MAPPER, &m_cWavFormat, (DWORD_PTR)WaveInProc, (DWORD)this, CALLBACK_FUNCTION);

	if (mmres != MMSYSERR_NOERROR)
	{
		// failed, try again.  
		//д��־����ʧ��
		/*char chMsg[Max_TempLength] = { 0 };
		sprintf_s(chMsg, Max_TempLength, "waveIn Open error,please check the audio,error:%d\n", mmres);
		WriteToLog(chMsg, strnlen_s(chMsg, Max_TempLength));*/
		
		return;
	}

	for (int i = 0; i < m_recoderNum; ++i)
	{
		m_pWaveHdr[i].lpData = (char*)m_pRecoderBuf + i * 1920;
		m_pWaveHdr[i].dwBufferLength = 1920;
		mmres = waveInPrepareHeader(m_hWaveIn, &m_pWaveHdr[i], sizeof(WAVEHDR));
		mmres = waveInAddBuffer(m_hWaveIn, &m_pWaveHdr[i], sizeof(WAVEHDR));

	}

	
	//mmres = waveInAddBuffer(m_hWaveIn, pHdr, sizeof(WAVEHDR));

	mmres = waveInStart(m_hWaveIn);

	if (mmres != MMSYSERR_NOERROR)
	{
		// failed, try again.  
		//д��־����ʧ��
		/*char chMsg[Max_TempLength] = { 0 };
		sprintf_s(chMsg, Max_TempLength, "waveIn start error:%d,please check the audio\n", mmres);
		WriteToLog(chMsg, strnlen_s(chMsg, Max_TempLength));*/

		return;
	}


}

void CAudioCapture::StotCapt()
{
	m_bIsCapture == false;
	CAutoLock  csLock(&m_csAudioLock);
	if (m_hWaveIn)
	{
		char chLog[1024] = { 0 };
		sprintf_s(chLog, "@@@@@@@@StotCapt\n");
		OutputDebugString(chLog);

		MMRESULT mmres = waveInStop(m_hWaveIn);
		waveInReset(m_hWaveIn);
		mmres = waveInClose(m_hWaveIn);
		m_hWaveIn = NULL;
	}
	
	
	if (NULL != m_pRecoderBuf)
	{
		delete[]m_pRecoderBuf;
		m_pRecoderBuf = NULL;
	}

	if (NULL != m_pWaveHdr)
	{
		delete[]m_pWaveHdr;
		m_pWaveHdr = NULL;
	}
}