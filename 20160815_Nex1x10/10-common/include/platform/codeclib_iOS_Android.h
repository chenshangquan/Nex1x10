/* CodecLib.h - Codec API Header */ 

/* Copyright(C) 2001-2002 KDC, All rights reserved. 
˵��:CODEC�ϲ�API��װ����
����:������ κ�α�
�޸��ˣ����
*/

#ifndef __CODECLIB_H_
#define __CODECLIB_H_

#include "kdvdef.h"
#ifndef _KDVMEDIANET_0603_H_
#include "kdvmedianet.h"
#endif

/*=======================================����������ṹ�Ķ���=================================*/

//ģ��汾��Ϣ�ͱ���ʱ�� �� �����Ŀ�İ汾�ͱ���ʱ��
API void kdvencoderver();
API void kdvdecoderver();

//ģ�������Ϣ �� �����Ŀ�İ�����Ϣ
API void kdvencoderhelp();
API void kdvdecoderhelp();

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
#define AUDIO_MODE_G728		 (u8)9 
//G.722
#define AUDIO_MODE_G722		 (u8)10 
//G.729
#define AUDIO_MODE_G729		 (u8)11 
//G.7221 24k
#define AUDIO_MODE_G7221_24		 (u8)12 
//adpcm
#define AUDIO_MODE_ADPCM		 (u8)13 

#define AUDIO_MODE_AACLC_32      (u8)14

#define AUDIO_MODE_AACLD_32      (u8)15

#define AUDIO_MODE_AACLC_32_SINGLE (u8)16

//G.7221 32K
#define AUDIO_MODE_G7221_32		(u8)17
//G.7221 48k
#define AUDIO_MODE_G7221_48		(u8)18

//iBLC
#define AUDIO_MODE_IBLC         (u8)19
//iSac
#define AUDIO_MODE_ISAC_16         (u8)20
#define AUDIO_MODE_ISAC_32         (u8)21
//OPUS
#define AUDIO_MODE_OPUS         (u8)22

#define  CTRL_AUDIO_ONLY          (u8)0x01 //��Ƶ�ɼ�
#define  CTRL_VIDEO_ONLY          (u8)0x02 //��Ƶ�ɼ�
#define  CTRL_AV_BOTH			  (u8)0x03 //����Ƶ����Ƶ��

#define  AUDIO_MODE_ONLYDEC      (u8)0x01
#define  AUDIO_MODE_ONLYRCV      (u8)0x02
#define  AUDIO_MODE_PLAY         (u8)0x00                

#define  MAX_DECODER_NUM		 (u8)2   //����������Ŀ

#define  SOFT_DEC_ONLY           (u8)0x01
#define  HARD_DEC_ONLY           (u8)0x02
#define  SOFTHARD_DEC_BOTH       (u8)0x03 

/*========================================��������붨��======================================*/

/*��Ƶ�����������*/
enum VID_DROP_LEVEL 
{ 
    VID_DROP_PREFERRED_QUALITY = 0,    //�������ȣ�Ϊ��I֡����
    VID_DROP_PREFERRED_FAST_SPEED = 1,    //�ٶ����ȿ쵵���Իָ������ж�����ֻ�ⲻ����֡��Ϊ1����
    VID_DROP_PREFERRED_MID_SPEED = 2,    //�ٶ������е����Իָ������ж�����ֻ�ⲻ����֡��Ϊ2����
    VID_DROP_PREFERRED_SLOW_SPEED = 3    //�ٶ������������Իָ������ж�����ֻ�ⲻ����֡��Ϊ4����
};

/*������������*/
#define VID_ENC_PROFILE_BASELINE  0   //�����ȼ���ENC_QUALITY_LEVEL_2
#define VID_ENC_PROFILE_MAINLINE  1   //��Ҫ�ȼ���ENC_QUALITY_LEVEL_3
#define VID_ENC_PROFILE_HIGHLINE  2   //�߽׵ȼ���ENC_QUALITY_LEVEL_4

/*==================================������=======================*/
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
#define ERROR_NO_AUDIO_DEV          (u16)(CODEC_ERROR_BASE + 36)//û��ָ����Ƶ�豸

#define ERROR_NO_VIDIO_RCV (u16)(CODEC_ERROR_BASE + 60) //û����Ƶ���ն���
#define ERROR_NO_VIDIO_TRANS (u16)(CODEC_ERROR_BASE + 61) //û����Ƶת������
#define ERROR_NO_VIDIO_DEC (u16)(CODEC_ERROR_BASE + 62) //û����Ƶ�������
#define ERROR_NO_VIDIO_OUT (u16)(CODEC_ERROR_BASE + 63) //û����Ƶ�������
#define ERROR_NO_VIDIO_DCPLY (u16)(CODEC_ERROR_BASE + 64) //û����Ƶ�Կ��������

