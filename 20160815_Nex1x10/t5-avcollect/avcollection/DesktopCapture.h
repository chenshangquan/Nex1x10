/*

Module Name:

    CDesktopCapture.h

Abstract:

    ���������������ֱ���ֻ����1920*1080

Author:

Revision History:
V1.0.0.1_0218
��Ҫ�޸ģ������������̵߳����ȼ�
V1.0.0.1_0303
1 ֧�ֶ�̬�޸ķֱ���
2 �޸ļ����������չ��ʱ�����»���
V1.0.0.1_0310
1 ���Ӽ�ⵯ����Window Aero ��ʾ�����͹رմ�����Ϣ
2 
V1.0.0.1_0313
1  �޸���release�汾���ܻص�
2  �޸��˻�ȡ��Ļ��С�Ĵ������������ܻ�ȡ�Ĵ���
V1.0.0.1_0315
1  ��ȡ����ֱ��ʲ��Ե�����
V1.0.0.1_0323
1  �ඪ����֡��֤�ϱ���ͼ����������
V1.0.0.1_0328
1  ��ʱ�䴦��󣬲��ܲɼ�
V1.0.0.1_0413
1 ��������չ����֧��
2 ����֡���޸ĳ�1��

V1.0.0.1_0425
1 �޸�ֹͣ���л���Ļ�����������һ��ʱ��û���л�
2 �޸ķֱ��ʺ󣬻Ứ��������
V1.0.0.1_0428
1 �޸�ֹͣ���л���Ļ�����������һ��ʱ��û���л�
V1.0.0.1_0502
1 �޸�֡��һֱ��������
V1.0.0.1_0507
1 �ڻص������У����������ϱ��߶ȣ����
V1.0.0.1_0717
1 �Ľ����޸ķֱ���ʱ�����»���������
V1.0.0.1_0802
1 �Ľ���1366*768ʱ������4�ֽڶ������⣬����bmpͼƬ��ÿ��������2�ֽڵĿգ�����ת������������Ӱ
V1.0.0.1_0825
1 �ڷ�basic�����£��޸ĳ�basic��߲�����
V1.0.0.1_0906
1 �ڷ�basic�����£������ʱ����Ϊ2ms
V1.0.0.1_0915
1 CPUռ��ʱ������ʱ����ʱ���ӳ��£�����cpuռ����
2 �ж�֡�ʲ��ܳ���120%
3 1366*768�ķֱ���ʱ�����¶����㷨�������Ҹ�����1�����أ�Ϊ�˽��ɫ�������
V1.0.0.1_0919
1 1366*768�ķֱ���ʱ�����¶����㷨������ֱ���
V1.0.0.1_0922
1 �����޸Ĳ���winmm
V1.0.0.1_0926
1 ����ʹ��һ���̴߳������ϱ����߳�ɾ��
V1.0.0.1_0928
1 �����ṩ�ķ�����ԭ���Ĵ����ͻ���²��ܿ���֡��
2 �޸����жϿ�ȱ�4����ʱ�ĺ�������������⣬�����л�������ֱ���
   ���»�����ʾ������
V1.0.0.1_0930
   1 �ϱ��߳��޸ĳ���Ϣ�Ļ��ƴ�������ͨ��ѭ���ķ�ʽ����
V1.0.0.1_1010
   1 �̣߳��޸ĳɶ�ʱ��
V1.0.0.1_1030
   1 �޸��˿�ʼ�ɼ��Ĵ���������λ�ã��ȳ�ʼ���������ɼ�
   2 ֹͣ�ɼ�ʱ����ʱ����Ϊ200ms

V1.0.0.1.1107
   3 �ɼ���֡�ʿ��ƣ������110%����
V1.0.0.1_1125
   1 �����˿�ָ����жϣ�������ֱ���
V1.0.0.1_1206
   1 Ϊ��֡�ʣ��ڲ��ܱ��������ķֱ����£����������죬��������д���
   2 Ϊ�˾��к��������������ⲻ��ˢ�µ����⣬��������䴦��
 V1.0.0.1_1213
   1 ҳ�����С������3840*2160
 V1.0.0.1_1214
   1 ��������־������־Ĭ�ϱ��浽��ǰĿ¼�µ�logĿ¼��
 V1.0.0.1_0305
   1 ��������־�ļ���С�ж�
   2 ���Ӵ�����־
 V1.0.0.1_0314
   1 ��ȡ������Ļʱ�������ж����������жϻᵼ�����ݴ����������
 V1.0.0.1_0321
   1 ������־���ж��������ԭ��
   2 ��־���ļ���С�ж���XP�������⣬���˺�������
 V1.0.0.1_0418
   1 �̶������ڴ棬����̬����
   2 �ص��̶̹߳�����
--*/


