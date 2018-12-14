/*****************************************************************************
  ģ����      : CodecHisi3798.a
  �ļ���      : codecwrapper_imix.h
  ����ļ�    : 
  �ļ�ʵ�ֹ���: 
  ����        : ������
  �汾        : V4.0  Copyright(C) 2007-2016 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
******************************************************************************/
#ifndef _CODECWRAPPER_IMIX_H_
#define _CODECWRAPPER_IMIX_H_

#include "kdvtype.h"
#include "osp.h"

typedef void (*PASKIFRAMEPROC )(void* pContext);//����KEY FRAME�ص�

typedef void (*PMediaSystemErrorCallBack )(void* pContext);//�������������ɻָ��쳣����ص���֪ͨҵ������2018.04.11 add by wj 


//������
#define ERROR_CODE_BASE             30000             
#define CODEC_NO_ERROR              0//�޴�
enum
{
	AUDIO_MODE_MP3 = 4,
	AUDIO_MODE_PCMA = 5,
	AUDIO_MODE_PCMU,
	AUDIO_MODE_G723_6,
	AUDIO_MODE_G723_5,
	AUDIO_MODE_G728,
	AUDIO_MODE_G722,
	AUDIO_MODE_G729,
	AUDIO_MODE_G719,
	AUDIO_MODE_G7221,
	AUDIO_MODE_ADPCM,
	AUDIO_MODE_OPUS,
	AUDIO_MODE_AACLC_32,     //32K ˫����
	AUDIO_MODE_AACLC_32_M,   //32K ������
	AUDIO_MODE_AACLC_48,     //48K ˫����
	AUDIO_MODE_AACLC_48_M,   //48K ������
	AUDIO_MODE_AACLD_32,
	AUDIO_MODE_AACLD_32_M,
	AUDIO_MODE_AACLD_48,
	AUDIO_MODE_AACLD_48_M
};
//��Ƶ����������
typedef enum 
{
    SAMPLE_RATE48000,     //������Ϊ48kHz��������0
    SAMPLE_RATE44100,     //������Ϊ44.1kHz��������1
    SAMPLE_RATE32000,     //������Ϊ32kHz��������2
    SAMPLE_RATE16000,     //������Ϊ16kHz��������3
    SAMPLE_RATE8000,       //������Ϊ8kHz��������4
    SAMPLE_RATE0          //������Ϊ0 ��������5  �൱����������
}enSampleRate;

enum enCodecErr
{
	Codec_Success = CODEC_NO_ERROR,

	Codec_Error_Base = ERROR_CODE_BASE,
	Codec_Error_Param,
	Codec_Error_CPUID,
	Codec_Error_Codec_NO_Create,
	Codec_Error_Audio_CapInstance,
	Codec_Error_Audio_PlyInstance,
	Codec_Error_CreateThread,
	Codec_Error_FastUpdateTooFast,
	Codec_Error_WriteToDSP,
	Codec_Error_CreateHPIChannel,
	Codec_Error_GetMem,
	Codec_Error_GetBMP,
	Codec_Error_SetZoomMode,
	Codec_Error_SetZorder,
	Codec_Error_SnapShotGetOutPutStdNull,
	Codec_Error_SnapShotError
};

typedef struct tagVidDecInit
{
	u32     dwIndex;						//0 - main decoder; 1 - aux decoder; 2 - dual view decoder
	u32     dwVidPort;						
	u32     dwPlayStd;						//video����ʽ��only decoder
	u32     dwReserve;						//���������������书�ܴ�����˴���չ����(TAdapterInfo)
	
}TVidDecImix;

typedef struct tagCodecInit
{	
	u32     dwChnID;   // 0,1....
	u32     dwPlyPort; //�ɼ��˿�
}TDecoder;

typedef struct tagVidFrameInfo
{
	BOOL32    m_bKeyFrame;    //Ƶ֡���ͣ�I or P��
	u16       m_wVideoWidth;  //��Ƶ֡��
	u16       m_wVideoHeight; //��Ƶ֡��
}
TVidFrameInfo;

typedef struct tagFrameHeader
{
	u32     m_dwMediaType;    //��������
	u32     m_dwFrameID;      //֡��ʶ�����ڽ��ն�
	u32     m_dwSSRC;         //ͬ��Դ��Ϣ�����ڽ��ն�
	u8*     m_pData;          //����Ƶ����
	u32     m_dwDataSize;     //���ݳ���
	u32		m_dwFPS;		  //֡��
	u32     m_dwTimeStamp;    //ʱ���
    union
    {
		TVidFrameInfo m_tVideoParam;
        u32           m_dwAudioMode;//��Ƶģʽ
        BOOL32    m_bUseAudioLevel; //�Ƿ�ʹ��audio level
        BOOL32 	  m_bVadFlag; //�Ƿ�Ϊ����
	    u8		  m_byAudioLevel; // ��Ƶ������ 0~127(-dBov)
    };
}
TFrameHeader, *PTFrameHeader;