#define ERROR_NO_AUDIO_RCV (u16)(CODEC_ERROR_BASE + 70) //û����Ƶ���ն���
#define ERROR_NO_AUDIO_TRANS (u16)(CODEC_ERROR_BASE + 71)//û����Ƶת������
#define ERROR_NO_AUDIO_DEC (u16)(CODEC_ERROR_BASE + 72) //û����Ƶ�������
#define ERROR_NO_AUDIO_OUT (u16)(CODEC_ERROR_BASE + 73) //û����Ƶ�������
#define ERROR_NO_AUDIO_DSPLY (u16)(CODEC_ERROR_BASE + 74) //û����Ƶ����豸���ƶ���

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

#define ERROR_SOCKET_RTP_PORT_OCCUPY    (u16)(CODEC_ERROR_BASE + 148)//�����������ʱ�˿ڱ�ռ��
#define ERROR_SOCKET_RTCP_PORT_OCCUPY   (u16)(CODEC_ERROR_BASE + 149)//�����������ʱ�˿ڱ�ռ��
#define ERROR_ENC_ENABLECRYPT           (u16)(CODEC_ERROR_BASE + 150)
#define ERROR_ENC_CRYPTCFGINIT          (u16)(CODEC_ERROR_BASE + 151)
#define ERROR_ENC_CRYPTCFGCIPHER        (u16)(CODEC_ERROR_BASE + 152)
#define ERROR_ENC_CRYPTCFGAUTH          (u16)(CODEC_ERROR_BASE + 153)
#define ERROR_ENC_CRYPTCFGMASTKEY       (u16)(CODEC_ERROR_BASE + 154)
#define ERROR_ENC_CRYPTCFGCIPHKEY       (u16)(CODEC_ERROR_BASE + 155)
#define ERROR_ENC_CRYPTCFGAUTHKEY       (u16)(CODEC_ERROR_BASE + 156)
#define ERROR_ENC_CRYPTCFGPKT           (u16)(CODEC_ERROR_BASE + 157)
#define ERROR_ENC_CRYPTCFGAUTHTAG       (u16)(CODEC_ERROR_BASE + 158)
#define ERROR_ENC_ENABLEFEC             (u16)(CODEC_ERROR_BASE + 159)
#define ERROR_DEC_ENABLECRYPT           (u16)(CODEC_ERROR_BASE + 160)
#define ERROR_DEC_CRYPTCFGINIT          (u16)(CODEC_ERROR_BASE + 161)
#define ERROR_DEC_CRYPTCFGCIPHER        (u16)(CODEC_ERROR_BASE + 162)
#define ERROR_DEC_CRYPTCFGAUTH          (u16)(CODEC_ERROR_BASE + 163)
#define ERROR_DEC_CRYPTCFGMASTKEY       (u16)(CODEC_ERROR_BASE + 164)
#define ERROR_DEC_CRYPTCFGCIPHKEY       (u16)(CODEC_ERROR_BASE + 165)
#define ERROR_DEC_CRYPTCFGAUTHKEY       (u16)(CODEC_ERROR_BASE + 166)
#define ERROR_DEC_CRYPTCFGPKT           (u16)(CODEC_ERROR_BASE + 167)
#define ERROR_DEC_CRYPTCFGAUTHTAG       (u16)(CODEC_ERROR_BASE + 168)
#define ERROR_DEC_REQUESTIDRFRAME		(u16)(CODEC_ERROR_BASE + 169)
#define ERROR_ENC_ENABLEFEC             (u16)(CODEC_ERROR_BASE + 170)
#define ERROR_DEC_ENABLEFEC             (u16)(CODEC_ERROR_BASE + 171)


//�豸ID
enum DeviceID {
  Code_None = 0,
  Codec_iPhone = 1,
  Codec_iPad = 2,
  Codec_Android = 3,
  Codec_Error,
};

//��Ƶ�ɼ�����
enum VidEncodeType
{
	vid_EncCamera = 0,
	vid_EncShare,
	InValid,
};

/*����������*/
typedef struct Encoder
{  
	  DeviceID   m_dwDeviceid;    //��ʱʹ�õ��豸ID
	  VidEncodeType m_dwVidEncType;  //��Ƶ�������ͣ���Ƶ����ʱ���������ʹ��
	  u32   m_dwRservered;      //�����ֶ�	
}TEncoder;

