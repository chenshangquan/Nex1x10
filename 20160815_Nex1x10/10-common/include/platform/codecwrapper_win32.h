/* CodecLib.h - Codec API Header */ 

/* Copyright(C) 2001-2002 KDC, All rights reserved. 

*/

#ifndef __CODECWRAPPER_WIN32_H_
#define __CODECWRAPPER_WIN32_H_

#include "KdvDef.h"
#include "kdvtype.h"
#include "kdvmedianet.h"
#include <windows.h>
#include <vector>
using namespace std;
//////////////////////////////////////////////////////////////////////////
#define CODEC_NO_ERROR              (u16)0//�޴�
#define CODEC_ERROR_BASE            (u16)10000//
#define ERROR_CODEC_UNKNOWN	        (u16)10000//��֪���ı���������� 
#define ERROR_CODEC_PARAM           (u16)(CODEC_ERROR_BASE + 1)//��������;  
#define ERROR_DEC_DRAW_HDC	        (u16)(CODEC_ERROR_BASE + 2)//��������ͼ����DC����
#define ERROR_DEC_DRAW_DIBOPEN      (u16)(CODEC_ERROR_BASE + 3)//��������ͼ����򿪴���
#define ERROR_DEC_DRAW_DIBBEGIN     (u16)(CODEC_ERROR_BASE + 4)//��������ͼ��ʽ����
#define ERROR_DEC_DRAW_CLEARWINDOW  (u16)(CODEC_ERROR_BASE + 5)//��������������
#define ERROR_DEC_ICOPEN            (u16)(CODEC_ERROR_BASE + 6)//�������򿪽�����������
#define ERROR_DEC_DECOMPRESSBEGIN   (u16)(CODEC_ERROR_BASE + 7)//���������ý���������ʽ����
#define ERROR_DEC_SETTIMER          (u16)(CODEC_ERROR_BASE + 8)//���������ý��붨ʱ������
#define ERROR_DEC_NO_VIDEO          (u16)(CODEC_ERROR_BASE + 9)//������û�д�����Ƶ
#define ERROR_DEC_SOCKET_CALLBACK   (u16)(CODEC_ERROR_BASE + 10)//���������������¼��ص�����
#define ERROR_DEC_SOCKET_CREATE     (u16)(CODEC_ERROR_BASE + 11)//���������������׽��ִ���
#define ERROR_DEC_NO_AUDIO          (u16)(CODEC_ERROR_BASE + 12)//������û�д�����Ƶ 
#define ERROR_DEC_WAVEOPEN          (u16)(CODEC_ERROR_BASE + 13)//���������ܴ�����*
#define ERROR_DEC_MIXEROPEN         (u16)(CODEC_ERROR_BASE + 14)//���������ܴ�������������
#define ERROR_DEC_WAVEPREHEADER     (u16)(CODEC_ERROR_BASE + 15)//����������������Ƶ����ͷ
#define ERROR_DEC_WAVEWRITE         (u16)(CODEC_ERROR_BASE + 16)//����������������д��Ƶ����
#define ERROR_DEC_WAVE_ENCOPEN      (u16)(CODEC_ERROR_BASE + 17)//���������ܴ���Ƶ������*
#define ERROR_DEC_WAVE_ENCPREHEADER (u16)(CODEC_ERROR_BASE + 18)//����������������Ƶ����ͷ
#define ERROR_DEC_WAVE_ENCCONVERT   (u16)(CODEC_ERROR_BASE + 19)//��������Ƶ�������
#define ERROR_DEC_WAVESTART         (u16)(CODEC_ERROR_BASE + 20)//��������ʼ��Ƶ���Ŵ���
#define ERROR_DEC_WAVESTOP          (u16)(CODEC_ERROR_BASE + 21)//������ֹͣ��Ƶ���Ŵ���
#define ERROR_DEC_MIXER_SETVOLUME   (u16)(CODEC_ERROR_BASE + 22)//������������������
#define ERROR_DEC_MIXER_GETVOLUME   (u16)(CODEC_ERROR_BASE + 23)//��������ȡ��������
#define ERROR_DEC_MIXERMUTE         (u16)(CODEC_ERROR_BASE + 24)//���������þ�������
#define ERROR_DEC_AUDIOOUT_EXIT     (u16)(CODEC_ERROR_BASE + 25)//��������Ƶ�߳��˳�����
#define ERROR_DEC_HARDCREATE        (u16)(CODEC_ERROR_BASE + 26)//����������Ӳ��������ʧ��
#define ERROR_DEC_CREATE            (u16)(CODEC_ERROR_BASE + 27)//�������������� 
#define ERROR_DEC_NEW               (u16)(CODEC_ERROR_BASE + 28)//�������ɳ���
#define ERROR_DEC_SETAUDIO_ADDR     (u16)(CODEC_ERROR_BASE + 29)//������������Ƶ��ַ����  
#define ERROR_DEC_AUDIO_LEN         (u16)(CODEC_ERROR_BASE + 30)//��Ƶ���������ݳ��Ȳ���ȷ
#define ERROR_DEC_NO_MASK           (u16)(CODEC_ERROR_BASE + 31)//�Ȳ����������Ҳ����Ӳ������
#define ERROR_SOCKOBJ_NULL          (u16)(CODEC_ERROR_BASE + 32)//������ն��󲻴���
#define ERROR_DEC_NET_INVALIDPARAM  (u16)(CODEC_ERROR_BASE + 33)//��Ч��������ղ��� 
#define EROOR_DEC_NO_IMPLEMENT      (u16)(CODEC_ERROR_BASE + 34)//�˹��ܻ���֧�� 
#define ERROR_DEC_SETSTATE          (u16)(CODEC_ERROR_BASE + 35)//���������ý�������״̬����

