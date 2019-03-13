/*

Module Name:

    common.h

Abstract:

    定义公共常量.

Author:

Revision History:

--*/

#ifndef _COMMON_H_
#define _COMMON_H_
#include<windows.h>
#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

#define AV_NOPTS_VALUE          ((int64_t)UINT64_C(0x8000000000000000))
#define AV_INPUT_BUFFER_PADDING_SIZE 32
#define BUFFER_FLAG_READONLY      (1 << 0)
#define AV_BUFFER_FLAG_READONLY (1 << 0)
#define BUFFER_FLAG_REALLOCATABLE (1 << 1)

#define MIN_CAPTURE_TIMER  20 
#define VIDEO_SUCCESS   0

	
#define SCREEN_MAX_NUM   2

#define uint8_t		unsigned char

#define l32         int
#define  YUV420     420    //分三个平面，Y平面，U平面，V平面，其中U平面和V平面均为Y平面的1/4  Y0 Y1 Y2 Y3.. U0 U1.. V0 V1..


	//图像缩放输出参数
typedef struct
{
	int nDeviceCount;             //数量
    DISPLAY_DEVICE aryddDisplay[SCREEN_MAX_NUM];     //显示器信息
    DEVMODE        arydmDevMode[SCREEN_MAX_NUM];     //显示参数 
	
    int u32Reserved;
}TDisplayInfo;


//rgb类型定义
typedef enum
{
	RGB1   = 1,
		RGB4   = 4,
		RGB8   = 8,
		RGB565 = 16,
		RGB555 = 15,
		RGB24  = 24,
		RGB32  = 32 //每个数据单元所占用的实际大小
}RGBTYPE_t;

//源图像的结构信息
typedef struct
{
	l32 l32SrcWidth;     //源图像的宽度
	l32 l32SrcHeight;    //源图像的高度
	l32 l32SrcYUVType;	 //源图像的图像类型，为YUV420或者YUV422
	l32 l32SrcInterlace; //源图像的帧场类型
	
	l32 l32SrcTopCutLine;     //上面的裁剪的行数，应为2的倍数
	l32 l32SrcBottomCutLine;  //下面的裁剪的行数，应为2的倍数
	l32 l32SrcLeftCutPoint;   //左边的裁剪的点数，应为2的倍数
	l32 l32SrcRightCutPoint;  //右边的裁剪的点数，应为2的倍数
	
	int u32Reserved;
}TSrcInfo;

//目的图像的结构参数
typedef struct
{
	l32 l32DstWidth;        //目的图像的宽度
	l32 l32DstHeight;		//目的图像的高度
	l32 l32DstYUVType;		//目的图像的图像类型，为YUV420或者YUV422
	l32 l32DstInterlace;	//目的图像的帧场类型
	
	l32 l32DstTopCutLine;     //上面的裁剪的行数，应为2的倍数
	l32 l32DstBottomCutLine;  //下面的裁剪的行数，应为2的倍数
	l32 l32DstLeftCutPoint;   //左边的裁剪的点数，应为2的倍数
	l32 l32DstRightCutPoint;  //右边的裁剪的点数，应为2的倍数
	
	l32 l32TopFillLine;     //上面的添加的颜色行数，应为2的倍数
	l32 l32BottomFillLine;  //下面的添加的颜色行数，应为2的倍数
	l32 l32LeftFillPoint;   //左边的添加的颜色点数，应为2的倍数
	l32 l32RightFillPoint;  //右边的添加的颜色点数，应为2的倍数
	
	l32 l32YColor;
	l32 l32UColor;
	l32 l32VColor;          //填充的边缘的颜色，目前黑色为Y:0x01,UV:0x80,绿色是全零，也可以考虑设置成RGB三个参数
	
	int u32Reserved;
}TDstInfo;

typedef struct
{
	TSrcInfo tSrcInfo;   //源图像的相关信息
	
	TDstInfo tDstInfo;   //目的图像的相关信息
	
    int u32Reserved;
}TImageResizerParam;

