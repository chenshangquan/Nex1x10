/*

Module Name:

    common.h

Abstract:

    ���幫������.

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
#define  YUV420     420    //������ƽ�棬Yƽ�棬Uƽ�棬Vƽ�棬����Uƽ���Vƽ���ΪYƽ���1/4  Y0 Y1 Y2 Y3.. U0 U1.. V0 V1..


	//ͼ�������������
typedef struct
{
	int nDeviceCount;             //����
    DISPLAY_DEVICE aryddDisplay[SCREEN_MAX_NUM];     //��ʾ����Ϣ
    DEVMODE        arydmDevMode[SCREEN_MAX_NUM];     //��ʾ���� 
	
    int u32Reserved;
}TDisplayInfo;


//rgb���Ͷ���
typedef enum
{
	RGB1   = 1,
		RGB4   = 4,
		RGB8   = 8,
		RGB565 = 16,
		RGB555 = 15,
		RGB24  = 24,
		RGB32  = 32 //ÿ�����ݵ�Ԫ��ռ�õ�ʵ�ʴ�С
}RGBTYPE_t;

//Դͼ��Ľṹ��Ϣ
typedef struct
{
	l32 l32SrcWidth;     //Դͼ��Ŀ��
	l32 l32SrcHeight;    //Դͼ��ĸ߶�
	l32 l32SrcYUVType;	 //Դͼ���ͼ�����ͣ�ΪYUV420����YUV422
	l32 l32SrcInterlace; //Դͼ���֡������
	
	l32 l32SrcTopCutLine;     //����Ĳü���������ӦΪ2�ı���
	l32 l32SrcBottomCutLine;  //����Ĳü���������ӦΪ2�ı���
	l32 l32SrcLeftCutPoint;   //��ߵĲü��ĵ�����ӦΪ2�ı���
	l32 l32SrcRightCutPoint;  //�ұߵĲü��ĵ�����ӦΪ2�ı���
	
	int u32Reserved;
}TSrcInfo;

//Ŀ��ͼ��Ľṹ����
typedef struct
{
	l32 l32DstWidth;        //Ŀ��ͼ��Ŀ��
	l32 l32DstHeight;		//Ŀ��ͼ��ĸ߶�
	l32 l32DstYUVType;		//Ŀ��ͼ���ͼ�����ͣ�ΪYUV420����YUV422
	l32 l32DstInterlace;	//Ŀ��ͼ���֡������
	
	l32 l32DstTopCutLine;     //����Ĳü���������ӦΪ2�ı���
	l32 l32DstBottomCutLine;  //����Ĳü���������ӦΪ2�ı���
	l32 l32DstLeftCutPoint;   //��ߵĲü��ĵ�����ӦΪ2�ı���
	l32 l32DstRightCutPoint;  //�ұߵĲü��ĵ�����ӦΪ2�ı���
	
	l32 l32TopFillLine;     //�������ӵ���ɫ������ӦΪ2�ı���
	l32 l32BottomFillLine;  //�������ӵ���ɫ������ӦΪ2�ı���
	l32 l32LeftFillPoint;   //��ߵ���ӵ���ɫ������ӦΪ2�ı���
	l32 l32RightFillPoint;  //�ұߵ���ӵ���ɫ������ӦΪ2�ı���
	
	l32 l32YColor;
	l32 l32UColor;
	l32 l32VColor;          //���ı�Ե����ɫ��Ŀǰ��ɫΪY:0x01,UV:0x80,��ɫ��ȫ�㣬Ҳ���Կ������ó�RGB��������
	
	int u32Reserved;
}TDstInfo;

typedef struct
{
	TSrcInfo tSrcInfo;   //Դͼ��������Ϣ
	
	TDstInfo tDstInfo;   //Ŀ��ͼ��������Ϣ
	
    int u32Reserved;
}TImageResizerParam;

//����ͼ��������
typedef enum
{
    IMG_YUV422_TO_YUV420 = 1, //ͼ��YUV422תΪͼ��YUV420
		IMG_YUV420_TO_YUV422,     //ͼ��YUV420תΪͼ��YUV422
		IMG_YUV420_TO_RGB,        //ͼ��YUV420תΪRGBͼ��
		IMG_YUV422_SPLIT,         //ͼ��YUV422���Ϊ4·YUV420ͼ��
		IMG_ZOOM,                 //ͼ��YUV420����С���Ŵ�
		IMG_MERGE,                //ͼ��YUV420�Ļ���ϳ�
		IMG_BMPTOYUVALPHA,        //BMPͼ��תΪYUVͼ������Alphaͨ��
		IMG_LOGO,                 //��̨��
		IMG_BANNER,               //�Ӻ��
		IMG_BANNER_LOGO,          //�������
		IMG_GENERATE_IMAGE,       //ͼ������
		IMG_MOSAIC,               //��������
		IMG_PN_CHANGE,            //ͼ��P�ƺ�N��ת��
		IMG_ADD_IMAGE,            //���л�
		IMG_YUV422_VGA_ZOOM,      //VGA��YUV422ͼ������
		IMG_ADAPT_16vs9,          //ͼ�������16vs9
		IMG_IMGUNIT,              //ͼ���汾��Ϣ����
		IMG_FILTER_OSD,           //��ʱ�����˲�OSD������
		IMG_MULTI_DEC,            //��·����
		IMG_APT_ZOOM_MOD,         //�����ϲ����ò�������ͼ�񲢼Ӻڱ�
		IMG_MERGE_ZOOM,           //ͼ�����Ų�����ϳ�
		IMG_MULTI_DEC_NEW,        //�µĶ�·����
		IMG_YUV422_ZOOM,          //YUV422ͼ������
		IMG_RESIZER,              //resizer����ģ��
		IMG_MULTI_ENC,            //��·����
		IMG_RGB_ZOOM,             //RBG565����ģ��
		IMG_RENOVATION,           //ͼ��ˢ��ģ��
		IMG_MOTION_DETECT_GM8180, //GM8180оƬ�˶����ģ��
		IMG_GM8180_TO_YUV420,     //GM8180��YUV420֮��Ļ���
		IMG_COMMON_ADDLOGO,       //GM8180��ͼ�ϼ�LOGO
		IMG_GM8180ADDMOSAIC,      //GM8180��ͼ�ϼ�MOSAIC
		IMG_DEINTERLACE,          //Deinterlace����
		IMG_FILTER,               //ͼ���˲�ģ��
		IMG_DUAL_ENC,             //˫������ģ�飨ͬԴ��
		IMG_SHARP,                //ͼ����ģ��
		IMG_RGBTOYUV,             //RGBתYUV420ģ��
		IMG_TEMPORAL_FILTER,      //ͼ��ʱ���˲�ģ��
		IMG_MOTION_DETECT,        //�ƶ����ģ��
		IMG_MOTION_DETECT_DM365,  //DM365оƬ�˶����ģ��
		IMG_HQ3DIIR_FILTER,       //ͼ��HQ3dIIR�˲�ģ��
		IMG_POSTDENOISE_HQ3D,     //����HQ3D�㷨��ͼ�������
		IMG_ROTATE,               //ͼ����ת(��������)
		IMG_HAZEREMOVE,           //ͼ��ȥ��ģ��	
		IMG_PROCESS_NONE          //ͼ�������ڵ�����
}ImageProcessType;

typedef struct
{
    int l32SrcWidth;         //Դͼ��Ŀ��
    int l32SrcHeight;        //Դͼ��ĸ߶�
    int l32SrcStride;        //Դͼ���Y����ֵ��Ŀǰ��Ҫ���ľ���RGBͼ����ߵ�ͼ��ʵ��������
    int l32SrcRGBType;
	
    int l32DstWidth;         //Ŀ��ͼ��Ŀ�ȣ�Ŀǰֻ֧��ͬ�ߴ��ת�����˲�����ɸ�Դһ�����ɣ�������Ϊ���Ժ���չ
    int l32DstHeight;         //Ŀ��ͼ��ĸ߶ȣ�Ŀǰֻ֧��ͬ�ߴ��ת�����˲�����ɸ�Դһ�����ɣ�������Ϊ���Ժ���չ
    int l32DstStride;        //Ŀ��ͼ���Y����ֵ������������ͼ���ȼ���
    int l32DstYUVType;
	
    int l32TransposeFlag;    //�Ƿ���Ҫͼ��ת��0��ʾ����ת��1��ʾ��ת
    unsigned int u32Reserved;
}TImageRGBtoYUVParam;

//ͼ�������������
typedef struct
{
	unsigned char *pu8SrcBAddr;         //Դͼ��B������ַ,��������Ǳ�׼��RGB��ʽ��ֻ��Ҫ����һ��ָ�뼴��
    unsigned char *pu8SrcGAddr;         //Դͼ��G������ַ
    unsigned char *pu8SrcRAddr;         //Դͼ��R������ַ
	
    void *pvRGBQuadMap;      //��ɫ����������,Ϊ�˽�����չ��������ʱ���Բ���
    int u32Reserved;
}TImageRGBtoYUVInput;

//ͼ�������������
typedef struct
{
    unsigned char *pu8DstYAddr;            //Ŀ��ͼ���Y������ַ
    unsigned char *pu8DstUAddr;            //Ŀ��ͼ���U������ַ
    unsigned char *pu8DstVAddr;            //Ŀ��ͼ���V������ַ
	
    int u32Reserved;
}TImageRGBtoYUVOutput1;


//ͼ�������������
typedef struct
{
    unsigned char *pu8DstYAddr;            //Ŀ��ͼ���Y������ַ
    unsigned char *pu8DstUAddr;            //Ŀ��ͼ���U������ַ
    unsigned char *pu8DstVAddr;            //Ŀ��ͼ���V������ַ
	
    int u32Reserved;
}TImageRGBtoYUVOutput;

int ImageProcess22(TImageRGBtoYUVInput *pvImageInput, TImageRGBtoYUVOutput1 *pvImageOutput,int nWidth,int nHeight);



/*====================================================================
������		: ImageUnitAnalyzeErrorCode
����		: ͼ������������
�㷨ʵ��	: ��
����ȫ�ֱ���: ��
����        : pvHandle: ָ��ͼ������ָ��[in]
              l32ErrorCode:	ͼ�����صĴ�����[in]
			  l32BufLen: ��������Ϣ�Ļ��峤��[in]
              pvErrorCodeInfo : ����������Ϣ[in/out]
����ֵ˵��  : �ɹ�: VIDEO_SUCCESS, ʧ��: ���ش�����
====================================================================*/
l32 ImageUnitAnalyzeErrorCode(void *pvHandle, l32 l32ErrorCode, l32 l32BufLen, void *pvErrorCodeInfo);