#include "AVCollect.h"
#include "AutoLock.h"
#include "common.h"


#ifdef DESKTOPCAPTURE_EXPORTS
#define DESKTOPCAPTURE_API __declspec(dllexport)
#else
#define DESKTOPCAPTURE_API __declspec(dllimport)
#endif


#define VEDIO_VERSION_DESC "V1.0.0.1_0419"    //�汾�ţ��汾����ʱ��
#define VEDIO_VERSION_COMPILE   "2018-4-19 15:10:12"    //�汾�ţ��汾����ʱ��

#define SCREEN_MIN_LOST   8

void GetAllDisplay();

typedef HRESULT(WINAPI * fpDwmEnableComposition)(UINT);
typedef HRESULT(WINAPI * fpIsCompositionEnabled)(BOOL*);


/**
 * Rational number
 */
typedef struct AVRational{
    int num; ///<  ֡��
    int den; ///< ���ʱ�� 
} AVRational;


/** 
    * GDI Device 
    */  
struct gdigrab {  
    int        frame_size;  /**< ֡��С*/  
    int        header_size; /**< DIBͷ */  
    int64_t    time_frame;  /**< ʱ�� */  
	int        av_framerate;  //zz
	int64_t    last_frame;  /**< zz laste time */
      
    int        draw_mouse;  /**<������ */  
    int        show_region; /**< ���Ʊ߿� */  
    AVRational framerate;   /**< ֡�� */  
    int        width;       /**< �� */  
    int        height;      /**< �� */  
    int        offset_x;    /**<ƫ�� */  
    int        offset_y;    /**< ƫ��y */  
      
    HWND       hwnd;        /**< �������� */  
    HDC        source_hdc;  /**< ԭʼhdc */  
    HDC        dest_hdc;    /**< Ŀ�� DC */  
    BITMAPINFO bmi;         /**< DIB ��ʽ */  
    HBITMAP    hbmp;        /**< BMP ���*/  
    void      *buffer;      /**< ͼ������ */  
    RECT       clip_rect;   /**< ������Χ */  
      
    HWND       region_hwnd; /**< �߿򴰿ھ�� */  

	int        nAllDelay;   //ʱ��
	int        nFrameCount; //֡����
      
    int cursor_error_printed;  
};  


/**
 * �ֽ�����.
 
 */
typedef struct AVIOContext {
    unsigned char *buffer;  /**< ����. */
    int buffer_size;        /**< ���ݴ�С */
    unsigned char *buf_ptr; /**< λ��ָ�� */
    unsigned char *buf_end; /**< ���ݽ���ָ��. */
    void *opaque;           /**< ����ָ��. */
    int (*read_packet)(void *opaque, uint8_t *buf, int buf_size);
    int (*write_packet)(void *opaque, uint8_t *buf, int buf_size);
    int64_t (*seek)(void *opaque, int64_t offset, int whence);
    int64_t pos;            /**< ��ǰλ�� */
    int must_flush;         
    int eof_reached;        
    int write_flag;        
    int max_packet_size;
    unsigned long checksum;
    unsigned char *checksum_ptr;
    unsigned long (*update_checksum)(unsigned long checksum, const uint8_t *buf, unsigned int size);
    int error;              /**< contains the error code or 0 if no error happened */
    
	int seekable;

    
    int64_t maxsize;

    int direct;

  
    int64_t bytes_read;

  
    int seek_count;

   
    int writeout_count;

    /**
     *ԭʼ�����С
     */
    int orig_buffer_size;

    int short_seek_threshold;

    /**
     * ',' separated list of allowed protocols.
     */
    const char *protocol_whitelist;

    /**
     * ',' separated list of disallowed protocols.
     */
    const char *protocol_blacklist;


    int ignore_boundary_point;

   int64_t last_time;
} AVIOContext;

typedef struct AVPacketSideData {
    uint8_t *data;
    int      size;
    enum AVPacketSideDataType type;
} AVPacketSideData;

