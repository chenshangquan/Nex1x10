#ifndef _KDVMEDIANET_0603_H_
#define _KDVMEDIANET_0603_H_

#include "osp.h"
#include "kdvdef.h"

/*for ios*/
#if (defined(__APPLE__) && defined(__MACH__)) || \
    (defined(macintosh) || defined(Macintosh)) || \
    defined(__MACOSX__)

/*for kdvmedianet64.h*/
# define _KDVMEDIANET_64_HEADER
#endif // for ios

#ifdef _KDVMEDIANET_64_HEADER
#include <kdvmedianet64.h>
#else

#if defined(_MSC_VER)
#include <Winsock2.h>
#include <ws2tcpip.h>
#if defined(_DLL_MEDIANET_)
#define MN_C_SYM    extern "C" __declspec(dllexport)
#define MN_CPP_SYM  __declspec(dllexport)
#else
#define MN_C_SYM    extern "C" __declspec(dllimport)
#define MN_CPP_SYM  __declspec(dllimport)
#endif
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#define MN_C_SYM    extern "C"
#define MN_CPP_SYM  __attribute__ ((visibility("default")))
#endif

#define  MEDIANET_NO_ERROR                  (u16)0//�ɹ�����ֵ
#define  ERROR_MEDIA_NET_BASE               (u16)16000
#define  ERROR_SND_PARAM                    (ERROR_MEDIA_NET_BASE+1)//���÷���ģ���������
#define  ERROR_SND_NOCREATE                 (ERROR_MEDIA_NET_BASE+2)//����ģ��û�д���
#define  ERROR_SND_MEMORY                   (ERROR_MEDIA_NET_BASE+3)//����ģ���ڴ��������
#define  ERROR_SND_CREATE_SOCK              (ERROR_MEDIA_NET_BASE+4)//����ģ�鴴��socket
#define  ERROR_RTP_SSRC                     (ERROR_MEDIA_NET_BASE+5)//RTPͬ��Դ����.
#define  ERROR_LOOPBUF_CREATE               (ERROR_MEDIA_NET_BASE+6)//��״���崴������
#define  ERROR_RTP_NO_INIT                  (ERROR_MEDIA_NET_BASE+7)//RTP����Щ����û����

#define  ERROR_RTCP_NO_INIT                 (ERROR_MEDIA_NET_BASE+8)//RTP����Щ����û����
#define  ERROR_RTCP_SET_TIMER               (ERROR_MEDIA_NET_BASE+9)//RTCP���ö�ʱ������

#define  ERROR_RTP_SSRC_COLLISION           (ERROR_MEDIA_NET_BASE+10)//RTP ͬ��Դ����


#define  ERROR_H261_PACK_NUM                (ERROR_MEDIA_NET_BASE+12)//H261�İ���������
#define  ERROR_PACK_TOO_LEN                 (ERROR_MEDIA_NET_BASE+13)//G.711�����ٰ�̫��
#define  ERROR_H263_PACK_NUM                (ERROR_MEDIA_NET_BASE+14)//H263�İ���������
#define  ERROR_H263_PACK_TOOMUCH            (ERROR_MEDIA_NET_BASE+15)//H263�����ݰ�̫��

#define  ERROR_SND_INVALID_SOCK             (ERROR_MEDIA_NET_BASE+16)//����ģ����Чsocket
#define  ERROR_SND_SEND_UDP                 (ERROR_MEDIA_NET_BASE+17)//����ģ�����ݰ�Ͷ��ʧ�ܣ�Ŀ����ܲ��ɴ
#define  ERROR_SND_FRAME                     (ERROR_MEDIA_NET_BASE+18)//����ģ��֡�������

#define  ERROR_NET_RCV_PARAM                (ERROR_MEDIA_NET_BASE+100)//���ý���ģ���������
#define  ERROR_NET_RCV_NOCREATE             (ERROR_MEDIA_NET_BASE+101)//����ģ��û�д���
#define  ERROR_NET_RCV_MEMORY               (ERROR_MEDIA_NET_BASE+102)//����ģ���ڴ��������
#define  ERROR_RCV_RTP_CREATE               (ERROR_MEDIA_NET_BASE+103)//����ģ��RTP����ʧ��
#define  ERROR_RCV_RTP_CALLBACK             (ERROR_MEDIA_NET_BASE+104)//����ģ������RTP�ص�����ʧ��
#define  ERROR_RCV_RTP_SETREMOTEADDR        (ERROR_MEDIA_NET_BASE+105)//����ģ������RTPԶ�˵�ַʧ��
#define  ERROR_CREATE_LOOP_BUF              (ERROR_MEDIA_NET_BASE+106)//������״����ʧ��
#define  ERROR_RCV_NO_CREATE                (ERROR_MEDIA_NET_BASE+107)//����ģ����ն���û�д���

#define  ERROR_WSA_STARTUP                  (ERROR_MEDIA_NET_BASE+200)//wsastartup error
#define  ERROR_CREATE_SEMAPORE              (ERROR_MEDIA_NET_BASE+201)// create semapore error


#define  ERROR_SOCK_INIT                    (ERROR_MEDIA_NET_BASE+301)//socket û�г�ʼ��
#define  ERROR_SOCK_CREATE                  (ERROR_MEDIA_NET_BASE+301)//socket û�г�ʼ��
#define  ERROR_SOCKET_CALL                  (ERROR_MEDIA_NET_BASE+302)//����socket() ��������
#define  ERROR_BIND_SOCKET                  (ERROR_MEDIA_NET_BASE+303)//socket �󶨳���
#define  ERROR_SOCK_ADDRINUSE               (ERROR_MEDIA_NET_BASE+304)//socket �˿���ʹ��
#define  ERROR_SOCK_RTP_ADDRINUSE           (ERROR_MEDIA_NET_BASE+305)//socket RTP�˿���ʹ��
#define  ERROR_SOCK_RTCP_ADDRINUSE          (ERROR_MEDIA_NET_BASE+306)//socket RTCP�˿���ʹ��

#define  ERROR_ADDTO_CHECK_THREAD           (ERROR_MEDIA_NET_BASE+401)

#define  ERROR_SEND_BUFFMGR                 (ERROR_MEDIA_NET_BASE+411)
#define  ERROR_SEND_BUFF_FULL               (ERROR_MEDIA_NET_BASE+412)

#define  ERROR_RECV_BUFFMGR                 (ERROR_MEDIA_NET_BASE+451)
#define  ERROR_RECV_BUFF_FULL               (ERROR_MEDIA_NET_BASE+452)


#define  ERROR_RECV_FRAME_EMPTY             (ERROR_MEDIA_NET_BASE+461)
#define  ERROR_RECV_FRAME_WAITTIME          (ERROR_MEDIA_NET_BASE+462)
#define  ERROR_RECV_FRAME_FULL              (ERROR_MEDIA_NET_BASE+463)
#define  ERROR_RECV_RTP_CHECK               (ERROR_MEDIA_NET_BASE+464)

#define  ERROR_CREATE_THREAD                (ERROR_MEDIA_NET_BASE+204)//�����̳߳���

#define  ERROR_LOOPBUF_FULL                 (ERROR_MEDIA_NET_BASE+205)//ѭ��������
#define  ERROR_NULL_POINT                   (ERROR_MEDIA_NET_BASE+206)//��ָ��

#define  ERROR_SET_DECRYPTKEY               (ERROR_MEDIA_NET_BASE+210)//���ý���keyʧ��
#define  ERROR_DECRYPT_FRAME                (ERROR_MEDIA_NET_BASE+212)//����һ֡ʧ��
#define  ERROR_SET_ENCRYPTKEY               (ERROR_MEDIA_NET_BASE+213)//���ü���keyʧ��
#define  ERROR_ENCRYPT_FRAME                (ERROR_MEDIA_NET_BASE+215)//����һ֡ʧ��
#define  ERROR_SET_USERDATA                 (ERROR_MEDIA_NET_BASE+216)//����һ֡ʧ��
#define  ERROR_SENDER_FEC_CRC               (ERROR_MEDIA_NET_BASE+217)//����fec�������
#define  ERROR_RECEIVER_FEC_CRC             (ERROR_MEDIA_NET_BASE+218)//����fec�������
#define  ERROR_RECEIVER_FEC_MODE_INVALID    (ERROR_MEDIA_NET_BASE+219)//����fecģʽ����
#define  ERROR_SENDER_FEC_INORDER           (ERROR_MEDIA_NET_BASE+220)//����fec����
#define  ERROR_SENDER_FEC_INVALID_PARAM     (ERROR_MEDIA_NET_BASE+221)//����fec�������
#define  ERROR_ARRAY_TOO_SMALL              (ERROR_MEDIA_NET_BASE+222)//����̫С

