/*
 * Kedacom Hardware Abstract Level
 *
 * src/video/vid_intf.h
 *
 * Copyright (C) 2013-2020, Kedacom, Inc.
 *
 * History:
 *   2013/09/22 - [xuliqin] Create
 *
 */

#ifndef __VID_INTF_H
#define __VID_INTF_H

#ifdef __cplusplus
extern "C" {
#endif

#include <drvlib_def.h>

#ifndef USE_KLSP_DEFINES

/*
 * video interface defines
 * use u32 type variable
 *     D[31:24]: flag mask
 *     if (flag & VIDIF_FLAG_IVP) == VIDIF_FLAG_IVP
 *         |- D[23:16]: IVP interface type
 *         |- D[15: 8]: index of chip
 *         |- D[ 7: 0]: index of video port
 *     if (flag & VIDIF_FLAG_IVP) == 0
 *         |- D[23:16]: PHY interface type
 *         |- D[15: 8]:
 *         |- D[ 7: 0]: index of physical video interface
 */

/* flag mask defines */
#define VIDIF_FLAG_IVP          0x80000000 /* internal video port, 0=phy intf */
#define VIDIF_FLAG_DIV2         0x40000000 /* for input : FPS/2 */
#define VIDIF_FLAG_DBL2         0x40000000 /* for output: FPS*2 */

/* interface type defines */
#define VIDIF_TYPE_SHIFT        16
#define VIDIF_TYPE_MASK         0xff
#define VIDIF_TYPE(v)           (((v) >> VIDIF_TYPE_SHIFT) & VIDIF_TYPE_MASK)

#define VIDIF_PHY_HDMI          0x01 /* type: HDMI */
#define VIDIF_PHY_VGA           0x02 /* type: VGA */
#define VIDIF_PHY_YPbPr         0x03 /* type: YPbPr */
#define VIDIF_PHY_SDI           0x04 /* type: SDI */
#define VIDIF_PHY_C             0x05 /* type: CVBS */
#define VIDIF_PHY_S             0x06 /* type: S-VIDEO */
#define VIDIF_PHY_DVI           0x07 /* type: DVI */
#define VIDIF_PHY_DP            0x08 /* type: Display Port */
#define VIDIF_PHY_CAMERA        0x09 /* type: Sensor Camera */
#define VIDIF_PHY_HDBASET       0x0A /* type: HDBaseT */

#define VIDIF_IVP_DSP           0x00 /* DSP capture/display video port */
#define VIDIF_IVP_CODEC         0x01 /* encoder/decoder(TAOS.etc) video port */
#define VIDIF_IVP_OSD           0x02 /* osd(fpga module,etc) video port */
#define VIDIF_IVP_RESIZER       0x03 /* Resizer(fpga module,etc) video port */
#define VIDIF_IVP_TITLE         0x04 /* Title(fpga module,etc) video port */
#define VIDIF_IVP_VCOMP         0x05 /* video composition video port */

/* chip index defines */
#define VIDIF_CHIP_SHIFT        8
#define VIDIF_CHIP_MASK         0xff
#define VIDIF_CHIP(v)           (((v) >> VIDIF_CHIP_SHIFT) & VIDIF_CHIP_MASK)

/* no. index defines */
#define VIDIF_NO_SHIFT          0
#define VIDIF_NO_MASK           0xff
#define VIDIF_NO(v)             (((v) >> VIDIF_NO_SHIFT) & VIDIF_NO_MASK)


/* physical interface defines */
#define VIDIF_PHY(type, no)           (((type) << VIDIF_TYPE_SHIFT) | \
                                       ((no)   << VIDIF_NO_SHIFT))
#define VIDIF_NONE                    0
#define VIDIF_HDMI(n)                 VIDIF_PHY(VIDIF_PHY_HDMI,       n)
#define VIDIF_VGA(n)                  VIDIF_PHY(VIDIF_PHY_VGA,        n)
#define VIDIF_YPbPr(n)                VIDIF_PHY(VIDIF_PHY_YPbPr,      n)
#define VIDIF_SDI(n)                  VIDIF_PHY(VIDIF_PHY_SDI,        n)
#define VIDIF_C(n)                    VIDIF_PHY(VIDIF_PHY_C,          n)
#define VIDIF_S(n)                    VIDIF_PHY(VIDIF_PHY_S,          n)
#define VIDIF_DVI(n)                  VIDIF_PHY(VIDIF_PHY_DVI,        n)
#define VIDIF_DP(n)                   VIDIF_PHY(VIDIF_PHY_DP,         n)
#define VIDIF_CAMERA(n)               VIDIF_PHY(VIDIF_PHY_CAMERA,     n)
#define VIDIF_HDBASET(n)              VIDIF_PHY(VIDIF_PHY_HDBASET,    n)