/*====================================================================
������		: ImageUnitClose
����		: �ر�ָ��ͼ������ͼ������
�㷨ʵ��	: ��
����ȫ�ֱ���: ��
�������˵��: pvHandle: ָ��ָ������ͼ������ָ��[in]
�������˵��: ��
����ֵ˵��  : �ɹ�: VIDEO_SUCCESS, ʧ��: ���ش�����
====================================================================*/
l32 ImageUnitClose(void *pvHandle);

/*====================================================================
������		: ImageUnitOpen
����		: ͼ�����ʼ��
�㷨ʵ��	: ��
����ȫ�ֱ���: ��
����        : ppvHandle: ָ��ͼ������ָ��[in/out]
              pvImageParam: ָ��ָ��ͼ�������Ͳ������ýṹ��ָ��[in]
			  pvEncMemParam: ָ���ڴ�����ṹ��ָ��[in/out]
			  u32ImageProcessType: ͼ��������[in]
����ֵ˵��  : �ɹ�: VIDEO_SUCCESS, ʧ��: ���ش�����
====================================================================*/
l32 ImageUnitOpen(void **ppvHandle, void *pvImageParam, void *pvMemParam, int u32IamgeProcessType);

/*====================================================================
������		: ImageUnitProcess
����		: ͼ����
�㷨ʵ��	: ��
����ȫ�ֱ���: ��
����        : pvHandle: ָ��ͼ������ָ��[in]
pvImageInput: ָ��ָ��ͼ����������������ṹ��ָ��[in]
ptEncOutput: ָ��ָ��ͼ����������������ṹ��ָ��[out]
����ֵ˵��  : �ɹ�: VIDEO_SUCCESS, ʧ��: ���ش�����
====================================================================*/
l32 ImageUnitProcess(void *pvHandle, void *pvImageInput, void *pvImageOutput);

/*====================================================================
������		: ImageUnitSetParam
����		: �ı�ָ��ͼ�������Ͳ�������
�㷨ʵ��	: ��
����ȫ�ֱ���: ��
����        : pvHandle: ָ��ָ��ͼ��������ͼ������ָ��[in/out]
pvImageParam: ָ��ָ��ͼ������ͼ�����ʼ�������ṹ��ָ��[in]
����ֵ˵��  : �ɹ�: VIDEO_SUCCESS, ʧ��: ���ش�����
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