#define MIN_PRE_BUF_SIZE                    (s32)28// G.711���ټ�һ�ֽ�

#define MAX_H261_HEADER_LEN      (s32)388//
#define MAX_H263_HEADER_LEN      (s32)3076//
#define MAX_H263PLUS_HEADER_LEN  (s32)3076//

#ifndef DES_ENCRYPT_MODE
#define DES_ENCRYPT_MODE         (u8)0      //DES����ģʽ
#define AES_ENCRYPT_MODE         (u8)1      //AES����ģʽ
#define ENCRYPT_KEY_SIZE         (u8)32     //��Կ���� ȡ���еĽϴ�ֵ
#define DES_ENCRYPT_KEY_SIZE     (u8)8      //DES��Կ����
#define AES_ENCRYPT_KEY_SIZE_MODE_A (u8)16  //AES Mode-A ��Կ����
#define AES_ENCRYPT_KEY_SIZE_MODE_B (u8)24  //AES Mode-B ��Կ����
#define AES_ENCRYPT_KEY_SIZE_MODE_C (u8)32  //AES Mode-C ��Կ����
#endif

#ifndef  MAX_NETSND_DEST_NUM
#define  MAX_NET_DEST_NUM   5
#endif

#define MAX_USERDATA_LEN    16

//���Ų���(������medianet.h���屣��ͬ��)
#define MAX_DELAY_UNKNOWN        0
#define MAX_DELAY_QUALITY        1
#define MAX_DELAY_QUALITY_NOAVS  2
#define MAX_DELAY_SPEED          3
#define MAX_DELAY_BALANCE        4


//Frame Header Structure
typedef struct tagFrameHdr {
	u8     m_byMediaType; //ý������
	u8    *m_pData;       //���ݻ���
	u32    m_dwPreBufSize;//m_pData����ǰԤ���˶��ٿռ䣬���ڼ�
	// RTP option��ʱ��ƫ��ָ��һ��Ϊ12+4+12
	// (FIXED HEADER + Extence option + Extence bit)
	u32    m_dwDataSize;  //m_pDataָ���ʵ�ʻ����С�����С
	u8     m_byFrameRate; //����֡��,���ڽ��ն�
	u32    m_dwFrameID;   //֡��ʶ�����ڽ��ն�
	u32    m_dwTimeStamp; //ʱ���, ���ڽ��ն�
    u64    m_qwCaptureMs; //�ɼ�ʱ��
                          //����ʱΪIN����,������MONOTONICʱ��,ms��λ(0����÷���ʱ����Ϊ�ɼ�ʱ��)
                          //����ʱΪOUT����,��������NTPʱ��,ms��λ(0������δ�յ�SR��Ϣ,�޷�����ɼ�ʱ��)
	u32    m_dwSSRC;      //ͬ��Դ, ���ڽ��ն�
	union {
		struct {
			BOOL32    m_bKeyFrame;    //Ƶ֡���ͣ�I or P��
			u16       m_wVideoWidth;  //��Ƶ֡��
			u16       m_wVideoHeight; //��Ƶ֡��
			BOOL32    m_bHighProfile; // H264 HP��ʶ
		} m_tVideoParam;
		struct{
				   BOOL32    m_bIncludeAudioLevel; //�Ƿ����audio level
				   BOOL32 	 m_bV; //�Ƿ�Ϊ����
				   u8		 m_byAudioLevel; // ��Ƶ������ 0~127(-dBov)
				   u8        m_byAudioMode;
				   s32       m_nPacMs; //ÿ֡ʱ��
			  }m_tAudioParam;
	};

} FRAMEHDR, *PFRAMEHDR;

typedef struct tagNetSession {
	TOspNetAddr tRTPAddr;
	TOspNetAddr tRTCPAddr;
} TNetSession;

/*�������*/
typedef struct tagMnetNetParam {
	u8          m_byRemoteNum;                    //ʵ��Զ�˵�ַ����,���Ϳ���
	//���MAX_NET_DEST_NUM��������ʱֻ֧��1��
	TNetSession m_tLocalNet;                     //���ص�ַ��
	TNetSession m_tRemoteNet[MAX_NET_DEST_NUM];  //Զ�˵�ַ��
} TMnetNetParam;

typedef struct tagFecParam {
	BOOL32      m_bUseFec;
	BOOL32      m_bIntraFrame;
	u8          m_nFecMode;
	s32         m_nFecPacklen;
	s32         m_nFecDataPackNum;
	s32         m_nFecCrcPackNum;
} TFecParam;

/*����ģ��״̬��Ϣ*/
typedef struct tagKdvSndStatus {
	u8           m_byMediaType;   //ý������
	u32          m_dwMaxFrameSize;//����֡��С
	u32          m_dwNetBand;     //���ʹ���(bps)
	u32          m_dwFrameID;     //����֡��ʶ
	u8           m_byFrameRate;   //����Ƶ��
	TMnetNetParam    m_tSendAddr;     //���͵�ַ
	TFecParam    m_tFecParam;
	BOOL32       m_bReverseG7221c;
} TKdvSndStatus;

/*����ģ��ͳ����Ϣ*/
typedef struct tagKdvSndStatistics {
	u32 m_dwPackSendNum; //�ѷ��͵İ���
	u32 m_dwFrameNum;    //�ѷ��͵�֡��
	u32 m_dwFrameLoseNum;//���ڻ�������ԭ����ɵķ��͵Ķ�֡��
} TKdvSndStatistics;

/*����scoket��Ϣ*/
typedef struct tagKdvSndSocketInfo {
	BOOL32 m_bUseRawSocket;
	u32    m_dwSrcIP;
	u32    m_wPort;
} TKdvSndSocketInfo;

/*����ģ��״̬��Ϣ*/
typedef struct tagKdvRcvStatus {
	BOOL32          m_bRcvStart;  //�Ƿ�ʼ����
	u32             m_dwFrameID;  //����֡ID
	TMnetNetParam       m_tRcvAddr;   //���յ��ص�ַ
	u32             m_dwFecFrameId;
	BOOL32          m_bReverseG7221c;

	TFecParam       m_tFecPar;
} TKdvRcvStatus;

/*������ͳ����Ϣ*/
typedef struct tagKdvRcvStatistics {
	u32    m_dwPackNum;       //�����ش�����ǰ�յ����ܰ���
	u32    m_dwPackLose;      //�����ش����Ժ��յ����ܰ���
	u32    m_dwPackIndexError;//��������
	u32    m_dwFrameNum;      //�ѽ��յ�֡��
	u32     m_dwPhysicalPackLose;//�����ش�����ǰ�Ķ�������
	//  u32    m_dwFrameLoseNum;  //��������Դ�л���ն��е�ԭ����ɵĽ��յĶ�֡��

	u32 m_dwFecPackNum;//���յ���fec����
	u32 m_dwFecPackLose;//��fec����󻹶����İ�����֡ʱ���������İ�
	u32 m_dwFecRealFrameNum;//fec��֡���������յ���fec������
	u32 m_dwFecNeedRecovery;
	u32 m_dwFecRecoSucc;
	u32 m_dwFecRecoFail;
} TKdvRcvStatistics;

typedef struct tagRtpPack {
	u8   m_byMark;          //�Ƿ�֡�߽�1��ʾ���һ��
	u8   m_byExtence;       //�Ƿ�����չ��Ϣ
	u8   m_byPadNum;        //���ܵ�padding����
	u8   m_byPayload;       //�غ�
	u32  m_dwSSRC;          //ͬ��Դ
	u16  m_wSequence;       //���к�
	u32  m_dwTimeStamp;     //ʱ���
	u8  *m_pExData;         //��չ����
	s32  m_nExSize;         //��չ��С��sizeof(u32)�ı�����
	u8  *m_pRealData;       //ý������
	s32  m_nRealSize;       //���ݴ�С
	s32  m_nPreBufSize;     //m_pRealDataǰԤ����Ŀռ�;
    BOOL32 m_bIncludeAudioLevel; //�Ƿ����audio level
	BOOL32 m_bV; //�Ƿ�Ϊ����
	u8	 m_byAudioLevel;    // ��Ƶ������ 0~127(-dBov)
} TRtpPack;