/* IVP interface defines */
#define VIDIF_IVP(type, chip, port) \
	(VIDIF_FLAG_IVP | \
	 ((type) << VIDIF_TYPE_SHIFT) | \
	 ((chip) << VIDIF_CHIP_SHIFT) | \
	 ((port) << VIDIF_NO_SHIFT))

#define VIDIF_DSP_VP(chip, port)     VIDIF_IVP(VIDIF_IVP_DSP, chip, port)
#define VIDIF_CODEC_VP(chip, port)   VIDIF_IVP(VIDIF_IVP_CODEC, chip, port)
#define VIDIF_OSD_VP(chip, port)     VIDIF_IVP(VIDIF_IVP_OSD, chip, port)
#define VIDIF_RESIZER_VP(chip, port) VIDIF_IVP(VIDIF_IVP_RESIZER, chip, port)
#define VIDIF_TITLE_VP(chip, port)   VIDIF_IVP(VIDIF_IVP_TITLE, chip, port)
#define VIDIF_VCOMP_VP(chip, port)   VIDIF_IVP(VIDIF_IVP_VCOMP, chip, port)


/* some utility defines */
#define VIDIF_PHY_TYPE(intf) \
	((intf & VIDIF_FLAG_IVP) ? VIDIF_NONE:VIDIF_TYPE(intf))

#define VIDIF_IS_PHY(intf)    ((intf & VIDIF_FLAG_IVP) ? 0:1)
#define VIDIF_IS_IVP(intf)    ((intf & VIDIF_FLAG_IVP) ? 1:0)

#define VIDIF_IS_HDMI(intf)   ((VIDIF_PHY_TYPE(intf) == VIDIF_PHY_HDMI)   ? 1:0)
#define VIDIF_IS_VGA(intf)    ((VIDIF_PHY_TYPE(intf) == VIDIF_PHY_VGA)    ? 1:0)
#define VIDIF_IS_YPbPr(intf)  ((VIDIF_PHY_TYPE(intf) == VIDIF_PHY_YPbPr)  ? 1:0)
#define VIDIF_IS_SDI(intf)    ((VIDIF_PHY_TYPE(intf) == VIDIF_PHY_SDI)    ? 1:0)
#define VIDIF_IS_C(intf)      ((VIDIF_PHY_TYPE(intf) == VIDIF_PHY_C)      ? 1:0)
#define VIDIF_IS_S(intf)      ((VIDIF_PHY_TYPE(intf) == VIDIF_PHY_S)      ? 1:0)
#define VIDIF_IS_DVI(intf)    ((VIDIF_PHY_TYPE(intf) == VIDIF_PHY_DVI)    ? 1:0)
#define VIDIF_IS_DP(intf)     ((VIDIF_PHY_TYPE(intf) == VIDIF_PHY_DP)     ? 1:0)
#define VIDIF_IS_CAMERA(intf) ((VIDIF_PHY_TYPE(intf) == VIDIF_PHY_CAMERA) ? 1:0)


/* ==========================================================================*
 *   color_space defines
 * --------------------------------------------------------------------------*/
/* timing mode */
#define VIDEO_STD_MASK_EMBSYNC        0x80000000 /* 1=embed; 0=dedicated */
#define VIDEO_STD_MASK_RB             0x40000000 /* 1=reduce blanking;0=normal*/

/* video colorspace */
#define VIDEO_STD_MASK_COLORSPACE     0x000000ff /* color space mask, D[7:0] */
#define VIDEO_COLORSPACE_YUV422       0 /* 16Bit YUV422I_UYVY */
#define VIDEO_COLORSPACE_RGB888       1 /* RGB888 */
#define VIDEO_COLORSPACE_RGB444       2 /* RGB444 */
#define VIDEO_COLORSPACE_RAW16BIT     3 /* 16Bit Raw RGB */
#define VIDEO_COLORSPACE_RGB565       4 /* RGB565 */
#define VIDEO_COLORSPACE_YUV422I_YUYV 5 /* 16Bit YUV422I_YUYV */
#define VIDEO_COLORSPACE_YUV422SP_UV  6 /* 16Bit YUV422 Semi-Planar
                                           Y separate, UV interleaved */