//声明图像处理类型
typedef enum
{
    IMG_YUV422_TO_YUV420 = 1, //图像YUV422转为图像YUV420
		IMG_YUV420_TO_YUV422,     //图像YUV420转为图像YUV422
		IMG_YUV420_TO_RGB,        //图像YUV420转为RGB图像
		IMG_YUV422_SPLIT,         //图像YUV422拆分为4路YUV420图像
		IMG_ZOOM,                 //图像YUV420的缩小、放大
		IMG_MERGE,                //图像YUV420的画面合成
		IMG_BMPTOYUVALPHA,        //BMP图像转为YUV图像并生成Alpha通道
		IMG_LOGO,                 //加台标
		IMG_BANNER,               //加横幅
		IMG_BANNER_LOGO,          //滚动横幅
		IMG_GENERATE_IMAGE,       //图像生成
		IMG_MOSAIC,               //加马赛克
		IMG_PN_CHANGE,            //图像P制和N制转换
		IMG_ADD_IMAGE,            //画中画
		IMG_YUV422_VGA_ZOOM,      //VGA的YUV422图像缩放
		IMG_ADAPT_16vs9,          //图像适配成16vs9
		IMG_IMGUNIT,              //图像库版本信息类型
		IMG_FILTER_OSD,           //临时增加滤波OSD的类型
		IMG_MULTI_DEC,            //多路解码
		IMG_APT_ZOOM_MOD,         //根据上层设置参数缩放图像并加黑边
		IMG_MERGE_ZOOM,           //图像缩放并画面合成
		IMG_MULTI_DEC_NEW,        //新的多路解码
		IMG_YUV422_ZOOM,          //YUV422图像缩放
		IMG_RESIZER,              //resizer缩放模块
		IMG_MULTI_ENC,            //多路编码
		IMG_RGB_ZOOM,             //RBG565缩放模块
		IMG_RENOVATION,           //图像刷新模块
		IMG_MOTION_DETECT_GM8180, //GM8180芯片运动侦测模块
		IMG_GM8180_TO_YUV420,     //GM8180与YUV420之间的互换
		IMG_COMMON_ADDLOGO,       //GM8180底图上加LOGO
		IMG_GM8180ADDMOSAIC,      //GM8180底图上加MOSAIC
		IMG_DEINTERLACE,          //Deinterlace处理
		IMG_FILTER,               //图像滤波模块
		IMG_DUAL_ENC,             //双流编码模块（同源）
		IMG_SHARP,                //图像锐化模块
		IMG_RGBTOYUV,             //RGB转YUV420模块
		IMG_TEMPORAL_FILTER,      //图像时域滤波模块
		IMG_MOTION_DETECT,        //移动侦测模块
		IMG_MOTION_DETECT_DM365,  //DM365芯片运动侦测模块
		IMG_HQ3DIIR_FILTER,       //图像HQ3dIIR滤波模块
		IMG_POSTDENOISE_HQ3D,     //基于HQ3D算法的图像后处理降噪
		IMG_ROTATE,               //图像旋转(包括镜像)
		IMG_HAZEREMOVE,           //图像去雾模块	
		IMG_PROCESS_NONE          //图像处理不存在的类型
}ImageProcessType;

typedef struct
{
    int l32SrcWidth;         //源图像的宽度
    int l32SrcHeight;        //源图像的高度
    int l32SrcStride;        //源图像的Y步进值，目前需要传的就是RGB图像或者底图的实际物理宽度
    int l32SrcRGBType;
	
    int l32DstWidth;         //目的图像的宽度，目前只支持同尺寸的转换，此参数填成跟源一样即可，保留是为了以后扩展
    int l32DstHeight;         //目的图像的高度，目前只支持同尺寸的转换，此参数填成跟源一样即可，保留是为了以后扩展
    int l32DstStride;        //目的图像的Y步进值，这里可以填成图像宽度即可
    int l32DstYUVType;
	
    int l32TransposeFlag;    //是否需要图像翻转，0表示不翻转，1表示翻转
    unsigned int u32Reserved;
}TImageRGBtoYUVParam;