typedef struct {
	u32 m_dwTotalBlock;
	u32 m_dwCurFreeBlock;
	u32 m_dwMinFreeBlock;

	u32 m_dwBitrate;        //��λkbps
	u32 m_dwRealBitrate;    //��λkbps

	BOOL32 m_bDirectSend;

	BOOL32 m_bFecEnable;

} TSendRtpStatus;

//���Ͷ˸߼����ò���
typedef struct tagAdvancedSndInfo {
	s32      m_nMaxSendNum;      // ���ݴ�����������ʹ���;
	BOOL32   m_bRepeatSend;      // ���� (mp4) �Ƿ��ط�
	u16      m_wBufTimeSpan;
	BOOL32   m_bEncryption;      // ���� (mp4/H.26X/Audio) �Ƿ����ü���
	u8       m_byEncryptMode;    // ����ģʽ Aes ���� Des
	u16      m_wKeySize;         // ������Կ����
	s8       m_szKeyBuf[ENCRYPT_KEY_SIZE + 1]; // ������Կ����
	u8       m_byLocalActivePT;  // ��̬�غ�PTֵ
	s32      m_nResendTimes;  //�ط�����
	s32      m_nResendSpan;   //�ط����
} TAdvancedSndInfo;

//���ն˸߼����ò���
typedef struct tagAdvancedRcvInfo {
	BOOL32    m_bConfuedAdjust;  // ���� (mp3) �Ƿ����������
	BOOL32    m_bRepeatSend;     // ���� (mp4) �Ƿ��ط�
	BOOL32    m_bDecryption;     // ���� (mp4/H.26X/Audio) �Ƿ����ý���
	u8        m_byDecryptMode;   // ����ģʽ Aes ���� Des
	u16       m_wKeySize;        // ������Կ����
	s8        m_szKeyBuf[ENCRYPT_KEY_SIZE + 1]; // ������Կ����
	u8        m_byRmtActivePT;   // ���յ��Ķ�̬�غɵ�Playloadֵ
	u8        m_byRealPT;        // �ö�̬�غ�ʵ�ʴ���ĵ�Playload���ͣ�ͬ�ڷ���ʱ��PTԼ��
	u8          m_byLastFrameType;
} TAdvancedRcvInfo;

typedef struct {
	//block use info
	u32 m_dwTotalBlock;
	u32 m_dwCurFreeBlock;
	u32 m_dwMinFreeBlock;

	u32 m_dwRealBitrate;         //��λkbps

	//frame num
	u32 m_dwCurFrameNum;
	u32 m_dwMaxFrameNum;

	u32 m_dwFrameDuration;
	u32 m_dwDelayFrameNum;

	BOOL32 m_bDirectCallback;
	s32 m_nAudioDelayNum;

    BOOL32 m_bHasCompleteKeyFrame; // Buffer���Ƿ��Ѿ��յ���������Ƶ�ؼ�֡
                                   // �Ѿ��յ��Ļ�,��������ֹͣ����ؼ�֡
                                   // (����ȵ��ص��ؼ�֡���ֹͣ����)

	//����ͳ��
	u32 m_dwRecvNum;
	u32 m_dwRealLostNum;
	u32 m_dwLostBackOkNum;

	u32 m_dwRegetNum;

	u32 m_dwCurMaxBuffTime;
	u32 m_dwLoopTime;        //loop time
	u32 m_dwCurLoopTime;

	u32 m_dwDisSortTime;

	//FEC
	BOOL32 m_bFecEnable;
	u32 m_dwFecPacket;
	u32 m_dwFecCorrect;
} TRecvRtpStatus;

//��̬��������(������medianet.h���屣��ͬ��)
typedef struct {
    u32         m_dwSSRC;    //SSRC
    BOOL32      m_bEnabled;  //�Ƿ�֧�ֶ�̬�������
    u64         m_qwID;      //ҵ���ID
    u32         m_dwGroup;   //������ID
    u32         m_dwBitrate; //��·����(bps)
} TBweReceiver; // ����ͨ��

//Frame Rcv CallBack Function
typedef   void (*PFRAMEPROC)(PFRAMEHDR pFrmHdr, u32 dwContext);
//RTP PACK Call back
typedef   void (*PRTPCALLBACK)(TRtpPack *pRtpPack, u32 dwContext);

enum RTCPSTATUS {
    RTCP_OFF          = 0,
    RTCP_COMPOUND     = 1,
    RTCP_NONCOMPOUND  = 2,
};

#define MAX_MAP_NUM 20
typedef struct tagMapSet {
	u8 m_byMapNum; //���MAX_MAP_NUM
	u8 m_abyMapType[MAX_MAP_NUM][2]; //[ ][0] for remote type, [ ][1] for real type
} TMapSet;

#ifndef MNET_SIZEOF_CRYPT_CFG_T
#define MNET_SIZEOF_CRYPT_CFG_T  256
#endif

typedef union {
    u8 data[MNET_SIZEOF_CRYPT_CFG_T];
    void* align;
} TMnetCryptCfg;

//������mnet_sec.h����һ��
typedef enum {
    MNET_CRYPT_DATA_NULL = 0,
    MNET_CRYPT_DATA_RTP,   //rtpͨ��
    MNET_CRYPT_DATA_RTCP,  //rtcpͨ��
    MNET_CRYPT_DATA_ALL,   //rtp&&rtcpͨ��������Կ
    MNET_CRYPT_DATA_MAX,
} TMnetCryptDataType;

//������mnet_sec.h����һ��
typedef enum {
    MNET_CRYPT_PKT_NULL = 0,
    MNET_CRYPT_PKT_H235,    //�ϵ�medianet��Ϊ������
    MNET_CRYPT_PKT_SRTP,    // srtp ���
    MNET_CRYPT_PKT_DTLS,
    MNET_CRYPT_PKT_MAX,
} TMnetCryptPktType;

//������mnet_sec.h����һ��
typedef enum {
    MNET_CRYPT_KEY_NULL = 0,
    MNET_CRYPT_KEY_STATIC,    //�ϵļ��� && srtp���ܶ�Ϊ������
    MNET_CRYPT_KEY_QUANTUM,   //���Ӽ���
    MNET_CRYPT_KEY_DTLS,
    MNET_CRYPT_KEY_MAX,
} TMnetCryptKeyType;

//������mnet_sec.h����һ��
typedef enum {
    MNET_CRYPT_ALGORITHM_NULL = 0,
    MNET_CRYPT_ALGORITHM_AES_CBC,
    MNET_CRYPT_ALGORITHM_AES_CM,
    MNET_CRYPT_ALGORITHM_AES_GCM,     //srtp cipher
    MNET_CRYPT_ALGORITHM_AES_ICM,     //srtp cipher
    MNET_CRYPT_ALGORITHM_SM4_CM,      //srtp cipher
    MNET_CRYPT_ALGORITHM_SM1_CM,      //srtp cipher
    MNET_CRYPT_ALGORITHM_HMAC_SHA1,   //srtp auth
    MNET_CRYPT_ALGORITHM_MAX,
} TMnetCryptAlgoType;

typedef enum {
    MNET_KEY_LEN_128 = 1, //128bit
    MNET_KEY_LEN_256,
} TMnetCrypKeyLen;

typedef enum {
    MNET_AUTH_TAG_LEN_0 = 1, //����֤
    MNET_AUTH_TAG_LEN_32,  //32bit
    MNET_AUTH_TAG_LEN_64,
    MNET_AUTH_TAG_LEN_80,
    MNET_AUTH_TAG_LEN_128,
} TMnetCryptTagLen;

/********************************************************************
 * ��������MnetCryptCfgInit
 *
 * ���ܣ���ʼ���������ýṹ��
 * default:������
 *
 *  srtp rtp policy support now
 *  sm1_cm_128_hmac_sha1_80/sm1_cm_128_hmac_sha1_null
 *  sm4_cm_128_hmac_sha1_80/sm4_cm_128_hmac_sha1_null
 *  aes_icm_128_hmac_sha1_80/aes_icm_128_hmac_sha1_32/aes_icm_128_hmac_sha1_null
 *  aes_icm_256_hmac_sha1_80/aes_icm_256_hmac_sha1_32/aes_icm_256_hmac_sha1_null
 *  aes_gcm_128_hmac_sha1_128/aes_gcm_128_hmac_sha1_64
 *  aes_gcm_256_hmac_sha1_128/aes_gcm_256_hmac_sha1_64
 *
 *  srtp rtcp policy support now
 *  sm1_cm_128_hmac_sha1_80
 *  sm4_cm_128_hmac_sha1_80
 *  aes_icm_128_hmac_sha1_80/aes_icm_128_hmac_sha1_32
 *  aes_icm_256_hmac_sha1_80/aes_icm_256_hmac_sha1_32
 *  aes_gcm_128_hmac_sha1_128/aes_gcm_128_hmac_sha1_64
 *  aes_gcm_256_hmac_sha1_128/aes_gcm_256_hmac_sha1_64
 * ����˵����
 * @param ptCfg        - ��Ҫ����ʼ�������ýṹ��
 * @param send         - �Ƿ��ͻ��ǽ���
 *
 * ����ֵ��
 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
 ********************************************************************/