#define VIDEO_COLORSPACE_YUV420SP_UV  7 /* 12Bit YUV420 Semi-Planar
                                           Y separate, UV interleaved. */
#define VIDEO_COLORSPACE_YUV444       8 /* YUV444 */
#define VIDEO_COLORSPACE_YUV420P      9 /* YUV420 Planar, YUV all separate */
#define VIDEO_COLORSPACE_YUV422I_UYVY 10/* 16Bit YUV422I_UYVY */

/* Interface Mode: Bus width etc */
#define VIDEO_STD_MASK_INTF_MODE      0x00f00000 /* mask */
#define VIDEO_IF_MODE_AUTO            0x00000000 /* auto select by video std  */
#define VIDEO_IF_MODE_8BIT            0x00100000 /*  8bit */
#define VIDEO_IF_MODE_16BIT           0x00200000 /* 16bit */
#define VIDEO_IF_MODE_24BIT           0x00300000 /* 24bit */
#define VIDEO_IF_MODE_32BIT           0x00400000 /* 32bit */
#define VIDEO_IF_MODE_2x16BIT         0x00500000 /* 2x16bit(double bus) */
/* -------------------------------------------------------------------------- */


/* nsf_level defines */
#define VIDNSF_OFF                    0x00000000 /* OFF */
#define VIDNSF_LOW                    0x00000001 /* LOW */
#define VIDNSF_MID                    0x00000002 /* MID */
#define VIDNSF_HIGH                   0x00000003 /* HIGH */

/* nsf_type defines */
#define VIDNSF_RNR                    0x00000001 /* Random Noise Reduction */
#define VIDNSF_MNR                    0x00000002 /* Mosquito Noise Reduction */
#define VIDNSF_BNR                    0x00000004 /* Block Noise Reduction */
#define VIDNSF_3D                     0x00000008 /* 3D NSF */

/*freeze define*/
#define VIDUNFREEZE_ALL      0x00000000/*bit[7:0] all win unfreeze*/
#define VIDFREEZE_WIN(n)     ((0x01) << n) /*freeze win n*/
#define VIDFREEZE_ALL           0x000000ff  /*bit[7:0] all win freeze*/
#define VIDFREEZE_INPUT_MODE     0x00000000  /*bit8[0] freeze input intf*/
#define VIDFREEZE_OUTPUT_MODE  0x00000100 /*bit8[1] freeze output intf*/

#endif /* USE_KLSP_DEFINES */

/* video composition defines */
#define VIDCOMP_IN_MAX_NUM               4

/*video prohibit area num*/
#define VIDPROHIBIT_AREA_MAX_NUM     4

/*video crop area num*/
#define VIDCROP_AREA_MAX_NUM        4

/* video standard param */
typedef struct
{
	u32    dwWidth;      /* in pixel, 0 = no video */
	u32    dwHeight;     /* in line,  0 = no video */
	BOOL32 bProgressive; /* TRUE = progressive; FALSE = interleaved */
	u32    dwFrameRate;  /* frame rate: 0 = no video; progressive = Freq_VS;
	                                interleaved = Freq_VS/2, 60i=30P */
	u32    dwColorSpace; /* see also: VIDEO_COLORSPACE_YUV422 */
} TVidStd;

/* video crop struct */
typedef struct
{
	u32 dwPosX;      /* horizontal offset base on active video, in pixel */
	u32 dwPosY;      /* vertical offset base on active video, in line */
	u32 dwWidth;     /* in pixel, 0 = no video */
	u32 dwHeight;    /* in line,  0 = no video */
	u32 dwEnable;    /* 0:disable, 1:enable */
} TVidCrop;

/*
 * video mux output defines
 * one logic video data channel may include multi video input data
 * these input data can muxed together with pix-by-pix or line-by-line
 */
typedef struct
{
	u32 dwVDPort;       /* digital video output port: 0=vp1 1=vp2... */
	u32 dwMuxChnlNum;   /* mux video channel number, 0=one channel */
	u32 dwMuxMode;      /* mux mode: 0=pix Mux; 1=line Mux */
	u32 dwMuxChnlMask;  /* video inport mask: D[3-0]=chnl0 D[7-4]=chnl1 ...
	                       4bit value = input port id: 0-15 */
} TVidInMuxOutput;