/*��Ƶ�������*/
typedef struct VideoEncParam
{
	u8      m_byEncType;   /*ͼ���������*/
    u8      m_byRcMode;    /*ͼ��ѹ�����ʿ��Ʋ���*/
    u16     m_byMaxKeyFrameInterval;/*I֡�����P֡��Ŀ*/
    u8      m_byMaxQuant;  /*�����������(1-31)*/
    u8      m_byMinQuant;  /*��С��������(1-31)*/
    u8      m_byReserved1; /*����*/
    u8      m_byReserved2; /*����*/
    u8      m_byReserved3; /*����*/
    u16     m_wBitRate;    /*���������(Kbps)*/
    u16     m_wReserved4;  /*����*/		
	u32     m_dwSndNetBand;/*���緢�ʹ���(��λ:Kbps,1K=1024)*/   
    u32     m_dwReserved5; /*����*/
	u16     m_EncVideoWidth;//��������ͼ���
	u16     m_EncVideoHeight;//��������ͼ���
	u8      m_byQcMode; /*ͼ���������ʿ��Ʋ���,�������Ȼ����ٶ�����*/
    u8      m_byQI;
    u8      m_byQP;
    u32     m_dwReversed;
}TVideoEncParam;

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
	u32             m_dwVideoBufLen;  /*��Ƶ���峤��*/
	u32             m_dwAudioBufLen;  /*��Ƶ���峤��*/ 
	TVideoEncParam	m_tVideoEncParam; /*��Ƶ�������*/
	u8              m_byAudioEncParam;/*��Ƶ����ģʽ*/
	u8			    m_byAudEncMediaType; /*��Ƶ����ý������*/	
	TMnetNetParam       m_tVideoSendAddr; /*��Ƶ���͵�ַ*/
	TMnetNetParam       m_tAudioSendAddr; /*��Ƶ���͵�ַ*/
	u32             m_dwSetEncParam; //����Ӳ�������������
	u32             m_dwVideoSend;   //�ѷ��͵���Ƶ����
	u32             m_dwAudioSend;   //�ѷ��͵���Ƶ����
	BOOL32			m_bReduceVideoEncRes;/*�Ƿ񽵵ͱ���ֱ���*/
	u32             m_dwReversed;
}TKdvEncStatus;

typedef struct MediaSDKEnvirVar
{
    u32 m_dwMediaSDKVer;     //��ǰMediaSDK�汾��
    u32 m_dwMediaSDKInfo;    //��ǰMediaSDK����Ϣ
    u32 m_dwOSVer;          //����ϵͳ�汾��
    u32 m_dwRservered;      //�����ֶ�
}TMediaSDKEnvirVar;

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
	u32  m_dwReversed;
}TKdvEncStatis;

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
	s8     aszLogoBmpPath[256];	
	u32    dwLogoPathLen;
	TAddLogoParam tLogoParam;
}TFullLogoParam;
struct TEncoderRef;
struct TEncoderStatus;
class  CKdvEncImp;

class CKdvEncoder/**/
{
public:
    CKdvEncoder();
    virtual ~CKdvEncoder();
public:
 
    //��ʼ�����������
    u16    Create( const TEncoder *ptEncoder, u8 byCapType = CTRL_AV_BOTH );
	
	u16    StartCap( u8 byCapType = CTRL_AV_BOTH );//��ʼ����
    u16    StopCap( u8 byCapType =  CTRL_AV_BOTH ); //ֹͣ����

    u16    SetAudioCapParam( u8 byMode );
    u16    SetVideoEncAddBlackBorder( BOOL32 bEnable );//bEnable, TRUEΪ�Ӻڱߴ���ʽ��FALSE����Ӧ��Ļ

    u16    GetEncoderStatus( TKdvEncStatus &tKdvEncStatus );/*��ȡ������״̬*/ 		
    u16    GetEncoderStatis( TKdvEncStatis &tKdvEncStatis );/*��ȡ��������ͳ����Ϣ*/

    u16    StartVideoCap();/*��ʼ�ɼ�ͼ��*/
    u16    StopVideoCap(); /*ֹͣ�ɼ�ͼ��*/

    u16    SetVideoEncParam(const TVideoEncParam *ptVideoEncParam );/*������Ƶ�������*/
    u16    GetVideoEncParam(TVideoEncParam &tVideoEncParam );       /*�õ���Ƶ�������*/
    u16    StartVideoEnc();/*��ʼѹ��ͼ��*/
    u16    StopVideoEnc(); /*ֹͣѹ��ͼ��*/
    
    u16    SetFastUpata(BOOL32 bIsNeedProtect = TRUE);     /*����IDR��*/
    u16    SendStaticPicture(BOOL32 bSend, s8* pszFileName);  //���;�̬ͼƬ     	

