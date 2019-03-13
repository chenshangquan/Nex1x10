/*

Module Name:

    CDesktopCapture.h

Abstract:

    截屏处理，限制最大分辨率只能是1920*1080

Author:

Revision History:
V1.0.0.1_0218
主要修改：提升采样的线程的优先级
V1.0.0.1_0303
1 支持动态修改分辨率
2 修改计算机设置扩展屏时，导致花屏
V1.0.0.1_0310
1 增加检测弹出的Window Aero 提示，发送关闭窗口消息
2 
V1.0.0.1_0313
1  修改了release版本不能回调
2  修改了获取屏幕大小的处理，避免引起不能获取的处理
V1.0.0.1_0315
1  获取桌面分辨率不对的问题
V1.0.0.1_0323
1  多丢弃几帧保证上报的图像是正常的
V1.0.0.1_0328
1  长时间处理后，不能采集
V1.0.0.1_0413
1 增加了扩展屏的支持
2 丢弃帧数修改成1秒

V1.0.0.1_0425
1 修改停止后，切换屏幕，如果主副屏一致时，没有切换
2 修改分辨率后，会花屏的问题
V1.0.0.1_0428
1 修改停止后，切换屏幕，如果主副屏一致时，没有切换
V1.0.0.1_0502
1 修改帧率一直不能上升
V1.0.0.1_0507
1 在回调函数中，增加数据上报高度，宽度
V1.0.0.1_0717
1 改进在修改分辨率时，导致花屏的问题
V1.0.0.1_0802
1 改进在1366*768时，由于4字节对齐问题，会在bmp图片中每行增加了2字节的空，导致转换后，左侧会有阴影
V1.0.0.1_0825
1 在非basic方案下，修改成basic提高采样率
V1.0.0.1_0906
1 在非basic方案下，检测延时减少为2ms
V1.0.0.1_0915
1 CPU占用时，将定时器的时间延长下，减少cpu占用率
2 判读帧率不能超过120%
3 1366*768的分辨率时，重新定义算法，将左右各减少1个像素，为了解决色块的问题
V1.0.0.1_0919
1 1366*768的分辨率时，重新定义算法，增大分辨率
V1.0.0.1_0922
1 尝试修改不用winmm
V1.0.0.1_0926
1 尝试使用一个线程处理，将上报的线程删除
V1.0.0.1_0928
1 由于提供的方法跟原来的处理冲突导致不能控制帧率
2 修改了判断宽度被4整除时的函数处理存在问题，导致切换画面出现崩溃
   导致画面显示不正常
V1.0.0.1_0930
   1 上报线程修改成消息的机制触发，不通过循环的方式进行
V1.0.0.1_1010
   1 线程，修改成定时器
V1.0.0.1_1030
   1 修改了开始采集的处理，调整下位置，先初始化再启动采集
   2 停止采集时，延时缩短为200ms

V1.0.0.1.1107
   3 采集的帧率控制，处理成110%以内
V1.0.0.1_1125
   1 增加了空指针的判断，避免出现崩溃
V1.0.0.1_1206
   1 为了帧率，在不能被四整除的分辨率下，不调用拉伸，将画面居中处理
   2 为了居中后，鼠标绘制在区域外不能刷新的问题，增加了填充处理
 V1.0.0.1_1213
   1 页桌面大小限制在3840*2160
 V1.0.0.1_1214
   1 增加了日志处理，日志默认保存到当前目录下的log目录中
 V1.0.0.1_0305
   1 增加了日志文件大小判断
   2 增加错误日志
 V1.0.0.1_0314
   1 获取所有屏幕时，增加判断数量，不判断会导致数据错乱引起错误
 V1.0.0.1_0321
   1 增加日志，判断引起错误原因
   2 日志的文件大小判断在XP存在问题，换了函数处理
 V1.0.0.1_0418
   1 固定申请内存，不动态申请
   2 回调线程固定申请
--*/


#include "AVCollect.h"
#include "AutoLock.h"
#include "common.h"


#ifdef DESKTOPCAPTURE_EXPORTS
#define DESKTOPCAPTURE_API __declspec(dllexport)
#else
#define DESKTOPCAPTURE_API __declspec(dllimport)
#endif