struct AVBuffer {
    uint8_t *data; /**< ���ݻ��� */
    int      size; /**< ��С */

    /**
     *  number of existing AVBufferRef instances referring to this buffer
     */
    volatile int refcount;

    /**
     * a callback for freeing the data
     */
    void (*free)(void *opaque, uint8_t *data);

    /**
     * an opaque pointer, to be used by the freeing callback
     */
    void *opaque;

    /**
     * A combination of BUFFER_FLAG_*
     */
    int flags;
};

/**
 * A reference to a data buffer.
 */
typedef struct AVBufferRef {
    AVBuffer *buffer;

    /**
     * The data buffer. It is considered writable if and only if
    */
    uint8_t *data;
    /**
     * Size of data in bytes.
     */
    int      size;
} AVBufferRef;


/**
 * This structure stores compressed data. It is typically exported by demuxers
 * and then passed as input to decoders, or received as output from encoders and
 * then passed to muxers.
 *
 */
typedef struct AVPacket {
    /**
     * A reference to the reference-counted buffer where the packet data is
     * stored.
     * May be NULL, then the packet data is not reference-counted.
     */
    AVBufferRef *buf;
    /**
     * Presentation timestamp in AVStream->time_base units; 
     */
    int64_t pts;
    /**
     * Decompression timestamp in AVStream->time_base units; 
     */
    int64_t dts;
    uint8_t *data;
    int   size;
    int   stream_index;
    /**
     * A combination of AV_PKT_FLAG values
     */
    int   flags;
    /**
     * Additional packet data that can be provided by the container.
     * Packet can contain several types of side information.
     */
  

    /**
     * Duration of this packet in AVStream->time_base units, 0 if unknown.
     * Equals next_pts - this_pts in presentation order.
     */
    int64_t duration;

    int64_t pos;                            ///< byte position in stream, -1 if unknown
} AVPacket;

/**
 * Format I/O context.
 */
typedef struct AVFormatContext {
    /**
     * A class for logging and @ref avoptions. Set by avformat_alloc_context().
     * Exports (de)muxer private options if they exist.
     */
    
    /**
     * The input container format.
     *
     * Demuxing only, set by avformat_open_input().
     */
    struct AVInputFormat *iformat;

  
    /**
     * Format private data. This is an AVOptions-enabled struct
     * if and only if iformat/oformat.priv_class is not NULL.
     */
    void *priv_data;

 
    /**
     * input or output filename
     *
     * - demuxing: set by avformat_open_input()
     * - muxing: may be set by the caller before avformat_write_header()
     */
    char filename[1024];

   
   


    unsigned int packet_size;
 
    /**
     * Flags modifying the (de)muxer behaviour. A combination of AVFMT_FLAG_*.
     * Set by the user before avformat_open_input() / avformat_write_header().
     */
    int flags;
#define AVFMT_FLAG_GENPTS       0x0001 ///< Generate missing pts even if it requires parsing future frames.
#define AVFMT_FLAG_IGNIDX       0x0002 ///< Ignore index.
#define AVFMT_FLAG_NONBLOCK     0x0004 ///< Do not block when reading packets from input.
#define AVFMT_FLAG_IGNDTS       0x0008 ///< Ignore DTS on frames that contain both DTS & PTS
#define AVFMT_FLAG_NOFILLIN     0x0010 ///< Do not infer any values from other values, just return what is stored in the container
#define AVFMT_FLAG_NOPARSE      0x0020 ///< Do not use AVParsers, you also must set AVFMT_FLAG_NOFILLIN as the fillin code works on frames and no parsing -> no frames. Also seeking to frames can not work if parsing to find frame boundaries has been disabled
#define AVFMT_FLAG_NOBUFFER     0x0040 ///< Do not buffer frames when possible
#define AVFMT_FLAG_CUSTOM_IO    0x0080 ///< The caller has supplied a custom AVIOContext, don't avio_close() it.
#define AVFMT_FLAG_DISCARD_CORRUPT  0x0100 ///< Discard frames marked corrupted
#define AVFMT_FLAG_FLUSH_PACKETS    0x0200 ///< Flush the AVIOContext every packet.
/**
 * When muxing, try to avoid writing any random/volatile data to the output.
 * This includes any random IDs, real-time timestamps/dates, muxer version, etc.
 *
 * This flag is mainly intended for testing.
 */
#define AVFMT_FLAG_BITEXACT         0x0400
#define AVFMT_FLAG_MP4A_LATM    0x8000 ///< Enable RTP MP4A-LATM payload
#define AVFMT_FLAG_SORT_DTS    0x10000 ///< try to interleave outputted packets by dts (using this flag can slow demuxing down)
#define AVFMT_FLAG_PRIV_OPT    0x20000 ///< Enable use of private options by delaying codec open (this could be made default once all code is converted)
#define AVFMT_FLAG_KEEP_SIDE_DATA 0x40000 ///< Don't merge side data but keep it separate.
#define AVFMT_FLAG_FAST_SEEK   0x80000 ///< Enable fast, but inaccurate seeks for some formats
#define AVFMT_FLAG_SHORTEST   0x100000 ///< Stop muxing when the shortest stream stops.
#define AVFMT_FLAG_AUTO_BSF   0x200000 ///< Wait for packet data before writing a header, and add bitstream filters as requested by the muxer

  
   
   
   
  
    /**
     * Flags to enable debugging.
     */
    int debug;
#define FF_FDEBUG_TS        0x0001

    /**
     * Maximum buffering duration for interleaving.
     *
     * Muxing only, set by the caller before avformat_write_header().
     */
    int64_t max_interleave_delta;

    /**
     * Allow non-standard and experimental extension
     * @see AVCodecContext.strict_std_compliance
     */
    int strict_std_compliance;

    /**
     * Flags for the user to detect events happening on the file. Flags must
     * be cleared by the user once the event has been handled.
     * A combination of AVFMT_EVENT_FLAG_*.
     */
    int event_flags;
#define AVFMT_EVENT_FLAG_METADATA_UPDATED 0x0001 ///< The call resulted in updated metadata.

    /**
     * Maximum number of packets to read while waiting for the first timestamp.
     * Decoding only.
     */
    int max_ts_probe;

    /**
     * Transport stream id.
     * This will be moved into demuxer private options. Thus no API/ABI compatibility
     */
    int ts_id;
	 
 

    /**
     * format probing score.
     */
    int probe_score;


  
   

} AVFormatContext;