/*������״̬*/
typedef struct tagKdvDecStatus
{
	BOOL32	m_bDecStart;         /*�Ƿ�ʼ����*/	
	u32     m_dwAudioDecType;    /*��������*/
    u32     m_dwHeart;           /*�����߳�����*/
	u32     m_dwPos;             /*�����߳�λ��*/
    u32     m_dwDecType;
}TKdvDecStatus;

/*������ͳ����Ϣ*/
typedef struct tagKdvDecStatis
{
	u16	   m_wFrameRate;           /*����֡��*/
    u16    m_wLoseRatio;           /*��ʧ��,��λ��%*/ 
	u32    m_dwRecvFrame;          /*�յ���֡��*/
	u32    m_dwLoseFrame;          /*��ʧ��֡��*/		
	u32    m_dwPackError;          /*��֡��*/ 
	u32    m_dwIndexLose;          /*��Ŷ�֡*/
	u32    m_dwSizeLose;           /*��С��֡*/
	u32    m_dwFullLose;           /*����֡*/	
	u16	   m_wBitRate;             /*��Ƶ��������*/
	u16    m_wAvrVideoBitRate;     /*1�����ڽ���ƽ������*/
	BOOL32 m_bVidCompellingIFrm;   /*��Ƶǿ������I֡*/								  
	u32    m_dwDecdWidth;	       /*�����Ŀ�*/
	u32    m_dwDecdHeight;         /*�����ĸ�*/
}TKdvDecStatis;

typedef struct tagVidSrcInfo
{
    u16	    m_wWidth;                     /* ��Ƶ������Ϊ��λ,Ϊ0��ʾ���ź� */
    u16	    m_wHeight;                    /* ��Ƶ�ߣ���Ϊ��λ,Ϊ0��ʾ���ź� */
    BOOL32  m_bProgressive;               /* ���л���У�TRUE=���У�FALSE=���� */
    u32     m_dwFrameRate;                /* ֡�ʣ�����ʱ=��Ƶ������ʱ=��Ƶ/2����60i=30P,Ϊ0��ʾ���ź� */
}
TVidSrcInfo;


#define MAX_VID_PLAY_INTFACE 10
typedef struct tagVidPortInfo
{
  TVidSrcInfo m_tVidSrcInfo;	//��Ƶ��ʽ
	u32         m_dwNumPort;
	union
	{
		u32			m_dwVidPort;	//��Ƶ�˿�		
		u32			m_dwVidPortList[MAX_VID_PLAY_INTFACE];	//��Ƶ�˿�			
		u32			m_dwNetraVpssVp;
	};
}
TVidPortInfo;

typedef struct tagAudSrcInfo
{
	BOOL32 bAudHdmi0; //AUDIF_HDMI(0)  i-mix hdmi��Ƶ
	BOOL32 bAudHdmi1; //AUDIF_HDMI(1)  ΪOPSTV ��Ƶ a 
	BOOL32 bAudHdmi2; //AUDIF_HDMI(2)  Ϊterminal ��Ƶ
	BOOL32 bAudHdmi3; //AUDIF_HDMI(3)  ΪOPSTV ��Ƶ b 
	BOOL32 bAudHdmi4; //AUDIF_HDMI(4)  i-mix i2S��Ƶ
	BOOL32 bAudRca;   //AUDIF_RCA(0)   ΪRCA�ӿڵ���Ƶ
}TAudSrcInfo;

//����Ƶ���ʱ���Ų���
enum enPlayMode
{
	EN_PLAY_LAST = 0, //������һ֡
	EN_PLAY_BLACK,    //��ɫ����
	EN_PLAY_BMP,      //Ĭ��ͼƬ
	EN_PLAY_BMP_USER,  //�û�����ͼƬ
	EN_PLAY_ERROR
};

/*ͼ�����*/
enum
{
    VID_SCALE_BRIGHTNESS = 0, /* �������ȣ�  C | YPbPr */
    VID_SCALE_CONTRAST,       /* ���öԱȶȣ�C | YPbPr */
    VID_SCALE_HUE,            /* ����ɫ�ȣ�  C */
    VID_SCALE_SATURATION      /* ���ñ��Ͷȣ�C | YPbPr */
};

