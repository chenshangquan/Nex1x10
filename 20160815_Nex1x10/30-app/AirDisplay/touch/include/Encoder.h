// Decoder.h: interface for the CDecoder class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DECODER_H__53DB286A_35A9_48CE_B5CC_DC2AE7D0A62B__INCLUDED_)
#define AFX_DECODER_H__53DB286A_35A9_48CE_B5CC_DC2AE7D0A62B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//#include "cncstruct.h" 

//�����
#define SOFT_CODEC 
#pragma comment(lib, "osplib.lib")

#include "codecwrapper_win32.h"
#pragma comment(lib, "mediasdkvc10.lib")


#include "kdvmedianet.h"
#pragma comment(lib, "kdvmedianetdll.lib")

#include "commonstruct.h"

typedef struct tagAudAACParam
{
    u32 dwSamplePerSecond;
    u32 dwChannel;
}TAudAACParam;



class CCallBackBase
{ 
public:
    //����ص������ĸ�ʽ
    virtual void operator() (BOOL32) = 0;
};

template<class T> class CClsCallBackFun:public  CCallBackBase
{
public:
    //����ص������ĸ�ʽ
    typedef void (T::*MemberFunctionType)(BOOL32);
    
    // �����ʱ����ҪΪ������ֵ
    CClsCallBackFun ( MemberFunctionType pFunc, T* pObject )
    {
        m_pObject = pObject;
        m_pFuc = pFunc ;
    }

    
    virtual void operator()(BOOL32 bValue )
    {
         (m_pObject->*m_pFuc)( bValue );
    }
    
private:
    T* m_pObject;
    MemberFunctionType m_pFuc;	
};


#define LOW_POWER_FRAME      10
#define NORMAL_POWER_FRAME   30


class CEncoder  
{
public:
	CEncoder();
	virtual ~CEncoder();

public:
    CKdvEncoder* GetEncoder();
    void SnapShot();
    BOOL IsPlayed();
   
    void StartPlay();
    void StopPlay();
    void StartEnc();
    void StopEnc(); 


    u16  SetAudioVolume(u8 byVolume );  /*���������������*/	
    u16  GetAudioVolume(u8 &pbyVolume );/*�õ������������*/ 

	u16	SetAudZoominVol(float fZoominVol);//������Ƶ�ɼ��źŷŴ������磺1.0f���ǲ��Ŵ�2.0f���ǷŴ�1����
     
    void SetVidDecZoomPolicy( enZoomMode emZoomMode );
	 
	void SetVideoEncParam(TVideoEncParam tVideoEncParam);          //������Ƶ�������
	void GetVideoEncParam(TVideoEncParam &tVideoEncParam );        //�õ���Ƶ�������
	void SetAudioEncParam(u8 byAudioMode, u16 wAudioDuration = 0); //������Ƶ�������


	u16 SetDeskSharedAudCallback(PDESKSHARECALLBACK pAudCallback, u32 dwContext);
	u16	SetDeskSharedVidCallback(PDESKSHARECALLBACK pVidCallback, u32 dwContext);
	u16 SetVideoCapStdCB(PVIDEOCAPSTDCALLBACK pVidCapStdCallBack, u32 dwContext);

	void SetAskKeyFrm(BOOL32 bIsNeedProtect = TRUE);//����ؼ�֡

	void SetAddLogoIntoEncStream(TFullLogoParam *ptLogoSetting);//����̨��
	void GetMeidaLibVersion(s8 *pszVersion);//��ȡ�ɼ���汾��

	void SetLowPowerMode();     //���ýڵ�ģʽ
	void SetNormalPowerMode();  //������������ģʽ

	bool GetCpuAdjustStatus(BOOL32 &bStatus);

	void SelectCaptureScreen(u32 dwScreenIndex, BOOL32 bStartCap = TRUE);//ѡ��ɼ���Ļ����1��ʼ��1������

    u16	 SetEnableHwEnc(BOOL32 bEnable);//����|�ر� Ӳ��
    u16  GetEncoderStatus(TKdvEncStatus &tKdvEncStatus);//��ȡ������״̬
private:
	void InitEncoder();
	void PlayVideo();
    void StopVideo();
    void PlayAudio();
    void StopAudio();
	void SendError();
	void SetWnd(HWND hwndPlay );
private:
    BOOL m_bPlayed;
    CKdvEncoder     *m_pcEncoder;

    EmTpMediaType   m_emMediaMode;
    BOOL            m_bAudio;
    
	HWND m_hMonitor;

    s16             m_hTimerAskKeyFrm;
    s16             m_hTimerAskKeyFrmForce;// //ǿ������ؼ�֡��һ�����ڸտ�������������������3�ιؼ�֡ PS:���ڽ�������δ�ȶ��Ƿ���Ҫ�ؼ�֡״̬����׼ȷ
};
#endif // !defined(AFX_DECODER_H__53DB286A_35A9_48CE_B5CC_DC2AE7D0A62B__INCLUDED_)