    u16    StartAudioCap();/*��ʼ�����ɼ�*/
    u16    StopAudioCap(); /*ֹͣ�����ɼ�*/

    u16    SetAudioEncParam(u8 byAudioEncParam, 
                            u8 byMediaType,
                            u16 wAudioDuration = 30); /*��������ѹ������*/
    u16    GetAudioEncParam(u8 &byAudioEncParam, 
                            u8 *pbyMediaType = NULL,
                            u16 *pwAudioDuration = NULL);/*�õ�����ѹ������*/

	u16    StartAudioEnc();/*��ʼѹ������*/
    u16    StopAudioEnc(); /*ֹͣѹ������*/

    u16    SetBackStage(BOOL32 bBackStage);
    u16	   SetAudioMute(BOOL32 bMute); /*�����Ƿ�����*/	
    u16    GetAudioMute( BOOL32& bMute );     // �Ƿ�����

	//����ͼ��������ش�����
	u16    SetNetFeedbackVideoParam(BOOL32 bRepeatSnd = FALSE);
	u16    SetNetFeedbackAudioParam(BOOL32 bRepeatSnd = FALSE);
	
	//������Ƶ����
	u16    SetAudioSendId(const char* EndPointId, u32 IdLen, u32 StreamId);
	u16    GetAudioSendId(char* EndPointId, u32* IdLen, u32* StreamId);
	u16    AudioSendEnableKeepAlive(BOOL32 enable, const TMnetNetParam *ptKeepAliveParam);
	
	//��Ƶ���ʹ������ƣ�dwNetBand�� dwMaxBitRate��һֵΪ�㣬���ʹ������ƣ� ucFrameRate��δʹ�ã�Ĭ��ֵΪ��
	u16    SetAudioSndBand(u32 dwNetBand, u32 dwMaxBitRate, u8 ucFrameRate = 0);   
	
	//������Ƶ����
	u16    SetVideoSendId(const char* EndPointId, u32 IdLen, u32 StreamId);
	u16    GetVideoSendId(char* EndPointId, u32* IdLen, u32* StreamId);
	u16    VideoSendEnableKeepAlive(BOOL32 enable, const TMnetNetParam *ptKeepAliveParam);

	//�ù��ܶ���Ƶ���ö౶����
	u16    SetNetAudioResend(s32 nSendSpan);

    u16    SetNetSndVideoParam(const TMnetNetParam *ptNetSndParam);/*����ͼ������紫�Ͳ���*/
    u16    SetNetSndAudioParam(const TMnetNetParam *ptNetSndParam);/*�������������紫�Ͳ���*/
    u16    StartSendVideo(int  dwSSRC = 0);/*��ʼ����ͼ��*/	
    u16    StopSendVideo(); /*ֹͣ����ͼ��*/
    u16    StartSendAudio(int  dwSSRC = 0);/*��ʼ��������*/	
    u16    StopSendAudio(); /*ֹͣ��������*/   

    //��Ƶ��̬�غɵ�PTֵ���趨
    u16 SetAudioActivePT(u8 byLocalActivePT, u8 byRemoteActivePT  = MEDIA_TYPE_NULL);
    	
    //��Ƶ��̬�غɵ�PTֵ���趨
    u16 SetVideoActivePT(u8 byLocalActivePT,u8 byRemoteActivePT = MEDIA_TYPE_NULL );
    	
    //������Ƶ�������key�ִ������ܵ��غ�PTֵ �Լ� ����ģʽ Aes or Des
    u16    SetAudEncryptKey( s8 *pszKeyBuf, u16 wKeySize, u8 byEncryptMode );
    	
    //������Ƶ�������key�ִ������ܵ��غ�PTֵ �Լ� ����ģʽ Aes or Des
    u16    SetVidEncryptKey( s8 *pszKeyBuf, u16 wKeySize, u8 byEncryptMode ); 
    
	u16    SetReverseG7221c(BOOL32 bReverse);
	u16    SendAudioPack(u8* lpBuf, s32 nlen);
	
	//ʹ��/�رն�̬������
	u16 ResetBwe(BOOL32 bEnable, u32 dwMaxRate, u32 dwMinRate, u32 dwStartRate);
	//��ȡ��̬��������,����ResetBweʹ��
	u16 GetBweStatus(u32* pNumber, TBweReceiver* pReceivers, u32* pRevision);
	//��ȡ��Ƶ���紫�俪���ٷֱ�
	u16 GetVidTransportOverhead(u8 *byPercent);

	u16	SetAddLogoIntoEncStream(TFullLogoParam *ptLogoSetting);