enum
{
	VID_OUTTYPE_ORIGIN = 0,	//ԭʼ��������
	VID_OUTTYPE_720P50,		//�̶��� 720p50���
	VID_OUTTYPE_720P60,		//�̶��� 720p60���
	VID_OUTTYPE_1080P24,	//�̶���1080p24���
	VID_OUTTYPE_1080P25,	//�̶���1080p25���
	VID_OUTTYPE_1080P30,	//�̶���1080p30���
	VID_OUTTYPE_1080P50,	//�̶���1080p50���
	VID_OUTTYPE_1080P60,	//�̶���1080p60��� 
	VID_OUTTYPE_XGA60,	  //�̶���XGA 60HZ��� 1024x768
	VID_OUTTYPE_SXGA60,	  //�̶���SXGA 60HZ���  1280x1024
	VID_OUTTYPE_WXGA1280x800_60,	  //�̶���WXGA 60HZ��� 1280x800
	VID_OUTTYPE_WXGA1366x768_60,	  //�̶���WXGA 60HZ��� 1360x768
	VID_OUTTYPE_WSXGA60,	  //�̶���WSXGA 60HZ��� 1440x900
	VID_OUTTYPE_WSXGAPLUS60,	  //�̶���SXGA+ 60HZ��� 1680x1050
	VID_OUTTYPE_2160P30,	//�̶���2160P30��� 3860*2160
	VID_OUTTYPE_2160P60,	//�̶���2160P60��� 3860*2160  
	//VID_OUTTYPE_WXGA1280x768_60,	  //�̶���WXGA 60HZ��� 1280x768
};

enum enZoomMode
{
    EN_ZOOM_FILLBLACK = 0,//�Ӻڱ�
    EN_ZOOM_CUT,//�ñ�
    EN_ZOOM_SCALE//���ȱ�����
};

//fpga������IMIX �ϵ���С����
typedef struct 
{
	u32 prohibit_start_x;
	u32 prohibit_start_y;
	u32 prohibit_end_x;
	u32 prohibit_end_y;
	u32 prohibit_start_x_2;
	u32 prohibit_start_y_2;
	u32 prohibit_end_x_2;
	u32 prohibit_end_y_2;
	u32 prohibit_start_x_3;
	u32 prohibit_start_y_3;
	u32 prohibit_end_x_3;
	u32 prohibit_end_y_3;
	u32 prohibit_start_x_4;
	u32 prohibit_start_y_4;
	u32 prohibit_end_x_4;
	u32 prohibit_end_y_4;
}TMcVidProhibitArea;

typedef struct 
{
	u32 flag; 		 //����2/3����2���滹��3����ϳ� 
	u32 start_x;
	u32 start_y;
	u32 height;
	u32 width;
	TMcVidProhibitArea tArea;
}TVidOverleyScreen;


/* ��Ƶ��������ӿں궨�� */
#define AUDIO_HDMI0					0x00000001//HDMI0
#define AUDIO_C0					0x00000030//c��
#define AUDIO_35mm0					0x00100000//3.5mm0

API void CodecCmdReg();
API void FpgaCmdReg();

class CVideoDecoder;
class CAudioDecoder;

class CKdvVidDec
{
public:
	CKdvVidDec();
	~CKdvVidDec();
public:
	/************************************************************************/
	/* ������:    Create                                                    */  
	/* ��������:                                                            */
	/*            TNetraCodecInfo* pDec    ��������������                   */
	/* ��������:  ����������												*/
	/************************************************************************/
    u16    Create(TVidDecImix* pDec);

	/************************************************************************/
	/* ������:      SetData                                                 */  
	/* ��������:                                                            */
	/*              TFrameHeader& tFrameInfo                                */
	/* ��������:	������Ƶ��������										*/
	/************************************************************************/
	u16    SetData(const TFrameHeader& tFrameInfo); 
	
	/************************************************************************/
	/* ������:      StartDec                                                */  
	/* ��������:                                                            */
	/*              ��                                                      */
	/* ��������:	��ʼͼ�����										    */
	/************************************************************************/
    u16    StartDec();

	/************************************************************************/
	/* ������:      StopDec                                                 */  
	/* ��������:                                                            */
	/*              ��                                                      */
	/* ��������:	ֹͣͼ�����										    */
	/************************************************************************/
    u16    StopDec(); 

	/************************************************************************/
	/* ������:      GetDecoderStatus                                        */  
	/* ��������:                                                            */
	/*              TKdvDecStatus &tKdvDecStatus ���ṹ��˵��               */
	/* ��������:	��ȡ����״̬��Ϣ										*/
	/************************************************************************/
	u16    GetDecoderStatus(TKdvDecStatus &tKdvDecStatus);

	/************************************************************************/
	/* ������:      GetDecoderStatis                                        */  
	/* ��������:                                                            */
	/*              TKdvDecStatis &tKdvDecStatis ���ṹ��˵��               */
	/* ��������:	��ȡ��������ͳ����Ϣ									*/
	/************************************************************************/
	u16    GetDecoderStatis(TKdvDecStatis &tKdvDecStatis);		
  