class  CDesktopCapture {
public:
	CDesktopCapture(void);
	~CDesktopCapture();
	// TODO: add your methods here.
	
	/*��������
	******/
	int CaptureScreen();
	/*��ʼ������
	******/
	void InitAll(bool bjt);
	/*����
	******/
	int Create();
	/*�ص�����
	******/
	void CallbackToUI();
	/*�����ֱ���
	******/
	int ResizeDestop();
	/*�жϽ����ı�־
	******/
	bool m_bIsStart;

	/*�жϵ����ֱ��ʽ����ı�־
	******/
	bool m_bIsEndChange;

	int m_nLostCount;

	/*�Ƿ��Ѿ���ʼ��
	*****/
	bool m_bIsInit;

	int m_nRGBtoYUVWidth;
	int m_nRGBtoYUVHeight;

	DWORD m_dwThreadId;

private:
	PAVCALLBACK      m_pVedioNetCB; //����YUV����
	/*���Ӳ���
	******/
	void* m_dwContext;

	CSimpleLock			m_csDB;

	int m_CallbackType;

	bool CpTheCaptureMemory();

	HANDLE m_handleBack;
	HANDLE m_handleCapture;

	TImageRGBtoYUVParam m_tImageRGBtoYUV;	//�ṹ����

	bool JudgeIsWin7Vista();
	bool InvalidAero();

	int InitConstData();
public:
	/*��ʼ������Ƶ�ص�
	******/
	bool SetVedioCallBack(PAVCALLBACK pVedioCallBack,void* dwContext);
	/*���òɼ�֡��
	******/
	void SetFrameRate(int nRate);
	/*�˳��������ֳ�
	******/
	void Destroy();
	/*ֹͣ��Ƶ�ɼ�
	******/
	void Stop();

	//TDisplayInfo g_tdispInfo;
	

	int GetDisplayInfo(TMonitorInfo*tMonitor);

	bool SelectCaptureScreen(int nNum);

	bool FindAeroTipWindow();

	bool JudgeScreenChange();

	bool GetIsRunning();

	bool IsAeroEnabled();
};

extern DESKTOPCAPTURE_API int nDesktopCapture;

DESKTOPCAPTURE_API int fnDesktopCapture(void);