    void    GetLastError( u32 &dwErrorId );
        	
	
	//��Ƶ�Ƿ�ʹ��ǰ�����
	u16    SetVidFecEnable(BOOL32 bEnableFec);
/*	//����fec���а�����
	u16    SetVidFecPackLen(u16 wPackLen);
	//�Ƿ�֡��fec
	u16    SetVidFecIntraFrame(BOOL32 bIntraFrame);
	//����fec�㷨 FEC_MODE_RAID5
	u16    SetVidFecMode(u8 byAlgorithm);
	//����fec��x�����ݰ� + y�������
	u16    SetVidFecXY(s32 nDataPackNum, s32 nCrcPackNum);
*/
	//��Ƶ�Ƿ�ʹ��ǰ�����
	u16    SetAudFecEnable(BOOL32 bEnableFec);
	//����fec���а�����
/*	u16    SetAudFecPackLen(u16 wPackLen);
	//�Ƿ�֡��fec
	u16    SetAudFecIntraFrame(BOOL32 bIntraFrame);
	//����fec�㷨 FEC_MODE_RAID5
	u16    SetAudFecMode(u8 byAlgorithm);
	//����fec��x�����ݰ� + y�������
	u16    SetAudFecXY(s32 nDataPackNum, s32 nCrcPackNum);
*/	
	/**************Video*******************/
	//ʹ�ܼ���
	u16     SetVidEnableCrypt( BOOL32 bEnableCrypt, TMnetCryptCfg *ptMnetCryptCfg);
	//��ʼ���������ýṹ��
	u16     SetVidMnetCryptCfgInit(TMnetCryptCfg* ptCfg, BOOL32 bsend);
	//���ü����õļ����㷨
	u16     SetVidMnetCryptCfgSetCipherAlgorithm(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptAlgoType tAlgorithm);
	//������֤�õļ����㷨
	u16     SetVidMnetCryptCfgSetAuthAlgorithm(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptAlgoType tAlgorithm);
	//������Կ���ͺ���Կ,���ӿ�����srtp
	u16     SetVidMnetCryptCfgSetMasterKey(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptKeyType tKeyType, u16 wKeySize, 
		u8* byKey, TMnetCrypKeyLen tKeyLenAuch, TMnetCrypKeyLen tKeyLenCipher);
	//���ü����õ�ĳ��ͨ���ļ�����Կ����,����H235����,Ŀǰ��֧��rtp aes����
	u16     SetVidMnetCryptCfgSetCipherKey(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, u16 wKeySize, u8* byKey);
	//���ü����õ�ĳ��ͨ������֤��Կ����,����H235,�ݲ�֧����֤
	u16     SetVidMnetCryptCfgSetAuthKey(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, u16 wKeySize, u8* byKey);
	//����ͨ����pkt����
	u16     SetVidMnetCryptCfgSetPkt(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptPktType tPktType);
	//���ü����õ�ĳ��ͨ������֤tag����,����srtp
	u16		SetVidMnetCryptCfgSetAuthTag(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptTagLen tTagLen);

	u16	    SetVidMnetKeyFrameRequestCallback(PKeyFrameRequestCallback pCallback, void *pContext);

	/**************Audio******************/
	//ʹ�ܼ���
	u16     SetAudEnableCrypt( BOOL32 bEnableCrypt, TMnetCryptCfg *ptMnetCryptCfg);
	//��ʼ���������ýṹ��
	u16     SetAudMnetCryptCfgInit(TMnetCryptCfg* ptCfg, BOOL32 bsend);
	//���ü����õļ����㷨
	u16     SetAudMnetCryptCfgSetCipherAlgorithm(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptAlgoType tAlgorithm);
	//������֤�õļ����㷨
	u16     SetAudMnetCryptCfgSetAuthAlgorithm(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptAlgoType tAlgorithm);
	//������Կ���ͺ���Կ,���ӿ�����srtp
	u16     SetAudMnetCryptCfgSetMasterKey(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptKeyType tKeyType, u16 wKeySize, 
		u8* byKey, TMnetCrypKeyLen tKeyLenAuch, TMnetCrypKeyLen tKeyLenCipher);
	//���ü����õ�ĳ��ͨ���ļ�����Կ����,����H235����,Ŀǰ��֧��rtp aes����
	u16     SetAudMnetCryptCfgSetCipherKey(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, u16 wKeySize, u8* byKey);
	//���ü����õ�ĳ��ͨ������֤��Կ����,����H235,�ݲ�֧����֤
	u16     SetAudMnetCryptCfgSetAuthKey(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, u16 wKeySize, u8* byKey);
	//����ͨ����pkt����
	u16     SetAudMnetCryptCfgSetPkt(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptPktType tPktType);
	//���ü����õ�ĳ��ͨ������֤tag����,����srtp
	u16		SetAudMnetCryptCfgSetAuthTag(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptTagLen tTagLen);

private:
	s64    m_qwLastFastupdataTime;     //���һ��FastUpdata��ʱ��

protected:
    CKdvEncImp     *m_pcKdvInterEnc;
    TEncoderRef     *m_ptRef;
    TEncoderStatus     *m_ptStatus;	
};