	/************************************************************************/
	/* ������:      SetPlayScale                                            */  
	/* ��������:                                                            */
	/*               u16 wWidth  :��ʾ�������0Ϊ�Զ�                       */
	/*               u16 wHeight :��ʾ�߱�����0Ϊ�Զ�						*/
	/* ��������:	���ò����豸����ʾ����									*/
	/*               ������ʽΪ16:9,����4:3��ͼ�����¼Ӻڱ�                 */
	/*               ������ʽΪ4:3,����16:9��ͼ�����ҼӺڱ�                 */
	/************************************************************************/
    u16    SetPlayZoomMode(enZoomMode emZoomMode);
    
	/************************************************************************/
	/* ������:      SetVideoPlyInfo                                         */  
	/* ��������:                                                            */
	/*              dwOutType  ������ʽ�� Ĭ�Ͽ���ά��ԭ����ʽ	            */
	/* ��������:	���ý��벥�ſ���ʽ										*/
	/************************************************************************/   
    u16	   SetVideoPlyInfo( u32 dwOutType /*= VID_OUTTYPE_ORIGIN*/ );

	/************************************************************************/
	/* ������:      GetVideoPlyInfo                                         */  
	/* ��������:                                                            */
	/*              TVidSrcInfo& tInfo ���ṹ��˵��         	            */
	/* ��������:	��ȡ���벥�ſ���ʽ										*/
	/************************************************************************/  
	u16    GetVideoPlyInfo(TVidSrcInfo& tInfo);   

	/************************************************************************/
	/* ������:     SnapShot                                                 */  
	/* ��������:                                                            */
	/*             s8* pFileName    �ļ���ȫ·��                            */
	/* ��������:   ����һ֡����ͼ��Ϊjpeg�ļ�								*/
	/************************************************************************/
	u16    SnapShot(s8* pFileName);

	/************************************************************************/
	/* ������:     RegAskIFrameCallBack                                      */  
	/* ��������:                                                             */
	/*           PASKIFRAMEPROC pFrameCallBackProc     ����I֡�Ļص�����    */
	/*           void* pContext    �û�������         						*/
	/*			u32 dwRequestIDRIntervalms   �ص����						*/
	/* ��������:	���ý���IDR֡�ص�										*/
	/************************************************************************/
	u16    RegAskIFrameCallBack(PASKIFRAMEPROC pFrameCallBackProc, void* pContext, u32 dwRequestIDRIntervalms);

	/************************************************************************/
	/* ������:     SetVidPlayPolicy                                          */  
	/* ��������:                                                             */
	/*           u32 dwTimeout     ��ʱ(ms)                                  */
	/*           u32 dwPlayType    ��ͼ���������  Ŀǰֻ֧�����һ֡�ͺ���  */
	/* ��������:	���ý��벥����ͼ����ʾ����							     */
	/************************************************************************/
	u16    SetVidPlayPolicy(u32 dwTimeout = 5000, u32 dwPlayType = EN_PLAY_LAST);

	/************************************************************************/
	/* ������:     SetShowRect                                          */  
	/* ��������:                                                             */
	/*           BOOL32 minimize        TRUE:��С��  FALSE�����           */
	/* ��������:	���ý��벥��ͼ�����ʾͼ��							     */
	/************************************************************************/
	u16    SetShowRect(BOOL32 bMinimize);

protected:
private:
	CVideoDecoder *m_pCodec;
};

class CKdvAudDec
{
public:
	CKdvAudDec();
	~CKdvAudDec();
public:
	u16	   CreateDecoder(TDecoder *pDecoer, u32 dwDevVersion);
	u16    GetDecoderStatus(TKdvDecStatus &tKdvDecStatus);/*��ȡ������״̬*/
    u16    GetDecoderStatis(TKdvDecStatis &tKdvDecStatis);/*��ȡ��������ͳ����Ϣ*/	
    u16    SetData(const TFrameHeader& tFrameInfo); /*������Ƶ��������*/   
    u16    StartDec();/*��ʼ��������*/	
    u16    StopDec(); /*ֹͣ��������*/	
	u16    SetAudOutPort(u32 dwAudPort);   //imix-c    ����
	u16    PlayRing(s8* pszFilePath = NULL);
	u16    StopRing();                      
protected:
private:
	CAudioDecoder *m_pCodec;
};

//�ӿ�FPGA����
void InitEnv();

u16 RegMediaSystemErrorCallBack(PMediaSystemErrorCallBack pCallBack, void* pContext);

void GetVidOutPortType(u32 dwVidIntf, u32 &dwRealPortType, TVidSrcInfo& tStd);

/************************************************************************/
/* ������:     SetHdmiSwitch                                            */  
/* ��������:                                                            */     
/*                   BOOL32 bOn=1 ��������ͬʱ���ߣ�3798���ݲ�����FPGA  */
/*                   BOOL32 bOn=0 ��������ͬʱ���ͣ�3798���ݿ��Ծ���FPGA*/
/* ��������:	����HDMI���أ���������			            			*/
/************************************************************************/
u16 SetHdmiSwitch(BOOL32 bUp);