#define ERROR_ENC_CAPWIN            (u16)(CODEC_ERROR_BASE + 100)//�������������񴰿ڳ���
#define ERROR_ENC_CAPDRIVER         (u16)(CODEC_ERROR_BASE + 101)//������û�з��ֲ���
#define ERROR_ENC_DIBOPEN           (u16)(CODEC_ERROR_BASE + 102)//��������ͼ����򿪴���
#define ERROR_ENC_DRAWHDC           (u16)(CODEC_ERROR_BASE + 103)//��������ͼ���ڴ򲻿�
#define ERROR_ENC_ICOPEN            (u16)(CODEC_ERROR_BASE + 104)//�������������򿪳���
#define ERROR_ENC_DRAWPOS           (u16)(CODEC_ERROR_BASE + 105)//�������õ���ͼλ�ó���
#define ERROR_ENC_DIBBEGIN          (u16)(CODEC_ERROR_BASE + 106)//���������û�ͼ��ʽ����
#define ERROR_ENC_GET_VIDEOBMP      (u16)(CODEC_ERROR_BASE + 107)//�������õ�ͼ���ʽ����
#define ERROR_ENC_SET_VIDEOBMP      (u16)(CODEC_ERROR_BASE + 108)//����������ͼ���ʽ����
#define ERROR_ENC_GET_CAPSET        (u16)(CODEC_ERROR_BASE + 109)//�������õ��������ó���
#define ERROR_ENC_SET_CAPSET        (u16)(CODEC_ERROR_BASE + 110)//���������ò������ó���
#define ERROR_ENC_SET_AUDIOFORMATE  (u16)(CODEC_ERROR_BASE + 111)//������������Ƶ�����ʽ����
#define ERROR_ENC_STREAMOPEN        (u16)(CODEC_ERROR_BASE + 112)//����������Ƶ����������
#define ERROR_ENC_PREHEADER         (u16)(CODEC_ERROR_BASE + 113)//������׼����Ƶ����ͷ����
#define ERROR_ENC_MIXEROPEN         (u16)(CODEC_ERROR_BASE + 114)//�������������������������
#define ERROR_ENC_MIXER_SETVOLUME   (u16)(CODEC_ERROR_BASE + 115)//������������������
#define ERROR_ENC_MIXER_GETVOLUME   (u16)(CODEC_ERROR_BASE + 116)//�������õ���������
#define ERROR_ENC_ALREADY           (u16)(CODEC_ERROR_BASE + 117)//������״̬�Ѿ�����
#define ERROR_ENC_STOPCAP           (u16)(CODEC_ERROR_BASE + 118)//�������޷�ֹͣ����
#define ERROR_ENC_SETSTATE          (u16)(CODEC_ERROR_BASE + 119)//���������ñ����������
#define ERROR_ENC_ENCBEGIN          (u16)(CODEC_ERROR_BASE + 120)//���������ñ���֡��ʽ
#define ERROR_ENC_SETTIMER          (u16)(CODEC_ERROR_BASE + 121)//���������ö�ʱ������
#define ERROR_ENC_STOPVIDEOENC      (u16)(CODEC_ERROR_BASE + 122)//������ֹͣ��Ƶ�������
#define ERROR_ENC_NO_SETPARAM       (u16)(CODEC_ERROR_BASE + 123)//������û�����ò���
#define ERROR_ENC_STOPAUDIOENC      (u16)(CODEC_ERROR_BASE + 124)//��������Ƶ�������
#define ERROR_ENC_CREATESOCK        (u16)(CODEC_ERROR_BASE + 125)//���������õ��ص�ַ����
#define ERROR_ENC_STOPSENDVIDEO     (u16)(CODEC_ERROR_BASE + 126)//������ֹͣ������Ƶ����
#define ERROR_ENC_STOPSENDAUDIO     (u16)(CODEC_ERROR_BASE + 127)//������ֹͣ������Ƶ����
#define ERROR_ENC_AUDIOENC          (u16)(CODEC_ERROR_BASE + 128)//��������Ƶת������
#define ERROR_ENC_NO_CREATE         (u16)(CODEC_ERROR_BASE + 129)//�������������ɹ�  
#define ERROR_ENC_SOCK_INIT         (u16)(CODEC_ERROR_BASE + 130)//�����������׽��ֲ���2.2��
#define ERROR_ENC_STARTCAP          (u16)(CODEC_ERROR_BASE + 131)//�������޷���ʼ����
#define ERROR_ENC_CAP_WIDTH         (u16)(CODEC_ERROR_BASE + 132)//����������̫֡��
#define ERROR_DRAW_FORMATE          (u16)(CODEC_ERROR_BASE + 133)//��ͼ��ʽ��֧��
#define ERROR_HARDENC_FORMATE       (u16)(CODEC_ERROR_BASE + 134)//Ӳ����֧�ֵĻ�ͼ��ʽ
#define ERROR_ENC_CAP_FORMATE       (u16)(CODEC_ERROR_BASE + 135)//�ɼ���ʽ�ͱ����ʽ��ƥ��
#define ERROR_ENC_NEW               (u16)(CODEC_ERROR_BASE + 136)//�������ɳ���
#define ERROR_ENC_INVALID_PARAM     (u16)(CODEC_ERROR_BASE + 137)//��Ч�Ĳ���
#define ERROR_ENC_CREATE_EVENT      (u16)(CODEC_ERROR_BASE + 138)//���ܴ����¼� 
#define EROOR_ENC_NO_IMPLEMENT      (u16)(CODEC_ERROR_BASE + 139)//�˹��ܻ���֧�� 
#define ERROR_ENC_GETSTATE          (u16)(CODEC_ERROR_BASE + 140)//�������õ������������
#define ERROR_DECENC_CREATE_THREAD  (u16)(CODEC_ERROR_BASE + 141)//���ܴ����߳�

#define ERROR_ENC_CAP_DESKTOP_FORMAT    (u16)(CODEC_ERROR_BASE + 142)//Ҫ��ı��������沶���ʽ����֧��
#define ERROR_ENC_CREATE_DESKTOP_MEMDC  (u16)(CODEC_ERROR_BASE + 143)//���������ڴ�dcʧ��
#define ERROR_ENC_CAP_DESKTOP_WIDTH     (u16)(CODEC_ERROR_BASE + 144)//��������������ֱ��ʸ��ڵ�ǰ����ʵ�ʷֱ���
#define ERROR_ENC_CAP_DESKTOP_BITCOUNT  (u16)(CODEC_ERROR_BASE + 145)//��������������λ����ڵ�ǰ����ʵ��λ��
#define ERROR_ENC_INVILAD_FILE      (u16)(CODEC_ERROR_BASE + 146)//�ṩ���ļ���Ч
#define ERROR_ENC_OPERATE_FILE     (u16)(CODEC_ERROR_BASE + 147)//�ļ���������ָ�����ļ�����ʧ��
/*=======================================����������ṹ�Ķ���=================================*/

#ifdef _KDV_CODEC_DLL_
#define MEDIA_API _declspec(dllexport)
#else
#define MEDIA_API _declspec(dllimport)
#endif

#define 	CAMERAPARAM_HUE				0
#define 	CAMERAPARAM_WHITEBALANCE	1
#define 	CAMERAPARAM_CONTRAST		2
#define 	CAMERAPARAM_SATURATION		3
#define 	CAMERAPARAM_SHARPNESS		4

#define CAP_YUV_FORMAT_MJPG			(u8)0
#define CAP_YUV_FORMAT_I420			(u8)1
#define CAP_YUV_FORMAT_RGB24		(u8)2
#define CAP_YUV_FORMAT_YUV2			(u8)3

/*����ģʽ mp3*/
#define	 AUDIO_MODE_WORST        (u8)0/*���*/
#define	 AUDIO_MODE_BAD          (u8)1/*��  */
#define	 AUDIO_MODE_NORMAL       (u8)2/*һ��*/
#define	 AUDIO_MODE_FINE         (u8)3/*��  */
#define	 AUDIO_MODE_BEST         (u8)4/*���*/
//G.711
#define  AUDIO_MODE_PCMA         (u8)5//a law
#define  AUDIO_MODE_PCMU         (u8)6//u law 
//G.723
#define AUDIO_MODE_G723_6        (u8)7 
#define AUDIO_MODE_G723_5        (u8)8
//G.728
#define AUDIO_MODE_G728			 (u8)9 
//G.722
#define AUDIO_MODE_G722			 (u8)10 
//G.729
#define AUDIO_MODE_G729			 (u8)11 
//G.7221 24k
#define AUDIO_MODE_G7221_24		 (u8)12 
//adpcm
#define AUDIO_MODE_ADPCM		 (u8)13 
//aaclc
#define AUDIO_MODE_AACLC_32      (u8)14
#define AUDIO_MODE_AACLD_32_SINGLE      (u8)15
#define AUDIO_MODE_AACLC_32_SINGLE	(u8)16
//G.7221 32K
#define AUDIO_MODE_G7221_32			(u8)17
//G.7221 48k
#define AUDIO_MODE_G7221_48			(u8)18
#define AUDIO_MODE_G719				(u8)19