class CKdvVidDecCtrl;
class CKdvAudDecCtrl;
struct TDecoderRef;
struct TDecoderStatus;

/*������ͳ����Ϣ*/
typedef struct KdvDecStatis
{
	u8	  m_byVideoFrameRate;/*��Ƶ����֡��*/
	u16	  m_wVideoBitRate;   /*��Ƶ��������*/
	u16	  m_wAudioBitRate;   /*������������*/
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
	u32	  m_dwVidPackLoseNum;//��Ƶ������
    u16   m_wVidPhyPackLoseRatio;//�ش�ǰ����Ƶ������
    u16   m_wVidPackLoseRatio;//�ش������Ƶ������
    u16   m_wAudPhyPackLoseRatio;//�ش�ǰ����Ƶ������
	u16   m_wAudPackLoseRatio;//�ش������Ƶ������	
}TKdvDecStatis; 

/*������״̬*/
typedef struct KdvDecStatus
{
	BOOL32	m_bVideoDecStart;/*�Ƿ�ʼ��Ƶ����*/
	BOOL32	m_bAudioDecStart;/*�Ƿ�ʼ��Ƶ����*/
	BOOL32	m_bRcvVideoStart;/*�Ƿ�ʼ��Ƶ����*/
	BOOL32	m_bRcvAudioStart;/*�Ƿ�ʼ��Ƶ����*/
	u32	m_dwAudioBufLen; /*��Ƶ���Ż��峤��*/
	u32	m_dwVideoBufLen; /*��Ƶ���Ż��峤��*/
	TMnetNetParam   m_tAudioRcvAddr;/*��Ƶ���ص�ַ*/
	TMnetNetParam   m_tVideoRcvAddr;/*��Ƶ���ص�ַ*/
	BOOL32	m_bAudioOutThread;/*�Ƿ����������̴߳��*/
	u32   m_dwAudioDecType;     //��Ƶ��������
	u32   m_dwVideoDecType;     //��Ƶ��������
}TKdvDecStatus;

/*��Ƶ����������*/
typedef struct VideoDecoder
{    
    DeviceID     m_dwDeviceid;    //��ʱʹ�õ��豸ID
	s32     m_nVideoPlayBufNum;     /*��Ƶ�طŻ������*/
	s32     m_nVideoStartPlayBufNum;/*��Ƶ��ʼ�طŻ������*/
	//Ӳ�����벿��
	u8      m_byMask;  //0x01�������,0x02Ӳ������,0x03����ͬʱ����
    u32     m_dwReversed;
}TVideoDecoder;

/*��Ƶ����������*/
typedef struct AudioDecoder
{
	DeviceID     m_dwDeviceid;    //��ʱʹ�õ��豸ID
	s32     m_nAudioPlayBufNum;/*��Ƶ���Ż�����*/
	s32     m_nAudioStartPlayBufNum;/*��Ƶ��ʼ���Ż�����*/
    u8      m_byAudioMode;
    u32     m_dwRservered;      //�����ֶ�
}TAudioDecoder;

typedef struct tagNetRSParam  //include medianet
{
    u16  m_wFirstTimeSpan;	  //��һ���ش�����
	u16  m_wSecondTimeSpan;  //�ڶ����ش�����
	u16  m_wThirdTimeSpan;   //�������ش�����
	u16  m_wRejectTimeSpan;  //���ڶ�����ʱ����
} TNetRSParam;

class CKdvDecoder
{
public:
    CKdvDecoder();
    virtual ~CKdvDecoder();
	
public:

    u16    CreateDecoder(const TVideoDecoder *ptVideoDecoder, const TAudioDecoder *ptAudioDecoder);/*��ʼ��������*/	
    u16    GetDecoderStatus(TKdvDecStatus &tKdvDecStatus );/*��ȡ������״̬*/
    u16    GetDecoderStatis(TKdvDecStatis &tKdvDecStatis );/*��ȡ��������ͳ����Ϣ*/	

    u16    StartVideoDec();/*��ʼͼ�����*/
    u16    StopVideoDec(); /*ֹͣͼ�����*/
    