/************************************************************************/
/* ������:     GetHdmiSwitch                                            */  
/* ��������:                                                            */
/*                   BOOL32 bOn=1 ��������ͬʱ���ߣ�3798���ݲ�����FPGA  */
/*                   BOOL32 bOn=0 ��������ͬʱ���ͣ�3798���ݿ��Ծ���FPGA*/
/* ��������:	��ȡHDMI����״̬����������			            		*/
/************************************************************************/
u16 GetHdmiSwitch(BOOL32 &bUp);

/************************************************************************/
/* ������:     SetVidInPortStd                                    */  
/* ��������:                                                            */
/*             u32 dwIntf  ��������ӿں�                               */
/*                         VIDIF_DSP_VP(0, 0)  i-mixΪ��OSD             */
/*	                       VIDIF_OSD_VP(0, 0)  i-mixΪOSD               */
/*	                       VIDIF_HDMI(0)  ΪOPSTV porta                 */
/*	                       VIDIF_HDMI(2)  ΪOPSTV portb                 */
/*	                       VIDIF_HDMI(1)  Ϊterminal                    */
/*             u32 dwPortType                ��ʽö��                   */
/* ��������:	������Ƶ����˿ڲ���			            		    */
/************************************************************************/
u16 SetVidInPortStd(u32 dwSrcIntf, u32 dwPortType);


/************************************************************************/
/* ������:     SetAdStatus                                            */  
/* ��������:                                                            */
/*             u32 dwSrcIntf  ��������ӿں�                               */
/*                         VIDIF_DSP_VP(0, 0)  i-mixΪ��OSD             */
/*	                       VIDIF_OSD_VP(0, 0)  i-mixΪOSD               */
/*	                       VIDIF_HDMI(0)  ΪOPSTV porta                 */
/*	                       VIDIF_HDMI(2)  ΪOPSTV portb                 */
/*	                       VIDIF_HDMI(1)  Ϊterminal                    */
/*             BOOL32 bStart               �Ƿ���dwIntf��Ӧ��оƬ     */
/* ��������:	ͨ���ӿ����øýӿڶ�Ӧ��AD/DAоƬ����ͣ      		    */
/*																		*/
/************************************************************************/
u16 SetAdStatus(u32 dwSrcIntf, BOOL32 bStart);

/************************************************************************/
/* ������:     ReSetAd                                            */  
/* ��������:                                                            */
/* u32 dwSrcIntf  Ϊ����������Ƶ��source intf���ӿڣ���Ϊ���¼��֣�*/
/*              VIDIF_DSP_VP(0, 0)  VIDIF_OSD_VP(0, 0)  ����ʾ��λ��һ��7619оƬ������hi3798оƬ���ǿ�            */
/*	           VIDIF_HDMI(0)   VIDIF_HDMI(2) ����ʾ��λ�ڶ���7619оƬ������ǰ����opstv���ǿ�  */
/*	           VIDIF_HDMI(1)  ��λ��3��7619оƬ�������ն�������ǿ�*/
/* ��������: ͨ���ӿ����øýӿڶ�Ӧ��AD/DAоƬ����ͣ  	    */
/*																		                   */
/************************************************************************/
u16 ReSetAd(u32 dwSrcIntf);