//ld ˫������
#define AUDIO_MODE_AACLD_32_UNDEF	(u8)20
//iBLC
#define AUDIO_MODE_IBLC         (u8)21
//iSac
#define AUDIO_MODE_ISAC_16         (u8)22
#define AUDIO_MODE_ISAC_32         (u8)23
//OPUS
#define AUDIO_MODE_OPUS         (u8)24

#define  CAP_CAMERA_ONLY         (u8)0x02 //      CAMERA��Ƶ���ݲ���
#define  CAP_DESKTOP_ONLY        (u8)0x04 //	    DESKTOP������Ƶ���ݲ���
#define  CAP_DESKSHARE_ONLY		 (u8)0x08 //   ����Ͷ��
#define  CAP_FILE_AV_BOTH		 (u8)0x08 //��ָ���ļ���Ŀǰ֧��kdc¼���������asf�ļ�����
#define MAX_DEV_NAME_LEN		  256

#define PIC_ENCODE_JPEG			 (u8)1     //ץȡͼƬ����ѡ�����ͼƬ��ʽ
#define PIC_ENCODE_BMP			 (u8)2     // 

#define MAX_FILE_PATH_LEN        256
/*����������*/
typedef struct tagInitVidEncoder
{  
	HWND    m_hwVideoPreview;
	u32		m_dwCapType;	//CAP_CAMERA_ONLY or CAP_DESKTOP_ONLY or CAP_DESKSHARE_ONLY
	s32		m_nCpuID;		  //Ĭ��0 ���� 
}TInitVidEncoder;

/*��Ƶ����������*/
typedef struct tagInitVidDecoder
{
	HWND    m_hwPlayVideo;
	s32		m_nCpuID;		  //Ĭ��0 ���� 
	//Ĭ�ϵ��ļ�Դ not impl yet
	wchar_t*	m_pchFileName;
	u8		m_byFileNameSize;
}TInitVidDecoder;

/*��Ƶ����������*/
typedef struct tagInitAudDecoder
{
	s32		m_nCpuID;		   //Ĭ��0 ���� 
	u32   m_dwReserved;         
}TInitAudDecoder;

typedef struct tagInitAudEncoder
{
	s32		m_nCpuID;		    //Ĭ��0 ���� 
	u32		m_dwReserved;
}TInitAudEncoder;

/*��Ƶ�������*/
typedef struct VideoEncParam
{
	u8  m_byEncType;   /*ͼ���������*/
    u8  m_byRcMode;    /*ͼ��ѹ�����ʿ��Ʋ���*/
    u16 m_byMaxKeyFrameInterval;/*I֡�����P֡��Ŀ*/
    u8  m_byMaxQuant;  /*�����������(1-31)*/
    u8  m_byMinQuant;  /*��С��������(1-31)*/
    u16 m_wBitRate;    /*���������(Kbps,1K=1024)*/
	u16 m_wMaxBitRate;  
	u16 m_wMinBitRate;
	u32 m_dwSndNetBand;/*���緢�ʹ���(��λ:Kbps)*/   
	u16 m_wEncVideoWidth;//��������ͼ���
	u16 m_wEncVideoHeight;//��������ͼ���
	u8	m_byFrameRate;  /*֡��(default:25)*/
	u8  m_byEncLevel;	//������������ 0:LV_QUALITY_PRIOR,1:LV_SPEED_PRIOR,2:LV_HPSINGLE_PRIOR,3:LV_HPMULTE_PRIOR
}TVideoEncParam;
typedef struct VideoCapParam
{
	u16	wVideoWidth; //��Ƶ����ͼ����(default:640)
	u16	wVideoHeight;//��Ƶ����ͼ��߶�(default:480)
	u8	byFrameRate; //��Ƶ����֡��(default:25)   ��֡��>=1���� m_byFrameRate �� fps, ��֡��<1���� m_byFrameRate �� spf  
	BOOL32 bUseSpecifyFormat; //Ĭ��false��ý��Ĭ��ʹ��mjpeg
	u8  byFormat;    // CAP_YUV_FORMAT_MJPG CAP_YUV_FORMAT_I420 �� 
}TVideoCapParam;


typedef struct TDevNameInfo
{
	wchar_t m_achDevName[MAX_DEV_NAME_LEN];
	wchar_t m_achDevGUID[MAX_DEV_NAME_LEN];   //�����������ַ�����һ��
}TDevNameInfo;
/*������״̬*/
typedef struct KdvEncStatus
{
	BOOL32 			m_bVideoSignal;			/*�Ƿ�����Ƶ�ź�*/
	BOOL32	        m_bVideoCapStart; /*�Ƿ�ʼ��Ƶ����*/
	BOOL32			m_bAudioCapStart; /*�Ƿ�ʼ��Ƶ����*/
	BOOL32			m_bVideoEncStart; /*�Ƿ�ʼ��Ƶ����*/
	BOOL32			m_bAudioEncStart; /*�Ƿ�ʼ��Ƶ����*/
	BOOL32			m_bNetSndVideoStart;/*�Ƿ�ʼ��Ƶ����*/
	BOOL32			m_bNetSndAudioStart;/*�Ƿ�ʼ��Ƶ����*/

	TVideoEncParam	m_tVideoEncParam; /*��Ƶ�������*/
	u8            m_byAudioEncParam;/*��Ƶ����ģʽ*/
	u8			  m_byAudEncMediaType; /*��Ƶ����ý������*/	
	TMnetNetParam     m_tVideoSendAddr; /*��Ƶ���͵�ַ*/
	TMnetNetParam     m_tAudioSendAddr; /*��Ƶ���͵�ַ*/
	u32           m_dwSetEncParam; //����Ӳ�������������
	u32           m_dwVideoSend;   //�ѷ��͵���Ƶ����
	u32           m_dwAudioSend;   //�ѷ��͵���Ƶ����

}TKdvEncStatus;


/*������ͳ����Ϣ*/
typedef struct KdvEncStatis
{
    u8   m_byVideoFrameRate;/*��Ƶ֡��*/
    u32  m_dwVideoBitRate;  /*��Ƶ�����ٶ�*/
    u32  m_dwAudioBitRate;  /*���������ٶ�*/
    u32  m_dwVideoPackLose; /*��Ƶ��֡��*/
    u32  m_dwVideoPackError;/*��Ƶ��֡��*/
    u32  m_dwAudioPackLose; /*������֡��*/
    u32  m_dwAudioPackError;/*������֡��*/
	u32  m_wAvrVideoBitRate;   /*1��������Ƶ����ƽ������*/
	u32	 m_wAvrAudioBitRate;   /*1��������������ƽ������*/
}TKdvEncStatis;