MN_C_SYM BOOL32 MnetCryptCfgInit(TMnetCryptCfg* ptCfg, BOOL32 send);

/********************************************************************
 * ��������MnetCryptCfgSetCipherAlgorithm
 *
 * ���ܣ����ü����õļ����㷨
 *
 * ����˵����
 * @param ptCfg        - ��Ҫ�����õ����ýṹ��
 * @param tDataType  - �����ĸ�ͨ��
 * @param tAlgorithm - ���õļ����㷨
 *
 * ����ֵ��
 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
 ********************************************************************/
MN_C_SYM BOOL32 MnetCryptCfgSetCipherAlgorithm(TMnetCryptCfg* ptCfg,
                                          TMnetCryptDataType tDataType,
                                          TMnetCryptAlgoType tAlgorithm);

/********************************************************************
 * ��������MnetCryptCfgSetAuthAlgorithm
 *
 * ���ܣ�������֤�õļ����㷨
 *
 * ����˵����
 * @param ptCfg        - ��Ҫ�����õ����ýṹ��
 * @param tDataType  - �����ĸ�ͨ��
 * @param tAlgorithm - ���õļ����㷨
 *
 * ����ֵ��
 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
 ********************************************************************/
MN_C_SYM BOOL32 MnetCryptCfgSetAuthAlgorithm(TMnetCryptCfg* ptCfg,
                                          TMnetCryptDataType tDataType,
                                          TMnetCryptAlgoType tAlgorithm);

/********************************************************************
 * ��������MnetCryptCfgSetMasterKey
 *
 * ���ܣ�������Կ���ͺ���Կ,���ӿ�����srtp
 *
 * ����˵����
 * @param ptCfg        - ��Ҫ�����õ����ýṹ��
  * @param tDataType  - �����ĸ�ͨ��
 * @param tKeyType   - ���õ���Կ����
 * @param wkeySize   - ��Կ�ĳ���
 * @param bykey        - ��Կ
 * @parma tKeyLenAuch - ��֤��Կ�ĳ���
 * @param tKeyLenCipher - ������Կ�ĳ���
 *
 * ����ֵ��
 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
 ********************************************************************/
MN_C_SYM BOOL32 MnetCryptCfgSetMasterKey(TMnetCryptCfg* ptCfg,
                                  TMnetCryptDataType tDataType,
                                  TMnetCryptKeyType tKeyType,
                                  u16 wKeySize, u8* byKey,
                                  TMnetCrypKeyLen tKeyLenAuch,
                                  TMnetCrypKeyLen tKeyLenCipher);

/********************************************************************
 * ��������MnetCryptCfgSetCipherKey
 *
 * ���ܣ����ü����õ�ĳ��ͨ���ļ�����Կ����,����H235����,Ŀǰ��֧��rtp aes����
 *
 * ����˵����
 * @param ptCfg        - ��Ҫ�����õ����ýṹ��
 * @param tDataType  - �����ĸ�ͨ��
 * @param wkeySize   - ��Կ�ĳ���
 * @param bykey        - ��Կ
 *
 * ����ֵ��
 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
 ********************************************************************/
MN_C_SYM BOOL32 MnetCryptCfgSetCipherKey(TMnetCryptCfg* ptCfg,
                                  TMnetCryptDataType tDataType,
                                  u16 wKeySize, u8* byKey);

/********************************************************************
 * ��������MnetCryptCfgSetAuthKey
 *
 * ���ܣ����ü����õ�ĳ��ͨ������֤��Կ����,����H235,�ݲ�֧����֤
 *
 * ����˵����
 * @param ptCfg        - ��Ҫ�����õ����ýṹ��
 * @param tDataType  - �����ĸ�ͨ��
 * @param wkeySize   - ��Կ�ĳ���
 * @param bykey        - ��Կ
 *
 * ����ֵ��
 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
 ********************************************************************/
MN_C_SYM BOOL32 MnetCryptCfgSetAuthKey(TMnetCryptCfg* ptCfg,
                                  TMnetCryptDataType tDataType,
                                  u16 wKeySize, u8* byKey);

/********************************************************************
 * ��������MnetCryptCfgSetAuthTag
 *
 * ���ܣ����ü����õ�ĳ��ͨ������֤tag����,����srtp
 *
 * ����˵����
 * @param ptCfg        - ��Ҫ�����õ����ýṹ��
 * @param tDataType  - �����ĸ�ͨ��
 * @param tTagLen     - ����srtp rtp/rtcp ��֤tag����
 *
 * ����ֵ��
 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
 ********************************************************************/
MN_C_SYM BOOL32 MnetCryptCfgSetAuthTag(TMnetCryptCfg* ptCfg,
                                  TMnetCryptDataType tDataType,
                                  TMnetCryptTagLen tTagLen);

/********************************************************************
 * ��������MnetCryptCfgSetPkt
 *
 * ���ܣ�����ͨ����pkt����
 *
 * ����˵����
 * @param ptCfg        - ��Ҫ�����õ����ýṹ��
 * @param tDataType  - �����ĸ�ͨ��
 * @param tPktType  - ͨ����pkt����
 *
 * ����ֵ��
 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
 ********************************************************************/
MN_C_SYM BOOL32 MnetCryptCfgSetPkt(TMnetCryptCfg* ptCfg,
                                  TMnetCryptDataType tDataType,
                                  TMnetCryptPktType tPktType);

class MN_CPP_SYM CKdvMediaSnd
{
public:
	/********************************************************************
	 * ��������GetMediaSnd
	 *
	 * ���ܣ����һ�����Ͷ���
	 *
	 * ʵ��˵����
	 * �ӿ��಻�����ϲ�new CKdvMediaSnd��Ҫ��÷��Ͷ���ֻ��ͨ������ӿ�
	 *
	 *
	 * ����˵����
	 * @param
	 *
	 * ����ֵ��
	 * @return NULL:��ʾʧ��  CKdvMediaSnd *:��ʾ�ɹ�
	 ********************************************************************/
	static CKdvMediaSnd *GetMediaSnd();

	/********************************************************************
	 * ��������PutMediaSnd
	 *
	 * ���ܣ��ͷ�һ�����Ͷ���
	 *
	 * ʵ��˵����
	 * �ͷ���GetMeidaSnd��õĶ���
	 *
	 *
	 * ����˵����
	 * @param
	 *
	 * ����ֵ��
	 * @return
	 ********************************************************************/
	static void PutMediaSnd(CKdvMediaSnd *pCKdvMediaSnd);