    u16    CleanScreen();  //�����Ŵ�����Ϊ����
    
//	u16    StartVideoPlay(); /* ��ʼͼ�񲥷� */  δʵ��
//	u16    StopVideoPlay(); /* ֹͣͼ�񲥷� */   δʵ��
	
//	u16    SetAudioDecType(u8 byType,u32 dwAudioMode); //δʵ��,Ҫ�л���Ƶ�����ʽ����Ҫ���´���������
    u16    StartAudioDec();/*��ʼ��������*/	
    u16    StopAudioDec(); /*ֹͣ��������*/	
    
    u16    SetAudioMute(BOOL32 bMute);/*���þ���*/          
    u16    GetAudioMute(BOOL32& bMute); //�õ�����״̬
    
	u16    SetBackStage(BOOL32 bBackStage);
    
    u16    StartRcvVideo();/*��ʼ�������ͼ��*/
    u16    StopRcvVideo(); /*ֹͣ�������ͼ��*/
    u16    StartRcvAudio();/*��ʼ�����������*/	
    u16    StopRcvAudio(); /*ֹͣ�����������*/	
    u16    SetVideoNetRcvParam(const TMnetNetParam *ptLocalNetParam );/*����ͼ���������ղ���*/
    u16    SetAudioNetRcvParam(const TMnetNetParam *ptLocalNetParam );/*����������������ղ���*/
    
	//������Ƶ����
	u16    SetAudioRcvId(const char* EndPointId, u32 IdLen, u32 StreamId);
	u16    GetAudioRcvId(char* EndPointId, u32* IdLen, u32* StreamId);
	u16    AudioRcvEnableKeepAlive(BOOL32 enable, const TMnetNetParam *ptKeepAliveParam);
	
	//������Ƶ����
	u16    SetVideoRcvId(const char* EndPointId, u32 IdLen, u32 StreamId);
	u16    GetVideoRcvId(char* EndPointId, u32* IdLen, u32* StreamId);
	u16    VideoRcvEnableKeepAlive(BOOL32 enable, const TMnetNetParam *ptKeepAliveParam);
	u16    SetMaxDelay(u8 ucPolicy, u32 dwSoftlimit, u32 dwHardlimit); //�����������ӳټ����Ų��ԣ���λms����Ϊsoftlimit��hardlimit��������
	
	/*����ͼ��������ش�����*/
	u16    SetNetFeedbackVideoParam(BOOL32 bRepeatSnd = FALSE);
	u16    SetNetFeedbackAudioParam(BOOL32 bRepeatSnd = FALSE);          

	/*������������·������һ·����Map����win32������ƣ�һ·��������, ����NULL,��رպ�һ·��������Ӧ�׽����ͷ�*/
    u16    SetVidDecDblSend(const TMnetNetParam *ptNetSndVideoParam, u16 wBitRate = 4<<10);
    u16    SetAudDecDblSend(const TMnetNetParam *ptNetSndAudioParam);   

	//���� H.263+/H.264 �ȶ�̬��Ƶ�غɵ� Playloadֵ
	u16    SetVideoActivePT( u8 byRmtActivePT, u8 byRealPT );
	u16    SetVideoActivePT( const TMapSet *ptMapSet );

	//���� ��Ƶ����key�ִ� �Լ� ����ģʽ Aes or Des
    u16    SetVidDecryptKey(s8 *pszKeyBuf, u16 wKeySize, u8 byDecryptMode); 

    //���� ��̬��Ƶ�غɵ� Playloadֵ
	u16    SetAudioActivePT( u8 byRmtActivePT, u8 byRealPT );
	u16    SetAudioActivePT( const TMapSet *ptMapSet );

	//���� ��Ƶ����key�ִ� �Լ� ����ģʽ Aes or Des
    u16    SetAudDecryptKey(s8 *pszKeyBuf, u16 wKeySize, u8 byDecryptMode); 

	/*������Ƶ�����������*/
	u16    SetVidDropPolicy(VID_DROP_LEVEL byDropPolicy);

    //�õ�Wrapper�İ汾�ͱ�����Ϣ bysize��ò�С��128  [zhuyr][2/23/2005]
    //u16    GetWrapperVer(s8 *pszVerBuffer, u8 bySize);   //δʵ��

	//�����Ƿ�ֻ��ؼ�֡ TRUEΪ���ã�FALSEΪȡ��
	u16    SetOnlyKeyFrame(BOOL32 bKeyFrame);

	u16    SetAudioDecParam(u32 dwSamplePerSecond, u32 dwChannels,u32 dwAudioMode = 255);//��Ƶ�����������
	u16    SetReverseG7221c(BOOL32 bReverse );//����g7221c��ת

	//��Ƶ�Ƿ�ʹ��ǰ�����
	u16    SetVidFecEnable(BOOL32 bEnableFec);
	//��Ƶ�Ƿ�ʹ��ǰ�����
	u16    SetAudFecEnable(BOOL32 bEnableFec);