/*������״̬*/
typedef struct KdvDecStatus
{
	BOOL32	m_bVideoDecStart;/*�Ƿ�ʼ��Ƶ����*/
	BOOL32	m_bAudioDecStart;/*�Ƿ�ʼ��Ƶ����*/
	BOOL32	m_bRcvVideoStart;/*�Ƿ�ʼ��Ƶ����*/
	BOOL32	m_bRcvAudioStart;/*�Ƿ�ʼ��Ƶ����*/
	TMnetNetParam   m_tAudioRcvAddr;/*��Ƶ���ص�ַ*/
	TMnetNetParam   m_tVideoRcvAddr;/*��Ƶ���ص�ַ*/
	BOOL32	m_bAudioOutThread;/*�Ƿ����������̴߳��*/
	BOOL32	m_bVideoCodecThread;/*�Ƿ�Video�����̴߳��*/
	u32   m_dwAudioDecType;     //��Ƶ��������
	u32   m_dwVideoDecType;     //��Ƶ��������
}TKdvDecStatus;

/*������ͳ����Ϣ */
typedef struct KdvDecStatis
{
	u8	  m_byVideoFrameRate;/*��Ƶ����֡��*/
	u32	  m_dwVideoBitRate;   /*��Ƶ��������*/
	u32	  m_dwAudioBitRate;   /*������������*/
	u32   m_dwVideoRecvFrame;/*�յ�����Ƶ֡��*/
	u32   m_dwAudioRecvFrame;/*�յ�������֡��*/
	u32   m_dwVideoLoseFrame;/*��ʧ����Ƶ֡��*/
	u32   m_dwAudioLoseFrame;/*��ʧ������֡��*/
    u16   m_wVideoLoseRatio;//��Ƶ��ʧ��,��λ��% 	
	u16   m_wAudioLoseRatio;//��Ƶ��ʧ��,��λ��% 	
	u32   m_dwPackError;/*��֡��*/ 
	u32   m_dwIndexLose;/*��Ŷ�֡*/
	u32   m_dwSizeLose; /*��С��֡*/
	u32   m_dwFullLose; /*����֡*/	
	u32   m_wAvrVideoBitRate;   /*1��������Ƶ����ƽ������*/
	u32	  m_wAvrAudioBitRate;   /*1��������������ƽ������*/
	BOOL32 m_bVidCompellingIFrm;  /*��Ƶǿ������I֡*/								  
	u32   m_dwDecdWidth;	/*�����Ŀ�*/
	u32   m_dwDecdHeight;   /*�����ĸ�*/
	u16   LastVideoBitRate; //�ϴ�ͳ�Ƶ�����
    u32   GetDecoderStatisnum;//���ʲ������ֵ����
	u32	  m_dwVidPackLoseNum;//��Ƶ��������080905
	u16   m_wVidPhyPackLoseRatio;//�ش�ǰ����Ƶ������
	u16   m_wVidPackLoseRatio;//�ش������Ƶ������
	u16   m_wAudPhyPackLoseRatio;//�ش�ǰ����Ƶ������
	u16   m_wAudPackLoseRatio;//�ش������Ƶ������	
	u32   m_dwTotalPackNum; //���յ��ܰ���
}TKdvDecStatis; 


typedef struct
{
	u32 dwErrorId;
}TErrorDescription;


struct TDecoderRef
{
	HWND			m_hwPlayVideo;
	s32				m_nVideoCpuId;
	s32				m_nAudioCpuId;
	TErrorDescription	m_tErrorDescription;
};

struct TDecoderStatus
{
	KdvDecStatus	m_kdsDecoderStatus;
	KdvDecStatis	m_kdsDecoderStatics;	
};

struct TEncoderRef
{
	HWND			m_hPreWnd;
	s32				m_nVideoCpuId;
	s32				m_nAudioCpuId;
	TErrorDescription	m_tErrorDescription;
};

struct TEncoderStatus
{
	KdvEncStatus	m_kdsEncStatus;
	KdvEncStatis	m_kdsEncStatics;
};

//XXX Τ������callback encoded audio/video frames for recording purpose
typedef void (*PVIDEOCALLBACK)(u8* pMp4Data, s32 nMp4Data, s32 nCodecID, s16 nWidth, s16 nHeight, u32 dwContext);
typedef void (*PVIDEOI420CALLBACK)(u8* pData, s32 nData, s16 nWidth, s16 nHeight, u32 dwContext);
typedef void (*PAUDIOCALLBACK)(u8 buAudioMode, const u8 *pBuf, s32 nSize, u32 dwContext);
typedef void (*PAUDIOPCMCALLBACK)(u8 *pBuf, s32 nSize, u32 dwSampleRate, u32 dwBitWidth, u32 dwChannel, u32 dwContext);
typedef void (*PAUDIOCAPERRCALLBACK)(void* pParam);
typedef void (*PAUDIOCAPDEVICECHANGE)(u32 dwContext, const vector<TDevNameInfo>& vecInsertlist, const vector<TDevNameInfo>& vecRemoveList);
typedef void (*PVOICECHECK)(CHAR cMode, u32 dwContext);
typedef void (*PDRAWCALLBACK)(HDC hDrawDC, u32 dwContext);
typedef void (*PSTATICPICCALLBACK)(u8 *pBuf, u32 dwSize, BITMAPINFOHEADER* pHead, u32 dwParam);

typedef struct tagVoiceCheck
{
	s32			m_nBGTime;
	s32			m_nThreshold;
	PVOICECHECK	m_pCallBack;
	u32         m_dwContext;
}TVoiceCheck;

typedef void (*PGETAUDIOPOWER)(u8 byAudioPower, u32 dwContext);
typedef void (*PVIDEODEVICECHECK)(u32 dwContext, const vector<TDevNameInfo>& vecInsertlist, const vector<TDevNameInfo>& vecRemoveList);
typedef void (*PGETDISKCHECK)(u8 byAlarmLevel, u32 dwContext);

/**********����Ͷ�����ݻص�����***********/
#define AUDIO_CAPERROR  -1
typedef void (*PDESKSHARECALLBACK)(void *pFrame, u32 dwContext);
typedef void (*PDAUDERRORCODECALLBACK)(s32 dwErrorcode, s32 dwContext);
typedef void (*PVIDEOCAPSTDCALLBACK)(u32 dwWidht, u32 dwHeight, u32 dwContext);
/****************************/

//̨�����������������Ϣ����
typedef struct tagTranspDColor
{
	u8 RColor;          //R����
	u8 GColor;          //G����
	u8 BColor;          //B����	
	u8 u8Transparency;  //͸����(0��ʾȫ͸����255��ʾ��͸����1~254��ʾ����͸��)
}TTranspColor;

typedef struct tagAddLogoParam
{
    float fXPosRate;		//��ȱ�����xpos = ��ͼ��*fXPosRate
    float fYPosRate;		//�߶ȱ�����ypos = ��ͼ��*fYPosRate
    u32   dwLogoBgWidth;	//�ο���ͼ�Ŀ�
    u32   dwLogoBgHeight;	//�ο���ͼ�ĸ�
    TTranspColor tBackBGDColor;    
}TAddLogoParam;