/************************************************************************/
/* ������:     GetVidInPortInfo                                    */  
/* ��������:                                                            */
/*             u32 dwIntf  ��������ӿں�                               */
/*                         VIDIF_DSP_VP(0, 0)  i-mixΪ��OSD             */
/*	                       VIDIF_OSD_VP(0, 0)  i-mixΪOSD               */
/*	                       VIDIF_HDMI(0)  ΪOPSTV porta                 */
/*	                       VIDIF_HDMI(2)  ΪOPSTV portb                 */
/*	                       VIDIF_HDMI(1)  Ϊterminal                    */
/*             u32 &dwRealPortType     ��ʽö��                         */
/*             BOOL32 bVideoSignal     �Ƿ����źŶ�Porta/portb��Ч      */
/*                    TVidSrcInfoe     ���ṹ��                         */
/* ��������:	������Ƶ����˿ڲ���			            		    */
/************************************************************************/
void GetVidInPortInfo(u32 dwSrcIntf, u32 &dwRealPortType, TVidSrcInfo& tStd, BOOL32 &bVideoSignal);
/************************************************************************/
/* ������:     SetVidOsdParam                                           */  
/* ��������:                                                            */
/*             u32 dwIntf  ��������ӿں�VIDIF_HDMI(0)����VIDIF_HDMI(1) */
/*             TVidSrcInfo &tOsd0Std osd��Ҫ���ź�Ŀ��    			*/
/*             u32 dwTransVal 0-0xff 0��ȫ͸ 255����͸��    			*/
/*             u32 dwTransKeyY 0x10-0xf0                        	    */
/*             BOOL32 bMid ����                                	        */
/* ��������:	����OSD���Ų����ӿ�			            				*/
/************************************************************************/
u16 SetVidOsdParam(u32 dwVidPortType, u32 dwOsdPortType, u32 dwTransVal, u32 dwTransKeyY, BOOL32 bCutEnable, BOOL32 bMid);
/************************************************************************/
/* ������:     ConnectVidInft                                    */  
/* ��������:                                                            */
/*             u32 dwDstIntf                                            */
/*                      ��������ӿں�VIDIF_HDMI(0)����VIDIF_HDMI(1)����*/
/*             u32 dwSrcIntf  ��������ӿں�                            */
/*                         VIDIF_DSP_VP(0, 0)  i-mixΪ��OSD             */
/*	                       VIDIF_OSD_VP(0, 0)  i-mixΪOSD               */
/*	                       VIDIF_HDMI(0)  ΪOPSTV porta                 */
/*	                       VIDIF_HDMI(2)  ΪOPSTV portb                 */
/*	                       VIDIF_HDMI(1)  Ϊterminal                    */
/*             BOOL32 bUpdateDstStdUsingSrcStd == TRUE 				    */
/*                               �Ƿ�Դ����ʽ����Ŀ��ӿڵ���ʽ       */
/* ��������:	������Ƶ����˿ڲ���			            		    */
/************************************************************************/
u16  ConnectVidIntf(u32 dwDstIntf, u32 dwSrcIntf, BOOL32 bUpdateDstStdUsingSrcStd = TRUE);

/************************************************************************/
/* ������:     SnapShot                                                 */  
/* ��������:                                                            */
/*             u32 dwIntf  ��������ӿں�VIDIF_HDMI(0)����VIDIF_HDMI(1) */
/*             s8* pFileName    �ļ���ȫ·��                            */
/* ��������:   ����һ֡����ͼ��Ϊjpeg�ļ�								*/
/************************************************************************/
u16  SnapShot(u32 dwIntf, s8* pFileName);

/************************************************************************/
/* ������:     SetAudioVolume                                           */  
/* ��������:                                                            */
/*             u32 dwIntf  ��������ӿں�                               */
/*                     AUDIF_HDMI(0)��AUDIF_HDMI(1)��AUDIF_JACK_3mm5(0) */
/*             u8 byVolume ��Χ��               			            */
/* ��������:	���������������			            			    */
/************************************************************************/
u16 SetAudioVolume(u32 dwIntf, u8 byVolume );

/************************************************************************/
/* ������:     GetAudioVolume                                           */  
/* ��������:                                                            */
/*             u32 dwIntf  ��������ӿں�                               */
/*                     AUDIF_HDMI(0)��AUDIF_HDMI(1)��AUDIF_JACK_3mm5(0) */
/*             u8 byVolume ��Χ��               			            */
/* ��������:	���������������			            			    */
/************************************************************************/
u16 GetAudioVolume(u32 dwIntf, u8 &pbyVolume );

/************************************************************************/
/* ������:     SetAudioMute                                             */  
/* ��������:                                                            */
/*             u32 dwIntf  ��������ӿں�
/*                     AUDIF_HDMI(0)��AUDIF_HDMI(1)��AUDIF_JACK_3mm5(0) */
/*             BOOL32 bMute 1������ 0��ȡ������               			*/
/* ��������:	���������������			            			    */
/************************************************************************/
u16 SetAudioMute(u32 dwIntf, BOOL32 bMute);		

/************************************************************************
* ������:     SetAudioLimit
* ��������:
*             u32 dwIntf  ��������ӿں�
*                     AUDIF_HDMI(0)��AUDIF_HDMI(1)��AUDIF_JACK_3mm5(0)
*             u32 dwUpper  ����ֵ
              u32 dwLower  ����ֵ
* ��������:	���������AIC3104��Ƶ���ݴ�С�ķ�Χ
************************************************************************/
u16 SetAudioLimit(u32 dwIntf, u32 dwUpper, u32 dwLower);

/************************************************************************/
/* ������:     SelAudMixIntf                                            */  
/* ��������:                                                            */
/*             u32 dwIntf1/dwIntf2  ��Ƶ��������ӿں�                  */
/*                         AUDIF_HDMI(0)  i-mix��Ƶ hdmi��Ƶ            */
/*	                       AUDIF_HDMI(1)  ΪOPSTV ��Ƶ a                */
/*	                       AUDIF_HDMI(2)  Ϊterminal ��Ƶ               */
/*	                       AUDIF_HDMI(3)  ΪOPSTV ��Ƶ b                */
/*                         AUDIF_HDMI(4)  i-mix i2s��Ƶ                 */
/*	                       AUDIF_RCA(0)   ΪRCA�ӿڵ���Ƶ               */
/* ��������:	ѡ��������������·������Ƶ            			    */
/************************************************************************/
u16 SelAudMixIntf(u32 dwIntf1, u32 dwIntf2);