/* TV info */
typedef struct
{
	u32        dwTVIntf;           /* tv interface type connnected
	                                  VIDIF_SHUT_DOWN = not connect */
	u8        adwManufacturer[16]; /* string */
	u8        adwName[16];         /* string */
} TVidOutTVInfo;

/* video distortion correction param */
typedef struct
{
	u32 dwCorrectLevel;     /* fpga distortion correct level */
	u32 dwStretchRegion;    /* fpga distortion correction stretch */
	u32 dwEnable;           /* 0:disable, 1:enable */
} TVidDistortParam;

/* video noise filter param */
typedef struct
{
	u32 dwNsfLevel;  /* see also: VIDNSF_OFF */
	u32 dwNsfType;   /* see also: VIDNSF_RNR */
} TVidNsfParam;

/* Title Generator picture struct */
typedef struct
{
	u32 dwPicId;           /* picture index, 0 - x */
	u32 dwPicWidth;        /* in pixel */
	u32 dwPicHeight;       /* in line */
	u32 dwPicFmt;          /* see alse VIDEO_COLORSPACE_YUV422 */
	void *pbyPicData;      /* user space buffer address */
	u32 dwPicSize;         /* in Bytes */
} TVidTitlePicLoad;

/* Title Generator draw operation struct */
typedef struct
{
	u32 dwIntfIn;          /* TitleGen video source interface */
	TVidStd tVidStd;       /* video standard */

	u32 dwOsdPosX;         /* OSD window coordinate X, in pixel */
	u32 dwOsdPosY;         /* OSD window coordinate y, in line */
	u32 dwOsdWidth;        /* OSD window width,  in pixel */
	u32 dwOsdHeight;       /* OSD window height, in line */

	u32 dwTransVal;        /* globle transparency: 0-0xff,
	                          0 = pass thought; 0xff=opaque */
	u32 dwTransKeyY;       /* pass thought color Y: 0x10-0xf0,
	                          when pix Y=trans_key_y then pass */

	u32 dwDrawPicId;       /* picture index, must be loaded  */
	u32 dwDrawMode;        /* 0 = still;
	                          1 = move from right to left
	                          2 = move from bottom to top */
	u32 dwDrawMvDelay;     /* valid when draw_mode!=0
	                          0 = move one step every frame
	                          n = move one step after n frames */
	u32 dwDrawMvStep;      /* valid when draw_mode!=0, in pixel/line
	                          if interleaved video must be even */
	u32 dwDrawTimes;       /* valid when draw_mode!=0 move cycles */

	u32 dwPauseInterval;   /* valid when draw_mode=2, in frames
	                          we moving one step after n frames */
	u32 dwPauseLines;      /* valid when draw_mode=2
	                          0 = move continue, max = 2^11-1=2047
	                          !pause_lines/draw_mv_step must be integer */
} TVidTitlePicDraw;

/* TitleGen status */
typedef struct
{
	u32 dwPicId;           /* picture index, 0 - x */
	u32 dwDrawedCnt;       /* valid when draw_mode !=0
	                          tell user moved cycles */
} TVidTitleStat;

/* OSD param struct */
typedef struct
{
	TVidStd tVid0Std;      /* video0 layer standard */
	TVidStd tOsd0Std;      /* osd0   layer standard */
	u32  dwTransVal;       /* globle transparency: 0-0xff,
	                          0 = pass thought; 0xff=opaque */
	u32  dwTransKeyY;      /* pass thought color Y: 0x10-0xf0,
	                          when pix Y=trans_key_y then pass */
} TVidOsdParam;

/* OSD or non-OSD param struct */
typedef struct
{
	u32     dwIntfDest;      /* dest interface */
	TVidStd tVid0Std;      /* video0 layer standard */
	TVidStd tOsd0Std;      /* osd0   layer standard */
	u32  dwTransVal;       /* globle transparency: 0-0xff,
	                          0 = pass thought; 0xff=opaque */
	u32  dwTransKeyY;      /* pass thought color Y: 0x10-0xf0,
	                          when pix Y=trans_key_y then pass */
	u32 cut_en;				/* cut_en=1 cut osd */
	u32 scaler_en;
	u32 draw_or_mid;
} TVidOsdOrNotParam;