typedef struct
{
    wchar_t aLogoBmpPath[MAX_FILE_PATH_LEN];	
	u32     dwLogoPathLen;
    TAddLogoParam tLogoParam;
}TFullLogoParam;

typedef struct MediaSDKEnvirVar
{
    u32 m_dwProductVer;     //MediaSDK���л����Ĳ�Ʒ�İ汾��Ϣ��Ĭ��ΪV1R2����(T2_V1R2),��ѡHD
    u32 m_dwProductInfo;    //MediaSDK���л���������汾��Ϣ
    u32 m_dwOSVer;          //����ϵͳ�汾��
    u32 m_dwRservered;      //�����ֶ�
	
}TMediaSDKEnvirVar;

enum enZoomMode
{
	EN_ZOOM_FILLBLACK = 0,//�Ӻڱ�
	EN_ZOOM_CUT,//�ñ�
	EN_ZOOM_SCALE//���ȱ�����
};

//mediasdk ȫ�ֳ�ʼ��
MEDIA_API u16 MediaSDKInitial();
//mediasdk ȫ������������encoder decoder �ͷź����
MEDIA_API u16 MediaSDKUninitial();
//mediasdk ���������ļ�·��
MEDIA_API u16 SetMediaSdkConfigPath(wchar_t* pszConfigPath);
class	CVidEncWrapper;
class	CAudEncWrapper;
class	CVidDecWrapper;
class	CAudDecWrapper;
class MEDIA_API CKdvEncoder

{
public:
    CKdvEncoder();
    virtual ~CKdvEncoder();
public:
	
    //��ʼ��������ģ�飬��������ã�Ĭ�Ϻ������ؽӿڶ���Ч
	u16		InitialVideoEncoder(const TInitVidEncoder& tEncoderInitParam);
	u16		InitialAudioEncoder(const TInitAudEncoder& tEncoderInitParam);
	u16		GetEncoderStatus(TKdvEncStatus &tKdvEncStatus);/*��ȡ������״̬*/ 		
	u16		GetEncoderStatis(TKdvEncStatis &tKdvEncStatis );/*��ȡ��������ͳ����Ϣ*/

	//////////////////////////////////////////////////////////////////////////audio
	//��ȡ�ɼ��豸�� + ����
	void    RefreshVidCapDevList(vector<TDevNameInfo>& tOutDevList, u32& dwDevNum);

	void	RefreshAudCapDevList(vector<TDevNameInfo>& tOutDevList, u32& dwDevNum);	
    u16		SetVoiceCheck(BOOL32 bCheck,const TVoiceCheck *ptVoiceCheck);/*�������ʼ��*/	
	u16		StartAudioCap();
	u16		StopAudioCap();
	u16		StartAudioEnc();/*��ʼѹ������*/
	u16		StopAudioEnc(); /*ֹͣѹ������*/
	u16		SetAudioEncParam(u8 byAudioMode, 
							 u16 wAudioDuration = 0); /*��������ѹ������*/
	u16		GetAudioEncParam(u8& byAudioEncParam, 
							 u16& wAudioDuration);/*�õ�����ѹ������*/
	u16		SetAudioCallBack(PAUDIOCALLBACK pAudioCallBack, u32 dwContext);
	u16		SetAudioCapCallBack(PAUDIOCAPERRCALLBACK pAudioCallBack, u32 dwContext); //��Ƶ�ɼ��豸��ʧ��ʱ�ص�
	u16		SetAudioCaptureDeviceChangeCB(PAUDIOCAPDEVICECHANGE pAudCapDevChangeCB, u32 dwContext); // ������Ƶ�����Ȳ�μ��Ļص�
	// ���� ��ȡ������Ƶ���� �Ļص�
	u16		SetInputAudioPowerCB(PGETAUDIOPOWER pGetInputAudioPowerCB, u32 dwContext);
	u16		GetAudioMute( BOOL32& bMute );     // �Ƿ����� [zhuyr][4/20/2005]
	u16		SetAudioMute( BOOL32 bMute );     //�����Ƿ���
	//�����Զ�����
	//bEnable��TRUE��ʾ�����Զ����棬FALSE�رա�����ֵ0��ʾ���óɹ�������ʧ��
	u16		SetAudioCapAutoGain(BOOL32 bEnable);
	//bEnable��TRUE��ʾ�����Զ����棬FALSE�رա�����ֵ0��ʾ��ȡ�ɹ�������ʧ��
	u16		GetAudioCapAutoGain(BOOL32 &bEnable);
	u16		SetAudioCapTest(BOOL32 bActive); //��Ƶ�ɼ���� ---taoz
	u16		SetAudioSoftVolume(u8 byVolume ); /*���òɼ����� ��ϵͳ*/	
	u16		GetAudioSoftVolume(u8 &byVolume );/*��ȡ�ɼ�����*/
	u16		SetAudioVolume(u8 byVolume ); /*���òɼ����� ϵͳ*/	
	u16		GetAudioVolume(u8 &byVolume );/*��ȡ�ɼ�����*/
	//////////////////////////////////////////////////////////////////////////video
    u16		SetPreviewHwnd( HWND hPrevWnd );
	u16		SetDeskDrawHwnd( HWND hDeskDrawWnd );
	//ѡ����ƵԴ byDeviceID Ϊ����ͷ�������ID���ֺ�
    u16		SelectVideoSource(const TVideoCapParam  *ptVideoCapParam, const wchar_t *pszDevName = NULL, const wchar_t *pszDevGUID = NULL);//ѡ����ƵԴ
	u16     GetCurVidCapDev(TDevNameInfo &tDevNameInfo);/*��ȡ��ǰ��Ƶ�ɼ��豸��Ϣ*/
	// byCamParamType Ϊ
	//0-----CAMERAPARAM_Hue;1-----CAMERAPARAM_WhiteBalance;2-----CAMERAPARAM_Brightness;3-----CAMERAPARAM_Contrast;4-----CAMERAPARAM_Saturation��5-----CAMERAPARAM_Sharpness
	//bAuto ΪTRUEʱʹ�������Զ�����
	u16		ChangeCameraParam(u8 byCamParamType, u32 dwVal, BOOL32 bAuto = FALSE);
	u16		GetCameraParam(u8 byCamParamType, u32& dwVal, BOOL32& bAuto);
	u16		GetDefaultCameraParam(u8 byCamParamType, u32& dwMin, u32& dwMax, u32& dwDefaultVal, u32& dwStep);
	u16		SelectAudioSource(const wchar_t *pszDevName = NULL, const wchar_t *pszGUIDName = NULL);//ѡ����ƵԴ
	u16     GetCurAudCapDev(TDevNameInfo &tDevNameInfo);/*��ȡ��ǰ��Ƶ�ɼ��豸��Ϣ*/
    u16		SetVideoIcon( BOOL32 bEnable );//bEnable,TRUEΪ���ã�FALSE���衣
    u16		SaveAsPic(const wchar_t* pszFileName, u8 byEncodeMode);
	// ������Ƶ��μ��Ļص�
	u16		SetVideoDeviceCheckCB(PVIDEODEVICECHECK pVideoDeviceCheckCB, u32 dwContext);
	// ���� ̨���������� �Ŀ���
	u16		SetAddLogoIntoEncStream(TFullLogoParam *ptLogoSetting);
	// ���� �������ı���Ԥ�� �Ŀ���
	u16		ShowPreview(BOOL32 bPreview);
    u16		StartVideoCap();/*��ʼ�ɼ�ͼ��*/
    u16		StopVideoCap(); /*ֹͣ�ɼ�ͼ��*/
    u16		SetVideoEncParam(const TVideoEncParam *ptVideoEncParam );/*������Ƶ�������*/
    u16		GetVideoEncParam(TVideoEncParam &tVideoEncParam );       /*�õ���Ƶ�������*/
	//���òɼ����������Ų���
	u16     SetVidCapToEncZoomPolicy(enZoomMode emZoomMode);
    u16		StartVideoEnc();/*��ʼѹ��ͼ��*/
    u16		StopVideoEnc(); /*ֹͣѹ��ͼ��*/
	u16		SetFastUpdate(BOOL32 bIsNeedProtect = TRUE);     /*����FastUpdate��MediaCtrl��75֡�ڱ�һ��I֡����*/
	u16		SendStaticPicture(BOOL32 bSend, wchar_t* pszFileName);
	void	GrabPic(HWND hWnd);
	//////////////////////////////////////////////////////////////////////////medianet
	/*����ͼ��������ش�����*/
	u16		SetNetFeedbackVideoParam(u16 wBufTimeSpan, BOOL32 bRepeatSnd = FALSE);
	u16		SetNetFeedbackAudioParam(u16 wBufTimeSpan, BOOL32 bRepeatSnd = FALSE);
	//�ù�����Ҫ�ѷ����ش���, ���û�򿪣����Զ��򿪡�
	u16		SetNetAudioResend(BOOL32 bReSend);
	u16     SetAudNetSndBand(u32 dwNetBand);//������Ƶ���ʹ���
	u16		SetNetSndVideoParam(const TMnetNetParam *ptNetSndParam);/*����ͼ������紫�Ͳ���*/	
	u16		SetNetSndAudioParam(const TMnetNetParam *ptNetSndParam);/*�������������紫�Ͳ���*/
	