//图像缩放输入参数
typedef struct
{
	unsigned char *pu8SrcBAddr;         //源图像B分量地址,这里如果是标准的RGB格式，只需要填这一个指针即可
    unsigned char *pu8SrcGAddr;         //源图像G分量地址
    unsigned char *pu8SrcRAddr;         //源图像R分量地址
	
    void *pvRGBQuadMap;      //调色板数据区域,为了将来扩展，这里暂时可以不填
    int u32Reserved;
}TImageRGBtoYUVInput;

//图像缩放输出参数
typedef struct
{
    unsigned char *pu8DstYAddr;            //目的图像的Y分量地址
    unsigned char *pu8DstUAddr;            //目的图像的U分量地址
    unsigned char *pu8DstVAddr;            //目的图像的V分量地址
	
    int u32Reserved;
}TImageRGBtoYUVOutput1;


//图像缩放输出参数
typedef struct
{
    unsigned char *pu8DstYAddr;            //目的图像的Y分量地址
    unsigned char *pu8DstUAddr;            //目的图像的U分量地址
    unsigned char *pu8DstVAddr;            //目的图像的V分量地址
	
    int u32Reserved;
}TImageRGBtoYUVOutput;

int ImageProcess22(TImageRGBtoYUVInput *pvImageInput, TImageRGBtoYUVOutput1 *pvImageOutput,int nWidth,int nHeight);



/*====================================================================
函数名		: ImageUnitAnalyzeErrorCode
功能		: 图像处理错误码分析
算法实现	: 无
引用全局变量: 无
参数        : pvHandle: 指向图像处理句柄指针[in]
              l32ErrorCode:	图像处理返回的错误码[in]
			  l32BufLen: 错误码信息的缓冲长度[in]
              pvErrorCodeInfo : 错误码码信息[in/out]
返回值说明  : 成功: VIDEO_SUCCESS, 失败: 返回错误码
====================================================================*/
l32 ImageUnitAnalyzeErrorCode(void *pvHandle, l32 l32ErrorCode, l32 l32BufLen, void *pvErrorCodeInfo);

/*====================================================================
函数名		: ImageUnitClose
功能		: 关闭指定图像类型图像处理句柄
算法实现	: 无
引用全局变量: 无
输入参数说明: pvHandle: 指向指定类型图像处理句柄指针[in]
输出参数说明: 无
返回值说明  : 成功: VIDEO_SUCCESS, 失败: 返回错误码
====================================================================*/
l32 ImageUnitClose(void *pvHandle);

/*====================================================================
函数名		: ImageUnitOpen
功能		: 图像处理初始化
算法实现	: 无
引用全局变量: 无
参数        : ppvHandle: 指向图像处理句柄指针[in/out]
              pvImageParam: 指向指定图像处理类型参数设置结构体指针[in]
			  pvEncMemParam: 指向内存参数结构体指针[in/out]
			  u32ImageProcessType: 图像处理类型[in]
返回值说明  : 成功: VIDEO_SUCCESS, 失败: 返回错误码
====================================================================*/
l32 ImageUnitOpen(void **ppvHandle, void *pvImageParam, void *pvMemParam, int u32IamgeProcessType);

/*====================================================================
函数名		: ImageUnitProcess
功能		: 图像处理
算法实现	: 无
引用全局变量: 无
参数        : pvHandle: 指向图像处理句柄指针[in]
pvImageInput: 指向指定图像处理类型输入参数结构体指针[in]
ptEncOutput: 指向指定图像处理类型输出参数结构体指针[out]
返回值说明  : 成功: VIDEO_SUCCESS, 失败: 返回错误码
====================================================================*/
l32 ImageUnitProcess(void *pvHandle, void *pvImageInput, void *pvImageOutput);

/*====================================================================
函数名		: ImageUnitSetParam
功能		: 改变指定图像处理类型参数设置
算法实现	: 无
引用全局变量: 无
参数        : pvHandle: 指向指定图像处理类型图像处理句柄指针[in/out]
pvImageParam: 指向指定图像类型图像处理初始化参数结构体指针[in]
返回值说明  : 成功: VIDEO_SUCCESS, 失败: 返回错误码
====================================================================*/
l32 ImageUnitSetParam(void *pvHandle, void *pvImageParam);



class CCommon
{
public:
	CCommon();
	virtual ~CCommon();

public:
	
};

#ifdef __cplusplus
}
#endif
#endif