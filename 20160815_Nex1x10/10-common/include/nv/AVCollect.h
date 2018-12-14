#pragma once
#ifdef CAPTURE_EXPORTS
#define CAPTURE_API __declspec(dllexport)
#else
#define CAPTURE_API __declspec(dllimport)
#endif


/*����������У��ӿ�
  �÷��� �����ȵ���AvMd5Encode���ܣ��ٴ���AvCheckAuth��У�� 
  ****/
#define Av_CheckAuth_MAX_LEN  32
CAPTURE_API bool AvCheckAuth(char* pcBuf, int dwLen );
CAPTURE_API void AvMd5Encode(char* szOut, char* szIn);


//��Ƶ����nwidthΪ������nheightΪ�����ʣ���Ƶ�ǿ����߶�
typedef void (*PAVCALLBACK)(unsigned char *pBuf, int nSize, int nParam1, int nParam2, void* dwContext,int nTimeTap);


class CAPTURE_API CAudioCollect
{
public:
	CAudioCollect(void);
	~CAudioCollect(void);

/*��ʼ�ɼ�����
******/
	int StartAudCapture(bool bAudio);
	/*ֹͣ�ɼ�����
    *******/
	int StopAudCapture(void);
	/*��ʼ������
    *******/
	int InitAudCap();

    /*������Ƶ�ص�����
    *******/
	bool SetAudioCallBack(PAVCALLBACK pAudioCallBack, 
		void* dwContext);

    /*��������
    *******/
	int Destroy(void);

	 /*���ص�ǰʹ�õİ汾��Ϣ
    *******/
	void GetCurrentVer(char*chVersion);
};

/*��Ļ��Ϣ
******/
typedef struct
{
	char chName[32];
	int nWidth;
	int nHeight;
}TMonitorInfo;

class CAPTURE_API CVideoCollect
{
public:
	CVideoCollect(void);
	~CVideoCollect(void);

	/*��ʼ�ɼ�����
	******/
	int StartVidCapture(bool bVedio);
	/*ֹͣ�ɼ�����
    *******/
	int StopVidCapture(void);
	/*������Ƶ�ɼ�֡��
    *******/
	int SetFrameRate(int nRate);
	/*��ʼ������
    *******/
	int InitVideoCap();
    /*������Ƶ�ص�����
    *******/
	bool SetVideoCallBack(PAVCALLBACK pVedioCallBack, 
									void* dwContext);

    /*��������
    *******/
	int Destroy(void);

	 /*���ص�ǰʹ�õİ汾��Ϣ
    *******/
	void GetCurrentVer(char*chVersion);

	/*���ص�ǰϵͳ��������Ϣ
	TMonitorInfo*ptMonitor ��ҪԤ������ռ䣬��ϵͳ�в���ʼ����ֻ�Ǹ�ֵ
    *******/
	int GetAllDisplay(TMonitorInfo*ptMonitor);

	/*ѡ���ȡ����Ļ
	**/
	bool SelectCaptureScreen(int nNum);


	
};