	//������Ƶ����
	//pszEndPointId - �ն˵�id, ��ǰ��֧��e164�� dwparam IdLen - �ն�id�ĳ��� dwStreamId - ��id
	u16     SetAudioSendId(const s8* pszEndPointId, u32 dwIdLen, u32 dwStreamId);//���÷��Ͷ˵�id
	u16     GetAudioSendId(s8* pszEndPointId, u32* pdwIdLen, u32* pdwStreamId);//��ȡ���Ͷ˵�id
	//1.ʹ�ܴ򶴹��ܲ��������ڴ򶴵����緢�Ͳ��� 2.ֹͣ�򶴹��ܲ�ɾ����Ӧ�������
	u16     AudioSendEnableKeepAlive(BOOL32 bEnable, const TMnetNetParam *ptKeepAliveParam);
	//����RTCP״̬
	u16     SetAudioRtcpStatus(RTCPSTATUS status);
	//�Ƿ������ƵRTP��չͷ
	u16     AudioEnableRtpExStrip(BOOL32 bEnable);

	//������Ƶ����
	//pszEndPointId - �ն˵�id, ��ǰ��֧��e164�� dwparam IdLen - �ն�id�ĳ��� dwStreamId - ��id
	u16     SetVideoSendId(const s8* pszEndPointId, u32 dwIdLen, u32 dwStreamId);//���÷��Ͷ˵�id
	u16     GetVideoSendId(s8* pszEndPointId, u32* pdwIdLen, u32* pdwStreamId);//��ȡ���Ͷ˵�id
	//1.ʹ�ܴ򶴹��ܲ��������ڴ򶴵����緢�Ͳ��� 2.ֹͣ�򶴹��ܲ�ɾ����Ӧ�������
	u16     VideoSendEnableKeepAlive(BOOL32 bEnable, const TMnetNetParam *ptKeepAliveParam);
	//����RTCP״̬
	u16     SetVideoRtcpStatus(RTCPSTATUS status);
	//�Ƿ������ƵRTP��չͷ
	u16     VideoEnableRtpExStrip(BOOL32 bEnable);
	//ʹ��/�رն�̬������ dwMaxRate:����������(��λkbps) dwMinRate:��С�������� dwStartRate����ʼ��������
	u16		ResetBwe(BOOL32 bEnable, u32 dwMaxRate, u32 dwMinRate, u32 dwStartRate);
	//��ȡ��̬�������� pNumber:�����߸��� pReceivers:�������� pRevision:������汾
	u16		GetBweStatus(u32* pNumber, TBweReceiver* pReceivers, u32* pRevision);
    u16		StartSendVideo(int  dwSSRC = 0);/*��ʼ����ͼ��*/	
    u16		StopSendVideo(); /*ֹͣ����ͼ��*/
    u16		StartSendAudio(int  dwSSRC = 0);/*��ʼ��������*/	
    u16		StopSendAudio(); /*ֹͣ��������*/	
	//��Ƶ�Ƿ�ʹ��ǰ�����
	u16		SetVidFecEnable(BOOL32 bEnableFec);
	//����fec���а�����
	u16		SetVidFecPackLen(u16 wPackLen);
	//�Ƿ�֡��fec
	u16		SetVidFecIntraFrame(BOOL32 bIntraFrame);
	//����fec�㷨 FEC_MODE_RAID5
	u16		SetVidFecMode(u8 byAlgorithm);
	//����fec��x�����ݰ� + y�������
	u16		SetVidFecXY(s32 nDataPackNum, s32 nCrcPackNum);

	//��Ƶ�Ƿ�ʹ��ǰ�����
	u16		SetAudFecEnable(BOOL32 bEnableFec);
	//����fec���а�����
	u16		SetAudFecPackLen(u16 wPackLen);
	//�Ƿ�֡��fec
	u16		SetAudFecIntraFrame(BOOL32 bIntraFrame);
	//����fec�㷨 FEC_MODE_RAID5
	u16		SetAudFecMode(u8 byAlgorithm);
	//����fec��x�����ݰ� + y�������
	u16		SetAudFecXY(s32 nDataPackNum, s32 nCrcPackNum);
	//��Ƶ��̬�غɵ�PTֵ���趨
	u16		SetAudioActivePT(u8 byLocalActivePT, u8 byRemoteActivePT = MEDIA_TYPE_NULL);
	//��Ƶ��̬�غɵ�PTֵ���趨
	u16		SetVideoActivePT(u8 byLocalActivePT, u8 byRemoteActivePT = MEDIA_TYPE_NULL );
	//������Ƶ�������key�ִ������ܵ��غ�PTֵ �Լ� ����ģʽ Aes or Des
	u16		SetAudEncryptKey( s8 *pszKeyBuf, u16 wKeySize, u8 byEncryptMode );
	//������Ƶ�������key�ִ������ܵ��غ�PTֵ �Լ� ����ģʽ Aes or Des
	u16		SetVidEncryptKey( s8 *pszKeyBuf, u16 wKeySize, u8 byEncryptMode ); 
	u16		SetReverseG7221c(BOOL32 bReverse);