	/********************************************************************
	 * ��������Create
	 *
	 * ���ܣ���������ģ��
	 *
	 * ʵ��˵����
	 *
	 * ����˵����
	 * @param dwMaxFrameSize    - ����֡�Ĵ�С
	 * @param dwNetBand         - ͨ������(bps)(��������,��SetSndInfo������)
	 * @param ucFramRate        - ���͵�֡��(fps)
	 * @param ucMediaType       - ���͵�ý������(��MEDIA_TYPE_H264)
	 * @param dwSSRC            - ���͵�SSRC
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 Create(u32 dwMaxFrameSize, u32 dwNetBand, u8 ucFrameRate, u8 ucMediaType, u32 dwSSRC = 0) = 0;

	/********************************************************************
	 * ��������SetNetSndParam
	 *
	 * ���ܣ��������緢�Ͳ���
	 *
	 * ʵ��˵����
	 * ���еײ��׽��ӵĴ������󶨶˿�,�Լ�����Ŀ���ַ���趨�ȶ���
	 * �������һ���ظ�����ֱ�ӷ��أ������һ����ɾ��֮ǰ���ã����´���
	 * NOTE:Ϊ�˷���ҵ�����õ�ַ�����˵�ַ��غ�(OSP_SET_NETADDR_ADDR)
	 *
	 * ����˵����
	 * @param tNetParam    - ���緢�Ͳ����������TNetParam
	 *                       �����ַ�Ͷ˿ھ�Ϊ�����ֽ���
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 SetNetSndParam(TMnetNetParam tNetParam) = 0;

	/********************************************************************
	 * ��������RemoveNetSndLocalParam
	 *
	 * ���ܣ��Ƴ����緢�ͱ��ص�ַ����
	 *
	 * ʵ��˵����
	 * ���еײ��׽��ӵ�ɾ�����ͷŶ˿ڵȶ���
	 *
	 * ����˵����
	 * @param
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 RemoveNetSndLocalParam() = 0;

	/********************************************************************
	 * ��������SetActivePT
	 *
	 * ���ܣ����������غ�ֵ�ͷ�������ӳ��
	 *
	 * ʵ��˵����
	 *
	 * ����˵����
	 * @param byLocalActivePT    - �����ı����غ�ֵ
	 * @param byRmtActivePT		 - ӳ������(Ĭ��MEDIA_TYPE_NULL����ӳ��)
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 SetActivePT(u8 byLocalActivePT, u8 byRmtActivePT = MEDIA_TYPE_NULL) = 0;

	/********************************************************************
	 * ��������SetEncryptKey
	 *
	 * ���ܣ���������
	 *
	 * ʵ��˵����!!!deprecated,����EnableCrypt
	 *
	 * ����˵����
	 * @param pszKeyBuf     - ��Կ��NULL��ʾ������
	 * @param wKeySize      - ��Կ�ĳ���
	 * @param byEncryptMode - �����㷨(AES or DES)
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 SetEncryptKey(s8 *pszKeyBuf, u16 wKeySize, u8 byEncryptMode = DES_ENCRYPT_MODE) = 0;

	/********************************************************************
	 * ��������ResetFrameId
	 *
	 * ���ܣ�����֡ID
	 *
	 * ʵ��˵����
	 *
	 * ����˵����
	 * @param
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 ResetFrameId() = 0;

	/********************************************************************
	 * ��������ResetSSRC
	 *
	 * ���ܣ�����ͬ��ԴSSRC
	 *
	 * ʵ��˵����
	 *
	 * ����˵����
	 * @param dwSSRC    - ͬ��Դ
	 * @param bForce      - �Ƿ�ǿ��ʹ��dwSSRC,ֻ���������ʶ�ͨ,��ssrcֻ����Ϊ����ż��
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 ResetSSRC(u32 dwSSRC = 0, BOOL32 bForce = FALSE) = 0;

	/********************************************************************
	 * ��������ResetRSFlag
	 *
	 * ���ܣ����÷��Ͷ��ش�����Ŀ���
	 *
	 * ʵ��˵����
	 * �򿪸ÿ��ط��Ͷ˻�Է��͹������ݽ��л��棬�Ա��յ��ش�����ʱ�ش�
	 * �رոÿ��ط��Ͷ˽�����Է��͹������ݻ��棬��ʱ��ʹ�յ��ش�����Ҳ
	 * �޷������ش���
	 *
	 * ����˵����
	 * @param bRepeatSnd    - �Ƿ���ش�����(Ĭ��ֵTRUE,��)
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 ResetRSFlag(BOOL32 bRepeatSnd = FALSE) = 0;

	/********************************************************************
	 * ��������EnableQos
	 *
	 * ���ܣ�qos����
	 *
	 * ����˵����
	 * @param bEnable    - �Ƿ���qos
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 EnableQos(BOOL32 bEnable) = 0;

	/********************************************************************
	 * ��������SetSndInfo
	 *
	 * ���ܣ�����ͨ������,����֡��,��������
	 *
	 * ����˵����
	 * @param dwNetBand    - ͨ������(bps)
	 * @param ucFrameRate  - ����֡��(fps)
            * @param dwBitRate    - ��������(bps)
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
     	 *
	 ********************************************************************/
	virtual u16 SetSndInfo(u32 dwNetBand, u8 ucFrameRate, u32 dwBitRate) = 0;

	/********************************************************************
	 * ��������GetTransportOverhead
	 *
	 * ���ܣ���ȡ���紫�俪���ٷֱ�
	 *
	 * ʵ��˵������ȡ���紫�俪��
	 *
	 * ����˵����

	 *@param byPercent �������紫�俪���ٷֱ�
	 *
	 *  ��:  byPercent����20�� ��ʾ���紫�俪��ռ��20%������ʱ���������������80%����
	 *
	 * ����ֵ��
	 * @return  ���紫�俪���ٷֱ�
	 ********************************************************************/
	virtual u16 GetTransportOverhead(u8 *byPercent) = 0;


	/********************************************************************
	 * ��������SetTOS
	 *
	 * ���ܣ�����TOS
	 *
	 * ʵ��˵�������÷���RTP��RTCP����TOS/DSCP
	 *
	 * ����˵����
	 * @param byTOS    - type of service (IP TOS�ֶε�ֵ)
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 SetTOS(u8 byTOS) = 0;

	/********************************************************************
	 * ��������GetTOS
	 *
	 * ���ܣ����TOSֵ
	 *
	 * ʵ��˵����
	 *
	 * ����˵����
	 *
	 * ����ֵ��
	 * @return TOSֵ
	 ********************************************************************/
	virtual u16 GetTOS(u8 *byTOS) = 0;

	/********************************************************************
	 * ��������SetMTU
	 *
	 * ���ܣ����÷��͵�MTU
	 *
	 * ʵ��˵����
	 * ����medianet���Ͱ������ֵ����������������MTU
	 *
	 * ����˵����
	 * @param wMTU    - ����RTP����С(Ĭ��ֵ1300byte)
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 SetMTU(u16 wMTU) = 0;

	/********************************************************************
	 * ������: EnableVad
	 *
	 * ����: ʹ��vad
	 * ʵ��˵��:
	 *
	 * ����˵��:
	 * @param bEnable -�Ƿ�ʹ��vad
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 *******************************************************************/
	virtual u16 EnableVad(BOOL32 bEnable = FALSE) = 0;