	/***********Video**************/
	//ʹ�ܼ���
	u16     SetVidEnableCrypt( BOOL32 bEnableCrypt, TMnetCryptCfg *ptMnetCryptCfg);
	//��ʼ���������ýṹ��
	u16     SetVidMnetCryptCfgInit(TMnetCryptCfg* ptCfg, BOOL32 bsend);
	//���ü����õļ����㷨
	u16     SetVidMnetCryptCfgSetCipherAlgorithm(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptAlgoType tAlgorithm);
	//������֤�õļ����㷨
	u16     SetVidMnetCryptCfgSetAuthAlgorithm(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptAlgoType tAlgorithm);
	//������Կ���ͺ���Կ,���ӿ�����srtp
	u16     SetVidMnetCryptCfgSetMasterKey(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptKeyType tKeyType, u16 wKeySize, 
		u8* byKey, TMnetCrypKeyLen tKeyLenAuch, TMnetCrypKeyLen tKeyLenCipher);
	//���ü����õ�ĳ��ͨ���ļ�����Կ����,����H235����,Ŀǰ��֧��rtp aes����
	u16     SetVidMnetCryptCfgSetCipherKey(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, u16 wKeySize, u8* byKey);
	//���ü����õ�ĳ��ͨ������֤��Կ����,����H235,�ݲ�֧����֤
	u16     SetVidMnetCryptCfgSetAuthKey(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, u16 wKeySize, u8* byKey);
	//����ͨ����pkt����
	u16     SetVidMnetCryptCfgSetPkt(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptPktType tPktType);
	//���ü����õ�ĳ��ͨ������֤tag����,����srtp
	u16		SetVidMnetCryptCfgSetAuthTag(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptTagLen tTagLen);

	u16     SetVidMnetRequestIDRFrame();

	u16     SetAudEnableCrypt(BOOL32 bEnableCrypt, TMnetCryptCfg *ptMnetCryptCfg);
	
	u16     SetAudMnetCryptCfgInit(TMnetCryptCfg* ptCfg, BOOL32 bsend);
	//���ü����õļ����㷨
	u16     SetAudMnetCryptCfgSetCipherAlgorithm(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptAlgoType tAlgorithm);
	//������֤�õļ����㷨
	u16     SetAudMnetCryptCfgSetAuthAlgorithm(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptAlgoType tAlgorithm);
	//������Կ���ͺ���Կ,���ӿ�����srtp
	u16     SetAudMnetCryptCfgSetMasterKey(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptKeyType tKeyType, u16 wKeySize, 
		u8* byKey, TMnetCrypKeyLen tKeyLenAuch, TMnetCrypKeyLen tKeyLenCipher);
	//���ü����õ�ĳ��ͨ���ļ�����Կ����,����H235����,Ŀǰ��֧��rtp aes����
	u16     SetAudMnetCryptCfgSetCipherKey(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, u16 wKeySize, u8* byKey);
	//���ü����õ�ĳ��ͨ������֤��Կ����,����H235,�ݲ�֧����֤
	u16     SetAudMnetCryptCfgSetAuthKey(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, u16 wKeySize, u8* byKey);
	//����ͨ����pkt����
	u16     SetAudMnetCryptCfgSetPkt(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptPktType tPktType);
	//���ü����õ�ĳ��ͨ������֤tag����,����srtp
	u16		SetAudMnetCryptCfgSetAuthTag(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptTagLen tTagLen);

    void   GetLastError( u32 &dwErrorId );

public:
    CKdvVidDecCtrl       *m_pcKdvVideoDec;//����
    CKdvAudDecCtrl       *m_pcKdvAudioDec;//����
    TDecoderRef	       *m_ptRef;   //����
    TDecoderStatus     *m_ptStatus;//����
    static TMediaSDKEnvirVar  m_tMediaSDKEnvirVar;//��¼MediaSDK�汾��Ϣ����ǰ��������Ϣ     
    u32 m_dwLastRcvFrameNum;
    u32 m_dwLastRcvPacketNum;
    u32 m_dwSpanRcvPacketNum;
    u32 m_dwLastLostPacketNum;
    u32 m_dwVidPackLoseNum;
    u32 m_dwVidPhyPackLoseNum;
    u32 m_dwLastLostPhyPacketNum;
    u32 m_dwAudPackLoseNum;
    u32 m_dwAudPhyPackLoseNum;
    u32 m_dwLastSec;
protected:
    u8		       m_byFlag;	
};

#endif /*__CODECLIB_H*/
