/* Resizer param */
typedef struct {
	u32     dwIntfIn;      /* Resizer video source interface */
	u32     dwMode;        /* Resize mode */
	TVidStd tVidInStd;     /* resize input standard */
	TVidStd tVidOutStd;    /* resize ouput standard */

	u32     dwScaledX;     /* offset x, in pixels */
	u32     dwScaledY;     /* offset y, in lines */
	u32     dwScaledWidth; /* 0 = out_std; else=width !must be even */
	u32     dwScaledHight; /* 0 = out_std; else=height */

	u8      *pbyCoef;      /* user space buffer, NULL= use default */
	u32     dwCoefLen;     /* len of filter coefficient, 0= use default */
} TVidResizeParam;

typedef enum {
	ONE_VID_COMP_DEFAULT,
	TWO_VID_COMP_LEFT_RIGHT_SAME,
	TWO_VID_COMP_ONE_LARGE_ONE_SMALL_LU,
	TWO_VID_COMP_ONE_LARGE_ONE_SMALL_LD,
	TWO_VID_COMP_ONE_LARGE_ONE_SMALL_RU,
	TWO_VID_COMP_ONE_LARGE_ONE_SMALL_RD,
	THREE_VID_COMP_ONE_LARGE_TWO_SMALL,
	THREE_VID_COMP_THREE_SAME,
	VID_COMP_STYLE_MAX
}EVidCompStyle;


/* Video composition param */
typedef struct {
	u32           dwVCompInNum;
	u32           dwVCompInSrc[VIDCOMP_IN_MAX_NUM];
	u32           dwVCompOutDest;
	EVidCompStyle eVidCompMode;
	TVidStd       tVCompInStd[VIDCOMP_IN_MAX_NUM];
	TVidStd       tVCompOutStd;
	TVidCrop      tVCompActRegion;
	TVidCrop      tVCompInSrcPos[VIDCOMP_IN_MAX_NUM];
} TVidCompParam;

/* screenshot size */
typedef struct {
	u32	width;
	u32	height;
} TVidScreenshotProperty;

typedef struct {
	u32     dwInterface;
	TVidScreenshotProperty tScPro;
}TVidScrshotProParam;

/* definition for video picture offset control */
typedef struct {
	int h_off;	/* horizontal video offset */
	int v_off;	/* vertical video offset */
} TVidOffsetParam;

typedef struct prohibit_area
{
	u32 prohibit_start_x;
	u32 prohibit_start_y;
	u32 prohibit_end_x;
	u32 prohibit_end_y;
}TVidProhibitArea;

typedef struct little_screen
{
	u32 flag;
	u32 start_x;
	u32 start_y;
	u32 height;
	u32 width;
	TVidProhibitArea area[VIDPROHIBIT_AREA_MAX_NUM];
}TVidLittleProhibitScreen;

typedef struct crop_area
{
	TVidCrop crop[VIDCROP_AREA_MAX_NUM];
}TVidDrvCropArea;

/* command for VidInApiCtrl VidOutApiCtrl */
enum eVidIfCmd {
	VIDIF_SET_BRIGHTNESS   = 1, /* pArgs = (u32 *), 0~0xff, def=0x80 */
	VIDIF_GET_BRIGHTNESS,       /* pArgs = (u32 *), 0~0xff, def=0x80 */
	VIDIF_SET_CONTRAST,         /* pArgs = (u32 *), 0~0xff, def=0x80 */
	VIDIF_GET_CONTRAST,         /* pArgs = (u32 *), 0~0xff, def=0x80 */
	VIDIF_SET_HUE,              /* pArgs = (u32 *), 0~0xff, def=0x80 */
	VIDIF_GET_HUE,              /* pArgs = (u32 *), 0~0xff, def=0x80 */
	VIDIF_SET_SATURATION,       /* pArgs = (u32 *), 0~0xff, def=0x80 */
	VIDIF_GET_SATURATION,       /* pArgs = (u32 *), 0~0xff, def=0x80 */
	VIDIF_SET_SHARPNESS,        /* pArgs = (u32 *), 0~0xff, def=0x80 */
	VIDIF_GET_SHARPNESS,        /* pArgs = (u32 *), 0~0xff, def=0x80 */
	VIDIF_SET_STD,              /* pArgs = (TVidStd *) */
	VIDIF_GET_STD,              /* pArgs = (TVidStd *) */
	VIDIF_GET_INTF_TYPE,        /* pArgs = (u32 *) */
	VIDIF_SET_OSD,              /* pArgs = (TVidOsdParam *) */
	VIDIF_START_OSD,            /* pArgs = NULL */
	VIDIF_STOP_OSD,             /* pArgs = NULL */
	VIDIF_SET_VCOMP,            /* pArgs = TVidCompParam */
	VIDIF_START_VCOMP,          /* pArgs = NULL */
	VIDIF_STOP_VCOMP,           /* pArgs = NULL */
	VIDIF_SET_RESIZER,          /* pArgs = (TVidResizeParam *) */
	VIDIF_START_RESIZER,        /* pArgs = NULL */
	VIDIF_STOP_RESIZER,         /* pArgs = NULL */
	VIDIF_LOAD_TITLE_PIC,       /* pArgs = (TVidTitlePicLoad *) */
	VIDIF_START_TITLE,          /* pArgs = (TVidTitlePicDraw *) */
	VIDIF_STOP_TITLE,           /* pArgs = (u32 *) */
	VIDIF_GET_TITLE_STAT,       /* pArgs = (TVidTitleStat *) */
	VIDIF_SET_CLK_PHASE,        /* pArgs = (u32 *) */
	VIDIF_GET_CLK_PHASE,        /* pArgs = (u32 *) */
	VIDIF_SET_FILT,             /* pArgs = (u32 *) */
	VIDIF_GET_FILT,             /* pArgs = (u32 *) */
	VIDIF_GET_TV_INFO,          /* pArgs = (TVidOutTVInfo *) */