#define VEDIO_VERSION_DESC "V1.0.0.1_0419"    //版本号，版本生成时间
#define VEDIO_VERSION_COMPILE   "2018-4-19 15:10:12"    //版本号，版本生成时间

#define SCREEN_MIN_LOST   8

void GetAllDisplay();

typedef HRESULT(WINAPI * fpDwmEnableComposition)(UINT);
typedef HRESULT(WINAPI * fpIsCompositionEnabled)(BOOL*);


/**
 * Rational number
 */
typedef struct AVRational{
    int num; ///<  帧率
    int den; ///< 间隔时间 
} AVRational;


/** 
    * GDI Device 
    */  
struct gdigrab {  
    int        frame_size;  /**< 帧大小*/  
    int        header_size; /**< DIB头 */  
    int64_t    time_frame;  /**< 时间 */  
	int        av_framerate;  //zz
	int64_t    last_frame;  /**< zz laste time */
      
    int        draw_mouse;  /**<鼠标绘制 */  
    int        show_region; /**< 绘制边框 */  
    AVRational framerate;   /**< 帧率 */  
    int        width;       /**< 宽 */  
    int        height;      /**< 高 */  
    int        offset_x;    /**<偏移 */  
    int        offset_y;    /**< 偏移y */  
      
    HWND       hwnd;        /**< 截屏窗口 */  
    HDC        source_hdc;  /**< 原始hdc */  
    HDC        dest_hdc;    /**< 目标 DC */  
    BITMAPINFO bmi;         /**< DIB 格式 */  
    HBITMAP    hbmp;        /**< BMP 句柄*/  
    void      *buffer;      /**< 图像数据 */  
    RECT       clip_rect;   /**< 截屏范围 */  
      
    HWND       region_hwnd; /**< 边框窗口句柄 */  

	int        nAllDelay;   //时延
	int        nFrameCount; //帧总数
      
    int cursor_error_printed;  
};  


/**
 * 字节数据.
 
 */
typedef struct AVIOContext {
    unsigned char *buffer;  /**< 数据. */
    int buffer_size;        /**< 数据大小 */
    unsigned char *buf_ptr; /**< 位置指针 */
    unsigned char *buf_end; /**< 数据结束指针. */
    void *opaque;           /**< 操作指针. */
    int (*read_packet)(void *opaque, uint8_t *buf, int buf_size);
    int (*write_packet)(void *opaque, uint8_t *buf, int buf_size);
    int64_t (*seek)(void *opaque, int64_t offset, int whence);
    int64_t pos;            /**< 当前位置 */
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
     *原始缓存大小
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
    uint8_t *data; /**< 数据缓存 */
    int      size; /**< 大小 */

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
	
	/*截屏处理
	******/
	int CaptureScreen();
	/*初始化数据
	******/
	void InitAll(bool bjt);
	/*建立
	******/
	int Create();
	/*回调处理
	******/
	void CallbackToUI();
	/*调整分辨率
	******/
	int ResizeDestop();
	/*判断截屏的标志
	******/
	bool m_bIsStart;

	/*判断调整分辨率结束的标志
	******/
	bool m_bIsEndChange;

	int m_nLostCount;

	/*是否已经初始化
	*****/
	bool m_bIsInit;

	int m_nRGBtoYUVWidth;
	int m_nRGBtoYUVHeight;

	DWORD m_dwThreadId;

private:
	PAVCALLBACK      m_pVedioNetCB; //返回YUV数据
	/*附加参数
	******/
	void* m_dwContext;

	CSimpleLock			m_csDB;

	int m_CallbackType;

	bool CpTheCaptureMemory();

	HANDLE m_handleBack;
	HANDLE m_handleCapture;

	TImageRGBtoYUVParam m_tImageRGBtoYUV;	//结构参数

	bool JudgeIsWin7Vista();
	bool InvalidAero();

	int InitConstData();
public:
	/*开始设置视频回调
	******/
	bool SetVedioCallBack(PAVCALLBACK pVedioCallBack,void* dwContext);
	/*设置采集帧率
	******/
	void SetFrameRate(int nRate);
	/*退出后清理现场
	******/
	void Destroy();
	/*停止视频采集
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