	/********************************************************************
	 * ��������Send
	 *
	 * ���ܣ�����һ֡����
	 *
	 * ʵ��˵����
	 *
	 * ����˵����
	 * @param pFrmHdr    - ֡�ṹ�壬�����PFRAMEHDR
	 * @param bValid     - �Ƿ���Ч(�ݲ�֧��)
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 Send(PFRAMEHDR pFrmHdr, BOOL32 bAvalid = TRUE) = 0;

	/********************************************************************
	 * ��������Send
	 *
	 * ���ܣ�����һ��rtp��
	 *
	 * ʵ��˵����
	 *
	 * ����˵����
	 * @param pRtpPack    - rtp���ṹ�������TRtpPack
	 * @param bTrans      - �Ƿ�ת��(�ݲ�֧��)
	 * @param bValid      - �Ƿ���Ч(�ݲ�֧��)
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 Send(TRtpPack *pRtpPack, BOOL32 bTrans = TRUE, BOOL32 bAvalid = TRUE) = 0;

	/********************************************************************
	 * ��������GetStatus
	 *
	 * ���ܣ���÷���״̬
	 *
	 * ʵ��˵����
	 *
	 * ����˵����
	 * @param tKdvSndStatus    - ״̬��Ϣ�������TKdvSndStatus
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 GetStatus(TKdvSndStatus &tKdvSndStatus) = 0;

	/********************************************************************
	 * ��������GetStatistics
	 *
	 * ���ܣ���÷���ͳ����Ϣ
	 *
	 * ʵ��˵����
	 *
	 * ����˵����
	 * @param tKdvSndStatistics    - ͳ����Ϣ�������TKdvSndStatistics
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 GetStatistics(TKdvSndStatistics &tKdvSndStatistics) = 0;

	/********************************************************************
	 * ��������GetAdvancedSndInfo
	 *
	 * ���ܣ���÷��Ͷ����õĲ���
	 *
	 * ʵ��˵����
	 *
	 * ����˵����
	 * @param tAdvancedSndInfo    - ���ø߼����Ͳ����������TAdvancedSndInfo
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 GetAdvancedSndInfo(TAdvancedSndInfo &tAdvancedSndInfo) = 0;

	/********************************************************************
	 * ��������GetNetSndParam
	 *
	 * ���ܣ���÷����������
	 *
	 * ʵ��˵����
	 *
	 * ����˵����
	 * @param ptNetSndParam    - ��������ṹ�壬�����TNetSndParam
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 GetNetSndParam(TMnetNetParam *ptNetSndParam) = 0;

	/********************************************************************
	 * ��������SetAudioResend
	 *
	 * ���ܣ�����Ƶ���ö౶����
	 *
	 * ʵ��˵����
	 * �µ�medianetֻ�����ϲ������Ƿ�౶���ͣ����ڷ��ͼ�����medianet����
	 * �����������
	 *
	 * ����˵����
	 * @param bReSend    - �Ƿ�������Ƶ�౶����(Ĭ��ֵTRUE,����)
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 SetAudioResend(BOOL32 bReSend) = 0;

	/********************************************************************
	 * ��������SetReverseG7221c
	 *
	 * ���ܣ�ʵ�ֶ�G7221.c�����ķ�ת
	 *
	 * ʵ��˵����
	 * ����������ʵ����żλ��ת
	 * before: 123456789
	 * after : 214365879
	 *
	 * ����˵����
	 * @param bReverse      - �Ƿ�ת(Ĭ��ֵFALSE,����ת)
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 SetReverseG7221c( BOOL32 bReverse ) = 0;

	/********************************************************************
	 * ��������ResetBwe
	 *
	 * ���ܣ�ʹ��/�رն�̬������
	 *
	 * ʵ��˵����
	 * ʹ�÷�������
	 * 1. ʹ�ܶ�̬������: ResetBwe
	 * 2. ���ڻ�ȡ��̬��������: GetBweStatus
	 * 3. ���ݴ������ñ�������(����/����
	 * 4. ���ݴ������ñ�������: SetSndInfo
	 *
	 * ����˵����
	 * @param bEnable          - ʹ��/�ر�
	 * @param dwMaxRate        - ����������(��λbps)
	 * @param dwMinRate        - ��С��������(��λbps)
	 * @param dwStartRate      - ��ʼ��������(��λbps)
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
    virtual u16 ResetBwe(BOOL32 bEnable, u32 dwMaxRate, u32 dwMinRate, u32 dwStartRate) = 0;

	/********************************************************************
	 * ��������GetBweStatus
	 *
	 * ���ܣ���ȡ��̬��������
	 *
	 * ʵ��˵����
     * �μ�ResetBwe
	 *
	 * ����˵����
	 * @param pNumber          - �����߸���(�������鳤��,���ʵ�ʽ����߸���)
	 * @param pReceivers       - ��������(ÿ�������ߵĶ�̬������Ϣ)
	 * @param pRevision        - ������汾(����ƥ�䲻ͬ����ͨ����Ľ�����)
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
     *         (����ERROR_ARRAY_TOO_SMALL��ʾ���������С,pNumber�а���ʵ�ʽ����߸���)
	 ********************************************************************/
    virtual u16 GetBweStatus(u32* pNumber, TBweReceiver* pReceivers, u32* pRevision) = 0;

	/********************************************************************
     * ��������SetId
     *
     * ���ܣ����÷��Ͷ˵�id
     *
     * ����˵����
     * @param EndPointId    - �ն˵�id, ��ǰ��֧��e164��
     * @param IdLen         - �ն�id�ĳ���
     * @param StreamId      - ��id
     *
     * ����ֵ��
     * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
     ********************************************************************/
    virtual u16 SetId(const char* EndPointId, u32 IdLen, u32 StreamId) = 0;

    /********************************************************************
     * ��������GetId
     *
     * ���ܣ���ȡ���Ͷ˵�id
     *
     * ����˵����
     * @param EndPointId    - �ն˵�id, ��ǰ��֧��e164��
     * @param IdLen         - �ն�id�ĳ���, ͬʱ��Ϊ��������
     * @param StreamId      - ��id
     *
     * ����ֵ��
     * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
     ********************************************************************/
    virtual u16 GetId(char* EndPointId, u32* IdLen, u32* StreamId) = 0;

	/********************************************************************
     * ��������EnableRtpExStrip
     *
     * ���ܣ��Ƿ����RTP��չͷ
     *
     * ����˵����
     * @param enable        - �Ƿ�����
     *
     * ����ֵ��
     * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
     ********************************************************************/
    virtual u16 EnableRtpExStrip(BOOL32 enable) = 0;

	/********************************************************************
	 * ��������EnableKeepAlive
	 *
	 * ���ܣ�1. ʹ�ܴ򶴹��ܲ��������ڴ򶴵����緢�Ͳ���
	 *       2. ֹͣ�򶴹��ܲ�ɾ����Ӧ�������
	 *
	 * ����˵����
	 * @param tKeepAliveParam    - ���緢�Ͳ����������TNetParam
	 *                             �����ַ�Ͷ˿ھ�Ϊ�����ֽ���
	 * @param enable             - �Ƿ�ʹ�ܴ򶴹���
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 EnableKeepAlive(BOOL32 enable, TMnetNetParam tKeepAliveParam) = 0;

	/********************************************************************
	 * ��������SetRtcpStatus
	 *
	 * ���ܣ�����RTCP״̬
	 *
	 * ����˵����
	 * @param status    - RTCP�������
	 *                     RTCP_OFF          = 0, ������RTCP
   	 *					   RTCP_COMPOUND     = 1, ����RTCP���ϰ�
     *					   RTCP_NONCOMPOUND  = 2, ������RTCP���ϰ�
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/

    virtual u16 SetRtcpStatus(RTCPSTATUS status) = 0;

	/********************************************************************
	 * ��������EnableFEC
	 *
	 * ���ܣ�ʹ��FEC
	 *
	 * ����˵����
	 * @param bEnableFec    - �Ƿ�����FEC
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual	u16 EnableFEC( BOOL32 bEnableFec ) = 0;

    /********************************************************************
	 * ��������EnableCrypt
	 *
	 * ���ܣ�ʹ�ܼ���
	 *
	 * ����˵����
	 * @param bEnableCrypt    - �Ƿ����ü���
	 * @param TMnetCryptCfg    - ����MnetCryptCfgInit ��ʼ���Ⱥ�������
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual	u16 EnableCrypt( BOOL32 bEnableCrypt, TMnetCryptCfg *ptMnetCryptCfg) = 0;
protected:
	CKdvMediaSnd() {}
    virtual ~CKdvMediaSnd() {}

private:
	CKdvMediaSnd(CKdvMediaSnd &);
	void operator=(const CKdvMediaSnd &);
};

class MN_CPP_SYM CKdvMediaRcv
{
public:
	/********************************************************************
	 * ��������GetMediaRcv
	 *
	 * ���ܣ����һ�����ն���
	 *
	 * ʵ��˵����
	 * �ӿ��಻�����ϲ�new CKdvMediaRcv��Ҫ��ý��ն���ֻ��ͨ������ӿ�
	 *
	 * ����˵����
	 * @param
	 *
	 * ����ֵ��
	 * @return NULL:��ʾʧ��  CKdvMediaRcv *:��ʾ�ɹ�
	 ********************************************************************/
	static CKdvMediaRcv *GetMediaRcv();

	/********************************************************************
	 * ��������PetMediaRcv
	 *
	 * ���ܣ��ͷ�һ�����ն���
	 *
	 * ʵ��˵����
	 * �ͷ�GetMediaRcv�ӿڻ�õĽ��ն���
	 *
	 *
	 * ����˵����
	 * @param
	 *
	 * ����ֵ��
	 * @return NULL:��ʾʧ��  CKdvMediaRcv *:��ʾ�ɹ�
	 ********************************************************************/
	static void PutMediaRcv(CKdvMediaRcv *pCKdvMediaRcv);