	VIDIF_SET_MUXOUT_MODE,      /* pArgs = (TVidInMuxOutput *) */
	VIDIF_SET_NSF,              /* pArgs = (TVidNsfParam *) */
	VIDIF_SET_ACE,              /* pArgs = (u8 *), 0=bypass, 1=enable */
	VIDIF_SET_FPGA_NSF,         /* pArgs = (TVidNsfParam *) */
	VIDIF_DISTORT_CORRECT,      /* pArgs = (TVidDistortParam *) */

	VIDIF_SET_FPGA_STD,         /* pArgs = (TVidStd *) */
	VIDIF_RESET_FPGA,           /* pArgs = (u32 *) */
	VIDIF_SELECT_INPUT_VIDEO_STANDARD,
	VIDIF_SCREENSHOT,			 /* pArgs = (u32 *) */
	VIDIF_SET_HDMI_SWITCH_STATUS,        /* pArgs = (u32 *) */
	VIDIF_SET_OSD_OR_NOT,       /* pArgs = (TVidOsdOrNotParam *) */
	VIDIF_GET_AD_PORT_STATUS,	/* pArgs = (u32 *) */
	VIDIF_SET_VIDEO_OFFSET,
	VIDIF_SET_ADDA_REG_VALUE,
	VIDIF_SET_DEV_STATUS,
	VIDIF_GET_VCOMP,
	VIDIF_SET_OUTPUT_PLL,
	VIDIF_RESET_OUTPUT_PLL,
	VIDIF_GET_DETECT_INTF,
	VIDIF_RESET_AD,
	VIDIF_SET_FREEZE,
	VIDIF_SET_FPGA_SCALAR_EN,
	VIDIF_SET_GPIO_STATUS,
	VIDIF_SET_OVERLAY,
	VIDIF_SET_FORCE_OUT,
	VIDIF_SET_FPGA_MODE,
	VIDIF_SET_SYNC_OFFSET,
	VIDIF_SET_SDI_INOUT,
	VIDIF_SET_CROP_AREA
};


/* APIs */

/*
 * Set Input Video Path
 * dwVP  : Video Port ID, such as: VIDIF_DSP_VP(chip, port)
 * dwIntf: Video Interface ID, such as: VIDIF_HDMI(n)
 */
int VidInApiMapIntfToVP(u32 dwVP, u32 dwIntf);

/*
 * set input video interface params
 */
int VidInApiCtrl(u32 dwIntf, int nCmd, void *pArgs);

/*
 * Set Output Video Path
 * dwDstIntf: Dest Video Interface ID, such as: VIDIF_HDMI(n)
 * dwSrcIntf: Src  Video Interface ID, such as: VIDIF_HDMI(n)
 */
int VidOutApiSelVidOutSrc(u32 dwDstIntf, u32 dwSrcIntf);

/*
 * set output video interface params
 */
int VidOutApiCtrl(u32 dwIntf, int nCmd, void *pArgs);


#ifdef __cplusplus
}
#endif

#endif /* end __VID_INTF_H */