	/*********************����Ͷ��**************************/
	//������Ƶ�ɼ�֡��
	u16		SetDeskSharedVidFrame(u32 dwFrame);
	//���������������ݻص�
	u16		SetDeskSharedVidCallback(PDESKSHARECALLBACK pVidCallback, u32 dwContext);
	//ѡ����Ļ, bStartCap: true,��ʼ�ɼ���
	u16     SelectCaptureScreen(u32 dwScreenIndex, BOOL32 bStartCap = TRUE);
	//��ȡ�ɼ���汾��
	u16		GetDeskShareLibVersion(s8 *pszVersion);
	//��ʼ��Ƶ�ɼ�
	u16		StartDeskSharedAud();
	//ֹͣ��Ƶ�ɼ�
	u16		StopDeskSharedAud();
	//������Ƶ�ɼ��źŷŴ������磺1.0f���ǲ��Ŵ�2.0f���ǷŴ�1����
	u16		SetAudZoominVol(float fZoominVol);
	//������Ƶ��������
	u16     SetDeskSharedAudCallback(PDESKSHARECALLBACK pAudCallback, u32 dwContext);
	//������Ƶ�ɼ�������ص�
	u16     SetAudCapErrorCallback(PDAUDERRORCODECALLBACK pAucCapError, s32 dwContext);
	//���õ��ɼ��ֱ��ʷ����仯ʱ�ص�
	u16     SetVideoCapStdCB(PVIDEOCAPSTDCALLBACK pVidCapStdCallBack, u32 dwContext);
	//���ø���cpu��̬�����ɼ�֡�ʣ�Ĭ�Ͽ���
	u16		EnableCpuAdjust(BOOL32 bEnable);
	
	u16     GetCpuAdjustStatus(BOOL32 &bStatus);
protected:
	void	DestroyVideoEncoder();
	void	DestroyAudioEncoder();
    CVidEncWrapper*	m_pcKdvVideoEncoder;
	CAudEncWrapper*	m_pcKdvAudioEncoder;
    TEncoderRef*	m_ptRef;
    TEncoderStatus*	m_ptStatus;	
};





class CKdvVideoDec;
class CKdvAudioDec;
struct TDecoderRef;
struct TDecoderStatus;


typedef struct tagNetRSParam
{
    u16  m_wFirstTimeSpan;	  //��һ���ش�����
	u16  m_wSecondTimeSpan;  //�ڶ����ش�����
	u16  m_wThirdTimeSpan;   //�������ش�����
	u16  m_wRejectTimeSpan;  //���ڶ�����ʱ����
} TNetRSParam;

class MEDIA_API CKdvDecoder

{
public:
    CKdvDecoder();
    virtual ~CKdvDecoder();
	
public:
	u16    InitialVideoDecoder(const TInitVidDecoder& tVidInitParam);
	u16	   InitialAudioDecoder(const TInitAudDecoder& tAudInitParam);
    u16    GetVidDecoderStatus(TKdvDecStatus &tKdvDecStatus );/*��ȡ��Ƶ������״̬*/
	u16    GetAudDecoderStatus(TKdvDecStatus &tKdvDecStatus );/*��ȡ��Ƶ������״̬*/
    u16    GetVidDecoderStatis(TKdvDecStatis &tKdvDecStatis );/*��ȡ��Ƶ��������ͳ����Ϣ*/	
	u16    GetAudDecoderStatis(TKdvDecStatis &tKdvDecStatis );/*��ȡ��Ƶ��������ͳ����Ϣ*/	

//////////////////////////////////////////////////////////////////////////audio
	void   RefreshPlayDevList(vector<TDevNameInfo>& tOutDevList, u32& dwDevNum);
	u16	   SelectAudioPlayDev(const wchar_t *pszDevName = NULL, const wchar_t *pszDevGUID = NULL);//ѡ����ƵԴ
	u16    GetCurAudPlyDev(TDevNameInfo &tDevNameInfo);/*��ȡ��ǰ��Ƶ�����豸��Ϣ*/
	u16    SetAudioSoftVolume(u8 byVolume );  /*������������㷨����������*/	
	u16    GetAudioSoftVolume(u8 &pbyVolume );/*�õ���������㷨����������*/
	u16    SetAudioVolume(u8 byVolume );  /*�������ϵͳ��������*/	
	u16    GetAudioVolume(u8 &pbyVolume );/*�õ����ϵͳ��������*/
	u16    SetAudioMute(BOOL32 bMute);/*���þ��� -- taoz */
	u16    GetAudioMute(BOOL32& bMute);
	u16    SetAudioDecType(u8 byType,u32 dwAudioMode); /*������������������, ֻ���ڿ�ʼ����ǰ���ò���Ч*/
	u16    StartAudioDec();/*��ʼ��������*/	
	u16    StopAudioDec(); /*ֹͣ��������*/	
	u16    SetAudioCallBack(PAUDIOCALLBACK pAudioCallBack, u32 dwContext);//����ǰ��Ƶ���ݻص�
	u16    SetAudioDecPCMCallBack(PAUDIOPCMCALLBACK pAudioCallBack, u32 dwContext);//�������ƵPCM���ݻص�
	// ���� ��ȡ�����Ƶ���� �Ļص�
	u16    SetOutputAudioPowerCB(PGETAUDIOPOWER pGetOutputAudioPowerCB, u32 dwContext);
	//����aac������� dwSamplePerSecondΪ������ ��48000�� 32000. dwChannelsΪ��˫���� �� ��1, 2
	u16    SetAudioDecParam(u32 dwSamplePerSecond, u32 dwChannels);//��Ƶ�����������
	//��Ƶ���Ų���
	u16    SetAuditoPlyTest(BOOL32 bActive);
	//////////////////////////////////////////////////////////////////////////video
    u16    StartVideoDec();/*��ʼͼ�����*/
    u16    StopVideoDec(); /*ֹͣͼ�����*/
	u16    ClearWindow();  /*����*/
	u16    FreezeVideo();  /*��Ƶ����*/
	u16    UnFreezeVideo();/*ȡ����Ƶ����*/
	u16    SetVideoDecI420CallBack(PVIDEOI420CALLBACK pVideoI420CallBack, u32 dwContext);//�������ƵI420���ݻص�
	//���ý�����ͼ����õĻص�����  [zhuyr][4/25/2005]
	u16    SetDrawCallBack(PDRAWCALLBACK pFun, u32 dwParam);
	u16    SetPlayHwnd( HWND hPlayWnd, BOOL32 bSaveLastFrame = FALSE);
	/*��pDrawWnd��Чʱ���ص��˽ӿڣ�����Ϊ��.*/
    u16	   SaveAsPic(const wchar_t* pszFileName, u8 byEncodeMode);
	//�����Ƿ�ֻ��ؼ�֡ TRUEΪ���ã�FALSEΪȡ��
	u16    SetOnlyKeyFrame(BOOL32 bKeyFrame);
	/////////////////////////////////////////////////////////////////////////medianet
    u16    StartRcvVideo();/*��ʼ�������ͼ��*/
    u16    StopRcvVideo(); /*ֹͣ�������ͼ��*/
    u16    StartRcvAudio();/*��ʼ�����������*/	
    u16    StopRcvAudio(); /*ֹͣ�����������*/	
	u16    SetVideoNetRcvParam(const TMnetNetParam *ptLocalNetParam );/*����ͼ���������ղ���*/	
	u16    SetAudioNetRcvParam(const TMnetNetParam *ptLocalNetParam );/*����������������ղ���*/