	/********************************************************************
	 * ��������Create
	 *
	 * ���ܣ���������ģ��
	 *
	 * ʵ��˵����
	 *
	 * ����˵����
	 * @param dwMaxFrameSize     - ������յ����֡��С
	 * @param pFrameCallBackProc - ֡�ص�����
	 * @param dwContext          - ֡�ص��������
	 * @param dwSSRC             - ����������SSRC
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 Create(u32 dwMaxFrameSize, PFRAMEPROC pFrameCallBackProc, u32 dwContext, u32 dwSSRC = 0) = 0;

	/********************************************************************
	 * ��������Create
	 *
	 * ���ܣ���������ģ��
	 *
	 * ʵ��˵����
	 *
	 * ����˵����
	 * @param dwMaxFrameSize     - ������յ����֡��С
	 * @param PRtpCallBackProc   - RTP���ص�����
	 * @param dwContext          - RTP���ص��������
	 * @param dwSSRC             - ����������SSRC
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/

	virtual u16 Create(u32 dwMaxFrameSize, PRTPCALLBACK PRtpCallBackProc, u32 dwContext, u32 dwSSRC = 0) = 0;

	/********************************************************************
	 * ��������SetNetRcvLocalParam
	 *
	 * ���ܣ����ý��յ�ַ����
	 *
	 * ʵ��˵����
	 * ���еײ��׽��ӵĴ������󶨶˿ڵȶ���
	 * ���������ͬ�ظ�����ֱ�ӷ��أ�������ͬ��ر�֮ǰ��socket���´���
	 * ����˿ڸ��ã������ṩԶ�˵�ַ�Ͷ˿ڣ��Ա�medianet���һص�
	 * ����˿ڲ����ã�Զ�˵�ַ�Ͷ˿ڿ�����0
	 * ע��Ŀǰ���յ�Զ�˵�ַĿǰֻ֧��һ��
	 * NOTE:Ϊ�˷���ҵ�����õ�ַ�����˵�ַ��غ�(OSP_SET_NETADDR_ADDR)
	 *
	 * ����˵����
	 * @param tNetParam    - ��������ṹ�壬�����TNetParam
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 SetNetRcvLocalParam(TMnetNetParam tNetParam) = 0;

	/********************************************************************
	 * ��������RemoveNetRcvLocalParam
	 *
	 * ���ܣ��Ƴ����յ�ַ����
	 *
	 * ʵ��˵����
	 * ���еײ��׽��ӵ�ɾ�����ͷŶ˿ڵȶ���
	 *
	 * ����˵����
	 * @param ptNetSndParam    - ��������ṹ�壬�����TNetSndParam
	 *                           �����ַ�Ͷ˿ھ�Ϊ�����ֽ���
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 RemoveNetRcvLocalParam() = 0;

	/********************************************************************
	 * ��������SetActivePT
	 *
	 * ���ܣ�(1)����һ������ӳ��
	 *	        (2)byRmtActivePT=MEDIA_TYPE_ANY����������Զ������ӳ����byRealPT
	 *	        (3)byRmtActivePT==byRealPT ���������ӳ�����ò����������غ�
	 *
	 * ʵ��˵����
	 * ������H264����������غ���105(���绪Ϊ)���������ǵ�H264��106��ʾ��
	 * ͨ��SetActivePT(105, 106)�Ϳ��԰�H264��֡�ص�
	 * SetActivePT(MEDIA_TYPE_ANY, 106) ����Զ��ʲôptֵ����H264��֡�ص�
	 *
	 * ����˵����
	 * @param byRmtActivePT    - Զ���������غ�ֵ
	 * @param byRealPT         - ����ʵ���غ�ֵ
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 SetActivePT(u8 byRmtActivePT, u8 byRealPT) = 0;

	/********************************************************************
	 * ��������SetActivePT
	 *
	 * ���ܣ���������������ӳ�伯��
	 *
	 * ʵ��˵����
	 * 		ӳ�伯��Ԫ�ظ���Ϊ0ʱ�������
	 *
	 * ����˵����
	 * @param  tMapSet -����ӳ�伯��
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 SetActivePT(TMapSet tMapSet) = 0;


	/********************************************************************
	 * ��������ResetRSFlag
	 *
	 * ���ܣ����ý��ն��ش�����Ŀ���
	 *
	 * ʵ��˵����
	 * ���ն˲�����ҵ�������ش�����ļ����ֻ���������Ƿ����ã����ڽ��ն���
	 * ���Ƿ����ش���������Ҫ���Ͷ�Ҳ���ش����ܴ򿪡�
	 *
	 * ����˵����
	 * @param bRepeatSnd    - �Ƿ�򿪽��ն��ش�������(Ĭ��ֵ��TRUE)
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 ResetRSFlag(BOOL32 bRepeatSnd = FALSE) = 0;

	/********************************************************************
	 * ��������ResetRtpCalllback
	 *
	 * ���ܣ�����RTP�ص�
	 *
	 * ʵ��˵����
	 *
	 * ����˵����
	 * @param pRtpCallBackProc    - �ص�����
	 * @param dwContext           - �ص����
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 ResetRtpCalllback(PRTPCALLBACK pRtpCallBackProc, u32 dwContext) = 0;

	/********************************************************************
	 * ��������SetDecryptKey
	 *
	 * ���ܣ���������
	 *
	 * ʵ��˵����!!!deprected,����EnableCrypt
	 *
	 * ����˵����
	 * @param pszKeyBuf     - ��Կ��NULL��ʾ������
	 * @param wKeySize      - ��Կ�ĳ���
	 * @param byEncryptMode - �����㷨(AES or DES)
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 SetDecryptKey(s8 *pszKeyBuf, u16 wKeySize, u8 byDecryptMode = DES_ENCRYPT_MODE) = 0;

	/********************************************************************
	 * ������: EnableVad
	 *
	 * ����: ʹ��vad
	 * ʵ��˵��:
	 *
	 * ����˵��:
	 * @param bEnable -�Ƿ�ʹ��vad
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 *******************************************************************/
	virtual u16 EnableVad(BOOL32 bEnable = FALSE) = 0;

	/********************************************************************
	 * ��������StartRcv
	 *
	 * ���ܣ���ʼ����
	 *
	 * ʵ��˵����
	 *
	 * ����˵����
	 * @param
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 StartRcv() = 0;

	/********************************************************************
	 * ��������StopRcv
	 *
	 * ���ܣ�ֹͣ����
	 *
	 * ʵ��˵����
	 *
	 * ����˵����
	 * @param
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 StopRcv() = 0;

	enum H264ProcessFlag {
		H264_DEL_SEI       = 0x1 << 0, //ɾ��H264SEI��Ϣ
		H264_DEL_MULTI_PPS = 0x1 << 1, //ɾ��H264����PPS��������һ��PPS
		H264_NALU_ALIGN    = 0x1 << 2, //H264 NALU�����ֽڶ���
	};
	/********************************************************************
	 * ��������SetH264Flag
	 *
	 * ���ܣ�����H264�ص�ǰ�Ƿ����־λ
	 *
	 * ʵ��˵����
	 * ����ɶ�һ�ο���������!!!
	 * ����ͬʱ�򿪹رն�����أ�֧�ֻ�����
	 *
	 * ����˵����
	 * @param wH264Flag    - �����־λ����enum H264ProcessFlag
	                         (Ĭ��ֵ0����������)
	 * @param bOpen        - TRUE:��ʾ�� FALSE:��ʾ�ر�
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 SetH264Flag(u16 wH264Flag, BOOL32 bOpen) = 0;

	/********************************************************************
	 * ��������GetH264Flag
	 *
	 * ���ܣ����H264�����־λ
	 *
	 * ʵ��˵����
	 *
	 * ����˵����
	 * @param
	 *
	 * ����ֵ��
	 * @return enum H264ProcessFlag
	 ********************************************************************/
	virtual u16 GetH264Flag() = 0;