/************************************************************************/
/* ������:     SetAudIntfSampleRate                                     */  
/* ��������:                                                            */
/*                      u32 dwIntf  ��Ƶ��������ӿں�                  */
/*                         AUDIF_HDMI(0)  i-mix��Ƶ hdmi��Ƶ            */
/*	                       AUDIF_HDMI(1)  ΪOPSTV ��Ƶ a                */
/*	                       AUDIF_HDMI(2)  Ϊterminal ��Ƶ               */
/*	                       AUDIF_HDMI(3)  ΪOPSTV ��Ƶ b                */
/*                         AUDIF_HDMI(4)  i-mix i2s��Ƶ                 */
/*	                       AUDIF_RCA(0)   ΪRCA�ӿڵ���Ƶ               */
/*                      enSampleRate emSampRate:                        */
/*                                            8K 16K 32K 44.1K 48K      */
/* ��������:	ѡ��������������·������Ƶ            			    */
/************************************************************************/
u16 SetAudIntfSampleRate(u32 dwIntf, enSampleRate emSampRate);

/************************************************************************/
/* ������:     SetAud0VolumPreMix                                       */  
/* ��������:                                                            */
/*                      u32 dwIntf  ��Ƶ��������ӿں�                  */
/*                         AUDIF_HDMI(0)  i-mix��Ƶ hdmi��Ƶ            */
/*	                       AUDIF_HDMI(1)  ΪOPSTV ��Ƶ a                */
/*	                       AUDIF_HDMI(2)  Ϊterminal ��Ƶ               */
/*	                       AUDIF_HDMI(3)  ΪOPSTV ��Ƶ b                */
/*                         AUDIF_HDMI(4)  i-mix i2s��Ƶ                 */
/*	                       AUDIF_RCA(0)   ΪRCA�ӿڵ���Ƶ               */
/*                      u32 dwMixerInputId ��������·����Id�ֱ���0��1   */
/*                      u8 byVolume                                     */
/* ��������:	���û���ǰ��audio��ƵԴ������            			    */
/************************************************************************/
u16 SetAudVolumPreMix(u32 dwIntf, u32 dwMixerInputId, u8 byVolume);

/************************************************************************/
/* ������:     SetAud0VolumPreMix                                       */  
/* ��������:                                                            */
/*                      u32 dwIntf  ��Ƶ��������ӿں�                  */
/*                         AUDIF_HDMI(0)  i-mix��Ƶ hdmi��Ƶ            */
/*	                       AUDIF_HDMI(1)  ΪOPSTV ��Ƶ a                */
/*	                       AUDIF_HDMI(2)  Ϊterminal ��Ƶ               */
/*	                       AUDIF_HDMI(3)  ΪOPSTV ��Ƶ b                */
/*                         AUDIF_HDMI(4)  i-mix i2s��Ƶ                 */
/*	                       AUDIF_RCA(0)   ΪRCA�ӿڵ���Ƶ               */
/*                      u32 dwMixerInputId ��������·����Id�ֱ���0��1   */
/*                      u8 byVolume                                     */
/* ��������:	��ȡ����ǰ��audio��ƵԴ������            			    */
/************************************************************************/
u16 GetAudVolumPreMix(u32 dwIntf, u32 dwMixerInputId, u8 &pbyVolume);

/************************************************************************/
/* ������:     GetAudSrcInfo                                            */  
/* ��������:                                                            */
/*                      TAudSrcInfo  ���ṹ��˵��                       */
/* ��������:	��ȡaudio��ƵԴ�Ƿ����ź�                			    */
/************************************************************************/
u16 GetAudSrcInfo(TAudSrcInfo &tAudSrcInfo);

/************************************************************************/
/* ������:     ConnectAudInft                                           */  
/* ��������:                                                            */
/*             u32 dwDstIntf                                            */
/*                     AUDIF_HDMI(0)��AUDIF_HDMI(1)��AUDIF_JACK_3mm5(0) */
/*                   u32 dwSrcIntf  ��Ƶ��������ӿں�                  */
/*                         AUDIF_HDMI(0)  i-mix��Ƶ hdmi��Ƶ            */
/*	                       AUDIF_HDMI(1)  ΪOPSTV ��Ƶ a                */
/*	                       AUDIF_HDMI(2)  Ϊterminal ��Ƶ               */
/*	                       AUDIF_HDMI(3)  ΪOPSTV ��Ƶ b                */
/*                         AUDIF_HDMI(4)  i-mix i2s��Ƶ                 */
/*	                       AUDIF_RCA(0)   ΪRCA�ӿڵ���Ƶ               */
/* ��������:	������Ƶ��������ӿ�			            		    */
/************************************************************************/
u16 ConnectAudInft(u32 dwDstIntf, u32 dwSrcIntf);