	//��Ƶ�Ƿ�ʹ��ǰ�����
	u16	   SetVidFecEnable(BOOL32 bEnableFec);

	//������Ƶ����
	//pszEndPointId - �ն˵�id, ��ǰ��֧��e164�� dwparam IdLen - �ն�id�ĳ��� dwStreamId - ��id
	u16    SetAudioRcvId(const s8* pszEndPointId, u32 dwIdLen, u32 dwStreamId);//���ý��ն˵�id
	u16    GetAudioRcvId(s8* pszEndPointId, u32* pdwIdLen, u32* pdwStreamId);  //��ȡ���ն˵�id
	//1.ʹ�ܴ򶴹��ܲ��������ڴ򶴵����緢�Ͳ��� 2.ֹͣ�򶴹��ܲ�ɾ����Ӧ�������
	u16    AudioRcvEnableKeepAlive(BOOL32 bEnable, const TMnetNetParam *ptKeepAliveParam);
	//����RTCP״̬
	u16    SetAudioRtcpStatus(RTCPSTATUS status);
	//������Ƶ����
	//pszEndPointId - �ն˵�id, ��ǰ��֧��e164�� dwparam IdLen - �ն�id�ĳ��� dwStreamId - ��id
	u16    SetVideoRcvId(const s8* pszEndPointId, u32 dwIdLen, u32 dwStreamId);//���ý��ն˵�id
	u16    GetVideoRcvId(s8* pszEndPointId, u32* pdwIdLen, u32* pdwStreamId);//��ȡ���ն˵�id
	//1.ʹ�ܴ򶴹��ܲ��������ڴ򶴵����緢�Ͳ��� 2.ֹͣ�򶴹��ܲ�ɾ����Ӧ�������
	u16    VideoRcvEnableKeepAlive(BOOL32 bEnable, const TMnetNetParam *ptKeepAliveParam);
	//����RTCP״̬
	u16    SetVideoRtcpStatus(RTCPSTATUS status);
	u16    ResetBwe(BOOL32 bEnable);//ʹ��/�رն�̬������
	u16    SetMaxDelay(u8 policy, u32 softlimit, u32 hardlimit);//�����������ӳټ����Ų���
	/*����ͼ��������ش�����*/
	u16    SetNetFeedbackVideoParam(BOOL32 bRepeatSnd = FALSE);
	u16    SetNetFeedbackAudioParam(BOOL32 bRepeatSnd = FALSE);
	
	/*������������·������һ·����Map����win32������ƣ�һ·��������, ����NULL,��رպ�һ·��������Ӧ�׽����ͷ�*/
	u16    SetVidDecDblSend(const TMnetNetParam *ptNetSndVideoParam, u16 wBitRate = 4<<10);
	u16    SetAudDecDblSend(const TMnetNetParam *ptNetSndAudioParam); 
	//���� H.263+/H.264 �ȶ�̬��Ƶ�غɵ� Playloadֵ
	u16    SetVideoActivePT( u8 byRmtActivePT, u8 byRealPT );
	//���� ��Ƶ����key�ִ� �Լ� ����ģʽ Aes or Des
    u16    SetVidDecryptKey(s8 *pszKeyBuf, u16 wKeySize, u8 byDecryptMode); 
	//���� ��̬��Ƶ�غɵ� Playloadֵ
	u16    SetAudioActivePT( u8 byRmtActivePT, u8 byRealPT );

	u16	   SetVideoActivePT( TMapSet tMapSet );
	u16	   SetAudioActivePT( TMapSet tMapSet );

	//���� ��Ƶ����key�ִ� �Լ� ����ģʽ Aes or Des
    u16    SetAudDecryptKey(s8 *pszKeyBuf, u16 wKeySize, u8 byDecryptMode); 
	u16    SetReverseG7221c(BOOL32 bReverse );//����g7221c��ת
	void   GrabPic(HWND hWnd);

	//��Ƶ�Ƿ�ʹ��ǰ�����
	u16	   SetAudFecEnable(BOOL32 bEnableFec);

	//���ý�����ʾ���Ų���
	u16    SetVidDecZoomPolicy(enZoomMode emZoomMode);
protected:
	void   DestroyVideoDecoder();
	void   DestroyAudioDecoder();
	CVidDecWrapper*		m_pcKdvVideoDecoder;
	CAudDecWrapper*		m_pcKdvAudioDecoder;
	TDecoderRef*		m_ptDecRef;
	TDecoderStatus*		m_ptDecStatus;
};



class CAVCapabilityList;

class MEDIA_API CAVCapCheck

{
public:
    CAVCapCheck();
    ~CAVCapCheck();
public:
	BOOL32 CheckAudInCap();
	BOOL32 CheckVidInCap();
	BOOL32 CheckAudOutCap();
	BOOL32 CheckVidOutCap();
	BOOL32 CheckAudEncCap(u8 byMediaType);
	BOOL32 CheckVidEncCap(u8 byMediaType);
	BOOL32 CheckAudDecCap(u8 byMediaType);
	BOOL32 CheckVidDecCap(u8 byMediaType);	

private:
	CAVCapabilityList *m_ptCAVCapList;
};

typedef struct tagRecoderParam
{
	wchar_t m_aFilePath[MAX_FILE_PATH_LEN];
	u32	   m_dwFilePathLen;
	BOOL32 m_bIsLocal;
	BOOL32 m_bHasAudio;
	BOOL32 m_bHasAuxVideo; //����Զ��¼������
	BOOL32 m_bRecreate;    //Ĭ����ΪTRUE
	BOOL32 m_bStartAfterCreated;
	u32	   m_dwReserved;
}TRecoderParam;



//����ý��TOSֵ nType����0:ȫ�� 1:��Ƶ 2:��Ƶ 3: ����
MEDIA_API	int SetMediaTOS(int nTOS, int nType);
MEDIA_API	int GetMediaTOS(int nType);

//¼���
MEDIA_API void*	CreateRecorder(const TRecoderParam& tRecoderParam);
MEDIA_API u16	CloseRecorder(void* pRecorderInst);
MEDIA_API u16	PauseRecoder(void* pRecorderInst);
MEDIA_API u16	ResumRecoder(void* pRecorderInst);
MEDIA_API u16   GetRecorderFilePath(void* pRecorderInst, wchar_t* pszPath, s32 nPath);
MEDIA_API u16   SetRecoderDiskCheckCB(PGETDISKCHECK pGetDiskCheckCB, u32 dwContext); 
//����¼��ռ�����̸澯��صķ������� *pszPartition ������ dwAlarmLevel1  һ���澯ֵ dwAlarmLevel2  �����澯ֵ
MEDIA_API u16   SetRecoderDiskCheckPartitionAlarm(const wchar_t *pszPartition, u32 dwAlarmLevel1, u32 dwAlarmLevel2);

#endif /*__CODECLIB_H*/