	/********************************************************************
	 * ��������GetStatus
	 *
	 * ���ܣ����״̬��Ϣ
	 *
	 * ʵ��˵����
	 *
	 * ����˵����
	 * @param tKdvRcvStatus    - ״̬��Ϣ�������TKdvRcvStatus
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 GetStatus(TKdvRcvStatus &tKdvRcvStatus) = 0;

	/********************************************************************
	 * ��������GetStatistics
	 *
	 * ���ܣ����ͳ����Ϣ
	 *
	 * ʵ��˵����
	 *
	 * ����˵����
	 * @param tKdvRcvStatistics    - ͳ����Ϣ�������TKdvRcvStatistics
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 GetStatistics(TKdvRcvStatistics &tKdvRcvStatistics) = 0;

	/********************************************************************
	 * ��������GetAdvancedRcvInfo
	 *
	 * ���ܣ���ý��ն����õĲ���
	 *
	 * ʵ��˵����
	 *
	 * ����˵����
	 * @param tAdvancedRcvInfo    - ���ø߼����Ͳ����������TAdvancedRcvInfo
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 GetAdvancedRcvInfo(TAdvancedRcvInfo &tAdvancedRcvInfo) = 0;

	/********************************************************************
	 * ��������SetReverseG7221c
	 *
	 * ���ܣ�ʵ�ֶ�G7221.c�����ķ�ת
	 *
	 * ʵ��˵����
	 * ����������ʵ����żλ��ת
	 * before: 123456789
	 * after : 214365879
	 *
	 * ����˵����
	 * @param bReverse      - �Ƿ�ת(Ĭ��ֵΪFALSE������ת)
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 SetReverseG7221c(BOOL32 bReverse) = 0;

	enum H264BuildFrameFlag {
		H264_DEPENDON_MARKER = 0,         //��markerλ�ж�֡�߽�
		H264_DEPENDON_TIMESTAMP = 1,      //��ʱ����ж�֡�߽�
	};
	/********************************************************************
	 * ��������SetH264BuildFrameFlag
	 *
	 * ���ܣ�����H264��֡ʱ����ʲô�ж�֡�߽�
	 *
	 * ʵ��˵����
	 * NOTE:��ʱûʵ��
	 *
	 * ����˵����
	 * @param tFalg    - ��֡ʱ�ж���߽�ı�־(Ĭ��ֵΪH264_DEPENDON_TIMESTAMP)
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 SetH264BuildFrameFlag(H264BuildFrameFlag tFalg) = 0;

	/********************************************************************
	 * ��������SetH264HDFlag
	 *
	 * ���ܣ�����HD��־�����ڱ�־�ص���H264�Ƿ���HD
	 *
	 * HD �����ص�֡���ݽṹ����:
	 * ---------------------------------------------------------------------------
	 * | Len0 | Len1 | Len2 | ... | Len511 | NALU0 | NALU1 | NALU2 | ... | NALUx |
	 * ---------------------------------------------------------------------------
	 * ��HD�����ص�֡���ݽṹ����:
	 * ---------------------------------------------------------------------------
	 * | 0001 | NALU0 | 0001 | NALU2  | 0001| NALU3 | 0001| NALU4 |0001 | .......|
	 * ---------------------------------------------------------------------------
	 *
	 * ʵ��˵����
	 * NOTE:��ʱûʵ��
	 *
	 *
	 * ����˵����
	 * @param bHdFlag    - �����ص�ʱ�Ƿ񰴸���ṹ�ص�(Ĭ��ֵΪ0������HD�ص�)
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 SetH264HDFlag(BOOL32 bHdFlag) = 0;

	/********************************************************************
	 * ��������SetRtpPublicAddr
	 *
	 * ���ܣ����ñ�����rtp���ն˿ڶ�Ӧ�Ĺ�����ַ
	 *
	 * ʵ��˵����
	 * NOTE:��ʱûʵ��
	 * �ش���natʱ�����ñ�����rtp���ն˿ڶ�Ӧ�Ĺ�����ַ,
	 * Ŀ��Ϊʹ�ش�ʱ���ù㲥
	 *
	 * ����˵����
	 * @param dwRtpPublicIp    - ���ؽ���rtp��Ӧ�Ĺ���ip
	 * @param wRtpPublicPort   - ���ؽ���rtp��Ӧ�Ĺ���port
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 SetRtpPublicAddr(u32 dwRtpPublicIp, u16 wRtpPublicPort) = 0;

	/********************************************************************
	 * ��������SetMaxDelay
	 *
	 * ���ܣ������������ӳټ����Ų���
	 *
	 * ʵ��˵����
     * �����ӳ�:
	 *  ����+�����ӳ�,��λms,��Ϊsoftlimit,hardlimit��������
     *
     * ���Ų���:
     *  MAX_DELAY_QUALITY       - ��������(������softlimit,hardlimit)
     *  MAX_DELAY_SPEED         - �ٶ�����.����hardlimit(������softlimit)
     *  MAX_DELAY_BALANCE       - �����ٶ�ƽ��.����softlimit(������hardlimit)
     *
     * Ĭ�ϲ����������Ȳ���
     *
	 * ����˵����
	 * @param ucPolicy          - ���Ų���
	 * @param dwSoftlimit       - ������
	 * @param dwHardlimit       - Ӳ����
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 SetMaxDelay(u8 ucPolicy, u32 dwSoftlimit, u32 dwHardlimit) = 0;

	/********************************************************************
	 * ��������ResetBwe
	 *
	 * ���ܣ�ʹ��/�رն�̬������
	 *
	 * ʵ��˵����
	 *
	 * ����˵����
	 * @param bEnable          - ʹ��/�ر�
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
    virtual u16 ResetBwe(BOOL32 bEnable) = 0;

	/********************************************************************
     * ��������SetId
     *
     * ���ܣ����ý��ն˵�id
     *
     * ����˵����
     * @param EndPointId    - �ն˵�id, ��ǰ��֧��e164��
     * @param IdLen         - �ն�id�ĳ���
     * @param StreamId      - ��id
     *
     * ����ֵ��
     * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
     ********************************************************************/
    virtual u16 SetId(const char* EndPointId, u32 IdLen, u32 StreamId) = 0;

    /********************************************************************
     * ��������GetId
     *
     * ���ܣ���ȡ���ն˵�id
     *
     * ����˵����
     * @param EndPointId    - �ն˵�id, ��ǰ��֧��e164��
     * @param IdLen         - �ն�id�ĳ���
     * @param StreamId      - ��id
     *
     * ����ֵ��
     * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
     ********************************************************************/
    virtual u16 GetId(char* EndPointId, u32* IdLen, u32* StreamId) = 0;

	/********************************************************************
	 * ��������SetTOS
	 *
	 * ���ܣ�����TOS
	 *
	 * ʵ��˵�������ý��ն˷���RTCP����TOS/DSCP
	 *
	 * ����˵����
	 * @param byTOS    - type of service (IP TOS�ֶε�ֵ)
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 SetTOS(u8 byTOS) = 0;

	/********************************************************************
	 * ��������GetTOS
	 *
	 * ���ܣ����TOSֵ
	 *
	 * ʵ��˵����
	 *
	 * ����˵����
	 *
	 * ����ֵ��
	 * @return TOSֵ
	 ********************************************************************/
	virtual u16 GetTOS(u8 *byTOS) = 0;

	/********************************************************************
	 * ��������EnableKeepAlive
	 *
	 * ���ܣ�1. ʹ�ܴ򶴹��ܲ�������Ӧ�����緢�Ͳ���
	 *       2. ֹͣ�򶴹��ܲ�ɾ����Ӧ�������
	 *
	 * ����˵����
	 * @param tKeepAliveParam    - ���緢�Ͳ����������TNetParam
	 *                             �����ַ�Ͷ˿ھ�Ϊ�����ֽ���
	 * @param enable             - �Ƿ�ʹ�ܴ򶴹���
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 EnableKeepAlive(BOOL32 enable, TMnetNetParam tKeepAliveParam) = 0;

	/********************************************************************
	 * ��������SetRtcpStatus
	 *
	 * ���ܣ�����RTCP״̬
	 *
	 * ����˵����
	 * @param status    - RTCP�������
	 *                     RTCP_OFF          = 0, ������RTCP
   	 *					   RTCP_COMPOUND     = 1, ����RTCP���ϰ�
     *					   RTCP_NONCOMPOUND  = 2, ������RTCP���ϰ�
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual u16 SetRtcpStatus(RTCPSTATUS status) = 0;

	/********************************************************************
	 * ��������EnableFEC
	 *
	 * ���ܣ�ʹ��FEC
	 *
	 * ����˵����
	 * @param bEnableFec    - �Ƿ�����FEC
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual	u16 EnableFEC( BOOL32 bEnableFec ) = 0;

    /********************************************************************
	 * ��������EnableCrypt
	 *
	 * ���ܣ�ʹ�ܽ���
	 *
	 * ����˵����
	 * @param bEnableCrypt    - �Ƿ����ü���
	 * @param ptMnetCryptCfg    - ����MnetCryptCfgInit ��ʼ���Ⱥ�������
	 *
	 * ����ֵ��
	 * @return MEDIANET_NO_ERROR:��ʾ�ɹ� �����ʾʧ��
	 ********************************************************************/
	virtual	u16 EnableCrypt( BOOL32 bEnableCrypt, TMnetCryptCfg *ptMnetCryptCfg ) = 0;

protected:
	CKdvMediaRcv() {}
    virtual ~CKdvMediaRcv() {}

private:
	CKdvMediaRcv(CKdvMediaRcv &);
	void operator=(const CKdvMediaRcv &);
};

#endif // for _KDVMEDIANET_64_HEADER

#endif  //_KDVMEDIANET_0603_H_