/************************************************************************/
/* ������:     SetOpsStatus                                             */  
/* ��������:                                                            */
/*             BOOL32 bOpen                                             */
/*                    TRUE:�� FALSE����                                 */
/* ��������:   ����Ops����          			            		    */
/************************************************************************/
u16 SetOpsStatus(BOOL32 bOpen);

/************************************************************************/
/* ������:     SetVidFreezePrm                                           */  
/* ��������:                                                            */
/*             u32 dwSrcIntf  ��������ӿں�                            */
/*                         VIDIF_DSP_VP(0, 0)  i-mixΪ��OSD             */
/*	                       VIDIF_OSD_VP(0, 0)  i-mixΪOSD               */
/*	                       VIDIF_HDMI(0)  ΪOPSTV porta                 */
/*	                       VIDIF_HDMI(2)  ΪOPSTV portb                 */
/*	                       VIDIF_HDMI(1)  Ϊterminal                    */
/*			 dwFreezeMode  0:�ⶳ��������Դ						        */
/*						   1:����imix,  �ⶳOPUS TERMINAL			 	        */
/*						   2:�ⶳOPS,  ����IMIX TERMINAL                                 */
/*						   3:����imix,oPS,�ⶳTERMINAL					*/
/*						   4:����TERMINAL,�ⶳimix,oPS					*/
/*						   5:����TERMINAL,imix,�ⶳoPS					*/
/*						   6:����TERMINAL,OPS �ⶳimiX					*/
/*						   7:������������Դ				             */
/*                         0x10:����IMIX��                               */
/*                         0x80:����scaler��                             */
/*                         0x90:����scaler����IMIX��                     */
/* ��������: ������Ƶ����                 		               		    */
/************************************************************************/
u16 SetVidFreezePrm(u32 dwSrcIntf, u32 dwFreezeMode);

/************************************************************************/
/* ������:		SetVidPlyPortStd										 */  
/* ��������:															 */
/*				 u32 dwintf	  ���ſ� 	VIDIF_HDMI(0)\ VIDIF_HDMI(1) 	 */
/*				 u32 dwOutType  ������ʽ�� ����VID_OUTTYPE_720P50	     */
/* ��������:	���ýӿ������ʽ									     */
/************************************************************************/
u16 SetVidPlyPortStd(u32 dwintf, u32 dwOutType = VID_OUTTYPE_ORIGIN);

/************************************************************************/
/* ������:		StartFpgaScale(BOOL32 bStart)        					 */  
/* ��������:															 */
/*				 BOOL32 bStart	  �Ƿ�������      					 */
/* ��������:	����FPGA���ţ�Ŀǰֻ���IMIX							 */
/************************************************************************/
u16 StartFpgaScale(BOOL32 bStart);

/************************************************************************/
/* ������:		SetAmplifierStatus(BOOL32 bMute)        					 */  
/* ��������:															 */
/*				 BOOL32 bMute	  �Ƿ񹦷ž���        					 */
/* ��������:	���ù����Ƿ���ͨ��GPIO�ӿڿ���    	 */
/************************************************************************/
u16 SetAmplifierStatus(BOOL32 bMute);

/************************************************************************/
/* ������:		SetFpgaVidOverlay(BOOL32 bMute)        					  */  
/* ��������:															  */
/*				 u32 dwintf	  opstv/termina        					                        */
/*	                                              VIDIF_HDMI(0)  ΪOPSTV porta                                  */
/*	                                              VIDIF_HDMI(2)  ΪOPSTV portb                                  */
/*	                                              VIDIF_HDMI(1)  Ϊterminal                                         */
/*                                                 TVidOverleyScreen tVidLittleProhibitScreen       */
/* ��������:	���ù����Ƿ���ͨ��GPIO�ӿڿ���    	  */
/************************************************************************/
u16 SetFpgaVidOverlay(u32 dwintf, TVidOverleyScreen tVidLittleProhibitScreen);

/************************************************************************/
/* ������:		SetFpgaVidOverlayMode(BOOL32 bMute)        					             */  
/* ��������:															             */
/*				 u32 dwOutintf	  ����ӿ� VIDIF_HDMI(0)   / VIDIF_HDMI(1)  	      */
/*                          u32 dwMode   0: 3ѡ1ģʽ                                                                         */
/*     						   1:	2�����ͼģʽ						             */
/*     						   2:	2�������ģʽ						             */
/*     						   3:	3�������ģʽ						             */
/* ��������:	���û������  ģʽ                                                           	      */
/************************************************************************/
u16 SetFpgaVidOverlayMode(u32 dwOutintf, u32 dwMode);

#endif
